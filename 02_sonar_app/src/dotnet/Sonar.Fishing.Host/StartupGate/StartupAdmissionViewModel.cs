using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.StartupGate;

public enum StartupAdmissionPhase
{
    Checking = 1,
    Allowed = 2,
    Blocked = 3,
    Unavailable = 4,
}

public sealed class StartupAdmissionViewModel : ObservableObject
{
    private readonly Action<Uri>? openDownload;
    private StartupAdmissionPhase phase;
    private string title = string.Empty;
    private string message = string.Empty;
    private string badgeText = string.Empty;
    private SemanticTone badgeTone;
    private Uri? downloadUri;
    private string reason = string.Empty;

    public StartupAdmissionViewModel(
        Action<Uri>? openDownload = null,
        Action? close = null)
    {
        this.openDownload = openDownload;
        DownloadCommand = new RelayCommand(OpenDownload, CanOpenDownload);
        CloseCommand = new RelayCommand(
            () => close?.Invoke(),
            () => close is not null);
        BeginCheck();
    }

    public StartupAdmissionPhase Phase
    {
        get => phase;
        private set => SetProperty(ref phase, value);
    }

    public string Title
    {
        get => title;
        private set => SetProperty(ref title, value);
    }

    public string Message
    {
        get => message;
        private set => SetProperty(ref message, value);
    }

    public string BadgeText
    {
        get => badgeText;
        private set => SetProperty(ref badgeText, value);
    }

    public SemanticTone BadgeTone
    {
        get => badgeTone;
        private set => SetProperty(ref badgeTone, value);
    }

    public string Reason
    {
        get => reason;
        private set => SetProperty(ref reason, value);
    }

    public bool IsChecking => Phase == StartupAdmissionPhase.Checking;

    public bool CanDownload => downloadUri is not null && openDownload is not null;

    public string DownloadUrl => downloadUri?.AbsoluteUri ?? string.Empty;

    public IRelayCommand DownloadCommand { get; }

    public IRelayCommand CloseCommand { get; }

    public void BeginCheck()
    {
        downloadUri = null;
        SetState(
            StartupAdmissionPhase.Checking,
            "Проверяем доступность этой версии",
            "Подождите несколько секунд.",
            "Проверка",
            SemanticTone.Info,
            string.Empty);
    }

    public void Apply(StartupAdmissionDecision decision)
    {
        ArgumentNullException.ThrowIfNull(decision);
        downloadUri = null;
        switch (decision.Kind)
        {
            case StartupAdmissionKind.Allowed:
                SetState(
                    StartupAdmissionPhase.Allowed,
                    "Версия доступна",
                    "Можно продолжить работу.",
                    "Готово",
                    SemanticTone.Success,
                    string.Empty);
                break;
            case StartupAdmissionKind.Blocked when TryGetSafeDownloadUri(
                decision.DownloadUrl,
                out var safeDownloadUri):
                downloadUri = safeDownloadUri;
                SetState(
                    StartupAdmissionPhase.Blocked,
                    "Требуется актуальная версия",
                    "Установленная версия больше не поддерживается. Скачайте актуальную версию Sonar Fishing.",
                    "Обновление",
                    SemanticTone.Warning,
                    decision.Reason);
                break;
            case StartupAdmissionKind.Blocked:
                SetState(
                    StartupAdmissionPhase.Unavailable,
                    "Безопасная ссылка недоступна",
                    "Не удалось открыть ссылку на обновление. Обратитесь в поддержку.",
                    "Остановлено",
                    SemanticTone.Danger,
                    "startup_block_download_url_invalid");
                break;
            case StartupAdmissionKind.Unavailable:
                SetState(
                    StartupAdmissionPhase.Unavailable,
                    "Не удалось проверить версию",
                    "Запуск остановлен. Проверьте подключение и повторите попытку позже.",
                    "Недоступно",
                    SemanticTone.Danger,
                    decision.Reason);
                break;
            default:
                throw new ArgumentOutOfRangeException(nameof(decision));
        }
    }

    private void OpenDownload()
    {
        if (downloadUri is null || openDownload is null)
        {
            return;
        }
        openDownload(downloadUri);
    }

    private bool CanOpenDownload() => downloadUri is not null && openDownload is not null;

    private void SetState(
        StartupAdmissionPhase nextPhase,
        string nextTitle,
        string nextMessage,
        string nextBadgeText,
        SemanticTone nextBadgeTone,
        string nextReason)
    {
        Phase = nextPhase;
        Title = nextTitle;
        Message = nextMessage;
        BadgeText = nextBadgeText;
        BadgeTone = nextBadgeTone;
        Reason = nextReason;
        OnPropertyChanged(nameof(IsChecking));
        OnPropertyChanged(nameof(CanDownload));
        OnPropertyChanged(nameof(DownloadUrl));
        DownloadCommand.NotifyCanExecuteChanged();
    }

    private static bool TryGetSafeDownloadUri(string value, out Uri? uri)
    {
        if (Uri.TryCreate(value, UriKind.Absolute, out var candidate) &&
            string.Equals(candidate.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase) &&
            string.IsNullOrEmpty(candidate.UserInfo))
        {
            uri = candidate;
            return true;
        }
        uri = null;
        return false;
    }
}
