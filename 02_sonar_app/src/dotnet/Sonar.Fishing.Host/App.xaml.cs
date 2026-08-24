using System.IO;
using System.Net;
using System.Net.Http;
using System.Diagnostics;
using System.Windows;
using Sonar.Fishing.Host.HostDiagnostics;
using Sonar.Fishing.Host.HostRuntime;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.EngineIntegration.Supervision;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StartupGate;
using Sonar.Fishing.Host.HostHotkeys;
using Sonar.Fishing.Host.UpdateRuntime;

namespace Sonar.Fishing.Host;

public partial class App : Application
{
    private HostApplicationComposition? _composition;
    private ProductDiagnosticLog? _diagnostics;
    private HttpClient? _licenseHttpClient;
    private ILicenseRuntimeLifecycle? _licenseRuntime;
    private HttpClient? _startupHttpClient;
    private CancellationTokenSource? _startupMonitorCancellation;
    private Task? _startupMonitorTask;
    private StartupAdmissionWindow? _startupWindow;

    protected override async void OnStartup(StartupEventArgs e)
    {
        base.OnStartup(e);
        if (ReleaseMaintenanceCommand.IsRequest(e.Args))
        {
            ShutdownMode = ShutdownMode.OnExplicitShutdown;
            var exitCode = await ReleaseMaintenanceCommand.ExecuteAsync(
                    e.Args,
                    CancellationToken.None)
                .ConfigureAwait(true);
            Shutdown(exitCode);
            return;
        }
        _diagnostics = TryOpenDiagnostics();

        try
        {
            var options = HostRunOptions.Parse(e.Args);
            TryLog(
                ProductDiagnosticLevel.Information,
                "host.start",
                $"mode={options.Mode}");
            var state = HostStateBootstrap.LoadCoordinatorForApplicationDirectory(
                AppContext.BaseDirectory);
            if (options.Mode == HostRunMode.Production &&
                !await AdmitProductionStartupAsync(state).ConfigureAwait(true))
            {
                return;
            }
            Action? clearDiagnostics = _diagnostics is null ? null : _diagnostics.Clear;
            _composition = options.Mode is HostRunMode.Production or
                HostRunMode.DeveloperFullAccess
                    ? CreateProductionComposition(
                        state,
                        clearDiagnostics,
                        options.Mode)
                    : HostApplicationComposition.Create(
                        options,
                        state,
                        clearDiagnostics);
            MainWindow = new MainWindow(
                _composition.Shell,
                _composition.Lifecycle);
            ShutdownMode = ShutdownMode.OnMainWindowClose;
            MainWindow.Show();
            _startupWindow?.Close();
            _startupWindow = null;
            if (options.Mode == HostRunMode.Production)
            {
                StartProductionStartupMonitor(state);
            }
        }
        catch (HostRunOptionsException exception)
        {
            TryLog(ProductDiagnosticLevel.Warning, "host.start.rejected", "run options invalid");
            MessageBox.Show(
                exception.Message,
                "Не удалось запустить Sonar Fishing",
                MessageBoxButton.OK,
                MessageBoxImage.Error);
            Shutdown(2);
        }
        catch (HostStateStartupException exception)
        {
            TryLog(ProductDiagnosticLevel.Error, "host.state.rejected", "state load failed");
            MessageBox.Show(
                exception.Message,
                "Sonar Fishing - настройки",
                MessageBoxButton.OK,
                MessageBoxImage.Error);
            Shutdown(3);
        }
    }

    protected override void OnExit(ExitEventArgs e)
    {
        TryLog(
            ProductDiagnosticLevel.Information,
            "host.exit",
            $"exit_code={e.ApplicationExitCode}");
        _diagnostics?.Dispose();
        _diagnostics = null;
        _startupMonitorCancellation?.Cancel();
        try
        {
            _startupMonitorTask?.GetAwaiter().GetResult();
        }
        catch (OperationCanceledException)
        {
        }
        _startupMonitorCancellation?.Dispose();
        _startupMonitorCancellation = null;
        _startupMonitorTask = null;
        _licenseRuntime?.StopAsync().GetAwaiter().GetResult();
        _licenseRuntime = null;
        _licenseHttpClient?.Dispose();
        _licenseHttpClient = null;
        _startupHttpClient?.Dispose();
        _startupHttpClient = null;
        base.OnExit(e);
    }

    private static HttpClient CreateLicenseHttpClient()
    {
        var handler = new SocketsHttpHandler
        {
            AllowAutoRedirect = false,
            AutomaticDecompression = DecompressionMethods.None,
            UseCookies = false,
            ConnectTimeout = TimeSpan.FromSeconds(5),
        };
        return new HttpClient(handler, disposeHandler: true)
        {
            Timeout = Timeout.InfiniteTimeSpan,
        };
    }

    private async Task<bool> AdmitProductionStartupAsync(HostStateCoordinator state)
    {
        _startupHttpClient = CreateLicenseHttpClient();
        var viewModel = new StartupAdmissionViewModel(
            OpenExternalHttps,
            () => Shutdown(4));
        _startupWindow = new StartupAdmissionWindow(viewModel);
        MainWindow = _startupWindow;
        _startupWindow.Show();
        var coordinator = new StartupAdmissionCoordinator(
            FishingProductionStartupPolicy.CreateClient(_startupHttpClient),
            FishingProductionStartupPolicy.CreateRequest(state),
            viewModel);
        var decision = await coordinator.CheckInitialAsync(CancellationToken.None)
            .ConfigureAwait(true);
        if (decision.CanCreateMainWindow)
        {
            _startupWindow.Hide();
            return true;
        }
        ShutdownMode = ShutdownMode.OnMainWindowClose;
        return false;
    }

