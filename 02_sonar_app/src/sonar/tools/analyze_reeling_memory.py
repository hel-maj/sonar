from __future__ import annotations

import argparse
import json
from collections import Counter
from pathlib import Path

import numpy as np


def _float_at(raw: np.ndarray, offset: int) -> np.ndarray:
    chunk = np.ascontiguousarray(raw[:, offset : offset + 4])
    return chunk.view("<f4").reshape(-1)


def _corr(x: np.ndarray, y: np.ndarray) -> float:
    mask = np.isfinite(x) & np.isfinite(y) & (y != 0)
    if int(mask.sum()) < 8:
        return 0.0
    xv = x[mask].astype(np.float64)
    yv = y[mask].astype(np.float64)
    if float(np.std(xv)) < 1e-9 or float(np.std(yv)) < 1e-9:
        return 0.0
    return float(np.corrcoef(xv, yv)[0, 1])


def _sign_acc(x: np.ndarray, y: np.ndarray, eps: float = 1e-6) -> float | None:
    mask = np.isfinite(x) & (np.abs(x) > eps) & (y != 0)
    if int(mask.sum()) < 8:
        return None
    return float((np.sign(x[mask]) == y[mask]).mean())


def _score(corr: float, acc: float | None) -> float:
    if acc is None:
        return abs(corr)
    return max(abs(corr), max(acc, 1.0 - acc) - 0.5)


def _mode_addr(addrs: np.ndarray) -> int:
    values = [int(value) for value in addrs.tolist() if int(value) != 0]
    if not values:
        return 0
    return Counter(values).most_common(1)[0][0]


def _format_offset(offset: int) -> str:
    return f"-0x{-offset:03X}" if offset < 0 else f"0x{offset:03X}"


def _summarize_candidate(
    source: str,
    slot: int,
    addr: int,
    offset: int,
    metric: str,
    score: float,
    corr: float,
    acc: float | None,
    n: int,
    values: np.ndarray,
) -> str:
    finite = values[np.isfinite(values)]
    if finite.size:
        p10, p50, p90 = np.percentile(finite, [10, 50, 90])
        spread = f"p10={p10:.4g} p50={p50:.4g} p90={p90:.4g}"
    else:
        spread = "p10=nan p50=nan p90=nan"
    return (
        f"{source:8s} slot={slot:<2d} addr=0x{addr:X} off={_format_offset(offset)} {metric:5s} "
        f"score={score:.3f} corr={corr:+.3f} acc={'n/a' if acc is None else f'{acc:.3f}'} n={n:<4d} {spread}"
    )


def _candidate_stats(values: np.ndarray, labels: np.ndarray) -> tuple[float, float, float | None] | None:
    mask = np.isfinite(values) & (labels != 0)
    if int(mask.sum()) < 12:
        return None
    if float(np.nanstd(values[mask])) < 1e-9:
        return None
    corr = _corr(values, labels)
    acc = _sign_acc(values, labels)
    return _score(corr, acc), corr, acc


def _append_raw_candidates(
    candidates: list[tuple[float, str]],
    *,
    source: str,
    slot: int,
    addr: int,
    raw: np.ndarray,
    labels: np.ndarray,
    base_offset: int = 0,
) -> None:
    if raw.shape[0] != labels.size:
        return
    for relative_offset in range(0, raw.shape[1] - 3, 4):
        values = _float_at(raw, relative_offset)
        if not np.isfinite(values).all() or float(np.nanmax(np.abs(values))) > 100000.0:
            continue
        offset = base_offset + relative_offset
        stats = _candidate_stats(values, labels)
        if stats is not None:
            score, corr, acc = stats
            if score >= 0.25:
                candidates.append(
                    (
                        score,
                        _summarize_candidate(source, slot, addr, offset, "raw", score, corr, acc, int((labels != 0).sum()), values),
                    )
                )
        if values.size < 3:
            continue
        delta = np.diff(values)
        delta_labels = labels[1:]
        delta_stats = _candidate_stats(delta, delta_labels)
        if delta_stats is None:
            continue
        score_d, corr_d, acc_d = delta_stats
        if score_d >= 0.25:
            candidates.append(
                (
                    score_d,
                    _summarize_candidate(
                        source,
                        slot,
                        addr,
                        offset,
                        "delta",
                        score_d,
                        corr_d,
                        acc_d,
                        int((delta_labels != 0).sum()),
                        delta,
                    ),
                )
            )


