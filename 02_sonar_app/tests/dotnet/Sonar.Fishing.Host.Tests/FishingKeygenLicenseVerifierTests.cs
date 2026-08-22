using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Net;
using System.Net.Http;
using Sonar.Fishing.Host.LicensePage;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.Licensing;

namespace Sonar.Fishing.Host.Tests;

internal static class FishingKeygenLicenseVerifierTests
{
    private static readonly DateTimeOffset ServerDate =
        DateTimeOffset.Parse("2026-08-22T01:02:03Z");

    internal static IEnumerable<TestCase> Create()
    {
        yield return new TestCase(
            "production_keygen_trust_root_is_exact_and_embedded",
            ProductionTrustRootIsExactAndEmbedded);
        yield return new TestCase(
            "signed_keygen_response_maps_product_group_and_short_lease",
            SignedResponseMapsProductGroupAndShortLease);
        yield return new TestCase(
            "current_keygen_fixture_is_shared_by_managed_and_native_verifiers",
            CurrentKeygenFixtureIsSharedByManagedAndNativeVerifiers);
        yield return new TestCase(
            "keygen_machine_feature_and_replay_gates_fail_closed",
            MachineFeatureAndReplayGatesFailClosed);
        yield return new TestCase(
            "signed_keygen_rejection_retains_only_bounded_activation_context",
            SignedRejectionRetainsBoundedActivationContext);
        yield return new TestCase(
            "keygen_http_client_preserves_raw_signed_response_and_exact_target",
            KeygenHttpClientPreservesRawSignedResponseAndExactTarget);
        yield return new TestCase(
            "machine_fingerprint_is_stable_and_non_reversible",
            MachineFingerprintIsStableAndNonReversible);
        yield return new TestCase(
            "license_activation_performs_one_machine_binding_then_revalidates",
            LicenseActivationPerformsOneMachineBindingThenRevalidates);
        yield return new TestCase(
            "protected_signed_license_cache_is_exact_and_tamper_evident",
            ProtectedSignedLicenseCacheIsExactAndTamperEvident);
        yield return new TestCase(
            "license_cache_is_used_only_for_transient_initial_transport_failure",
            LicenseCacheIsUsedOnlyForTransientInitialTransportFailure);
        yield return new TestCase(
            "license_runtime_refreshes_five_minute_cache_and_revokes_signed_denial",
            LicenseRuntimeRefreshesFiveMinuteCacheAndRevokesSignedDenial);
        yield return new TestCase(
            "license_runtime_rejection_uses_actionable_user_copy",
            LicenseRuntimeRejectionUsesActionableUserCopy);
        yield return new TestCase(
            "license_page_activation_projects_verified_settings_without_key_echo",
            LicensePageActivationProjectsVerifiedSettingsWithoutKeyEcho);
    }

    private static void ProductionTrustRootIsExactAndEmbedded()
    {
        var trust = FishingProductionEntitlementPolicy.KeygenTrustRoot(ServerDate);

        TestAssert.True(trust.HasTrustRoot, "Production trust root stayed empty");
        TestAssert.Equal(
            FishingProductionEntitlementPolicy.KeygenAccountId,
            trust.ExpectedKeyId,
            "Production Keygen key id drifted");
        TestAssert.Equal(
            FishingProductionEntitlementPolicy.KeygenValidationTarget,
            trust.ExpectedRequestTarget,
            "Production validation request target drifted");
        using var rsa = RSA.Create();
        rsa.ImportFromPem(trust.RsaPublicKeyPem);
        TestAssert.Equal(2048, rsa.KeySize, "Production Keygen RSA key size changed");
    }

