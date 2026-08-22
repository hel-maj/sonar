using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.StartupGate;

public partial class StartupAdmissionScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(StartupAdmissionViewModel),
        typeof(StartupAdmissionScreen),
        new FrameworkPropertyMetadata(null));

    public StartupAdmissionScreen()
    {
        InitializeComponent();
    }

    public StartupAdmissionViewModel ViewModel
    {
        get => (StartupAdmissionViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
