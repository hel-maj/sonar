using CommunityToolkit.Mvvm.ComponentModel;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.LicensePage;

public sealed class LicensePageViewModel : ObservableObject
{
    private static readonly IReadOnlyDictionary<string, string> FeatureLabels =
        new Dictionary<string, string>(StringComparer.Ordinal)
        {
            ["fishing"] = "Рыбалка",
            ["fishing_bot"] = "Автоматическая рыбалка",
            ["fishing_tackle"] = "Снасти",
            ["statistics"] = "Статистика",
            ["stream"] = "Трансляция",
            ["stream_chat"] = "Чат трансляции",
            ["telegram"] = "Telegram",
        };

    private readonly Func<string, CancellationToken, Task<FishingLicenseActivationResult>>? activate;
    private readonly LicensePagePresentation presentation;
    private bool isBusy;
    private string statusText = string.Empty;
    private SemanticTone statusTone;
    private string licenseId = string.Empty;
    private string subscription = string.Empty;
    private string expiresAt = string.Empty;
    private string featureSummary = string.Empty;
    private string activationMessage = string.Empty;
    private SemanticTone activationTone;

    public LicensePageViewModel(LicenseHostSettings settings)
        : this(settings, null)
    {
    }

    internal LicensePageViewModel(
        LicenseHostSettings settings,
        Func<string, CancellationToken, Task<FishingLicenseActivationResult>>? activate,
        LicensePagePresentation presentation = LicensePagePresentation.Standard)
    {
        this.presentation = presentation;
        this.activate = presentation == LicensePagePresentation.LocalAccess
            ? null
            : activate;
        Apply(settings);
        ActivationMessage = presentation == LicensePagePresentation.LocalAccess
            ? string.Empty
            : activate is null
            ? "Активация сейчас недоступна."
            : "Введите ключ, чтобы проверить или обновить лицензию.";
        ActivationTone = presentation == LicensePagePresentation.LocalAccess
            ? SemanticTone.Success
            : activate is null
                ? SemanticTone.Warning
                : SemanticTone.Info;
    }

    public string HeaderSubtitle => presentation == LicensePagePresentation.LocalAccess
        ? "Доступ к функциям приложения открыт."
        : "Активируйте ключ и проверьте доступные функции";

    public bool ShowActivationControls =>
        presentation == LicensePagePresentation.Standard;

    public bool HasValidatedLicense => LicenseId != "-";

    public string StatusText
    {
        get => statusText;
        private set => SetProperty(ref statusText, value);
    }

    public SemanticTone StatusTone
    {
        get => statusTone;
        private set => SetProperty(ref statusTone, value);
    }

    public string LicenseId
    {
        get => licenseId;
        private set
        {
            if (SetProperty(ref licenseId, value))
            {
                OnPropertyChanged(nameof(HasValidatedLicense));
            }
        }
    }

    public string Subscription
    {
        get => subscription;
        private set => SetProperty(ref subscription, value);
    }

    public string ExpiresAt
    {
        get => expiresAt;
        private set => SetProperty(ref expiresAt, value);
    }

    public string FeatureSummary
    {
        get => featureSummary;
        private set => SetProperty(ref featureSummary, value);
    }

    public bool IsBusy
    {
        get => isBusy;
        private set
        {
            if (SetProperty(ref isBusy, value))
            {
                OnPropertyChanged(nameof(CanActivate));
                OnPropertyChanged(nameof(ActivateButtonText));
            }
        }
    }

    public bool CanActivate => activate is not null && !IsBusy;

    public string ActivateButtonText => IsBusy ? "Проверка..." : "Активировать";

    public string ActivationMessage
    {
        get => activationMessage;
        private set => SetProperty(ref activationMessage, value);
    }

    public SemanticTone ActivationTone
    {
        get => activationTone;
        private set => SetProperty(ref activationTone, value);
    }

    internal async Task<bool> ActivateAsync(string licenseKey, CancellationToken cancellationToken)
    {
        if (activate is null || IsBusy)
        {
            return false;
        }
        IsBusy = true;
        ActivationMessage = "Проверяем лицензию...";
        ActivationTone = SemanticTone.Info;
        try
        {
            var result = await activate(licenseKey, cancellationToken).ConfigureAwait(true);
            ActivationMessage = result.Message;
            ActivationTone = result.Accepted ? SemanticTone.Success : SemanticTone.Warning;
            if (result.Accepted && result.Settings is not null)
            {
                Apply(result.Settings);
                return true;
            }
            return false;
        }
        finally
        {
            IsBusy = false;
        }
    }

    internal void ApplyExternalSettings(LicenseHostSettings settings) => Apply(settings);

    private void Apply(LicenseHostSettings settings)
    {
        ArgumentNullException.ThrowIfNull(settings);
        if (presentation == LicensePagePresentation.LocalAccess)
        {
            StatusText = "Локальный доступ";
            StatusTone = SemanticTone.Success;
            LicenseId = "Локальный доступ";
            Subscription = "Доступные функции";
            ExpiresAt = "Без срока";
            FeatureSummary = FriendlyFeatureSummary(settings.Features);
            return;
        }
        var validated = settings.LicenseId.Length != 0;
        StatusText = validated ? "Активна" : "Не активирована";
        StatusTone = validated ? SemanticTone.Success : SemanticTone.Warning;
        LicenseId = validated ? settings.LicenseId : "-";
        Subscription = validated &&
            settings.Group.Length != 0 &&
            !string.Equals(settings.Group, "legacy", StringComparison.OrdinalIgnoreCase)
                ? settings.Group
                : "—";
        ExpiresAt = settings.ExpiresAt.Length == 0 ? "—" : settings.ExpiresAt;
        FeatureSummary = settings.Features.Count == 0
            ? "Функции ещё не подтверждены"
            : FriendlyFeatureSummary(settings.Features);
    }

    private static string FriendlyFeatureSummary(IReadOnlyList<string> features)
    {
        var labels = features
            .Distinct(StringComparer.Ordinal)
            .Select(feature => FeatureLabels.GetValueOrDefault(feature))
            .OfType<string>()
            .Order(StringComparer.CurrentCulture)
            .ToArray();
        return labels.Length == 0
            ? "Доступ подтверждён"
            : string.Join(", ", labels);
    }
}

internal enum LicensePagePresentation
{
    Standard,
    LocalAccess,
}
