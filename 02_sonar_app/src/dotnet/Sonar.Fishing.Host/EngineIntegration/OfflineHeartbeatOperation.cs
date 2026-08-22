using System.IO;
using Sonar.Fishing.Ipc.Contracts.V1;
using Sonar.Platform.Ipc.Contracts;
using Sonar.Platform.Ipc.Contracts.V1;

namespace Sonar.Fishing.Host.EngineIntegration;

internal static class OfflineHeartbeatOperation
{
    internal static async Task<ulong> ExecuteAsync(
        Stream control,
        EngineSessionIdentity identity,
        string sessionId,
        ulong sequence,
        HeartbeatLivenessTracker tracker,
        CancellationToken cancellationToken)
    {
        await Task.Delay(TimeSpan.FromMilliseconds(2), cancellationToken)
            .ConfigureAwait(false);
        if (!tracker.TryCreateHeartbeat(out var heartbeat, out var reason))
        {
            throw new InvalidOperationException(reason);
        }

        var requestId = $"heartbeat-{heartbeat.HeartbeatId}-{Guid.NewGuid():N}";
        var request = OfflineEngineSessionProtocol.CreateEnvelope(
            identity,
            PeerRole.Host,
            MessageKind.Heartbeat,
            sessionId,
            sequence,
            requestId: requestId,
            status: "pending");
        request.Platform = new PlatformPayload { Heartbeat = heartbeat };
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
            MessageKind.Heartbeat,
            sessionId,
            expectedCorrelationId: requestId);
        if (response.PayloadCase != Envelope.PayloadOneofCase.Platform ||
            response.Platform.PayloadCase !=
                PlatformPayload.PayloadOneofCase.HeartbeatAcknowledged ||
            !tracker.TryAcknowledge(response.Platform.HeartbeatAcknowledged, out reason))
        {
            throw new InvalidOperationException(
                string.IsNullOrEmpty(reason) ? "heartbeat_ack_missing" : reason);
        }
        if (tracker.GetSnapshot().State != HeartbeatLivenessState.Healthy)
        {
            throw new InvalidOperationException("heartbeat_liveness_not_healthy");
        }
        return heartbeat.HeartbeatId;
    }
}
