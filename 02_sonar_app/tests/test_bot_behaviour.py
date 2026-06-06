from __future__ import annotations

import threading
import time
from datetime import datetime

import numpy as np

import sonar.automation.input_controller as input_controller_module
import sonar.fishing.bot as bot_module
from sonar.automation.input_controller import SCAN_CODES, InputController
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

    def find_detections(self, frame, names=None) -> dict[str, DummyMatch]:
        del names
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


def make_obscured_tackle_scan() -> TackleScanResult:
    scan = make_tackle_scan({})
    return TackleScanResult(
        items=scan.items,
        obscured=True,
        row_rect=scan.row_rect,
        scanned_at=scan.scanned_at,
    )


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


def test_press_fishing_start_does_not_block_wrong_storage():
    bot = FishingBot.__new__(FishingBot)
    bot.input_controller = DummyInput()
    bot.settings = FishingSettings(store_in_trunk=True)
    bot._last_trigger_matches = {"start": DummyMatch(), "human": DummyMatch()}
    bot._last_start_pressed_at = 0.0
    bot._focus_game = lambda: True
    bot._sleep_random = lambda minimum, extra: None
    logs: list[str] = []
    bot._log = logs.append

    assert bot._press_fishing_start() is True
    assert bot.input_controller.keys == ["e"]
    assert not any("хранилище" in message.lower() for message in logs)


