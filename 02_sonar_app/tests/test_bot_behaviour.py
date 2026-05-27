from __future__ import annotations

import threading
import time
from datetime import datetime

import numpy as np

import sonar.fishing.bot as bot_module
from sonar.config.models import FishingSettings
from sonar.core.state import BotPhase, BotState
from sonar.fishing.bot import FishingBot
from sonar.fishing.item_info import ItemInfo
from sonar.fishing.meal_system import MealItemMatch, MealItemSnapshot
from sonar.fishing.player_status import PlayerStatus
from sonar.fishing.catch_screen import CatchScreenResult
from sonar.fishing.tackle_detection import TACKLE_SLOTS, TackleItemCount, TackleScanResult
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatch


class DummyInput:
    def __init__(self) -> None:
        self.keys: list[str] = []

    def press_key(self, key: str) -> None:
        self.keys.append(key)

    def release_all_keys(self) -> None:
        self.keys.append("release_all")


class DummyCapture:
    def capture(self):
        return object()


class DummyMatch:
    confidence = 1.0




class FakeMealSystem:
    def __init__(self) -> None:
        self.frames_seen = 0
        self.backpack_moves = 0
        self.inventory_checks = 0

    def check_needs_meal(self, _frame, **_kwargs) -> bool:
        return True

    def find_food_in_inventory(self, _frame):
        self.inventory_checks += 1
        if self.inventory_checks == 1:
            return None
        return MealItemMatch("irp", TemplateMatch(20, 30, 1.0, 10, 10, "irp"), "inventory")

    def find_food_in_backpack(self, _frame):
        return MealItemMatch("irp", TemplateMatch(5, 6, 1.0, 10, 10, "irp"), "backpack")

    def move_item_from_backpack(self, _match, move_key: str = "r") -> bool:
        del move_key
        self.backpack_moves += 1
        return True

    def consume_item(self, _x: int, _y: int, item_name: str, use_key: str = "e") -> MealItemSnapshot:
        del use_key
        return MealItemSnapshot(item_name, "ИРП Армии США", "ИРП Армии США", "1.0")


def make_meal_loop_bot(meal_system: FakeMealSystem):
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings()
    bot._stop_event = threading.Event()
    bot.meal_system = meal_system
    bot.capture = DummyCapture()
    bot._prepare_meal_system = lambda: None
    bot._inventory_retry_after = 0.0
    bot._log_messages = []
    bot._ui_events = []
    bot._notifications = []
    bot._log = bot._log_messages.append
    bot._sleep = lambda _seconds: None
    bot._open_inventory = lambda: True
    bot._notify_meal_consumed = lambda snapshot: bot._notifications.append(snapshot.item_title)
    bot._publish_ui_event = lambda title, **kwargs: bot._ui_events.append((title, kwargs))
    return bot


class SequenceTriggerMonitor:
    def __init__(self, steps: list[dict[str, DummyMatch]]) -> None:
        self.steps = iter(steps)

    def find_detections(self, frame) -> dict[str, DummyMatch]:
        return next(self.steps, {})


class DummyCatchDetector:
    def detect(self, frame):
        return CatchScreenResult(False)

    def crop_panel(self, frame, result):
        return frame


class ClosedDetector:
    def is_open(self, frame) -> bool:
        return False


class ClosedMenuDetector:
    def detect(self, frame):
        return None


def make_tackle_scan(counts: dict[str, int]) -> TackleScanResult:
    return TackleScanResult(
        items=tuple(TackleItemCount(slot.key, slot.name, counts.get(slot.key, 1)) for slot in TACKLE_SLOTS),
        obscured=False,
        row_rect=Rect(0, 0, 1, 1),
        scanned_at=datetime.now(),
    )


def make_empty_tackle_scan() -> TackleScanResult:
    return make_tackle_scan({slot.key: 0 for slot in TACKLE_SLOTS})


def make_change_bait_bot(trigger_steps: list[dict[str, float]], *, auto_change_bait: bool = True):
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(auto_change_bait=auto_change_bait)
    bot.input_controller = DummyInput()
    bot.state = BotState()
    bot._stop_event = threading.Event()
    bot._last_triggers = {}
    bot._last_change_bait_at = 0.0
    bot._kickstart_requested = False
    bot._focus_game = lambda: True
    bot._sleep = lambda seconds: None
    bot._log = lambda message: None
    steps = iter(trigger_steps)

    def refresh_triggers() -> None:
        bot._last_triggers = next(steps, {})

    bot._refresh_triggers = refresh_triggers
    return bot


