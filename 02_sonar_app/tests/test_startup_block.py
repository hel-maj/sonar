from __future__ import annotations

from sonar.license.startup_block import (
    StartupBlockClient,
    StartupBlockStatus,
    encode_base64url,
    parse_signed_startup_block_response,
    startup_block_blocks_running_app,
)
from sonar.security.ed25519 import ed25519_public_key_from_seed, ed25519_sign, ed25519_verify


RFC8032_SEED = bytes.fromhex("9d61b19deffd5a60ba844af492ec2cc44449c5697b326919703bac031cae7f60")
RFC8032_PUBLIC_KEY = bytes.fromhex("d75a980182b10ab7d54bfed3c964073a0ee172f3daa62325af021a68f707511a")
RFC8032_SIGNATURE = bytes.fromhex(
    "e5564300c360ac729086e2cc806e828a"
    "84877f1eb8e5d974d873e06522490155"
    "5fb8821590a33bacc61e39701cf9b46b"
    "d25bf5f0595bbe24655141438e7a100b"
)


def test_ed25519_verifies_rfc8032_test_vector():
    assert ed25519_public_key_from_seed(RFC8032_SEED) == RFC8032_PUBLIC_KEY
    assert ed25519_verify(RFC8032_PUBLIC_KEY, b"", RFC8032_SIGNATURE) is True
    assert ed25519_verify(RFC8032_PUBLIC_KEY, b"tampered", RFC8032_SIGNATURE) is False


def test_signed_startup_block_response_is_verified():
    seed = bytes(range(32))
    public_key = ed25519_public_key_from_seed(seed)
    payload = {"blocked": True, "download_url": "https://m-sonar-addr.ru/download"}
    message = b'{"blocked":true,"download_url":"https://m-sonar-addr.ru/download"}'
    body = {**payload, "signature": encode_base64url(ed25519_sign(seed, message))}

    status = parse_signed_startup_block_response(body, public_key)

    assert status.checked is True
    assert status.blocked is True
    assert status.download_url == "https://m-sonar-addr.ru/download"


def test_tampered_startup_block_response_is_not_trusted():
    seed = bytes(range(32))
    public_key = ed25519_public_key_from_seed(seed)
    message = b'{"blocked":false,"download_url":""}'
    body = {
        "blocked": True,
        "download_url": "https://m-sonar-addr.ru/download",
        "signature": encode_base64url(ed25519_sign(seed, message)),
    }

    status = parse_signed_startup_block_response(body, public_key)

    assert status.checked is False
    assert status.blocked is False
    assert "signature" in status.error


class FakeResponse:
    ok = True
    status_code = 200

    def __init__(self, body: dict[str, object]) -> None:
        self.body = body

    def json(self) -> dict[str, object]:
        return self.body


class FakeSession:
    def __init__(self, body: dict[str, object]) -> None:
        self.body = body
        self.calls: list[dict[str, object]] = []

    def post(self, url: str, *, headers: dict[str, str], json: dict[str, object], timeout: float) -> FakeResponse:
        self.calls.append({"url": url, "headers": headers, "json": json, "timeout": timeout})
        return FakeResponse(self.body)




def test_startup_block_headers_use_ascii_name_but_payload_keeps_branding():
    seed = bytes(range(32))
    public_key = ed25519_public_key_from_seed(seed)
    message = b'{"blocked":false,"download_url":""}'
    session = FakeSession({"blocked": False, "download_url": "", "signature": encode_base64url(ed25519_sign(seed, message))})
    app_name = "Tom Clancy’s The Division® 2"
    client = StartupBlockClient(
        check_url="https://checks.example/api/startup-block",
        public_key=public_key,
        build_key="build-key",
        build_hash="build-hash",
        app_name=app_name,
        session=session,
    )

    status = client.check(license_key="LICENSE-KEY")

    assert status.checked is True
    call = session.calls[0]
    assert call["json"]["app_name"] == app_name
    assert call["headers"]["User-Agent"].encode("ascii")
    assert "Tom Clancys" in call["headers"]["User-Agent"]


def test_startup_block_client_sends_build_and_license_keys():
    seed = bytes(range(32))
    public_key = ed25519_public_key_from_seed(seed)
    message = b'{"blocked":false,"download_url":""}'
    session = FakeSession({"blocked": False, "download_url": "", "signature": encode_base64url(ed25519_sign(seed, message))})
    client = StartupBlockClient(
        check_url="https://checks.example/api/startup-block",
        public_key=public_key,
        build_key="build-key",
        build_hash="build-hash",
        app_name="Sonar",
        session=session,
    )

    status = client.check(license_key="LICENSE-KEY")

    assert status.checked is True
    assert status.blocked is False
    call = session.calls[0]
    assert call["url"] == "https://checks.example/api/startup-block"
    assert call["json"]["build_key"] == "build-key"
    assert call["json"]["license_key"] == "LICENSE-KEY"
    assert call["headers"]["X-Sonar-Build-Key"] == "build-key"


def test_running_app_blocks_only_on_signed_block_status():
    assert startup_block_blocks_running_app(StartupBlockStatus(checked=False, error="network failed")) is False
    assert startup_block_blocks_running_app(StartupBlockStatus(checked=True, blocked=False)) is False
    assert startup_block_blocks_running_app(StartupBlockStatus(checked=True, blocked=True, download_url="https://example.test")) is True

