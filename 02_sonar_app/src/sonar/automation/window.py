from __future__ import annotations


class WindowActivator:
    def __init__(self, process_name: str = "gta5.exe") -> None:
        self.process_name = process_name

    def activate_window(self) -> bool:
        import psutil
        import win32api
        import win32con
        import win32gui
        import win32process

        pids = {proc.pid for proc in psutil.process_iter(["name"]) if (proc.info.get("name") or "").lower() == self.process_name.lower()}
        target_hwnd: int | None = None

        def callback(hwnd: int, _: object) -> bool:
            nonlocal target_hwnd
            if target_hwnd is not None or not win32gui.IsWindowVisible(hwnd):
                return True
            _, pid = win32process.GetWindowThreadProcessId(hwnd)
            if pid in pids:
                target_hwnd = hwnd
            return True

        win32gui.EnumWindows(callback, None)
        if target_hwnd is None:
            return False
        try:
            if win32gui.IsIconic(target_hwnd):
                win32gui.ShowWindow(target_hwnd, win32con.SW_RESTORE)
            foreground = win32gui.GetForegroundWindow()
            current_thread = win32api.GetCurrentThreadId()
            target_thread, _ = win32process.GetWindowThreadProcessId(target_hwnd)
            foreground_thread, _ = win32process.GetWindowThreadProcessId(foreground)
            attached_target = False
            attached_foreground = False
            try:
                attached_target = bool(win32process.AttachThreadInput(current_thread, target_thread, True))
                if foreground_thread != target_thread:
                    attached_foreground = bool(win32process.AttachThreadInput(current_thread, foreground_thread, True))
                win32gui.BringWindowToTop(target_hwnd)
                win32gui.SetForegroundWindow(target_hwnd)
            finally:
                if attached_foreground:
                    win32process.AttachThreadInput(current_thread, foreground_thread, False)
                if attached_target:
                    win32process.AttachThreadInput(current_thread, target_thread, False)
            return win32gui.GetForegroundWindow() == target_hwnd
        except Exception:
            try:
                win32gui.SetForegroundWindow(target_hwnd)
                return win32gui.GetForegroundWindow() == target_hwnd
            except Exception:
                return False

    def force_activate_gta5(self) -> bool:
        return self.activate_window()
