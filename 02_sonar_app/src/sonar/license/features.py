from __future__ import annotations

from dataclasses import dataclass
from typing import Any, Iterable


FEATURE_OVERVIEW = "overview"
FEATURE_OVERVIEW_SESSION_STATS = "overview_session_stats"
FEATURE_FISHING = "fishing"
FEATURE_FISHING_BOT = "fishing_bot"
FEATURE_FISHING_TACKLE = "fishing_tackle"
FEATURE_SETTINGS = "settings"
FEATURE_STATISTICS = "statistics"
FEATURE_STREAM = "stream"
FEATURE_STREAM_CHAT = "stream_chat"
FEATURE_TELEGRAM = "telegram"

INTRO_FEATURES = frozenset({FEATURE_FISHING})

BASIC_FEATURES = frozenset(
    {
        FEATURE_OVERVIEW,
        FEATURE_FISHING,
        FEATURE_FISHING_BOT,
        FEATURE_FISHING_TACKLE,
        FEATURE_TELEGRAM,
    }
)

PREMIUM_FEATURES = frozenset(
    {
        FEATURE_OVERVIEW,
        FEATURE_OVERVIEW_SESSION_STATS,
        FEATURE_FISHING,
        FEATURE_FISHING_BOT,
        FEATURE_FISHING_TACKLE,
        FEATURE_SETTINGS,
        FEATURE_STATISTICS,
        FEATURE_STREAM,
        FEATURE_STREAM_CHAT,
        FEATURE_TELEGRAM,
    }
)

ALL_FEATURES = PREMIUM_FEATURES

STABLE_FEATURES = frozenset(
    {
        FEATURE_OVERVIEW,
        FEATURE_OVERVIEW_SESSION_STATS,
        FEATURE_FISHING,
        FEATURE_FISHING_BOT,
        FEATURE_FISHING_TACKLE,
        FEATURE_SETTINGS,
        FEATURE_STATISTICS,
        FEATURE_STREAM,
        FEATURE_TELEGRAM,
    }
)

SUBSCRIPTION_LEVELS = ("intro", "basic", "premium", "dev", "promo")
PREMIUM_LIKE_GROUPS = frozenset({"premium", "dev", "promo", "legacy", "admin", "owner"})
SUBSCRIPTION_LABELS = {
    "intro": "Intro",
    "basic": "Basic",
    "premium": "Premium",
    "dev": "Dev",
    "promo": "Promo",
    "legacy": "Premium",
    "admin": "Dev",
    "owner": "Dev",
}

GROUP_ALIASES = {
    "starter": "intro",
    "free": "intro",
    "standard": "basic",
    "streamer": "premium",
    "pro": "premium",
    "developer": "dev",
    "development": "dev",
    "promotion": "promo",
}

FEATURE_ALIASES = {
    "bot": FEATURE_FISHING_BOT,
    "fishing_automation": FEATURE_FISHING_BOT,
    "automation": FEATURE_FISHING_BOT,
    "tackle": FEATURE_FISHING_TACKLE,
    "equipment": FEATURE_FISHING_TACKLE,
    "overview_stats": FEATURE_OVERVIEW_SESSION_STATS,
    "overview_statistics": FEATURE_OVERVIEW_SESSION_STATS,
    "session_stats": FEATURE_OVERVIEW_SESSION_STATS,
    "streaming": FEATURE_STREAM,
    "stream_chat_zoom": FEATURE_STREAM_CHAT,
}

GROUP_FEATURES: dict[str, frozenset[str]] = {
    "intro": INTRO_FEATURES,
    "basic": BASIC_FEATURES,
    "streamer": STABLE_FEATURES,
    "premium": PREMIUM_FEATURES,
    "dev": PREMIUM_FEATURES,
    "promo": PREMIUM_FEATURES,
    "legacy": PREMIUM_FEATURES,
    "admin": ALL_FEATURES,
    "owner": ALL_FEATURES,
}

ROLE_FEATURES: dict[str, frozenset[str]] = {
    "admin": ALL_FEATURES,
    "administrator": ALL_FEATURES,
    "owner": ALL_FEATURES,
}

GROUP_KEYS = ("license_group", "sonar_group", "group", "plan", "tier")
ALLOW_KEYS = ("features", "allow_features", "enabled_features", "sonar_features")
DENY_KEYS = ("deny_features", "disabled_features", "blocked_features")


@dataclass(frozen=True, slots=True)
class LicenseEntitlements:
    role: str = "user"
    group: str = "legacy"
    allowed: frozenset[str] = STABLE_FEATURES
    denied: frozenset[str] = frozenset()
    explicit_policy: bool = False

    def allows(self, feature_key: str) -> bool:
        key = normalize_feature_key(feature_key)
        return key in self.allowed and key not in self.denied

    def to_config(self) -> tuple[str, tuple[str, ...], tuple[str, ...]]:
        return self.group, tuple(sorted(self.allowed)), tuple(sorted(self.denied))

    @property
    def subscription_label(self) -> str:
        return subscription_label(self.group)


