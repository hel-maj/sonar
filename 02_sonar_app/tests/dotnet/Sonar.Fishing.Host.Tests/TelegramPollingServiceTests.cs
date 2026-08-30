using System.Text.Json;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.TelegramPage;

namespace Sonar.Fishing.Host.Tests;

internal static class TelegramPollingServiceTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("telegram_polling_orders_updates_acknowledges_callbacks_and_advances_offset", PollingMatches),
        new("telegram_polling_disabled_settings_never_touch_transport", DisabledIsInert),
        new("telegram_polling_recovers_with_health_and_preserves_offset", RetryPreservesOffset),
    ];

    private static void PollingMatches()
    {
        using var cancellation = new CancellationTokenSource();
        var api = new FakeTelegramBotApi(cancellation);
        var decisions = new List<TelegramInboundDecision>();
        var service = new TelegramPollingService(
            api,
            new TelegramInboundRouter(),
            (decision, _) =>
            {
                decisions.Add(decision);
                return Task.CompletedTask;
            });
        var settings = new TelegramHostSettings(
            true,
            [42],
            1.0,
            TelegramHostSettings.Default.Notifications,
            TelegramSoundSettings.AllEnabled);

        TestAssert.Throws<OperationCanceledException>(
            () => service.RunAsync(settings, cancellation.Token).GetAwaiter().GetResult(),
            "Telegram polling did not stop through cancellation");

        TestAssert.True(
            decisions.Select(decision => decision.Kind).SequenceEqual(
            [
                TelegramInboundIntentKind.ShowMainMenu,
                TelegramInboundIntentKind.ShowStatistics,
            ]),
            "Telegram polling did not dispatch updates in sequence order");
        TestAssert.True(
            api.Offsets.Count == 2 && api.Offsets[0] is null && api.Offsets[1] == 3,
            "Telegram polling did not advance to highest update id plus one");
        TestAssert.True(
            api.CallbackAnswers.SequenceEqual(["callback-2"], StringComparer.Ordinal),
            "Telegram callback was not acknowledged exactly once");
    }

    private static void DisabledIsInert()
    {
        using var cancellation = new CancellationTokenSource();
        var api = new FakeTelegramBotApi(cancellation);
        var service = new TelegramPollingService(
            api,
            new TelegramInboundRouter(),
            (_, _) => Task.CompletedTask);
        var disabled = new TelegramHostSettings(
            false,
            [42],
            1.0,
            TelegramHostSettings.Default.Notifications,
            TelegramSoundSettings.AllEnabled);

        service.RunAsync(disabled, CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(0, api.Offsets.Count, "Disabled Telegram started polling");
    }

    private static void RetryPreservesOffset()
    {
        using var cancellation = new CancellationTokenSource();
        var api = new RecoveringTelegramBotApi(cancellation);
        var cursor = new TelegramPollingCursor();
        var health = new List<TelegramAvailabilityStatus>();
        var service = new TelegramPollingService(
            api,
            new TelegramInboundRouter(),
            (_, _) => Task.CompletedTask,
            cursor,
            () => health.Add(TelegramAvailabilityStatus.Available),
            _ => health.Add(TelegramAvailabilityStatus.Unavailable),
            TimeSpan.FromMilliseconds(1));

        TestAssert.Throws<OperationCanceledException>(
            () => service.RunAsync(EnabledSettings(), cancellation.Token).GetAwaiter().GetResult(),
            "Recovering polling did not stop through cancellation");

        TestAssert.True(
            api.Offsets.SequenceEqual([null, null, 6L]),
            "Polling retry replayed or skipped the retained offset");
        TestAssert.True(
            health.SequenceEqual(
                [TelegramAvailabilityStatus.Unavailable, TelegramAvailabilityStatus.Available]),
            "Polling health did not recover after a transient API failure");
        TestAssert.Equal<long>(6, cursor.NextOffset!.Value, "Shared polling cursor was not retained");
    }

    private static TelegramHostSettings EnabledSettings() => new(
        true,
        [42],
        1.0,
        TelegramHostSettings.Default.Notifications,
        TelegramSoundSettings.AllEnabled);

    private sealed class FakeTelegramBotApi(CancellationTokenSource cancellation)
        : ITelegramBotApi
    {
        public List<long?> Offsets { get; } = [];

        public List<string> CallbackAnswers { get; } = [];

        public Task<IReadOnlyList<TelegramBotApiUpdate>> GetUpdatesAsync(
            long? offset,
            int longPollingTimeoutSeconds,
            CancellationToken cancellationToken)
        {
            Offsets.Add(offset);
            if (Offsets.Count == 1)
            {
                IReadOnlyList<TelegramBotApiUpdate> updates =
                [
                    CallbackUpdate(2),
                    MessageUpdate(1),
                ];
                return Task.FromResult(updates);
            }
            cancellation.Cancel();
            return Task.FromCanceled<IReadOnlyList<TelegramBotApiUpdate>>(cancellation.Token);
        }

        public Task AnswerCallbackQueryAsync(
            string callbackId,
            CancellationToken cancellationToken)
        {
            CallbackAnswers.Add(callbackId);
            return Task.CompletedTask;
        }

        public Task<long?> SendMessageAsync(
            long chatId,
            string html,
            bool silent,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken) => throw new NotSupportedException();

        public Task EditMessageAsync(
            long chatId,
            long messageId,
            string html,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken) => throw new NotSupportedException();

        public Task<long?> SendPhotoAsync(
            long chatId,
            ReadOnlyMemory<byte> png,
            string captionHtml,
            bool silent,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken) => throw new NotSupportedException();

        private static TelegramBotApiUpdate CallbackUpdate(long updateId) => new(
            updateId,
            JsonSerializer.SerializeToUtf8Bytes(new
            {
                update_id = updateId,
                callback_query = new
                {
                    id = "callback-2",
                    data = "action:stats",
                    message = new { message_id = 77, chat = new { id = 42 } },
                },
            }).AsMemory());

        private static TelegramBotApiUpdate MessageUpdate(long updateId) => new(
            updateId,
            JsonSerializer.SerializeToUtf8Bytes(new
            {
                update_id = updateId,
                message = new
                {
                    chat = new { id = 42 },
                    text = "/menu",
                },
            }).AsMemory());
    }

    private sealed class RecoveringTelegramBotApi(CancellationTokenSource cancellation)
        : ITelegramBotApi
    {
        public List<long?> Offsets { get; } = [];

        public Task<IReadOnlyList<TelegramBotApiUpdate>> GetUpdatesAsync(
            long? offset,
            int longPollingTimeoutSeconds,
            CancellationToken cancellationToken)
        {
            Offsets.Add(offset);
            if (Offsets.Count == 1)
            {
                throw new TelegramBotApiException("telegram_http_unavailable");
            }
            if (Offsets.Count == 2)
            {
                IReadOnlyList<TelegramBotApiUpdate> updates =
                    [new TelegramBotApiUpdate(5, JsonSerializer.SerializeToUtf8Bytes(new
                    {
                        update_id = 5,
                        message = new { chat = new { id = 99 }, text = "/menu" },
                    }))];
                return Task.FromResult(updates);
            }
            cancellation.Cancel();
            return Task.FromCanceled<IReadOnlyList<TelegramBotApiUpdate>>(cancellation.Token);
        }

        public Task AnswerCallbackQueryAsync(
            string callbackId,
            CancellationToken cancellationToken) => Task.CompletedTask;

        public Task<long?> SendMessageAsync(
            long chatId,
            string html,
            bool silent,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken) => throw new NotSupportedException();

        public Task EditMessageAsync(
            long chatId,
            long messageId,
            string html,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken) => throw new NotSupportedException();

        public Task<long?> SendPhotoAsync(
            long chatId,
            ReadOnlyMemory<byte> png,
            string captionHtml,
            bool silent,
            TelegramMenuPlan? menu,
            CancellationToken cancellationToken) => throw new NotSupportedException();
    }
}
