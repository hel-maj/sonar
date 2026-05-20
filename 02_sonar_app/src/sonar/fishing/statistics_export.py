from __future__ import annotations

import csv
import re
import secrets
from datetime import datetime
from pathlib import Path

from sonar.fishing.statistics import (
    FishingSessionStats,
    format_base_price,
    format_catch_summary,
    format_duration,
    format_money_range,
    format_weight,
)


def default_stats_csv_path(directory: Path, app_name: str, now: datetime | None = None) -> Path:
    timestamp = (now or datetime.now()).strftime("%Y%m%d_%H%M%S")
    salt = secrets.token_hex(3)
    stem = _safe_filename_stem(app_name)
    return directory / f"stats_{timestamp}_{salt}_{stem}.csv"


def write_stats_csv(path: Path, stats: FishingSessionStats, *, app_name: str, build_hash: str) -> None:
    totals = stats.totals()
    rows = stats.rows()
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8-sig", newline="") as file:
        writer = csv.writer(file, delimiter=";")
        writer.writerow(["Программа", app_name])
        writer.writerow(["Хэш билда", build_hash])
        writer.writerow(["Дата выгрузки", datetime.now().strftime("%Y-%m-%d %H:%M:%S")])
        writer.writerow([])
        writer.writerow(["Общая статистика"])
        writer.writerow(["Время рыбалки", format_duration(totals.duration_seconds)])
        writer.writerow(["Поймано", format_catch_summary(totals.caught_count, totals.caught_kg)])
        writer.writerow(["Отпущено", format_catch_summary(totals.released_count, totals.released_kg)])
        writer.writerow(["Общий вес", format_weight(totals.kept_kg)])
        writer.writerow(["Доход", format_money_range(totals.earned_min, totals.earned_max)])
        writer.writerow(["Доход в час", format_money_range(totals.earned_per_hour_min, totals.earned_per_hour_max)])
        writer.writerow([])
        writer.writerow(["Статистика по рыбе"])
        writer.writerow(["Рыба", "Поймано", "Отпущено", "Цена", "Своя цена за 1000", "Доход"])
        for row in rows:
            writer.writerow(
                [
                    row.stat.name,
                    format_catch_summary(row.stat.caught_count, row.stat.caught_kg),
                    format_catch_summary(row.stat.released_count, row.stat.released_kg),
                    format_base_price(row.base_price),
                    f"{row.custom_price:g}" if row.custom_price is not None else "",
                    format_money_range(row.earned_min, row.earned_max),
                ]
            )


def _safe_filename_stem(value: str) -> str:
    stem = re.sub(r'[<>:"/\\|?*\x00-\x1f]+', "_", value).strip(" .")
    return stem[:80].rstrip(" .") or "Sonar"
