using System.IO;
using System.Net;
using System.Net.Http;
using System.Security.Cryptography;
using System.Text;
using Sonar.Fishing.Host.UpdateRuntime;

namespace Sonar.Fishing.Host.Tests;

internal static class UpdateRuntimeTests
{
    private static readonly byte[] ValidSignature = new byte[64];

    public static IReadOnlyList<TestCase> Create() =>
    [
        new("release_manifest_is_exact_signed_and_fail_closed", ManifestIsExact),
        new("release_http_payload_source_is_headers_only_and_bounded", HttpPayloadSourceIsBounded),
        new("release_staging_is_bounded_hash_verified_and_recoverable", StagingIsBounded),
        new("release_swap_preserves_state_logs_and_exact_allowlist", SwapPreservesUserState),
        new("release_swap_exception_rolls_back_old_pair", SwapExceptionRollsBack),
        new("release_recovery_rolls_back_interrupted_generation", InterruptedGenerationRecovers),
        new("release_staging_rejects_non_newer_version", NonNewerVersionIsRejected),
        new("uninstall_plan_requires_exact_confirmation_and_safe_install_root", UninstallPlanIsSafe),
    ];

    private static void ManifestIsExact()
    {
        var signatureVerifier = new RecordingSignatureVerifier();
        var verifier = new SignedReleaseManifestVerifier(signatureVerifier);
        var envelope = EnvelopeJson(Payloads());
        var result = verifier.Verify(envelope);
        TestAssert.True(result.Verified && result.Manifest is not null,
            $"Valid signed manifest failed: {result.Reason}");
        TestAssert.True(
            result.Manifest!.Files.Select(file => file.Path).SequenceEqual(
                ReleaseInstallLayout.ReleaseFiles,
                StringComparer.Ordinal),
            "Signed release payload order changed");
        TestAssert.True(
            signatureVerifier.Message!.SequenceEqual(
                SignedReleaseManifestVerifier.CanonicalPayload(
                    result.Manifest.Version,
                    result.Manifest.Generation,
                    result.Manifest.Files)),
            "Release signature did not cover the canonical payload");

        var extraProperty = Encoding.UTF8.GetBytes(
            Encoding.UTF8.GetString(envelope).Replace(
                "\"signature\"",
                "\"unexpected\":true,\"signature\"",
                StringComparison.Ordinal));
        TestAssert.Equal(
            "release_manifest_contract_invalid",
            verifier.Verify(extraProperty).Reason,
            "Unknown release property was accepted");

        var unsafeUrl = Encoding.UTF8.GetBytes(
            Encoding.UTF8.GetString(envelope).Replace(
                "https://updates.example.test/engine",
                "http://updates.example.test/engine",
                StringComparison.Ordinal));
        TestAssert.Equal(
            "release_files_invalid",
            verifier.Verify(unsafeUrl).Reason,
            "Plain HTTP release payload was accepted");

        signatureVerifier.Accept = false;
        TestAssert.Equal(
            "release_signature_invalid",
            verifier.Verify(envelope).Reason,
            "Invalid release signature was accepted");
    }

    private static void HttpPayloadSourceIsBounded()
    {
        var bytes = Encoding.UTF8.GetBytes("verified-release-payload");
        var descriptor = new ReleaseFileDescriptor(
            "Sonar.exe",
            bytes.LongLength,
            Convert.ToHexString(SHA256.HashData(bytes)),
            new Uri("https://updates.example.test/host"));
        using var client = new HttpClient(new StubHttpHandler((request) =>
        {
            TestAssert.Equal(
                descriptor.DownloadUri.AbsoluteUri,
                request.RequestUri?.AbsoluteUri ?? string.Empty,
                "Release transport changed the signed payload URI");
            return new HttpResponseMessage(HttpStatusCode.OK)
            {
                Content = new ByteArrayContent(bytes),
            };
        }));
        var source = new HttpReleasePayloadSource(client);
        using var stream = source.OpenReadAsync(descriptor, CancellationToken.None)
            .AsTask().GetAwaiter().GetResult();
        using var copied = new MemoryStream();
        stream.CopyTo(copied);
        TestAssert.True(
            copied.ToArray().SequenceEqual(bytes),
            "Release transport changed verified response bytes");

        using var invalidLengthClient = new HttpClient(new StubHttpHandler((_) =>
            new HttpResponseMessage(HttpStatusCode.OK)
            {
                Content = new ByteArrayContent(bytes[..^1]),
            }));
        TestAssert.Throws<InvalidOperationException>(
            () => new HttpReleasePayloadSource(invalidLengthClient)
                .OpenReadAsync(descriptor, CancellationToken.None)
                .AsTask().GetAwaiter().GetResult(),
            "Release transport accepted a mismatched Content-Length");
    }

