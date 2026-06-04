from __future__ import annotations

import base64
import hashlib
import os


LOG_ENCRYPTION_MAGIC = b"SONAR_REELING_LOSS_LOG_V1\n"
DEFAULT_LOG_ENCRYPTION_KEY = "sonar"


def _xor_bytes(data: bytes, key_stream: bytes) -> bytes:
    return bytes(value ^ key_stream[index] for index, value in enumerate(data))


def _log_keystream(key: str, nonce: bytes, length: int) -> bytes:
    key_bytes = key.encode("utf-8")
    stream = bytearray()
    counter = 0
    while len(stream) < length:
        stream.extend(hashlib.sha256(key_bytes + nonce + counter.to_bytes(8, "big")).digest())
        counter += 1
    return bytes(stream[:length])


def encrypt_log_payload(plaintext: bytes, *, key: str = DEFAULT_LOG_ENCRYPTION_KEY) -> bytes:
    nonce = os.urandom(16)
    encrypted = _xor_bytes(plaintext, _log_keystream(key, nonce, len(plaintext)))
    return base64.b64encode(LOG_ENCRYPTION_MAGIC + nonce + encrypted)


def decrypt_log_payload(payload: bytes, *, key: str = DEFAULT_LOG_ENCRYPTION_KEY) -> bytes:
    raw = base64.b64decode(payload)
    if not raw.startswith(LOG_ENCRYPTION_MAGIC):
        raise ValueError("Invalid encrypted log payload")
    body = raw[len(LOG_ENCRYPTION_MAGIC):]
    nonce = body[:16]
    encrypted = body[16:]
    return _xor_bytes(encrypted, _log_keystream(key, nonce, len(encrypted)))
