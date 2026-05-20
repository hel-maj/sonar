from __future__ import annotations

import csv
import io
import os
import random
import shutil
import sys
import threading
import time
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path
from typing import Callable

import cv2
import psutil
from PIL import Image

from sonar.automation.input_controller import InputController
from sonar.automation.window import WindowActivator
from sonar.config.manager import ConfigManager
from sonar.config.models import FishingSettings, TelegramSettings
from sonar.core.logging import CallbackLogger, LogCallback, debug_log
from sonar.core.sounds import play_sound
from sonar.core.state import BotPhase, BotState
from sonar.fishing.catch_screen import CatchScreenDetector, CatchScreenResult
from sonar.fishing.constants import BOT_DELAYS, TRIGGER_ROIS_FHD, resolution_name
from sonar.fishing.casting_a_fishing_rod import GreenPixelMonitor, create_monitor_for_frame as create_casting_monitor
from sonar.fishing.fish_names import fish_display_name, fish_id_from_display
from sonar.fishing.fish_recognition import FishRecognition
from sonar.fishing.garbage_disposal import GarbageDisposal
from sonar.fishing.game_menu import GameMenuDetector
from sonar.fishing.inventory_memory import InventoryMemoryDetector
from sonar.fishing.hooking import TemplateMonitor, create_monitor_for_frame as create_hooking_monitor
from sonar.fishing.inventory_stage import InventoryStageDetector
from sonar.fishing.meal_system import MealSystem
from sonar.fishing.memory_reeling import MemoryReelingTracker
from sonar.fishing.statistics import FishingSessionStats, parse_fish_prices_from_markdown
from sonar.fishing.store_fish import FishStorer
from sonar.fishing.trigger_monitor import TriggerMonitor
from sonar.telegram.notifier import NotificationManager
from sonar.paths import APP_DIR, LOG_DIR, LOGS_ENABLED
from sonar.vision.capture import WindowCapture
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


DEBUG_CAPTURE_ALLOWED_FISH_IDS = frozenset({"seriola", "ruster", "marlin", "krasny_gorbyl"})
DEBUG_CAPTURE_ROOT_DIR = APP_DIR / "debug_capture"
DEBUG_CAPTURE_UNEXPECTED_FISH_DIR = DEBUG_CAPTURE_ROOT_DIR / "fish_identification_screen_screenshots"
DEBUG_CAPTURE_OVER_15KG_DIR = DEBUG_CAPTURE_ROOT_DIR / "over_15kg_fish_screenshots"
DEBUG_CAPTURE_TROPHY_DIR = DEBUG_CAPTURE_ROOT_DIR / "trophy_fish_screenshots"
DEBUG_CAPTURE_ALL_CATCHES_DIR = DEBUG_CAPTURE_ROOT_DIR / "all_caught_fish_session_screenshots"
DEBUG_CAPTURE_CSV_NAME = "metadata.csv"
DEBUG_CAPTURE_WEIGHT_THRESHOLD_KG = 15.0
START_STOP_SOUND_VOLUME = 0.3
AUTO_STOP_TIMEOUT_SECONDS = 40.0
STOP_REASON_MANUAL = "вручную"
STOP_REASON_START_FAILED = "не смог начать рыбалку в течение 40 секунд"
STOP_REASON_NO_STAGE = "не в зоне рыбалки или не видно стадии рыбалки 40 секунд"
REEL_CATCH_SCREEN_TIMEOUT_SECONDS = 3.0
CATCH_SCREEN_CURRENT_TIMEOUT_SECONDS = 1.2
CATCH_SCREEN_POLL_SECONDS = 0.05
MEAL_ANIMATION_WAIT_SECONDS = 6.0
PREPARE_START_POLL_SECONDS = 0.05
RANDOM_DELAY_JITTER_SECONDS = 0.6
TACKLE_ACTION_DELAY_SECONDS = 0.5
CAST_GREEN_DETECTION_DELAY_SECONDS = 1.0
FOCUS_STATE_CHECK_INTERVAL_SECONDS = 0.5
START_MENU_OPEN_DELAY_SECONDS = 0.65
STORAGE_SELECTION_RETRY_SECONDS = 0.75
STORAGE_SELECTION_GIVE_UP_SECONDS = 3.0
STORAGE_SELECTION_CLICK_PAUSE_SECONDS = 0.58
CAST_CONTROL_POLL_SECONDS = 0.001


