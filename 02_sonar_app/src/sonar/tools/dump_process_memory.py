from __future__ import annotations

import argparse
import json
import re
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable

import psutil

from sonar.fishing.memory_reeling import PTR_MAX, PTR_MIN
from sonar.paths import PROJECT_DIR
from sonar.tools.dump_chat_history import (
    PROCESS_CACHE_NAME,
    STATE_WINDOW_CACHE_NAME,
    WINDOW_CACHE_NAME,
    _cached_process_identity_mismatch,
    _process_snapshot,
)
from sonar.tools.find_chat_memory import _collect_search_regions, _open_tracker, iter_process_targets


DEFAULT_OUT_DIR = PROJECT_DIR / "logs" / "chat_memory"
DEFAULT_TARGETS = "GTA5.exe,majestic-webengine.exe"
GTA_TARGET = "GTA5.exe"
WEBENGINE_TARGET = "majestic-webengine.exe"
MODE_CHOICES = ("auto", "all", "gtav", "webengine", "cache", "near-player", "map", "custom")
REGION_MODE_CHOICES = ("auto", "readable", "cache", "near-player", "map")


@dataclass(frozen=True, slots=True)
class DumpRegion:
    start: int
    end: int

    @property
    def size(self) -> int:
        return max(0, self.end - self.start)


@dataclass(frozen=True, slots=True)
class DumpRegionEntry:
    start: int
    end: int
    file_offset: int
    size: int


def _safe_name(value: str) -> str:
    return re.sub(r"[^0-9A-Za-z_.-]+", "_", value).strip("._") or "process"


def _parse_int(value: Any) -> int | None:
    try:
        if isinstance(value, str):
            return int(value.strip(), 0)
        return int(value)
    except (TypeError, ValueError):
        return None


def _format_mb(value: int | float) -> str:
    return f"{float(value) / 1024 / 1024:.1f} MB"


def _write_json(path: Path, payload: dict[str, Any]) -> None:
    path.write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")


def _read_json(path: Path) -> dict[str, Any] | None:
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return None
    return data if isinstance(data, dict) else None


def _copy_args(args: argparse.Namespace, **updates: Any) -> argparse.Namespace:
    data = vars(args).copy()
    data.update(updates)
    return argparse.Namespace(**data)


def _merge_regions(regions: Iterable[tuple[int, int] | DumpRegion]) -> list[tuple[int, int]]:
    normalized: list[tuple[int, int]] = []
    for region in regions:
        if isinstance(region, DumpRegion):
            start, end = region.start, region.end
        else:
            start, end = region
        if end > start:
            normalized.append((start, end))
    normalized.sort()
    merged: list[tuple[int, int]] = []
    for start, end in normalized:
        if merged and start <= merged[-1][1]:
            merged[-1] = (merged[-1][0], max(merged[-1][1], end))
        else:
            merged.append((start, end))
    return merged


def _limit_regions_by_total(regions: list[tuple[int, int]], max_total_mb: int) -> list[tuple[int, int]]:
    if max_total_mb <= 0:
        return regions
    limit = max_total_mb * 1024 * 1024
    selected: list[tuple[int, int]] = []
    total = 0
    for start, end in regions:
        size = end - start
        if size <= 0:
            continue
        if total + size > limit:
            remaining = limit - total
            if remaining > 0:
                selected.append((start, start + remaining))
            break
        selected.append((start, end))
        total += size
    return selected


def _region_records(regions: Iterable[tuple[int, int]]) -> list[dict[str, int | str]]:
    return [
        {
            "start": start,
            "end": end,
            "start_hex": f"0x{start:X}",
            "end_hex": f"0x{end:X}",
            "size": end - start,
        }
        for start, end in regions
        if end > start
    ]


def _module_records(tracker: Any) -> list[dict[str, int | str]]:
    try:
        modules = tracker._get_modules()
    except Exception:
        return []
    records: list[dict[str, int | str]] = []
    for module in modules:
        base = int(module.base)
        size = int(module.size)
        records.append(
            {
                "name": str(module.name),
                "base": base,
                "end": base + size,
                "base_hex": f"0x{base:X}",
                "end_hex": f"0x{base + size:X}",
                "size": size,
            }
        )
    return records


def _parse_cached_window(item: Any) -> tuple[int, int] | None:
    if isinstance(item, dict):
        start = _parse_int(item.get("start"))
        end = _parse_int(item.get("end"))
    elif isinstance(item, (list, tuple)) and len(item) >= 2:
        start = _parse_int(item[0])
        end = _parse_int(item[1])
    else:
        return None
    if start is None or end is None or end <= start:
        return None
    return start, end


