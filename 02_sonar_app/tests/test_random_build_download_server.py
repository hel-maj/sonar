from __future__ import annotations

import importlib.util
import random
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def _load_server():
    path = ROOT / "scripts" / "random_build_download_server.py"
    spec = importlib.util.spec_from_file_location("random_build_download_server", path)
    assert spec and spec.loader
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def test_iter_archive_files_only_accepts_build_archives(tmp_path):
    server = _load_server()
    key = "a" * 11
    valid = tmp_path / f"{key}-Game Name.zip"
    invalid = tmp_path / "plain.zip"
    nested = tmp_path / "nested" / f"{key}-Nested.zip"
    nested.parent.mkdir()
    valid.write_bytes(b"zip")
    invalid.write_bytes(b"zip")
    nested.write_bytes(b"zip")

    assert server.iter_archive_files(tmp_path) == [valid, nested]
    assert server.iter_invalid_archive_files(tmp_path) == [invalid]


def test_iter_archive_files_keeps_old_exe_zip_compatibility(tmp_path):
    server = _load_server()
    key = "b" * 11
    archive = tmp_path / f"{key}-Old Name.exe.zip"
    archive.write_bytes(b"zip")

    assert server.iter_archive_files(tmp_path) == [archive]


def test_iter_archive_files_uses_latest_version_folder_only(tmp_path):
    server = _load_server()
    old = tmp_path / "0.1.0"
    latest = tmp_path / "0.2.0"
    old.mkdir()
    latest.mkdir()
    old_archive = old / f"{'a' * 11}-Old.zip"
    latest_archive = latest / f"{'b' * 11}-Latest.zip"
    root_archive = tmp_path / f"{'c' * 11}-Root.zip"
    old_archive.write_bytes(b"old")
    latest_archive.write_bytes(b"latest")
    root_archive.write_bytes(b"root")

    assert server.latest_version_dir(tmp_path).version == "0.2.0"
    assert server.iter_archive_files(tmp_path) == [latest_archive]


def test_choose_build_archive_returns_random_valid_archive(tmp_path):
    server = _load_server()
    first = tmp_path / f"{'a' * 64}-A.zip"
    second = tmp_path / f"{'b' * 64}-B.zip"
    first.write_bytes(b"a")
    second.write_bytes(b"b")

    archive = server.choose_build_archive(tmp_path, random.Random(1))

    assert archive.path in {first, second}
    assert archive.archive_name == archive.path.name


def test_choose_build_archive_errors_when_folder_has_no_zip_builds(tmp_path):
    server = _load_server()
    (tmp_path / "Game.exe").write_bytes(b"exe")

    try:
        server.choose_build_archive(tmp_path)
    except FileNotFoundError as exc:
        assert "No build .zip archives found" in str(exc)
    else:
        raise AssertionError("expected missing build archive error")


def test_download_page_points_to_random_zip_endpoint():
    server = _load_server()

    html = server.download_page(token="secret value")

    assert "/api/random-build.zip?token=secret%20value" in html
    assert "Подготовка загрузки" in html


def test_startup_blocklist_matches_build_or_license_key(tmp_path):
    server = _load_server()
    path = tmp_path / "startup-blocklist.json"
    path.write_text(
        """{
  "build_keys": ["abc123"],
  "license_keys": ["LICENSE-1"],
  "download_url": "https://m-sonar-addr.ru/download"
}""",
        encoding="utf-8",
    )

    blocklist = server.load_startup_blocklist(path)

    assert server.is_startup_blocked({"build_key": "ABC123", "license_key": ""}, blocklist) is True
    assert server.is_startup_blocked({"build_key": "", "license_key": "LICENSE-1"}, blocklist) is True
    assert server.is_startup_blocked({"build_key": "other", "license_key": "LICENSE-2"}, blocklist) is False


def test_startup_block_response_is_signed_for_client_verifier():
    server = _load_server()
    from sonar.license.startup_block import parse_signed_startup_block_response
    from sonar.security.ed25519 import ed25519_public_key_from_seed

    seed = bytes(range(32))
    body = server.signed_startup_block_response(
        blocked=True,
        download_url="https://m-sonar-addr.ru/download",
        private_key_seed=seed,
    )

    status = parse_signed_startup_block_response(body, ed25519_public_key_from_seed(seed))

    assert set(body) == {"blocked", "download_url", "signature"}
    assert status.checked is True
    assert status.blocked is True
    assert status.download_url == "https://m-sonar-addr.ru/download"
