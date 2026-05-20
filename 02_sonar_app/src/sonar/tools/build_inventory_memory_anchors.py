from __future__ import annotations

import argparse
import bisect
import json
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import numpy as np

from sonar.fishing.memory_reeling import MemoryReelingTracker, ModuleInfo, PTR_MAX, PTR_MIN
from sonar.paths import PROJECT_DIR
from sonar.tools.probe_inventory_memory import _collect_regions_limited
from sonar.tools.record_reeling_memory import NullInputController


@dataclass(frozen=True, slots=True)
class ProfileCandidate:
    addr: int
    closed_value: int
    open_value: int
    weight: float


def _hex(addr: int | None) -> str:
    return "None" if addr is None else f"0x{addr:X}"


def _parse_addr(value: str | int | None) -> int | None:
    if value is None:
        return None
    if isinstance(value, int):
        return value
    return int(value, 16) if value.startswith("0x") else int(value)


def _latest_profile(report_dir: Path) -> Path | None:
    paths = sorted(report_dir.glob("inventory_memory_profile_*.json"), key=lambda path: path.stat().st_mtime, reverse=True)
    return paths[0] if paths else None


def _load_profile(path: Path) -> tuple[dict[str, Any], list[ProfileCandidate]]:
    data = json.loads(path.read_text(encoding="utf-8"))
    candidates: list[ProfileCandidate] = []
    for item in data.get("candidates", []):
        addr_raw = item.get("addr")
        if addr_raw is None:
            continue
        addr = int(addr_raw, 16) if isinstance(addr_raw, str) else int(addr_raw)
        candidates.append(
            ProfileCandidate(
                addr=addr,
                closed_value=int(item["closed_value"]),
                open_value=int(item["open_value"]),
                weight=float(item.get("weight", item.get("accuracy", 1.0))),
            )
        )
    return data, candidates


def _main_cluster(candidates: list[ProfileCandidate], max_gap: int) -> list[ProfileCandidate]:
    if not candidates:
        return []
    ordered = sorted(candidates, key=lambda item: item.addr)
    clusters: list[list[ProfileCandidate]] = [[ordered[0]]]
    for candidate in ordered[1:]:
        if candidate.addr - clusters[-1][-1].addr <= max_gap:
            clusters[-1].append(candidate)
        else:
            clusters.append([candidate])
    clusters.sort(key=lambda items: (len(items), -(items[-1].addr - items[0].addr)), reverse=True)
    return clusters[0]


def _module_for_addr(modules: list[ModuleInfo], addr: int) -> ModuleInfo | None:
    for module in modules:
        if module.base <= addr < module.base + module.size:
            return module
    return None


def _mask_dynamic_bytes(
    window_start: int,
    data: bytes,
    cluster: list[ProfileCandidate],
    pointer_wildcards: bool,
) -> bytes:
    mask = bytearray(b"\x01" * len(data))
    window_end = window_start + len(data)
    for candidate in cluster:
        if window_start <= candidate.addr < window_end:
            mask[candidate.addr - window_start] = 0
    if pointer_wildcards:
        align = (8 - (window_start % 8)) % 8
        for index in range(align, max(0, len(data) - 7), 8):
            value = int.from_bytes(data[index : index + 8], "little", signed=False)
            if PTR_MIN <= value <= PTR_MAX:
                mask[index : index + 8] = b"\x00" * 8
    return bytes(mask)


def _longest_exact_run(mask: bytes) -> tuple[int, int]:
    best_start = 0
    best_len = 0
    cur_start = 0
    cur_len = 0
    for index, value in enumerate(mask):
        if value:
            if cur_len == 0:
                cur_start = index
            cur_len += 1
            if cur_len > best_len:
                best_start = cur_start
                best_len = cur_len
        else:
            cur_len = 0
    return best_start, best_len


def _find_masked_matches(data: bytes, pattern: bytes, mask: bytes, limit: int) -> list[int]:
    anchor_start, anchor_len = _longest_exact_run(mask)
    if anchor_len < 4:
        return []
    anchor = pattern[anchor_start : anchor_start + anchor_len]
    exact_indexes = [index for index, value in enumerate(mask) if value]
    matches: list[int] = []
    search_from = 0
    while len(matches) < limit:
        hit = data.find(anchor, search_from)
        if hit < 0:
            break
        start = hit - anchor_start
        if start >= 0 and start + len(pattern) <= len(data):
            if all(data[start + index] == pattern[index] for index in exact_indexes):
                matches.append(start)
        search_from = hit + 1
    return matches


