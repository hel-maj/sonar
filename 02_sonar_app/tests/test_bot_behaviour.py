from __future__ import annotations

import threading
import time
from datetime import datetime

import numpy as np

import sonar.fishing.bot as bot_module
from sonar.config.models import FishingSettings
from sonar.core.state import BotState
from sonar.fishing.bot import FishingBot
from sonar.fishing.catch_screen import CatchScreenResult
from sonar.fishing.tackle_detection import TACKLE_SLOTS, TackleItemCount, TackleScanResult
from sonar.vision.geometry import Rect


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
    bot = make_change_bait_bot([{"changed_bait": 1.0, "start2": 1.0}, {}])

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
    bot.catch_detector = DummyCatchDetector()
    bot.capture.capture = lambda: np.zeros((32, 32, 3), dtype=np.uint8)
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
        quality="Рекордный улов",
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
