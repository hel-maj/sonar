namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal sealed record EngineRestartPolicy(
    int MaximumFailures,
    TimeSpan FailureWindow,
    TimeSpan HeartbeatInterval)
{
    internal static EngineRestartPolicy Default { get; } = new(
        MaximumFailures: 3,
        FailureWindow: TimeSpan.FromMinutes(1),
        HeartbeatInterval: TimeSpan.FromSeconds(2));

    internal void Validate()
    {
        if (MaximumFailures is < 1 or > 10)
        {
            throw new ArgumentOutOfRangeException(nameof(MaximumFailures));
        }
        if (FailureWindow <= TimeSpan.Zero || FailureWindow > TimeSpan.FromMinutes(10))
        {
            throw new ArgumentOutOfRangeException(nameof(FailureWindow));
        }
        if (HeartbeatInterval <= TimeSpan.Zero || HeartbeatInterval > TimeSpan.FromMinutes(1))
        {
            throw new ArgumentOutOfRangeException(nameof(HeartbeatInterval));
        }
    }
}
