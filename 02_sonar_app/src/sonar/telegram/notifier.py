from __future__ import annotations

import threading
import time
from dataclasses import dataclass, field
from typing import Any, Callable

import requests

from sonar.config.models import TelegramSettings
from sonar.fishing.statistics import FishStatsRow, SessionTotals, format_catch_summary, format_duration, format_money_range, format_weight


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
    _stop_event: threading.Event = field(default_factory=threading.Event, init=False)
    _poll_thread: threading.Thread | None = field(default=None, init=False)
    _last_update_id: int | None = field(default=None, init=False)

    def __post_init__(self) -> None:
        self._stop_event = threading.Event()
        self._poll_thread = None
        self._last_update_id = None

    def configure(
        self,
        settings: TelegramSettings,
        *,
        start_callback: Callable[[], bool] | None = None,
        stop_callback: Callable[[], None] | None = None,
        is_running_callback: Callable[[], bool] | None = None,
        stats_callback: Callable[[], SessionTotals] | None = None,
        stats_rows_callback: Callable[[], list[FishStatsRow]] | None = None,
        has_stats_callback: Callable[[], bool] | None = None,
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
    ) -> None:
        self.settings = settings
        self.start_callback = start_callback
        self.stop_callback = stop_callback
        self.is_running_callback = is_running_callback
        self.stats_callback = stats_callback
        self.stats_rows_callback = stats_rows_callback
        self.has_stats_callback = has_stats_callback
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
        if self.settings.enabled and self.settings.bot_token:
            self.start_polling()
        else:
            self.stop_polling()

    def start_polling(self) -> None:
        poll_thread = getattr(self, "_poll_thread", None)
        if poll_thread and poll_thread.is_alive():
            return
        if not hasattr(self, "_stop_event"):
            self._stop_event = threading.Event()
        self._stop_event.clear()
        self._poll_thread = threading.Thread(target=self._poll_loop, name="sonar-telegram", daemon=True)
        self._poll_thread.start()

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
    ) -> None:
        if not self.settings.notify_catch:
            return
        message = self._format_catch_message(fish_name, weight_kg, quality_text, xp_current, xp_total, totals)
        if image_bytes is not None and self.send_photo_to_admins(image_bytes, caption=message):
            return
        self.send_message(message)

    def notify_fishing_started(self, totals: SessionTotals, has_stats: bool) -> None:
        if not self.settings.notify_start_stop:
            return
        if not has_stats:
            self.send_message("🚤 Рыбалка началась!\n\n🎣 Удочка закинута, ждём улов...")
            return
        self.send_message(self._format_session_stats_message("🚤 Рыбалка началась!", "📊 Текущая сессия", totals))

    def notify_fishing_stopped(self, totals: SessionTotals, *, reason: str | None = None) -> None:
        if not self.settings.notify_start_stop:
            return
        self.send_message(self._format_session_stats_message("🛑 Рыбалка остановлена!", "📊 Статистика сессии", totals, reason=reason))

    def notify_meal_eaten(self) -> None:
        if self.settings.notify_meal:
            self.send_message("🍔 Голод утолён!")

    def notify_meal_ended(self) -> None:
        if self.settings.notify_meal:
            self.send_message("🍽 Эффект еды закончился")

    def notify_backpack_stored(self, count: int) -> None:
        if count > 0 and self.settings.notify_inventory_full:
            self.send_message(f"🎒 Рыба переложена в рюкзак: {count} шт")

    def notify_inventory_full(self) -> None:
        if self.settings.notify_inventory_full:
            self.send_message("📦 Закончилось место!")

    def notify_focus_lost(self) -> None:
        if self.settings.notify_focus_lost:
            self.send_message(
                "⚠️🎮 Фокус ушёл с игры\n\n"
                "Ввод поставлен на паузу, чтобы клавиши не нажимались в другом окне. "
                "Откройте меню Telegram и нажмите «Вернуть фокус игре»."
            )

    def notify_fishing_failed(self) -> None:
        if self.settings.notify_start_stop:
            self.send_message("⚠️ Не удалось восстановить рыбалку")

    def notify_fishing_restored(self) -> None:
        if self.settings.notify_start_stop:
            self.send_message("✅ Рыбалка восстановлена")

    def send_message(self, text: str, *, chat_id: int | None = None, reply_markup: dict[str, Any] | None = None) -> bool:
        if self.sink:
            self.sink(text)
        if not self.settings.enabled or not self.settings.bot_token:
            return False
        chat_ids = [chat_id] if chat_id is not None else list(self.settings.admin_ids)
        if not chat_ids:
            return False
        payload_base: dict[str, Any] = {"text": text}
        if reply_markup is not None:
            payload_base["reply_markup"] = reply_markup
        ok = True
        for target_id in chat_ids:
            response = self._api_post("sendMessage", json={"chat_id": target_id, **payload_base})
            ok = ok and bool(response and response.ok)
        return ok

    def send_photo(self, chat_id: int, image_bytes: bytes, caption: str = "📸 Скриншот игры") -> bool:
        response = self._api_post(
            "sendPhoto",
            data={"chat_id": chat_id, "caption": caption},
            files={"photo": ("screen.png", image_bytes, "image/png")},
        )
        return bool(response and response.ok)

    def send_photo_to_admins(self, image_bytes: bytes, caption: str = "📸 Скриншот игры") -> bool:
        if not self.settings.enabled or not self.settings.bot_token or not self.settings.admin_ids:
            return False
        ok = True
        for chat_id in self.settings.admin_ids:
            ok = self.send_photo(chat_id, image_bytes, caption=caption) and ok
        return ok

    def _poll_loop(self) -> None:
        while not self._stop_event.is_set():
            if not self.settings.enabled or not self.settings.bot_token:
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
            if data == "menu:main":
                self._send_menu(chat_id, message_id=message_id)
            elif data == "menu:notifications":
                self._send_notifications(chat_id, message_id=message_id)
            elif data == "menu:stream":
                self._send_stream_menu(chat_id, message_id=message_id)
            elif data == "menu:stream_quality":
                self._send_stream_quality(chat_id, message_id=message_id)
            elif data.startswith("toggle:"):
                self._toggle_notification(data.removeprefix("toggle:"))
                self._send_notifications(chat_id, message_id=message_id)
            elif data.startswith("stream:quality:"):
                self._set_stream_quality(data.removeprefix("stream:quality:"), chat_id, message_id=message_id)
            elif data == "stream:start_stop":
                self._toggle_stream(chat_id, message_id=message_id)
            elif data == "stream:open":
                self._send_stream_link(chat_id)
            elif data == "stream:switch_area":
                self._switch_stream_area(chat_id, message_id=message_id)
            elif data == "action:start_stop":
                self._toggle_fishing(chat_id)
            elif data == "action:screen":
                self._send_screen(chat_id)
            elif data == "action:focus_game":
                self._focus_game(chat_id)
            elif data == "action:stats":
                self._send_stats(chat_id)
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
                {"text": "📊 Статистика", "callback_data": "action:stats"},
            ],
            [
                {"text": "📺 Стрим", "callback_data": "menu:stream"},
            ],
            [
                {"text": start_stop_text, "callback_data": "action:start_stop"},
            ],
            [
                {"text": "🎮 Вернуть фокус игре", "callback_data": "action:focus_game"},
            ],
            [
                {"text": "📸 Скриншот игры", "callback_data": "action:screen"},
            ],
            [
                {"text": "🖥 Выключить ПК", "callback_data": "action:shutdown_pc"},
                {"text": "🎮 Выключить игру", "callback_data": "action:shutdown_game"},
            ],
        ]
        self._send_or_edit_message("🎣 Меню рыболовного бота", chat_id=chat_id, message_id=message_id, reply_markup={"inline_keyboard": keyboard})

    def _send_stream_menu(self, chat_id: int, *, message_id: int | None = None) -> None:
        snapshot = self._stream_snapshot()
        active = bool(getattr(snapshot, "active", False))
        status = "online" if active else "offline"
        if snapshot is not None and getattr(snapshot, "status", "") == "starting":
            status = "starting"
        quality = str(getattr(snapshot, "quality", "720p") or "720p")
        area = "Чат" if getattr(snapshot, "area", "full") == "chat" else "Все окно"
        error = str(getattr(snapshot, "error", "") or "")
        auto_stop = getattr(snapshot, "seconds_until_auto_stop", None)
        auto_stop_line = ""
        if active and auto_stop is not None:
            minutes, seconds = divmod(max(0, int(auto_stop)), 60)
            auto_stop_line = f"\nАвтостоп без зрителей: {minutes}:{seconds:02d}"
        text = (
            "📺 Меню стрима игры.\n"
            f"Статус {status}\n"
            f"Область: {area}\n"
            f"Качество: {quality}"
            f"{auto_stop_line}\n\n"
            "Режим чата доступен на странице стрима"
        )
        if error:
            text = f"{text}\n\n⚠️ {error}"
        start_stop_text = "⏹ Остановить стрим" if active else "▶️ Запустить стрим"
        switch_area_text = "🔎 Переключить область на окно игры" if area == "Чат" else "🔎 Переключить область на Чат"
        keyboard = [
            [{"text": f"⚙️ Качество: {quality}", "callback_data": "menu:stream_quality"}],
            [{"text": start_stop_text, "callback_data": "stream:start_stop"}],
        ]
        if active:
            keyboard.append([{"text": "🔗 Открыть стрим", "callback_data": "stream:open"}])
            keyboard.append([{"text": switch_area_text, "callback_data": "stream:switch_area"}])
        keyboard.append([{"text": "⬅️ Меню", "callback_data": "menu:main"}])
        self._send_or_edit_message(text, chat_id=chat_id, message_id=message_id, reply_markup={"inline_keyboard": keyboard})

    def _send_stream_quality(self, chat_id: int, *, message_id: int | None = None) -> None:
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
        items = [
            ("notify_catch", "Поймана рыба"),
            ("notify_start_stop", "Запуск/Остановка"),
            ("notify_meal", "Питание"),
            ("notify_inventory_full", "Закончилось место"),
        ]
        items.append(("notify_focus_lost", "Потеря фокуса игры"))
        keyboard = []
        for index in range(0, len(items), 2):
            row = []
            for field_name, label in items[index : index + 2]:
                enabled = bool(getattr(self.settings, field_name))
                icon = "🔔" if enabled else "🔕"
                row.append({"text": f"{icon} {label}", "callback_data": f"toggle:{field_name}"})
            keyboard.append(row)
        keyboard.append([{"text": "⬅️ Меню", "callback_data": "menu:main"}])
        self._send_or_edit_message("🔔 Уведомления", chat_id=chat_id, message_id=message_id, reply_markup={"inline_keyboard": keyboard})

    def _send_stats(self, chat_id: int) -> None:
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

    def _toggle_notification(self, field_name: str) -> None:
        if field_name not in {
            "notify_catch",
            "notify_start_stop",
            "notify_meal",
            "notify_inventory_full",
            "notify_focus_lost",
        }:
            return
        setattr(self.settings, field_name, not bool(getattr(self.settings, field_name)))
        if self.settings_changed_callback:
            self.settings_changed_callback(self.settings)

    def _toggle_fishing(self, chat_id: int) -> None:
        if self._is_running():
            if self.stop_callback:
                self.stop_callback()
            self.send_message("🛑 Рыбалка остановлена", chat_id=chat_id)
        else:
            ok = self.start_callback() if self.start_callback else False
            self.send_message("🚤 Рыбалка запущена" if ok else "⚠️ Не удалось запустить рыбалку", chat_id=chat_id)

    def _toggle_stream(self, chat_id: int, *, message_id: int | None = None) -> None:
        snapshot = self._stream_snapshot()
        if bool(getattr(snapshot, "active", False)):
            if self.stream_stop_callback is not None:
                self.stream_stop_callback()
            self._send_stream_menu(chat_id, message_id=message_id)
            return
        ok = self.stream_start_callback() if self.stream_start_callback is not None else False
        if not ok:
            self.send_message("⚠️ Не удалось запустить стрим. Проверьте вкладку стрима в программе.", chat_id=chat_id)
        self._send_stream_menu(chat_id, message_id=message_id)

    def _send_stream_link(self, chat_id: int) -> None:
        snapshot = self._stream_snapshot()
        if not bool(getattr(snapshot, "active", False)):
            self.send_message("📴 Стрим сейчас выключен.", chat_id=chat_id)
            return
        url = str(getattr(snapshot, "stream_url", "") or "")
        if not url:
            self.send_message("⚠️ Ссылка на стрим ещё не готова.", chat_id=chat_id)
            return
        self.send_message(f"🖥 Трансляция:\n{url}", chat_id=chat_id)

    def _set_stream_quality(self, quality: str, chat_id: int, *, message_id: int | None = None) -> None:
        ok = self.stream_set_quality_callback(quality) if self.stream_set_quality_callback is not None else False
        if not ok:
            self.send_message("⚠️ Не удалось изменить качество стрима.", chat_id=chat_id)
        self._send_stream_menu(chat_id, message_id=message_id)

    def _switch_stream_area(self, chat_id: int, *, message_id: int | None = None) -> None:
        snapshot = self._stream_snapshot()
        next_chat_zoom = getattr(snapshot, "area", "full") != "chat"
        ok = self.stream_set_chat_zoom_callback(next_chat_zoom) if self.stream_set_chat_zoom_callback is not None else False
        if not ok:
            self.send_message("⚠️ Не удалось переключить область стрима.", chat_id=chat_id)
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
        payload: dict[str, Any] = {"chat_id": chat_id, "message_id": message_id, "text": text}
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
        return f"https://api.telegram.org/bot{self.settings.bot_token}/{method}"

    def _api_post(self, method: str, **kwargs) -> requests.Response | None:
        if not self.settings.bot_token:
            return None
        try:
            return requests.post(self._api_url(method), timeout=self.timeout, **kwargs)
        except requests.RequestException:
            return None

    @staticmethod
    def _format_catch_message(
        fish_name: str,
        weight_kg: float | None,
        quality_text: str | None,
        xp_current: int | None,
        xp_total: int | None,
        totals: SessionTotals,
    ) -> str:
        trophy = quality_text and any(marker in quality_text.lower() for marker in ("троф", "рекорд"))
        lines = []
        if trophy:
            lines.append("🏆 Трофейный улов!")
            lines.append("")
        lines.append(f"🐟 {fish_name} — {format_weight(weight_kg or 0.0)}")
        lines.append("")
        lines.append(f"📦 Всего: {format_weight(totals.caught_kg)} · {totals.caught_count} выловов")
        lines.append(f"💰 Доход: {format_money_range(totals.earned_min, totals.earned_max)}")
        if xp_current is not None and xp_total is not None:
            lines.append(f"⭐ Опыт: {xp_current} / {xp_total}")
        elif xp_current is not None:
            lines.append(f"⭐ Опыт: {xp_current}")
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
            title,
            "",
            subtitle,
            "",
        ]
        if reason:
            lines.extend([f"Причина остановки: {reason}", ""])
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
                        f"• {stat.name}",
                        f"  🎣 Поймано: {format_catch_summary(stat.caught_count, stat.caught_kg)}",
                        f"  🌊 Отпущено: {format_catch_summary(stat.released_count, stat.released_kg)}",
                        f"  💰 Доход: {format_money_range(row.earned_min, row.earned_max)}",
                        "",
                    ]
                )
            while lines and lines[-1] == "":
                lines.pop()
        return "\n".join(lines)
