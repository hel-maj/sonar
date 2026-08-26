using System.IO;
using System.Security.Cryptography;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal sealed record VerifiedDevelopmentBundle(
    string Root,
    string Version,
    string HostSha256,
    string EngineSha256,
    LocalReleaseChannel Channel);

internal static partial class DevelopmentBundleVerifier
{
    private const int MaximumManifestBytes = 64 * 1024;
    private static readonly string[] DevelopmentRootProperties =
    [
        "schemaVersion", "product", "releaseMode", "version", "source", "ipc",
        "host", "engine", "requiredRuntime", "determinism", "authenticode",
    ];
    private static readonly string[] DeveloperFullAccessRootProperties =
    [
        "schemaVersion", "product", "releaseMode", "developerFullAccess",
        "version", "source", "ipc", "host", "engine", "requiredRuntime",
        "determinism", "authenticode",
    ];
    private static readonly string[] ProductProperties =
        ["path", "sha256", "unsignedSha256", "buildId"];

    internal static VerifiedDevelopmentBundle Verify(
        string bundleDirectory,
        LocalReleaseChannel channel = LocalReleaseChannel.DevelopmentUnsigned)
    {
        var root = ReleaseInstallLayout.ValidateSteadyState(bundleDirectory);
        var manifestPath = Path.Combine(root, "bundle-manifest.json");
        var bytes = File.ReadAllBytes(manifestPath);
        if (bytes.Length is 0 or > MaximumManifestBytes)
        {
            throw new InvalidOperationException("development_bundle_manifest_size_invalid");
        }

        try
        {
            using var document = JsonDocument.Parse(bytes, new JsonDocumentOptions
            {
                AllowTrailingCommas = false,
                CommentHandling = JsonCommentHandling.Disallow,
                MaxDepth = 16,
            });
            var rootElement = document.RootElement;
            var (rootProperties, expectedSchemaVersion, expectedReleaseMode,
                developerFullAccess) = channel switch
            {
                LocalReleaseChannel.DevelopmentUnsigned =>
                    (DevelopmentRootProperties, 1, "development-unsigned", false),
                LocalReleaseChannel.DeveloperFullAccessUnsigned =>
                    (DeveloperFullAccessRootProperties, 2,
                        "developer-full-access-unsigned", true),
                _ => throw new InvalidOperationException(
                    "development_bundle_channel_invalid"),
            };
            RequireExactProperties(
                rootElement,
                rootProperties,
                "root");
            if (rootElement.GetProperty("schemaVersion").GetInt32() !=
                    expectedSchemaVersion ||
                rootElement.GetProperty("product").GetString() != "fishing" ||
                rootElement.GetProperty("releaseMode").GetString() !=
                    expectedReleaseMode ||
                (developerFullAccess &&
                 rootElement.GetProperty("developerFullAccess").ValueKind !=
                    JsonValueKind.True))
            {
                throw new InvalidOperationException("development_bundle_identity_invalid");
            }

            var version = rootElement.GetProperty("version").GetString() ?? string.Empty;
            if (!SemanticVersionPattern().IsMatch(version))
            {
                throw new InvalidOperationException("development_bundle_version_invalid");
            }

            var host = VerifyProductPayload(rootElement, root, "host", "Sonar.exe");
            var engine = VerifyProductPayload(
                rootElement,
                root,
                "engine",
                "Sonar.Engine.exe");
            var source = rootElement.GetProperty("source");
            RequireExactProperties(source, ["commitSha", "dirty"], "source");
            var commitSha = source.GetProperty("commitSha").GetString() ?? string.Empty;
            if (!LowerCommitPattern().IsMatch(commitSha) ||
                source.GetProperty("dirty").ValueKind is not
                    (JsonValueKind.True or JsonValueKind.False))
            {
                throw new InvalidOperationException("development_bundle_source_invalid");
            }
            var ipc = rootElement.GetProperty("ipc");
            RequireExactProperties(ipc, ["schema", "schemaSha256"], "ipc");
            if (ipc.GetProperty("schema").GetString() != "ipc/v1/sonar_fishing.proto" ||
                !UpperSha256Pattern().IsMatch(
                    ipc.GetProperty("schemaSha256").GetString() ?? string.Empty))
            {
                throw new InvalidOperationException("development_bundle_ipc_invalid");
            }
            var runtime = rootElement.GetProperty("requiredRuntime");
            RequireExactProperties(
                runtime,
                ["family", "majorVersion", "architecture", "deployment"],
                "runtime");
            if (runtime.GetProperty("family").GetString() !=
                    "Microsoft.WindowsDesktop.App" ||
                runtime.GetProperty("majorVersion").GetInt32() != 10 ||
                runtime.GetProperty("architecture").GetString() != "x64" ||
                runtime.GetProperty("deployment").GetString() !=
                    "framework-dependent-single-file")
            {
                throw new InvalidOperationException("development_bundle_runtime_invalid");
            }
            var determinism = rootElement.GetProperty("determinism");
            RequireExactProperties(
                determinism,
                ["verified", "secondHostSha256", "secondEngineSha256"],
                "determinism");
            if (!determinism.GetProperty("verified").GetBoolean() ||
                determinism.GetProperty("secondHostSha256").GetString() != host ||
                determinism.GetProperty("secondEngineSha256").GetString() != engine)
            {
                throw new InvalidOperationException(
                    "development_bundle_determinism_invalid");
            }
            var authenticode = rootElement.GetProperty("authenticode");
            RequireExactProperties(
                authenticode,
                ["required", "hostStatus", "engineStatus"],
                "authenticode");
            if (authenticode.GetProperty("required").GetBoolean())
            {
                throw new InvalidOperationException(
                    "development_bundle_signature_policy_invalid");
            }

            return new VerifiedDevelopmentBundle(
                root,
                version,
                host,
                engine,
                channel);
        }
        catch (JsonException exception)
        {
            throw new InvalidOperationException(
                "development_bundle_manifest_json_invalid",
                exception);
        }
        catch (InvalidOperationException)
        {
            throw;
        }
        catch (Exception exception) when (
            exception is FormatException or KeyNotFoundException or
                OverflowException)
        {
            throw new InvalidOperationException(
                "development_bundle_manifest_contract_invalid",
                exception);
        }
    }

