using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed class TelegramPollingCursor
{
    private readonly object gate = new();
    private long? nextOffset;

    public long? NextOffset
    {
        get
        {
            lock (gate)
            {
                return nextOffset;
            }
        }
    }

    public bool TryAdvance(long updateId)
    {
        if (updateId <= 0)
        {
            throw new ArgumentOutOfRangeException(nameof(updateId));
        }
        lock (gate)
        {
            if (nextOffset is { } minimum && updateId < minimum)
            {
                return false;
            }
            nextOffset = checked(updateId + 1);
            return true;
        }
    }
}

public sealed class TelegramPollingService
{
    private static readonly TimeSpan RetryDelay = TimeSpan.FromSeconds(2);
    private readonly ITelegramBotApi api;
    private readonly TelegramInboundRouter router;
    private readonly Func<TelegramInboundDecision, CancellationToken, Task> dispatch;
    private readonly TelegramPollingCursor cursor;
    private readonly Action? reportAvailable;
    private readonly Action<TelegramAvailabilityFailure>? reportUnavailable;
    private readonly TimeSpan retryDelay;
    private int running;

    public TelegramPollingService(
        ITelegramBotApi api,
        TelegramInboundRouter router,
        Func<TelegramInboundDecision, CancellationToken, Task> dispatch,
        TelegramPollingCursor? cursor = null,
        Action? reportAvailable = null,
        Action<TelegramAvailabilityFailure>? reportUnavailable = null,
        TimeSpan? retryDelay = null)
    {
        ArgumentNullException.ThrowIfNull(api);
        ArgumentNullException.ThrowIfNull(router);
        ArgumentNullException.ThrowIfNull(dispatch);
        this.api = api;
        this.router = router;
        this.dispatch = dispatch;
        this.cursor = cursor ?? new TelegramPollingCursor();
        this.reportAvailable = reportAvailable;
        this.reportUnavailable = reportUnavailable;
        this.retryDelay = retryDelay ?? RetryDelay;
        if (this.retryDelay <= TimeSpan.Zero || this.retryDelay == Timeout.InfiniteTimeSpan)
        {
            throw new ArgumentOutOfRangeException(nameof(retryDelay));
        }
    }

    public async Task RunAsync(
        TelegramHostSettings settings,
        CancellationToken cancellationToken) => await RunAsync(
            () => settings,
            cancellationToken).ConfigureAwait(false);

    public async Task RunAsync(
        Func<TelegramHostSettings> readSettings,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(readSettings);
        var initialSettings = readSettings();
        ArgumentNullException.ThrowIfNull(initialSettings);
        if (!initialSettings.Enabled || initialSettings.AdminIds.Count == 0)
        {
            return;
        }
        if (Interlocked.CompareExchange(ref running, 1, 0) != 0)
        {
            throw new InvalidOperationException("telegram_polling_already_running");
        }

        try
        {
            while (true)
            {
                cancellationToken.ThrowIfCancellationRequested();
                var settings = readSettings();
                ArgumentNullException.ThrowIfNull(settings);
                if (!settings.Enabled || settings.AdminIds.Count == 0)
                {
                    return;
                }
                try
                {
                    var updates = await api.GetUpdatesAsync(
                        cursor.NextOffset,
                        longPollingTimeoutSeconds: 20,
                        cancellationToken).ConfigureAwait(false);
                    reportAvailable?.Invoke();
                    foreach (var update in updates.OrderBy(update => update.UpdateId))
                    {
                        if (!cursor.TryAdvance(update.UpdateId))
                        {
                            continue;
                        }
                        var decision = router.RouteJson(
                            update.Utf8Json.Span,
                            runtimeEnabled: true,
                            settings);
                        if (decision.RequiresCallbackAnswer)
                        {
                            await api.AnswerCallbackQueryAsync(
                                decision.CallbackId,
                                cancellationToken).ConfigureAwait(false);
                        }
                        if (decision.Kind is not TelegramInboundIntentKind.Ignore and
                            not TelegramInboundIntentKind.AcknowledgeOnly)
                        {
                            await dispatch(decision, cancellationToken).ConfigureAwait(false);
                        }
                    }
                }
                catch (TelegramBotApiException exception)
                {
                    reportUnavailable?.Invoke(TelegramAvailabilityProbe.Classify(exception));
                    await Task.Delay(retryDelay, cancellationToken).ConfigureAwait(false);
                }
            }
        }
        finally
        {
            Volatile.Write(ref running, 0);
        }
    }
}
