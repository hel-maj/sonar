using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.EngineStatus;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.FishingSessionSummary;

namespace Sonar.Fishing.Host.FishingPage;

public sealed class FishingPageViewModel : ObservableObject
{
    private EngineStatusViewModel _engineStatus;
    private FishingSessionSummaryViewModel _sessionSummary;
    private readonly IFishingAutomationRuntime? _automationRuntime;
    private readonly bool _productionPresentation;
    private readonly SynchronizationContext? _uiContext;
    private FishingSessionStateSnapshot? _lastAppliedSessionState;

    private FishingPageViewModel(
        EngineStatusViewModel engineStatus,
        FishingSessionSummaryViewModel sessionSummary,
        IFishingAutomationRuntime? automationRuntime = null,
        bool productionPresentation = false)
    {
        _engineStatus = engineStatus;
        _sessionSummary = sessionSummary;
        _automationRuntime = automationRuntime;
        _productionPresentation = productionPresentation;
        _uiContext = SynchronizationContext.Current;
        if (automationRuntime is IFishingAutomationStateSource stateSource)
        {
            stateSource.SessionStateChanged += OnRuntimeSessionStateChanged;
        }
        StartFishingCommand = new AsyncRelayCommand(
            StartFishingAsync,
            CanStartFishing);
        StopFishingCommand = new AsyncRelayCommand(
            StopFishingAsync,
            CanStopFishing);
    }

    public static FishingPageViewModel MigrationPreview { get; } = new(
        engineStatus: EngineStatusViewModel.MigrationPreview,
        sessionSummary: FishingSessionSummaryViewModel.FromSnapshot(
            new FishingSessionSummarySnapshot(
                durationSeconds: 3720,
                caughtCount: 12,
                releasedCount: 4,
                earnedMin: 15400,
                earnedMax: 16600,
                tackleItems:
                [
                    new TackleItemSnapshot("Удочка", 1),
                    new TackleItemSnapshot("Катушка", 1),
                    new TackleItemSnapshot("Леска", 2),
                    new TackleItemSnapshot("Крючки/поводки", 7),
                    new TackleItemSnapshot("Наживка/блёсна", 18),
                    new TackleItemSnapshot("Подсак", 1),
                ])));

    public static FishingPageViewModel CreateOfflineEngine() => new(
        engineStatus: EngineStatusViewModel.FromSnapshot(EngineSessionSnapshot.InertReady),
        sessionSummary: FishingSessionSummaryViewModel.FromSnapshot(
            FishingSessionSummarySnapshot.Empty));

    internal static FishingPageViewModel CreateProduction(
        IFishingAutomationRuntime automationRuntime) => new(
        engineStatus: EngineStatusViewModel.FromSnapshot(EngineSessionSnapshot.InertReady),
        sessionSummary: FishingSessionSummaryViewModel.FromSnapshot(
            FishingSessionSummarySnapshot.Empty),
        automationRuntime: automationRuntime ??
            throw new ArgumentNullException(nameof(automationRuntime)),
        productionPresentation: true);

    public event Action<FishingSessionStateSnapshot>? SessionStateChanged;

    public IAsyncRelayCommand StartFishingCommand { get; }

    public IAsyncRelayCommand StopFishingCommand { get; }

    public EngineStatusViewModel EngineStatus
    {
        get => _engineStatus;
        private set => SetProperty(ref _engineStatus, value);
    }

    public FishingSessionSummaryViewModel SessionSummary
    {
        get => _sessionSummary;
        private set => SetProperty(ref _sessionSummary, value);
    }

    public void ApplySessionState(FishingSessionStateSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        if (ReferenceEquals(snapshot, _lastAppliedSessionState))
        {
            return;
        }
        _lastAppliedSessionState = snapshot;
        EngineStatus = _productionPresentation
            ? EngineStatusViewModel.FromProductionSessionState(snapshot)
            : EngineStatusViewModel.FromSessionState(snapshot);
        SessionSummary = FishingSessionSummaryViewModel.FromSessionState(snapshot);
        NotifyCommandAvailability();
    }

    internal void RefreshCommandAuthority() => NotifyCommandAvailability();

    private void OnRuntimeSessionStateChanged(FishingSessionStateSnapshot snapshot)
    {
        if (_uiContext is null || ReferenceEquals(
                SynchronizationContext.Current,
                _uiContext))
        {
            PublishSessionState(snapshot);
            return;
        }
        _uiContext.Post(
            static state =>
            {
                var (owner, value) =
                    ((FishingPageViewModel, FishingSessionStateSnapshot))state!;
                owner.PublishSessionState(value);
            },
            (this, snapshot));
    }

    private void PublishSessionState(FishingSessionStateSnapshot snapshot)
    {
        if (ReferenceEquals(snapshot, _lastAppliedSessionState))
        {
            return;
        }
        ApplySessionState(snapshot);
        SessionStateChanged?.Invoke(snapshot);
    }

    private bool CanStartFishing() =>
        _automationRuntime is { HasActiveEntitlement: true } &&
        EngineStatus.CanStart &&
        !StartFishingCommand.IsRunning &&
        !StopFishingCommand.IsRunning;

    private bool CanStopFishing() =>
        _automationRuntime is not null &&
        EngineStatus.CanStop &&
        !StartFishingCommand.IsRunning &&
        !StopFishingCommand.IsRunning;

    private Task StartFishingAsync(CancellationToken cancellationToken)
    {
        if (_automationRuntime is not { HasActiveEntitlement: true } ||
            !EngineStatus.CanStart ||
            StopFishingCommand.IsRunning)
        {
            return Task.CompletedTask;
        }
        return ExecuteCommandAsync(
            runtime => runtime.StartAsync(cancellationToken),
            cancellationToken);
    }

    private Task StopFishingAsync(CancellationToken cancellationToken)
    {
        if (_automationRuntime is null ||
            !EngineStatus.CanStop ||
            StartFishingCommand.IsRunning)
        {
            return Task.CompletedTask;
        }
        return ExecuteCommandAsync(
            runtime => runtime.StopAsync(cancellationToken),
            cancellationToken);
    }

    private async Task ExecuteCommandAsync(
        Func<IFishingAutomationRuntime, Task<FishingSessionStateSnapshot>> command,
        CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        var runtime = _automationRuntime ??
            throw new InvalidOperationException("fishing_automation_runtime_missing");
        NotifyCommandAvailability();
        try
        {
            var snapshot = await command(runtime).ConfigureAwait(true);
            PublishSessionState(snapshot);
        }
        catch (EngineCommandRejectedException exception)
        {
            EngineStatus = EngineStatus.WithCommandRejection(exception.Reason);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
        }
        catch (Exception)
        {
            EngineStatus = EngineStatusViewModel.FromBoundaryFailure(
                runtime.HasActiveEntitlement);
        }
        finally
        {
            NotifyCommandAvailability();
        }
    }

    private void NotifyCommandAvailability()
    {
        StartFishingCommand.NotifyCanExecuteChanged();
        StopFishingCommand.NotifyCanExecuteChanged();
    }
}
