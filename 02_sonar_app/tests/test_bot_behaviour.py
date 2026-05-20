from __future__ import annotations

import threading
import time

import numpy as np

import sonar.fishing.bot as bot_module
from sonar.config.models import FishingSettings
from sonar.core.state import BotState
from sonar.fishing.bot import FishingBot
from sonar.fishing.catch_screen import CatchScreenResult


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
    def crop_panel(self, frame, result):
        return frame


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
