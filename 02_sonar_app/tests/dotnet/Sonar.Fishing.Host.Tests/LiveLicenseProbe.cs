using System.IO;
using System.Net;
using System.Net.Http;
using System.Text.Json;
using Sonar.Fishing.Host.Licensing;

namespace Sonar.Fishing.Host.Tests;

internal static class LiveLicenseProbe
{
    internal static int Run(string configPath)
    {
        try
        {
            var fullPath = Path.GetFullPath(configPath);
            using var document = JsonDocument.Parse(File.ReadAllBytes(fullPath));
            var key = document.RootElement.GetProperty("license_key").GetString();
            if (string.IsNullOrWhiteSpace(key))
            {
                Console.Error.WriteLine("live_license_probe_key_missing");
                return 2;
            }
            using var handler = new SocketsHttpHandler
            {
                AllowAutoRedirect = false,
                AutomaticDecompression = DecompressionMethods.None,
                UseCookies = false,
                ConnectTimeout = TimeSpan.FromSeconds(5),
            };
            using var httpClient = new HttpClient(handler)
            {
                Timeout = Timeout.InfiniteTimeSpan,
            };
            var service = new FishingLicenseActivationService(
                new KeygenLicenseApiClient(httpClient),
                WindowsMachineFingerprint.Current());
            var result = service.ActivateOrRefreshAsync(
                key,
                0,
                CancellationToken.None).GetAwaiter().GetResult();
            Console.WriteLine($"accepted={result.Accepted.ToString().ToLowerInvariant()}");
            Console.WriteLine($"message={result.Message}");
            Console.WriteLine($"signed_envelope_verified={result.Accepted || result.Message == "Срок действия лицензии истёк."}");
            return result.Accepted || result.Message == "Срок действия лицензии истёк." ? 0 : 1;
        }
        catch (Exception exception) when (
            exception is IOException or UnauthorizedAccessException or JsonException or
            FishingLicenseTransportException or InvalidOperationException)
        {
            Console.Error.WriteLine($"live_license_probe_failed:{exception.Message}");
            return 1;
        }
    }
}
