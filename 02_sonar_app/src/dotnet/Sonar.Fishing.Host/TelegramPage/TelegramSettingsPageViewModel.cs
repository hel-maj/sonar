using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed class TelegramSettingsSaveResult
{
    public TelegramSettingsSaveResult(
        TelegramHostSettings settings,
        string botToken,
        string enableBlockReason)
    {
        Settings = settings ?? throw new ArgumentNullException(nameof(settings));
        BotToken = botToken ?? throw new ArgumentNullException(nameof(botToken));
        EnableBlockReason = enableBlockReason ?? throw new ArgumentNullException(nameof(enableBlockReason));
    }

    public TelegramHostSettings Settings { get; }

    public string BotToken { get; }

    public string EnableBlockReason { get; }

    public bool EnableRequestRejected => EnableBlockReason.Length != 0;
}

public sealed class TelegramSettingsPageViewModel : ObservableObject
{
    public static Uri BotFatherUri { get; } = new("https://t.me/BotFather");

    public static Uri UserIdBotUri { get; } = new("https://t.me/Getmyid_bot");

    private TelegramSettingsDraft saved;
    private TelegramSettingsDraft draft;
    private bool featureAllowed;
    private TelegramAvailability availability;
    private readonly Action<TelegramSettingsSaveResult>? saveHandler;
    private string interactionMessage = string.Empty;

    public TelegramSettingsPageViewModel(
        TelegramHostSettings settings,
        string botToken,
        bool featureAllowed,
        TelegramAvailability? availability = null,
        Action<TelegramSettingsSaveResult>? saveHandler = null)
    {
        ArgumentNullException.ThrowIfNull(settings);
        saved = TelegramSettingsDraft.FromSettings(settings, botToken);
        draft = TelegramSettingsDraft.FromSettings(settings, botToken);
        this.featureAllowed = featureAllowed;
        this.availability = availability ?? TelegramAvailability.Unknown;
        this.saveHandler = saveHandler;
        SaveCommand = new RelayCommand(Save, () => IsDirty && this.saveHandler is not null);
        DiscardCommand = new RelayCommand(DiscardChanges, () => IsDirty);
    }

    public TelegramSettingsDraft Draft
    {
        get => draft;
        private set
        {
            if (ReferenceEquals(draft, value))
            {
                return;
            }
            draft = value;
            RaiseStateChanged();
        }
    }

    public bool IsDirty => !Draft.ContentEquals(saved);

    public bool CredentialsEditable => !Draft.Enabled;

    public bool CanEnable => Draft.Enabled || EnableBlockReason.Length == 0;

    public string EnableBlockReason
    {
        get
        {
            if (!Draft.ConfigurationReady)
            {
                return "укажите токен бота и ID администраторов";
            }
            if (!featureAllowed)
            {
                return "функция Telegram недоступна для лицензии";
            }
            if (AvailabilityMatches(TelegramAvailabilityStatus.Available))
            {
                return string.Empty;
            }
            if (AvailabilityMatches(TelegramAvailabilityStatus.Checking))
            {
                return "подождите завершения подключения";
            }
            if (AvailabilityMatches(TelegramAvailabilityStatus.Unavailable) &&
                availability.Error.Length != 0)
            {
                return availability.Error;
            }
            return "Telegram недоступен";
        }
    }

    public string StatusText
    {
        get
        {
            var available = AvailabilityMatches(TelegramAvailabilityStatus.Available);
            if (Draft.Enabled)
            {
                return available ? "Включен" : "Недоступен";
            }
            return Draft.ConfigurationReady && !available ? "Недоступен" : "Отключен";
        }
    }

    public bool Enabled
    {
        get => Draft.Enabled;
        set
        {
            if (!TrySetEnabled(value, out var reason))
            {
                InteractionMessage = reason;
                OnPropertyChanged();
                return;
            }
            InteractionMessage = string.Empty;
        }
    }

    public string BotToken
    {
        get => Draft.BotToken;
        set => UpdateCredentials(value, Draft.AdminIdsText);
    }

    public string AdminIdsText
    {
        get => Draft.AdminIdsText;
        set => UpdateCredentials(Draft.BotToken, value);
    }

    public string InventorySpaceLowThresholdText
    {
        get => Draft.InventorySpaceLowThresholdText;
        set => UpdateInventorySpaceLowThreshold(value);
    }

    public bool NotifyCatch
    {
        get => Draft.Notifications.Catch;
        set => ReplaceNotifications(Draft.Notifications with { Catch = value });
    }

    public bool NotifyStartStop
    {
        get => Draft.Notifications.StartStop;
        set => ReplaceNotifications(Draft.Notifications with { StartStop = value });
    }

    public bool NotifyMeal
    {
        get => Draft.Notifications.Meal;
        set => ReplaceNotifications(Draft.Notifications with { Meal = value });
    }

