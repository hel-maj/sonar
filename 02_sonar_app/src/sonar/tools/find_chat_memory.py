from __future__ import annotations

import argparse
import ctypes
import json
import re
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Callable, Iterable

from sonar.fishing.memory_reeling import MemoryReelingTracker, PROCESS_ALL_READ, PTR_MAX, PTR_MIN
from sonar.paths import PROJECT_DIR
from sonar.tools.record_reeling_memory import NullInputController


DEFAULT_QUERY_FILE = PROJECT_DIR / "config" / "chat_memory_query.txt"
DEFAULT_OUT_DIR = PROJECT_DIR / "logs" / "chat_memory"
DEFAULT_ENCODINGS = ("utf-8", "utf-16-le", "cp1251")
QUERY_TEMPLATE = (
    "Paste fresh chat text here, then run:\n"
    "python -m sonar.tools.find_chat_memory --query-file config/chat_memory_query.txt\n"
)


@dataclass(frozen=True, slots=True)
class Needle:
    label: str
    text: str
    encoding: str
    data: bytes
    is_full: bool


@dataclass(frozen=True, slots=True)
class SearchHit:
    addr: int
    needle: Needle

    @property
    def score(self) -> tuple[int, int]:
        return (1 if self.needle.is_full else 0, len(self.needle.data))


def _normalize_text(value: str) -> str:
    return re.sub(r"\s+", " ", value).strip()


def _dedupe_preserve_order(values: Iterable[str]) -> list[str]:
    out: list[str] = []
    seen: set[str] = set()
    for value in values:
        normalized = _normalize_text(value)
        if not normalized or normalized in seen:
            continue
        seen.add(normalized)
        out.append(normalized)
    return out


def _word_fragments(text: str, min_chars: int, max_chars: int, limit: int) -> list[str]:
    words = _normalize_text(text).split()
    if not words:
        return []
    fragments: list[str] = []
    for start in range(len(words)):
        current: list[str] = []
        for word in words[start:]:
            candidate = " ".join((*current, word))
            if len(candidate) > max_chars:
                break
            current.append(word)
            if len(candidate) >= min_chars:
                fragments.append(candidate)
                break
        if len(fragments) >= limit:
            break
    return fragments


def _sentence_fragments(text: str, min_chars: int, max_chars: int) -> list[str]:
    fragments: list[str] = []
    for part in re.split(r"(?<=[.!?])\s+", _normalize_text(text)):
        if len(part) < min_chars:
            continue
        fragments.append(part[:max_chars].strip())
    return fragments


def build_needles(
    query: str,
    encodings: Iterable[str] = DEFAULT_ENCODINGS,
    min_fragment_chars: int = 32,
    max_fragment_chars: int = 96,
    max_fragments: int = 32,
) -> list[Needle]:
    raw = query.strip()
    normalized = _normalize_text(raw)
    texts: list[tuple[str, str, bool]] = []
    for label, text in (("full_raw", raw), ("full_normalized", normalized)):
        if len(text) >= max(1, min_fragment_chars):
            texts.append((label, text, True))

    fragment_candidates: list[str] = []
    if len(normalized) > max_fragment_chars:
        fragment_candidates.extend(_sentence_fragments(normalized, min_fragment_chars, max_fragment_chars))
        fragment_candidates.extend(_word_fragments(normalized, min_fragment_chars, max_fragment_chars, max_fragments))
        fragment_candidates.append(normalized[:max_fragment_chars].strip())
        fragment_candidates.append(normalized[-max_fragment_chars:].strip())
    else:
        fragment_candidates.append(normalized)

    for index, fragment in enumerate(_dedupe_preserve_order(fragment_candidates)[:max_fragments], 1):
        texts.append((f"fragment_{index:02d}", fragment, False))

    needles: list[Needle] = []
    for encoding in encodings:
        encoding = encoding.strip()
        if not encoding:
            continue
        for label, text, is_full in texts:
            try:
                data = text.encode(encoding)
            except UnicodeEncodeError:
                continue
            if data:
                needles.append(Needle(label=label, text=text, encoding=encoding, data=data, is_full=is_full))
    needles.sort(key=lambda item: (0 if item.is_full else 1, -len(item.data), item.encoding, item.label))
    return needles


def _find_all(data: bytes, needle: bytes, limit: int) -> list[int]:
    indexes: list[int] = []
    start = 0
    while len(indexes) < limit:
        hit = data.find(needle, start)
        if hit < 0:
            break
        indexes.append(hit)
        start = hit + 1
    return indexes


