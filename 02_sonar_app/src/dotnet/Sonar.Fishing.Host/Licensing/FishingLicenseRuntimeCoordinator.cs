using System.IO;
using System.Security.Cryptography;
using System.Text.Json;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.Licensing;

public interface ILicenseRuntimeLifecycle
{
    Task StartAsync();

    Task StopAsync();
}

internal interface IFishingEntitlementRuntimeSink
{
    Task<bool> ApplyAsync(
        FishingSignedEntitlementEnvelope envelope,
        FishingKeygenLicenseClaims claims,
        CancellationToken cancellationToken);

    Task RevokeAsync(CancellationToken cancellationToken);
}

internal sealed class FishingLicenseRuntimeCoordinator : ILicenseRuntimeLifecycle
{
    private static readonly TimeSpan DefaultRefreshInterval = TimeSpan.FromMinutes(5);

    private readonly FishingLicenseActivationService service;
    private readonly HostStateCoordinator state;
    private readonly IFishingEntitlementRuntimeSink? entitlementSink;
    private readonly Func<DateTimeOffset> nowUtc;
    private readonly TimeSpan refreshInterval;
    private readonly Func<TimeSpan, CancellationToken, Task> delay;
    private readonly Action<Action> dispatchStateMutation;
    private readonly SemaphoreSlim refreshGate = new(1, 1);
    private readonly object lifecycleGate = new();
    private readonly CancellationTokenSource lifecycleCancellation = new();
    private Task? startupTask;
    private Task? refreshLoopTask;
    private Task? stopTask;
    private ulong acceptedGeneration;
    private long acceptedLeaseExpiresUnixSeconds;

    internal FishingLicenseRuntimeCoordinator(
        FishingLicenseActivationService service,
        HostStateCoordinator state,
        IFishingEntitlementRuntimeSink? entitlementSink = null,
        Func<DateTimeOffset>? nowUtc = null,
        TimeSpan? refreshInterval = null,
        Func<TimeSpan, CancellationToken, Task>? delay = null,
        Action<Action>? dispatchStateMutation = null)
    {
        this.service = service ?? throw new ArgumentNullException(nameof(service));
        this.state = state ?? throw new ArgumentNullException(nameof(state));
        this.entitlementSink = entitlementSink;
        this.nowUtc = nowUtc ?? (() => DateTimeOffset.UtcNow);
        this.refreshInterval = refreshInterval ?? DefaultRefreshInterval;
        if (this.refreshInterval <= TimeSpan.Zero ||
            this.refreshInterval > TimeSpan.FromHours(1))
        {
            throw new ArgumentOutOfRangeException(nameof(refreshInterval));
        }
        this.delay = delay ?? Task.Delay;
        this.dispatchStateMutation = dispatchStateMutation ?? (action => action());
    }

    public Task StartAsync()
    {
        lock (lifecycleGate)
        {
            startupTask ??= StartCoreAsync(lifecycleCancellation.Token);
            return startupTask;
        }
    }

    public Task StopAsync()
    {
        lock (lifecycleGate)
        {
            lifecycleCancellation.Cancel();
            stopTask ??= StopCoreAsync();
            return stopTask;
        }
    }

    internal Task<FishingLicenseActivationResult> ActivateAsync(
        string licenseKey,
        CancellationToken cancellationToken) =>
        ExecuteAsync(
            licenseKey,
            protectedSignedCache: null,
            scheduledRefresh: false,
            cancellationToken);

    internal async Task<FishingLicenseActivationResult> RefreshSavedAsync(
        CancellationToken cancellationToken)
    {
        var snapshot = state.Current;
        if (string.IsNullOrWhiteSpace(snapshot.Secrets.LicenseKey))
        {
            if (snapshot.License.LicenseId.Length != 0)
            {
                await RevokeRuntimeAndStateAsync(
                    clearSignedCache: true,
                    cancellationToken).ConfigureAwait(false);
            }
            return FishingLicenseActivationResult.Reject("Лицензия не активирована.");
        }
        return await ExecuteAsync(
            snapshot.Secrets.LicenseKey,
            snapshot.Secrets.SignedLicenseCache,
            scheduledRefresh: true,
            cancellationToken).ConfigureAwait(false);
    }

