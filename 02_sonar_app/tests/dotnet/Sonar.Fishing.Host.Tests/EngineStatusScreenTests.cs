using System.Windows;
using System.Windows.Automation;
using System.Windows.Automation.Peers;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;
using System.Windows.Threading;
using Sonar.Fishing.Host.EngineStatus;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.Shell;
using Sonar.UI.Wpf;
using Sonar.UI.Wpf.Controls;
using FishingPageControl = Sonar.Fishing.Host.FishingPage.FishingPage;

namespace Sonar.Fishing.Host.Tests;

internal static class EngineStatusScreenTests
{
    public static IReadOnlyList<TestCase> Create(ResourceDictionary theme) =>
    [
        new("package_theme_loads_from_exact_reference", () => PackageThemeLoads(theme)),
        new("ready_running_stopping_mapping_is_stable", StatusMappingIsStable),
        new("common_controls_preserve_runtime_mutable_badge", RuntimeBadgeToneChanges),
        new("related_status_badges_stay_adjacent_to_their_headings", StatusBadgesStayAdjacent),
        new("host_shell_has_no_fixed_width_and_resizes", HostShellResizes),
        new("screen_exposes_accessible_keyboard_actions", ScreenIsAccessible),
    ];

    private static void PackageThemeLoads(ResourceDictionary theme)
    {
        var assemblyName = typeof(Card).Assembly.GetName();
        TestAssert.Equal("Sonar.UI.Wpf", assemblyName.Name!, "Unexpected Common UI assembly");
        TestAssert.Equal(new Version(0, 2, 13, 0), assemblyName.Version!, "Unexpected Common UI version");
        TestAssert.Equal(ThemeCatalog.DefaultThemeUri, theme.Source, "Theme URI changed");

        var missing = ThemeCatalog.FindMissingResources(theme);
        TestAssert.True(missing.Count == 0, $"Missing theme resources: {string.Join(", ", missing)}");
        foreach (var controlType in new[]
                 {
                     typeof(Card),
                     typeof(StatusBadge),
                     typeof(SectionHeader),
                     typeof(ActionButton),
                     typeof(MetricCard),
                     typeof(NavigationButton),
                 })
        {
            TestAssert.True(
                Application.Current.TryFindResource(controlType) is Style,
                $"Package theme did not publish a style for {controlType.Name}");
        }
    }

    private static void StatusMappingIsStable()
    {
        var ready = EngineStatusViewModel.FromSnapshot(EngineSessionSnapshot.InertReady);
        TestAssert.Equal("Можно начинать", ready.Title, "Ready title changed");
        TestAssert.Equal("Готово", ready.BadgeText, "Ready badge changed");
        TestAssert.Equal(SemanticTone.Success, ready.BadgeTone, "Ready tone changed");
        TestAssert.True(ready.CanStart && !ready.CanStop, "Ready action availability changed");

        var running = EngineStatusViewModel.FromSnapshot(new EngineSessionSnapshot(
            Running: true,
            Stopping: false,
            DetectedStage: "Ожидаем поклевку"));
        TestAssert.Equal("Работает", running.Title, "Running title changed");
        TestAssert.Equal("Ожидаем поклевку", running.Description, "Detected stage was lost");
        TestAssert.Equal("Активен", running.BadgeText, "Running badge changed");
        TestAssert.True(!running.CanStart && running.CanStop, "Running action availability changed");

        var stopping = EngineStatusViewModel.FromSnapshot(new EngineSessionSnapshot(
            Running: true,
            Stopping: true,
            DetectedStage: "Сохранение улова"));
        TestAssert.Equal("Остановка", stopping.Title, "Stopping title changed");
        TestAssert.Equal("Завершаем текущие операции", stopping.Description, "Stopping description changed");
        TestAssert.Equal("Остановка", stopping.BadgeText, "Stopping badge changed");
        TestAssert.Equal(SemanticTone.Warning, stopping.BadgeTone, "Stopping tone changed");
        TestAssert.True(!stopping.CanStart && !stopping.CanStop, "Stopping actions must be disabled");
    }

