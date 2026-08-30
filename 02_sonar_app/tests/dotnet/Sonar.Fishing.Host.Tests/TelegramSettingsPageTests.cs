using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.TelegramPage;

namespace Sonar.Fishing.Host.Tests;

internal static class TelegramSettingsPageTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("telegram_draft_normalizes_legacy_input_semantics", DraftNormalizesInput),
        new("telegram_enable_requires_matching_available_configuration", EnableRequiresAvailability),
        new("telegram_enabled_credentials_lock_and_sounds_are_preserved", EnabledCredentialsLock),
        new("telegram_save_fails_closed_when_availability_changes", SaveFailsClosed),
        new("telegram_enabled_configuration_survives_transient_unavailability", EnabledSurvivesOutage),
        new("telegram_draft_publishes_availability_candidate_changes", CandidateChangesArePublished),
    ];

    private static void DraftNormalizesInput()
    {
        var draft = TelegramSettingsDraft.FromSettings(
                TelegramHostSettings.Default,
                "  fake-token  ")
            .WithCredentials("  fake-token  ", "42, broken, 77, 42, -8")
            .WithInventorySpaceLowThreshold("0,5");

        TestAssert.Equal("fake-token", draft.BotToken, "Bot token was not trimmed");
        TestAssert.True(draft.AdminIds.SequenceEqual([42L, 77L]), "Admin ID parsing changed");
        TestAssert.Equal("42,77", draft.AdminIdsText, "Admin ID normalization changed");
        TestAssert.Equal(1.0, draft.InventorySpaceLowThresholdKg, "Threshold minimum changed");
        TestAssert.Equal("1.00", draft.InventorySpaceLowThresholdText, "Threshold display changed");
        TestAssert.True(
            TelegramSettingsDraft.IsThresholdTextAccepted("999999,99"),
            "Legacy threshold validator rejected a valid value");
        TestAssert.True(
            !TelegramSettingsDraft.IsThresholdTextAccepted("1000000"),
            "Legacy six-digit threshold bound was lost");
    }

    private static void EnableRequiresAvailability()
    {
        var settings = new TelegramHostSettings(
            false,
            [42],
            1.0,
            TelegramHostSettings.Default.Notifications);
        var model = new TelegramSettingsPageViewModel(
            settings,
            "fake-token",
            featureAllowed: true);

        TestAssert.True(!model.CanEnable, "Unknown Telegram availability allowed enable");
        TestAssert.Equal("Telegram недоступен", model.EnableBlockReason, "Unknown block copy changed");
        model.UpdateAccessPolicy(
            true,
            TelegramAvailability.Checking("fake-token", [42]));
        TestAssert.Equal(
            "подождите завершения подключения",
            model.EnableBlockReason,
            "Availability checking copy changed");
        model.UpdateAccessPolicy(
            true,
            TelegramAvailability.Available("fake-token", [42]));

        TestAssert.True(model.CanEnable, "Matching available configuration stayed blocked");
        TestAssert.True(model.TrySetEnabled(true, out var reason), "Available Telegram could not enable");
        TestAssert.Equal(string.Empty, reason, "Available Telegram returned a block reason");
        TestAssert.Equal("Включен", model.StatusText, "Enabled status copy changed");
    }

    private static void EnabledCredentialsLock()
    {
        var sounds = TelegramSoundSettings.AllEnabled with { InventoryFull = false };
        var settings = new TelegramHostSettings(
            false,
            [42],
            1.0,
            TelegramHostSettings.Default.Notifications,
            sounds);
        var model = new TelegramSettingsPageViewModel(
            settings,
            "fake-token",
            true,
            TelegramAvailability.Available("fake-token", [42]));
        TestAssert.True(model.TrySetEnabled(true, out _), "Telegram did not enable");

        TestAssert.True(!model.CredentialsEditable, "Enabled Telegram credentials remained editable");
        TestAssert.Throws<InvalidOperationException>(
            () => model.UpdateCredentials("replacement", "77"),
            "Enabled Telegram accepted credential mutation");
        model.ReplaceNotifications(model.Draft.Notifications with { FocusLost = true });
        var result = model.BuildSaveResult();

        TestAssert.True(result.Settings.Enabled, "Available Telegram save was disabled");
        TestAssert.True(result.Settings.Notifications.FocusLost, "Notification edit was lost");
        TestAssert.True(!result.Settings.Sounds.InventoryFull, "Hidden sound policy was lost");
        TestAssert.Equal("fake-token", result.BotToken, "Token changed during save");
    }

    private static void SaveFailsClosed()
    {
        var settings = new TelegramHostSettings(
            false,
            [42],
            1.0,
            TelegramHostSettings.Default.Notifications);
        var model = new TelegramSettingsPageViewModel(
            settings,
            "fake-token",
            true,
            TelegramAvailability.Available("fake-token", [42]));
        TestAssert.True(model.TrySetEnabled(true, out _), "Telegram did not enable");

        model.UpdateAccessPolicy(
            true,
            TelegramAvailability.Unavailable(
                "fake-token",
                [42],
                "Telegram API недоступен"));
        var result = model.BuildSaveResult();

        TestAssert.True(!result.Settings.Enabled, "Unavailable Telegram remained enabled on save");
        TestAssert.True(result.EnableRequestRejected, "Rejected enable request was not reported");
        TestAssert.Equal(
            "Telegram API недоступен",
            result.EnableBlockReason,
            "Availability error copy changed");
    }

    private static void EnabledSurvivesOutage()
    {
        var settings = new TelegramHostSettings(
            true,
            [42],
            1.0,
            TelegramHostSettings.Default.Notifications);
        var model = new TelegramSettingsPageViewModel(
            settings,
            "fake-token",
            true,
            TelegramAvailability.Unavailable(
                "fake-token",
                [42],
                "Telegram недоступен"));

        var result = model.BuildSaveResult();

        TestAssert.True(result.Settings.Enabled, "Transient outage disabled persisted Telegram");
        TestAssert.True(!result.EnableRequestRejected, "Existing enabled state became a new enable request");
        TestAssert.Equal("Недоступен", model.StatusText, "Outage status was hidden");
    }

    private static void CandidateChangesArePublished()
    {
        var model = new TelegramSettingsPageViewModel(
            TelegramHostSettings.Default,
            string.Empty,
            featureAllowed: true);
        var candidates = new List<TelegramAvailabilityCandidate>();
        model.AvailabilityCandidateChanged += candidates.Add;

        model.UpdateCredentials("  fake-token  ", "77,42");
        model.DiscardChanges();

        TestAssert.Equal(2, candidates.Count, "Draft and discard did not both publish candidates");
        TestAssert.True(
            candidates[0].Identity.Equals(
                TelegramConfigurationIdentity.Create("fake-token", [42, 77])),
            "Draft candidate identity was not normalized");
        TestAssert.True(
            !candidates[1].ConfigurationReady,
            "Discard did not restore the saved empty candidate");
        TestAssert.True(
            !candidates[0].ToString().Contains("fake-token", StringComparison.Ordinal),
            "Availability candidate string exposed the token");
    }
}
