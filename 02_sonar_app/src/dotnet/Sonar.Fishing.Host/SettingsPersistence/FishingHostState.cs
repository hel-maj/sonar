using System.Collections.ObjectModel;
using System.IO;
using Sonar.Fishing.Host.ProductCatalog;

namespace Sonar.Fishing.Host.SettingsPersistence;

public enum OverweightPolicyAction
{
    Release = 1,
    Stop = 2,
    ExitGame = 3,
}

public enum DepletedPolicyAction
{
    Stop = 1,
    ExitGame = 2,
}

public enum EquipmentDepletedPolicyAction
{
    Stop = 1,
    ExitGame = 2,
    ShutdownPc = 3,
}

public enum FoodDepletedPolicyAction
{
    Continue = 1,
    Stop = 2,
    ExitGame = 3,
    ShutdownPc = 4,
}

public sealed record RecoveryThresholds(int Food, int Water, int Health)
{
    public void Validate()
    {
        if (Food is < 1 or > 90 || Water is < 1 or > 90 || Health is < 1 or > 90)
        {
            throw new InvalidDataException("settings_threshold_out_of_range");
        }
    }
}

public sealed record FishingBehaviorPolicy(
    bool AutoMeal,
    bool AutoChangeBait,
    bool StoreInTrunk,
    bool StartStopSoundEnabled,
    OverweightPolicyAction OverweightAction,
    bool FishWithoutLeader,
    DepletedPolicyAction LeaderDepletedAction,
    bool FishWithoutNet,
    DepletedPolicyAction NetDepletedAction,
    EquipmentDepletedPolicyAction EquipmentDepletedAction,
    FoodDepletedPolicyAction FoodDepletedAction,
    bool StreamSnapshotMode);

public sealed record FishingHotkeys(
    string StartStop,
    string Inventory,
    string UseItem,
    string BackpackMove,
    string Discard,
    string Chat)
{
    public void Validate()
    {
        foreach (var value in new[] { StartStop, Inventory, UseItem, BackpackMove, Discard, Chat })
        {
            if (!HotkeyContract.IsValid(value))
            {
                throw new InvalidDataException("settings_hotkey_invalid");
            }
        }
    }
}

public sealed class FishingSelectionPolicy
{
    private readonly ReadOnlyDictionary<string, bool> fishKeep;
    private readonly ReadOnlyDictionary<string, bool> garbageDisposal;
    private readonly ReadOnlyDictionary<string, double> customFishPrices;

    public FishingSelectionPolicy(
        IEnumerable<KeyValuePair<string, bool>> fishKeep,
        IEnumerable<KeyValuePair<string, bool>> garbageDisposal,
        IEnumerable<KeyValuePair<string, double>> customFishPrices)
    {
        ArgumentNullException.ThrowIfNull(fishKeep);
        ArgumentNullException.ThrowIfNull(garbageDisposal);
        ArgumentNullException.ThrowIfNull(customFishPrices);
        this.fishKeep = Freeze(fishKeep, ValidateIdentifier);
        this.garbageDisposal = Freeze(garbageDisposal, ValidateIdentifier);
        this.customFishPrices = Freeze(customFishPrices, pair =>
        {
            ValidateIdentifier(pair);
            if (!double.IsFinite(pair.Value) || pair.Value <= 0)
            {
                throw new InvalidDataException("settings_custom_price_invalid");
            }
        });
    }

    public IReadOnlyDictionary<string, bool> FishKeep => fishKeep;

    public IReadOnlyDictionary<string, bool> GarbageDisposal => garbageDisposal;

    public IReadOnlyDictionary<string, double> CustomFishPrices => customFishPrices;

    private static ReadOnlyDictionary<string, TValue> Freeze<TValue>(
        IEnumerable<KeyValuePair<string, TValue>> source,
        Action<KeyValuePair<string, TValue>> validate)
    {
        var result = new SortedDictionary<string, TValue>(StringComparer.Ordinal);
        foreach (var pair in source)
        {
            validate(pair);
            if (!result.TryAdd(pair.Key, pair.Value))
            {
                throw new InvalidDataException("settings_policy_duplicate_id");
            }
        }
        return new ReadOnlyDictionary<string, TValue>(result);
    }

