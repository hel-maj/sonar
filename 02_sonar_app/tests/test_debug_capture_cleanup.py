from __future__ import annotations

import sonar.fishing.bot as bot_module
from sonar.fishing.bot import FishingBot


def test_debug_capture_is_cleared_for_new_session_unless_kept(tmp_path, monkeypatch):
    monkeypatch.setattr(bot_module, "DEBUG_CAPTURE_ROOT_DIR", tmp_path)
    old_dir = tmp_path / "old"
    old_dir.mkdir()
    (old_dir / "frame.png").write_text("old", encoding="utf-8")
    (tmp_path / "metadata.csv").write_text("old", encoding="utf-8")

    bot = FishingBot.__new__(FishingBot)
    bot.keep_debug_capture = False

    bot._clear_debug_capture_for_new_session()

    assert list(tmp_path.iterdir()) == []

    kept_dir = tmp_path / "kept"
    kept_dir.mkdir()
    (kept_dir / "frame.png").write_text("kept", encoding="utf-8")
    bot.keep_debug_capture = True

    bot._clear_debug_capture_for_new_session()

    assert (kept_dir / "frame.png").exists()
