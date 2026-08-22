using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.IO;
using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.StatisticsPage;

public sealed class StatisticsPageViewModel : ObservableObject
{
    private CurrentSessionStatisticsViewModel current;
    private readonly Action<string, double?>? persistPrice;
    private readonly Func<FishingSessionStateSnapshot>? resetSession;
    private string commandStatus = string.Empty;

    public StatisticsPageViewModel(
        FishingSessionStateSnapshot snapshot,
        Action<string, double?>? persistPrice = null,
        Func<FishingSessionStateSnapshot>? resetSession = null)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        this.persistPrice = persistPrice;
        this.resetSession = resetSession;
        current = CurrentSessionStatisticsViewModel.FromSnapshot(snapshot, TryPersistPrice);
        ResetSessionCommand = new RelayCommand(
            Reset,
            () => this.resetSession is not null && Current.HasCatches);
    }

    public CurrentSessionStatisticsViewModel Current
    {
        get => current;
        private set => SetProperty(ref current, value);
    }

    public string CommandStatus
    {
        get => commandStatus;
        private set => SetProperty(ref commandStatus, value);
    }

    public IRelayCommand ResetSessionCommand { get; }

    public void ApplySessionState(FishingSessionStateSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        Current = CurrentSessionStatisticsViewModel.FromSnapshot(snapshot, TryPersistPrice);
        ResetSessionCommand.NotifyCanExecuteChanged();
    }

    private bool TryPersistPrice(string fishId, double? price)
    {
        if (persistPrice is null)
        {
            return false;
        }
        try
        {
            persistPrice(fishId, price);
            CommandStatus = price is null ? "Своя цена удалена" : "Своя цена сохранена";
            return true;
        }
        catch (Exception exception) when (
            exception is ArgumentException or InvalidDataException or InvalidOperationException)
        {
            CommandStatus = "Не удалось сохранить свою цену";
            return false;
        }
    }

    private void Reset()
    {
        if (resetSession is null)
        {
            throw new InvalidOperationException("session_reset_unavailable");
        }
        ApplySessionState(resetSession());
        CommandStatus = "Начата новая сессия";
    }
}
