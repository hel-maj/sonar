from __future__ import annotations

import argparse
from pathlib import Path

import numpy as np


DEFAULT_MINIMUM_TAIL_SECONDS = 4.0
DEFAULT_PRE_WINDOW_SECONDS = 4.0
DEFAULT_SETTLE_SECONDS = 0.75
DEFAULT_TOP = 80


def infer_completion_boundary(
    perf_times: np.ndarray,
    key_labels: np.ndarray,
    minimum_tail_seconds: float = DEFAULT_MINIMUM_TAIL_SECONDS,
) -> tuple[int, float, float] | None:
    manual = np.flatnonzero(np.isin(key_labels, (-1, 1, 2)))
    if manual.size == 0 or perf_times.size == 0:
        return None
    last_manual_index = int(manual[-1])
    last_manual_at = float(perf_times[last_manual_index])
    tail_seconds = float(perf_times[-1] - last_manual_at)
    if tail_seconds < minimum_tail_seconds:
        return None
    return last_manual_index, last_manual_at, tail_seconds


def _mode_and_ratio(values: np.ndarray) -> tuple[int, float]:
    counts = np.bincount(values, minlength=256)
    value = int(counts.argmax())
    return value, int(counts[value]) / max(1, values.size)


def _float_at(raw: np.ndarray, offset: int) -> np.ndarray:
    chunk = np.ascontiguousarray(raw[:, offset : offset + 4])
    return chunk.view("<f4").reshape(-1)


def _format_offset(offset: int) -> str:
    return f"-0x{-offset:03X}" if offset < 0 else f"0x{offset:03X}"


def _completion_candidates(
    source: str,
    raw: np.ndarray,
    pre_mask: np.ndarray,
    tail_mask: np.ndarray,
    base_offset: int = 0,
) -> list[tuple[float, str, str]]:
    candidates: list[tuple[float, str, str]] = []
    pre_raw = raw[pre_mask]
    tail_raw = raw[tail_mask]
    if pre_raw.shape[0] < 8 or tail_raw.shape[0] < 8:
        return candidates

    for relative_offset in range(raw.shape[1]):
        pre_mode, pre_ratio = _mode_and_ratio(pre_raw[:, relative_offset])
        tail_mode, tail_ratio = _mode_and_ratio(tail_raw[:, relative_offset])
        if pre_mode == tail_mode or tail_ratio < 0.98:
            continue
        simple_bonus = 0.15 if tail_mode in (0, 1) else 0.0
        simple_bonus += 0.15 if pre_mode in (0, 1) else 0.0
        score = tail_ratio + 0.25 * pre_ratio + simple_bonus
        candidates.append(
            (
                score,
                "byte",
                f"{source:8s} off={_format_offset(base_offset + relative_offset)} byte "
                f"pre={pre_mode:<3d} tail={tail_mode:<3d} "
                f"pre_mode={pre_ratio:.3f} tail_mode={tail_ratio:.3f}",
            )
        )

    for relative_offset in range(0, raw.shape[1] - 3, 4):
        pre = _float_at(pre_raw, relative_offset)
        tail = _float_at(tail_raw, relative_offset)
        if not np.isfinite(pre).all() or not np.isfinite(tail).all():
            continue
        if max(float(np.max(np.abs(pre))), float(np.max(np.abs(tail)))) > 100000.0:
            continue
        pre_value = float(np.median(pre))
        tail_value = float(np.median(tail))
        change = abs(tail_value - pre_value)
        if change < 1e-4:
            continue
        tail_spread = float(np.percentile(tail, 90) - np.percentile(tail, 10))
        if tail_spread > max(1e-4, change * 0.1):
            continue
        simple_bonus = 0.15 if abs(tail_value) < 1e-7 or abs(tail_value - 1.0) < 1e-7 else 0.0
        score = 1.0 + simple_bonus - min(0.5, tail_spread / max(change, 1e-9))
        candidates.append(
            (
                score,
                "f32",
                f"{source:8s} off={_format_offset(base_offset + relative_offset)} f32  "
                f"pre={pre_value:+.7g} tail={tail_value:+.7g} tail_spread={tail_spread:.3g}",
            )
        )
    return candidates


