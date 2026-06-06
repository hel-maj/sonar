from __future__ import annotations

import argparse
import ctypes
import json
import math
import re
import struct
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
    FISH_REELING_ACTIVE_OFFSET,
    FISH_REELING_ACTIVE_VALUE,
    MemoryReelingTracker,
    PLAYER_MATRIX_OFFSETS,
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
VK_LEFT = 0x25
VK_RIGHT = 0x27
LABEL_KEY_VKS = {
    "ad": (VK_A, VK_D),
    "arrows": (VK_LEFT, VK_RIGHT),
}
DEFAULT_FISH_BYTES = 0x4000
DEFAULT_FISH_BEFORE_BYTES = 0x400
DEFAULT_PLAYER_BYTES = 0x1000
DEFAULT_CANDIDATE_BYTES = 0x1000
DEFAULT_CANDIDATE_INTERVAL = 0.75
DEFAULT_POINTER_INTERVAL = 0.20
DEFAULT_POINTER_SCAN_BYTES = 0x1000
DEFAULT_POINTER_TARGET_BYTES = 0x400
DEFAULT_MAX_POINTER_TARGETS = 48
DEFAULT_FIXTURE_SAMPLES = 1200
DEFAULT_FIXTURE_COMPLETION_SAMPLES = 500
FIXTURE_DIRECTION_TRANSITION_MARGIN_SECONDS = 0.18
FIXTURE_DIRECTION_TAIL_EXCLUDE_SECONDS = 2.0
DEFAULT_AUTO_STOP_IDLE_SECONDS = 5.0
DEFAULT_AUTO_STOP_MIN_MANUAL_SAMPLES = 25
FALLBACK_READ_CHUNK_BYTES = 0x400


def _parse_non_negative_int(value: str) -> int:
    try:
        parsed = int(value, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"expected integer, got {value!r}") from exc
    if parsed < 0:
        raise argparse.ArgumentTypeError("expected a non-negative integer")
    return parsed


def _safe_label(value: str | None) -> str:
    if not value:
        return ""
    return re.sub(r"[^0-9A-Za-zА-Яа-яЁё_.-]+", "_", value).strip("._")


def _capture_sizes(args: argparse.Namespace) -> tuple[int, int, int, int]:
    legacy_bytes = getattr(args, "bytes", None)
    if legacy_bytes is not None:
        return legacy_bytes, legacy_bytes, legacy_bytes, min(legacy_bytes, DEFAULT_FISH_BEFORE_BYTES)
    return args.fish_bytes, args.player_bytes, args.candidate_bytes, args.fish_before_bytes


def _validate_args(args: argparse.Namespace) -> None:
    if args.duration <= 0:
        raise ValueError("--duration must be positive")
    if args.interval <= 0:
        raise ValueError("--interval must be positive")
    if args.candidate_interval < 0 or args.pointer_interval < 0:
        raise ValueError("capture intervals must be non-negative")
    if args.max_candidates <= 0 or args.max_pointer_targets <= 0:
        raise ValueError("capture limits must be positive")
    if args.pointer_target_bytes <= 0:
        raise ValueError("--pointer-target-bytes must be positive")
    if not (0.0 <= args.fixture_min_accuracy <= 1.0):
        raise ValueError("--fixture-min-accuracy must be between 0 and 1")
    if args.auto_stop_idle < 0:
        raise ValueError("--auto-stop-idle must be non-negative")
    if args.auto_stop_min_manual_samples <= 0:
        raise ValueError("--auto-stop-min-manual-samples must be positive")


def _key_down(vk: int) -> bool:
    if not hasattr(ctypes, "windll"):
        return False
    return bool(ctypes.windll.user32.GetAsyncKeyState(vk) & 0x8000)


def _keyboard_snapshot(label_keys: str = "ad") -> tuple[int, bool, bool]:
    left_vk, right_vk = LABEL_KEY_VKS[label_keys]
    left_down = _key_down(left_vk)
    right_down = _key_down(right_vk)
    if left_down and not right_down:
        return -1, left_down, right_down
    if right_down and not left_down:
        return 1, left_down, right_down
    if left_down and right_down:
        return 2, left_down, right_down
    return 0, left_down, right_down


def _should_auto_stop_idle(
    elapsed: float,
    key_label: int,
    manual_key_samples: int,
    last_manual_key_at: float | None,
    idle_seconds: float,
    minimum_manual_samples: int,
) -> bool:
    return (
        idle_seconds > 0
        and key_label == 0
        and manual_key_samples >= minimum_manual_samples
        and last_manual_key_at is not None
        and elapsed - last_manual_key_at >= idle_seconds
    )


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
    if data:
        chunk = np.frombuffer(data[:size], dtype=np.uint8)
        out[: len(chunk)] = chunk
        return out
    if size <= FALLBACK_READ_CHUNK_BYTES:
        return out
    for offset in range(0, size, FALLBACK_READ_CHUNK_BYTES):
        chunk_size = min(FALLBACK_READ_CHUNK_BYTES, size - offset)
        data = tracker._read(addr + offset, chunk_size)
        if not data:
            continue
        chunk = np.frombuffer(data[:chunk_size], dtype=np.uint8)
        out[offset : offset + len(chunk)] = chunk
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


