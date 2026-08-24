using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineIntegration.Notifications;

internal abstract record FishingEngineNotification;

internal sealed record FishingCatchEngineNotification(
    string FishName,
    double? WeightKg,
    string? QualityText,
    ulong? XpCurrent,
    ulong? XpTotal,
    bool Released,
    FishingSessionTotalsSnapshot Totals) : FishingEngineNotification;

internal sealed record FishingStartedEngineNotification(
    FishingSessionTotalsSnapshot Totals) : FishingEngineNotification;

internal sealed record FishingStoppedEngineNotification(
    FishingSessionTotalsSnapshot Totals,
    string? Reason) : FishingEngineNotification;

internal sealed record FishingPlayerStatusSnapshot(
    int? Food,
    int? Water,
    int? Health,
    double? InventoryWeight,
    double? InventoryWeightMax,
    double? BackpackWeight,
    double? BackpackWeightMax);

internal sealed record MealRecoveredEngineNotification(
    int AffectedCount,
    FishingPlayerStatusSnapshot? PlayerStatus) : FishingEngineNotification;

internal sealed record InventoryFullEngineNotification : FishingEngineNotification;

internal sealed record PlayerStatusEngineNotification(
    FishingPlayerStatusSnapshot Status) : FishingEngineNotification;

internal sealed record BaitTiredEngineNotification : FishingEngineNotification;

internal sealed record FocusLostEngineNotification(
    string Reason) : FishingEngineNotification;

internal sealed record FishingEngineNotificationFrame(
    string SessionId,
    ulong Sequence,
    long CapturedAtUnixMs,
    FishingEngineNotification Notification);

internal sealed record FishingEngineNotificationReceipt(
    ulong Generation,
    ulong Sequence,
    long CapturedAtUnixMs,
    FishingEngineNotification Notification);

internal interface IFishingEngineNotificationSource
{
    event Action<FishingEngineNotificationReceipt>? NotificationReceived;
}