def analyze(path: Path, top: int) -> Path:
    data = np.load(path, allow_pickle=False)
    labels = data["key_labels"].astype(np.float32)
    report: list[str] = []
    metadata = json.loads(str(data["metadata"]))
    report.append(f"file={path}")
    report.append(f"samples={labels.size} labels: A={int((labels == -1).sum())} D={int((labels == 1).sum())} none={int((labels == 0).sum())}")
    report.append(f"metadata={json.dumps(metadata, ensure_ascii=False)}")
    candidates: list[tuple[float, str]] = []

    entity_bytes = data["entity_bytes"]
    entity_addrs = data["entity_addrs"]
    entity_labels = data["entity_key_labels"].astype(np.float32) if "entity_key_labels" in data else labels
    for slot in range(entity_bytes.shape[1]):
        mode_addr = _mode_addr(entity_addrs[:, slot])
        if mode_addr == 0:
            continue
        same_addr = entity_addrs[:, slot] == mode_addr
        if int(same_addr.sum()) < 12:
            continue
        raw = entity_bytes[same_addr, slot, :]
        _append_raw_candidates(
            candidates,
            source="entity",
            slot=slot,
            addr=mode_addr,
            raw=raw,
            labels=entity_labels[same_addr],
        )

    player_bytes = data["player_bytes"]
    player_addr = _mode_addr(data["player_addrs"])
    if player_addr and player_bytes.shape[0] >= 12:
        _append_raw_candidates(
            candidates,
            source="player",
            slot=0,
            addr=player_addr,
            raw=player_bytes,
            labels=labels,
        )

    fish_bytes = data["fish_bytes"] if "fish_bytes" in data else np.zeros((0, 0), dtype=np.uint8)
    fish_addr = _mode_addr(data["fish_addrs"])
    if fish_addr and fish_bytes.shape[0] >= 12:
        _append_raw_candidates(
            candidates,
            source="fish",
            slot=0,
            addr=fish_addr,
            raw=fish_bytes,
            labels=labels,
        )

    fish_before_bytes = data["fish_before_bytes"] if "fish_before_bytes" in data else np.zeros((0, 0), dtype=np.uint8)
    if fish_addr and fish_before_bytes.shape[0] >= 12 and fish_before_bytes.shape[1] > 0:
        _append_raw_candidates(
            candidates,
            source="fish_pre",
            slot=0,
            addr=fish_addr,
            raw=fish_before_bytes,
            labels=labels,
            base_offset=-fish_before_bytes.shape[1],
        )

    if "fish_pointer_bytes" in data and "fish_pointer_addrs" in data:
        pointer_bytes = data["fish_pointer_bytes"]
        pointer_addrs = data["fish_pointer_addrs"]
        pointer_labels = data["pointer_key_labels"].astype(np.float32)
        for slot in range(pointer_bytes.shape[1]):
            mode_addr = _mode_addr(pointer_addrs[:, slot])
            if mode_addr == 0:
                continue
            same_addr = pointer_addrs[:, slot] == mode_addr
            if int(same_addr.sum()) < 12:
                continue
            _append_raw_candidates(
                candidates,
                source="fish_ptr",
                slot=slot,
                addr=mode_addr,
                raw=pointer_bytes[same_addr, slot, :],
                labels=pointer_labels[same_addr],
            )

    candidates.sort(key=lambda item: item[0], reverse=True)
    report.append("")
    report.append("Top memory variables correlated with manual A/D labels:")
    if not candidates:
        report.append("No strong candidates. Record longer and press only the correct A or D while reeling.")
    else:
        report.extend(text for _, text in candidates[:top])
    out_path = path.with_suffix(".analysis.txt")
    out_path.write_text("\n".join(report), encoding="utf-8")
    print("\n".join(report[: 5 + min(top, 25)]))
    print(f"Saved report: {out_path}")
    return out_path


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Analyze passive reeling memory samples.")
    parser.add_argument("snapshot", type=Path)
    parser.add_argument("--top", type=int, default=60)
    return parser


def main() -> int:
    args = build_parser().parse_args()
    analyze(args.snapshot, args.top)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
