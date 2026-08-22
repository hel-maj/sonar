using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.AboutPage;

public partial class AboutScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(AboutPageViewModel),
        typeof(AboutScreen),
        new FrameworkPropertyMetadata(null));

    public AboutScreen()
    {
        InitializeComponent();
    }

    public AboutPageViewModel ViewModel
    {
        get => (AboutPageViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
