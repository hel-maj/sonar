using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.HostRuntime;
using Sonar.Fishing.Host.HostHotkeys;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.Shell;
using Sonar.Fishing.Host.TelegramPage;
using System.Diagnostics;
using System.Windows.Threading;

namespace Sonar.Fishing.Host.Tests;

internal static class HostRuntimeTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("host_defaults_to_production_and_keeps_explicit_dev_modes", RunModeDefaultsToProduction),
        new("demo_composition_never_starts_engine_health_use_case", DemoCompositionIsInert),
        new("host_composition_retains_validated_state", CompositionRetainsState),
        new("offline_health_maps_real_containment_receipt", OfflineHealthMapsReceipt),
        new("host_lifecycle_cancels_inflight_engine_health", LifecycleCancelsHealth),
        new("host_lifecycle_disposes_long_lived_engine_session", LifecycleDisposesSession),
        new("host_lifecycle_starts_and_stops_telegram_runtime_exactly_once", LifecycleOwnsTelegram),
        new("host_lifecycle_starts_and_stops_license_runtime_exactly_once", LifecycleOwnsLicense),
        new("host_lifecycle_starts_and_stops_hotkey_runtime_exactly_once", LifecycleOwnsHotkeys),
        new("host_lifecycle_stop_before_content_render_never_restarts_runtime", LifecycleStopBeforeStartIsTerminal),
        new("host_lifecycle_concurrent_start_stop_is_terminal_and_idempotent", LifecycleConcurrentStartStopIsIdempotent),
        new("host_window_start_fault_exits_nonzero_without_unhandled_exception", WindowStartFaultExitsNonzero),
        new("host_window_defers_second_close_after_synchronous_stop", WindowDefersSecondClose),
        new("host_window_stop_fault_exits_nonzero_without_hanging", WindowStopFaultExitsNonzero),
        new("host_window_stop_timeout_exits_nonzero_without_hanging", WindowStopTimeoutExitsNonzero),
        new("common_job_terminates_contained_engine_on_host_dispose", ContainedEngineStopsWithHost),
        new("wpf_host_assembly_has_real_entrypoint", HostAssemblyHasEntryPoint),
    ];

    private static void RunModeDefaultsToProduction()
    {
        var production = HostRunOptions.Parse(Array.Empty<string>());
        TestAssert.Equal(HostRunMode.Production, production.Mode, "Default product mode changed");
        TestAssert.True(production.EngineExecutable is null, "Production mode retained a dev Engine path");
#if SONAR_FISHING_DEVELOPER_FULL_ACCESS
        var developer = HostRunOptions.Parse(["--developer-full-access"]);
        TestAssert.Equal(
            HostRunMode.DeveloperFullAccess,
            developer.Mode,
            "Compiled developer authority mode was not accepted");
#else
        TestAssert.Throws<HostRunOptionsException>(
            () => HostRunOptions.Parse(["--developer-full-access"]),
            "Production Host accepted developer authority arguments");
#endif
        try
        {
            _ = HostRunOptions.Parse(["--offline-engine"]);
            throw new InvalidOperationException("Offline mode accepted a missing Engine path");
        }
        catch (HostRunOptionsException exception)
        {
            TestAssert.True(
                !exception.Message.Contains("--", StringComparison.Ordinal) &&
                !exception.Message.Contains("Engine", StringComparison.OrdinalIgnoreCase),
                "User-facing run error exposed developer flags or process topology");
        }

        var demo = HostRunOptions.Parse(["--demo"]);
        TestAssert.Equal(HostRunMode.Demo, demo.Mode, "Demo mode changed");
        TestAssert.True(demo.EngineExecutable is null, "Demo mode retained an Engine path");

        var offline = HostRunOptions.Parse(["--offline-engine", "engine.exe"]);
        TestAssert.Equal(HostRunMode.OfflineEngine, offline.Mode, "Offline mode changed");
        TestAssert.Equal("engine.exe", offline.EngineExecutable!, "Engine path changed");

        try
        {
            _ = HostApplicationComposition.Create(
                new HostRunOptions(HostRunMode.OfflineEngine, null),
                FishingHostState.Default);
            throw new InvalidOperationException("Offline composition accepted a missing file path");
        }
        catch (HostRunOptionsException exception)
        {
            TestAssert.True(
                !exception.Message.Contains("Engine", StringComparison.OrdinalIgnoreCase) &&
                !exception.Message.Contains("Host", StringComparison.OrdinalIgnoreCase),
                "User-facing composition error exposed process topology");
        }
    }

    private static void DemoCompositionIsInert()
    {
        var composition = HostApplicationComposition.Create(
            new HostRunOptions(HostRunMode.Demo, null),
            FishingHostState.Default);
        composition.Lifecycle.StartAsync().GetAwaiter().GetResult();
        composition.Lifecycle.StopAsync().GetAwaiter().GetResult();

        TestAssert.Equal(
            FishingHostPage.License,
            composition.Shell.SelectedPage,
            "Demo composition did not open the required License page");
        TestAssert.Equal("Предпросмотр", composition.Shell.ModeText, "Preview mode label changed");
    }

    private static void CompositionRetainsState()
    {
        var state = FishingHostState.Default with
        {
            Fishing = FishingRuntimeSettings.CreateDefault(revision: 8),
        };
        var composition = HostApplicationComposition.Create(
            new HostRunOptions(HostRunMode.Demo, null),
            state);

        TestAssert.True(
            ReferenceEquals(state, composition.State),
            "Host composition copied or discarded the validated startup state");
        TestAssert.Equal<ulong>(
            8,
            composition.State.Fishing.Revision,
            "Host composition changed the persisted settings revision");
    }

    private static void OfflineHealthMapsReceipt()
    {
        var fake = new SuccessfulHealthUseCase();
        var viewModel = EngineHealthViewModel.CreateOffline(fake);
        var lifecycle = new HostLifecycleCoordinator(viewModel);

        lifecycle.StartAsync().GetAwaiter().GetResult();
        lifecycle.StartAsync().GetAwaiter().GetResult();

        TestAssert.Equal(1, fake.CallCount, "Host lifecycle started the Engine health session twice");
        TestAssert.Equal(EngineHealthPhase.Healthy, viewModel.Phase, "Healthy receipt was not mapped");
        TestAssert.Equal("Готово", viewModel.BadgeText, "Healthy badge changed");
        TestAssert.Equal(
            "Все необходимые компоненты доступны.",
            viewModel.Description,
            "Healthy user guidance changed");
        VisibleCopyAudit.AssertText(viewModel.Title, "application-check/title");
        VisibleCopyAudit.AssertText(viewModel.Description, "application-check/description");
    }

    private static void LifecycleCancelsHealth()
    {
        var fake = new BlockingHealthUseCase();
        var viewModel = EngineHealthViewModel.CreateOffline(fake);
        var lifecycle = new HostLifecycleCoordinator(viewModel);

        var startup = lifecycle.StartAsync();
        TestAssert.True(
            fake.Started.Task.Wait(TimeSpan.FromSeconds(2)),
            "Fake Engine health use case did not start");
        lifecycle.StopAsync().GetAwaiter().GetResult();
        startup.GetAwaiter().GetResult();

        TestAssert.True(fake.CancellationObserved, "Host close did not cancel Engine health");
        TestAssert.Equal(EngineHealthPhase.Cancelled, viewModel.Phase, "Cancelled state was lost");
    }

    private static void LifecycleDisposesSession()
    {
        var fake = new DisposableHealthUseCase();
        var viewModel = EngineHealthViewModel.CreateOffline(fake);
        var lifecycle = new HostLifecycleCoordinator(viewModel);

        lifecycle.StartAsync().GetAwaiter().GetResult();
        lifecycle.StopAsync().GetAwaiter().GetResult();
        lifecycle.StopAsync().GetAwaiter().GetResult();

        TestAssert.Equal(1, fake.DisposeCount, "Host did not dispose the long-lived Engine session exactly once");
    }

    private static void LifecycleOwnsTelegram()
    {
        var health = EngineHealthViewModel.CreateOffline(new SuccessfulHealthUseCase());
        var telegram = new FakeTelegramRuntimeLifecycle();
        var lifecycle = new HostLifecycleCoordinator(health, telegram);

        lifecycle.StartAsync().GetAwaiter().GetResult();
        lifecycle.StartAsync().GetAwaiter().GetResult();
        lifecycle.StopAsync().GetAwaiter().GetResult();
        lifecycle.StopAsync().GetAwaiter().GetResult();

        TestAssert.Equal(1, telegram.StartCount, "Telegram runtime started more than once");
        TestAssert.Equal(1, telegram.StopCount, "Telegram runtime stopped more than once");
    }

    private static void LifecycleOwnsLicense()
    {
        var health = EngineHealthViewModel.CreateOffline(new SuccessfulHealthUseCase());
        var license = new FakeLicenseRuntimeLifecycle();
        var lifecycle = new HostLifecycleCoordinator(health, license: license);

        lifecycle.StartAsync().GetAwaiter().GetResult();
        lifecycle.StartAsync().GetAwaiter().GetResult();
        lifecycle.StopAsync().GetAwaiter().GetResult();
        lifecycle.StopAsync().GetAwaiter().GetResult();

        TestAssert.Equal(1, license.StartCount, "License runtime started more than once");
        TestAssert.Equal(1, license.StopCount, "License runtime stopped more than once");
    }

    private static void LifecycleOwnsHotkeys()
    {
        var health = EngineHealthViewModel.CreateOffline(new SuccessfulHealthUseCase());
        var hotkeys = new FakeHotkeyRuntimeLifecycle();
        var lifecycle = new HostLifecycleCoordinator(
            health,
            telegram: null,
            license: null,
            hotkeys);

        lifecycle.StartAsync().GetAwaiter().GetResult();
        lifecycle.StartAsync().GetAwaiter().GetResult();
        lifecycle.StopAsync().GetAwaiter().GetResult();
        lifecycle.StopAsync().GetAwaiter().GetResult();

        TestAssert.Equal(1, hotkeys.StartCount, "Hotkey runtime started more than once");
        TestAssert.Equal(1, hotkeys.StopCount, "Hotkey runtime stopped more than once");
    }

    private static void LifecycleStopBeforeStartIsTerminal()
    {
        var healthUseCase = new SuccessfulHealthUseCase();
        var health = EngineHealthViewModel.CreateOffline(healthUseCase);
        var telegram = new FakeTelegramRuntimeLifecycle();
        var license = new FakeLicenseRuntimeLifecycle();
        var lifecycle = new HostLifecycleCoordinator(health, telegram, license);

        lifecycle.StopAsync().GetAwaiter().GetResult();
        lifecycle.StartAsync().GetAwaiter().GetResult();

        TestAssert.Equal(0, healthUseCase.CallCount,
            "Late content render restarted Engine health after terminal Host stop");
        TestAssert.Equal(0, telegram.StartCount,
            "Late content render restarted Telegram after terminal Host stop");
        TestAssert.Equal(1, telegram.StopCount,
            "Terminal Host stop did not close Telegram exactly once");
        TestAssert.Equal(0, license.StartCount,
            "Late content render restarted license refresh after terminal Host stop");
        TestAssert.Equal(1, license.StopCount,
            "Terminal Host stop did not close license runtime exactly once");
    }

    private static void LifecycleConcurrentStartStopIsIdempotent()
    {
        for (var iteration = 0; iteration < 64; iteration++)
        {
            var healthUseCase = new SuccessfulHealthUseCase();
            var health = EngineHealthViewModel.CreateOffline(healthUseCase);
            var telegram = new FakeTelegramRuntimeLifecycle();
            var license = new FakeLicenseRuntimeLifecycle();
            var lifecycle = new HostLifecycleCoordinator(health, telegram, license);

            var start = Task.Run(lifecycle.StartAsync);
            var stop = Task.Run(lifecycle.StopAsync);
            Task.WaitAll(start, stop);
            lifecycle.StartAsync().GetAwaiter().GetResult();
            lifecycle.StopAsync().GetAwaiter().GetResult();

            TestAssert.True(
                healthUseCase.CallCount is 0 or 1,
                "Concurrent lifecycle race started Engine health more than once");
            TestAssert.True(
                telegram.StartCount is 0 or 1,
                "Concurrent lifecycle race started Telegram more than once");
            TestAssert.True(
                license.StartCount is 0 or 1,
                "Concurrent lifecycle race started license refresh more than once");
            TestAssert.Equal(1, telegram.StopCount,
                "Concurrent lifecycle race stopped Telegram more than once");
            TestAssert.Equal(1, license.StopCount,
                "Concurrent lifecycle race stopped license refresh more than once");
        }
    }

    private static void WindowStartFaultExitsNonzero()
    {
        var result = ExerciseWindowStartup(
            new WindowLifecycle(
                Task.FromException(new InvalidOperationException("fixture")),
                Task.CompletedTask),
            TimeSpan.FromSeconds(1));

        TestAssert.True(result.Closed, "Faulted lifecycle start left the Host window open");
        TestAssert.Equal(
            MainWindow.LifecycleStartupFailureExitCode,
            result.ShutdownExitCode,
            "Faulted lifecycle start did not request controlled nonzero shutdown");
    }

    private static void WindowDefersSecondClose()
    {
        var result = ExerciseWindowClose(
            new WindowLifecycle(Task.CompletedTask),
            TimeSpan.FromSeconds(1));

        TestAssert.True(result.Closed, "Synchronous lifecycle stop left the Host window open");
        TestAssert.Equal(0, result.ShutdownExitCode, "Normal Host close requested failure shutdown");
    }

    private static void WindowStopFaultExitsNonzero()
    {
        var result = ExerciseWindowClose(
            new WindowLifecycle(Task.FromException(new InvalidOperationException("fixture"))),
            TimeSpan.FromSeconds(1));

        TestAssert.True(result.Closed, "Faulted lifecycle stop left the Host window open");
        TestAssert.Equal(
            MainWindow.LifecycleShutdownFailureExitCode,
            result.ShutdownExitCode,
            "Faulted lifecycle stop did not request nonzero shutdown");
    }

    private static void WindowStopTimeoutExitsNonzero()
    {
        var neverCompletes = new TaskCompletionSource(
            TaskCreationOptions.RunContinuationsAsynchronously);
        var result = ExerciseWindowClose(
            new WindowLifecycle(neverCompletes.Task),
            TimeSpan.FromMilliseconds(50));

        TestAssert.True(result.Closed, "Timed-out lifecycle stop left the Host window open");
        TestAssert.Equal(
            MainWindow.LifecycleShutdownFailureExitCode,
            result.ShutdownExitCode,
            "Timed-out lifecycle stop did not request nonzero shutdown");
    }

    private static WindowCloseResult ExerciseWindowClose(
        IHostLifecycle lifecycle,
        TimeSpan shutdownTimeout)
    {
        var composition = HostApplicationComposition.Create(
            new HostRunOptions(HostRunMode.Demo, null),
            FishingHostState.Default);
        var shutdownExitCode = 0;
        var closed = false;
        var timedOut = false;
        var frame = new DispatcherFrame();
        var timeout = new DispatcherTimer(
            TimeSpan.FromSeconds(2),
            DispatcherPriority.Send,
            (_, _) =>
            {
                timedOut = true;
                frame.Continue = false;
            },
            Dispatcher.CurrentDispatcher);
        var window = new MainWindow(
            composition.Shell,
            lifecycle,
            shutdownTimeout,
            exitCode => shutdownExitCode = exitCode)
        {
            ShowActivated = false,
            ShowInTaskbar = false,
            Left = -10_000,
            Top = -10_000,
        };
        window.Closed += (_, _) =>
        {
            closed = true;
            frame.Continue = false;
        };

        try
        {
            window.Show();
            window.Close();
            Dispatcher.PushFrame(frame);
        }
        finally
        {
            timeout.Stop();
            if (!closed)
            {
                window.Close();
            }
        }

        TestAssert.True(!timedOut, "Host window close exceeded the bounded regression budget");
        return new WindowCloseResult(closed, shutdownExitCode);
    }

    private static WindowCloseResult ExerciseWindowStartup(
        IHostLifecycle lifecycle,
        TimeSpan shutdownTimeout)
    {
        var composition = HostApplicationComposition.Create(
            new HostRunOptions(HostRunMode.Demo, null),
            FishingHostState.Default);
        var shutdownExitCode = 0;
        var closed = false;
        var timedOut = false;
        var frame = new DispatcherFrame();
        var timeout = new DispatcherTimer(
            TimeSpan.FromSeconds(2),
            DispatcherPriority.Send,
            (_, _) =>
            {
                timedOut = true;
                frame.Continue = false;
            },
            Dispatcher.CurrentDispatcher);
        var window = new MainWindow(
            composition.Shell,
            lifecycle,
            shutdownTimeout,
            exitCode => shutdownExitCode = exitCode)
        {
            ShowActivated = false,
            ShowInTaskbar = false,
            Left = -10_000,
            Top = -10_000,
        };
        window.Closed += (_, _) =>
        {
            closed = true;
            frame.Continue = false;
        };

        try
        {
            window.Show();
            Dispatcher.PushFrame(frame);
        }
        finally
        {
            timeout.Stop();
            if (!closed)
            {
                window.Close();
            }
        }

        TestAssert.True(!timedOut, "Host startup failure exceeded the bounded regression budget");
        return new WindowCloseResult(closed, shutdownExitCode);
    }

    private static void HostAssemblyHasEntryPoint()
    {
        TestAssert.True(
            typeof(App).Assembly.EntryPoint is not null,
            "Sonar.Fishing.Host is still a class library without an entrypoint");
        TestAssert.True(
            typeof(App).IsAssignableTo(typeof(System.Windows.Application)),
            "Host entrypoint is not a WPF Application");
    }

    private static void ContainedEngineStopsWithHost()
    {
        var startInfo = new ProcessStartInfo
        {
            FileName = "powershell.exe",
            UseShellExecute = false,
            CreateNoWindow = true,
            WindowStyle = ProcessWindowStyle.Hidden,
        };
        startInfo.ArgumentList.Add("-NoProfile");
        startInfo.ArgumentList.Add("-NonInteractive");
        startInfo.ArgumentList.Add("-Command");
        startInfo.ArgumentList.Add("Start-Sleep -Seconds 30");

        var child = ContainedEngineProcess.Start(startInfo);
        var processId = child.Id;
        TestAssert.True(child.IsContained, "Product Engine wrapper did not use the Common Job");
        child.DisposeAsync().AsTask().GetAwaiter().GetResult();
        child.DisposeAsync().AsTask().GetAwaiter().GetResult();

        TestAssert.True(
            !IsProcessAlive(processId),
            "Contained Engine survived Host lifecycle disposal");
    }

    private static bool IsProcessAlive(int processId)
    {
        try
        {
            using var process = Process.GetProcessById(processId);
            return !process.HasExited;
        }
        catch (ArgumentException)
        {
            return false;
        }
    }

    private sealed class SuccessfulHealthUseCase : IEngineHealthUseCase
    {
        public int CallCount { get; private set; }

        public Task<EngineHealthResult> RunAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            CallCount++;
            return Task.FromResult(new EngineHealthResult(
                VerifiedEngineProcessId: 4242,
                ProcessContainmentVerified: true,
                NegotiatedProtocolMinor: 0,
                SideEffectsEnabled: false,
                ProductionAuthority: "native-cpp-diagnostic-engine",
                SessionState: CreateSessionState()));
        }
    }

    private static FishingSessionStateSnapshot CreateSessionState() => new(
        revision: 1,
        running: false,
        stopping: false,
        detectedStage: "read_only_session_started",
        totals: new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
        tackleItems: Array.Empty<FishingTackleItemSnapshot>());

    private sealed class BlockingHealthUseCase : IEngineHealthUseCase
    {
        public TaskCompletionSource Started { get; } = new(
            TaskCreationOptions.RunContinuationsAsynchronously);

        public bool CancellationObserved { get; private set; }

        public async Task<EngineHealthResult> RunAsync(CancellationToken cancellationToken)
        {
            Started.SetResult();
            try
            {
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken).ConfigureAwait(false);
            }
            catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
            {
                CancellationObserved = true;
                throw;
            }

            throw new InvalidOperationException("unreachable");
        }
    }

    private sealed class DisposableHealthUseCase : IEngineHealthUseCase, IAsyncDisposable
    {
        public int DisposeCount { get; private set; }

        public Task<EngineHealthResult> RunAsync(CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            return Task.FromResult(new EngineHealthResult(
                VerifiedEngineProcessId: 4242,
                ProcessContainmentVerified: true,
                NegotiatedProtocolMinor: 0,
                SideEffectsEnabled: false,
                ProductionAuthority: "native-cpp-diagnostic-engine",
                SessionState: CreateSessionState()));
        }

        public ValueTask DisposeAsync()
        {
            if (DisposeCount == 0)
            {
                DisposeCount++;
            }
            return ValueTask.CompletedTask;
        }
    }

    private sealed class FakeTelegramRuntimeLifecycle : ITelegramRuntimeLifecycle
    {
        public int StartCount { get; private set; }

        public int StopCount { get; private set; }

        public Task StartAsync()
        {
            StartCount++;
            return Task.CompletedTask;
        }

        public Task StopAsync()
        {
            StopCount++;
            return Task.CompletedTask;
        }
    }

    private sealed class FakeLicenseRuntimeLifecycle : ILicenseRuntimeLifecycle
    {
        public int StartCount { get; private set; }

        public int StopCount { get; private set; }

        public Task StartAsync()
        {
            StartCount++;
            return Task.CompletedTask;
        }

        public Task StopAsync()
        {
            StopCount++;
            return Task.CompletedTask;
        }
    }

    private sealed class FakeHotkeyRuntimeLifecycle : IHostHotkeyRuntimeLifecycle
    {
        public int StartCount { get; private set; }

        public int StopCount { get; private set; }

        public Task StartAsync()
        {
            StartCount++;
            return Task.CompletedTask;
        }

        public Task StopAsync()
        {
            StopCount++;
            return Task.CompletedTask;
        }
    }

    private sealed record WindowCloseResult(bool Closed, int ShutdownExitCode);

    private sealed class WindowLifecycle : IHostLifecycle
    {
        private readonly Task startTask;
        private readonly Task stopTask;

        internal WindowLifecycle(Task stopTask)
            : this(Task.CompletedTask, stopTask)
        {
        }

        internal WindowLifecycle(Task startTask, Task stopTask)
        {
            this.startTask = startTask;
            this.stopTask = stopTask;
        }

        public Task StartAsync() => startTask;

        public Task StopAsync() => stopTask;
    }
}
