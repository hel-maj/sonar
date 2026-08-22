namespace Sonar.Fishing.Host.HostRuntime;

public enum HostRunMode
{
    Production,
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

        if (arguments.Count == 2 &&
            string.Equals(arguments[0], "--offline-engine", StringComparison.Ordinal) &&
            !string.IsNullOrWhiteSpace(arguments[1]))
        {
            return new HostRunOptions(HostRunMode.OfflineEngine, arguments[1]);
        }

        throw new HostRunOptionsException(
            "Запустите Sonar без параметров. Для разработки доступны только " +
            "--demo и --offline-engine <путь к инертному Engine>.");
    }
}

public sealed class HostRunOptionsException : Exception
{
    public HostRunOptionsException(string message)
        : base(message)
    {
    }
}
