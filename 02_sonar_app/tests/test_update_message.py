from sonar.ui import main_window
from sonar.ui.main_window import format_download_link_html, format_update_message_html, is_update_available


def test_update_message_linkifies_urls_and_keeps_emoji():
    html = format_update_message_html("🐟 Скачать: https://example.com/Sonar.exe\nГотово ✅")

    assert "🐟" in html
    assert "Готово ✅" in html
    assert '<a href="https://example.com/Sonar.exe">https://example.com/Sonar.exe</a>' in html
    assert "<br>" in html


def test_update_message_keeps_trailing_punctuation_outside_link():
    html = format_update_message_html("Ссылка: https://example.com/build).")

    assert '<a href="https://example.com/build">https://example.com/build</a>).' in html


def test_update_message_accepts_literal_newline_escape():
    html = format_update_message_html("Строка 1\\nСтрока 2 🚀")

    assert "Строка 1<br>Строка 2 🚀" in html


def test_download_link_uses_separate_human_label():
    html = format_download_link_html("https://example.com/Sonar.exe")

    assert html == '<a href="https://example.com/Sonar.exe">Скачать обновление</a>'


def test_update_block_is_hidden_when_versions_match():
    assert is_update_available("0.1.0", current_version="0.1.0") is False
    assert is_update_available("v0.1.0", current_version="0.1.0") is False
    assert is_update_available("0.1.1", current_version="0.1.0") is True


def test_release_logo_is_preferred_over_build_icon(tmp_path, monkeypatch):
    logo_path = tmp_path / "logo.png"
    logo_path.write_bytes(b"logo")
    (tmp_path / "app.ico").write_bytes(b"icon")
    monkeypatch.setattr(main_window, "RESOURCE_DIR", tmp_path)

    assert main_window.find_app_logo_path() == logo_path
