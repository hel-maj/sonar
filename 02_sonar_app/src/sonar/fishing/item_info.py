from __future__ import annotations

import re
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import cv2
import numpy as np
from PIL import Image

from sonar.ocr import configure_tesseract, tessdata_config
from sonar.paths import RESOURCE_DIR
from sonar.vision.geometry import Rect


MIN_TOOLTIP_WIDTH = 70
MIN_TOOLTIP_HEIGHT = 35
MAX_TOOLTIP_WIDTH_RATIO = 0.55
MAX_TOOLTIP_HEIGHT_RATIO = 0.65
DARK_RGB_THRESHOLD = 25
MIN_DARK_RATIO = 0.45
MIN_FILL_RATIO = 0.65
TRIM_GRAY_THRESHOLD = 35
TRIM_EDGE_DARK_RATIO = 0.65
TRIM_PASSES = 2
MERGED_TOP_SCAN_HEIGHT = 32
TITLE_REGION_HEIGHT = 58
WEIGHT_REGION_HEIGHT = 44
OCR_PADDING_LEFT = 4
OCR_PADDING_TOP = 2
OCR_PADDING_RIGHT = 4
OCR_PADDING_BOTTOM = 2
BASE_TOOLTIP_WIDTH = 312
OCR_WORD_CONFIDENCE = 18
OCR_RECT_MIN_SCORE = 6.0


@dataclass(frozen=True, slots=True)
class ItemEffect:
    name: str
    duration: str = ""
    description: str = ""
    parameter_modifications: tuple[str, ...] = ()


@dataclass(frozen=True, slots=True)
class ParsedItemInfo:
    title: str = ""
    item_name: str = ""
    weight: str = ""
    description: str = ""
    satiety_change: str = ""
    thirst_change: str = ""
    condition_percent: str = ""
    poison_chance: str = ""
    effects: tuple[ItemEffect, ...] = ()
    standalone_parameter_modifications: tuple[str, ...] = ()
    strength: str = ""
    gender: str = ""
    text: str = ""

    @property
    def effect_names(self) -> tuple[str, ...]:
        return tuple(effect.name for effect in self.effects)

    @property
    def effect_durations(self) -> tuple[str, ...]:
        return tuple(effect.duration for effect in self.effects if effect.duration)

    @property
    def effect_descriptions(self) -> tuple[str, ...]:
        return tuple(effect.description for effect in self.effects if effect.description)

    @property
    def parameter_modifications(self) -> tuple[str, ...]:
        return (*self.standalone_parameter_modifications, *(value for effect in self.effects for value in effect.parameter_modifications))


@dataclass(frozen=True, slots=True)
class ItemInfo:
    rect: Rect
    title: str = ""
    weight: str = ""
    text: str = ""
    item_name: str = ""
    description: str = ""
    satiety_change: str = ""
    thirst_change: str = ""
    condition_percent: str = ""
    poison_chance: str = ""
    effects: tuple[ItemEffect, ...] = ()
    standalone_parameter_modifications: tuple[str, ...] = ()
    strength: str = ""
    gender: str = ""

    @property
    def effect_names(self) -> tuple[str, ...]:
        return tuple(effect.name for effect in self.effects)

    @property
    def effect_durations(self) -> tuple[str, ...]:
        return tuple(effect.duration for effect in self.effects if effect.duration)

    @property
    def effect_descriptions(self) -> tuple[str, ...]:
        return tuple(effect.description for effect in self.effects if effect.description)

    @property
    def parameter_modifications(self) -> tuple[str, ...]:
        return (*self.standalone_parameter_modifications, *(value for effect in self.effects for value in effect.parameter_modifications))


