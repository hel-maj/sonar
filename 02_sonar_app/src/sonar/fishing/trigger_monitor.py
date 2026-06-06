from __future__ import annotations

from collections.abc import Iterable
from dataclasses import dataclass, field
from pathlib import Path

import cv2
import numpy as np

from sonar.fishing.constants import (
    frame_scale,
    reference_size_for_resolution,
    resolution_name,
    template_scales_for_frame,
    trigger_roi_for_resolution,
)
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

    def detect(self, screenshot: np.ndarray, names: Iterable[str] | None = None) -> dict[str, float]:
        return {name: match.confidence for name, match in self.find_detections(screenshot, names=names).items()}

    def find_detections(self, screenshot: np.ndarray, names: Iterable[str] | None = None) -> dict[str, TemplateMatch]:
        height, width = screenshot.shape[:2]
        res = resolution_name(width, height)
        if not self.templates or self.loaded_resolution != res:
            self.load_templates(res)
        search_frame, scale_x, scale_y = self._normalized_search_frame(screenshot, res)
        search_height, search_width = search_frame.shape[:2]
        wanted = set(names) if names is not None else None
        scales = self._template_scales(search_width, search_height, res)
        detections: dict[str, TemplateMatch] = {}
        for name, info in self.templates.items():
            if wanted is not None and name not in wanted:
                continue
            roi = trigger_roi_for_resolution(str(info["roi"]), search_width, search_height)
            matcher = self.matcher
            if info.get("threshold") is not None:
                matcher = TemplateMatcher(float(info["threshold"]))
            match = matcher.find_best_scaled(
                search_frame,
                info["image"],  # type: ignore[arg-type]
                roi=roi,
                name=name,
                scales=scales,
            )
            if match:
                detections[name] = self._scale_match(match, scale_x, scale_y)
        return detections

    @staticmethod
    def _normalized_search_frame(screenshot: np.ndarray, resolution: str) -> tuple[np.ndarray, float, float]:
        height, width = screenshot.shape[:2]
        reference_width, reference_height = reference_size_for_resolution(resolution)
        if width <= int(reference_width * 1.12) and height <= int(reference_height * 1.12):
            return screenshot, 1.0, 1.0
        aspect = width / max(1, height)
        reference_aspect = reference_width / reference_height
        if abs(aspect - reference_aspect) / reference_aspect > 0.025:
            return screenshot, 1.0, 1.0
        resized = cv2.resize(screenshot, (reference_width, reference_height), interpolation=cv2.INTER_AREA)
        return resized, width / reference_width, height / reference_height

    @staticmethod
    def _scale_match(match: TemplateMatch, scale_x: float, scale_y: float) -> TemplateMatch:
        if scale_x == 1.0 and scale_y == 1.0:
            return match
        return TemplateMatch(
            x=int(round(match.x * scale_x)),
            y=int(round(match.y * scale_y)),
            confidence=match.confidence,
            width=max(1, int(round(match.width * scale_x))),
            height=max(1, int(round(match.height * scale_y))),
            name=match.name,
        )

    @staticmethod
    def _template_scales(width: int, height: int, template_resolution: str) -> tuple[float, ...]:
        base = frame_scale(width, height, reference_resolution=template_resolution)
        if abs(base - 1.0) <= 0.02:
            return (1.0,)
        return template_scales_for_frame(width, height, template_resolution)
