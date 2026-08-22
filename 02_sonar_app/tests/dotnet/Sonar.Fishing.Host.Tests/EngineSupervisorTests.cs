using System.IO;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.EngineIntegration.Supervision;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.Tests;

internal static class EngineSupervisorTests
{
    private static readonly EngineRestartPolicy ManualCyclePolicy = new(
        MaximumFailures: 3,
        FailureWindow: TimeSpan.FromMinutes(1),
        HeartbeatInterval: TimeSpan.FromMinutes(1));

    public static IReadOnlyList<TestCase> Create() =>
    [
        new("engine_supervisor_reuses_one_healthy_generation", ReusesHealthyGeneration),
        new("engine_supervisor_restarts_one_unexpected_exit", RestartsUnexpectedExit),
        new("engine_supervisor_opens_bounded_restart_circuit", OpensRestartCircuit),
        new("engine_supervisor_caller_cancellation_preserves_session", CallerCancellationPreservesSession),
        new("engine_supervisor_terminal_stop_cancels_start_and_prevents_restart", TerminalStopCancelsStart),
        new("engine_supervisor_concurrent_terminal_stop_is_idempotent", ConcurrentStopIsIdempotent),
        new("engine_supervisor_rejects_uncontained_candidate", RejectsUncontainedCandidate),
        new("engine_automation_uses_current_settings_and_preserves_rejection", AutomationUsesCurrentSettings),
    ];

    private static void ReusesHealthyGeneration()
    {
        var session = new FakeSession(processId: 4101);
        var factory = new FakeFactory(_ => Task.FromResult<IEngineManagedSession>(session));
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);