def _clamp_windows_to_regions(windows: Iterable[tuple[int, int]], regions: list[tuple[int, int]]) -> list[tuple[int, int]]:
    clamped: list[tuple[int, int]] = []
    region_index = 0
    sorted_regions = _merge_regions(regions)
    for window_start, window_end in _merge_regions(windows):
        while region_index < len(sorted_regions) and sorted_regions[region_index][1] <= window_start:
            region_index += 1
        scan_index = region_index
        while scan_index < len(sorted_regions):
            region_start, region_end = sorted_regions[scan_index]
            if region_start >= window_end:
                break
            start = max(window_start, region_start)
            end = min(window_end, region_end)
            if end > start:
                clamped.append((start, end))
            scan_index += 1
    return _merge_regions(clamped)


def _default_process_for_mode(mode: str) -> str:
    if mode in {"auto", "all", "map"}:
        return DEFAULT_TARGETS
    if mode == "gtav" or mode == "near-player":
        return GTA_TARGET
    if mode == "webengine":
        return WEBENGINE_TARGET
    if mode == "cache":
        return WEBENGINE_TARGET
    return ""


def _region_mode_for_args(args: argparse.Namespace) -> str:
    explicit = getattr(args, "region_mode", "auto")
    if explicit != "auto":
        return explicit
    mode = getattr(args, "mode", "auto")
    if mode == "cache":
        return "cache"
    if mode == "near-player":
        return "near-player"
    if mode == "map":
        return "map"
    return "readable"


def _target_processes(process_value: str | None, pids: list[int] | None) -> list[tuple[str, int | None]]:
    targets = iter_process_targets(process_value or "")
    seen = {pid for _, pid in targets if pid is not None}
    for pid in pids or []:
        if pid in seen:
            continue
        try:
            proc = psutil.Process(pid)
            name = proc.name()
        except psutil.Error:
            name = f"pid:{pid}"
        targets.append((name, pid))
        seen.add(pid)
    return targets


def _cache_item_to_target(item: dict[str, Any]) -> tuple[str, int] | None:
    pid = _parse_int(item.get("pid"))
    if pid is None:
        return None
    process_name = str(item.get("process") or "").strip()
    if not process_name:
        try:
            process_name = psutil.Process(pid).name()
        except psutil.Error:
            process_name = f"pid:{pid}"
    return process_name, pid


def _targets_from_cache(cache_dir: Path) -> list[tuple[str, int | None]]:
    targets: list[tuple[str, int | None]] = []
    seen: set[int] = set()

    process_cache = _read_json(cache_dir / PROCESS_CACHE_NAME)
    if process_cache:
        selected = process_cache.get("selected")
        if isinstance(selected, dict):
            selected_items = [selected]
        elif isinstance(selected, list):
            selected_items = [item for item in selected if isinstance(item, dict)]
        else:
            selected_items = []
        for item in selected_items:
            target = _cache_item_to_target(item)
            if target is None or target[1] in seen:
                continue
            targets.append(target)
            seen.add(target[1])

    for name in (WINDOW_CACHE_NAME, STATE_WINDOW_CACHE_NAME):
        data = _read_json(cache_dir / name)
        if not data:
            continue
        target = _cache_item_to_target(data)
        if target is None or target[1] in seen:
            continue
        targets.append(target)
        seen.add(target[1])

    return targets


def _process_brief(pid: int | None) -> dict[str, Any]:
    if pid is None:
        return {}
    try:
        proc = psutil.Process(pid)
        snapshot = _process_snapshot(proc) or {}
        try:
            memory = proc.memory_info()
            snapshot["rss"] = int(memory.rss)
            snapshot["vms"] = int(memory.vms)
        except psutil.Error:
            pass
        return snapshot
    except psutil.Error:
        return {}


def _print_targets(targets: list[tuple[str, int | None]]) -> None:
    for index, (process_name, pid) in enumerate(targets, 1):
        snapshot = _process_brief(pid)
        role = snapshot.get("role") or "-"
        rss = _format_mb(int(snapshot.get("rss") or 0)) if snapshot.get("rss") else "-"
        exe = snapshot.get("exe") or ""
        print(f"{index:>2}. pid={pid or '-':>6} process={process_name} role={role} rss={rss} {exe}")


