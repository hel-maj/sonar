from __future__ import annotations

import io
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
    assert command[command.index("-video_size") + 1] == "540x720"


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


def test_chat_memory_can_be_enabled_without_chat_mode(tmp_path, monkeypatch):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    monkeypatch.setattr(service, "_chat_memory_scan_worker", lambda generation: None)

    snapshot = service.set_chat_memory_enabled(True)

    assert snapshot.chat_memory_enabled is True
    assert snapshot.chat_mode_enabled is False


def test_chat_mode_restores_previous_chat_memory_setting_on_exit(tmp_path, monkeypatch):
    service = StreamingService(
        temp_root=tmp_path,
        prewarm_binaries=False,
        chat_mode_callback=lambda: ChatActionResult(True, "open"),
        chat_exit_callback=lambda: ChatActionResult(True, "close"),
    )
    monkeypatch.setattr(service, "_refresh_chat_memory_if_needed", lambda *, force=False: None)

    assert service.enable_chat_mode().chat_memory_enabled is True
    assert service.disable_chat_mode().chat_memory_enabled is False

    service.set_chat_memory_enabled(True)
    assert service.enable_chat_mode().chat_memory_enabled is True
    assert service.disable_chat_mode().chat_memory_enabled is True


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


def test_forced_chat_mode_disable_clears_mode_when_exit_callback_fails(tmp_path):
    service = StreamingService(
        temp_root=tmp_path,
        prewarm_binaries=False,
        chat_exit_callback=lambda: ChatActionResult(False, "close failed"),
    )
    service._chat_mode_enabled = True

    snapshot = service.disable_chat_mode(force=True)

    assert snapshot.chat_mode_enabled is False
    assert snapshot.error == "close failed"


def test_stop_stream_exits_chat_mode_before_runtime_cleanup(tmp_path):
    calls: list[str] = []
    service = StreamingService(
        temp_root=tmp_path,
        prewarm_binaries=False,
        chat_exit_callback=lambda: calls.append("close") or ChatActionResult(True, "closed"),
    )
    service._active = True
    service._status = "online"
    service._chat_mode_enabled = True

    service.stop_stream("test")

    assert calls == ["close"]
    assert service.snapshot().chat_mode_enabled is False
    assert service.snapshot().status == "offline"


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
    assert "player.src([])" in STREAM_PAGE_HTML
    assert "player.load()" in STREAM_PAGE_HTML
    assert "/api/stream/chat-send" in STREAM_PAGE_HTML
    assert "/api/stream/chat-select" in STREAM_PAGE_HTML
    assert "/api/stream/chat-memory" in STREAM_PAGE_HTML
    assert "/api/stream/chat" in STREAM_PAGE_HTML
    assert "outboxConfirmationCandidates" in STREAM_PAGE_HTML
    assert "recordConfirmsOutbox(record, item)" in STREAM_PAGE_HTML
    assert "confirmedOutboxMatches" in STREAM_PAGE_HTML
    assert "chat_confirmed_outbox" in STREAM_PAGE_HTML
    assert "Ждёт подтверждения" in STREAM_PAGE_HTML
    assert "Ждёт дамп" in STREAM_PAGE_HTML
    assert "Не подтверждено" in STREAM_PAGE_HTML
    assert "повторная отправка" not in STREAM_PAGE_HTML
    assert "retryItems" not in STREAM_PAGE_HTML
    assert "4500" not in STREAM_PAGE_HTML
    assert "/api/stream/snapshot-batch" not in STREAM_PAGE_HTML
    assert "snapshotStream" not in STREAM_PAGE_HTML
    assert "fps10" in STREAM_PAGE_HTML
    assert "chatTabs" in STREAM_PAGE_HTML
    assert "commandHelpButton" in STREAM_PAGE_HTML
    assert "streamHidden" in STREAM_PAGE_HTML
    assert "window.close()" in STREAM_PAGE_HTML
    assert "Режим 10fps" in STREAM_PAGE_HTML
    assert "Выйти из режима чата" in STREAM_PAGE_HTML


def test_chat_memory_refresh_does_not_show_loading_when_history_exists(tmp_path, monkeypatch):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._chat_mode_enabled = True
    service._chat_memory = {"records": [{"text": "old"}], "tabs": [{"id": "all", "name": "Все"}]}
    service._chat_memory_at = -1_000_000.0
    monkeypatch.setattr(service, "_chat_memory_scan_worker", lambda generation: None)

    service._refresh_chat_memory_if_needed(force=True)

    with service._lock:
        assert service._chat_memory_loading is False


