using CommunityToolkit.Mvvm.ComponentModel;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.LicensePage;

public sealed class LicensePageViewModel : ObservableObject
{
    private readonly Func<string, CancellationToken, Task<FishingLicenseActivationResult>>? activate;
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
        Func<string, CancellationToken, Task<FishingLicenseActivationResult>>? activate)
    {
        this.activate = activate;
        Apply(settings);
        ActivationMessage = activate is null
            ? "Активация сейчас недоступна."
            : "Введите ключ, чтобы проверить или обновить лицензию.";
        ActivationTone = activate is null ? SemanticTone.Warning : SemanticTone.Info;
    }

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
            : string.Join(", ", settings.Features.Order(StringComparer.Ordinal));
    }
}
