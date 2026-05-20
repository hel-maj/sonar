from __future__ import annotations

import html
import re
import threading
import time
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path

from sonar.fishing.fish_names import fish_display_name, fish_id_from_display
from sonar.fishing.tackle_detection import TackleItemCount


DEFAULT_PRICE_NOTE_PATH = Path(
    r"D:\Documents\Obsidian Storages\personal\Моя записная\majestic\Цены предметов с проф\⭐ Рыбак по уровням.md"
)


@dataclass(frozen=True)
class FishPrice:
    per_item_min: float
    per_item_max: float
    per_1000_min: float
    per_1000_max: float


EMBEDDED_FISH_PRICES: dict[str, FishPrice] = {
    "albula": FishPrice(0.65, 0.73, 650.0, 730.0),
    "ancient_gyneria": FishPrice(2.64, 2.69, 2640.0, 2690.0),
    "barracuda": FishPrice(0.64, 0.69, 640.0, 690.0),
    "golavl": FishPrice(0.65, 0.70, 650.0, 700.0),
    "korichnevy_som": FishPrice(0.96, 1.03, 960.0, 1030.0),
    "krasny_gorbyl": FishPrice(0.61, 0.64, 610.0, 640.0),
    "marlin": FishPrice(0.67, 0.73, 670.0, 730.0),
    "polosaty_lavrak": FishPrice(0.67, 0.74, 670.0, 740.0),
    "pribrezhny_bass": FishPrice(0.62, 0.68, 620.0, 680.0),
    "roach_plotva": FishPrice(1.16, 1.25, 1160.0, 1250.0),
    "roach_vobla": FishPrice(0.81, 0.88, 810.0, 880.0),
    "rudd_krasnoperka": FishPrice(1.26, 1.35, 1260.0, 1350.0),
    "ruster": FishPrice(1.05, 1.12, 1050.0, 1120.0),
    "serebryany_karas": FishPrice(1.01, 1.09, 1010.0, 1090.0),
    "seriola": FishPrice(1.07, 1.10, 1070.0, 1100.0),
    "sterlet": FishPrice(0.84, 0.91, 840.0, 910.0),
    "sudak_obyknovennyy": FishPrice(0.67, 0.73, 670.0, 730.0),
    "tarpon": FishPrice(0.75, 0.78, 750.0, 780.0),
    "toksichny_okun": FishPrice(1.92, 2.00, 1920.0, 2000.0),
    "zhereh": FishPrice(0.69, 0.74, 690.0, 740.0),
}


@dataclass
class FishStat:
    fish_id: str
    name: str
    caught_count: int = 0
    caught_kg: float = 0.0
    released_count: int = 0
    released_kg: float = 0.0

    @property
    def kept_kg(self) -> float:
        return max(0.0, self.caught_kg - self.released_kg)


@dataclass
class SessionTotals:
    duration_seconds: float
    caught_count: int
    caught_kg: float
    released_count: int
    released_kg: float
    earned_min: float
    earned_max: float

    @property
    def kept_kg(self) -> float:
        return max(0.0, self.caught_kg - self.released_kg)

    @property
    def earned(self) -> float:
        return self.earned_max

    @property
    def earned_per_hour_min(self) -> float:
        if self.duration_seconds <= 0:
            return 0.0
        return self.earned_min / (self.duration_seconds / 3600.0)

    @property
    def earned_per_hour_max(self) -> float:
        if self.duration_seconds <= 0:
            return 0.0
        return self.earned_max / (self.duration_seconds / 3600.0)


@dataclass(frozen=True)
class FishStatsRow:
    stat: FishStat
    base_price: FishPrice | None
    custom_price: float | None
    earned_min: float
    earned_max: float


