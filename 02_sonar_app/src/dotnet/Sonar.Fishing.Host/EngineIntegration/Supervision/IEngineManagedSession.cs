using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.EngineIntegration.Notifications;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal interface IEngineManagedSession : IAsyncDisposable
{
    int ProcessId { get; }

    bool IsContained { get; }

    bool IsAlive { get; }

    uint NegotiatedProtocolMinor { get; }

    TimeSpan BootstrapDuration { get; }

    FishingSessionStateSnapshot SessionState { get; }

    Task PingAsync(CancellationToken cancellationToken);
}

internal interface IEngineSessionStateSource
{
    event Action<FishingSessionStateSnapshot>? SessionStateChanged;
}

internal interface IEngineNotificationFrameSource
{
    event Action<FishingEngineNotificationFrame>? NotificationReceived;
}

internal interface IEngineBootstrapAuthoritySession
{
    bool HasBootstrapRuntimeAuthority { get; }
}
