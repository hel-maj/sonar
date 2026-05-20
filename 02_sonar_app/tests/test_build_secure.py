from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def test_secure_build_requests_admin_and_bundles_uninstall_helpers():
    script = (ROOT / "scripts" / "build_secure.ps1").read_text(encoding="utf-8")

    assert "--windows-uac-admin" in script
    assert "--include-data-files=\"$SecureWipePath=sonar/secure_wipe.ps1\"" in script
    assert "--include-data-files=\"$SDeletePath=sonar/sdelete.exe\"" in script


def test_secure_build_prepares_portable_streaming_binaries():
    script = (ROOT / "scripts" / "build_secure.ps1").read_text(encoding="utf-8")

    assert "scripts\\prepare_streaming_binaries.py" in script
    assert "Failed to prepare streaming binaries" in script


def test_package_data_includes_uninstall_helpers():
    pyproject = (ROOT / "pyproject.toml").read_text(encoding="utf-8")

    assert '"secure_wipe.ps1"' in pyproject
    assert '"sdelete.exe"' in pyproject
