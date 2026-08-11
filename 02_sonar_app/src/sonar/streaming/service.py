from __future__ import annotations

import atexit
import json
import os
import re
import shutil
import subprocess
import sys
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

from sonar.core.logging import debug_log
from sonar.paths import CONFIG_DIR, LOG_DIR, PROJECT_DIR, RESOURCE_DIR
from sonar.security.runtime import decrypt_json_literal, decrypt_text_literal
from sonar.streaming.chat import CHAT_COMMANDS, ChatActionResult, ChatCommand, ChatDetection, ChatTab
from sonar.vision.geometry import Rect


VIEWER_TIMEOUT_SECONDS = 300.0
STREAM_RUNTIME_PREFIX = "stream-"
CLOUDFLARED_URL_RE = re.compile(r"https://[a-z0-9-]+\.trycloudflare\.com", re.IGNORECASE)
TUNNELMOLE_URL_RE = re.compile(r"https?://[a-z0-9-]+\.tunnelmole\.(?:net|com)", re.IGNORECASE)
CLOUDFLARED_REGISTERED_RE = re.compile(r"\bRegistered tunnel connection\b", re.IGNORECASE)
ARGOTUNNEL_DNS_ERROR_RE = re.compile(r"\bFailed to initialize DNS local resolver\b", re.IGNORECASE)
STREAMING_RESOURCE_DIR = RESOURCE_DIR / "streaming"
CHAT_ICON_DIR = RESOURCE_DIR / "chat_icons"
STREAMING_CACHE_DIR = CONFIG_DIR / "streaming"
STREAMING_RUNTIME_DIR = STREAMING_CACHE_DIR / "runtime"
LEGACY_STREAMING_CACHE_DIR = PROJECT_DIR / "02_sonar_app" / "config" / "streaming"
FFMPEG_DOWNLOAD_URL = decrypt_text_literal("ffmpeg_download_url")
CLOUDFLARED_DOWNLOAD_URL = decrypt_text_literal("cloudflared_download_url")
WEBENGINE_PROCESS_NAME = str(decrypt_json_literal("player_status")["webengine_process_name"])
DOWNLOAD_TIMEOUT_SECONDS = 180.0
HLS_READY_TIMEOUT_SECONDS = 15.0
HLS_READY_POLL_SECONDS = 0.1
DEFAULT_STREAM_FPS = 30
LOW_FPS_STREAM_FPS = 10
SNAPSHOT_MODE_INTERVAL_MS = int(1000 / LOW_FPS_STREAM_FPS)
CLOUDFLARED_DEFAULT_PROTOCOL = "http2"
CLOUDFLARED_DEFAULT_EDGE_IP_VERSION = "4"
CLOUDFLARED_PUBLIC_URL_READY_TIMEOUT_SECONDS = 60.0
CLOUDFLARED_PUBLIC_URL_READY_POLL_SECONDS = 0.5
CLOUDFLARED_PUBLIC_URL_CHECK_TIMEOUT_SECONDS = 3.0
CLOUDFLARED_PUBLIC_URL_RESTART_BACKOFF_SECONDS = 2.0
CLOUDFLARED_MAX_START_ATTEMPTS = 3
CHAT_MEMORY_SCAN_INTERVAL_SECONDS = 2.0
CHAT_MEMORY_SCAN_TIMEOUT_SECONDS = 30.0
CHAT_MEMORY_LATEST_STALE_GRACE_SECONDS = 1.0
CHAT_CONFIRM_SCAN_INTERVAL_SECONDS = 1.0
CHAT_CONFIRM_SCAN_TIMEOUT_SECONDS = 10.0
CHAT_CONFIRM_RETENTION_SECONDS = 120.0
CHAT_MEMORY_OUT_DIR = LOG_DIR / "chat_memory"
CHAT_MEMORY_LATEST_JSON = CHAT_MEMORY_OUT_DIR / "chat_history_latest.json"


@dataclass(frozen=True, slots=True)
class StreamQuality:
    name: str
    height: int
    bitrate: str
    low_fps_bitrate: str

    def bitrate_for_fps(self, fps: int) -> str:
        if fps == LOW_FPS_STREAM_FPS:
            return self.low_fps_bitrate
        return self.bitrate


STREAM_QUALITIES: dict[str, StreamQuality] = {
    "480p": StreamQuality("480p", 480, "1200k", "600k"),
    "720p": StreamQuality("720p", 720, "2900k", "1500k"),
    "1080p": StreamQuality("1080p", 1080, "5000k", "2300k"),
}


