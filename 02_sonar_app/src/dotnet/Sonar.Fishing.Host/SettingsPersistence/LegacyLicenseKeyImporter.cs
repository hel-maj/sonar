using System.IO;
using System.Text.Json;
using Sonar.Fishing.Host.UpdateRuntime;

namespace Sonar.Fishing.Host.SettingsPersistence;

internal sealed record LegacyLicenseImportResult(bool Changed, string Status);

internal static class LegacyLicenseKeyImporter
{
    private const int MaximumSourceBytes = 64 * 1024;
    private static readonly HashSet<string> AllowedProperties = new(StringComparer.Ordinal)
    {
        "license_key",
        "license_id",
        "last_validated_at",
        "expires_at",
        "role",
        "group",
        "features",
        "denied_features",
    };

    internal static LegacyLicenseImportResult Import(
        string legacyLicenseSettingsPath,
        string installRoot,
        ISecretProtector protector,
        bool dryRun = false)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(legacyLicenseSettingsPath);
        ArgumentException.ThrowIfNullOrWhiteSpace(installRoot);
        ArgumentNullException.ThrowIfNull(protector);

        var source = Path.GetFullPath(legacyLicenseSettingsPath);
        if (!File.Exists(source) ||
            !string.Equals(
                Path.GetFileName(source),
                "license_settings.json",
                StringComparison.OrdinalIgnoreCase) ||
            (File.GetAttributes(source) & FileAttributes.ReparsePoint) != 0)
        {
            throw new InvalidOperationException("legacy_license_source_invalid");
        }
        var sourceBytes = File.ReadAllBytes(source);
        if (sourceBytes.Length is 0 or > MaximumSourceBytes)
        {
            throw new InvalidOperationException("legacy_license_source_size_invalid");
        }

        string licenseKey;
        try
        {
            using var document = JsonDocument.Parse(sourceBytes, new JsonDocumentOptions
            {
                AllowTrailingCommas = false,
                CommentHandling = JsonCommentHandling.Disallow,
                MaxDepth = 8,
            });
            if (document.RootElement.ValueKind != JsonValueKind.Object)
            {
                throw new InvalidOperationException("legacy_license_contract_invalid");
            }
            var seen = new HashSet<string>(StringComparer.Ordinal);
            foreach (var property in document.RootElement.EnumerateObject())
            {
                if (!AllowedProperties.Contains(property.Name) || !seen.Add(property.Name))
                {
                    throw new InvalidOperationException("legacy_license_contract_invalid");
                }
            }
            if (!document.RootElement.TryGetProperty("license_key", out var keyElement) ||
                keyElement.ValueKind != JsonValueKind.String)
            {
                throw new InvalidOperationException("legacy_license_key_missing");
            }
            licenseKey = keyElement.GetString()?.Trim() ?? string.Empty;
        }
        catch (JsonException exception)
        {
            throw new InvalidOperationException("legacy_license_json_invalid", exception);
        }

        if (licenseKey.Length is 0 or > 256 || licenseKey.Any(char.IsControl))
        {
            throw new InvalidOperationException("legacy_license_key_invalid");
        }

        var root = ReleaseInstallLayout.ValidateSteadyState(installRoot);
        var config = Path.Combine(root, "config");
        var store = new FishingStateStore(config, protector);
        var state = File.Exists(store.StatePath)
            ? store.Load()
            : FishingHostState.Default;
        if (state.Secrets.LicenseKey.Length != 0)
        {
            if (!string.Equals(
                    state.Secrets.LicenseKey,
                    licenseKey,
                    StringComparison.Ordinal))
            {
                throw new InvalidOperationException("legacy_license_target_already_configured");
            }
            return new LegacyLicenseImportResult(false, "legacy_license_already_imported");
        }
        if (dryRun)
        {
            return new LegacyLicenseImportResult(false, "legacy_license_import_ready");
        }

        Directory.CreateDirectory(config);
        store.Save(state with
        {
            License = LicenseHostSettings.Default,
            Secrets = state.Secrets with
            {
                LicenseKey = licenseKey,
                SignedLicenseCache = string.Empty,
            },
        });
        var verified = store.Load();
        if (!string.Equals(verified.Secrets.LicenseKey, licenseKey, StringComparison.Ordinal) ||
            verified.Secrets.SignedLicenseCache.Length != 0 ||
            verified.License.LicenseId.Length != 0 ||
            verified.License.LastValidatedAt.Length != 0 ||
            verified.License.ExpiresAt.Length != 0 ||
            verified.License.Features.Count != 0 ||
            verified.License.DeniedFeatures.Count != 0)
        {
            throw new InvalidOperationException("legacy_license_import_verification_failed");
        }
        return new LegacyLicenseImportResult(true, "legacy_license_imported");
    }
}