    private static void SignedResponseMapsProductGroupAndShortLease()
    {
        using var rsa = RSA.Create(2048);
        var body = ResponseBody(
            valid: true,
            code: "VALID",
            fingerprint: "machine-001",
            group: "premium");
        var envelope = Sign(body, rsa);
        var result = FishingKeygenLicenseVerifier.Verify(
            envelope,
            Trust(rsa),
            Policy("machine-001", ["fishing", "fishing_bot"]));

        TestAssert.True(result.Accepted, $"Signed Keygen response rejected: {result.Error}");
        TestAssert.Equal("license-001", result.Claims!.LicenseId, "License id changed");
        TestAssert.Equal("premium", result.Claims.Group, "Subscription group changed");
        TestAssert.True(
            result.Claims.Features.SetEquals(
                [
                    "overview",
                    "overview_session_stats",
                    "fishing",
                    "fishing_bot",
                    "fishing_tackle",
                    "settings",
                    "statistics",
                    "stream",
                    "stream_chat",
                    "telegram",
                ]),
            "Premium feature projection changed");
        TestAssert.Equal(
            ServerDate.AddMinutes(10).ToUnixTimeSeconds(),
            result.Claims.LeaseExpiresUnixSeconds,
            "Short Engine lease changed");
        TestAssert.Equal(
            (ulong)ServerDate.ToUnixTimeSeconds(),
            result.Claims.Generation,
            "Signed server-date generation changed");
    }

    private static void CurrentKeygenFixtureIsSharedByManagedAndNativeVerifiers()
    {
        var root = Path.Combine(AppContext.BaseDirectory, "Fixtures", "Licensing");
        var values = File.ReadAllLines(Path.Combine(root, "keygen-response-v1.properties"))
            .Where(line => line.Length != 0 && !line.StartsWith('#'))
            .Select(line => line.Split('=', 2))
            .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
        var envelope = new FishingSignedEntitlementEnvelope(
            values["method"],
            values["requestTarget"],
            values["host"],
            values["date"],
            values["digest"],
            values["signature"],
            Convert.FromHexString(
                File.ReadAllText(Path.Combine(root, "keygen-response-v1-body.hex")).Trim()));
        var now = DateTimeOffset.FromUnixTimeSeconds(long.Parse(values["nowUnix"]));
        var trust = new FishingEntitlementTrustPolicy(
            values["keyId"],
            values["method"],
            values["requestTarget"],
            values["host"],
            File.ReadAllText(Path.Combine(root, "keygen-response-v1-public.pem")),
            now,
            TimeSpan.FromMinutes(5),
            TimeSpan.FromMinutes(1));
        var result = FishingKeygenLicenseVerifier.Verify(
            envelope,
            trust,
            new FishingKeygenClaimPolicy(
                values["machineFingerprint"],
                ["fishing", "fishing_bot"],
                0,
                TimeSpan.FromMinutes(10)));

        TestAssert.True(result.Accepted, $"Shared Keygen fixture rejected: {result.Error}");
        TestAssert.Equal("basic", result.Claims!.Group, "Shared fixture group changed");
        TestAssert.Equal(
            ulong.Parse(values["generation"]),
            result.Claims.Generation,
            "Managed/native server-date generation diverged");
        TestAssert.Equal(
            1787361123L,
            result.Claims.LeaseExpiresUnixSeconds,
            "Managed/native short lease diverged");
    }

    private static void MachineFeatureAndReplayGatesFailClosed()
    {
        using var rsa = RSA.Create(2048);
        var envelope = Sign(
            ResponseBody(
                valid: true,
                code: "VALID",
                fingerprint: "machine-001",
                group: "intro"),
            rsa);

        var wrongMachine = FishingKeygenLicenseVerifier.Verify(
            envelope,
            Trust(rsa),
            Policy("machine-002", ["fishing"]));
        TestAssert.Equal(
            FishingKeygenLicenseError.MachineMismatch,
            wrongMachine.Error,
            "Machine mismatch admitted a license");

        var missingFeature = FishingKeygenLicenseVerifier.Verify(
            envelope,
            Trust(rsa),
            Policy("machine-001", ["fishing_bot"]));
        TestAssert.Equal(
            FishingKeygenLicenseError.RequiredFeatureMissing,
            missingFeature.Error,
            "Intro license admitted automation");

        var replay = FishingKeygenLicenseVerifier.Verify(
            envelope,
            Trust(rsa),
            Policy(
                "machine-001",
                ["fishing"],
                (ulong)ServerDate.ToUnixTimeSeconds()));
        TestAssert.Equal(
            FishingKeygenLicenseError.LeaseReplayed,
            replay.Error,
            "Equal signed server-date replay was admitted");

        var tampered = envelope.RawBody.ToArray();
        tampered[^2] ^= 1;
        var rejectedTransport = FishingKeygenLicenseVerifier.Verify(
            new FishingSignedEntitlementEnvelope(
                envelope.Method,
                envelope.RequestTarget,
                envelope.Host,
                envelope.DateHeader,
                envelope.DigestHeader,
                envelope.SignatureHeader,
                tampered),
            Trust(rsa),
            Policy("machine-001", ["fishing"]));
        TestAssert.Equal(
            FishingKeygenLicenseError.TransportRejected,
            rejectedTransport.Error,
            "Tampered raw response reached product claims");
    }

