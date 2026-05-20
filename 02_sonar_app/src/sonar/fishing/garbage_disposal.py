from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path

import numpy as np

from sonar.automation.input_controller import InputController
from sonar.fishing.constants import (
    GARBAGE_MATCH_THRESHOLD,
    GARBAGE_TEMPLATE_FILES_2K,
    GARBAGE_TEMPLATE_FILES_FHD,
    garbage_roi_for_resolution,
    resolution_name,
)
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.capture import WindowCapture
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


GARBAGE_NAMES = {
    "corn": "corn can",
    "bag": "empty bag",
    "pack": "empty cigarette pack",
}


@dataclass(slots=True)
class GarbageDisposal:
    process_name: str = "gta5.exe"
    resource_dir: Path = FISHING_RESOURCE_DIR
    threshold: float = GARBAGE_MATCH_THRESHOLD
    input_controller: InputController = field(default_factory=InputController)
    capture: WindowCapture = field(init=False)
    matcher: TemplateMatcher = field(init=False)
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
        files = GARBAGE_TEMPLATE_FILES_2K if resolution == "2k" else GARBAGE_TEMPLATE_FILES_FHD
        template_dir = self.resource_dir / "garbage"
        self.templates = {key: load_template(template_dir / filename) for key, filename in files.items()}

    def find_template(self, screenshot: np.ndarray, template: np.ndarray) -> TemplateMatch | None:
        height, width = screenshot.shape[:2]
        return self.matcher.find_best(screenshot, template, roi=garbage_roi_for_resolution(width, height))

    def find_all_template_matches(self, screenshot: np.ndarray, template: np.ndarray, name: str) -> list[TemplateMatch]:
        height, width = screenshot.shape[:2]
        return self.matcher.find_all(screenshot, template, roi=garbage_roi_for_resolution(width, height), name=name)

    def find_all_garbage(self, screenshot: np.ndarray, enabled_keys: set[str] | None = None) -> list[dict[str, object]]:
        enabled = enabled_keys or set(self.templates)
        found: list[dict[str, object]] = []
        for key, template in self.templates.items():
            if key not in enabled:
                continue
            for match in self.find_all_template_matches(screenshot, template, key):
                found.append({"key": key, "name": GARBAGE_NAMES.get(key, key), "x": match.x, "y": match.y, "confidence": match.confidence})
        return sorted(found, key=lambda item: float(item["confidence"]), reverse=True)

    def dispose_garbage_by_position(self, garbage_info: dict[str, object], discard_key: str = "q") -> bool:
        x = int(garbage_info["x"])
        y = int(garbage_info["y"])
        self.input_controller.click(x, y, button="right")
        self.input_controller.sleep(0.3)
        self.input_controller.press_key(discard_key)
        self.input_controller.sleep(0.1)
        return True

    def run(self, enabled_keys: set[str] | None = None, discard_key: str = "q") -> int:
        if self.capture.hwnd is None and not self.initialize():
            return 0
        screenshot = self.capture.capture()
        items = self.find_all_garbage(screenshot, enabled_keys)
        for item in items:
            self.dispose_garbage_by_position(item, discard_key=discard_key)
        return len(items)
