using System.Windows;
using Sonar.UI.Wpf;

namespace Sonar.Fishing.Host.Tests;

internal static class Program
{
    [STAThread]
    private static int Main(string[] args)
    {
        var application = new Application
        {
            ShutdownMode = ShutdownMode.OnExplicitShutdown,
        };
        var theme = new ResourceDictionary { Source = ThemeCatalog.DefaultThemeUri };
        application.Resources.MergedDictionaries.Add(theme);

        if (args is ["--render-ui", var outputDirectory])
        {
            try
            {
                var result = UiGalleryRenderer.Render(outputDirectory);
                Console.WriteLine(
                    $"Rendered {result.ImageCount} Fishing UI images to {result.OutputDirectory}.");
                application.Shutdown();
                return 0;
            }
            catch (Exception exception)
            {
                Console.Error.WriteLine($"UI gallery render failed: {exception}");
                application.Shutdown();
                return 1;
            }
        }

        if (args is ["--verify-saved-license", var configPath])
        {
            var result = LiveLicenseProbe.Run(configPath);
            application.Shutdown();
            return result;
        }

        if (args is ["--verify-production-startup"])
        {
            var result = LiveStartupBlockProbe.Run();
            application.Shutdown();
            return result;
        }

        if (args.Length != 0)
        {
            Console.Error.WriteLine(
                "Usage: Sonar.Fishing.Host.Tests [--render-ui <output-directory>] " +
                "[--verify-saved-license <config-path>] [--verify-production-startup]");
            application.Shutdown();
            return 2;
        }

        var tests = EngineStatusScreenTests.Create(theme)
            .Concat(FishingSessionSummaryScreenTests.Create())
            .Concat(FishingHostNavigationTests.Create())
            .Concat(InventoryPageTests.Create())
            .Concat(HostRuntimeTests.Create())
            .Concat(EngineSupervisorTests.Create())
            .Concat(EngineSessionIdentityTests.Create())
            .Concat(FishingAutomationViewModelTests.Create())
            .Concat(FishingStateStoreTests.Create())
            .Concat(FishingFishCatalogTests.Create())
            .Concat(FishingProductModelTests.Create())
            .Concat(TelegramSettingsPageTests.Create())
            .Concat(TelegramInboundRouterTests.Create())
            .Concat(TelegramNotificationPlannerTests.Create())
            .Concat(TelegramEngineNotificationPublisherTests.Create())
            .Concat(TelegramBotApiClientTests.Create())
            .Concat(TelegramPollingServiceTests.Create())
            .Concat(TelegramCommandDispatcherTests.Create())
            .Concat(StartupBlockGateTests.Create())
            .Concat(CurrentSessionStatisticsTests.Create())
            .Concat(StreamingPageTests.Create())
            .Concat(StreamingRuntimeTests.Create())
            .Concat(UpdateRuntimeTests.Create())
            .Concat(LocalReleaseMaintenanceTests.Create())
            .Concat(ProductDiagnosticLogTests.Create())
            .Concat(StartStopHotkeyTests.Create())
            .Concat(FishingEntitlementTests.Create())
            .Concat(FishingKeygenLicenseVerifierTests.Create())
            .Concat(LicensePageTests.Create())
            .Concat(VisibleCopyTests.Create())
            .Concat(DesignSystemCompositionTests.Create())
            .Concat(UiGalleryRendererTests.Create())
            .ToArray();
        var failures = 0;
        foreach (var test in tests)
        {
            try
            {
                test.Run();
                Console.WriteLine($"PASS {test.Name}");
            }
            catch (Exception exception)
            {
                failures++;
                Console.Error.WriteLine($"FAIL {test.Name}: {exception}");
            }
        }

        Console.WriteLine($"Executed {tests.Length} Fishing WPF tests; failures: {failures}.");
        application.Shutdown();
        return failures == 0 ? 0 : 1;
    }
}
