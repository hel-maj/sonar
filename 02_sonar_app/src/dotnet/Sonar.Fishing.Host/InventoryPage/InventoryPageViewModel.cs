using CommunityToolkit.Mvvm.ComponentModel;
using Sonar.UI.Wpf.Controls;
using System.Globalization;

namespace Sonar.Fishing.Host.InventoryPage;

public sealed record InventoryCategoryOption(string Value, string Label);

public sealed class InventoryPageViewModel : ObservableObject, IDisposable
{
    private readonly IInventoryImageProvider? imageProvider;
    private readonly IDisposable? ownedImageProvider;
    private InventoryProductState snapshot;
    private CancellationTokenSource? imageCancellation;
    private IReadOnlyList<InventoryItemViewModel> allItems =
        Array.Empty<InventoryItemViewModel>();
    private IReadOnlyList<InventoryItemViewModel> visibleItems =
        Array.Empty<InventoryItemViewModel>();
    private IReadOnlyList<InventoryCategoryOption> categoryOptions =
        Array.Empty<InventoryCategoryOption>();
    private string search = string.Empty;
    private string selectedCategory = string.Empty;
    private int viewModeIndex;
    private ulong engineGeneration;

    public InventoryPageViewModel(InventoryProductState snapshot)
        : this(snapshot, imageProvider: null)
    {
    }

    internal InventoryPageViewModel(
        InventoryProductState snapshot,
        IInventoryImageProvider? imageProvider,
        IDisposable? ownedImageProvider = null)
    {
        this.snapshot = snapshot ?? throw new ArgumentNullException(nameof(snapshot));
        this.imageProvider = imageProvider;
        this.ownedImageProvider = ownedImageProvider;
        Rebuild();
    }

    internal static InventoryPageViewModel CreateProduction()
    {
        var provider = new CommonInventoryImageProvider();
        return new InventoryPageViewModel(
            InventoryProductState.Unknown,
            provider,
            provider);
    }

    public string StatusText => !snapshot.OpenKnown
        ? "Недоступно"
        : snapshot.Open ? "Открыт" : "Закрыт";

    public SemanticTone StatusTone => !snapshot.OpenKnown
        ? SemanticTone.Neutral
        : snapshot.Open ? SemanticTone.Success : SemanticTone.Info;

    public string WeightText => snapshot.Ready &&
        snapshot.CurrentWeight.HasValue && snapshot.MaximumWeight.HasValue
            ? $"{FormatNumber(snapshot.CurrentWeight.Value)} / " +
              $"{FormatNumber(snapshot.MaximumWeight.Value)} кг"
            : "-";

    public string ItemCountText => FormatPositionCount(snapshot.Items.Count);

    public int GridRows => checked((int)snapshot.GridRows);

    public int GridColumns => checked((int)snapshot.GridColumns);

    public PageState ContentState => !snapshot.Ready
        ? PageState.Unavailable
        : visibleItems.Count == 0 ? PageState.Empty : PageState.Ready;

    public string StateTitle => !snapshot.Ready
        ? "Инвентарь недоступен"
        : snapshot.Items.Count == 0 ? "Инвентарь пуст" : "Ничего не найдено";

    public string StateMessage => !snapshot.Ready
        ? "Данные появятся после подключения к игре."
        : snapshot.Items.Count == 0
            ? "В инвентаре нет предметов."
            : "Измените поиск или фильтр.";

    public string Search
    {
        get => search;
        set
        {
            value ??= string.Empty;
            if (SetProperty(ref search, value))
            {
                RebuildVisibleItems();
            }
        }
    }

    public InventoryCategoryOption? SelectedCategoryOption
    {
        get => categoryOptions.FirstOrDefault(option => string.Equals(
            option.Value,
            selectedCategory,
            StringComparison.OrdinalIgnoreCase));
        set
        {
            var next = value?.Value ?? string.Empty;
            if (SetProperty(ref selectedCategory, next))
            {
                RebuildVisibleItems();
            }
        }
    }

    public int ViewModeIndex
    {
        get => viewModeIndex;
        set
        {
            if (value is not (0 or 1))
            {
                throw new ArgumentOutOfRangeException(nameof(value));
            }
            SetProperty(ref viewModeIndex, value);
        }
    }

    public IReadOnlyList<InventoryCategoryOption> CategoryOptions => categoryOptions;

    public IReadOnlyList<InventoryItemViewModel> VisibleItems => visibleItems;

