from __future__ import annotations

import html
import hashlib
import ipaddress
import json
import random
import re
import threading
import time
import urllib.error
import urllib.request
from io import BytesIO
from dataclasses import dataclass, field
from datetime import datetime
from typing import Any, Callable
from urllib.parse import urlparse, urlunparse

import requests
from PIL import Image, ImageChops, ImageDraw, ImageEnhance, ImageFilter, ImageOps

from sonar.config.models import TelegramSettings
from sonar.fishing.item_info import ItemInfo
from sonar.fishing.player_status import PlayerStatus
from sonar.fishing.statistics import FishStatsRow, SessionTotals, format_catch_summary, format_duration, format_money, format_money_range, format_weight
from sonar.fishing.tackle_detection import TackleItemCount, format_tackle_items
from sonar.security.runtime import decrypt_text_literal


def _h(value: object) -> str:
    return html.escape(str(value), quote=False)


def _non_empty(value: str | None) -> str:
    return (value or "").strip()


STREAM_MENU_REFRESH_INTERVAL_SECONDS = 15.0
STREAM_MENU_REFRESH_MAX_SECONDS = 4 * 60 * 60.0
STREAM_MENU_PUBLIC_URL_GRACE_SECONDS = 8.0
STREAM_LINK_DELIVERY_INTERVAL_SECONDS = 1.0
STREAM_LINK_DELIVERY_MAX_SECONDS = 60.0
CATCH_BACKGROUND_COLORS = ((11, 11, 11), (36, 36, 36), (232, 28, 90))
CATCH_BACKGROUND_RELEASE_ACCENT = (135, 103, 114)
CATCH_FOREGROUND_TARGET_SIZE = (410, 478)
CATCH_CANVAS_PADDING_PX = 180
CATCH_FOREGROUND_EDGE_FILL = (11, 11, 11, 255)
CATCH_FOREGROUND_EDGE_PADDING_PX = 8
CATCH_FRAME_INSET_PX = 8
CATCH_FRAME_SHADOW_PRIMARY_ALPHA = 124
CATCH_FRAME_SHADOW_SECONDARY_ALPHA = 68
TELEGRAM_NOTIFICATION_ITEMS = (
    ("notify_catch", "sound_catch", "Поймана рыба"),
    ("notify_start_stop", "sound_start_stop", "Запуск/Остановка"),
    ("notify_meal", "sound_meal", "Питание"),
    ("notify_inventory_full", "sound_inventory_full", "Закончилось место"),
    ("notify_inventory_space_low", "sound_inventory_space_low", "Мало места"),
    ("notify_bait_tired", "sound_bait_tired", "Устала от приманки"),
    ("notify_focus_lost", "sound_focus_lost", "Потеря фокуса игры"),
)


@dataclass(frozen=True, slots=True)
class TelegramAccessCheck:
    ok: bool
    error: str = ""


def check_telegram_bot_access(bot_token: str, *, timeout: float = 5.0) -> TelegramAccessCheck:
    token = bot_token.strip()
    if not token:
        return TelegramAccessCheck(False, "Токен не указан")
    url = f"{decrypt_text_literal('telegram_api_base')}/bot{token}/getMe"
    try:
        response = requests.get(url, timeout=timeout)
    except requests.RequestException:
        return TelegramAccessCheck(False, "Telegram недоступен")
    try:
        payload = response.json()
    except (AttributeError, ValueError):
        payload = {}
    if response.ok and payload.get("ok") is True:
        return TelegramAccessCheck(True)
    error_code = payload.get("error_code") or response.status_code
    description = str(payload.get("description") or "").strip()
    if error_code in {401, 404} or response.status_code in {401, 404}:
        return TelegramAccessCheck(False, "Неверный токен")
    if response.status_code == 429:
        return TelegramAccessCheck(False, "Telegram ограничил запросы")
    return TelegramAccessCheck(False, description or f"HTTP {response.status_code}")