def _select_targets_interactive(targets: list[tuple[str, int | None]]) -> list[tuple[str, int | None]]:
    if not targets:
        return targets
    print("Available target processes:")
    _print_targets(targets)
    raw = input("Select indexes/PIDs separated by comma, or press Enter for all: ").strip()
    if not raw or raw.lower() == "all":
        return targets
    selected: list[tuple[str, int | None]] = []
    seen: set[int | str] = set()
    for token in re.split(r"[,;\s]+", raw):
        if not token:
            continue
        value = _parse_int(token)
        match: tuple[str, int | None] | None = None
        if value is not None and 1 <= value <= len(targets):
            match = targets[value - 1]
        elif value is not None:
            match = next((item for item in targets if item[1] == value), None)
            if match is None:
                match = (f"pid:{value}", value)
        if match is None:
            continue
        key: int | str = match[1] if match[1] is not None else match[0].lower()
        if key in seen:
            continue
        selected.append(match)
        seen.add(key)
    return selected


def _resolve_targets(args: argparse.Namespace, *, apply_selection: bool = True) -> list[tuple[str, int | None]]:
    mode = getattr(args, "mode", "auto")
    pids = getattr(args, "pid", None)
    process_value = getattr(args, "process", None)
    if mode == "custom" and not process_value and not pids:
        raise RuntimeError("--mode custom requires --process and/or --pid")

    if mode == "cache" and not process_value and not pids:
        targets = _targets_from_cache(Path(getattr(args, "cache_dir", DEFAULT_OUT_DIR)))
        if not targets:
            targets = _target_processes(_default_process_for_mode(mode), pids)
    else:
        targets = _target_processes(process_value or _default_process_for_mode(mode), pids)

    if apply_selection and getattr(args, "select", False):
        targets = _select_targets_interactive(targets)
    return targets


def _load_cached_windows_from_file(
    path: Path,
    process_name: str,
    pid: int,
    readable_regions: list[tuple[int, int]],
    pad_bytes: int,
) -> tuple[list[tuple[int, int]], dict[str, Any]]:
    source: dict[str, Any] = {"path": str(path), "file": path.name}
    data = _read_json(path)
    if data is None:
        source["cache"] = "miss"
        return [], source
    source["kind"] = data.get("kind")
    if data.get("pid") != pid:
        source.update({"cache": "pid_mismatch", "pid": data.get("pid")})
        return [], source
    try:
        snapshot = _process_snapshot(psutil.Process(pid))
    except psutil.Error:
        snapshot = None
    if snapshot is None:
        source["cache"] = "process_gone"
        return [], source
    expected_process = None if process_name.lower().startswith("pid:") else process_name
    mismatch = _cached_process_identity_mismatch(
        data,
        snapshot,
        expected_process=expected_process,
        expected_pid=pid,
        require_command_line=True,
    )
    if mismatch:
        source["cache"] = mismatch
        return [], source

    windows: list[tuple[int, int]] = []
    raw_windows = data.get("windows", [])
    if not isinstance(raw_windows, list):
        source["cache"] = "invalid_windows"
        return [], source
    for raw_window in raw_windows:
        window = _parse_cached_window(raw_window)
        if window is None:
            continue
        start, end = window
        if pad_bytes > 0:
            start -= pad_bytes
            end += pad_bytes
        windows.append((start, end))
    windows = _clamp_windows_to_regions(windows, readable_regions)
    source.update(
        {
            "cache": "hit" if windows else "empty",
            "process": data.get("process"),
            "pid": pid,
            "updated_at": data.get("updated_at"),
            "raw_windows": len(raw_windows),
            "windows": len(windows),
        }
    )
    return windows, source


def _collect_cache_regions(
    args: argparse.Namespace,
    process_name: str,
    pid: int,
    readable_regions: list[tuple[int, int]],
) -> tuple[list[tuple[int, int]], dict[str, Any]]:
    cache_dir = Path(getattr(args, "cache_dir", DEFAULT_OUT_DIR))
    pad_bytes = max(0, int(getattr(args, "cache_pad_kb", 0) or 0)) * 1024
    windows: list[tuple[int, int]] = []
    sources: list[dict[str, Any]] = []
    for name in (WINDOW_CACHE_NAME, STATE_WINDOW_CACHE_NAME):
        cached_windows, source = _load_cached_windows_from_file(cache_dir / name, process_name, pid, readable_regions, pad_bytes)
        windows.extend(cached_windows)
        sources.append(source)
    windows = _limit_regions_by_total(_merge_regions(windows), int(getattr(args, "max_total_mb", 0) or 0))
    return windows, {"cache_dir": str(cache_dir), "cache_sources": sources}


