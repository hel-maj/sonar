using System.ComponentModel;
using System.Diagnostics;
using System.Windows;
using Sonar.Fishing.Host.HostRuntime;
using Sonar.Fishing.Host.Shell;

namespace Sonar.Fishing.Host;

public partial class MainWindow : Window
{
    internal const int LifecycleShutdownFailureExitCode = 6;
    private static readonly TimeSpan DefaultShutdownTimeout = TimeSpan.FromSeconds(10);

    private readonly IHostLifecycle _lifecycle;
    private readonly TimeSpan _shutdownTimeout;
    private readonly Action<int> _shutdownApplication;
    private bool _allowClose;
    private bool _closing;

    public MainWindow(
        FishingHostShellViewModel shell,
        HostLifecycleCoordinator lifecycle)
        : this(
            shell,
            lifecycle,
            DefaultShutdownTimeout,
            exitCode => Application.Current.Shutdown(exitCode))
    {
    }

    internal MainWindow(
        FishingHostShellViewModel shell,
        IHostLifecycle lifecycle,
        TimeSpan shutdownTimeout,
        Action<int> shutdownApplication)
    {
        ArgumentNullException.ThrowIfNull(shell);
        ArgumentNullException.ThrowIfNull(lifecycle);
        ArgumentNullException.ThrowIfNull(shutdownApplication);
        if (shutdownTimeout <= TimeSpan.Zero || shutdownTimeout > DefaultShutdownTimeout)
        {
            throw new ArgumentOutOfRangeException(nameof(shutdownTimeout));
        }

        _lifecycle = lifecycle;
        _shutdownTimeout = shutdownTimeout;
        _shutdownApplication = shutdownApplication;
        DataContext = shell;
        InitializeComponent();
        ContentRendered += OnContentRendered;
        Closing += OnClosing;
    }

    private async void OnContentRendered(object? sender, EventArgs e)
    {
        ContentRendered -= OnContentRendered;
        await _lifecycle.StartAsync().ConfigureAwait(true);
    }

    private void OnClosing(object? sender, CancelEventArgs e)
    {
        if (_allowClose)
        {
            return;
        }

        e.Cancel = true;
        if (_closing)
        {
            return;
        }

        _closing = true;
        _ = StopAndCloseAsync();
    }

    private async Task StopAndCloseAsync()
    {
        // The first Closing event is still on the stack and was cancelled.
        // Always yield before a second Close so a synchronously completed stop
        // cannot re-enter WPF's close state machine.
        await Task.Yield();

        var stopTask = _lifecycle.StopAsync();
        try
        {
            await stopTask.WaitAsync(_shutdownTimeout).ConfigureAwait(true);
            _allowClose = true;
            Close();
        }
        catch (Exception exception)
        {
            if (!stopTask.IsCompleted)
            {
                _ = ObserveLateStopAsync(stopTask);
            }
            Trace.TraceError(
                $"Host lifecycle shutdown failed: {exception.GetType().Name}");
            _allowClose = true;
            _shutdownApplication(LifecycleShutdownFailureExitCode);
            if (IsVisible)
            {
                Close();
            }
        }
    }

    private static async Task ObserveLateStopAsync(Task stopTask)
    {
        try
        {
            await stopTask.ConfigureAwait(false);
        }
        catch (Exception)
        {
            // Failure was already reported and converted to nonzero shutdown.
        }
    }
}
