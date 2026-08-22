using System.Net;
using System.Net.Http;
using System.Text;
using System.Text.Json;
using System.Windows;
using System.Windows.Controls;
using Sonar.Fishing.Host.StartupGate;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.Tests;

internal static class StartupBlockGateTests
{
    private const string PublicKeyHex =
        "03a107bff3ce10be1d70dd18e74bc09967e4d6309ba50d5f1ddc8664125531b8";
    private const string AllowedSignature =
        "DbxFOnybwfWHVXDanbNBiam9HHJAnzuajA8kZcHcABRX0h0FnJ0foMM99SPujqouQcCTPueARDaInNf3DohlAg";
    private const string BlockedSignature =
        "L5LPIdvE-sOSqlhCbRX0IidYFexVuN9I3WGrrzjuhlBNySTzFfYJXIAsm1Vh_JD-d6WggHIBDUIKSE4t7UP1Cw";
    private const string UnsafeUrlSignature =
        "3Y4lGsOO2iffEiDCXCYe-qlIlCU7mkYGtxbKPS7GewnxOu4FibT72gDMe6z1iG9HUvij--3ZB4w2FHYLQY7RBg";

    public static IReadOnlyList<TestCase> Create() =>
    [
        new("startup_block_verifier_accepts_fixed_ed25519_parity_vectors", ValidSignaturesMatch),
        new("startup_block_verifier_rejects_tampering_and_unsafe_navigation", InvalidResponsesFailClosed),
        new("startup_block_client_preserves_branding_and_build_contract", HttpRequestMatches),
        new("startup_block_client_bounds_response_and_maps_transport_failures", HttpFailuresAreStable),
        new("startup_block_client_propagates_caller_cancellation", CallerCancellationPropagates),
        new("startup_block_request_redacts_identity_and_rejects_unsafe_headers", RequestIsBoundedAndRedacted),
        new("production_startup_policy_hashes_current_native_host_and_pins_trust", ProductionPolicyIsPinned),
        new("startup_admission_is_fail_closed_only_at_initial_launch", AdmissionPolicyMatches),
        new("startup_admission_coordinator_projects_checked_and_failed_states", AdmissionCoordinatorProjects),
        new("startup_runtime_monitor_ignores_transient_failures_and_stops_once", RuntimeMonitorMatches),
        new("startup_admission_view_model_opens_only_signed_https_target", AdmissionViewModelNavigatesSafely),
        new("startup_admission_screen_uses_common_surface_and_actions", AdmissionScreenUsesCommonComposition),
    ];

    private static void ValidSignaturesMatch()
    {
        var verifier = new StartupBlockResponseVerifier(PublicKeyHex);

        var allowed = verifier.Verify(Response(false, string.Empty, AllowedSignature));
        TestAssert.True(allowed.Checked, "Signed allowed response was not checked");
        TestAssert.True(!allowed.Blocked, "Signed allowed response was blocked");
        TestAssert.Equal(string.Empty, allowed.Error, "Signed allowed response has an error");

        var blocked = verifier.Verify(Response(
            true,
            "https://m-sonar-addr.ru/download",
            BlockedSignature));
        TestAssert.True(blocked.Checked, "Signed blocked response was not checked");
        TestAssert.True(blocked.Blocked, "Signed blocked response was not enforced");
        TestAssert.Equal(
            "https://m-sonar-addr.ru/download",
            blocked.DownloadUrl,
            "Signed download URL changed");
    }

    private static void InvalidResponsesFailClosed()
    {
        var verifier = new StartupBlockResponseVerifier(PublicKeyHex);

        var tampered = verifier.Verify(Response(
            true,
            "https://m-sonar-addr.ru/other",
            BlockedSignature));
        TestAssert.True(!tampered.Checked, "Tampered response was trusted");
        TestAssert.Equal(
            "startup_block_signature_invalid",
            tampered.Error,
            "Tampered response reason changed");

        var unsafeUrl = verifier.Verify(Response(
            true,
            "http://unsafe.example/file",
            UnsafeUrlSignature));
        TestAssert.True(unsafeUrl.Checked, "Signed unsafe URL lost its checked state");
        TestAssert.True(!unsafeUrl.Blocked, "Unsafe navigation target became actionable");
        TestAssert.Equal(
            "startup_block_download_url_invalid",
            unsafeUrl.Error,
            "Unsafe URL reason changed");

        var malformed = verifier.Verify("[]"u8);
        TestAssert.True(!malformed.Checked, "Malformed response was trusted");
        TestAssert.Equal(
            "startup_block_response_contract_invalid",
            malformed.Error,
            "Malformed response reason changed");
    }