    private static void SignedRejectionRetainsBoundedActivationContext()
    {
        using var rsa = RSA.Create(2048);
        var result = FishingKeygenLicenseVerifier.Verify(
            Sign(
                ResponseBody(
                    valid: false,
                    code: "NO_MACHINE",
                    fingerprint: "machine-001",
                    group: "basic"),
                rsa),
            Trust(rsa),
            Policy("machine-001", ["fishing"]));

        TestAssert.Equal(
            FishingKeygenLicenseError.ValidationRejected,
            result.Error,
            "Rejected Keygen response changed category");
        TestAssert.Equal("NO_MACHINE", result.ServerCode, "Activation code was lost");
        TestAssert.Equal("license-001", result.LicenseId, "Activation license id was lost");
        TestAssert.True(result.Claims is null, "Rejected response exposed accepted claims");
    }

    private static void KeygenHttpClientPreservesRawSignedResponseAndExactTarget()
    {
        var rawBody = Encoding.UTF8.GetBytes("{\"meta\":{\"valid\":false}}");
        var handler = new RecordingHandler(request =>
        {
            var response = new HttpResponseMessage(HttpStatusCode.OK)
            {
                RequestMessage = request,
                Content = new ByteArrayContent(rawBody),
            };
            response.Headers.TryAddWithoutValidation("Date", ServerDate.ToString("r"));
            response.Headers.TryAddWithoutValidation("Digest", "sha-256=digest");
            response.Headers.TryAddWithoutValidation(
                "Keygen-Signature",
                "keyid=\"account-test\", algorithm=\"rsa-sha256\", signature=\"signature\", headers=\"(request-target) host date digest\"");
            return response;
        });
        using var httpClient = new HttpClient(handler);
        var client = new KeygenLicenseApiClient(httpClient, TimeSpan.FromSeconds(1));

        var envelope = client.ValidateAsync(
            "ABCDE-FGHIJ-KLMNO",
            "machine-001",
            CancellationToken.None).GetAwaiter().GetResult();

        TestAssert.True(envelope.RawBody.Span.SequenceEqual(rawBody), "Raw response bytes changed");
        TestAssert.Equal(
            FishingProductionEntitlementPolicy.KeygenValidationTarget,
            envelope.RequestTarget,
            "Signed request target changed");
        TestAssert.Equal("POST", handler.Method, "Validation method changed");
        TestAssert.Equal(
            "algorithm=\"rsa-sha256\"",
            handler.AcceptSignature,
            "RSA response-signature request changed");
        using var payload = JsonDocument.Parse(handler.Body);
        TestAssert.Equal(
            "ABCDE-FGHIJ-KLMNO",
            payload.RootElement.GetProperty("meta").GetProperty("key").GetString()!,
            "License key request body changed");
        TestAssert.Equal(
            "machine-001",
            payload.RootElement.GetProperty("meta").GetProperty("scope").GetProperty("fingerprint").GetString()!,
            "Machine scope request body changed");
    }

    private static void MachineFingerprintIsStableAndNonReversible()
    {
        var first = WindowsMachineFingerprint.Compute(
            "Windows",
            "AMD64",
            "machine-guid",
            "123456",
            "fallback");
        var second = WindowsMachineFingerprint.Compute(
            "Windows",
            "AMD64",
            "machine-guid",
            "123456",
            "other-fallback");

        TestAssert.Equal(first, second, "Stable machine fingerprint changed");
        TestAssert.Equal(64, first.Length, "Machine fingerprint is not SHA-256 hex");
        TestAssert.True(
            !first.Contains("machine-guid", StringComparison.Ordinal),
            "Machine identity leaked into fingerprint");
    }