def test_chat_confirmation_queries_cover_me_and_short_ic() -> None:
    me_queries = StreamingService._chat_confirmation_queries("/m решил подрочить", "Marvin Angels")
    short_ic_queries = StreamingService._chat_confirmation_queries("12345", "Marvin Angels")

    assert "Marvin Angels решил подрочить" in me_queries
    assert "решил подрочить" in me_queries
    assert "Marvin Angels говорит: 12345" in short_ic_queries
    assert "говорит: 12345" in short_ic_queries
    assert "12345" not in short_ic_queries


def test_send_chat_message_waits_for_memory_confirmation(tmp_path, monkeypatch):
    service = StreamingService(
        temp_root=tmp_path,
        prewarm_binaries=False,
        chat_send_callback=lambda tab_id, message: ChatActionResult(True, "Сообщение отправлено"),
    )
    confirm_calls: list[bool] = []
    monkeypatch.setattr(service, "_refresh_chat_memory_if_needed", lambda *, force=False: None)
    monkeypatch.setattr(service, "_refresh_chat_confirmations_if_needed", lambda *, force=False: confirm_calls.append(force))

    service.send_chat_message(None, "12345")

    assert confirm_calls == [True]
    with service._lock:
        assert len(service._chat_recent_sends) == 1
        assert service._chat_recent_sends[0]["text"] == "12345"
        assert service._chat_recent_sends[0]["confirmed"] is False


def test_ffmpeg_hls_window_is_tuned_for_lower_latency(tmp_path):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._temp_dir = tmp_path / "session"
    service._hls_dir = service._temp_dir / "hls"
    service._hls_dir.mkdir(parents=True)

    command = service._build_ffmpeg_command(Path("ffmpeg.exe"))

    assert command[command.index("-framerate") + 1] == "30"
    assert command[command.index("-g") + 1] == "30"
    assert command[command.index("-hls_time") + 1] == "1"
    assert command[command.index("-hls_list_size") + 1] == "5"
    assert command[command.index("-hls_delete_threshold") + 1] == "5"
    assert "append_list" not in command[command.index("-hls_flags") + 1]
    assert "independent_segments" in command[command.index("-hls_flags") + 1]


def test_ffmpeg_command_captures_system_audio_by_default(tmp_path, monkeypatch):
    monkeypatch.delenv("SONAR_STREAM_AUDIO_ENABLED", raising=False)
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._temp_dir = tmp_path / "session"
    service._hls_dir = service._temp_dir / "hls"
    service._hls_dir.mkdir(parents=True)

    command = service._build_ffmpeg_command(Path("ffmpeg.exe"))

    assert "-an" not in command
    assert "wasapi" in command
    assert "-loopback" in command
    assert command[command.index("-c:a") + 1] == "aac"
    assert command[command.index("-b:a") + 1] == "128k"
    assert command[command.index("-map") + 1] == "0:v:0"
    assert "1:a:0" in command


def test_ffmpeg_command_can_disable_stream_audio(tmp_path, monkeypatch):
    monkeypatch.setenv("SONAR_STREAM_AUDIO_ENABLED", "0")
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._temp_dir = tmp_path / "session"
    service._hls_dir = service._temp_dir / "hls"
    service._hls_dir.mkdir(parents=True)

    command = service._build_ffmpeg_command(Path("ffmpeg.exe"))

    assert "-an" in command
    assert "wasapi" not in command
    assert "-c:a" not in command


def test_low_fps_mode_uses_ffmpeg_hls_at_ten_fps(tmp_path):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._snapshot_mode_enabled = True
    service._temp_dir = tmp_path / "session"
    service._hls_dir = service._temp_dir / "hls"
    service._hls_dir.mkdir(parents=True)

    command = service._build_ffmpeg_command(Path("ffmpeg.exe"))

    assert command[command.index("-framerate") + 1] == "10"
    assert command[command.index("-g") + 1] == "10"
    assert "gdigrab" in command


def test_stream_quality_bitrates_match_resolution_and_fps_profiles():
    profiles = {
        "480p": ("1200k", "600k"),
        "720p": ("2900k", "1500k"),
        "1080p": ("5000k", "2300k"),
    }

    for quality_name, (default_bitrate, low_fps_bitrate) in profiles.items():
        quality = stream_service.STREAM_QUALITIES[quality_name]

        assert quality.bitrate_for_fps(stream_service.DEFAULT_STREAM_FPS) == default_bitrate
        assert quality.bitrate_for_fps(stream_service.LOW_FPS_STREAM_FPS) == low_fps_bitrate


