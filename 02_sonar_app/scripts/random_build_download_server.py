from __future__ import annotations

import html
import json
import os
import random
import re
import shutil
from dataclasses import dataclass
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, quote, urlparse


ROOT = Path(__file__).resolve().parents[1]
HOST = os.environ.get("SONAR_RANDOM_BUILD_HOST", "127.0.0.1")
PORT = int(os.environ.get("SONAR_RANDOM_BUILD_PORT", "8766"))
BUILDS_DIR = Path(os.environ.get("SONAR_RANDOM_BUILD_DIR", str(ROOT / "builds"))).resolve()
ACCESS_TOKEN = os.environ.get("SONAR_RANDOM_BUILD_TOKEN", "").strip()
ARCHIVE_NAME_RE = re.compile(r"^[0-9a-f]{64}-.+\.exe\.zip$", re.IGNORECASE)


@dataclass(frozen=True, slots=True)
class BuildArchive:
    path: Path

    @property
    def archive_name(self) -> str:
        return self.path.name


def iter_archive_files(builds_dir: Path = BUILDS_DIR) -> list[Path]:
    if not builds_dir.exists():
        return []
    return sorted(path for path in builds_dir.rglob("*.zip") if path.is_file() and is_build_archive(path))


def iter_invalid_archive_files(builds_dir: Path = BUILDS_DIR) -> list[Path]:
    if not builds_dir.exists():
        return []
    return sorted(path for path in builds_dir.rglob("*.zip") if path.is_file() and not is_build_archive(path))


def is_build_archive(path: Path) -> bool:
    return bool(ARCHIVE_NAME_RE.match(path.name))


def choose_build_archive(builds_dir: Path = BUILDS_DIR, rng: random.Random | None = None) -> BuildArchive:
    candidates = iter_archive_files(builds_dir)
    if not candidates:
        raise FileNotFoundError(f"No build .zip archives found in {builds_dir}")
    selected = (rng or random.SystemRandom()).choice(candidates)
    return BuildArchive(path=selected)


class RandomBuildHandler(BaseHTTPRequestHandler):
    server_version = "SonarRandomBuildDownload/1.0"

    def do_GET(self) -> None:  # noqa: N802
        parsed = urlparse(self.path)
        if parsed.path in {"/", "/download"}:
            self._send_html(download_page(token=self._token_from_query(parsed.query)))
            return
        if parsed.path in {"/health", "/random-build-health"}:
            self._send_json(
                {
                    "ok": True,
                    "builds_dir": str(BUILDS_DIR),
                    "archive_count": len(iter_archive_files()),
                    "invalid_archive_count": len(iter_invalid_archive_files()),
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
