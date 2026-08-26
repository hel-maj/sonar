using System.Windows;
using System.Windows.Automation;
using System.Windows.Automation.Peers;
using System.Windows.Controls;
using System.Windows.Threading;
using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.LicensePage;
using Sonar.Fishing.Host.InventoryPage;
using Sonar.Fishing.Host.StatisticsPage;
using Sonar.Fishing.Host.Shell;
using Sonar.UI.Wpf.Controls;
using FishingPageControl = Sonar.Fishing.Host.FishingPage.FishingPage;

namespace Sonar.Fishing.Host.Tests;

internal static class FishingHostNavigationTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("shell_navigation_uses_common_primitives_and_real_pages", NavigationUsesCommonPrimitives),
        new("offline_engine_page_is_accessible_and_truthful", EngineHealthPageIsAccessible),
    ];

    private static void NavigationUsesCommonPrimitives()
    {
        var shell = new FishingHostShell();
        Arrange(shell, new Size(980, 700));

        TestAssert.IsType<AppShell>(shell.FindName("ApplicationShell"), "Common AppShell is missing");
        TestAssert.IsType<AppBrand>(shell.FindName("ProductBrand"), "Common AppBrand is missing");
        var licenseButton = TestAssert.IsType<NavigationButton>(
            shell.FindName("LicenseNavigationButton"),
            "Common License NavigationButton is missing");
        var fishingButton = TestAssert.IsType<NavigationButton>(
            shell.FindName("FishingNavigationButton"),
            "Common Fishing NavigationButton is missing");
        var inventoryButton = TestAssert.IsType<NavigationButton>(
            shell.FindName("InventoryNavigationButton"),
            "Inventory navigation is missing");
        TestAssert.IsType<NavigationButton>(shell.FindName("OverviewNavigationButton"), "Overview navigation is missing");
        TestAssert.IsType<NavigationButton>(shell.FindName("SettingsNavigationButton"), "Settings navigation is missing");
        var statisticsButton = TestAssert.IsType<NavigationButton>(
            shell.FindName("StatisticsNavigationButton"),
            "Statistics navigation is missing");
        TestAssert.IsType<NavigationButton>(shell.FindName("StreamingNavigationButton"), "Streaming navigation is missing");
        TestAssert.IsType<NavigationButton>(shell.FindName("TelegramNavigationButton"), "Telegram navigation is missing");
        TestAssert.IsType<NavigationButton>(shell.FindName("AboutNavigationButton"), "About navigation is missing");
        TestAssert.IsType<StatusBadge>(shell.FindName("HostModeBadge"), "Common mode StatusBadge is missing");
        TestAssert.True(licenseButton.IsSelected, "License page is not initially selected");
        TestAssert.True(!fishingButton.IsSelected, "Fishing page was selected unexpectedly");
        WpfTestVisualTree.FindDescendant<LicenseScreen>(shell, "License page was not composed");

        shell.ViewModel.ShowFishingCommand.Execute(null);
        Arrange(shell, new Size(980, 700));
        TestAssert.True(!licenseButton.IsSelected, "License selection was not cleared");
        TestAssert.True(fishingButton.IsSelected, "Fishing selection was not applied");
        WpfTestVisualTree.FindDescendant<FishingPageControl>(shell, "Fishing page was not composed");

        shell.ViewModel.ShowInventoryCommand.Execute(null);
        Arrange(shell, new Size(980, 700));
        TestAssert.True(inventoryButton.IsSelected, "Inventory selection was not applied");
        WpfTestVisualTree.FindDescendant<InventoryScreen>(shell, "Inventory page was not composed");

        shell.ViewModel.ShowStatisticsCommand.Execute(null);
        Arrange(shell, new Size(980, 700));
        TestAssert.True(!fishingButton.IsSelected, "Fishing selection was not cleared");
        TestAssert.True(statisticsButton.IsSelected, "Statistics selection was not applied");
        WpfTestVisualTree.FindDescendant<StatisticsScreen>(shell, "Statistics page was not composed");
        TestAssert.True(
            licenseButton.IsTabStop && fishingButton.IsTabStop && statisticsButton.IsTabStop,
            "Navigation must remain keyboard reachable");
    }

    private static void EngineHealthPageIsAccessible()
    {
        var health = EngineHealthViewModel.CreateDemo();
        var screen = new EngineHealthScreen { ViewModel = health };
        Arrange(screen, new Size(760, 520));

        TestAssert.Equal(
            "Проверка приложения",
            AutomationProperties.GetName(screen),
            "Application check screen automation name changed");
        TestAssert.IsType<Card>(screen.FindName("EngineHealthCard"), "Common health Card is missing");
        TestAssert.IsType<SectionHeader>(screen.FindName("EngineHealthHeader"), "Common health SectionHeader is missing");
        TestAssert.IsType<StatusBadge>(screen.FindName("EngineHealthBadge"), "Common health StatusBadge is missing");
        var check = TestAssert.IsType<ActionButton>(
            screen.FindName("CheckEngineHealthButton"),
            "Common health ActionButton is missing");
        TestAssert.Equal(
            "Проверить приложение",
            new ButtonAutomationPeer(check).GetName(),
            "Health action automation name changed");
        TestAssert.True(!check.IsEnabled, "Preview exposed an unavailable check action");
        TestAssert.Equal(
            "Запустите приложение обычным способом и повторите.",
            health.Description,
            "Preview check guidance changed");
        VisibleCopyAudit.AssertSurface(screen, "application-check/preview");
    }

    private static void Arrange(FrameworkElement element, Size size)
    {
        element.Measure(size);
        element.Arrange(new Rect(new Point(0, 0), size));
        element.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
        element.UpdateLayout();
    }
}
