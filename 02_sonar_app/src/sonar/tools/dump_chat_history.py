from __future__ import annotations

import argparse
import bisect
import hashlib
import json
import re
import time
import urllib.parse
from dataclasses import asdict, dataclass, field, replace
from datetime import datetime
from functools import lru_cache
from pathlib import Path
from typing import Any, Callable

import psutil

from sonar.fishing.memory_reeling import PTR_MAX, PTR_MIN
from sonar.paths import PROJECT_DIR
from sonar.tools.find_chat_memory import _collect_search_regions, _open_tracker, iter_process_targets


DEFAULT_OUT_DIR = PROJECT_DIR / "logs" / "chat_memory"
PROCESS_CACHE_NAME = "chat_process_latest.json"
AUTO_PROCESS_TOKENS = {"auto", "auto-chat", "chat", "cef-chat"}
CHAT_MARKERS = (
    '"timestamp":',
    '"type":"',
    '"text":"',
    "chatInput",
    "\u0433\u043e\u0432\u043e\u0440\u0438\u0442:",
    "[default]",
    '[gov]',
    '[me]',
    '[admin]',
    "[fam]",
    "[frac]",
    "[ el News]",
    "[Weazel News]",
    "Weazel News",
    "\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:",
    "\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c \u043d\u0430 Majestic Role Play",
    "\u041f\u043e\u0431\u0435\u0434\u0438\u0442\u0435\u043b\u044f\u043c\u0438",
    "\u0412\u0441\u0435\u0433\u043e \u0443\u0447\u0430\u0441\u0442\u043d\u0438\u043a\u043e\u0432",
    "\u043b\u044e\u0431\u0443\u0435\u0442\u0441\u044f",
)
CHAT_TYPES = ("default", "news", "system", "me", "admin", "family", "fraction", "gov", "report")
CHAT_PREFIX_MARKERS = (
    "[default]",
    "[gov]",
    "[global]",
    "[me]",
    "[admin]",
    "[fam]",
    "[frac]",
    "[report]",
    "[ el News]",
    "[Weazel News]",
)
CHAT_DISCOVERY_MARKERS = (
    ("\u0433\u043e\u0432\u043e\u0440\u0438\u0442:", 24),
    ("\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:", 24),
    ("[Weazel News]", 22),
    ("Weazel News", 18),
    ("\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c \u043d\u0430 Majestic Role Play", 18),
    ("\u041f\u043e\u0431\u0435\u0434\u0438\u0442\u0435\u043b\u044f\u043c\u0438", 18),
    ("\u0412\u0441\u0435\u0433\u043e \u0443\u0447\u0430\u0441\u0442\u043d\u0438\u043a\u043e\u0432", 18),
    ("\u043b\u044e\u0431\u0443\u0435\u0442\u0441\u044f", 16),
    ("[default]", 18),
    ("[fam]", 18),
    ("[frac]", 18),
    ("[gov]", 16),
    ("[global]", 14),
    ("chatInput", 8),
    ("chatMessage", 8),
    ("chatIsActive", 6),
    ("chatIsShow", 6),
    ("activeFilter", 5),
    ('"timestamp":', 4),
    ('"text":"', 4),
    ('"type":"', 4),
)
CHAT_STATE_MARKERS = (
    "chatIsActive",
    "chatIsShow",
    "inputStatus",
    "activeFilter",
    "activeTab",
    "selectedTab",
    "currentTab",
    "chat/changeTab",
    "chat.setActiveFilter",
    "chat/setInputStatus",
    "chatInput",
    "input#chatInput",
    "label.chat-input",
    "label.chat-input.withCommand",
    "div.chat.disabled",
    "div.chat-container > div.chat",
    "div.main-cover.full-width.full-height > div.chat-container > div.chat",
    "ui.click",
    "copy-input",
)
CHAT_CONTEXT_MARKERS = tuple(f'"type":"{item}' for item in CHAT_TYPES) + (
    "chatInput",
    "\u0433\u043e\u0432\u043e\u0440\u0438\u0442:",
    "[default]",
    "[gov]",
    "[me]",
    "[admin]",
    "[fam]",
    "[frac]",
    "[ el News]",
    "[Weazel News]",
    "Weazel News",
    "\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:",
    "\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c \u043d\u0430 Majestic Role Play",
    "\u041f\u043e\u0431\u0435\u0434\u0438\u0442\u0435\u043b\u044f\u043c\u0438",
    "\u0412\u0441\u0435\u0433\u043e \u0443\u0447\u0430\u0441\u0442\u043d\u0438\u043a\u043e\u0432",
    "\u043b\u044e\u0431\u0443\u0435\u0442\u0441\u044f",
)
TEXT_FIELD_RE = re.compile(r'(?:text|ext)"\s*:\s*"')
TYPE_RE = re.compile(r'"type"\s*:\s*"(' + "|".join(CHAT_TYPES) + r")", re.IGNORECASE)
TIMESTAMP_RE = re.compile(r'"timestamp"\s*:\s*(\d{10,16})')
PHONE_RE = re.compile(r'"phoneNumber"\s*:\s*"?(\d{3,16})"?')
VISIBLE_PHONE_RE = re.compile(
    r"(?:\u0422\u0435\u043b\.?\s*\u043d\u043e\u043c\u0435\u0440|\u0422\u0435\u043b\u0435\u0444\u043e\u043d|phone)\s*:\s*(\d{3,16})",
    re.IGNORECASE,
)
COLOR_TAG_RE = re.compile(r"@\{(?P<color>[0-9A-Fa-f]{6})\}")
PLAYER_NAME_RE = re.compile(r"(?P<name>[A-Z][A-Za-z_'-]{1,24}\s+[A-Z][A-Za-z_'-]{1,24}(?:\s+[A-Z][A-Za-z_'-]{1,24})?)")
STATIC_SPEAKER_RE = re.compile(r"^#?(?P<static_id>\d{1,10})$")
ID_RE = re.compile(r'"id"\s*:\s*"?([0-9A-Za-z_-]{1,32})"?')
JSON_FIELD_RE = re.compile(
    r'"(?P<key>[A-Za-z_][A-Za-z0-9_-]{0,48})"\s*:\s*'
    r'(?P<value>"(?:\\.|[^"\\])*"|true|false|null|-?\d+(?:\.\d+)?)'
)
MESSAGE_ID_KEYS = ("messageId", "messageID", "message_id", "msgId", "msgID")
PLAYER_ID_KEYS = (
    "playerId",
    "playerID",
    "player_id",
    "senderId",
    "senderID",
    "authorId",
    "ownerId",
    "userId",
    "targetId",
)
STATIC_ID_KEYS = ("staticId", "staticID", "static_id", "static", "accountId", "uid")
PLAYER_NAME_KEYS = ("playerName", "player_name", "userName", "username", "senderName", "authorName", "name")
EDITOR_NAME_KEYS = ("editorName", "editor_name", "displayName", "display_name")
PLAYER_ACTION_KEYWORDS = (
    "\u043b\u044e\u0431\u0443\u0435\u0442\u0441\u044f",
    "\u043f\u0440\u0438\u0441\u0442\u0435\u0433\u043d\u0443\u043b",
    "\u043e\u0442\u0441\u0442\u0435\u0433\u043d\u0443\u043b",
    "\u0434\u043e\u0441\u0442\u0430\u043b",
    "\u0443\u0431\u0440\u0430\u043b",
    "\u043a\u0443\u043f\u0438\u043b",
    "\u0437\u0430\u0432\u0435\u0440\u0448\u0438\u043b",
    "\u0432\u044b\u043f\u043e\u043b\u043d\u0438\u043b",
)
RECORD_BOUNDARY_RE = re.compile(r'\},\{"type"|\{"type"')
TEXT_END_MARKERS = (
    '","phoneNumber"',
    '","id"',
    '","isLocation"',
    '","messageId"',
    '","duration"',
    '","createAt"',
    '","seen"',
    '","status"',
    '","timestamp"',
    '"phoneNumber"',
    '"id"',
    '"isLocation"',
    '"messageId"',
    '"duration"',
    '"createAt"',
    '"seen"',
    '"status"',
    '"timestamp"',
)
CODE_FRAGMENT_MARKERS = (
    "=>",
    "function ",
    "function(",
    "const ",
    "let ",
    "var ",
    "return ",
    "this.",
    "mp.",
    ".emit",
    "emit(",
    "JSON.",
    "prototype",
    "constructor()",
    "void 0",
    "!==",
    "===",
)
BAD_RECORD_MARKERS = (
    "cache_default",
    "majestic_settings",
    "bindId",
    "triggerType",
    "chatSet Custom",
    "telegramActivity",
    "captureHud",
    "{text}",
    "name}",
    "{name}",
    'p["',
    'v("',
    '["name"]',
    '+(" говорит',
    '+" говорит',
)
NOISE_TOKEN_RE = re.compile(r"^[%+*/_=|\\:;.,!?@#\"'()[\]{}-]*[A-Za-z0-9]{0,4}[%+*/_=|\\:;.,!?@#\"'()[\]{}-]*$")


@dataclass(frozen=True, slots=True)
class ChatRecord:
    type: str
    text: str
    timestamp: int | None
    time: str | None
    phoneNumber: str | None
    id: str | None
    source: str
    encoding: str
    pos: int
    process: str | None = None
    pid: int | None = None
    messageId: str | None = None
    stableId: str | None = None
    playerId: str | None = None
    staticId: str | None = None
    playerName: str | None = None
    color: str | None = None
    formatting: dict[str, Any] = field(default_factory=dict)
    owner: dict[str, Any] = field(default_factory=dict)
    raw_fields: dict[str, Any] = field(default_factory=dict)
    order: int | None = None
    orderSource: str | None = None


@dataclass(frozen=True, slots=True)
class TextFragment:
    text: str
    source: str
    encoding: str
    addr: int
    process: str | None = None
    pid: int | None = None


@dataclass(frozen=True, slots=True)
class RenderedTextNode:
    raw: str
    text: str
    start: int
    end: int


def _marker_bytes() -> list[bytes]:
    out: list[bytes] = []
    for marker in CHAT_MARKERS:
        out.append(marker.encode("utf-8"))
        out.append(marker.encode("utf-16-le"))
    return out


def _encoded_markers(markers: tuple[str, ...]) -> list[bytes]:
    out: list[bytes] = []
    for marker in markers:
        out.append(marker.encode("utf-8"))
        out.append(marker.encode("utf-16-le"))
    return out


def _has_chat_context(data: bytes) -> bool:
    return any(marker in data for marker in _encoded_markers(CHAT_CONTEXT_MARKERS))


@lru_cache(maxsize=16)
def _compiled_marker_regex(markers: tuple[bytes, ...]) -> re.Pattern[bytes]:
    ordered = sorted({marker for marker in markers if marker}, key=len, reverse=True)
    return re.compile(b"|".join(re.escape(marker) for marker in ordered))


def _scan_marker_offsets(
    read_chunk: Callable[[int, int], bytes | None],
    start: int,
    end: int,
    markers: list[bytes],
    chunk_size: int,
    overlap: int,
    limit: int,
) -> list[int]:
    hits: list[int] = []
    seen: set[int] = set()
    carry = b""
    addr = start
    while addr < end and len(hits) < limit:
        size = min(chunk_size, end - addr)
        data = read_chunk(addr, size)
        if not data:
            carry = b""
            addr += size
            continue
        scan_data = carry + data
        scan_base = addr - len(carry)
        carry_len = len(carry)
        marker_regex = _compiled_marker_regex(tuple(markers))
        for match in marker_regex.finditer(scan_data):
            if len(hits) >= limit:
                break
            hit = match.start()
            if hit + (match.end() - match.start()) <= carry_len:
                continue
            absolute = scan_base + hit
            if absolute in seen:
                continue
            seen.add(absolute)
            hits.append(absolute)
        carry = scan_data[-overlap:] if overlap else b""
        addr += size
    hits.sort()
    return hits


def _merge_windows(windows: list[tuple[int, int]]) -> list[tuple[int, int]]:
    if not windows:
        return []
    ordered = sorted(windows)
    merged = [ordered[0]]
    for start, end in ordered[1:]:
        last_start, last_end = merged[-1]
        if start <= last_end:
            merged[-1] = (last_start, max(last_end, end))
        else:
            merged.append((start, end))
    return merged


def _timestamp_to_text(timestamp: int | None) -> str | None:
    if timestamp is None:
        return None
    value = timestamp / 1000 if timestamp > 10_000_000_000 else timestamp
    try:
        return datetime.fromtimestamp(value).isoformat(sep=" ", timespec="milliseconds")
    except (OSError, OverflowError, ValueError):
        return None


def _json_scalar(value: str) -> Any:
    if value == "true":
        return True
    if value == "false":
        return False
    if value == "null":
        return None
    if value.startswith('"') and value.endswith('"'):
        try:
            return json.loads(value)
        except json.JSONDecodeError:
            return value[1:-1]
    try:
        return int(value)
    except ValueError:
        try:
            return float(value)
        except ValueError:
            return value


def _json_field_map(segment: str) -> dict[str, Any]:
    fields: dict[str, Any] = {}
    for match in JSON_FIELD_RE.finditer(segment):
        key = match.group("key")
        if key == "text":
            continue
        fields.setdefault(key, _json_scalar(match.group("value")))
    return fields


def _first_field(fields: dict[str, Any], keys: tuple[str, ...]) -> str | None:
    for key in keys:
        value = fields.get(key)
        if value is None or value is False:
            continue
        text = str(value).strip()
        if text:
            return text
    return None


def _phone_from_text(text: str) -> str | None:
    match = VISIBLE_PHONE_RE.search(text)
    return match.group(1) if match else None


def _normalize_color(value: str) -> str:
    return "#" + value.lower()


def _formatting_from_raw(raw_text: str, record_type: str | None = None, chat_text: str | None = None) -> dict[str, Any]:
    segments = [
        {"color": _normalize_color(match.group("color")), "offset": match.start(), "token": match.group(0)}
        for match in COLOR_TAG_RE.finditer(raw_text)
    ]
    if segments:
        colors = []
        for segment in segments:
            color = str(segment["color"])
            if color not in colors:
                colors.append(color)
        return {
            "source": "memory.inline_tag",
            "primaryColor": colors[0],
            "colors": colors,
            "segments": segments,
        }
    inferred = _inferred_message_color(record_type, chat_text or "")
    if inferred is None:
        return {}
    return {
        "source": "inferred.semantic",
        "primaryColor": inferred,
        "colors": [inferred],
    }


def _primary_color(formatting: dict[str, Any]) -> str | None:
    value = formatting.get("primaryColor")
    return str(value) if value else None


def _inferred_message_color(record_type: str | None, text: str) -> str | None:
    if text.startswith("[fam]") or record_type == "family":
        return "#f745a4"
    if text.startswith("[gov]") or record_type == "gov":
        return "#33ccff"
    if text.startswith("[Weazel News]") or record_type == "news":
        return "#24df42"
    if record_type == "me" or "\u043b\u044e\u0431\u0443\u0435\u0442\u0441\u044f" in text:
        return "#c2a2da"
    if record_type == "system":
        return "#33ccff"
    return None