def _linked_pointer_targets(
    tracker: MemoryReelingTracker,
    source_addr: int | None,
    scan_bytes: int,
    target_bytes: int,
    limit: int,
) -> list[dict[str, Any]]:
    if not source_addr or scan_bytes < 8 or target_bytes <= 0 or limit <= 0:
        return []
    source = tracker._read(source_addr, scan_bytes)
    if not source:
        return []
    targets: list[dict[str, Any]] = []
    seen: set[int] = set()
    for source_offset in range(0, len(source) - 7, 8):
        target_addr = struct.unpack_from("<Q", source, source_offset)[0]
        if not tracker._is_ptr(target_addr) or target_addr in seen:
            continue
        target = tracker._read(target_addr, target_bytes)
        if not target:
            continue
        seen.add(target_addr)
        targets.append(
            {
                "source_offset": source_offset,
                "addr": target_addr,
                "bytes": _read_bytes(tracker, target_addr, target_bytes),
            }
        )
        if len(targets) >= limit:
            break
    return targets


def _padded_linked_pointer_snapshot(
    tracker: MemoryReelingTracker,
    source_addr: int | None,
    scan_bytes: int,
    target_bytes: int,
    limit: int,
) -> tuple[np.ndarray, np.ndarray, np.ndarray, list[dict[str, str]]]:
    source_offsets = np.full(limit, -1, dtype=np.int32)
    addrs = np.zeros(limit, dtype=np.uint64)
    raw = np.zeros((limit, target_bytes), dtype=np.uint8)
    json_targets: list[dict[str, str]] = []
    for index, target in enumerate(_linked_pointer_targets(tracker, source_addr, scan_bytes, target_bytes, limit)):
        source_offset = int(target["source_offset"])
        addr = int(target["addr"])
        source_offsets[index] = source_offset
        addrs[index] = addr
        raw[index] = target["bytes"]
        json_targets.append({"source_offset": f"0x{source_offset:X}", "addr": f"0x{addr:X}"})
    return source_offsets, addrs, raw, json_targets


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


def _wait_for_initial_resolution(tracker: MemoryReelingTracker) -> None:
    resolver = tracker._resolver_thread
    if resolver is None or not resolver.is_alive():
        return
    print("Resolving GTA memory structures before recording...")
    resolver.join()
    print(
        "Initial resolution finished: "
        f"player={'None' if tracker.player_addr is None else f'0x{tracker.player_addr:X}'} "
        f"fish={'None' if tracker.fish_addr is None else f'0x{tracker.fish_addr:X}'}"
    )


def _probe_tracker_step(tracker: MemoryReelingTracker, allow_deep_search: bool) -> ReelingState:
    if allow_deep_search or tracker.fish_addr is not None or not tracker.handle:
        return tracker.step()
    if tracker.player_addr is None:
        return ReelingState(active=True, action="target_search")
    tracker._retry_find_fish(allow_deep_search=False)
    return ReelingState(
        active=True,
        action="target_search",
        fish_addr=tracker.fish_addr,
        player_addr=tracker.player_addr,
    )


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


def _move_label(move_val: float | None) -> int:
    if move_val is None:
        return 0
    if move_val > DIRECTION_EPS:
        return 1
    if move_val < -DIRECTION_EPS:
        return -1
    return 0


def _right_vec_from_snapshot(raw: np.ndarray) -> np.ndarray:
    data = raw.tobytes()
    for matrix_offset in PLAYER_MATRIX_OFFSETS:
        for row in (0, 1, 2):
            offset = matrix_offset + row * 16
            if offset + 16 > len(data):
                continue
            rx, ry, rz, _rw = struct.unpack_from("<4f", data, offset)
            if not all(math.isfinite(value) for value in (rx, ry, rz)):
                continue
            length = math.hypot(rx, ry)
            if 0.45 < length < 1.55 and abs(rx) <= 1.2 and abs(ry) <= 1.2:
                return np.array((rx / length, ry / length), dtype=np.float32)
    return np.full(2, np.nan, dtype=np.float32)


def _capture_right_vectors(data: Any) -> np.ndarray:
    if "player_right_vectors" in data:
        return data["player_right_vectors"].astype(np.float32)
    return np.stack([_right_vec_from_snapshot(row) for row in data["player_bytes"]]).astype(np.float32)


