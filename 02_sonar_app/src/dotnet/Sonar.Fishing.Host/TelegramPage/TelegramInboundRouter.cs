using System.Globalization;
using System.Text.Json;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public enum TelegramInboundIntentKind
{
    Ignore = 0,
    AcknowledgeOnly = 1,
    ShowMainMenu = 2,
    ShowNotifications = 3,
    ShowStatistics = 4,
    ShowTackle = 5,
    ShowPlayerStatus = 6,
    ScanPlayerStatus = 7,
    SendScreenshot = 8,
    ShutdownPc = 9,
    ShutdownGame = 10,
    ShowStream = 11,
    ShowStreamQuality = 12,
    ToggleNotification = 13,
    ToggleNotificationSound = 14,
    SetStreamQuality = 15,
    ToggleStream = 16,
    OpenStream = 17,
    SwitchStreamArea = 18,
    SwitchStreamMode = 19,
    ToggleFishing = 20,
    FocusGame = 21,
}

public sealed record TelegramInboundDecision(
    TelegramInboundIntentKind Kind,
    long ChatId = 0,
    long? MessageId = null,
    string CallbackId = "",
    TelegramNotificationKind? Notification = null,
    string Value = "")
{
    public static TelegramInboundDecision Ignored { get; } = new(
        TelegramInboundIntentKind.Ignore);

    public bool RequiresCallbackAnswer => CallbackId.Length != 0;
}

public sealed class TelegramInboundRouter
{
    private const int MaximumUpdateBytes = 64 * 1024;

    public TelegramInboundDecision RouteJson(
        ReadOnlySpan<byte> utf8Json,
        bool runtimeEnabled,
        TelegramHostSettings settings)
    {
        ArgumentNullException.ThrowIfNull(settings);
        if (!runtimeEnabled || !settings.Enabled ||
            utf8Json.Length is 0 or > MaximumUpdateBytes)
        {
            return TelegramInboundDecision.Ignored;
        }

        try
        {
            using var document = JsonDocument.Parse(utf8Json.ToArray(), new JsonDocumentOptions
            {
                AllowTrailingCommas = false,
                CommentHandling = JsonCommentHandling.Disallow,
                MaxDepth = 16,
            });
            if (document.RootElement.ValueKind != JsonValueKind.Object)
            {
                return TelegramInboundDecision.Ignored;
            }
            var root = document.RootElement;
            if (root.TryGetProperty("message", out var message) &&
                message.ValueKind == JsonValueKind.Object)
            {
                return RouteMessage(message, settings);
            }
            if (root.TryGetProperty("callback_query", out var callback) &&
                callback.ValueKind == JsonValueKind.Object)
            {
                return RouteCallback(callback, settings);
            }
        }
        catch (JsonException)
        {
        }
        return TelegramInboundDecision.Ignored;
    }

    private static TelegramInboundDecision RouteMessage(
        JsonElement message,
        TelegramHostSettings settings)
    {
        if (!TryReadNestedChatId(message, out var chatId) || !IsAdmin(chatId, settings))
        {
            return TelegramInboundDecision.Ignored;
        }
        var text = ReadString(message, "text");
        var parts = text.Split((char[]?)null, StringSplitOptions.RemoveEmptyEntries);
        if (parts.Length == 0)
        {
            return TelegramInboundDecision.Ignored;
        }
        var command = parts[0].ToLowerInvariant();
        var kind = command switch
        {
            "/menu" => TelegramInboundIntentKind.ShowMainMenu,
            "/notifications" => TelegramInboundIntentKind.ShowNotifications,
            "/stats" => TelegramInboundIntentKind.ShowStatistics,
            "/tackle" => TelegramInboundIntentKind.ShowTackle,
            "/status" => TelegramInboundIntentKind.ShowPlayerStatus,
            "/scan_status" => TelegramInboundIntentKind.ScanPlayerStatus,
            "/screen" => TelegramInboundIntentKind.SendScreenshot,
            "/shutdown_pc" => TelegramInboundIntentKind.ShutdownPc,
            "/shutdown_game" => TelegramInboundIntentKind.ShutdownGame,
            _ => TelegramInboundIntentKind.Ignore,
        };
        return kind == TelegramInboundIntentKind.Ignore
            ? TelegramInboundDecision.Ignored
            : new TelegramInboundDecision(kind, chatId);
    }

    private static TelegramInboundDecision RouteCallback(
        JsonElement callback,
        TelegramHostSettings settings)
    {
        if (!callback.TryGetProperty("message", out var message) ||
            message.ValueKind != JsonValueKind.Object ||
            !TryReadNestedChatId(message, out var chatId) ||
            !IsAdmin(chatId, settings))
        {
            return TelegramInboundDecision.Ignored;
        }
        long? messageId = TryReadInt64(message, "message_id", out var rawMessageId) && rawMessageId != 0
            ? rawMessageId
            : null;
        var callbackId = ReadString(callback, "id");
        var data = ReadString(callback, "data");
        var decision = RouteCallbackData(data, chatId, messageId, callbackId);
        return decision;
    }

