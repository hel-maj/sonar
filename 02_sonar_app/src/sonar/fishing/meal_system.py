from __future__ import annotations

import time
from dataclasses import dataclass, field
from pathlib import Path

import numpy as np

from sonar.automation.input_controller import InputController
from sonar.fishing.constants import (
    MEAL_MATCH_THRESHOLD,
    MEAL_MAX_CONSUME,
    food_check_roi_for_resolution,
    inventory_roi_for_resolution,
    resolution_name,
    thirst_check_roi_for_resolution,
)
from sonar.fishing.item_info import ItemInfo, ItemInfoDetector
from sonar.fishing.player_status import PlayerStatus, PlayerStatusDetector, PlayerStatusMemoryDetector
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.capture import WindowCapture
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


MEAL_FILES = {
    "donut": {"fullhd": "donut.png", "2k": "donut2k.png"},
    "cocktail": {"fullhd": "cocktail.png", "2k": "cocktail2k.png"},
    "irp": {"fullhd": "irp.png", "2k": "irp2k.png"},
    "full_indicator": {"fullhd": "100%.png", "2k": "100%_2k.png"},
}

ITEM_TOOLTIP_INITIAL_WAIT_SECONDS = 1.55
ITEM_TOOLTIP_RETRY_SECONDS = 1.0
ITEM_TOOLTIP_RETRY_POLL_SECONDS = 0.2

MEAL_DISPLAY_NAMES = {
    "irp": "ИРП Армии США",
    "donut": "Пончик",
    "cocktail": "Коктейль",
}


@dataclass(frozen=True, slots=True)
class MealItemMatch:
    key: str
    match: TemplateMatch
    source: str


@dataclass(frozen=True, slots=True)
class MealItemSnapshot:
    key: str
    display_name: str
    item_title: str
    item_weight: str
    image: np.ndarray | None = None
    screen_image: np.ndarray | None = None
    item_info: ItemInfo | None = None
    player_status: PlayerStatus | None = None


@dataclass(frozen=True, slots=True)
class MealRunResult:
    consumed: tuple[MealItemSnapshot, ...] = ()
    moved_from_backpack: int = 0
    food_missing: bool = False
    still_needs_meal: bool = False

    @property
    def used_any(self) -> bool:
        return bool(self.consumed)


