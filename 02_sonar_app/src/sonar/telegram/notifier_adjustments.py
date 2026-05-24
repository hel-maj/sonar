from __future__ import annotations


def apply_to_module(notifier_module) -> None:
    if getattr(notifier_module, "_SONAR_NOTIFIER_ADJUSTMENTS_APPLIED", False):
        return
    notifier_module._SONAR_NOTIFIER_ADJUSTMENTS_APPLIED = True

    def format_catch_message(fish_name, weight_kg, quality_text, xp_current, xp_total, totals):
        trophy = quality_text and "троф" in quality_text.lower()
        lines = []
        if trophy:
            lines.append("🏆 Трофейная!")
            lines.append("")
        lines.append(f"🐟 {fish_name} — {notifier_module.format_weight(weight_kg or 0.0)}")
        lines.append("")
        lines.append(f"📦 Всего: {notifier_module.format_weight(totals.caught_kg)} · {totals.caught_count} выловов")
        lines.append(f"💰 Доход: {notifier_module.format_money_range(totals.earned_min, totals.earned_max)}")
        if xp_current is not None and xp_total is not None:
            lines.append(f"⭐ Опыт: {xp_current} / {xp_total}")
        elif xp_current is not None:
            lines.append(f"⭐ Опыт: {xp_current}")
        return "\n".join(lines)

    notifier_module.NotificationManager._format_catch_message = staticmethod(format_catch_message)
