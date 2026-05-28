from __future__ import annotations

import argparse
from pathlib import Path


FORBIDDEN_MARKERS = (
    b"sonar-keygen",
    b".nip.io",
    b"https://api.telegram.org",
    b"https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.zip",
    b"https://github.com/cloudflare/cloudflared/releases/latest/download/cloudflared-windows-amd64.exe",
    b"inventory/indicators/v2/health.svg",
    b"inventory-interface full-width full-height router-view",
    b"weight__text-current",
    b"gta5.exe",
    b"majestic-webengine.exe",
)
SERVER_IP_MARKER = b".".join(str(part).encode("ascii") for part in (31, 172, 71, 133))


def iter_files(target: Path) -> list[Path]:
    if target.is_file():
        return [target]
    return [path for path in target.rglob("*") if path.is_file()]


def scan_file(path: Path) -> list[str]:
    try:
        data = path.read_bytes()
    except OSError as exc:
        return [f"{path}: unable to read: {exc}"]
    findings: list[str] = []
    for marker in (*FORBIDDEN_MARKERS, SERVER_IP_MARKER):
        if marker in data:
            findings.append(f"{path}: contains {marker.decode('utf-8', errors='replace')}")
    return findings


def main() -> int:
    parser = argparse.ArgumentParser(description="Scan release artifacts for plaintext runtime secrets.")
    parser.add_argument("--target", required=True, type=Path)
    args = parser.parse_args()
    findings: list[str] = []
    for path in iter_files(args.target):
        findings.extend(scan_file(path))
    if findings:
        for finding in findings:
            print(finding)
        return 1
    print(f"No forbidden plaintext markers found in {args.target}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
