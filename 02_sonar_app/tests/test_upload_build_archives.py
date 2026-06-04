from __future__ import annotations

import importlib.util
import sys
from pathlib import Path
from types import SimpleNamespace


ROOT = Path(__file__).resolve().parents[1]


def _load_uploads():
    path = ROOT / "scripts" / "upload_build_archives.py"
    spec = importlib.util.spec_from_file_location("upload_build_archives", path)
    assert spec and spec.loader
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def test_iter_build_archives_accepts_only_named_build_zips(tmp_path):
    uploads = _load_uploads()
    key = "a" * 11
    valid = tmp_path / f"{key}-Game.exe.zip"
    invalid = tmp_path / "Game.zip"
    nested = tmp_path / "nested" / f"{key}-Nested.exe.zip"
    nested.parent.mkdir()
    valid.write_bytes(b"zip")
    invalid.write_bytes(b"zip")
    nested.write_bytes(b"zip")

    assert uploads.iter_build_archives(tmp_path) == [valid, nested]


def test_ssh_command_uses_key_and_batch_mode():
    uploads = _load_uploads()
    args = SimpleNamespace(port=2222, key=Path("id_ed25519"), allow_password=False, user="root", host="example.com")

    command = uploads.ssh_command(args, "mkdir -p -- /builds")

    assert command == [
        "ssh",
        "-p",
        "2222",
        "-i",
        "id_ed25519",
        "-o",
        "BatchMode=yes",
        "root@example.com",
        "mkdir -p -- /builds",
    ]


def test_scp_command_uploads_to_remote_builds_dir():
    uploads = _load_uploads()
    archive = Path("dist") / f"{'b' * 64}-Game.exe.zip"
    args = SimpleNamespace(
        port=22,
        key=None,
        allow_password=False,
        user="root",
        host="m-sonar-addr.ru",
        remote_dir="/remote/builds",
    )

    command = uploads.scp_command(args, archive)

    assert command == [
        "scp",
        "-P",
        "22",
        "-o",
        "BatchMode=yes",
        str(archive),
        "root@m-sonar-addr.ru:/remote/builds/",
    ]


def test_default_upload_host_is_production_domain(tmp_path, monkeypatch):
    monkeypatch.setenv("SONAR_DOTENV_PATH", str(tmp_path / "missing.env"))
    monkeypatch.delenv("SONAR_UPLOAD_HOST", raising=False)
    uploads = _load_uploads()

    assert uploads.DEFAULT_HOST == "m-sonar-addr.ru"


def test_default_upload_host_can_come_from_dotenv(tmp_path, monkeypatch):
    dotenv = tmp_path / ".env"
    dotenv.write_text("SONAR_UPLOAD_HOST=uploads.example.test\n", encoding="utf-8")
    monkeypatch.setenv("SONAR_DOTENV_PATH", str(dotenv))
    monkeypatch.delenv("SONAR_UPLOAD_HOST", raising=False)

    uploads = _load_uploads()

    assert uploads.DEFAULT_HOST == "uploads.example.test"


def test_upload_archives_dry_run_does_not_report_uploaded(tmp_path, capsys):
    uploads = _load_uploads()
    key = "c" * 64
    archive = tmp_path / f"{key}-Game.exe.zip"
    archive.write_bytes(b"zip")
    args = SimpleNamespace(
        source=tmp_path,
        port=22,
        key=None,
        allow_password=False,
        user="root",
        host="m-sonar-addr.ru",
        remote_dir="/remote/builds",
        dry_run=True,
    )

    assert uploads.upload_archives(args) == 0
    output = capsys.readouterr().out

    assert "Dry run complete" in output
    assert "would be uploaded" in output


def test_upload_archives_requires_host(tmp_path, capsys):
    uploads = _load_uploads()
    key = "d" * 64
    archive = tmp_path / f"{key}-Game.exe.zip"
    archive.write_bytes(b"zip")
    args = SimpleNamespace(
        source=tmp_path,
        port=22,
        key=None,
        allow_password=False,
        user="root",
        host="",
        remote_dir="/remote/builds",
        dry_run=True,
    )

    assert uploads.upload_archives(args) == 2
    assert "SSH host is required" in capsys.readouterr().out
