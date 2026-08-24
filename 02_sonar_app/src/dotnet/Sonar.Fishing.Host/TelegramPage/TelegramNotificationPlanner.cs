using System.Globalization;
using System.Text;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Presentation;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed record TelegramPlayerStatusSnapshot(
    int? Food,
    int? Water,
    int? Health,
    double? InventoryWeight,
    double? InventoryWeightMax,
    double? BackpackWeight,
    double? BackpackWeightMax);

public sealed record TelegramCatchNotification(
    string FishName,
    double? WeightKg,
    string? QualityText,
    int? XpCurrent,
    int? XpTotal,
    bool? Released,
    FishingSessionTotalsSnapshot Totals,
    bool PreferPhoto);

public sealed record TelegramNotificationPlan(
    string Html,
    bool Silent,
    bool IncludeMenuButton,
    bool PreferPhoto);

public static class TelegramNotificationPlanner
{
    public static TelegramNotificationPlan? PlanCatch(
        TelegramHostSettings settings,
        TelegramCatchNotification notification)
    {
        ArgumentNullException.ThrowIfNull(settings);
        ArgumentNullException.ThrowIfNull(notification);
        ArgumentNullException.ThrowIfNull(notification.Totals);
        if (!settings.Notifications.Catch)
        {
            return null;
        }
        var quality = notification.QualityText?.Trim() ?? string.Empty;
        var lines = new List<string>();
        if (string.Equals(quality, "трофейная", StringComparison.OrdinalIgnoreCase))
        {
            lines.Add($"🏆 <b>{Html(quality)}!</b>");
            lines.Add(string.Empty);
        }
        lines.Add(
            $"🐟 <b>{Html(notification.FishName)}</b> - " +
            FishingValueFormatter.Weight(notification.WeightKg ?? 0));
        if (notification.Released is { } released)
        {
            lines.Add($"🌊 <b>Статус:</b> {(released ? "отпущена" : "оставлена")}");
        }
        lines.Add(string.Empty);
        var keptCount = Math.Max(0, notification.Totals.CaughtCount - notification.Totals.ReleasedCount);
        var keptKg = Math.Max(0, notification.Totals.CaughtKg - notification.Totals.ReleasedKg);
        lines.Add(
            $"📦 <b>Оставлено:</b> {FishingValueFormatter.Weight(keptKg)} · {Invariant(keptCount)} выловов");
        lines.Add(
            $"📦 <b>Всего:</b> {FishingValueFormatter.Weight(notification.Totals.CaughtKg)} · " +
            $"{Invariant(notification.Totals.CaughtCount)} выловов");
        lines.Add($"💰 <b>Доход:</b> от {FishingValueFormatter.Money(notification.Totals.EarnedMin)}");
        if (notification.XpCurrent is { } xpCurrent)
        {
            lines.Add(notification.XpTotal is { } xpTotal
                ? $"⭐ <b>Опыт:</b> {Invariant(xpCurrent)} / {Invariant(xpTotal)}"
                : $"⭐ <b>Опыт:</b> {Invariant(xpCurrent)}");
        }
        return new TelegramNotificationPlan(
            string.Join('\n', lines),
            !settings.Sounds.Catch,
            IncludeMenuButton: false,
            notification.PreferPhoto);
    }

    public static TelegramNotificationPlan? PlanFishingStarted(
        TelegramHostSettings settings,
        FishingSessionStateSnapshot session,
        bool hasStatistics)
    {
        ArgumentNullException.ThrowIfNull(settings);
        ArgumentNullException.ThrowIfNull(session);
        if (!settings.Notifications.StartStop)
        {
            return null;
        }
        var text = hasStatistics
            ? FormatSessionStatistics(
                "🚤 Рыбалка началась!",
                "📊 Текущая сессия",
                session.Totals)
            : "🚤 <b>Рыбалка началась!</b>\n\n🎣 Удочка закинута, ждём улов...";
        return new TelegramNotificationPlan(
            text,
            !settings.Sounds.StartStop,
            IncludeMenuButton: true,
            PreferPhoto: false);
    }

    public static TelegramNotificationPlan? PlanFishingStopped(
        TelegramHostSettings settings,
        FishingSessionStateSnapshot session,
        string? reason,
        bool preferPhoto)
    {
        ArgumentNullException.ThrowIfNull(settings);
        ArgumentNullException.ThrowIfNull(session);
        if (!settings.Notifications.StartStop)
        {
            return null;
        }
        return new TelegramNotificationPlan(
            FormatSessionStatistics(
                "🛑 Рыбалка остановлена!",
                "📊 Статистика сессии",
                session.Totals,
                reason),
            !settings.Sounds.StartStop,
            IncludeMenuButton: true,
            preferPhoto);
    }