    private static void LicenseActivationPerformsOneMachineBindingThenRevalidates()
    {
        using var rsa = RSA.Create(2048);
        var api = new FakeKeygenApi(
            Sign(ResponseBody(false, "NO_MACHINE", "machine-001", "basic"), rsa),
            Sign(ResponseBody(true, "VALID", "machine-001", "basic"), rsa));
        var service = new FishingLicenseActivationService(
            api,
            "machine-001",
            () => ServerDate.AddSeconds(15),
            _ => Trust(rsa));

        var result = service.ActivateOrRefreshAsync(
            "ABCDE-FGHIJ-KLMNO",
            0,
            CancellationToken.None).GetAwaiter().GetResult();

        TestAssert.True(result.Accepted, $"Activation failed: {result.Message}");
        TestAssert.Equal(2, api.ValidationCount, "Activation did not revalidate exactly once");
        TestAssert.Equal(1, api.ActivationCount, "Machine activation count changed");
        TestAssert.Equal("license-001", api.ActivatedLicenseId, "Activation license id changed");
        TestAssert.Equal("basic", result.Settings!.Group, "Activated group changed");
        TestAssert.True(
            result.Settings.Features.Contains("fishing_bot", StringComparer.Ordinal),
            "Basic automation feature was lost");
    }

    private static void ProtectedSignedLicenseCacheIsExactAndTamperEvident()
    {
        using var rsa = RSA.Create(2048);
        var envelope = Sign(
            ResponseBody(true, "VALID", "machine-001", "premium"),
            rsa);
        var token = FishingSignedLicenseCacheCodec.Encode(envelope);
        var decoded = FishingSignedLicenseCacheCodec.Decode(token);

        TestAssert.Equal(envelope.Method, decoded.Method, "Cached method changed");
        TestAssert.Equal(envelope.RequestTarget, decoded.RequestTarget, "Cached target changed");
        TestAssert.Equal(envelope.Host, decoded.Host, "Cached host changed");
        TestAssert.Equal(envelope.DateHeader, decoded.DateHeader, "Cached date changed");
        TestAssert.Equal(envelope.DigestHeader, decoded.DigestHeader, "Cached digest changed");
        TestAssert.Equal(envelope.SignatureHeader, decoded.SignatureHeader, "Cached signature changed");
        TestAssert.True(
            envelope.RawBody.Span.SequenceEqual(decoded.RawBody.Span),
            "Cached exact raw response bytes changed");

        var cacheJson = Encoding.UTF8.GetString(Convert.FromBase64String(token));
        const string marker = "\"rawBody\":\"";
        var bodyIndex = cacheJson.IndexOf(marker, StringComparison.Ordinal) + marker.Length;
        TestAssert.True(bodyIndex >= marker.Length, "Cached raw body field disappeared");
        var replacement = cacheJson[bodyIndex] == 'A' ? 'B' : 'A';
        var tamperedJson =
            cacheJson[..bodyIndex] + replacement + cacheJson[(bodyIndex + 1)..];
        var tamperedEnvelope = FishingSignedLicenseCacheCodec.Decode(
            Convert.ToBase64String(Encoding.UTF8.GetBytes(tamperedJson)));
        var verification = FishingKeygenLicenseVerifier.Verify(
            tamperedEnvelope,
            Trust(rsa),
            Policy("machine-001", ["fishing"]));
        TestAssert.Equal(
            FishingKeygenLicenseError.TransportRejected,
            verification.Error,
            "Tampered cached raw bytes retained authority");
    }

