from pathlib import Path

import sonar.self_uninstall as self_uninstall
from sonar.self_uninstall import create_uninstall_script, get_uninstall_availability, resolve_packaged_executable_path


def test_uninstall_disabled_when_not_frozen(tmp_path):
    exe = tmp_path / "Sonar.exe"
    exe.write_text("", encoding="utf-8")

    availability = get_uninstall_availability(argv0=exe, app_dir=tmp_path, is_frozen=False)

    assert availability.enabled is False
    assert availability.executable_path is None


def test_uninstall_enabled_for_frozen_exe_folder(tmp_path):
    exe = tmp_path / "Sonar.exe"
    exe.write_text("", encoding="utf-8")

    availability = get_uninstall_availability(
        argv0=exe,
        app_dir=tmp_path,
        is_frozen=True,
        project_dir=tmp_path / "source",
    )

    assert availability.enabled is True
    assert availability.executable_path == exe.resolve()


def test_uninstall_allows_git_folder_without_source_tree(tmp_path):
    exe = tmp_path / "Sonar.exe"
    exe.write_text("", encoding="utf-8")
    (tmp_path / ".git").mkdir()

    availability = get_uninstall_availability(
        argv0=exe,
        app_dir=tmp_path,
        is_frozen=True,
        project_dir=tmp_path / "source",
    )

    assert availability.enabled is True
    assert availability.executable_path == exe.resolve()


def test_uninstall_allows_frozen_app_dir_without_source_tree_when_project_dir_matches(tmp_path):
    exe = tmp_path / "Sonar.exe"
    exe.write_text("", encoding="utf-8")
    (tmp_path / "Sonar.rt").mkdir()
    (tmp_path / "config").mkdir()

    availability = get_uninstall_availability(
        argv0=exe,
        app_dir=tmp_path,
        is_frozen=True,
        project_dir=tmp_path,
    )

    assert availability.enabled is True
    assert availability.executable_path == exe.resolve()


def test_uninstall_rejects_source_tree_even_with_exe(tmp_path):
    exe = tmp_path / "Sonar.exe"
    exe.write_text("", encoding="utf-8")
    (tmp_path / "pyproject.toml").write_text("[project]\nname = 'sonar'\n", encoding="utf-8")
    (tmp_path / "src").mkdir()

    availability = get_uninstall_availability(
        argv0=exe,
        app_dir=tmp_path,
        is_frozen=True,
        project_dir=tmp_path / "source",
    )

    assert availability.enabled is False
    assert "исходного кода" in availability.reason


def test_uninstall_requires_exe_in_target_folder(tmp_path):
    exe_dir = tmp_path / "dist"
    target_dir = tmp_path / "other"
    exe_dir.mkdir()
    target_dir.mkdir()
    exe = exe_dir / "Sonar.exe"
    exe.write_text("", encoding="utf-8")

    availability = get_uninstall_availability(
        argv0=exe,
        app_dir=target_dir,
        is_frozen=True,
        project_dir=tmp_path / "source",
    )

    assert availability.enabled is False


def test_python_executable_is_not_packaged_exe():
    assert (
        resolve_packaged_executable_path(
            argv0=Path("sonar.py"),
            executable=Path("python.exe"),
            is_frozen=True,
        )
        is None
    )


