from __future__ import annotations

from pathlib import Path

from sonar.streaming.service import STREAM_PAGE_HTML, StreamingService


def test_chat_zoom_capture_uses_left_top_two_thirds(tmp_path, monkeypatch):
    service = StreamingService(temp_root=tmp_path)
    service._temp_dir = tmp_path / "session"
    service._hls_dir = service._temp_dir / "hls"
    service._hls_dir.mkdir(parents=True)
    service._chat_zoom_enabled = True
    monkeypatch.setattr(service, "_screen_size", lambda: (1920, 1080))

    command = service._build_ffmpeg_command(Path("ffmpeg.exe"))

    assert command[command.index("-offset_x") + 1] == "0"
    assert command[command.index("-offset_y") + 1] == "0"
    assert command[command.index("-video_size") + 1] == "960x720"


def test_chat_zoom_resets_for_every_new_stream(tmp_path):
    service = StreamingService(temp_root=tmp_path)
    service._chat_zoom_enabled = True
    service._chat_mode_enabled = True

    with service._lock:
        service._prepare_new_runtime_locked()

    assert service.snapshot().chat_zoom_enabled is False
    assert service.snapshot().chat_mode_enabled is False


def test_auto_stop_after_viewer_timeout(tmp_path):
    now = 0.0

    def clock() -> float:
        return now

    service = StreamingService(temp_root=tmp_path, clock=clock, viewer_timeout_seconds=180.0)
    with service._lock:
        service._active = True
        service._started_at = 0.0
        service._last_viewer_activity_at = 0.0

    now = 179.0
    with service._lock:
        assert service._should_auto_stop_locked() is False

    now = 180.0
    with service._lock:
        assert service._should_auto_stop_locked() is True

    service.mark_viewer_activity()
    now = 359.0
    with service._lock:
        assert service._should_auto_stop_locked() is False


def test_stream_page_uses_react_ui_kit_and_video_player():
    assert "react.production.min.js" in STREAM_PAGE_HTML
    assert "MaterialUI" in STREAM_PAGE_HTML
    assert "video-js" in STREAM_PAGE_HTML
