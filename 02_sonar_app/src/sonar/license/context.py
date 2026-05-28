from __future__ import annotations

from dataclasses import dataclass
from datetime import datetime, timezone
from typing import Any

from sonar.license.features import LicenseEntitlements, entitlements_from_cached_fields


@dataclass(frozen=True, slots=True)
class LicenseContext:
    active: bool
    entitlements: LicenseEntitlements

    @classmethod
    def from_status(cls, status: Any) -> "LicenseContext":
        expires_at = getattr(status, "expires_at", None)
        expired = bool(expires_at is not None and expires_at <= datetime.now(timezone.utc))
        active = bool(getattr(status, "valid", False) and not expired)
        entitlements = entitlements_from_cached_fields(
            role=str(getattr(status, "role", "user") or "user"),
            group=str(getattr(status, "group", "") or ""),
            features=tuple(getattr(status, "features", ()) or ()),
            denied_features=tuple(getattr(status, "denied_features", ()) or ()),
        )
        return cls(active=active, entitlements=entitlements)

    def can(self, feature_key: str) -> bool:
        return self.active and self.entitlements.allows(feature_key)

    @property
    def role(self) -> str:
        return self.entitlements.role

    @property
    def group(self) -> str:
        return self.entitlements.group
