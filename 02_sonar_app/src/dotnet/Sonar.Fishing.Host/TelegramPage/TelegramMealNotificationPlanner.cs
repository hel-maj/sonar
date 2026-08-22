using System.Collections.ObjectModel;
using System.Globalization;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed class TelegramMealEffectSnapshot
{
    private readonly ReadOnlyCollection<string> parameterModifications;

    public TelegramMealEffectSnapshot(
        string name,
        string? duration,
        string? description,
        IEnumerable<string>? parameterModifications = null)
    {
        ArgumentNullException.ThrowIfNull(name);
        Name = name;
        Duration = duration;
        Description = description;
        this.parameterModifications = Array.AsReadOnly(
            (parameterModifications ?? []).ToArray());
    }

    public string Name { get; }

    public string? Duration { get; }

    public string? Description { get; }

    public IReadOnlyList<string> ParameterModifications => parameterModifications;
}

public sealed class TelegramMealItemInfoSnapshot
{
    private readonly ReadOnlyCollection<TelegramMealEffectSnapshot> effects;
    private readonly ReadOnlyCollection<string> parameterModifications;

    public TelegramMealItemInfoSnapshot(
        string? ItemName,
        string? Title,
        string? Weight,
        string? SatietyChange,
        string? ThirstChange,
        string? ConditionPercent,
        string? PoisonChance,
        string? Strength,
        IEnumerable<TelegramMealEffectSnapshot>? Effects = null,
        IEnumerable<string>? ParameterModifications = null)
    {
        this.ItemName = ItemName;
        this.Title = Title;
        this.Weight = Weight;
        this.SatietyChange = SatietyChange;
        this.ThirstChange = ThirstChange;
        this.ConditionPercent = ConditionPercent;
        this.PoisonChance = PoisonChance;
        this.Strength = Strength;
        effects = Array.AsReadOnly((Effects ?? []).ToArray());
        parameterModifications = Array.AsReadOnly((ParameterModifications ?? []).ToArray());
    }

    public string? ItemName { get; }

    public string? Title { get; }

    public string? Weight { get; }

    public string? SatietyChange { get; }

    public string? ThirstChange { get; }

    public string? ConditionPercent { get; }

    public string? PoisonChance { get; }

    public string? Strength { get; }

    public IReadOnlyList<TelegramMealEffectSnapshot> Effects => effects;

    public IReadOnlyList<string> ParameterModifications => parameterModifications;
}

public static class TelegramMealNotificationPlanner
{
    public static TelegramNotificationPlan? Plan(
        TelegramHostSettings settings,
        string itemName,
        TelegramMealItemInfoSnapshot? itemInfo,
        TelegramPlayerStatusSnapshot? playerStatus)
    {
        ArgumentNullException.ThrowIfNull(settings);
        ArgumentNullException.ThrowIfNull(itemName);
        if (!settings.Notifications.Meal)
        {
            return null;
        }

        var title = NonEmpty(itemInfo?.ItemName) ??
            NonEmpty(itemInfo?.Title) ??
            NonEmpty(itemName) ??
            "еда";
        var lines = new List<string>
        {
            "🍽 <b>Питание использовано!</b>",
            string.Empty,
            $"🥪 <b>Съедено:</b> {Html(title)}",
        };
        if (itemInfo is not null)
        {
            Append(lines, "⚖️ <b>Вес:</b>", itemInfo.Weight, " кг");
            Append(lines, "🍗 <b>Сытость:</b>", itemInfo.SatietyChange);
            Append(lines, "💧 <b>Жажда:</b>", itemInfo.ThirstChange);
            Append(lines, "🛡 <b>Состояние:</b>", itemInfo.ConditionPercent, "%");
            Append(lines, "🧪 <b>Шанс отравления:</b>", itemInfo.PoisonChance);
            Append(lines, "🧰 <b>Прочность:</b>", itemInfo.Strength);
            if (itemInfo.Effects.Count > 0)
            {
                lines.AddRange([string.Empty, "✨ <b>Эффекты</b>"]);
                foreach (var effect in itemInfo.Effects)
                {
                    var duration = NonEmpty(effect.Duration) is { } value
                        ? $" - ⏳ {Html(value)}"
                        : string.Empty;
                    lines.Add($"• <b>{Html(effect.Name)}</b>{duration}");
                    if (NonEmpty(effect.Description) is { } description)
                    {
                        lines.Add($"  <i>{Html(description)}</i>");
                    }
                    foreach (var modification in effect.ParameterModifications)
                    {
                        lines.Add($"  <code>{Html(modification)}</code>");
                    }
                }
            }
            else if (itemInfo.ParameterModifications.Count > 0)
            {
                lines.AddRange([string.Empty, "🧩 <b>Модификации параметров</b>"]);
                foreach (var modification in itemInfo.ParameterModifications)
                {
                    lines.Add($"• <code>{Html(modification)}</code>");
                }
            }
        }

        if (playerStatus is not null)
        {
            var statusLines = BuildStatusLines(playerStatus);
            if (statusLines.Count > 0)
            {
                lines.AddRange([string.Empty, "📊 <b>Показатели</b>"]);
                lines.AddRange(statusLines);
            }
        }
        return new TelegramNotificationPlan(
            string.Join('\n', lines),
            Silent: !settings.Sounds.Meal,
            IncludeMenuButton: false,
            PreferPhoto: false);
    }

