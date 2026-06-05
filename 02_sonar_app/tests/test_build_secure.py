import importlib.util
from pathlib import Path
from types import SimpleNamespace

from PIL import Image


ROOT = Path(__file__).resolve().parents[1]


def _load_obfuscator():
    path = ROOT / "scripts" / "obfuscate_release_sources.py"
    spec = importlib.util.spec_from_file_location("obfuscate_release_sources", path)
    assert spec and spec.loader
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def _load_branding():
    path = ROOT / "scripts" / "prepare_build_branding.py"
    spec = importlib.util.spec_from_file_location("prepare_build_branding", path)
    assert spec and spec.loader
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_secure_build_requests_admin_and_bundles_uninstall_helpers():
    script = (ROOT / "scripts" / "build_secure.ps1").read_text(encoding="utf-8")

    assert "--windows-uac-admin" in script
    assert "--python-flag=no_docstrings" in script
    assert "--python-flag=no_asserts" in script
    assert "[switch]$NoLto" in script
    assert "$LtoMode = if ($NoLto)" in script
    assert "--lto=$LtoMode" in script
    assert "$env:PYTHONUTF8 = \"1\"" in script
    assert "$env:PYTHONIOENCODING = \"utf-8\"" in script
    assert "--include-data-files=$SecureWipePath=sonar/secure_wipe.ps1" in script
    assert "--include-data-files=$SDeletePath=sonar/sdelete.exe" in script


def test_secure_build_prepares_portable_streaming_binaries():
    script = (ROOT / "scripts" / "build_secure.ps1").read_text(encoding="utf-8")

    assert "scripts\\prepare_streaming_binaries.py" in script
    assert "Failed to prepare streaming binaries" in script


def test_secure_build_records_reproducible_build_key_map():
    script = (ROOT / "scripts" / "build_secure.ps1").read_text(encoding="utf-8")
    branding = (ROOT / "scripts" / "prepare_build_branding.py").read_text(encoding="utf-8")

    assert "sonar_build_keys.json" in script
    assert "app_version" in script
    assert "archive_name" in script
    assert "archive_path" in script
    assert "APP_BUILD_KEY" in branding
    assert "APP_OBFUSCATION_SEED" in branding
    assert "--seed" in branding


def test_secure_build_runs_release_secret_audit():
    script = (ROOT / "scripts" / "build_secure.ps1").read_text(encoding="utf-8")
    audit = (ROOT / "scripts" / "audit_release_secrets.py").read_text(encoding="utf-8")

    assert "scripts\\audit_release_secrets.py" in script
    assert "sonar-keygen" in audit
    assert ".nip.io" in audit


def test_secure_build_creates_uploadable_zip_archive_next_to_exe():
    script = (ROOT / "scripts" / "build_secure.ps1").read_text(encoding="utf-8")

    assert "[int]$Count = 1" in script
    assert "[string]$LicenseServerUrl = \"\"" in script
    assert "[string]$StartupBlockUrl = \"\"" in script
    assert "[string]$StartupBlockPublicKey = \"\"" in script
    assert "--license-server-url" in script
    assert "--startup-block-url" in script
    assert "--startup-block-public-key" in script
    assert "function New-BuildArchive" in script
    assert "[System.IO.Compression.ZipFile]::Open" in script
    assert "[System.IO.Compression.CompressionLevel]::NoCompression" in script
    assert "$VersionDistRoot = Join-Path $DistRoot $AppVersion" in script
    assert "\"{0}-{1}.zip\"" in script
    assert "Build archive:" in script
    assert "Build version:" in script


def test_secure_build_obfuscates_release_sources_with_seed():
    script = (ROOT / "scripts" / "build_secure.ps1").read_text(encoding="utf-8")

    assert "scripts\\obfuscate_release_sources.py" in script
    assert "--seed" in script
    assert "$($Branding.obfuscation_seed)" in script


def test_release_obfuscator_renames_private_identifiers_deterministically(tmp_path):
    obfuscator = _load_obfuscator()

    def make_source(root: Path) -> Path:
        source_root = root / "src"
        sonar_root = source_root / "sonar"
        (sonar_root / "security").mkdir(parents=True)
        (sonar_root / "module.py").write_text(
            "_VALUE = 1\n\n"
            "def _helper():\n"
            "    _local = _VALUE\n"
            "    return _local\n\n"
            "def public():\n"
            "    return _helper()\n",
            encoding="utf-8",
        )
        (sonar_root / "reflect.py").write_text(
            "def public(obj):\n"
            "    return getattr(obj, \"_reflected\", None)\n\n"
            "def _reflected():\n"
            "    return 1\n",
            encoding="utf-8",
        )
        (sonar_root / "build_metadata.py").write_text("APP_BUILD_KEY = '_stable'\n", encoding="utf-8")
        (sonar_root / "security" / "literals.py").write_text("ENCRYPTED_LITERALS = {'_stable': 'x'}\n", encoding="utf-8")
        return source_root

    first = make_source(tmp_path / "first")
    second = make_source(tmp_path / "second")
    first_meta = obfuscator.obfuscate_release_sources(first, "repeatable-seed")
    second_meta = obfuscator.obfuscate_release_sources(second, "repeatable-seed")

    first_text = (first / "sonar" / "module.py").read_text(encoding="utf-8")
    second_text = (second / "sonar" / "module.py").read_text(encoding="utf-8")
    assert first_meta["renamed_identifiers"] == second_meta["renamed_identifiers"]
    assert first_text == second_text
    assert "_helper" not in first_text
    assert "_VALUE" not in first_text
    assert "def public" in first_text
    assert 'APP_BUILD_KEY = \'_stable\'' in (first / "sonar" / "build_metadata.py").read_text(encoding="utf-8")
    assert "ENCRYPTED_LITERALS = {'_stable': 'x'}" in (first / "sonar" / "security" / "literals.py").read_text(encoding="utf-8")
    assert "def _reflected" in (first / "sonar" / "reflect.py").read_text(encoding="utf-8")