def _replay_motion_direction_fixture(data: Any) -> tuple[float | None, int]:
    labels = data["key_labels"].astype(np.int8)
    perf_times = data["perf_times"].astype(np.float64)
    fish_positions = data["fish_positions"].astype(np.float32)
    right_vectors = data["player_right_vectors"].astype(np.float32)
    if "player_positions" in data:
        player_positions = data["player_positions"].astype(np.float32)
    else:
        player_positions = np.full_like(fish_positions, np.nan, dtype=np.float32)
    if not (labels.size == perf_times.size == fish_positions.shape[0] == right_vectors.shape[0]):
        raise ValueError("Motion fixture sample counts differ")
    if player_positions.shape[0] != labels.size:
        raise ValueError("Motion fixture player position sample count differs")

    fixture_addr = 0x20000000000
    tracker = MemoryReelingTracker.__new__(MemoryReelingTracker)
    tracker.velocity_xy = (0.0, 0.0)
    tracker.last_fish_xy = None
    tracker.last_time = None
    tracker._projected_velocity_fish_addr = None
    tracker._projected_velocity = 0.0
    tracker._reset_move_stabilizer()
    predictions: list[int] = []
    expected: list[int] = []
    for now, label, fish_pos, right, player_pos in zip(
        perf_times,
        labels,
        fish_positions,
        right_vectors,
        player_positions,
    ):
        if not np.isfinite(fish_pos).all() or not np.isfinite(right).all():
            continue
        motion_updated = tracker._update_fish_velocity(float(now), tuple(float(value) for value in fish_pos), False)
        velocity_along = tracker.velocity_xy[0] * float(right[0]) + tracker.velocity_xy[1] * float(right[1])
        if np.isfinite(player_pos).all():
            velocity_along, _fish_forward, _fish_behind_player = (
                MemoryReelingTracker._orient_projected_velocity_to_fish_side(
                    velocity_along,
                    (float(right[0]), float(right[1])),
                    tuple(float(value) for value in player_pos),
                    tuple(float(value) for value in fish_pos),
                )
            )
        move_val, _source, action_eps = tracker._movement_from_projected_velocity(
            velocity_along=velocity_along,
            fish_addr=fixture_addr,
            using_stale_fish_pos=False,
            motion_updated=motion_updated,
        )
        move_val, _stable_source = tracker._stabilize_move(move_val, action_eps, float(now))
        if label not in (-1, 1):
            continue
        predictions.append(_move_label(move_val))
        expected.append(int(label))
    if not expected:
        return None, 0
    return float((np.array(predictions, dtype=np.int8) == np.array(expected, dtype=np.int8)).mean()), len(expected)


def replay_direction_fixture(path: Path) -> tuple[float | None, int]:
    data = np.load(path, allow_pickle=False)
    metadata = json.loads(str(data["metadata"]))
    if metadata.get("kind") != "sonar_reeling_direction_fixture":
        raise ValueError(f"Unsupported fixture kind: {metadata.get('kind')!r}")
    if "fish_positions" in data and "player_right_vectors" in data:
        return _replay_motion_direction_fixture(data)
    fish_bytes = data["fish_bytes"].astype(np.uint8)
    labels = data["key_labels"].astype(np.int8)
    if fish_bytes.shape[0] != labels.size:
        raise ValueError("Fixture fish_bytes and key_labels sample counts differ")

    fixture_addr = 0x20000000000
    tracker = MemoryReelingTracker.__new__(MemoryReelingTracker)
    tracker.fish_addr = fixture_addr
    tracker._fish_confirmed_hash = True
    tracker._fish_direction_offsets = FISH_PRIMARY_DIRECTION_OFFSETS
    tracker._blocked_direction_offsets = set()
    tracker._direction_watch_addr = fixture_addr
    tracker._direction_watch = {}
    tracker._direction_alignment = {}
    current_row = 0

    def f32(addr: int) -> float | None:
        offset = addr - fixture_addr
        if offset < 0 or offset + 4 > fish_bytes.shape[1]:
            return None
        return struct.unpack_from("<f", fish_bytes[current_row].tobytes(), offset)[0]

    tracker._f32 = f32
    tracker._reset_direction_tracking(fixture_addr)
    predictions: list[int] = []
    expected: list[int] = []
    for current_row in range(labels.size):
        label = int(labels[current_row])
        if label not in (-1, 1):
            continue
        selected = tracker._read_control_direction(
            fixture_addr,
            tracker._fish_direction_offsets,
            tracker._blocked_direction_offsets,
        )
        predictions.append(0 if selected is None else _move_label(selected[0]))
        expected.append(label)
    if not expected:
        return None, 0
    return float((np.array(predictions, dtype=np.int8) == np.array(expected, dtype=np.int8)).mean()), len(expected)


def _completion_fixture_indices(perf_times: np.ndarray, labels: np.ndarray, max_samples: int) -> np.ndarray:
    from sonar.tools.analyze_reeling_completion import infer_completion_boundary

    boundary = infer_completion_boundary(perf_times, labels)
    if boundary is None:
        return np.zeros(0, dtype=np.int64)
    _last_manual_index, last_manual_at, _tail_seconds = boundary
    valid = np.flatnonzero(perf_times >= last_manual_at - 5.0)
    if max_samples > 0 and valid.size > max_samples:
        positions = np.linspace(0, valid.size - 1, num=max_samples, dtype=np.int64)
        valid = valid[positions]
    return valid