def _pos_record(pos: tuple[float, float, float] | None) -> dict[str, float] | None:
    if pos is None:
        return None
    return {"x": float(pos[0]), "y": float(pos[1]), "z": float(pos[2])}


def _add_anchor(
    anchors: list[dict[str, Any]],
    *,
    label: str,
    addr: int | None,
    window_kb: int,
    extra: dict[str, Any] | None = None,
) -> None:
    if addr is None:
        return
    item: dict[str, Any] = {
        "label": label,
        "addr": int(addr),
        "addr_hex": f"0x{int(addr):X}",
        "window_kb": int(window_kb),
    }
    if extra:
        item.update(extra)
    anchors.append(item)


def _collect_near_player_regions(
    args: argparse.Namespace,
    tracker: Any,
    readable_regions: list[tuple[int, int]],
) -> tuple[list[tuple[int, int]], dict[str, Any]]:
    window_kb = max(4, int(getattr(args, "near_window_kb", 512) or 512))
    replay_window_kb = max(4, int(getattr(args, "near_replay_window_kb", 128) or 128))
    anchors: list[dict[str, Any]] = []
    errors: list[str] = []

    replay_interface: int | None = None
    player_addr: int | None = None
    fish_addr: int | None = None
    player_pos: tuple[float, float, float] | None = None
    fish_pos: tuple[float, float, float] | None = None

    try:
        replay_interface = tracker._find_replay_interface_global()
        tracker.replay_interface = replay_interface
    except Exception as exc:
        errors.append(f"replay_interface: {exc}")

    try:
        player_addr = tracker._find_cped()
        tracker.player_addr = player_addr
        if player_addr is not None:
            player_pos = tracker._read_player_pos(player_addr)
    except Exception as exc:
        errors.append(f"player: {exc}")

    if player_addr is not None and not getattr(args, "no_near_fish", False):
        try:
            fish_addr = tracker._find_fish_addr_replay() or tracker._find_fish_addr()
            tracker.fish_addr = fish_addr
            if fish_addr is not None:
                fish_pos = tracker._read_fish_pos(fish_addr)
        except Exception as exc:
            errors.append(f"fish: {exc}")

    _add_anchor(anchors, label="player", addr=player_addr, window_kb=window_kb, extra={"position": _pos_record(player_pos)})
    _add_anchor(anchors, label="fish", addr=fish_addr, window_kb=window_kb, extra={"position": _pos_record(fish_pos)})
    _add_anchor(anchors, label="replay_interface", addr=replay_interface, window_kb=replay_window_kb)

    windows: list[tuple[int, int]] = []
    for anchor in anchors:
        addr = int(anchor["addr"])
        half = int(anchor["window_kb"]) * 1024
        windows.append((max(PTR_MIN, addr - half), min(PTR_MAX, addr + half)))

    clamped = _clamp_windows_to_regions(windows, readable_regions)
    clamped = _limit_regions_by_total(clamped, int(getattr(args, "max_total_mb", 0) or 0))
    meta: dict[str, Any] = {"anchors": anchors}
    if errors:
        meta["anchor_errors"] = errors
    if not anchors:
        meta["region_warning"] = "no_near_player_anchors"
    elif not clamped:
        meta["region_warning"] = "near_player_anchors_unreadable"
    return clamped, meta


def _select_regions_to_dump(
    args: argparse.Namespace,
    tracker: Any,
    process_name: str,
    pid: int,
    readable_regions: list[tuple[int, int]],
) -> tuple[list[tuple[int, int]], dict[str, Any]]:
    region_mode = _region_mode_for_args(args)
    if region_mode == "map":
        return [], {"memory_map": _region_records(readable_regions)}
    if region_mode == "cache":
        return _collect_cache_regions(args, process_name, pid, readable_regions)
    if region_mode == "near-player":
        return _collect_near_player_regions(args, tracker, readable_regions)
    return readable_regions, {}


