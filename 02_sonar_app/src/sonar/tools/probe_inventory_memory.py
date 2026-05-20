from __future__ import annotations

import argparse
import json
import time
from dataclasses import asdict, dataclass
from pathlib import Path

import numpy as np

from sonar.fishing.memory_reeling import MemoryReelingTracker, PTR_MAX, PTR_MIN
from sonar.paths import PROJECT_DIR
from sonar.tools.record_reeling_memory import NullInputController


@dataclass(slots=True)
class ByteCandidate:
    addr: int
    closed_value: int
    open_value: int
    delta: int
    region_size: int
    correct: int = 0
    wrong: int = 0
    unreadable: int = 0
    total: int = 0
    accuracy: float = 0.0

    @property
    def page(self) -> int:
        return self.addr & ~0xFFF


def _collect_regions_limited(tracker: MemoryReelingTracker, max_total_mb: int, max_region_mb: int) -> list[tuple[int, int]]:
    regions = tracker._collect_regions(PTR_MIN, PTR_MAX)
    filtered = [(start, end) for start, end in regions if 0 < end - start <= max_region_mb * 1024 * 1024]
    filtered.sort(key=lambda item: item[1] - item[0])
    selected: list[tuple[int, int]] = []
    total = 0
    limit = max_total_mb * 1024 * 1024
    for start, end in filtered:
        size = end - start
        if total + size > limit:
            continue
        selected.append((start, end))
        total += size
    return selected


def _snapshot(tracker: MemoryReelingTracker, regions: list[tuple[int, int]]) -> dict[int, bytes]:
    out: dict[int, bytes] = {}
    for start, end in regions:
        data = tracker._read(start, end - start)
        if data and len(data) == end - start:
            out[start] = data
    return out


def _cap_per_page(candidates: list[ByteCandidate], per_page: int, limit: int) -> list[ByteCandidate]:
    out: list[ByteCandidate] = []
    page_counts: dict[int, int] = {}
    for candidate in candidates:
        count = page_counts.get(candidate.page, 0)
        if count >= per_page:
            continue
        page_counts[candidate.page] = count + 1
        out.append(candidate)
        if len(out) >= limit:
            break
    return out


def _stable_byte_candidates(
    labels: list[int],
    snapshots: list[dict[int, bytes]],
    limit: int,
    per_region_limit: int,
    per_page_limit: int,
) -> list[ByteCandidate]:
    closed_indexes = [index for index, label in enumerate(labels) if label == 0]
    open_indexes = [index for index, label in enumerate(labels) if label == 1]
    if not closed_indexes or not open_indexes:
        return []
    common_bases = set(snapshots[0])
    for snap in snapshots[1:]:
        common_bases &= set(snap)
    candidates: list[ByteCandidate] = []
    for base in sorted(common_bases):
        arrays = [np.frombuffer(snap[base], dtype=np.uint8) for snap in snapshots]
        min_len = min(array.size for array in arrays)
        if min_len <= 0:
            continue
        arr = np.stack([array[:min_len] for array in arrays])
        closed = arr[closed_indexes]
        opened = arr[open_indexes]
        closed_same = np.all(closed == closed[0], axis=0)
        open_same = np.all(opened == opened[0], axis=0)
        different = closed[0] != opened[0]
        idxs = np.where(closed_same & open_same & different)[0]
        for idx in idxs[:per_region_limit]:
            delta = abs(int(opened[0, idx]) - int(closed[0, idx]))
            candidates.append(
                ByteCandidate(
                    addr=base + int(idx),
                    closed_value=int(closed[0, idx]),
                    open_value=int(opened[0, idx]),
                    delta=delta,
                    region_size=min_len,
                )
            )
    candidates.sort(key=lambda item: (-item.delta, item.region_size, item.addr))
    return _cap_per_page(candidates, per_page_limit, limit)


def _read_candidate_byte(tracker: MemoryReelingTracker, addr: int) -> int | None:
    data = tracker._read(addr, 1)
    return None if data is None else data[0]


def _validate_candidates(
    tracker: MemoryReelingTracker,
    candidates: list[ByteCandidate],
    sequence: list[int],
    samples_per_state: int,
    sample_interval: float,
) -> None:
    for index, label in enumerate(sequence, 1):
        state = "CLOSED" if label == 0 else "OPEN"
        input(f"[validation {index}/{len(sequence)}] Set inventory {state}, wait until stable, then press Enter...")
        for sample_index in range(samples_per_state):
            for candidate in candidates:
                value = _read_candidate_byte(tracker, candidate.addr)
                expected = candidate.open_value if label == 1 else candidate.closed_value
                opposite = candidate.closed_value if label == 1 else candidate.open_value
                candidate.total += 1
                if value is None:
                    candidate.unreadable += 1
                elif value == expected:
                    candidate.correct += 1
                elif value == opposite:
                    candidate.wrong += 1
                else:
                    candidate.unreadable += 1
            if sample_index + 1 < samples_per_state:
                time.sleep(sample_interval)
        print(f"Validated {state}: samples={samples_per_state}")
    for candidate in candidates:
        candidate.accuracy = candidate.correct / candidate.total if candidate.total else 0.0


def _candidate_line(candidate: ByteCandidate) -> str:
    return (
        f"addr=0x{candidate.addr:X} byte closed={candidate.closed_value} open={candidate.open_value} "
        f"delta={candidate.delta} accuracy={candidate.accuracy:.3f} "
        f"correct={candidate.correct}/{candidate.total} wrong={candidate.wrong} unreadable={candidate.unreadable}"
    )


