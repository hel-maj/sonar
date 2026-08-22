using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineIntegration;

internal static class FishingSessionWireMapper
{
    internal static FishingSessionStateSnapshot Map(
        Sonar.Fishing.Ipc.Contracts.V1.FishingSessionSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        if (snapshot.Revision == 0 || snapshot.Totals is null)
        {
            throw new InvalidOperationException("fishing_session_snapshot_invalid");
        }
        return new FishingSessionStateSnapshot(
            snapshot.Revision,
            snapshot.Running,
            snapshot.Stopping,
            snapshot.DetectedStage,
            new FishingSessionTotalsSnapshot(
                snapshot.Totals.DurationSeconds,
                checked((int)snapshot.Totals.CaughtCount),
                snapshot.Totals.CaughtKg,
                checked((int)snapshot.Totals.ReleasedCount),
                snapshot.Totals.ReleasedKg,
                snapshot.Totals.EarnedMin,
                snapshot.Totals.EarnedMax),
            snapshot.TackleItems.Select(item => new FishingTackleItemSnapshot(
                item.Key,
                item.Name,
                checked((int)item.Count))),
            snapshot.AcceptedSettingsRevision,
            snapshot.FishRows.Select(item => new FishingSessionFishRowSnapshot(
                item.FishId,
                item.Name,
                checked((int)item.CaughtCount),
                item.CaughtKg,
                checked((int)item.ReleasedCount),
                item.ReleasedKg,
                checked((int)item.KeptCount),
                item.KeptKg,
                item.BasePrice is null
                    ? null
                    : new FishingPriceSnapshot(
                        item.BasePrice.PerItemMin,
                        item.BasePrice.PerItemMax,
                        item.BasePrice.Per1000Min,
                        item.BasePrice.Per1000Max),
                item.HasCustomPrice ? item.CustomPrice : null,
                item.EarnedMin,
                item.EarnedMax)),
            snapshot.CatchSizes.Select(item => new FishingCatchSizeSnapshot(
                item.Key,
                item.Label,
                checked((int)item.Count),
                item.Percent)));
    }
}
