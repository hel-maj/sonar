using System.IO;
using Sonar.Fishing.Host.StreamingPage;

namespace Sonar.Fishing.Host.StreamingRuntime;

internal sealed class ContainedStreamingSessionBackend : IStreamingSessionBackend
{
    private readonly IStreamingExecutableProvider executableProvider;
    private readonly IStreamingCaptureSource captureSource;
    private readonly IStreamingNetworkSessionFactory networkFactory;
    private readonly IStreamingProcessLauncher processLauncher;
    private readonly StreamingRuntimePolicy policy;

    internal ContainedStreamingSessionBackend(
        IStreamingExecutableProvider executableProvider,
        IStreamingCaptureSource captureSource,
        IStreamingNetworkSessionFactory networkFactory,
        IStreamingProcessLauncher processLauncher,
        StreamingRuntimePolicy policy)
    {
        this.executableProvider = executableProvider ??
            throw new ArgumentNullException(nameof(executableProvider));
        this.captureSource = captureSource ??
            throw new ArgumentNullException(nameof(captureSource));
        this.networkFactory = networkFactory ??
            throw new ArgumentNullException(nameof(networkFactory));
        this.processLauncher = processLauncher ??
            throw new ArgumentNullException(nameof(processLauncher));
        this.policy = policy ?? throw new ArgumentNullException(nameof(policy));
        policy.Validate();
    }

    public async ValueTask<IStreamingRuntimeSession> StartAsync(
        StreamingSessionRequest request,
        CancellationToken cancellationToken)
    {
        ValidateRequest(request);
        IStreamingExecutableLease? executableLease = null;
        IStreamingNetworkSession? network = null;
        IStreamingProcessLease? encoder = null;
        IStreamingProcessLease? tunnel = null;
        try
        {
            executableLease = await executableProvider.AcquireAsync(cancellationToken)
                .ConfigureAwait(false);
            ValidateExecutables(executableLease.Executables);
            var capture = await captureSource.ResolveAsync(
                    request.ChatZoomEnabled,
                    cancellationToken)
                .ConfigureAwait(false);
            network = await networkFactory.StartAsync(cancellationToken)
                .ConfigureAwait(false);
            ValidateNetwork(network.Descriptor);

            encoder = await processLauncher.StartAsync(
                    StreamingProcessPlanFactory.CreateEncoder(
                        executableLease.Executables,
                        capture,
                        network.Descriptor,
                        request.Encoding),
                    cancellationToken)
                .ConfigureAwait(false);
            await WaitForMediaOrExitAsync(network, encoder, cancellationToken)
                .ConfigureAwait(false);

            tunnel = await processLauncher.StartAsync(
                    StreamingProcessPlanFactory.CreateTunnel(
                        executableLease.Executables,
                        network.Descriptor),
                    cancellationToken)
                .ConfigureAwait(false);
            var publicUri = await StreamingTunnelEndpointReader.WaitForPublicUriAsync(
                    tunnel,
                    policy.MaximumTunnelDiagnosticLines,
                    cancellationToken)
                .ConfigureAwait(false);
            var publicStreamUri = new Uri(
                publicUri,
                network.Descriptor.PublicStreamPath.TrimStart('/'));

            return new ContainedStreamingRuntimeSession(
                executableLease,
                network,
                encoder,
                tunnel,
                publicUri,
                publicStreamUri,
                policy);
        }
        catch
        {
            var cleanupFailure = await CleanupAsync(
                    tunnel,
                    encoder,
                    network,
                    executableLease,
                    policy.CleanupTimeout)
                .ConfigureAwait(false);
            if (cleanupFailure is not null)
            {
                throw new StreamingRuntimeException(cleanupFailure);
            }
            throw;
        }
    }

    private static async ValueTask WaitForMediaOrExitAsync(
        IStreamingNetworkSession network,
        IStreamingProcessLease encoder,
        CancellationToken cancellationToken)
    {
        var mediaReady = network.WaitForMediaAsync(cancellationToken).AsTask();
        var completed = await Task.WhenAny(
                mediaReady,
                encoder.Completion,
                network.Completion)
            .WaitAsync(cancellationToken)
            .ConfigureAwait(false);
        if (completed != mediaReady)
        {
            throw new StreamingRuntimeException("streaming_encoder_not_ready");
        }
        await mediaReady.ConfigureAwait(false);
    }

    private static void ValidateRequest(StreamingSessionRequest request)
    {
        ArgumentNullException.ThrowIfNull(request);
        ArgumentNullException.ThrowIfNull(request.Encoding);
        var quality = StreamingQualityCatalog.Require(request.Encoding.Name);
        var lowFps = request.Encoding.FramesPerSecond switch
        {
            10 => true,
            30 => false,
            _ => throw new StreamingRuntimeException("streaming_frame_rate_invalid"),
        };
        var expected = StreamingEncodingProfile.From(quality, lowFps);
        if (request.Encoding != expected)
        {
            throw new StreamingRuntimeException("streaming_encoding_profile_invalid");
        }
    }

    private static void ValidateExecutables(StreamingExecutableSet executables)
    {
        ArgumentNullException.ThrowIfNull(executables);
        if (executables.Origin != StreamingExecutableOrigin.EmbeddedResource)
        {
            throw new StreamingRuntimeException("streaming_loose_tools_forbidden");
        }
        if (!Path.IsPathFullyQualified(executables.EncoderPath) ||
            !Path.IsPathFullyQualified(executables.TunnelPath) ||
            string.Equals(
                executables.EncoderPath,
                executables.TunnelPath,
                StringComparison.OrdinalIgnoreCase))
        {
            throw new StreamingRuntimeException("streaming_tool_paths_invalid");
        }
    }

