using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.UI.Wpf.Controls;
using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineHealth;

public enum EngineHealthPhase
{
    Demo,
    NotChecked,
    Checking,
    Healthy,
    Failed,
    Cancelled,
}

public sealed class EngineHealthViewModel : ObservableObject
{
    private readonly IEngineHealthUseCase? _useCase;
    private readonly Action<FishingSessionStateSnapshot>? _sessionStateConsumer;
    private readonly string? _expectedAuthority;
    private readonly bool _productionPresentation;
    private EngineHealthPhase _phase;
    private string _title;
    private string _description;
    private string _badgeText;
    private SemanticTone _badgeTone;

    private EngineHealthViewModel(
        IEngineHealthUseCase? useCase,
        Action<FishingSessionStateSnapshot>? sessionStateConsumer,
        string modeLabel,
        EngineHealthPhase phase,
        string title,
        string description,
        string badgeText,
        SemanticTone badgeTone,
        string? expectedAuthority = null,
        bool productionPresentation = false)
    {
        _useCase = useCase;
        _sessionStateConsumer = sessionStateConsumer;
        _expectedAuthority = expectedAuthority;
        _productionPresentation = productionPresentation;
        ModeLabel = modeLabel;
        _phase = phase;
        _title = title;
        _description = description;
        _badgeText = badgeText;
        _badgeTone = badgeTone;
        CheckHealthCommand = new AsyncRelayCommand(CheckHealthAsync, CanCheckHealth);
    }

    public static EngineHealthViewModel CreateDemo() => new(
        useCase: null,
        sessionStateConsumer: null,
        modeLabel: "Предпросмотр",
        phase: EngineHealthPhase.Demo,
        title: "Проверка недоступна",
        description: "Запустите приложение обычным способом и повторите.",
        badgeText: "Недоступно",
        badgeTone: SemanticTone.Neutral);

    public static EngineHealthViewModel CreateOffline(
        IEngineHealthUseCase useCase,
        Action<FishingSessionStateSnapshot>? sessionStateConsumer = null)
    {
        ArgumentNullException.ThrowIfNull(useCase);
        return new EngineHealthViewModel(
            useCase,
            sessionStateConsumer,
            modeLabel: "Локальный режим",
            phase: EngineHealthPhase.NotChecked,
            title: "Готово к проверке",
            description: "Нажмите «Проверить», чтобы подтвердить готовность приложения.",
            badgeText: "Не проверено",
            badgeTone: SemanticTone.Neutral,
            expectedAuthority: OfflineEngineSessionProtocol.OfflineDiagnosticAuthority);
    }

    internal static EngineHealthViewModel CreateProduction(
        IEngineHealthUseCase useCase,
        Action<FishingSessionStateSnapshot>? sessionStateConsumer = null)
    {
        ArgumentNullException.ThrowIfNull(useCase);
        return new EngineHealthViewModel(
            useCase,
            sessionStateConsumer,
            modeLabel: "Рабочий режим",
            phase: EngineHealthPhase.NotChecked,
            title: "Проверяем готовность",
            description: "Дождитесь завершения проверки перед началом рыбалки.",
            badgeText: "Проверка",
            badgeTone: SemanticTone.Neutral,
            expectedAuthority: OfflineEngineSessionProtocol.NativeProductionAuthority,
            productionPresentation: true);
    }

    public string ModeLabel { get; }

    public EngineHealthPhase Phase
    {
        get => _phase;
        private set => SetProperty(ref _phase, value);
    }

    public string Title
    {
        get => _title;
        private set => SetProperty(ref _title, value);
    }

    public string Description
    {
        get => _description;
        private set => SetProperty(ref _description, value);
    }

    public string BadgeText
    {
        get => _badgeText;
        private set => SetProperty(ref _badgeText, value);
    }

    public SemanticTone BadgeTone
    {
        get => _badgeTone;
        private set => SetProperty(ref _badgeTone, value);
    }

    public IAsyncRelayCommand CheckHealthCommand { get; }

    public Task RunInitialCheckAsync() =>
        _useCase is null
            ? Task.CompletedTask
            : CheckHealthCommand.ExecuteAsync(null);

    public void Cancel() => CheckHealthCommand.Cancel();

    public async Task StopAsync()
    {
        Cancel();
        if (_useCase is IAsyncDisposable disposable)
        {
            await disposable.DisposeAsync().ConfigureAwait(false);
        }
    }

    private bool CanCheckHealth() => _useCase is not null && !CheckHealthCommand.IsRunning;

    private async Task CheckHealthAsync(CancellationToken cancellationToken)
    {
        if (_useCase is null)
        {
            return;
        }

        SetState(
            EngineHealthPhase.Checking,
            "Проверяем приложение",
            "Это обычно занимает несколько секунд.",
            "Проверка",
            SemanticTone.Warning);
        CheckHealthCommand.NotifyCanExecuteChanged();

        try
        {
            var result = await _useCase.RunAsync(cancellationToken).ConfigureAwait(true);
            if (result.SideEffectsEnabled)
            {
                throw new UnauthorizedAccessException("offline_engine_side_effects_enabled");
            }
            if (!result.ProcessContainmentVerified)
            {
                throw new InvalidOperationException("offline_engine_containment_missing");
            }
            if (_expectedAuthority is not null &&
                !string.Equals(
                    result.ProductionAuthority,
                    _expectedAuthority,
                    StringComparison.Ordinal))
            {
                throw new InvalidOperationException("production_authority_changed");
            }

            _sessionStateConsumer?.Invoke(result.SessionState);

            SetState(
                EngineHealthPhase.Healthy,
                "Приложение готово",
                _productionPresentation
                    ? "Можно начинать рыбалку."
                    : "Все необходимые компоненты доступны.",
                "Готово",
                SemanticTone.Success);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            SetState(
                EngineHealthPhase.Cancelled,
                "Проверка остановлена",
                "Повторите проверку перед началом рыбалки.",
                "Остановлено",
                SemanticTone.Neutral);
        }
        catch (Exception)
        {
            SetState(
                EngineHealthPhase.Failed,
                "Проверка не пройдена",
                "Перезапустите приложение и повторите проверку.",
                "Ошибка",
                SemanticTone.Danger);
        }
        finally
        {
            CheckHealthCommand.NotifyCanExecuteChanged();
        }
    }

    private void SetState(
        EngineHealthPhase phase,
        string title,
        string description,
        string badgeText,
        SemanticTone badgeTone)
    {
        Phase = phase;
        Title = title;
        Description = description;
        BadgeText = badgeText;
        BadgeTone = badgeTone;
    }
}
