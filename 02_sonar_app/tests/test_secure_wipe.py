from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def test_secure_wipe_accepts_sdelete_eula():
    script = (ROOT / "src" / "sonar" / "secure_wipe.ps1").read_text(encoding="utf-8")

    assert "-accepteula -p 4" in script
    assert "-accepteula -p 1 -z" in script


def test_secure_wipe_keeps_parent_folder_targeted():
    script = (ROOT / "src" / "sonar" / "secure_wipe.ps1").read_text(encoding="utf-8")

    assert 'Secure-Delete-Path $ExecutablePath' in script
    assert 'Join-Path $TargetDir "config"' in script
    assert 'Join-Path $TargetDir "logs"' in script
    assert 'Join-Path $TargetDir "debug_capture"' in script
    assert 'Join-Path $TargetDir ".runtime"' in script
    assert 'Remove-Item -Path $TargetDir -Recurse' not in script
