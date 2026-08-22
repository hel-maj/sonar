using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

/// <summary>
/// Product policy for one long-lived Engine session. Generic process containment
/// remains owned by Sonar.Platform.Processes.
/// </summary>
internal sealed class EngineSessionSupervisor : IAsyncDisposable
{
    private readonly IEngineManagedSessionFactory factory;
    private readonly EngineRestartPolicy policy;
    private readonly TimeProvider timeProvider;
    private readonly SemaphoreSlim lifecycleGate = new(1, 1);
    private readonly CancellationTokenSource lifetimeCancellation = new();
    private readonly Queue<DateTimeOffset> failures = new();
    private readonly TaskCompletionSource disposalCompletion = new(
        TaskCreationOptions.RunContinuationsAsynchronously);

    private IEngineManagedSession? session;
    private Task? monitorTask;
    private Exception? lastMonitorFailure;
    private ulong generation;
    private FishingSignedEntitlementEnvelope? currentEntitlement;
    private int restartCount;
    private bool circuitOpen;
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
            PruneFailures();
            if (circuitOpen)
            {
                throw CreateCircuitOpenException();
            }

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

            if (circuitOpen)
            {
                throw CreateCircuitOpenException();
            }

            if (session is null)
            {
                await StartSessionAsync(token).ConfigureAwait(false);
            }

            if (monitorTask is null || monitorTask.IsCompleted)
            {
                monitorTask = MonitorAsync(lifetimeCancellation.Token);
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
            if (session is null || !session.IsAlive)
            {
                if (session is not null)
                {
                    await RetireSessionAsync().ConfigureAwait(false);
                }
                await StartSessionAsync(token).ConfigureAwait(false);
            }
            if (session is not IEngineEntitlementSession entitlementSession)
            {
                throw new InvalidOperationException("engine_entitlement_capability_missing");
            }
            var receipt = await entitlementSession.ApplyVerifiedKeygenEntitlementAsync(
                entitlement,
                token).ConfigureAwait(false);
            currentEntitlement = receipt.Accepted ? entitlement : null;
            return receipt;
        }
        catch (OperationCanceledException) when (token.IsCancellationRequested)
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
        Volatile.Read(ref currentEntitlement) is not null;

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

            if (currentEntitlement is not null)
            {
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
                    await candidate.DisposeAsync().ConfigureAwait(false);
                    throw new InvalidOperationException("engine_cached_entitlement_rejected");
                }
            }

            session = candidate;
            if (candidate is IEngineSessionStateSource stateSource)
            {
                stateSource.SessionStateChanged += OnSessionStateChanged;
            }
            if (generation != 0)
            {
                restartCount++;
            }
            generation++;
            lastMonitorFailure = null;
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (Exception exception)
        {
            RegisterFailure(exception);
            if (circuitOpen)
            {
                throw CreateCircuitOpenException();
            }
            throw new InvalidOperationException(
                "engine_supervisor_start_failed",
                exception);
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
        var token = operationCancellation.Token;
        await lifecycleGate.WaitAsync(token).ConfigureAwait(false);
        try
        {
            ThrowIfStopped();
            if (session is null || !session.IsAlive)
            {
                if (session is not null)
                {
                    await RetireSessionAsync().ConfigureAwait(false);
                }
                await StartSessionAsync(token).ConfigureAwait(false);
            }
            if (session is not IEngineAutomationSession automation)
            {
                throw new InvalidOperationException("engine_automation_capability_missing");
            }
            return await operation(automation, token).ConfigureAwait(false);
        }
        catch (EngineCommandRejectedException)
        {
            throw;
        }
        catch (OperationCanceledException) when (token.IsCancellationRequested)
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
                    if (circuitOpen)
                    {
                        return;
                    }
                }
            }
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
        }
    }

    private async ValueTask RetireSessionAsync()
    {
        var retiring = session;
        session = null;
        if (retiring is not null)
        {
            if (retiring is IEngineSessionStateSource stateSource)
            {
                stateSource.SessionStateChanged -= OnSessionStateChanged;
            }
            await retiring.DisposeAsync().ConfigureAwait(false);
        }
    }

    private void OnSessionStateChanged(FishingSessionStateSnapshot snapshot) =>
        SessionStateChanged?.Invoke(snapshot);

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
            current.SessionState);
    }

    private void RegisterFailure(Exception exception)
    {
        lastMonitorFailure = exception;
        var now = timeProvider.GetUtcNow();
        PruneFailures(now);
        failures.Enqueue(now);
        circuitOpen = failures.Count >= policy.MaximumFailures;
    }

    private void PruneFailures() => PruneFailures(timeProvider.GetUtcNow());

    private void PruneFailures(DateTimeOffset now)
    {
        while (failures.TryPeek(out var occurredAt) &&
               now - occurredAt > policy.FailureWindow)
        {
            _ = failures.Dequeue();
        }
        if (failures.Count < policy.MaximumFailures)
        {
            circuitOpen = false;
        }
    }

    private InvalidOperationException CreateCircuitOpenException() => new(
        "engine_supervisor_restart_circuit_open",
        lastMonitorFailure);

    private void ThrowIfStopped()
    {
        if (stopRequested || disposed)
        {
            throw new InvalidOperationException("engine_supervisor_stopped");
        }
    }
}
