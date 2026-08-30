using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public interface ITelegramRuntimeLifecycle
{
    Task StartAsync();

    Task StopAsync();
}

public sealed class TelegramRuntimeConfiguration
{
    private readonly string botToken;
    private readonly TelegramConfigurationIdentity transportIdentity;

    public TelegramRuntimeConfiguration(
        bool networkAllowed,
        bool featureAllowed,
        TelegramHostSettings settings,
        string botToken)
    {
        Settings = settings ?? throw new ArgumentNullException(nameof(settings));
        ArgumentNullException.ThrowIfNull(botToken);
        NetworkAllowed = networkAllowed;
        FeatureAllowed = featureAllowed;
        this.botToken = botToken;
        transportIdentity = TelegramConfigurationIdentity.Create(botToken, settings.AdminIds);
    }

    public bool NetworkAllowed { get; }

    public bool FeatureAllowed { get; }

    public TelegramHostSettings Settings { get; }

    public TelegramAvailabilityCandidate Candidate => new(botToken, Settings.AdminIds);

    public bool ProbeEligible =>
        NetworkAllowed &&
        FeatureAllowed &&
        Candidate.ConfigurationReady;

    public bool RuntimeEligible => ProbeEligible && Settings.Enabled;

    public bool Eligible => RuntimeEligible;

    internal string BotToken => botToken;

    internal bool SameTransportAs(TelegramRuntimeConfiguration other)
    {
        ArgumentNullException.ThrowIfNull(other);
        return NetworkAllowed == other.NetworkAllowed &&
            FeatureAllowed == other.FeatureAllowed &&
            Settings.Enabled == other.Settings.Enabled &&
            transportIdentity.Equals(other.transportIdentity);
    }

    internal bool SamePolicyAndRuntimeAs(TelegramRuntimeConfiguration other)
    {
        ArgumentNullException.ThrowIfNull(other);
        return NetworkAllowed == other.NetworkAllowed &&
            FeatureAllowed == other.FeatureAllowed &&
            Settings.Enabled == other.Settings.Enabled &&
            transportIdentity.Equals(other.transportIdentity);
    }

    public override string ToString() =>
        $"TelegramRuntimeConfiguration {{ NetworkAllowed = {NetworkAllowed}, " +
        $"FeatureAllowed = {FeatureAllowed}, Enabled = {Settings.Enabled}, " +
        $"AdminCount = {Settings.AdminIds.Count}, Token = [REDACTED] }}";
}

public sealed class TelegramRuntimeCoordinator : ITelegramRuntimeLifecycle
{
    private static readonly TimeSpan RestartDelay = TimeSpan.FromSeconds(2);
    private readonly object gate = new();
    private readonly Func<TelegramRuntimeConfiguration, CancellationToken, Task> runGeneration;
    private TelegramRuntimeConfiguration configuration;
    private TaskCompletionSource configurationChanged = NewSignal();
    private CancellationTokenSource? stopSource;
    private CancellationTokenSource? activeGeneration;
    private Task? supervisorTask;
    private long configurationVersion;
    private bool terminallyStopped;

    public TelegramRuntimeCoordinator(
        TelegramRuntimeConfiguration initialConfiguration,
        Func<TelegramRuntimeConfiguration, CancellationToken, Task> runGeneration)
    {
        configuration = initialConfiguration ??
            throw new ArgumentNullException(nameof(initialConfiguration));
        this.runGeneration = runGeneration ?? throw new ArgumentNullException(nameof(runGeneration));
    }

    public Task StartAsync()
    {
        lock (gate)
        {
            if (terminallyStopped)
            {
                // Stop is terminal for this coordinator. A late WPF
                // ContentRendered callback must remain fail-closed without
                // turning an already completed shutdown into an unhandled
                // process exception.
                return Task.CompletedTask;
            }
            if (supervisorTask is not null)
            {
                return Task.CompletedTask;
            }
            stopSource = new CancellationTokenSource();
            supervisorTask = SuperviseAsync(stopSource.Token);
        }
        return Task.CompletedTask;
    }

