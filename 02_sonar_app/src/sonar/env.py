from __future__ import annotations

import os
import re
from functools import lru_cache
from pathlib import Path


APP_ROOT = Path(__file__).resolve().parents[2]
WORKSPACE_ROOT = APP_ROOT.parent


def _dotenv_paths() -> list[Path]:
    explicit = os.environ.get("SONAR_DOTENV_PATH", "").strip()
    if explicit:
        return [Path(explicit)]
    return [WORKSPACE_ROOT / ".env", APP_ROOT / ".env"]


def _parse_dotenv(path: Path) -> dict[str, str]:
    try:
        lines = path.read_text(encoding="utf-8").splitlines()
    except OSError:
        return {}
    values: dict[str, str] = {}
    for line in lines:
        stripped = line.strip()
        if not stripped or stripped.startswith("#"):
            continue
        if stripped.startswith("export "):
            stripped = stripped[7:].lstrip()
        if "=" not in stripped:
            continue
        key, value = stripped.split("=", 1)
        key = key.strip()
        if not re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", key):
            continue
        value = value.strip()
        if len(value) >= 2 and value[0] == value[-1] and value[0] in {"'", '"'}:
            value = value[1:-1]
        else:
            value = value.split(" #", 1)[0].strip()
        values[key] = value
    return values


@lru_cache(maxsize=1)
def load_dotenv() -> dict[str, str]:
    values: dict[str, str] = {}
    for path in _dotenv_paths():
        values.update(_parse_dotenv(path))
    return values


def env_value(name: str) -> str:
    value = os.environ.get(name, "").strip()
    if value:
        return value
    return load_dotenv().get(name, "").strip()

