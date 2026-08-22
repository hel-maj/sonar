using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal sealed class ProductionEngineManagedSessionFactory : IEngineManagedSessionFactory
{
    private readonly string engineExecutable;
    private readonly TimeSpan timeout;
    private readonly Func<FishingRuntimeSettings> runtimeSettings;

    internal ProductionEngineManagedSessionFactory(
        string engineExecutable,
        TimeSpan timeout,
        Func<FishingRuntimeSettings> runtimeSettings)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(engineExecutable);
        if (timeout <= TimeSpan.Zero || timeout > TimeSpan.FromSeconds(30))
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }
        ArgumentNullException.ThrowIfNull(runtimeSettings);
        this.engineExecutable = engineExecutable;
        this.timeout = timeout;
        this.runtimeSettings = runtimeSettings;
    }

    public async Task<IEngineManagedSession> StartAsync(CancellationToken cancellationToken)
    {
        var identity = BundleSessionIdentityLoader.Load(engineExecutable);
        var candidate = await OfflineEngineSession.StartProductionAsync(
            engineExecutable,
            timeout,
            identity,
            cancellationToken).ConfigureAwait(false);
        try
        {
            var settings = runtimeSettings();
            settings.Validate();
            _ = await candidate.ApplyRuntimeSettingsAsync(
                settings,
                cancellationToken).ConfigureAwait(false);
            _ = await candidate.PingAsync(cancellationToken).ConfigureAwait(false);
            return new ProductionEngineManagedSession(candidate, timeout);
        }
        catch
        {
            await candidate.DisposeAsync().ConfigureAwait(false);
            throw;
        }
    }

    private sealed class ProductionEngineManagedSession
        : IEngineManagedSession,
          IEngineEntitlementSession,
          IEngineAutomationSession,
          IEngineSessionStateSource
    {
        private readonly OfflineEngineSession session;
        private readonly TimeSpan heartbeatTimeout;
        private FishingSessionStateSnapshot sessionState = FishingSessionStateSnapshot.Empty;

        internal ProductionEngineManagedSession(
            OfflineEngineSession session,
            TimeSpan heartbeatTimeout)
        {
            this.session = session ?? throw new ArgumentNullException(nameof(session));
            this.heartbeatTimeout = heartbeatTimeout;
            session.SessionSnapshotReceived += OnSessionSnapshotReceived;
        }

        public event Action<FishingSessionStateSnapshot>? SessionStateChanged;

        public int ProcessId => session.ProcessId;

        public bool IsContained => session.IsContained;

        public bool IsAlive => session.IsAlive;

        public uint NegotiatedProtocolMinor => session.NegotiatedProtocolMinor;

        public TimeSpan BootstrapDuration => session.BootstrapDuration;

        public FishingSessionStateSnapshot SessionState => Volatile.Read(ref sessionState);

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

        public Task<ulong> RevokeSignedEntitlementAsync(CancellationToken cancellationToken) =>
            session.RevokeSignedEntitlementAsync(cancellationToken);

        public async Task<FishingSessionStateSnapshot> StartFishingSessionAsync(
            FishingRuntimeSettings settings,
            CancellationToken cancellationToken)
        {
            ArgumentNullException.ThrowIfNull(settings);
            settings.Validate();
            _ = await session.ApplyRuntimeSettingsAsync(
                settings,
                cancellationToken).ConfigureAwait(false);
            Volatile.Write(ref sessionState, await session.StartFishingSessionAsync(
                settings.Revision,
                cancellationToken).ConfigureAwait(false));
            return SessionState;
        }

        public async Task<FishingSessionStateSnapshot> StopAutomationAsync(
            CancellationToken cancellationToken)
        {
            Volatile.Write(ref sessionState,
                await session.StopAutomationAsync(cancellationToken)
                    .ConfigureAwait(false));
            return SessionState;
        }

        public ValueTask DisposeAsync()
        {
            session.SessionSnapshotReceived -= OnSessionSnapshotReceived;
            return session.DisposeAsync();
        }

        private void OnSessionSnapshotReceived(FishingSessionStateSnapshot snapshot)
        {
            Volatile.Write(ref sessionState, snapshot);
            SessionStateChanged?.Invoke(snapshot);
        }
    }
}
