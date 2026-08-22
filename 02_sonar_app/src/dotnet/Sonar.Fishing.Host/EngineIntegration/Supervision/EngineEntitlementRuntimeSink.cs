using Sonar.Fishing.Host.Licensing;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal sealed class EngineEntitlementRuntimeSink(
    EngineSessionSupervisor supervisor) : IFishingEntitlementRuntimeSink
{
    private readonly EngineSessionSupervisor supervisor = supervisor ??
        throw new ArgumentNullException(nameof(supervisor));

    public async Task<bool> ApplyAsync(
        FishingSignedEntitlementEnvelope envelope,
        FishingKeygenLicenseClaims claims,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(envelope);
        ArgumentNullException.ThrowIfNull(claims);
        var receipt = await supervisor.ApplyVerifiedKeygenEntitlementAsync(
            envelope,
            cancellationToken).ConfigureAwait(false);
        var accepted = receipt.Accepted &&
            receipt.AcceptedGeneration == claims.Generation &&
            receipt.ExpiresUnixSeconds == claims.LeaseExpiresUnixSeconds;
        if (!accepted)
        {
            await supervisor.RevokeSignedEntitlementAsync(CancellationToken.None)
                .ConfigureAwait(false);
        }
        return accepted;
    }

    public Task RevokeAsync(CancellationToken cancellationToken) =>
        supervisor.RevokeSignedEntitlementAsync(cancellationToken);
}
