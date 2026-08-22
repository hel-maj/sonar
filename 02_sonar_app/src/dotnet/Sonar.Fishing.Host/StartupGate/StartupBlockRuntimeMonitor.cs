namespace Sonar.Fishing.Host.StartupGate;

public sealed class StartupBlockRuntimeMonitor
{
    public static readonly TimeSpan DefaultInterval = TimeSpan.FromMinutes(5);

    private readonly IStartupBlockCheck startupBlockCheck;
    private readonly Func<StartupBlockRequest> requestFactory;
    private readonly Func<StartupBlockStatus, CancellationToken, Task> signedBlockHandler;
    private readonly Func<TimeSpan, CancellationToken, Task> delay;
    private readonly TimeSpan interval;

    public StartupBlockRuntimeMonitor(
        IStartupBlockCheck startupBlockCheck,
        Func<StartupBlockRequest> requestFactory,
        Func<StartupBlockStatus, CancellationToken, Task> signedBlockHandler,
        TimeSpan? interval = null,
        Func<TimeSpan, CancellationToken, Task>? delay = null)
    {
        this.startupBlockCheck = startupBlockCheck ??
            throw new ArgumentNullException(nameof(startupBlockCheck));
        this.requestFactory = requestFactory ?? throw new ArgumentNullException(nameof(requestFactory));
        this.signedBlockHandler = signedBlockHandler ??
            throw new ArgumentNullException(nameof(signedBlockHandler));
        this.interval = interval ?? DefaultInterval;
        if (this.interval <= TimeSpan.Zero || this.interval > TimeSpan.FromHours(24))
        {
            throw new ArgumentOutOfRangeException(nameof(interval));
        }
        this.delay = delay ?? Task.Delay;
    }

    public async Task RunAsync(CancellationToken cancellationToken)
    {
        while (true)
        {
            await delay(interval, cancellationToken).ConfigureAwait(false);

            StartupBlockStatus status;
            try
            {
                status = await startupBlockCheck.CheckAsync(
                    requestFactory(),
                    cancellationToken).ConfigureAwait(false);
            }
            catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
            {
                throw;
            }
            catch (Exception)
            {
                status = StartupBlockStatus.Failure("startup_block_runtime_check_failed");
            }

            if (!StartupAdmissionPolicy.MustStopRunningApplication(status))
            {
                continue;
            }

            await signedBlockHandler(status, cancellationToken).ConfigureAwait(false);
            return;
        }
    }
}
