from __future__ import annotations

import platform
import socket
import os
import re
from dataclasses import dataclass, field
from datetime import datetime, timezone
from typing import Any

import requests

from sonar.build_metadata import APP_BUILD_HASH, APP_NAME


JSON_API_HEADERS = {
    "Accept": "application/vnd.api+json",
    "Content-Type": "application/vnd.api+json",
}

ACTIVATION_CODES = {
    "FINGERPRINT_SCOPE_MISMATCH",
    "FINGERPRINT_SCOPE_REQUIRED",
    "MACHINE_SCOPE_REQUIRED",
    "NO_MACHINE",
    "NO_MACHINES",
}

PUBLIC_IP_SERVICES = (
    "https://api.ipify.org",
    "https://ifconfig.me/ip",
    "https://ident.me",
    "https://icanhazip.com",
    "https://ipinfo.io/ip",
)
PUBLIC_IP_TIMEOUT = 1.5


@dataclass(slots=True)
class LicenseStatus:
    valid: bool = False
    license_key: str = ""
    license_id: str = ""
    masked_key: str = ""
    expires_at: datetime | None = None
    latest_version: str = ""
    update_message: str = ""
    role: str = "user"
    error: str = ""
    code: str = ""
    raw: dict[str, Any] = field(default_factory=dict)

    @property
    def expired(self) -> bool:
        return self.expires_at is not None and self.expires_at <= datetime.now(timezone.utc)


class KeygenLicenseClient:
    def __init__(
        self,
        server_url: str,
        account_id: str = "",
        *,
        build_hash: str = APP_BUILD_HASH,
        app_name: str = APP_NAME,
        timeout: float = 8.0,
        session: requests.Session | None = None,
    ) -> None:
        self.server_url = server_url.rstrip("/")
        self.account_id = account_id.strip()
        self.build_hash = build_hash.strip() or "dev"
        self.app_name = app_name.strip() or "Sonar"
        self.timeout = timeout
        self.session = session or requests.Session()

    def validate_and_activate(self, license_key: str, fingerprint: str) -> LicenseStatus:
        key = license_key.strip()
        if not key:
            return LicenseStatus(valid=False, error="Введите ключ лицензии")
        first = self.validate_key(key, fingerprint)
        if first.valid:
            self.update_machine_details(key, fingerprint)
            return first
        if first.license_id and first.code in ACTIVATION_CODES:
            activated = self.activate_machine(key, first.license_id, fingerprint)
            if not activated.valid and activated.error:
                return activated
            return self.validate_key(key, fingerprint)
        return first

    def validate_key(self, license_key: str, fingerprint: str) -> LicenseStatus:
        payload = {
            "meta": {
                "key": license_key.strip(),
                "scope": {"fingerprint": fingerprint},
            }
        }
        try:
            response = self.session.post(
                self._url("/licenses/actions/validate-key"),
                headers=self._headers(),
                json=payload,
                timeout=self.timeout,
            )
        except requests.RequestException as exc:
            return LicenseStatus(valid=False, license_key=license_key, masked_key=mask_license_key(license_key), error=str(exc))
        return self._status_from_response(response, license_key)

    def activate_machine(self, license_key: str, license_id: str, fingerprint: str) -> LicenseStatus:
        payload = {
            "data": {
                "type": "machines",
                "attributes": self._machine_attributes(fingerprint, include_metadata=True),
                "relationships": {
                    "license": {
                        "data": {
                            "type": "licenses",
                            "id": license_id,
                        }
                    }
                },
            }
        }
        headers = self._headers({"Authorization": f"License {license_key.strip()}"})
        try:
            response = self.session.post(
                self._url("/machines"),
                headers=headers,
                json=payload,
                timeout=self.timeout,
            )
        except requests.RequestException as exc:
            return LicenseStatus(valid=False, license_key=license_key, masked_key=mask_license_key(license_key), error=str(exc))
        if response.ok:
            return LicenseStatus(valid=True, license_key=license_key, masked_key=mask_license_key(license_key))
        return self._status_from_response(response, license_key)

    def update_machine_details(self, license_key: str, fingerprint: str) -> None:
        payload = {
            "data": {
                "type": "machines",
                "attributes": self._machine_attributes(fingerprint, include_metadata=False),
            }
        }
        headers = self._headers({"Authorization": f"License {license_key.strip()}"})
        try:
            self.session.patch(
                self._url(f"/machines/{fingerprint}"),
                headers=headers,
                json=payload,
                timeout=self.timeout,
            )
        except (AttributeError, requests.RequestException):
            return

    def _url(self, path: str) -> str:
        prefix = f"/v1/accounts/{self.account_id}" if self.account_id else "/v1"
        return f"{self.server_url}{prefix}{path}"

    def _machine_attributes(self, fingerprint: str, *, include_metadata: bool) -> dict[str, Any]:
        hostname = socket.gethostname() or platform.node() or "Windows PC"
        local_ip = _detect_local_ip()
        public_ip = _detect_public_ip()
        attributes: dict[str, Any] = {
            "fingerprint": fingerprint,
            "name": hostname,
            "hostname": hostname,
            "platform": platform.platform(),
        }
        if public_ip or local_ip:
            attributes["ip"] = public_ip or local_ip
        if include_metadata:
            attributes["metadata"] = {
                "build_hash": self.build_hash,
                "app_name": self.app_name,
                "windows_user": _windows_username(),
                "local_ip": local_ip,
                "public_ip": public_ip,
            }
        return attributes

    def _headers(self, extra: dict[str, str] | None = None) -> dict[str, str]:
        headers = {
            **JSON_API_HEADERS,
            "User-Agent": f"{self.app_name}/1.0 SonarBuild/{self.build_hash}",
            "X-Sonar-Build-Hash": self.build_hash,
        }
        if extra:
            headers.update(extra)
        return headers

    def _status_from_response(self, response: requests.Response, license_key: str) -> LicenseStatus:
        try:
            body = response.json()
        except ValueError:
            return LicenseStatus(
                valid=False,
                license_key=license_key,
                masked_key=mask_license_key(license_key),
                error=f"Сервер лицензий вернул HTTP {response.status_code}",
            )
        return parse_keygen_status(body, license_key, http_status=response.status_code)


