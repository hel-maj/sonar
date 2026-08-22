using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.FishingPage;

public partial class FishingPage : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(FishingPageViewModel),
        typeof(FishingPage),
        new FrameworkPropertyMetadata(FishingPageViewModel.MigrationPreview));

    public FishingPage()
    {
        InitializeComponent();
    }

    public FishingPageViewModel ViewModel
    {
        get => (FishingPageViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
