from __future__ import annotations

from pathlib import Path

import cv2
import pytest

from sonar.fishing.hooking import create_monitor_for_frame
from sonar.fishing.catch_screen import CatchScreenDetector
from sonar.fishing.inventory_stage import InventoryStageDetector
from sonar.fishing.meal_system import MealSystem
from sonar.fishing.trigger_monitor import TriggerMonitor
from sonar.fishing.constants import resolution_name


FIXTURES = Path(__file__).parent / "fixtures" / "gameplay"
TACKLE_FIXTURES = Path(__file__).parent / "fixtures" / "tackle"


def load_frame(name: str):
    path = FIXTURES / name
    frame = cv2.imread(str(path))
    assert frame is not None, f"Fixture is not readable: {path}"
    return frame


def load_tackle_frame(name: str):
    path = TACKLE_FIXTURES / name
    frame = cv2.imread(str(path))
    assert frame is not None, f"Fixture is not readable: {path}"
    return frame


def detections(name: str) -> dict[str, float]:
    return TriggerMonitor().detect(load_frame(name))


def stage_from_detections(matches: dict[str, float]) -> str | None:
    for name in ("ad", "start2", "wait_tension", "start1", "start"):
        if name in matches:
            return "start2" if name == "wait_tension" else name
    return None


@pytest.mark.parametrize(
    "fixture",
    [
        "inventory_474.jpg",
        "inventory_475.jpg",
        "inventory_476.jpg",
        "inventory_477.jpg",
        "inventory_487.jpg",
        "inventory_490.jpg",
        "inventory_492.jpg",
    ],
)
def test_inventory_open_is_detected_by_top_text(fixture):
    assert InventoryStageDetector().is_open(load_frame(fixture)) is True


@pytest.mark.parametrize(
    "fixture",
    [
        "idle_085845.jpg",
        "catch_ruster_good_081821.jpg",
        "tackle_select_488.jpg",
        "waiting_081552.jpg",
    ],
)
def test_inventory_open_rejects_non_inventory_screens(fixture):
    assert InventoryStageDetector().is_open(load_frame(fixture)) is False


@pytest.mark.parametrize("fixture", ["thirst_493.jpg", "thirst_494.jpg", "thirst_496.jpg", "thirst_overweight_085057.jpg"])
def test_thirst_indicator_is_detected(fixture):
    assert "thirst" in detections(fixture)


@pytest.mark.parametrize("fixture", ["no_thirst_18190951.jpg", "no_thirst_catch_marlin_053636.jpg"])
def test_thirst_indicator_is_absent(fixture):
    assert "thirst" not in detections(fixture)


@pytest.mark.parametrize("fixture", ["tackle_select_488.jpg"])
def test_tackle_selection_stage_is_detected(fixture):
    assert stage_from_detections(detections(fixture)) == "start"


def test_tackle_selection_stage_survives_downscale():
    frame = load_frame("tackle_select_488.jpg")
    resized = cv2.resize(frame, (1920, 1080), interpolation=cv2.INTER_AREA)

    assert stage_from_detections(TriggerMonitor().detect(resized)) == "start"


@pytest.mark.parametrize("fixture", ["tackle_select_473.jpg"])
def test_casting_stage_is_detected(fixture):
    assert stage_from_detections(detections(fixture)) == "start1"


@pytest.mark.parametrize("fixture", ["waiting_081609.jpg", "waiting_081555.jpg", "waiting_081552.jpg", "waiting_084829.jpg"])
def test_waiting_for_bite_stage_is_detected(fixture):
    assert stage_from_detections(detections(fixture)) == "start2"


@pytest.mark.parametrize(
    "fixture",
    [
        "change_bait_20260519120751.jpg",
        "change_bait_20260519120814.jpg",
        "change_bait_20260519120815_1.jpg",
        "change_bait_20260519120815_2.jpg",
        "change_bait_20260519120816.jpg",
        "change_bait_20260519120817.jpg",
        "change_bait_20260519120818.jpg",
    ],
)
def test_change_bait_notification_is_detected(fixture):
    assert "changed_bait" in detections(fixture)


@pytest.mark.parametrize("fixture", ["reeling_084114.jpg", "reeling_081715.jpg"])
def test_reeling_stage_is_detected(fixture):
    assert stage_from_detections(detections(fixture)) == "ad"


