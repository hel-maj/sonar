using System.Globalization;
using System.IO;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Text.Json;

namespace Sonar.Fishing.Host.StartupGate;

public sealed class StartupBlockHttpClient : IStartupBlockCheck
{
    public static readonly TimeSpan DefaultTimeout = TimeSpan.FromSeconds(4);
    private readonly HttpClient httpClient;
    private readonly Uri endpoint;
    private readonly StartupBlockResponseVerifier verifier;
    private readonly TimeSpan timeout;

    public StartupBlockHttpClient(
        HttpClient httpClient,
        Uri endpoint,
        StartupBlockResponseVerifier verifier,
        TimeSpan? timeout = null)
    {
        this.httpClient = httpClient ?? throw new ArgumentNullException(nameof(httpClient));
        this.endpoint = RequireHttpsEndpoint(endpoint);
        this.verifier = verifier ?? throw new ArgumentNullException(nameof(verifier));
        this.timeout = timeout ?? DefaultTimeout;
        if (this.timeout <= TimeSpan.Zero || this.timeout > TimeSpan.FromSeconds(30))
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }
    }

    public async Task<StartupBlockStatus> CheckAsync(
        StartupBlockRequest request,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(request);
        using var timeoutSource = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
        timeoutSource.CancelAfter(timeout);
        var requestBytes = JsonSerializer.SerializeToUtf8Bytes(new
        {
            app_name = request.AppName,
            build_hash = request.BuildHash,
            build_key = request.BuildKey,
            license_key = request.LicenseKey,
        });
        using var requestContent = new ByteArrayContent(requestBytes);
        requestContent.Headers.ContentType = new MediaTypeHeaderValue("application/json");
        using var httpRequest = new HttpRequestMessage(HttpMethod.Post, endpoint)
        {
            Content = requestContent,
        };
        httpRequest.Headers.Accept.ParseAdd("application/json");
        httpRequest.Headers.CacheControl = new System.Net.Http.Headers.CacheControlHeaderValue
        {
            NoStore = true,
        };
        httpRequest.Headers.TryAddWithoutValidation(
            "User-Agent",
            $"{AsciiHeaderToken(request.AppName)}/1.0 " +
            $"SonarStartupBlock/{AsciiHeaderToken(request.BuildHash, "dev")}");
        AddAsciiHeader(httpRequest, "X-Sonar-Build-Hash", request.BuildHash);
        AddAsciiHeader(httpRequest, "X-Sonar-Build-Key", request.BuildKey);

        try
        {
            using var response = await httpClient.SendAsync(
                httpRequest,
                HttpCompletionOption.ResponseHeadersRead,
                timeoutSource.Token).ConfigureAwait(false);
            if (!response.IsSuccessStatusCode)
            {
                return StartupBlockStatus.Failure("startup_block_http_rejected");
            }
            if (response.Content.Headers.ContentLength is > StartupBlockResponseVerifier.MaximumResponseBytes)
            {
                return StartupBlockStatus.Failure("startup_block_response_size_invalid");
            }
            await using var stream = await response.Content.ReadAsStreamAsync(
                timeoutSource.Token).ConfigureAwait(false);
            using var buffer = new MemoryStream();
            var scratch = new byte[4096];
            while (true)
            {
                var read = await stream.ReadAsync(scratch, timeoutSource.Token).ConfigureAwait(false);
                if (read == 0)
                {
                    break;
                }
                if (buffer.Length + read > StartupBlockResponseVerifier.MaximumResponseBytes)
                {
                    return StartupBlockStatus.Failure("startup_block_response_size_invalid");
                }
                buffer.Write(scratch, 0, read);
            }
            return verifier.Verify(buffer.ToArray());
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (OperationCanceledException)
        {
            return StartupBlockStatus.Failure("startup_block_timeout");
        }
        catch (HttpRequestException)
        {
            return StartupBlockStatus.Failure("startup_block_http_unavailable");
        }
    }

    private static Uri RequireHttpsEndpoint(Uri endpoint)
    {
        ArgumentNullException.ThrowIfNull(endpoint);
        if (!endpoint.IsAbsoluteUri ||
            !string.Equals(endpoint.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase) ||
            !string.IsNullOrEmpty(endpoint.UserInfo))
        {
            throw new ArgumentException("startup_block_endpoint_invalid", nameof(endpoint));
        }
        return endpoint;
    }

    private static void AddAsciiHeader(
        HttpRequestMessage request,
        string name,
        string value)
    {
        if (value.Any(character => character is < ' ' or > '~'))
        {
            throw new ArgumentException("startup_block_header_value_invalid", nameof(value));
        }
        request.Headers.TryAddWithoutValidation(name, value);
    }

    private static string AsciiHeaderToken(string value, string fallback = "Sonar")
    {
        var normalized = value.Trim().Normalize(NormalizationForm.FormKD);
        var result = new string(normalized
            .Where(character =>
                character is >= ' ' and <= '~' &&
                CharUnicodeInfo.GetUnicodeCategory(character) != UnicodeCategory.NonSpacingMark)
            .ToArray());
        result = string.Join(' ', result.Split((char[]?)null, StringSplitOptions.RemoveEmptyEntries));
        return result.Length == 0 ? fallback : result;
    }
}
