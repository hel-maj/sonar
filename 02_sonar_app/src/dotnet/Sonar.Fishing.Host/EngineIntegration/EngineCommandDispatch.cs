namespace Sonar.Fishing.Host.EngineIntegration;

internal readonly record struct EngineCommandDispatchReceipt(
    bool BytesMayHaveBeenWritten);

internal readonly record struct EngineCommandDispatchReceipt<T>(
    T Result,
    bool BytesMayHaveBeenWritten);

internal sealed class EngineCommandDispatchException : Exception
{
    internal EngineCommandDispatchException(
        bool bytesMayHaveBeenWritten,
        Exception innerException)
        : base(
            "engine_command_dispatch_failed",
            innerException ?? throw new ArgumentNullException(nameof(innerException)))
    {
        BytesMayHaveBeenWritten = bytesMayHaveBeenWritten;
    }

    internal bool BytesMayHaveBeenWritten { get; }
}

internal sealed class EngineCommandDispatchState
{
    private const int Pending = 0;
    private const int WriteMayHaveStarted = 1;
    private const int CancelledBeforeWrite = 2;

    private int state;

    internal bool BytesMayHaveBeenWritten =>
        Volatile.Read(ref state) == WriteMayHaveStarted;

    internal void EnterWriteBoundary(CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        var observed = Interlocked.CompareExchange(
            ref state,
            WriteMayHaveStarted,
            Pending);
        if (observed == CancelledBeforeWrite)
        {
            throw new OperationCanceledException(
                "engine_command_cancelled_before_write",
                cancellationToken);
        }
    }

    internal void CancelBeforeWrite() =>
        _ = Interlocked.CompareExchange(ref state, CancelledBeforeWrite, Pending);
}

internal sealed class EngineCommandDispatch<T>
{
    private readonly EngineCommandDispatchState state;

    internal EngineCommandDispatch(
        EngineCommandDispatchState state,
        Task<EngineCommandDispatchReceipt<T>> completion)
    {
        this.state = state ?? throw new ArgumentNullException(nameof(state));
        Completion = completion ?? throw new ArgumentNullException(nameof(completion));
    }

    internal Task<EngineCommandDispatchReceipt<T>> Completion { get; }

    internal bool BytesMayHaveBeenWritten => state.BytesMayHaveBeenWritten;

    internal void CancelBeforeWrite() => state.CancelBeforeWrite();

    internal EngineCommandDispatch<TResult> Map<TResult>(Func<T, TResult> map)
    {
        ArgumentNullException.ThrowIfNull(map);
        return new EngineCommandDispatch<TResult>(state, MapCompletionAsync());

        async Task<EngineCommandDispatchReceipt<TResult>> MapCompletionAsync()
        {
            var receipt = await Completion.ConfigureAwait(false);
            return new EngineCommandDispatchReceipt<TResult>(
                map(receipt.Result),
                receipt.BytesMayHaveBeenWritten);
        }
    }
}