def analyze(
    path: Path,
    *,
    minimum_tail_seconds: float = DEFAULT_MINIMUM_TAIL_SECONDS,
    pre_window_seconds: float = DEFAULT_PRE_WINDOW_SECONDS,
    settle_seconds: float = DEFAULT_SETTLE_SECONDS,
    top: int = DEFAULT_TOP,
) -> Path:
    data = np.load(path, allow_pickle=False)
    perf_times = data["perf_times"].astype(np.float64)
    key_labels = data["key_labels"].astype(np.int8)
    out_path = path.with_suffix(".completion.txt")
    lines = [f"file={path}"]
    boundary = infer_completion_boundary(perf_times, key_labels, minimum_tail_seconds)
    if boundary is None:
        lines.append(
            f"No sustained manual-idle tail found. Need at least {minimum_tail_seconds:g}s "
            "after the final A/D key press."
        )
        out_path.write_text("\n".join(lines), encoding="utf-8")
        print(f"Saved completion report: {out_path}")
        return out_path

    last_manual_index, last_manual_at, tail_seconds = boundary
    pre_mask = (perf_times >= last_manual_at - pre_window_seconds) & (perf_times < last_manual_at - settle_seconds)
    tail_mask = perf_times >= last_manual_at + settle_seconds
    lines.extend(
        [
            f"last_manual_index={last_manual_index}",
            f"last_manual_at={last_manual_at:.3f}",
            f"idle_tail_seconds={tail_seconds:.3f}",
            f"pre_samples={int(pre_mask.sum())} tail_samples={int(tail_mask.sum())}",
            "",
            "Completion-state memory candidates:",
            "Treat these as hypotheses until the same offsets repeat across different captures.",
        ]
    )
    if "fish_addrs" in data:
        fish_addrs = data["fish_addrs"].astype(np.uint64)
        lines.insert(5, f"tail_fish_addr_nonzero={int((fish_addrs[tail_mask] != 0).sum())}/{int(tail_mask.sum())}")
    if "fish_hashes" in data:
        fish_hashes = data["fish_hashes"].astype(np.int64)
        lines.insert(6, f"tail_fish_hash_nonzero={int((fish_hashes[tail_mask] != 0).sum())}/{int(tail_mask.sum())}")

    candidates: list[tuple[float, str, str]] = []
    fish_bytes = data["fish_bytes"] if "fish_bytes" in data else np.zeros((0, 0), dtype=np.uint8)
    if fish_bytes.shape[0] == perf_times.size:
        candidates.extend(_completion_candidates("fish", fish_bytes, pre_mask, tail_mask))
    fish_before_bytes = data["fish_before_bytes"] if "fish_before_bytes" in data else np.zeros((0, 0), dtype=np.uint8)
    if fish_before_bytes.shape[0] == perf_times.size:
        candidates.extend(
            _completion_candidates(
                "fish_pre",
                fish_before_bytes,
                pre_mask,
                tail_mask,
                base_offset=-fish_before_bytes.shape[1],
            )
        )
    player_bytes = data["player_bytes"] if "player_bytes" in data else np.zeros((0, 0), dtype=np.uint8)
    if player_bytes.shape[0] == perf_times.size:
        candidates.extend(_completion_candidates("player", player_bytes, pre_mask, tail_mask))

    byte_candidates = sorted((item for item in candidates if item[1] == "byte"), key=lambda item: item[0], reverse=True)
    float_candidates = sorted((item for item in candidates if item[1] == "f32"), key=lambda item: item[0], reverse=True)
    if candidates:
        lines.extend(["", "Stable changed byte candidates:"])
        lines.extend(text for _, _, text in byte_candidates[:top])
        lines.extend(["", "Stable changed aligned f32 candidates:"])
        lines.extend(text for _, _, text in float_candidates[:top])
    else:
        lines.append("No stable changed fields found in tracked memory windows.")
    out_path.write_text("\n".join(lines), encoding="utf-8")
    print(f"Saved completion report: {out_path}")
    return out_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Find memory fields that change after manual reeling finishes.")
    parser.add_argument("snapshot", type=Path)
    parser.add_argument("--minimum-tail-seconds", type=float, default=DEFAULT_MINIMUM_TAIL_SECONDS)
    parser.add_argument("--pre-window-seconds", type=float, default=DEFAULT_PRE_WINDOW_SECONDS)
    parser.add_argument("--settle-seconds", type=float, default=DEFAULT_SETTLE_SECONDS)
    parser.add_argument("--top", type=int, default=DEFAULT_TOP)
    return parser


def main() -> int:
    args = build_parser().parse_args()
    analyze(
        args.snapshot,
        minimum_tail_seconds=args.minimum_tail_seconds,
        pre_window_seconds=args.pre_window_seconds,
        settle_seconds=args.settle_seconds,
        top=args.top,
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