class FishingSessionStats:
    def __init__(
        self,
        default_prices: dict[str, FishPrice | float] | None = None,
        custom_prices: dict[str, float] | None = None,
    ) -> None:
        self._elapsed_seconds = 0.0
        self._running_started_at: float | None = None
        self.default_prices = _coerce_price_catalog(default_prices or EMBEDDED_FISH_PRICES)
        self.custom_prices = _clean_custom_prices(custom_prices or {})
        self._fish: dict[str, FishStat] = {}
        self._tackle_items: tuple[TackleItemCount, ...] = ()
        self._tackle_image_bytes: bytes | None = None
        self._tackle_scanned_at: datetime | None = None
        self._lock = threading.RLock()

    def reset(self) -> None:
        with self._lock:
            self._elapsed_seconds = 0.0
            if self._running_started_at is not None:
                self._running_started_at = time.time()
            self._fish.clear()
            self.clear_tackle_scan()

    def start_timer(self) -> None:
        with self._lock:
            if self._running_started_at is None:
                self._running_started_at = time.time()

    def stop_timer(self) -> None:
        with self._lock:
            if self._running_started_at is not None:
                self._elapsed_seconds += time.time() - self._running_started_at
                self._running_started_at = None

    def set_custom_prices(self, prices: dict[str, float]) -> None:
        with self._lock:
            self.custom_prices = _clean_custom_prices(prices)

    def set_custom_price(self, fish_id: str, price: float | None) -> None:
        with self._lock:
            if price is None or price <= 0:
                self.custom_prices.pop(fish_id, None)
            else:
                self.custom_prices[fish_id] = float(price)

    def record_catch(
        self,
        fish_id: str | None,
        fish_name: str | None,
        weight_kg: float | None,
        *,
        kept: bool,
        released: bool | None = None,
    ) -> None:
        key = fish_id or "unknown"
        name = fish_name or (fish_display_name(fish_id) if fish_id else "unknown")
        weight = max(0.0, float(weight_kg or 0.0))
        released = (not kept) if released is None else released
        with self._lock:
            stat = self._fish.setdefault(key, FishStat(fish_id=key, name=name))
            stat.name = name
            stat.caught_count += 1
            stat.caught_kg += weight
            if released:
                stat.released_count += 1
                stat.released_kg += weight

    def set_tackle_scan(
        self,
        items: tuple[TackleItemCount, ...] | list[TackleItemCount],
        *,
        image_bytes: bytes | None = None,
        scanned_at: datetime | None = None,
    ) -> None:
        with self._lock:
            self._tackle_items = tuple(items)
            self._tackle_image_bytes = image_bytes
            self._tackle_scanned_at = scanned_at or datetime.now()

    def clear_tackle_scan(self) -> None:
        with self._lock:
            self._tackle_items = ()
            self._tackle_image_bytes = None
            self._tackle_scanned_at = None

    def tackle_items(self) -> tuple[TackleItemCount, ...]:
        with self._lock:
            return tuple(self._tackle_items)

    def tackle_image_bytes(self) -> bytes | None:
        with self._lock:
            return self._tackle_image_bytes

    def tackle_scanned_at(self) -> datetime | None:
        with self._lock:
            return self._tackle_scanned_at

    def has_tackle_scan(self) -> bool:
        with self._lock:
            return bool(self._tackle_items)

    def base_price_for(self, fish_id: str) -> FishPrice | None:
        with self._lock:
            return self.default_prices.get(fish_id)

    def effective_price_range_for(self, fish_id: str) -> tuple[float, float]:
        with self._lock:
            custom_price = self.custom_prices.get(fish_id)
            if custom_price is not None:
                return custom_price, custom_price
            base_price = self.default_prices.get(fish_id)
            if base_price is None:
                return 0.0, 0.0
            return base_price.per_1000_min, base_price.per_1000_max

    def rows(self) -> list[FishStatsRow]:
        with self._lock:
            rows: list[FishStatsRow] = []
            for stat in self._fish.values():
                price_min, price_max = self.effective_price_range_for(stat.fish_id)
                rows.append(
                    FishStatsRow(
                        stat=FishStat(**stat.__dict__),
                        base_price=self.default_prices.get(stat.fish_id),
                        custom_price=self.custom_prices.get(stat.fish_id),
                        earned_min=stat.kept_kg * price_min,
                        earned_max=stat.kept_kg * price_max,
                    )
                )
            return sorted(rows, key=lambda item: item.stat.name)

    def totals(self) -> SessionTotals:
        with self._lock:
            caught_count = sum(item.caught_count for item in self._fish.values())
            caught_kg = sum(item.caught_kg for item in self._fish.values())
            released_count = sum(item.released_count for item in self._fish.values())
            released_kg = sum(item.released_kg for item in self._fish.values())
            earned_min = 0.0
            earned_max = 0.0
            for item in self._fish.values():
                price_min, price_max = self.effective_price_range_for(item.fish_id)
                earned_min += item.kept_kg * price_min
                earned_max += item.kept_kg * price_max
            return SessionTotals(
                duration_seconds=self._duration_seconds_locked(),
                caught_count=caught_count,
                caught_kg=caught_kg,
                released_count=released_count,
                released_kg=released_kg,
                earned_min=earned_min,
                earned_max=earned_max,
            )

    def has_catches(self) -> bool:
        return self.totals().caught_count > 0

    def _duration_seconds_locked(self) -> float:
        if self._running_started_at is None:
            return self._elapsed_seconds
        return self._elapsed_seconds + time.time() - self._running_started_at


