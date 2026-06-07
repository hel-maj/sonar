from __future__ import annotations

import argparse
import base64
import hashlib
import json
import os
import re
import random
import secrets
import unicodedata
from pathlib import Path
from typing import Any

from PIL import Image


ROOT = Path(__file__).resolve().parents[1]


def _dotenv_paths() -> list[Path]:
    explicit = os.environ.get("SONAR_DOTENV_PATH", "").strip()
    if explicit:
        return [Path(explicit)]
    return [ROOT.parent / ".env", ROOT / ".env"]


def _parse_dotenv(path: Path) -> dict[str, str]:
    try:
        lines = path.read_text(encoding="utf-8").splitlines()
    except OSError:
        return {}
    values: dict[str, str] = {}
    for line in lines:
        stripped = line.strip()
        if not stripped or stripped.startswith("#"):
            continue
        if stripped.startswith("export "):
            stripped = stripped[7:].lstrip()
        if "=" not in stripped:
            continue
        key, value = stripped.split("=", 1)
        key = key.strip()
        if not re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", key):
            continue
        value = value.strip()
        if len(value) >= 2 and value[0] == value[-1] and value[0] in {"'", '"'}:
            value = value[1:-1]
        else:
            value = value.split(" #", 1)[0].strip()
        values[key] = value
    return values


def load_dotenv() -> None:
    values: dict[str, str] = {}
    for path in _dotenv_paths():
        values.update(_parse_dotenv(path))
    for key, value in values.items():
        os.environ.setdefault(key, value)


load_dotenv()


MIN_SALT_BYTES = 100 * 1024
MAX_SALT_BYTES = 50 * 1024 * 1024
BUILD_KEY_LENGTH = 11
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
BUILD_ARCHIVE_NAME_RE = re.compile(r"^(?:[0-9a-f]{11}|[0-9a-f]{64})-(.+?)(?:\.exe)?\.zip$", re.IGNORECASE)
VERSION_DIR_RE = re.compile(r"^v?[0-9]+(?:\.[0-9]+){0,3}$")
DEFAULT_LICENSE_SERVER_URL = "https://updates.example.invalid"
DEFAULT_STARTUP_BLOCK_URL = "https://m-sonar-addr.ru/api/startup-block"
DEFAULT_STARTUP_BLOCK_PUBLIC_KEY = "8fdff2bf7962162273a0e97a1ed1c3375c9fd8d174f531143dc6866f49007874"
RUNTIME_LITERAL_VALUES = {
    "license_server_url": DEFAULT_LICENSE_SERVER_URL,
    "license_account_id": "",
    "startup_block_url": DEFAULT_STARTUP_BLOCK_URL,
    "startup_block_public_key": DEFAULT_STARTUP_BLOCK_PUBLIC_KEY,
    "public_ip_services": [
        "https://api.ipify.org",
        "https://ifconfig.me/ip",
        "https://ident.me",
        "https://icanhazip.com",
        "https://ipinfo.io/ip",
    ],
    "telegram_api_base": "https://api.telegram.org",
    "ffmpeg_download_url": "https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.zip",
    "cloudflared_download_url": "https://github.com/cloudflare/cloudflared/releases/latest/download/cloudflared-windows-amd64.exe",
    "gta_process_name": "gta5.exe",
    "memory_reeling": {
        "pos_offsets": [0x50, 0x40, 0x60, 0x30],
        "fish_pos_offsets": [0x130, 0x120, 0x90, 0x110, 0x160],
        "fish_primary_direction_offsets": [0x304, 0x68, 0x300, 0x70],
        "fish_direction_source_rank": [[0x304, 0], [0x68, 1], [0x300, 2], [0x70, 3]],
        "fish_direction_anchor_offset": 0x68,
        "fish_direction_fields": [
            [0x304, 0.08, 1.0],
            [0x68, 0.0012, 1.0],
            [0x300, 0.08, 1.0],
            [0x70, 0.08, 1.0],
            [0x80, 0.08, -1.0],
            [0x64, 0.08, -1.0],
            [0x314, 0.08, -1.0],
        ],
        "fish_direction_adaptive_fields": [
            [0x304, 0.68, 0.4],
            [0x300, 0.68, 0.75],
            [0x70, 0.68, 0.75],
            [0x80, 0.25, 0.9],
            [0x64, 0.68, 0.75],
            [0x314, 1.36, 0.25],
        ],
        "replay_patterns": [
            [[72, 139, 5, None, None, None, None, 72, 139, 72, 8, 72, 133, 201], 3, 7, [8]],
            [[72, 139, 5, None, None, None, None, 243, 15, 16, 80], 3, 7, [8, 16]],
            [[72, 139, 5, None, None, None, None, 72, 133, 192], 3, 7, [8, 16, 24]],
            [[72, 139, 13, None, None, None, None, 72, 133, 201], 3, 7, [8]],
            [[72, 139, 5, None, None, None, None, 51, 255], 3, 7, [8]],
        ],
        "cped_pattern": [
            72,
            141,
            13,
            None,
            None,
            None,
            None,
            72,
            139,
            215,
            232,
            None,
            None,
            None,
            None,
            72,
            141,
            13,
            None,
            None,
            None,
            None,
            138,
            216,
            232,
            None,
            None,
            None,
            None,
            132,
            219,
            117,
            19,
            72,
            141,
            13,
        ],
    },
    "player_status": {
        "webengine_process_name": "majestic-webengine.exe",
        "webengine_markers": [
            "inventory/indicators/v2/health.svg",
            "inventory-interface full-width full-height router-view",
            "weight__text-current",
        ],
    },
}


