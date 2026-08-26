using System.Diagnostics;
using System.Globalization;
using System.Runtime.InteropServices;

namespace Sonar.Fishing.Host.StreamingRuntime;

/// <summary>
/// Resolves one current GTA window for FFmpeg's HWND capture input. No display
/// size or absolute desktop coordinate becomes part of the capture contract.
/// </summary>
internal sealed class Win32GtaStreamingCaptureSource : IStreamingCaptureSource
{
    public ValueTask<StreamingCaptureDescriptor> ResolveAsync(
        bool chatZoomEnabled,
        CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        var candidates = Process.GetProcessesByName("GTA5")
            .Select(TryDescribe)
            .Where(static candidate => candidate is not null)
            .Cast<WindowCandidate>()
            .ToArray();
        if (candidates.Length != 1)
        {
            throw new StreamingRuntimeException(
                candidates.Length == 0
                    ? "streaming_game_window_missing"
                    : "streaming_game_window_ambiguous");
        }

        var candidate = candidates[0];
        var arguments = new List<string> { "-draw_mouse", "0" };
        if (chatZoomEnabled)
        {
            var width = Math.Max(320, checked(candidate.ClientWidth * 9 / 32));
            var height = Math.Max(240, checked(candidate.ClientHeight * 2 / 3));
            width = Math.Min(width, candidate.ClientWidth);
            height = Math.Min(height, candidate.ClientHeight);
            arguments.AddRange(
            [
                "-offset_x", "0",
                "-offset_y", "0",
                "-video_size",
                $"{width.ToString(CultureInfo.InvariantCulture)}x" +
                height.ToString(CultureInfo.InvariantCulture),
            ]);
        }

        return ValueTask.FromResult(new StreamingCaptureDescriptor(
            "gdigrab",
            $"hwnd=0x{candidate.Handle.ToInt64():X}",
            arguments));
    }

    private static WindowCandidate? TryDescribe(Process process)
    {
        using (process)
        {
            try
            {
                var handle = process.MainWindowHandle;
                if (handle == IntPtr.Zero || IsIconic(handle) ||
                    !GetClientRect(handle, out var bounds) ||
                    bounds.Right <= bounds.Left || bounds.Bottom <= bounds.Top)
                {
                    return null;
                }

                _ = GetWindowThreadProcessId(handle, out var ownerProcessId);
                return ownerProcessId == process.Id
                    ? new WindowCandidate(
                        handle,
                        bounds.Right - bounds.Left,
                        bounds.Bottom - bounds.Top)
                    : null;
            }
            catch (InvalidOperationException)
            {
                return null;
            }
            catch (System.ComponentModel.Win32Exception)
            {
                return null;
            }
        }
    }

    [DllImport("user32.dll")]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static extern bool GetClientRect(IntPtr window, out NativeRect bounds);

    [DllImport("user32.dll")]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static extern bool IsIconic(IntPtr window);

    [DllImport("user32.dll")]
    private static extern uint GetWindowThreadProcessId(
        IntPtr window,
        out int processId);

    [StructLayout(LayoutKind.Sequential)]
    private struct NativeRect
    {
        internal int Left;
        internal int Top;
        internal int Right;
        internal int Bottom;
    }

    private sealed record WindowCandidate(
        IntPtr Handle,
        int ClientWidth,
        int ClientHeight);
}