    private static void StagingIsBounded()
    {
        using var install = TempInstall.Create();
        var payloads = Payloads();
        var manifest = Manifest(payloads, "1.0.1");
        var stager = new ReleasePayloadStager(new MemoryPayloadSource(payloads));
        var staged = stager.StageAsync(
                manifest,
                "1.0.0",
                1,
                install.Root,
                CancellationToken.None)
            .AsTask().GetAwaiter().GetResult();
        TestAssert.True(
            Directory.Exists(staged.StagingDirectory),
            "Verified release staging directory was not retained by its lease");
        ReleaseInstallLayout.ValidatePayloadDirectory(staged.StagingDirectory);
        staged.DisposeAsync().AsTask().GetAwaiter().GetResult();
        TestAssert.True(
            !Directory.Exists(staged.StagingDirectory),
            "Disposed release staging lease left transaction files behind");

        var damaged = payloads.ToDictionary(pair => pair.Key, pair => pair.Value.ToArray());
        damaged["Sonar.exe"][0] ^= 0x7F;
        TestAssert.Throws<InvalidOperationException>(
            () => stagerWith(damaged).StageAsync(
                    manifest,
                    "1.0.0",
                    1,
                    install.Root,
                    CancellationToken.None)
                .AsTask().GetAwaiter().GetResult(),
            "Hash-damaged release payload was accepted");
        TestAssert.True(
            !Directory.EnumerateDirectories(install.Root, ".update-*").Any(),
            "Failed release staging left transaction files behind");

        static ReleasePayloadStager stagerWith(IReadOnlyDictionary<string, byte[]> values) =>
            new(new MemoryPayloadSource(values));
    }

    private static void SwapPreservesUserState()
    {
        using var install = TempInstall.Create();
        Directory.CreateDirectory(Path.Combine(install.Root, "config"));
        Directory.CreateDirectory(Path.Combine(install.Root, "logs"));
        File.WriteAllText(Path.Combine(install.Root, "config", "state.dat"), "user-state");
        File.WriteAllText(Path.Combine(install.Root, "logs", "current.log"), "bounded-log");

        var payloads = Payloads();
        var staged = new ReleasePayloadStager(new MemoryPayloadSource(payloads))
            .StageAsync(
                Manifest(payloads, "1.0.1"),
                "1.0.0",
                1,
                install.Root,
                CancellationToken.None)
            .AsTask().GetAwaiter().GetResult();
        ReleaseSwapTransaction.Apply(staged);

        foreach (var payload in payloads)
        {
            TestAssert.True(
                File.ReadAllBytes(Path.Combine(install.Root, payload.Key))
                    .SequenceEqual(payload.Value),
                $"Activated release payload changed: {payload.Key}");
        }
        TestAssert.Equal(
            "user-state",
            File.ReadAllText(Path.Combine(install.Root, "config", "state.dat")),
            "Update transaction changed state.dat");
        TestAssert.Equal(
            "bounded-log",
            File.ReadAllText(Path.Combine(install.Root, "logs", "current.log")),
            "Update transaction changed logs");
        TestAssert.True(
            !Directory.EnumerateDirectories(install.Root, ".update-*").Any() &&
            !Directory.EnumerateDirectories(install.Root, ".rollback-*").Any(),
            "Successful update left staging or rollback artifacts");
        ReleaseInstallLayout.ValidateSteadyState(install.Root);
    }

    private static void NonNewerVersionIsRejected()
    {
        using var install = TempInstall.Create();
        var payloads = Payloads();
        var exception = TestAssert.Throws<InvalidOperationException>(
            () => new ReleasePayloadStager(new MemoryPayloadSource(payloads))
                .StageAsync(
                    Manifest(payloads, "1.0.0"),
                    "1.0.0",
                    1,
                    install.Root,
                    CancellationToken.None)
                .AsTask().GetAwaiter().GetResult(),
            "Equal release version was accepted");
        TestAssert.Equal(
            "release_version_not_newer",
            exception.Message,
            "Non-newer release rejection reason changed");

        TestAssert.Throws<InvalidOperationException>(
            () => new ReleasePayloadStager(new MemoryPayloadSource(payloads))
                .StageAsync(
                    Manifest(payloads, "1.0.1"),
                    "1.0.0",
                    2,
                    install.Root,
                    CancellationToken.None)
                .AsTask().GetAwaiter().GetResult(),
            "Replayed release generation was accepted");
    }

