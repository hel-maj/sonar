using System.Collections.Concurrent;
using System.Diagnostics;
using System.IO;
using System.Net.Http;
using Sonar.Fishing.Host.StreamingPage;
using Sonar.Fishing.Host.StreamingRuntime;

namespace Sonar.Fishing.Host.Tests;

internal static class StreamingRuntimeTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("streaming_process_plans_preserve_exact_quality_and_fps_matrix", ProcessPlansPreservePolicy),
        new("streaming_tunnel_endpoint_parser_accepts_only_safe_https_base", TunnelEndpointParserIsFailClosed),
        new("streaming_loopback_hls_requires_secret_path_and_cleans_workspace", LoopbackHlsIsAuthenticatedAndClean),
        new("streaming_local_access_composition_matches_embedded_tool_resources", LocalAccessCompositionMatchesResources),
        new("streaming_backend_starts_and_cleans_fake_components_in_order", BackendLifecycleIsOrdered),
        new("streaming_backend_rejects_loose_tools_and_unauthenticated_viewer", BackendBoundariesFailClosed),
        new("streaming_backend_rolls_back_partial_fake_start", BackendRollsBackPartialStart),
        new("streaming_cleanup_budget_bounds_noncooperative_fake_adapter", CleanupBudgetIsBounded),
        new("streaming_controller_cancels_inflight_fake_start", ControllerCancelsInflightStart),
        new("streaming_controller_start_stop_is_cancellable_and_cleanup_bounded", ControllerStartStopIsBounded),
        new("streaming_controller_serializes_quality_restart_without_overlap", ControllerRestartIsSerialized),
        new("streaming_controller_bounds_automatic_restart_budget", ControllerRestartBudgetIsBounded),
        new("streaming_controller_bounds_chat_bridge_command", ControllerChatCommandIsBounded),
    ];

    private static void ProcessPlansPreservePolicy()
    {
        var executables = EmbeddedExecutableSet();
        var capture = new StreamingCaptureDescriptor("fake-capture", "fake-input", ["-fake"]);
        var network = NetworkDescriptor(authenticationEnforced: true);

        foreach (var quality in StreamingQualityCatalog.All)
        {
            foreach (var lowFps in new[] { false, true })
            {
                var encoding = StreamingEncodingProfile.From(quality, lowFps);
                var plan = StreamingProcessPlanFactory.CreateEncoder(
                    executables,
                    capture,
                    network,
                    encoding);
                TestAssert.Equal(
                    quality.FramesPerSecondFor(lowFps).ToString(),
                    ArgumentAfter(plan.Arguments, "-framerate"),
                    $"{quality.Name} capture FPS changed");
                TestAssert.Equal(
                    quality.FramesPerSecondFor(lowFps).ToString(),
                    ArgumentAfter(plan.Arguments, "-r"),
                    $"{quality.Name} output FPS changed");
                TestAssert.Equal(
                    quality.BitrateFor(lowFps),
                    ArgumentAfter(plan.Arguments, "-b:v"),
                    $"{quality.Name} bitrate changed");
                var filter = ArgumentAfter(plan.Arguments, "-vf");
                TestAssert.True(
                    filter.Contains(
                        $"scale={quality.Width}:{quality.Height}",
                        StringComparison.Ordinal) &&
                    filter.Contains(
                        $"pad={quality.Width}:{quality.Height}",
                        StringComparison.Ordinal),
                    $"{quality.Name} aspect-preserving output geometry changed");
            }
        }
    }

    private static void TunnelEndpointParserIsFailClosed()
    {
        TestAssert.True(
            StreamingTunnelEndpointReader.TryParsePublicUri(
                "INF tunnel ready https://unit.trycloudflare.test",
                out var endpoint),
            "Safe HTTPS tunnel endpoint was rejected");
        TestAssert.Equal(
            "https://unit.trycloudflare.test/",
            endpoint.AbsoluteUri,
            "Tunnel endpoint was not normalized to a base URI");
        TestAssert.True(
            !StreamingTunnelEndpointReader.TryParsePublicUri(
                "http://unit.trycloudflare.test",
                out _),
            "Plain HTTP tunnel endpoint was accepted");
        TestAssert.True(
            !StreamingTunnelEndpointReader.TryParsePublicUri(
                "https://user:secret@unit.trycloudflare.test",
                out _),
            "Credential-bearing tunnel endpoint was accepted");
        TestAssert.True(
            !StreamingTunnelEndpointReader.TryParsePublicUri(
                "https://unit.trycloudflare.test/?token=secret",
                out _),
            "Query-bearing tunnel endpoint was accepted");
    }

    private static void LoopbackHlsIsAuthenticatedAndClean()
    {
        var root = Path.Combine(
            Path.GetTempPath(),
            $"sonar-fishing-streaming-{Guid.NewGuid():N}");
        IStreamingNetworkSession? session = null;
        try
        {
            session = new LoopbackHlsNetworkSessionFactory(root)
                .StartAsync(CancellationToken.None)
                .AsTask()
                .GetAwaiter()
                .GetResult();
            File.WriteAllBytes(
                Path.Combine(
                    Path.GetDirectoryName(session.Descriptor.MediaPlaylistPath)!,
                    "live0.ts"),
                [0x47, 0x40, 0x00, 0x10]);
            File.WriteAllText(
                session.Descriptor.MediaPlaylistPath,
                "#EXTM3U\n#EXTINF:2.0,\nlive0.ts\n");
            session.WaitForMediaAsync(CancellationToken.None)
                .AsTask()
                .GetAwaiter()
                .GetResult();

            using var client = new HttpClient();
            var unauthorized = client.GetAsync(session.Descriptor.LocalBaseUri)
                .GetAwaiter()
                .GetResult();
            TestAssert.Equal(
                System.Net.HttpStatusCode.NotFound,
                unauthorized.StatusCode,
                "Streaming origin disclosed content without the secret path");
            var viewer = client.GetAsync(session.Descriptor.LocalStreamUri)
                .GetAwaiter()
                .GetResult();
            TestAssert.Equal(
                System.Net.HttpStatusCode.OK,
                viewer.StatusCode,
                "Authenticated streaming viewer page was unavailable");
            var viewerHtml = viewer.Content.ReadAsStringAsync()
                .GetAwaiter()
                .GetResult();
            TestAssert.True(
                viewerHtml.Contains(
                    "hls.js@1.6.16/dist/hls.min.js",
                    StringComparison.Ordinal) &&
                viewerHtml.Contains(
                    "sha384-5E8B0pTlZZJMabWpC0fyYf6OUpe15jJij34BqBAh4NXoHAlLNOjCPRrwtOXOQFAn",
                    StringComparison.Ordinal) &&
                !viewerHtml.Contains("hls.js@1/dist", StringComparison.Ordinal),
                "Streaming viewer did not pin its HLS player dependency");
            var playlist = client.GetAsync(new Uri(
                    session.Descriptor.LocalStreamUri,
                    "live.m3u8"))
                .GetAwaiter()
                .GetResult();
            TestAssert.Equal(
                System.Net.HttpStatusCode.OK,
                playlist.StatusCode,
                "Authenticated HLS playlist was unavailable");
            TestAssert.Equal(
                1,
                session.GetViewerCountAsync(CancellationToken.None)
                    .AsTask()
                    .GetAwaiter()
                    .GetResult(),
                "Authenticated playlist access was not counted as a viewer");

            session.StopAsync(TimeSpan.FromSeconds(2), CancellationToken.None)
                .AsTask()
                .GetAwaiter()
                .GetResult();
            TestAssert.True(
                !Directory.EnumerateDirectories(root).Any(),
                "Streaming session workspace survived a normal stop");
        }
        finally
        {
            if (session is not null)
            {
                session.DisposeAsync().AsTask().GetAwaiter().GetResult();
            }
            if (Directory.Exists(root))
            {
                Directory.Delete(root, recursive: true);
            }
        }
    }

    private static void LocalAccessCompositionMatchesResources()
    {
        var assembly = typeof(LocalAccessStreamingComposition).Assembly;
        var resources = assembly.GetManifestResourceNames();
        var toolsEmbedded = resources.Contains(
                "Sonar.Fishing.Host.Streaming.ffmpeg.exe",
                StringComparer.Ordinal) &&
            resources.Contains(
                "Sonar.Fishing.Host.Streaming.cloudflared.exe",
                StringComparer.Ordinal) &&
            resources.Contains(
                "Sonar.Fishing.Host.Streaming.tool-manifest.json",
                StringComparer.Ordinal);
        var runtime = LocalAccessStreamingComposition.TryCreate(
            snapshotModeEnabled: false);
        try
        {
            TestAssert.Equal(
                toolsEmbedded,
                runtime is not null,
                "Local Access streaming availability diverged from embedded resources");
            if (runtime is not null)
            {
                TestAssert.Equal(
                    StreamingRuntimeStatus.Offline,
                    runtime.Controller.Current.Status,
                    "Embedded Local Access streaming did not start from an offline state");
                TestAssert.True(
                    !runtime.ChatAvailable,
                    "Unimplemented chat bridge was advertised as available");
            }
        }
        finally
        {
            runtime?.Controller.DisposeAsync().AsTask().GetAwaiter().GetResult();
        }
    }

    private static void BackendLifecycleIsOrdered()
    {
        var log = new List<string>();
        var processLauncher = new RecordingProcessLauncher(log, tunnelEndpointAvailable: true);
        var backend = CreateContainedBackend(
            log,
            processLauncher,
            EmbeddedExecutableSet(),
            NetworkDescriptor(authenticationEnforced: true));
        var session = backend.StartAsync(SessionRequest(), CancellationToken.None)
            .AsTask().GetAwaiter().GetResult();

        TestAssert.True(
            log.SequenceEqual(
            [
                "tools.acquire",
                "capture.resolve:false",
                "network.start",
                "encoder.start",
                "network.media",
                "tunnel.start",
                "tunnel.read",
            ]),
            $"Streaming startup order changed: {string.Join(',', log)}");
        TestAssert.Equal(
            "https://viewer.example.test/live/",
            session.StreamUri.AbsoluteUri,
            "Authenticated public stream path changed");

        session.StopAsync(CancellationToken.None).AsTask().GetAwaiter().GetResult();
        TestAssert.True(
            log.TakeLast(7).SequenceEqual(
            [
                "tunnel.stop",
                "tunnel.dispose",
                "encoder.stop",
                "encoder.dispose",
                "network.stop",
                "network.dispose",
                "tools.dispose",
            ]),
            $"Streaming cleanup order changed: {string.Join(',', log)}");
    }

    private static void BackendBoundariesFailClosed()
    {
        var looseLog = new List<string>();
        var looseBackend = CreateContainedBackend(
            looseLog,
            new RecordingProcessLauncher(looseLog, tunnelEndpointAvailable: true),
            EmbeddedExecutableSet() with { Origin = StreamingExecutableOrigin.LooseFile },
            NetworkDescriptor(authenticationEnforced: true));
        var loose = TestAssert.Throws<StreamingRuntimeException>(
            () => looseBackend.StartAsync(SessionRequest(), CancellationToken.None)
                .AsTask().GetAwaiter().GetResult(),
            "Loose streaming tools were accepted");
        TestAssert.Equal(
            "streaming_loose_tools_forbidden",
            loose.Reason,
            "Loose-tool rejection reason changed");
        TestAssert.True(
            looseLog.SequenceEqual(["tools.acquire", "tools.dispose"]),
            "Loose-tool rejection crossed the process/network boundary");

        var networkLog = new List<string>();
        var unauthenticatedBackend = CreateContainedBackend(
            networkLog,
            new RecordingProcessLauncher(networkLog, tunnelEndpointAvailable: true),
            EmbeddedExecutableSet(),
            NetworkDescriptor(authenticationEnforced: false));
        var unauthenticated = TestAssert.Throws<StreamingRuntimeException>(
            () => unauthenticatedBackend.StartAsync(SessionRequest(), CancellationToken.None)
                .AsTask().GetAwaiter().GetResult(),
            "Unauthenticated viewer surface was accepted");
        TestAssert.Equal(
            "streaming_network_boundary_invalid",
            unauthenticated.Reason,
            "Unauthenticated viewer rejection reason changed");
        TestAssert.True(
            networkLog.SequenceEqual(
            [
                "tools.acquire",
                "capture.resolve:false",
                "network.start",
                "network.stop",
                "network.dispose",
                "tools.dispose",
            ]),
            "Unauthenticated viewer rejection launched a process or leaked resources");
    }

    private static void BackendRollsBackPartialStart()
    {
        var log = new List<string>();
        var backend = CreateContainedBackend(
            log,
            new RecordingProcessLauncher(log, tunnelEndpointAvailable: false),
            EmbeddedExecutableSet(),
            NetworkDescriptor(authenticationEnforced: true));
        var exception = TestAssert.Throws<StreamingRuntimeException>(
            () => backend.StartAsync(SessionRequest(), CancellationToken.None)
                .AsTask().GetAwaiter().GetResult(),
            "Missing tunnel endpoint did not fail startup");
        TestAssert.Equal(
            "streaming_tunnel_endpoint_missing",
            exception.Reason,
            "Missing tunnel endpoint reason changed");
        TestAssert.True(
            log.TakeLast(7).SequenceEqual(
            [
                "tunnel.stop",
                "tunnel.dispose",
                "encoder.stop",
                "encoder.dispose",
                "network.stop",
                "network.dispose",
                "tools.dispose",
            ]),
            $"Partial startup rollback order changed: {string.Join(',', log)}");
    }

    private static void CleanupBudgetIsBounded()
    {
        var neverCompletes = new TaskCompletionSource(
            TaskCreationOptions.RunContinuationsAsynchronously);
        var stopwatch = Stopwatch.StartNew();
        var failure = StreamingCleanupScope.RunAsync(
                TimeSpan.FromMilliseconds(40),
                _ => new ValueTask(neverCompletes.Task))
            .AsTask().GetAwaiter().GetResult();
        stopwatch.Stop();
        TestAssert.Equal(
            "streaming_cleanup_timeout",
            failure!,
            "Noncooperative cleanup did not expose the stable timeout reason");
        TestAssert.True(
            stopwatch.Elapsed < TimeSpan.FromSeconds(1),
            "Noncooperative cleanup exceeded the total cleanup budget");
    }

    private static void ControllerCancelsInflightStart()
    {
        var backend = new BlockingSessionBackend();
        var controller = CreateController(
            backend,
            new FakeChatModeBridge(),
            maximumRestarts: 0);
        try
        {
            TestAssert.True(controller.Start().Accepted, "Blocked fake start was rejected");
            WaitUntil(
                () => backend.Started.Task.IsCompleted,
                "Blocked fake backend was not entered");
            var stopwatch = Stopwatch.StartNew();
            controller.Stop("test");
            stopwatch.Stop();
            TestAssert.True(
                stopwatch.Elapsed < TimeSpan.FromSeconds(1),
                "In-flight startup cancellation blocked the caller");
            WaitUntil(
                () => backend.Canceled.Task.IsCompleted,
                $"In-flight fake startup did not observe cancellation; " +
                $"can_cancel={backend.ObservedToken.CanBeCanceled}; " +
                $"requested={backend.ObservedToken.IsCancellationRequested}; " +
                $"status={controller.Current.Status}");
            TestAssert.Equal(
                StreamingRuntimeStatus.Offline,
                controller.Current.Status,
                "Canceled startup overwrote the offline snapshot");
        }
        finally
        {
            controller.DisposeAsync().AsTask().GetAwaiter().GetResult();
        }
    }

    private static void ControllerStartStopIsBounded()
    {
        var backend = new RecordingSessionBackend(
            _ => new FakeRuntimeSession(healthy: true, viewerCount: 1));
        var bridge = new FakeChatModeBridge();
        var revisions = new ConcurrentQueue<ulong>();
        var controller = CreateController(backend, bridge, maximumRestarts: 0);
        controller.SnapshotChanged += snapshot => revisions.Enqueue(snapshot.Revision);
        try
        {
            var started = controller.Start();
            TestAssert.True(started.Accepted, "Streaming start was rejected");
            TestAssert.Equal(
                StreamingRuntimeStatus.Starting,
                started.Snapshot.Status,
                "Streaming did not enter starting state synchronously");
            WaitUntil(
                () => controller.Current.Status == StreamingRuntimeStatus.Online,
                "Streaming fake session did not become online");

            var stopwatch = Stopwatch.StartNew();
            var stopped = controller.Stop("test");
            stopwatch.Stop();
            TestAssert.True(stopped.Accepted, "Streaming stop was rejected");
            TestAssert.Equal(
                StreamingRuntimeStatus.Offline,
                stopped.Snapshot.Status,
                "Streaming stop did not publish offline atomically");
            TestAssert.True(
                stopwatch.Elapsed < TimeSpan.FromSeconds(1),
                "Streaming stop blocked the caller beyond its coarse cancellation boundary");
            WaitUntil(
                () => backend.Sessions.Single().Stopped,
                "Streaming fake session was not cleaned after stop");
            var observed = revisions.ToArray();
            TestAssert.True(
                observed.Zip(observed.Skip(1), (left, right) => right > left).All(value => value),
                "Streaming snapshots were not strictly revisioned");
        }
        finally
        {
            controller.DisposeAsync().AsTask().GetAwaiter().GetResult();
        }
    }

    private static void ControllerRestartIsSerialized()
    {
        var backend = new RecordingSessionBackend(
            _ => new FakeRuntimeSession(healthy: true, viewerCount: 1));
        var controller = CreateController(
            backend,
            new FakeChatModeBridge(),
            maximumRestarts: 0);
        try
        {
            TestAssert.True(
                controller.SetSnapshotMode(true).Accepted,
                "10-FPS setting was rejected while offline");
            TestAssert.True(controller.Start().Accepted, "Initial stream start was rejected");
            WaitUntil(
                () => controller.Current.Status == StreamingRuntimeStatus.Online,
                "Initial fake stream did not become online");

            var restarted = controller.SetQuality("1080p");
            TestAssert.True(restarted.Accepted, "Online quality restart was rejected");
            TestAssert.Equal(
                StreamingRuntimeStatus.Starting,
                restarted.Snapshot.Status,
                "Online quality change did not enter controlled restart");
            WaitUntil(
                () => backend.Requests.Count >= 2 &&
                    controller.Current.Status == StreamingRuntimeStatus.Online,
                "Replacement fake stream did not become online");

            var requests = backend.Requests.ToArray();
            TestAssert.Equal(2, requests.Length, "Quality restart launched the wrong generation count");
            TestAssert.Equal(10, requests[0].Encoding.FramesPerSecond, "Initial 10-FPS setting changed");
            TestAssert.Equal("1080p", requests[1].Encoding.Name, "Restart lost new quality");
            TestAssert.Equal(10, requests[1].Encoding.FramesPerSecond, "Restart lost 10-FPS mode");
            TestAssert.Equal(1, backend.MaximumActiveSessions, "Streaming generations overlapped");
        }
        finally
        {
            controller.Stop("test");
            controller.DisposeAsync().AsTask().GetAwaiter().GetResult();
        }
    }

    private static void ControllerRestartBudgetIsBounded()
    {
        var backend = new RecordingSessionBackend(
            _ => new FakeRuntimeSession(healthy: false, viewerCount: 0));
        var controller = CreateController(
            backend,
            new FakeChatModeBridge(),
            maximumRestarts: 2);
        try
        {
            TestAssert.True(controller.Start().Accepted, "Streaming retry test did not start");
            WaitUntil(
                () => controller.Current.Status == StreamingRuntimeStatus.Error,
                "Streaming retry budget did not terminate in an error state");
            TestAssert.Equal(3, backend.Requests.Count, "Streaming retry budget changed");
            TestAssert.Equal(1, backend.MaximumActiveSessions, "Automatic retries overlapped sessions");
        }
        finally
        {
            controller.DisposeAsync().AsTask().GetAwaiter().GetResult();
        }
    }

    private static void ControllerChatCommandIsBounded()
    {
        var backend = new RecordingSessionBackend(
            _ => new FakeRuntimeSession(healthy: true, viewerCount: 1));
        var bridge = new FakeChatModeBridge(hangWhenEnabling: true);
        var controller = CreateController(
            backend,
            bridge,
            maximumRestarts: 0,
            chatCommandTimeout: TimeSpan.FromMilliseconds(40));
        try
        {
            controller.Start();
            WaitUntil(
                () => controller.Current.Status == StreamingRuntimeStatus.Online,
                "Chat timeout test stream did not become online");
            var stopwatch = Stopwatch.StartNew();
            var result = controller.SetChatMode(true);
            stopwatch.Stop();
            TestAssert.True(!result.Accepted, "Timed-out chat bridge command was accepted");
            TestAssert.Equal(
                "streaming_chat_command_timeout",
                result.Reason,
                "Chat bridge timeout reason changed");
            TestAssert.True(
                stopwatch.Elapsed < TimeSpan.FromSeconds(1),
                "Chat bridge command exceeded its bounded deadline");
        }
        finally
        {
            controller.Stop("test");
            controller.DisposeAsync().AsTask().GetAwaiter().GetResult();
        }
    }

    private static ContainedStreamingSessionBackend CreateContainedBackend(
        List<string> log,
        IStreamingProcessLauncher processLauncher,
        StreamingExecutableSet executables,
        StreamingNetworkDescriptor network) => new(
            new RecordingExecutableProvider(log, executables),
            new RecordingCaptureSource(log),
            new RecordingNetworkFactory(log, network),
            processLauncher,
            TestPolicy(maximumRestarts: 0));

    private static StreamingRuntimeController CreateController(
        IStreamingSessionBackend backend,
        FakeChatModeBridge bridge,
        int maximumRestarts,
        TimeSpan? chatCommandTimeout = null) => new(
            backend,
            bridge,
            snapshotModeEnabled: false,
            TestPolicy(maximumRestarts, chatCommandTimeout),
            eventDispatcher: action => action());

    private static StreamingRuntimePolicy TestPolicy(
        int maximumRestarts,
        TimeSpan? chatCommandTimeout = null) => new(
            StartupTimeout: TimeSpan.FromSeconds(5),
            CleanupTimeout: TimeSpan.FromSeconds(1),
            MonitorInterval: TimeSpan.FromMilliseconds(5),
            RestartDelay: TimeSpan.FromMilliseconds(1),
            MaximumRestartAttempts: maximumRestarts,
            NoViewerAutoStop: TimeSpan.FromMinutes(1),
            ChatCommandTimeout: chatCommandTimeout ?? TimeSpan.FromMilliseconds(100),
            MaximumTunnelDiagnosticLines: 8);

    private static StreamingSessionRequest SessionRequest(
        string quality = "720p",
        bool lowFps = false) => new(
            StreamingEncodingProfile.From(
                StreamingQualityCatalog.Require(quality),
                lowFps),
            ChatZoomEnabled: false);

    private static StreamingExecutableSet EmbeddedExecutableSet() => new(
        Path.GetFullPath("fake-ffmpeg.exe"),
        Path.GetFullPath("fake-cloudflared.exe"),
        StreamingExecutableOrigin.EmbeddedResource);

    private static StreamingNetworkDescriptor NetworkDescriptor(
        bool authenticationEnforced) => new(
            new Uri("http://127.0.0.1:4242/"),
            new Uri("http://127.0.0.1:4242/live/"),
            Path.GetFullPath("fake-media/live/index.m3u8"),
            "/live/",
            authenticationEnforced);

    private static string ArgumentAfter(IReadOnlyList<string> arguments, string name)
    {
        var index = arguments.ToList().IndexOf(name);
        if (index < 0 || index + 1 >= arguments.Count)
        {
            throw new InvalidOperationException($"Missing streaming argument {name}");
        }
        return arguments[index + 1];
    }

    private static void WaitUntil(Func<bool> predicate, string message)
    {
        TestAssert.True(
            SpinWait.SpinUntil(predicate, TimeSpan.FromSeconds(2)),
            message);
    }

    private sealed class RecordingExecutableProvider : IStreamingExecutableProvider
    {
        private readonly List<string> log;
        private readonly StreamingExecutableSet executables;

        internal RecordingExecutableProvider(
            List<string> log,
            StreamingExecutableSet executables)
        {
            this.log = log;
            this.executables = executables;
        }

        public ValueTask<IStreamingExecutableLease> AcquireAsync(
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            log.Add("tools.acquire");
            return ValueTask.FromResult<IStreamingExecutableLease>(
                new RecordingExecutableLease(log, executables));
        }
    }

    private sealed class RecordingExecutableLease : IStreamingExecutableLease
    {
        private readonly List<string> log;
        private bool disposed;

        internal RecordingExecutableLease(
            List<string> log,
            StreamingExecutableSet executables)
        {
            this.log = log;
            Executables = executables;
        }

        public StreamingExecutableSet Executables { get; }

        public ValueTask DisposeAsync()
        {
            if (!disposed)
            {
                log.Add("tools.dispose");
                disposed = true;
            }
            return ValueTask.CompletedTask;
        }
    }

    private sealed class RecordingCaptureSource : IStreamingCaptureSource
    {
        private readonly List<string> log;

        internal RecordingCaptureSource(List<string> log) => this.log = log;

        public ValueTask<StreamingCaptureDescriptor> ResolveAsync(
            bool chatZoomEnabled,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            log.Add($"capture.resolve:{chatZoomEnabled.ToString().ToLowerInvariant()}");
            return ValueTask.FromResult(new StreamingCaptureDescriptor(
                "fake-capture",
                "fake-input",
                ["-fake"]));
        }
    }

    private sealed class RecordingNetworkFactory : IStreamingNetworkSessionFactory
    {
        private readonly List<string> log;
        private readonly StreamingNetworkDescriptor descriptor;

        internal RecordingNetworkFactory(
            List<string> log,
            StreamingNetworkDescriptor descriptor)
        {
            this.log = log;
            this.descriptor = descriptor;
        }

        public ValueTask<IStreamingNetworkSession> StartAsync(
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            log.Add("network.start");
            return ValueTask.FromResult<IStreamingNetworkSession>(
                new RecordingNetworkSession(log, descriptor));
        }
    }

    private sealed class RecordingNetworkSession : IStreamingNetworkSession
    {
        private readonly List<string> log;
        private readonly TaskCompletionSource completion = new(
            TaskCreationOptions.RunContinuationsAsynchronously);
        private bool stopped;
        private bool disposed;

        internal RecordingNetworkSession(
            List<string> log,
            StreamingNetworkDescriptor descriptor)
        {
            this.log = log;
            Descriptor = descriptor;
        }

        public StreamingNetworkDescriptor Descriptor { get; }

        public Task Completion => completion.Task;

        public ValueTask WaitForMediaAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            log.Add("network.media");
            return ValueTask.CompletedTask;
        }

        public ValueTask<int> GetViewerCountAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            return ValueTask.FromResult(1);
        }

        public ValueTask StopAsync(TimeSpan timeout, CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            if (!stopped)
            {
                log.Add("network.stop");
                completion.TrySetResult();
                stopped = true;
            }
            return ValueTask.CompletedTask;
        }

        public ValueTask DisposeAsync()
        {
            if (!disposed)
            {
                log.Add("network.dispose");
                disposed = true;
            }
            return ValueTask.CompletedTask;
        }
    }

    private sealed class RecordingProcessLauncher : IStreamingProcessLauncher
    {
        private readonly List<string> log;
        private readonly bool tunnelEndpointAvailable;

        internal RecordingProcessLauncher(
            List<string> log,
            bool tunnelEndpointAvailable)
        {
            this.log = log;
            this.tunnelEndpointAvailable = tunnelEndpointAvailable;
        }

        public ValueTask<IStreamingProcessLease> StartAsync(
            StreamingProcessRequest request,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            var role = request.Role == StreamingProcessRole.Encoder ? "encoder" : "tunnel";
            log.Add($"{role}.start");
            return ValueTask.FromResult<IStreamingProcessLease>(
                new RecordingProcessLease(log, request.Role, tunnelEndpointAvailable));
        }
    }

    private sealed class RecordingProcessLease : IStreamingProcessLease
    {
        private readonly List<string> log;
        private readonly Queue<string> diagnostics;
        private readonly TaskCompletionSource<StreamingProcessExit> completion = new(
            TaskCreationOptions.RunContinuationsAsynchronously);
        private bool stopped;
        private bool disposed;

        internal RecordingProcessLease(
            List<string> log,
            StreamingProcessRole role,
            bool tunnelEndpointAvailable)
        {
            this.log = log;
            Role = role;
            diagnostics = role == StreamingProcessRole.Tunnel && tunnelEndpointAvailable
                ? new Queue<string>(["INF https://viewer.example.test"])
                : new Queue<string>();
        }

        public StreamingProcessRole Role { get; }

        public Task<StreamingProcessExit> Completion => completion.Task;

        public ValueTask<string?> ReadDiagnosticLineAsync(
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            log.Add("tunnel.read");
            return ValueTask.FromResult(
                diagnostics.Count == 0 ? null : diagnostics.Dequeue());
        }

        public ValueTask StopAsync(TimeSpan timeout, CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            if (!stopped)
            {
                log.Add($"{RoleName}.stop");
                completion.TrySetResult(new StreamingProcessExit(0));
                stopped = true;
            }
            return ValueTask.CompletedTask;
        }

        public ValueTask DisposeAsync()
        {
            if (!disposed)
            {
                log.Add($"{RoleName}.dispose");
                disposed = true;
            }
            return ValueTask.CompletedTask;
        }

        private string RoleName => Role == StreamingProcessRole.Encoder ? "encoder" : "tunnel";
    }

    private sealed class RecordingSessionBackend : IStreamingSessionBackend
    {
        private readonly Func<StreamingSessionRequest, FakeRuntimeSession> sessionFactory;
        private int activeSessions;

        internal RecordingSessionBackend(
            Func<StreamingSessionRequest, FakeRuntimeSession> sessionFactory) =>
            this.sessionFactory = sessionFactory;

        internal ConcurrentQueue<StreamingSessionRequest> Requests { get; } = new();

        internal ConcurrentQueue<FakeRuntimeSession> Sessions { get; } = new();

        internal int MaximumActiveSessions { get; private set; }

        public ValueTask<IStreamingRuntimeSession> StartAsync(
            StreamingSessionRequest request,
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            var active = Interlocked.Increment(ref activeSessions);
            MaximumActiveSessions = Math.Max(MaximumActiveSessions, active);
            Requests.Enqueue(request);
            var session = sessionFactory(request);
            session.OnStopped = () => Interlocked.Decrement(ref activeSessions);
            Sessions.Enqueue(session);
            return ValueTask.FromResult<IStreamingRuntimeSession>(session);
        }
    }

    private sealed class BlockingSessionBackend : IStreamingSessionBackend
    {
        internal TaskCompletionSource Started { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        internal TaskCompletionSource Canceled { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        internal CancellationToken ObservedToken { get; private set; }

        public async ValueTask<IStreamingRuntimeSession> StartAsync(
            StreamingSessionRequest request,
            CancellationToken cancellationToken)
        {
            ObservedToken = cancellationToken;
            using var registration = cancellationToken.Register(
                () => Canceled.TrySetResult());
            Started.TrySetResult();
            try
            {
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken)
                    .ConfigureAwait(false);
            }
            catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
            {
                throw;
            }
            throw new InvalidOperationException("unreachable_fake_start");
        }
    }

    private sealed class FakeRuntimeSession : IStreamingRuntimeSession
    {
        private readonly bool healthy;
        private readonly int viewerCount;
        private int stopped;

        internal FakeRuntimeSession(bool healthy, int viewerCount)
        {
            this.healthy = healthy;
            this.viewerCount = viewerCount;
        }

        internal Action? OnStopped { get; set; }

        internal bool Stopped => Volatile.Read(ref stopped) != 0;

        public Uri LocalUri { get; } = new("http://127.0.0.1:4242/live/");

        public Uri PublicUri { get; } = new("https://viewer.example.test/");

        public Uri StreamUri { get; } = new("https://viewer.example.test/live/");

        public async ValueTask<StreamingSessionObservation> ObserveAsync(
            TimeSpan interval,
            CancellationToken cancellationToken)
        {
            await Task.Delay(interval, cancellationToken).ConfigureAwait(false);
            return new StreamingSessionObservation(
                healthy,
                viewerCount,
                healthy ? string.Empty : "streaming_fake_component_exited");
        }

        public ValueTask StopAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            if (Interlocked.Exchange(ref stopped, 1) == 0)
            {
                OnStopped?.Invoke();
            }
            return ValueTask.CompletedTask;
        }

        public ValueTask DisposeAsync() => StopAsync(CancellationToken.None);
    }

    private sealed class FakeChatModeBridge : IStreamingChatModeBridge
    {
        private readonly bool hangWhenEnabling;

        internal FakeChatModeBridge(bool hangWhenEnabling = false) =>
            this.hangWhenEnabling = hangWhenEnabling;

        public async ValueTask<StreamingChatModeResult> SetEnabledAsync(
            bool enabled,
            CancellationToken cancellationToken)
        {
            if (enabled && hangWhenEnabling)
            {
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken)
                    .ConfigureAwait(false);
            }
            return new StreamingChatModeResult(enabled, "accepted");
        }
    }
}
