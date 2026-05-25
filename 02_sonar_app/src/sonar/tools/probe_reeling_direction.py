from __future__ import annotations

import argparse
import ctypes
import json
import math
import time
from datetime import datetime
from pathlib import Path
from typing import Any

import numpy as np

from sonar.fishing.memory_reeling import (
    DIRECTION_EPS,
    FISH_DIRECTION_FIELDS,
    FISH_MODEL_HASH,
    FISH_POS_OFFSETS,
    FISH_PRIMARY_DIRECTION_OFFSETS,
    MemoryReelingTracker,
    POS_OFFSETS,
    ReelingState,
)
from sonar.paths import PROJECT_DIR
from sonar.tools.record_reeling_memory import NullInputController


ENTITY_POS_OFFSETS = (
    0x30,
    0x40,
    0x50,
    0x60,
    0x68,
    0x70,
    0x80,
    0x90,
    0x110,
    0x120,
    0x130,
    0x160,
    0x180,
    0x1A0,
    0x1D0,
    0x200,
    0x300,
    0x310,
)
VK_A = 0x41
VK_D = 0x44


def _key_down(vk: int) -> bool:
    if not hasattr(ctypes, "windll"):
        return False
    return bool(ctypes.windll.user32.GetAsyncKeyState(vk) & 0x8000)


def _keyboard_snapshot() -> tuple[int, bool, bool]:
    a_down = _key_down(VK_A)
    d_down = _key_down(VK_D)
    if a_down and not d_down:
        return -1, a_down, d_down
    if d_down and not a_down:
        return 1, a_down, d_down
    if a_down and d_down:
        return 2, a_down, d_down
    return 0, a_down, d_down


def _command_label_from_state(state: ReelingState, held_key: str | None) -> int:
    action = state.action or ""
    if action.startswith("hold_a") or held_key == "a":
        return -1
    if action.startswith("hold_d") or held_key == "d":
        return 1
    move_val = state.move_val
    if move_val is None:
        return 0
    if move_val > DIRECTION_EPS:
        return 1
    if move_val < -DIRECTION_EPS:
        return -1
    return 0


def _read_bytes(tracker: MemoryReelingTracker, addr: int | None, size: int) -> np.ndarray:
    out = np.zeros(size, dtype=np.uint8)
    if not addr or size <= 0:
        return out
    data = tracker._read(addr, size)
    if not data:
        return out
    chunk = np.frombuffer(data[:size], dtype=np.uint8)
    out[: len(chunk)] = chunk
    return out


def _pos_candidates(
    tracker: MemoryReelingTracker,
    addr: int | None,
    offsets: tuple[int, ...],
) -> np.ndarray:
    out = np.full((len(offsets), 3), np.nan, dtype=np.float32)
    if not addr:
        return out
    for index, offset in enumerate(offsets):
        item = tracker._read_pos_at_offsets(addr, (offset,))
        if item is not None:
            out[index] = np.array(item[0], dtype=np.float32)
    return out


def _direction_values(tracker: MemoryReelingTracker, addr: int | None) -> np.ndarray:
    out = np.full(len(FISH_DIRECTION_FIELDS), np.nan, dtype=np.float32)
    if not addr:
        return out
    for index, (offset, _eps, _polarity) in enumerate(FISH_DIRECTION_FIELDS):
        value = tracker._f32(addr + offset)
        if value is not None and math.isfinite(value) and abs(value) < 100000.0:
            out[index] = value
    return out


def _direction_snapshot(tracker: MemoryReelingTracker, fish_addr: int | None) -> dict[str, Any]:
    values: dict[str, float | None] = {}
    if not fish_addr:
        for offset, _eps, _polarity in FISH_DIRECTION_FIELDS:
            values[f"0x{offset:X}"] = None
        return {
            "selected_offset": None,
            "selected_raw": None,
            "selected_move": None,
            "values": values,
        }
    selected = tracker._read_fish_direction(
        fish_addr,
        tracker._fish_direction_offsets,
        tracker._blocked_direction_offsets,
    )
    for offset, _eps, polarity in FISH_DIRECTION_FIELDS:
        raw = tracker._f32(fish_addr + offset)
        values[f"0x{offset:X}"] = None if raw is None or not math.isfinite(raw) else raw * polarity
    if selected is None:
        return {
            "selected_offset": None,
            "selected_raw": None,
            "selected_move": None,
            "values": values,
        }
    selected_move, selected_offset, selected_raw = selected
    return {
        "selected_offset": f"0x{selected_offset:X}",
        "selected_raw": selected_raw,
        "selected_move": selected_move,
        "values": values,
    }


