from __future__ import annotations

import threading
import time
from types import SimpleNamespace

from sonar.config.models import TelegramSettings
from sonar.fishing.statistics import FishPrice, FishingSessionStats, SessionTotals
from sonar.fishing.tackle_detection import TackleItemCount
import sonar.telegram.notifier as notifier_module
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
    assert any(button["callback_data"] == "action:tackle" for row in keyboard for button in row)


def test_app_lifecycle_notification_sends_started_before_menu():
    messages: list[str] = []
    manager = NotificationManager(settings=TelegramSettings(enabled=False, admin_ids=[1]), sink=messages.append)

    manager.notify_app_started()
    manager.notify_app_stopped()

    assert messages[0] == "Sonar запущен"
    assert "Меню" in messages[1]
    assert messages[-1] == "Sonar выключен"


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


def test_stream_menu_hides_open_button_until_public_link(monkeypatch):
    snapshot = SimpleNamespace(
        active=True,
        status="online",
        quality="720p",
        area="full",
        error="",
        seconds_until_auto_stop=120,
        public_url="http://127.0.0.1:1000",
        stream_url="http://127.0.0.1:1000/live/",
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

    keyboard = calls[0][1]["json"]["reply_markup"]["inline_keyboard"]
    assert not any(button["callback_data"] == "stream:open" for row in keyboard for button in row)


def test_stream_menu_allows_cancelling_starting_stream(monkeypatch):
    snapshot = SimpleNamespace(
        active=False,
        status="starting",
        quality="720p",
        area="full",
        error="",
        seconds_until_auto_stop=None,
        stream_url=None,
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
    assert "Статус starting" in payload["text"]
    assert any(button["text"] == "⏹ Остановить запуск" for row in keyboard for button in row)


def test_stream_start_refreshes_menu_until_online(monkeypatch):
    monkeypatch.setattr(notifier_module, "STREAM_MENU_REFRESH_INTERVAL_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_MENU_REFRESH_MAX_SECONDS", 0.5)
    monkeypatch.setattr(notifier_module, "STREAM_MENU_PUBLIC_URL_GRACE_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_LINK_DELIVERY_INTERVAL_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_LINK_DELIVERY_MAX_SECONDS", 0.5)
    state = {
        "snapshot": SimpleNamespace(
            active=False,
            status="offline",
            quality="720p",
            area="full",
            error="",
            seconds_until_auto_stop=None,
            stream_url=None,
        )
    }
    calls = []

    def start_stream():
        state["snapshot"] = SimpleNamespace(
            active=False,
            status="starting",
            quality="720p",
            area="full",
            error="",
            seconds_until_auto_stop=None,
            stream_url=None,
        )

        def mark_online():
            state["snapshot"] = SimpleNamespace(
                active=True,
                status="online",
                quality="720p",
                area="full",
                error="",
                seconds_until_auto_stop=180,
                stream_url="https://example.trycloudflare.com/live/",
            )

        threading.Timer(0.03, mark_online).start()
        return True

    manager = NotificationManager(
        settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]),
        stream_status_callback=lambda: state["snapshot"],
        stream_start_callback=start_stream,
    )

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager._toggle_stream(1, message_id=42)

    deadline = time.monotonic() + 1.0
    while time.monotonic() < deadline:
        if any("Статус online" in call[1]["json"]["text"] for call in calls if call[0] == "editMessageText"):
            break
        time.sleep(0.01)

    assert any("Статус starting" in call[1]["json"]["text"] for call in calls if call[0] == "editMessageText")
    assert any("Статус online" in call[1]["json"]["text"] for call in calls if call[0] == "editMessageText")


def test_send_stream_link_waits_for_public_url_instead_of_sending_local(monkeypatch):
    snapshot = SimpleNamespace(
        active=True,
        status="online",
        quality="720p",
        area="full",
        error="",
        seconds_until_auto_stop=120,
        public_url="http://127.0.0.1:1000",
        stream_url="http://127.0.0.1:1000/live/",
    )
    manager = NotificationManager(
        settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]),
        stream_status_callback=lambda: snapshot,
    )
    calls = []
    scheduled = []

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    def fake_schedule(self, chat_id):
        scheduled.append(chat_id)

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)
    monkeypatch.setattr(NotificationManager, "_schedule_stream_link_delivery", fake_schedule)

    manager._send_stream_link(1)

    assert scheduled == [1]
    assert calls[0][0] == "sendMessage"
    text = calls[0][1]["json"]["text"]
    assert "готовится" in text
    assert "127.0.0.1" not in text


def test_stream_start_sends_public_link_automatically(monkeypatch):
    monkeypatch.setattr(notifier_module, "STREAM_MENU_REFRESH_INTERVAL_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_MENU_REFRESH_MAX_SECONDS", 0.5)
    monkeypatch.setattr(notifier_module, "STREAM_MENU_PUBLIC_URL_GRACE_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_LINK_DELIVERY_INTERVAL_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_LINK_DELIVERY_MAX_SECONDS", 0.5)
    state = {
        "snapshot": SimpleNamespace(
            active=False,
            status="offline",
            quality="720p",
            area="full",
            error="",
            seconds_until_auto_stop=None,
            public_url=None,
            stream_url=None,
        )
    }
    calls = []

    def start_stream():
        state["snapshot"] = SimpleNamespace(
            active=True,
            status="online",
            quality="720p",
            area="full",
            error="",
            seconds_until_auto_stop=180,
            public_url="http://127.0.0.1:1000",
            stream_url="http://127.0.0.1:1000/live/",
        )

        def publish_url():
            state["snapshot"] = SimpleNamespace(
                active=True,
                status="online",
                quality="720p",
                area="full",
                error="",
                seconds_until_auto_stop=180,
                public_url="https://example.trycloudflare.com",
                stream_url="https://example.trycloudflare.com/live/",
            )

        threading.Timer(0.03, publish_url).start()
        return True

    manager = NotificationManager(
        settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]),
        stream_status_callback=lambda: state["snapshot"],
        stream_start_callback=start_stream,
    )

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager._toggle_stream(1, message_id=42)

    deadline = time.monotonic() + 1.0
    while time.monotonic() < deadline:
        if any("https://example.trycloudflare.com/live/" in call[1]["json"]["text"] for call in calls if call[0] == "sendMessage"):
            break
        time.sleep(0.01)

    sent_messages = [call[1]["json"]["text"] for call in calls if call[0] == "sendMessage"]
    assert any("https://example.trycloudflare.com/live/" in text for text in sent_messages)
    assert not any("127.0.0.1" in text for text in sent_messages)


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


def test_tackle_menu_sends_last_scan_photo_with_counts(monkeypatch):
    calls = []
    manager = NotificationManager(
        settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]),
        tackle_callback=lambda: (
            TackleItemCount("rod", "Удочка", 1),
            TackleItemCount("hook", "Крючки/поводки", 3),
        ),
        tackle_image_callback=lambda: b"png",
    )

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager._send_tackle(1)

    assert calls[0][0] == "sendPhoto"
    assert calls[0][1]["files"]["photo"][1] == b"png"
    assert "Снаряжение" in calls[0][1]["data"]["caption"]
    assert "Крючки/поводки: 3шт." in calls[0][1]["data"]["caption"]
