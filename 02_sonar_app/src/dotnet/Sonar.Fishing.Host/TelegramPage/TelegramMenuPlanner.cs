using System.Collections.ObjectModel;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StreamingPage;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed record TelegramMenuButton(
    string Text,
    string CallbackData = "",
    string Url = "");

public sealed class TelegramMenuPlan
{
    private readonly ReadOnlyCollection<IReadOnlyList<TelegramMenuButton>> rows;

    public TelegramMenuPlan(
        string text,
        IEnumerable<IEnumerable<TelegramMenuButton>> rows)
    {
        ArgumentNullException.ThrowIfNull(text);
        ArgumentNullException.ThrowIfNull(rows);
        Text = text;
        this.rows = Array.AsReadOnly<IReadOnlyList<TelegramMenuButton>>(
            rows.Select(row =>
                (IReadOnlyList<TelegramMenuButton>)Array.AsReadOnly(row.ToArray()))
                .ToArray());
    }

    public string Text { get; }

    public IReadOnlyList<IReadOnlyList<TelegramMenuButton>> Rows => rows;
}

public sealed record TelegramMenuCapabilities(
    bool Fishing,
    bool Statistics,
    bool Tackle,
    bool Streaming,
    bool PlayerStatus = false,
    bool GameControl = false,
    bool SystemControl = false);

public static class TelegramMenuPlanner
{
    public static TelegramMenuPlan BuildMainMenu(
        TelegramMenuCapabilities capabilities,
        bool fishingRunning)
    {
        ArgumentNullException.ThrowIfNull(capabilities);
        var rows = new List<IReadOnlyList<TelegramMenuButton>>();
        var firstRow = new List<TelegramMenuButton>
        {
            new("🔔 Уведомления", "menu:notifications"),
        };
        if (capabilities.Statistics)
        {
            firstRow.Add(new TelegramMenuButton("📊 Статистика", "action:stats"));
        }
        rows.Add(firstRow);
        if (capabilities.Streaming)
        {
            rows.Add([new TelegramMenuButton("📺 Стрим", "menu:stream")]);
        }
        var fishingTools = new List<TelegramMenuButton>();
        if (capabilities.Tackle)
        {
            fishingTools.Add(new TelegramMenuButton("🎒 Снаряжение", "action:tackle"));
        }
        if (capabilities.PlayerStatus)
        {
            fishingTools.Add(new TelegramMenuButton("📊 Показатели", "action:player_status"));
        }
        if (fishingTools.Count > 0)
        {
            rows.Add(fishingTools);
        }
        if (capabilities.PlayerStatus)
        {
            rows.Add([new TelegramMenuButton("🔎 Просканировать показатели", "action:scan_player_status")]);
        }
        if (capabilities.Fishing)
        {
            rows.Add([
                new TelegramMenuButton(
                    fishingRunning ? "🛑 Остановить" : "🚤 Запустить",
                    "action:start_stop"),
            ]);
        }
        if (capabilities.GameControl)
        {
            rows.Add([new TelegramMenuButton("🎮 Вернуть фокус игре", "action:focus_game")]);
            rows.Add([new TelegramMenuButton("📸 Скриншот игры", "action:screen")]);
        }
        if (capabilities.GameControl && capabilities.SystemControl)
        {
            rows.Add([
                new TelegramMenuButton("🖥 Выключить ПК", "action:shutdown_pc"),
                new TelegramMenuButton("🎮 Выключить игру", "action:shutdown_game"),
            ]);
        }
        else if (capabilities.GameControl)
        {
            rows.Add([new TelegramMenuButton("🎮 Выключить игру", "action:shutdown_game")]);
        }
        else if (capabilities.SystemControl)
        {
            rows.Add([new TelegramMenuButton("🖥 Выключить ПК", "action:shutdown_pc")]);
        }
        return new TelegramMenuPlan("🎣 Меню рыболовного бота", rows);
    }

    public static TelegramMenuPlan BuildNotifications(TelegramHostSettings settings)
    {
        ArgumentNullException.ThrowIfNull(settings);
        var rows = new List<IReadOnlyList<TelegramMenuButton>>();
        foreach (var descriptor in TelegramNotificationCatalog.All)
        {
            var notifyEnabled = NotificationEnabled(settings.Notifications, descriptor.Kind);
            var soundEnabled = SoundEnabled(settings.Sounds, descriptor.Kind);
            rows.Add([
                new TelegramMenuButton(
                    $"{(notifyEnabled ? "🔔" : "🔕")} {descriptor.Label}",
                    $"toggle:{descriptor.NotificationField}"),
                new TelegramMenuButton(
                    $"{(soundEnabled ? "🔈" : "🔇")} Звук",
                    $"toggle_sound:{descriptor.SoundField}"),
            ]);
        }
        rows.Add([new TelegramMenuButton("⬅️ Меню", "menu:main")]);
        return new TelegramMenuPlan(
            "🔔 Уведомления\n\n🔔 - отправка уведомления\n🔈 - звук уведомления",
            rows);
    }

    public static TelegramMenuPlan BuildStreamQuality(string currentQuality)
    {
        currentQuality ??= string.Empty;
        return new TelegramMenuPlan(
            "⚙️ Выберите качество стрима",
            [
                new[]
                {
                    QualityButton("480p", currentQuality),
                    QualityButton("720p", currentQuality),
                    QualityButton("1080p", currentQuality),
                },
                [new TelegramMenuButton("⬅️ Назад к стриму", "menu:stream")],
            ]);
    }

