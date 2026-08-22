using Sonar.Licensing.Verification;

namespace Sonar.Fishing.Host.Licensing;

internal sealed class FishingSignedEntitlementEnvelope
{
    private readonly byte[] rawBody;

    internal FishingSignedEntitlementEnvelope(
        string method,
        string requestTarget,
        string host,
        string dateHeader,
        string digestHeader,
        string signatureHeader,
        ReadOnlySpan<byte> rawBody)
    {
        Method = method ?? throw new ArgumentNullException(nameof(method));
        RequestTarget = requestTarget ?? throw new ArgumentNullException(nameof(requestTarget));
        Host = host ?? throw new ArgumentNullException(nameof(host));
        DateHeader = dateHeader ?? throw new ArgumentNullException(nameof(dateHeader));
        DigestHeader = digestHeader ?? throw new ArgumentNullException(nameof(digestHeader));
        SignatureHeader = signatureHeader ?? throw new ArgumentNullException(nameof(signatureHeader));
        this.rawBody = rawBody.ToArray();
    }

    internal string Method { get; }

    internal string RequestTarget { get; }

    internal string Host { get; }

    internal string DateHeader { get; }

    internal string DigestHeader { get; }

    internal string SignatureHeader { get; }

    internal ReadOnlyMemory<byte> RawBody => rawBody;

    internal SignedHttpResponseEnvelope ToCommonEnvelope() => new(
        Method,
        RequestTarget,
        Host,
        DateHeader,
        DigestHeader,
        SignatureHeader,
        rawBody);
}