MOJIBAKE_MARKERS = (
    "вЂ",
    "в„",
    "В®",
    "В©",
    "Рђ",
    "РЃ",
    "Р°",
    "Рё",
    "РЅ",
    "Рѕ",
    "Рќ",
    "Рћ",
    "РЎ",
    "Р”",
    "РІ",
    "С‚",
    "СЊ",
    "СЃ",
    "С‡",
    "С‚Р”РІ",
    "тДв",
    "â",
    "Â",
    "Ã",
    "Ð",
    "Ñ",
)
MOJIBAKE_ENCODINGS = ("cp1251", "cp866", "latin1")


def mojibake_score(value: str) -> int:
    return sum(value.count(marker) for marker in MOJIBAKE_MARKERS)


def repair_mojibake(value: str) -> str:
    current = value
    current_score = mojibake_score(current)
    for _ in range(3):
        best = current
        best_score = current_score
        for encoding in MOJIBAKE_ENCODINGS:
            try:
                candidate = current.encode(encoding).decode("utf-8")
            except UnicodeError:
                continue
            candidate_score = mojibake_score(candidate)
            if candidate_score < best_score:
                best = candidate
                best_score = candidate_score
        if best == current:
            break
        current = best
        current_score = best_score
    return current


def sanitize_windows_stem(value: str) -> str:
    normalized = unicodedata.normalize("NFC", repair_mojibake(value))
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


def write_metadata_json(path: Path, metadata: dict[str, Any]) -> None:
    path.write_text(json.dumps(metadata, ensure_ascii=True, indent=2), encoding="utf-8")


def load_history(path: Path) -> list[str]:
    try:
        raw = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return []
    used = raw.get("used", raw) if isinstance(raw, dict) else raw
    return [str(item) for item in used] if isinstance(used, list) else []


def save_history(path: Path, used: list[str]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps({"used": used}, ensure_ascii=False, indent=2), encoding="utf-8")


def assert_png_loads(path: Path) -> None:
    with Image.open(path) as image:
        image.verify()


def readable_icons(icons_dir: Path) -> list[Path]:
    icons: list[Path] = []
    for icon_path in sorted(path for path in icons_dir.glob("*.png") if path.is_file()):
        try:
            assert_png_loads(icon_path)
        except Exception:
            continue
        icons.append(icon_path)
    if not icons:
        raise SystemExit(f"No readable PNG icons found in {icons_dir}")
    return icons


def app_name_from_icon(icon_path: Path) -> str:
    return sanitize_windows_stem(icon_path.stem)


