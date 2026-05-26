from __future__ import annotations

import threading
import time
from io import BytesIO
from types import SimpleNamespace

from PIL import Image

from sonar.config.models import TelegramSettings
from sonar.fishing.item_info import ItemEffect, ItemInfo
from sonar.fishing.player_status import PlayerStatus
from sonar.fishing.statistics import FishPrice, FishingSessionStats, SessionTotals
from sonar.fishing.tackle_detection import TackleItemCount
import sonar.telegram.notifier as notifier_module
from sonar.telegram.notifier import NotificationManager
from sonar.vision.geometry import Rect


class Response:
    ok = True
    status_code = 200


class MessageResponse(Response):
    def __init__(self, message_id: int) -> None:
        self.message_id = message_id

    def json(self):
        return {"result": {"message_id": self.message_id}}


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
    assert [len(row) for row in keyboard] == [2, 2, 2, 1]


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

    assert "Sonar запущен" in messages[0]
    assert "Меню" in messages[1]
    assert "Sonar выключен" in messages[-1]


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
    assert "Стрим игры" in payload["text"]
    assert "Область: Чат" in payload["text"]
    assert "Режим: 30fps" in payload["text"]
    assert "Статус: 🟢 online" in payload["text"]
    assert any(button.get("url") == "https://example.test/live/" for row in keyboard for button in row)
    assert any(button.get("callback_data") == "stream:switch_area" for row in keyboard for button in row)


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
    assert not any(button.get("url") for row in keyboard for button in row)


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
    assert "Статус: 🟡 starting" in payload["text"]
    assert any(button["text"] == "⏹ Остановить запуск" for row in keyboard for button in row)


def test_stream_menu_switches_snapshot_mode_from_telegram(monkeypatch):
    snapshot = SimpleNamespace(
        active=True,
        status="online",
        quality="720p",
        area="full",
        error="",
        seconds_until_auto_stop=120,
        snapshot_mode_enabled=False,
        stream_url="https://example.test/live/",
    )
    switched: list[bool] = []
    manager = NotificationManager(
        settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]),
        stream_status_callback=lambda: snapshot,
        stream_set_snapshot_mode_callback=lambda enabled: switched.append(enabled) or True,
    )
    calls = []

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager._switch_stream_mode(1, message_id=42)

    assert switched == [True]
    keyboard = calls[-1][1]["json"]["reply_markup"]["inline_keyboard"]
    assert any(button["callback_data"] == "stream:switch_mode" for row in keyboard for button in row)


def test_stream_start_refreshes_menu_until_online(monkeypatch):
    monkeypatch.setattr(notifier_module, "STREAM_MENU_REFRESH_INTERVAL_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_MENU_REFRESH_MAX_SECONDS", 0.5)
    monkeypatch.setattr(notifier_module, "STREAM_MENU_PUBLIC_URL_GRACE_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_LINK_DELIVERY_INTERVAL_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_LINK_DELIVERY_MAX_SECONDS", 0.5)
    monkeypatch.setattr(NotificationManager, "_url_is_reachable", staticmethod(lambda url: True))
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
        if any("Статус: 🟢 online" in call[1]["json"]["text"] for call in calls if call[0] == "editMessageText"):
            break
        time.sleep(0.01)

    assert any("Статус: 🟡 starting" in call[1]["json"]["text"] for call in calls if call[0] == "editMessageText")
    assert any("Статус: 🟢 online" in call[1]["json"]["text"] for call in calls if call[0] == "editMessageText")


def test_stream_stop_deletes_sent_stream_links(monkeypatch):
    manager = NotificationManager(settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]))
    calls = []

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        if method == "sendMessage":
            return MessageResponse(77)
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager.send_message("🖥 Трансляция:\nhttps://example.test/live/", chat_id=1)
    manager._delete_stream_link_messages(1)

    assert any(call[0] == "deleteMessage" and call[1]["json"]["message_id"] == 77 for call in calls)


def test_send_stream_link_shows_menu_without_sending_local_link(monkeypatch):
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

    manager._send_stream_link(1)

    assert calls[0][0] == "sendMessage"
    text = calls[0][1]["json"]["text"]
    assert "Формируется" in text
    assert "127.0.0.1" not in text


