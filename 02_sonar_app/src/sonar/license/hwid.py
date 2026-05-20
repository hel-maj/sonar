from __future__ import annotations

import ctypes
import hashlib
import os
import platform


def machine_fingerprint() -> str:
    """Return a stable, non-reversible fingerprint for the current machine."""

    stable_parts = [
        platform.system(),
        platform.machine(),
        _windows_machine_guid(),
        _windows_system_volume_serial(),
    ]
    raw = "|".join(part for part in stable_parts if part)
    if not raw:
        raw = os.environ.get("COMPUTERNAME") or os.environ.get("HOSTNAME") or platform.node()
    return hashlib.sha256(raw.encode("utf-8", errors="ignore")).hexdigest()


def _windows_machine_guid() -> str:
    if platform.system().lower() != "windows":
        return ""
    try:
        import winreg

        with winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE, r"SOFTWARE\Microsoft\Cryptography") as key:
            value, _ = winreg.QueryValueEx(key, "MachineGuid")
        return str(value)
    except OSError:
        return ""


def _windows_system_volume_serial() -> str:
    if platform.system().lower() != "windows":
        return ""
    serial = ctypes.c_ulong()
    try:
        ctypes.windll.kernel32.GetVolumeInformationW(  # type: ignore[attr-defined]
            "C:\\",
            None,
            0,
            ctypes.byref(serial),
            None,
            None,
            None,
            0,
        )
    except OSError:
        return ""
    return str(serial.value) if serial.value else ""
