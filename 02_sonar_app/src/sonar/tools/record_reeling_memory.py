from __future__ import annotations

import argparse
import json
import time
from datetime import datetime
from pathlib import Path
from typing import Any

import numpy as np

from sonar.fishing.memory_reeling import FISH_MODEL_HASH, FISH_POS_OFFSETS, MemoryReelingTracker, POS_OFFSETS
from sonar.paths import PROJECT_DIR


ENTITY_OFFSETS = (0x30, 0x40, 0x50, 0x60, 0x90, 0x110, 0x120, 0x130, 0x160, 0x180, 0x1A0, 0x1D0, 0x200)


class NullInputController:
    def key_down(self, key: str) -> None:
        return None

    def key_up(self, key: str) -> None:
        return None

    def press_key(self, key: str, duration: float = 0.05) -> None:
        return None

    def click(self, x: int, y: int) -> None:
        return None

    def move_to(self, x: int, y: int) -> None:
        return None

    def sleep(self, seconds: float) -> None:
        time.sleep(seconds)


def _key_label() -> int:
    import win32api

    a_down = bool(win32api.GetAsyncKeyState(ord("A")) & 0x8000)
    d_down = bool(win32api.GetAsyncKeyState(ord("D")) & 0x8000)
    if a_down and not d_down:
        return -1
    if d_down and not a_down:
        return 1
    return 0


def _read_bytes(tracker: MemoryReelingTracker, addr: int | None, size: int) -> np.ndarray:
    out = np.zeros(size, dtype=np.uint8)
    if not addr:
        return out
    data = tracker._read(addr, size)
    if not data:
        return out
    chunk = np.frombuffer(data[:size], dtype=np.uint8)
    out[: len(chunk)] = chunk
    return out


def _pos_candidates(tracker: MemoryReelingTracker, addr: int | None, offsets: tuple[int, ...]) -> np.ndarray:
    out = np.full((len(offsets), 3), np.nan, dtype=np.float32)
    if not addr:
        return out
    for index, offset in enumerate(offsets):
        item = tracker._read_pos_at_offsets(addr, (offset,))
        if item is not None:
            out[index] = np.array(item[0], dtype=np.float32)
    return out


def _ped_lists(tracker: MemoryReelingTracker) -> list[tuple[int, int]]:
    p_iface = tracker.replay_interface or tracker._find_replay_interface_global()
    if p_iface is None:
        return []
    lists: list[tuple[int, int]] = []
    for ri_off in (0x8, 0x20, 0x18, 0x10, 0x28):
        p_ped_iface = tracker._u64(p_iface + ri_off)
        if not tracker._is_ptr(p_ped_iface):
            continue
        for list_off, max_off in ((0x0, 0x18), (0x8, 0x18), (0x30, 0x38), (0x100, 0x108), (0x108, 0x110), (0x110, 0x118)):
            p_ped_list = tracker._u64(p_ped_iface + list_off)
            max_peds = tracker._i32(p_ped_iface + max_off)
            if tracker._is_ptr(p_ped_list) and p_ped_list % 8 == 0 and max_peds is not None and 0 < max_peds <= 2048:
                lists.append((p_ped_list, max_peds))
    return lists


def _collect_candidates(tracker: MemoryReelingTracker, limit: int) -> list[dict[str, Any]]:
    if tracker.player_addr is None:
        tracker._retry_find_targets()
    if tracker.fish_addr is None:
        tracker._retry_find_fish()
    player_item = tracker._read_pos_at_offsets(tracker.player_addr, POS_OFFSETS) if tracker.player_addr else None
    if player_item is None:
        return []
    player_pos = player_item[0]
    px, py, pz = player_pos
    candidates: dict[int, dict[str, Any]] = {}
    if tracker.fish_addr:
        candidates[tracker.fish_addr] = {"addr": tracker.fish_addr, "dist": np.inf, "hash": tracker._read_entity_hash(tracker.fish_addr) or 0}
    for p_ped_list, max_peds in _ped_lists(tracker):
        for i in range(min(max_peds, 2048)):
            ent_addr = tracker._u64(p_ped_list + i * 0x10)
            if not tracker._is_ptr(ent_addr) or ent_addr == tracker.player_addr:
                continue
            signal = tracker._read_fish_candidate_signal(ent_addr, player_pos)
            if signal is not None:
                d2, entity_hash, _pos, _source = signal
                dist = float(d2**0.5)
                old = candidates.get(ent_addr)
                if old is None or dist < old["dist"]:
                    candidates[ent_addr] = {"addr": ent_addr, "dist": dist, "hash": int(entity_hash or 0)}
                continue
            entity_hash = tracker._read_entity_hash(ent_addr) or 0
            pos_item = tracker._read_fish_pos_relative(ent_addr, player_pos) if entity_hash == FISH_MODEL_HASH else tracker._read_pos_at_offsets(ent_addr, POS_OFFSETS)
            if pos_item is None:
                continue
            pos = pos_item[0]
            dx, dy, dz = pos[0] - px, pos[1] - py, pos[2] - pz
            dist = float((dx * dx + dy * dy + dz * dz) ** 0.5)
            if not (0.5 < dist < 45.0):
                continue
            old = candidates.get(ent_addr)
            if old is None or dist < old["dist"]:
                candidates[ent_addr] = {"addr": ent_addr, "dist": dist, "hash": entity_hash}
    ordered = sorted(candidates.values(), key=lambda item: (0 if item["hash"] == FISH_MODEL_HASH else 1, item["dist"]))
    return ordered[:limit]


