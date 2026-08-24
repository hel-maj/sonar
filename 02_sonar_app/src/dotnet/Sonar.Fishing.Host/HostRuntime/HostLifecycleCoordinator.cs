using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.TelegramPage;
using Sonar.Fishing.Host.HostHotkeys;

namespace Sonar.Fishing.Host.HostRuntime;

public sealed class HostLifecycleCoordinator : IHostLifecycle
{
    private readonly EngineHealthViewModel _engineHealth;
    private readonly ITelegramRuntimeLifecycle? _telegram;
    private readonly ILicenseRuntimeLifecycle? _license;
    private readonly IHostHotkeyRuntimeLifecycle? _hotkeys;
    private readonly object _sync = new();
    private Task? _startupTask;
    private Task? _stopTask;
    private bool _stopRequested;

    public HostLifecycleCoordinator(
        EngineHealthViewModel engineHealth,
        ITelegramRuntimeLifecycle? telegram = null,
        ILicenseRuntimeLifecycle? license = null)
        : this(engineHealth, telegram, license, hotkeys: null)
    {
    }

    internal HostLifecycleCoordinator(
        EngineHealthViewModel engineHealth,
        ITelegramRuntimeLifecycle? telegram,
        ILicenseRuntimeLifecycle? license,
        IHostHotkeyRuntimeLifecycle? hotkeys = null)
    {
        _engineHealth = engineHealth ?? throw new ArgumentNullException(nameof(engineHealth));
        _telegram = telegram;
        _license = license;
        _hotkeys = hotkeys;
    }

    public Task StartAsync()
    {
        lock (_sync)
        {
            if (_stopRequested)
            {
                return Task.CompletedTask;
            }
            _startupTask ??= StartCoreAsync();
            return _startupTask;
        }
    }

    public Task StopAsync()
    {
        lock (_sync)
        {
            _stopRequested = true;
            _stopTask ??= StopCoreAsync();
            return _stopTask;
        }
    }

    private async Task StopCoreAsync()
    {
        Task? startupTask;
        lock (_sync)
        {
            startupTask = _startupTask;
        }
        _engineHealth.Cancel();
        var licenseStopTask = _license?.StopAsync() ?? Task.CompletedTask;
        var telegramStopTask = _telegram?.StopAsync() ?? Task.CompletedTask;
        var hotkeyStopTask = _hotkeys?.StopAsync() ?? Task.CompletedTask;
        Exception? startupFailure = null;
        try
        {
            if (startupTask is not null)
            {
                await startupTask.ConfigureAwait(false);
            }
        }
        catch (Exception exception)
        {
            startupFailure = exception;
        }

        Exception? boundaryStopFailure = null;
        try
        {
            await Task.WhenAll(licenseStopTask, telegramStopTask, hotkeyStopTask)
                .ConfigureAwait(false);
        }
        catch (Exception exception)
        {
            boundaryStopFailure = exception;
        }
        finally
        {
            await _engineHealth.StopAsync().ConfigureAwait(false);
        }

        if (startupFailure is not null)
        {
            throw new InvalidOperationException(
                "host_lifecycle_start_failed",
                startupFailure);
        }
        if (boundaryStopFailure is not null)
        {
            throw new InvalidOperationException(
                "host_lifecycle_boundary_stop_failed",
                boundaryStopFailure);
        }
    }

    private async Task StartCoreAsync()
    {
        var telegramStart = _telegram?.StartAsync() ?? Task.CompletedTask;
        var licenseStart = _license?.StartAsync() ?? Task.CompletedTask;
        await Task.WhenAll(
            _engineHealth.RunInitialCheckAsync(),
            telegramStart,
            licenseStart).ConfigureAwait(false);
        await (_hotkeys?.StartAsync() ?? Task.CompletedTask).ConfigureAwait(false);
    }
}
