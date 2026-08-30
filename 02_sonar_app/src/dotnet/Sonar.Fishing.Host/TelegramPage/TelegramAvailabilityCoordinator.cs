namespace Sonar.Fishing.Host.TelegramPage;

public sealed class TelegramAvailabilityCoordinatorOptions
{
    public static TelegramAvailabilityCoordinatorOptions Default { get; } = new(
        TimeSpan.FromMilliseconds(350),
        TimeSpan.FromSeconds(5),
        TimeSpan.FromSeconds(2),
        TimeSpan.FromSeconds(2));

    public TelegramAvailabilityCoordinatorOptions(
        TimeSpan credentialDebounce,
        TimeSpan probeTimeout,
        TimeSpan retryDelay,
        TimeSpan stopTimeout)
    {
        CredentialDebounce = RequireNonNegative(
            credentialDebounce,
            nameof(credentialDebounce));
        ProbeTimeout = RequirePositive(probeTimeout, nameof(probeTimeout));
        RetryDelay = RequirePositive(retryDelay, nameof(retryDelay));
        StopTimeout = RequirePositive(stopTimeout, nameof(stopTimeout));
    }

    public TimeSpan CredentialDebounce { get; }

    public TimeSpan ProbeTimeout { get; }

    public TimeSpan RetryDelay { get; }

    public TimeSpan StopTimeout { get; }

    private static TimeSpan RequireNonNegative(TimeSpan value, string parameterName)
    {
        if (value < TimeSpan.Zero || value == Timeout.InfiniteTimeSpan)
        {
            throw new ArgumentOutOfRangeException(parameterName);
        }
        return value;
    }

    private static TimeSpan RequirePositive(TimeSpan value, string parameterName)
    {
        if (value <= TimeSpan.Zero || value == Timeout.InfiniteTimeSpan)
        {
            throw new ArgumentOutOfRangeException(parameterName);
        }
        return value;
    }
}

public sealed class TelegramRuntimeGenerationContext
{
    private readonly Action reportAvailable;
    private readonly Action<TelegramAvailabilityFailure> reportUnavailable;

    internal TelegramRuntimeGenerationContext(
        TelegramRuntimeConfiguration configuration,
        TelegramPollingCursor cursor,
        Action reportAvailable,
        Action<TelegramAvailabilityFailure> reportUnavailable)
    {
        Configuration = configuration ??
            throw new ArgumentNullException(nameof(configuration));
        Cursor = cursor ?? throw new ArgumentNullException(nameof(cursor));
        this.reportAvailable = reportAvailable ??
            throw new ArgumentNullException(nameof(reportAvailable));
        this.reportUnavailable = reportUnavailable ??
            throw new ArgumentNullException(nameof(reportUnavailable));
    }

    public TelegramRuntimeConfiguration Configuration { get; }

    internal TelegramPollingCursor Cursor { get; }

    public void ReportAvailable() => reportAvailable();

    public void ReportUnavailable(TelegramAvailabilityFailure failure)
    {
        if (failure == TelegramAvailabilityFailure.None)
        {
            throw new ArgumentOutOfRangeException(nameof(failure));
        }
        reportUnavailable(failure);
    }
}

public sealed class TelegramAvailabilityCoordinator : ITelegramRuntimeLifecycle
{
    private readonly object gate = new();
    private readonly SemaphoreSlim probeGate = new(1, 1);
    private readonly ITelegramAvailabilityProbe probe;
    private readonly Func<TelegramRuntimeGenerationContext, CancellationToken, Task>
        runGeneration;
    private readonly TelegramAvailabilityCoordinatorOptions options;
    private TelegramRuntimeConfiguration configuration;
    private TelegramAvailabilityCandidate candidate;
    private TelegramPollingCursor cursor = new();
    private TelegramAvailability current = TelegramAvailability.Unknown;
    private TelegramAvailability runtimeAvailability = TelegramAvailability.Unknown;
    private TaskCompletionSource runtimeConfigurationChanged = NewSignal();
    private TaskCompletionSource candidateChanged = NewSignal();
    private CancellationTokenSource? stopSource;
    private CancellationTokenSource? activeRuntimeGeneration;
    private CancellationTokenSource? activeCandidateGeneration;
    private Task? supervisorTask;
    private long runtimeVersion;
    private long candidateVersion;
    private int pendingRuntimeConfigurationChangeWaiters;
    private int pendingCandidateChangeWaiters;
    private bool terminallyStopped;

