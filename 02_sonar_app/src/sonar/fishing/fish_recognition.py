from __future__ import annotations

from dataclasses import dataclass

import numpy as np


@dataclass(slots=True)
class FishRecognition:
    """Compatibility shim for the removed image-template fish recognizer."""

    process_name: str = ""

    def __post_init__(self) -> None:
        pass

    def initialize(self) -> bool:
        return True

    def recognize_fish(self, screenshot: np.ndarray) -> tuple[str | None, float]:
        return None, 0.0

    def recognize_once(self) -> tuple[str | None, float]:
        return None, 0.0

    def run(self) -> tuple[str | None, float]:
        return self.recognize_once()
