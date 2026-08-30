using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Sonar.Fishing.Host.Presentation;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.StreamingPage;

public sealed class StreamingPageViewModel : ObservableObject
{
    private readonly IStreamingController controller;
    private readonly bool featureAllowed;
    private readonly bool chatFeatureAllowed;
    private readonly Action<bool>? persistSnapshotMode;
    private StreamingRuntimeSnapshot snapshot;
    private string commandError = string.Empty;

    public StreamingPageViewModel()
        : this(
            new UnavailableStreamingController(snapshotModeEnabled: false),
            featureAllowed: false,
            chatFeatureAllowed: false)
    {
    }

    public StreamingPageViewModel(
        IStreamingController controller,
        bool featureAllowed,
        bool chatFeatureAllowed,
        Action<bool>? persistSnapshotMode = null)
    {
        this.controller = controller ?? throw new ArgumentNullException(nameof(controller));
        this.featureAllowed = featureAllowed;
        this.chatFeatureAllowed = chatFeatureAllowed;
        this.persistSnapshotMode = persistSnapshotMode;
        snapshot = controller.Current.Normalize();
        controller.SnapshotChanged += ApplySnapshot;
        StartCommand = new RelayCommand(Start, () => CanStart);
        StopCommand = new RelayCommand(Stop, () => CanStop);
        ToggleChatModeCommand = new RelayCommand(ToggleChatMode, () => CanToggleChatMode);
    }

    public IReadOnlyList<StreamingQualityProfile> QualityOptions =>
        StreamingQualityCatalog.All;

    public string Status => snapshot.Status switch
    {
        StreamingRuntimeStatus.Unavailable => "Недоступен",
        StreamingRuntimeStatus.Preparing => "Подготовка",
        StreamingRuntimeStatus.Starting => "Запускается",
        StreamingRuntimeStatus.Online => "В эфире",
        StreamingRuntimeStatus.Offline => "Остановлен",
        StreamingRuntimeStatus.Error => "Ошибка",
        _ => "Неизвестно",
    };

    public SemanticTone StatusTone => snapshot.Status switch
    {
        StreamingRuntimeStatus.Online => SemanticTone.Success,
        StreamingRuntimeStatus.Preparing or StreamingRuntimeStatus.Starting => SemanticTone.Warning,
        StreamingRuntimeStatus.Error => SemanticTone.Danger,
        _ => SemanticTone.Neutral,
    };

    public string Description => !string.IsNullOrEmpty(commandError)
        ? CommandErrorText(commandError)
        : !string.IsNullOrEmpty(snapshot.Error)
            ? snapshot.Error
            : snapshot.Status switch
            {
                StreamingRuntimeStatus.Online => "Трансляция доступна по указанной ссылке.",
                StreamingRuntimeStatus.Preparing => "Подготавливаются средства трансляции.",
                StreamingRuntimeStatus.Starting => "Ожидаются первые сегменты трансляции.",
                _ => "Трансляция остановлена.",
            };

    public bool HasNotice => snapshot.Status is StreamingRuntimeStatus.Unavailable or
        StreamingRuntimeStatus.Error || !string.IsNullOrEmpty(commandError);

    public bool CanStart => featureAllowed &&
        snapshot.Status is StreamingRuntimeStatus.Offline or StreamingRuntimeStatus.Error;

    public bool CanStop => featureAllowed &&
        (snapshot.Active || snapshot.Status is StreamingRuntimeStatus.Preparing or
            StreamingRuntimeStatus.Starting or StreamingRuntimeStatus.Error);

    public bool CanConfigure => featureAllowed &&
        snapshot.Status is not StreamingRuntimeStatus.Unavailable and
        not StreamingRuntimeStatus.Preparing and
        not StreamingRuntimeStatus.Starting;

    public bool CanToggleChatMode => chatFeatureAllowed &&
        (snapshot.Active || snapshot.ChatActive || snapshot.ChatModeEnabled);

    public bool IsChatModeAvailable => chatFeatureAllowed;

    public string CaptureArea => snapshot.ChatZoomEnabled ? "Чат" : "Все окно";

    public string Quality
    {
        get => snapshot.Quality;
        set
        {
            if (!string.Equals(value, snapshot.Quality, StringComparison.Ordinal))
            {
                ApplyResult(controller.SetQuality(value));
            }
        }
    }

    public bool ChatZoomEnabled
    {
        get => snapshot.ChatZoomEnabled;
        set
        {
            if (value != snapshot.ChatZoomEnabled)
            {
                ApplyResult(controller.SetChatZoom(value));
            }
        }
    }

