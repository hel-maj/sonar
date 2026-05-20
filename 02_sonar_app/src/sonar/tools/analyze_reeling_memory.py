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
        f"{source:8s} slot={slot:<2d} addr=0x{addr:X} off=0x{offset:03X} {metric:5s} "
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
    for slot in range(entity_bytes.shape[1]):
        mode_addr = _mode_addr(entity_addrs[:, slot])
        if mode_addr == 0:
            continue
        same_addr = entity_addrs[:, slot] == mode_addr
        if int(same_addr.sum()) < 12:
            continue
        raw = entity_bytes[same_addr, slot, :]
        y = labels[same_addr]
        for offset in range(0, raw.shape[1] - 4, 4):
            values = _float_at(raw, offset)
            if not np.isfinite(values).all() or float(np.nanmax(np.abs(values))) > 100000.0:
                continue
            stats = _candidate_stats(values, y)
            if stats is None:
                continue
            score, corr, acc = stats
            if score >= 0.25:
                candidates.append(
                    (
                        score,
                        _summarize_candidate("entity", slot, mode_addr, offset, "raw", score, corr, acc, int((y != 0).sum()), values),
                    )
                )
            if values.size >= 3:
                delta = np.diff(values)
                dy = y[1:]
                stats_d = _candidate_stats(delta, dy)
                if stats_d is None:
                    continue
                score_d, corr_d, acc_d = stats_d
                same_next = same_addr[np.where(same_addr)[0][1:]]
                if score_d >= 0.25 and bool(np.all(same_next)):
                    candidates.append(
                        (
                            score_d,
                            _summarize_candidate("entity", slot, mode_addr, offset, "delta", score_d, corr_d, acc_d, int((dy != 0).sum()), delta),
                        )
                    )

    player_bytes = data["player_bytes"]
    player_addr = _mode_addr(data["player_addrs"])
    if player_addr and player_bytes.shape[0] >= 12:
        for offset in range(0, player_bytes.shape[1] - 4, 4):
            values = _float_at(player_bytes, offset)
            if not np.isfinite(values).all() or float(np.nanmax(np.abs(values))) > 100000.0:
                continue
            stats = _candidate_stats(values, labels)
            if stats is None:
                continue
            score, corr, acc = stats
            if score >= 0.25:
                candidates.append(
                    (
                        score,
                        _summarize_candidate("player", 0, player_addr, offset, "raw", score, corr, acc, int((labels != 0).sum()), values),
                    )
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
