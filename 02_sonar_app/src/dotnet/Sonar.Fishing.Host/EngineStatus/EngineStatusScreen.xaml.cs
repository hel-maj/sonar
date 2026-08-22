using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Sonar.Fishing.Host.EngineStatus;

public partial class EngineStatusScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(EngineStatusViewModel),
        typeof(EngineStatusScreen),
        new FrameworkPropertyMetadata(
            EngineStatusViewModel.FromSnapshot(EngineSessionSnapshot.InertReady)));

    public static readonly DependencyProperty StartCommandProperty = DependencyProperty.Register(
        nameof(StartCommand),
        typeof(ICommand),
        typeof(EngineStatusScreen));

    public static readonly DependencyProperty StopCommandProperty = DependencyProperty.Register(
        nameof(StopCommand),
        typeof(ICommand),
        typeof(EngineStatusScreen));

    public EngineStatusScreen()
    {
        InitializeComponent();
    }

    public EngineStatusViewModel ViewModel
    {
        get => (EngineStatusViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }

    public ICommand? StartCommand
    {
        get => (ICommand?)GetValue(StartCommandProperty);
        set => SetValue(StartCommandProperty, value);
    }

    public ICommand? StopCommand
    {
        get => (ICommand?)GetValue(StopCommandProperty);
        set => SetValue(StopCommandProperty, value);
    }
}