def record(args: argparse.Namespace) -> Path:
    out_dir = Path(args.out_dir or PROJECT_DIR / "logs" / "memory_snapshots")
    out_dir.mkdir(parents=True, exist_ok=True)
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    out_path = out_dir / f"reeling_memory_{stamp}.npz"
    tracker = MemoryReelingTracker(args.process, input_controller=NullInputController(), log_callback=print)
    tracker.start()
    time.sleep(0.5)
    timestamps: list[float] = []
    labels: list[int] = []
    player_addrs: list[int] = []
    fish_addrs: list[int] = []
    entity_addrs: list[list[int]] = []
    entity_hashes: list[list[int]] = []
    entity_distances: list[list[float]] = []
    player_bytes: list[np.ndarray] = []
    entity_bytes: list[np.ndarray] = []
    player_positions: list[np.ndarray] = []
    entity_positions: list[np.ndarray] = []
    started = time.perf_counter()
    next_sample = started
    print("Recording memory. Manually reel the fish and press the correct A/D keys.")
    print("The recorder only reads memory and keyboard state; it does not press anything.")
    try:
        while time.perf_counter() - started < args.duration:
            now = time.perf_counter()
            if now < next_sample:
                time.sleep(min(0.002, next_sample - now))
                continue
            next_sample += args.interval
            candidates = _collect_candidates(tracker, args.max_candidates)
            addrs = [int(item["addr"]) for item in candidates]
            hashes = [int(item["hash"]) for item in candidates]
            distances = [float(item["dist"]) for item in candidates]
            while len(addrs) < args.max_candidates:
                addrs.append(0)
                hashes.append(0)
                distances.append(np.nan)
            addrs = addrs[: args.max_candidates]
            hashes = hashes[: args.max_candidates]
            distances = distances[: args.max_candidates]
            timestamps.append(time.time())
            labels.append(_key_label())
            player_addrs.append(int(tracker.player_addr or 0))
            fish_addrs.append(int(tracker.fish_addr or 0))
            entity_addrs.append(addrs)
            entity_hashes.append(hashes)
            entity_distances.append(distances)
            player_bytes.append(_read_bytes(tracker, tracker.player_addr, args.bytes))
            entity_bytes.append(np.stack([_read_bytes(tracker, addr, args.bytes) for addr in addrs]))
            player_positions.append(_pos_candidates(tracker, tracker.player_addr, POS_OFFSETS))
            entity_positions.append(np.stack([_pos_candidates(tracker, addr, ENTITY_OFFSETS) for addr in addrs]))
            if len(timestamps) % max(1, int(1 / args.interval)) == 0:
                print(f"samples={len(timestamps)} label={labels[-1]} candidates={sum(1 for addr in addrs if addr)}")
    finally:
        tracker.stop()
    metadata = {
        "process": args.process,
        "duration": args.duration,
        "interval": args.interval,
        "bytes": args.bytes,
        "max_candidates": args.max_candidates,
        "entity_offsets": ENTITY_OFFSETS,
        "fish_pos_offsets": FISH_POS_OFFSETS,
        "pos_offsets": POS_OFFSETS,
        "label_meaning": {"-1": "A pressed", "0": "none/both", "1": "D pressed"},
    }
    np.savez_compressed(
        out_path,
        timestamps=np.array(timestamps, dtype=np.float64),
        key_labels=np.array(labels, dtype=np.int8),
        player_addrs=np.array(player_addrs, dtype=np.uint64),
        fish_addrs=np.array(fish_addrs, dtype=np.uint64),
        entity_addrs=np.array(entity_addrs, dtype=np.uint64),
        entity_hashes=np.array(entity_hashes, dtype=np.int64),
        entity_distances=np.array(entity_distances, dtype=np.float32),
        player_bytes=np.stack(player_bytes).astype(np.uint8) if player_bytes else np.zeros((0, args.bytes), dtype=np.uint8),
        entity_bytes=np.stack(entity_bytes).astype(np.uint8) if entity_bytes else np.zeros((0, args.max_candidates, args.bytes), dtype=np.uint8),
        player_positions=np.stack(player_positions).astype(np.float32) if player_positions else np.zeros((0, len(POS_OFFSETS), 3), dtype=np.float32),
        entity_positions=np.stack(entity_positions).astype(np.float32) if entity_positions else np.zeros((0, args.max_candidates, len(ENTITY_OFFSETS), 3), dtype=np.float32),
        metadata=json.dumps(metadata, ensure_ascii=False),
    )
    print(f"Saved: {out_path}")
    return out_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Record passive GTA memory samples during manual reeling.")
    parser.add_argument("--process", default="gta5.exe")
    parser.add_argument("--duration", type=float, default=45.0)
    parser.add_argument("--interval", type=float, default=0.02)
    parser.add_argument("--bytes", type=int, default=0x400)
    parser.add_argument("--max-candidates", type=int, default=8)
    parser.add_argument("--out-dir", default=None)
    return parser


def main() -> int:
    record(build_parser().parse_args())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
