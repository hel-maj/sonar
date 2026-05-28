from __future__ import annotations

import base64
import hashlib
import json
from functools import lru_cache
from typing import Any

from sonar.build_metadata import APP_BUILD_KEY
from sonar.security.literals import ENCRYPTED_LITERALS


SALT_BYTES = 16
DEV_BUILD_KEY = "sonar-dev-build-key-v1"


def build_key() -> str:
    return str(APP_BUILD_KEY or DEV_BUILD_KEY)


@lru_cache(maxsize=None)
def decrypt_text_literal(name: str) -> str:
    token = ENCRYPTED_LITERALS[name]
    return _decrypt_token(token, build_key()).decode("utf-8")


@lru_cache(maxsize=None)
def decrypt_json_literal(name: str) -> Any:
    return json.loads(decrypt_text_literal(name))


def _decrypt_token(token: str, key: str) -> bytes:
    padding = "=" * (-len(token) % 4)
    raw = base64.urlsafe_b64decode(token + padding)
    if len(raw) < SALT_BYTES:
        raise ValueError("Encrypted literal is too short")
    salt = raw[:SALT_BYTES]
    payload = raw[SALT_BYTES:]
    stream = _key_stream(key, salt, len(payload))
    return bytes(value ^ stream[index] for index, value in enumerate(payload))


def _key_stream(key: str, salt: bytes, size: int) -> bytes:
    key_bytes = _derive_key(key)
    out = bytearray()
    counter = 0
    while len(out) < size:
        block_counter = counter.to_bytes(4, "big")
        out.extend(
            hashlib.sha256(
                b"SonarRuntimeStream:v1\0" + key_bytes + salt + block_counter
            ).digest()
        )
        counter += 1
    return bytes(out[:size])


def _derive_key(key: str) -> bytes:
    return hashlib.sha256(b"SonarRuntimeKey:v1\0" + key.encode("utf-8")).digest()
