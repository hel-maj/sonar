using System.IO;
using Google.Protobuf;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Ipc.Contracts.V1;
using Sonar.Platform.Ipc.Contracts.V1;

namespace Sonar.Fishing.Host.EngineIntegration;

internal sealed record OfflineSignedEntitlementDiagnostic(
    FishingEntitlementVerificationResult HostVerification,
    bool EngineAccepted,
    string EngineReason,
    ulong AcceptedGeneration,
    long ExpiresUnixSeconds)
{
    internal bool IndependentlyAccepted => HostVerification.Accepted && EngineAccepted;
}

internal sealed record EngineSignedEntitlementReceipt(
    bool Accepted,
    string Reason,
    ulong AcceptedGeneration,
    long ExpiresUnixSeconds);

internal static class OfflineSignedEntitlementOperation
{
    internal static async Task<OfflineSignedEntitlementDiagnostic> ExecuteAsync(
        Stream control,
        EngineSessionIdentity identity,
        string sessionId,
        ulong sequence,
        FishingSignedEntitlementEnvelope entitlement,
        FishingEntitlementVerificationResult hostVerification,
        CancellationToken cancellationToken)
    {
        if (!hostVerification.Accepted)
        {
            return new OfflineSignedEntitlementDiagnostic(
                hostVerification,
                EngineAccepted: false,
                EngineReason: "host_entitlement_rejected",
                AcceptedGeneration: 0,
                ExpiresUnixSeconds: 0);
        }

        var receipt = await ApplyVerifiedAsync(
            control,
            identity,
            sessionId,
            sequence,
            entitlement,
            cancellationToken).ConfigureAwait(false);
        return new OfflineSignedEntitlementDiagnostic(
            hostVerification,
            receipt.Accepted,
            receipt.Reason,
            receipt.AcceptedGeneration,
            receipt.ExpiresUnixSeconds);
    }

    internal static async Task<EngineSignedEntitlementReceipt> ApplyVerifiedAsync(
        Stream control,
        EngineSessionIdentity identity,
        string sessionId,
        ulong sequence,
        FishingSignedEntitlementEnvelope entitlement,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(entitlement);
        var requestId = $"apply-entitlement-{Guid.NewGuid():N}";
        var request = OfflineEngineSessionProtocol.CreateEnvelope(
            identity,
            PeerRole.Host,
            MessageKind.Command,
            sessionId,
            sequence,
            requestId: requestId,
            commandId: "apply-signed-entitlement",
            status: "pending");
        request.ApplySignedEntitlementRequest = new ApplySignedEntitlementRequest
        {
            Envelope = new SignedEntitlementEnvelope
            {
                Method = entitlement.Method,
                RequestTarget = entitlement.RequestTarget,
                Host = entitlement.Host,
                DateHeader = entitlement.DateHeader,
                DigestHeader = entitlement.DigestHeader,
                SignatureHeader = entitlement.SignatureHeader,
                RawBody = ByteString.CopyFrom(entitlement.RawBody.Span),
            },
        };
        await OfflineEngineSessionProtocol.WriteEnvelopeAsync(
            control,
            request,
            cancellationToken).ConfigureAwait(false);

        var response = await OfflineEngineSessionProtocol.ReadEnvelopeAsync(
            control,
            cancellationToken).ConfigureAwait(false);
        OfflineEngineSessionProtocol.ValidateEngineEnvelope(
            identity,
            response,
            MessageKind.Reply,
            sessionId,
            expectedCorrelationId: requestId);
        if (response.PayloadCase != Envelope.PayloadOneofCase.ApplySignedEntitlementResult)
        {
            throw new InvalidOperationException("signed_entitlement_result_missing");
        }
        var result = response.ApplySignedEntitlementResult;
        if (string.IsNullOrEmpty(result.Reason))
        {
            throw new InvalidOperationException("signed_entitlement_reason_missing");
        }
        return new EngineSignedEntitlementReceipt(
            result.Accepted,
            result.Reason,
            result.AcceptedGeneration,
            result.ExpiresUnixSeconds);
    }

    internal static async Task<ulong> RevokeAsync(
        Stream control,
        EngineSessionIdentity identity,
        string sessionId,
        ulong sequence,
        CancellationToken cancellationToken)
    {
        var requestId = $"revoke-entitlement-{Guid.NewGuid():N}";
        var request = OfflineEngineSessionProtocol.CreateEnvelope(
            identity,
            PeerRole.Host,
            MessageKind.Command,
            sessionId,
            sequence,
            requestId: requestId,
            commandId: "revoke-signed-entitlement",
            status: "pending");
        request.RevokeSignedEntitlementRequest = new RevokeSignedEntitlementRequest();
        await OfflineEngineSessionProtocol.WriteEnvelopeAsync(
            control,
            request,
            cancellationToken).ConfigureAwait(false);

        var response = await OfflineEngineSessionProtocol.ReadEnvelopeAsync(
            control,
            cancellationToken).ConfigureAwait(false);
        OfflineEngineSessionProtocol.ValidateEngineEnvelope(
            identity,
            response,
            MessageKind.Reply,
            sessionId,
            expectedCorrelationId: requestId);
        if (response.PayloadCase != Envelope.PayloadOneofCase.RevokeSignedEntitlementResult ||
            !response.RevokeSignedEntitlementResult.Revoked ||
            !string.Equals(
                response.RevokeSignedEntitlementResult.Reason,
                "entitlement_revoked",
                StringComparison.Ordinal))
        {
            throw new InvalidOperationException("signed_entitlement_revoke_rejected");
        }
        return response.RevokeSignedEntitlementResult.PreviousGeneration;
    }
}