    public static TelegramNotificationPlan? PlanInventorySpaceLow(
        TelegramHostSettings settings,
        double freeKg,
        double thresholdKg,
        TelegramPlayerStatusSnapshot? playerStatus)
    {
        ArgumentNullException.ThrowIfNull(settings);
        ValidateWeight(freeKg, nameof(freeKg));
        ValidateWeight(thresholdKg, nameof(thresholdKg));
        if (!settings.Notifications.InventorySpaceLow)
        {
            return null;
        }
        var lines = new List<string>
        {
            "⚖️ <b>Мало места в инвентаре</b>",
            string.Empty,
            $"Свободно: <b>{StatusWeightNumber(freeKg)}</b> кг",
            $"Порог: <b>{StatusWeightNumber(thresholdKg)}</b> кг",
        };
        if (playerStatus is not null)
        {
            var inventory = StatusWeight(playerStatus.InventoryWeight, playerStatus.InventoryWeightMax);
            var backpack = StatusWeight(playerStatus.BackpackWeight, playerStatus.BackpackWeightMax);
            if (inventory.Length != 0)
            {
                lines.Add($"🎒 Инвентарь: {inventory} кг");
            }
            if (backpack.Length != 0)
            {
                lines.Add($"🧳 Рюкзак: {backpack} кг");
            }
        }
        return new TelegramNotificationPlan(
            string.Join('\n', lines),
            !settings.Sounds.InventorySpaceLow,
            IncludeMenuButton: false,
            PreferPhoto: false);
    }

    public static TelegramNotificationPlan? PlanMealEnded(TelegramHostSettings settings) =>
        Simple(
            settings.Notifications.Meal,
            settings.Sounds.Meal,
            "🍽 <b>Эффект еды закончился</b>");

    public static TelegramNotificationPlan? PlanInventoryFull(TelegramHostSettings settings) =>
        Simple(
            settings.Notifications.InventoryFull,
            settings.Sounds.InventoryFull,
            "📦 <b>Закончилось место!</b>");

    public static TelegramNotificationPlan? PlanBaitTired(TelegramHostSettings settings) =>
        Simple(
            settings.Notifications.BaitTired,
            settings.Sounds.BaitTired,
            "<b>Рыба устала от приманки</b>\nИсправляем");

    public static TelegramNotificationPlan? PlanFocusLost(TelegramHostSettings settings) =>
        Simple(
            settings.Notifications.FocusLost,
            settings.Sounds.FocusLost,
            "⚠️🎮 <b>Фокус ушёл с игры</b>\n\n" +
            "Ввод поставлен на паузу. Переключитесь на окно игры, чтобы продолжить.");

    public static TelegramNotificationPlan? PlanFishingFailed(TelegramHostSettings settings) =>
        Simple(
            settings.Notifications.StartStop,
            settings.Sounds.StartStop,
            "⚠️ <b>Не удалось восстановить рыбалку</b>");

    public static TelegramNotificationPlan PlanAppStarted() => new(
        "<b>Sonar запущен</b>",
        Silent: false,
        IncludeMenuButton: false,
        PreferPhoto: false);

    public static TelegramNotificationPlan PlanAppStopped() => new(
        "<b>Sonar выключен</b>",
        Silent: false,
        IncludeMenuButton: false,
        PreferPhoto: false);

    public static string FormatPlayerStatus(
        TelegramPlayerStatusSnapshot? status,
        string title = "📊 <b>Показатели игрока</b>")
    {
        if (status is null)
        {
            return "📊 Показатели игрока\n\nПоследнего сканирования ещё нет.";
        }
        var lines = new List<string> { title, string.Empty };
        if (status.Food is { } food)
        {
            lines.Add($"🍗 Еда: <b>{Invariant(food)}%</b>");
        }
        if (status.Water is { } water)
        {
            lines.Add($"💧 Вода: <b>{Invariant(water)}%</b>");
        }
        if (status.Health is { } health)
        {
            lines.Add($"❤️ HP: <b>{Invariant(health)}%</b>");
        }
        var inventory = StatusWeight(status.InventoryWeight, status.InventoryWeightMax);
        var backpack = StatusWeight(status.BackpackWeight, status.BackpackWeightMax);
        if (inventory.Length != 0)
        {
            lines.Add($"🎒 Инвентарь: <b>{inventory}</b> кг");
        }
        if (backpack.Length != 0)
        {
            lines.Add($"🧳 Рюкзак: <b>{backpack}</b> кг");
        }
        if (lines.Count == 2)
        {
            lines.Add("Данных пока нет.");
        }
        return string.Join('\n', lines);
    }

