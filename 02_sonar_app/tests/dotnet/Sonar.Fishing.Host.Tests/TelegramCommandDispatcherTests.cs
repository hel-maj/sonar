using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StreamingPage;
using Sonar.Fishing.Host.TelegramPage;

namespace Sonar.Fishing.Host.Tests;

internal static class TelegramCommandDispatcherTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("telegram_dispatcher_preserves_edit_settings_stats_media_and_action_contracts", DispatchesUseCases),
        new("telegram_dispatcher_routes_stream_controller_and_fails_closed_without_capability", StreamAndCapabilityGuardsMatch),
        new("telegram_dispatcher_handles_unchanged_edit_and_falls_back_from_rejected_edit", EditFallbackMatches),
        new("telegram_runtime_reconfigures_transport_without_leaking_token", RuntimeLifecycleMatches),
        new("telegram_runtime_is_inert_when_network_policy_denies_it", RuntimeDeniedIsInert),
    ];

    private static void DispatchesUseCases()
    {
        var api = new FakeTelegramBotApi();
        var settings = EnabledSettings();
        var saves = 0;
        var product = new FakeProductUseCases(CreateProductState());
        var dispatcher = new TelegramCommandDispatcher(
            api,
            () => settings,
            (updated, cancellationToken) =>
            {
                cancellationToken.ThrowIfCancellationRequested();
                settings = updated;
                saves++;
                return Task.CompletedTask;
            },
            product,
            new TestStreamingController());

        dispatcher.DispatchAsync(
            new TelegramInboundDecision(
                TelegramInboundIntentKind.ShowMainMenu,
                ChatId: 42,
                MessageId: 77),
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(1, api.Edits.Count, "Callback menu was not edited in place");
        TestAssert.True(
            api.Edits[0].Menu!.Rows.SelectMany(row => row)
                .Any(button => button.Text.Contains("Остановить", StringComparison.Ordinal)),
            "Main menu did not project the live fishing state");

        dispatcher.DispatchAsync(
            new TelegramInboundDecision(
                TelegramInboundIntentKind.ToggleNotification,
                ChatId: 42,
                MessageId: 77,
                Notification: TelegramNotificationKind.Catch),
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(1, saves, "Notification toggle was not persisted exactly once");
        TestAssert.True(!settings.Notifications.Catch, "Notification toggle did not update immutable settings");

        dispatcher.DispatchAsync(
            new TelegramInboundDecision(TelegramInboundIntentKind.ShowStatistics, ChatId: 42),
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(
            api.Messages[^1].Html.Contains("Текущая статистика", StringComparison.Ordinal) &&
            api.Messages[^1].Html.Contains("Карп", StringComparison.Ordinal),
            "Statistics command lost aggregate or per-fish details");

        dispatcher.DispatchAsync(
            new TelegramInboundDecision(TelegramInboundIntentKind.ShowTackle, ChatId: 42),
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(1, api.Photos.Count, "Tackle evidence did not use the available PNG");
        TestAssert.True(
            api.Photos[0].Html.Contains("Удочка", StringComparison.Ordinal),
            "Tackle caption lost inventory details");

        dispatcher.DispatchAsync(
            new TelegramInboundDecision(TelegramInboundIntentKind.FocusGame, ChatId: 42),
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(
            product.Actions.SequenceEqual([TelegramProductAction.FocusGame]),
            "Guarded product action did not reach its narrow Host port");
        TestAssert.Equal("🎮 Фокус возвращён игре", api.Messages[^1].Html, "Action response changed");
    }

    private static void StreamAndCapabilityGuardsMatch()
    {
        var api = new FakeTelegramBotApi();
        var settings = EnabledSettings();
        var streaming = new TestStreamingController();
        var product = new FakeProductUseCases(CreateProductState());
        var dispatcher = new TelegramCommandDispatcher(
            api,
            () => settings,
            (_, _) => Task.CompletedTask,
            product,
            streaming);

        dispatcher.DispatchAsync(
            new TelegramInboundDecision(
                TelegramInboundIntentKind.SetStreamQuality,
                ChatId: 42,
                MessageId: 77,
                Value: "1080p"),
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal("1080p", streaming.Current.Quality, "Stream quality command was not applied");
        TestAssert.True(
            api.Edits[^1].Menu!.Rows.SelectMany(row => row)
                .Any(button => button.Text.Contains("1080p", StringComparison.Ordinal)),
            "Edited stream menu did not project the accepted quality");

        dispatcher.DispatchAsync(
            new TelegramInboundDecision(
                TelegramInboundIntentKind.ToggleStream,
                ChatId: 42,
                MessageId: 77),
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(streaming.Current.Active, "Stream start command did not reach the controller");
        TestAssert.True(
            api.Edits[^1].Menu!.Rows.SelectMany(row => row)
                .Any(button => button.Url == "https://stream.example/live/"),
            "Online stream menu lost its verified HTTPS link");

        var unavailableProduct = new FakeProductUseCases(TelegramProductState.Unavailable);
        var guarded = new TelegramCommandDispatcher(
            api,
            () => settings,
            (_, _) => Task.CompletedTask,
            unavailableProduct,
            streaming);
        guarded.DispatchAsync(
            new TelegramInboundDecision(TelegramInboundIntentKind.ToggleFishing, ChatId: 42),
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(0, unavailableProduct.Actions.Count, "Unavailable fishing action crossed the capability gate");
        TestAssert.True(
            api.Messages[^1].Html.Contains("недоступен", StringComparison.Ordinal),
            "Capability rejection was not visible to the admin");
    }

    private static void RuntimeLifecycleMatches()
    {
        const string token = "12345:secret_TOKEN";
        var settings = EnabledSettings();
        var starts = 0;
        var coordinator = new TelegramRuntimeCoordinator(
            new TelegramRuntimeConfiguration(true, true, settings, token),
            async (_, cancellationToken) =>
            {
                Interlocked.Increment(ref starts);
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken).ConfigureAwait(false);
            });

        coordinator.StartAsync().GetAwaiter().GetResult();
        coordinator.StartAsync().GetAwaiter().GetResult();
        TestAssert.True(
            SpinWait.SpinUntil(() => Volatile.Read(ref starts) == 1, TimeSpan.FromSeconds(2)),
            "Telegram runtime generation did not start");

        var notificationOnly = new TelegramHostSettings(
            true,
            [42],
            1.0,
            settings.Notifications with { Catch = !settings.Notifications.Catch },
            settings.Sounds);
        coordinator.ApplyConfiguration(new TelegramRuntimeConfiguration(
            true,
            true,
            notificationOnly,
            token));
        Task.Delay(100).GetAwaiter().GetResult();
        TestAssert.Equal(1, Volatile.Read(ref starts), "Notification-only save restarted long polling");

        coordinator.ApplyConfiguration(new TelegramRuntimeConfiguration(
            true,
            true,
            notificationOnly,
            "12345:rotated_TOKEN"));
        TestAssert.True(
            SpinWait.SpinUntil(() => Volatile.Read(ref starts) == 2, TimeSpan.FromSeconds(2)),
            "Token rotation did not replace the polling generation");
        coordinator.StopAsync().GetAwaiter().GetResult();
        coordinator.StopAsync().GetAwaiter().GetResult();
        TestAssert.Throws<InvalidOperationException>(
            () => coordinator.StartAsync().GetAwaiter().GetResult(),
            "Terminally stopped Telegram runtime restarted");

        var description = new TelegramRuntimeConfiguration(true, true, settings, token).ToString();
        TestAssert.True(
            !description.Contains(token, StringComparison.Ordinal) &&
            description.Contains("[REDACTED]", StringComparison.Ordinal),
            "Telegram runtime configuration exposed the bot token");
    }

    private static void EditFallbackMatches()
    {
        var settings = EnabledSettings();
        var api = new FakeTelegramBotApi
        {
            EditFailureReason = "telegram_message_not_modified",
        };
        var dispatcher = new TelegramCommandDispatcher(
            api,
            () => settings,
            (_, _) => Task.CompletedTask,
            new FakeProductUseCases(CreateProductState()),
            new TestStreamingController());
        var decision = new TelegramInboundDecision(
            TelegramInboundIntentKind.ShowMainMenu,
            ChatId: 42,
            MessageId: 77);

        dispatcher.DispatchAsync(decision, CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(0, api.Messages.Count, "Unchanged edit created a duplicate message");

        api.EditFailureReason = "telegram_api_rejected";
        dispatcher.DispatchAsync(decision, CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(1, api.Messages.Count, "Rejected edit did not fall back to a new message");
    }

    private static void RuntimeDeniedIsInert()
    {
        var starts = 0;
        var coordinator = new TelegramRuntimeCoordinator(
            new TelegramRuntimeConfiguration(
                networkAllowed: false,
                featureAllowed: true,
                EnabledSettings(),
                "12345:secret_TOKEN"),
            (_, _) =>
            {
                Interlocked.Increment(ref starts);
                return Task.CompletedTask;
            });
        coordinator.StartAsync().GetAwaiter().GetResult();
        coordinator.StopAsync().GetAwaiter().GetResult();
        TestAssert.Equal(0, Volatile.Read(ref starts), "Denied network policy started Telegram transport");
    }

    private static TelegramHostSettings EnabledSettings() => new(
        true,
        [42],
        1.0,
        new TelegramNotificationSettings(true, true, true, true, true, true, true),
        TelegramSoundSettings.AllEnabled);

    private static TelegramProductState CreateProductState()
    {
        var session = new FishingSessionStateSnapshot(
            revision: 3,
            running: true,
            stopping: false,
            detectedStage: "fishing",
            totals: new FishingSessionTotalsSnapshot(600, 2, 4.5, 0, 0, 100, 120),
            tackleItems: [new FishingTackleItemSnapshot("rod", "Удочка", 1)],
            fishRows:
            [
                new FishingSessionFishRowSnapshot(
                    "carp",
                    "Карп",
                    2,
                    4.5,
                    0,
                    0,
                    2,
                    4.5,
                    null,
                    null,
                    100,
                    120),
            ]);
        return new TelegramProductState(
            new TelegramMenuCapabilities(true, true, true, true),
            session,
            new TelegramPlayerStatusSnapshot(90, 80, 100, 10, 20, null, null),
            new byte[] { 0x89, 0x50, 0x4e, 0x47 });
    }

    private sealed class FakeProductUseCases(TelegramProductState state)
        : ITelegramProductUseCases
    {
        public List<TelegramProductAction> Actions { get; } = [];

        public TelegramProductState Current { get; } = state;

        public Task<TelegramProductActionResult> ExecuteAsync(
            TelegramProductAction action,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            Actions.Add(action);
            return Task.FromResult(TelegramProductActionResult.Message(
                action == TelegramProductAction.FocusGame
                    ? "🎮 Фокус возвращён игре"
                    : "✅ Команда принята"));
        }
    }

    private sealed class FakeTelegramBotApi : ITelegramBotApi
    {
        public List<Sent> Messages { get; } = [];
        public List<Sent> Edits { get; } = [];
        public List<Sent> Photos { get; } = [];

        public string EditFailureReason { get; set; } = string.Empty;

        public Task<IReadOnlyList<TelegramBotApiUpdate>> GetUpdatesAsync(
            long? offset,
            int longPollingTimeoutSeconds,
            CancellationToken cancellationToken) => throw new NotSupportedException();

        public Task<long?> SendMessageAsync(
            long chatId,
            string html,
            bool silent,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken)
        {
            Messages.Add(new Sent(chatId, null, html, menu));
            return Task.FromResult<long?>(Messages.Count);
        }

        public Task EditMessageAsync(
            long chatId,
            long messageId,
            string html,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken)
        {
            if (EditFailureReason.Length != 0)
            {
                throw new TelegramBotApiException(EditFailureReason, statusCode: 400);
            }
            Edits.Add(new Sent(chatId, messageId, html, menu));
            return Task.CompletedTask;
        }

        public Task<long?> SendPhotoAsync(
            long chatId,
            ReadOnlyMemory<byte> png,
            string captionHtml,
            bool silent,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken)
        {
            Photos.Add(new Sent(chatId, null, captionHtml, menu));
            return Task.FromResult<long?>(Photos.Count);
        }

        public Task AnswerCallbackQueryAsync(
            string callbackId,
            CancellationToken cancellationToken) => Task.CompletedTask;
    }

    private sealed record Sent(
        long ChatId,
        long? MessageId,
        string Html,
        TelegramMenuPlan? Menu);

    private sealed class TestStreamingController : IStreamingController
    {
        private ulong revision = 1;

        public StreamingRuntimeSnapshot Current { get; private set; } = new(
            1,
            StreamingRuntimeStatus.Offline,
            false,
            "720p",
            false,
            false,
            false,
            false,
            null,
            null,
            null,
            null,
            null,
            string.Empty);

        public event Action<StreamingRuntimeSnapshot>? SnapshotChanged;

        public StreamingCommandResult Start() => Update(Current with
        {
            Status = StreamingRuntimeStatus.Online,
            Active = true,
            PublicUrl = "https://stream.example",
            StreamUrl = "https://stream.example/live/",
            StartedAt = DateTimeOffset.UtcNow,
        });

        public StreamingCommandResult Stop(string reason) => Update(Current with
        {
            Status = StreamingRuntimeStatus.Offline,
            Active = false,
            PublicUrl = null,
            StreamUrl = null,
            StartedAt = null,
        });

        public StreamingCommandResult SetQuality(string quality) =>
            Update(Current with { Quality = StreamingQualityCatalog.Require(quality).Name });

        public StreamingCommandResult SetChatZoom(bool enabled) =>
            Update(Current with { ChatZoomEnabled = enabled });

        public StreamingCommandResult SetSnapshotMode(bool enabled) =>
            Update(Current with { SnapshotModeEnabled = enabled });

        public StreamingCommandResult SetChatMode(bool enabled) =>
            Update(Current with { ChatModeEnabled = enabled, ChatActive = enabled });

        private StreamingCommandResult Update(StreamingRuntimeSnapshot next)
        {
            Current = next with { Revision = ++revision };
            Current.Validate();
            SnapshotChanged?.Invoke(Current);
            return new StreamingCommandResult(true, "accepted", Current);
        }
    }
}
