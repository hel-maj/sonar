using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.TelegramPage;

namespace Sonar.Fishing.Host.HostRuntime;

public sealed class HostLifecycleCoordinator : IHostLifecycle
{
    private readonly EngineHealthViewModel _engineHealth;
    private readonly ITelegramRuntimeLifecycle? _telegram;
    private readonly ILicenseRuntimeLifecycle? _license;
    private readonly object _sync = new();
    private Task? _startupTask;
    private Task? _stopTask;
    private bool _stopRequested;

    public HostLifecycleCoordinator(
        EngineHealthViewModel engineHealth,
        ITelegramRuntimeLifecycle? telegram = null,
        ILicenseRuntimeLifecycle? license = null)
    {
        _engineHealth = engineHealth ?? throw new ArgumentNullException(nameof(engineHealth));
        _telegram = telegram;
        _license = license;
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
        if (startupTask is not null)
        {
            await startupTask.ConfigureAwait(false);
        }
        try
        {
            await Task.WhenAll(licenseStopTask, telegramStopTask).ConfigureAwait(false);
        }
        finally
        {
            await _engineHealth.StopAsync().ConfigureAwait(false);
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
    }
}
