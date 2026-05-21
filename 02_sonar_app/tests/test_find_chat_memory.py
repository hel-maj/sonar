from __future__ import annotations

from sonar.tools.dump_chat_history import (
    CHAT_MARKERS,
    ChatRecord,
    DumpMemoryTracker,
    _dedupe_records,
    _extract_active_tab_from_text,
    _extract_chat_input_fragments,
    _extract_rendered_records_from_text,
    _extract_records_from_text,
    _extract_wide_fragments,
    _infer_active_tab_from_records,
    _known_chat_tabs,
    _merge_history_data,
    _select_chat_candidates,
)
from sonar.tools.find_chat_memory import _scan_chunks, build_needles


def test_build_needles_contains_russian_encodings_and_fragments() -> None:
    query = (
        "Sheriff Department: \u0423\u0432\u0430\u0436\u0430\u0435\u043c\u044b\u0435 "
        "\u0436\u0438\u0442\u0435\u043b\u0438 \u0448\u0442\u0430\u0442\u0430! "
        "\u0412 \u0434\u0430\u043d\u043d\u044b\u0439 \u043c\u043e\u043c\u0435\u043d\u0442 "
        "\u043f\u0440\u043e\u0445\u043e\u0434\u0438\u0442 "
        "\u0441\u043e\u0431\u0435\u0441\u0435\u0434\u043e\u0432\u0430\u043d\u0438\u0435 "
        "\u0432 Los Santos County Sheriff Department."
    )

    needles = build_needles(query, min_fragment_chars=16, max_fragment_chars=48, max_fragments=8)

    assert any(needle.encoding == "utf-8" and needle.is_full for needle in needles)
    assert any(needle.encoding == "utf-16-le" for needle in needles)
    assert any(needle.encoding == "cp1251" for needle in needles)
    assert any(
        not needle.is_full
        and "\u0423\u0432\u0430\u0436\u0430\u0435\u043c\u044b\u0435 \u0436\u0438\u0442\u0435\u043b\u0438" in needle.text
        for needle in needles
    )


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


def test_extract_chat_records_repairs_percent_encoded_cyrillic() -> None:
    text = (
        '{"type":"systemXYZext":"[gov] @{33CCFF}Sheriff Department: '
        "%D0%A3%D0%B2%D0%B0%D0%B6%D0%B0%D0%B5%D0%BC%D1%8B%D0%B5 "
        '%D0%B6%D0%B8%D1%82%D0%B5%D0%BB%D0%B8","timestamp":1779293952307}'
    )

    records = _extract_records_from_text(text, 0x1000, "utf-8", "0x1000-0x2000", 1)

    assert len(records) == 1
    assert records[0].type == "system"
    assert records[0].timestamp == 1779293952307
    assert records[0].text == "[gov] Sheriff Department: \u0423\u0432\u0430\u0436\u0430\u0435\u043c\u044b\u0435 \u0436\u0438\u0442\u0435\u043b\u0438"


def test_extract_wide_fragments_keeps_chat_tail() -> None:
    data = (
        "noise\x00"
        "[gov] \u041c\u044b \u043d\u0430\u0445\u043e\u0434\u0438\u043c\u0441\u044f "
        "\u043f\u043e \u0430\u0434\u0440\u0435\u0441\u0443: "
        "\u041f\u0430\u043b\u0435\u0442\u0442\u043e-\u0411\u044d\u0439. "
        "\u0421 \u0443\u0432\u0430\u0436\u0435\u043d\u0438\u0435\u043c, Logistics & Supply Division."
        "\x00tail"
    ).encode("utf-16-le")

    fragments = _extract_wide_fragments(data, 0x5000, "0x5000-0x6000", min_chars=24)

    assert len(fragments) == 1
    assert "Logistics & Supply Division" in fragments[0].text


def test_extract_chat_records_supports_default_short_messages() -> None:
    text = '{"type":"default","text":"\u041a\u0440\u0443\u0442\u043e\u0439 \u0433\u0430\u0440\u0430\u0436!","timestamp":1779294500123,"messageId":12}'

    records = _extract_records_from_text(text, 0x1000, "utf-8", "0x1000-0x2000", 1)

    assert len(records) == 1
    assert records[0].type == "default"
    assert records[0].text == "\u041a\u0440\u0443\u0442\u043e\u0439 \u0433\u0430\u0440\u0430\u0436!"
    assert records[0].messageId == "12"


