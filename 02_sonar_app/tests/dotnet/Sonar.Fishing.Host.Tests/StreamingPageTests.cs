using Sonar.Fishing.Host.Overview;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StreamingPage;

namespace Sonar.Fishing.Host.Tests;

internal static class StreamingPageTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("streaming_quality_profiles_match_effective_product_policy", QualityProfilesMatch),
        new("streaming_snapshot_normalizes_inactive_preparing_without_public_url", SnapshotNormalizes),
        new("unavailable_streaming_controller_rejects_every_mutation", UnavailableControllerRejects),
        new("streaming_page_projects_one_controller_snapshot_and_persists_10fps", PageProjectsController),
        new("streaming_page_hides_chat_mode_without_bridge_capability", ChatModeAvailabilityIsExplicit),
        new("overview_stream_card_projects_the_same_runtime_snapshot", OverviewProjectsSnapshot),
    ];

    private static void QualityProfilesMatch()
    {
        var profiles = StreamingQualityCatalog.All;
        TestAssert.True(
            profiles.Select(item => item.Name).SequenceEqual(
                ["480p", "720p", "1080p"],
                StringComparer.Ordinal),
            "Streaming quality order changed");
        TestAssert.Equal("1200k", profiles[0].BitrateFor(lowFps: false), "480p bitrate changed");
        TestAssert.Equal("600k", profiles[0].BitrateFor(lowFps: true), "480p 10fps bitrate changed");
        TestAssert.Equal(854, profiles[0].Width, "480p width changed");
        TestAssert.Equal(480, profiles[0].Height, "480p height changed");
        TestAssert.Equal("2900k", profiles[1].BitrateFor(lowFps: false), "720p bitrate changed");
        TestAssert.Equal("1500k", profiles[1].BitrateFor(lowFps: true), "720p 10fps bitrate changed");
        TestAssert.Equal(1280, profiles[1].Width, "720p width changed");
        TestAssert.Equal(720, profiles[1].Height, "720p height changed");
        TestAssert.Equal("5000k", profiles[2].BitrateFor(lowFps: false), "1080p bitrate changed");
        TestAssert.Equal("2300k", profiles[2].BitrateFor(lowFps: true), "1080p 10fps bitrate changed");
        TestAssert.Equal(1920, profiles[2].Width, "1080p width changed");
        TestAssert.Equal(1080, profiles[2].Height, "1080p height changed");
        TestAssert.True(
            profiles.All(profile =>
                profile.FramesPerSecondFor(lowFps: false) == 30 &&
                profile.FramesPerSecondFor(lowFps: true) == 10),
            "Streaming FPS policy changed");
    }

    private static void SnapshotNormalizes()
    {
        var preparing = CreateSnapshot(StreamingRuntimeStatus.Preparing);
        var normalized = preparing.Normalize();
        TestAssert.Equal(
            StreamingRuntimeStatus.Offline,
            normalized.Status,
            "Inactive preparation leaked as a runtime-active status");

        var publicPreparation = preparing with
        {
            Revision = 2,
            PublicUrl = "https://example.test",
        };
        TestAssert.Equal(
            StreamingRuntimeStatus.Preparing,
            publicPreparation.Normalize().Status,
            "Preparation with a public URL was incorrectly normalized away");
    }

    private static void UnavailableControllerRejects()
    {
        var controller = new UnavailableStreamingController(snapshotModeEnabled: true);
        var original = controller.Current;
        var results = new[]
        {
            controller.Start(),
            controller.Stop("test"),
            controller.SetQuality("1080p"),
            controller.SetChatZoom(true),
            controller.SetSnapshotMode(false),
            controller.SetChatMode(true),
        };

        TestAssert.True(
            results.All(result => !result.Accepted &&
                result.Reason == "streaming_runtime_unavailable"),
            "Unavailable streaming accepted a mutation or changed its stable reason");
        TestAssert.True(
            results.All(result => result.Snapshot == original),
            "Unavailable streaming mutated its stable snapshot");
    }

    private static void PageProjectsController()
    {
        var persisted = new List<bool>();
        var controller = new TestStreamingController();
        var page = new StreamingPageViewModel(
            controller,
            featureAllowed: true,
            chatFeatureAllowed: true,
            persisted.Add);

        TestAssert.True(page.CanStart, "Offline stream did not expose start");
        page.StartCommand.Execute(null);
        TestAssert.Equal("В эфире", page.Status, "Online stream status was not projected");
        TestAssert.True(page.CanStop, "Online stream did not expose stop");
        TestAssert.Equal("https://stream.example/live/", page.StreamUrl, "Stream URL changed");

        page.Quality = "1080p";
        page.ChatZoomEnabled = true;
        page.SnapshotModeEnabled = true;
        TestAssert.Equal("1080p", page.Quality, "Quality mutation was not projected");
        TestAssert.Equal("Чат", page.CaptureArea, "Chat zoom was not projected");
        TestAssert.Equal("10", page.TargetFps, "10fps target changed");
        TestAssert.Equal("2300k", page.Bitrate, "10fps bitrate profile changed");
        TestAssert.True(persisted.SequenceEqual([true]), "10fps persistence did not run exactly once");

        page.StopCommand.Execute(null);
        TestAssert.Equal("Остановлен", page.Status, "Stopped stream status was not projected");
        TestAssert.True(page.CanStart, "Stopped stream did not restore start command");
    }

    private static void ChatModeAvailabilityIsExplicit()
    {
        var controller = new TestStreamingController();
        var withoutBridge = new StreamingPageViewModel(
            controller,
            featureAllowed: true,
            chatFeatureAllowed: false);
        var withBridge = new StreamingPageViewModel(
            controller,
            featureAllowed: true,
            chatFeatureAllowed: true);

        TestAssert.True(!withoutBridge.IsChatModeAvailable,
            "Missing chat bridge was presented as available");
        TestAssert.True(!withoutBridge.ToggleChatModeCommand.CanExecute(null),
            "Missing chat bridge admitted a chat command");
        TestAssert.True(withBridge.IsChatModeAvailable,
            "Composed chat bridge was hidden from presentation");
    }

    private static void OverviewProjectsSnapshot()
    {
        var overview = new OverviewPageViewModel(TelegramHostSettings.Default);
        var online = CreateSnapshot(
            StreamingRuntimeStatus.Online,
            active: true,
            snapshotMode: true) with
        {
            StartedAt = DateTimeOffset.UtcNow.AddMinutes(-1),
            ChatZoomEnabled = true,
        };

        overview.ApplyStreamingSnapshot(online);

        TestAssert.Equal("В эфире", overview.StreamStatus, "Overview stream status changed");
        TestAssert.True(
            overview.StreamDescription.Contains("720p", StringComparison.Ordinal) &&
            overview.StreamDescription.Contains("10 FPS", StringComparison.Ordinal) &&
            overview.StreamDescription.Contains("чат", StringComparison.Ordinal),
            "Overview stream summary lost quality, mode or area");
    }

    private static StreamingRuntimeSnapshot CreateSnapshot(
        StreamingRuntimeStatus status,
        bool active = false,
        bool snapshotMode = false) => new(
            Revision: 1,
            Status: status,
            Active: active,
            Quality: "720p",
            ChatZoomEnabled: false,
            SnapshotModeEnabled: snapshotMode,
            ChatModeEnabled: false,
            ChatActive: false,
            LocalUrl: null,
            PublicUrl: null,
            StreamUrl: null,
            StartedAt: active ? DateTimeOffset.UtcNow.AddMinutes(-1) : null,
            SecondsUntilAutoStop: active ? 240 : null,
            Error: string.Empty);

    private sealed class TestStreamingController : IStreamingController
    {
        private ulong revision = 1;

        public StreamingRuntimeSnapshot Current { get; private set; } =
            CreateSnapshot(StreamingRuntimeStatus.Offline);

        public event Action<StreamingRuntimeSnapshot>? SnapshotChanged;

        public StreamingCommandResult Start() => Update(Current with
        {
            Status = StreamingRuntimeStatus.Online,
            Active = true,
            StartedAt = DateTimeOffset.UtcNow.AddMinutes(-1),
            SecondsUntilAutoStop = 240,
            LocalUrl = "http://127.0.0.1:4242",
            PublicUrl = "https://stream.example",
            StreamUrl = "https://stream.example/live/",
        });

        public StreamingCommandResult Stop(string reason)
        {
            ArgumentException.ThrowIfNullOrWhiteSpace(reason);
            return Update(Current with
            {
                Status = StreamingRuntimeStatus.Offline,
                Active = false,
                StartedAt = null,
                SecondsUntilAutoStop = null,
                LocalUrl = null,
                PublicUrl = null,
                StreamUrl = null,
                ChatZoomEnabled = false,
                ChatModeEnabled = false,
                ChatActive = false,
            });
        }

        public StreamingCommandResult SetQuality(string quality) =>
            Update(Current with { Quality = StreamingQualityCatalog.Require(quality).Name });

        public StreamingCommandResult SetChatZoom(bool enabled) =>
            Update(Current with { ChatZoomEnabled = enabled });

        public StreamingCommandResult SetSnapshotMode(bool enabled) =>
            Update(Current with { SnapshotModeEnabled = enabled });

        public StreamingCommandResult SetChatMode(bool enabled) =>
            Update(Current with { ChatModeEnabled = enabled, ChatActive = enabled });

        private StreamingCommandResult Update(StreamingRuntimeSnapshot next)
        {
            Current = next with { Revision = ++revision };
            Current.Validate();
            SnapshotChanged?.Invoke(Current);
            return new StreamingCommandResult(true, "accepted", Current);
        }
    }
}
