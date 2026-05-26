from __future__ import annotations

import ctypes
import json
import re
import statistics
import struct
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any
from ctypes import wintypes

import cv2
import numpy as np
import psutil

from sonar.fishing.memory_reeling import MEM_COMMIT, PAGE_GUARD, PAGE_NOACCESS, PROCESS_ALL_READ
from sonar.paths import LOG_DIR


STATUS_BAR_WIDTH_AT_1080P = 288.0
STATUS_BAR_MIN_WIDTH_AT_1080P = 55.0
STATUS_SEARCH_ROI = (0.30, 0.35, 0.70, 0.62)
MEMORY_PROFILE_GLOB = "player_status_memory_profile_*.json"
WEBENGINE_PROCESS_NAME = "majestic-webengine.exe"
WEBENGINE_PROCESS_SCAN_LIMIT = 4
WEBENGINE_SCAN_COOLDOWN_SECONDS = 2.5
WEBENGINE_SCAN_CHUNK_BYTES = 4 * 1024 * 1024
WEBENGINE_REGION_SCAN_LIMIT_BYTES = 96 * 1024 * 1024
WEBENGINE_WINDOW_BEFORE_BYTES = 64 * 1024
WEBENGINE_WINDOW_AFTER_BYTES = 160 * 1024
WEBENGINE_INDICATOR_RECORD_BYTES = 52
WEBENGINE_INDICATOR_SCORE_MIN = 60
WEBENGINE_MAX_MARKER_HITS_PER_REGION = 96
WEBENGINE_MARKERS = (
    b"inventory/indicators/v2/health.svg",
    b"inventory-interface full-width full-height router-view",
    b"weight__text-current",
)
READABLE_PROTECT_MASK = 0x02 | 0x04 | 0x08 | 0x20 | 0x40 | 0x80


class MEMORY_BASIC_INFORMATION(ctypes.Structure):
    _fields_ = [
        ("BaseAddress", ctypes.c_void_p),
        ("AllocationBase", ctypes.c_void_p),
        ("AllocationProtect", wintypes.DWORD),
        ("RegionSize", ctypes.c_size_t),
        ("State", wintypes.DWORD),
        ("Protect", wintypes.DWORD),
        ("Type", wintypes.DWORD),
    ]


@dataclass(frozen=True, slots=True)
class PlayerStatus:
    food: int | None = None
    water: int | None = None
    health: int | None = None
    inventory_weight: float | None = None
    inventory_weight_max: float | None = None
    backpack_weight: float | None = None
    backpack_weight_max: float | None = None
    source: str = ""

    def has_needs(
        self,
        *,
        food_threshold: int = 100,
        water_threshold: int = 100,
        health_threshold: int | None = None,
    ) -> bool:
        if self.food is not None and self.food < food_threshold:
            return True
        if self.water is not None and self.water < water_threshold:
            return True
        return bool(health_threshold is not None and self.health is not None and self.health < health_threshold)

    def merge_missing(self, fallback: "PlayerStatus") -> "PlayerStatus":
        fields = {
            "food": self.food if self.food is not None else fallback.food,
            "water": self.water if self.water is not None else fallback.water,
            "health": self.health if self.health is not None else fallback.health,
            "inventory_weight": self.inventory_weight if self.inventory_weight is not None else fallback.inventory_weight,
            "inventory_weight_max": self.inventory_weight_max if self.inventory_weight_max is not None else fallback.inventory_weight_max,
            "backpack_weight": self.backpack_weight if self.backpack_weight is not None else fallback.backpack_weight,
            "backpack_weight_max": self.backpack_weight_max if self.backpack_weight_max is not None else fallback.backpack_weight_max,
        }
        sources = tuple(dict.fromkeys(item for item in (self.source, fallback.source) if item))
        return PlayerStatus(**fields, source="+".join(sources))

    def has_core_values(self) -> bool:
        return self.food is not None and self.water is not None and self.health is not None

    def has_any_value(self) -> bool:
        return any(
            value is not None
            for value in (
                self.food,
                self.water,
                self.health,
                self.inventory_weight,
                self.inventory_weight_max,
                self.backpack_weight,
                self.backpack_weight_max,
            )
        )


