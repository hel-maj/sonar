using System.Collections.ObjectModel;

namespace Sonar.Fishing.Host.FishingSessionState;

public sealed record FishingSessionTotalsSnapshot(
    double DurationSeconds,
    int CaughtCount,
    double CaughtKg,
    int ReleasedCount,
    double ReleasedKg,
    double EarnedMin,
    double EarnedMax);

public sealed record FishingTackleItemSnapshot(
    string Key,
    string Name,
    int Count);

public sealed record FishingPriceSnapshot(
    double PerItemMin,
    double PerItemMax,
    double PerThousandMin,
    double PerThousandMax);

public sealed record FishingSessionFishRowSnapshot(
    string FishId,
    string Name,
    int CaughtCount,
    double CaughtKg,
    int ReleasedCount,
    double ReleasedKg,
    int KeptCount,
    double KeptKg,
    FishingPriceSnapshot? BasePrice,
    double? CustomPrice,
    double EarnedMin,
    double EarnedMax);

public sealed record FishingCatchSizeSnapshot(
    string Key,
    string Label,
    int Count,
    double Percent);

public sealed class FishingSessionStateSnapshot
{
    private readonly ReadOnlyCollection<FishingTackleItemSnapshot> _tackleItems;
    private readonly ReadOnlyCollection<FishingSessionFishRowSnapshot> _fishRows;
    private readonly ReadOnlyCollection<FishingCatchSizeSnapshot> _catchSizes;

    public static FishingSessionStateSnapshot Empty { get; } = new(
        revision: 0,
        running: false,
        stopping: false,
        detectedStage: string.Empty,
        totals: new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
        tackleItems: []);

    public FishingSessionStateSnapshot(
        ulong revision,
        bool running,
        bool stopping,
        string detectedStage,
        FishingSessionTotalsSnapshot totals,
        IEnumerable<FishingTackleItemSnapshot> tackleItems,
        ulong acceptedSettingsRevision = 0,
        IEnumerable<FishingSessionFishRowSnapshot>? fishRows = null,
        IEnumerable<FishingCatchSizeSnapshot>? catchSizes = null)
    {
        ArgumentNullException.ThrowIfNull(detectedStage);
        ArgumentNullException.ThrowIfNull(totals);
        ArgumentNullException.ThrowIfNull(tackleItems);
        ValidateTotals(totals);
        var frozenFishRows = (fishRows ?? []).ToArray();
        var frozenCatchSizes = (catchSizes ?? []).ToArray();
        foreach (var row in frozenFishRows)
        {
            ValidateFishRow(row);
        }
        foreach (var catchSize in frozenCatchSizes)
        {
            ValidateCatchSize(catchSize);
        }

        Revision = revision;
        Running = running;
        Stopping = stopping;
        DetectedStage = detectedStage;
        Totals = totals;
        AcceptedSettingsRevision = acceptedSettingsRevision;
        _tackleItems = Array.AsReadOnly(tackleItems.ToArray());
        _fishRows = Array.AsReadOnly(frozenFishRows);
        _catchSizes = Array.AsReadOnly(frozenCatchSizes);
    }

    public ulong Revision { get; }

    public bool Running { get; }

    public bool Stopping { get; }

    public string DetectedStage { get; }

    public FishingSessionTotalsSnapshot Totals { get; }

    public ulong AcceptedSettingsRevision { get; }

    public IReadOnlyList<FishingTackleItemSnapshot> TackleItems => _tackleItems;

    public IReadOnlyList<FishingSessionFishRowSnapshot> FishRows => _fishRows;

    public IReadOnlyList<FishingCatchSizeSnapshot> CatchSizes => _catchSizes;

    private static void ValidateTotals(FishingSessionTotalsSnapshot totals)
    {
        if (!double.IsFinite(totals.DurationSeconds) || totals.DurationSeconds < 0 ||
            !double.IsFinite(totals.CaughtKg) || totals.CaughtKg < 0 ||
            !double.IsFinite(totals.ReleasedKg) || totals.ReleasedKg < 0 ||
            !double.IsFinite(totals.EarnedMin) || totals.EarnedMin < 0 ||
            !double.IsFinite(totals.EarnedMax) || totals.EarnedMax < 0 ||
            totals.CaughtCount < 0 || totals.ReleasedCount < 0 ||
            totals.ReleasedCount > totals.CaughtCount ||
            totals.ReleasedKg > totals.CaughtKg + 1e-9 ||
            totals.EarnedMin > totals.EarnedMax + 1e-9)
        {
            throw new ArgumentOutOfRangeException(nameof(totals));
        }
    }

    private static void ValidateFishRow(FishingSessionFishRowSnapshot row)
    {
        ArgumentNullException.ThrowIfNull(row);
        if (string.IsNullOrWhiteSpace(row.FishId) ||
            string.IsNullOrWhiteSpace(row.Name) ||
            row.CaughtCount < 0 || row.ReleasedCount < 0 || row.KeptCount < 0 ||
            row.ReleasedCount > row.CaughtCount ||
            row.KeptCount != row.CaughtCount - row.ReleasedCount ||
            !IsNonNegativeFinite(row.CaughtKg) ||
            !IsNonNegativeFinite(row.ReleasedKg) ||
            !IsNonNegativeFinite(row.KeptKg) ||
            row.ReleasedKg > row.CaughtKg + 1e-9 ||
            Math.Abs(row.KeptKg - (row.CaughtKg - row.ReleasedKg)) > 1e-9 ||
            !IsNonNegativeFinite(row.EarnedMin) ||
            !IsNonNegativeFinite(row.EarnedMax) ||
            row.EarnedMin > row.EarnedMax + 1e-9 ||
            row.CustomPrice is { } customPrice &&
                (!IsNonNegativeFinite(customPrice) || customPrice == 0))
        {
            throw new ArgumentException("session_fish_row_invalid", nameof(row));
        }
        if (row.BasePrice is { } price &&
            (!IsNonNegativeFinite(price.PerItemMin) ||
             !IsNonNegativeFinite(price.PerItemMax) ||
             !IsNonNegativeFinite(price.PerThousandMin) ||
             !IsNonNegativeFinite(price.PerThousandMax) ||
             price.PerItemMin > price.PerItemMax + 1e-9 ||
             price.PerThousandMin > price.PerThousandMax + 1e-9))
        {
            throw new ArgumentException("session_fish_price_invalid", nameof(row));
        }
    }

    private static void ValidateCatchSize(FishingCatchSizeSnapshot catchSize)
    {
        ArgumentNullException.ThrowIfNull(catchSize);
        if (string.IsNullOrWhiteSpace(catchSize.Key) ||
            string.IsNullOrWhiteSpace(catchSize.Label) ||
            catchSize.Count < 0 ||
            !double.IsFinite(catchSize.Percent) ||
            catchSize.Percent is < 0 or > 100)
        {
            throw new ArgumentException("session_catch_size_invalid", nameof(catchSize));
        }
    }

    private static bool IsNonNegativeFinite(double value) =>
        double.IsFinite(value) && value >= 0;
}
