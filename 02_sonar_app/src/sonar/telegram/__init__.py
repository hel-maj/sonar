"""Telegram integration."""

from sonar.telegram.notifier_adjustments import apply_to_module


def install() -> None:
    import sys

    module = sys.modules.get("sonar.telegram.notifier")
    if module is not None:
        apply_to_module(module)


install()
