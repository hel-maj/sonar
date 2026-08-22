namespace Sonar.Fishing.Host.StreamingPage;

public sealed class UnavailableStreamingController : IStreamingController
{
    public UnavailableStreamingController(bool snapshotModeEnabled)
    {
        Current = StreamingRuntimeSnapshot.Unavailable(snapshotModeEnabled);
    }

    public StreamingRuntimeSnapshot Current { get; }

    public event Action<StreamingRuntimeSnapshot>? SnapshotChanged
    {
        add { }
        remove { }
    }

    public StreamingCommandResult Start() => Reject();

    public StreamingCommandResult Stop(string reason)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(reason);
        return Reject();
    }

    public StreamingCommandResult SetQuality(string quality)
    {
        _ = StreamingQualityCatalog.Require(quality);
        return Reject();
    }

    public StreamingCommandResult SetChatZoom(bool enabled) => Reject();

    public StreamingCommandResult SetSnapshotMode(bool enabled) => Reject();

    public StreamingCommandResult SetChatMode(bool enabled) => Reject();

    private StreamingCommandResult Reject() => new(
        Accepted: false,
        Reason: "streaming_runtime_unavailable",
        Current);
}
