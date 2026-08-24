using System.Globalization;
using System.IO;
using System.Text.Json;

namespace Sonar.Fishing.Host.SettingsPersistence;

public sealed class LegacyJsonSettingsMigrator
{
    private readonly string fishingPath;
    private readonly string telegramPath;
    private readonly string licensePath;

    public LegacyJsonSettingsMigrator(string configDirectory)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(configDirectory);
        var root = Path.GetFullPath(configDirectory);
        fishingPath = Path.Combine(root, "fishing_settings.json");
        telegramPath = Path.Combine(root, "telegram_settings.json");
        licensePath = Path.Combine(root, "license_settings.json");
    }

    public FishingHostState LoadMigrateOrCreate(FishingStateStore store)
    {
        ArgumentNullException.ThrowIfNull(store);
        if (File.Exists(store.StatePath))
        {
            return store.Load();
        }

        var hasLegacyState = File.Exists(fishingPath) ||
            File.Exists(telegramPath) ||
            File.Exists(licensePath);
        if (!hasLegacyState)
        {
            return store.LoadOrCreate();
        }

        using var fishing = ReadObject(fishingPath);
        using var telegram = ReadObject(telegramPath);
        using var license = ReadObject(licensePath);
        var state = new FishingHostState(
            ImportFishing(fishing.RootElement),
            ImportTelegram(telegram.RootElement),
            ImportLicense(license.RootElement),
            new SensitiveHostSettings(
                Text(telegram.RootElement, "bot_token"),
                Text(license.RootElement, "license_key")));
        store.Save(state);
        var verified = store.Load();
        foreach (var path in new[] { fishingPath, telegramPath, licensePath })
        {
            if (File.Exists(path))
            {
                File.Delete(path);
            }
        }
        return verified;
    }

    private static FishingRuntimeSettings ImportFishing(JsonElement source)
    {
        var defaults = FishingRuntimeSettings.CreateDefault();
        var behavior = defaults.Behavior;
        return new FishingRuntimeSettings(
            Revision: 1,
            new RecoveryThresholds(
                Percent(source, "restore_food_from", 90),
                Percent(source, "restore_water_from", 90),
                HealthPercent(source)),
            new FishingBehaviorPolicy(
                Boolean(source, "auto_meal", true),
                Boolean(source, "auto_change_bait", true),
                Boolean(source, "store_in_trunk", true),
                Boolean(source, "start_stop_sound_enabled", true),
                ParseOverweight(Text(source, "overweight_action", "stop")),
                Boolean(source, "fish_without_leader", false),
                ParseDepleted(Text(source, "leader_depleted_action", "stop")),
                Boolean(source, "fish_without_net", true),
                ParseDepleted(Text(source, "net_depleted_action", "stop")),
                ParseEquipment(Text(source, "equipment_depleted_action", "stop")),
                ParseFood(Text(source, "food_depleted_action", "continue")),
                Boolean(source, "stream_snapshot_mode", false)),
            new FishingHotkeys(
                Hotkey(source, "hotkey", "F9"),
                Hotkey(source, "inventory_hotkey", "Tab"),
                Hotkey(source, "use_item_hotkey", "e"),
                Hotkey(source, "backpack_move_hotkey", "r"),
                Hotkey(source, "discard_key", "q"),
                Hotkey(source, "chat_hotkey", "t")),
            new FishingSelectionPolicy(
                BooleanMap(source, "fish_settings"),
                BooleanMap(source, "garbage_settings"),
                PriceMap(source, "custom_fish_prices")));
    }

    private static TelegramHostSettings ImportTelegram(JsonElement source)
    {
        var adminIds = new List<long>();
        if (TryProperty(source, "admin_ids", out var rawIds))
        {
            var values = rawIds.ValueKind == JsonValueKind.Array
                ? rawIds.EnumerateArray().Select(ValueText)
                : ValueText(rawIds).Split(',', StringSplitOptions.TrimEntries | StringSplitOptions.RemoveEmptyEntries);
            foreach (var value in values)
            {
                if (long.TryParse(value, NumberStyles.Integer, CultureInfo.InvariantCulture, out var id))
                {
                    adminIds.Add(id);
                }
            }
        }
        return new TelegramHostSettings(
            Boolean(source, "enabled", false),
            adminIds,
            ThresholdKg(source),
            new TelegramNotificationSettings(
                Boolean(source, "notify_catch", true),
                Boolean(source, "notify_start_stop", true),
                Boolean(source, "notify_meal", true),
                Boolean(source, "notify_inventory_full", true),
                Boolean(source, "notify_inventory_space_low", false),
                Boolean(source, "notify_bait_tired", true),
                Boolean(source, "notify_focus_lost", false)),
            new TelegramSoundSettings(
                Boolean(source, "sound_catch", true),
                Boolean(source, "sound_start_stop", true),
                Boolean(source, "sound_meal", true),
                Boolean(source, "sound_inventory_full", true),
                Boolean(source, "sound_inventory_space_low", true),
                Boolean(source, "sound_bait_tired", true),
                Boolean(source, "sound_focus_lost", true)));
    }

    // Legacy metadata was not a signed entitlement. Only the secret identifier
    // is migrated; timestamps, role, group and feature lists gain authority
    // solely after the current backend response is verified again.
    private static LicenseHostSettings ImportLicense(JsonElement source)
    {
        _ = source;
        return LicenseHostSettings.Default;
    }

    private static JsonDocument ReadObject(string path)
    {
        if (!File.Exists(path))
        {
            return JsonDocument.Parse("{}");
        }
        try
        {
            var document = JsonDocument.Parse(File.ReadAllBytes(path), new JsonDocumentOptions
            {
                AllowTrailingCommas = false,
                CommentHandling = JsonCommentHandling.Disallow,
                MaxDepth = 32,
            });
            if (document.RootElement.ValueKind == JsonValueKind.Object)
            {
                return document;
            }
            document.Dispose();
        }
        catch (JsonException)
        {
        }
        return JsonDocument.Parse("{}");
    }

    private static bool TryProperty(JsonElement source, string name, out JsonElement value)
    {
        if (source.ValueKind == JsonValueKind.Object && source.TryGetProperty(name, out value))
        {
            return true;
        }
        value = default;
        return false;
    }

    private static bool Boolean(JsonElement source, string name, bool fallback) =>
        TryProperty(source, name, out var value) ? value.ValueKind switch
        {
            JsonValueKind.True => true,
            JsonValueKind.False => false,
            JsonValueKind.Number => value.TryGetInt64(out var number) && number != 0,
            JsonValueKind.String => !string.IsNullOrEmpty(value.GetString()),
            _ => false,
        } : fallback;

    private static string Text(JsonElement source, string name, string fallback = "") =>
        TryProperty(source, name, out var value) ? ValueText(value).Trim() : fallback;

    private static string ValueText(JsonElement value) => value.ValueKind switch
    {
        JsonValueKind.String => value.GetString() ?? string.Empty,
        JsonValueKind.Number => value.GetRawText(),
        JsonValueKind.True => "true",
        JsonValueKind.False => "false",
        _ => string.Empty,
    };

    private static int Percent(JsonElement source, string name, int fallback)
    {
        var text = Text(source, name, fallback.ToString(CultureInfo.InvariantCulture));
        return int.TryParse(text, NumberStyles.Integer, CultureInfo.InvariantCulture, out var value)
            ? Math.Clamp(value, 1, 90)
            : fallback;
    }

    private static int HealthPercent(JsonElement source)
    {
        // Legacy FishingSettings.from_dict intentionally discarded the stored
        // restore_health_from value and always reconstructed the default 1.
        _ = source;
        return 1;
    }

    private static double ThresholdKg(JsonElement source)
    {
        var text = Text(source, "inventory_space_low_threshold_kg", "1.0").Replace(',', '.');
        return double.TryParse(text, NumberStyles.Float, CultureInfo.InvariantCulture, out var value) &&
            double.IsFinite(value)
            ? Math.Max(1.0, Math.Round(value, 2, MidpointRounding.ToEven))
            : 1.0;
    }

    private static string Hotkey(JsonElement source, string name, string fallback)
    {
        var value = Text(source, name, fallback);
        return HotkeyContract.IsValid(value) ? value : fallback;
    }

    private static IEnumerable<KeyValuePair<string, bool>> BooleanMap(JsonElement source, string name)
    {
        if (!TryProperty(source, name, out var value) || value.ValueKind != JsonValueKind.Object)
        {
            return Array.Empty<KeyValuePair<string, bool>>();
        }
        return value.EnumerateObject()
            .Select(property => new KeyValuePair<string, bool>(
                property.Name,
                property.Value.ValueKind switch
                {
                    JsonValueKind.True => true,
                    JsonValueKind.False => false,
                    JsonValueKind.Number => property.Value.TryGetInt64(out var number) && number != 0,
                    JsonValueKind.String => !string.IsNullOrEmpty(property.Value.GetString()),
                    _ => false,
                }))
            .ToArray();
    }

    private static IEnumerable<KeyValuePair<string, double>> PriceMap(JsonElement source, string name)
    {
        if (!TryProperty(source, name, out var value) || value.ValueKind != JsonValueKind.Object)
        {
            return Array.Empty<KeyValuePair<string, double>>();
        }
        var result = new List<KeyValuePair<string, double>>();
        foreach (var property in value.EnumerateObject())
        {
            var text = ValueText(property.Value).Replace(',', '.');
            if (double.TryParse(text, NumberStyles.Float, CultureInfo.InvariantCulture, out var price) &&
                double.IsFinite(price) && price > 0)
            {
                result.Add(new KeyValuePair<string, double>(property.Name, price));
            }
        }
        return result;
    }

    private static IReadOnlyList<string> StringList(JsonElement source, string name)
    {
        if (!TryProperty(source, name, out var value))
        {
            return Array.Empty<string>();
        }
        var values = value.ValueKind == JsonValueKind.Array
            ? value.EnumerateArray().Select(ValueText)
            : ValueText(value).Replace(';', ',').Split(',');
        return Array.AsReadOnly(values.Select(item => item.Trim()).Where(item => item.Length != 0).ToArray());
    }

    private static OverweightPolicyAction ParseOverweight(string value) => value switch
    {
        "release" => OverweightPolicyAction.Release,
        "exit_game" => OverweightPolicyAction.ExitGame,
        _ => OverweightPolicyAction.Stop,
    };

    private static DepletedPolicyAction ParseDepleted(string value) =>
        value == "exit_game" ? DepletedPolicyAction.ExitGame : DepletedPolicyAction.Stop;

    private static EquipmentDepletedPolicyAction ParseEquipment(string value) => value switch
    {
        "exit_game" => EquipmentDepletedPolicyAction.ExitGame,
        "shutdown_pc" => EquipmentDepletedPolicyAction.ShutdownPc,
        _ => EquipmentDepletedPolicyAction.Stop,
    };

    private static FoodDepletedPolicyAction ParseFood(string value) => value switch
    {
        "stop" => FoodDepletedPolicyAction.Stop,
        "exit_game" => FoodDepletedPolicyAction.ExitGame,
        "shutdown_pc" => FoodDepletedPolicyAction.ShutdownPc,
        _ => FoodDepletedPolicyAction.Continue,
    };
}
