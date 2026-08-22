using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.EngineHealth;

public partial class EngineHealthScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(EngineHealthViewModel),
        typeof(EngineHealthScreen),
        new FrameworkPropertyMetadata(EngineHealthViewModel.CreateDemo()));

    public EngineHealthScreen()
    {
        InitializeComponent();
    }

    public EngineHealthViewModel ViewModel
    {
        get => (EngineHealthViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