def _ped_lists(tracker: MemoryReelingTracker) -> list[tuple[int, int, int, int]]:
    p_iface = tracker.replay_interface or tracker._find_replay_interface_global()
    if p_iface is None:
        return []
    tracker.replay_interface = p_iface
    lists: list[tuple[int, int, int, int]] = []
    for ri_off in (0x8, 0x20, 0x18, 0x10, 0x28):
        p_ped_iface = tracker._u64(p_iface + ri_off)
        if not tracker._is_ptr(p_ped_iface):
            continue
        for list_off, max_off in (
            (0x0, 0x18),
            (0x8, 0x18),
            (0x30, 0x38),
            (0x100, 0x108),
            (0x108, 0x110),
            (0x110, 0x118),
        ):
            p_ped_list = tracker._u64(p_ped_iface + list_off)
            max_peds = tracker._i32(p_ped_iface + max_off)
            if (
                tracker._is_ptr(p_ped_list)
                and p_ped_list % 8 == 0
                and max_peds is not None
                and 0 < max_peds <= 2048
            ):
                lists.append((p_ped_list, max_peds, ri_off, list_off))
    return lists


def _distance_to_player(
    tracker: MemoryReelingTracker,
    ent_addr: int,
    player_pos: tuple[float, float, float] | None,
) -> tuple[float, tuple[float, float, float] | None, int | None, str]:
    fish_item = tracker._read_fish_pos_relative(ent_addr, player_pos)
    if fish_item is not None:
        pos, offset = fish_item
        if player_pos is None or tracker._is_fishing_local_pos(pos):
            dist = math.sqrt(pos[0] * pos[0] + pos[1] * pos[1] + pos[2] * pos[2])
            return dist, pos, offset, "fish_pos"
        px, py, pz = player_pos
        dist = math.sqrt((pos[0] - px) ** 2 + (pos[1] - py) ** 2 + (pos[2] - pz) ** 2)
        return dist, pos, offset, "fish_pos"

    pos_item = tracker._read_pos_at_offsets(ent_addr, POS_OFFSETS)
    if pos_item is not None and player_pos is not None:
        pos, offset = pos_item
        px, py, pz = player_pos
        dist = math.sqrt((pos[0] - px) ** 2 + (pos[1] - py) ** 2 + (pos[2] - pz) ** 2)
        return dist, pos, offset, "world_pos"

    return math.inf, None, None, "unreadable"


def _collect_candidates(
    tracker: MemoryReelingTracker,
    player_pos: tuple[float, float, float] | None,
    limit: int,
) -> list[dict[str, Any]]:
    candidates: dict[int, dict[str, Any]] = {}
    if tracker.fish_addr:
        dist, pos, pos_offset, source = _distance_to_player(tracker, tracker.fish_addr, player_pos)
        candidates[tracker.fish_addr] = {
            "addr": int(tracker.fish_addr),
            "hash": int(tracker._read_entity_hash(tracker.fish_addr) or 0),
            "dist": float(dist),
            "pos": pos,
            "pos_offset": pos_offset,
            "source": f"tracker_{source}",
            "list": None,
        }

    for p_ped_list, max_peds, ri_off, list_off in _ped_lists(tracker):
        for index in range(min(max_peds, 2048)):
            ent_addr = tracker._u64(p_ped_list + index * 0x10)
            if not tracker._is_ptr(ent_addr) or ent_addr == tracker.player_addr:
                continue
            entity_hash = tracker._read_entity_hash(ent_addr) or 0
            dist, pos, pos_offset, source = _distance_to_player(tracker, ent_addr, player_pos)
            if not math.isfinite(dist) or not (0.25 < dist < 80.0):
                if entity_hash != FISH_MODEL_HASH:
                    continue
            direction = tracker._read_fish_direction(ent_addr, FISH_PRIMARY_DIRECTION_OFFSETS)
            has_direction = direction is not None
            if entity_hash != FISH_MODEL_HASH and not has_direction and dist > 45.0:
                continue
            old = candidates.get(ent_addr)
            if old is not None and dist >= old["dist"]:
                continue
            candidates[ent_addr] = {
                "addr": int(ent_addr),
                "hash": int(entity_hash),
                "dist": float(dist),
                "pos": pos,
                "pos_offset": pos_offset,
                "source": source if entity_hash != FISH_MODEL_HASH else "hash",
                "list": {
                    "ri_off": ri_off,
                    "list_off": list_off,
                    "index": index,
                },
            }

    def sort_key(item: dict[str, Any]) -> tuple[int, float]:
        entity_hash = item["hash"]
        dist = item["dist"]
        if entity_hash == FISH_MODEL_HASH:
            return 0, dist
        if item["addr"] == tracker.fish_addr:
            return 1, dist
        return 2, dist

    return sorted(candidates.values(), key=sort_key)[:limit]