def parse_keygen_status(body: dict[str, Any], license_key: str = "", *, http_status: int = 200) -> LicenseStatus:
    meta = body.get("meta") if isinstance(body.get("meta"), dict) else {}
    data = body.get("data") if isinstance(body.get("data"), dict) else {}
    attributes = data.get("attributes") if isinstance(data.get("attributes"), dict) else {}
    errors = body.get("errors") if isinstance(body.get("errors"), list) else []
    error = _error_detail(errors) or str(meta.get("detail") or "")
    code = str(meta.get("code") or (errors[0].get("code") if errors and isinstance(errors[0], dict) else "") or "")
    license_id = str(data.get("id") or "")
    key = license_key or str(attributes.get("key") or "")
    valid = bool(meta.get("valid")) and not _is_expired(attributes)
    if not valid and not error and http_status >= 400:
        error = f"Сервер лицензий вернул HTTP {http_status}"
    expires_at = parse_keygen_datetime(attributes.get("expiry") or attributes.get("expires") or attributes.get("expiresAt"))
    latest_version, update_message = _version_fields(attributes)
    role = _license_role(attributes)
    return LicenseStatus(
        valid=valid,
        license_key=key,
        license_id=license_id,
        masked_key=mask_license_key(key),
        expires_at=expires_at,
        latest_version=latest_version,
        update_message=update_message,
        role=role,
        error=error,
        code=code,
        raw=body,
    )


def parse_keygen_datetime(value: Any) -> datetime | None:
    if not value:
        return None
    try:
        text = str(value).replace("Z", "+00:00")
        parsed = datetime.fromisoformat(text)
        if parsed.tzinfo is None:
            parsed = parsed.replace(tzinfo=timezone.utc)
        return parsed.astimezone(timezone.utc)
    except ValueError:
        return None


def mask_license_key(key: str) -> str:
    text = key.strip()
    if not text:
        return ""
    parts = text.split("-")
    if len(parts) >= 3:
        return f"{parts[0]}-*****-{parts[-1]}"
    if len(text) <= 10:
        return "*" * len(text)
    return f"{text[:5]}*****{text[-5:]}"


def _version_fields(attributes: dict[str, Any]) -> tuple[str, str]:
    metadata = attributes.get("metadata") if isinstance(attributes.get("metadata"), dict) else {}
    latest_version = str(
        metadata.get("latest_version")
        or metadata.get("latestVersion")
        or metadata.get("app_version")
        or metadata.get("appVersion")
        or attributes.get("version")
        or ""
    ).strip()
    update_message = str(
        metadata.get("update_message")
        or metadata.get("updateMessage")
        or metadata.get("release_notes")
        or metadata.get("releaseNotes")
        or metadata.get("description")
        or attributes.get("description")
        or ""
    )
    return latest_version, update_message


def _license_role(attributes: dict[str, Any]) -> str:
    metadata = attributes.get("metadata") if isinstance(attributes.get("metadata"), dict) else {}
    raw_role = (
        metadata.get("role")
        or metadata.get("sonar_role")
        or metadata.get("sonarRole")
        or metadata.get("user_role")
        or metadata.get("userRole")
        or attributes.get("role")
        or "user"
    )
    if metadata.get("admin") is True or metadata.get("is_admin") is True or metadata.get("isAdmin") is True:
        raw_role = "admin"
    role = str(raw_role or "user").strip().lower()
    return role or "user"


def _error_detail(errors: list[Any]) -> str:
    for item in errors:
        if not isinstance(item, dict):
            continue
        detail = item.get("detail") or item.get("title")
        if detail:
            return str(detail)
    return ""


def _is_expired(attributes: dict[str, Any]) -> bool:
    if str(attributes.get("status") or "").upper() == "EXPIRED":
        return True
    expiry = parse_keygen_datetime(attributes.get("expiry") or attributes.get("expires") or attributes.get("expiresAt"))
    return bool(expiry and expiry <= datetime.now(timezone.utc))


def _detect_local_ip() -> str:
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
            sock.connect(("8.8.8.8", 80))
            return str(sock.getsockname()[0])
    except OSError:
        try:
            return str(socket.gethostbyname(socket.gethostname()))
        except OSError:
            return ""


def _detect_public_ip() -> str:
    headers = {"User-Agent": f"{APP_NAME}/1.0"}
    for url in PUBLIC_IP_SERVICES:
        try:
            response = requests.get(url, headers=headers, timeout=PUBLIC_IP_TIMEOUT)
            if not response.ok:
                continue
            ip = _extract_ip_address(response.text)
            if ip:
                return ip
        except requests.RequestException:
            continue
    return ""


def _extract_ip_address(text: str) -> str:
    match = re.search(r"\b(?:\d{1,3}\.){3}\d{1,3}\b|[0-9a-fA-F:]{3,}", text)
    if not match:
        return ""
    candidate = match.group(0).strip()
    try:
        socket.inet_pton(socket.AF_INET, candidate)
        return candidate
    except OSError:
        try:
            socket.inet_pton(socket.AF_INET6, candidate)
            return candidate
        except OSError:
            return ""


def _windows_username() -> str:
    domain = os.environ.get("USERDOMAIN", "").strip()
    user = os.environ.get("USERNAME", "").strip()
    if domain and user:
        return f"{domain}\\{user}"
    return user