    private static void SwapExceptionRollsBack()
    {
        using var install = TempInstall.Create();
        var old = ReleaseInstallLayout.ReleaseFiles.ToDictionary(
            path => path,
            path => File.ReadAllBytes(Path.Combine(install.Root, path)),
            StringComparer.Ordinal);
        var payloads = Payloads();
        var staged = new ReleasePayloadStager(new MemoryPayloadSource(payloads))
            .StageAsync(
                Manifest(payloads, "1.0.1"),
                "1.0.0",
                1,
                install.Root,
                CancellationToken.None)
            .AsTask().GetAwaiter().GetResult();

        TestAssert.Throws<InvalidOperationException>(
            () => ReleaseSwapTransaction.Apply(
                staged,
                moveIndex =>
                {
                    if (moveIndex == 4)
                    {
                        throw new IOException("simulated_interruption");
                    }
                }),
            "Injected update failure did not abort activation");
        foreach (var payload in old)
        {
            TestAssert.True(
                File.ReadAllBytes(Path.Combine(install.Root, payload.Key))
                    .SequenceEqual(payload.Value),
                $"Exception rollback did not restore {payload.Key}");
        }
        TestAssert.True(
            !Directory.EnumerateDirectories(install.Root, ".rollback-*").Any(),
            "Exception rollback left backup state behind");
        staged.DisposeAsync().AsTask().GetAwaiter().GetResult();
        ReleaseInstallLayout.ValidateSteadyState(install.Root);
    }

    private static void InterruptedGenerationRecovers()
    {
        using var install = TempInstall.Create();
        var old = ReleaseInstallLayout.ReleaseFiles.ToDictionary(
            path => path,
            path => File.ReadAllBytes(Path.Combine(install.Root, path)),
            StringComparer.Ordinal);
        var payloads = Payloads();
        var staged = new ReleasePayloadStager(new MemoryPayloadSource(payloads))
            .StageAsync(
                Manifest(payloads, "1.0.1"),
                "1.0.0",
                1,
                install.Root,
                CancellationToken.None)
            .AsTask().GetAwaiter().GetResult();
        var transactionId = Path.GetFileName(staged.StagingDirectory)[".update-".Length..];
        var rollback = Path.Combine(install.Root, $".rollback-{transactionId}");
        Directory.CreateDirectory(rollback);

        foreach (var file in ReleaseInstallLayout.ReleaseFiles.Take(2))
        {
            File.Move(Path.Combine(install.Root, file), Path.Combine(rollback, file));
        }
        File.Move(
            Path.Combine(staged.StagingDirectory, "Sonar.Engine.exe"),
            Path.Combine(install.Root, "Sonar.Engine.exe"));

        ReleaseSwapRecovery.Recover(install.Root);
        foreach (var payload in old)
        {
            TestAssert.True(
                File.ReadAllBytes(Path.Combine(install.Root, payload.Key))
                    .SequenceEqual(payload.Value),
                $"Crash recovery did not restore {payload.Key}");
        }
        TestAssert.True(
            !Directory.EnumerateDirectories(install.Root, ".update-*").Any() &&
            !Directory.EnumerateDirectories(install.Root, ".rollback-*").Any(),
            "Crash recovery left transaction artifacts behind");
        ReleaseInstallLayout.ValidateSteadyState(install.Root);
    }

    private static void UninstallPlanIsSafe()
    {
        using var install = TempInstall.Create();
        TestAssert.Throws<InvalidOperationException>(
            () => SafeUninstallPlan.Create(install.Root, "yes"),
            "Uninstall plan accepted an approximate confirmation");
        var plan = SafeUninstallPlan.Create(
            install.Root,
            SafeUninstallPlan.ConfirmationPhrase);
        TestAssert.True(
            plan.RelativePaths.SequenceEqual(
                ReleaseInstallLayout.ReleaseFiles.OrderBy(path => path, StringComparer.Ordinal),
                StringComparer.Ordinal),
            "Uninstall plan escaped the exact release payload");

        File.WriteAllText(Path.Combine(install.Root, "unexpected.dll"), "not-allowed");
        TestAssert.Throws<InvalidOperationException>(
            () => SafeUninstallPlan.Create(
                install.Root,
                SafeUninstallPlan.ConfirmationPhrase),
            "Uninstall plan accepted an unknown loose dependency");

        File.Delete(Path.Combine(install.Root, "unexpected.dll"));
        Directory.CreateDirectory(Path.Combine(install.Root, "unexpected-empty"));
        TestAssert.Throws<InvalidOperationException>(
            () => SafeUninstallPlan.Create(
                install.Root,
                SafeUninstallPlan.ConfirmationPhrase),
            "Uninstall plan accepted an unknown empty directory");

        using var sourceTree = TempInstall.Create();
        Directory.CreateDirectory(Path.Combine(sourceTree.Root, "src"));
        Directory.CreateDirectory(Path.Combine(sourceTree.Root, "tests"));
        TestAssert.Throws<InvalidOperationException>(
            () => SafeUninstallPlan.Create(
                sourceTree.Root,
                SafeUninstallPlan.ConfirmationPhrase),
            "Uninstall plan accepted a source tree");
    }

