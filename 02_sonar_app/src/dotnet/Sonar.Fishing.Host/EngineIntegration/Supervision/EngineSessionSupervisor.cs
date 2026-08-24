using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.EngineIntegration.Notifications;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

/// <summary>
/// Product policy for one long-lived Engine session. Generic process containment
/// remains owned by Sonar.Platform.Processes.
/// </summary>
internal sealed class EngineSessionSupervisor : IAsyncDisposable, IFishingEngineNotificationSource
{
    private readonly IEngineManagedSessionFactory factory;
    private readonly EngineRestartPolicy policy;
    private readonly TimeProvider timeProvider;
    private readonly SemaphoreSlim lifecycleGate = new(1, 1);
    private readonly object eventForwardingGate = new();
    private readonly CancellationTokenSource lifetimeCancellation = new();
    private readonly Queue<DateTimeOffset> failures = new();
    private readonly TaskCompletionSource disposalCompletion = new(
        TaskCreationOptions.RunContinuationsAsynchronously);

    private IEngineManagedSession? session;
    private EngineGenerationBinding? activeEventBinding;
    private IEngineSessionStateSource? sessionStateSource;
    private Action<FishingSessionStateSnapshot>? sessionStateHandler;
    private IEngineNotificationFrameSource? notificationFrameSource;
    private Action<FishingEngineNotificationFrame>? notificationFrameHandler;
    private Task? monitorTask;
    private Exception? lastMonitorFailure;
    private ulong generation;
    private FishingSignedEntitlementEnvelope? currentEntitlement;
    private bool runtimeAuthorityActive;
    private int restartCount;
    private bool restartDelayRequired;
    private TimeSpan lastRestartDelay;
    private volatile bool stopRequested;
    private volatile bool disposed;
    private int disposeStarted;

    internal EngineSessionSupervisor(
        IEngineManagedSessionFactory factory,
        EngineRestartPolicy policy,
        TimeProvider? timeProvider = null)
    {
        this.factory = factory ?? throw new ArgumentNullException(nameof(factory));
        this.policy = policy ?? throw new ArgumentNullException(nameof(policy));
        policy.Validate();
        this.timeProvider = timeProvider ?? TimeProvider.System;
    }

    internal event Action<FishingSessionStateSnapshot>? SessionStateChanged;

    public event Action<FishingEngineNotificationReceipt>? NotificationReceived;

    internal async Task<EngineSupervisorSnapshot> CheckAsync(
        CancellationToken cancellationToken)
    {
        ThrowIfStopped();
        using var operationCancellation = CancellationTokenSource.CreateLinkedTokenSource(
            cancellationToken,
            lifetimeCancellation.Token);
        var token = operationCancellation.Token;
        await lifecycleGate.WaitAsync(token).ConfigureAwait(false);
        try
        {
            ThrowIfStopped();
            EnsureMonitorRunning();
            PruneFailures();

            if (session is not null)
            {
                if (!session.IsAlive)
                {
                    await RetireSessionAsync().ConfigureAwait(false);
                    RegisterFailure(new InvalidOperationException(
                        "engine_supervisor_process_exited"));
                }
                else
                {
                    try
                    {
                        await session.PingAsync(token).ConfigureAwait(false);
                    }
                    catch (OperationCanceledException) when (token.IsCancellationRequested)
                    {
                        throw;
                    }
                    catch (Exception exception)
                    {
                        await RetireSessionAsync().ConfigureAwait(false);
                        RegisterFailure(exception);
                    }
                }
            }

            if (session is null)
            {
                await StartSessionWithBackoffAsync(token).ConfigureAwait(false);
            }

            return CreateSnapshot();
        }
        finally
        {
            lifecycleGate.Release();
        }
    }

    internal async Task<EngineSignedEntitlementReceipt> ApplyVerifiedKeygenEntitlementAsync(
        FishingSignedEntitlementEnvelope entitlement,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(entitlement);
        ThrowIfStopped();
        using var operationCancellation = CancellationTokenSource.CreateLinkedTokenSource(
            cancellationToken,
            lifetimeCancellation.Token);
        var token = operationCancellation.Token;
        await lifecycleGate.WaitAsync(token).ConfigureAwait(false);
        try
        {
            ThrowIfStopped();
            await EnsureSessionAsync(token).ConfigureAwait(false);
            if (session is not IEngineEntitlementSession entitlementSession)
            {
                throw new InvalidOperationException("engine_entitlement_capability_missing");
            }
            var receipt = await entitlementSession.ApplyVerifiedKeygenEntitlementAsync(
                entitlement,
                token).ConfigureAwait(false);
            currentEntitlement = receipt.Accepted ? entitlement : null;
            Volatile.Write(ref runtimeAuthorityActive, receipt.Accepted);
            return receipt;
        }
        catch (OperationCanceledException) when (token.IsCancellationRequested)
        {
            throw;
        }
        catch (InvalidOperationException exception)
            when (IsRegisteredLifecycleFailure(exception))
        {
            throw;
        }
        catch (Exception exception) when (exception is not InvalidOperationException ||
                                          exception.Message != "engine_entitlement_capability_missing")
        {
            await RetireSessionAsync().ConfigureAwait(false);
            RegisterFailure(exception);
            throw new InvalidOperationException("engine_entitlement_apply_failed", exception);
        }
        finally
        {
            lifecycleGate.Release();
        }
    }

