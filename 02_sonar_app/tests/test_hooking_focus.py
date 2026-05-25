from __future__ import annotations

import time

import numpy as np

from sonar.fishing.hooking import TemplateMonitor
from sonar.vision.geometry import Rect


class InputRecorder:
    def __init__(self, calls: list[str]) -> None:
        self.calls = calls

    def press_key(self, key: str) -> bool:
        self.calls.append(key)
        return True


def test_hooking_returns_focus_before_space_press():
    calls: list[str] = []
    monitor = TemplateMonitor.__new__(TemplateMonitor)
    monitor.last_frame_time = time.time()
    monitor.pause_until = 0.0
    monitor.bubles_template = np.zeros((1, 1, 3), dtype=np.uint8)
    monitor.roi2 = Rect(0, 0, 10, 10)
    monitor.input_controller = InputRecorder(calls)
    monitor.focus_callback = lambda: calls.append("focus") or True
    monitor.match_red_template = lambda frame: (0.9, True)
    monitor.match_template = lambda frame, template, roi: (0.0, False)

    result = TemplateMonitor.check_and_act(monitor, np.zeros((10, 10, 3), dtype=np.uint8))

    assert result.pressed is True
    assert calls == ["focus", "space"]