def test_extract_chat_records_keeps_owner_metadata_fields() -> None:
    text = (
        '{"type":"default","text":"\u041c\u0430\u0440\u0432\u0438\u043d '
        '\u0433\u043e\u0432\u043e\u0440\u0438\u0442: '
        '\u043a\u0440\u0443\u0442\u043e\u0439 \u0433\u0430\u0440\u0430\u0436",'
        '"timestamp":1779294500123,"messageId":"m-42","id":"row-7",'
        '"playerId":590,"staticId":123456,"playerName":"Marvin Angels","phoneNumber":"5551234"}'
    )

    records = _extract_records_from_text(text, 0x1000, "utf-8", "webengine", 1, "majestic-webengine.exe", 32276)

    assert len(records) == 1
    record = records[0]
    assert record.process == "majestic-webengine.exe"
    assert record.pid == 32276
    assert record.id == "row-7"
    assert record.messageId == "m-42"
    assert record.playerId == "590"
    assert record.staticId == "123456"
    assert record.playerName == "Marvin Angels"
    assert record.phoneNumber == "5551234"
    assert record.owner == {"name": "Marvin Angels", "playerId": "590", "staticId": "123456"}


def test_extract_chat_records_stops_before_duration_and_prefers_visible_news_owner() -> None:
    text = (
        '{"type":"news","text":"[Weazel News] Rei Omens: '
        '\u041d\u0430\u0431\u043e\u0440 \u0432 \u0441\u0435\u043c\u044c\u044e Plugg. '
        '\u041f\u043e\u0447\u0442\u0430: korrnis@ds.gg.","duration":10000,'
        '"createAt":1779359542,"id":"25609","userName":"Sottik Pluggerr",'
        '"editorName":"Rei Omens","timestamp":1779359540332}'
    )

    records = _extract_records_from_text(text, 0x1000, "utf-8", "webengine", 1)

    assert len(records) == 1
    record = records[0]
    assert record.text == (
        "[Weazel News] Rei Omens: "
        "\u041d\u0430\u0431\u043e\u0440 \u0432 \u0441\u0435\u043c\u044c\u044e Plugg. "
        "\u041f\u043e\u0447\u0442\u0430: korrnis@ds.gg."
    )
    assert record.id == "25609"
    assert record.messageId == "25609"
    assert record.stableId
    assert record.playerName == "Rei Omens"
    assert record.owner == {
        "name": "Rei Omens",
        "kind": "player",
        "organization": "Weazel News",
        "userName": "Sottik Pluggerr",
    }


def test_extract_chat_input_fragments_keeps_short_draft_text() -> None:
    data = (
        "copy-input\x00cb\x00chatInput\x00"
        "\u0421\u043a\u043e\u0440\u043e \u0437\u0430\u043a\u0440\u043e\u044e "
        "\u043a\u043e\u043d\u0442\u0440\u0430\u043a\u0442 \u043d\u0430\u043a\u043e\u043d\u0435\u0446"
        "\x00off"
    ).encode("utf-16-le")

    fragments = _extract_chat_input_fragments(data, 0x7000, "0x7000-0x8000", min_chars=8)

    assert [fragment.text for fragment in fragments] == [
        "\u0421\u043a\u043e\u0440\u043e \u0437\u0430\u043a\u0440\u043e\u044e \u043a\u043e\u043d\u0442\u0440\u0430\u043a\u0442 \u043d\u0430\u043a\u043e\u043d\u0435\u0446"
    ]


