using Sonar.Fishing.Host.EngineIntegration.Supervision;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.EngineIntegration;

internal sealed class EngineFishingAutomationRuntime(
    EngineSessionSupervisor supervisor,
    Func<FishingRuntimeSettings> currentSettings)
    : IFishingAutomationRuntime,
      IFishingAutomationStateSource,
      IFishingSessionStatisticsRuntime
{
    private readonly EngineSessionSupervisor supervisor = supervisor ??
        throw new ArgumentNullException(nameof(supervisor));
    private readonly Func<FishingRuntimeSettings> currentSettings = currentSettings ??
        throw new ArgumentNullException(nameof(currentSettings));

    public event Action<FishingSessionStateSnapshot>? SessionStateChanged
    {
        add => supervisor.SessionStateChanged += value;
        remove => supervisor.SessionStateChanged -= value;
    }

    public bool HasActiveEntitlement => supervisor.HasActiveEntitlement;

    public Task<FishingSessionStateSnapshot> StartAsync(
        CancellationToken cancellationToken)
    {
        RequireActiveEntitlement();
        var settings = currentSettings();
        settings.Validate();
        return supervisor.StartFishingSessionAsync(
            settings,
            cancellationToken);
    }

    public Task<FishingSessionStateSnapshot> StopAsync(
        CancellationToken cancellationToken) =>
        supervisor.StopAutomationAsync(cancellationToken);

    public Task<FishingSessionStateSnapshot> ResetCurrentSessionAsync(
        CancellationToken cancellationToken) =>
        supervisor.ResetCurrentSessionStatisticsAsync(cancellationToken);

    private void RequireActiveEntitlement()
    {
        if (!HasActiveEntitlement)
        {
            throw new EngineCommandRejectedException(
                "start-fishing-session",
                "active_entitlement_required");
        }
    }
}
