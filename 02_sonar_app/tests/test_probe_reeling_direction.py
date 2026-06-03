from __future__ import annotations

import json
import struct
from pathlib import Path

import numpy as np
import pytest

from sonar.tools import probe_reeling_direction as probe_module
from sonar.fishing.memory_reeling import (
    FISH_DIRECTION_ANCHOR_OFFSET,
    FISH_DIRECTION_FIELD_CONFIG,
    FISH_MODEL_HASH,
    PTR_MIN,
    ReelingState,
)
from sonar.tools.analyze_reeling_completion import analyze as analyze_completion
from sonar.tools.analyze_reeling_completion import infer_completion_boundary
from sonar.tools.analyze_reeling_memory import analyze
from sonar.tools.probe_reeling_direction import (
    DEFAULT_AUTO_STOP_IDLE_SECONDS,
    DEFAULT_CANDIDATE_BYTES,
    DEFAULT_FISH_BYTES,
    DEFAULT_PLAYER_BYTES,
    FALLBACK_READ_CHUNK_BYTES,
    _direction_fixture_indices,
    _keyboard_snapshot,
    _padded_linked_pointer_snapshot,
    _probe_tracker_step,
    _read_bytes,
    _should_auto_stop_idle,
    _write_fixture,
    build_parser,
    replay_direction_fixture,
)


def test_probe_defaults_capture_wider_tracked_fish_window() -> None:
    args = build_parser().parse_args([])

    assert args.fish_bytes == DEFAULT_FISH_BYTES
    assert args.player_bytes == DEFAULT_PLAYER_BYTES
    assert args.candidate_bytes == DEFAULT_CANDIDATE_BYTES
    assert args.fish_bytes > args.candidate_bytes
    assert args.auto_stop_idle == DEFAULT_AUTO_STOP_IDLE_SECONDS
    assert args.label_keys == "ad"


def test_probe_accepts_hexadecimal_capture_sizes() -> None:
    args = build_parser().parse_args(["--fish-bytes", "0x8000", "--candidate-bytes", "0x800"])

    assert args.fish_bytes == 0x8000
    assert args.candidate_bytes == 0x800


def test_probe_accepts_independent_arrow_label_keys() -> None:
    args = build_parser().parse_args(["--label-keys", "arrows"])

    assert args.label_keys == "arrows"


def test_keyboard_snapshot_reads_independent_arrow_labels(monkeypatch) -> None:
    monkeypatch.setattr(probe_module, "_key_down", lambda vk: vk == probe_module.VK_LEFT)

    assert _keyboard_snapshot("arrows") == (-1, True, False)


def test_linked_pointer_snapshot_deduplicates_and_skips_unreadable_targets() -> None:
    source_addr = PTR_MIN + 0x10000
    target_addr = PTR_MIN + 0x20000
    unreadable_addr = PTR_MIN + 0x30000
    source = bytearray(0x30)
    struct.pack_into("<Q", source, 0x08, target_addr)
    struct.pack_into("<Q", source, 0x10, target_addr)
    struct.pack_into("<Q", source, 0x18, unreadable_addr)

    class DummyTracker:
        @staticmethod
        def _is_ptr(addr: int | None) -> bool:
            return bool(addr and PTR_MIN <= addr)

        @staticmethod
        def _read(addr: int, size: int) -> bytes | None:
            if addr == source_addr:
                return bytes(source[:size])
            if addr == target_addr:
                return b"\xAB" * size
            return None

    offsets, addrs, raw, json_targets = _padded_linked_pointer_snapshot(
        DummyTracker(),
        source_addr,
        scan_bytes=len(source),
        target_bytes=0x20,
        limit=4,
    )

    assert offsets.tolist() == [0x08, -1, -1, -1]
    assert addrs.tolist() == [target_addr, 0, 0, 0]
    assert raw[0].tolist() == [0xAB] * 0x20
    assert json_targets == [{"source_offset": "0x8", "addr": f"0x{target_addr:X}"}]


def test_right_vec_from_snapshot_reads_player_matrix_row() -> None:
    raw = np.zeros(0x100, dtype=np.uint8)
    struct.pack_into("<4f", raw, probe_module.PLAYER_MATRIX_OFFSETS[0], 0.6, 0.8, 0.0, 0.0)

    right = probe_module._right_vec_from_snapshot(raw)

    assert np.allclose(right, (0.6, 0.8))


def test_probe_tracker_step_runs_only_cheap_fish_retry_by_default() -> None:
    class DummyTracker:
        handle = 1
        fish_addr = None
        player_addr = PTR_MIN + 0x10000
        allow_deep_search: bool | None = None

        @staticmethod
        def step() -> ReelingState:
            raise AssertionError("Default diagnostic capture must not run expensive fish retry scans")

        def _retry_find_fish(self, *, allow_deep_search: bool) -> None:
            self.allow_deep_search = allow_deep_search

    tracker = DummyTracker()

    state = _probe_tracker_step(tracker, allow_deep_search=False)

    assert tracker.allow_deep_search is False
    assert tracker.fish_addr is None
    assert state.action == "target_search"