def test_extract_rendered_records_finds_webengine_chat_lines() -> None:
    text = (
        "\u00e5\x03-@{ffffff}Marvin Angels \u0433\u043e\u0432\u043e\u0440\u0438\u0442: "
        "\u041a\u0440\u0443\u0442\u043e\u0439 \u0433\u0430\u0440\u0430\u0436!"
        "\u00e5\x03-[default] @{c2a2da}Marvin Angels "
        "\u0432\u043a\u0443\u0441\u043d\u043e \u043f\u043e\u043f\u0438\u043b"
        "\u00e5\x03a[fam] @{f745a4}[\u0421\u0435\u043c\u044c\u044f] [XD99] "
        "Dep.Leader Marvin Angels [590]: (( "
        "\u0421\u043a\u043e\u0440\u043e \u0437\u0430\u043a\u0440\u043e\u044e "
        "\u043a\u043e\u043d\u0442\u0440\u0430\u043a\u0442 \u043d\u0430\u043a\u043e\u043d\u0435\u0446 ))"
    )

    records = _extract_rendered_records_from_text(text, 0x9000, "utf-16-le", "webengine", 2)

    assert [(record.type, record.text) for record in records] == [
        ("default", "Marvin Angels \u0433\u043e\u0432\u043e\u0440\u0438\u0442: \u041a\u0440\u0443\u0442\u043e\u0439 \u0433\u0430\u0440\u0430\u0436!"),
        ("default", "[default] Marvin Angels \u0432\u043a\u0443\u0441\u043d\u043e \u043f\u043e\u043f\u0438\u043b"),
        (
            "family",
            "[fam] [\u0421\u0435\u043c\u044c\u044f] [XD99] Dep.Leader Marvin Angels [590]: (( "
            "\u0421\u043a\u043e\u0440\u043e \u0437\u0430\u043a\u0440\u043e\u044e "
            "\u043a\u043e\u043d\u0442\u0440\u0430\u043a\u0442 \u043d\u0430\u043a\u043e\u043d\u0435\u0446 ))",
        ),
    ]
    assert records[0].playerName == "Marvin Angels"
    assert records[2].playerName == "Marvin Angels"
    assert records[2].playerId == "590"
    assert records[2].owner["role"] == "Dep.Leader"


def test_extract_rendered_records_joins_split_weazel_phone_nodes() -> None:
    text = (
        "\u00e5\x03<@{24df42}[Weazel News] Rei Omens: "
        "\u041a\u0443\u043f\u043b\u044e \u0430\u0432\u0442\u043e\u043c\u043e\u0431\u0438\u043b\u044c Ferruccio Ursus. "
        "\u0411\u044e\u0434\u0436\u0435\u0442: \u0441\u0432\u043e\u0431\u043e\u0434-"
        "\u00e5\x03\u0014\u043d\u044b\u0439. \u0422\u0435\u043b. \u043d\u043e\u043c\u0435\u0440: 22004504"
    )

    records = _extract_rendered_records_from_text(text, 0xA000, "utf-16-le", "webengine", 2)

    assert len(records) == 1
    record = records[0]
    assert record.type == "news"
    assert record.phoneNumber == "22004504"
    assert record.messageId == record.stableId
    assert record.raw_fields["messageId_source"] == "stable_hash"
    assert record.color == "#24df42"
    assert record.formatting["source"] == "memory.inline_tag"
    assert "Ferruccio Ursus" in record.text
    assert record.owner == {"name": "Rei Omens", "kind": "player", "organization": "Weazel News"}


def test_extract_rendered_records_keeps_visible_actions_but_rejects_static_catalog() -> None:
    text = (
        "@{c2a2da}Marvin Angels \u043e\u043f\u044f\u0442\u044c "
        "\u043b\u044e\u0431\u0443\u0435\u0442\u0441\u044f \u0433\u0430\u0440\u0430\u0436\u043e\u043c"
        "\x00@{c2a2da}Marvin Angels \u043f\u0440\u0438\u0441\u0442\u0435\u0433\u043d\u0443\u043b "
        "\u0440\u0435\u043c\u0435\u043d\u044c \u0431\u0435\u0437\u043e\u043f\u0430\u0441\u043d\u043e\u0441\u0442\u0438"
        "\x00Ferruccio Ursus Kreed Edition"
        "\x00Social Club \u043d\u0435 \u043d\u0430\u0448\u0435\u043b\u0441\u044f"
    )

    records = _extract_rendered_records_from_text(text, 0xB000, "utf-16-le", "webengine", 2)

    assert [(record.type, record.playerName, record.text) for record in records] == [
        (
            "me",
            "Marvin Angels",
            "Marvin Angels \u043e\u043f\u044f\u0442\u044c \u043b\u044e\u0431\u0443\u0435\u0442\u0441\u044f \u0433\u0430\u0440\u0430\u0436\u043e\u043c",
        ),
        (
            "me",
            "Marvin Angels",
            "Marvin Angels \u043f\u0440\u0438\u0441\u0442\u0435\u0433\u043d\u0443\u043b "
            "\u0440\u0435\u043c\u0435\u043d\u044c \u0431\u0435\u0437\u043e\u043f\u0430\u0441\u043d\u043e\u0441\u0442\u0438",
        ),
    ]


