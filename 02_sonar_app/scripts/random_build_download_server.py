from __future__ import annotations

import base64
import hashlib
import html
import json
import os
import random
import re
import shutil
import sys
from dataclasses import dataclass
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, quote, urlparse


ROOT = Path(__file__).resolve().parents[1]
SRC_DIR = ROOT / "src"
if str(SRC_DIR) not in sys.path:
    sys.path.insert(0, str(SRC_DIR))

try:
    from sonar.security.ed25519 import ed25519_sign  # noqa: E402
except ModuleNotFoundError:
    Q = 2**255 - 19
    L = 2**252 + 27742317777372353535851937790883648493
    D = -121665 * pow(121666, Q - 2, Q) % Q
    I = pow(2, (Q - 1) // 4, Q)

    def ed25519_sign(seed: bytes, message: bytes) -> bytes:
        if len(seed) != 32:
            raise ValueError("Ed25519 seed must be 32 bytes")
        digest = hashlib.sha512(seed).digest()
        secret = _clamp_scalar(digest[:32])
        prefix = digest[32:]
        public_key = _encode_point(_scalar_mult(_base_point(), secret))
        nonce = _sha512_mod_l(prefix + message)
        encoded_r = _encode_point(_scalar_mult(_base_point(), nonce))
        h = _sha512_mod_l(encoded_r + public_key + message)
        s = (nonce + h * secret) % L
        return encoded_r + s.to_bytes(32, "little")

    def _sha512_mod_l(data: bytes) -> int:
        return int.from_bytes(hashlib.sha512(data).digest(), "little") % L

    def _clamp_scalar(value: bytes) -> int:
        scalar = bytearray(value)
        scalar[0] &= 248
        scalar[31] &= 63
        scalar[31] |= 64
        return int.from_bytes(scalar, "little")

    def _base_point() -> tuple[int, int]:
        y = 4 * pow(5, Q - 2, Q) % Q
        return (_recover_x(y), y)

    def _recover_x(y: int) -> int:
        xx = (y * y - 1) * pow(D * y * y + 1, Q - 2, Q)
        x = pow(xx, (Q + 3) // 8, Q)
        if (x * x - xx) % Q != 0:
            x = (x * I) % Q
        if (x * x - xx) % Q != 0:
            raise ValueError("Invalid Ed25519 point")
        if x & 1:
            x = Q - x
        return x

    def _edwards_add(left: tuple[int, int], right: tuple[int, int]) -> tuple[int, int]:
        x1, y1 = left
        x2, y2 = right
        denominator_x = pow(1 + D * x1 * x2 * y1 * y2, Q - 2, Q)
        denominator_y = pow(1 - D * x1 * x2 * y1 * y2, Q - 2, Q)
        x3 = (x1 * y2 + x2 * y1) * denominator_x % Q
        y3 = (y1 * y2 + x1 * x2) * denominator_y % Q
        return x3, y3

    def _scalar_mult(point: tuple[int, int], scalar: int) -> tuple[int, int]:
        result = (0, 1)
        addend = point
        while scalar > 0:
            if scalar & 1:
                result = _edwards_add(result, addend)
            addend = _edwards_add(addend, addend)
            scalar >>= 1
        return result

    def _encode_point(point: tuple[int, int]) -> bytes:
        x, y = point
        encoded = bytearray(y.to_bytes(32, "little"))
        encoded[31] |= (x & 1) << 7
        return bytes(encoded)

HOST = os.environ.get("SONAR_RANDOM_BUILD_HOST", "127.0.0.1")
PORT = int(os.environ.get("SONAR_RANDOM_BUILD_PORT", "8766"))
BUILDS_DIR = Path(os.environ.get("SONAR_RANDOM_BUILD_DIR", str(ROOT / "builds"))).resolve()
ACCESS_TOKEN = os.environ.get("SONAR_RANDOM_BUILD_TOKEN", "").strip()
STARTUP_BLOCKLIST_PATH = Path(os.environ.get("SONAR_STARTUP_BLOCKLIST_PATH", str(ROOT / "startup-blocklist.json"))).resolve()
STARTUP_BLOCK_DOWNLOAD_URL = os.environ.get("SONAR_STARTUP_BLOCK_DOWNLOAD_URL", "https://m-sonar-addr.ru/download").strip()
STARTUP_BLOCK_PRIVATE_KEY = os.environ.get("SONAR_STARTUP_BLOCK_PRIVATE_KEY", "").strip()
ARCHIVE_NAME_RE = re.compile(r"^(?:[0-9a-f]{11}|[0-9a-f]{64})-.+\.exe\.zip$", re.IGNORECASE)
VERSION_DIR_RE = re.compile(r"^v?([0-9]+(?:\.[0-9]+){0,3})$")
MAX_STARTUP_BLOCK_REQUEST_BYTES = 16 * 1024


@dataclass(frozen=True, slots=True)
class BuildArchive:
    path: Path

    @property
    def archive_name(self) -> str:
        return self.path.name


@dataclass(frozen=True, slots=True)
class BuildVersion:
    version: str
    path: Path


@dataclass(frozen=True, slots=True)
class StartupBlockList:
    build_keys: frozenset[str]
    license_keys: frozenset[str]
    download_url: str


def normalize_version_name(value: str) -> str:
    match = VERSION_DIR_RE.match(value.strip())
    return match.group(1) if match else ""


def version_sort_key(value: str) -> tuple[int, int, int, int]:
    parts = [int(part) for part in normalize_version_name(value).split(".") if part != ""]
    while len(parts) < 4:
        parts.append(0)
    return tuple(parts[:4])


def iter_version_dirs(builds_dir: Path = BUILDS_DIR) -> list[BuildVersion]:
    if not builds_dir.exists():
        return []
    versions: list[BuildVersion] = []
    for path in builds_dir.iterdir():
        version = normalize_version_name(path.name)
        if path.is_dir() and version:
            versions.append(BuildVersion(version=version, path=path))
    return sorted(versions, key=lambda item: version_sort_key(item.version))


def latest_version_dir(builds_dir: Path = BUILDS_DIR) -> BuildVersion | None:
    versions = iter_version_dirs(builds_dir)
    return versions[-1] if versions else None


def selected_builds_dir(builds_dir: Path = BUILDS_DIR) -> Path:
    latest = latest_version_dir(builds_dir)
    return latest.path if latest else builds_dir


def iter_archive_files(builds_dir: Path = BUILDS_DIR) -> list[Path]:
    active_dir = selected_builds_dir(builds_dir)
    if not active_dir.exists():
        return []
    return sorted(path for path in active_dir.rglob("*.zip") if path.is_file() and is_build_archive(path))


def iter_invalid_archive_files(builds_dir: Path = BUILDS_DIR) -> list[Path]:
    active_dir = selected_builds_dir(builds_dir)
    if not active_dir.exists():
        return []
    return sorted(path for path in active_dir.rglob("*.zip") if path.is_file() and not is_build_archive(path))


def iter_all_archive_files(builds_dir: Path = BUILDS_DIR) -> list[Path]:
    if not builds_dir.exists():
        return []
    return sorted(path for path in builds_dir.rglob("*.zip") if path.is_file() and is_build_archive(path))


def is_build_archive(path: Path) -> bool:
    return bool(ARCHIVE_NAME_RE.match(path.name))


def choose_build_archive(builds_dir: Path = BUILDS_DIR, rng: random.Random | None = None) -> BuildArchive:
    candidates = iter_archive_files(builds_dir)
    if not candidates:
        raise FileNotFoundError(f"No build .zip archives found in {selected_builds_dir(builds_dir)}")
    selected = (rng or random.SystemRandom()).choice(candidates)
    return BuildArchive(path=selected)


def load_startup_blocklist(path: Path = STARTUP_BLOCKLIST_PATH) -> StartupBlockList:
    if not path.exists():
        return StartupBlockList(frozenset(), frozenset(), STARTUP_BLOCK_DOWNLOAD_URL)
    body = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(body, dict):
        raise ValueError("Startup blocklist must be a JSON object")
    build_keys = frozenset(
        key.lower()
        for key in _string_values(body.get("build_keys") or body.get("blocked_build_keys"))
        if key
    )
    license_keys = frozenset(
        key
        for key in _string_values(body.get("license_keys") or body.get("blocked_license_keys"))
        if key
    )
    download_url = str(body.get("download_url") or body.get("download_link") or STARTUP_BLOCK_DOWNLOAD_URL).strip()
    return StartupBlockList(build_keys=build_keys, license_keys=license_keys, download_url=download_url)


def is_startup_blocked(request_payload: dict[str, object], blocklist: StartupBlockList) -> bool:
    build_key = str(request_payload.get("build_key") or "").strip().lower()
    license_key = str(request_payload.get("license_key") or "").strip()
    return bool((build_key and build_key in blocklist.build_keys) or (license_key and license_key in blocklist.license_keys))


def signed_startup_block_response(*, blocked: bool, download_url: str, private_key_seed: bytes) -> dict[str, object]:
    payload = {"blocked": bool(blocked), "download_url": download_url.strip() if blocked else ""}
    signature = ed25519_sign(private_key_seed, canonical_startup_block_payload(payload))
    return {**payload, "signature": encode_base64url(signature)}


def canonical_startup_block_payload(payload: dict[str, object]) -> bytes:
    return json.dumps(payload, ensure_ascii=False, separators=(",", ":"), sort_keys=True).encode("utf-8")


def decode_private_key_seed(value: str) -> bytes:
    text = value.strip()
    if not text:
        raise ValueError("Startup block private key is not configured")
    if len(text) in {64, 128} and all(character in "0123456789abcdefABCDEF" for character in text):
        data = bytes.fromhex(text)
    else:
        data = decode_base64url(text)
    if len(data) == 64:
        data = data[:32]
    if len(data) != 32:
        raise ValueError("Startup block private key seed must be 32 bytes")
    return data


def decode_base64url(value: str) -> bytes:
    padding = "=" * (-len(value) % 4)
    return base64.urlsafe_b64decode(value + padding)


def encode_base64url(value: bytes) -> str:
    return base64.urlsafe_b64encode(value).decode("ascii").rstrip("=")


def _string_values(value: object) -> list[str]:
    if value is None:
        return []
    if isinstance(value, str):
        return [item.strip() for item in value.replace(";", ",").split(",") if item.strip()]
    if isinstance(value, list):
        return [str(item).strip() for item in value if str(item).strip()]
    return []


class RandomBuildHandler(BaseHTTPRequestHandler):
    server_version = "SonarRandomBuildDownload/1.0"

    def do_GET(self) -> None:  # noqa: N802
        parsed = urlparse(self.path)
        if parsed.path == "/api/startup-block":
            self._send_json({"error": "method not allowed"}, HTTPStatus.METHOD_NOT_ALLOWED)
            return
        if parsed.path in {"/", "/download"}:
            self._send_html(download_page(token=self._token_from_query(parsed.query)))
            return
        if parsed.path in {"/health", "/random-build-health"}:
            latest = latest_version_dir()
            active_dir = selected_builds_dir()
            self._send_json(
                {
                    "ok": True,
                    "builds_dir": str(BUILDS_DIR),
                    "latest_version": latest.version if latest else "",
                    "latest_builds_dir": str(active_dir),
                    "version_count": len(iter_version_dirs()),
                    "archive_count": len(iter_archive_files()),
                    "invalid_archive_count": len(iter_invalid_archive_files()),
                    "total_archive_count": len(iter_all_archive_files()),
                }
            )
            return
        if parsed.path == "/api/random-build.zip":
            if not self._authorized(parsed.query):
                self._send_json({"error": "unauthorized"}, HTTPStatus.UNAUTHORIZED)
                return
            self._send_random_archive()
            return
        self._send_json({"error": "not found"}, HTTPStatus.NOT_FOUND)

    def do_POST(self) -> None:  # noqa: N802
        parsed = urlparse(self.path)
        if parsed.path != "/api/startup-block":
            self._send_json({"error": "not found"}, HTTPStatus.NOT_FOUND)
            return
        self._send_startup_block_response()

    def log_message(self, format: str, *args: object) -> None:
        print(f"{self.address_string()} - {format % args}")

    def _send_random_archive(self) -> None:
        try:
            archive = choose_build_archive()
            size = archive.path.stat().st_size
            download_name = archive.archive_name
            self.send_response(HTTPStatus.OK)
            self.send_header("Content-Type", "application/zip")
            self.send_header("Content-Length", str(size))
            self.send_header(
                "Content-Disposition",
                f"attachment; filename=\"download.zip\"; filename*=UTF-8''{quote(download_name)}",
            )
            self.send_header("Cache-Control", "no-store")
            self.end_headers()
            with archive.path.open("rb") as file:
                shutil.copyfileobj(file, self.wfile, length=1024 * 1024)
        except FileNotFoundError as exc:
            self._send_json({"error": str(exc)}, HTTPStatus.SERVICE_UNAVAILABLE)

    def _send_startup_block_response(self) -> None:
        try:
            private_key_seed = decode_private_key_seed(STARTUP_BLOCK_PRIVATE_KEY)
        except ValueError as exc:
            self._send_json({"error": str(exc)}, HTTPStatus.SERVICE_UNAVAILABLE)
            return
        try:
            request_payload = self._read_json_body()
            blocklist = load_startup_blocklist()
            blocked = is_startup_blocked(request_payload, blocklist)
            download_url = blocklist.download_url if blocked else ""
            if blocked and not download_url:
                self._send_json({"error": "download URL is not configured"}, HTTPStatus.SERVICE_UNAVAILABLE)
                return
            self._send_json(
                signed_startup_block_response(
                    blocked=blocked,
                    download_url=download_url,
                    private_key_seed=private_key_seed,
                )
            )
        except ValueError as exc:
            self._send_json({"error": str(exc)}, HTTPStatus.BAD_REQUEST)
        except OSError as exc:
            self._send_json({"error": str(exc)}, HTTPStatus.SERVICE_UNAVAILABLE)

    def _read_json_body(self) -> dict[str, object]:
        try:
            length = int(self.headers.get("Content-Length", "0"))
        except ValueError as exc:
            raise ValueError("Invalid Content-Length") from exc
        if length <= 0:
            raise ValueError("Request body is required")
        if length > MAX_STARTUP_BLOCK_REQUEST_BYTES:
            raise ValueError("Request body is too large")
        raw = self.rfile.read(length)
        try:
            body = json.loads(raw.decode("utf-8"))
        except (UnicodeDecodeError, json.JSONDecodeError) as exc:
            raise ValueError("Request body must be valid JSON") from exc
        if not isinstance(body, dict):
            raise ValueError("Request body must be a JSON object")
        return body

    def _authorized(self, query: str) -> bool:
        if not ACCESS_TOKEN:
            return True
        query_token = self._token_from_query(query)
        header_token = self.headers.get("X-Sonar-Random-Build-Token", "").strip()
        return ACCESS_TOKEN in {query_token, header_token}

    @staticmethod
    def _token_from_query(query: str) -> str:
        return (parse_qs(query).get("token") or [""])[0].strip()

    def _send_json(self, payload: dict[str, object], status: HTTPStatus = HTTPStatus.OK) -> None:
        data = json.dumps(payload, ensure_ascii=False).encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(data)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(data)

    def _send_html(self, value: str) -> None:
        data = value.encode("utf-8")
        self.send_response(HTTPStatus.OK)
        self.send_header("Content-Type", "text/html; charset=utf-8")
        self.send_header("Content-Length", str(len(data)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(data)


def download_page(*, token: str) -> str:
    url = "/api/random-build.zip"
    if token:
        url = f"{url}?token={quote(token)}"
    escaped_url = html.escape(url, quote=True)
    return f"""<!doctype html>
<html lang="ru">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>Загрузка Sonar</title>
  <style>
    :root {{ font-family: Inter, Segoe UI, Arial, sans-serif; color: #17203c; background: #f4f8ff; }}
    body {{ margin: 0; min-height: 100vh; display: grid; place-items: center; padding: 24px; }}
    main {{ width: min(560px, 100%); background: rgba(255,255,255,.94); border: 1px solid rgba(205,218,238,.9); border-radius: 8px; box-shadow: 0 24px 80px rgba(23,32,60,.14); padding: 22px; }}
    h1 {{ margin: 0 0 8px; font-size: 24px; }}
    p {{ margin: 0; color: #5c6782; line-height: 1.5; }}
    .row {{ display: flex; gap: 12px; align-items: center; margin-top: 18px; }}
    .spinner {{ width: 22px; height: 22px; border: 3px solid #dbe7ff; border-top-color: #1677ff; border-radius: 50%; animation: spin .9s linear infinite; }}
    a {{ color: #1677ff; font-weight: 800; }}
    @keyframes spin {{ to {{ transform: rotate(360deg); }} }}
  </style>
</head>
<body>
  <main>
    <h1>Подготовка загрузки</h1>
    <p>Выбираем случайную сборку из доступных архивов. Загрузка начнется автоматически.</p>
    <div class="row"><div class="spinner"></div><a id="manual" href="{escaped_url}">Скачать вручную</a></div>
  </main>
  <script>
    setTimeout(() => {{ window.location.href = "{escaped_url}"; }}, 500);
  </script>
</body>
</html>"""


def main() -> int:
    BUILDS_DIR.mkdir(parents=True, exist_ok=True)
    server = ThreadingHTTPServer((HOST, PORT), RandomBuildHandler)
    print(f"Sonar random build downloads listening on http://{HOST}:{PORT}")
    print(f"Build archives directory: {BUILDS_DIR}")
    server.serve_forever()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