    public void ApplyConfiguration(TelegramRuntimeConfiguration next)
    {
        ArgumentNullException.ThrowIfNull(next);
        TaskCompletionSource signal;
        CancellationTokenSource? active;
        lock (gate)
        {
            var transportChanged = !configuration.SameTransportAs(next);
            configuration = next;
            if (!transportChanged)
            {
                return;
            }
            checked
            {
                configurationVersion++;
            }
            signal = configurationChanged;
            configurationChanged = NewSignal();
            active = activeGeneration;
        }
        active?.Cancel();
        signal.TrySetResult();
    }

    public async Task StopAsync()
    {
        CancellationTokenSource? stop;
        CancellationTokenSource? active;
        Task? supervisor;
        TaskCompletionSource signal;
        lock (gate)
        {
            terminallyStopped = true;
            stop = stopSource;
            active = activeGeneration;
            supervisor = supervisorTask;
            signal = configurationChanged;
            if (stop is null || supervisor is null)
            {
                return;
            }
        }
        stop.Cancel();
        active?.Cancel();
        signal.TrySetResult();
        try
        {
            await supervisor.ConfigureAwait(false);
        }
        catch (OperationCanceledException) when (stop.IsCancellationRequested)
        {
        }
        finally
        {
            lock (gate)
            {
                if (ReferenceEquals(supervisorTask, supervisor))
                {
                    supervisorTask = null;
                    activeGeneration?.Dispose();
                    activeGeneration = null;
                    stopSource?.Dispose();
                    stopSource = null;
                }
            }
        }
    }

    private async Task SuperviseAsync(CancellationToken stoppingToken)
    {
        while (true)
        {
            stoppingToken.ThrowIfCancellationRequested();
            var snapshot = SnapshotConfiguration();
            if (!snapshot.Configuration.Eligible)
            {
                await WaitForConfigurationChangeAsync(
                    snapshot.Version,
                    stoppingToken).ConfigureAwait(false);
                continue;
            }

            using var generation = CancellationTokenSource.CreateLinkedTokenSource(stoppingToken);
            lock (gate)
            {
                activeGeneration = generation;
            }
            try
            {
                await runGeneration(snapshot.Configuration, generation.Token).ConfigureAwait(false);
            }
            catch (OperationCanceledException)
                when (generation.IsCancellationRequested || stoppingToken.IsCancellationRequested)
            {
            }
            catch
            {
                // The supervisor retries with a bounded delay. Exception text is not
                // persisted because transport exceptions can contain credential URLs.
            }
            finally
            {
                lock (gate)
                {
                    if (ReferenceEquals(activeGeneration, generation))
                    {
                        activeGeneration = null;
                    }
                }
            }

            if (SnapshotConfiguration().Version == snapshot.Version)
            {
                await DelayUntilRetryOrChangeAsync(
                    snapshot.Version,
                    stoppingToken).ConfigureAwait(false);
            }
        }
    }

    private async Task DelayUntilRetryOrChangeAsync(
        long observedVersion,
        CancellationToken cancellationToken)
    {
        var changed = WaitForConfigurationChangeAsync(observedVersion, cancellationToken);
        var retry = Task.Delay(RestartDelay, cancellationToken);
        await Task.WhenAny(changed, retry).ConfigureAwait(false);
        cancellationToken.ThrowIfCancellationRequested();
    }

    private async Task WaitForConfigurationChangeAsync(
        long observedVersion,
        CancellationToken cancellationToken)
    {
        Task signal;
        lock (gate)
        {
            if (configurationVersion != observedVersion)
            {
                return;
            }
            signal = configurationChanged.Task;
        }
        await signal.WaitAsync(cancellationToken).ConfigureAwait(false);
    }

    private (TelegramRuntimeConfiguration Configuration, long Version) SnapshotConfiguration()
    {
        lock (gate)
        {
            return (configuration, configurationVersion);
        }
    }

    private static TaskCompletionSource NewSignal() => new(
        TaskCreationOptions.RunContinuationsAsynchronously);
}
