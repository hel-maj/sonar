using Sonar.Fishing.Host.Overview;
using Sonar.Fishing.Host.ProductNavigation;
using Sonar.Fishing.Host.SettingsPage;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.Tests;

internal static class FishingProductModelTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("product_page_catalog_preserves_legacy_order_and_feature_redirect", PageCatalogPreservesUnion),
        new("recent_events_enforce_retention_and_presentation_bounds", RecentEventsAreBounded),
        new("recent_events_reject_replay_and_clear_atomically", RecentEventsRejectReplay),
        new("recent_events_expose_compact_local_time_without_raw_offset", RecentEventsFormatVisibleTime),
        new("settings_draft_tracks_dependencies_dirty_state_and_revision", SettingsDraftTracksState),
        new("settings_draft_updates_fish_policy_without_losing_other_policy", SettingsDraftPreservesPolicy),
        new("settings_draft_defers_newer_external_revision_until_discard", SettingsDraftDefersExternalRevision),
        new("settings_draft_blocks_semantically_duplicate_hotkeys", SettingsDraftBlocksHotkeyConflict),
        new("production_default_inventory_hotkey_is_tab", ProductionDefaultInventoryHotkeyIsTab),
        new("common_hotkey_shortcut_round_trips_unmodified_product_defaults", PlainHotkeysUseCommonShortcut),
    ];

    private static void PageCatalogPreservesUnion()
    {
        var pages = FishingProductPageCatalog.All;
        TestAssert.Equal(8, pages.Count, "Production page catalog count changed");
        TestAssert.True(
            pages.Select(page => page.Title).SequenceEqual(
            [
                "Обзор",
                "Лицензия",
                "Рыбалка",
                "Настройки",
                "Статистика",
                "Стрим",
                "Telegram",
                "О программе",
            ], StringComparer.Ordinal),
            "Production page order or copy changed");
        TestAssert.Equal(
            FishingProductPageId.License,
            FishingProductPageCatalog.InitialPage,
            "Initial production page must remain License");
        TestAssert.Equal(
            FishingProductPageId.License,
            FishingProductPageCatalog.ResolveAllowed(
                FishingProductPageId.Streaming,
                new HashSet<string>(StringComparer.Ordinal)),
            "Denied feature page did not redirect to License");
        TestAssert.Equal(
            FishingProductPageId.About,
            FishingProductPageCatalog.ResolveAllowed(
                FishingProductPageId.About,
                new HashSet<string>(StringComparer.Ordinal)),
            "Unlicensed About page was incorrectly gated");
    }

    private static void RecentEventsAreBounded()
    {
        var events = new RecentEventBuffer();
        for (ulong sequence = 1; sequence <= 410; sequence++)
        {
            events.Append(CreateEvent(sequence));
        }

        var presented = events.PresentationSnapshot();
        TestAssert.Equal(RecentEventBuffer.RetentionLimit, events.Count, "Event retention bound changed");
        TestAssert.Equal(RecentEventBuffer.PresentationLimit, presented.Count, "Event presentation bound changed");
        TestAssert.Equal<ulong>(331, presented[0].Sequence, "Presented event window does not contain newest 80");
        TestAssert.Equal<ulong>(410, presented[^1].Sequence, "Newest event was lost");
    }

    private static void RecentEventsRejectReplay()
    {
        var events = new RecentEventBuffer();
        events.Append(CreateEvent(7));
        TestAssert.Throws<InvalidOperationException>(
            () => events.Append(CreateEvent(7)),
            "Duplicate event sequence was accepted");
        var revision = events.Revision;
        events.Clear();
        TestAssert.Equal(0, events.Count, "Clear left retained events");
        TestAssert.Equal(revision + 1, events.Revision, "Clear did not advance presentation revision");
    }

    private static void RecentEventsFormatVisibleTime()
    {
        var visibleTime = CreateEvent(7).OccurredAtText;

        TestAssert.Equal(5, visibleTime.Length, "Recent event time is not compact");
        TestAssert.Equal(':', visibleTime[2], "Recent event time lost its hour/minute separator");
        TestAssert.True(
            visibleTime.Where((_, index) => index != 2).All(char.IsDigit),
            "Recent event time leaked a raw date, offset, or culture-specific suffix");
    }

    private static void SettingsDraftTracksState()
    {
        var model = new FishingSettingsPageViewModel(
            FishingRuntimeSettings.CreateDefault(revision: 9));
        TestAssert.True(!model.IsDirty, "Fresh settings draft is dirty");
        TestAssert.True(model.MealControlsEnabled, "Default meal controls changed");

        model.ReplaceDraft(model.Draft.WithBehavior(
            model.Draft.Behavior with
            {
                AutoMeal = false,
                FishWithoutLeader = true,
                FishWithoutNet = false,
            }));

        TestAssert.True(model.IsDirty, "Behavior edit did not mark settings dirty");
        TestAssert.True(!model.MealControlsEnabled, "Meal-dependent controls remained enabled");
        TestAssert.True(model.LeaderFallbackEnabled, "Leader fallback did not follow toggle");
        TestAssert.True(!model.NetFallbackEnabled, "Net fallback did not follow toggle");

        var next = model.BuildNextRevision();
        TestAssert.Equal<ulong>(10, next.Revision, "Settings revision did not advance exactly once");
        model.AcceptSaved(next);
        TestAssert.True(!model.IsDirty, "Accepted settings remained dirty");
        TestAssert.Throws<InvalidOperationException>(
            () => model.BuildNextRevision(),
            "Unchanged settings exposed Save operation");
    }

    private static void SettingsDraftPreservesPolicy()
    {
        var selection = new FishingSelectionPolicy(
            new Dictionary<string, bool> { ["marlin"] = false },
            new Dictionary<string, bool> { ["bag"] = true },
            new Dictionary<string, double> { ["marlin"] = 701.5 });
        var initial = FishingRuntimeSettings.CreateDefault(revision: 3) with
        {
            Selection = selection,
        };
        var model = new FishingSettingsPageViewModel(initial);
        model.ReplaceDraft(model.Draft.WithFishKeep("marlin", true));
        var saved = model.BuildNextRevision();

        TestAssert.True(saved.Selection.FishKeep["marlin"], "Fish keep edit was lost");
        TestAssert.True(saved.Selection.GarbageDisposal["bag"], "Unrelated garbage policy was lost");
        TestAssert.Equal(701.5, saved.Selection.CustomFishPrices["marlin"], "Custom price was lost");
    }

    private static void SettingsDraftDefersExternalRevision()
    {
        var initial = FishingRuntimeSettings.CreateDefault(revision: 3);
        var model = new FishingSettingsPageViewModel(initial, _ => { });
        model.AutoMeal = false;
        var external = FishingRuntimeSettings.CreateDefault(revision: 4) with
        {
            Selection = new FishingSelectionPolicy(
                new Dictionary<string, bool> { ["marlin"] = false },
                new Dictionary<string, bool>(),
                new Dictionary<string, double> { ["marlin"] = 701 }),
        };

        model.ApplyExternalSettings(external);

        TestAssert.True(model.IsDirty, "Newer external settings clobbered a dirty draft");
        TestAssert.True(
            model.SaveStatus.Contains("изменились", StringComparison.Ordinal),
            "External revision conflict was not explained");
        model.DiscardChanges();
        TestAssert.True(!model.IsDirty, "Discard did not accept the pending external revision");
        TestAssert.True(
            !model.FishColumnOne.Concat(model.FishColumnTwo).Single(row => row.Id == "marlin").Keep,
            "Pending external fish policy was not applied");
        model.ReplaceDraft(model.Draft.WithFishKeep("marlin", true));
        TestAssert.Equal<ulong>(5, model.BuildNextRevision().Revision, "External revision was not adopted");
    }

    private static void SettingsDraftBlocksHotkeyConflict()
    {
        FishingRuntimeSettings? persisted = null;
        var model = new FishingSettingsPageViewModel(
            FishingRuntimeSettings.CreateDefault(revision: 2),
            settings => persisted = settings);

        model.InventoryShortcut = model.StartStopShortcut;

        TestAssert.True(model.HasHotkeyConflicts, "Duplicate hotkey conflict was not detected");
        TestAssert.True(
            model.HotkeyConflictStatus.Contains("Старт / стоп", StringComparison.Ordinal) &&
            model.HotkeyConflictStatus.Contains("Инвентарь", StringComparison.Ordinal),
            "Hotkey conflict did not identify both product actions");
        TestAssert.True(!model.SaveCommand.CanExecute(null), "Conflicting hotkeys remained saveable");
        TestAssert.Throws<InvalidOperationException>(
            () => model.BuildNextRevision(),
            "Conflicting hotkeys produced a runtime settings snapshot");

        model.InventoryShortcut = HotkeyGesture.ParseInvariant("Ctrl+I");
        TestAssert.True(!model.HasHotkeyConflicts, "Resolved hotkey conflict remained active");
        model.SaveCommand.Execute(null);
        TestAssert.True(persisted is not null, "Resolved hotkey settings were not saved");
    }

    private static void PlainHotkeysUseCommonShortcut()
    {
        var model = new FishingSettingsPageViewModel(
            FishingRuntimeSettings.CreateDefault(revision: 1));
        var shortcuts = new[]
        {
            model.InventoryShortcut,
            model.UseItemShortcut,
            model.BackpackMoveShortcut,
            model.DiscardShortcut,
            model.ChatShortcut,
        };

        TestAssert.True(
            shortcuts.Select(shortcut => shortcut.ToInvariantString()).SequenceEqual(
                ["Tab", "E", "R", "Q", "T"],
                StringComparer.OrdinalIgnoreCase),
            "Common shortcut contract did not preserve the unmodified product hotkeys");
        TestAssert.True(
            shortcuts.All(shortcut => !string.IsNullOrWhiteSpace(shortcut.ToDisplayString())),
            "Common shortcut contract rendered an unmodified product hotkey as empty");
    }

    private static void ProductionDefaultInventoryHotkeyIsTab()
    {
        var defaults = FishingRuntimeSettings.CreateDefault();

        TestAssert.Equal("Tab", defaults.Hotkeys.Inventory,
            "Production inventory hotkey default is not the confirmed Majestic binding");
        TestAssert.Equal("Tab", HotkeyGesture.ParseInvariant(defaults.Hotkeys.Inventory).ToInvariantString(),
            "Common hotkey contract changed the canonical inventory binding");
    }

    private static FishingEventSnapshot CreateEvent(ulong sequence) => new(
        sequence,
        DateTimeOffset.UnixEpoch.AddSeconds(sequence),
        FishingEventTone.Neutral,
        "fish",
        $"event-{sequence}");
}
