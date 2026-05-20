from __future__ import annotations

from dataclasses import dataclass
from datetime import datetime

import cv2
import numpy as np

from sonar.vision.geometry import Rect


TACKLE_REFERENCE_WIDTH = 1920
TACKLE_REFERENCE_HEIGHT = 1080
TACKLE_SLOT_SIZE = 69
TACKLE_SLOT_GAP = 11
TACKLE_TOTAL_VISIBLE_SLOTS = 7
TACKLE_ROW_BOTTOM_OFFSET = 77


@dataclass(frozen=True, slots=True)
class TackleSlotSpec:
    key: str
    name: str


TACKLE_SLOTS: tuple[TackleSlotSpec, ...] = (
    TackleSlotSpec("rod", "Удочка"),
    TackleSlotSpec("reel", "Катушка"),
    TackleSlotSpec("line", "Леска"),
    TackleSlotSpec("hook", "Крючки/поводки"),
    TackleSlotSpec("bait", "Наживка/блёсна"),
    TackleSlotSpec("net", "Подсак"),
)


@dataclass(frozen=True, slots=True)
class TackleItemCount:
    key: str
    name: str
    count: int


@dataclass(frozen=True, slots=True)
class TackleScanResult:
    items: tuple[TackleItemCount, ...]
    obscured: bool
    row_rect: Rect
    scanned_at: datetime

    def count_for(self, key: str) -> int:
        for item in self.items:
            if item.key == key:
                return item.count
        return 0


