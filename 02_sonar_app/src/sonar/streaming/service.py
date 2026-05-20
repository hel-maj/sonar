from __future__ import annotations

import atexit
import json
import os
import re
import shutil
import subprocess
import tempfile
import threading
import time
import uuid
import urllib.error
import urllib.request
import zipfile
from dataclasses import asdict, dataclass
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Callable
from urllib.parse import urlparse

from sonar.paths import CONFIG_DIR, PROJECT_DIR, RESOURCE_DIR


VIEWER_TIMEOUT_SECONDS = 180.0
STREAM_TEMP_PREFIX = "sonar-stream-"
CLOUDFLARED_URL_RE = re.compile(r"https://[a-z0-9-]+\.trycloudflare\.com", re.IGNORECASE)
STREAMING_RESOURCE_DIR = RESOURCE_DIR / "streaming"
STREAMING_CACHE_DIR = CONFIG_DIR / "streaming"
LEGACY_STREAMING_CACHE_DIR = PROJECT_DIR / "02_sonar_app" / "config" / "streaming"
FFMPEG_DOWNLOAD_URL = "https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.zip"
CLOUDFLARED_DOWNLOAD_URL = "https://github.com/cloudflare/cloudflared/releases/latest/download/cloudflared-windows-amd64.exe"
DOWNLOAD_TIMEOUT_SECONDS = 180.0
HLS_READY_TIMEOUT_SECONDS = 15.0
HLS_READY_POLL_SECONDS = 0.1


@dataclass(frozen=True, slots=True)
class StreamQuality:
    name: str
    height: int
    bitrate: str


STREAM_QUALITIES: dict[str, StreamQuality] = {
    "480p": StreamQuality("480p", 480, "1400k"),
    "720p": StreamQuality("720p", 720, "3200k"),
    "1080p": StreamQuality("1080p", 1080, "5800k"),
}


@dataclass(frozen=True, slots=True)
class StreamSnapshot:
    active: bool
    status: str
    quality: str
    area: str
    chat_zoom_enabled: bool
    chat_mode_enabled: bool
    local_url: str | None
    public_url: str | None
    stream_url: str | None
    hls_url: str | None
    started_at: float | None
    last_viewer_activity_at: float | None
    seconds_until_auto_stop: int | None
    error: str


