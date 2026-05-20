from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path

import numpy as np

from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


MENU_REFERENCE_WIDTH = 1920
MENU_REFERENCE_HEIGHT = 1080
MENU_MATCH_THRESHOLD = 0.74


@dataclass
class GameMenuDetector:
    resource_dir: Path = FISHING_RESOURCE_DIR
    matcher: TemplateMatcher = field(default_factory=lambda: TemplateMatcher(MENU_MATCH_THRESHOLD))
    templates: dict[str, np.ndarray] = field(default_factory=dict)

    def __post_init__(self) -> None:
        menu_dir = self.resource_dir / "menu"
        self.templates = {
            "menu_hide": load_template(menu_dir / "menu_hide.png"),
            "menu_back": load_template(menu_dir / "menu_back.png"),
        }

    def detect(self, frame: np.ndarray) -> TemplateMatch | None:
        height, width = frame.shape[:2]
        roi = Rect(width // 2, height // 2, width - width // 2, height - height // 2)
        best: TemplateMatch | None = None
        for name, template in self.templates.items():
            match = self.matcher.find_best_scaled(
                frame,
                template,
                roi=roi,
                name=name,
                scales=self._scales_for_frame(width, height),
            )
            if match and (best is None or match.confidence > best.confidence):
                best = match
        return best

    def is_open(self, frame: np.ndarray) -> bool:
        return self.detect(frame) is not None

    @staticmethod
    def _scales_for_frame(width: int, height: int) -> tuple[float, ...]:
        base = ((width / MENU_REFERENCE_WIDTH) + (height / MENU_REFERENCE_HEIGHT)) / 2.0
        values = {round(base * factor, 2) for factor in (0.70, 0.82, 0.92, 1.0, 1.08, 1.20, 1.38, 1.60)}
        values.add(1.0)
        return tuple(sorted(value for value in values if 0.45 <= value <= 3.0))
