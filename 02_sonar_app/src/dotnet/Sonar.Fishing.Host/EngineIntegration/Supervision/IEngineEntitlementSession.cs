using Sonar.Fishing.Host.Licensing;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal interface IEngineEntitlementSession
{
    Task<EngineSignedEntitlementReceipt> ApplyVerifiedKeygenEntitlementAsync(
        FishingSignedEntitlementEnvelope entitlement,
        CancellationToken cancellationToken);

    Task<ulong> RevokeSignedEntitlementAsync(CancellationToken cancellationToken);
}
