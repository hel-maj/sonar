#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
WHEELHOUSE="$ROOT/wheelhouse/linux-py312"
REQUIREMENTS="$ROOT/requirements-offline-py312.txt"

mkdir -p "$WHEELHOUSE"

python3.12 -m pip download \
  --only-binary=:all: \
  --dest "$WHEELHOUSE" \
  -r "$REQUIREMENTS"

echo "Linux wheelhouse is ready: $WHEELHOUSE"
