namespace Sonar.Fishing.Host.Licensing;

internal sealed record FishingEntitlementTrustPolicy(
    string ExpectedKeyId,
    string ExpectedMethod,
    string ExpectedRequestTarget,
    string ExpectedHost,
    string RsaPublicKeyPem,
    DateTimeOffset NowUtc,
    TimeSpan MaximumResponseAge,
    TimeSpan MaximumFutureSkew)
{
    internal bool HasTrustRoot =>
        !string.IsNullOrWhiteSpace(ExpectedKeyId) &&
        !string.IsNullOrWhiteSpace(RsaPublicKeyPem);
}

internal sealed class FishingEntitlementClaimPolicy
{
    private readonly HashSet<string> requiredFeatures;

    internal FishingEntitlementClaimPolicy(
        string expectedMachineFingerprint,
        string expectedBundleManifestHash,
        string expectedPolicyId,
        IEnumerable<string> requiredFeatures,
        ulong lastAcceptedGeneration,
        TimeSpan maximumLeaseDuration)
    {
        ExpectedMachineFingerprint = RequireBounded(expectedMachineFingerprint, nameof(expectedMachineFingerprint));
        ExpectedBundleManifestHash = RequireBounded(expectedBundleManifestHash, nameof(expectedBundleManifestHash));
        ExpectedPolicyId = RequireBounded(expectedPolicyId, nameof(expectedPolicyId));
        ArgumentNullException.ThrowIfNull(requiredFeatures);
        this.requiredFeatures = new HashSet<string>(requiredFeatures, StringComparer.Ordinal);
        if (this.requiredFeatures.Count == 0 ||
            this.requiredFeatures.Any(item => item.Length is 0 or > 64))
        {
            throw new ArgumentException("entitlement_required_features_invalid", nameof(requiredFeatures));
        }
        if (maximumLeaseDuration <= TimeSpan.Zero || maximumLeaseDuration > TimeSpan.FromHours(1))
        {
            throw new ArgumentOutOfRangeException(nameof(maximumLeaseDuration));
        }
        LastAcceptedGeneration = lastAcceptedGeneration;
        MaximumLeaseDuration = maximumLeaseDuration;
    }

    internal string ExpectedMachineFingerprint { get; }

    internal string ExpectedBundleManifestHash { get; }

    internal string ExpectedPolicyId { get; }

    internal IReadOnlySet<string> RequiredFeatures => requiredFeatures;

    internal ulong LastAcceptedGeneration { get; }

    internal TimeSpan MaximumLeaseDuration { get; }

    private static string RequireBounded(string value, string name)
    {
        ArgumentNullException.ThrowIfNull(value);
        if (value.Length is 0 or > 256)
        {
            throw new ArgumentException("entitlement_expected_claim_invalid", name);
        }
        return value;
    }
}

internal static class FishingProductionEntitlementPolicy
{
    internal const string ProductId = "fishing";
    internal const string Audience = "sonar-fishing-engine";

    internal const string KeygenAccountId = "e8b61b74-558a-4d85-9bc5-4ac5870a27ae";
    internal const string KeygenProductId = "f92e17ce-1a7f-44ac-b98e-3cd0a514543b";
    internal const string KeygenHost = "m-sonar-addr.ru";
    internal const string KeygenValidationTarget =
        "/v1/licenses/actions/validate-key?include=policy";
    internal const string KeygenRsaPublicKeyPem = """
        -----BEGIN PUBLIC KEY-----
        MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA827rC65fMFhIeaTyIFtI
        5bMqSRHL3boAcVkZLnVJriM6Y7OKdMLnK4XRpISHHJUG5CCQJFtLogfcQkX0Pk6z
        E8J0GBRytJgPlb8VoYp8oIX7M4H9lubc2cwKd9nRkjUaTWR449v0hWuHr2uXz6mF
        DsKS1ZHw1NkbOlRAFb4tmufQvn+pcx0regiVtZOlaA40gdZC0u8FlgwVOhWnuu89
        C9sdxilrcPtOwy9zH7N9XpPXSrhSG40LbONIR+wBb9wORpS6lgak25lNcFceJKot
        LMomwKErDDSEC1SjPlSCymimkCvb1CxIefTDgZ1V1JkfnwFaQ2AcGf5v/ucGqPNc
        HwIDAQAB
        -----END PUBLIC KEY-----
        """;

    // The Keygen RSA trust root is intentionally not substituted with the
    // unrelated startup-block Ed25519 key. Production admission remains closed.
    internal static FishingEntitlementTrustPolicy MissingTrustRoot(DateTimeOffset nowUtc) => new(
        ExpectedKeyId: string.Empty,
        ExpectedMethod: "post",
        ExpectedRequestTarget: "/v1/licenses/actions/validate-key?include=policy",
        ExpectedHost: "m-sonar-addr.ru",
        RsaPublicKeyPem: string.Empty,
        NowUtc: nowUtc,
        MaximumResponseAge: TimeSpan.FromMinutes(5),
        MaximumFutureSkew: TimeSpan.FromMinutes(1));

    internal static FishingEntitlementTrustPolicy KeygenTrustRoot(DateTimeOffset nowUtc) => new(
        ExpectedKeyId: KeygenAccountId,
        ExpectedMethod: "post",
        ExpectedRequestTarget: KeygenValidationTarget,
        ExpectedHost: KeygenHost,
        RsaPublicKeyPem: KeygenRsaPublicKeyPem,
        NowUtc: nowUtc,
        MaximumResponseAge: TimeSpan.FromMinutes(5),
        MaximumFutureSkew: TimeSpan.FromMinutes(1));

    internal static FishingEntitlementTrustPolicy KeygenCachedTrustRoot(DateTimeOffset nowUtc) => new(
        ExpectedKeyId: KeygenAccountId,
        ExpectedMethod: "post",
        ExpectedRequestTarget: KeygenValidationTarget,
        ExpectedHost: KeygenHost,
        RsaPublicKeyPem: KeygenRsaPublicKeyPem,
        NowUtc: nowUtc,
        MaximumResponseAge: TimeSpan.FromMinutes(10),
        MaximumFutureSkew: TimeSpan.FromMinutes(1));
}