    public TelegramAvailabilityCoordinator(
        TelegramRuntimeConfiguration initialConfiguration,
        ITelegramAvailabilityProbe probe,
        Func<TelegramRuntimeGenerationContext, CancellationToken, Task> runGeneration,
        TelegramAvailabilityCoordinatorOptions? options = null)
    {
        configuration = initialConfiguration ??
            throw new ArgumentNullException(nameof(initialConfiguration));
        candidate = initialConfiguration.Candidate;
        this.probe = probe ?? throw new ArgumentNullException(nameof(probe));
        this.runGeneration = runGeneration ?? throw new ArgumentNullException(nameof(runGeneration));
        this.options = options ?? TelegramAvailabilityCoordinatorOptions.Default;
    }

    public event Action<TelegramAvailability>? AvailabilityChanged;

    public TelegramAvailability Current
    {
        get
        {
            lock (gate)
            {
                return current;
            }
        }
    }

    internal int PendingRuntimeConfigurationChangeWaiters =>
        Volatile.Read(ref pendingRuntimeConfigurationChangeWaiters);

    internal int PendingCandidateChangeWaiters =>
        Volatile.Read(ref pendingCandidateChangeWaiters);

    public Task StartAsync()
    {
        lock (gate)
        {
            if (terminallyStopped || supervisorTask is not null)
            {
                return Task.CompletedTask;
            }
            stopSource = new CancellationTokenSource();
            supervisorTask = Task.WhenAll(
                SuperviseRuntimeAsync(stopSource.Token),
                SuperviseCandidateAsync(stopSource.Token));
        }
        return Task.CompletedTask;
    }

    public void ApplyConfiguration(TelegramRuntimeConfiguration next)
    {
        ArgumentNullException.ThrowIfNull(next);
        CancellationTokenSource? activeRuntime = null;
        CancellationTokenSource? activeCandidate = null;
        TaskCompletionSource? runtimeSignal = null;
        TaskCompletionSource? candidateSignal = null;
        lock (gate)
        {
            if (terminallyStopped)
            {
                return;
            }

            var previous = configuration;
            var previousPersistedCandidate = previous.Candidate;
            var candidateFollowedPersisted = candidate.Identity.Equals(
                previousPersistedCandidate.Identity);
            var previousRuntimeSuppliedCandidate = previous.RuntimeEligible &&
                candidateFollowedPersisted;
            var runtimeChanged = !previous.SamePolicyAndRuntimeAs(next);
            var persistedIdentityChanged = !previousPersistedCandidate.Identity.Equals(
                next.Candidate.Identity);

            configuration = next;
            var nextPersistedCandidate = next.Candidate;
            var draftCandidateChanged = candidateFollowedPersisted &&
                persistedIdentityChanged;
            if (draftCandidateChanged)
            {
                candidate = nextPersistedCandidate;
            }
            if (persistedIdentityChanged)
            {
                cursor = new TelegramPollingCursor();
            }
            if (runtimeChanged)
            {
                runtimeAvailability = TelegramAvailability.Unknown;
                checked
                {
                    runtimeVersion++;
                }
                runtimeSignal = runtimeConfigurationChanged;
                runtimeConfigurationChanged = NewSignal();
                activeRuntime = activeRuntimeGeneration;
            }

            var nextRuntimeSuppliedCandidate = next.RuntimeEligible &&
                candidate.Identity.Equals(nextPersistedCandidate.Identity);
            var candidatePolicyChanged = previous.NetworkAllowed != next.NetworkAllowed ||
                previous.FeatureAllowed != next.FeatureAllowed ||
                previousRuntimeSuppliedCandidate != nextRuntimeSuppliedCandidate;
            if (draftCandidateChanged || candidatePolicyChanged)
            {
                checked
                {
                    candidateVersion++;
                }
                candidateSignal = candidateChanged;
                candidateChanged = NewSignal();
                activeCandidate = activeCandidateGeneration;
            }
        }

        CancelIfAlive(activeRuntime);
        CancelIfAlive(activeCandidate);
        runtimeSignal?.TrySetResult();
        candidateSignal?.TrySetResult();
    }

