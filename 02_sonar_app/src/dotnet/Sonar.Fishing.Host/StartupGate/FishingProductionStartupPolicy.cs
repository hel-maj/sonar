using System.IO;
using System.Net.Http;
using System.Security.Cryptography;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.StartupGate;

internal static class FishingProductionStartupPolicy
{
    internal static readonly Uri Endpoint = new(
        "https://m-sonar-addr.ru/api/startup-block",
        UriKind.Absolute);

    internal const string PublicKey =
        "8fdff2bf7962162273a0e97a1ed1c3375c9fd8d174f531143dc6866f49007874";

    private const string AppName = "Sonar";
    private const string BuildKey = "sonar-native-wpf-cpp-v1";

    internal static StartupBlockRequest CreateRequest(HostStateCoordinator state)
    {
        ArgumentNullException.ThrowIfNull(state);
        var executable = Environment.ProcessPath;
        return CreateRequest(executable, state.Current.Secrets.LicenseKey);
    }

    internal static StartupBlockRequest CreateRequest(
        string? executable,
        string licenseKey)
    {
        ArgumentNullException.ThrowIfNull(licenseKey);
        if (string.IsNullOrWhiteSpace(executable) || !File.Exists(executable))
        {
            throw new InvalidOperationException("startup_executable_identity_missing");
        }
        using var stream = new FileStream(
            executable,
            FileMode.Open,
            FileAccess.Read,
            FileShare.Read,
            bufferSize: 128 * 1024,
            FileOptions.SequentialScan);
        var buildHash = Convert.ToHexString(SHA256.HashData(stream));
        return new StartupBlockRequest(
            AppName,
            buildHash,
            BuildKey,
            licenseKey);
    }

    internal static StartupBlockHttpClient CreateClient(HttpClient httpClient) =>
        new(
            httpClient,
            Endpoint,
            new StartupBlockResponseVerifier(PublicKey));
}
