from __future__ import annotations

from dataclasses import dataclass
from enum import Enum


class BotPhase(str, Enum):
    IDLE = "idle"
    CASTING = "casting"
    HOOKING = "hooking"
    REELING = "reeling"
    CATCH = "catch"
    INVENTORY = "inventory"
    RECOVERY = "recovery"
    STOPPING = "stopping"


@dataclass(slots=True)
class BotState:
    running: bool = False
    phase: BotPhase = BotPhase.IDLE
    detected_stage: str = "Свободно"
    last_error: str | None = None
