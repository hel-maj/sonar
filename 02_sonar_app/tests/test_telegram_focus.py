from __future__ import annotations

from sonar.config.models import TelegramSettings
from sonar.telegram.notifier import NotificationManager


def test_focus_button_calls_callback_and_replies():
    messages: list[str] = []
    calls: list[bool] = []
    manager = NotificationManager(
        settings=TelegramSettings(enabled=False),
        sink=messages.append,
        focus_game_callback=lambda: calls.append(True) or True,
    )

    manager._focus_game(1)

    assert calls == [True]
    assert "Фокус" in messages[0]


def test_focus_lost_notification_respects_toggle():
    messages: list[str] = []
    manager = NotificationManager(
        settings=TelegramSettings(enabled=False, notify_focus_lost=False),
        sink=messages.append,
    )

    manager.notify_focus_lost()
    assert messages == []

    manager.settings.notify_focus_lost = True
    manager.notify_focus_lost()
    assert "Фокус ушёл с игры" in messages[0]


def test_focus_lost_notification_defaults_off():
    settings = TelegramSettings.from_dict({})

    assert settings.notify_focus_lost is False
    assert settings.to_dict()["notify_focus_lost"] is False