    private static void HttpRequestMatches()
    {
        CapturedRequest? captured = null;
        using var client = Client(async (request, cancellationToken) =>
        {
            captured = await CaptureAsync(request, cancellationToken);
            return JsonResponse(Response(false, string.Empty, AllowedSignature));
        });
        var check = new StartupBlockHttpClient(
            client,
            new Uri("https://checks.example/api/startup-block"),
            new StartupBlockResponseVerifier(PublicKeyHex));
        var request = new StartupBlockRequest(
            "Tom Clancy’s The Division® 2",
            "build-hash",
            "build-key",
            "LICENSE-KEY");

        var status = check.CheckAsync(request, CancellationToken.None).GetAwaiter().GetResult();

        TestAssert.True(status.Checked && !status.Blocked, "Valid HTTP response was not accepted");
        TestAssert.Equal(HttpMethod.Post, captured!.Method, "Startup check did not use POST");
        TestAssert.Equal(
            "https://checks.example/api/startup-block",
            captured.Uri.AbsoluteUri,
            "Startup endpoint changed");
        TestAssert.True(
            captured.UserAgent.All(character => character <= 0x7f),
            "Startup User-Agent is not ASCII");
        TestAssert.True(
            captured.UserAgent.Contains("Tom Clancys The Division 2", StringComparison.Ordinal),
            "ASCII branding was not preserved in User-Agent");
        TestAssert.Equal("build-key", captured.BuildKeyHeader, "Build key header changed");
        TestAssert.Equal("application/json", captured.MediaType, "Startup request media type changed");
        TestAssert.Equal<long>(
            captured.Body.LongLength,
            captured.ContentLength,
            "Startup request must carry an explicit bounded Content-Length");
        using var body = JsonDocument.Parse(captured.Body);
        var root = body.RootElement;
        TestAssert.Equal(
            "Tom Clancy’s The Division® 2",
            root.GetProperty("app_name").GetString()!,
            "Product branding changed in JSON");
        TestAssert.Equal("build-hash", root.GetProperty("build_hash").GetString()!, "Build hash changed");
        TestAssert.Equal("build-key", root.GetProperty("build_key").GetString()!, "Build key changed");
        TestAssert.Equal("LICENSE-KEY", root.GetProperty("license_key").GetString()!, "License key changed");
    }

    private static void ProductionPolicyIsPinned()
    {
        var executable = Environment.ProcessPath ??
            throw new InvalidOperationException("Test process path is unavailable");
        var request = FishingProductionStartupPolicy.CreateRequest(
            executable,
            "LICENSE-KEY");

        TestAssert.Equal("Sonar", request.AppName, "Production app identity changed");
        TestAssert.True(
            request.BuildHash.Length == 64 &&
            request.BuildHash.All(character => char.IsDigit(character) || character is >= 'A' and <= 'F'),
            "Production build hash is not canonical SHA-256");
        TestAssert.Equal(
            "sonar-native-wpf-cpp-v1",
            request.BuildKey,
            "Production native build family changed");
        TestAssert.Equal("LICENSE-KEY", request.LicenseKey, "Startup license identity changed");
        TestAssert.Equal(
            "https://m-sonar-addr.ru/api/startup-block",
            FishingProductionStartupPolicy.Endpoint.AbsoluteUri,
            "Production startup endpoint changed");
        TestAssert.True(
            FishingProductionStartupPolicy.PublicKey.Length == 64,
            "Production startup public key is not Ed25519-sized");
    }

