using System.Globalization;
using System.IO;
using System.Text.Json;
using Sonar.Licensing.Verification;

namespace Sonar.Fishing.Host.Licensing;

internal enum FishingKeygenLicenseError
{
    None = 0,
    TrustRootMissing,
    TransportRejected,
    ClaimsMalformed,
    ValidationRejected,
    ProductMismatch,
    MachineMismatch,
    RequiredFeatureMissing,
    LeaseInvalid,
    LeaseReplayed,
}

internal sealed record FishingKeygenLicenseClaims(
    string LicenseId,
    string PolicyId,
    string Group,
    IReadOnlySet<string> Features,
    DateTimeOffset LicenseExpiresAt,
    long LeaseExpiresUnixSeconds,
    ulong Generation);

internal sealed record FishingKeygenLicenseVerificationResult(
    FishingKeygenLicenseError Error,
    SignedResponseVerificationError TransportError,
    string ServerCode,
    string LicenseId,
    FishingKeygenLicenseClaims? Claims)
{
    internal bool Accepted => Error == FishingKeygenLicenseError.None && Claims is not null;

    internal static FishingKeygenLicenseVerificationResult Reject(
        FishingKeygenLicenseError error,
        SignedResponseVerificationError transportError = SignedResponseVerificationError.None,
        string serverCode = "",
        string licenseId = "") =>
        new(error, transportError, serverCode, licenseId, null);
}

internal sealed class FishingKeygenClaimPolicy
{
    private readonly HashSet<string> requiredFeatures;

    internal FishingKeygenClaimPolicy(
        string expectedMachineFingerprint,
        IEnumerable<string> requiredFeatures,
        ulong lastAcceptedGeneration,
        TimeSpan leaseDuration)
    {
        if (string.IsNullOrWhiteSpace(expectedMachineFingerprint) ||
            expectedMachineFingerprint.Length > 256)
        {
            throw new ArgumentException("license_machine_fingerprint_invalid", nameof(expectedMachineFingerprint));
        }
        ArgumentNullException.ThrowIfNull(requiredFeatures);
        this.requiredFeatures = new HashSet<string>(requiredFeatures, StringComparer.Ordinal);
        if (this.requiredFeatures.Count == 0 ||
            this.requiredFeatures.Any(item => item.Length is 0 or > 64))
        {
            throw new ArgumentException("license_required_features_invalid", nameof(requiredFeatures));
        }
        if (leaseDuration <= TimeSpan.Zero || leaseDuration > TimeSpan.FromMinutes(15))
        {
            throw new ArgumentOutOfRangeException(nameof(leaseDuration));
        }
        ExpectedMachineFingerprint = expectedMachineFingerprint;
        LastAcceptedGeneration = lastAcceptedGeneration;
        LeaseDuration = leaseDuration;
    }

    internal string ExpectedMachineFingerprint { get; }

    internal IReadOnlySet<string> RequiredFeatures => requiredFeatures;

    internal ulong LastAcceptedGeneration { get; }

    internal TimeSpan LeaseDuration { get; }
}

internal static class FishingKeygenLicenseVerifier
{
    private const int MaximumJsonDepth = 24;
    private const int MaximumBodyBytes = 256 * 1024;

    private static readonly IReadOnlySet<string> AllFeatures = FeatureSet(
        "overview",
        "overview_session_stats",
        "fishing",
        "fishing_bot",
        "fishing_tackle",
        "settings",
        "statistics",
        "stream",
        "stream_chat",
        "telegram");

    private static readonly IReadOnlyDictionary<string, IReadOnlySet<string>> GroupFeatures =
        new Dictionary<string, IReadOnlySet<string>>(StringComparer.Ordinal)
        {
            ["intro"] = FeatureSet("fishing"),
            ["basic"] = FeatureSet(
                "overview",
                "fishing",
                "fishing_bot",
                "fishing_tackle",
                "telegram"),
            ["premium"] = FullFeatureSet(),
            ["dev"] = FullFeatureSet(),
            ["promo"] = FullFeatureSet(),
        };