def test_ffmpeg_command_uses_profile_bitrate_for_default_fps(tmp_path):
    expected_bitrates = {
        "480p": "1200k",
        "720p": "2900k",
        "1080p": "5000k",
    }

    for quality_name, bitrate in expected_bitrates.items():
        service = StreamingService(temp_root=tmp_path / quality_name, prewarm_binaries=False)
        service._quality = quality_name
        service._temp_dir = tmp_path / quality_name / "session"
        service._hls_dir = service._temp_dir / "hls"
        service._hls_dir.mkdir(parents=True)

        command = service._build_ffmpeg_command(Path("ffmpeg.exe"))

        assert command[command.index("-b:v") + 1] == bitrate
        assert command[command.index("-maxrate") + 1] == bitrate
        assert command[command.index("-bufsize") + 1] == service._double_bitrate(bitrate)


def test_ffmpeg_command_uses_profile_bitrate_for_low_fps(tmp_path):
    expected_bitrates = {
        "480p": "600k",
        "720p": "1500k",
        "1080p": "2300k",
    }

    for quality_name, bitrate in expected_bitrates.items():
        service = StreamingService(temp_root=tmp_path / quality_name, prewarm_binaries=False)
        service._quality = quality_name
        service._snapshot_mode_enabled = True
        service._temp_dir = tmp_path / quality_name / "session"
        service._hls_dir = service._temp_dir / "hls"
        service._hls_dir.mkdir(parents=True)

        command = service._build_ffmpeg_command(Path("ffmpeg.exe"))

        assert command[command.index("-b:v") + 1] == bitrate
        assert command[command.index("-maxrate") + 1] == bitrate
        assert command[command.index("-bufsize") + 1] == service._double_bitrate(bitrate)


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


def test_cloudflared_command_uses_http2_by_default(tmp_path, monkeypatch):
    monkeypatch.delenv("SONAR_STREAM_CLOUDFLARED_PROTOCOL", raising=False)
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._local_url = "http://127.0.0.1:12345"

    command = service._build_cloudflared_command(Path("cloudflared.exe"))

    assert command == [
        "cloudflared.exe",
        "tunnel",
        "--edge-ip-version",
        "4",
        "--protocol",
        "http2",
        "--url",
        "http://127.0.0.1:12345",
    ]


def test_cloudflared_protocol_can_be_overridden(tmp_path, monkeypatch):
    monkeypatch.setenv("SONAR_STREAM_CLOUDFLARED_PROTOCOL", "quic")
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._local_url = "http://127.0.0.1:12345"

    command = service._build_cloudflared_command(Path("cloudflared.exe"))

    assert command[command.index("--protocol") + 1] == "quic"


def test_cloudflared_edge_ip_version_can_be_overridden(tmp_path, monkeypatch):
    monkeypatch.setenv("SONAR_STREAM_CLOUDFLARED_EDGE_IP_VERSION", "auto")
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._local_url = "http://127.0.0.1:12345"

    command = service._build_cloudflared_command(Path("cloudflared.exe"))

    assert command[command.index("--edge-ip-version") + 1] == "auto"


def test_tunnelmole_command_uses_local_port(tmp_path):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._local_url = "http://127.0.0.1:12345"

    command = service._build_tunnelmole_command(["tmole"])

    assert command == ["tmole", "12345"]


def test_cloudflared_after_three_failed_starts_falls_back_to_tunnelmole(tmp_path, monkeypatch):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._active = True
    service._runtime_token = "runtime-token"
    fallback_tokens: list[str] = []
    monkeypatch.setattr(service, "_resolve_cloudflared_binary", lambda wait_timeout=None: Path("cloudflared.exe"))
    monkeypatch.setattr(service, "_start_cloudflared_process_locked", lambda cloudflared: (_ for _ in ()).throw(RuntimeError("boom")))
    monkeypatch.setattr(service, "_start_tunnelmole_worker", lambda token: fallback_tokens.append(token))

    service._start_tunnel_worker("runtime-token")
    service._start_tunnel_worker("runtime-token")
    service._start_tunnel_worker("runtime-token")

    assert service._cloudflared_start_attempts == 3
    assert fallback_tokens == ["runtime-token"]


def test_cloudflared_url_waits_for_registered_connection(tmp_path):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._active = True
    service._local_url = "http://127.0.0.1:12345"
    service._public_url = service._local_url

    class FakeProcess:
        stdout = iter([
            "|  https://example.trycloudflare.com  |\n",
        ])

        def poll(self):
            return None

    process = FakeProcess()
    service._cloudflared_process = process

    service._watch_cloudflared_output(process, io.StringIO())

    assert service._public_url == "http://127.0.0.1:12345"