def test_extract_rendered_records_keeps_majestic_welcome_not_templates() -> None:
    text = (
        "\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c "
        "\u043d\u0430 Majestic Role Play, Marvin Angels!"
        "\x00\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c "
        "\u043d\u0430 Majestic Role Play, {name}!"
    )

    records = _extract_rendered_records_from_text(text, 0xC000, "utf-16-le", "webengine", 2)

    assert [record.text for record in records] == [
        "\u0414\u043e\u0431\u0440\u043e \u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c "
        "\u043d\u0430 Majestic Role Play, Marvin Angels!"
    ]
    assert records[0].type == "system"


def test_extract_rendered_records_cleans_default_ooc_owner_name() -> None:
    text = "[default] @{c9c9c9}Marvin Angels: (( \u0431\u043b\u044f, \u0447\u0443\u0442\u044c \u043d\u0435 \u043f\u043e\u043c\u0435\u0440 ))"

    records = _extract_rendered_records_from_text(text, 0xC000, "utf-16-le", "webengine", 2)

    assert len(records) == 1
    assert records[0].playerName == "Marvin Angels"
    assert records[0].owner == {"name": "Marvin Angels", "kind": "player"}


def test_extract_rendered_records_filters_templates() -> None:
    text = (
        '{name} \u0433\u043e\u0432\u043e\u0440\u0438\u0442: {text}'
        '\x00p["name"]+" \u0433\u043e\u0432\u043e\u0440\u0438\u0442: "+p["text"]'
        "\x00[gov] EmergIQ%"
    )

    records = _extract_rendered_records_from_text(text, 0x9000, "utf-16-le", "webengine", 2)

    assert records == []


def test_rendered_owner_does_not_treat_system_text_as_player() -> None:
    text = (
        "[default] \u0414\u043e\u0431\u0440\u043e "
        "\u043f\u043e\u0436\u0430\u043b\u043e\u0432\u0430\u0442\u044c "
        "\u043d\u0430 Majestic Role Play"
        "\x00[global] \u0422\u0435\u043a\u0443\u0449\u0435\u0435 "
        "\u0432\u0440\u0435\u043c\u044f 11:00!"
    )

    records = _extract_rendered_records_from_text(text, 0x9000, "utf-16-le", "webengine", 2)

    assert [record.playerName for record in records] == [None, None]
    assert [record.owner for record in records] == [{}, {}]


def test_chat_history_markers_are_generic_not_single_message_anchors() -> None:
    assert '"type":"' in CHAT_MARKERS
    assert '"text":"' in CHAT_MARKERS
    assert "chatInput" in CHAT_MARKERS
    assert "[default]" in CHAT_MARKERS
    assert "Sheriff" not in CHAT_MARKERS
    assert "Logistics" not in CHAT_MARKERS
    assert "DriveD" not in CHAT_MARKERS
    assert "phoneNumber" not in CHAT_MARKERS
    assert "isLocation" not in CHAT_MARKERS


def test_extract_active_tab_from_serialized_chat_state() -> None:
    text = '{"chatIsActive":true,"activeFilter":{"id":"fam","name":"\u0421\u0435\u043c\u044c\u044f"}}'

    tab = _extract_active_tab_from_text(text, 0x2000, "utf-8", "state", 1)

    assert tab is not None
    assert tab["id"] == "fam"
    assert tab["name"] == "\u0421\u0435\u043c\u044c\u044f"
    assert tab["confidence"] == "high"
    assert tab["addr"] == "0x2015"


