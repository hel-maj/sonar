using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineHealth;

public sealed record EngineHealthResult(
    int VerifiedEngineProcessId,
    bool ProcessContainmentVerified,
    uint NegotiatedProtocolMinor,
    bool SideEffectsEnabled,
    string ProductionAuthority,
    FishingSessionStateSnapshot SessionState);

public interface IEngineHealthUseCase
{
    Task<EngineHealthResult> RunAsync(CancellationToken cancellationToken);
}
