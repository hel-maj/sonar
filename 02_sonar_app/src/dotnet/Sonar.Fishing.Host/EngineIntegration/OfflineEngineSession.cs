using System.Diagnostics;
using System.IO;
using Sonar.Fishing.Host.EngineIntegration.CatchDisposition;
using Sonar.Fishing.Host.EngineIntegration.CatchQuality;
using Sonar.Fishing.Host.EngineIntegration.RuntimeSettings;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Ipc.Contracts.V1;
using Sonar.Platform.Ipc.Contracts;
using Sonar.Platform.Ipc.Contracts.V1;
using Sonar.Platform.Ipc.NamedPipes;

using HostRuntimeSettings = Sonar.Fishing.Host.SettingsPersistence.FishingRuntimeSettings;

namespace Sonar.Fishing.Host.EngineIntegration;

internal sealed class OfflineEngineSession : IAsyncDisposable
{
    private static readonly TimeSpan DisposeTimeout = TimeSpan.FromSeconds(5);

    private readonly LocalPipeServerPair servers;
    private readonly ContainedEngineProcess engineProcess;
    private readonly string sessionId;
    private readonly EngineSessionIdentity identity;
    private readonly SemaphoreSlim commandGate = new(1, 1);
    private readonly HeartbeatLivenessTracker heartbeatTracker;
    private readonly CancellationTokenSource eventPumpCancellation = new();
    private readonly Task eventPumpTask;
    private readonly object eventGate = new();
    private readonly Dictionary<string, TaskCompletionSource<FishingSessionStateSnapshot>>
        pendingSessionSnapshots = new(StringComparer.Ordinal);
    private Exception? eventPumpFailure;
    private ulong lastEventSequence;
    private ulong sequence = 2;
    private bool shutdown;
    private bool disposed;

    private OfflineEngineSession(
        LocalPipeServerPair servers,
        ContainedEngineProcess engineProcess,
        string sessionId,
        EngineSessionIdentity identity,
        uint negotiatedProtocolMinor,
        TimeSpan bootstrapDuration)
    {
        this.servers = servers;
        this.engineProcess = engineProcess;
        this.sessionId = sessionId;
        this.identity = identity;
        heartbeatTracker = new HeartbeatLivenessTracker(
            new HeartbeatLivenessPolicy(
                TimeSpan.FromMilliseconds(1),
                TimeSpan.FromSeconds(1)));
        if (!heartbeatTracker.TryStart(out var reason))
        {
            throw new InvalidOperationException(reason);
        }
        NegotiatedProtocolMinor = negotiatedProtocolMinor;
        BootstrapDuration = bootstrapDuration;
        eventPumpTask = RunEventPumpAsync(eventPumpCancellation.Token);
    }

    internal event Action<FishingSessionStateSnapshot>? SessionSnapshotReceived;

    internal int ProcessId => engineProcess.Id;

    internal bool IsContained => engineProcess.IsContained;

    internal bool IsAlive => !disposed && !engineProcess.Process.HasExited;

    internal uint NegotiatedProtocolMinor { get; }

    internal TimeSpan BootstrapDuration { get; }

    internal Process Process => engineProcess.Process;

    internal static async Task<OfflineEngineSession> StartAsync(
        string engineExecutable,
        TimeSpan timeout,
        CancellationToken cancellationToken) =>
        await StartAsync(
            engineExecutable,
            timeout,
            EngineProcessAuthorityMode.OfflineDiagnostics,
            EngineSessionIdentity.OfflineDiagnostics,
            cancellationToken).ConfigureAwait(false);

    internal static async Task<OfflineEngineSession> StartProductionAsync(
        string engineExecutable,
        TimeSpan timeout,
        EngineSessionIdentity identity,
        CancellationToken cancellationToken) =>
        await StartAsync(
            engineExecutable,
            timeout,
            EngineProcessAuthorityMode.Production,
            identity,
            cancellationToken).ConfigureAwait(false);