def remember_icon(history_file: Path, icon_name: str, *, use_history: bool) -> None:
    if not use_history:
        return
    history = load_history(history_file)
    if icon_name not in history:
        history.append(icon_name)
        save_history(history_file, history)


def choose_icon(
    icons_dir: Path,
    history_file: Path,
    rng: random.Random,
    *,
    use_history: bool,
    icon_name: str = "",
) -> Path:
    icons = readable_icons(icons_dir)
    if icon_name:
        requested = next((path for path in icons if path.name == icon_name), None)
        if requested is None:
            raise SystemExit(f"Planned icon {icon_name!r} was not found in {icons_dir}")
        remember_icon(history_file, requested.name, use_history=use_history)
        return requested

    history = load_history(history_file) if use_history else []
    history_names = {str(item) for item in history}
    shuffled = icons[:]
    rng.shuffle(shuffled)
    for icon_path in shuffled:
        if use_history and icon_path.name in history_names:
            continue
        remember_icon(history_file, icon_path.name, use_history=use_history)
        return icon_path

    rng.shuffle(shuffled)
    icon_path = shuffled[0]
    remember_icon(history_file, icon_path.name, use_history=use_history)
    return icon_path


def archive_build_name(path: Path) -> str:
    match = BUILD_ARCHIVE_NAME_RE.match(path.name)
    if not match:
        return ""
    return sanitize_windows_stem(match.group(1))


def existing_build_names(builds_dir: Path | None) -> set[str]:
    if builds_dir is None or not builds_dir.exists():
        return set()
    names: set[str] = set()
    for archive in builds_dir.rglob("*.zip"):
        name = archive_build_name(archive)
        if name:
            names.add(name.casefold())
    for executable in builds_dir.rglob("*.exe"):
        names.add(sanitize_windows_stem(executable.stem).casefold())
    return names


def icon_groups_by_name(icons_dir: Path) -> dict[str, list[Path]]:
    groups: dict[str, list[Path]] = {}
    for icon_path in readable_icons(icons_dir):
        groups.setdefault(app_name_from_icon(icon_path), []).append(icon_path)
    return groups


def build_name_plan(
    icons_dir: Path,
    history_file: Path,
    count: int,
    rng: random.Random,
    *,
    existing_dir: Path | None = None,
    use_history: bool = True,
) -> list[dict[str, str]]:
    if count < 1:
        raise SystemExit("Plan count must be greater than zero")
    groups = icon_groups_by_name(icons_dir)
    all_names = sorted(groups)
    existing_names = existing_build_names(existing_dir)
    history_names = {app_name_from_icon(Path(item)).casefold() for item in load_history(history_file)} if use_history else set()
    cycle_used: set[str] = set()
    plan: list[dict[str, str]] = []

    def candidates(*, block_existing: bool, block_history: bool) -> list[str]:
        blocked = set(cycle_used)
        if block_existing:
            blocked.update(existing_names)
        if block_history:
            blocked.update(history_names)
        return [name for name in all_names if name.casefold() not in blocked]

    while len(plan) < count:
        batch = candidates(block_existing=True, block_history=True)
        if not batch:
            batch = candidates(block_existing=True, block_history=False)
        if not batch:
            cycle_used.clear()
            batch = candidates(block_existing=True, block_history=True)
        if not batch:
            batch = candidates(block_existing=True, block_history=False)
        if not batch:
            batch = candidates(block_existing=False, block_history=True)
        if not batch:
            batch = candidates(block_existing=False, block_history=False)
        if not batch:
            raise SystemExit(f"No PNG icons found in {icons_dir}")

        rng.shuffle(batch)
        for app_name in batch:
            icons = groups[app_name][:]
            rng.shuffle(icons)
            icon_path = icons[0]
            plan.append({"icon_name": icon_path.name, "app_name": app_name, "exe_name": f"{app_name}.exe"})
            cycle_used.add(app_name.casefold())
            if len(plan) >= count:
                break
    return plan


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