def _scan_chunks(
    read_chunk: Callable[[int, int], bytes | None],
    start: int,
    end: int,
    needles: list[Needle],
    chunk_size: int,
    overlap: int,
    limit: int,
) -> list[SearchHit]:
    hits: list[SearchHit] = []
    seen: set[tuple[int, str, str]] = set()
    carry = b""
    addr = start
    while addr < end and len(hits) < limit:
        size = min(chunk_size, end - addr)
        data = read_chunk(addr, size)
        if not data:
            carry = b""
            addr += size
            continue
        scan_data = carry + data
        scan_base = addr - len(carry)
        carry_len = len(carry)
        for needle in needles:
            remaining = limit - len(hits)
            if remaining <= 0:
                break
            for offset in _find_all(scan_data, needle.data, remaining):
                absolute = scan_base + offset
                if offset + len(needle.data) <= carry_len:
                    continue
                key = (absolute, needle.encoding, needle.text)
                if key in seen:
                    continue
                seen.add(key)
                hits.append(SearchHit(addr=absolute, needle=needle))
                if len(hits) >= limit:
                    break
        carry = scan_data[-overlap:] if overlap else b""
        addr += size
    hits.sort(key=lambda item: (-item.score[0], -item.score[1], item.addr, item.needle.encoding))
    return hits


def _read_query(path: Path, query: str | None) -> str:
    if query:
        return query.strip()
    if not path.exists():
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(QUERY_TEMPLATE, encoding="utf-8")
        raise FileNotFoundError(f"Created query file: {path}. Paste chat text into it and rerun.")
    text = path.read_text(encoding="utf-8-sig").strip()
    if not text or text == QUERY_TEMPLATE.strip():
        raise ValueError(f"Query file is empty: {path}")
    return text


def _collect_search_regions(
    tracker: MemoryReelingTracker,
    max_region_mb: int,
    max_total_mb: int,
) -> list[tuple[int, int]]:
    regions = tracker._collect_regions(PTR_MIN, PTR_MAX)
    max_region_bytes = max_region_mb * 1024 * 1024
    filtered = [(start, end) for start, end in regions if end > start and end - start <= max_region_bytes]
    if max_total_mb <= 0:
        return filtered
    selected: list[tuple[int, int]] = []
    total = 0
    max_total_bytes = max_total_mb * 1024 * 1024
    for start, end in filtered:
        size = end - start
        if total + size > max_total_bytes:
            continue
        selected.append((start, end))
        total += size
    return selected


def _open_tracker(process_name: str) -> MemoryReelingTracker:
    tracker = MemoryReelingTracker(process_name, input_controller=NullInputController(), log_callback=print)
    tracker.pid = tracker._get_pid()
    if tracker.pid is None:
        raise RuntimeError(f"Process not found: {process_name}")
    tracker.handle = ctypes.windll.kernel32.OpenProcess(PROCESS_ALL_READ, False, tracker.pid)
    if not tracker.handle:
        tracker.handle = None
        raise RuntimeError(f"OpenProcess failed for {process_name} pid={tracker.pid}")
    return tracker


def _decode_context(data: bytes, encoding: str) -> str:
    if encoding.startswith("utf-16") and len(data) % 2:
        data = data[:-1]
    text = data.decode(encoding, errors="ignore")
    text = text.replace("\x00", "")
    return _normalize_text(text)


def _context_for_hit(tracker: MemoryReelingTracker, hit: SearchHit, before: int, after: int) -> str:
    start = max(PTR_MIN, hit.addr - before)
    size = before + len(hit.needle.data) + after
    data = tracker._read(start, size)
    if not data:
        return ""
    return _decode_context(data, hit.needle.encoding)


def _hit_record(tracker: MemoryReelingTracker, hit: SearchHit, context_bytes: int) -> dict[str, object]:
    return {
        "addr": f"0x{hit.addr:X}",
        "encoding": hit.needle.encoding,
        "label": hit.needle.label,
        "is_full": hit.needle.is_full,
        "needle_chars": len(hit.needle.text),
        "needle_bytes": len(hit.needle.data),
        "needle_text": hit.needle.text,
        "context": _context_for_hit(tracker, hit, context_bytes, context_bytes),
    }


