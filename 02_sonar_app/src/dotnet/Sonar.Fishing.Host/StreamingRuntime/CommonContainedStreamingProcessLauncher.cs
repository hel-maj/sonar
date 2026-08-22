using System.Diagnostics;
using System.IO;
using System.Threading.Channels;
using Sonar.Platform.Processes;

namespace Sonar.Fishing.Host.StreamingRuntime;

/// <summary>
/// Product lifecycle around the Common kill-on-close containment primitive.
/// </summary>
internal sealed class CommonContainedStreamingProcessLauncher : IStreamingProcessLauncher
{
    public ValueTask<IStreamingProcessLease> StartAsync(
        StreamingProcessRequest request,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(request);
        cancellationToken.ThrowIfCancellationRequested();
        ValidateRequest(request);

        var startInfo = new ProcessStartInfo
        {
            FileName = request.ExecutablePath,
            WorkingDirectory = Path.GetDirectoryName(request.ExecutablePath)!,
            UseShellExecute = false,
            CreateNoWindow = true,
            RedirectStandardInput = request.GracefulStopInput is not null,
            RedirectStandardOutput = request.CaptureDiagnosticOutput,
            RedirectStandardError = request.CaptureDiagnosticOutput,
        };
        foreach (var argument in request.Arguments)
        {
            startInfo.ArgumentList.Add(argument);
        }

        var containment = KillOnCloseJob.Create();
        var process = new Process
        {
            StartInfo = startInfo,
            EnableRaisingEvents = true,
        };
        var started = false;
        try
        {
            if (!process.Start())
            {
                throw new StreamingRuntimeException("streaming_process_start_failed");
            }
            started = true;
            containment.Assign(process);
            if (!containment.Contains(process))
            {
                throw new StreamingRuntimeException("streaming_process_containment_missing");
            }
            cancellationToken.ThrowIfCancellationRequested();
            return ValueTask.FromResult<IStreamingProcessLease>(
                new CommonContainedStreamingProcessLease(process, containment, request));
        }
        catch (OperationCanceledException)
        {
            containment.Dispose();
            if (started && !process.HasExited)
            {
                _ = process.WaitForExit(milliseconds: 5000);
            }
            process.Dispose();
            throw;
        }
        catch (Exception exception) when (exception is not StreamingRuntimeException)
        {
            containment.Dispose();
            if (started && !process.HasExited)
            {
                _ = process.WaitForExit(milliseconds: 5000);
            }
            process.Dispose();
            throw new StreamingRuntimeException("streaming_process_start_failed", exception);
        }
        catch
        {
            containment.Dispose();
            if (started && !process.HasExited)
            {
                _ = process.WaitForExit(milliseconds: 5000);
            }
            process.Dispose();
            throw;
        }
    }

    private static void ValidateRequest(StreamingProcessRequest request)
    {
        if (!Path.IsPathFullyQualified(request.ExecutablePath) ||
            !File.Exists(request.ExecutablePath) ||
            request.Arguments is null ||
            request.Arguments.Any(static argument => argument is null))
        {
            throw new StreamingRuntimeException("streaming_process_request_invalid");
        }
    }
}

internal sealed class CommonContainedStreamingProcessLease : IStreamingProcessLease
{
    private const int DiagnosticCapacity = 128;

    private readonly Process process;
    private readonly KillOnCloseJob containment;
    private readonly string? gracefulStopInput;
    private readonly Channel<string>? diagnosticLines;
    private readonly CancellationTokenSource diagnosticCancellation = new();
    private readonly Task diagnosticCompletion;
    private readonly SemaphoreSlim stopGate = new(1, 1);
    private bool stopped;

    internal CommonContainedStreamingProcessLease(
        Process process,
        KillOnCloseJob containment,
        StreamingProcessRequest request)
    {
        this.process = process;
        this.containment = containment;
        gracefulStopInput = request.GracefulStopInput;
        Role = request.Role;
        Completion = ObserveExitAsync();

        if (request.CaptureDiagnosticOutput)
        {
            diagnosticLines = Channel.CreateBounded<string>(new BoundedChannelOptions(
                DiagnosticCapacity)
            {
                SingleReader = true,
                SingleWriter = false,
                FullMode = BoundedChannelFullMode.Wait,
            });
            diagnosticCompletion = CompleteDiagnosticsAsync(
                PumpDiagnosticsAsync(process.StandardOutput, diagnosticCancellation.Token),
                PumpDiagnosticsAsync(process.StandardError, diagnosticCancellation.Token));
        }
        else
        {
            diagnosticCompletion = Task.CompletedTask;
        }
    }

