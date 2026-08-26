using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.EngineIntegration.Notifications;
using Sonar.Fishing.Host.EngineIntegration.Inventory;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal sealed class ProductionEngineManagedSessionFactory : IEngineManagedSessionFactory
{
    private readonly string engineExecutable;
    private readonly TimeSpan timeout;
    private readonly Func<FishingRuntimeSettings> runtimeSettings;
    private readonly EngineProcessAuthorityMode authorityMode;

    internal ProductionEngineManagedSessionFactory(
        string engineExecutable,
        TimeSpan timeout,
        Func<FishingRuntimeSettings> runtimeSettings,
        EngineProcessAuthorityMode authorityMode = EngineProcessAuthorityMode.Production)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(engineExecutable);
        if (timeout <= TimeSpan.Zero || timeout > TimeSpan.FromSeconds(30))
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }
        ArgumentNullException.ThrowIfNull(runtimeSettings);
#if !SONAR_FISHING_DEVELOPER_FULL_ACCESS
        if (authorityMode == EngineProcessAuthorityMode.DeveloperFullAccess)
        {
            throw new ArgumentException(
                "developer_full_access_not_compiled",
                nameof(authorityMode));
        }
#endif
        if (authorityMode == EngineProcessAuthorityMode.OfflineDiagnostics)
        {
            throw new ArgumentOutOfRangeException(nameof(authorityMode));
        }
        this.engineExecutable = engineExecutable;
        this.timeout = timeout;
        this.runtimeSettings = runtimeSettings;
        this.authorityMode = authorityMode;
    }

    public async Task<IEngineManagedSession> StartAsync(CancellationToken cancellationToken)
    {
        var identity = BundleSessionIdentityLoader.Load(engineExecutable, authorityMode);
        var candidate = authorityMode == EngineProcessAuthorityMode.DeveloperFullAccess
            ? await OfflineEngineSession.StartDeveloperFullAccessAsync(
                engineExecutable,
                timeout,
                identity,
                cancellationToken).ConfigureAwait(false)
            : await OfflineEngineSession.StartProductionAsync(
                engineExecutable,
                timeout,
                identity,
                cancellationToken).ConfigureAwait(false);
        try
        {
            var settings = runtimeSettings();
            settings.Validate();
            var acceptedSettingsRevision = await candidate.ApplyRuntimeSettingsAsync(
                settings,
                cancellationToken).ConfigureAwait(false);
            _ = await candidate.PingAsync(cancellationToken).ConfigureAwait(false);
            var restoredIdleState = new FishingSessionStateSnapshot(
                revision: 0,
                running: false,
                stopping: false,
                detectedStage: string.Empty,
                totals: new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
                tackleItems: [],
                acceptedSettingsRevision: acceptedSettingsRevision);
            return new ProductionEngineManagedSession(
                candidate,
                timeout,
                restoredIdleState,
                authorityMode == EngineProcessAuthorityMode.DeveloperFullAccess);
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
          IEngineSessionStateSource,
          IEngineNotificationFrameSource,
          IEngineInventorySnapshotFrameSource,
          IEngineBootstrapAuthoritySession
    {
        private readonly OfflineEngineSession session;
        private readonly TimeSpan heartbeatTimeout;
        private FishingSessionStateSnapshot sessionState = FishingSessionStateSnapshot.Empty;

        internal ProductionEngineManagedSession(
            OfflineEngineSession session,
            TimeSpan heartbeatTimeout,
            FishingSessionStateSnapshot restoredIdleState,
            bool hasBootstrapRuntimeAuthority)
        {
            this.session = session ?? throw new ArgumentNullException(nameof(session));
            this.heartbeatTimeout = heartbeatTimeout;
            sessionState = restoredIdleState ??
                throw new ArgumentNullException(nameof(restoredIdleState));
            HasBootstrapRuntimeAuthority = hasBootstrapRuntimeAuthority;
            session.SessionSnapshotReceived += OnSessionSnapshotReceived;
            session.NotificationReceived += OnNotificationReceived;
            session.InventorySnapshotReceived += OnInventorySnapshotReceived;
        }

        public event Action<FishingSessionStateSnapshot>? SessionStateChanged;

        public event Action<FishingEngineNotificationFrame>? NotificationReceived;

        public event Action<FishingInventorySnapshotFrame>? InventorySnapshotReceived;

        public int ProcessId => session.ProcessId;

        public bool IsContained => session.IsContained;

        public bool IsAlive => session.IsAlive;

        public uint NegotiatedProtocolMinor => session.NegotiatedProtocolMinor;

        public TimeSpan BootstrapDuration => session.BootstrapDuration;

        public FishingSessionStateSnapshot SessionState => Volatile.Read(ref sessionState);

        public bool HasBootstrapRuntimeAuthority { get; }

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
            session.NotificationReceived -= OnNotificationReceived;
            session.InventorySnapshotReceived -= OnInventorySnapshotReceived;
            return session.DisposeAsync();
        }

        private void OnSessionSnapshotReceived(FishingSessionStateSnapshot snapshot)
        {
            Volatile.Write(ref sessionState, snapshot);
            SessionStateChanged?.Invoke(snapshot);
        }

        private void OnNotificationReceived(FishingEngineNotificationFrame notification) =>
            NotificationReceived?.Invoke(notification);

        private void OnInventorySnapshotReceived(FishingInventorySnapshotFrame snapshot) =>
            InventorySnapshotReceived?.Invoke(snapshot);
    }
}
