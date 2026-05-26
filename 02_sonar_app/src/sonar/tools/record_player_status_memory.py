from __future__ import annotations

import argparse
import ctypes
import json
import struct
import time
from dataclasses import asdict, dataclass, field
from datetime import datetime
from pathlib import Path
from ctypes import wintypes
from typing import Any

import cv2
import psutil

from sonar.fishing.memory_reeling import MEM_COMMIT, PAGE_GUARD, PAGE_NOACCESS, PROCESS_ALL_READ
from sonar.fishing.player_status import PlayerStatus, PlayerStatusDetector
from sonar.paths import PROJECT_DIR
from sonar.vision.capture import WindowCapture


READABLE_PROTECT_MASK = 0x02 | 0x04 | 0x08 | 0x20 | 0x40 | 0x80
DEFAULT_TARGET_PROCESSES = ("gta5.exe", "majestic-webengine.exe")
DEFAULT_MARKERS = (
    b"inventory_updateIndicators",
    b"inventory/updateIndicators",
    b"main_setPlayerStats",
    b"client.stats.update",
    b"storedHeal",
    b"get_hp",
    b"test_hp",
    b"hunger",
    b"hungry",
    b"thirst",
    b"thirsty",
    b"satiety",
    b"inventory/indicators/v2/health.svg",
    b"inventory/indicators/v2/water.svg",
    b"inventory/indicators/v2/hunger.svg",
    b"weight__text-current",
    b"active fill",
    b"fill-border",
)


class MEMORY_BASIC_INFORMATION(ctypes.Structure):
    _fields_ = [
        ("BaseAddress", ctypes.c_void_p),
        ("AllocationBase", ctypes.c_void_p),
        ("AllocationProtect", wintypes.DWORD),
        ("RegionSize", ctypes.c_size_t),
        ("State", wintypes.DWORD),
        ("Protect", wintypes.DWORD),
        ("Type", wintypes.DWORD),
    ]


@dataclass(slots=True)
class MemoryWindow:
    start: int
    end: int
    reasons: list[str] = field(default_factory=list)


@dataclass(slots=True)
class DumpedRegion:
    start: str
    size: int
    file_offset: int
    dumped_size: int
    reasons: list[str]


@dataclass(slots=True)
class ProcessDump:
    process: str
    pid: int
    regions_file: str
    regions: list[DumpedRegion]
    dumped_bytes: int


@dataclass(slots=True)
class StatusSnapshot:
    index: int
    created_at: str
    status: dict[str, Any]
    previous_status: dict[str, Any] | None
    screenshot: str
    process_dumps: list[ProcessDump]


def _status_key(status: PlayerStatus) -> tuple[int | None, int | None, int | None]:
    return status.food, status.water, status.health


def _status_dict(status: PlayerStatus | None) -> dict[str, Any] | None:
    if status is None:
        return None
    return asdict(status)


def _open_process(pid: int) -> int | None:
    handle = ctypes.windll.kernel32.OpenProcess(PROCESS_ALL_READ, False, pid)
    return int(handle) if handle else None


def _close_handle(handle: int) -> None:
    ctypes.windll.kernel32.CloseHandle(handle)


def _read_memory(handle: int, addr: int, size: int) -> bytes | None:
    if size <= 0:
        return None
    buffer = ctypes.create_string_buffer(size)
    nread = ctypes.c_size_t()
    ok = ctypes.windll.kernel32.ReadProcessMemory(
        handle,
        ctypes.c_void_p(addr),
        buffer,
        size,
        ctypes.byref(nread),
    )
    if not ok or nread.value <= 0:
        return None
    return buffer.raw[: nread.value]


