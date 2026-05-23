from __future__ import annotations

from PySide6.QtCore import QRectF, Qt
from PySide6.QtGui import QColor, QLinearGradient, QPainter, QPainterPath, QPen, QPixmap
from PySide6.QtWidgets import QPushButton, QWidget

from sonar.ui import overview_redesign, widgets


class FixedGamePreviewFrame(overview_redesign.GamePreviewFrame):
    def __init__(self, parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self.setFixedSize(236, 188)

    @staticmethod
    def _load_preview() -> QPixmap:
        pixmap = overview_redesign.GamePreviewFrame._load_preview()
        if pixmap.isNull():
            return QPixmap()
        return pixmap

    def paintEvent(self, event) -> None:  # type: ignore[override]
        super(overview_redesign.GamePreviewFrame, self).paintEvent(event)
        painter = QPainter(self)
        painter.setRenderHint(QPainter.RenderHint.Antialiasing)
        path = QPainterPath()
        path.addRoundedRect(QRectF(self.rect()), 12, 12)
        painter.setClipPath(path)
        if self._pixmap.isNull():
            self._draw_fallback_preview(painter)
            painter.end()
            return
        scaled = self._pixmap.scaled(self.size(), Qt.AspectRatioMode.KeepAspectRatioByExpanding, Qt.TransformationMode.SmoothTransformation)
        x = (self.width() - scaled.width()) // 2
        y = (self.height() - scaled.height()) // 2
        painter.drawPixmap(x, y, scaled)
        painter.end()

    def _draw_fallback_preview(self, painter: QPainter) -> None:
        sky = QLinearGradient(0, 0, 0, self.height())
        sky.setColorAt(0, QColor('#8fb3d4'))
        sky.setColorAt(0.48, QColor('#f5cf9b'))
        sky.setColorAt(0.5, QColor('#4b7892'))
        sky.setColorAt(1, QColor('#2f5c75'))
        painter.fillRect(self.rect(), sky)

        painter.setPen(Qt.PenStyle.NoPen)
        painter.setBrush(QColor(34, 54, 67, 180))
        painter.drawRect(0, int(self.height() * 0.47), self.width(), 10)
        painter.setPen(QPen(QColor(255, 226, 173, 120), 1))
        for offset in range(0, 56, 9):
            y = int(self.height() * 0.62) + offset
            painter.drawLine(18, y, self.width() - 14, y + 2)

        body_x = int(self.width() * 0.47)
        body_y = int(self.height() * 0.55)
        painter.setPen(Qt.PenStyle.NoPen)
        painter.setBrush(QColor('#202a35'))
        painter.drawEllipse(body_x - 8, body_y - 32, 16, 16)
        painter.drawRoundedRect(body_x - 10, body_y - 16, 20, 42, 8, 8)
        painter.drawRect(body_x - 14, body_y + 24, 8, 34)
        painter.drawRect(body_x + 6, body_y + 24, 8, 34)
        painter.setPen(QPen(QColor('#2b3340'), 3))
        painter.drawLine(body_x + 8, body_y - 10, self.width() - 36, 34)


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
                button.setGraphicsEffect(None)
            elif text == 'Остановить':
                button.setObjectName('overviewStopButton')
                button.setGraphicsEffect(None)
            elif text == 'Настроить':
                button.setObjectName('overviewSettingsButton')
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
