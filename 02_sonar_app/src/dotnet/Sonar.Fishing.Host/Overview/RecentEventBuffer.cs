using System.Collections.ObjectModel;
using System.Globalization;

namespace Sonar.Fishing.Host.Overview;

public enum FishingEventTone
{
    Neutral,
    Success,
    Warning,
    Error,
}

public sealed record FishingEventSnapshot(
    ulong Sequence,
    DateTimeOffset OccurredAt,
    FishingEventTone Tone,
    string IconResourceKey,
    string Message,
    string? Detail = null,
    string? Extra = null,
    FishingEventTone ExtraTone = FishingEventTone.Neutral)
{
    public string OccurredAtText =>
        OccurredAt.ToLocalTime().ToString("HH:mm", CultureInfo.CurrentCulture);
}

public sealed class RecentEventBuffer
{
    public const int RetentionLimit = 400;
    public const int PresentationLimit = 80;

    private readonly Queue<FishingEventSnapshot> _events = new(RetentionLimit);
    private ulong _lastSequence;

    public int Count => _events.Count;

    public ulong Revision { get; private set; }

    public void Append(FishingEventSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        Validate(snapshot);
        if (snapshot.Sequence <= _lastSequence)
        {
            throw new InvalidOperationException("recent_event_sequence_not_increasing");
        }

        _events.Enqueue(snapshot);
        _lastSequence = snapshot.Sequence;
        while (_events.Count > RetentionLimit)
        {
            _events.Dequeue();
        }
        Revision++;
    }

    public IReadOnlyList<FishingEventSnapshot> PresentationSnapshot()
    {
        var skip = Math.Max(0, _events.Count - PresentationLimit);
        return new ReadOnlyCollection<FishingEventSnapshot>(
            _events.Skip(skip).ToArray());
    }

    public void Clear()
    {
        if (_events.Count == 0)
        {
            return;
        }
        _events.Clear();
        Revision++;
    }

    private static void Validate(FishingEventSnapshot snapshot)
    {
        if (snapshot.Sequence == 0 ||
            string.IsNullOrWhiteSpace(snapshot.IconResourceKey) ||
            string.IsNullOrWhiteSpace(snapshot.Message) ||
            snapshot.Message.Length > 1024 ||
            snapshot.Detail?.Length > 4096 ||
            snapshot.Extra?.Length > 1024)
        {
            throw new ArgumentException("recent_event_invalid", nameof(snapshot));
        }
    }
}