def _direction_fixture_indices(
    perf_times: np.ndarray,
    labels: np.ndarray,
    fish_addrs: np.ndarray,
    fish_hashes: np.ndarray,
    max_samples: int,
    fish_bytes: np.ndarray | None = None,
) -> np.ndarray:
    valid_mask = (
        np.isin(labels, (-1, 1))
        & (fish_addrs != 0)
        & (fish_hashes == FISH_MODEL_HASH)
    )
    if fish_bytes is not None and fish_bytes.shape[1] > FISH_REELING_ACTIVE_OFFSET:
        valid_mask &= fish_bytes[:, FISH_REELING_ACTIVE_OFFSET] == FISH_REELING_ACTIVE_VALUE
    manual = np.flatnonzero(np.isin(labels, (-1, 1)))
    if manual.size:
        final_manual_at = float(perf_times[manual[-1]])
        valid_mask &= perf_times <= final_manual_at - FIXTURE_DIRECTION_TAIL_EXCLUDE_SECONDS
    transitions = np.flatnonzero(
        np.isin(labels[:-1], (-1, 1))
        & np.isin(labels[1:], (-1, 1))
        & (labels[:-1] != labels[1:])
    )
    for index in transitions:
        transition_at = float(perf_times[index + 1])
        valid_mask &= np.abs(perf_times - transition_at) > FIXTURE_DIRECTION_TRANSITION_MARGIN_SECONDS
    valid = np.flatnonzero(valid_mask)
    if max_samples > 0 and valid.size > max_samples:
        positions = np.linspace(0, valid.size - 1, num=max_samples, dtype=np.int64)
        valid = valid[positions]
    return valid


def _motion_fixture_indices(
    labels: np.ndarray,
    fish_addrs: np.ndarray,
    fish_hashes: np.ndarray,
    fish_bytes: np.ndarray,
    fish_positions: np.ndarray,
    right_vectors: np.ndarray,
    max_samples: int,
) -> np.ndarray:
    if fish_bytes.shape[1] <= FISH_REELING_ACTIVE_OFFSET:
        return np.zeros(0, dtype=np.int64)
    valid_mask = (
        np.isin(labels, (-1, 0, 1, 2))
        & (fish_addrs != 0)
        & (fish_hashes == FISH_MODEL_HASH)
        & (fish_bytes[:, FISH_REELING_ACTIVE_OFFSET] == FISH_REELING_ACTIVE_VALUE)
        & np.isfinite(fish_positions).all(axis=1)
        & np.isfinite(right_vectors).all(axis=1)
    )
    valid = np.flatnonzero(valid_mask)
    if max_samples > 0 and valid.size > max_samples:
        valid = valid[:max_samples]
    return valid


def _write_fixture(npz_path: Path, fixture_path: Path, max_samples: int, minimum_accuracy: float) -> Path:
    data = np.load(npz_path, allow_pickle=False)
    labels = data["key_labels"].astype(np.int8)
    fish_addrs = data["fish_addrs"].astype(np.uint64)
    fish_hashes = data["fish_hashes"].astype(np.int64)
    completion_valid = _completion_fixture_indices(data["perf_times"].astype(np.float64), labels, DEFAULT_FIXTURE_COMPLETION_SAMPLES)
    source_metadata = json.loads(str(data["metadata"]))
    if "fish_positions" in data and "player_bytes" in data:
        right_vectors = _capture_right_vectors(data)
        fish_positions = data["fish_positions"][:, 0].astype(np.float32)
        if "player_positions" in data:
            player_positions = data["player_positions"][:, 0].astype(np.float32)
        else:
            player_positions = np.full_like(fish_positions, np.nan, dtype=np.float32)
        valid = _motion_fixture_indices(
            labels,
            fish_addrs,
            fish_hashes,
            data["fish_bytes"],
            fish_positions,
            right_vectors,
            max_samples,
        )
        fixture_metadata = {
            "kind": "sonar_reeling_direction_fixture",
            "version": 3,
            "source_capture": npz_path.name,
            "source_capture_version": source_metadata.get("version"),
            "label": source_metadata.get("label", ""),
            "minimum_accuracy": minimum_accuracy,
            "fish_model_hash": FISH_MODEL_HASH,
            "sample_count": int(valid.size),
            "completion_sample_count": int(completion_valid.size),
        }
        np.savez_compressed(
            fixture_path,
            perf_times=data["perf_times"][valid].astype(np.float64),
            key_labels=labels[valid],
            fish_positions=fish_positions[valid],
            player_positions=player_positions[valid],
            player_right_vectors=right_vectors[valid],
            completion_perf_times=data["perf_times"][completion_valid].astype(np.float64),
            completion_key_labels=labels[completion_valid],
            completion_fish_bytes=data["fish_bytes"][completion_valid].astype(np.uint8),
            metadata=json.dumps(fixture_metadata, ensure_ascii=False),
        )
        return fixture_path

    valid = _direction_fixture_indices(
        data["perf_times"].astype(np.float64),
        labels,
        fish_addrs,
        fish_hashes,
        max_samples,
        fish_bytes=data["fish_bytes"],
    )
    fixture_metadata = {
        "kind": "sonar_reeling_direction_fixture",
        "version": 1,
        "source_capture": npz_path.name,
        "source_capture_version": source_metadata.get("version"),
        "label": source_metadata.get("label", ""),
        "minimum_accuracy": minimum_accuracy,
        "fish_model_hash": FISH_MODEL_HASH,
        "direction_fields": source_metadata.get("direction_fields", []),
        "sample_count": int(valid.size),
        "completion_sample_count": int(completion_valid.size),
    }
    np.savez_compressed(
        fixture_path,
        perf_times=data["perf_times"][valid].astype(np.float64),
        key_labels=labels[valid],
        fish_bytes=data["fish_bytes"][valid].astype(np.uint8),
        completion_perf_times=data["perf_times"][completion_valid].astype(np.float64),
        completion_key_labels=labels[completion_valid],
        completion_fish_bytes=data["fish_bytes"][completion_valid].astype(np.uint8),
        metadata=json.dumps(fixture_metadata, ensure_ascii=False),
    )
    return fixture_path


