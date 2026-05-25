from __future__ import annotations

import csv
from pathlib import Path

import cv2
import pytest

from sonar.fishing.catch_screen import CatchScreenDetector
from sonar.fishing.fish_names import fish_id_from_display
from sonar.paths import FISHING_RESOURCE_DIR


FIXTURE = Path(__file__).parent / "fixtures" / "catch_marlin_1920x1080.jpg"
GAMEPLAY_FIXTURES = Path(__file__).parent / "fixtures" / "gameplay"
DEBUG_CATCH_FIXTURES = Path(__file__).parent / "fixtures" / "debug_catches"
ALL_CATCHES_FIXTURES = DEBUG_CATCH_FIXTURES / "all_caught_fish_session_screenshots"


def _load_fixture():
    frame = cv2.imread(str(FIXTURE))
    assert frame is not None, f"Fixture is not readable: {FIXTURE}"
    return frame


def _load_gameplay_fixture(name: str):
    path = GAMEPLAY_FIXTURES / name
    frame = cv2.imread(str(path))
    assert frame is not None, f"Fixture is not readable: {path}"
    return frame


def _debug_catch_rows(folder: str):
    csv_path = DEBUG_CATCH_FIXTURES / folder / "metadata.csv"
    with csv_path.open("r", encoding="utf-8-sig", newline="") as file:
        for row in csv.DictReader(file):
            yield folder, row


def _parse_expected_kg(value: str | None) -> float | None:
    if not value:
        return None
    return float(value.replace(",", "."))


@pytest.mark.parametrize(
    ("size", "expected_keep", "expected_release"),
    [
        ((1920, 1080), (866, 726), (1034, 726)),
        ((1280, 720), (577, 484), (689, 484)),
        ((2560, 1440), (1155, 968), (1379, 968)),
    ],
)
def test_catch_screen_detects_marlin_weight_and_action_buttons(size, expected_keep, expected_release):
    source = _load_fixture()
    interpolation = cv2.INTER_AREA if size[0] < source.shape[1] else cv2.INTER_CUBIC
    frame = cv2.resize(source, size, interpolation=interpolation)

    result = CatchScreenDetector().detect(frame)

    assert result.visible is True
    assert result.fish_id == "marlin"
    assert result.fish_text == "Марлин"
    assert result.weight_kg == pytest.approx(4.04, abs=0.02)
    assert result.keep_button is not None
    assert result.release_button is not None
    assert (result.keep_button.x, result.keep_button.y) == pytest.approx(expected_keep, abs=10)
    assert (result.release_button.x, result.release_button.y) == pytest.approx(expected_release, abs=10)


def test_catch_screen_crop_contains_center_panel():
    frame = _load_fixture()
    detector = CatchScreenDetector()
    result = detector.detect(frame)

    crop = detector.crop_panel(frame, result)

    assert result.visible is True
    assert result.panel_rect is not None
    assert crop is not None
    assert 360 <= crop.shape[1] <= 520
    assert 420 <= crop.shape[0] <= 560


def test_catch_screen_rejects_buttons_without_fish_content():
    frame = cv2.imread(str(FIXTURE))
    assert frame is not None
    blank = frame.copy()
    blank[:] = 0
    keep = cv2.imread(str(FISHING_RESOURCE_DIR / "result" / "take_btn.png"))
    release = cv2.imread(str(FISHING_RESOURCE_DIR / "result" / "free_btn.png"))
    assert keep is not None and release is not None
    for template, center in ((keep, (866, 726)), (release, (1034, 726))):
        h, w = template.shape[:2]
        x = center[0] - w // 2
        y = center[1] - h // 2
        blank[y : y + h, x : x + w] = template

    result = CatchScreenDetector().detect(blank)

    assert result.visible is False


