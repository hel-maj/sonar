using System.IO;
using Sonar.Fishing.Ipc.Contracts.V1;
using Sonar.Platform.Ipc.Contracts.V1;

namespace Sonar.Fishing.Host.EngineIntegration.CatchQuality;

public sealed record OfflineCatchQualityDiagnostic(
    string? NormalizedLabel,
    string StableKey,
    bool Recognized);

internal static class CatchQualityDiagnosticOperation
{
    internal static async Task<OfflineCatchQualityDiagnostic> ExecuteAsync(
        Stream server,
        EngineSessionIdentity identity,
        string sessionId,
        ulong sequence,
        string? rawText,
        CancellationToken cancellationToken)
    {
        var requestId = $"quality-{Guid.NewGuid():N}";
        var request = OfflineEngineSessionProtocol.CreateEnvelope(
            identity,
            PeerRole.Host,
            MessageKind.Command,
            sessionId,
            sequence,
            requestId: requestId,
            commandId: "classify-catch-quality",
            status: "pending");
        request.ClassifyCatchQualityRequest = new ClassifyCatchQualityRequest();
        if (rawText is not null)
        {
            request.ClassifyCatchQualityRequest.RawText = rawText;
        }
        await OfflineEngineSessionProtocol.WriteEnvelopeAsync(
            server,
            request,
            cancellationToken).ConfigureAwait(false);

        var resultEnvelope = await OfflineEngineSessionProtocol.ReadEnvelopeAsync(
            server,
            cancellationToken).ConfigureAwait(false);
        OfflineEngineSessionProtocol.ValidateEngineEnvelope(
            identity,
            resultEnvelope,
            MessageKind.Reply,
            sessionId,
            expectedCorrelationId: requestId);
        if (resultEnvelope.PayloadCase !=
            Envelope.PayloadOneofCase.ClassifyCatchQualityResult)
        {
            throw new InvalidOperationException("catch_quality_result_missing");
        }
        var result = resultEnvelope.ClassifyCatchQualityResult;
        return new OfflineCatchQualityDiagnostic(
            result.HasNormalizedLabel ? result.NormalizedLabel : null,
            result.StableKey,
            result.Recognized);
    }
}