    private static List<string> BuildStatusLines(TelegramPlayerStatusSnapshot status)
    {
        var lines = new List<string>();
        if (status.Food is { } food)
        {
            lines.Add($"🍗 <b>Еда:</b> {food.ToString(CultureInfo.InvariantCulture)}%");
        }
        if (status.Water is { } water)
        {
            lines.Add($"💧 <b>Вода:</b> {water.ToString(CultureInfo.InvariantCulture)}%");
        }
        if (status.Health is { } health)
        {
            lines.Add($"❤️ <b>Здоровье:</b> {health.ToString(CultureInfo.InvariantCulture)}%");
        }
        AppendWeight(lines, "🎒 <b>Инвентарь:</b>", status.InventoryWeight, status.InventoryWeightMax);
        AppendWeight(lines, "🎒 <b>Рюкзак:</b>", status.BackpackWeight, status.BackpackWeightMax);
        return lines;
    }

    private static void Append(
        ICollection<string> lines,
        string label,
        string? value,
        string suffix = "")
    {
        if (NonEmpty(value) is { } present)
        {
            lines.Add($"{label} {Html(present)}{suffix}");
        }
    }

    private static void AppendWeight(
        ICollection<string> lines,
        string label,
        double? current,
        double? maximum)
    {
        var value = FormatWeight(current, maximum);
        if (value.Length > 0)
        {
            lines.Add($"{label} {value} кг");
        }
    }

    private static string FormatWeight(double? current, double? maximum)
    {
        ValidateWeight(current);
        ValidateWeight(maximum);
        if (current is null && maximum is null)
        {
            return string.Empty;
        }
        if (current is null)
        {
            return $"- / {FormatNumber(maximum!.Value)}";
        }
        if (maximum is null)
        {
            return FormatNumber(current.Value);
        }
        return $"{FormatNumber(current.Value)} / {FormatNumber(maximum.Value)}";
    }

    private static void ValidateWeight(double? value)
    {
        if (value is { } present && (!double.IsFinite(present) || present < 0))
        {
            throw new ArgumentOutOfRangeException(nameof(value));
        }
    }

    private static string FormatNumber(double value) =>
        value.ToString("0.##", CultureInfo.InvariantCulture);

    private static string? NonEmpty(string? value) =>
        string.IsNullOrWhiteSpace(value) ? null : value.Trim();

    private static string Html(string value) => value
        .Replace("&", "&amp;", StringComparison.Ordinal)
        .Replace("<", "&lt;", StringComparison.Ordinal)
        .Replace(">", "&gt;", StringComparison.Ordinal);
}
