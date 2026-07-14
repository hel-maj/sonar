from __future__ import annotations

import argparse
import json
from pathlib import Path

from sonar.fishing.memory_reeling import PTR_MIN
from sonar.tools import dump_process_memory as dpm


def test_clamp_windows_to_regions_merges_overlaps() -> None:
    windows = [(0x1000, 0x2200), (0x2000, 0x3000), (0x9000, 0xA000)]
    regions = [(0x1800, 0x2800), (0x4000, 0x5000), (0x9800, 0x9900)]

    assert dpm._clamp_windows_to_regions(windows, regions) == [(0x1800, 0x2800), (0x9800, 0x9900)]


def test_limit_regions_by_total_splits_last_region() -> None:
    one_mb = 1024 * 1024
    regions = [(0x1000, 0x1000 + one_mb), (0x400000, 0x400000 + one_mb)]

    assert dpm._limit_regions_by_total(regions, 1) == [(0x1000, 0x1000 + one_mb)]
    assert dpm._limit_regions_by_total(regions, 0) == regions


def test_collect_near_player_regions_uses_player_fish_and_replay_anchors() -> None:
    class FakeTracker:
        def _find_replay_interface_global(self) -> int:
            return PTR_MIN + 0x3000

        def _find_cped(self) -> int:
            return PTR_MIN + 0x1000

        def _read_player_pos(self, addr: int) -> tuple[float, float, float]:
            return (1.0, 2.0, 3.0)

        def _find_fish_addr_replay(self) -> int:
            return PTR_MIN + 0x5000

        def _find_fish_addr(self) -> None:
            return None

        def _read_fish_pos(self, addr: int) -> tuple[float, float, float]:
            return (4.0, 5.0, 6.0)

    args = argparse.Namespace(
        near_window_kb=4,
        near_replay_window_kb=4,
        no_near_fish=False,
        max_total_mb=0,
    )

    regions, meta = dpm._collect_near_player_regions(args, FakeTracker(), [(PTR_MIN, PTR_MIN + 0x10000)])

    assert regions == [(PTR_MIN, PTR_MIN + 0x6000)]
    assert [item["label"] for item in meta["anchors"]] == ["player", "fish", "replay_interface"]
    assert meta["anchors"][0]["position"] == {"x": 1.0, "y": 2.0, "z": 3.0}


def _write_manifest_dump(root: Path, data: bytes, *, pid: int = 123) -> None:
    process_dir = root / "GTA5.exe_123"
    process_dir.mkdir(parents=True)
    data_path = process_dir / "memory.bin"
    data_path.write_bytes(data)
    manifest = {
        "kind": "sonar_process_memory_dump",
        "version": 3,
        "processes": [
            {
                "process": "GTA5.exe",
                "pid": pid,
                "data_file": "GTA5.exe_123/memory.bin",
                "regions": [
                    {
                        "start": 0x1000,
                        "end": 0x1000 + len(data),
                        "size": len(data),
                        "file_offset": 0,
                    }
                ],
            }
        ],
    }
    (root / "manifest.json").write_text(json.dumps(manifest), encoding="utf-8")


def test_compare_memory_dumps_reports_changed_bytes(tmp_path: Path) -> None:
    left = tmp_path / "left"
    right = tmp_path / "right"
    left.mkdir()
    right.mkdir()
    _write_manifest_dump(left, b"abcd0123EFGH")
    _write_manifest_dump(right, b"abcd9123Ezzz")

    out_path = tmp_path / "diff.json"
    args = argparse.Namespace(
        compare=[str(left), str(right)],
        compare_out=str(out_path),
        compare_key="process-pid",
        diff_chunk_mb=1,
        diff_max_ranges=10,
    )

    result_path = dpm.compare_memory_dumps(args)
    report = json.loads(result_path.read_text(encoding="utf-8"))

    assert result_path == out_path
    assert report["comparable_bytes"] == 12
    assert report["changed_bytes"] == 4
    assert report["processes"][0]["changed_ranges"] == [
        {
            "start": 0x1004,
            "end": 0x100C,
            "start_hex": "0x1004",
            "end_hex": "0x100C",
            "changed_bytes": 4,
        }
    ]
