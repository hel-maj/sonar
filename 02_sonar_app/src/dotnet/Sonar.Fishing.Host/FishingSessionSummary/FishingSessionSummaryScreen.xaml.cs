using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.FishingSessionSummary;

public partial class FishingSessionSummaryScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(FishingSessionSummaryViewModel),
        typeof(FishingSessionSummaryScreen),
        new FrameworkPropertyMetadata(
            FishingSessionSummaryViewModel.FromSnapshot(FishingSessionSummarySnapshot.Empty)));

    public FishingSessionSummaryScreen()
    {
        InitializeComponent();
    }

    public FishingSessionSummaryViewModel ViewModel
    {
        get => (FishingSessionSummaryViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
