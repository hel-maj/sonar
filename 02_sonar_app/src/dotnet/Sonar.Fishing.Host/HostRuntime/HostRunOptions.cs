namespace Sonar.Fishing.Host.HostRuntime;

public enum HostRunMode
{
    Production,
    DeveloperFullAccess,
    Demo,
    OfflineEngine,
}

public sealed record HostRunOptions(
    HostRunMode Mode,
    string? EngineExecutable)
{
    public static HostRunOptions Parse(IReadOnlyList<string> arguments)
    {
        ArgumentNullException.ThrowIfNull(arguments);

        if (arguments.Count == 0)
        {
            return new HostRunOptions(HostRunMode.Production, null);
        }

        if (arguments.Count == 1 &&
            string.Equals(arguments[0], "--demo", StringComparison.Ordinal))
        {
            return new HostRunOptions(HostRunMode.Demo, null);
        }

#if SONAR_FISHING_DEVELOPER_FULL_ACCESS
        if (arguments.Count == 1 &&
            string.Equals(
                arguments[0],
                "--developer-full-access",
                StringComparison.Ordinal))
        {
            return new HostRunOptions(HostRunMode.DeveloperFullAccess, null);
        }
#endif

        if (arguments.Count == 2 &&
            string.Equals(arguments[0], "--offline-engine", StringComparison.Ordinal) &&
            !string.IsNullOrWhiteSpace(arguments[1]))
        {
            return new HostRunOptions(HostRunMode.OfflineEngine, arguments[1]);
        }

        throw new HostRunOptionsException(
            "Не удалось запустить приложение. Используйте обычную команду " +
            "запуска Sonar Fishing.");
    }
}

public sealed class HostRunOptionsException : Exception
{
    public HostRunOptionsException(string message)
        : base(message)
    {
    }
}