    private static void HttpFailuresAreStable()
    {
        var verifier = new StartupBlockResponseVerifier(PublicKeyHex);
        var request = Request();

        using (var rejectedClient = Client((_, _) => Task.FromResult(
            new HttpResponseMessage(HttpStatusCode.ServiceUnavailable))))
        {
            var status = new StartupBlockHttpClient(
                rejectedClient,
                new Uri("https://checks.example/api/startup-block"),
                verifier).CheckAsync(request, CancellationToken.None).GetAwaiter().GetResult();
            TestAssert.Equal("startup_block_http_rejected", status.Error, "HTTP rejection reason changed");
        }

        using (var oversizedClient = Client((_, _) => Task.FromResult(
            new HttpResponseMessage(HttpStatusCode.OK)
            {
                Content = new ByteArrayContent(
                    new byte[StartupBlockResponseVerifier.MaximumResponseBytes + 1]),
            })))
        {
            var status = new StartupBlockHttpClient(
                oversizedClient,
                new Uri("https://checks.example/api/startup-block"),
                verifier).CheckAsync(request, CancellationToken.None).GetAwaiter().GetResult();
            TestAssert.Equal("startup_block_response_size_invalid", status.Error, "Response bound changed");
        }

        using (var failedClient = Client((_, _) =>
            throw new HttpRequestException("LICENSE-KEY build-key unsafe transport detail")))
        {
            var status = new StartupBlockHttpClient(
                failedClient,
                new Uri("https://checks.example/api/startup-block"),
                verifier).CheckAsync(request, CancellationToken.None).GetAwaiter().GetResult();
            TestAssert.Equal("startup_block_http_unavailable", status.Error, "Transport reason changed");
            TestAssert.True(
                !status.ToString().Contains("LICENSE-KEY", StringComparison.Ordinal),
                "Transport detail leaked into status");
        }

        using var timeoutClient = Client(WaitUntilCancelledAsync);
        var timedOut = new StartupBlockHttpClient(
            timeoutClient,
            new Uri("https://checks.example/api/startup-block"),
            verifier,
            TimeSpan.FromMilliseconds(25))
            .CheckAsync(request, CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal("startup_block_timeout", timedOut.Error, "Timeout reason changed");
    }

    private static void CallerCancellationPropagates()
    {
        using var cancellation = new CancellationTokenSource();
        cancellation.Cancel();
        using var client = Client(WaitUntilCancelledAsync);
        var check = new StartupBlockHttpClient(
            client,
            new Uri("https://checks.example/api/startup-block"),
            new StartupBlockResponseVerifier(PublicKeyHex));

        TestAssert.Throws<OperationCanceledException>(
            () => check.CheckAsync(Request(), cancellation.Token).GetAwaiter().GetResult(),
            "Caller cancellation was converted into a network failure");
    }

    private static void RequestIsBoundedAndRedacted()
    {
        var request = Request();
        var text = request.ToString();
        TestAssert.True(!text.Contains("LICENSE-KEY", StringComparison.Ordinal), "License key leaked");
        TestAssert.True(!text.Contains("build-key", StringComparison.Ordinal), "Build key leaked");
        TestAssert.True(!text.Contains("build-hash", StringComparison.Ordinal), "Build hash leaked");

        TestAssert.Throws<ArgumentException>(
            () => new StartupBlockRequest("Sonar", "hash", "ключ", "license"),
            "Non-ASCII build identity reached HTTP headers");
        TestAssert.Throws<ArgumentException>(
            () => new StartupBlockRequest("Sonar\r\nInjected", "hash", "key", "license"),
            "Header injection reached the request boundary");
        TestAssert.Throws<ArgumentException>(
            () => new StartupBlockResponseVerifier(new byte[31]),
            "Invalid Ed25519 key length was accepted");
        TestAssert.Throws<ArgumentException>(
            () => new StartupBlockHttpClient(
                new HttpClient(),
                new Uri("http://checks.example/api/startup-block"),
                new StartupBlockResponseVerifier(PublicKeyHex)),
            "Plain HTTP startup endpoint was accepted");
    }

    private static void AdmissionPolicyMatches()
    {
        var allowed = StartupAdmissionPolicy.InitialLaunch(
            new StartupBlockStatus(true, false, string.Empty, string.Empty));
        TestAssert.Equal(StartupAdmissionKind.Allowed, allowed.Kind, "Allowed startup was rejected");
        TestAssert.True(allowed.CanCreateMainWindow, "Allowed startup cannot create main window");

        var unavailable = StartupAdmissionPolicy.InitialLaunch(
            StartupBlockStatus.Failure("startup_block_http_unavailable"));
        TestAssert.Equal(StartupAdmissionKind.Unavailable, unavailable.Kind, "Initial failure did not fail closed");
        TestAssert.True(!unavailable.CanCreateMainWindow, "Unavailable startup can create main window");

        var blockedStatus = new StartupBlockStatus(
            true,
            true,
            "https://m-sonar-addr.ru/download",
            string.Empty);
        var blocked = StartupAdmissionPolicy.InitialLaunch(blockedStatus);
        TestAssert.Equal(StartupAdmissionKind.Blocked, blocked.Kind, "Signed block was not enforced");
        TestAssert.True(
            StartupAdmissionPolicy.MustStopRunningApplication(blockedStatus),
            "Runtime signed block did not stop the application");
        TestAssert.True(
            !StartupAdmissionPolicy.MustStopRunningApplication(
                StartupBlockStatus.Failure("startup_block_timeout")),
            "Transient runtime failure stopped the application");
    }

    private static void AdmissionCoordinatorProjects()
    {
        var blockedStatus = new StartupBlockStatus(
            true,
            true,
            "https://m-sonar-addr.ru/download",
            string.Empty);
        var blockedViewModel = new StartupAdmissionViewModel(_ => { }, () => { });
        var blocked = new StartupAdmissionCoordinator(
            new FixedStartupBlockCheck(blockedStatus),
            Request(),
            blockedViewModel).CheckInitialAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(StartupAdmissionKind.Blocked, blocked.Kind, "Coordinator lost signed block");
        TestAssert.Equal(
            StartupAdmissionPhase.Blocked,
            blockedViewModel.Phase,
            "Signed block was not projected into startup UI");

        var failedViewModel = new StartupAdmissionViewModel();
        var failed = new StartupAdmissionCoordinator(
            new ThrowingStartupBlockCheck(),
            Request(),
            failedViewModel).CheckInitialAsync(CancellationToken.None).GetAwaiter().GetResult();
        TestAssert.Equal(StartupAdmissionKind.Unavailable, failed.Kind, "Unexpected check error did not fail closed");
        TestAssert.Equal(
            "startup_block_check_failed",
            failed.Reason,
            "Unexpected check error leaked unstable detail");
        TestAssert.Equal(
            StartupAdmissionPhase.Unavailable,
            failedViewModel.Phase,
            "Failed initial check was not projected");
    }

    private static void RuntimeMonitorMatches()
    {
        var check = new SequenceStartupBlockCheck(
        [
            StartupBlockStatus.Failure("startup_block_http_unavailable"),
            new StartupBlockStatus(true, false, string.Empty, string.Empty),
            new StartupBlockStatus(
                true,
                true,
                "https://m-sonar-addr.ru/download",
                string.Empty),
        ]);
        var delayCount = 0;
        var blockCount = 0;
        var monitor = new StartupBlockRuntimeMonitor(
            check,
            Request,
            (status, cancellationToken) =>
            {
                cancellationToken.ThrowIfCancellationRequested();
                TestAssert.True(status.Blocked, "Runtime handler received a non-blocking status");
                blockCount++;
                return Task.CompletedTask;
            },
            TimeSpan.FromSeconds(1),
            (_, cancellationToken) =>
            {
                cancellationToken.ThrowIfCancellationRequested();
                delayCount++;
                return Task.CompletedTask;
            });

        monitor.RunAsync(CancellationToken.None).GetAwaiter().GetResult();

        TestAssert.Equal(3, check.CallCount, "Runtime monitor did not preserve sequential polling");
        TestAssert.Equal(3, delayCount, "Runtime monitor interval count changed");
        TestAssert.Equal(1, blockCount, "Runtime signed block handler was not exactly once");
    }

    private static void AdmissionViewModelNavigatesSafely()
    {
        Uri? opened = null;
        var viewModel = new StartupAdmissionViewModel(uri => opened = uri, () => { });
        viewModel.Apply(new StartupAdmissionDecision(
            StartupAdmissionKind.Blocked,
            "https://m-sonar-addr.ru/download",
            "startup_blocked"));

        TestAssert.True(viewModel.CanDownload, "Signed HTTPS download was not actionable");
        TestAssert.True(viewModel.DownloadCommand.CanExecute(null), "Download command was disabled");
        viewModel.DownloadCommand.Execute(null);
        TestAssert.Equal(
            "https://m-sonar-addr.ru/download",
            opened!.AbsoluteUri,
            "Startup UI opened another target");

        viewModel.Apply(new StartupAdmissionDecision(
            StartupAdmissionKind.Blocked,
            "https://user:password@unsafe.example/file",
            "startup_blocked"));
        TestAssert.Equal(
            StartupAdmissionPhase.Unavailable,
            viewModel.Phase,
            "Unsafe navigation target remained in blocked UI");
        TestAssert.True(!viewModel.CanDownload, "Unsafe navigation target remained actionable");
        TestAssert.True(!viewModel.DownloadCommand.CanExecute(null), "Unsafe download command stayed enabled");
    }

    private static void AdmissionScreenUsesCommonComposition()
    {
        var viewModel = new StartupAdmissionViewModel(_ => { }, () => { });
        viewModel.Apply(new StartupAdmissionDecision(
            StartupAdmissionKind.Blocked,
            "https://m-sonar-addr.ru/download",
            "startup_blocked"));
        var screen = new StartupAdmissionScreen { ViewModel = viewModel };
        screen.Measure(new Size(640, 400));
        screen.Arrange(new Rect(0, 0, 640, 400));
        screen.UpdateLayout();

        _ = TestAssert.IsType<Card>(
            screen.FindName("StartupAdmissionCard"),
            "Startup surface is not a Common Card");
        var progress = TestAssert.IsType<ProgressBar>(
            screen.FindName("StartupAdmissionProgress"),
            "Startup loading indicator is missing");
        var download = TestAssert.IsType<ActionButton>(
            screen.FindName("StartupDownloadButton"),
            "Startup primary download action is missing");
        _ = TestAssert.IsType<ActionButton>(
            screen.FindName("StartupCloseButton"),
            "Startup close action is missing");
        TestAssert.Equal(
            ActionButtonRole.Primary,
            download.Role,
            "Startup download action lost Primary styling");
        TestAssert.True(
            progress.Visibility == Visibility.Collapsed,
            "Startup progress remained visible after a decision");
    }

    private static StartupBlockRequest Request() => new(
        "Sonar",
        "build-hash",
        "build-key",
        "LICENSE-KEY");

    private static byte[] Response(bool blocked, string downloadUrl, string signature) =>
        JsonSerializer.SerializeToUtf8Bytes(new
        {
            blocked,
            download_url = downloadUrl,
            signature,
        });

    private static HttpResponseMessage JsonResponse(byte[] utf8Json) => new(HttpStatusCode.OK)
    {
        Content = new ByteArrayContent(utf8Json)
        {
            Headers = { ContentType = new System.Net.Http.Headers.MediaTypeHeaderValue("application/json") },
        },
    };

    private static HttpClient Client(
        Func<HttpRequestMessage, CancellationToken, Task<HttpResponseMessage>> responder) =>
        new(new DelegateHandler(responder))
        {
            Timeout = Timeout.InfiniteTimeSpan,
        };

    private static async Task<CapturedRequest> CaptureAsync(
        HttpRequestMessage request,
        CancellationToken cancellationToken) =>
        new(
            request.Method,
            request.RequestUri!,
            request.Headers.UserAgent.ToString(),
            request.Headers.TryGetValues("X-Sonar-Build-Key", out var values)
                ? values.Single()
                : string.Empty,
            request.Content?.Headers.ContentType?.MediaType ?? string.Empty,
            request.Content?.Headers.ContentLength ?? -1,
            request.Content is null
                ? Array.Empty<byte>()
                : await request.Content.ReadAsByteArrayAsync(cancellationToken));

    private static async Task<HttpResponseMessage> WaitUntilCancelledAsync(
        HttpRequestMessage request,
        CancellationToken cancellationToken)
    {
        _ = request;
        await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken);
        throw new InvalidOperationException("Cancellation wait completed unexpectedly");
    }

