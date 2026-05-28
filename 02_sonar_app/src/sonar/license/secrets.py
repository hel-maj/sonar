from __future__ import annotations

from sonar.security.runtime import decrypt_text_literal


def decrypt_license_server_url() -> str:
    return decrypt_text_literal("license_server_url").rstrip("/")


def decrypt_license_account_id() -> str:
    return decrypt_text_literal("license_account_id")
