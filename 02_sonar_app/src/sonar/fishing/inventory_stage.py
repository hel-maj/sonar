from __future__ import annotations

import re
import time
from dataclasses import dataclass, field
from pathlib import Path

import cv2
import numpy as np
from PIL import Image

from sonar.ocr import configure_tesseract, tessdata_config
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


INVENTORY_REFERENCE_WIDTH = 1920
INVENTORY_REFERENCE_HEIGHT = 1080
INVENTORY_TITLE_MATCH_THRESHOLD = 0.86
INVENTORY_CLOSE_MATCH_THRESHOLD = 0.72


@dataclass
class InventoryStageDetector:
    resource_dir: Path = FISHING_RESOURCE_DIR
    title_matcher: TemplateMatcher = field(default_factory=lambda: TemplateMatcher(INVENTORY_TITLE_MATCH_THRESHOLD))
    close_matcher: TemplateMatcher = field(default_factory=lambda: TemplateMatcher(INVENTORY_CLOSE_MATCH_THRESHOLD))
    title_template: np.ndarray | None = None
    close_template: np.ndarray | None = None
    _last_cache_at: float = field(default=0.0, init=False)
    _last_cache_signature: tuple[int, int, int, int] | None = field(default=None, init=False)
    _last_cache_result: TemplateMatch | None = field(default=None, init=False)

    def __post_init__(self) -> None:
        self.title_template = load_template(self.resource_dir / "inventory" / "inventory_text.png")
        self.close_template = load_template(self.resource_dir / "inventory" / "inventory_close.png")

    def detect(self, frame: np.ndarray) -> TemplateMatch | None:
        height, width = frame.shape[:2]
        roi = self._top_text_roi(width, height)
        signature = self._cache_signature(frame, roi)
        now = time.time()
        if self._last_cache_signature == signature and now - self._last_cache_at < 0.35:
            return self._last_cache_result

        result = self._detect_by_template(frame, roi)
        if result is None:
            result = self._detect_by_text(frame, roi)
        self._last_cache_at = now
        self._last_cache_signature = signature
        self._last_cache_result = result
        return result

    def detect_close(self, frame: np.ndarray) -> TemplateMatch | None:
        if self.close_template is None:
            return None
        height, width = frame.shape[:2]
        return self.close_matcher.find_best_scaled(
                frame,
                self.close_template,
                roi=self._top_right_roi(width, height),
                name="inventory_close",
                scales=self._scales_for_frame(width, height),
        )

    def is_open(self, frame: np.ndarray) -> bool:
        return self.detect(frame) is not None

    @staticmethod
    def _top_right_roi(width: int, height: int) -> Rect:
        return Rect(width // 2, 0, width - width // 2, height // 2)

    @staticmethod
    def _top_text_roi(width: int, height: int) -> Rect:
        return Rect(0, 0, width, max(1, height // 5))

    @staticmethod
    def _cache_signature(frame: np.ndarray, roi: Rect) -> tuple[int, int, int, int]:
        crop = frame[roi.slice()]
        sample = crop[:: max(1, crop.shape[0] // 32), :: max(1, crop.shape[1] // 64)]
        return (frame.shape[1], frame.shape[0], int(np.mean(sample)), int(np.std(sample)))

    def _detect_by_template(self, frame: np.ndarray, roi: Rect) -> TemplateMatch | None:
        if self.title_template is None:
            return None
        height, width = frame.shape[:2]
        return self.title_matcher.find_best_scaled(
            frame,
            self.title_template,
            roi=roi,
            name="inventory_text",
            scales=self._scales_for_frame(width, height),
        )

    def _detect_by_text(self, frame: np.ndarray, roi: Rect) -> TemplateMatch | None:
        text = self._read_top_text(frame, roi)
        if not text:
            return None
        normalized = self._normalize_text(text)
        if "окружение" not in normalized or "инвентарь" not in normalized:
            return None
        return TemplateMatch(
            x=roi.x + roi.width // 2,
            y=roi.y + roi.height // 2,
            confidence=1.0,
            width=roi.width,
            height=roi.height,
            name="inventory_text",
        )

    @staticmethod
    def _read_top_text(frame: np.ndarray, roi: Rect) -> str | None:
        try:
            import pytesseract
        except Exception:
            return None
        InventoryStageDetector._configure_tesseract(pytesseract)
        h, w = frame.shape[:2]
        crop = frame[roi.clamp(w, h).slice()]
        if crop.size == 0:
            return None
        scaled = cv2.resize(crop, None, fx=2.0, fy=2.0, interpolation=cv2.INTER_CUBIC)
        gray = cv2.cvtColor(scaled, cv2.COLOR_BGR2GRAY)
        _, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
        config = "--psm 6"
        lang = "rus"
        config = tessdata_config(config, lang)
        candidates = (Image.fromarray(gray), Image.fromarray(thresh))
        for candidate in candidates:
            try:
                text = pytesseract.image_to_string(candidate, lang=lang, config=config)
            except Exception:
                continue
            text = " ".join(text.replace("\n", " ").split())
            if text:
                return text
        return None

    @staticmethod
    def _normalize_text(text: str) -> str:
        return re.sub(r"[^0-9a-zа-яё]+", "", text.lower())

    @staticmethod
    def _configure_tesseract(pytesseract_module) -> None:
        configure_tesseract(pytesseract_module)

    @staticmethod
    def _scales_for_frame(width: int, height: int) -> tuple[float, ...]:
        base = ((width / INVENTORY_REFERENCE_WIDTH) + (height / INVENTORY_REFERENCE_HEIGHT)) / 2.0
        values = {round(base * factor, 2) for factor in (0.65, 0.78, 0.90, 1.0, 1.12, 1.28, 1.50, 1.75, 2.0)}
        return tuple(sorted(value for value in values if 0.35 <= value <= 3.0))
