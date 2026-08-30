using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.IO;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.StatisticsPage;

public sealed class StatisticsPageViewModel : ObservableObject
{
    private CurrentSessionStatisticsViewModel current;
    private readonly Action<string, double?>? persistPrice;
    private readonly IFishingSessionStatisticsRuntime? statisticsRuntime;
    private FishingSessionStateSnapshot sessionSnapshot;
    private int resetInFlight;
    private string commandStatus = string.Empty;

    public StatisticsPageViewModel(
        FishingSessionStateSnapshot snapshot,
        Action<string, double?>? persistPrice = null)
        : this(snapshot, persistPrice, statisticsRuntime: null)
    {
    }

    internal StatisticsPageViewModel(
        FishingSessionStateSnapshot snapshot,
        Action<string, double?>? persistPrice,
        IFishingSessionStatisticsRuntime? statisticsRuntime)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        this.persistPrice = persistPrice;
        this.statisticsRuntime = statisticsRuntime;
        sessionSnapshot = snapshot;
        current = CurrentSessionStatisticsViewModel.FromSnapshot(snapshot, TryPersistPrice);
        ResetSessionCommand = new AsyncRelayCommand(
            ResetAsync,
            CanReset);
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

    public IAsyncRelayCommand ResetSessionCommand { get; }

    public void ApplySessionState(FishingSessionStateSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        sessionSnapshot = snapshot;
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

    private bool CanReset() =>
        statisticsRuntime is not null &&
        Volatile.Read(ref resetInFlight) == 0 &&
        HasResettableSessionData(sessionSnapshot);

    private async Task ResetAsync(CancellationToken cancellationToken)
    {
        if (statisticsRuntime is null ||
            !HasResettableSessionData(sessionSnapshot) ||
            Interlocked.CompareExchange(ref resetInFlight, 1, 0) != 0)
        {
            return;
        }
        ResetSessionCommand.NotifyCanExecuteChanged();
        try
        {
            ApplySessionState(await statisticsRuntime.ResetCurrentSessionAsync(
                cancellationToken).ConfigureAwait(true));
            CommandStatus = string.Empty;
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
        }
        catch (Exception exception) when (
            exception is EngineCommandRejectedException or
                InvalidOperationException or IOException)
        {
            CommandStatus = "Не удалось начать новую сессию";
        }
        finally
        {
            Interlocked.Exchange(ref resetInFlight, 0);
            ResetSessionCommand.NotifyCanExecuteChanged();
        }
    }

    private static bool HasResettableSessionData(FishingSessionStateSnapshot snapshot) =>
        snapshot.Totals.DurationSeconds > 0 ||
        snapshot.Totals.CaughtCount > 0 ||
        snapshot.TackleItems.Count > 0 ||
        snapshot.FishRows.Count > 0 ||
        snapshot.CatchSizes.Any(item => item.Count > 0);
}