    private static void RuntimeBadgeToneChanges()
    {
        var screen = new EngineStatusScreen
        {
            ViewModel = EngineStatusViewModel.FromSnapshot(EngineSessionSnapshot.InertReady),
        };
        Arrange(screen, new Size(640, 360));

        TestAssert.IsType<Card>(screen.FindName("EngineStatusCard"), "Common Card is missing");
        TestAssert.IsType<SectionHeader>(screen.FindName("EngineStatusHeader"), "Common SectionHeader is missing");
        var badge = TestAssert.IsType<StatusBadge>(
            screen.FindName("EngineStatusBadge"),
            "Common StatusBadge is missing");
        TestAssert.IsType<ActionButton>(screen.FindName("StartFishingButton"), "Common start ActionButton is missing");
        TestAssert.IsType<ActionButton>(screen.FindName("StopFishingButton"), "Common stop ActionButton is missing");

        badge.ApplyTemplate();
        var readyBrush = TestAssert.IsType<SolidColorBrush>(badge.Foreground, "Ready badge brush was not resolved");

        screen.ViewModel = EngineStatusViewModel.FromSnapshot(new EngineSessionSnapshot(
            Running: true,
            Stopping: true,
            DetectedStage: string.Empty));
        BindingOperations.GetBindingExpression(badge, StatusBadge.ToneProperty)?.UpdateTarget();
        BindingOperations.GetBindingExpression(badge, ContentControl.ContentProperty)?.UpdateTarget();
        screen.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
        screen.UpdateLayout();

        TestAssert.Equal(SemanticTone.Warning, badge.Tone, "Runtime stopping tone was not applied");
        TestAssert.Equal("Остановка", badge.Content?.ToString()!, "Runtime stopping text was not applied");
        var stoppingBrush = TestAssert.IsType<SolidColorBrush>(
            badge.Foreground,
            "Stopping badge brush was not resolved");
        TestAssert.True(readyBrush.Color != stoppingBrush.Color, "Runtime tone did not update visuals");
    }

    private static void StatusBadgesStayAdjacent()
    {
        var shell = new FishingHostShell();
        shell.ViewModel.ShowFishingCommand.Execute(null);
        Arrange(shell, new Size(1_180, 760));

        var pageHeader = WpfTestVisualTree.FindDescendants<PageHeader>(shell)
            .Single(header => string.Equals(header.Title, "Sonar Fishing", StringComparison.Ordinal));
        var hostBadge = TestAssert.IsType<StatusBadge>(
            shell.FindName("HostModeBadge"),
            "Host mode badge is missing");
        AssertAdjacent(pageHeader, hostBadge, "Sonar Fishing", "Host mode badge");

        var fishingPage = WpfTestVisualTree.FindDescendant<FishingPageControl>(
            shell,
            "Fishing page is missing from the shell");
        var screen = TestAssert.IsType<EngineStatusScreen>(
            fishingPage.FindName("EngineStatusScreen"),
            "Engine status screen is missing");
        var sectionHeader = TestAssert.IsType<SectionHeader>(
            screen.FindName("EngineStatusHeader"),
            "Engine status header is missing");
        var engineBadge = TestAssert.IsType<StatusBadge>(
            screen.FindName("EngineStatusBadge"),
            "Automation status badge is missing");
        AssertAdjacent(sectionHeader, engineBadge, "Автоматизация", "Automation status badge");
    }

    private static void AssertAdjacent(
        FrameworkElement header,
        FrameworkElement badge,
        string title,
        string context)
    {
        header.ApplyTemplate();
        var titleBlock = WpfTestVisualTree.FindDescendants<TextBlock>(header)
            .Single(block => string.Equals(block.Text, title, StringComparison.Ordinal));
        var titleBounds = titleBlock.TransformToAncestor(header).TransformBounds(
            new Rect(new Point(0, 0), titleBlock.RenderSize));
        var badgeBounds = badge.TransformToAncestor(header).TransformBounds(
            new Rect(new Point(0, 0), badge.RenderSize));
        TestAssert.True(
            badgeBounds.Left >= titleBounds.Right - 0.5 &&
            badgeBounds.Left - titleBounds.Right <= 12.5,
            $"{context} is not adjacent to its title");
        TestAssert.True(
            Math.Abs(badgeBounds.Top - titleBounds.Top) <= 4,
            $"{context} is not aligned with its title");
    }

