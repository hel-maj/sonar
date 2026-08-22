using System.IO;
using System.Text.Json;
using Sonar.Licensing.Verification;

namespace Sonar.Fishing.Host.Licensing;

internal enum FishingEntitlementError
{
    None = 0,
    TrustRootMissing,
    TransportRejected,
    ClaimsMalformed,
    ValidationRejected,
    ProductMismatch,
    AudienceMismatch,
    MachineMismatch,
    BundleMismatch,
    PolicyMismatch,
    RequiredFeatureMissing,
    LeaseInvalid,
    LeaseReplayed,
}

internal sealed record FishingEntitlementClaims(
    string LicenseId,
    string MachineFingerprint,
    string BundleManifestHash,
    string PolicyId,
    IReadOnlySet<string> Features,
    long IssuedUnixSeconds,
    long ExpiresUnixSeconds,
    ulong Generation);

internal sealed record FishingEntitlementVerificationResult(
    FishingEntitlementError Error,
    SignedResponseVerificationError TransportError,
    FishingEntitlementClaims? Claims)
{
    internal bool Accepted => Error == FishingEntitlementError.None && Claims is not null;

    internal static FishingEntitlementVerificationResult Reject(
        FishingEntitlementError error,
        SignedResponseVerificationError transportError = SignedResponseVerificationError.None) =>
        new(error, transportError, null);
}

internal static class FishingEntitlementVerifier
{
    private const int MaximumJsonDepth = 16;

    internal static FishingEntitlementVerificationResult Verify(
        FishingSignedEntitlementEnvelope envelope,
        FishingEntitlementTrustPolicy trust,
        FishingEntitlementClaimPolicy claimsPolicy)
    {
        ArgumentNullException.ThrowIfNull(envelope);
        ArgumentNullException.ThrowIfNull(trust);
        ArgumentNullException.ThrowIfNull(claimsPolicy);
        if (!trust.HasTrustRoot)
        {
            return FishingEntitlementVerificationResult.Reject(
                FishingEntitlementError.TrustRootMissing);
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
            return FishingEntitlementVerificationResult.Reject(
                FishingEntitlementError.TransportRejected,
                transport.Error);
        }

        FishingEntitlementClaims claims;
        try
        {
            claims = ParseClaims(transport.Verified!.RawBody);
        }
        catch (ProductClaimException exception)
        {
            return FishingEntitlementVerificationResult.Reject(exception.Error);
        }
        catch (Exception exception) when (
            exception is JsonException or InvalidDataException or InvalidOperationException or OverflowException)
        {
            return FishingEntitlementVerificationResult.Reject(
                FishingEntitlementError.ClaimsMalformed);
        }

        if (claims.LicenseId.Length == 0)
        {
            return FishingEntitlementVerificationResult.Reject(
                FishingEntitlementError.ValidationRejected);
        }
        if (!string.Equals(claims.MachineFingerprint, claimsPolicy.ExpectedMachineFingerprint, StringComparison.Ordinal))
        {
            return FishingEntitlementVerificationResult.Reject(FishingEntitlementError.MachineMismatch);
        }
        if (!string.Equals(claims.BundleManifestHash, claimsPolicy.ExpectedBundleManifestHash, StringComparison.Ordinal))
        {
            return FishingEntitlementVerificationResult.Reject(FishingEntitlementError.BundleMismatch);
        }
        if (!string.Equals(claims.PolicyId, claimsPolicy.ExpectedPolicyId, StringComparison.Ordinal))
        {
            return FishingEntitlementVerificationResult.Reject(FishingEntitlementError.PolicyMismatch);
        }
        if (!claimsPolicy.RequiredFeatures.IsSubsetOf(claims.Features))
        {
            return FishingEntitlementVerificationResult.Reject(
                FishingEntitlementError.RequiredFeatureMissing);
        }
        if (claims.Generation <= claimsPolicy.LastAcceptedGeneration)
        {
            return FishingEntitlementVerificationResult.Reject(FishingEntitlementError.LeaseReplayed);
        }

        var serverUnix = transport.Verified.ServerDateUtc.ToUnixTimeSeconds();
        var nowUnix = trust.NowUtc.ToUnixTimeSeconds();
        var maximumLeaseSeconds = checked((long)claimsPolicy.MaximumLeaseDuration.TotalSeconds);
        if (claims.IssuedUnixSeconds > serverUnix ||
            serverUnix >= claims.ExpiresUnixSeconds ||
            nowUnix >= claims.ExpiresUnixSeconds ||
            claims.ExpiresUnixSeconds <= claims.IssuedUnixSeconds ||
            claims.ExpiresUnixSeconds - claims.IssuedUnixSeconds > maximumLeaseSeconds)
        {
            return FishingEntitlementVerificationResult.Reject(FishingEntitlementError.LeaseInvalid);
        }

        return new FishingEntitlementVerificationResult(
            FishingEntitlementError.None,
            SignedResponseVerificationError.None,
            claims);
    }