def record(args: argparse.Namespace) -> Path:
    _validate_args(args)
    out_dir = Path(args.out_dir or PROJECT_DIR / "logs" / "reeling_direction_probes")
    out_dir.mkdir(parents=True, exist_ok=True)
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    label = _safe_label(args.label)
    stem = f"reeling_direction_probe_{label + '_' if label else ''}{stamp}"
    npz_path = out_dir / f"{stem}.npz"
    jsonl_path = out_dir / f"{stem}.jsonl"
    report_path = out_dir / f"{stem}.report.txt"
    fixture_path = out_dir / f"{stem}.fixture.npz"
    fish_bytes_size, player_bytes_size, candidate_bytes_size, fish_before_bytes_size = _capture_sizes(args)

    tracker = MemoryReelingTracker(args.process, input_controller=NullInputController(), log_callback=print)
    tracker.start()
    _wait_for_initial_resolution(tracker)
    time.sleep(args.warmup)
    for seconds_left in range(int(math.ceil(args.countdown)), 0, -1):
        print(f"Recording starts in {seconds_left}...")
        time.sleep(1.0)

    timestamps: list[float] = []
    perf_times: list[float] = []
    sample_durations: list[float] = []
    schedule_lags: list[float] = []
    key_labels: list[int] = []
    label_left_downs: list[bool] = []
    label_right_downs: list[bool] = []
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
    player_right_vectors: list[np.ndarray] = []
    fish_positions: list[np.ndarray] = []
    player_bytes: list[np.ndarray] = []
    fish_bytes: list[np.ndarray] = []
    fish_before_bytes: list[np.ndarray] = []
    candidate_perf_times: list[float] = []
    candidate_key_labels: list[int] = []
    entity_addrs: list[list[int]] = []
    entity_hashes: list[list[int]] = []
    entity_distances: list[list[float]] = []
    entity_positions: list[np.ndarray] = []
    entity_directions: list[np.ndarray] = []
    entity_bytes: list[np.ndarray] = []
    pointer_perf_times: list[float] = []
    pointer_key_labels: list[int] = []
    fish_pointer_source_offsets: list[np.ndarray] = []
    fish_pointer_addrs: list[np.ndarray] = []
    fish_pointer_bytes: list[np.ndarray] = []

    started = time.perf_counter()
    next_sample = started
    next_progress = started + 1.0
    last_candidate_capture_at = float("-inf")
    last_pointer_capture_at = float("-inf")
    latest_candidate_count = 0
    manual_key_samples = 0
    last_manual_key_at: float | None = None
    stop_reason = "duration"
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
                scheduled_at = next_sample
                next_sample += args.interval
                sample_started = time.perf_counter()

                state = (
                    _probe_tracker_step(tracker, args.allow_deep_search)
                    if args.run_tracker_step
                    else tracker.latest_state()
                )
                held_key = tracker.held_key
                key_label, label_left_down, label_right_down = _keyboard_snapshot(args.label_keys)
                a_down = _key_down(VK_A)
                d_down = _key_down(VK_D)
                command_label = _command_label_from_state(state, held_key)
                elapsed = now_perf - started
                if key_label in (-1, 1):
                    manual_key_samples += 1
                if key_label != 0:
                    last_manual_key_at = elapsed

                player_item = tracker._read_pos_at_offsets(tracker.player_addr, POS_OFFSETS) if tracker.player_addr else None
                player_pos = None if player_item is None else player_item[0]

                direction_info = _direction_snapshot(tracker, tracker.fish_addr)
                selected_offset_text = direction_info["selected_offset"]
                selected_offset = 0 if selected_offset_text is None else int(str(selected_offset_text), 16)
                selected_raw = direction_info["selected_raw"]

                timestamp = time.time()
                timestamps.append(timestamp)
                perf_times.append(elapsed)
                key_labels.append(key_label)
                label_left_downs.append(label_left_down)
                label_right_downs.append(label_right_down)
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
                player_right = tracker._read_player_right_vec(tracker.player_addr) if tracker.player_addr else None
                player_right_vectors.append(
                    np.full(2, np.nan, dtype=np.float32)
                    if player_right is None
                    else np.array(player_right, dtype=np.float32)
                )
                fish_positions.append(_pos_candidates(tracker, tracker.fish_addr, FISH_POS_OFFSETS))
                player_bytes.append(_read_bytes(tracker, tracker.player_addr, player_bytes_size))
                fish_bytes.append(_read_bytes(tracker, tracker.fish_addr, fish_bytes_size))
                fish_before_addr = None if tracker.fish_addr is None else tracker.fish_addr - fish_before_bytes_size
                fish_before_bytes.append(_read_bytes(tracker, fish_before_addr, fish_before_bytes_size))

                candidates_json = None
                if now_perf - last_candidate_capture_at >= args.candidate_interval:
                    last_candidate_capture_at = now_perf
                    candidates = _collect_candidates(tracker, player_pos, args.max_candidates)
                    if tracker.fish_addr is None:
                        fish_candidate = next((item for item in candidates if item["hash"] == FISH_MODEL_HASH), None)
                        if fish_candidate is not None:
                            tracker.fish_addr = int(fish_candidate["addr"])
                            tracker._set_fish_signal_profile(FISH_MODEL_HASH)
                    candidates_json = [_candidate_json(tracker, item) for item in candidates]
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
                    candidate_perf_times.append(elapsed)
                    candidate_key_labels.append(key_label)
                    entity_addrs.append(addrs)
                    entity_hashes.append(hashes)
                    entity_distances.append(distances)
                    entity_positions.append(np.stack([_pos_candidates(tracker, addr, ENTITY_POS_OFFSETS) for addr in addrs]))
                    entity_directions.append(np.stack([_direction_values(tracker, addr) for addr in addrs]))
                    entity_bytes.append(np.stack([_read_bytes(tracker, addr, candidate_bytes_size) for addr in addrs]))
                    latest_candidate_count = sum(1 for addr in addrs if addr)

                linked_fish_pointers_json = None
                if now_perf - last_pointer_capture_at >= args.pointer_interval:
                    last_pointer_capture_at = now_perf
                    pointer_offsets, pointer_addrs, pointer_raw, linked_fish_pointers_json = _padded_linked_pointer_snapshot(
                        tracker,
                        tracker.fish_addr,
                        args.pointer_scan_bytes,
                        args.pointer_target_bytes,
                        args.max_pointer_targets,
                    )
                    pointer_perf_times.append(elapsed)
                    pointer_key_labels.append(key_label)
                    fish_pointer_source_offsets.append(pointer_offsets)
                    fish_pointer_addrs.append(pointer_addrs)
                    fish_pointer_bytes.append(pointer_raw)

                sample_durations.append(time.perf_counter() - sample_started)
                schedule_lags.append(max(0.0, now_perf - scheduled_at))

                row = {
                    "t": timestamp,
                    "elapsed": elapsed,
                    "keys": {
                        "label": key_label,
                        "label_keys": args.label_keys,
                        "label_left_down": label_left_down,
                        "label_right_down": label_right_down,
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
                    "candidates": candidates_json,
                    "linked_fish_pointers": linked_fish_pointers_json,
                }
                jsonl.write(json.dumps(row, ensure_ascii=False, separators=(",", ":")) + "\n")

                if _should_auto_stop_idle(
                    elapsed,
                    key_label,
                    manual_key_samples,
                    last_manual_key_at,
                    args.auto_stop_idle,
                    args.auto_stop_min_manual_samples,
                ):
                    stop_reason = "manual_idle_tail"
                    print(
                        f"Auto-stop: no manual {args.label_keys} label keys for {args.auto_stop_idle:g}s "
                        "after reeling activity. Saving completion tail."
                    )
                    break

                if now_perf >= next_progress:
                    next_progress = now_perf + 1.0
                    average_fps = len(timestamps) / max(0.001, now_perf - started)
                    print(
                        f"samples={len(timestamps)} fps={average_fps:.1f} action={state.action} "
                        f"cmd={command_label} keys={key_label} "
                        f"fish={'None' if tracker.fish_addr is None else f'0x{tracker.fish_addr:X}'} "
                        f"candidates={latest_candidate_count}"
                    )
    except KeyboardInterrupt:
        print("Interrupted by user; saving collected samples.")
    finally:
        tracker.stop()

    metadata = {
        "kind": "sonar_reeling_direction_probe",
        "version": 2,
        "label": label,
        "process": args.process,
        "duration": args.duration,
        "interval": args.interval,
        "warmup": args.warmup,
        "countdown": args.countdown,
        "bytes": candidate_bytes_size,
        "fish_bytes": fish_bytes_size,
        "fish_before_bytes": fish_before_bytes_size,
        "player_bytes": player_bytes_size,
        "candidate_bytes": candidate_bytes_size,
        "candidate_interval": args.candidate_interval,
        "max_candidates": args.max_candidates,
        "pointer_interval": args.pointer_interval,
        "pointer_scan_bytes": args.pointer_scan_bytes,
        "pointer_target_bytes": args.pointer_target_bytes,
        "max_pointer_targets": args.max_pointer_targets,
        "run_tracker_step": args.run_tracker_step,
        "allow_deep_search": args.allow_deep_search,
        "auto_stop_idle": args.auto_stop_idle,
        "auto_stop_min_manual_samples": args.auto_stop_min_manual_samples,
        "label_keys": args.label_keys,
        "manual_key_samples": manual_key_samples,
        "stop_reason": stop_reason,
        "direction_fields": [
            {"offset": offset, "eps": eps, "current_polarity": polarity}
            for offset, eps, polarity in FISH_DIRECTION_FIELDS
        ],
        "fish_model_hash": FISH_MODEL_HASH,
        "fish_pos_offsets": FISH_POS_OFFSETS,
        "player_pos_offsets": POS_OFFSETS,
        "entity_pos_offsets": ENTITY_POS_OFFSETS,
        "key_label_meaning": {
            "-1": "A" if args.label_keys == "ad" else "Left",
            "0": "none",
            "1": "D" if args.label_keys == "ad" else "Right",
            "2": "both",
        },
        "jsonl_path": str(jsonl_path),
    }

    sample_count = len(timestamps)
    zero_entity_bytes = np.zeros((0, args.max_candidates, candidate_bytes_size), dtype=np.uint8)
    zero_pointer_bytes = np.zeros((0, args.max_pointer_targets, args.pointer_target_bytes), dtype=np.uint8)
    np.savez_compressed(
        npz_path,
        timestamps=np.array(timestamps, dtype=np.float64),
        perf_times=np.array(perf_times, dtype=np.float64),
        sample_durations=np.array(sample_durations, dtype=np.float32),
        schedule_lags=np.array(schedule_lags, dtype=np.float32),
        key_labels=np.array(key_labels, dtype=np.int8),
        label_left_down=np.array(label_left_downs, dtype=np.bool_),
        label_right_down=np.array(label_right_downs, dtype=np.bool_),
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
        player_right_vectors=np.stack(player_right_vectors).astype(np.float32) if player_right_vectors else np.zeros((0, 2), dtype=np.float32),
        fish_positions=np.stack(fish_positions).astype(np.float32) if fish_positions else np.zeros((0, len(FISH_POS_OFFSETS), 3), dtype=np.float32),
        player_bytes=np.stack(player_bytes).astype(np.uint8) if player_bytes else np.zeros((0, player_bytes_size), dtype=np.uint8),
        fish_bytes=np.stack(fish_bytes).astype(np.uint8) if fish_bytes else np.zeros((0, fish_bytes_size), dtype=np.uint8),
        fish_before_bytes=np.stack(fish_before_bytes).astype(np.uint8) if fish_before_bytes else np.zeros((0, fish_before_bytes_size), dtype=np.uint8),
        candidate_perf_times=np.array(candidate_perf_times, dtype=np.float64),
        entity_key_labels=np.array(candidate_key_labels, dtype=np.int8),
        entity_addrs=np.array(entity_addrs, dtype=np.uint64) if entity_addrs else np.zeros((0, args.max_candidates), dtype=np.uint64),
        entity_hashes=np.array(entity_hashes, dtype=np.int64) if entity_hashes else np.zeros((0, args.max_candidates), dtype=np.int64),
        entity_distances=np.array(entity_distances, dtype=np.float32) if entity_distances else np.zeros((0, args.max_candidates), dtype=np.float32),
        entity_positions=np.stack(entity_positions).astype(np.float32) if entity_positions else np.zeros((0, args.max_candidates, len(ENTITY_POS_OFFSETS), 3), dtype=np.float32),
        entity_directions=np.stack(entity_directions).astype(np.float32) if entity_directions else np.zeros((0, args.max_candidates, len(FISH_DIRECTION_FIELDS)), dtype=np.float32),
        entity_bytes=np.stack(entity_bytes).astype(np.uint8) if entity_bytes else zero_entity_bytes,
        pointer_perf_times=np.array(pointer_perf_times, dtype=np.float64),
        pointer_key_labels=np.array(pointer_key_labels, dtype=np.int8),
        fish_pointer_source_offsets=np.stack(fish_pointer_source_offsets).astype(np.int32) if fish_pointer_source_offsets else np.zeros((0, args.max_pointer_targets), dtype=np.int32),
        fish_pointer_addrs=np.stack(fish_pointer_addrs).astype(np.uint64) if fish_pointer_addrs else np.zeros((0, args.max_pointer_targets), dtype=np.uint64),
        fish_pointer_bytes=np.stack(fish_pointer_bytes).astype(np.uint8) if fish_pointer_bytes else zero_pointer_bytes,
        metadata=json.dumps(metadata, ensure_ascii=False),
    )
    _write_report(npz_path, report_path)
    try:
        from sonar.tools.analyze_reeling_memory import analyze

        analyze(npz_path, args.analysis_top)
    except Exception as exc:
        print(f"Broad memory analysis failed: {exc}")
    try:
        from sonar.tools.analyze_reeling_completion import analyze as analyze_completion

        analyze_completion(npz_path, top=args.completion_top)
    except Exception as exc:
        print(f"Completion memory analysis failed: {exc}")
    _write_fixture(npz_path, fixture_path, args.fixture_samples, args.fixture_min_accuracy)
    fixture_accuracy, fixture_count = replay_direction_fixture(fixture_path)

    print(f"Saved samples: {sample_count}")
    print(f"Saved NPZ: {npz_path}")
    print(f"Saved JSONL: {jsonl_path}")
    print(f"Saved report: {report_path}")
    print(f"Saved regression fixture candidate: {fixture_path}")
    print(
        "Fixture current-direction accuracy: "
        f"{'n/a' if fixture_accuracy is None else f'{fixture_accuracy:.3f}'} n={fixture_count}"
    )
    return npz_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Passively record GTA memory, direction labels, and A/D control key state during manual reeling."
    )
    parser.add_argument("--process", default="gta5.exe")
    parser.add_argument("--duration", type=float, default=30.0)
    parser.add_argument("--interval", type=float, default=0.02)
    parser.add_argument("--warmup", type=float, default=0.5)
    parser.add_argument("--countdown", type=float, default=5.0)
    parser.add_argument("--label", default="")
    parser.add_argument(
        "--label-keys",
        choices=tuple(LABEL_KEY_VKS),
        default="ad",
        help="Keys used as direction labels: regular A/D controls or independent Left/Right arrow annotations.",
    )
    parser.add_argument("--fish-bytes", type=_parse_non_negative_int, default=DEFAULT_FISH_BYTES)
    parser.add_argument("--fish-before-bytes", type=_parse_non_negative_int, default=DEFAULT_FISH_BEFORE_BYTES)
    parser.add_argument("--player-bytes", type=_parse_non_negative_int, default=DEFAULT_PLAYER_BYTES)
    parser.add_argument("--candidate-bytes", type=_parse_non_negative_int, default=DEFAULT_CANDIDATE_BYTES)
    parser.add_argument(
        "--bytes",
        type=_parse_non_negative_int,
        default=None,
        help="Compatibility shortcut: override fish, player, and candidate byte windows with one size.",
    )
    parser.add_argument("--candidate-interval", type=float, default=DEFAULT_CANDIDATE_INTERVAL)
    parser.add_argument("--max-candidates", type=int, default=16)
    parser.add_argument("--pointer-interval", type=float, default=DEFAULT_POINTER_INTERVAL)
    parser.add_argument("--pointer-scan-bytes", type=_parse_non_negative_int, default=DEFAULT_POINTER_SCAN_BYTES)
    parser.add_argument("--pointer-target-bytes", type=_parse_non_negative_int, default=DEFAULT_POINTER_TARGET_BYTES)
    parser.add_argument("--max-pointer-targets", type=int, default=DEFAULT_MAX_POINTER_TARGETS)
    parser.add_argument("--fixture-samples", type=int, default=DEFAULT_FIXTURE_SAMPLES)
    parser.add_argument("--fixture-min-accuracy", type=float, default=0.70)
    parser.add_argument("--analysis-top", type=int, default=100)
    parser.add_argument("--completion-top", type=int, default=80)
    parser.add_argument("--auto-stop-idle", type=float, default=DEFAULT_AUTO_STOP_IDLE_SECONDS)
    parser.add_argument(
        "--auto-stop-min-manual-samples",
        type=int,
        default=DEFAULT_AUTO_STOP_MIN_MANUAL_SAMPLES,
    )
    parser.add_argument("--out-dir", default=None)
    parser.add_argument(
        "--no-tracker-step",
        dest="run_tracker_step",
        action="store_false",
        help="Only observe cached tracker state. Default runs tracker.step() with a null input controller.",
    )
    parser.add_argument(
        "--allow-deep-search",
        action="store_true",
        help="Allow expensive fallback fish scans during recording. Disabled by default to preserve sampling cadence.",
    )
    parser.set_defaults(run_tracker_step=True)
    return parser


def main() -> int:
    record(build_parser().parse_args())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
