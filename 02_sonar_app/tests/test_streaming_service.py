from __future__ import annotations

import shutil
import threading
import time
import zipfile
from pathlib import Path

import sonar.streaming.service as stream_service
from sonar.streaming.chat import ChatActionResult, ChatDetection, ChatTab
from sonar.streaming.service import STREAM_PAGE_HTML, StreamingService
from sonar.vision.geometry import Rect


def test_chat_zoom_capture_uses_left_top_two_thirds(tmp_path, monkeypatch):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
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
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._chat_zoom_enabled = True
    service._chat_mode_enabled = True

    with service._lock:
        service._prepare_new_runtime_locked()

    assert service.snapshot().chat_zoom_enabled is False
    assert service.snapshot().chat_mode_enabled is False


def test_chat_mode_can_be_disabled_through_exit_callback(tmp_path):
    calls: list[str] = []
    service = StreamingService(
        temp_root=tmp_path,
        prewarm_binaries=False,
        chat_mode_callback=lambda: calls.append("open"),
        chat_exit_callback=lambda: calls.append("close"),
    )

    assert service.enable_chat_mode().chat_mode_enabled is True
    assert service.disable_chat_mode().chat_mode_enabled is False
    assert calls == ["open", "close"]


def test_chat_mode_stays_enabled_when_exit_callback_fails(tmp_path):
    service = StreamingService(
        temp_root=tmp_path,
        prewarm_binaries=False,
        chat_exit_callback=lambda: ChatActionResult(False, "close failed"),
    )
    service._chat_mode_enabled = True

    snapshot = service.disable_chat_mode()

    assert snapshot.chat_mode_enabled is True
    assert snapshot.error == "close failed"


def test_snapshot_hides_chat_tabs_until_input_is_active(tmp_path):
    tabs = (ChatTab("0", "Все", True, Rect(1, 2, 3, 4)),)
    service = StreamingService(
        temp_root=tmp_path,
        prewarm_binaries=False,
        chat_status_callback=lambda: ChatDetection(active=False, tabs=tabs, selected_tab_id="0"),
    )

    snapshot = service.snapshot()

    assert snapshot.chat_active is False
    assert snapshot.chat_tabs == ()
    assert snapshot.chat_selected_tab_id is None


def test_select_chat_tab_calls_game_callback(tmp_path):
    selected: list[str | None] = []
    service = StreamingService(
        temp_root=tmp_path,
        prewarm_binaries=False,
        chat_select_callback=lambda tab_id: selected.append(tab_id) or ChatActionResult(True, "selected"),
    )

    snapshot = service.select_chat_tab("1")

    assert snapshot.chat_mode_enabled is True
    assert selected == ["1"]


def test_default_viewer_timeout_is_five_minutes(tmp_path):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)

    assert service.viewer_timeout_seconds == 300.0


def test_auto_stop_after_viewer_timeout(tmp_path):
    now = 0.0

    def clock() -> float:
        return now

    service = StreamingService(temp_root=tmp_path, clock=clock, viewer_timeout_seconds=180.0, prewarm_binaries=False)
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
    assert "liveRangeSafeTimeDelta" in STREAM_PAGE_HTML
    assert "sourceKeyRef" in STREAM_PAGE_HTML
    assert "/hls/live.m3u8?stream=" in STREAM_PAGE_HTML
    assert "player.load()" in STREAM_PAGE_HTML
    assert "/api/stream/chat-send" in STREAM_PAGE_HTML
    assert "/api/stream/chat-select" in STREAM_PAGE_HTML
    assert "Вкладка чата" in STREAM_PAGE_HTML
    assert "Выйти из режима чата" in STREAM_PAGE_HTML


def test_ffmpeg_hls_window_keeps_enough_segments(tmp_path):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._temp_dir = tmp_path / "session"
    service._hls_dir = service._temp_dir / "hls"
    service._hls_dir.mkdir(parents=True)

    command = service._build_ffmpeg_command(Path("ffmpeg.exe"))

    assert command[command.index("-hls_time") + 1] == "2"
    assert command[command.index("-hls_list_size") + 1] == "12"
    assert command[command.index("-hls_delete_threshold") + 1] == "12"
    assert "append_list" not in command[command.index("-hls_flags") + 1]
    assert "independent_segments" in command[command.index("-hls_flags") + 1]