def test_branding_accepts_neutral_license_server_override():
    branding = _load_branding()

    values = branding.runtime_literal_values(
        SimpleNamespace(
            license_server_url="https://m-sonar-addr.ru/",
            license_account_id="account-id",
            startup_block_url="https://checks.example/api/startup-block",
            startup_block_public_key="a" * 64,
        )
    )

    assert values["license_server_url"] == "https://m-sonar-addr.ru"
    assert values["license_account_id"] == "account-id"
    assert values["startup_block_url"] == "https://checks.example/api/startup-block"
    assert values["startup_block_public_key"] == "a" * 64


def test_branding_accepts_license_server_from_dotenv(tmp_path, monkeypatch):
    dotenv = tmp_path / ".env"
    dotenv.write_text(
        "\n".join(
            [
                "SONAR_LICENSE_SERVER_URL=https://dotenv.example.test/",
                "SONAR_LICENSE_ACCOUNT_ID=dotenv-account",
                "SONAR_STARTUP_BLOCK_URL=https://dotenv-checks.example.test/api/startup-block",
                "SONAR_STARTUP_BLOCK_PUBLIC_KEY=bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
                "",
            ]
        ),
        encoding="utf-8",
    )
    monkeypatch.setenv("SONAR_DOTENV_PATH", str(dotenv))
    monkeypatch.delenv("SONAR_LICENSE_SERVER_URL", raising=False)
    monkeypatch.delenv("SONAR_LICENSE_ACCOUNT_ID", raising=False)
    monkeypatch.delenv("SONAR_STARTUP_BLOCK_URL", raising=False)
    monkeypatch.delenv("SONAR_STARTUP_BLOCK_PUBLIC_KEY", raising=False)
    branding = _load_branding()

    values = branding.runtime_literal_values(
        SimpleNamespace(license_server_url="", license_account_id="", startup_block_url="", startup_block_public_key="")
    )

    assert values["license_server_url"] == "https://dotenv.example.test"
    assert values["license_account_id"] == "dotenv-account"
    assert values["startup_block_url"] == "https://dotenv-checks.example.test/api/startup-block"
    assert values["startup_block_public_key"] == "b" * 64


def test_branding_seed_ignores_icon_history_for_reproducible_rebuild(tmp_path):
    branding = _load_branding()
    icons = tmp_path / "icons"
    icons.mkdir()
    for name, color in (("A.png", (255, 0, 0, 255)), ("B.png", (0, 255, 0, 255)), ("C.png", (0, 0, 255, 255))):
        Image.new("RGBA", (16, 16), color).save(icons / name)

    history_file = icons / ".build_history.json"
    first = branding.prepare_build(
        SimpleNamespace(
            source_root=_make_branding_source(tmp_path / "first"),
            icons_dir=icons,
            metadata_out=tmp_path / "first.json",
            history_file=history_file,
            seed="fixed-seed",
            build_key="fixed-key",
        )
    )
    second = branding.prepare_build(
        SimpleNamespace(
            source_root=_make_branding_source(tmp_path / "second"),
            icons_dir=icons,
            metadata_out=tmp_path / "second.json",
            history_file=history_file,
            seed="fixed-seed",
            build_key="fixed-key",
        )
    )

    assert Path(first["icon_png"]).name == Path(second["icon_png"]).name
    assert first["exe_name"] == second["exe_name"]
    assert not history_file.exists()


def test_branding_generates_short_build_key(tmp_path):
    branding = _load_branding()
    icons = tmp_path / "icons"
    icons.mkdir()
    Image.new("RGBA", (16, 16), (255, 0, 0, 255)).save(icons / "A.png")

    result = branding.prepare_build(
        SimpleNamespace(
            source_root=_make_branding_source(tmp_path / "build"),
            icons_dir=icons,
            metadata_out=tmp_path / "build.json",
            history_file=icons / ".build_history.json",
            seed="fixed-seed",
            build_key="",
            license_server_url="",
            license_account_id="",
        )
    )

    assert len(result["build_key"]) == 11
    assert all(character in "0123456789abcdef" for character in result["build_key"])


def test_package_data_includes_uninstall_helpers():
    pyproject = (ROOT / "pyproject.toml").read_text(encoding="utf-8")

    assert '"secure_wipe.ps1"' in pyproject
    assert '"sdelete.exe"' in pyproject


def _make_branding_source(path: Path) -> Path:
    source_root = path / "src"
    resources = source_root / "sonar" / "resources"
    security = source_root / "sonar" / "security"
    resources.mkdir(parents=True)
    security.mkdir(parents=True)
    (source_root / "sonar" / "build_metadata.py").write_text("", encoding="utf-8")
    (security / "literals.py").write_text("", encoding="utf-8")
    return source_root
