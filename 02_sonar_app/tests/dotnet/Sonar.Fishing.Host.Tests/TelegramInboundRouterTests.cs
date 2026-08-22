using System.IO;
using System.Text.Json;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.TelegramPage;

namespace Sonar.Fishing.Host.Tests;

internal static class TelegramInboundRouterTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("telegram_inbound_router_matches_shared_legacy_corpus", SharedCorpusMatches),
        new("telegram_inbound_router_rejects_disabled_unauthorized_and_malformed", RouterFailsClosed),
        new("telegram_notification_catalog_and_reducer_preserve_exact_policy", CatalogAndReducerMatch),
        new("telegram_menu_planner_preserves_exact_union_and_callback_allowlist", MenuPlannerMatches),
        new("telegram_notification_menu_reflects_send_and_sound_policy", NotificationMenuMatches),
    ];

    private static void SharedCorpusMatches()
    {
        var router = new TelegramInboundRouter();
        var settings = EnabledSettings();
        var path = Path.Combine(
            AppContext.BaseDirectory,
            "Fixtures",
            "telegram",
            "inbound_router.tsv");
        var rows = File.ReadAllLines(path).Skip(1);
        var count = 0;
        foreach (var row in rows)
        {
            if (string.IsNullOrWhiteSpace(row))
            {
                continue;
            }
            count++;
            var columns = row.Split('\t');
            TestAssert.Equal(5, columns.Length, "Telegram corpus column count changed");
            var json = columns[0] switch
            {
                "message" => MessageJson(columns[1], chatId: 42),
                "callback" => CallbackJson(columns[1], chatId: 42, messageId: 77),
                _ => throw new InvalidDataException("telegram_corpus_kind_invalid"),
            };
            var decision = router.RouteJson(json, runtimeEnabled: true, settings);
            var expectedKind = Enum.Parse<TelegramInboundIntentKind>(columns[2]);

            TestAssert.Equal(expectedKind, decision.Kind, $"Intent changed for {columns[1]}");
            if (columns[3] != "-")
            {
                if (expectedKind == TelegramInboundIntentKind.SetStreamQuality)
                {
                    TestAssert.Equal(columns[3], decision.Value, "Stream quality payload changed");
                }
                else
                {
                    TestAssert.Equal(
                        Enum.Parse<TelegramNotificationKind>(columns[3]),
                        decision.Notification!.Value,
                        "Notification callback mapping changed");
                }
            }
            TestAssert.Equal(
                columns[4] == "edit",
                decision.MessageId.HasValue,
                "New/edit message target changed");
            TestAssert.Equal(
                columns[0] == "callback",
                decision.RequiresCallbackAnswer,
                "Callback acknowledgement contract changed");
        }
        TestAssert.Equal(45, count, "Telegram shared corpus case count changed");
    }

    private static void RouterFailsClosed()
    {
        var router = new TelegramInboundRouter();
        var enabled = EnabledSettings();
        var disabled = new TelegramHostSettings(
            false,
            enabled.AdminIds,
            enabled.InventorySpaceLowThresholdKg,
            enabled.Notifications,
            enabled.Sounds);

        TestAssert.Equal(
            TelegramInboundIntentKind.Ignore,
            router.RouteJson(MessageJson("/menu", 42), false, enabled).Kind,
            "Runtime-disabled router accepted a command");
        TestAssert.Equal(
            TelegramInboundIntentKind.Ignore,
            router.RouteJson(MessageJson("/menu", 42), true, disabled).Kind,
            "Settings-disabled router accepted a command");
        TestAssert.Equal(
            TelegramInboundIntentKind.Ignore,
            router.RouteJson(MessageJson("/shutdown_pc", 99), true, enabled).Kind,
            "Unauthorized destructive command was accepted");
        TestAssert.Equal(
            TelegramInboundIntentKind.Ignore,
            router.RouteJson("{"u8, true, enabled).Kind,
            "Malformed JSON was accepted");
        TestAssert.Equal(
            TelegramInboundIntentKind.Ignore,
            router.RouteJson(MessageJson(string.Empty, 42), true, enabled).Kind,
            "Empty message was not ignored fail-closed");

        var invalidToggle = router.RouteJson(
            CallbackJson("toggle:not_a_field", 42, 77),
            true,
            enabled);
        TestAssert.Equal(
            TelegramInboundIntentKind.ShowNotifications,
            invalidToggle.Kind,
            "Unknown notification field escaped the allowlist");
        TestAssert.True(
            invalidToggle.RequiresCallbackAnswer,
            "Authorized unknown toggle lost callback acknowledgement");
    }

    private static void CatalogAndReducerMatch()
    {
        TestAssert.True(
            TelegramNotificationCatalog.All.Select(item => item.Label).SequenceEqual(
            [
                "Поймана рыба",
                "Запуск/Остановка",
                "Питание",
                "Закончилось место",
                "Мало места",
                "Устала от приманки",
                "Потеря фокуса игры",
            ], StringComparer.Ordinal),
            "Telegram notification order or copy changed");
        var initial = EnabledSettings();
        var notificationDecision = new TelegramInboundDecision(
            TelegramInboundIntentKind.ToggleNotification,
            Notification: TelegramNotificationKind.FocusLost);
        TestAssert.True(
            TelegramSettingsReducer.TryApply(initial, notificationDecision, out var notificationsChanged),
            "Notification reducer rejected an allowed toggle");
        TestAssert.True(
            notificationsChanged.Notifications.FocusLost,
            "Notification reducer did not toggle focus lost");
        TestAssert.True(
            notificationsChanged.Sounds.FocusLost,
            "Notification toggle changed its sound policy");

        var soundDecision = new TelegramInboundDecision(
            TelegramInboundIntentKind.ToggleNotificationSound,
            Notification: TelegramNotificationKind.Catch);
        TestAssert.True(
            TelegramSettingsReducer.TryApply(initial, soundDecision, out var soundsChanged),
            "Sound reducer rejected an allowed toggle");
        TestAssert.True(!soundsChanged.Sounds.Catch, "Sound reducer did not toggle catch");
        TestAssert.True(soundsChanged.Notifications.Catch, "Sound toggle changed notification send policy");
    }

    private static void MenuPlannerMatches()
    {
        var full = TelegramMenuPlanner.BuildMainMenu(
            new TelegramMenuCapabilities(true, true, true, true),
            fishingRunning: false);
        TestAssert.Equal("🎣 Меню рыболовного бота", full.Text, "Main menu title changed");
        TestAssert.Equal(8, full.Rows.Count, "Full Telegram menu row count changed");
        TestAssert.True(
            full.Rows[0].Select(button => button.Text).SequenceEqual(
                ["🔔 Уведомления", "📊 Статистика"],
                StringComparer.Ordinal),
            "Main menu first row changed");
        TestAssert.Equal("🚤 Запустить", full.Rows[4][0].Text, "Stopped menu action changed");
        var running = TelegramMenuPlanner.BuildMainMenu(
            new TelegramMenuCapabilities(true, true, true, true),
            fishingRunning: true);
        TestAssert.Equal("🛑 Остановить", running.Rows[4][0].Text, "Running menu action changed");

        var limited = TelegramMenuPlanner.BuildMainMenu(
            new TelegramMenuCapabilities(false, false, false, false),
            fishingRunning: true);
        TestAssert.Equal(6, limited.Rows.Count, "Limited Telegram menu row count changed");
        TestAssert.True(
            limited.Rows.SelectMany(row => row).All(button =>
                button.CallbackData is not "action:stats" and not "action:tackle" and
                    not "menu:stream" and not "action:start_stop"),
            "Limited menu exposed a gated action");

        var quality = TelegramMenuPlanner.BuildStreamQuality("720p");
        TestAssert.Equal("✅ 720p", quality.Rows[0][1].Text, "Current stream quality marker changed");
        TestAssert.Equal("stream:quality:1080p", quality.Rows[0][2].CallbackData, "Quality callback changed");
    }

    private static void NotificationMenuMatches()
    {
        var settings = new TelegramHostSettings(
            true,
            [42],
            1.0,
            TelegramHostSettings.Default.Notifications with { Catch = false },
            TelegramSoundSettings.AllEnabled with { Catch = false });
        var menu = TelegramMenuPlanner.BuildNotifications(settings);

        TestAssert.Equal(8, menu.Rows.Count, "Notification menu row count changed");
        TestAssert.Equal("🔕 Поймана рыба", menu.Rows[0][0].Text, "Notification off icon changed");
        TestAssert.Equal("🔇 Звук", menu.Rows[0][1].Text, "Sound off icon changed");
        TestAssert.Equal("toggle:notify_catch", menu.Rows[0][0].CallbackData, "Notification callback changed");
        TestAssert.Equal("toggle_sound:sound_catch", menu.Rows[0][1].CallbackData, "Sound callback changed");
        TestAssert.Equal("⬅️ Меню", menu.Rows[^1][0].Text, "Notification back action changed");
    }

    private static TelegramHostSettings EnabledSettings() => new(
        true,
        [42],
        1.0,
        TelegramHostSettings.Default.Notifications,
        TelegramSoundSettings.AllEnabled);

    private static byte[] MessageJson(string text, long chatId) =>
        JsonSerializer.SerializeToUtf8Bytes(new
        {
            update_id = 1,
            message = new
            {
                chat = new { id = chatId },
                text,
            },
        });

    private static byte[] CallbackJson(string data, long chatId, long messageId) =>
        JsonSerializer.SerializeToUtf8Bytes(new
        {
            update_id = 1,
            callback_query = new
            {
                id = "callback-id",
                data,
                message = new
                {
                    message_id = messageId,
                    chat = new { id = chatId },
                },
            },
        });
}