    public bool SnapshotModeEnabled
    {
        get => snapshot.SnapshotModeEnabled;
        set
        {
            if (value == snapshot.SnapshotModeEnabled)
            {
                return;
            }
            var result = controller.SetSnapshotMode(value);
            ApplyResult(result);
            if (result.Accepted)
            {
                persistSnapshotMode?.Invoke(value);
            }
        }
    }

    public string AutoStop => snapshot.Active && snapshot.SecondsUntilAutoStop is int seconds
        ? $"{seconds / 60}:{seconds % 60:00} без зрителей"
        : "—";

    public string StreamUrl => snapshot.StreamUrl ?? "—";

    public string TargetFps => snapshot.SnapshotModeEnabled ? "10" : "30";

    public string Bitrate => StreamingQualityCatalog.Require(snapshot.Quality)
        .BitrateFor(snapshot.SnapshotModeEnabled);

    public string Mode => snapshot.SnapshotModeEnabled ? "10 FPS" : "Обычный";

    public string Uptime => snapshot.Active && snapshot.StartedAt is DateTimeOffset startedAt
        ? FishingValueFormatter.Duration(
            Math.Max(0, (DateTimeOffset.UtcNow - startedAt).TotalSeconds))
        : "00:00:00";

    public string ChatModeActionText => snapshot.ChatModeEnabled || snapshot.ChatActive
        ? "Выйти из режима чата"
        : "Включить режим чата";

    public IRelayCommand StartCommand { get; }

    public IRelayCommand StopCommand { get; }

    public IRelayCommand ToggleChatModeCommand { get; }

    public void ApplySnapshot(StreamingRuntimeSnapshot next)
    {
        ArgumentNullException.ThrowIfNull(next);
        next = next.Normalize();
        if (next.Revision < snapshot.Revision)
        {
            return;
        }
        snapshot = next;
        commandError = string.Empty;
        NotifySnapshotChanged();
    }

    private void Start() => ApplyResult(controller.Start());

    private void Stop() => ApplyResult(controller.Stop("ui"));

    private void ToggleChatMode() =>
        ApplyResult(controller.SetChatMode(!(snapshot.ChatModeEnabled || snapshot.ChatActive)));

    private void ApplyResult(StreamingCommandResult result)
    {
        ArgumentNullException.ThrowIfNull(result);
        result.Snapshot.Validate();
        commandError = result.Accepted ? string.Empty : result.Reason;
        snapshot = result.Snapshot.Normalize();
        NotifySnapshotChanged();
    }

    private void NotifySnapshotChanged()
    {
        OnPropertyChanged(nameof(Status));
        OnPropertyChanged(nameof(StatusTone));
        OnPropertyChanged(nameof(Description));
        OnPropertyChanged(nameof(HasNotice));
        OnPropertyChanged(nameof(CanStart));
        OnPropertyChanged(nameof(CanStop));
        OnPropertyChanged(nameof(CanConfigure));
        OnPropertyChanged(nameof(CanToggleChatMode));
        OnPropertyChanged(nameof(CaptureArea));
        OnPropertyChanged(nameof(Quality));
        OnPropertyChanged(nameof(ChatZoomEnabled));
        OnPropertyChanged(nameof(SnapshotModeEnabled));
        OnPropertyChanged(nameof(AutoStop));
        OnPropertyChanged(nameof(StreamUrl));
        OnPropertyChanged(nameof(TargetFps));
        OnPropertyChanged(nameof(Bitrate));
        OnPropertyChanged(nameof(Mode));
        OnPropertyChanged(nameof(Uptime));
        OnPropertyChanged(nameof(ChatModeActionText));
        StartCommand.NotifyCanExecuteChanged();
        StopCommand.NotifyCanExecuteChanged();
        ToggleChatModeCommand.NotifyCanExecuteChanged();
    }

    private static string CommandErrorText(string reason) => reason switch
    {
        "streaming_runtime_unavailable" => "Средства трансляции недоступны в текущей установке.",
        "streaming_feature_denied" => "Трансляция недоступна для текущей лицензии.",
        "stream_chat_feature_denied" => "Режим чата недоступен для текущей лицензии.",
        "streaming_already_running" or "streaming_restart_in_progress" =>
            "Изменение уже выполняется. Дождитесь обновления статуса.",
        "streaming_not_online" => "Сначала запустите трансляцию.",
        "streaming_chat_command_timeout" or "streaming_chat_command_failed" =>
            "Не удалось переключить режим чата.",
        _ => "Команда трансляции не выполнена.",
    };
}