def _stable_message_id(
    record_type: str,
    text: str,
    timestamp: int | None,
    phone_number: str | None,
    player_name: str | None,
    player_id: str | None,
    static_id: str | None,
    color: str | None,
) -> str:
    payload = "\x1f".join(
        [
            record_type,
            str(timestamp or ""),
            text,
            phone_number or "",
            player_name or "",
            player_id or "",
            static_id or "",
            color or "",
        ]
    )
    return hashlib.sha1(payload.encode("utf-8", errors="ignore")).hexdigest()[:20]


def _looks_like_player_name(value: str) -> bool:
    parts = [part.strip(":,;") for part in value.replace(".", " ").split()]
    return (
        2 <= len(parts) <= 4
        and all(any(ch.isalpha() for ch in part) for part in parts)
        and all(any(ch.islower() for ch in part) for part in parts)
        and all(part[0].isalpha() and part[0].isupper() for part in parts if part)
    )


def _static_id_from_speaker(value: str) -> str | None:
    speaker = value.replace("[default]", "").strip().strip(":,;")
    match = STATIC_SPEAKER_RE.fullmatch(speaker)
    return match.group("static_id") if match else None


def _looks_like_player_action_tail(value: str) -> bool:
    tail = value.strip()
    if len(tail) < 3 or _russian_score(tail) < 3:
        return False
    if any(marker in tail for marker in ("{", "}", ":", "_", "Botmessage", "Answers")):
        return False
    first = tail[0]
    if not (("а" <= first <= "я") or first == "ё"):
        return False
    lowered = tail.lower()
    first_word = lowered.split(maxsplit=1)[0].strip(".,!?:;")
    if first_word in {"в", "во", "у", "на", "с", "со", "к", "ко", "из", "не"}:
        return False
    return any(keyword in lowered for keyword in PLAYER_ACTION_KEYWORDS)


def _owner_from_fields(fields: dict[str, Any], chat_text: str) -> dict[str, Any]:
    owner: dict[str, Any] = {}
    rendered = _rendered_owner(chat_text)
    editor_name = _first_field(fields, EDITOR_NAME_KEYS)
    player_name = _first_field(fields, PLAYER_NAME_KEYS)
    player_id = _first_field(fields, PLAYER_ID_KEYS)
    static_id = _first_field(fields, STATIC_ID_KEYS)
    if rendered:
        owner.update(rendered)
        if editor_name and owner.get("name") != editor_name:
            owner["editorName"] = editor_name
        if player_name and owner.get("name") != player_name:
            owner["userName"] = player_name
        if player_id:
            owner["playerId"] = player_id
        if static_id:
            owner["staticId"] = static_id
        return owner
    if editor_name:
        owner["editorName"] = editor_name
    if player_name:
        owner["name"] = player_name
    if player_id:
        owner["playerId"] = player_id
    if static_id:
        owner["staticId"] = static_id
    if owner:
        return owner
    return rendered


def _visible_message_owner(text: str) -> dict[str, Any]:
    owner: dict[str, Any] = {}
    body = re.sub(r"^(?:\[[^\]]+\]\s*)+", "", text).strip()
    if "\u0433\u043e\u0432\u043e\u0440\u0438\u0442:" in text:
        speaker = text.split("\u0433\u043e\u0432\u043e\u0440\u0438\u0442:", 1)[0].replace("[default]", "").strip()
        speaker = re.sub(r"^(?:\[[^\]]+\]\s*)+", "", speaker).strip()
        static_id = _static_id_from_speaker(speaker)
        if static_id:
            owner["staticId"] = static_id
            owner["kind"] = "player"
        elif _looks_like_player_name(speaker):
            owner["name"] = speaker
            owner["kind"] = "player"
    elif "\u043b\u044e\u0431\u0443\u0435\u0442\u0441\u044f" in text:
        match = PLAYER_NAME_RE.match(text.replace("[me]", "").strip())
        speaker = match.group("name") if match else ""
        if speaker and _looks_like_player_name(speaker):
            owner["name"] = speaker
            owner["kind"] = "player"
    elif re.match(r"^[A-Z][A-Za-z_'-]{1,24}\s+[A-Z][A-Za-z_'-]{1,24}\s*:\s*\(\(", body):
        speaker = body.split(":", 1)[0].strip()
        if _looks_like_player_name(speaker):
            owner["name"] = speaker
            owner["kind"] = "player"
    elif text.startswith("[Weazel News]") and ":" in text:
        prefix, _ = text.split(":", 1)
        speaker = prefix.removeprefix("[Weazel News]").strip()
        if _looks_like_player_name(speaker):
            owner["name"] = speaker
            owner["kind"] = "player"
            owner["organization"] = "Weazel News"
    elif match := PLAYER_NAME_RE.match(body):
        speaker = match.group("name")
        tail = body[match.end() :].strip()
        if _looks_like_player_name(speaker) and _looks_like_player_action_tail(tail):
            owner["name"] = speaker
            owner["kind"] = "player"
    elif text.startswith("[default]"):
        tail = text.removeprefix("[default]").strip()
        words = tail.split()
        if len(words) >= 2:
            candidate = " ".join(words[:2])
            if _looks_like_player_name(candidate):
                owner["name"] = candidate.rstrip(":,;")
                owner["kind"] = "player"
    return owner


def _rendered_owner(text: str) -> dict[str, Any]:
    owner = _visible_message_owner(text)
    player_id_match = re.search(r"\[(?P<player_id>\d{1,7})\]\s*:", text)
    if player_id_match:
        before = text[: player_id_match.start()]
        before = re.sub(r"^\[[^\]]+\]\s*", "", before)
        parts = [part for part in re.sub(r"\[[^\]]+\]", " ", before).split() if part]
        if len(parts) >= 2:
            name = " ".join(parts[-2:])
            if _looks_like_player_name(name):
                owner["name"] = name
                owner["kind"] = "player"
        if len(parts) > 2:
            owner["role"] = " ".join(parts[:-2])
        owner["playerId"] = player_id_match.group("player_id")
    if not owner and text.startswith(("[gov]", "[ el News]")) and ":" in text:
        prefix, _ = text.split(":", 1)
        organization = re.sub(r"^\[[^\]]+\]\s*", "", prefix).strip()
        if organization:
            owner["name"] = organization
            owner["kind"] = "organization"
    return owner


def _record_metadata(fields: dict[str, Any], chat_text: str) -> dict[str, Any]:
    owner = _owner_from_fields(fields, chat_text)
    rendered_owner = _rendered_owner(chat_text)
    visible_player_name = (
        str(rendered_owner.get("name"))
        if rendered_owner.get("kind") == "player" and rendered_owner.get("name")
        else None
    )
    return {
        "messageId": _first_field(fields, MESSAGE_ID_KEYS) or _first_field(fields, ("id",)),
        "playerId": _first_field(fields, PLAYER_ID_KEYS) or (str(owner.get("playerId")) if owner.get("playerId") else None),
        "staticId": _first_field(fields, STATIC_ID_KEYS) or (str(owner.get("staticId")) if owner.get("staticId") else None),
        "playerName": visible_player_name
        or _first_field(fields, PLAYER_NAME_KEYS)
        or (str(owner.get("name")) if owner.get("kind") == "player" and owner.get("name") else None),
        "owner": owner,
    }


def _parse_addr(value: str) -> int:
    return int(value, 16) if value.lower().startswith("0x") else int(value)


def _latest_search_report(report_dir: Path) -> Path | None:
    paths = sorted(report_dir.glob("chat_memory_search_*.json"), key=lambda path: path.stat().st_mtime, reverse=True)
    for path in paths:
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            continue
        if data.get("hits"):
            return path
    return paths[0] if paths else None


def _anchor_addrs_from_report(path: Path) -> list[int]:
    data = json.loads(path.read_text(encoding="utf-8"))
    addrs: list[int] = []
    for hit in data.get("hits", []):
        raw = hit.get("addr") if isinstance(hit, dict) else None
        if isinstance(raw, str):
            try:
                addrs.append(_parse_addr(raw))
            except ValueError:
                continue
    return addrs


def _is_auto_process(value: str) -> bool:
    return value.strip().lower() in AUTO_PROCESS_TOKENS


def _process_role(cmdline: list[str]) -> str | None:
    for item in cmdline:
        if item.startswith("--type="):
            return item.split("=", 1)[1].strip() or None
    return None


def _process_snapshot(proc: psutil.Process) -> dict[str, Any] | None:
    try:
        name = proc.name()
        cmdline = proc.cmdline()
        return {
            "process": name,
            "pid": proc.pid,
            "parent_pid": proc.ppid(),
            "role": _process_role(cmdline),
            "create_time": proc.create_time(),
            "command_line": " ".join(cmdline),
        }
    except (psutil.AccessDenied, psutil.NoSuchProcess, psutil.ZombieProcess):
        return None


def _auto_process_candidates(*, include_gta: bool = False) -> list[dict[str, Any]]:
    gta_pids: set[int] = set()
    snapshots: list[dict[str, Any]] = []
    raw_snapshots: list[dict[str, Any]] = []
    for proc in psutil.process_iter():
        snapshot = _process_snapshot(proc)
        if snapshot is None:
            continue
        raw_snapshots.append(snapshot)
        name = str(snapshot["process"]).lower()
        if name in {"gta5.exe", "gta5"}:
            gta_pids.add(int(snapshot["pid"]))
    for snapshot in raw_snapshots:
        name = str(snapshot["process"]).lower()
        if name in {"majestic-webengine.exe", "majestic-webengine"}:
            if gta_pids and int(snapshot.get("parent_pid") or -1) not in gta_pids:
                continue
            role = snapshot.get("role")
            if role and role != "renderer":
                continue
            snapshots.append(snapshot)
        elif include_gta and name in {"gta5.exe", "gta5"}:
            snapshots.append(snapshot)
    return sorted(
        snapshots,
        key=lambda item: (
            0 if str(item.get("process", "")).lower().startswith("majestic-webengine") else 1,
            0 if item.get("role") == "renderer" else 1,
            int(item.get("pid") or 0),
        ),
    )


def _discovery_marker_bytes() -> list[tuple[str, int, bytes]]:
    markers: list[tuple[str, int, bytes]] = []
    for marker, weight in CHAT_DISCOVERY_MARKERS:
        markers.append((marker, weight, marker.encode("utf-8")))
        markers.append((marker, weight, marker.encode("utf-16-le")))
    return markers


def _count_discovery_markers(data: bytes, carry_len: int, markers: list[tuple[str, int, bytes]]) -> tuple[int, int, dict[str, int]]:
    score = 0
    hit_count = 0
    counts: dict[str, int] = {}
    for label, weight, marker in markers:
        search_from = 0
        while True:
            hit = data.find(marker, search_from)
            if hit < 0:
                break
            if hit + len(marker) > carry_len:
                counts[label] = counts.get(label, 0) + 1
                hit_count += 1
                score += weight
            search_from = hit + 1
    return score, hit_count, counts


def _score_chat_process(
    args: argparse.Namespace,
    process_name: str,
    pid: int,
    *,
    max_total_mb: int | None = None,
    marker_hit_limit: int | None = None,
) -> dict[str, Any]:
    started = time.perf_counter()
    report: dict[str, Any] = {"process": process_name, "pid": pid, "score": 0, "marker_hit_count": 0}
    try:
        snapshot = _process_snapshot(psutil.Process(pid))
        if snapshot:
            report.update(snapshot)
    except psutil.Error:
        pass
    try:
        tracker = _open_tracker(process_name, pid)
    except Exception as exc:
        report["error"] = str(exc)
        report["elapsed_seconds"] = time.perf_counter() - started
        return report
    try:
        regions = _collect_search_regions(
            tracker,
            args.max_region_mb,
            args.auto_max_total_mb if max_total_mb is None else max_total_mb,
        )
        markers = _discovery_marker_bytes()
        max_marker_len = max(len(marker) for _, _, marker in markers)
        chunk_size = max(4096, args.chunk_mb * 1024 * 1024)
        limit = args.auto_marker_hits if marker_hit_limit is None else marker_hit_limit
        score = 0
        hit_count = 0
        marker_counts: dict[str, int] = {}
        for start, end in regions:
            if hit_count >= limit:
                break
            addr = start
            carry = b""
            while addr < end and hit_count < limit:
                size = min(chunk_size, end - addr)
                data = tracker._read(addr, size)
                if not data:
                    carry = b""
                    addr += size
                    continue
                scan_data = carry + data
                chunk_score, chunk_hits, chunk_counts = _count_discovery_markers(scan_data, len(carry), markers)
                score += chunk_score
                hit_count += chunk_hits
                for key, value in chunk_counts.items():
                    marker_counts[key] = marker_counts.get(key, 0) + value
                carry = scan_data[-(max_marker_len - 1) :]
                addr += size
        process_lower = str(report.get("process") or process_name).lower()
        if process_lower.startswith("majestic-webengine"):
            score += 50
        if report.get("role") == "renderer":
            score += 35
        if report.get("parent_pid"):
            score += 5
        report.update(
            {
                "regions": len(regions),
                "score": score,
                "marker_hit_count": hit_count,
                "marker_counts": marker_counts,
                "elapsed_seconds": time.perf_counter() - started,
            }
        )
        return report
    finally:
        tracker.stop()


def _candidate_sort_key(candidate: dict[str, Any]) -> tuple[int, int, int, int]:
    process = str(candidate.get("process") or "").lower()
    return (
        -int(candidate.get("score") or 0),
        0 if process.startswith("majestic-webengine") else 1,
        0 if candidate.get("role") == "renderer" else 1,
        int(candidate.get("pid") or 0),
    )


def _select_chat_candidates(candidates: list[dict[str, Any]], limit: int) -> list[dict[str, Any]]:
    ranked = sorted(candidates, key=_candidate_sort_key)
    return [item for item in ranked if int(item.get("marker_hit_count") or 0) > 0][:limit]


def _process_cache_path(out_dir: Path) -> Path:
    return out_dir / PROCESS_CACHE_NAME


def _load_cached_chat_process(args: argparse.Namespace, out_dir: Path) -> dict[str, Any] | None:
    if getattr(args, "no_process_cache", False):
        return None
    path = _process_cache_path(out_dir)
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return None
    selected = data.get("selected")
    if not isinstance(selected, dict):
        return None
    pid = selected.get("pid")
    process_name = selected.get("process")
    if not isinstance(pid, int) or not isinstance(process_name, str):
        return None
    if process_name.lower().startswith("gta5") and getattr(args, "cef_only", False):
        return None
    try:
        snapshot = _process_snapshot(psutil.Process(pid))
    except psutil.Error:
        return None
    if snapshot is None or str(snapshot.get("process", "")).lower() != process_name.lower():
        return None
    cached_create_time = selected.get("create_time")
    if isinstance(cached_create_time, (int, float)) and abs(float(cached_create_time) - float(snapshot["create_time"])) > 1:
        return None
    report = _score_chat_process(args, process_name, pid, max_total_mb=min(args.auto_max_total_mb, 256), marker_hit_limit=8)
    if int(report.get("marker_hit_count") or 0) <= 0:
        return None
    report["cache"] = "hit"
    return report


