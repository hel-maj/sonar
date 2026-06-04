from __future__ import annotations

import logging

import sonar.core.logging as log_module
from sonar.core.log_crypto import decrypt_log_payload


def _close_debug_handlers() -> None:
    logger = logging.getLogger("sonar.debug")
    for handler in list(logger.handlers):
        handler.close()
    logger.handlers.clear()


def test_debug_log_uses_log_log_name_and_20mb_limit(tmp_path, monkeypatch):
    _close_debug_handlers()
    monkeypatch.setattr(log_module, "LOG_DIR", tmp_path)
    monkeypatch.setattr(log_module, "IS_FROZEN", False)

    log_module.configure_logging()
    log_module.debug_log("plain dev message")
    _close_debug_handlers()

    path = tmp_path / "log.log"
    assert path.exists()
    assert "plain dev message" in path.read_text(encoding="utf-8")
    assert not (tmp_path / "sonar_debug.log").exists()
    assert log_module.DEBUG_LOG_MAX_BYTES == 20 * 1024 * 1024


def test_frozen_debug_log_is_encrypted_log_log_enc(tmp_path, monkeypatch):
    _close_debug_handlers()
    monkeypatch.setattr(log_module, "LOG_DIR", tmp_path)
    monkeypatch.setattr(log_module, "IS_FROZEN", True)

    log_module.configure_logging()
    log_module.debug_log("encrypted release message")
    _close_debug_handlers()

    path = tmp_path / "log.log.enc"
    assert path.exists()
    payload = path.read_bytes().strip()
    assert b"encrypted release message" not in payload
    assert b"encrypted release message" in decrypt_log_payload(payload)
    assert not (tmp_path / "sonar_debug.log.enc").exists()