def entitlements_from_metadata(metadata: dict[str, Any], *, role: str = "user") -> LicenseEntitlements:
    normalized_role = _normalize_name(role) or "user"
    explicit_policy = any(key in metadata for key in (*GROUP_KEYS, *ALLOW_KEYS, *DENY_KEYS))
    group = _metadata_group(metadata)
    if not group:
        group = "admin" if normalized_role in ROLE_FEATURES else "legacy"

    allowed = set(ROLE_FEATURES.get(normalized_role, GROUP_FEATURES.get(group, frozenset())))
    if not allowed:
        allowed = set(GROUP_FEATURES["intro"])
    if not explicit_policy and group == "legacy":
        allowed = set(PREMIUM_FEATURES)

    denied: set[str] = set()
    for key in ALLOW_KEYS:
        value = metadata.get(key)
        if isinstance(value, dict):
            for feature_key, enabled in value.items():
                normalized = normalize_feature_key(str(feature_key))
                if normalized not in ALL_FEATURES:
                    continue
                if _truthy(enabled):
                    allowed.add(normalized)
                    denied.discard(normalized)
                else:
                    denied.add(normalized)
                    allowed.discard(normalized)
        else:
            allowed.update(_feature_keys(value))

    for key in DENY_KEYS:
        denied.update(_feature_keys(metadata.get(key)))

    allowed = {key for key in allowed if key in ALL_FEATURES}
    denied = {key for key in denied if key in ALL_FEATURES}
    return LicenseEntitlements(
        role=normalized_role,
        group=group,
        allowed=frozenset(allowed - denied),
        denied=frozenset(denied),
        explicit_policy=explicit_policy,
    )


def entitlements_from_cached_fields(
    *,
    role: str = "user",
    group: str = "",
    features: Iterable[str] = (),
    denied_features: Iterable[str] = (),
) -> LicenseEntitlements:
    normalized_features = frozenset(key for key in (normalize_feature_key(item) for item in features) if key in ALL_FEATURES)
    normalized_denied = frozenset(key for key in (normalize_feature_key(item) for item in denied_features) if key in ALL_FEATURES)
    normalized_role = _normalize_name(role) or "user"
    normalized_group = normalize_subscription_group(group) or ("admin" if normalized_role in ROLE_FEATURES else "legacy")
    if normalized_features:
        return LicenseEntitlements(
            role=normalized_role,
            group=normalized_group,
            allowed=frozenset(normalized_features - normalized_denied),
            denied=normalized_denied,
            explicit_policy=True,
        )
    metadata = {
        "license_group": normalized_group,
        "deny_features": list(normalized_denied),
    }
    return entitlements_from_metadata(metadata, role=normalized_role)


def normalize_feature_key(value: str) -> str:
    normalized = str(value).strip().lower().replace("-", "_").replace(" ", "_")
    return FEATURE_ALIASES.get(normalized, normalized)


def normalize_subscription_group(value: Any) -> str:
    normalized = _normalize_name(value)
    return GROUP_ALIASES.get(normalized, normalized)


def subscription_label(value: Any) -> str:
    normalized = normalize_subscription_group(value)
    return SUBSCRIPTION_LABELS.get(normalized, str(value or "").strip() or "Unknown")


def subscription_product_name(value: Any) -> str:
    return f"Sonar - {subscription_label(value)}"


def subscription_description(value: Any, *, active: bool = True) -> str:
    if not active:
        return "Активируйте ключ, чтобы открыть доступные функции Sonar."
    normalized = normalize_subscription_group(value)
    if normalized == "intro":
        return "Режим просмотра рыбалки без запуска бота и дополнительных модулей."
    if normalized == "basic":
        return "Рыбалка, Обзор и Telegram уведомления без стрима и расширенной статистики."
    return "Полный доступ к рыбалке, статистике, Telegram и стриму."


def _metadata_group(metadata: dict[str, Any]) -> str:
    for key in GROUP_KEYS:
        value = metadata.get(key)
        if value:
            return normalize_subscription_group(value)
    return ""


def _feature_keys(value: Any) -> set[str]:
    out: set[str] = set()
    for item in _flatten_feature_values(value):
        key = normalize_feature_key(str(item))
        if key in ALL_FEATURES:
            out.add(key)
    return out


def _flatten_feature_values(value: Any) -> Iterable[Any]:
    if value is None:
        return ()
    if isinstance(value, str):
        return (item.strip() for item in value.replace(";", ",").split(",") if item.strip())
    if isinstance(value, dict):
        return (key for key, enabled in value.items() if _truthy(enabled))
    if isinstance(value, Iterable):
        return value
    return (value,)


def _truthy(value: Any) -> bool:
    if isinstance(value, bool):
        return value
    if value is None:
        return False
    if isinstance(value, (int, float)):
        return value != 0
    return str(value).strip().lower() not in {"", "0", "false", "no", "off", "disabled", "deny"}


def _normalize_name(value: Any) -> str:
    return str(value or "").strip().lower().replace("-", "_").replace(" ", "_")
