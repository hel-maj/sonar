using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public static class TelegramSettingsReducer
{
    public static bool TryApply(
        TelegramHostSettings settings,
        TelegramInboundDecision decision,
        out TelegramHostSettings updated)
    {
        ArgumentNullException.ThrowIfNull(settings);
        ArgumentNullException.ThrowIfNull(decision);
        if (decision.Notification is not { } notification)
        {
            updated = settings;
            return false;
        }

        if (decision.Kind == TelegramInboundIntentKind.ToggleNotification)
        {
            updated = Copy(settings, notifications: Toggle(settings.Notifications, notification));
            return true;
        }
        if (decision.Kind == TelegramInboundIntentKind.ToggleNotificationSound)
        {
            updated = Copy(settings, sounds: Toggle(settings.Sounds, notification));
            return true;
        }
        updated = settings;
        return false;
    }

    private static TelegramNotificationSettings Toggle(
        TelegramNotificationSettings settings,
        TelegramNotificationKind kind) => kind switch
        {
            TelegramNotificationKind.Catch => settings with { Catch = !settings.Catch },
            TelegramNotificationKind.StartStop => settings with { StartStop = !settings.StartStop },
            TelegramNotificationKind.Meal => settings with { Meal = !settings.Meal },
            TelegramNotificationKind.InventoryFull => settings with { InventoryFull = !settings.InventoryFull },
            TelegramNotificationKind.InventorySpaceLow => settings with { InventorySpaceLow = !settings.InventorySpaceLow },
            TelegramNotificationKind.BaitTired => settings with { BaitTired = !settings.BaitTired },
            TelegramNotificationKind.FocusLost => settings with { FocusLost = !settings.FocusLost },
            _ => throw new ArgumentOutOfRangeException(nameof(kind)),
        };

    private static TelegramSoundSettings Toggle(
        TelegramSoundSettings settings,
        TelegramNotificationKind kind) => kind switch
        {
            TelegramNotificationKind.Catch => settings with { Catch = !settings.Catch },
            TelegramNotificationKind.StartStop => settings with { StartStop = !settings.StartStop },
            TelegramNotificationKind.Meal => settings with { Meal = !settings.Meal },
            TelegramNotificationKind.InventoryFull => settings with { InventoryFull = !settings.InventoryFull },
            TelegramNotificationKind.InventorySpaceLow => settings with { InventorySpaceLow = !settings.InventorySpaceLow },
            TelegramNotificationKind.BaitTired => settings with { BaitTired = !settings.BaitTired },
            TelegramNotificationKind.FocusLost => settings with { FocusLost = !settings.FocusLost },
            _ => throw new ArgumentOutOfRangeException(nameof(kind)),
        };

    private static TelegramHostSettings Copy(
        TelegramHostSettings settings,
        TelegramNotificationSettings? notifications = null,
        TelegramSoundSettings? sounds = null) => new(
            settings.Enabled,
            settings.AdminIds,
            settings.InventorySpaceLowThresholdKg,
            notifications ?? settings.Notifications,
            sounds ?? settings.Sounds);
}
