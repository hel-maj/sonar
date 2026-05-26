#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
VENV="$ROOT/.venv"
PYTHON="$VENV/bin/python"

export QT_QPA_PLATFORM="${QT_QPA_PLATFORM:-offscreen}"
export OMP_THREAD_LIMIT="${OMP_THREAD_LIMIT:-1}"
export OPENBLAS_NUM_THREADS="${OPENBLAS_NUM_THREADS:-1}"
export OPENCV_FOR_THREADS_NUM="${OPENCV_FOR_THREADS_NUM:-1}"

if [ ! -x "$PYTHON" ]; then
  python3.12 -m venv "$VENV"
fi

cd "$ROOT"
"$PYTHON" -m pip install -e ".[test]"
"$PYTHON" scripts/run_tests.py "$@"