    internal async Task RevokeSignedEntitlementAsync(CancellationToken cancellationToken)
    {
        using var operationCancellation = CancellationTokenSource.CreateLinkedTokenSource(
            cancellationToken,
            lifetimeCancellation.Token);
        var token = operationCancellation.Token;
        await lifecycleGate.WaitAsync(token).ConfigureAwait(false);
        try
        {
            currentEntitlement = null;
            Volatile.Write(ref runtimeAuthorityActive, false);
            if (session is IEngineEntitlementSession entitlementSession && session.IsAlive)
            {
                try
                {
                    _ = await entitlementSession.RevokeSignedEntitlementAsync(token)
                        .ConfigureAwait(false);
                }
                catch (OperationCanceledException) when (token.IsCancellationRequested)
                {
                    throw;
                }
                catch (Exception exception)
                {
                    await RetireSessionAsync().ConfigureAwait(false);
                    RegisterFailure(exception);
                    throw new InvalidOperationException(
                        "engine_entitlement_revoke_failed",
                        exception);
                }
            }
        }
        finally
        {
            lifecycleGate.Release();
        }
    }

    internal Task<FishingSessionStateSnapshot> StartFishingSessionAsync(
        FishingRuntimeSettings settings,
        CancellationToken cancellationToken) =>
        ExecuteAutomationAsync(
            (automation, token) => automation.StartFishingSessionAsync(
                settings,
                token),
            cancellationToken);

    internal bool HasActiveEntitlement =>
        Volatile.Read(ref runtimeAuthorityActive);

    internal Task<FishingSessionStateSnapshot> StopAutomationAsync(
        CancellationToken cancellationToken) =>
        ExecuteAutomationAsync(
            (automation, token) => automation.StopAutomationAsync(token),
            cancellationToken);

    public async ValueTask DisposeAsync()
    {
        if (Interlocked.Exchange(ref disposeStarted, 1) != 0)
        {
            await disposalCompletion.Task.ConfigureAwait(false);
            return;
        }

        try
        {
            stopRequested = true;
            lifetimeCancellation.Cancel();
            var monitor = monitorTask;
            if (monitor is not null)
            {
                try
                {
                    await monitor.ConfigureAwait(false);
                }
                catch (OperationCanceledException) when (lifetimeCancellation.IsCancellationRequested)
                {
                }
            }

            await lifecycleGate.WaitAsync(CancellationToken.None).ConfigureAwait(false);
            try
            {
                await RetireSessionAsync().ConfigureAwait(false);
                disposed = true;
            }
            finally
            {
                lifecycleGate.Release();
                lifecycleGate.Dispose();
                lifetimeCancellation.Dispose();
            }

            disposalCompletion.TrySetResult();
        }
        catch (Exception exception)
        {
            disposed = true;
            disposalCompletion.TrySetException(exception);
            throw;
        }
    }

