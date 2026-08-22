using Sonar.Fishing.Host.EngineIntegration.CatchDisposition;
using Sonar.Fishing.Host.EngineIntegration.CatchQuality;
using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineIntegration;

public sealed record OfflineEngineDiagnosticReceipt(
    OfflineCatchQualityDiagnostic CatchQuality,
    OfflineCatchDispositionDiagnostic CatchDisposition,
    FishingSessionStateSnapshot SessionState,
    int VerifiedEngineProcessId,
    bool ProcessContainmentVerified,
    uint NegotiatedProtocolMinor,
    bool SideEffectsEnabled,
    ulong AcceptedSettingsRevision,
    ulong AcknowledgedHeartbeatId,
    string ProductionAuthority,
    OfflineEnginePerformanceSnapshot Performance);

public sealed record OfflineEnginePerformanceSnapshot(
    TimeSpan BootstrapDuration,
    TimeSpan IpcScenarioDuration,
    TimeSpan TotalDuration,
    TimeSpan EngineProcessorTime,
    long EnginePeakWorkingSetBytes,
    int MeasuredIpcOperations);