class ItemInfoParser:
    CATEGORY_TITLES = {
        "Легкое",
        "Среднее",
        "Тяжелое",
        "Обычное",
        "Редкое",
        "Эпическое",
        "Легендарное",
        "Маски",
        "Очки",
        "Головные уборы",
        "Аксессуары",
        "Низ",
        "Обувь",
        "Рюкзаки",
    }
    SECTION_LABELS = {
        "Эффекты": "effects",
        "Длительность эффектов": "effect_durations",
        "Описание эффектов": "effect_descriptions",
        "Модификация параметров": "parameter_modifications",
        "Шанс отравления": "poison_chance",
        "Состояние": "condition_percent",
        "Прочность": "strength",
    }

    @classmethod
    def parse(cls, text: str) -> ParsedItemInfo:
        lines = [cls._clean_line(line) for line in text.splitlines()]
        lines = [line for line in lines if line]
        if not lines:
            return ParsedItemInfo(text="")
        title = cls._normalize_category_title(ItemInfoDetector._clean_title(lines[0]))
        labeled = cls._labeled_values(lines)
        item_name = cls._extract_item_name(title, lines)
        description = cls._extract_description(title, item_name, lines)
        names = cls._split_values(labeled.get("effects", ""))
        modifications = cls._split_values(labeled.get("parameter_modifications", ""))
        effects = cls._build_effects(
            names,
            cls._split_values(labeled.get("effect_durations", "")),
            cls._split_values(labeled.get("effect_descriptions", "")),
            modifications,
        )
        standalone_modifications = tuple(modifications) if not names else ()
        if not effects:
            heuristic_effects, heuristic_modifications = cls._extract_heuristic_effects(lines, title, item_name)
            if heuristic_effects or heuristic_modifications:
                effects = heuristic_effects
                standalone_modifications = tuple(heuristic_modifications) if not effects else ()
        weight = ItemInfoDetector._extract_weight(lines)
        satiety_change = cls._extract_change(lines, "сытост")
        thirst_change = cls._extract_change(lines, "жажд")
        condition_percent = cls._normalize_percent(labeled.get("condition_percent", ""))
        poison_chance = cls._normalize_poison_chance(labeled.get("poison_chance", ""))
        strength = labeled.get("strength", "")
        gender = cls._extract_gender(lines)
        return ParsedItemInfo(
            title=title,
            item_name=item_name,
            weight=weight,
            description=description,
            satiety_change=satiety_change,
            thirst_change=thirst_change,
            condition_percent=condition_percent,
            poison_chance=poison_chance,
            effects=effects,
            standalone_parameter_modifications=standalone_modifications,
            strength=strength,
            gender=gender,
            text=cls._canonical_text(
                title=title,
                description=description,
                satiety_change=satiety_change,
                thirst_change=thirst_change,
                poison_chance=poison_chance,
                effects=effects,
                standalone_modifications=standalone_modifications,
                condition_percent=condition_percent,
                strength=strength,
                gender=gender,
                weight=weight,
                fallback_lines=lines,
            ),
        )

    @staticmethod
    def _clean_line(line: str) -> str:
        line = line.replace("`", " ").strip()
        return re.sub(r"\s+", " ", line)

    @classmethod
    def _labeled_values(cls, lines: list[str]) -> dict[str, str]:
        values: dict[str, str] = {}
        for line in lines:
            for label, key in cls.SECTION_LABELS.items():
                match = re.search(rf"(?:^|\s){re.escape(label)}(?![A-Za-zА-Яа-яЁёβΒ])\s*:?\s*(.+)$", line, flags=re.IGNORECASE)
                if match:
                    value = cls._clean_value(match.group(1))
                    if value and cls._value_score(value) > cls._value_score(values.get(key, "")):
                        values[key] = value
                    break
        return values

    @staticmethod
    def _value_score(value: str) -> tuple[int, int]:
        letters = len(re.findall(r"[A-Za-zА-Яа-яЁёβΒ]", value))
        digits = len(re.findall(r"\d", value))
        return letters + digits, len(value.strip())

    @staticmethod
    def _clean_value(value: str) -> str:
        value = value.strip()
        value = re.sub(r"^[^0-9A-Za-zА-Яа-яЁёβΒ+\-~]+|[^0-9A-Za-zА-Яа-яЁёβΒ.%+\-~]+$", "", value)
        return re.sub(r"\s+", " ", value)

    @staticmethod
    def _split_values(value: str) -> list[str]:
        if not value:
            return []
        return [part.strip() for part in value.split("|") if part.strip()]

    @classmethod
    def _extract_item_name(cls, title: str, lines: list[str]) -> str:
        if cls._is_category_title(title):
            name_lines: list[str] = []
            for line in lines[1:]:
                raw_line = cls._normalize_ocr_text(cls._clean_line(line))
                clean_line = cls._normalize_category_title(ItemInfoDetector._clean_title(raw_line)) if not name_lines else raw_line
                if not clean_line or cls._is_metadata_line(clean_line) or cls._is_noise_line(clean_line):
                    if name_lines:
                        break
                    continue
                if cls._parse_effect_header(clean_line) is not None:
                    if name_lines:
                        break
                    continue
                if name_lines and not cls._looks_like_name_continuation(clean_line):
                    break
                name_lines.append(clean_line)
            if name_lines:
                return cls._normalize_ocr_text(" ".join(name_lines))
        return title

    @staticmethod
    def _looks_like_name_continuation(line: str) -> bool:
        if re.search(r"[.:;!?\d]", line):
            return False
        words = line.split()
        if not words or len(words) > 4:
            return False
        return bool(re.match(r'^[а-яёa-z("\']', words[0]))

    @classmethod
    def _is_category_title(cls, value: str) -> bool:
        value_casefold = value.casefold()
        return any(title.casefold() == value_casefold for title in cls.CATEGORY_TITLES)

    @classmethod
    def _normalize_category_title(cls, value: str) -> str:
        value = value.strip()
        value_casefold = value.casefold()
        for title in cls.CATEGORY_TITLES:
            if title.casefold() == value_casefold:
                return title
        return value

    @classmethod
    def _extract_description(cls, title: str, item_name: str, lines: list[str]) -> str:
        values: list[str] = []
        start_index = 1
        if cls._is_category_title(title):
            return item_name
        for line in lines[start_index:]:
            if cls._is_metadata_line(line):
                break
            if cls._same_clean_title(line, title) or cls._same_clean_title(line, item_name) or cls._looks_like_title_duplicate(line, title) or cls._looks_like_title_duplicate(line, item_name) or cls._is_noise_line(line) or ItemInfoDetector._suspicious_title(line):
                continue
            values.append(cls._normalize_ocr_text(line))
        description = " ".join(values).strip()
        return re.sub(r",$", ".", description)

    @staticmethod
    def _looks_like_title_duplicate(line: str, title: str) -> bool:
        line_clean = ItemInfoDetector._clean_title(line)
        title_clean = ItemInfoDetector._clean_title(title)
        if not line_clean or not title_clean or any(mark in line_clean for mark in ",.;:!?"):
            return False
        line_words = re.findall(r"[A-Za-zА-Яа-яЁёβΒ0-9-]+", line_clean.casefold())
        title_words = re.findall(r"[A-Za-zА-Яа-яЁёβΒ0-9-]+", title_clean.casefold())
        if len(line_words) > len(title_words) + 1:
            return False
        if not line_words or not title_words:
            return False
        overlap = len(set(line_words) & set(title_words))
        return overlap >= max(1, min(len(title_words), 2))

    @staticmethod
    def _same_clean_title(left: str, right: str) -> bool:
        left_clean = ItemInfoDetector._clean_title(left).casefold()
        right_clean = ItemInfoDetector._clean_title(right).casefold()
        return bool(left_clean and right_clean and left_clean == right_clean)

    @staticmethod
    def _looks_like_weight_line(line: str) -> bool:
        lowered = line.lower()
        lowered = re.sub(r"(?<![A-Za-zА-Яа-яЁёβΒ])[oо](?=[.,:]?\d)", "0", lowered)
        return bool(re.fullmatch(r"[^0-9A-Za-zА-Яа-яЁёβΒ]*(?:\d+(?:[.,:]\d+)?)\s*(?:кг|kg|кз|кс|ке|кё|кв|кб|ke|xs|me|«g|@|&|№|®|м|m)[^A-Za-zА-Яа-яЁёβΒ]*", lowered))

    @classmethod
    def _is_metadata_line(cls, line: str) -> bool:
        lowered = line.lower()
        if cls._looks_like_weight_line(line):
            return True
        if re.match(r"^[^A-Za-zА-Яа-яЁёβΒ]*\d+(?:[.,:]\d+)?\s*(?:кг|kg|кз|кс|ке|кё|кв|кб|ke|xs|me|«g|@|&|№)", lowered):
            return True
        if re.match(r"^[+\-~]?\s*\d+\s*к\s*(?:с[ыьiі]тост|ж[аеи]жд)", lowered):
            return True
        if re.fullmatch(r"[^0-9A-Za-zА-Яа-яЁёβΒ]*\d+(?:[.,:]\d+)?\s*[кk8][^A-Za-zА-Яа-яЁёβΒ]*", lowered):
            return True
        if re.search(r"(?:^|\s)к\s*(?:с[ыьiі]тост|ж[аеи]жд)", lowered):
            return True
        if re.search(r"для\s+(?:мужчин|женщин)\b", lowered):
            return True
        if re.search(r"\b(?:состояние|шанс\s+отравления)\b", lowered):
            return True
        if any(lowered.startswith(label.lower()) for label in cls.SECTION_LABELS):
            return True
        return False

    @staticmethod
    def _extract_change(lines: list[str], stem: str) -> str:
        label_pattern = ItemInfoParser._change_label_pattern(stem)
        pattern = rf"([+\-~]\s*\d+)\s+к\s*{label_pattern}"
        matches: list[str] = []
        for line in lines:
            normalized_line = line.replace("O", "0").replace("О", "0").replace("S", "5").replace("s", "5")
            match = re.search(pattern, normalized_line, flags=re.IGNORECASE)
            if match:
                matches.append(match.group(1).replace(" ", "").replace("~", "+"))
        if not matches:
            return ""
        for value in matches:
            if value.startswith("+") and f"-{value[1:]}" in matches:
                return value
        positives = [value for value in matches if value.startswith("+")]
        if positives:
            return max(positives, key=lambda value: int(re.sub(r"\D", "", value) or "0"))
        return matches[0]

    @staticmethod
    def _change_label_pattern(stem: str) -> str:
        if stem.startswith("жажд"):
            return r"ж[аеи]жд[а-яё]*"
        if stem.startswith("сытост"):
            return r"с[ыьiі]тост[а-яё]*"
        return re.escape(stem)

    @staticmethod
    def _normalize_percent(value: str) -> str:
        match = re.search(r"(\d+)", value)
        return match.group(1) if match else ""

    @staticmethod
    def _normalize_poison_chance(value: str) -> str:
        lowered = value.lower()
        if "низ" in lowered:
            return "Низкий"
        if "сред" in lowered:
            return "Средний"
        if "выс" in lowered:
            return "Высокий"
        return value if len(value) > 2 else ""

    @staticmethod
    def _normalize_ocr_text(value: str) -> str:
        value = value.replace("Иэ", "Из").replace("иэ", "из")
        value = value.replace("отровления", "отравления").replace("Отровления", "Отравления")
        value = re.sub(r"\b(?:kg|кз|кс|ке|кё|кв|кб|ke|xs|me)\b", "кг", value, flags=re.IGNORECASE)
        value = re.sub(r"\$\s*-\s*(\d)", r"S-\1", value)
        value = re.sub(r",\s+([A-ZА-ЯЁ])", r". \1", value)
        value = re.sub(r"\s+([.,;:!?])", r"\1", value)
        return re.sub(r"\s+", " ", value).strip()

    @staticmethod
    def _is_noise_line(line: str) -> bool:
        cleaned = line.strip()
        if not cleaned:
            return True
        letters = re.sub(r"[^A-Za-zА-Яа-яЁёβΒ]", "", cleaned)
        digits = re.sub(r"\D", "", cleaned)
        if not letters:
            return True
        if digits:
            return False
        if len(cleaned) <= 8 and len(letters) <= 3 and re.search(r"[^A-Za-zА-Яа-яЁёβΒ\s]", cleaned):
            return True
        return False

    @staticmethod
    def _extract_gender(lines: list[str]) -> str:
        for line in lines:
            match = re.search(r"для\s+(мужчин|женщин)\b", line, flags=re.IGNORECASE)
            if match:
                return f"Для {match.group(1).lower()}"
        return ""

    @classmethod
    def _extract_heuristic_effects(
        cls,
        lines: list[str],
        title: str,
        item_name: str,
    ) -> tuple[tuple[ItemEffect, ...], tuple[str, ...]]:
        effects_by_name: dict[str, ItemEffect] = {}
        modifications: list[str] = []
        current_name = ""
        current_duration = ""
        current_description: list[str] = []
        effect_zone = False
        in_modifications = False
        recent_lines: list[str] = []
        blocked_titles = {ItemInfoDetector._clean_title(title).casefold(), ItemInfoDetector._clean_title(item_name).casefold()}

        def flush_effect() -> None:
            nonlocal current_name, current_duration, current_description
            if not current_name:
                return
            description = cls._normalize_ocr_text(" ".join(current_description))
            existing = effects_by_name.get(current_name)
            effect = ItemEffect(current_name, current_duration, description)
            if existing is None or cls._effect_score(effect) > cls._effect_score(existing):
                effects_by_name[current_name] = effect
            current_name = ""
            current_duration = ""
            current_description = []

        for line in lines[1:]:
            clean_line = cls._normalize_ocr_text(cls._clean_line(line))
            if not clean_line or ItemInfoDetector._clean_title(clean_line).casefold() in blocked_titles or cls._is_noise_line(clean_line):
                continue
            if re.search(r"модификация\s+параметров", clean_line, flags=re.IGNORECASE):
                if not current_name:
                    current_name = cls._infer_effect_name_before_modification(recent_lines)
                flush_effect()
                effect_zone = True
                in_modifications = True
                recent_lines.append(clean_line)
                continue
            modification = cls._parse_parameter_modification(clean_line)
            if in_modifications and modification:
                if modification not in modifications:
                    modifications.append(modification)
                continue
            if cls._is_change_line(clean_line) or re.search(r"шанс\s+отравления", clean_line, flags=re.IGNORECASE):
                effect_zone = True
                continue
            if cls._is_metadata_line(clean_line):
                flush_effect()
                if cls._looks_like_weight_line(clean_line):
                    break
                recent_lines.append(clean_line)
                continue
            header = cls._parse_effect_header(clean_line)
            if header is not None:
                header_name, header_duration = header
                if ItemInfoDetector._clean_title(header_name).casefold() in blocked_titles:
                    continue
                flush_effect()
                current_name, current_duration = header_name, header_duration
                in_modifications = False
                recent_lines.append(clean_line)
                continue
            if current_name:
                if not current_duration and not current_description and cls._looks_like_effect_name_continuation(clean_line):
                    current_name = f"{current_name} {clean_line}"
                    continue
                current_description.append(clean_line)
            recent_lines.append(clean_line)

        flush_effect()
        effects = cls._dedupe_heuristic_effects(list(effects_by_name.values()))
        if effects and modifications:
            first = effects[0]
            effects[0] = ItemEffect(
                first.name,
                first.duration,
                first.description,
                tuple(modifications),
            )
            return tuple(effects), ()
        return tuple(effects), tuple(modifications)

    @staticmethod
    def _effect_score(effect: ItemEffect) -> tuple[int, int, int]:
        return (
            int(bool(effect.description)),
            len(re.findall(r"[A-Za-zА-Яа-яЁёβΒ]", effect.description)),
            int(bool(effect.duration)),
        )

    @staticmethod
    def _infer_effect_name_before_modification(lines: list[str]) -> str:
        candidates = [line for line in lines[-4:] if line and not ItemInfoParser._is_metadata_line(line) and not ItemInfoParser._is_noise_line(line)]
        if not candidates:
            return ""
        last = candidates[-1]
        if ItemInfoParser._looks_like_effect_name_continuation(last) and len(candidates) >= 2:
            previous = candidates[-2]
            if re.match(r"^[A-ZА-ЯЁ]", previous) and not re.search(r"[.:;!?\d]", previous):
                return f"{previous} {last}"
        if re.match(r"^[A-ZА-ЯЁ]", last) and not re.search(r"[.:;!?\d]", last):
            return last
        return ""

    @staticmethod
    def _looks_like_effect_name_continuation(line: str) -> bool:
        if re.search(r"[.:;!?]", line):
            return False
        if re.search(r"\d|[+\-~]", line):
            return False
        words = line.split()
        if not words or len(words) > 4:
            return False
        return bool(re.match(r"^[а-яёa-z]", words[0]))

    @staticmethod
    def _dedupe_heuristic_effects(effects: list[ItemEffect]) -> list[ItemEffect]:
        result: list[ItemEffect] = []
        for effect in effects:
            duplicate_index = None
            for index, existing in enumerate(result):
                same_duration = bool(effect.duration and effect.duration == existing.duration)
                same_description = bool(effect.description and existing.description and ItemInfoParser._similar_text(effect.description, existing.description))
                same_name = ItemInfoParser._similar_effect_name(effect.name, existing.name)
                if same_name or same_duration and (same_description or not effect.parameter_modifications and not existing.parameter_modifications):
                    duplicate_index = index
                    break
            if duplicate_index is None:
                result.append(effect)
                continue
            if ItemInfoParser._effect_name_score(effect.name) > ItemInfoParser._effect_name_score(result[duplicate_index].name):
                result[duplicate_index] = effect
        return result

    @staticmethod
    def _similar_effect_name(left: str, right: str) -> bool:
        left_norm = re.sub(r"\s+", " ", left.casefold()).strip()
        right_norm = re.sub(r"\s+", " ", right.casefold()).strip()
        if not left_norm or not right_norm:
            return False
        return left_norm.startswith(right_norm) or right_norm.startswith(left_norm)

    @staticmethod
    def _similar_text(left: str, right: str) -> bool:
        left_words = set(re.findall(r"[A-Za-zА-Яа-яЁёβΒ]{3,}", left.casefold()))
        right_words = set(re.findall(r"[A-Za-zА-Яа-яЁёβΒ]{3,}", right.casefold()))
        if not left_words or not right_words:
            return False
        overlap = len(left_words & right_words)
        return overlap / max(1, min(len(left_words), len(right_words))) >= 0.5

    @staticmethod
    def _effect_name_score(name: str) -> tuple[int, int, int]:
        cyrillic = len(re.findall(r"[А-Яа-яЁё]", name))
        latin = len(re.findall(r"[A-Za-z]", name))
        letters = len(re.findall(r"[A-Za-zА-Яа-яЁёβΒ]", name))
        return cyrillic - latin, letters, -len(re.findall(r"[^A-Za-zА-Яа-яЁёβΒ\s-]", name))

    @staticmethod
    def _parse_parameter_modification(line: str) -> str:
        if ItemInfoParser._is_change_line(line):
            return ""
        line = re.sub(r"^[4AА]\s*(?=\d+%?\s+к)", "+", line)
        match = re.match(r"^([+\-~]\s*\d+%?\s+.+)$", line)
        if not match:
            return ""
        value = match.group(1).replace("~", "+")
        return re.sub(r"\s+", " ", value).strip()

    @staticmethod
    def _is_change_line(line: str) -> bool:
        return bool(re.match(r"^[^0-9+\-~]*[+\-~]?\s*\d+\s*к\s*(?:с[ыьiі]тост|ж[аеи]жд)", line, flags=re.IGNORECASE))

    @staticmethod
    def _parse_effect_header(line: str) -> tuple[str, str] | None:
        raw_line = line.strip()
        if not raw_line:
            return None
        has_icon_prefix = bool(re.match(r"^\s*[^A-Za-zА-Яа-яЁёβΒ0-9]+", raw_line))
        has_short_prefix = bool(re.match(r"^\s*[A-Za-zА-Яа-яЁёβΒ0-9]\s+[A-ZА-ЯЁ]", raw_line))
        if re.search(r"#\s*\d", raw_line):
            return None
        candidate = re.sub(r"^[^A-Za-zА-Яа-яЁёβΒ0-9]+", "", raw_line).strip()
        parts = candidate.split()
        if len(parts) > 1 and len(re.sub(r"[^A-Za-zА-Яа-яЁёβΒ]", "", parts[0])) <= 1 and re.match(r"^[A-ZА-ЯЁ]", parts[1]):
            candidate = " ".join(parts[1:])
            has_short_prefix = True
        duration = ""
        duration_match = re.search(r"(?:[©@®oО0]\s*)*(\d+)\s*([мmчh])\.?", candidate, flags=re.IGNORECASE)
        if duration_match:
            number = duration_match.group(1)
            unit = "ч" if duration_match.group(2).lower() in {"ч", "h"} else "м"
            duration = f"{number} {unit}."
            name_part = candidate[:duration_match.start()]
        else:
            fallback_duration = re.search(r"(?:[©@®oО0]\s*)*(\d+)4\.", candidate, flags=re.IGNORECASE)
            if fallback_duration:
                duration = f"{fallback_duration.group(1)} ч."
                name_part = candidate[:fallback_duration.start()]
            else:
                name_part = candidate
        if not duration and not (has_icon_prefix or has_short_prefix):
            return None
        name = re.sub(r"[©@®0]+", " ", name_part)
        name = re.sub(r"[^A-Za-zА-Яа-яЁёβΒ\-\s]", " ", name)
        name = re.sub(r"\s+", " ", name).strip(" -")
        if len(re.sub(r"[^A-Za-zА-Яа-яЁёβΒ]", "", name)) < 3:
            return None
        if duration and not re.match(r"^[A-ZА-ЯЁ]", name):
            return None
        if duration and len(re.findall(r"[А-Яа-яЁё]", name)) < len(re.findall(r"[A-Za-z]", name)):
            return None
        if re.search(r"(?:с[ыьiі]тост|ж[аеи]жд)", name, flags=re.IGNORECASE):
            return None
        if not duration and not re.match(r"^[A-ZА-ЯЁ]", name):
            return None
        if not duration and len(name.split()) > 3:
            return None
        return name, duration

    @staticmethod
    def _build_effects(names: list[str], durations: list[str], descriptions: list[str], modifications: list[str]) -> tuple[ItemEffect, ...]:
        if not names:
            return ()
        result: list[ItemEffect] = []
        for index, name in enumerate(names):
            if len(modifications) == len(names):
                effect_modifications = (modifications[index],) if modifications[index] else ()
            elif index == 0:
                effect_modifications = tuple(modifications)
            else:
                effect_modifications = ()
            result.append(
                ItemEffect(
                    name=name,
                    duration=durations[index] if index < len(durations) else "",
                    description=descriptions[index] if index < len(descriptions) else "",
                    parameter_modifications=effect_modifications,
                )
            )
        return tuple(result)

    @staticmethod
    def _canonical_text(
        *,
        title: str,
        description: str,
        satiety_change: str,
        thirst_change: str,
        poison_chance: str,
        effects: tuple[ItemEffect, ...],
        standalone_modifications: tuple[str, ...],
        condition_percent: str,
        strength: str,
        gender: str,
        weight: str,
        fallback_lines: list[str],
    ) -> str:
        lines: list[str] = []
        if title:
            lines.append(title)
        if description and description != title:
            lines.append(description)
        if satiety_change:
            lines.append(f"{satiety_change} к сытости")
        if thirst_change:
            lines.append(f"{thirst_change} к жажде")
        if poison_chance:
            lines.append(f"Шанс отравления: {poison_chance}")
        if effects:
            lines.append("Эффекты: " + " | ".join(effect.name for effect in effects))
            durations = [effect.duration for effect in effects if effect.duration]
            if durations:
                lines.append("Длительность эффектов: " + " | ".join(durations))
            descriptions = [effect.description for effect in effects if effect.description]
            if descriptions:
                lines.append("Описание эффектов: " + " | ".join(descriptions))
            modifications = [value for effect in effects for value in effect.parameter_modifications]
            if modifications:
                lines.append("Модификация параметров: " + " | ".join(modifications))
        elif standalone_modifications:
            lines.append("Модификация параметров: " + " | ".join(standalone_modifications))
        if strength:
            lines.append(f"Прочность: {strength}")
        if gender:
            lines.append(gender)
        if condition_percent:
            lines.append(f"Состояние: {condition_percent}%")
        if weight:
            lines.append(f"{weight} кг")
        if not lines:
            return "\n".join(fallback_lines)
        result: list[str] = []
        seen: set[str] = set()
        for line in lines:
            normalized = re.sub(r"\s+", " ", line.casefold()).strip()
            if not normalized or normalized in seen:
                continue
            seen.add(normalized)
            result.append(line)
        return "\n".join(result)


