from __future__ import annotations

from datetime import datetime

from sonar.fishing.statistics import FishPrice, FishingSessionStats
from sonar.fishing.statistics_export import default_stats_csv_path, write_stats_csv


def test_default_stats_csv_path_contains_date_salt_and_app_name(tmp_path, monkeypatch):
    monkeypatch.setattr("sonar.fishing.statistics_export.secrets.token_hex", lambda size: "abc123")

    path = default_stats_csv_path(tmp_path, "My: Build", datetime(2026, 5, 20, 10, 11, 12))

    assert path.name == "stats_20260520_101112_abc123_My_ Build.csv"


def test_write_stats_csv_contains_totals_and_fish_rows(tmp_path):
    stats = FishingSessionStats(default_prices={"albula": FishPrice(1.0, 2.0, 1000.0, 2000.0)})
    stats.record_catch("albula", "Albula", 3.1, kept=True)
    stats.record_catch("albula", "Albula", 1.0, kept=False)
    path = tmp_path / "stats.csv"

    write_stats_csv(path, stats, app_name="Build", build_hash="hash-1")

    text = path.read_text(encoding="utf-8-sig")
    assert "Программа;Build" in text
    assert "Хэш билда;hash-1" in text
    assert "Общий вес;3.1 кг" in text
    assert "Albula;2 шт · 4.1 кг;1 шт · 1 кг;1-2 $/шт · 1000-2000 $/1000;;от 3 100 $ до 6 200 $" in text
