from __future__ import annotations

import csv
from pathlib import Path

import cv2
import pytest

from sonar.fishing.item_info import ItemInfoDetector, ItemInfoParser
from sonar.vision.geometry import Rect


FIXTURE_DIR = Path(__file__).parent / "fixtures" / "inventory_item_info"
METADATA_PATH = FIXTURE_DIR / "metadata.csv"
COORDINATE_TOLERANCE = 22
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


def expected_rect(row: dict[str, str], scale: float = 1.0) -> Rect:
    return Rect(
        round(int(row["block_x"]) * scale),
        round(int(row["block_y"]) * scale),
        round(int(row["block_width"]) * scale),
        round(int(row["block_height"]) * scale),
    )


def assert_rect_close(actual: Rect, expected: Rect, tolerance: int = COORDINATE_TOLERANCE) -> None:
    assert abs(actual.x - expected.x) <= tolerance
    assert abs(actual.y - expected.y) <= tolerance
    assert abs(actual.width - expected.width) <= tolerance
    assert abs(actual.height - expected.height) <= tolerance


@pytest.mark.parametrize("row", metadata_rows(), ids=lambda row: row["source_image"])
def test_item_info_detector_matches_manual_metadata(row: dict[str, str]):
    frame = cv2.imread(str(FIXTURE_DIR / "images" / row["source_image"]))
    assert frame is not None

    item_info = ItemInfoDetector().detect(frame, read_text=False)

    assert item_info is not None
    assert_rect_close(item_info.rect, expected_rect(row))


@pytest.mark.parametrize("row", metadata_rows(), ids=lambda row: row["source_image"])
def test_item_info_crop_matches_detected_rect_size(row: dict[str, str]):
    frame = cv2.imread(str(FIXTURE_DIR / "images" / row["source_image"]))
    assert frame is not None

    crop = ItemInfoDetector().crop(frame, expected_rect(row))
    assert crop is not None
    assert abs(crop.shape[1] - int(row["block_width"])) <= COORDINATE_TOLERANCE
    assert abs(crop.shape[0] - int(row["block_height"])) <= COORDINATE_TOLERANCE


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


@pytest.mark.parametrize("row", low_res_rows(), ids=lambda row: row["source_image"])
def test_item_info_detector_keeps_rect_on_downscaled_screenshots(row: dict[str, str]):
    frame = cv2.imread(str(FIXTURE_DIR / "images" / row["source_image"]))
    assert frame is not None
    small_frame = cv2.resize(frame, None, fx=LOW_RES_SCALE, fy=LOW_RES_SCALE, interpolation=cv2.INTER_AREA)

    item_info = ItemInfoDetector().detect(small_frame, read_text=False)

    assert item_info is not None
    assert_rect_close(item_info.rect, expected_rect(row, LOW_RES_SCALE), tolerance=18)
