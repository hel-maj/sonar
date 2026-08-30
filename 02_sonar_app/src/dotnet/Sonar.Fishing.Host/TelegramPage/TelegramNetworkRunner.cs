using System.Net.Http;
using Sonar.Fishing.Host.EngineIntegration.Notifications;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StreamingPage;

namespace Sonar.Fishing.Host.TelegramPage;

internal sealed class TelegramNetworkRunner
{
    private readonly Func<TelegramHostSettings> readSettings;
    private readonly Func<TelegramHostSettings, CancellationToken, Task> saveSettings;
    private readonly ITelegramProductUseCases product;
    private readonly IStreamingController streaming;
    private readonly IFishingEngineNotificationSource? notificationSource;
    private readonly Func<HttpMessageHandler>? handlerFactory;

    public TelegramNetworkRunner(
        Func<TelegramHostSettings> readSettings,
        Func<TelegramHostSettings, CancellationToken, Task> saveSettings,
        ITelegramProductUseCases product,
        IStreamingController streaming,
        IFishingEngineNotificationSource? notificationSource = null,
        Func<HttpMessageHandler>? handlerFactory = null)
    {
        this.readSettings = readSettings ?? throw new ArgumentNullException(nameof(readSettings));
        this.saveSettings = saveSettings ?? throw new ArgumentNullException(nameof(saveSettings));
        this.product = product ?? throw new ArgumentNullException(nameof(product));
        this.streaming = streaming ?? throw new ArgumentNullException(nameof(streaming));
        this.notificationSource = notificationSource;
        this.handlerFactory = handlerFactory;
    }

    public Task RunAsync(
        TelegramRuntimeConfiguration configuration,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(configuration);
        return RunCoreAsync(
            configuration,
            new TelegramPollingCursor(),
            static () => { },
            static _ => { },
            cancellationToken);
    }

    public Task RunVerifiedAsync(
        TelegramRuntimeGenerationContext context,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(context);
        return RunCoreAsync(
            context.Configuration,
            context.Cursor,
            context.ReportAvailable,
            context.ReportUnavailable,
            cancellationToken);
    }

    private async Task RunCoreAsync(
        TelegramRuntimeConfiguration configuration,
        TelegramPollingCursor cursor,
        Action reportAvailable,
        Action<TelegramAvailabilityFailure> reportUnavailable,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(configuration);
        ArgumentNullException.ThrowIfNull(cursor);
        ArgumentNullException.ThrowIfNull(reportAvailable);
        ArgumentNullException.ThrowIfNull(reportUnavailable);
        if (!configuration.RuntimeEligible)
        {
            return;
        }
        using var httpClient = handlerFactory is null
            ? new HttpClient()
            : new HttpClient(handlerFactory(), disposeHandler: true);
        httpClient.BaseAddress = new Uri("https://api.telegram.org/");
        httpClient.Timeout = TimeSpan.FromSeconds(35);
        var api = new TelegramBotApiClient(httpClient, configuration.BotToken);
        var dispatcher = new TelegramCommandDispatcher(
            api,
            readSettings,
            saveSettings,
            product,
            streaming);
        var polling = new TelegramPollingService(
            api,
            new TelegramInboundRouter(),
            dispatcher.DispatchAsync,
            cursor,
            reportAvailable,
            reportUnavailable);
        if (notificationSource is null)
        {
            await polling.RunAsync(readSettings, cancellationToken).ConfigureAwait(false);
            return;
        }
        var publisher = new TelegramEngineNotificationPublisher(
            notificationSource,
            readSettings,
            product);
        using var generation = CancellationTokenSource.CreateLinkedTokenSource(
            cancellationToken);
        var pollingTask = polling.RunAsync(readSettings, generation.Token);
        var publisherTask = publisher.RunAsync(api, generation.Token);
        var completed = await Task.WhenAny(pollingTask, publisherTask).ConfigureAwait(false);
        generation.Cancel();
        try
        {
            await completed.ConfigureAwait(false);
        }
        finally
        {
            var sibling = ReferenceEquals(completed, pollingTask)
                ? publisherTask
                : pollingTask;
            try
            {
                await sibling.ConfigureAwait(false);
            }
            catch (OperationCanceledException) when (generation.IsCancellationRequested)
            {
            }
            catch
            {
                // The first completed task owns this generation's outcome.
                // The availability coordinator performs the bounded retry.
            }
        }
    }
}