def _readable_regions(handle: int) -> list[tuple[int, int]]:
    kernel32 = ctypes.windll.kernel32
    mbi = MEMORY_BASIC_INFORMATION()
    mbi_size = ctypes.sizeof(MEMORY_BASIC_INFORMATION)
    regions: list[tuple[int, int]] = []
    addr = 0
    while kernel32.VirtualQueryEx(handle, ctypes.c_void_p(addr), ctypes.byref(mbi), mbi_size):
        base = int(mbi.BaseAddress or 0)
        size = int(mbi.RegionSize)
        if (
            size > 0
            and mbi.State == MEM_COMMIT
            and not (mbi.Protect & PAGE_GUARD)
            and not (mbi.Protect & PAGE_NOACCESS)
            and bool(mbi.Protect & READABLE_PROTECT_MASK)
        ):
            regions.append((base, base + size))
        next_addr = base + size
        if next_addr <= addr:
            break
        addr = next_addr
    return regions


def _iter_target_processes(names: list[str], max_per_name: int) -> list[psutil.Process]:
    wanted = {name.lower() for name in names}
    grouped: dict[str, list[psutil.Process]] = {name: [] for name in wanted}
    for process in psutil.process_iter(["name", "memory_info"]):
        try:
            name = (process.info.get("name") or "").lower()
            if name in wanted:
                grouped[name].append(process)
        except (psutil.AccessDenied, psutil.NoSuchProcess):
            continue
    out: list[psutil.Process] = []
    for name in sorted(grouped):
        processes = grouped[name]
        processes.sort(key=lambda item: getattr(item.info.get("memory_info"), "rss", 0), reverse=True)
        out.extend(processes[:max_per_name])
    return out


def _numeric_patterns(status: PlayerStatus, previous: PlayerStatus | None) -> dict[bytes, str]:
    values: set[int] = set()
    for item in (status, previous):
        if item is None:
            continue
        for value in (item.food, item.water, item.health):
            if value is not None and 0 <= value <= 100:
                values.add(int(value))

    patterns: dict[bytes, str] = {}
    for value in sorted(values):
        text = str(value).encode("ascii")
        patterns[text] = f"ascii:{value}"
        patterns[text + b"%"] = f"ascii_percent:{value}"
        if value == 0:
            continue
        patterns[struct.pack("<B", value)] = f"u8:{value}"
        patterns[struct.pack("<I", value)] = f"u32:{value}"
        patterns[struct.pack("<i", value)] = f"i32:{value}"
        patterns[struct.pack("<I", value << 1)] = f"v8_smi32:{value}"
        patterns[struct.pack("<f", float(value))] = f"f32:{value}"
        patterns[struct.pack("<d", float(value))] = f"f64:{value}"
    return patterns


def _add_window(
    windows: list[MemoryWindow],
    region_start: int,
    region_end: int,
    hit_addr: int,
    radius: int,
    reason: str,
) -> None:
    start = max(region_start, hit_addr - radius)
    end = min(region_end, hit_addr + radius)
    if end <= start:
        return
    windows.append(MemoryWindow(start, end, [reason]))


def _find_pattern_windows(
    handle: int,
    regions: list[tuple[int, int]],
    patterns: dict[bytes, str],
    *,
    radius: int,
    chunk_size: int,
    max_hits_per_pattern: int,
) -> list[MemoryWindow]:
    windows: list[MemoryWindow] = []
    if not patterns:
        return windows
    hit_counts = {pattern: 0 for pattern in patterns}
    max_pattern_len = max(len(pattern) for pattern in patterns)
    for region_start, region_end in regions:
        offset = region_start
        carry = b""
        while offset < region_end:
            read_size = min(chunk_size, region_end - offset)
            chunk = _read_memory(handle, offset, read_size)
            if chunk:
                data = carry + chunk
                base_adjust = offset - len(carry)
                for pattern, reason in patterns.items():
                    if hit_counts[pattern] >= max_hits_per_pattern:
                        continue
                    search_from = 0
                    while hit_counts[pattern] < max_hits_per_pattern:
                        index = data.find(pattern, search_from)
                        if index < 0:
                            break
                        hit_addr = base_adjust + index
                        if hit_addr >= region_start:
                            _add_window(windows, region_start, region_end, hit_addr, radius, reason)
                            hit_counts[pattern] += 1
                        search_from = index + 1
                carry = data[-max_pattern_len:]
            offset += read_size
    return windows


