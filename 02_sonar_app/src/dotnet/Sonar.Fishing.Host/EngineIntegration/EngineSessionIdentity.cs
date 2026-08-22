using System.IO;
using System.Text.RegularExpressions;

namespace Sonar.Fishing.Host.EngineIntegration;

internal sealed partial record EngineSessionIdentity
{
    internal const string ProductId = "fishing";
    internal const uint SessionGeneration = 1;

    private EngineSessionIdentity(
        string hostBuildId,
        string engineBuildId,
        string bundleManifestHash,
        bool production)
    {
        HostBuildId = hostBuildId;
        EngineBuildId = engineBuildId;
        BundleManifestHash = bundleManifestHash;
        Production = production;
    }

    internal string HostBuildId { get; }

    internal string EngineBuildId { get; }

    internal string BundleManifestHash { get; }

    internal bool Production { get; }

    internal static EngineSessionIdentity OfflineDiagnostics { get; } = new(
        "offline-host-0.1.0",
        "offline-engine-0.1.0",
        "offline-bundle-manifest",
        production: false);

    internal static EngineSessionIdentity CreateProduction(
        string hostBuildId,
        string engineBuildId,
        string bundleManifestHash)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(hostBuildId);
        ArgumentException.ThrowIfNullOrWhiteSpace(engineBuildId);
        ArgumentException.ThrowIfNullOrWhiteSpace(bundleManifestHash);
        if (!HostBuildIdPattern().IsMatch(hostBuildId))
        {
            throw new InvalidDataException("bundle_host_build_id_invalid");
        }
        if (!EngineBuildIdPattern().IsMatch(engineBuildId))
        {
            throw new InvalidDataException("bundle_engine_build_id_invalid");
        }
        if (!Sha256Pattern().IsMatch(bundleManifestHash))
        {
            throw new InvalidDataException("bundle_manifest_hash_invalid");
        }
        return new EngineSessionIdentity(
            hostBuildId,
            engineBuildId,
            bundleManifestHash.ToUpperInvariant(),
            production: true);
    }

    [GeneratedRegex("^fishing-host-[0-9a-f]{16}$", RegexOptions.CultureInvariant)]
    private static partial Regex HostBuildIdPattern();

    [GeneratedRegex("^fishing-engine-[0-9a-f]{16}$", RegexOptions.CultureInvariant)]
    private static partial Regex EngineBuildIdPattern();

    [GeneratedRegex("^[0-9A-Fa-f]{64}$", RegexOptions.CultureInvariant)]
    private static partial Regex Sha256Pattern();
}