class TackleDetector:
    def detect(self, frame: np.ndarray) -> TackleScanResult:
        frame = _ensure_bgr(frame)
        height, width = frame.shape[:2]
        slots = self.slot_rects(width, height)
        items: list[TackleItemCount] = []
        for spec, rect in zip(TACKLE_SLOTS, slots):
            crop = frame[rect.clamp(width, height).slice()]
            occupied = self._is_slot_occupied(crop)
            quantity = 0
            if occupied:
                quantity = self._read_count(crop) or 1
            items.append(TackleItemCount(spec.key, spec.name, quantity))
        return TackleScanResult(
            items=tuple(items),
            obscured=self.is_obscured(frame),
            row_rect=self.row_rect(width, height),
            scanned_at=datetime.now(),
        )

    @classmethod
    def slot_rects(cls, width: int, height: int) -> tuple[Rect, ...]:
        scale = cls._scale(width, height)
        slot = max(1, int(round(TACKLE_SLOT_SIZE * scale)))
        gap = max(1, int(round(TACKLE_SLOT_GAP * scale)))
        total_width = TACKLE_TOTAL_VISIBLE_SLOTS * slot + (TACKLE_TOTAL_VISIBLE_SLOTS - 1) * gap
        left = int(round((width - total_width) / 2))
        top = int(round(height - (TACKLE_SLOT_SIZE + TACKLE_ROW_BOTTOM_OFFSET) * scale))
        return tuple(Rect(left + index * (slot + gap), top, slot, slot) for index in range(len(TACKLE_SLOTS)))

    @classmethod
    def visible_slot_rects(cls, width: int, height: int) -> tuple[Rect, ...]:
        scale = cls._scale(width, height)
        slot = max(1, int(round(TACKLE_SLOT_SIZE * scale)))
        gap = max(1, int(round(TACKLE_SLOT_GAP * scale)))
        total_width = TACKLE_TOTAL_VISIBLE_SLOTS * slot + (TACKLE_TOTAL_VISIBLE_SLOTS - 1) * gap
        left = int(round((width - total_width) / 2))
        top = int(round(height - (TACKLE_SLOT_SIZE + TACKLE_ROW_BOTTOM_OFFSET) * scale))
        return tuple(Rect(left + index * (slot + gap), top, slot, slot) for index in range(TACKLE_TOTAL_VISIBLE_SLOTS))

    @classmethod
    def row_rect(cls, width: int, height: int) -> Rect:
        scale = cls._scale(width, height)
        slot = max(1, int(round(TACKLE_SLOT_SIZE * scale)))
        gap = max(1, int(round(TACKLE_SLOT_GAP * scale)))
        total_width = len(TACKLE_SLOTS) * slot + (len(TACKLE_SLOTS) - 1) * gap
        visible_total = TACKLE_TOTAL_VISIBLE_SLOTS * slot + (TACKLE_TOTAL_VISIBLE_SLOTS - 1) * gap
        left = int(round((width - visible_total) / 2))
        top = int(round(height - (TACKLE_SLOT_SIZE + TACKLE_ROW_BOTTOM_OFFSET) * scale))
        pad_x = max(4, int(round(12 * scale)))
        pad_y = max(4, int(round(10 * scale)))
        return Rect(left - pad_x, top - pad_y, total_width + pad_x * 2, slot + pad_y * 2).clamp(width, height)

    @classmethod
    def crop_row(cls, frame: np.ndarray) -> np.ndarray:
        frame = _ensure_bgr(frame)
        height, width = frame.shape[:2]
        rect = cls.row_rect(width, height)
        return frame[rect.slice()].copy()

    @classmethod
    def is_obscured(cls, frame: np.ndarray) -> bool:
        frame = _ensure_bgr(frame)
        height, width = frame.shape[:2]
        scale = cls._scale(width, height)
        visible_slots = cls.visible_slot_rects(width, height)
        row = visible_slots[0]
        last = visible_slots[-1]
        left = max(0, row.x - int(round(20 * scale)))
        right = min(width, last.right + int(round(20 * scale)))
        top = max(0, row.y + row.height // 2)
        bottom = min(height, row.bottom + int(round(70 * scale)))
        if right <= left or bottom <= top:
            return False
        roi = frame[top:bottom, left:right]
        hsv = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
        yellow = (hsv[:, :, 0] >= 15) & (hsv[:, :, 0] <= 45) & (hsv[:, :, 1] > 70) & (hsv[:, :, 2] > 120)
        red = ((hsv[:, :, 0] <= 5) | (hsv[:, :, 0] >= 170)) & (hsv[:, :, 1] > 70) & (hsv[:, :, 2] > 120)
        color_mask = yellow | red
        for slot in visible_slots:
            sx0 = max(0, slot.x - left)
            sx1 = min(color_mask.shape[1], slot.right - left)
            sy0 = max(0, slot.y - top)
            sy1 = min(color_mask.shape[0], slot.bottom - top)
            color_mask[sy0:sy1, sx0:sx1] = False
        if not color_mask.any():
            return False
        components = cv2.connectedComponentsWithStats(color_mask.astype("uint8"), 8)[2]
        for index in range(1, components.shape[0]):
            _, _, component_width, component_height, area = components[index]
            if component_height >= max(25, int(round(25 * scale))) and component_width <= max(10, int(round(10 * scale))):
                return True
            if component_height >= max(45, int(round(45 * scale))) and area >= max(120, int(round(120 * scale * scale))):
                return True
        return False

    @staticmethod
    def _scale(width: int, height: int) -> float:
        return min(width / TACKLE_REFERENCE_WIDTH, height / TACKLE_REFERENCE_HEIGHT)

    @staticmethod
    def _is_slot_occupied(crop: np.ndarray) -> bool:
        if crop.size == 0:
            return False
        height, width = crop.shape[:2]
        body = crop[
            int(height * 0.12) : max(int(height * 0.12) + 1, int(height * 0.88)),
            int(width * 0.09) : max(int(width * 0.09) + 1, int(width * 0.91)),
        ]
        gray = cv2.cvtColor(body, cv2.COLOR_BGR2GRAY)
        hsv = cv2.cvtColor(body, cv2.COLOR_BGR2HSV)
        colorful_ratio = float(np.mean((hsv[:, :, 1] > 45) & (hsv[:, :, 2] > 50)))
        very_bright_ratio = float(np.mean(gray > 135))
        return float(gray.std()) >= 28.0 or colorful_ratio >= 0.03 or very_bright_ratio >= 0.02

    @classmethod
    def _read_count(cls, crop: np.ndarray) -> int | None:
        if crop.size == 0:
            return None
        if crop.shape[0] != TACKLE_SLOT_SIZE or crop.shape[1] != TACKLE_SLOT_SIZE:
            interpolation = cv2.INTER_AREA if crop.shape[0] > TACKLE_SLOT_SIZE else cv2.INTER_CUBIC
            crop = cv2.resize(crop, (TACKLE_SLOT_SIZE, TACKLE_SLOT_SIZE), interpolation=interpolation)
        height, width = crop.shape[:2]
        roi = crop[int(round(height * 0.65)) : height, int(round(width * 0.41)) : width]
        if roi.size == 0:
            return None
        hsv = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
        mask = ((hsv[:, :, 2] > 105) & (hsv[:, :, 1] < 90)).astype("uint8") * 255
        clean = np.zeros_like(mask)
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        for contour in contours:
            x, y, component_width, component_height = cv2.boundingRect(contour)
            if component_width * component_height < 3 or component_height < 3:
                continue
            if y + component_height <= mask.shape[0] * 0.35:
                continue
            clean[y : y + component_height, x : x + component_width] = np.maximum(
                clean[y : y + component_height, x : x + component_width],
                mask[y : y + component_height, x : x + component_width],
            )
        columns = np.where(clean.any(axis=0))[0]
        if len(columns) == 0:
            return None
        gaps = np.diff(columns)
        large_gaps = np.where(gaps >= 5)[0] if len(gaps) else []
        if len(large_gaps):
            clean[:, : columns[int(large_gaps[-1]) + 1]] = 0
            columns = np.where(clean.any(axis=0))[0]
        if len(columns) == 0:
            return None
        x_min, x_max = int(columns.min()), int(columns.max()) + 1
        rows = np.where(clean[:, x_min:x_max].any(axis=1))[0]
        if len(rows) == 0:
            return None
        cluster = clean[int(rows.min()) : int(rows.max()) + 1, x_min:x_max]
        digits = cls._split_digit_cluster(cluster)
        if not digits:
            return None
        text = ""
        distances: list[int] = []
        for digit in digits:
            value, distance = _classify_digit(digit)
            if value is None:
                return None
            text += value
            distances.append(distance)
        if not text or max(distances, default=0) > 14:
            return None
        try:
            return int(text)
        except ValueError:
            return None

    @staticmethod
    def _split_digit_cluster(cluster: np.ndarray) -> list[np.ndarray]:
        columns = np.where(cluster.any(axis=0))[0]
        if len(columns) == 0:
            return []
        ranges: list[tuple[int, int]] = []
        start = previous = int(columns[0])
        for column in columns[1:]:
            column = int(column)
            if column - previous > 1:
                ranges.append((start, previous + 1))
                start = column
            previous = column
        ranges.append((start, previous + 1))

        parts: list[np.ndarray] = []
        for left, right in ranges:
            width = right - left
            if width > 9:
                count = max(2, int(round(width / 6.5)))
                boundaries = [round(left + width * index / count) for index in range(count + 1)]
                for part_left, part_right in zip(boundaries[:-1], boundaries[1:]):
                    part = cluster[:, part_left:part_right]
                    if part.any():
                        parts.append(part)
            else:
                part = cluster[:, left:right]
                if part.any():
                    parts.append(part)

        trimmed: list[np.ndarray] = []
        for part in parts:
            rows = np.where(part.any(axis=1))[0]
            columns = np.where(part.any(axis=0))[0]
            if len(rows) == 0 or len(columns) == 0:
                continue
            digit = part[int(rows[0]) : int(rows[-1]) + 1, int(columns[0]) : int(columns[-1]) + 1]
            if digit.shape[0] >= 4 and digit.shape[1] >= 2:
                trimmed.append(digit)
        return trimmed


def format_tackle_items(items: tuple[TackleItemCount, ...] | list[TackleItemCount]) -> str:
    if not items:
        return "Снаряжение ещё не сканировалось"
    return "\n".join(f"{item.name}: {item.count}шт." for item in items)


def _ensure_bgr(frame: np.ndarray) -> np.ndarray:
    if frame.ndim == 2:
        return cv2.cvtColor(frame, cv2.COLOR_GRAY2BGR)
    if frame.shape[2] == 4:
        return cv2.cvtColor(frame, cv2.COLOR_BGRA2BGR)
    return frame


def _classify_digit(digit: np.ndarray) -> tuple[str | None, int]:
    resized = cv2.resize(digit, (5, 9), interpolation=cv2.INTER_AREA)
    grid = (resized > 80).astype("uint8")
    best_value: str | None = None
    best_distance = 999
    for value, template in _digit_templates():
        distance = int(np.count_nonzero(grid != template))
        if distance < best_distance:
            best_value = value
            best_distance = distance
    return best_value, best_distance


def _pattern(rows: tuple[str, ...]) -> np.ndarray:
    return np.array([[1 if char == "#" else 0 for char in row] for row in rows], dtype="uint8")


_HAND_DIGIT_PATTERNS: tuple[tuple[str, tuple[str, ...]], ...] = (
    ("0", (".###.", ".#.##", "#...#", "#...#", "#...#", "#...#", "#...#", ".#.##", ".###.")),
    ("1", (".####", "#####", "#####", "#####", ".####", ".####", ".####", ".###.", ".####")),
    ("1", ("...##", "..###", "##.##", "#..##", "...##", "...##", "...##", "...##", "...##")),
    ("2", (".###.", ".#.##", "....#", "...##", "...#.", "..##.", ".##..", ".##..", "#####")),
    ("3", ("####.", "....#", "....#", "..###", "..###", "..###", "....#", "#...#", "####.")),
    ("4", ("..##.", "..##.", ".###.", ".#.#.", ".#.#.", "#####", "#####", "...#.", "...#.")),
    ("6", (".####", ".#...", ".#...", "#####", "#####", ".#..#", ".#..#", ".#..#", ".###.")),
    ("8", ("####.", "#...#", "#...#", "#####", "#####", "#####", "#...#", "#...#", "####.")),
    ("8", (".###.", ".#..#", ".#..#", ".####", ".####", "#####", "##..#", ".#..#", ".###.")),
    ("9", (".###.", ".#..#", "##..#", "##..#", ".##.#", ".##.#", "....#", "...##", ".###.")),
    ("9", (".###.", "#..#.", "#..#.", "#..##", "#####", "#####", "...#.", "...#.", "####.")),
)


_DIGIT_TEMPLATE_CACHE: tuple[tuple[str, np.ndarray], ...] | None = None


def _digit_templates() -> tuple[tuple[str, np.ndarray], ...]:
    global _DIGIT_TEMPLATE_CACHE
    if _DIGIT_TEMPLATE_CACHE is not None:
        return _DIGIT_TEMPLATE_CACHE
    templates: list[tuple[str, np.ndarray]] = [(value, _pattern(rows)) for value, rows in _HAND_DIGIT_PATTERNS]
    for font, scale, thickness in (
        (cv2.FONT_HERSHEY_SIMPLEX, 0.6, 1),
        (cv2.FONT_HERSHEY_DUPLEX, 0.6, 1),
        (cv2.FONT_HERSHEY_PLAIN, 1.2, 1),
    ):
        for value in "057":
            image = np.zeros((32, 24), dtype="uint8")
            cv2.putText(image, value, (1, 24), font, scale, 255, thickness, cv2.LINE_AA)
            _, mask = cv2.threshold(image, 80, 255, cv2.THRESH_BINARY)
            rows, columns = np.where(mask > 0)
            if len(rows) == 0 or len(columns) == 0:
                continue
            crop = mask[int(rows.min()) : int(rows.max()) + 1, int(columns.min()) : int(columns.max()) + 1]
            resized = cv2.resize(crop, (5, 9), interpolation=cv2.INTER_AREA)
            templates.append((value, (resized > 80).astype("uint8")))
    _DIGIT_TEMPLATE_CACHE = tuple(templates)
    return _DIGIT_TEMPLATE_CACHE
