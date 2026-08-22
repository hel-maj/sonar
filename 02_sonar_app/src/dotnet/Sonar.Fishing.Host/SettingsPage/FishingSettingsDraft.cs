using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.SettingsPage;

public sealed class FishingSettingsDraft
{
    private FishingSettingsDraft(
        RecoveryThresholds thresholds,
        FishingBehaviorPolicy behavior,
        FishingHotkeys hotkeys,
        FishingSelectionPolicy selection)
    {
        Thresholds = thresholds;
        Behavior = behavior;
        Hotkeys = hotkeys;
        Selection = selection;
    }

    public RecoveryThresholds Thresholds { get; }

    public FishingBehaviorPolicy Behavior { get; }

    public FishingHotkeys Hotkeys { get; }

    public FishingSelectionPolicy Selection { get; }

    public bool MealControlsEnabled => Behavior.AutoMeal;

    public bool LeaderFallbackEnabled => Behavior.FishWithoutLeader;

    public bool NetFallbackEnabled => Behavior.FishWithoutNet;

    public static FishingSettingsDraft FromSettings(FishingRuntimeSettings settings)
    {
        ArgumentNullException.ThrowIfNull(settings);
        settings.Validate();
        return new FishingSettingsDraft(
            settings.Thresholds,
            settings.Behavior,
            settings.Hotkeys,
            CopySelection(settings.Selection));
    }

    public FishingSettingsDraft WithThresholds(RecoveryThresholds thresholds)
    {
        ArgumentNullException.ThrowIfNull(thresholds);
        thresholds.Validate();
        return new FishingSettingsDraft(thresholds, Behavior, Hotkeys, Selection);
    }

    public FishingSettingsDraft WithBehavior(FishingBehaviorPolicy behavior)
    {
        ArgumentNullException.ThrowIfNull(behavior);
        return Validated(new FishingSettingsDraft(Thresholds, behavior, Hotkeys, Selection));
    }

    public FishingSettingsDraft WithHotkeys(FishingHotkeys hotkeys)
    {
        ArgumentNullException.ThrowIfNull(hotkeys);
        hotkeys.Validate();
        return new FishingSettingsDraft(Thresholds, Behavior, hotkeys, Selection);
    }

    public FishingSettingsDraft WithFishKeep(string fishId, bool keep)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(fishId);
        var keepPolicy = new SortedDictionary<string, bool>(StringComparer.Ordinal);
        foreach (var pair in Selection.FishKeep)
        {
            keepPolicy.Add(pair.Key, pair.Value);
        }
        keepPolicy[fishId] = keep;
        return WithSelection(keepPolicy);
    }

    public FishingSettingsDraft SetAllFishKeep(
        IEnumerable<string> fishIds,
        bool keep)
    {
        ArgumentNullException.ThrowIfNull(fishIds);
        var keepPolicy = new SortedDictionary<string, bool>(StringComparer.Ordinal);
        foreach (var fishId in fishIds)
        {
            ArgumentException.ThrowIfNullOrWhiteSpace(fishId);
            if (!keepPolicy.TryAdd(fishId, keep))
            {
                throw new ArgumentException("settings_duplicate_fish_id", nameof(fishIds));
            }
        }
        return WithSelection(keepPolicy);
    }

    public FishingRuntimeSettings BuildSettings(ulong revision)
    {
        var settings = new FishingRuntimeSettings(
            revision,
            Thresholds,
            Behavior,
            Hotkeys,
            CopySelection(Selection));
        settings.Validate();
        return settings;
    }

    public bool ContentEquals(FishingSettingsDraft other)
    {
        ArgumentNullException.ThrowIfNull(other);
        return Thresholds == other.Thresholds &&
            Behavior == other.Behavior &&
            Hotkeys == other.Hotkeys &&
            Selection.FishKeep.SequenceEqual(other.Selection.FishKeep) &&
            Selection.GarbageDisposal.SequenceEqual(other.Selection.GarbageDisposal) &&
            Selection.CustomFishPrices.SequenceEqual(other.Selection.CustomFishPrices);
    }

    private FishingSettingsDraft WithSelection(
        IEnumerable<KeyValuePair<string, bool>> fishKeep) => new(
            Thresholds,
            Behavior,
            Hotkeys,
            new FishingSelectionPolicy(
                fishKeep,
                Selection.GarbageDisposal,
                Selection.CustomFishPrices));

    private static FishingSettingsDraft Validated(FishingSettingsDraft draft)
    {
        _ = draft.BuildSettings(1);
        return draft;
    }

    private static FishingSelectionPolicy CopySelection(FishingSelectionPolicy selection)
    {
        ArgumentNullException.ThrowIfNull(selection);
        return new FishingSelectionPolicy(
            selection.FishKeep,
            selection.GarbageDisposal,
            selection.CustomFishPrices);
    }
}
