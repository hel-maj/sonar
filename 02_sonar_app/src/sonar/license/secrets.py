from __future__ import annotations


_KEY = bytes((83, 111, 110, 97, 114, 76, 105, 99, 101, 110, 115, 101, 86, 49))
_LICENSE_SERVER_URL = bytes(
    (
        59,
        27,
        26,
        17,
        1,
        118,
        70,
        76,
        22,
        1,
        29,
        4,
        36,
        28,
        56,
        10,
        23,
        6,
        23,
        34,
        71,
        80,
        84,
        64,
        66,
        82,
        100,
        31,
        100,
        94,
        64,
        80,
        65,
        127,
        71,
        13,
        12,
        30,
        93,
        12,
        57,
    )
)


def decrypt_license_server_url() -> str:
    return _xor(_LICENSE_SERVER_URL).decode("utf-8").rstrip("/")


def decrypt_license_account_id() -> str:
    return ""


def _xor(payload: bytes) -> bytes:
    return bytes(value ^ _KEY[index % len(_KEY)] for index, value in enumerate(payload))
