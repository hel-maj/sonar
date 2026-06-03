from __future__ import annotations

import importlib.abc
import importlib.machinery
import random
import sys
import time

from sonar.core.state import BotPhase
from sonar.vision.matching import TemplateMatch

BAIT_RESTART_ATTEMPTS = 10
BAIT_RESTART_INTERVAL_SECONDS = 1.5


class _BotLoader(importlib.abc.Loader):
    def __init__(self, wrapped: importlib.abc.Loader) -> None:
        self.wrapped = wrapped

    def create_module(self, spec):
        if hasattr(self.wrapped, "create_module"):
            return self.wrapped.create_module(spec)
        return None

    def exec_module(self, module) -> None:
        self.wrapped.exec_module(module)
        apply_to_module(module)


class _BotFinder(importlib.abc.MetaPathFinder):
    def find_spec(self, fullname, path, target=None):
        if fullname != "sonar.fishing.bot":
            return None
        try:
            sys.meta_path.remove(self)
            spec = importlib.machinery.PathFinder.find_spec(fullname, path)
        finally:
            sys.meta_path.insert(0, self)
        if spec is not None and spec.loader is not None:
            spec.loader = _BotLoader(spec.loader)
        return spec


def install() -> None:
    module = sys.modules.get("sonar.fishing.bot")
    if module is not None:
        apply_to_module(module)
        return
    if any(isinstance(finder, _BotFinder) for finder in sys.meta_path):
        return
    sys.meta_path.insert(0, _BotFinder())


def apply_to_module(bot_module) -> None:
    if getattr(bot_module, "_SONAR_FISHING_ADJUSTMENTS_APPLIED", False):
        return
    bot_module._SONAR_FISHING_ADJUSTMENTS_APPLIED = True
    bot_module.BAIT_RESTART_ATTEMPTS = BAIT_RESTART_ATTEMPTS
    bot_module.BAIT_RESTART_INTERVAL_SECONDS = BAIT_RESTART_INTERVAL_SECONDS
    bot_module.DEBUG_CAPTURE_WATCHED_FISH_IDS = frozenset({"roach_vobla"})
    bot_module.FishingBot._restart_fishing_after_bait_change = _restart_fishing_after_bait_change
    bot_module.FishingBot._do_change_bait = _do_change_bait
    bot_module.FishingBot._prepare_fishing_start = _prepare_fishing_start
    bot_module.FishingBot._is_trophy_quality = staticmethod(_is_trophy_quality)
    bot_module.FishingBot._press_fishing_start = _wrap_press_fishing_start(bot_module.FishingBot._press_fishing_start)
    bot_module.FishingBot._save_debug_catch_snapshots = _wrap_save_debug_catch_snapshots(
        bot_module.FishingBot._save_debug_catch_snapshots,
        bot_module,
    )


def _restart_fishing_after_bait_change(self) -> bool:
    import sonar.fishing.bot as bot_module

    for attempt in range(1, bot_module.BAIT_RESTART_ATTEMPTS + 1):
        self._focus_game()
        if self._press_fishing_entry("Смена наживки"):
            self._log(f"Смена наживки: попытка входа в рыбалку {attempt}/{bot_module.BAIT_RESTART_ATTEMPTS}")
        self._sleep(bot_module.BAIT_RESTART_INTERVAL_SECONDS)
        self._refresh_triggers()
        if self._is_fishing_stage_active(self._last_triggers):
            self._log("Смена наживки: рыбалка запущена заново")
            self._kickstart_requested = True
            return True
    self._log(f"Автостоп: {bot_module.STOP_REASON_NO_STAGE}")
    self._stop_from_brain(bot_module.STOP_REASON_NO_STAGE)
    return False


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
    self._notify_bait_tired()
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
    return self._restart_fishing_after_bait_change()