    private async Task<FishingLicenseActivationResult> ExecuteAsync(
        string licenseKey,
        string? protectedSignedCache,
        bool scheduledRefresh,
        CancellationToken cancellationToken)
    {
        await refreshGate.WaitAsync(cancellationToken).ConfigureAwait(false);
        try
        {
            var result = await service.ActivateOrRefreshAsync(
                licenseKey,
                acceptedGeneration,
                protectedSignedCache,
                cancellationToken).ConfigureAwait(false);
            if (!result.Accepted || result.Settings is null ||
                result.Envelope is null || result.Claims is null)
            {
                if (scheduledRefresh &&
                    (!result.TemporarilyUnavailable ||
                     acceptedGeneration == 0 ||
                     nowUtc().ToUnixTimeSeconds() >= acceptedLeaseExpiresUnixSeconds))
                {
                    await RevokeRuntimeAndStateAsync(
                        clearSignedCache: !result.TemporarilyUnavailable,
                        cancellationToken).ConfigureAwait(false);
                }
                return result;
            }

            if (entitlementSink is not null)
            {
                bool engineAccepted;
                try
                {
                    engineAccepted = await entitlementSink.ApplyAsync(
                        result.Envelope,
                        result.Claims,
                        cancellationToken).ConfigureAwait(false);
                }
                catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
                {
                    throw;
                }
                catch (Exception exception) when (IsRuntimeBoundaryFailure(exception))
                {
                    engineAccepted = false;
                }
                if (!engineAccepted)
                {
                    await RevokeRuntimeAndStateAsync(
                        clearSignedCache: true,
                        cancellationToken).ConfigureAwait(false);
                    return FishingLicenseActivationResult.Reject(
                        "Не удалось подтвердить лицензию. Проверьте ключ и повторите.");
                }
            }

            try
            {
                var encodedCache = FishingSignedLicenseCacheCodec.Encode(result.Envelope);
                dispatchStateMutation(() =>
                    state.SaveLicense(result.Settings, licenseKey, encodedCache));
            }
            catch (Exception exception) when (
                exception is IOException or UnauthorizedAccessException or
                InvalidDataException or CryptographicException or JsonException)
            {
                if (entitlementSink is not null)
                {
                    await entitlementSink.RevokeAsync(CancellationToken.None).ConfigureAwait(false);
                }
                return FishingLicenseActivationResult.Reject(
                    "Не удалось безопасно сохранить подтверждённую лицензию.");
            }

            acceptedGeneration = result.Claims.Generation;
            acceptedLeaseExpiresUnixSeconds = result.Claims.LeaseExpiresUnixSeconds;
            return result;
        }
        finally
        {
            refreshGate.Release();
        }
    }

    private async Task RevokeRuntimeAndStateAsync(
        bool clearSignedCache,
        CancellationToken cancellationToken)
    {
        try
        {
            if (entitlementSink is not null)
            {
                await entitlementSink.RevokeAsync(cancellationToken).ConfigureAwait(false);
            }
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            // Cancellation cannot preserve authority: state is revoked below and
            // the containing Engine process is retired by its supervisor.
        }
        catch (Exception exception) when (IsRuntimeBoundaryFailure(exception))
        {
            // A failed coarse revoke retires the contained Engine process.
        }
        finally
        {
            acceptedGeneration = 0;
            acceptedLeaseExpiresUnixSeconds = 0;
            dispatchStateMutation(() => state.RevokeLicenseAuthority(clearSignedCache));
        }
    }

    private async Task StartCoreAsync(CancellationToken cancellationToken)
    {
        try
        {
            await RefreshSavedAsync(cancellationToken).ConfigureAwait(false);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            return;
        }
        lock (lifecycleGate)
        {
            if (!cancellationToken.IsCancellationRequested)
            {
                refreshLoopTask = RefreshLoopAsync(cancellationToken);
            }
        }
    }

    private async Task RefreshLoopAsync(CancellationToken cancellationToken)
    {
        try
        {
            while (true)
            {
                await delay(refreshInterval, cancellationToken).ConfigureAwait(false);
                await RefreshSavedAsync(cancellationToken).ConfigureAwait(false);
            }
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            // Normal product shutdown.
        }
    }

    private async Task StopCoreAsync()
    {
        Task? startup;
        Task? refreshLoop;
        lock (lifecycleGate)
        {
            startup = startupTask;
            refreshLoop = refreshLoopTask;
        }
        if (startup is not null)
        {
            await startup.ConfigureAwait(false);
        }
        lock (lifecycleGate)
        {
            refreshLoop ??= refreshLoopTask;
        }
        if (refreshLoop is not null)
        {
            await refreshLoop.ConfigureAwait(false);
        }
        if (entitlementSink is not null)
        {
            try
            {
                await entitlementSink.RevokeAsync(CancellationToken.None).ConfigureAwait(false);
            }
            catch (Exception exception) when (IsRuntimeBoundaryFailure(exception))
            {
                // Supervisor containment is the shutdown fallback.
            }
        }
    }

    private static bool IsRuntimeBoundaryFailure(Exception exception) =>
        exception is IOException or InvalidOperationException or UnauthorizedAccessException;
}