def _profile_candidate(candidate: ByteCandidate) -> dict[str, int | float | str]:
    data = asdict(candidate)
    data["addr"] = f"0x{candidate.addr:X}"
    data["page"] = f"0x{candidate.page:X}"
    data["weight"] = max(0.1, candidate.accuracy)
    return data


def run(args: argparse.Namespace) -> Path:
    tracker = MemoryReelingTracker(args.process, input_controller=NullInputController(), log_callback=print)
    tracker.start()
    time.sleep(0.5)
    if not tracker.handle:
        raise RuntimeError("Could not open process memory")
    regions = _collect_regions_limited(tracker, args.max_total_mb, args.max_region_mb)
    total_mb = sum(end - start for start, end in regions) / 1024 / 1024
    print(f"Selected regions: {len(regions)} total={total_mb:.1f} MB")
    print("Discovery phase reads large memory snapshots. Follow prompts exactly.")
    print("After changing inventory state, wait until the animation is fully finished before pressing Enter.")
    sequence = [state for _ in range(args.discovery_cycles) for state in (0, 1)]
    labels: list[int] = []
    snapshots: list[dict[int, bytes]] = []
    candidates: list[ByteCandidate] = []
    try:
        for index, label in enumerate(sequence, 1):
            state = "CLOSED" if label == 0 else "OPEN"
            input(f"[discovery {index}/{len(sequence)}] Set inventory {state}, wait until stable, then press Enter...")
            labels.append(label)
            snapshots.append(_snapshot(tracker, regions))
            print(f"Captured {state}: regions={len(snapshots[-1])}")

        candidates = _stable_byte_candidates(
            labels,
            snapshots,
            limit=args.candidate_limit,
            per_region_limit=args.per_region_limit,
            per_page_limit=args.per_page_limit,
        )
        del snapshots
        print(f"Discovery candidates: {len(candidates)}")
        if candidates:
            print("Validation phase reads only candidate bytes.")
            validation_sequence = [state for _ in range(args.validation_cycles) for state in (0, 1)]
            _validate_candidates(tracker, candidates, validation_sequence, args.samples_per_state, args.sample_interval)
    finally:
        tracker.stop()
    if not candidates:
        validated: list[ByteCandidate] = []
    else:
        validated = [
            candidate
            for candidate in candidates
            if candidate.total
            and candidate.accuracy >= args.min_accuracy
            and candidate.wrong <= args.max_wrong
            and candidate.unreadable <= args.max_unreadable
        ]
        validated.sort(key=lambda item: (-item.accuracy, item.wrong, item.unreadable, -item.delta, item.region_size, item.addr))
        validated = _cap_per_page(validated, args.profile_per_page_limit, args.top)
    lines = [
        "Inventory memory probe",
        f"process={args.process}",
        f"pid={tracker.pid}",
        f"regions={len(regions)} total_mb={total_mb:.1f}",
        f"discovery_candidates={0 if not candidates else len(candidates)}",
        f"validated_candidates={len(validated)}",
        "Validated candidates:",
    ]
    lines.extend([_candidate_line(candidate) for candidate in validated] or ["No validated candidates found. Re-run and keep each prompted state stable."])
    out_dir = PROJECT_DIR / "logs" / "memory_snapshots"
    out_dir.mkdir(parents=True, exist_ok=True)
    stamp = int(time.time())
    out_path = out_dir / f"inventory_memory_probe_{stamp}.txt"
    out_path.write_text("\n".join(lines), encoding="utf-8")
    profile_path = out_dir / f"inventory_memory_profile_{stamp}.json"
    profile = {
        "kind": "sonar_inventory_memory_profile",
        "version": 1,
        "created_at": time.time(),
        "process": args.process,
        "pid": tracker.pid,
        "regions": len(regions),
        "total_mb": total_mb,
        "discovery_cycles": args.discovery_cycles,
        "validation_cycles": args.validation_cycles,
        "samples_per_state": args.samples_per_state,
        "min_accuracy": args.min_accuracy,
        "candidates": [_profile_candidate(candidate) for candidate in validated],
    }
    profile_path.write_text(json.dumps(profile, ensure_ascii=False, indent=2), encoding="utf-8")
    print("\n".join(lines[: min(len(lines), args.top + 6)]))
    print(f"Saved report: {out_path}")
    print(f"Saved profile: {profile_path}")
    return out_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Find memory bytes that correlate with inventory open/closed state.")
    parser.add_argument("--process", default="gta5.exe")
    parser.add_argument("--max-total-mb", type=int, default=512)
    parser.add_argument("--max-region-mb", type=int, default=16)
    parser.add_argument("--top", type=int, default=80)
    parser.add_argument("--discovery-cycles", type=int, default=3)
    parser.add_argument("--validation-cycles", type=int, default=3)
    parser.add_argument("--samples-per-state", type=int, default=3)
    parser.add_argument("--sample-interval", type=float, default=0.12)
    parser.add_argument("--candidate-limit", type=int, default=1600)
    parser.add_argument("--per-region-limit", type=int, default=512)
    parser.add_argument("--per-page-limit", type=int, default=16)
    parser.add_argument("--profile-per-page-limit", type=int, default=8)
    parser.add_argument("--min-accuracy", type=float, default=0.98)
    parser.add_argument("--max-wrong", type=int, default=0)
    parser.add_argument("--max-unreadable", type=int, default=0)
    return parser


def main() -> int:
    run(build_parser().parse_args())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
