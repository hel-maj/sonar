using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.TelegramPage;

namespace Sonar.Fishing.Host.Tests;

internal static class TelegramNotificationPlannerTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("telegram_catch_notification_preserves_html_sound_and_photo_policy", CatchPlanIsExact),
        new("telegram_session_notification_preserves_menu_and_statistics_semantics", SessionPlanIsExact),
        new("telegram_player_status_formats_partial_values_fail_closed", PlayerStatusIsFailClosed),
        new("telegram_meal_notification_preserves_item_effect_and_status_union", MealPlanIsExact),
    ];

    private static void CatchPlanIsExact()
    {
        var settings = CreateSettings().WithSounds(sounds => sounds with { Catch = false });
        var plan = TelegramNotificationPlanner.PlanCatch(
            settings,
            new TelegramCatchNotification(
                "Марлин <редкий>",
                12.5,
                "ТРОФЕЙНАЯ",
                7,
                10,
                Released: false,
                Totals: Totals(),
                PreferPhoto: true));

        TestAssert.True(plan is not null, "Enabled catch notification was dropped");
        TestAssert.True(plan!.Silent, "Disabled catch sound did not produce silent delivery");
        TestAssert.True(plan.PreferPhoto, "Catch photo preference was lost");
        TestAssert.True(
            plan.Html.Contains("Марлин &lt;редкий&gt;", StringComparison.Ordinal) &&
            plan.Html.Contains("🏆 <b>ТРОФЕЙНАЯ!</b>", StringComparison.Ordinal) &&
            plan.Html.Contains("Оставлено:", StringComparison.Ordinal),
            "Catch payload or HTML escaping changed");
    }

    private static void SessionPlanIsExact()
    {
        var settings = CreateSettings();
        var session = new FishingSessionStateSnapshot(
            1,
            false,
            false,
            string.Empty,
            Totals(),
            []);
        var plan = TelegramNotificationPlanner.PlanFishingStopped(
            settings,
            session,
            "ошибка <окна>",
            preferPhoto: false);

        TestAssert.True(plan is not null, "Enabled stop notification was dropped");
        TestAssert.True(plan!.IncludeMenuButton, "Stop notification lost menu action");
        TestAssert.True(!plan.Silent, "Enabled stop sound became silent");
        TestAssert.True(
            plan.Html.Contains("ошибка &lt;окна&gt;", StringComparison.Ordinal) &&
            plan.Html.Contains("Доход в час:", StringComparison.Ordinal),
            "Stop statistics payload changed");
    }

    private static void PlayerStatusIsFailClosed()
    {
        var message = TelegramNotificationPlanner.FormatPlayerStatus(
            new TelegramPlayerStatusSnapshot(
                Food: 80,
                Water: null,
                Health: 99,
                InventoryWeight: null,
                InventoryWeightMax: 120,
                BackpackWeight: null,
                BackpackWeightMax: null));
        TestAssert.True(
            message.Contains("Еда: <b>80%</b>", StringComparison.Ordinal) &&
            message.Contains("Инвентарь: <b>- / 120</b> кг", StringComparison.Ordinal) &&
            !message.Contains("Вода:", StringComparison.Ordinal),
            "Partial player status formatting changed");
        TestAssert.Throws<ArgumentOutOfRangeException>(
            () => TelegramNotificationPlanner.PlanInventorySpaceLow(
                CreateSettings(notifyInventorySpaceLow: true),
                -1,
                2,
                null),
            "Negative inventory weight was accepted");
    }

    private static void MealPlanIsExact()
    {
        var modifications = new List<string> { "+10 <HP>" };
        var info = new TelegramMealItemInfoSnapshot(
            "Сэндвич & чай",
            null,
            "0.5",
            "+20",
            "+10",
            "90",
            null,
            null,
            [new TelegramMealEffectSnapshot("Бодрость", "5 мин", "Быстрее", modifications)],
            []);
        modifications[0] = "mutated";
        var plan = TelegramMealNotificationPlanner.Plan(
            CreateSettings(),
            string.Empty,
            info,
            new TelegramPlayerStatusSnapshot(90, 80, 100, 12.5, 100, null, null));

        TestAssert.True(plan is not null, "Enabled meal notification was dropped");
        TestAssert.True(
            plan!.Html.Contains("Сэндвич &amp; чай", StringComparison.Ordinal) &&
            plan.Html.Contains("+10 &lt;HP&gt;", StringComparison.Ordinal) &&
            plan.Html.Contains("Инвентарь:</b> 12.5 / 100 кг", StringComparison.Ordinal),
            "Meal item/effect/status payload changed or input was not frozen");
    }

    private static TelegramHostSettings CreateSettings(bool notifyInventorySpaceLow = true) => new(
        false,
        [42],
        1.0,
        TelegramHostSettings.Default.Notifications with
        {
            InventorySpaceLow = notifyInventorySpaceLow,
            FocusLost = true,
        },
        TelegramSoundSettings.AllEnabled);

    private static TelegramHostSettings WithSounds(
        this TelegramHostSettings settings,
        Func<TelegramSoundSettings, TelegramSoundSettings> update) => new(
            settings.Enabled,
            settings.AdminIds,
            settings.InventorySpaceLowThresholdKg,
            settings.Notifications,
            update(settings.Sounds));

    private static FishingSessionTotalsSnapshot Totals() => new(
        DurationSeconds: 3600,
        CaughtCount: 4,
        CaughtKg: 20,
        ReleasedCount: 1,
        ReleasedKg: 2,
        EarnedMin: 1000,
        EarnedMax: 1200);
}