def _marker_windows(
    handle: int,
    regions: list[tuple[int, int]],
    markers: tuple[bytes, ...],
    *,
    radius: int,
    chunk_size: int,
    max_hits_per_marker: int,
) -> list[MemoryWindow]:
    return _find_pattern_windows(
        handle,
        regions,
        {marker: f"marker:{marker.decode('ascii', errors='replace')}" for marker in markers},
        radius=radius,
        chunk_size=chunk_size,
        max_hits_per_pattern=max_hits_per_marker,
    )


def _selected_full_windows(
    regions: list[tuple[int, int]],
    *,
    max_total_mb: int,
    max_region_mb: int,
) -> list[MemoryWindow]:
    limit = max_total_mb * 1024 * 1024
    max_region = max_region_mb * 1024 * 1024
    selected: list[MemoryWindow] = []
    total = 0
    for start, end in sorted(regions, key=lambda item: item[1] - item[0]):
        size = end - start
        if size <= 0 or size > max_region or total + size > limit:
            continue
        selected.append(MemoryWindow(start, end, ["full_selected_region"]))
        total += size
    return selected


def _merge_windows(windows: list[MemoryWindow]) -> list[MemoryWindow]:
    if not windows:
        return []
    windows.sort(key=lambda item: (item.start, item.end))
    merged: list[MemoryWindow] = []
    for window in windows:
        if not merged or window.start > merged[-1].end:
            merged.append(MemoryWindow(window.start, window.end, list(dict.fromkeys(window.reasons))))
            continue
        current = merged[-1]
        current.end = max(current.end, window.end)
        current.reasons = list(dict.fromkeys([*current.reasons, *window.reasons]))
    return merged


def _dump_process(
    process: psutil.Process,
    snapshot_dir: Path,
    status: PlayerStatus,
    previous: PlayerStatus | None,
    args: argparse.Namespace,
) -> ProcessDump | None:
    handle = _open_process(process.pid)
    if handle is None:
        return None
    try:
        regions = _readable_regions(handle)
        windows = _marker_windows(
            handle,
            regions,
            DEFAULT_MARKERS,
            radius=args.marker_window_kb * 1024,
            chunk_size=args.chunk_mb * 1024 * 1024,
            max_hits_per_marker=args.max_marker_hits,
        )
        windows.extend(
            _find_pattern_windows(
                handle,
                regions,
                _numeric_patterns(status, previous),
                radius=args.numeric_window_kb * 1024,
                chunk_size=args.chunk_mb * 1024 * 1024,
                max_hits_per_pattern=args.max_numeric_hits,
            )
        )
        if args.full_selected_mb > 0:
            windows.extend(
                _selected_full_windows(
                    regions,
                    max_total_mb=args.full_selected_mb,
                    max_region_mb=args.full_selected_region_mb,
                )
            )
        windows = _merge_windows(windows)
        process_dir = snapshot_dir / f"{_safe_name(process.name())}_{process.pid}"
        process_dir.mkdir(parents=True, exist_ok=True)
        regions_path = process_dir / "memory_regions.bin"
        manifest_regions: list[DumpedRegion] = []
        offset = 0
        with regions_path.open("wb") as file:
            for window in windows:
                data = _read_memory(handle, window.start, window.end - window.start)
                if not data:
                    continue
                file.write(data)
                manifest_regions.append(
                    DumpedRegion(
                        start=f"0x{window.start:X}",
                        size=window.end - window.start,
                        file_offset=offset,
                        dumped_size=len(data),
                        reasons=window.reasons,
                    )
                )
                offset += len(data)
        manifest_path = process_dir / "regions.json"
        manifest_path.write_text(
            json.dumps([asdict(item) for item in manifest_regions], ensure_ascii=False, indent=2),
            encoding="utf-8",
        )
        return ProcessDump(
            process=process.name(),
            pid=process.pid,
            regions_file=str(regions_path.relative_to(snapshot_dir)),
            regions=manifest_regions,
            dumped_bytes=offset,
        )
    finally:
        _close_handle(handle)


