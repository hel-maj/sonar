using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Sonar.Fishing.Host.ProductCatalog;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.SettingsPage;

public sealed record FishingSettingsOption<T>(T Value, string Label)
    where T : struct, Enum;

public sealed class FishingSettingsPageViewModel : ObservableObject
{
    private FishingSettingsDraft _saved;
    private FishingSettingsDraft _draft;
    private ulong _savedRevision;
    private readonly Action<FishingRuntimeSettings>? saveHandler;
    private readonly IReadOnlyList<FishingFishSelectionViewModel> fishRows;
    private FishingRuntimeSettings? pendingExternalSettings;
    private string saveStatus = string.Empty;

    public FishingSettingsPageViewModel(
        FishingRuntimeSettings settings,
        Action<FishingRuntimeSettings>? saveHandler = null)
    {
        ArgumentNullException.ThrowIfNull(settings);
        settings.Validate();
        _savedRevision = settings.Revision;
        _saved = FishingSettingsDraft.FromSettings(settings);
        _draft = FishingSettingsDraft.FromSettings(settings);
        this.saveHandler = saveHandler;
        fishRows = FishingFishCatalog.All.Select(fish =>
            new FishingFishSelectionViewModel(
                fish,
                IsFishKept(_draft.Selection, fish.Id),
                UpdateFishKeep)).ToArray();
        var firstColumnCount = (fishRows.Count + 1) / 2;
        FishColumnOne = fishRows.Take(firstColumnCount).ToArray();
        FishColumnTwo = fishRows.Skip(firstColumnCount).ToArray();
        SaveCommand = new RelayCommand(
            Save,
            () => IsDirty && this.saveHandler is not null && !HasHotkeyConflicts);
        DiscardCommand = new RelayCommand(DiscardChanges, () => IsDirty);
        SelectAllFishCommand = new RelayCommand(() => SetAllFishKeep(true));
        ClearAllFishCommand = new RelayCommand(() => SetAllFishKeep(false));
    }

    public FishingSettingsDraft Draft
    {
        get => _draft;
        private set
        {
            if (ReferenceEquals(_draft, value))
            {
                return;
            }
            _draft = value;
            OnPropertyChanged();
            OnPropertyChanged(nameof(IsDirty));
            OnPropertyChanged(nameof(MealControlsEnabled));
            OnPropertyChanged(nameof(LeaderFallbackEnabled));
            OnPropertyChanged(nameof(NetFallbackEnabled));
            OnPropertyChanged(nameof(AutoMeal));
            OnPropertyChanged(nameof(AutoChangeBait));
            OnPropertyChanged(nameof(StoreInTrunk));
            OnPropertyChanged(nameof(StartStopSoundEnabled));
            OnPropertyChanged(nameof(FishWithoutLeader));
            OnPropertyChanged(nameof(FishWithoutNet));
            OnPropertyChanged(nameof(OverweightAction));
            OnPropertyChanged(nameof(LeaderDepletedAction));
            OnPropertyChanged(nameof(NetDepletedAction));
            OnPropertyChanged(nameof(EquipmentDepletedAction));
            OnPropertyChanged(nameof(FoodDepletedAction));
            OnPropertyChanged(nameof(FoodThreshold));
            OnPropertyChanged(nameof(WaterThreshold));
            OnPropertyChanged(nameof(HealthThreshold));
            OnPropertyChanged(nameof(StartStopShortcut));
            OnPropertyChanged(nameof(InventoryShortcut));
            OnPropertyChanged(nameof(UseItemShortcut));
            OnPropertyChanged(nameof(BackpackMoveShortcut));
            OnPropertyChanged(nameof(DiscardShortcut));
            OnPropertyChanged(nameof(ChatShortcut));
            OnPropertyChanged(nameof(HasHotkeyConflicts));
            OnPropertyChanged(nameof(HotkeyConflictStatus));
            SyncFishRows();
            SaveCommand.NotifyCanExecuteChanged();
            DiscardCommand.NotifyCanExecuteChanged();
        }
    }

    public bool IsDirty => !Draft.ContentEquals(_saved);

    public bool MealControlsEnabled => Draft.MealControlsEnabled;

    public bool LeaderFallbackEnabled => Draft.LeaderFallbackEnabled;

    public bool NetFallbackEnabled => Draft.NetFallbackEnabled;

    public bool CanPersist => saveHandler is not null;

    public bool HasHotkeyConflicts =>
        FishingHotkeyConflictPolicy.FindConflictingLabels(Draft.Hotkeys).Count > 0;

    public string HotkeyConflictStatus
    {
        get
        {
            var labels = FishingHotkeyConflictPolicy.FindConflictingLabels(Draft.Hotkeys);
            return labels.Count == 0
                ? string.Empty
                : $"Одна клавиша назначена нескольким действиям: {string.Join(", ", labels)}.";
        }
    }

    public string SaveStatus
    {
        get => saveStatus;
        private set => SetProperty(ref saveStatus, value);
    }