    public void ApplyCandidate(TelegramAvailabilityCandidate next)
    {
        ArgumentNullException.ThrowIfNull(next);
        CancellationTokenSource? active;
        TaskCompletionSource signal;
        lock (gate)
        {
            if (terminallyStopped || candidate.Identity.Equals(next.Identity))
            {
                return;
            }
            candidate = next;
            checked
            {
                candidateVersion++;
            }
            signal = candidateChanged;
            candidateChanged = NewSignal();
            active = activeCandidateGeneration;
        }
        CancelIfAlive(active);
        signal.TrySetResult();
    }

    public async Task StopAsync()
    {
        Task? supervisor;
        CancellationTokenSource? stop;
        CancellationTokenSource? activeRuntime;
        CancellationTokenSource? activeCandidate;
        TaskCompletionSource runtimeSignal;
        TaskCompletionSource candidateSignal;
        lock (gate)
        {
            if (!terminallyStopped)
            {
                terminallyStopped = true;
                checked
                {
                    runtimeVersion++;
                    candidateVersion++;
                }
            }
            supervisor = supervisorTask;
            stop = stopSource;
            activeRuntime = activeRuntimeGeneration;
            activeCandidate = activeCandidateGeneration;
            runtimeSignal = runtimeConfigurationChanged;
            candidateSignal = candidateChanged;
        }

        CancelIfAlive(stop);
        CancelIfAlive(activeRuntime);
        CancelIfAlive(activeCandidate);
        runtimeSignal.TrySetResult();
        candidateSignal.TrySetResult();
        if (supervisor is null || stop is null)
        {
            return;
        }
        try
        {
            await supervisor.WaitAsync(options.StopTimeout).ConfigureAwait(false);
        }
        catch (OperationCanceledException) when (stop.IsCancellationRequested)
        {
        }
        catch (TimeoutException)
        {
            _ = supervisor.ContinueWith(
                _ => CleanupCompletedSupervisor(supervisor),
                CancellationToken.None,
                TaskContinuationOptions.ExecuteSynchronously,
                TaskScheduler.Default);
            return;
        }
        CleanupCompletedSupervisor(supervisor);
    }

    private async Task SuperviseRuntimeAsync(CancellationToken stoppingToken)
    {
        try
        {
            while (true)
            {
                stoppingToken.ThrowIfCancellationRequested();
                var snapshot = RuntimeSnapshot();
                if (!snapshot.Configuration.RuntimeEligible)
                {
                    await WaitForRuntimeConfigurationChangeAsync(
                        snapshot.Version,
                        stoppingToken).ConfigureAwait(false);
                    continue;
                }

                using var generation = CancellationTokenSource.CreateLinkedTokenSource(
                    stoppingToken);
                lock (gate)
                {
                    if (terminallyStopped || runtimeVersion != snapshot.Version)
                    {
                        continue;
                    }
                    activeRuntimeGeneration = generation;
                }
                try
                {
                    await Task.Delay(
                        options.CredentialDebounce,
                        generation.Token).ConfigureAwait(false);
                    PublishRuntimeAvailability(
                        snapshot.Version,
                        snapshot.Configuration.Candidate,
                        TelegramAvailability.Checking(
                            snapshot.Configuration.Candidate.BotToken,
                            snapshot.Configuration.Candidate.AdminIds));
                    var probeResult = await ProbeWithTimeoutAsync(
                        snapshot.Configuration.Candidate,
                        generation.Token).ConfigureAwait(false);
                    if (!probeResult.Available)
                    {
                        PublishRuntimeUnavailable(
                            snapshot.Version,
                            snapshot.Configuration.Candidate,
                            probeResult.Failure);
                        await DelayUntilRuntimeRetryOrChangeAsync(
                            snapshot.Version,
                            generation.Token).ConfigureAwait(false);
                        continue;
                    }

                    PublishRuntimeAvailable(
                        snapshot.Version,
                        snapshot.Configuration.Candidate);
                    var context = new TelegramRuntimeGenerationContext(
                        snapshot.Configuration,
                        snapshot.Cursor,
                        () => PublishRuntimeAvailable(
                            snapshot.Version,
                            snapshot.Configuration.Candidate),
                        failure => PublishRuntimeUnavailable(
                            snapshot.Version,
                            snapshot.Configuration.Candidate,
                            failure));
                    try
                    {
                        await runGeneration(context, generation.Token).ConfigureAwait(false);
                        PublishRuntimeUnavailable(
                            snapshot.Version,
                            snapshot.Configuration.Candidate,
                            TelegramAvailabilityFailure.NetworkUnavailable);
                    }
                    catch (OperationCanceledException) when (generation.IsCancellationRequested)
                    {
                        throw;
                    }
                    catch
                    {
                        PublishRuntimeUnavailable(
                            snapshot.Version,
                            snapshot.Configuration.Candidate,
                            TelegramAvailabilityFailure.NetworkUnavailable);
                    }
                    await DelayUntilRuntimeRetryOrChangeAsync(
                        snapshot.Version,
                        generation.Token).ConfigureAwait(false);
                }
                catch (OperationCanceledException) when (generation.IsCancellationRequested)
                {
                }
                finally
                {
                    lock (gate)
                    {
                        if (ReferenceEquals(activeRuntimeGeneration, generation))
                        {
                            activeRuntimeGeneration = null;
                        }
                    }
                }
            }
        }
        catch (OperationCanceledException) when (stoppingToken.IsCancellationRequested)
        {
        }
    }

