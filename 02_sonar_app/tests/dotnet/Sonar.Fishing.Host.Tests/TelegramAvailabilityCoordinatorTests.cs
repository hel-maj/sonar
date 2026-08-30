using System.Diagnostics;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.TelegramPage;

namespace Sonar.Fishing.Host.Tests;

internal static class TelegramAvailabilityCoordinatorTests
{
    private static readonly TelegramAvailabilityCoordinatorOptions FastOptions = new(
        TimeSpan.Zero,
        TimeSpan.FromMilliseconds(100),
        TimeSpan.FromMilliseconds(5),
        TimeSpan.FromMilliseconds(50));

    public static IReadOnlyList<TestCase> Create() =>
    [
        new("telegram_availability_probes_disabled_draft_before_enable", DisabledDraftCanEnable),
        new("telegram_availability_policy_denial_is_network_inert", PolicyDenialIsInert),
        new("telegram_availability_drops_stale_probe_generation", StaleProbeIsDropped),
        new("telegram_availability_timeout_recovers_without_secret_leak", TimeoutRecovers),
        new("telegram_availability_retry_waiters_remain_bounded", RetryWaitersRemainBounded),
        new("telegram_availability_runtime_retry_preserves_poll_cursor", RuntimeRetryPreservesCursor),
        new("telegram_availability_draft_detour_preserves_persisted_runtime_cursor", DraftDetourPreservesRuntimeCursor),
        new("telegram_availability_stop_is_bounded_for_stuck_adapter", StopIsBounded),
        new("telegram_availability_late_probe_after_stop_is_dropped", LateProbeAfterStopIsDropped),
    ];