    public bool AutoMeal
    {
        get => Draft.Behavior.AutoMeal;
        set => UpdateBehavior(Draft.Behavior with { AutoMeal = value });
    }

    public bool AutoChangeBait
    {
        get => Draft.Behavior.AutoChangeBait;
        set => UpdateBehavior(Draft.Behavior with { AutoChangeBait = value });
    }

    public bool StoreInTrunk
    {
        get => Draft.Behavior.StoreInTrunk;
        set => UpdateBehavior(Draft.Behavior with { StoreInTrunk = value });
    }

    public bool StartStopSoundEnabled
    {
        get => Draft.Behavior.StartStopSoundEnabled;
        set => UpdateBehavior(Draft.Behavior with { StartStopSoundEnabled = value });
    }

    public bool FishWithoutLeader
    {
        get => Draft.Behavior.FishWithoutLeader;
        set => UpdateBehavior(Draft.Behavior with { FishWithoutLeader = value });
    }

    public bool FishWithoutNet
    {
        get => Draft.Behavior.FishWithoutNet;
        set => UpdateBehavior(Draft.Behavior with { FishWithoutNet = value });
    }

    public OverweightPolicyAction OverweightAction
    {
        get => Draft.Behavior.OverweightAction;
        set => UpdateBehavior(Draft.Behavior with { OverweightAction = value });
    }

    public DepletedPolicyAction LeaderDepletedAction
    {
        get => Draft.Behavior.LeaderDepletedAction;
        set => UpdateBehavior(Draft.Behavior with { LeaderDepletedAction = value });
    }

    public DepletedPolicyAction NetDepletedAction
    {
        get => Draft.Behavior.NetDepletedAction;
        set => UpdateBehavior(Draft.Behavior with { NetDepletedAction = value });
    }

    public EquipmentDepletedPolicyAction EquipmentDepletedAction
    {
        get => Draft.Behavior.EquipmentDepletedAction;
        set => UpdateBehavior(Draft.Behavior with { EquipmentDepletedAction = value });
    }

    public FoodDepletedPolicyAction FoodDepletedAction
    {
        get => Draft.Behavior.FoodDepletedAction;
        set => UpdateBehavior(Draft.Behavior with { FoodDepletedAction = value });
    }

    public IReadOnlyList<FishingSettingsOption<OverweightPolicyAction>> OverweightOptions { get; } =
    [
        new(OverweightPolicyAction.Release, "Отпускать улов"),
        new(OverweightPolicyAction.Stop, "Остановить рыбалку"),
        new(OverweightPolicyAction.ExitGame, "Выйти из игры"),
    ];

    public IReadOnlyList<FishingSettingsOption<DepletedPolicyAction>> DepletedOptions { get; } =
    [
        new(DepletedPolicyAction.Stop, "Остановить рыбалку"),
        new(DepletedPolicyAction.ExitGame, "Выйти из игры"),
    ];

    public IReadOnlyList<FishingSettingsOption<EquipmentDepletedPolicyAction>> EquipmentOptions { get; } =
    [
        new(EquipmentDepletedPolicyAction.Stop, "Остановить рыбалку"),
        new(EquipmentDepletedPolicyAction.ExitGame, "Выйти из игры"),
        new(EquipmentDepletedPolicyAction.ShutdownPc, "Выключить компьютер"),
    ];

    public IReadOnlyList<FishingSettingsOption<FoodDepletedPolicyAction>> FoodOptions { get; } =
    [
        new(FoodDepletedPolicyAction.Continue, "Продолжить рыбалку"),
        new(FoodDepletedPolicyAction.Stop, "Остановить рыбалку"),
        new(FoodDepletedPolicyAction.ExitGame, "Выйти из игры"),
        new(FoodDepletedPolicyAction.ShutdownPc, "Выключить компьютер"),
    ];

    public int FoodThreshold
    {
        get => Draft.Thresholds.Food;
        set => UpdateThresholds(Draft.Thresholds with { Food = value });
    }

    public int WaterThreshold
    {
        get => Draft.Thresholds.Water;
        set => UpdateThresholds(Draft.Thresholds with { Water = value });
    }

    public int HealthThreshold
    {
        get => Draft.Thresholds.Health;
        set => UpdateThresholds(Draft.Thresholds with { Health = value });
    }

    public HotkeyGesture StartStopShortcut
    {
        get => HotkeyGesture.ParseInvariant(Draft.Hotkeys.StartStop);
        set => UpdateHotkeys(Draft.Hotkeys with { StartStop = value.ToInvariantString() });
    }

    public HotkeyGesture InventoryShortcut
    {
        get => HotkeyGesture.ParseInvariant(Draft.Hotkeys.Inventory);
        set => UpdateHotkeys(Draft.Hotkeys with { Inventory = value.ToInvariantString() });
    }

    public HotkeyGesture UseItemShortcut
    {
        get => HotkeyGesture.ParseInvariant(Draft.Hotkeys.UseItem);
        set => UpdateHotkeys(Draft.Hotkeys with { UseItem = value.ToInvariantString() });
    }

