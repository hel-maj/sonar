from __future__ import annotations

import argparse
import os
import re
import shlex
import subprocess
from pathlib import Path
from typing import Sequence


ROOT = Path(__file__).resolve().parents[1]


def _dotenv_paths() -> list[Path]:
    explicit = os.environ.get("SONAR_DOTENV_PATH", "").strip()
    if explicit:
        return [Path(explicit)]
    return [ROOT.parent / ".env", ROOT / ".env"]


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


def load_dotenv() -> None:
    values: dict[str, str] = {}
    for path in _dotenv_paths():
        values.update(_parse_dotenv(path))
    for key, value in values.items():
        os.environ.setdefault(key, value)


load_dotenv()

DEFAULT_SOURCE = ROOT / "dist"
DEFAULT_HOST = os.environ.get("SONAR_UPLOAD_HOST", "m-sonar-addr.ru")
DEFAULT_USER = "root"
DEFAULT_REMOTE_DIR = "/var/lib/docker/volumes/sonar-keygen-caddy-data/_data/builds"
ARCHIVE_NAME_RE = re.compile(r"^(?:[0-9a-f]{11}|[0-9a-f]{64})-.+\.exe\.zip$", re.IGNORECASE)


def is_build_archive(path: Path) -> bool:
    return path.is_file() and bool(ARCHIVE_NAME_RE.match(path.name))


def iter_build_archives(source: Path) -> list[Path]:
    source = source.resolve()
    if not source.exists():
        return []
    if source.is_file():
        return [source] if is_build_archive(source) else []
    return sorted(path for path in source.rglob("*.zip") if is_build_archive(path))


def ssh_target(user: str, host: str) -> str:
    user = user.strip()
    host = host.strip()
    return f"{user}@{host}" if user else host


def ssh_command(args: argparse.Namespace, remote_command: str) -> list[str]:
    command = ["ssh", "-p", str(args.port)]
    if args.key:
        command.extend(["-i", str(args.key)])
    if not args.allow_password:
        command.extend(["-o", "BatchMode=yes"])
    command.extend([ssh_target(args.user, args.host), remote_command])
    return command


def scp_command(args: argparse.Namespace, archive: Path) -> list[str]:
    command = ["scp", "-P", str(args.port)]
    if args.key:
        command.extend(["-i", str(args.key)])
    if not args.allow_password:
        command.extend(["-o", "BatchMode=yes"])
    command.extend([str(archive), f"{ssh_target(args.user, args.host)}:{args.remote_dir.rstrip('/')}/"])
    return command


def display_command(command: Sequence[str]) -> str:
    return subprocess.list2cmdline([str(part) for part in command])


def run_command(command: list[str], *, dry_run: bool) -> int:
    print(display_command(command))
    if dry_run:
        return 0
    completed = subprocess.run(command, check=False)
    return completed.returncode


def upload_archives(args: argparse.Namespace) -> int:
    if not args.host.strip():
        print("SSH host is required. Pass --host <ssh-host> or set SONAR_UPLOAD_HOST.")
        return 2
    archives = iter_build_archives(args.source)
    if not archives:
        print(f"No build archives found in {args.source}")
        return 1

    print(f"Found {len(archives)} build archive(s)")
    mkdir = f"mkdir -p -- {shlex.quote(args.remote_dir)}"
    code = run_command(ssh_command(args, mkdir), dry_run=args.dry_run)
    if code != 0:
        return code

    for archive in archives:
        code = run_command(scp_command(args, archive), dry_run=args.dry_run)
        if code != 0:
            return code

    if args.dry_run:
        print(f"Dry run complete: {len(archives)} archive(s) would be uploaded to {ssh_target(args.user, args.host)}:{args.remote_dir}")
    else:
        print(f"Uploaded {len(archives)} archive(s) to {ssh_target(args.user, args.host)}:{args.remote_dir}")
    return 0


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Upload Sonar build zip archives to the server builds folder via SSH key.")
    parser.add_argument("--source", type=Path, default=DEFAULT_SOURCE, help="Build archive file or folder to scan recursively")
    parser.add_argument("--host", default=DEFAULT_HOST, help="SSH host or neutral domain. Defaults to m-sonar-addr.ru and can be overridden with SONAR_UPLOAD_HOST.")
    parser.add_argument("--user", default=DEFAULT_USER, help="SSH user")
    parser.add_argument("--port", type=int, default=22, help="SSH port")
    parser.add_argument("--key", type=Path, default=None, help="Optional private SSH key path")
    parser.add_argument("--remote-dir", default=DEFAULT_REMOTE_DIR, help="Remote builds folder")
    parser.add_argument("--allow-password", action="store_true", help="Allow ssh/scp to prompt for a password")
    parser.add_argument("--dry-run", action="store_true", help="Print commands without uploading")
    return parser.parse_args()


def main() -> int:
    return upload_archives(parse_args())


if __name__ == "__main__":
    raise SystemExit(main())