@pytest.mark.parametrize(
    ("fixture", "fish_id", "fish_text", "weight", "quality", "xp_current", "xp_total", "is_max_level"),
    [
        ("catch_ruster_good_081821.jpg", "ruster", "Рустер", 2.65, "Хороший улов", 10751, None, True),
        ("catch_seriola_record_084122.jpg", "seriola", "Сериола", 3.69, "Рекордный улов", 10752, None, True),
        (
            "catch_record_toxic_okun.png",
            "toksichny_okun",
            "Токсичный окунь",
            1.26,
            "Рекордный улов",
            2903,
            3120,
            False,
        ),
    ],
)
def test_catch_screen_reads_fish_quality_weight_and_xp(
    fixture,
    fish_id,
    fish_text,
    weight,
    quality,
    xp_current,
    xp_total,
    is_max_level,
):
    result = CatchScreenDetector().detect(_load_gameplay_fixture(fixture))

    assert result.visible is True
    assert result.fish_id == fish_id
    assert result.fish_text == fish_text
    assert result.weight_kg == pytest.approx(weight, abs=0.03)
    assert result.quality_text == quality
    assert result.xp_current == xp_current
    assert result.xp_total == xp_total
    assert result.is_max_level is is_max_level
    assert result.keep_button is not None
    assert result.release_button is not None
    assert result.keep_button.x < result.release_button.x
    assert abs(result.keep_button.y - result.release_button.y) < 25


def test_catch_screen_detects_marlin_from_gameplay_fixture():
    result = CatchScreenDetector().detect(_load_gameplay_fixture("no_thirst_catch_marlin_053636.jpg"))

    assert result.visible is True
    assert result.fish_id == "marlin"
    assert result.fish_text == "Марлин"
    assert result.weight_kg == pytest.approx(4.04, abs=0.03)
    assert result.quality_text == "Рекордный улов"
    assert result.xp_current == 10735
    assert result.is_max_level is True


@pytest.mark.parametrize(
    ("fixture", "fish_id", "weight"),
    [
        ("catch_marlin_310_20260519113616.jpg", "marlin", 3.10),
        ("catch_seriola_337_20260519115235.jpg", "seriola", 3.37),
    ],
)
def test_catch_screen_regressions_from_user_screenshots(fixture, fish_id, weight):
    result = CatchScreenDetector().detect(_load_gameplay_fixture(fixture))

    assert result.visible is True
    assert result.fish_id == fish_id
    assert result.weight_kg == pytest.approx(weight, abs=0.02)


@pytest.mark.parametrize(("folder", "row"), list(_debug_catch_rows("unexpected_fish")))
def test_catch_screen_uses_ocr_name_for_debug_unexpected_fish_crops(folder, row):
    frame = cv2.imread(str(DEBUG_CATCH_FIXTURES / folder / row["screenshot"]))
    assert frame is not None
    result = CatchScreenDetector().detect(frame)

    assert result.visible is True
    assert result.fish_id == fish_id_from_display(row["expected_fish_name"])
    expected_kg = _parse_expected_kg(row.get("expected_kg"))
    if expected_kg is not None:
        assert result.weight_kg == pytest.approx(expected_kg, abs=0.03)


@pytest.mark.parametrize(("folder", "row"), list(_debug_catch_rows("over_15kg")))
def test_catch_screen_reads_debug_weight_without_kg_icon_artifacts(folder, row):
    frame = cv2.imread(str(DEBUG_CATCH_FIXTURES / folder / row["screenshot"]))
    assert frame is not None
    expected_kg = _parse_expected_kg(row.get("expected_kg"))
    assert expected_kg is not None

    result = CatchScreenDetector().detect(frame)

    assert result.visible is True
    expected_fish_id = fish_id_from_display(row.get("expected_fish_name"))
    if expected_fish_id is not None:
        assert result.fish_id == expected_fish_id
    assert result.weight_kg == pytest.approx(expected_kg, abs=0.03)


