using System.Collections.ObjectModel;

namespace Sonar.Fishing.Host.FishingSessionSummary;

public sealed record TackleItemSnapshot(string Name, int Count);

public sealed class FishingSessionSummarySnapshot
{
    private readonly ReadOnlyCollection<TackleItemSnapshot> _tackleItems;

    public FishingSessionSummarySnapshot(
        double durationSeconds,
        int caughtCount,
        int releasedCount,
        double earnedMin,
        double earnedMax,
        IEnumerable<TackleItemSnapshot> tackleItems)
    {
        ArgumentNullException.ThrowIfNull(tackleItems);
        if (!double.IsFinite(durationSeconds))
        {
            throw new ArgumentOutOfRangeException(nameof(durationSeconds));
        }
        if (!double.IsFinite(earnedMin))
        {
            throw new ArgumentOutOfRangeException(nameof(earnedMin));
        }
        if (!double.IsFinite(earnedMax))
        {
            throw new ArgumentOutOfRangeException(nameof(earnedMax));
        }

        DurationSeconds = durationSeconds;
        CaughtCount = caughtCount;
        ReleasedCount = releasedCount;
        EarnedMin = earnedMin;
        EarnedMax = earnedMax;
        _tackleItems = Array.AsReadOnly(tackleItems.ToArray());
    }

    public static FishingSessionSummarySnapshot Empty { get; } = new(
        durationSeconds: 0,
        caughtCount: 0,
        releasedCount: 0,
        earnedMin: 0,
        earnedMax: 0,
        tackleItems: Array.Empty<TackleItemSnapshot>());

    public double DurationSeconds { get; }

    public int CaughtCount { get; }

    public int ReleasedCount { get; }

    public double EarnedMin { get; }

    public double EarnedMax { get; }

    public IReadOnlyList<TackleItemSnapshot> TackleItems => _tackleItems;
}
