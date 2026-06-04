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
    valid = tmp_path / f"{key}-Game Name.exe.zip"
    invalid = tmp_path / "plain.zip"
    nested = tmp_path / "nested" / f"{key}-Nested.exe.zip"
    nested.parent.mkdir()
    valid.write_bytes(b"zip")
    invalid.write_bytes(b"zip")
    nested.write_bytes(b"zip")

    assert server.iter_archive_files(tmp_path) == [valid, nested]
    assert server.iter_invalid_archive_files(tmp_path) == [invalid]


def test_choose_build_archive_returns_random_valid_archive(tmp_path):
    server = _load_server()
    first = tmp_path / f"{'a' * 64}-A.exe.zip"
    second = tmp_path / f"{'b' * 64}-B.exe.zip"
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