STREAM_PAGE_HTML = r"""<!doctype html>
<html lang="ru">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>Стрим игры</title>
  <link href="https://vjs.zencdn.net/8.16.1/video-js.css" rel="stylesheet" />
  <style>
    :root {
      color-scheme: dark;
      font-family: Inter, Roboto, Arial, sans-serif;
      background: #0d1117;
      color: #f4f7fb;
    }
    * { box-sizing: border-box; }
    body {
      margin: 0;
      min-height: 100vh;
      background:
        radial-gradient(circle at 18% 12%, rgba(43, 110, 255, 0.20), transparent 28%),
        linear-gradient(135deg, #0d1117 0%, #151a22 56%, #101316 100%);
    }
    #root { min-height: 100vh; }
    .page {
      display: grid;
      grid-template-columns: minmax(0, 1fr) 340px;
      gap: 18px;
      min-height: 100vh;
      padding: 18px;
    }
    .playerShell {
      min-width: 0;
      align-self: stretch;
      display: flex;
      flex-direction: column;
    }
    .video-js {
      width: 100%;
      height: calc(100vh - 36px);
      border-radius: 8px;
      overflow: hidden;
      background: #05070a;
      box-shadow: 0 18px 60px rgba(0, 0, 0, 0.42);
    }
    .side {
      align-self: start;
      border: 1px solid rgba(255, 255, 255, 0.10);
      border-radius: 8px;
      background: rgba(20, 25, 32, 0.88);
      padding: 18px;
      backdrop-filter: blur(12px);
    }
    .statusGrid {
      display: grid;
      grid-template-columns: 1fr 1fr;
      gap: 10px;
      margin: 16px 0;
    }
    .metric {
      border: 1px solid rgba(255, 255, 255, 0.08);
      border-radius: 8px;
      padding: 10px;
      background: rgba(255, 255, 255, 0.04);
    }
    .metricLabel {
      color: #9ca8b7;
      font-size: 12px;
      margin-bottom: 3px;
    }
    .metricValue {
      font-weight: 700;
      font-size: 15px;
    }
    .comment {
      color: #aab4c2;
      font-size: 13px;
      margin-top: 6px;
    }
    @media (max-width: 900px) {
      .page {
        grid-template-columns: 1fr;
        padding: 10px;
      }
      .video-js {
        height: 58vh;
      }
      .side {
        align-self: stretch;
      }
    }
  </style>
</head>
<body>
  <div id="root"></div>
  <script src="https://unpkg.com/react@18/umd/react.production.min.js"></script>
  <script src="https://unpkg.com/react-dom@18/umd/react-dom.production.min.js"></script>
  <script src="https://unpkg.com/@mui/material@5.15.20/umd/material-ui.production.min.js"></script>
  <script src="https://vjs.zencdn.net/8.16.1/video.min.js"></script>
  <script>
    const { useEffect, useMemo, useRef, useState } = React;
    const {
      Button,
      Chip,
      Divider,
      FormControlLabel,
      Stack,
      Switch,
      TextField,
      Typography,
    } = MaterialUI;

    function formatStatus(status) {
      if (status === "online") return "online";
      if (status === "starting") return "запуск";
      if (status === "error") return "ошибка";
      return "offline";
    }

    function App() {
      const videoRef = useRef(null);
      const playerRef = useRef(null);
      const sourceKeyRef = useRef("");
      const [status, setStatus] = useState(null);
      const [busy, setBusy] = useState(false);

      async function refresh() {
        const response = await fetch("/api/stream/status", { cache: "no-store" });
        setStatus(await response.json());
      }

      useEffect(() => {
        refresh();
        const refreshTimer = setInterval(refresh, 3000);
        const heartbeatTimer = setInterval(() => {
          fetch("/api/stream/viewer-heartbeat", { method: "POST" }).then(refresh).catch(() => {});
        }, 10000);
        fetch("/api/stream/viewer-heartbeat", { method: "POST" }).catch(() => {});
        return () => {
          clearInterval(refreshTimer);
          clearInterval(heartbeatTimer);
        };
      }, []);

      useEffect(() => {
        if (!videoRef.current || playerRef.current) return;
        playerRef.current = videojs(videoRef.current, {
          autoplay: true,
          controls: true,
          liveui: true,
          fluid: false,
          sources: [{ src: "/hls/live.m3u8", type: "application/x-mpegURL" }],
          html5: {
            vhs: {
              liveRangeSafeTimeDelta: 12,
              smoothQualityChange: true,
            },
          },
          liveTracker: {
            trackingThreshold: 12,
            liveTolerance: 12,
          },
        });
      }, [videoRef.current]);

      useEffect(() => {
        const player = playerRef.current;
        if (!player || status?.status !== "online" || !status?.active || !status?.hls_url) return;
        const sourceKey = [
          status.started_at || "",
          status.quality || "",
          status.area || "",
          status.chat_zoom_enabled ? "chat" : "full",
        ].join(":");
        if (sourceKeyRef.current === sourceKey) return;
        sourceKeyRef.current = sourceKey;
        player.src({
          src: `/hls/live.m3u8?stream=${encodeURIComponent(sourceKey)}&t=${Date.now()}`,
          type: "application/x-mpegURL",
        });
        player.load();
        const playResult = player.play();
        if (playResult && typeof playResult.catch === "function") {
          playResult.catch(() => {});
        }
      }, [status?.status, status?.active, status?.started_at, status?.quality, status?.area, status?.chat_zoom_enabled, status?.hls_url]);

      const areaText = status?.area === "chat" ? "Чат" : "Все окно";
      const autoStopText = useMemo(() => {
        if (!status?.active || status.seconds_until_auto_stop == null) return "-";
        const seconds = Math.max(0, status.seconds_until_auto_stop);
        const minutes = Math.floor(seconds / 60);
        const rest = String(seconds % 60).padStart(2, "0");
        return `${minutes}:${rest}`;
      }, [status]);

      async function setChatZoom(enabled) {
        setBusy(true);
        try {
          const response = await fetch("/api/stream/chat-zoom", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ enabled }),
          });
          setStatus(await response.json());
        } finally {
          setBusy(false);
        }
      }

      async function enableChatMode() {
        setBusy(true);
        try {
          const response = await fetch("/api/stream/chat-mode", { method: "POST" });
          setStatus(await response.json());
        } finally {
          setBusy(false);
        }
      }

      return React.createElement("main", { className: "page" },
        React.createElement("section", { className: "playerShell" },
          React.createElement("video", {
            ref: videoRef,
            className: "video-js vjs-big-play-centered",
            playsInline: true,
          })
        ),
        React.createElement("aside", { className: "side" },
          React.createElement(Stack, { spacing: 2 },
            React.createElement(Stack, { direction: "row", justifyContent: "space-between", alignItems: "center" },
              React.createElement(Typography, { variant: "h5", component: "h1" }, "Стрим игры"),
              React.createElement(Chip, {
                label: formatStatus(status?.status),
                color: status?.status === "online" ? "success" : status?.status === "error" ? "error" : "default",
                size: "small",
              })
            ),
            React.createElement("div", { className: "statusGrid" },
              React.createElement("div", { className: "metric" },
                React.createElement("div", { className: "metricLabel" }, "Качество"),
                React.createElement("div", { className: "metricValue" }, status?.quality || "720p")
              ),
              React.createElement("div", { className: "metric" },
                React.createElement("div", { className: "metricLabel" }, "Область"),
                React.createElement("div", { className: "metricValue" }, areaText)
              ),
              React.createElement("div", { className: "metric" },
                React.createElement("div", { className: "metricLabel" }, "Автостоп"),
                React.createElement("div", { className: "metricValue" }, autoStopText)
              ),
              React.createElement("div", { className: "metric" },
                React.createElement("div", { className: "metricLabel" }, "Режим чата"),
                React.createElement("div", { className: "metricValue" }, status?.chat_mode_enabled ? "Включен" : "Выключен")
              )
            ),
            status?.error ? React.createElement(Chip, { label: status.error, color: "error", variant: "outlined" }) : null,
            React.createElement(Divider, null),
            React.createElement(FormControlLabel, {
              control: React.createElement(Switch, {
                checked: Boolean(status?.chat_zoom_enabled),
                disabled: busy,
                onChange: (event) => setChatZoom(event.target.checked),
              }),
              label: "Увеличить чат",
            }),
            React.createElement(Stack, { spacing: 1 },
              React.createElement(Button, {
                variant: "contained",
                color: "warning",
                disabled: busy,
                onClick: enableChatMode,
              }, "Включить режим чата"),
              React.createElement("div", { className: "comment" }, "Режим чата прервёт рыбалку")
            ),
            React.createElement(TextField, {
              label: "Сообщение в чат",
              size: "small",
              disabled: true,
              value: "",
              fullWidth: true,
            })
          )
        )
      );
    }

    ReactDOM.createRoot(document.getElementById("root")).render(React.createElement(App));
  </script>
</body>
</html>
"""


