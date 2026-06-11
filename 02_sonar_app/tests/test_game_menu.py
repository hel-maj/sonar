from __future__ import annotations

import cv2
import numpy as np

from sonar.fishing.game_menu import GameMenuDetector
from sonar.paths import FISHING_RESOURCE_DIR


def test_game_menu_detector_finds_bottom_right_menu_text():
    frame = np.zeros((1080, 1920, 3), dtype=np.uint8)
    template = cv2.imread(str(FISHING_RESOURCE_DIR / "menu" / "menu_hide.png"))
    assert template is not None
    h, w = template.shape[:2]
    x, y = 1540, 940
    frame[y : y + h, x : x + w] = template

    match = GameMenuDetector().detect(frame)

    assert match is not None
    assert match.name == "menu_hide"
    assert match.confidence > 0.9


def test_game_menu_detector_ignores_top_left_same_text():
    frame = np.zeros((1080, 1920, 3), dtype=np.uint8)
    template = cv2.imread(str(FISHING_RESOURCE_DIR / "menu" / "menu_back.png"))
    assert template is not None
    h, w = template.shape[:2]
    frame[40 : 40 + h, 40 : 40 + w] = template

    assert GameMenuDetector().detect(frame) is None