    public void ApplySnapshot(InventoryProductState next)
    {
        ArgumentNullException.ThrowIfNull(next);
        if (next.Revision != 0 && snapshot.Revision != 0 &&
            next.Revision < snapshot.Revision)
        {
            return;
        }

        snapshot = next;
        Rebuild();
        OnPropertyChanged(nameof(StatusText));
        OnPropertyChanged(nameof(StatusTone));
        OnPropertyChanged(nameof(WeightText));
        OnPropertyChanged(nameof(ItemCountText));
        OnPropertyChanged(nameof(GridRows));
        OnPropertyChanged(nameof(GridColumns));
    }

    internal void ApplyEngineSnapshot(
        ulong generation,
        InventoryProductState next)
    {
        ArgumentNullException.ThrowIfNull(next);
        if (generation == 0 || generation < engineGeneration)
        {
            return;
        }

        if (generation > engineGeneration)
        {
            engineGeneration = generation;
            snapshot = InventoryProductState.Unknown;
        }

        ApplySnapshot(next);
    }

    public void Dispose()
    {
        imageCancellation?.Cancel();
        imageCancellation?.Dispose();
        imageCancellation = null;
        ownedImageProvider?.Dispose();
    }

    private void Rebuild()
    {
        imageCancellation?.Cancel();
        imageCancellation?.Dispose();
        imageCancellation = null;

        allItems = snapshot.Items.Select(InventoryItemViewModel.Map).ToArray();
        if (imageProvider is not null && allItems.Count > 0)
        {
            imageCancellation = new CancellationTokenSource();
            _ = LoadImagesAsync(allItems, imageCancellation.Token);
        }

        categoryOptions = new[] { new InventoryCategoryOption(string.Empty, "Все категории") }
            .Concat(snapshot.Items
                .Select(item => item.Category)
                .Where(category => !string.IsNullOrWhiteSpace(category))
                .Distinct(StringComparer.OrdinalIgnoreCase)
                .OrderBy(category => category, StringComparer.OrdinalIgnoreCase)
                .ThenBy(category => category, StringComparer.Ordinal)
                .Select(category => new InventoryCategoryOption(category, category)))
            .ToArray();
        if (selectedCategory.Length > 0 && !categoryOptions.Any(option =>
            string.Equals(option.Value, selectedCategory, StringComparison.OrdinalIgnoreCase)))
        {
            selectedCategory = string.Empty;
            OnPropertyChanged(nameof(SelectedCategoryOption));
        }
        OnPropertyChanged(nameof(CategoryOptions));
        OnPropertyChanged(nameof(SelectedCategoryOption));
        RebuildVisibleItems();
    }

    private async Task LoadImagesAsync(
        IReadOnlyList<InventoryItemViewModel> items,
        CancellationToken cancellationToken)
    {
        try
        {
            await Task.WhenAll(items.Select(item =>
                item.LoadImageAsync(imageProvider!, cancellationToken)));
        }
        catch (OperationCanceledException)
        {
        }
    }

    private void RebuildVisibleItems()
    {
        var query = search.Trim();
        var category = selectedCategory.Trim();
        visibleItems = allItems
            .Where(item =>
                (query.Length == 0 || item.Name.Contains(
                    query,
                    StringComparison.OrdinalIgnoreCase)) &&
                (category.Length == 0 || string.Equals(
                    item.Category,
                    category,
                    StringComparison.OrdinalIgnoreCase)))
            .OrderBy(item => item.Row)
            .ThenBy(item => item.Column)
            .ThenBy(item => item.Name, StringComparer.OrdinalIgnoreCase)
            .ThenBy(item => item.RuntimeId, StringComparer.Ordinal)
            .ToArray();
        OnPropertyChanged(nameof(VisibleItems));
        OnPropertyChanged(nameof(ContentState));
        OnPropertyChanged(nameof(StateTitle));
        OnPropertyChanged(nameof(StateMessage));
    }

    private static string FormatNumber(double value) =>
        value.ToString("0.##", CultureInfo.CurrentCulture);

    private static string FormatPositionCount(int count)
    {
        var mod100 = count % 100;
        var mod10 = count % 10;
        var noun = mod100 is >= 11 and <= 14
            ? "позиций"
            : mod10 switch
            {
                1 => "позиция",
                2 or 3 or 4 => "позиции",
                _ => "позиций",
            };
        return $"{count} {noun}";
    }
}