def parse_fish_prices_from_markdown(path: Path | None = None) -> dict[str, FishPrice]:
    if path is None:
        return dict(EMBEDDED_FISH_PRICES)
    if not path.exists():
        return dict(EMBEDDED_FISH_PRICES)
    try:
        text = path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        text = path.read_text(encoding="cp1251", errors="ignore")
    text = _repair_mojibake(text)
    prices: dict[str, FishPrice] = {}
    for raw_line in text.splitlines():
        if "||" not in raw_line:
            continue
        left, right = raw_line.split("||", 1)
        name = _extract_fish_name(left)
        fish_id = fish_id_from_display(name)
        if not fish_id:
            continue
        item_price_text = re.sub(r"<[^>]+>", " ", html.unescape(left))
        thousand_price_text = re.sub(r"<[^>]+>", " ", html.unescape(right))
        item_numbers = [float(value.replace(" ", "")) for value in re.findall(r"(\d+(?:\.\d+)?)\s*\$", item_price_text)]
        thousand_numbers = [float(value.replace(" ", "")) for value in re.findall(r"(\d[\d\s]*)\s*\$", thousand_price_text)]
        if len(item_numbers) < 2 or len(thousand_numbers) < 2:
            continue
        prices[fish_id] = FishPrice(
            per_item_min=item_numbers[0],
            per_item_max=item_numbers[1],
            per_1000_min=thousand_numbers[0],
            per_1000_max=thousand_numbers[1],
        )
    return prices or dict(EMBEDDED_FISH_PRICES)


def format_duration(seconds: float) -> str:
    total_minutes = max(0, int(seconds // 60))
    hours, minutes = divmod(total_minutes, 60)
    if hours:
        return f"{hours} ч {minutes} мин"
    return f"{minutes} мин"


def format_weight(value: float) -> str:
    if abs(value - round(value)) < 0.05:
        return f"{value:.0f} кг"
    return f"{value:.1f} кг"


def format_money(value: float) -> str:
    return f"{round(value):,}".replace(",", " ") + " $"


def format_money_range(min_value: float, max_value: float) -> str:
    if abs(min_value - max_value) < 0.5:
        return format_money(max_value)
    return f"от {format_money(min_value)} до {format_money(max_value)}"


def format_catch_summary(count: int, weight_kg: float) -> str:
    return f"{count} шт · {format_weight(weight_kg)}"


def format_price_range(min_value: float, max_value: float, suffix: str = "") -> str:
    left = _format_price_value(min_value)
    right = _format_price_value(max_value)
    value = left if left == right else f"{left}-{right}"
    return f"{value}{suffix}"


def format_base_price(price: FishPrice | None) -> str:
    if price is None:
        return ""
    item = format_price_range(price.per_item_min, price.per_item_max, " $/шт")
    thousand = format_price_range(price.per_1000_min, price.per_1000_max, " $/1000")
    return f"{item} · {thousand}"


def _extract_fish_name(text: str) -> str:
    cleaned = re.sub(r"<[^>]+>", " ", html.unescape(text))
    cleaned = re.sub(r"^\s*\d+\s*[).]?\s*", "", cleaned)
    cleaned = re.split(r"\s+[\u2013\u2014-]\s+", cleaned, 1)[0]
    return " ".join(cleaned.split())


def _repair_mojibake(text: str) -> str:
    if "Р " not in text and "РЎ" not in text:
        return text
    try:
        repaired = text.encode("cp1251").decode("utf-8")
    except UnicodeError:
        return text
    return repaired if repaired.count("пїЅ") <= text.count("пїЅ") else text


def _coerce_price_catalog(prices: dict[str, FishPrice | float]) -> dict[str, FishPrice]:
    catalog: dict[str, FishPrice] = {}
    for fish_id, price in prices.items():
        if isinstance(price, FishPrice):
            catalog[str(fish_id)] = price
        else:
            value = float(price)
            catalog[str(fish_id)] = FishPrice(value / 1000.0, value / 1000.0, value, value)
    return catalog


def _clean_custom_prices(prices: dict[str, float]) -> dict[str, float]:
    clean: dict[str, float] = {}
    for fish_id, value in prices.items():
        try:
            price = float(value)
        except (TypeError, ValueError):
            continue
        if price > 0:
            clean[str(fish_id)] = price
    return clean


def _format_price_value(value: float) -> str:
    if abs(value - round(value)) < 0.005:
        return str(int(round(value)))
    return f"{value:.2f}".rstrip("0").rstrip(".")
