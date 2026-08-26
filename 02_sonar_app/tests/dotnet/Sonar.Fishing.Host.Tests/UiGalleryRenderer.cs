using System.Security.Cryptography;
using System.Text.Json;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using Sonar.Fishing.Host.AboutPage;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.LicensePage;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.InventoryPage;
using Sonar.Fishing.Host.Overview;
using Sonar.Fishing.Host.ProductNavigation;
using Sonar.Fishing.Host.SettingsPage;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.Shell;
using Sonar.Fishing.Host.StartupGate;
using Sonar.Fishing.Host.StatisticsPage;
using Sonar.Fishing.Host.StreamingPage;
using Sonar.Fishing.Host.TelegramPage;
using Sonar.UI.Wpf;

namespace Sonar.Fishing.Host.Tests;

internal sealed record UiGalleryRenderDefinition(
    string PageId,
    string VariantId,
    string LayoutId,
    double WidthDip,
    double HeightDip,
    int DpiPercent);

internal sealed record UiGalleryRenderResult(string OutputDirectory, int ImageCount);

internal static class UiGalleryRenderer
{
    internal static string CommonUiVersion
    {
        get
        {
            var version = typeof(ThemeCatalog).Assembly.GetName().Version
                ?? throw new InvalidOperationException("Common UI assembly version is unavailable.");
            return $"{version.Major}.{version.Minor}.{version.Build}";
        }
    }

    private static readonly (string Id, Action<FishingHostShellViewModel> Navigate)[] Pages =
    [
        ("overview", viewModel => viewModel.ShowOverviewCommand.Execute(null)),
        ("engine-health", viewModel => viewModel.ShowEngineHealthCommand.Execute(null)),
        ("license", viewModel => viewModel.ShowLicenseCommand.Execute(null)),
        ("fishing", viewModel => viewModel.ShowFishingCommand.Execute(null)),
        ("inventory", viewModel => viewModel.ShowInventoryCommand.Execute(null)),
        ("settings", viewModel => viewModel.ShowSettingsCommand.Execute(null)),
        ("statistics", viewModel =>
        {
            viewModel.ShowStatisticsCommand.Execute(null);
            ((StatisticsPageViewModel)viewModel.CurrentPage).ApplySessionState(
                CreateStatisticsPreview());
        }),
        ("streaming", viewModel => viewModel.ShowStreamingCommand.Execute(null)),
        ("telegram", viewModel => viewModel.ShowTelegramCommand.Execute(null)),
        ("about", viewModel => viewModel.ShowAboutCommand.Execute(null)),
    ];

    private static readonly (string Id, double Width, double Height)[] Layouts =
    [
        ("compact", 640, 720),
        ("medium", 960, 760),
        ("expanded", 1280, 800),
    ];

    private static readonly int[] DpiPercentages = [100, 125, 150, 200];

    internal static IReadOnlyList<UiGalleryRenderDefinition> Definitions { get; } =
        (from page in Pages
         from layout in Layouts
         from dpi in DpiPercentages
         select new UiGalleryRenderDefinition(
             page.Id,
             "top",
             layout.Id,
             layout.Width,
             layout.Height,
             dpi))
        .Concat(
            from layout in Layouts
            from dpi in DpiPercentages
            select new UiGalleryRenderDefinition(
                "fishing",
                "session",
                layout.Id,
                layout.Width,
                layout.Height,
                dpi))
        .Concat(
            from layout in Layouts
            from dpi in DpiPercentages
            select new UiGalleryRenderDefinition(
                "settings",
                "fish-selection",
                layout.Id,
                layout.Width,
                layout.Height,
                dpi))
        .Concat(
            from layout in Layouts
            from dpi in DpiPercentages
            select new UiGalleryRenderDefinition(
                "settings",
                "thresholds",
                layout.Id,
                layout.Width,
                layout.Height,
                dpi))
        .Concat(
            from layout in Layouts
            from dpi in DpiPercentages
            select new UiGalleryRenderDefinition(
                "settings",
                "hotkey-conflict",
                layout.Id,
                layout.Width,
                layout.Height,
                dpi))
        .Concat(
            from variant in new[] { "checking", "blocked", "unavailable" }
            from layout in Layouts
            from dpi in DpiPercentages
            select new UiGalleryRenderDefinition(
                "startup",
                variant,
                layout.Id,
                layout.Width,
                layout.Height,
                dpi))
        .ToArray();

