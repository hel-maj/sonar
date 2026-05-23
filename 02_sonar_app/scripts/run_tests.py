from __future__ import annotations

import os
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FILE_TIMEOUT = 240
TEST_TIMEOUT = 60

ENV_DEFAULTS = {
    "QT_QPA_PLATFORM": "offscreen",
    "OMP_THREAD_LIMIT": "1",
    "OPENBLAS_NUM_THREADS": "1",
    "OPENCV_FOR_THREADS_NUM": "1",
}


def build_env() -> dict[str, str]:
    env = os.environ.copy()
    for key, value in ENV_DEFAULTS.items():
        env.setdefault(key, value)
    src = str(ROOT / "src")
    current = env.get("PYTHONPATH")
    env["PYTHONPATH"] = src if not current else os.pathsep.join((src, current))
    return env


def run_pytest(args: list[str], timeout: int) -> subprocess.CompletedProcess[str] | None:
    command = [sys.executable, "-m", "pytest", *args]
    try:
        return subprocess.run(
            command,
            cwd=ROOT,
            env=build_env(),
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            timeout=timeout,
        )
    except subprocess.TimeoutExpired as error:
        output = error.stdout or ""
        if isinstance(output, bytes):
            output = output.decode(errors="replace")
        print(output, end="", flush=True)
        print(f"\nTIMEOUT after {timeout}s: {' '.join(command)}", flush=True)
        return None


def collect_tests() -> dict[str, list[str]]:
    result = run_pytest(["--collect-only", "-q"], timeout=120)
    if result is None or result.returncode != 0:
        if result is not None:
            print(result.stdout, end="", flush=True)
        raise SystemExit(1)

    tests_by_file: dict[str, list[str]] = defaultdict(list)
    for line in result.stdout.splitlines():
        if "::" not in line:
            continue
        test_file = line.split("::", 1)[0]
        tests_by_file[test_file].append(line)
    return dict(tests_by_file)


def run_file(test_file: str, node_ids: list[str]) -> bool:
    result = run_pytest(["-q", test_file], timeout=FILE_TIMEOUT)
    if result is not None and result.returncode == 0:
        print(f"OK {test_file}", flush=True)
        return True

    if result is not None:
        print(result.stdout, end="", flush=True)
    print(f"FALLBACK {test_file}: running {len(node_ids)} tests separately", flush=True)

    ok = True
    for node_id in node_ids:
        item_result = run_pytest(["-q", node_id], timeout=TEST_TIMEOUT)
        if item_result is not None and item_result.returncode == 0:
            print(f"  OK {node_id}", flush=True)
            continue
        ok = False
        if item_result is not None:
            print(item_result.stdout, end="", flush=True)
        print(f"  FAILED {node_id}", flush=True)
    return ok


def main() -> int:
    if len(sys.argv) > 1:
        result = run_pytest(sys.argv[1:], timeout=FILE_TIMEOUT)
        if result is None:
            return 1
        print(result.stdout, end="", flush=True)
        return result.returncode

    tests_by_file = collect_tests()
    failed_files: list[str] = []
    for test_file, node_ids in tests_by_file.items():
        if not run_file(test_file, node_ids):
            failed_files.append(test_file)

    if failed_files:
        print("\nFAILED FILES:", flush=True)
        for test_file in failed_files:
            print(f"- {test_file}", flush=True)
        return 1

    total = sum(len(node_ids) for node_ids in tests_by_file.values())
    print(f"\nOK {total} tests", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
