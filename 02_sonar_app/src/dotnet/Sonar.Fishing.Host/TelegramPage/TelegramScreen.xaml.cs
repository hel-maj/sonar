using System.Windows;
using System.Windows.Controls;

namespace Sonar.Fishing.Host.TelegramPage;

public partial class TelegramScreen : UserControl
{
    public static readonly DependencyProperty ViewModelProperty = DependencyProperty.Register(
        nameof(ViewModel),
        typeof(TelegramSettingsPageViewModel),
        typeof(TelegramScreen),
        new FrameworkPropertyMetadata(null, OnViewModelChanged));

    private bool synchronizingPassword;

    public TelegramScreen()
    {
        InitializeComponent();
    }

    public TelegramSettingsPageViewModel ViewModel
    {
        get => (TelegramSettingsPageViewModel)GetValue(ViewModelProperty);
        set => SetValue(ViewModelProperty, value);
    }

    private static void OnViewModelChanged(
        DependencyObject dependencyObject,
        DependencyPropertyChangedEventArgs eventArgs)
    {
        var screen = (TelegramScreen)dependencyObject;
        screen.SynchronizePassword(eventArgs.NewValue as TelegramSettingsPageViewModel);
    }

    private void SynchronizePassword(TelegramSettingsPageViewModel? viewModel)
    {
        if (BotTokenEditor is null || viewModel is null ||
            string.Equals(BotTokenEditor.Password, viewModel.BotToken, StringComparison.Ordinal))
        {
            return;
        }
        synchronizingPassword = true;
        try
        {
            BotTokenEditor.Password = viewModel.BotToken;
        }
        finally
        {
            synchronizingPassword = false;
        }
    }

    private void OnBotTokenChanged(object sender, RoutedEventArgs eventArgs)
    {
        if (!synchronizingPassword && ViewModel is not null)
        {
            ViewModel.BotToken = BotTokenEditor.Password;
        }
    }
}