    internal static UiGalleryRenderResult Render(string outputDirectory)
    {
        if (string.IsNullOrWhiteSpace(outputDirectory))
        {
            throw new ArgumentException("UI gallery output directory is required.", nameof(outputDirectory));
        }

        var fullOutputDirectory = Path.GetFullPath(outputDirectory);
        Directory.CreateDirectory(fullOutputDirectory);
        var shell = new FishingHostShell
        {
            ViewModel = CreateGalleryViewModel(),
            SnapsToDevicePixels = true,
            UseLayoutRounding = true,
        };
        var pageNavigation = Pages.ToDictionary(page => page.Id, page => page.Navigate, StringComparer.Ordinal);
        var manifestEntries = new List<object>(Definitions.Count);

        foreach (var definition in Definitions)
        {
            FrameworkElement surface;
            if (definition.PageId == "startup")
            {
                surface = CreateStartupSurface(definition.VariantId);
                Arrange(surface, new Size(definition.WidthDip, definition.HeightDip));
            }
            else
            {
                pageNavigation[definition.PageId](shell.ViewModel);
                Arrange(shell, new Size(definition.WidthDip, definition.HeightDip));
                PrepareVariant(shell, definition);
                surface = shell;
            }
            VisibleCopyAudit.AssertSurface(
                surface,
                $"gallery/{definition.PageId}/{definition.VariantId}/" +
                $"{definition.LayoutId}/{definition.DpiPercent}");
            var pngBytes = RenderPng(surface, definition);
            var variantSuffix = definition.VariantId == "top"
                ? string.Empty
                : $"-{definition.VariantId}";
            var fileName = $"{definition.PageId}{variantSuffix}-{definition.LayoutId}-{definition.DpiPercent}dpi.png";
            var imagePath = Path.Combine(fullOutputDirectory, fileName);
            File.WriteAllBytes(imagePath, pngBytes);
            manifestEntries.Add(new
            {
                definition.PageId,
                definition.VariantId,
                definition.LayoutId,
                definition.WidthDip,
                definition.HeightDip,
                definition.DpiPercent,
                PixelWidth = ToPixels(definition.WidthDip, definition.DpiPercent),
                PixelHeight = ToPixels(definition.HeightDip, definition.DpiPercent),
                FileName = fileName,
                Sha256 = Convert.ToHexString(SHA256.HashData(pngBytes)),
            });
        }

        var manifest = new
        {
            SchemaVersion = 1,
            Product = "fishing",
            Renderer = "wpf-offscreen",
            CommonUiVersion,
            Images = manifestEntries,
        };
        File.WriteAllText(
            Path.Combine(fullOutputDirectory, "gallery-manifest.json"),
            JsonSerializer.Serialize(manifest, new JsonSerializerOptions { WriteIndented = true }));

        return new UiGalleryRenderResult(fullOutputDirectory, Definitions.Count);
    }

    private static byte[] RenderPng(
        FrameworkElement element,
        UiGalleryRenderDefinition definition)
    {
        var dpi = 96.0 * definition.DpiPercent / 100.0;
        var bitmap = new RenderTargetBitmap(
            ToPixels(definition.WidthDip, definition.DpiPercent),
            ToPixels(definition.HeightDip, definition.DpiPercent),
            dpi,
            dpi,
            PixelFormats.Pbgra32);
        bitmap.Render(element);
        bitmap.Freeze();

        var encoder = new PngBitmapEncoder();
        encoder.Frames.Add(BitmapFrame.Create(bitmap));
        using var stream = new MemoryStream();
        encoder.Save(stream);
        return stream.ToArray();
    }

