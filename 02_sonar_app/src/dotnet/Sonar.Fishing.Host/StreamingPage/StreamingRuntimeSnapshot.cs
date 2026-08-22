using System.IO;

namespace Sonar.Fishing.Host.StreamingPage;

public enum StreamingRuntimeStatus
{
    Unavailable,
    Preparing,
    Starting,
    Online,
    Offline,
    Error,
}

public sealed record StreamingRuntimeSnapshot(
    ulong Revision,
    StreamingRuntimeStatus Status,
    bool Active,
    string Quality,
    bool ChatZoomEnabled,
    bool SnapshotModeEnabled,
    bool ChatModeEnabled,
    bool ChatActive,
    string? LocalUrl,
    string? PublicUrl,
    string? StreamUrl,
    DateTimeOffset? StartedAt,
    int? SecondsUntilAutoStop,
    string Error)
{
    public void Validate()
    {
        if (Revision == 0)
        {
            throw new InvalidDataException("streaming_snapshot_revision_invalid");
        }
        _ = StreamingQualityCatalog.Require(Quality);
        if (SecondsUntilAutoStop is < 0)
        {
            throw new InvalidDataException("streaming_auto_stop_invalid");
        }
        if (Active && Status is not StreamingRuntimeStatus.Online and not StreamingRuntimeStatus.Error)
        {
            throw new InvalidDataException("streaming_active_status_invalid");
        }
        if (Status == StreamingRuntimeStatus.Online && (!Active || StartedAt is null))
        {
            throw new InvalidDataException("streaming_online_state_invalid");
        }
        if (!Active && StartedAt is not null)
        {
            throw new InvalidDataException("streaming_inactive_start_time_invalid");
        }
        if (!string.IsNullOrEmpty(StreamUrl) &&
            !Uri.TryCreate(StreamUrl, UriKind.Absolute, out _))
        {
            throw new InvalidDataException("streaming_url_invalid");
        }
    }

    public StreamingRuntimeSnapshot Normalize()
    {
        Validate();
        return Status == StreamingRuntimeStatus.Preparing &&
               !Active &&
               string.IsNullOrEmpty(PublicUrl)
            ? this with { Status = StreamingRuntimeStatus.Offline }
            : this;
    }

    public static StreamingRuntimeSnapshot Unavailable(bool snapshotModeEnabled) => new(
        Revision: 1,
        Status: StreamingRuntimeStatus.Unavailable,
        Active: false,
        Quality: "720p",
        ChatZoomEnabled: false,
        SnapshotModeEnabled: snapshotModeEnabled,
        ChatModeEnabled: false,
        ChatActive: false,
        LocalUrl: null,
        PublicUrl: null,
        StreamUrl: null,
        StartedAt: null,
        SecondsUntilAutoStop: null,
        Error: "Средства трансляции недоступны в текущей установке.");

    public static StreamingRuntimeSnapshot Offline(bool snapshotModeEnabled) => new(
        Revision: 1,
        Status: StreamingRuntimeStatus.Offline,
        Active: false,
        Quality: "720p",
        ChatZoomEnabled: false,
        SnapshotModeEnabled: snapshotModeEnabled,
        ChatModeEnabled: false,
        ChatActive: false,
        LocalUrl: null,
        PublicUrl: null,
        StreamUrl: null,
        StartedAt: null,
        SecondsUntilAutoStop: null,
        Error: string.Empty);
}
