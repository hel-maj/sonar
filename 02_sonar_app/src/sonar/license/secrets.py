from __future__ import annotations

from sonar.env import env_value
from sonar.security.runtime import decrypt_text_literal


DEFAULT_STARTUP_BLOCK_URL = "https://m-sonar-addr.ru/api/startup-block"
DEFAULT_STARTUP_BLOCK_PUBLIC_KEY = "8fdff2bf7962162273a0e97a1ed1c3375c9fd8d174f531143dc6866f49007874"


def decrypt_license_server_url() -> str:
    return (env_value("SONAR_LICENSE_SERVER_URL") or decrypt_text_literal("license_server_url")).rstrip("/")


def decrypt_license_account_id() -> str:
    return env_value("SONAR_LICENSE_ACCOUNT_ID") or decrypt_text_literal("license_account_id")


def decrypt_startup_block_url() -> str:
    return (env_value("SONAR_STARTUP_BLOCK_URL") or decrypt_text_literal("startup_block_url") or DEFAULT_STARTUP_BLOCK_URL).strip()


def decrypt_startup_block_public_key() -> str:
    return env_value("SONAR_STARTUP_BLOCK_PUBLIC_KEY") or decrypt_text_literal("startup_block_public_key") or DEFAULT_STARTUP_BLOCK_PUBLIC_KEY
