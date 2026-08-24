using System.Threading.Channels;
using Sonar.Fishing.Host.EngineIntegration.Notifications;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

internal sealed class TelegramEngineNotificationPublisher
{
    private const int MaximumPendingNotifications = 64;
    private readonly IFishingEngineNotificationSource source;
    private readonly Func<TelegramHostSettings> readSettings;
    private readonly ITelegramProductUseCases product;

    internal TelegramEngineNotificationPublisher(
        IFishingEngineNotificationSource source,
        Func<TelegramHostSettings> readSettings,
        ITelegramProductUseCases product)
    {
        this.source = source ?? throw new ArgumentNullException(nameof(source));
        this.readSettings = readSettings ?? throw new ArgumentNullException(nameof(readSettings));
        this.product = product ?? throw new ArgumentNullException(nameof(product));
    }

    internal async Task RunAsync(
        ITelegramBotApi api,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(api);
        var channel = Channel.CreateBounded<FishingEngineNotificationReceipt>(
            new BoundedChannelOptions(MaximumPendingNotifications)
            {
                SingleReader = true,
                SingleWriter = false,
                FullMode = BoundedChannelFullMode.DropWrite,
                AllowSynchronousContinuations = false,
            });
        var sequenceGate = new object();
        ulong latestGeneration = 0;
        ulong latestSequence = 0;

        void Receive(FishingEngineNotificationReceipt receipt)
        {
            try
            {
                lock (sequenceGate)
                {
                    if (receipt.Generation < latestGeneration)
                    {
                        return;
                    }
                    if (receipt.Generation > latestGeneration)
                    {
                        latestGeneration = receipt.Generation;
                        latestSequence = 0;
                    }
                    if (receipt.Sequence <= latestSequence)
                    {
                        return;
                    }
                    latestSequence = receipt.Sequence;
                    _ = channel.Writer.TryWrite(receipt);
                }
            }
            catch
            {
                // An observational notification cannot fail the Engine event
                // source, Host lifecycle or fishing runtime.
            }
        }

        source.NotificationReceived += Receive;
        try
        {
            ulong projectionGeneration = 0;
            bool inventoryWasLow = false;
            await foreach (var receipt in channel.Reader.ReadAllAsync(cancellationToken)
                               .ConfigureAwait(false))
            {
                lock (sequenceGate)
                {
                    if (receipt.Generation < latestGeneration)
                    {
                        continue;
                    }
                }
                try
                {
                    if (receipt.Generation != projectionGeneration)
                    {
                        projectionGeneration = receipt.Generation;
                        inventoryWasLow = false;
                    }
                    var settings = readSettings();
                    ArgumentNullException.ThrowIfNull(settings);
                    if (!settings.Enabled || settings.AdminIds.Count == 0)
                    {
                        continue;
                    }
                    var plan = Plan(settings, receipt.Notification, ref inventoryWasLow);
                    if (plan is null)
                    {
                        continue;
                    }
                    var current = product.Current;
                    var menu = plan.IncludeMenuButton
                        ? TelegramMenuPlanner.BuildMainMenu(
                            current.Capabilities,
                            current.Session.Running)
                        : null;
                    foreach (var chatId in settings.AdminIds.Distinct())
                    {
                        try
                        {
                            _ = await api.SendMessageAsync(
                                chatId,
                                plan.Html,
                                plan.Silent,
                                menu,
                                cancellationToken).ConfigureAwait(false);
                        }
                        catch (OperationCanceledException)
                            when (cancellationToken.IsCancellationRequested)
                        {
                            throw;
                        }
                        catch
                        {
                            // One rejected administrator delivery cannot block
                            // other recipients or the next Engine occurrence.
                        }
                    }
                }
                catch (OperationCanceledException)
                    when (cancellationToken.IsCancellationRequested)
                {
                    throw;
                }
                catch
                {
                    // Invalid observational data or planner failure is dropped
                    // without affecting polling, Host or Engine runtime.
                }
            }
        }
        finally
        {
            source.NotificationReceived -= Receive;
            channel.Writer.TryComplete();
        }
    }

    private static TelegramNotificationPlan? Plan(
        TelegramHostSettings settings,
        FishingEngineNotification notification,
        ref bool inventoryWasLow) => notification switch
    {
        FishingCatchEngineNotification value => TelegramNotificationPlanner.PlanCatch(
            settings,
            new TelegramCatchNotification(
                value.FishName,
                value.WeightKg,
                value.QualityText,
                ToInt(value.XpCurrent),
                ToInt(value.XpTotal),
                value.Released,
                value.Totals,
                PreferPhoto: false)),
        FishingStartedEngineNotification value =>
            TelegramNotificationPlanner.PlanFishingStarted(
                settings,
                Session(value.Totals, running: true),
                hasStatistics: value.Totals.CaughtCount != 0),
        FishingStoppedEngineNotification value =>
            TelegramNotificationPlanner.PlanFishingStopped(
                settings,
                Session(value.Totals, running: false),
                UserFacingStopReason(value.Reason),
                preferPhoto: false),
        MealRecoveredEngineNotification value => TelegramMealNotificationPlanner.Plan(
            settings,
            value.AffectedCount == 1 ? "Приём пищи" : $"Приём пищи: {value.AffectedCount}",
            itemInfo: null,
            PlayerStatus(value.PlayerStatus)),
        InventoryFullEngineNotification =>
            TelegramNotificationPlanner.PlanInventoryFull(settings),
        PlayerStatusEngineNotification value => PlanInventoryStatus(
            settings,
            value.Status,
            ref inventoryWasLow),
        BaitTiredEngineNotification =>
            TelegramNotificationPlanner.PlanBaitTired(settings),
        FocusLostEngineNotification =>
            TelegramNotificationPlanner.PlanFocusLost(settings),
        _ => null,
    };

    private static TelegramNotificationPlan? PlanInventoryStatus(
        TelegramHostSettings settings,
        FishingPlayerStatusSnapshot status,
        ref bool inventoryWasLow)
    {
        if (status.InventoryWeight is not { } current ||
            status.InventoryWeightMax is not { } maximum ||
            maximum < current)
        {
            inventoryWasLow = false;
            return null;
        }
        var free = maximum - current;
        var low = free <= settings.InventorySpaceLowThresholdKg;
        if (!low)
        {
            inventoryWasLow = false;
            return null;
        }
        if (inventoryWasLow)
        {
            return null;
        }
        inventoryWasLow = true;
        return TelegramNotificationPlanner.PlanInventorySpaceLow(
            settings,
            free,
            settings.InventorySpaceLowThresholdKg,
            PlayerStatus(status));
    }

    private static FishingSessionStateSnapshot Session(
        FishingSessionTotalsSnapshot totals,
        bool running) => new(
            revision: 1,
            running,
            stopping: false,
            detectedStage: running ? "active" : "idle",
            totals,
            tackleItems: [],
            acceptedSettingsRevision: 1);

    private static TelegramPlayerStatusSnapshot? PlayerStatus(
        FishingPlayerStatusSnapshot? status) => status is null
        ? null
        : new TelegramPlayerStatusSnapshot(
            status.Food,
            status.Water,
            status.Health,
            status.InventoryWeight,
            status.InventoryWeightMax,
            status.BackpackWeight,
            status.BackpackWeightMax);

    private static int? ToInt(ulong? value) => value is { } present && present <= int.MaxValue
        ? (int)present
        : null;

    private static string? UserFacingStopReason(string? reason) =>
        reason?.Contains("not_foreground", StringComparison.Ordinal) == true
            ? "окно игры потеряло фокус"
            : null;
}