def _write_dump_bytes(
    tracker: Any,
    data_path: Path,
    regions: list[tuple[int, int]],
    args: argparse.Namespace,
    process_name: str,
) -> tuple[list[dict[str, int]], int, int]:
    regions_out: list[dict[str, int]] = []
    chunk_size = max(4096, int(getattr(args, "chunk_mb", 8) or 8) * 1024 * 1024)
    written = 0
    failed_reads = 0
    with data_path.open("wb") as out:
        for index, (start, end) in enumerate(regions, 1):
            addr = start
            while addr < end:
                size = min(chunk_size, end - addr)
                data = tracker._read(addr, size)
                if data:
                    file_offset = out.tell()
                    out.write(data)
                    chunk_end = addr + len(data)
                    if (
                        regions_out
                        and regions_out[-1]["end"] == addr
                        and regions_out[-1]["file_offset"] + regions_out[-1]["size"] == file_offset
                    ):
                        regions_out[-1]["end"] = chunk_end
                        regions_out[-1]["size"] += len(data)
                    else:
                        regions_out.append(
                            {
                                "start": addr,
                                "end": chunk_end,
                                "size": len(data),
                                "file_offset": file_offset,
                            }
                        )
                    written += len(data)
                else:
                    failed_reads += 1
                addr += size
            progress = int(getattr(args, "progress", 100) or 0)
            if progress and (index % progress == 0 or index == len(regions)):
                print(
                    f"{process_name} pid={tracker.pid} "
                    f"regions={index}/{len(regions)} written={_format_mb(written)}"
                )
    return regions_out, written, failed_reads


def _dump_one_process(args: argparse.Namespace, dump_root: Path, process_name: str, pid: int | None) -> dict[str, Any]:
    tracker = _open_tracker(process_name, pid)
    assert tracker.pid is not None
    snapshot: dict[str, Any] = {}
    started = time.perf_counter()
    try:
        proc_snapshot = _process_snapshot(psutil.Process(tracker.pid))
        if proc_snapshot:
            snapshot.update(proc_snapshot)
    except psutil.Error:
        pass
    snapshot.setdefault("process", process_name)
    snapshot.setdefault("pid", tracker.pid)

    region_mode = _region_mode_for_args(args)
    max_total_for_scan = int(getattr(args, "max_total_mb", 0) or 0) if region_mode == "readable" else 0
    readable_regions = _collect_search_regions(tracker, int(getattr(args, "max_region_mb", 512) or 512), max_total_for_scan)
    selected_regions, region_meta = _select_regions_to_dump(args, tracker, process_name, tracker.pid, readable_regions)
    selected_regions = _merge_regions(selected_regions)

    process_dir = dump_root / f"{_safe_name(process_name)}_{tracker.pid}"
    regions_out: list[dict[str, int]] = []
    written = 0
    failed_reads = 0
    try:
        if region_mode != "map":
            process_dir.mkdir(parents=True, exist_ok=True)
            data_path = process_dir / "memory.bin"
            regions_out, written, failed_reads = _write_dump_bytes(tracker, data_path, selected_regions, args, process_name)
            snapshot["data_file"] = str(data_path.relative_to(dump_root))
    finally:
        elapsed = time.perf_counter() - started
        snapshot.update(
            {
                "mode": getattr(args, "mode", "auto"),
                "region_mode": region_mode,
                "regions": regions_out,
                "region_count": len(regions_out),
                "selected_regions": _region_records(selected_regions),
                "selected_region_count": len(selected_regions),
                "selected_bytes": sum(end - start for start, end in selected_regions),
                "candidate_region_count": len(readable_regions),
                "candidate_bytes": sum(end - start for start, end in readable_regions),
                "dumped_bytes": written,
                "failed_reads": failed_reads,
                "elapsed_seconds": elapsed,
                "modules": _module_records(tracker),
            }
        )
        snapshot.update(region_meta)
        tracker.stop()
    return snapshot


def dump_process_memory(args: argparse.Namespace) -> Path:
    out_dir = Path(getattr(args, "out_dir", None) or DEFAULT_OUT_DIR)
    out_dir.mkdir(parents=True, exist_ok=True)
    dump_root = out_dir / f"{_safe_name(getattr(args, 'name', 'process_memory_dump'))}_{time.strftime('%Y%m%d_%H%M%S')}"
    dump_root.mkdir(parents=True, exist_ok=False)
    manifest_path = dump_root / "manifest.json"
    mode = getattr(args, "mode", "auto")
    manifest: dict[str, Any] = {
        "kind": "sonar_process_memory_dump",
        "version": 3,
        "created_at": time.time(),
        "path": str(dump_root),
        "mode": mode,
        "region_mode": _region_mode_for_args(args),
        "process": getattr(args, "process", None) or _default_process_for_mode(mode) or "custom",
        "cache_dir": str(Path(getattr(args, "cache_dir", DEFAULT_OUT_DIR))),
        "processes": [],
    }
    _write_json(manifest_path, manifest)

    targets = _resolve_targets(args)
    if not targets:
        raise RuntimeError(f"Process not found: {manifest['process']}")

    for process_name, pid in targets:
        try:
            process_report = _dump_one_process(args, dump_root, process_name, pid)
        except Exception as exc:
            process_report = {
                "process": process_name,
                "pid": pid,
                "mode": mode,
                "region_mode": _region_mode_for_args(args),
                "error": str(exc),
                "regions": [],
            }
            print(f"Memory dump failed for {process_name} pid={pid}: {exc}")
        manifest["processes"].append(process_report)
        _write_json(manifest_path, manifest)

    total_bytes = sum(int(item.get("dumped_bytes") or 0) for item in manifest["processes"])
    print(f"Saved process memory dump: {dump_root}")
    print(f"Processes: {len(manifest['processes'])} dumped={_format_mb(total_bytes)}")
    return dump_root