    private static void HostShellResizes()
    {
        var shell = new FishingHostShell();
        TestAssert.True(double.IsNaN(shell.Width), "Host shell introduced a fixed width");
        TestAssert.True(shell.MinWidth == 0, "Host shell introduced a minimum width");
        TestAssert.True(double.IsPositiveInfinity(shell.MaxWidth), "Host shell introduced a maximum width");

        Arrange(shell, new Size(420, 320));
        var narrowWidth = shell.ActualWidth;
        Arrange(shell, new Size(940, 640));
        var wideWidth = shell.ActualWidth;
        TestAssert.True(Math.Abs(narrowWidth - 420) < 0.1, "Host shell did not accept narrow layout width");
        TestAssert.True(Math.Abs(wideWidth - 940) < 0.1, "Host shell did not accept wide layout width");

        shell.ViewModel.ShowFishingCommand.Execute(null);
        Arrange(shell, new Size(940, 640));

        var fishingPage = WpfTestVisualTree.FindDescendant<FishingPageControl>(
            shell,
            "Fishing page is missing from the shell");
        var screen = TestAssert.IsType<EngineStatusScreen>(
            fishingPage.FindName("EngineStatusScreen"),
            "Engine status screen is missing from the Fishing page");
        TestAssert.True(double.IsNaN(screen.Width), "Engine screen introduced a fixed width");
        var description = TestAssert.IsType<TextBlock>(
            screen.FindName("EngineStatusDescription"),
            "Engine description is missing");
        TestAssert.Equal(TextWrapping.Wrap, description.TextWrapping, "Responsive description wrapping changed");
    }

    private static void ScreenIsAccessible()
    {
        var shell = new FishingHostShell();
        Arrange(shell, new Size(720, 480));
        TestAssert.Equal("Sonar Fishing", AutomationProperties.GetName(shell), "Shell automation name changed");

        var brand = TestAssert.IsType<AppBrand>(
            shell.FindName("ProductBrand"),
            "Common AppBrand is missing");
        TestAssert.Equal(
            "Sonar Fishing",
            AutomationProperties.GetName(brand),
            "Product brand automation name changed");

        shell.ViewModel.ShowFishingCommand.Execute(null);
        Arrange(shell, new Size(720, 480));

        var fishingPage = WpfTestVisualTree.FindDescendant<FishingPageControl>(
            shell,
            "Fishing page is missing");
        var screen = TestAssert.IsType<EngineStatusScreen>(
            fishingPage.FindName("EngineStatusScreen"),
            "Engine status screen is missing");
        TestAssert.Equal(
            "Управление рыбалкой",
            AutomationProperties.GetName(screen),
            "Screen automation name changed");

        var start = TestAssert.IsType<ActionButton>(
            screen.FindName("StartFishingButton"),
            "Start action is missing");
        var stop = TestAssert.IsType<ActionButton>(
            screen.FindName("StopFishingButton"),
            "Stop action is missing");
        TestAssert.Equal("Начать рыбалку", new ButtonAutomationPeer(start).GetName(), "Start automation name changed");
        TestAssert.Equal("Остановить рыбалку", new ButtonAutomationPeer(stop).GetName(), "Stop automation name changed");
        TestAssert.True(start.IsTabStop && stop.IsTabStop, "Engine actions must remain keyboard reachable");
        TestAssert.True(
            !string.IsNullOrWhiteSpace(AutomationProperties.GetHelpText(start)) &&
            !string.IsNullOrWhiteSpace(AutomationProperties.GetHelpText(stop)),
            "Engine actions require accessible help text while they are inert");
    }

    private static void Arrange(FrameworkElement element, Size size)
    {
        element.Measure(size);
        element.Arrange(new Rect(new Point(0, 0), size));
        element.UpdateLayout();
    }
}