def test_hls_playlist_ready_requires_segment_file(tmp_path):
    hls_dir = tmp_path / "hls"
    hls_dir.mkdir()
    (hls_dir / "live.m3u8").write_text(
        "#EXTM3U\n#EXT-X-TARGETDURATION:2\n#EXTINF:2.000000,\nseg_00000.ts\n",
        encoding="utf-8",
    )

    assert StreamingService._hls_playlist_ready(hls_dir) is False

    (hls_dir / "seg_00000.ts").write_bytes(b"segment")

    assert StreamingService._hls_playlist_ready(hls_dir) is True


def test_resolve_binary_copies_bundled_exe_to_runtime_temp(tmp_path, monkeypatch):
    resource_dir = tmp_path / "resources"
    streaming_dir = resource_dir / "streaming"
    streaming_dir.mkdir(parents=True)
    bundled = streaming_dir / "ffmpeg.exe"
    bundled.write_bytes(b"portable-ffmpeg")
    monkeypatch.setattr(stream_service, "STREAMING_RESOURCE_DIR", streaming_dir)
    monkeypatch.setattr(stream_service, "STREAMING_CACHE_DIR", tmp_path / "cache")
    monkeypatch.setattr(stream_service, "LEGACY_STREAMING_CACHE_DIR", tmp_path / "legacy-cache")
    monkeypatch.setattr(stream_service.shutil, "which", lambda command: None)
    monkeypatch.setenv("SONAR_STREAM_DISABLE_DOWNLOAD", "1")
    service = StreamingService(temp_root=tmp_path / "temp", prewarm_binaries=False)
    service._temp_dir = tmp_path / "temp" / "session"

    resolved = service._resolve_binary(
        "ffmpeg.exe",
        "ffmpeg",
        display_name="FFmpeg",
        archive_patterns=("ffmpeg*.zip",),
        download_url=None,
    )

    assert resolved == service._runtime_dir / "bin" / "ffmpeg.exe"
    assert resolved.read_bytes() == b"portable-ffmpeg"
    assert (tmp_path / "cache" / "bin" / "ffmpeg.exe").read_bytes() == b"portable-ffmpeg"
    assert bundled.read_bytes() == b"portable-ffmpeg"


def test_resolve_binary_downloads_and_extracts_zip_to_runtime_temp(tmp_path, monkeypatch):
    resource_dir = tmp_path / "empty-resources"
    streaming_dir = resource_dir / "streaming"
    streaming_dir.mkdir(parents=True)
    archive = tmp_path / "source-ffmpeg.zip"
    with zipfile.ZipFile(archive, "w") as zip_file:
        zip_file.writestr("ffmpeg-build/bin/ffmpeg.exe", b"downloaded-ffmpeg")
    monkeypatch.setattr(stream_service, "STREAMING_RESOURCE_DIR", streaming_dir)
    monkeypatch.setattr(stream_service, "STREAMING_CACHE_DIR", tmp_path / "cache")
    monkeypatch.setattr(stream_service, "LEGACY_STREAMING_CACHE_DIR", tmp_path / "legacy-cache")
    monkeypatch.setattr(stream_service.shutil, "which", lambda command: None)
    monkeypatch.delenv("SONAR_STREAM_DISABLE_DOWNLOAD", raising=False)
    service = StreamingService(temp_root=tmp_path / "temp", prewarm_binaries=False)
    service._temp_dir = tmp_path / "temp" / "session"

    def fake_download(url: str, target: Path) -> None:
        shutil.copy2(archive, target)

    monkeypatch.setattr(service, "_download_file", fake_download)

    resolved = service._resolve_binary(
        "ffmpeg.exe",
        "ffmpeg",
        display_name="FFmpeg",
        archive_patterns=("ffmpeg*.zip",),
        download_url="https://example.test/ffmpeg.zip",
    )

    assert resolved == service._runtime_dir / "bin" / "ffmpeg.exe"
    assert resolved.read_bytes() == b"downloaded-ffmpeg"
    assert (tmp_path / "cache" / "bin" / "ffmpeg.exe").read_bytes() == b"downloaded-ffmpeg"