    private static void LicenseCacheIsUsedOnlyForTransientInitialTransportFailure()
    {
        using var rsa = RSA.Create(2048);
        var validEnvelope = Sign(
            ResponseBody(true, "VALID", "machine-001", "premium"),
            rsa);
        var cache = FishingSignedLicenseCacheCodec.Encode(validEnvelope);
        var transientService = new FishingLicenseActivationService(
            new SequenceKeygenApi(
                new FishingLicenseTransportException("license_http_unavailable")),
            "machine-001",
            () => ServerDate.AddSeconds(15),
            _ => Trust(rsa));

        var cached = transientService.ActivateOrRefreshAsync(
            "ABCDE-FGHIJ-KLMNO",
            0,
            cache,
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(cached.Accepted, "Fresh signed cache was not used during outage");
        TestAssert.True(cached.FromProtectedCache, "Cache source was not retained");
        TestAssert.True(!cached.TemporarilyUnavailable, "Accepted cache remained unavailable");

        var denialService = new FishingLicenseActivationService(
            new SequenceKeygenApi(
                Sign(ResponseBody(false, "EXPIRED", "machine-001", "premium"), rsa)),
            "machine-001",
            () => ServerDate.AddSeconds(15),
            _ => Trust(rsa));
        var denied = denialService.ActivateOrRefreshAsync(
            "ABCDE-FGHIJ-KLMNO",
            0,
            cache,
            CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(!denied.Accepted, "Signed expiry was replaced by older cache");
        TestAssert.True(!denied.FromProtectedCache, "Signed denial fell back to cache");
        TestAssert.True(!denied.TemporarilyUnavailable, "Signed denial became network failure");
    }

    private static void LicenseRuntimeRefreshesFiveMinuteCacheAndRevokesSignedDenial()
    {
        using var rsa = RSA.Create(2048);
        var validEnvelope = Sign(
            ResponseBody(true, "VALID", "machine-001", "premium"),
            rsa);
        var cache = FishingSignedLicenseCacheCodec.Encode(validEnvelope);
        var api = new SequenceKeygenApi(
            new FishingLicenseTransportException("license_http_unavailable"),
            Sign(ResponseBody(false, "EXPIRED", "machine-001", "premium"), rsa));
        var service = new FishingLicenseActivationService(
            api,
            "machine-001",
            () => ServerDate.AddSeconds(15),
            _ => Trust(rsa));
        var directory = Path.Combine(
            Path.GetTempPath(),
            "sonar-fishing-license-runtime-" + Guid.NewGuid().ToString("N"));
        try
        {
            var store = new FishingStateStore(directory, new TestSecretProtector());
            var initial = FishingHostState.Default with
            {
                Secrets = new SensitiveHostSettings(
                    string.Empty,
                    "ABCDE-FGHIJ-KLMNO",
                    cache),
            };
            var state = new HostStateCoordinator(store, store.LoadOrCreate(initial));
            var sink = new RecordingEntitlementSink();
            var delayEntered = new TaskCompletionSource<TimeSpan>(
                TaskCreationOptions.RunContinuationsAsynchronously);
            Task ControlledDelay(TimeSpan interval, CancellationToken cancellationToken)
            {
                delayEntered.TrySetResult(interval);
                return Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken);
            }
            var runtime = new FishingLicenseRuntimeCoordinator(
                service,
                state,
                sink,
                () => ServerDate.AddSeconds(15),
                delay: ControlledDelay);

            runtime.StartAsync().GetAwaiter().GetResult();
            var interval = delayEntered.Task.WaitAsync(TimeSpan.FromSeconds(2))
                .GetAwaiter().GetResult();
            TestAssert.Equal(TimeSpan.FromMinutes(5), interval, "Refresh cadence changed");
            TestAssert.Equal("license-001", state.Current.License.LicenseId, "Cached license was not persisted");
            TestAssert.Equal(1, sink.ApplyCount, "Engine entitlement was not applied exactly once");

            var denied = runtime.RefreshSavedAsync(CancellationToken.None)
                .GetAwaiter().GetResult();
            TestAssert.True(!denied.Accepted, "Signed expiry was accepted by runtime");
            TestAssert.Equal(string.Empty, state.Current.License.LicenseId, "Revoked license stayed visible");
            TestAssert.Equal(string.Empty, state.Current.Secrets.SignedLicenseCache, "Revoked cache survived");
            TestAssert.Equal(
                "ABCDE-FGHIJ-KLMNO",
                state.Current.Secrets.LicenseKey,
                "Refresh key was unexpectedly discarded");
            TestAssert.Equal(1, sink.RevokeCount, "Engine authority was not revoked exactly once");
            runtime.StopAsync().GetAwaiter().GetResult();
        }
        finally
        {
            if (Directory.Exists(directory))
            {
                Directory.Delete(directory, recursive: true);
            }
        }
    }

    private static void LicensePageActivationProjectsVerifiedSettingsWithoutKeyEcho()
    {
        var settings = new LicenseHostSettings(
            "license-verified",
            ServerDate.ToString("O"),
            ServerDate.AddDays(7).ToString("O"),
            "user",
            "premium",
            ["fishing", "fishing_bot"],
            []);
        string? receivedKey = null;
        var viewModel = new LicensePageViewModel(
            LicenseHostSettings.Default,
            (key, _) =>
            {
                receivedKey = key;
                return Task.FromResult(new FishingLicenseActivationResult(
                    true,
                    "Лицензия подтверждена.",
                    settings,
                    null,
                    null));
            });

        var accepted = viewModel.ActivateAsync(
            "ABCDE-FGHIJ-KLMNO",
            CancellationToken.None).GetAwaiter().GetResult();

        TestAssert.True(accepted, "License page did not accept verified settings");
        TestAssert.Equal("ABCDE-FGHIJ-KLMNO", receivedKey!, "License key was not passed exactly");
        TestAssert.Equal("license-verified", viewModel.LicenseId, "Verified license id was not projected");
        TestAssert.Equal("premium", viewModel.Subscription, "Verified subscription was not projected");
        TestAssert.True(
            !viewModel.ActivationMessage.Contains("ABCDE", StringComparison.Ordinal),
            "License key leaked into activation copy");
    }

    private static void LicenseRuntimeRejectionUsesActionableUserCopy()
    {
        using var rsa = RSA.Create(2048);
        var api = new SequenceKeygenApi(Sign(
            ResponseBody(true, "VALID", "machine-001", "premium"),
            rsa));
        var service = new FishingLicenseActivationService(
            api,
            "machine-001",
            () => ServerDate.AddSeconds(15),
            _ => Trust(rsa));
        var directory = Path.Combine(
            Path.GetTempPath(),
            "sonar-fishing-license-copy-" + Guid.NewGuid().ToString("N"));
        try
        {
            var store = new FishingStateStore(directory, new TestSecretProtector());
            var state = new HostStateCoordinator(
                store,
                store.LoadOrCreate(FishingHostState.Default));
            var sink = new RecordingEntitlementSink(applyResult: false);
            var runtime = new FishingLicenseRuntimeCoordinator(
                service,
                state,
                sink,
                () => ServerDate.AddSeconds(15));

            var result = runtime.ActivateAsync(
                    "ABCDE-FGHIJ-KLMNO",
                    CancellationToken.None)
                .GetAwaiter()
                .GetResult();

            TestAssert.True(!result.Accepted, "Runtime rejection was unexpectedly accepted");
            TestAssert.Equal(
                "Не удалось подтвердить лицензию. Проверьте ключ и повторите.",
                result.Message,
                "Runtime rejection exposed implementation detail");
            VisibleCopyAudit.AssertText(result.Message, "license/runtime-rejection");
            TestAssert.Equal(1, sink.ApplyCount, "Runtime verification was not attempted once");
            TestAssert.Equal(
                string.Empty,
                state.Current.License.LicenseId,
                "Rejected entitlement changed visible license state");
        }
        finally
        {
            if (Directory.Exists(directory))
            {
                Directory.Delete(directory, recursive: true);
            }
        }
    }

    private static FishingEntitlementTrustPolicy Trust(RSA rsa) => new(
        "account-test",
        "post",
        FishingProductionEntitlementPolicy.KeygenValidationTarget,
        FishingProductionEntitlementPolicy.KeygenHost,
        rsa.ExportSubjectPublicKeyInfoPem(),
        ServerDate.AddSeconds(15),
        TimeSpan.FromMinutes(5),
        TimeSpan.FromMinutes(1));

    private static FishingKeygenClaimPolicy Policy(
        string machine,
        IEnumerable<string> required,
        ulong lastGeneration = 0) =>
        new(machine, required, lastGeneration, TimeSpan.FromMinutes(10));

    private static FishingSignedEntitlementEnvelope Sign(byte[] body, RSA rsa)
    {
        var date = ServerDate.ToString("r");
        var digest = "sha-256=" + Convert.ToBase64String(SHA256.HashData(body));
        var signingData = string.Join(
            '\n',
            $"(request-target): post {FishingProductionEntitlementPolicy.KeygenValidationTarget}",
            $"host: {FishingProductionEntitlementPolicy.KeygenHost}",
            $"date: {date}",
            $"digest: {digest}");
        var signature = Convert.ToBase64String(
            rsa.SignData(
                Encoding.ASCII.GetBytes(signingData),
                HashAlgorithmName.SHA256,
                RSASignaturePadding.Pkcs1));
        return new FishingSignedEntitlementEnvelope(
            "post",
            FishingProductionEntitlementPolicy.KeygenValidationTarget,
            FishingProductionEntitlementPolicy.KeygenHost,
            date,
            digest,
            $"keyid=\"account-test\", algorithm=\"rsa-sha256\", signature=\"{signature}\", headers=\"(request-target) host date digest\"",
            body);
    }

    private static byte[] ResponseBody(
        bool valid,
        string code,
        string fingerprint,
        string group)
    {
        return JsonSerializer.SerializeToUtf8Bytes(new
        {
            meta = new
            {
                valid,
                code,
                scope = new { fingerprint },
            },
            data = new
            {
                type = "licenses",
                id = "license-001",
                attributes = new
                {
                    status = "ACTIVE",
                    expiry = "2026-08-23T01:02:03.000Z",
                    metadata = new
                    {
                        licenseGroup = group,
                        sonarSubscriptionLevel = group,
                    },
                },
                relationships = new
                {
                    product = new
                    {
                        data = new
                        {
                            type = "products",
                            id = FishingProductionEntitlementPolicy.KeygenProductId,
                        },
                    },
                    policy = new
                    {
                        data = new
                        {
                            type = "policies",
                            id = "policy-001",
                        },
                    },
                },
            },
        });
    }

    private sealed class RecordingHandler(
        Func<HttpRequestMessage, HttpResponseMessage> createResponse) : HttpMessageHandler
    {
        internal string Method { get; private set; } = string.Empty;

        internal string AcceptSignature { get; private set; } = string.Empty;

        internal string Body { get; private set; } = string.Empty;

        protected override async Task<HttpResponseMessage> SendAsync(
            HttpRequestMessage request,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            Method = request.Method.Method;
            AcceptSignature = request.Headers.GetValues("Keygen-Accept-Signature").Single();
            Body = request.Content is null
                ? string.Empty
                : await request.Content.ReadAsStringAsync(cancellationToken).ConfigureAwait(false);
            return createResponse(request);
        }
    }

    private sealed class FakeKeygenApi(params FishingSignedEntitlementEnvelope[] responses)
        : IKeygenLicenseApi
    {
        private readonly Queue<FishingSignedEntitlementEnvelope> queue = new(responses);

        internal int ValidationCount { get; private set; }

        internal int ActivationCount { get; private set; }

        internal string ActivatedLicenseId { get; private set; } = string.Empty;

        public Task<FishingSignedEntitlementEnvelope> ValidateAsync(
            string licenseKey,
            string machineFingerprint,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            _ = licenseKey;
            _ = machineFingerprint;
            ValidationCount++;
            return Task.FromResult(queue.Dequeue());
        }

        public Task ActivateMachineAsync(
            string licenseKey,
            string licenseId,
            string machineFingerprint,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            _ = licenseKey;
            _ = machineFingerprint;
            ActivationCount++;
            ActivatedLicenseId = licenseId;
            return Task.CompletedTask;
        }
    }

    private sealed class SequenceKeygenApi(params object[] responses) : IKeygenLicenseApi
    {
        private readonly Queue<object> queue = new(responses);

        public Task<FishingSignedEntitlementEnvelope> ValidateAsync(
            string licenseKey,
            string machineFingerprint,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            _ = licenseKey;
            _ = machineFingerprint;
            var next = queue.Dequeue();
            if (next is Exception exception)
            {
                throw exception;
            }
            return Task.FromResult((FishingSignedEntitlementEnvelope)next);
        }

        public Task ActivateMachineAsync(
            string licenseKey,
            string licenseId,
            string machineFingerprint,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            _ = licenseKey;
            _ = licenseId;
            _ = machineFingerprint;
            return Task.CompletedTask;
        }
    }

    private sealed class RecordingEntitlementSink(bool applyResult = true) : IFishingEntitlementRuntimeSink
    {
        internal int ApplyCount { get; private set; }

        internal int RevokeCount { get; private set; }

        public Task<bool> ApplyAsync(
            FishingSignedEntitlementEnvelope envelope,
            FishingKeygenLicenseClaims claims,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            _ = envelope;
            _ = claims;
            ApplyCount++;
            return Task.FromResult(applyResult);
        }

        public Task RevokeAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            RevokeCount++;
            return Task.CompletedTask;
        }
    }

    private sealed class TestSecretProtector : ISecretProtector
    {
        public byte[] Protect(ReadOnlySpan<byte> plaintext) => plaintext.ToArray();

        public byte[] Unprotect(ReadOnlySpan<byte> protectedData) => protectedData.ToArray();
    }
}
