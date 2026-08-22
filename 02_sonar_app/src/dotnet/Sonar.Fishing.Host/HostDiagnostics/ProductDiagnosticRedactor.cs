using System.Text.RegularExpressions;

namespace Sonar.Fishing.Host.HostDiagnostics;

internal static partial class ProductDiagnosticRedactor
{
    internal const int MaximumMessageLength = 4096;
    private const string Replacement = "[REDACTED]";

    internal static string Redact(string value)
    {
        ArgumentNullException.ThrowIfNull(value);
        var bounded = value.Length <= MaximumMessageLength
            ? value
            : value[..MaximumMessageLength];
        bounded = TelegramToken().Replace(bounded, "/bot[REDACTED]/");
        bounded = NamedSecret().Replace(bounded, match =>
            $"{match.Groups[1].Value}{match.Groups[2].Value}{Replacement}");
        bounded = SensitiveQuery().Replace(bounded, match =>
            $"{match.Groups[1].Value}{Replacement}");
        bounded = BearerToken().Replace(bounded, $"Bearer {Replacement}");
        return bounded.Replace('\r', ' ').Replace('\n', ' ');
    }

    [GeneratedRegex(@"/bot\d{4,}:[A-Za-z0-9_-]{16,}/", RegexOptions.CultureInvariant)]
    private static partial Regex TelegramToken();

    [GeneratedRegex(
        @"(?i)\b(authorization|bot[_-]?token|license[_-]?key|password|secret|token)(\s*[:=]\s*)(?:""[^""]*""|'[^']*'|[^\s,;]+)",
        RegexOptions.CultureInvariant)]
    private static partial Regex NamedSecret();

    [GeneratedRegex(
        @"(?i)([?&](?:access_token|api_key|license_key|secret|token)=)[^&#\s]+",
        RegexOptions.CultureInvariant)]
    private static partial Regex SensitiveQuery();

    [GeneratedRegex(@"(?i)\bBearer\s+[A-Za-z0-9._~-]+", RegexOptions.CultureInvariant)]
    private static partial Regex BearerToken();
}
