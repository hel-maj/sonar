from __future__ import annotations

import logging
from logging.handlers import RotatingFileHandler
from pathlib import Path
from typing import Callable

from sonar.core.log_crypto import encrypt_log_payload
from sonar.paths import IS_FROZEN, LOG_DIR


LogCallback = Callable[[str], None]
DEBUG_LOG_MAX_BYTES = 20 * 1024 * 1024
DEBUG_LOG_BACKUP_COUNT = 2


class EncryptedRotatingFileHandler(logging.Handler):
    def __init__(self, path: Path, *, max_bytes: int, backup_count: int, encoding: str = "utf-8") -> None:
        super().__init__()
        self.path = path
        self.max_bytes = max_bytes
        self.backup_count = backup_count
        self.encoding = encoding
        self.path.parent.mkdir(parents=True, exist_ok=True)

    def emit(self, record: logging.LogRecord) -> None:
        try:
            payload = self.format(record).encode(self.encoding, errors="replace")
            encrypted_line = encrypt_log_payload(payload) + b"\n"
            self._rotate_if_needed(len(encrypted_line))
            with self.path.open("ab") as file:
                file.write(encrypted_line)
        except Exception:
            self.handleError(record)

    def _rotate_if_needed(self, next_size: int) -> None:
        if self.max_bytes <= 0:
            return
        try:
            current_size = self.path.stat().st_size if self.path.exists() else 0
        except OSError:
            current_size = 0
        if current_size + next_size <= self.max_bytes:
            return
        for index in range(self.backup_count, 0, -1):
            source = self.path.with_name(f"{self.path.name}.{index}")
            target = self.path.with_name(f"{self.path.name}.{index + 1}")
            if index == self.backup_count:
                try:
                    source.unlink()
                except FileNotFoundError:
                    pass
                continue
            if source.exists():
                source.replace(target)
        if self.path.exists() and self.backup_count > 0:
            self.path.replace(self.path.with_name(f"{self.path.name}.1"))
        elif self.path.exists():
            self.path.unlink()


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
    logs_dir = LOG_DIR
    logs_dir.mkdir(parents=True, exist_ok=True)
    if IS_FROZEN:
        handler = EncryptedRotatingFileHandler(
            logs_dir / "log.log.enc",
            max_bytes=DEBUG_LOG_MAX_BYTES,
            backup_count=DEBUG_LOG_BACKUP_COUNT,
        )
    else:
        handler = RotatingFileHandler(
            logs_dir / "log.log",
            mode="w",
            maxBytes=DEBUG_LOG_MAX_BYTES,
            backupCount=DEBUG_LOG_BACKUP_COUNT,
            encoding="utf-8",
    )
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