    private static void ValidateIdentifier<TValue>(KeyValuePair<string, TValue> pair)
    {
        ArgumentNullException.ThrowIfNull(pair.Key);
        if (pair.Key.Length is 0 or > 128 || pair.Key.Any(character => character is < '!' or > '~'))
        {
            throw new InvalidDataException("settings_policy_identifier_invalid");
        }
    }
}

public sealed record FishingRuntimeSettings(
    ulong Revision,
    RecoveryThresholds Thresholds,
    FishingBehaviorPolicy Behavior,
    FishingHotkeys Hotkeys,
    FishingSelectionPolicy Selection)
{
    public void Validate()
    {
        if (Revision == 0)
        {
            throw new InvalidDataException("settings_revision_zero");
        }
        ArgumentNullException.ThrowIfNull(Thresholds);
        ArgumentNullException.ThrowIfNull(Behavior);
        ArgumentNullException.ThrowIfNull(Hotkeys);
        ArgumentNullException.ThrowIfNull(Selection);
        Thresholds.Validate();
        Hotkeys.Validate();
        if (!Enum.IsDefined(Behavior.OverweightAction) ||
            !Enum.IsDefined(Behavior.LeaderDepletedAction) ||
            !Enum.IsDefined(Behavior.NetDepletedAction) ||
            !Enum.IsDefined(Behavior.EquipmentDepletedAction) ||
            !Enum.IsDefined(Behavior.FoodDepletedAction))
        {
            throw new InvalidDataException("settings_action_invalid");
        }
    }

    public static FishingRuntimeSettings CreateDefault(ulong revision = 1) => new(
        revision,
        new RecoveryThresholds(90, 90, 1),
        new FishingBehaviorPolicy(
            AutoMeal: true,
            AutoChangeBait: true,
            StoreInTrunk: true,
            StartStopSoundEnabled: true,
            OverweightPolicyAction.Stop,
            FishWithoutLeader: false,
            DepletedPolicyAction.Stop,
            FishWithoutNet: true,
            DepletedPolicyAction.Stop,
            EquipmentDepletedPolicyAction.Stop,
            FoodDepletedPolicyAction.Continue,
            StreamSnapshotMode: false),
        new FishingHotkeys("F9", "Tab", "e", "r", "q", "t"),
        new FishingSelectionPolicy(
            FishingFishCatalog.AllIds.Select(fishId =>
                new KeyValuePair<string, bool>(fishId, true)),
            Array.Empty<KeyValuePair<string, bool>>(),
            Array.Empty<KeyValuePair<string, double>>()));
}

public sealed record TelegramNotificationSettings(
    bool Catch,
    bool StartStop,
    bool Meal,
    bool InventoryFull,
    bool InventorySpaceLow,
    bool BaitTired,
    bool FocusLost);

public sealed record TelegramSoundSettings(
    bool Catch,
    bool StartStop,
    bool Meal,
    bool InventoryFull,
    bool InventorySpaceLow,
    bool BaitTired,
    bool FocusLost)
{
    public static TelegramSoundSettings AllEnabled { get; } = new(
        true,
        true,
        true,
        true,
        true,
        true,
        true);
}

public sealed class TelegramHostSettings
{
    private readonly ReadOnlyCollection<long> adminIds;

    public TelegramHostSettings(
        bool enabled,
        IEnumerable<long> adminIds,
        double inventorySpaceLowThresholdKg,
        TelegramNotificationSettings notifications,
        TelegramSoundSettings? sounds = null)
    {
        ArgumentNullException.ThrowIfNull(adminIds);
        ArgumentNullException.ThrowIfNull(notifications);
        if (!double.IsFinite(inventorySpaceLowThresholdKg) ||
            inventorySpaceLowThresholdKg < 1.0)
        {
            throw new InvalidDataException("telegram_threshold_invalid");
        }
        Enabled = enabled;
        this.adminIds = Array.AsReadOnly(adminIds.Distinct().ToArray());
        InventorySpaceLowThresholdKg = inventorySpaceLowThresholdKg;
        Notifications = notifications;
        Sounds = sounds ?? TelegramSoundSettings.AllEnabled;
    }

    public bool Enabled { get; }

