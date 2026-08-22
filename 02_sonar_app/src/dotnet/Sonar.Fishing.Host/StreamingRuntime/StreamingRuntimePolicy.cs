namespace Sonar.Fishing.Host.StreamingRuntime;

internal sealed record StreamingRuntimePolicy(
    TimeSpan StartupTimeout,
    TimeSpan CleanupTimeout,
    TimeSpan MonitorInterval,
    TimeSpan RestartDelay,
    int MaximumRestartAttempts,
    TimeSpan NoViewerAutoStop,
    TimeSpan ChatCommandTimeout,
    int MaximumTunnelDiagnosticLines)
{
    internal static StreamingRuntimePolicy Default { get; } = new(
        StartupTimeout: TimeSpan.FromSeconds(20),
        CleanupTimeout: TimeSpan.FromSeconds(5),
        MonitorInterval: TimeSpan.FromSeconds(1),
        RestartDelay: TimeSpan.FromMilliseconds(500),
        MaximumRestartAttempts: 2,
        NoViewerAutoStop: TimeSpan.FromMinutes(5),
        ChatCommandTimeout: TimeSpan.FromSeconds(2),
        MaximumTunnelDiagnosticLines: 128);

    internal void Validate()
    {
        RequirePositive(StartupTimeout, nameof(StartupTimeout));
        RequirePositive(CleanupTimeout, nameof(CleanupTimeout));
        RequirePositive(MonitorInterval, nameof(MonitorInterval));
        if (RestartDelay < TimeSpan.Zero)
        {
            throw new ArgumentOutOfRangeException(nameof(RestartDelay));
        }
        if (MaximumRestartAttempts is < 0 or > 5)
        {
            throw new ArgumentOutOfRangeException(nameof(MaximumRestartAttempts));
        }
        RequirePositive(NoViewerAutoStop, nameof(NoViewerAutoStop));
        if (NoViewerAutoStop > TimeSpan.FromHours(24))
        {
            throw new ArgumentOutOfRangeException(nameof(NoViewerAutoStop));
        }
        RequirePositive(ChatCommandTimeout, nameof(ChatCommandTimeout));
        if (MaximumTunnelDiagnosticLines is < 1 or > 1024)
        {
            throw new ArgumentOutOfRangeException(nameof(MaximumTunnelDiagnosticLines));
        }
    }

    private static void RequirePositive(TimeSpan value, string parameterName)
    {
        if (value <= TimeSpan.Zero)
        {
            throw new ArgumentOutOfRangeException(parameterName);
        }
    }
}
