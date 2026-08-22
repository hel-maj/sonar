namespace Sonar.Fishing.Host.StreamingPage;

public sealed record StreamingCommandResult(
    bool Accepted,
    string Reason,
    StreamingRuntimeSnapshot Snapshot);

public interface IStreamingController
{
    StreamingRuntimeSnapshot Current { get; }

    event Action<StreamingRuntimeSnapshot>? SnapshotChanged;

    StreamingCommandResult Start();

    StreamingCommandResult Stop(string reason);

    StreamingCommandResult SetQuality(string quality);

    StreamingCommandResult SetChatZoom(bool enabled);

    StreamingCommandResult SetSnapshotMode(bool enabled);

    StreamingCommandResult SetChatMode(bool enabled);
}
