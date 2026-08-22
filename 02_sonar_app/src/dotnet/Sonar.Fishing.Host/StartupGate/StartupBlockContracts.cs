namespace Sonar.Fishing.Host.StartupGate;

public sealed record StartupBlockStatus(
    bool Checked,
    bool Blocked,
    string DownloadUrl,
    string Error)
{
    public static StartupBlockStatus Failure(string error)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(error);
        return new StartupBlockStatus(false, false, string.Empty, error);
    }
}

public sealed class StartupBlockRequest
{
    private readonly string licenseKey;

    public StartupBlockRequest(
        string appName,
        string buildHash,
        string buildKey,
        string licenseKey)
    {
        AppName = RequireBounded(appName, 128, nameof(appName), allowEmpty: false);
        BuildHash = RequireBounded(
            buildHash,
            256,
            nameof(buildHash),
            allowEmpty: true,
            printableAsciiOnly: true);
        BuildKey = RequireBounded(
            buildKey,
            256,
            nameof(buildKey),
            allowEmpty: true,
            printableAsciiOnly: true);
        this.licenseKey = RequireBounded(licenseKey, 512, nameof(licenseKey), allowEmpty: true);
    }

    public string AppName { get; }

    public string BuildHash { get; }

    public string BuildKey { get; }

    internal string LicenseKey => licenseKey;

    public override string ToString() =>
        $"StartupBlockRequest {{ AppName = {AppName}, BuildIdentity = [REDACTED], " +
        "LicenseKey = [REDACTED] }";

    private static string RequireBounded(
        string value,
        int maximumLength,
        string parameterName,
        bool allowEmpty,
        bool printableAsciiOnly = false)
    {
        ArgumentNullException.ThrowIfNull(value, parameterName);
        var normalized = value.Trim();
        if ((!allowEmpty && normalized.Length == 0) ||
            normalized.Length > maximumLength ||
            normalized.Any(character => character is '\r' or '\n' or '\0') ||
            (printableAsciiOnly && normalized.Any(character => character is < ' ' or > '~')))
        {
            throw new ArgumentException("startup_block_request_field_invalid", parameterName);
        }
        return normalized;
    }
}

public interface IStartupBlockCheck
{
    Task<StartupBlockStatus> CheckAsync(
        StartupBlockRequest request,
        CancellationToken cancellationToken);
}
