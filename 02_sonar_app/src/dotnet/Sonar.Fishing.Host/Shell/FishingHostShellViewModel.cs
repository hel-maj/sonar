using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Sonar.Fishing.Host.AboutPage;
using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.LicensePage;
using Sonar.Fishing.Host.Overview;
using Sonar.Fishing.Host.ProductNavigation;
using Sonar.Fishing.Host.SettingsPage;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StatisticsPage;
using Sonar.Fishing.Host.StreamingPage;
using Sonar.Fishing.Host.TelegramPage;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.Shell;

public enum FishingHostPage
{
    Overview,
    License,
    Fishing,
    Settings,
    Statistics,
    Streaming,
    Telegram,
    About,
    EngineHealth,
}

public sealed class FishingHostShellViewModel : ObservableObject
{
    private readonly HashSet<string> allowedFeatures;
    private readonly IReadOnlyDictionary<FishingHostPage, object> pages;
    private FishingHostPage selectedPage;
    private object currentPage;

    public FishingHostShellViewModel(
        OverviewPageViewModel overviewPage,
        LicensePageViewModel licensePage,
        FishingPageViewModel fishingPage,
        FishingSettingsPageViewModel settingsPage,
        StatisticsPageViewModel statisticsPage,
        StreamingPageViewModel streamingPage,
        TelegramSettingsPageViewModel telegramPage,
        AboutPageViewModel aboutPage,
        EngineHealthViewModel engineHealthPage,
        IReadOnlySet<string> allowedFeatures,
        FishingHostPage initialPage)
    {
        ArgumentNullException.ThrowIfNull(overviewPage);
        ArgumentNullException.ThrowIfNull(licensePage);
        ArgumentNullException.ThrowIfNull(fishingPage);
        ArgumentNullException.ThrowIfNull(settingsPage);
        ArgumentNullException.ThrowIfNull(statisticsPage);
        ArgumentNullException.ThrowIfNull(streamingPage);
        ArgumentNullException.ThrowIfNull(telegramPage);
        ArgumentNullException.ThrowIfNull(aboutPage);
        ArgumentNullException.ThrowIfNull(engineHealthPage);
        ArgumentNullException.ThrowIfNull(allowedFeatures);

        this.allowedFeatures = new HashSet<string>(allowedFeatures, StringComparer.Ordinal);
        pages = new Dictionary<FishingHostPage, object>
        {
            [FishingHostPage.Overview] = overviewPage,
            [FishingHostPage.License] = licensePage,
            [FishingHostPage.Fishing] = fishingPage,
            [FishingHostPage.Settings] = settingsPage,
            [FishingHostPage.Statistics] = statisticsPage,
            [FishingHostPage.Streaming] = streamingPage,
            [FishingHostPage.Telegram] = telegramPage,
            [FishingHostPage.About] = aboutPage,
            [FishingHostPage.EngineHealth] = engineHealthPage,
        };
        selectedPage = ResolveAllowed(initialPage);
        currentPage = ResolvePage(selectedPage);

        ShowOverviewCommand = CreateNavigationCommand(FishingHostPage.Overview);
        ShowLicenseCommand = CreateNavigationCommand(FishingHostPage.License);
        ShowFishingCommand = CreateNavigationCommand(FishingHostPage.Fishing);
        ShowSettingsCommand = CreateNavigationCommand(FishingHostPage.Settings);
        ShowStatisticsCommand = CreateNavigationCommand(FishingHostPage.Statistics);
        ShowStreamingCommand = CreateNavigationCommand(FishingHostPage.Streaming);
        ShowTelegramCommand = CreateNavigationCommand(FishingHostPage.Telegram);
        ShowAboutCommand = CreateNavigationCommand(FishingHostPage.About);
        ShowEngineHealthCommand = CreateNavigationCommand(FishingHostPage.EngineHealth);
    }

    public static FishingHostShellViewModel CreatePreview()
    {
        var state = FishingHostState.Default;
        var health = EngineHealthViewModel.CreateDemo();
        var overview = new OverviewPageViewModel(state.Telegram);
        overview.ApplySessionState(FishingSessionStateSnapshot.Empty);
        return new FishingHostShellViewModel(
            overview,
            new LicensePageViewModel(state.License),
            FishingPageViewModel.MigrationPreview,
            new FishingSettingsPageViewModel(state.Fishing),
            new StatisticsPageViewModel(FishingSessionStateSnapshot.Empty),
            new StreamingPageViewModel(),
            new TelegramSettingsPageViewModel(
                state.Telegram,
                state.Secrets.TelegramBotToken,
                featureAllowed: true),
            new AboutPageViewModel(),
            health,
            FishingProductPageCatalog.All
                .Where(page => page.RequiredFeature is not null)
                .Select(page => page.RequiredFeature!)
                .ToHashSet(StringComparer.Ordinal),
            FishingHostPage.License);
    }

    public string ModeText => ((EngineHealthViewModel)pages[FishingHostPage.EngineHealth]).ModeLabel;

    public SemanticTone ModeTone => SemanticTone.Neutral;