    public static string FormatSessionStatistics(
        string title,
        string subtitle,
        FishingSessionTotalsSnapshot totals,
        string? reason = null,
        IReadOnlyList<FishingSessionFishRowSnapshot>? rows = null)
    {
        ArgumentNullException.ThrowIfNull(title);
        ArgumentNullException.ThrowIfNull(subtitle);
        ArgumentNullException.ThrowIfNull(totals);
        var lines = new List<string>
        {
            $"<b>{Html(title)}</b>",
            string.Empty,
            $"<b>{Html(subtitle)}</b>",
            string.Empty,
        };
        if (!string.IsNullOrEmpty(reason))
        {
            lines.Add($"<b>Причина остановки:</b> {Html(reason)}");
            lines.Add(string.Empty);
        }
        var keptKg = Math.Max(0, totals.CaughtKg - totals.ReleasedKg);
        var perHourMin = totals.DurationSeconds <= 0
            ? 0
            : totals.EarnedMin / (totals.DurationSeconds / 3600);
        var perHourMax = totals.DurationSeconds <= 0
            ? 0
            : totals.EarnedMax / (totals.DurationSeconds / 3600);
        lines.Add($"⏱ Длительность: {FishingValueFormatter.Duration(totals.DurationSeconds)}");
        lines.Add($"🎣 Поймано: {FishingValueFormatter.CatchSummary(totals.CaughtCount, totals.CaughtKg)}");
        lines.Add($"🌊 Отпущено: {FishingValueFormatter.CatchSummary(totals.ReleasedCount, totals.ReleasedKg)}");
        lines.Add($"⚖️ Общий вес: {FishingValueFormatter.Weight(keptKg)}");
        lines.Add($"💰 Доход: {FishingValueFormatter.MoneyRange(totals.EarnedMin, totals.EarnedMax)}");
        lines.Add($"📈 Доход в час: {FishingValueFormatter.MoneyRange(perHourMin, perHourMax)}");
        if (rows is { Count: > 0 })
        {
            lines.AddRange([string.Empty, "➖➖➖➖➖➖➖➖➖", string.Empty, "🐟 Улов по видам", string.Empty]);
            foreach (var row in rows)
            {
                lines.Add($"• <b>{Html(row.Name)}</b>");
                lines.Add($"  🎣 Поймано: {FishingValueFormatter.CatchSummary(row.CaughtCount, row.CaughtKg)}");
                lines.Add($"  🌊 Отпущено: {FishingValueFormatter.CatchSummary(row.ReleasedCount, row.ReleasedKg)}");
                lines.Add($"  💰 Доход: {FishingValueFormatter.MoneyRange(row.EarnedMin, row.EarnedMax)}");
                lines.Add(string.Empty);
            }
            while (lines.Count != 0 && lines[^1].Length == 0)
            {
                lines.RemoveAt(lines.Count - 1);
            }
        }
        return string.Join('\n', lines);
    }

    private static TelegramNotificationPlan? Simple(
        bool enabled,
        bool soundEnabled,
        string html) => enabled
            ? new TelegramNotificationPlan(
                html,
                !soundEnabled,
                IncludeMenuButton: false,
                PreferPhoto: false)
            : null;

    private static string StatusWeight(double? current, double? maximum)
    {
        if (current is null && maximum is null)
        {
            return string.Empty;
        }
        if (current is null)
        {
            return $"- / {StatusWeightNumber(maximum)}";
        }
        if (maximum is null)
        {
            return StatusWeightNumber(current);
        }
        return $"{StatusWeightNumber(current)} / {StatusWeightNumber(maximum)}";
    }

    private static string StatusWeightNumber(double? value)
    {
        if (value is null)
        {
            return "-";
        }
        ValidateWeight(value.Value, nameof(value));
        return value.Value.ToString("0.##", CultureInfo.InvariantCulture);
    }

    private static void ValidateWeight(double value, string parameterName)
    {
        if (!double.IsFinite(value) || value < 0)
        {
            throw new ArgumentOutOfRangeException(parameterName);
        }
    }

    private static string Html(string value) => value
        .Replace("&", "&amp;", StringComparison.Ordinal)
        .Replace("<", "&lt;", StringComparison.Ordinal)
        .Replace(">", "&gt;", StringComparison.Ordinal);

    private static string Invariant(int value) => value.ToString(CultureInfo.InvariantCulture);
}
