using System.Windows;

namespace Sonar.Fishing.Host.StartupGate;

public partial class StartupAdmissionWindow : Window
{
    public StartupAdmissionWindow(StartupAdmissionViewModel viewModel)
    {
        DataContext = viewModel ?? throw new ArgumentNullException(nameof(viewModel));
        InitializeComponent();
    }
}
