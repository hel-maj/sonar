using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.StatisticsPage;

public partial class StatisticsScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(StatisticsPageViewModel),
        typeof(StatisticsScreen),
        new FrameworkPropertyMetadata(null));

    public StatisticsScreen()
    {
        InitializeComponent();
    }

    public StatisticsPageViewModel ViewModel
    {
        get => (StatisticsPageViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
