using System.IO;
using Sonar.Fishing.Host.Licensing;
using Sonar.Licensing.Verification;

namespace Sonar.Fishing.Host.Tests;

internal static class FishingEntitlementTests
{
    internal static IEnumerable<TestCase> Create()
    {
        yield return new TestCase(
            "signed_entitlement_is_verified_before_product_claims_are_accepted",
            SignedEntitlementIsVerifiedBeforeProductClaimsAreAccepted);
        yield return new TestCase(
            "entitlement_envelope_retains_exact_raw_response_bytes",
            EntitlementEnvelopeRetainsExactRawResponseBytes);
        yield return new TestCase(
            "production_entitlement_without_rsa_trust_root_is_fail_closed",
            ProductionEntitlementWithoutRsaTrustRootIsFailClosed);
        yield return new TestCase(
            "entitlement_transport_and_product_claim_mismatches_are_fail_closed",
            EntitlementTransportAndProductClaimMismatchesAreFailClosed);
        yield return new TestCase(
            "entitlement_generation_and_required_features_are_fail_closed",
            EntitlementGenerationAndRequiredFeaturesAreFailClosed);
    }

    private static void SignedEntitlementIsVerifiedBeforeProductClaimsAreAccepted()
    {
        var fixture = SignedEntitlementFixture.Load();
        var result = FishingEntitlementVerifier.Verify(
            fixture.Envelope,
            fixture.Trust,
            fixture.ClaimsPolicy());

        TestAssert.True(result.Accepted, $"Signed entitlement was rejected: {result.Error}/{result.TransportError}");
        TestAssert.Equal("license-test", result.Claims!.LicenseId, "License id changed after verification");
        TestAssert.Equal<ulong>(7, result.Claims.Generation, "Lease generation changed");
        TestAssert.True(
            result.Claims.Features.SetEquals(["fishing", "fishing_bot"]),
            "Signed feature allowlist changed");
    }

    private static void EntitlementEnvelopeRetainsExactRawResponseBytes()
    {
        var fixture = SignedEntitlementFixture.Load();
        var callerOwned = fixture.Envelope.RawBody.ToArray();
        var envelope = new FishingSignedEntitlementEnvelope(
            fixture.Envelope.Method,
            fixture.Envelope.RequestTarget,
            fixture.Envelope.Host,
            fixture.Envelope.DateHeader,
            fixture.Envelope.DigestHeader,
            fixture.Envelope.SignatureHeader,
            callerOwned);
        callerOwned[0] ^= 0x01;

        TestAssert.True(
            envelope.RawBody.Span.SequenceEqual(fixture.Envelope.RawBody.Span),
            "Raw signed response retained caller-owned mutable storage");
    }

    private static void ProductionEntitlementWithoutRsaTrustRootIsFailClosed()
    {
        var fixture = SignedEntitlementFixture.Load();
        var result = FishingEntitlementVerifier.Verify(
            fixture.Envelope,
            FishingProductionEntitlementPolicy.MissingTrustRoot(fixture.Trust.NowUtc),
            fixture.ClaimsPolicy());

        TestAssert.True(!result.Accepted, "Missing production trust root admitted automation");
        TestAssert.Equal(
            FishingEntitlementError.TrustRootMissing,
            result.Error,
            "Missing production trust root reason changed");
    }