def list_processes(args: argparse.Namespace) -> None:
    targets = _resolve_targets(args, apply_selection=False)
    if not targets:
        print("No matching processes.")
        return
    _print_targets(targets)


def run_interactive(args: argparse.Namespace) -> Path:
    out_dir = Path(getattr(args, "out_dir", None) or DEFAULT_OUT_DIR)
    series_root = out_dir / f"{_safe_name(getattr(args, 'name', 'process_memory_dump'))}_series_{time.strftime('%Y%m%d_%H%M%S')}"
    series_root.mkdir(parents=True, exist_ok=False)
    series_manifest_path = series_root / "series_manifest.json"
    selected_targets: list[tuple[str, int | None]] | None = None
    series_args = args
    if getattr(args, "select", False):
        selected_targets = _resolve_targets(args, apply_selection=True)
        process_tokens = [f"pid:{pid}" if pid is not None else process_name for process_name, pid in selected_targets]
        series_args = _copy_args(args, select=False, process=",".join(process_tokens), pid=None)
    series_manifest: dict[str, Any] = {
        "kind": "sonar_process_memory_dump_series",
        "version": 1,
        "created_at": time.time(),
        "mode": getattr(args, "mode", "auto"),
        "region_mode": _region_mode_for_args(args),
        "selected_targets": [
            {"process": process_name, "pid": pid}
            for process_name, pid in (selected_targets or [])
        ],
        "snapshots": [],
    }
    _write_json(series_manifest_path, series_manifest)

    index = 0
    max_count = max(0, int(getattr(args, "count", 0) or 0))
    print(f"Interactive dump series: {series_root}")
    while max_count <= 0 or index < max_count:
        try:
            command = input(f"[{index + 1}] Enter=dump, l=list processes, q=quit > ").strip().lower()
        except EOFError:
            break
        if command in {"q", "quit", "exit"}:
            break
        if command in {"l", "list"}:
            list_processes(series_args)
            continue
        index += 1
        snapshot_args = _copy_args(
            series_args,
            interactive=False,
            out_dir=str(series_root),
            name=f"snapshot_{index:03d}",
        )
        dump_path = dump_process_memory(snapshot_args)
        series_manifest["snapshots"].append(
            {
                "index": index,
                "created_at": time.time(),
                "path": str(dump_path),
                "manifest": str(dump_path / "manifest.json"),
            }
        )
        _write_json(series_manifest_path, series_manifest)
    print(f"Saved dump series: {series_root}")
    return series_root


def _load_dump_manifest(path_value: str | Path) -> tuple[Path, dict[str, Any]]:
    path = Path(path_value)
    manifest_path = path / "manifest.json" if path.is_dir() else path
    data = _read_json(manifest_path)
    if data is None:
        raise RuntimeError(f"Invalid dump manifest: {manifest_path}")
    return manifest_path.parent, data


def _process_compare_key(process: dict[str, Any], mode: str) -> str:
    name = str(process.get("process") or "").lower()
    pid = process.get("pid")
    if mode == "process":
        return name
    return f"{name}:{pid}"


def _processes_by_key(manifest: dict[str, Any], mode: str) -> dict[str, dict[str, Any]]:
    out: dict[str, dict[str, Any]] = {}
    for process in manifest.get("processes", []):
        if isinstance(process, dict):
            out[_process_compare_key(process, mode)] = process
    return out


def _region_entries(process: dict[str, Any]) -> list[DumpRegionEntry]:
    entries: list[DumpRegionEntry] = []
    for item in process.get("regions", []):
        if not isinstance(item, dict):
            continue
        start = _parse_int(item.get("start"))
        end = _parse_int(item.get("end"))
        file_offset = _parse_int(item.get("file_offset"))
        size = _parse_int(item.get("size"))
        if start is None or end is None or file_offset is None:
            continue
        if size is None:
            size = end - start
        end = min(end, start + size)
        if end > start and size > 0:
            entries.append(DumpRegionEntry(start=start, end=end, file_offset=file_offset, size=end - start))
    entries.sort(key=lambda item: item.start)
    return entries