    private static Dictionary<string, byte[]> Payloads() => new(StringComparer.Ordinal)
    {
        ["Sonar.Engine.exe"] = Encoding.UTF8.GetBytes("new-engine"),
        ["Sonar.exe"] = Encoding.UTF8.GetBytes("new-host"),
        ["bundle-manifest.json"] = Encoding.UTF8.GetBytes("{\"format_version\":1}"),
    };

    private static ProductReleaseManifest Manifest(
        IReadOnlyDictionary<string, byte[]> payloads,
        string version) =>
        new(
            version,
            2,
            Descriptors(payloads),
            EnvelopeJson(payloads));

    private static IReadOnlyList<ReleaseFileDescriptor> Descriptors(
        IReadOnlyDictionary<string, byte[]> payloads) =>
        ReleaseInstallLayout.ReleaseFiles.Select((path, index) =>
            new ReleaseFileDescriptor(
                path,
                payloads[path].LongLength,
                Convert.ToHexString(SHA256.HashData(payloads[path])),
                new Uri($"https://updates.example.test/{new[] { "engine", "host", "manifest" }[index]}")))
            .ToArray();

    private static byte[] EnvelopeJson(IReadOnlyDictionary<string, byte[]> payloads)
    {
        var descriptors = Descriptors(payloads);
        var files = string.Join(
            ",",
            descriptors.Select(file =>
                $"{{\"path\":\"{file.Path}\",\"bytes\":{file.Bytes}," +
                $"\"sha256\":\"{file.Sha256}\",\"download_url\":\"{file.DownloadUri.AbsoluteUri}\"}}"));
        var signature = Convert.ToBase64String(ValidSignature)
            .TrimEnd('=').Replace('+', '-').Replace('/', '_');
        return Encoding.UTF8.GetBytes(
            $"{{\"format_version\":1,\"product\":\"Sonar Fishing\"," +
            $"\"version\":\"1.0.1\",\"generation\":2,\"files\":[{files}]," +
            $"\"signature\":\"{signature}\"}}");
    }

    private sealed class RecordingSignatureVerifier : IReleaseSignatureVerifier
    {
        internal bool Accept { get; set; } = true;
        internal byte[]? Message { get; private set; }

        public bool Verify(ReadOnlySpan<byte> message, ReadOnlySpan<byte> signature)
        {
            Message = message.ToArray();
            return Accept && signature.SequenceEqual(ValidSignature);
        }
    }

    private sealed class MemoryPayloadSource : IReleasePayloadSource
    {
        private readonly IReadOnlyDictionary<string, byte[]> payloads;

        internal MemoryPayloadSource(IReadOnlyDictionary<string, byte[]> payloads)
        {
            this.payloads = payloads;
        }

        public ValueTask<Stream> OpenReadAsync(
            ReleaseFileDescriptor descriptor,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            return ValueTask.FromResult<Stream>(
                new MemoryStream(payloads[descriptor.Path], writable: false));
        }
    }

    private sealed class StubHttpHandler : HttpMessageHandler
    {
        private readonly Func<HttpRequestMessage, HttpResponseMessage> responder;

        internal StubHttpHandler(Func<HttpRequestMessage, HttpResponseMessage> responder)
        {
            this.responder = responder;
        }

        protected override Task<HttpResponseMessage> SendAsync(
            HttpRequestMessage request,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            var response = responder(request);
            response.RequestMessage ??= request;
            return Task.FromResult(response);
        }
    }

    private sealed class TempInstall : IDisposable
    {
        private TempInstall(string root)
        {
            Root = root;
        }

        internal string Root { get; }

        internal static TempInstall Create()
        {
            var root = Path.Combine(
                Path.GetTempPath(),
                $"sonar-fishing-update-tests-{Guid.NewGuid():N}");
            Directory.CreateDirectory(root);
            File.WriteAllText(Path.Combine(root, "Sonar.Engine.exe"), "old-engine");
            File.WriteAllText(Path.Combine(root, "Sonar.exe"), "old-host");
            File.WriteAllText(Path.Combine(root, "bundle-manifest.json"), "old-manifest");
            return new TempInstall(root);
        }

        public void Dispose()
        {
            if (Directory.Exists(Root))
            {
                Directory.Delete(Root, recursive: true);
            }
        }
    }
}
