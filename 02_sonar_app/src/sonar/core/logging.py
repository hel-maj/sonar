from __future__ import annotations

import logging
from logging.handlers import RotatingFileHandler
from typing import Callable

from sonar.paths import LOG_DIR, LOGS_ENABLED


LogCallback = Callable[[str], None]


def configure_logging(level: int = logging.INFO) -> None:
    logging.basicConfig(
        level=level,
        format="%(asctime)s %(levelname)s %(name)s: %(message)s",
        datefmt="%H:%M:%S",
    )
    debug_logger = logging.getLogger("sonar.debug")
    debug_logger.setLevel(logging.DEBUG)
    debug_logger.propagate = False
    debug_logger.handlers.clear()
    if not LOGS_ENABLED:
        debug_logger.addHandler(logging.NullHandler())
        return
    logs_dir = LOG_DIR
    logs_dir.mkdir(parents=True, exist_ok=True)
    handler = RotatingFileHandler(logs_dir / "sonar_debug.log", mode="w", maxBytes=8_000_000, backupCount=2, encoding="utf-8")
    handler.setFormatter(logging.Formatter("%(asctime)s.%(msecs)03d %(message)s", datefmt="%H:%M:%S"))
    debug_logger.addHandler(handler)


def debug_log(message: str) -> None:
    logging.getLogger("sonar.debug").debug(message)


class CallbackLogger:
    def __init__(self, callback: LogCallback | None = None) -> None:
        self.callback = callback

    def write(self, message: str) -> None:
        if self.callback:
            self.callback(message)
        logging.getLogger("sonar").info(message)