def _append_changed_range(
    ranges: list[dict[str, int | str]],
    start: int,
    end: int,
    changed_bytes: int,
    max_ranges: int,
) -> int:
    if ranges and start <= int(ranges[-1]["end"]):
        ranges[-1]["end"] = max(int(ranges[-1]["end"]), end)
        ranges[-1]["end_hex"] = f"0x{int(ranges[-1]['end']):X}"
        ranges[-1]["changed_bytes"] = int(ranges[-1]["changed_bytes"]) + changed_bytes
        return 0
    if len(ranges) >= max_ranges:
        return 1
    ranges.append(
        {
            "start": start,
            "end": end,
            "start_hex": f"0x{start:X}",
            "end_hex": f"0x{end:X}",
            "changed_bytes": changed_bytes,
        }
    )
    return 0


def _first_last_diff(left: bytes, right: bytes) -> tuple[int, int, int] | None:
    if left == right:
        return None
    limit = min(len(left), len(right))
    first = 0
    while first < limit and left[first] == right[first]:
        first += 1
    last = limit - 1
    while last >= first and left[last] == right[last]:
        last -= 1
    changed = sum(1 for index in range(first, last + 1) if left[index] != right[index])
    return first, last + 1, changed


def _compare_process_regions(
    left_root: Path,
    left_process: dict[str, Any],
    right_root: Path,
    right_process: dict[str, Any],
    *,
    chunk_size: int,
    max_ranges: int,
) -> dict[str, Any]:
    left_file_value = left_process.get("data_file")
    right_file_value = right_process.get("data_file")
    result: dict[str, Any] = {
        "process": right_process.get("process") or left_process.get("process"),
        "left_pid": left_process.get("pid"),
        "right_pid": right_process.get("pid"),
        "comparable_bytes": 0,
        "changed_bytes": 0,
        "changed_ranges": [],
        "omitted_changed_ranges": 0,
    }
    if not isinstance(left_file_value, str) or not isinstance(right_file_value, str):
        result["error"] = "missing_data_file"
        return result
    left_entries = _region_entries(left_process)
    right_entries = _region_entries(right_process)
    left_path = left_root / left_file_value
    right_path = right_root / right_file_value
    if not left_path.exists() or not right_path.exists():
        result["error"] = "data_file_not_found"
        return result

    i = 0
    j = 0
    with left_path.open("rb") as left_file, right_path.open("rb") as right_file:
        while i < len(left_entries) and j < len(right_entries):
            left_entry = left_entries[i]
            right_entry = right_entries[j]
            start = max(left_entry.start, right_entry.start)
            end = min(left_entry.end, right_entry.end)
            if end > start:
                offset = 0
                size = end - start
                while offset < size:
                    read_size = min(chunk_size, size - offset)
                    addr = start + offset
                    left_file.seek(left_entry.file_offset + (addr - left_entry.start))
                    right_file.seek(right_entry.file_offset + (addr - right_entry.start))
                    left_data = left_file.read(read_size)
                    right_data = right_file.read(read_size)
                    actual = min(len(left_data), len(right_data))
                    if actual <= 0:
                        break
                    result["comparable_bytes"] += actual
                    diff = _first_last_diff(left_data[:actual], right_data[:actual])
                    if diff is not None:
                        first, last, changed = diff
                        result["changed_bytes"] += changed
                        result["omitted_changed_ranges"] += _append_changed_range(
                            result["changed_ranges"],
                            addr + first,
                            addr + last,
                            changed,
                            max_ranges,
                        )
                    offset += actual
            if left_entry.end <= right_entry.end:
                i += 1
            else:
                j += 1
    return result


