using System.IO;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.Licensing;

internal sealed record FishingLicenseActivationResult(
    bool Accepted,
    string Message,
    LicenseHostSettings? Settings,
    FishingSignedEntitlementEnvelope? Envelope,
    FishingKeygenLicenseClaims? Claims,
    bool FromProtectedCache = false,
    bool TemporarilyUnavailable = false)
{
    internal static FishingLicenseActivationResult Reject(
        string message,
        bool temporarilyUnavailable = false) =>
        new(
            false,
            message,
            null,
            null,
            null,
            FromProtectedCache: false,
            TemporarilyUnavailable: temporarilyUnavailable);
}

internal sealed class FishingLicenseActivationService
{
    private static readonly IReadOnlySet<string> ActivationCodes =
        new HashSet<string>(StringComparer.Ordinal)
        {
            "FINGERPRINT_SCOPE_MISMATCH",
            "FINGERPRINT_SCOPE_REQUIRED",
            "MACHINE_SCOPE_REQUIRED",
            "NO_MACHINE",
            "NO_MACHINES",
        };

    private readonly IKeygenLicenseApi api;
    private readonly Func<DateTimeOffset> nowUtc;
    private readonly Func<DateTimeOffset, FishingEntitlementTrustPolicy> trustPolicy;
    private readonly Func<DateTimeOffset, FishingEntitlementTrustPolicy> cachedTrustPolicy;
    private readonly string machineFingerprint;

    internal FishingLicenseActivationService(
        IKeygenLicenseApi api,
        string machineFingerprint,
        Func<DateTimeOffset>? nowUtc = null,
        Func<DateTimeOffset, FishingEntitlementTrustPolicy>? trustPolicy = null,
        Func<DateTimeOffset, FishingEntitlementTrustPolicy>? cachedTrustPolicy = null)
    {
        this.api = api ?? throw new ArgumentNullException(nameof(api));
        if (string.IsNullOrWhiteSpace(machineFingerprint) || machineFingerprint.Length > 256)
        {
            throw new ArgumentException("license_machine_fingerprint_invalid", nameof(machineFingerprint));
        }
        this.machineFingerprint = machineFingerprint;
        this.nowUtc = nowUtc ?? (() => DateTimeOffset.UtcNow);
        this.trustPolicy = trustPolicy ?? FishingProductionEntitlementPolicy.KeygenTrustRoot;
        this.cachedTrustPolicy = cachedTrustPolicy ??
            (trustPolicy is null
                ? FishingProductionEntitlementPolicy.KeygenCachedTrustRoot
                : trustPolicy);
    }

    internal async Task<FishingLicenseActivationResult> ActivateOrRefreshAsync(
        string licenseKey,
        ulong lastAcceptedGeneration,
        CancellationToken cancellationToken) =>
        await ActivateOrRefreshAsync(
            licenseKey,
            lastAcceptedGeneration,
            protectedSignedCache: null,
            cancellationToken).ConfigureAwait(false);

