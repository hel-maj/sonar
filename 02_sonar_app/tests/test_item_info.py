from __future__ import annotations

import csv
import struct
from pathlib import Path

import cv2
import numpy as np
import pytest

from sonar.fishing.item_info import ItemInfoDetector, ItemInfoParser
from sonar.fishing.player_status import PlayerStatusDetector, PlayerStatusMemoryDetector
from sonar.vision.geometry import Rect


FIXTURE_DIR = Path(__file__).parent / "fixtures" / "inventory_item_info"
METADATA_PATH = FIXTURE_DIR / "metadata.csv"
STATUS_METADATA_PATH = FIXTURE_DIR / "status_metadata.csv"
COORDINATE_TOLERANCE = 64
LOW_RES_SCALE = 0.5
LOW_RES_FIXTURE_NAMES = {
    "20260524180108_1.jpg",
    "20260524180903_1.jpg",
    "20260524180947_1.jpg",
    "20260524201249_1.jpg",
    "20260524202216_1.jpg",
    "20260524202329_1.jpg",
    "20260524203627_1.jpg",
}


def metadata_rows() -> list[dict[str, str]]:
    with METADATA_PATH.open(encoding="utf-8-sig", newline="") as file:
        return list(csv.DictReader(file, delimiter=";"))


def low_res_rows() -> list[dict[str, str]]:
    return [row for row in metadata_rows() if row["source_image"] in LOW_RES_FIXTURE_NAMES]


def status_rows() -> list[dict[str, str]]:
    with STATUS_METADATA_PATH.open(encoding="utf-8-sig", newline="") as file:
        return list(csv.DictReader(file, delimiter=";"))


def ocr_crop_rows() -> list[dict[str, str]]:
    rows = metadata_rows()
    selectors = [
        lambda row: bool(row["satiety_change"] and row["thirst_change"] and not row["condition_percent"] and not row["poison_chance"]),
        lambda row: bool(row["condition_percent"] and row["poison_chance"]),
        lambda row: bool(row["gender"] and not row["parameter_modifications"]),
        lambda row: bool(row["strength"]),
        lambda row: bool(row["gender"] and row["parameter_modifications"]),
    ]
    selected: list[dict[str, str]] = []
    for selector in selectors:
        for row in rows:
            crop_path = FIXTURE_DIR / row["crop_image"]
            if crop_path.exists() and selector(row) and row not in selected:
                selected.append(row)
                break
    return selected


def geometry_rows() -> list[dict[str, str]]:
    return ocr_crop_rows()


OCR_SCREENSHOT_EXPECTATIONS = [
    (
        "20260524202218_1.jpg",
        {
            "title": "Энергетик",
            "weight": "0.45",
            "satiety_change": "",
            "thirst_change": "+50",
            "condition_percent": "",
            "poison_chance": "",
            "effects": ("Ускорение",),
            "effect_durations": ("15 м.",),
            "effect_descriptions": ("Ускорение скорости передвижения.",),
            "parameter_modifications": ("+10% к скорости бега", "+100 к выносливости"),
            "description": "Напиток, содержащий компоненты обеспечивающие физическую стимуляцию.",
        },
    ),
    (
        "20260524202315_1.jpg",
        {
            "title": "Жаркое из зайца по-домашнему",
            "weight": "0.85",
            "satiety_change": "+45",
            "thirst_change": "+4",
            "condition_percent": "75",
            "poison_chance": "Низкий",
            "effects": ("Вакцина", "Противовирусное", "Детокс"),
            "effect_durations": (),
            "effect_descriptions": (
                "Подавление инфекции и возвращение жизненной силы.",
                "Избавление от простуды и её симптомов.",
                "Лечение отравления путём вывода токсинов из организма.",
            ),
            "parameter_modifications": (),
            "description": (
                "Сытное домашнее блюдо для уютного ужина. Диетическое мясо зайца, медленно "
                "тушенное в закрытой посуде с молодой картошкой, сладкой морковью и репчатым "
                "луком. Блюдо можно продать у любого бармена в городе!"
            ),
        },
    ),
    (
        "20260524202323_1.jpg",
        {
            "title": "BIOLINK",
            "weight": "0.4",
            "satiety_change": "+100",
            "thirst_change": "+100",
            "condition_percent": "",
            "poison_chance": "",
            "effects": ("Анабиоз",),
            "effect_durations": ("5 ч.",),
            "effect_descriptions": ("Избавление от жажды и голода.",),
            "parameter_modifications": (),
            "description": (
                "Инновационный продукт, утоляющий жажду и голод. "
                "Революционное решение для управления потребностями организма."
            ),
        },
    ),
]