def _candidate_json(
    tracker: MemoryReelingTracker,
    item: dict[str, Any],
) -> dict[str, Any]:
    addr = int(item["addr"])
    direction_values = {}
    for (offset, _eps, polarity), value in zip(FISH_DIRECTION_FIELDS, _direction_values(tracker, addr), strict=True):
        direction_values[f"0x{offset:X}"] = None if not math.isfinite(float(value)) else float(value * polarity)
    pos = item.get("pos")
    return {
        "addr": f"0x{addr:X}",
        "hash": item["hash"],
        "is_hash_fish": item["hash"] == FISH_MODEL_HASH,
        "distance": None if not math.isfinite(float(item["dist"])) else item["dist"],
        "pos": None if pos is None else [round(float(v), 5) for v in pos],
        "pos_offset": None if item.get("pos_offset") is None else f"0x{int(item['pos_offset']):X}",
        "source": item.get("source"),
        "list": item.get("list"),
        "direction": direction_values,
    }


def _serializable_state(state: ReelingState, held_key: str | None) -> dict[str, Any]:
    return {
        "action": state.action,
        "move_val": state.move_val,
        "command_label": _command_label_from_state(state, held_key),
        "held_key": held_key,
        "distance": state.distance,
        "lateral": state.lateral,
        "fish_addr": None if state.fish_addr is None else f"0x{state.fish_addr:X}",
        "player_addr": None if state.player_addr is None else f"0x{state.player_addr:X}",
        "player_pos_offset": None if state.player_pos_offset is None else f"0x{state.player_pos_offset:X}",
        "fish_pos_offset": None if state.fish_pos_offset is None else f"0x{state.fish_pos_offset:X}",
    }


def _float_corr(x: np.ndarray, y: np.ndarray) -> float:
    mask = np.isfinite(x) & (y != 0)
    if int(mask.sum()) < 8:
        return 0.0
    xv = x[mask].astype(np.float64)
    yv = y[mask].astype(np.float64)
    if float(np.std(xv)) < 1e-9 or float(np.std(yv)) < 1e-9:
        return 0.0
    return float(np.corrcoef(xv, yv)[0, 1])


def _sign_accuracy(values: np.ndarray, labels: np.ndarray, invert: bool) -> tuple[float | None, int]:
    mask = np.isfinite(values) & (np.abs(values) > 1e-7) & np.isin(labels, (-1, 1))
    n = int(mask.sum())
    if n < 8:
        return None, n
    signs = np.sign(values[mask]).astype(np.int8)
    if invert:
        signs = -signs
    return float((signs == labels[mask]).mean()), n


def _label_counts(labels: np.ndarray) -> str:
    return (
        f"A={int((labels == -1).sum())} "
        f"D={int((labels == 1).sum())} "
        f"none={int((labels == 0).sum())} "
        f"both={int((labels == 2).sum())}"
    )


def _mode_addr(addrs: np.ndarray) -> int:
    values = [int(value) for value in addrs.tolist() if int(value) != 0]
    if not values:
        return 0
    counts: dict[int, int] = {}
    for value in values:
        counts[value] = counts.get(value, 0) + 1
    return max(counts, key=counts.get)