    public HotkeyGesture BackpackMoveShortcut
    {
        get => HotkeyGesture.ParseInvariant(Draft.Hotkeys.BackpackMove);
        set => UpdateHotkeys(Draft.Hotkeys with { BackpackMove = value.ToInvariantString() });
    }

    public HotkeyGesture DiscardShortcut
    {
        get => HotkeyGesture.ParseInvariant(Draft.Hotkeys.Discard);
        set => UpdateHotkeys(Draft.Hotkeys with { Discard = value.ToInvariantString() });
    }

    public HotkeyGesture ChatShortcut
    {
        get => HotkeyGesture.ParseInvariant(Draft.Hotkeys.Chat);
        set => UpdateHotkeys(Draft.Hotkeys with { Chat = value.ToInvariantString() });
    }

    public IRelayCommand SaveCommand { get; }

    public IRelayCommand DiscardCommand { get; }

    public IRelayCommand SelectAllFishCommand { get; }

    public IRelayCommand ClearAllFishCommand { get; }

    public IReadOnlyList<FishingFishSelectionViewModel> FishColumnOne { get; }

    public IReadOnlyList<FishingFishSelectionViewModel> FishColumnTwo { get; }

    public void ReplaceDraft(FishingSettingsDraft draft)
    {
        ArgumentNullException.ThrowIfNull(draft);
        _ = draft.BuildSettings(1);
        Draft = draft;
    }

    public FishingRuntimeSettings BuildNextRevision()
    {
        if (!IsDirty)
        {
            throw new InvalidOperationException("settings_draft_unchanged");
        }
        if (_savedRevision == ulong.MaxValue)
        {
            throw new InvalidOperationException("settings_revision_exhausted");
        }
        if (HasHotkeyConflicts)
        {
            throw new InvalidOperationException("settings_hotkey_conflict");
        }
        return Draft.BuildSettings(_savedRevision + 1);
    }

    public void AcceptSaved(FishingRuntimeSettings accepted)
    {
        ArgumentNullException.ThrowIfNull(accepted);
        accepted.Validate();
        if (accepted.Revision <= _savedRevision)
        {
            throw new InvalidOperationException("settings_revision_not_advanced");
        }
        _savedRevision = accepted.Revision;
        _saved = FishingSettingsDraft.FromSettings(accepted);
        pendingExternalSettings = null;
        Draft = FishingSettingsDraft.FromSettings(accepted);
    }

    public void ApplyExternalSettings(FishingRuntimeSettings settings)
    {
        ArgumentNullException.ThrowIfNull(settings);
        settings.Validate();
        if (settings.Revision <= _savedRevision)
        {
            return;
        }
        if (IsDirty)
        {
            pendingExternalSettings = settings;
            SaveStatus = "Настройки изменились в другой части программы. Отмените правки и повторите.";
            return;
        }
        AcceptSaved(settings);
        SaveStatus = string.Empty;
    }

    public void DiscardChanges()
    {
        if (pendingExternalSettings is { } external)
        {
            AcceptSaved(external);
            SaveStatus = string.Empty;
            return;
        }
        Draft = FishingSettingsDraft.FromSettings(
            _saved.BuildSettings(_savedRevision));
    }

    private void Save()
    {
        if (saveHandler is null)
        {
            throw new InvalidOperationException("settings_persistence_unavailable");
        }
        var next = BuildNextRevision();
        try
        {
            saveHandler(next);
        }
        catch (InvalidOperationException exception)
            when (exception.Message == "settings_revision_stale")
        {
            SaveStatus = "Настройки уже изменились. Отмените правки, чтобы загрузить актуальную версию.";
            return;
        }
        AcceptSaved(next);
        SaveStatus = string.Empty;
    }

    private void UpdateBehavior(FishingBehaviorPolicy behavior)
    {
        SaveStatus = string.Empty;
        ReplaceDraft(Draft.WithBehavior(behavior));
    }

    private void UpdateThresholds(RecoveryThresholds thresholds)
    {
        SaveStatus = string.Empty;
        ReplaceDraft(Draft.WithThresholds(thresholds));
    }

    private void UpdateHotkeys(FishingHotkeys hotkeys)
    {
        SaveStatus = string.Empty;
        ReplaceDraft(Draft.WithHotkeys(hotkeys));
    }

    private void UpdateFishKeep(string fishId, bool keep)
    {
        SaveStatus = string.Empty;
        ReplaceDraft(Draft.WithFishKeep(fishId, keep));
    }

    private void SetAllFishKeep(bool keep)
    {
        SaveStatus = string.Empty;
        ReplaceDraft(Draft.SetAllFishKeep(FishingFishCatalog.AllIds, keep));
    }

    private void SyncFishRows()
    {
        foreach (var row in fishRows)
        {
            row.ApplyKeep(IsFishKept(Draft.Selection, row.Id));
        }
    }

    private static bool IsFishKept(FishingSelectionPolicy selection, string fishId) =>
        !selection.FishKeep.TryGetValue(fishId, out var keep) || keep;

}