def test_wide_snapshot_falls_back_to_partial_chunk_reads() -> None:
    addr = PTR_MIN + 0x60000
    size = FALLBACK_READ_CHUNK_BYTES * 3

    class DummyTracker:
        @staticmethod
        def _read(read_addr: int, read_size: int) -> bytes | None:
            if read_size > FALLBACK_READ_CHUNK_BYTES:
                return None
            if read_addr == addr:
                return b"\x11" * read_size
            if read_addr == addr + FALLBACK_READ_CHUNK_BYTES * 2:
                return b"\x33" * read_size
            return None

    raw = _read_bytes(DummyTracker(), addr, size)

    assert raw[:FALLBACK_READ_CHUNK_BYTES].tolist() == [0x11] * FALLBACK_READ_CHUNK_BYTES
    assert raw[FALLBACK_READ_CHUNK_BYTES : FALLBACK_READ_CHUNK_BYTES * 2].tolist() == [0] * FALLBACK_READ_CHUNK_BYTES
    assert raw[FALLBACK_READ_CHUNK_BYTES * 2 :].tolist() == [0x33] * FALLBACK_READ_CHUNK_BYTES


def test_auto_stop_waits_for_manual_activity_and_idle_tail() -> None:
    assert not _should_auto_stop_idle(8.0, 0, 0, None, idle_seconds=5.0, minimum_manual_samples=25)
    assert not _should_auto_stop_idle(8.0, 1, 100, 2.0, idle_seconds=5.0, minimum_manual_samples=25)
    assert not _should_auto_stop_idle(6.9, 0, 100, 2.0, idle_seconds=5.0, minimum_manual_samples=25)
    assert _should_auto_stop_idle(7.0, 0, 100, 2.0, idle_seconds=5.0, minimum_manual_samples=25)


def test_completion_analyzer_reports_changed_fish_field(tmp_path: Path) -> None:
    path = tmp_path / "capture.npz"
    perf_times = np.arange(0.0, 12.0, 0.1, dtype=np.float64)
    key_labels = np.where(perf_times < 6.0, 1, 0).astype(np.int8)
    fish_bytes = np.zeros((perf_times.size, 0x80), dtype=np.uint8)
    fish_bytes[perf_times < 6.0, 0x24] = 1
    np.savez_compressed(
        path,
        perf_times=perf_times,
        key_labels=key_labels,
        fish_bytes=fish_bytes,
        fish_before_bytes=np.zeros((perf_times.size, 0), dtype=np.uint8),
        player_bytes=np.zeros((perf_times.size, 0), dtype=np.uint8),
    )

    boundary = infer_completion_boundary(perf_times, key_labels)
    report_path = analyze_completion(path)
    report = report_path.read_text(encoding="utf-8")

    assert boundary is not None
    assert boundary[0] == 59
    assert "idle_tail_seconds=6.000" in report
    assert "fish     off=0x024 byte pre=1   tail=0" in report


def _capture_with_anchor_labels(path: Path, labels: np.ndarray) -> None:
    fish_bytes = np.zeros((labels.size, 0x400), dtype=np.uint8)
    fish_bytes[:, probe_module.FISH_REELING_ACTIVE_OFFSET] = probe_module.FISH_REELING_ACTIVE_VALUE
    polarity = FISH_DIRECTION_FIELD_CONFIG[FISH_DIRECTION_ANCHOR_OFFSET][1]
    for index, label in enumerate(labels.tolist()):
        struct.pack_into("<f", fish_bytes[index], FISH_DIRECTION_ANCHOR_OFFSET, float(label) * polarity * 0.5)
    np.savez_compressed(
        path,
        perf_times=np.arange(labels.size, dtype=np.float64) * 0.02,
        key_labels=labels,
        fish_addrs=np.full(labels.size, PTR_MIN + 0x50000, dtype=np.uint64),
        fish_hashes=np.full(labels.size, FISH_MODEL_HASH, dtype=np.int64),
        fish_bytes=fish_bytes,
        metadata=json.dumps({"kind": "sonar_reeling_direction_probe", "version": 2}),
    )


def test_exported_fixture_replays_direction_labels(tmp_path: Path) -> None:
    capture_path = tmp_path / "capture.npz"
    fixture_path = tmp_path / "capture.fixture.npz"
    labels = np.array([-1] * 60 + [1] * 60 + [-1] * 60 + [1] * 120, dtype=np.int8)
    _capture_with_anchor_labels(capture_path, labels)

    _write_fixture(capture_path, fixture_path, max_samples=100, minimum_accuracy=0.9)

    accuracy, sample_count = replay_direction_fixture(fixture_path)
    fixture = np.load(fixture_path, allow_pickle=False)
    assert accuracy == 1.0
    assert 0 < sample_count < labels.size
    assert fixture["completion_fish_bytes"].shape == (0, fixture["fish_bytes"].shape[1])


