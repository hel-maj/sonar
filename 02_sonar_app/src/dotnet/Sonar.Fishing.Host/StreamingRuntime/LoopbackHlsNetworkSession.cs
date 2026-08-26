using System.Collections.Concurrent;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Security.Cryptography;
using System.Text;

namespace Sonar.Fishing.Host.StreamingRuntime;

internal sealed class LoopbackHlsNetworkSessionFactory : IStreamingNetworkSessionFactory
{
    private readonly string rootDirectory;

    internal LoopbackHlsNetworkSessionFactory(string rootDirectory)
    {
        this.rootDirectory = Path.GetFullPath(
            string.IsNullOrWhiteSpace(rootDirectory)
                ? throw new ArgumentException(
                    "streaming_media_root_required",
                    nameof(rootDirectory))
                : rootDirectory);
    }

    public ValueTask<IStreamingNetworkSession> StartAsync(
        CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        Directory.CreateDirectory(rootDirectory);
        DeleteStaleSessions();
        var sessionDirectory = Path.Combine(
            rootDirectory,
            $"session-{Guid.NewGuid():N}");
        Directory.CreateDirectory(sessionDirectory);
        try
        {
            return ValueTask.FromResult<IStreamingNetworkSession>(
                new LoopbackHlsNetworkSession(rootDirectory, sessionDirectory));
        }
        catch
        {
            DeleteOwnedDirectory(rootDirectory, sessionDirectory);
            throw;
        }
    }

    private void DeleteStaleSessions()
    {
        foreach (var directory in Directory.EnumerateDirectories(
                     rootDirectory,
                     "session-*",
                     SearchOption.TopDirectoryOnly))
        {
            DeleteOwnedDirectory(rootDirectory, directory);
        }
    }

    internal static void DeleteOwnedDirectory(
        string rootDirectory,
        string sessionDirectory)
    {
        var root = Path.GetFullPath(rootDirectory);
        var session = Path.GetFullPath(sessionDirectory);
        var relative = Path.GetRelativePath(root, session);
        if (Path.IsPathFullyQualified(relative) ||
            relative.StartsWith("..", StringComparison.Ordinal) ||
            relative.Contains(Path.DirectorySeparatorChar) ||
            !relative.StartsWith("session-", StringComparison.Ordinal))
        {
            throw new StreamingRuntimeException(
                "streaming_media_cleanup_scope_invalid");
        }
        if (Directory.Exists(session))
        {
            Directory.Delete(session, recursive: true);
        }
    }
}

internal sealed class LoopbackHlsNetworkSession : IStreamingNetworkSession
{
    private const int MaximumRequestHeaderBytes = 16 * 1024;
    private const int MaximumConcurrentClients = 32;
    private static readonly TimeSpan ViewerFreshness = TimeSpan.FromSeconds(15);
    private static readonly byte[] HeaderTerminator = "\r\n\r\n"u8.ToArray();
    private readonly string rootDirectory;
    private readonly string sessionDirectory;
    private readonly string accessToken;
    private readonly TcpListener listener;
    private readonly CancellationTokenSource lifetime = new();
    private readonly SemaphoreSlim clientSlots = new(
        MaximumConcurrentClients,
        MaximumConcurrentClients);
    private readonly ConcurrentDictionary<string, DateTimeOffset> viewers =
        new(StringComparer.Ordinal);
    private readonly TaskCompletionSource completion = new(
        TaskCreationOptions.RunContinuationsAsynchronously);
    private readonly Task acceptLoop;
    private int stopped;

