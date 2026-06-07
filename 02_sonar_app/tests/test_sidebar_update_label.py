from __future__ import annotations

from PySide6.QtCore import Qt
from PySide6.QtTest import QTest
from PySide6.QtWidgets import QApplication, QVBoxLayout, QWidget

from sonar.ui.main_window import MainWindow
from sonar.ui.widgets import ClickableLabel


def test_clickable_label_emits_left_click():
    QApplication.instance() or QApplication([])
    clicks: list[bool] = []
    label = ClickableLabel('Доступна новая версия')
    label.clicked.connect(lambda: clicks.append(True))
    label.resize(130, 40)
    label.show()

    QTest.mouseClick(label, Qt.MouseButton.LeftButton)

    assert clicks == [True]


def test_sidebar_update_label_wraps_and_opens_about_tab():
    QApplication.instance() or QApplication([])
    selected: list[QWidget] = []
    about_tab = QWidget()
    window = MainWindow.__new__(MainWindow)
    window.license_tab = QWidget()
    window.about_tab = about_tab
    window._select_page = selected.append
    holder = QWidget()
    layout = QVBoxLayout(holder)

    MainWindow._build_sidebar(window, layout)
    window.sidebar_update_label.setText('Доступна новая версия: v123456789')

    assert window.sidebar_update_label.wordWrap() is True
    assert window.sidebar_update_label.toolTip() == 'Открыть вкладку «О программе»'

    window.sidebar_update_label.clicked.emit()

    assert selected == [about_tab]
