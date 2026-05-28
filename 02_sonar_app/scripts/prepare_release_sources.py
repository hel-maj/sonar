from __future__ import annotations

import argparse
import re
import shutil
from pathlib import Path


CHAT_STUB = '''
from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True, slots=True)
class ChatCommand:
    key: str
    title: str
    code: str
    description: str


@dataclass(frozen=True, slots=True)
class ChatTab:
    id: str
    name: str
    selected: bool
    rect: object | None = None
    available: bool = True


@dataclass(frozen=True, slots=True)
class ChatDetection:
    active: bool = False
    tabs: tuple[ChatTab, ...] = ()
    selected_tab_id: str | None = None
    input_rect: object | None = None
    error: str = ""


@dataclass(frozen=True, slots=True)
class ChatActionResult:
    ok: bool
    message: str
    detection: ChatDetection


CHAT_COMMANDS: tuple[ChatCommand, ...] = ()


class MajesticChatDetector:
    def __init__(self, *args, **kwargs) -> None:
        pass

    def detect(self) -> ChatDetection:
        return ChatDetection(error="Недоступно в exe-сборке")


class MajesticChatController(MajesticChatDetector):
    def open_chat(self, *args, **kwargs) -> ChatActionResult:
        detection = self.detect()
        return ChatActionResult(False, detection.error, detection)

    def close_chat(self, *args, **kwargs) -> ChatActionResult:
        detection = self.detect()
        return ChatActionResult(False, detection.error, detection)

    def select_tab(self, *args, **kwargs) -> ChatActionResult:
        detection = self.detect()
        return ChatActionResult(False, detection.error, detection)

    def send_message(self, *args, **kwargs) -> ChatActionResult:
        detection = self.detect()
        return ChatActionResult(False, detection.error, detection)

    def clear_chat_input(self, *args, **kwargs) -> ChatActionResult:
        detection = self.detect()
        return ChatActionResult(False, detection.error, detection)
'''