    internal LoopbackHlsNetworkSession(
        string rootDirectory,
        string sessionDirectory)
    {
        this.rootDirectory = rootDirectory;
        this.sessionDirectory = sessionDirectory;
        accessToken = Convert.ToHexString(RandomNumberGenerator.GetBytes(32))
            .ToLowerInvariant();
        listener = new TcpListener(IPAddress.Loopback, 0);
        listener.Start(64);
        var endpoint = (IPEndPoint)listener.LocalEndpoint;
        var localBase = new Uri($"http://127.0.0.1:{endpoint.Port}/");
        var publicPath = $"/{accessToken}/";
        Descriptor = new StreamingNetworkDescriptor(
            localBase,
            new Uri(localBase, publicPath.TrimStart('/')),
            Path.Combine(sessionDirectory, "live.m3u8"),
            publicPath,
            AuthenticationEnforced: true);
        acceptLoop = Task.Run(AcceptLoopAsync);
    }

    public StreamingNetworkDescriptor Descriptor { get; }

    public Task Completion => completion.Task;

    public async ValueTask WaitForMediaAsync(CancellationToken cancellationToken)
    {
        while (true)
        {
            cancellationToken.ThrowIfCancellationRequested();
            if (HasPlayableMedia())
            {
                return;
            }
            await Task.Delay(TimeSpan.FromMilliseconds(100), cancellationToken)
                .ConfigureAwait(false);
        }
    }

    public ValueTask<int> GetViewerCountAsync(CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        var threshold = DateTimeOffset.UtcNow - ViewerFreshness;
        foreach (var viewer in viewers)
        {
            if (viewer.Value < threshold)
            {
                _ = viewers.TryRemove(viewer.Key, out _);
            }
        }
        return ValueTask.FromResult(viewers.Count);
    }

    public async ValueTask StopAsync(
        TimeSpan timeout,
        CancellationToken cancellationToken)
    {
        if (timeout <= TimeSpan.Zero)
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }
        if (Interlocked.Exchange(ref stopped, 1) != 0)
        {
            await acceptLoop.WaitAsync(timeout, cancellationToken)
                .ConfigureAwait(false);
            return;
        }

