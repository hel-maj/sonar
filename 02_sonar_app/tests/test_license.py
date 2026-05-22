from __future__ import annotations

from datetime import datetime, timedelta, timezone

from sonar.config.manager import ConfigManager
from sonar.license.client import KeygenLicenseClient, LicenseStatus, _extract_ip_address, mask_license_key, parse_keygen_status
from sonar.license.hwid import machine_fingerprint
from sonar.license.manager import LicenseManager
from sonar.license.secrets import decrypt_license_server_url


def test_license_key_mask_matches_ui_format():
    assert mask_license_key("FA5B1-ABCDE-G2K34") == "FA5B1-*****-G2K34"


def test_keygen_status_extracts_license_and_release_metadata():
    status = parse_keygen_status(
        {
            "meta": {"valid": True, "code": "VALID"},
            "data": {
                "id": "license-id",
                "attributes": {
                    "key": "FA5B1-ABCDE-G2K34",
                    "expiry": "2026-06-25T17:14:00.000Z",
                    "metadata": {
                        "latest_version": "1.2.1",
                        "update_message": "Новая версия\n🐟 быстрее",
                    },
                },
            },
        }
    )

    assert status.valid is True
    assert status.license_id == "license-id"
    assert status.masked_key == "FA5B1-*****-G2K34"
    assert status.latest_version == "1.2.1"
    assert status.update_message == "Новая версия\n🐟 быстрее"
    assert status.role == "user"


def test_keygen_status_extracts_license_role_from_metadata():
    status = parse_keygen_status(
        {
            "meta": {"valid": True, "code": "VALID"},
            "data": {
                "id": "license-id",
                "attributes": {
                    "key": "FA5B1-ABCDE-G2K34",
                    "metadata": {"role": "Admin"},
                },
            },
        }
    )

    assert status.role == "admin"


def test_machine_fingerprint_is_sha256_hex():
    fingerprint = machine_fingerprint()

    assert len(fingerprint) == 64
    assert all(char in "0123456789abcdef" for char in fingerprint)


def test_license_server_url_is_decrypted_at_runtime():
    assert decrypt_license_server_url() == "https://sonar-keygen.31.172.71.133.nip.io"


class FakeResponse:
    ok = True
    status_code = 200

    def __init__(self, body: dict):
        self.body = body

    def json(self):
        return self.body


class FakeSession:
    def __init__(self) -> None:
        self.calls: list[dict] = []

    def post(self, url, *, headers, json, timeout):
        self.calls.append({"url": url, "headers": headers, "json": json, "timeout": timeout})
        return FakeResponse({"meta": {"valid": True}, "data": {"id": "license-id", "attributes": {"key": "ABC"}}})

    def patch(self, url, *, headers, json, timeout):
        self.calls.append({"method": "PATCH", "url": url, "headers": headers, "json": json, "timeout": timeout})
        return FakeResponse({"data": {"id": "machine-id", "attributes": {}}})


def test_keygen_validation_sends_build_hash():
    session = FakeSession()
    client = KeygenLicenseClient("https://keygen.example", "account", build_hash="hash-123", app_name="Build Name", session=session)

    client.validate_key("ABC", "fingerprint")

    call = session.calls[0]
    assert call["headers"]["X-Sonar-Build-Hash"] == "hash-123"
    assert call["headers"]["User-Agent"] == "Build Name/1.0 SonarBuild/hash-123"
    assert set(call["json"]["meta"]) == {"key", "scope"}
    assert call["json"]["meta"]["scope"]["fingerprint"] == "fingerprint"


def test_keygen_machine_activation_sends_build_hash_metadata(monkeypatch):
    import socket

    monkeypatch.setattr("sonar.license.client._detect_public_ip", lambda: "8.8.8.8")
    session = FakeSession()
    client = KeygenLicenseClient("https://keygen.example", "account", build_hash="hash-456", app_name="Build Name", session=session)

    client.activate_machine("ABC", "license-id", "fingerprint")

    call = session.calls[0]
    assert call["headers"]["X-Sonar-Build-Hash"] == "hash-456"
    attributes = call["json"]["data"]["attributes"]
    assert attributes["hostname"] == socket.gethostname()
    assert attributes["name"] == socket.gethostname()
    assert attributes["ip"] == "8.8.8.8"
    assert attributes["metadata"]["build_hash"] == "hash-456"
    assert attributes["metadata"]["app_name"] == "Build Name"
    assert attributes["metadata"]["public_ip"] == "8.8.8.8"


def test_keygen_valid_license_refreshes_machine_columns(monkeypatch):
    monkeypatch.setattr("sonar.license.client._detect_public_ip", lambda: "8.8.4.4")
    session = FakeSession()
    client = KeygenLicenseClient("https://keygen.example", "account", build_hash="hash-789", app_name="Build Name", session=session)

    status = client.validate_and_activate("ABC", "fingerprint")

    assert status.valid is True
    patch_call = session.calls[1]
    assert patch_call["method"] == "PATCH"
    assert patch_call["url"].endswith("/machines/fingerprint")
    attributes = patch_call["json"]["data"]["attributes"]
    assert "hostname" in attributes
    assert attributes["ip"] == "8.8.4.4"
    assert "metadata" not in attributes


def test_extract_ip_address_accepts_ipv4_and_ipv6():
    assert _extract_ip_address("ip=8.8.8.8") == "8.8.8.8"
    assert _extract_ip_address("2001:4860:4860::8888\n") == "2001:4860:4860::8888"
    assert _extract_ip_address("not an ip") == ""


def test_license_manager_clears_cached_expiry_on_server_rejection(tmp_path, monkeypatch):
    config = ConfigManager(tmp_path)
    settings = config.load()
    settings.license.license_key = "ABC"
    settings.license.license_id = "old-id"
    settings.license.expires_at = (datetime.now(timezone.utc) + timedelta(days=1)).isoformat()
    config.save(settings)

    class RejectingClient:
        def __init__(self, *args, **kwargs) -> None:
            pass

        def validate_and_activate(self, license_key: str, fingerprint: str) -> LicenseStatus:
            return LicenseStatus(
                valid=False,
                license_key=license_key,
                license_id="server-id",
                expires_at=datetime.now(timezone.utc) + timedelta(days=1),
                error="revoked",
                raw={"meta": {"valid": False}},
            )

    monkeypatch.setattr("sonar.license.manager.KeygenLicenseClient", RejectingClient)

    status = LicenseManager(config).validate_key("ABC")

    stored = config.load().license
    assert status.valid is False
    assert stored.license_key == "ABC"
    assert stored.license_id == "server-id"
    assert stored.expires_at == ""
