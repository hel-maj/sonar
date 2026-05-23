from __future__ import annotations

import re
from dataclasses import dataclass


@dataclass(frozen=True, slots=True)
class CatchSizeType:
    key: str
    label: str
    markers: tuple[str, ...]


CATCH_SIZE_TYPES: tuple[CatchSizeType, ...] = (
    CatchSizeType("modest", "Скромный улов", ("скром",)),
    CatchSizeType("good", "Хороший улов", ("хорош",)),
    CatchSizeType("record", "Рекордный улов", ("рекорд",)),
    CatchSizeType("trophy", "Трофейный улов", ("троф",)),
)

CATCH_SIZE_BY_LABEL: dict[str, CatchSizeType] = {item.label: item for item in CATCH_SIZE_TYPES}
CATCH_SIZE_LABELS: tuple[str, ...] = tuple(item.label for item in CATCH_SIZE_TYPES)
CATCH_SIZE_COLORS_BY_LABEL: dict[str, str] = {
    "Скромный улов": "#242424",
    "Хороший улов": "#275277",
    "Рекордный улов": "#8C1D2C",
    "Трофейный улов": "#1D8667",
}
CATCH_SIZE_COLORS_BY_KEY: dict[str, str] = {item.key: CATCH_SIZE_COLORS_BY_LABEL[item.label] for item in CATCH_SIZE_TYPES}
UNKNOWN_CATCH_SIZE_KEY = "unknown"
UNKNOWN_CATCH_SIZE_LABEL = "Не распознано"


def normalize_catch_size(text: str | None) -> str | None:
    if not text:
        return None
    normalized = re.sub(r"[^0-9a-zа-яё]+", "", text.lower())
    for item in CATCH_SIZE_TYPES:
        if any(marker in normalized for marker in item.markers):
            return item.label
    return " ".join(text.split())


def catch_size_key(label: str | None) -> str:
    if not label:
        return UNKNOWN_CATCH_SIZE_KEY
    known = CATCH_SIZE_BY_LABEL.get(label)
    if known is not None:
        return known.key
    return UNKNOWN_CATCH_SIZE_KEY


def catch_size_label(key: str) -> str:
    for item in CATCH_SIZE_TYPES:
        if item.key == key:
            return item.label
    return UNKNOWN_CATCH_SIZE_LABEL
