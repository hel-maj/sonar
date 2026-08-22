namespace Sonar.Fishing.Host.StreamingPage;

public sealed record StreamingQualityProfile(
    string Name,
    int Width,
    int Height,
    string DefaultBitrate,
    string LowFpsBitrate)
{
    public int FramesPerSecondFor(bool lowFps) => lowFps ? 10 : 30;

    public string BitrateFor(bool lowFps) =>
        lowFps ? LowFpsBitrate : DefaultBitrate;
}

public static class StreamingQualityCatalog
{
    public static IReadOnlyList<StreamingQualityProfile> All { get; } =
    [
        new("480p", 854, 480, "1200k", "600k"),
        new("720p", 1280, 720, "2900k", "1500k"),
        new("1080p", 1920, 1080, "5000k", "2300k"),
    ];

    public static StreamingQualityProfile Require(string name)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(name);
        return All.FirstOrDefault(item =>
                   string.Equals(item.Name, name, StringComparison.Ordinal))
            ?? throw new ArgumentOutOfRangeException(
                nameof(name),
                name,
                "streaming_quality_unsupported");
    }
}
