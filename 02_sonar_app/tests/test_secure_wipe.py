import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def test_secure_wipe_accepts_sdelete_eula():
    script = (ROOT / "src" / "sonar" / "secure_wipe.ps1").read_text(encoding="utf-8")

    assert "-accepteula -p 4" in script
    assert "-z" not in script


def test_secure_wipe_stops_target_processes_and_removes_target_folder():
    script = (ROOT / "src" / "sonar" / "secure_wipe.ps1").read_text(encoding="utf-8")

    assert "function Stop-Target-Processes" in script
    assert "Stop-Process -Id $_.ProcessId -Force" in script
    assert "Stop-Target-Processes $TargetDir" in script
    assert "Secure-Delete-Path $TargetDir" in script
    assert "Remove-Item -LiteralPath $TargetDir -Recurse -Force" in script
    assert "Secure-Delete-Path $ExecutablePath" not in script
    assert 'Join-Path $TargetDir "config"' not in script


def test_secure_wipe_removes_target_folder_with_fake_sdelete(tmp_path):
    target_dir = tmp_path / "App"
    target_dir.mkdir()
    exe = target_dir / "App.exe"
    exe.write_text("exe", encoding="utf-8")
    (target_dir / "config").mkdir()
    (target_dir / "config" / "settings.json").write_text("{}", encoding="utf-8")
    runtime_dir = target_dir / "App.rt"
    runtime_dir.mkdir()
    (runtime_dir / "payload.bin").write_text("payload", encoding="utf-8")
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
    assert not target_dir.exists()
