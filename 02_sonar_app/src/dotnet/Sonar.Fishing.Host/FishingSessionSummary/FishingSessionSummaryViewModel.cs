using System.Collections.ObjectModel;
using System.Globalization;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Presentation;

namespace Sonar.Fishing.Host.FishingSessionSummary;

public sealed record TackleItemViewModel(
    string Name,
    string CountText,
    string AccessibleName);

public sealed class FishingSessionSummaryViewModel
{
    private readonly ReadOnlyCollection<TackleItemViewModel> _tackleItems;

    private FishingSessionSummaryViewModel(
        string duration,
        string caught,
        string released,
        string income,
        IEnumerable<TackleItemViewModel> tackleItems)
    {
        Duration = duration;
        Caught = caught;
        Released = released;
        Income = income;
        _tackleItems = Array.AsReadOnly(tackleItems.ToArray());
    }

    public string Duration { get; }

    public string Caught { get; }

    public string Released { get; }

    public string Income { get; }

    public IReadOnlyList<TackleItemViewModel> TackleItems => _tackleItems;

    public bool HasTackleItems => _tackleItems.Count > 0;

    public string EmptyTackleMessage => "Снаряжение появится после начала рыбалки";

    public static FishingSessionSummaryViewModel FromSnapshot(FishingSessionSummarySnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);

        var tackleItems = snapshot.TackleItems.Select(item => new TackleItemViewModel(
            Name: item.Name,
            CountText: $"{item.Count.ToString(CultureInfo.InvariantCulture)}шт.",
            AccessibleName: $"{item.Name}: {item.Count.ToString(CultureInfo.InvariantCulture)} шт."));

        return new FishingSessionSummaryViewModel(
            duration: FishingValueFormatter.Duration(snapshot.DurationSeconds),
            caught: snapshot.CaughtCount.ToString(CultureInfo.InvariantCulture),
            released: snapshot.ReleasedCount.ToString(CultureInfo.InvariantCulture),
            income: FishingValueFormatter.MoneyRange(snapshot.EarnedMin, snapshot.EarnedMax),
            tackleItems: tackleItems);
    }

    public static FishingSessionSummaryViewModel FromSessionState(
        FishingSessionStateSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        return FromSnapshot(new FishingSessionSummarySnapshot(
            snapshot.Totals.DurationSeconds,
            snapshot.Totals.CaughtCount,
            snapshot.Totals.ReleasedCount,
            snapshot.Totals.EarnedMin,
            snapshot.Totals.EarnedMax,
            snapshot.TackleItems.Select(item => new TackleItemSnapshot(
                item.Name,
                item.Count))));
    }

}
