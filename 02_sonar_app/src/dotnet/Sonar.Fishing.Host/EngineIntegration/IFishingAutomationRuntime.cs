using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineIntegration;

internal interface IFishingAutomationRuntime
{
    bool HasActiveEntitlement { get; }

    Task<FishingSessionStateSnapshot> StartAsync(
        CancellationToken cancellationToken);

    Task<FishingSessionStateSnapshot> StopAsync(
        CancellationToken cancellationToken);
}

internal interface IFishingAutomationStateSource
{
    event Action<FishingSessionStateSnapshot>? SessionStateChanged;
}
