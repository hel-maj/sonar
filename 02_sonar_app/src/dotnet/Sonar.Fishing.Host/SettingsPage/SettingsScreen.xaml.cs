using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.SettingsPage;

public partial class SettingsScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(FishingSettingsPageViewModel),
        typeof(SettingsScreen),
        new FrameworkPropertyMetadata(null));

    public SettingsScreen()
    {
        InitializeComponent();
    }

    public FishingSettingsPageViewModel ViewModel
    {
        get => (FishingSettingsPageViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