def _command_accuracy(command_labels: np.ndarray, key_labels: np.ndarray) -> tuple[float | None, int]:
    mask = np.isin(command_labels, (-1, 1)) & np.isin(key_labels, (-1, 1))
    n = int(mask.sum())
    if n < 8:
        return None, n
    return float((command_labels[mask] == key_labels[mask]).mean()), n


def _write_report(npz_path: Path, report_path: Path) -> None:
    data = np.load(npz_path, allow_pickle=False)
    key_labels = data["key_labels"].astype(np.int8)
    command_labels = data["command_labels"].astype(np.int8)
    direction_values = data["direction_values"].astype(np.float32)
    fish_addrs = data["fish_addrs"].astype(np.uint64)
    actions = data["actions"].astype(str)
    metadata = json.loads(str(data["metadata"]))
    direction_fields = tuple(
        (int(item["offset"]), float(item["eps"]), float(item["current_polarity"]))
        for item in metadata.get("direction_fields", [])
    ) or FISH_DIRECTION_FIELDS

    lines: list[str] = []
    lines.append(f"file={npz_path}")
    lines.append(f"samples={key_labels.size} keys: {_label_counts(key_labels)}")
    lines.append(f"metadata={json.dumps(metadata, ensure_ascii=False)}")
    fish_addr = _mode_addr(fish_addrs)
    lines.append(f"mode_fish_addr={'None' if fish_addr == 0 else f'0x{fish_addr:X}'}")
    lines.append(
        "actions="
        + ", ".join(
            f"{name}:{int((actions == name).sum())}"
            for name in sorted(set(actions.tolist()))
            if name
        )
    )

    accuracy, n = _command_accuracy(command_labels, key_labels)
    if accuracy is None:
        lines.append("current_logic_vs_actual_keys=n/a (need manual A/D labels or bot key presses)")
    else:
        lines.append(f"current_logic_vs_actual_keys={accuracy:.3f} n={n}")

    lines.append("")
    lines.append("Direction fields vs actual A/D keys:")
    best: tuple[float, int, int, float, float, float | None, float | None] | None = None
    for index, (offset, eps, current_polarity) in enumerate(direction_fields):
        if index >= direction_values.shape[1]:
            continue
        values = direction_values[:, index]
        raw_values = values / current_polarity
        corr = _float_corr(values, key_labels.astype(np.float32))
        acc_same, n_same = _sign_accuracy(raw_values, key_labels, invert=current_polarity < 0)
        acc_invert, n_invert = _sign_accuracy(raw_values, key_labels, invert=current_polarity > 0)
        n_field = max(n_same, n_invert)
        if n_field < 8:
            lines.append(f"  off=0x{offset:03X} n={n_field} insufficient")
            continue
        same_score = acc_same if acc_same is not None else 0.0
        invert_score = acc_invert if acc_invert is not None else 0.0
        recommended_polarity = int(current_polarity) if same_score >= invert_score else -int(current_polarity)
        best_score = max(same_score, invert_score, abs(corr))
        if best is None or best_score > best[0]:
            best = (best_score, offset, recommended_polarity, current_polarity, corr, acc_same, acc_invert)
        verdict = "ok"
        if recommended_polarity != current_polarity and max(same_score, invert_score) >= 0.75:
            verdict = "polarity_suspect"
        lines.append(
            f"  off=0x{offset:03X} eps={eps:g} current_polarity={current_polarity:+.0f} "
            f"recommended_polarity={recommended_polarity:+d} corr={corr:+.3f} "
            f"current_acc={'n/a' if acc_same is None else f'{acc_same:.3f}'} "
            f"inverted_polarity_acc={'n/a' if acc_invert is None else f'{acc_invert:.3f}'} "
            f"n={n_field} {verdict}"
        )

    lines.append("")
    if best is None:
        lines.append("No reliable direction field found. Record a longer manual reeling session.")
    else:
        _score, offset, recommended_polarity, current_polarity, corr, acc_same, acc_invert = best
        lines.append(
            "Best field: "
            f"off=0x{offset:X} recommended_polarity={recommended_polarity:+d} "
            f"current_polarity={current_polarity:+.0f} corr={corr:+.3f} "
            f"current_acc={'n/a' if acc_same is None else f'{acc_same:.3f}'} "
            f"inverted_polarity_acc={'n/a' if acc_invert is None else f'{acc_invert:.3f}'}"
        )
        if recommended_polarity != current_polarity:
            lines.append(
                "Suspicion: current code may press the opposite A/D key for this direction field. "
                "Use this report together with the JSONL samples before changing memory_reeling.py."
            )

    fish_positions = data["fish_positions"].astype(np.float32)
    if fish_positions.shape[0] >= 10:
        lines.append("")
        lines.append("Fish position X-delta vs actual A/D keys:")
        for index, offset in enumerate(metadata["fish_pos_offsets"]):
            values = fish_positions[:, index, 0]
            delta = np.diff(values)
            labels = key_labels[1:]
            corr = _float_corr(delta, labels.astype(np.float32))
            acc_same, n_same = _sign_accuracy(delta, labels, invert=False)
            acc_invert, n_invert = _sign_accuracy(delta, labels, invert=True)
            n_field = max(n_same, n_invert)
            if n_field >= 8:
                lines.append(
                    f"  off=0x{int(offset):03X} delta_corr={corr:+.3f} "
                    f"delta_sign_acc={'n/a' if acc_same is None else f'{acc_same:.3f}'} "
                    f"delta_inverted_acc={'n/a' if acc_invert is None else f'{acc_invert:.3f}'} n={n_field}"
                )

    report_path.write_text("\n".join(lines), encoding="utf-8")


