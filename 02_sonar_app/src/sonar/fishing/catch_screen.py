from __future__ import annotations

import re
from dataclasses import dataclass, field
from pathlib import Path

import cv2
import numpy as np
from PIL import Image

from sonar.fishing.catch_quality import normalize_catch_size
from sonar.fishing.fish_names import fish_display_name, fish_id_from_display
from sonar.fishing.fish_recognition import FishRecognition
from sonar.ocr import configure_tesseract, has_tessdata, tessdata_config
from sonar.paths import FISHING_RESOURCE_DIR
from sonar.vision.geometry import Rect
from sonar.vision.matching import TemplateMatch, TemplateMatcher, load_template


CATCH_REFERENCE_WIDTH = 1920
CATCH_REFERENCE_HEIGHT = 1080
CATCH_MATCH_THRESHOLD = 0.58
MIN_CATCH_BUTTON_CONFIDENCE = 0.72


@dataclass(slots=True)
class CatchScreenResult:
    visible: bool
    keep_button: TemplateMatch | None = None
    release_button: TemplateMatch | None = None
    panel_rect: Rect | None = None
    fish_id: str | None = None
    fish_confidence: float = 0.0
    fish_text: str | None = None
    quality_text: str | None = None
    weight_text: str | None = None
    weight_kg: float | None = None
    xp_text: str | None = None
    xp_current: int | None = None
    xp_total: int | None = None
    is_max_level: bool = False


