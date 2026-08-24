using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Ipc.Contracts.V1;

namespace Sonar.Fishing.Host.EngineIntegration.Notifications;

internal static class FishingEngineNotificationWireMapper
{
    internal static FishingEngineNotification Map(FishingNotificationEvent source)
    {
        ArgumentNullException.ThrowIfNull(source);
        return source.DetailCase switch
        {
            FishingNotificationEvent.DetailOneofCase.CatchObserved => MapCatch(
                source.CatchObserved),
            FishingNotificationEvent.DetailOneofCase.SessionStarted =>
                new FishingStartedEngineNotification(MapTotals(
                    source.SessionStarted.Totals)),
            FishingNotificationEvent.DetailOneofCase.SessionStopped =>
                new FishingStoppedEngineNotification(
                    MapTotals(source.SessionStopped.Totals),
                    source.SessionStopped.HasReason
                        ? NonEmpty(source.SessionStopped.Reason, "notification_stop_reason_invalid")
                        : null),
            FishingNotificationEvent.DetailOneofCase.MealRecovered =>
                MapMeal(source.MealRecovered),
            FishingNotificationEvent.DetailOneofCase.InventoryFull =>
                new InventoryFullEngineNotification(),
            FishingNotificationEvent.DetailOneofCase.PlayerStatus =>
                new PlayerStatusEngineNotification(MapPlayerStatus(source.PlayerStatus)),
            FishingNotificationEvent.DetailOneofCase.BaitTired =>
                new BaitTiredEngineNotification(),
            FishingNotificationEvent.DetailOneofCase.FocusLost =>
                new FocusLostEngineNotification(NonEmpty(
                    source.FocusLost.Reason,
                    "notification_focus_reason_invalid")),
            _ => throw new InvalidOperationException("fishing_notification_event_invalid"),
        };
    }

    private static FishingCatchEngineNotification MapCatch(CatchNotification source)
    {
        ArgumentNullException.ThrowIfNull(source);
        if (source.HasWeightKg &&
            (!double.IsFinite(source.WeightKg) || source.WeightKg < 0))
        {
            throw new InvalidOperationException("notification_catch_weight_invalid");
        }
        return new FishingCatchEngineNotification(
            NonEmpty(source.FishName, "notification_fish_name_invalid"),
            source.HasWeightKg ? source.WeightKg : null,
            source.HasQualityText
                ? NonEmpty(source.QualityText, "notification_quality_invalid")
                : null,
            source.HasXpCurrent ? source.XpCurrent : null,
            source.HasXpTotal ? source.XpTotal : null,
            source.Released,
            MapTotals(source.Totals));
    }

    private static MealRecoveredEngineNotification MapMeal(
        MealRecoveredNotification source)
    {
        ArgumentNullException.ThrowIfNull(source);
        if (source.AffectedCount == 0)
        {
            throw new InvalidOperationException("notification_meal_count_invalid");
        }
        return new MealRecoveredEngineNotification(
            checked((int)source.AffectedCount),
            source.PlayerStatus is null
                ? null
                : MapPlayerStatus(source.PlayerStatus));
    }

    private static FishingSessionTotalsSnapshot MapTotals(FishingSessionTotals? source)
    {
        if (source is null ||
            !double.IsFinite(source.DurationSeconds) || source.DurationSeconds < 0 ||
            !double.IsFinite(source.CaughtKg) || source.CaughtKg < 0 ||
            !double.IsFinite(source.ReleasedKg) || source.ReleasedKg < 0 ||
            !double.IsFinite(source.EarnedMin) || source.EarnedMin < 0 ||
            !double.IsFinite(source.EarnedMax) || source.EarnedMax < source.EarnedMin)
        {
            throw new InvalidOperationException("notification_totals_invalid");
        }
        return new FishingSessionTotalsSnapshot(
            source.DurationSeconds,
            checked((int)source.CaughtCount),
            source.CaughtKg,
            checked((int)source.ReleasedCount),
            source.ReleasedKg,
            source.EarnedMin,
            source.EarnedMax);
    }

    private static FishingPlayerStatusSnapshot MapPlayerStatus(
        PlayerStatusNotification source)
    {
        ArgumentNullException.ThrowIfNull(source);
        var result = new FishingPlayerStatusSnapshot(
            source.HasFood ? source.Food : null,
            source.HasWater ? source.Water : null,
            source.HasHealth ? source.Health : null,
            source.HasInventoryWeight ? source.InventoryWeight : null,
            source.HasInventoryWeightMax ? source.InventoryWeightMax : null,
            source.HasBackpackWeight ? source.BackpackWeight : null,
            source.HasBackpackWeightMax ? source.BackpackWeightMax : null);
        ValidatePercent(result.Food);
        ValidatePercent(result.Water);
        ValidatePercent(result.Health);
        ValidateWeight(result.InventoryWeight);
        ValidateWeight(result.InventoryWeightMax);
        ValidateWeight(result.BackpackWeight);
        ValidateWeight(result.BackpackWeightMax);
        ValidateWeightPair(result.InventoryWeight, result.InventoryWeightMax);
        ValidateWeightPair(result.BackpackWeight, result.BackpackWeightMax);
        return result;
    }

    private static void ValidatePercent(int? value)
    {
        if (value is < 0 or > 100)
        {
            throw new InvalidOperationException("notification_player_status_invalid");
        }
    }

    private static void ValidateWeight(double? value)
    {
        if (value is { } present && (!double.IsFinite(present) || present < 0))
        {
            throw new InvalidOperationException("notification_player_status_invalid");
        }
    }

    private static void ValidateWeightPair(double? current, double? maximum)
    {
        if (current is { } present && maximum is { } limit && present > limit)
        {
            throw new InvalidOperationException("notification_player_status_invalid");
        }
    }

    private static string NonEmpty(string value, string reason) =>
        string.IsNullOrWhiteSpace(value)
            ? throw new InvalidOperationException(reason)
            : value.Trim();
}