def test_resolve_binary_reuses_persistent_cache(tmp_path, monkeypatch):
    streaming_dir = tmp_path / "resources" / "streaming"
    streaming_dir.mkdir(parents=True)
    cache_dir = tmp_path / "cache"
    cached = cache_dir / "bin" / "ffmpeg.exe"
    cached.parent.mkdir(parents=True)
    cached.write_bytes(b"cached-ffmpeg")
    monkeypatch.setattr(stream_service, "STREAMING_RESOURCE_DIR", streaming_dir)
    monkeypatch.setattr(stream_service, "STREAMING_CACHE_DIR", cache_dir)
    monkeypatch.setattr(stream_service, "LEGACY_STREAMING_CACHE_DIR", tmp_path / "legacy-cache")
    monkeypatch.setattr(stream_service.shutil, "which", lambda command: None)
    monkeypatch.setenv("SONAR_STREAM_DISABLE_DOWNLOAD", "1")
    service = StreamingService(temp_root=tmp_path / "temp", prewarm_binaries=False)

    resolved = service._resolve_binary(
        "ffmpeg.exe",
        "ffmpeg",
        display_name="FFmpeg",
        archive_patterns=("ffmpeg*.zip",),
        download_url=None,
    )

    assert resolved == service._runtime_dir / "bin" / "ffmpeg.exe"
    assert resolved.read_bytes() == b"cached-ffmpeg"


def test_resolve_binary_reuses_legacy_app_cache(tmp_path, monkeypatch):
    streaming_dir = tmp_path / "resources" / "streaming"
    streaming_dir.mkdir(parents=True)
    cache_dir = tmp_path / "cache"
    legacy_cache_dir = tmp_path / "legacy-cache"
    cached = legacy_cache_dir / "bin" / "ffmpeg.exe"
    cached.parent.mkdir(parents=True)
    cached.write_bytes(b"legacy-cached-ffmpeg")
    monkeypatch.setattr(stream_service, "STREAMING_RESOURCE_DIR", streaming_dir)
    monkeypatch.setattr(stream_service, "STREAMING_CACHE_DIR", cache_dir)
    monkeypatch.setattr(stream_service, "LEGACY_STREAMING_CACHE_DIR", legacy_cache_dir)
    monkeypatch.setattr(stream_service.shutil, "which", lambda command: None)
    monkeypatch.setenv("SONAR_STREAM_DISABLE_DOWNLOAD", "1")
    service = StreamingService(temp_root=tmp_path / "temp", prewarm_binaries=False)

    resolved = service._resolve_binary(
        "ffmpeg.exe",
        "ffmpeg",
        display_name="FFmpeg",
        archive_patterns=("ffmpeg*.zip",),
        download_url=None,
    )

    assert resolved == service._runtime_dir / "bin" / "ffmpeg.exe"
    assert resolved.read_bytes() == b"legacy-cached-ffmpeg"


def test_resolve_binary_can_disable_runtime_download(tmp_path, monkeypatch):
    streaming_dir = tmp_path / "resources" / "streaming"
    streaming_dir.mkdir(parents=True)
    monkeypatch.setattr(stream_service, "STREAMING_RESOURCE_DIR", streaming_dir)
    monkeypatch.setattr(stream_service, "STREAMING_CACHE_DIR", tmp_path / "cache")
    monkeypatch.setattr(stream_service, "LEGACY_STREAMING_CACHE_DIR", tmp_path / "legacy-cache")
    monkeypatch.setattr(stream_service.shutil, "which", lambda command: None)
    monkeypatch.setenv("SONAR_STREAM_DISABLE_DOWNLOAD", "1")
    service = StreamingService(temp_root=tmp_path / "temp", prewarm_binaries=False)
    service._temp_dir = tmp_path / "temp" / "session"

    resolved = service._resolve_binary(
        "ffmpeg.exe",
        "ffmpeg",
        display_name="FFmpeg",
        archive_patterns=("ffmpeg*.zip",),
        download_url="https://example.test/ffmpeg.zip",
    )

    assert resolved is None


def test_start_stream_returns_while_runtime_is_preparing(tmp_path, monkeypatch):
    started = threading.Event()
    release = threading.Event()
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)

    def slow_resolve_ffmpeg(**kwargs):
        started.set()
        release.wait(timeout=2.0)
        return None

    monkeypatch.setattr(service, "_resolve_ffmpeg_binary", slow_resolve_ffmpeg)

    started_at = time.monotonic()
    assert service.start_stream() is True
    elapsed = time.monotonic() - started_at

    assert elapsed < 0.5
    assert started.wait(timeout=1.0)
    assert service.snapshot().status == "starting"
    service.stop_stream("test cleanup")
    release.set()
    if service._start_thread is not None:
        service._start_thread.join(timeout=2.0)


