from __future__ import annotations

import time
from dataclasses import dataclass
from enum import Enum

import cv2
import numpy as np

from sonar.automation.input_controller import InputController
from sonar.fishing.constants import (
    CASTING_PAUSE_SECONDS,
    GREEN_HSV_HIGH,
    GREEN_HSV_LOW,
    MIN_GREEN_PIXELS,
    casting_roi_for_resolution,
)
from sonar.vision.geometry import Rect


CAST_INPUT_LEAD_SECONDS = 0.075
MARKER_SAMPLE_MAX_AGE = 0.12
FAST_CAPTURE_PRESS_FPS = 35.0
SLOW_CAPTURE_LEAD_RATIO = 0.30
SLOW_CAPTURE_WINDOW_RATIO = 0.10


class GreenMonitorState(str, Enum):
    SEARCHING = "searching"
    TRACKING = "tracking"
    PAUSED = "paused"


@dataclass(slots=True)
class GreenPixelResult:
    count: int
    peak_count: int
    bbox_area: int
    bbox_rect: Rect | None
    marker_offset: float | None
    predicted_offset: float | None
    marker_velocity: float | None
    marker_age: float | None
    center_tolerance: float | None
    drop: int
    detected: bool
    pressed: bool
    fps: float
    paused_remaining: float


