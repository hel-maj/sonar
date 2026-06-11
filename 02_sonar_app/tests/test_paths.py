from __future__ import annotations

import sys
from pathlib import Path

import sonar.paths as paths


def test_frozen_app_dir_uses_original_onefile_exe_dir(monkeypatch, tmp_path):
    executable = tmp_path / "Cyberpunk 2077.exe"
    monkeypatch.setattr(paths.sys, "argv", [str(executable)])
    monkeypatch.setattr(paths.sys, "executable", str(tmp_path / ".runtime" / "onefile_123" / "python.exe"))

    assert paths._frozen_app_dir() == tmp_path.resolve()


def test_frozen_app_dir_falls_back_to_sys_executable_parent(monkeypatch, tmp_path):
    executable = tmp_path / "python.exe"
    monkeypatch.setattr(paths.sys, "argv", [""])
    monkeypatch.setattr(paths.sys, "executable", str(executable))

    assert paths._frozen_app_dir() == tmp_path.resolve()


def test_frozen_payload_dirs_are_neutral(monkeypatch, tmp_path):
    package_dir = tmp_path / "onefile" / "sonar"
    monkeypatch.setattr(paths, "PACKAGE_DIR", package_dir)
    monkeypatch.setattr(paths, "IS_FROZEN", True)

    payload_dir = paths._frozen_payload_dir() / ".payload"

    assert payload_dir == tmp_path / "onefile" / ".payload"
    assert "sonar" not in str(payload_dir.relative_to(tmp_path)).lower()
