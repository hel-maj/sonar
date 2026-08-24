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
        new("engine_bootstrap_scrubs_ambient_authority_environment", BootstrapScrubsAmbientAuthority),
        new("developer_bundle_is_rejected_by_production_identity_path", ProductionRejectsDeveloperBundle),
        new("developer_bundle_authority_is_compile_isolated", DeveloperAuthorityIsCompileIsolated),
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

    private static void ProductionRejectsDeveloperBundle()
    {
        using var bundle = TestBundle.Create(developerFullAccess: true);
        _ = TestAssert.Throws<InvalidDataException>(
            () => BundleSessionIdentityLoader.Load(bundle.EnginePath, bundle.HostPath),
            "Production identity path accepted a developer-full-access manifest");
    }

    private static void BootstrapScrubsAmbientAuthority()
    {
        string[] names =
        [
            "SONAR_FISHING_OFFLINE_GATE",
            "SONAR_FISHING_ENGINE_MODE",
            "SONAR_FISHING_HOST_BUILD_ID",
            "SONAR_FISHING_ENGINE_BUILD_ID",
            "SONAR_FISHING_BUNDLE_MANIFEST_HASH",
        ];
        var previous = names.ToDictionary(
            static name => name,
            Environment.GetEnvironmentVariable,
            StringComparer.Ordinal);
        try
        {
            foreach (var name in names)
            {
                Environment.SetEnvironmentVariable(name, "stale-parent-value");
            }

            using var bundle = TestBundle.Create();
            var identity = BundleSessionIdentityLoader.Load(bundle.EnginePath, bundle.HostPath);
            var production = OfflineEngineProcessBootstrap.CreateStartInfo(
                bundle.EnginePath,
                PipeBootstrap.Create("fishing-production-environment-test"),
                "production-environment-session",
                identity,
                EngineProcessAuthorityMode.Production);
            TestAssert.True(
                !production.Environment.ContainsKey("SONAR_FISHING_OFFLINE_GATE"),
                "Production bootstrap retained an inherited offline gate");
            TestAssert.Equal(
                "production",
                production.Environment["SONAR_FISHING_ENGINE_MODE"]!,
                "Production bootstrap did not replace an inherited mode");

            var offline = OfflineEngineProcessBootstrap.CreateStartInfo(
                bundle.EnginePath,
                PipeBootstrap.Create("fishing-offline-environment-test"),
                "offline-environment-session",
                EngineSessionIdentity.OfflineDiagnostics);
            TestAssert.Equal(
                "1",
                offline.Environment["SONAR_FISHING_OFFLINE_GATE"]!,
                "Offline bootstrap did not replace an inherited gate");
            TestAssert.True(
                !offline.Environment.ContainsKey("SONAR_FISHING_ENGINE_MODE"),
                "Offline bootstrap retained an inherited production mode");
            TestAssert.True(
                !offline.Environment.ContainsKey("SONAR_FISHING_HOST_BUILD_ID") &&
                !offline.Environment.ContainsKey("SONAR_FISHING_ENGINE_BUILD_ID") &&
                !offline.Environment.ContainsKey("SONAR_FISHING_BUNDLE_MANIFEST_HASH"),
                "Offline bootstrap retained inherited production identity");
        }
        finally
        {
            foreach (var pair in previous)
            {
                Environment.SetEnvironmentVariable(pair.Key, pair.Value);
            }
        }
    }

    private static void DeveloperAuthorityIsCompileIsolated()
    {
        using var bundle = TestBundle.Create(developerFullAccess: true);
#if SONAR_FISHING_DEVELOPER_FULL_ACCESS
        var identity = BundleSessionIdentityLoader.Load(
            bundle.EnginePath,
            bundle.HostPath,
            EngineProcessAuthorityMode.DeveloperFullAccess);
        TestAssert.True(
            identity.DeveloperFullAccess,
            "Developer manifest did not create developer identity");
        var bootstrap = PipeBootstrap.Create("fishing-developer-identity-test");
        var startInfo = OfflineEngineProcessBootstrap.CreateStartInfo(
            bundle.EnginePath,
            bootstrap,
            "developer-identity-session",
            identity,
            EngineProcessAuthorityMode.DeveloperFullAccess);
        TestAssert.Equal(
            "developer-full-access",
            startInfo.Environment["SONAR_FISHING_ENGINE_MODE"]!,
            "Developer authority mode was not bound to Engine bootstrap");
#else
        var error = TestAssert.Throws<InvalidOperationException>(
            () => BundleSessionIdentityLoader.Load(
                bundle.EnginePath,
                bundle.HostPath,
                EngineProcessAuthorityMode.DeveloperFullAccess),
            "Production Host loaded developer authority");
        TestAssert.Equal(
            "developer_full_access_not_compiled",
            error.Message,
            "Production developer rejection reason changed");
#endif
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

        internal static TestBundle Create(bool developerFullAccess = false)
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
            var manifest = new Dictionary<string, object?>
            {
                ["schemaVersion"] = developerFullAccess ? 2 : 1,
                ["product"] = "fishing",
                ["releaseMode"] = developerFullAccess
                    ? "developer-full-access-unsigned"
                    : "development-unsigned",
            };
            if (developerFullAccess)
            {
                manifest["developerFullAccess"] = true;
            }
            manifest["version"] = "0.0.0-test";
            manifest["source"] = new { commitSha = new string('0', 40), dirty = true };
            manifest["ipc"] = new
            {
                schema = "ipc/v1/sonar_fishing.proto",
                schemaSha256 = FishingSchemaIdentity.Sha256,
            };
            manifest["host"] = new
            {
                path = "Sonar.exe",
                sha256 = hostHash,
                unsignedSha256 = hostHash,
                buildId = hostBuildId,
            };
            manifest["engine"] = new
            {
                path = "Sonar.Engine.exe",
                sha256 = engineHash,
                unsignedSha256 = engineHash,
                buildId = engineBuildId,
            };
            manifest["requiredRuntime"] = new { family = "Microsoft.WindowsDesktop.App" };
            manifest["determinism"] = new { verified = true };
            manifest["authenticode"] = new { required = false };
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
