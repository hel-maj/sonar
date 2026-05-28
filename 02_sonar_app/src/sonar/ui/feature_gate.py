from __future__ import annotations

from typing import Any

from sonar.license.context import LicenseContext


def apply_page_feature_gate(
    *,
    page_features: dict[Any, str],
    nav_buttons: dict[Any, Any],
    license_context: LicenseContext,
) -> list[Any]:
    allowed_pages: list[Any] = []
    for page, feature_key in page_features.items():
        allowed = license_context.can(feature_key)
        if allowed:
            allowed_pages.append(page)
        button = nav_buttons.get(page)
        if button is not None:
            button.setVisible(allowed)
            button.setEnabled(allowed)
    return allowed_pages


def fallback_page(*, preferred: Any, license_page: Any, allowed_pages: list[Any]) -> Any:
    if preferred in allowed_pages:
        return preferred
    if allowed_pages:
        return allowed_pages[0]
    return license_page