    private static async Task<OfflineEngineSession> StartAsync(
        string engineExecutable,
        TimeSpan timeout,
        EngineProcessAuthorityMode authorityMode,
        EngineSessionIdentity identity,
        CancellationToken cancellationToken)
    {
        if (timeout <= TimeSpan.Zero || timeout > TimeSpan.FromSeconds(30))
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }
        ArgumentNullException.ThrowIfNull(identity);
        if (identity.Production !=
            (authorityMode == EngineProcessAuthorityMode.Production))
        {
            throw new InvalidOperationException("engine_session_identity_mode_mismatch");
        }

        var enginePath = OfflineEngineProcessBootstrap.RequireEnginePath(engineExecutable);
        var bootstrap = PipeBootstrap.Create("fishing-it");
        if (bootstrap.ControlPipeName.Length > 160)
        {
            throw new InvalidOperationException("offline_pipe_name_exceeded_native_bound");
        }
        var sessionId = $"it-{Guid.NewGuid():N}";
        var servers = LocalPipeServerPair.Create(
            bootstrap,
            FrameLimits.ControlBytes,
            FrameLimits.EventBytes);
        ContainedEngineProcess? engineProcess = null;
        try
        {
            var startedAt = Stopwatch.GetTimestamp();
            engineProcess = ContainedEngineProcess.Start(
                OfflineEngineProcessBootstrap.CreateStartInfo(
                    enginePath,
                    bootstrap,
                    sessionId,
                    identity,
                    authorityMode));
            if (!engineProcess.IsContained)
            {
                throw new InvalidOperationException("offline_engine_containment_missing");
            }

            using var timeoutSource = CancellationTokenSource.CreateLinkedTokenSource(
                cancellationToken);
            timeoutSource.CancelAfter(timeout);
            var token = timeoutSource.Token;
            await servers.AcceptExpectedClientAsync(
                engineProcess.Id,
                timeout,
                token).ConfigureAwait(false);

            var helloEnvelope = await OfflineEngineSessionProtocol.ReadEnvelopeAsync(
                servers.Control,
                token).ConfigureAwait(false);
            var handshakeAccepted = OfflineEngineSessionProtocol.AcceptHandshake(
                identity,
                authorityMode,
                helloEnvelope,
                bootstrap.Nonce,
                sessionId);
            var accepted = OfflineEngineSessionProtocol.CreateEnvelope(
                identity,
                PeerRole.Host,
                MessageKind.Handshake,
                sessionId,
                sequence: 1,
                status: "accepted");
            accepted.Platform = new PlatformPayload
            {
                HandshakeAccepted = handshakeAccepted,
            };
            await OfflineEngineSessionProtocol.WriteEnvelopeAsync(
                servers.Control,
                accepted,
                token).ConfigureAwait(false);

            return new OfflineEngineSession(
                servers,
                engineProcess,
                sessionId,
                identity,
                handshakeAccepted.NegotiatedProtocolMinor,
                Stopwatch.GetElapsedTime(startedAt));
        }
        catch
        {
            if (engineProcess is not null)
            {
                await engineProcess.DisposeAsync().ConfigureAwait(false);
            }
            await servers.DisposeAsync().ConfigureAwait(false);
            throw;
        }
    }

    internal Task<ulong> PingAsync(CancellationToken cancellationToken) =>
        ExecuteCommandAsync(
            (control, currentSequence, token) => OfflineHeartbeatOperation.ExecuteAsync(
                control,
                identity,
                sessionId,
                currentSequence,
                heartbeatTracker,
                token),
            cancellationToken);

    internal Task<ulong> ApplyRuntimeSettingsAsync(
        HostRuntimeSettings runtimeSettings,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(runtimeSettings);
        runtimeSettings.Validate();
        return ExecuteCommandAsync(
            (control, currentSequence, token) => OfflineRuntimeSettingsOperation.ApplyAsync(
                control,
                identity,
                sessionId,
                currentSequence,
                runtimeSettings,
                token),
            cancellationToken);
    }

    internal Task<FishingSessionStateSnapshot> StartReadOnlySessionAsync(
        CancellationToken cancellationToken) =>
        ExecuteCommandAsync(StartReadOnlySessionCoreAsync, cancellationToken);

    internal Task<FishingSessionStateSnapshot> StartFishingSessionAsync(
        ulong expectedSettingsRevision,
        CancellationToken cancellationToken)
    {
        if (expectedSettingsRevision == 0)
        {
            throw new ArgumentOutOfRangeException(nameof(expectedSettingsRevision));
        }
        return ExecuteCommandAsync(
            (control, currentSequence, token) => StartFishingSessionCoreAsync(
                control,
                currentSequence,
                expectedSettingsRevision,
                token),
            cancellationToken);
    }

    internal Task<FishingSessionStateSnapshot> StopAutomationAsync(
        CancellationToken cancellationToken) =>
        ExecuteCommandAsync(StopAutomationCoreAsync, cancellationToken);

    internal Task<OfflineCatchQualityDiagnostic> ClassifyCatchQualityAsync(
        string? rawText,
        CancellationToken cancellationToken) =>
        ExecuteCommandAsync(
            (control, currentSequence, token) => CatchQualityDiagnosticOperation.ExecuteAsync(
                control,
                identity,
                sessionId,
                currentSequence,
                rawText,
                token),
            cancellationToken);

    internal Task<OfflineCatchDispositionDiagnostic> EvaluateCatchDispositionAsync(
        string? fishId,
        IReadOnlyCollection<string> selectedFishIds,
        bool inventoryFull,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(selectedFishIds);
        var snapshot = selectedFishIds.Select(item =>
        {
            ArgumentNullException.ThrowIfNull(item);
            return item;
        }).ToArray();
        return ExecuteCommandAsync(
            (control, currentSequence, token) => CatchDispositionDiagnosticOperation.ExecuteAsync(
                control,
                identity,
                sessionId,
                currentSequence,
                fishId,
                snapshot,
                inventoryFull,
                token),
            cancellationToken);
    }

    internal Task<OfflineSignedEntitlementDiagnostic> ApplySignedEntitlementAsync(
        FishingSignedEntitlementEnvelope entitlement,
        FishingEntitlementTrustPolicy trust,
        FishingEntitlementClaimPolicy claimsPolicy,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(entitlement);
        ArgumentNullException.ThrowIfNull(trust);
        ArgumentNullException.ThrowIfNull(claimsPolicy);
        var hostVerification = FishingEntitlementVerifier.Verify(
            entitlement,
            trust,
            claimsPolicy);
        if (!hostVerification.Accepted)
        {
            return Task.FromResult(new OfflineSignedEntitlementDiagnostic(
                hostVerification,
                EngineAccepted: false,
                EngineReason: "host_entitlement_rejected",
                AcceptedGeneration: 0,
                ExpiresUnixSeconds: 0));
        }
        return ExecuteCommandAsync(
            (control, currentSequence, token) => OfflineSignedEntitlementOperation.ExecuteAsync(
                control,
                identity,
                sessionId,
                currentSequence,
                entitlement,
                hostVerification,
                token),
            cancellationToken);
    }

    internal Task<EngineSignedEntitlementReceipt> ApplyVerifiedKeygenEntitlementAsync(
        FishingSignedEntitlementEnvelope entitlement,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(entitlement);
        return ExecuteCommandAsync(
            (control, currentSequence, token) =>
                OfflineSignedEntitlementOperation.ApplyVerifiedAsync(
                    control,
                    identity,
                    sessionId,
                    currentSequence,
                    entitlement,
                    token),
            cancellationToken);
    }

    internal Task<ulong> RevokeSignedEntitlementAsync(
        CancellationToken cancellationToken) =>
        ExecuteCommandAsync(
            (control, currentSequence, token) =>
                OfflineSignedEntitlementOperation.RevokeAsync(
                    control,
                    identity,
                    sessionId,
                    currentSequence,
                    token),
            cancellationToken);

    internal async Task ShutdownAsync(CancellationToken cancellationToken)
    {
        if (shutdown || disposed)
        {
            return;
        }
        await commandGate.WaitAsync(cancellationToken).ConfigureAwait(false);
        try
        {
            if (shutdown || disposed)
            {
                return;
            }
            var shutdownId = $"shutdown-{Guid.NewGuid():N}";
            var request = OfflineEngineSessionProtocol.CreateEnvelope(
                identity,
                PeerRole.Host,
                MessageKind.Command,
                sessionId,
                sequence++,
                requestId: shutdownId,
                commandId: "shutdown-engine",
                status: "pending");
            request.Platform = new PlatformPayload
            {
                ShutdownEngine = new ShutdownEngine(),
            };
            await OfflineEngineSessionProtocol.WriteEnvelopeAsync(
                servers.Control,
                request,
                cancellationToken).ConfigureAwait(false);
            var response = await OfflineEngineSessionProtocol.ReadEnvelopeAsync(
                servers.Control,
                cancellationToken).ConfigureAwait(false);
            OfflineEngineSessionProtocol.ValidateEngineEnvelope(
                identity,
                response,
                MessageKind.Reply,
                sessionId,
                expectedCorrelationId: shutdownId);
            if (response.PayloadCase != Envelope.PayloadOneofCase.Platform ||
                response.Platform.PayloadCase != PlatformPayload.PayloadOneofCase.ShutdownReady)
            {
                throw new InvalidOperationException("shutdown_ready_missing");
            }
            shutdown = true;
            await engineProcess.Process.WaitForExitAsync(cancellationToken).ConfigureAwait(false);
            if (engineProcess.Process.ExitCode != 0)
            {
                throw new InvalidOperationException(
                    $"offline_engine_exit_{engineProcess.Process.ExitCode}");
            }
        }
        finally
        {
            commandGate.Release();
        }
    }

    public async ValueTask DisposeAsync()
    {
        if (disposed)
        {
            return;
        }

        using var timeout = new CancellationTokenSource(DisposeTimeout);
        try
        {
            if (!shutdown && IsAlive)
            {
                await ShutdownAsync(timeout.Token).ConfigureAwait(false);
            }
        }
        catch (Exception exception) when (
            exception is OperationCanceledException or IOException or InvalidOperationException)
        {
            // Closing the Common Job below is the crash-safe fallback.
        }
        finally
        {
            disposed = true;
            heartbeatTracker.Stop();
            eventPumpCancellation.Cancel();
            try
            {
                await eventPumpTask.ConfigureAwait(false);
            }
            catch (Exception exception) when (
                exception is OperationCanceledException or IOException)
            {
            }
            await servers.DisposeAsync().ConfigureAwait(false);
            await engineProcess.DisposeAsync().ConfigureAwait(false);
            eventPumpCancellation.Dispose();
            commandGate.Dispose();
        }
    }

    private async Task<FishingSessionStateSnapshot> StartReadOnlySessionCoreAsync(
        Stream control,
        ulong currentSequence,
        CancellationToken cancellationToken)
    {
        var requestId = $"start-session-{Guid.NewGuid():N}";
        var request = OfflineEngineSessionProtocol.CreateEnvelope(
            identity,
            PeerRole.Host,
            MessageKind.Command,
            sessionId,
            currentSequence,
            requestId: requestId,
            commandId: "start-engine-session",
            status: "pending");
        request.Platform = new PlatformPayload
        {
            StartEngineSession = new StartEngineSession { ReadOnly = true },
        };
        var snapshotTask = ExpectSessionSnapshotAsync(requestId, cancellationToken);
        try
        {
            await OfflineEngineSessionProtocol.WriteEnvelopeAsync(
                control,
                request,
                cancellationToken).ConfigureAwait(false);

            var reply = await OfflineEngineSessionProtocol.ReadEnvelopeAsync(
                control,
                cancellationToken).ConfigureAwait(false);
            OfflineEngineSessionProtocol.ValidateEngineEnvelope(
                identity,
                reply,
                MessageKind.Reply,
                sessionId,
                expectedCorrelationId: requestId);
            if (reply.PayloadCase != Envelope.PayloadOneofCase.Platform ||
                reply.Platform.PayloadCase != PlatformPayload.PayloadOneofCase.CommandResult ||
                reply.Platform.CommandResult.CommandId != "start-engine-session" ||
                reply.Platform.CommandResult.Status != "completed")
            {
                throw new InvalidOperationException("start_read_only_session_rejected");
            }

            return await snapshotTask.ConfigureAwait(false);
        }
        catch
        {
            AbandonExpectedSessionSnapshot(requestId);
            throw;
        }
    }

    private async Task<FishingSessionStateSnapshot> StartFishingSessionCoreAsync(
        Stream control,
        ulong currentSequence,
        ulong expectedSettingsRevision,
        CancellationToken cancellationToken)
    {
        var requestId = $"start-fishing-{Guid.NewGuid():N}";
        var request = OfflineEngineSessionProtocol.CreateEnvelope(
            identity,
            PeerRole.Host,
            MessageKind.Command,
            sessionId,
            currentSequence,
            requestId: requestId,
            commandId: "start-fishing-session",
            status: "pending");
        request.StartFishingSessionRequest = new StartFishingSessionRequest
        {
            ExpectedRevision = expectedSettingsRevision,
        };
        var snapshotTask = ExpectSessionSnapshotAsync(requestId, cancellationToken);
        try
        {
            await OfflineEngineSessionProtocol.WriteEnvelopeAsync(
                control,
                request,
                cancellationToken).ConfigureAwait(false);
            await RequireCompletedCommandAsync(
                control,
                requestId,
                "start-fishing-session",
                cancellationToken).ConfigureAwait(false);
            return await snapshotTask.ConfigureAwait(false);
        }
        catch
        {
            AbandonExpectedSessionSnapshot(requestId);
            throw;
        }
    }

    private async Task<FishingSessionStateSnapshot> StopAutomationCoreAsync(
        Stream control,
        ulong currentSequence,
        CancellationToken cancellationToken)
    {
        var requestId = $"stop-fishing-{Guid.NewGuid():N}";
        var request = OfflineEngineSessionProtocol.CreateEnvelope(
            identity,
            PeerRole.Host,
            MessageKind.Command,
            sessionId,
            currentSequence,
            requestId: requestId,
            commandId: "stop-automation",
            status: "pending");
        request.Platform = new PlatformPayload
        {
            StopAutomation = new StopAutomation(),
        };
        var snapshotTask = ExpectSessionSnapshotAsync(requestId, cancellationToken);
        try
        {
            await OfflineEngineSessionProtocol.WriteEnvelopeAsync(
                control,
                request,
                cancellationToken).ConfigureAwait(false);
            await RequireCompletedCommandAsync(
                control,
                requestId,
                "stop-automation",
                cancellationToken).ConfigureAwait(false);
            return await snapshotTask.ConfigureAwait(false);
        }
        catch
        {
            AbandonExpectedSessionSnapshot(requestId);
            throw;
        }
    }

    private async Task RequireCompletedCommandAsync(
        Stream control,
        string requestId,
        string commandId,
        CancellationToken cancellationToken)
    {
        var response = await OfflineEngineSessionProtocol.ReadEnvelopeAsync(
            control,
            cancellationToken).ConfigureAwait(false);
        OfflineEngineSessionProtocol.ValidateEngineEnvelope(
            identity,
            response,
            MessageKind.Reply,
            sessionId,
            expectedCorrelationId: requestId);
        if (response.PayloadCase != Envelope.PayloadOneofCase.Platform ||
            response.Platform.PayloadCase != PlatformPayload.PayloadOneofCase.CommandResult ||
            !string.Equals(response.Platform.CommandResult.CommandId, commandId, StringComparison.Ordinal))
        {
            throw new InvalidOperationException("engine_command_result_missing");
        }
        var result = response.Platform.CommandResult;
        if (!string.Equals(result.Status, "completed", StringComparison.Ordinal))
        {
            throw new EngineCommandRejectedException(
                commandId,
                string.IsNullOrWhiteSpace(result.Reason)
                    ? "engine_command_rejected"
                    : result.Reason);
        }
    }

    private Task<FishingSessionStateSnapshot> ExpectSessionSnapshotAsync(
        string requestId,
        CancellationToken cancellationToken)
    {
        lock (eventGate)
        {
            if (eventPumpFailure is not null)
            {
                throw new InvalidOperationException(
                    "engine_event_pump_failed",
                    eventPumpFailure);
            }
            var completion = new TaskCompletionSource<FishingSessionStateSnapshot>(
                TaskCreationOptions.RunContinuationsAsynchronously);
            if (!pendingSessionSnapshots.TryAdd(requestId, completion))
            {
                throw new InvalidOperationException(
                    "engine_event_correlation_already_pending");
            }
            return completion.Task.WaitAsync(cancellationToken);
        }
    }

    private void AbandonExpectedSessionSnapshot(string requestId)
    {
        TaskCompletionSource<FishingSessionStateSnapshot>? completion;
        lock (eventGate)
        {
            pendingSessionSnapshots.Remove(requestId, out completion);
        }
        completion?.TrySetCanceled();
    }

    private async Task RunEventPumpAsync(CancellationToken cancellationToken)
    {
        try
        {
            while (!cancellationToken.IsCancellationRequested)
            {
                var envelope = await OfflineEngineSessionProtocol.ReadEventEnvelopeAsync(
                    servers.Events,
                    cancellationToken).ConfigureAwait(false);
                OfflineEngineSessionProtocol.ValidateEngineEventEnvelope(
                    identity,
                    envelope,
                    MessageKind.Snapshot,
                    sessionId);
                if (envelope.Header.Sequence <= lastEventSequence)
                {
                    throw new InvalidOperationException("engine_event_sequence_replayed");
                }
                if (string.IsNullOrWhiteSpace(envelope.Header.CorrelationId) ||
                    envelope.PayloadCase != Envelope.PayloadOneofCase.FishingSessionSnapshot)
                {
                    throw new InvalidOperationException("fishing_session_snapshot_invalid");
                }
                lastEventSequence = envelope.Header.Sequence;
                var snapshot = FishingSessionWireMapper.Map(
                    envelope.FishingSessionSnapshot);
                TaskCompletionSource<FishingSessionStateSnapshot>? completion;
                lock (eventGate)
                {
                    pendingSessionSnapshots.Remove(
                        envelope.Header.CorrelationId,
                        out completion);
                }
                completion?.TrySetResult(snapshot);
                SessionSnapshotReceived?.Invoke(snapshot);
            }
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
        }
        catch (Exception exception)
        {
            TaskCompletionSource<FishingSessionStateSnapshot>[] pending;
            lock (eventGate)
            {
                eventPumpFailure = exception;
                pending = pendingSessionSnapshots.Values.ToArray();
                pendingSessionSnapshots.Clear();
            }
            foreach (var completion in pending)
            {
                completion.TrySetException(new InvalidOperationException(
                    "engine_event_pump_failed",
                    exception));
            }
            throw;
        }
    }

    private async Task<T> ExecuteCommandAsync<T>(
        Func<Stream, ulong, CancellationToken, Task<T>> operation,
        CancellationToken cancellationToken)
    {
        ObjectDisposedException.ThrowIf(disposed, this);
        if (shutdown || !IsAlive)
        {
            throw new InvalidOperationException("offline_engine_session_closed");
        }
        await commandGate.WaitAsync(cancellationToken).ConfigureAwait(false);
        try
        {
            return await operation(
                servers.Control,
                sequence++,
                cancellationToken).ConfigureAwait(false);
        }
        finally
        {
            commandGate.Release();
        }
    }
}
