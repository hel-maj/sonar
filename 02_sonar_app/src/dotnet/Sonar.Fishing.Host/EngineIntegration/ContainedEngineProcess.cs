using System.Diagnostics;
using Sonar.Platform.Processes;

namespace Sonar.Fishing.Host.EngineIntegration;

/// <summary>
/// Product-owned child lifecycle around the Common kill-on-close primitive.
/// </summary>
internal sealed class ContainedEngineProcess : IAsyncDisposable
{
    private static readonly TimeSpan DisposeExitTimeout = TimeSpan.FromSeconds(5);

    private readonly Process process;
    private readonly KillOnCloseJob containment;
    private bool disposed;

    private ContainedEngineProcess(Process process, KillOnCloseJob containment)
    {
        this.process = process;
        this.containment = containment;
    }

    internal Process Process
    {
        get
        {
            ObjectDisposedException.ThrowIf(disposed, this);
            return process;
        }
    }

    internal int Id => Process.Id;

    internal bool IsContained => containment.Contains(Process);

    internal static ContainedEngineProcess Start(ProcessStartInfo startInfo)
    {
        ArgumentNullException.ThrowIfNull(startInfo);
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
                throw new InvalidOperationException("engine_process_start_failed");
            }
            started = true;
            containment.Assign(process);
            if (!containment.Contains(process))
            {
                throw new InvalidOperationException("engine_process_containment_missing");
            }
            return new ContainedEngineProcess(process, containment);
        }
        catch
        {
            containment.Dispose();
            if (started && !process.HasExited)
            {
                process.WaitForExit(checked((int)DisposeExitTimeout.TotalMilliseconds));
            }
            process.Dispose();
            throw;
        }
    }

    public async ValueTask DisposeAsync()
    {
        if (disposed)
        {
            return;
        }

        disposed = true;
        containment.Dispose();
        try
        {
            if (!process.HasExited)
            {
                await process.WaitForExitAsync(CancellationToken.None)
                    .WaitAsync(DisposeExitTimeout)
                    .ConfigureAwait(false);
            }
        }
        finally
        {
            process.Dispose();
        }
    }
}
