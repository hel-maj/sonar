from __future__ import annotations

from sonar.tools.find_chat_memory import _scan_chunks, build_needles


def test_build_needles_contains_russian_encodings_and_fragments() -> None:
    query = (
        "Sheriff Department: Уважаемые жители штата! "
        "В данный момент проходит собеседование в Los Santos County Sheriff Department."
    )

    needles = build_needles(query, min_fragment_chars=16, max_fragment_chars=48, max_fragments=8)

    assert any(needle.encoding == "utf-8" and needle.is_full for needle in needles)
    assert any(needle.encoding == "utf-16-le" for needle in needles)
    assert any(needle.encoding == "cp1251" for needle in needles)
    assert any(not needle.is_full and "Уважаемые жители" in needle.text for needle in needles)


def test_scan_chunks_finds_utf16_hit_across_chunk_boundary() -> None:
    query = "Los Santos County Sheriff Department"
    needle = build_needles(
        query,
        encodings=("utf-16-le",),
        min_fragment_chars=8,
        max_fragment_chars=64,
        max_fragments=2,
    )[0]
    memory = b"A" * 15 + needle.data + b"B" * 10
    base = 0x10000000000

    def read_chunk(addr: int, size: int) -> bytes:
        offset = addr - base
        return memory[offset : offset + size]

    hits = _scan_chunks(
        read_chunk,
        base,
        base + len(memory),
        [needle],
        chunk_size=16,
        overlap=len(needle.data) - 1,
        limit=5,
    )

    assert [hit.addr for hit in hits] == [base + 15]
    assert hits[0].needle.encoding == "utf-16-le"