    private static void EntitlementTransportAndProductClaimMismatchesAreFailClosed()
    {
        var fixture = SignedEntitlementFixture.Load();
        var mutatedBody = fixture.Envelope.RawBody.ToArray();
        mutatedBody[^1] ^= 0x01;
        var transportRejected = FishingEntitlementVerifier.Verify(
            new FishingSignedEntitlementEnvelope(
                fixture.Envelope.Method,
                fixture.Envelope.RequestTarget,
                fixture.Envelope.Host,
                fixture.Envelope.DateHeader,
                fixture.Envelope.DigestHeader,
                fixture.Envelope.SignatureHeader,
                mutatedBody),
            fixture.Trust,
            fixture.ClaimsPolicy());
        TestAssert.Equal(
            FishingEntitlementError.TransportRejected,
            transportRejected.Error,
            "Mutated body reached claim authority");
        TestAssert.Equal(
            SignedResponseVerificationError.DigestMismatch,
            transportRejected.TransportError,
            "Mutated body transport reason changed");

        var wrongMachine = FishingEntitlementVerifier.Verify(
            fixture.Envelope,
            fixture.Trust,
            fixture.ClaimsPolicy(machineFingerprint: "other-machine"));
        TestAssert.Equal(
            FishingEntitlementError.MachineMismatch,
            wrongMachine.Error,
            "Machine mismatch admitted entitlement");

        var wrongBundle = FishingEntitlementVerifier.Verify(
            fixture.Envelope,
            fixture.Trust,
            fixture.ClaimsPolicy(bundleManifestHash: "other-bundle"));
        TestAssert.Equal(
            FishingEntitlementError.BundleMismatch,
            wrongBundle.Error,
            "Bundle mismatch admitted entitlement");
    }

    private static void EntitlementGenerationAndRequiredFeaturesAreFailClosed()
    {
        var fixture = SignedEntitlementFixture.Load();
        var replay = FishingEntitlementVerifier.Verify(
            fixture.Envelope,
            fixture.Trust,
            fixture.ClaimsPolicy(lastAcceptedGeneration: 7));
        TestAssert.Equal(
            FishingEntitlementError.LeaseReplayed,
            replay.Error,
            "Equal entitlement generation was replayed");

        var missingFeature = FishingEntitlementVerifier.Verify(
            fixture.Envelope,
            fixture.Trust,
            fixture.ClaimsPolicy(requiredFeatures: ["fishing", "stream"]));
        TestAssert.Equal(
            FishingEntitlementError.RequiredFeatureMissing,
            missingFeature.Error,
            "Missing signed feature admitted product capability");
    }

    private sealed record SignedEntitlementFixture(
        FishingSignedEntitlementEnvelope Envelope,
        FishingEntitlementTrustPolicy Trust,
        IReadOnlyDictionary<string, string> Values)
    {
        internal static SignedEntitlementFixture Load()
        {
            var root = Path.Combine(AppContext.BaseDirectory, "Fixtures", "Licensing");
            var values = File.ReadAllLines(Path.Combine(root, "signed-entitlement-v1.properties"))
                .Where(line => line.Length != 0 && !line.StartsWith('#'))
                .Select(line => line.Split('=', 2))
                .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            TestAssert.Equal("1", values["schemaVersion"], "Entitlement fixture schema changed");
            var rawBody = Convert.FromHexString(
                File.ReadAllText(Path.Combine(root, "signed-entitlement-v1-body.hex")).Trim());
            var publicKey = File.ReadAllText(
                Path.Combine(root, "signed-entitlement-v1-public.pem")).Trim();
            var now = DateTimeOffset.FromUnixTimeSeconds(long.Parse(values["nowUnix"]));
            return new SignedEntitlementFixture(
                new FishingSignedEntitlementEnvelope(
                    values["method"],
                    values["requestTarget"],
                    values["host"],
                    values["date"],
                    values["digest"],
                    values["signature"],
                    rawBody),
                new FishingEntitlementTrustPolicy(
                    values["keyId"],
                    values["method"],
                    values["requestTarget"],
                    values["host"],
                    publicKey,
                    now,
                    TimeSpan.FromMinutes(5),
                    TimeSpan.FromMinutes(1)),
                values);
        }

        internal FishingEntitlementClaimPolicy ClaimsPolicy(
            string? machineFingerprint = null,
            string? bundleManifestHash = null,
            IEnumerable<string>? requiredFeatures = null,
            ulong lastAcceptedGeneration = 0) => new(
                machineFingerprint ?? Values["machineFingerprint"],
                bundleManifestHash ?? Values["bundleManifestHash"],
                Values["policyId"],
                requiredFeatures ?? ["fishing", "fishing_bot"],
                lastAcceptedGeneration,
                TimeSpan.FromMinutes(10));
    }
}
