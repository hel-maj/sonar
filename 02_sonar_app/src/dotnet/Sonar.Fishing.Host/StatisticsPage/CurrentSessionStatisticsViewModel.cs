using System.Collections.ObjectModel;
using System.Globalization;
using CommunityToolkit.Mvvm.ComponentModel;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Presentation;
using Sonar.Fishing.Host.ProductCatalog;

namespace Sonar.Fishing.Host.StatisticsPage;

public sealed class FishStatisticsRowViewModel : ObservableObject
{
    private readonly Func<string, double?, bool>? persistPrice;
    private string customPrice;

    internal FishStatisticsRowViewModel(
        string fishId,
        string name,
        string imageResourceUri,
        string caught,
        string kept,
        string basePrice,
        string customPrice,
        string income,
        Func<string, double?, bool>? persistPrice)
    {
        FishId = fishId;
        Name = name;
        ImageResourceUri = imageResourceUri;
        IconResourceKey = $"fish/{fishId}";
        Caught = caught;
        Kept = kept;
        BasePrice = basePrice;
        this.customPrice = customPrice;
        Income = income;
        this.persistPrice = persistPrice;
    }

    public string FishId { get; }

    public string Name { get; }

    public string ImageResourceUri { get; }

    public string IconResourceKey { get; }

    public string Caught { get; }

    public string Kept { get; }

    public string BasePrice { get; }

    public string CustomPrice
    {
        get => customPrice;
        set
        {
            var normalized = new string((value ?? string.Empty)
                .Where(char.IsAsciiDigit)
                .Take(12)
                .ToArray());
            double? parsed = normalized.Length == 0
                ? null
                : double.Parse(normalized, NumberStyles.None, CultureInfo.InvariantCulture);
            if (parsed is <= 0)
            {
                normalized = string.Empty;
                parsed = null;
            }
            if (normalized == customPrice || persistPrice is null)
            {
                return;
            }
            if (persistPrice(FishId, parsed))
            {
                SetProperty(ref customPrice, normalized);
            }
        }
    }

    public string Income { get; }

    public bool CanEditCustomPrice => persistPrice is not null;
}

public sealed record CatchSizeLegendItemViewModel(
    string Key,
    string Label,
    int Count,
    double Percent);

public sealed class CurrentSessionStatisticsViewModel
{
    private readonly ReadOnlyCollection<FishStatisticsRowViewModel> _fishRows;
    private readonly ReadOnlyCollection<CatchSizeLegendItemViewModel> _catchSizes;

    private CurrentSessionStatisticsViewModel(
        string duration,
        string caught,
        string kept,
        string keptWeight,
        string income,
        string incomePerHour,
        IEnumerable<FishStatisticsRowViewModel> fishRows,
        IEnumerable<CatchSizeLegendItemViewModel> catchSizes)
    {
        Duration = duration;
        Caught = caught;
        Kept = kept;
        KeptWeight = keptWeight;
        Income = income;
        IncomePerHour = incomePerHour;
        _fishRows = Array.AsReadOnly(fishRows.ToArray());
        _catchSizes = Array.AsReadOnly(catchSizes.ToArray());
    }

    public string Duration { get; }

    public string Caught { get; }

    public string Kept { get; }

    public string KeptWeight { get; }

    public string Income { get; }

    public string IncomePerHour { get; }

    public IReadOnlyList<FishStatisticsRowViewModel> FishRows => _fishRows;

    public IReadOnlyList<CatchSizeLegendItemViewModel> CatchSizes => _catchSizes;

    public bool HasCatches => _fishRows.Count > 0;

    public string EmptyCatchMessage => "Уловов пока нет";

    public static CurrentSessionStatisticsViewModel FromSnapshot(
        FishingSessionStateSnapshot snapshot,
        Func<string, double?, bool>? persistPrice = null)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        var totals = snapshot.Totals;
        var keptCount = Math.Max(0, totals.CaughtCount - totals.ReleasedCount);
        var keptKg = Math.Max(0d, totals.CaughtKg - totals.ReleasedKg);
        var incomePerHourMin = totals.DurationSeconds <= 0
            ? 0d
            : totals.EarnedMin / (totals.DurationSeconds / 3600d);
        var incomePerHourMax = totals.DurationSeconds <= 0
            ? 0d
            : totals.EarnedMax / (totals.DurationSeconds / 3600d);

        return new CurrentSessionStatisticsViewModel(
            FishingValueFormatter.Duration(totals.DurationSeconds),
            FishingValueFormatter.CatchSummary(totals.CaughtCount, totals.CaughtKg),
            FishingValueFormatter.CatchSummary(keptCount, keptKg),
            FishingValueFormatter.Weight(keptKg),
            FishingValueFormatter.MoneyRange(totals.EarnedMin, totals.EarnedMax),
            totals.DurationSeconds > 0
                ? FishingValueFormatter.MoneyRange(incomePerHourMin, incomePerHourMax)
                : "0 $",
            snapshot.FishRows.Select(row =>
            {
                var fish = FishingFishCatalog.All.FirstOrDefault(
                    candidate => candidate.Id == row.FishId);
                return new FishStatisticsRowViewModel(
                    row.FishId,
                    row.Name,
                    fish?.ImageResourceUri ?? string.Empty,
                    FishingValueFormatter.CatchSummary(row.CaughtCount, row.CaughtKg),
                    FishingValueFormatter.CatchSummary(row.KeptCount, row.KeptKg),
                    FishingValueFormatter.BasePrice(row.BasePrice),
                    FishingValueFormatter.OptionalPrice(row.CustomPrice),
                    FishingValueFormatter.MoneyRange(row.EarnedMin, row.EarnedMax),
                    persistPrice);
            }),
            snapshot.CatchSizes.Select(item => new CatchSizeLegendItemViewModel(
                item.Key,
                item.Label,
                item.Count,
                item.Percent)));
    }
}
