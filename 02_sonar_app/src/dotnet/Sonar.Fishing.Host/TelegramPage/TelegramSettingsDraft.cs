using System.Collections.ObjectModel;
using System.Globalization;
using System.Text.RegularExpressions;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed partial class TelegramSettingsDraft
{
    private readonly ReadOnlyCollection<long> adminIds;

    private TelegramSettingsDraft(
        bool enabled,
        string botToken,
        IEnumerable<long> adminIds,
        double inventorySpaceLowThresholdKg,
        TelegramNotificationSettings notifications,
        TelegramSoundSettings sounds)
    {
        ArgumentNullException.ThrowIfNull(botToken);
        ArgumentNullException.ThrowIfNull(adminIds);
        ArgumentNullException.ThrowIfNull(notifications);
        ArgumentNullException.ThrowIfNull(sounds);
        Enabled = enabled;
        BotToken = botToken.Trim();
        this.adminIds = Array.AsReadOnly(adminIds.Distinct().ToArray());
        InventorySpaceLowThresholdKg = NormalizeThreshold(inventorySpaceLowThresholdKg);
        Notifications = notifications;
        Sounds = sounds;
    }

    public bool Enabled { get; }

    public string BotToken { get; }

    public IReadOnlyList<long> AdminIds => adminIds;

    public string AdminIdsText => string.Join(',', AdminIds);

    public double InventorySpaceLowThresholdKg { get; }

    public string InventorySpaceLowThresholdText =>
        InventorySpaceLowThresholdKg.ToString("F2", CultureInfo.InvariantCulture);

    public TelegramNotificationSettings Notifications { get; }

    public TelegramSoundSettings Sounds { get; }

    public bool ConfigurationReady => BotToken.Length != 0 && AdminIds.Count != 0;

    public int EnabledNotificationCount => new[]
    {
        Notifications.Catch,
        Notifications.StartStop,
        Notifications.Meal,
        Notifications.InventoryFull,
        Notifications.InventorySpaceLow,
        Notifications.BaitTired,
        Notifications.FocusLost,
    }.Count(value => value);

    public static TelegramSettingsDraft FromSettings(
        TelegramHostSettings settings,
        string botToken)
    {
        ArgumentNullException.ThrowIfNull(settings);
        return new TelegramSettingsDraft(
            settings.Enabled && !string.IsNullOrWhiteSpace(botToken) && settings.AdminIds.Count != 0,
            botToken,
            settings.AdminIds,
            settings.InventorySpaceLowThresholdKg,
            settings.Notifications,
            settings.Sounds);
    }

    public TelegramSettingsDraft WithCredentials(
        string botToken,
        string adminIdsText)
    {
        ArgumentNullException.ThrowIfNull(botToken);
        ArgumentNullException.ThrowIfNull(adminIdsText);
        if (Enabled)
        {
            throw new InvalidOperationException("telegram_credentials_locked");
        }
        return Copy(
            botToken: botToken,
            adminIds: ParseAdminIds(adminIdsText));
    }

    public TelegramSettingsDraft WithEnabled(bool enabled) => Copy(enabled: enabled);

    public TelegramSettingsDraft WithNotifications(
        TelegramNotificationSettings notifications)
    {
        ArgumentNullException.ThrowIfNull(notifications);
        return Copy(notifications: notifications);
    }

    public TelegramSettingsDraft WithInventorySpaceLowThreshold(string value)
    {
        ArgumentNullException.ThrowIfNull(value);
        return Copy(inventorySpaceLowThresholdKg: ParseThreshold(value));
    }

    public TelegramSettingsDraft WithSounds(TelegramSoundSettings sounds)
    {
        ArgumentNullException.ThrowIfNull(sounds);
        return Copy(sounds: sounds);
    }

    public TelegramHostSettings BuildSettings(bool enabled) => new(
        enabled,
        AdminIds,
        InventorySpaceLowThresholdKg,
        Notifications,
        Sounds);

    public bool ContentEquals(TelegramSettingsDraft other)
    {
        ArgumentNullException.ThrowIfNull(other);
        return Enabled == other.Enabled &&
            string.Equals(BotToken, other.BotToken, StringComparison.Ordinal) &&
            AdminIds.SequenceEqual(other.AdminIds) &&
            InventorySpaceLowThresholdKg.Equals(other.InventorySpaceLowThresholdKg) &&
            Notifications == other.Notifications &&
            Sounds == other.Sounds;
    }

    public static bool IsThresholdTextAccepted(string value) =>
        value is not null && ThresholdPattern().IsMatch(value);

    public static IReadOnlyList<long> ParseAdminIds(string value)
    {
        ArgumentNullException.ThrowIfNull(value);
        var result = new List<long>();
        foreach (var item in value.Split(',', StringSplitOptions.TrimEntries))
        {
            if (item.Length == 0 || item.Any(character => character is < '0' or > '9'))
            {
                continue;
            }
            if (long.TryParse(item, NumberStyles.None, CultureInfo.InvariantCulture, out var id))
            {
                result.Add(id);
            }
        }
        return Array.AsReadOnly(result.Distinct().ToArray());
    }

    private static double ParseThreshold(string value)
    {
        var normalized = value.Replace(',', '.');
        return double.TryParse(
            normalized,
            NumberStyles.Float,
            CultureInfo.InvariantCulture,
            out var parsed) && double.IsFinite(parsed)
            ? NormalizeThreshold(parsed)
            : 1.0;
    }

    private static double NormalizeThreshold(double value) =>
        double.IsFinite(value)
            ? Math.Max(1.0, Math.Round(value, 2, MidpointRounding.ToEven))
            : 1.0;

    private TelegramSettingsDraft Copy(
        bool? enabled = null,
        string? botToken = null,
        IEnumerable<long>? adminIds = null,
        double? inventorySpaceLowThresholdKg = null,
        TelegramNotificationSettings? notifications = null,
        TelegramSoundSettings? sounds = null) => new(
            enabled ?? Enabled,
            botToken ?? BotToken,
            adminIds ?? AdminIds,
            inventorySpaceLowThresholdKg ?? InventorySpaceLowThresholdKg,
            notifications ?? Notifications,
            sounds ?? Sounds);

    [GeneratedRegex(@"^\d{0,6}([\.,]\d{0,2})?$", RegexOptions.CultureInvariant)]
    private static partial Regex ThresholdPattern();
}