def test_auto_change_bait_restarts_fishing_from_waiting_state():
    bot = make_change_bait_bot([{"changed_bait": 1.0, "start2": 1.0}, {}, {"start2": 1.0}])

    assert bot._do_change_bait() is True
    assert bot.input_controller.keys == ["esc", "e"]
    assert bot._kickstart_requested is True


def test_auto_change_bait_never_exits_reeling():
    bot = make_change_bait_bot([{"changed_bait": 1.0, "ad": 1.0}])

    assert bot._do_change_bait() is False
    assert bot.input_controller.keys == []


def test_prepare_start_does_not_treat_bait_notice_as_active_stage():
    bot = FishingBot.__new__(FishingBot)
    bot.input_controller = DummyInput()
    bot.settings = FishingSettings()
    bot.capture = DummyCapture()
    bot.trigger_monitor = SequenceTriggerMonitor(
        [
            {"changed_bait": DummyMatch()},
            {"start": DummyMatch()},
            {"start1": DummyMatch()},
        ]
    )
    bot._stop_event = threading.Event()
    bot._last_trigger_matches = {}
    bot._last_triggers = {}
    bot._last_start_pressed_at = 0.0
    bot._focus_game = lambda: True
    bot._sleep = lambda seconds: None
    bot._sleep_random = lambda minimum, extra: None
    bot._log = lambda message: None
    bot._check_tackle_before_start = lambda frame: True
    bot._ensure_storage_selection = lambda matches, **kwargs: ("done", None)

    assert bot._prepare_fishing_start(timeout=1.0) == "casting"
    assert bot.input_controller.keys == ["e", "e"]


def test_chat_pause_keeps_running_state_and_releases_keys():
    bot = FishingBot.__new__(FishingBot)
    bot.input_controller = DummyInput()
    bot.state = BotState(running=True)
    bot._chat_pause_event = threading.Event()
    bot._no_stage_since = 1.0
    logs: list[str] = []
    bot._log = logs.append

    bot.pause_for_chat(True)

    assert bot.state.running is True
    assert bot.state.detected_stage == "Чат"
    assert bot.is_paused_for_chat() is True
    assert bot.input_controller.keys == ["release_all"]

    bot.pause_for_chat(False)

    assert bot.state.running is True
    assert bot.is_paused_for_chat() is False
    assert bot._no_stage_since is None
    assert bot._kickstart_requested is True


def test_chat_pause_can_resume_without_kickstart_after_failed_open():
    bot = FishingBot.__new__(FishingBot)
    bot.input_controller = DummyInput()
    bot.state = BotState(running=True)
    bot._chat_pause_event = threading.Event()
    bot._chat_pause_event.set()
    bot._no_stage_since = 1.0
    bot._kickstart_requested = False
    bot._log = lambda message: None

    bot.pause_for_chat(False, restart_on_resume=False)

    assert bot.is_paused_for_chat() is False
    assert bot._kickstart_requested is False


def test_player_status_threshold_can_request_meal_outside_reeling():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(restore_food_from=90, restore_water_from=90, restore_health_from=50)
    bot._last_player_status = PlayerStatus(food=89, water=100, health=100, source="memory")
    bot._last_player_status_at = time.time()

    assert bot._status_indicates_needs_meal("start2") is True


def test_player_status_threshold_is_ignored_during_reeling():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(restore_food_from=90, restore_water_from=90, restore_health_from=50)
    bot._last_player_status = PlayerStatus(food=1, water=1, health=1, source="memory")
    bot._last_player_status_at = time.time()

    assert bot._status_indicates_needs_meal("ad") is False


def test_player_status_scan_request_is_queued_during_reeling():
    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState(running=True, phase=BotPhase.REELING, detected_stage="Вываживание")
    bot._last_triggers = {"ad": 1.0}
    bot._last_catch_result = None
    bot._log_messages = []
    bot._log = bot._log_messages.append

    ok, message = bot.request_player_status_scan()

    assert ok is True
    assert "после вываживания" in message
    assert bot._player_status_scan_requested is True


def test_player_status_scan_request_waits_while_stage_is_reeling():
    bot = FishingBot.__new__(FishingBot)
    bot._player_status_scan_requested = True

    assert bot._handle_player_status_scan_request("ad") is False
    assert bot._player_status_scan_requested is True


def test_player_status_scan_request_is_queued_when_running():
    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState(running=True, phase=BotPhase.IDLE, detected_stage="Ожидание поклёвки")
    bot._last_triggers = {"start2": 1.0}
    bot._last_catch_result = None
    bot._log_messages = []
    bot._log = bot._log_messages.append

    ok, message = bot.request_player_status_scan()

    assert ok is True
    assert "очередь" in message
    assert bot._player_status_scan_requested is True


