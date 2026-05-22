from __future__ import annotations

from datetime import datetime, timezone

from sonar.config.manager import ConfigManager
from sonar.license.client import KeygenLicenseClient, LicenseStatus, mask_license_key, parse_keygen_datetime
from sonar.license.hwid import machine_fingerprint
from sonar.license.secrets import decrypt_license_account_id, decrypt_license_server_url


class LicenseManager:
    def __init__(self, config_manager: ConfigManager) -> None:
        self.config_manager = config_manager

    def cached_status(self) -> LicenseStatus:
        settings = self.config_manager.load().license
        expires_at = parse_keygen_datetime(settings.expires_at)
        valid = bool(settings.license_key and expires_at and expires_at > datetime.now(timezone.utc))
        return LicenseStatus(
            valid=valid,
            license_key=settings.license_key,
            license_id=settings.license_id,
            masked_key=mask_license_key(settings.license_key),
            expires_at=expires_at,
            role=settings.role or "user",
        )

    def check_saved_license(self) -> LicenseStatus:
        settings = self.config_manager.load().license
        if not settings.license_key:
            return LicenseStatus(valid=False, error="Лицензия не введена")
        return self.validate_key(settings.license_key)

    def validate_key(self, license_key: str) -> LicenseStatus:
        settings = self.config_manager.load()
        client = KeygenLicenseClient(decrypt_license_server_url(), decrypt_license_account_id())
        status = client.validate_and_activate(license_key, machine_fingerprint())
        if status.valid or status.raw:
            settings.license.license_key = status.license_key or license_key.strip()
            settings.license.license_id = status.license_id or settings.license.license_id
            settings.license.last_validated_at = datetime.now(timezone.utc).isoformat()
            settings.license.expires_at = status.expires_at.isoformat() if status.valid and status.expires_at else ""
            settings.license.role = status.role or settings.license.role or "user"
            self.config_manager.save(settings)
        return status