    private async Task SuperviseCandidateAsync(CancellationToken stoppingToken)
    {
        try
        {
            while (true)
            {
                stoppingToken.ThrowIfCancellationRequested();
                var snapshot = CandidateSnapshot();
                if (!snapshot.ProbeEligible)
                {
                    PublishCandidate(
                        snapshot.Version,
                        snapshot.Candidate,
                        TelegramAvailability.Unknown);
                    await WaitForCandidateChangeAsync(
                        snapshot.Version,
                        stoppingToken).ConfigureAwait(false);
                    continue;
                }
                if (snapshot.SuppliedByRuntime)
                {
                    PublishCandidate(
                        snapshot.Version,
                        snapshot.Candidate,
                        snapshot.RuntimeAvailability);
                    await WaitForCandidateChangeAsync(
                        snapshot.Version,
                        stoppingToken).ConfigureAwait(false);
                    continue;
                }

                using var generation = CancellationTokenSource.CreateLinkedTokenSource(
                    stoppingToken);
                lock (gate)
                {
                    if (terminallyStopped || candidateVersion != snapshot.Version)
                    {
                        continue;
                    }
                    activeCandidateGeneration = generation;
                }
                try
                {
                    await Task.Delay(
                        options.CredentialDebounce,
                        generation.Token).ConfigureAwait(false);
                    PublishCandidate(
                        snapshot.Version,
                        snapshot.Candidate,
                        TelegramAvailability.Checking(
                            snapshot.Candidate.BotToken,
                            snapshot.Candidate.AdminIds));
                    var probeResult = await ProbeWithTimeoutAsync(
                        snapshot.Candidate,
                        generation.Token).ConfigureAwait(false);
                    if (probeResult.Available)
                    {
                        PublishCandidateAvailable(snapshot.Version, snapshot.Candidate);
                        await WaitForCandidateChangeAsync(
                            snapshot.Version,
                            generation.Token).ConfigureAwait(false);
                        continue;
                    }
                    PublishCandidateUnavailable(
                        snapshot.Version,
                        snapshot.Candidate,
                        probeResult.Failure);
                    await DelayUntilCandidateRetryOrChangeAsync(
                        snapshot.Version,
                        generation.Token).ConfigureAwait(false);
                }
                catch (OperationCanceledException) when (generation.IsCancellationRequested)
                {
                }
                finally
                {
                    lock (gate)
                    {
                        if (ReferenceEquals(activeCandidateGeneration, generation))
                        {
                            activeCandidateGeneration = null;
                        }
                    }
                }
            }
        }
        catch (OperationCanceledException) when (stoppingToken.IsCancellationRequested)
        {
        }
    }