@pytest.mark.parametrize("fixture", ["idle_085845.jpg", "idle_085848.jpg", "idle_085850.jpg"])
def test_idle_screens_have_no_fishing_stage_even_with_needs_icons(fixture):
    matches = detections(fixture)

    assert stage_from_detections(matches) is None
    assert not {"start", "start1", "start2", "wait_tension", "ad"}.intersection(matches)


def test_catch_screen_is_visible_even_when_bottom_action_text_matches_fishing_stage():
    frame = load_frame("catch_ruster_good_081821.jpg")
    matches = TriggerMonitor().detect(frame)

    assert stage_from_detections(matches) == "start1"
    assert CatchScreenDetector().detect(frame).visible is True


@pytest.mark.parametrize(
    "fixture",
    ["thirst_overweight_085057.jpg", "overweight_084130.jpg", "overweight_081833.jpg", "overweight_081832.jpg"],
)
def test_overweight_notification_is_detected(fixture):
    assert "pereves" in detections(fixture)


class DummyInput:
    def __init__(self) -> None:
        self.keys: list[str] = []

    def press_key(self, key: str) -> None:
        self.keys.append(key)


@pytest.mark.parametrize("fixture", ["hook_trigger_081640.jpg", "hook_trigger_085702.jpg"])
def test_hook_trigger_presses_space(fixture):
    frame = load_frame(fixture)
    input_controller = DummyInput()

    result = create_monitor_for_frame(frame, input_controller).check_and_act(frame)

    assert result.pressed is True
    assert input_controller.keys == ["space"]


@pytest.mark.parametrize("fixture", ["waiting_081552.jpg", "waiting_084829.jpg"])
def test_waiting_screen_does_not_press_space_before_hook_trigger(fixture):
    frame = load_frame(fixture)
    input_controller = DummyInput()

    result = create_monitor_for_frame(frame, input_controller).check_and_act(frame)

    assert result.pressed is False
    assert input_controller.keys == []


@pytest.mark.parametrize(
    "fixture",
    ["no_line_bait_net.jpg", "counts_line998_hook0_bait1.jpg", "counts_line900_hook0_bait1.jpg"],
)
def test_hook_trigger_ignores_gray_bar_matches_without_red_stage(fixture):
    frame = load_tackle_frame(fixture)
    input_controller = DummyInput()

    result = create_monitor_for_frame(frame, input_controller).check_and_act(frame)

    assert result.red_detected is False
    assert result.pressed is False
    assert input_controller.keys == []


@pytest.mark.parametrize(
    "fixture",
    [
        "inventory_475.jpg",
        "inventory_476.jpg",
        "inventory_477.jpg",
        "inventory_irp_481.jpg",
        "inventory_irp_482.jpg",
        "inventory_irp_484.jpg",
        "inventory_irp_485.jpg",
        "inventory_irp_489.jpg",
        "inventory_490.jpg",
    ],
)
def test_irp_is_detected_in_inventory(fixture):
    frame = load_frame(fixture)
    meal = MealSystem()
    meal.load_templates(resolution_name(frame.shape[1], frame.shape[0]))

    assert meal.find_item_in_inventory(frame, "irp") is not None


@pytest.mark.parametrize("fixture", ["inventory_no_irp_479.jpg", "inventory_no_irp_480.jpg", "inventory_no_irp_491.jpg", "inventory_492.jpg"])
def test_irp_absence_is_detected_in_inventory(fixture):
    frame = load_frame(fixture)
    meal = MealSystem()
    meal.load_templates(resolution_name(frame.shape[1], frame.shape[0]))

    assert meal.find_item_in_inventory(frame, "irp") is None


@pytest.mark.parametrize("fixture", ["inventory_487.jpg", "inventory_irp_482.jpg", "inventory_irp_483.jpg"])
def test_irp_is_detected_in_backpack(fixture):
    frame = load_frame(fixture)
    meal = MealSystem()
    meal.load_templates(resolution_name(frame.shape[1], frame.shape[0]))

    match = meal.find_food_in_backpack(frame)

    assert match is not None
    assert match.key == "irp"
    assert match.source == "backpack"


def test_inventory_and_backpack_regions_do_not_overlap():
    frame = load_frame("inventory_irp_482.jpg")

    inventory_roi = MealSystem.inventory_items_roi(frame)
    backpack_roi = MealSystem.backpack_items_roi(frame)

    assert inventory_roi.x >= frame.shape[1] // 2
    assert backpack_roi.right <= frame.shape[1] // 2
    assert backpack_roi.y >= frame.shape[0] // 2
