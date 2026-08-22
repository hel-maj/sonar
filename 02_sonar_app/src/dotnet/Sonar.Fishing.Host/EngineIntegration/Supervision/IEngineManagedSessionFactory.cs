namespace Sonar.Fishing.Host.EngineIntegration.Supervision;

internal interface IEngineManagedSessionFactory
{
    Task<IEngineManagedSession> StartAsync(CancellationToken cancellationToken);
}
