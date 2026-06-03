from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path

import numpy as np

from sonar.automation.input_controller import InputController
from sonar.fishing.constants import PROCESS_NAME, STORE_FISH_MATCH_THRESHOLD, inventory_roi_for_resolution
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.capture import WindowCapture
from sonar.vision.matching import TemplateMatcher, load_template


@dataclass
class FishStorer:
    process_name: str = PROCESS_NAME
    resource_dir: Path = FISHING_RESOURCE_DIR
    threshold: float = STORE_FISH_MATCH_THRESHOLD
    input_controller: InputController = field(default_factory=InputController)
    templates: dict[str, np.ndarray] = field(default_factory=dict)
    remove_template: np.ndarray | None = None

    def __post_init__(self) -> None:
        self.capture = WindowCapture(self.process_name)
        self.matcher = TemplateMatcher(self.threshold)

    def initialize(self) -> bool:
        if not self.capture.find_window_by_process():
            return False
        self.load_templates()
        return True

    def load_templates(self) -> None:
        template_dir = self.resource_dir / "fish"
        self.templates = {path.stem: load_template(path) for path in sorted(template_dir.glob("*.png")) if path.stem != "remove"}
        remove_path = template_dir / "remove.png"
        self.remove_template = load_template(remove_path) if remove_path.exists() else None

    def find_template(self, screenshot: np.ndarray, template: np.ndarray):
        height, width = screenshot.shape[:2]
        return self.matcher.find_best(screenshot, template, roi=inventory_roi_for_resolution(width, height))

    def find_all_fish(self, screenshot: np.ndarray, fish_to_keep: set[str]) -> list[dict[str, object]]:
        found: list[dict[str, object]] = []
        for fish_name, template in self.templates.items():
            if fish_name not in fish_to_keep:
                continue
            height, width = screenshot.shape[:2]
            roi = inventory_roi_for_resolution(width, height)
            for match in self.matcher.find_all(screenshot, template, roi=roi, name=fish_name):
                found.append({"fish": fish_name, "x": match.x, "y": match.y, "confidence": match.confidence})
        return found

    def store_fish_by_position(self, fish_info: dict[str, object]) -> bool:
        self.input_controller.click(int(fish_info["x"]), int(fish_info["y"]), button="right")
        self.input_controller.sleep(0.3)
        if self.remove_template is None:
            return True
        screenshot = self.capture.capture()
        remove_match = self.matcher.find_best(screenshot, self.remove_template)
        if remove_match is None:
            return False
        self.input_controller.click(remove_match.x, remove_match.y)
        self.input_controller.sleep(0.5)
        return True

    def run(self, fish_to_keep: set[str]) -> int:
        if self.capture.hwnd is None and not self.initialize():
            return 0
        screenshot = self.capture.capture()
        if not self.templates:
            self.load_templates()
        fish_positions = self.find_all_fish(screenshot, fish_to_keep)
        stored_count = 0
        for fish_info in fish_positions:
            if self.store_fish_by_position(fish_info):
                stored_count += 1
        return stored_count
