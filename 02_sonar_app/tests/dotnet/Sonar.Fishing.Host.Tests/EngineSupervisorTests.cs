using System.IO;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.EngineIntegration.Supervision;
using Sonar.Fishing.Host.EngineIntegration.Notifications;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StatisticsPage;

namespace Sonar.Fishing.Host.Tests;

internal static class EngineSupervisorTests
{
    private static readonly EngineRestartPolicy ManualCyclePolicy = new(
        FailureWindow: TimeSpan.FromMinutes(1),
        HeartbeatInterval: TimeSpan.FromMinutes(1),
        InitialRestartDelay: TimeSpan.FromMilliseconds(1),
        MaximumRestartDelay: TimeSpan.FromMilliseconds(4),
        AutomationCommandTimeout: TimeSpan.FromMilliseconds(100));

    public static IReadOnlyList<TestCase> Create() =>
    [
        new("engine_supervisor_reuses_one_healthy_generation", ReusesHealthyGeneration),
        new("engine_supervisor_restarts_one_unexpected_exit", RestartsUnexpectedExit),
        new("engine_supervisor_crash_withdraws_authority_restores_settings_without_command_replay", CrashRecoveryIsFailClosed),
        new("developer_engine_crash_restores_bootstrap_authority_without_command_or_lease_replay", DeveloperCrashRecoveryIsFailClosed),
        new("engine_supervisor_recovers_after_failures_beyond_previous_limit", RecoversAfterRepeatedFailures),
        new("faulted_event_pump_recovers_generation_without_old_notification_replay", NotificationsFollowCurrentGeneration),
        new("engine_generation_bound_state_callback_cannot_cross_retirement", GenerationBoundStateCannotCrossRetirement),
        new("engine_generation_bound_notification_callback_cannot_cross_retirement", GenerationBoundNotificationCannotCrossRetirement),
        new("engine_automation_timeout_retires_generation_and_allows_recovery", AutomationTimeoutRetiresGeneration),
        new("session_statistics_reset_is_generation_bound_and_not_replayed", StatisticsResetIsGenerationBound),
        new("session_statistics_reset_timeout_retires_without_replay", StatisticsResetTimeoutRetiresWithoutReplay),
        new("session_statistics_reset_timeout_while_queued_preserves_generation", StatisticsResetQueuedTimeoutPreservesGeneration),
        new("session_statistics_reset_timeout_before_pipe_write_preserves_generation_and_allows_retry", StatisticsResetTimeoutBeforePipeWritePreservesGeneration),
        new("session_statistics_reset_caller_cancel_before_pipe_write_preserves_generation_and_allows_retry", StatisticsResetCallerCancellationBeforePipeWritePreservesGeneration),
        new("session_statistics_reset_caller_cancel_after_pipe_write_retires_without_failure_or_replay", StatisticsResetCallerCancellationAfterPipeWriteRetiresWithoutFailure),
        new("engine_managed_session_state_merge_rejects_late_reset_response", ManagedSessionStateMergeRejectsLateResetResponse),
        new("rejected_cached_entitlement_allows_fresh_replacement_envelope", RejectedCachedEntitlementAllowsReplacement),
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

    private static void RecoversAfterRepeatedFailures()
    {
        const int previousCircuitFailureLimit = 3;
        var replacement = new FakeSession(processId: 4301);
        var factory = new RecoveringFactory(
            failuresBeforeSuccess: previousCircuitFailureLimit + 2,
            replacement);
        var recoveryPolicy = ManualCyclePolicy with
        {
            HeartbeatInterval = TimeSpan.FromMilliseconds(1),
        };
        var supervisor = new EngineSessionSupervisor(factory, recoveryPolicy);

        var initialFailure = CaptureFailure(
            () => supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult());
        var recoveredWithoutAnotherCheck = factory.SuccessfulStart.Task.Wait(
            TimeSpan.FromSeconds(2));
        var recovered = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.Equal(
            "engine_supervisor_start_failed",
            initialFailure.Message,
            "Initial start failure lost its stable reason");
        TestAssert.True(
            recoveredWithoutAnotherCheck,
            "Heartbeat monitor did not recover after the previous failure limit");
        TestAssert.Equal(
            previousCircuitFailureLimit + 3,
            factory.StartCount,
            "Heartbeat monitor did not perform the expected bounded retries");
        TestAssert.Equal<ulong>(1, recovered.Generation, "Recovered generation changed");
        TestAssert.Equal(4301, recovered.ProcessId, "Recovered Engine identity changed");
        TestAssert.Equal(
            recoveryPolicy.MaximumRestartDelay,
            recovered.LastRestartDelay,
            "Repeated recovery delay did not stay at its configured cap");
        TestAssert.Equal(1, replacement.DisposeCount, "Recovered Engine was not disposed once");
    }

    private static void CrashRecoveryIsFailClosed()
    {
        var settings = FishingRuntimeSettings.CreateDefault(revision: 17);
        var firstSession = new FakeSession(processId: 4251);
        var secondSession = new FakeSession(processId: 4252);
        var factory = new GatedRecoveryFactory(
            firstSession,
            secondSession,
            () => settings);
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);
        var runtime = new EngineFishingAutomationRuntime(supervisor, () => settings);
        var observed = new List<FishingSessionStateSnapshot>();
        runtime.SessionStateChanged += observed.Add;
        var entitlement = new FishingSignedEntitlementEnvelope(
            "POST",
            "/v1/licenses/actions/validate-key",
            "api.keygen.sh",
            "date",
            "digest",
            "signature",
            [1]);

        _ = supervisor.ApplyVerifiedKeygenEntitlementAsync(
            entitlement,
            CancellationToken.None).GetAwaiter().GetResult();
        _ = runtime.StartAsync(CancellationToken.None).GetAwaiter().GetResult();
        settings = FishingRuntimeSettings.CreateDefault(revision: 18);
        firstSession.IsAlive = false;
        var recovery = supervisor.CheckAsync(CancellationToken.None);
        var replacementStarted = factory.ReplacementStarted.Task.Wait(
            TimeSpan.FromSeconds(2));
        var authorityWithdrawn = !runtime.HasActiveEntitlement;
        var withdrawnStatePublished = observed.Any(snapshot =>
            !snapshot.Running && snapshot.AcceptedSettingsRevision == 0);
        factory.ReleaseReplacement.TrySetResult();
        var recovered = recovery.GetAwaiter().GetResult();
        var authorityRestored = runtime.HasActiveEntitlement;
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.True(replacementStarted, "Replacement Engine did not enter bounded restart");
        TestAssert.True(authorityWithdrawn, "Crashed Engine authority stayed active during restart");
        TestAssert.True(withdrawnStatePublished, "Crash did not publish fail-closed idle state");
        TestAssert.True(authorityRestored,
            "Replacement Engine did not restore signed runtime authority");
        TestAssert.True(runtime.HasActiveEntitlement == false,
            "Terminal cleanup retained Engine runtime authority");
        TestAssert.Equal<ulong>(18, recovered.SessionState.AcceptedSettingsRevision,
            "Replacement Engine did not restore the latest settings snapshot");
        TestAssert.True(!recovered.SessionState.Running,
            "Replacement Engine replayed the previous running state");
        TestAssert.Equal(ManualCyclePolicy.InitialRestartDelay, recovered.LastRestartDelay,
            "Replacement did not apply the configured restart backoff");
        TestAssert.Equal(ManualCyclePolicy.MaximumRestartDelay,
            ManualCyclePolicy.DelayForFailureCount(100),
            "Restart backoff exceeded or missed its cap");
        TestAssert.Equal(1, firstSession.StartCommandCount,
            "Original Engine did not receive the explicit start exactly once");
        TestAssert.Equal(0, secondSession.StartCommandCount,
            "Replacement Engine replayed the automation start command");
        TestAssert.Equal(0, secondSession.StopCommandCount,
            "Replacement Engine fabricated a stop command or input cleanup lease");
        TestAssert.Equal(1, secondSession.EntitlementApplyCount,
            "Replacement Engine did not restore exactly one signed authority envelope");
    }