def compare_memory_dumps(args: argparse.Namespace) -> Path:
    left_root, left_manifest = _load_dump_manifest(getattr(args, "compare")[0])
    right_root, right_manifest = _load_dump_manifest(getattr(args, "compare")[1])
    compare_key = getattr(args, "compare_key", "process-pid")
    left_processes = _processes_by_key(left_manifest, compare_key)
    right_processes = _processes_by_key(right_manifest, compare_key)
    chunk_size = max(4096, int(getattr(args, "diff_chunk_mb", 8) or 8) * 1024 * 1024)
    max_ranges = max(0, int(getattr(args, "diff_max_ranges", 200) or 200))
    report: dict[str, Any] = {
        "kind": "sonar_process_memory_diff",
        "version": 1,
        "created_at": time.time(),
        "left": str(left_root),
        "right": str(right_root),
        "compare_key": compare_key,
        "processes": [],
    }
    for key in sorted(set(left_processes) | set(right_processes)):
        left_process = left_processes.get(key)
        right_process = right_processes.get(key)
        if left_process is None or right_process is None:
            report["processes"].append(
                {
                    "key": key,
                    "status": "missing_left" if left_process is None else "missing_right",
                }
            )
            continue
        process_report = _compare_process_regions(
            left_root,
            left_process,
            right_root,
            right_process,
            chunk_size=chunk_size,
            max_ranges=max_ranges,
        )
        process_report["key"] = key
        process_report["status"] = "compared"
        report["processes"].append(process_report)

    total_comparable = sum(int(item.get("comparable_bytes") or 0) for item in report["processes"])
    total_changed = sum(int(item.get("changed_bytes") or 0) for item in report["processes"])
    report["comparable_bytes"] = total_comparable
    report["changed_bytes"] = total_changed

    out_value = getattr(args, "compare_out", None)
    if out_value:
        out_path = Path(out_value)
        if out_path.suffix.lower() != ".json":
            out_path.mkdir(parents=True, exist_ok=True)
            out_path = out_path / f"memory_diff_{time.strftime('%Y%m%d_%H%M%S')}.json"
        else:
            out_path.parent.mkdir(parents=True, exist_ok=True)
    else:
        out_path = right_root / f"memory_diff_{time.strftime('%Y%m%d_%H%M%S')}.json"
    _write_json(out_path, report)
    print(f"Saved memory diff: {out_path}")
    print(f"Comparable={_format_mb(total_comparable)} changed={_format_mb(total_changed)}")
    return out_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Create repeatable GTA/Majestic process memory dumps.")
    parser.add_argument("--mode", choices=MODE_CHOICES, default="auto")
    parser.add_argument("--region-mode", choices=REGION_MODE_CHOICES, default="auto")
    parser.add_argument("--process", default=None, help="Process list, PID list, or process names separated by commas.")
    parser.add_argument("--pid", action="append", type=int, help="Additional PID to dump. Can be passed more than once.")
    parser.add_argument("--select", action="store_true", help="Interactively select several target processes from the resolved list.")
    parser.add_argument("--list-processes", action="store_true", help="List resolved target processes and exit.")
    parser.add_argument("--interactive", action="store_true", help="Press Enter for each dump in a timestamped series.")
    parser.add_argument("--count", type=int, default=0, help="Maximum interactive dumps. 0 means until q/EOF.")
    parser.add_argument("--out-dir", default=str(DEFAULT_OUT_DIR))
    parser.add_argument("--cache-dir", default=str(DEFAULT_OUT_DIR))
    parser.add_argument("--name", default="process_memory_dump")
    parser.add_argument("--max-region-mb", type=int, default=512)
    parser.add_argument("--max-total-mb", type=int, default=0, help="0 dumps all selected readable regions.")
    parser.add_argument("--chunk-mb", type=int, default=8)
    parser.add_argument("--progress", type=int, default=100, help="Print progress every N regions. Use 0 to disable.")
    parser.add_argument("--cache-pad-kb", type=int, default=0, help="Extra KB around cached chat/state windows.")
    parser.add_argument("--near-window-kb", type=int, default=512, help="Half-window around player/fish anchors in near-player mode.")
    parser.add_argument("--near-replay-window-kb", type=int, default=128, help="Half-window around replay-interface anchor.")
    parser.add_argument("--no-near-fish", action="store_true", help="Skip fish address resolution in near-player mode.")
    parser.add_argument("--compare", nargs=2, metavar=("LEFT", "RIGHT"), help="Compare two dump directories or manifest.json files.")
    parser.add_argument("--compare-out", default=None, help="JSON diff path or directory.")
    parser.add_argument("--compare-key", choices=("process-pid", "process"), default="process-pid")
    parser.add_argument("--diff-chunk-mb", type=int, default=8)
    parser.add_argument("--diff-max-ranges", type=int, default=200)
    return parser


def main() -> int:
    args = build_parser().parse_args()
    if args.compare:
        compare_memory_dumps(args)
        return 0
    if args.list_processes:
        list_processes(args)
        return 0
    if args.interactive:
        run_interactive(args)
        return 0
    dump_process_memory(args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