def test_prepare_start_falls_through_when_storage_is_not_selected(monkeypatch):
    monkeypatch.setattr(bot_module, "STORAGE_SELECTION_GIVE_UP_SECONDS", -1.0)
    monkeypatch.setattr(bot_module, "STORAGE_SELECTION_RETRY_SECONDS", 0.0)
    bot = FishingBot.__new__(FishingBot)
    bot.input_controller = DummyInput()
    bot.settings = FishingSettings(store_in_trunk=True)
    bot.capture = DummyCapture()
    bot.trigger_monitor = SequenceTriggerMonitor(
        [
            {"start": DummyMatch()},
            {"start": DummyMatch(), "human": DummyMatch()},
            {"start1": DummyMatch(), "human": DummyMatch()},
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
    bot._is_fishing_stage_active = lambda matches: "start" in matches
    bot._mark_storage_from_matches = lambda matches: None
    bot._format_precise_triggers = lambda matches: "start=1.00"
    storage_calls: list[dict[str, DummyMatch]] = []

    def ensure_storage_selection(matches, **kwargs):
        storage_calls.append(matches)
        return "missing", None

    bot._ensure_storage_selection = ensure_storage_selection

    assert bot._prepare_fishing_start(timeout=1.0) == "casting"
    assert storage_calls
    assert bot.input_controller.keys == ["e"]


def test_storage_selection_opens_selector_from_wrong_current_storage():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(store_in_trunk=True)
    bot._player_storage_fallback_active = False
    bot._sleep_random = lambda minimum, extra: None
    bot._log = lambda message: None
    clicks: list[str] = []
    human = TemplateMatch(20, 30, 1.0, 10, 10, "human")
    matches = {
        "start": TemplateMatch(1, 1, 1.0, 10, 10, "start"),
        "human": human,
    }

    def click_match(match):
        clicks.append(match.name or "")

    bot._click_match = click_match

    result, anchor_match = bot._ensure_storage_selection(
        matches,
        selector_opened=False,
        anchor=None,
    )

    assert result == "opened"
    assert anchor_match is human
    assert clicks == ["human"]


def test_storage_selection_falls_back_to_human_when_boat_is_missing_from_selector():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(store_in_trunk=True)
    bot._player_storage_fallback_active = False
    bot._sleep_random = lambda minimum, extra: None
    bot._click_storage_option_from_screenshot = lambda target, anchor: False
    logs: list[str] = []
    clicks: list[str] = []
    bot._log = logs.append
    bot._click_match = lambda match: clicks.append(match.name or "")
    human = TemplateMatch(20, 30, 1.0, 10, 10, "human")

    result, anchor_match = bot._ensure_storage_selection(
        {
            "start": TemplateMatch(1, 1, 1.0, 10, 10, "start"),
            "human": human,
        },
        selector_opened=True,
        anchor=human,
    )

    assert result == "progress"
    assert anchor_match is human
    assert clicks == ["human"]
    assert bot._player_storage_fallback_active is True
    assert bot._last_confirmed_storage == "human"
    assert any("human fallback" in message for message in logs)


def test_storage_screenshot_click_uses_selector_anchor_when_start_is_temporarily_hidden(tmp_path, monkeypatch):
    class Capture:
        def capture(self):
            return np.zeros((1080, 1920, 3), dtype=np.uint8)

    class TriggerMonitor:
        resource_dir = tmp_path

        def find_detections(self, _frame, names=None):
            del names
            return {}

    class Matcher:
        def __init__(self, _threshold: float) -> None:
            pass

        def find_best_scaled(self, _frame, _template, *, roi, name, scales):
            del roi, scales
            if name == "change_boat":
                return TemplateMatch(1199, 887, 1.0, 10, 10, name)
            return None

    bot = FishingBot.__new__(FishingBot)
    bot.capture = Capture()
    bot.trigger_monitor = TriggerMonitor()
    bot._sleep_random = lambda minimum, extra: None
    clicks: list[str] = []
    logs: list[str] = []
    bot._click_match = lambda match: clicks.append(match.name or "")
    bot._log = logs.append
    monkeypatch.setattr(bot_module, "load_template", lambda _path: object())
    monkeypatch.setattr(bot_module, "TemplateMatcher", Matcher)

    assert bot._click_storage_option_from_screenshot(
        "boat",
        TemplateMatch(1199, 969, 1.0, 10, 10, "human"),
    ) is True
    assert clicks == ["change_boat"]
    assert not any("menu is not confirmed" in message for message in logs)


def test_start_stage_uses_casting_preparation_instead_of_direct_press():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(auto_meal=False)
    bot.state = BotState()
    bot._stop_event = threading.Event()
    bot._meal_search_disabled_until_restart = False
    bot._kickstart_requested = False
    bot._inventory_retry_after = time.time() + 10.0
    bot.is_paused_for_chat = lambda: False
    bot._publish_stage = lambda stage: None
    bot._sleep = lambda seconds: bot._stop_event.set()
    bot._update_focus_state_notification = lambda: None
    bot._get_triggers = lambda: {"start": 1.0, "human": 1.0}
    bot._detect_stage = lambda triggers: "start"
    bot._stage_label = lambda stage: "Выбор снастей"
    bot._publish_estimated_player_status_if_changed = lambda: None
    bot._status_indicates_needs_meal = lambda stage: False
    bot._status_timer_needs_meal = lambda: False
    bot._stop_if_no_stage_timed_out = lambda stage, needs_meal: False
    bot._close_game_menu_if_open = lambda: False
    bot._has_pending_catch = lambda: False
    bot._probe_catch_screen = lambda: False
    bot._handle_player_status_scan_request = lambda stage: False
    bot._should_handle_meal_now = lambda stage, needs_meal: False
    calls: list[str] = []

    def do_casting() -> None:
        calls.append("casting")
        bot._stop_event.set()

    bot._do_casting = do_casting
    bot._press_fishing_start = lambda: calls.append("press")
    bot._log = lambda message: None

    bot._brain_loop()

    assert calls == ["casting"]


def test_get_triggers_throttles_secondary_template_searches():
    class Monitor:
        def __init__(self) -> None:
            self.calls: list[tuple[str, ...]] = []

        def find_detections(self, _frame, names=None):
            names_tuple = tuple(names or ())
            self.calls.append(names_tuple)
            if names_tuple == bot_module.FISHING_STAGE_TRIGGER_NAMES:
                return {"start1": DummyMatch()}
            if names_tuple == bot_module.SECONDARY_TRIGGER_NAMES:
                return {"thirst": DummyMatch()}
            return {}

    bot = FishingBot.__new__(FishingBot)
    bot.capture = DummyCapture()
    bot.trigger_monitor = Monitor()
    bot.state = BotState()
    bot._last_trigger_matches = {}
    bot._last_triggers = {}
    bot._last_secondary_trigger_at = 0.0
    bot._log = lambda message: None

    first = bot._get_triggers()
    second = bot._get_triggers()

    assert "start1" in first
    assert "thirst" in first
    assert "start1" in second
    assert "thirst" not in second
    assert bot.trigger_monitor.calls == [
        bot_module.FISHING_STAGE_TRIGGER_NAMES,
        bot_module.SECONDARY_TRIGGER_NAMES,
        bot_module.FISHING_STAGE_TRIGGER_NAMES,
    ]


def test_kickstart_does_not_cast_after_pending_inventory_tasks():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(auto_meal=True)
    bot.state = BotState()
    bot._stop_event = threading.Event()
    bot._meal_search_disabled_until_restart = False
    bot._kickstart_requested = True
    bot._initial_status_scan_pending = False
    bot._inventory_retry_after = 0.0
    bot.is_paused_for_chat = lambda: False
    bot._publish_stage = lambda stage: None
    bot._sleep = lambda seconds: None
    bot._update_focus_state_notification = lambda: None
    bot._detect_stage = lambda triggers: None
    bot._publish_estimated_player_status_if_changed = lambda: None
    bot._status_indicates_needs_meal = lambda stage: False
    bot._status_timer_needs_meal = lambda: False
    bot._stop_if_no_stage_timed_out = lambda stage, needs_meal: False
    bot._close_game_menu_if_open = lambda: False
    bot._has_pending_catch = lambda: False
    bot._probe_catch_screen = lambda: False
    bot._handle_player_status_scan_request = lambda stage: False
    bot._should_handle_meal_now = lambda stage, needs_meal: False
    calls: list[str] = []

    def get_triggers() -> dict[str, float]:
        if calls:
            bot._stop_event.set()
            return {}
        return {"hunger": 1.0}

    bot._get_triggers = get_triggers
    bot._handle_pending_tasks = lambda do_meal: calls.append("inventory")
    bot._do_casting = lambda: calls.append("casting")

    bot._brain_loop()

    assert calls == ["inventory"]


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
    bot._stop_event = threading.Event()
    bot._start_attempt_since = time.time() - bot_module.AUTO_STOP_TIMEOUT_SECONDS - 1.0
    bot._prepare_fishing_start = lambda: None
    logs: list[str] = []
    reasons: list[str] = []
    bot._log = logs.append
    bot._stop_from_brain = reasons.append

    bot._do_casting()

    assert reasons == [bot_module.STOP_REASON_START_FAILED]
    assert any(bot_module.STOP_REASON_START_FAILED in message for message in logs)


def test_casting_does_not_log_missing_stage_after_prepare_stops_bot():
    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState()
    bot._stop_event = threading.Event()
    bot._start_attempt_since = None
    logs: list[str] = []
    bot._log = logs.append

    def stop_during_prepare():
        bot._stop_event.set()
        return None

    bot._prepare_fishing_start = stop_during_prepare

    bot._do_casting()

    assert not any("стадия рыбалки не найдена" in message for message in logs)


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


def test_fishing_entry_press_has_global_cooldown(monkeypatch):
    current_time = 100.0
    bot = FishingBot.__new__(FishingBot)
    bot.input_controller = DummyInput()
    bot._log = lambda _message: None
    monkeypatch.setattr(bot_module.time, "time", lambda: current_time)

    assert bot._press_fishing_entry("test") is True
    current_time += bot_module.FISHING_ENTRY_MIN_INTERVAL_SECONDS - 0.1
    assert bot._press_fishing_entry("test") is False
    current_time += 0.1
    assert bot._press_fishing_entry("test") is True
    assert bot.input_controller.keys == ["e", "e"]


def test_recover_does_not_move_character_forward():
    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState()
    bot.input_controller = DummyInput()
    bot._stop_event = threading.Event()
    bot._last_triggers = {}
    bot._refresh_triggers = lambda *args, **kwargs: None
    bot._focus_game = lambda: None
    bot._wait_for_start_phase = lambda timeout: True
    bot._log = lambda _message: None
    bot.notification_manager = type("Notifier", (), {"notify_fishing_restored": lambda self: None})()

    assert bot._try_recover() is True
    assert bot.input_controller.keys == ["e"]


def test_inventory_brain_error_is_retried_without_fishing_recovery():
    calls: list[str] = []
    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState(running=True, phase=BotPhase.INVENTORY)
    bot._inventory_retry_after = 0.0
    bot._log = lambda message: calls.append(message)
    bot._sleep = lambda seconds: calls.append(f"sleep:{seconds}")
    bot._try_recover = lambda: calls.append("recover")

    bot._handle_brain_error(RuntimeError("inventory failed"))

    assert bot._inventory_tasks_retry_pending is True
    assert bot._inventory_retry_after > time.time()
    assert "recover" not in calls
    assert "sleep:1.0" in calls


def test_non_inventory_brain_error_still_uses_fishing_recovery():
    calls: list[str] = []
    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState(running=True, phase=BotPhase.CASTING)
    bot._log = lambda message: calls.append(message)
    bot._try_recover = lambda: calls.append("recover")

    bot._handle_brain_error(RuntimeError("casting failed"))

    assert "recover" in calls


def test_inventory_open_waits_before_pressing_hotkey():
    events: list[str] = []
    inventory_states = iter([False, False, True])

    class InputController:
        def press_key(self, key: str) -> None:
            events.append(f"key:{key}")

    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings()
    bot.input_controller = InputController()
    bot._stop_event = threading.Event()
    bot._focus_game = lambda: None
    bot._close_game_menu_if_open = lambda: False
    bot._is_inventory_open = lambda: next(inventory_states)
    bot._exit_to_idle_before_inventory = lambda: events.append("idle") or True
    bot._sleep = lambda seconds: events.append(f"sleep:{seconds}")
    bot._log = lambda _message: None

    assert bot._open_inventory() is True
    assert events[:4] == ["idle", "sleep:1.0", "idle", "key:i"]


def test_inventory_open_does_not_press_hotkey_when_stage_changes_during_pause():
    events: list[str] = []
    idle_checks = iter([True, False])

    class InputController:
        def press_key(self, key: str) -> None:
            events.append(f"key:{key}")

    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings()
    bot.input_controller = InputController()
    bot._stop_event = threading.Event()
    bot._focus_game = lambda: None
    bot._close_game_menu_if_open = lambda: False
    bot._is_inventory_open = lambda: False
    bot._exit_to_idle_before_inventory = lambda: next(idle_checks)
    bot._sleep = lambda seconds: events.append(f"sleep:{seconds}")
    bot._log = lambda _message: None

    assert bot._open_inventory() is False
    assert events == ["sleep:1.0"]


def test_failed_inventory_tasks_are_retried_instead_of_casting():
    events: list[str] = []
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(auto_meal=True)
    bot.state = BotState()
    bot._open_inventory = lambda: False
    bot._log = lambda message: events.append(message)

    bot._do_combined_inventory_tasks(do_meal=True, do_backpack=False)
    assert bot._inventory_tasks_retry_pending is True

    bot._inventory_retry_after = 0.0
    bot._handle_pending_tasks = lambda do_meal: events.append(f"inventory:{do_meal}")
    bot._prepare_fishing_start = lambda: events.append("casting") or None

    bot._do_casting()

    assert "inventory:True" in events
    assert "casting" not in events


def test_return_to_fishing_waits_after_inventory_is_closed():
    events: list[str] = []
    inventory_states = iter([True, False])

    class InputController:
        def press_key(self, key: str) -> None:
            events.append(f"key:{key}")

    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings()
    bot.input_controller = InputController()
    bot._stop_event = threading.Event()
    bot._last_triggers = {}
    bot._focus_game = lambda: None
    bot._close_game_menu_if_open = lambda: False
    bot._is_inventory_open = lambda: next(inventory_states)
    bot._refresh_triggers = lambda *args, **kwargs: None
    bot._sleep = lambda seconds: events.append(f"sleep:{seconds}")
    bot._log = lambda _message: None

    bot._return_to_fishing()

    assert events == [
        "key:i",
        "sleep:1.0",
        "sleep:0.12",
        "sleep:1.5",
        "key:e",
    ]


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


def test_missing_net_from_session_start_does_not_publish_allowed_warning():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings()
    bot._session_started_with_net = False
    reasons: list[str] = []
    events: list[str] = []
    logs: list[str] = []
    bot._publish_ui_event = lambda title, **kwargs: events.append(title)
    bot._log = logs.append
    bot._stop_from_brain = reasons.append

    handled = bot._handle_tackle_depletion(make_tackle_scan({"net": 0}))

    assert handled is False
    assert reasons == []
    assert events == []
    assert not any("Подсак закончился" in message for message in logs)


def test_missing_net_from_session_start_still_stops_when_required():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(fish_without_net=False)
    bot._session_started_with_net = False
    reasons: list[str] = []
    bot._publish_ui_event = lambda title, **kwargs: None
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append

    handled = bot._handle_tackle_depletion(make_tackle_scan({"net": 0}))

    assert handled is True
    assert reasons == ["Подсак закончился"]


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


def test_obscured_tackle_scan_is_skipped_instead_of_stopping_fishing():
    class ObscuredTackleDetector:
        def detect(self, frame):
            return make_obscured_tackle_scan()

    bot = FishingBot.__new__(FishingBot)
    bot.capture = DummyCapture()
    bot.tackle_detector = ObscuredTackleDetector()
    bot._stop_event = threading.Event()
    bot._sleep = lambda seconds: None
    logs: list[str] = []
    reasons: list[str] = []
    bot._log = logs.append
    bot._stop_from_brain = reasons.append
    bot._store_tackle_scan = lambda scan, frame: None

    assert bot._check_tackle_before_start(object()) is True
    assert reasons == []
    assert any("проверка пропущена" in message for message in logs)


def test_unobscured_empty_tackle_scan_still_stops_fishing():
    class EmptyTackleDetector:
        def detect(self, frame):
            return make_empty_tackle_scan()

    bot = FishingBot.__new__(FishingBot)
    bot.capture = DummyCapture()
    bot.tackle_detector = EmptyTackleDetector()
    bot._stop_event = threading.Event()
    bot._sleep = lambda seconds: None
    reasons: list[str] = []
    bot._log = lambda message: None
    bot._stop_from_brain = reasons.append
    bot._store_tackle_scan = lambda scan, frame: None

    assert bot._check_tackle_before_start(object()) is False
    assert reasons == [bot_module.STOP_REASON_TACKLE_UNREADABLE]


def test_active_stage_tackle_scan_stores_waiting_stage_counts():
    class Detector:
        def detect(self, frame):
            return make_tackle_scan({"bait": 7})

    bot = FishingBot.__new__(FishingBot)
    stored: list[TackleScanResult] = []
    bot.tackle_detector = Detector()
    bot.capture = DummyCapture()
    bot._active_tackle_scanned_stages = set()
    bot._store_tackle_scan = lambda scan, frame: stored.append(scan)
    bot._log = lambda message: None

    bot._scan_tackle_for_active_stage("start2", object())

    assert stored
    assert stored[0].count_for("bait") == 7


def test_active_stage_tackle_scan_runs_once_per_stage_entry():
    class Detector:
        def __init__(self) -> None:
            self.calls = 0

        def detect(self, frame):
            self.calls += 1
            return make_tackle_scan({"bait": 7})

    detector = Detector()
    bot = FishingBot.__new__(FishingBot)
    stored: list[TackleScanResult] = []
    bot.tackle_detector = detector
    bot.capture = DummyCapture()
    bot._active_tackle_scanned_stages = set()
    bot._store_tackle_scan = lambda scan, frame: stored.append(scan)
    bot._log = lambda message: None

    bot._scan_tackle_for_active_stage("start2", object())
    bot._scan_tackle_for_active_stage("start2", object())
    bot._reset_active_tackle_scan("start2")
    bot._scan_tackle_for_active_stage("start2", object())

    assert detector.calls == 2
    assert len(stored) == 2


def test_active_stage_tackle_scan_limits_waiting_and_reeling_separately():
    class Detector:
        def __init__(self) -> None:
            self.calls = 0

        def detect(self, frame):
            self.calls += 1
            return make_tackle_scan({})

    detector = Detector()
    bot = FishingBot.__new__(FishingBot)
    stored: list[TackleScanResult] = []
    bot.tackle_detector = detector
    bot.capture = DummyCapture()
    bot._active_tackle_scanned_stages = set()
    bot._store_tackle_scan = lambda scan, frame: stored.append(scan)
    bot._log = lambda message: None

    bot._scan_tackle_for_active_stage("start2", object())
    bot._scan_tackle_for_active_stage("start2", object())
    bot._scan_tackle_for_active_stage("ad", object())
    bot._scan_tackle_for_active_stage("ad", object())

    assert detector.calls == 2
    assert len(stored) == 2


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
    assert calls == ["Кончилась леска", "shutdown_game"]


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


def test_reeling_loss_release_log_is_encrypted_and_rotated(tmp_path, monkeypatch):
    bot = FishingBot.__new__(FishingBot)
    bot._log = lambda _message: None
    monkeypatch.setattr(bot_module, "IS_FROZEN", True)
    monkeypatch.setattr(bot_module, "LOG_DIR", tmp_path)
    monkeypatch.delenv("SONAR_DEBUG_MODE", raising=False)
    monkeypatch.delenv("SONAR_DEBUG_CAPTURE", raising=False)

    current_time = 1_770_000_000

    def fake_time() -> float:
        nonlocal current_time
        current_time += 1
        return float(current_time)

    monkeypatch.setattr(bot_module.time, "time", fake_time)
    records = [{"event": "state", "action": "target_search"}]

    for index in range(17):
        path = bot._save_reeling_debug_log(records, f"lost_{index}")
        assert path is not None

    files = sorted(tmp_path.glob("reeling_loss_*.jsonl.enc"))
    assert len(files) == 15
    payload = files[-1].read_bytes()
    assert b"target_search" not in payload
    assert b"target_search" in bot_module.decrypt_reeling_loss_log(payload, key="sonar")


def test_auto_stop_sends_screenshot_with_stop_notification():
    events: list[str] = []

    class DummyReelingTracker:
        def stop(self) -> None:
            events.append("reeling_stop")

    class DummyCloser:
        def __init__(self, name: str) -> None:
            self.name = name

        def close(self) -> None:
            events.append(self.name)

    class DummyMealSystem:
        status_memory_detector = DummyCloser("meal_close")

    class DummyInputController:
        def release_all_keys(self) -> None:
            events.append("release_all")

    class DummySessionStats:
        def __init__(self) -> None:
            self.stopped = False

        def stop_timer(self) -> None:
            self.stopped = True
            events.append("timer_stop")

        def totals(self):
            return object()

    class DummyNotifier:
        def __init__(self) -> None:
            self.image_bytes = None
            self.reason = None

        def notify_fishing_stopped(self, _totals, *, reason=None, image_bytes=None) -> None:
            self.reason = reason
            self.image_bytes = image_bytes
            events.append("notify_stop")

    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState(running=True)
    bot._stop_event = threading.Event()
    bot.reeling_tracker = DummyReelingTracker()
    bot.inventory_memory_detector = DummyCloser("inventory_close")
    bot.meal_system = DummyMealSystem()
    bot.input_controller = DummyInputController()
    bot.settings = FishingSettings(start_stop_sound_enabled=False)
    bot.session_stats = DummySessionStats()
    bot.notification_manager = DummyNotifier()
    bot._log = lambda _message: None
    bot._publish_ui_event = lambda *_args, **_kwargs: None
    bot._wait_before_auto_stop_screenshot = lambda: events.append("wait_screenshot")
    bot._capture_screenshot_bytes = lambda: events.append("capture_screenshot") or b"screen"

    bot._stop_from_brain(bot_module.STOP_REASON_NO_STAGE)

    assert bot.notification_manager.reason == bot_module.STOP_REASON_NO_STAGE
    assert bot.notification_manager.image_bytes == b"screen"
    assert bot.session_stats.stopped is True
    assert events.index("timer_stop") < events.index("wait_screenshot")
    assert events.index("wait_screenshot") < events.index("capture_screenshot")
    assert events.index("capture_screenshot") < events.index("notify_stop")


def test_stop_async_returns_before_cleanup_finishes():
    cleanup_started = threading.Event()
    allow_cleanup = threading.Event()

    class BlockingReelingTracker:
        def stop(self) -> None:
            cleanup_started.set()
            assert allow_cleanup.wait(timeout=1.0)

    class DummyCloser:
        def close(self) -> None:
            pass

    class DummyMealSystem:
        status_memory_detector = DummyCloser()

    class DummyInputController:
        def release_all_keys(self) -> None:
            pass

    class DummySessionStats:
        def stop_timer(self) -> None:
            pass

        def totals(self):
            return object()

    class DummyNotifier:
        def notify_fishing_stopped(self, _totals, *, reason=None, image_bytes=None) -> None:
            del reason, image_bytes

    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState(running=True)
    bot._stop_event = threading.Event()
    bot._brain_thread = None
    bot.reeling_tracker = BlockingReelingTracker()
    bot.inventory_memory_detector = DummyCloser()
    bot.meal_system = DummyMealSystem()
    bot.input_controller = DummyInputController()
    bot.settings = FishingSettings(start_stop_sound_enabled=False)
    bot.session_stats = DummySessionStats()
    bot.notification_manager = DummyNotifier()
    bot._log = lambda _message: None
    bot._publish_ui_event = lambda *_args, **_kwargs: None

    started_at = time.monotonic()
    bot.stop_async()
    elapsed = time.monotonic() - started_at

    assert elapsed < 0.2
    assert cleanup_started.wait(timeout=0.5)
    assert bot._stop_event.is_set()
    assert bot.state.running is False
    assert bot.state.phase == BotPhase.STOPPING

    allow_cleanup.set()
    deadline = time.monotonic() + 1.0
    while bot.state.phase != BotPhase.IDLE and time.monotonic() < deadline:
        time.sleep(0.01)
    assert bot.state.phase == BotPhase.IDLE


def test_begin_stop_immediately_blocks_worker_input(monkeypatch):
    sent_keys: list[tuple[str, bool]] = []
    controller = InputController()
    monkeypatch.setattr(InputController, "_send_key", lambda _self, key, key_up: sent_keys.append((key, key_up)))

    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState(running=True)
    bot._stop_event = threading.Event()
    bot._input_enabled_event = threading.Event()
    bot._input_enabled_event.set()
    bot._is_game_foreground = lambda: True
    controller.input_allowed_callback = bot._is_fishing_input_allowed

    assert controller.key_down("space") is True
    sent_keys.clear()

    bot._begin_stop()

    assert controller.key_down("space") is False
    assert controller.tap_key_fast("space") is False
    assert sent_keys == []


def test_input_controller_never_sends_automated_w(monkeypatch):
    sent_keys: list[tuple[str, bool]] = []
    monkeypatch.setattr(InputController, "_send_key", lambda _self, key, key_up: sent_keys.append((key, key_up)))
    controller = InputController(input_allowed_callback=lambda: True)

    assert controller.key_down("w") is False
    assert controller.press_key("w") is False
    assert controller.tap_key_fast("w") is False
    assert controller.key_up("w") is False
    controller.release_all_keys()

    assert "w" not in SCAN_CODES
    assert not any(key == "w" for key, _key_up in sent_keys)


def test_input_controller_low_level_never_sends_automated_w(monkeypatch):
    send_input_calls: list[tuple[object, ...]] = []

    class User32:
        def SendInput(self, *args):
            send_input_calls.append(args)
            return 1

    monkeypatch.setattr(input_controller_module.ctypes, "windll", type("WinDll", (), {"user32": User32()})(), raising=False)

    controller = InputController()
    controller._send_key("w", key_up=False)
    controller._send_key("w", key_up=True)

    assert send_input_calls == []


def test_stop_cleanup_failure_does_not_leave_bot_running():
    events: list[str] = []
    logs: list[str] = []

    class FailingReelingTracker:
        def stop(self) -> None:
            raise RuntimeError("reeling cleanup failed")

    class DummyCloser:
        def close(self) -> None:
            events.append("close")

    class DummyMealSystem:
        status_memory_detector = DummyCloser()

    class DummyInputController:
        def release_all_keys(self) -> None:
            events.append("release_all")

    class DummySessionStats:
        def stop_timer(self) -> None:
            events.append("timer_stop")

        def totals(self):
            return object()

    class DummyNotifier:
        def notify_fishing_stopped(self, _totals, *, reason=None, image_bytes=None) -> None:
            del reason, image_bytes
            events.append("notify_stop")

    bot = FishingBot.__new__(FishingBot)
    bot.state = BotState(running=True)
    bot._stop_event = threading.Event()
    bot._brain_thread = None
    bot.reeling_tracker = FailingReelingTracker()
    bot.inventory_memory_detector = DummyCloser()
    bot.meal_system = DummyMealSystem()
    bot.input_controller = DummyInputController()
    bot.settings = FishingSettings(start_stop_sound_enabled=False)
    bot.session_stats = DummySessionStats()
    bot.notification_manager = DummyNotifier()
    bot._log = logs.append
    bot._publish_ui_event = lambda *_args, **_kwargs: None

    bot.stop()

    assert bot.state.running is False
    assert bot.state.phase == BotPhase.IDLE
    assert "release_all" in events
    assert "timer_stop" in events
    assert "notify_stop" in events
    assert any("reeling tracker" in message for message in logs)


def test_trunk_overweight_switches_to_player_storage_before_final_action():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(store_in_trunk=True, overweight_action="stop")
    bot.state = BotState(running=True)
    bot.input_controller = DummyInput()
    bot._stop_event = threading.Event()
    bot._last_confirmed_storage = "boat"
    bot._player_storage_fallback_active = False
    bot.inventory_full = False
    bot._inventory_retry_after = 100.0
    bot._kickstart_requested = False
    bot._last_catch_result = None
    bot._last_triggers = {}
    bot._focus_game = lambda: None
    bot._refresh_triggers = lambda *args, **kwargs: setattr(bot, "_last_triggers", {})
    bot._sleep = lambda seconds: None
    entry_reasons: list[str] = []
    bot._press_fishing_entry = lambda reason: entry_reasons.append(reason) or True
    logs: list[str] = []
    bot._log = logs.append
    events: list[str] = []
    bot.notification_manager = type("Notifier", (), {"notify_inventory_full": lambda self: events.append("notify")})()
    bot._handle_overweight_action = lambda previous_result: events.append("action")

    bot._handle_overweight_trigger()

    assert bot.inventory_full is False
    assert bot._player_storage_fallback_active is True
    assert bot._last_confirmed_storage == ""
    assert bot._inventory_retry_after == 0.0
    assert bot._kickstart_requested is True
    assert bot.state.phase == BotPhase.RECOVERY
    assert bot.input_controller.keys == ["esc"]
    assert entry_reasons == ["Перевес: переключение хранилища"]
    assert events == []
    assert any("багажник заполнен" in message for message in logs)


def test_player_storage_overweight_runs_action_after_trunk_fallback():
    bot = FishingBot.__new__(FishingBot)
    bot.settings = FishingSettings(store_in_trunk=True, overweight_action="stop")
    bot._last_confirmed_storage = "human"
    bot._player_storage_fallback_active = True
    bot.inventory_full = False
    previous_result = object()
    bot._last_catch_result = previous_result
    logs: list[str] = []
    events: list[object] = []
    bot._log = logs.append
    bot.notification_manager = type("Notifier", (), {"notify_inventory_full": lambda self: events.append("notify")})()
    bot._handle_overweight_action = lambda previous_result: events.append(("action", previous_result))

    bot._handle_overweight_trigger()

    assert bot.inventory_full is True
    assert events == ["notify", ("action", previous_result)]
    assert any("инвентарь помечен как полный" in message for message in logs)


def test_overweight_terminal_actions_finish_stop_lifecycle():
    class DummyReelingTracker:
        def __init__(self, events: list[str]) -> None:
            self.events = events

        def stop(self) -> None:
            self.events.append("reeling_stop")

    class DummyCloser:
        def __init__(self, events: list[str], name: str) -> None:
            self.events = events
            self.name = name

        def close(self) -> None:
            self.events.append(self.name)

    class DummyMealSystem:
        def __init__(self, events: list[str]) -> None:
            self.status_memory_detector = DummyCloser(events, "meal_close")

    class DummyInputController:
        def __init__(self, events: list[str]) -> None:
            self.events = events

        def release_all_keys(self) -> None:
            self.events.append("release_all")

    class DummySessionStats:
        def __init__(self, events: list[str]) -> None:
            self.events = events

        def stop_timer(self) -> None:
            self.events.append("timer_stop")

        def totals(self):
            return object()

    class DummyNotifier:
        def __init__(self, events: list[str]) -> None:
            self.events = events
            self.reason = None

        def notify_fishing_stopped(self, _totals, *, reason=None, image_bytes=None) -> None:
            del image_bytes
            self.reason = reason
            self.events.append("notify_stop")

    for action in ("stop", "exit_game"):
        events: list[str] = []
        bot = FishingBot.__new__(FishingBot)
        bot.state = BotState(running=True)
        bot._stop_event = threading.Event()
        bot.reeling_tracker = DummyReelingTracker(events)
        bot.inventory_memory_detector = DummyCloser(events, "inventory_close")
        bot.meal_system = DummyMealSystem(events)
        bot.input_controller = DummyInputController(events)
        bot.settings = FishingSettings(overweight_action=action, start_stop_sound_enabled=False)
        bot.session_stats = DummySessionStats(events)
        bot.notification_manager = DummyNotifier(events)
        bot.inventory_full = True
        bot._last_catch_result = None
        bot._log = lambda _message: None
        bot._publish_ui_event = lambda *_args, **_kwargs: None
        bot._shutdown_game = lambda: events.append("shutdown_game")

        bot._handle_overweight_action(previous_result=None)

        assert bot._stop_event.is_set()
        assert bot.state.running is False
        assert bot.state.phase == BotPhase.IDLE
        assert bot.inventory_full is False
        assert bot.notification_manager.reason == bot_module.STOP_REASON_OVERWEIGHT
        assert "reeling_stop" in events
        assert "release_all" in events
        assert ("shutdown_game" in events) is (action == "exit_game")


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


def test_current_catch_result_refreshes_cached_unknown_fish():
    bot = FishingBot.__new__(FishingBot)
    stale = CatchScreenResult(
        True,
        fish_text="ин Ш",
        fish_confidence=0.0,
        weight_kg=3.53,
        weight_text="3.537",
    )
    refreshed = CatchScreenResult(
        True,
        fish_id="marlin",
        fish_confidence=0.95,
        fish_text="Марлин",
        weight_kg=3.53,
        weight_text="3.53",
    )
    snapshots: list[CatchScreenResult] = []

    class Detector:
        def detect(self, frame):
            return refreshed

    bot._last_catch_result = stale
    bot._stop_event = threading.Event()
    bot.capture = DummyCapture()
    bot.game_menu_detector = ClosedDetector()
    bot.catch_detector = Detector()
    bot._sleep = lambda _seconds: None
    bot._save_catch_panel_snapshot = lambda _frame, result: snapshots.append(result)

    result = bot._current_catch_result(timeout=0.1)

    assert result is refreshed
    assert bot._last_catch_result is refreshed
    assert snapshots == [refreshed]


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
    bot._refresh_triggers = lambda *args, **kwargs: None
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


def test_food_depleted_shutdown_game_runs_after_stop():
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
