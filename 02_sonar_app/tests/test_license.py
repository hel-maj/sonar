from __future__ import annotations

from datetime import datetime, timedelta, timezone

from sonar.config.manager import ConfigManager
from sonar.license.client import KeygenLicenseClient, LicenseStatus, _extract_ip_address, mask_license_key, parse_keygen_status
from sonar.license.hwid import machine_fingerprint
from sonar.license.manager import LicenseManager
from sonar.license.secrets import decrypt_license_account_id, decrypt_license_server_url


def test_license_key_mask_matches_ui_format():
    assert mask_license_key("FA5B1-ABCDE-G2K34") == "FA5B1-*****-G2K34"


def test_keygen_status_ignores_license_update_metadata():
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
    assert status.latest_version == ""
    assert status.update_message == ""
    assert status.download_link == ""
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
    assert "stream_chat" in status.features


def test_keygen_status_extracts_group_features_and_overrides():
    status = parse_keygen_status(
        {
            "meta": {"valid": True, "code": "VALID"},
            "data": {
                "id": "license-id",
                "attributes": {
                    "key": "FA5B1-ABCDE-G2K34",
                    "metadata": {
                        "license_group": "basic",
                        "allow_features": ["telegram"],
                        "deny_features": "statistics",
                    },
                },
            },
        }
    )

    assert status.group == "basic"
    assert "fishing" in status.features
    assert "telegram" in status.features
    assert "stream" not in status.features
    assert "statistics" not in status.features
    assert status.denied_features == ("statistics",)


def test_keygen_status_merges_policy_metadata_before_license_overrides():
    status = parse_keygen_status(
        {
            "meta": {"valid": True, "code": "VALID"},
            "data": {
                "id": "license-id",
                "attributes": {
                    "key": "FA5B1-ABCDE-G2K34",
                    "metadata": {
                        "allow_features": ["stream_chat"],
                        "update_message": "Индивидуальный текст",
                    },
                },
                "relationships": {"policy": {"data": {"type": "policies", "id": "policy-id"}}},
            },
            "included": [
                {
                    "type": "policies",
                    "id": "policy-id",
                    "attributes": {
                        "metadata": {
                            "license_group": "streamer",
                            "latest_version": "1.5.0",
                            "update_message": "Групповой текст",
                            "download_link": "https://example.com/group.exe",
                        }
                    },
                }
            ],
        }
    )

    assert status.group == "streamer"
    assert "stream" in status.features
    assert "stream_chat" in status.features
    assert status.latest_version == ""
    assert status.update_message == ""
    assert status.download_link == ""


def test_machine_fingerprint_is_sha256_hex():
    fingerprint = machine_fingerprint()

    assert len(fingerprint) == 64
    assert all(char in "0123456789abcdef" for char in fingerprint)


def test_license_server_url_is_decrypted_at_runtime(monkeypatch, tmp_path):
    monkeypatch.setenv("SONAR_DOTENV_PATH", str(tmp_path / "missing.env"))
    monkeypatch.delenv("SONAR_LICENSE_SERVER_URL", raising=False)
    monkeypatch.delenv("SONAR_LICENSE_ACCOUNT_ID", raising=False)
    import sonar.env as sonar_env

    sonar_env.load_dotenv.cache_clear()

    assert decrypt_license_server_url() == "https://updates.example.invalid"


def test_license_server_url_can_come_from_dotenv(monkeypatch, tmp_path):
    dotenv = tmp_path / ".env"
    dotenv.write_text(
        "\n".join(
            [
                "SONAR_LICENSE_SERVER_URL=https://m-sonar-addr.ru/",
                "SONAR_LICENSE_ACCOUNT_ID=account-from-dotenv",
                "",
            ]
        ),
        encoding="utf-8",
    )
    monkeypatch.setenv("SONAR_DOTENV_PATH", str(dotenv))
    monkeypatch.delenv("SONAR_LICENSE_SERVER_URL", raising=False)
    monkeypatch.delenv("SONAR_LICENSE_ACCOUNT_ID", raising=False)
    import sonar.env as sonar_env

    sonar_env.load_dotenv.cache_clear()

    assert decrypt_license_server_url() == "https://m-sonar-addr.ru"
    assert decrypt_license_account_id() == "account-from-dotenv"


