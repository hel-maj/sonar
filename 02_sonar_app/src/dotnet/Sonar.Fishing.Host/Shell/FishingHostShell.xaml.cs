using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.Shell;

public partial class FishingHostShell : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(FishingHostShellViewModel),
        typeof(FishingHostShell),
        new FrameworkPropertyMetadata(null));

    public FishingHostShell()
    {
        InitializeComponent();
        SetCurrentValue(ViewModelProperty, FishingHostShellViewModel.CreatePreview());
    }

    public FishingHostShellViewModel ViewModel
    {
        get => (FishingHostShellViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
