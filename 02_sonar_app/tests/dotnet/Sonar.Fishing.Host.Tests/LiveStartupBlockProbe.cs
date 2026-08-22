using System.Net;
using System.Net.Http;
using Sonar.Fishing.Host.StartupGate;

namespace Sonar.Fishing.Host.Tests;

internal static class LiveStartupBlockProbe
{
    internal static int Run()
    {
        using var handler = new SocketsHttpHandler
        {
            AllowAutoRedirect = false,
            AutomaticDecompression = DecompressionMethods.None,
            UseCookies = false,
            ConnectTimeout = TimeSpan.FromSeconds(5),
        };
        using var statusCapture = new StatusCaptureHandler(handler);
        using var httpClient = new HttpClient(statusCapture)
        {
            Timeout = Timeout.InfiniteTimeSpan,
        };
        var request = FishingProductionStartupPolicy.CreateRequest(
            Environment.ProcessPath,
            string.Empty);
        var status = FishingProductionStartupPolicy.CreateClient(httpClient)
            .CheckAsync(request, CancellationToken.None)
            .GetAwaiter().GetResult();
        if (!status.Checked || status.Error.Length != 0)
        {
            Console.Error.WriteLine(
                $"Production startup admission failed: {status.Error}; " +
                $"http={(int?)statusCapture.LastStatusCode ?? 0}; " +
                $"response={statusCapture.ResponseSummary}");
            return 1;
        }
        Console.WriteLine(
            status.Blocked
                ? "PASS production startup signature; this build identity is blocked"
                : "PASS production startup signature; this build identity is allowed");
        return 0;
    }

    private sealed class StatusCaptureHandler(HttpMessageHandler inner) : DelegatingHandler(inner)
    {
        internal HttpStatusCode? LastStatusCode { get; private set; }

        internal string ResponseSummary { get; private set; } = string.Empty;

        protected override async Task<HttpResponseMessage> SendAsync(
            HttpRequestMessage request,
            CancellationToken cancellationToken)
        {
            var response = await base.SendAsync(request, cancellationToken).ConfigureAwait(false);
            LastStatusCode = response.StatusCode;
            var responseBody = await response.Content.ReadAsStringAsync(cancellationToken)
                .ConfigureAwait(false);
            ResponseSummary = new string(responseBody
                .Where(character => character is >= ' ' and <= '~')
                .Take(256)
                .ToArray());
            return response;
        }
    }
}