    private sealed record CapturedRequest(
        HttpMethod Method,
        Uri Uri,
        string UserAgent,
        string BuildKeyHeader,
        string MediaType,
        long ContentLength,
        byte[] Body);

    private sealed class DelegateHandler(
        Func<HttpRequestMessage, CancellationToken, Task<HttpResponseMessage>> responder)
        : HttpMessageHandler
    {
        protected override Task<HttpResponseMessage> SendAsync(
            HttpRequestMessage request,
            CancellationToken cancellationToken) => responder(request, cancellationToken);
    }

    private sealed class FixedStartupBlockCheck(StartupBlockStatus status) : IStartupBlockCheck
    {
        public Task<StartupBlockStatus> CheckAsync(
            StartupBlockRequest request,
            CancellationToken cancellationToken)
        {
            _ = request;
            cancellationToken.ThrowIfCancellationRequested();
            return Task.FromResult(status);
        }
    }

    private sealed class ThrowingStartupBlockCheck : IStartupBlockCheck
    {
        public Task<StartupBlockStatus> CheckAsync(
            StartupBlockRequest request,
            CancellationToken cancellationToken)
        {
            _ = request;
            cancellationToken.ThrowIfCancellationRequested();
            throw new InvalidOperationException("LICENSE-KEY unsafe detail");
        }
    }

    private sealed class SequenceStartupBlockCheck(IReadOnlyList<StartupBlockStatus> statuses)
        : IStartupBlockCheck
    {
        public int CallCount { get; private set; }

        public Task<StartupBlockStatus> CheckAsync(
            StartupBlockRequest request,
            CancellationToken cancellationToken)
        {
            _ = request;
            cancellationToken.ThrowIfCancellationRequested();
            if (CallCount >= statuses.Count)
            {
                throw new InvalidOperationException("startup_block_test_sequence_exhausted");
            }
            return Task.FromResult(statuses[CallCount++]);
        }
    }
}
