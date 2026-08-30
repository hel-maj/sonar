using System.Net.Http;

namespace Sonar.Fishing.Host.TelegramPage;

public interface ITelegramAvailabilityProbe
{
    Task<TelegramAvailabilityProbeResult> ProbeAsync(
        TelegramAvailabilityCandidate candidate,
        CancellationToken cancellationToken);
}

public sealed class TelegramAvailabilityProbe : ITelegramAvailabilityProbe
{
    private readonly Func<HttpMessageHandler>? handlerFactory;
    private readonly Uri baseAddress;

    public TelegramAvailabilityProbe(
        Func<HttpMessageHandler>? handlerFactory = null,
        Uri? baseAddress = null)
    {
        this.handlerFactory = handlerFactory;
        this.baseAddress = baseAddress ?? new Uri("https://api.telegram.org/");
        if (!string.Equals(
                this.baseAddress.Scheme,
                Uri.UriSchemeHttps,
                StringComparison.OrdinalIgnoreCase))
        {
            throw new ArgumentException("telegram_https_base_required", nameof(baseAddress));
        }
    }

    public async Task<TelegramAvailabilityProbeResult> ProbeAsync(
        TelegramAvailabilityCandidate candidate,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(candidate);
        if (!candidate.ConfigurationReady)
        {
            return TelegramAvailabilityProbeResult.Failed(
                TelegramAvailabilityFailure.CredentialsRejected);
        }

        using var httpClient = handlerFactory is null
            ? new HttpClient()
            : new HttpClient(handlerFactory(), disposeHandler: true);
        httpClient.BaseAddress = baseAddress;
        httpClient.Timeout = Timeout.InfiniteTimeSpan;
        try
        {
            var api = new TelegramBotApiClient(httpClient, candidate.BotToken);
            _ = await api.GetMeAsync(cancellationToken).ConfigureAwait(false);
            return TelegramAvailabilityProbeResult.Success;
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (TelegramBotApiException exception)
        {
            return TelegramAvailabilityProbeResult.Failed(Classify(exception));
        }
        catch (ArgumentException)
        {
            return TelegramAvailabilityProbeResult.Failed(
                TelegramAvailabilityFailure.CredentialsRejected);
        }
    }

    internal static TelegramAvailabilityFailure Classify(
        TelegramBotApiException exception)
    {
        ArgumentNullException.ThrowIfNull(exception);
        if (exception.StatusCode == 401 || exception.ApiErrorCode == 401)
        {
            return TelegramAvailabilityFailure.CredentialsRejected;
        }
        return exception.Reason switch
        {
            "telegram_bot_identity_invalid" or
            "telegram_response_invalid" or
            "telegram_result_missing" => TelegramAvailabilityFailure.InvalidResponse,
            _ => TelegramAvailabilityFailure.NetworkUnavailable,
        };
    }
}
