using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.StreamingPage;

public partial class StreamingScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(StreamingPageViewModel),
        typeof(StreamingScreen),
        new FrameworkPropertyMetadata(null));

    public StreamingScreen()
    {
        InitializeComponent();
    }

    public StreamingPageViewModel ViewModel
    {
        get => (StreamingPageViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
