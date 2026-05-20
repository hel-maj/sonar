from __future__ import annotations

import argparse
import json
import time
from pathlib import Path
from typing import Any

from sonar.fishing.memory_reeling import MemoryReelingTracker, ModuleInfo
from sonar.paths import PROJECT_DIR
from sonar.tools.build_inventory_memory_anchors import _hex, _scan_signature
from sonar.tools.probe_inventory_memory import _collect_regions_limited
from sonar.tools.record_reeling_memory import NullInputController


def _latest_anchors(report_dir: Path) -> Path | None:
    paths = sorted(report_dir.glob("inventory_memory_anchors_*.json"), key=lambda path: path.stat().st_mtime, reverse=True)
    for path in paths:
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            continue
        if data.get("kind") == "sonar_inventory_memory_anchors":
            return path
    return None


def _parse_addr(value: str | int | None) -> int | None:
    if value is None:
        return None
    if isinstance(value, int):
        return value
    return int(value, 16) if value.startswith("0x") else int(value)


def _module_by_name(modules: list[ModuleInfo], name: str | None) -> ModuleInfo | None:
    if not name:
        return None
    wanted = name.lower()
    for module in modules:
        if module.name.lower() == wanted:
            return module
    return None


def _read_byte(tracker: MemoryReelingTracker, addr: int) -> int | None:
    data = tracker._read(addr, 1)
    return None if data is None else data[0]


def _scan_signature_bases(
    tracker: MemoryReelingTracker,
    anchors: dict[str, Any],
    max_total_mb: int,
    max_region_mb: int,
    per_signature_limit: int,
) -> tuple[dict[int, int], list[dict[str, Any]]]:
    signatures = anchors.get("signatures", [])
    if not signatures:
        return {}, []
    regions = _collect_regions_limited(tracker, max_total_mb, max_region_mb)
    base_votes: dict[int, int] = {}
    details: list[dict[str, Any]] = []
    for signature in signatures:
        pattern = bytes.fromhex(str(signature["bytes_hex"]))
        mask = bytes.fromhex(str(signature["mask_hex"]))
        matches = _scan_signature(tracker, regions, pattern, mask, per_signature_limit)
        inferred_bases = [match - int(signature["window_rel"]) for match in matches]
        for base in inferred_bases:
            base_votes[base] = base_votes.get(base, 0) + 1
        details.append(
            {
                "candidate_rel": signature.get("candidate_rel"),
                "matches": [_hex(match) for match in matches],
                "inferred_bases": [_hex(base) for base in inferred_bases],
            }
        )
    return base_votes, details


def _candidates_for_base(anchors: dict[str, Any], base: int) -> list[dict[str, Any]]:
    return [
        {
            "addr": _hex(base + int(item["rel"])),
            "closed_value": int(item["closed_value"]),
            "open_value": int(item["open_value"]),
            "weight": float(item.get("weight", 1.0)),
        }
        for item in anchors.get("cluster_candidates", [])
    ]


def _resolve_by_module_pointers(
    tracker: MemoryReelingTracker,
    modules: list[ModuleInfo],
    anchors: dict[str, Any],
) -> list[dict[str, Any]]:
    resolved: list[dict[str, Any]] = []
    for item in anchors.get("pointers", []):
        if not item.get("module_rooted"):
            continue
        module = _module_by_name(modules, item.get("source_module"))
        source_offset = item.get("source_module_offset")
        if module is None or source_offset is None:
            continue
        source_addr = module.base + int(source_offset)
        value = tracker._u64(source_addr)
        if value is None:
            continue
        target_delta = int(item.get("target_delta", 0))
        target_addr = value + target_delta
        original_target = _parse_addr(item.get("target_addr"))
        resolved.append(
            {
                "source_addr": _hex(source_addr),
                "source_module": module.name,
                "points_to": _hex(value),
                "target_addr": _hex(target_addr),
                "original_target_addr": _hex(original_target),
                "target_delta": target_delta,
            }
        )
    return resolved