    private static TelegramInboundDecision RouteCallbackData(
        string data,
        long chatId,
        long? messageId,
        string callbackId)
    {
        TelegramInboundDecision Decision(
            TelegramInboundIntentKind kind,
            TelegramNotificationKind? notification = null,
            string value = "") => new(
                kind,
                chatId,
                messageId,
                callbackId,
                notification,
                value);

        if (data == "menu:main:new")
        {
            return Decision(TelegramInboundIntentKind.ShowMainMenu) with { MessageId = null };
        }
        if (data == "menu:main")
        {
            return Decision(TelegramInboundIntentKind.ShowMainMenu);
        }
        if (data == "menu:notifications")
        {
            return Decision(TelegramInboundIntentKind.ShowNotifications);
        }
        if (data == "menu:stream")
        {
            return Decision(TelegramInboundIntentKind.ShowStream);
        }
        if (data == "menu:stream_quality")
        {
            return Decision(TelegramInboundIntentKind.ShowStreamQuality);
        }
        if (data.StartsWith("toggle:", StringComparison.Ordinal))
        {
            return TelegramNotificationCatalog.TryFindNotificationField(
                data["toggle:".Length..],
                out var notification)
                ? Decision(TelegramInboundIntentKind.ToggleNotification, notification)
                : Decision(TelegramInboundIntentKind.ShowNotifications);
        }
        if (data.StartsWith("toggle_sound:", StringComparison.Ordinal))
        {
            return TelegramNotificationCatalog.TryFindSoundField(
                data["toggle_sound:".Length..],
                out var notification)
                ? Decision(TelegramInboundIntentKind.ToggleNotificationSound, notification)
                : Decision(TelegramInboundIntentKind.ShowNotifications);
        }
        if (data.StartsWith("stream:quality:", StringComparison.Ordinal))
        {
            return Decision(
                TelegramInboundIntentKind.SetStreamQuality,
                value: data["stream:quality:".Length..]);
        }
        return data switch
        {
            "stream:start_stop" => Decision(TelegramInboundIntentKind.ToggleStream),
            "stream:open" => Decision(TelegramInboundIntentKind.OpenStream) with { MessageId = null },
            "stream:switch_area" => Decision(TelegramInboundIntentKind.SwitchStreamArea),
            "stream:switch_mode" => Decision(TelegramInboundIntentKind.SwitchStreamMode),
            "action:start_stop" => Decision(TelegramInboundIntentKind.ToggleFishing) with { MessageId = null },
            "action:screen" => Decision(TelegramInboundIntentKind.SendScreenshot) with { MessageId = null },
            "action:focus_game" => Decision(TelegramInboundIntentKind.FocusGame) with { MessageId = null },
            "action:stats" => Decision(TelegramInboundIntentKind.ShowStatistics) with { MessageId = null },
            "action:tackle" => Decision(TelegramInboundIntentKind.ShowTackle) with { MessageId = null },
            "action:player_status" => Decision(TelegramInboundIntentKind.ShowPlayerStatus) with { MessageId = null },
            "action:scan_player_status" => Decision(TelegramInboundIntentKind.ScanPlayerStatus) with { MessageId = null },
            "action:shutdown_pc" => Decision(TelegramInboundIntentKind.ShutdownPc) with { MessageId = null },
            "action:shutdown_game" => Decision(TelegramInboundIntentKind.ShutdownGame) with { MessageId = null },
            _ => Decision(TelegramInboundIntentKind.AcknowledgeOnly),
        };
    }

    private static bool IsAdmin(long chatId, TelegramHostSettings settings) =>
        chatId != 0 && settings.AdminIds.Contains(chatId);

    private static bool TryReadNestedChatId(JsonElement message, out long chatId)
    {
        if (message.TryGetProperty("chat", out var chat) &&
            chat.ValueKind == JsonValueKind.Object &&
            TryReadInt64(chat, "id", out chatId))
        {
            return true;
        }
        chatId = 0;
        return false;
    }

    private static bool TryReadInt64(
        JsonElement source,
        string propertyName,
        out long value)
    {
        if (source.TryGetProperty(propertyName, out var property))
        {
            if (property.ValueKind == JsonValueKind.Number && property.TryGetInt64(out value))
            {
                return true;
            }
            if (property.ValueKind == JsonValueKind.String &&
                long.TryParse(
                    property.GetString(),
                    NumberStyles.Integer,
                    CultureInfo.InvariantCulture,
                    out value))
            {
                return true;
            }
        }
        value = 0;
        return false;
    }

    private static string ReadString(JsonElement source, string propertyName) =>
        source.TryGetProperty(propertyName, out var property) &&
        property.ValueKind == JsonValueKind.String
            ? property.GetString() ?? string.Empty
            : string.Empty;
}
