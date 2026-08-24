using Sonar.Fishing.Host.EngineIntegration.Notifications;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.TelegramPage;
using Sonar.Fishing.Ipc.Contracts.V1;

namespace Sonar.Fishing.Host.Tests;

internal static class TelegramEngineNotificationPublisherTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("telegram_engine_publisher_deduplicates_generation_sequence_and_survives_send_failure", PublishesCurrentGenerationOnly),
        new("telegram_inventory_low_notification_is_edge_triggered", InventoryLowIsEdgeTriggered),
        new("telegram_engine_wire_mapper_preserves_typed_event_payload", WireMapperPreservesPayload),
    ];

    private static void PublishesCurrentGenerationOnly()
    {
        var source = new FakeSource();
        var api = new FakeApi(blockFirstSend: true, failAttempt: 2);
        var publisher = new TelegramEngineNotificationPublisher(
            source,
            EnabledSettings,
            new FakeProduct());
        using var cancellation = new CancellationTokenSource();
        var running = publisher.RunAsync(api, cancellation.Token);

        source.Emit(1, 1, new BaitTiredEngineNotification());
        TestAssert.True(
            api.FirstSendStarted.Task.Wait(TimeSpan.FromSeconds(2)),
            "First notification did not reach the publisher");
        source.Emit(1, 2, new InventoryFullEngineNotification());
        source.Emit(1, 3, new BaitTiredEngineNotification());
        source.Emit(2, 1, new FocusLostEngineNotification("window_not_foreground"));
        source.Emit(1, 4, new InventoryFullEngineNotification());
        source.Emit(2, 1, new BaitTiredEngineNotification());
        api.ReleaseFirstSend.TrySetResult();
        TestAssert.True(
            SpinWait.SpinUntil(() => api.AttemptCount >= 2, TimeSpan.FromSeconds(2)),
            "Replacement generation notification was not attempted");
        source.Emit(2, 2, new InventoryFullEngineNotification());
        TestAssert.True(
            SpinWait.SpinUntil(() => api.AttemptCount >= 3, TimeSpan.FromSeconds(2)),
            "Publisher stopped after a Telegram send failure");
        cancellation.Cancel();
        TestAssert.Throws<OperationCanceledException>(
            () => running.GetAwaiter().GetResult(),
            "Publisher did not stop with its network generation");

        var attempts = api.Attempts;
        TestAssert.Equal(3, attempts.Count, "Duplicate or retired Engine event was delivered");
        TestAssert.True(
            attempts[0].Contains("Рыба устала", StringComparison.Ordinal) &&
            attempts[1].Contains("Фокус ушёл", StringComparison.Ordinal) &&
            attempts[2].Contains("Закончилось место", StringComparison.Ordinal),
            "Typed Engine notification projection changed");
    }

    private static void InventoryLowIsEdgeTriggered()
    {
        var source = new FakeSource();
        var api = new FakeApi();
        var publisher = new TelegramEngineNotificationPublisher(
            source,
            EnabledSettings,
            new FakeProduct());
        using var cancellation = new CancellationTokenSource();
        var running = publisher.RunAsync(api, cancellation.Token);

        source.Emit(1, 1, Status(current: 39.5, maximum: 40));
        source.Emit(1, 2, Status(current: 39.75, maximum: 40));
        source.Emit(1, 3, Status(current: 35, maximum: 40));
        source.Emit(1, 4, Status(current: 39.5, maximum: 40));
        TestAssert.True(
            SpinWait.SpinUntil(() => api.AttemptCount >= 2, TimeSpan.FromSeconds(2)),
            "Inventory threshold edge did not publish twice");
        cancellation.Cancel();
        TestAssert.Throws<OperationCanceledException>(
            () => running.GetAwaiter().GetResult(),
            "Inventory publisher did not stop");

        TestAssert.Equal(2, api.Attempts.Count, "Repeated low status notification was not deduplicated");
        TestAssert.True(
            api.Attempts.All(message => message.Contains("Мало места", StringComparison.Ordinal)),
            "Inventory status mapped to the wrong notification");
    }

    private static void WireMapperPreservesPayload()
    {
        var wire = new FishingNotificationEvent
        {
            CatchObserved = new CatchNotification
            {
                FishName = "Марлин",
                WeightKg = 12.5,
                QualityText = "Трофейная",
                XpCurrent = 7,
                XpTotal = 10,
                Released = true,
                Totals = WireTotals(),
            },
        };
        var mapped = FishingEngineNotificationWireMapper.Map(wire);

        TestAssert.True(
            mapped is FishingCatchEngineNotification
            {
                FishName: "Марлин",
                WeightKg: 12.5,
                QualityText: "Трофейная",
                XpCurrent: 7,
                XpTotal: 10,
                Released: true,
                Totals.CaughtCount: 4,
            },
            "Typed catch event changed during wire mapping");
        TestAssert.Throws<InvalidOperationException>(
            () => FishingEngineNotificationWireMapper.Map(new FishingNotificationEvent()),
            "Missing notification detail was accepted");
    }

    private static TelegramHostSettings EnabledSettings() => new(
        enabled: true,
        adminIds: [42],
        inventorySpaceLowThresholdKg: 1.0,
        TelegramHostSettings.Default.Notifications with
        {
            InventorySpaceLow = true,
            FocusLost = true,
        },
        TelegramSoundSettings.AllEnabled);

    private static PlayerStatusEngineNotification Status(double current, double maximum) => new(
        new FishingPlayerStatusSnapshot(
            Food: 80,
            Water: 90,
            Health: 100,
            InventoryWeight: current,
            InventoryWeightMax: maximum,
            BackpackWeight: null,
            BackpackWeightMax: null));

    private static FishingSessionTotalsSnapshot Totals() => new(
        60,
        4,
        12.5,
        1,
        1.0,
        100,
        120);

    private static FishingSessionTotals WireTotals() => new()
    {
        DurationSeconds = 60,
        CaughtCount = 4,
        CaughtKg = 12.5,
        ReleasedCount = 1,
        ReleasedKg = 1,
        EarnedMin = 100,
        EarnedMax = 120,
    };

    private sealed class FakeSource : IFishingEngineNotificationSource
    {
        public event Action<FishingEngineNotificationReceipt>? NotificationReceived;

        internal void Emit(
            ulong generation,
            ulong sequence,
            FishingEngineNotification notification) =>
            NotificationReceived?.Invoke(new FishingEngineNotificationReceipt(
                generation,
                sequence,
                1_900_000_000_000,
                notification));
    }

    private sealed class FakeProduct : ITelegramProductUseCases
    {
        public TelegramProductState Current { get; } = new(
            new TelegramMenuCapabilities(true, true, true, false),
            new FishingSessionStateSnapshot(1, true, false, "active", Totals(), []),
            null,
            ReadOnlyMemory<byte>.Empty);

        public Task<TelegramProductActionResult> ExecuteAsync(
            TelegramProductAction action,
            CancellationToken cancellationToken) =>
            throw new NotSupportedException();
    }

    private sealed class FakeApi(
        bool blockFirstSend = false,
        int failAttempt = 0) : ITelegramBotApi
    {
        private readonly object gate = new();
        private readonly List<string> attempts = [];

        internal TaskCompletionSource FirstSendStarted { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        internal TaskCompletionSource ReleaseFirstSend { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        internal int AttemptCount
        {
            get
            {
                lock (gate)
                {
                    return attempts.Count;
                }
            }
        }

        internal IReadOnlyList<string> Attempts
        {
            get
            {
                lock (gate)
                {
                    return attempts.ToArray();
                }
            }
        }

        public Task<IReadOnlyList<TelegramBotApiUpdate>> GetUpdatesAsync(
            long? offset,
            int longPollingTimeoutSeconds,
            CancellationToken cancellationToken) =>
            throw new NotSupportedException();

        public async Task<long?> SendMessageAsync(
            long chatId,
            string html,
            bool silent,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken)
        {
            int attempt;
            lock (gate)
            {
                attempts.Add(html);
                attempt = attempts.Count;
            }
            if (attempt == 1)
            {
                FirstSendStarted.TrySetResult();
                if (blockFirstSend)
                {
                    await ReleaseFirstSend.Task.WaitAsync(cancellationToken)
                        .ConfigureAwait(false);
                }
            }
            if (attempt == failAttempt)
            {
                throw new TelegramBotApiException("fixture_send_failed");
            }
            return attempt;
        }

        public Task EditMessageAsync(
            long chatId,
            long messageId,
            string html,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken) =>
            throw new NotSupportedException();

        public Task<long?> SendPhotoAsync(
            long chatId,
            ReadOnlyMemory<byte> png,
            string captionHtml,
            bool silent,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken) =>
            throw new NotSupportedException();

        public Task AnswerCallbackQueryAsync(
            string callbackId,
            CancellationToken cancellationToken) =>
            throw new NotSupportedException();
    }
}
