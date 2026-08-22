using Sonar.Fishing.Host.HostHotkeys;
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

    private static StartStopHotkeySample Sample(
        bool isDown,
        bool canStartOrStop = true,
        bool captureActive = false,
        bool gestureValid = true,
        bool botStopping = false) =>
        new(canStartOrStop, captureActive, gestureValid, isDown, botStopping);
}
