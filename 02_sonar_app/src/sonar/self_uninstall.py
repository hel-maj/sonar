from __future__ import annotations

import os
import subprocess
import sys
import tempfile
import uuid
from dataclasses import dataclass
from pathlib import Path

from sonar.paths import APP_DIR, IS_FROZEN, PROJECT_DIR


PYTHON_EXECUTABLE_NAMES = {"python.exe", "pythonw.exe", "python", "pythonw"}


@dataclass(frozen=True)
class UninstallAvailability:
    enabled: bool
    target_dir: Path
    executable_path: Path | None
    reason: str = ""


def get_uninstall_availability(
    *,
    argv0: str | os.PathLike[str] | None = None,
    executable: str | os.PathLike[str] | None = None,
    app_dir: str | os.PathLike[str] | None = None,
    is_frozen: bool = IS_FROZEN,
    project_dir: str | os.PathLike[str] | None = PROJECT_DIR,
) -> UninstallAvailability:
    target_dir = Path(app_dir).resolve() if app_dir is not None else APP_DIR.resolve()
    executable_path = resolve_packaged_executable_path(argv0=argv0, executable=executable, is_frozen=is_frozen)
    if executable_path is None:
        return UninstallAvailability(False, target_dir, None, "Доступно только при запуске собранного exe.")
    if executable_path.parent.resolve() != target_dir:
        return UninstallAvailability(False, target_dir, executable_path, "Папка программы не совпадает с папкой exe.")
    safety_error = _target_safety_error(target_dir, project_dir=Path(project_dir).resolve() if project_dir is not None else None)
    if safety_error:
        return UninstallAvailability(False, target_dir, executable_path, safety_error)
    return UninstallAvailability(True, target_dir, executable_path)


def resolve_packaged_executable_path(
    *,
    argv0: str | os.PathLike[str] | None = None,
    executable: str | os.PathLike[str] | None = None,
    is_frozen: bool = IS_FROZEN,
) -> Path | None:
    if not is_frozen:
        return None
    candidates = []
    if argv0 is None:
        argv0 = sys.argv[0] if sys.argv else ""
    if argv0:
        candidates.append(Path(argv0))
    if executable is None:
        executable = sys.executable
    if executable:
        candidates.append(Path(executable))

    for candidate in candidates:
        if candidate.suffix.lower() != ".exe":
            continue
        if candidate.name.lower() in PYTHON_EXECUTABLE_NAMES:
            continue
        return candidate.resolve()
    return None


def schedule_self_uninstall(*, pid: int | None = None) -> Path:
    availability = get_uninstall_availability()
    if not availability.enabled:
        raise RuntimeError(availability.reason)
    script_path = create_uninstall_script(availability.target_dir, pid=pid or os.getpid())
    creationflags = 0
    if os.name == "nt":
        creationflags = subprocess.CREATE_NEW_PROCESS_GROUP | subprocess.DETACHED_PROCESS | subprocess.CREATE_NO_WINDOW
    subprocess.Popen(
        ["cmd.exe", "/c", str(script_path)],
        cwd=str(script_path.parent),
        creationflags=creationflags,
        close_fds=True,
    )
    return script_path


def create_uninstall_script(target_dir: Path, *, pid: int) -> Path:
    script_path = Path(tempfile.gettempdir()) / f"sonar_uninstall_{uuid.uuid4().hex}.cmd"
    target = _batch_literal(target_dir.resolve())
    script = f"""@echo off
chcp 65001 >nul
setlocal
set "TARGET={target}"
set "PID={int(pid)}"
:wait_process
tasklist /FI "PID eq %PID%" 2>nul | find "%PID%" >nul
if not errorlevel 1 (
    timeout /t 1 /nobreak >nul
    goto wait_process
)
attrib -r -s -h "%TARGET%\\*" /s /d >nul 2>nul
for /l %%i in (1,1,30) do (
    if exist "%TARGET%" (
        rmdir /s /q "%TARGET%" >nul 2>nul
        timeout /t 1 /nobreak >nul
    ) else (
        goto done
    )
)
:done
del "%~f0" >nul 2>nul
"""
    script_path.write_text(script, encoding="utf-8")
    return script_path


def _target_safety_error(target_dir: Path, *, project_dir: Path | None) -> str:
    if target_dir.parent == target_dir or str(target_dir) == target_dir.anchor:
        return "Нельзя удалить корень диска."
    if project_dir is not None and target_dir == project_dir:
        return "Папка похожа на папку исходного кода."
    if _looks_like_source_tree(target_dir):
        return "Папка похожа на папку исходного кода."
    return ""


def _looks_like_source_tree(path: Path) -> bool:
    return (
        (path / ".git").exists()
        or ((path / "pyproject.toml").exists() and (path / "src").exists())
        or ((path / "src" / "sonar").exists() and (path / "tests").exists())
    )


def _batch_literal(path: Path) -> str:
    return str(path).replace("%", "%%")
