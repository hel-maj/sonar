using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.LicensePage;

public partial class LicenseScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(LicensePageViewModel),
        typeof(LicenseScreen),
        new FrameworkPropertyMetadata(null));

    public LicenseScreen()
    {
        InitializeComponent();
    }

    public LicensePageViewModel ViewModel
    {
        get => (LicensePageViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }

    private async void OnActivateLicense(object sender, RoutedEventArgs e)
    {
        if (ViewModel is null)
        {
            return;
        }
        var accepted = await ViewModel.ActivateAsync(
            LicenseKeyEditor.Password,
            CancellationToken.None).ConfigureAwait(true);
        if (accepted)
        {
            LicenseKeyEditor.Clear();
        }
    }
}