    private static void NotificationsFollowCurrentGeneration()
    {
        var first = new FakeSession(processId: 4351);
        var second = new FakeSession(processId: 4352);
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(first, second),
            ManualCyclePolicy);
        var observed = new List<FishingEngineNotificationReceipt>();
        supervisor.NotificationReceived += observed.Add;

        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        first.EmitNotification(sequence: 7);
        first.FailEventPump();
        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        first.EmitNotification(sequence: 8);
        second.EmitNotification(sequence: 1);
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.Equal(2, observed.Count, "Retired Engine notification was forwarded");
        TestAssert.Equal<ulong>(1, observed[0].Generation, "Initial event generation changed");
        TestAssert.Equal<ulong>(7, observed[0].Sequence, "Initial event sequence changed");
        TestAssert.Equal<ulong>(2, observed[1].Generation, "Replacement event generation changed");
        TestAssert.Equal<ulong>(1, observed[1].Sequence, "Replacement sequence was replayed or remapped");
    }

    private static void GenerationBoundStateCannotCrossRetirement()
    {
        var first = new FakeSession(processId: 4361);
        var second = new FakeSession(processId: 4362);
        var factory = FakeFactory.FromSessions(first, second);
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);
        var observed = new List<FishingSessionStateSnapshot>();
        var observedGate = new object();
        using var callbackEntered = new ManualResetEventSlim();
        using var releaseCallback = new ManualResetEventSlim();
        supervisor.SessionStateChanged += snapshot =>
        {
            if (snapshot.Revision == 99)
            {
                callbackEntered.Set();
                _ = releaseCallback.Wait(TimeSpan.FromSeconds(2));
            }
            lock (observedGate)
            {
                observed.Add(snapshot);
            }
        };

        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        var staleCallback = Task.Run(() => first.EmitSessionState(
            revision: 99,
            running: true));
        TestAssert.True(
            callbackEntered.Wait(TimeSpan.FromSeconds(2)),
            "Old generation state callback did not enter the subscriber");
        first.FailEventPump();
        var recovery = Task.Run(() =>
            supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult());
        _ = SpinWait.SpinUntil(() => factory.StartCount == 2, TimeSpan.FromMilliseconds(250));
        releaseCallback.Set();
        staleCallback.GetAwaiter().GetResult();
        var recovered = recovery.GetAwaiter().GetResult();

        FishingSessionStateSnapshot[] snapshot;
        lock (observedGate)
        {
            snapshot = observed.ToArray();
        }
        var staleIndex = Array.FindLastIndex(snapshot, value => value.Revision == 99);
        var withdrawnIndex = Array.FindLastIndex(snapshot, value =>
            value.Revision == 0 && !value.Running);
        TestAssert.True(
            staleIndex >= 0 && withdrawnIndex > staleIndex,
            "Retired generation state was published after fail-closed replacement state");
        TestAssert.Equal<ulong>(2, recovered.Generation,
            "State callback serialization prevented Engine recovery");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
    }

    private static void GenerationBoundNotificationCannotCrossRetirement()
    {
        var first = new FakeSession(processId: 4363);
        var second = new FakeSession(processId: 4364);
        var factory = FakeFactory.FromSessions(first, second);
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);
        var observed = new List<FishingEngineNotificationReceipt>();
        var observedGate = new object();
        using var callbackEntered = new ManualResetEventSlim();
        using var releaseCallback = new ManualResetEventSlim();
        supervisor.NotificationReceived += receipt =>
        {
            if (receipt.Generation == 1 && receipt.Sequence == 7)
            {
                callbackEntered.Set();
                _ = releaseCallback.Wait(TimeSpan.FromSeconds(2));
            }
            lock (observedGate)
            {
                observed.Add(receipt);
            }
        };

        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        var staleCallback = Task.Run(() => first.EmitNotification(sequence: 7));
        TestAssert.True(
            callbackEntered.Wait(TimeSpan.FromSeconds(2)),
            "Old generation notification callback did not enter the subscriber");
        first.FailEventPump();
        var recovery = Task.Run(() =>
            supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult());
        var replacementCrossedCallback = SpinWait.SpinUntil(
            () => factory.StartCount == 2,
            TimeSpan.FromMilliseconds(250));
        if (replacementCrossedCallback)
        {
            second.EmitNotification(sequence: 1);
        }
        releaseCallback.Set();
        staleCallback.GetAwaiter().GetResult();
        _ = recovery.GetAwaiter().GetResult();
        if (!replacementCrossedCallback)
        {
            second.EmitNotification(sequence: 1);
        }

        FishingEngineNotificationReceipt[] receipts;
        lock (observedGate)
        {
            receipts = observed.ToArray();
        }
        TestAssert.Equal(2, receipts.Length,
            "Generation callback race dropped or duplicated a notification");
        TestAssert.Equal<ulong>(1, receipts[0].Generation,
            "Replacement notification overtook an already admitted old-generation callback");
        TestAssert.Equal<ulong>(2, receipts[1].Generation,
            "Old notification was tagged as or delivered after the replacement generation");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
    }

    private static void AutomationTimeoutRetiresGeneration()
    {
        var first = new FakeSession(processId: 4371) { BlockStart = true };
        var second = new FakeSession(processId: 4372);
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(first, second),
            ManualCyclePolicy with
            {
                AutomationCommandTimeout = TimeSpan.FromMilliseconds(25),
            });
        var entitlement = Entitlement(bodyByte: 1);
        _ = supervisor.ApplyVerifiedKeygenEntitlementAsync(
            entitlement,
            CancellationToken.None).GetAwaiter().GetResult();
        var runtime = new EngineFishingAutomationRuntime(
            supervisor,
            () => FishingRuntimeSettings.CreateDefault(revision: 41));

        var failure = CaptureFailure(
            () => runtime.StartAsync(CancellationToken.None).GetAwaiter().GetResult());
        TestAssert.Equal(
            "engine_automation_command_timeout",
            failure.Message,
            "Automation deadline lost its stable boundary reason");
        TestAssert.True(!runtime.HasActiveEntitlement,
            "Timed-out generation retained runtime authority");
        var recovered = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();

        TestAssert.Equal<ulong>(2, recovered.Generation,
            "Supervisor did not replace a timed-out automation generation");
        TestAssert.Equal(1, first.DisposeCount,
            "Timed-out Engine generation was not retired exactly once");
        TestAssert.Equal(0, second.StartCommandCount,
            "Replacement Engine replayed the timed-out start command");
        TestAssert.True(runtime.HasActiveEntitlement,
            "Replacement Engine did not freshly restore the signed entitlement");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
    }

    private static void StatisticsResetIsGenerationBound()
    {
        var first = new FakeSession(processId: 4373);
        var second = new FakeSession(processId: 4374);
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(first, second),
            ManualCyclePolicy);

        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        var reset = supervisor.ResetCurrentSessionStatisticsAsync(
            CancellationToken.None).GetAwaiter().GetResult();
        first.IsAlive = false;
        var recovered = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.Equal(1, first.ResetStatisticsCommandCount,
            "Current generation did not receive exactly one reset command");
        TestAssert.Equal(0, second.ResetStatisticsCommandCount,
            "Replacement generation replayed the statistics reset");
        TestAssert.Equal<ulong>(2, recovered.Generation,
            "Replacement generation did not advance after crash");
        TestAssert.Equal(0, reset.Totals.CaughtCount,
            "Reset receipt retained catches");
    }

    private static void StatisticsResetTimeoutRetiresWithoutReplay()
    {
        var first = new FakeSession(processId: 4375) { BlockResetStatistics = true };
        var second = new FakeSession(processId: 4376);
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(first, second),
            ManualCyclePolicy with
            {
                AutomationCommandTimeout = TimeSpan.FromMilliseconds(25),
            });

        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        var failure = CaptureFailure(() =>
            supervisor.ResetCurrentSessionStatisticsAsync(CancellationToken.None)
                .GetAwaiter().GetResult());
        var recovered = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.Equal("engine_session_statistics_reset_timeout", failure.Message,
            "Statistics reset timeout lost its stable reason");
        TestAssert.Equal(1, first.ResetStatisticsCommandCount,
            "Timed-out reset was not issued exactly once");
        TestAssert.Equal(0, second.ResetStatisticsCommandCount,
            "Replacement generation replayed the timed-out reset");
        TestAssert.Equal<ulong>(2, recovered.Generation,
            "Timed-out reset did not recover with a fresh generation");
    }

    private static void StatisticsResetQueuedTimeoutPreservesGeneration()
    {
        var session = new FakeSession(processId: 4377);
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(session),
            ManualCyclePolicy with
            {
                AutomationCommandTimeout = TimeSpan.FromMilliseconds(25),
            });

        var initial = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();
        session.BlockPing = true;
        using var holderCancellation = new CancellationTokenSource();
        var holder = supervisor.CheckAsync(holderCancellation.Token);
        TestAssert.True(
            session.PingStarted.Task.Wait(TimeSpan.FromSeconds(2)),
            "Lifecycle gate holder did not enter the heartbeat");

        var failure = CaptureFailure(() =>
            supervisor.ResetCurrentSessionStatisticsAsync(CancellationToken.None)
                .GetAwaiter().GetResult());

        TestAssert.Equal("engine_session_statistics_reset_timeout", failure.Message,
            "Queued reset timeout escaped without its stable reason");
        TestAssert.Equal(0, session.ResetStatisticsCommandCount,
            "Queued reset timeout issued an ambiguous Engine command");
        TestAssert.Equal(0, session.DisposeCount,
            "Queued reset timeout retired an unambiguous generation");

        holderCancellation.Cancel();
        TestAssert.Throws<OperationCanceledException>(
            () => holder.GetAwaiter().GetResult(),
            "Cancelled lifecycle gate holder did not return caller cancellation");
        session.BlockPing = false;
        _ = supervisor.ResetCurrentSessionStatisticsAsync(CancellationToken.None)
            .GetAwaiter().GetResult();
        var after = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();

        TestAssert.Equal<ulong>(initial.Generation, after.Generation,
            "Queued timeout advanced the Engine generation");
        TestAssert.Equal(initial.ProcessId, after.ProcessId,
            "Queued timeout replaced the Engine process");
        TestAssert.Equal(0, after.FailuresInWindow,
            "Queued timeout consumed the runtime failure budget");
        TestAssert.Equal(TimeSpan.Zero, after.LastRestartDelay,
            "Queued timeout introduced restart backoff");
        TestAssert.Equal(1, session.ResetStatisticsCommandCount,
            "Healthy retry did not issue exactly one reset on the same generation");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
    }

    private static void StatisticsResetCallerCancellationBeforePipeWritePreservesGeneration()
    {
        var session = new FakeSession(processId: 4378)
        {
            BlockResetStatisticsBeforeWrite = true,
        };
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(session),
            ManualCyclePolicy);

        var initial = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();
        using var cancellation = new CancellationTokenSource();
        var reset = supervisor.ResetCurrentSessionStatisticsAsync(cancellation.Token);
        TestAssert.True(
            session.ResetStatisticsPreWriteStarted.Task.Wait(TimeSpan.FromSeconds(2)),
            "Statistics reset did not enter the pre-write cancellation window");
        cancellation.Cancel();
        TestAssert.Throws<OperationCanceledException>(
            () => reset.GetAwaiter().GetResult(),
            "Pre-write caller cancellation was converted into a runtime failure");

        TestAssert.Equal(0, session.ResetStatisticsCommandCount,
            "Pre-write cancellation recorded an Engine command as dispatched");
        TestAssert.Equal(0, session.DisposeCount,
            "Pre-write cancellation retired an unambiguous healthy generation");
        session.BlockResetStatisticsBeforeWrite = false;
        _ = supervisor.ResetCurrentSessionStatisticsAsync(CancellationToken.None)
            .GetAwaiter().GetResult();
        var after = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();

        TestAssert.Equal(initial.ProcessId, after.ProcessId,
            "Pre-write cancellation replaced the Engine process");
        TestAssert.Equal(initial.Generation, after.Generation,
            "Pre-write cancellation advanced the Engine generation");
        TestAssert.Equal(0, after.FailuresInWindow,
            "Pre-write caller cancellation consumed the runtime failure budget");
        TestAssert.Equal(TimeSpan.Zero, after.LastRestartDelay,
            "Pre-write caller cancellation introduced restart backoff");
        TestAssert.Equal(1, session.ResetStatisticsCommandCount,
            "Bounded retry did not dispatch exactly one reset on the same generation");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
    }

    private static void StatisticsResetTimeoutBeforePipeWritePreservesGeneration()
    {
        var session = new FakeSession(processId: 4380)
        {
            BlockResetStatisticsBeforeWrite = true,
        };
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(session),
            ManualCyclePolicy with
            {
                AutomationCommandTimeout = TimeSpan.FromMilliseconds(25),
            });

        var initial = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();
        var reset = supervisor.ResetCurrentSessionStatisticsAsync(CancellationToken.None);
        TestAssert.True(
            session.ResetStatisticsPreWriteStarted.Task.Wait(TimeSpan.FromSeconds(2)),
            "Statistics reset did not enter the pre-write timeout window");
        var failure = CaptureFailure(() => reset.GetAwaiter().GetResult());

        TestAssert.Equal("engine_session_statistics_reset_timeout", failure.Message,
            "Pre-write reset timeout lost its stable reason");
        TestAssert.Equal(0, session.ResetStatisticsCommandCount,
            "Pre-write timeout recorded an Engine command as dispatched");
        TestAssert.Equal(0, session.DisposeCount,
            "Pre-write timeout retired an unambiguous healthy generation");
        session.BlockResetStatisticsBeforeWrite = false;
        _ = supervisor.ResetCurrentSessionStatisticsAsync(CancellationToken.None)
            .GetAwaiter().GetResult();
        var after = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();

        TestAssert.Equal(initial.ProcessId, after.ProcessId,
            "Pre-write timeout replaced the Engine process");
        TestAssert.Equal(initial.Generation, after.Generation,
            "Pre-write timeout advanced the Engine generation");
        TestAssert.Equal(0, after.FailuresInWindow,
            "Pre-write timeout consumed the runtime failure budget");
        TestAssert.Equal(TimeSpan.Zero, after.LastRestartDelay,
            "Pre-write timeout introduced restart backoff");
        TestAssert.Equal(1, session.ResetStatisticsCommandCount,
            "Bounded retry after pre-write timeout did not dispatch exactly once");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
    }

    private static void StatisticsResetCallerCancellationAfterPipeWriteRetiresWithoutFailure()
    {
        var first = new FakeSession(processId: 4378) { BlockResetStatistics = true };
        var second = new FakeSession(processId: 4379);
        var supervisor = new EngineSessionSupervisor(
            FakeFactory.FromSessions(first, second),
            ManualCyclePolicy);
        var observed = new List<FishingSessionStateSnapshot>();
        supervisor.SessionStateChanged += observed.Add;

        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        var runtime = new EngineFishingAutomationRuntime(
            supervisor,
            () => FishingRuntimeSettings.CreateDefault(revision: 7));
        var statistics = new StatisticsPageViewModel(
            CreatePopulatedStatisticsState(),
            persistPrice: null,
            runtime);
        runtime.SessionStateChanged += statistics.ApplySessionState;
        first.EmitSessionState(revision: 7, running: true);
        using var cancellation = new CancellationTokenSource();
        var reset = runtime.ResetCurrentSessionAsync(cancellation.Token);
        TestAssert.True(
            first.ResetStatisticsStarted.Task.Wait(TimeSpan.FromSeconds(2)),
            "Statistics reset did not cross the generation-bound issue point");
        cancellation.Cancel();
        TestAssert.Throws<OperationCanceledException>(
            () => reset.GetAwaiter().GetResult(),
            "Caller-cancelled reset was converted into a runtime failure");

        TestAssert.Equal(1, first.DisposeCount,
            "Ambiguous cancelled reset did not retire its generation");
        TestAssert.True(ReferenceEquals(FishingSessionStateSnapshot.Empty, observed[^1]),
            "Ambiguous reset retirement did not publish fail-closed empty state");
        TestAssert.True(!statistics.Current.HasCatches,
            "Statistics ViewModel retained an ambiguous retired-generation aggregate");
        var recovered = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();

        TestAssert.Equal<ulong>(2, recovered.Generation,
            "Cancelled ambiguous reset did not recover on a fresh generation");
        TestAssert.Equal(0, recovered.FailuresInWindow,
            "Caller cancellation consumed the runtime failure budget");
        TestAssert.Equal(TimeSpan.Zero, recovered.LastRestartDelay,
            "Caller cancellation introduced restart backoff");
        TestAssert.Equal(1, first.ResetStatisticsCommandCount,
            "Cancelled reset was not issued exactly once");
        TestAssert.Equal(0, second.ResetStatisticsCommandCount,
            "Replacement generation replayed the cancelled reset");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
    }

    private static void ManagedSessionStateMergeRejectsLateResetResponse()
    {
        var owner = new EngineSessionStateRevisionOwner(
            CreateState(revision: 8, running: true));
        var published = new List<ulong>();
        var resetResponse = CreateState(revision: 9, running: true);

        _ = owner.Merge(resetResponse);
        _ = owner.Merge(resetResponse, snapshot => published.Add(snapshot.Revision));
        _ = owner.Merge(
            CreateState(revision: 10, running: true),
            snapshot => published.Add(snapshot.Revision));
        var merged = owner.Merge(resetResponse);

        TestAssert.Equal<ulong>(10, owner.Current.Revision,
            "Late reset continuation rolled session state back from N+1 to N");
        TestAssert.Equal<ulong>(10, merged.Revision,
            "Late reset response returned stale state to its caller");
        TestAssert.Equal("9,10", string.Join(',', published),
            "Response/event merge skipped or replayed a session revision");
    }

    private static void RejectedCachedEntitlementAllowsReplacement()
    {
        var first = new FakeSession(processId: 4381);
        var second = new FakeSession(processId: 4382)
        {
            RejectEntitlementApplicationsRemaining = 1,
        };
        var factory = FakeFactory.FromSessions(first, second);
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);
        _ = supervisor.ApplyVerifiedKeygenEntitlementAsync(
            Entitlement(bodyByte: 1),
            CancellationToken.None).GetAwaiter().GetResult();
        first.FailEventPump();

        var receipt = supervisor.ApplyVerifiedKeygenEntitlementAsync(
            Entitlement(bodyByte: 2),
            CancellationToken.None).GetAwaiter().GetResult();
        var recovered = supervisor.CheckAsync(CancellationToken.None)
            .GetAwaiter().GetResult();

        TestAssert.True(receipt.Accepted,
            "Fresh verified entitlement was discarded after cached lease rejection");
        TestAssert.Equal(2, second.EntitlementApplyCount,
            "Replacement did not reject the cache once and accept the fresh envelope once");
        TestAssert.Equal<ulong>(2, recovered.Generation,
            "Cached entitlement rejection caused another Engine generation");
        TestAssert.True(supervisor.HasActiveEntitlement,
            "Fresh replacement entitlement did not restore runtime authority");
        TestAssert.Equal(0, second.DisposeCount,
            "Cached entitlement rejection disposed the usable replacement Engine");
        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
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

    private static void DeveloperCrashRecoveryIsFailClosed()
    {
        var settings = FishingRuntimeSettings.CreateDefault(revision: 31);
        var firstSession = new FakeSession(
            processId: 4261,
            hasBootstrapRuntimeAuthority: true);
        var secondSession = new FakeSession(
            processId: 4262,
            hasBootstrapRuntimeAuthority: true);
        var factory = new GatedRecoveryFactory(
            firstSession,
            secondSession,
            () => settings);
        var supervisor = new EngineSessionSupervisor(factory, ManualCyclePolicy);
        var runtime = new EngineFishingAutomationRuntime(supervisor, () => settings);

        _ = supervisor.CheckAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.True(
            runtime.HasActiveEntitlement,
            "Developer bootstrap authority was not activated");
        _ = runtime.StartAsync(CancellationToken.None).GetAwaiter().GetResult();
        settings = FishingRuntimeSettings.CreateDefault(revision: 32);
        firstSession.IsAlive = false;
        var recovery = supervisor.CheckAsync(CancellationToken.None);
        TestAssert.True(
            factory.ReplacementStarted.Task.Wait(TimeSpan.FromSeconds(2)),
            "Developer replacement Engine did not enter bounded restart");
        TestAssert.True(
            !runtime.HasActiveEntitlement,
            "Developer authority stayed active while Engine was absent");
        factory.ReleaseReplacement.TrySetResult();
        var recovered = recovery.GetAwaiter().GetResult();

        TestAssert.True(
            runtime.HasActiveEntitlement,
            "Replacement did not restore compile-bound developer authority");
        TestAssert.Equal<ulong>(
            32,
            recovered.SessionState.AcceptedSettingsRevision,
            "Developer replacement did not restore current settings");
        TestAssert.True(
            !recovered.SessionState.Running,
            "Developer replacement replayed the running state");
        TestAssert.Equal(
            0,
            secondSession.StartCommandCount,
            "Developer replacement replayed the start command");
        TestAssert.Equal(
            0,
            secondSession.StopCommandCount,
            "Developer replacement fabricated a stop or input lease");
        TestAssert.Equal(
            0,
            secondSession.EntitlementApplyCount,
            "Developer replacement replayed a signed entitlement envelope");

        supervisor.DisposeAsync().AsTask().GetAwaiter().GetResult();
        TestAssert.True(
            !runtime.HasActiveEntitlement,
            "Terminal cleanup retained developer runtime authority");
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

    private static FishingSessionStateSnapshot CreateState(
        ulong revision,
        bool running) => new(
        revision,
        running,
        stopping: false,
        detectedStage: running ? "active" : "idle",
        totals: new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
        tackleItems: [],
        acceptedSettingsRevision: revision);

    private static FishingSessionStateSnapshot CreatePopulatedStatisticsState() => new(
        revision: 6,
        running: true,
        stopping: false,
        detectedStage: "active",
        totals: new FishingSessionTotalsSnapshot(90, 1, 2.5, 0, 0, 100, 120),
        tackleItems: [],
        acceptedSettingsRevision: 7,
        fishRows:
        [
            new FishingSessionFishRowSnapshot(
                "fixture",
                "Fixture",
                1,
                2.5,
                0,
                0,
                1,
                2.5,
                null,
                null,
                100,
                120),
        ]);

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

    private static FishingSignedEntitlementEnvelope Entitlement(byte bodyByte) => new(
        "POST",
        "/v1/licenses/actions/validate-key",
        "api.keygen.sh",
        "date",
        "digest",
        "signature",
        [bodyByte]);

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

    private sealed class RecoveringFactory(
        int failuresBeforeSuccess,
        FakeSession replacement) : IEngineManagedSessionFactory
    {
        public TaskCompletionSource SuccessfulStart { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        public int StartCount { get; private set; }

        public Task<IEngineManagedSession> StartAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            StartCount++;
            if (StartCount <= failuresBeforeSuccess)
            {
                return Task.FromException<IEngineManagedSession>(
                    new IOException($"restart_failed_{StartCount}"));
            }
            SuccessfulStart.TrySetResult();
            return Task.FromResult<IEngineManagedSession>(replacement);
        }
    }

    private sealed class GatedRecoveryFactory(
        FakeSession first,
        FakeSession replacement,
        Func<FishingRuntimeSettings> currentSettings) : IEngineManagedSessionFactory
    {
        public TaskCompletionSource ReplacementStarted { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        public TaskCompletionSource ReleaseReplacement { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        private int startCount;

        public async Task<IEngineManagedSession> StartAsync(
            CancellationToken cancellationToken)
        {
            startCount++;
            if (startCount == 1)
            {
                first.RestoreSettings(currentSettings().Revision);
                return first;
            }
            if (startCount != 2)
            {
                throw new InvalidOperationException("unexpected_fake_engine_start");
            }
            ReplacementStarted.TrySetResult();
            await ReleaseReplacement.Task.WaitAsync(cancellationToken)
                .ConfigureAwait(false);
            replacement.RestoreSettings(currentSettings().Revision);
            return replacement;
        }
    }

    private sealed class FakeSession(
        int processId,
        bool hasBootstrapRuntimeAuthority = false) :
        IEngineManagedSession,
        IEngineEntitlementSession,
        IEngineAutomationSession,
        IEngineSessionStatisticsSession,
        IEngineSessionStateSource,
        IEngineNotificationFrameSource,
        IEngineBootstrapAuthoritySession
    {
        public TaskCompletionSource PingStarted { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        public TaskCompletionSource ResetStatisticsStarted { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        public TaskCompletionSource ResetStatisticsPreWriteStarted { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        public int ProcessId { get; } = processId;

        public bool IsContained { get; set; } = true;

        public bool IsAlive { get; set; } = true;

        public uint NegotiatedProtocolMinor => 0;

        public TimeSpan BootstrapDuration => TimeSpan.FromMilliseconds(4);

        public FishingSessionStateSnapshot SessionState { get; private set; } =
            FishingSessionStateSnapshot.Empty;

        public bool HasBootstrapRuntimeAuthority { get; } =
            hasBootstrapRuntimeAuthority;

        public int PingCount { get; private set; }

        public int DisposeCount { get; private set; }

        public bool BlockPing { get; set; }

        public bool RejectStart { get; set; }

        public bool BlockStart { get; set; }

        public bool BlockResetStatistics { get; set; }

        public bool BlockResetStatisticsBeforeWrite { get; set; }

        public bool RejectResetStatistics { get; set; }

        public int RejectEntitlementApplicationsRemaining { get; set; }

        public ulong LastSettingsRevision { get; private set; }

        public int EntitlementApplyCount { get; private set; }

        public int StartCommandCount { get; private set; }

        public int StopCommandCount { get; private set; }

        public int ResetStatisticsCommandCount { get; private set; }

        public event Action<FishingSessionStateSnapshot>? SessionStateChanged;

        public event Action<FishingEngineNotificationFrame>? NotificationReceived;

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
            EntitlementApplyCount++;
            if (RejectEntitlementApplicationsRemaining > 0)
            {
                RejectEntitlementApplicationsRemaining--;
                return Task.FromResult(new EngineSignedEntitlementReceipt(
                    Accepted: false,
                    Reason: "cached_entitlement_rejected",
                    AcceptedGeneration: 0,
                    ExpiresUnixSeconds: 0));
            }
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

        public async Task<FishingSessionStateSnapshot> StartFishingSessionAsync(
            FishingRuntimeSettings settings,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            ArgumentNullException.ThrowIfNull(settings);
            StartCommandCount++;
            LastSettingsRevision = settings.Revision;
            if (BlockStart)
            {
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken)
                    .ConfigureAwait(false);
            }
            if (RejectStart)
            {
                throw new EngineCommandRejectedException(
                    "start-fishing-session",
                    "settings_revision_mismatch");
            }
            SessionState = CreateSessionState(settings.Revision, running: true);
            return SessionState;
        }

        public Task<FishingSessionStateSnapshot> StopAutomationAsync(
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            StopCommandCount++;
            SessionState = CreateSessionState(
                LastSettingsRevision == 0 ? 1 : LastSettingsRevision,
                running: false);
            return Task.FromResult(SessionState);
        }

        public EngineCommandDispatch<FishingSessionStateSnapshot>
            ResetCurrentSessionStatistics(CancellationToken cancellationToken)
        {
            var dispatchState = new EngineCommandDispatchState();
            return new EngineCommandDispatch<FishingSessionStateSnapshot>(
                dispatchState,
                ResetCurrentSessionStatisticsCoreAsync(
                    dispatchState,
                    cancellationToken));
        }

        private async Task<EngineCommandDispatchReceipt<FishingSessionStateSnapshot>>
            ResetCurrentSessionStatisticsCoreAsync(
                EngineCommandDispatchState dispatchState,
                CancellationToken cancellationToken)
        {
            try
            {
                cancellationToken.ThrowIfCancellationRequested();
                if (BlockResetStatisticsBeforeWrite)
                {
                    ResetStatisticsPreWriteStarted.TrySetResult();
                    await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken)
                        .ConfigureAwait(false);
                }
                dispatchState.EnterWriteBoundary(cancellationToken);
                ResetStatisticsCommandCount++;
                ResetStatisticsStarted.TrySetResult();
                if (BlockResetStatistics)
                {
                    await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken)
                        .ConfigureAwait(false);
                }
                if (RejectResetStatistics)
                {
                    throw new EngineCommandRejectedException(
                        "reset-fishing-session-statistics",
                        "session_statistics_reset_rejected");
                }
                SessionState = new FishingSessionStateSnapshot(
                    SessionState.Revision + 1,
                    SessionState.Running,
                    SessionState.Stopping,
                    SessionState.DetectedStage,
                    new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
                    [],
                    SessionState.AcceptedSettingsRevision);
                return new EngineCommandDispatchReceipt<FishingSessionStateSnapshot>(
                    SessionState,
                    dispatchState.BytesMayHaveBeenWritten);
            }
            catch (EngineCommandRejectedException)
            {
                throw;
            }
            catch (EngineCommandDispatchException)
            {
                throw;
            }
            catch (Exception exception)
            {
                throw new EngineCommandDispatchException(
                    dispatchState.BytesMayHaveBeenWritten,
                    exception);
            }
        }

        public void RestoreSettings(ulong revision)
        {
            LastSettingsRevision = revision;
            SessionState = CreateSessionState(revision, running: false);
        }

        public void EmitSessionState(ulong revision, bool running)
        {
            SessionState = CreateSessionState(revision, running);
            SessionStateChanged?.Invoke(SessionState);
        }

        public void EmitNotification(ulong sequence) =>
            NotificationReceived?.Invoke(new FishingEngineNotificationFrame(
                $"fake-{ProcessId}",
                sequence,
                1_900_000_000_000,
                new BaitTiredEngineNotification()));

        public void FailEventPump() => IsAlive = false;

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
            tackleItems: Array.Empty<FishingTackleItemSnapshot>(),
            acceptedSettingsRevision: revision);
    }
}