def make_chat_exit_bot(trigger_steps: list[dict[str, DummyMatch]], *, running: bool = False):
    bot = FishingBot.__new__(FishingBot)
    bot.input_controller = DummyInput()
    bot.capture = DummyCapture()
    bot.trigger_monitor = SequenceTriggerMonitor(trigger_steps)
    bot.game_menu_detector = ClosedMenuDetector()
    bot.inventory_detector = ClosedDetector()
    bot.catch_detector = DummyCatchDetector()
    bot.settings = FishingSettings()
    bot.state = BotState(running=running)
    bot._stop_event = threading.Event()
    if not running:
        bot._stop_event.set()
    bot._last_trigger_matches = {}
    bot._last_triggers = {}
    bot._last_catch_result = None
    bot._last_menu_close_at = 0.0
    bot._focus_game = lambda: True
    bot._publish_stage = lambda label: None
    bot._chat_mode_sleep = lambda seconds: None
    bot._log = lambda message: None
    return bot


def test_prepare_chat_mode_exits_fishing_stage_even_when_bot_is_not_running():
    bot = make_chat_exit_bot([{"start2": DummyMatch()}, {}], running=False)

    ok, message = bot.prepare_for_chat_mode(timeout=0.2)

    assert ok is True
    assert message == "Персонаж выведен из рыбалки"
    assert bot.input_controller.keys == ["release_all", "esc"]


def test_prepare_chat_mode_does_not_press_escape_when_already_idle():
    bot = make_chat_exit_bot([{}], running=False)

    ok, message = bot.prepare_for_chat_mode(timeout=0.2)

    assert ok is True
    assert message == "Персонаж выведен из рыбалки"
    assert bot.input_controller.keys == ["release_all"]


def test_auto_change_bait_setting_disables_restart():
    bot = make_change_bait_bot([{"changed_bait": 1.0}], auto_change_bait=False)

    assert bot._do_change_bait() is False
    assert bot.input_controller.keys == []


def test_auto_stop_when_no_stage_is_visible_for_timeout():
    bot = FishingBot.__new__(FishingBot)
    bot._no_stage_since = time.time() - bot_module.AUTO_STOP_TIMEOUT_SECONDS - 1.0
    bot._has_pending_catch = lambda: False
    logs: list[str] = []
    reasons: list[str] = []
    bot._log = logs.append
    bot._stop_from_brain = reasons.append

    assert bot._stop_if_no_stage_timed_out(None, needs_meal=False) is True
    assert reasons == [bot_module.STOP_REASON_NO_STAGE]
    assert any(bot_module.STOP_REASON_NO_STAGE in message for message in logs)


def test_meal_can_interrupt_non_reeling_stages_when_retry_is_due():
    bot = FishingBot.__new__(FishingBot)
    bot._inventory_retry_after = time.time() - 1.0

    assert bot._should_handle_meal_now("start2", needs_meal=True) is True
    assert bot._should_handle_meal_now("start1", needs_meal=True) is True
    assert bot._should_handle_meal_now("start", needs_meal=True) is True
    assert bot._should_handle_meal_now(None, needs_meal=True) is True
    assert bot._should_handle_meal_now("ad", needs_meal=True) is False

    bot._inventory_retry_after = time.time() + 10.0
    assert bot._should_handle_meal_now("start2", needs_meal=True) is False
    assert bot._should_handle_meal_now("start2", needs_meal=False) is False


def test_auto_stop_when_start_cannot_find_fishing_stage():
    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState()
    bot._start_attempt_since = time.time() - bot_module.AUTO_STOP_TIMEOUT_SECONDS - 1.0
    bot._prepare_fishing_start = lambda: None
    logs: list[str] = []
    reasons: list[str] = []
    bot._log = logs.append
    bot._stop_from_brain = reasons.append

    bot._do_casting()

    assert reasons == [bot_module.STOP_REASON_START_FAILED]
    assert any(bot_module.STOP_REASON_START_FAILED in message for message in logs)


def test_reeling_walking_guard_stops_when_fish_state_is_problematic_and_stage_is_gone():
    bot = FishingBot.__new__(FishingBot)
    bot._last_triggers = {}
    bot._last_catch_result = None
    bot._has_pending_catch = lambda: False

    assert bot._should_stop_for_reeling_walking_guard("target_search") is True


