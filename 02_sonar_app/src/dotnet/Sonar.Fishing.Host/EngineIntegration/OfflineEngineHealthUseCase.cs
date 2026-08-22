using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.EngineIntegration.Supervision;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.EngineIntegration;

public sealed class OfflineEngineHealthUseCase : IEngineHealthUseCase, IAsyncDisposable
{
    private readonly TimeSpan timeout;
    private readonly EngineSessionSupervisor supervisor;
    private bool disposed;

    public OfflineEngineHealthUseCase(
        string engineExecutable,
        TimeSpan timeout,
        FishingRuntimeSettings runtimeSettings)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(engineExecutable);
        if (timeout <= TimeSpan.Zero || timeout > TimeSpan.FromSeconds(30))
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }

        this.timeout = timeout;
        runtimeSettings = runtimeSettings ?? throw new ArgumentNullException(nameof(runtimeSettings));
        runtimeSettings.Validate();
        supervisor = new EngineSessionSupervisor(
            new OfflineEngineManagedSessionFactory(
                engineExecutable,
                timeout,
                runtimeSettings),
            EngineRestartPolicy.Default);
    }

    public async Task<EngineHealthResult> RunAsync(CancellationToken cancellationToken)
    {
        ObjectDisposedException.ThrowIf(disposed, this);
        using var operationCancellation = CancellationTokenSource.CreateLinkedTokenSource(
            cancellationToken);
        operationCancellation.CancelAfter(timeout);
        var current = await supervisor.CheckAsync(operationCancellation.Token)
            .ConfigureAwait(false);
        return new EngineHealthResult(
            current.ProcessId,
            current.IsContained,
            current.NegotiatedProtocolMinor,
            SideEffectsEnabled: false,
            OfflineEngineSessionProtocol.OfflineDiagnosticAuthority,
            current.SessionState);
    }

    public async ValueTask DisposeAsync()
    {
        if (disposed)
        {
            return;
        }

        disposed = true;
        await supervisor.DisposeAsync().ConfigureAwait(false);
    }
}
