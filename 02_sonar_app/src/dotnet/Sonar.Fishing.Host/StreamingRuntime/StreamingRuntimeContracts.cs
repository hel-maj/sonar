using Sonar.Fishing.Host.StreamingPage;

namespace Sonar.Fishing.Host.StreamingRuntime;

internal sealed record StreamingEncodingProfile(
    string Name,
    int Width,
    int Height,
    int FramesPerSecond,
    string Bitrate)
{
    internal static StreamingEncodingProfile From(
        StreamingQualityProfile quality,
        bool lowFps)
    {
        ArgumentNullException.ThrowIfNull(quality);
        return new StreamingEncodingProfile(
            quality.Name,
            quality.Width,
            quality.Height,
            quality.FramesPerSecondFor(lowFps),
            quality.BitrateFor(lowFps));
    }
}

internal sealed record StreamingSessionRequest(
    StreamingEncodingProfile Encoding,
    bool ChatZoomEnabled)
{
    internal static StreamingSessionRequest From(StreamingRuntimeSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        snapshot.Validate();
        return new StreamingSessionRequest(
            StreamingEncodingProfile.From(
                StreamingQualityCatalog.Require(snapshot.Quality),
                snapshot.SnapshotModeEnabled),
            snapshot.ChatZoomEnabled);
    }
}

internal enum StreamingExecutableOrigin
{
    EmbeddedResource,
    LooseFile,
}

internal sealed record StreamingExecutableSet(
    string EncoderPath,
    string TunnelPath,
    StreamingExecutableOrigin Origin);

internal interface IStreamingExecutableLease : IAsyncDisposable
{
    StreamingExecutableSet Executables { get; }
}

internal interface IStreamingExecutableProvider
{
    ValueTask<IStreamingExecutableLease> AcquireAsync(CancellationToken cancellationToken);
}

internal sealed record StreamingCaptureDescriptor(
    string InputFormat,
    string InputSpecifier,
    IReadOnlyList<string> InputArguments);

internal interface IStreamingCaptureSource
{
    ValueTask<StreamingCaptureDescriptor> ResolveAsync(
        bool chatZoomEnabled,
        CancellationToken cancellationToken);
}

internal enum StreamingProcessRole
{
    Encoder,
    Tunnel,
}

internal sealed record StreamingProcessRequest(
    StreamingProcessRole Role,
    string ExecutablePath,
    IReadOnlyList<string> Arguments,
    string? GracefulStopInput,
    bool CaptureDiagnosticOutput);

internal sealed record StreamingProcessExit(int ExitCode);

internal interface IStreamingProcessLease : IAsyncDisposable
{
    StreamingProcessRole Role { get; }

    Task<StreamingProcessExit> Completion { get; }

    ValueTask<string?> ReadDiagnosticLineAsync(CancellationToken cancellationToken);

    ValueTask StopAsync(TimeSpan timeout, CancellationToken cancellationToken);
}

internal interface IStreamingProcessLauncher
{
    ValueTask<IStreamingProcessLease> StartAsync(
        StreamingProcessRequest request,
        CancellationToken cancellationToken);
}

internal sealed record StreamingNetworkDescriptor(
    Uri LocalBaseUri,
    Uri LocalStreamUri,
    string MediaPlaylistPath,
    string PublicStreamPath,
    bool AuthenticationEnforced);

internal interface IStreamingNetworkSession : IAsyncDisposable
{
    StreamingNetworkDescriptor Descriptor { get; }

    Task Completion { get; }

    ValueTask WaitForMediaAsync(CancellationToken cancellationToken);

    ValueTask<int> GetViewerCountAsync(CancellationToken cancellationToken);

    ValueTask StopAsync(TimeSpan timeout, CancellationToken cancellationToken);
}

internal interface IStreamingNetworkSessionFactory
{
    ValueTask<IStreamingNetworkSession> StartAsync(CancellationToken cancellationToken);
}

internal sealed record StreamingSessionObservation(
    bool Healthy,
    int ViewerCount,
    string FailureReason);

internal interface IStreamingRuntimeSession : IAsyncDisposable
{
    Uri LocalUri { get; }

    Uri PublicUri { get; }

    Uri StreamUri { get; }

    ValueTask<StreamingSessionObservation> ObserveAsync(
        TimeSpan interval,
        CancellationToken cancellationToken);

    ValueTask StopAsync(CancellationToken cancellationToken);
}

internal interface IStreamingSessionBackend
{
    ValueTask<IStreamingRuntimeSession> StartAsync(
        StreamingSessionRequest request,
        CancellationToken cancellationToken);
}

internal sealed record StreamingChatModeResult(bool Active, string Reason);

internal interface IStreamingChatModeBridge
{
    ValueTask<StreamingChatModeResult> SetEnabledAsync(
        bool enabled,
        CancellationToken cancellationToken);
}

internal sealed class StreamingRuntimeException : Exception
{
    internal StreamingRuntimeException(string reason)
        : base(reason)
    {
        Reason = reason;
    }

    internal StreamingRuntimeException(string reason, Exception innerException)
        : base(reason, innerException)
    {
        Reason = reason;
    }

    internal string Reason { get; }
}
