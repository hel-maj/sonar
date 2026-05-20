from __future__ import annotations

from pathlib import Path

import cv2
import pytest

from sonar.fishing.tackle_detection import TackleDetector, format_tackle_items


FIXTURES = Path(__file__).parent / "fixtures" / "tackle"


def load_frame(name: str):
    frame = cv2.imread(str(FIXTURES / name))
    assert frame is not None, name
    return frame


def counts_for(name: str) -> list[int]:
    scan = TackleDetector().detect(load_frame(name))
    assert scan.obscured is False
    return [item.count for item in scan.items]


@pytest.mark.parametrize(
    ("fixture", "expected"),
    [
        ("all_except_net_1.jpg", [1, 1, 1298, 6, 6, 0]),
        ("all_except_net_2.jpg", [1, 1, 1298, 6, 6, 0]),
        ("all_except_net_3.jpg", [1, 1, 1298, 6, 6, 0]),
        ("rod_only_1.jpg", [1, 0, 0, 0, 0, 0]),
        ("rod_only_2.jpg", [1, 0, 0, 0, 0, 0]),
        ("rod_only_3.jpg", [1, 0, 0, 0, 0, 0]),
        ("rod_only_4.jpg", [1, 0, 0, 0, 0, 0]),
        ("no_hook_1.jpg", [1, 1, 1298, 0, 6, 0]),
        ("no_hook_2.jpg", [1, 1, 1298, 0, 6, 0]),
        ("no_line_bait_net.jpg", [1, 1, 0, 6, 0, 0]),
        ("no_bait_net.jpg", [1, 1, 1298, 6, 0, 0]),
        ("counts_hook1_bait6.jpg", [1, 1, 1298, 1, 6, 0]),
        ("counts_hook3_bait1.jpg", [1, 1, 1298, 3, 1, 0]),
        ("counts_line998_hook0_bait1.jpg", [1, 1, 998, 0, 1, 0]),
        ("counts_line900_hook0_bait1.jpg", [1, 1, 900, 0, 1, 0]),
        ("counts_line11_hook0_bait1.jpg", [1, 1, 11, 0, 1, 0]),
        ("counts_line848_hook3_bait4.jpg", [1, 1, 848, 3, 4, 0]),
        ("counts_reel0_line848_hook3_bait4.jpg", [1, 0, 848, 3, 4, 0]),
    ],
)
def test_tackle_counts_are_read_from_slot_color_and_quantity_digits(fixture, expected):
    assert counts_for(fixture) == expected


@pytest.mark.parametrize(
    "fixture",
    [
        "obscured_1.jpg",
        "obscured_2.jpg",
        "obscured_3.jpg",
        "obscured_4.jpg",
        "obscured_5.jpg",
        "obscured_6.jpg",
    ],
)
def test_tackle_scan_detects_bottom_notifications_covering_slots(fixture):
    assert TackleDetector().detect(load_frame(fixture)).obscured is True


def test_tackle_slot_layout_scales_with_resolution():
    rects = TackleDetector.slot_rects(2560, 1440)

    assert len(rects) == 6
    assert rects[0].width == 92
    assert rects[1].x - rects[0].x == 107
    assert rects[0].y == 1245


def test_format_tackle_items_lists_all_slots():
    scan = TackleDetector().detect(load_frame("counts_hook3_bait1.jpg"))

    text = format_tackle_items(scan.items)

    assert "Удочка: 1шт." in text
    assert "Крючки/поводки: 3шт." in text
    assert "Подсак: 0шт." in text