    private static void DisabledDraftCanEnable()
    {
        var probe = new SequenceProbe(TelegramAvailabilityProbeResult.Success);
        var starts = 0;
        var coordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: false),
            probe,
            async (_, cancellationToken) =>
            {
                Interlocked.Increment(ref starts);
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken);
            },
            FastOptions);
        coordinator.StartAsync().GetAwaiter().GetResult();
        TestAssert.True(
            SpinWait.SpinUntil(
                () => coordinator.Current.Status == TelegramAvailabilityStatus.Available,
                TimeSpan.FromSeconds(1)),
            "Disabled credential draft was not checked");
        TestAssert.Equal(0, Volatile.Read(ref starts), "Disabled draft started polling");

        coordinator.ApplyConfiguration(Configuration(enabled: true));
        TestAssert.True(
            SpinWait.SpinUntil(() => Volatile.Read(ref starts) == 1, TimeSpan.FromSeconds(1)),
            "Verified configuration did not start polling after enable");
        coordinator.StopAsync().GetAwaiter().GetResult();
        TestAssert.True(probe.Calls >= 1, "Real availability probe was bypassed");
    }

    private static void PolicyDenialIsInert()
    {
        var probe = new SequenceProbe(TelegramAvailabilityProbeResult.Success);
        var starts = 0;
        var coordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: true, networkAllowed: false),
            probe,
            (_, _) =>
            {
                Interlocked.Increment(ref starts);
                return Task.CompletedTask;
            },
            FastOptions);

        coordinator.StartAsync().GetAwaiter().GetResult();
        Task.Delay(25).GetAwaiter().GetResult();
        coordinator.StopAsync().GetAwaiter().GetResult();

        TestAssert.Equal(0, probe.Calls, "Denied network policy reached getMe");
        TestAssert.Equal(0, starts, "Denied feature policy started polling");
    }

    private static void StaleProbeIsDropped()
    {
        var firstResult = new TaskCompletionSource<TelegramAvailabilityProbeResult>(
            TaskCreationOptions.RunContinuationsAsynchronously);
        var probe = new BlockingFirstProbe(firstResult.Task);
        var coordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: false),
            probe,
            (_, _) => Task.CompletedTask,
            FastOptions);
        coordinator.StartAsync().GetAwaiter().GetResult();
        TestAssert.True(
            probe.FirstStarted.Wait(TimeSpan.FromSeconds(1)),
            "First credential probe did not start");

        var next = new TelegramAvailabilityCandidate("12345:replacement_TOKEN", [77]);
        coordinator.ApplyCandidate(next);
        firstResult.SetResult(TelegramAvailabilityProbeResult.Failed(
            TelegramAvailabilityFailure.CredentialsRejected));

        TestAssert.True(
            SpinWait.SpinUntil(
                () => coordinator.Current.Status == TelegramAvailabilityStatus.Available &&
                    coordinator.Current.Matches("12345:replacement_TOKEN", [77]),
                TimeSpan.FromSeconds(1)),
            "Stale probe result replaced the current candidate state");
        coordinator.StopAsync().GetAwaiter().GetResult();
    }

    private static void TimeoutRecovers()
    {
        var probe = new TimeoutThenSuccessProbe();
        var coordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: false),
            probe,
            (_, _) => Task.CompletedTask,
            FastOptions);
        coordinator.StartAsync().GetAwaiter().GetResult();

        TestAssert.True(
            SpinWait.SpinUntil(
                () => coordinator.Current.Status == TelegramAvailabilityStatus.Available,
                TimeSpan.FromSeconds(1)),
            "Timed-out getMe did not self-recover");
        TestAssert.True(probe.Calls >= 2, "Timed-out getMe was not retried");
        TestAssert.True(
            !coordinator.Current.Error.Contains("12345:secret_TOKEN", StringComparison.Ordinal),
            "Availability state exposed the token");
        coordinator.StopAsync().GetAwaiter().GetResult();
    }

    private static void RuntimeRetryPreservesCursor()
    {
        var offsets = new List<long?>();
        var starts = 0;
        var coordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: true),
            new SequenceProbe(TelegramAvailabilityProbeResult.Success),
            async (context, cancellationToken) =>
            {
                lock (offsets)
                {
                    offsets.Add(context.Cursor.NextOffset);
                }
                if (Interlocked.Increment(ref starts) == 1)
                {
                    TestAssert.True(context.Cursor.TryAdvance(5), "Initial cursor did not advance");
                    context.ReportUnavailable(TelegramAvailabilityFailure.NetworkUnavailable);
                    return;
                }
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken);
            },
            FastOptions);
        coordinator.StartAsync().GetAwaiter().GetResult();

        TestAssert.True(
            SpinWait.SpinUntil(() => Volatile.Read(ref starts) == 2, TimeSpan.FromSeconds(1)),
            "Runtime generation was not restarted");
        lock (offsets)
        {
            TestAssert.True(
                offsets.SequenceEqual([null, 6L]),
                "Same-identity runtime retry reset the polling cursor");
        }
        coordinator.StopAsync().GetAwaiter().GetResult();
    }

    private static void RetryWaitersRemainBounded()
    {
        var runtimeProbe = new AlwaysFailingProbe();
        var runtimeCoordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: true),
            runtimeProbe,
            (_, _) => Task.CompletedTask,
            FastOptions);
        runtimeCoordinator.StartAsync().GetAwaiter().GetResult();
        TestAssert.True(
            SpinWait.SpinUntil(() => runtimeProbe.Calls >= 64, TimeSpan.FromSeconds(2)),
            "Runtime outage did not exercise repeated retries");
        TestAssert.True(
            runtimeCoordinator.PendingRuntimeConfigurationChangeWaiters <= 1,
            "Runtime retries accumulated abandoned configuration waiters");
        runtimeCoordinator.StopAsync().GetAwaiter().GetResult();

        var candidateProbe = new AlwaysFailingProbe();
        var candidateCoordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: false),
            candidateProbe,
            (_, _) => Task.CompletedTask,
            FastOptions);
        candidateCoordinator.StartAsync().GetAwaiter().GetResult();
        TestAssert.True(
            SpinWait.SpinUntil(() => candidateProbe.Calls >= 64, TimeSpan.FromSeconds(2)),
            "Candidate outage did not exercise repeated retries");
        TestAssert.True(
            candidateCoordinator.PendingCandidateChangeWaiters <= 1,
            "Candidate retries accumulated abandoned change waiters");
        candidateCoordinator.StopAsync().GetAwaiter().GetResult();
    }

    private static void DraftDetourPreservesRuntimeCursor()
    {
        var offsets = new List<long?>();
        var starts = 0;
        var firstStarted = new ManualResetEventSlim(false);
        var releaseFirst = new TaskCompletionSource(
            TaskCreationOptions.RunContinuationsAsynchronously);
        var coordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: true),
            new SequenceProbe(TelegramAvailabilityProbeResult.Success),
            async (context, cancellationToken) =>
            {
                lock (offsets)
                {
                    offsets.Add(context.Cursor.NextOffset);
                }
                var generation = Interlocked.Increment(ref starts);
                if (generation == 1)
                {
                    TestAssert.True(
                        context.Cursor.TryAdvance(5),
                        "Initial persisted cursor did not advance");
                    firstStarted.Set();
                    await releaseFirst.Task.ConfigureAwait(false);
                    return;
                }
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken);
            },
            FastOptions);
        coordinator.StartAsync().GetAwaiter().GetResult();
        TestAssert.True(
            firstStarted.Wait(TimeSpan.FromSeconds(1)),
            "Persisted Telegram runtime did not start");

        coordinator.ApplyCandidate(new TelegramAvailabilityCandidate(
            "12345:draft_TOKEN",
            [77]));
        TestAssert.True(
            SpinWait.SpinUntil(
                () => coordinator.Current.Status == TelegramAvailabilityStatus.Available &&
                    coordinator.Current.Matches("12345:draft_TOKEN", [77]),
                TimeSpan.FromSeconds(1)),
            "Unsaved draft was not verified independently");
        TestAssert.Equal(
            1,
            Volatile.Read(ref starts),
            "Unsaved draft restarted the persisted Telegram runtime");

        coordinator.ApplyCandidate(Configuration(enabled: true).Candidate);
        TestAssert.True(
            SpinWait.SpinUntil(
                () => coordinator.Current.Status == TelegramAvailabilityStatus.Available &&
                    coordinator.Current.Matches("12345:secret_TOKEN", [42]),
                TimeSpan.FromSeconds(1)),
            "Discard did not restore the persisted runtime availability");
        releaseFirst.SetResult();
        TestAssert.True(
            SpinWait.SpinUntil(() => Volatile.Read(ref starts) == 2, TimeSpan.FromSeconds(1)),
            "Persisted runtime did not retry after the draft detour");
        lock (offsets)
        {
            TestAssert.True(
                offsets.SequenceEqual([null, 6L]),
                "Draft detour or discard reset the persisted polling cursor");
        }

        coordinator.ApplyCandidate(new TelegramAvailabilityCandidate(
            "12345:draft_TOKEN",
            [77]));
        coordinator.ApplyConfiguration(Configuration(
            enabled: true,
            botToken: "12345:draft_TOKEN",
            adminId: 77));
        TestAssert.True(
            SpinWait.SpinUntil(() => Volatile.Read(ref starts) == 3, TimeSpan.FromSeconds(1)),
            "Saved replacement identity did not start its runtime generation");
        lock (offsets)
        {
            TestAssert.True(
                offsets.SequenceEqual([null, 6L, null]),
                "Persisted identity replacement did not reset the cursor exactly once");
        }
        coordinator.StopAsync().GetAwaiter().GetResult();
    }

    private static void StopIsBounded()
    {
        var release = new TaskCompletionSource<TelegramAvailabilityProbeResult>(
            TaskCreationOptions.RunContinuationsAsynchronously);
        var probe = new BlockingFirstProbe(release.Task);
        var coordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: false),
            probe,
            (_, _) => Task.CompletedTask,
            FastOptions);
        coordinator.StartAsync().GetAwaiter().GetResult();
        TestAssert.True(probe.FirstStarted.Wait(TimeSpan.FromSeconds(1)), "Stuck probe did not start");

        var stopwatch = Stopwatch.StartNew();
        coordinator.StopAsync().GetAwaiter().GetResult();
        stopwatch.Stop();
        release.SetResult(TelegramAvailabilityProbeResult.Success);

        TestAssert.True(
            stopwatch.Elapsed < TimeSpan.FromMilliseconds(500),
            "Stop waited indefinitely for a non-cooperative Telegram adapter");
    }

    private static void LateProbeAfterStopIsDropped()
    {
        var release = new TaskCompletionSource<TelegramAvailabilityProbeResult>(
            TaskCreationOptions.RunContinuationsAsynchronously);
        var probe = new BlockingFirstProbe(release.Task);
        var coordinator = new TelegramAvailabilityCoordinator(
            Configuration(enabled: false),
            probe,
            (_, _) => Task.CompletedTask,
            FastOptions);
        var callbacks = 0;
        coordinator.AvailabilityChanged += _ => Interlocked.Increment(ref callbacks);
        coordinator.StartAsync().GetAwaiter().GetResult();
        TestAssert.True(
            probe.FirstStarted.Wait(TimeSpan.FromSeconds(1)),
            "Non-cooperative availability probe did not start");

        coordinator.StopAsync().GetAwaiter().GetResult();
        var stoppedState = coordinator.Current;
        var stoppedCallbacks = Volatile.Read(ref callbacks);
        release.SetResult(TelegramAvailabilityProbeResult.Success);
        Task.Delay(100).GetAwaiter().GetResult();
        coordinator.ApplyCandidate(new TelegramAvailabilityCandidate(
            "12345:after_stop_TOKEN",
            [77]));
        Task.Delay(25).GetAwaiter().GetResult();

        TestAssert.Equal(
            stoppedState,
            coordinator.Current,
            "Late probe completion changed availability after terminal stop");
        TestAssert.Equal(
            stoppedCallbacks,
            Volatile.Read(ref callbacks),
            "Late probe completion notified UI after terminal stop");
    }

    private static TelegramRuntimeConfiguration Configuration(
        bool enabled,
        bool networkAllowed = true,
        bool featureAllowed = true,
        string botToken = "12345:secret_TOKEN",
        long adminId = 42) => new(
            networkAllowed,
            featureAllowed,
            new TelegramHostSettings(
                enabled,
                [adminId],
                1.0,
                TelegramHostSettings.Default.Notifications,
                TelegramSoundSettings.AllEnabled),
            botToken);

    private sealed class SequenceProbe(params TelegramAvailabilityProbeResult[] results)
        : ITelegramAvailabilityProbe
    {
        private int calls;

        public int Calls => Volatile.Read(ref calls);

        public Task<TelegramAvailabilityProbeResult> ProbeAsync(
            TelegramAvailabilityCandidate candidate,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            var index = Interlocked.Increment(ref calls) - 1;
            var result = results[Math.Min(index, results.Length - 1)];
            return Task.FromResult(result);
        }
    }

    private sealed class BlockingFirstProbe(Task<TelegramAvailabilityProbeResult> first)
        : ITelegramAvailabilityProbe
    {
        private int calls;

        public ManualResetEventSlim FirstStarted { get; } = new(false);

        public Task<TelegramAvailabilityProbeResult> ProbeAsync(
            TelegramAvailabilityCandidate candidate,
            CancellationToken cancellationToken)
        {
            if (Interlocked.Increment(ref calls) == 1)
            {
                FirstStarted.Set();
                return first;
            }
            cancellationToken.ThrowIfCancellationRequested();
            return Task.FromResult(TelegramAvailabilityProbeResult.Success);
        }
    }

    private sealed class AlwaysFailingProbe : ITelegramAvailabilityProbe
    {
        private int calls;

        public int Calls => Volatile.Read(ref calls);

        public Task<TelegramAvailabilityProbeResult> ProbeAsync(
            TelegramAvailabilityCandidate candidate,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            Interlocked.Increment(ref calls);
            return Task.FromResult(TelegramAvailabilityProbeResult.Failed(
                TelegramAvailabilityFailure.NetworkUnavailable));
        }
    }

    private sealed class TimeoutThenSuccessProbe : ITelegramAvailabilityProbe
    {
        private int calls;

        public int Calls => Volatile.Read(ref calls);

        public async Task<TelegramAvailabilityProbeResult> ProbeAsync(
            TelegramAvailabilityCandidate candidate,
            CancellationToken cancellationToken)
        {
            if (Interlocked.Increment(ref calls) == 1)
            {
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken);
            }
            return TelegramAvailabilityProbeResult.Success;
        }
    }
}