    public IReadOnlyList<long> AdminIds => adminIds;

    public double InventorySpaceLowThresholdKg { get; }

    public TelegramNotificationSettings Notifications { get; }

    public TelegramSoundSettings Sounds { get; }

    public static TelegramHostSettings Default { get; } = new(
        false,
        Array.Empty<long>(),
        1.0,
        new TelegramNotificationSettings(true, true, true, true, false, true, false),
        TelegramSoundSettings.AllEnabled);
}

public sealed record LicenseHostSettings(
    string LicenseId,
    string LastValidatedAt,
    string ExpiresAt,
    string Role,
    string Group,
    IReadOnlyList<string> Features,
    IReadOnlyList<string> DeniedFeatures)
{
    public static LicenseHostSettings Default { get; } = new(
        string.Empty,
        string.Empty,
        string.Empty,
        "user",
        "legacy",
        Array.Empty<string>(),
        Array.Empty<string>());
}

public sealed record SensitiveHostSettings(
    string TelegramBotToken,
    string LicenseKey,
    string SignedLicenseCache = "")
{
    public static SensitiveHostSettings Empty { get; } = new(
        string.Empty,
        string.Empty,
        string.Empty);
}

public sealed record FishingHostState(
    FishingRuntimeSettings Fishing,
    TelegramHostSettings Telegram,
    LicenseHostSettings License,
    SensitiveHostSettings Secrets)
{
    public void Validate()
    {
        ArgumentNullException.ThrowIfNull(Fishing);
        ArgumentNullException.ThrowIfNull(Telegram);
        ArgumentNullException.ThrowIfNull(License);
        ArgumentNullException.ThrowIfNull(Secrets);
        Fishing.Validate();
    }

    public static FishingHostState Default { get; } = new(
        FishingRuntimeSettings.CreateDefault(),
        TelegramHostSettings.Default,
        LicenseHostSettings.Default,
        SensitiveHostSettings.Empty);
}

internal static class HotkeyContract
{
    internal static bool IsValid(string value)
    {
        if (string.IsNullOrEmpty(value) || value.Length > 48 || value.Any(char.IsWhiteSpace))
        {
            return false;
        }
        var parts = value.Split('+');
        var modifiers = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
        var baseSeen = false;
        foreach (var part in parts)
        {
            if (part.Length == 0)
            {
                return false;
            }
            var lower = part.ToLowerInvariant();
            if (lower == "control")
            {
                lower = "ctrl";
            }
            if (lower is "ctrl" or "alt" or "shift")
            {
                if (baseSeen || !modifiers.Add(lower))
                {
                    return false;
                }
                continue;
            }
            if (baseSeen || !IsBaseKey(lower))
            {
                return false;
            }
            baseSeen = true;
        }
        return baseSeen;
    }

    internal static string NormalizeForComparison(string value)
    {
        if (!IsValid(value))
        {
            throw new InvalidDataException("settings_hotkey_invalid");
        }
        var modifiers = new HashSet<string>(StringComparer.Ordinal);
        string? baseKey = null;
        foreach (var part in value.Split('+'))
        {
            var lower = part.ToLowerInvariant();
            if (lower == "control")
            {
                lower = "ctrl";
            }
            if (lower is "ctrl" or "alt" or "shift")
            {
                modifiers.Add(lower);
            }
            else
            {
                baseKey = lower;
            }
        }
        var ordered = new List<string>(4);
        foreach (var modifier in new[] { "ctrl", "alt", "shift" })
        {
            if (modifiers.Contains(modifier))
            {
                ordered.Add(modifier);
            }
        }
        ordered.Add(baseKey ?? throw new InvalidDataException("settings_hotkey_invalid"));
        return string.Join('+', ordered);
    }

    private static bool IsBaseKey(string value)
    {
        if (value.Length == 1 && value[0] <= 0x7f && char.IsLetterOrDigit(value[0]))
        {
            return true;
        }
        if (value is "tab" or "backspace" or "enter" or "space")
        {
            return true;
        }
        return value.Length is 2 or 3 &&
            value[0] == 'f' &&
            int.TryParse(value.AsSpan(1), out var number) &&
            number is >= 1 and <= 24;
    }
}