def _candidate_votes(tracker: MemoryReelingTracker, candidates: list[dict[str, Any]]) -> dict[str, Any]:
    open_votes = 0.0
    closed_votes = 0.0
    matched = 0
    unreadable = 0
    for candidate in candidates:
        addr = _parse_addr(candidate.get("addr"))
        if addr is None:
            continue
        value = _read_byte(tracker, addr)
        if value is None:
            unreadable += 1
            continue
        weight = float(candidate.get("weight", 1.0))
        if value == int(candidate["open_value"]):
            open_votes += weight
            matched += 1
        elif value == int(candidate["closed_value"]):
            closed_votes += weight
            matched += 1
    total = open_votes + closed_votes
    state = "unknown"
    confidence = 0.0
    if matched and total > 0:
        confidence = max(open_votes, closed_votes) / total
        if confidence >= 0.85:
            state = "open" if open_votes > closed_votes else "closed"
    return {
        "state": state,
        "confidence": confidence,
        "open_votes": open_votes,
        "closed_votes": closed_votes,
        "matched": matched,
        "unreadable": unreadable,
    }


def _write_resolved_profile(
    path: Path,
    anchors: dict[str, Any],
    candidates: list[dict[str, Any]],
    tracker: MemoryReelingTracker,
    method: str,
) -> Path:
    stamp = int(time.time())
    out_path = path.parent / f"inventory_memory_profile_{stamp}.json"
    profile = {
        "kind": "sonar_inventory_memory_profile",
        "version": 1,
        "created_at": time.time(),
        "process": anchors.get("process", "gta5.exe"),
        "pid": tracker.pid,
        "resolved_from": str(path),
        "resolve_method": method,
        "candidates": candidates,
    }
    out_path.write_text(json.dumps(profile, ensure_ascii=False, indent=2), encoding="utf-8")
    return out_path


