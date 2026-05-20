from __future__ import annotations

from difflib import SequenceMatcher
import re


FISH_DISPLAY_NAMES: dict[str, str] = {
    "albula": "Альбула",
    "ancient_gyneria": "Древняя гинерия",
    "barracuda": "Барракуда",
    "bream_leshch": "Лещ",
    "common_snook": "Снук обыкновенный",
    "golavl": "Голавль",
    "korichnevy_som": "Коричневый сом",
    "krasny_gorbyl": "Красный горбыль",
    "krugly_trahinot": "Круглый трахинот",
    "marlin": "Марлин",
    "obyknovennaya_shchuka": "Обыкновенная щука",
    "polosaty_lavrak": "Полосатый лаврак",
    "pribrezhny_bass": "Прибрежный басс",
    "raduzhnaya_forel": "Радужная форель",
    "rechnoy_okun": "Речной окунь",
    "roach_plotva": "Плотва",
    "roach_vobla": "Вобла",
    "rudd_krasnoperka": "Краснопёрка",
    "ruster": "Рустер",
    "sazan": "Сазан",
    "serebryany_karas": "Серебряный карась",
    "seriola": "Сериола",
    "som_obyknovennyy": "Сом обыкновенный",
    "steelhead_salmon": "Стальноголовый лосось",
    "sterlet": "Стерлядь",
    "sudak_obyknovennyy": "Судак обыкновенный",
    "tarpon": "Тарпон",
    "temny_gorbyl": "Тёмный горбыль",
    "toksichny_okun": "Токсичный окунь",
    "zerkalny_karp": "Зеркальный карп",
    "zhereh": "Жерех",
}


def fish_display_name(fish_id: str | None) -> str:
    if not fish_id:
        return "unknown"
    return FISH_DISPLAY_NAMES.get(fish_id, fish_id)


def fish_id_from_display(text: str | None) -> str | None:
    if not text:
        return None
    normalized = _normalize(text)
    if len(normalized) < 4:
        return None
    best_id: str | None = None
    best_score = 0.0
    for fish_id, display_name in FISH_DISPLAY_NAMES.items():
        candidate = _normalize(display_name)
        if candidate == normalized:
            return fish_id
        score = SequenceMatcher(None, normalized, candidate).ratio()
        if score > best_score:
            best_id = fish_id
            best_score = score
    if best_score >= 0.72:
        return best_id
    return None


def _normalize(text: str) -> str:
    return re.sub(r"[^0-9a-zа-яё]+", "", text.lower())
