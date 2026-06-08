from __future__ import annotations

import base64
import json
from dataclasses import dataclass
from typing import Any

import requests

from sonar.build_metadata import APP_BUILD_HASH, APP_BUILD_KEY, APP_NAME
from sonar.license.http_headers import ascii_header_token
from sonar.license.secrets import decrypt_startup_block_public_key, decrypt_startup_block_url
from sonar.security.ed25519 import ed25519_verify


STARTUP_BLOCK_TIMEOUT_SECONDS = 4.0


@dataclass(frozen=True, slots=True)
class StartupBlockStatus:
    checked: bool = False
    blocked: bool = False
    download_url: str = ""
    error: str = ""


class StartupBlockClient:
    def __init__(
        self,
        *,
        check_url: str | None = None,
        public_key: str | bytes | None = None,
        build_key: str = APP_BUILD_KEY,
        build_hash: str = APP_BUILD_HASH,
        app_name: str = APP_NAME,
        timeout: float = STARTUP_BLOCK_TIMEOUT_SECONDS,
        session: requests.Session | None = None,
    ) -> None:
        self.check_url = (check_url if check_url is not None else decrypt_startup_block_url()).strip()
        self.public_key = public_key if public_key is not None else decrypt_startup_block_public_key()
        self.build_key = build_key.strip()
        self.build_hash = build_hash.strip()
        self.app_name = app_name.strip() or "Sonar"
        self.header_app_name = ascii_header_token(self.app_name)
        self.timeout = timeout
        self.session = session or requests.Session()

    def check(self, *, license_key: str = "") -> StartupBlockStatus:
        if not self.check_url:
            return StartupBlockStatus(error="Startup block check URL is not configured")
        try:
            public_key = decode_ed25519_key(self.public_key)
        except ValueError as exc:
            return StartupBlockStatus(error=str(exc))
        payload = {
            "app_name": self.app_name,
            "build_hash": self.build_hash,
            "build_key": self.build_key,
            "license_key": license_key.strip(),
        }
        try:
            response = self.session.post(
                self.check_url,
                headers={
                    "Accept": "application/json",
                    "Cache-Control": "no-store",
                    "Content-Type": "application/json",
                    "User-Agent": f"{self.header_app_name}/1.0 SonarStartupBlock/{self.build_hash or 'dev'}",
                    "X-Sonar-Build-Hash": self.build_hash,
                    "X-Sonar-Build-Key": self.build_key,
                },
                json=payload,
                timeout=self.timeout,
            )
        except requests.RequestException as exc:
            return StartupBlockStatus(error=str(exc))
        if not response.ok:
            return StartupBlockStatus(error=f"Startup block server returned HTTP {response.status_code}")
        try:
            body = response.json()
        except ValueError:
            return StartupBlockStatus(error="Startup block server returned invalid JSON")
        if not isinstance(body, dict):
            return StartupBlockStatus(error="Startup block response must be a JSON object")
        return parse_signed_startup_block_response(body, public_key)


def parse_signed_startup_block_response(body: dict[str, Any], public_key: bytes) -> StartupBlockStatus:
    signature_text = str(body.get("signature") or "").strip()
    if not signature_text:
        return StartupBlockStatus(error="Startup block response has no signature")
    try:
        signature = decode_base64url(signature_text)
    except ValueError as exc:
        return StartupBlockStatus(error=str(exc))
    payload = startup_block_payload_from_response(body)
    message = canonical_startup_block_payload(payload)
    if not ed25519_verify(public_key, message, signature):
        return StartupBlockStatus(error="Startup block response signature is invalid")
    blocked = bool(payload["blocked"])
    download_url = str(payload["download_url"])
    if blocked and not download_url:
        return StartupBlockStatus(checked=True, error="Blocked startup response has no download URL")
    return StartupBlockStatus(checked=True, blocked=blocked, download_url=download_url)


def startup_block_payload_from_response(body: dict[str, Any]) -> dict[str, object]:
    return {
        "blocked": bool(body.get("blocked")),
        "download_url": str(body.get("download_url") or "").strip(),
    }


def canonical_startup_block_payload(payload: dict[str, object]) -> bytes:
    return json.dumps(payload, ensure_ascii=False, separators=(",", ":"), sort_keys=True).encode("utf-8")


def decode_ed25519_key(value: str | bytes | None) -> bytes:
    if isinstance(value, bytes):
        data = value
    else:
        text = str(value or "").strip()
        if not text:
            raise ValueError("Startup block public key is not configured")
        if len(text) == 64 and all(character in "0123456789abcdefABCDEF" for character in text):
            data = bytes.fromhex(text)
        else:
            data = decode_base64url(text)
    if len(data) != 32:
        raise ValueError("Startup block public key must be 32 bytes")
    return data


def decode_base64url(value: str) -> bytes:
    text = value.strip()
    if not text:
        raise ValueError("Base64url value is empty")
    try:
        padding = "=" * (-len(text) % 4)
        return base64.urlsafe_b64decode(text + padding)
    except (ValueError, TypeError) as exc:
        raise ValueError("Invalid base64url value") from exc


def startup_block_blocks_running_app(status: StartupBlockStatus) -> bool:
    return bool(status.checked and status.blocked and not status.error)


def encode_base64url(value: bytes) -> str:
    return base64.urlsafe_b64encode(value).decode("ascii").rstrip("=")