@dataclass
class MealSystem:
    process_name: str = "gta5.exe"
    resource_dir: Path = FISHING_RESOURCE_DIR
    threshold: float = MEAL_MATCH_THRESHOLD
    input_controller: InputController = field(default_factory=InputController)
    templates: dict[str, np.ndarray] = field(default_factory=dict)

    def __post_init__(self) -> None:
        self.capture = WindowCapture(self.process_name)
        self.matcher = TemplateMatcher(self.threshold)
        self.item_info_detector = ItemInfoDetector()
        self.status_detector = PlayerStatusDetector()
        self.status_memory_detector = PlayerStatusMemoryDetector(self.process_name)

    def initialize(self) -> bool:
        if not self.capture.find_window_by_process():
            return False
        width, height = self.capture.get_window_size()
        self.load_templates(resolution_name(width, height))
        return True

    def load_templates(self, resolution: str) -> None:
        meal_dir = self.resource_dir / "meal"
        self.templates = {name: load_template(meal_dir / files[resolution]) for name, files in MEAL_FILES.items()}

    def find_template(self, screenshot: np.ndarray, template: np.ndarray, roi: Rect | None = None):
        return self.matcher.find_best(screenshot, template, roi=roi)

    def check_food_full(self, screenshot: np.ndarray) -> bool:
        height, width = screenshot.shape[:2]
        template = self.templates.get("full_indicator")
        return bool(template is not None and self.find_template(screenshot, template, food_check_roi_for_resolution(width, height)))

    def check_thirst_full(self, screenshot: np.ndarray) -> bool:
        height, width = screenshot.shape[:2]
        template = self.templates.get("full_indicator")
        return bool(template is not None and self.find_template(screenshot, template, thirst_check_roi_for_resolution(width, height)))

    def check_needs_meal(
        self,
        screenshot: np.ndarray,
        *,
        food_threshold: int = 100,
        water_threshold: int = 100,
        health_threshold: int | None = None,
    ) -> bool:
        status = self.detect_player_status(screenshot)
        if status is not None and status.food is not None and status.water is not None:
            return status.has_needs(
                food_threshold=food_threshold,
                water_threshold=water_threshold,
                health_threshold=health_threshold,
            )
        return not (self.check_food_full(screenshot) and self.check_thirst_full(screenshot))

    def detect_player_status(
        self,
        screenshot: np.ndarray | None = None,
        *,
        allow_screenshot_fallback: bool = True,
    ) -> PlayerStatus | None:
        status = self.status_memory_detector.detect()
        if status is not None and (status.has_core_values() or not allow_screenshot_fallback) and screenshot is None:
            return status
        if not allow_screenshot_fallback:
            return status
        if screenshot is None:
            try:
                screenshot = self.capture.capture()
            except Exception:
                return status
        fallback = self.status_detector.detect(screenshot)
        if status is not None and fallback is not None:
            return fallback.merge_missing(status)
        return fallback or status

    def find_item_in_inventory(self, screenshot: np.ndarray, item_key: str):
        template = self.templates.get(item_key)
        if template is None:
            return None
        return self.find_template(screenshot, template, self.inventory_items_roi(screenshot))

    def find_item_in_backpack(self, screenshot: np.ndarray, item_key: str):
        template = self.templates.get(item_key)
        if template is None:
            return None
        return self.find_template(screenshot, template, self.backpack_items_roi(screenshot))

    def find_food(self, screenshot: np.ndarray) -> str | None:
        match = self.find_food_in_inventory(screenshot)
        return None if match is None else match.key

    def find_food_in_inventory(self, screenshot: np.ndarray) -> MealItemMatch | None:
        return self._find_food_in_area(screenshot, self.inventory_items_roi(screenshot), "inventory")

    def find_food_in_backpack(self, screenshot: np.ndarray) -> MealItemMatch | None:
        return self._find_food_in_area(screenshot, self.backpack_items_roi(screenshot), "backpack")

    def consume_item(self, x: int, y: int, item_name: str, use_key: str = "e") -> MealItemSnapshot:
        screen_x, screen_y = self.capture.client_to_screen(x, y)
        self.input_controller.move_to(screen_x, screen_y)
        snapshot_frame, item_info = self._capture_hovered_item_info()
        if snapshot_frame is None:
            snapshot_frame = self.capture.capture()
            item_info = self.item_info_detector.detect(snapshot_frame)
        image = self.item_info_detector.crop(snapshot_frame, item_info) if item_info is not None else None
        title = self._meal_item_title(item_name, item_info)
        weight = item_info.weight if item_info else ""
        self.input_controller.press_key(use_key)
        self.input_controller.sleep(0.1)
        return MealItemSnapshot(
            key=item_name,
            display_name=MEAL_DISPLAY_NAMES.get(item_name, item_name),
            item_title=title,
            item_weight=weight,
            image=image,
            screen_image=snapshot_frame,
            item_info=item_info,
        )

    @staticmethod
    def _meal_item_title(item_name: str, item_info: ItemInfo | None) -> str:
        display_name = MEAL_DISPLAY_NAMES.get(item_name, item_name)
        return item_info.title if item_info and item_info.title else display_name

    def _capture_hovered_item_info(self) -> tuple[np.ndarray | None, ItemInfo | None]:
        self.input_controller.sleep(ITEM_TOOLTIP_INITIAL_WAIT_SECONDS)
        deadline = time.monotonic() + ITEM_TOOLTIP_RETRY_SECONDS
        last_frame: np.ndarray | None = None
        while time.monotonic() <= deadline:
            last_frame = self.capture.capture()
            item_info = self.item_info_detector.detect(last_frame)
            if item_info is not None:
                return last_frame, item_info
            self.input_controller.sleep(ITEM_TOOLTIP_RETRY_POLL_SECONDS)
        return last_frame, None

    def move_item_from_backpack(self, match: MealItemMatch, move_key: str = "r") -> bool:
        screen_x, screen_y = self.capture.client_to_screen(match.match.x, match.match.y)
        self.input_controller.move_to(screen_x, screen_y)
        self.input_controller.sleep(0.35)
        self.input_controller.press_key(move_key)
        self.input_controller.sleep(1.0)
        return True

    def consume_irp(self, use_key: str = "e") -> bool:
        screenshot = self.capture.capture()
        match = self.find_item_in_inventory(screenshot, "irp")
        if match is None:
            return False
        self.consume_item(match.x, match.y, "irp", use_key=use_key)
        return True

    def consume_donuts_until_full(self, use_key: str = "e") -> int:
        consumed_count = 0
        for _ in range(MEAL_MAX_CONSUME):
            screenshot = self.capture.capture()
            if self.check_food_full(screenshot):
                break
            match = self.find_item_in_inventory(screenshot, "donut")
            if match is None:
                break
            self.consume_item(match.x, match.y, "donut", use_key=use_key)
            consumed_count += 1
        return consumed_count

    def consume_cocktails_until_full(self, use_key: str = "e") -> int:
        consumed_count = 0
        for _ in range(MEAL_MAX_CONSUME):
            screenshot = self.capture.capture()
            if self.check_thirst_full(screenshot):
                break
            match = self.find_item_in_inventory(screenshot, "cocktail")
            if match is None:
                break
            self.consume_item(match.x, match.y, "cocktail", use_key=use_key)
            consumed_count += 1
        return consumed_count

    def run(self, use_key: str = "e") -> dict[str, int | bool]:
        if self.capture.hwnd is None and not self.initialize():
            return {"irp": False, "donuts": 0, "cocktails": 0}
        width, height = self.capture.get_window_size()
        if not self.templates:
            self.load_templates(resolution_name(width, height))
        irp_used = self.consume_irp(use_key=use_key)
        donuts = self.consume_donuts_until_full(use_key=use_key)
        cocktails = self.consume_cocktails_until_full(use_key=use_key)
        return {"irp": irp_used, "donuts": donuts, "cocktails": cocktails}

    def _find_food_in_area(self, screenshot: np.ndarray, roi: Rect, source: str) -> MealItemMatch | None:
        for name in ("irp", "donut", "cocktail"):
            template = self.templates.get(name)
            if template is None:
                continue
            match = self.matcher.find_best(screenshot, template, roi=roi, name=name)
            if match is not None:
                return MealItemMatch(name, match, source)
        return None

    @staticmethod
    def inventory_items_roi(screenshot: np.ndarray) -> Rect:
        height, width = screenshot.shape[:2]
        right_half = Rect(width // 2, 0, width - width // 2, height)
        return MealSystem._intersect(inventory_roi_for_resolution(width, height), right_half).clamp(width, height)

    @staticmethod
    def backpack_items_roi(screenshot: np.ndarray) -> Rect:
        height, width = screenshot.shape[:2]
        left_lower = Rect(0, height // 2, width // 2, height - height // 2)
        return MealSystem._intersect(inventory_roi_for_resolution(width, height), left_lower).clamp(width, height)

    @staticmethod
    def _intersect(first: Rect, second: Rect) -> Rect:
        x1 = max(first.x, second.x)
        y1 = max(first.y, second.y)
        x2 = min(first.right, second.right)
        y2 = min(first.bottom, second.bottom)
        return Rect(x1, y1, max(0, x2 - x1), max(0, y2 - y1))