class StreamingService:
    def __init__(
        self,
        *,
        log_callback: Callable[[str], None] | None = None,
        chat_mode_callback: Callable[[], None] | None = None,
        clock: Callable[[], float] = time.monotonic,
        popen_factory: Callable[..., subprocess.Popen] = subprocess.Popen,
        temp_root: Path | None = None,
        viewer_timeout_seconds: float = VIEWER_TIMEOUT_SECONDS,
        prewarm_binaries: bool = True,
    ) -> None:
        self.log_callback = log_callback
        self.chat_mode_callback = chat_mode_callback
        self.clock = clock
        self.popen_factory = popen_factory
        self.temp_root = temp_root or Path(tempfile.gettempdir())
        self.viewer_timeout_seconds = viewer_timeout_seconds
        self._lock = threading.RLock()
        self._quality = "720p"
        self._active = False
        self._status = "offline"
        self._error = ""
        self._chat_zoom_enabled = False
        self._chat_mode_enabled = False
        self._started_at: float | None = None
        self._last_viewer_activity_at: float | None = None
        self._runtime_dir = self.temp_root / f"{STREAM_TEMP_PREFIX}runtime-{uuid.uuid4().hex}"
        self._ffmpeg_binary: Path | None = None
        self._cloudflared_binary: Path | None = None
        self._binary_prepare_error = ""
        self._binary_ready = threading.Event()
        self._ffmpeg_ready = threading.Event()
        self._cloudflared_ready = threading.Event()
        self._binary_prepare_lock = threading.Lock()
        self._binary_prepare_thread: threading.Thread | None = None
        self._temp_dir: Path | None = None
        self._hls_dir: Path | None = None
        self._local_url: str | None = None
        self._public_url: str | None = None
        self._httpd: ThreadingHTTPServer | None = None
        self._server_thread: threading.Thread | None = None
        self._ffmpeg_process: subprocess.Popen | None = None
        self._cloudflared_process: subprocess.Popen | None = None
        self._monitor_thread: threading.Thread | None = None
        self._start_thread: threading.Thread | None = None
        self._tunnel_thread: threading.Thread | None = None
        self._runtime_token: str | None = None
        self._stop_monitor = threading.Event()
        self._log_files: list[object] = []
        self.cleanup_orphaned_runtime_dirs()
        if prewarm_binaries:
            self.prepare_binaries_async()
        atexit.register(self.shutdown)

    def start_stream(self) -> bool:
        with self._lock:
            if self._active:
                return True
            if self._status == "starting" and self._start_thread and self._start_thread.is_alive():
                return True
            self._prepare_new_runtime_locked()
            token = uuid.uuid4().hex
            self._runtime_token = token
            self._start_thread = threading.Thread(
                target=self._start_runtime_worker,
                args=(token,),
                name="sonar-stream-start",
                daemon=True,
            )
            self._start_thread.start()
            return True

    def stop_stream(self, reason: str = "manual") -> None:
        with self._lock:
            if not self._active and self._status == "offline":
                return
            self._log(f"Стрим остановлен: {reason}")
            self._stop_runtime_locked(clean_temp=True)

    def shutdown(self) -> None:
        with self._lock:
            self._stop_runtime_locked(clean_temp=True)
        shutil.rmtree(self._runtime_dir, ignore_errors=True)

    def prepare_binaries_async(self) -> None:
        if self._binary_prepare_thread and self._binary_prepare_thread.is_alive():
            return
        self._binary_ready.clear()
        self._ffmpeg_ready.clear()
        self._cloudflared_ready.clear()
        self._binary_prepare_thread = threading.Thread(
            target=self._prepare_binaries_worker,
            name="sonar-stream-binaries",
            daemon=True,
        )
        self._binary_prepare_thread.start()

    def snapshot(self) -> StreamSnapshot:
        with self._lock:
            return self._snapshot_locked()

    def set_quality(self, quality: str) -> bool:
        if quality not in STREAM_QUALITIES:
            return False
        should_restart = False
        with self._lock:
            if self._quality == quality:
                return True
            self._quality = quality
            if self._active:
                should_restart = True
        if should_restart:
            self._restart_ffmpeg()
        return True

    def set_chat_zoom_enabled(self, enabled: bool) -> bool:
        should_restart = False
        with self._lock:
            enabled = bool(enabled)
            if self._chat_zoom_enabled == enabled:
                return True
            self._chat_zoom_enabled = enabled
            if self._active:
                should_restart = True
        if should_restart:
            self._restart_ffmpeg()
        return True

    def enable_chat_mode(self) -> StreamSnapshot:
        if self.chat_mode_callback is not None:
            self.chat_mode_callback()
        with self._lock:
            self._chat_mode_enabled = True
        self.set_chat_zoom_enabled(True)
        return self.snapshot()

    def mark_viewer_activity(self) -> None:
        with self._lock:
            if self._active:
                self._last_viewer_activity_at = self.clock()

    def stream_url(self) -> str | None:
        with self._lock:
            return self._stream_url_locked()

    def cleanup_orphaned_runtime_dirs(self) -> None:
        try:
            for child in self.temp_root.glob(f"{STREAM_TEMP_PREFIX}*"):
                if child.is_dir():
                    shutil.rmtree(child, ignore_errors=True)
        except OSError as exc:
            self._log(f"Не удалось очистить старые папки стрима: {exc}")

    def _prepare_new_runtime_locked(self) -> None:
        self._active = False
        self._status = "starting"
        self._error = ""
        self._chat_zoom_enabled = False
        self._chat_mode_enabled = False
        self._started_at = None
        self._last_viewer_activity_at = None
        self._local_url = None
        self._public_url = None
        self._temp_dir = self.temp_root / f"{STREAM_TEMP_PREFIX}{uuid.uuid4().hex}"
        self._hls_dir = self._temp_dir / "hls"
        self._hls_dir.mkdir(parents=True, exist_ok=True)

    def _prepare_binaries_worker(self) -> None:
        with self._binary_prepare_lock:
            try:
                self._log("Streaming runtime: подготавливаю portable FFmpeg/cloudflared")
                ffmpeg = self._resolve_binary(
                    "ffmpeg.exe",
                    "ffmpeg",
                    display_name="FFmpeg",
                    archive_patterns=("ffmpeg*.zip",),
                    download_url=os.environ.get("SONAR_STREAM_FFMPEG_URL", FFMPEG_DOWNLOAD_URL),
                )
                with self._lock:
                    self._ffmpeg_binary = ffmpeg
                    self._binary_prepare_error = "" if ffmpeg is not None else "FFmpeg не подготовлен"
                self._ffmpeg_ready.set()
                if ffmpeg is not None:
                    self._log("Streaming runtime: FFmpeg готов")

                cloudflared = self._resolve_binary(
                    "cloudflared.exe",
                    "cloudflared",
                    display_name="cloudflared",
                    archive_patterns=("cloudflared*.zip",),
                    download_url=os.environ.get("SONAR_STREAM_CLOUDFLARED_URL", CLOUDFLARED_DOWNLOAD_URL),
                )
                with self._lock:
                    self._cloudflared_binary = cloudflared
                self._cloudflared_ready.set()
                if cloudflared is not None:
                    self._log("Streaming runtime: cloudflared готов")
            except Exception as exc:
                with self._lock:
                    self._binary_prepare_error = str(exc)
                self._log(f"Streaming runtime: подготовка не удалась: {exc}")
            finally:
                self._ffmpeg_ready.set()
                self._cloudflared_ready.set()
                self._binary_ready.set()

    def _start_runtime_worker(self, token: str) -> None:
        try:
            ffmpeg = self._resolve_ffmpeg_binary(wait_timeout=None)
            if ffmpeg is None:
                raise RuntimeError(
                    "FFmpeg не удалось подготовить автоматически. "
                    "В portable-сборке должен быть resources/streaming/ffmpeg*.zip или ffmpeg.exe."
                )
            with self._lock:
                if token != self._runtime_token or self._status != "starting":
                    return
                self._start_http_server_locked()
                self._start_ffmpeg_process_locked(ffmpeg)
                self._log("Стрим: ожидаю первые HLS-сегменты")
            self._wait_for_hls_ready(token)
            with self._lock:
                if token != self._runtime_token or self._status != "starting":
                    return
                self._active = True
                self._status = "online"
                self._started_at = self.clock()
                self._last_viewer_activity_at = self._started_at
                self._ensure_monitor_locked()
                self._log("Стрим запущен")
                self._tunnel_thread = threading.Thread(
                    target=self._start_tunnel_worker,
                    args=(token,),
                    name="sonar-stream-tunnel",
                    daemon=True,
                )
                self._tunnel_thread.start()
        except Exception as exc:
            with self._lock:
                if token != self._runtime_token:
                    return
                error = str(exc)
                self._log(f"Не удалось запустить стрим: {exc}")
                self._stop_runtime_locked(clean_temp=True)
                self._error = error
                self._status = "error"

    def _start_tunnel_worker(self, token: str) -> None:
        cloudflared = self._resolve_cloudflared_binary(wait_timeout=None)
        if cloudflared is None:
            self._log("cloudflared не удалось подготовить автоматически, ссылка будет локальной")
            return
        with self._lock:
            if token != self._runtime_token or not self._active:
                return
            try:
                self._start_cloudflared_process_locked(cloudflared)
            except Exception as exc:
                self._log(f"cloudflared не запустился: {exc}")

    def _wait_for_hls_ready(self, token: str) -> None:
        deadline = time.monotonic() + HLS_READY_TIMEOUT_SECONDS
        while True:
            with self._lock:
                if token != self._runtime_token or self._status != "starting":
                    return
                process = self._ffmpeg_process
                hls_dir = self._hls_dir
            if process is not None and process.poll() is not None:
                raise RuntimeError("FFmpeg завершился до готовности HLS")
            if self._hls_playlist_ready(hls_dir):
                return
            if time.monotonic() >= deadline:
                raise RuntimeError("FFmpeg не создал HLS-плейлист за 15 секунд")
            time.sleep(HLS_READY_POLL_SECONDS)

    @staticmethod
    def _hls_playlist_ready(hls_dir: Path | None) -> bool:
        if hls_dir is None:
            return False
        playlist = hls_dir / "live.m3u8"
        if not playlist.exists() or playlist.stat().st_size <= 0:
            return False
        try:
            text = playlist.read_text(encoding="utf-8", errors="ignore")
        except OSError:
            return False
        segment_names = [line.strip() for line in text.splitlines() if line.strip() and not line.startswith("#")]
        if not segment_names or "#EXTINF" not in text:
            return False
        return any((hls_dir / name).exists() and (hls_dir / name).stat().st_size > 0 for name in segment_names)

    def _start_http_server_locked(self) -> None:
        service = self

        class Handler(StreamRequestHandler):
            stream_service = service

        self._httpd = ThreadingHTTPServer(("127.0.0.1", 0), Handler)
        port = int(self._httpd.server_address[1])
        self._local_url = f"http://127.0.0.1:{port}"
        self._public_url = self._local_url
        self._server_thread = threading.Thread(target=self._httpd.serve_forever, name="sonar-stream-http", daemon=True)
        self._server_thread.start()

    def _start_ffmpeg_locked(self) -> None:
        ffmpeg = self._resolve_ffmpeg_binary()
        if ffmpeg is None:
            raise RuntimeError(
                "FFmpeg не удалось подготовить автоматически. "
                "В portable-сборке должен быть resources/streaming/ffmpeg*.zip или ffmpeg.exe."
            )
        self._start_ffmpeg_process_locked(ffmpeg)

    def _resolve_ffmpeg_binary(self, *, wait_timeout: float | None = 0.05) -> Path | None:
        if self._ffmpeg_binary is not None and self._ffmpeg_binary.exists():
            return self._ffmpeg_binary
        if self._binary_prepare_thread and self._binary_prepare_thread.is_alive():
            self._ffmpeg_ready.wait(timeout=wait_timeout)
            if self._ffmpeg_binary is not None and self._ffmpeg_binary.exists():
                return self._ffmpeg_binary
            return None
        return self._resolve_binary(
            "ffmpeg.exe",
            "ffmpeg",
            display_name="FFmpeg",
            archive_patterns=("ffmpeg*.zip",),
            download_url=os.environ.get("SONAR_STREAM_FFMPEG_URL", FFMPEG_DOWNLOAD_URL),
        )

    def _start_ffmpeg_process_locked(self, ffmpeg: Path) -> None:
        if self._hls_dir is None:
            raise RuntimeError("HLS папка не подготовлена")
        log_file = self._open_log_file_locked("ffmpeg.log")
        command = self._build_ffmpeg_command(ffmpeg)
        self._ffmpeg_process = self._popen(command, stdout=log_file, stderr=subprocess.STDOUT)

    def _start_cloudflared_locked(self) -> None:
        cloudflared = self._resolve_cloudflared_binary()
        if cloudflared is None or self._local_url is None:
            self._log("cloudflared не удалось подготовить автоматически, ссылка будет локальной")
            return
        self._start_cloudflared_process_locked(cloudflared)

    def _resolve_cloudflared_binary(self, *, wait_timeout: float | None = 0.05) -> Path | None:
        if self._cloudflared_binary is not None and self._cloudflared_binary.exists():
            return self._cloudflared_binary
        if self._binary_prepare_thread and self._binary_prepare_thread.is_alive():
            self._cloudflared_ready.wait(timeout=wait_timeout)
            if self._cloudflared_binary is not None and self._cloudflared_binary.exists():
                return self._cloudflared_binary
            return None
        return self._resolve_binary(
            "cloudflared.exe",
            "cloudflared",
            display_name="cloudflared",
            archive_patterns=("cloudflared*.zip",),
            download_url=os.environ.get("SONAR_STREAM_CLOUDFLARED_URL", CLOUDFLARED_DOWNLOAD_URL),
        )

    def _start_cloudflared_process_locked(self, cloudflared: Path) -> None:
        if self._local_url is None:
            return
        log_file = self._open_log_file_locked("cloudflared.log")
        command = [str(cloudflared), "tunnel", "--url", self._local_url]
        process = self._popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        self._cloudflared_process = process
        threading.Thread(
            target=self._watch_cloudflared_output,
            args=(process, log_file),
            name="sonar-cloudflared",
            daemon=True,
        ).start()

    def _watch_cloudflared_output(self, process: subprocess.Popen, log_file) -> None:
        stream = process.stdout
        if stream is None:
            return
        try:
            for line in stream:
                try:
                    log_file.write(line.encode("utf-8", errors="replace") if "b" in getattr(log_file, "mode", "") else line)
                    log_file.flush()
                except Exception:
                    pass
                match = CLOUDFLARED_URL_RE.search(line)
                if match:
                    with self._lock:
                        self._public_url = match.group(0).rstrip("/")
        except Exception as exc:
            self._log(f"cloudflared output error: {exc}")

    def _restart_ffmpeg_locked(self) -> None:
        token = self._runtime_token
        try:
            self._restart_ffmpeg()
        except Exception as exc:
            with self._lock:
                if token != self._runtime_token:
                    return
                self._error = str(exc)
                self._status = "error"
                self._log(f"Не удалось переключить стрим: {exc}")

    def _restart_ffmpeg(self) -> None:
        token: str | None = None
        try:
            with self._lock:
                if not self._active:
                    return
                token = self._runtime_token
                self._terminate_process(self._ffmpeg_process)
                self._ffmpeg_process = None
                if self._hls_dir is not None:
                    shutil.rmtree(self._hls_dir, ignore_errors=True)
                    self._hls_dir.mkdir(parents=True, exist_ok=True)
                self._status = "starting"
                self._start_ffmpeg_locked()
                self._log("Стрим: ожидаю HLS после переключения области")
            if token is not None:
                self._wait_for_hls_ready(token)
            with self._lock:
                if token != self._runtime_token or not self._active:
                    return
                self._error = ""
                self._status = "online"
        except Exception as exc:
            with self._lock:
                if token != self._runtime_token:
                    return
                self._error = str(exc)
                self._status = "error"
                self._log(f"Не удалось переключить стрим: {exc}")

    def _ensure_monitor_locked(self) -> None:
        if self._monitor_thread and self._monitor_thread.is_alive():
            return
        self._stop_monitor.clear()
        self._monitor_thread = threading.Thread(target=self._monitor_loop, name="sonar-stream-monitor", daemon=True)
        self._monitor_thread.start()

    def _monitor_loop(self) -> None:
        while not self._stop_monitor.wait(2.0):
            should_stop = False
            restart_needed = False
            with self._lock:
                if self._active and self._should_auto_stop_locked():
                    should_stop = True
                if self._active and self._ffmpeg_process and self._ffmpeg_process.poll() is not None:
                    self._log("FFmpeg завершился, перезапускаю стрим")
                    restart_needed = True
            if restart_needed:
                self._restart_ffmpeg()
            if should_stop:
                self.stop_stream("нет зрителей 3 минуты")

    def _should_auto_stop_locked(self) -> bool:
        if not self._active:
            return False
        reference = self._last_viewer_activity_at or self._started_at
        if reference is None:
            return False
        return self.clock() - reference >= self.viewer_timeout_seconds

    def _stop_runtime_locked(self, *, clean_temp: bool) -> None:
        self._active = False
        self._status = "offline"
        self._stop_monitor.set()
        monitor_thread = self._monitor_thread
        if monitor_thread and monitor_thread.is_alive() and threading.current_thread() is not monitor_thread:
            monitor_thread.join(timeout=1.0)
        self._terminate_process(self._ffmpeg_process)
        self._terminate_process(self._cloudflared_process)
        self._ffmpeg_process = None
        self._cloudflared_process = None
        if self._httpd is not None:
            try:
                self._httpd.shutdown()
                self._httpd.server_close()
            except Exception:
                pass
        self._httpd = None
        self._server_thread = None
        self._close_log_files_locked()
        if clean_temp and self._temp_dir is not None:
            shutil.rmtree(self._temp_dir, ignore_errors=True)
        self._temp_dir = None
        self._hls_dir = None
        self._local_url = None
        self._public_url = None
        self._started_at = None
        self._last_viewer_activity_at = None
        self._runtime_token = None

    def _snapshot_locked(self) -> StreamSnapshot:
        seconds_until_auto_stop: int | None = None
        if self._active:
            reference = self._last_viewer_activity_at or self._started_at
            if reference is not None:
                seconds_until_auto_stop = max(0, int(self.viewer_timeout_seconds - (self.clock() - reference)))
        return StreamSnapshot(
            active=self._active,
            status="preparing" if self._status == "offline" and self._binary_prepare_thread and self._binary_prepare_thread.is_alive() else self._status,
            quality=self._quality,
            area="chat" if self._chat_zoom_enabled else "full",
            chat_zoom_enabled=self._chat_zoom_enabled,
            chat_mode_enabled=self._chat_mode_enabled,
            local_url=self._local_url,
            public_url=self._public_url,
            stream_url=self._stream_url_locked(),
            hls_url="/hls/live.m3u8" if self._active else None,
            started_at=self._started_at,
            last_viewer_activity_at=self._last_viewer_activity_at,
            seconds_until_auto_stop=seconds_until_auto_stop,
            error=self._error or self._binary_prepare_error,
        )

    def _stream_url_locked(self) -> str | None:
        base = self._public_url or self._local_url
        if not base:
            return None
        return f"{base.rstrip('/')}/live/"

    def _build_ffmpeg_command(self, executable: Path) -> list[str]:
        if self._hls_dir is None:
            raise RuntimeError("HLS папка не подготовлена")
        quality = STREAM_QUALITIES[self._quality]
        capture_args = self._capture_args()
        encoder = os.environ.get("SONAR_STREAM_ENCODER", "libx264").strip() or "libx264"
        hls_playlist = self._hls_dir / "live.m3u8"
        hls_segment = self._hls_dir / "seg_%05d.ts"
        return [
            str(executable),
            "-hide_banner",
            "-nostdin",
            "-loglevel",
            "warning",
            "-f",
            "gdigrab",
            "-framerate",
            "30",
            *capture_args,
            "-i",
            "desktop",
            "-an",
            "-vf",
            f"scale=-2:{quality.height}:flags=lanczos",
            "-c:v",
            encoder,
            "-preset",
            "veryfast",
            "-tune",
            "zerolatency",
            "-b:v",
            quality.bitrate,
            "-maxrate",
            quality.bitrate,
            "-bufsize",
            self._double_bitrate(quality.bitrate),
            "-pix_fmt",
            "yuv420p",
            "-g",
            "60",
            "-f",
            "hls",
            "-hls_time",
            "2",
            "-hls_list_size",
            "12",
            "-hls_delete_threshold",
            "12",
            "-hls_flags",
            "delete_segments+independent_segments+omit_endlist",
            "-hls_segment_filename",
            str(hls_segment),
            str(hls_playlist),
        ]

    def _capture_args(self) -> list[str]:
        screen_width, screen_height = self._screen_size()
        if self._chat_zoom_enabled:
            width = max(320, screen_width // 2)
            height = max(240, (screen_height * 2) // 3)
            return ["-offset_x", "0", "-offset_y", "0", "-video_size", f"{width}x{height}"]
        return ["-video_size", f"{screen_width}x{screen_height}"]

    @staticmethod
    def _screen_size() -> tuple[int, int]:
        if os.name == "nt":
            try:
                import ctypes

                user32 = ctypes.windll.user32
                return int(user32.GetSystemMetrics(0)), int(user32.GetSystemMetrics(1))
            except Exception:
                pass
        return 1920, 1080

    @staticmethod
    def _double_bitrate(value: str) -> str:
        if value.endswith("k") and value[:-1].isdigit():
            return f"{int(value[:-1]) * 2}k"
        return value

    def _resolve_binary(
        self,
        binary_name: str,
        command_name: str,
        *,
        display_name: str,
        archive_patterns: tuple[str, ...],
        download_url: str | None,
    ) -> Path | None:
        runtime_binary = self._runtime_bin_dir_locked() / binary_name
        if runtime_binary.exists():
            return runtime_binary

        env_path = os.environ.get(f"SONAR_STREAM_{command_name.upper()}_PATH", "").strip()
        source = Path(env_path) if env_path else None
        if source and source.exists():
            return self._cache_and_copy_binary(source, binary_name)

        bundled_binary = STREAMING_RESOURCE_DIR / binary_name
        if bundled_binary.exists():
            return self._cache_and_copy_binary(bundled_binary, binary_name)

        for cached_binary in self._cached_binary_paths(binary_name):
            if cached_binary.exists():
                return self._copy_binary_to_runtime(cached_binary, binary_name)

        for pattern in archive_patterns:
            for archive_path in sorted(STREAMING_RESOURCE_DIR.glob(pattern)):
                resolved = self._extract_binary_from_zip(archive_path, binary_name)
                if resolved is not None:
                    self._log(f"{display_name}: используется встроенный portable-архив {archive_path.name}")
                    return resolved

        found = shutil.which(binary_name) or shutil.which(command_name)
        if found:
            return self._cache_and_copy_binary(Path(found), binary_name)

        if not download_url or os.environ.get("SONAR_STREAM_DISABLE_DOWNLOAD") == "1":
            return None

        try:
            downloaded = self._download_portable_binary(display_name, binary_name, download_url)
            if downloaded.suffix.lower() == ".zip":
                return self._extract_binary_from_zip(downloaded, binary_name)
            return self._cache_and_copy_binary(downloaded, binary_name)
        except (OSError, urllib.error.URLError, zipfile.BadZipFile, RuntimeError) as exc:
            self._log(f"{display_name}: portable-загрузка не удалась: {exc}")
            return None

    def _runtime_bin_dir_locked(self) -> Path:
        bin_dir = self._runtime_dir / "bin"
        bin_dir.mkdir(parents=True, exist_ok=True)
        return bin_dir

    @staticmethod
    def _cached_binary_path(binary_name: str) -> Path:
        return STREAMING_CACHE_DIR / "bin" / binary_name

    @staticmethod
    def _cached_binary_paths(binary_name: str) -> tuple[Path, ...]:
        primary = STREAMING_CACHE_DIR / "bin" / binary_name
        legacy = LEGACY_STREAMING_CACHE_DIR / "bin" / binary_name
        if primary == legacy:
            return (primary,)
        return (primary, legacy)

    def _cache_and_copy_binary(self, source: Path, binary_name: str) -> Path:
        cached = self._cached_binary_path(binary_name)
        cached.parent.mkdir(parents=True, exist_ok=True)
        if source.resolve() != cached.resolve():
            shutil.copy2(source, cached)
        try:
            cached.chmod(0o755)
        except OSError:
            pass
        return self._copy_binary_to_runtime(cached, binary_name)

    def _copy_binary_to_runtime(self, source: Path, binary_name: str) -> Path:
        target = self._runtime_bin_dir_locked() / binary_name
        target.parent.mkdir(parents=True, exist_ok=True)
        if source.resolve() != target.resolve():
            shutil.copy2(source, target)
        try:
            target.chmod(0o755)
        except OSError:
            pass
        return target

    def _extract_binary_from_zip(self, archive_path: Path, binary_name: str) -> Path | None:
        target = self._cached_binary_path(binary_name)
        binary_name_lower = binary_name.lower()
        with zipfile.ZipFile(archive_path) as archive:
            members = [
                member
                for member in archive.infolist()
                if not member.is_dir() and Path(member.filename).name.lower() == binary_name_lower
            ]
            if not members:
                return None
            preferred = sorted(
                members,
                key=lambda member: (
                    "/bin/" not in member.filename.replace("\\", "/").lower(),
                    len(member.filename),
                ),
            )[0]
            target.parent.mkdir(parents=True, exist_ok=True)
            with archive.open(preferred) as source, target.open("wb") as output:
                shutil.copyfileobj(source, output)
        try:
            target.chmod(0o755)
        except OSError:
            pass
        return self._copy_binary_to_runtime(target, binary_name)

    def _download_portable_binary(self, display_name: str, binary_name: str, url: str) -> Path:
        suffix = Path(urlparse(url).path).suffix.lower()
        filename = f"{display_name.lower()}-portable{suffix or Path(binary_name).suffix}"
        target = STREAMING_CACHE_DIR / "downloads" / filename
        partial_target = target.with_name(f"{target.name}.part")
        target.parent.mkdir(parents=True, exist_ok=True)
        if target.exists() and target.stat().st_size > 0:
            return target
        self._log(f"{display_name}: скачиваю portable runtime в кэш приложения")
        partial_target.unlink(missing_ok=True)
        self._download_file(url, partial_target)
        partial_target.replace(target)
        return target

    @staticmethod
    def _download_file(url: str, target: Path) -> None:
        request = urllib.request.Request(url, headers={"User-Agent": "Sonar-streaming/1.0"})
        with urllib.request.urlopen(request, timeout=DOWNLOAD_TIMEOUT_SECONDS) as response, target.open("wb") as file:
            shutil.copyfileobj(response, file)

    def _open_log_file_locked(self, filename: str):
        if self._temp_dir is None:
            raise RuntimeError("Temp папка стрима не подготовлена")
        path = self._temp_dir / "logs" / filename
        path.parent.mkdir(parents=True, exist_ok=True)
        file = path.open("ab")
        self._log_files.append(file)
        return file

    def _close_log_files_locked(self) -> None:
        for file in self._log_files:
            try:
                file.close()
            except Exception:
                pass
        self._log_files.clear()

    def _popen(self, command: list[str], **kwargs) -> subprocess.Popen:
        creationflags = kwargs.pop("creationflags", 0)
        if os.name == "nt":
            creationflags |= getattr(subprocess, "CREATE_NO_WINDOW", 0)
        return self.popen_factory(command, creationflags=creationflags, **kwargs)

    @staticmethod
    def _terminate_process(process: subprocess.Popen | None) -> None:
        if process is None:
            return
        try:
            if process.poll() is None:
                process.terminate()
                try:
                    process.wait(timeout=3.0)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait(timeout=2.0)
        except Exception:
            pass

    def _log(self, message: str) -> None:
        if self.log_callback is not None:
            self.log_callback(message)


class StreamRequestHandler(BaseHTTPRequestHandler):
    stream_service: StreamingService

    def do_GET(self) -> None:  # noqa: N802
        parsed = urlparse(self.path)
        if parsed.path in {"", "/"}:
            self.send_response(HTTPStatus.FOUND)
            self.send_header("Location", "/live/")
            self.end_headers()
            return
        if parsed.path in {"/live", "/live/"}:
            self._send_bytes(STREAM_PAGE_HTML.encode("utf-8"), "text/html; charset=utf-8")
            return
        if parsed.path == "/api/stream/status":
            self._send_json(self.stream_service.snapshot())
            return
        if parsed.path.startswith("/hls/"):
            self.stream_service.mark_viewer_activity()
            self._serve_hls_file(parsed.path.removeprefix("/hls/"))
            return
        self.send_error(HTTPStatus.NOT_FOUND)

    def do_POST(self) -> None:  # noqa: N802
        parsed = urlparse(self.path)
        if parsed.path == "/api/stream/viewer-heartbeat":
            self.stream_service.mark_viewer_activity()
            self._send_json(self.stream_service.snapshot())
            return
        if parsed.path == "/api/stream/chat-zoom":
            payload = self._read_json_body()
            self.stream_service.set_chat_zoom_enabled(bool(payload.get("enabled")))
            self._send_json(self.stream_service.snapshot())
            return
        if parsed.path == "/api/stream/chat-mode":
            self._send_json(self.stream_service.enable_chat_mode())
            return
        self.send_error(HTTPStatus.NOT_FOUND)

    def log_message(self, format: str, *args) -> None:  # noqa: A002
        return

    def _serve_hls_file(self, relative_path: str) -> None:
        snapshot = self.stream_service.snapshot()
        with self.stream_service._lock:
            hls_dir = self.stream_service._hls_dir
        if hls_dir is None or not snapshot.active:
            self.send_error(HTTPStatus.NOT_FOUND)
            return
        candidate = (hls_dir / relative_path).resolve()
        try:
            candidate.relative_to(hls_dir.resolve())
        except ValueError:
            self.send_error(HTTPStatus.NOT_FOUND)
            return
        if not candidate.exists() or not candidate.is_file():
            self.send_error(HTTPStatus.NOT_FOUND)
            return
        content_type = "application/vnd.apple.mpegurl" if candidate.suffix == ".m3u8" else "video/mp2t"
        self._send_bytes(candidate.read_bytes(), content_type)

    def _read_json_body(self) -> dict[str, object]:
        try:
            length = int(self.headers.get("Content-Length") or "0")
        except ValueError:
            length = 0
        if length <= 0:
            return {}
        try:
            body = self.rfile.read(length).decode("utf-8")
            data = json.loads(body)
            return data if isinstance(data, dict) else {}
        except (OSError, json.JSONDecodeError, UnicodeDecodeError):
            return {}

    def _send_json(self, snapshot: StreamSnapshot) -> None:
        payload = json.dumps(asdict(snapshot), ensure_ascii=False).encode("utf-8")
        self._send_bytes(payload, "application/json; charset=utf-8")

    def _send_bytes(self, payload: bytes, content_type: str) -> None:
        self.send_response(HTTPStatus.OK)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(payload)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(payload)