def expected_rect(row: dict[str, str], scale: float = 1.0) -> Rect:
    width = int(row["block_width"])
    height = int(row["block_height"])
    crop_path = FIXTURE_DIR / row["crop_image"]
    crop = cv2.imread(str(crop_path)) if crop_path.exists() else None
    if crop is not None:
        height, width = crop.shape[:2]
    return Rect(
        round(int(row["block_x"]) * scale),
        round(int(row["block_y"]) * scale),
        round(width * scale),
        round(height * scale),
    )


def assert_rect_close(actual: Rect, expected: Rect, tolerance: int = COORDINATE_TOLERANCE) -> None:
    assert abs(actual.x - expected.x) <= tolerance
    assert abs(actual.y - expected.y) <= tolerance
    assert abs(actual.width - expected.width) <= tolerance
    assert abs(actual.height - expected.height) <= tolerance


@pytest.mark.parametrize("row", geometry_rows(), ids=lambda row: row["source_image"])
def test_item_info_detector_matches_manual_metadata(row: dict[str, str]):
    frame = cv2.imread(str(FIXTURE_DIR / "images" / row["source_image"]))
    assert frame is not None

    item_info = ItemInfoDetector().detect(frame, read_text=False)

    assert item_info is not None
    assert_rect_close(item_info.rect, expected_rect(row))


@pytest.mark.parametrize("row", geometry_rows(), ids=lambda row: row["source_image"])
def test_item_info_crop_matches_detected_rect_size(row: dict[str, str]):
    frame = cv2.imread(str(FIXTURE_DIR / "images" / row["source_image"]))
    assert frame is not None

    rect = expected_rect(row)
    crop = ItemInfoDetector().crop(frame, rect)
    assert crop is not None
    assert abs(crop.shape[1] - rect.width) <= COORDINATE_TOLERANCE
    assert abs(crop.shape[0] - rect.height) <= COORDINATE_TOLERANCE


@pytest.mark.parametrize("row", metadata_rows(), ids=lambda row: row["source_image"])
def test_item_info_parser_matches_metadata(row: dict[str, str]):
    parsed = ItemInfoParser.parse(row["raw_text"])

    assert parsed.title == row["title"]
    assert parsed.item_name == row["item_name"]
    assert parsed.weight == row["weight_kg"]
    assert parsed.description == row["description"]
    assert parsed.satiety_change == row["satiety_change"]
    assert parsed.thirst_change == row["thirst_change"]
    assert parsed.condition_percent == row["condition_percent"]
    assert parsed.poison_chance == row["poison_chance"]
    assert " | ".join(effect.name for effect in parsed.effects) == row["effects"]
    assert " | ".join(effect.duration for effect in parsed.effects if effect.duration) == row["effect_durations"]
    assert " | ".join(effect.description for effect in parsed.effects if effect.description) == row["effect_descriptions"]
    assert " | ".join(parsed.parameter_modifications) == row["parameter_modifications"]
    assert parsed.strength == row["strength"]
    assert parsed.gender == row["gender"]



def test_item_info_title_keeps_greek_beta_letter():
    assert ItemInfoDetector._clean_title("β-Блокатор") == "β-Блокатор"


def test_item_info_parser_keeps_beta_in_title():
    parsed = ItemInfoParser.parse("β-Блокатор\n0.1 кг")

    assert parsed.title == "β-Блокатор"
    assert parsed.weight == "0.1"


def test_item_info_title_keeps_allowed_pibwasser_beta():
    assert ItemInfoDetector._clean_title("Пиво Piβwasser") == "Пиво Piβwasser"



@pytest.mark.parametrize("row", ocr_crop_rows(), ids=lambda row: row["source_image"])
def test_item_info_detector_reads_crop_metadata(row: dict[str, str]):
    crop = cv2.imread(str(FIXTURE_DIR / row["crop_image"]))
    assert crop is not None

    title, weight, text = ItemInfoDetector().read_text(crop, Rect(0, 0, crop.shape[1], crop.shape[0]))
    parsed = ItemInfoParser.parse(text)

    assert (parsed.title or title) == row["title"]
    assert (parsed.weight or weight) == row["weight_kg"]
    assert parsed.satiety_change == row["satiety_change"]
    assert parsed.thirst_change == row["thirst_change"]
    assert parsed.condition_percent == row["condition_percent"]
    assert parsed.poison_chance == row["poison_chance"]
    assert " | ".join(parsed.parameter_modifications) == row["parameter_modifications"]
    assert parsed.strength == row["strength"]
    assert parsed.gender == row["gender"]


@pytest.mark.parametrize("source_image, expected", OCR_SCREENSHOT_EXPECTATIONS, ids=[item[0] for item in OCR_SCREENSHOT_EXPECTATIONS])
def test_item_info_detector_reads_problematic_screenshot_ocr(source_image: str, expected: dict[str, object]):
    frame = cv2.imread(str(FIXTURE_DIR / "images" / source_image))
    assert frame is not None

    item_info = ItemInfoDetector().detect(frame, read_text=True)

    assert item_info is not None
    assert item_info.title == expected["title"]
    assert item_info.weight == expected["weight"]
    assert item_info.satiety_change == expected["satiety_change"]
    assert item_info.thirst_change == expected["thirst_change"]
    assert item_info.condition_percent == expected["condition_percent"]
    assert item_info.poison_chance == expected["poison_chance"]
    assert item_info.effect_names == expected["effects"]
    assert item_info.effect_durations == expected["effect_durations"]
    assert item_info.effect_descriptions == expected["effect_descriptions"]
    assert item_info.parameter_modifications == expected["parameter_modifications"]
    assert item_info.description == expected["description"]