def test_reeling_walking_guard_keeps_running_while_reeling_stage_is_visible():
    bot = FishingBot.__new__(FishingBot)
    bot._last_triggers = {"ad": 1.0}
    bot._last_catch_result = None
    bot._has_pending_catch = lambda: False

    assert bot._should_stop_for_reeling_walking_guard("target_search") is False


def test_reeling_walking_guard_does_not_stop_on_known_interruption_state():
    bot = FishingBot.__new__(FishingBot)
    reasons: list[str] = []
    bot._last_triggers = {}
    bot._has_pending_catch = lambda: False
    bot._detect_reeling_interruption_state = lambda: "Выбор снастей"
    bot._try_return_to_fishing_from_idle = lambda: False
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append

    assert bot._check_reeling_walking_guard("target_search") is False
    assert reasons == []


def test_reeling_walking_guard_does_not_stop_when_idle_returns_to_fishing():
    bot = FishingBot.__new__(FishingBot)
    reasons: list[str] = []
    bot._last_triggers = {}
    bot._has_pending_catch = lambda: False
    bot._detect_reeling_interruption_state = lambda: None
    bot._try_return_to_fishing_from_idle = lambda: True
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append

    assert bot._check_reeling_walking_guard("target_search") is False
    assert reasons == []


def test_reeling_walking_guard_stops_when_no_state_and_idle_cannot_return():
    bot = FishingBot.__new__(FishingBot)
    reasons: list[str] = []
    bot._last_triggers = {}
    bot._has_pending_catch = lambda: False
    bot._detect_reeling_interruption_state = lambda: None
    bot._try_return_to_fishing_from_idle = lambda: False
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append

    assert bot._check_reeling_walking_guard("target_search") is True
    assert reasons == [bot_module.STOP_REASON_WALKING_GUARD]


def test_restore_reeling_focus_uses_force_focus_while_bot_is_running():
    bot = FishingBot.__new__(FishingBot)
    calls: list[str] = []
    bot._force_focus_game = lambda: calls.append("focus") or True

    assert bot._restore_reeling_focus(8.0, now=10.0) == 10.0
    assert calls == ["focus"]


def test_restore_reeling_focus_is_throttled():
    bot = FishingBot.__new__(FishingBot)
    calls: list[str] = []
    bot._force_focus_game = lambda: calls.append("focus") or True

    assert bot._restore_reeling_focus(9.5, now=10.0) == 9.5
    assert calls == []


def test_reeling_idle_return_presses_e_and_accepts_new_fishing_stage():
    bot = FishingBot.__new__(FishingBot)
    bot.capture = DummyCapture()
    bot.game_menu_detector = ClosedDetector()
    bot.inventory_detector = ClosedDetector()
    bot.catch_detector = DummyCatchDetector()
    bot.trigger_monitor = SequenceTriggerMonitor([{}, {"start": DummyMatch()}])
    bot.input_controller = DummyInput()
    bot._stop_event = threading.Event()
    bot._last_triggers = {}
    bot._last_trigger_matches = {}
    bot._last_catch_result = None
    bot._save_catch_panel_snapshot = lambda frame, result: None
    bot._publish_stage = lambda label: None
    bot._focus_game = lambda: True
    bot._sleep = lambda seconds: None
    bot._log = lambda message: None

    assert bot._try_return_to_fishing_from_idle(timeout=0.1) is True
    assert bot.input_controller.keys == ["e"]


def test_missing_hook_stops_by_default_with_tackle_reason():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings()
    reasons: list[str] = []
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append

    handled = bot._handle_tackle_depletion(make_tackle_scan({"hook": 0}))

    assert handled is True
    assert reasons == ["Закончились крючки/поводки"]


def test_missing_hook_can_be_allowed_by_setting():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(fish_without_leader=True)
    reasons: list[str] = []
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append

    handled = bot._handle_tackle_depletion(make_tackle_scan({"hook": 0}))

    assert handled is False
    assert reasons == []


def test_missing_net_is_allowed_by_default():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings()
    reasons: list[str] = []
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append

    handled = bot._handle_tackle_depletion(make_tackle_scan({"net": 0}))

    assert handled is False
    assert reasons == []


def test_empty_tackle_scan_is_retried_instead_of_missing_rod_stop():
    class SequenceTackleDetector:
        def __init__(self) -> None:
            self.scans = iter([make_empty_tackle_scan(), make_tackle_scan({})])

        def detect(self, frame):
            return next(self.scans)

    bot = FishingBot.__new__(FishingBot)
    bot.capture = DummyCapture()
    bot.tackle_detector = SequenceTackleDetector()
    bot._stop_event = threading.Event()
    bot._sleep = lambda seconds: None
    bot._log = lambda message: None
    bot._stop_from_brain = lambda reason: None
    bot._store_tackle_scan = lambda scan, frame: None

    scan = bot._read_tackle_until_clear(object())

    assert scan is not None
    assert scan.count_for("rod") == 1