def test_extract_active_tab_from_numeric_state() -> None:
    tab = _extract_active_tab_from_text('{"selectedTab":2}', 0x3000, "utf-8", "state", 1)

    assert tab is not None
    assert tab["id"] == "2"
    assert tab["name"] == "\u0424\u0440\u0430\u043a\u0446\u0438\u044f"


def test_infer_active_tab_from_memory_records() -> None:
    tab = _infer_active_tab_from_records(
        [
            {"type": "default", "text": "Marvin Angels \u0433\u043e\u0432\u043e\u0440\u0438\u0442: test"},
            {"type": "family", "text": "[fam] [\u0421\u0435\u043c\u044c\u044f] Marvin Angels [590]: test"},
            {"type": "system", "text": "[gov] Government: test"},
        ]
    )

    assert tab is not None
    assert tab["id"] == "all"
    assert tab["name"] == "\u0412\u0441\u0435"
    assert tab["confidence"] == "inferred"
    assert tab["channels"] == ["default", "family", "gov"]


def test_infer_family_tab_from_family_only_records() -> None:
    tab = _infer_active_tab_from_records([{"type": "family", "text": "[fam] hello"}])

    assert tab is not None
    assert tab["id"] == "fam"
    assert tab["name"] == "\u0421\u0435\u043c\u044c\u044f"


def test_known_chat_tabs_marks_active_tab() -> None:
    tabs = _known_chat_tabs({"id": "fam"})

    assert [tab["id"] for tab in tabs] == ["all", "fam", "frac", "gov", "report"]
    assert [tab["active"] for tab in tabs] == [False, True, False, False, False]


def test_dump_memory_tracker_reads_manifest_regions(tmp_path) -> None:
    data_path = tmp_path / "memory.bin"
    data_path.write_bytes(b"hello" + b"chatInput" + b"world")
    tracker = DumpMemoryTracker(
        tmp_path,
        {
            "process": "majestic-webengine.exe",
            "pid": 123,
            "data_file": "memory.bin",
            "regions": [{"start": 0x1000, "end": 0x1000 + data_path.stat().st_size, "file_offset": 0}],
        },
    )
    try:
        assert tracker._collect_regions(0x1000, 0x2000) == [(0x1000, 0x1000 + data_path.stat().st_size)]
        assert tracker._read(0x1005, 9) == b"chatInput"
    finally:
        tracker.stop()


def test_dump_memory_tracker_reads_unmanifested_tail(tmp_path) -> None:
    data_path = tmp_path / "memory.bin"
    data_path.write_bytes(b"hello" + b"orphan chat tail")
    tracker = DumpMemoryTracker(
        tmp_path,
        {
            "process": "GTA5.exe",
            "pid": 123,
            "data_file": "memory.bin",
            "regions": [{"start": 0x1000, "end": 0x1005, "size": 5, "file_offset": 0}],
        },
    )
    try:
        regions = tracker._collect_regions(0, 0x40000000000)
        assert len(regions) == 2
        orphan_start, orphan_end = regions[-1]
        assert orphan_end - orphan_start == len(b"orphan chat tail")
        assert tracker._read(orphan_start, orphan_end - orphan_start) == b"orphan chat tail"
        assert tracker.info["orphan_tail_bytes"] == len(b"orphan chat tail")
    finally:
        tracker.stop()


def test_select_chat_candidates_prefers_scored_chat_renderer() -> None:
    selected = _select_chat_candidates(
        [
            {"process": "majestic-webengine.exe", "pid": 11, "role": "renderer", "score": 90, "marker_hit_count": 0},
            {"process": "GTA5.exe", "pid": 12, "score": 120, "marker_hit_count": 2},
            {"process": "majestic-webengine.exe", "pid": 13, "role": "renderer", "score": 500, "marker_hit_count": 5},
        ],
        limit=1,
    )

    assert selected == [
        {"process": "majestic-webengine.exe", "pid": 13, "role": "renderer", "score": 500, "marker_hit_count": 5}
    ]


def test_select_chat_candidates_rejects_unscored_candidates() -> None:
    assert _select_chat_candidates(
        [{"process": "majestic-webengine.exe", "pid": 11, "role": "renderer", "score": 90, "marker_hit_count": 0}],
        limit=1,
    ) == []


