using Sonar.Licensing.Verification;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal sealed class Ed25519ReleaseSignatureVerifier : IReleaseSignatureVerifier
{
    private readonly byte[] publicKey;

    internal Ed25519ReleaseSignatureVerifier(ReadOnlySpan<byte> publicKey)
    {
        if (publicKey.Length != Ed25519DetachedSignatureVerifier.PublicKeyLength)
        {
            throw new ArgumentException("release_public_key_invalid", nameof(publicKey));
        }
        this.publicKey = publicKey.ToArray();
    }

    public bool Verify(ReadOnlySpan<byte> message, ReadOnlySpan<byte> signature) =>
        Ed25519DetachedSignatureVerifier.Verify(publicKey, message, signature);
}
