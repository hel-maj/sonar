#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
VENV="$ROOT/.venv"
PYTHON="$VENV/bin/python"
WHEELHOUSE="$ROOT/wheelhouse/linux-py312"

if [ ! -x "$PYTHON" ]; then
  python3.12 -m venv "$VENV"
fi

cd "$ROOT"
"$PYTHON" -m pip install --no-index --find-links="$WHEELHOUSE" -e ".[test]"

echo "Offline venv is ready: $VENV"
