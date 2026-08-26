using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;
using Sonar.Fishing.Host.InventoryPage;
using Sonar.Fishing.Host.EngineIntegration.Inventory;
using Sonar.Inventory.Ipc.Contracts.V1;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.Tests;

internal static class InventoryPageTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("inventory_page_keeps_latest_snapshot_and_filters_locally", LatestSnapshotWins),
        new("inventory_page_accepts_fresh_revision_after_engine_recovery", FreshGenerationWins),
        new("inventory_wire_mapper_preserves_common_grid_images_and_weight", CommonWireSnapshotMaps),
        new("inventory_page_uses_shared_square_spatial_panel_without_horizontal_scroll", SharedSpatialPanelIsUsed),
    ];

    private static void LatestSnapshotWins()
    {
        var viewModel = new InventoryPageViewModel(Snapshot(
            revision: 2,
            Item("meat", "Мясо оленя", "Еда", 0, 0)));

        viewModel.ApplySnapshot(Snapshot(
            revision: 1,
            Item("knife", "Нож", "Инструменты", 1, 0)));
        TestAssert.Equal(1, viewModel.VisibleItems.Count, "Stale inventory changed item count");
        TestAssert.Equal("Мясо оленя", viewModel.VisibleItems[0].Name, "Stale inventory replaced latest state");

        viewModel.ApplySnapshot(Snapshot(
            revision: 3,
            Item("meat", "Мясо оленя", "Еда", 0, 0),
            Item("knife", "Нож", "Инструменты", 1, 0)));
        viewModel.Search = "нож";
        TestAssert.Equal(1, viewModel.VisibleItems.Count, "Inventory search did not filter locally");
        TestAssert.Equal("Нож", viewModel.VisibleItems[0].Name, "Inventory search selected another item");
    }

    private static void FreshGenerationWins()
    {
        var viewModel = new InventoryPageViewModel(InventoryProductState.Unknown);
        viewModel.ApplyEngineSnapshot(2, Snapshot(
            revision: 50,
            Item("meat", "Мясо оленя", "Еда", 0, 0)));
        viewModel.ApplyEngineSnapshot(3, Snapshot(
            revision: 1,
            Item("knife", "Нож", "Инструменты", 1, 0)));
        viewModel.ApplyEngineSnapshot(2, Snapshot(
            revision: 51,
            Item("stale", "Устаревшее", "Инструменты", 2, 0)));

        TestAssert.Equal(1, viewModel.VisibleItems.Count, "Fresh generation item count changed");
        TestAssert.Equal("Нож", viewModel.VisibleItems[0].Name, "Old generation crossed recovery");
    }

    private static void CommonWireSnapshotMaps()
    {
        var wire = new InventoryStateSnapshot
        {
            Availability = InventoryAvailability.Ready,
            Revision = 7,
            ObservedAtMs = 15,
            Open = true,
            CurrentWeight = 19.9,
            MaximumWeight = 40,
            GridRows = 5,
            GridColumns = 4,
        };
        wire.Items.Add(new InventoryItemSnapshot
        {
            RuntimeId = "knife-1",
            CatalogItemId = 246,
            Name = "Нож",
            Category = "Инструменты",
            Column = 1,
            Row = 2,
            ColumnSpan = 1,
            RowSpan = 3,
            Count = 1,
            MaximumCount = 1,
            UnitWeight = 0.18,
            TotalWeight = 0.18,
            ConditionPercent = 75,
            ConditionKind = Sonar.Inventory.Ipc.Contracts.V1.InventoryConditionKind.Wear,
            Description = "Охотничий нож",
            ImageReference = "https://example.invalid/items/246.png",
        });

        var mapped = FishingInventoryWireMapper.Map(wire);
        TestAssert.True(mapped.Ready, "Ready Common snapshot became unavailable");
        TestAssert.Equal((uint)5, mapped.GridRows, "Common grid rows were not preserved");
        TestAssert.Equal((uint)4, mapped.GridColumns, "Common grid columns were not preserved");
        TestAssert.Equal(19.9, mapped.CurrentWeight!.Value, "Inventory weight changed");
        TestAssert.Equal(
            "https://example.invalid/items/246.png",
            mapped.Items[0].ImageReference,
            "Catalog image reference changed");
    }

    private static void SharedSpatialPanelIsUsed()
    {
        var viewModel = new InventoryPageViewModel(Snapshot(
            revision: 1,
            Item("meat", "Мясо оленя", "Еда", 0, 0, columnSpan: 2, rowSpan: 2),
            Item("knife", "Нож", "Инструменты", 2, 0, columnSpan: 1, rowSpan: 3)) with
        {
            GridColumns = 4,
            GridRows = 5,
        });
        viewModel.ViewModeIndex = 1;
        var screen = new InventoryScreen { ViewModel = viewModel };
        Arrange(screen, new Size(920, 760));

        var panel = WpfTestVisualTree.FindDescendant<InventorySpatialPanel>(
            screen,
            "Fishing inventory did not compose the Common spatial panel");
        TestAssert.Equal(4, panel.Columns, "Inventory grid column contract changed");
        TestAssert.Equal(5, panel.Rows, "Inventory grid row contract changed");
        var scroll = TestAssert.IsType<ScrollViewer>(
            screen.FindName("SpatialScroll"),
            "Inventory spatial viewport is missing");
        TestAssert.Equal(
            ScrollBarVisibility.Disabled,
            scroll.HorizontalScrollBarVisibility,
            "Inventory spatial view allows horizontal scrolling");
    }

    private static InventoryProductState Snapshot(
        ulong revision,
        params InventoryItemState[] items) => new(
            Ready: true,
            Reason: "ready",
            Revision: revision,
            ObservedAtMilliseconds: revision,
            OpenKnown: true,
            Open: true,
            CurrentWeight: 1.2,
            MaximumWeight: 40,
            Items: items);

    private static InventoryItemState Item(
        string id,
        string name,
        string category,
        uint column,
        uint row,
        uint columnSpan = 1,
        uint rowSpan = 1) => new(
            RuntimeId: id,
            CatalogItemId: 1,
            Name: name,
            Category: category,
            Column: column,
            Row: row,
            ColumnSpan: columnSpan,
            RowSpan: rowSpan,
            Count: 1,
            MaximumCount: 1,
            UnitWeight: 0.1,
            TotalWeight: 0.1,
            ConditionPercent: null,
            FreshnessPercent: null,
            ConditionKind: Sonar.Fishing.Host.InventoryPage.InventoryConditionKind.None,
            Durability: string.Empty,
            Description: string.Empty,
            ImageReference: string.Empty,
            DetailLines: Array.Empty<string>());

    private static void Arrange(FrameworkElement element, Size size)
    {
        element.Measure(size);
        element.Arrange(new Rect(new Point(0, 0), size));
        element.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
        element.UpdateLayout();
    }
}
