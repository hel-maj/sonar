from __future__ import annotations

import os
import sys
from pathlib import Path


def _is_frozen() -> bool:
    executable_name = Path(sys.executable).name.lower()
    is_python_executable = executable_name in {"python.exe", "pythonw.exe", "python", "pythonw"} or executable_name.startswith("python")
    return bool(getattr(sys, "frozen", False) or "__compiled__" in globals() or not is_python_executable)


def _frozen_app_dir() -> Path:
    argv0 = Path(sys.argv[0]).resolve() if sys.argv and sys.argv[0] else None
    if argv0 is not None:
        executable_name = argv0.name.lower()
        is_python_executable = executable_name in {"python.exe", "pythonw.exe", "python", "pythonw"} or executable_name.startswith("python")
        if not is_python_executable:
            return argv0.parent
    return Path(sys.executable).resolve().parent


def _frozen_payload_dir() -> Path:
    return PACKAGE_DIR.parent


IS_FROZEN = _is_frozen()
PACKAGE_DIR = Path(__file__).resolve().parent
PROJECT_DIR = PACKAGE_DIR.parents[2]
APP_DIR = _frozen_app_dir() if IS_FROZEN else PROJECT_DIR
PAYLOAD_DATA_DIR = _frozen_payload_dir() / ".payload" if IS_FROZEN else PACKAGE_DIR
RESOURCE_DIR = PAYLOAD_DATA_DIR / "resources"
HELPER_DIR = PAYLOAD_DATA_DIR / "helpers" if IS_FROZEN else PACKAGE_DIR
FISHING_RESOURCE_DIR = RESOURCE_DIR / "fishing"
CONFIG_DIR = APP_DIR / "config"
LOG_DIR = APP_DIR / "logs"
LOGS_ENABLED = not IS_FROZEN or os.environ.get("SONAR_ENABLE_RELEASE_LOGS") == "1"


def ensure_runtime_dirs() -> None:
    CONFIG_DIR.mkdir(parents=True, exist_ok=True)
    if LOGS_ENABLED:
        LOG_DIR.mkdir(parents=True, exist_ok=True)