    public StreamingProcessRole Role { get; }

    public Task<StreamingProcessExit> Completion { get; }

    public async ValueTask<string?> ReadDiagnosticLineAsync(
        CancellationToken cancellationToken)
    {
        if (diagnosticLines is null)
        {
            return null;
        }
        while (await diagnosticLines.Reader.WaitToReadAsync(cancellationToken)
                   .ConfigureAwait(false))
        {
            if (diagnosticLines.Reader.TryRead(out var line))
            {
                return line;
            }
        }
        return null;
    }

    public async ValueTask StopAsync(
        TimeSpan timeout,
        CancellationToken cancellationToken)
    {
        if (timeout <= TimeSpan.Zero)
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }

        await stopGate.WaitAsync(cancellationToken).ConfigureAwait(false);
        try
        {
            if (stopped)
            {
                return;
            }

            var deadline = Stopwatch.GetTimestamp() +
                (long)(timeout.TotalSeconds * Stopwatch.Frequency);
            if (!process.HasExited && gracefulStopInput is not null)
            {
                try
                {
                    await process.StandardInput.WriteLineAsync(
                            gracefulStopInput.AsMemory(),
                            cancellationToken)
                        .ConfigureAwait(false);
                    await process.StandardInput.FlushAsync(cancellationToken)
                        .ConfigureAwait(false);
                }
                catch (IOException)
                {
                    // The process may exit between the state check and the write.
                }
                catch (InvalidOperationException)
                {
                    // Standard input is already closed by an exiting process.
                }
                catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
                {
                    // Cancellation skips the graceful wait but never the Job hard stop.
                }
            }

            if (!process.HasExited)
            {
                try
                {
                    await process.WaitForExitAsync(cancellationToken)
                        .WaitAsync(Remaining(deadline), cancellationToken)
                        .ConfigureAwait(false);
                }
                catch (TimeoutException)
                {
                    // Closing the Common Job is the bounded hard-stop fallback.
                }
                catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
                {
                    // Closing the Common Job remains mandatory after cancellation.
                }
            }

            containment.Dispose();
            try
            {
                if (!process.HasExited)
                {
                    await process.WaitForExitAsync(CancellationToken.None)
                        .WaitAsync(Remaining(deadline), CancellationToken.None)
                        .ConfigureAwait(false);
                }

                diagnosticCancellation.Cancel();
                await diagnosticCompletion
                    .WaitAsync(Remaining(deadline), CancellationToken.None)
                    .ConfigureAwait(false);
            }
            finally
            {
                process.Dispose();
                stopped = true;
            }
        }
        catch (TimeoutException exception)
        {
            throw new StreamingRuntimeException("streaming_process_cleanup_timeout", exception);
        }
        finally
        {
            stopGate.Release();
        }
    }

    public async ValueTask DisposeAsync()
    {
        await StopAsync(TimeSpan.FromSeconds(5), CancellationToken.None)
            .ConfigureAwait(false);
    }

    private async Task<StreamingProcessExit> ObserveExitAsync()
    {
        await process.WaitForExitAsync(CancellationToken.None).ConfigureAwait(false);
        return new StreamingProcessExit(process.ExitCode);
    }

    private async Task PumpDiagnosticsAsync(
        StreamReader reader,
        CancellationToken cancellationToken)
    {
        try
        {
            while (await reader.ReadLineAsync(cancellationToken).ConfigureAwait(false) is { } line)
            {
                await diagnosticLines!.Writer.WriteAsync(line, cancellationToken)
                    .ConfigureAwait(false);
            }
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
        }
        catch (IOException)
        {
        }
    }

    private async Task CompleteDiagnosticsAsync(Task standardOutput, Task standardError)
    {
        try
        {
            await Task.WhenAll(standardOutput, standardError).ConfigureAwait(false);
            diagnosticLines!.Writer.TryComplete();
        }
        catch (Exception exception)
        {
            diagnosticLines!.Writer.TryComplete(exception);
        }
    }

    private static TimeSpan Remaining(long deadline)
    {
        var remainingTicks = deadline - Stopwatch.GetTimestamp();
        if (remainingTicks <= 0)
        {
            throw new TimeoutException();
        }
        return TimeSpan.FromSeconds((double)remainingTicks / Stopwatch.Frequency);
    }
}