def test_direction_fixture_indices_exclude_transitions_and_noisy_tail() -> None:
    perf_times = np.arange(0.0, 6.0, 0.1, dtype=np.float64)
    labels = np.where(perf_times < 3.0, -1, 1).astype(np.int8)
    fish_addrs = np.full(labels.size, PTR_MIN + 0x50000, dtype=np.uint64)
    fish_hashes = np.full(labels.size, FISH_MODEL_HASH, dtype=np.int64)

    valid = _direction_fixture_indices(perf_times, labels, fish_addrs, fish_hashes, max_samples=100)
    valid_times = perf_times[valid]

    assert valid_times.size > 0
    assert np.all(np.abs(valid_times - 3.0) > 0.18)
    assert np.all(valid_times <= 3.9 + 1e-9)


def test_direction_fixture_indices_exclude_finished_fish_samples() -> None:
    perf_times = np.arange(0.0, 5.0, 0.1, dtype=np.float64)
    labels = np.ones(perf_times.size, dtype=np.int8)
    fish_addrs = np.full(labels.size, PTR_MIN + 0x50000, dtype=np.uint64)
    fish_hashes = np.full(labels.size, FISH_MODEL_HASH, dtype=np.int64)
    fish_bytes = np.zeros((labels.size, 0x200), dtype=np.uint8)
    fish_bytes[:, probe_module.FISH_REELING_ACTIVE_OFFSET] = probe_module.FISH_REELING_ACTIVE_VALUE
    fish_bytes[perf_times >= 2.0, probe_module.FISH_REELING_ACTIVE_OFFSET] = 0

    valid = _direction_fixture_indices(
        perf_times,
        labels,
        fish_addrs,
        fish_hashes,
        max_samples=100,
        fish_bytes=fish_bytes,
    )

    assert np.all(perf_times[valid] < 2.0)


def test_analyzer_scans_tracked_fish_bytes(tmp_path: Path) -> None:
    path = tmp_path / "capture.npz"
    labels = np.array([-1, 1] * 8, dtype=np.int8)
    fish_bytes = np.zeros((labels.size, 0x180), dtype=np.uint8)
    for index, label in enumerate(labels.tolist()):
        struct.pack_into("<f", fish_bytes[index], 0x100, float(label))
    np.savez_compressed(
        path,
        key_labels=labels,
        entity_bytes=np.zeros((0, 1, 4), dtype=np.uint8),
        entity_addrs=np.zeros((0, 1), dtype=np.uint64),
        entity_key_labels=np.zeros(0, dtype=np.int8),
        player_bytes=np.zeros((labels.size, 4), dtype=np.uint8),
        player_addrs=np.zeros(labels.size, dtype=np.uint64),
        fish_bytes=fish_bytes,
        fish_addrs=np.full(labels.size, PTR_MIN + 0x50000, dtype=np.uint64),
        metadata=json.dumps({"kind": "sonar_reeling_direction_probe", "version": 2}),
    )

    report_path = analyze(path, top=10)
    report = report_path.read_text(encoding="utf-8")

    assert "fish     slot=0" in report
    assert "off=0x100" in report


FIXTURE_DIR = Path(__file__).parent / "fixtures" / "reeling_direction"
CHECKED_FIXTURES = sorted(FIXTURE_DIR.glob("*.npz"))
KNOWN_FAILING_FIXTURES = {
    "reeling_direction_probe_main_4_1_0_20260601_010306.fixture.npz": (
        "First manual capture reproduces the current incorrect A/D direction selection."
    ),
}
CHECKED_FIXTURE_PARAMS = [
    pytest.param(
        fixture_path,
        marks=pytest.mark.xfail(strict=True, reason=KNOWN_FAILING_FIXTURES[fixture_path.name]),
    )
    if fixture_path.name in KNOWN_FAILING_FIXTURES
    else fixture_path
    for fixture_path in CHECKED_FIXTURES
]


@pytest.mark.parametrize("fixture_path", CHECKED_FIXTURE_PARAMS)
def test_checked_reeling_direction_fixture(fixture_path: Path) -> None:
    data = np.load(fixture_path, allow_pickle=False)
    metadata = json.loads(str(data["metadata"]))
    accuracy, sample_count = replay_direction_fixture(fixture_path)

    assert sample_count > 0
    assert accuracy is not None
    assert "completion_fish_bytes" in data
    if int(metadata["completion_sample_count"]) > 0:
        assert infer_completion_boundary(data["completion_perf_times"], data["completion_key_labels"]) is not None
    assert accuracy >= float(metadata["minimum_accuracy"])
