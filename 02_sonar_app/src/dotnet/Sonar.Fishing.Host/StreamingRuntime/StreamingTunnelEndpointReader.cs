namespace Sonar.Fishing.Host.StreamingRuntime;

internal static class StreamingTunnelEndpointReader
{
    private const int MaximumDiagnosticLineLength = 4096;

    internal static async ValueTask<Uri> WaitForPublicUriAsync(
        IStreamingProcessLease tunnel,
        int maximumLines,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(tunnel);
        if (tunnel.Role != StreamingProcessRole.Tunnel)
        {
            throw new ArgumentException("streaming_tunnel_role_required", nameof(tunnel));
        }
        if (maximumLines <= 0)
        {
            throw new ArgumentOutOfRangeException(nameof(maximumLines));
        }

        for (var index = 0; index < maximumLines; index++)
        {
            var line = await tunnel.ReadDiagnosticLineAsync(cancellationToken)
                .ConfigureAwait(false);
            if (line is null)
            {
                throw new StreamingRuntimeException("streaming_tunnel_endpoint_missing");
            }
            if (TryParsePublicUri(line, out var publicUri))
            {
                return publicUri;
            }
        }
        throw new StreamingRuntimeException("streaming_tunnel_output_limit");
    }

    internal static bool TryParsePublicUri(string line, out Uri publicUri)
    {
        publicUri = null!;
        if (string.IsNullOrEmpty(line) || line.Length > MaximumDiagnosticLineLength)
        {
            return false;
        }

        var start = line.IndexOf("https://", StringComparison.OrdinalIgnoreCase);
        if (start < 0)
        {
            return false;
        }
        var end = start;
        while (end < line.Length && !char.IsWhiteSpace(line[end]) &&
               line[end] is not '"' and not '\'' and not '<' and not '>')
        {
            end++;
        }
        var candidate = line[start..end].TrimEnd('.', ',', ';', ')', ']');
        if (!Uri.TryCreate(candidate, UriKind.Absolute, out var parsed) ||
            parsed.Scheme != Uri.UriSchemeHttps ||
            string.IsNullOrWhiteSpace(parsed.Host) ||
            !string.IsNullOrEmpty(parsed.UserInfo) ||
            !string.IsNullOrEmpty(parsed.Query) ||
            !string.IsNullOrEmpty(parsed.Fragment))
        {
            return false;
        }

        publicUri = new UriBuilder(parsed)
        {
            Path = "/",
            Query = string.Empty,
            Fragment = string.Empty,
        }.Uri;
        return true;
    }
}
