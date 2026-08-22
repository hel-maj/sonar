using System.Net.Http;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StreamingPage;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed class TelegramNetworkRunner
{
    private readonly Func<TelegramHostSettings> readSettings;
    private readonly Func<TelegramHostSettings, CancellationToken, Task> saveSettings;
    private readonly ITelegramProductUseCases product;
    private readonly IStreamingController streaming;
    private readonly Func<HttpMessageHandler>? handlerFactory;

    public TelegramNetworkRunner(
        Func<TelegramHostSettings> readSettings,
        Func<TelegramHostSettings, CancellationToken, Task> saveSettings,
        ITelegramProductUseCases product,
        IStreamingController streaming,
        Func<HttpMessageHandler>? handlerFactory = null)
    {
        this.readSettings = readSettings ?? throw new ArgumentNullException(nameof(readSettings));
        this.saveSettings = saveSettings ?? throw new ArgumentNullException(nameof(saveSettings));
        this.product = product ?? throw new ArgumentNullException(nameof(product));
        this.streaming = streaming ?? throw new ArgumentNullException(nameof(streaming));
        this.handlerFactory = handlerFactory;
    }

    public async Task RunAsync(
        TelegramRuntimeConfiguration configuration,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(configuration);
        if (!configuration.Eligible)
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
            dispatcher.DispatchAsync);
        await polling.RunAsync(readSettings, cancellationToken).ConfigureAwait(false);
    }
}