def test_cloudflared_url_publishes_after_registered_connection(tmp_path, monkeypatch):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._active = True
    service._local_url = "http://127.0.0.1:12345"
    service._public_url = service._local_url
    monkeypatch.setattr(service, "_schedule_public_tunnel_publish", lambda process, url: setattr(service, "_public_url", url))

    class FakeProcess:
        stdout = iter([
            "|  https://example.trycloudflare.com  |\n",
            "INF Registered tunnel connection connIndex=0 protocol=http2\n",
        ])

        def poll(self):
            return None

    process = FakeProcess()
    service._cloudflared_process = process

    service._watch_cloudflared_output(process, io.StringIO())

    assert service._public_url == "https://example.trycloudflare.com"


def test_tunnelmole_url_publishes_when_announced(tmp_path, monkeypatch):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._active = True
    service._local_url = "http://127.0.0.1:12345"
    service._public_url = service._local_url
    service._tunnel_provider = "tunnelmole"
    monkeypatch.setattr(service, "_schedule_public_tunnel_publish", lambda process, url: setattr(service, "_public_url", url))

    class FakeProcess:
        stdout = iter([
            "https://blue.tunnelmole.net is forwarding to localhost:12345\n",
        ])

        def poll(self):
            return None

    process = FakeProcess()
    service._cloudflared_process = process

    service._watch_tunnelmole_output(process, io.StringIO())

    assert service._public_url == "https://blue.tunnelmole.net"


def test_cloudflared_transient_serve_error_keeps_public_url(tmp_path, monkeypatch):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._active = True
    service._local_url = "http://127.0.0.1:12345"
    service._public_url = service._local_url
    monkeypatch.setattr(service, "_schedule_public_tunnel_publish", lambda process, url: setattr(service, "_public_url", url))

    class FakeProcess:
        stdout = iter([
            "|  https://example.trycloudflare.com  |\n",
            "INF Registered tunnel connection connIndex=0 protocol=http2\n",
            'ERR Serve tunnel error error="context canceled"\n',
        ])

        def poll(self):
            return None

    process = FakeProcess()
    service._cloudflared_process = process

    service._watch_cloudflared_output(process, io.StringIO())

    assert service._public_url == "https://example.trycloudflare.com"


def test_cloudflared_process_exit_clears_public_url(tmp_path):
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._active = True
    service._local_url = "http://127.0.0.1:12345"
    service._public_url = "https://example.trycloudflare.com"

    class FakeProcess:
        stdout = iter([])

        def poll(self):
            return 1

    process = FakeProcess()
    service._cloudflared_process = process

    service._watch_cloudflared_output(process, io.StringIO())

    assert service._public_url == "http://127.0.0.1:12345"


def test_cloudflared_url_readiness_timeout_restarts_tunnel(tmp_path, monkeypatch):
    monkeypatch.setattr(stream_service, "CLOUDFLARED_PUBLIC_URL_READY_TIMEOUT_SECONDS", 0.01)
    monkeypatch.setattr(stream_service, "CLOUDFLARED_PUBLIC_URL_READY_POLL_SECONDS", 0.001)
    monkeypatch.setattr(stream_service, "CLOUDFLARED_PUBLIC_URL_RESTART_BACKOFF_SECONDS", 0.0)
    service = StreamingService(temp_root=tmp_path, prewarm_binaries=False)
    service._active = True
    service._runtime_token = "runtime-token"
    service._local_url = "http://127.0.0.1:12345"
    service._public_url = service._local_url

    class FakeProcess:
        def poll(self):
            return None

    process = FakeProcess()
    service._cloudflared_process = process
    monkeypatch.setattr(service, "_public_tunnel_url_check", lambda url: (False, "http_error=530"))
    terminated: list[object] = []
    restarted: list[str] = []
    monkeypatch.setattr(service, "_terminate_process", lambda proc: terminated.append(proc))
    monkeypatch.setattr(service, "_start_tunnel_worker", lambda token: restarted.append(token))

    service._publish_public_tunnel_when_ready(process, "https://example.trycloudflare.com")

    assert terminated == [process]
    assert restarted == ["runtime-token"]
    assert service._cloudflared_process is None
    assert service._public_url == "http://127.0.0.1:12345"


def test_cloudflared_url_check_rejects_530_from_curl(monkeypatch):
    class FakeResult:
        stdout = "530"
        stderr = ""
        returncode = 0

    monkeypatch.setattr(stream_service.shutil, "which", lambda command: "curl.exe" if command == "curl.exe" else None)
    monkeypatch.setattr(stream_service.subprocess, "run", lambda *args, **kwargs: FakeResult())

    reachable, detail = StreamingService._public_tunnel_url_check("https://example.trycloudflare.com")

    assert reachable is False
    assert "status=530" in detail


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