def test_stream_menu_marks_unreachable_cloudflare_link_as_forming(monkeypatch):
    snapshot = SimpleNamespace(
        active=True,
        status="online",
        quality="720p",
        area="full",
        error="",
        seconds_until_auto_stop=120,
        public_url="https://example.trycloudflare.com",
        stream_url="https://example.trycloudflare.com/live/",
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
    monkeypatch.setattr(NotificationManager, "_url_is_reachable", staticmethod(lambda url: False))

    manager._send_stream_menu(1, message_id=42)

    payload = calls[0][1]["json"]
    assert "Ссылка: Формируется..." in payload["text"]
    keyboard = payload["reply_markup"]["inline_keyboard"]
    assert not any(button.get("url") for row in keyboard for button in row)


def test_stream_start_refreshes_menu_with_public_link(monkeypatch):
    monkeypatch.setattr(notifier_module, "STREAM_MENU_REFRESH_INTERVAL_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_MENU_REFRESH_MAX_SECONDS", 0.5)
    monkeypatch.setattr(notifier_module, "STREAM_MENU_PUBLIC_URL_GRACE_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_LINK_DELIVERY_INTERVAL_SECONDS", 0.01)
    monkeypatch.setattr(notifier_module, "STREAM_LINK_DELIVERY_MAX_SECONDS", 0.5)
    monkeypatch.setattr(NotificationManager, "_url_is_reachable", staticmethod(lambda url: True))
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
        if any("https://example.trycloudflare.com/live/" in call[1]["json"]["text"] for call in calls if call[0] == "editMessageText"):
            break
        time.sleep(0.01)

    edited_messages = [call[1]["json"]["text"] for call in calls if call[0] == "editMessageText"]
    sent_messages = [call[1]["json"]["text"] for call in calls if call[0] == "sendMessage"]
    assert any("https://example.trycloudflare.com/live/" in text for text in edited_messages)
    assert not any("https://example.trycloudflare.com/live/" in text for text in sent_messages)
    assert not any("127.0.0.1" in text for text in edited_messages)


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
    assert "Рустер" in messages[0]
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

    photo_call = next(call for call in calls if call[0] == "sendPhoto")
    assert photo_call[1]["files"]["photo"][1] == b"png"
    assert "Рустер" in photo_call[1]["data"]["caption"]


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


def test_bait_tired_notification_respects_toggle():
    messages: list[str] = []
    manager = NotificationManager(
        settings=TelegramSettings(enabled=False, notify_bait_tired=False),
        sink=messages.append,
    )

    manager.notify_bait_tired()
    assert messages == []

    manager.settings.notify_bait_tired = True
    manager.notify_bait_tired()
    assert "Рыба устала от приманки" in messages[0]
    assert "Исправляем" in messages[0]


def test_meal_notification_sends_text_without_item_photo(monkeypatch):
    calls = []
    manager = NotificationManager(settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1], notify_meal=True))

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager.notify_meal_eaten("ИРП Армии США", image_bytes=b"png")

    assert calls[0][0] == "sendMessage"
    assert "ИРП Армии США" in calls[0][1]["json"]["text"]
    assert "🍽" in calls[0][1]["json"]["text"]
    assert "Проверяю голод и жажду дальше" not in calls[0][1]["json"]["text"]


def test_caught_fish_notification_decorates_valid_photo_with_blurred_background(monkeypatch):
    calls = []
    manager = NotificationManager(settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1]))

    source = BytesIO()
    Image.new("RGBA", (40, 20), (120, 40, 20, 255)).save(source, format="PNG")
    source_bytes = source.getvalue()

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager.notify_caught_fish("Рустер", 2.17, "Хороший улов", 10, None, SessionTotals(0, 1, 2.17, 0, 0, 100, 150), image_bytes=source_bytes)

    photo_call = next(call for call in calls if call[0] == "sendPhoto")
    sent_bytes = photo_call[1]["files"]["photo"][1]
    decorated = Image.open(BytesIO(sent_bytes))
    assert sent_bytes != source_bytes
    assert decorated.width > 40
    assert decorated.height > 20
    assert "Доход:</b> от 100 $" in photo_call[1]["data"]["caption"]
    assert "до 150 $" not in photo_call[1]["data"]["caption"]


def test_meal_notification_includes_item_effect_details(monkeypatch):
    calls = []
    manager = NotificationManager(settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1], notify_meal=True))
    item_info = ItemInfo(
        rect=Rect(0, 0, 1, 1),
        title="Энергетик",
        item_name="Энергетик",
        weight="0.45",
        thirst_change="+50",
        condition_percent="75",
        effects=(
            ItemEffect(
                name="Ускорение",
                duration="15 м.",
                description="Ускорение скорости передвижения.",
                parameter_modifications=("+10% к скорости бега", "+100 к выносливости"),
            ),
        ),
    )

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager.notify_meal_eaten("Энергетик", item_info=item_info)

    text = calls[0][1]["json"]["text"]
    assert calls[0][0] == "sendMessage"
    assert "<b>Питание использовано!</b>" in text
    assert "Жажда:</b> +50" in text
    assert "Состояние:</b> 75%" in text
    assert "Ускорение" in text
    assert "15 м." in text
    assert "+10% к скорости бега" in text
    assert "+100 к выносливости" in text


def test_meal_notification_includes_player_status(monkeypatch):
    calls = []
    manager = NotificationManager(settings=TelegramSettings(enabled=True, bot_token="token", admin_ids=[1], notify_meal=True))

    def fake_post(self, method, **kwargs):
        calls.append((method, kwargs))
        return Response()

    monkeypatch.setattr(NotificationManager, "_api_post", fake_post)

    manager.notify_meal_eaten(
        "ИРП Армии США",
        player_status=PlayerStatus(
            food=96,
            water=71,
            health=47,
            inventory_weight=5.74,
            inventory_weight_max=40,
            backpack_weight=11.74,
            backpack_weight_max=20,
            source="screenshot",
        ),
    )

    text = calls[0][1]["json"]["text"]
    assert "Еда:</b> 96%" in text
    assert "Вода:</b> 71%" in text
    assert "Здоровье:</b> 47%" in text
    assert "Инвентарь:</b> 5.74 / 40 кг" in text
    assert "Рюкзак:</b> 11.74 / 20 кг" in text
