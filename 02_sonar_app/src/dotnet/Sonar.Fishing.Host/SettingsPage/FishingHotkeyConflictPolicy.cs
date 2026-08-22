using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.SettingsPage;

public static class FishingHotkeyConflictPolicy
{
    private static readonly (string Label, Func<FishingHotkeys, string> Select)[] Bindings =
    [
        ("Старт / стоп", hotkeys => hotkeys.StartStop),
        ("Инвентарь", hotkeys => hotkeys.Inventory),
        ("Использовать предмет", hotkeys => hotkeys.UseItem),
        ("Переместить в рюкзак", hotkeys => hotkeys.BackpackMove),
        ("Выбросить", hotkeys => hotkeys.Discard),
        ("Чат", hotkeys => hotkeys.Chat),
    ];

    public static IReadOnlyList<string> FindConflictingLabels(FishingHotkeys hotkeys)
    {
        ArgumentNullException.ThrowIfNull(hotkeys);
        hotkeys.Validate();
        return Bindings
            .Select(binding => new
            {
                binding.Label,
                Gesture = HotkeyContract.NormalizeForComparison(binding.Select(hotkeys)),
            })
            .GroupBy(binding => binding.Gesture, StringComparer.Ordinal)
            .Where(group => group.Count() > 1)
            .SelectMany(group => group.Select(binding => binding.Label))
            .ToArray();
    }
}
