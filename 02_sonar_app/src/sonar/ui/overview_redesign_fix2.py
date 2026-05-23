from __future__ import annotations

from PySide6.QtWidgets import QPushButton, QWidget

from sonar.ui import overview_redesign, widgets


BaseGamePreviewFrame = overview_redesign.GamePreviewFrame


class FixedGamePreviewFrame(BaseGamePreviewFrame):
    def __init__(self, parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self.setFixedSize(236, 188)


def _patch_window_size(main_window_module) -> None:
    if getattr(main_window_module.MainWindow, '_overview_window_size_patched', False):
        return
    original_init = main_window_module.MainWindow.__init__

    def patched_init(self, *args, **kwargs) -> None:
        original_init(self, *args, **kwargs)
        self.setFixedSize(1536, 960)

    main_window_module.MainWindow.__init__ = patched_init
    main_window_module.MainWindow._overview_window_size_patched = True


def _patch_overview_buttons(main_window_module) -> None:
    if getattr(main_window_module.MainWindow, '_overview_buttons_patched', False):
        return
    original_build = main_window_module.MainWindow._build_overview_tab

    def patched_build(self):
        page = original_build(self)
        for button in page.findChildren(QPushButton):
            text = button.text().strip()
            if text == 'Запустить':
                button.setObjectName('overviewStartButton')
            elif text == 'Остановить':
                button.setObjectName('overviewStopButton')
            elif text == 'Настроить':
                button.setObjectName('overviewSettingsButton')
            if text in {'Запустить', 'Остановить', 'Настроить'}:
                button.setGraphicsEffect(None)
                button.style().unpolish(button)
                button.style().polish(button)
        return page

    main_window_module.MainWindow._build_overview_tab = patched_build
    main_window_module.MainWindow._overview_buttons_patched = True


def apply(main_window_module) -> None:
    overview_redesign.GamePreviewFrame = FixedGamePreviewFrame
    overview_redesign.apply(main_window_module)
    _patch_window_size(main_window_module)
    _patch_overview_buttons(main_window_module)
    qss = """
QPushButton#overviewStartButton {
    color: #ffffff;
    background: #1677ff;
    border: 1px solid #1677ff;
    border-radius: 11px;
    font-weight: 850;
}
QPushButton#overviewStartButton:hover {
    color: #ffffff;
    background: #2f80ff;
}
QPushButton#overviewStartButton:disabled {
    color: #dce9ff;
    background: #9ec5ff;
    border-color: #9ec5ff;
}
QPushButton#overviewStopButton {
    color: #ffffff;
    background: #ff4d57;
    border: 1px solid #ff4d57;
    border-radius: 11px;
    font-weight: 850;
}
QPushButton#overviewStopButton:hover {
    color: #ffffff;
    background: #ff5d66;
}
QPushButton#overviewStopButton:disabled {
    color: #ffe2e4;
    background: #ffa4aa;
    border-color: #ffa4aa;
}
QPushButton#overviewSettingsButton {
    background: #ffffff;
    color: #17203c;
    border: 1px solid #dce6f3;
    border-radius: 11px;
    font-weight: 800;
}
QFrame#overviewFishingCard {
    min-height: 288px;
}
QFrame#overviewHotkeyCard {
    min-height: 72px;
    max-height: 72px;
}
"""
    if 'overviewStartButton' not in widgets.SONAR_QSS:
        widgets.SONAR_QSS = widgets.SONAR_QSS + qss
