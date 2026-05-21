from __future__ import annotations

import argparse
import json
import re
import time
from pathlib import Path
from typing import Any

import psutil

from sonar.paths import PROJECT_DIR
from sonar.tools.dump_chat_history import _process_snapshot
from sonar.tools.find_chat_memory import _collect_search_regions, _open_tracker, iter_process_targets


DEFAULT_OUT_DIR = PROJECT_DIR / "logs" / "chat_memory"


def _safe_name(value: str) -> str:
    return re.sub(r"[^0-9A-Za-z_.-]+", "_", value).strip("._") or "process"


def _target_processes(process_value: str, pids: list[int] | None) -> list[tuple[str, int | None]]:
    targets = iter_process_targets(process_value)
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


def _write_manifest(path: Path, manifest: dict[str, Any]) -> None:
    path.write_text(json.dumps(manifest, ensure_ascii=False, indent=2), encoding="utf-8")


def _dump_one_process(args: argparse.Namespace, dump_root: Path, process_name: str, pid: int | None) -> dict[str, Any]:
    tracker = _open_tracker(process_name, pid)
    assert tracker.pid is not None
    snapshot: dict[str, Any] = {}
    try:
        proc_snapshot = _process_snapshot(psutil.Process(tracker.pid))
        if proc_snapshot:
            snapshot.update(proc_snapshot)
    except psutil.Error:
        pass
    snapshot.setdefault("process", process_name)
    snapshot.setdefault("pid", tracker.pid)

    process_dir = dump_root / f"{_safe_name(process_name)}_{tracker.pid}"
    process_dir.mkdir(parents=True, exist_ok=True)
    data_path = process_dir / "memory.bin"
    regions_out: list[dict[str, int]] = []
    chunk_size = max(4096, args.chunk_mb * 1024 * 1024)

    started = time.perf_counter()
    try:
        regions = _collect_search_regions(tracker, args.max_region_mb, args.max_total_mb)
        total_bytes = sum(end - start for start, end in regions)
        written = 0
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
                    addr += size
                if args.progress and (index % args.progress == 0 or index == len(regions)):
                    print(
                        f"{process_name} pid={tracker.pid} "
                        f"regions={index}/{len(regions)} written={written / 1024 / 1024:.1f} MB"
                    )
        elapsed = time.perf_counter() - started
        snapshot.update(
            {
                "data_file": str(data_path.relative_to(dump_root)),
                "regions": regions_out,
                "region_count": len(regions_out),
                "candidate_region_count": len(regions),
                "candidate_bytes": total_bytes,
                "dumped_bytes": written,
                "elapsed_seconds": elapsed,
            }
        )
        return snapshot
    finally:
        tracker.stop()


def dump_process_memory(args: argparse.Namespace) -> Path:
    out_dir = Path(args.out_dir or DEFAULT_OUT_DIR)
    out_dir.mkdir(parents=True, exist_ok=True)
    dump_root = out_dir / f"{args.name}_{time.strftime('%Y%m%d_%H%M%S')}"
    dump_root.mkdir(parents=True, exist_ok=False)
    manifest_path = dump_root / "manifest.json"
    manifest: dict[str, Any] = {
        "kind": "sonar_process_memory_dump",
        "version": 2,
        "created_at": time.time(),
        "path": str(dump_root),
        "process": args.process,
        "processes": [],
    }
    _write_manifest(manifest_path, manifest)

    targets = _target_processes(args.process, args.pid)
    if not targets:
        raise RuntimeError(f"Process not found: {args.process}")

    for process_name, pid in targets:
        try:
            process_report = _dump_one_process(args, dump_root, process_name, pid)
        except Exception as exc:
            process_report = {
                "process": process_name,
                "pid": pid,
                "error": str(exc),
                "regions": [],
            }
            print(f"Memory dump failed for {process_name} pid={pid}: {exc}")
        manifest["processes"].append(process_report)
        _write_manifest(manifest_path, manifest)

    total_bytes = sum(int(item.get("dumped_bytes") or 0) for item in manifest["processes"])
    print(f"Saved process memory dump: {dump_root}")
    print(f"Processes: {len(manifest['processes'])} dumped={total_bytes / 1024 / 1024:.1f} MB")
    return dump_root


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Create a process memory dump that dump_chat_history can read later.")
    parser.add_argument("--process", default="GTA5.exe,majestic-webengine.exe")
    parser.add_argument("--pid", action="append", type=int, help="Additional PID to dump. Can be passed more than once.")
    parser.add_argument("--out-dir", default=str(DEFAULT_OUT_DIR))
    parser.add_argument("--name", default="process_memory_dump")
    parser.add_argument("--max-region-mb", type=int, default=512)
    parser.add_argument("--max-total-mb", type=int, default=0, help="0 dumps all selected readable regions.")
    parser.add_argument("--chunk-mb", type=int, default=8)
    parser.add_argument("--progress", type=int, default=100, help="Print progress every N regions. Use 0 to disable.")
    return parser


def main() -> int:
    dump_process_memory(build_parser().parse_args())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
