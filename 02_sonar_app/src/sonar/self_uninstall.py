from __future__ import annotations

import os
import shutil
import subprocess
import sys
import tempfile
import uuid
from dataclasses import dataclass
from pathlib import Path

from sonar.paths import APP_DIR, HELPER_DIR, IS_FROZEN, PROJECT_DIR


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
    if not availability.enabled or availability.executable_path is None:
        raise RuntimeError(availability.reason)

    script_path = create_uninstall_script(
        availability.target_dir,
        executable_path=availability.executable_path,
        pid=pid or os.getpid(),
    )

    creationflags = 0
    if os.name == "nt":
        creationflags = subprocess.CREATE_NEW_PROCESS_GROUP | subprocess.CREATE_NO_WINDOW

    subprocess.Popen(
        ["cmd.exe", "/c", str(script_path)],
        cwd=str(script_path.parent.parent),
        creationflags=creationflags,
        close_fds=True,
    )
    return script_path


def create_uninstall_script(target_dir: Path, *, pid: int, executable_path: Path | None = None) -> Path:
    target_dir = target_dir.resolve()
    executable_path = executable_path.resolve() if executable_path is not None else _find_executable_in_dir(target_dir)
    if executable_path is None:
        raise FileNotFoundError("Не найден exe для удаления.")

    uninstall_id = uuid.uuid4().hex
    runtime_dir = Path(tempfile.gettempdir()) / f"uninstall_{uninstall_id}"
    script_path = runtime_dir / "uninstall.cmd"

    ps1_path, sdelete_path = _copy_uninstall_helpers(runtime_dir)

    target = _batch_literal(target_dir)
    executable = _batch_literal(executable_path)
    ps1_full = _batch_literal(ps1_path)
    sdelete_full = _batch_literal(sdelete_path)
    runtime = _batch_literal(runtime_dir)

    script = f"""@echo off
chcp 65001 >nul
setlocal EnableDelayedExpansion

set "TARGET={target}"
set "EXE={executable}"
set "PID={int(pid)}"
set "PS1={ps1_full}"
set "SDELETE={sdelete_full}"
set "RUNTIME={runtime}"

powershell -NoProfile -ExecutionPolicy Bypass -Command "try {{ Wait-Process -Id %PID% -Timeout 15 -ErrorAction SilentlyContinue }} catch {{}}" >nul 2>&1

echo [SECURE UNINSTALL] Starting targeted wipe...

powershell -NoProfile -ExecutionPolicy Bypass -File "%PS1%" "%TARGET%" "%SDELETE%" "%EXE%" >nul 2>&1

cd /d "%TEMP%" >nul 2>&1
del "%~f0" /f /q >nul 2>&1
del "%PS1%" /f /q >nul 2>&1
del "%SDELETE%" /f /q >nul 2>&1
rmdir "%RUNTIME%" /s /q >nul 2>&1

exit
"""
    script_path.write_text(script, encoding="utf-8")
    return script_path


def _copy_uninstall_helpers(runtime_dir: Path) -> tuple[Path, Path]:
    source_ps1 = HELPER_DIR / "secure_wipe.ps1"
    source_sdelete = HELPER_DIR / "sdelete.exe"
    if not source_ps1.exists():
        raise FileNotFoundError(f"Не найден файл удаления: {source_ps1}")
    if not source_sdelete.exists():
        raise FileNotFoundError(f"Не найден sdelete.exe: {source_sdelete}")

    runtime_dir.mkdir(parents=True, exist_ok=True)
    temp_ps1 = runtime_dir / "wipe.ps1"
    temp_sdelete = runtime_dir / "erase.exe"
    shutil.copy2(source_ps1, temp_ps1)
    shutil.copy2(source_sdelete, temp_sdelete)
    return temp_ps1, temp_sdelete


def _find_executable_in_dir(target_dir: Path) -> Path | None:
    executables = [path for path in target_dir.glob("*.exe") if path.name.lower() not in PYTHON_EXECUTABLE_NAMES]
    if len(executables) != 1:
        return None
    return executables[0].resolve()


def _target_safety_error(target_dir: Path, *, project_dir: Path | None) -> str:
    if target_dir.parent == target_dir or str(target_dir) == target_dir.anchor:
        return "Нельзя удалить корень диска."
    if project_dir is not None and target_dir == project_dir and _looks_like_source_tree(target_dir):
        return "Папка похожа на папку исходного кода."
    if _looks_like_source_tree(target_dir):
        return "Папка похожа на папку исходного кода."
    return ""


def _looks_like_source_tree(path: Path) -> bool:
    return (
        ((path / "pyproject.toml").exists() and (path / "src").exists())
        or ((path / "src" / "sonar").exists() and (path / "tests").exists())
    )


def _batch_literal(path: Path) -> str:
    return str(path).replace("%", "%%")