@dataclass(frozen=True, slots=True)
class StreamSnapshot:
    active: bool
    status: str
    quality: str
    area: str
    chat_zoom_enabled: bool
    snapshot_mode_enabled: bool
    snapshot_interval_ms: int
    chat_memory_enabled: bool
    chat_mode_enabled: bool
    local_url: str | None
    public_url: str | None
    stream_url: str | None
    hls_url: str | None
    started_at: float | None
    last_viewer_activity_at: float | None
    seconds_until_auto_stop: int | None
    error: str
    chat_active: bool = False
    chat_tabs: tuple[ChatTab, ...] = ()
    chat_selected_tab_id: str | None = None
    chat_status_error: str = ""
    chat_last_action: str = ""
    chat_memory_loading: bool = False
    chat_history: dict[str, object] | None = None
    license_role: str = "user"
    chat_commands: tuple[ChatCommand, ...] = CHAT_COMMANDS


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
    * {
      scrollbar-width: thin;
      scrollbar-color: rgba(154, 174, 205, 0.86) rgba(237, 243, 251, 0.12);
    }
    *::-webkit-scrollbar {
      width: 10px;
      height: 10px;
    }
    *::-webkit-scrollbar-track {
      background: rgba(237, 243, 251, 0.12);
      border-radius: 999px;
    }
    *::-webkit-scrollbar-thumb {
      background: rgba(154, 174, 205, 0.86);
      border-radius: 999px;
      border: 2px solid transparent;
      background-clip: padding-box;
    }
    *::-webkit-scrollbar-thumb:hover {
      background: rgba(184, 201, 228, 0.95);
      background-clip: padding-box;
    }
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
    .playerShell {
      min-width: 0;
      align-self: stretch;
      display: flex;
      flex-direction: column;
    }
    .streamHidden {
      display: none !important;
    }
    .video-js {
      width: 100%;
      height: min(68vh, calc(100vh - 390px));
      min-height: 360px;
      border-radius: 8px;
      overflow: hidden;
      background: #05070a;
      box-shadow: 0 18px 60px rgba(0, 0, 0, 0.42);
    }
    .side {
      align-self: stretch;
      border: 1px solid rgba(255, 255, 255, 0.10);
      border-radius: 8px;
      background: rgba(20, 25, 32, 0.88);
      padding: 14px;
      backdrop-filter: blur(12px);
      transition: min-height 180ms ease, padding-bottom 180ms ease;
    }
    .chatPanel {
      overflow: hidden;
      max-height: 720px;
      opacity: 1;
      transform: translateY(0);
      transition: max-height 180ms ease, opacity 150ms ease, transform 180ms ease, margin-top 180ms ease;
    }
    .chatPanel.collapsed {
      max-height: 0;
      opacity: 0;
      margin-top: -8px;
      transform: translateY(-4px);
      pointer-events: none;
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
      margin: 0;
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
    .commandGrid {
      display: flex;
      flex-wrap: wrap;
      gap: 8px;
      align-items: center;
      position: relative;
    }
    .commandHelpButton {
      width: 32px;
      height: 32px;
      border-radius: 50%;
      border: 1px solid rgba(255, 255, 255, 0.18);
      background: rgba(124, 183, 255, 0.16);
      color: #f4f7fb;
      font-weight: 900;
      cursor: pointer;
    }
    .commandHelpPanel {
      border: 1px solid rgba(255, 255, 255, 0.12);
      border-radius: 8px;
      background: rgba(11, 15, 21, 0.94);
      padding: 10px 12px;
      color: #dce7f7;
      display: grid;
      gap: 7px;
      font-size: 13px;
      line-height: 1.35;
    }
    .commandHelpPanel strong {
      color: #ffffff;
    }
    .chatTabs {
      display: flex;
      flex-wrap: wrap;
      gap: 8px;
    }
    .chatTab {
      border: 1px solid rgba(255, 255, 255, 0.10);
      border-radius: 6px;
      padding: 7px 12px;
      color: #eef3fb;
      background: rgba(5, 8, 12, 0.62);
      cursor: pointer;
      font-weight: 800;
    }
    .chatTab.active {
      background: linear-gradient(180deg, #c2376f, #951d4f);
      border-color: rgba(255, 148, 190, 0.55);
    }
    .chatTab.pending {
      opacity: 0.72;
    }
    .chatTab:disabled {
      cursor: default;
      opacity: 0.45;
    }
    .chatHint {
      min-height: 18px;
      color: #d6dce6;
      font-size: 13px;
      font-weight: 700;
    }
    .chatActions {
      display: grid;
      grid-template-columns: 1fr 1fr;
      gap: 10px;
    }
    .streamControls {
      display: flex;
      flex-wrap: wrap;
      gap: 12px;
      align-items: center;
    }
    .chatLayout {
      display: grid;
      grid-template-columns: minmax(320px, 0.8fr) minmax(360px, 1.2fr);
      gap: 14px;
      align-items: start;
    }
    .chatLayout.historyOnly {
      grid-template-columns: 1fr;
    }
    .chatComposer {
      display: flex;
      flex-direction: column;
      gap: 10px;
    }
    .chatHistory {
      max-height: 300px;
      overflow: auto;
      padding-right: 4px;
      display: flex;
      flex-direction: column;
      gap: 8px;
    }
    .chatMessage {
      display: grid;
      grid-template-columns: 30px minmax(0, 1fr);
      gap: 8px;
      align-items: start;
      padding: 8px 9px;
      border-radius: 8px;
      background: rgba(255, 255, 255, 0.055);
      border-left: 3px solid var(--msg-color, #7cb7ff);
      animation: messageIn 180ms ease-out;
    }
    .chatMessage.pendingMessage {
      background: rgba(124, 183, 255, 0.13);
    }
    .messageInfo {
      width: 24px;
      height: 24px;
      border-radius: 50%;
      border: 1px solid rgba(255, 255, 255, 0.12);
      background: rgba(0, 0, 0, 0.24);
      color: #dce8f7;
      cursor: help;
      line-height: 22px;
      text-align: center;
      font-size: 13px;
    }
    .orgIcon {
      width: 20px;
      height: 20px;
      object-fit: contain;
      margin-right: 6px;
      vertical-align: -4px;
      filter: drop-shadow(0 1px 2px rgba(0, 0, 0, 0.45));
    }
    .infoPopover,
    .commandPopover {
      max-width: min(360px, calc(100vw - 28px));
      background: rgba(11, 15, 21, 0.98);
      color: #edf4ff;
      border: 1px solid rgba(255, 255, 255, 0.14);
      border-radius: 8px;
      padding: 10px 12px;
      white-space: pre-line;
      font-size: 13px;
      line-height: 1.45;
    }
    .messageBody {
      min-width: 0;
      white-space: pre-wrap;
      overflow-wrap: anywhere;
      line-height: 1.35;
      font-size: 14px;
    }
    .messageMeta {
      color: #98a6b8;
      font-size: 12px;
      margin-bottom: 2px;
    }
    .messageAuthor {
      color: #ffe08a;
      font-weight: 800;
      margin-right: 6px;
    }
    .skeleton {
      display: flex;
      flex-direction: column;
      gap: 8px;
    }
    .skeletonLine {
      height: 18px;
      border-radius: 6px;
      background: rgba(255, 255, 255, 0.08);
    }
    .skeleton.loading .skeletonLine {
      background: linear-gradient(90deg, rgba(255,255,255,0.06), rgba(255,255,255,0.18), rgba(255,255,255,0.06));
      background-size: 220% 100%;
      animation: shimmer 1.15s linear infinite;
    }
    @keyframes shimmer {
      from { background-position: 120% 0; }
      to { background-position: -120% 0; }
    }
    @keyframes messageIn {
      from { opacity: 0; transform: translateY(-4px); }
      to { opacity: 1; transform: translateY(0); }
    }
    .side .MuiOutlinedInput-root {
      background: rgba(255, 255, 255, 0.08);
      color: #f4f7fb;
    }
    .side .MuiOutlinedInput-notchedOutline {
      border-color: rgba(255, 255, 255, 0.28);
    }
    .side .MuiOutlinedInput-root:hover .MuiOutlinedInput-notchedOutline {
      border-color: rgba(255, 255, 255, 0.44);
    }
    .side .MuiOutlinedInput-root.Mui-focused .MuiOutlinedInput-notchedOutline {
      border-color: #ffd166;
    }
    .side .MuiInputLabel-root {
      color: #cfd8e6;
    }
    .side .MuiInputLabel-root.Mui-focused {
      color: #fff2bd;
      background: rgba(11, 15, 21, 0.98);
      padding: 0 4px;
      border-radius: 4px;
    }
    .side .MuiInputBase-input,
    .side .MuiSelect-select,
    .side .MuiInputLabel-root,
    .side .MuiSvgIcon-root {
      color: #f4f7fb;
    }
    .side .Mui-disabled {
      -webkit-text-fill-color: rgba(244, 247, 251, 0.46);
    }
    @media (max-width: 900px) {
      .page {
        padding: 10px;
      }
      .video-js {
        height: 58vh;
      }
      .statusGrid,
      .chatLayout,
      .topBar {
        grid-template-columns: 1fr;
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
      Popover,
      Stack,
      Switch,
      TextField,
      Tooltip,
      Typography,
    } = MaterialUI;

    function formatStatus(status) {
      if (status === "online") return "online";
      if (status === "starting") return "запуск";
      if (status === "error") return "ошибка";
      return "offline";
    }

    function chatHint(message, commands) {
      const text = (message || "").trimStart();
      const match = text.match(/^\/([^\s/]+)(?:\s|$)/);
      if (!match) return "Обычный локальный IC";
      const code = `/${match[1].toLowerCase()}`;
      const command = (commands || []).find((item) => item.code === code);
      if (command) return command.title;
      if (code === "/m") {
        const meCommand = (commands || []).find((item) => item.code === "/me");
        return meCommand ? meCommand.title : "RP-действие";
      }
      return "Команда чата";
    }

    function applyCommandToMessage(message, code) {
      const body = (message || "").replace(/^\/[^\s/]+(?:\s+|$)/, "");
      return code ? `${code} ${body}` : body;
    }

    function messageKindTitle(kind, record = null) {
      if (kind === "pending") {
        if (record?.sending) return "Отправляется";
        if (record?.sent) return "Ждёт дамп";
        if (record?.deliveryError) return "Не подтверждено";
        return "Ждёт подтверждения";
      }
      return ({
        default: "Локальный IC",
        family: "Семейный",
        fraction: "Фракция",
        gov: "Департамент",
        news: "Новости",
        system: "Система",
        me: "Действие",
        admin: "Админ",
        report: "Репорт",
      })[kind] || "Сообщение";
    }

    function messageColor(record) {
      const kind = record?.type || record?.kind || "default";
      return record?.color || ({
        default: "#f4f7fb",
        family: "#f745a4",
        fraction: "#7cb7ff",
        gov: "#33ccff",
        news: "#ffa500",
        system: "#ffffff",
        me: "#bd8cff",
        admin: "#ff6969",
        report: "#7ee787",
        pending: "#7cb7ff",
      })[kind] || "#7cb7ff";
    }

    function stripChatPrefix(text) {
      return String(text || "").replace(/^\[(?:default|global|fam|frac|gov|report|admin|me|Weazel News| el News)\]\s*/i, "");
    }

    function tabAllowsRecord(tabId, record) {
      const type = String(record?.type || "");
      const text = String(record?.text || "");
      if (!tabId || tabId === "all") return true;
      if (tabId === "fam") return type === "family" || text.startsWith("[fam]");
      if (tabId === "frac") return type === "fraction" || text.startsWith("[frac]");
      if (tabId === "gov") return type === "gov" || text.startsWith("[gov]") || text.startsWith("[ el News]");
      if (tabId === "report") return type === "report" || text.startsWith("[report]");
      return true;
    }

    function recordTabId(record) {
      const type = String(record?.type || "");
      const text = String(record?.text || "");
      if (type === "family" || text.startsWith("[fam]")) return "fam";
      if (type === "fraction" || text.startsWith("[frac]")) return "frac";
      if (type === "gov" || text.startsWith("[gov]") || text.startsWith("[ el News]")) return "gov";
      if (type === "report" || text.startsWith("[report]")) return "report";
      return "all";
    }

    function formatMessageTitle(record) {
      const staticId = record?.staticId ? `#${record.staticId}` : "";
      const name = record?.playerName || record?.owner?.name || "";
      return [staticId, name].filter(Boolean).join(" ");
    }

    function stableRecordKey(record) {
      if (record?.occurrenceId) return `occ-${record.occurrenceId}`;
      if (record?.messageId) return `msg-${record.messageId}`;
      if (record?.stableId) return `stable-${record.stableId}`;
      const raw = [
        record?.type || record?.kind || "",
        record?.time || "",
        record?.timestamp || "",
        record?.order || "",
        record?.staticId || "",
        record?.playerId || "",
        record?.text || "",
      ].join("|");
      let hash = 0;
      for (let index = 0; index < raw.length; index += 1) {
        hash = ((hash << 5) - hash + raw.charCodeAt(index)) | 0;
      }
      return `hash-${Math.abs(hash)}`;
    }

    function normalizeChatSearchText(value) {
      return String(value || "")
        .replace(/\s+/g, " ")
        .replace(/[.,!?;:]+$/g, "")
        .trim()
        .toLowerCase();
    }

    function outboxConfirmationCandidates(message) {
      const raw = normalizeChatSearchText(message);
      const candidates = raw ? [raw] : [];
      const match = String(message || "").trim().match(/^\/([^\s/]+)(?:\s+([\s\S]+))?$/);
      if (match) {
        const body = normalizeChatSearchText(match[2] || "");
        if (body) candidates.push(body);
      }
      return [...new Set(candidates)];
    }

    function recordConfirmsOutbox(record, item) {
      const recordText = normalizeChatSearchText(record?.text || "");
      if (!recordText) return false;
      return outboxConfirmationCandidates(item?.text).some((candidate) => candidate && recordText.includes(candidate));
    }

    function confirmedOutboxMatches(item, confirmed) {
      const confirmedText = normalizeChatSearchText(confirmed?.text || confirmed);
      if (!confirmedText) return false;
      return outboxConfirmationCandidates(item?.text).some((candidate) => candidate && (
        confirmedText === candidate || confirmedText.includes(candidate) || candidate.includes(confirmedText)
      ));
    }

    function chatSendSucceeded(payload) {
      const action = String(payload?.chat_last_action || "").toLowerCase();
      return Boolean(payload && !payload.error && action.includes("отправлено"));
    }

    function organizationIcon(record) {
      const source = [
        record?.organization,
        record?.owner?.organization,
        record?.owner?.name,
        record?.owner?.role,
        record?.owner?.kind,
        record?.role,
        record?.type,
        record?.kind,
        record?.text,
      ].filter(Boolean).join(" ").toLowerCase();
      const mappings = [
        ["weazle-news", ["weazel", "weazle", "news", "новост"]],
        ["government", ["government", "правитель", "gov"]],
        ["ems", ["ems", "medical", "emergency", "медиц"]],
        ["fib", ["fib", "federal", "investigation"]],
        ["sheriff", ["sheriff", "шериф"]],
        ["lspd", ["lspd", "police", "полици"]],
        ["sang", ["sang", "national guard", "guard", "арм"]],
        ["ballas", ["ballas"]],
        ["vagos", ["vagos"]],
        ["famillies", ["families", "famillies"]],
        ["bloods", ["bloods"]],
        ["marabunta", ["marabunta"]],
        ["fam", ["family", "семья", "[fam]", "familia"]],
      ];
      const match = mappings.find(([, aliases]) => aliases.some((alias) => source.includes(alias)));
      return match ? `/assets/chat-icons/${match[0]}.png` : "";
    }

    function messageTooltip(record, isAdmin) {
      const raw = record?.raw_fields || {};
      const rows = [
        ["🧾", "Вид", messageKindTitle(record?.type || record?.kind, record)],
        ["🆔", "ID", record?.visible_playerId || record?.playerId || raw.visible_playerId || ""],
        ["👤", "Имя", record?.playerName || record?.owner?.name || ""],
        ["🎭", "Тип", record?.role || record?.owner?.kind || raw.visible_kind || ""],
        ["🛡", "Роль", record?.owner?.role || ""],
        ["#️⃣", "Static ID", record?.staticId || ""],
        ["⚠️", "Ошибка", record?.deliveryError || ""],
      ];
      if (isAdmin) {
        rows.push(["📨", "ID сообщения", record?.messageId || record?.stableId || ""]);
        rows.push(["🧩", "Источник", record?.source || ""]);
        rows.push(["🎨", "Цвет", record?.color || ""]);
      }
      return rows.filter((row) => row[2]).map((row) => `${row[0]} ${row[1]}: ${row[2]}`).join("\n") || "Данных пока нет";
    }

    function Skeleton({ loading = false }) {
      return React.createElement("div", { className: `skeleton${loading ? " loading" : ""}` },
        [92, 76, 84, 64, 88, 70].map((width, index) =>
          React.createElement("div", {
            key: index,
            className: "skeletonLine",
            style: { width: `${width}%` },
          })
        )
      );
    }

    function App() {
      const videoRef = useRef(null);
      const playerRef = useRef(null);
      const sourceKeyRef = useRef("");
      const tabRequestRef = useRef(0);
      const wasActiveRef = useRef(false);
      const statusJsonRef = useRef("");
      const chatJsonRef = useRef("");
      const outboxRef = useRef([]);
      const [status, setStatus] = useState(null);
      const [chatState, setChatState] = useState(null);
      const [busy, setBusy] = useState(false);
      const [tabBusy, setTabBusy] = useState(false);
      const [message, setMessage] = useState("");
      const [selectedTabId, setSelectedTabId] = useState("");
      const [outbox, setOutbox] = useState([]);
      const [commandHelpAnchor, setCommandHelpAnchor] = useState(null);
      const [infoAnchor, setInfoAnchor] = useState(null);
      const [infoRecord, setInfoRecord] = useState(null);

      async function refresh() {
        const response = await fetch("/api/stream/status", { cache: "no-store" });
        const payload = await response.json();
        const nextJson = JSON.stringify(payload);
        if (nextJson !== statusJsonRef.current) {
          statusJsonRef.current = nextJson;
          setStatus(payload);
        }
      }

      async function refreshChat() {
        const response = await fetch("/api/stream/chat", { cache: "no-store" });
        const payload = await response.json();
        const nextJson = JSON.stringify(payload);
        if (nextJson !== chatJsonRef.current) {
          chatJsonRef.current = nextJson;
          setChatState(payload);
        }
        return payload;
      }

      const chatData = chatState || status || {};

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
        const enabled = Boolean(status?.chat_memory_enabled || status?.chat_mode_enabled);
        if (!enabled) {
          setChatState(null);
          chatJsonRef.current = "";
          return;
        }
        let stopped = false;
        const tick = () => {
          if (stopped) return;
          refreshChat().catch(() => {});
        };
        tick();
        const timer = setInterval(tick, 2200);
        return () => {
          stopped = true;
          clearInterval(timer);
        };
      }, [status?.chat_memory_enabled, status?.chat_mode_enabled]);

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

      useEffect(() => {
        const tabs = (chatData?.chat_tabs || chatData?.chat_history?.tabs || []).filter((tab) => tab.available !== false);
        if (!tabs.length) {
          setSelectedTabId("all");
          return;
        }
        if (selectedTabId && tabs.some((tab) => tab.id === selectedTabId)) {
          if ((chatData?.chat_selected_tab_id || "") === selectedTabId) setTabBusy(false);
          return;
        }
        const selected = tabs.find((tab) => tab.selected) || tabs[0];
        setSelectedTabId(selected.id);
      }, [chatData?.chat_selected_tab_id, chatData?.chat_tabs?.length, chatData?.chat_history?.tabs?.length]);

      useEffect(() => {
        const records = chatData?.chat_history?.records || [];
        const confirmedOutbox = chatData?.chat_confirmed_outbox || [];
        if (!outbox.length) return;
        const nextOutbox = outbox.map((item) => {
          if (confirmedOutbox.some((confirmed) => confirmedOutboxMatches(item, confirmed))) return { ...item, confirmed: true };
          if (records.some((record) => recordConfirmsOutbox(record, item))) return { ...item, confirmed: true };
          if (item.sent) return item;
          const misses = (item.misses || 0) + 1;
          if (misses < 12) return { ...item, misses };
          return {
            ...item,
            misses,
            deliveryError: "Сообщение отправлено, но пока не найдено в истории памяти чата.",
          };
        });
        const visible = nextOutbox
          .filter((item) => !item.confirmed);
        if (JSON.stringify(visible) !== JSON.stringify(outboxRef.current)) {
          outboxRef.current = visible;
          setOutbox(visible);
        }
      }, [chatData?.chat_history?.updated_at, chatData?.chat_history?.records?.length, chatData?.chat_confirmed_outbox?.length]);

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

      const areaText = status?.area === "chat" ? "Чат" : "Все окно";
      const autoStopText = useMemo(() => {
        if (!status?.active || status.seconds_until_auto_stop == null) return "-";
        const seconds = Math.max(0, status.seconds_until_auto_stop);
        const minutes = Math.floor(seconds / 60);
        const rest = String(seconds % 60).padStart(2, "0");
        return `${minutes}:${rest}`;
      }, [status]);
      const chatModeActive = Boolean(chatData?.chat_mode_enabled || status?.chat_mode_enabled);
      const chatMemoryEnabled = Boolean(chatData?.chat_memory_enabled || status?.chat_memory_enabled || chatModeActive);
      const chatModeTransitioning = Boolean(chatModeActive && !chatData?.chat_active);
      const chatReady = Boolean(chatData?.chat_active);
      const memoryTabs = chatData?.chat_history?.tabs || [];
      const defaultTabs = [{ id: "all", name: "Все", active: true, available: true }];
      const role = String(chatData?.license_role || status?.license_role || "user").toLowerCase();
      const isAdmin = role === "admin" || role === "administrator" || role === "owner";
      const chatTabs = (chatReady ? (chatData?.chat_tabs || memoryTabs) : memoryTabs).filter((tab) => isAdmin || tab.available !== false);
      const visibleTabs = chatTabs.length ? chatTabs : defaultTabs;
      const chatCommands = chatData?.chat_commands || status?.chat_commands || [];
      const selectedTab = visibleTabs.find((tab) => tab.id === selectedTabId) || visibleTabs.find((tab) => tab.selected || tab.active) || visibleTabs[0];
      const hintText = chatHint(message, chatCommands);
      const availableTabIds = new Set(visibleTabs.filter((tab) => tab.available !== false).map((tab) => tab.id));
      const records = (chatData?.chat_history?.records || [])
        .filter((record) => isAdmin || availableTabIds.has(recordTabId(record)))
        .filter((record) => tabAllowsRecord(selectedTab?.id || "all", record))
        .slice()
        .sort((a, b) => (b.order || b.timestamp || 0) - (a.order || a.timestamp || 0))
        .slice(0, 80);
      const displayRecords = [...outbox, ...records];
      const hasMemoryPayload = Boolean(memoryTabs.length || (chatData?.chat_history?.records || []).length);
      const showChatLoadingSkeleton = chatMemoryEnabled && !hasMemoryPayload && (chatData?.chat_memory_loading || chatModeTransitioning);

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

      async function setChatMode(enabled) {
        setBusy(true);
        try {
          const response = await fetch("/api/stream/chat-mode", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ enabled }),
          });
          const nextStatus = await response.json();
          setStatus(nextStatus);
          await refreshChat();
        } finally {
          setBusy(false);
        }
      }

      async function setChatMemoryEnabled(enabled) {
        setBusy(true);
        try {
          const response = await fetch("/api/stream/chat-memory", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ enabled }),
          });
          const nextStatus = await response.json();
          setStatus(nextStatus);
          if (enabled) await refreshChat();
        } finally {
          setBusy(false);
        }
      }

      async function selectChatTab(tabId) {
        const nextTab = tabId || "all";
        setSelectedTabId(nextTab);
        if (!nextTab || !chatReady) return;
        const requestId = ++tabRequestRef.current;
        setTabBusy(true);
        try {
          const response = await fetch("/api/stream/chat-select", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ tab_id: nextTab }),
          });
          const nextStatus = await response.json();
          if (requestId === tabRequestRef.current) {
            setStatus(nextStatus);
            await refreshChat();
          }
        } finally {
          if (requestId === tabRequestRef.current) setTabBusy(false);
        }
      }

      async function clearChat() {
        setBusy(true);
        try {
          const response = await fetch("/api/stream/chat-clear", { method: "POST" });
          setStatus(await response.json());
          await refreshChat();
        } finally {
          setBusy(false);
        }
      }

      function updateOutbox(updater) {
        setOutbox((items) => {
          const nextItems = updater(items);
          outboxRef.current = nextItems;
          return nextItems;
        });
      }

      async function sendOutboxItem(item) {
        updateOutbox((items) => items.map((current) => current.stableId === item.stableId ? { ...current, sending: true, sent: false } : current));
        try {
          const response = await fetch("/api/stream/chat-send", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ tab_id: item.tabId || null, message: item.text }),
          });
          if (!response.ok) throw new Error(`HTTP ${response.status}`);
          const nextStatus = await response.json();
          setStatus(nextStatus);
          await refreshChat();
          if (chatSendSucceeded(nextStatus)) {
            updateOutbox((items) => items.map((current) => current.stableId === item.stableId ? {
              ...current,
              sending: false,
              sent: true,
              deliveryError: "",
            } : current));
          }
        } catch (error) {
          const errorText = error instanceof Error ? error.message : String(error || "");
          updateOutbox((items) => items.map((current) => current.stableId === item.stableId ? {
            ...current,
            deliveryError: `Не удалось отправить сообщение: ${errorText}`,
          } : current));
          throw error;
        } finally {
          updateOutbox((items) => items.map((current) => current.stableId === item.stableId ? { ...current, sending: false } : current));
        }
      }

      async function sendChatMessage() {
        if (!message.trim()) return;
        const text = message.trim();
        if (document.activeElement && typeof document.activeElement.blur === "function") {
          document.activeElement.blur();
        }
        const tempId = `pending-${Date.now()}`;
        const item = {
          messageId: tempId,
          stableId: tempId,
          type: "pending",
          text,
          time: "сейчас",
          createdAt: Date.now(),
          misses: 0,
          attempt: 1,
          tabId: selectedTab?.id || selectedTabId || null,
        };
        outboxRef.current = [item, ...outboxRef.current];
        setOutbox((items) => [item, ...items]);
        setBusy(true);
        try {
          await sendOutboxItem(item);
          setMessage("");
        } catch (error) {
        } finally {
          setBusy(false);
        }
      }

      const chatHistoryNode = !chatMemoryEnabled
        ? null
        : showChatLoadingSkeleton
          ? React.createElement(Skeleton, { loading: true })
          : displayRecords.length
            ? (() => {
              const renderedKeys = new Map();
              return displayRecords.map((record) => {
                const color = messageColor(record);
                const title = formatMessageTitle(record);
                const body = stripChatPrefix(record.text);
                const baseKey = stableRecordKey(record);
                const seenCount = renderedKeys.get(baseKey) || 0;
                renderedKeys.set(baseKey, seenCount + 1);
                const key = seenCount ? `${baseKey}-${seenCount}` : baseKey;
                const icon = organizationIcon(record);
                return React.createElement("div", {
                  key,
                  className: `chatMessage${record.type === "pending" ? " pendingMessage" : ""}`,
                  style: { "--msg-color": color },
                },
                  React.createElement("button", {
                    className: "messageInfo",
                    type: "button",
                    onClick: (event) => {
                      setInfoAnchor(event.currentTarget);
                      setInfoRecord(record);
                    },
                  }, "!"),
                  React.createElement("div", { className: "messageBody" },
                    React.createElement("div", { className: "messageMeta" }, `${record.time || ""} · ${messageKindTitle(record.type, record)}`),
                    React.createElement("div", null,
                      icon ? React.createElement("img", {
                        className: "orgIcon",
                        src: icon,
                        alt: "",
                        onError: (event) => { event.currentTarget.style.display = "none"; },
                      }) : null,
                      title ? React.createElement("span", { className: "messageAuthor" }, title) : null,
                      body
                    )
                  )
                );
              });
            })()
            : React.createElement("div", { className: "comment" }, "История чата пока пуста");

      const chatComposerNode = chatModeActive
        ? React.createElement("div", { className: "chatComposer" },
            React.createElement("div", { className: "chatHint" }, hintText),
            React.createElement(TextField, {
              label: "Сообщение в чат",
              size: "small",
              disabled: busy || !chatReady,
              value: message,
              multiline: true,
              minRows: 3,
              onChange: (event) => setMessage(event.target.value),
              fullWidth: true,
            }),
            React.createElement("div", { className: "commandGrid" },
              chatCommands.filter((command) => command.code).map((command) =>
                React.createElement(Button, {
                  key: command.key,
                  variant: "outlined",
                  size: "small",
                  disabled: busy || !chatReady,
                  title: `${command.title}: ${command.description}`,
                  onClick: () => setMessage((current) => applyCommandToMessage(current, command.code)),
                }, command.code)
              ),
              React.createElement("button", {
                className: "commandHelpButton",
                type: "button",
                onClick: (event) => setCommandHelpAnchor(event.currentTarget),
                "aria-label": "Справка по командам чата",
                title: "Справка по командам",
              }, "?")
            ),
            React.createElement("div", { className: "chatActions" },
              React.createElement(Button, {
                variant: "outlined",
                color: "inherit",
                disabled: busy || !chatReady,
                onClick: clearChat,
              }, "Очистить"),
              React.createElement(Button, {
                variant: "contained",
                disabled: busy || !chatReady || !message.trim(),
                onClick: sendChatMessage,
              }, "Отправить")
            )
          )
        : null;

      return React.createElement("main", { className: "page" },
        React.createElement("section", { className: "playerShell" },
          React.createElement("video", {
            ref: videoRef,
            className: "video-js vjs-big-play-centered",
            playsInline: true,
          })
        ),
        React.createElement("aside", { className: "side" },
          React.createElement(Stack, { spacing: 1.5 },
            React.createElement("div", { className: "topBar" },
              React.createElement(Stack, { spacing: 1 },
                React.createElement(Stack, { direction: "row", spacing: 1, alignItems: "center", flexWrap: "wrap" },
                  React.createElement(Typography, { variant: "h5", component: "h1" }, "Стрим игры"),
                  React.createElement(Chip, {
                    label: formatStatus(status?.status),
                    color: status?.status === "online" ? "success" : status?.status === "error" ? "error" : "default",
                    size: "small",
                  })
                ),
                React.createElement("div", { className: "comment" }, "Задержка трансляции может достигать 15 секунд.")
              ),
              React.createElement("div", { className: "streamControls" },
                React.createElement(FormControlLabel, {
                  control: React.createElement(Switch, {
                    checked: Boolean(status?.chat_zoom_enabled),
                    disabled: busy,
                    onChange: (event) => setChatZoom(event.target.checked),
                  }),
                  label: "Увеличить чат",
                }),
                React.createElement(FormControlLabel, {
                  control: React.createElement(Switch, {
                    checked: Boolean(status?.snapshot_mode_enabled),
                    disabled: busy,
                    onChange: (event) => setSnapshotMode(event.target.checked),
                  }),
                  label: "Режим 10fps",
                }),
                React.createElement(FormControlLabel, {
                  control: React.createElement(Switch, {
                    checked: chatMemoryEnabled,
                    disabled: busy || chatModeActive,
                    onChange: (event) => setChatMemoryEnabled(event.target.checked),
                  }),
                  label: "Чат",
                }),
                React.createElement(Button, {
                  variant: "contained",
                  color: "warning",
                  disabled: busy || chatModeTransitioning || (!status?.active && !chatModeActive),
                  onClick: () => setChatMode(!chatModeActive),
                }, chatModeActive ? "Выйти из режима чата" : "Включить режим чата")
              )
            ),
            React.createElement("div", { className: "statusGrid" },
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
              ),
              React.createElement("div", { className: "metric" },
                React.createElement("div", { className: "metricLabel" }, "Режим чата"),
                React.createElement("div", { className: "metricValue" }, chatData?.chat_active ? "Активен" : chatModeActive ? "Открываю" : "Выключен")
              )
            ),
            status?.error ? React.createElement(Chip, { label: status.error, color: "error", variant: "outlined" }) : null,
            React.createElement(Divider, null),
            React.createElement("div", { className: `chatPanel${chatMemoryEnabled ? "" : " collapsed"}` },
              React.createElement("div", { className: "chatTabs" },
                visibleTabs.map((tab) =>
                  React.createElement("button", {
                    key: tab.id,
                    className: `chatTab${(selectedTab?.id || "all") === tab.id ? " active" : ""}${tabBusy ? " pending" : ""}`,
                    disabled: busy || !chatModeActive || !chatReady || tabBusy,
                    onClick: () => selectChatTab(tab.id),
                    type: "button",
                  }, tab.name)
                )
              ),
              React.createElement("div", { className: `chatLayout${chatComposerNode ? "" : " historyOnly"}` },
                chatComposerNode,
                React.createElement("div", { className: "chatHistory" }, chatHistoryNode)
              ),
              chatData?.chat_last_action ? React.createElement("div", { className: "comment" }, chatData.chat_last_action) : null,
              chatData?.chat_status_error ? React.createElement(Chip, { label: chatData.chat_status_error, color: "error", variant: "outlined" }) : null
            ),
            React.createElement(Popover, {
              open: Boolean(infoAnchor),
              anchorEl: infoAnchor,
              onClose: () => { setInfoAnchor(null); setInfoRecord(null); },
              anchorOrigin: { vertical: "center", horizontal: "left" },
              transformOrigin: { vertical: "center", horizontal: "right" },
            }, React.createElement("div", { className: "infoPopover" }, messageTooltip(infoRecord || {}, isAdmin))),
            React.createElement(Popover, {
              open: Boolean(commandHelpAnchor),
              anchorEl: commandHelpAnchor,
              onClose: () => setCommandHelpAnchor(null),
              anchorOrigin: { vertical: "top", horizontal: "right" },
              transformOrigin: { vertical: "bottom", horizontal: "right" },
            }, React.createElement("div", { className: "commandPopover" },
              chatCommands.filter((command) => command.code).map((command) =>
                React.createElement("div", { key: `help-${command.key}` },
                  React.createElement("strong", null, command.code),
                  ` - ${command.title}: ${command.description}`
                )
              )
            ))
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
        chat_mode_callback: Callable[[], ChatActionResult | ChatDetection | None] | None = None,
        chat_exit_callback: Callable[[], ChatActionResult | ChatDetection | None] | None = None,
        chat_status_callback: Callable[[], ChatDetection] | None = None,
        chat_select_callback: Callable[[str | None], ChatActionResult] | None = None,
        chat_send_callback: Callable[[str | None, str], ChatActionResult] | None = None,
        chat_clear_callback: Callable[[], ChatActionResult] | None = None,
        game_window_available_callback: Callable[[], bool] | None = None,
        snapshot_mode_changed_callback: Callable[[bool], None] | None = None,
        license_role_callback: Callable[[], str] | None = None,
        clock: Callable[[], float] = time.monotonic,
        popen_factory: Callable[..., subprocess.Popen] = subprocess.Popen,
        temp_root: Path | None = None,
        viewer_timeout_seconds: float = VIEWER_TIMEOUT_SECONDS,
        prewarm_binaries: bool = True,
    ) -> None:
        self.log_callback = log_callback
        self.chat_mode_callback = chat_mode_callback
        self.chat_exit_callback = chat_exit_callback
        self.chat_status_callback = chat_status_callback
        self.chat_select_callback = chat_select_callback
        self.chat_send_callback = chat_send_callback
        self.chat_clear_callback = chat_clear_callback
        self.game_window_available_callback = game_window_available_callback
        self.snapshot_mode_changed_callback = snapshot_mode_changed_callback
        self.license_role_callback = license_role_callback
        self.clock = clock
        self.popen_factory = popen_factory
        self.temp_root = temp_root or STREAMING_RUNTIME_DIR
        self.viewer_timeout_seconds = viewer_timeout_seconds
        self._lock = threading.RLock()
        self._quality = "720p"
        self._active = False
        self._status = "offline"
        self._error = ""
        self._chat_zoom_enabled = False
        self._snapshot_mode_enabled = False
        self._chat_memory_enabled = False
        self._chat_memory_restore_enabled = False
        self._chat_mode_enabled = False
        self._chat_detection = ChatDetection()
        self._chat_detection_at = -1_000_000.0
        self._chat_last_action = ""
        self._chat_memory: dict[str, object] = {}
        self._chat_memory_at = -1_000_000.0
        self._chat_memory_loading = False
        self._chat_memory_scan_running = False
        self._chat_memory_generation = 0
        self._chat_memory_error = ""
        self._chat_recent_sends: list[dict[str, object]] = []
        self._chat_confirm_scan_at = -1_000_000.0
        self._chat_confirm_scan_running = False
        self._chat_confirm_process: tuple[str, int] | None = None
        self._chat_action_lock = threading.Lock()
        self._started_at: float | None = None
        self._last_viewer_activity_at: float | None = None
        self._runtime_dir = self.temp_root / f"{STREAM_RUNTIME_PREFIX}runtime-{uuid.uuid4().hex}"
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
        self._tunnel_provider = ""
        self._cloudflared_start_attempts = 0
        self._audio_fallback_video_only = False
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
            if self.game_window_available_callback is not None and not self.game_window_available_callback():
                self._error = "Окно игры не найдено"
                self._status = "error"
                self._log("Стрим не запущен: окно игры не найдено")
                return False
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
        self._disable_chat_mode_before_stream_stop()
        with self._lock:
            if not self._active and self._status == "offline":
                return
            self._log(f"Стрим остановлен: {reason}")
            self._stop_runtime_locked(clean_temp=True)

    def shutdown(self) -> None:
        self._disable_chat_mode_before_stream_stop()
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
        self._refresh_chat_detection_if_needed()
        self._refresh_chat_memory_if_needed()
        with self._lock:
            return self._snapshot_locked()

    def chat_snapshot(self) -> dict[str, object]:
        self._refresh_chat_detection_if_needed()
        self._refresh_chat_memory_if_needed()
        self._refresh_chat_confirmations_if_needed()
        with self._lock:
            snapshot = self._snapshot_locked()
            return {
                "chat_memory_enabled": snapshot.chat_memory_enabled,
                "chat_mode_enabled": snapshot.chat_mode_enabled,
                "chat_active": snapshot.chat_active,
                "chat_tabs": snapshot.chat_tabs,
                "chat_selected_tab_id": snapshot.chat_selected_tab_id,
                "chat_status_error": snapshot.chat_status_error,
                "chat_last_action": snapshot.chat_last_action,
                "chat_memory_loading": snapshot.chat_memory_loading,
                "chat_history": snapshot.chat_history,
                "chat_confirmed_outbox": self._chat_confirmed_outbox_locked(),
                "license_role": snapshot.license_role,
                "chat_commands": snapshot.chat_commands,
            }

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

    def set_snapshot_mode_enabled(self, enabled: bool) -> bool:
        enabled = bool(enabled)
        should_restart = False
        with self._lock:
            if self._snapshot_mode_enabled == enabled:
                return True
            self._snapshot_mode_enabled = enabled
            if self.snapshot_mode_changed_callback is not None:
                try:
                    self.snapshot_mode_changed_callback(enabled)
                except Exception as exc:
                    self._log(f"Не удалось сохранить режим 10fps: {exc}")
            if not self._active:
                return True
            should_restart = True
        if should_restart:
            self._restart_ffmpeg()
        return True

    def set_chat_memory_enabled(self, enabled: bool) -> StreamSnapshot:
        with self._lock:
            if self._chat_mode_enabled:
                self._chat_memory_enabled = True
            else:
                self._chat_memory_enabled = bool(enabled)
                if not self._chat_memory_enabled:
                    self._chat_memory_loading = False
        if enabled:
            self._refresh_chat_memory_if_needed(force=True)
        return self.snapshot()

    def enable_chat_mode(self) -> StreamSnapshot:
        result: ChatActionResult | ChatDetection | None = None
        with self._lock:
            previous_chat_memory_enabled = self._chat_memory_enabled
            self._chat_memory_restore_enabled = previous_chat_memory_enabled
            self._chat_memory_enabled = True
        if self.chat_mode_callback is not None:
            with self._chat_action_lock:
                result = self.chat_mode_callback()
        with self._lock:
            self._chat_mode_enabled = not (isinstance(result, ChatActionResult) and not result.ok)
            self._apply_chat_result_locked(result)
            if self._chat_mode_enabled:
                self._chat_memory = {}
                self._chat_memory_error = ""
                self._chat_memory_enabled = True
            else:
                self._chat_memory_enabled = previous_chat_memory_enabled
        self.set_chat_zoom_enabled(True)
        self._refresh_chat_memory_if_needed(force=True)
        return self.snapshot()

    def disable_chat_mode(self, *, force: bool = False) -> StreamSnapshot:
        result: ChatActionResult | ChatDetection | None = None
        if self.chat_exit_callback is not None:
            with self._chat_action_lock:
                result = self.chat_exit_callback()
        with self._lock:
            self._chat_mode_enabled = not force and isinstance(result, ChatActionResult) and not result.ok
            self._apply_chat_result_locked(result)
            if not self._chat_mode_enabled:
                self._chat_memory_loading = False
                self._chat_memory_enabled = self._chat_memory_restore_enabled
        return self.snapshot()

    def set_chat_mode_enabled(self, enabled: bool) -> StreamSnapshot:
        if enabled:
            return self.enable_chat_mode()
        return self.disable_chat_mode()

    def _disable_chat_mode_before_stream_stop(self) -> None:
        with self._lock:
            chat_mode_enabled = self._chat_mode_enabled
        if chat_mode_enabled:
            self.disable_chat_mode(force=True)

    def send_chat_message(self, tab_id: str | None, message: str) -> StreamSnapshot:
        if self.chat_send_callback is None:
            with self._lock:
                self._error = "Режим чата недоступен"
            return self.snapshot()
        with self._chat_action_lock:
            result = self.chat_send_callback(tab_id, message)
        with self._lock:
            self._chat_mode_enabled = True
            self._chat_memory_enabled = True
            self._apply_chat_result_locked(result)
            if isinstance(result, ChatActionResult) and result.ok and message.strip():
                self._remember_chat_send_locked(message)
        self.set_chat_zoom_enabled(True)
        self._refresh_chat_memory_if_needed(force=True)
        self._refresh_chat_confirmations_if_needed(force=True)
        return self.snapshot()

    def select_chat_tab(self, tab_id: str | None) -> StreamSnapshot:
        if self.chat_select_callback is None:
            with self._lock:
                self._error = "Выбор вкладки чата недоступен"
            return self.snapshot()
        with self._chat_action_lock:
            result = self.chat_select_callback(tab_id)
        with self._lock:
            self._chat_mode_enabled = True
            self._chat_memory_enabled = True
            self._apply_chat_result_locked(result)
        self.set_chat_zoom_enabled(True)
        self._refresh_chat_memory_if_needed(force=True)
        return self.snapshot()

    def clear_chat_input(self) -> StreamSnapshot:
        if self.chat_clear_callback is None:
            with self._lock:
                self._error = "Очистка чата недоступна"
            return self.snapshot()
        with self._chat_action_lock:
            result = self.chat_clear_callback()
        with self._lock:
            self._chat_mode_enabled = True
            self._chat_memory_enabled = True
            self._apply_chat_result_locked(result)
        self.set_chat_zoom_enabled(True)
        self._refresh_chat_memory_if_needed(force=True)
        return self.snapshot()

    def mark_viewer_activity(self) -> None:
        with self._lock:
            if self._active:
                self._last_viewer_activity_at = self.clock()

    def stream_url(self) -> str | None:
        with self._lock:
            return self._stream_url_locked()

    def _refresh_chat_detection_if_needed(self, *, force: bool = False) -> None:
        with self._lock:
            if self.chat_status_callback is None:
                return
            if not force and not self._chat_mode_enabled:
                return
            now = self.clock()
            if not force and now - self._chat_detection_at < 1.0:
                return
            callback = self.chat_status_callback
            game_window_available_callback = self.game_window_available_callback
        if game_window_available_callback is not None and not game_window_available_callback():
            with self._lock:
                self._chat_detection = ChatDetection(error="Окно игры не найдено")
                self._chat_detection_at = self.clock()
            return
        try:
            detection = callback()
        except Exception as exc:
            detection = ChatDetection(error=str(exc))
        with self._lock:
            self._chat_detection = detection
            self._chat_detection_at = self.clock()

    def _refresh_chat_memory_if_needed(self, *, force: bool = False) -> None:
        with self._lock:
            if not (self._chat_memory_enabled or self._chat_mode_enabled):
                self._chat_memory_loading = False
                return
            now = self.clock()
            if self._chat_memory_scan_running:
                return
            if not force and now - self._chat_memory_at < CHAT_MEMORY_SCAN_INTERVAL_SECONDS:
                return
            self._chat_memory_scan_running = True
            self._chat_memory_loading = force and not bool(self._chat_memory)
            self._chat_memory_generation += 1
            generation = self._chat_memory_generation
        threading.Thread(
            target=self._chat_memory_scan_worker,
            args=(generation,),
            name="sonar-chat-memory-scan",
            daemon=True,
        ).start()

    def _chat_memory_scan_worker(self, generation: int) -> None:
        error = ""
        payload: dict[str, object] = {}
        CHAT_MEMORY_OUT_DIR.mkdir(parents=True, exist_ok=True)
        command = [
            sys.executable,
            "-m",
            "sonar.tools.dump_chat_history",
            "--process",
            "auto",
            "--max-chat-processes",
            "2",
            "--max-total-mb",
            "512",
            "--window-kb",
            "16",
            "--marker-hits",
            "400",
            "--window-cache-refresh-hits",
            "64",
            "--auto-max-total-mb",
            "512",
            "--auto-marker-hits",
            "256",
            "--window-cache-pad-kb",
            "32",
            "--state-window-cache-pad-kb",
            "16",
            "--progress",
            "0",
            "--print-records",
            "120",
            "--fragment-limit",
            "0",
            "--out-dir",
            str(CHAT_MEMORY_OUT_DIR),
        ]
        scan_started_at = time.time()
        try:
            run_kwargs: dict[str, object] = {
                "cwd": PROJECT_DIR / "02_sonar_app",
                "stdout": subprocess.DEVNULL,
                "stderr": subprocess.DEVNULL,
                "timeout": CHAT_MEMORY_SCAN_TIMEOUT_SECONDS,
                "check": False,
            }
            if os.name == "nt":
                run_kwargs["creationflags"] = getattr(subprocess, "CREATE_NO_WINDOW", 0)
            subprocess.run(
                command,
                **run_kwargs,
            )
        except subprocess.TimeoutExpired:
            error = f"Скан памяти чата не завершился за {CHAT_MEMORY_SCAN_TIMEOUT_SECONDS:.0f} сек."
        except Exception as exc:
            error = str(exc)
        try:
            if CHAT_MEMORY_LATEST_JSON.exists():
                latest_mtime = CHAT_MEMORY_LATEST_JSON.stat().st_mtime
                if latest_mtime + CHAT_MEMORY_LATEST_STALE_GRACE_SECONDS < scan_started_at:
                    if not error:
                        error = "Скан памяти чата не создал свежую историю."
                else:
                    loaded = json.loads(CHAT_MEMORY_LATEST_JSON.read_text(encoding="utf-8"))
                    if isinstance(loaded, dict):
                        payload = loaded
        except (OSError, json.JSONDecodeError, UnicodeDecodeError) as exc:
            error = str(exc)
        with self._lock:
            if generation != self._chat_memory_generation:
                self._chat_memory_scan_running = False
                return
            if payload:
                self._chat_memory = payload
                self._chat_memory_error = ""
            elif error:
                self._chat_memory = {}
                self._chat_memory_error = error
            self._chat_memory_at = self.clock()
            self._chat_memory_loading = False
            self._chat_memory_scan_running = False

    def _remember_chat_send_locked(self, message: str) -> None:
        text = message.strip()
        now = self.clock()
        self._chat_recent_sends = [
            item
            for item in self._chat_recent_sends
            if now - float(item.get("created_at") or now) <= CHAT_CONFIRM_RETENTION_SECONDS
        ]
        if any(str(item.get("text") or "") == text and not item.get("confirmed") for item in self._chat_recent_sends):
            return
        self._chat_recent_sends.append({"text": text, "created_at": now, "confirmed": False})

    def _chat_confirmed_outbox_locked(self) -> list[dict[str, object]]:
        now = self.clock()
        self._chat_recent_sends = [
            item
            for item in self._chat_recent_sends
            if now - float(item.get("created_at") or now) <= CHAT_CONFIRM_RETENTION_SECONDS
        ]
        return [
            {
                "text": str(item.get("text") or ""),
                "confirmed_at": item.get("confirmed_at"),
                "source": item.get("source") or "memory_search",
            }
            for item in self._chat_recent_sends
            if item.get("confirmed") and item.get("text")
        ]

    def _local_player_name_locked(self) -> str | None:
        records = self._chat_memory.get("records") if isinstance(self._chat_memory.get("records"), list) else []
        for record in records:
            if not isinstance(record, dict):
                continue
            text = str(record.get("text") or "")
            match = re.search(r"Majestic Role Play,\s*([^!]+)!", text)
            if match:
                name = match.group(1).strip()
                if name:
                    return name
        return None

    @staticmethod
    def _chat_confirmation_queries(message: str, player_name: str | None = None) -> list[str]:
        text = message.strip()
        if not text:
            return []
        match = re.match(r"^/([^\s/]+)(?:\s+([\s\S]+))?$", text)
        command = f"/{match.group(1).lower()}" if match else ""
        body = (match.group(2) or "").strip() if match else text
        if not body:
            return []
        candidates: list[str] = []
        if player_name:
            candidates.append(f"{player_name} {body}")
            candidates.append(f"{player_name} говорит: {body}")
        if command in {"", "/w", "/s", "/b"}:
            candidates.append(f"говорит: {body}")
        if len(body) >= 8:
            candidates.append(body)
        out: list[str] = []
        seen: set[str] = set()
        for candidate in candidates:
            normalized = re.sub(r"\s+", " ", candidate).strip()
            if normalized and normalized not in seen:
                seen.add(normalized)
                out.append(normalized)
        return out

    def _refresh_chat_confirmations_if_needed(self, *, force: bool = False) -> None:
        with self._lock:
            pending = [str(item.get("text") or "") for item in self._chat_recent_sends if item.get("text") and not item.get("confirmed")]
            if not pending:
                return
            now = self.clock()
            if self._chat_confirm_scan_running:
                return
            if not force and now - self._chat_confirm_scan_at < CHAT_CONFIRM_SCAN_INTERVAL_SECONDS:
                return
            self._chat_confirm_scan_running = True
            self._chat_confirm_scan_at = now
            player_name = self._local_player_name_locked()
            process_hint = self._chat_confirm_process
        threading.Thread(
            target=self._chat_confirm_scan_worker,
            args=(pending, player_name, process_hint),
            name="sonar-chat-confirm-scan",
            daemon=True,
        ).start()

    def _chat_confirm_scan_worker(
        self,
        pending: list[str],
        player_name: str | None,
        process_hint: tuple[str, int] | None,
    ) -> None:
        confirmed: list[tuple[str, dict[str, object]]] = []
        next_process_hint = process_hint
        try:
            for message in pending:
                for query in self._chat_confirmation_queries(message, player_name):
                    hit = self._find_chat_confirmation_hit(query, next_process_hint)
                    if not hit and next_process_hint is not None:
                        hit = self._find_chat_confirmation_hit(query, None)
                    if not hit:
                        continue
                    confirmed.append((message, hit))
                    process_name = str(hit.get("process") or "")
                    pid = hit.get("pid")
                    if process_name and isinstance(pid, int):
                        next_process_hint = (process_name, pid)
                    break
        finally:
            with self._lock:
                if next_process_hint is not None:
                    self._chat_confirm_process = next_process_hint
                now = self.clock()
                for message, hit in confirmed:
                    for item in self._chat_recent_sends:
                        if str(item.get("text") or "") != message:
                            continue
                        item["confirmed"] = True
                        item["confirmed_at"] = now
                        item["source"] = "memory_search"
                        item["addr"] = hit.get("addr")
                        item["pid"] = hit.get("pid")
                self._chat_confirm_scan_running = False

    def _find_chat_confirmation_hit(self, query: str, process_hint: tuple[str, int] | None) -> dict[str, object] | None:
        process_value = str(process_hint[1]) if process_hint is not None else WEBENGINE_PROCESS_NAME
        command = [
            sys.executable,
            "-m",
            "sonar.tools.find_chat_memory",
            "--process",
            process_value,
            "--query",
            query,
            "--min-fragment-chars",
            str(max(3, min(8, len(query)))),
            "--max-total-mb",
            "0",
            "--hits",
            "1",
            "--print-hits",
            "0",
            "--progress",
            "0",
            "--out-dir",
            str(CHAT_MEMORY_OUT_DIR),
        ]
        try:
            run_kwargs: dict[str, object] = {
                "cwd": PROJECT_DIR / "02_sonar_app",
                "stdout": subprocess.PIPE,
                "stderr": subprocess.DEVNULL,
                "timeout": CHAT_CONFIRM_SCAN_TIMEOUT_SECONDS,
                "check": False,
                "text": True,
                "encoding": "utf-8",
                "errors": "replace",
            }
            if os.name == "nt":
                run_kwargs["creationflags"] = getattr(subprocess, "CREATE_NO_WINDOW", 0)
            completed = subprocess.run(command, **run_kwargs)
        except Exception:
            return None
        output = str(completed.stdout or "")
        match = re.search(r"Saved report:\s*(.+)", output)
        if not match:
            return None
        report_path = Path(match.group(1).strip())
        try:
            report = json.loads(report_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError, UnicodeDecodeError):
            return None
        hits = report.get("hits")
        if not isinstance(hits, list) or not hits:
            return None
        hit = hits[0]
        return hit if isinstance(hit, dict) else None

    def _apply_chat_result_locked(self, result: ChatActionResult | ChatDetection | None) -> None:
        if result is None:
            return
        if isinstance(result, ChatActionResult):
            self._chat_detection = result.detection
            self._chat_detection_at = self.clock()
            self._chat_last_action = result.message
            if result.ok:
                self._error = ""
            elif result.message:
                self._error = result.message
            return
        self._chat_detection = result
        self._chat_detection_at = self.clock()

    def cleanup_orphaned_runtime_dirs(self) -> None:
        try:
            for child in self.temp_root.glob(f"{STREAM_RUNTIME_PREFIX}*"):
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
        self._chat_memory_enabled = False
        self._chat_memory_restore_enabled = False
        self._chat_detection = ChatDetection()
        self._chat_detection_at = -1_000_000.0
        self._chat_last_action = ""
        self._chat_recent_sends = []
        self._chat_confirm_process = None
        self._chat_confirm_scan_running = False
        self._audio_fallback_video_only = False
        self._started_at = None
        self._last_viewer_activity_at = None
        self._local_url = None
        self._public_url = None
        self._tunnel_provider = ""
        self._cloudflared_start_attempts = 0
        self._temp_dir = self.temp_root / f"{STREAM_RUNTIME_PREFIX}{uuid.uuid4().hex}"
        self._hls_dir = self._temp_dir / "hls"
        self._hls_dir.mkdir(parents=True, exist_ok=True)
        self._log(f"Stream link: new runtime temp_dir={self._temp_dir} hls_dir={self._hls_dir}")

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
            with self._lock:
                snapshot_mode = self._snapshot_mode_enabled
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
                if snapshot_mode:
                    self._log("Стрим: режим 10fps, запускаю HLS-видео через FFmpeg")
                else:
                    self._log("Стрим: ожидаю первые HLS-сегменты")
                self._start_ffmpeg_process_locked(ffmpeg)
            try:
                self._wait_for_hls_ready(token)
            except RuntimeError:
                if not self._audio_capture_args():
                    raise
                with self._lock:
                    if token != self._runtime_token or self._status != "starting":
                        return
                    self._log("Стрим: звук не запустился, продолжаю без аудио")
                    self._audio_fallback_video_only = True
                    self._terminate_process(self._ffmpeg_process)
                    self._ffmpeg_process = None
                    if self._hls_dir is not None:
                        shutil.rmtree(self._hls_dir, ignore_errors=True)
                        self._hls_dir.mkdir(parents=True, exist_ok=True)
                    self._start_ffmpeg_process_locked(ffmpeg)
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
        with self._lock:
            start_tunnelmole = self._cloudflared_start_attempts >= CLOUDFLARED_MAX_START_ATTEMPTS
            if start_tunnelmole:
                self._log("cloudflared: max start attempts reached, switching to tunnelmole")
        if start_tunnelmole:
            self._start_tunnelmole_worker(token)
            return

        self._log(f"Stream link: resolving cloudflared token={token}")
        cloudflared = self._resolve_cloudflared_binary(wait_timeout=None)
        if cloudflared is None:
            fallback_token: str | None = None
            with self._lock:
                if token == self._runtime_token and self._active:
                    self._cloudflared_start_attempts = CLOUDFLARED_MAX_START_ATTEMPTS
                    fallback_token = token
            if fallback_token is not None:
                self._start_tunnelmole_worker(fallback_token)
            self._log("cloudflared не удалось подготовить автоматически, ссылка будет локальной")
            return
        self._log(f"Stream link: cloudflared binary={cloudflared}")
        fallback_token: str | None = None
        with self._lock:
            if token != self._runtime_token or not self._active:
                self._log(f"Stream link: cloudflared start skipped token={token} active={self._active}")
                return
            if self._cloudflared_process is not None and self._cloudflared_process.poll() is None:
                provider = self._tunnel_provider or "cloudflared"
                self._log(f"Stream link: {provider} already running pid={getattr(self._cloudflared_process, 'pid', None)}")
                return
            try:
                self._cloudflared_start_attempts += 1
                self._start_cloudflared_process_locked(cloudflared)
            except Exception as exc:
                self._cloudflared_process = None
                self._tunnel_provider = ""
                if self._cloudflared_start_attempts >= CLOUDFLARED_MAX_START_ATTEMPTS:
                    self._log("cloudflared: switching to tunnelmole after failed start")
                    fallback_token = token
                self._log(f"cloudflared не запустился: {exc}")

        if fallback_token is not None:
            self._start_tunnelmole_worker(fallback_token)

    def _start_tunnelmole_worker(self, token: str) -> None:
        command_prefix = self._resolve_tunnelmole_command()
        if command_prefix is None:
            self._log("tunnelmole: tmole/tunnelmole/npx not found, keeping local stream URL")
            return
        with self._lock:
            if token != self._runtime_token or not self._active:
                self._log(f"Stream link: tunnelmole start skipped token={token} active={self._active}")
                return
            if self._cloudflared_process is not None and self._cloudflared_process.poll() is None:
                provider = self._tunnel_provider or "tunnel"
                self._log(f"Stream link: {provider} already running pid={getattr(self._cloudflared_process, 'pid', None)}")
                return
            try:
                self._start_tunnelmole_process_locked(command_prefix)
            except Exception as exc:
                self._log(f"tunnelmole: failed to start: {exc}")

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
        self._log(f"Stream link: local origin ready url={self._local_url}")
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
        command = self._build_ffmpeg_command(ffmpeg, include_audio=not self._audio_fallback_video_only)
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
        command = self._build_cloudflared_command(cloudflared)
        self._log(f"cloudflared: starting command={self._format_command_for_log(command)}")
        process = self._popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        self._cloudflared_process = process
        self._tunnel_provider = "cloudflared"
        self._log(f"cloudflared: process started pid={getattr(process, 'pid', None)} origin={self._local_url}")
        threading.Thread(
            target=self._watch_cloudflared_output,
            args=(process, log_file),
            name="sonar-cloudflared",
            daemon=True,
        ).start()

    def _build_cloudflared_command(self, cloudflared: Path) -> list[str]:
        protocol = (
            os.environ.get("SONAR_STREAM_CLOUDFLARED_PROTOCOL", CLOUDFLARED_DEFAULT_PROTOCOL).strip()
            or CLOUDFLARED_DEFAULT_PROTOCOL
        )
        edge_ip_version = (
            os.environ.get("SONAR_STREAM_CLOUDFLARED_EDGE_IP_VERSION", CLOUDFLARED_DEFAULT_EDGE_IP_VERSION).strip()
            or CLOUDFLARED_DEFAULT_EDGE_IP_VERSION
        )
        return [
            str(cloudflared),
            "tunnel",
            "--edge-ip-version",
            edge_ip_version,
            "--protocol",
            protocol,
            "--url",
            self._local_url or "",
        ]

    def _resolve_tunnelmole_command(self) -> list[str] | None:
        env_path = os.environ.get("SONAR_STREAM_TUNNELMOLE_PATH", "").strip()
        if env_path:
            explicit = Path(env_path)
            if explicit.exists():
                return [str(explicit)]
            found = shutil.which(env_path)
            if found:
                return [found]
        for name in ("tmole", "tunnelmole"):
            found = shutil.which(name)
            if found:
                return [found]
        if os.environ.get("SONAR_STREAM_TUNNELMOLE_DISABLE_NPX") == "1":
            return None
        npx = shutil.which("npx.cmd") or shutil.which("npx")
        if npx:
            return [npx, "-y", "tunnelmole"]
        return None

    def _start_tunnelmole_process_locked(self, command_prefix: list[str]) -> None:
        if self._local_url is None:
            return
        log_file = self._open_log_file_locked("tunnelmole.log")
        command = self._build_tunnelmole_command(command_prefix)
        self._log(f"tunnelmole: starting command={self._format_command_for_log(command)}")
        process = self._popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        self._cloudflared_process = process
        self._tunnel_provider = "tunnelmole"
        self._log(f"tunnelmole: process started pid={getattr(process, 'pid', None)} origin={self._local_url}")
        threading.Thread(
            target=self._watch_tunnelmole_output,
            args=(process, log_file),
            name="sonar-tunnelmole",
            daemon=True,
        ).start()

    def _build_tunnelmole_command(self, command_prefix: list[str]) -> list[str]:
        parsed = urlparse(self._local_url or "")
        if parsed.port is None:
            raise RuntimeError(f"Cannot determine local stream port from {self._local_url!r}")
        return [*command_prefix, str(parsed.port)]

    @staticmethod
    def _format_command_for_log(command: list[str]) -> str:
        return " ".join(f'"{part}"' if " " in part else part for part in command)

    def _watch_cloudflared_output(self, process: subprocess.Popen, log_file) -> None:
        stream = process.stdout
        if stream is None:
            return
        pending_public_url = ""
        try:
            for line in stream:
                try:
                    log_file.write(line.encode("utf-8", errors="replace") if "b" in getattr(log_file, "mode", "") else line)
                    log_file.flush()
                except Exception:
                    pass
                match = CLOUDFLARED_URL_RE.search(line)
                if match:
                    pending_public_url = match.group(0).rstrip("/")
                    self._log(f"cloudflared: candidate quick tunnel URL announced url={pending_public_url}")
                    continue
                if CLOUDFLARED_REGISTERED_RE.search(line) and pending_public_url:
                    self._log(f"cloudflared: registered connection url={pending_public_url}")
                    self._schedule_public_tunnel_publish(process, pending_public_url)
                    continue
                if ARGOTUNNEL_DNS_ERROR_RE.search(line):
                    self._log(f"cloudflared: Argo DNS resolver failed line={line.strip()}")
                    continue
        except Exception as exc:
            self._log(f"cloudflared output error: {exc}")
        finally:
            with self._lock:
                if self._cloudflared_process is process and process.poll() is not None:
                    self._log(f"cloudflared: process exited returncode={process.poll()}")
                    self._clear_public_tunnel_url_locked()

    def _watch_tunnelmole_output(self, process: subprocess.Popen, log_file) -> None:
        stream = process.stdout
        if stream is None:
            return
        published_urls: set[str] = set()
        try:
            for line in stream:
                try:
                    log_file.write(line.encode("utf-8", errors="replace") if "b" in getattr(log_file, "mode", "") else line)
                    log_file.flush()
                except Exception:
                    pass
                for match in TUNNELMOLE_URL_RE.finditer(line):
                    public_url = match.group(0).rstrip("/")
                    if public_url in published_urls:
                        continue
                    published_urls.add(public_url)
                    self._log(f"tunnelmole: public URL announced url={public_url}")
                    self._schedule_public_tunnel_publish(process, public_url)
        except Exception as exc:
            self._log(f"tunnelmole output error: {exc}")
        finally:
            with self._lock:
                if self._cloudflared_process is process and process.poll() is not None:
                    self._log(f"tunnelmole: process exited returncode={process.poll()}")
                    self._clear_public_tunnel_url_locked()

    def _clear_public_tunnel_url_locked(self) -> None:
        if self._is_public_tunnel_url(self._public_url):
            self._log(f"Stream link: clearing public URL url={self._public_url} fallback={self._local_url}")
            self._public_url = self._local_url

    @staticmethod
    def _is_public_tunnel_url(url: str | None) -> bool:
        if not url:
            return False
        lowered = url.lower()
        return "trycloudflare.com" in lowered or ".tunnelmole." in lowered

    def _schedule_public_tunnel_publish(self, process: subprocess.Popen, public_url: str) -> None:
        self._log(f"Stream link: scheduling public URL readiness check url={public_url}")
        threading.Thread(
            target=self._publish_public_tunnel_when_ready,
            args=(process, public_url),
            name="sonar-cloudflared-url-check",
            daemon=True,
        ).start()

    def _publish_public_tunnel_when_ready(self, process: subprocess.Popen, public_url: str) -> None:
        deadline = time.monotonic() + CLOUDFLARED_PUBLIC_URL_READY_TIMEOUT_SECONDS
        attempt = 0
        while time.monotonic() < deadline:
            attempt += 1
            with self._lock:
                if self._cloudflared_process is not process or not self._active:
                    self._log(f"Stream link: public URL check cancelled url={public_url} attempt={attempt}")
                    return
            reachable, detail = self._public_tunnel_url_check(public_url)
            if reachable:
                with self._lock:
                    if self._cloudflared_process is process and self._active:
                        self._public_url = public_url
                        provider = self._tunnel_provider or "tunnel"
                        if provider == "cloudflared":
                            self._cloudflared_start_attempts = 0
                        self._log(f"Stream link: public URL ready provider={provider} url={public_url} attempt={attempt} detail={detail}")
                return
            self._log(f"Stream link: public URL not ready url={public_url} attempt={attempt} detail={detail}")
            time.sleep(CLOUDFLARED_PUBLIC_URL_READY_POLL_SECONDS)
        self._log(f"Stream link: public URL readiness timeout url={public_url}")
        self._restart_cloudflared_after_bad_public_url(process, public_url, "readiness timeout")

    def _restart_cloudflared_after_bad_public_url(self, process: subprocess.Popen, public_url: str, reason: str) -> None:
        token: str | None = None
        provider = "cloudflared"
        fallback_to_tunnelmole = False
        with self._lock:
            if self._cloudflared_process is not process or not self._active:
                self._log(f"cloudflared: restart skipped for stale URL url={public_url} reason={reason}")
                return
            token = self._runtime_token
            provider = self._tunnel_provider or "cloudflared"
            if provider == "cloudflared":
                fallback_to_tunnelmole = self._cloudflared_start_attempts >= CLOUDFLARED_MAX_START_ATTEMPTS
            self._log(f"{provider}: restarting after unusable public URL url={public_url} reason={reason}")
            self._cloudflared_process = None
            self._tunnel_provider = ""
            self._clear_public_tunnel_url_locked()
        self._terminate_process(process)
        if token is None:
            return
        time.sleep(CLOUDFLARED_PUBLIC_URL_RESTART_BACKOFF_SECONDS)
        if fallback_to_tunnelmole:
            self._log("cloudflared: switching to tunnelmole after public URL failures")
            self._start_tunnelmole_worker(token)
        elif provider == "tunnelmole":
            self._start_tunnelmole_worker(token)
        else:
            self._start_tunnel_worker(token)

    @staticmethod
    def _public_tunnel_url_check(public_url: str) -> tuple[bool, str]:
        target = f"{public_url.rstrip('/')}/live/"
        curl = shutil.which("curl.exe") or shutil.which("curl")
        if curl:
            return StreamingService._public_tunnel_url_check_with_curl(curl, target)
        try:
            request = urllib.request.Request(
                target,
                headers={"User-Agent": "Sonar-stream-check/1.0"},
            )
            with urllib.request.urlopen(request, timeout=CLOUDFLARED_PUBLIC_URL_CHECK_TIMEOUT_SECONDS) as response:
                status = int(getattr(response, "status", 200))
                return 200 <= status < 500, f"status={status}"
        except urllib.error.HTTPError as exc:
            return False, f"http_error={exc.code}"
        except (OSError, urllib.error.URLError, ValueError) as exc:
            return False, f"error={type(exc).__name__}: {exc}"

    @staticmethod
    def _public_tunnel_url_check_with_curl(curl: str, target: str) -> tuple[bool, str]:
        command = [
            curl,
            "--silent",
            "--show-error",
            "--location",
            "--max-time",
            str(CLOUDFLARED_PUBLIC_URL_CHECK_TIMEOUT_SECONDS),
            "--output",
            os.devnull,
            "--write-out",
            "%{http_code}",
            target,
        ]
        try:
            creationflags = getattr(subprocess, "CREATE_NO_WINDOW", 0) if os.name == "nt" else 0
            result = subprocess.run(
                command,
                capture_output=True,
                text=True,
                timeout=CLOUDFLARED_PUBLIC_URL_CHECK_TIMEOUT_SECONDS + 1.0,
                creationflags=creationflags,
            )
        except (OSError, subprocess.TimeoutExpired) as exc:
            return False, f"curl_error={type(exc).__name__}: {exc}"
        status_text = (result.stdout or "").strip()[-3:]
        try:
            status = int(status_text)
        except ValueError:
            status = 0
        if 200 <= status < 500:
            return True, f"status={status} checker=curl"
        detail = (result.stderr or "").strip().replace("\r", " ").replace("\n", " ")
        if detail:
            detail = detail[:240]
            return False, f"status={status} curl_exit={result.returncode} detail={detail}"
        return False, f"status={status} curl_exit={result.returncode}"

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
            game_missing = False
            restart_needed = False
            restart_tunnel_token: str | None = None
            restart_tunnelmole_token: str | None = None
            with self._lock:
                if self._active and self._should_auto_stop_locked():
                    should_stop = True
                if (
                    self._active
                    and self._ffmpeg_process
                    and self._ffmpeg_process.poll() is not None
                ):
                    self._log("FFmpeg завершился, перезапускаю стрим")
                    restart_needed = True
                if (
                    self._active
                    and self._cloudflared_process
                    and self._cloudflared_process.poll() is not None
                ):
                    provider = self._tunnel_provider or "cloudflared"
                    self._log(f"{provider} ended, restarting tunnel")
                    self._cloudflared_process = None
                    self._tunnel_provider = ""
                    self._clear_public_tunnel_url_locked()
                    if provider == "cloudflared" and self._cloudflared_start_attempts >= CLOUDFLARED_MAX_START_ATTEMPTS:
                        restart_tunnelmole_token = self._runtime_token
                    elif provider == "tunnelmole":
                        restart_tunnelmole_token = self._runtime_token
                    else:
                        restart_tunnel_token = self._runtime_token
                active = self._active
                game_window_available_callback = self.game_window_available_callback
            if active and game_window_available_callback is not None and not game_window_available_callback():
                game_missing = True
            if game_missing:
                self.stop_stream("окно игры закрыто")
                continue
            if restart_needed:
                self._restart_ffmpeg()
            if restart_tunnel_token is not None:
                self._start_tunnel_worker(restart_tunnel_token)
            if restart_tunnelmole_token is not None:
                self._start_tunnelmole_worker(restart_tunnelmole_token)
            if should_stop:
                self.stop_stream("нет зрителей 5 минут")

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
        self._tunnel_provider = ""
        self._cloudflared_start_attempts = 0
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
        self._chat_zoom_enabled = False
        self._chat_mode_enabled = False
        self._chat_detection = ChatDetection()
        self._chat_detection_at = -1_000_000.0
        self._chat_last_action = ""
        self._chat_memory_loading = False
        self._started_at = None
        self._last_viewer_activity_at = None
        self._runtime_token = None

    def _memory_chat_detection_locked(self, fallback: ChatDetection) -> ChatDetection:
        payload = self._chat_memory
        if not payload:
            return fallback
        has_active_flag = isinstance(payload.get("chat_input_active"), bool)
        active = bool(payload.get("chat_input_active")) if has_active_flag else fallback.active
        tabs_payload = payload.get("tabs")
        tabs: list[ChatTab] = []
        selected_tab_id: str | None = None
        if isinstance(tabs_payload, list):
            for index, item in enumerate(tabs_payload):
                if not isinstance(item, dict):
                    continue
                tab_id = str(item.get("id") or index)
                name = str(item.get("name") or tab_id)
                selected = bool(item.get("active"))
                if selected:
                    selected_tab_id = tab_id
                tabs.append(ChatTab(tab_id, name, selected, Rect(0, 0, 0, 0)))
        active_tab = payload.get("active_tab")
        if selected_tab_id is None and isinstance(active_tab, dict) and active_tab.get("id"):
            selected_tab_id = str(active_tab.get("id"))
            tabs = [
                ChatTab(tab.id, tab.name, tab.id == selected_tab_id, tab.rect)
                for tab in tabs
            ]
        if not tabs:
            tabs = list(fallback.tabs)
            selected_tab_id = fallback.selected_tab_id
        input_rect = fallback.input_rect
        error = self._chat_memory_error or fallback.error
        return ChatDetection(active=active, tabs=tuple(tabs), selected_tab_id=selected_tab_id, input_rect=input_rect, error=error)

    def _license_role_locked(self) -> str:
        if self.license_role_callback is None:
            return "user"
        try:
            role = str(self.license_role_callback() or "user").strip().lower()
        except Exception:
            return "user"
        return role or "user"

    def _chat_history_public_payload_locked(self) -> dict[str, object] | None:
        if not (self._chat_memory_enabled or self._chat_mode_enabled) or not self._chat_memory:
            return None
        payload = self._chat_memory
        records = payload.get("records") if isinstance(payload.get("records"), list) else []
        tabs = payload.get("tabs") if isinstance(payload.get("tabs"), list) else []
        return {
            "updated_at": payload.get("updated_at"),
            "chat_input_active": payload.get("chat_input_active"),
            "active_tab": payload.get("active_tab") if isinstance(payload.get("active_tab"), dict) else None,
            "tabs": tabs,
            "records": records[-160:],
        }

    def _snapshot_locked(self) -> StreamSnapshot:
        seconds_until_auto_stop: int | None = None
        if self._active:
            reference = self._last_viewer_activity_at or self._started_at
            if reference is not None:
                seconds_until_auto_stop = max(0, int(self.viewer_timeout_seconds - (self.clock() - reference)))
        chat_detection = self._memory_chat_detection_locked(self._chat_detection)
        chat_tabs = chat_detection.tabs if chat_detection.active else ()
        return StreamSnapshot(
            active=self._active,
            status="preparing" if self._status == "offline" and self._binary_prepare_thread and self._binary_prepare_thread.is_alive() else self._status,
            quality=self._quality,
            area="chat" if self._chat_zoom_enabled else "full",
            chat_zoom_enabled=self._chat_zoom_enabled,
            snapshot_mode_enabled=self._snapshot_mode_enabled,
            snapshot_interval_ms=SNAPSHOT_MODE_INTERVAL_MS,
            chat_memory_enabled=self._chat_memory_enabled or self._chat_mode_enabled,
            chat_mode_enabled=self._chat_mode_enabled,
            local_url=self._local_url,
            public_url=self._public_url,
            stream_url=self._stream_url_locked(),
            hls_url="/hls/live.m3u8" if self._active else None,
            started_at=self._started_at,
            last_viewer_activity_at=self._last_viewer_activity_at,
            seconds_until_auto_stop=seconds_until_auto_stop,
            error=self._error or self._binary_prepare_error,
            chat_active=chat_detection.active,
            chat_tabs=chat_tabs,
            chat_selected_tab_id=chat_detection.selected_tab_id if chat_detection.active else None,
            chat_status_error=chat_detection.error,
            chat_last_action=self._chat_last_action,
            chat_memory_loading=self._chat_memory_loading,
            chat_history=self._chat_history_public_payload_locked(),
            license_role=self._license_role_locked(),
        )

    def _stream_url_locked(self) -> str | None:
        base = self._public_url or self._local_url
        if not base:
            return None
        return f"{base.rstrip('/')}/live/"

    def _build_ffmpeg_command(self, executable: Path, *, include_audio: bool = True) -> list[str]:
        if self._hls_dir is None:
            raise RuntimeError("HLS папка не подготовлена")
        quality = STREAM_QUALITIES[self._quality]
        capture_args = self._capture_args()
        audio_args = self._audio_capture_args() if include_audio else []
        fps = LOW_FPS_STREAM_FPS if self._snapshot_mode_enabled else DEFAULT_STREAM_FPS
        encoder = os.environ.get("SONAR_STREAM_ENCODER", "libx264").strip() or "libx264"
        hls_playlist = self._hls_dir / "live.m3u8"
        hls_segment = self._hls_dir / "seg_%05d.ts"
        bitrate = quality.bitrate_for_fps(fps)
        command = [
            str(executable),
            "-hide_banner",
            "-nostdin",
            "-loglevel",
            "warning",
            "-f",
            "gdigrab",
            "-framerate",
            str(fps),
            *capture_args,
            "-i",
            "desktop",
            *audio_args,
            "-map",
            "0:v:0",
        ]
        if audio_args:
            command.extend([
                "-map",
                "1:a:0",
            ])
        else:
            command.append("-an")
        command.extend([
            "-vf",
            f"scale=-2:{quality.height}:flags=lanczos",
            "-c:v",
            encoder,
            "-preset",
            "veryfast",
            "-tune",
            "zerolatency",
            "-b:v",
            bitrate,
            "-maxrate",
            bitrate,
            "-bufsize",
            self._double_bitrate(bitrate),
            "-pix_fmt",
            "yuv420p",
            "-g",
            str(fps),
        ])
        if audio_args:
            command.extend([
                "-c:a",
                "aac",
                "-b:a",
                os.environ.get("SONAR_STREAM_AUDIO_BITRATE", "128k").strip() or "128k",
                "-ac",
                "2",
                "-ar",
                "48000",
            ])
        command.extend([
            "-f",
            "hls",
            "-hls_time",
            "1",
            "-hls_list_size",
            "5",
            "-hls_delete_threshold",
            "5",
            "-hls_flags",
            "delete_segments+independent_segments+omit_endlist",
            "-hls_segment_filename",
            str(hls_segment),
            str(hls_playlist),
        ])
        return command

    @staticmethod
    def _audio_capture_args() -> list[str]:
        enabled = os.environ.get("SONAR_STREAM_AUDIO_ENABLED", "1").strip().lower()
        if enabled in {"0", "false", "no", "off"}:
            return []
        driver = os.environ.get("SONAR_STREAM_AUDIO_DRIVER", "wasapi").strip().lower() or "wasapi"
        source = (
            os.environ.get("SONAR_STREAM_AUDIO_DEVICE")
            or os.environ.get("SONAR_STREAM_AUDIO_INPUT")
            or "default"
        ).strip() or "default"
        if driver == "dshow":
            return ["-thread_queue_size", "1024", "-f", "dshow", "-i", f"audio={source}"]
        return ["-thread_queue_size", "1024", "-f", "wasapi", "-loopback", "1", "-i", source]

    def _capture_args(self) -> list[str]:
        x, y, width, height = self._capture_rect()
        if self._chat_zoom_enabled:
            return ["-offset_x", str(x), "-offset_y", str(y), "-video_size", f"{width}x{height}"]
        return ["-video_size", f"{width}x{height}"]

    def _capture_rect(self) -> tuple[int, int, int, int]:
        screen_width, screen_height = self._screen_size()
        if self._chat_zoom_enabled:
            width = max(320, (screen_width * 9) // 32)
            height = max(240, (screen_height * 2) // 3)
            return 0, 0, width, height
        return 0, 0, screen_width, screen_height

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
        debug_log(message)
        if self.log_callback is not None:
            self.log_callback(message)


def _json_default(value: object) -> object:
    if hasattr(value, "__dataclass_fields__"):
        return asdict(value)  # type: ignore[arg-type]
    return str(value)


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
        if parsed.path == "/api/stream/chat":
            self._send_json(self.stream_service.chat_snapshot())
            return
        if parsed.path.startswith("/assets/chat-icons/"):
            self._serve_chat_icon(parsed.path.removeprefix("/assets/chat-icons/"))
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
        if parsed.path == "/api/stream/snapshot-mode":
            payload = self._read_json_body()
            self.stream_service.set_snapshot_mode_enabled(bool(payload.get("enabled")))
            self._send_json(self.stream_service.snapshot())
            return
        if parsed.path == "/api/stream/chat-memory":
            payload = self._read_json_body()
            self._send_json(self.stream_service.set_chat_memory_enabled(bool(payload.get("enabled"))))
            return
        if parsed.path == "/api/stream/chat-mode":
            payload = self._read_json_body()
            if "enabled" in payload:
                self._send_json(self.stream_service.set_chat_mode_enabled(bool(payload.get("enabled"))))
            else:
                self._send_json(self.stream_service.enable_chat_mode())
            return
        if parsed.path == "/api/stream/chat-select":
            payload = self._read_json_body()
            tab_id = payload.get("tab_id")
            self._send_json(self.stream_service.select_chat_tab(str(tab_id) if tab_id is not None else None))
            return
        if parsed.path == "/api/stream/chat-send":
            payload = self._read_json_body()
            tab_id = payload.get("tab_id")
            message = str(payload.get("message") or "")
            self._send_json(self.stream_service.send_chat_message(str(tab_id) if tab_id is not None else None, message))
            return
        if parsed.path == "/api/stream/chat-clear":
            self._send_json(self.stream_service.clear_chat_input())
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

    def _serve_chat_icon(self, relative_path: str) -> None:
        name = Path(relative_path).name
        if not name or name != relative_path or not name.lower().endswith(".png"):
            self.send_error(HTTPStatus.NOT_FOUND)
            return
        candidate = CHAT_ICON_DIR / name
        if not candidate.exists() or not candidate.is_file():
            self.send_error(HTTPStatus.NOT_FOUND)
            return
        self._send_bytes(candidate.read_bytes(), "image/png")

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

    def _send_json(self, snapshot: StreamSnapshot | dict[str, object]) -> None:
        data = asdict(snapshot) if isinstance(snapshot, StreamSnapshot) else snapshot
        payload = json.dumps(data, ensure_ascii=False, default=_json_default).encode("utf-8")
        self._send_bytes(payload, "application/json; charset=utf-8")

    def _send_bytes(self, payload: bytes, content_type: str) -> None:
        self.send_response(HTTPStatus.OK)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(payload)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(payload)
