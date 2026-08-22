namespace Sonar.Fishing.Host.TelegramPage;

public enum TelegramNotificationKind
{
    Catch = 1,
    StartStop = 2,
    Meal = 3,
    InventoryFull = 4,
    InventorySpaceLow = 5,
    BaitTired = 6,
    FocusLost = 7,
}

public sealed record TelegramNotificationDescriptor(
    TelegramNotificationKind Kind,
    string Label,
    string NotificationField,
    string SoundField);

public static class TelegramNotificationCatalog
{
    public static IReadOnlyList<TelegramNotificationDescriptor> All { get; } =
        Array.AsReadOnly<TelegramNotificationDescriptor>(
        [
            new(TelegramNotificationKind.Catch, "Поймана рыба", "notify_catch", "sound_catch"),
            new(TelegramNotificationKind.StartStop, "Запуск/Остановка", "notify_start_stop", "sound_start_stop"),
            new(TelegramNotificationKind.Meal, "Питание", "notify_meal", "sound_meal"),
            new(TelegramNotificationKind.InventoryFull, "Закончилось место", "notify_inventory_full", "sound_inventory_full"),
            new(TelegramNotificationKind.InventorySpaceLow, "Мало места", "notify_inventory_space_low", "sound_inventory_space_low"),
            new(TelegramNotificationKind.BaitTired, "Устала от приманки", "notify_bait_tired", "sound_bait_tired"),
            new(TelegramNotificationKind.FocusLost, "Потеря фокуса игры", "notify_focus_lost", "sound_focus_lost"),
        ]);

    public static bool TryFindNotificationField(
        string field,
        out TelegramNotificationKind kind) => TryFind(
            field,
            descriptor => descriptor.NotificationField,
            out kind);

    public static bool TryFindSoundField(
        string field,
        out TelegramNotificationKind kind) => TryFind(
            field,
            descriptor => descriptor.SoundField,
            out kind);

    private static bool TryFind(
        string field,
        Func<TelegramNotificationDescriptor, string> selector,
        out TelegramNotificationKind kind)
    {
        foreach (var descriptor in All)
        {
            if (string.Equals(selector(descriptor), field, StringComparison.Ordinal))
            {
                kind = descriptor.Kind;
                return true;
            }
        }
        kind = default;
        return false;
    }
}