    private async Task StartSessionAsync(CancellationToken cancellationToken)
    {
        try
        {
            var candidate = await factory.StartAsync(cancellationToken).ConfigureAwait(false);
            if (!candidate.IsAlive || !candidate.IsContained)
            {
                var reason = !candidate.IsAlive
                    ? "engine_supervisor_started_process_exited"
                    : "engine_supervisor_containment_missing";
                await candidate.DisposeAsync().ConfigureAwait(false);
                throw new InvalidOperationException(reason);
            }

            var restoredAuthority = candidate is IEngineBootstrapAuthoritySession
            {
                HasBootstrapRuntimeAuthority: true,
            };
            if (currentEntitlement is not null)
            {
                if (restoredAuthority)
                {
                    await candidate.DisposeAsync().ConfigureAwait(false);
                    throw new InvalidOperationException(
                        "engine_runtime_authority_mode_conflict");
                }
                if (candidate is not IEngineEntitlementSession entitlementSession)
                {
                    await candidate.DisposeAsync().ConfigureAwait(false);
                    throw new InvalidOperationException("engine_entitlement_capability_missing");
                }
                var receipt = await entitlementSession.ApplyVerifiedKeygenEntitlementAsync(
                    currentEntitlement,
                    cancellationToken).ConfigureAwait(false);
                if (!receipt.Accepted)
                {
                    // A lease can expire or be superseded while the Engine is
                    // being replaced. Keep the fresh process fail-closed so an
                    // already verified replacement envelope can be applied.
                    currentEntitlement = null;
                }
                else
                {
                    restoredAuthority = true;
                }
            }

            if (generation != 0)
            {
                restartCount++;
            }
            var candidateGeneration = generation + 1;
            var binding = new EngineGenerationBinding(candidate, candidateGeneration);
            Action<FishingSessionStateSnapshot>? candidateStateHandler = null;
            if (candidate is IEngineSessionStateSource stateSource)
            {
                candidateStateHandler = snapshot => OnSessionStateChanged(binding, snapshot);
                stateSource.SessionStateChanged += candidateStateHandler;
            }
            Action<FishingEngineNotificationFrame>? candidateFrameHandler = null;
            if (candidate is IEngineNotificationFrameSource frameSource)
            {
                candidateFrameHandler = frame => OnNotificationReceived(binding, frame);
                frameSource.NotificationReceived += candidateFrameHandler;
            }
            lock (eventForwardingGate)
            {
                session = candidate;
                generation = candidateGeneration;
                activeEventBinding = binding;
                sessionStateSource = candidate as IEngineSessionStateSource;
                sessionStateHandler = candidateStateHandler;
                notificationFrameSource = candidate as IEngineNotificationFrameSource;
                notificationFrameHandler = candidateFrameHandler;
            }
            restartDelayRequired = false;
            lastMonitorFailure = null;
            Volatile.Write(ref runtimeAuthorityActive, restoredAuthority);
            OnSessionStateChanged(binding, candidate.SessionState);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (Exception exception)
        {
            Volatile.Write(ref runtimeAuthorityActive, false);
            RegisterFailure(exception);
            throw new InvalidOperationException(
                "engine_supervisor_start_failed",
                exception);
        }
    }

    private async Task StartSessionWithBackoffAsync(
        CancellationToken cancellationToken)
    {
        if (restartDelayRequired)
        {
            PruneFailures();
            lastRestartDelay = policy.DelayForFailureCount(failures.Count);
            if (lastRestartDelay > TimeSpan.Zero)
            {
                await Task.Delay(
                    lastRestartDelay,
                    timeProvider,
                    cancellationToken).ConfigureAwait(false);
            }
        }
        else
        {
            lastRestartDelay = TimeSpan.Zero;
        }
        await StartSessionAsync(cancellationToken).ConfigureAwait(false);
    }

    private async Task EnsureSessionAsync(CancellationToken cancellationToken)
    {
        PruneFailures();
        if (session is not null && !session.IsAlive)
        {
            await RetireSessionAsync().ConfigureAwait(false);
            RegisterFailure(new InvalidOperationException(
                "engine_supervisor_process_exited"));
        }
        if (session is null)
        {
            await StartSessionWithBackoffAsync(cancellationToken)
                .ConfigureAwait(false);
        }
    }

    private async Task<FishingSessionStateSnapshot> ExecuteAutomationAsync(
        Func<IEngineAutomationSession, CancellationToken, Task<FishingSessionStateSnapshot>> operation,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(operation);
        ThrowIfStopped();
        using var operationCancellation = CancellationTokenSource.CreateLinkedTokenSource(
            cancellationToken,
            lifetimeCancellation.Token);
        using var deadlineCancellation = new CancellationTokenSource(
            policy.AutomationCommandTimeout,
            timeProvider);
        using var boundedCancellation = CancellationTokenSource.CreateLinkedTokenSource(
            operationCancellation.Token,
            deadlineCancellation.Token);
        var token = boundedCancellation.Token;
        await lifecycleGate.WaitAsync(token).ConfigureAwait(false);
        try
        {
            ThrowIfStopped();
            await EnsureSessionAsync(token).ConfigureAwait(false);
            if (session is not IEngineAutomationSession automation)
            {
                throw new InvalidOperationException("engine_automation_capability_missing");
            }
            return await operation(automation, token)
                .WaitAsync(token)
                .ConfigureAwait(false);
        }
        catch (EngineCommandRejectedException)
        {
            throw;
        }
        catch (OperationCanceledException exception)
            when (deadlineCancellation.IsCancellationRequested &&
                  !operationCancellation.IsCancellationRequested)
        {
            await RetireSessionAsync().ConfigureAwait(false);
            var timeout = new TimeoutException(
                "engine_automation_command_timeout",
                exception);
            RegisterFailure(timeout);
            throw new InvalidOperationException(
                "engine_automation_command_timeout",
                timeout);
        }
        catch (OperationCanceledException) when (operationCancellation.IsCancellationRequested)
        {
            throw;
        }
        catch (InvalidOperationException exception)
            when (IsRegisteredLifecycleFailure(exception))
        {
            throw;
        }
        catch (Exception exception)
        {
            await RetireSessionAsync().ConfigureAwait(false);
            RegisterFailure(exception);
            throw new InvalidOperationException("engine_automation_command_failed", exception);
        }
        finally
        {
            lifecycleGate.Release();
        }
    }

    private async Task MonitorAsync(CancellationToken cancellationToken)
    {
        using var timer = new PeriodicTimer(policy.HeartbeatInterval, timeProvider);
        try
        {
            while (await timer.WaitForNextTickAsync(cancellationToken).ConfigureAwait(false))
            {
                try
                {
                    _ = await CheckAsync(cancellationToken).ConfigureAwait(false);
                }
                catch (InvalidOperationException exception)
                {
                    lastMonitorFailure = exception;
                }
                catch (Exception exception)
                {
                    // Cleanup or adapter failures must not terminate the
                    // heartbeat owner. The next bounded cycle retries.
                    RegisterFailure(exception);
                }
            }
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
        }
    }

    private async ValueTask RetireSessionAsync()
    {
        IEngineManagedSession? retiring;
        lock (eventForwardingGate)
        {
            retiring = session;
            session = null;
            activeEventBinding = null;
        }
        if (retiring is not null)
        {
            Volatile.Write(ref runtimeAuthorityActive, false);
            if (sessionStateSource is not null && sessionStateHandler is not null)
            {
                sessionStateSource.SessionStateChanged -= sessionStateHandler;
            }
            if (notificationFrameSource is not null && notificationFrameHandler is not null)
            {
                notificationFrameSource.NotificationReceived -= notificationFrameHandler;
            }
            notificationFrameSource = null;
            notificationFrameHandler = null;
            sessionStateSource = null;
            sessionStateHandler = null;
            lock (eventForwardingGate)
            {
                SessionStateChanged?.Invoke(FishingSessionStateSnapshot.Empty);
            }
            await retiring.DisposeAsync().ConfigureAwait(false);
        }
    }

    private void OnSessionStateChanged(
        EngineGenerationBinding binding,
        FishingSessionStateSnapshot snapshot)
    {
        lock (eventForwardingGate)
        {
            if (!ReferenceEquals(activeEventBinding, binding))
            {
                return;
            }
            SessionStateChanged?.Invoke(snapshot);
        }
    }

    private void OnNotificationReceived(
        EngineGenerationBinding binding,
        FishingEngineNotificationFrame frame)
    {
        lock (eventForwardingGate)
        {
            if (!ReferenceEquals(activeEventBinding, binding))
            {
                return;
            }
            try
            {
                NotificationReceived?.Invoke(new FishingEngineNotificationReceipt(
                    binding.Generation,
                    frame.Sequence,
                    frame.CapturedAtUnixMs,
                    frame.Notification));
            }
            catch
            {
                // Notification consumers are observational and cannot own Engine
                // session lifecycle or runtime authority.
            }
        }
    }

    private EngineSupervisorSnapshot CreateSnapshot()
    {
        var current = session ?? throw new InvalidOperationException(
            "engine_supervisor_session_missing");
        PruneFailures();
        return new EngineSupervisorSnapshot(
            generation,
            current.ProcessId,
            current.IsContained,
            current.NegotiatedProtocolMinor,
            current.BootstrapDuration,
            restartCount,
            failures.Count,
            lastRestartDelay,
            current.SessionState);
    }

    private void RegisterFailure(Exception exception)
    {
        lastMonitorFailure = exception;
        var now = timeProvider.GetUtcNow();
        PruneFailures(now);
        failures.Enqueue(now);
        restartDelayRequired = true;
    }

    private void PruneFailures() => PruneFailures(timeProvider.GetUtcNow());

    private void PruneFailures(DateTimeOffset now)
    {
        while (failures.TryPeek(out var occurredAt) &&
               now - occurredAt > policy.FailureWindow)
        {
            _ = failures.Dequeue();
        }
    }

    private void EnsureMonitorRunning()
    {
        if (monitorTask is null || monitorTask.IsCompleted)
        {
            monitorTask = MonitorAsync(lifetimeCancellation.Token);
        }
    }

    private static bool IsRegisteredLifecycleFailure(
        InvalidOperationException exception) =>
        exception.Message is "engine_supervisor_start_failed";

    private sealed record EngineGenerationBinding(
        IEngineManagedSession Session,
        ulong Generation);

    private void ThrowIfStopped()
    {
        if (stopRequested || disposed)
        {
            throw new InvalidOperationException("engine_supervisor_stopped");
        }
    }
}
