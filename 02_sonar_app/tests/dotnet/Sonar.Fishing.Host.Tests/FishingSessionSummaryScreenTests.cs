using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Media;
using System.Windows.Threading;
using Sonar.Fishing.Host.FishingSessionSummary;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Shell;
using Sonar.UI.Wpf.Controls;
using Sonar.UI.Wpf.Layout;
using FishingPageControl = Sonar.Fishing.Host.FishingPage.FishingPage;

namespace Sonar.Fishing.Host.Tests;

internal static class FishingSessionSummaryScreenTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("session_summary_mapping_matches_frozen_presentation_contract", MappingMatchesFrozenContract),
        new("session_summary_snapshot_defensively_freezes_tackle_items", SnapshotFreezesTackleItems),
        new("session_summary_composes_only_common_visual_primitives", CommonPrimitiveCompositionIsStable),
        new("session_summary_is_resizable_and_accessible", SummaryIsResizableAndAccessible),
        new("migration_preview_preserves_six_tackle_slots_in_order", PreviewPreservesTackleOrder),
        new("real_engine_session_state_replaces_offline_preview", RealEngineStateReplacesOfflinePreview),
    ];

    private static void MappingMatchesFrozenContract()
    {
        var empty = FishingSessionSummaryViewModel.FromSnapshot(FishingSessionSummarySnapshot.Empty);
        TestAssert.Equal("0 мин", empty.Duration, "Empty duration changed");
        TestAssert.Equal("0", empty.Caught, "Empty caught count changed");
        TestAssert.Equal("0", empty.Released, "Empty released count changed");
        TestAssert.Equal("0 $", empty.Income, "Empty income changed");
        TestAssert.True(!empty.HasTackleItems, "Empty snapshot must stay unscanned");
        TestAssert.Equal(
            "Снаряжение появится после начала рыбалки",
            empty.EmptyTackleMessage,
            "Legacy empty tackle text changed");

        var populated = FishingSessionSummaryViewModel.FromSnapshot(new FishingSessionSummarySnapshot(
            durationSeconds: 3660,
            caughtCount: 12,
            releasedCount: 4,
            earnedMin: 1200,
            earnedMax: 1500,
            tackleItems: new[]
            {
                new TackleItemSnapshot("Удочка", 1),
                new TackleItemSnapshot("Наживка/блёсна", 18),
            }));

        TestAssert.Equal("1 ч 1 мин", populated.Duration, "Duration formatting changed");
        TestAssert.Equal("12", populated.Caught, "Caught count changed");
        TestAssert.Equal("4", populated.Released, "Released count changed");
        TestAssert.Equal("от 1 200 $ до 1 500 $", populated.Income, "Income range formatting changed");
        TestAssert.True(populated.HasTackleItems, "Scanned tackle must be visible");
        TestAssert.Equal("Удочка", populated.TackleItems[0].Name, "Tackle name changed");
        TestAssert.Equal("1шт.", populated.TackleItems[0].CountText, "Tackle count formatting changed");

        var threshold = FishingSessionSummaryViewModel.FromSnapshot(new FishingSessionSummarySnapshot(
            durationSeconds: -1,
            caughtCount: 0,
            releasedCount: 0,
            earnedMin: 1200.1,
            earnedMax: 1200.5,
            tackleItems: Array.Empty<TackleItemSnapshot>()));
        TestAssert.Equal("0 мин", threshold.Duration, "Negative legacy duration clamp changed");
        TestAssert.Equal("1 200 $", threshold.Income, "Money-range threshold changed");
    }

    private static void SnapshotFreezesTackleItems()
    {
        var source = new List<TackleItemSnapshot>
        {
            new("Удочка", 1),
        };
        var snapshot = new FishingSessionSummarySnapshot(
            durationSeconds: 0,
            caughtCount: 0,
            releasedCount: 0,
            earnedMin: 0,
            earnedMax: 0,
            tackleItems: source);

        source.Add(new TackleItemSnapshot("Подсак", 1));
        TestAssert.Equal(1, snapshot.TackleItems.Count, "Snapshot retained caller-owned mutable storage");
        TestAssert.True(
            snapshot.TackleItems is ICollection<TackleItemSnapshot> collection && collection.IsReadOnly,
            "Snapshot tackle collection must be read-only");
    }

    private static void CommonPrimitiveCompositionIsStable()
    {
        var viewModel = FishingSessionSummaryViewModel.FromSnapshot(new FishingSessionSummarySnapshot(
            durationSeconds: 3720,
            caughtCount: 12,
            releasedCount: 4,
            earnedMin: 15400,
            earnedMax: 16600,
            tackleItems: new[]
            {
                new TackleItemSnapshot("Удочка", 1),
                new TackleItemSnapshot("Подсак", 1),
            }));
        var screen = new FishingSessionSummaryScreen { ViewModel = viewModel };
        Arrange(screen, new Size(760, 540));

        TestAssert.IsType<Card>(screen.FindName("SessionMetricsCard"), "Common metrics Card is missing");
        TestAssert.IsType<SectionHeader>(screen.FindName("SessionSummaryHeader"), "Common session header is missing");
        TestAssert.IsType<Card>(screen.FindName("TackleCard"), "Common tackle Card is missing");
        TestAssert.IsType<SectionHeader>(screen.FindName("TackleHeader"), "Common tackle header is missing");

        var duration = TestAssert.IsType<MetricCard>(screen.FindName("DurationMetric"), "Common duration MetricCard is missing");
        var caught = TestAssert.IsType<MetricCard>(screen.FindName("CaughtMetric"), "Common caught MetricCard is missing");
        var released = TestAssert.IsType<MetricCard>(screen.FindName("ReleasedMetric"), "Common released MetricCard is missing");
        var income = TestAssert.IsType<MetricCard>(screen.FindName("IncomeMetric"), "Common income MetricCard is missing");
        TestAssert.Equal("1 ч 2 мин", duration.Value, "Duration binding changed");
        TestAssert.Equal("12", caught.Value, "Caught binding changed");
        TestAssert.Equal("4", released.Value, "Released binding changed");
        TestAssert.Equal("от 15 400 $ до 16 600 $", income.Value, "Income binding changed");

        var items = TestAssert.IsType<ItemsControl>(screen.FindName("TackleItemsList"), "Tackle list is missing");
        TestAssert.Equal(2, items.Items.Count, "Tackle rows were lost");
        var emptyMessage = TestAssert.IsType<TextBlock>(screen.FindName("EmptyTackleMessage"), "Empty tackle state is missing");
        TestAssert.Equal(Visibility.Collapsed, emptyMessage.Visibility, "Populated tackle still shows empty state");
    }

    private static void SummaryIsResizableAndAccessible()
    {
        var shell = new FishingHostShell();
        Arrange(shell, new Size(420, 640));
        shell.ViewModel.ShowFishingCommand.Execute(null);
        Arrange(shell, new Size(420, 640));
        var fishingPage = WpfTestVisualTree.FindDescendant<FishingPageControl>(
            shell,
            "Fishing page is missing from the Host shell");
        var screen = TestAssert.IsType<FishingSessionSummaryScreen>(
            fishingPage.FindName("FishingSessionSummaryScreen"),
            "Session summary is missing from the Fishing page");
        TestAssert.True(double.IsNaN(screen.Width), "Session summary introduced a fixed width");
        TestAssert.True(screen.MinWidth == 0, "Session summary introduced a minimum width");
        TestAssert.True(double.IsPositiveInfinity(screen.MaxWidth), "Session summary introduced a maximum width");

        Arrange(shell, new Size(940, 760));
        TestAssert.Equal(
            "Сводка текущей сессии рыбалки",
            AutomationProperties.GetName(screen),
            "Summary automation name changed");
        var header = TestAssert.IsType<SectionHeader>(
            screen.FindName("SessionSummaryHeader"),
            "Session summary heading is missing");
        TestAssert.Equal(
            AutomationHeadingLevel.Level2,
            AutomationProperties.GetHeadingLevel(header),
            "Session summary heading level changed");

        var metricGrid = TestAssert.IsType<ResponsiveGrid>(
            screen.FindName("SessionMetricGrid"),
            "Responsive metric grid is missing");
        TestAssert.Equal(8, metricGrid.CurrentColumnCount, "Medium responsive grid contract changed");
        var duration = TestAssert.IsType<MetricCard>(screen.FindName("DurationMetric"), "Duration metric is missing");
        TestAssert.Equal("Время, 1 ч 2 мин", AutomationProperties.GetName(duration), "Metric accessibility changed");

        var emptyScreen = new FishingSessionSummaryScreen();
        Arrange(emptyScreen, new Size(420, 360));
        var emptyMessage = TestAssert.IsType<TextBlock>(
            emptyScreen.FindName("EmptyTackleMessage"),
            "Empty tackle message is missing");
        TestAssert.Equal(Visibility.Visible, emptyMessage.Visibility, "Unscanned tackle state is hidden");
        TestAssert.Equal(TextWrapping.Wrap, emptyMessage.TextWrapping, "Empty state no longer wraps responsively");
    }

    private static void PreviewPreservesTackleOrder()
    {
        var names = FishingPageViewModel.MigrationPreview.SessionSummary.TackleItems
            .Select(item => item.Name)
            .ToArray();
        TestAssert.True(
            names.SequenceEqual(
            [
                "Удочка",
                "Катушка",
                "Леска",
                "Крючки/поводки",
                "Наживка/блёсна",
                "Подсак",
            ]),
            "Migration preview lost the exact six-slot tackle order");
    }

    private static void RealEngineStateReplacesOfflinePreview()
    {
        var viewModel = FishingPageViewModel.CreateOfflineEngine();
        var changes = new List<string?>();
        viewModel.PropertyChanged += (_, args) => changes.Add(args.PropertyName);

        viewModel.ApplySessionState(new FishingSessionStateSnapshot(
            revision: 7,
            running: true,
            stopping: false,
            detectedStage: "Проверка снастей",
            totals: new FishingSessionTotalsSnapshot(
                DurationSeconds: 3660,
                CaughtCount: 12,
                CaughtKg: 31.5,
                ReleasedCount: 4,
                ReleasedKg: 8.2,
                EarnedMin: 1200,
                EarnedMax: 1500),
            tackleItems:
            [
                new FishingTackleItemSnapshot("rod", "Удочка", 1),
                new FishingTackleItemSnapshot("bait", "Наживка/блёсна", 18),
            ]));

        TestAssert.Equal("Работает", viewModel.EngineStatus.Title, "Real Engine status was not mapped");
        TestAssert.Equal("12", viewModel.SessionSummary.Caught, "Real caught count was not mapped");
        TestAssert.Equal(2, viewModel.SessionSummary.TackleItems.Count, "Real tackle state was lost");
        TestAssert.True(
            changes.Contains(nameof(FishingPageViewModel.EngineStatus)) &&
            changes.Contains(nameof(FishingPageViewModel.SessionSummary)),
            "WPF composition did not notify both session surfaces");
    }

    private static void Arrange(FrameworkElement element, Size size)
    {
        element.Measure(size);
        element.Arrange(new Rect(new Point(0, 0), size));
        element.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
        element.UpdateLayout();
    }
}