def test_license_server_url_prefers_environment_over_dotenv(monkeypatch, tmp_path):
    dotenv = tmp_path / ".env"
    dotenv.write_text("SONAR_LICENSE_SERVER_URL=https://dotenv.example.test\n", encoding="utf-8")
    monkeypatch.setenv("SONAR_DOTENV_PATH", str(dotenv))
    monkeypatch.setenv("SONAR_LICENSE_SERVER_URL", "https://env.example.test/")
    import sonar.env as sonar_env

    sonar_env.load_dotenv.cache_clear()

    assert decrypt_license_server_url() == "https://env.example.test"


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
    assert "include=policy" in call["url"]
    assert call["headers"]["X-Sonar-Build-Hash"] == "hash-123"
    assert call["headers"]["User-Agent"] == "Build Name/1.0 SonarBuild/hash-123"
    assert set(call["json"]["meta"]) == {"key", "scope"}
    assert call["json"]["meta"]["scope"]["fingerprint"] == "fingerprint"


def test_keygen_validation_uses_global_release_metadata_over_keygen_metadata(monkeypatch):
    class ReleaseSession(FakeSession):
        def post(self, url, *, headers, json, timeout):
            self.calls.append({"url": url, "headers": headers, "json": json, "timeout": timeout})
            return FakeResponse(
                {
                    "meta": {"valid": True},
                    "data": {
                        "id": "license-id",
                        "attributes": {
                            "key": "ABC",
                            "metadata": {
                                "latest_version": "1.0.0",
                                "update_message": "license metadata should not drive updates",
                                "download_link": "https://example.com/license.exe",
                            },
                        },
                    },
                }
            )

        def get(self, url, *, headers, timeout):
            self.calls.append({"method": "GET", "url": url, "headers": headers, "timeout": timeout})
            return FakeResponse(
                {
                    "latest_version": "9.9.9",
                    "update_message": "Глобальный релиз\\n✅ готов",
                    "download_link": "https://example.com/Sonar.exe",
                }
            )

    monkeypatch.delenv("SONAR_RELEASE_METADATA_URL", raising=False)
    session = ReleaseSession()
    client = KeygenLicenseClient("https://m-sonar-addr.ru", "account", build_hash="hash-123", app_name="Build Name", session=session)

    status = client.validate_key("ABC", "fingerprint")

    assert status.latest_version == "9.9.9"
    assert status.update_message == "Глобальный релиз\\n✅ готов"
    assert status.download_link == "https://example.com/Sonar.exe"
    assert session.calls[1]["method"] == "GET"
    assert session.calls[1]["url"] == "https://m-sonar-addr.ru/sonar-release.json"


def test_keygen_release_metadata_url_uses_public_server_root():
    client = KeygenLicenseClient("https://m-sonar-addr.ru/", "account")

    assert client._release_metadata_url() == "https://m-sonar-addr.ru/sonar-release.json"


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


def test_license_manager_persists_feature_entitlements(tmp_path, monkeypatch):
    config = ConfigManager(tmp_path)

    class FeatureClient:
        def __init__(self, *args, **kwargs) -> None:
            pass

        def validate_and_activate(self, license_key: str, fingerprint: str) -> LicenseStatus:
            return LicenseStatus(
                valid=True,
                license_key=license_key,
                license_id="license-id",
                role="user",
                group="basic",
                features=("fishing", "overview"),
                denied_features=("stream",),
            )

    monkeypatch.setattr("sonar.license.manager.KeygenLicenseClient", FeatureClient)

    LicenseManager(config).validate_key("ABC")

    stored = config.load().license
    assert stored.group == "basic"
    assert stored.features == ["fishing", "overview"]
    assert stored.denied_features == ["stream"]
