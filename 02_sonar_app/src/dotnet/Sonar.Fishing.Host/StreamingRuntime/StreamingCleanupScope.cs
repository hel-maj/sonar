using System.Diagnostics;

namespace Sonar.Fishing.Host.StreamingRuntime;

internal static class StreamingCleanupScope
{
    internal static async ValueTask<string?> RunAsync(
        TimeSpan timeout,
        params Func<CancellationToken, ValueTask>[] actions)
    {
        if (timeout <= TimeSpan.Zero)
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }
        ArgumentNullException.ThrowIfNull(actions);

        var deadline = Stopwatch.GetTimestamp() +
            (long)(timeout.TotalSeconds * Stopwatch.Frequency);
        string? firstFailure = null;
        foreach (var action in actions)
        {
            if (action is null)
            {
                firstFailure ??= "streaming_cleanup_action_invalid";
                continue;
            }

            var remaining = Remaining(deadline);
            if (remaining <= TimeSpan.Zero)
            {
                firstFailure ??= "streaming_cleanup_timeout";
                break;
            }
            using var cancellation = new CancellationTokenSource(remaining);
            try
            {
                await action(cancellation.Token).AsTask()
                    .WaitAsync(remaining, CancellationToken.None)
                    .ConfigureAwait(false);
            }
            catch (Exception exception) when (
                exception is OperationCanceledException or TimeoutException)
            {
                firstFailure ??= "streaming_cleanup_timeout";
            }
            catch (StreamingRuntimeException exception)
            {
                firstFailure ??= exception.Reason;
            }
            catch
            {
                firstFailure ??= "streaming_cleanup_failed";
            }
        }
        return firstFailure;
    }

    private static TimeSpan Remaining(long deadline)
    {
        var ticks = deadline - Stopwatch.GetTimestamp();
        return ticks <= 0
            ? TimeSpan.Zero
            : TimeSpan.FromSeconds((double)ticks / Stopwatch.Frequency);
    }
}