    private static int ToPixels(double dip, int dpiPercent) =>
        checked((int)Math.Round(dip * dpiPercent / 100.0, MidpointRounding.AwayFromZero));

    private static FishingSessionStateSnapshot CreateStatisticsPreview() => new(
        revision: 17,
        running: true,
        stopping: false,
        detectedStage: "catch",
        totals: new FishingSessionTotalsSnapshot(
            DurationSeconds: 5412,
            CaughtCount: 8,
            CaughtKg: 18.4,
            ReleasedCount: 3,
            ReleasedKg: 5.2,
            EarnedMin: 10747.2,
            EarnedMax: 11087.2),
        tackleItems: [],
        acceptedSettingsRevision: 7,
        fishRows:
        [
            new FishingSessionFishRowSnapshot(
                "marlin", "Марлин", 3, 9.8, 1, 2.6, 2, 7.2,
                new FishingPriceSnapshot(0.67, 0.73, 670, 730),
                701, 5047.2, 5047.2),
            new FishingSessionFishRowSnapshot(
                "ruster", "Рустер", 3, 5.4, 1, 1.4, 2, 4.0,
                new FishingPriceSnapshot(1.05, 1.12, 1050, 1120),
                null, 4200, 4480),
            new FishingSessionFishRowSnapshot(
                "tarpon", "Тарпон", 2, 3.2, 1, 1.2, 1, 2.0,
                new FishingPriceSnapshot(0.75, 0.78, 750, 780),
                null, 1500, 1560),
        ],
        catchSizes:
        [
            new FishingCatchSizeSnapshot("small", "Малый улов", 2, 25),
            new FishingCatchSizeSnapshot("good", "Хороший улов", 3, 37.5),
            new FishingCatchSizeSnapshot("large", "Крупный улов", 2, 25),
            new FishingCatchSizeSnapshot("record", "Рекордный улов", 1, 12.5),
        ]);

    internal static FishingHostShellViewModel CreateGalleryViewModel()
    {
        var state = FishingHostState.Default;
        var session = CreateFishingPreview();
        const string galleryTelegramToken = "gallery-placeholder";
        var galleryTelegram = new TelegramHostSettings(
            enabled: true,
            adminIds: [100001],
            state.Telegram.InventorySpaceLowThresholdKg,
            state.Telegram.Notifications,
            state.Telegram.Sounds);
        var recentEvents = new RecentEventBuffer();
        recentEvents.Append(new FishingEventSnapshot(
            Sequence: 1,
            OccurredAt: new DateTimeOffset(2026, 8, 22, 12, 8, 0, TimeSpan.FromHours(3)),
            Tone: FishingEventTone.Success,
            IconResourceKey: "fish/marlin",
            Message: "Пойман марлин",
            Detail: "4.8 кг · оставлен"));
        recentEvents.Append(new FishingEventSnapshot(
            Sequence: 2,
            OccurredAt: new DateTimeOffset(2026, 8, 22, 12, 14, 0, TimeSpan.FromHours(3)),
            Tone: FishingEventTone.Neutral,
            IconResourceKey: "event.session",
            Message: "Снаряжение обновлено",
            Detail: "Новая наживка готова"));
        var overview = new OverviewPageViewModel(galleryTelegram, recentEvents);
        overview.ApplySessionState(session);

        var fishing = FishingPageViewModel.CreateProduction(
            new GalleryAutomationRuntime(session));
        fishing.ApplySessionState(session);

        var settings = new FishingSettingsPageViewModel(state.Fishing, _ => { });
        settings.StartStopSoundEnabled = !settings.StartStopSoundEnabled;

        var streamingController = new GalleryStreamingController();
        var streaming = new StreamingPageViewModel(
            streamingController,
            featureAllowed: true,
            chatFeatureAllowed: true,
            _ => { });
        overview.ApplyStreamingSnapshot(streamingController.Current);

        var telegram = new TelegramSettingsPageViewModel(
            galleryTelegram,
            galleryTelegramToken,
            featureAllowed: true,
            TelegramAvailability.Available(galleryTelegramToken, galleryTelegram.AdminIds),
            _ => { });
        telegram.NotifyCatch = !telegram.NotifyCatch;

        return new FishingHostShellViewModel(
            overview,
            new LicensePageViewModel(
                state.License,
                (_, _) => Task.FromResult(FishingLicenseActivationResult.Reject(
                    "Не удалось подтвердить лицензию. Проверьте ключ и повторите."))),
            fishing,
            new InventoryPageViewModel(CreateInventoryPreview()),
            settings,
            new StatisticsPageViewModel(
                session,
                (_, _) => { },
                () => FishingSessionStateSnapshot.Empty),
            streaming,
            telegram,
            new AboutPageViewModel(() => { }),
            EngineHealthViewModel.CreateProduction(new GalleryEngineHealthUseCase()),
            FishingProductPageCatalog.All
                .Where(page => page.RequiredFeature is not null)
                .Select(page => page.RequiredFeature!)
                .ToHashSet(StringComparer.Ordinal),
            FishingHostPage.Overview);
    }

