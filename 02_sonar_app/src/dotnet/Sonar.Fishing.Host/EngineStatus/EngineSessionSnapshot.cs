namespace Sonar.Fishing.Host.EngineStatus;

public sealed record EngineSessionSnapshot(
    bool Running,
    bool Stopping,
    string DetectedStage)
{
    public static EngineSessionSnapshot InertReady { get; } = new(
        Running: false,
        Stopping: false,
        DetectedStage: string.Empty);
}