def test_start_stream_waits_for_background_ffmpeg_prepare(tmp_path, monkeypatch):
    release = threading.Event()
    fake_ffmpeg = tmp_path / "ffmpeg.exe"
    fake_ffmpeg.write_bytes(b"ffmpeg")
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._binary_ready.clear()
    service._ffmpeg_ready.clear()
    service._cloudflared_ready.clear()

    def prepare_worker():
        release.wait(timeout=2.0)
        with service._lock:
            service._ffmpeg_binary = fake_ffmpeg
        service._ffmpeg_ready.set()
        service._cloudflared_ready.set()
        service._binary_ready.set()

    service._binary_prepare_thread = threading.Thread(target=prepare_worker, daemon=True)
    service._binary_prepare_thread.start()

    def fake_http_server():
        service._local_url = "http://127.0.0.1:1"
        service._public_url = service._local_url

    monkeypatch.setattr(service, "_start_http_server_locked", fake_http_server)
    monkeypatch.setattr(service, "_start_ffmpeg_process_locked", lambda ffmpeg: None)
    monkeypatch.setattr(service, "_wait_for_hls_ready", lambda token: None)

    started_at = time.monotonic()
    assert service.start_stream() is True
    elapsed = time.monotonic() - started_at

    assert elapsed < 0.5
    assert service.snapshot().status == "starting"

    release.set()
    assert service._start_thread is not None
    service._start_thread.join(timeout=2.0)

    assert service.snapshot().status == "online"
    service.stop_stream("test cleanup")


def test_start_stream_waits_for_hls_playlist_before_online(tmp_path, monkeypatch):
    fake_ffmpeg = tmp_path / "ffmpeg.exe"
    fake_ffmpeg.write_bytes(b"ffmpeg")
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._ffmpeg_binary = fake_ffmpeg
    release_hls = threading.Event()

    class FakeProcess:
        def poll(self):
            return None

    def fake_http_server():
        service._local_url = "http://127.0.0.1:1"
        service._public_url = service._local_url

    def fake_start_ffmpeg(ffmpeg):
        service._ffmpeg_process = FakeProcess()

    def make_hls_ready():
        release_hls.wait(timeout=2.0)
        assert service._hls_dir is not None
        (service._hls_dir / "live.m3u8").write_text(
            "#EXTM3U\n#EXT-X-TARGETDURATION:2\n#EXTINF:2.000000,\nseg_00000.ts\n",
            encoding="utf-8",
        )
        (service._hls_dir / "seg_00000.ts").write_bytes(b"segment")

    monkeypatch.setattr(service, "_start_http_server_locked", fake_http_server)
    monkeypatch.setattr(service, "_start_ffmpeg_process_locked", fake_start_ffmpeg)
    threading.Thread(target=make_hls_ready, daemon=True).start()

    assert service.start_stream() is True
    time.sleep(0.1)
    assert service.snapshot().status == "starting"

    release_hls.set()
    assert service._start_thread is not None
    service._start_thread.join(timeout=2.0)

    assert service.snapshot().status == "online"
    service.stop_stream("test cleanup")


def test_chat_zoom_restart_waits_for_new_hls_before_online(tmp_path, monkeypatch):
    fake_ffmpeg = tmp_path / "ffmpeg.exe"
    fake_ffmpeg.write_bytes(b"ffmpeg")
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._ffmpeg_binary = fake_ffmpeg
    service._temp_dir = tmp_path / "session"
    service._hls_dir = service._temp_dir / "hls"
    service._hls_dir.mkdir(parents=True)
    service._active = True
    service._status = "online"
    service._runtime_token = "runtime"
    result: list[bool] = []

    class FakeProcess:
        def __init__(self) -> None:
            self.terminated = False

        def poll(self):
            return None

        def terminate(self) -> None:
            self.terminated = True

        def wait(self, timeout=None):
            return 0

    service._ffmpeg_process = FakeProcess()

    def fake_start_ffmpeg(ffmpeg):
        service._ffmpeg_process = FakeProcess()

    monkeypatch.setattr(service, "_start_ffmpeg_process_locked", fake_start_ffmpeg)

    thread = threading.Thread(target=lambda: result.append(service.set_chat_zoom_enabled(True)), daemon=True)
    thread.start()

    deadline = time.monotonic() + 1.0
    while time.monotonic() < deadline and service.snapshot().status != "starting":
        time.sleep(0.01)

    assert service.snapshot().status == "starting"
    assert result == []
    assert service._hls_dir is not None
    (service._hls_dir / "live.m3u8").write_text(
        "#EXTM3U\n#EXT-X-TARGETDURATION:2\n#EXTINF:2.000000,\nseg_00000.ts\n",
        encoding="utf-8",
    )
    (service._hls_dir / "seg_00000.ts").write_bytes(b"segment")

    thread.join(timeout=2.0)

    assert result == [True]
    assert service.snapshot().status == "online"
    assert service.snapshot().area == "chat"
    service.stop_stream("test cleanup")
