from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True, slots=True)
class Rect:
    x: int
    y: int
    width: int
    height: int

    @property
    def right(self) -> int:
        return self.x + self.width

    @property
    def bottom(self) -> int:
        return self.y + self.height

    def clamp(self, image_width: int, image_height: int) -> "Rect":
        x = max(0, min(self.x, image_width))
        y = max(0, min(self.y, image_height))
        right = max(x, min(self.right, image_width))
        bottom = max(y, min(self.bottom, image_height))
        return Rect(x, y, right - x, bottom - y)

    def slice(self) -> tuple[slice, slice]:
        return slice(self.y, self.bottom), slice(self.x, self.right)
