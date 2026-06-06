from __future__ import annotations

import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable

import numpy as np

from sonar.automation.input_controller import InputController
from sonar.fishing.constants import (
    HOOKING_MATCH_THRESHOLD,
    HOOKING_PAUSE_SECONDS,
    hooking_rois_for_resolution,
    resolution_name,
    template_scales_for_frame,
)
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


RED_PIXEL_MIN_CHANNEL = 120
RED_PIXEL_MIN_DELTA = 45
RED_MATCH_MIN_RATIO = 0.25
RED_MATCH_MIN_PIXELS = 20


@dataclass(slots=True)
class HookingResult:
    red_confidence: float
    bubles_confidence: float
    red_detected: bool
    bubles_detected: bool
    pressed: bool
    trigger_reason: str
    fps: float
    paused_remaining: float


@dataclass
class TemplateMonitor:
    roi1: Rect
    roi2: Rect
    resolution_type: str
    template_scales: tuple[float, ...] = (1.0,)
    resource_dir: Path = FISHING_RESOURCE_DIR
    input_controller: InputController = field(default_factory=InputController)
    focus_callback: Callable[[], bool] | None = None
    threshold: float = HOOKING_MATCH_THRESHOLD

    def __post_init__(self) -> None:
        self.matcher = TemplateMatcher(self.threshold)
        self.red_template: np.ndarray | None = None
        self.bubles_template: np.ndarray | None = None
        self.pause_until = 0.0
        self.last_frame_time = time.time()
        self.load_templates()

    def load_templates(self) -> None:
        trigger_dir = self.resource_dir / "triger"
        red_name = "red_2k.png" if self.resolution_type == "2k" else "red.png"
        bubles_name = "bubles_2k.png" if self.resolution_type == "2k" else "bubles.png"
        self.red_template = load_template(trigger_dir / red_name)
        self.bubles_template = load_template(trigger_dir / bubles_name)

    def match_template(self, frame: np.ndarray, template: np.ndarray, roi: Rect) -> tuple[float, bool]:
        match = self.matcher.find_best_scaled(frame, template, roi=roi, scales=self.template_scales)
        if match is None:
            return 0.0, False
        return match.confidence, True

    def match_red_template(self, frame: np.ndarray) -> tuple[float, bool]:
        assert self.red_template is not None
        match = self.matcher.find_best_scaled(frame, self.red_template, roi=self.roi1, scales=self.template_scales)
        if match is None or not self.is_red_match_valid(frame, match):
            return 0.0, False
        return match.confidence, True

    def is_red_match_valid(self, frame: np.ndarray, match: TemplateMatch) -> bool:
        top = match.y - match.height // 2
        left = match.x - match.width // 2
        bottom = top + match.height
        right = left + match.width
        if top < 0 or left < 0 or bottom > frame.shape[0] or right > frame.shape[1]:
            return False

        crop = frame[top:bottom, left:right]
        if crop.size == 0:
            return False

        blue = crop[:, :, 0].astype(np.int16)
        green = crop[:, :, 1].astype(np.int16)
        red = crop[:, :, 2].astype(np.int16)
        red_pixels = (
            (red >= RED_PIXEL_MIN_CHANNEL)
            & (red - green >= RED_PIXEL_MIN_DELTA)
            & (red - blue >= RED_PIXEL_MIN_DELTA)
        )
        red_count = int(np.count_nonzero(red_pixels))
        return red_count >= RED_MATCH_MIN_PIXELS and red_count / red_pixels.size >= RED_MATCH_MIN_RATIO

    def check_and_act(self, frame: np.ndarray) -> HookingResult:
        now = time.time()
        elapsed = max(now - self.last_frame_time, 0.001)
        self.last_frame_time = now
        fps = 1.0 / elapsed
        if now < self.pause_until:
            return HookingResult(0.0, 0.0, False, False, False, "", fps, self.pause_until - now)

        assert self.bubles_template is not None
        red_conf, red_detected = self.match_red_template(frame)
        bubles_conf, bubles_detected = self.match_template(frame, self.bubles_template, self.roi2)
        pressed = False
        reason = ""
        if red_detected or bubles_detected:
            reason = "red" if red_conf >= bubles_conf else "bubles"
            if self.focus_callback is not None:
                self.focus_callback()
            if self.input_controller.press_key("space") is not False:
                self.pause_until = now + HOOKING_PAUSE_SECONDS
                pressed = True
        return HookingResult(red_conf, bubles_conf, red_detected, bubles_detected, pressed, reason, fps, 0.0)


def create_monitor_for_frame(
    frame: np.ndarray,
    input_controller: InputController | None = None,
    focus_callback: Callable[[], bool] | None = None,
) -> TemplateMonitor:
    height, width = frame.shape[:2]
    resolution = resolution_name(width, height)
    roi1, roi2 = hooking_rois_for_resolution(width, height)
    return TemplateMonitor(
        roi1,
        roi2,
        resolution,
        template_scales=template_scales_for_frame(width, height, resolution),
        input_controller=input_controller or InputController(),
        focus_callback=focus_callback,
    )