    private static InventoryProductState CreateInventoryPreview() => new(
        Ready: true,
        Reason: "ready",
        Revision: 4,
        ObservedAtMilliseconds: 1,
        OpenKnown: true,
        Open: true,
        CurrentWeight: 1.24,
        MaximumWeight: 40,
        Items:
        [
            new InventoryItemState(
                RuntimeId: "gallery-meat",
                CatalogItemId: 240,
                Name: "Мясо оленя",
                Category: "Еда",
                Column: 0,
                Row: 0,
                ColumnSpan: 2,
                RowSpan: 2,
                Count: 2,
                MaximumCount: 10000,
                UnitWeight: 0.5,
                TotalWeight: 1,
                ConditionPercent: null,
                FreshnessPercent: 88,
                ConditionKind: InventoryConditionKind.Food,
                Durability: string.Empty,
                Description: "Мясо после охоты.",
                ImageReference: string.Empty,
                DetailLines: Array.Empty<string>()),
            new InventoryItemState(
                RuntimeId: "gallery-knife",
                CatalogItemId: 246,
                Name: "Нож",
                Category: "Инструменты",
                Column: 2,
                Row: 0,
                ColumnSpan: 1,
                RowSpan: 3,
                Count: 1,
                MaximumCount: 1,
                UnitWeight: 0.18,
                TotalWeight: 0.18,
                ConditionPercent: 75,
                FreshnessPercent: null,
                ConditionKind: InventoryConditionKind.Wear,
                Durability: "Хорошая",
                Description: "Охотничий нож.",
                ImageReference: string.Empty,
                DetailLines: Array.Empty<string>()),
        ]);

    private static FishingSessionStateSnapshot CreateFishingPreview() => new(
        revision: 18,
        running: false,
        stopping: false,
        detectedStage: string.Empty,
        totals: new FishingSessionTotalsSnapshot(
            DurationSeconds: 3720,
            CaughtCount: 12,
            CaughtKg: 24.6,
            ReleasedCount: 4,
            ReleasedKg: 7.2,
            EarnedMin: 15400,
            EarnedMax: 16600),
        tackleItems:
        [
            new FishingTackleItemSnapshot("rod", "Удочка", 1),
            new FishingTackleItemSnapshot("reel", "Катушка", 1),
            new FishingTackleItemSnapshot("line", "Леска", 2),
            new FishingTackleItemSnapshot("leaders", "Крючки и поводки", 7),
            new FishingTackleItemSnapshot("bait", "Наживка и блёсны", 18),
            new FishingTackleItemSnapshot("net", "Подсак", 1),
        ],
        acceptedSettingsRevision: 7);

