using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.EngineIntegration.Notifications;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.LicensePage;
using Sonar.Fishing.Host.Overview;
using Sonar.Fishing.Host.SettingsPage;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.Shell;
using Sonar.Fishing.Host.StatisticsPage;
using Sonar.Fishing.Host.StreamingPage;
using Sonar.Fishing.Host.StreamingRuntime;
using Sonar.Fishing.Host.TelegramPage;
using Sonar.Fishing.Host.AboutPage;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.HostHotkeys;
using Sonar.Fishing.Host.InventoryPage;
using Sonar.Fishing.Host.EngineIntegration.Inventory;

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
        IFishingSessionStatisticsRuntime statisticsRuntime,
        IFishingEngineNotificationSource engineNotifications,
        IFishingInventorySnapshotSource inventorySnapshots,
        ILicenseRuntimeLifecycle licenseRuntime,
        IHostHotkeyRuntimeLifecycle hotkeyRuntime,
        Func<string, CancellationToken, Task<FishingLicenseActivationResult>>? activateLicense,
        Action? clearDiagnostics = null,
        HostRunMode runMode = HostRunMode.Production,
        LicenseHostSettings? licenseOverride = null)
    {
        ArgumentNullException.ThrowIfNull(coordinator);
        ArgumentNullException.ThrowIfNull(engineHealthUseCase);
        ArgumentNullException.ThrowIfNull(automationRuntime);
        ArgumentNullException.ThrowIfNull(statisticsRuntime);
        ArgumentNullException.ThrowIfNull(engineNotifications);
        ArgumentNullException.ThrowIfNull(inventorySnapshots);
        ArgumentNullException.ThrowIfNull(licenseRuntime);
        ArgumentNullException.ThrowIfNull(hotkeyRuntime);
        if (runMode is not (HostRunMode.Production or
            HostRunMode.DeveloperFullAccess))
        {
            throw new ArgumentOutOfRangeException(nameof(runMode));
        }
        return CreateCore(
            new HostRunOptions(runMode, null),
            coordinator.Current,
            coordinator,
            clearDiagnostics,
            activateLicense,
            engineHealthUseCase,
            licenseRuntime,
            automationRuntime,
            statisticsRuntime,
            hotkeyRuntime,
            licenseOverride,
            engineNotifications,
            inventorySnapshots);
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
        IFishingSessionStatisticsRuntime? statisticsRuntime = null,
        IHostHotkeyRuntimeLifecycle? hotkeyRuntime = null,
        LicenseHostSettings? licenseOverride = null,
        IFishingEngineNotificationSource? engineNotifications = null,
        IFishingInventorySnapshotSource? inventorySnapshots = null)
    {
        ArgumentNullException.ThrowIfNull(options);
        ArgumentNullException.ThrowIfNull(state);
        state.Validate();

        var fishingPage = options.Mode switch
        {
            HostRunMode.Production or HostRunMode.DeveloperFullAccess =>
                FishingPageViewModel.CreateProduction(
                automationRuntime ?? throw new InvalidOperationException(
                    "production_automation_runtime_missing")),
            HostRunMode.Demo => FishingPageViewModel.MigrationPreview,
            HostRunMode.OfflineEngine => FishingPageViewModel.CreateOfflineEngine(),
            _ => throw new ArgumentOutOfRangeException(nameof(options)),
        };
        var inventoryPage = options.Mode is HostRunMode.Production or
            HostRunMode.DeveloperFullAccess
            ? InventoryPageViewModel.CreateProduction()
            : new InventoryPageViewModel(InventoryProductState.Unknown);
        IDisposable inventoryLifetime = inventoryPage;
        if (inventorySnapshots is not null)
        {
            inventoryLifetime = new InventoryPageRuntimeBinding(
                inventorySnapshots,
                inventoryPage);
        }
        IAsyncDisposable? streamingLifetime = null;
        var localStreaming = options.Mode is HostRunMode.Production or
            HostRunMode.DeveloperFullAccess
                ? LocalAccessStreamingComposition.TryCreate(
                    state.Fishing.Behavior.StreamSnapshotMode)
                : null;
        IStreamingController streamingController;
        var streamingChatAvailable = false;
        if (localStreaming is null)
        {
            streamingController = new UnavailableStreamingController(
                state.Fishing.Behavior.StreamSnapshotMode);
        }
        else
        {
            streamingController = localStreaming.Controller;
            streamingLifetime = localStreaming.Controller;
            streamingChatAvailable = localStreaming.ChatAvailable;
        }
        var overviewPage = new OverviewPageViewModel(state.Telegram);
        overviewPage.ApplyStreamingSnapshot(streamingController.Current);
        streamingController.SnapshotChanged += overviewPage.ApplyStreamingSnapshot;
        Action<string, double?>? persistCustomPrice = coordinator is null
            ? null
            : (fishId, price) =>
                coordinator.UpdateCustomFishPrice(fishId, price);
        var statisticsPage = new StatisticsPageViewModel(
            FishingSessionStateSnapshot.Empty,
            persistCustomPrice,
            statisticsRuntime);
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
            HostRunMode.Production or HostRunMode.DeveloperFullAccess =>
                EngineHealthViewModel.CreateProduction(
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
        var initialPage = options.Mode switch
        {
            HostRunMode.OfflineEngine => FishingHostPage.EngineHealth,
            HostRunMode.DeveloperFullAccess => FishingHostPage.Overview,
            _ => FishingHostPage.License,
        };
        var effectiveLicense = licenseOverride ?? state.License;
        var allowedFeatures = effectiveLicense.Features.ToHashSet(StringComparer.Ordinal);
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
        var liveRuntime = options.Mode is HostRunMode.Production or
            HostRunMode.DeveloperFullAccess;
        ITelegramProductUseCases telegramProduct = liveRuntime
            ? new FishingTelegramProductUseCases(
                automationRuntime ?? throw new InvalidOperationException(
                    "production_automation_runtime_missing"),
                () =>
                {
                    var current = coordinator?.Current ?? state;
                    return licenseOverride is null
                        ? current
                        : current with { License = licenseOverride };
                })
            : new UnavailableTelegramProductUseCases();
        var telegramNetwork = new TelegramNetworkRunner(
            ReadTelegramSettings,
            SaveTelegramSettingsAsync,
            telegramProduct,
            streamingController,
            liveRuntime ? engineNotifications : null);
        TelegramRuntimeConfiguration TelegramConfiguration(FishingHostState source) => new(
            networkAllowed: liveRuntime,
            featureAllowed: licenseOverride is null
                ? source.License.Features.Contains("telegram", StringComparer.Ordinal)
                : allowedFeatures.Contains("telegram"),
            source.Telegram,
            source.Secrets.TelegramBotToken);
        var telegramPage = new TelegramSettingsPageViewModel(
            state.Telegram,
            state.Secrets.TelegramBotToken,
            telegramFeatureAllowed,
            saveHandler: coordinator is null
                ? null
                : result => coordinator.SaveTelegram(result.Settings, result.BotToken));
        var telegramRuntime = new TelegramAvailabilityCoordinator(
            TelegramConfiguration(state),
            new TelegramAvailabilityProbe(),
            telegramNetwork.RunVerifiedAsync);
        telegramPage.AvailabilityCandidateChanged += telegramRuntime.ApplyCandidate;
        telegramRuntime.ApplyCandidate(telegramPage.CurrentAvailabilityCandidate);
        telegramRuntime.AvailabilityChanged += availability =>
        {
            var current = coordinator?.Current ?? state;
            var featureAllowed = licenseOverride is null
                ? current.License.Features.Contains("telegram", StringComparer.Ordinal)
                : allowedFeatures.Contains("telegram");
            telegramPage.UpdateAccessPolicy(featureAllowed, availability);
        };
        telegramPage.UpdateAccessPolicy(telegramFeatureAllowed, telegramRuntime.Current);
        if (coordinator is not null)
        {
            coordinator.StateChanged += updated =>
            {
                telegramRuntime.ApplyConfiguration(TelegramConfiguration(updated));
                var featureAllowed = licenseOverride is null
                    ? updated.License.Features.Contains("telegram", StringComparer.Ordinal)
                    : allowedFeatures.Contains("telegram");
                telegramPage.UpdateAccessPolicy(featureAllowed, telegramRuntime.Current);
            };
        }
        var licensePage = new LicensePageViewModel(
            effectiveLicense,
            activateLicense,
            options.Mode == HostRunMode.DeveloperFullAccess
                ? LicensePagePresentation.LocalAccess
                : LicensePagePresentation.Standard);
        var shell = new FishingHostShellViewModel(
            overviewPage,
            licensePage,
            fishingPage,
            inventoryPage,
            settingsPage,
            statisticsPage,
            new StreamingPageViewModel(
                streamingController,
                featureAllowed: allowedFeatures.Contains("stream") &&
                    streamingController.Current.Status !=
                        StreamingRuntimeStatus.Unavailable,
                chatFeatureAllowed: allowedFeatures.Contains("stream_chat") &&
                    streamingChatAvailable,
                persistSnapshotMode: coordinator is null
                    ? null
                    : enabled => coordinator.UpdateStreamSnapshotMode(enabled)),
            telegramPage,
            new AboutPageViewModel(clearDiagnostics),
            engineHealth,
            allowedFeatures,
            initialPage);

        if (coordinator is not null)
        {
            coordinator.StateChanged += updated =>
            {
                if (licenseOverride is null)
                {
                    licensePage.ApplyExternalSettings(updated.License);
                    shell.ApplyAllowedFeatures(updated.License.Features);
                }
                fishingPage.RefreshCommandAuthority();
            };
        }

        return new HostApplicationComposition(
            shell,
            new HostLifecycleCoordinator(
                engineHealth,
                telegramRuntime,
                licenseRuntime,
                hotkeyRuntime,
                inventoryLifetime,
                streamingLifetime),
            state);
    }

    private static string RequireEngineExecutable(HostRunOptions options) =>
        string.IsNullOrWhiteSpace(options.EngineExecutable)
            ? throw new HostRunOptionsException(
                "Не удалось открыть выбранный режим. Запустите Sonar Fishing " +
                "обычным способом.")
            : options.EngineExecutable;
}
