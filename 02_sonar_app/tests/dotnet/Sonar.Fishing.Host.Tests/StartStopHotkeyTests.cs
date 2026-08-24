using Sonar.Fishing.Host.HostHotkeys;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.Tests;

internal static class StartStopHotkeyTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("start_stop_hotkey_fires_only_on_rising_edge", RisingEdgeOnly),
        new("start_stop_hotkey_capture_suppresses_until_full_release", CaptureSuppresses),
        new("start_stop_hotkey_preserves_legacy_stopping_and_eligibility_semantics", EligibilityAndStopping),
        new("start_stop_hotkey_maps_common_gesture_to_exact_virtual_keys", GestureMaps),
        new("start_stop_hotkey_runtime_toggles_coarse_automation_once_per_press", RuntimeTogglesCoarseAutomation),
        new("start_stop_hotkey_runtime_suppresses_focused_window_until_release", RuntimeSuppressesFocusedWindow),
        new("start_stop_hotkey_runtime_stop_before_start_is_terminal", RuntimeStopBeforeStartIsTerminal),
    ];

    private static void RisingEdgeOnly()
    {
        var gate = new StartStopHotkeyStateMachine();
        TestAssert.Equal(StartStopHotkeyOutcome.None, gate.Poll(Sample(isDown: false)), "Idle poll fired");
        TestAssert.Equal(
            StartStopHotkeyOutcome.ToggleRequested,
            gate.Poll(Sample(isDown: true)),
            "Rising edge did not toggle");
        TestAssert.Equal(StartStopHotkeyOutcome.None, gate.Poll(Sample(isDown: true)), "Held key repeated");
        TestAssert.Equal(StartStopHotkeyOutcome.None, gate.Poll(Sample(isDown: false)), "Release fired");
        TestAssert.Equal(
            StartStopHotkeyOutcome.ToggleRequested,
            gate.Poll(Sample(isDown: true)),
            "Second rising edge did not toggle");
    }

    private static void CaptureSuppresses()
    {
        var gate = new StartStopHotkeyStateMachine();
        TestAssert.Equal(
            StartStopHotkeyOutcome.None,
            gate.Poll(Sample(isDown: true, captureActive: true)),
            "Capture emitted a product action");
        TestAssert.True(gate.IsSuppressedUntilRelease, "Capture did not arm suppression");
        TestAssert.Equal(
            StartStopHotkeyOutcome.None,
            gate.Poll(Sample(isDown: true)),
            "Captured held key leaked through");
        TestAssert.Equal(
            StartStopHotkeyOutcome.None,
            gate.Poll(Sample(isDown: false)),
            "Suppression release emitted an action");
        TestAssert.True(!gate.IsSuppressedUntilRelease, "Full release did not clear suppression");
        TestAssert.Equal(
            StartStopHotkeyOutcome.ToggleRequested,
            gate.Poll(Sample(isDown: true)),
            "Fresh press after release was lost");
    }

    private static void EligibilityAndStopping()
    {
        var gate = new StartStopHotkeyStateMachine();
        TestAssert.Equal(
            StartStopHotkeyOutcome.None,
            gate.Poll(Sample(isDown: true, canStartOrStop: false)),
            "Ineligible state emitted an action");
        TestAssert.Equal(
            StartStopHotkeyOutcome.StoppingNoticeRequested,
            gate.Poll(Sample(isDown: true, botStopping: true)),
            "Legacy eligibility reset or stopping notice changed");
        TestAssert.Equal(
            StartStopHotkeyOutcome.None,
            gate.Poll(Sample(isDown: true, botStopping: true)),
            "Held stopping hotkey repeated notice");
    }

    private static void GestureMaps()
    {
        TestAssert.True(
            HotkeyVirtualKeyMapper.Map(HotkeyGesture.ParseInvariant("F9"))
                .SequenceEqual([0x78]),
            "F9 virtual-key mapping changed");
        TestAssert.True(
            HotkeyVirtualKeyMapper.Map(HotkeyGesture.ParseInvariant("Ctrl+i"))
                .SequenceEqual([0x11, 0x49]),
            "Ctrl+i virtual-key mapping changed");
    }

    private static void RuntimeTogglesCoarseAutomation()
    {
        var settings = FishingRuntimeSettings.CreateDefault(revision: 1);
        var reader = new FakeHotkeyStateReader();
        var automation = new FakeFishingAutomationRuntime();
        var runtime = new StartStopHotkeyRuntime(
            reader,
            () => settings,
            automation,
            () => false);

        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        reader.IsDownValue = true;
        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(1, automation.StartCount, "Held hotkey started automation more than once");

        reader.IsDownValue = false;
        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        reader.IsDownValue = true;
        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(1, automation.StopCount, "Second press did not stop automation exactly once");

        settings = settings with
        {
            Revision = 2,
            Hotkeys = settings.Hotkeys with { StartStop = "Ctrl+i" },
        };
        reader.IsDownValue = false;
        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(reader.LastGesture.HasValue,
            "Runtime did not read the newly persisted hotkey");
        var observedGesture = reader.LastGesture ??
            throw new InvalidOperationException("Runtime did not read the persisted hotkey");
        TestAssert.Equal("Ctrl+i", observedGesture.ToInvariantString(),
            "Runtime did not consume the newly persisted hotkey");
    }

    private static void RuntimeSuppressesFocusedWindow()
    {
        var focused = true;
        var reader = new FakeHotkeyStateReader { IsDownValue = true };
        var automation = new FakeFishingAutomationRuntime();
        var runtime = new StartStopHotkeyRuntime(
            reader,
            () => FishingRuntimeSettings.CreateDefault(revision: 1),
            automation,
            () => focused);

        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        focused = false;
        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(0, automation.StartCount,
            "Held key escaped after the product window lost focus");

        reader.IsDownValue = false;
        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        reader.IsDownValue = true;
        runtime.PollOnceAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(1, automation.StartCount,
            "Fresh press after focused-window suppression was lost");
    }

    private static void RuntimeStopBeforeStartIsTerminal()
    {
        var reader = new FakeHotkeyStateReader { IsDownValue = true };
        var runtime = new StartStopHotkeyRuntime(
            reader,
            () => FishingRuntimeSettings.CreateDefault(revision: 1),
            new FakeFishingAutomationRuntime(),
            () => false,
            TimeSpan.FromMilliseconds(10));

        runtime.StopAsync().GetAwaiter().GetResult();
        runtime.StartAsync().GetAwaiter().GetResult();
        Thread.Sleep(30);

        TestAssert.Equal(0, reader.ReadCount,
            "Terminal hotkey runtime restarted after Host shutdown");
    }

    private static StartStopHotkeySample Sample(
        bool isDown,
        bool canStartOrStop = true,
        bool captureActive = false,
        bool gestureValid = true,
        bool botStopping = false) =>
        new(canStartOrStop, captureActive, gestureValid, isDown, botStopping);

    private sealed class FakeHotkeyStateReader : IHotkeyStateReader
    {
        public bool IsDownValue { get; set; }

        public int ReadCount { get; private set; }

        public HotkeyGesture? LastGesture { get; private set; }

        public bool IsDown(HotkeyGesture gesture)
        {
            ReadCount++;
            LastGesture = gesture;
            return IsDownValue;
        }
    }

    private sealed class FakeFishingAutomationRuntime :
        IFishingAutomationRuntime,
        IFishingAutomationStateSource
    {
        public bool HasActiveEntitlement => true;

        public int StartCount { get; private set; }

        public int StopCount { get; private set; }

        public event Action<FishingSessionStateSnapshot>? SessionStateChanged;

        public Task<FishingSessionStateSnapshot> StartAsync(
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            StartCount++;
            var snapshot = Snapshot(running: true, revision: (ulong)(StartCount + StopCount));
            SessionStateChanged?.Invoke(snapshot);
            return Task.FromResult(snapshot);
        }

        public Task<FishingSessionStateSnapshot> StopAsync(
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            StopCount++;
            var snapshot = Snapshot(running: false, revision: (ulong)(StartCount + StopCount));
            SessionStateChanged?.Invoke(snapshot);
            return Task.FromResult(snapshot);
        }

        private static FishingSessionStateSnapshot Snapshot(bool running, ulong revision) => new(
            revision,
            running,
            stopping: false,
            detectedStage: running ? "fishing" : "idle",
            totals: new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
            tackleItems: []);
    }
}
