import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def test_secure_wipe_accepts_sdelete_eula():
    script = (ROOT / "src" / "sonar" / "secure_wipe.ps1").read_text(encoding="utf-8")

    assert "-accepteula -p 4" in script
    assert "-accepteula -p 1 -z" in script


def test_secure_wipe_keeps_parent_folder_targeted():
    script = (ROOT / "src" / "sonar" / "secure_wipe.ps1").read_text(encoding="utf-8")

    assert "Stop-Process" not in script
    assert "Get-CimInstance Win32_Process" not in script
    assert "Secure-Delete-Path $ExecutablePath" in script
    assert 'Join-Path $TargetDir "config"' in script
    assert 'Join-Path $TargetDir "logs"' in script
    assert 'Join-Path $TargetDir "debug_capture"' in script
    assert 'Join-Path $TargetDir ".runtime"' in script
    assert 'Join-Path $TargetDir "$AppName.rt"' in script
    assert "Secure-Delete-Path $TargetDir" not in script
    assert "Remove-Item -LiteralPath $TargetDir -Recurse -Force" not in script


def test_secure_wipe_removes_only_app_artifacts_with_fake_sdelete(tmp_path):
    target_dir = tmp_path / "App"
    target_dir.mkdir()
    exe = target_dir / "App.exe"
    exe.write_text("exe", encoding="utf-8")
    (target_dir / "config").mkdir()
    (target_dir / "config" / "settings.json").write_text("{}", encoding="utf-8")
    (target_dir / "logs").mkdir()
    (target_dir / "logs" / "app.log").write_text("log", encoding="utf-8")
    runtime_dir = target_dir / "App.rt"
    runtime_dir.mkdir()
    (runtime_dir / "payload.bin").write_text("payload", encoding="utf-8")
    user_file = target_dir / "keep.txt"
    user_file.write_text("keep", encoding="utf-8")
    fake_sdelete = tmp_path / "sdelete.cmd"
    fake_sdelete.write_text("@echo off\r\nexit /b 0\r\n", encoding="utf-8")

    result = subprocess.run(
        [
            "powershell",
            "-NoProfile",
            "-ExecutionPolicy",
            "Bypass",
            "-File",
            str(ROOT / "src" / "sonar" / "secure_wipe.ps1"),
            str(target_dir),
            str(fake_sdelete),
            str(exe),
        ],
        capture_output=True,
        text=True,
        timeout=30,
    )

    assert result.returncode == 0, result.stderr
    assert target_dir.exists()
    assert user_file.exists()
    assert not exe.exists()
    assert not (target_dir / "config").exists()
    assert not (target_dir / "logs").exists()
    assert not runtime_dir.exists()