def scan_once(args: argparse.Namespace) -> Path:
    query_path = Path(args.query_file)
    query = _read_query(query_path, args.query)
    encodings = tuple(item.strip() for item in args.encodings.split(",") if item.strip())
    needles = build_needles(
        query,
        encodings=encodings,
        min_fragment_chars=args.min_fragment_chars,
        max_fragment_chars=args.max_fragment_chars,
        max_fragments=args.max_fragments,
    )
    if not needles:
        raise ValueError("No searchable byte patterns were generated from the query.")

    tracker = _open_tracker(args.process)
    time.sleep(args.startup_delay)
    try:
        regions = _collect_search_regions(tracker, args.max_region_mb, args.max_total_mb)
        total_mb = sum(end - start for start, end in regions) / 1024 / 1024
        print(
            f"Chat memory search: process={args.process} pid={tracker.pid} "
            f"query_chars={len(query)} needles={len(needles)} regions={len(regions)} total={total_mb:.1f} MB"
        )

        chunk_size = max(4096, args.chunk_mb * 1024 * 1024)
        max_needle_len = max(len(needle.data) for needle in needles)
        overlap = min(max_needle_len - 1, max(0, args.max_overlap_kb * 1024))
        hits: list[SearchHit] = []
        started = time.perf_counter()
        for index, (start, end) in enumerate(regions, 1):
            if len(hits) >= args.hits:
                break
            region_hits = _scan_chunks(
                tracker._read,
                start,
                end,
                needles,
                chunk_size,
                overlap,
                args.hits - len(hits),
            )
            hits.extend(region_hits)
            if args.progress and (index % args.progress == 0 or region_hits):
                scanned_mb = sum(reg_end - reg_start for reg_start, reg_end in regions[:index]) / 1024 / 1024
                print(f"scanned_regions={index}/{len(regions)} scanned={scanned_mb:.1f} MB hits={len(hits)}")
        hits.sort(key=lambda item: (-item.score[0], -item.score[1], item.addr, item.needle.encoding))
        records = [_hit_record(tracker, hit, args.context_bytes) for hit in hits[: args.hits]]
        elapsed = time.perf_counter() - started

        out_dir = Path(args.out_dir or DEFAULT_OUT_DIR)
        out_dir.mkdir(parents=True, exist_ok=True)
        stamp = time.strftime("%Y%m%d_%H%M%S")
        out_path = out_dir / f"chat_memory_search_{stamp}.json"
        report = {
            "kind": "sonar_chat_memory_search",
            "version": 1,
            "created_at": time.time(),
            "process": args.process,
            "pid": tracker.pid,
            "query_file": str(query_path),
            "query": query,
            "encodings": encodings,
            "regions": len(regions),
            "total_mb": total_mb,
            "elapsed_seconds": elapsed,
            "hits": records,
        }
        out_path.write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")

        if records:
            print(f"Found hits: {len(records)}")
            for index, record in enumerate(records[: args.print_hits], 1):
                print(
                    f"[{index}] addr={record['addr']} encoding={record['encoding']} "
                    f"label={record['label']} bytes={record['needle_bytes']}"
                )
                context = str(record["context"])
                if context:
                    print(f"    context: {context[: args.print_context_chars]}")
        else:
            print("No hits found. Try a shorter distinctive phrase or increase --max-total-mb.")
        print(f"Saved report: {out_path}")
        return out_path
    finally:
        tracker.stop()


def run(args: argparse.Namespace) -> None:
    if not args.watch:
        scan_once(args)
        return
    while True:
        try:
            scan_once(args)
        except Exception as exc:
            print(f"chat memory search failed: {exc}")
        time.sleep(args.watch_interval)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Search GTA process memory for fresh chat text.")
    parser.add_argument("--process", default="gta5.exe")
    parser.add_argument("--query-file", default=str(DEFAULT_QUERY_FILE))
    parser.add_argument("--query", default=None)
    parser.add_argument("--encodings", default=",".join(DEFAULT_ENCODINGS))
    parser.add_argument("--min-fragment-chars", type=int, default=32)
    parser.add_argument("--max-fragment-chars", type=int, default=96)
    parser.add_argument("--max-fragments", type=int, default=32)
    parser.add_argument("--hits", type=int, default=40)
    parser.add_argument("--print-hits", type=int, default=10)
    parser.add_argument("--print-context-chars", type=int, default=240)
    parser.add_argument("--context-bytes", type=int, default=192)
    parser.add_argument("--chunk-mb", type=int, default=8)
    parser.add_argument("--max-overlap-kb", type=int, default=1024)
    parser.add_argument("--max-region-mb", type=int, default=512)
    parser.add_argument("--max-total-mb", type=int, default=4096, help="0 scans all selected regions.")
    parser.add_argument("--startup-delay", type=float, default=0.4)
    parser.add_argument("--progress", type=int, default=25, help="Print progress every N regions. Use 0 to disable.")
    parser.add_argument("--out-dir", default=None)
    parser.add_argument("--watch", action="store_true")
    parser.add_argument("--watch-interval", type=float, default=10.0)
    return parser


def main() -> int:
    run(build_parser().parse_args())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
