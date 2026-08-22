using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Ipc.Contracts;
using Sonar.Platform.Ipc.NamedPipes;

namespace Sonar.Fishing.Host.Tests;

internal static class EngineSessionIdentityTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("production_engine_identity_is_bound_to_verified_bundle_pair", VerifiedBundlePair),
        new("production_engine_identity_rejects_tampered_pair", RejectsTamperedPair),
        new("production_engine_bootstrap_carries_exact_pair_identity", BootstrapCarriesIdentity),
    ];

    private static void VerifiedBundlePair()
    {
        using var bundle = TestBundle.Create();
        var identity = BundleSessionIdentityLoader.Load(bundle.EnginePath, bundle.HostPath);

        TestAssert.Equal(bundle.HostBuildId, identity.HostBuildId, "Host build identity changed");
        TestAssert.Equal(bundle.EngineBuildId, identity.EngineBuildId, "Engine build identity changed");
        TestAssert.Equal(
            bundle.ManifestSha256,
            identity.BundleManifestHash,
            "Manifest identity was not derived from the verified bytes");
        TestAssert.True(identity.Production, "Verified bundle did not create production identity");
    }

    private static void RejectsTamperedPair()
    {
        using var bundle = TestBundle.Create();
        File.AppendAllText(bundle.EnginePath, "tamper", Encoding.UTF8);
        var error = TestAssert.Throws<InvalidDataException>(
            () => BundleSessionIdentityLoader.Load(bundle.EnginePath, bundle.HostPath),
            "Hash-damaged Engine was accepted");
        TestAssert.Equal(
            "bundle_engine_hash_mismatch",
            error.Message,
            "Hash failure reason changed");
    }

    private static void BootstrapCarriesIdentity()
    {
        using var bundle = TestBundle.Create();
        var identity = BundleSessionIdentityLoader.Load(bundle.EnginePath, bundle.HostPath);
        var bootstrap = PipeBootstrap.Create("fishing-identity-test");
        var startInfo = OfflineEngineProcessBootstrap.CreateStartInfo(
            bundle.EnginePath,
            bootstrap,
            "identity-session",
            identity,
            EngineProcessAuthorityMode.Production);

        TestAssert.Equal(
            identity.HostBuildId,
            startInfo.Environment["SONAR_FISHING_HOST_BUILD_ID"]!,
            "Host build identity was not passed to Engine");
        TestAssert.Equal(
            identity.EngineBuildId,
            startInfo.Environment["SONAR_FISHING_ENGINE_BUILD_ID"]!,
            "Engine build identity was not passed to Engine");
        TestAssert.Equal(
            identity.BundleManifestHash,
            startInfo.Environment["SONAR_FISHING_BUNDLE_MANIFEST_HASH"]!,
            "Manifest identity was not passed to Engine");
        TestAssert.Equal(
            "production",
            startInfo.Environment["SONAR_FISHING_ENGINE_MODE"]!,
            "Production authority mode was not passed to Engine");
        TestAssert.True(
            !startInfo.Environment.ContainsKey("SONAR_FISHING_OFFLINE_GATE"),
            "Production bootstrap retained the offline authority gate");
    }

    private sealed class TestBundle : IDisposable
    {
        private TestBundle(
            string root,
            string hostPath,
            string enginePath,
            string hostBuildId,
            string engineBuildId,
            string manifestSha256)
        {
            Root = root;
            HostPath = hostPath;
            EnginePath = enginePath;
            HostBuildId = hostBuildId;
            EngineBuildId = engineBuildId;
            ManifestSha256 = manifestSha256;
        }

        internal string Root { get; }

        internal string EnginePath { get; }

        internal string HostPath { get; }

        internal string HostBuildId { get; }

        internal string EngineBuildId { get; }

        internal string ManifestSha256 { get; }

        internal static TestBundle Create()
        {
            var root = Path.Combine(
                Path.GetTempPath(),
                $"sonar-fishing-bundle-identity-{Guid.NewGuid():N}");
            Directory.CreateDirectory(root);
            var hostPath = Path.Combine(root, "Sonar.exe");
            var enginePath = Path.Combine(root, "Sonar.Engine.exe");
            File.WriteAllBytes(hostPath, Encoding.UTF8.GetBytes("host-pair-v1"));
            File.WriteAllBytes(enginePath, Encoding.UTF8.GetBytes("engine-pair-v1"));
            var hostHash = Sha256(hostPath);
            var engineHash = Sha256(enginePath);
            var hostBuildId = $"fishing-host-{hostHash[..16].ToLowerInvariant()}";
            var engineBuildId = $"fishing-engine-{engineHash[..16].ToLowerInvariant()}";
            var manifest = new
            {
                schemaVersion = 1,
                product = "fishing",
                releaseMode = "development-unsigned",
                version = "0.0.0-test",
                source = new { commitSha = new string('0', 40), dirty = true },
                ipc = new
                {
                    schema = "ipc/v1/sonar_fishing.proto",
                    schemaSha256 = FishingSchemaIdentity.Sha256,
                },
                host = new
                {
                    path = "Sonar.exe",
                    sha256 = hostHash,
                    unsignedSha256 = hostHash,
                    buildId = hostBuildId,
                },
                engine = new
                {
                    path = "Sonar.Engine.exe",
                    sha256 = engineHash,
                    unsignedSha256 = engineHash,
                    buildId = engineBuildId,
                },
                requiredRuntime = new { family = "Microsoft.WindowsDesktop.App" },
                determinism = new { verified = true },
                authenticode = new { required = false },
            };
            var manifestBytes = Encoding.UTF8.GetBytes(JsonSerializer.Serialize(manifest) + "\n");
            File.WriteAllBytes(Path.Combine(root, "bundle-manifest.json"), manifestBytes);
            return new TestBundle(
                root,
                hostPath,
                enginePath,
                hostBuildId,
                engineBuildId,
                Convert.ToHexString(SHA256.HashData(manifestBytes)));
        }

        public void Dispose()
        {
            if (Directory.Exists(Root))
            {
                Directory.Delete(Root, recursive: true);
            }
        }

        private static string Sha256(string path) =>
            Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path)));
    }
}
