namespace Sonar.Fishing.Host.HostRuntime;

internal interface IHostLifecycle
{
    Task StartAsync();

    Task StopAsync();
}
