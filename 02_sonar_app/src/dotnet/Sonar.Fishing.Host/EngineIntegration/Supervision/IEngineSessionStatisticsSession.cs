using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal interface IEngineSessionStatisticsSession
{
    EngineCommandDispatch<FishingSessionStateSnapshot> ResetCurrentSessionStatistics(
        CancellationToken cancellationToken);
}