        var first = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        var second = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.Equal<ulong>(1, first.Generation, "Initial Engine generation changed");
        TestAssert.Equal(first.ProcessId, second.ProcessId, "Healthy Engine process was replaced");
        TestAssert.Equal(0, second.RestartCount, "Healthy Engine reported a restart");
        TestAssert.Equal(1, factory.StartCount, "Healthy Engine factory ran twice");
        TestAssert.Equal(1, session.PingCount, "Health recheck did not use the existing session");
        TestAssert.Equal(1, session.DisposeCount, "Terminal stop did not dispose the session once");
    }

    private static void RestartsUnexpectedExit()
    {
        var firstSession = new FakeSession(processId: 4201);
        var secondSession = new FakeSession(processId: 4202);
        var factory = FakeFactory.FromSessions(firstSession, secondSession);
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);

        var first = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        firstSession.IsAlive = false;
        var recovered = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.Equal<ulong>(1, first.Generation, "Initial generation changed");
        TestAssert.Equal<ulong>(2, recovered.Generation, "Recovered generation did not advance");
        TestAssert.Equal(4202, recovered.ProcessId, "Replacement Engine identity changed");
        TestAssert.Equal(1, recovered.RestartCount, "Unexpected exit restart was not counted");
        TestAssert.Equal(1, recovered.FailuresInWindow, "Crash budget did not retain the exit");
        TestAssert.Equal(1, firstSession.DisposeCount, "Exited generation was not retired once");
        TestAssert.Equal(1, secondSession.DisposeCount, "Replacement survived terminal cleanup");
    }

    private static void OpensRestartCircuit()
    {
        var firstSession = new FakeSession(processId: 4301);
        var factory = new FakeFactory(
            _ => Task.FromResult<IEngineManagedSession>(firstSession),
            _ => Task.FromException<IEngineManagedSession>(new IOException("first_restart_failed")),
            _ => Task.FromException<IEngineManagedSession>(new IOException("second_restart_failed")));
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);

        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        firstSession.IsAlive = false;
        TestAssert.Throws<InvalidOperationException>(
            () => supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult(),
            "First replacement failure was accepted");
        var circuitFailure = CaptureFailure(
            () => supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult());
        var startCountAtOpen = factory.StartCount;
        var repeatedFailure = CaptureFailure(
            () => supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult());
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.Equal(
            "engine_supervisor_restart_circuit_open",
            circuitFailure.Message,
            "Restart budget did not open with a stable reason");
        TestAssert.Equal(
            circuitFailure.Message,
            repeatedFailure.Message,
            "Open circuit changed its terminal reason");
        TestAssert.Equal(startCountAtOpen, factory.StartCount, "Open circuit started another Engine");
        TestAssert.Equal(1, firstSession.DisposeCount, "Crashed generation was retired more than once");
    }

    private static void CallerCancellationPreservesSession()
    {
        var session = new FakeSession(processId: 4401);
        var factory = FakeFactory.FromSessions(session);
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);
        var first = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        session.BlockPing = true;
        using var cancellation = new CancellationTokenSource();

        var cancelledCheck = supervisor.CheckAsync(cancellation.Token);
        TestAssert.True(
            session.PingStarted.Task.Wait(TimeSpan.FromSeconds(2)),
            "Blocking heartbeat did not start");
        cancellation.Cancel();
        TestAssert.Throws<OperationCanceledException>(
            () => cancelledCheck.GetAwaiter().GetResult(),
            "Caller cancellation was converted into an Engine failure");
        session.BlockPing = false;
        var afterCancellation = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.Equal(first.ProcessId, afterCancellation.ProcessId, "Cancellation replaced Engine");
        TestAssert.Equal<ulong>(1, afterCancellation.Generation, "Cancellation advanced generation");
        TestAssert.Equal(0, afterCancellation.FailuresInWindow, "Cancellation consumed crash budget");
    }

    private static void TerminalStopCancelsStart()
    {
        var factory = new BlockingFactory();
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);

        var start = supervisor.CheckAsync(CancellationToken.None);
        TestAssert.True(
            factory.Started.Task.Wait(TimeSpan.FromSeconds(2)),
            "Blocking Engine start did not begin");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
        TestAssert.Throws<OperationCanceledException>(
            () => start.GetAwaiter().GetResult(),
            "Terminal stop did not cancel in-flight bootstrap");
        var stopped = CaptureFailure(
            () => supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult());

        TestAssert.True(factory.CancellationObserved, "Factory did not observe terminal cancellation");
        TestAssert.Equal(1, factory.StartCount, "Terminal stop allowed a restart");
        TestAssert.Equal("engine_supervisor_stopped", stopped.Message, "Stopped reason changed");
    }

    private static void RejectsUncontainedCandidate()
    {
        var session = new FakeSession(processId: 4501) { IsContained = false };
        var factory = FakeFactory.FromSessions(session);
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);

        var failure = CaptureFailure(
            () => supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult());
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.Equal("engine_supervisor_start_failed", failure.Message, "Containment failure changed");
        TestAssert.True(
            failure.InnerException?.Message == "engine_supervisor_containment_missing",
            "Containment failure lost its stable inner reason");
        TestAssert.Equal(1, session.DisposeCount, "Uncontained candidate was not disposed once");
    }

    private static void ConcurrentStopIsIdempotent()
    {
        var session = new FakeSession(processId: 4451);
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(session),
            ManualCyclePolicy);
        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();

        var first = supervisor.DisposeAsync().AsTask();
        var second = supervisor.DisposeAsync().AsTask();
        Task.WhenAll(first, second).GetAwaiter().GetResult();

        TestAssert.Equal(1, session.DisposeCount, "Concurrent stop disposed Engine twice");
    }

    private static void AutomationUsesCurrentSettings()
    {
        var session = new FakeSession(processId: 4461);
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(session),
            ManualCyclePolicy);
        var entitlement = new FishingSignedEntitlementEnvelope(
            "POST",
            "/v1/licenses/actions/validate-key",
            "api.keygen.sh",
            "date",
            "digest",
            "signature",
            [1]);
        var receipt = supervisor.ApplyVerifiedKeygenEntitlementAsync(
            entitlement,
            CancellationToken.None).GetAwaiter().GetResult();
        var settings = FishingRuntimeSettings.CreateDefault(revision: 17);
        var runtime = new EngineFishingAutomationRuntime(supervisor, () => settings);

        var started = runtime.StartAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(receipt.Accepted, "Fake entitlement was not accepted");
        TestAssert.True(runtime.HasActiveEntitlement, "Accepted entitlement was not retained");
        TestAssert.Equal<ulong>(17, session.LastSettingsRevision, "Start did not pass current settings");
        TestAssert.True(started.Running, "Start snapshot did not become active");

        settings = FishingRuntimeSettings.CreateDefault(revision: 18);
        session.RejectStart = true;
        _ = TestAssert.Throws<EngineCommandRejectedException>(
            () => runtime.StartAsync(CancellationToken.None).GetAwaiter().GetResult(),
            "Guarded Engine rejection was hidden");
        var stillHealthy = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(4461, stillHealthy.ProcessId, "Guard rejection retired a healthy Engine");
        TestAssert.Equal(0, stillHealthy.FailuresInWindow, "Guard rejection consumed crash budget");

        supervisor.RevokeSignedEntitlementAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(!runtime.HasActiveEntitlement, "Revoked entitlement remained active");
        _ = TestAssert.Throws<EngineCommandRejectedException>(
            () => runtime.StartAsync(CancellationToken.None).GetAwaiter().GetResult(),
            "Host sent a start command without active entitlement");
        var stopped = runtime.StopAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(!stopped.Running, "Fail-safe stop required an active entitlement");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
    }

    private static InvalidOperationException CaptureFailure(Action action)
    {
        try
        {
            action();
        }
        catch (InvalidOperationException exception)
        {
            return exception;
        }
        throw new InvalidOperationException("Expected InvalidOperationException was not thrown");
    }

    private sealed class FakeFactory(
        params Func<CancellationToken, Task<IEngineManagedSession>>[] starts)
        : IEngineManagedSessionFactory
    {
        private readonly Queue<Func<CancellationToken, Task<IEngineManagedSession>>> pending =
            new(starts);

        public int StartCount { get; private set; }

        public Task<IEngineManagedSession> StartAsync(CancellationToken cancellationToken)
        {
            StartCount++;
            if (!pending.TryDequeue(out var start))
            {
                throw new InvalidOperationException("unexpected_fake_engine_start");
            }
            return start(cancellationToken);
        }

        internal static FakeFactory FromSessions(params FakeSession[] sessions) => new(
            sessions.Select<FakeSession, Func<CancellationToken, Task<IEngineManagedSession>>>(
                session => _ => Task.FromResult<IEngineManagedSession>(session)).ToArray());
    }

    private sealed class BlockingFactory : IEngineManagedSessionFactory
    {
        public TaskCompletionSource Started { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        public int StartCount { get; private set; }

        public bool CancellationObserved { get; private set; }

        public async Task<IEngineManagedSession> StartAsync(CancellationToken cancellationToken)
        {
            StartCount++;
            Started.TrySetResult();
            try
            {
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken).ConfigureAwait(false);
            }
            catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
            {
                CancellationObserved = true;
                throw;
            }
            throw new InvalidOperationException("unreachable");
        }
    }

    private sealed class FakeSession(int processId) :
        IEngineManagedSession,
        IEngineEntitlementSession,
        IEngineAutomationSession
    {
        public TaskCompletionSource PingStarted { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        public int ProcessId { get; } = processId;

        public bool IsContained { get; set; } = true;

        public bool IsAlive { get; set; } = true;

        public uint NegotiatedProtocolMinor => 0;

        public TimeSpan BootstrapDuration => TimeSpan.FromMilliseconds(4);

        public FishingSessionStateSnapshot SessionState { get; private set; } =
            FishingSessionStateSnapshot.Empty;

        public int PingCount { get; private set; }

        public int DisposeCount { get; private set; }

        public bool BlockPing { get; set; }

        public bool RejectStart { get; set; }

        public ulong LastSettingsRevision { get; private set; }

        public async Task PingAsync(CancellationToken cancellationToken)
        {
            PingCount++;
            PingStarted.TrySetResult();
            if (BlockPing)
            {
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken)
                    .ConfigureAwait(false);
            }
        }

        public Task<EngineSignedEntitlementReceipt> ApplyVerifiedKeygenEntitlementAsync(
            FishingSignedEntitlementEnvelope entitlement,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            ArgumentNullException.ThrowIfNull(entitlement);
            return Task.FromResult(new EngineSignedEntitlementReceipt(
                Accepted: true,
                Reason: "accepted",
                AcceptedGeneration: 7,
                ExpiresUnixSeconds: DateTimeOffset.UtcNow.AddMinutes(10).ToUnixTimeSeconds()));
        }

        public Task<ulong> RevokeSignedEntitlementAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            return Task.FromResult<ulong>(8);
        }

        public Task<FishingSessionStateSnapshot> StartFishingSessionAsync(
            FishingRuntimeSettings settings,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            ArgumentNullException.ThrowIfNull(settings);
            LastSettingsRevision = settings.Revision;
            if (RejectStart)
            {
                throw new EngineCommandRejectedException(
                    "start-fishing-session",
                    "settings_revision_mismatch");
            }
            SessionState = CreateSessionState(settings.Revision, running: true);
            return Task.FromResult(SessionState);
        }

        public Task<FishingSessionStateSnapshot> StopAutomationAsync(
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            SessionState = CreateSessionState(
                LastSettingsRevision == 0 ? 1 : LastSettingsRevision,
                running: false);
            return Task.FromResult(SessionState);
        }

        public ValueTask DisposeAsync()
        {
            DisposeCount++;
            IsAlive = false;
            return ValueTask.CompletedTask;
        }

        private static FishingSessionStateSnapshot CreateSessionState(
            ulong revision,
            bool running) => new(
            revision,
            running,
            stopping: false,
            detectedStage: running ? "active" : "idle",
            totals: new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
            tackleItems: Array.Empty<FishingTackleItemSnapshot>());
    }
}