@dataclass(slots=True)
class NotificationManager:
    settings: TelegramSettings = field(default_factory=TelegramSettings)
    timeout: float = 5.0
    sink: Callable[[str], None] | None = None
    start_callback: Callable[[], bool] | None = None
    stop_callback: Callable[[], None] | None = None
    is_running_callback: Callable[[], bool] | None = None
    stats_callback: Callable[[], SessionTotals] | None = None
    stats_rows_callback: Callable[[], list[FishStatsRow]] | None = None
    has_stats_callback: Callable[[], bool] | None = None
    tackle_callback: Callable[[], tuple[TackleItemCount, ...]] | None = None
    tackle_image_callback: Callable[[], bytes | None] | None = None
    tackle_scanned_at_callback: Callable[[], datetime | None] | None = None
    player_status_callback: Callable[[], PlayerStatus | None] | None = None
    screenshot_callback: Callable[[], bytes] | None = None
    focus_game_callback: Callable[[], bool] | None = None
    shutdown_game_callback: Callable[[], None] | None = None
    shutdown_pc_callback: Callable[[], None] | None = None
    settings_changed_callback: Callable[[TelegramSettings], None] | None = None
    stream_status_callback: Callable[[], Any] | None = None
    stream_start_callback: Callable[[], bool] | None = None
    stream_stop_callback: Callable[[], None] | None = None
    stream_set_quality_callback: Callable[[str], bool] | None = None
    stream_set_chat_zoom_callback: Callable[[bool], bool] | None = None
    stream_set_snapshot_mode_callback: Callable[[bool], bool] | None = None
    fishing_runtime_enabled_callback: Callable[[], bool] | None = None
    stats_runtime_enabled_callback: Callable[[], bool] | None = None
    tackle_runtime_enabled_callback: Callable[[], bool] | None = None
    stream_runtime_enabled_callback: Callable[[], bool] | None = None
    player_status_scan_callback: Callable[[], tuple[bool, str]] | None = None
    runtime_enabled: bool = True
    _stop_event: threading.Event = field(default_factory=threading.Event, init=False)
    _poll_thread: threading.Thread | None = field(default=None, init=False)
    _last_update_id: int | None = field(default=None, init=False)
    _stream_menu_refresh_lock: threading.Lock = field(default_factory=threading.Lock, init=False)
    _stream_menu_refresh_generation: int = field(default=0, init=False)
    _stream_link_delivery_lock: threading.Lock = field(default_factory=threading.Lock, init=False)
    _stream_link_delivery_generation: int = field(default=0, init=False)
    _stream_link_messages: dict[int, set[int]] = field(default_factory=dict, init=False)
    _stream_verified_url: str = field(default="", init=False)
    _commands_registered_signature: tuple[str, tuple[int, ...]] | None = field(default=None, init=False)
    _player_status_scan_waiting_chat_ids: set[int] = field(default_factory=set, init=False)
    _player_status_scan_lock: threading.Lock = field(default_factory=threading.Lock, init=False)

    def __post_init__(self) -> None:
        self._stop_event = threading.Event()
        self._poll_thread = None
        self._last_update_id = None
        self._stream_menu_refresh_lock = threading.Lock()
        self._stream_menu_refresh_generation = 0
        self._stream_link_delivery_lock = threading.Lock()
        self._stream_link_delivery_generation = 0
        self._stream_link_messages = {}
        self._stream_verified_url = ""
        self._commands_registered_signature = None
        self._player_status_scan_waiting_chat_ids = set()
        self._player_status_scan_lock = threading.Lock()

    def configure(
        self,
        settings: TelegramSettings,
        *,
        runtime_enabled: bool | None = None,
        start_callback: Callable[[], bool] | None = None,
        stop_callback: Callable[[], None] | None = None,
        is_running_callback: Callable[[], bool] | None = None,
        stats_callback: Callable[[], SessionTotals] | None = None,
        stats_rows_callback: Callable[[], list[FishStatsRow]] | None = None,
        has_stats_callback: Callable[[], bool] | None = None,
        tackle_callback: Callable[[], tuple[TackleItemCount, ...]] | None = None,
        tackle_image_callback: Callable[[], bytes | None] | None = None,
        tackle_scanned_at_callback: Callable[[], datetime | None] | None = None,
        player_status_callback: Callable[[], PlayerStatus | None] | None = None,
        screenshot_callback: Callable[[], bytes] | None = None,
        focus_game_callback: Callable[[], bool] | None = None,
        shutdown_game_callback: Callable[[], None] | None = None,
        shutdown_pc_callback: Callable[[], None] | None = None,
        settings_changed_callback: Callable[[TelegramSettings], None] | None = None,
        stream_status_callback: Callable[[], Any] | None = None,
        stream_start_callback: Callable[[], bool] | None = None,
        stream_stop_callback: Callable[[], None] | None = None,
        stream_set_quality_callback: Callable[[str], bool] | None = None,
        stream_set_chat_zoom_callback: Callable[[bool], bool] | None = None,
        stream_set_snapshot_mode_callback: Callable[[bool], bool] | None = None,
        fishing_runtime_enabled_callback: Callable[[], bool] | None = None,
        stats_runtime_enabled_callback: Callable[[], bool] | None = None,
        tackle_runtime_enabled_callback: Callable[[], bool] | None = None,
        stream_runtime_enabled_callback: Callable[[], bool] | None = None,
        player_status_scan_callback: Callable[[], tuple[bool, str]] | None = None,
    ) -> None:
        self.settings = settings
        if runtime_enabled is not None:
            self.runtime_enabled = bool(runtime_enabled)
        self.start_callback = start_callback
        self.stop_callback = stop_callback
        self.is_running_callback = is_running_callback
        self.stats_callback = stats_callback
        self.stats_rows_callback = stats_rows_callback
        self.has_stats_callback = has_stats_callback
        self.tackle_callback = tackle_callback
        self.tackle_image_callback = tackle_image_callback
        self.tackle_scanned_at_callback = tackle_scanned_at_callback
        self.player_status_callback = player_status_callback
        self.screenshot_callback = screenshot_callback
        self.focus_game_callback = focus_game_callback
        self.shutdown_game_callback = shutdown_game_callback
        self.shutdown_pc_callback = shutdown_pc_callback
        self.settings_changed_callback = settings_changed_callback
        self.stream_status_callback = stream_status_callback
        self.stream_start_callback = stream_start_callback
        self.stream_stop_callback = stream_stop_callback
        self.stream_set_quality_callback = stream_set_quality_callback
        self.stream_set_chat_zoom_callback = stream_set_chat_zoom_callback
        self.stream_set_snapshot_mode_callback = stream_set_snapshot_mode_callback
        self.fishing_runtime_enabled_callback = fishing_runtime_enabled_callback
        self.stats_runtime_enabled_callback = stats_runtime_enabled_callback
        self.tackle_runtime_enabled_callback = tackle_runtime_enabled_callback
        self.stream_runtime_enabled_callback = stream_runtime_enabled_callback
        self.player_status_scan_callback = player_status_scan_callback
        self._sync_polling()

    def set_runtime_enabled(self, enabled: bool) -> None:
        self.runtime_enabled = bool(enabled)
        self._sync_polling()

    def _sync_polling(self) -> None:
        if self.runtime_enabled and self.settings.enabled and self.settings.bot_token:
            self.start_polling()
        else:
            self.stop_polling()

    @staticmethod
    def _callback_enabled(callback: Callable[[], bool] | None) -> bool:
        if callback is None:
            return True
        try:
            return bool(callback())
        except Exception:
            return False

    def _fishing_runtime_enabled(self) -> bool:
        return self._callback_enabled(self.fishing_runtime_enabled_callback)

    def _stats_runtime_enabled(self) -> bool:
        return self._callback_enabled(self.stats_runtime_enabled_callback)

    def _tackle_runtime_enabled(self) -> bool:
        return self._callback_enabled(self.tackle_runtime_enabled_callback)

    def _stream_runtime_enabled(self) -> bool:
        return self._callback_enabled(self.stream_runtime_enabled_callback)

    @staticmethod
    def _menu_reply_markup() -> dict[str, Any]:
        return {"inline_keyboard": [[{"text": "📋 Меню", "callback_data": "menu:main:new"}]]}

    def _send_unavailable(self, chat_id: int, feature: str, *, message_id: int | None = None) -> None:
        self._send_or_edit_message(
            f"Функция «{feature}» недоступна для этой подписки.",
            chat_id=chat_id,
            message_id=message_id,
            reply_markup={"inline_keyboard": [[{"text": "⬅️ Меню", "callback_data": "menu:main"}]]},
        )

    def start_polling(self) -> None:
        if not self.runtime_enabled or not self.settings.enabled or not self.settings.bot_token:
            return
        self._register_bot_commands()
        poll_thread = getattr(self, "_poll_thread", None)
        if poll_thread and poll_thread.is_alive():
            return
        if not hasattr(self, "_stop_event"):
            self._stop_event = threading.Event()
        self._stop_event.clear()
        self._poll_thread = threading.Thread(target=self._poll_loop, name="sonar-telegram", daemon=True)
        self._poll_thread.start()

    def _register_bot_commands(self) -> None:
        if not self.runtime_enabled or not self.settings.enabled or not self.settings.bot_token:
            return
        admin_ids = tuple(int(chat_id) for chat_id in self.settings.admin_ids)
        signature = (self.settings.bot_token.strip(), admin_ids)
        if self._commands_registered_signature == signature:
            return
        commands = [{"command": "menu", "description": "Открыть меню Sonar"}]
        default_response = self._api_post("setMyCommands", json={"commands": commands})
        ok = bool(default_response and default_response.ok)
        for chat_id in admin_ids:
            response = self._api_post(
                "setMyCommands",
                json={
                    "commands": commands,
                    "scope": {"type": "chat", "chat_id": chat_id},
                },
            )
            ok = bool(response and response.ok) and ok
        if ok:
            self._commands_registered_signature = signature

    def stop_polling(self) -> None:
        if not hasattr(self, "_stop_event"):
            self._stop_event = threading.Event()
        self._stop_event.set()
        poll_thread = getattr(self, "_poll_thread", None)
        if poll_thread and poll_thread.is_alive():
            poll_thread.join(timeout=1.0)

    def notify_caught_fish(
        self,
        fish_name: str,
        weight_kg: float | None,
        quality_text: str | None,
        xp_current: int | None,
        xp_total: int | None,
        totals: SessionTotals,
        image_bytes: bytes | None = None,
        released: bool | None = None,
    ) -> None:
        if not self.settings.notify_catch:
            return
        message = self._format_catch_message(
            fish_name,
            weight_kg,
            quality_text,
            xp_current,
            xp_total,
            totals,
            released=released,
        )
        if image_bytes is not None:
            image_bytes = self._decorate_catch_photo(image_bytes, released=bool(released))
        silent = not self._notification_sound_enabled("sound_catch")
        if image_bytes is not None and self.send_photo_to_admins(image_bytes, caption=message, disable_notification=silent):
            return
        self.send_message(message, disable_notification=silent)

    def notify_fishing_started(self, totals: SessionTotals, has_stats: bool) -> None:
        if not self.settings.notify_start_stop:
            return
        if not has_stats:
            self.send_message(
                "🚤 <b>Рыбалка началась!</b>\n\n🎣 Удочка закинута, ждём улов...",
                reply_markup=self._menu_reply_markup(),
                disable_notification=not self._notification_sound_enabled("sound_start_stop"),
            )
            return
        self.send_message(
            self._format_session_stats_message("🚤 Рыбалка началась!", "📊 Текущая сессия", totals),
            reply_markup=self._menu_reply_markup(),
            disable_notification=not self._notification_sound_enabled("sound_start_stop"),
        )

    def notify_fishing_stopped(
        self,
        totals: SessionTotals,
        *,
        reason: str | None = None,
        image_bytes: bytes | None = None,
    ) -> None:
        if not self.settings.notify_start_stop:
            return
        message = self._format_session_stats_message("🛑 Рыбалка остановлена!", "📊 Статистика сессии", totals, reason=reason)
        silent = not self._notification_sound_enabled("sound_start_stop")
        if image_bytes is not None and self.send_photo_to_admins(
            image_bytes,
            caption=message,
            reply_markup=self._menu_reply_markup(),
            disable_notification=silent,
        ):
            return
        self.send_message(message, reply_markup=self._menu_reply_markup(), disable_notification=silent)

    def notify_meal_eaten(
        self,
        item_name: str = "",
        *,
        image_bytes: bytes | None = None,
        item_info: ItemInfo | None = None,
        player_status: PlayerStatus | None = None,
    ) -> None:
        del image_bytes
        if not self.settings.notify_meal:
            return
        self.send_message(
            self._format_meal_message(item_name, item_info, player_status),
            disable_notification=not self._notification_sound_enabled("sound_meal"),
        )

    def notify_meal_ended(self) -> None:
        if self.settings.notify_meal:
            self.send_message(
                "🍽 <b>Эффект еды закончился</b>",
                disable_notification=not self._notification_sound_enabled("sound_meal"),
            )

    def notify_backpack_stored(self, count: int) -> None:
        del count
        return

    def notify_inventory_full(self) -> None:
        if self.settings.notify_inventory_full:
            self.send_message(
                "📦 <b>Закончилось место!</b>",
                disable_notification=not self._notification_sound_enabled("sound_inventory_full"),
            )

    def notify_inventory_space_low(
        self,
        free_kg: float,
        threshold_kg: float,
        player_status: PlayerStatus | None = None,
    ) -> None:
        if not self.settings.notify_inventory_space_low:
            return
        lines = [
            "⚖️ <b>Мало места в инвентаре</b>",
            "",
            f"Свободно: <b>{self._format_status_weight_number(free_kg)}</b> кг",
            f"Порог: <b>{self._format_status_weight_number(threshold_kg)}</b> кг",
        ]
        if player_status is not None:
            inventory_weight = self._format_status_weight(player_status.inventory_weight, player_status.inventory_weight_max)
            backpack_weight = self._format_status_weight(player_status.backpack_weight, player_status.backpack_weight_max)
            if inventory_weight:
                lines.append(f"🎒 Инвентарь: {inventory_weight} кг")
            if backpack_weight:
                lines.append(f"🧳 Рюкзак: {backpack_weight} кг")
        self.send_message(
            "\n".join(lines),
            disable_notification=not self._notification_sound_enabled("sound_inventory_space_low"),
        )

    def notify_bait_tired(self) -> None:
        if self.settings.notify_bait_tired:
            self.send_message(
                "<b>Рыба устала от приманки</b>\nИсправляем",
                disable_notification=not self._notification_sound_enabled("sound_bait_tired"),
            )

    def notify_focus_lost(self) -> None:
        if self.settings.notify_focus_lost:
            self.send_message(
                "⚠️🎮 <b>Фокус ушёл с игры</b>\n\n"
                "Ввод поставлен на паузу, чтобы клавиши не нажимались в другом окне. "
                "Откройте меню Telegram и нажмите «Вернуть фокус игре».",
                disable_notification=not self._notification_sound_enabled("sound_focus_lost"),
            )

    def notify_fishing_failed(self) -> None:
        if self.settings.notify_start_stop:
            self.send_message(
                "⚠️ <b>Не удалось восстановить рыбалку</b>",
                disable_notification=not self._notification_sound_enabled("sound_start_stop"),
            )

    def notify_fishing_restored(self) -> None:
        return

    def notify_app_started(self) -> None:
        self.send_message("<b>Sonar запущен</b>")
        for chat_id in list(self.settings.admin_ids):
            self._send_menu(chat_id)

    def notify_app_stopped(self) -> None:
        self._delete_stream_link_messages()
        self.send_message("<b>Sonar выключен</b>")

    def send_message(
        self,
        text: str,
        *,
        chat_id: int | None = None,
        reply_markup: dict[str, Any] | None = None,
        disable_notification: bool = False,
    ) -> bool:
        if self.sink:
            self.sink(text)
        if not self.runtime_enabled or not self.settings.enabled or not self.settings.bot_token:
            return False
        chat_ids = [chat_id] if chat_id is not None else list(self.settings.admin_ids)
        if not chat_ids:
            return False
        payload_base: dict[str, Any] = {"text": text, "parse_mode": "HTML", "disable_web_page_preview": True}
        if disable_notification:
            payload_base["disable_notification"] = True
        if reply_markup is not None:
            payload_base["reply_markup"] = reply_markup
        ok = True
        for target_id in chat_ids:
            response = self._api_post("sendMessage", json={"chat_id": target_id, **payload_base})
            ok = ok and bool(response and response.ok)
            if response and response.ok and self._message_contains_stream_link(text):
                self._track_stream_link_message(target_id, response)
        return ok

    def send_photo(
        self,
        chat_id: int,
        image_bytes: bytes,
        caption: str = "📸 Скриншот игры",
        *,
        reply_markup: dict[str, Any] | None = None,
        disable_notification: bool = False,
    ) -> bool:
        if not self.runtime_enabled or not self.settings.enabled or not self.settings.bot_token:
            return False
        data: dict[str, Any] = {"chat_id": chat_id, "caption": caption, "parse_mode": "HTML"}
        if disable_notification:
            data["disable_notification"] = True
        if reply_markup is not None:
            data["reply_markup"] = json.dumps(reply_markup, ensure_ascii=False)
        response = self._api_post(
            "sendPhoto",
            data=data,
            files={"photo": ("screen.png", image_bytes, "image/png")},
        )
        return bool(response and response.ok)

    def send_photo_to_admins(
        self,
        image_bytes: bytes,
        caption: str = "📸 Скриншот игры",
        *,
        reply_markup: dict[str, Any] | None = None,
        disable_notification: bool = False,
    ) -> bool:
        if not self.runtime_enabled or not self.settings.enabled or not self.settings.bot_token or not self.settings.admin_ids:
            return False
        ok = True
        for chat_id in self.settings.admin_ids:
            ok = self.send_photo(
                chat_id,
                image_bytes,
                caption=caption,
                reply_markup=reply_markup,
                disable_notification=disable_notification,
            ) and ok
        return ok

    def _notification_sound_enabled(self, field_name: str) -> bool:
        return bool(getattr(self.settings, field_name, True))

    def _poll_loop(self) -> None:
        while not self._stop_event.is_set():
            if not self.runtime_enabled or not self.settings.enabled or not self.settings.bot_token:
                self._stop_event.wait(1.0)
                continue
            params: dict[str, Any] = {"timeout": 20, "allowed_updates": ["message", "callback_query"]}
            if self._last_update_id is not None:
                params["offset"] = self._last_update_id + 1
            try:
                response = requests.get(self._api_url("getUpdates"), params=params, timeout=25)
                if not response.ok:
                    self._stop_event.wait(2.0)
                    continue
                if self._stop_event.is_set() or not self.runtime_enabled or not self.settings.enabled or not self.settings.bot_token:
                    break
                for update in response.json().get("result", []):
                    self._last_update_id = update.get("update_id", self._last_update_id)
                    self._handle_update(update)
            except requests.RequestException:
                self._stop_event.wait(2.0)
            except Exception as exc:
                if self.sink:
                    self.sink(f"Telegram error: {exc}")
                self._stop_event.wait(2.0)

    def _handle_update(self, update: dict[str, Any]) -> None:
        if not self.runtime_enabled or not self.settings.enabled:
            return
        if "message" in update:
            message = update["message"]
            chat_id = int(message.get("chat", {}).get("id", 0))
            if not self._is_admin(chat_id):
                return
            text = str(message.get("text") or "").split()[0].lower()
            if text == "/menu":
                self._send_menu(chat_id)
            elif text == "/notifications":
                self._send_notifications(chat_id)
            elif text == "/stats":
                self._send_stats(chat_id)
            elif text == "/tackle":
                self._send_tackle(chat_id)
            elif text == "/status":
                self._send_player_status(chat_id)
            elif text == "/scan_status":
                self._request_player_status_scan(chat_id)
            elif text == "/screen":
                self._send_screen(chat_id)
            elif text == "/shutdown_pc":
                self._shutdown_pc(chat_id)
            elif text == "/shutdown_game":
                self._shutdown_game(chat_id)
            return
        if "callback_query" in update:
            query = update["callback_query"]
            message = query.get("message", {}) if isinstance(query.get("message"), dict) else {}
            chat_id = int(message.get("chat", {}).get("id", 0))
            message_id = int(message.get("message_id") or 0) or None
            if not self._is_admin(chat_id):
                return
            data = str(query.get("data") or "")
            callback_id = str(query.get("id") or "")
            self._answer_callback(callback_id)
            if data == "menu:main:new":
                self._send_menu(chat_id)
            elif data == "menu:main":
                self._send_menu(chat_id, message_id=message_id)
            elif data == "menu:notifications":
                self._send_notifications(chat_id, message_id=message_id)
            elif data == "menu:stream":
                self._send_stream_menu(chat_id, message_id=message_id)
                snapshot = self._stream_snapshot()
                if getattr(snapshot, "status", "") in {"starting", "preparing"}:
                    self._schedule_stream_menu_refresh(chat_id, message_id)
            elif data == "menu:stream_quality":
                self._send_stream_quality(chat_id, message_id=message_id)
            elif data.startswith("toggle:"):
                self._toggle_notification(data.removeprefix("toggle:"))
                self._send_notifications(chat_id, message_id=message_id)
            elif data.startswith("toggle_sound:"):
                self._toggle_notification_sound(data.removeprefix("toggle_sound:"))
                self._send_notifications(chat_id, message_id=message_id)
            elif data.startswith("stream:quality:"):
                self._set_stream_quality(data.removeprefix("stream:quality:"), chat_id, message_id=message_id)
            elif data == "stream:start_stop":
                self._toggle_stream(chat_id, message_id=message_id)
            elif data == "stream:open":
                self._send_stream_link(chat_id)
            elif data == "stream:switch_area":
                self._switch_stream_area(chat_id, message_id=message_id)
            elif data == "stream:switch_mode":
                self._switch_stream_mode(chat_id, message_id=message_id)
            elif data == "action:start_stop":
                self._toggle_fishing(chat_id)
            elif data == "action:screen":
                self._send_screen(chat_id)
            elif data == "action:focus_game":
                self._focus_game(chat_id)
            elif data == "action:stats":
                self._send_stats(chat_id)
            elif data == "action:tackle":
                self._send_tackle(chat_id)
            elif data == "action:player_status":
                self._send_player_status(chat_id)
            elif data == "action:scan_player_status":
                self._request_player_status_scan(chat_id)
            elif data == "action:shutdown_pc":
                self._shutdown_pc(chat_id)
            elif data == "action:shutdown_game":
                self._shutdown_game(chat_id)

    def _send_menu(self, chat_id: int, *, message_id: int | None = None) -> None:
        running = self._is_running()
        start_stop_text = "🛑 Остановить" if running else "🚤 Запустить"
        keyboard = [
            [
                {"text": "🔔 Уведомления", "callback_data": "menu:notifications"},
            ],
        ]
        if self._stats_runtime_enabled():
            keyboard[0].append({"text": "📊 Статистика", "callback_data": "action:stats"})
        if self._stream_runtime_enabled():
            keyboard.append([{"text": "📺 Стрим", "callback_data": "menu:stream"}])
        fishing_tools = []
        if self._tackle_runtime_enabled():
            fishing_tools.append({"text": "🎒 Снаряжение", "callback_data": "action:tackle"})
        fishing_tools.append({"text": "📊 Показатели", "callback_data": "action:player_status"})
        keyboard.append(fishing_tools)
        keyboard.append([{"text": "🔎 Просканировать показатели", "callback_data": "action:scan_player_status"}])
        if self._fishing_runtime_enabled():
            keyboard.append([{"text": start_stop_text, "callback_data": "action:start_stop"}])
        keyboard.append([{"text": "🎮 Вернуть фокус игре", "callback_data": "action:focus_game"}])
        keyboard.append([{"text": "📸 Скриншот игры", "callback_data": "action:screen"}])
        keyboard.append(
            [
                {"text": "🖥 Выключить ПК", "callback_data": "action:shutdown_pc"},
                {"text": "🎮 Выключить игру", "callback_data": "action:shutdown_game"},
            ]
        )
        self._send_or_edit_message("🎣 Меню рыболовного бота", chat_id=chat_id, message_id=message_id, reply_markup={"inline_keyboard": keyboard})

    def _send_stream_menu(self, chat_id: int, *, message_id: int | None = None) -> None:
        if not self._stream_runtime_enabled():
            self._send_unavailable(chat_id, "Стрим", message_id=message_id)
            return
        snapshot = self._stream_snapshot()
        active = bool(getattr(snapshot, "active", False))
        starting = snapshot is not None and getattr(snapshot, "status", "") == "starting"
        running_or_starting = active or starting
        status = "online" if active else "offline"
        preparing = snapshot is not None and getattr(snapshot, "status", "") == "preparing"
        if starting:
            status = "starting"
        if preparing:
            status = "preparing"
        if not active and not starting and not preparing:
            self._delete_stream_link_messages(chat_id)
        quality = str(getattr(snapshot, "quality", "720p") or "720p")
        area = "Чат" if getattr(snapshot, "area", "full") == "chat" else "Все окно"
        snapshot_mode_enabled = bool(getattr(snapshot, "snapshot_mode_enabled", False))
        mode = "10fps" if snapshot_mode_enabled else "30fps"
        error = str(getattr(snapshot, "error", "") or "")
        auto_stop = getattr(snapshot, "seconds_until_auto_stop", None)
        auto_stop_line = ""
        if active and auto_stop is not None:
            minutes, seconds = divmod(max(0, int(auto_stop)), 60)
            auto_stop_line = f"\n⏱ Автостоп: {minutes}:{seconds:02d} без зрителей"
        formed_link = self._public_stream_url(snapshot) if active else ""
        link = self._verified_public_stream_url(snapshot) if formed_link else ""
        link_status = link or (
            f"{formed_link}\n⚠️ Ссылка сформирована, но Cloudflare пока не отвечает"
            if formed_link
            else "Формируется..."
        )
        link_line = f"\n🔗 Ссылка: {link_status}" if active else ""
        status_icon = "🟢" if status == "online" else "🔴" if status == "offline" else "🟡"
        text = (
            "📺 Стрим игры\n\n"
            f"• Статус: {status_icon} {status}\n"
            f"• Область: {area}\n"
            f"• Режим: {mode}\n"
            f"• Качество: {quality}"
            f"{auto_stop_line}"
            f"{link_line}\n\n"
            "Режим чата доступен на странице стрима"
        )
        if error:
            text = f"{text}\n\n⚠️ {error}"
        start_stop_text = "⏹ Остановить запуск" if starting else "⏹ Остановить стрим" if active else "▶️ Запустить стрим"
        switch_area_text = "🔎 Переключить область на окно игры" if area == "Чат" else "🔎 Переключить область на Чат"
        switch_mode_text = "🎞 Переключить на 30fps" if snapshot_mode_enabled else "🎞 Переключить на 10fps"
        keyboard = [
            [{"text": f"⚙️ Качество: {quality}", "callback_data": "menu:stream_quality"}],
            [{"text": switch_mode_text, "callback_data": "stream:switch_mode"}],
            [{"text": start_stop_text, "callback_data": "stream:start_stop"}],
        ]
        if running_or_starting and link:
            keyboard.append([{"text": "🔗 Открыть стрим", "url": link}])
        if active:
            keyboard.append([{"text": switch_area_text, "callback_data": "stream:switch_area"}])
        keyboard.append([{"text": "⬅️ Меню", "callback_data": "menu:main"}])
        self._send_or_edit_message(text, chat_id=chat_id, message_id=message_id, reply_markup={"inline_keyboard": keyboard})

    def _send_stream_quality(self, chat_id: int, *, message_id: int | None = None) -> None:
        if not self._stream_runtime_enabled():
            self._send_unavailable(chat_id, "Стрим", message_id=message_id)
            return
        snapshot = self._stream_snapshot()
        current = str(getattr(snapshot, "quality", "720p") or "720p")
        keyboard = [
            [
                {"text": f"{'✅ ' if current == '480p' else ''}480p", "callback_data": "stream:quality:480p"},
                {"text": f"{'✅ ' if current == '720p' else ''}720p", "callback_data": "stream:quality:720p"},
                {"text": f"{'✅ ' if current == '1080p' else ''}1080p", "callback_data": "stream:quality:1080p"},
            ],
            [{"text": "⬅️ Назад к стриму", "callback_data": "menu:stream"}],
        ]
        self._send_or_edit_message(
            "⚙️ Качество стрима\n\nВыберите разрешение трансляции.",
            chat_id=chat_id,
            message_id=message_id,
            reply_markup={"inline_keyboard": keyboard},
        )

    def _send_notifications(self, chat_id: int, *, message_id: int | None = None) -> None:
        keyboard = []
        for notify_field, sound_field, label in TELEGRAM_NOTIFICATION_ITEMS:
            notify_enabled = bool(getattr(self.settings, notify_field))
            sound_enabled = self._notification_sound_enabled(sound_field)
            notify_icon = "🔔" if notify_enabled else "🔕"
            sound_icon = "🔈" if sound_enabled else "🔇"
            keyboard.append(
                [
                    {"text": f"{notify_icon} {label}", "callback_data": f"toggle:{notify_field}"},
                    {"text": f"{sound_icon} Звук", "callback_data": f"toggle_sound:{sound_field}"},
                ]
            )
        keyboard.append([{"text": "⬅️ Меню", "callback_data": "menu:main"}])
        self._send_or_edit_message(
            "🔔 Уведомления\n\n🔔 - отправка уведомления\n🔈 - звук уведомления",
            chat_id=chat_id,
            message_id=message_id,
            reply_markup={"inline_keyboard": keyboard},
        )

    def _send_stats(self, chat_id: int) -> None:
        if not self._stats_runtime_enabled():
            self.send_message("📊 Статистика недоступна для этой подписки", chat_id=chat_id)
            return
        if self.stats_callback is None:
            self.send_message("📊 Статистика недоступна", chat_id=chat_id)
            return
        totals = self.stats_callback()
        has_stats = self.has_stats_callback() if self.has_stats_callback else totals.caught_count > 0
        if not has_stats:
            self.send_message("📊 В текущей сессии пока нет улова", chat_id=chat_id)
            return
        rows = self.stats_rows_callback() if self.stats_rows_callback else None
        self.send_message(self._format_session_stats_message("📊 Текущая статистика", "🎣 Сессия рыбалки", totals, rows=rows), chat_id=chat_id)

    def _player_status_unavailable_message(self) -> str:
        return "📊 Показатели игрока\n\nПоследнего сканирования ещё нет."

    def _format_player_status_message(self, status: PlayerStatus, *, title: str = "📊 <b>Показатели игрока</b>") -> str:
        lines = [title, ""]
        if status.food is not None:
            lines.append(f"🍗 Еда: <b>{status.food}%</b>")
        if status.water is not None:
            lines.append(f"💧 Вода: <b>{status.water}%</b>")
        if status.health is not None:
            lines.append(f"❤️ HP: <b>{status.health}%</b>")
        inventory_weight = self._format_status_weight(status.inventory_weight, status.inventory_weight_max)
        backpack_weight = self._format_status_weight(status.backpack_weight, status.backpack_weight_max)
        if inventory_weight:
            lines.append(f"🎒 Инвентарь: <b>{inventory_weight}</b> кг")
        if backpack_weight:
            lines.append(f"🧳 Рюкзак: <b>{backpack_weight}</b> кг")
        if len(lines) == 2:
            lines.append("Данных пока нет.")
        return "\n".join(lines)

    def _send_player_status(self, chat_id: int) -> None:
        status = self.player_status_callback() if self.player_status_callback else None
        if status is None:
            self.send_message(self._player_status_unavailable_message(), chat_id=chat_id)
            return
        self.send_message(self._format_player_status_message(status), chat_id=chat_id)

    def _request_player_status_scan(self, chat_id: int) -> None:
        if self.player_status_scan_callback is None:
            self.send_message("🔎 Сканирование показателей недоступно", chat_id=chat_id)
            return
        ok, message = self.player_status_scan_callback()
        if ok:
            if not hasattr(self, "_player_status_scan_lock"):
                self._player_status_scan_lock = threading.Lock()
            if not hasattr(self, "_player_status_scan_waiting_chat_ids"):
                self._player_status_scan_waiting_chat_ids = set()
            with self._player_status_scan_lock:
                self._player_status_scan_waiting_chat_ids.add(chat_id)
        prefix = "✅" if ok else "⚠️"
        self.send_message(f"{prefix} {message}", chat_id=chat_id)

    def notify_player_status_scan_result(self, status: PlayerStatus | None) -> None:
        if not hasattr(self, "_player_status_scan_lock"):
            self._player_status_scan_lock = threading.Lock()
        if not hasattr(self, "_player_status_scan_waiting_chat_ids"):
            self._player_status_scan_waiting_chat_ids = set()
        with self._player_status_scan_lock:
            chat_ids = sorted(self._player_status_scan_waiting_chat_ids)
            self._player_status_scan_waiting_chat_ids.clear()
        if not chat_ids:
            return
        if status is None:
            text = "🔎 <b>Сканирование показателей завершено</b>\n\nДанные не прочитаны."
        else:
            text = self._format_player_status_message(status, title="🔎 <b>Показатели просканированы</b>")
        for chat_id in chat_ids:
            self.send_message(text, chat_id=chat_id)

    def _send_tackle(self, chat_id: int) -> None:
        if not self._tackle_runtime_enabled():
            self.send_message("🎒 Снаряжение недоступно для этой подписки", chat_id=chat_id)
            return
        items = self.tackle_callback() if self.tackle_callback else ()
        if not items:
            self.send_message("🎒 Снаряжение\n\nПоследнего сканирования ещё нет.", chat_id=chat_id)
            return
        scanned_at = self.tackle_scanned_at_callback() if self.tackle_scanned_at_callback else None
        scanned_line = f"\n🕒 Сканирование: {scanned_at.strftime('%H:%M:%S')}" if scanned_at is not None else ""
        text = f"🎒 Снаряжение{scanned_line}\n\n{format_tackle_items(items)}"
        image_bytes = self.tackle_image_callback() if self.tackle_image_callback else None
        if image_bytes is not None and self.send_photo(chat_id, image_bytes, caption=text):
            return
        self.send_message(text, chat_id=chat_id)

    def _toggle_notification(self, field_name: str) -> None:
        allowed_fields = {notify_field for notify_field, _sound_field, _label in TELEGRAM_NOTIFICATION_ITEMS}
        if field_name not in allowed_fields:
            return
        setattr(self.settings, field_name, not bool(getattr(self.settings, field_name)))
        if self.settings_changed_callback:
            self.settings_changed_callback(self.settings)

    def _toggle_notification_sound(self, field_name: str) -> None:
        allowed_fields = {sound_field for _notify_field, sound_field, _label in TELEGRAM_NOTIFICATION_ITEMS}
        if field_name not in allowed_fields:
            return
        setattr(self.settings, field_name, not self._notification_sound_enabled(field_name))
        if self.settings_changed_callback:
            self.settings_changed_callback(self.settings)

    def _toggle_fishing(self, chat_id: int) -> None:
        if not self._fishing_runtime_enabled():
            self.send_message("🚤 Запуск рыбалки недоступен для этой подписки", chat_id=chat_id)
            return
        if self._is_running():
            if self.stop_callback:
                self.stop_callback()
            self.send_message("🛑 Рыбалка остановлена", chat_id=chat_id)
        else:
            ok = self.start_callback() if self.start_callback else False
            self.send_message("🚤 Рыбалка запущена" if ok else "⚠️ Не удалось запустить рыбалку", chat_id=chat_id)

    def _toggle_stream(self, chat_id: int, *, message_id: int | None = None) -> None:
        if not self._stream_runtime_enabled():
            self._send_unavailable(chat_id, "Стрим", message_id=message_id)
            return
        snapshot = self._stream_snapshot()
        if bool(getattr(snapshot, "active", False)) or getattr(snapshot, "status", "") == "starting":
            self._cancel_stream_link_delivery()
            if self.stream_stop_callback is not None:
                self.stream_stop_callback()
            self._delete_stream_link_messages(chat_id)
            self._send_stream_menu(chat_id, message_id=message_id)
            return
        ok = self.stream_start_callback() if self.stream_start_callback is not None else False
        if not ok:
            self.send_message("⚠️ Не удалось запустить стрим. Проверьте вкладку стрима в программе.", chat_id=chat_id)
        self._send_stream_menu(chat_id, message_id=message_id)
        if ok:
            self._schedule_stream_menu_refresh(chat_id, message_id)

    def _send_stream_link(self, chat_id: int) -> None:
        if not self._stream_runtime_enabled():
            self.send_message("📺 Стрим недоступен для этой подписки", chat_id=chat_id)
            return
        self._send_stream_menu(chat_id)

    def _set_stream_quality(self, quality: str, chat_id: int, *, message_id: int | None = None) -> None:
        if not self._stream_runtime_enabled():
            self._send_unavailable(chat_id, "Стрим", message_id=message_id)
            return
        ok = self.stream_set_quality_callback(quality) if self.stream_set_quality_callback is not None else False
        if not ok:
            self.send_message("⚠️ Не удалось изменить качество стрима.", chat_id=chat_id)
        self._send_stream_menu(chat_id, message_id=message_id)

    def _switch_stream_area(self, chat_id: int, *, message_id: int | None = None) -> None:
        if not self._stream_runtime_enabled():
            self._send_unavailable(chat_id, "Стрим", message_id=message_id)
            return
        snapshot = self._stream_snapshot()
        next_chat_zoom = getattr(snapshot, "area", "full") != "chat"
        ok = self.stream_set_chat_zoom_callback(next_chat_zoom) if self.stream_set_chat_zoom_callback is not None else False
        if not ok:
            self.send_message("⚠️ Не удалось переключить область стрима.", chat_id=chat_id)
        self._send_stream_menu(chat_id, message_id=message_id)

    def _switch_stream_mode(self, chat_id: int, *, message_id: int | None = None) -> None:
        if not self._stream_runtime_enabled():
            self._send_unavailable(chat_id, "Стрим", message_id=message_id)
            return
        snapshot = self._stream_snapshot()
        next_snapshot_mode = not bool(getattr(snapshot, "snapshot_mode_enabled", False))
        ok = (
            self.stream_set_snapshot_mode_callback(next_snapshot_mode)
            if self.stream_set_snapshot_mode_callback is not None
            else False
        )
        if not ok:
            self.send_message("⚠️ Не удалось переключить режим стрима.", chat_id=chat_id)
        self._send_stream_menu(chat_id, message_id=message_id)

    def _stream_snapshot(self) -> Any | None:
        if self.stream_status_callback is None:
            return None
        try:
            return self.stream_status_callback()
        except Exception as exc:
            if self.sink:
                self.sink(f"Stream status error: {exc}")
            return None

    def _schedule_stream_menu_refresh(self, chat_id: int, message_id: int | None) -> None:
        if message_id is None:
            return
        with self._stream_menu_refresh_lock:
            self._stream_menu_refresh_generation += 1
            generation = self._stream_menu_refresh_generation
        threading.Thread(
            target=self._stream_menu_refresh_loop,
            args=(chat_id, message_id, generation),
            name="sonar-telegram-stream-menu",
            daemon=True,
        ).start()

    def _stream_menu_refresh_loop(self, chat_id: int, message_id: int, generation: int) -> None:
        deadline = time.monotonic() + STREAM_MENU_REFRESH_MAX_SECONDS
        while time.monotonic() < deadline and not self._stop_event.wait(STREAM_MENU_REFRESH_INTERVAL_SECONDS):
            with self._stream_menu_refresh_lock:
                if generation != self._stream_menu_refresh_generation:
                    return
            snapshot = self._stream_snapshot()
            self._send_stream_menu(chat_id, message_id=message_id)
            status = str(getattr(snapshot, "status", "") or "")
            active = bool(getattr(snapshot, "active", False))
            if status in {"starting", "preparing"}:
                continue
            if not active:
                self._delete_stream_link_messages(chat_id)
                return

    def _schedule_stream_link_delivery(self, chat_id: int) -> None:
        with self._stream_link_delivery_lock:
            self._stream_link_delivery_generation += 1
            generation = self._stream_link_delivery_generation
        threading.Thread(
            target=self._stream_link_delivery_loop,
            args=(chat_id, generation),
            name="sonar-telegram-stream-link",
            daemon=True,
        ).start()

    def _cancel_stream_link_delivery(self) -> None:
        with self._stream_link_delivery_lock:
            self._stream_link_delivery_generation += 1

    def _stream_link_delivery_loop(self, chat_id: int, generation: int) -> None:
        deadline = time.monotonic() + STREAM_LINK_DELIVERY_MAX_SECONDS
        while time.monotonic() < deadline and not self._stop_event.wait(STREAM_LINK_DELIVERY_INTERVAL_SECONDS):
            with self._stream_link_delivery_lock:
                if generation != self._stream_link_delivery_generation:
                    return
            snapshot = self._stream_snapshot()
            status = str(getattr(snapshot, "status", "") or "")
            if status == "error":
                self._send_stream_menu(chat_id)
                return
            if status not in {"starting", "preparing"} and not bool(getattr(snapshot, "active", False)):
                self._delete_stream_link_messages(chat_id)
                return
            url = self._verified_public_stream_url(snapshot)
            if url:
                self._send_stream_menu(chat_id)
                return
        with self._stream_link_delivery_lock:
            if generation != self._stream_link_delivery_generation:
                return
        self._send_stream_menu(chat_id)

    @staticmethod
    def _public_stream_url(snapshot: Any | None) -> str:
        for field_name in ("public_url", "stream_url"):
            url = NotificationManager._normalize_stream_page_url(str(getattr(snapshot, field_name, "") or ""))
            if url:
                return url
        return ""

    @staticmethod
    def _normalize_stream_page_url(url: str) -> str:
        if not NotificationManager._is_public_stream_url(url):
            return ""
        parsed = urlparse(url.strip())
        path = parsed.path.rstrip("/")
        path_lower = path.lower()
        if path_lower.startswith("/hls/") or path_lower.endswith(".m3u8"):
            path = "/live"
        elif not path_lower.endswith("/live"):
            path = f"{path}/live" if path else "/live"
        return urlunparse((parsed.scheme, parsed.netloc, f"{path}/", "", "", ""))

    def _verified_public_stream_url(self, snapshot: Any | None) -> str:
        url = self._public_stream_url(snapshot)
        if not url:
            self._stream_verified_url = ""
            return ""
        if url == self._stream_verified_url:
            return url
        if "trycloudflare.com" not in url.lower():
            self._stream_verified_url = url
            return url
        if self._url_is_reachable(url):
            self._stream_verified_url = url
            return url
        return ""

    @staticmethod
    def _url_is_reachable(url: str) -> bool:
        try:
            request = urllib.request.Request(url, headers={"User-Agent": "Sonar-stream-check/1.0"})
            with urllib.request.urlopen(request, timeout=0.8) as response:
                return 200 <= int(getattr(response, "status", 200)) < 500
        except (OSError, urllib.error.URLError, ValueError):
            return False

    @staticmethod
    def _is_public_stream_url(url: str) -> bool:
        parsed = urlparse(url.strip())
        if parsed.scheme.lower() not in {"http", "https"} or not parsed.hostname:
            return False
        host = parsed.hostname.strip("[]").lower()
        if host == "localhost":
            return False
        try:
            address = ipaddress.ip_address(host)
        except ValueError:
            return True
        return not (address.is_loopback or address.is_unspecified)

    @staticmethod
    def _message_contains_stream_link(text: str) -> bool:
        for match in re.findall(r"https?://[^\s<>()]+", text):
            url = match.rstrip(".,;)")
            if NotificationManager._is_public_stream_url(url) and "/live" in url.lower():
                return True
        return False

    def _track_stream_link_message(self, chat_id: int, response: requests.Response) -> None:
        try:
            message_id = int((response.json().get("result") or {}).get("message_id") or 0)
        except (TypeError, ValueError, AttributeError):
            message_id = 0
        if message_id <= 0:
            return
        with self._stream_link_delivery_lock:
            self._stream_link_messages.setdefault(chat_id, set()).add(message_id)

    def _delete_stream_link_messages(self, chat_id: int | None = None) -> None:
        with self._stream_link_delivery_lock:
            if chat_id is None:
                targets = {target: set(ids) for target, ids in self._stream_link_messages.items()}
                self._stream_link_messages.clear()
            else:
                targets = {chat_id: set(self._stream_link_messages.pop(chat_id, set()))}
            self._stream_verified_url = ""
        for target_id, message_ids in targets.items():
            for message_id in message_ids:
                self._api_post("deleteMessage", json={"chat_id": target_id, "message_id": message_id})

    def _send_screen(self, chat_id: int) -> None:
        if self.screenshot_callback is None:
            self.send_message("⚠️ Скриншот недоступен", chat_id=chat_id)
            return
        try:
            self.send_photo(chat_id, self.screenshot_callback())
        except Exception as exc:
            self.send_message(f"⚠️ Не удалось сделать скриншот: {exc}", chat_id=chat_id)

    def _focus_game(self, chat_id: int) -> None:
        ok = self.focus_game_callback() if self.focus_game_callback else False
        self.send_message("🎮 Фокус возвращён игре" if ok else "⚠️ Не удалось вернуть фокус игре", chat_id=chat_id)

    def _shutdown_game(self, chat_id: int) -> None:
        if self.shutdown_game_callback:
            self.shutdown_game_callback()
        self.send_message("🎮 Игра выключается", chat_id=chat_id)

    def _shutdown_pc(self, chat_id: int) -> None:
        self.send_message("🖥 ПК выключается", chat_id=chat_id)
        time.sleep(0.3)
        if self.shutdown_pc_callback:
            self.shutdown_pc_callback()

    def _is_running(self) -> bool:
        return bool(self.is_running_callback and self.is_running_callback())

    def _is_admin(self, chat_id: int) -> bool:
        return bool(chat_id) and chat_id in self.settings.admin_ids

    def _answer_callback(self, callback_id: str) -> None:
        if callback_id:
            self._api_post("answerCallbackQuery", json={"callback_query_id": callback_id})

    def _send_or_edit_message(
        self,
        text: str,
        *,
        chat_id: int,
        message_id: int | None = None,
        reply_markup: dict[str, Any] | None = None,
    ) -> bool:
        if message_id is None:
            return self.send_message(text, chat_id=chat_id, reply_markup=reply_markup)
        if self.sink:
            self.sink(text)
        if not self.runtime_enabled or not self.settings.enabled or not self.settings.bot_token:
            return False
        payload: dict[str, Any] = {"chat_id": chat_id, "message_id": message_id, "text": text, "parse_mode": "HTML", "disable_web_page_preview": True}
        if reply_markup is not None:
            payload["reply_markup"] = reply_markup
        response = self._api_post("editMessageText", json=payload)
        if response and response.ok:
            return True
        if response is not None and response.status_code == 400:
            try:
                description = str(response.json().get("description") or "").lower()
            except ValueError:
                description = ""
            if "message is not modified" in description:
                return True
        return self.send_message(text, chat_id=chat_id, reply_markup=reply_markup)

    def _api_url(self, method: str) -> str:
        return f"{decrypt_text_literal('telegram_api_base')}/bot{self.settings.bot_token}/{method}"

    def _api_post(self, method: str, **kwargs) -> requests.Response | None:
        if not self.runtime_enabled or not self.settings.enabled or not self.settings.bot_token:
            return None
        try:
            return requests.post(self._api_url(method), timeout=self.timeout, **kwargs)
        except requests.RequestException:
            return None

    @staticmethod
    def _decorate_catch_photo(image_bytes: bytes, *, released: bool = False) -> bytes:
        try:
            with Image.open(BytesIO(image_bytes)) as image:
                original = ImageOps.exif_transpose(image).convert("RGBA")
                width, height = original.size
                if width <= 0 or height <= 0:
                    return image_bytes
                crop_x = min(width // 3, max(0, int(round(width * 0.02))))
                crop_top = min(height // 3, max(0, int(round(height * 0.01))))
                if (crop_x > 0 or crop_top > 0) and width - crop_x * 2 > 1 and height - crop_top > 1:
                    original = original.crop((crop_x, crop_top, width - crop_x, height))
                original = original.resize(CATCH_FOREGROUND_TARGET_SIZE, Image.Resampling.BICUBIC)
                width, height = original.size
                canvas_width = width + CATCH_CANVAS_PADDING_PX
                canvas_height = height + CATCH_CANVAS_PADDING_PX
                framed = NotificationManager._decorate_catch_foreground(original)
                background = NotificationManager._build_catch_background(
                    original,
                    canvas_width,
                    canvas_height,
                    released=released,
                )
                x = (canvas_width - framed.width) // 2
                y = (canvas_height - framed.height) // 2
                NotificationManager._draw_catch_frame_shadow(
                    background,
                    (x, y, x + framed.width - 1, y + framed.height - 1),
                )
                background.alpha_composite(framed, (x, y))
                output = BytesIO()
                background.save(output, format="PNG")
                return output.getvalue()
        except Exception:
            return image_bytes

    @staticmethod
    def _build_catch_background(image: Image.Image, canvas_width: int, canvas_height: int, *, released: bool) -> Image.Image:
        center_color = NotificationManager._sample_center_color(image)
        accent = CATCH_BACKGROUND_RELEASE_ACCENT if released else CATCH_BACKGROUND_COLORS[2]
        palette = (CATCH_BACKGROUND_COLORS[0], CATCH_BACKGROUND_COLORS[1], accent, center_color)

        sample_source = Image.new("RGB", image.size, palette[1])
        sample_source.paste(image.convert("RGB"), mask=image.getchannel("A"))
        sample = sample_source.resize((30, 30), Image.Resampling.BILINEAR)
        seed = int.from_bytes(hashlib.blake2b(image.tobytes(), digest_size=8).digest(), "big")
        rng = random.Random(seed)

        colors: list[tuple[int, int, int]] = []
        for red, green, blue in sample.getdata():
            luminance = (0.2126 * red + 0.7152 * green + 0.0722 * blue) / 255.0
            saturation = (max(red, green, blue) - min(red, green, blue)) / 255.0
            tone = luminance + rng.uniform(-0.14, 0.14)
            accent_chance = 0.16 + saturation * 0.24 + max(0.0, tone - 0.24) * 0.22
            center_chance = 0.07 + saturation * 0.16 + luminance * 0.08
            roll = rng.random()
            if roll < accent_chance:
                color = palette[2]
            elif roll < accent_chance + center_chance:
                color = palette[3]
            elif tone < 0.22:
                color = palette[0]
            elif tone < 0.48:
                color = palette[1]
            else:
                color = palette[2] if rng.random() < 0.72 else palette[3]
            colors.append(NotificationManager._mix_rgb(color, palette[1], rng.random() * 0.12))
        rng.shuffle(colors)

        background_seed = Image.new("RGB", sample.size)
        background_seed.putdata(colors)
        background = background_seed.resize((canvas_width, canvas_height), Image.Resampling.BICUBIC)
        background = background.filter(ImageFilter.GaussianBlur(radius=max(18, max(canvas_width, canvas_height) // 14)))
        background = ImageEnhance.Color(background).enhance(1.35)
        background = ImageEnhance.Contrast(background).enhance(1.12)
        background = background.convert("RGBA")

        vignette = Image.new("L", (96, 96), 0)
        vignette_pixels = vignette.load()
        for y in range(96):
            for x in range(96):
                dx = (x - 47.5) / 47.5
                dy = (y - 47.5) / 47.5
                alpha = int(max(0.0, min(1.0, (dx * dx + dy * dy - 0.25) / 0.9)) * 88)
                vignette_pixels[x, y] = alpha
        vignette = vignette.resize((canvas_width, canvas_height), Image.Resampling.BICUBIC)
        background.alpha_composite(Image.new("RGBA", background.size, (0, 0, 0, 0)))
        background.alpha_composite(Image.composite(Image.new("RGBA", background.size, (0, 0, 0, 120)), Image.new("RGBA", background.size, (0, 0, 0, 0)), vignette))
        return background

    @staticmethod
    def _sample_center_color(image: Image.Image) -> tuple[int, int, int]:
        width, height = image.size
        box_width = max(1, width // 8)
        box_height = max(1, height // 8)
        left = max(0, width // 2 - box_width // 2)
        top = max(0, height // 2 - box_height // 2)
        crop = image.crop((left, top, min(width, left + box_width), min(height, top + box_height))).convert("RGBA")
        total_alpha = 0
        red_total = green_total = blue_total = 0
        for red, green, blue, alpha in crop.getdata():
            if alpha <= 8:
                continue
            total_alpha += alpha
            red_total += red * alpha
            green_total += green * alpha
            blue_total += blue * alpha
        if total_alpha <= 0:
            return CATCH_BACKGROUND_COLORS[1]
        return red_total // total_alpha, green_total // total_alpha, blue_total // total_alpha

    @staticmethod
    def _mix_rgb(first: tuple[int, int, int], second: tuple[int, int, int], amount: float) -> tuple[int, int, int]:
        amount = max(0.0, min(1.0, amount))
        return tuple(int(round(a * (1.0 - amount) + b * amount)) for a, b in zip(first, second))

    @staticmethod
    def _decorate_catch_foreground(foreground: Image.Image) -> Image.Image:
        foreground = foreground.convert("RGBA")
        foreground = ImageOps.expand(foreground, border=CATCH_FOREGROUND_EDGE_PADDING_PX, fill=CATCH_FOREGROUND_EDGE_FILL)
        width, height = foreground.size
        padding = 2
        outer_width = width + padding * 2
        outer_height = height + padding * 2
        radius = max(14, int(round(min(width, height) * 0.045)))
        inner_radius = max(10, radius - 3)
        canvas = Image.new("RGBA", (outer_width, outer_height), (0, 0, 0, 0))
        outer_rect = (
            0,
            0,
            outer_width - 1,
            outer_height - 1,
        )

        draw = ImageDraw.Draw(canvas, "RGBA")
        draw.rounded_rectangle(outer_rect, radius=radius, fill=(255, 255, 255, 31), outline=(255, 255, 255, 61), width=1)
        image_pos = (padding, padding)
        image_mask = NotificationManager._rounded_mask(foreground.size, inner_radius)
        foreground_alpha = ImageChops.multiply(foreground.getchannel("A"), image_mask)
        foreground.putalpha(foreground_alpha)
        canvas.alpha_composite(foreground, image_pos)

        glass = NotificationManager._glass_overlay((outer_width, outer_height), radius)
        canvas.alpha_composite(glass, (0, 0))
        inset = CATCH_FRAME_INSET_PX
        inner_rect = (
            outer_rect[0] + inset,
            outer_rect[1] + inset,
            outer_rect[2] - inset,
            outer_rect[3] - inset,
        )
        draw.rounded_rectangle(inner_rect, radius=max(6, radius - 7), outline=(0, 0, 0, 26), width=2)
        draw.rounded_rectangle(inner_rect, radius=max(6, radius - 7), outline=(255, 255, 255, 61), width=1)
        NotificationManager._add_catch_glare(canvas, outer_rect, small=False)
        NotificationManager._add_catch_glare(canvas, outer_rect, small=True)
        return canvas

    @staticmethod
    def _draw_catch_frame_shadow(canvas: Image.Image, rect: tuple[int, int, int, int]) -> None:
        width = rect[2] - rect[0] + 1
        height = rect[3] - rect[1] + 1
        radius = max(14, int(round(min(width, height) * 0.045)))
        shadow_base = max(18, int(round(min(width, height) * 0.055)))
        NotificationManager._draw_rounded_shadow(
            canvas,
            rect,
            radius,
            (0, int(shadow_base * 0.9)),
            int(shadow_base * 2.0),
            (0, 0, 0, CATCH_FRAME_SHADOW_PRIMARY_ALPHA),
        )
        NotificationManager._draw_rounded_shadow(
            canvas,
            rect,
            radius,
            (0, int(shadow_base * 0.35)),
            int(shadow_base * 0.75),
            (0, 0, 0, CATCH_FRAME_SHADOW_SECONDARY_ALPHA),
        )

    @staticmethod
    def _draw_rounded_shadow(
        canvas: Image.Image,
        rect: tuple[int, int, int, int],
        radius: int,
        offset: tuple[int, int],
        blur: int,
        color: tuple[int, int, int, int],
    ) -> None:
        mask = Image.new("L", canvas.size, 0)
        shadow_rect = (
            rect[0] + offset[0],
            rect[1] + offset[1],
            rect[2] + offset[0],
            rect[3] + offset[1],
        )
        ImageDraw.Draw(mask).rounded_rectangle(shadow_rect, radius=radius, fill=color[3])
        mask = mask.filter(ImageFilter.GaussianBlur(radius=blur))
        shadow = Image.new("RGBA", canvas.size, color[:3] + (0,))
        shadow.putalpha(mask)
        canvas.alpha_composite(shadow)

    @staticmethod
    def _rounded_mask(size: tuple[int, int], radius: int) -> Image.Image:
        mask = Image.new("L", size, 0)
        ImageDraw.Draw(mask).rounded_rectangle((0, 0, size[0] - 1, size[1] - 1), radius=radius, fill=255)
        return mask

    @staticmethod
    def _glass_overlay(size: tuple[int, int], radius: int) -> Image.Image:
        width, height = size
        overlay = Image.new("RGBA", size, (0, 0, 0, 0))
        pixels = overlay.load()
        for y in range(height):
            for x in range(width):
                diagonal = (x + y) / max(1, width + height)
                if diagonal < 0.22:
                    alpha = int(36 * (1.0 - diagonal / 0.22))
                    pixels[x, y] = (255, 255, 255, alpha)
                elif diagonal > 0.58:
                    alpha = int(22 * min(1.0, (diagonal - 0.58) / 0.42))
                    pixels[x, y] = (0, 0, 0, alpha)
        mask = NotificationManager._rounded_mask(size, max(1, radius - 3))
        radial = Image.new("L", size, 0)
        radial_pixels = radial.load()
        center_x = width * 0.24
        center_y = height * 0.10
        max_distance = max(1.0, min(width, height) * 0.38)
        for y in range(height):
            for x in range(width):
                distance = ((x - center_x) ** 2 + (y - center_y) ** 2) ** 0.5
                if distance < max_distance:
                    radial_pixels[x, y] = int((1.0 - distance / max_distance) * 32)
        radial_layer = Image.new("RGBA", size, (255, 255, 255, 0))
        radial_layer.putalpha(ImageChops.multiply(radial, mask))
        overlay.putalpha(ImageChops.multiply(overlay.getchannel("A"), mask))
        overlay.alpha_composite(radial_layer)
        return overlay

    @staticmethod
    def _add_catch_glare(canvas: Image.Image, rect: tuple[int, int, int, int], *, small: bool) -> None:
        left, top, right, bottom = rect
        width = right - left + 1
        height = bottom - top + 1
        if small:
            glare_size = (max(12, int(width * 0.22)), max(18, int(height * 0.38)))
            position = (right - int(width * 0.26), bottom - int(height * 0.45))
            angle = 6
            alpha = 14
        else:
            glare_size = (max(24, int(width * 0.52)), max(16, int(height * 0.24)))
            position = (left + int(width * 0.05), top + int(height * 0.04))
            angle = -12
            alpha = 24
        glare = Image.new("RGBA", glare_size, (0, 0, 0, 0))
        glare_pixels = glare.load()
        center_x = glare_size[0] * (0.18 if not small else 0.5)
        center_y = glare_size[1] * (0.25 if not small else 0.0)
        max_distance = max(1.0, (glare_size[0] ** 2 + glare_size[1] ** 2) ** 0.5)
        for y in range(glare_size[1]):
            for x in range(glare_size[0]):
                distance = ((x - center_x) ** 2 + (y - center_y) ** 2) ** 0.5
                fade = max(0.0, 1.0 - distance / max_distance)
                directional = max(0.0, 1.0 - x / max(1, glare_size[0])) if not small else max(0.0, 1.0 - y / max(1, glare_size[1]))
                glare_pixels[x, y] = (255, 255, 255, int(alpha * fade * (0.35 + directional * 0.65)))
        glare_mask = NotificationManager._rounded_mask(glare_size, max(6, min(glare_size) // 2))
        glare.putalpha(ImageChops.multiply(glare.getchannel("A"), glare_mask))
        glare = glare.filter(ImageFilter.GaussianBlur(radius=0.4 if not small else 0.3))
        glare = glare.rotate(angle, resample=Image.Resampling.BICUBIC, expand=True)
        canvas.alpha_composite(glare, position)

    @staticmethod
    def _format_meal_message(item_name: str, item_info: ItemInfo | None, player_status: PlayerStatus | None = None) -> str:
        title = _non_empty(item_info.item_name if item_info else "") or _non_empty(item_info.title if item_info else "") or item_name.strip() or "еда"
        lines = ["🍽 <b>Питание использовано!</b>", "", f"🥪 <b>Съедено:</b> {_h(title)}"]
        if item_info is not None:
            if item_info.weight:
                lines.append(f"⚖️ <b>Вес:</b> {_h(item_info.weight)} кг")
            if item_info.satiety_change:
                lines.append(f"🍗 <b>Сытость:</b> {_h(item_info.satiety_change)}")
            if item_info.thirst_change:
                lines.append(f"💧 <b>Жажда:</b> {_h(item_info.thirst_change)}")
            if item_info.condition_percent:
                lines.append(f"🛡 <b>Состояние:</b> {_h(item_info.condition_percent)}%")
            if item_info.poison_chance:
                lines.append(f"🧪 <b>Шанс отравления:</b> {_h(item_info.poison_chance)}")
            if item_info.strength:
                lines.append(f"🧰 <b>Прочность:</b> {_h(item_info.strength)}")
            if item_info.effects:
                lines.extend(["", "✨ <b>Эффекты</b>"])
                for effect in item_info.effects:
                    duration = f" — ⏳ {_h(effect.duration)}" if effect.duration else ""
                    lines.append(f"• <b>{_h(effect.name)}</b>{duration}")
                    if effect.description:
                        lines.append(f"  <i>{_h(effect.description)}</i>")
                    for modification in effect.parameter_modifications:
                        lines.append(f"  <code>{_h(modification)}</code>")
            elif item_info.parameter_modifications:
                lines.extend(["", "🧩 <b>Модификации параметров</b>"])
                for modification in item_info.parameter_modifications:
                    lines.append(f"• <code>{_h(modification)}</code>")
        if player_status is not None:
            status_lines = []
            if player_status.food is not None:
                status_lines.append(f"🍗 <b>Еда:</b> {player_status.food}%")
            if player_status.water is not None:
                status_lines.append(f"💧 <b>Вода:</b> {player_status.water}%")
            if player_status.health is not None:
                status_lines.append(f"❤️ <b>Здоровье:</b> {player_status.health}%")
            inventory_weight = NotificationManager._format_status_weight(
                player_status.inventory_weight,
                player_status.inventory_weight_max,
            )
            if inventory_weight:
                status_lines.append(f"🎒 <b>Инвентарь:</b> {inventory_weight} кг")
            backpack_weight = NotificationManager._format_status_weight(
                player_status.backpack_weight,
                player_status.backpack_weight_max,
            )
            if backpack_weight:
                status_lines.append(f"🎒 <b>Рюкзак:</b> {backpack_weight} кг")
            if status_lines:
                lines.extend(["", "📊 <b>Показатели</b>", *status_lines])
        return "\n".join(lines)

    @staticmethod
    def _format_status_weight(current: float | None, maximum: float | None) -> str:
        if current is None and maximum is None:
            return ""
        if current is None:
            return f"— / {NotificationManager._format_status_weight_number(maximum)}"
        if maximum is None:
            return NotificationManager._format_status_weight_number(current)
        return (
            f"{NotificationManager._format_status_weight_number(current)} / "
            f"{NotificationManager._format_status_weight_number(maximum)}"
        )

    @staticmethod
    def _format_status_weight_number(value: float | None) -> str:
        if value is None:
            return "—"
        return f"{value:.2f}".rstrip("0").rstrip(".")

    @staticmethod
    def _format_catch_message(
        fish_name: str,
        weight_kg: float | None,
        quality_text: str | None,
        xp_current: int | None,
        xp_total: int | None,
        totals: SessionTotals,
        *,
        released: bool | None = None,
    ) -> str:
        trophy = bool(quality_text and quality_text.strip().casefold() == "трофейная")
        lines = []
        if trophy:
            lines.append(f"🏆 <b>{_h(quality_text)}!</b>")
            lines.append("")
        lines.append(f"🐟 <b>{_h(fish_name)}</b> — {_h(format_weight(weight_kg or 0.0))}")
        if released is not None:
            status = "отпущена" if released else "оставлена"
            lines.append(f"🌊 <b>Статус:</b> {_h(status)}")
        lines.append("")
        lines.append(f"📦 <b>Всего:</b> {_h(format_weight(totals.caught_kg))} · {totals.caught_count} выловов")
        lines.append(f"📦 <b>Оставлено:</b> {_h(format_weight(totals.kept_kg))} · {totals.kept_count} выловов")
        lines.append(f"💰 <b>Доход:</b> от {_h(format_money(totals.earned_min))}")
        if xp_current is not None and xp_total is not None:
            lines.append(f"⭐ <b>Опыт:</b> {xp_current} / {xp_total}")
        elif xp_current is not None:
            lines.append(f"⭐ <b>Опыт:</b> {xp_current}")
        return "\n".join(lines)

    @staticmethod
    def _format_session_stats_message(
        title: str,
        subtitle: str,
        totals: SessionTotals,
        *,
        reason: str | None = None,
        rows: list[FishStatsRow] | None = None,
    ) -> str:
        lines = [
            f"<b>{_h(title)}</b>",
            "",
            f"<b>{_h(subtitle)}</b>",
            "",
        ]
        if reason:
            lines.extend([f"<b>Причина остановки:</b> {_h(reason)}", ""])
        lines.extend(
            [
                f"⏱ Длительность: {format_duration(totals.duration_seconds)}",
                f"🎣 Поймано: {format_catch_summary(totals.caught_count, totals.caught_kg)}",
                f"🌊 Отпущено: {format_catch_summary(totals.released_count, totals.released_kg)}",
                f"⚖️ Общий вес: {format_weight(totals.kept_kg)}",
                f"💰 Доход: {format_money_range(totals.earned_min, totals.earned_max)}",
                f"📈 Доход в час: {format_money_range(totals.earned_per_hour_min, totals.earned_per_hour_max)}",
            ]
        )
        if rows:
            lines.extend(["", "➖➖➖➖➖➖➖➖➖", "", "🐟 Улов по видам", ""])
            for row in rows:
                stat = row.stat
                lines.extend(
                    [
                        f"• <b>{_h(stat.name)}</b>",
                        f"  🎣 Поймано: {format_catch_summary(stat.caught_count, stat.caught_kg)}",
                        f"  🌊 Отпущено: {format_catch_summary(stat.released_count, stat.released_kg)}",
                        f"  💰 Доход: {format_money_range(row.earned_min, row.earned_max)}",
                        "",
                    ]
                )
            while lines and lines[-1] == "":
                lines.pop()
        return "\n".join(lines)
