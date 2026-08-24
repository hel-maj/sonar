using System.Buffers.Binary;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.Tests;

internal static class FishingStateStoreTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("state_dat_round_trip_protects_secrets", RoundTripProtectsSecrets),
        new("state_dat_hash_corruption_fails_closed", HashCorruptionFailsClosed),
        new("state_dat_recovers_newer_complete_pending_write", NewerPendingWriteIsRecovered),
        new("state_dat_discards_invalid_pending_when_current_is_valid", InvalidPendingIsDiscarded),
        new("state_snapshot_defensively_freezes_product_policies", ProductPoliciesAreFrozen),
        new("state_dat_round_trips_telegram_sound_policy", TelegramSoundsRoundTrip),
        new("state_dat_schema_v1_defaults_telegram_sound_policy", SchemaV1DefaultsTelegramSounds),
        new("dpapi_current_user_secret_round_trip", DpapiRoundTrip),
        new("legacy_json_settings_migrate_once_into_state_dat", LegacyJsonMigration),
        new("legacy_json_inventory_hotkey_preserves_nonempty_value", LegacyInventoryHotkeyIsPreserved),
        new("host_startup_owns_exact_config_state_dat_path", HostStartupOwnsExactStatePath),
        new("host_startup_error_hides_internal_storage_path", HostStartupErrorHidesInternalPath),
        new("state_coordinator_serializes_custom_price_revision", CoordinatorSerializesCustomPrice),
        new("state_coordinator_serializes_stream_mode_revision", CoordinatorSerializesStreamMode),
    ];

    private static void RoundTripProtectsSecrets()
    {
        using var sandbox = new TemporaryDirectory();
        var store = new FishingStateStore(sandbox.Path, new TestSecretProtector());
        var state = CreateState(1, "telegram-secret", "license-secret");

        store.Save(state);
        var bytes = File.ReadAllBytes(store.StatePath);
        var visible = Encoding.UTF8.GetString(bytes);
        TestAssert.True(!visible.Contains("telegram-secret", StringComparison.Ordinal), "Telegram token leaked into state.dat");
        TestAssert.True(!visible.Contains("license-secret", StringComparison.Ordinal), "License key leaked into state.dat");

        var loaded = store.Load();
        TestAssert.Equal("telegram-secret", loaded.Secrets.TelegramBotToken, "Telegram token did not round trip");
        TestAssert.Equal("license-secret", loaded.Secrets.LicenseKey, "License key did not round trip");
        TestAssert.Equal<ulong>(1, loaded.Fishing.Revision, "Settings revision changed");
    }

    private static void HashCorruptionFailsClosed()
    {
        using var sandbox = new TemporaryDirectory();
        var store = new FishingStateStore(sandbox.Path, new TestSecretProtector());
        store.Save(CreateState(1, "token", "key"));
        var bytes = File.ReadAllBytes(store.StatePath);
        bytes[^1] ^= 0x7f;
        File.WriteAllBytes(store.StatePath, bytes);

        TestAssert.Throws<InvalidDataException>(
            () => store.Load(),
            "Corrupted state.dat was accepted");
    }

    private static void NewerPendingWriteIsRecovered()
    {
        using var sandbox = new TemporaryDirectory();
        using var newerSandbox = new TemporaryDirectory();
        var protector = new TestSecretProtector();
        var store = new FishingStateStore(sandbox.Path, protector);
        var newerStore = new FishingStateStore(newerSandbox.Path, protector);
        store.Save(CreateState(1, "old", "old-key"));
        newerStore.Save(CreateState(2, "new", "new-key"));
        File.Copy(newerStore.StatePath, store.PendingPath);

        var recovered = store.Load();
        TestAssert.Equal<ulong>(2, recovered.Fishing.Revision, "Newer pending revision was not promoted");
        TestAssert.Equal("new", recovered.Secrets.TelegramBotToken, "Recovered pending data changed");
        TestAssert.True(!File.Exists(store.PendingPath), "Pending file remained after recovery");
    }

    private static void InvalidPendingIsDiscarded()
    {
        using var sandbox = new TemporaryDirectory();
        var store = new FishingStateStore(sandbox.Path, new TestSecretProtector());
        store.Save(CreateState(3, "valid", "valid-key"));
        File.WriteAllText(store.PendingPath, "incomplete");

        var loaded = store.Load();
        TestAssert.Equal<ulong>(3, loaded.Fishing.Revision, "Valid current state was lost");
        TestAssert.True(!File.Exists(store.PendingPath), "Invalid pending file was not removed");
    }

    private static void ProductPoliciesAreFrozen()
    {
        var fish = new Dictionary<string, bool> { ["marlin"] = true };
        var policy = new FishingSelectionPolicy(
            fish,
            new Dictionary<string, bool> { ["bag"] = true },
            Array.Empty<KeyValuePair<string, double>>());
        fish["marlin"] = false;

        TestAssert.True(policy.FishKeep["marlin"], "Caller mutation changed immutable settings");
        TestAssert.Throws<NotSupportedException>(
            () => ((IDictionary<string, bool>)policy.FishKeep)["marlin"] = false,
            "Read-only settings policy allowed mutation");
    }

    private static void TelegramSoundsRoundTrip()
    {
        using var sandbox = new TemporaryDirectory();
        var store = new FishingStateStore(sandbox.Path, new TestSecretProtector());
        var telegram = new TelegramHostSettings(
            false,
            [42],
            2.5,
            TelegramHostSettings.Default.Notifications,
            TelegramSoundSettings.AllEnabled with
            {
                Catch = false,
                FocusLost = false,
            });
        var state = new FishingHostState(
            FishingRuntimeSettings.CreateDefault(),
            telegram,
            LicenseHostSettings.Default,
            new SensitiveHostSettings("fake-token", string.Empty));

        store.Save(state);
        var loaded = store.Load();

        TestAssert.True(!loaded.Telegram.Sounds.Catch, "Catch sound policy changed");
        TestAssert.True(!loaded.Telegram.Sounds.FocusLost, "Focus sound policy changed");
        TestAssert.True(loaded.Telegram.Sounds.Meal, "Unchanged sound policy changed");
    }

    private static void SchemaV1DefaultsTelegramSounds()
    {
        const int headerLength = 8 + sizeof(int) + sizeof(int) + 32;
        using var sandbox = new TemporaryDirectory();
        var store = new FishingStateStore(sandbox.Path, new TestSecretProtector());
        store.Save(CreateState(1, "fake-token", string.Empty));
        var bytes = File.ReadAllBytes(store.StatePath);
        var document = JsonNode.Parse(bytes.AsSpan(headerLength))!.AsObject();
        document["schemaVersion"] = 1;
        document["telegram"]!.AsObject().Remove("sounds");
        var payload = JsonSerializer.SerializeToUtf8Bytes(document);
        var schemaV1 = new byte[headerLength + payload.Length];
        bytes.AsSpan(0, 12).CopyTo(schemaV1);
        BinaryPrimitives.WriteInt32LittleEndian(schemaV1.AsSpan(12, sizeof(int)), payload.Length);
        SHA256.HashData(payload, schemaV1.AsSpan(16, 32));
        payload.CopyTo(schemaV1.AsSpan(headerLength));
        File.WriteAllBytes(store.StatePath, schemaV1);

        var loaded = store.Load();

        TestAssert.Equal(
            TelegramSoundSettings.AllEnabled,
            loaded.Telegram.Sounds,
            "Schema-v1 Telegram sounds did not use legacy all-enabled defaults");
    }

    private static void DpapiRoundTrip()
    {
        var protector = new DpapiCurrentUserSecretProtector();
        var plaintext = Encoding.UTF8.GetBytes($"fishing-dpapi-{Guid.NewGuid():N}");
        var encrypted = protector.Protect(plaintext);
        TestAssert.True(!encrypted.SequenceEqual(plaintext), "DPAPI returned plaintext bytes");
        var roundTrip = protector.Unprotect(encrypted);
        TestAssert.True(roundTrip.SequenceEqual(plaintext), "DPAPI round trip changed secret bytes");
    }

    private static void LegacyJsonMigration()
    {
        using var sandbox = new TemporaryDirectory();
        File.WriteAllText(
            System.IO.Path.Combine(sandbox.Path, "fishing_settings.json"),
            """
            {
              "restore_food_from": 12,
              "restore_water_from": "91",
              "restore_health_from": 50,
              "overweight_action": "release",
              "food_depleted_action": "shutdown_pc",
              "hotkey": "ctrl+F10",
              "fish_settings": { "marlin": false },
              "garbage_settings": { "bag": true },
              "custom_fish_prices": { "marlin": "701.5", "bad": "x" }
            }
            """);
        File.WriteAllText(
            System.IO.Path.Combine(sandbox.Path, "telegram_settings.json"),
            """
            {
              "enabled": true,
              "bot_token": "telegram-legacy-secret",
              "admin_ids": "42, broken, 77",
              "inventory_space_low_threshold_kg": "0,5",
              "sound_catch": false,
              "sound_focus_lost": false
            }
            """);
        File.WriteAllText(
            System.IO.Path.Combine(sandbox.Path, "license_settings.json"),
            """
            {
              "license_key": "license-legacy-secret",
              "license_id": "license-id",
              "role": "admin",
              "features": "fishing;stream"
            }
            """);
        var store = new FishingStateStore(sandbox.Path, new TestSecretProtector());
        var migrated = new LegacyJsonSettingsMigrator(sandbox.Path)
            .LoadMigrateOrCreate(store);

        TestAssert.Equal(12, migrated.Fishing.Thresholds.Food, "Food threshold migration changed");
        TestAssert.Equal(90, migrated.Fishing.Thresholds.Water, "Water threshold was not clamped");
        TestAssert.Equal(1, migrated.Fishing.Thresholds.Health, "Legacy health reconstruction changed");
        TestAssert.Equal(OverweightPolicyAction.Release, migrated.Fishing.Behavior.OverweightAction, "Overweight action changed");
        TestAssert.Equal(FoodDepletedPolicyAction.ShutdownPc, migrated.Fishing.Behavior.FoodDepletedAction, "Food action changed");
        TestAssert.Equal("Tab", migrated.Fishing.Hotkeys.Inventory,
            "Missing legacy inventory hotkey did not use the confirmed production fallback");
        TestAssert.True(!migrated.Fishing.Selection.FishKeep["marlin"], "Fish policy changed");
        TestAssert.Equal(701.5, migrated.Fishing.Selection.CustomFishPrices["marlin"], "Custom price changed");
        TestAssert.True(!migrated.Fishing.Selection.CustomFishPrices.ContainsKey("bad"), "Invalid custom price migrated");
        TestAssert.Equal("telegram-legacy-secret", migrated.Secrets.TelegramBotToken, "Telegram secret changed");
        TestAssert.True(!migrated.Telegram.Sounds.Catch, "Legacy catch sound policy changed");
        TestAssert.True(!migrated.Telegram.Sounds.FocusLost, "Legacy focus sound policy changed");
        TestAssert.True(migrated.Telegram.Sounds.Meal, "Legacy default sound policy changed");
        TestAssert.Equal("license-legacy-secret", migrated.Secrets.LicenseKey, "License secret changed");
        TestAssert.Equal(string.Empty, migrated.License.LicenseId,
            "Unsigned legacy license id became current authority");
        TestAssert.True(migrated.License.Features.Count == 0,
            "Unsigned legacy feature list became current authority");
        TestAssert.True(File.Exists(store.StatePath), "state.dat was not created");
        TestAssert.True(
            !Directory.EnumerateFiles(sandbox.Path, "*_settings.json").Any(),
            "Legacy JSON files remained after verified migration");
    }

    private static void LegacyInventoryHotkeyIsPreserved()
    {
        using var sandbox = new TemporaryDirectory();
        File.WriteAllText(
            System.IO.Path.Combine(sandbox.Path, "fishing_settings.json"),
            """
            {
              "inventory_hotkey": "i"
            }
            """);
        var store = new FishingStateStore(sandbox.Path, new TestSecretProtector());

        var migrated = new LegacyJsonSettingsMigrator(sandbox.Path)
            .LoadMigrateOrCreate(store);

        TestAssert.Equal("i", migrated.Fishing.Hotkeys.Inventory,
            "Valid nonempty legacy inventory hotkey was overwritten by the new fallback");
    }

    private static void HostStartupOwnsExactStatePath()
    {
        using var sandbox = new TemporaryDirectory();
        var state = HostStateBootstrap.LoadForApplicationDirectory(
            sandbox.Path,
            new TestSecretProtector());
        var configDirectory = System.IO.Path.Combine(sandbox.Path, "config");

        TestAssert.Equal<ulong>(1, state.Fishing.Revision, "Startup default revision changed");
        TestAssert.True(
            File.Exists(System.IO.Path.Combine(configDirectory, "state.dat")),
            "Host startup did not create exact config/state.dat");
        TestAssert.True(
            Directory.EnumerateFileSystemEntries(configDirectory)
                .Select(System.IO.Path.GetFileName)
                .SequenceEqual(["state.dat"], StringComparer.Ordinal),
            "Host startup created a loose config dependency");
    }

    private static void HostStartupErrorHidesInternalPath()
    {
        using var sandbox = new TemporaryDirectory();
        var invalidApplicationRoot = System.IO.Path.Combine(sandbox.Path, "not-a-directory");
        File.WriteAllText(invalidApplicationRoot, "occupied");

        try
        {
            HostStateBootstrap.LoadForApplicationDirectory(invalidApplicationRoot);
            throw new InvalidOperationException("Invalid application root was accepted");
        }
        catch (HostStateStartupException exception)
        {
            TestAssert.True(
                !exception.Message.Contains("state.dat", StringComparison.OrdinalIgnoreCase) &&
                !exception.Message.Contains("config", StringComparison.OrdinalIgnoreCase),
                "Startup dialog exposed the internal settings path");
            TestAssert.True(
                exception.Message.Contains("настройки приложения", StringComparison.OrdinalIgnoreCase),
                "Startup dialog did not identify the affected user data");
        }
    }

    private static void CoordinatorSerializesCustomPrice()
    {
        using var sandbox = new TemporaryDirectory();
        var store = new FishingStateStore(sandbox.Path, new TestSecretProtector());
        store.Save(CreateState(4, string.Empty, string.Empty));
        var coordinator = new HostStateCoordinator(store, store.Load());
        var notifications = 0;
        coordinator.StateChanged += _ => notifications++;

        var accepted = coordinator.UpdateCustomFishPrice("marlin", 701);
        TestAssert.Equal<ulong>(5, accepted.Revision, "Custom price did not advance the settings revision once");
        TestAssert.Equal(701d, store.Load().Fishing.Selection.CustomFishPrices["marlin"], "Custom price was not persisted atomically");

        accepted = coordinator.UpdateCustomFishPrice("marlin", 0);
        TestAssert.Equal<ulong>(6, accepted.Revision, "Custom price removal did not advance revision once");
        TestAssert.True(!store.Load().Fishing.Selection.CustomFishPrices.ContainsKey("marlin"), "Zero custom price was persisted");
        TestAssert.Equal(2, notifications, "State observers did not receive exact accepted commits");
        TestAssert.Throws<InvalidOperationException>(
            () => coordinator.SaveFishing(FishingRuntimeSettings.CreateDefault(revision: 5)),
            "Stale settings overwrote a newer custom price revision");
    }

    private static void CoordinatorSerializesStreamMode()
    {
        using var sandbox = new TemporaryDirectory();
        var store = new FishingStateStore(sandbox.Path, new TestSecretProtector());
        store.Save(CreateState(8, string.Empty, string.Empty));
        var coordinator = new HostStateCoordinator(store, store.Load());

        var accepted = coordinator.UpdateStreamSnapshotMode(enabled: true);

        TestAssert.Equal<ulong>(9, accepted.Revision, "Stream mode did not advance the settings revision once");
        TestAssert.True(accepted.Behavior.StreamSnapshotMode, "Accepted stream mode changed");
        var persisted = store.Load().Fishing;
        TestAssert.Equal<ulong>(9, persisted.Revision, "Stream mode revision was not persisted atomically");
        TestAssert.True(persisted.Behavior.StreamSnapshotMode, "Stream mode was not persisted atomically");
    }

    private static FishingHostState CreateState(ulong revision, string telegramToken, string licenseKey) => new(
        FishingRuntimeSettings.CreateDefault(revision),
        TelegramHostSettings.Default,
        LicenseHostSettings.Default,
        new SensitiveHostSettings(telegramToken, licenseKey));

    private sealed class TestSecretProtector : ISecretProtector
    {
        private const byte Mask = 0xa5;

        public byte[] Protect(ReadOnlySpan<byte> plaintext) => Transform(plaintext);

        public byte[] Unprotect(ReadOnlySpan<byte> protectedData) => Transform(protectedData);

        private static byte[] Transform(ReadOnlySpan<byte> value)
        {
            var result = value.ToArray();
            for (var index = 0; index < result.Length; index++)
            {
                result[index] ^= Mask;
            }
            return result;
        }
    }

    private sealed class TemporaryDirectory : IDisposable
    {
        public TemporaryDirectory()
        {
            Path = System.IO.Path.Combine(
                System.IO.Path.GetTempPath(),
                $"sonar-fishing-state-tests-{Guid.NewGuid():N}");
            Directory.CreateDirectory(Path);
        }

        public string Path { get; }

        public void Dispose()
        {
            Directory.Delete(Path, recursive: true);
        }
    }
}
