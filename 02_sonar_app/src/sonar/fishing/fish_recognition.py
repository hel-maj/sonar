from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path

import numpy as np

from sonar.fishing.constants import FISH_MATCH_THRESHOLD, PROCESS_NAME, fish_roi_for_resolution, resolution_name
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.capture import WindowCapture
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


@dataclass(slots=True)
class FishRecognition:
    process_name: str = PROCESS_NAME
    resource_dir: Path = FISHING_RESOURCE_DIR
    threshold: float = FISH_MATCH_THRESHOLD
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
        folder_name = "fish2k" if resolution == "2k" else "fishHd"
        template_dir = self.resource_dir / folder_name
        self.templates.clear()
        for path in sorted(template_dir.glob("*.png")):
            self.templates[path.stem] = load_template(path)

    def find_template(self, screenshot: np.ndarray, template: np.ndarray) -> TemplateMatch | None:
        height, width = screenshot.shape[:2]
        return self.matcher.find_best(screenshot, template, roi=fish_roi_for_resolution(width, height))

    def recognize_fish(self, screenshot: np.ndarray) -> tuple[str | None, float]:
        if not self.templates:
            height, width = screenshot.shape[:2]
            self.load_templates(resolution_name(width, height))
        best_name: str | None = None
        best_confidence = 0.0
        for fish_name, template in self.templates.items():
            match = self.find_template(screenshot, template)
            if match and match.confidence > best_confidence:
                best_name = fish_name
                best_confidence = match.confidence
        return best_name, best_confidence

    def recognize_once(self) -> tuple[str | None, float]:
        if self.capture.hwnd is None and not self.initialize():
            return None, 0.0
        return self.recognize_fish(self.capture.capture())

    def run(self) -> tuple[str | None, float]:
        return self.recognize_once()