        lifetime.Cancel();
        listener.Stop();
        await acceptLoop.WaitAsync(timeout, cancellationToken).ConfigureAwait(false);
        completion.TrySetResult();
        LoopbackHlsNetworkSessionFactory.DeleteOwnedDirectory(
            rootDirectory,
            sessionDirectory);
    }

    public async ValueTask DisposeAsync()
    {
        try
        {
            await StopAsync(TimeSpan.FromSeconds(5), CancellationToken.None)
                .ConfigureAwait(false);
        }
        finally
        {
            lifetime.Dispose();
            clientSlots.Dispose();
        }
    }

    private async Task AcceptLoopAsync()
    {
        try
        {
            while (!lifetime.IsCancellationRequested)
            {
                var client = await listener.AcceptTcpClientAsync(lifetime.Token)
                    .ConfigureAwait(false);
                if (!await clientSlots.WaitAsync(0, lifetime.Token)
                        .ConfigureAwait(false))
                {
                    client.Dispose();
                    continue;
                }
                _ = HandleClientAndReleaseAsync(client);
            }
        }
        catch (OperationCanceledException) when (lifetime.IsCancellationRequested)
        {
        }
        catch (SocketException) when (lifetime.IsCancellationRequested)
        {
        }
        catch (ObjectDisposedException) when (lifetime.IsCancellationRequested)
        {
        }
        catch (Exception exception)
        {
            completion.TrySetException(exception);
            lifetime.Cancel();
            listener.Stop();
        }
    }

    private async Task HandleClientAndReleaseAsync(TcpClient client)
    {
        try
        {
            using (client)
            using (var requestTimeout = CancellationTokenSource.CreateLinkedTokenSource(
                       lifetime.Token))
            {
                requestTimeout.CancelAfter(TimeSpan.FromSeconds(5));
                await HandleClientAsync(client, requestTimeout.Token)
                    .ConfigureAwait(false);
            }
        }
        catch (OperationCanceledException)
        {
        }
        catch (IOException)
        {
        }
        catch (SocketException)
        {
        }
        finally
        {
            clientSlots.Release();
        }
    }

    private async Task HandleClientAsync(
        TcpClient client,
        CancellationToken cancellationToken)
    {
        var stream = client.GetStream();
        var rawHeader = await ReadHeaderAsync(stream, cancellationToken)
            .ConfigureAwait(false);
        if (rawHeader is null)
        {
            await WriteStatusAsync(stream, 431, "Request Header Fields Too Large", cancellationToken)
                .ConfigureAwait(false);
            return;
        }

        var lines = Encoding.ASCII.GetString(rawHeader)
            .Split("\r\n", StringSplitOptions.None);
        var request = lines[0].Split(' ', StringSplitOptions.RemoveEmptyEntries);
        if (request.Length != 3 || request[2] != "HTTP/1.1" ||
            request[0] is not ("GET" or "HEAD") ||
            !Uri.TryCreate("http://127.0.0.1" + request[1], UriKind.Absolute, out var uri))
        {
            await WriteStatusAsync(stream, 400, "Bad Request", cancellationToken)
                .ConfigureAwait(false);
            return;
        }

        var prefix = $"/{accessToken}/";
        if (!uri.AbsolutePath.StartsWith(prefix, StringComparison.Ordinal))
        {
            await WriteStatusAsync(stream, 404, "Not Found", cancellationToken)
                .ConfigureAwait(false);
            return;
        }

        var relative = uri.AbsolutePath[prefix.Length..];
        if (relative.Length == 0)
        {
            await WriteBytesAsync(
                    stream,
                    200,
                    "text/html; charset=utf-8",
                    Encoding.UTF8.GetBytes(ViewerHtml(accessToken)),
                    request[0] == "HEAD",
                    cancellationToken)
                .ConfigureAwait(false);
            return;
        }

        if (!IsSafeMediaName(relative))
        {
            await WriteStatusAsync(stream, 404, "Not Found", cancellationToken)
                .ConfigureAwait(false);
            return;
        }

        var path = Path.Combine(sessionDirectory, relative);
        if (!File.Exists(path))
        {
            await WriteStatusAsync(stream, 404, "Not Found", cancellationToken)
                .ConfigureAwait(false);
            return;
        }

        MarkViewer(client, lines);
        var contentType = relative.EndsWith(".m3u8", StringComparison.OrdinalIgnoreCase)
            ? "application/vnd.apple.mpegurl"
            : "video/mp2t";
        var content = await File.ReadAllBytesAsync(path, cancellationToken)
            .ConfigureAwait(false);
        await WriteBytesAsync(
                stream,
                200,
                contentType,
                content,
                request[0] == "HEAD",
                cancellationToken)
            .ConfigureAwait(false);
    }

    private bool HasPlayableMedia()
    {
        var playlist = Descriptor.MediaPlaylistPath;
        try
        {
            if (!File.Exists(playlist))
            {
                return false;
            }
            var lines = File.ReadAllLines(playlist);
            return lines.Any(static line => line.StartsWith("#EXTINF", StringComparison.Ordinal)) &&
                lines.Where(static line => line.Length > 0 && line[0] != '#')
                    .Any(segment =>
                        IsSafeMediaName(segment) &&
                        File.Exists(Path.Combine(sessionDirectory, segment)));
        }
        catch (IOException)
        {
            return false;
        }
        catch (UnauthorizedAccessException)
        {
            return false;
        }
    }

    private void MarkViewer(TcpClient client, IReadOnlyList<string> headers)
    {
        var forwarded = headers.FirstOrDefault(static line =>
            line.StartsWith("CF-Connecting-IP:", StringComparison.OrdinalIgnoreCase));
        var identity = forwarded is null
            ? (client.Client.RemoteEndPoint as IPEndPoint)?.Address.ToString()
            : forwarded[(forwarded.IndexOf(':') + 1)..].Trim();
        if (string.IsNullOrWhiteSpace(identity) || identity.Length > 64)
        {
            identity = "unknown";
        }
        viewers[identity] = DateTimeOffset.UtcNow;
    }

    private static async ValueTask<byte[]?> ReadHeaderAsync(
        NetworkStream stream,
        CancellationToken cancellationToken)
    {
        var result = new List<byte>(1024);
        var buffer = new byte[1024];
        while (result.Count <= MaximumRequestHeaderBytes)
        {
            var read = await stream.ReadAsync(buffer, cancellationToken)
                .ConfigureAwait(false);
            if (read == 0)
            {
                break;
            }
            for (var index = 0; index < read; ++index)
            {
                result.Add(buffer[index]);
                if (result.Count >= HeaderTerminator.Length &&
                    result.TakeLast(HeaderTerminator.Length)
                        .SequenceEqual(HeaderTerminator))
                {
                    return result.ToArray();
                }
                if (result.Count > MaximumRequestHeaderBytes)
                {
                    return null;
                }
            }
        }
        return null;
    }

    private static bool IsSafeMediaName(string value) =>
        value.Length is > 0 and <= 128 &&
        !value.Contains('/') && !value.Contains('\\') &&
        value.All(static character => char.IsAsciiLetterOrDigit(character) ||
            character is '.' or '_' or '-') &&
        (value.EndsWith(".m3u8", StringComparison.OrdinalIgnoreCase) ||
            value.EndsWith(".ts", StringComparison.OrdinalIgnoreCase));

    private static async ValueTask WriteStatusAsync(
        NetworkStream stream,
        int status,
        string reason,
        CancellationToken cancellationToken) =>
        await WriteBytesAsync(
                stream,
                status,
                "text/plain; charset=utf-8",
                Encoding.UTF8.GetBytes(reason),
                headOnly: false,
                cancellationToken)
            .ConfigureAwait(false);

    private static async ValueTask WriteBytesAsync(
        NetworkStream stream,
        int status,
        string contentType,
        byte[] content,
        bool headOnly,
        CancellationToken cancellationToken)
    {
        var reason = status switch
        {
            200 => "OK",
            400 => "Bad Request",
            404 => "Not Found",
            431 => "Request Header Fields Too Large",
            _ => "Error",
        };
        var headers = Encoding.ASCII.GetBytes(
            $"HTTP/1.1 {status} {reason}\r\n" +
            $"Content-Type: {contentType}\r\n" +
            $"Content-Length: {content.Length}\r\n" +
            "Cache-Control: no-store\r\n" +
            "X-Content-Type-Options: nosniff\r\n" +
            "Connection: close\r\n\r\n");
        await stream.WriteAsync(headers, cancellationToken).ConfigureAwait(false);
        if (!headOnly)
        {
            await stream.WriteAsync(content, cancellationToken).ConfigureAwait(false);
        }
    }

    private static string ViewerHtml(string token) => $$"""
        <!doctype html>
        <html lang="ru"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
        <title>Sonar Fishing</title><style>html,body{margin:0;background:#090d13;color:#fff;font-family:Segoe UI,sans-serif;height:100%}main{display:grid;place-items:center;height:100%;padding:16px;box-sizing:border-box}video{width:min(100%,1280px);max-height:calc(100vh - 32px);background:#000;border-radius:12px}</style></head>
        <body><main><video id="stream" controls autoplay muted playsinline></video></main>
        <script src="https://cdn.jsdelivr.net/npm/hls.js@1.6.16/dist/hls.min.js" integrity="sha384-5E8B0pTlZZJMabWpC0fyYf6OUpe15jJij34BqBAh4NXoHAlLNOjCPRrwtOXOQFAn" crossorigin="anonymous"></script>
        <script>const v=document.getElementById('stream'),u='/{{token}}/live.m3u8';if(v.canPlayType('application/vnd.apple.mpegurl'))v.src=u;else if(window.Hls&&Hls.isSupported()){const h=new Hls();h.loadSource(u);h.attachMedia(v);}</script></body></html>
        """;
}