    private void StartProductionStartupMonitor(HostStateCoordinator state)
    {
        var httpClient = _startupHttpClient ??
            throw new InvalidOperationException("startup_http_client_missing");
        _startupMonitorCancellation = new CancellationTokenSource();
        var monitor = new StartupBlockRuntimeMonitor(
            FishingProductionStartupPolicy.CreateClient(httpClient),
            () => FishingProductionStartupPolicy.CreateRequest(state),
            HandleSignedRuntimeBlockAsync);
        _startupMonitorTask = monitor.RunAsync(_startupMonitorCancellation.Token);
    }

    private Task HandleSignedRuntimeBlockAsync(
        StartupBlockStatus status,
        CancellationToken cancellationToken) =>
        Dispatcher.InvokeAsync(async () =>
        {
            cancellationToken.ThrowIfCancellationRequested();
            var previousWindow = MainWindow;
            if (_composition is not null)
            {
                await _composition.Lifecycle.StopAsync().ConfigureAwait(true);
            }
            var viewModel = new StartupAdmissionViewModel(
                OpenExternalHttps,
                () => Shutdown(5));
            viewModel.Apply(StartupAdmissionPolicy.InitialLaunch(status));
            var blockedWindow = new StartupAdmissionWindow(viewModel);
            MainWindow = blockedWindow;
            ShutdownMode = ShutdownMode.OnMainWindowClose;
            blockedWindow.Show();
            previousWindow?.Hide();
            previousWindow?.Close();
        }).Task.Unwrap();

    private static void OpenExternalHttps(Uri uri)
    {
        ArgumentNullException.ThrowIfNull(uri);
        if (!string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase) ||
            !string.IsNullOrEmpty(uri.UserInfo))
        {
            throw new InvalidOperationException("startup_navigation_rejected");
        }
        Process.Start(new ProcessStartInfo(uri.AbsoluteUri)
        {
            UseShellExecute = true,
        });
    }

    private HostApplicationComposition CreateProductionComposition(
        HostStateCoordinator state,
        Action? clearDiagnostics,
        HostRunMode runMode)
    {
        if (runMode is not (HostRunMode.Production or
            HostRunMode.DeveloperFullAccess))
        {
            throw new ArgumentOutOfRangeException(nameof(runMode));
        }
#if !SONAR_FISHING_DEVELOPER_FULL_ACCESS
        if (runMode == HostRunMode.DeveloperFullAccess)
        {
            throw new InvalidOperationException("developer_full_access_not_compiled");
        }
#endif
        var developerFullAccess = runMode == HostRunMode.DeveloperFullAccess;
        if (!developerFullAccess)
        {
            state.RevokeLicenseAuthority(clearSignedCache: false);
        }
        var engineExecutable = Path.Combine(AppContext.BaseDirectory, "Sonar.Engine.exe");
        var timeout = TimeSpan.FromSeconds(10);
        var supervisor = new EngineSessionSupervisor(
            new ProductionEngineManagedSessionFactory(
                engineExecutable,
                timeout,
                () => state.Current.Fishing,
                developerFullAccess
                    ? EngineProcessAuthorityMode.DeveloperFullAccess
                    : EngineProcessAuthorityMode.Production),
            EngineRestartPolicy.Default);
        var healthUseCase = new ProductionEngineHealthUseCase(supervisor, timeout);
        var automationRuntime = new EngineFishingAutomationRuntime(
            supervisor,
            () => state.Current.Fishing);
        var hotkeyRuntime = new StartStopHotkeyRuntime(
            new Win32HotkeyStateReader(),
            () => state.Current.Fishing,
            automationRuntime,
            ProductWindowFocusProbe.IsActive);
        Func<string, CancellationToken, Task<FishingLicenseActivationResult>>?
            activateLicense = null;
        LicenseHostSettings? licenseOverride = null;
        if (developerFullAccess)
        {
            _licenseRuntime = DeveloperLicenseRuntimeLifecycle.Instance;
            licenseOverride = DeveloperFullAccessPolicy.VisibleLicense;
        }
        else
        {
            _licenseHttpClient = CreateLicenseHttpClient();
            var licenseService = new FishingLicenseActivationService(
                new KeygenLicenseApiClient(_licenseHttpClient),
                WindowsMachineFingerprint.Current());
            var productionLicenseRuntime = new FishingLicenseRuntimeCoordinator(
                licenseService,
                state,
                new EngineEntitlementRuntimeSink(supervisor),
                dispatchStateMutation: action => Dispatcher.Invoke(action));
            _licenseRuntime = productionLicenseRuntime;
            activateLicense = productionLicenseRuntime.ActivateAsync;
        }
        return HostApplicationComposition.CreateProduction(
            state,
            healthUseCase,
            automationRuntime,
            supervisor,
            _licenseRuntime,
            hotkeyRuntime,
            activateLicense,
            clearDiagnostics,
            runMode,
            licenseOverride);
    }

    private static ProductDiagnosticLog? TryOpenDiagnostics()
    {
        try
        {
            return ProductDiagnosticLog.Open(AppContext.BaseDirectory);
        }
        catch (Exception exception) when (
            exception is IOException or UnauthorizedAccessException or
            InvalidOperationException or ArgumentException)
        {
            return null;
        }
    }

    private void TryLog(
        ProductDiagnosticLevel level,
        string eventId,
        string message)
    {
        try
        {
            _diagnostics?.Append(new ProductDiagnosticEntry(
                DateTimeOffset.UtcNow,
                level,
                eventId,
                message));
        }
        catch (Exception exception) when (
            exception is IOException or UnauthorizedAccessException or ObjectDisposedException)
        {
            // Diagnostics must never replace the product's primary failure path.
        }
    }
}
