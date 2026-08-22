using System.Buffers.Binary;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace Sonar.Fishing.Host.SettingsPersistence;

public sealed class FishingStateStore
{
    private const int ContainerVersion = 1;
    private const int CurrentSchemaVersion = 2;
    private const int HeaderLength = 8 + sizeof(int) + sizeof(int) + 32;
    private const int MaximumPayloadBytes = 1024 * 1024;
    private static readonly byte[] Magic = "SONARFS1"u8.ToArray();
    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        PropertyNameCaseInsensitive = false,
        UnmappedMemberHandling = JsonUnmappedMemberHandling.Disallow,
        MaxDepth = 32,
    };

    private readonly ISecretProtector secretProtector;

    public FishingStateStore(string configDirectory, ISecretProtector secretProtector)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(configDirectory);
        this.secretProtector = secretProtector ?? throw new ArgumentNullException(nameof(secretProtector));
        ConfigDirectory = Path.GetFullPath(configDirectory);
        StatePath = Path.Combine(ConfigDirectory, "state.dat");
        PendingPath = Path.Combine(ConfigDirectory, "state.dat.pending");
    }

    public string ConfigDirectory { get; }

    public string StatePath { get; }

    public string PendingPath { get; }

    public FishingHostState Load()
    {
        Directory.CreateDirectory(ConfigDirectory);
        RecoverPendingWrite();
        if (!File.Exists(StatePath))
        {
            throw new FileNotFoundException("Fishing state.dat is missing.", StatePath);
        }
        return ReadState(StatePath);
    }

    public FishingHostState LoadOrCreate(FishingHostState? initialState = null)
    {
        Directory.CreateDirectory(ConfigDirectory);
        RecoverPendingWrite();
        if (File.Exists(StatePath))
        {
            return ReadState(StatePath);
        }
        var state = initialState ?? FishingHostState.Default;
        Save(state);
        return ReadState(StatePath);
    }

    public void Save(FishingHostState state)
    {
        ArgumentNullException.ThrowIfNull(state);
        state.Validate();
        Directory.CreateDirectory(ConfigDirectory);
        RecoverPendingWrite();
        var bytes = Encode(state);
        using (var stream = new FileStream(
            PendingPath,
            FileMode.CreateNew,
            FileAccess.Write,
            FileShare.None,
            bufferSize: 64 * 1024,
            FileOptions.WriteThrough))
        {
            stream.Write(bytes);
            stream.Flush(flushToDisk: true);
        }
        File.Move(PendingPath, StatePath, overwrite: true);
    }

    private byte[] Encode(FishingHostState state)
    {
        var secretBytes = JsonSerializer.SerializeToUtf8Bytes(
            SecretDocument.FromState(state.Secrets),
            JsonOptions);
        byte[] protectedSecrets;
        try
        {
            protectedSecrets = secretProtector.Protect(secretBytes);
        }
        finally
        {
            CryptographicOperations.ZeroMemory(secretBytes);
        }
        if (protectedSecrets.Length == 0)
        {
            throw new CryptographicException("protected_secrets_empty");
        }

        var document = StateDocument.FromState(state, protectedSecrets);
        var payload = JsonSerializer.SerializeToUtf8Bytes(document, JsonOptions);
        if (payload.Length is 0 or > MaximumPayloadBytes)
        {
            throw new InvalidDataException("state_payload_size_invalid");
        }
        var output = new byte[checked(HeaderLength + payload.Length)];
        Magic.CopyTo(output, 0);
        BinaryPrimitives.WriteInt32LittleEndian(output.AsSpan(8, sizeof(int)), ContainerVersion);
        BinaryPrimitives.WriteInt32LittleEndian(output.AsSpan(12, sizeof(int)), payload.Length);
        SHA256.HashData(payload, output.AsSpan(16, 32));
        payload.CopyTo(output.AsSpan(HeaderLength));
        return output;
    }

    private FishingHostState ReadState(string path)
    {
        var file = new FileInfo(path);
        if (!file.Exists || file.Length < HeaderLength ||
            file.Length > HeaderLength + MaximumPayloadBytes)
        {
            throw new InvalidDataException("state_container_size_invalid");
        }
        var bytes = File.ReadAllBytes(path);
        if (!bytes.AsSpan(0, Magic.Length).SequenceEqual(Magic))
        {
            throw new InvalidDataException("state_magic_invalid");
        }
        var version = BinaryPrimitives.ReadInt32LittleEndian(bytes.AsSpan(8, sizeof(int)));
        if (version != ContainerVersion)
        {
            throw new InvalidDataException("state_container_version_invalid");
        }
        var payloadLength = BinaryPrimitives.ReadInt32LittleEndian(bytes.AsSpan(12, sizeof(int)));
        if (payloadLength is <= 0 or > MaximumPayloadBytes ||
            bytes.Length != HeaderLength + payloadLength)
        {
            throw new InvalidDataException("state_payload_length_invalid");
        }
        var payload = bytes.AsSpan(HeaderLength, payloadLength);
        Span<byte> actualHash = stackalloc byte[32];
        SHA256.HashData(payload, actualHash);
        if (!CryptographicOperations.FixedTimeEquals(actualHash, bytes.AsSpan(16, 32)))
        {
            throw new InvalidDataException("state_payload_hash_invalid");
        }
        var document = JsonSerializer.Deserialize<StateDocument>(payload, JsonOptions)
            ?? throw new InvalidDataException("state_document_missing");
        if (document.SchemaVersion is < 1 or > CurrentSchemaVersion ||
            document.ProtectedSecrets is null ||
            document.ProtectedSecrets.Length == 0)
        {
            throw new InvalidDataException("state_schema_invalid");
        }
        var secretBytes = secretProtector.Unprotect(document.ProtectedSecrets);
        try
        {
            var secrets = JsonSerializer.Deserialize<SecretDocument>(secretBytes, JsonOptions)
                ?? throw new InvalidDataException("state_secrets_missing");
            var state = document.ToState(secrets);
            state.Validate();
            return state;
        }
        finally
        {
            CryptographicOperations.ZeroMemory(secretBytes);
        }
    }

    private void RecoverPendingWrite()
    {
        if (!File.Exists(PendingPath))
        {
            return;
        }

        var pending = TryRead(PendingPath);
        var current = File.Exists(StatePath) ? TryRead(StatePath) : null;
        if (pending is not null &&
            (current is null || pending.Fishing.Revision > current.Fishing.Revision))
        {
            File.Move(PendingPath, StatePath, overwrite: true);
            return;
        }
        if (current is not null)
        {
            File.Delete(PendingPath);
            return;
        }
        throw new InvalidDataException("state_recovery_failed");
    }

    private FishingHostState? TryRead(string path)
    {
        try
        {
            return ReadState(path);
        }
        catch (Exception error) when (error is IOException or UnauthorizedAccessException or
            InvalidDataException or JsonException or CryptographicException)
        {
            return null;
        }
    }

    private sealed class StateDocument
    {
        public int SchemaVersion { get; set; }
        public FishingDocument? Fishing { get; set; }
        public TelegramDocument? Telegram { get; set; }
        public LicenseDocument? License { get; set; }
        public byte[]? ProtectedSecrets { get; set; }

        public static StateDocument FromState(FishingHostState state, byte[] protectedSecrets) => new()
        {
            SchemaVersion = CurrentSchemaVersion,
            Fishing = FishingDocument.FromState(state.Fishing),
            Telegram = TelegramDocument.FromState(state.Telegram),
            License = LicenseDocument.FromState(state.License),
            ProtectedSecrets = protectedSecrets,
        };

        public FishingHostState ToState(SecretDocument secrets) => new(
            (Fishing ?? throw new InvalidDataException("state_fishing_missing")).ToState(),
            (Telegram ?? throw new InvalidDataException("state_telegram_missing")).ToState(),
            (License ?? throw new InvalidDataException("state_license_missing")).ToState(),
            secrets.ToState());
    }

    private sealed class FishingDocument
    {
        public ulong Revision { get; set; }
        public RecoveryThresholds? Thresholds { get; set; }
        public FishingBehaviorPolicy? Behavior { get; set; }
        public FishingHotkeys? Hotkeys { get; set; }
        public SortedDictionary<string, bool>? FishKeep { get; set; }
        public SortedDictionary<string, bool>? GarbageDisposal { get; set; }
        public SortedDictionary<string, double>? CustomFishPrices { get; set; }

        public static FishingDocument FromState(FishingRuntimeSettings settings) => new()
        {
            Revision = settings.Revision,
            Thresholds = settings.Thresholds,
            Behavior = settings.Behavior,
            Hotkeys = settings.Hotkeys,
            FishKeep = new SortedDictionary<string, bool>(
                settings.Selection.FishKeep.ToDictionary(
                    pair => pair.Key,
                    pair => pair.Value,
                    StringComparer.Ordinal),
                StringComparer.Ordinal),
            GarbageDisposal = new SortedDictionary<string, bool>(
                settings.Selection.GarbageDisposal.ToDictionary(
                    pair => pair.Key,
                    pair => pair.Value,
                    StringComparer.Ordinal),
                StringComparer.Ordinal),
            CustomFishPrices = new SortedDictionary<string, double>(
                settings.Selection.CustomFishPrices.ToDictionary(
                    pair => pair.Key,
                    pair => pair.Value,
                    StringComparer.Ordinal),
                StringComparer.Ordinal),
        };

        public FishingRuntimeSettings ToState() => new(
            Revision,
            Thresholds ?? throw new InvalidDataException("state_thresholds_missing"),
            Behavior ?? throw new InvalidDataException("state_behavior_missing"),
            Hotkeys ?? throw new InvalidDataException("state_hotkeys_missing"),
            new FishingSelectionPolicy(
                FishKeep ?? throw new InvalidDataException("state_fish_policy_missing"),
                GarbageDisposal ?? throw new InvalidDataException("state_garbage_policy_missing"),
                CustomFishPrices ?? throw new InvalidDataException("state_prices_missing")));
    }

    private sealed class TelegramDocument
    {
        public bool Enabled { get; set; }
        public long[]? AdminIds { get; set; }
        public double InventorySpaceLowThresholdKg { get; set; }
        public TelegramNotificationSettings? Notifications { get; set; }
        public TelegramSoundSettings? Sounds { get; set; }

        public static TelegramDocument FromState(TelegramHostSettings settings) => new()
        {
            Enabled = settings.Enabled,
            AdminIds = settings.AdminIds.ToArray(),
            InventorySpaceLowThresholdKg = settings.InventorySpaceLowThresholdKg,
            Notifications = settings.Notifications,
            Sounds = settings.Sounds,
        };

        public TelegramHostSettings ToState() => new(
            Enabled,
            AdminIds ?? throw new InvalidDataException("state_telegram_admins_missing"),
            InventorySpaceLowThresholdKg,
            Notifications ?? throw new InvalidDataException("state_telegram_notifications_missing"),
            Sounds ?? TelegramSoundSettings.AllEnabled);
    }

    private sealed class LicenseDocument
    {
        public string? LicenseId { get; set; }
        public string? LastValidatedAt { get; set; }
        public string? ExpiresAt { get; set; }
        public string? Role { get; set; }
        public string? Group { get; set; }
        public string[]? Features { get; set; }
        public string[]? DeniedFeatures { get; set; }

        public static LicenseDocument FromState(LicenseHostSettings settings) => new()
        {
            LicenseId = settings.LicenseId,
            LastValidatedAt = settings.LastValidatedAt,
            ExpiresAt = settings.ExpiresAt,
            Role = settings.Role,
            Group = settings.Group,
            Features = settings.Features.ToArray(),
            DeniedFeatures = settings.DeniedFeatures.ToArray(),
        };

        public LicenseHostSettings ToState() => new(
            LicenseId ?? string.Empty,
            LastValidatedAt ?? string.Empty,
            ExpiresAt ?? string.Empty,
            Role ?? "user",
            Group ?? "legacy",
            Array.AsReadOnly(Features ?? []),
            Array.AsReadOnly(DeniedFeatures ?? []));
    }

    private sealed class SecretDocument
    {
        public string? TelegramBotToken { get; set; }
        public string? LicenseKey { get; set; }

        public string? SignedLicenseCache { get; set; }

        public static SecretDocument FromState(SensitiveHostSettings settings) => new()
        {
            TelegramBotToken = settings.TelegramBotToken,
            LicenseKey = settings.LicenseKey,
            SignedLicenseCache = settings.SignedLicenseCache,
        };

        public SensitiveHostSettings ToState() => new(
            TelegramBotToken ?? string.Empty,
            LicenseKey ?? string.Empty,
            SignedLicenseCache ?? string.Empty);
    }
}