STREAM_PAGE_HTML_RELEASE = r'''<!doctype html>
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
      display: flex;
      flex-direction: column;
      gap: 14px;
      min-height: 100vh;
      padding: 18px;
      max-width: 1480px;
      margin: 0 auto;
    }
    .video-js {
      width: 100%;
      height: min(76vh, calc(100vh - 220px));
      min-height: 360px;
      border-radius: 8px;
      overflow: hidden;
      background: #05070a;
      box-shadow: 0 18px 60px rgba(0, 0, 0, 0.42);
    }
    .side {
      border: 1px solid rgba(255, 255, 255, 0.10);
      border-radius: 8px;
      background: rgba(20, 25, 32, 0.88);
      padding: 14px;
      backdrop-filter: blur(12px);
    }
    .topBar {
      display: grid;
      grid-template-columns: minmax(0, 1fr) auto;
      gap: 12px;
      align-items: start;
    }
    .statusGrid {
      display: grid;
      grid-template-columns: repeat(4, minmax(120px, 1fr));
      gap: 10px;
      margin-top: 12px;
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
    .controls {
      display: flex;
      flex-wrap: wrap;
      gap: 12px;
      align-items: center;
    }
    button {
      border: 0;
      border-radius: 8px;
      padding: 8px 12px;
      background: #2f81f7;
      color: #fff;
      font-weight: 800;
      cursor: pointer;
    }
    button:disabled {
      opacity: 0.55;
      cursor: default;
    }
    select {
      border-radius: 8px;
      padding: 8px 10px;
      background: rgba(255, 255, 255, 0.08);
      color: #f4f7fb;
      border: 1px solid rgba(255, 255, 255, 0.28);
    }
    label {
      display: inline-flex;
      align-items: center;
      gap: 6px;
      color: #dce7f7;
    }
    @media (max-width: 900px) {
      .page { padding: 10px; }
      .video-js { height: 58vh; }
      .topBar,
      .statusGrid { grid-template-columns: 1fr; }
    }
  </style>
</head>
<body>
  <div id="root"></div>
  <script src="https://unpkg.com/react@18/umd/react.production.min.js"></script>
  <script src="https://unpkg.com/react-dom@18/umd/react-dom.production.min.js"></script>
  <script src="https://vjs.zencdn.net/8.16.1/video.min.js"></script>
  <script>
    const { useEffect, useMemo, useRef, useState } = React;

    function formatStatus(status) {
      if (status === "online") return "online";
      if (status === "starting") return "запуск";
      if (status === "preparing") return "подготовка";
      if (status === "error") return "ошибка";
      return "offline";
    }

    function App() {
      const videoRef = useRef(null);
      const playerRef = useRef(null);
      const sourceKeyRef = useRef("");
      const wasActiveRef = useRef(false);
      const [status, setStatus] = useState(null);
      const [busy, setBusy] = useState(false);

      async function refresh() {
        const response = await fetch("/api/stream/status", { cache: "no-store" });
        setStatus(await response.json());
      }

      useEffect(() => {
        refresh();
        const refreshTimer = setInterval(refresh, 2000);
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
          preload: "none",
          sources: [],
          html5: {
            vhs: {
              liveRangeSafeTimeDelta: 3,
              smoothQualityChange: true,
            },
          },
          liveTracker: {
            trackingThreshold: 3,
            liveTolerance: 3,
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
          status.snapshot_mode_enabled ? "fps10" : "fps30",
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
      }, [status?.status, status?.active, status?.started_at, status?.quality, status?.area, status?.chat_zoom_enabled, status?.hls_url, status?.snapshot_mode_enabled]);

      useEffect(() => {
        const player = playerRef.current;
        if (!player) return;
        if (!status?.active || status?.status !== "online") {
          if (sourceKeyRef.current !== "__idle__") {
            sourceKeyRef.current = "__idle__";
          }
          try {
            player.pause();
            player.src([]);
          } catch (error) {
          }
        }
      }, [status?.active, status?.status]);

      useEffect(() => {
        if (!status) return;
        if (status.active) {
          wasActiveRef.current = true;
          return;
        }
        if (!wasActiveRef.current) return;
        window.close();
        setTimeout(() => {
          if (!document.hidden) {
            try {
              window.location.replace("about:blank");
            } catch (error) {
            }
          }
        }, 300);
      }, [status?.active]);

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

      async function setSnapshotMode(enabled) {
        setBusy(true);
        try {
          const response = await fetch("/api/stream/snapshot-mode", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ enabled }),
          });
          setStatus(await response.json());
        } finally {
          setBusy(false);
        }
      }


      return React.createElement("main", { className: "page" },
        React.createElement("section", null,
          React.createElement("video", {
            ref: videoRef,
            className: "video-js vjs-big-play-centered",
            playsInline: true,
          })
        ),
        React.createElement("aside", { className: "side" },
          React.createElement("div", { className: "topBar" },
            React.createElement("div", null,
              React.createElement("h1", null, "Стрим игры"),
              React.createElement("div", { className: "comment" }, "Задержка трансляции может достигать 15 секунд.")
            ),
            React.createElement("div", { className: "controls" },
              React.createElement("label", null,
                React.createElement("input", {
                  type: "checkbox",
                  checked: Boolean(status?.chat_zoom_enabled),
                  disabled: busy,
                  onChange: (event) => setChatZoom(event.target.checked),
                }),
                "Увеличить чат"
              ),
              React.createElement("label", null,
                React.createElement("input", {
                  type: "checkbox",
                  checked: Boolean(status?.snapshot_mode_enabled),
                  disabled: busy,
                  onChange: (event) => setSnapshotMode(event.target.checked),
                }),
                "Режим 10fps"
              )
            )
          ),
          React.createElement("div", { className: "statusGrid" },
            React.createElement("div", { className: "metric" },
              React.createElement("div", { className: "metricLabel" }, "Статус"),
              React.createElement("div", { className: "metricValue" }, formatStatus(status?.status))
            ),
            React.createElement("div", { className: "metric" },
              React.createElement("div", { className: "metricLabel" }, "Качество"),
              React.createElement("div", { className: "metricValue" }, status?.snapshot_mode_enabled ? "10fps" : status?.quality || "720p")
            ),
            React.createElement("div", { className: "metric" },
              React.createElement("div", { className: "metricLabel" }, "Область"),
              React.createElement("div", { className: "metricValue" }, areaText)
            ),
            React.createElement("div", { className: "metric" },
              React.createElement("div", { className: "metricLabel" }, "Автостоп"),
              React.createElement("div", { className: "metricValue" }, autoStopText)
            )
          ),
          status?.error ? React.createElement("div", { className: "comment" }, status.error) : null
        )
      );
    }

    ReactDOM.createRoot(document.getElementById("root")).render(React.createElement(App));
  </script>
</body>
</html>
'''