def test_active_stage_tackle_scan_stores_waiting_stage_counts():
    class Detector:
        def detect(self, frame):
            return make_tackle_scan({"bait": 7})

    bot = FishingBot.__new__(FishingBot)
    stored: list[TackleScanResult] = []
    bot.tackle_detector = Detector()
    bot.capture = DummyCapture()
    bot._last_active_tackle_scan_at = {}
    bot._store_tackle_scan = lambda scan, frame: stored.append(scan)
    bot._log = lambda message: None

    bot._scan_tackle_for_active_stage("start2", object())

    assert stored
    assert stored[0].count_for("bait") == 7


def test_tackle_depletion_is_rechecked_before_stop():
    bot = FishingBot.__new__(FishingBot)
    scans = iter([make_tackle_scan({"rod": 0}), make_tackle_scan({})])
    reasons: list[str] = []
    bot.settings = FishingSettings()
    bot._stop_event = threading.Event()
    bot._read_tackle_until_clear = lambda frame=None: next(scans)
    bot._sleep = lambda seconds: None
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append

    assert bot._check_tackle_before_start() is True
    assert reasons == []


def test_tackle_depletion_stops_after_confirmation():
    bot = FishingBot.__new__(FishingBot)
    scans = iter([make_tackle_scan({"rod": 0}), make_tackle_scan({"rod": 0}), make_tackle_scan({"rod": 0})])
    reasons: list[str] = []
    bot.settings = FishingSettings()
    bot._stop_event = threading.Event()
    bot._read_tackle_until_clear = lambda frame=None: next(scans)
    bot._sleep = lambda seconds: None
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append

    assert bot._check_tackle_before_start() is False
    assert reasons == [bot._find_tackle_depletion(make_tackle_scan({"rod": 0}))[1]]


def test_generic_equipment_action_can_close_game():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(equipment_depleted_action="exit_game")
    calls: list[str] = []
    bot._log = lambda message: None
    bot._shutdown_game = lambda: calls.append("shutdown_game")
    bot._stop_from_brain = lambda reason: calls.append(reason)

    handled = bot._handle_tackle_depletion(make_tackle_scan({"line": 0}))

    assert handled is True
    assert calls == ["shutdown_game", "Кончилась леска"]


def test_debug_capture_writes_only_when_debug_enabled(tmp_path, monkeypatch):
    bot = FishingBot.__new__(FishingBot)
    bot.capture = DummyCapture()
    bot.capture.capture = lambda: np.zeros((32, 32, 3), dtype=np.uint8)
    bot.catch_detector = DummyCatchDetector()
    monkeypatch.setattr(bot_module, "DEBUG_CAPTURE_UNEXPECTED_FISH_DIR", tmp_path / "unexpected")
    monkeypatch.setattr(bot_module, "DEBUG_CAPTURE_OVER_15KG_DIR", tmp_path / "over_15")
    monkeypatch.setattr(bot_module, "DEBUG_CAPTURE_TROPHY_DIR", tmp_path / "trophy")
    monkeypatch.setattr(bot_module, "DEBUG_CAPTURE_ALL_CATCHES_DIR", tmp_path / "all")
    result = CatchScreenResult(True, fish_id="albula", weight_kg=1.0, weight_text="1.00")

    bot._save_debug_catch_snapshots(
        result=result,
        fish_id="albula",
        fish_label="Albula",
        weight="1.00",
        quality="unknown",
        xp="unknown",
        confidence=0.95,
        stage_log_line="stage",
        catch_log_line="catch",
    )
    assert not list(tmp_path.rglob("*.png"))

    monkeypatch.setenv("SONAR_DEBUG_CAPTURE", "1")
    bot._save_debug_catch_snapshots(
        result=result,
        fish_id="albula",
        fish_label="Albula",
        weight="1.00",
        quality="Трофейная",
        xp="unknown",
        confidence=0.95,
        stage_log_line="stage",
        catch_log_line="catch",
    )

    assert len(list((tmp_path / "unexpected").glob("*.png"))) == 1
    assert len(list((tmp_path / "trophy").glob("*.png"))) == 1
    assert len(list((tmp_path / "all").glob("*.png"))) == 1
    assert (tmp_path / "all" / "metadata.csv").exists()
    assert (tmp_path / "unexpected" / "metadata.csv").exists()


