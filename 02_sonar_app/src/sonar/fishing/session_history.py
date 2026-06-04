from __future__ import annotations

import json
import secrets
from dataclasses import dataclass
from datetime import date, datetime
from pathlib import Path
from typing import Any

from sonar.fishing.statistics import FishPrice, FishingSessionStats, format_session_title


@dataclass(frozen=True, slots=True)
class StoredFishingSession:
    session_id: str
    started_at: datetime
    ended_at: datetime
    stats_data: dict[str, Any]

    @property
    def day(self) -> date:
        return self.started_at.date()

    def title(self, *, default_prices: dict[str, FishPrice] | None = None) -> str:
        stats = self.to_stats(default_prices=default_prices)
        return format_session_title(self.started_at, stats.totals())

    def to_stats(
        self,
        *,
        default_prices: dict[str, FishPrice] | None = None,
        custom_prices: dict[str, float] | None = None,
    ) -> FishingSessionStats:
        return FishingSessionStats.from_dict(self.stats_data, default_prices=default_prices, custom_prices=custom_prices)

    def to_dict(self) -> dict[str, Any]:
        return {
            "session_id": self.session_id,
            "started_at": self.started_at.isoformat(timespec="seconds"),
            "ended_at": self.ended_at.isoformat(timespec="seconds"),
            "stats": self.stats_data,
        }

    @classmethod
    def from_dict(cls, data: dict[str, Any]) -> "StoredFishingSession | None":
        stats_data = data.get("stats")
        if not isinstance(stats_data, dict):
            return None
        started_at = _parse_datetime(data.get("started_at"))
        ended_at = _parse_datetime(data.get("ended_at"))
        if started_at is None or ended_at is None:
            return None
        session_id = str(data.get("session_id") or "").strip() or _new_session_id(started_at)
        return cls(session_id=session_id, started_at=started_at, ended_at=ended_at, stats_data=stats_data)

    @classmethod
    def from_stats(cls, stats: FishingSessionStats, *, ended_at: datetime | None = None) -> "StoredFishingSession":
        started_at = stats.started_at()
        return cls(
            session_id=_new_session_id(started_at),
            started_at=started_at,
            ended_at=ended_at or datetime.now(),
            stats_data=stats.to_dict(),
        )


class FishingSessionHistory:
    def __init__(self, path: Path) -> None:
        self.path = path

    def load(self) -> list[StoredFishingSession]:
        if not self.path.exists():
            return []
        try:
            with self.path.open("r", encoding="utf-8") as file:
                raw = json.load(file)
        except (OSError, json.JSONDecodeError):
            return []
        if not isinstance(raw, list):
            return []
        sessions = [item for item in (StoredFishingSession.from_dict(data) for data in raw if isinstance(data, dict)) if item is not None]
        return sorted(sessions, key=lambda item: (item.started_at, item.session_id), reverse=True)

    def save(self, sessions: list[StoredFishingSession]) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)
        ordered = sorted(sessions, key=lambda item: (item.started_at, item.session_id), reverse=True)
        with self.path.open("w", encoding="utf-8") as file:
            json.dump([item.to_dict() for item in ordered], file, ensure_ascii=False, indent=2)

    def add_from_stats(self, stats: FishingSessionStats) -> StoredFishingSession | None:
        if not stats.has_catches():
            return None
        record = StoredFishingSession.from_stats(stats)
        sessions = self.load()
        sessions.insert(0, record)
        self.save(sessions)
        return record


def _new_session_id(started_at: datetime) -> str:
    return f"{started_at.strftime('%Y%m%d%H%M%S')}-{secrets.token_hex(3)}"


def _parse_datetime(value: Any) -> datetime | None:
    if isinstance(value, datetime):
        return value
    text = str(value or "").strip()
    if not text:
        return None
    if text.endswith("Z"):
        text = f"{text[:-1]}+00:00"
    try:
        return datetime.fromisoformat(text)
    except ValueError:
        return None