    private static StartupAdmissionScreen CreateStartupSurface(string variant)
    {
        var viewModel = new StartupAdmissionViewModel(_ => { }, () => { });
        switch (variant)
        {
            case "checking":
                break;
            case "blocked":
                viewModel.Apply(new StartupAdmissionDecision(
                    StartupAdmissionKind.Blocked,
                    "https://m-sonar-addr.ru/download",
                    "startup_blocked"));
                break;
            case "unavailable":
                viewModel.Apply(new StartupAdmissionDecision(
                    StartupAdmissionKind.Unavailable,
                    string.Empty,
                    "startup_block_http_unavailable"));
                break;
            default:
                throw new InvalidOperationException($"Unknown startup gallery variant: {variant}");
        }
        return new StartupAdmissionScreen
        {
            ViewModel = viewModel,
            SnapsToDevicePixels = true,
            UseLayoutRounding = true,
        };
    }

    private static void Arrange(FrameworkElement element, Size size)
    {
        element.Measure(size);
        element.Arrange(new Rect(new Point(0, 0), size));
        element.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
        element.UpdateLayout();
        element.Dispatcher.Invoke(() => { }, DispatcherPriority.Render);
    }

    private static void PrepareVariant(
        FishingHostShell shell,
        UiGalleryRenderDefinition definition)
    {
        if (definition.VariantId == "top")
        {
            return;
        }
        if (definition is { PageId: "fishing", VariantId: "session" })
        {
            var fishing = WpfTestVisualTree.FindDescendant<Sonar.Fishing.Host.FishingPage.FishingPage>(
                shell,
                "Fishing page is missing while rendering the session variant");
            var fishingScroller = fishing.FindName("FishingPageScrollViewer") as ScrollViewer
                ?? throw new InvalidOperationException("Fishing page scroll viewer is missing");
            var summary = fishing.FindName("FishingSessionSummaryScreen") as FrameworkElement
                ?? throw new InvalidOperationException("Fishing session summary is missing");
            summary.BringIntoView(new Rect(
                0,
                0,
                summary.ActualWidth,
                Math.Min(summary.ActualHeight, fishingScroller.ViewportHeight)));
            shell.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
            shell.UpdateLayout();
            shell.Dispatcher.Invoke(() => { }, DispatcherPriority.Render);
            return;
        }
        if (definition is { PageId: "settings", VariantId: "thresholds" })
        {
            var thresholdSettings = WpfTestVisualTree.FindDescendant<SettingsScreen>(
                shell,
                "Settings page is missing while rendering the thresholds variant");
            var thresholdScroller = thresholdSettings.FindName("SettingsPageScrollViewer") as ScrollViewer
                ?? throw new InvalidOperationException("Settings page scroll viewer is missing");
            var thresholdsSection = thresholdSettings.FindName("ThresholdsSection") as FrameworkElement
                ?? throw new InvalidOperationException("Thresholds section is missing");
            thresholdsSection.BringIntoView(new Rect(
                0,
                0,
                thresholdsSection.ActualWidth,
                Math.Min(thresholdsSection.ActualHeight, thresholdScroller.ViewportHeight)));
            shell.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
            shell.UpdateLayout();
            shell.Dispatcher.Invoke(() => { }, DispatcherPriority.Render);
            return;
        }
        if (definition is { PageId: "settings", VariantId: "hotkey-conflict" })
        {
            ((FishingSettingsPageViewModel)shell.ViewModel.CurrentPage).InventoryShortcut =
                ((FishingSettingsPageViewModel)shell.ViewModel.CurrentPage).StartStopShortcut;
            var conflictSettings = WpfTestVisualTree.FindDescendant<SettingsScreen>(
                shell,
                "Settings page is missing while rendering the hotkey-conflict variant");
            var conflictScroller = conflictSettings.FindName("SettingsPageScrollViewer") as ScrollViewer
                ?? throw new InvalidOperationException("Settings page scroll viewer is missing");
            var hotkeysSection = conflictSettings.FindName("HotkeysSection") as FrameworkElement
                ?? throw new InvalidOperationException("Hotkeys section is missing");
            hotkeysSection.BringIntoView(new Rect(
                0,
                0,
                hotkeysSection.ActualWidth,
                Math.Min(hotkeysSection.ActualHeight, conflictScroller.ViewportHeight)));
            shell.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
            shell.UpdateLayout();
            shell.Dispatcher.Invoke(() => { }, DispatcherPriority.Render);
            return;
        }
        if (definition is not { PageId: "settings", VariantId: "fish-selection" })
        {
            throw new InvalidOperationException(
                $"Unknown UI gallery variant: {definition.PageId}/{definition.VariantId}");
        }

        var settings = WpfTestVisualTree.FindDescendant<SettingsScreen>(
            shell,
            "Settings page is missing while rendering the fish-selection variant");
        var scroller = settings.FindName("SettingsPageScrollViewer") as ScrollViewer
            ?? throw new InvalidOperationException("Settings page scroll viewer is missing");
        var fishScroller = settings.FindName("FishSelectionScrollViewer") as ScrollViewer
            ?? throw new InvalidOperationException("Fish-selection scroll viewer is missing");
        var fishSection = settings.FindName("FishSelectionSection") as FrameworkElement
            ?? throw new InvalidOperationException("Fish-selection section is missing");
        fishScroller.ScrollToTop();
        fishSection.BringIntoView(new Rect(
            0,
            0,
            fishSection.ActualWidth,
            Math.Min(fishSection.ActualHeight, scroller.ViewportHeight)));
        shell.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
        shell.UpdateLayout();
        shell.Dispatcher.Invoke(() => { }, DispatcherPriority.Render);
    }

