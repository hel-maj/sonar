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
ARCHIVE_NAME_RE = re.compile(r"^(?:[0-9a-f]{11}|[0-9a-f]{64})-.+(?:\.exe)?\.zip$", re.IGNORECASE)
APP_VERSION_RE = re.compile(r'APP_VERSION\s*=\s*"([0-9]+(?:\.[0-9]+){0,3})"')
VERSION_RE = re.compile(r"^v?([0-9]+(?:\.[0-9]+){0,3})$")


def read_app_version(version_file: Path = ROOT / "src" / "sonar" / "version.py") -> str:
    try:
        text = version_file.read_text(encoding="utf-8")
    except OSError:
        return ""
    match = APP_VERSION_RE.search(text)
    return match.group(1) if match else ""


DEFAULT_VERSION = os.environ.get("SONAR_UPLOAD_VERSION", "").strip() or read_app_version()


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
    return scp_command_to_dir(args, archive, args.remote_dir)


def scp_command_to_dir(args: argparse.Namespace, archive: Path, remote_dir: str) -> list[str]:
    command = ["scp", "-P", str(args.port)]
    if args.key:
        command.extend(["-i", str(args.key)])
    if not args.allow_password:
        command.extend(["-o", "BatchMode=yes"])
    command.extend([str(archive), f"{ssh_target(args.user, args.host)}:{remote_dir.rstrip('/')}/"])
    return command


def display_command(command: Sequence[str]) -> str:
    return subprocess.list2cmdline([str(part) for part in command])


def run_command(command: list[str], *, dry_run: bool) -> int:
    print(display_command(command))
    if dry_run:
        return 0
    completed = subprocess.run(command, check=False)
    return completed.returncode


def normalize_version(value: str) -> str:
    version = value.strip()
    if not version:
        return ""
    match = VERSION_RE.match(version)
    if not match:
        raise ValueError(f"Invalid version {value!r}. Expected numeric version like 1.2.3.")
    return match.group(1)


def remote_version_dir(remote_dir: str, version: str) -> str:
    base = remote_dir.rstrip("/")
    return f"{base}/{version}" if version else base


def source_version_dir(source: Path, version: str) -> Path:
    if not version or not source.is_dir():
        return source
    version_dir = source / version
    return version_dir if version_dir.is_dir() else source


def upload_archives(args: argparse.Namespace) -> int:
    if not args.host.strip():
        print("SSH host is required. Pass --host <ssh-host> or set SONAR_UPLOAD_HOST.")
        return 2
    try:
        version = normalize_version(getattr(args, "version", DEFAULT_VERSION))
    except ValueError as exc:
        print(str(exc))
        return 2
    if getattr(args, "replace_version", False) and not version:
        print("--replace-version requires a version. Pass --version <app-version>.")
        return 2
    source = source_version_dir(args.source, version)
    archives = iter_build_archives(source)
    if not archives:
        print(f"No build archives found in {source}")
        return 1

    target_dir = remote_version_dir(args.remote_dir, version)
    print(f"Found {len(archives)} build archive(s)")
    print(f"Upload source: {source}")
    if version:
        print(f"Upload version: {version}")
    if getattr(args, "replace_version", False):
        setup = f"rm -rf -- {shlex.quote(target_dir)} && mkdir -p -- {shlex.quote(target_dir)}"
    else:
        setup = f"mkdir -p -- {shlex.quote(target_dir)}"
    code = run_command(ssh_command(args, setup), dry_run=args.dry_run)
    if code != 0:
        return code

    for archive in archives:
        code = run_command(scp_command_to_dir(args, archive, target_dir), dry_run=args.dry_run)
        if code != 0:
            return code

    if args.dry_run:
        print(f"Dry run complete: {len(archives)} archive(s) would be uploaded to {ssh_target(args.user, args.host)}:{target_dir}")
    else:
        print(f"Uploaded {len(archives)} archive(s) to {ssh_target(args.user, args.host)}:{target_dir}")
    return 0


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Upload Sonar build zip archives to the server builds folder via SSH key.")
    parser.add_argument("--source", type=Path, default=DEFAULT_SOURCE, help="Build archive file or folder to scan recursively")
    parser.add_argument("--host", default=DEFAULT_HOST, help="SSH host or neutral domain. Defaults to m-sonar-addr.ru and can be overridden with SONAR_UPLOAD_HOST.")
    parser.add_argument("--user", default=DEFAULT_USER, help="SSH user")
    parser.add_argument("--port", type=int, default=22, help="SSH port")
    parser.add_argument("--key", type=Path, default=None, help="Optional private SSH key path")
    parser.add_argument("--remote-dir", default=DEFAULT_REMOTE_DIR, help="Remote builds folder")
    parser.add_argument("--version", default=DEFAULT_VERSION, help="Release version folder under the remote builds folder. Defaults to APP_VERSION or SONAR_UPLOAD_VERSION.")
    parser.add_argument("--replace-version", action="store_true", help="Delete and recreate the remote folder for this version before uploading.")
    parser.add_argument("--allow-password", action="store_true", help="Allow ssh/scp to prompt for a password")
    parser.add_argument("--dry-run", action="store_true", help="Print commands without uploading")
    return parser.parse_args()


def main() -> int:
    return upload_archives(parse_args())


if __name__ == "__main__":
    raise SystemExit(main())
