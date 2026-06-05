from __future__ import annotations

from sonar.env import env_value
from sonar.security.runtime import decrypt_text_literal


def decrypt_license_server_url() -> str:
    return (env_value("SONAR_LICENSE_SERVER_URL") or decrypt_text_literal("license_server_url")).rstrip("/")


def decrypt_license_account_id() -> str:
    return env_value("SONAR_LICENSE_ACCOUNT_ID") or decrypt_text_literal("license_account_id")


def decrypt_startup_block_url() -> str:
    return (env_value("SONAR_STARTUP_BLOCK_URL") or decrypt_text_literal("startup_block_url")).strip()


def decrypt_startup_block_public_key() -> str:
    return env_value("SONAR_STARTUP_BLOCK_PUBLIC_KEY") or decrypt_text_literal("startup_block_public_key")