def _write_chat_process_cache(out_dir: Path, selected: dict[str, Any], candidates: list[dict[str, Any]]) -> None:
    out_dir.mkdir(parents=True, exist_ok=True)
    payload = {
        "kind": "sonar_chat_process_cache",
        "updated_at": time.time(),
        "selected": selected,
        "candidates": candidates,
    }
    _process_cache_path(out_dir).write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")


def _resolve_process_targets(args: argparse.Namespace, out_dir: Path) -> tuple[list[tuple[str, int | None]], dict[str, Any]]:
    if not _is_auto_process(args.process):
        targets = iter_process_targets(args.process)
        return targets, {"mode": "manual", "selected": [{"process": name, "pid": pid} for name, pid in targets]}

    cached = _load_cached_chat_process(args, out_dir)
    if cached is not None:
        return [(str(cached["process"]), int(cached["pid"]))], {
            "mode": "auto",
            "cache": "hit",
            "selected": [cached],
            "candidates": [cached],
        }

    candidates = [
        _score_chat_process(args, str(item["process"]), int(item["pid"]))
        for item in _auto_process_candidates(include_gta=not getattr(args, "cef_only", False))
        if isinstance(item.get("pid"), int)
    ]
    selected = _select_chat_candidates(candidates, max(1, args.max_chat_processes))
    if selected:
        _write_chat_process_cache(out_dir, selected[0], candidates)
    return [(str(item["process"]), int(item["pid"])) for item in selected], {
        "mode": "auto",
        "cache": "miss",
        "selected": selected,
        "candidates": candidates,
    }


class DumpMemoryTracker:
    def __init__(self, dump_root: Path, process_info: dict[str, Any]) -> None:
        self.process_name = str(process_info.get("process") or "dump")
        self.pid = int(process_info.get("pid") or 0)
        self.info = process_info
        data_file = process_info.get("data_file")
        if not isinstance(data_file, str) or not data_file:
            raise ValueError(f"Memory dump process has no data_file: {self.process_name} pid={self.pid}")
        self.data_path = dump_root / data_file
        self._file = self.data_path.open("rb")
        regions: list[tuple[int, int, int]] = []
        for raw_region in process_info.get("regions", []):
            if not isinstance(raw_region, dict):
                continue
            start = int(raw_region.get("start") or 0)
            end = int(raw_region.get("end") or 0)
            file_offset = int(raw_region.get("file_offset") or 0)
            if end > start:
                regions.append((start, end, file_offset))
        covered_file_end = max((file_offset + (end - start) for start, end, file_offset in regions), default=0)
        file_size = self.data_path.stat().st_size
        if file_size > covered_file_end:
            base = max(PTR_MIN, max((end for _, end, _ in regions), default=PTR_MIN))
            orphan_start = min(PTR_MAX - (file_size - covered_file_end), base + 0x10000)
            orphan_end = orphan_start + (file_size - covered_file_end)
            if PTR_MIN <= orphan_start < orphan_end <= PTR_MAX:
                regions.append((orphan_start, orphan_end, covered_file_end))
                self.info["orphan_tail_bytes"] = file_size - covered_file_end
        self._regions = sorted(regions)
        self._starts = [start for start, _, _ in self._regions]

    def _collect_regions(self, start: int, end: int) -> list[tuple[int, int]]:
        regions: list[tuple[int, int]] = []
        for region_start, region_end, _ in self._regions:
            clipped_start = max(start, region_start)
            clipped_end = min(end, region_end)
            if clipped_end > clipped_start:
                regions.append((clipped_start, clipped_end))
        return regions

    def _read(self, addr: int, size: int) -> bytes | None:
        if size <= 0:
            return b""
        index = bisect.bisect_right(self._starts, addr) - 1
        if index < 0:
            return None
        region_start, region_end, file_offset = self._regions[index]
        if not (region_start <= addr < region_end):
            return None
        readable = min(size, region_end - addr)
        self._file.seek(file_offset + addr - region_start)
        data = self._file.read(readable)
        return data or None

    def stop(self) -> None:
        self._file.close()


def _load_memory_dump(path_value: str | None) -> tuple[Path, dict[str, Any]] | None:
    if not path_value:
        return None
    path = Path(path_value)
    manifest_path = path / "manifest.json" if path.is_dir() else path
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    root = manifest_path.parent
    return root, manifest


def _score_dump_chat_process(args: argparse.Namespace, dump_root: Path, process_info: dict[str, Any]) -> dict[str, Any]:
    started = time.perf_counter()
    process_name = str(process_info.get("process") or "dump")
    pid = int(process_info.get("pid") or 0)
    report: dict[str, Any] = {
        "process": process_name,
        "pid": pid,
        "score": 0,
        "marker_hit_count": 0,
        "source": "memory_dump",
    }
    for key in ("create_time", "cmdline", "exe"):
        if key in process_info:
            report[key] = process_info[key]
    tracker = DumpMemoryTracker(dump_root, process_info)
    try:
        regions = _collect_search_regions(
            tracker,  # type: ignore[arg-type]
            args.max_region_mb,
            args.auto_max_total_mb,
        )
        markers = _discovery_marker_bytes()
        max_marker_len = max(len(marker) for _, _, marker in markers)
        chunk_size = max(4096, args.chunk_mb * 1024 * 1024)
        score = 0
        hit_count = 0
        marker_counts: dict[str, int] = {}
        for start, end in regions:
            if hit_count >= args.auto_marker_hits:
                break
            addr = start
            carry = b""
            while addr < end and hit_count < args.auto_marker_hits:
                size = min(chunk_size, end - addr)
                data = tracker._read(addr, size)
                if not data:
                    carry = b""
                    addr += size
                    continue
                scan_data = carry + data
                chunk_score, chunk_hits, chunk_counts = _count_discovery_markers(scan_data, len(carry), markers)
                score += chunk_score
                hit_count += chunk_hits
                for key, value in chunk_counts.items():
                    marker_counts[key] = marker_counts.get(key, 0) + value
                carry = scan_data[-(max_marker_len - 1) :]
                addr += size
        if process_name.lower().startswith("majestic-webengine"):
            score += 50
        if process_name.lower().startswith("gta5"):
            score -= 20
        report.update(
            {
                "regions": len(regions),
                "score": score,
                "marker_hit_count": hit_count,
                "marker_counts": marker_counts,
                "elapsed_seconds": time.perf_counter() - started,
            }
        )
        return report
    finally:
        tracker.stop()


def _dump_process_matches(process_info: dict[str, Any], token: str) -> bool:
    process_name = str(process_info.get("process") or "").lower()
    pid = str(process_info.get("pid") or "")
    wanted = token.strip().lower()
    if not wanted:
        return False
    if wanted.startswith("pid:"):
        return pid == wanted.split(":", 1)[1]
    if wanted.isdigit():
        return pid == wanted
    return process_name == wanted or (wanted.endswith(".exe") and process_name == wanted[:-4]) or process_name + ".exe" == wanted


def _resolve_memory_dump_targets(
    args: argparse.Namespace,
    dump_root: Path,
    manifest: dict[str, Any],
) -> tuple[list[dict[str, Any]], dict[str, Any]]:
    processes = [item for item in manifest.get("processes", []) if isinstance(item, dict) and item.get("regions")]
    if not _is_auto_process(args.process):
        selected: list[dict[str, Any]] = []
        seen: set[tuple[str, int]] = set()
        for raw_token in args.process.split(","):
            token = raw_token.strip()
            if not token:
                continue
            for process_info in processes:
                if not _dump_process_matches(process_info, token):
                    continue
                key = (str(process_info.get("process") or ""), int(process_info.get("pid") or 0))
                if key in seen:
                    continue
                seen.add(key)
                selected.append(process_info)
        return selected, {
            "mode": "memory_dump",
            "dump": str(dump_root),
            "selected": [{"process": item.get("process"), "pid": item.get("pid")} for item in selected],
            "candidates": [{"process": item.get("process"), "pid": item.get("pid")} for item in processes],
        }

    candidates = [_score_dump_chat_process(args, dump_root, item) for item in processes]
    selected_reports = _select_chat_candidates(candidates, max(1, args.max_chat_processes))
    selected_keys = {(item.get("process"), item.get("pid")) for item in selected_reports}
    selected = [item for item in processes if (item.get("process"), item.get("pid")) in selected_keys]
    return selected, {
        "mode": "memory_dump_auto",
        "dump": str(dump_root),
        "selected": selected_reports,
        "candidates": candidates,
    }


def _russian_score(text: str) -> int:
    return sum(("А" <= ch <= "я") or ch in "Ёё" for ch in text)


def _repair_mojibake(text: str) -> str:
    best = text
    best_score = _russian_score(text)
    for encoding in ("cp1251", "latin1"):
        try:
            candidate = text.encode(encoding, errors="strict").decode("utf-8", errors="strict")
        except UnicodeError:
            continue
        score = _russian_score(candidate)
        if score > best_score:
            best = candidate
            best_score = score
    return best


def _is_noise_token(token: str) -> bool:
    stripped = token.strip()
    if not stripped:
        return False
    if len(stripped) > 4:
        return False
    if not NOISE_TOKEN_RE.match(stripped):
        return False
    return any(ch in stripped for ch in "%+*/=|\\:;.,!?@#\"'()[]{}-") or stripped.isupper() or stripped.isdigit()


def _trim_corrupted_tail(text: str) -> str:
    tokens = list(re.finditer(r"\S+", text))
    run_start: int | None = None
    run = 0
    for match in tokens:
        token = match.group(0)
        if _is_noise_token(token):
            if run == 0:
                run_start = match.start()
            run += 1
            if run >= 8 and run_start is not None and run_start > 32:
                return text[:run_start].rstrip(" ,.;:-")
            continue
        run = 0
        run_start = None
    return text


def _chat_text_noise_score(text: str) -> int:
    score = 0
    score += text.count("\ufffd") * 20
    score += text.count("%") * 4
    score += text.count("{") * 3
    score += text.count("}") * 3
    score += text.count("=") * 2
    score += text.count("+")
    score += text.count("\\")
    score += sum(20 for marker in BAD_RECORD_MARKERS if marker in text)
    score += max(0, len(re.findall(r"\b[A-Za-z]\b", text)) - 4)
    return score