def record(args: argparse.Namespace) -> Path:
    out_dir = Path(args.out_dir or PROJECT_DIR / "logs" / "memory_snapshots")
    out_dir.mkdir(parents=True, exist_ok=True)
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    stem = f"reeling_direction_probe_{stamp}"
    npz_path = out_dir / f"{stem}.npz"
    jsonl_path = out_dir / f"{stem}.jsonl"
    report_path = out_dir / f"{stem}.report.txt"

    tracker = MemoryReelingTracker(args.process, input_controller=NullInputController(), log_callback=print)
    tracker.start()
    time.sleep(args.warmup)

    timestamps: list[float] = []
    perf_times: list[float] = []
    key_labels: list[int] = []
    a_downs: list[bool] = []
    d_downs: list[bool] = []
    command_labels: list[int] = []
    actions: list[str] = []
    move_values: list[float] = []
    player_addrs: list[int] = []
    fish_addrs: list[int] = []
    fish_hashes: list[int] = []
    direction_values: list[np.ndarray] = []
    selected_direction_offsets: list[int] = []
    selected_direction_raws: list[float] = []
    player_positions: list[np.ndarray] = []
    fish_positions: list[np.ndarray] = []
    entity_addrs: list[list[int]] = []
    entity_hashes: list[list[int]] = []
    entity_distances: list[list[float]] = []
    entity_positions: list[np.ndarray] = []
    entity_directions: list[np.ndarray] = []
    player_bytes: list[np.ndarray] = []
    fish_bytes: list[np.ndarray] = []
    entity_bytes: list[np.ndarray] = []

    started = time.perf_counter()
    next_sample = started
    print("Passive reeling direction probe started.")
    print("It reads GTA memory and A/D key state only; it does not press any keys.")
    print("For ground truth, reel manually and press only the correct A or D while the probe is running.")
    try:
        with jsonl_path.open("w", encoding="utf-8") as jsonl:
            while time.perf_counter() - started < args.duration:
                now_perf = time.perf_counter()
                if now_perf < next_sample:
                    time.sleep(min(0.002, next_sample - now_perf))
                    continue
                next_sample += args.interval

                state = tracker.step() if args.run_tracker_step else tracker.latest_state()
                held_key = tracker.held_key
                key_label, a_down, d_down = _keyboard_snapshot()
                command_label = _command_label_from_state(state, held_key)

                player_item = tracker._read_pos_at_offsets(tracker.player_addr, POS_OFFSETS) if tracker.player_addr else None
                player_pos = None if player_item is None else player_item[0]
                candidates = _collect_candidates(tracker, player_pos, args.max_candidates)

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

                direction_info = _direction_snapshot(tracker, tracker.fish_addr)
                selected_offset_text = direction_info["selected_offset"]
                selected_offset = 0 if selected_offset_text is None else int(str(selected_offset_text), 16)
                selected_raw = direction_info["selected_raw"]

                timestamp = time.time()
                timestamps.append(timestamp)
                perf_times.append(now_perf - started)
                key_labels.append(key_label)
                a_downs.append(a_down)
                d_downs.append(d_down)
                command_labels.append(command_label)
                actions.append(state.action)
                move_values.append(float("nan") if state.move_val is None else float(state.move_val))
                player_addrs.append(int(tracker.player_addr or 0))
                fish_addrs.append(int(tracker.fish_addr or 0))
                fish_hashes.append(int(tracker._read_entity_hash(tracker.fish_addr) or 0) if tracker.fish_addr else 0)
                direction_values.append(_direction_values(tracker, tracker.fish_addr))
                selected_direction_offsets.append(selected_offset)
                selected_direction_raws.append(float("nan") if selected_raw is None else float(selected_raw))
                player_positions.append(_pos_candidates(tracker, tracker.player_addr, POS_OFFSETS))
                fish_positions.append(_pos_candidates(tracker, tracker.fish_addr, FISH_POS_OFFSETS))
                entity_addrs.append(addrs)
                entity_hashes.append(hashes)
                entity_distances.append(distances)
                entity_positions.append(np.stack([_pos_candidates(tracker, addr, ENTITY_POS_OFFSETS) for addr in addrs]))
                entity_directions.append(np.stack([_direction_values(tracker, addr) for addr in addrs]))
                player_bytes.append(_read_bytes(tracker, tracker.player_addr, args.bytes))
                fish_bytes.append(_read_bytes(tracker, tracker.fish_addr, args.bytes))
                entity_bytes.append(np.stack([_read_bytes(tracker, addr, args.bytes) for addr in addrs]))

                row = {
                    "t": timestamp,
                    "elapsed": now_perf - started,
                    "keys": {
                        "label": key_label,
                        "a_down": a_down,
                        "d_down": d_down,
                    },
                    "tracker": _serializable_state(state, held_key),
                    "replay": None if tracker.replay_interface is None else f"0x{tracker.replay_interface:X}",
                    "player_addr": None if tracker.player_addr is None else f"0x{tracker.player_addr:X}",
                    "fish_addr": None if tracker.fish_addr is None else f"0x{tracker.fish_addr:X}",
                    "fish_hash": fish_hashes[-1],
                    "direction": direction_info,
                    "player_positions": [
                        {
                            "offset": f"0x{offset:X}",
                            "pos": None if not np.isfinite(player_positions[-1][idx]).all() else [float(v) for v in player_positions[-1][idx]],
                        }
                        for idx, offset in enumerate(POS_OFFSETS)
                    ],
                    "fish_positions": [
                        {
                            "offset": f"0x{offset:X}",
                            "pos": None if not np.isfinite(fish_positions[-1][idx]).all() else [float(v) for v in fish_positions[-1][idx]],
                        }
                        for idx, offset in enumerate(FISH_POS_OFFSETS)
                    ],
                    "candidates": [_candidate_json(tracker, item) for item in candidates],
                }
                jsonl.write(json.dumps(row, ensure_ascii=False, separators=(",", ":")) + "\n")

                if len(timestamps) % max(1, int(1 / args.interval)) == 0:
                    print(
                        f"samples={len(timestamps)} action={state.action} "
                        f"cmd={command_label} keys={key_label} "
                        f"fish={'None' if tracker.fish_addr is None else f'0x{tracker.fish_addr:X}'} "
                        f"candidates={sum(1 for addr in addrs if addr)}"
                    )
    except KeyboardInterrupt:
        print("Interrupted by user; saving collected samples.")
    finally:
        tracker.stop()

    metadata = {
        "kind": "sonar_reeling_direction_probe",
        "version": 1,
        "process": args.process,
        "duration": args.duration,
        "interval": args.interval,
        "warmup": args.warmup,
        "bytes": args.bytes,
        "max_candidates": args.max_candidates,
        "run_tracker_step": args.run_tracker_step,
        "direction_fields": [
            {"offset": offset, "eps": eps, "current_polarity": polarity}
            for offset, eps, polarity in FISH_DIRECTION_FIELDS
        ],
        "fish_model_hash": FISH_MODEL_HASH,
        "fish_pos_offsets": FISH_POS_OFFSETS,
        "player_pos_offsets": POS_OFFSETS,
        "entity_pos_offsets": ENTITY_POS_OFFSETS,
        "key_label_meaning": {"-1": "A", "0": "none", "1": "D", "2": "both"},
        "jsonl_path": str(jsonl_path),
    }

    sample_count = len(timestamps)
    zero_entity_bytes = np.zeros((0, args.max_candidates, args.bytes), dtype=np.uint8)
    np.savez_compressed(
        npz_path,
        timestamps=np.array(timestamps, dtype=np.float64),
        perf_times=np.array(perf_times, dtype=np.float64),
        key_labels=np.array(key_labels, dtype=np.int8),
        a_down=np.array(a_downs, dtype=np.bool_),
        d_down=np.array(d_downs, dtype=np.bool_),
        command_labels=np.array(command_labels, dtype=np.int8),
        actions=np.array(actions, dtype="<U64"),
        move_values=np.array(move_values, dtype=np.float32),
        player_addrs=np.array(player_addrs, dtype=np.uint64),
        fish_addrs=np.array(fish_addrs, dtype=np.uint64),
        fish_hashes=np.array(fish_hashes, dtype=np.int64),
        direction_values=np.stack(direction_values).astype(np.float32) if direction_values else np.zeros((0, len(FISH_DIRECTION_FIELDS)), dtype=np.float32),
        selected_direction_offsets=np.array(selected_direction_offsets, dtype=np.int32),
        selected_direction_raws=np.array(selected_direction_raws, dtype=np.float32),
        player_positions=np.stack(player_positions).astype(np.float32) if player_positions else np.zeros((0, len(POS_OFFSETS), 3), dtype=np.float32),
        fish_positions=np.stack(fish_positions).astype(np.float32) if fish_positions else np.zeros((0, len(FISH_POS_OFFSETS), 3), dtype=np.float32),
        entity_addrs=np.array(entity_addrs, dtype=np.uint64) if entity_addrs else np.zeros((0, args.max_candidates), dtype=np.uint64),
        entity_hashes=np.array(entity_hashes, dtype=np.int64) if entity_hashes else np.zeros((0, args.max_candidates), dtype=np.int64),
        entity_distances=np.array(entity_distances, dtype=np.float32) if entity_distances else np.zeros((0, args.max_candidates), dtype=np.float32),
        entity_positions=np.stack(entity_positions).astype(np.float32) if entity_positions else np.zeros((0, args.max_candidates, len(ENTITY_POS_OFFSETS), 3), dtype=np.float32),
        entity_directions=np.stack(entity_directions).astype(np.float32) if entity_directions else np.zeros((0, args.max_candidates, len(FISH_DIRECTION_FIELDS)), dtype=np.float32),
        player_bytes=np.stack(player_bytes).astype(np.uint8) if player_bytes else np.zeros((0, args.bytes), dtype=np.uint8),
        fish_bytes=np.stack(fish_bytes).astype(np.uint8) if fish_bytes else np.zeros((0, args.bytes), dtype=np.uint8),
        entity_bytes=np.stack(entity_bytes).astype(np.uint8) if entity_bytes else zero_entity_bytes,
        metadata=json.dumps(metadata, ensure_ascii=False),
    )
    _write_report(npz_path, report_path)

    print(f"Saved samples: {sample_count}")
    print(f"Saved NPZ: {npz_path}")
    print(f"Saved JSONL: {jsonl_path}")
    print(f"Saved report: {report_path}")
    return npz_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Passively record GTA memory and A/D key state during manual reeling."
    )
    parser.add_argument("--process", default="gta5.exe")
    parser.add_argument("--duration", type=float, default=75.0)
    parser.add_argument("--interval", type=float, default=0.02)
    parser.add_argument("--warmup", type=float, default=0.5)
    parser.add_argument("--bytes", type=int, default=0x500)
    parser.add_argument("--max-candidates", type=int, default=12)
    parser.add_argument("--out-dir", default=None)
    parser.add_argument(
        "--no-tracker-step",
        dest="run_tracker_step",
        action="store_false",
        help="Only observe cached tracker state. Default runs tracker.step() with a null input controller.",
    )
    parser.set_defaults(run_tracker_step=True)
    return parser


def main() -> int:
    record(build_parser().parse_args())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
