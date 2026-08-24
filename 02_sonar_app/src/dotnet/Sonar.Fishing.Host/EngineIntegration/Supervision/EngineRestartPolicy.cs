namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal sealed record EngineRestartPolicy(
    TimeSpan FailureWindow,
    TimeSpan HeartbeatInterval,
    TimeSpan InitialRestartDelay,
    TimeSpan MaximumRestartDelay,
    TimeSpan AutomationCommandTimeout)
{
    internal static EngineRestartPolicy Default { get; } = new(
        FailureWindow: TimeSpan.FromMinutes(1),
        HeartbeatInterval: TimeSpan.FromSeconds(2),
        InitialRestartDelay: TimeSpan.FromMilliseconds(250),
        MaximumRestartDelay: TimeSpan.FromSeconds(2),
        AutomationCommandTimeout: TimeSpan.FromSeconds(10));

    internal void Validate()
    {
        if (FailureWindow <= TimeSpan.Zero || FailureWindow > TimeSpan.FromMinutes(10))
        {
            throw new ArgumentOutOfRangeException(nameof(FailureWindow));
        }
        if (HeartbeatInterval <= TimeSpan.Zero || HeartbeatInterval > TimeSpan.FromMinutes(1))
        {
            throw new ArgumentOutOfRangeException(nameof(HeartbeatInterval));
        }
        if (InitialRestartDelay <= TimeSpan.Zero ||
            InitialRestartDelay > TimeSpan.FromSeconds(10))
        {
            throw new ArgumentOutOfRangeException(nameof(InitialRestartDelay));
        }
        if (MaximumRestartDelay < InitialRestartDelay ||
            MaximumRestartDelay > TimeSpan.FromSeconds(30))
        {
            throw new ArgumentOutOfRangeException(nameof(MaximumRestartDelay));
        }
        if (AutomationCommandTimeout <= TimeSpan.Zero ||
            AutomationCommandTimeout > TimeSpan.FromMinutes(1))
        {
            throw new ArgumentOutOfRangeException(nameof(AutomationCommandTimeout));
        }
    }

    internal TimeSpan DelayForFailureCount(int failureCount)
    {
        if (failureCount <= 0)
        {
            return TimeSpan.Zero;
        }
        var ticks = InitialRestartDelay.Ticks;
        for (var index = 1; index < failureCount && ticks < MaximumRestartDelay.Ticks; index++)
        {
            ticks = ticks > MaximumRestartDelay.Ticks / 2
                ? MaximumRestartDelay.Ticks
                : Math.Min(ticks * 2, MaximumRestartDelay.Ticks);
        }
        return TimeSpan.FromTicks(ticks);
    }
}
