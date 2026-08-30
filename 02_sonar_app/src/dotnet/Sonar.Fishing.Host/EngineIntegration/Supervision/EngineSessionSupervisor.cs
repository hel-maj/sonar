using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.EngineIntegration.Notifications;
using Sonar.Fishing.Host.EngineIntegration.Inventory;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

/// <summary>
/// Product policy for one long-lived Engine session. Generic process containment
/// remains owned by Sonar.Platform.Processes.
/// </summary>
internal sealed class EngineSessionSupervisor :
    IAsyncDisposable,
    IFishingEngineNotificationSource,
    IFishingInventorySnapshotSource
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
    private IEngineInventorySnapshotFrameSource? inventoryFrameSource;
    private Action<FishingInventorySnapshotFrame>? inventoryFrameHandler;
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

    public event Action<FishingInventorySnapshotReceipt>? InventorySnapshotReceived;

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
        ExecuteGenerationBoundCommandAsync<IEngineAutomationSession>(
            (automation, token) => automation.StartFishingSessionAsync(
                settings,
                token),
            "engine_automation_capability_missing",
            "engine_automation_command",
            retireOnCallerCancellation: false,
            cancellationToken);

    internal bool HasActiveEntitlement =>
        Volatile.Read(ref runtimeAuthorityActive);

    internal Task<FishingSessionStateSnapshot> StopAutomationAsync(
        CancellationToken cancellationToken) =>
        ExecuteGenerationBoundCommandAsync<IEngineAutomationSession>(
            (automation, token) => automation.StopAutomationAsync(token),
            "engine_automation_capability_missing",
            "engine_automation_command",
            retireOnCallerCancellation: false,
            cancellationToken);

    internal Task<FishingSessionStateSnapshot> ResetCurrentSessionStatisticsAsync(
        CancellationToken cancellationToken) =>
        ExecuteGenerationBoundDispatchCommandAsync<IEngineSessionStatisticsSession>(
            (statistics, token) =>
                statistics.ResetCurrentSessionStatistics(token),
            "engine_session_statistics_capability_missing",
            "engine_session_statistics_reset",
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
            Action<FishingInventorySnapshotFrame>? candidateInventoryHandler = null;
            if (candidate is IEngineInventorySnapshotFrameSource inventorySource)
            {
                candidateInventoryHandler = frame =>
                    OnInventorySnapshotReceived(binding, frame);
                inventorySource.InventorySnapshotReceived += candidateInventoryHandler;
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
                inventoryFrameSource = candidate as IEngineInventorySnapshotFrameSource;
                inventoryFrameHandler = candidateInventoryHandler;
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

    private async Task<FishingSessionStateSnapshot> ExecuteGenerationBoundCommandAsync<TCapability>(
        Func<TCapability, CancellationToken, Task<FishingSessionStateSnapshot>> operation,
        string capabilityMissingReason,
        string failureReason,
        bool retireOnCallerCancellation,
        CancellationToken cancellationToken)
        where TCapability : class
    {
        ArgumentNullException.ThrowIfNull(operation);
        ArgumentException.ThrowIfNullOrWhiteSpace(capabilityMissingReason);
        ArgumentException.ThrowIfNullOrWhiteSpace(failureReason);
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
        var gateAcquired = false;
        var operationIssued = false;
        try
        {
            await lifecycleGate.WaitAsync(token).ConfigureAwait(false);
            gateAcquired = true;
            ThrowIfStopped();
            await EnsureSessionAsync(token).ConfigureAwait(false);
            var boundSession = session ?? throw new InvalidOperationException(
                "engine_supervisor_session_missing");
            var boundGeneration = generation;
            if (boundSession is not TCapability capability)
            {
                throw new InvalidOperationException(capabilityMissingReason);
            }
            var operationTask = operation(capability, token);
            operationIssued = true;
            var result = await operationTask
                .WaitAsync(token)
                .ConfigureAwait(false);
            if (!ReferenceEquals(session, boundSession) || generation != boundGeneration)
            {
                throw new InvalidOperationException(
                    "engine_command_generation_changed");
            }
            return result;
        }
        catch (EngineCommandRejectedException)
        {
            throw;
        }
        catch (OperationCanceledException exception)
            when (deadlineCancellation.IsCancellationRequested &&
                  !operationCancellation.IsCancellationRequested)
        {
            var timeout = new TimeoutException(
                $"{failureReason}_timeout",
                exception);
            if (operationIssued)
            {
                await RetireSessionAsync().ConfigureAwait(false);
                RegisterFailure(timeout);
            }
            throw new InvalidOperationException(
                $"{failureReason}_timeout",
                timeout);
        }
        catch (OperationCanceledException) when (operationCancellation.IsCancellationRequested)
        {
            if (retireOnCallerCancellation &&
                operationIssued &&
                !lifetimeCancellation.IsCancellationRequested)
            {
                await RetireSessionAsync().ConfigureAwait(false);
            }
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
            throw new InvalidOperationException($"{failureReason}_failed", exception);
        }
        finally
        {
            if (gateAcquired)
            {
                lifecycleGate.Release();
            }
        }
    }

    private async Task<FishingSessionStateSnapshot>
        ExecuteGenerationBoundDispatchCommandAsync<TCapability>(
            Func<TCapability, CancellationToken,
                EngineCommandDispatch<FishingSessionStateSnapshot>> operation,
            string capabilityMissingReason,
            string failureReason,
            CancellationToken cancellationToken)
        where TCapability : class
    {
        ArgumentNullException.ThrowIfNull(operation);
        ArgumentException.ThrowIfNullOrWhiteSpace(capabilityMissingReason);
        ArgumentException.ThrowIfNullOrWhiteSpace(failureReason);
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
        var gateAcquired = false;
        EngineCommandDispatch<FishingSessionStateSnapshot>? dispatch = null;
        try
        {
            await lifecycleGate.WaitAsync(token).ConfigureAwait(false);
            gateAcquired = true;
            ThrowIfStopped();
            await EnsureSessionAsync(token).ConfigureAwait(false);
            var boundSession = session ?? throw new InvalidOperationException(
                "engine_supervisor_session_missing");
            var boundGeneration = generation;
            if (boundSession is not TCapability capability)
            {
                throw new InvalidOperationException(capabilityMissingReason);
            }
            dispatch = operation(capability, token);
            var receipt = await dispatch.Completion
                .WaitAsync(token)
                .ConfigureAwait(false);
            if (!ReferenceEquals(session, boundSession) || generation != boundGeneration)
            {
                throw new InvalidOperationException(
                    "engine_command_generation_changed");
            }
            if (!receipt.BytesMayHaveBeenWritten)
            {
                throw new InvalidOperationException(
                    "engine_command_dispatch_receipt_invalid");
            }
            return receipt.Result;
        }
        catch (EngineCommandRejectedException)
        {
            throw;
        }
        catch (EngineCommandDispatchException exception)
            when (exception.InnerException is OperationCanceledException cancellation &&
                  deadlineCancellation.IsCancellationRequested &&
                  !operationCancellation.IsCancellationRequested)
        {
            dispatch?.CancelBeforeWrite();
            var timeout = new TimeoutException(
                $"{failureReason}_timeout",
                cancellation);
            if (dispatch?.BytesMayHaveBeenWritten == true ||
                exception.BytesMayHaveBeenWritten)
            {
                await RetireSessionAsync().ConfigureAwait(false);
                RegisterFailure(timeout);
            }
            throw new InvalidOperationException(
                $"{failureReason}_timeout",
                timeout);
        }
        catch (EngineCommandDispatchException exception)
            when (exception.InnerException is OperationCanceledException cancellation &&
                  operationCancellation.IsCancellationRequested)
        {
            dispatch?.CancelBeforeWrite();
            if (!lifetimeCancellation.IsCancellationRequested &&
                (dispatch?.BytesMayHaveBeenWritten == true ||
                 exception.BytesMayHaveBeenWritten))
            {
                await RetireSessionAsync().ConfigureAwait(false);
            }
            throw new OperationCanceledException(
                cancellation.Message,
                cancellation,
                cancellation.CancellationToken);
        }
        catch (OperationCanceledException exception)
            when (deadlineCancellation.IsCancellationRequested &&
                  !operationCancellation.IsCancellationRequested)
        {
            dispatch?.CancelBeforeWrite();
            var timeout = new TimeoutException(
                $"{failureReason}_timeout",
                exception);
            if (dispatch?.BytesMayHaveBeenWritten == true)
            {
                await RetireSessionAsync().ConfigureAwait(false);
                RegisterFailure(timeout);
            }
            throw new InvalidOperationException(
                $"{failureReason}_timeout",
                timeout);
        }
        catch (OperationCanceledException) when (operationCancellation.IsCancellationRequested)
        {
            dispatch?.CancelBeforeWrite();
            if (!lifetimeCancellation.IsCancellationRequested &&
                dispatch?.BytesMayHaveBeenWritten == true)
            {
                await RetireSessionAsync().ConfigureAwait(false);
            }
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
            throw new InvalidOperationException($"{failureReason}_failed", exception);
        }
        finally
        {
            if (gateAcquired)
            {
                lifecycleGate.Release();
            }
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
        EngineGenerationBinding? retiringBinding;
        lock (eventForwardingGate)
        {
            retiring = session;
            retiringBinding = activeEventBinding;
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
            if (inventoryFrameSource is not null && inventoryFrameHandler is not null)
            {
                inventoryFrameSource.InventorySnapshotReceived -= inventoryFrameHandler;
            }
            inventoryFrameSource = null;
            inventoryFrameHandler = null;
            sessionStateSource = null;
            sessionStateHandler = null;
            lock (eventForwardingGate)
            {
                SessionStateChanged?.Invoke(FishingSessionStateSnapshot.Empty);
                if (retiringBinding is not null)
                {
                    try
                    {
                        InventorySnapshotReceived?.Invoke(
                            new FishingInventorySnapshotReceipt(
                                retiringBinding.Generation,
                                ulong.MaxValue,
                                0,
                                Sonar.Fishing.Host.InventoryPage.InventoryProductState.Unknown));
                    }
                    catch
                    {
                        // The process is already retired; presentation cleanup
                        // cannot delay replacement generation startup.
                    }
                }
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

    private void OnInventorySnapshotReceived(
        EngineGenerationBinding binding,
        FishingInventorySnapshotFrame frame)
    {
        lock (eventForwardingGate)
        {
            if (!ReferenceEquals(activeEventBinding, binding))
            {
                return;
            }
            try
            {
                InventorySnapshotReceived?.Invoke(new FishingInventorySnapshotReceipt(
                    binding.Generation,
                    frame.Sequence,
                    frame.CapturedAtUnixMs,
                    frame.Snapshot));
            }
            catch
            {
                // Inventory presentation is observational and cannot own the
                // Engine process or revoke runtime authority.
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