def run(args: argparse.Namespace) -> Path | None:
    report_dir = Path(args.report_dir or PROJECT_DIR / "logs" / "memory_snapshots")
    anchor_path = Path(args.anchors) if args.anchors else _latest_anchors(report_dir)
    if anchor_path is None:
        raise RuntimeError("Inventory memory anchors were not found. Run build_inventory_memory_anchors first.")
    anchors = json.loads(anchor_path.read_text(encoding="utf-8"))
    tracker = MemoryReelingTracker(args.process or anchors.get("process", "gta5.exe"), input_controller=NullInputController(), log_callback=print)
    tracker.start()
    time.sleep(0.5)
    if not tracker.handle:
        raise RuntimeError("Could not open process memory")
    resolved_profile_path: Path | None = None
    try:
        modules = tracker._get_modules()
        base_votes, signature_details = _scan_signature_bases(
            tracker,
            anchors,
            max_total_mb=args.signature_scan_mb,
            max_region_mb=args.signature_scan_region_mb,
            per_signature_limit=args.signature_match_limit,
        )
        resolved_candidates: list[dict[str, Any]] = []
        method = "none"
        base: int | None = None
        signature_vote_report: dict[int, dict[str, Any]] = {}
        for candidate_base, signature_votes in sorted(base_votes.items(), key=lambda item: item[1], reverse=True)[: args.base_candidates]:
            if signature_votes < args.min_signature_votes:
                continue
            candidate_set = _candidates_for_base(anchors, candidate_base)
            candidate_vote = _candidate_votes(tracker, candidate_set)
            signature_vote_report[candidate_base] = {"signature_votes": signature_votes, "candidate_votes": candidate_vote}
            matched = int(candidate_vote.get("matched", 0))
            confidence = float(candidate_vote.get("confidence", 0.0))
            min_matched = max(args.min_candidate_votes, int(len(candidate_set) * args.min_candidate_ratio + 0.999))
            if matched >= min_matched and confidence >= args.min_candidate_confidence:
                if base is None:
                    base = candidate_base
                else:
                    current = signature_vote_report[base]["candidate_votes"]
                    current_key = (
                        int(current.get("matched", 0)),
                        float(current.get("confidence", 0.0)),
                        int(signature_vote_report[base]["signature_votes"]),
                    )
                    new_key = (matched, confidence, signature_votes)
                    if new_key > current_key:
                        base = candidate_base
        if base is not None:
            method = "signature_cluster"
            resolved_candidates = _candidates_for_base(anchors, base)
        pointer_resolved = _resolve_by_module_pointers(tracker, modules, anchors)
        if not resolved_candidates and pointer_resolved:
            method = "module_pointer"
            original_by_addr = {
                _parse_addr(item.get("addr")): item
                for item in anchors.get("cluster_candidates", [])
                if _parse_addr(item.get("addr")) is not None
            }
            seen: set[int] = set()
            for item in pointer_resolved:
                original = original_by_addr.get(_parse_addr(item.get("original_target_addr")))
                target_addr = _parse_addr(item.get("target_addr"))
                if original is None or target_addr is None or target_addr in seen:
                    continue
                seen.add(target_addr)
                resolved_candidates.append(
                    {
                        "addr": _hex(target_addr),
                        "closed_value": int(original["closed_value"]),
                        "open_value": int(original["open_value"]),
                        "weight": float(original.get("weight", 1.0)),
                    }
                )
        votes = _candidate_votes(tracker, resolved_candidates) if resolved_candidates else {}
        if resolved_candidates and args.write_profile:
            resolved_profile_path = _write_resolved_profile(anchor_path, anchors, resolved_candidates, tracker, method)
    finally:
        tracker.stop()
    out_path = anchor_path.with_name(f"{anchor_path.stem}.validation_{int(time.time())}.json")
    report = {
        "kind": "sonar_inventory_memory_anchor_validation",
        "created_at": time.time(),
        "anchors": str(anchor_path),
        "process": args.process or anchors.get("process", "gta5.exe"),
        "pid": tracker.pid,
        "signature_base": _hex(base),
        "signature_base_votes": {_hex(key): value for key, value in sorted(base_votes.items(), key=lambda item: item[1], reverse=True)},
        "signature_vote_report": {
            _hex(key): value for key, value in sorted(signature_vote_report.items(), key=lambda item: item[1]["signature_votes"], reverse=True)
        },
        "signature_details": signature_details,
        "module_pointer_resolved": pointer_resolved,
        "resolved_candidate_count": len(resolved_candidates),
        "resolved_candidates": resolved_candidates,
        "candidate_votes": votes,
        "written_profile": None if resolved_profile_path is None else str(resolved_profile_path),
    }
    out_path.write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
    print(f"signature_base={_hex(base)} votes={report['signature_base_votes']}")
    print(f"module_pointer_resolved={len(pointer_resolved)}")
    print(f"resolved_candidates={len(resolved_candidates)} votes={votes}")
    if resolved_profile_path is not None:
        print(f"Saved resolved profile: {resolved_profile_path}")
    print(f"Saved validation: {out_path}")
    return resolved_profile_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Validate inventory memory anchors in the current GTA process.")
    parser.add_argument("--process", default=None)
    parser.add_argument("--anchors", default=None)
    parser.add_argument("--report-dir", default=None)
    parser.add_argument("--signature-scan-mb", type=int, default=512)
    parser.add_argument("--signature-scan-region-mb", type=int, default=16)
    parser.add_argument("--signature-match-limit", type=int, default=12)
    parser.add_argument("--base-candidates", type=int, default=12)
    parser.add_argument("--min-signature-votes", type=int, default=2)
    parser.add_argument("--min-candidate-votes", type=int, default=6)
    parser.add_argument("--min-candidate-ratio", type=float, default=0.75)
    parser.add_argument("--min-candidate-confidence", type=float, default=0.85)
    parser.add_argument("--write-profile", action="store_true")
    return parser


def main() -> None:
    run(build_parser().parse_args())


if __name__ == "__main__":
    main()