    internal static int CompareVersions(string left, string right)
    {
        var leftCore = ParseCore(left);
        var rightCore = ParseCore(right);
        for (var index = 0; index < leftCore.Length; index++)
        {
            var comparison = leftCore[index].CompareTo(rightCore[index]);
            if (comparison != 0)
            {
                return comparison;
            }
        }
        return 0;
    }

    private static string VerifyProductPayload(
        JsonElement manifest,
        string root,
        string property,
        string expectedPath)
    {
        var payload = manifest.GetProperty(property);
        RequireExactProperties(payload, ProductProperties, property);
        if (payload.GetProperty("path").GetString() != expectedPath)
        {
            throw new InvalidOperationException("development_bundle_pair_identity_invalid");
        }
        var expectedHash = payload.GetProperty("sha256").GetString() ?? string.Empty;
        var unsignedHash = payload.GetProperty("unsignedSha256").GetString() ?? string.Empty;
        var expectedBuildId = property == "host"
            ? $"fishing-host-{unsignedHash[..Math.Min(16, unsignedHash.Length)].ToLowerInvariant()}"
            : $"fishing-engine-{unsignedHash[..Math.Min(16, unsignedHash.Length)].ToLowerInvariant()}";
        if (!UpperSha256Pattern().IsMatch(expectedHash) ||
            unsignedHash != expectedHash ||
            payload.GetProperty("buildId").GetString() != expectedBuildId)
        {
            throw new InvalidOperationException("development_bundle_pair_identity_invalid");
        }
        using var payloadStream = new FileStream(
            Path.Combine(root, expectedPath),
            FileMode.Open,
            FileAccess.Read,
            FileShare.Read,
            bufferSize: 128 * 1024,
            FileOptions.SequentialScan);
        var actualHash = Convert.ToHexString(SHA256.HashData(payloadStream));
        if (!string.Equals(actualHash, expectedHash, StringComparison.Ordinal))
        {
            throw new InvalidOperationException("development_bundle_content_hash_mismatch");
        }
        return actualHash;
    }

    private static void RequireExactProperties(
        JsonElement element,
        IReadOnlyList<string> expected,
        string context)
    {
        if (element.ValueKind != JsonValueKind.Object)
        {
            throw new InvalidOperationException(
                $"development_bundle_{context}_contract_invalid");
        }
        var actual = element.EnumerateObject().Select(property => property.Name).ToArray();
        if (!actual.SequenceEqual(expected, StringComparer.Ordinal))
        {
            throw new InvalidOperationException(
                $"development_bundle_{context}_contract_invalid");
        }
    }

    private static int[] ParseCore(string value)
    {
        var match = SemanticVersionPattern().Match(value);
        if (!match.Success)
        {
            throw new InvalidOperationException("development_bundle_version_invalid");
        }
        return
        [
            int.Parse(match.Groups[1].Value, System.Globalization.CultureInfo.InvariantCulture),
            int.Parse(match.Groups[2].Value, System.Globalization.CultureInfo.InvariantCulture),
            int.Parse(match.Groups[3].Value, System.Globalization.CultureInfo.InvariantCulture),
        ];
    }

    [GeneratedRegex(
        "^(0|[1-9][0-9]*)\\.(0|[1-9][0-9]*)\\.(0|[1-9][0-9]*)(?:-[0-9A-Za-z-]+(?:\\.[0-9A-Za-z-]+)*)?$",
        RegexOptions.CultureInvariant)]
    private static partial Regex SemanticVersionPattern();

    [GeneratedRegex("^[0-9A-F]{64}$", RegexOptions.CultureInvariant)]
    private static partial Regex UpperSha256Pattern();

    [GeneratedRegex("^[0-9a-f]{40}$", RegexOptions.CultureInvariant)]
    private static partial Regex LowerCommitPattern();
}