class ItemInfoDetector:
    def detect(self, frame: np.ndarray, *, read_text: bool = True) -> ItemInfo | None:
        rect = self.detect_rect(frame)
        if rect is None:
            return None
        if not read_text:
            return ItemInfo(rect=rect)
        title, weight, text = self.read_text(frame, rect)
        parsed = ItemInfoParser.parse(text)
        title = parsed.title or title
        weight = parsed.weight or weight
        return ItemInfo(
            rect=rect,
            title=title,
            weight=weight,
            text=parsed.text or text,
            item_name=parsed.item_name or title,
            description=parsed.description,
            satiety_change=parsed.satiety_change,
            thirst_change=parsed.thirst_change,
            condition_percent=parsed.condition_percent,
            poison_chance=parsed.poison_chance,
            effects=parsed.effects,
            standalone_parameter_modifications=parsed.standalone_parameter_modifications,
            strength=parsed.strength,
            gender=parsed.gender,
        )

    def detect_rect(self, frame: np.ndarray) -> Rect | None:
        if frame.size == 0:
            return None
        rect = self._detect_rect_by_contours(frame)
        if rect is not None and not self._should_try_ocr_rect(frame, rect):
            return rect
        ocr_rect = self._detect_rect_by_ocr(frame)
        if ocr_rect is not None:
            if rect is None:
                return ocr_rect
            return ocr_rect if self._ocr_rect_is_better(frame, rect, ocr_rect) else rect
        window_rect = self._detect_rect_by_dark_window(frame) if rect is None or self._should_try_ocr_rect(frame, rect) else None
        if window_rect is None:
            return rect
        if rect is None:
            return window_rect
        return self._best_detected_rect(frame, [rect, window_rect])

    def crop(self, frame: np.ndarray, item_info: ItemInfo | Rect) -> np.ndarray | None:
        rect = item_info if isinstance(item_info, Rect) else item_info.rect
        height, width = frame.shape[:2]
        clamped = rect.clamp(width, height)
        crop = frame[clamped.slice()]
        return None if crop.size == 0 else crop

    def read_text(self, frame: np.ndarray, rect: Rect) -> tuple[str, str, str]:
        try:
            import pytesseract
        except Exception:
            return "", "", ""
        self._configure_tesseract(pytesseract)
        rect = self._refine_rect_for_ocr(frame, rect)
        title_lines = self._ocr_lines(pytesseract, self._title_crop(frame, rect), region="title")
        weight_lines = self._ocr_lines(pytesseract, self._weight_crop(frame, rect), region="weight")
        text_lines = self._ocr_lines(pytesseract, self._text_crop(frame, rect), region="full")
        title_from_title = self._extract_title(title_lines)
        title_from_text = self._extract_title(text_lines)
        title = title_from_text if title_from_text and self._suspicious_title(title_from_title) else title_from_title or title_from_text
        weight = self._extract_weight(weight_lines) or self._extract_weight(text_lines)
        title_group = [title] if title else []
        merged_lines = self._merge_ocr_lines(title_group, text_lines, title_lines, weight_lines)
        return title, weight, "\n".join(merged_lines)

    @staticmethod
    def _suspicious_title(title: str) -> bool:
        if not title:
            return True
        letters = re.findall(r"[A-Za-zА-Яа-яЁёβΒ]", title)
        cyrillic = re.findall(r"[А-Яа-яЁё]", title)
        latin = re.findall(r"[A-Za-z]", title)
        if len(letters) <= 4 and len(latin) >= len(letters) - 1 and not cyrillic:
            return True
        if title.endswith(".") and latin and not cyrillic:
            return True
        if not cyrillic and " " in title and (re.search(r"[a-z]", title) or re.search(r"\d", title)):
            return True
        return False

    @staticmethod
    def _merge_ocr_lines(*groups: list[str]) -> list[str]:
        result: list[str] = []
        for group in groups:
            for line in group:
                if not line:
                    continue
                if result and result[-1] == line:
                    continue
                result.append(line)
        return result

    def _detect_rect_by_contours(self, frame: np.ndarray) -> Rect | None:
        height, width = frame.shape[:2]
        mask = self._dark_mask(frame)
        kernel_size = max(3, int(round(min(width, height) / 216)))
        if kernel_size % 2 == 0:
            kernel_size += 1
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (kernel_size, kernel_size))
        closed = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel, iterations=1)
        contours, _ = cv2.findContours(closed, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        candidates: list[tuple[Rect, float, float]] = []
        max_tooltip_width = int(width * MAX_TOOLTIP_WIDTH_RATIO)
        max_tooltip_height = int(height * MAX_TOOLTIP_HEIGHT_RATIO)
        min_area = max(2500, int(width * height * 0.0012))
        for contour in contours:
            x, y, w, h = cv2.boundingRect(contour)
            area = w * h
            if w < MIN_TOOLTIP_WIDTH or h < MIN_TOOLTIP_HEIGHT or w > max_tooltip_width or h > max_tooltip_height:
                continue
            if area < min_area:
                continue
            crop_mask = mask[y:y + h, x:x + w]
            dark_ratio = float(np.mean(crop_mask > 0))
            fill_ratio = float(cv2.contourArea(contour) / area)
            if dark_ratio < MIN_DARK_RATIO or fill_ratio < MIN_FILL_RATIO:
                continue
            rough_rect = Rect(x, y, w, h)
            rect = self._trim_rect(frame, rough_rect)
            if rect.width < MIN_TOOLTIP_WIDTH or rect.height < MIN_TOOLTIP_HEIGHT:
                continue
            if self._is_likely_hud_overlay_rect(frame, rect):
                continue
            refined_mask = mask[rect.y:rect.bottom, rect.x:rect.right]
            refined_dark_ratio = float(np.mean(refined_mask > 0)) if refined_mask.size else 0.0
            candidates.append((rect, refined_dark_ratio, fill_ratio))
        if not candidates:
            return None
        candidates.sort(key=lambda item: (item[1], item[2], item[0].width * item[0].height), reverse=True)
        return candidates[0][0]

    def _detect_rect_by_dark_window(self, frame: np.ndarray) -> Rect | None:
        height, width = frame.shape[:2]
        if width <= 0 or height <= 0:
            return None
        frame_scale = self._resolution_scale(frame)
        expected_width = int(round(BASE_TOOLTIP_WIDTH * frame_scale))
        expected_width = max(MIN_TOOLTIP_WIDTH, min(int(width * MAX_TOOLTIP_WIDTH_RATIO), expected_width))
        max_height = int(height * MAX_TOOLTIP_HEIGHT_RATIO)
        mask = self._dark_mask(frame)
        gray = cv2.cvtColor(frame[:, :, :3], cv2.COLOR_BGR2GRAY)
        panel_mask = (gray < 55).astype(np.uint8) * 255
        value = cv2.cvtColor(frame[:, :, :3], cv2.COLOR_BGR2HSV)[:, :, 2]
        text_mask = (value > 70) & (gray > 45)
        candidates: list[tuple[Rect, float]] = []
        x_step = max(2, int(round(4 * frame_scale)))
        padding_bottom = max(12, int(round(24 * frame_scale)))
        min_row_ratio = 0.004
        dark_start_gap = max(28, int(round(45 * frame_scale)))
        for x in range(0, max(1, width - expected_width + 1), x_step):
            x2 = min(width, x + expected_width)
            row_dark = np.mean(panel_mask[:, x:x2] > 0, axis=1)
            row_text = np.mean(text_mask[:, x:x2], axis=1)
            dark_segments = self._row_segments(row_dark >= 0.42, max_gap=max(2, int(round(5 * frame_scale))))
            text_rows_all = np.flatnonzero(row_text >= min_row_ratio)
            if text_rows_all.size < max(6, int(round(10 * frame_scale))):
                continue
            for top, _ in dark_segments:
                text_rows = text_rows_all[(text_rows_all >= top) & (text_rows_all <= top + max_height)]
                if text_rows.size < max(6, int(round(10 * frame_scale))):
                    continue
                first_text = int(text_rows[0])
                if first_text - top > dark_start_gap:
                    continue
                bottom = min(height, int(text_rows[-1]) + padding_bottom)
                rect = Rect(x, top, x2 - x, bottom - top).clamp(width, height)
                rect = self._align_dark_window_left_edge(panel_mask, rect, expected_width)
                if rect.height < MIN_TOOLTIP_HEIGHT or rect.height > max_height:
                    continue
                if self._is_likely_hud_overlay_rect(frame, rect):
                    continue
                dark_crop = mask[rect.y:rect.bottom, rect.x:rect.right]
                text_crop = text_mask[rect.y:rect.bottom, rect.x:rect.right]
                if dark_crop.size == 0:
                    continue
                dark_ratio = float(np.mean(dark_crop > 0))
                text_ratio = float(np.mean(text_crop))
                if dark_ratio < 0.18 or text_ratio < 0.003:
                    continue
                span_score = min(1.0, rect.height / max(1.0, 190 * frame_scale))
                score = dark_ratio * 2.5 + text_ratio * 220.0 + span_score
                candidates.append((rect, score))
        if not candidates:
            return None
        candidates.sort(key=lambda item: item[1], reverse=True)
        return candidates[0][0]

    @staticmethod
    def _align_dark_window_left_edge(mask: np.ndarray, rect: Rect, expected_width: int) -> Rect:
        crop = mask[rect.y:rect.bottom, rect.x:rect.right]
        if crop.size == 0:
            return rect
        column_ratios = np.mean(crop > 0, axis=0)
        dark_columns = np.flatnonzero(column_ratios >= 0.42)
        if dark_columns.size == 0:
            return rect
        left_offset = int(dark_columns[0])
        if left_offset <= 2 or left_offset > expected_width * 0.45:
            return rect
        left_padding = 0
        new_x = min(mask.shape[1] - expected_width, max(0, rect.x + left_offset - left_padding))
        return Rect(new_x, rect.y, expected_width, rect.height).clamp(mask.shape[1], mask.shape[0])

    @staticmethod
    def _row_segments(mask: np.ndarray, *, max_gap: int) -> list[tuple[int, int]]:
        segments: list[tuple[int, int]] = []
        start: int | None = None
        misses = 0
        for index, value in enumerate(mask):
            if bool(value):
                if start is None:
                    start = index
                misses = 0
                continue
            if start is None:
                continue
            misses += 1
            if misses <= max_gap:
                continue
            segments.append((start, index - misses + 1))
            start = None
            misses = 0
        if start is not None:
            segments.append((start, len(mask)))
        return segments

    @staticmethod
    def _append_dark_window_candidate(
        frame: np.ndarray,
        mask: np.ndarray,
        gray: np.ndarray,
        value: np.ndarray,
        candidates: list[tuple[Rect, float]],
        x: int,
        y: int,
        width: int,
        height: int,
        max_height: int,
    ) -> None:
        if height < MIN_TOOLTIP_HEIGHT or height > max_height:
            return
        rect = Rect(x, y, width, height).clamp(frame.shape[1], frame.shape[0])
        if rect.width < MIN_TOOLTIP_WIDTH or rect.height < MIN_TOOLTIP_HEIGHT or rect.height > max_height:
            return
        if ItemInfoDetector._is_likely_hud_overlay_rect(frame, rect):
            return
        dark_crop = mask[rect.y:rect.bottom, rect.x:rect.right]
        gray_crop = gray[rect.y:rect.bottom, rect.x:rect.right]
        value_crop = value[rect.y:rect.bottom, rect.x:rect.right]
        if dark_crop.size == 0:
            return
        dark_ratio = float(np.mean(dark_crop > 0))
        bright_ratio = float(np.mean((value_crop > 70) & (gray_crop > 45)))
        if dark_ratio < 0.35 or bright_ratio < 0.002:
            return
        height_score = min(1.0, rect.height / 260.0)
        score = dark_ratio * 4.0 + bright_ratio * 180.0 + height_score
        candidates.append((rect, score))

    @staticmethod
    def _best_detected_rect(frame: np.ndarray, candidates: list[Rect]) -> Rect:
        frame_scale = ItemInfoDetector._resolution_scale(frame)
        expected_width = BASE_TOOLTIP_WIDTH * frame_scale
        scored: list[tuple[float, Rect]] = []
        gray = cv2.cvtColor(frame[:, :, :3], cv2.COLOR_BGR2GRAY)
        value = cv2.cvtColor(frame[:, :, :3], cv2.COLOR_BGR2HSV)[:, :, 2]
        for rect in candidates:
            width_error = abs(rect.width - expected_width) / max(1.0, expected_width)
            crop_gray = gray[rect.y:rect.bottom, rect.x:rect.right]
            crop_value = value[rect.y:rect.bottom, rect.x:rect.right]
            bright_ratio = float(np.mean((crop_value > 70) & (crop_gray > 45))) if crop_gray.size else 0.0
            dark_ratio = ItemInfoDetector._rect_dark_ratio(frame, rect)
            score = dark_ratio * 4.0 + bright_ratio * 180.0 + min(1.0, rect.height / 240.0) - width_error * 2.0
            if rect.height < 60 * frame_scale:
                score -= 2.0
            scored.append((score, rect))
        scored.sort(key=lambda item: item[0], reverse=True)
        return scored[0][1]

    def _detect_rect_by_ocr(self, frame: np.ndarray) -> Rect | None:
        try:
            import pytesseract
        except Exception:
            return None
        self._configure_tesseract(pytesseract)
        height, width = frame.shape[:2]
        if width <= 0 or height <= 0:
            return None
        frame_scale = self._resolution_scale(frame)
        expected_width = int(round(BASE_TOOLTIP_WIDTH * frame_scale))
        expected_width = max(MIN_TOOLTIP_WIDTH, min(int(width * MAX_TOOLTIP_WIDTH_RATIO), expected_width))
        ocr_scale = 1.0 if min(width, height) >= 700 else 2.0
        scaled = cv2.resize(frame[:, :, :3], None, fx=ocr_scale, fy=ocr_scale, interpolation=cv2.INTER_CUBIC)
        gray = cv2.cvtColor(scaled, cv2.COLOR_BGR2GRAY)
        _, threshold = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
        words = self._ocr_words(pytesseract, Image.fromarray(threshold), ocr_scale)
        if not words:
            words = self._ocr_words(pytesseract, Image.fromarray(gray), ocr_scale)
        if not words:
            return None
        candidate_x = self._ocr_candidate_x_values(words, expected_width, width)
        best_rect: Rect | None = None
        best_score = 0.0
        for x in candidate_x:
            clustered_words = self._cluster_ocr_words(words, x, expected_width, height)
            if not clustered_words:
                continue
            score = self._score_ocr_cluster(clustered_words, expected_width)
            min_y = min(word["top"] for word in clustered_words)
            max_y = max(word["bottom"] for word in clustered_words)
            min_x = min(word["left"] for word in clustered_words)
            padding_top = int(round(22 * frame_scale))
            padding_bottom = int(round(20 * frame_scale))
            y = max(0, min_y - padding_top)
            rect_width = expected_width
            rect_x = int(round(min(max(0, x), max(0, width - rect_width))))
            if min_x > rect_x + int(45 * frame_scale):
                rect_x = max(0, min(width - rect_width, min_x - int(round(22 * frame_scale))))
            rect_height = max(MIN_TOOLTIP_HEIGHT, max_y - min_y + padding_top + padding_bottom)
            rect = Rect(rect_x, y, rect_width, rect_height).clamp(width, height)
            if height - rect.bottom <= max(35, int(round(40 * frame_scale))):
                rect = Rect(rect.x, rect.y, rect.width, height - rect.y)
            if self._is_likely_hud_overlay_rect(frame, rect):
                continue
            dark_score = self._rect_dark_ratio(frame, rect)
            if dark_score < 0.12:
                continue
            score += min(1.0, dark_score) * 6.0
            if score <= best_score:
                continue
            rect = self._expand_ocr_rect_to_dark_panel(frame, rect)
            best_rect = rect
            best_score = score
        if best_rect is None or best_score < OCR_RECT_MIN_SCORE:
            return None
        return best_rect

    @staticmethod
    def _ocr_words(pytesseract_module: Any, image: Image.Image, scale: float) -> list[dict[str, int | str]]:
        try:
            data = pytesseract_module.image_to_data(
                image,
                lang="rus+eng",
                config="--psm 11",
                output_type=pytesseract_module.Output.DICT,
                timeout=5,
            )
        except Exception:
            return []
        result: list[dict[str, int | str]] = []
        for index, raw_text in enumerate(data.get("text", [])):
            text = ItemInfoDetector._clean_ocr_word(str(raw_text))
            if not ItemInfoDetector._valid_ocr_word(text):
                continue
            try:
                confidence = float(data.get("conf", [0])[index])
            except (TypeError, ValueError, IndexError):
                confidence = 0.0
            if confidence < OCR_WORD_CONFIDENCE:
                continue
            left = int(round(int(data["left"][index]) / scale))
            top = int(round(int(data["top"][index]) / scale))
            width = int(round(int(data["width"][index]) / scale))
            height = int(round(int(data["height"][index]) / scale))
            source_height = max(1, int(round(image.height / scale)))
            if height > max(30, int(round(source_height * 0.035))):
                continue
            result.append({"text": text, "left": left, "top": top, "right": left + width, "bottom": top + height})
        return result

    @staticmethod
    def _clean_ocr_word(text: str) -> str:
        text = text.strip().strip(".,;:!?'\"()[]{}<>«»|/\\")
        return re.sub(r"\s+", " ", text)

    @staticmethod
    def _valid_ocr_word(text: str) -> bool:
        if not text:
            return False
        letters = re.sub(r"[^A-Za-zА-Яа-яЁёβΒ]", "", text)
        digits = re.sub(r"\D", "", text)
        if len(letters) <= 2 and re.fullmatch(r"[A-Za-z]+", letters or ""):
            return text.lower() in {"kg"}
        return len(letters) >= 2 or bool(digits)

    @staticmethod
    def _ocr_candidate_x_values(words: list[dict[str, int | str]], expected_width: int, image_width: int) -> list[int]:
        values: set[int] = set()
        for word in words:
            left = int(word["left"])
            right = int(word["right"])
            center = (left + right) // 2
            for value in (left - 18, right - expected_width + 18, center - expected_width // 2):
                values.add(max(0, min(image_width - expected_width, int(value))))
        return sorted(values)

    @staticmethod
    def _cluster_ocr_words(
        words: list[dict[str, int | str]],
        x: int,
        expected_width: int,
        image_height: int,
    ) -> list[dict[str, int | str]]:
        left = x + 6
        right = x + expected_width - 4
        inside = [word for word in words if int(word["left"]) >= left and int(word["right"]) <= right]
        if not inside:
            return []
        inside.sort(key=lambda word: (int(word["top"]), int(word["left"])))
        max_gap = max(28, int(round(image_height / 13)))
        best: list[dict[str, int | str]] = []
        current: list[dict[str, int | str]] = []
        last_bottom: int | None = None
        for word in inside:
            top = int(word["top"])
            bottom = int(word["bottom"])
            if last_bottom is None or top - last_bottom <= max_gap:
                current.append(word)
            else:
                if len(current) > len(best):
                    best = current
                current = [word]
            last_bottom = max(last_bottom or bottom, bottom)
        if len(current) > len(best):
            best = current
        return ItemInfoDetector._drop_left_numeric_artifacts(best)

    @staticmethod
    def _drop_left_numeric_artifacts(words: list[dict[str, int | str]]) -> list[dict[str, int | str]]:
        alpha_left_values = [int(word["left"]) for word in words if len(re.sub(r"[^A-Za-zА-Яа-яЁёβΒ]", "", str(word["text"]))) >= 2]
        if not alpha_left_values:
            return words
        alpha_left = min(alpha_left_values)
        filtered = []
        for word in words:
            text = str(word["text"])
            letters = re.sub(r"[^A-Za-zА-Яа-яЁёβΒ]", "", text)
            digits = re.sub(r"\D", "", text)
            if digits and not letters and int(word["right"]) < alpha_left - 12:
                continue
            filtered.append(word)
        return filtered

    @staticmethod
    def _score_ocr_cluster(words: list[dict[str, int | str]], expected_width: int) -> float:
        if len(words) < 2:
            return 0.0
        text = " ".join(str(word["text"]).lower() for word in words)
        score = float(len(words))
        letter_count = len(re.findall(r"[A-Za-zА-Яа-яЁёβΒ]", text))
        digit_count = len(re.findall(r"\d", text))
        score += min(8.0, letter_count / 8.0)
        score += min(4.0, digit_count / 2.0)
        if re.search(r"\d+(?:[.,:]\d+)?\s*(?:кг|kg)", text):
            score += 5.0
        if re.search(r"[+-]\s*\d+\s+к\s+[A-Za-zА-Яа-яЁёβΒ]{3,}", text):
            score += 4.0
        min_x = min(int(word["left"]) for word in words)
        max_x = max(int(word["right"]) for word in words)
        min_y = min(int(word["top"]) for word in words)
        max_y = max(int(word["bottom"]) for word in words)
        if max_x - min_x > expected_width * 0.92:
            score -= 4.0
        if max_y - min_y < 28:
            score -= 3.0
        return score

    @staticmethod
    def _should_try_ocr_rect(frame: np.ndarray, rect: Rect) -> bool:
        height, width = frame.shape[:2]
        frame_scale = ItemInfoDetector._resolution_scale(frame)
        expected_width = BASE_TOOLTIP_WIDTH * frame_scale
        if rect.y <= 2 and rect.height < 110 * frame_scale:
            return True
        if rect.height < max(MIN_TOOLTIP_HEIGHT, int(82 * frame_scale)):
            return True
        if abs(rect.width - expected_width) > max(12, int(14 * frame_scale)):
            return True
        if rect.width < expected_width * 0.82:
            return True
        return False

    @staticmethod
    def _ocr_rect_is_better(frame: np.ndarray, contour_rect: Rect, ocr_rect: Rect) -> bool:
        frame_scale = ItemInfoDetector._resolution_scale(frame)
        expected_width = BASE_TOOLTIP_WIDTH * frame_scale
        contour_width_error = abs(contour_rect.width - expected_width)
        ocr_width_error = abs(ocr_rect.width - expected_width)
        if contour_rect.y <= 2 and contour_rect.height < 110 * frame_scale:
            return True
        if contour_rect.height < 82 * frame_scale:
            return True
        if ocr_width_error + 4 < contour_width_error and ocr_rect.height <= contour_rect.height + max(16, int(22 * frame_scale)):
            return True
        return False

    @staticmethod
    def _is_likely_hud_overlay_rect(frame: np.ndarray, rect: Rect) -> bool:
        height, width = frame.shape[:2]
        if width <= 0 or height <= 0:
            return False
        right_edge_margin = max(18, int(round(width * 0.05)))
        if rect.x >= int(width * 0.78) and rect.right >= width - right_edge_margin and rect.y <= int(height * 0.36):
            return True
        if rect.x >= int(width * 0.70) and rect.height >= int(height * 0.85):
            return True
        return rect.x <= int(width * 0.24) and rect.y >= int(height * 0.58)

    @staticmethod
    def _rect_dark_ratio(frame: np.ndarray, rect: Rect) -> float:
        height, width = frame.shape[:2]
        clamped = rect.clamp(width, height)
        if clamped.width <= 0 or clamped.height <= 0:
            return 0.0
        mask = ItemInfoDetector._dark_mask(frame)
        crop = mask[clamped.y:clamped.bottom, clamped.x:clamped.right]
        return float(np.mean(crop > 0)) if crop.size else 0.0

    @staticmethod
    def _expand_ocr_rect_to_dark_panel(frame: np.ndarray, rect: Rect) -> Rect:
        height, width = frame.shape[:2]
        clamped = rect.clamp(width, height)
        if clamped.width <= 0 or clamped.height <= 0:
            return clamped
        mask = ItemInfoDetector._dark_mask(frame)
        frame_scale = ItemInfoDetector._resolution_scale(frame)
        max_gap = max(3, int(round(6 * frame_scale)))
        top = clamped.y
        misses = 0
        while top > 0:
            row = mask[top - 1, clamped.x:clamped.right]
            dark_ratio = float(np.mean(row > 0)) if row.size else 0.0
            if dark_ratio >= 0.42:
                misses = 0
            else:
                misses += 1
                if misses > max_gap:
                    top += misses
                    break
            top -= 1
        top = max(0, min(clamped.y, top))
        return Rect(clamped.x, top, clamped.width, clamped.bottom - top)

    @staticmethod
    def _resolution_scale(frame: np.ndarray) -> float:
        height = frame.shape[0]
        return max(0.35, min(2.0, height / 1080.0))

    @staticmethod
    def _dark_mask(frame: np.ndarray) -> np.ndarray:
        bgr = frame[:, :, :3]
        return ((bgr[:, :, 0] < DARK_RGB_THRESHOLD) & (bgr[:, :, 1] < DARK_RGB_THRESHOLD) & (bgr[:, :, 2] < DARK_RGB_THRESHOLD)).astype(np.uint8) * 255

    @staticmethod
    def _trim_rect(frame: np.ndarray, rect: Rect) -> Rect:
        height, width = frame.shape[:2]
        clamped = rect.clamp(width, height)
        x = clamped.x
        y = clamped.y
        rect_width = clamped.width
        rect_height = clamped.height
        if rect_width == 0 or rect_height == 0:
            return clamped
        gray = cv2.cvtColor(frame[:, :, :3], cv2.COLOR_BGR2GRAY)
        mask = gray < TRIM_GRAY_THRESHOLD
        for _ in range(TRIM_PASSES):
            while rect_height > 1 and float(np.mean(mask[y, x:x + rect_width])) < TRIM_EDGE_DARK_RATIO:
                y += 1
                rect_height -= 1
            while rect_height > 1 and float(np.mean(mask[y + rect_height - 1, x:x + rect_width])) < TRIM_EDGE_DARK_RATIO:
                rect_height -= 1
            while rect_width > 1 and float(np.mean(mask[y:y + rect_height, x])) < TRIM_EDGE_DARK_RATIO:
                x += 1
                rect_width -= 1
            while rect_width > 1 and float(np.mean(mask[y:y + rect_height, x + rect_width - 1])) < TRIM_EDGE_DARK_RATIO:
                rect_width -= 1
        rect = Rect(x, y, rect_width, rect_height)
        return ItemInfoDetector._split_merged_top_panel(gray, mask, rect)

    @staticmethod
    def _split_merged_top_panel(gray: np.ndarray, mask: np.ndarray, rect: Rect) -> Rect:
        if rect.height < 280 or rect.x < 8:
            return rect
        left_width = min(12, rect.x)
        right_width = min(12, gray.shape[1] - rect.right)
        if right_width <= 0:
            return rect
        scan_height = min(MERGED_TOP_SCAN_HEIGHT, rect.height // 3)
        left_means = [float(np.mean(gray[rect.y + offset, rect.x - left_width:rect.x])) for offset in range(scan_height)]
        right_means = [float(np.mean(gray[rect.y + offset, rect.right:rect.right + right_width])) for offset in range(scan_height)]
        if float(np.mean(left_means[:8])) < 95.0 or float(np.mean(right_means[:8])) > 40.0:
            return rect
        for offset in range(8, scan_height):
            inside_dark_ratio = float(np.mean(mask[rect.y + offset, rect.x:rect.right]))
            if inside_dark_ratio > 0.9 and left_means[offset] < 70.0:
                return Rect(rect.x, rect.y + offset, rect.width, rect.height - offset)
        return rect

    @staticmethod
    def _refine_rect_for_ocr(frame: np.ndarray, rect: Rect) -> Rect:
        height, width = frame.shape[:2]
        clamped = rect.clamp(width, height)
        crop = frame[clamped.slice()]
        if crop.size == 0 or crop.shape[0] < 80:
            return clamped
        gray = cv2.cvtColor(crop[:, :, :3], cv2.COLOR_BGR2GRAY)
        dark_ratio = np.mean(gray < 35, axis=1)
        window = max(8, min(18, crop.shape[0] // 10))
        top_window = min(24, crop.shape[0])
        top_dark = float(np.mean(dark_ratio[:top_window]))
        best_start = 0
        for index in range(0, max(1, len(dark_ratio) - window)):
            if float(np.mean(dark_ratio[index:index + window])) >= 0.88:
                best_start = index
                break
        if best_start > 12 and top_dark < 0.78:
            return Rect(clamped.x, clamped.y + best_start, clamped.width, clamped.height - best_start).clamp(width, height)
        return clamped

    @staticmethod
    def _text_crop(frame: np.ndarray, rect: Rect) -> np.ndarray:
        height, width = frame.shape[:2]
        clamped = rect.clamp(width, height)
        x1 = min(clamped.right, clamped.x + OCR_PADDING_LEFT)
        y1 = min(clamped.bottom, clamped.y + OCR_PADDING_TOP)
        x2 = max(x1, clamped.right - OCR_PADDING_RIGHT)
        y2 = max(y1, clamped.bottom - OCR_PADDING_BOTTOM)
        return frame[y1:y2, x1:x2]

    @staticmethod
    def _title_crop(frame: np.ndarray, rect: Rect) -> np.ndarray:
        height, width = frame.shape[:2]
        clamped = rect.clamp(width, height)
        x1 = clamped.x
        y1 = clamped.y
        x2 = max(x1, clamped.right - OCR_PADDING_RIGHT)
        y2 = min(clamped.bottom, clamped.y + TITLE_REGION_HEIGHT)
        return ItemInfoDetector._text_line_crop(frame, x1, y1, x2, y2, first=True)

    @staticmethod
    def _weight_crop(frame: np.ndarray, rect: Rect) -> np.ndarray:
        height, width = frame.shape[:2]
        clamped = rect.clamp(width, height)
        x1 = clamped.x
        y1 = max(clamped.y, clamped.bottom - WEIGHT_REGION_HEIGHT)
        x2 = min(clamped.right, clamped.x + 130)
        y2 = clamped.bottom
        return ItemInfoDetector._text_line_crop(frame, x1, y1, x2, y2, first=False)

    @staticmethod
    def _text_line_crop(frame: np.ndarray, x1: int, y1: int, x2: int, y2: int, *, first: bool) -> np.ndarray:
        crop = frame[y1:y2, x1:x2]
        if crop.size == 0:
            return crop
        gray = cv2.cvtColor(crop[:, :, :3], cv2.COLOR_BGR2GRAY)
        bright_rows = np.mean(gray > 90, axis=1) > 0.015
        groups: list[tuple[int, int]] = []
        start: int | None = None
        for index, is_bright in enumerate(bright_rows):
            if is_bright and start is None:
                start = index
            if start is not None and (not is_bright or index == len(bright_rows) - 1):
                end = index + 1 if is_bright and index == len(bright_rows) - 1 else index
                if end - start >= 2:
                    groups.append((start, end))
                start = None
        if not groups:
            return crop
        if first:
            top, bottom = groups[0]
        else:
            top, bottom = groups[-1]
        top = max(0, top - 4)
        bottom = min(crop.shape[0], bottom + 4)
        return crop[top:bottom, :]

    @classmethod
    def _ocr_lines(cls, pytesseract_module: Any, crop: np.ndarray, *, region: str = "full") -> list[str]:
        if crop.size == 0:
            return []
        scale = 4.0 if min(crop.shape[:2]) < 220 else 2.5
        scaled = cv2.resize(crop, None, fx=scale, fy=scale, interpolation=cv2.INTER_CUBIC)
        gray = cv2.cvtColor(scaled, cv2.COLOR_BGR2GRAY)
        value = cv2.cvtColor(scaled, cv2.COLOR_BGR2HSV)[:, :, 2]
        max_channel = scaled[:, :, :3].max(axis=2)
        _, threshold = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
        _, value_threshold = cv2.threshold(value, 50, 255, cv2.THRESH_BINARY)
        _, max_threshold = cv2.threshold(max_channel, 45, 255, cv2.THRESH_BINARY)
        if region == "full":
            candidates = (gray, value_threshold)
        elif region == "title":
            candidates = (gray, value_threshold)
        else:
            candidates = (gray, value_threshold)
        best_lines: list[str] = []
        collected_lines: list[str] = []
        for lang, config in cls._ocr_configs(region):
            for candidate in candidates:
                try:
                    text = pytesseract_module.image_to_string(Image.fromarray(candidate), lang=lang, config=config, timeout=3)
                except Exception:
                    continue
                lines = [cls._clean_line(line) for line in text.splitlines()]
                lines = [line for line in lines if line]
                if region == "full":
                    collected_lines = cls._dedupe_lines([*collected_lines, *lines])
                if cls._score_lines(lines) > cls._score_lines(best_lines):
                    best_lines = lines
                    if region == "title" and cls._extract_title(best_lines):
                        return best_lines
                    if region == "weight" and cls._extract_weight(best_lines):
                        return best_lines
        return collected_lines if region == "full" and collected_lines else best_lines

    @staticmethod
    def _dedupe_lines(lines: list[str]) -> list[str]:
        result: list[str] = []
        normalized_seen: set[str] = set()
        for line in lines:
            normalized = re.sub(r"\s+", " ", line.casefold()).strip()
            if not normalized or normalized in normalized_seen:
                continue
            normalized_seen.add(normalized)
            result.append(line)
        return result

    @staticmethod
    def _ocr_configs(region: str) -> tuple[tuple[str, str], ...]:
        if region == "title":
            base_configs = (("eng+rus+ell", "--oem 3 --psm 7"), ("rus+eng+ell", "--oem 3 --psm 7"), ("eng+rus", "--oem 3 --psm 7"))
        elif region == "weight":
            base_configs = (("rus+eng", "--oem 3 --psm 7"),)
        else:
            base_configs = (("rus+eng", "--oem 3 --psm 6"),)
        configs: list[tuple[str, str]] = []
        for lang, config in base_configs:
            project_config = tessdata_config(config, lang)
            configs.append((lang, project_config))
            if project_config == config:
                continue
            configs.append((lang, config))
        return tuple(configs)

    @staticmethod
    def _score_lines(lines: list[str]) -> tuple[int, int, int, int]:
        if not lines:
            return 0, 0, 0, 0
        letters = sum(len(re.findall(r"[A-Za-zА-Яа-яЁёβΒ]", line)) for line in lines)
        numbers = sum(len(re.findall(r"\d", line)) for line in lines)
        markers = sum(1 for line in lines if ":" in line or re.search(r"[+-]\d+", line))
        return len(lines), markers, letters, numbers

    @staticmethod
    def _clean_line(line: str) -> str:
        line = line.replace("`", " ").strip()
        line = re.sub(r"\s+", " ", line)
        return line.strip(" |")

    @classmethod
    def _extract_title(cls, lines: list[str]) -> str:
        for line in lines:
            cleaned = cls._clean_title(line)
            if not cleaned or re.match(r"^[+\-]?\d", cleaned):
                continue
            if ItemInfoParser._is_metadata_line(cleaned):
                continue
            if cls._suspicious_title(cleaned):
                continue
            if re.search(r"[><|\[\]{}]", cleaned):
                continue
            letters = len(re.findall(r"[A-Za-zА-Яа-яЁёβΒ]", cleaned))
            if letters < 3:
                continue
            punctuation = len(re.findall(r'[^0-9A-Za-zА-Яа-яЁёβΒ\s.,:;!?\'"()\-+%№]', cleaned))
            if punctuation:
                continue
            return cleaned
        return ""

    @staticmethod
    def _clean_title(line: str) -> str:
        cleaned = re.sub(r"^[^0-9A-Za-zА-Яа-яЁёβΒ]+", "", line).strip()
        cleaned = re.sub(r"\s+", " ", cleaned)
        cleaned = ItemInfoDetector._normalize_allowed_title_token(cleaned)
        tokens = cleaned.split()
        while len(tokens) > 1 and len(re.sub(r"[^A-Za-zА-Яа-яЁёβΒ]", "", tokens[0])) <= 2:
            next_letters = re.sub(r"[^A-Za-zА-Яа-яЁёβΒ]", "", tokens[1])
            if len(next_letters) < 3:
                break
            tokens.pop(0)
        if tokens and all(len(re.sub(r"[^A-Za-zА-Яа-яЁёβΒ]", "", token)) <= 2 for token in tokens):
            return ""
        return " ".join(tokens)

    @staticmethod
    def _normalize_allowed_title_token(title: str) -> str:
        # Единственное разрешенное точечное исправление: в тестовых данных и игре это
        # смешанное латиница + греческая beta. Остальные названия OCR обязан читать сам.
        return re.sub(r"\bPi[βΒBВß8]wasser\b", "Piβwasser", title, flags=re.IGNORECASE)

    @classmethod
    def _extract_weight(cls, lines: list[str]) -> str:
        unit_pattern = r"(\d+(?:[.,:]\d+)?)\s*(?:кг|kg|кз|кс|ке|кё|кв|кб|ke|xs|me|«g|@|&|№)(?![A-Za-zА-Яа-яЁёβΒ])"
        for line in reversed(lines):
            normalized_line = line.replace("O", "0").replace("О", "0")
            match = re.search(r"^\s*(\d+(?:[.,:]?\d+)?)\s+[^0-9]*(?:состояние|cocтoяние)", normalized_line, flags=re.IGNORECASE)
            if match:
                return cls._normalize_weight(match.group(1))
        for line in reversed(lines):
            normalized_line = line.replace("O", "0").replace("О", "0")
            match = re.search(unit_pattern, normalized_line, flags=re.IGNORECASE)
            if match:
                return cls._normalize_weight(match.group(1))
        for line in reversed(lines):
            normalized_line = line.replace("O", "0").replace("О", "0")
            match = re.search(r"^[^0-9]*(\d+(?:[.,:]\d+)?)[^0-9A-Za-zА-Яа-яЁёβΒ]*$", normalized_line, flags=re.IGNORECASE)
            if match:
                return cls._normalize_weight(match.group(1))
        return ""

    @staticmethod
    def _normalize_weight(raw: str) -> str:
        value = raw.replace(",", ".").replace(":", ".")
        if "." in value:
            return value
        if value.startswith("0") and len(value) == 2:
            return f"0.{value[1:]}"
        if value.startswith("0") and len(value) == 3:
            return f"0.{value[1:]}"
        return value

    @staticmethod
    def _configure_tesseract(pytesseract_module: Any) -> None:
        configure_tesseract(pytesseract_module)
