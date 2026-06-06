from __future__ import annotations

import json
import shutil
import subprocess
from pathlib import Path

import pytest


PROJECT_DIR = Path(__file__).resolve().parents[1]
SCRIPT = PROJECT_DIR / "scripts" / "record_manual_reeling.ps1"


def _powershell() -> str | None:
    return shutil.which("powershell") or shutil.which("pwsh")


@pytest.mark.parametrize(
    ("label_keys", "expected"),
    [
        ("AD", "ad"),
        ("Arrows", "arrows"),
    ],
)
def test_record_manual_reeling_dry_run_builds_label_key_arguments(label_keys: str, expected: str) -> None:
    shell = _powershell()
    if shell is None:
        pytest.skip("PowerShell is not available")

    completed = subprocess.run(
        [
            shell,
            "-NoProfile",
            "-ExecutionPolicy",
            "Bypass",
            "-File",
            str(SCRIPT),
            "-DryRun",
            "-Label",
            "smoke",
            "-Duration",
            "0.1",
            "-Countdown",
            "0",
            "-AutoStopIdle",
            "0.1",
            "-LabelKeys",
            label_keys,
        ],
        cwd=PROJECT_DIR,
        check=True,
        capture_output=True,
        text=True,
    )

    payload = json.loads(completed.stdout)
    args = payload["Arguments"]

    label_keys_index = args.index("--label-keys")
    assert args[label_keys_index + 1] == expected
    assert "--label" in args
    assert args[args.index("--label") + 1] == "smoke"
    assert payload["WorkingDirectory"] == str(PROJECT_DIR)