@pytest.mark.parametrize("row", low_res_rows(), ids=lambda row: row["source_image"])
def test_item_info_detector_keeps_rect_on_downscaled_screenshots(row: dict[str, str]):
    frame = cv2.imread(str(FIXTURE_DIR / "images" / row["source_image"]))
    assert frame is not None
    small_frame = cv2.resize(frame, None, fx=LOW_RES_SCALE, fy=LOW_RES_SCALE, interpolation=cv2.INTER_AREA)

    item_info = ItemInfoDetector().detect(small_frame, read_text=False)

    assert item_info is not None
    assert_rect_close(item_info.rect, expected_rect(row, LOW_RES_SCALE), tolerance=36)


@pytest.mark.parametrize("row", status_rows(), ids=lambda row: row["source_image"])
def test_player_status_detector_matches_inventory_bars(row: dict[str, str]):
    frame = cv2.imread(str(FIXTURE_DIR / "images" / row["source_image"]))
    assert frame is not None

    status = PlayerStatusDetector().detect(frame)

    assert status is not None
    assert status.food == int(row["food"])
    assert status.water == int(row["water"])
    assert status.health == int(row["health"])


@pytest.mark.parametrize("row", status_rows(), ids=lambda row: row["source_image"])
def test_player_status_detector_matches_downscaled_inventory_bars(row: dict[str, str]):
    frame = cv2.imread(str(FIXTURE_DIR / "images" / row["source_image"]))
    assert frame is not None
    small_frame = cv2.resize(frame, None, fx=LOW_RES_SCALE, fy=LOW_RES_SCALE, interpolation=cv2.INTER_AREA)

    status = PlayerStatusDetector().detect(small_frame)

    assert status is not None
    assert status.food == int(row["food"])
    assert status.water == int(row["water"])
    assert status.health == int(row["health"])


def test_player_status_detector_infers_zero_middle_bar():
    frame = np.zeros((1080, 1920, 3), dtype=np.uint8)
    cv2.rectangle(frame, (812, 494), (956, 497), (0, 185, 255), -1)
    cv2.rectangle(frame, (812, 548), (1019, 551), (40, 40, 255), -1)

    status = PlayerStatusDetector().detect(frame)

    assert status is not None
    assert status.food == 50
    assert status.water == 0
    assert status.health == 72


def test_player_status_memory_parser_reads_webengine_weight_strings():
    data = (
        b"\x00weight__text-current \x00"
        b"\x04\x00\x00\x005.72I&"
        b"https://cdn.majestic-files.net/public/master/static/img/inventory/indicators/v2/health.svg\x00"
        b"https://cdn.majestic-files.net/public/master/static/img/inventory/indicators/v2/water.svg\x00"
        b"https://cdn.majestic-files.net/public/master/static/img/inventory/indicators/v2/hunger.svg\x00"
        b" \xa0/ 20\x00\x05\x00\x00\x0011.74\x00"
        b" \xa0/ 40 \x00"
    )

    status = PlayerStatusMemoryDetector._parse_webengine_window(data)

    assert status is not None
    assert status.inventory_weight == 5.72
    assert status.inventory_weight_max == 40.0
    assert status.backpack_weight == 11.74
    assert status.backpack_weight_max == 20.0


def test_player_status_memory_parser_reads_webengine_indicator_records():
    def record(value: int, icon_ptr: int, tail_ptr: int, extra_ptr: int = 0x01F5FE29, final_ptr: int = 0x28D9) -> bytes:
        return struct.pack(
            "<13I",
            value << 1,
            0x00EF5FF1,
            0x775,
            0x775,
            0x047793A1,
            0x041DE895,
            0xA1,
            icon_ptr,
            0x775,
            0x775,
            tail_ptr,
            extra_ptr,
            final_ptr,
        )

    data = (
        b"https://cdn.majestic-files.net/public/master/static/img/inventory/indicators/v2/health.svg\x00"
        + b"\x00" * 32
        + record(83, 0x064142C5, 0x0476D5E5)
        + record(63, 0x064142C5, 0x0476D5E5)
        + record(32, 0x058B2815, 0x0477938D, 0x028F0A59, 0x041DE7B5)
    )

    status = PlayerStatusMemoryDetector._parse_webengine_window(data)

    assert status is not None
    assert status.food == 83
    assert status.water == 63
    assert status.health == 32
