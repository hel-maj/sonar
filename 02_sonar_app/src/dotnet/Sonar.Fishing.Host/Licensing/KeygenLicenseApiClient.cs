using System.IO;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Net.Http.Json;
using System.Runtime.InteropServices;

namespace Sonar.Fishing.Host.Licensing;

internal sealed class FishingLicenseTransportException : Exception
{
    internal FishingLicenseTransportException(string reason)
        : base(reason)
    {
    }
}

internal interface IKeygenLicenseApi
{
    Task<FishingSignedEntitlementEnvelope> ValidateAsync(
        string licenseKey,
        string machineFingerprint,
        CancellationToken cancellationToken);

    Task ActivateMachineAsync(
        string licenseKey,
        string licenseId,
        string machineFingerprint,
        CancellationToken cancellationToken);
}

internal sealed class KeygenLicenseApiClient : IKeygenLicenseApi
{
    private const int MaximumResponseBytes = 256 * 1024;
    private static readonly Uri ValidationEndpoint = new(
        $"https://{FishingProductionEntitlementPolicy.KeygenHost}" +
        FishingProductionEntitlementPolicy.KeygenValidationTarget);
    private static readonly Uri MachineEndpoint = new(
        $"https://{FishingProductionEntitlementPolicy.KeygenHost}/v1/machines");

    private readonly HttpClient httpClient;
    private readonly TimeSpan timeout;