    private sealed class GalleryAutomationRuntime(
        FishingSessionStateSnapshot snapshot) : IFishingAutomationRuntime
    {
        public bool HasActiveEntitlement => true;

        public Task<FishingSessionStateSnapshot> StartAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            return Task.FromResult(snapshot);
        }

        public Task<FishingSessionStateSnapshot> StopAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            return Task.FromResult(snapshot);
        }
    }

    private sealed class GalleryEngineHealthUseCase : IEngineHealthUseCase
    {
        public Task<EngineHealthResult> RunAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            return Task.FromResult(new EngineHealthResult(
                VerifiedEngineProcessId: 1,
                ProcessContainmentVerified: true,
                NegotiatedProtocolMinor: 0,
                SideEffectsEnabled: false,
                ProductionAuthority: "native-cpp-engine",
                SessionState: FishingSessionStateSnapshot.Empty));
        }
    }

    private sealed class GalleryStreamingController : IStreamingController
    {
        public StreamingRuntimeSnapshot Current { get; } =
            StreamingRuntimeSnapshot.Offline(snapshotModeEnabled: false);

        public event Action<StreamingRuntimeSnapshot>? SnapshotChanged
        {
            add { }
            remove { }
        }

        public StreamingCommandResult Start() => Reject();

        public StreamingCommandResult Stop(string reason)
        {
            ArgumentException.ThrowIfNullOrWhiteSpace(reason);
            return Reject();
        }

        public StreamingCommandResult SetQuality(string quality)
        {
            _ = StreamingQualityCatalog.Require(quality);
            return Reject();
        }

        public StreamingCommandResult SetChatZoom(bool enabled) => Reject();

        public StreamingCommandResult SetSnapshotMode(bool enabled) => Reject();

        public StreamingCommandResult SetChatMode(bool enabled) => Reject();

        private StreamingCommandResult Reject() => new(
            Accepted: false,
            Reason: "gallery_read_only",
            Current);
    }
}
