from __future__ import annotations

import hashlib


Q = 2**255 - 19
L = 2**252 + 27742317777372353535851937790883648493
D = -121665 * pow(121666, Q - 2, Q) % Q
I = pow(2, (Q - 1) // 4, Q)


def ed25519_public_key_from_seed(seed: bytes) -> bytes:
    if len(seed) != 32:
        raise ValueError("Ed25519 seed must be 32 bytes")
    digest = hashlib.sha512(seed).digest()
    secret = _clamp_scalar(digest[:32])
    return _encode_point(_scalar_mult(_base_point(), secret))


def ed25519_sign(seed: bytes, message: bytes) -> bytes:
    if len(seed) != 32:
        raise ValueError("Ed25519 seed must be 32 bytes")
    digest = hashlib.sha512(seed).digest()
    secret = _clamp_scalar(digest[:32])
    prefix = digest[32:]
    public_key = _encode_point(_scalar_mult(_base_point(), secret))
    nonce = _sha512_mod_l(prefix + message)
    encoded_r = _encode_point(_scalar_mult(_base_point(), nonce))
    h = _sha512_mod_l(encoded_r + public_key + message)
    s = (nonce + h * secret) % L
    return encoded_r + s.to_bytes(32, "little")


def ed25519_verify(public_key: bytes, message: bytes, signature: bytes) -> bool:
    if len(public_key) != 32 or len(signature) != 64:
        return False
    try:
        a = _decode_point(public_key)
        r = _decode_point(signature[:32])
    except ValueError:
        return False
    s = int.from_bytes(signature[32:], "little")
    if s >= L:
        return False
    h = _sha512_mod_l(signature[:32] + public_key + message)
    return _scalar_mult(_base_point(), s) == _edwards_add(r, _scalar_mult(a, h))


def _sha512_mod_l(data: bytes) -> int:
    return int.from_bytes(hashlib.sha512(data).digest(), "little") % L


def _clamp_scalar(value: bytes) -> int:
    scalar = bytearray(value)
    scalar[0] &= 248
    scalar[31] &= 63
    scalar[31] |= 64
    return int.from_bytes(scalar, "little")


def _base_point() -> tuple[int, int]:
    y = 4 * pow(5, Q - 2, Q) % Q
    return (_recover_x(y), y)


def _recover_x(y: int) -> int:
    xx = (y * y - 1) * pow(D * y * y + 1, Q - 2, Q)
    x = pow(xx, (Q + 3) // 8, Q)
    if (x * x - xx) % Q != 0:
        x = (x * I) % Q
    if (x * x - xx) % Q != 0:
        raise ValueError("Invalid Ed25519 point")
    if x & 1:
        x = Q - x
    return x


def _edwards_add(left: tuple[int, int], right: tuple[int, int]) -> tuple[int, int]:
    x1, y1 = left
    x2, y2 = right
    denominator_x = pow(1 + D * x1 * x2 * y1 * y2, Q - 2, Q)
    denominator_y = pow(1 - D * x1 * x2 * y1 * y2, Q - 2, Q)
    x3 = (x1 * y2 + x2 * y1) * denominator_x % Q
    y3 = (y1 * y2 + x1 * x2) * denominator_y % Q
    return x3, y3


def _scalar_mult(point: tuple[int, int], scalar: int) -> tuple[int, int]:
    result = (0, 1)
    addend = point
    while scalar > 0:
        if scalar & 1:
            result = _edwards_add(result, addend)
        addend = _edwards_add(addend, addend)
        scalar >>= 1
    return result


def _encode_point(point: tuple[int, int]) -> bytes:
    x, y = point
    encoded = bytearray(y.to_bytes(32, "little"))
    encoded[31] |= (x & 1) << 7
    return bytes(encoded)


def _decode_point(encoded: bytes) -> tuple[int, int]:
    if len(encoded) != 32:
        raise ValueError("Encoded Ed25519 point must be 32 bytes")
    y = int.from_bytes(encoded, "little") & ((1 << 255) - 1)
    if y >= Q:
        raise ValueError("Invalid Ed25519 y coordinate")
    x = _recover_x(y)
    if (x & 1) != (encoded[31] >> 7):
        x = Q - x
    if (-x * x + y * y - 1 - D * x * x * y * y) % Q != 0:
        raise ValueError("Invalid Ed25519 point")
    return x, y
