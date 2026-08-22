using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.EngineIntegration.Supervision;

namespace Sonar.Fishing.Host.EngineIntegration;

internal sealed class ProductionEngineHealthUseCase(
    EngineSessionSupervisor supervisor,
    TimeSpan timeout) : IEngineHealthUseCase, IAsyncDisposable
{
    private readonly EngineSessionSupervisor supervisor = supervisor ??
        throw new ArgumentNullException(nameof(supervisor));
    private readonly TimeSpan timeout = RequireTimeout(timeout);
    private bool disposed;

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
            OfflineEngineSessionProtocol.NativeProductionAuthority,
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

    private static TimeSpan RequireTimeout(TimeSpan value) =>
        value <= TimeSpan.Zero || value > TimeSpan.FromSeconds(30)
            ? throw new ArgumentOutOfRangeException(nameof(value))
            : value;
}