def write_build_metadata(
    source_root: Path,
    app_name: str,
    icon_source: Path,
    build_hash: str,
    build_key: str,
    obfuscation_seed: str,
) -> Path:
    metadata_path = source_root / "sonar" / "build_metadata.py"
    metadata_path.write_text(
        "\n".join(
            [
                "from __future__ import annotations",
                "",
                f"APP_NAME = {app_name!r}",
                f"APP_ICON_SOURCE = {icon_source.name!r}",
                f"APP_BUILD_HASH = {build_hash!r}",
                f"APP_BUILD_KEY = {build_key!r}",
                f"APP_OBFUSCATION_SEED = {obfuscation_seed!r}",
                "",
            ]
        ),
        encoding="utf-8",
    )
    return metadata_path


def runtime_literal_values(args: argparse.Namespace) -> dict[str, Any]:
    values = dict(RUNTIME_LITERAL_VALUES)
    license_server_url = (getattr(args, "license_server_url", "") or os.environ.get("SONAR_LICENSE_SERVER_URL") or "").strip()
    license_account_id = (getattr(args, "license_account_id", "") or os.environ.get("SONAR_LICENSE_ACCOUNT_ID") or "").strip()
    startup_block_url = (getattr(args, "startup_block_url", "") or os.environ.get("SONAR_STARTUP_BLOCK_URL") or "").strip()
    startup_block_public_key = (
        getattr(args, "startup_block_public_key", "") or os.environ.get("SONAR_STARTUP_BLOCK_PUBLIC_KEY") or ""
    ).strip()
    if license_server_url:
        values["license_server_url"] = license_server_url.rstrip("/")
    if license_account_id:
        values["license_account_id"] = license_account_id
    if startup_block_url:
        values["startup_block_url"] = startup_block_url
    if startup_block_public_key:
        values["startup_block_public_key"] = startup_block_public_key
    return values


def write_runtime_literals(source_root: Path, build_key: str, rng: random.Random, values: dict[str, Any]) -> Path:
    literals_path = source_root / "sonar" / "security" / "literals.py"
    encrypted: dict[str, str] = {}
    for name, value in values.items():
        if isinstance(value, str):
            plain = value
        else:
            plain = json.dumps(value, ensure_ascii=False, separators=(",", ":"))
        encrypted[name] = encrypt_literal(plain, build_key, random_bytes(rng, 16))
    body = [
        "from __future__ import annotations",
        "",
        "",
        "ENCRYPTED_LITERALS = {",
    ]
    for name, token in encrypted.items():
        body.append(f"    {name!r}: {token!r},")
    body.extend(["}", ""])
    literals_path.write_text("\n".join(body), encoding="utf-8")
    return literals_path


def random_bytes(rng: random.Random, size: int) -> bytes:
    return bytes(rng.getrandbits(8) for _ in range(size))


def random_hex(rng: random.Random, size: int) -> str:
    return random_bytes(rng, size).hex()


def random_hex_chars(rng: random.Random, length: int) -> str:
    return "".join(f"{rng.randrange(16):x}" for _ in range(length))


def encrypt_literal(plain: str, build_key: str, salt: bytes) -> str:
    payload = plain.encode("utf-8")
    stream = key_stream(build_key, salt, len(payload))
    cipher = bytes(value ^ stream[index] for index, value in enumerate(payload))
    return base64.urlsafe_b64encode(salt + cipher).decode("ascii").rstrip("=")


def key_stream(build_key: str, salt: bytes, size: int) -> bytes:
    key = hashlib.sha256(b"SonarRuntimeKey:v1\0" + build_key.encode("utf-8")).digest()
    out = bytearray()
    counter = 0
    while len(out) < size:
        out.extend(
            hashlib.sha256(
                b"SonarRuntimeStream:v1\0" + key + salt + counter.to_bytes(4, "big")
            ).digest()
        )
        counter += 1
    return bytes(out[:size])


def write_salt(path: Path, rng: random.Random) -> int:
    path.parent.mkdir(parents=True, exist_ok=True)
    size = MIN_SALT_BYTES + rng.randrange(MAX_SALT_BYTES - MIN_SALT_BYTES + 1)
    remaining = size
    with path.open("wb") as file:
        while remaining:
            chunk_size = min(remaining, 1024 * 1024)
            file.write(random_bytes(rng, chunk_size))
            remaining -= chunk_size
    return size


