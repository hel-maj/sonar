from __future__ import annotations

from PySide6.QtCore import Qt
from PySide6.QtTest import QTest
from PySide6.QtWidgets import QApplication

from sonar.ui import widgets
from sonar.ui.widgets import ExternalLinkLabel


def process_qt_events(times: int = 5) -> None:
    app = QApplication.instance() or QApplication([])
    for _ in range(times):
        app.processEvents()


def test_external_link_label_elides_but_keeps_full_clickable_url(monkeypatch):
    app = QApplication.instance() or QApplication([])
    opened_urls: list[str] = []
    monkeypatch.setattr(
        widgets.QDesktopServices,
        'openUrl',
        lambda url: opened_urls.append(url.toString()) or True,
    )
    url = 'https://example.trycloudflare.com/live/very/long/path/that/does/not/fit'
    label = ExternalLinkLabel()
    label.resize(130, 22)
    label.set_link(url)
    label.show()
    process_qt_events()

    assert label.url() == url
    assert label.full_text() == url
    assert label.toolTip() == url
    assert label.text() != url

    QTest.mouseClick(label, Qt.MouseButton.LeftButton)

    assert opened_urls == [url]


def test_external_link_label_can_return_to_plain_text():
    QApplication.instance() or QApplication([])
    label = ExternalLinkLabel()
    label.set_link('https://example.test/live')
    label.set_plain_text('Ошибка запуска', 'Подробность')

    assert label.url() == ''
    assert label.full_text() == 'Ошибка запуска'
    assert label.toolTip() == 'Подробность'
