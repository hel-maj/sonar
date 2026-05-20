from __future__ import annotations

import argparse
import json
import os
import re
import secrets
import unicodedata
from pathlib import Path
from typing import Any

from PIL import Image


MIN_SALT_BYTES = 100 * 1024
MAX_SALT_BYTES = 50 * 1024 * 1024
ICON_SIZES = ((16, 16), (24, 24), (32, 32), (48, 48), (64, 64), (128, 128), (256, 256))
INVALID_FILENAME_CHARS = set('<>:"/\\|?*')
RESERVED_WINDOWS_NAMES = {
    "CON",
    "PRN",
    "AUX",
    "NUL",
    *(f"COM{index}" for index in range(1, 10)),
    *(f"LPT{index}" for index in range(1, 10)),
}


def sanitize_windows_stem(value: str) -> str:
    normalized = unicodedata.normalize("NFKC", value)
    normalized = re.sub(r"\s+", " ", normalized)
    cleaned = "".join("_" if character in INVALID_FILENAME_CHARS or ord(character) < 32 else character for character in normalized)
    cleaned = cleaned.strip(" .")
    if not cleaned:
        cleaned = f"Build_{secrets.token_hex(4)}"
    if cleaned.upper() in RESERVED_WINDOWS_NAMES:
        cleaned = f"{cleaned}_app"
    if len(cleaned) > 90:
        cleaned = cleaned[:90].rstrip(" .")
    return cleaned


def load_history(path: Path) -> list[str]:
    try:
        raw = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return []
    used = raw.get("used", raw) if isinstance(raw, dict) else raw
    return [str(item) for item in used] if isinstance(used, list) else []


def save_history(path: Path, used: list[str]) -> None:
    path.write_text(json.dumps({"used": used}, ensure_ascii=False, indent=2), encoding="utf-8")


def assert_png_loads(path: Path) -> None:
    with Image.open(path) as image:
        image.verify()


def choose_icon(icons_dir: Path, history_file: Path) -> Path:
    icons = sorted(path for path in icons_dir.glob("*.png") if path.is_file())
    if not icons:
        raise SystemExit(f"No PNG icons found in {icons_dir}")

    history = load_history(history_file)
    history_set = set(history)
    candidates = [path for path in icons if path.name not in history_set]
    if not candidates:
        history = []
        candidates = icons[:]

    shuffled = candidates[:]
    secrets.SystemRandom().shuffle(shuffled)
    for icon_path in shuffled:
        try:
            assert_png_loads(icon_path)
        except Exception:
            continue
        history.append(icon_path.name)
        save_history(history_file, history)
        return icon_path

    raise SystemExit(f"No readable PNG icons found in {icons_dir}")


def square_icon_image(path: Path) -> Image.Image:
    with Image.open(path) as source:
        image = source.convert("RGBA")
    edge = max(image.width, image.height)
    canvas = Image.new("RGBA", (edge, edge), (0, 0, 0, 0))
    canvas.alpha_composite(image, ((edge - image.width) // 2, (edge - image.height) // 2))
    return canvas


def write_ico(source_png: Path, icon_path: Path) -> None:
    icon_path.parent.mkdir(parents=True, exist_ok=True)
    image = square_icon_image(source_png)
    image.save(icon_path, format="ICO", sizes=ICON_SIZES)


def write_build_metadata(source_root: Path, app_name: str, icon_source: Path, build_hash: str) -> Path:
    metadata_path = source_root / "sonar" / "build_metadata.py"
    metadata_path.write_text(
        "\n".join(
            [
                "from __future__ import annotations",
                "",
                f"APP_NAME = {app_name!r}",
                f"APP_ICON_SOURCE = {icon_source.name!r}",
                f"APP_BUILD_HASH = {build_hash!r}",
                "",
            ]
        ),
        encoding="utf-8",
    )
    return metadata_path


def write_salt(path: Path) -> int:
    path.parent.mkdir(parents=True, exist_ok=True)
    size = MIN_SALT_BYTES + secrets.randbelow(MAX_SALT_BYTES - MIN_SALT_BYTES + 1)
    remaining = size
    with path.open("wb") as file:
        while remaining:
            chunk_size = min(remaining, 1024 * 1024)
            file.write(os.urandom(chunk_size))
            remaining -= chunk_size
    return size


def prepare_build(args: argparse.Namespace) -> dict[str, Any]:
    source_root = args.source_root.resolve()
    resources_dir = source_root / "sonar" / "resources"
    icon_png = choose_icon(args.icons_dir.resolve(), args.history_file.resolve())
    app_name = sanitize_windows_stem(icon_png.stem)
    build_hash = secrets.token_hex(16)
    icon_ico = resources_dir / "app.ico"
    salt_path = resources_dir / "build_salt.bin"

    write_ico(icon_png, icon_ico)
    metadata_path = write_build_metadata(source_root, app_name, icon_png, build_hash)
    salt_bytes = write_salt(salt_path)

    return {
        "app_name": app_name,
        "exe_name": f"{app_name}.exe",
        "build_hash": build_hash,
        "icon_png": str(icon_png),
        "icon_ico": str(icon_ico),
        "metadata_path": str(metadata_path),
        "salt_path": str(salt_path),
        "salt_bytes": salt_bytes,
    }


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Prepare per-build executable branding.")
    parser.add_argument("--source-root", required=True, type=Path)
    parser.add_argument("--icons-dir", required=True, type=Path)
    parser.add_argument("--metadata-out", required=True, type=Path)
    parser.add_argument("--history-file", type=Path)
    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()
    if args.history_file is None:
        args.history_file = args.icons_dir / ".build_history.json"
    metadata = prepare_build(args)
    args.metadata_out.parent.mkdir(parents=True, exist_ok=True)
    args.metadata_out.write_text(json.dumps(metadata, ensure_ascii=False, indent=2), encoding="utf-8")
    print(json.dumps(metadata, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