def test_reeling_loss_debug_log_is_saved_in_debug_mode(tmp_path, monkeypatch):
    bot = FishingBot.__new__(FishingBot)
    logs: list[str] = []
    bot._log = logs.append
    monkeypatch.setenv("SONAR_DEBUG_MODE", "1")
    monkeypatch.setattr(bot_module, "DEBUG_CAPTURE_REELING_LOSS_DIR", tmp_path / "reeling")

    records = bot._new_reeling_debug_log()
    bot._append_reeling_debug_log(records, "state", action="target_search")
    path = bot._save_reeling_debug_log(records, "ad_stage_ended")

    assert path is not None
    assert path.exists()
    assert "target_search" in path.read_text(encoding="utf-8")
    assert any("debug-лог срыва" in message for message in logs)


def test_debug_capture_writes_meal_item_info_crop_and_screen(tmp_path, monkeypatch):
    monkeypatch.setattr(bot_module, "DEBUG_CAPTURE_MEAL_DIR", tmp_path / "meal")
    monkeypatch.setenv("SONAR_DEBUG_CAPTURE", "1")
    bot = FishingBot.__new__(FishingBot)
    snapshot = MealItemSnapshot(
        key="irp",
        display_name="ИРП Армии США",
        item_title="ИРП Армии США",
        item_weight="0.6",
        image=np.zeros((8, 12, 3), dtype=np.uint8),
        screen_image=np.zeros((24, 32, 3), dtype=np.uint8),
        item_info=ItemInfo(Rect(0, 0, 12, 8), title="ИРП Армии США", satiety_change="+80", thirst_change="+75", text="ИРП Армии США"),
        player_status=PlayerStatus(food=96, water=71, health=47, source="screenshot"),
    )

    bot._save_debug_meal_snapshot(snapshot)

    png_files = list((tmp_path / "meal").glob("*.png"))
    assert len(png_files) == 2
    assert any(path.name.endswith("_item_info.png") for path in png_files)
    assert any(path.name.endswith("_screen.png") for path in png_files)
    csv_text = (tmp_path / "meal" / bot_module.DEBUG_CAPTURE_CSV_NAME).read_text(encoding="utf-8")
    assert "item_info_screenshot" in csv_text
    assert "screen_screenshot" in csv_text
    assert "ИРП Армии США" in csv_text
    assert "96" in csv_text
    assert "71" in csv_text
    assert "47" in csv_text


def test_debug_capture_writes_meal_screen_even_without_item_info_crop(tmp_path, monkeypatch):
    monkeypatch.setattr(bot_module, "DEBUG_CAPTURE_MEAL_DIR", tmp_path / "meal")
    monkeypatch.setenv("SONAR_DEBUG_CAPTURE", "1")
    bot = FishingBot.__new__(FishingBot)
    snapshot = MealItemSnapshot(
        key="irp",
        display_name="ИРП Армии США",
        item_title="ИРП Армии США",
        item_weight="",
        screen_image=np.zeros((24, 32, 3), dtype=np.uint8),
    )

    bot._save_debug_meal_snapshot(snapshot)

    png_files = list((tmp_path / "meal").glob("*.png"))
    assert len(png_files) == 1
    assert png_files[0].name.endswith("_screen.png")
    csv_text = (tmp_path / "meal" / bot_module.DEBUG_CAPTURE_CSV_NAME).read_text(encoding="utf-8")
    assert "screen_screenshot" in csv_text
    assert "ИРП Армии США" in csv_text


def test_catch_screen_text_overrides_reeling_image_guess():
    bot = FishingBot.__new__(FishingBot)
    logs: list[str] = []
    clicks: list[object] = []
    records: list[tuple[str | None, str, float | None, bool, str]] = []
    release_button = object()
    result = CatchScreenResult(
        True,
        release_button=release_button,
        fish_id="ruster",
        fish_confidence=0.95,
        fish_text="Рустер",
        quality_text="Хороший улов",
        weight_kg=2.29,
        weight_text="2.29",
        xp_current=11136,
        is_max_level=True,
    )

    class Config:
        def get_fish_to_keep(self):
            return set()

    class Stats:
        def totals(self):
            return {}

        def record_catch(self, fish_id, fish_label, weight_kg, *, kept, catch_size):
            records.append((fish_id, fish_label, weight_kg, kept, catch_size))

    class Notifications:
        def notify_caught_fish(self, *args, **kwargs):
            return None

    bot.config_manager = Config()
    bot.session_stats = Stats()
    bot.notification_manager = Notifications()
    bot.state = BotState()
    bot.inventory_full = False
    bot._last_catch_result = None
    bot._current_catch_result = lambda timeout: result
    bot._sleep_random = lambda minimum, extra: None
    bot._click_match = clicks.append
    bot._log = logs.append
    bot._capture_catch_panel = lambda catch_result: None
    bot._encode_png_bytes = lambda image: None
    bot._save_debug_catch_snapshots = lambda **kwargs: None
    bot._publish_catch_ui_event = lambda **kwargs: None

    bot._do_fish_catch("krasny_gorbyl", 0.99)

    assert clicks == [release_button]
    assert records == [("ruster", "Рустер", 2.29, False, "Хороший улов")]
    assert any("Улов: рыба=Рустер id=ruster вес=2.29" in log for log in logs)
    assert not any("Улов: рыба=Красный горбыль" in log for log in logs)


