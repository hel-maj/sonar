using System.Runtime.InteropServices;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.HostHotkeys;

internal interface IHostHotkeyRuntimeLifecycle
{
    Task StartAsync();

    Task StopAsync();
}

internal sealed class StartStopHotkeyRuntime : IHostHotkeyRuntimeLifecycle
{
    private readonly IHotkeyStateReader stateReader;
    private readonly Func<FishingRuntimeSettings> currentSettings;
    private readonly IFishingAutomationRuntime automation;
    private readonly Func<bool> hostWindowActive;
    private readonly TimeSpan pollInterval;
    private readonly StartStopHotkeyStateMachine stateMachine = new();
    private readonly CancellationTokenSource lifetimeCancellation = new();
    private readonly object sync = new();
    private Task? runTask;
    private bool stopRequested;
    private FishingSessionStateSnapshot session = FishingSessionStateSnapshot.Empty;

    internal StartStopHotkeyRuntime(
        IHotkeyStateReader stateReader,
        Func<FishingRuntimeSettings> currentSettings,
        IFishingAutomationRuntime automation,
        Func<bool> hostWindowActive,
        TimeSpan? pollInterval = null)
    {
        this.stateReader = stateReader ?? throw new ArgumentNullException(nameof(stateReader));
        this.currentSettings = currentSettings ??
            throw new ArgumentNullException(nameof(currentSettings));
        this.automation = automation ?? throw new ArgumentNullException(nameof(automation));
        this.hostWindowActive = hostWindowActive ??
            throw new ArgumentNullException(nameof(hostWindowActive));
        this.pollInterval = pollInterval ?? TimeSpan.FromMilliseconds(50);
        if (this.pollInterval <= TimeSpan.Zero ||
            this.pollInterval > TimeSpan.FromSeconds(1))
        {
            throw new ArgumentOutOfRangeException(nameof(pollInterval));
        }
        if (automation is IFishingAutomationStateSource stateSource)
        {
            stateSource.SessionStateChanged += OnSessionStateChanged;
        }
    }

    public Task StartAsync()
    {
        lock (sync)
        {
            if (stopRequested)
            {
                return Task.CompletedTask;
            }
            runTask ??= RunAsync(lifetimeCancellation.Token);
            return Task.CompletedTask;
        }
    }

    public async Task StopAsync()
    {
        Task? current;
        lock (sync)
        {
            if (!stopRequested)
            {
                stopRequested = true;
                lifetimeCancellation.Cancel();
            }
            current = runTask;
        }
        if (current is not null)
        {
            await current.ConfigureAwait(false);
        }
    }

    internal async Task PollOnceAsync(CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        HotkeyGesture gesture;
        bool captureActive;
        bool isDown;
        try
        {
            gesture = HotkeyGesture.ParseInvariant(currentSettings().Hotkeys.StartStop);
            captureActive = hostWindowActive();
            isDown = stateReader.IsDown(gesture);
        }
        catch (Exception) when (!cancellationToken.IsCancellationRequested)
        {
            stateMachine.SuppressUntilRelease();
            return;
        }

        var current = Volatile.Read(ref session);
        var outcome = stateMachine.Poll(new StartStopHotkeySample(
            CanStartOrStop: current.Running || current.Stopping ||
                automation.HasActiveEntitlement,
            CaptureActive: captureActive,
            GestureValid: HotkeyVirtualKeyMapper.Map(gesture).Count > 0,
            IsDown: isDown,
            BotStopping: current.Stopping));
        if (outcome != StartStopHotkeyOutcome.ToggleRequested)
        {
            return;
        }

        try
        {
            var updated = current.Running
                ? await automation.StopAsync(cancellationToken).ConfigureAwait(false)
                : await automation.StartAsync(cancellationToken).ConfigureAwait(false);
            Volatile.Write(ref session, updated);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (Exception)
        {
            // Admission and boundary failures remain visible on the regular
            // Fishing surface; the global key reader never retries a held key.
        }
    }

    private async Task RunAsync(CancellationToken cancellationToken)
    {
        using var timer = new PeriodicTimer(pollInterval);
        try
        {
            while (await timer.WaitForNextTickAsync(cancellationToken).ConfigureAwait(false))
            {
                await PollOnceAsync(cancellationToken).ConfigureAwait(false);
            }
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
        }
    }

    private void OnSessionStateChanged(FishingSessionStateSnapshot snapshot) =>
        Volatile.Write(ref session, snapshot);
}

internal static class ProductWindowFocusProbe
{
    internal static bool IsActive()
    {
        var foreground = GetForegroundWindow();
        if (foreground == IntPtr.Zero)
        {
            return true;
        }
        _ = GetWindowThreadProcessId(foreground, out var processId);
        return processId == Environment.ProcessId;
    }

    [DllImport("user32.dll")]
    private static extern IntPtr GetForegroundWindow();

    [DllImport("user32.dll")]
    private static extern uint GetWindowThreadProcessId(
        IntPtr window,
        out int processId);
}
