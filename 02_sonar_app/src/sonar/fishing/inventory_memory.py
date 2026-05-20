from __future__ import annotations

import ctypes
import json
import re
from dataclasses import dataclass
from pathlib import Path

import psutil

from sonar.fishing.memory_reeling import PROCESS_ALL_READ
from sonar.paths import LOG_DIR


MIN_VOTE_CANDIDATES = 6
MIN_VOTE_CONFIDENCE = 0.85
MAX_CANDIDATES = 80


@dataclass(frozen=True, slots=True)
class InventoryMemoryCandidate:
    addr: int
    closed_value: int
    open_value: int
    weight: float = 1.0


class InventoryMemoryDetector:
    _candidate_re = re.compile(r"addr=0x([0-9A-Fa-f]+)\s+byte\s+closed=(\d+)\s+open=(\d+)")

    def __init__(self, process_name: str = "gta5.exe", report_dir: Path | None = None) -> None:
        self.process_name = process_name
        self.report_dir = report_dir or LOG_DIR / "memory_snapshots"
        self._report_path: Path | None = None
        self._report_mtime = 0.0
        self._candidates: list[InventoryMemoryCandidate] = []
        self._pid: int | None = None
        self._process_started_at = 0.0
        self._handle: int | None = None

    def close(self) -> None:
        if self._handle:
            ctypes.windll.kernel32.CloseHandle(self._handle)
        self._handle = None
        self._pid = None
        self._process_started_at = 0.0

    def is_open(self) -> bool | None:
        if not self._load_candidates():
            return None
        if not self._ensure_handle():
            return None
        open_votes = 0.0
        closed_votes = 0.0
        matched = 0
        for candidate in self._candidates:
            value = self._read_byte(candidate.addr)
            if value is None:
                continue
            if value == candidate.open_value:
                open_votes += candidate.weight
                matched += 1
            elif value == candidate.closed_value:
                closed_votes += candidate.weight
                matched += 1
        total_weight = open_votes + closed_votes
        if matched < MIN_VOTE_CANDIDATES or total_weight <= 0.0:
            return None
        confidence = max(open_votes, closed_votes) / total_weight
        if confidence < MIN_VOTE_CONFIDENCE:
            return None
        return open_votes > closed_votes

    def _load_candidates(self) -> bool:
        report = self._latest_report()
        if report is None:
            self._candidates = []
            self._report_path = None
            self._report_mtime = 0.0
            return False
        mtime = report.stat().st_mtime
        if self._report_path == report and self._report_mtime == mtime:
            return bool(self._candidates)
        if report.suffix.lower() == ".json":
            candidates = self._load_profile_candidates(report)
            self._report_path = report
            self._report_mtime = mtime
            self._candidates = candidates[:MAX_CANDIDATES]
            return bool(self._candidates)
        candidates: list[InventoryMemoryCandidate] = []
        for line in report.read_text(encoding="utf-8", errors="ignore").splitlines():
            match = self._candidate_re.search(line)
            if not match:
                continue
            candidates.append(
                InventoryMemoryCandidate(
                    addr=int(match.group(1), 16),
                    closed_value=int(match.group(2)),
                    open_value=int(match.group(3)),
                )
            )
            if len(candidates) >= MAX_CANDIDATES:
                break
        self._report_path = report
        self._report_mtime = mtime
        self._candidates = candidates
        return bool(self._candidates)

    def _load_profile_candidates(self, path: Path) -> list[InventoryMemoryCandidate]:
        try:
            profile = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            return []
        out: list[InventoryMemoryCandidate] = []
        for item in profile.get("candidates", []):
            try:
                addr_raw = item["addr"]
                addr = int(addr_raw, 16) if isinstance(addr_raw, str) else int(addr_raw)
                out.append(
                    InventoryMemoryCandidate(
                        addr=addr,
                        closed_value=int(item["closed_value"]),
                        open_value=int(item["open_value"]),
                        weight=float(item.get("weight", item.get("accuracy", 1.0))),
                    )
                )
            except (KeyError, TypeError, ValueError):
                continue
        return out

    def _latest_report(self) -> Path | None:
        profiles = sorted(self.report_dir.glob("inventory_memory_profile_*.json"), key=lambda path: path.stat().st_mtime, reverse=True)
        if profiles:
            return profiles[0]
        reports = sorted(self.report_dir.glob("inventory_memory_probe_*.txt"), key=lambda path: path.stat().st_mtime, reverse=True)
        return reports[0] if reports else None

    def _ensure_handle(self) -> bool:
        proc = self._get_process()
        if proc is None:
            self.close()
            return False
        if self._report_mtime and self._report_mtime < proc.create_time():
            self.close()
            return False
        if self._handle and self._pid == proc.pid:
            return True
        self.close()
        handle = ctypes.windll.kernel32.OpenProcess(PROCESS_ALL_READ, False, proc.pid)
        if not handle:
            return False
        self._handle = handle
        self._pid = proc.pid
        self._process_started_at = proc.create_time()
        return True

    def _get_process(self) -> psutil.Process | None:
        wanted = self.process_name.lower()
        for proc in psutil.process_iter(["name"]):
            try:
                if (proc.info.get("name") or "").lower() == wanted:
                    return proc
            except (psutil.NoSuchProcess, psutil.AccessDenied):
                continue
        return None

    def _read_byte(self, addr: int) -> int | None:
        if not self._handle:
            return None
        buffer = ctypes.create_string_buffer(1)
        nread = ctypes.c_size_t()
        ok = ctypes.windll.kernel32.ReadProcessMemory(self._handle, ctypes.c_void_p(addr), buffer, 1, ctypes.byref(nread))
        if not ok or nread.value != 1:
            return None
        return buffer.raw[0]