    private async Task<TelegramAvailabilityProbeResult> ProbeWithTimeoutAsync(
        TelegramAvailabilityCandidate observedCandidate,
        CancellationToken cancellationToken)
    {
        using var timeout = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
        timeout.CancelAfter(options.ProbeTimeout);
        var acquired = false;
        try
        {
            await probeGate.WaitAsync(timeout.Token).ConfigureAwait(false);
            acquired = true;
            return await probe.ProbeAsync(
                observedCandidate,
                timeout.Token).ConfigureAwait(false);
        }
        catch (OperationCanceledException) when (
            timeout.IsCancellationRequested && !cancellationToken.IsCancellationRequested)
        {
            return TelegramAvailabilityProbeResult.Failed(
                TelegramAvailabilityFailure.NetworkUnavailable);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch
        {
            return TelegramAvailabilityProbeResult.Failed(
                TelegramAvailabilityFailure.NetworkUnavailable);
        }
        finally
        {
            if (acquired)
            {
                probeGate.Release();
            }
        }
    }

    private void PublishCandidateAvailable(
        long observedVersion,
        TelegramAvailabilityCandidate observedCandidate) => PublishCandidate(
            observedVersion,
            observedCandidate,
            TelegramAvailability.Available(
                observedCandidate.BotToken,
                observedCandidate.AdminIds));

    private void PublishCandidateUnavailable(
        long observedVersion,
        TelegramAvailabilityCandidate observedCandidate,
        TelegramAvailabilityFailure failure) => PublishCandidate(
            observedVersion,
            observedCandidate,
            TelegramAvailability.Unavailable(
                observedCandidate.BotToken,
                observedCandidate.AdminIds,
                TelegramAvailabilityFailureCopy.UserFacing(failure)));

    private void PublishCandidate(
        long observedVersion,
        TelegramAvailabilityCandidate observedCandidate,
        TelegramAvailability next)
    {
        Action<TelegramAvailability>? handler;
        lock (gate)
        {
            if (terminallyStopped ||
                candidateVersion != observedVersion ||
                !candidate.Identity.Equals(observedCandidate.Identity) ||
                current == next)
            {
                return;
            }
            current = next;
            handler = AvailabilityChanged;
        }
        Notify(handler, next);
    }

    private void PublishRuntimeAvailable(
        long observedVersion,
        TelegramAvailabilityCandidate observedCandidate) => PublishRuntimeAvailability(
            observedVersion,
            observedCandidate,
            TelegramAvailability.Available(
                observedCandidate.BotToken,
                observedCandidate.AdminIds));

    private void PublishRuntimeUnavailable(
        long observedVersion,
        TelegramAvailabilityCandidate observedCandidate,
        TelegramAvailabilityFailure failure) => PublishRuntimeAvailability(
            observedVersion,
            observedCandidate,
            TelegramAvailability.Unavailable(
                observedCandidate.BotToken,
                observedCandidate.AdminIds,
                TelegramAvailabilityFailureCopy.UserFacing(failure)));

    private void PublishRuntimeAvailability(
        long observedVersion,
        TelegramAvailabilityCandidate observedCandidate,
        TelegramAvailability next)
    {
        Action<TelegramAvailability>? handler = null;
        lock (gate)
        {
            if (terminallyStopped ||
                runtimeVersion != observedVersion ||
                !configuration.Candidate.Identity.Equals(observedCandidate.Identity))
            {
                return;
            }
            runtimeAvailability = next;
            if (candidate.Identity.Equals(observedCandidate.Identity) && current != next)
            {
                current = next;
                handler = AvailabilityChanged;
            }
        }
        Notify(handler, next);
    }

    private static void Notify(
        Action<TelegramAvailability>? handler,
        TelegramAvailability next)
    {
        if (handler is null)
        {
            return;
        }
        foreach (Action<TelegramAvailability> subscriber in handler.GetInvocationList())
        {
            try
            {
                subscriber(next);
            }
            catch
            {
                // An observer cannot terminate credential verification or polling.
            }
        }
    }

    private async Task DelayUntilRuntimeRetryOrChangeAsync(
        long observedVersion,
        CancellationToken cancellationToken)
    {
        await DelayUntilRetryOrChangeAsync(
            token => WaitForRuntimeConfigurationChangeAsync(observedVersion, token),
            cancellationToken).ConfigureAwait(false);
    }

    private async Task DelayUntilCandidateRetryOrChangeAsync(
        long observedVersion,
        CancellationToken cancellationToken)
    {
        await DelayUntilRetryOrChangeAsync(
            token => WaitForCandidateChangeAsync(observedVersion, token),
            cancellationToken).ConfigureAwait(false);
    }

    private async Task DelayUntilRetryOrChangeAsync(
        Func<CancellationToken, Task> waitForChange,
        CancellationToken cancellationToken)
    {
        using var race = CancellationTokenSource.CreateLinkedTokenSource(
            cancellationToken);
        var changed = waitForChange(race.Token);
        var retry = Task.Delay(options.RetryDelay, race.Token);
        await Task.WhenAny(changed, retry).ConfigureAwait(false);
        race.Cancel();
        await ObserveRaceTaskAsync(changed, race.Token).ConfigureAwait(false);
        await ObserveRaceTaskAsync(retry, race.Token).ConfigureAwait(false);
        cancellationToken.ThrowIfCancellationRequested();
    }

    private static async Task ObserveRaceTaskAsync(
        Task task,
        CancellationToken raceToken)
    {
        try
        {
            await task.ConfigureAwait(false);
        }
        catch (OperationCanceledException) when (raceToken.IsCancellationRequested)
        {
        }
    }

    private async Task WaitForRuntimeConfigurationChangeAsync(
        long observedVersion,
        CancellationToken cancellationToken)
    {
        Interlocked.Increment(ref pendingRuntimeConfigurationChangeWaiters);
        try
        {
            Task signal;
            lock (gate)
            {
                if (runtimeVersion != observedVersion)
                {
                    return;
                }
                signal = runtimeConfigurationChanged.Task;
            }
            await signal.WaitAsync(cancellationToken).ConfigureAwait(false);
        }
        finally
        {
            Interlocked.Decrement(ref pendingRuntimeConfigurationChangeWaiters);
        }
    }

    private async Task WaitForCandidateChangeAsync(
        long observedVersion,
        CancellationToken cancellationToken)
    {
        Interlocked.Increment(ref pendingCandidateChangeWaiters);
        try
        {
            Task signal;
            lock (gate)
            {
                if (candidateVersion != observedVersion)
                {
                    return;
                }
                signal = candidateChanged.Task;
            }
            await signal.WaitAsync(cancellationToken).ConfigureAwait(false);
        }
        finally
        {
            Interlocked.Decrement(ref pendingCandidateChangeWaiters);
        }
    }

    private RuntimeCoordinatorSnapshot RuntimeSnapshot()
    {
        lock (gate)
        {
            return new RuntimeCoordinatorSnapshot(
                configuration,
                cursor,
                runtimeVersion);
        }
    }

    private CandidateCoordinatorSnapshot CandidateSnapshot()
    {
        lock (gate)
        {
            return new CandidateCoordinatorSnapshot(
                candidate,
                configuration.NetworkAllowed &&
                    configuration.FeatureAllowed &&
                    candidate.ConfigurationReady,
                configuration.RuntimeEligible &&
                    configuration.Candidate.Identity.Equals(candidate.Identity),
                runtimeAvailability,
                candidateVersion);
        }
    }

    private void CleanupCompletedSupervisor(Task supervisor)
    {
        lock (gate)
        {
            if (!ReferenceEquals(supervisorTask, supervisor) || !supervisor.IsCompleted)
            {
                return;
            }
            supervisorTask = null;
            activeRuntimeGeneration?.Dispose();
            activeRuntimeGeneration = null;
            activeCandidateGeneration?.Dispose();
            activeCandidateGeneration = null;
            stopSource?.Dispose();
            stopSource = null;
        }
    }

    private static TaskCompletionSource NewSignal() => new(
        TaskCreationOptions.RunContinuationsAsynchronously);

    private static void CancelIfAlive(CancellationTokenSource? source)
    {
        try
        {
            source?.Cancel();
        }
        catch (ObjectDisposedException)
        {
            // The completed generation cleared itself between snapshot and cancel.
        }
    }

    private sealed record RuntimeCoordinatorSnapshot(
        TelegramRuntimeConfiguration Configuration,
        TelegramPollingCursor Cursor,
        long Version);

    private sealed record CandidateCoordinatorSnapshot(
        TelegramAvailabilityCandidate Candidate,
        bool ProbeEligible,
        bool SuppliedByRuntime,
        TelegramAvailability RuntimeAvailability,
        long Version);
}