def _prepare_fishing_start(self, timeout: float = 12.0) -> str | None:
    import sonar.fishing.bot as bot_module

    self._focus_game()
    initial_matches = self.trigger_monitor.find_detections(self.capture.capture())
    if not self._is_fishing_stage_active(initial_matches):
        self._press_fishing_entry("Вход в рыбалку")
        self._sleep_random(bot_module.START_MENU_OPEN_DELAY_SECONDS, bot_module.RANDOM_DELAY_JITTER_SECONDS)
    deadline = time.time() + timeout
    clicked: set[str] = set()
    last_log_at = 0.0
    storage_warning_logged = False
    storage_retry_at = 0.0
    storage_started_at = 0.0
    storage_pending = False
    storage_selector_opened = False
    storage_anchor: TemplateMatch | None = None
    storage_block_logged = False
    tackle_checked = False
    while time.time() < deadline and not self._stop_event.is_set():
        frame = self.capture.capture()
        matches = self.trigger_monitor.find_detections(frame)
        self._last_trigger_matches = matches
        self._last_triggers = {name: match.confidence for name, match in matches.items()}
        self._mark_storage_from_matches(matches)
        if matches and time.time() - last_log_at > 1.0:
            self._log(f"Pre-cast detections: {self._format_precise_triggers(matches)}")
            last_log_at = time.time()
        if not any(name in matches for name in ("start", "start1", "start2", "wait_tension", "ad")):
            self._sleep(bot_module.PREPARE_START_POLL_SECONDS)
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
        if "storage" not in clicked and "start" in matches:
            if storage_started_at == 0.0:
                storage_started_at = time.time()
            if time.time() >= storage_retry_at:
                storage_retry_at = (
                    time.time()
                    + bot_module.STORAGE_SELECTION_RETRY_SECONDS
                    + random.uniform(0.0, bot_module.RANDOM_DELAY_JITTER_SECONDS)
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
                    storage_block_logged = False
                if storage_result == "opened":
                    storage_pending = True
                    storage_selector_opened = True
                    self._sleep_random(bot_module.STORAGE_SELECTION_CLICK_PAUSE_SECONDS, bot_module.RANDOM_DELAY_JITTER_SECONDS)
                    continue
                if storage_result == "progress":
                    storage_pending = True
                    self._sleep_random(bot_module.STORAGE_SELECTION_CLICK_PAUSE_SECONDS, bot_module.RANDOM_DELAY_JITTER_SECONDS)
                    continue
                if storage_result == "missing":
                    storage_warning_logged = True
            if "storage" not in clicked:
                if time.time() - storage_started_at <= bot_module.STORAGE_SELECTION_GIVE_UP_SECONDS:
                    if storage_pending or "boat" in matches or "human" in matches:
                        self._sleep(bot_module.PREPARE_START_POLL_SECONDS)
                        continue
                elif not storage_block_logged:
                    storage_block_logged = True
                    self._log("Выбор снастей: хранилище не выбрано, продолжаю заброс")
        if "start" in matches and "start" not in clicked:
            if self._press_fishing_start():
                clicked.add("start")
            self._sleep(bot_module.PREPARE_START_POLL_SECONDS)
            continue
        if ("changed_bait" in matches or "gear" in matches) and "change_bait" not in clicked:
            if self._do_change_bait():
                clicked.add("change_bait")
                self._sleep_random(bot_module.STORAGE_SELECTION_CLICK_PAUSE_SECONDS, bot_module.RANDOM_DELAY_JITTER_SECONDS)
                continue
        self._sleep(bot_module.PREPARE_START_POLL_SECONDS)
    return None


def _is_trophy_quality(quality: str | None) -> bool:
    return bool(quality and "троф" in quality.lower())


def _wrap_press_fishing_start(original):
    def patched(self) -> bool:
        return original(self)
    return patched

def _wrap_save_debug_catch_snapshots(original, bot_module):
    def patched(
        self,
        *,
        result,
        fish_id,
        fish_label,
        weight,
        quality,
        xp,
        confidence,
        stage_log_line,
        catch_log_line,
        crop=None,
    ) -> None:
        original(
            self,
            result=result,
            fish_id=fish_id,
            fish_label=fish_label,
            weight=weight,
            quality=quality,
            xp=xp,
            confidence=confidence,
            stage_log_line=stage_log_line,
            catch_log_line=catch_log_line,
            crop=crop,
        )
        if fish_id != "roach_vobla":
            return
        frame = self.capture.capture()
        if frame is None:
            return
        self._write_debug_catch_snapshot(
            directory=bot_module.DEBUG_CAPTURE_UNEXPECTED_FISH_DIR,
            reason="unexpected_fish",
            crop=frame,
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
    return patched