    internal KeygenLicenseApiClient(HttpClient httpClient, TimeSpan? timeout = null)
    {
        this.httpClient = httpClient ?? throw new ArgumentNullException(nameof(httpClient));
        this.timeout = timeout ?? TimeSpan.FromSeconds(8);
        if (this.timeout <= TimeSpan.Zero || this.timeout > TimeSpan.FromSeconds(30))
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }
    }

    public async Task<FishingSignedEntitlementEnvelope> ValidateAsync(
        string licenseKey,
        string machineFingerprint,
        CancellationToken cancellationToken)
    {
        ValidateKey(licenseKey);
        ValidateFingerprint(machineFingerprint);
        using var request = JsonRequest(
            ValidationEndpoint,
            new
            {
                meta = new
                {
                    key = licenseKey,
                    scope = new { fingerprint = machineFingerprint },
                },
            });
        using var response = await SendAsync(request, cancellationToken).ConfigureAwait(false);
        if ((int)response.StatusCode != 200)
        {
            throw new FishingLicenseTransportException("license_validation_http_rejected");
        }
        RequireExactFinalUri(response, ValidationEndpoint);
        var rawBody = await ReadBoundedAsync(response.Content, cancellationToken).ConfigureAwait(false);
        return new FishingSignedEntitlementEnvelope(
            "post",
            FishingProductionEntitlementPolicy.KeygenValidationTarget,
            FishingProductionEntitlementPolicy.KeygenHost,
            RequireSingleHeader(response, "Date", 64),
            RequireSingleHeader(response, "Digest", 128),
            RequireSingleHeader(response, "Keygen-Signature", 2048),
            rawBody);
    }

    public async Task ActivateMachineAsync(
        string licenseKey,
        string licenseId,
        string machineFingerprint,
        CancellationToken cancellationToken)
    {
        ValidateKey(licenseKey);
        ValidateFingerprint(machineFingerprint);
        if (string.IsNullOrWhiteSpace(licenseId) || licenseId.Length > 128)
        {
            throw new ArgumentException("license_id_invalid", nameof(licenseId));
        }
        using var request = JsonRequest(
            MachineEndpoint,
            new
            {
                data = new
                {
                    type = "machines",
                    attributes = new
                    {
                        fingerprint = machineFingerprint,
                        name = BoundedMachineName(),
                        platform = BoundedPlatformName(),
                    },
                    relationships = new
                    {
                        license = new
                        {
                            data = new
                            {
                                type = "licenses",
                                id = licenseId,
                            },
                        },
                    },
                },
            });
        request.Headers.Authorization = new AuthenticationHeaderValue("License", licenseKey);
        using var response = await SendAsync(request, cancellationToken).ConfigureAwait(false);
        RequireExactFinalUri(response, MachineEndpoint);
        _ = await ReadBoundedAsync(response.Content, cancellationToken).ConfigureAwait(false);
        if ((int)response.StatusCode is not (200 or 201))
        {
            throw new FishingLicenseTransportException("license_activation_rejected");
        }
    }

    private async Task<HttpResponseMessage> SendAsync(
        HttpRequestMessage request,
        CancellationToken cancellationToken)
    {
        using var timeoutSource = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
        timeoutSource.CancelAfter(timeout);
        try
        {
            return await httpClient.SendAsync(
                request,
                HttpCompletionOption.ResponseHeadersRead,
                timeoutSource.Token).ConfigureAwait(false);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (OperationCanceledException)
        {
            throw new FishingLicenseTransportException("license_http_timeout");
        }
        catch (HttpRequestException)
        {
            throw new FishingLicenseTransportException("license_http_unavailable");
        }
    }

    private static HttpRequestMessage JsonRequest(Uri endpoint, object body)
    {
        var request = new HttpRequestMessage(HttpMethod.Post, endpoint)
        {
            Content = JsonContent.Create(body),
        };
        request.Headers.Accept.Add(new MediaTypeWithQualityHeaderValue("application/vnd.api+json"));
        request.Headers.CacheControl = new CacheControlHeaderValue { NoStore = true };
        request.Headers.TryAddWithoutValidation(
            "Keygen-Accept-Signature",
            "algorithm=\"rsa-sha256\"");
        request.Headers.TryAddWithoutValidation(
            "User-Agent",
            "Sonar-Fishing/1.0 NativeMigration/1");
        return request;
    }

    private static async Task<byte[]> ReadBoundedAsync(
        HttpContent content,
        CancellationToken cancellationToken)
    {
        if (content.Headers.ContentLength is < 0 or > MaximumResponseBytes)
        {
            throw new FishingLicenseTransportException("license_response_size_invalid");
        }
        await using var stream = await content.ReadAsStreamAsync(cancellationToken).ConfigureAwait(false);
        using var buffer = new MemoryStream();
        var scratch = new byte[8192];
        while (true)
        {
            var read = await stream.ReadAsync(scratch, cancellationToken).ConfigureAwait(false);
            if (read == 0)
            {
                return buffer.ToArray();
            }
            if (buffer.Length + read > MaximumResponseBytes)
            {
                throw new FishingLicenseTransportException("license_response_size_invalid");
            }
            buffer.Write(scratch, 0, read);
        }
    }

    private static string RequireSingleHeader(
        HttpResponseMessage response,
        string name,
        int maximumLength)
    {
        if (!response.Headers.TryGetValues(name, out var values))
        {
            throw new FishingLicenseTransportException("license_signature_headers_missing");
        }
        var materialized = values.ToArray();
        if (materialized.Length != 1 ||
            string.IsNullOrWhiteSpace(materialized[0]) ||
            materialized[0].Length > maximumLength ||
            materialized[0].Any(character => character is '\r' or '\n'))
        {
            throw new FishingLicenseTransportException("license_signature_headers_invalid");
        }
        return materialized[0];
    }

    private static void RequireExactFinalUri(HttpResponseMessage response, Uri expected)
    {
        var actual = response.RequestMessage?.RequestUri;
        if (actual is null || !string.Equals(actual.AbsoluteUri, expected.AbsoluteUri, StringComparison.Ordinal))
        {
            throw new FishingLicenseTransportException("license_redirect_rejected");
        }
    }

    private static void ValidateKey(string licenseKey)
    {
        if (string.IsNullOrWhiteSpace(licenseKey) ||
            licenseKey.Length > 256 ||
            licenseKey.Any(character =>
                character > 0x7f ||
                !(char.IsLetterOrDigit(character) || character is '-' or '_' or '.' or '/')))
        {
            throw new ArgumentException("license_key_invalid", nameof(licenseKey));
        }
    }

    private static void ValidateFingerprint(string machineFingerprint)
    {
        if (string.IsNullOrWhiteSpace(machineFingerprint) ||
            machineFingerprint.Length > 256 ||
            machineFingerprint.Any(character =>
                character > 0x7f ||
                !(char.IsLetterOrDigit(character) || character is '-' or '_')))
        {
            throw new ArgumentException("license_fingerprint_invalid", nameof(machineFingerprint));
        }
    }

    private static string BoundedMachineName()
    {
        var value = Environment.MachineName.Trim();
        return value.Length == 0 ? "Windows PC" : value[..Math.Min(value.Length, 128)];
    }

    private static string BoundedPlatformName()
    {
        var value = RuntimeInformation.OSDescription.Trim();
        return value.Length == 0 ? "Windows" : value[..Math.Min(value.Length, 128)];
    }
}
