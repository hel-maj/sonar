from __future__ import annotations

from dataclasses import dataclass

import numpy as np

from sonar.fishing.constants import PROCESS_NAME


@dataclass(slots=True)
class WindowInfo:
    hwnd: int
    width: int
    height: int


class WindowCapture:
    def __init__(self, process_name: str = PROCESS_NAME) -> None:
        self.process_name = process_name
        self.hwnd: int | None = None

    def find_window_by_process(self) -> bool:
        import psutil
        import win32gui
        import win32process

        pids = {proc.pid for proc in psutil.process_iter(["name"]) if (proc.info.get("name") or "").lower() == self.process_name.lower()}
        hwnds: list[int] = []

        def callback(hwnd: int, _: object) -> bool:
            if not win32gui.IsWindowVisible(hwnd):
                return True
            _, pid = win32process.GetWindowThreadProcessId(hwnd)
            if pid in pids:
                hwnds.append(hwnd)
            return True

        win32gui.EnumWindows(callback, None)
        self.hwnd = hwnds[0] if hwnds else None
        return self.hwnd is not None

    def is_window_available(self) -> bool:
        return self.find_window_by_process()

    def get_window_size(self) -> tuple[int, int]:
        import win32gui

        hwnd = self._require_window()
        try:
            left, top, right, bottom = win32gui.GetClientRect(hwnd)
        except Exception as exc:
            self.hwnd = None
            raise RuntimeError("Окно игры недоступно") from exc
        return right - left, bottom - top

    def client_to_screen(self, x: int, y: int) -> tuple[int, int]:
        import win32gui

        hwnd = self._require_window()
        try:
            return win32gui.ClientToScreen(hwnd, (int(x), int(y)))
        except Exception as exc:
            self.hwnd = None
            raise RuntimeError("Окно игры недоступно") from exc

    def capture(self) -> np.ndarray:
        import win32gui
        import win32ui
        import win32con

        hwnd = self._require_window()
        try:
            left, top, right, bottom = win32gui.GetClientRect(hwnd)
            screen_left, screen_top = win32gui.ClientToScreen(hwnd, (left, top))
        except Exception as exc:
            self.hwnd = None
            raise RuntimeError("Окно игры недоступно") from exc
        width = right - left
        height = bottom - top
        if width <= 0 or height <= 0:
            return np.zeros((0, 0, 3), dtype=np.uint8)

        screen_dc = win32gui.GetDC(0)
        src_dc = win32ui.CreateDCFromHandle(screen_dc)
        mem_dc = src_dc.CreateCompatibleDC()
        bitmap = win32ui.CreateBitmap()
        bitmap.CreateCompatibleBitmap(src_dc, width, height)
        old_bitmap = mem_dc.SelectObject(bitmap)
        try:
            mem_dc.BitBlt((0, 0), (width, height), src_dc, (screen_left, screen_top), win32con.SRCCOPY)
            bits = bitmap.GetBitmapBits(True)
            frame = np.frombuffer(bits, dtype=np.uint8).reshape((height, width, 4))
            return frame[:, :, :3].copy()
        finally:
            mem_dc.SelectObject(old_bitmap)
            win32gui.DeleteObject(bitmap.GetHandle())
            mem_dc.DeleteDC()
            src_dc.DeleteDC()
            win32gui.ReleaseDC(0, screen_dc)

    def _require_window(self) -> int:
        if self.hwnd is not None and self._is_valid_window(self.hwnd):
            return self.hwnd
        self.hwnd = None
        if not self.find_window_by_process():
            raise RuntimeError(f"Window for process {self.process_name!r} was not found")
        assert self.hwnd is not None
        return self.hwnd

    @staticmethod
    def _is_valid_window(hwnd: int) -> bool:
        import win32gui

        try:
            return bool(hwnd and win32gui.IsWindow(hwnd) and win32gui.IsWindowVisible(hwnd))
        except Exception:
            return False