@dataclass
class CatchScreenDetector:
    resource_dir: Path = FISHING_RESOURCE_DIR
    fish_recognition: FishRecognition | None = None
    matcher: TemplateMatcher = field(default_factory=lambda: TemplateMatcher(CATCH_MATCH_THRESHOLD))
    templates: dict[str, np.ndarray] = field(default_factory=dict)

    def __post_init__(self) -> None:
        catch_dir = self.resource_dir / "catch"
        self.templates = {
            "keep": load_template(catch_dir / "keep_button.png"),
            "release": load_template(catch_dir / "release_button.png"),
        }

    def detect(self, frame: np.ndarray) -> CatchScreenResult:
        keep = self._find_button(frame, "keep")
        release = self._find_button(frame, "release")
        if keep is None or release is None:
            return CatchScreenResult(False, keep_button=keep, release_button=release)
        if not self._buttons_have_catch_layout(keep, release, frame.shape[1], frame.shape[0]):
            return CatchScreenResult(False, keep_button=keep, release_button=release)

        panel_rect = self._panel_rect(keep, release, frame.shape[1], frame.shape[0])
        fish_text = self._read_text(frame, self._fish_name_roi(panel_rect))
        text_fish_id = fish_id_from_display(fish_text)
        fish_id, confidence = self._recognize_fish(frame)
        if text_fish_id:
            fish_id = text_fish_id
            confidence = max(confidence, 0.95)
        elif fish_id is None:
            fish_id = text_fish_id
        quality_text = self._normalize_quality(self._read_text(frame, self._quality_roi(panel_rect)))
        weight_text = self._read_weight_text(frame, panel_rect)
        weight_kg = self._parse_weight(weight_text)
        xp_text = self._read_xp_text(frame, panel_rect)
        is_max_level, xp_current, xp_total = self._parse_xp(xp_text)
        if not self._has_valid_catch_content(fish_id, fish_text, weight_kg):
            return CatchScreenResult(False, keep_button=keep, release_button=release)
        return CatchScreenResult(
            True,
            keep_button=keep,
            release_button=release,
            panel_rect=panel_rect,
            fish_id=fish_id,
            fish_confidence=confidence,
            fish_text=fish_display_name(fish_id) if fish_id else fish_text,
            quality_text=quality_text,
            weight_text=weight_text,
            weight_kg=weight_kg,
            xp_text=xp_text,
            xp_current=xp_current,
            xp_total=xp_total,
            is_max_level=is_max_level,
        )

    @staticmethod
    def _buttons_have_catch_layout(keep: TemplateMatch, release: TemplateMatch, width: int, height: int) -> bool:
        if keep.confidence < MIN_CATCH_BUTTON_CONFIDENCE or release.confidence < MIN_CATCH_BUTTON_CONFIDENCE:
            return False
        if release.x <= keep.x:
            return False
        scale = max(0.45, min(3.0, (keep.width / 111 + release.width / 81) / 2.0))
        expected_gap = 170 * scale
        gap = release.x - keep.x
        return abs(keep.y - release.y) <= max(12, 18 * scale) and expected_gap * 0.45 <= gap <= expected_gap * 1.65

    @staticmethod
    def _has_valid_catch_content(fish_id: str | None, fish_text: str | None, weight_kg: float | None) -> bool:
        if weight_kg is None or not (0.01 <= weight_kg <= 500.0):
            return False
        if fish_id:
            return True
        if not fish_text:
            return False
        normalized = re.sub(r"[^0-9A-Za-zА-Яа-яЁё]+", "", fish_text)
        return len(normalized) >= 3

    def _find_button(self, frame: np.ndarray, name: str) -> TemplateMatch | None:
        h, w = frame.shape[:2]
        roi = Rect(int(w * 0.05), int(h * 0.40), int(w * 0.90), int(h * 0.58))
        return self.matcher.find_best_scaled(
            frame,
            self.templates[name],
            roi=roi,
            name=name,
            scales=self._scales_for_frame(w, h),
        )

    @staticmethod
    def _scales_for_frame(width: int, height: int) -> tuple[float, ...]:
        base = ((width / CATCH_REFERENCE_WIDTH) + (height / CATCH_REFERENCE_HEIGHT)) / 2.0
        values = {round(base * factor, 2) for factor in (0.70, 0.82, 0.92, 1.0, 1.08, 1.20, 1.38, 1.60, 2.0)}
        values.update({1.0, 1.2, 1.5})
        return tuple(sorted(value for value in values if 0.45 <= value <= 3.0))

    def _recognize_fish(self, frame: np.ndarray) -> tuple[str | None, float]:
        if self.fish_recognition is None:
            return None, 0.0
        return self.fish_recognition.recognize_fish(frame)

    @staticmethod
    def _panel_metrics(keep: TemplateMatch, release: TemplateMatch) -> tuple[float, float, float, float]:
        scale = max(0.6, min(3.0, (keep.width / 136 + release.width / 98) / 2.0))
        left = min(keep.x, release.x) - 95 * scale
        right = max(keep.x, release.x) + 115 * scale
        button_y = (keep.y + release.y) / 2.0
        return left, right, button_y, scale

    @staticmethod
    def _relative_roi(panel: Rect, x: float, y: float, width: float, height: float) -> Rect:
        return Rect(
            int(panel.x + panel.width * x),
            int(panel.y + panel.height * y),
            int(panel.width * width),
            int(panel.height * height),
        )

    @classmethod
    def _fish_name_roi(cls, panel: Rect) -> Rect:
        return cls._relative_roi(panel, 0.10, 0.56, 0.45, 0.08)

    @classmethod
    def _fish_weight_roi(cls, panel: Rect) -> Rect:
        return cls._relative_roi(panel, 0.68, 0.52, 0.28, 0.12)

    @classmethod
    def _fish_weight_number_rois(cls, panel: Rect) -> tuple[Rect, ...]:
        return (
            cls._fish_weight_roi(panel),
            cls._relative_roi(panel, 0.730, 0.535, 0.135, 0.10),
            cls._relative_roi(panel, 0.745, 0.55, 0.105, 0.09),
            cls._relative_roi(panel, 0.765, 0.55, 0.095, 0.09),
            cls._relative_roi(panel, 0.780, 0.56, 0.085, 0.08),
        )

    @classmethod
    def _quality_roi(cls, panel: Rect) -> Rect:
        return cls._relative_roi(panel, 0.10, 0.18, 0.42, 0.08)

    @classmethod
    def _xp_roi(cls, panel: Rect) -> Rect:
        return cls._relative_roi(panel, 0.06, 0.70, 0.88, 0.08)

    @classmethod
    def _xp_number_rois(cls, panel: Rect) -> tuple[Rect, ...]:
        return (
            cls._relative_roi(panel, 0.58, 0.69, 0.36, 0.09),
            cls._relative_roi(panel, 0.68, 0.69, 0.27, 0.09),
            cls._relative_roi(panel, 0.72, 0.69, 0.21, 0.09),
            cls._relative_roi(panel, 0.76, 0.69, 0.18, 0.09),
            cls._relative_roi(panel, 0.80, 0.69, 0.15, 0.09),
        )

    @classmethod
    def _panel_rect(cls, keep: TemplateMatch, release: TemplateMatch, width: int, height: int) -> Rect:
        left, right, button_y, scale = cls._panel_metrics(keep, release)
        return Rect(
            int(left - 55 * scale),
            int(button_y - 528 * scale),
            int((right - left) + 110 * scale),
            int(590 * scale),
        ).clamp(width, height)

    @staticmethod
    def crop_panel(frame: np.ndarray, result: CatchScreenResult) -> np.ndarray | None:
        if result.panel_rect is None:
            return None
        h, w = frame.shape[:2]
        roi = result.panel_rect.clamp(w, h)
        crop = frame[roi.slice()]
        return None if crop.size == 0 else crop

    @staticmethod
    def _read_text(frame: np.ndarray, roi: Rect, digits: bool = False) -> str | None:
        try:
            import pytesseract
        except Exception:
            return None
        CatchScreenDetector._configure_tesseract(pytesseract)
        h, w = frame.shape[:2]
        crop = frame[roi.clamp(w, h).slice()]
        if crop.size == 0:
            return None
        scaled = cv2.resize(crop, None, fx=3.0, fy=3.0, interpolation=cv2.INTER_CUBIC)
        gray = cv2.cvtColor(scaled, cv2.COLOR_BGR2GRAY)
        blurred = cv2.GaussianBlur(gray, (3, 3), 0)
        _, thresh = cv2.threshold(blurred, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
        config = "--psm 7"
        lang = "eng"
        if not digits and has_tessdata("rus"):
            lang = "rus"
            config = tessdata_config(config, lang)
        if digits:
            config += " -c tessedit_char_whitelist=0123456789.,"
        candidates = [
            Image.fromarray(cv2.cvtColor(scaled, cv2.COLOR_BGR2RGB)),
            Image.fromarray(gray),
            Image.fromarray(thresh),
        ]
        for candidate in candidates:
            try:
                text = pytesseract.image_to_string(candidate, lang=lang, config=config, timeout=5)
            except Exception:
                continue
            text = " ".join(text.replace("\n", " ").split())
            if text:
                return text
        return None

    @classmethod
    def _read_weight_text(cls, frame: np.ndarray, panel: Rect) -> str | None:
        fallback: str | None = None
        valid: list[tuple[str, float]] = []
        for roi in cls._fish_weight_number_rois(panel):
            text = cls._read_text(frame, roi, digits=True)
            weight = cls._parse_weight(text)
            if not text or weight is None:
                continue
            if fallback is None:
                fallback = text
            if not 0.01 <= weight < 15.0:
                continue
            if "." in text or "," in text:
                return text
            valid.append((text, weight))
        if valid:
            return min(valid, key=lambda item: item[1])[0]
        return fallback

    @classmethod
    def _read_xp_text(cls, frame: np.ndarray, panel: Rect) -> str | None:
        base_text = cls._read_text(frame, cls._xp_roi(panel))
        is_max_level, xp_current, xp_total = cls._parse_xp(base_text)
        if base_text and xp_total is not None:
            return base_text
        if base_text and (not is_max_level or (xp_current is not None and xp_current >= 10000)):
            return base_text
        number_texts: list[str] = []
        for roi in cls._xp_number_rois(panel):
            text = cls._read_text(frame, roi, digits=True)
            if text and re.search(r"\d", text):
                number_texts.append(text)
        best_number = cls._best_digit_text(number_texts)
        if not best_number:
            return base_text
        if not base_text:
            return best_number
        base_numbers = re.findall(r"\d+", base_text)
        if best_number in base_numbers:
            return base_text
        return f"{base_text} {best_number}"

    @staticmethod
    def _best_digit_text(values: list[str]) -> str | None:
        numbers = [re.sub(r"\D+", "", value) for value in values]
        numbers = [number for number in numbers if number]
        if not numbers:
            return None
        return max(numbers, key=lambda number: (len(number), int(number)))

    @staticmethod
    def _configure_tesseract(pytesseract_module) -> None:
        configure_tesseract(pytesseract_module)

    @staticmethod
    def _parse_weight(text: str | None) -> float | None:
        if not text:
            return None
        match = re.search(r"(\d+(?:[.,]\d+)?)", text)
        if not match:
            return None
        raw = match.group(1)
        try:
            if "." not in raw and "," not in raw and raw.isdigit() and len(raw) >= 3:
                return float(raw) / 100.0
            normalized = raw.replace(",", ".")
            if "." in normalized:
                whole, fraction = normalized.split(".", 1)
                normalized = f"{whole}.{fraction[:2]}"
            return float(normalized)
        except ValueError:
            return None

    @staticmethod
    def _normalize_quality(text: str | None) -> str | None:
        return normalize_catch_size(text)

    @staticmethod
    def _parse_xp(text: str | None) -> tuple[bool, int | None, int | None]:
        if not text:
            return False, None, None
        normalized = re.sub(r"[^0-9a-zа-яё/]+", "", text.lower())
        slash_match = re.search(r"(\d+)\s*/\s*(\d+)", text)
        if slash_match:
            return False, int(slash_match.group(1)), int(slash_match.group(2))
        numbers = [int(value) for value in re.findall(r"\d+", text)]
        if "максимальныйуровень" in normalized or "максималь" in normalized:
            if not numbers:
                return True, None, None
            xp = max(numbers, key=lambda value: (len(str(value)), value))
            return True, xp, None
        return False, numbers[0] if numbers else None, None
