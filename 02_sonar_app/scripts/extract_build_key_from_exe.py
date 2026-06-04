from __future__ import annotations

import argparse
import json
import re
import zipfile
from dataclasses import dataclass
from pathlib import Path
from typing import BinaryIO


APP_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_BUILD_MAP = APP_ROOT.parent / "config" / "sonar_build_keys.json"
BUILD_KEY_RE = re.compile(rb"(?<![0-9A-Fa-f])(?:[0-9A-Fa-f]{11}|[0-9A-Fa-f]{64})(?![0-9A-Fa-f])")
TEXT_BUILD_KEY_RE = re.compile(r"^(?:[0-9a-f]{11}|[0-9a-f]{64})$")


@dataclass(frozen=True, slots=True)
class ExtractionResult:
    path: Path
    build_key: str
    candidates: list[str]
    map_entry: dict[str, object]


def extract_build_key(path: Path, build_map_path: Path | None = DEFAULT_BUILD_MAP) -> ExtractionResult:
    path = path.resolve()
    candidates = candidate_keys_from_path(path)
    key_map = load_build_key_map(build_map_path) if build_map_path else {}
    build_key = choose_candidate(candidates, key_map)
    return ExtractionResult(
        path=path,
        build_key=build_key,
        candidates=candidates,
        map_entry=dict(key_map.get(build_key, {})) if build_key else {},
    )


def candidate_keys_from_path(path: Path) -> list[str]:
    candidates = candidate_keys_from_name(path.name)
    if candidates:
        return candidates
    if path.suffix.lower() == ".zip":
        candidates.extend(candidate_keys_from_zip(path))
    else:
        candidates.extend(candidate_keys_from_file(path))
    return unique_keys(candidates)


def candidate_keys_from_name(name: str) -> list[str]:
    first = name.split("-", 1)[0].strip().lower()
    return [first] if TEXT_BUILD_KEY_RE.match(first) else []


def candidate_keys_from_zip(path: Path) -> list[str]:
    candidates: list[str] = []
    try:
        with zipfile.ZipFile(path) as archive:
            for info in archive.infolist():
                candidates.extend(candidate_keys_from_name(Path(info.filename).name))
                if Path(info.filename).suffix.lower() != ".exe":
                    continue
                with archive.open(info, "r") as file:
                    candidates.extend(scan_stream(file))
    except (OSError, zipfile.BadZipFile):
        return candidates
    return candidates


def candidate_keys_from_file(path: Path) -> list[str]:
    try:
        with path.open("rb") as file:
            return scan_stream(file)
    except OSError:
        return []


def scan_stream(file: BinaryIO, chunk_size: int = 1024 * 1024) -> list[str]:
    candidates: list[str] = []
    tail = b""
    while True:
        chunk = file.read(chunk_size)
        if not chunk:
            break
        data = tail + chunk
        candidates.extend(match.group(0).decode("ascii").lower() for match in BUILD_KEY_RE.finditer(data))
        tail = data[-80:]
    return unique_keys(candidates)


def unique_keys(keys: list[str]) -> list[str]:
    seen: set[str] = set()
    result: list[str] = []
    for key in keys:
        normalized = key.strip().lower()
        if TEXT_BUILD_KEY_RE.match(normalized) and normalized not in seen:
            seen.add(normalized)
            result.append(normalized)
    return result


def load_build_key_map(path: Path | None) -> dict[str, dict[str, object]]:
    if not path or not path.exists():
        return {}
    try:
        raw = json.loads(path.read_text(encoding="utf-8-sig"))
    except (OSError, json.JSONDecodeError):
        return {}
    build_keys = raw.get("build_keys") if isinstance(raw, dict) else None
    if not isinstance(build_keys, dict):
        return {}
    result: dict[str, dict[str, object]] = {}
    for key, value in build_keys.items():
        normalized = str(key).strip().lower()
        if TEXT_BUILD_KEY_RE.match(normalized) and isinstance(value, dict):
            result[normalized] = value
    return result


def choose_candidate(candidates: list[str], key_map: dict[str, dict[str, object]]) -> str:
    for candidate in candidates:
        if candidate in key_map:
            return candidate
    return candidates[0] if candidates else ""


def result_payload(result: ExtractionResult) -> dict[str, object]:
    return {
        "path": str(result.path),
        "build_key": result.build_key,
        "candidates": result.candidates,
        "map_entry": result.map_entry,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description="Extract Sonar build key from a built exe or build zip.")
    parser.add_argument("path", type=Path, help="Path to .exe or <build_key>-<exe>.zip")
    parser.add_argument("--map", dest="build_map", type=Path, default=DEFAULT_BUILD_MAP, help="Path to sonar_build_keys.json")
    parser.add_argument("--no-map", action="store_true", help="Do not use sonar_build_keys.json to resolve ambiguous keys")
    parser.add_argument("--json", action="store_true", help="Print machine-readable JSON")
    args = parser.parse_args()

    build_map = None if args.no_map else args.build_map
    result = extract_build_key(args.path, build_map)
    if args.json:
        print(json.dumps(result_payload(result), ensure_ascii=False, indent=2))
    elif result.build_key:
        print(f"Build key: {result.build_key}")
        if result.map_entry:
            seed = result.map_entry.get("obfuscation_seed")
            exe_name = result.map_entry.get("exe_name")
            app_name = result.map_entry.get("app_name")
            if seed:
                print(f"Obfuscation seed: {seed}")
            if app_name:
                print(f"App name: {app_name}")
            if exe_name:
                print(f"Exe name: {exe_name}")
        if len(result.candidates) > 1:
            print("Other candidates:")
            for candidate in result.candidates:
                if candidate != result.build_key:
                    print(f"  {candidate}")
    else:
        print(f"Build key not found in {args.path}")
    return 0 if result.build_key else 1


if __name__ == "__main__":
    raise SystemExit(main())
