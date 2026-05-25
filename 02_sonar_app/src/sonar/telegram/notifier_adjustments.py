from __future__ import annotations


def apply_to_module(notifier_module) -> None:
    if getattr(notifier_module, "_SONAR_NOTIFIER_ADJUSTMENTS_APPLIED", False):
        return
    notifier_module._SONAR_NOTIFIER_ADJUSTMENTS_APPLIED = True
