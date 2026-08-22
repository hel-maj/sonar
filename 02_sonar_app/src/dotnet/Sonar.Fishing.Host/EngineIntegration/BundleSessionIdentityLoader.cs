using System.IO;
using System.Security.Cryptography;
using System.Text.Json;
using Sonar.Fishing.Ipc.Contracts;

namespace Sonar.Fishing.Host.EngineIntegration;

internal static class BundleSessionIdentityLoader
{
    private const int MaximumManifestBytes = 64 * 1024;

    private static readonly string[] RootProperties =
    [
        "schemaVersion", "product", "releaseMode", "version", "source", "ipc",
        "host", "engine", "requiredRuntime", "determinism", "authenticode",
    ];

    internal static EngineSessionIdentity Load(string engineExecutable)
    {
        var hostExecutable = Environment.ProcessPath;
        if (string.IsNullOrWhiteSpace(hostExecutable))
        {
            throw new InvalidDataException("bundle_host_process_path_missing");
        }
        return Load(engineExecutable, hostExecutable);
    }

    internal static EngineSessionIdentity Load(
        string engineExecutable,
        string hostExecutable)
    {
        var enginePath = Path.GetFullPath(engineExecutable);
        var bundleDirectory = Path.GetDirectoryName(enginePath)
            ?? throw new InvalidDataException("bundle_directory_missing");
        var expectedEnginePath = Path.Combine(bundleDirectory, "Sonar.Engine.exe");
        if (!string.Equals(
                enginePath,
                expectedEnginePath,
                StringComparison.OrdinalIgnoreCase))
        {
            throw new InvalidDataException("bundle_engine_path_invalid");
        }
        var hostPath = Path.GetFullPath(hostExecutable);
        var expectedHostPath = Path.Combine(bundleDirectory, "Sonar.exe");
        if (!string.Equals(
                hostPath,
                expectedHostPath,
                StringComparison.OrdinalIgnoreCase))
        {
            throw new InvalidDataException("bundle_host_process_path_invalid");
        }

        var manifestPath = Path.Combine(bundleDirectory, "bundle-manifest.json");
        var manifestBytes = ReadBounded(manifestPath);
        using var document = ParseStrict(manifestBytes);
        var root = document.RootElement;
        RequireExactProperties(root, RootProperties, "bundle_manifest_root_invalid");
        if (root.GetProperty("schemaVersion").GetInt32() != 1 ||
            root.GetProperty("product").GetString() != EngineSessionIdentity.ProductId)
        {
            throw new InvalidDataException("bundle_manifest_identity_invalid");
        }
        var releaseMode = root.GetProperty("releaseMode").GetString();
        if (releaseMode is not ("development-unsigned" or "production-signed"))
        {
            throw new InvalidDataException("bundle_manifest_mode_invalid");
        }

        var ipc = root.GetProperty("ipc");
        RequireExactProperties(
            ipc,
            ["schema", "schemaSha256"],
            "bundle_manifest_ipc_invalid");
        if (ipc.GetProperty("schema").GetString() != "ipc/v1/sonar_fishing.proto" ||
            !HashEquals(
                ipc.GetProperty("schemaSha256").GetString(),
                FishingSchemaIdentity.Sha256))
        {
            throw new InvalidDataException("bundle_manifest_schema_invalid");
        }

        var host = root.GetProperty("host");
        var engine = root.GetProperty("engine");
        RequirePairDescriptor(host, "Sonar.exe", "fishing-host-", "host");
        RequirePairDescriptor(engine, "Sonar.Engine.exe", "fishing-engine-", "engine");

        RequireFileHash(hostPath, host.GetProperty("sha256").GetString(), "host");
        RequireFileHash(enginePath, engine.GetProperty("sha256").GetString(), "engine");

        return EngineSessionIdentity.CreateProduction(
            host.GetProperty("buildId").GetString()!,
            engine.GetProperty("buildId").GetString()!,
            Convert.ToHexString(SHA256.HashData(manifestBytes)));
    }

    private static byte[] ReadBounded(string path)
    {
        using var stream = new FileStream(
            path,
            FileMode.Open,
            FileAccess.Read,
            FileShare.Read,
            bufferSize: 4096,
            FileOptions.SequentialScan);
        if (stream.Length <= 0 || stream.Length > MaximumManifestBytes)
        {
            throw new InvalidDataException("bundle_manifest_size_invalid");
        }
        var bytes = new byte[stream.Length];
        stream.ReadExactly(bytes);
        return bytes;
    }

    private static JsonDocument ParseStrict(byte[] bytes)
    {
        try
        {
            return JsonDocument.Parse(
                bytes,
                new JsonDocumentOptions
                {
                    AllowTrailingCommas = false,
                    CommentHandling = JsonCommentHandling.Disallow,
                    MaxDepth = 12,
                });
        }
        catch (JsonException exception)
        {
            throw new InvalidDataException("bundle_manifest_json_invalid", exception);
        }
    }

    private static void RequirePairDescriptor(
        JsonElement descriptor,
        string expectedPath,
        string buildIdPrefix,
        string context)
    {
        RequireExactProperties(
            descriptor,
            ["path", "sha256", "unsignedSha256", "buildId"],
            $"bundle_manifest_{context}_invalid");
        var path = descriptor.GetProperty("path").GetString();
        var sha256 = descriptor.GetProperty("sha256").GetString();
        var unsignedSha256 = descriptor.GetProperty("unsignedSha256").GetString();
        var buildId = descriptor.GetProperty("buildId").GetString();
        if (path != expectedPath || !IsSha256(sha256) || !IsSha256(unsignedSha256) ||
            buildId != buildIdPrefix + unsignedSha256![..16].ToLowerInvariant())
        {
            throw new InvalidDataException($"bundle_manifest_{context}_invalid");
        }
    }

    private static void RequireExactProperties(
        JsonElement element,
        IReadOnlyList<string> expected,
        string reason)
    {
        if (element.ValueKind != JsonValueKind.Object ||
            !element.EnumerateObject().Select(item => item.Name).SequenceEqual(
                expected,
                StringComparer.Ordinal))
        {
            throw new InvalidDataException(reason);
        }
    }

    private static void RequireFileHash(string path, string? expected, string context)
    {
        if (!IsSha256(expected) || !File.Exists(path))
        {
            throw new InvalidDataException($"bundle_{context}_missing");
        }
        using var stream = new FileStream(
            path,
            FileMode.Open,
            FileAccess.Read,
            FileShare.Read,
            bufferSize: 64 * 1024,
            FileOptions.SequentialScan);
        var actual = Convert.ToHexString(SHA256.HashData(stream));
        if (!HashEquals(expected, actual))
        {
            throw new InvalidDataException($"bundle_{context}_hash_mismatch");
        }
    }

    private static bool HashEquals(string? left, string right) =>
        left is not null && string.Equals(left, right, StringComparison.OrdinalIgnoreCase);

    private static bool IsSha256(string? value) =>
        value is { Length: 64 } && value.All(character =>
            character is >= '0' and <= '9' or >= 'A' and <= 'F');
}