    internal async Task<FishingLicenseActivationResult> ActivateOrRefreshAsync(
        string licenseKey,
        ulong lastAcceptedGeneration,
        string? protectedSignedCache,
        CancellationToken cancellationToken)
    {
        if (string.IsNullOrWhiteSpace(licenseKey))
        {
            return FishingLicenseActivationResult.Reject("Введите ключ лицензии.");
        }

        FishingSignedEntitlementEnvelope firstEnvelope;
        try
        {
            firstEnvelope = await api.ValidateAsync(
                licenseKey,
                machineFingerprint,
                cancellationToken).ConfigureAwait(false);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (FishingLicenseTransportException exception) when (IsTransient(exception))
        {
            return TryAcceptProtectedCache(
                protectedSignedCache,
                lastAcceptedGeneration,
                exception);
        }
        catch (ArgumentException)
        {
            return FishingLicenseActivationResult.Reject("Проверьте формат ключа лицензии.");
        }

        var first = Verify(firstEnvelope, lastAcceptedGeneration);
        if (first.Accepted)
        {
            return Accepted(firstEnvelope, first);
        }
        if (!ActivationCodes.Contains(first.ServerCode) || first.LicenseId.Length == 0)
        {
            // A signed explicit denial must never fall back to an older cache.
            return FishingLicenseActivationResult.Reject(UserMessage(first));
        }

        try
        {
            await api.ActivateMachineAsync(
                licenseKey,
                first.LicenseId,
                machineFingerprint,
                cancellationToken).ConfigureAwait(false);
            var activatedEnvelope = await api.ValidateAsync(
                licenseKey,
                machineFingerprint,
                cancellationToken).ConfigureAwait(false);
            var activated = Verify(activatedEnvelope, lastAcceptedGeneration);
            return activated.Accepted
                ? Accepted(activatedEnvelope, activated)
                : FishingLicenseActivationResult.Reject(UserMessage(activated));
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (FishingLicenseTransportException exception)
        {
            // Once the server has explicitly requested machine activation, an
            // older cache cannot authorize a partially completed transition.
            return TransportFailure(exception);
        }
        catch (ArgumentException)
        {
            return FishingLicenseActivationResult.Reject("Проверьте формат ключа лицензии.");
        }
    }

    private FishingKeygenLicenseVerificationResult Verify(
        FishingSignedEntitlementEnvelope envelope,
        ulong lastAcceptedGeneration) =>
        Verify(
            envelope,
            lastAcceptedGeneration,
            trustPolicy(nowUtc()));

    private FishingKeygenLicenseVerificationResult Verify(
        FishingSignedEntitlementEnvelope envelope,
        ulong lastAcceptedGeneration,
        FishingEntitlementTrustPolicy trust) =>
        FishingKeygenLicenseVerifier.Verify(
            envelope,
            trust,
            new FishingKeygenClaimPolicy(
                machineFingerprint,
                ["fishing"],
                lastAcceptedGeneration,
                TimeSpan.FromMinutes(10)));

    private FishingLicenseActivationResult TryAcceptProtectedCache(
        string? protectedSignedCache,
        ulong lastAcceptedGeneration,
        FishingLicenseTransportException transportFailure)
    {
        if (!string.IsNullOrWhiteSpace(protectedSignedCache))
        {
            try
            {
                var envelope = FishingSignedLicenseCacheCodec.Decode(protectedSignedCache);
                var verification = Verify(
                    envelope,
                    lastAcceptedGeneration,
                    cachedTrustPolicy(nowUtc()));
                if (verification.Accepted)
                {
                    return Accepted(
                        envelope,
                        verification,
                        "Лицензия подтверждена по защищённому краткому кэшу.",
                        fromProtectedCache: true);
                }
            }
            catch (InvalidDataException)
            {
                // Corrupt or substituted cache data has no authority.
            }
        }
        return TransportFailure(transportFailure);
    }

    private FishingLicenseActivationResult Accepted(
        FishingSignedEntitlementEnvelope envelope,
        FishingKeygenLicenseVerificationResult verification,
        string message = "Лицензия подтверждена.",
        bool fromProtectedCache = false)
    {
        var claims = verification.Claims ??
            throw new InvalidOperationException("license_claims_missing");
        var settings = new LicenseHostSettings(
            claims.LicenseId,
            nowUtc().ToString("O"),
            claims.LicenseExpiresAt.ToString("O"),
            "user",
            claims.Group,
            claims.Features.Order(StringComparer.Ordinal).ToArray(),
            Array.Empty<string>());
        return new FishingLicenseActivationResult(
            true,
            message,
            settings,
            envelope,
            claims,
            FromProtectedCache: fromProtectedCache,
            TemporarilyUnavailable: false);
    }

    private static bool IsTransient(FishingLicenseTransportException exception) =>
        exception.Message is "license_http_timeout" or "license_http_unavailable";

    private static FishingLicenseActivationResult TransportFailure(
        FishingLicenseTransportException exception) =>
        FishingLicenseActivationResult.Reject(
            exception.Message switch
            {
                "license_http_timeout" => "Сервер лицензий не ответил вовремя.",
                "license_http_unavailable" => "Сервер лицензий сейчас недоступен.",
                "license_activation_rejected" => "Сервер отклонил привязку этого компьютера.",
                _ => "Не удалось безопасно проверить лицензию.",
            },
            temporarilyUnavailable: IsTransient(exception));

    private static string UserMessage(FishingKeygenLicenseVerificationResult result) =>
        result.ServerCode switch
        {
            "EXPIRED" => "Срок действия лицензии истёк.",
            "SUSPENDED" => "Лицензия приостановлена.",
            "NOT_FOUND" => "Ключ лицензии не найден.",
            "MACHINE_LIMIT_EXCEEDED" => "Достигнут лимит компьютеров для этой лицензии.",
            _ when result.Error == FishingKeygenLicenseError.RequiredFeatureMissing =>
                "Эта подписка не включает Sonar Fishing.",
            _ when result.Error == FishingKeygenLicenseError.MachineMismatch =>
                "Ответ лицензии относится к другому компьютеру.",
            _ => "Лицензия не прошла безопасную проверку.",
        };
}
