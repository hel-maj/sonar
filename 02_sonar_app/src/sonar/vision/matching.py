from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

import cv2
import numpy as np

from sonar.vision.geometry import Rect


@dataclass(frozen=True, slots=True)
class TemplateMatch:
    x: int
    y: int
    confidence: float
    width: int
    height: int
    name: str = ""


def load_template(path: Path) -> np.ndarray:
    image = cv2.imread(str(path), cv2.IMREAD_COLOR)
    if image is None:
        raise FileNotFoundError(f"Template not readable: {path}")
    return image


def ensure_bgr(image: np.ndarray) -> np.ndarray:
    if image.ndim == 2:
        return cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)
    if image.shape[2] == 4:
        return cv2.cvtColor(image, cv2.COLOR_BGRA2BGR)
    return image


class TemplateMatcher:
    def __init__(self, threshold: float = 0.8) -> None:
        self.threshold = threshold

    def find_best(
        self,
        screenshot: np.ndarray,
        template: np.ndarray,
        roi: Rect | None = None,
        name: str = "",
    ) -> TemplateMatch | None:
        search_area, offset_x, offset_y = self._search_area(screenshot, roi)
        if search_area.size == 0:
            return None
        result = cv2.matchTemplate(ensure_bgr(search_area), ensure_bgr(template), cv2.TM_CCOEFF_NORMED)
        _, max_val, _, max_loc = cv2.minMaxLoc(result)
        if max_val < self.threshold:
            return None
        h, w = template.shape[:2]
        return TemplateMatch(
            x=offset_x + max_loc[0] + w // 2,
            y=offset_y + max_loc[1] + h // 2,
            confidence=float(max_val),
            width=w,
            height=h,
            name=name,
        )

    def find_all(
        self,
        screenshot: np.ndarray,
        template: np.ndarray,
        roi: Rect | None = None,
        name: str = "",
    ) -> list[TemplateMatch]:
        search_area, offset_x, offset_y = self._search_area(screenshot, roi)
        if search_area.size == 0:
            return []
        result = cv2.matchTemplate(ensure_bgr(search_area), ensure_bgr(template), cv2.TM_CCOEFF_NORMED)
        ys, xs = np.where(result >= self.threshold)
        h, w = template.shape[:2]
        matches = [
            TemplateMatch(
                x=offset_x + int(x) + w // 2,
                y=offset_y + int(y) + h // 2,
                confidence=float(result[y, x]),
                width=w,
                height=h,
                name=name,
            )
            for y, x in zip(ys, xs)
        ]
        return remove_overlapping_matches(matches, min_distance=max(w, h) // 2)

    def find_best_scaled(
        self,
        screenshot: np.ndarray,
        template: np.ndarray,
        roi: Rect | None = None,
        name: str = "",
        scales: tuple[float, ...] = (1.0,),
    ) -> TemplateMatch | None:
        best: TemplateMatch | None = None
        for scale in scales:
            scaled = resize_template(template, scale)
            if scaled is None:
                continue
            match = self.find_best(screenshot, scaled, roi=roi, name=name)
            if match and (best is None or match.confidence > best.confidence):
                best = match
        return best

    @staticmethod
    def _search_area(screenshot: np.ndarray, roi: Rect | None) -> tuple[np.ndarray, int, int]:
        if roi is None:
            return screenshot, 0, 0
        h, w = screenshot.shape[:2]
        clamped = roi.clamp(w, h)
        return screenshot[clamped.slice()], clamped.x, clamped.y


def remove_overlapping_matches(matches: list[TemplateMatch], min_distance: int) -> list[TemplateMatch]:
    ordered = sorted(matches, key=lambda item: item.confidence, reverse=True)
    filtered: list[TemplateMatch] = []
    for match in ordered:
        overlaps = any(((match.x - existing.x) ** 2 + (match.y - existing.y) ** 2) ** 0.5 < min_distance for existing in filtered)
        if not overlaps:
            filtered.append(match)
    return filtered


def resize_template(template: np.ndarray, scale: float) -> np.ndarray | None:
    if scale <= 0:
        return None
    h, w = template.shape[:2]
    new_w = max(1, int(round(w * scale)))
    new_h = max(1, int(round(h * scale)))
    if new_w < 3 or new_h < 3:
        return None
    if new_w == w and new_h == h:
        return template
    interpolation = cv2.INTER_AREA if scale < 1.0 else cv2.INTER_CUBIC
    return cv2.resize(template, (new_w, new_h), interpolation=interpolation)
