using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.Overview;

public partial class OverviewScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(OverviewPageViewModel),
        typeof(OverviewScreen),
        new FrameworkPropertyMetadata(null));

    public OverviewScreen()
    {
        InitializeComponent();
    }

    public OverviewPageViewModel ViewModel
    {
        get => (OverviewPageViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
