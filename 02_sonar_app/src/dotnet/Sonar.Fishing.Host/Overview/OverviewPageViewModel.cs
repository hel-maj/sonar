using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Presentation;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StreamingPage;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.Overview;

public sealed class OverviewPageViewModel : ObservableObject
{
    private readonly RecentEventBuffer recentEvents;
    private string fishingStatus = "Готово";
    private SemanticTone fishingTone = SemanticTone.Neutral;
    private string duration = "00:00:00";
    private string caught = "0";
    private string kept = "0";
    private string income = "0 $";
    private string incomePerHour = "0 $";
    private string streamStatus = "Недоступен";
    private SemanticTone streamTone = SemanticTone.Neutral;
    private string streamDescription = "Средства трансляции недоступны";

    public OverviewPageViewModel(
        TelegramHostSettings telegram,
        RecentEventBuffer? recentEvents = null)
    {
        ArgumentNullException.ThrowIfNull(telegram);
        this.recentEvents = recentEvents ?? new RecentEventBuffer();
        TelegramStatus = telegram.Enabled ? "Включен" : "Отключен";
        TelegramTone = telegram.Enabled ? SemanticTone.Success : SemanticTone.Neutral;
        TelegramAdministrators = FormatAdministrators(telegram.AdminIds);
        TelegramNotifications = $"{CountEnabled(telegram.Notifications)} из 7 уведомлений";
        ClearEventsCommand = new RelayCommand(ClearEvents, () => HasEvents);
    }

    public string FishingStatus
    {
        get => fishingStatus;
        private set => SetProperty(ref fishingStatus, value);
    }

    public SemanticTone FishingTone
    {
        get => fishingTone;
        private set => SetProperty(ref fishingTone, value);
    }

    public string Duration
    {
        get => duration;
        private set => SetProperty(ref duration, value);
    }

    public string Caught
    {
        get => caught;
        private set => SetProperty(ref caught, value);
    }

    public string Kept
    {
        get => kept;
        private set => SetProperty(ref kept, value);
    }

    public string Income
    {
        get => income;
        private set => SetProperty(ref income, value);
    }

    public string IncomePerHour
    {
        get => incomePerHour;
        private set => SetProperty(ref incomePerHour, value);
    }

    public string TelegramStatus { get; }

    public SemanticTone TelegramTone { get; }

    public string TelegramAdministrators { get; }

    public string TelegramNotifications { get; }

    public string StreamStatus
    {
        get => streamStatus;
        private set => SetProperty(ref streamStatus, value);
    }

    public SemanticTone StreamTone
    {
        get => streamTone;
        private set => SetProperty(ref streamTone, value);
    }

    public string StreamDescription
    {
        get => streamDescription;
        private set => SetProperty(ref streamDescription, value);
    }

    public IReadOnlyList<FishingEventSnapshot> Events => recentEvents.PresentationSnapshot();

    public bool HasEvents => recentEvents.Count > 0;

    public IRelayCommand ClearEventsCommand { get; }

    public void ApplySessionState(FishingSessionStateSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        FishingStatus = snapshot.Stopping
            ? "Останавливается"
            : snapshot.Running
                ? "Работает"
                : "Готово";
        FishingTone = snapshot.Stopping
            ? SemanticTone.Warning
            : snapshot.Running
                ? SemanticTone.Success
                : SemanticTone.Neutral;
        Duration = FishingValueFormatter.Duration(snapshot.Totals.DurationSeconds);
        Caught = FishingValueFormatter.CatchSummary(
            snapshot.Totals.CaughtCount,
            snapshot.Totals.CaughtKg);
        var keptCount = Math.Max(0, snapshot.Totals.CaughtCount - snapshot.Totals.ReleasedCount);
        var keptKg = Math.Max(0, snapshot.Totals.CaughtKg - snapshot.Totals.ReleasedKg);
        Kept = FishingValueFormatter.CatchSummary(keptCount, keptKg);
        Income = FishingValueFormatter.MoneyRange(
            snapshot.Totals.EarnedMin,
            snapshot.Totals.EarnedMax);
        var hours = snapshot.Totals.DurationSeconds / 3600d;
        IncomePerHour = hours > 0
            ? FishingValueFormatter.MoneyRange(
                snapshot.Totals.EarnedMin / hours,
                snapshot.Totals.EarnedMax / hours)
            : "0 $";
    }

    public void ApplyStreamingSnapshot(StreamingRuntimeSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        snapshot = snapshot.Normalize();
        StreamStatus = snapshot.Status switch
        {
            StreamingRuntimeStatus.Unavailable => "Недоступен",
            StreamingRuntimeStatus.Preparing => "Подготовка",
            StreamingRuntimeStatus.Starting => "Запускается",
            StreamingRuntimeStatus.Online => "В эфире",
            StreamingRuntimeStatus.Offline => "Остановлен",
            StreamingRuntimeStatus.Error => "Ошибка",
            _ => "Неизвестно",
        };
        StreamTone = snapshot.Status switch
        {
            StreamingRuntimeStatus.Online => SemanticTone.Success,
            StreamingRuntimeStatus.Preparing or StreamingRuntimeStatus.Starting => SemanticTone.Warning,
            StreamingRuntimeStatus.Error => SemanticTone.Danger,
            _ => SemanticTone.Neutral,
        };
        var area = snapshot.ChatZoomEnabled ? "чат" : "всё окно";
        var mode = snapshot.SnapshotModeEnabled ? "10 FPS" : "30 FPS";
        StreamDescription = snapshot.Status == StreamingRuntimeStatus.Unavailable
            ? "Средства трансляции недоступны"
            : $"{snapshot.Quality}, {mode}, {area}";
    }

    public void NotifyEventsChanged()
    {
        OnPropertyChanged(nameof(Events));
        OnPropertyChanged(nameof(HasEvents));
        ClearEventsCommand.NotifyCanExecuteChanged();
    }

    private void ClearEvents()
    {
        recentEvents.Clear();
        NotifyEventsChanged();
    }

    private static string FormatAdministrators(IReadOnlyList<long> adminIds)
    {
        if (adminIds.Count == 0)
        {
            return "Не настроены";
        }
        var first = string.Join(", ", adminIds.Take(2));
        return adminIds.Count > 2 ? $"{first} и ещё {adminIds.Count - 2}" : first;
    }

    private static int CountEnabled(TelegramNotificationSettings settings) =>
        new[]
        {
            settings.Catch,
            settings.StartStop,
            settings.Meal,
            settings.InventoryFull,
            settings.InventorySpaceLow,
            settings.BaitTired,
            settings.FocusLost,
        }.Count(enabled => enabled);
}
