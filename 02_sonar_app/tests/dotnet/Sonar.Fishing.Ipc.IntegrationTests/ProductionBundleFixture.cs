using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Ipc.Contracts;

namespace Sonar.Fishing.Ipc.IntegrationTests;

internal sealed class ProductionBundleFixture : IDisposable
{
    private ProductionBundleFixture(
        string root,
        string hostPath,
        string enginePath,
        EngineSessionIdentity identity)
    {
        Root = root;
        HostPath = hostPath;
        EnginePath = enginePath;
        Identity = identity;
    }

    internal string Root { get; }

    internal string HostPath { get; }

    internal string EnginePath { get; }

    internal EngineSessionIdentity Identity { get; }

    internal static ProductionBundleFixture Create(string sourceEnginePath)
    {
        var root = Path.Combine(
            Path.GetTempPath(),
            $"sonar-fishing-production-ipc-{Guid.NewGuid():N}");
        Directory.CreateDirectory(root);
        var hostPath = Path.Combine(root, "Sonar.exe");
        var enginePath = Path.Combine(root, "Sonar.Engine.exe");
        File.WriteAllBytes(hostPath, Encoding.UTF8.GetBytes("production-host-test-pair"));
        File.Copy(sourceEnginePath, enginePath);
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
        var identity = BundleSessionIdentityLoader.Load(enginePath, hostPath);
        return new ProductionBundleFixture(root, hostPath, enginePath, identity);
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
