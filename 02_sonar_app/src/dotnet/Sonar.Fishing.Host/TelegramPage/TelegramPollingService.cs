using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed class TelegramPollingService
{
    private static readonly TimeSpan RetryDelay = TimeSpan.FromSeconds(2);
    private readonly ITelegramBotApi api;
    private readonly TelegramInboundRouter router;
    private readonly Func<TelegramInboundDecision, CancellationToken, Task> dispatch;
    private int running;

    public TelegramPollingService(
        ITelegramBotApi api,
        TelegramInboundRouter router,
        Func<TelegramInboundDecision, CancellationToken, Task> dispatch)
    {
        ArgumentNullException.ThrowIfNull(api);
        ArgumentNullException.ThrowIfNull(router);
        ArgumentNullException.ThrowIfNull(dispatch);
        this.api = api;
        this.router = router;
        this.dispatch = dispatch;
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
            long? nextOffset = null;
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
                        nextOffset,
                        longPollingTimeoutSeconds: 20,
                        cancellationToken).ConfigureAwait(false);
                    foreach (var update in updates.OrderBy(update => update.UpdateId))
                    {
                        if (nextOffset is { } minimum && update.UpdateId < minimum)
                        {
                            continue;
                        }

                        nextOffset = checked(update.UpdateId + 1);
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
                catch (TelegramBotApiException)
                {
                    await Task.Delay(RetryDelay, cancellationToken).ConfigureAwait(false);
                }
            }
        }
        finally
        {
            Volatile.Write(ref running, 0);
        }
    }
}