    private static void ValidateNetwork(StreamingNetworkDescriptor descriptor)
    {
        ArgumentNullException.ThrowIfNull(descriptor);
        if (!descriptor.AuthenticationEnforced ||
            !descriptor.LocalBaseUri.IsAbsoluteUri ||
            !descriptor.LocalBaseUri.IsLoopback ||
            !descriptor.LocalStreamUri.IsAbsoluteUri ||
            !descriptor.LocalStreamUri.IsLoopback ||
            !string.Equals(
                descriptor.LocalBaseUri.Host,
                descriptor.LocalStreamUri.Host,
                StringComparison.OrdinalIgnoreCase) ||
            !string.Equals(
                descriptor.LocalBaseUri.Scheme,
                descriptor.LocalStreamUri.Scheme,
                StringComparison.OrdinalIgnoreCase) ||
            descriptor.LocalBaseUri.Port != descriptor.LocalStreamUri.Port ||
            !Path.IsPathFullyQualified(descriptor.MediaPlaylistPath) ||
            string.IsNullOrWhiteSpace(descriptor.PublicStreamPath) ||
            !descriptor.PublicStreamPath.StartsWith("/", StringComparison.Ordinal) ||
            descriptor.PublicStreamPath.Contains("..", StringComparison.Ordinal))
        {
            throw new StreamingRuntimeException("streaming_network_boundary_invalid");
        }
    }

    internal static ValueTask<string?> CleanupAsync(
        IStreamingProcessLease? tunnel,
        IStreamingProcessLease? encoder,
        IStreamingNetworkSession? network,
        IStreamingExecutableLease? executableLease,
        TimeSpan timeout) => StreamingCleanupScope.RunAsync(
        timeout,
        cancellationToken => StopProcessAsync(tunnel, timeout, cancellationToken),
        cancellationToken => StopProcessAsync(encoder, timeout, cancellationToken),
        cancellationToken => StopNetworkAsync(network, timeout, cancellationToken),
        _ => executableLease?.DisposeAsync() ?? ValueTask.CompletedTask);

    private static async ValueTask StopProcessAsync(
        IStreamingProcessLease? process,
        TimeSpan timeout,
        CancellationToken cancellationToken)
    {
        if (process is null)
        {
            return;
        }
        await process.StopAsync(timeout, cancellationToken).ConfigureAwait(false);
        await process.DisposeAsync().ConfigureAwait(false);
    }

    private static async ValueTask StopNetworkAsync(
        IStreamingNetworkSession? network,
        TimeSpan timeout,
        CancellationToken cancellationToken)
    {
        if (network is null)
        {
            return;
        }
        await network.StopAsync(timeout, cancellationToken).ConfigureAwait(false);
        await network.DisposeAsync().ConfigureAwait(false);
    }
}

internal sealed class ContainedStreamingRuntimeSession : IStreamingRuntimeSession
{
    private readonly IStreamingExecutableLease executableLease;
    private readonly IStreamingNetworkSession network;
    private readonly IStreamingProcessLease encoder;
    private readonly IStreamingProcessLease tunnel;
    private readonly StreamingRuntimePolicy policy;
    private readonly object stopSync = new();
    private Task? stopTask;

    internal ContainedStreamingRuntimeSession(
        IStreamingExecutableLease executableLease,
        IStreamingNetworkSession network,
        IStreamingProcessLease encoder,
        IStreamingProcessLease tunnel,
        Uri publicUri,
        Uri streamUri,
        StreamingRuntimePolicy policy)
    {
        this.executableLease = executableLease;
        this.network = network;
        this.encoder = encoder;
        this.tunnel = tunnel;
        this.policy = policy;
        LocalUri = network.Descriptor.LocalStreamUri;
        PublicUri = publicUri;
        StreamUri = streamUri;
    }

    public Uri LocalUri { get; }

    public Uri PublicUri { get; }

    public Uri StreamUri { get; }

    public async ValueTask<StreamingSessionObservation> ObserveAsync(
        TimeSpan interval,
        CancellationToken cancellationToken)
    {
        if (interval <= TimeSpan.Zero)
        {
            throw new ArgumentOutOfRangeException(nameof(interval));
        }

        var delay = Task.Delay(interval, cancellationToken);
        var completed = await Task.WhenAny(
                delay,
                encoder.Completion,
                tunnel.Completion,
                network.Completion)
            .WaitAsync(cancellationToken)
            .ConfigureAwait(false);
        if (completed != delay)
        {
            _ = completed.Exception;
            return new StreamingSessionObservation(
                Healthy: false,
                ViewerCount: 0,
                FailureReason: "streaming_component_exited");
        }

        var viewers = await network.GetViewerCountAsync(cancellationToken)
            .ConfigureAwait(false);
        if (viewers < 0)
        {
            return new StreamingSessionObservation(
                Healthy: false,
                ViewerCount: 0,
                FailureReason: "streaming_viewer_count_invalid");
        }
        return new StreamingSessionObservation(
            Healthy: true,
            ViewerCount: viewers,
            FailureReason: string.Empty);
    }

    public async ValueTask StopAsync(CancellationToken cancellationToken)
    {
        Task currentStop;
        lock (stopSync)
        {
            stopTask ??= StopCoreAsync();
            currentStop = stopTask;
        }
        await currentStop.WaitAsync(cancellationToken).ConfigureAwait(false);
    }

    public ValueTask DisposeAsync() => StopAsync(CancellationToken.None);

    private async Task StopCoreAsync()
    {
        var failure = await ContainedStreamingSessionBackend.CleanupAsync(
                tunnel,
                encoder,
                network,
                executableLease,
                policy.CleanupTimeout)
            .ConfigureAwait(false);
        if (failure is not null)
        {
            throw new StreamingRuntimeException(failure);
        }
    }
}
