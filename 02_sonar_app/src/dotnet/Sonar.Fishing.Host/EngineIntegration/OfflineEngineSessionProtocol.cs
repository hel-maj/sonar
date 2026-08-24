using System.IO;
using Sonar.Fishing.Ipc.Contracts;
using Sonar.Fishing.Ipc.Contracts.V1;
using Sonar.Platform.Ipc.Contracts;
using Sonar.Platform.Ipc.Contracts.V1;
using Sonar.Platform.Ipc.NamedPipes;

namespace Sonar.Fishing.Host.EngineIntegration;

internal static class OfflineEngineSessionProtocol
{
    internal const string OfflineDiagnosticAuthority = "native-cpp-diagnostic-engine";
    internal const string NativeProductionAuthority = "native-cpp-engine";

    private const string CatchQualityCapabilityId = "catch-quality.aggregate";
    private const string CatchDispositionCapabilityId = "catch-disposition.evaluate";
    private const string SessionStatisticsCapabilityId = "fishing-session.statistics";
    private const string RuntimeSettingsCapabilityId = "fishing-runtime-settings.apply";
    private const string SignedEntitlementCapabilityId = "signed-entitlement.verify";
    private const string NotificationEventsCapabilityId = "fishing-notifications.events";

    internal static HandshakeAccepted AcceptHandshake(
        EngineSessionIdentity identity,
        EngineProcessAuthorityMode authorityMode,
        Envelope envelope,
        byte[] expectedNonce,
        string sessionId)
    {
        if (envelope.PayloadCase != Envelope.PayloadOneofCase.Platform ||
            envelope.Platform.PayloadCase != PlatformPayload.PayloadOneofCase.HandshakeHello)
        {
            throw new InvalidOperationException("handshake_hello_missing");
        }
        var requirements = new List<CapabilityRequirement>
        {
            new(CatchQualityCapabilityId, Major: 1, MinimumMinor: 0),
            new(CatchDispositionCapabilityId, Major: 1, MinimumMinor: 0),
            new(SessionStatisticsCapabilityId, Major: 1, MinimumMinor: 0),
            new(RuntimeSettingsCapabilityId, Major: 1, MinimumMinor: 0),
            new(SignedEntitlementCapabilityId, Major: 1, MinimumMinor: 0),
            new(NotificationEventsCapabilityId, Major: 1, MinimumMinor: 0),
        };
        if (authorityMode is EngineProcessAuthorityMode.Production or
            EngineProcessAuthorityMode.DeveloperFullAccess)
        {
            requirements.Add(new CapabilityRequirement(
                "fishing-session.control",
                Major: 1,
                MinimumMinor: 0));
        }
        var allowSideEffects = authorityMode is EngineProcessAuthorityMode.Production or
            EngineProcessAuthorityMode.DeveloperFullAccess;
        if (identity.AuthorityMode != authorityMode ||
            identity.SideEffectsAllowed != allowSideEffects)
        {
            throw new InvalidOperationException("engine_session_identity_mode_mismatch");
        }
        var expectation = new HandshakeExpectation(
            EngineSessionIdentity.ProductId,
            identity.HostBuildId,
            identity.EngineBuildId,
            identity.BundleManifestHash,
            FishingSchemaIdentity.Sha256,
            sessionId,
            sessionGeneration: 1,
            expectedNonce,
            requirements,
            allowSideEffects);
        if (!HandshakeContract.TryAccept(
                envelope.Header,
                envelope.Platform.HandshakeHello,
                expectation,
                out var accepted,
                out var reason))
        {
            throw new InvalidOperationException(reason);
        }
        if (accepted.SideEffectsEnabled != allowSideEffects)
        {
            throw new UnauthorizedAccessException(
                allowSideEffects
                    ? "production_engine_authority_invalid"
                    : "offline_engine_authority_invalid");
        }
        return accepted;
    }

    internal static void ValidateEngineEnvelope(
        EngineSessionIdentity identity,
        Envelope envelope,
        MessageKind messageKind,
        string sessionId,
        string? expectedCorrelationId = null)
    {
        if (!SessionHeaderContract.TryValidate(
                envelope.Header,
                CreateSessionExpectation(identity, sessionId),
                PeerRole.Engine,
                ChannelKind.Control,
                messageKind,
                out var reason))
        {
            throw new InvalidOperationException(reason);
        }
        if (expectedCorrelationId is not null &&
            envelope.Header.CorrelationId != expectedCorrelationId)
        {
            throw new InvalidOperationException("engine_correlation_invalid");
        }
    }

    internal static void ValidateEngineEventEnvelope(
        EngineSessionIdentity identity,
        Envelope envelope,
        MessageKind messageKind,
        string sessionId,
        string? expectedCorrelationId = null)
    {
        if (!SessionHeaderContract.TryValidate(
                envelope.Header,
                CreateSessionExpectation(identity, sessionId),
                PeerRole.Engine,
                ChannelKind.Events,
                messageKind,
                out var reason))
        {
            throw new InvalidOperationException(reason);
        }
        if (expectedCorrelationId is not null &&
            envelope.Header.CorrelationId != expectedCorrelationId)
        {
            throw new InvalidOperationException("engine_event_correlation_invalid");
        }
    }

    internal static Envelope CreateEnvelope(
        EngineSessionIdentity identity,
        PeerRole peerRole,
        MessageKind messageKind,
        string sessionId,
        ulong sequence,
        string requestId = "",
        string commandId = "",
        string status = "") =>
        new()
        {
            Header = new EnvelopeHeader
            {
                ProtocolMajor = ProtocolContract.Major,
                ProtocolMinor = ProtocolContract.Minor,
                ProductId = EngineSessionIdentity.ProductId,
                PeerRole = peerRole,
                HostBuildId = identity.HostBuildId,
                EngineBuildId = identity.EngineBuildId,
                BundleManifestHash = identity.BundleManifestHash,
                SchemaHash = FishingSchemaIdentity.Sha256,
                SessionId = sessionId,
                SessionGeneration = EngineSessionIdentity.SessionGeneration,
                Channel = ChannelKind.Control,
                MessageKind = messageKind,
                RequestId = requestId,
                CommandId = commandId,
                Sequence = sequence,
                CapturedAtUnixMs = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds(),
                Status = status,
            },
        };

    internal static ValueTask WriteEnvelopeAsync(
        Stream stream,
        Envelope envelope,
        CancellationToken cancellationToken) =>
        LengthPrefixedFrameCodec.WriteMessageAsync(
            stream,
            envelope,
            FrameLimits.ControlBytes,
            cancellationToken);

    internal static ValueTask<Envelope> ReadEnvelopeAsync(
        Stream stream,
        CancellationToken cancellationToken) =>
        LengthPrefixedFrameCodec.ReadMessageAsync(
            stream,
            Envelope.Parser,
            FrameLimits.ControlBytes,
            cancellationToken);

    internal static ValueTask<Envelope> ReadEventEnvelopeAsync(
        Stream stream,
        CancellationToken cancellationToken) =>
        LengthPrefixedFrameCodec.ReadMessageAsync(
            stream,
            Envelope.Parser,
            FrameLimits.EventBytes,
            cancellationToken);

    private static SessionIdentityExpectation CreateSessionExpectation(
        EngineSessionIdentity identity,
        string sessionId) =>
        new(
            EngineSessionIdentity.ProductId,
            identity.HostBuildId,
            identity.EngineBuildId,
            identity.BundleManifestHash,
            FishingSchemaIdentity.Sha256,
            sessionId,
            SessionGeneration: EngineSessionIdentity.SessionGeneration);
}
