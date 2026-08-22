using System.IO;
using System.Reflection;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace Sonar.Fishing.Host.AboutPage;

public sealed class AboutPageViewModel : ObservableObject
{
    private readonly Action? clearDiagnostics;
    private string diagnosticsStatus;

    public AboutPageViewModel(Action? clearDiagnostics = null)
    {
        this.clearDiagnostics = clearDiagnostics;
        var assembly = typeof(AboutPageViewModel).Assembly;
        Version = assembly.GetName().Version?.ToString(3) ?? "0.0.0";
        Build = assembly.GetCustomAttribute<AssemblyInformationalVersionAttribute>()?.InformationalVersion
            ?? Version;
        diagnosticsStatus = clearDiagnostics is null
            ? "Журнал недоступен"
            : "При обращении в поддержку приложите журнал";
        ClearDiagnosticsCommand = new RelayCommand(ClearDiagnostics, () => CanClearDiagnostics);
    }

    public string Version { get; }

    public string Build { get; }

    public string Subscription => "Определяется лицензией";

    public string UpdateStatus => "Проверка обновлений недоступна";

    public bool CanDownloadUpdate => false;

    public bool CanClearDiagnostics => clearDiagnostics is not null;

    public string DiagnosticsStatus
    {
        get => diagnosticsStatus;
        private set => SetProperty(ref diagnosticsStatus, value);
    }

    public IRelayCommand ClearDiagnosticsCommand { get; }

    private void ClearDiagnostics()
    {
        if (clearDiagnostics is null)
        {
            return;
        }
        try
        {
            clearDiagnostics();
            DiagnosticsStatus = "Журнал очищен";
        }
        catch (Exception exception) when (
            exception is IOException or UnauthorizedAccessException or ObjectDisposedException)
        {
            DiagnosticsStatus = "Не удалось очистить журнал";
        }
    }
}