def _safe_name(value: str) -> str:
    return "".join(ch if ch.isalnum() or ch in "._-" else "_" for ch in value)


def _write_snapshot(
    root: Path,
    index: int,
    frame,
    status: PlayerStatus,
    previous: PlayerStatus | None,
    args: argparse.Namespace,
) -> StatusSnapshot:
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S_%f")[:-3]
    status_part = f"food_{status.food}_water_{status.water}_hp_{status.health}"
    snapshot_dir = root / f"{index:04d}_{stamp}_{status_part}"
    snapshot_dir.mkdir(parents=True, exist_ok=False)
    screenshot_path = snapshot_dir / "screenshot.png"
    cv2.imwrite(str(screenshot_path), frame)

    process_dumps: list[ProcessDump] = []
    for process in _iter_target_processes(args.target_process, args.max_processes_per_name):
        try:
            dump = _dump_process(process, snapshot_dir, status, previous, args)
        except (psutil.AccessDenied, psutil.NoSuchProcess, OSError) as exc:
            print(f"Process dump failed: {process.pid} {process.name()} {exc}")
            continue
        if dump is not None:
            process_dumps.append(dump)

    snapshot = StatusSnapshot(
        index=index,
        created_at=datetime.now().isoformat(timespec="milliseconds"),
        status=_status_dict(status) or {},
        previous_status=_status_dict(previous),
        screenshot=str(screenshot_path.relative_to(root)),
        process_dumps=process_dumps,
    )
    (snapshot_dir / "status.json").write_text(json.dumps(asdict(snapshot), ensure_ascii=False, indent=2), encoding="utf-8")
    return snapshot


def _write_root_manifest(root: Path, snapshots: list[StatusSnapshot], args: argparse.Namespace) -> None:
    payload = {
        "kind": "sonar_player_status_memory_changes",
        "created_at": datetime.now().isoformat(timespec="milliseconds"),
        "root": str(root),
        "args": vars(args),
        "snapshots": [asdict(snapshot) for snapshot in snapshots],
    }
    (root / "manifest.json").write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")


def record(args: argparse.Namespace) -> Path:
    if args.target_process is None:
        args.target_process = list(DEFAULT_TARGET_PROCESSES)
    out_dir = Path(args.out_dir or PROJECT_DIR / "logs" / "memory_snapshots")
    root = out_dir / f"player_status_changes_{datetime.now().strftime('%Y%m%d_%H%M%S')}"
    root.mkdir(parents=True, exist_ok=False)
    capture = WindowCapture(args.capture_process)
    detector = PlayerStatusDetector()
    snapshots: list[StatusSnapshot] = []
    last_status: PlayerStatus | None = None

    print(f"Output: {root}")
    if args.watch_changes:
        _record_on_changes(root, capture, detector, snapshots, last_status, args)
    else:
        _record_interactive(root, capture, detector, snapshots, last_status, args)
    _write_root_manifest(root, snapshots, args)
    print(f"Snapshots: {len(snapshots)}")
    return root


def _detect_current_status(capture: WindowCapture, detector: PlayerStatusDetector) -> tuple[Any, PlayerStatus | None]:
    frame = capture.capture()
    return frame, detector.detect(frame)


