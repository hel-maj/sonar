using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal interface IEngineAutomationSession
{
    Task<FishingSessionStateSnapshot> StartFishingSessionAsync(
        FishingRuntimeSettings settings,
        CancellationToken cancellationToken);

    Task<FishingSessionStateSnapshot> StopAutomationAsync(
        CancellationToken cancellationToken);
}
