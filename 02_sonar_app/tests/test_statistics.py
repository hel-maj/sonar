from __future__ import annotations

from pathlib import Path

import pytest

from sonar.fishing import statistics
from sonar.fishing.statistics import (
    FishPrice,
    FishingSessionStats,
    format_base_price,
    format_duration_hhmm,
    format_session_title,
    format_money_range,
    parse_fish_prices_from_markdown,
)
from sonar.fishing.session_history import FishingSessionHistory


def test_embedded_price_catalog_contains_markdown_prices():
    prices = parse_fish_prices_from_markdown()

    assert len(prices) == 20
    assert prices["marlin"] == FishPrice(0.67, 0.73, 670.0, 730.0)
    assert prices["rudd_krasnoperka"] == FishPrice(1.26, 1.35, 1260.0, 1350.0)


def test_markdown_price_parser_reads_item_and_thousand_ranges(tmp_path: Path):
    note = tmp_path / "prices.md"
    note.write_text(
        "1. Краснопёрка — от <strong>1.26&#36;</strong> до <strong>1.35&#36;</strong> || "
        "<strong>1260&#36;</strong> - <strong>1350&#36;</strong>\n",
        encoding="utf-8",
    )

    prices = parse_fish_prices_from_markdown(note)

    assert prices["rudd_krasnoperka"] == FishPrice(1.26, 1.35, 1260.0, 1350.0)


def test_earnings_use_kept_weight_and_price_per_1000_without_dividing_again():
    stats = FishingSessionStats(default_prices={"marlin": FishPrice(0.67, 0.73, 670.0, 730.0)})
    stats.record_catch("marlin", "Марлин", 3.1, kept=True)
    stats.record_catch("marlin", "Марлин", 2.0, kept=False)

    totals = stats.totals()

    assert totals.kept_kg == pytest.approx(3.1)
    assert totals.earned_min == pytest.approx(2077.0)
    assert totals.earned_max == pytest.approx(2263.0)


def test_custom_price_overrides_range_and_keeps_table_field_blank_by_default():
    stats = FishingSessionStats(default_prices={"marlin": FishPrice(0.67, 0.73, 670.0, 730.0)})
    stats.record_catch("marlin", "Марлин", 3.1, kept=True)

    row = stats.rows()[0]
    assert row.custom_price is None
    assert row.earned_min == pytest.approx(2077.0)
    assert row.earned_max == pytest.approx(2263.0)

    stats.set_custom_price("marlin", 1000)
    row = stats.rows()[0]
    assert row.custom_price == 1000
    assert row.earned_min == pytest.approx(3100.0)
    assert row.earned_max == pytest.approx(3100.0)


def test_session_timer_pauses_when_bot_is_not_running(monkeypatch):
    now = [1000.0]
    monkeypatch.setattr(statistics.time, "time", lambda: now[0])
    stats = FishingSessionStats()

    stats.start_timer()
    now[0] += 10.0
    stats.stop_timer()
    stopped_duration = stats.totals().duration_seconds
    now[0] += 50.0

    assert stopped_duration == 10.0
    assert stats.totals().duration_seconds == 10.0

    stats.start_timer()
    now[0] += 5.0
    assert stats.totals().duration_seconds == 15.0


def test_money_and_price_ranges_collapse_equal_values():
    assert format_money_range(1200, 1200) == "1 200 $"
    assert format_money_range(1200, 1500) == "от 1 200 $ до 1 500 $"
    assert format_base_price(FishPrice(1.0, 1.0, 1000.0, 1000.0)) == "1 $/шт · 1000 $/1000"


def test_session_tracks_catch_size_distribution():
    stats = FishingSessionStats(default_prices={"marlin": FishPrice(0.67, 0.73, 670.0, 730.0)})

    stats.record_catch("marlin", "Марлин", 3.1, kept=True, catch_size="Скромный улов")
    stats.record_catch("marlin", "Марлин", 4.0, kept=True, catch_size="Рекордный улов")
    stats.record_catch("marlin", "Марлин", 2.0, kept=False, catch_size="Рекордный улов")

    rows = {row.label: row for row in stats.catch_size_rows()}

    assert rows["Скромный улов"].count == 1
    assert rows["Скромный улов"].percent == pytest.approx(33.333, abs=0.01)
    assert rows["Рекордный улов"].count == 2
    assert rows["Рекордный улов"].percent == pytest.approx(66.667, abs=0.01)


def test_session_resets_catch_size_distribution():
    stats = FishingSessionStats(default_prices={"marlin": FishPrice(0.67, 0.73, 670.0, 730.0)})
    stats.record_catch("marlin", "Марлин", 3.1, kept=True, catch_size="Хороший улов")

    stats.reset()

    assert all(row.count == 0 for row in stats.catch_size_rows())


def test_session_snapshot_roundtrip_and_aggregate(monkeypatch):
    now = [1000.0]
    monkeypatch.setattr(statistics.time, "time", lambda: now[0])
    stats = FishingSessionStats(default_prices={"marlin": FishPrice(0.67, 0.73, 670.0, 730.0)})
    stats.start_timer()
    now[0] += 125.0
    stats.record_catch("marlin", "Марлин", 3.1, kept=True, catch_size="Хороший улов")

    restored = FishingSessionStats.from_dict(stats.to_dict(), default_prices=stats.default_prices)
    aggregate = FishingSessionStats.aggregate([restored, restored], default_prices=stats.default_prices)

    assert restored.totals().duration_seconds == pytest.approx(125.0)
    assert restored.rows()[0].stat.caught_count == 1
    assert aggregate.totals().caught_count == 2
    assert aggregate.totals().duration_seconds == pytest.approx(250.0)


def test_session_title_uses_date_duration_and_catch_count():
    stats = FishingSessionStats()
    stats.record_catch("marlin", "Марлин", 3.1, kept=True)
    totals = statistics.SessionTotals(3660, 12, 10.0, 0, 0.0, 0, 0)

    assert format_duration_hhmm(3660) == "01:01"
    assert format_session_title(stats.started_at(), totals).endswith("01:01, 12шт.")


def test_history_skips_empty_sessions_and_persists_non_empty(tmp_path):
    history = FishingSessionHistory(tmp_path / "statistics_sessions.json")
    empty = FishingSessionStats()
    filled = FishingSessionStats()
    filled.record_catch("marlin", "Марлин", 3.1, kept=True)

    assert history.add_from_stats(empty) is None
    record = history.add_from_stats(filled)

    assert record is not None
    loaded = history.load()
    assert len(loaded) == 1
    assert loaded[0].to_stats().totals().caught_count == 1