def _save_current_snapshot(
    root: Path,
    frame: Any,
    status: PlayerStatus,
    previous: PlayerStatus | None,
    snapshots: list[StatusSnapshot],
    args: argparse.Namespace,
) -> StatusSnapshot:
    print(f"Dump started: food={status.food} water={status.water} hp={status.health}")
    snapshot = _write_snapshot(root, len(snapshots) + 1, frame, status, previous, args)
    snapshots.append(snapshot)
    _write_root_manifest(root, snapshots, args)
    snapshot_dir = root / Path(snapshot.screenshot).parent
    dumped_mb = sum(item.dumped_bytes for item in snapshot.process_dumps) / 1024 / 1024
    print(
        f"Dump finished #{snapshot.index}: food={status.food} water={status.water} hp={status.health} "
        f"processes={len(snapshot.process_dumps)} dumped={dumped_mb:.1f} MB"
    )
    print(f"Path: {snapshot_dir}")
    return snapshot


def _record_interactive(
    root: Path,
    capture: WindowCapture,
    detector: PlayerStatusDetector,
    snapshots: list[StatusSnapshot],
    last_status: PlayerStatus | None,
    args: argparse.Namespace,
) -> None:
    print("Keep the inventory visible.")
    print("Press Enter to save one screenshot + memory dump. Type q and press Enter to stop.")
    try:
        while True:
            command = input("> ").strip().lower()
            if command in {"q", "quit", "exit"}:
                break
            frame, status = _detect_current_status(capture, detector)
            if status is None or not status.has_core_values():
                print("Status was not detected. Keep inventory open and try again.")
                continue
            _save_current_snapshot(root, frame, status, last_status, snapshots, args)
            last_status = status
    except KeyboardInterrupt:
        print("Stopped.")


def _record_on_changes(
    root: Path,
    capture: WindowCapture,
    detector: PlayerStatusDetector,
    snapshots: list[StatusSnapshot],
    last_status: PlayerStatus | None,
    args: argparse.Namespace,
) -> None:
    last_key: tuple[int | None, int | None, int | None] | None = None
    deadline = None if args.duration <= 0 else time.monotonic() + args.duration

    print("Keep the inventory visible. Press Ctrl+C to stop.")
    try:
        while deadline is None or time.monotonic() < deadline:
            frame, status = _detect_current_status(capture, detector)
            if status is None or not status.has_core_values():
                time.sleep(args.interval)
                continue
            key = _status_key(status)
            changed = last_key is not None and key != last_key
            should_dump = changed or (not args.no_initial and not snapshots)
            if should_dump:
                _save_current_snapshot(root, frame, status, last_status, snapshots, args)
            last_status = status
            last_key = key
            time.sleep(args.interval)
    except KeyboardInterrupt:
        print("Stopped.")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Record focused GTA/webengine memory snapshots for inventory food/water/hp values."
    )
    parser.add_argument("--capture-process", default="gta5.exe", help="Process whose window is captured for status OCR.")
    parser.add_argument("--target-process", action="append", default=None, help="Process name to dump. Can be repeated.")
    parser.add_argument("--out-dir", default=None)
    parser.add_argument("--interval", type=float, default=0.5)
    parser.add_argument("--duration", type=float, default=0.0, help="Watch mode only. Seconds to run. 0 means until Ctrl+C.")
    parser.add_argument("--watch-changes", action="store_true", help="Automatically dump when food/water/hp changes instead of waiting for Enter.")
    parser.add_argument("--no-initial", action="store_true", help="Watch mode only. Only dump after the first detected change.")
    parser.add_argument("--max-processes-per-name", type=int, default=4)
    parser.add_argument("--chunk-mb", type=int, default=4)
    parser.add_argument("--marker-window-kb", type=int, default=256)
    parser.add_argument("--numeric-window-kb", type=int, default=4)
    parser.add_argument("--max-marker-hits", type=int, default=24)
    parser.add_argument("--max-numeric-hits", type=int, default=180)
    parser.add_argument("--full-selected-mb", type=int, default=0, help="Also dump this many MB of small readable regions per process.")
    parser.add_argument("--full-selected-region-mb", type=int, default=8)
    return parser


def main() -> int:
    record(build_parser().parse_args())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
