from __future__ import annotations

import shutil
import urllib.request
import zipfile
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
STREAMING_DIR = ROOT / "src" / "sonar" / "resources" / "streaming"
DOWNLOADS = {
    "cloudflared.exe": "https://github.com/cloudflare/cloudflared/releases/latest/download/cloudflared-windows-amd64.exe",
}
FFMPEG_ZIP_URL = "https://www.gyan.dev/ffmpeg/builds/ffmpeg-release-essentials.zip"


def download(url: str, target: Path) -> None:
    request = urllib.request.Request(url, headers={"User-Agent": "Sonar-build/1.0"})
    with urllib.request.urlopen(request, timeout=180) as response, target.open("wb") as output:
        shutil.copyfileobj(response, output)


def main() -> int:
    STREAMING_DIR.mkdir(parents=True, exist_ok=True)
    ffmpeg_target = STREAMING_DIR / "ffmpeg.exe"
    if ffmpeg_target.exists() and ffmpeg_target.stat().st_size > 0:
        print(f"exists: {ffmpeg_target}")
    else:
        archive_path = STREAMING_DIR / "ffmpeg-release-essentials.zip"
        print(f"download: {FFMPEG_ZIP_URL}")
        download(FFMPEG_ZIP_URL, archive_path)
        with zipfile.ZipFile(archive_path) as archive:
            members = [
                member
                for member in archive.infolist()
                if not member.is_dir() and Path(member.filename).name.lower() == "ffmpeg.exe"
            ]
            if not members:
                raise RuntimeError("ffmpeg.exe not found in downloaded archive")
            preferred = sorted(
                members,
                key=lambda member: (
                    "/bin/" not in member.filename.replace("\\", "/").lower(),
                    len(member.filename),
                ),
            )[0]
            with archive.open(preferred) as source, ffmpeg_target.open("wb") as output:
                shutil.copyfileobj(source, output)
        archive_path.unlink(missing_ok=True)
        print(f"saved: {ffmpeg_target}")
    for filename, url in DOWNLOADS.items():
        target = STREAMING_DIR / filename
        if target.exists() and target.stat().st_size > 0:
            print(f"exists: {target}")
            continue
        print(f"download: {url}")
        download(url, target)
        print(f"saved: {target}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
