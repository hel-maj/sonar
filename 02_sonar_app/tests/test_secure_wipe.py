from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def test_secure_wipe_accepts_sdelete_eula():
    script = (ROOT / "src" / "sonar" / "secure_wipe.ps1").read_text(encoding="utf-8")

    assert "-accepteula -p 4" in script
    assert "-accepteula -p 1 -z" in script
