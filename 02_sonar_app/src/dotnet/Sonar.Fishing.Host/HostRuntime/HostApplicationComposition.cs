using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.LicensePage;
using Sonar.Fishing.Host.Overview;
using Sonar.Fishing.Host.SettingsPage;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.Shell;
using Sonar.Fishing.Host.StatisticsPage;
using Sonar.Fishing.Host.StreamingPage;
using Sonar.Fishing.Host.TelegramPage;
using Sonar.Fishing.Host.AboutPage;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.HostHotkeys;

namespace Sonar.Fishing.Host.HostRuntime;

public sealed record HostApplicationComposition(
    FishingHostShellViewModel Shell,
    HostLifecycleCoordinator Lifecycle,
    FishingHostState State)
{
    public static HostApplicationComposition Create(
        HostRunOptions options,
        FishingHostState state,
        Action? clearDiagnostics = null) =>
        CreateCore(options, state, coordinator: null, clearDiagnostics: clearDiagnostics);

    public static HostApplicationComposition Create(
        HostRunOptions options,
        HostStateCoordinator coordinator,
        Action? clearDiagnostics = null) =>
        Create(options, coordinator, clearDiagnostics, activateLicense: null);

    internal static HostApplicationComposition Create(
        HostRunOptions options,
        HostStateCoordinator coordinator,
        Action? clearDiagnostics,
        Func<string, CancellationToken, Task<FishingLicenseActivationResult>>? activateLicense = null)
    {
        ArgumentNullException.ThrowIfNull(coordinator);
        return CreateCore(
            options,
            coordinator.Current,
            coordinator,
            clearDiagnostics,
            activateLicense);
    }

    internal static HostApplicationComposition CreateProduction(
        HostStateCoordinator coordinator,
        IEngineHealthUseCase engineHealthUseCase,
        IFishingAutomationRuntime automationRuntime,
        ILicenseRuntimeLifecycle licenseRuntime,
        IHostHotkeyRuntimeLifecycle hotkeyRuntime,
        Func<string, CancellationToken, Task<FishingLicenseActivationResult>> activateLicense,
        Action? clearDiagnostics = null)
    {
        ArgumentNullException.ThrowIfNull(coordinator);
        ArgumentNullException.ThrowIfNull(engineHealthUseCase);
        ArgumentNullException.ThrowIfNull(automationRuntime);
        ArgumentNullException.ThrowIfNull(licenseRuntime);
        ArgumentNullException.ThrowIfNull(hotkeyRuntime);
        ArgumentNullException.ThrowIfNull(activateLicense);
        return CreateCore(
            new HostRunOptions(HostRunMode.Production, null),
            coordinator.Current,
            coordinator,
            clearDiagnostics,
            activateLicense,
            engineHealthUseCase,
            licenseRuntime,
            automationRuntime,
            hotkeyRuntime);
    }

    private static HostApplicationComposition CreateCore(
        HostRunOptions options,
        FishingHostState state,
        HostStateCoordinator? coordinator,
        Action? clearDiagnostics,
        Func<string, CancellationToken, Task<FishingLicenseActivationResult>>? activateLicense = null,
        IEngineHealthUseCase? productionEngineHealth = null,
        ILicenseRuntimeLifecycle? licenseRuntime = null,
        IFishingAutomationRuntime? automationRuntime = null,
        IHostHotkeyRuntimeLifecycle? hotkeyRuntime = null)
    {
        ArgumentNullException.ThrowIfNull(options);
        ArgumentNullException.ThrowIfNull(state);
        state.Validate();

        var fishingPage = options.Mode switch
        {
            HostRunMode.Production => FishingPageViewModel.CreateProduction(
                automationRuntime ?? throw new InvalidOperationException(
                    "production_automation_runtime_missing")),
            HostRunMode.Demo => FishingPageViewModel.MigrationPreview,
            HostRunMode.OfflineEngine => FishingPageViewModel.CreateOfflineEngine(),
            _ => throw new ArgumentOutOfRangeException(nameof(options)),
        };
        var streamingController = new UnavailableStreamingController(
            state.Fishing.Behavior.StreamSnapshotMode);
        var overviewPage = new OverviewPageViewModel(state.Telegram);
        overviewPage.ApplyStreamingSnapshot(streamingController.Current);
        streamingController.SnapshotChanged += overviewPage.ApplyStreamingSnapshot;
        Action<string, double?>? persistCustomPrice = coordinator is null
            ? null
            : (fishId, price) =>
                coordinator.UpdateCustomFishPrice(fishId, price);
        var statisticsPage = new StatisticsPageViewModel(
            FishingSessionStateSnapshot.Empty,
            persistCustomPrice);
        overviewPage.ApplySessionState(FishingSessionStateSnapshot.Empty);
        void ApplySessionState(FishingSessionStateSnapshot snapshot)
        {
            fishingPage.ApplySessionState(snapshot);
            overviewPage.ApplySessionState(snapshot);
            statisticsPage.ApplySessionState(snapshot);
        }
        fishingPage.SessionStateChanged += snapshot =>
        {
            overviewPage.ApplySessionState(snapshot);
            statisticsPage.ApplySessionState(snapshot);
        };
        var engineHealth = options.Mode switch
        {
            HostRunMode.Production => EngineHealthViewModel.CreateProduction(
                productionEngineHealth ?? throw new InvalidOperationException(
                    "production_engine_health_missing"),
                ApplySessionState),
            HostRunMode.Demo => EngineHealthViewModel.CreateDemo(),
            HostRunMode.OfflineEngine => EngineHealthViewModel.CreateOffline(
                new OfflineEngineHealthUseCase(
                    RequireEngineExecutable(options),
                    TimeSpan.FromSeconds(10),
                    state.Fishing),
                ApplySessionState),
            _ => throw new ArgumentOutOfRangeException(nameof(options)),
        };
        var initialPage = options.Mode == HostRunMode.OfflineEngine
            ? FishingHostPage.EngineHealth
            : FishingHostPage.License;
        var allowedFeatures = state.License.Features.ToHashSet(StringComparer.Ordinal);
        var telegramFeatureAllowed = allowedFeatures.Contains("telegram");
        Action<FishingRuntimeSettings>? saveFishing = coordinator is null
            ? null
            : coordinator.SaveFishing;
        var settingsPage = new FishingSettingsPageViewModel(
            state.Fishing,
            saveFishing);
        if (coordinator is not null)
        {
            coordinator.StateChanged += updated =>
                settingsPage.ApplyExternalSettings(updated.Fishing);
        }
        TelegramHostSettings ReadTelegramSettings() =>
            coordinator?.Current.Telegram ?? state.Telegram;
        Task SaveTelegramSettingsAsync(
            TelegramHostSettings settings,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            if (coordinator is null)
            {
                throw new InvalidOperationException("telegram_settings_store_unavailable");
            }
            coordinator.SaveTelegram(
                settings,
                coordinator.Current.Secrets.TelegramBotToken);
            return Task.CompletedTask;
        }
        ITelegramProductUseCases telegramProduct = options.Mode == HostRunMode.Production
            ? new FishingTelegramProductUseCases(
                automationRuntime ?? throw new InvalidOperationException(
                    "production_automation_runtime_missing"),
                () => coordinator?.Current ?? state)
            : new UnavailableTelegramProductUseCases();
        var telegramNetwork = new TelegramNetworkRunner(
            ReadTelegramSettings,
            SaveTelegramSettingsAsync,
            telegramProduct,
            streamingController);
        TelegramRuntimeConfiguration TelegramConfiguration(FishingHostState source) => new(
            networkAllowed: options.Mode == HostRunMode.Production,
            featureAllowed: source.License.Features.Contains("telegram", StringComparer.Ordinal),
            source.Telegram,
            source.Secrets.TelegramBotToken);
        var telegramRuntime = new TelegramRuntimeCoordinator(
            TelegramConfiguration(state),
            telegramNetwork.RunAsync);
        if (coordinator is not null)
        {
            coordinator.StateChanged += updated =>
                telegramRuntime.ApplyConfiguration(TelegramConfiguration(updated));
        }
        var licensePage = new LicensePageViewModel(state.License, activateLicense);
        var shell = new FishingHostShellViewModel(
            overviewPage,
            licensePage,
            fishingPage,
            settingsPage,
            statisticsPage,
            new StreamingPageViewModel(
                streamingController,
                featureAllowed: allowedFeatures.Contains("stream"),
                chatFeatureAllowed: allowedFeatures.Contains("stream_chat"),
                persistSnapshotMode: coordinator is null
                    ? null
                    : enabled => coordinator.UpdateStreamSnapshotMode(enabled)),
            new TelegramSettingsPageViewModel(
                state.Telegram,
                state.Secrets.TelegramBotToken,
                telegramFeatureAllowed,
                saveHandler: coordinator is null
                    ? null
                    : result => coordinator.SaveTelegram(result.Settings, result.BotToken)),
            new AboutPageViewModel(clearDiagnostics),
            engineHealth,
            allowedFeatures,
            initialPage);

        if (coordinator is not null)
        {
            coordinator.StateChanged += updated =>
            {
                licensePage.ApplyExternalSettings(updated.License);
                shell.ApplyAllowedFeatures(updated.License.Features);
                fishingPage.RefreshCommandAuthority();
            };
        }

        return new HostApplicationComposition(
            shell,
            new HostLifecycleCoordinator(
                engineHealth,
                telegramRuntime,
                licenseRuntime,
                hotkeyRuntime),
            state);
    }

    private static string RequireEngineExecutable(HostRunOptions options) =>
        string.IsNullOrWhiteSpace(options.EngineExecutable)
            ? throw new HostRunOptionsException(
                "Не удалось открыть выбранный режим. Запустите Sonar Fishing " +
                "обычным способом.")
            : options.EngineExecutable;
}
