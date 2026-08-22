using System.IO;
using Sonar.Fishing.Ipc.Contracts.V1;
using Sonar.Platform.Ipc.Contracts.V1;
using CatchDispositionContract = Sonar.Fishing.Ipc.Contracts.V1.CatchDisposition;

namespace Sonar.Fishing.Host.EngineIntegration.CatchDisposition;

public sealed record OfflineCatchDispositionDiagnostic(
    bool Keep,
    string Reason);

internal static class CatchDispositionDiagnosticOperation
{
    internal static async Task<OfflineCatchDispositionDiagnostic> ExecuteAsync(
        Stream server,
        EngineSessionIdentity identity,
        string sessionId,
        ulong sequence,
        string? fishId,
        IReadOnlyList<string> selectedFishIds,
        bool inventoryFull,
        CancellationToken cancellationToken)
    {
        var requestId = $"disposition-{Guid.NewGuid():N}";
        var request = OfflineEngineSessionProtocol.CreateEnvelope(
            identity,
            PeerRole.Host,
            MessageKind.Command,
            sessionId,
            sequence,
            requestId: requestId,
            commandId: "evaluate-catch-disposition",
            status: "pending");
        request.EvaluateCatchDispositionRequest = new EvaluateCatchDispositionRequest
        {
            InventoryFull = inventoryFull,
        };
        if (fishId is not null)
        {
            request.EvaluateCatchDispositionRequest.FishId = fishId;
        }
        request.EvaluateCatchDispositionRequest.SelectedFishIds.Add(selectedFishIds);
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
            Envelope.PayloadOneofCase.EvaluateCatchDispositionResult)
        {
            throw new InvalidOperationException("catch_disposition_result_missing");
        }
        var result = resultEnvelope.EvaluateCatchDispositionResult;
        var keep = result.Disposition switch
        {
            CatchDispositionContract.Keep => true,
            CatchDispositionContract.Release => false,
            _ => throw new InvalidOperationException("catch_disposition_unspecified"),
        };
        return new OfflineCatchDispositionDiagnostic(keep, result.Reason);
    }
}
