namespace Sonar.Fishing.Host.UpdateRuntime;

internal sealed record ReleaseFileDescriptor(
    string Path,
    long Bytes,
    string Sha256,
    Uri DownloadUri);

internal sealed record ProductReleaseManifest(
    string Version,
    long Generation,
    IReadOnlyList<ReleaseFileDescriptor> Files,
    byte[] SignedEnvelope)
{
    internal bool IsNewerThan(string currentVersion) =>
        System.Version.TryParse(currentVersion, out var current) &&
        System.Version.TryParse(Version, out var target) &&
        target > current;
}

internal sealed record ReleaseManifestVerificationResult(
    bool Verified,
    ProductReleaseManifest? Manifest,
    string Reason)
{
    internal static ReleaseManifestVerificationResult Failure(string reason) =>
        new(false, null, reason);
}

internal interface IReleaseSignatureVerifier
{
    bool Verify(ReadOnlySpan<byte> message, ReadOnlySpan<byte> signature);
}
