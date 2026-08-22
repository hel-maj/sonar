using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal sealed record EngineSupervisorSnapshot(
    ulong Generation,
    int ProcessId,
    bool IsContained,
    uint NegotiatedProtocolMinor,
    TimeSpan BootstrapDuration,
    int RestartCount,
    int FailuresInWindow,
    FishingSessionStateSnapshot SessionState);
