from __future__ import annotations

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
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.capture import WindowCapture
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatcher, load_template


MEAL_FILES = {
    "donut": {"fullhd": "donut.png", "2k": "donut2k.png"},
    "cocktail": {"fullhd": "cocktail.png", "2k": "cocktail2k.png"},
    "irp": {"fullhd": "irp.png", "2k": "irp2k.png"},
    "full_indicator": {"fullhd": "100%.png", "2k": "100%_2k.png"},
}


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

    def find_item_in_inventory(self, screenshot: np.ndarray, item_key: str):
        height, width = screenshot.shape[:2]
        template = self.templates.get(item_key)
        if template is None:
            return None
        return self.find_template(screenshot, template, inventory_roi_for_resolution(width, height))

    def find_food(self, screenshot: np.ndarray) -> str | None:
        for name in ("irp", "donut", "cocktail"):
            template = self.templates.get(name)
            height, width = screenshot.shape[:2]
            if template is not None and self.matcher.find_best(screenshot, template, roi=inventory_roi_for_resolution(width, height), name=name):
                return name
        return None

    def consume_item(self, x: int, y: int, item_name: str, use_key: str = "e") -> bool:
        screen_x, screen_y = self.capture.client_to_screen(x, y)
        self.input_controller.move_to(screen_x, screen_y)
        self.input_controller.sleep(1.0)
        self.input_controller.press_key(use_key)
        self.input_controller.sleep(0.1)
        return True

    def consume_irp(self, use_key: str = "e") -> bool:
        screenshot = self.capture.capture()
        match = self.find_item_in_inventory(screenshot, "irp")
        if match is None:
            return False
        return self.consume_item(match.x, match.y, "irp", use_key=use_key)

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
