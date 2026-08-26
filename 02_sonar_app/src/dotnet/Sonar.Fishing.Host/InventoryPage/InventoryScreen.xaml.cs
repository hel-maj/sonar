using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.InventoryPage;

public partial class InventoryScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(InventoryPageViewModel),
        typeof(InventoryScreen),
        new FrameworkPropertyMetadata(null));

    public InventoryScreen()
    {
        InitializeComponent();
    }

    public InventoryPageViewModel ViewModel
    {
        get => (InventoryPageViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }
}