@pytest.mark.parametrize(
    ("fixture", "fish_id", "fish_text", "weight", "quality", "xp"),
    [
        ("1779302278077_all_catches_ruster_2_59.png", "ruster", "Рустер", 2.59, "Хороший улов", 11048),
        ("1779302429075_all_catches_ruster_2_35.png", "ruster", "Рустер", 2.35, "Хороший улов", 11049),
        ("1779302539866_all_catches_ruster_3_06.png", "ruster", "Рустер", 3.06, "Рекордный улов", 11050),
        ("1779502694357_all_catches_ruster_3_00.png", "ruster", "Рустер", 3.00, "Рекордный улов", 11051),
        ("1779585243219_all_catches_roach_vobla_2_38.png", "seriola", "Сериола", 2.38, "Скромный улов", 11121),
        ("1779585618747_all_catches_krasny_gorbyl_2_68.png", "krasny_gorbyl", "Красный горбыль", 2.68, "Хороший улов", 11123),
        ("1779585715265_all_catches_seriola_2_92.png", "seriola", "Сериола", 2.92, "Хороший улов", 11125),
        ("1779585794215_all_catches_krasny_gorbyl_2_94.png", "krasny_gorbyl", "Красный горбыль", 2.94, "Хороший улов", 11126),
        ("1779585898035_all_catches_ruster_1_82.png", "ruster", "Рустер", 1.82, "Скромный улов", 11128),
        ("1779585996353_all_catches_seriola_3_30.png", "seriola", "Сериола", 3.30, "Рекордный улов", 11129),
        ("1779586091729_all_catches_seriola_3_36.png", "seriola", "Сериола", 3.36, "Рекордный улов", 11130),
        ("1779586201862_all_catches_seriola_3_82.png", "seriola", "Сериола", 3.82, "Рекордный улов", 11132),
        ("1779592407360_all_catches_seriola_3_30.png", "seriola", "Сериола", 3.30, "Рекордный улов", 11135),
        ("1779592498547_all_catches_krasny_gorbyl_2_29.png", "ruster", "Рустер", 2.29, "Хороший улов", 11136),
    ],
)
def test_catch_screen_reads_all_user_catch_crops_from_visible_text(fixture, fish_id, fish_text, weight, quality, xp):
    frame = cv2.imread(str(ALL_CATCHES_FIXTURES / fixture))
    assert frame is not None

    result = CatchScreenDetector().detect(frame)

    assert result.visible is True
    assert result.fish_id == fish_id
    assert result.fish_text == fish_text
    assert result.weight_kg == pytest.approx(weight, abs=0.03)
    assert result.quality_text == quality
    assert result.xp_current == xp
    assert result.is_max_level is True


def test_catch_screen_reads_user_full_trophy_screenshot():
    result = CatchScreenDetector().detect(_load_gameplay_fixture("catch_krasny_gorbyl_trophy_799_20260524.png"))

    assert result.visible is True
    assert result.fish_id == "krasny_gorbyl"
    assert result.fish_text == "Красный горбыль"
    assert result.weight_kg == pytest.approx(7.99, abs=0.03)
    assert result.quality_text == "Трофейная"
    assert result.xp_current == 11097
    assert result.is_max_level is True


@pytest.mark.parametrize("scale", [0.67, 0.85, 1.35])
def test_catch_screen_text_identity_survives_scaled_full_frame(scale):
    panel = cv2.imread(str(ALL_CATCHES_FIXTURES / "1779592498547_all_catches_krasny_gorbyl_2_29.png"))
    assert panel is not None
    frame = cv2.imread(str(GAMEPLAY_FIXTURES / "catch_krasny_gorbyl_trophy_799_20260524.png"))
    assert frame is not None
    frame[:] = 0
    y = (frame.shape[0] - panel.shape[0]) // 2
    x = (frame.shape[1] - panel.shape[1]) // 2
    frame[y : y + panel.shape[0], x : x + panel.shape[1]] = panel
    scaled = cv2.resize(frame, None, fx=scale, fy=scale, interpolation=cv2.INTER_CUBIC)

    result = CatchScreenDetector().detect(scaled)

    assert result.visible is True
    assert result.fish_id == "ruster"
    assert result.fish_text == "Рустер"
    assert result.weight_kg == pytest.approx(2.29, abs=0.03)
    assert result.xp_current == 11136


def test_parse_xp_prefers_full_max_level_value_over_coin_artifacts():
    assert CatchScreenDetector._parse_xp("Максимальный уровень 11133 133") == (True, 11133, None)
    assert CatchScreenDetector._parse_xp("Максимальный уровень 133 11133") == (True, 11133, None)