    public bool NotifyInventoryFull
    {
        get => Draft.Notifications.InventoryFull;
        set => ReplaceNotifications(Draft.Notifications with { InventoryFull = value });
    }

    public bool NotifyInventorySpaceLow
    {
        get => Draft.Notifications.InventorySpaceLow;
        set => ReplaceNotifications(Draft.Notifications with { InventorySpaceLow = value });
    }

    public bool NotifyBaitTired
    {
        get => Draft.Notifications.BaitTired;
        set => ReplaceNotifications(Draft.Notifications with { BaitTired = value });
    }

    public bool NotifyFocusLost
    {
        get => Draft.Notifications.FocusLost;
        set => ReplaceNotifications(Draft.Notifications with { FocusLost = value });
    }

    public bool CanPersist => saveHandler is not null;

    public string InteractionMessage
    {
        get => interactionMessage;
        private set => SetProperty(ref interactionMessage, value);
    }

    public IRelayCommand SaveCommand { get; }

    public IRelayCommand DiscardCommand { get; }

    public void UpdateCredentials(string botToken, string adminIdsText) =>
        Draft = Draft.WithCredentials(botToken, adminIdsText);

    public bool TrySetEnabled(bool enabled, out string blockReason)
    {
        if (!enabled)
        {
            Draft = Draft.WithEnabled(false);
            blockReason = string.Empty;
            return true;
        }
        blockReason = EnableBlockReason;
        if (blockReason.Length != 0)
        {
            return false;
        }
        Draft = Draft.WithEnabled(true);
        return true;
    }

    public void ReplaceNotifications(TelegramNotificationSettings notifications) =>
        Draft = Draft.WithNotifications(notifications);

    public void UpdateInventorySpaceLowThreshold(string value) =>
        Draft = Draft.WithInventorySpaceLowThreshold(value);

    public void UpdateAccessPolicy(
        bool allowed,
        TelegramAvailability nextAvailability)
    {
        featureAllowed = allowed;
        availability = nextAvailability ?? throw new ArgumentNullException(nameof(nextAvailability));
        RaiseStateChanged();
    }

    public TelegramSettingsSaveResult BuildSaveResult()
    {
        var reason = Draft.Enabled ? EnableBlockReason : string.Empty;
        return new TelegramSettingsSaveResult(
            Draft.BuildSettings(Draft.Enabled && reason.Length == 0),
            Draft.BotToken,
            reason);
    }

    public void AcceptSaved(TelegramSettingsSaveResult result)
    {
        ArgumentNullException.ThrowIfNull(result);
        saved = TelegramSettingsDraft.FromSettings(result.Settings, result.BotToken);
        Draft = TelegramSettingsDraft.FromSettings(result.Settings, result.BotToken);
    }

    public void DiscardChanges() => Draft = TelegramSettingsDraft.FromSettings(
        saved.BuildSettings(saved.Enabled),
        saved.BotToken);

    private bool AvailabilityMatches(TelegramAvailabilityStatus status) =>
        availability.Status == status &&
        availability.Matches(Draft.BotToken, Draft.AdminIds);

    private void RaiseStateChanged()
    {
        OnPropertyChanged(nameof(Draft));
        OnPropertyChanged(nameof(IsDirty));
        OnPropertyChanged(nameof(CredentialsEditable));
        OnPropertyChanged(nameof(CanEnable));
        OnPropertyChanged(nameof(EnableBlockReason));
        OnPropertyChanged(nameof(StatusText));
        OnPropertyChanged(nameof(Enabled));
        OnPropertyChanged(nameof(BotToken));
        OnPropertyChanged(nameof(AdminIdsText));
        OnPropertyChanged(nameof(InventorySpaceLowThresholdText));
        OnPropertyChanged(nameof(NotifyCatch));
        OnPropertyChanged(nameof(NotifyStartStop));
        OnPropertyChanged(nameof(NotifyMeal));
        OnPropertyChanged(nameof(NotifyInventoryFull));
        OnPropertyChanged(nameof(NotifyInventorySpaceLow));
        OnPropertyChanged(nameof(NotifyBaitTired));
        OnPropertyChanged(nameof(NotifyFocusLost));
        SaveCommand.NotifyCanExecuteChanged();
        DiscardCommand.NotifyCanExecuteChanged();
    }

    private void Save()
    {
        if (saveHandler is null)
        {
            throw new InvalidOperationException("telegram_persistence_unavailable");
        }
        var result = BuildSaveResult();
        saveHandler(result);
        AcceptSaved(result);
        InteractionMessage = result.EnableRequestRejected
            ? $"Telegram сохранён выключенным: {result.EnableBlockReason}"
            : string.Empty;
    }
}
