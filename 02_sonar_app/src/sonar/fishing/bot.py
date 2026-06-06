from __future__ import annotations

import csv
import io
import json
import os
import random
import shutil
import sys
import threading
import time
from dataclasses import dataclass, field, replace
from datetime import datetime, timezone
from pathlib import Path
from typing import Callable

import cv2
import numpy as np
import psutil
from PIL import Image

from sonar.automation.input_controller import InputController
from sonar.automation.window import WindowActivator
from sonar.config.manager import ConfigManager
from sonar.config.models import FishingSettings, TelegramSettings
from sonar.core.log_crypto import decrypt_log_payload, encrypt_log_payload
from sonar.core.logging import CallbackLogger, LogCallback, debug_log
from sonar.core.sounds import play_sound
from sonar.core.events import UiEventMessage, event_bus
from sonar.core.state import BotPhase, BotState
from sonar.fishing.catch_screen import CatchScreenDetector, CatchScreenResult
from sonar.fishing.constants import (
    BOT_DELAYS,
    PROCESS_NAME,
    casting_roi_for_resolution,
    frame_scale,
    hooking_rois_for_resolution,
    resolution_name,
    template_scales_for_frame,
)
from sonar.fishing.casting_a_fishing_rod import GreenPixelMonitor, create_monitor_for_frame as create_casting_monitor
from sonar.fishing.fish_names import fish_display_name, fish_id_from_display
from sonar.fishing.garbage_disposal import GarbageDisposal
from sonar.fishing.game_menu import GameMenuDetector
from sonar.fishing.inventory_memory import InventoryMemoryDetector
from sonar.fishing.hooking import TemplateMonitor, create_monitor_for_frame as create_hooking_monitor
from sonar.fishing.inventory_stage import InventoryStageDetector
from sonar.fishing.meal_system import MealItemSnapshot, MealSystem
from sonar.fishing.memory_reeling import MemoryReelingTracker
from sonar.fishing.player_status import PlayerStatus, PlayerStatusEstimate
from sonar.fishing.statistics import FishingSessionStats, format_money_range, format_weight, parse_fish_prices_from_markdown
from sonar.fishing.store_fish import FishStorer
from sonar.fishing.tackle_detection import TackleDetector, TackleScanResult, format_tackle_items
from sonar.fishing.trigger_monitor import TriggerMonitor
from sonar.telegram.notifier import NotificationManager
from sonar.paths import APP_DIR, IS_FROZEN, LOG_DIR, LOGS_ENABLED
from sonar.vision.capture import WindowCapture
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


DEBUG_CAPTURE_ALLOWED_FISH_IDS = frozenset({"seriola", "ruster", "marlin", "krasny_gorbyl"})
DEBUG_CAPTURE_ROOT_DIR = APP_DIR / "debug_capture"
DEBUG_CAPTURE_UNEXPECTED_FISH_DIR = DEBUG_CAPTURE_ROOT_DIR / "fish_identification_screen_screenshots"
DEBUG_CAPTURE_OVER_15KG_DIR = DEBUG_CAPTURE_ROOT_DIR / "over_15kg_fish_screenshots"
DEBUG_CAPTURE_TROPHY_DIR = DEBUG_CAPTURE_ROOT_DIR / "trophy_fish_screenshots"
DEBUG_CAPTURE_ALL_CATCHES_DIR = DEBUG_CAPTURE_ROOT_DIR / "all_caught_fish_session_screenshots"
DEBUG_CAPTURE_MEAL_DIR = DEBUG_CAPTURE_ROOT_DIR / "eaten_item_info_screenshots"
DEBUG_CAPTURE_REELING_LOSS_DIR = DEBUG_CAPTURE_ROOT_DIR / "reeling_loss_logs"
DEBUG_CAPTURE_CSV_NAME = "metadata.csv"
DEBUG_CAPTURE_WEIGHT_THRESHOLD_KG = 15.0
START_STOP_SOUND_VOLUME = 0.3
AUTO_STOP_TIMEOUT_SECONDS = 40.0
AUTO_STOP_SCREENSHOT_DELAY_SECONDS = 5.0
STOP_REASON_MANUAL = "вручную"
STOP_REASON_START_FAILED = "не смог начать рыбалку в течение 40 секунд"
STOP_REASON_NO_STAGE = "не в зоне рыбалки или не видно стадии рыбалки 40 секунд"
STOP_REASON_WALKING_GUARD = "Сработала защита от ходьбы"
STOP_REASON_TACKLE_UNREADABLE = "Не удалось прочитать снаряжение"
STOP_REASON_OVERWEIGHT = "перевес инвентаря"
AUTO_STOP_SCREENSHOT_REASONS = frozenset({STOP_REASON_NO_STAGE, STOP_REASON_START_FAILED})
REELING_LOSS_RELEASE_LOG_KEY = "sonar"
REELING_LOSS_RELEASE_LOG_GLOB = "reeling_loss_*.jsonl.enc"
REELING_LOSS_RELEASE_LOG_LIMIT = 15
REEL_CATCH_SCREEN_TIMEOUT_SECONDS = 3.0
CATCH_SCREEN_CURRENT_TIMEOUT_SECONDS = 1.2
CATCH_SCREEN_POLL_SECONDS = 0.05
MEAL_ANIMATION_WAIT_SECONDS = 6.0
MEAL_POST_USE_HUD_CHECK_TIMEOUT_SECONDS = 6.0
MEAL_MISSING_HUD_CHECK_TIMEOUT_SECONDS = 2.0
MEAL_HUD_CHECK_POLL_SECONDS = 0.5
MEAL_CLEAR_CONFIRM_POLLS = 2
MEAL_BACKPACK_MOVE_MAX_ATTEMPTS = 5
MEAL_MISSING_RETRY_SECONDS = 45.0
MEAL_STATUS_MAX_AGE_SECONDS = 15.0
MEAL_STATUS_THRESHOLD_TOLERANCE = 2
PREPARE_START_POLL_SECONDS = 0.05
RANDOM_DELAY_JITTER_SECONDS = 0.6
TACKLE_ACTION_DELAY_SECONDS = 0.5
CAST_GREEN_DETECTION_DELAY_SECONDS = 1.0
FOCUS_STATE_CHECK_INTERVAL_SECONDS = 0.5
CHAT_STAGE_EXIT_TIMEOUT_SECONDS = 18.0
CHAT_STAGE_EXIT_POLL_SECONDS = 0.12
CHAT_STAGE_EXIT_ESC_INTERVAL_SECONDS = 0.65
REELING_WALKING_GUARD_INTERVAL_SECONDS = 0.5
REELING_IDLE_RETURN_TIMEOUT_SECONDS = 2.0
REELING_IDLE_RETURN_POLL_SECONDS = 0.1
REELING_STAGE_CHECK_INTERVAL_SECONDS = 0.35
REELING_ACTION_LOG_INTERVAL_SECONDS = 1.0
REELING_ACTION_CHANGE_LOG_INTERVAL_SECONDS = 0.08
REELING_FOCUS_RETRY_SECONDS = 1.0
POST_HOOK_STAGE_CONFIRM_TIMEOUT_SECONDS = 3.0
POST_HOOK_STAGE_POLL_SECONDS = 0.08
START_MENU_OPEN_DELAY_SECONDS = 0.65
FISHING_ENTRY_MIN_INTERVAL_SECONDS = 1.5
STORAGE_SELECTION_RETRY_SECONDS = 0.75
STORAGE_SELECTION_GIVE_UP_SECONDS = 3.0
STORAGE_SELECTION_CLICK_PAUSE_SECONDS = 0.58
STORAGE_SELECTION_BOAT_UNCONFIRMED_ATTEMPTS = 1
CAST_CONTROL_POLL_SECONDS = 0.001
TACKLE_OBSCURED_INITIAL_WAIT_SECONDS = 6.0
TACKLE_OBSCURED_RETRY_WAIT_SECONDS = 2.0
TACKLE_OBSCURED_RETRIES = 3
TACKLE_DEPLETION_CONFIRM_DELAY_SECONDS = 0.5
TACKLE_DEPLETION_CONFIRM_ATTEMPTS = 2
TACKLE_ACTIVE_STAGE_SCAN_INTERVAL_SECONDS = 6.0
INVENTORY_OPEN_PAUSE_SECONDS = 1.0
INVENTORY_STAGE_EXIT_SETTLE_SECONDS = 2.3
INVENTORY_OPEN_RETRY_DELAY_SECONDS = 0.5
INVENTORY_OPEN_CONFIRM_TIMEOUT_SECONDS = 4.0
INVENTORY_CLOSE_PAUSE_SECONDS = 1.5
REELING_PROBLEM_ACTIONS = frozenset({"target_search", "position_unreadable", "memory_unavailable", "control_error"})
REELING_KNOWN_INTERRUPTION_TRIGGERS = frozenset(
    {
        "ad",
        "start2",
        "wait_tension",
        "start1",
        "start",
        "changed_bait",
        "gear",
        "pereves",
        "thirst",
        "hunger",
    }
)
FISHING_STAGE_TRIGGER_NAMES = ("ad", "start2", "wait_tension", "start1", "start")
PREPARE_START_TRIGGER_NAMES = ("ad", "start2", "wait_tension", "start1", "start")
PREPARE_START_CONTEXT_TRIGGER_NAMES = ("boat", "human", "changed_bait", "gear")
SECONDARY_TRIGGER_NAMES = ("pereves", "changed_bait", "gear", "thirst", "hunger")
HOOKING_STAGE_TRIGGER_NAMES = ("start2", "wait_tension")
HOOKING_MEAL_TRIGGER_NAMES = ("thirst", "hunger")
SECONDARY_TRIGGER_REFRESH_SECONDS = 1.0
HOOKING_STAGE_CHECK_INTERVAL_SECONDS = 0.75
HOOKING_STAGE_GRACE_SECONDS = 1.5


def encrypt_reeling_loss_log(plaintext: bytes, *, key: str = REELING_LOSS_RELEASE_LOG_KEY) -> bytes:
    return encrypt_log_payload(plaintext, key=key)


def decrypt_reeling_loss_log(payload: bytes, *, key: str = REELING_LOSS_RELEASE_LOG_KEY) -> bytes:
    return decrypt_log_payload(payload, key=key)