    private static FishingEntitlementClaims ParseClaims(ReadOnlyMemory<byte> rawBody)
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
        var root = RequireObject(document.RootElement, "entitlement_root_invalid");
        var meta = RequireObject(RequireProperty(root, "meta"), "entitlement_meta_invalid");
        var valid = RequireProperty(meta, "valid");
        if (valid.ValueKind != JsonValueKind.True ||
            RequireString(meta, "code") != "VALID")
        {
            throw new ProductClaimException(FishingEntitlementError.ValidationRejected);
        }

        var data = RequireObject(RequireProperty(root, "data"), "entitlement_data_invalid");
        var licenseId = RequireBoundedString(data, "id", 128);
        if (RequireString(data, "type") != "licenses")
        {
            throw new InvalidDataException("entitlement_license_type_invalid");
        }
        var attributes = RequireObject(RequireProperty(data, "attributes"), "entitlement_attributes_invalid");
        var metadata = RequireObject(RequireProperty(attributes, "metadata"), "entitlement_metadata_invalid");
        if (RequireString(metadata, "product_id") != FishingProductionEntitlementPolicy.ProductId)
        {
            throw new ProductClaimException(FishingEntitlementError.ProductMismatch);
        }
        if (RequireString(metadata, "audience") != FishingProductionEntitlementPolicy.Audience)
        {
            throw new ProductClaimException(FishingEntitlementError.AudienceMismatch);
        }

        var relationships = RequireObject(
            RequireProperty(data, "relationships"),
            "entitlement_relationships_invalid");
        var policy = RequireObject(RequireProperty(relationships, "policy"), "entitlement_policy_invalid");
        var policyData = RequireObject(RequireProperty(policy, "data"), "entitlement_policy_data_invalid");
        if (RequireString(policyData, "type") != "policies")
        {
            throw new InvalidDataException("entitlement_policy_type_invalid");
        }

        var featuresElement = RequireProperty(metadata, "features");
        if (featuresElement.ValueKind != JsonValueKind.Array)
        {
            throw new InvalidDataException("entitlement_features_invalid");
        }
        var features = new HashSet<string>(StringComparer.Ordinal);
        foreach (var item in featuresElement.EnumerateArray())
        {
            if (item.ValueKind != JsonValueKind.String ||
                !features.Add(RequireBounded(item.GetString(), 64, "entitlement_feature_invalid")))
            {
                throw new InvalidDataException("entitlement_feature_invalid");
            }
        }

        var generationValue = RequireProperty(metadata, "generation");
        if (!generationValue.TryGetUInt64(out var generation) || generation == 0)
        {
            throw new InvalidDataException("entitlement_generation_invalid");
        }
        return new FishingEntitlementClaims(
            licenseId,
            RequireBoundedString(metadata, "machine_fingerprint", 256),
            RequireBoundedString(metadata, "bundle_manifest_hash", 256),
            RequireBoundedString(policyData, "id", 128),
            features,
            RequireInt64(metadata, "issued_unix"),
            RequireInt64(metadata, "expires_unix"),
            generation);
    }

    private static JsonElement RequireProperty(JsonElement element, string name)
    {
        if (!element.TryGetProperty(name, out var value))
        {
            throw new InvalidDataException($"entitlement_property_missing:{name}");
        }
        return value;
    }

    private static JsonElement RequireObject(JsonElement element, string reason)
    {
        if (element.ValueKind != JsonValueKind.Object)
        {
            throw new InvalidDataException(reason);
        }
        return element;
    }

    private static string RequireString(JsonElement element, string name)
    {
        var value = RequireProperty(element, name);
        if (value.ValueKind != JsonValueKind.String)
        {
            throw new InvalidDataException($"entitlement_string_invalid:{name}");
        }
        return value.GetString() ?? throw new InvalidDataException($"entitlement_string_invalid:{name}");
    }

    private static string RequireBoundedString(JsonElement element, string name, int maximum) =>
        RequireBounded(RequireString(element, name), maximum, $"entitlement_string_invalid:{name}");

    private static string RequireBounded(string? value, int maximum, string reason)
    {
        if (string.IsNullOrEmpty(value) || value.Length > maximum)
        {
            throw new InvalidDataException(reason);
        }
        return value;
    }

    private static long RequireInt64(JsonElement element, string name)
    {
        var value = RequireProperty(element, name);
        if (!value.TryGetInt64(out var result))
        {
            throw new InvalidDataException($"entitlement_integer_invalid:{name}");
        }
        return result;
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
                    throw new InvalidDataException("entitlement_duplicate_property");
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

    private sealed class ProductClaimException(FishingEntitlementError error) : Exception
    {
        internal FishingEntitlementError Error { get; } = error;
    }
}