def prepare_release_sources(source_root: Path) -> None:
    sonar_root = source_root / "sonar"
    tools_path = sonar_root / "tools"
    chat_path = sonar_root / "streaming" / "chat.py"
    service_path = sonar_root / "streaming" / "service.py"
    notifier_path = sonar_root / "telegram" / "notifier.py"

    if tools_path.exists():
        shutil.rmtree(tools_path)
    for cache_dir in sonar_root.rglob("__pycache__"):
        shutil.rmtree(cache_dir, ignore_errors=True)
    for pyc_path in sonar_root.rglob("*.pyc"):
        pyc_path.unlink(missing_ok=True)

    chat_path.write_text(CHAT_STUB, encoding="utf-8")

    service_text = service_path.read_text(encoding="utf-8")
    next_service_text = re.sub(
        r'STREAM_PAGE_HTML = r""".*?"""\n\n\nclass StreamingService:',
        f'STREAM_PAGE_HTML = r"""{STREAM_PAGE_HTML_RELEASE}"""\n\n\nclass StreamingService:',
        service_text,
        flags=re.DOTALL,
    )
    if next_service_text == service_text:
        raise RuntimeError("STREAM_PAGE_HTML block was not found")
    next_service_text = next_service_text.replace(
        '        if parsed.path == "/api/stream/chat":\n'
        '            self._send_json(self.stream_service.chat_snapshot())\n'
        '            return\n',
        "",
    )
    next_service_text = next_service_text.replace(
        '        if parsed.path == "/api/stream/chat-memory":\n'
        '            payload = self._read_json_body()\n'
        '            self._send_json(self.stream_service.set_chat_memory_enabled(bool(payload.get("enabled"))))\n'
        '            return\n',
        "",
    )
    next_service_text = next_service_text.replace(
        '        if parsed.path == "/api/stream/chat-mode":\n'
        '            payload = self._read_json_body()\n'
        '            if "enabled" in payload:\n'
        '                self._send_json(self.stream_service.set_chat_mode_enabled(bool(payload.get("enabled"))))\n'
        '            else:\n'
        '                self._send_json(self.stream_service.enable_chat_mode())\n'
        '            return\n',
        "",
    )
    next_service_text = next_service_text.replace(
        '        if parsed.path == "/api/stream/chat-select":\n'
        '            payload = self._read_json_body()\n'
        '            tab_id = payload.get("tab_id")\n'
        '            self._send_json(self.stream_service.select_chat_tab(str(tab_id) if tab_id is not None else None))\n'
        '            return\n',
        "",
    )
    next_service_text = next_service_text.replace(
        '        if parsed.path == "/api/stream/chat-send":\n'
        '            payload = self._read_json_body()\n'
        '            tab_id = payload.get("tab_id")\n'
        '            message = str(payload.get("message") or "")\n'
        '            self._send_json(self.stream_service.send_chat_message(str(tab_id) if tab_id is not None else None, message))\n'
        '            return\n',
        "",
    )
    next_service_text = next_service_text.replace(
        '        if parsed.path == "/api/stream/chat-clear":\n'
        '            self._send_json(self.stream_service.clear_chat_input())\n'
        '            return\n',
        "",
    )
    service_path.write_text(next_service_text, encoding="utf-8")

    notifier_text = notifier_path.read_text(encoding="utf-8")
    notifier_text = notifier_text.replace(
        '            f"{link_line}\\n\\n"\n'
        '            "Режим чата доступен на странице стрима"\n',
        '            f"{link_line}"\n',
    )
    notifier_path.write_text(notifier_text, encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser(description="Strip WIP chat mode from release build sources.")
    parser.add_argument("--source-root", required=True)
    args = parser.parse_args()
    prepare_release_sources(Path(args.source_root))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