class GreenPixelMonitor:
    def __init__(self, roi: Rect, input_controller: InputController | None = None) -> None:
        self.roi = roi
        self.input_controller = input_controller or InputController()
        self.state = GreenMonitorState.SEARCHING
        self.peak_count = 0
        self.tight_bbox: Rect | None = None
        self.baseline_cols: np.ndarray | None = None
        self.pause_until = 0.0
        self.last_frame_time = time.time()
        self.last_count = 0
        self.last_marker_offset: float | None = None
        self.last_marker_time: float | None = None

    def _green_mask(self, frame: np.ndarray, roi: Rect | None = None) -> np.ndarray:
        region_roi = roi or self.roi
        height, width = frame.shape[:2]
        region_roi = region_roi.clamp(width, height)
        region = frame[region_roi.slice()]
        if region.size == 0:
            return np.zeros((0, 0), dtype=np.uint8)
        hsv = cv2.cvtColor(region, cv2.COLOR_BGR2HSV)
        return cv2.inRange(hsv, np.array(GREEN_HSV_LOW, dtype=np.uint8), np.array(GREEN_HSV_HIGH, dtype=np.uint8))

    def _count_green(self, frame: np.ndarray, roi: Rect | None = None) -> int:
        return int(cv2.countNonZero(self._green_mask(frame, roi)))

    def _find_tight_bbox(self, frame: np.ndarray) -> Rect | None:
        height, width = frame.shape[:2]
        roi = self.roi.clamp(width, height)
        region = frame[roi.slice()]
        if region.size == 0:
            return None
        hsv = cv2.cvtColor(region, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, np.array(GREEN_HSV_LOW, dtype=np.uint8), np.array(GREEN_HSV_HIGH, dtype=np.uint8))
        coords = cv2.findNonZero(mask)
        if coords is None:
            return None
        x, y, w, h = cv2.boundingRect(coords)
        return Rect(roi.x + x, roi.y + y, w, h)

    def _tap_space_fast(self) -> None:
        self.input_controller.key_down("space")
        time.sleep(0.015)
        self.input_controller.key_up("space")

    def _marker_offset_from_center(self, frame: np.ndarray) -> float | None:
        if self.tight_bbox is None:
            return None
        mask = self._green_mask(frame, self.tight_bbox)
        if mask.size == 0:
            return None
        cols = np.count_nonzero(mask, axis=0)
        if self.baseline_cols is None or self.baseline_cols.shape != cols.shape or int(cols.sum()) > int(self.baseline_cols.sum()):
            self.baseline_cols = cols.copy()
            return None
        deficit = self.baseline_cols.astype(np.int16) - cols.astype(np.int16)
        if deficit.size == 0:
            return None
        threshold = max(1, int(max(1, self.baseline_cols.max()) * 0.25))
        occluded = np.where(deficit >= threshold)[0]
        if occluded.size == 0:
            return None
        return float(occluded.mean() - ((len(cols) - 1) / 2.0))

    def check_and_act(self, frame: np.ndarray) -> GreenPixelResult:
        now = time.time()
        elapsed = max(now - self.last_frame_time, 0.001)
        self.last_frame_time = now
        fps = 1.0 / elapsed

        if now < self.pause_until:
            remaining = self.pause_until - now
            return GreenPixelResult(0, self.peak_count, -1, None, None, None, None, None, None, 0, False, False, fps, remaining)

        pressed = False
        count = self._count_green(frame, self.tight_bbox or self.roi)
        self.last_count = count
        detected = count >= MIN_GREEN_PIXELS
        marker_offset: float | None = None
        predicted_offset: float | None = None
        marker_velocity: float | None = None
        marker_age: float | None = None
        center_tolerance: float | None = None
        drop = 0

        if self.state != GreenMonitorState.TRACKING:
            if detected:
                self.tight_bbox = self._find_tight_bbox(frame)
                if self.tight_bbox is not None:
                    count = self._count_green(frame, self.tight_bbox)
                    self.last_count = count
                    self.baseline_cols = np.count_nonzero(self._green_mask(frame, self.tight_bbox), axis=0)
                self.peak_count = count
                self.state = GreenMonitorState.TRACKING
        else:
            if count > self.peak_count:
                self.peak_count = count
                if self.tight_bbox is not None:
                    self.baseline_cols = np.count_nonzero(self._green_mask(frame, self.tight_bbox), axis=0)
            marker_offset = self._marker_offset_from_center(frame)
            min_drop = max(30, int(self.peak_count * 0.03))
            drop = self.peak_count - count
            center_tolerance = max(2.5, (self.tight_bbox.width if self.tight_bbox else self.roi.width) * 0.04)
            predicted_offset = None
            if marker_offset is not None and self.last_marker_offset is not None and self.last_marker_time is not None:
                dt = max(now - self.last_marker_time, 0.001)
                marker_age = dt
                if dt <= MARKER_SAMPLE_MAX_AGE:
                    marker_velocity = (marker_offset - self.last_marker_offset) / dt
                    predicted_offset = marker_offset + marker_velocity * CAST_INPUT_LEAD_SECONDS
            if marker_offset is not None:
                self.last_marker_offset = marker_offset
                self.last_marker_time = now
            bbox_width = self.tight_bbox.width if self.tight_bbox else self.roi.width
            slow_capture_lead = min(max(bbox_width * SLOW_CAPTURE_LEAD_RATIO, center_tolerance * 3.0), bbox_width * 0.45)
            slow_capture_window = max(center_tolerance * 1.8, bbox_width * SLOW_CAPTURE_WINDOW_RATIO)
            current_centered = (
                marker_offset is not None
                and (
                    fps >= FAST_CAPTURE_PRESS_FPS
                    or abs(abs(marker_offset) - slow_capture_lead) <= slow_capture_window
                )
            )
            predicted_centered = predicted_offset is not None and abs(predicted_offset) <= center_tolerance
            centered_marker = current_centered or predicted_centered
            if self.peak_count >= MIN_GREEN_PIXELS and drop >= min_drop and centered_marker:
                result_peak_count = self.peak_count
                result_bbox_area = -1 if self.tight_bbox is None else self.tight_bbox.width * self.tight_bbox.height
                result_bbox_rect = self.tight_bbox
                pressed = True
                self.pause_until = now + CASTING_PAUSE_SECONDS
                self.state = GreenMonitorState.PAUSED
                self.tight_bbox = None
                self.baseline_cols = None
                self.last_marker_offset = None
                self.last_marker_time = None
                self.peak_count = 0
                return GreenPixelResult(
                    count,
                    result_peak_count,
                    result_bbox_area,
                    result_bbox_rect,
                    marker_offset,
                    predicted_offset,
                    marker_velocity,
                    marker_age,
                    center_tolerance,
                    drop,
                    detected,
                    pressed,
                    fps,
                    0.0,
                )
            if not detected:
                self.state = GreenMonitorState.SEARCHING
                self.tight_bbox = None
                self.baseline_cols = None
                self.last_marker_offset = None
                self.last_marker_time = None
                self.peak_count = 0

        bbox_area = -1 if self.tight_bbox is None else self.tight_bbox.width * self.tight_bbox.height
        return GreenPixelResult(
            count,
            self.peak_count,
            bbox_area,
            self.tight_bbox,
            marker_offset,
            predicted_offset,
            marker_velocity,
            marker_age,
            center_tolerance,
            drop,
            detected,
            pressed,
            fps,
            0.0,
        )

    def count_green_pixels(self, frame: np.ndarray) -> int:
        return self._count_green(frame)


def create_monitor_for_frame(frame: np.ndarray, input_controller: InputController | None = None) -> GreenPixelMonitor:
    height, width = frame.shape[:2]
    return GreenPixelMonitor(casting_roi_for_resolution(width, height), input_controller=input_controller)
