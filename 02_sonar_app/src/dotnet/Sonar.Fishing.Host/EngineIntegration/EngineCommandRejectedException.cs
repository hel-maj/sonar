namespace Sonar.Fishing.Host.EngineIntegration;

internal sealed class EngineCommandRejectedException : InvalidOperationException
{
    internal EngineCommandRejectedException(string command, string reason)
        : base($"{command}:{reason}")
    {
        Command = command;
        Reason = reason;
    }

    internal string Command { get; }

    internal string Reason { get; }
}
