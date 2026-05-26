#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
WHEELHOUSE="$ROOT/wheelhouse/linux-py312"

mkdir -p "$WHEELHOUSE"

python3 -m pip download \
  --only-binary=:all: \
  --dest "$WHEELHOUSE" \
  -r "$ROOT/requirements-test.txt"

python3 -m pip download \
  --only-binary=:all: \
  --dest "$WHEELHOUSE" \
  "$ROOT[test]"

echo "Linux wheelhouse is ready: $WHEELHOUSE"