def test_catch_snapshot_wrapper_accepts_crop_before_result_click(monkeypatch):
    bot = FishingBot.__new__(FishingBot)
    clicks: list[object] = []
    keep_button = object()
    result = CatchScreenResult(
        True,
        keep_button=keep_button,
        fish_id="krasny_gorbyl",
        fish_confidence=0.95,
        fish_text="Красный горбыль",
        quality_text="Трофейная",
        weight_kg=7.21,
        weight_text="7.21",
        xp_current=11138,
    )

    class Config:
        def get_fish_to_keep(self):
            return {"krasny_gorbyl"}

    class Stats:
        def totals(self):
            return {}

        def record_catch(self, *args, **kwargs):
            return None

    class Notifications:
        def notify_caught_fish(self, *args, **kwargs):
            return None

    bot.config_manager = Config()
    bot.session_stats = Stats()
    bot.notification_manager = Notifications()
    bot.capture = DummyCapture()
    bot.capture.capture = lambda: np.zeros((32, 32, 3), dtype=np.uint8)
    bot.catch_detector = DummyCatchDetector()
    bot.state = BotState()
    bot.inventory_full = False
    bot._last_catch_result = None
    bot._current_catch_result = lambda timeout: result
    bot._sleep_random = lambda minimum, extra: None
    bot._click_match = clicks.append
    bot._log = lambda message: None
    bot._publish_catch_ui_event = lambda **kwargs: None
    bot._wait_for_pereves = lambda timeout: False
    monkeypatch.delenv("SONAR_DEBUG_CAPTURE", raising=False)

    bot._do_fish_catch(None, 0.0)

    assert clicks == [keep_button]


def test_continue_after_hook_does_not_start_reeling_without_confirmed_stage():
    bot = FishingBot.__new__(FishingBot)
    bot._stop_event = threading.Event()
    bot._log = lambda message: None
    reeling_calls: list[bool] = []
    bot._run_reeling_module = lambda: reeling_calls.append(True) or (None, 0.0)

    bot._continue_after_hook(None)

    assert reeling_calls == []


def test_continue_after_hook_starts_reeling_only_for_confirmed_reeling_stage():
    bot = FishingBot.__new__(FishingBot)
    bot._stop_event = threading.Event()
    bot._has_pending_catch = lambda: False
    bot._do_fish_catch = lambda *args: None
    bot._log = lambda message: None
    reeling_calls: list[bool] = []
    bot._run_reeling_module = lambda: reeling_calls.append(True) or (None, 0.0)

    bot._continue_after_hook("ad")

    assert reeling_calls == [True]


def test_change_bait_publishes_local_event_and_telegram_notification():
    bot = make_change_bait_bot([{"changed_bait": 1.0}, {}, {"start2": 1.0}])
    events: list[tuple[str, str]] = []
    messages: list[str] = []

    class Notifications:
        def notify_bait_tired(self):
            messages.append("telegram")

    bot.notification_manager = Notifications()
    bot._publish_ui_event = lambda text, **kwargs: events.append((text, kwargs.get("icon", "")))

    assert bot._do_change_bait() is True
    assert events == [("Рыба устала от приманки, исправляем", "bait.png")]
    assert messages == ["telegram"]


def test_run_reeling_module_refuses_to_start_when_current_stage_is_not_reeling():
    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState()
    bot._last_triggers = {}
    bot._stop_event = threading.Event()
    bot._has_pending_catch = lambda: False
    bot._probe_catch_screen = lambda: False
    bot._refresh_triggers = lambda: None
    bot._publish_stage = lambda label: None
    logs: list[str] = []
    bot._log = logs.append

    class Tracker:
        def __init__(self):
            self.started = False

        def start(self):
            self.started = True

        def start_control_loop(self):
            self.started = True

    tracker = Tracker()
    bot.reeling_tracker = tracker

    assert bot._run_reeling_module() == (None, 0.0)
    assert tracker.started is False
    assert any("Вываживание не запущено" in item for item in logs)