@dataclass
class FishingBot:
    log_callback: LogCallback | None = None
    config_manager: ConfigManager = field(default_factory=ConfigManager)
    input_controller: InputController = field(default_factory=InputController)
    notification_manager: NotificationManager = field(default_factory=NotificationManager)
    can_start_callback: Callable[[], bool] | None = None
    start_command_callback: Callable[[], bool] | None = None
    telegram_settings_changed_callback: Callable[[TelegramSettings], None] | None = None
    session_stats: FishingSessionStats = field(
        default_factory=lambda: FishingSessionStats(default_prices=parse_fish_prices_from_markdown())
    )
    process_name: str = "gta5.exe"
    keep_debug_capture: bool = False
    state: BotState = field(default_factory=BotState)

    def __post_init__(self) -> None:
        self.logger = CallbackLogger(self.log_callback)
        self.input_controller.input_allowed_callback = self._is_game_foreground
        self.capture = WindowCapture(self.process_name)
        self.window_activator = WindowActivator(self.process_name)
        self.trigger_monitor = TriggerMonitor()
        self.fish_recognition = FishRecognition(self.process_name)
        self.catch_detector = CatchScreenDetector(fish_recognition=self.fish_recognition)
        self.game_menu_detector = GameMenuDetector()
        self.inventory_detector = InventoryStageDetector()
        self.inventory_memory_detector = InventoryMemoryDetector(self.process_name)
        self.garbage_disposal = GarbageDisposal(self.process_name, input_controller=self.input_controller)
        self.meal_system = MealSystem(self.process_name, input_controller=self.input_controller)
        self.fish_storer = FishStorer(self.process_name, input_controller=self.input_controller)
        self.reeling_tracker = MemoryReelingTracker(self.process_name, input_controller=self.input_controller, log_callback=self._log)
        self.casting_monitor: GreenPixelMonitor | None = None
        self.hooking_monitor: TemplateMonitor | None = None
        self._stop_event = threading.Event()
        self._brain_thread: threading.Thread | None = None
        self._last_triggers: dict[str, float] = {}
        self._last_trigger_matches: dict[str, TemplateMatch] = {}
        self._kickstart_requested = False
        self._last_focus_at = 0.0
        self._last_focus_state_check_at = 0.0
        self._focus_lost_notified = False
        self._last_start2_handled_at = 0.0
        self._last_start_pressed_at = 0.0
        self._last_catch_result: CatchScreenResult | None = None
        self._last_stage_label = ""
        self._last_catch_snapshot_at = 0.0
        self._last_catch_probe_at = 0.0
        self._last_menu_close_at = 0.0
        self._last_change_bait_at = 0.0
        self._no_stage_since: float | None = None
        self._start_attempt_since: float | None = None
        self._inventory_retry_after = 0.0
        self.inventory_full = False
        self.settings: FishingSettings = self.config_manager.load().fishing
        self._configure_notifications()
        debug_log("FishingBot initialized")

    def reload_settings(self) -> None:
        settings = self.config_manager.load()
        self.settings = settings.fishing
        self.session_stats.default_prices = parse_fish_prices_from_markdown()
        self.session_stats.set_custom_prices(self.settings.custom_fish_prices)
        self._configure_notifications()
        self._log("Settings reloaded")

    def _configure_notifications(self) -> None:
        settings = self.config_manager.load()
        self.notification_manager.configure(
            settings.telegram,
            start_callback=self.start_command_callback or self.start,
            stop_callback=self.stop,
            is_running_callback=lambda: self.state.running,
            stats_callback=self.session_stats.totals,
            stats_rows_callback=self.session_stats.rows,
            has_stats_callback=self.session_stats.has_catches,
            screenshot_callback=self._capture_screenshot_bytes,
            focus_game_callback=self._force_focus_game,
            shutdown_game_callback=self._shutdown_game,
            shutdown_pc_callback=self._shutdown_pc,
            settings_changed_callback=self._save_telegram_settings,
        )

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
        if self._brain_thread and self._brain_thread.is_alive():
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
        self.state.running = True
        self.state.phase = BotPhase.IDLE
        self.state.detected_stage = "Свободно"
        self.inventory_full = False
        self._inventory_retry_after = 0.0
        self._last_catch_result = None
        self._no_stage_since = None
        self._start_attempt_since = None
        self._last_focus_state_check_at = 0.0
        self._focus_lost_notified = False
        self.session_stats.start_timer()
        self._brain_thread = threading.Thread(target=self._brain_loop, name="sonar-brain", daemon=True)
        self._brain_thread.start()
        self._kickstart_requested = True
        self._log("Fishing bot started")
        if self.settings.start_stop_sound_enabled:
            play_sound("bot_start.wav", volume=START_STOP_SOUND_VOLUME)
        self.notification_manager.notify_fishing_started(self.session_stats.totals(), self.session_stats.has_catches())
        return True

    def stop(self, reason: str = STOP_REASON_MANUAL) -> None:
        was_running = self.state.running
        self.state.phase = BotPhase.STOPPING
        self._stop_event.set()
        self._finish_stop(was_running, reason)
        if self._brain_thread and self._brain_thread.is_alive() and threading.current_thread() is not self._brain_thread:
            threading.Thread(target=self._join_brain_thread, name="sonar-brain-stop", daemon=True).start()

    def _stop_from_brain(self, reason: str) -> None:
        was_running = self.state.running
        self.state.phase = BotPhase.STOPPING
        self._stop_event.set()
        self._finish_stop(was_running, reason)

    def _finish_stop(self, was_running: bool, reason: str) -> None:
        self.reeling_tracker.stop()
        self.inventory_memory_detector.close()
        self.input_controller.release_all_keys()
        self.state.running = False
        self.state.phase = BotPhase.IDLE
        self.state.detected_stage = "Свободно"
        self.inventory_full = False
        self._last_catch_result = None
        self._no_stage_since = None
        self._start_attempt_since = None
        self._focus_lost_notified = False
        if was_running:
            self.session_stats.stop_timer()
        self._log(f"Fishing bot stopped: {reason}")
        if was_running:
            if self.settings.start_stop_sound_enabled:
                play_sound("bot_stop.wav", volume=START_STOP_SOUND_VOLUME)
            self.notification_manager.notify_fishing_stopped(self.session_stats.totals(), reason=reason)

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
        self._refresh_triggers()
        return dict(self._last_triggers)

    def _refresh_triggers(self) -> None:
        try:
            frame = self.capture.capture()
            self._last_trigger_matches = self.trigger_monitor.find_detections(frame)
            self._last_triggers = {name: match.confidence for name, match in self._last_trigger_matches.items()}
        except Exception as exc:
            self.state.last_error = str(exc)
            self._log(f"Trigger refresh error: {exc}")

    def _is_trigger_active(self, trigger_name: str) -> bool:
        return trigger_name in self._last_triggers

    def _brain_loop(self) -> None:
        while not self._stop_event.is_set():
            self._update_focus_state_notification()
            triggers = self._get_triggers()
            stage = self._detect_stage(triggers)
            self._publish_stage(self._stage_label(stage))
            try:
                needs_meal = "hunger" in triggers or "thirst" in triggers
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
                    if needs_meal and time.time() >= self._inventory_retry_after:
                        self._handle_pending_tasks(do_meal=True)
                    if self._stop_event.is_set():
                        break
                    self._do_casting()
                elif "pereves" in triggers:
                    self._handle_overweight_trigger()
                elif self._has_pending_catch() or self._probe_catch_screen():
                    self._do_fish_catch()
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
                        self._press_fishing_start()
                elif needs_meal:
                    if time.time() >= self._inventory_retry_after:
                        self._handle_pending_tasks(do_meal=True)
                    else:
                        self._sleep(0.5)
                else:
                    self._sleep(0.25)
            except Exception as exc:
                self.state.last_error = str(exc)
                self._log(f"Brain error: {exc}")
                try:
                    self._try_recover()
                except Exception as recover_exc:
                    self._sleep(1.0)

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
        self._log(f"Автостоп: {STOP_REASON_NO_STAGE}")
        self._stop_from_brain(STOP_REASON_NO_STAGE)
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
        self._publish_stage("Вываживание")
        self.reeling_tracker.start()
        self.reeling_tracker.start_control_loop()
        last_recognition_at = 0.0
        last_trigger_check_at = 0.0
        last_action_log_at = 0.0
        seen_ad_stage = False
        started_at = time.time()
        ad_missing_since: float | None = None
        last_reeling_menu_log_at = 0.0
        deadline = time.time() + 180.0
        while time.time() < deadline and not self._stop_event.is_set():
            self._update_focus_state_notification()
            now = time.time()
            if now - last_trigger_check_at >= 0.15:
                last_trigger_check_at = now
                frame = self.capture.capture()
                if self.game_menu_detector.is_open(frame):
                    if now - last_reeling_menu_log_at >= 2.0:
                        self._log("Вываживание: меню игры обнаружено, Esc не нажимаю")
                        last_reeling_menu_log_at = now
                    continue
                catch_result = self.catch_detector.detect(frame)
                if catch_result.visible:
                    self._last_catch_result = catch_result
                    self._save_catch_panel_snapshot(frame, catch_result)
                    fish_label = fish_display_name(catch_result.fish_id) if catch_result.fish_id else catch_result.fish_text or "unknown"
                    self._log(
                        "Стадия: пойманная рыба "
                        f"name={fish_label} id={catch_result.fish_id or 'unknown'} "
                        f"weight={catch_result.weight_text or 'unknown'} confidence={catch_result.fish_confidence:.2f}"
                    )
                    break
                self._last_trigger_matches = self.trigger_monitor.find_detections(frame)
                self._last_triggers = {name: match.confidence for name, match in self._last_trigger_matches.items()}
                if "ad" in self._last_triggers:
                    seen_ad_stage = True
                    ad_missing_since = None
                elif seen_ad_stage:
                    ad_missing_since = ad_missing_since or now
                    if now - ad_missing_since >= 1.5:
                        self._log("Вываживание: стадия закончилась")
                        break
            state = self.reeling_tracker.latest_state()
            if now - last_action_log_at >= 1.0:
                details = f", distance={state.distance:.2f}" if state.distance is not None else ""
                if state.move_val is not None:
                    if state.lateral is not None:
                        details += f", lateral={state.lateral:.2f}"
                    details += f", move={state.move_val:.2f}"
                if state.player_pos_offset is not None and state.fish_pos_offset is not None:
                    details += f", pos_offsets=0x{state.player_pos_offset:X}/0x{state.fish_pos_offset:X}"
                self._log(f"Вываживание: {state.action}{details}")
                last_action_log_at = now
            if state.action == "target_search":
                if not seen_ad_stage and now - started_at >= 20.0:
                    break
            if seen_ad_stage and now - last_recognition_at >= 1.0:
                last_recognition_at = now
                fish_name, confidence = self.fish_recognition.recognize_once()
                if fish_name and confidence >= 0.55:
                    self.reeling_tracker.stop()
                    return fish_name, confidence
            if self._stop_event.is_set():
                break
            self._sleep(0.003)
        self.reeling_tracker.stop()
        if self._last_catch_result and self._last_catch_result.visible:
            result = self._last_catch_result
            return result.fish_id or fish_id_from_display(result.fish_text), result.fish_confidence
        fish_name, confidence = self._wait_for_catch_screen(timeout=REEL_CATCH_SCREEN_TIMEOUT_SECONDS)
        if fish_name:
            return fish_name, confidence
        return None, 0.0

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

    def _casting_control_loop(
        self,
        deadline: float,
        cast_done: threading.Event,
        cast_result: dict[str, object],
        last_debug_at: float,
        last_file_debug_at: float,
    ) -> None:
        try:
            while time.time() < deadline and not self._stop_event.is_set() and not cast_done.is_set():
                now = time.time()
                frame = self.capture.capture()
                if self.casting_monitor is None:
                    self.casting_monitor = create_casting_monitor(frame, self.input_controller)
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
                    if self.input_controller.key_down("space") is False:
                        cast_result["blocked"] = "game_not_foreground"
                        cast_done.set()
                        return
                    time.sleep(0.003)
                    self.input_controller.key_up("space")
                    press_end = time.time()
                    after_frame = self.capture.capture()
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
        self._log("Стадия: Подсечка")
        self._focus_game()
        deadline = time.time() + 60.0
        last_debug_at = 0.0
        self.hooking_monitor = None
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers()
            if "start2" not in self._last_triggers and "wait_tension" not in self._last_triggers:
                self._log("Подсечка: стадия закончилась до триггера")
                return False
            frame = self.capture.capture()
            if self.hooking_monitor is None:
                self.hooking_monitor = create_hooking_monitor(frame, self.input_controller)
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
        self.state.phase = BotPhase.HOOKING
        self._log("Стадия: Ожидание поклёвки -> ждём триггер подсечки")
        self._focus_game()
        hooked = self._do_hooking()
        if not hooked or self._stop_event.is_set():
            return
        transition = self._wait_for_stage_transition(("start2", "wait_tension"), ("ad",), timeout=2.0, return_on_old_gone=True)
        if transition != "ad":
            self._log("Стадия: Вываживание -> запускаю после успешной подсечки")
        if not self._stop_event.is_set():
            fish_name, confidence = self._run_reeling_module()
            if fish_name or self._has_pending_catch():
                self._do_fish_catch(fish_name, confidence)

    def _wait_for_stage_transition(
        self,
        old_names: tuple[str, ...],
        new_names: tuple[str, ...],
        timeout: float,
        return_on_old_gone: bool = True,
    ) -> str | None:
        deadline = time.time() + timeout
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers()
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
        fish_name = fish_name or result.fish_id or fish_id_from_display(result.fish_text)
        confidence = max(confidence, result.fish_confidence)
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
        )
        self.notification_manager.notify_caught_fish(
            fish_label,
            result.weight_kg,
            quality,
            result.xp_current,
            result.xp_total,
            self.session_stats.totals(),
            image_bytes=catch_image_bytes,
        )
        if keep_fish:
            self._log(f"Рыба оставлена: {fish_label} ({confidence:.2f})")
            if self._wait_for_pereves(timeout=2.0):
                self._handle_overweight_after_keep(result)
                return
        else:
            self._log(f"Рыба отпущена: {fish_label} ({confidence:.2f})")
        self._inventory_retry_after = 0.0

    def _has_pending_catch(self) -> bool:
        return bool(self._last_catch_result and self._last_catch_result.visible)

    def _current_catch_result(self, timeout: float = 0.0) -> CatchScreenResult | None:
        if self._last_catch_result and self._last_catch_result.visible:
            return self._last_catch_result
        deadline = time.time() + timeout
        while time.time() <= deadline and not self._stop_event.is_set():
            frame = self.capture.capture()
            if self.game_menu_detector.is_open(frame):
                self._close_game_menu_if_open(frame)
                return None
            result = self.catch_detector.detect(frame)
            if result.visible:
                self._last_catch_result = result
                self._save_catch_panel_snapshot(frame, result)
                return result
            if timeout <= 0:
                break
            self._sleep(CATCH_SCREEN_POLL_SECONDS)
        return None

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
    def _debug_capture_enabled() -> bool:
        return os.environ.get("SONAR_DEBUG_CAPTURE") == "1" or "--debug" in sys.argv

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
        self._do_combined_inventory_tasks(
            do_meal=self.settings.auto_meal if do_meal is None else do_meal,
            do_backpack=self.settings.store_in_backpack,
        )

    def _do_combined_inventory_tasks(self, do_meal: bool, do_backpack: bool) -> None:
        if not do_meal and not do_backpack:
            return
        self.state.phase = BotPhase.INVENTORY
        if not self._open_inventory():
            self._log("Инвентарь не открыт; отложенные действия пропущены")
            return
        if do_meal:
            self._do_meal_actions()
        if do_backpack:
            self._do_backpack_actions()
        self._do_garbage()
        if self.settings.store_in_trunk:
            self._log("Store trunk routine skipped: exact original path is not restored yet")
        self._return_to_fishing()

    def _do_meal_actions(self) -> bool:
        result = self.meal_system.run(use_key=self.settings.use_item_hotkey)
        used_any = bool(result.get("irp") or result.get("donuts") or result.get("cocktails"))
        if used_any:
            self.notification_manager.notify_meal_eaten()
            self._log("Еда/вода использована, жду завершения анимации")
            self._sleep(MEAL_ANIMATION_WAIT_SECONDS)
            self._inventory_retry_after = 0.0
        else:
            self._inventory_retry_after = time.time() + 45.0
        self._log(f"Meal routine: irp={result.get('irp')} donuts={result.get('donuts')} cocktails={result.get('cocktails')}")
        return used_any

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
        self._refresh_triggers()
        if "ad" in self._last_triggers:
            self._log("Смена наживки пропущена: идёт вываживание")
            return False
        if "changed_bait" not in self._last_triggers and "gear" not in self._last_triggers:
            return False
        self.state.phase = BotPhase.RECOVERY
        self._log("Смена наживки: выхожу из режима рыбалки")
        self.input_controller.press_key("esc")
        self._sleep(0.3)
        deadline = time.time() + 5.0
        next_esc_at = 0.0
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers()
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
        self.input_controller.press_key("e")
        self._log("Смена наживки: рыбалка запущена заново")
        self._kickstart_requested = True
        self._sleep(0.3)
        return True

    def _do_store_trunk(self) -> bool:
        if not self.settings.store_in_trunk:
            return False
        self._focus_game()
        self.input_controller.press_key("esc")
        self._sleep(BOT_DELAYS["inventory"])
        self.input_controller.press_key("e")
        self._sleep(BOT_DELAYS["wait"])
        self._log("Store trunk routine executed")
        return True

    def _do_exit_fishing_on_pereves(self) -> None:
        self._handle_overweight_trigger()

    def _wait_for_pereves(self, timeout: float) -> bool:
        deadline = time.time() + timeout
        while time.time() < deadline and not self._stop_event.is_set():
            frame = self.capture.capture()
            detections = self.trigger_monitor.find_detections(frame)
            if "pereves" in detections:
                if not self.inventory_full:
                    self.notification_manager.notify_inventory_full()
                self.inventory_full = True
                self._log("Перевес: места в инвентаре нет")
                return True
            self._sleep(PREPARE_START_POLL_SECONDS)
        return False

    def _handle_overweight_trigger(self) -> None:
        if not self.inventory_full:
            self._log("Перевес: триггер найден, инвентарь помечен как полный")
            self.notification_manager.notify_inventory_full()
        self.inventory_full = True
        self._handle_overweight_action(previous_result=self._last_catch_result)

    def _handle_overweight_after_keep(self, previous_result: CatchScreenResult | None) -> None:
        self.inventory_full = True
        self._handle_overweight_action(previous_result=previous_result)

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
            self._shutdown_game()
            self._stop_event.set()
            return
        self._log("Перевес: останавливаю рыбалку")
        self._stop_event.set()

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
            self._refresh_triggers()
            if any(name in self._last_triggers for name in ("start", "start1", "start2", "wait_tension")):
                return True
            self._sleep(0.1)
        return False

    def _prepare_fishing_start(self, timeout: float = 12.0) -> str | None:
        self._focus_game()
        initial_matches = self.trigger_monitor.find_detections(self.capture.capture())
        if not self._is_fishing_stage_active(initial_matches):
            self.input_controller.press_key("e")
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
        while time.time() < deadline and not self._stop_event.is_set():
            frame = self.capture.capture()
            matches = self.trigger_monitor.find_detections(frame)
            self._last_trigger_matches = matches
            self._last_triggers = {name: match.confidence for name, match in matches.items()}
            if matches and time.time() - last_log_at > 1.0:
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

    def _press_fishing_start(self) -> bool:
        self._focus_game()
        now = time.time()
        if now - self._last_start_pressed_at < 0.3:
            return False
        self._last_start_pressed_at = now
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
        target = "boat" if self.settings.store_in_trunk else "human"
        other = "human" if target == "boat" else "boat"
        target_match = matches.get(target)
        other_match = matches.get(other)
        current = target if target_match else other if other_match else ""
        if current == target:
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

        if anchor and self._click_storage_option_from_screenshot(target, anchor):
            return "progress", anchor
        if target_match and other_match:
            self._click_match(target_match)
            self._log(f"Fish storage option clicked: {target}")
            self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
            return "progress", anchor
        change_match = matches.get("change_boat")
        if change_match:
            self._click_match(change_match)
            self._log(f"Fish storage switch clicked: {current or 'unknown'} -> {target}")
            self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
            return "progress", anchor
        if current and warn:
            self._log(f"Fish storage is {current}; switch button was not found")
        return "missing", anchor

    def _click_storage_option_from_screenshot(self, target: str, anchor: TemplateMatch) -> bool:
        frame = self.capture.capture()
        fresh_matches = self.trigger_monitor.find_detections(frame)
        if "start" not in fresh_matches:
            self._log("Fish storage screenshot click skipped: fishing menu is not confirmed")
            return False
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
            match = matcher.find_best_scaled(
                frame,
                template,
                roi=roi,
                name=name,
                scales=self._storage_template_scales(width, height),
            )
            if match is None:
                continue
            if not self._is_storage_click_safe(match, anchor):
                self._log(f"Fish storage screenshot candidate rejected: {name} ({match.confidence:.2f})")
                continue
            self._click_match(match)
            self._log(f"Fish storage screenshot option clicked: {name} ({match.confidence:.2f})")
            self._sleep_random(STORAGE_SELECTION_CLICK_PAUSE_SECONDS, RANDOM_DELAY_JITTER_SECONDS)
            return True
        self._log(f"Fish storage screenshot option not found: {target}")
        return False

    @staticmethod
    def _is_storage_click_safe(match: TemplateMatch, anchor: TemplateMatch) -> bool:
        return abs(match.x - anchor.x) <= 320 and abs(match.y - anchor.y) <= 420

    @staticmethod
    def _storage_selector_roi(anchor: TemplateMatch, width: int, height: int) -> Rect:
        x = max(anchor.x - 420, 0)
        y = max(anchor.y - 360, 0)
        w = min(700, width - x)
        h = min(520, height - y)
        return Rect(x, y, w, h)

    @staticmethod
    def _storage_template_scales(width: int, height: int) -> tuple[float, ...]:
        base = ((width / 1920) + (height / 1080)) / 2.0
        values = {round(base * factor, 2) for factor in (0.70, 0.82, 0.92, 1.0, 1.08, 1.20, 1.38)}
        values.add(1.0)
        return tuple(sorted(value for value in values if 0.45 <= value <= 2.5))

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
        self.input_controller.press_key(self.settings.inventory_hotkey)
        self._log(f"Инвентарь: нажата клавиша {self.settings.inventory_hotkey}")
        self._sleep(1.0)
        deadline = time.time() + 4.0
        while time.time() < deadline and not self._stop_event.is_set():
            if self._is_inventory_open():
                self._log("Стадия: Инвентарь открыт")
                return True
            self._sleep(0.12)
        self._save_inventory_detection_debug()
        self._inventory_retry_after = time.time() + 8.0
        self._log("Инвентарь не открылся по хоткею")
        return False

    def _return_to_fishing(self) -> None:
        self._focus_game()
        deadline = time.time() + 8.0
        next_inventory_toggle_at = 0.0
        while time.time() < deadline and not self._stop_event.is_set():
            if self._close_game_menu_if_open():
                self._sleep(0.2)
                continue
            if not self._is_inventory_open():
                break
            if time.time() >= next_inventory_toggle_at:
                self.input_controller.press_key(self.settings.inventory_hotkey)
                self._log(f"Инвентарь: закрываю клавишей {self.settings.inventory_hotkey}")
                self._sleep(1.0)
                next_inventory_toggle_at = time.time() + 1.0
            self._sleep(0.12)
        idle_deadline = time.time() + 5.0
        while time.time() < idle_deadline and not self._stop_event.is_set():
            self._refresh_triggers()
            if not self._is_fishing_stage_active(self._last_triggers):
                break
            self._sleep(0.2)
        if self._stop_event.is_set():
            return
        self.input_controller.press_key("e")
        self._log("Возврат к рыбалке: нажата E")

    def _exit_to_idle_before_inventory(self, timeout: float = 12.0) -> bool:
        deadline = time.time() + timeout
        next_esc_at = 0.0
        while time.time() < deadline and not self._stop_event.is_set():
            self._refresh_triggers()
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
                self._sleep_random(2.0, 1.0)
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

    def _try_recover(self, max_retries: int = 3) -> bool:
        self.state.phase = BotPhase.RECOVERY
        self._refresh_triggers()
        if "ad" in self._last_triggers:
            self._log("Recover skipped: идёт вываживание")
            return False
        for attempt in range(max_retries):
            if self._stop_event.is_set():
                return False
            self._log(f"Recover attempt {attempt + 1}/{max_retries}")
            self._focus_game()
            self.input_controller.key_down("w")
            self._sleep(BOT_DELAYS["half"])
            self.input_controller.key_up("w")
            self.input_controller.press_key("e")
            if self._wait_for_start_phase(timeout=BOT_DELAYS["recover_pause"]):
                self.notification_manager.notify_fishing_restored()
                return True
        self.notification_manager.notify_fishing_failed()
        return False

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

    def _capture_screenshot_bytes(self) -> bytes:
        frame = self.capture.capture()
        image = Image.fromarray(frame[:, :, ::-1])
        buffer = io.BytesIO()
        image.save(buffer, format="PNG")
        return buffer.getvalue()
