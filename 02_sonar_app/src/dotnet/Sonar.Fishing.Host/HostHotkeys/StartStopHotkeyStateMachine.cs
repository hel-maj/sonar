namespace Sonar.Fishing.Host.HostHotkeys;

internal enum StartStopHotkeyOutcome
{
    None,
    ToggleRequested,
    StoppingNoticeRequested,
}

internal readonly record struct StartStopHotkeySample(
    bool CanStartOrStop,
    bool CaptureActive,
    bool GestureValid,
    bool IsDown,
    bool BotStopping);

internal sealed class StartStopHotkeyStateMachine
{
    private bool wasDown;
    private bool suppressedUntilRelease;

    internal bool IsSuppressedUntilRelease => suppressedUntilRelease;

    internal void SuppressUntilRelease()
    {
        suppressedUntilRelease = true;
        wasDown = false;
    }

    internal StartStopHotkeyOutcome Poll(StartStopHotkeySample sample)
    {
        if (sample.CaptureActive)
        {
            SuppressUntilRelease();
            return StartStopHotkeyOutcome.None;
        }
        if (!sample.CanStartOrStop || !sample.GestureValid)
        {
            wasDown = false;
            return StartStopHotkeyOutcome.None;
        }
        if (suppressedUntilRelease)
        {
            if (!sample.IsDown)
            {
                suppressedUntilRelease = false;
            }
            wasDown = sample.IsDown;
            return StartStopHotkeyOutcome.None;
        }

        var risingEdge = sample.IsDown && !wasDown;
        wasDown = sample.IsDown;
        if (!risingEdge)
        {
            return StartStopHotkeyOutcome.None;
        }
        return sample.BotStopping
            ? StartStopHotkeyOutcome.StoppingNoticeRequested
            : StartStopHotkeyOutcome.ToggleRequested;
    }
}
