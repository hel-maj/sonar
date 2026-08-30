using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineIntegration;

internal interface IFishingSessionStatisticsRuntime
{
    Task<FishingSessionStateSnapshot> ResetCurrentSessionAsync(
        CancellationToken cancellationToken);
}
