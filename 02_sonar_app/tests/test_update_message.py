from sonar.ui.main_window import format_update_message_html


def test_update_message_linkifies_urls_and_keeps_emoji():
    html = format_update_message_html("🐟 Скачать: https://example.com/Sonar.exe\nГотово ✅")

    assert "🐟" in html
    assert "Готово ✅" in html
    assert '<a href="https://example.com/Sonar.exe">https://example.com/Sonar.exe</a>' in html
    assert "<br>" in html


def test_update_message_keeps_trailing_punctuation_outside_link():
    html = format_update_message_html("Ссылка: https://example.com/build).")

    assert '<a href="https://example.com/build">https://example.com/build</a>).' in html

