using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.Licensing;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal sealed class OfflineEngineManagedSessionFactory : IEngineManagedSessionFactory
{
    private readonly string engineExecutable;
    private readonly TimeSpan timeout;
    private readonly FishingRuntimeSettings runtimeSettings;

    internal OfflineEngineManagedSessionFactory(
        string engineExecutable,
        TimeSpan timeout,
        FishingRuntimeSettings runtimeSettings)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(engineExecutable);
        if (timeout <= TimeSpan.Zero || timeout > TimeSpan.FromSeconds(30))
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }
        runtimeSettings.Validate();

        this.engineExecutable = engineExecutable;
        this.timeout = timeout;
        this.runtimeSettings = runtimeSettings;
    }

    public async Task<IEngineManagedSession> StartAsync(
        CancellationToken cancellationToken)
    {
        var candidate = await OfflineEngineSession.StartAsync(
            engineExecutable,
            timeout,
            cancellationToken).ConfigureAwait(false);
        try
        {
            _ = await candidate.ApplyRuntimeSettingsAsync(
                runtimeSettings,
                cancellationToken).ConfigureAwait(false);
            var state = await candidate.StartReadOnlySessionAsync(
                cancellationToken).ConfigureAwait(false);
            _ = await candidate.PingAsync(cancellationToken).ConfigureAwait(false);
            return new OfflineEngineManagedSession(candidate, state, timeout);
        }
        catch
        {
            await candidate.DisposeAsync().ConfigureAwait(false);
            throw;
        }
    }

    private sealed class OfflineEngineManagedSession(
        OfflineEngineSession session,
        FishingSessionState.FishingSessionStateSnapshot sessionState,
        TimeSpan heartbeatTimeout)
        : IEngineManagedSession, IEngineEntitlementSession
    {
        public int ProcessId => session.ProcessId;

        public bool IsContained => session.IsContained;

        public bool IsAlive => session.IsAlive;

        public uint NegotiatedProtocolMinor => session.NegotiatedProtocolMinor;

        public TimeSpan BootstrapDuration => session.BootstrapDuration;

        public FishingSessionState.FishingSessionStateSnapshot SessionState { get; } =
            sessionState;

        public async Task PingAsync(CancellationToken cancellationToken)
        {
            using var timeoutCancellation = CancellationTokenSource.CreateLinkedTokenSource(
                cancellationToken);
            timeoutCancellation.CancelAfter(heartbeatTimeout);
            _ = await session.PingAsync(timeoutCancellation.Token).ConfigureAwait(false);
        }

        public Task<EngineSignedEntitlementReceipt> ApplyVerifiedKeygenEntitlementAsync(
            FishingSignedEntitlementEnvelope entitlement,
            CancellationToken cancellationToken) =>
            session.ApplyVerifiedKeygenEntitlementAsync(entitlement, cancellationToken);

        public Task<ulong> RevokeSignedEntitlementAsync(
            CancellationToken cancellationToken) =>
            session.RevokeSignedEntitlementAsync(cancellationToken);

        public ValueTask DisposeAsync() => session.DisposeAsync();
    }
}
