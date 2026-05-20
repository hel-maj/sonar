from pathlib import Path

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


def test_uninstall_script_deletes_target_without_recycle_bin(tmp_path):
    script_path = create_uninstall_script(tmp_path / "app%dir", pid=12345)
    try:
        script = script_path.read_text(encoding="utf-8")
    finally:
        script_path.unlink(missing_ok=True)

    assert "tasklist /FI \"PID eq %PID%\"" in script
    assert "rmdir /s /q \"%TARGET%\"" in script
    assert "del \"%~f0\"" in script
    assert "app%%dir" in script