def _scan_signature(
    tracker: MemoryReelingTracker,
    regions: list[tuple[int, int]],
    pattern: bytes,
    mask: bytes,
    limit: int,
) -> list[int]:
    matches: list[int] = []
    overlap = max(0, len(pattern) - 1)
    for start, end in regions:
        data = tracker._read(start, end - start)
        if not data:
            continue
        for offset in _find_masked_matches(data, pattern, mask, limit - len(matches)):
            matches.append(start + offset)
            if len(matches) >= limit:
                return matches
        if overlap and len(data) == end - start:
            # Regions are scanned whole by _collect_regions_limited, so overlap is
            # only needed for future chunked reads. Keep this path explicit.
            pass
    return matches


def _build_signatures(
    tracker: MemoryReelingTracker,
    cluster: list[ProfileCandidate],
    before: int,
    after: int,
    limit: int,
    min_exact_run: int,
    pointer_wildcards: bool,
    samples: int,
    sample_interval: float,
) -> list[dict[str, Any]]:
    if not cluster:
        return []
    base = min(candidate.addr for candidate in cluster)
    if limit < len(cluster):
        indexes = np.linspace(0, len(cluster) - 1, limit, dtype=np.int32).tolist()
        selected = [cluster[index] for index in sorted(set(int(index) for index in indexes))]
    else:
        selected = cluster
    out: list[dict[str, Any]] = []
    for candidate in selected:
        window_start = candidate.addr - before
        size = before + 1 + after
        reads: list[bytes] = []
        for sample_index in range(max(1, samples)):
            data = tracker._read(window_start, size)
            if data is None or len(data) != size:
                reads = []
                break
            reads.append(data)
            if sample_index + 1 < samples:
                time.sleep(sample_interval)
        if not reads:
            continue
        data = reads[0]
        mask = _mask_dynamic_bytes(window_start, data, cluster, pointer_wildcards)
        if len(reads) > 1:
            mutable = bytearray(mask)
            for index in range(size):
                first = data[index]
                if any(read[index] != first for read in reads[1:]):
                    mutable[index] = 0
            mask = bytes(mutable)
        run_start, run_len = _longest_exact_run(mask)
        if run_len < min_exact_run:
            continue
        out.append(
            {
                "candidate_addr": _hex(candidate.addr),
                "candidate_rel": candidate.addr - base,
                "window_start": _hex(window_start),
                "window_rel": window_start - base,
                "size": size,
                "value_offset": before,
                "bytes_hex": data.hex(),
                "mask_hex": mask.hex(),
                "exact_bytes": int(sum(mask)),
                "wildcards": int(len(mask) - sum(mask)),
                "longest_exact_run": {"offset": run_start, "size": run_len},
                "sample_count": len(reads),
                "closed_value": candidate.closed_value,
                "open_value": candidate.open_value,
                "weight": candidate.weight,
            }
        )
    return out


def _region_sources(
    tracker: MemoryReelingTracker,
    modules: list[ModuleInfo],
    max_heap_mb: int,
    max_heap_region_mb: int,
    max_module_mb: int,
) -> list[tuple[int, int, str]]:
    sources: list[tuple[int, int, str]] = []
    for module in modules:
        if module.size <= max_module_mb * 1024 * 1024:
            for start, end in tracker._collect_regions(module.base, module.base + module.size):
                sources.append((start, end, f"module:{module.name}"))
    for start, end in _collect_regions_limited(tracker, max_heap_mb, max_heap_region_mb):
        sources.append((start, end, "heap"))
    return sources


