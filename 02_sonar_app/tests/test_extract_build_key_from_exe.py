from __future__ import annotations

import importlib.util
import json
import sys
import zipfile
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def _load_extractor():
    path = ROOT / "scripts" / "extract_build_key_from_exe.py"
    spec = importlib.util.spec_from_file_location("extract_build_key_from_exe", path)
    assert spec and spec.loader
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


def test_extract_build_key_from_exe_bytes(tmp_path):
    extractor = _load_extractor()
    key = "a" * 64
    exe = tmp_path / "Game.exe"
    exe.write_bytes(b"before " + key.encode("ascii") + b" after")

    result = extractor.extract_build_key(exe, None)

    assert result.build_key == key
    assert result.candidates == [key]


def test_extract_build_key_prefers_key_from_build_map(tmp_path):
    extractor = _load_extractor()
    wrong = "a" * 64
    right = "b" * 64
    exe = tmp_path / "Game.exe"
    build_map = tmp_path / "sonar_build_keys.json"
    exe.write_bytes(wrong.encode("ascii") + b" " + right.encode("ascii"))
    build_map.write_text(
        json.dumps({"build_keys": {right: {"obfuscation_seed": "seed", "exe_name": "Game.exe"}}}),
        encoding="utf-8",
    )

    result = extractor.extract_build_key(exe, build_map)

    assert result.build_key == right
    assert result.map_entry["obfuscation_seed"] == "seed"


def test_extract_build_key_prefers_build_map_path_match(tmp_path):
    extractor = _load_extractor()
    wrong = "a" * 11
    right = "b" * 11
    exe = tmp_path / "Game.exe"
    build_map = tmp_path / "sonar_build_keys.json"
    exe.write_bytes(wrong.encode("ascii"))
    build_map.write_text(
        json.dumps({"build_keys": {right: {"dist_path": str(exe), "obfuscation_seed": "seed"}}}),
        encoding="utf-8",
    )

    result = extractor.extract_build_key(exe, build_map)

    assert result.build_key == right
    assert result.map_entry["obfuscation_seed"] == "seed"


def test_extract_build_key_reads_powershell_utf8_bom_build_map(tmp_path):
    extractor = _load_extractor()
    key = "e" * 64
    exe = tmp_path / "Game.exe"
    build_map = tmp_path / "sonar_build_keys.json"
    exe.write_bytes(key.encode("ascii"))
    payload = json.dumps({"build_keys": {key: {"obfuscation_seed": "seed"}}})
    build_map.write_text("\ufeff" + payload, encoding="utf-8")

    result = extractor.extract_build_key(exe, build_map)

    assert result.map_entry["obfuscation_seed"] == "seed"


def test_extract_build_key_from_zip_name_without_reading_exe(tmp_path):
    extractor = _load_extractor()
    key = "c" * 64
    false_key = "f" * 64
    archive_path = tmp_path / f"{key}-Game.zip"
    with zipfile.ZipFile(archive_path, "w") as archive:
        archive.writestr("Game.exe", false_key.encode("ascii"))

    result = extractor.extract_build_key(archive_path, None)

    assert result.build_key == key
    assert result.candidates == [key]


def test_extract_short_build_key_from_zip_name(tmp_path):
    extractor = _load_extractor()
    key = "a1b2c3d4e5f"
    archive_path = tmp_path / f"{key}-Game.zip"
    with zipfile.ZipFile(archive_path, "w") as archive:
        archive.writestr("Game.exe", b"payload")

    result = extractor.extract_build_key(archive_path, None)

    assert result.build_key == key
    assert result.candidates == [key]


def test_extract_build_key_from_sibling_archive_before_exe_scan(tmp_path):
    extractor = _load_extractor()
    key = "a1b2c3d4e5f"
    false_key = "deadbeef123"
    exe = tmp_path / "Game.exe"
    exe.write_bytes(false_key.encode("ascii"))
    with zipfile.ZipFile(tmp_path / f"{key}-Game.zip", "w") as archive:
        archive.writestr("Game.exe", b"payload")

    result = extractor.extract_build_key(exe, None)

    assert result.build_key == key
    assert result.candidates[0] == key


def test_extract_build_key_from_exe_inside_zip(tmp_path):
    extractor = _load_extractor()
    key = "d" * 64
    archive_path = tmp_path / "Game.zip"
    with zipfile.ZipFile(archive_path, "w") as archive:
        archive.writestr("Game.exe", b"payload " + key.encode("ascii"))

    result = extractor.extract_build_key(archive_path, None)

    assert result.build_key == key
