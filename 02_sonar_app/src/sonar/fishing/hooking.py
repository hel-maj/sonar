from __future__ import annotations

import time
from dataclasses import dataclass, field
from pathlib import Path

import numpy as np

from sonar.automation.input_controller import InputController
from sonar.fishing.constants import HOOKING_MATCH_THRESHOLD, HOOKING_PAUSE_SECONDS, hooking_rois_for_resolution, resolution_name
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatcher, load_template


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
    resource_dir: Path = FISHING_RESOURCE_DIR
    input_controller: InputController = field(default_factory=InputController)
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
        match = self.matcher.find_best(frame, template, roi=roi)
        if match is None:
            return 0.0, False
        return match.confidence, True

    def check_and_act(self, frame: np.ndarray) -> HookingResult:
        now = time.time()
        elapsed = max(now - self.last_frame_time, 0.001)
        self.last_frame_time = now
        fps = 1.0 / elapsed
        if now < self.pause_until:
            return HookingResult(0.0, 0.0, False, False, False, "", fps, self.pause_until - now)

        assert self.red_template is not None
        assert self.bubles_template is not None
        red_conf, red_detected = self.match_template(frame, self.red_template, self.roi1)
        bubles_conf, bubles_detected = self.match_template(frame, self.bubles_template, self.roi2)
        pressed = False
        reason = ""
        if red_detected or bubles_detected:
            reason = "red" if red_conf >= bubles_conf else "bubles"
            if self.input_controller.press_key("space") is not False:
                self.pause_until = now + HOOKING_PAUSE_SECONDS
                pressed = True
        return HookingResult(red_conf, bubles_conf, red_detected, bubles_detected, pressed, reason, fps, 0.0)


def create_monitor_for_frame(frame: np.ndarray, input_controller: InputController | None = None) -> TemplateMonitor:
    height, width = frame.shape[:2]
    roi1, roi2 = hooking_rois_for_resolution(width, height)
    return TemplateMonitor(roi1, roi2, resolution_name(width, height), input_controller=input_controller or InputController())
