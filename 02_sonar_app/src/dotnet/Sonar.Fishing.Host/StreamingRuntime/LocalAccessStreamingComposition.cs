using System.IO;
using System.Text.Json;

namespace Sonar.Fishing.Host.StreamingRuntime;

internal sealed record LocalAccessStreamingRuntime(
    StreamingRuntimeController Controller,
    bool ChatAvailable);

internal static class LocalAccessStreamingComposition
{
    private const string ToolManifestResource =
        "Sonar.Fishing.Host.Streaming.tool-manifest.json";

    internal static LocalAccessStreamingRuntime? TryCreate(
        bool snapshotModeEnabled)
    {
#if SONAR_FISHING_EMBEDDED_STREAMING
        var assembly = typeof(LocalAccessStreamingComposition).Assembly;
        var resources = assembly.GetManifestResourceNames()
            .ToHashSet(StringComparer.Ordinal);
        if (!resources.Contains(ToolManifestResource))
        {
            return null;
        }

        var tools = ReadToolManifest(assembly);
        if (tools is null)
        {
            return null;
        }
        var ffmpeg = tools.SingleOrDefault(tool => tool.Id == "ffmpeg");
        var cloudflared = tools.SingleOrDefault(tool => tool.Id == "cloudflared");
        if (ffmpeg is null || cloudflared is null ||
            !resources.Contains(ffmpeg.ResourceName) ||
            !resources.Contains(cloudflared.ResourceName))
        {
            return null;
        }

        var localRoot = Path.Combine(
            Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData),
            "Sonar",
            "Fishing",
            "streaming");
        var policy = StreamingRuntimePolicy.Default;
        var backend = new ContainedStreamingSessionBackend(
            new EmbeddedStreamingExecutableProvider(
                assembly,
                Path.Combine(localRoot, "tools"),
                new EmbeddedStreamingExecutableDescriptor(
                    ffmpeg.ResourceName,
                    ffmpeg.FileName,
                    ffmpeg.Sha256),
                new EmbeddedStreamingExecutableDescriptor(
                    cloudflared.ResourceName,
                    cloudflared.FileName,
                    cloudflared.Sha256)),
            new Win32GtaStreamingCaptureSource(),
            new LoopbackHlsNetworkSessionFactory(Path.Combine(localRoot, "media")),
            new CommonContainedStreamingProcessLauncher(),
            policy);
        return new LocalAccessStreamingRuntime(
            new StreamingRuntimeController(
                backend,
                new UnavailableStreamingChatModeBridge(),
                snapshotModeEnabled,
                policy),
            ChatAvailable: false);
#else
        _ = snapshotModeEnabled;
        return null;
#endif
    }

    private static IReadOnlyList<StreamingToolManifestEntry>? ReadToolManifest(
        System.Reflection.Assembly assembly)
    {
        try
        {
            using var stream = assembly.GetManifestResourceStream(ToolManifestResource);
            if (stream is null)
            {
                return null;
            }
            var manifest = JsonSerializer.Deserialize<StreamingToolManifest>(
                stream,
                new JsonSerializerOptions { PropertyNameCaseInsensitive = true });
            if (manifest is null || manifest.SchemaVersion != 1 ||
                manifest.Tools is null || manifest.Tools.Count != 2 ||
                manifest.Tools.Any(tool => !tool.IsValid()) ||
                manifest.Tools.Select(tool => tool.Id).Distinct(StringComparer.Ordinal).Count() != 2 ||
                manifest.Tools.Select(tool => tool.FileName).Distinct(StringComparer.Ordinal).Count() != 2 ||
                manifest.Tools.Select(tool => tool.ResourceName).Distinct(StringComparer.Ordinal).Count() != 2)
            {
                return null;
            }
            return manifest.Tools;
        }
        catch (JsonException)
        {
            return null;
        }
    }

    private sealed record StreamingToolManifest(
        [property: System.Text.Json.Serialization.JsonPropertyName("schema_version")]
        int SchemaVersion,
        [property: System.Text.Json.Serialization.JsonPropertyName("tools")]
        IReadOnlyList<StreamingToolManifestEntry> Tools);

    private sealed record StreamingToolManifestEntry(
        [property: System.Text.Json.Serialization.JsonPropertyName("id")]
        string Id,
        [property: System.Text.Json.Serialization.JsonPropertyName("file_name")]
        string FileName,
        [property: System.Text.Json.Serialization.JsonPropertyName("resource_name")]
        string ResourceName,
        [property: System.Text.Json.Serialization.JsonPropertyName("version")]
        string Version,
        [property: System.Text.Json.Serialization.JsonPropertyName("sha256")]
        string Sha256)
    {
        internal bool IsValid()
        {
            return !string.IsNullOrWhiteSpace(Id) &&
                Path.GetFileName(FileName) == FileName &&
                !string.IsNullOrWhiteSpace(ResourceName) &&
                !string.IsNullOrWhiteSpace(Version) &&
                Sha256.Length == 64 &&
                Sha256.All(static character => char.IsAsciiHexDigit(character));
        }
    }

    private sealed class UnavailableStreamingChatModeBridge :
        IStreamingChatModeBridge
    {
        public ValueTask<StreamingChatModeResult> SetEnabledAsync(
            bool enabled,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            return ValueTask.FromResult(new StreamingChatModeResult(
                Active: false,
                Reason: enabled
                    ? "streaming_chat_bridge_unavailable"
                    : "accepted"));
        }
    }
}
