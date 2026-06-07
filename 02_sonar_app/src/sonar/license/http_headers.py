from __future__ import annotations

import re
import unicodedata


PRINTABLE_ASCII_RE = re.compile(r"[^\x20-\x7E]+")
WHITESPACE_RE = re.compile(r"\s+")


def ascii_header_token(value: str, *, fallback: str = "Sonar") -> str:
    normalized = unicodedata.normalize("NFKD", value.strip())
    ascii_value = normalized.encode("ascii", "ignore").decode("ascii")
    cleaned = PRINTABLE_ASCII_RE.sub("", ascii_value)
    cleaned = WHITESPACE_RE.sub(" ", cleaned).strip()
    return cleaned or fallback