@dataclass
class FishingBot:
    log_callback: LogCallback | None = None
    config_manager: ConfigManager = field(default_factory=ConfigManager)
    input_controller: InputController = field(default_factory=InputController)
    notification_manager: NotificationManager = field(default_factory=NotificationManager)
    can_start_callback: Callable[[], bool] | None = None
    start_command_callback: Callable[[], bool] | None = None
    telegram_runtime_enabled_callback: Callable[[], bool] | None = None
    telegram_settings_changed_callback: Callable[[TelegramSettings], None] | None = None
    player_status_callback: Callable[[PlayerStatus | None], None] | None = None
    fishing_runtime_enabled_callback: Callable[[], bool] | None = None
    stats_runtime_enabled_callback: Callable[[], bool] | None = None
    tackle_runtime_enabled_callback: Callable[[], bool] | None = None
    stream_runtime_enabled_callback: Callable[[], bool] | None = None
    stream_status_callback: Callable[[], object] | None = None
    stream_start_callback: Callable[[], bool] | None = None
    stream_stop_callback: Callable[[], None] | None = None
    stream_set_quality_callback: Callable[[str], bool] | None = None
    stream_set_chat_zoom_callback: Callable[[bool], bool] | None = None
    stream_set_snapshot_mode_callback: Callable[[bool], bool] | None = None
    session_stats: FishingSessionStats = field(
        default_factory=lambda: FishingSessionStats(default_prices=parse_fish_prices_from_markdown())
    )
    process_name: str = PROCESS_NAME
    keep_debug_capture: bool = False
    manual_reeling_mode: bool = False
    state: BotState = field(default_factory=BotState)

    def __post_init__(self) -> None:
        self.logger = CallbackLogger(self.log_callback)
        self.capture = WindowCapture(self.process_name)
        self.window_activator = WindowActivator(self.process_name)
        self.trigger_monitor = TriggerMonitor()
        self.catch_detector = CatchScreenDetector()
        self.game_menu_detector = GameMenuDetector()
        self.inventory_detector = InventoryStageDetector()
        self.inventory_memory_detector = InventoryMemoryDetector(self.process_name)
        self.garbage_disposal = GarbageDisposal(self.process_name, input_controller=self.input_controller)
        self.meal_system = MealSystem(self.process_name, input_controller=self.input_controller)
        self.fish_storer = FishStorer(self.process_name, input_controller=self.input_controller)
        self.reeling_tracker = MemoryReelingTracker(self.process_name, input_controller=self.input_controller, log_callback=self._log)
        self.tackle_detector = TackleDetector()
        self.casting_monitor: GreenPixelMonitor | None = None
        self.hooking_monitor: TemplateMonitor | None = None
        self._stop_event = threading.Event()
        self._input_enabled_event = threading.Event()
        self._input_enabled_event.set()
        self.input_controller.input_allowed_callback = self._is_fishing_input_allowed
        self._chat_pause_event = threading.Event()
        self._brain_thread: threading.Thread | None = None
        self._stop_state_lock = threading.Lock()
        self._stop_cleanup_lock = threading.Lock()
        self._last_triggers: dict[str, float] = {}
        self._last_trigger_matches: dict[str, TemplateMatch] = {}
        self._last_secondary_trigger_at = 0.0
        self._kickstart_requested = False
        self._last_focus_at = 0.0
        self._last_focus_state_check_at = 0.0
        self._focus_lost_notified = False
        self._last_start2_handled_at = 0.0
        self._last_start_pressed_at = 0.0
        self._last_fishing_entry_pressed_at = 0.0
        self._last_catch_result: CatchScreenResult | None = None
        self._last_stage_label = ""
        self._last_catch_snapshot_at = 0.0
        self._last_catch_probe_at = 0.0
        self._last_menu_close_at = 0.0
        self._last_change_bait_at = 0.0
        self._no_stage_since: float | None = None
        self._start_attempt_since: float | None = None
        self._inventory_retry_after = 0.0
        self._inventory_tasks_retry_pending = False
        self._meal_search_disabled_until_restart = False
        self._last_player_status: PlayerStatus | None = None
        self._last_player_status_at = 0.0
        self._player_status_estimate = PlayerStatusEstimate()
        self._last_published_estimated_status: PlayerStatus | None = None
        self._initial_status_scan_pending = False
        self._last_confirmed_storage = ""
        self._player_storage_fallback_active = False
        self._storage_boat_unconfirmed_attempts = 0
        self._inventory_space_low_notified = False
        self._player_status_scan_requested = False
        self._active_tackle_scanned_stages: set[str] = set()
        self._session_started_with_net: bool | None = None
        self.inventory_full = False
        self.settings: FishingSettings = self.config_manager.load().fishing
        self.reeling_tracker.configure_manual_mode(self.manual_reeling_mode)
        self._configure_notifications()
        debug_log("FishingBot initialized")

    def reload_settings(self) -> None:
        settings = self.config_manager.load()
        self.settings = settings.fishing
        self.reeling_tracker.configure_manual_mode(self.manual_reeling_mode)
        self.session_stats.default_prices = parse_fish_prices_from_markdown()
        self.session_stats.set_custom_prices(self.settings.custom_fish_prices)
        self._configure_notifications()
        self._log("Settings reloaded")

    def detect_player_status(self, *, allow_screenshot_fallback: bool = False) -> PlayerStatus | None:
        frame = None
        if allow_screenshot_fallback:
            try:
                frame = self.capture.capture()
            except Exception:
                frame = None
        status = self.meal_system.detect_player_status(frame, allow_screenshot_fallback=allow_screenshot_fallback)
        self._remember_player_status(status)
        estimated = self.estimated_player_status() or status
        self._publish_player_status(estimated)
        self._sync_next_meal_check_from_status(estimated, log=False)
        return estimated

    def estimated_player_status(self) -> PlayerStatus | None:
        return self._player_status_estimate.estimate()

    def is_stopping(self) -> bool:
        thread = getattr(self, "_brain_thread", None)
        return self.state.phase == BotPhase.STOPPING or (
            thread is not None and thread.is_alive() and not self.state.running
        )

    def request_player_status_scan(self) -> tuple[bool, str]:
        if not self.state.running:
            return False, "Сканирование через инвентарь доступно во время работы бота"
        if self.state.phase == BotPhase.REELING or self.state.detected_stage == "Вываживание" or "ad" in getattr(self, "_last_triggers", {}):
            self._player_status_scan_requested = True
            self._log("Показатели: ручное сканирование добавлено в очередь после вываживания")
            return True, "Подождите немного: сканирование показателей поставлено в очередь и будет выполнено после вываживания"
        if self._has_pending_catch():
            return False, "Сначала нужно обработать экран улова"
        self._player_status_scan_requested = True
        self._log("Показатели: ручное сканирование добавлено в очередь")
        return True, "Сканирование показателей добавлено в очередь"

    def _configure_notifications(self) -> None:
        settings = self.config_manager.load()
        self.notification_manager.configure(
            settings.telegram,
            runtime_enabled=self.telegram_runtime_enabled_callback() if self.telegram_runtime_enabled_callback else True,
            start_callback=self.start_command_callback or self.start,
            stop_callback=self.stop,
            is_running_callback=lambda: self.state.running,
            stats_callback=self.session_stats.totals,
            stats_rows_callback=self.session_stats.rows,
            has_stats_callback=self.session_stats.has_catches,
            tackle_callback=self.session_stats.tackle_items,
            tackle_image_callback=self.session_stats.tackle_image_bytes,
            tackle_scanned_at_callback=self.session_stats.tackle_scanned_at,
            screenshot_callback=self._capture_screenshot_bytes,
            focus_game_callback=self._force_focus_game,
            shutdown_game_callback=self._shutdown_game,
            shutdown_pc_callback=self._shutdown_pc,
            settings_changed_callback=self._save_telegram_settings,
            stream_status_callback=self.stream_status_callback,
            stream_start_callback=self.stream_start_callback,
            stream_stop_callback=self.stream_stop_callback,
            stream_set_quality_callback=self.stream_set_quality_callback,
            stream_set_chat_zoom_callback=self.stream_set_chat_zoom_callback,
            stream_set_snapshot_mode_callback=self.stream_set_snapshot_mode_callback,
            fishing_runtime_enabled_callback=self.fishing_runtime_enabled_callback,
            stats_runtime_enabled_callback=self.stats_runtime_enabled_callback,
            tackle_runtime_enabled_callback=self.tackle_runtime_enabled_callback,
            stream_runtime_enabled_callback=self.stream_runtime_enabled_callback,
            player_status_callback=self.estimated_player_status,
            player_status_scan_callback=self.request_player_status_scan,
        )

    def configure_streaming_callbacks(
        self,
        *,
        status_callback: Callable[[], object] | None = None,
        start_callback: Callable[[], bool] | None = None,
        stop_callback: Callable[[], None] | None = None,
        set_quality_callback: Callable[[str], bool] | None = None,
        set_chat_zoom_callback: Callable[[bool], bool] | None = None,
        set_snapshot_mode_callback: Callable[[bool], bool] | None = None,
        stream_runtime_enabled_callback: Callable[[], bool] | None = None,
    ) -> None:
        self.stream_status_callback = status_callback
        self.stream_start_callback = start_callback
        self.stream_stop_callback = stop_callback
        self.stream_set_quality_callback = set_quality_callback
        self.stream_set_chat_zoom_callback = set_chat_zoom_callback
        self.stream_set_snapshot_mode_callback = set_snapshot_mode_callback
        self.stream_runtime_enabled_callback = stream_runtime_enabled_callback
        self._configure_notifications()

    def _save_telegram_settings(self, telegram_settings) -> None:
        settings = self.config_manager.load()
        settings.telegram = telegram_settings
        self.config_manager.save(settings)
        self.settings = settings.fishing
        if self.telegram_settings_changed_callback:
            self.telegram_settings_changed_callback(telegram_settings)

    def start(self, *, skip_license_check: bool = False) -> bool:
        if self.state.running:
            return True
        if self.is_stopping():
            self.state.last_error = "Bot is still stopping"
            self._log(self.state.last_error)
            return False
        if not skip_license_check and self.can_start_callback and not self.can_start_callback():
            self.state.last_error = "License is not active"
            self._log(self.state.last_error)
            return False
        self.reload_settings()
        if not self.capture.find_window_by_process():
            self.state.last_error = f"{self.process_name} window was not found"
            self._log(self.state.last_error)
            return False
        self._clear_debug_capture_for_new_session()
        self._focus_game()
        self._stop_event.clear()
        self._input_enabled_event.set()
        self._chat_pause_event.clear()
        self.state.running = True
        self.state.phase = BotPhase.IDLE
        self.state.detected_stage = "Свободно"
        self.inventory_full = False
        self._inventory_retry_after = 0.0
        self._inventory_tasks_retry_pending = False
        self._meal_search_disabled_until_restart = False
        self._initial_status_scan_pending = self.settings.auto_meal
        self._player_status_estimate = PlayerStatusEstimate()
        self._last_published_estimated_status = None
        self._last_confirmed_storage = ""
        self._player_storage_fallback_active = False
        self._storage_boat_unconfirmed_attempts = 0
        self._inventory_space_low_notified = False
        self._player_status_scan_requested = False
        self._active_tackle_scanned_stages = set()
        self._session_started_with_net = None
        self._last_catch_result = None
        self._no_stage_since = None
        self._start_attempt_since = None
        self._last_fishing_entry_pressed_at = 0.0
        self._last_focus_state_check_at = 0.0
        self._focus_lost_notified = False
        self.session_stats.clear_tackle_scan()
        self.session_stats.start_timer()
        self._brain_thread = threading.Thread(target=self._brain_loop, name="sonar-brain", daemon=True)
        self._brain_thread.start()
        self._kickstart_requested = True
        self._log("Fishing bot started")
        self._publish_ui_event("Рыбалка запущена", event_type="success", icon="play.svg")
        if self.settings.start_stop_sound_enabled:
            play_sound("bot_start.wav", volume=START_STOP_SOUND_VOLUME)
        self.notification_manager.notify_fishing_started(self.session_stats.totals(), self.session_stats.has_catches())
        return True

    def stop(self, reason: str = STOP_REASON_MANUAL) -> None:
        was_running = self._begin_stop()
        self._finish_stop(was_running, reason)
        if self._brain_thread and self._brain_thread.is_alive() and threading.current_thread() is not self._brain_thread:
            threading.Thread(target=self._join_brain_thread, name="sonar-brain-stop", daemon=True).start()

    def stop_async(self, reason: str = STOP_REASON_MANUAL) -> None:
        was_running = self._begin_stop()
        if not was_running:
            return
        threading.Thread(
            target=self._finish_stop_and_join,
            args=(was_running, reason),
            name="sonar-stop-cleanup",
            daemon=True,
        ).start()

    def _stop_from_brain(self, reason: str) -> None:
        was_running = self._begin_stop()
        self._finish_stop(was_running, reason, capture_auto_stop_screenshot=was_running)

    def _begin_stop(self) -> bool:
        lock = getattr(self, "_stop_state_lock", None)
        if lock is None:
            lock = threading.Lock()
            self._stop_state_lock = lock
        with lock:
            was_running = self.state.running
            self.state.phase = BotPhase.STOPPING
            input_enabled_event = getattr(self, "_input_enabled_event", None)
            if input_enabled_event is not None:
                input_enabled_event.clear()
            self._stop_event.set()
            self.state.running = False
            return was_running

    def _finish_stop_and_join(self, was_running: bool, reason: str) -> None:
        try:
            self._finish_stop(was_running, reason)
        finally:
            self._join_brain_thread()

    def _finish_stop(
        self,
        was_running: bool,
        reason: str,
        *,
        auto_stop_screenshot: bytes | None = None,
        capture_auto_stop_screenshot: bool = False,
    ) -> None:
        cleanup_lock = getattr(self, "_stop_cleanup_lock", None)
        if cleanup_lock is None:
            cleanup_lock = threading.Lock()
            self._stop_cleanup_lock = cleanup_lock
        with cleanup_lock:
            self._finish_stop_locked(
                was_running,
                reason,
                auto_stop_screenshot=auto_stop_screenshot,
                capture_auto_stop_screenshot=capture_auto_stop_screenshot,
            )

    def _finish_stop_locked(
        self,
        was_running: bool,
        reason: str,
        *,
        auto_stop_screenshot: bytes | None = None,
        capture_auto_stop_screenshot: bool = False,
    ) -> None:
        if hasattr(self, "_chat_pause_event"):
            self._chat_pause_event.clear()
        self._run_stop_step("reeling tracker", self.reeling_tracker.stop)
        self._run_stop_step("inventory detector", self.inventory_memory_detector.close)
        self._run_stop_step("meal status detector", lambda: self.meal_system.status_memory_detector.close())
        self._run_stop_step("input keys", self.input_controller.release_all_keys)
        self.state.running = False
        self.state.phase = BotPhase.IDLE
        self.state.detected_stage = "Свободно"
        self.inventory_full = False
        self._player_storage_fallback_active = False
        self._storage_boat_unconfirmed_attempts = 0
        self._last_catch_result = None
        self._no_stage_since = None
        self._start_attempt_since = None
        self._focus_lost_notified = False
        self._player_status_scan_requested = False
        if was_running:
            self._run_stop_step("session timer", self.session_stats.stop_timer)
        self._log(f"Fishing bot stopped: {reason}")
        if was_running:
            self._run_stop_step(
                "UI event",
                lambda: self._publish_ui_event("Рыбалка остановлена", event_type="warning", icon="stop.svg", detail=reason),
            )
        if was_running:
            if self.settings.start_stop_sound_enabled:
                self._run_stop_step("stop sound", lambda: play_sound("bot_stop.wav", volume=START_STOP_SOUND_VOLUME))
            totals = self._run_stop_step("session totals", self.session_stats.totals)
            if capture_auto_stop_screenshot:
                auto_stop_screenshot = self._run_stop_step(
                    "auto-stop screenshot",
                    lambda: self._capture_auto_stop_screenshot(reason),
                )
            if totals is not None:
                self._run_stop_step(
                    "stop notification",
                    lambda: self.notification_manager.notify_fishing_stopped(
                        totals,
                        reason=reason,
                        image_bytes=auto_stop_screenshot,
                    ),
                )

    def _run_stop_step(self, name: str, callback: Callable[[], object]) -> object | None:
        try:
            return callback()
        except Exception as exc:
            debug_log(f"BOT_STOP_CLEANUP_FAILED step={name} error={exc}")
            try:
                self._log(f"Ошибка очистки при остановке ({name}): {exc}")
            except Exception:
                pass
            return None

    def _capture_auto_stop_screenshot(self, reason: str) -> bytes | None:
        if reason not in AUTO_STOP_SCREENSHOT_REASONS:
            return None
        try:
            self._wait_before_auto_stop_screenshot()
            return self._capture_screenshot_bytes()
        except Exception as exc:
            debug_log(f"AUTO_STOP_SCREENSHOT_FAILED reason={reason} error={exc}")
            self._log(f"Автостоп: не удалось сделать скриншот после остановки: {exc}")
            return None

    def _wait_before_auto_stop_screenshot(self) -> None:
        delay = max(0.0, AUTO_STOP_SCREENSHOT_DELAY_SECONDS)
        deadline = time.time() + delay
        while time.time() < deadline:
            time.sleep(min(0.05, deadline - time.time()))

    def pause_for_chat(self, enabled: bool, *, restart_on_resume: bool = True) -> None:
        if not hasattr(self, "_chat_pause_event"):
            self._chat_pause_event = threading.Event()
        enabled = bool(enabled)
        if enabled:
            if not self._chat_pause_event.is_set():
                self.input_controller.release_all_keys()
                self.state.detected_stage = "Чат"
                self._log("Рыбалка приостановлена для режима чата")
            self._chat_pause_event.set()
            return
        if self._chat_pause_event.is_set():
            self._no_stage_since = None
            if restart_on_resume and self.state.running:
                self._kickstart_requested = True
            self._chat_pause_event.clear()
            self._log("Рыбалка продолжена после режима чата")

    def is_paused_for_chat(self) -> bool:
        return hasattr(self, "_chat_pause_event") and self._chat_pause_event.is_set()

    def prepare_for_chat_mode(self, timeout: float = CHAT_STAGE_EXIT_TIMEOUT_SECONDS) -> tuple[bool, str]:
        self._focus_game()
        self.input_controller.release_all_keys()
        self._publish_stage("Выход в чат")
        deadline = time.time() + timeout
        next_esc_at = 0.0
        last_stage_label = ""
        while time.time() < deadline and not self._chat_stage_exit_cancelled():
            frame = None
            try:
                frame = self.capture.capture()
            except Exception as exc:
                self._log(f"Режим чата: не удалось получить кадр для выхода из рыбалки: {exc}")

            if frame is not None and self._close_game_menu_if_open(frame):
                self._chat_mode_sleep(0.2)
                continue
            if frame is not None and self._close_inventory_for_chat(frame):
                self._chat_mode_sleep(0.4)
                continue
            if frame is not None and self._dismiss_catch_screen_for_chat(frame):
                self._chat_mode_sleep(0.35)
                continue

            if frame is not None:
                self._remember_trigger_matches(self.trigger_monitor.find_detections(frame, names=FISHING_STAGE_TRIGGER_NAMES))
            else:
                self._refresh_triggers(names=FISHING_STAGE_TRIGGER_NAMES)
            stage = self._detect_stage(self._last_triggers)
            if stage is None:
                self._publish_stage("Свободно")
                return True, "Персонаж выведен из рыбалки"

            stage_label = self._stage_label(stage)
            if stage_label != last_stage_label:
                last_stage_label = stage_label
                self._log(f"Режим чата: выхожу из стадии «{stage_label}»")
            if time.time() >= next_esc_at:
                self.input_controller.press_key("esc")
                self._log("Режим чата: нажата Esc для выхода из рыбалки")
                next_esc_at = time.time() + CHAT_STAGE_EXIT_ESC_INTERVAL_SECONDS
            self._chat_mode_sleep(CHAT_STAGE_EXIT_POLL_SECONDS)

        if self._chat_stage_exit_cancelled():
            return False, "Выход в чат отменён остановкой бота"
        return False, "Не удалось вывести персонажа из рыбалки"

    def _chat_stage_exit_cancelled(self) -> bool:
        return self.state.running and self._stop_event.is_set()

    def _chat_mode_sleep(self, seconds: float) -> None:
        end = time.time() + seconds
        while time.time() < end and not self._chat_stage_exit_cancelled():
            time.sleep(min(0.05, max(0.0, end - time.time())))

    def _close_inventory_for_chat(self, frame) -> bool:
        try:
            if not self.inventory_detector.is_open(frame):
                return False
        except Exception as exc:
            debug_log(f"CHAT_INVENTORY_DETECT_FAILED {exc}")
            return False
        self.input_controller.press_key(self.settings.inventory_hotkey)
        self._log(f"Режим чата: закрываю инвентарь клавишей {self.settings.inventory_hotkey}")
        self._chat_mode_sleep(INVENTORY_CLOSE_PAUSE_SECONDS)
        return True

    def _dismiss_catch_screen_for_chat(self, frame) -> bool:
        try:
            result = self.catch_detector.detect(frame)
        except Exception as exc:
            debug_log(f"CHAT_CATCH_DETECT_FAILED {exc}")
            return False
        if not result.visible:
            return False
        self._last_catch_result = result
        self._log("Режим чата: закрываю экран улова перед открытием чата")
        self._do_fish_catch()
        return True

    def _join_brain_thread(self) -> None:
        if self._brain_thread and self._brain_thread.is_alive():
            self._brain_thread.join(timeout=2.0)

    def _clear_debug_capture_for_new_session(self) -> None:
        if self.keep_debug_capture:
            return
        try:
            if DEBUG_CAPTURE_ROOT_DIR.exists():
                for child in DEBUG_CAPTURE_ROOT_DIR.iterdir():
                    if child.is_dir() and not child.is_symlink():
                        shutil.rmtree(child)
                    else:
                        child.unlink()
            DEBUG_CAPTURE_ROOT_DIR.mkdir(parents=True, exist_ok=True)
            debug_log(f"DEBUG_CAPTURE_CLEARED path={DEBUG_CAPTURE_ROOT_DIR}")
        except Exception as exc:
            debug_log(f"DEBUG_CAPTURE_CLEAR_FAILED {exc}")

    def _update_focus_state_notification(self) -> None:
        now = time.time()
        if now - getattr(self, "_last_focus_state_check_at", 0.0) < FOCUS_STATE_CHECK_INTERVAL_SECONDS:
            return
        self._last_focus_state_check_at = now
        if self._is_game_foreground():
            self._focus_lost_notified = False
            return
        if getattr(self, "_focus_lost_notified", False):
            return
        self._focus_lost_notified = True
        threading.Thread(target=self.notification_manager.notify_focus_lost, name="sonar-focus-lost-notify", daemon=True).start()

    def _get_triggers(self) -> dict[str, float]:
        try:
            frame = self.capture.capture()
            self._remember_trigger_matches(self.trigger_monitor.find_detections(frame, names=FISHING_STAGE_TRIGGER_NAMES))
            now = time.time()
            if now - getattr(self, "_last_secondary_trigger_at", 0.0) >= SECONDARY_TRIGGER_REFRESH_SECONDS:
                secondary_matches = self.trigger_monitor.find_detections(frame, names=SECONDARY_TRIGGER_NAMES)
                self._merge_trigger_matches(secondary_matches)
                self._last_secondary_trigger_at = now
        except Exception as exc:
            self.state.last_error = str(exc)
            self._log(f"Trigger refresh error: {exc}")
        return dict(self._last_triggers)

    def _refresh_triggers(self, names: tuple[str, ...] | None = None) -> None:
        try:
            frame = self.capture.capture()
            self._remember_trigger_matches(self.trigger_monitor.find_detections(frame, names=names))
        except Exception as exc:
            self.state.last_error = str(exc)
            self._log(f"Trigger refresh error: {exc}")

    def _capture_region_or_full(self, roi: Rect | None) -> tuple[np.ndarray, bool]:
        if roi is not None:
            capture_region = getattr(self.capture, "capture_region", None)
            if callable(capture_region):
                try:
                    frame = capture_region(roi)
                    if frame.size > 0:
                        return frame, True
                except Exception as exc:
                    debug_log(f"FAST_REGION_CAPTURE_FAILED roi={roi} error={exc}")
        return self.capture.capture(), False

    def _window_size_or_none(self) -> tuple[int, int] | None:
        try:
            return self.capture.get_window_size()
        except Exception as exc:
            debug_log(f"WINDOW_SIZE_UNAVAILABLE {exc}")
            return None

    @staticmethod
    def _union_rect(*rects: Rect) -> Rect:
        left = min(rect.x for rect in rects)
        top = min(rect.y for rect in rects)
        right = max(rect.right for rect in rects)
        bottom = max(rect.bottom for rect in rects)
        return Rect(left, top, right - left, bottom - top)

    @staticmethod
    def _translate_rect(rect: Rect, origin: Rect) -> Rect:
        return Rect(rect.x - origin.x, rect.y - origin.y, rect.width, rect.height)

    def _is_trigger_active(self, trigger_name: str) -> bool:
        return trigger_name in self._last_triggers

    def _status_indicates_needs_meal(self, stage: str | None) -> bool:
        if not self.settings.auto_meal:
            return False
        if stage == "ad":
            return False
        status = getattr(self, "_last_player_status", None)
        checked_at = getattr(self, "_last_player_status_at", 0.0)
        if status is None or time.time() - checked_at > MEAL_STATUS_MAX_AGE_SECONDS:
            return False
        return status.has_needs(
            food_threshold=self.settings.restore_food_from,
            water_threshold=self.settings.restore_water_from,
            health_threshold=None,
        )

    def _brain_loop(self) -> None:
        while not self._stop_event.is_set():
            if self.is_paused_for_chat():
                self._publish_stage("Чат")
                self._sleep(0.15)
                continue
            self._update_focus_state_notification()
            triggers = self._get_triggers()
            stage = self._detect_stage(triggers)
            self._publish_stage(self._stage_label(stage))
            try:
                self._publish_estimated_player_status_if_changed()
                trigger_needs_meal = "hunger" in triggers or "thirst" in triggers
                status_needs_meal = self._status_indicates_needs_meal(stage)
                timer_needs_meal = self._status_timer_needs_meal()
                needs_meal = (
                    self.settings.auto_meal
                    and (trigger_needs_meal or status_needs_meal or timer_needs_meal)
                    and not self._meal_search_disabled_until_restart
                )
                if self._stop_if_no_stage_timed_out(stage, needs_meal):
                    break
                if stage != "ad" and self._close_game_menu_if_open():
                    continue
                if self._kickstart_requested:
                    self._kickstart_requested = False
                    if stage == "ad":
                        fish_name, confidence = self._run_reeling_module()
                        if fish_name or self._has_pending_catch():
                            self._do_fish_catch(fish_name, confidence)
                        continue
                    if self._should_run_initial_status_scan(stage):
                        self._initial_status_scan_pending = False
                        self._handle_pending_tasks(do_meal=True)
                        continue
                    if needs_meal and time.time() >= self._inventory_retry_after:
                        self._handle_pending_tasks(do_meal=True)
                        continue
                    if self._stop_event.is_set():
                        break
                    self._do_casting()
                elif "pereves" in triggers:
                    self._handle_overweight_trigger()
                elif self._has_pending_catch() or self._probe_catch_screen():
                    self._do_fish_catch()
                elif self._handle_player_status_scan_request(stage):
                    continue
                elif self._should_handle_meal_now(stage, needs_meal):
                    self._handle_pending_tasks(do_meal=True)
                elif stage == "ad":
                    fish_name, confidence = self._run_reeling_module()
                    if fish_name or self._has_pending_catch():
                        self._do_fish_catch(fish_name, confidence)
                elif "changed_bait" in triggers or "gear" in triggers:
                    self._do_change_bait()
                elif stage == "start2":
                    if time.time() - self._last_start2_handled_at > 8.0:
                        self._handle_start2_stage()
                    else:
                        self._sleep(0.25)
                elif stage == "start1":
                    self._do_casting()
                elif stage == "start":
                    if needs_meal and time.time() >= self._inventory_retry_after:
                        self._handle_pending_tasks(do_meal=True)
                    else:
                        self._do_casting()
                elif needs_meal:
                    if time.time() >= self._inventory_retry_after:
                        self._handle_pending_tasks(do_meal=True)
                    else:
                        self._sleep(0.5)
                else:
                    self._recover_idle_without_tasks()
            except Exception as exc:
                self._handle_brain_error(exc)

    def _recover_idle_without_tasks(self) -> None:
        if self._stop_event.is_set():
            return
        self._log("Свободно: задач нет, запускаю рыбалку")
        self._do_casting()

    def _handle_brain_error(self, exc: Exception) -> None:
        self.state.last_error = str(exc)
        if self._should_continue_reeling_after_capture_error(exc):
            self._log(f"Вываживание: временная ошибка захвата кадра, продолжаю: {exc}")
            self._sleep(0.2)
            return
        self._log(f"Brain error: {exc}")
        if self.state.phase == BotPhase.INVENTORY:
            self._inventory_tasks_retry_pending = True
            self._inventory_retry_after = max(getattr(self, "_inventory_retry_after", 0.0), time.time() + 8.0)
            self._log("Инвентарь: ошибка обработки, повторю позже без восстановления рыбалки")
            self._sleep(1.0)
            return
        try:
            self._try_recover()
        except Exception:
            self._sleep(1.0)

    def _should_continue_reeling_after_capture_error(self, exc: Exception) -> bool:
        if self.state.phase != BotPhase.REELING:
            return False
        if not self._is_transient_capture_error(exc):
            return False
        return "ad" in getattr(self, "_last_triggers", {}) or self.state.detected_stage == self._stage_label("ad")

    @staticmethod
    def _is_transient_capture_error(exc: Exception) -> bool:
        message = str(exc)
        return any(
            marker in message
            for marker in (
                "CreateCompatibleDC failed",
                "CreateCompatibleBitmap failed",
                "BitBlt failed",
                "GetBitmapBits failed",
            )
        )

    def _stop_if_no_stage_timed_out(self, stage: str | None, needs_meal: bool) -> bool:
        if stage is not None or needs_meal or self._has_pending_catch():
            self._no_stage_since = None
            return False
        now = time.time()
        if self._no_stage_since is None:
            self._no_stage_since = now
            return False
        if now - self._no_stage_since < AUTO_STOP_TIMEOUT_SECONDS:
            return False
        if not self._confirm_no_stage_before_autostop():
            return False
        self._log(f"Автостоп: {STOP_REASON_NO_STAGE}")
        self._stop_from_brain(STOP_REASON_NO_STAGE)
        return True

    def _confirm_no_stage_before_autostop(self) -> bool:
        try:
            frame = self.capture.capture()
            matches = self.trigger_monitor.find_detections(frame, names=FISHING_STAGE_TRIGGER_NAMES)
        except Exception as exc:
            self.state.last_error = str(exc)
            self._log(f"Auto-stop confirmation error: {exc}")
            return True
        self._remember_trigger_matches(matches)
        stage = self._detect_stage(self._last_triggers)
        if stage is not None:
            self._publish_stage(self._stage_label(stage))
            return False
        if self._has_pending_catch() or self._probe_catch_screen():
            self._no_stage_since = None
            return False
        return True

    def _run_casting_module(self) -> None:
        self._do_casting()

    @staticmethod
    def _stage_label(stage: str | None) -> str:
        labels = {
            "start": "Выбор снастей",
            "start1": "Заброс",
            "start2": "Ожидание поклёвки",
            "wait_tension": "Ожидание поклёвки",
            "ad": "Вываживание",
        }
        return labels.get(stage or "", "Свободно")

    def _should_handle_meal_now(self, stage: str | None, needs_meal: bool) -> bool:
        return bool(needs_meal and stage != "ad" and time.time() >= self._inventory_retry_after)

    def _should_run_initial_status_scan(self, stage: str | None) -> bool:
        return bool(self.settings.auto_meal and self._initial_status_scan_pending and stage != "ad")

    def _status_timer_needs_meal(self) -> bool:
        if not self.settings.auto_meal:
            return False
        return time.time() >= self._inventory_retry_after > 0.0

    def _sync_next_meal_check_from_status(self, status: PlayerStatus | None, *, log: bool = False) -> None:
        if not self.settings.auto_meal or getattr(self, "_meal_search_disabled_until_restart", False):
            return
        if status is None or status.food is None or status.water is None:
            return
        if self._status_needs_meal_for_scan(status):
            self._inventory_retry_after = 0.0
            if log:
                self._log("Питание: показатели ниже порога, проверка нужна сейчас")
            return
        self._schedule_next_meal_check_from_estimate(log=log)

    def _schedule_next_meal_check_from_estimate(self, *, log: bool = True) -> None:
        estimate = getattr(self, "_player_status_estimate", None)
        waits = None
        if estimate is not None:
            waits = estimate.seconds_until_below_breakdown(
                food_threshold=self._meal_food_threshold(),
                water_threshold=self._meal_water_threshold(),
            )
        if waits is None:
            self._inventory_retry_after = time.time() + MEAL_MISSING_RETRY_SECONDS
            if log:
                self._log(
                    "Питание: еда или вода не прочитаны, повторная проверка через "
                    f"{self._format_seconds(MEAL_MISSING_RETRY_SECONDS)}"
                )
            return
        food_wait, water_wait = waits
        wait_seconds = min(food_wait, water_wait)
        self._inventory_retry_after = time.time() + max(0.0, wait_seconds)
        if log:
            self._log(
                "Питание: следующая проверка через "
                f"{self._format_seconds(wait_seconds)} "
                f"(еда {self._format_seconds(food_wait)}, вода {self._format_seconds(water_wait)})"
            )

    def _meal_food_threshold(self) -> int:
        return min(100, self.settings.restore_food_from + MEAL_STATUS_THRESHOLD_TOLERANCE)

    def _meal_water_threshold(self) -> int:
        return min(100, self.settings.restore_water_from + MEAL_STATUS_THRESHOLD_TOLERANCE)

    @staticmethod
    def _format_seconds(seconds: float) -> str:
        total = max(0, int(round(seconds)))
        minutes, sec = divmod(total, 60)
        return f"{minutes}м {sec:02d}с"

    def _publish_stage(self, label: str) -> None:
        if self.state.detected_stage == label:
            return
        self.state.detected_stage = label
        if label != self._last_stage_label:
            self._last_stage_label = label
            self._log(f"Текущая стадия: {label}")

    @staticmethod
    def _detect_stage(triggers: dict[str, float]) -> str | None:
        for name in ("ad", "start2", "wait_tension", "start1", "start"):
            if name in triggers:
                return "start2" if name == "wait_tension" else name
        return None

    def _run_hooking_module(self) -> None:
        self._do_hooking()

    def _run_reeling_module(self) -> tuple[str | None, float]:
        self.state.phase = BotPhase.REELING
        self._reset_active_tackle_scan("ad")
        self._refresh_triggers(names=FISHING_STAGE_TRIGGER_NAMES)
        stage = self._detect_stage(self._last_triggers)
        if stage != "ad":
            if self._has_pending_catch() or self._probe_catch_screen():
                return None, 0.0
            label = self._stage_label(stage) if stage is not None else "Свободно"
            self._publish_stage(label)
            self._log(f"Вываживание не запущено: текущая стадия {label}")
            return None, 0.0
        self._publish_stage("Вываживание")
        reeling_debug_log = self._new_reeling_debug_log()
        self._append_reeling_debug_log(reeling_debug_log, "start", stage=stage)
        last_reeling_focus_attempt_at = self._restore_reeling_focus(0.0)
        self.reeling_tracker.configure_manual_mode(self.manual_reeling_mode)
        self.reeling_tracker.start()
        self.reeling_tracker.start_control_loop()
        last_trigger_check_at = 0.0
        last_interrupt_trigger_check_at = 0.0
        last_walking_guard_at = 0.0
        last_action_log_at = 0.0
        last_action_log_signature: tuple[str, int | None] | None = None
        seen_ad_stage = True
        started_at = time.time()
        ad_missing_since: float | None = None
        last_reeling_menu_log_at = 0.0
        finish_reason = "timeout"
        deadline = time.time() + 180.0
        while time.time() < deadline and not self._stop_event.is_set():
            self._update_focus_state_notification()
            now = time.time()
            if now - last_trigger_check_at >= REELING_STAGE_CHECK_INTERVAL_SECONDS:
                last_trigger_check_at = now
                frame = self.capture.capture()
                if self.game_menu_detector.is_open(frame):
                    if now - last_reeling_menu_log_at >= 2.0:
                        self._log("Вываживание: меню игры обнаружено, Esc не нажимаю")
                        last_reeling_menu_log_at = now
                    continue
                self._scan_tackle_for_active_stage("ad", frame)
                catch_result = self.catch_detector.detect(frame)
                if catch_result.visible:
                    finish_reason = "catch_screen"
                    self._last_catch_result = catch_result
                    self._save_catch_panel_snapshot(frame, catch_result)
                    fish_label = fish_display_name(catch_result.fish_id) if catch_result.fish_id else catch_result.fish_text or "unknown"
                    self._log(
                        "Стадия: пойманная рыба "
                        f"name={fish_label} id={catch_result.fish_id or 'unknown'} "
                        f"weight={catch_result.weight_text or 'unknown'} confidence={catch_result.fish_confidence:.2f}"
                    )
                    self._append_reeling_debug_log(
                        reeling_debug_log,
                        "catch_screen",
                        fish_id=catch_result.fish_id,
                        fish_name=fish_label,
                        weight=catch_result.weight_text,
                        confidence=catch_result.fish_confidence,
                    )
                    break
                self._remember_trigger_matches(self.trigger_monitor.find_detections(frame, names=FISHING_STAGE_TRIGGER_NAMES))
                if now - last_interrupt_trigger_check_at >= SECONDARY_TRIGGER_REFRESH_SECONDS:
                    last_interrupt_trigger_check_at = now
                    self._merge_trigger_matches(
                        self.trigger_monitor.find_detections(
                            frame,
                            names=("changed_bait", "gear", "pereves", "thirst", "hunger"),
                        )
                    )
                current_stage = self._detect_stage(self._last_triggers)
                if current_stage == "ad":
                    seen_ad_stage = True
                    ad_missing_since = None
                elif current_stage is not None:
                    finish_reason = f"stage_{current_stage}"
                    label = self._stage_label(current_stage)
                    self._publish_stage(label)
                    self._log(f"Вываживание: обнаружена другая стадия {label}, останавливаю вываживание")
                    self._append_reeling_debug_log(reeling_debug_log, "stage_changed", stage=current_stage, label=label)
                    break
                elif any(name in self._last_triggers for name in ("changed_bait", "gear", "pereves", "thirst", "hunger")):
                    state_name = next(name for name in ("changed_bait", "gear", "pereves", "thirst", "hunger") if name in self._last_triggers)
                    finish_reason = f"trigger_{state_name}"
                    self._log(f"Вываживание: обнаружено состояние {state_name}, останавливаю вываживание")
                    self._append_reeling_debug_log(reeling_debug_log, "trigger_interrupt", trigger=state_name)
                    break
                elif seen_ad_stage:
                    ad_missing_since = ad_missing_since or now
                    if now - ad_missing_since >= 1.5:
                        finish_reason = "ad_stage_ended"
                        self._log("Вываживание: стадия закончилась")
                        self._append_reeling_debug_log(reeling_debug_log, "ad_stage_ended")
                        break
            state = self.reeling_tracker.latest_state()
            if state.action == "input_blocked":
                last_reeling_focus_attempt_at = self._restore_reeling_focus(last_reeling_focus_attempt_at, now)
            if seen_ad_stage and now - last_walking_guard_at >= REELING_WALKING_GUARD_INTERVAL_SECONDS:
                last_walking_guard_at = now
                if self._check_reeling_walking_guard(state.action):
                    break
            move_sign = self._reeling_move_sign(state.move_val)
            action_log_signature = (state.action, move_sign)
            action_changed = action_log_signature != last_action_log_signature
            action_log_due = now - last_action_log_at >= REELING_ACTION_LOG_INTERVAL_SECONDS
            action_change_due = action_changed and now - last_action_log_at >= REELING_ACTION_CHANGE_LOG_INTERVAL_SECONDS
            if action_log_due or action_change_due:
                details = f", distance={state.distance:.2f}" if state.distance is not None else ""
                if state.move_val is not None:
                    if state.lateral is not None:
                        details += f", lateral={state.lateral:.2f}"
                    details += f", move={state.move_val:.2f}"
                if state.player_pos_offset is not None and state.fish_pos_offset is not None:
                    details += f", pos_offsets=0x{state.player_pos_offset:X}/0x{state.fish_pos_offset:X}"
                self._log(f"Вываживание: {state.action}{details}")
                self._append_reeling_debug_log(reeling_debug_log, "state", state=state)
                last_action_log_at = now
                last_action_log_signature = action_log_signature
            if state.action == "target_search":
                if not seen_ad_stage and now - started_at >= 20.0:
                    finish_reason = "target_search_timeout"
                    self._append_reeling_debug_log(reeling_debug_log, "target_search_timeout", state=state)
                    break
            if self._stop_event.is_set():
                break
            self._sleep(0.003)
        self.reeling_tracker.stop()
        if self._last_catch_result and self._last_catch_result.visible:
            result = self._last_catch_result
            self._append_reeling_debug_log(reeling_debug_log, "finish_catch", fish_id=result.fish_id, confidence=result.fish_confidence)
            return result.fish_id or fish_id_from_display(result.fish_text), result.fish_confidence
        fish_name, confidence = self._wait_for_catch_screen(timeout=REEL_CATCH_SCREEN_TIMEOUT_SECONDS)
        if fish_name:
            self._append_reeling_debug_log(reeling_debug_log, "finish_catch_wait", fish_id=fish_name, confidence=confidence)
            return fish_name, confidence
        self._append_reeling_debug_log(reeling_debug_log, "finish_lost", reason=finish_reason)
        if not self._stop_event.is_set():
            self._save_reeling_debug_log(reeling_debug_log, finish_reason)
        return None, 0.0

    def _new_reeling_debug_log(self) -> list[dict[str, object]] | None:
        if not self._should_collect_reeling_loss_log():
            return None
        return []

    def _append_reeling_debug_log(
        self,
        records: list[dict[str, object]] | None,
        event: str,
        *,
        state=None,
        **extra: object,
    ) -> None:
        if records is None:
            return
        record: dict[str, object] = {
            "time": datetime.now(timezone.utc).isoformat(),
            "event": event,
        }
        if state is not None:
            record.update(self._reeling_debug_state_fields(state))
        for key, value in extra.items():
            if value is None:
                continue
            record[key] = value
        records.append(record)

    @staticmethod
    def _reeling_debug_state_fields(state) -> dict[str, object]:
        fields: dict[str, object] = {
            "action": state.action,
            "active": state.active,
        }
        for key in ("distance", "lateral", "move_val"):
            value = getattr(state, key, None)
            if value is not None:
                fields[key] = round(float(value), 4)
        for key in ("fish_addr", "player_addr", "player_pos_offset", "fish_pos_offset"):
            value = getattr(state, key, None)
            if value is not None:
                fields[key] = f"0x{int(value):X}"
        return fields

    def _save_reeling_debug_log(self, records: list[dict[str, object]] | None, reason: str) -> Path | None:
        if not records:
            return None
        if IS_FROZEN and not self._debug_mode_enabled():
            return self._save_encrypted_reeling_loss_log(records, reason)
        try:
            DEBUG_CAPTURE_REELING_LOSS_DIR.mkdir(parents=True, exist_ok=True)
            stamp = int(time.time() * 1000)
            safe_reason = self._safe_debug_filename_part(reason or "lost")
            path = DEBUG_CAPTURE_REELING_LOSS_DIR / f"{stamp}_{safe_reason}.jsonl"
            path.write_bytes(self._serialize_reeling_loss_log(records))
            debug_log(f"REELING_LOSS_LOG_SAVED reason={reason} path={path}")
            self._log(f"Вываживание: debug-лог срыва сохранён {path}")
            return path
        except Exception as exc:
            debug_log(f"REELING_LOSS_LOG_SAVE_FAILED {exc}")
            return None

    def _save_encrypted_reeling_loss_log(self, records: list[dict[str, object]], reason: str) -> Path | None:
        try:
            LOG_DIR.mkdir(parents=True, exist_ok=True)
            stamp = int(time.time() * 1000)
            safe_reason = self._safe_debug_filename_part(reason or "lost")
            path = LOG_DIR / f"reeling_loss_{stamp}_{safe_reason}.jsonl.enc"
            plaintext = self._serialize_reeling_loss_log(records)
            path.write_bytes(encrypt_reeling_loss_log(plaintext, key=REELING_LOSS_RELEASE_LOG_KEY))
            self._prune_encrypted_reeling_loss_logs()
            debug_log(f"REELING_LOSS_ENCRYPTED_LOG_SAVED reason={reason} path={path}")
            self._log(f"Вываживание: зашифрованный лог срыва сохранён {path}")
            return path
        except Exception as exc:
            debug_log(f"REELING_LOSS_ENCRYPTED_LOG_SAVE_FAILED {exc}")
            return None

    @staticmethod
    def _serialize_reeling_loss_log(records: list[dict[str, object]]) -> bytes:
        text = "".join(f"{json.dumps(record, ensure_ascii=False, sort_keys=True)}\n" for record in records)
        return text.encode("utf-8")

    @staticmethod
    def _prune_encrypted_reeling_loss_logs() -> None:
        files = []
        for path in LOG_DIR.glob(REELING_LOSS_RELEASE_LOG_GLOB):
            if not path.is_file():
                continue
            try:
                files.append((path.stat().st_mtime, path.name, path))
            except OSError:
                continue
        files.sort(reverse=True)
        for _, _, path in files[REELING_LOSS_RELEASE_LOG_LIMIT:]:
            try:
                path.unlink()
            except OSError:
                pass

    def _restore_reeling_focus(self, last_attempt_at: float, now: float | None = None) -> float:
        current_time = time.time() if now is None else now
        if current_time - last_attempt_at < REELING_FOCUS_RETRY_SECONDS:
            return last_attempt_at
        self._force_focus_game()
        return current_time

    @staticmethod
    def _reeling_move_sign(move_val: float | None) -> int | None:
        if move_val is None:
            return None
        if move_val > 0:
            return 1
        if move_val < 0:
            return -1
        return 0

    def _check_reeling_walking_guard(self, reeling_action: str) -> bool:
        if not self._should_stop_for_reeling_walking_guard(reeling_action):
            return False
        current_state = self._detect_reeling_interruption_state()
        if current_state is not None:
            self._log(f"Вываживание прервано: найдено состояние {current_state}")
            return False
        if self._try_return_to_fishing_from_idle():
            return False
        self._log(f"Автостоп: {STOP_REASON_WALKING_GUARD}")
        self._stop_from_brain(STOP_REASON_WALKING_GUARD)
        return True

    def _should_stop_for_reeling_walking_guard(self, reeling_action: str) -> bool:
        if reeling_action not in REELING_PROBLEM_ACTIONS:
            return False
        if "ad" in self._last_triggers:
            return False
        if self._has_pending_catch():
            return False
        return True

    def _detect_reeling_interruption_state(self) -> str | None:
        frame = self.capture.capture()
        if self.game_menu_detector.is_open(frame):
            return "меню игры"
        if self.inventory_detector.is_open(frame):
            return "инвентарь"
        catch_result = self.catch_detector.detect(frame)
        if catch_result.visible:
            self._last_catch_result = catch_result
            self._save_catch_panel_snapshot(frame, catch_result)
            return "пойманная рыба"
        matches = self.trigger_monitor.find_detections(frame, names=tuple(REELING_KNOWN_INTERRUPTION_TRIGGERS))
        self._remember_trigger_matches(matches)
        stage = self._detect_stage(self._last_triggers)
        if stage is not None:
            self._publish_stage(self._stage_label(stage))
            return self._stage_label(stage)
        for name in sorted(REELING_KNOWN_INTERRUPTION_TRIGGERS):
            if name in self._last_triggers:
                return name
        return None

    def _try_return_to_fishing_from_idle(self, timeout: float = REELING_IDLE_RETURN_TIMEOUT_SECONDS) -> bool:
        self._log("Вываживание прервано: состояние не найдено, проверяю возврат клавишей E")
        self._focus_game()
        self._press_fishing_entry("Вываживание прервано")
        deadline = time.time() + timeout
        while time.time() < deadline and not self._stop_event.is_set():
            state = self._detect_reeling_interruption_state()
            if state is not None:
                self._log(f"Вываживание прервано: после E найдено состояние {state}")
                return True
            self._sleep(REELING_IDLE_RETURN_POLL_SECONDS)
        return False

    def _wait_for_catch_screen(self, timeout: float) -> tuple[str | None, float]:
        self.state.phase = BotPhase.CATCH
        deadline = time.time() + timeout
        while time.time() < deadline and not self._stop_event.is_set():
            frame = self.capture.capture()
            if self.game_menu_detector.is_open(frame):
                self._close_game_menu_if_open(frame)
                return None, 0.0
            result = self.catch_detector.detect(frame)
            if result.visible:
                self._last_catch_result = result
                self._save_catch_panel_snapshot(frame, result)
                fish_label = fish_display_name(result.fish_id) if result.fish_id else result.fish_text or "unknown"
                weight = result.weight_text or "unknown"
                self._log(
                    "Стадия: пойманная рыба "
                    f"name={fish_label} id={result.fish_id or 'unknown'} "
                    f"weight={weight} confidence={result.fish_confidence:.2f}"
                )
                return result.fish_id, result.fish_confidence
            self._sleep(CATCH_SCREEN_POLL_SECONDS)
        return None, 0.0

    def _do_casting(self) -> None:
        if self._retry_inventory_tasks_before_casting():
            return
        self.state.phase = BotPhase.CASTING
        self._log("Стадия: Заброс")
        if self._start_attempt_since is None:
            self._start_attempt_since = time.time()
        start_phase = self._prepare_fishing_start()
        if start_phase == "hooking":
            self._start_attempt_since = None
            self._handle_start2_stage()
            return
        if start_phase == "reeling":
            self._start_attempt_since = None
            fish_name, confidence = self._run_reeling_module()
            if fish_name or self._has_pending_catch():
                self._do_fish_catch(fish_name, confidence)
            return
        if self._stop_event.is_set():
            return
        if start_phase != "casting":
            self._log("Заброс пропущен: стадия рыбалки не найдена")
            if self._start_attempt_since is not None and time.time() - self._start_attempt_since >= AUTO_STOP_TIMEOUT_SECONDS:
                self._log(f"Автостоп: {STOP_REASON_START_FAILED}")
                self._stop_from_brain(STOP_REASON_START_FAILED)
            return
        self._start_attempt_since = None
        self._sleep_random(CAST_GREEN_DETECTION_DELAY_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
        timeout = 10.0
        deadline = time.time() + timeout
        cast_done = threading.Event()
        cast_result: dict[str, object] = {"pressed": False}
        last_debug_at = 0.0
        last_file_debug_at = 0.0
        self.casting_monitor = None
        control_thread = threading.Thread(
            target=self._casting_control_loop,
            args=(deadline, cast_done, cast_result, last_debug_at, last_file_debug_at),
            name="sonar-casting-control",
            daemon=True,
        )
        control_thread.start()
        while time.time() < deadline and not self._stop_event.is_set() and not cast_done.is_set():
            self._update_focus_state_notification()
            cast_done.wait(0.02)
        cast_done.set()
        control_thread.join(timeout=0.5)
        if cast_result.get("error"):
            self._log(f"Заброс: ошибка быстрого потока: {cast_result['error']}")
        if cast_result.get("blocked"):
            self._log("Заброс: ввод пропущен, окно игры не активно")
            return
        if not cast_result.get("pressed"):
            self._log("Заброс: таймаут зелёной зоны")
            return
        self._log("Заброс: завершён")
        self._wait_for_stage_transition(("start1",), ("start2", "wait_tension"), timeout=8.0, return_on_old_gone=False)

    def _retry_inventory_tasks_before_casting(self) -> bool:
        if not getattr(self, "_inventory_tasks_retry_pending", False):
            return False
        wait_seconds = self._inventory_retry_after - time.time()
        if wait_seconds > 0.0:
            self._sleep(min(0.5, wait_seconds))
            return True
        self._log("Инвентарь: повторяю отложенные действия перед забросом")
        self._handle_pending_tasks(do_meal=True)
        return True

    def _casting_control_loop(
        self,
        deadline: float,
        cast_done: threading.Event,
        cast_result: dict[str, object],
        last_debug_at: float,
        last_file_debug_at: float,
    ) -> None:
        window_size = self._window_size_or_none()
        casting_region = casting_roi_for_resolution(*window_size) if window_size is not None else None
        monitor_region_mode: bool | None = None
        try:
            while time.time() < deadline and not self._stop_event.is_set() and not cast_done.is_set():
                now = time.time()
                frame, region_captured = self._capture_region_or_full(casting_region)
                if self.casting_monitor is None or monitor_region_mode != region_captured:
                    if region_captured:
                        self.casting_monitor = GreenPixelMonitor(Rect(0, 0, frame.shape[1], frame.shape[0]), self.input_controller)
                    else:
                        self.casting_monitor = create_casting_monitor(frame, self.input_controller)
                    monitor_region_mode = region_captured
                result = self.casting_monitor.check_and_act(frame)
                if now - last_file_debug_at >= 0.05 or result.pressed:
                    debug_log(
                        "CAST "
                        f"count={result.count} peak={result.peak_count} drop={result.drop} "
                        f"bbox={result.bbox_area} marker={result.marker_offset} predicted={result.predicted_offset} "
                        f"velocity={result.marker_velocity} age={result.marker_age} "
                        f"tol={result.center_tolerance} fps={result.fps:.1f} pressed={result.pressed}"
                    )
                    last_file_debug_at = now
                if now - last_debug_at >= 1.0:
                    self._log(
                        "Заброс: зелёная зона "
                        f"count={result.count} peak={result.peak_count} "
                        f"bbox={result.bbox_area} marker={result.marker_offset} "
                        f"fps={result.fps:.0f} pressed={result.pressed}"
                    )
                    last_debug_at = now
                if result.pressed:
                    press_start = time.time()
                    tap_key_fast = getattr(self.input_controller, "tap_key_fast", None)
                    if tap_key_fast is not None:
                        pressed = tap_key_fast("space", duration=0.003)
                    else:
                        pressed = self.input_controller.key_down("space")
                        if pressed is not False:
                            time.sleep(0.003)
                            self.input_controller.key_up("space")
                    if pressed is False:
                        cast_result["blocked"] = "game_not_foreground"
                        cast_done.set()
                        return
                    press_end = time.time()
                    after_frame, _ = self._capture_region_or_full(casting_region if region_captured else None)
                    snapshot_path = self._save_cast_press_snapshot(frame, result, after_frame, press_start, press_end)
                    self._log(
                        f"Заброс: Space нажат marker={result.marker_offset} predicted={result.predicted_offset} "
                        f"velocity={result.marker_velocity} bbox={result.bbox_area} fps={result.fps:.0f}"
                    )
                    debug_log(
                        "CAST_PRESS "
                        f"count={result.count} peak={result.peak_count} drop={result.drop} "
                        f"bbox={result.bbox_area} marker={result.marker_offset} predicted={result.predicted_offset} "
                        f"velocity={result.marker_velocity} age={result.marker_age} "
                        f"tol={result.center_tolerance} fps={result.fps:.1f} "
                        f"press_ms={(press_end - press_start) * 1000:.1f} snapshot={snapshot_path}"
                    )
                    cast_result["pressed"] = True
                    cast_done.set()
                    return
                cast_done.wait(CAST_CONTROL_POLL_SECONDS)
        except Exception as exc:
            cast_result["error"] = str(exc)
            cast_done.set()
            return

    def _save_cast_press_snapshot(self, frame, result, after_frame=None, press_start: float | None = None, press_end: float | None = None) -> str | None:
        if not LOGS_ENABLED:
            return None
        try:
            snapshots_dir = LOG_DIR / "cast_press"
            snapshots_dir.mkdir(parents=True, exist_ok=True)
            ts = int(time.time() * 1000)
            path = snapshots_dir / f"cast_press_{ts}.png"
            image = frame.copy()
            if after_frame is not None and after_frame.shape == image.shape:
                separator = 6
                sep = image[:, :separator].copy()
                sep[:] = (255, 255, 255)
                image = cv2.hconcat([image, sep, after_frame.copy()])
            bbox = result.bbox_rect
            if bbox is not None:
                panels = 2 if after_frame is not None and after_frame.shape == frame.shape else 1
                panel_width = frame.shape[1] + (6 if panels == 2 else 0)
                for panel in range(panels):
                    x_shift = panel * panel_width
                    cv2.rectangle(image, (bbox.x + x_shift, bbox.y), (bbox.right + x_shift, bbox.bottom), (0, 255, 255), 2)
                    center_x = bbox.x + bbox.width // 2 + x_shift
                    cv2.line(image, (center_x, bbox.y - 18), (center_x, bbox.bottom + 18), (255, 255, 255), 1)
                    if result.marker_offset is not None:
                        marker_x = int(round(center_x + result.marker_offset))
                        cv2.line(image, (marker_x, bbox.y - 24), (marker_x, bbox.bottom + 24), (0, 0, 255), 2)
                    if result.predicted_offset is not None:
                        predicted_x = int(round(center_x + result.predicted_offset))
                        cv2.line(image, (predicted_x, bbox.y - 30), (predicted_x, bbox.bottom + 30), (255, 0, 0), 1)
                label = (
                    f"marker={result.marker_offset} predicted={result.predicted_offset} "
                    f"velocity={result.marker_velocity} age={result.marker_age} "
                    f"tol={result.center_tolerance} fps={result.fps:.1f} "
                    f"press_ms={None if press_start is None or press_end is None else round((press_end - press_start) * 1000, 1)}"
                )
                cv2.putText(image, label, (max(0, bbox.x - 120), max(18, bbox.y - 34)), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (255, 255, 255), 2)
            cv2.imwrite(str(path), image)
            return str(path)
        except Exception as exc:
            debug_log(f"CAST_SNAPSHOT_FAILED {exc}")
            return None

    def _do_hooking(self) -> bool:
        self.state.phase = BotPhase.HOOKING
        self._reset_active_tackle_scan("start2")
        self._log("Стадия: Подсечка")
        self._focus_game()
        if getattr(self, "_player_status_scan_requested", False):
            self._log("Показатели: прерываю ожидание подсечки для сканирования")
            return False
        deadline = time.time() + 60.0
        last_debug_at = 0.0
        self.hooking_monitor = None
        window_size = self._window_size_or_none()
        hook_region: Rect | None = None
        hook_red_roi: Rect | None = None
        hook_bubles_roi: Rect | None = None
        hook_resolution = "fullhd"
        hook_template_scales = (1.0,)
        if window_size is not None:
            hook_red_roi, hook_bubles_roi = hooking_rois_for_resolution(*window_size)
            hook_region = self._union_rect(hook_red_roi, hook_bubles_roi)
            hook_resolution = resolution_name(*window_size)
            hook_template_scales = template_scales_for_frame(*window_size, hook_resolution)
        monitor_region_mode: bool | None = None
        last_stage_seen_at = time.time()
        next_stage_check_at = 0.0
        tackle_scanned = False
        while time.time() < deadline and not self._stop_event.is_set():
            if getattr(self, "_player_status_scan_requested", False):
                self._log("Показатели: прерываю ожидание подсечки для сканирования")
                return False
            now = time.time()
            if now >= next_stage_check_at:
                next_stage_check_at = now + HOOKING_STAGE_CHECK_INTERVAL_SECONDS
                trigger_names = HOOKING_STAGE_TRIGGER_NAMES
                if (
                    self.settings.auto_meal
                    and not self._meal_search_disabled_until_restart
                    and now >= self._inventory_retry_after
                ):
                    trigger_names = HOOKING_STAGE_TRIGGER_NAMES + HOOKING_MEAL_TRIGGER_NAMES
                stage_frame = self.capture.capture()
                self._remember_trigger_matches(self.trigger_monitor.find_detections(stage_frame, names=trigger_names))
                if "start2" in self._last_triggers or "wait_tension" in self._last_triggers:
                    last_stage_seen_at = now
                if not tackle_scanned:
                    self._scan_tackle_for_active_stage("start2", stage_frame)
                    tackle_scanned = True
            if (
                "start2" not in self._last_triggers
                and "wait_tension" not in self._last_triggers
                and now - last_stage_seen_at >= HOOKING_STAGE_GRACE_SECONDS
            ):
                self._log("Подсечка: стадия закончилась до триггера")
                return False
            if (
                self.settings.auto_meal
                and not self._meal_search_disabled_until_restart
                and time.time() >= self._inventory_retry_after
                and ("hunger" in self._last_triggers or "thirst" in self._last_triggers)
            ):
                self._log("Подсечка: найден голод/жажда, выхожу из ожидания для питания")
                return False
            frame, region_captured = self._capture_region_or_full(hook_region)
            if self.hooking_monitor is None or monitor_region_mode != region_captured:
                if region_captured and hook_region is not None and hook_red_roi is not None and hook_bubles_roi is not None:
                    self.hooking_monitor = TemplateMonitor(
                        self._translate_rect(hook_red_roi, hook_region),
                        self._translate_rect(hook_bubles_roi, hook_region),
                        hook_resolution,
                        template_scales=hook_template_scales,
                        input_controller=self.input_controller,
                        focus_callback=self._force_focus_game,
                    )
                else:
                    self.hooking_monitor = create_hooking_monitor(frame, self.input_controller, self._force_focus_game)
                monitor_region_mode = region_captured
            result = self.hooking_monitor.check_and_act(frame)
            if time.time() - last_debug_at >= 2.0:
                self._log(f"Подсечка: red={result.red_confidence:.2f} bubbles={result.bubles_confidence:.2f}")
                last_debug_at = time.time()
            if result.pressed:
                self._log(f"Подсечка: Space нажат по триггеру {result.trigger_reason}")
                self._log("Подсечка: завершена")
                return True
            self._sleep(0.005)
        self._log("Подсечка: таймаут")
        return False

    def _handle_start2_stage(self) -> None:
        self._last_start2_handled_at = time.time()
        self._no_stage_since = None
        self.state.phase = BotPhase.HOOKING
        self._log("Стадия: Ожидание поклёвки -> ждём триггер подсечки")
        self._focus_game()
        hooked = self._do_hooking()
        if not hooked or self._stop_event.is_set():
            self._no_stage_since = None
            return
        stage = self._confirm_stage_after_hook()
        self._continue_after_hook(stage)

    def _confirm_stage_after_hook(self) -> str | None:
        deadline = time.time() + POST_HOOK_STAGE_CONFIRM_TIMEOUT_SECONDS
        while time.time() < deadline and not self._stop_event.is_set():
            if self._has_pending_catch() or self._probe_catch_screen():
                return "catch"
            self._refresh_triggers(names=FISHING_STAGE_TRIGGER_NAMES)
            stage = self._detect_stage(self._last_triggers)
            if stage is not None:
                self._publish_stage(self._stage_label(stage))
                return stage
            self._sleep(POST_HOOK_STAGE_POLL_SECONDS)
        self._log("Подсечка: после Space стадия не подтвердилась, возвращаюсь к общему определению стадии")
        return None

    def _continue_after_hook(self, stage: str | None) -> None:
        if self._stop_event.is_set():
            return
        if stage == "catch":
            self._do_fish_catch()
            return
        if stage == "ad":
            self._log("Стадия: Вываживание подтверждена после подсечки")
            fish_name, confidence = self._run_reeling_module()
            if fish_name or self._has_pending_catch():
                self._do_fish_catch(fish_name, confidence)
            return
        if stage == "start2":
            self._last_start2_handled_at = 0.0
            self._log("Подсечка: стадия осталась ожиданием поклёвки, вываживание не запускаю")
            return
        if stage in {"start", "start1"}:
            self._log(f"Подсечка: после Space найдена стадия {self._stage_label(stage)}, продолжаю по ней")
            self._do_casting()
            return
        self._log("Подсечка: текущая стадия не найдена, вываживание не запускаю")

    def _wait_for_stage_transition(
        self,
        old_names: tuple[str, ...],
        new_names: tuple[str, ...],
        timeout: float,
        return_on_old_gone: bool = True,
    ) -> str | None:
        deadline = time.time() + timeout
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers(names=tuple(set(old_names + new_names + ("ad",))))
            if "ad" not in self._last_triggers:
                self._close_game_menu_if_open()
            for name in new_names:
                if name in self._last_triggers:
                    return name
            if return_on_old_gone and not any(name in self._last_triggers for name in old_names):
                self._log("Переход стадии: предыдущая стадия исчезла")
                return None
            self._sleep(0.1)
        self._log("Переход стадии: таймаут")
        return None

    def _do_fish_catch(self, fish_name: str | None = None, confidence: float = 0.0) -> None:
        self.state.phase = BotPhase.CATCH
        result = self._current_catch_result(timeout=CATCH_SCREEN_CURRENT_TIMEOUT_SECONDS)
        if result is None:
            self._log("Экран улова не распознан; клик Забрать/Отпустить не отправлен")
            return
        catch_fish_name = result.fish_id or fish_id_from_display(result.fish_text)
        fish_name = catch_fish_name or fish_name
        confidence = result.fish_confidence if catch_fish_name else max(confidence, result.fish_confidence)
        fish_label = fish_display_name(fish_name) if fish_name else result.fish_text or "unknown"
        weight = f"{result.weight_kg:.2f}" if result.weight_kg is not None else result.weight_text or "unknown"
        quality = result.quality_text or "unknown"
        xp = (
            f"{result.xp_current}/{result.xp_total}"
            if result.xp_total is not None
            else str(result.xp_current)
            if result.xp_current is not None
            else "unknown"
        )
        stage_log_line = self._format_catch_stage_log(result, fish_label, fish_name)
        catch_log_line = (
            f"Улов: рыба={fish_label} id={fish_name or 'unknown'} "
            f"вес={weight} качество={quality} опыт={xp} confidence={confidence:.2f}"
        )
        self._log(catch_log_line)
        catch_panel = self._capture_catch_panel(result)
        catch_image_bytes = self._encode_png_bytes(catch_panel) if catch_panel is not None else None
        self._save_debug_catch_snapshots(
            result=result,
            fish_id=fish_name,
            fish_label=fish_label,
            weight=weight,
            quality=quality,
            xp=xp,
            confidence=confidence,
            stage_log_line=stage_log_line,
            catch_log_line=catch_log_line,
            crop=catch_panel,
        )
        fish_to_keep = self.config_manager.get_fish_to_keep()
        if self.inventory_full:
            keep_fish = False
            self._log("Инвентарь помечен как полный: рыба будет отпущена")
        elif fish_name:
            keep_fish = fish_name in fish_to_keep
        else:
            self._log("Рыба не распознана; отпускаю, чтобы не блокировать следующую попытку")
            keep_fish = False
        button = result.keep_button if keep_fish else result.release_button
        if button is None:
            self._log("Кнопка результата улова не найдена")
            return
        self._sleep_random(0.04, 0.04)
        self._click_match(button)
        self._last_catch_result = None
        self.session_stats.record_catch(
            fish_name,
            fish_label,
            result.weight_kg,
            kept=keep_fish,
            catch_size=quality,
        )
        self._publish_catch_ui_event(
            fish_id=fish_name,
            fish_label=fish_label,
            weight_kg=result.weight_kg,
            catch_size=quality,
            kept=keep_fish,
        )
        self.notification_manager.notify_caught_fish(
            fish_label,
            result.weight_kg,
            quality,
            result.xp_current,
            result.xp_total,
            self.session_stats.totals(),
            image_bytes=catch_image_bytes,
            released=not keep_fish,
        )
        if keep_fish:
            self._add_kept_fish_weight_to_inventory_estimate(result.weight_kg)
            self._log(f"Рыба оставлена: {fish_label} ({confidence:.2f})")
            if self._wait_for_pereves(timeout=2.0):
                self._handle_overweight_after_keep(result)
                return
        else:
            self._log(f"Рыба отпущена: {fish_label} ({confidence:.2f})")
        self._inventory_retry_after = 0.0

    def _has_pending_catch(self) -> bool:
        return bool(self._last_catch_result and self._last_catch_result.visible)

    @staticmethod
    def _catch_result_needs_refresh(result: CatchScreenResult) -> bool:
        return result.visible and result.fish_id is None

    @staticmethod
    def _catch_text_score(result: CatchScreenResult) -> int:
        return sum(1 for char in (result.fish_text or "") if char.isalnum())

    @classmethod
    def _is_better_catch_result(
        cls,
        candidate: CatchScreenResult,
        current: CatchScreenResult | None,
    ) -> bool:
        if not candidate.visible:
            return False
        if current is None:
            return True
        if candidate.fish_id and not current.fish_id:
            return True
        if candidate.fish_id == current.fish_id and candidate.fish_confidence > current.fish_confidence:
            return True
        if not candidate.fish_id and not current.fish_id and cls._catch_text_score(candidate) > cls._catch_text_score(current):
            return True
        return candidate.weight_kg is not None and current.weight_kg is None

    def _current_catch_result(self, timeout: float = 0.0) -> CatchScreenResult | None:
        fallback = self._last_catch_result if self._last_catch_result and self._last_catch_result.visible else None
        if fallback is not None and not self._catch_result_needs_refresh(fallback):
            return fallback
        deadline = time.time() + timeout
        while not self._stop_event.is_set():
            frame = self.capture.capture()
            if self.game_menu_detector.is_open(frame):
                self._close_game_menu_if_open(frame)
                return fallback
            result = self.catch_detector.detect(frame)
            if result.visible:
                if self._is_better_catch_result(result, fallback):
                    self._last_catch_result = result
                    self._save_catch_panel_snapshot(frame, result)
                    fallback = result
                if not self._catch_result_needs_refresh(result):
                    return result
            if timeout <= 0 or time.time() >= deadline:
                break
            self._sleep(CATCH_SCREEN_POLL_SECONDS)
        return fallback

    def _probe_catch_screen(self) -> bool:
        now = time.time()
        if now - self._last_catch_probe_at < 0.5:
            return False
        self._last_catch_probe_at = now
        frame = self.capture.capture()
        if self.game_menu_detector.is_open(frame):
            self._close_game_menu_if_open(frame)
            return False
        result = self.catch_detector.detect(frame)
        if not result.visible:
            return False
        self._last_catch_result = result
        self._save_catch_panel_snapshot(frame, result)
        self._publish_stage("Пойманная рыба")
        return True

    def _save_catch_panel_snapshot(self, frame, result: CatchScreenResult) -> str | None:
        now = time.time()
        if now - self._last_catch_snapshot_at < 0.8:
            return None
        if not LOGS_ENABLED:
            self._last_catch_snapshot_at = now
            return None
        crop = self.catch_detector.crop_panel(frame, result)
        if crop is None:
            return None
        try:
            catch_dir = LOG_DIR / "catches"
            catch_dir.mkdir(parents=True, exist_ok=True)
            fish_id = result.fish_id or "unknown"
            weight = (result.weight_text or "unknown").replace(".", "_").replace(",", "_").replace(" ", "_")
            path = catch_dir / f"catch_{int(now * 1000)}_{fish_id}_{weight}.png"
            cv2.imwrite(str(path), crop)
            self._last_catch_snapshot_at = now
            debug_log(f"CATCH_PANEL_SAVED {path}")
            return str(path)
        except Exception as exc:
            debug_log(f"CATCH_PANEL_SAVE_FAILED {exc}")
            return None

    @staticmethod
    def _format_catch_stage_log(result: CatchScreenResult, fish_label: str, fish_id: str | None = None) -> str:
        return (
            "Стадия: пойманная рыба "
            f"name={fish_label} id={fish_id or result.fish_id or 'unknown'} "
            f"weight={result.weight_text or 'unknown'} confidence={result.fish_confidence:.2f}"
        )

    def _capture_catch_panel(self, result: CatchScreenResult):
        try:
            frame = self.capture.capture()
            return self.catch_detector.crop_panel(frame, result)
        except Exception as exc:
            debug_log(f"CATCH_PANEL_CAPTURE_FAILED {exc}")
            return None

    @staticmethod
    def _encode_png_bytes(image) -> bytes | None:
        if image is None:
            return None
        ok, encoded = cv2.imencode(".png", image)
        if not ok:
            return None
        return encoded.tobytes()

    def _save_debug_catch_snapshots(
        self,
        *,
        result: CatchScreenResult,
        fish_id: str | None,
        fish_label: str,
        weight: str,
        quality: str,
        xp: str,
        confidence: float,
        stage_log_line: str,
        catch_log_line: str,
        crop=None,
    ) -> None:
        if not self._debug_capture_enabled():
            return
        reasons: list[tuple[str, Path]] = [("all_catches", DEBUG_CAPTURE_ALL_CATCHES_DIR)]
        if fish_id not in DEBUG_CAPTURE_ALLOWED_FISH_IDS:
            reasons.append(("unexpected_fish", DEBUG_CAPTURE_UNEXPECTED_FISH_DIR))
        if result.weight_kg is not None and result.weight_kg > DEBUG_CAPTURE_WEIGHT_THRESHOLD_KG:
            reasons.append(("over_15kg", DEBUG_CAPTURE_OVER_15KG_DIR))
        if self._is_trophy_quality(quality):
            reasons.append(("trophy", DEBUG_CAPTURE_TROPHY_DIR))
        try:
            crop = crop if crop is not None else self._capture_catch_panel(result)
            if crop is None:
                debug_log("DEBUG_CAPTURE_SKIPPED empty catch panel crop")
                return
            for reason, directory in reasons:
                self._write_debug_catch_snapshot(
                    directory=directory,
                    reason=reason,
                    crop=crop,
                    result=result,
                    fish_id=fish_id,
                    fish_label=fish_label,
                    weight=weight,
                    quality=quality,
                    xp=xp,
                    confidence=confidence,
                    stage_log_line=stage_log_line,
                    catch_log_line=catch_log_line,
                )
        except Exception as exc:
            debug_log(f"DEBUG_CAPTURE_FAILED {exc}")

    def _write_debug_catch_snapshot(
        self,
        *,
        directory: Path,
        reason: str,
        crop,
        result: CatchScreenResult,
        fish_id: str | None,
        fish_label: str,
        weight: str,
        quality: str,
        xp: str,
        confidence: float,
        stage_log_line: str,
        catch_log_line: str,
    ) -> None:
        directory.mkdir(parents=True, exist_ok=True)
        created_at = datetime.now(timezone.utc).isoformat(timespec="milliseconds")
        timestamp = int(time.time() * 1000)
        safe_fish = self._safe_debug_filename_part(fish_id or fish_label or "unknown")
        safe_weight = self._safe_debug_filename_part(weight)
        screenshot_path = directory / f"{timestamp}_{reason}_{safe_fish}_{safe_weight}.png"
        if not cv2.imwrite(str(screenshot_path), crop):
            debug_log(f"DEBUG_CAPTURE_WRITE_FAILED {screenshot_path}")
            return
        csv_path = directory / DEBUG_CAPTURE_CSV_NAME
        write_header = not csv_path.exists()
        with csv_path.open("a", encoding="utf-8", newline="") as file:
            writer = csv.DictWriter(
                file,
                fieldnames=[
                    "screenshot",
                    "screenshot_path",
                    "created_at_utc",
                    "reason",
                    "fish_id",
                    "fish_name",
                    "expected_fish_name",
                    "weight_kg",
                    "expected_kg",
                    "weight_text",
                    "quality",
                    "xp",
                    "confidence",
                    "full_description",
                    "stage_log_line",
                    "catch_log_line",
                ],
            )
            if write_header:
                writer.writeheader()
            writer.writerow(
                {
                    "screenshot": screenshot_path.name,
                    "screenshot_path": str(screenshot_path),
                    "created_at_utc": created_at,
                    "reason": reason,
                    "fish_id": fish_id or "",
                    "fish_name": fish_label,
                    "expected_fish_name": "",
                    "weight_kg": "" if result.weight_kg is None else f"{result.weight_kg:.2f}",
                    "expected_kg": "",
                    "weight_text": result.weight_text or weight,
                    "quality": quality,
                    "xp": xp,
                    "confidence": f"{confidence:.2f}",
                    "full_description": catch_log_line,
                    "stage_log_line": stage_log_line,
                    "catch_log_line": catch_log_line,
                }
            )
        debug_log(f"DEBUG_CAPTURE_SAVED reason={reason} path={screenshot_path}")

    @staticmethod
    def _safe_debug_filename_part(value: str) -> str:
        safe = "".join(char if char.isalnum() or char in {"-", "_"} else "_" for char in value.strip())
        safe = "_".join(part for part in safe.split("_") if part)
        return (safe or "unknown")[:80]

    @staticmethod
    def _should_collect_reeling_loss_log() -> bool:
        return IS_FROZEN or FishingBot._debug_mode_enabled()

    @staticmethod
    def _debug_capture_enabled() -> bool:
        return os.environ.get("SONAR_DEBUG_CAPTURE") == "1" or "--debug" in sys.argv

    @staticmethod
    def _debug_mode_enabled() -> bool:
        return os.environ.get("SONAR_DEBUG_MODE") == "1" or FishingBot._debug_capture_enabled()

    @staticmethod
    def _is_trophy_quality(quality: str | None) -> bool:
        return bool(quality and any(marker in quality.lower() for marker in ("троф", "рекорд")))

    def _close_game_menu_if_open(self, frame=None) -> bool:
        try:
            frame = self.capture.capture() if frame is None else frame
            match = self.game_menu_detector.detect(frame)
        except Exception as exc:
            debug_log(f"GAME_MENU_DETECT_FAILED {exc}")
            return False
        if match is None:
            return False
        now = time.time()
        if now - self._last_menu_close_at >= 1.0:
            self._last_menu_close_at = now
            self.input_controller.press_key("esc")
            self._publish_stage("Меню игры")
            self._log(f"Меню игры обнаружено ({match.name}={match.confidence:.2f}); нажимаю Esc")
        return True

    def _handle_pending_tasks(self, do_meal: bool | None = None) -> None:
        requested_meal = self.settings.auto_meal if do_meal is None else bool(do_meal and self.settings.auto_meal)
        self._do_combined_inventory_tasks(
            do_meal=requested_meal,
            do_backpack=self.settings.store_in_backpack,
        )

    def _handle_player_status_scan_request(self, stage: str | None) -> bool:
        if not getattr(self, "_player_status_scan_requested", False):
            return False
        if stage == "ad":
            return False
        self._player_status_scan_requested = False
        self._do_player_status_inventory_scan()
        return True

    def _do_player_status_inventory_scan(self) -> PlayerStatus | None:
        self.state.phase = BotPhase.INVENTORY
        self._log("Показатели: открываю инвентарь для сканирования")
        if not self._open_inventory():
            self._log("Показатели: инвентарь не открыт, сканирование пропущено")
            self._notify_player_status_scan_result(None)
            return None
        status: PlayerStatus | None = None
        result: PlayerStatus | None = None
        try:
            frame = self.capture.capture()
            status = self.meal_system.detect_player_status(frame)
            self._remember_player_status(status, inventory_scan=True)
            estimated = self.estimated_player_status() or status
            self._publish_player_status(estimated)
            self._sync_next_meal_check_from_status(estimated, log=True)
            result = estimated
            if estimated is None or not estimated.has_any_value():
                self._log("Показатели: не удалось прочитать еду, воду или вес")
            else:
                self._log(f"Показатели: {self._format_player_status_for_log(estimated)}")
            return estimated
        except Exception as exc:
            debug_log(f"PLAYER_STATUS_SCAN_FAILED {exc}")
            self._log(f"Показатели: ошибка сканирования: {exc}")
            return None
        finally:
            self._notify_player_status_scan_result(result)
            if self.state.running and not self._stop_event.is_set():
                self._return_to_fishing()

    def _notify_player_status_scan_result(self, status: PlayerStatus | None) -> None:
        notify = getattr(getattr(self, "notification_manager", None), "notify_player_status_scan_result", None)
        if callable(notify):
            notify(status)

    @staticmethod
    def _format_player_status_for_log(status: PlayerStatus) -> str:
        parts: list[str] = []
        if status.food is not None:
            parts.append(f"еда={status.food}%")
        if status.water is not None:
            parts.append(f"вода={status.water}%")
        if status.health is not None:
            parts.append(f"HP={status.health}%")
        if status.inventory_weight is not None or status.inventory_weight_max is not None:
            parts.append(
                "инвентарь="
                f"{FishingBot._format_status_weight_for_log(status.inventory_weight)}/"
                f"{FishingBot._format_status_weight_for_log(status.inventory_weight_max)} кг"
            )
        if status.backpack_weight is not None or status.backpack_weight_max is not None:
            parts.append(
                "рюкзак="
                f"{FishingBot._format_status_weight_for_log(status.backpack_weight)}/"
                f"{FishingBot._format_status_weight_for_log(status.backpack_weight_max)} кг"
            )
        return ", ".join(parts) or "нет данных"

    @staticmethod
    def _format_status_weight_for_log(value: float | None) -> str:
        if value is None:
            return "?"
        return f"{value:.2f}".rstrip("0").rstrip(".")

    def _do_combined_inventory_tasks(self, do_meal: bool, do_backpack: bool) -> None:
        if not do_meal and not do_backpack:
            return
        self.state.phase = BotPhase.INVENTORY
        if not self._open_inventory():
            self._inventory_tasks_retry_pending = True
            self._log("Инвентарь не открыт; отложенные действия пропущены")
            return
        self._inventory_tasks_retry_pending = False
        if do_meal:
            self._do_meal_actions()
        if do_backpack:
            if not self._is_inventory_open() and not self._open_inventory():
                self._log("Инвентарь закрыт; складывание в рюкзак пропущено")
            else:
                self._do_backpack_actions()
        if not self._is_inventory_open() and self.config_manager.get_garbage_to_eject():
            self._open_inventory()
        self._do_garbage()
        if self.settings.store_in_trunk:
            self._log("Store trunk routine skipped: exact original path is not restored yet")
        self._return_to_fishing()

    def _do_meal_actions(self) -> bool:
        if not self.settings.auto_meal:
            self._log("Питание пропущено: авто-питание выключено")
            return False
        consumed: list[MealItemSnapshot] = []
        moved_from_backpack_attempts = 0
        self._prepare_meal_system()
        while not self._stop_event.is_set():
            frame = self.capture.capture()
            detect_player_status = getattr(self.meal_system, "detect_player_status", None)
            status = detect_player_status(frame) if callable(detect_player_status) else None
            self._remember_player_status(status, inventory_scan=True)
            if status is not None and not self._status_needs_meal_for_scan(status):
                self._schedule_next_meal_check_from_estimate()
                break
            if status is None and not self.meal_system.check_needs_meal(
                frame,
                food_threshold=self._meal_food_threshold(),
                water_threshold=self._meal_water_threshold(),
                health_threshold=None,
            ):
                if self._meal_trigger_active_after_inventory_close():
                    if self._open_inventory():
                        continue
                    self._inventory_retry_after = time.time() + MEAL_MISSING_RETRY_SECONDS
                break
            inventory_food = self.meal_system.find_food_in_inventory(frame)
            if inventory_food is not None:
                snapshot = self.meal_system.consume_item(
                    inventory_food.match.x,
                    inventory_food.match.y,
                    inventory_food.key,
                    use_key=self.settings.use_item_hotkey,
                )
                consumed.append(snapshot)
                moved_from_backpack_attempts = 0
                self._log(f"Еда/вода использована: {snapshot.item_title or snapshot.display_name}, жду завершения анимации")
                self._sleep(MEAL_ANIMATION_WAIT_SECONDS)
                player_status = self._detect_player_status_for_meal()
                if player_status is not None:
                    snapshot = replace(snapshot, player_status=player_status)
                    consumed[-1] = snapshot
                self._notify_meal_consumed(snapshot)
                self._save_debug_meal_snapshot(snapshot)
                self._publish_ui_event("Питание использовано", event_type="meal", icon="food.svg", detail=snapshot.item_title)
                self._inventory_retry_after = 0.0
                if not self._confirm_still_needs_meal_after_consumption():
                    break
                if self._open_inventory():
                    continue
                self._inventory_retry_after = time.time() + MEAL_MISSING_RETRY_SECONDS
                break
            backpack_food = self.meal_system.find_food_in_backpack(frame)
            if backpack_food is not None and moved_from_backpack_attempts < MEAL_BACKPACK_MOVE_MAX_ATTEMPTS:
                moved_from_backpack_attempts += 1
                self._log(
                    "Питание: еды в инвентаре нет, перекладываю из рюкзака "
                    f"({moved_from_backpack_attempts}/{MEAL_BACKPACK_MOVE_MAX_ATTEMPTS})"
                )
                self.meal_system.move_item_from_backpack(backpack_food, move_key=self.settings.backpack_move_hotkey)
                continue
            if self._confirm_still_needs_meal_without_food():
                self._handle_food_depleted()
            break
        if consumed:
            self._schedule_next_meal_check_from_estimate()
        else:
            if self._inventory_retry_after <= time.time():
                self._inventory_retry_after = time.time() + MEAL_MISSING_RETRY_SECONDS
        self._log(f"Meal routine: consumed={len(consumed)} backpack_attempts={moved_from_backpack_attempts}")
        return bool(consumed)

    def _prepare_meal_system(self) -> None:
        width, height = self.capture.get_window_size()
        if not self.meal_system.templates:
            self.meal_system.load_templates(resolution_name(width, height))

    def _meal_trigger_active_after_inventory_close(self) -> bool:
        return self._confirm_still_needs_meal_outside_inventory(MEAL_MISSING_HUD_CHECK_TIMEOUT_SECONDS)

    def _confirm_still_needs_meal_after_consumption(self) -> bool:
        status = self.estimated_player_status()
        if status is not None and status.has_core_values():
            still_needs_meal = self._status_needs_meal_for_scan(status)
            if still_needs_meal:
                self._log("Питание: показатели всё ещё ниже порога, продолжаю поиск еды")
            return still_needs_meal
        still_needs_meal = self._confirm_still_needs_meal_outside_inventory(MEAL_POST_USE_HUD_CHECK_TIMEOUT_SECONDS)
        if still_needs_meal:
            self._log("Питание: голод/жажда всё ещё активны, продолжаю поиск еды")
        return still_needs_meal

    def _confirm_still_needs_meal_without_food(self) -> bool:
        status = self.estimated_player_status()
        if status is not None and status.has_core_values():
            return self._status_needs_meal_for_scan(status)
        return self._confirm_still_needs_meal_outside_inventory(MEAL_MISSING_HUD_CHECK_TIMEOUT_SECONDS)

    def _confirm_still_needs_meal_outside_inventory(self, timeout: float) -> bool:
        inventory_closed = self._close_inventory_for_meal_check()
        if self._stop_event.is_set():
            return False
        if not inventory_closed:
            self._log("Питание: инвентарь не закрылся для проверки, считаю голод/жажду активными")
            return True
        clear_polls = 0
        deadline = time.time() + timeout
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers(names=("hunger", "thirst"))
            needs_meal = "hunger" in self._last_triggers or "thirst" in self._last_triggers
            if needs_meal:
                clear_polls = 0
            else:
                clear_polls += 1
                if clear_polls >= MEAL_CLEAR_CONFIRM_POLLS:
                    return False
            self._sleep(MEAL_HUD_CHECK_POLL_SECONDS)
        return True

    def _close_inventory_for_meal_check(self) -> bool:
        self._focus_game()
        deadline = time.time() + 4.0
        next_toggle_at = 0.0
        inventory_was_open = False
        while time.time() < deadline and not self._stop_event.is_set():
            if not self._is_inventory_open():
                if inventory_was_open:
                    self._sleep(INVENTORY_CLOSE_PAUSE_SECONDS)
                return True
            inventory_was_open = True
            if time.time() >= next_toggle_at:
                self.input_controller.press_key(self.settings.inventory_hotkey)
                self._log(f"Питание: закрываю инвентарь клавишей {self.settings.inventory_hotkey} для контрольной проверки")
                next_toggle_at = time.time() + 1.0
            self._sleep(0.15)
        return False

    def _detect_player_status_for_meal(self):
        try:
            frame = self.capture.capture()
            status = self.meal_system.detect_player_status(frame)
            self._remember_player_status(status, inventory_scan=True)
            estimated = self.estimated_player_status() or status
            self._publish_player_status(estimated)
            return estimated
        except Exception as exc:
            debug_log(f"MEAL_STATUS_DETECT_FAILED {exc}")
            return None

    def _status_needs_meal_for_scan(self, status: PlayerStatus) -> bool:
        return status.has_needs(
            food_threshold=self._meal_food_threshold(),
            water_threshold=self._meal_water_threshold(),
            health_threshold=None,
        )

    def _remember_player_status(self, status: PlayerStatus | None, *, inventory_scan: bool = False) -> None:
        if status is None:
            return
        trusted_core = "screenshot" in status.source or inventory_scan
        self._player_status_estimate.update(status, trusted_core=trusted_core, inventory_scan=inventory_scan or "screenshot" in status.source)
        estimated = self.estimated_player_status()
        if estimated is not None:
            self._check_inventory_space_notification(estimated)

    def _publish_estimated_player_status_if_changed(self) -> None:
        status = self.estimated_player_status()
        if status is None or status == self._last_published_estimated_status:
            return
        self._last_published_estimated_status = status
        self._publish_player_status(status)

    def _publish_player_status(self, status: PlayerStatus | None) -> None:
        self._last_player_status = status
        self._last_player_status_at = time.time()
        callback = self.player_status_callback
        if callback is None:
            return
        try:
            callback(status)
        except Exception as exc:
            debug_log(f"PLAYER_STATUS_CALLBACK_FAILED {exc}")

    def _notify_meal_consumed(self, snapshot: MealItemSnapshot) -> None:
        self.notification_manager.notify_meal_eaten(
            snapshot.item_title or snapshot.display_name,
            image_bytes=self._encode_png_bytes(snapshot.image),
            item_info=snapshot.item_info,
            player_status=snapshot.player_status,
        )

    def _save_debug_meal_snapshot(self, snapshot: MealItemSnapshot) -> None:
        if not self._debug_capture_enabled():
            return
        if snapshot.image is None and snapshot.screen_image is None:
            return
        try:
            DEBUG_CAPTURE_MEAL_DIR.mkdir(parents=True, exist_ok=True)
            timestamp = int(time.time() * 1000)
            safe_item = self._safe_debug_filename_part(snapshot.item_title or snapshot.display_name or snapshot.key)
            base_name = f"{timestamp}_meal_{safe_item}"
            item_info_path = DEBUG_CAPTURE_MEAL_DIR / f"{base_name}_item_info.png"
            screen_path = DEBUG_CAPTURE_MEAL_DIR / f"{base_name}_screen.png"
            saved_item_info_path = self._write_debug_png(item_info_path, snapshot.image)
            saved_screen_path = self._write_debug_png(screen_path, snapshot.screen_image)
            if saved_item_info_path is None and saved_screen_path is None:
                return
            item_info = snapshot.item_info
            status = snapshot.player_status
            csv_path = DEBUG_CAPTURE_MEAL_DIR / DEBUG_CAPTURE_CSV_NAME
            write_header = not csv_path.exists()
            with csv_path.open("a", encoding="utf-8", newline="") as file:
                writer = csv.DictWriter(
                    file,
                    fieldnames=[
                        "screenshot",
                        "screenshot_path",
                        "item_info_screenshot",
                        "item_info_screenshot_path",
                        "screen_screenshot",
                        "screen_screenshot_path",
                        "created_at_utc",
                        "item_key",
                        "display_name",
                        "item_title",
                        "weight_kg",
                        "satiety_change",
                        "thirst_change",
                        "condition_percent",
                        "status_food",
                        "status_water",
                        "status_health",
                        "status_source",
                        "raw_text",
                    ],
                )
                if write_header:
                    writer.writeheader()
                item_info_screenshot = saved_item_info_path.name if saved_item_info_path else ""
                item_info_screenshot_path = str(saved_item_info_path) if saved_item_info_path else ""
                writer.writerow(
                    {
                        "screenshot": item_info_screenshot,
                        "screenshot_path": item_info_screenshot_path,
                        "item_info_screenshot": item_info_screenshot,
                        "item_info_screenshot_path": item_info_screenshot_path,
                        "screen_screenshot": saved_screen_path.name if saved_screen_path else "",
                        "screen_screenshot_path": str(saved_screen_path) if saved_screen_path else "",
                        "created_at_utc": datetime.now(timezone.utc).isoformat(timespec="milliseconds"),
                        "item_key": snapshot.key,
                        "display_name": snapshot.display_name,
                        "item_title": snapshot.item_title,
                        "weight_kg": snapshot.item_weight,
                        "satiety_change": item_info.satiety_change if item_info else "",
                        "thirst_change": item_info.thirst_change if item_info else "",
                        "condition_percent": item_info.condition_percent if item_info else "",
                        "status_food": "" if status is None or status.food is None else status.food,
                        "status_water": "" if status is None or status.water is None else status.water,
                        "status_health": "" if status is None or status.health is None else status.health,
                        "status_source": status.source if status else "",
                        "raw_text": item_info.text if item_info else "",
                    }
                )
            debug_log(
                "DEBUG_MEAL_CAPTURE_SAVED "
                f"item_info={saved_item_info_path or ''} screen={saved_screen_path or ''}"
            )
        except Exception as exc:
            debug_log(f"DEBUG_MEAL_CAPTURE_FAILED {exc}")

    @staticmethod
    def _write_debug_png(path: Path, image) -> Path | None:
        if image is None:
            return None
        if not cv2.imwrite(str(path), image):
            debug_log(f"DEBUG_MEAL_CAPTURE_WRITE_FAILED {path}")
            return None
        return path

    def _handle_food_depleted(self) -> None:
        self._publish_ui_event("Закончилась еда", event_type="danger", icon="food.svg")
        self._log("Закончилась еда")
        action = self.settings.food_depleted_action
        if action == "continue":
            self._meal_search_disabled_until_restart = True
            self._inventory_retry_after = float("inf")
            self._log("Питание: поиск еды отключён до следующего ручного перезапуска рыбалки")
            return
        self._stop_then_run_terminal_action(action, "Закончилась еда")

    def _do_backpack_actions(self) -> None:
        fish_to_keep = self.config_manager.get_fish_to_keep()
        count = self.fish_storer.run(fish_to_keep)
        self.notification_manager.notify_backpack_stored(count)
        self._log(f"Backpack routine stored: {count}")

    def _do_meal_routine(self) -> None:
        self._do_combined_inventory_tasks(do_meal=True, do_backpack=False)

    def _do_store_backpack_routine(self) -> None:
        self._do_combined_inventory_tasks(do_meal=False, do_backpack=True)

    def _do_garbage(self) -> int:
        enabled = self.config_manager.get_garbage_to_eject()
        if not enabled:
            return 0
        count = self.garbage_disposal.run(enabled, discard_key=self.settings.discard_key)
        if count:
            self._log(f"Disposed garbage items: {count}")
        return count

    def _do_change_bait(self) -> bool:
        if not self.settings.auto_change_bait:
            return False
        now = time.time()
        if now - self._last_change_bait_at < 3.0:
            return False
        self._last_change_bait_at = now
        self._focus_game()
        self._refresh_triggers(names=("ad", "changed_bait", "gear"))
        if "ad" in self._last_triggers:
            self._log("Смена наживки пропущена: идёт вываживание")
            return False
        if "changed_bait" not in self._last_triggers and "gear" not in self._last_triggers:
            return False
        self._notify_bait_tired()
        self.state.phase = BotPhase.RECOVERY
        self._log("Смена наживки: выхожу из режима рыбалки")
        self.input_controller.press_key("esc")
        self._sleep(0.3)
        deadline = time.time() + 5.0
        next_esc_at = 0.0
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers(names=FISHING_STAGE_TRIGGER_NAMES)
            if "ad" in self._last_triggers:
                self._log("Смена наживки остановлена: началось вываживание")
                return False
            if not self._is_fishing_stage_active(self._last_triggers):
                break
            if time.time() >= next_esc_at:
                self.input_controller.press_key("esc")
                next_esc_at = time.time() + 0.3
            self._sleep(0.1)
        if self._stop_event.is_set():
            return False
        if self._press_fishing_entry("Смена наживки"):
            self._log("Смена наживки: рыбалка запущена заново")
        self._kickstart_requested = True
        self._sleep(0.3)
        return True

    def _notify_bait_tired(self) -> None:
        try:
            self._publish_ui_event(
                "Рыба устала от приманки, исправляем",
                event_type="warning",
                icon="bait.png",
            )
        except AttributeError:
            pass
        notify = getattr(getattr(self, "notification_manager", None), "notify_bait_tired", None)
        if callable(notify):
            notify()

    def _do_store_trunk(self) -> bool:
        if not self.settings.store_in_trunk:
            return False
        self._focus_game()
        self.input_controller.press_key("esc")
        self._sleep(BOT_DELAYS["inventory"])
        self._press_fishing_entry("Хранилище")
        self._sleep(BOT_DELAYS["wait"])
        self._log("Store trunk routine executed")
        return True

    def _do_exit_fishing_on_pereves(self) -> None:
        self._handle_overweight_trigger()

    def _wait_for_pereves(self, timeout: float) -> bool:
        deadline = time.time() + timeout
        while time.time() < deadline and not self._stop_event.is_set():
            frame = self.capture.capture()
            detections = self.trigger_monitor.find_detections(frame, names=("pereves",))
            if "pereves" in detections:
                self._log("Перевес: триггер найден после сохранения рыбы")
                return True
            self._sleep(PREPARE_START_POLL_SECONDS)
        return False

    def _handle_overweight_trigger(self) -> None:
        self._handle_overweight_event(previous_result=self._last_catch_result)

    def _handle_overweight_event(self, previous_result: CatchScreenResult | None) -> None:
        if self._should_switch_trunk_to_player_storage():
            self._switch_from_trunk_to_player_storage()
            return
        if not self.inventory_full:
            self._log("Перевес: триггер найден, инвентарь помечен как полный")
            self.notification_manager.notify_inventory_full()
        self.inventory_full = True
        self._handle_overweight_action(previous_result=previous_result)

    def _should_switch_trunk_to_player_storage(self) -> bool:
        if not self.settings.store_in_trunk:
            return False
        if getattr(self, "_player_storage_fallback_active", False):
            return False
        return getattr(self, "_last_confirmed_storage", "") != "human"

    def _switch_from_trunk_to_player_storage(self) -> None:
        self._player_storage_fallback_active = True
        self.inventory_full = False
        self._last_confirmed_storage = ""
        self._inventory_retry_after = 0.0
        self.state.phase = BotPhase.RECOVERY
        self._log("Перевес: багажник заполнен, переключаю хранилище на инвентарь игрока")
        self._focus_game()
        self.input_controller.press_key("esc")
        self._sleep(0.3)
        deadline = time.time() + 5.0
        next_esc_at = 0.0
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers(names=FISHING_STAGE_TRIGGER_NAMES)
            if not self._is_fishing_stage_active(self._last_triggers):
                break
            if time.time() >= next_esc_at:
                self.input_controller.press_key("esc")
                next_esc_at = time.time() + 0.3
            self._sleep(0.1)
        if self._stop_event.is_set():
            return
        if self._press_fishing_entry("Перевес: переключение хранилища"):
            self._log("Перевес: открыт выбор снастей для хранилища игрока")
        self._kickstart_requested = True
        self._sleep(0.3)

    def _check_inventory_space_notification(self, status: PlayerStatus | None = None) -> None:
        if not self.state.running or self._stop_event.is_set():
            self._inventory_space_low_notified = False
            return
        telegram = self.config_manager.load().telegram
        if not telegram.notify_inventory_space_low:
            self._inventory_space_low_notified = False
            return
        status = status or self.estimated_player_status()
        if status is None or status.inventory_weight is None or status.inventory_weight_max is None:
            return
        free_kg = max(0.0, status.inventory_weight_max - status.inventory_weight)
        threshold = telegram.inventory_space_low_threshold_kg
        if free_kg < threshold:
            if not self._inventory_space_low_notified:
                self._inventory_space_low_notified = True
                self.notification_manager.notify_inventory_space_low(free_kg, threshold, status)
            return
        self._inventory_space_low_notified = False

    def _mark_storage_from_matches(self, matches: dict[str, TemplateMatch]) -> None:
        if "human" in matches:
            self._last_confirmed_storage = "human"
        elif "boat" in matches:
            self._last_confirmed_storage = "boat"
            self._storage_boat_unconfirmed_attempts = 0

    def _add_kept_fish_weight_to_inventory_estimate(self, weight_kg: float | None) -> None:
        if getattr(self, "_last_confirmed_storage", "") != "human":
            return
        self._player_status_estimate.add_inventory_fish_weight(weight_kg)
        status = self.estimated_player_status()
        if status is not None:
            self._publish_player_status(status)
            self._check_inventory_space_notification(status)

    def _handle_overweight_after_keep(self, previous_result: CatchScreenResult | None) -> None:
        self._handle_overweight_event(previous_result=previous_result)

    def _handle_overweight_action(self, previous_result: CatchScreenResult | None) -> None:
        action = self.settings.overweight_action
        if action == "release":
            self._log("Перевес: дальше отпускаю всю рыбу")
            result = self._current_catch_result(timeout=1.5) or previous_result
            if result and result.release_button:
                self._click_match(result.release_button)
            return
        if action == "exit_game":
            self._log("Перевес: выключаю игру")
            self._stop_then_run_terminal_action(action, STOP_REASON_OVERWEIGHT)
            return
        self._log("Перевес: останавливаю рыбалку")
        self._stop_then_run_terminal_action(action, STOP_REASON_OVERWEIGHT)

    def _stop_then_run_terminal_action(self, action: str, reason: str) -> None:
        self._stop_from_brain(reason)
        if action == "exit_game":
            self._shutdown_game()
        elif action == "shutdown_pc":
            self._shutdown_pc()

    def _shutdown_game(self) -> None:
        wanted = self.process_name.lower()
        for proc in psutil.process_iter(["name"]):
            try:
                if (proc.info.get("name") or "").lower() == wanted:
                    proc.terminate()
            except (psutil.NoSuchProcess, psutil.AccessDenied):
                continue

    def _shutdown_pc(self) -> None:
        import subprocess

        subprocess.Popen(["shutdown", "/s", "/t", "0"], shell=False)

    def _wait_for_start_phase(self, timeout: float = 10.0) -> bool:
        deadline = time.time() + timeout
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers(names=("start", "start1", "start2", "wait_tension"))
            if any(name in self._last_triggers for name in ("start", "start1", "start2", "wait_tension")):
                return True
            self._sleep(0.1)
        return False

    def _prepare_fishing_start(self, timeout: float = 12.0) -> str | None:
        self._focus_game()
        initial_matches = self.trigger_monitor.find_detections(
            self.capture.capture(),
            names=PREPARE_START_TRIGGER_NAMES,
        )
        if not self._is_fishing_stage_active(initial_matches):
            self._press_fishing_entry("Вход в рыбалку")
            self._sleep_random(START_MENU_OPEN_DELAY_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
        deadline = time.time() + timeout
        clicked: set[str] = set()
        last_log_at = 0.0
        storage_warning_logged = False
        storage_retry_at = 0.0
        storage_started_at = 0.0
        storage_gave_up = False
        storage_pending = False
        storage_selector_opened = False
        storage_anchor: TemplateMatch | None = None
        tackle_checked = False
        while time.time() < deadline and not self._stop_event.is_set():
            frame = self.capture.capture()
            matches = self.trigger_monitor.find_detections(frame, names=PREPARE_START_TRIGGER_NAMES)
            if "start" in matches:
                matches.update(self.trigger_monitor.find_detections(frame, names=PREPARE_START_CONTEXT_TRIGGER_NAMES))
            self._remember_trigger_matches(matches)
            self._mark_storage_from_matches(matches)
            if time.time() - last_log_at > 1.0:
                self._log(f"Pre-cast detections: {self._format_precise_triggers(matches)}")
                last_log_at = time.time()
            if not any(name in matches for name in ("start", "start1", "start2", "wait_tension", "ad")):
                self._sleep(PREPARE_START_POLL_SECONDS)
                continue
            if "ad" in matches and "ad" not in clicked:
                self._log("Стадия: Вываживание")
                return "reeling"
            if "start2" in matches or "wait_tension" in matches:
                self._log("Стадия: Ожидание поклёвки")
                return "hooking"
            if "start1" in matches:
                self._log("Стадия: Заброс")
                return "casting"
            if "start" in matches and not tackle_checked:
                tackle_checked = True
                if not self._check_tackle_before_start(frame):
                    return None
            if "storage" not in clicked and not storage_gave_up and "start" in matches:
                if storage_started_at == 0.0:
                    storage_started_at = time.time()
                if time.time() >= storage_retry_at:
                    storage_retry_at = (
                        time.time()
                        + STORAGE_SELECTION_RETRY_SECONDS
                        + random.uniform(0.0, RANDOM_DELAY_JITTER_SECONDS)
                    )
                    storage_result, anchor = self._ensure_storage_selection(
                        matches,
                        selector_opened=storage_selector_opened,
                        anchor=storage_anchor,
                        warn=not storage_warning_logged,
                    )
                    if anchor is not None:
                        storage_anchor = anchor
                    if storage_result == "done":
                        clicked.add("storage")
                        storage_pending = False
                    if storage_result == "opened":
                        storage_pending = True
                        storage_selector_opened = True
                        self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
                        continue
                    if storage_result == "progress":
                        storage_pending = True
                        self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
                        continue
                    if storage_result == "missing":
                        storage_warning_logged = True
                if "storage" not in clicked and time.time() - storage_started_at > STORAGE_SELECTION_GIVE_UP_SECONDS:
                    storage_gave_up = True
                    storage_pending = False
                elif "storage" not in clicked and (storage_pending or ("boat" in matches or "human" in matches)):
                    self._sleep(PREPARE_START_POLL_SECONDS)
                    continue
            if "start" in matches and "start" not in clicked:
                if self._press_fishing_start():
                    clicked.add("start")
                self._sleep(PREPARE_START_POLL_SECONDS)
                continue
            if ("changed_bait" in matches or "gear" in matches) and "change_bait" not in clicked:
                if self._do_change_bait():
                    clicked.add("change_bait")
                    self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
                    continue
            self._sleep(PREPARE_START_POLL_SECONDS)
        return None

    def _check_tackle_before_start(self, frame=None) -> bool:
        scan = self._read_tackle_until_clear(frame)
        if scan is None:
            return False
        if scan.obscured:
            self._log("Снаряжение: проверка пропущена, панель всё ещё перекрыта уведомлением")
            return True
        self._remember_session_start_net_state(scan)
        self._log("Снаряжение:\n" + format_tackle_items(scan.items))
        depletion = self._find_tackle_depletion(scan)
        if depletion is None:
            return not self._handle_tackle_depletion(scan)
        scan = self._confirm_tackle_depletion(scan, depletion[0])
        if scan is None:
            return False
        self._log("Снаряжение после перепроверки:\n" + format_tackle_items(scan.items))
        return not self._handle_tackle_depletion(scan)

    def _reset_active_tackle_scan(self, stage: str) -> None:
        if not hasattr(self, "_active_tackle_scanned_stages"):
            self._active_tackle_scanned_stages = set()
        self._active_tackle_scanned_stages.discard(stage)

    def _scan_tackle_for_active_stage(self, stage: str, frame=None) -> None:
        if stage not in {"start2", "ad"}:
            return
        if not hasattr(self, "_active_tackle_scanned_stages"):
            self._active_tackle_scanned_stages = set()
        if stage in self._active_tackle_scanned_stages:
            return
        self._active_tackle_scanned_stages.add(stage)
        label = self._stage_label(stage)
        try:
            current_frame = self.capture.capture() if frame is None else frame
            scan = self.tackle_detector.detect(current_frame)
            if scan.obscured:
                self._log(f"Снаряжение ({label}): перекрыто уведомлением")
                return
            if self._is_empty_tackle_scan(scan):
                self._log(f"Снаряжение ({label}): не прочитано")
                return
            self._store_tackle_scan(scan, current_frame)
            self._log(f"Снаряжение ({label}):\n" + format_tackle_items(scan.items))
        except Exception as exc:
            debug_log(f"TACKLE_ACTIVE_STAGE_SCAN_FAILED stage={stage} error={exc}")

    def _read_tackle_until_clear(self, frame=None) -> TackleScanResult | None:
        waits = [0.0, TACKLE_OBSCURED_INITIAL_WAIT_SECONDS]
        waits.extend([TACKLE_OBSCURED_RETRY_WAIT_SECONDS] * TACKLE_OBSCURED_RETRIES)
        latest_obscured_scan: TackleScanResult | None = None
        for attempt, wait_seconds in enumerate(waits):
            if wait_seconds > 0:
                self._log(f"Снаряжение перекрыто уведомлением, жду {wait_seconds:.0f} сек")
                self._sleep(wait_seconds)
                if self._stop_event.is_set():
                    return None
            current_frame = frame if attempt == 0 and frame is not None else self.capture.capture()
            scan = self.tackle_detector.detect(current_frame)
            if scan.obscured:
                latest_obscured_scan = scan
                continue
            latest_obscured_scan = None
            if self._is_empty_tackle_scan(scan):
                continue
            self._store_tackle_scan(scan, current_frame)
            return scan
        if latest_obscured_scan is not None:
            return latest_obscured_scan
        self._log(f"Автостоп: {STOP_REASON_TACKLE_UNREADABLE}")
        self._stop_from_brain(STOP_REASON_TACKLE_UNREADABLE)
        return None

    def _store_tackle_scan(self, scan: TackleScanResult, frame) -> None:
        row = self.tackle_detector.crop_row(frame)
        self.session_stats.set_tackle_scan(
            scan.items,
            image_bytes=self._encode_png_bytes(row),
            scanned_at=scan.scanned_at,
        )

    @staticmethod
    def _is_empty_tackle_scan(scan: TackleScanResult) -> bool:
        return all(item.count <= 0 for item in scan.items)

    def _find_tackle_depletion(self, scan: TackleScanResult) -> tuple[str, str, str, bool] | None:
        checks = (
            ("rod", "Удочка закончилась", self.settings.equipment_depleted_action, False),
            ("reel", "Катушка закончилась", self.settings.equipment_depleted_action, False),
            ("line", "Кончилась леска", self.settings.equipment_depleted_action, False),
            ("hook", "Закончились крючки/поводки", self.settings.leader_depleted_action, self.settings.fish_without_leader),
            ("bait", "Закончилась наживка/блёсна", self.settings.equipment_depleted_action, False),
            ("net", "Подсак закончился", self.settings.net_depleted_action, self.settings.fish_without_net),
        )
        for key, reason, action, allowed_without_item in checks:
            if scan.count_for(key) > 0:
                continue
            if allowed_without_item:
                continue
            return key, reason, action, allowed_without_item
        return None

    def _confirm_tackle_depletion(self, scan: TackleScanResult, depleted_key: str) -> TackleScanResult | None:
        latest = scan
        for _ in range(TACKLE_DEPLETION_CONFIRM_ATTEMPTS):
            self._sleep(TACKLE_DEPLETION_CONFIRM_DELAY_SECONDS)
            if self._stop_event.is_set():
                return None
            latest = self._read_tackle_until_clear()
            if latest is None:
                return None
            depletion = self._find_tackle_depletion(latest)
            if depletion is None:
                self._log("Снаряжение: повторное чтение не подтвердило отсутствие предмета")
                return latest
            if depletion[0] != depleted_key:
                return latest
        return latest

    def _handle_tackle_depletion(self, scan: TackleScanResult) -> bool:
        for item in scan.items:
            if item.count > 0:
                continue
            if item.key == "hook" and self.settings.fish_without_leader:
                self._publish_ui_event(
                    "Закончились крючки/поводки",
                    event_type="warning",
                    icon="leader.png",
                    detail="Бот продолжит работу по настройке",
                )
                self._log("Снаряжение: Закончились крючки/поводки, продолжаю по настройке")
            if item.key == "net" and self.settings.fish_without_net:
                if not self._should_notify_net_depleted():
                    continue
                self._publish_ui_event(
                    "Подсак закончился",
                    event_type="warning",
                    icon="landing_net.png",
                    detail="Бот продолжит работу по настройке",
                )
                self._log("Снаряжение: Подсак закончился, продолжаю по настройке")
        depletion = self._find_tackle_depletion(scan)
        if depletion is None:
            return False
        _, reason, action, _ = depletion
        self._perform_tackle_depleted_action(action, reason)
        return True

    def _perform_tackle_depleted_action(self, action: str, reason: str) -> None:
        self._publish_ui_event("Снаряжение закончилось", event_type="danger", icon="warning.svg", detail=reason)
        self._log(f"Снаряжение закончилось: {reason}")
        self._stop_then_run_terminal_action(action, reason)

    def _remember_session_start_net_state(self, scan: TackleScanResult) -> None:
        if getattr(self, "_session_started_with_net", None) is None:
            self._session_started_with_net = scan.count_for("net") > 0

    def _should_notify_net_depleted(self) -> bool:
        return getattr(self, "_session_started_with_net", None) is not False

    def _press_fishing_start(self) -> bool:
        self._focus_game()
        now = time.time()
        if now - self._last_start_pressed_at < 0.3:
            return False
        self._last_start_pressed_at = now
        debug_log("FISHING_START_PRESS reason=tackle_selection")
        self.input_controller.press_key("e")
        self._log("Стадия: Выбор снастей -> нажата E")
        self._sleep_random(TACKLE_ACTION_DELAY_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
        return True

    @staticmethod
    def _format_precise_triggers(matches: dict[str, TemplateMatch]) -> str:
        if any(name in matches for name in ("start", "start1", "start2", "wait_tension", "ad")):
            visible = matches
        else:
            visible = {name: match for name, match in matches.items() if name not in {"boat", "human", "change_boat"}}
        if not visible:
            return "no fishing stage"
        return ", ".join(f"{name}={match.confidence:.2f}" for name, match in sorted(visible.items()))

    def _ensure_storage_selection(
        self,
        matches: dict[str, TemplateMatch],
        selector_opened: bool,
        anchor: TemplateMatch | None,
        warn: bool = True,
    ) -> tuple[str, TemplateMatch | None]:
        if "start" not in matches:
            if warn:
                self._log("Fish storage skipped: fishing start stage is not confirmed")
            return "missing", anchor
        target = self._preferred_storage_target()
        other = "human" if target == "boat" else "boat"
        target_match = matches.get(target)
        other_match = matches.get(other)
        current = target if target_match else other if other_match else ""
        if current == target:
            if target == "boat":
                self._storage_boat_unconfirmed_attempts = 0
            self._log(f"Fish storage already selected: {target}")
            return "done", anchor
        current_match = matches.get(current)
        if not selector_opened:
            if current_match:
                self._click_match(current_match)
                self._log(f"Fish storage selector opened from: {current}")
                self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
                return "opened", current_match
            if current and warn:
                self._log(f"Fish storage is {current}; selector icon was not found")
            return "missing", anchor

        if target == "boat" and self._should_use_human_storage_fallback(current):
            if self._select_human_storage_when_boat_missing(other_match, anchor):
                return "progress", anchor
            return "done", anchor
        if anchor and self._click_storage_option_from_screenshot(target, anchor):
            self._mark_storage_selection_attempt(target)
            return "progress", anchor
        if target_match and other_match:
            self._click_match(target_match)
            self._mark_storage_selection_attempt(target)
            self._log(f"Fish storage option clicked: {target}")
            self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
            return "progress", anchor
        change_match = matches.get("change_boat")
        if change_match:
            self._click_match(change_match)
            self._mark_storage_selection_attempt(target)
            self._log(f"Fish storage switch clicked: {current or 'unknown'} -> {target}")
            self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
            return "progress", anchor
        if target == "boat" and self._select_human_storage_when_boat_missing(other_match, anchor):
            return "progress", anchor
        if current and warn:
            self._log(f"Fish storage is {current}; switch button was not found")
        return "missing", anchor

    def _preferred_storage_target(self) -> str:
        if self.settings.store_in_trunk and not getattr(self, "_player_storage_fallback_active", False):
            return "boat"
        return "human"

    def _mark_storage_selection_attempt(self, target: str) -> None:
        if target == "boat":
            self._storage_boat_unconfirmed_attempts = getattr(self, "_storage_boat_unconfirmed_attempts", 0) + 1

    def _should_use_human_storage_fallback(self, current: str) -> bool:
        if current != "human":
            return False
        attempts = getattr(self, "_storage_boat_unconfirmed_attempts", 0)
        if attempts < STORAGE_SELECTION_BOAT_UNCONFIRMED_ATTEMPTS:
            return False
        self._player_storage_fallback_active = True
        self._last_confirmed_storage = "human"
        self._storage_boat_unconfirmed_attempts = 0
        self._log("Fish storage boat option was not confirmed; using human fallback")
        return True

    def _select_human_storage_when_boat_missing(
        self,
        human_match: TemplateMatch | None,
        anchor: TemplateMatch | None,
    ) -> bool:
        if human_match is None and anchor is None:
            return False
        if human_match is not None:
            self._click_match(human_match)
            self._player_storage_fallback_active = True
            self._last_confirmed_storage = "human"
            self._storage_boat_unconfirmed_attempts = 0
            self._log("Fish storage boat option not found; selected human fallback")
            self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
            return True
        if anchor and self._click_storage_option_from_screenshot("human", anchor):
            self._player_storage_fallback_active = True
            self._last_confirmed_storage = "human"
            self._storage_boat_unconfirmed_attempts = 0
            self._log("Fish storage boat option not found; selected human fallback from screenshot")
            return True
        return False

    def _click_storage_option_from_screenshot(self, target: str, anchor: TemplateMatch) -> bool:
        frame = self.capture.capture()
        height, width = frame.shape[:2]
        res = resolution_name(width, height)
        roi = self._storage_selector_roi(anchor, width, height)
        template_specs: list[tuple[str, str, float]] = []
        if target == "boat":
            template_specs.append(("change_boat", "change_boat2k.png" if res == "2k" else "change_boat.png", 0.50))
            template_specs.append(("change_boat", "change_boat.png", 0.48))
            template_specs.append(("change_boat", "change_boat2k.png", 0.48))
            template_specs.append(("boat", "boat2k.png" if res == "2k" else "boat.png", 0.48))
            template_specs.append(("boat", "boat.png", 0.46))
            template_specs.append(("boat", "boat2k.png", 0.46))
        else:
            template_specs.append(("human", "human2k.png" if res == "2k" else "human.png", 0.50))
            template_specs.append(("human", "human.png", 0.46))
            template_specs.append(("human", "human2k.png", 0.46))

        for name, filename, threshold in template_specs:
            template = load_template(self.trigger_monitor.resource_dir / "triger" / filename)
            matcher = TemplateMatcher(threshold)
            template_resolution = "2k" if "2k" in filename else "fullhd"
            match = matcher.find_best_scaled(
                frame,
                template,
                roi=roi,
                name=name,
                scales=self._storage_template_scales(width, height, template_resolution),
            )
            if match is None:
                continue
            if not self._is_storage_click_safe(match, anchor, width, height):
                self._log(f"Fish storage screenshot candidate rejected: {name} ({match.confidence:.2f})")
                continue
            self._click_match(match)
            self._log(f"Fish storage screenshot option clicked: {name} ({match.confidence:.2f})")
            self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
            return True
        self._log(f"Fish storage screenshot option not found: {target}")
        return False

    @staticmethod
    def _is_storage_click_safe(match: TemplateMatch, anchor: TemplateMatch, width: int = 1920, height: int = 1080) -> bool:
        scale = frame_scale(width, height)
        return abs(match.x - anchor.x) <= int(round(320 * scale)) and abs(match.y - anchor.y) <= int(round(420 * scale))

    @staticmethod
    def _storage_selector_roi(anchor: TemplateMatch, width: int, height: int) -> Rect:
        scale = frame_scale(width, height)
        x = max(anchor.x - int(round(420 * scale)), 0)
        y = max(anchor.y - int(round(360 * scale)), 0)
        w = min(int(round(700 * scale)), width - x)
        h = min(int(round(520 * scale)), height - y)
        return Rect(x, y, w, h)

    @staticmethod
    def _storage_template_scales(width: int, height: int, template_resolution: str = "fullhd") -> tuple[float, ...]:
        return template_scales_for_frame(
            width,
            height,
            template_resolution,
            factors=(0.70, 0.82, 0.92, 1.0, 1.08, 1.20, 1.38),
        )

    @staticmethod
    def _best_storage_option(matches: list[TemplateMatch], anchor: TemplateMatch) -> TemplateMatch:
        def score(match: TemplateMatch) -> tuple[float, float]:
            vertical_bonus = 0.1 if match.y < anchor.y - 20 else 0.0
            horizontal_penalty = abs(match.x - anchor.x) / 10000.0
            return match.confidence + vertical_bonus - horizontal_penalty, match.confidence

        return max(matches, key=score)

    def _click_match(self, match: TemplateMatch) -> None:
        self._click_client(match.x, match.y)
        self._log(f"Clicked {match.name or 'template'} at client=({match.x},{match.y})")

    def _click_client(self, x: int, y: int) -> None:
        screen_x, screen_y = self.capture.client_to_screen(x, y)
        self.input_controller.click(screen_x, screen_y)

    def _exit_fishing(self) -> None:
        self._focus_game()
        self.input_controller.press_key("esc")
        self._sleep(BOT_DELAYS["esc"])
        self.input_controller.press_key("esc")

    def _open_inventory(self) -> bool:
        self._focus_game()
        self._close_game_menu_if_open()
        if self._is_inventory_open():
            self._log("Стадия: Инвентарь уже открыт")
            return True
        if not self._exit_to_idle_before_inventory():
            return False
        self._sleep(INVENTORY_OPEN_PAUSE_SECONDS)
        if self._stop_event.is_set():
            return False
        if self._is_inventory_open():
            self._log("Стадия: Инвентарь уже открыт")
            return True
        if not self._exit_to_idle_before_inventory():
            self._log("Инвентарь: стадия изменилась перед открытием, повторю позже")
            return False
        for attempt in range(2):
            self.input_controller.press_key(self.settings.inventory_hotkey)
            self._log(f"Инвентарь: нажата клавиша {self.settings.inventory_hotkey}")
            self._sleep(1.0)
            if self._wait_for_inventory_open():
                self._log("Стадия: Инвентарь открыт")
                return True
            if attempt == 0 and not self._stop_event.is_set():
                self._log("Инвентарь не открылся, повторяю через 0.5с")
                self._sleep(INVENTORY_OPEN_RETRY_DELAY_SECONDS)
                if self._is_inventory_open():
                    self._log("Стадия: Инвентарь открыт")
                    return True
                if not self._exit_to_idle_before_inventory():
                    self._log("Инвентарь: стадия изменилась перед повторным открытием, повторю позже")
                    return False
        self._save_inventory_detection_debug()
        self._inventory_retry_after = time.time() + 8.0
        self._log("Инвентарь не открылся по хоткею")
        return False

    def _wait_for_inventory_open(self, timeout: float = INVENTORY_OPEN_CONFIRM_TIMEOUT_SECONDS) -> bool:
        deadline = time.time() + timeout
        while time.time() < deadline and not self._stop_event.is_set():
            if self._is_inventory_open():
                return True
            self._sleep(0.12)
        return False

    def _return_to_fishing(self) -> None:
        self._focus_game()
        deadline = time.time() + 8.0
        next_inventory_toggle_at = 0.0
        inventory_was_open = False
        while time.time() < deadline and not self._stop_event.is_set():
            if self._close_game_menu_if_open():
                self._sleep(0.2)
                continue
            if not self._is_inventory_open():
                if inventory_was_open:
                    self._sleep(INVENTORY_CLOSE_PAUSE_SECONDS)
                break
            inventory_was_open = True
            if time.time() >= next_inventory_toggle_at:
                self.input_controller.press_key(self.settings.inventory_hotkey)
                self._log(f"Инвентарь: закрываю клавишей {self.settings.inventory_hotkey}")
                self._sleep(1.0)
                next_inventory_toggle_at = time.time() + 1.0
            self._sleep(0.12)
        idle_deadline = time.time() + 5.0
        while time.time() < idle_deadline and not self._stop_event.is_set():
            self._refresh_triggers(names=FISHING_STAGE_TRIGGER_NAMES)
            if not self._is_fishing_stage_active(self._last_triggers):
                break
            self._sleep(0.2)
        if self._stop_event.is_set():
            return
        if self._press_fishing_entry("Возврат к рыбалке"):
            self._log("Возврат к рыбалке: нажата E")

    def _exit_to_idle_before_inventory(self, timeout: float = 12.0) -> bool:
        deadline = time.time() + timeout
        next_esc_at = 0.0
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers(names=FISHING_STAGE_TRIGGER_NAMES)
            if self._close_game_menu_if_open():
                self._sleep(0.2)
                continue
            if "ad" in self._last_triggers:
                self._log("Инвентарь: стадия вываживания активна, Esc не нажимаю")
                return False
            if self._is_inventory_open():
                return True
            catch_result = self.catch_detector.detect(self.capture.capture())
            if not self._is_fishing_stage_active(self._last_triggers) and not catch_result.visible:
                return True
            if time.time() >= next_esc_at:
                self.input_controller.press_key("esc")
                self._log("Инвентарь: выхожу из текущей стадии через Esc")
                self._sleep(INVENTORY_STAGE_EXIT_SETTLE_SECONDS)
                self._sleep_random(1.2, 1.0)
                next_esc_at = time.time() + 0.2
            self._sleep(0.12)
        self._log("Инвентарь: не удалось выйти в свободную стадию")
        return False

    def _is_inventory_open(self) -> bool:
        try:
            frame = self.capture.capture()
            if self.game_menu_detector.is_open(frame):
                return False
            if self.inventory_detector.is_open(frame):
                return True
        except Exception as exc:
            debug_log(f"INVENTORY_DETECT_FAILED {exc}")
        return False

    def _save_inventory_detection_debug(self) -> None:
        if not LOGS_ENABLED:
            return
        try:
            frame = self.capture.capture()
            path = LOG_DIR / "inventory_detect_failed.png"
            path.parent.mkdir(parents=True, exist_ok=True)
            cv2.imwrite(str(path), frame)
            debug_log(f"INVENTORY_DETECT_FAILED_SCREENSHOT {path}")
        except Exception as exc:
            debug_log(f"INVENTORY_DEBUG_SCREENSHOT_FAILED {exc}")

    @staticmethod
    def _is_fishing_stage_active(triggers: dict[str, float]) -> bool:
        return any(name in triggers for name in ("start", "start1", "start2", "wait_tension", "ad"))

    def _remember_trigger_matches(self, matches: dict[str, TemplateMatch]) -> None:
        self._last_trigger_matches = matches
        self._last_triggers = {name: match.confidence for name, match in matches.items()}
        self._reset_no_stage_timer_if_stage_visible(self._last_triggers)

    def _merge_trigger_matches(self, matches: dict[str, TemplateMatch]) -> None:
        self._last_trigger_matches.update(matches)
        self._last_triggers.update({name: match.confidence for name, match in matches.items()})
        self._reset_no_stage_timer_if_stage_visible({name: match.confidence for name, match in matches.items()})

    def _reset_no_stage_timer_if_stage_visible(self, triggers: dict[str, float]) -> None:
        if self._is_fishing_stage_active(triggers):
            self._no_stage_since = None

    def _try_recover(self, max_retries: int = 3) -> bool:
        self.state.phase = BotPhase.RECOVERY
        self._refresh_triggers(names=FISHING_STAGE_TRIGGER_NAMES)
        if "ad" in self._last_triggers:
            self._log("Recover skipped: идёт вываживание")
            return False
        for attempt in range(max_retries):
            if self._stop_event.is_set():
                return False
            self._log(f"Recover attempt {attempt + 1}/{max_retries}")
            self._focus_game()
            self._press_fishing_entry("Recover")
            if self._wait_for_start_phase(timeout=BOT_DELAYS["recover_pause"]):
                self.notification_manager.notify_fishing_restored()
                return True
        self.notification_manager.notify_fishing_failed()
        return False

    def _press_fishing_entry(self, reason: str) -> bool:
        now = time.time()
        elapsed = now - getattr(self, "_last_fishing_entry_pressed_at", 0.0)
        if elapsed < FISHING_ENTRY_MIN_INTERVAL_SECONDS:
            remaining = FISHING_ENTRY_MIN_INTERVAL_SECONDS - elapsed
            self._log(f"{reason}: повторное нажатие E пропущено, cooldown {remaining:.1f}с")
            return False
        self._last_fishing_entry_pressed_at = now
        debug_log(f"FISHING_ENTRY_PRESS reason={reason}")
        if self.input_controller.press_key("e") is False:
            self._last_fishing_entry_pressed_at = 0.0
            return False
        return True

    def _sleep(self, seconds: float) -> None:
        end = time.time() + seconds
        while time.time() < end and not self._stop_event.is_set():
            time.sleep(min(0.05, end - time.time()))

    def _sleep_random(self, minimum: float, extra: float) -> None:
        self._sleep(minimum + random.uniform(0.0, max(0.0, extra)))

    def _load_fish_names(self) -> dict[str, str]:
        from sonar.fishing.fish_names import FISH_DISPLAY_NAMES

        return FISH_DISPLAY_NAMES

    def _get_fish_name_ru(self, fish_name_eng: str) -> str:
        return self._load_fish_names().get(fish_name_eng, fish_name_eng)

    def _publish_ui_event(
        self,
        text: str,
        *,
        event_type: str = "info",
        icon: str = "",
        detail: str = "",
        extra_green: str = "",
        extra_red: str = "",
    ) -> None:
        event_bus.publish_ui_event(
            UiEventMessage(
                text=text,
                event_type=event_type,
                icon=icon,
                detail=detail,
                extra_green=extra_green,
                extra_red=extra_red,
            )
        )

    def _publish_catch_ui_event(
        self,
        *,
        fish_id: str | None,
        fish_label: str,
        weight_kg: float | None,
        catch_size: str,
        kept: bool,
    ) -> None:
        details: list[str] = []
        if weight_kg is not None:
            details.append(format_weight(weight_kg))
        if catch_size and catch_size != "unknown":
            details.append(catch_size)
        price_text = ""
        if fish_id and weight_kg is not None:
            price_min, price_max = self.session_stats.effective_price_range_for(fish_id)
            if price_min > 0 or price_max > 0:
                price_text = "+ " + format_money_range(weight_kg * price_min, weight_kg * price_max)
        self._publish_ui_event(
            f"Поймана рыба: {fish_label}",
            event_type="fish",
            icon="fish.svg",
            detail=" · ".join(details),
            extra_green=price_text if kept else "",
            extra_red="отпущена" if not kept else "",
        )

    def _log(self, msg: str) -> None:
        self.logger.write(msg)

    def _force_focus_game(self) -> bool:
        try:
            if self._is_game_foreground():
                self._focus_lost_notified = False
                return True
            focused = self.window_activator.force_activate_gta5()
            if focused:
                self._last_focus_at = time.time()
                self._focus_lost_notified = False
            else:
                self._log("Game focus failed: Telegram focus request did not switch focus")
            return focused
        except Exception as exc:
            self._log(f"Game focus failed: {exc}")
            return False

    def _focus_game(self) -> bool:
        try:
            if self._is_game_foreground():
                self._focus_lost_notified = False
                return True
            if self.state.running:
                return False
            now = time.time()
            if now - self._last_focus_at < 5.0:
                return False
            self._last_focus_at = now
            focused = self.window_activator.force_activate_gta5()
            if focused:
                self._focus_lost_notified = False
            if not focused:
                self._log("Game focus failed: window was found but Windows did not switch focus")
            return focused
        except Exception as exc:
            self._log(f"Game focus failed: {exc}")
            return False

    def _is_game_foreground(self) -> bool:
        try:
            import psutil
            import win32gui
            import win32process

            hwnd = win32gui.GetForegroundWindow()
            _, pid = win32process.GetWindowThreadProcessId(hwnd)
            if not pid:
                return False
            return psutil.Process(pid).name().lower() == self.process_name.lower()
        except Exception:
            return False

    def _is_fishing_input_allowed(self) -> bool:
        input_enabled_event = getattr(self, "_input_enabled_event", None)
        return bool(input_enabled_event is not None and input_enabled_event.is_set() and self._is_game_foreground())

    def _capture_screenshot_bytes(self) -> bytes:
        frame = self.capture.capture()
        image = Image.fromarray(frame[:, :, ::-1])
        buffer = io.BytesIO()
        image.save(buffer, format="PNG")
        return buffer.getvalue()