    public static TelegramMenuPlan BuildStreamMenu(StreamingRuntimeSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        snapshot.Validate();
        var status = snapshot.Status switch
        {
            StreamingRuntimeStatus.Online => "🟢 online",
            StreamingRuntimeStatus.Offline => "🔴 offline",
            StreamingRuntimeStatus.Preparing => "🟡 preparing",
            StreamingRuntimeStatus.Starting => "🟡 starting",
            StreamingRuntimeStatus.Error => "🟡 error",
            _ => "🔴 unavailable",
        };
        var area = snapshot.ChatZoomEnabled ? "Чат" : "Все окно";
        var mode = snapshot.SnapshotModeEnabled ? "10fps" : "30fps";
        var lines = new List<string>
        {
            "📺 Стрим игры",
            string.Empty,
            $"• Статус: {status}",
            $"• Область: {area}",
            $"• Режим: {mode}",
            $"• Качество: {snapshot.Quality}",
        };
        if (snapshot.Active && snapshot.SecondsUntilAutoStop is { } autoStop)
        {
            var bounded = Math.Max(0, autoStop);
            lines.Add($"⏱ Автостоп: {bounded / 60}:{bounded % 60:00} без зрителей");
        }
        if (snapshot.Active && TryPublicStreamUrl(snapshot, out var publicUrl))
        {
            lines.Add($"🔗 Ссылка: {Html(publicUrl)}");
        }
        lines.AddRange([string.Empty, "Режим чата доступен на странице стрима"]);
        if (!string.IsNullOrWhiteSpace(snapshot.Error))
        {
            lines.AddRange([string.Empty, $"⚠️ {Html(snapshot.Error)}"]);
        }

        var runningOrStarting = snapshot.Active ||
            snapshot.Status is StreamingRuntimeStatus.Starting or
                StreamingRuntimeStatus.Preparing;
        var startStopText = snapshot.Status == StreamingRuntimeStatus.Starting
            ? "⏹ Остановить запуск"
            : snapshot.Active
                ? "⏹ Остановить стрим"
                : "▶️ Запустить стрим";
        var rows = new List<IReadOnlyList<TelegramMenuButton>>
        {
            new[] { new TelegramMenuButton($"⚙️ Качество: {snapshot.Quality}", "menu:stream_quality") },
            new[]
            {
                new TelegramMenuButton(
                    snapshot.SnapshotModeEnabled
                        ? "🎞 Переключить на 30fps"
                        : "🎞 Переключить на 10fps",
                    "stream:switch_mode"),
            },
            new[] { new TelegramMenuButton(startStopText, "stream:start_stop") },
        };
        if (runningOrStarting && TryPublicStreamUrl(snapshot, out publicUrl))
        {
            rows.Add([new TelegramMenuButton("🔗 Открыть стрим", Url: publicUrl)]);
        }
        if (snapshot.Active)
        {
            rows.Add([
                new TelegramMenuButton(
                    snapshot.ChatZoomEnabled
                        ? "🔎 Переключить область на окно игры"
                        : "🔎 Переключить область на Чат",
                    "stream:switch_area"),
            ]);
        }
        rows.Add([new TelegramMenuButton("⬅️ Меню", "menu:main")]);
        return new TelegramMenuPlan(string.Join('\n', lines), rows);
    }

    public static TelegramMenuPlan BuildUnavailable(string feature)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(feature);
        return new TelegramMenuPlan(
            $"⚠️ {feature} недоступен для этой подписки.",
            [[new TelegramMenuButton("⬅️ Меню", "menu:main")]]);
    }

    private static TelegramMenuButton QualityButton(
        string quality,
        string currentQuality) => new(
            $"{(string.Equals(quality, currentQuality, StringComparison.Ordinal) ? "✅ " : string.Empty)}{quality}",
            $"stream:quality:{quality}");

    private static bool NotificationEnabled(
        TelegramNotificationSettings settings,
        TelegramNotificationKind kind) => kind switch
        {
            TelegramNotificationKind.Catch => settings.Catch,
            TelegramNotificationKind.StartStop => settings.StartStop,
            TelegramNotificationKind.Meal => settings.Meal,
            TelegramNotificationKind.InventoryFull => settings.InventoryFull,
            TelegramNotificationKind.InventorySpaceLow => settings.InventorySpaceLow,
            TelegramNotificationKind.BaitTired => settings.BaitTired,
            TelegramNotificationKind.FocusLost => settings.FocusLost,
            _ => throw new ArgumentOutOfRangeException(nameof(kind)),
        };

    private static bool SoundEnabled(
        TelegramSoundSettings settings,
        TelegramNotificationKind kind) => kind switch
        {
            TelegramNotificationKind.Catch => settings.Catch,
            TelegramNotificationKind.StartStop => settings.StartStop,
            TelegramNotificationKind.Meal => settings.Meal,
            TelegramNotificationKind.InventoryFull => settings.InventoryFull,
            TelegramNotificationKind.InventorySpaceLow => settings.InventorySpaceLow,
            TelegramNotificationKind.BaitTired => settings.BaitTired,
            TelegramNotificationKind.FocusLost => settings.FocusLost,
            _ => throw new ArgumentOutOfRangeException(nameof(kind)),
        };

    private static bool TryPublicStreamUrl(
        StreamingRuntimeSnapshot snapshot,
        out string url)
    {
        foreach (var candidate in new[] { snapshot.StreamUrl, snapshot.PublicUrl })
        {
            if (Uri.TryCreate(candidate, UriKind.Absolute, out var uri) &&
                string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase))
            {
                url = uri.AbsoluteUri;
                return true;
            }
        }
        url = string.Empty;
        return false;
    }

    private static string Html(string value) => value
        .Replace("&", "&amp;", StringComparison.Ordinal)
        .Replace("<", "&lt;", StringComparison.Ordinal)
        .Replace(">", "&gt;", StringComparison.Ordinal);
}