@dataclass(frozen=True, slots=True)
class StatusBar:
    name: str
    percent: int
    rect: tuple[int, int, int, int]


class PlayerStatusDetector:
    def detect(self, frame: np.ndarray) -> PlayerStatus | None:
        bars = self.detect_bars(frame)
        values = {bar.name: bar.percent for bar in bars}
        if not {"food", "water", "health"}.issubset(values):
            return None
        return PlayerStatus(
            food=values["food"],
            water=values["water"],
            health=values["health"],
            source="screenshot",
        )

    def detect_bars(self, frame: np.ndarray) -> tuple[StatusBar, ...]:
        if frame.size == 0:
            return ()
        height, width = frame.shape[:2]
        scale = max(0.35, min(2.0, height / 1080.0))
        x1, y1, x2, y2 = self._search_roi(width, height)
        roi = frame[y1:y2, x1:x2]
        if roi.size == 0:
            return ()
        hsv = cv2.cvtColor(roi[:, :, :3], cv2.COLOR_BGR2HSV)
        masks = {
            "food": cv2.inRange(hsv, (12, 70, 95), (42, 255, 255)),
            "water": cv2.inRange(hsv, (85, 55, 95), (112, 255, 255)),
            "health": cv2.bitwise_or(
                cv2.inRange(hsv, (0, 70, 95), (10, 255, 255)),
                cv2.inRange(hsv, (170, 70, 95), (179, 255, 255)),
            ),
        }
        bars: list[StatusBar] = []
        expected_width = STATUS_BAR_WIDTH_AT_1080P * scale
        min_width = max(18, int(round(STATUS_BAR_MIN_WIDTH_AT_1080P * scale)))
        for name, mask in masks.items():
            rect = self._find_bar_component(mask, scale, min_width)
            if rect is None:
                continue
            local_x, local_y, local_w, local_h = rect
            percent = int(round((local_w / expected_width) * 100))
            percent = max(0, min(100, percent))
            bars.append(StatusBar(name, percent, (x1 + local_x, y1 + local_y, local_w, local_h)))
        bars = self._add_zero_bars_from_tracks(bars, roi, x1, y1, scale)
        return tuple(sorted(bars, key=lambda bar: bar.rect[1]))

    @staticmethod
    def _search_roi(width: int, height: int) -> tuple[int, int, int, int]:
        left, top, right, bottom = STATUS_SEARCH_ROI
        return int(width * left), int(height * top), int(width * right), int(height * bottom)

    @staticmethod
    def _find_bar_component(mask: np.ndarray, scale: float, min_width: int) -> tuple[int, int, int, int] | None:
        kernel = cv2.getStructuringElement(
            cv2.MORPH_RECT,
            (max(3, int(round(5 * scale))), max(1, int(round(2 * scale)))),
        )
        opened = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
        contours, _ = cv2.findContours(opened, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        candidates: list[tuple[int, int, int, int]] = []
        max_height = max(18, int(round(18 * scale)))
        min_height = max(2, int(round(2 * scale)))
        for contour in contours:
            x, y, width, height = cv2.boundingRect(contour)
            if width < min_width or height < min_height or height > max_height:
                continue
            if width / max(1, height) < 8.0:
                continue
            candidates.append((x, y, width, height))
        if not candidates:
            return None
        return max(candidates, key=lambda rect: (rect[2], -abs(rect[1] - mask.shape[0] // 2)))

    @staticmethod
    def _add_zero_bars_from_tracks(
        bars: list[StatusBar],
        roi: np.ndarray,
        roi_x: int,
        roi_y: int,
        scale: float,
    ) -> list[StatusBar]:
        found = {bar.name for bar in bars}
        if {"food", "water", "health"}.issubset(found):
            return bars
        bars_by_name = {bar.name: bar for bar in bars}
        inferred = PlayerStatusDetector._infer_zero_bars_from_spacing(bars_by_name)
        for bar in inferred:
            if bar.name not in found:
                bars.append(bar)
                found.add(bar.name)
        if {"food", "water", "health"}.issubset(found):
            return bars
        tracks = PlayerStatusDetector._find_status_tracks(roi, scale)
        if len(tracks) < 3:
            return bars
        tracks = sorted(tracks, key=lambda rect: rect[1])[:3]
        order = ("food", "water", "health")
        for name, track in zip(order, tracks):
            if name in found:
                continue
            x, y, width, height = track
            bars.append(StatusBar(name, 0, (roi_x + x, roi_y + y, width, height)))
        return bars

    @staticmethod
    def _infer_zero_bars_from_spacing(bars_by_name: dict[str, StatusBar]) -> list[StatusBar]:
        inferred: list[StatusBar] = []
        food = bars_by_name.get("food")
        water = bars_by_name.get("water")
        health = bars_by_name.get("health")
        if food is not None and health is not None and water is None:
            inferred.append(PlayerStatusDetector._zero_bar_like("water", food, (food.rect[1] + health.rect[1]) // 2))
        elif water is not None and health is not None and food is None:
            step = health.rect[1] - water.rect[1]
            if 8 <= step <= 60:
                inferred.append(PlayerStatusDetector._zero_bar_like("food", water, water.rect[1] - step))
        elif food is not None and water is not None and health is None:
            step = water.rect[1] - food.rect[1]
            if 8 <= step <= 60:
                inferred.append(PlayerStatusDetector._zero_bar_like("health", water, water.rect[1] + step))
        return inferred

    @staticmethod
    def _zero_bar_like(name: str, reference: StatusBar, y: int) -> StatusBar:
        x, _, width, height = reference.rect
        return StatusBar(name, 0, (x, y, width, height))

    @staticmethod
    def _find_status_tracks(roi: np.ndarray, scale: float) -> list[tuple[int, int, int, int]]:
        gray = cv2.cvtColor(roi[:, :, :3], cv2.COLOR_BGR2GRAY)
        mask = cv2.inRange(gray, 28, 88)
        kernel = cv2.getStructuringElement(
            cv2.MORPH_RECT,
            (max(8, int(round(40 * scale))), max(1, int(round(2 * scale)))),
        )
        closed = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
        contours, _ = cv2.findContours(closed, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        min_width = max(80, int(round(180 * scale)))
        max_height = max(14, int(round(14 * scale)))
        candidates: list[tuple[int, int, int, int]] = []
        for contour in contours:
            x, y, width, height = cv2.boundingRect(contour)
            if width < min_width or height > max_height or height < 1:
                continue
            if width / max(1, height) < 16.0:
                continue
            candidates.append((x, y, width, height))
        candidates.sort(key=lambda rect: (rect[1], -rect[2]))
        compact: list[tuple[int, int, int, int]] = []
        for rect in candidates:
            if any(abs(rect[1] - existing[1]) <= max(4, int(round(6 * scale))) for existing in compact):
                continue
            compact.append(rect)
        return compact


@dataclass(frozen=True, slots=True)
class MemoryStatusCandidate:
    field: str
    process_name: str
    addr: int
    value_type: str = "u8"
    scale: float = 1.0
    offset: float = 0.0
    min_value: float = 0.0
    max_value: float = 100.0


@dataclass(frozen=True, slots=True)
class WebengineStatusWindow:
    pid: int
    region_base: int
    region_size: int
    hit_addr: int


class PlayerStatusMemoryDetector:
    def __init__(
        self,
        process_name: str = "gta5.exe",
        *,
        report_dir: Path | None = None,
    ) -> None:
        self.process_name = process_name
        self.report_dir = report_dir or LOG_DIR / "memory_snapshots"
        self._profile_path: Path | None = None
        self._profile_mtime = 0.0
        self._candidates: tuple[MemoryStatusCandidate, ...] = ()
        self._handles: dict[int, int] = {}
        self._webengine_window: WebengineStatusWindow | None = None
        self._last_webengine_scan_at = 0.0

    def close(self) -> None:
        for handle in self._handles.values():
            ctypes.windll.kernel32.CloseHandle(handle)
        self._handles.clear()
        self._webengine_window = None

    def detect(self) -> PlayerStatus | None:
        profile_status = self._detect_profile_status()
        # Webengine keeps inventory UI snapshots and can lag while the inventory is closed.
        # Keep this fallback: it is still useful for weights and post-inventory verification.
        webengine_status = self._detect_webengine_status()
        if profile_status is not None and webengine_status is not None:
            return webengine_status.merge_missing(profile_status)
        return webengine_status or profile_status

    def _detect_profile_status(self) -> PlayerStatus | None:
        if not self._load_candidates():
            return None
        values: dict[str, list[int]] = {"food": [], "water": [], "health": []}
        for candidate in self._candidates:
            raw_value = self._read_candidate(candidate)
            if raw_value is None:
                continue
            value = int(round(raw_value * candidate.scale + candidate.offset))
            if int(candidate.min_value) <= value <= int(candidate.max_value):
                values.setdefault(candidate.field, []).append(value)
        result = {field: self._vote(field_values) for field, field_values in values.items()}
        if not any(value is not None for value in result.values()):
            return None
        return PlayerStatus(food=result.get("food"), water=result.get("water"), health=result.get("health"), source="memory")

    def _detect_webengine_status(self) -> PlayerStatus | None:
        cached_status: PlayerStatus | None = None
        if self._webengine_window is not None:
            cached_status = self._read_webengine_window(self._webengine_window)
            if cached_status is None or not cached_status.has_any_value():
                self._webengine_window = None
                cached_status = None

        now = time.monotonic()
        if now - self._last_webengine_scan_at < WEBENGINE_SCAN_COOLDOWN_SECONDS:
            return cached_status
        self._last_webengine_scan_at = now

        best_status: PlayerStatus | None = None
        best_window: WebengineStatusWindow | None = None
        best_score = 0
        best_hit_addr = 0
        for process in self._processes_by_name(WEBENGINE_PROCESS_NAME)[:WEBENGINE_PROCESS_SCAN_LIMIT]:
            handle = self._handle_for_process(process)
            if not handle:
                continue
            for region_base, region_size in self._readable_regions(handle):
                for hit_addr in self._find_webengine_marker_hits(handle, region_base, region_size):
                    window = WebengineStatusWindow(process.pid, region_base, region_size, hit_addr)
                    status = self._read_webengine_window(window)
                    if status is None:
                        continue
                    score = self._status_score(status)
                    if score > best_score or (score == best_score and hit_addr > best_hit_addr):
                        best_score = score
                        best_status = status
                        best_window = window
                        best_hit_addr = hit_addr
        self._webengine_window = best_window
        return best_status or cached_status

    def _read_webengine_window(self, window: WebengineStatusWindow) -> PlayerStatus | None:
        handle = self._handles.get(window.pid)
        if not handle:
            try:
                process = psutil.Process(window.pid)
            except (psutil.NoSuchProcess, psutil.AccessDenied):
                return None
            handle = self._handle_for_process(process)
        if not handle:
            return None
        start = max(window.region_base, window.hit_addr - WEBENGINE_WINDOW_BEFORE_BYTES)
        end = min(window.region_base + window.region_size, window.hit_addr + WEBENGINE_WINDOW_AFTER_BYTES)
        if end <= start:
            return None
        data = self._read_memory(handle, start, end - start)
        if not data:
            return None
        return self._parse_webengine_window(data)

    @classmethod
    def _parse_webengine_window(cls, data: bytes) -> PlayerStatus | None:
        if not any(marker in data for marker in WEBENGINE_MARKERS):
            return None
        food, water, health = cls._parse_indicator_values(data)
        inventory_weight, inventory_weight_max, backpack_weight, backpack_weight_max = cls._parse_weights(data)
        status = PlayerStatus(
            food=food,
            water=water,
            health=health,
            inventory_weight=inventory_weight,
            inventory_weight_max=inventory_weight_max,
            backpack_weight=backpack_weight,
            backpack_weight_max=backpack_weight_max,
            source="memory",
        )
        return status if status.has_any_value() else None

    @classmethod
    def _parse_weights(cls, data: bytes) -> tuple[float | None, float | None, float | None, float | None]:
        max_entries = cls._weight_max_entries(data)
        decimals = cls._decimal_entries(data)
        if not max_entries or not decimals:
            return None, None, None, None

        backpack_max_entry = cls._entry_for_weight_max(max_entries, 20.0)
        inventory_max_entry = cls._entry_for_weight_max(max_entries, 40.0)

        used_positions: set[int] = set()
        backpack_weight = None
        backpack_weight_max = backpack_max_entry[1] if backpack_max_entry is not None else None
        if backpack_max_entry is not None:
            backpack_weight_entry = cls._nearest_decimal_after(
                decimals,
                backpack_max_entry[0],
                max_value=backpack_max_entry[1],
                max_distance=2048,
            )
            if backpack_weight_entry is None:
                backpack_weight_entry = cls._nearest_decimal_around(
                    decimals,
                    backpack_max_entry[0],
                    max_value=backpack_max_entry[1],
                    max_distance=4096,
                )
            if backpack_weight_entry is not None:
                used_positions.add(backpack_weight_entry[0])
                backpack_weight = backpack_weight_entry[1]

        inventory_weight = None
        inventory_weight_max = inventory_max_entry[1] if inventory_max_entry is not None else None
        if inventory_max_entry is not None:
            inventory_weight_entry = cls._inventory_current_weight_entry(
                data,
                decimals,
                max_value=inventory_max_entry[1],
                excluded_positions=used_positions,
            )
            if inventory_weight_entry is None:
                inventory_weight_entry = cls._nearest_decimal_around(
                    decimals,
                    inventory_max_entry[0],
                    max_value=inventory_max_entry[1],
                    max_distance=24 * 1024,
                    excluded_positions=used_positions,
                )
            if inventory_weight_entry is not None:
                inventory_weight = inventory_weight_entry[1]

        return inventory_weight, inventory_weight_max, backpack_weight, backpack_weight_max

    @classmethod
    def _parse_indicator_values(cls, data: bytes) -> tuple[int | None, int | None, int | None]:
        candidates = cls._indicator_candidates(data)
        if not candidates:
            return None, None, None
        candidates.sort(key=lambda item: item[0], reverse=True)
        score, values = candidates[0]
        if score < WEBENGINE_INDICATOR_SCORE_MIN:
            return None, None, None
        return values

    @classmethod
    def _indicator_candidates(cls, data: bytes) -> list[tuple[int, tuple[int, int, int]]]:
        if len(data) < WEBENGINE_INDICATOR_RECORD_BYTES * 3:
            return []
        candidates: list[tuple[int, tuple[int, int, int]]] = []
        last_offset = len(data) - WEBENGINE_INDICATOR_RECORD_BYTES * 3
        for alignment in range(4):
            for offset in range(alignment, last_offset + 1, 4):
                records = cls._indicator_records_at(data, offset)
                if records is None:
                    continue
                score = cls._indicator_record_score(records)
                if score >= WEBENGINE_INDICATOR_SCORE_MIN:
                    values = (records[0][0] // 2, records[1][0] // 2, records[2][0] // 2)
                    candidates.append((score, values))
        return candidates

    @staticmethod
    def _indicator_records_at(data: bytes, offset: int) -> tuple[tuple[int, ...], tuple[int, ...], tuple[int, ...]] | None:
        records: list[tuple[int, ...]] = []
        for record_index in range(3):
            record_offset = offset + record_index * WEBENGINE_INDICATOR_RECORD_BYTES
            values = struct.unpack_from("<13I", data, record_offset)
            status_value = values[0]
            if status_value & 1:
                return None
            decoded = status_value // 2
            if not 0 <= decoded <= 100:
                return None
            records.append(values)
        return records[0], records[1], records[2]

    @staticmethod
    def _indicator_record_score(records: tuple[tuple[int, ...], tuple[int, ...], tuple[int, ...]]) -> int:
        score = 0
        first, second, third = records
        values = (first[0] // 2, second[0] // 2, third[0] // 2)
        if first[1] == second[1] == third[1] and first[1] & 1 and first[1] > 0x10000:
            score += 10
        if first[4] == second[4] == third[4] and first[4] & 1:
            score += 6
        if first[6] == second[6] == third[6] and first[6] & 1:
            score += 5
        if first[8] == second[8] == third[8] and first[9] == second[9] == third[9] and first[8] == first[9]:
            score += 8
        if first[7] == second[7] and third[7] != first[7]:
            score += 8
        if first[10] == second[10] and third[10] != first[10]:
            score += 8
        if first[11] == second[11] and third[11] != first[11]:
            score += 5
        if first[12] == second[12] and third[12] != first[12]:
            score += 5
        if values[2] >= 20:
            score += 4
        if values[0] >= 20 and values[1] >= 20:
            score += 4
        if values[0] >= values[2] or values[1] >= values[2]:
            score += 1
        return score

    @staticmethod
    def _weight_max_entries(data: bytes) -> list[tuple[int, float]]:
        entries: list[tuple[int, float]] = []
        for match in re.finditer(rb"(?<![A-Za-z0-9])/\s*(\d{1,3})\s*(?![A-Za-z0-9])", data):
            value = float(match.group(1))
            if 1 <= value <= 500:
                entries.append((match.start(), value))
        return entries

    @staticmethod
    def _decimal_entries(data: bytes) -> list[tuple[int, float]]:
        entries: list[tuple[int, float]] = []
        for match in re.finditer(rb"(?<![\d.])\d{1,3}\.\d{1,2}(?![\d.])", data):
            try:
                value = float(match.group().decode("ascii"))
            except ValueError:
                continue
            if 0 <= value <= 500:
                entries.append((match.start(), value))
        return entries

    @staticmethod
    def _entry_for_weight_max(entries: list[tuple[int, float]], value: float) -> tuple[int, float] | None:
        for entry in entries:
            if abs(entry[1] - value) < 0.01:
                return entry
        return None

    @staticmethod
    def _nearest_decimal_after(
        entries: list[tuple[int, float]],
        origin: int,
        *,
        max_value: float,
        max_distance: int,
        excluded_positions: set[int] | None = None,
    ) -> tuple[int, float] | None:
        excluded_positions = excluded_positions or set()
        candidates = [
            entry
            for entry in entries
            if entry[0] not in excluded_positions and origin <= entry[0] <= origin + max_distance and entry[1] <= max_value
        ]
        if not candidates:
            return None
        return min(candidates, key=lambda entry: entry[0] - origin)

    @staticmethod
    def _nearest_decimal_around(
        entries: list[tuple[int, float]],
        origin: int,
        *,
        max_value: float,
        max_distance: int,
        excluded_positions: set[int] | None = None,
    ) -> tuple[int, float] | None:
        excluded_positions = excluded_positions or set()
        candidates = [
            entry
            for entry in entries
            if entry[0] not in excluded_positions and abs(entry[0] - origin) <= max_distance and entry[1] <= max_value
        ]
        if not candidates:
            return None
        return min(candidates, key=lambda entry: abs(entry[0] - origin))

    @classmethod
    def _inventory_current_weight_entry(
        cls,
        data: bytes,
        entries: list[tuple[int, float]],
        *,
        max_value: float,
        excluded_positions: set[int],
    ) -> tuple[int, float] | None:
        marker_positions = [data.find(marker) for marker in (b"inventory/indicators/v2/health.svg", b"indicators/v2/health.svg")]
        marker_positions = [position for position in marker_positions if position >= 0]
        if not marker_positions:
            return None
        marker = min(marker_positions)
        candidates = [
            entry
            for entry in entries
            if entry[0] not in excluded_positions and 0 <= marker - entry[0] <= 24 * 1024 and entry[1] <= max_value
        ]
        if not candidates:
            return None
        return max(candidates, key=lambda entry: entry[0])

    @staticmethod
    def _status_score(status: PlayerStatus) -> int:
        score = 0
        core_values = sum(1 for value in (status.food, status.water, status.health) if value is not None)
        score += core_values
        if core_values == 3:
            score += 4
        if status.inventory_weight is not None and status.inventory_weight_max is not None:
            score += 3 if 39.0 <= status.inventory_weight_max <= 41.0 else 1
        if status.backpack_weight is not None and status.backpack_weight_max is not None:
            score += 3 if 19.0 <= status.backpack_weight_max <= 21.0 else 1
        return score

    def _find_webengine_marker_hits(self, handle: int, region_base: int, region_size: int) -> tuple[int, ...]:
        hits: list[int] = []
        scan_size = min(region_size, WEBENGINE_REGION_SCAN_LIMIT_BYTES)
        offset = 0
        carry = b""
        max_marker_len = max(len(marker) for marker in WEBENGINE_MARKERS)
        while offset < scan_size:
            chunk_size = min(WEBENGINE_SCAN_CHUNK_BYTES, scan_size - offset)
            chunk = self._read_memory(handle, region_base + offset, chunk_size)
            if chunk:
                data = carry + chunk
                base_adjust = region_base + offset - len(carry)
                for marker in WEBENGINE_MARKERS:
                    start = 0
                    while True:
                        index = data.find(marker, start)
                        if index < 0:
                            break
                        hit = base_adjust + index
                        if hit >= region_base:
                            hits.append(hit)
                        start = index + 1
                        if len(hits) >= WEBENGINE_MAX_MARKER_HITS_PER_REGION:
                            return tuple(dict.fromkeys(hits))
                carry = data[-max_marker_len:]
            offset += chunk_size
        return tuple(dict.fromkeys(hits))

    @staticmethod
    def _readable_regions(handle: int) -> tuple[tuple[int, int], ...]:
        kernel32 = ctypes.windll.kernel32
        mbi = MEMORY_BASIC_INFORMATION()
        mbi_size = ctypes.sizeof(MEMORY_BASIC_INFORMATION)
        regions: list[tuple[int, int]] = []
        addr = 0
        while kernel32.VirtualQueryEx(handle, ctypes.c_void_p(addr), ctypes.byref(mbi), mbi_size):
            base = int(mbi.BaseAddress or 0)
            size = int(mbi.RegionSize)
            if (
                size > 0
                and mbi.State == MEM_COMMIT
                and not (mbi.Protect & PAGE_GUARD)
                and not (mbi.Protect & PAGE_NOACCESS)
                and bool(mbi.Protect & READABLE_PROTECT_MASK)
            ):
                regions.append((base, size))
            next_addr = base + size
            if next_addr <= addr:
                break
            addr = next_addr
        return tuple(regions)

    @staticmethod
    def _read_memory(handle: int, addr: int, size: int) -> bytes | None:
        if size <= 0:
            return None
        buffer = ctypes.create_string_buffer(size)
        nread = ctypes.c_size_t()
        ok = ctypes.windll.kernel32.ReadProcessMemory(
            handle,
            ctypes.c_void_p(addr),
            buffer,
            size,
            ctypes.byref(nread),
        )
        if not ok or nread.value <= 0:
            return None
        return buffer.raw[: nread.value]

    def _load_candidates(self) -> bool:
        profile = self._latest_profile()
        if profile is None:
            self._candidates = ()
            self._profile_path = None
            self._profile_mtime = 0.0
            return False
        mtime = profile.stat().st_mtime
        if self._profile_path == profile and self._profile_mtime == mtime:
            return bool(self._candidates)
        try:
            data = json.loads(profile.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            self._candidates = ()
            return False
        candidates: list[MemoryStatusCandidate] = []
        for field, items in (data.get("fields") or {}).items():
            if field not in {"food", "water", "health"} or not isinstance(items, list):
                continue
            for item in items:
                candidate = self._candidate_from_json(field, item)
                if candidate is not None:
                    candidates.append(candidate)
        self._profile_path = profile
        self._profile_mtime = mtime
        self._candidates = tuple(candidates)
        return bool(self._candidates)

    def _latest_profile(self) -> Path | None:
        profiles = sorted(self.report_dir.glob(MEMORY_PROFILE_GLOB), key=lambda path: path.stat().st_mtime, reverse=True)
        return profiles[0] if profiles else None

    def _candidate_from_json(self, field: str, item: Any) -> MemoryStatusCandidate | None:
        if not isinstance(item, dict):
            return None
        try:
            raw_addr = item["addr"]
            addr = int(raw_addr, 16) if isinstance(raw_addr, str) else int(raw_addr)
            return MemoryStatusCandidate(
                field=field,
                process_name=str(item.get("process_name") or item.get("process") or self.process_name),
                addr=addr,
                value_type=str(item.get("type") or item.get("value_type") or "u8").lower(),
                scale=float(item.get("scale", 1.0)),
                offset=float(item.get("offset", 0.0)),
                min_value=float(item.get("min", 0.0)),
                max_value=float(item.get("max", 100.0)),
            )
        except (KeyError, TypeError, ValueError):
            return None

    def _read_candidate(self, candidate: MemoryStatusCandidate) -> float | None:
        process = self._get_process(candidate.process_name)
        if process is None:
            return None
        handle = self._handle_for_process(process)
        if not handle:
            return None
        fmt = self._struct_format(candidate.value_type)
        if fmt is None:
            return None
        size = struct.calcsize(fmt)
        buffer = ctypes.create_string_buffer(size)
        nread = ctypes.c_size_t()
        ok = ctypes.windll.kernel32.ReadProcessMemory(
            handle,
            ctypes.c_void_p(candidate.addr),
            buffer,
            size,
            ctypes.byref(nread),
        )
        if not ok or nread.value != size:
            return None
        return float(struct.unpack(fmt, buffer.raw)[0])

    def _handle_for_process(self, process: psutil.Process) -> int | None:
        handle = self._handles.get(process.pid)
        if handle:
            return handle
        handle = ctypes.windll.kernel32.OpenProcess(PROCESS_ALL_READ, False, process.pid)
        if not handle:
            return None
        self._handles[process.pid] = handle
        return handle

    @staticmethod
    def _get_process(process_name: str) -> psutil.Process | None:
        wanted = process_name.lower()
        for process in psutil.process_iter(["name"]):
            try:
                if (process.info.get("name") or "").lower() == wanted:
                    return process
            except (psutil.AccessDenied, psutil.NoSuchProcess):
                continue
        return None

    @staticmethod
    def _processes_by_name(process_name: str) -> tuple[psutil.Process, ...]:
        wanted = process_name.lower()
        processes: list[psutil.Process] = []
        for process in psutil.process_iter(["name", "memory_info"]):
            try:
                if (process.info.get("name") or "").lower() == wanted:
                    processes.append(process)
            except (psutil.AccessDenied, psutil.NoSuchProcess):
                continue
        processes.sort(
            key=lambda item: getattr(item.info.get("memory_info"), "rss", 0) if hasattr(item, "info") else 0,
            reverse=True,
        )
        return tuple(processes)

    @staticmethod
    def _struct_format(value_type: str) -> str | None:
        return {
            "u8": "B",
            "i8": "b",
            "u16": "<H",
            "i16": "<h",
            "u32": "<I",
            "i32": "<i",
            "f32": "<f",
            "f64": "<d",
        }.get(value_type)

    @staticmethod
    def _vote(values: list[int]) -> int | None:
        if not values:
            return None
        try:
            return int(statistics.mode(values))
        except statistics.StatisticsError:
            return int(round(statistics.median(values)))