    internal static FishingKeygenLicenseVerificationResult Verify(
        FishingSignedEntitlementEnvelope envelope,
        FishingEntitlementTrustPolicy trust,
        FishingKeygenClaimPolicy claimsPolicy)
    {
        ArgumentNullException.ThrowIfNull(envelope);
        ArgumentNullException.ThrowIfNull(trust);
        ArgumentNullException.ThrowIfNull(claimsPolicy);
        if (!trust.HasTrustRoot)
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.TrustRootMissing);
        }
        if (envelope.RawBody.Length is 0 or > MaximumBodyBytes)
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.ClaimsMalformed);
        }

        var transport = RsaSha256SignedResponseVerifier.Verify(
            envelope.ToCommonEnvelope(),
            new SignedResponseVerificationPolicy(
                trust.ExpectedKeyId,
                trust.ExpectedMethod,
                trust.ExpectedRequestTarget,
                trust.ExpectedHost,
                trust.RsaPublicKeyPem,
                trust.NowUtc,
                trust.MaximumResponseAge,
                trust.MaximumFutureSkew));
        if (!transport.IsVerified)
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.TransportRejected,
                transport.Error);
        }

        ParsedResponse parsed;
        try
        {
            parsed = Parse(transport.Verified!.RawBody);
        }
        catch (Exception exception) when (
            exception is JsonException or InvalidDataException or InvalidOperationException)
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.ClaimsMalformed);
        }

        if (!parsed.Valid || !string.Equals(parsed.Code, "VALID", StringComparison.Ordinal))
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.ValidationRejected,
                serverCode: parsed.Code,
                licenseId: parsed.LicenseId);
        }
        if (!string.Equals(
                parsed.ProductId,
                FishingProductionEntitlementPolicy.KeygenProductId,
                StringComparison.Ordinal))
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.ProductMismatch,
                serverCode: parsed.Code,
                licenseId: parsed.LicenseId);
        }
        if (!string.Equals(
                parsed.MachineFingerprint,
                claimsPolicy.ExpectedMachineFingerprint,
                StringComparison.Ordinal))
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.MachineMismatch,
                serverCode: parsed.Code,
                licenseId: parsed.LicenseId);
        }
        if (!claimsPolicy.RequiredFeatures.IsSubsetOf(parsed.Features))
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.RequiredFeatureMissing,
                serverCode: parsed.Code,
                licenseId: parsed.LicenseId);
        }

        var serverUnix = transport.Verified.ServerDateUtc.ToUnixTimeSeconds();
        if (serverUnix <= 0 || (ulong)serverUnix <= claimsPolicy.LastAcceptedGeneration)
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.LeaseReplayed,
                serverCode: parsed.Code,
                licenseId: parsed.LicenseId);
        }
        var leaseExpires = Math.Min(
            parsed.ExpiresAt.ToUnixTimeSeconds(),
            checked(serverUnix + (long)claimsPolicy.LeaseDuration.TotalSeconds));
        if (trust.NowUtc >= parsed.ExpiresAt ||
            trust.NowUtc.ToUnixTimeSeconds() >= leaseExpires ||
            leaseExpires <= serverUnix)
        {
            return FishingKeygenLicenseVerificationResult.Reject(
                FishingKeygenLicenseError.LeaseInvalid,
                serverCode: parsed.Code,
                licenseId: parsed.LicenseId);
        }

        var claims = new FishingKeygenLicenseClaims(
            parsed.LicenseId,
            parsed.PolicyId,
            parsed.Group,
            parsed.Features,
            parsed.ExpiresAt,
            leaseExpires,
            (ulong)serverUnix);
        return new FishingKeygenLicenseVerificationResult(
            FishingKeygenLicenseError.None,
            SignedResponseVerificationError.None,
            parsed.Code,
            parsed.LicenseId,
            claims);
    }

    private static ParsedResponse Parse(ReadOnlyMemory<byte> rawBody)
    {
        using var document = JsonDocument.Parse(
            rawBody,
            new JsonDocumentOptions
            {
                AllowTrailingCommas = false,
                CommentHandling = JsonCommentHandling.Disallow,
                MaxDepth = MaximumJsonDepth,
            });
        RequireUniqueProperties(document.RootElement);
        var root = RequireObject(document.RootElement, "license_root_invalid");
        var meta = RequireObject(RequireProperty(root, "meta"), "license_meta_invalid");
        var validElement = RequireProperty(meta, "valid");
        if (validElement.ValueKind is not (JsonValueKind.True or JsonValueKind.False))
        {
            throw new InvalidDataException("license_valid_invalid");
        }
        var code = RequireBoundedString(meta, "code", 128);
        var scope = RequireObject(RequireProperty(meta, "scope"), "license_scope_invalid");
        var fingerprint = RequireBoundedString(scope, "fingerprint", 256);

        var data = RequireObject(RequireProperty(root, "data"), "license_data_invalid");
        if (!string.Equals(RequireString(data, "type"), "licenses", StringComparison.Ordinal))
        {
            throw new InvalidDataException("license_type_invalid");
        }
        var licenseId = RequireBoundedString(data, "id", 128);
        var attributes = RequireObject(RequireProperty(data, "attributes"), "license_attributes_invalid");
        var expiryText = RequireBoundedString(attributes, "expiry", 64);
        if (!DateTimeOffset.TryParse(
                expiryText,
                CultureInfo.InvariantCulture,
                DateTimeStyles.AssumeUniversal | DateTimeStyles.AdjustToUniversal,
                out var expiresAt))
        {
            throw new InvalidDataException("license_expiry_invalid");
        }
        var metadata = RequireObject(RequireProperty(attributes, "metadata"), "license_metadata_invalid");
        var group = ResolveGroup(metadata);
        var features = new HashSet<string>(GroupFeatures[group], StringComparer.Ordinal);
        ApplyFeatureOverrides(metadata, features);

        var relationships = RequireObject(
            RequireProperty(data, "relationships"),
            "license_relationships_invalid");
        var productId = RequireRelationshipId(relationships, "product", "products");
        var policyId = RequireRelationshipId(relationships, "policy", "policies");
        return new ParsedResponse(
            validElement.ValueKind == JsonValueKind.True,
            code,
            licenseId,
            fingerprint,
            productId,
            policyId,
            group,
            features,
            expiresAt);
    }

    private static string ResolveGroup(JsonElement metadata)
    {
        string? group = null;
        foreach (var name in new[]
                 {
                     "licenseGroup",
                     "license_group",
                     "sonarSubscriptionLevel",
                     "sonar_subscription_level",
                 })
        {
            if (!metadata.TryGetProperty(name, out var value))
            {
                continue;
            }
            if (value.ValueKind != JsonValueKind.String)
            {
                throw new InvalidDataException("license_group_invalid");
            }
            var candidate = value.GetString()?.Trim().ToLowerInvariant();
            if (candidate is null || !GroupFeatures.ContainsKey(candidate) ||
                (group is not null && !string.Equals(group, candidate, StringComparison.Ordinal)))
            {
                throw new InvalidDataException("license_group_invalid");
            }
            group = candidate;
        }
        return group ?? throw new InvalidDataException("license_group_missing");
    }

    private static void ApplyFeatureOverrides(JsonElement metadata, HashSet<string> features)
    {
        foreach (var name in new[] { "allowFeatures", "allow_features", "features" })
        {
            if (metadata.TryGetProperty(name, out var value))
            {
                foreach (var feature in ReadFeatureArray(value))
                {
                    if (AllFeatures.Contains(feature))
                    {
                        features.Add(feature);
                    }
                }
            }
        }
        foreach (var name in new[] { "denyFeatures", "deny_features" })
        {
            if (metadata.TryGetProperty(name, out var value))
            {
                foreach (var feature in ReadFeatureArray(value))
                {
                    features.Remove(feature);
                }
            }
        }
    }

    private static IEnumerable<string> ReadFeatureArray(JsonElement value)
    {
        if (value.ValueKind != JsonValueKind.Array || value.GetArrayLength() > 64)
        {
            throw new InvalidDataException("license_features_invalid");
        }
        var seen = new HashSet<string>(StringComparer.Ordinal);
        foreach (var item in value.EnumerateArray())
        {
            if (item.ValueKind != JsonValueKind.String)
            {
                throw new InvalidDataException("license_feature_invalid");
            }
            var feature = item.GetString()?.Trim().ToLowerInvariant();
            if (string.IsNullOrEmpty(feature) || feature.Length > 64 || !seen.Add(feature))
            {
                throw new InvalidDataException("license_feature_invalid");
            }
            yield return feature;
        }
    }

    private static string RequireRelationshipId(
        JsonElement relationships,
        string name,
        string expectedType)
    {
        var relationship = RequireObject(
            RequireProperty(relationships, name),
            $"license_{name}_invalid");
        var data = RequireObject(
            RequireProperty(relationship, "data"),
            $"license_{name}_data_invalid");
        if (!string.Equals(RequireString(data, "type"), expectedType, StringComparison.Ordinal))
        {
            throw new InvalidDataException($"license_{name}_type_invalid");
        }
        return RequireBoundedString(data, "id", 128);
    }

    private static JsonElement RequireProperty(JsonElement element, string name) =>
        element.TryGetProperty(name, out var value)
            ? value
            : throw new InvalidDataException($"license_property_missing:{name}");

    private static JsonElement RequireObject(JsonElement element, string reason) =>
        element.ValueKind == JsonValueKind.Object
            ? element
            : throw new InvalidDataException(reason);

    private static string RequireString(JsonElement element, string name)
    {
        var value = RequireProperty(element, name);
        return value.ValueKind == JsonValueKind.String
            ? value.GetString() ?? throw new InvalidDataException($"license_string_invalid:{name}")
            : throw new InvalidDataException($"license_string_invalid:{name}");
    }

    private static string RequireBoundedString(JsonElement element, string name, int maximum)
    {
        var value = RequireString(element, name);
        return value.Length is > 0 && value.Length <= maximum
            ? value
            : throw new InvalidDataException($"license_string_invalid:{name}");
    }

    private static void RequireUniqueProperties(JsonElement element)
    {
        if (element.ValueKind == JsonValueKind.Object)
        {
            var names = new HashSet<string>(StringComparer.Ordinal);
            foreach (var property in element.EnumerateObject())
            {
                if (!names.Add(property.Name))
                {
                    throw new InvalidDataException("license_duplicate_property");
                }
                RequireUniqueProperties(property.Value);
            }
        }
        else if (element.ValueKind == JsonValueKind.Array)
        {
            foreach (var item in element.EnumerateArray())
            {
                RequireUniqueProperties(item);
            }
        }
    }

    private static IReadOnlySet<string> FeatureSet(params string[] features) =>
        new HashSet<string>(features, StringComparer.Ordinal);

    private static IReadOnlySet<string> FullFeatureSet() =>
        new HashSet<string>(AllFeatures, StringComparer.Ordinal);

    private sealed record ParsedResponse(
        bool Valid,
        string Code,
        string LicenseId,
        string MachineFingerprint,
        string ProductId,
        string PolicyId,
        string Group,
        IReadOnlySet<string> Features,
        DateTimeOffset ExpiresAt);
}