def make_food_depleted_bot(action: str):
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(food_depleted_action=action)
    bot._meal_search_disabled_until_restart = False
    bot._inventory_retry_after = 0.0
    bot._stop_event = threading.Event()
    bot._log_messages: list[str] = []
    bot._ui_events: list[str] = []
    bot._stop_reasons: list[str] = []
    bot._shutdown_game_calls = 0
    bot._shutdown_pc_calls = 0
    bot._log = bot._log_messages.append
    bot._publish_ui_event = lambda title, **kwargs: bot._ui_events.append(title)
    bot._stop_from_brain = bot._stop_reasons.append

    def shutdown_game():
        bot._shutdown_game_calls += 1

    def shutdown_pc():
        bot._shutdown_pc_calls += 1

    bot._shutdown_game = shutdown_game
    bot._shutdown_pc = shutdown_pc
    return bot


def test_food_depleted_continue_disables_meal_search_until_restart():
    bot = make_food_depleted_bot("continue")

    bot._handle_food_depleted()

    assert bot._ui_events == ["Закончилась еда"]
    assert bot._meal_search_disabled_until_restart is True
    assert bot._inventory_retry_after == float("inf")
    assert bot._stop_reasons == []


def test_food_depleted_shutdown_game_stops_bot_after_closing_game():
    bot = make_food_depleted_bot("exit_game")

    bot._handle_food_depleted()

    assert bot._ui_events == ["Закончилась еда"]
    assert bot._shutdown_game_calls == 1
    assert bot._shutdown_pc_calls == 0
    assert bot._stop_reasons == ["Закончилась еда"]


def test_meal_loop_stops_after_first_consumption_when_hud_is_clear():
    meal_system = FakeMealSystem()
    bot = make_meal_loop_bot(meal_system)
    confirmations = []

    def confirm_after_consumption() -> bool:
        confirmations.append(True)
        return False

    bot._confirm_still_needs_meal_after_consumption = confirm_after_consumption

    assert bot._do_meal_actions() is True
    assert meal_system.backpack_moves == 1
    assert bot._notifications == ["ИРП Армии США"]
    assert confirmations == [True]


def test_meal_loop_continues_after_consumption_only_when_hud_still_needs_meal():
    meal_system = FakeMealSystem()
    bot = make_meal_loop_bot(meal_system)
    confirmations = iter([True, False])
    bot._confirm_still_needs_meal_after_consumption = lambda: next(confirmations)

    assert bot._do_meal_actions() is True
    assert meal_system.backpack_moves == 1
    assert bot._notifications == ["ИРП Армии США", "ИРП Армии США"]


def test_auto_meal_off_ignores_low_player_status():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(auto_meal=False, restore_food_from=90, restore_water_from=90, restore_health_from=50)
    bot._last_player_status = PlayerStatus(food=1, water=1, health=1, source="memory")
    bot._last_player_status_at = time.time()

    assert bot._status_indicates_needs_meal("start2") is False


def test_status_timer_is_disabled_when_auto_meal_is_off():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(auto_meal=False)
    bot._inventory_retry_after = time.time() - 1.0

    assert bot._status_timer_needs_meal() is False


def test_kept_fish_weight_is_added_only_for_confirmed_human_storage():
    bot = FishingBot.__new__(FishingBot)
    bot._player_status_estimate = bot_module.PlayerStatusEstimate()
    bot._last_published_estimated_status = None
    bot._last_confirmed_storage = "boat"
    bot._publish_player_status = lambda status: None
    bot._check_inventory_space_notification = lambda status=None: None
    bot._player_status_estimate.update(
        PlayerStatus(inventory_weight=10.0, inventory_weight_max=40.0, source="screenshot"),
        trusted_core=True,
        inventory_scan=True,
    )

    bot._add_kept_fish_weight_to_inventory_estimate(2.5)
    assert bot.estimated_player_status().inventory_weight == 10.0

    bot._last_confirmed_storage = "human"
    bot._add_kept_fish_weight_to_inventory_estimate(2.5)
    assert bot.estimated_player_status().inventory_weight == 12.5


def test_removed_hp_threshold_does_not_request_meal():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(restore_food_from=30, restore_water_from=30, restore_health_from=90)
    bot._last_player_status = PlayerStatus(food=100, water=100, health=10, source="memory")
    bot._last_player_status_at = time.time()

    assert bot._status_indicates_needs_meal("start2") is False