def prepare_build(args: argparse.Namespace) -> dict[str, Any]:
    source_root = args.source_root.resolve()
    resources_dir = source_root / "sonar" / "resources"
    obfuscation_seed = args.seed or secrets.token_hex(16)
    rng = random.Random(obfuscation_seed)
    icon_png = choose_icon(
        args.icons_dir.resolve(),
        args.history_file.resolve(),
        rng,
        use_history=not bool(args.seed),
        icon_name=(getattr(args, "icon_name", "") or ""),
    )
    app_name = app_name_from_icon(icon_png)
    build_hash = random_hex(rng, 16)
    build_key = args.build_key or random_hex_chars(rng, BUILD_KEY_LENGTH)
    icon_ico = resources_dir / "app.ico"
    salt_path = resources_dir / "build_salt.bin"

    write_ico(icon_png, icon_ico)
    metadata_path = write_build_metadata(source_root, app_name, icon_png, build_hash, build_key, obfuscation_seed)
    literals_path = write_runtime_literals(source_root, build_key, rng, runtime_literal_values(args))
    salt_bytes = write_salt(salt_path, rng)

    return {
        "app_name": app_name,
        "exe_name": f"{app_name}.exe",
        "build_hash": build_hash,
        "build_key": build_key,
        "obfuscation_seed": obfuscation_seed,
        "icon_png": str(icon_png),
        "icon_ico": str(icon_ico),
        "metadata_path": str(metadata_path),
        "literals_path": str(literals_path),
        "salt_path": str(salt_path),
        "salt_bytes": salt_bytes,
    }


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Prepare per-build executable branding.")
    parser.add_argument("--source-root", required=True, type=Path)
    parser.add_argument("--icons-dir", required=True, type=Path)
    parser.add_argument("--metadata-out", required=True, type=Path)
    parser.add_argument("--history-file", type=Path)
    parser.add_argument("--icon-name", default="", help="Planned PNG icon file name for this build.")
    parser.add_argument("--plan-count", type=int, default=0, help="Create a shuffled build name plan instead of preparing one build.")
    parser.add_argument("--plan-out", type=Path, help="Path for the planned build name array JSON.")
    parser.add_argument("--existing-builds-dir", type=Path, help="Existing builds folder used to avoid already occupied names.")
    parser.add_argument("--seed", default="", help="Deterministic obfuscation seed for reproducible release builds.")
    parser.add_argument("--build-key", default="", help="Existing build key for a reproducible rebuild.")
    parser.add_argument("--license-server-url", default="", help="Public neutral license/update base URL for this build.")
    parser.add_argument("--license-account-id", default="", help="Optional Keygen account id override for this build.")
    parser.add_argument("--startup-block-url", default="", help="Independent signed startup block check URL for this build.")
    parser.add_argument("--startup-block-public-key", default="", help="Ed25519 public key for signed startup block responses.")
    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()
    if args.history_file is None:
        args.history_file = args.icons_dir / ".build_history.json"
    if args.plan_count:
        if args.plan_out is None:
            parser.error("--plan-out is required with --plan-count")
        rng = random.Random(args.seed or secrets.token_hex(16))
        plan = build_name_plan(
            args.icons_dir.resolve(),
            args.history_file.resolve(),
            args.plan_count,
            rng,
            existing_dir=args.existing_builds_dir.resolve() if args.existing_builds_dir else None,
            use_history=not bool(args.seed),
        )
        args.plan_out.parent.mkdir(parents=True, exist_ok=True)
        args.plan_out.write_text(json.dumps(plan, ensure_ascii=True, indent=2), encoding="utf-8")
        print(json.dumps(plan, ensure_ascii=True))
        return 0

    metadata = prepare_build(args)
    args.metadata_out.parent.mkdir(parents=True, exist_ok=True)
    write_metadata_json(args.metadata_out, metadata)
    print(json.dumps(metadata, ensure_ascii=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
