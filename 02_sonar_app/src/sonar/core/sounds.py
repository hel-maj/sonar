from __future__ import annotations

import tempfile
import wave
from pathlib import Path

from sonar.paths import RESOURCE_DIR


def play_sound(name: str, *, volume: float = 1.0) -> None:
    path = RESOURCE_DIR / "sounds" / name
    if not path.exists():
        return
    try:
        import winsound

        play_path = _volume_adjusted_wav(path, volume) if volume < 0.999 else path
        winsound.PlaySound(str(play_path or path), winsound.SND_FILENAME | winsound.SND_ASYNC | winsound.SND_NODEFAULT)
    except Exception:
        return


def _volume_adjusted_wav(path: Path, volume: float) -> Path | None:
    volume = max(0.0, min(1.0, volume))
    cache_dir = Path(tempfile.gettempdir()) / "sonar_sound_cache"
    cache_path = cache_dir / f"{path.stem}_volume_{int(volume * 1000):03d}{path.suffix}"
    try:
        if cache_path.exists() and cache_path.stat().st_mtime >= path.stat().st_mtime:
            return cache_path
        cache_dir.mkdir(parents=True, exist_ok=True)
        with wave.open(str(path), "rb") as source:
            params = source.getparams()
            if params.comptype != "NONE":
                return None
            frames = source.readframes(params.nframes)
        adjusted = _scale_pcm_frames(frames, params.sampwidth, volume)
        with wave.open(str(cache_path), "wb") as target:
            target.setparams(params)
            target.writeframes(adjusted)
        return cache_path
    except Exception:
        return None


def _scale_pcm_frames(frames: bytes, sample_width: int, volume: float) -> bytes:
    if sample_width == 1:
        return bytes(max(0, min(255, int(round((sample - 128) * volume + 128)))) for sample in frames)
    if sample_width == 2:
        return _scale_signed_pcm_frames(frames, sample_width, volume, -32768, 32767)
    if sample_width == 3:
        return _scale_24bit_pcm_frames(frames, volume)
    if sample_width == 4:
        return _scale_signed_pcm_frames(frames, sample_width, volume, -2147483648, 2147483647)
    return frames


def _scale_signed_pcm_frames(frames: bytes, sample_width: int, volume: float, minimum: int, maximum: int) -> bytes:
    output = bytearray(len(frames))
    for index in range(0, len(frames), sample_width):
        sample = int.from_bytes(frames[index : index + sample_width], byteorder="little", signed=True)
        scaled = max(minimum, min(maximum, int(round(sample * volume))))
        output[index : index + sample_width] = scaled.to_bytes(sample_width, byteorder="little", signed=True)
    return bytes(output)


def _scale_24bit_pcm_frames(frames: bytes, volume: float) -> bytes:
    output = bytearray(len(frames))
    for index in range(0, len(frames), 3):
        sample = int.from_bytes(frames[index : index + 3], byteorder="little", signed=True)
        scaled = max(-8388608, min(8388607, int(round(sample * volume))))
        output[index : index + 3] = scaled.to_bytes(3, byteorder="little", signed=True)
    return bytes(output)
