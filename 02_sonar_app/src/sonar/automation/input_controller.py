from __future__ import annotations

import ctypes
import time
from dataclasses import dataclass
from typing import Callable


PUL = ctypes.POINTER(ctypes.c_ulong)
INPUT_KEYBOARD = 1
INPUT_MOUSE = 0
KEYEVENTF_KEYUP = 0x0002
KEYEVENTF_SCANCODE = 0x0008
MOUSEEVENTF_LEFTDOWN = 0x0002
MOUSEEVENTF_LEFTUP = 0x0004
MOUSEEVENTF_RIGHTDOWN = 0x0008
MOUSEEVENTF_RIGHTUP = 0x0010

SCAN_CODES = {
    "esc": 0x01,
    "escape": 0x01,
    "1": 0x02,
    "2": 0x03,
    "3": 0x04,
    "4": 0x05,
    "5": 0x06,
    "q": 0x10,
    "w": 0x11,
    "e": 0x12,
    "a": 0x1E,
    "s": 0x1F,
    "d": 0x20,
    "i": 0x17,
    "space": 0x39,
    "shift": 0x2A,
    "left_shift": 0x2A,
}


class KeyBdInput(ctypes.Structure):
    _fields_ = [
        ("wVk", ctypes.c_ushort),
        ("wScan", ctypes.c_ushort),
        ("dwFlags", ctypes.c_ulong),
        ("time", ctypes.c_ulong),
        ("dwExtraInfo", PUL),
    ]


class MouseInput(ctypes.Structure):
    _fields_ = [
        ("dx", ctypes.c_long),
        ("dy", ctypes.c_long),
        ("mouseData", ctypes.c_ulong),
        ("dwFlags", ctypes.c_ulong),
        ("time", ctypes.c_ulong),
        ("dwExtraInfo", PUL),
    ]


class HardwareInput(ctypes.Structure):
    _fields_ = [("uMsg", ctypes.c_ulong), ("wParamL", ctypes.c_short), ("wParamH", ctypes.c_ushort)]


class InputUnion(ctypes.Union):
    _fields_ = [("ki", KeyBdInput), ("mi", MouseInput), ("hi", HardwareInput)]


class Input(ctypes.Structure):
    _fields_ = [("type", ctypes.c_ulong), ("union", InputUnion)]


@dataclass(slots=True)
class InputController:
    dry_run: bool = False
    pause_after_action: float = 0.05
    key_press_duration: float = 0.06
    input_allowed_callback: Callable[[], bool] | None = None

    def is_input_allowed(self) -> bool:
        return self.input_allowed_callback is None or bool(self.input_allowed_callback())

    def click(self, x: int, y: int, button: str = "left") -> bool:
        if not self.dry_run and not self.is_input_allowed():
            return False
        if not self.dry_run:
            ctypes.windll.user32.SetCursorPos(int(x), int(y))
            down, up = self._mouse_flags(button)
            self._send_mouse(down)
            time.sleep(0.035)
            self._send_mouse(up)
        time.sleep(self.pause_after_action)
        return True

    def double_click(self, x: int, y: int) -> bool:
        if not self.click(x, y):
            return False
        time.sleep(0.05)
        return self.click(x, y)

    def move_to(self, x: int, y: int) -> bool:
        if not self.dry_run and not self.is_input_allowed():
            return False
        if not self.dry_run:
            ctypes.windll.user32.SetCursorPos(int(x), int(y))
        time.sleep(self.pause_after_action)
        return True

    def press_key(self, key: str) -> bool:
        if not self.key_down(key):
            return False
        time.sleep(self.key_press_duration)
        self.key_up(key)
        time.sleep(self.pause_after_action)
        return True

    def key_down(self, key: str) -> bool:
        if not self.dry_run and not self.is_input_allowed():
            return False
        if not self.dry_run:
            self._send_key(key, key_up=False)
        return True

    def key_up(self, key: str) -> bool:
        if not self.dry_run:
            self._send_key(key, key_up=True)
        return True

    def release_all_keys(self, keys: tuple[str, ...] = ("w", "a", "s", "d", "e", "q", "shift", "space")) -> None:
        for key in keys:
            self.key_up(key)

    @staticmethod
    def sleep(seconds: float) -> None:
        time.sleep(seconds)

    def _send_key(self, key: str, key_up: bool) -> None:
        scan = SCAN_CODES.get(key.lower())
        if scan is None:
            raise ValueError(f"Unsupported key: {key}")
        flags = KEYEVENTF_SCANCODE | (KEYEVENTF_KEYUP if key_up else 0)
        extra = ctypes.c_ulong(0)
        event = Input(
            type=INPUT_KEYBOARD,
            union=InputUnion(ki=KeyBdInput(0, scan, flags, 0, ctypes.pointer(extra))),
        )
        sent = ctypes.windll.user32.SendInput(1, ctypes.byref(event), ctypes.sizeof(event))
        if sent != 1:
            raise ctypes.WinError()

    @staticmethod
    def _send_mouse(flags: int) -> None:
        extra = ctypes.c_ulong(0)
        event = Input(
            type=INPUT_MOUSE,
            union=InputUnion(mi=MouseInput(0, 0, 0, flags, 0, ctypes.pointer(extra))),
        )
        sent = ctypes.windll.user32.SendInput(1, ctypes.byref(event), ctypes.sizeof(event))
        if sent != 1:
            raise ctypes.WinError()

    @staticmethod
    def _mouse_flags(button: str) -> tuple[int, int]:
        if button == "left":
            return MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP
        if button == "right":
            return MOUSEEVENTF_RIGHTDOWN, MOUSEEVENTF_RIGHTUP
        raise ValueError(f"Unsupported mouse button: {button}")