    public string VersionText
    {
        get
        {
            var version = typeof(FishingHostShellViewModel).Assembly.GetName().Version;
            return $"Версия {version?.ToString(3) ?? "не указана"}";
        }
    }

    public FishingHostPage SelectedPage
    {
        get => selectedPage;
        private set => SetProperty(ref selectedPage, value);
    }

    public object CurrentPage
    {
        get => currentPage;
        private set => SetProperty(ref currentPage, value);
    }

    public bool IsOverviewSelected => SelectedPage == FishingHostPage.Overview;

    public bool IsLicenseSelected => SelectedPage == FishingHostPage.License;

    public bool IsFishingSelected => SelectedPage == FishingHostPage.Fishing;

    public bool IsSettingsSelected => SelectedPage == FishingHostPage.Settings;

    public bool IsStatisticsSelected => SelectedPage == FishingHostPage.Statistics;

    public bool IsStreamingSelected => SelectedPage == FishingHostPage.Streaming;

    public bool IsTelegramSelected => SelectedPage == FishingHostPage.Telegram;

    public bool IsAboutSelected => SelectedPage == FishingHostPage.About;

    public bool IsEngineHealthSelected => SelectedPage == FishingHostPage.EngineHealth;

    public IRelayCommand ShowOverviewCommand { get; }

    public IRelayCommand ShowLicenseCommand { get; }

    public IRelayCommand ShowFishingCommand { get; }

    public IRelayCommand ShowSettingsCommand { get; }

    public IRelayCommand ShowStatisticsCommand { get; }

    public IRelayCommand ShowStreamingCommand { get; }

    public IRelayCommand ShowTelegramCommand { get; }

    public IRelayCommand ShowAboutCommand { get; }

    public IRelayCommand ShowEngineHealthCommand { get; }

    internal void ApplyAllowedFeatures(IEnumerable<string> features)
    {
        ArgumentNullException.ThrowIfNull(features);
        allowedFeatures.Clear();
        allowedFeatures.UnionWith(features);
        var resolved = ResolveAllowed(SelectedPage);
        if (resolved == SelectedPage)
        {
            return;
        }
        SelectedPage = resolved;
        CurrentPage = ResolvePage(resolved);
        RaiseSelectionChanged();
    }

    private IRelayCommand CreateNavigationCommand(FishingHostPage page) =>
        new RelayCommand(() => SelectPage(page));

    private void SelectPage(FishingHostPage requested)
    {
        var page = ResolveAllowed(requested);
        if (SelectedPage == page)
        {
            return;
        }

        SelectedPage = page;
        CurrentPage = ResolvePage(page);
        RaiseSelectionChanged();
    }

    private FishingHostPage ResolveAllowed(FishingHostPage requested)
    {
        if (requested == FishingHostPage.EngineHealth)
        {
            return requested;
        }
        var productPage = ToProductPage(requested);
        return FromProductPage(FishingProductPageCatalog.ResolveAllowed(productPage, allowedFeatures));
    }

    private object ResolvePage(FishingHostPage page) => pages.TryGetValue(page, out var value)
        ? value
        : throw new ArgumentOutOfRangeException(nameof(page));

    private void RaiseSelectionChanged()
    {
        OnPropertyChanged(nameof(IsOverviewSelected));
        OnPropertyChanged(nameof(IsLicenseSelected));
        OnPropertyChanged(nameof(IsFishingSelected));
        OnPropertyChanged(nameof(IsSettingsSelected));
        OnPropertyChanged(nameof(IsStatisticsSelected));
        OnPropertyChanged(nameof(IsStreamingSelected));
        OnPropertyChanged(nameof(IsTelegramSelected));
        OnPropertyChanged(nameof(IsAboutSelected));
        OnPropertyChanged(nameof(IsEngineHealthSelected));
    }

    private static FishingProductPageId ToProductPage(FishingHostPage page) => page switch
    {
        FishingHostPage.Overview => FishingProductPageId.Overview,
        FishingHostPage.License => FishingProductPageId.License,
        FishingHostPage.Fishing => FishingProductPageId.Fishing,
        FishingHostPage.Settings => FishingProductPageId.Settings,
        FishingHostPage.Statistics => FishingProductPageId.Statistics,
        FishingHostPage.Streaming => FishingProductPageId.Streaming,
        FishingHostPage.Telegram => FishingProductPageId.Telegram,
        FishingHostPage.About => FishingProductPageId.About,
        _ => throw new ArgumentOutOfRangeException(nameof(page)),
    };

    private static FishingHostPage FromProductPage(FishingProductPageId page) => page switch
    {
        FishingProductPageId.Overview => FishingHostPage.Overview,
        FishingProductPageId.License => FishingHostPage.License,
        FishingProductPageId.Fishing => FishingHostPage.Fishing,
        FishingProductPageId.Settings => FishingHostPage.Settings,
        FishingProductPageId.Statistics => FishingHostPage.Statistics,
        FishingProductPageId.Streaming => FishingHostPage.Streaming,
        FishingProductPageId.Telegram => FishingHostPage.Telegram,
        FishingProductPageId.About => FishingHostPage.About,
        _ => throw new ArgumentOutOfRangeException(nameof(page)),
    };
}