def test_uninstall_script_runs_secure_wipe_from_app_helpers(tmp_path, monkeypatch):
    helper_dir = tmp_path / "helpers"
    helper_dir.mkdir()
    (helper_dir / "secure_wipe.ps1").write_text("param()\n", encoding="utf-8")
    (helper_dir / "sdelete.exe").write_bytes(b"fake exe")
    runner_dir = tmp_path / "temp"
    runner_dir.mkdir()
    monkeypatch.setattr("sonar.self_uninstall.HELPER_DIR", helper_dir)
    monkeypatch.setattr("sonar.self_uninstall.APP_BUILD_KEY", "abc123def45")
    monkeypatch.setattr("sonar.self_uninstall.tempfile.gettempdir", lambda: str(runner_dir))
    app_dir = tmp_path / "app%dir"
    app_dir.mkdir()
    exe = app_dir / "App.exe"
    exe.write_text("", encoding="utf-8")

    script_path = create_uninstall_script(app_dir, executable_path=exe, pid=12345)
    script = script_path.read_text(encoding="utf-8")
    runner_script = runner_dir / "abc123def45.cmd"
    runner_exe = runner_dir / "abc123def45.exe"

    assert "Wait-Process -Id %PID%" in script
    assert "-Timeout 15" in script
    assert "tasklist" not in script
    assert "find" not in script
    assert "timeout" not in script
    assert 'powershell -NoProfile -ExecutionPolicy Bypass -File "%PS1%" "%TARGET%" "%SDELETE%" "%EXE%"' in script
    assert script_path.parent == app_dir
    assert script_path.name.startswith(".uninstall_")
    assert ".wipe_" in script
    assert ".erase_" in script
    assert list(app_dir.glob(".wipe_*.ps1"))
    assert list(app_dir.glob(".erase_*.exe"))
    assert list(app_dir.glob(".uninstall_*.cmd"))
    assert "sonar_secure_wipe_" not in script
    assert "sonar_sdelete_" not in script
    assert "%TEMP%" not in script
    assert "del \"%PS1%\" /f /q" in script
    assert "del \"%SDELETE%\" /f /q" in script
    assert script.index('del "%PS1%"') < script.index('del "%~f0"')
    assert script.index('del "%SDELETE%"') < script.index('del "%~f0"')
    assert f'set "FREE_SPACE_CMD={runner_script}"' in script
    assert f'set "FREE_SPACE_SDELETE={runner_exe}"' in script
    assert 'Start-Process -WindowStyle Hidden' in script
    assert runner_script.exists()
    assert runner_script.name == "abc123def45.cmd"
    assert runner_script.read_text(encoding="utf-8").count("-z") == 1
    assert "app%%dir" in script
    assert "App.exe" in script


def test_uninstall_script_requires_helper_files(tmp_path, monkeypatch):
    helper_dir = tmp_path / "missing_helpers"
    helper_dir.mkdir()
    monkeypatch.setattr("sonar.self_uninstall.HELPER_DIR", helper_dir)
    app_dir = tmp_path / "app"
    app_dir.mkdir()
    exe = app_dir / "App.exe"
    exe.write_text("", encoding="utf-8")

    try:
        create_uninstall_script(app_dir, executable_path=exe, pid=12345)
    except FileNotFoundError as exc:
        assert "удаления" in str(exc)
    else:
        raise AssertionError("create_uninstall_script must fail without helper files")


def test_schedule_self_uninstall_starts_hidden_cmd_without_detached_process(tmp_path, monkeypatch):
    exe = tmp_path / "App.exe"
    exe.write_text("", encoding="utf-8")
    script_path = tmp_path / ".uninstall_test.cmd"
    script_path.write_text("", encoding="utf-8")
    captured = {}

    monkeypatch.setattr(
        self_uninstall,
        "get_uninstall_availability",
        lambda: self_uninstall.UninstallAvailability(True, tmp_path, exe),
    )
    monkeypatch.setattr(self_uninstall, "create_uninstall_script", lambda *args, **kwargs: script_path)
    monkeypatch.setattr(self_uninstall.os, "name", "nt")

    def fake_popen(args, *, cwd, creationflags, close_fds):
        captured["args"] = args
        captured["cwd"] = cwd
        captured["creationflags"] = creationflags
        captured["close_fds"] = close_fds

    monkeypatch.setattr(self_uninstall.subprocess, "Popen", fake_popen)

    result = self_uninstall.schedule_self_uninstall(pid=12345)

    assert result == script_path
    assert captured["args"] == ["cmd.exe", "/c", str(script_path)]
    assert captured["cwd"] == str(tmp_path.parent)
    assert captured["creationflags"] & self_uninstall.subprocess.CREATE_NO_WINDOW
    assert captured["creationflags"] & self_uninstall.subprocess.CREATE_NEW_PROCESS_GROUP
    assert not (captured["creationflags"] & self_uninstall.subprocess.DETACHED_PROCESS)
    assert captured["close_fds"] is True