def test_merge_history_data_accumulates_and_dedupes_records() -> None:
    existing = {
        "created_at": 1.0,
        "records": [
            {"type": "news", "timestamp": 10, "time": "t1", "text": "first line", "source": "old"},
        ],
        "fragments": [
            {"text": "[gov] first rendered fragment", "addr": 10, "encoding": "utf-16-le", "source": "old"},
        ],
        "snapshots": [],
    }
    incoming = {
        "created_at": 2.0,
        "process": "gta5.exe",
        "pid": 123,
        "records": [
            {"type": "news", "timestamp": 10, "time": "t1", "text": "first line", "source": "new"},
            {"type": "system", "timestamp": 20, "time": "t2", "text": "second line", "source": "new"},
        ],
        "fragments": [
            {"text": "[gov] first rendered fragment", "addr": 10, "encoding": "utf-16-le", "source": "new"},
            {"text": "[me] second rendered fragment", "addr": 20, "encoding": "utf-16-le", "source": "new"},
        ],
        "marker_hit_count": 2,
        "windows": 1,
    }

    merged = _merge_history_data(existing, incoming, fragment_limit=10)

    assert merged["kind"] == "sonar_chat_history_latest"
    assert merged["created_at"] == 1.0
    assert merged["process"] == "gta5.exe"
    assert [record["text"] for record in merged["records"]] == ["first line", "second line"]
    assert [fragment["text"] for fragment in merged["fragments"]] == [
        "[gov] first rendered fragment",
        "[me] second rendered fragment",
    ]
    assert merged["snapshots"][-1]["records"] == 2


def test_merge_history_data_prefers_cleaner_record_for_same_timestamp() -> None:
    incoming = {
        "created_at": 2.0,
        "records": [
            {"type": "system", "timestamp": 20, "text": "[gov] Good text %B B H H + + + + + + + + garbage"},
            {"type": "system", "timestamp": 20, "text": "[gov] Good text"},
        ],
        "fragments": [],
    }

    merged = _merge_history_data(None, incoming, fragment_limit=10)

    assert [record["text"] for record in merged["records"]] == ["[gov] Good text"]


def test_dedupe_records_prefers_timestamped_copy_for_same_text() -> None:
    rendered = ChatRecord(
        type="news",
        text="[Weazel News] Rei Omens: text",
        timestamp=None,
        time=None,
        phoneNumber=None,
        id=None,
        source="rendered",
        encoding="utf-16-le",
        pos=20,
        messageId="stable",
        stableId="stable",
    )
    serialized = ChatRecord(
        type="news",
        text="[Weazel News] Rei Omens: text",
        timestamp=1779359540332,
        time="2026-05-21 13:32:20.332",
        phoneNumber=None,
        id="25609",
        source="serialized",
        encoding="utf-16-le",
        pos=10,
        messageId="25609",
        stableId="stable",
    )

    records = _dedupe_records([rendered, serialized])

    assert records == [serialized]


def test_merge_history_data_filters_code_fragments() -> None:
    incoming = {
        "created_at": 2.0,
        "records": [],
        "fragments": [
            {
                "text": 'const item = { text: e.text, phoneNumber: e.phoneNumber, isLocation: e.isLocation };',
                "addr": 10,
                "encoding": "utf-16-le",
                "source": "bundle",
            },
            {"text": "[gov] rendered chat fragment", "addr": 20, "encoding": "utf-16-le", "source": "chat"},
            {
                "text": "\u0421\u043a\u043e\u0440\u043e \u0437\u0430\u043a\u0440\u043e\u044e \u043a\u043e\u043d\u0442\u0440\u0430\u043a\u0442",
                "addr": 30,
                "encoding": "utf-16-le",
                "source": "chat_input",
            },
        ],
    }

    merged = _merge_history_data(None, incoming, fragment_limit=10)

    assert [fragment["text"] for fragment in merged["fragments"]] == [
        "[gov] rendered chat fragment",
        "\u0421\u043a\u043e\u0440\u043e \u0437\u0430\u043a\u0440\u043e\u044e \u043a\u043e\u043d\u0442\u0440\u0430\u043a\u0442",
    ]
