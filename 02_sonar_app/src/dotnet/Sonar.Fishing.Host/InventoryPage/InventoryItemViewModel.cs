using CommunityToolkit.Mvvm.ComponentModel;
using System.Globalization;
using System.Windows.Media;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.InventoryPage;

public sealed class InventoryItemViewModel : ObservableObject
{
    private ImageSource? iconSource;
    private ImageSlotState iconState;

    private InventoryItemViewModel(InventoryItemState source)
    {
        RuntimeId = source.RuntimeId;
        CatalogItemId = source.CatalogItemId;
        Name = source.Name;
        Category = source.Category;
        Column = source.Column;
        Row = source.Row;
        ColumnSpan = source.ColumnSpan;
        RowSpan = source.RowSpan;
        Count = source.Count;
        MaximumCount = source.MaximumCount;
        UnitWeight = source.UnitWeight;
        TotalWeight = source.TotalWeight;
        ConditionPercent = source.ConditionPercent;
        FreshnessPercent = source.FreshnessPercent;
        ConditionKind = source.ConditionKind;
        Durability = source.Durability;
        Description = source.Description;
        ImageReference = source.ImageReference;
        DetailLines = source.DetailLines;
        iconState = ImageSlotState.Empty;
    }

    public string RuntimeId { get; }

    public ulong CatalogItemId { get; }

    public string Name { get; }

    public string Category { get; }

    public uint Column { get; }

    public uint Row { get; }

    public uint ColumnSpan { get; }

    public uint RowSpan { get; }

    public uint Count { get; }

    public uint? MaximumCount { get; }

    public double? UnitWeight { get; }

    public double? TotalWeight { get; }

    public double? ConditionPercent { get; }

    public double? FreshnessPercent { get; }

    public InventoryConditionKind ConditionKind { get; }

    public string Durability { get; }

    public string Description { get; }

    public string ImageReference { get; }

    public IReadOnlyList<string> DetailLines { get; }

    public ImageSource? IconSource
    {
        get => iconSource;
        private set => SetProperty(ref iconSource, value);
    }

    public ImageSlotState IconState
    {
        get => iconState;
        private set => SetProperty(ref iconState, value);
    }

    public string CatalogText => CatalogItemId == 0 ? "-" : $"#{CatalogItemId}";

    public string CellText => $"{Column + 1} x {Row + 1}";

    public string FootprintText => $"{ColumnSpan} x {RowSpan}";

    public string CountText => MaximumCount.HasValue
        ? $"{Count} / {MaximumCount.Value}"
        : Count.ToString(CultureInfo.CurrentCulture);

    public string CountOverlayText => CountText;

    public string WeightText => TotalWeight.HasValue
        ? $"{FormatNumber(TotalWeight.Value)} кг"
        : "-";

    public string UnitWeightText => UnitWeight.HasValue
        ? $"{FormatNumber(UnitWeight.Value)} кг"
        : "-";

    public string ConditionText => ConditionPercent.HasValue
        ? $"{FormatNumber(ConditionPercent.Value)}%"
        : "-";

    public string FreshnessText => FreshnessPercent.HasValue
        ? $"{FormatNumber(FreshnessPercent.Value)}%"
        : "-";

    public string DescriptionText => string.IsNullOrWhiteSpace(Description)
        ? "Описание отсутствует."
        : Description;

    public static InventoryItemViewModel Map(InventoryItemState source)
    {
        ArgumentNullException.ThrowIfNull(source);
        return new InventoryItemViewModel(source);
    }

    internal async Task LoadImageAsync(
        IInventoryImageProvider provider,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(provider);
        if (string.IsNullOrWhiteSpace(ImageReference))
        {
            IconSource = null;
            IconState = ImageSlotState.Empty;
            return;
        }

        IconSource = null;
        IconState = ImageSlotState.Loading;
        try
        {
            var source = await provider.LoadAsync(ImageReference, cancellationToken);
            if (cancellationToken.IsCancellationRequested)
            {
                IconSource = null;
                IconState = ImageSlotState.Empty;
                return;
            }
            IconSource = source;
            IconState = source is null ? ImageSlotState.Error : ImageSlotState.Ready;
        }
        catch (OperationCanceledException)
        {
            IconSource = null;
            IconState = ImageSlotState.Empty;
        }
    }

    private static string FormatNumber(double value) =>
        value.ToString("0.##", CultureInfo.CurrentCulture);
}
