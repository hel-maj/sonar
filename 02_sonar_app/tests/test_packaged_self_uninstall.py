import importlib.util
import json
import os
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[1]
BUILD_KEY_LENGTH = 11


def test_packaged_exe_self_uninstall_removes_app_artifacts(tmp_path):
    source = os.environ.get("SONAR_SELF_UNINSTALL_EXE")
    if not source:
        pytest.skip("set SONAR_SELF_UNINSTALL_EXE to run packaged exe self-uninstall smoke test")

    source_exe = Path(source)
    assert source_exe.exists(), source_exe

    build_key = _resolve_build_key(source_exe)
    assert build_key, f"could not resolve build key for {source_exe}"
    install_dir = tmp_path / "install"
    install_dir.mkdir()
    exe = install_dir / source_exe.name
    shutil.copy2(source_exe, exe)

    env = os.environ.copy()
    env["SONAR_ALLOW_SELF_UNINSTALL_TEST"] = "1"
    result = subprocess.run(
        [str(exe), "--self-uninstall-smoke-test"],
        cwd=str(install_dir),
        env=env,
        capture_output=True,
        text=True,
        timeout=120,
    )

    try:
        assert result.returncode == 0, result.stdout + result.stderr
        _wait_for_app_artifacts_removed(install_dir, exe.name, timeout_seconds=240)
    finally:
        if build_key:
            _cleanup_free_space_runner(build_key)


def _resolve_build_key(exe: Path) -> str:
    return _build_key_from_sibling_archive(exe) or _build_key_from_build_map(exe) or _extract_build_key_from_exe(exe)


def _build_key_from_sibling_archive(exe: Path) -> str:
    suffix = f"-{exe.stem}.zip"
    matches: list[tuple[float, str]] = []
    for path in exe.parent.iterdir():
        if not path.is_file() or not path.name.endswith(suffix):
            continue
        build_key = path.name[: -len(suffix)]
        if _looks_like_build_key(build_key):
            matches.append((path.stat().st_mtime, build_key))
    if not matches:
        return ""
    return max(matches)[1]


def _build_key_from_build_map(exe: Path) -> str:
    build_map = ROOT.parent / "config" / "sonar_build_keys.json"
    if not build_map.exists():
        return ""
    data = json.loads(build_map.read_text(encoding="utf-8-sig"))
    target = os.path.normcase(os.path.abspath(exe))
    for build_key, value in data.get("build_keys", {}).items():
        if not _looks_like_build_key(build_key) or not isinstance(value, dict):
            continue
        dist_path = value.get("dist_path")
        if dist_path and os.path.normcase(os.path.abspath(str(dist_path))) == target:
            return build_key
    return ""


def _extract_build_key_from_exe(exe: Path) -> str:
    path = ROOT / "scripts" / "extract_build_key_from_exe.py"
    spec = importlib.util.spec_from_file_location("extract_build_key_from_exe", path)
    assert spec and spec.loader
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    result = module.extract_build_key(exe, None)
    return result.build_key


def _looks_like_build_key(value: str) -> bool:
    return len(value) == BUILD_KEY_LENGTH and all(char in "0123456789abcdef" for char in value.lower())


def _wait_for_app_artifacts_removed(install_dir: Path, exe_name: str, *, timeout_seconds: int) -> None:
    deadline = time.monotonic() + timeout_seconds
    last_leftovers: list[Path] = []
    while time.monotonic() < deadline:
        if not install_dir.exists():
            return
        last_leftovers = [
            path
            for path in install_dir.iterdir()
            if path.name == exe_name
            or path.name in {"config", "logs", "debug_capture", ".runtime"}
            or path.name.endswith(".rt")
            or path.name.startswith((".uninstall_", ".wipe_", ".erase_"))
        ]
        if not last_leftovers:
            return
        time.sleep(1)

    names = ", ".join(sorted(path.name for path in last_leftovers))
    raise AssertionError(f"packaged self-uninstall left app artifacts in {install_dir}: {names}")


def _cleanup_free_space_runner(build_key: str) -> None:
    temp_dir = Path(tempfile.gettempdir())
    runner_exe = temp_dir / f"{build_key}.exe"
    runner_cmd = temp_dir / f"{build_key}.cmd"
    deadline = time.monotonic() + 30
    last_seen_at: float | None = None
    while time.monotonic() < deadline:
        had_files = runner_exe.exists() or runner_cmd.exists()
        stopped_count = _stop_runner_processes(runner_exe, runner_cmd)
        _unlink_if_possible(runner_exe)
        _unlink_if_possible(runner_cmd)
        has_files = runner_exe.exists() or runner_cmd.exists()
        if stopped_count or had_files or has_files:
            last_seen_at = time.monotonic()
        if last_seen_at is not None and stopped_count == 0 and not has_files:
            if time.monotonic() - last_seen_at >= 2:
                return
        time.sleep(0.2)

    stopped_count = _stop_runner_processes(runner_exe, runner_cmd)
    _unlink_if_possible(runner_exe)
    _unlink_if_possible(runner_cmd)
    leftovers = [path for path in (runner_exe, runner_cmd) if path.exists()]
    if last_seen_at is None:
        raise AssertionError("packaged self-uninstall did not create free-space runner")
    if stopped_count or leftovers:
        names = ", ".join([str(path) for path in leftovers] or [f"{stopped_count} process(es)"])
        raise AssertionError(f"packaged self-uninstall left free-space runner artifact(s): {names}")


def _unlink_if_possible(path: Path) -> None:
    try:
        path.unlink(missing_ok=True)
    except OSError:
        pass


def _stop_runner_processes(runner_exe: Path, runner_cmd: Path) -> int:
    command = (
        "$runnerExe = "
        + _powershell_single_quoted(str(runner_exe))
        + "; $runnerCmd = "
        + _powershell_single_quoted(str(runner_cmd))
        + "; $matches = @(Get-CimInstance Win32_Process | "
        + "Where-Object { $_.ProcessId -ne $PID -and ($_.ExecutablePath -eq $runnerExe "
        + "-or $_.CommandLine -like ('*' + $runnerExe + '*') "
        + "-or $_.CommandLine -like ('*' + $runnerCmd + '*')) }); "
        + "$matches | ForEach-Object { Stop-Process -Id $_.ProcessId -Force -ErrorAction SilentlyContinue }; "
        + "$matches.Count"
    )
    result = subprocess.run(
        ["powershell", "-NoProfile", "-Command", command],
        capture_output=True,
        text=True,
        timeout=30,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return int(result.stdout.strip() or "0")


def _powershell_single_quoted(value: str) -> str:
    return "'" + value.replace("'", "''") + "'"
