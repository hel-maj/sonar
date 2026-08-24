using System.IO;
using System.Runtime.Versioning;

namespace Sonar.Fishing.Host.SettingsPersistence;

public static class HostStateBootstrap
{
    [SupportedOSPlatform("windows")]
    public static FishingHostState LoadForApplicationDirectory(string applicationDirectory)
        => LoadCoordinatorForApplicationDirectory(applicationDirectory).Current;

    [SupportedOSPlatform("windows")]
    public static HostStateCoordinator LoadCoordinatorForApplicationDirectory(
        string applicationDirectory)
    {
        try
        {
            return LoadCoordinatorForApplicationDirectory(
                applicationDirectory,
                new DpapiCurrentUserSecretProtector());
        }
        catch (HostStateStartupException)
        {
            throw;
        }
        catch (Exception exception) when (exception is IOException or
                                          UnauthorizedAccessException or
                                          System.Security.Cryptography.CryptographicException or
                                          System.Text.Json.JsonException or
                                          ArgumentException)
        {
            throw new HostStateStartupException(
                "Не удалось безопасно загрузить настройки приложения. " +
                "Запуск остановлен, чтобы не потерять их.",
                exception);
        }
    }

    public static FishingHostState LoadForApplicationDirectory(
        string applicationDirectory,
        ISecretProtector secretProtector)
        => LoadCoordinatorForApplicationDirectory(applicationDirectory, secretProtector).Current;

    public static HostStateCoordinator LoadCoordinatorForApplicationDirectory(
        string applicationDirectory,
        ISecretProtector secretProtector)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(applicationDirectory);
        ArgumentNullException.ThrowIfNull(secretProtector);

        var root = Path.GetFullPath(applicationDirectory);
        var configDirectory = Path.Combine(root, "config");
        var store = new FishingStateStore(configDirectory, secretProtector);
        var migrator = new LegacyJsonSettingsMigrator(configDirectory);
        var state = migrator.LoadMigrateOrCreate(store);
        return new HostStateCoordinator(store, state);
    }
}

public sealed class HostStateStartupException : Exception
{
    public HostStateStartupException(string message, Exception innerException)
        : base(message, innerException)
    {
    }
}