def _scan_pointer_sources(
    tracker: MemoryReelingTracker,
    modules: list[ModuleInfo],
    targets: list[int],
    max_offset: int,
    max_heap_mb: int,
    max_heap_region_mb: int,
    max_module_mb: int,
    limit: int,
) -> list[dict[str, Any]]:
    if not targets:
        return []
    targets_sorted = sorted(set(targets))
    min_value = max(0, min(targets_sorted) - max_offset)
    max_value = max(targets_sorted)
    hits: list[dict[str, Any]] = []
    sources = _region_sources(tracker, modules, max_heap_mb, max_heap_region_mb, max_module_mb)
    for start, end, source_kind in sources:
        data = tracker._read(start, end - start)
        if not data or len(data) < 8:
            continue
        align = (8 - (start % 8)) % 8
        if align >= len(data) - 7:
            continue
        arr = np.frombuffer(data[align : len(data) - ((len(data) - align) % 8)], dtype="<u8")
        candidate_indexes = np.where((arr >= min_value) & (arr <= max_value))[0]
        for array_index in candidate_indexes.tolist():
            value = int(arr[array_index])
            left = bisect.bisect_left(targets_sorted, value)
            right = bisect.bisect_right(targets_sorted, value + max_offset)
            if left == right:
                continue
            source_addr = start + align + array_index * 8
            source_module = _module_for_addr(modules, source_addr)
            for target in targets_sorted[left:right]:
                delta = target - value
                if delta < 0 or delta > max_offset:
                    continue
                hits.append(
                    {
                        "source_addr": _hex(source_addr),
                        "source_kind": source_kind,
                        "source_module": None if source_module is None else source_module.name,
                        "source_module_offset": None if source_module is None else source_addr - source_module.base,
                        "points_to": _hex(value),
                        "target_addr": _hex(target),
                        "target_delta": delta,
                        "module_rooted": source_module is not None,
                    }
                )
                if len(hits) >= limit:
                    return hits
    hits.sort(key=lambda item: (not item["module_rooted"], item["source_kind"], item["target_delta"]))
    return hits


def _build_pointer_chains(
    tracker: MemoryReelingTracker,
    modules: list[ModuleInfo],
    leaf_hits: list[dict[str, Any]],
    max_depth: int,
    max_offset: int,
    max_heap_mb: int,
    max_heap_region_mb: int,
    max_module_mb: int,
    scan_limit: int,
    frontier_limit: int,
    chain_limit: int,
) -> list[dict[str, Any]]:
    if max_depth <= 1 or not leaf_hits:
        return []
    chains: list[dict[str, Any]] = []
    frontier: list[dict[str, Any]] = []
    seen_frontier: set[tuple[int, str]] = set()
    for hit in leaf_hits:
        source_addr = _parse_addr(hit.get("source_addr"))
        if source_addr is None or hit.get("module_rooted"):
            continue
        key = (source_addr, json.dumps(hit, sort_keys=True))
        if key in seen_frontier:
            continue
        seen_frontier.add(key)
        frontier.append({"target": source_addr, "path": [hit]})
        if len(frontier) >= frontier_limit:
            break

    for depth in range(2, max_depth + 1):
        if not frontier:
            break
        target_to_states: dict[int, list[dict[str, Any]]] = {}
        for state in frontier:
            target_to_states.setdefault(int(state["target"]), []).append(state)
        parent_hits = _scan_pointer_sources(
            tracker,
            modules,
            targets=list(target_to_states),
            max_offset=max_offset,
            max_heap_mb=max_heap_mb,
            max_heap_region_mb=max_heap_region_mb,
            max_module_mb=max_module_mb,
            limit=scan_limit,
        )
        next_frontier: list[dict[str, Any]] = []
        seen_next: set[tuple[int, str]] = set()
        for parent in parent_hits:
            parent_target = _parse_addr(parent.get("target_addr"))
            if parent_target is None:
                continue
            states = target_to_states.get(parent_target, [])
            for state in states:
                path = [parent, *state["path"]]
                if parent.get("module_rooted"):
                    chains.append({"depth": depth, "path": path})
                    if len(chains) >= chain_limit:
                        return chains
                    continue
                parent_source = _parse_addr(parent.get("source_addr"))
                if parent_source is None:
                    continue
                key = (parent_source, json.dumps(path, sort_keys=True))
                if key in seen_next:
                    continue
                seen_next.add(key)
                next_frontier.append({"target": parent_source, "path": path})
                if len(next_frontier) >= frontier_limit:
                    break
            if len(next_frontier) >= frontier_limit:
                break
        frontier = next_frontier
    return chains


