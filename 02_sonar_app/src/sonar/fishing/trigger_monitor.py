from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path

import numpy as np

from sonar.fishing.constants import TRIGGER_ROIS_FHD, resolution_name
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


TRIGGER_FILES = {
    "thirst": {"fullhd": "thirst.png", "2k": "thirst2k.png", "roi": "needs"},
    "hunger": {"fullhd": "hunger.png", "2k": "hunger2k.png", "roi": "needs"},
    "advantage": {"fullhd": "advantage.png", "2k": "advantage2k.png", "roi": "advantage"},
    "pereves": {"fullhd": "pereves.png", "2k": "pereves2k.png", "roi": "events"},
    "changed_bait": {"fullhd": "changeBait.png", "2k": "changed_Bait2k.png", "roi": "events"},
    "gear": {"fullhd": "gear.png", "2k": "gear_2k.png", "roi": "events"},
    "boat": {"fullhd": "boat.png", "2k": "boat2k.png", "roi": "boat_human"},
    "human": {"fullhd": "human.png", "2k": "human2k.png", "roi": "boat_human"},
    "start": {"fullhd": "start_action.png", "2k": "start_action_2k.png", "roi": "stage"},
    "start1": {"fullhd": "cast_action.png", "2k": "cast_action_2k.png", "roi": "stage"},
    "start2": {"fullhd": "hook_action.png", "2k": "hook_action_2k.png", "roi": "stage"},
    "wait_tension": {"fullhd": "wait_tension.png", "2k": "wait_tension_2k.png", "roi": "tension", "threshold": 0.75},
    "ad": {"fullhd": "AD.png", "2k": "AD_2k.png", "roi": "ad", "threshold": 0.65},
}


@dataclass(slots=True)
class TriggerMonitor:
    resource_dir: Path = FISHING_RESOURCE_DIR
    threshold: float = 0.8
    matcher: TemplateMatcher = field(init=False)
    templates: dict[str, dict[str, object]] = field(default_factory=dict)
    loaded_resolution: str | None = None

    def __post_init__(self) -> None:
        self.matcher = TemplateMatcher(self.threshold)

    def load_templates(self, resolution: str) -> None:
        trigger_dir = self.resource_dir / "triger"
        self.templates.clear()
        for name, info in TRIGGER_FILES.items():
            filename = str(info[resolution])
            path = trigger_dir / filename
            if path.exists():
                self.templates[name] = {
                    "image": load_template(path),
                    "roi": str(info["roi"]),
                    "threshold": info.get("threshold"),
                }
        self.loaded_resolution = resolution

    def detect(self, screenshot: np.ndarray) -> dict[str, float]:
        return {name: match.confidence for name, match in self.find_detections(screenshot).items()}

    def find_detections(self, screenshot: np.ndarray) -> dict[str, TemplateMatch]:
        height, width = screenshot.shape[:2]
        res = resolution_name(width, height)
        if not self.templates or self.loaded_resolution != res:
            self.load_templates(res)
        detections: dict[str, TemplateMatch] = {}
        for name, info in self.templates.items():
            roi_name = str(info["roi"])
            if res == "2k" and f"{roi_name}_2k" in TRIGGER_ROIS_FHD:
                roi_name = f"{roi_name}_2k"
            roi = TRIGGER_ROIS_FHD.get(roi_name)
            matcher = self.matcher
            if info.get("threshold") is not None:
                matcher = TemplateMatcher(float(info["threshold"]))
            match = matcher.find_best(screenshot, info["image"], roi=roi, name=name)  # type: ignore[arg-type]
            if match:
                detections[name] = match
        return detections
