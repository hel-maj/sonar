from __future__ import annotations

from types import SimpleNamespace

from sonar.config.models import TelegramSettings
from sonar.fishing.statistics import FishPrice, FishingSessionStats, SessionTotals
from sonar.telegram.notifier import NotificationManager


class Response:
    ok = True
    status_code = 200


def test_notification_menu_edits_callback_message_and_uses_two_columns(monkeypatch):
    manager = NotificationManager(settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]))
    calls = []

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager._send_notifications(1, message_id=42)

    assert calls[0][0] == "editMessageText"
    keyboard = calls[0][1]["json"]["reply_markup"]["inline_keyboard"]
    assert [len(row) for row in keyboard] == [2, 2, 1, 1]


def test_main_menu_contains_stream_entry(monkeypatch):
    manager = NotificationManager(settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]))
    calls = []

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager._send_menu(1)

    keyboard = calls[0][1]["json"]["reply_markup"]["inline_keyboard"]
    assert any(button["callback_data"] == "menu:stream" for row in keyboard for button in row)


def test_stream_menu_shows_active_link_and_area_switch(monkeypatch):
    snapshot = SimpleNamespace(
        active=True,
        status="online",
        quality="720p",
        area="chat",
        error="",
        seconds_until_auto_stop=120,
        stream_url="https://example.test/live/",
    )
    manager = NotificationManager(
        settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]),
        stream_status_callback=lambda: snapshot,
    )
    calls = []

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager._send_stream_menu(1, message_id=42)

    payload = calls[0][1]["json"]
    keyboard = payload["reply_markup"]["inline_keyboard"]
    assert "Меню стрима игры" in payload["text"]
    assert "Область: Чат" in payload["text"]
    assert any(button["callback_data"] == "stream:open" for row in keyboard for button in row)
    assert any(button["callback_data"] == "stream:switch_area" for row in keyboard for button in row)


def test_stats_menu_message_uses_income_range():
    messages: list[str] = []
    manager = NotificationManager(
        settings=TelegramSettings(enabled=False),
        sink=messages.append,
        stats_callback=lambda: SessionTotals(
            duration_seconds=3600,
            caught_count=2,
            caught_kg=4.0,
            released_count=1,
            released_kg=1.0,
            earned_min=3000.0,
            earned_max=4500.0,
        ),
        has_stats_callback=lambda: True,
    )

    manager._send_stats(1)

    assert "💰 Доход: от 3 000 $ до 4 500 $" in messages[0]
    assert "📈 Доход в час: от 3 000 $ до 4 500 $" in messages[0]


def test_stats_menu_message_includes_fish_rows():
    messages: list[str] = []
    stats = FishingSessionStats(default_prices={"ruster": FishPrice(1.0, 2.0, 1000.0, 2000.0)})
    stats.record_catch("ruster", "Рустер", 3.0, kept=True)
    stats.record_catch("ruster", "Рустер", 1.0, kept=False)
    manager = NotificationManager(
        settings=TelegramSettings(enabled=False),
        sink=messages.append,
        stats_callback=stats.totals,
        stats_rows_callback=stats.rows,
        has_stats_callback=lambda: True,
    )

    manager._send_stats(1)

    assert "🐟 Улов по видам" in messages[0]
    assert "• Рустер" in messages[0]
    assert "🎣 Поймано: 2 шт · 4 кг" in messages[0]
    assert "🌊 Отпущено: 1 шт · 1 кг" in messages[0]
    assert "💰 Доход: от 3 000 $ до 6 000 $" in messages[0]


def test_caught_fish_notification_sends_photo_with_caption(monkeypatch):
    calls = []
    manager = NotificationManager(settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]))

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager.notify_caught_fish("Рустер", 2.17, "Хороший улов", 10, None, SessionTotals(0, 1, 2.17, 0, 0, 100, 100), image_bytes=b"png")

    assert calls[0][0] == "sendPhoto"
    assert calls[0][1]["files"]["photo"][1] == b"png"
    assert "Рустер" in calls[0][1]["data"]["caption"]