def _scan_current_signature_votes(
    tracker: MemoryReelingTracker,
    signatures: list[dict[str, Any]],
    regions: list[tuple[int, int]],
    per_signature_limit: int,
) -> tuple[list[dict[str, Any]], dict[str, int]]:
    base_votes: dict[int, int] = {}
    summaries: list[dict[str, Any]] = []
    for signature in signatures:
        pattern = bytes.fromhex(str(signature["bytes_hex"]))
        mask = bytes.fromhex(str(signature["mask_hex"]))
        matches = _scan_signature(tracker, regions, pattern, mask, per_signature_limit)
        inferred = [match - int(signature["window_rel"]) for match in matches]
        for base in inferred:
            base_votes[base] = base_votes.get(base, 0) + 1
        summaries.append(
            {
                "candidate_rel": signature["candidate_rel"],
                "matches": [_hex(match) for match in matches],
                "inferred_bases": [_hex(base) for base in inferred],
            }
        )
    return summaries, {_hex(base): votes for base, votes in sorted(base_votes.items(), key=lambda item: item[1], reverse=True)}


def run(args: argparse.Namespace) -> Path:
    report_dir = Path(args.report_dir or PROJECT_DIR / "logs" / "memory_snapshots")
    profile_path = Path(args.profile) if args.profile else _latest_profile(report_dir)
    if profile_path is None:
        raise RuntimeError("Inventory memory profile was not found. Run probe_inventory_memory first.")
    profile, candidates = _load_profile(profile_path)
    if not candidates:
        raise RuntimeError(f"No candidates in profile: {profile_path}")

    cluster = _main_cluster(candidates, args.cluster_gap)
    cluster_base = min(candidate.addr for candidate in cluster)
    cluster_end = max(candidate.addr for candidate in cluster)
    tracker = MemoryReelingTracker(args.process, input_controller=NullInputController(), log_callback=print)
    tracker.start()
    time.sleep(0.5)
    if not tracker.handle:
        raise RuntimeError("Could not open process memory")
    try:
        modules = tracker._get_modules()
        signatures = _build_signatures(
            tracker,
            cluster,
            before=args.signature_before,
            after=args.signature_after,
            limit=args.signature_limit,
            min_exact_run=args.min_exact_run,
            pointer_wildcards=not args.no_pointer_wildcards,
            samples=args.signature_samples,
            sample_interval=args.signature_sample_interval,
        )
        signature_scan: list[dict[str, Any]] = []
        signature_base_votes: dict[str, int] = {}
        if signatures and not args.skip_signature_scan:
            regions = _collect_regions_limited(tracker, args.signature_scan_mb, args.signature_scan_region_mb)
            signature_scan, signature_base_votes = _scan_current_signature_votes(
                tracker, signatures, regions, args.signature_match_limit
            )
        targets = [cluster_base] + [candidate.addr for candidate in cluster]
        pointers = _scan_pointer_sources(
            tracker,
            modules,
            targets=targets,
            max_offset=args.pointer_max_offset,
            max_heap_mb=args.pointer_heap_mb,
            max_heap_region_mb=args.pointer_heap_region_mb,
            max_module_mb=args.pointer_module_mb,
            limit=args.pointer_limit,
        )
        pointer_chains = _build_pointer_chains(
            tracker,
            modules,
            pointers,
            max_depth=args.pointer_depth,
            max_offset=args.pointer_max_offset,
            max_heap_mb=args.pointer_heap_mb,
            max_heap_region_mb=args.pointer_heap_region_mb,
            max_module_mb=args.pointer_module_mb,
            scan_limit=args.pointer_limit,
            frontier_limit=args.pointer_frontier_limit,
            chain_limit=args.pointer_chain_limit,
        )
    finally:
        tracker.stop()

    out_dir = report_dir
    out_dir.mkdir(parents=True, exist_ok=True)
    stamp = int(time.time())
    out_path = out_dir / f"inventory_memory_anchors_{stamp}.json"
    payload = {
        "kind": "sonar_inventory_memory_anchors",
        "version": 1,
        "created_at": time.time(),
        "process": args.process,
        "pid": tracker.pid,
        "profile_path": str(profile_path),
        "profile_created_at": profile.get("created_at"),
        "candidate_count": len(candidates),
        "cluster_base": _hex(cluster_base),
        "cluster_end": _hex(cluster_end),
        "cluster_size": cluster_end - cluster_base + 1,
        "cluster_candidate_count": len(cluster),
        "cluster_candidates": [
            {
                "addr": _hex(candidate.addr),
                "rel": candidate.addr - cluster_base,
                "closed_value": candidate.closed_value,
                "open_value": candidate.open_value,
                "weight": candidate.weight,
            }
            for candidate in cluster
        ],
        "modules": [{"name": module.name, "base": _hex(module.base), "size": module.size} for module in modules],
        "signatures": signatures,
        "signature_scan": signature_scan,
        "signature_base_votes": signature_base_votes,
        "pointers": pointers,
        "pointer_chains": pointer_chains,
    }
    out_path.write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")
    txt_path = out_path.with_suffix(".txt")
    module_pointers = sum(1 for item in pointers if item.get("module_rooted"))
    module_chains = sum(1 for item in pointer_chains if item.get("path") and item["path"][0].get("module_rooted"))
    lines = [
        "Inventory memory anchors",
        f"profile={profile_path}",
        f"process={args.process} pid={tracker.pid}",
        f"cluster={_hex(cluster_base)}..{_hex(cluster_end)} candidates={len(cluster)}/{len(candidates)}",
        f"signatures={len(signatures)}",
        f"signature_base_votes={signature_base_votes}",
        f"pointers={len(pointers)} module_rooted={module_pointers}",
        f"pointer_chains={len(pointer_chains)} module_rooted={module_chains}",
        "Top pointers:",
    ]
    for item in pointers[:20]:
        lines.append(
            f"source={item['source_addr']} kind={item['source_kind']} module={item['source_module']} "
            f"module_off={item['source_module_offset']} points_to={item['points_to']} "
            f"target={item['target_addr']} delta=0x{int(item['target_delta']):X}"
        )
    if pointer_chains:
        lines.append("Top pointer chains:")
        for chain in pointer_chains[:10]:
            parts = []
            for hop in chain.get("path", []):
                source_module = hop.get("source_module")
                source = f"{source_module}+0x{int(hop['source_module_offset']):X}" if source_module else hop["source_addr"]
                parts.append(f"{source} -> {hop['points_to']} +0x{int(hop['target_delta']):X}")
            lines.append(f"depth={chain['depth']} " + " ; ".join(parts))
    txt_path.write_text("\n".join(lines), encoding="utf-8")
    print("\n".join(lines[:30]))
    print(f"Saved anchors: {out_path}")
    print(f"Saved summary: {txt_path}")
    return out_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Build signature and pointer candidates for inventory memory profile addresses.")
    parser.add_argument("--process", default="gta5.exe")
    parser.add_argument("--profile", default=None)
    parser.add_argument("--report-dir", default=None)
    parser.add_argument("--cluster-gap", type=lambda text: int(text, 0), default=0x2000)
    parser.add_argument("--signature-before", type=int, default=96)
    parser.add_argument("--signature-after", type=int, default=32)
    parser.add_argument("--signature-limit", type=int, default=16)
    parser.add_argument("--signature-samples", type=int, default=5)
    parser.add_argument("--signature-sample-interval", type=float, default=0.05)
    parser.add_argument("--min-exact-run", type=int, default=16)
    parser.add_argument("--no-pointer-wildcards", action="store_true")
    parser.add_argument("--skip-signature-scan", action="store_true")
    parser.add_argument("--signature-scan-mb", type=int, default=512)
    parser.add_argument("--signature-scan-region-mb", type=int, default=16)
    parser.add_argument("--signature-match-limit", type=int, default=8)
    parser.add_argument("--pointer-max-offset", type=lambda text: int(text, 0), default=0x10000)
    parser.add_argument("--pointer-heap-mb", type=int, default=512)
    parser.add_argument("--pointer-heap-region-mb", type=int, default=16)
    parser.add_argument("--pointer-module-mb", type=int, default=512)
    parser.add_argument("--pointer-limit", type=int, default=200)
    parser.add_argument("--pointer-depth", type=int, default=2)
    parser.add_argument("--pointer-frontier-limit", type=int, default=80)
    parser.add_argument("--pointer-chain-limit", type=int, default=50)
    return parser


def main() -> None:
    run(build_parser().parse_args())


if __name__ == "__main__":
    main()