def _is_bad_chat_text(text: str, timestamp: int | None) -> bool:
    noise = _chat_text_noise_score(text)
    if any(marker in text for marker in BAD_RECORD_MARKERS):
        return True
    if "@{" in text or len(re.findall(r"%[A-Z]", text)) >= 2:
        return True
    if len(text) < 80 and noise >= 4:
        return True
    if timestamp is None and (noise >= 18 or len(text) > 1200):
        return True
    return noise >= max(22, len(text) // 12)


def _record_quality(record: ChatRecord | dict) -> tuple[int, int, int]:
    if isinstance(record, ChatRecord):
        text = record.text
        timestamp = record.timestamp
    else:
        text = str(record.get("text") or "")
        timestamp = record.get("timestamp") if isinstance(record.get("timestamp"), int) else None
    noise = _chat_text_noise_score(text)
    timestamp_bonus = 100 if timestamp is not None else 0
    prefix_bonus = 20 if any(marker in text for marker in CHAT_PREFIX_MARKERS) else 0
    length_score = min(len(text), 900)
    return (timestamp_bonus + prefix_bonus + _russian_score(text) * 2 + length_score - noise * 12, -noise, length_score)


def _clean_chat_text(text: str) -> str:
    text = urllib.parse.unquote(text)
    text = _repair_mojibake(text)
    text = text.replace("\\/", "/")
    text = re.sub(r"@\{[0-9A-Fa-f]{6}\}", "", text)
    text = "".join(
        ch
        if (
            ch.isascii()
            and (ch.isalnum() or ch.isspace() or ch in "[]{}():;.,!?-_/&%+@#=\"'")
        )
        or ("А" <= ch <= "я")
        or ch in "Ёё"
        else " "
        for ch in text
    )
    text = re.sub(r"\s+", " ", text).strip()
    text = _trim_corrupted_tail(text)
    for anchor in (*CHAT_PREFIX_MARKERS, "[Gov]"):
        pos = text.find(anchor)
        if pos > 0:
            text = text[pos:].strip()
            break
    while text and not (text[0].isalnum() or text[0] == "["):
        text = text[1:].lstrip()
    return text


def _extract_field_text(segment: str, start: int) -> str:
    end_candidates = [segment.find(marker, start) for marker in TEXT_END_MARKERS]
    end_candidates = [index for index in end_candidates if index >= 0]
    end = min(end_candidates) if end_candidates else min(len(segment), start + 8000)
    return segment[start:end]


def _record_from_segment(
    segment: str,
    record_type: str,
    timestamp: int | None,
    base_pos: int,
    encoding: str,
    source: str,
    process: str | None = None,
    pid: int | None = None,
) -> ChatRecord | None:
    field_match = TEXT_FIELD_RE.search(segment)
    if not field_match:
        return None
    raw_text = _extract_field_text(segment, field_match.end())
    chat_text = _clean_chat_text(raw_text)
    if len(chat_text) < 8:
        return None
    if _is_bad_chat_text(chat_text, timestamp):
        return None
    if not (_russian_score(chat_text) or any(marker in chat_text for marker in ("News", "Sheriff", *CHAT_PREFIX_MARKERS, ":"))):
        return None
    if timestamp is None and "News" not in chat_text and _russian_score(chat_text) < 10:
        return None
    raw_fields = _json_field_map(segment)
    phone_match = PHONE_RE.search(segment)
    id_match = ID_RE.search(segment)
    phone_value = raw_fields.get("phoneNumber") or (phone_match.group(1) if phone_match else None) or _phone_from_text(chat_text)
    id_value = raw_fields.get("id") or (id_match.group(1) if id_match else None)
    metadata = _record_metadata(raw_fields, chat_text)
    phone_text = (str(phone_value).strip() or None) if phone_value is not None else None
    if phone_text and record_type == "news":
        visible_phone = f"\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440: {phone_text}"
        if visible_phone not in chat_text and phone_text not in chat_text:
            chat_text = f"{chat_text.rstrip()} {visible_phone}"
        raw_fields.setdefault("phoneNumber_source", "memory")
    formatting = _formatting_from_raw(raw_text, record_type, chat_text)
    color = _primary_color(formatting)
    stable_id = _stable_message_id(
        record_type,
        chat_text,
        timestamp,
        phone_text,
        metadata["playerName"],
        metadata["playerId"],
        metadata["staticId"],
        color,
    )
    message_id = metadata["messageId"] or stable_id
    raw_fields.setdefault("messageId_source", "memory" if metadata["messageId"] else "stable_hash")
    return ChatRecord(
        type=record_type,
        text=chat_text,
        timestamp=timestamp,
        time=_timestamp_to_text(timestamp),
        phoneNumber=phone_text,
        id=(str(id_value).strip() or None) if id_value is not None else None,
        source=source,
        encoding=encoding,
        pos=base_pos,
        process=process,
        pid=pid,
        messageId=message_id,
        stableId=stable_id,
        playerId=metadata["playerId"],
        staticId=metadata["staticId"],
        playerName=metadata["playerName"],
        color=color,
        formatting=formatting,
        owner=metadata["owner"],
        raw_fields=raw_fields,
    )


def _record_segment_bounds(text: str, timestamp_match: re.Match[str]) -> tuple[int, int]:
    lookback_start = max(0, timestamp_match.start() - 12000)
    prefix = text[lookback_start : timestamp_match.start()]
    starts = [match.start() + lookback_start for match in RECORD_BOUNDARY_RE.finditer(prefix)]
    start = starts[-1] if starts else lookback_start
    next_match = RECORD_BOUNDARY_RE.search(text, timestamp_match.end())
    end = next_match.start() if next_match else min(len(text), timestamp_match.end() + 4000)
    return start, end


def _extract_records_from_text(
    text: str,
    base_addr: int,
    encoding: str,
    source: str,
    scale: int,
    process: str | None = None,
    pid: int | None = None,
) -> list[ChatRecord]:
    records: list[ChatRecord] = []
    for timestamp_match in TIMESTAMP_RE.finditer(text):
        start, end = _record_segment_bounds(text, timestamp_match)
        segment = text[start:end]
        type_match = TYPE_RE.search(segment)
        if not type_match:
            continue
        record_type = type_match.group(1).lower()
        if record_type not in CHAT_TYPES:
            continue
        try:
            timestamp = int(timestamp_match.group(1))
        except ValueError:
            timestamp = None
        record = _record_from_segment(
            segment,
            record_type,
            timestamp,
            base_addr + start * scale,
            encoding,
            source,
            process,
            pid,
        )
        if record is not None:
            records.append(record)
    for type_match in TYPE_RE.finditer(text):
        record_type = type_match.group(1).lower()
        start = type_match.start()
        next_match = RECORD_BOUNDARY_RE.search(text, type_match.end())
        end = next_match.start() if next_match else min(len(text), type_match.end() + 12000)
        segment = text[start:end]
        timestamp_match = TIMESTAMP_RE.search(segment)
        timestamp = int(timestamp_match.group(1)) if timestamp_match else None
        record = _record_from_segment(
            segment,
            record_type,
            timestamp,
            base_addr + start * scale,
            encoding,
            source,
            process,
            pid,
        )
        if record is not None:
            records.append(record)
    return _dedupe_records(records)


def _is_fragment_char(ch: str) -> bool:
    return (
        ch.isascii()
        and (ch.isalnum() or ch.isspace() or ch in "[]{}():;.,!?-_/&%+@#=\"'")
    ) or ("А" <= ch <= "я") or ch in "Ёё"


def _extract_wide_fragments(
    data: bytes,
    base_addr: int,
    source: str,
    min_chars: int,
    process: str | None = None,
    pid: int | None = None,
) -> list[TextFragment]:
    fragments: list[TextFragment] = []
    for align in (0, 1):
        text = data[align:].decode("utf-16-le", errors="ignore")
        current: list[str] = []
        current_start = 0
        for index, ch in enumerate(text):
            if _is_fragment_char(ch):
                if not current:
                    current_start = index
                current.append(ch)
                continue
            if current:
                fragment = _clean_chat_text("".join(current))
                if _is_chat_fragment(fragment, min_chars):
                    fragments.append(
                        TextFragment(
                            text=fragment,
                            source=source,
                            encoding="utf-16-le",
                            addr=base_addr + align + current_start * 2,
                            process=process,
                            pid=pid,
                        )
                    )
                current = []
        if current:
            fragment = _clean_chat_text("".join(current))
            if _is_chat_fragment(fragment, min_chars):
                fragments.append(
                    TextFragment(
                        text=fragment,
                        source=source,
                        encoding="utf-16-le",
                        addr=base_addr + align + current_start * 2,
                        process=process,
                        pid=pid,
                    )
                )
    return fragments


def _is_chat_fragment(text: str, min_chars: int) -> bool:
    if len(text) < min_chars:
        return False
    if _looks_like_code_fragment(text):
        return False
    if any(marker in text for marker in CHAT_PREFIX_MARKERS):
        return True
    return any(
        marker in text
        for marker in (
            "\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:",
            "\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c \u043d\u0430 Majestic Role Play",
            "\u041f\u043e\u0431\u0435\u0434\u0438\u0442\u0435\u043b\u044f\u043c\u0438",
            "\u0412\u0441\u0435\u0433\u043e \u0443\u0447\u0430\u0441\u0442\u043d\u0438\u043a\u043e\u0432",
            "\u0433\u043e\u0432\u043e\u0440\u0438\u0442:",
        )
    )


def _is_chat_input_fragment(text: str, min_chars: int) -> bool:
    if len(text) < min_chars:
        return False
    if _looks_like_code_fragment(text) or _chat_text_noise_score(text) >= 12:
        return False
    return _russian_score(text) >= 4 or any(marker in text for marker in CHAT_PREFIX_MARKERS)


def _looks_like_code_fragment(text: str) -> bool:
    if any(marker in text for marker in CODE_FRAGMENT_MARKERS):
        return True
    structural_chars = text.count("{") + text.count("}") + text.count("=")
    if structural_chars >= 5 and text.count(",") >= 5:
        return True
    return text.count(":") >= 4 and text.count("{") >= 2


def _extract_chat_input_fragments(
    data: bytes,
    base_addr: int,
    source: str,
    min_chars: int,
    process: str | None = None,
    pid: int | None = None,
) -> list[TextFragment]:
    fragments: list[TextFragment] = []
    minimum = min(min_chars, 8)
    for align in (0, 1):
        text = data[align:].decode("utf-16-le", errors="ignore")
        for marker_match in re.finditer("chatInput", text):
            start = marker_match.end()
            window = text[start : start + 500]
            for match in re.finditer(r"[\w\s\[\]{}():;.,!?/_@#=\"'+-]{%d,}" % minimum, window):
                fragment = _clean_chat_text(match.group(0))
                if not _is_chat_input_fragment(fragment, minimum):
                    continue
                if fragment in {"chatInput", "copy-input"}:
                    continue
                fragments.append(
                    TextFragment(
                        text=fragment,
                        source=f"{source} chat_input",
                        encoding="utf-16-le",
                        addr=base_addr + align + (start + match.start()) * 2,
                        process=process,
                        pid=pid,
                    )
                )
    return fragments


def _rendered_chat_type(text: str) -> str | None:
    if text.startswith("[fam]"):
        return "family"
    if text.startswith("[frac]"):
        return "fraction"
    if text.startswith("[Weazel News]") or (text.startswith("Weazel News") and ":" in text):
        return "news"
    if text.startswith(("\u041a\u0440\u0438\u0442\u0435\u0440\u0438\u0438:", "\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:")):
        return "news"
    if text.startswith("[gov]") or text.startswith("[global]") or text.startswith("[ el News]"):
        return "system"
    if text.startswith(
        (
            "\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c \u043d\u0430 Majestic Role Play",
            "\u041f\u043e\u0431\u0435\u0434\u0438\u0442\u0435\u043b\u044f\u043c\u0438",
            "\u0412\u0441\u0435\u0433\u043e \u0443\u0447\u0430\u0441\u0442\u043d\u0438\u043a\u043e\u0432",
        )
    ):
        return "system"
    if text.startswith("[default]") and "\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c \u043d\u0430 Majestic Role Play" in text:
        return "system"
    if text.startswith("[default]") or "\u0433\u043e\u0432\u043e\u0440\u0438\u0442:" in text:
        return "default"
    if re.match(r"^[A-Z][A-Za-z_'-]{1,24}\s+[A-Z][A-Za-z_'-]{1,24}\s*:\s*\(\(", text):
        return "default"
    player_match = PLAYER_NAME_RE.match(text)
    if player_match and _looks_like_player_name(player_match.group("name")) and _looks_like_player_action_tail(text[player_match.end() :]):
        return "me"
    if text.startswith("[me]"):
        return "me"
    if text.startswith("[admin]"):
        return "admin"
    return None


def _is_valid_rendered_chat_text(text: str, record_type: str) -> bool:
    if any(marker in text for marker in BAD_RECORD_MARKERS):
        return False
    if "{" in text or "}" in text:
        return False
    if '","' in text or '":"' in text:
        return False
    if record_type == "news" and "Weazel News" in text and ":" not in text:
        return False
    if record_type == "news" and text.startswith("\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:") and _phone_from_text(text) is None:
        return False
    if record_type == "me":
        owner = _rendered_owner(text)
        if owner.get("kind") != "player":
            return False
        name = str(owner.get("name") or "")
        if not name or not _looks_like_player_name(name):
            return False
        tail = text.split(name, 1)[1] if name in text else ""
        if not _looks_like_player_action_tail(tail):
            return False
    if record_type == "system" and len(text) < 80 and _chat_text_noise_score(text) >= 4:
        return False
    if (
        record_type == "system"
        and "\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c \u043d\u0430 Majestic Role Play" in text
        and text.rstrip().endswith(",")
    ):
        return False
    if record_type == "default" and "\u0433\u043e\u0432\u043e\u0440\u0438\u0442:" in text:
        speaker, message = text.split("\u0433\u043e\u0432\u043e\u0440\u0438\u0442:", 1)
        speaker = speaker.replace("[default]", "").strip()
        message = message.strip()
        if _static_id_from_speaker(speaker):
            return len(message) >= 1
        if len(speaker) < 3 or len(message) < 2:
            return False
        if any(ch in speaker for ch in "{}[]\""):
            return False
    return True


def _rendered_text_nodes(text: str) -> list[RenderedTextNode]:
    nodes: list[RenderedTextNode] = []
    current: list[str] = []
    current_start = 0

    def flush(end: int) -> None:
        nonlocal current
        if not current:
            return
        raw = "".join(current)
        start = current_start
        current = []
        chat_text = _clean_chat_text(raw)
        if len(chat_text) < 3:
            return
        if _is_bad_chat_text(chat_text, None):
            return
        nodes.append(RenderedTextNode(raw=raw, text=chat_text, start=start, end=end))

    for index, ch in enumerate(text):
        if _is_fragment_char(ch):
            if not current:
                current_start = index
            current.append(ch)
        else:
            flush(index)
    flush(len(text))
    return nodes


def _rendered_record_from_text(
    raw: str,
    chat_text: str,
    record_type: str,
    base_pos: int,
    encoding: str,
    source: str,
    process: str | None = None,
    pid: int | None = None,
) -> ChatRecord | None:
    if len(chat_text) < 6 or _is_bad_chat_text(chat_text, None):
        return None
    if not _is_valid_rendered_chat_text(chat_text, record_type):
        return None
    owner = _rendered_owner(chat_text)
    phone_number = _phone_from_text(chat_text)
    formatting = _formatting_from_raw(raw, record_type, chat_text)
    color = _primary_color(formatting)
    player_name = str(owner.get("name")) if owner.get("kind") == "player" and owner.get("name") else None
    player_id = str(owner.get("playerId")) if owner.get("playerId") else None
    static_id = str(owner.get("staticId")) if owner.get("staticId") else None
    stable_id = _stable_message_id(record_type, chat_text, None, phone_number, player_name, player_id, static_id, color)
    raw_fields: dict[str, Any] = {"rendered": True, "messageId_source": "stable_hash"}
    raw_fields.update({f"visible_{key}": value for key, value in owner.items()})
    return ChatRecord(
        type=record_type,
        text=chat_text,
        timestamp=None,
        time=None,
        phoneNumber=phone_number,
        id=None,
        source=source,
        encoding=encoding,
        pos=base_pos,
        process=process,
        pid=pid,
        messageId=stable_id,
        stableId=stable_id,
        playerId=player_id,
        staticId=static_id,
        playerName=player_name,
        color=color,
        formatting=formatting,
        owner=owner,
        raw_fields=raw_fields,
    )


def _is_news_continuation(text: str) -> bool:
    if text.startswith(("\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:", "\u041a\u0440\u0438\u0442\u0435\u0440\u0438\u0438:")):
        return True
    if _rendered_chat_type(text) is not None:
        return False
    return _russian_score(text) >= 4 and len(text) <= 260


def _is_phone_only_record(record: ChatRecord) -> bool:
    return (
        record.type == "news"
        and _phone_from_text(record.text) is not None
        and record.text.strip().startswith("\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:")
    )


def _drop_unattached_phone_records(records: list[ChatRecord]) -> list[ChatRecord]:
    return [record for record in records if not _is_phone_only_record(record)]


def _attach_phone_to_record(record: ChatRecord, phone_record: ChatRecord) -> ChatRecord:
    phone_number = phone_record.phoneNumber or _phone_from_text(phone_record.text)
    if not phone_number:
        return record
    text = record.text
    phone_text = f"\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440: {phone_number}"
    if phone_text not in text and phone_number not in text:
        text = f"{text.rstrip()} {phone_text}"
    raw_fields = dict(record.raw_fields)
    attached = list(raw_fields.get("attached_phone_records") or [])
    attached.append(
        {
            "phoneNumber": phone_number,
            "text": phone_record.text,
            "source": phone_record.source,
            "pos": phone_record.pos,
            "messageId": phone_record.messageId,
            "stableId": phone_record.stableId,
        }
    )
    raw_fields["attached_phone_records"] = attached
    raw_fields["phoneNumber_source"] = raw_fields.get("phoneNumber_source") or "rendered_continuation"
    stable_id = _stable_message_id(
        record.type,
        text,
        record.timestamp,
        phone_number,
        record.playerName,
        record.playerId,
        record.staticId,
        record.color,
    )
    message_id = record.messageId
    if raw_fields.get("messageId_source") != "memory":
        message_id = stable_id
    return replace(
        record,
        text=text,
        phoneNumber=phone_number,
        messageId=message_id,
        stableId=stable_id,
        raw_fields=raw_fields,
    )


def _attach_standalone_phone_records(records: list[ChatRecord], *, max_distance: int = 0x20000) -> list[ChatRecord]:
    ordered = sorted(records, key=lambda item: item.pos)
    out: list[ChatRecord] = []
    last_news_index: int | None = None
    last_news_pos: int | None = None
    for record in ordered:
        if _is_phone_only_record(record):
            if (
                last_news_index is not None
                and last_news_pos is not None
                and record.pos >= last_news_pos
                and record.pos - last_news_pos <= max_distance
            ):
                out[last_news_index] = _attach_phone_to_record(out[last_news_index], record)
                last_news_index = None
                last_news_pos = None
                continue
            out.append(record)
            continue
        out.append(record)
        if record.type == "news" and not record.phoneNumber:
            last_news_index = len(out) - 1
            last_news_pos = record.pos
        elif record.type not in {"news"}:
            last_news_index = None
            last_news_pos = None
    return out


def _extract_split_rendered_records(
    nodes: list[RenderedTextNode],
    base_addr: int,
    encoding: str,
    source: str,
    scale: int,
    process: str | None = None,
    pid: int | None = None,
) -> tuple[list[ChatRecord], set[int]]:
    records: list[ChatRecord] = []
    consumed: set[int] = set()
    for index, node in enumerate(nodes):
        if not node.text.startswith(("[Weazel News]", "Weazel News", "[ el News]")):
            continue
        raw_parts = [node.raw]
        text_parts = [node.text]
        node_starts = {node.start}
        last_end = node.end
        for tail in nodes[index + 1 : index + 12]:
            if tail.start - last_end > 4096:
                break
            if not _is_news_continuation(tail.text):
                break
            raw_parts.append(tail.raw)
            text_parts.append(tail.text)
            node_starts.add(tail.start)
            last_end = tail.end
            if _phone_from_text(tail.text):
                break
        if len(text_parts) <= 1:
            continue
        combined_raw = " ".join(raw_parts)
        combined_text = _clean_chat_text(" ".join(text_parts))
        record_type = _rendered_chat_type(combined_text) or "news"
        record = _rendered_record_from_text(
            combined_raw,
            combined_text,
            record_type,
            base_addr + node.start * scale,
            encoding,
            f"{source} rendered_split",
            process,
            pid,
        )
        if record is None:
            continue
        if record.phoneNumber and any(_phone_from_text(part) for part in text_parts[1:]):
            raw_fields = dict(record.raw_fields)
            raw_fields.setdefault("phoneNumber_source", "rendered_continuation")
            raw_fields.setdefault(
                "attached_phone_records",
                [
                    {
                        "phoneNumber": record.phoneNumber,
                        "source": source,
                        "pos": base_addr + node.start * scale,
                    }
                ],
            )
            record = replace(record, raw_fields=raw_fields)
        records.append(record)
        consumed.update(node_starts)
    return records, consumed


def _extract_rendered_records_from_text(
    text: str,
    base_addr: int,
    encoding: str,
    source: str,
    scale: int,
    process: str | None = None,
    pid: int | None = None,
) -> list[ChatRecord]:
    records: list[ChatRecord] = []
    nodes = _rendered_text_nodes(text)
    split_records, consumed_starts = _extract_split_rendered_records(nodes, base_addr, encoding, source, scale, process, pid)
    records.extend(split_records)
    for node in nodes:
        if node.start in consumed_starts:
            continue
        chat_text = node.text
        record_type = _rendered_chat_type(chat_text)
        if record_type is None:
            continue
        record = _rendered_record_from_text(
            node.raw,
            chat_text,
            record_type,
            base_addr + node.start * scale,
            encoding,
            f"{source} rendered",
            process,
            pid,
        )
        if record is not None:
            records.append(record)
    return _dedupe_records(_drop_unattached_phone_records(_attach_standalone_phone_records(records)))


def _record_visible_key(text: str) -> str:
    return re.sub(r"\s+", " ", text).strip()


def _record_text_match(rendered_text: str, candidate_text: str) -> bool:
    rendered = _record_visible_key(rendered_text)
    candidate = _record_visible_key(candidate_text)
    if not rendered or not candidate:
        return False
    if rendered == candidate:
        return True
    if len(rendered) < 24 or len(candidate) < 24:
        return False
    return candidate.startswith(rendered) or rendered.startswith(candidate)


def _is_rendered_record(record: ChatRecord) -> bool:
    return bool(record.raw_fields.get("rendered")) or str(record.source or "").endswith(" rendered")


def _record_enrichment_candidates(record: ChatRecord, candidates: list[ChatRecord]) -> list[ChatRecord]:
    matches: list[ChatRecord] = []
    for candidate in candidates:
        if candidate is record or candidate.type != record.type:
            continue
        if _record_text_match(record.text, candidate.text):
            matches.append(candidate)
    distinct: dict[tuple[Any, ...], ChatRecord] = {}
    for candidate in matches:
        key = (
            candidate.timestamp,
            candidate.id,
            candidate.messageId if candidate.raw_fields.get("messageId_source") == "memory" else None,
            candidate.playerId,
            candidate.staticId,
            candidate.playerName,
            candidate.phoneNumber,
        )
        distinct.setdefault(key, candidate)
    return list(distinct.values())


def _enrich_rendered_record(record: ChatRecord, candidate: ChatRecord) -> ChatRecord:
    raw_fields = dict(record.raw_fields)
    raw_fields.setdefault("matched_record", {})
    matched = dict(raw_fields["matched_record"])
    matched.update(
        {
            "source": candidate.source,
            "pos": candidate.pos,
            "id": candidate.id,
            "messageId": candidate.messageId,
            "timestamp": candidate.timestamp,
        }
    )
    raw_fields["matched_record"] = {key: value for key, value in matched.items() if value is not None}
    update: dict[str, Any] = {"raw_fields": raw_fields}
    if record.timestamp is None and candidate.timestamp is not None:
        update["timestamp"] = candidate.timestamp
        update["time"] = candidate.time or _timestamp_to_text(candidate.timestamp)
        raw_fields["timestamp_source"] = "matched_serialized_unique"
    if record.phoneNumber is None and candidate.phoneNumber is not None:
        update["phoneNumber"] = candidate.phoneNumber
        raw_fields["phoneNumber_source"] = raw_fields.get("phoneNumber_source") or "matched_serialized_unique"
    if record.playerId is None and candidate.playerId is not None:
        update["playerId"] = candidate.playerId
        raw_fields["playerId_source"] = "matched_serialized_unique"
    if record.staticId is None and candidate.staticId is not None:
        update["staticId"] = candidate.staticId
        raw_fields["staticId_source"] = "matched_serialized_unique"
    if record.playerName is None and candidate.playerName is not None:
        update["playerName"] = candidate.playerName
        raw_fields["playerName_source"] = "matched_serialized_unique"
    if not record.owner and candidate.owner:
        update["owner"] = candidate.owner
        raw_fields["owner_source"] = "matched_serialized_unique"
    elif record.owner and candidate.owner:
        owner = dict(candidate.owner)
        owner.update(record.owner)
        update["owner"] = owner
    return replace(record, **update)


def _enrich_rendered_records(records: list[ChatRecord]) -> list[ChatRecord]:
    candidates = [
        record
        for record in records
        if not _is_rendered_record(record)
        and (record.timestamp is not None or record.id or record.playerId or record.staticId or record.playerName)
    ]
    out: list[ChatRecord] = []
    for record in records:
        if not _is_rendered_record(record):
            out.append(record)
            continue
        matches = _record_enrichment_candidates(record, candidates)
        if len(matches) == 1:
            out.append(_enrich_rendered_record(record, matches[0]))
        else:
            out.append(record)
    return out


def _record_dedupe_key(record: ChatRecord) -> tuple[str, int | None, str]:
    if record.id:
        return ("id", None, f"{record.type}:{record.id}")
    if record.raw_fields.get("messageId_source") == "memory" and record.messageId:
        return ("messageId", None, f"{record.type}:{record.messageId}")
    if record.raw_fields.get("messageId_source") == "stable_hash" and record.messageId:
        return (
            "memory-near",
            None,
            (
                f"{record.type}:{record.process or ''}:{record.pid or ''}:"
                f"{record.source}:{record.timestamp or ''}:{record.pos // 16}:{record.messageId}"
            ),
        )
    return (
        "memory",
        None,
        (
            f"{record.type}:{record.process or ''}:{record.pid or ''}:"
            f"{record.pos}:{record.source}:{record.timestamp or ''}:{record.text[:160]}"
        ),
    )


def _merge_record_pair(current: ChatRecord, candidate: ChatRecord) -> ChatRecord:
    if _record_quality(candidate) > _record_quality(current):
        primary, secondary = candidate, current
    else:
        primary, secondary = current, candidate
    merged = primary
    if secondary.phoneNumber and not merged.phoneNumber:
        if secondary.type == "news":
            merged = _attach_phone_to_record(merged, secondary)
        else:
            merged = replace(merged, phoneNumber=secondary.phoneNumber)
    raw_fields = dict(secondary.raw_fields)
    raw_fields.update(merged.raw_fields)
    owner = dict(secondary.owner)
    owner.update(merged.owner)
    update: dict[str, Any] = {"raw_fields": raw_fields, "owner": owner}
    for field_name in ("timestamp", "time", "id", "messageId", "playerId", "staticId", "playerName", "color"):
        if getattr(merged, field_name) is None and getattr(secondary, field_name) is not None:
            update[field_name] = getattr(secondary, field_name)
    if merged.formatting:
        update["formatting"] = merged.formatting
    elif secondary.formatting:
        update["formatting"] = secondary.formatting
    if update.get("staticId") and not update.get("playerId"):
        update["playerId"] = None
    return replace(merged, **update)


def _sort_records(records: list[ChatRecord]) -> list[ChatRecord]:
    return sorted(
        records,
        key=lambda item: (
            0 if item.timestamp is not None else 1,
            item.timestamp or 0,
            str(item.process or ""),
            int(item.pid or 0),
            item.pos,
            item.type,
            item.text,
        ),
    )


def _assign_record_order(records: list[ChatRecord]) -> list[ChatRecord]:
    ordered = _sort_records(records)
    out: list[ChatRecord] = []
    for index, record in enumerate(ordered, 1):
        source = "timestamp" if record.timestamp is not None else "memory_position"
        out.append(replace(record, order=index, orderSource=source))
    return out


def _dedupe_records(records: list[ChatRecord]) -> list[ChatRecord]:
    best: dict[tuple[str, int | None, str], ChatRecord] = {}
    for record in _drop_unattached_phone_records(records):
        key = _record_dedupe_key(record)
        current = best.get(key)
        if current is None:
            best[key] = record
        else:
            best[key] = _merge_record_pair(current, record)
    return _assign_record_order(_enrich_rendered_records(list(best.values())))


def _record_channel(record: ChatRecord | dict[str, Any]) -> str | None:
    record_type = record.type if isinstance(record, ChatRecord) else str(record.get("type") or "")
    text = record.text if isinstance(record, ChatRecord) else str(record.get("text") or "")
    if record_type == "family" or text.startswith("[fam]"):
        return "family"
    if record_type == "fraction" or text.startswith("[frac]"):
        return "fraction"
    if text.startswith("[gov]") or text.startswith("[ el News]"):
        return "gov"
    if record_type == "default" or text.startswith("[default]") or "\u0433\u043e\u0432\u043e\u0440\u0438\u0442:" in text:
        return "default"
    if record_type == "system" or text.startswith("[global]"):
        return "system"
    if record_type:
        return record_type
    return None


def _infer_active_tab_from_records(records: list[ChatRecord] | list[dict[str, Any]]) -> dict[str, Any] | None:
    channels = {channel for record in records if (channel := _record_channel(record))}
    if not channels:
        return None
    if len(channels) > 1:
        tab_id = "all"
    elif "family" in channels:
        tab_id = "fam"
    elif "fraction" in channels:
        tab_id = "frac"
    elif "gov" in channels:
        tab_id = "gov"
    else:
        tab_id = "all"
    return {
        "id": tab_id,
        "name": _tab_name_from_id(tab_id),
        "source": "memory.records",
        "confidence": "inferred",
        "channels": sorted(channels),
    }


def _dedupe_fragments(fragments: list[TextFragment]) -> list[TextFragment]:
    out: list[TextFragment] = []
    seen: set[str] = set()
    for fragment in sorted(fragments, key=lambda item: (-len(item.text), item.addr)):
        key = fragment.text
        if key in seen:
            continue
        if any(key in existing or existing in key for existing in seen):
            continue
        seen.add(key)
        out.append(fragment)
    return sorted(out, key=lambda item: item.addr)


def _record_dict_key(record: dict) -> tuple[str, int | None, str]:
    record_type = str(record.get("type") or "")
    record_id = record.get("id")
    if record_id:
        return ("id", None, f"{record_type}:{record_id}")
    raw_fields = record.get("raw_fields") if isinstance(record.get("raw_fields"), dict) else {}
    message_id = record.get("messageId")
    if raw_fields.get("messageId_source") == "memory" and message_id:
        return ("messageId", None, f"{record_type}:{message_id}")
    timestamp = record.get("timestamp")
    if not isinstance(timestamp, int):
        timestamp = None
    if raw_fields.get("messageId_source") == "stable_hash" and message_id:
        pos = record.get("pos")
        if not isinstance(pos, int):
            pos = 0
        return (
            "memory-near",
            None,
            (
                f"{record_type}:{record.get('process') or ''}:{record.get('pid') or ''}:"
                f"{record.get('source') or ''}:{timestamp or ''}:{pos // 16}:{message_id}"
            ),
        )
    return (
        "memory",
        None,
        (
            f"{record_type}:{record.get('process') or ''}:{record.get('pid') or ''}:"
            f"{record.get('pos') or 0}:{record.get('source') or ''}:{timestamp or ''}:"
            f"{str(record.get('text') or '')[:160]}"
        ),
    )


def _is_phone_only_record_dict(record: dict) -> bool:
    text = str(record.get("text") or "").strip()
    record_type = str(record.get("type") or "")
    return (
        record_type == "news"
        and text.startswith("\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:")
        and _phone_from_text(text) is not None
    )


def _normalize_record_dict(record: dict) -> dict:
    normalized = dict(record)
    record_type = str(normalized.get("type") or "")
    text = str(normalized.get("text") or "")
    raw_fields = dict(normalized.get("raw_fields") or {})
    if text and (raw_fields.get("rendered") or str(normalized.get("source") or "").endswith(" rendered")):
        owner = _rendered_owner(text)
        if owner:
            existing_owner = dict(normalized.get("owner") or {})
            existing_owner.update(owner)
            normalized["owner"] = existing_owner
            raw_fields.update({f"visible_{key}": value for key, value in owner.items()})
            if owner.get("kind") == "player" and owner.get("name") and not normalized.get("playerName"):
                normalized["playerName"] = str(owner["name"])
            if owner.get("playerId") and not normalized.get("playerId"):
                normalized["playerId"] = str(owner["playerId"])
            if owner.get("staticId") and not normalized.get("staticId"):
                normalized["staticId"] = str(owner["staticId"])
    if raw_fields:
        normalized["raw_fields"] = raw_fields
    phone_number = normalized.get("phoneNumber")
    if record_type == "news" and phone_number:
        phone_text = f"\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440: {phone_number}"
        if not text.strip().startswith("\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440:") and phone_text not in text and str(phone_number) not in text:
            normalized["text"] = f"{text.rstrip()} {phone_text}".strip()
            raw_fields = dict(normalized.get("raw_fields") or {})
            raw_fields.setdefault("phoneNumber_source", "record")
            normalized["raw_fields"] = raw_fields
    return normalized


def _is_rendered_record_dict(record: dict) -> bool:
    raw_fields = record.get("raw_fields") if isinstance(record.get("raw_fields"), dict) else {}
    return bool(raw_fields.get("rendered")) or str(record.get("source") or "").endswith(" rendered")


def _record_dict_enrichment_candidates(record: dict, candidates: list[dict]) -> list[dict]:
    matches: list[dict] = []
    record_type = str(record.get("type") or "")
    text = str(record.get("text") or "")
    for candidate in candidates:
        if str(candidate.get("type") or "") != record_type:
            continue
        if _record_text_match(text, str(candidate.get("text") or "")):
            matches.append(candidate)
    distinct: dict[tuple[Any, ...], dict] = {}
    for candidate in matches:
        raw_fields = candidate.get("raw_fields") if isinstance(candidate.get("raw_fields"), dict) else {}
        key = (
            candidate.get("timestamp") if isinstance(candidate.get("timestamp"), int) else None,
            candidate.get("id"),
            candidate.get("messageId") if raw_fields.get("messageId_source") == "memory" else None,
            candidate.get("playerId"),
            candidate.get("staticId"),
            candidate.get("playerName"),
            candidate.get("phoneNumber"),
        )
        distinct.setdefault(key, candidate)
    return list(distinct.values())


def _enrich_rendered_record_dict(record: dict, candidate: dict) -> dict:
    enriched = dict(record)
    raw_fields = dict(enriched.get("raw_fields") or {})
    matched = dict(raw_fields.get("matched_record") or {})
    matched.update(
        {
            "source": candidate.get("source"),
            "pos": candidate.get("pos"),
            "id": candidate.get("id"),
            "messageId": candidate.get("messageId"),
            "timestamp": candidate.get("timestamp"),
        }
    )
    raw_fields["matched_record"] = {key: value for key, value in matched.items() if value is not None}
    timestamp = candidate.get("timestamp")
    if not isinstance(enriched.get("timestamp"), int) and isinstance(timestamp, int):
        enriched["timestamp"] = timestamp
        enriched["time"] = candidate.get("time") or _timestamp_to_text(timestamp)
        raw_fields["timestamp_source"] = "matched_serialized_unique"
    for key, source_name in (
        ("phoneNumber", "phoneNumber_source"),
        ("playerId", "playerId_source"),
        ("staticId", "staticId_source"),
        ("playerName", "playerName_source"),
    ):
        if not enriched.get(key) and candidate.get(key):
            enriched[key] = candidate[key]
            raw_fields[source_name] = "matched_serialized_unique"
    if not enriched.get("owner") and candidate.get("owner"):
        enriched["owner"] = candidate["owner"]
        raw_fields["owner_source"] = "matched_serialized_unique"
    elif isinstance(enriched.get("owner"), dict) and isinstance(candidate.get("owner"), dict):
        owner = dict(candidate["owner"])
        owner.update(enriched["owner"])
        enriched["owner"] = owner
    enriched["raw_fields"] = raw_fields
    return enriched


def _enrich_rendered_record_dicts(records: list[dict]) -> list[dict]:
    candidates = [
        record
        for record in records
        if not _is_rendered_record_dict(record)
        and (
            isinstance(record.get("timestamp"), int)
            or record.get("id")
            or record.get("playerId")
            or record.get("staticId")
            or record.get("playerName")
        )
    ]
    out: list[dict] = []
    for record in records:
        if not _is_rendered_record_dict(record):
            out.append(record)
            continue
        matches = _record_dict_enrichment_candidates(record, candidates)
        out.append(_enrich_rendered_record_dict(record, matches[0]) if len(matches) == 1 else record)
    return out


def _record_dict_sort_key(record: dict) -> tuple[int, int, str, str]:
    timestamp = record.get("timestamp")
    if not isinstance(timestamp, int):
        timestamp = 0
    return (0 if timestamp else 1, timestamp, str(record.get("type") or ""), str(record.get("text") or ""))


def _prefer_richer_record(current: dict, candidate: dict) -> dict:
    current_quality = _record_quality(current)
    candidate_quality = _record_quality(candidate)
    if candidate_quality > current_quality:
        return candidate
    if current_quality > candidate_quality:
        return current
    richness_keys = (
        "time",
        "phoneNumber",
        "id",
        "messageId",
        "stableId",
        "playerId",
        "staticId",
        "playerName",
        "color",
        "formatting",
        "owner",
        "raw_fields",
        "process",
        "pid",
        "source",
        "encoding",
    )
    current_score = sum(1 for key in richness_keys if current.get(key))
    candidate_score = sum(1 for key in richness_keys if candidate.get(key))
    if candidate_score > current_score:
        return candidate
    if len(str(candidate.get("text") or "")) > len(str(current.get("text") or "")):
        return candidate
    return current


def _merge_record_dict_pair(current: dict, candidate: dict) -> dict:
    primary = _prefer_richer_record(current, candidate)
    secondary = current if primary is candidate else candidate
    merged = dict(primary)
    if not merged.get("phoneNumber") and secondary.get("phoneNumber"):
        phone_number = str(secondary.get("phoneNumber"))
        merged["phoneNumber"] = phone_number
        phone_text = f"\u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440: {phone_number}"
        if phone_text not in str(merged.get("text") or "") and phone_number not in str(merged.get("text") or ""):
            merged["text"] = f"{str(merged.get('text') or '').rstrip()} {phone_text}".strip()
    for key in (
        "timestamp",
        "time",
        "id",
        "messageId",
        "stableId",
        "playerId",
        "staticId",
        "playerName",
        "color",
        "process",
        "pid",
        "source",
        "encoding",
    ):
        if not merged.get(key) and secondary.get(key):
            merged[key] = secondary[key]
    for key in ("formatting", "owner", "raw_fields"):
        if isinstance(secondary.get(key), dict) or isinstance(merged.get(key), dict):
            value = dict(secondary.get(key) or {})
            value.update(dict(merged.get(key) or {}))
            merged[key] = value
    return merged


def _dedupe_record_dicts(records: list[dict]) -> list[dict]:
    best: dict[tuple[str, int | None, str], dict] = {}
    normalized_records: list[dict] = []
    for record in records:
        if _is_phone_only_record_dict(record):
            continue
        normalized_records.append(_normalize_record_dict(record))
    for record in _enrich_rendered_record_dicts(normalized_records):
        key = _record_dict_key(record)
        best[key] = _merge_record_dict_pair(best[key], record) if key in best else record
    out = sorted(best.values(), key=_record_dict_sort_key)
    for index, record in enumerate(out, 1):
        record["order"] = index
        record["orderSource"] = "timestamp" if isinstance(record.get("timestamp"), int) else "memory_position"
    return out


def _merge_fragment_dicts(fragments: list[dict], limit: int) -> list[dict]:
    if limit <= 0:
        return []
    out: list[dict] = []
    seen: set[str] = set()
    for fragment in sorted(fragments, key=lambda item: (-len(str(item.get("text") or "")), int(item.get("addr") or 0))):
        text = str(fragment.get("text") or "").strip()
        if len(text) < 8:
            continue
        source = str(fragment.get("source") or "")
        valid = _is_chat_input_fragment(text, 4) if "chat_input" in source else _is_chat_fragment(text, 8)
        if not valid:
            continue
        if text in seen:
            continue
        if any(text in existing or existing in text for existing in seen):
            continue
        seen.add(text)
        out.append(fragment)
        if len(out) >= limit:
            break
    return sorted(out, key=lambda item: int(item.get("addr") or 0))


def _process_keys_from_report(report: dict) -> set[tuple[str, int]]:
    keys: set[tuple[str, int]] = set()
    for section in ("selected_processes", "processes"):
        for item in report.get(section, []) if isinstance(report.get(section), list) else []:
            if not isinstance(item, dict):
                continue
            process = item.get("process")
            pid = item.get("pid")
            if process and isinstance(pid, int):
                keys.add((str(process), pid))
    process = report.get("process")
    pid = report.get("pid")
    if process and isinstance(pid, int):
        keys.add((str(process), pid))
    return keys


def _record_belongs_to_processes(record: dict, process_keys: set[tuple[str, int]]) -> bool:
    if not process_keys:
        return True
    process = record.get("process")
    pid = record.get("pid")
    if not process or not isinstance(pid, int):
        return False
    return (str(process), pid) in process_keys


def _merge_history_data(existing: dict | None, incoming: dict, fragment_limit: int) -> dict:
    existing = existing or {}
    record_candidates: list[dict] = []
    incoming_process_keys = _process_keys_from_report(incoming)
    existing_records = [
        record
        for record in existing.get("records", [])
        if isinstance(record, dict) and _record_belongs_to_processes(record, incoming_process_keys)
    ]
    for record in [*existing_records, *incoming.get("records", [])]:
        if not isinstance(record, dict) or not str(record.get("text") or "").strip():
            continue
        timestamp = record.get("timestamp") if isinstance(record.get("timestamp"), int) else None
        if _is_bad_chat_text(str(record.get("text") or ""), timestamp):
            continue
        record_candidates.append(record)

    fragments: list[dict] = []
    for fragment in [*existing.get("fragments", []), *incoming.get("fragments", [])]:
        if isinstance(fragment, dict):
            fragments.append(fragment)

    snapshots = [item for item in existing.get("snapshots", []) if isinstance(item, dict)]
    snapshots.append(
        {
            "created_at": incoming.get("created_at"),
            "pid": incoming.get("pid"),
            "selected_processes": incoming.get("selected_processes", []),
            "chat_state": incoming.get("chat_state"),
            "chat_input_active": incoming.get("chat_input_active"),
            "active_tab": incoming.get("active_tab"),
            "tabs": incoming.get("tabs"),
            "records": len(incoming.get("records", [])),
            "fragments": len(incoming.get("fragments", [])),
            "marker_hit_count": incoming.get("marker_hit_count"),
            "windows": incoming.get("windows"),
        }
    )

    merged_records = _dedupe_record_dicts(record_candidates)
    chat_state = incoming.get("chat_state") if isinstance(incoming.get("chat_state"), dict) else existing.get("chat_state")
    if not isinstance(chat_state, dict):
        chat_state = _empty_chat_state()
    chat_input_active = incoming.get("chat_input_active")
    if not isinstance(chat_input_active, bool):
        chat_input_active = chat_state.get("chat_input_active")
    if not isinstance(chat_input_active, bool):
        chat_input_active = existing.get("chat_input_active")
    active_tab = incoming.get("active_tab") or existing.get("active_tab")
    if not isinstance(active_tab, dict) or active_tab.get("confidence") == "unknown":
        inferred_tab = _infer_active_tab_from_records(merged_records)
        if inferred_tab is not None:
            if isinstance(active_tab, dict):
                inferred_tab["memory_probe"] = active_tab
            active_tab = inferred_tab

    return {
        "kind": "sonar_chat_history_latest",
        "created_at": existing.get("created_at") or incoming.get("created_at") or time.time(),
        "updated_at": time.time(),
        "process": incoming.get("process") or existing.get("process"),
        "pid": incoming.get("pid"),
        "memory_dump": incoming.get("memory_dump") or existing.get("memory_dump"),
        "selected_processes": incoming.get("selected_processes") or existing.get("selected_processes", []),
        "chat_state": chat_state,
        "chat_input_active": chat_input_active,
        "active_tab": active_tab,
        "tabs": _known_chat_tabs(active_tab if isinstance(active_tab, dict) else None, merged_records),
        "process_discovery": incoming.get("process_discovery") or existing.get("process_discovery"),
        "records": merged_records,
        "fragments": _merge_fragment_dicts(fragments, fragment_limit),
        "snapshots": snapshots[-200:],
    }


def _format_history_text(report: dict, title: str, fragment_limit: int) -> str:
    records = [item for item in report.get("records", []) if isinstance(item, dict)]
    fragments = [item for item in report.get("fragments", []) if isinstance(item, dict)]
    txt_lines = [
        title,
        f"process={report.get('process')} pid={report.get('pid')}",
        f"chat_input_active={report.get('chat_input_active')}",
        f"active_tab={(report.get('active_tab') or {}).get('name') or (report.get('active_tab') or {}).get('id') or 'unknown'}",
        f"records={len(records)} fragments={min(len(fragments), fragment_limit)}",
        "",
        "Records:",
    ]
    for record in records:
        prefix = record.get("time") or str(record.get("timestamp") or "")
        meta = f"{prefix} [{record.get('type')}]"
        if record.get("phoneNumber"):
            meta += f" phone={record.get('phoneNumber')}"
        if record.get("id"):
            meta += f" id={record.get('id')}"
        if record.get("messageId"):
            meta += f" messageId={record.get('messageId')}"
        if record.get("stableId") and record.get("stableId") != record.get("messageId"):
            meta += f" stableId={record.get('stableId')}"
        if record.get("playerId"):
            meta += f" playerId={record.get('playerId')}"
        if record.get("staticId"):
            meta += f" staticId={record.get('staticId')}"
        if record.get("playerName"):
            meta += f" playerName={record.get('playerName')}"
        if record.get("color"):
            meta += f" color={record.get('color')}"
        txt_lines.append(meta)
        txt_lines.append(str(record.get("text") or ""))
        txt_lines.append("")
    if not records:
        txt_lines.append("No parsed chat records found.")
        txt_lines.append("")
    txt_lines.append("Fragments:")
    for fragment in fragments[:fragment_limit]:
        addr = int(fragment.get("addr") or 0)
        txt_lines.append(f"0x{addr:X} {fragment.get('encoding')} {fragment.get('source')}")
        txt_lines.append(str(fragment.get("text") or ""))
        txt_lines.append("")
    return "\n".join(txt_lines)


def update_latest_history(json_path: Path, out_dir: Path, latest_name: str, fragment_limit: int) -> Path:
    latest_json = out_dir / f"{latest_name}.json"
    latest_txt = out_dir / f"{latest_name}.txt"
    incoming = json.loads(json_path.read_text(encoding="utf-8"))
    existing: dict | None = None
    if not incoming.get("memory_dump") and latest_json.exists():
        try:
            existing = json.loads(latest_json.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            existing = None
    merged = _merge_history_data(existing, incoming, fragment_limit)
    latest_json.write_text(json.dumps(merged, ensure_ascii=False, indent=2), encoding="utf-8")
    latest_txt.write_text(_format_history_text(merged, "Sonar chat history latest", fragment_limit), encoding="utf-8-sig")
    return latest_json


def _decode_texts(data: bytes) -> list[tuple[str, str, int]]:
    return [
        ("utf-8", data.decode("utf-8", errors="ignore"), 1),
        ("utf-16-le", data.decode("utf-16-le", errors="ignore"), 2),
        ("utf-16-le+1", data[1:].decode("utf-16-le", errors="ignore"), 2),
    ]


def _tab_name_from_id(tab_id: str | None) -> str | None:
    if tab_id is None:
        return None
    value = str(tab_id).strip().lower()
    return {
        "0": "Все",
        "all": "Все",
        "default": "Все",
        "1": "Семья",
        "fam": "Семья",
        "family": "Семья",
        "2": "Фракция",
        "frac": "Фракция",
        "fraction": "Фракция",
        "3": "Департамент",
        "dep": "Департамент",
        "gov": "Департамент",
        "4": "Репорт",
        "report": "Репорт",
    }.get(value)


def _canonical_tab_id(tab_id: str | None) -> str | None:
    if tab_id is None:
        return None
    value = str(tab_id).strip().lower()
    return {
        "0": "all",
        "default": "all",
        "all": "all",
        "1": "fam",
        "family": "fam",
        "fam": "fam",
        "2": "frac",
        "fraction": "frac",
        "frac": "frac",
        "3": "gov",
        "dep": "gov",
        "gov": "gov",
        "4": "report",
        "report": "report",
    }.get(value, value or None)


def _available_tab_ids_from_records(
    records: list[ChatRecord] | list[dict[str, Any]] | None,
    active_tab: dict[str, Any] | None,
) -> set[str] | None:
    if records is None:
        return None
    available = {"all"}
    if isinstance(active_tab, dict) and active_tab.get("id"):
        active_id = _canonical_tab_id(str(active_tab.get("id")))
        if active_id:
            available.add(active_id)
    for record in records:
        record_type = record.type if isinstance(record, ChatRecord) else str(record.get("type") or "")
        text = record.text if isinstance(record, ChatRecord) else str(record.get("text") or "")
        if record_type == "family" or text.startswith("[fam]"):
            available.add("fam")
        elif record_type == "fraction" or text.startswith("[frac]"):
            available.add("frac")
        elif record_type == "report" or text.startswith("[report]"):
            available.add("report")
        elif record_type == "gov":
            available.add("gov")
    return available


def _known_chat_tabs(
    active_tab: dict[str, Any] | None,
    records: list[ChatRecord] | list[dict[str, Any]] | None = None,
) -> list[dict[str, Any]]:
    active_id = _canonical_tab_id(str(active_tab.get("id"))) if isinstance(active_tab, dict) and active_tab.get("id") else None
    available_ids = _available_tab_ids_from_records(records, active_tab)
    tabs = []
    for tab_id in ("all", "fam", "frac", "gov", "report"):
        tab = {
            "id": tab_id,
            "name": _tab_name_from_id(tab_id),
            "active": active_id == tab_id,
            "source": "known_chat_tabs",
        }
        if available_ids is not None:
            tab["available"] = tab_id in available_ids
            tab["availabilitySource"] = "memory.records.inferred"
        tabs.append(tab)
    return tabs


def _active_tab_from_value(key: str, value: Any, source: str, addr: int, raw: str) -> dict[str, Any] | None:
    if value is None:
        return None
    if isinstance(value, bool):
        return None
    tab_id = str(value).strip()
    if not tab_id:
        return None
    return {
        "id": tab_id,
        "name": _tab_name_from_id(tab_id),
        "source": source,
        "addr": f"0x{addr:X}",
        "field": key,
        "confidence": "medium",
        "raw": raw[:500],
    }


def _state_confidence_rank(confidence: str | None) -> int:
    return {
        "disabled": -1,
        "unknown": 0,
        "low": 1,
        "inferred": 1,
        "medium": 2,
        "high": 3,
    }.get(str(confidence or "unknown"), 0)


def _state_bool_from_value(value: str) -> bool | None:
    normalized = value.strip().strip('"').strip().lower()
    if normalized in {"true", "1", "yes", "on"}:
        return True
    if normalized in {"false", "0", "no", "off"}:
        return False
    return None


def _empty_chat_state(source: str = "memory", confidence: str = "unknown", marker_hit_count: int | None = None) -> dict[str, Any]:
    state: dict[str, Any] = {
        "chat_input_active": None,
        "chat_visible": None,
        "active_tab": None,
        "source": source,
        "confidence": confidence,
    }
    if marker_hit_count is not None:
        state["marker_hit_count"] = marker_hit_count
    return state


def _clean_state_raw(value: str | None, limit: int = 700) -> str | None:
    if value is None:
        return None
    cleaned = re.sub(r"[\x00-\x08\x0B\x0C\x0E-\x1F]+", " ", str(value))
    cleaned = re.sub(r"\s+", " ", cleaned).strip()
    return cleaned[:limit] if cleaned else None


def _extract_active_tab_from_text(text: str, base_addr: int = 0, encoding: str = "utf-8", source: str = "", scale: int = 1) -> dict[str, Any] | None:
    for key in ("activeFilter", "activeTab", "selectedTab", "currentTab"):
        object_match = re.search(rf'"{re.escape(key)}"\s*:\s*\{{(?P<body>.{{0,500}}?)\}}', text, re.DOTALL)
        if object_match:
            fields = _json_field_map("{" + object_match.group("body") + "}")
            tab_id = _first_field(fields, ("id", "key", "value", "type", "name"))
            result = _active_tab_from_value(key, tab_id, source, base_addr + object_match.start() * scale, object_match.group(0))
            if result is not None:
                if fields.get("name"):
                    result["name"] = str(fields["name"])
                result["confidence"] = "high"
                return result
        for pattern in (
            rf'"{re.escape(key)}"\s*:\s*"(?P<value>[^"]{{1,40}})"',
            rf'"{re.escape(key)}"\s*:\s*(?P<value>-?\d{{1,4}})',
            rf'\b{re.escape(key)}\b\s*[=:]\s*"(?P<value>[^"]{{1,40}})"',
            rf'\b{re.escape(key)}\b\s*[=:]\s*(?P<value>-?\d{{1,4}})',
        ):
            match = re.search(pattern, text)
            if not match:
                continue
            result = _active_tab_from_value(key, match.group("value"), source, base_addr + match.start() * scale, match.group(0))
            if result is not None:
                result["encoding"] = encoding
                return result
    return None


def _chat_state_from_serialized_fields(
    text: str,
    base_addr: int,
    encoding: str,
    source: str,
    scale: int,
) -> dict[str, Any] | None:
    fields: dict[str, bool] = {}
    first_match: re.Match[str] | None = None
    for key in ("chatIsActive", "chatIsShow", "inputStatus"):
        pattern = (
            rf'(?:"{re.escape(key)}"|\b{re.escape(key)}\b)\s*[:=]\s*'
            r'(?P<value>true|false|0|1|"true"|"false"|"0"|"1")'
        )
        match = re.search(pattern, text, re.IGNORECASE)
        if not match:
            continue
        parsed = _state_bool_from_value(match.group("value"))
        if parsed is None:
            continue
        fields[key] = parsed
        first_match = first_match or match
    if not fields:
        return None

    assert first_match is not None
    raw_start = max(0, first_match.start() - 120)
    raw_end = min(len(text), first_match.end() + 380)
    state = {
        "chat_input_active": fields.get("inputStatus", fields.get("chatIsActive")),
        "chat_visible": fields.get("chatIsShow"),
        "source": source,
        "addr": f"0x{base_addr + first_match.start() * scale:X}",
        "encoding": encoding,
        "confidence": "high",
        "raw": _clean_state_raw(text[raw_start:raw_end], 500),
        "raw_fields": {key: value for key, value in fields.items()},
    }
    return state


def _chat_state_from_dom_selectors(
    text: str,
    base_addr: int,
    encoding: str,
    source: str,
    scale: int,
) -> dict[str, Any] | None:
    disabled_matches = list(re.finditer(r"\bdiv\.chat\.disabled\b|\bdiv\.chat-container\s*>\s*div\.chat\.disabled\b", text))
    enabled_matches = list(
        re.finditer(
            r"\bdiv\.main-cover\.full-width\.full-height\s*>\s*div\.chat-container\s*>\s*div\.chat(?![A-Za-z0-9_.-])"
            r"|\bdiv\.chat-container\s*>\s*div\.chat(?![A-Za-z0-9_.-])",
            text,
        )
    )
    with_command_matches = list(re.finditer(r"\blabel\.chat-input\.withCommand\b", text))
    input_click_matches = [
        match
        for match in re.finditer(r"\bui\.click\b", text)
        if "chatInput" in text[max(0, match.start() - 500) : match.end() + 700]
        or "label.chat-input" in text[max(0, match.start() - 500) : match.end() + 700]
    ]

    if not disabled_matches and not enabled_matches and not with_command_matches and not input_click_matches:
        return None

    if disabled_matches and not enabled_matches and not with_command_matches:
        active = False
        match = disabled_matches[0]
        confidence = "medium"
        reason = "dom_disabled_selector"
    else:
        active = True
        match = (with_command_matches or input_click_matches or enabled_matches or disabled_matches)[0]
        confidence = "medium" if enabled_matches or with_command_matches else "low"
        reason = "dom_enabled_selector"
        if with_command_matches:
            reason = "dom_input_with_command"
        elif input_click_matches:
            reason = "dom_input_click"

    raw_start = max(0, match.start() - 220)
    raw_end = min(len(text), match.end() + 520)
    return {
        "chat_input_active": active,
        "chat_visible": True,
        "source": source,
        "addr": f"0x{base_addr + match.start() * scale:X}",
        "encoding": encoding,
        "confidence": confidence,
        "raw": _clean_state_raw(text[raw_start:raw_end], 700),
        "raw_fields": {
            "input_state_source": reason,
            "dom_disabled_selectors": len(disabled_matches),
            "dom_enabled_selectors": len(enabled_matches),
            "dom_with_command_selectors": len(with_command_matches),
            "dom_input_clicks": len(input_click_matches),
        },
    }


def _extract_chat_state_from_text(
    text: str,
    base_addr: int = 0,
    encoding: str = "utf-8",
    source: str = "",
    scale: int = 1,
) -> dict[str, Any] | None:
    candidates = [
        item
        for item in (
            _chat_state_from_serialized_fields(text, base_addr, encoding, source, scale),
            _chat_state_from_dom_selectors(text, base_addr, encoding, source, scale),
        )
        if item is not None
    ]
    active_tab = _extract_active_tab_from_text(text, base_addr, encoding, source, scale)
    if active_tab is not None:
        candidates.append(
            {
                "chat_input_active": None,
                "chat_visible": None,
                "active_tab": active_tab,
                "source": active_tab.get("source") or source,
                "addr": active_tab.get("addr"),
                "encoding": active_tab.get("encoding") or encoding,
                "confidence": active_tab.get("confidence") or "medium",
                "raw": active_tab.get("raw"),
                "raw_fields": {"active_tab_source": active_tab.get("field")},
            }
        )
    if not candidates:
        return None
    return _merge_chat_state_candidates(candidates)


def _merge_chat_state_candidates(candidates: list[dict[str, Any]]) -> dict[str, Any]:
    out = _empty_chat_state()
    raw_fields: dict[str, Any] = {}
    best_confidence = "unknown"

    for field in ("chat_input_active", "chat_visible"):
        field_candidates = [item for item in candidates if isinstance(item.get(field), bool)]
        if not field_candidates:
            continue
        field_candidates.sort(
            key=lambda item: (
                _state_confidence_rank(str(item.get("confidence") or "unknown")),
                int((item.get("raw_fields") or {}).get("dom_enabled_selectors") or 0)
                + int((item.get("raw_fields") or {}).get("dom_with_command_selectors") or 0),
            ),
            reverse=True,
        )
        selected = field_candidates[0]
        out[field] = selected[field]
        out[f"{field}_confidence"] = selected.get("confidence")
        out[f"{field}_source"] = selected.get("source")
        if selected.get("addr"):
            out[f"{field}_addr"] = selected.get("addr")
        best_confidence = max(
            best_confidence,
            str(selected.get("confidence") or "unknown"),
            key=_state_confidence_rank,
        )
        if isinstance(selected.get("raw_fields"), dict):
            raw_fields.update(selected["raw_fields"])

    tab_candidates = [item["active_tab"] for item in candidates if isinstance(item.get("active_tab"), dict)]
    if tab_candidates:
        tab_candidates.sort(key=lambda item: _state_confidence_rank(str(item.get("confidence") or "unknown")), reverse=True)
        out["active_tab"] = tab_candidates[0]
        best_confidence = max(
            best_confidence,
            str(tab_candidates[0].get("confidence") or "unknown"),
            key=_state_confidence_rank,
        )

    selected_source = next((item.get("source") for item in candidates if item.get("source")), "memory")
    selected_addr = next((item.get("addr") for item in candidates if item.get("addr")), None)
    selected_encoding = next((item.get("encoding") for item in candidates if item.get("encoding")), None)
    selected_raw = next((item.get("raw") for item in candidates if item.get("raw")), None)
    out.update(
        {
            "source": selected_source,
            "confidence": best_confidence,
        }
    )
    if selected_addr:
        out["addr"] = selected_addr
    if selected_encoding:
        out["encoding"] = selected_encoding
    if selected_raw:
        cleaned_raw = _clean_state_raw(str(selected_raw), 700)
        if cleaned_raw:
            out["raw"] = cleaned_raw
    if raw_fields:
        out["raw_fields"] = raw_fields
    return out


def _scan_chat_state(
    tracker,
    args: argparse.Namespace,
    process_name: str,
    pid: int,
    regions: list[tuple[int, int]],
) -> dict[str, Any]:
    if getattr(args, "no_active_tab", False):
        return _empty_chat_state("disabled", "disabled")
    markers = _encoded_markers(CHAT_STATE_MARKERS)
    marker_hits: list[int] = []
    chunk_size = max(4096, args.chunk_mb * 1024 * 1024)
    overlap = max(len(marker) for marker in markers) - 1
    max_total_bytes = args.active_tab_max_total_mb * 1024 * 1024
    scanned = 0
    for start, end in regions:
        if len(marker_hits) >= args.active_tab_marker_hits:
            break
        size = end - start
        if args.active_tab_max_total_mb > 0 and scanned + size > max_total_bytes:
            end = start + max(0, max_total_bytes - scanned)
            size = end - start
        if size <= 0:
            break
        hits = _scan_marker_offsets(
            tracker._read,
            start,
            end,
            markers,
            chunk_size=chunk_size,
            overlap=overlap,
            limit=args.active_tab_marker_hits - len(marker_hits),
        )
        marker_hits.extend(hits)
        scanned += size

    half_window = 8192
    candidates: list[dict[str, Any]] = []
    for hit in marker_hits:
        for region_start, region_end in regions:
            if not (region_start <= hit < region_end):
                continue
            start = max(region_start, hit - half_window)
            end = min(region_end, hit + half_window)
            data = tracker._read(start, end - start)
            if not data:
                break
            source = f"{process_name}:{pid} chat_state 0x{start:X}-0x{end:X}"
            for encoding, text, scale in _decode_texts(data):
                base = start if encoding != "utf-16-le+1" else start + 1
                candidate = _extract_chat_state_from_text(text, base, encoding, source, scale)
                if candidate is not None:
                    candidates.append(candidate)
            break
    if candidates:
        state = _merge_chat_state_candidates(candidates)
        state["marker_hit_count"] = len(marker_hits)
        return state
    return _empty_chat_state("memory", "unknown", len(marker_hits))


def _scan_active_tab(
    tracker,
    args: argparse.Namespace,
    process_name: str,
    pid: int,
    regions: list[tuple[int, int]],
) -> dict[str, Any]:
    state = _scan_chat_state(tracker, args, process_name, pid, regions)
    active_tab = state.get("active_tab")
    if isinstance(active_tab, dict):
        return active_tab
    return {
        "id": None,
        "name": None,
        "source": state.get("source") or "memory",
        "confidence": state.get("confidence") if state.get("confidence") == "disabled" else "unknown",
        "marker_hit_count": state.get("marker_hit_count", 0),
    }


def _scan_tracker_history(
    args: argparse.Namespace,
    process_name: str,
    pid: int | None,
    dump_root: Path | None = None,
    dump_process: dict[str, Any] | None = None,
) -> dict:
    tracker = DumpMemoryTracker(dump_root, dump_process) if dump_root is not None and dump_process is not None else _open_tracker(process_name, pid)
    started = time.perf_counter()
    try:
        regions = _collect_search_regions(tracker, args.max_region_mb, args.max_total_mb)
        markers = _marker_bytes()
        marker_hits: list[int] = []
        raw_windows: list[tuple[int, int]] = []
        chunk_size = max(4096, args.chunk_mb * 1024 * 1024)
        overlap = max(len(marker) for marker in markers) - 1
        half_window = max(4096, args.window_kb * 1024 // 2)
        anchor_addrs: list[int] = []
        for value in args.address or []:
            anchor_addrs.append(_parse_addr(value))
        if args.anchor_report:
            report_path = _latest_search_report(Path(args.out_dir or DEFAULT_OUT_DIR)) if args.anchor_report == "latest" else Path(args.anchor_report)
            if report_path is None:
                print("anchor report not found")
            else:
                report_addrs = _anchor_addrs_from_report(report_path)
                anchor_addrs.extend(report_addrs)
                print(f"anchor_report={report_path} anchor_hits={len(report_addrs)}")
        for addr in anchor_addrs:
            for region_start, region_end in regions:
                if region_start <= addr < region_end:
                    raw_windows.append((max(region_start, addr - half_window), min(region_end, addr + half_window)))
                    break
        for index, (start, end) in enumerate(regions, 1):
            if len(marker_hits) >= args.marker_hits:
                break
            hits = _scan_marker_offsets(
                tracker._read,
                start,
                end,
                markers,
                chunk_size=chunk_size,
                overlap=overlap,
                limit=args.marker_hits - len(marker_hits),
            )
            marker_hits.extend(hits)
            raw_windows.extend((max(start, hit - half_window), min(end, hit + half_window)) for hit in hits)
            if args.progress and index % args.progress == 0:
                print(
                    f"{process_name} pid={tracker.pid} "
                    f"scanned_regions={index}/{len(regions)} marker_hits={len(marker_hits)}"
                )

        windows = _merge_windows(raw_windows)
        records: list[ChatRecord] = []
        fragments: list[TextFragment] = []
        for start, end in windows:
            data = tracker._read(start, end - start)
            if not data:
                continue
            if not _has_chat_context(data):
                continue
            source = f"{process_name}:{tracker.pid} 0x{start:X}-0x{end:X}"
            for encoding, text, scale in _decode_texts(data):
                base = start if encoding != "utf-16-le+1" else start + 1
                records.extend(_extract_records_from_text(text, base, encoding, source, scale, process_name, tracker.pid))
                records.extend(_extract_rendered_records_from_text(text, base, encoding, source, scale, process_name, tracker.pid))
            fragments.extend(_extract_wide_fragments(data, start, source, args.min_fragment_chars, process_name, tracker.pid))
            fragments.extend(_extract_chat_input_fragments(data, start, source, args.min_fragment_chars, process_name, tracker.pid))

        chat_state = _scan_chat_state(tracker, args, process_name, tracker.pid, regions)
        active_tab = chat_state.get("active_tab")
        if not isinstance(active_tab, dict):
            active_tab = {
                "id": None,
                "name": None,
                "source": chat_state.get("source") or "memory",
                "confidence": chat_state.get("confidence") if chat_state.get("confidence") == "disabled" else "unknown",
                "marker_hit_count": chat_state.get("marker_hit_count", 0),
            }
        return {
            "process": process_name,
            "pid": tracker.pid,
            "regions": len(regions),
            "orphan_tail_bytes": tracker.info.get("orphan_tail_bytes") if hasattr(tracker, "info") else None,
            "marker_hit_count": len(marker_hits),
            "windows": len(windows),
            "elapsed_seconds": time.perf_counter() - started,
            "chat_state": chat_state,
            "active_tab": active_tab,
            "records": _dedupe_records(records),
            "fragments": _dedupe_fragments(fragments),
        }
    finally:
        tracker.stop()


def _select_chat_state(states: list[dict[str, Any]]) -> dict[str, Any]:
    candidates = [item for item in states if isinstance(item, dict) and item.get("confidence") != "disabled"]
    if not candidates:
        return _empty_chat_state("memory", "unknown")
    meaningful = [
        item
        for item in candidates
        if isinstance(item.get("chat_input_active"), bool)
        or isinstance(item.get("chat_visible"), bool)
        or isinstance(item.get("active_tab"), dict)
    ]
    if meaningful:
        return _merge_chat_state_candidates(meaningful)
    fallback = candidates[0]
    return _empty_chat_state(
        str(fallback.get("source") or "memory"),
        str(fallback.get("confidence") or "unknown"),
        fallback.get("marker_hit_count") if isinstance(fallback.get("marker_hit_count"), int) else None,
    )


def dump_history(args: argparse.Namespace) -> Path:
    started = time.perf_counter()
    process_reports: list[dict] = []
    records: list[ChatRecord] = []
    fragments: list[TextFragment] = []
    out_dir = Path(args.out_dir or DEFAULT_OUT_DIR)
    out_dir.mkdir(parents=True, exist_ok=True)
    memory_dump = _load_memory_dump(args.memory_dump)
    dump_root: Path | None = None
    dump_targets: list[dict[str, Any]] | None = None
    if memory_dump is not None:
        dump_root, dump_manifest = memory_dump
        dump_targets, process_discovery = _resolve_memory_dump_targets(args, dump_root, dump_manifest)
        targets = [(str(item.get("process") or "dump"), int(item.get("pid") or 0)) for item in dump_targets]
    else:
        targets, process_discovery = _resolve_process_targets(args, out_dir)
    if not targets:
        if _is_auto_process(args.process):
            raise RuntimeError(
                "No CEF chat renderer with chat markers was found. Open the game chat, "
                "or pass --allow-gta-fallback/--process GTA5.exe for the slower fallback scan."
            )
        raise RuntimeError(f"Process not found: {args.process}")

    for index, (process_name, pid) in enumerate(targets):
        dump_process = dump_targets[index] if dump_targets is not None else None
        process_report = _scan_tracker_history(args, process_name, pid, dump_root, dump_process)
        process_reports.append(
            {
                key: value
                for key, value in process_report.items()
                if key not in {"records", "fragments"}
            }
        )
        records.extend(process_report["records"])
        fragments.extend(process_report["fragments"])

    records = _dedupe_records(records)
    fragments = _dedupe_fragments(fragments)
    elapsed = time.perf_counter() - started

    stamp = time.strftime("%Y%m%d_%H%M%S")
    json_path = out_dir / f"chat_history_dump_{stamp}.json"
    txt_path = out_dir / f"chat_history_dump_{stamp}.txt"
    selected_states = [item.get("chat_state") for item in process_reports if isinstance(item.get("chat_state"), dict)]
    chat_state = _select_chat_state(selected_states)
    selected_tabs = [item.get("active_tab") for item in process_reports if isinstance(item.get("active_tab"), dict)]
    state_tab = chat_state.get("active_tab")
    if isinstance(state_tab, dict):
        selected_tabs.insert(0, state_tab)
    active_tab = next((item for item in selected_tabs if item.get("confidence") != "unknown"), None)
    active_tab = active_tab or (selected_tabs[0] if selected_tabs else {"id": None, "name": None, "source": "memory", "confidence": "unknown"})
    if active_tab.get("confidence") == "unknown":
        inferred_tab = _infer_active_tab_from_records(records)
        if inferred_tab is not None:
            inferred_tab["memory_probe"] = active_tab
            active_tab = inferred_tab
    selected_processes = process_discovery.get("selected", [])
    selected_pid = selected_processes[0].get("pid") if len(selected_processes) == 1 and isinstance(selected_processes[0], dict) else None
    report = {
        "kind": "sonar_chat_history_dump",
        "created_at": time.time(),
        "process": args.process,
        "pid": selected_pid,
        "memory_dump": str(dump_root) if dump_root is not None else None,
        "process_discovery": process_discovery,
        "selected_processes": selected_processes,
        "chat_state": chat_state,
        "chat_input_active": chat_state.get("chat_input_active"),
        "active_tab": active_tab,
        "tabs": _known_chat_tabs(active_tab, records),
        "processes": process_reports,
        "regions": sum(int(item["regions"]) for item in process_reports),
        "marker_hit_count": sum(int(item["marker_hit_count"]) for item in process_reports),
        "windows": sum(int(item["windows"]) for item in process_reports),
        "elapsed_seconds": elapsed,
        "records": [asdict(record) for record in records],
        "fragments": [asdict(fragment) for fragment in fragments[: args.fragment_limit]],
    }
    json_path.write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
    txt_lines = [
        "Sonar chat history dump",
        f"process={args.process} processes={len(process_reports)}",
        f"chat_input_active={chat_state.get('chat_input_active')}",
        f"active_tab={active_tab.get('name') or active_tab.get('id') or 'unknown'} confidence={active_tab.get('confidence')}",
        f"records={len(records)} fragments={min(len(fragments), args.fragment_limit)} markers={report['marker_hit_count']} windows={report['windows']} elapsed={elapsed:.2f}s",
        "",
        "Records:",
    ]
    for record in records:
        prefix = record.time or str(record.timestamp or "")
        meta = f"{prefix} [{record.type}]"
        if record.phoneNumber:
            meta += f" phone={record.phoneNumber}"
        if record.id:
            meta += f" id={record.id}"
        if record.messageId:
            meta += f" messageId={record.messageId}"
        if record.stableId and record.stableId != record.messageId:
            meta += f" stableId={record.stableId}"
        if record.playerId:
            meta += f" playerId={record.playerId}"
        if record.staticId:
            meta += f" staticId={record.staticId}"
        if record.playerName:
            meta += f" playerName={record.playerName}"
        if record.color:
            meta += f" color={record.color}"
        txt_lines.append(meta)
        txt_lines.append(record.text)
        txt_lines.append("")
    if not records:
        txt_lines.append("No parsed chat records found.")
        txt_lines.append("")
    txt_lines.append("Fragments:")
    for fragment in fragments[: args.fragment_limit]:
        txt_lines.append(f"0x{fragment.addr:X} {fragment.encoding} {fragment.source}")
        txt_lines.append(fragment.text)
        txt_lines.append("")
    txt_path.write_text("\n".join(txt_lines), encoding="utf-8-sig")

    print(f"Chat history: records={len(records)} fragments={min(len(fragments), args.fragment_limit)}")
    selected = report.get("selected_processes") or []
    if selected:
        summary = ", ".join(
            f"{item.get('process')} pid={item.get('pid')} score={item.get('score')}"
            for item in selected[:5]
            if isinstance(item, dict)
        )
        print(f"Chat processes: {summary}")
    print(f"Chat input active: {chat_state.get('chat_input_active')}")
    print(f"Active tab: {active_tab.get('name') or active_tab.get('id') or 'unknown'} ({active_tab.get('confidence')})")
    for record in records[: args.print_records]:
        print(f"{record.time or record.timestamp} [{record.type}] {record.text[: args.print_chars]}")
    print(f"Saved JSON: {json_path}")
    print(f"Saved TXT: {txt_path}")
    return json_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Dump parsed chat history records from GTA process memory.")
    parser.add_argument("--process", default="auto")
    parser.add_argument("--memory-dump", default=None, help="Path to a saved process memory dump directory or manifest.json.")
    parser.add_argument("--max-region-mb", type=int, default=512)
    parser.add_argument("--max-total-mb", type=int, default=0, help="0 scans all selected regions.")
    parser.add_argument("--chunk-mb", type=int, default=8)
    parser.add_argument("--window-kb", type=int, default=32)
    parser.add_argument("--marker-hits", type=int, default=10000)
    parser.add_argument("--max-chat-processes", type=int, default=3, help="How many auto-discovered chat processes to scan.")
    parser.add_argument("--auto-max-total-mb", type=int, default=1024, help="Memory budget for auto PID discovery. 0 scans all selected regions.")
    parser.add_argument("--auto-marker-hits", type=int, default=64, help="Stop PID discovery after this many chat marker hits per process.")
    parser.add_argument("--no-process-cache", action="store_true", help="Do not reuse the last validated chat process PID.")
    parser.add_argument("--allow-gta-fallback", action="store_true", help="Compatibility flag; GTA5.exe is included in auto discovery unless --cef-only is passed.")
    parser.add_argument("--cef-only", action="store_true", help="Only scan majestic-webengine.exe renderers during auto discovery.")
    parser.add_argument("--active-tab-max-total-mb", type=int, default=512, help="Memory budget for active chat tab probing. 0 scans all selected regions.")
    parser.add_argument("--active-tab-marker-hits", type=int, default=256)
    parser.add_argument("--no-active-tab", action="store_true", help="Skip active chat tab probing.")
    parser.add_argument("--min-fragment-chars", type=int, default=8)
    parser.add_argument("--fragment-limit", type=int, default=0, help="Raw debug fragments to include. Use 0 for records-only output.")
    parser.add_argument("--print-records", type=int, default=20)
    parser.add_argument("--print-chars", type=int, default=260)
    parser.add_argument("--progress", type=int, default=250)
    parser.add_argument("--anchor-report", default=None, help='Path to a chat_memory_search JSON report, or "latest".')
    parser.add_argument("--address", action="append", help="Additional hex address to dump around. Can be passed more than once.")
    parser.add_argument("--out-dir", default=None)
    parser.add_argument("--latest-name", default="chat_history_latest", help="Base name for the cumulative JSON/TXT files.")
    parser.add_argument("--no-latest", action="store_true", help="Do not merge this dump into the cumulative latest files.")
    parser.add_argument("--watch", action="store_true", help="Keep collecting chat history until interrupted.")
    parser.add_argument("--watch-interval", type=float, default=5.0, help="Seconds between memory snapshots in --watch mode.")
    return parser


def run(args: argparse.Namespace) -> None:
    while True:
        json_path = dump_history(args)
        if not args.no_latest:
            latest_path = update_latest_history(
                json_path,
                Path(args.out_dir or DEFAULT_OUT_DIR),
                args.latest_name,
                args.fragment_limit,
            )
            print(f"Updated latest: {latest_path}")
        if not args.watch:
            return
        time.sleep(max(1.0, args.watch_interval))


def main() -> int:
    try:
        run(build_parser().parse_args())
        return 0
    except KeyboardInterrupt:
        print("Stopped chat history collector.")
        return 130
    except RuntimeError as exc:
        print(f"Chat history collector failed: {exc}")
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
