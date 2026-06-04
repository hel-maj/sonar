from __future__ import annotations

from pathlib import Path

from PySide6.QtCore import QByteArray, QEvent, QEasingCurve, QPoint, QPropertyAnimation, QRectF, QSize, QTimer, Qt, Property, QUrl, Signal
from PySide6.QtGui import QColor, QDesktopServices, QFontMetrics, QIcon, QPainter, QPixmap
from PySide6.QtSvg import QSvgRenderer
from PySide6.QtWidgets import (
    QFrame,
    QCheckBox,
    QComboBox,
    QGraphicsOpacityEffect,
    QGraphicsDropShadowEffect,
    QHBoxLayout,
    QLabel,
    QPushButton,
    QScrollArea,
    QSizePolicy,
    QToolTip,
    QVBoxLayout,
    QWidget,
)


SONAR_QSS = """
* {
    font-family: "Segoe UI Variable", "Segoe UI", Arial, sans-serif;
    color: #192342;
    outline: none;
}
QMainWindow, QWidget#appRoot {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #f8fbff, stop:0.55 #f4f8ff, stop:1 #eef5ff);
}
QWidget#startupWindow {
    background: transparent;
}
QFrame#sidebar {
    background: #fbfdff;
    border-right: 1px solid #d9e5f3;
}
QFrame#contentShell {
    background: transparent;
}
QFrame[card="true"] {
    background: #ffffff;
    border: 1px solid #dde8f6;
    border-radius: 10px;
}
QFrame[softCard="true"] {
    background: #ffffff;
    border: 1px solid #e2ebf7;
    border-radius: 8px;
}
QFrame[dangerCard="true"] {
    background: #fff4f4;
    border: 1px solid #ffd4d4;
    border-radius: 10px;
}
QLabel[muted="true"] {
    color: #7583a2;
}
QLabel[title="true"] {
    color: #121a35;
    font-size: 19px;
    font-weight: 800;
}
QLabel[sectionTitle="true"] {
    color: #17203c;
    font-size: 13px;
    font-weight: 750;
}
QLabel[metricValue="true"] {
    color: #14203d;
    font-size: 18px;
    font-weight: 800;
}
QLabel[metricLabel="true"] {
    color: #7482a2;
    font-size: 10px;
    font-weight: 600;
}
QLabel[badge="green"] {
    color: #17a34a;
    background: #eafaf0;
    border-radius: 7px;
    padding: 3px 8px;
    font-weight: 700;
}
QLabel[badge="blue"] {
    color: #1268e8;
    background: #eaf2ff;
    border-radius: 7px;
    padding: 3px 8px;
    font-weight: 700;
}
QLabel[badge="red"] {
    color: #e54848;
    background: #fff0f0;
    border-radius: 7px;
    padding: 3px 8px;
    font-weight: 700;
}
QLabel[badge="gray"] {
    color: #697796;
    background: #f2f5fa;
    border-radius: 7px;
    padding: 3px 8px;
    font-weight: 700;
}
QPushButton {
    min-height: 30px;
    padding: 5px 10px;
    border-radius: 8px;
    background: #ffffff;
    border: 1px solid #dce6f3;
    color: #17203c;
    font-weight: 700;
}
QPushButton:hover {
    background: #f5f9ff;
    border-color: #bfd5f4;
}
QPushButton:pressed {
    background: #edf5ff;
}
QPushButton:disabled {
    color: #9aa6bb;
    background: #f2f5fa;
    border-color: #e2e8f2;
}
QPushButton[role="primary"] {
    color: #ffffff;
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #2f80ff, stop:1 #0b63f6);
    border: 1px solid #0b63f6;
}
QPushButton[role="primary"]:hover {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #3b8bff, stop:1 #176cff);
}
QPushButton[role="primary"]:disabled {
    color: #d8e5ff;
    background: #9dc2fb;
    border-color: #9dc2fb;
}
QPushButton[role="danger"] {
    color: #ffffff;
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #ff6066, stop:1 #ff343e);
    border: 1px solid #ff343e;
}
QPushButton[role="danger"]:disabled {
    color: #ffd7d9;
    background: #ffadb1;
    border-color: #ffadb1;
}
QPushButton[role="ghostDanger"] {
    color: #e54848;
    background: #fff7f7;
    border: 1px solid #ffc6c8;
}
QPushButton[buttonSize="xxs"] {
    min-height: 22px;
    padding: 3px 7px;
    border-radius: 6px;
    font-size: 10px;
}
QPushButton[buttonSize="xs"] {
    min-height: 25px;
    padding: 4px 8px;
    border-radius: 7px;
    font-size: 11px;
}
QPushButton[buttonSize="s"] {
    min-height: 28px;
    padding: 5px 9px;
    border-radius: 8px;
    font-size: 12px;
}
QPushButton[buttonSize="l"] {
    min-height: 36px;
    padding: 7px 13px;
    border-radius: 9px;
    font-size: 13px;
}
QPushButton[buttonSize="xl"] {
    min-height: 40px;
    padding: 8px 16px;
    border-radius: 10px;
    font-size: 13px;
}
QPushButton[nav="true"] {
    min-height: 31px;
    padding: 5px 9px;
    text-align: left;
    border: 0;
    border-radius: 8px;
    background: transparent;
    color: #33405e;
    font-weight: 650;
}
QPushButton[nav="true"]:hover {
    background: #edf5ff;
    color: #0d67e9;
}
QPushButton[nav="true"][selected="true"] {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0, stop:0 #e8f2ff, stop:1 #f3f8ff);
    color: #0d67e9;
}
QLineEdit, QComboBox {
    min-height: 30px;
    padding: 4px 9px;
    border-radius: 8px;
    background: #ffffff;
    border: 1px solid #dce6f3;
    color: #17203c;
    selection-background-color: #cfe2ff;
}
QLineEdit:focus, QComboBox:focus {
    border: 1px solid #71a7ff;
    background: #ffffff;
}
QComboBox::drop-down {
    border: none;
    width: 24px;
}
QComboBox QAbstractItemView {
    background: #ffffff;
    border: 1px solid #dce6f3;
    border-radius: 10px;
    padding: 6px;
    selection-background-color: #e9f3ff;
    selection-color: #0d67e9;
}
QCheckBox {
    spacing: 8px;
    color: #24304f;
    font-weight: 600;
}
QCheckBox::indicator {
    width: 42px;
    height: 24px;
    border-radius: 12px;
    background: #d8e2ef;
}
QCheckBox::indicator:checked {
    background: #34c759;
}
QCheckBox::indicator:disabled {
    background: #eef2f7;
}
QTableWidget {
    background: #ffffff;
    border: 1px solid #dde8f6;
    border-radius: 0;
    gridline-color: #e9eef7;
    alternate-background-color: #f8fbff;
    selection-background-color: #e8f2ff;
    selection-color: #17203c;
}
QHeaderView::section {
    background: #f6f9fd;
    border: 0;
    border-bottom: 1px solid #e2ebf7;
    padding: 7px;
    color: #63718f;
    font-weight: 800;
}
QScrollArea {
    background: transparent;
    border: none;
}
QScrollArea#pageScrollArea, QScrollArea#pageScrollArea > QWidget, QScrollArea#pageScrollArea > QWidget > QWidget {
    background: transparent;
}
QWidget#pageScrollViewport, QWidget#scrollPageContent {
    background: transparent;
}
QAbstractScrollArea::corner {
    background: transparent;
    border: none;
}
QScrollBar:vertical {
    width: 10px;
    margin: 0;
    background: #edf3fb;
    border: none;
    border-radius: 5px;
}
QScrollBar::handle:vertical {
    background: #b9c7dc;
    min-height: 28px;
    border-radius: 5px;
    margin: 2px;
}
QScrollBar::handle:vertical:hover {
    background: #94a8c5;
}
QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
    width: 0;
    height: 0;
    background: transparent;
    border: none;
}
QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
    background: transparent;
    border: none;
}
QScrollBar:horizontal {
    height: 10px;
    margin: 0;
    background: #edf3fb;
    border: none;
    border-radius: 5px;
}
QScrollBar::handle:horizontal {
    background: #b9c7dc;
    min-width: 28px;
    border-radius: 5px;
    margin: 2px;
}
QScrollBar::handle:horizontal:hover {
    background: #94a8c5;
}
QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {
    width: 0;
    height: 0;
    background: transparent;
    border: none;
}
QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {
    background: transparent;
    border: none;
}
QScrollArea#fishKeepScroll {
    background: #ffffff;
    border: none;
}
QScrollArea#fishKeepScroll > QWidget > QWidget {
    background: #ffffff;
}
QWidget#fishKeepList {
    background: #ffffff;
}
QFrame#fishKeepCard {
    background: #ffffff;
    border: 1px solid #e1eaf6;
    border-radius: 8px;
}
QScrollArea#recentEventsScroll, QScrollArea#recentEventsScroll > QWidget, QScrollArea#recentEventsScroll > QWidget > QWidget, QWidget#recentEventsWidget {
    background: transparent;
}
QFrame#recentEventRow {
    background: transparent;
    border: none;
}
QFrame#recentEventDivider {
    background: #e7eef8;
    border: none;
    min-height: 1px;
    max-height: 1px;
}
QLabel[recentTitle="true"] {
    color: #17203c;
    font-size: 12px;
    font-weight: 400;
}
QLabel[recentTime="true"] {
    color: #7a88a8;
    font-size: 11px;
}
QLabel[recentDetail="true"] {
    color: #687696;
    font-size: 12px;
    font-weight: 400;
}
QLabel[recentExtraGreen="true"] {
    color: #1d9f52;
    font-size: 12px;
    font-weight: 700;
}
QLabel[recentExtraRed="true"] {
    color: #e54848;
    font-size: 12px;
    font-weight: 700;
}
QLabel[recentTime="true"] {
    font-weight: 400;
}
QFrame#startupLoader {
    background: rgba(255,255,255,0.96);
    border: 1px solid #dce7f5;
    border-radius: 20px;
}
QProgressBar {
    height: 7px;
    border: none;
    border-radius: 4px;
    background: #edf2f8;
    text-align: center;
}
QProgressBar::chunk {
    border-radius: 4px;
    background: #1f7aff;
}
QLabel#fishingPreview {
    background: #eef4fb;
    border: 1px solid #d9e5f3;
    border-radius: 6px;
    color: #7583a2;
}
"""


_SVG_TEXT_CACHE: dict[str, str] = {}
_SVG_BYTES_CACHE: dict[tuple[str, str], QByteArray] = {}
_SVG_RENDERER_CACHE: dict[tuple[str, str], QSvgRenderer] = {}


def apply_sonar_style(widget: QWidget) -> None:
    widget.setStyleSheet(SONAR_QSS)


def clear_layout(layout) -> None:
    while layout.count():
        item = layout.takeAt(0)
        child = item.widget()
        child_layout = item.layout()
        if child is not None:
            child.deleteLater()
        elif child_layout is not None:
            clear_layout(child_layout)


def fade_in(widget: QWidget, duration: int = 150) -> None:
    effect = QGraphicsOpacityEffect(widget)
    widget.setGraphicsEffect(effect)
    animation = QPropertyAnimation(effect, b"opacity", widget)
    animation.setStartValue(0.0)
    animation.setEndValue(1.0)
    animation.setDuration(duration)
    animation.setEasingCurve(QEasingCurve.Type.OutCubic)
    widget._sonar_fade_animation = animation  # keep alive
    animation.start()


def load_pixmap(path: Path, size: int | QSize | None = None) -> QPixmap:
    pixmap = QPixmap(str(path))
    if size is None or pixmap.isNull():
        return pixmap
    if isinstance(size, int):
        target = QSize(size, size)
    else:
        target = size
    return pixmap.scaled(target, Qt.AspectRatioMode.KeepAspectRatio, Qt.TransformationMode.SmoothTransformation)


def _tint_svg_text(text: str, color: QColor | str) -> str:
    tint = QColor(color).name()

    def replace_attr(match) -> str:
        attr = match.group(1)
        value = match.group(2)
        if value.lower() in {"none", "transparent"}:
            return match.group(0)
        return f'{attr}="{tint}"'

    import re

    text = re.sub(r'(fill|stroke)="(#[0-9a-fA-F]{3,8}|black|white|rgb\([^)]*\))"', replace_attr, text)
    text = re.sub(r'(fill|stroke):\s*(#[0-9a-fA-F]{3,8}|black|white|rgb\([^;)]*\))', lambda m: f'{m.group(1)}: {tint}', text)
    return text


def _svg_bytes(path: Path, color: QColor | str | None = None) -> QByteArray:
    cache_key = (str(path), QColor(color).name() if color is not None else "")
    cached = _SVG_BYTES_CACHE.get(cache_key)
    if cached is not None:
        return cached
    path_key = str(path)
    text = _SVG_TEXT_CACHE.get(path_key)
    if text is None:
        text = path.read_text(encoding="utf-8", errors="ignore")
        _SVG_TEXT_CACHE[path_key] = text
    if color is not None:
        text = _tint_svg_text(text, color)
    data = QByteArray(text.encode("utf-8"))
    _SVG_BYTES_CACHE[cache_key] = data
    return data


def _svg_renderer(path: Path, color: QColor | str | None = None) -> QSvgRenderer:
    cache_key = (str(path), QColor(color).name() if color is not None else "")
    renderer = _SVG_RENDERER_CACHE.get(cache_key)
    if renderer is None:
        renderer = QSvgRenderer(_svg_bytes(path, color))
        _SVG_RENDERER_CACHE[cache_key] = renderer
    return renderer


def tinted_icon_from_path(path: Path, color: str | QColor, size: int = 32) -> QIcon:
    if not path.exists():
        return QIcon()
    if path.suffix.lower() != ".svg":
        return QIcon(str(path))
    renderer = _svg_renderer(path, color)
    pixmap = QPixmap(size, size)
    pixmap.fill(Qt.GlobalColor.transparent)
    painter = QPainter(pixmap)
    renderer.render(painter)
    painter.end()
    return QIcon(pixmap)


class SvgIcon(QWidget):
    def __init__(self, path: Path, size: int = 24, color: str | QColor = "#1f7aff", parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self.path = path
        self._size = size
        self._color = QColor(color)
        self._animation: QPropertyAnimation | None = None
        self.setFixedSize(size, size)
        self.setSizePolicy(QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed)

    def _get_icon_color(self) -> QColor:
        return QColor(self._color)

    def _set_icon_color(self, color: QColor) -> None:
        self._color = QColor(color)
        self.update()

    iconColor = Property(QColor, _get_icon_color, _set_icon_color)

    def set_color(self, color: str | QColor, *, animated: bool = True) -> None:
        target = QColor(color)
        if not target.isValid() or target == self._color:
            return
        if self._animation is not None:
            self._animation.stop()
        if not animated:
            self._set_icon_color(target)
            return
        animation = QPropertyAnimation(self, b"iconColor", self)
        animation.setStartValue(QColor(self._color))
        animation.setEndValue(target)
        animation.setDuration(150)
        animation.setEasingCurve(QEasingCurve.Type.OutCubic)
        self._animation = animation
        animation.start()

    def paintEvent(self, event) -> None:  # type: ignore[override]
        del event
        if not self.path.exists():
            return
        renderer = _svg_renderer(self.path, self._color)
        painter = QPainter(self)
        painter.setRenderHint(QPainter.RenderHint.Antialiasing)
        renderer.render(painter)
        painter.end()


class Card(QFrame):
    def __init__(self, parent: QWidget | None = None, *, danger: bool = False, soft: bool = False) -> None:
        super().__init__(parent)
        if danger:
            self.setProperty("dangerCard", True)
        elif soft:
            self.setProperty("softCard", True)
        else:
            self.setProperty("card", True)
        self.setAutoFillBackground(True)
        self.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Preferred)
        shadow = QGraphicsDropShadowEffect(self)
        shadow.setBlurRadius(14)
        shadow.setOffset(0, 4)
        shadow.setColor(QColor(32, 55, 95, 18))
        self.setGraphicsEffect(shadow)


class SectionHeader(QWidget):
    def __init__(self, title: str, subtitle: str = "", parent: QWidget | None = None) -> None:
        super().__init__(parent)
        layout = QVBoxLayout(self)
        layout.setContentsMargins(0, 0, 0, 7)
        layout.setSpacing(2)
        title_label = QLabel(title)
        title_label.setProperty("title", True)
        layout.addWidget(title_label)
        if subtitle:
            subtitle_label = QLabel(subtitle)
            subtitle_label.setProperty("muted", True)
            subtitle_label.setWordWrap(True)
            layout.addWidget(subtitle_label)


class Badge(QLabel):
    def __init__(self, text: str, tone: str = "gray", parent: QWidget | None = None) -> None:
        super().__init__(text, parent)
        self.setProperty("badge", tone)
        self.setAlignment(Qt.AlignmentFlag.AlignCenter)

    def set_tone(self, tone: str) -> None:
        self.setProperty("badge", tone)
        self.style().unpolish(self)
        self.style().polish(self)


class ElidedLabel(QLabel):
    def __init__(self, text: str = "", parent: QWidget | None = None, *, tooltip_delay_ms: int = 500) -> None:
        super().__init__(parent)
        self._full_text = ""
        self._is_elided = False
        self._tooltip_timer = QTimer(self)
        self._tooltip_timer.setSingleShot(True)
        self._tooltip_timer.setInterval(tooltip_delay_ms)
        self._tooltip_timer.timeout.connect(self._show_delayed_tooltip)
        self.setMinimumWidth(0)
        self.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Fixed)
        self.setText(text)

    def setText(self, text: str) -> None:  # type: ignore[override]
        self._full_text = text
        self._update_elided_text()

    def full_text(self) -> str:
        return self._full_text

    def is_elided(self) -> bool:
        return self._is_elided

    def resizeEvent(self, event) -> None:  # type: ignore[override]
        super().resizeEvent(event)
        self._update_elided_text()

    def enterEvent(self, event) -> None:  # type: ignore[override]
        super().enterEvent(event)
        if self._is_elided:
            self._tooltip_timer.start()

    def leaveEvent(self, event) -> None:  # type: ignore[override]
        self._tooltip_timer.stop()
        QToolTip.hideText()
        super().leaveEvent(event)

    def _update_elided_text(self) -> None:
        metrics = QFontMetrics(self.font())
        available_width = max(0, self.width() - 2)
        if available_width <= 0:
            QLabel.setText(self, self._full_text)
            self._is_elided = False
            return
        visible_text = metrics.elidedText(self._full_text, Qt.TextElideMode.ElideRight, available_width)
        self._is_elided = visible_text != self._full_text
        QLabel.setText(self, visible_text)

    def _show_delayed_tooltip(self) -> None:
        if not self._is_elided or not self.underMouse():
            return
        position = self.mapToGlobal(QPoint(0, self.height() + 4))
        QToolTip.showText(position, self._full_text, self)


class ExternalLinkLabel(ElidedLabel):
    def __init__(self, text: str = "—", parent: QWidget | None = None, *, tooltip_delay_ms: int = 500) -> None:
        super().__init__(text, parent, tooltip_delay_ms=tooltip_delay_ms)
        self._url = ""
        self.setCursor(Qt.CursorShape.ArrowCursor)

    def set_link(self, url: str) -> None:
        self._url = url.strip()
        self.setText(self._url)
        self.setToolTip(self._url)
        self.setCursor(Qt.CursorShape.PointingHandCursor if self._url else Qt.CursorShape.ArrowCursor)
        self.setStyleSheet("color: #1677ff; text-decoration: underline; font-weight: 650;")

    def set_plain_text(self, text: str, tooltip: str = "") -> None:
        self._url = ""
        self.setText(text)
        self.setToolTip(tooltip)
        self.setCursor(Qt.CursorShape.ArrowCursor)
        self.setStyleSheet("")

    def url(self) -> str:
        return self._url

    def mouseReleaseEvent(self, event) -> None:  # type: ignore[override]
        if event.button() == Qt.MouseButton.LeftButton and self._url:
            QDesktopServices.openUrl(QUrl(self._url))
            event.accept()
            return
        super().mouseReleaseEvent(event)


class ToggleSwitch(QCheckBox):
    def __init__(self, text: str = "", parent: QWidget | None = None) -> None:
        super().__init__(text, parent)
        self.setCursor(Qt.CursorShape.PointingHandCursor)
        self.setMinimumHeight(21)
        self._switch_position = 1.0 if self.isChecked() else 0.0
        self._switch_animation: QPropertyAnimation | None = None
        self.stateChanged.connect(self._animate_state_change)

    def setChecked(self, checked: bool) -> None:  # type: ignore[override]
        changed = checked != self.isChecked()
        super().setChecked(checked)
        if self.signalsBlocked() or not changed:
            self._set_switch_position(1.0 if checked else 0.0)

    def _get_switch_position(self) -> float:
        return self._switch_position

    def _set_switch_position(self, value: float) -> None:
        self._switch_position = max(0.0, min(1.0, float(value)))
        self.update()

    switchPosition = Property(float, _get_switch_position, _set_switch_position)

    def _animate_state_change(self) -> None:
        target = 1.0 if self.isChecked() else 0.0
        if self._switch_animation is not None:
            self._switch_animation.stop()
        animation = QPropertyAnimation(self, b"switchPosition", self)
        animation.setStartValue(self._switch_position)
        animation.setEndValue(target)
        animation.setDuration(150)
        animation.setEasingCurve(QEasingCurve.Type.OutCubic)
        self._switch_animation = animation
        animation.start()

    def sizeHint(self) -> QSize:  # type: ignore[override]
        metrics = QFontMetrics(self.font())
        width = 34
        if self.text():
            width += 7 + metrics.horizontalAdvance(self.text())
        return QSize(width, 21)

    def hitButton(self, pos) -> bool:  # type: ignore[override]
        return self.rect().contains(pos)

    @staticmethod
    def _mix_color(start: QColor, end: QColor, ratio: float) -> QColor:
        ratio = max(0.0, min(1.0, ratio))
        return QColor(
            round(start.red() + (end.red() - start.red()) * ratio),
            round(start.green() + (end.green() - start.green()) * ratio),
            round(start.blue() + (end.blue() - start.blue()) * ratio),
        )

    def paintEvent(self, event) -> None:  # type: ignore[override]
        del event
        painter = QPainter(self)
        painter.setRenderHint(QPainter.RenderHint.Antialiasing)
        painter.setRenderHint(QPainter.RenderHint.TextAntialiasing)

        track_width = 34
        track_height = 19
        track_x = 0
        track_y = (self.height() - track_height) / 2
        track_rect = QRectF(track_x, track_y, track_width, track_height)
        off_color = QColor("#d8e2ef")
        on_color = QColor("#34c759")
        track_color = self._mix_color(off_color, on_color, self._switch_position)
        if not self.isEnabled():
            track_color = QColor("#eef2f7")
        painter.setPen(Qt.PenStyle.NoPen)
        painter.setBrush(track_color)
        painter.drawRoundedRect(track_rect, track_height / 2, track_height / 2)

        knob_size = 15
        knob_margin = 2
        knob_x = track_x + knob_margin + (track_width - knob_size - knob_margin * 2) * self._switch_position
        knob_rect = QRectF(knob_x, track_y + knob_margin, knob_size, knob_size)
        painter.setBrush(QColor("#ffffff"))
        painter.drawEllipse(knob_rect)

        if self.text():
            painter.setPen(QColor("#24304f" if self.isEnabled() else "#9aa6bb"))
            text_rect = self.rect().adjusted(track_width + 7, 0, 0, 0)
            painter.drawText(text_rect, Qt.AlignmentFlag.AlignVCenter | Qt.AlignmentFlag.AlignLeft, self.text())
        painter.end()


class NonScrollingComboBox(QComboBox):
    def wheelEvent(self, event) -> None:  # type: ignore[override]
        event.ignore()


class PageScrollArea(QScrollArea):
    def __init__(self, parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self.setObjectName("pageScrollArea")
        self.setFrameShape(QFrame.Shape.NoFrame)
        self.setAttribute(Qt.WidgetAttribute.WA_TranslucentBackground, True)
        self.viewport().setObjectName("pageScrollViewport")
        self.viewport().setAttribute(Qt.WidgetAttribute.WA_TranslucentBackground, True)
        self.viewport().setAutoFillBackground(False)

    def setWidget(self, widget: QWidget | None) -> None:  # type: ignore[override]
        super().setWidget(widget)
        self.viewport().installEventFilter(self)
        if widget is not None:
            widget.setAttribute(Qt.WidgetAttribute.WA_TranslucentBackground, True)
            widget.setAutoFillBackground(False)
            self._install_wheel_forwarding(widget)

    def _install_wheel_forwarding(self, widget: QWidget) -> None:
        widget.installEventFilter(self)
        for child in widget.findChildren(QWidget):
            if isinstance(child, QScrollArea):
                continue
            child.installEventFilter(self)

    def showEvent(self, event) -> None:  # type: ignore[override]
        widget = self.widget()
        if widget is not None:
            self._install_wheel_forwarding(widget)
        super().showEvent(event)

    def eventFilter(self, watched, event) -> bool:  # type: ignore[override]
        if event.type() != QEvent.Type.Wheel:
            return super().eventFilter(watched, event)
        if isinstance(watched, QWidget) and self._is_inside_nested_scroll(watched):
            return super().eventFilter(watched, event)
        delta = event.pixelDelta().y() if hasattr(event, "pixelDelta") and not event.pixelDelta().isNull() else event.angleDelta().y()
        if delta == 0:
            return super().eventFilter(watched, event)
        bar = self.verticalScrollBar()
        bar.setValue(bar.value() - delta)
        event.accept()
        return True

    def _is_inside_nested_scroll(self, widget: QWidget) -> bool:
        parent = widget.parentWidget()
        while parent is not None:
            if parent is self:
                return False
            if isinstance(parent, QScrollArea):
                return True
            parent = parent.parentWidget()
        return False


class ContainedScrollArea(QScrollArea):
    def wheelEvent(self, event) -> None:  # type: ignore[override]
        delta = event.pixelDelta().y() if hasattr(event, "pixelDelta") and not event.pixelDelta().isNull() else event.angleDelta().y()
        if delta:
            bar = self.verticalScrollBar()
            bar.setValue(bar.value() - delta)
        event.accept()



class HoverAnimatedButton(QPushButton):
    def __init__(self, text: str = "", parent: QWidget | None = None) -> None:
        super().__init__(text, parent)
        self._hover_progress = 0.0
        self._hover_animation: QPropertyAnimation | None = None
        self._hover_shadow: QGraphicsDropShadowEffect | None = None

    def _get_hover_progress(self) -> float:
        return self._hover_progress

    def _set_hover_progress(self, value: float) -> None:
        self._hover_progress = max(0.0, min(1.0, float(value)))
        if self._hover_shadow is None:
            return
        alpha = round(42 * self._hover_progress)
        self._hover_shadow.setColor(QColor(31, 122, 255, alpha))
        self._hover_shadow.setBlurRadius(4 + 12 * self._hover_progress)
        self._hover_shadow.setOffset(0, 1 + 2 * self._hover_progress)

    hoverProgress = Property(float, _get_hover_progress, _set_hover_progress)

    def _animate_hover(self, target: float) -> None:
        if self._hover_shadow is None:
            self._hover_progress = target
            return
        if self._hover_animation is not None:
            self._hover_animation.stop()
        animation = QPropertyAnimation(self, b"hoverProgress", self)
        animation.setStartValue(self._hover_progress)
        animation.setEndValue(target)
        animation.setDuration(150)
        animation.setEasingCurve(QEasingCurve.Type.OutCubic)
        self._hover_animation = animation
        animation.start()

    def enterEvent(self, event) -> None:  # type: ignore[override]
        self._animate_hover(1.0)
        super().enterEvent(event)

    def leaveEvent(self, event) -> None:  # type: ignore[override]
        self._animate_hover(0.0)
        super().leaveEvent(event)


class NavButton(HoverAnimatedButton):
    def __init__(self, text: str, icon: str | Path = "", parent: QWidget | None = None) -> None:
        super().__init__(text, parent)
        self._icon_path = icon if isinstance(icon, Path) else None
        if self._icon_path is not None:
            self.setIcon(tinted_icon_from_path(self._icon_path, "#52617e", 17))
            self.setIconSize(QSize(17, 17))
        elif icon:
            self.setText(f"{icon}  {text}")
        self.setProperty("nav", True)
        self.setCursor(Qt.CursorShape.PointingHandCursor)

    def set_selected(self, selected: bool) -> None:
        self.setProperty("selected", selected)
        if self._icon_path is not None:
            self.setIcon(tinted_icon_from_path(self._icon_path, "#0d67e9" if selected else "#52617e", 17))
        self.style().unpolish(self)
        self.style().polish(self)


class ActionButton(HoverAnimatedButton):
    def __init__(
        self,
        text: str,
        role: str = "",
        parent: QWidget | None = None,
        icon: Path | None = None,
        size: str = "m",
    ) -> None:
        super().__init__(text, parent)
        if role:
            self.setProperty("role", role)
        self.setProperty("buttonSize", size)
        if icon is not None:
            color = "#ffffff" if role in {"primary", "danger"} else "#1677ff"
            self.setIcon(tinted_icon_from_path(icon, color, 15))
            self.setIconSize(QSize(15, 15))
        self.setCursor(Qt.CursorShape.PointingHandCursor)


class HotkeyButton(ActionButton):
    hotkeyChanged = Signal(str)
    captureStateChanged = Signal(bool)

    _KEY_NAMES = {
        int(Qt.Key.Key_Tab): "tab",
        int(Qt.Key.Key_Backspace): "backspace",
        int(Qt.Key.Key_Return): "enter",
        int(Qt.Key.Key_Enter): "enter",
        int(Qt.Key.Key_Space): "space",
    }
    _MODIFIER_KEYS = {
        int(Qt.Key.Key_Shift),
        int(Qt.Key.Key_Control),
        int(Qt.Key.Key_Alt),
        int(Qt.Key.Key_Meta),
    }

    def __init__(self, hotkey: str = "", parent: QWidget | None = None) -> None:
        super().__init__("", parent=parent, size="s")
        self._hotkey = ""
        self._capture_active = False
        self.clicked.connect(self._start_capture)
        self.setFocusPolicy(Qt.FocusPolicy.StrongFocus)
        self.set_hotkey(hotkey)

    def hotkey(self) -> str:
        return self._hotkey

    def set_hotkey(self, hotkey: str) -> None:
        was_active = self._capture_active
        self._capture_active = False
        self._hotkey = self._normalize_hotkey(hotkey)
        self.setText(self._display_hotkey(self._hotkey))
        if was_active:
            self.captureStateChanged.emit(False)

    def is_capture_active(self) -> bool:
        return self._capture_active

    def _start_capture(self) -> None:
        if not self._capture_active:
            self._capture_active = True
            self.captureStateChanged.emit(True)
        self.setText("Нажмите сочетание…")
        self.setFocus(Qt.FocusReason.MouseFocusReason)

    def _cancel_capture(self) -> None:
        if not self._capture_active:
            return
        self._capture_active = False
        self.setText(self._display_hotkey(self._hotkey))
        self.captureStateChanged.emit(False)

    def keyPressEvent(self, event) -> None:  # type: ignore[override]
        if not self._capture_active:
            super().keyPressEvent(event)
            return
        key = int(event.key())
        if key == int(Qt.Key.Key_Escape):
            self._cancel_capture()
            event.accept()
            return
        if key in self._MODIFIER_KEYS:
            event.accept()
            return
        hotkey = self._hotkey_from_key_event(key, event.text(), event.modifiers())
        if not hotkey:
            event.accept()
            return
        self.set_hotkey(hotkey)
        self.hotkeyChanged.emit(self._hotkey)
        event.accept()

    def focusOutEvent(self, event) -> None:  # type: ignore[override]
        self._cancel_capture()
        super().focusOutEvent(event)

    @classmethod
    def _hotkey_from_key_event(cls, key: int, text: str, modifiers: Qt.KeyboardModifier | Qt.KeyboardModifiers = Qt.KeyboardModifier.NoModifier) -> str:
        base = cls._key_name_from_key_event(key, text)
        if not base:
            return ""
        modifier_names: list[str] = []
        if modifiers & Qt.KeyboardModifier.ControlModifier:
            modifier_names.append("ctrl")
        if modifiers & Qt.KeyboardModifier.AltModifier:
            modifier_names.append("alt")
        if modifiers & Qt.KeyboardModifier.ShiftModifier:
            modifier_names.append("shift")
        return "+".join([*modifier_names, base])

    @classmethod
    def _key_name_from_key_event(cls, key: int, text: str) -> str:
        if int(Qt.Key.Key_F1) <= key <= int(Qt.Key.Key_F24):
            return f"F{key - int(Qt.Key.Key_F1) + 1}"
        if key in cls._KEY_NAMES:
            return cls._KEY_NAMES[key]
        if text and len(text) == 1 and text.isalnum():
            return text.lower()
        return ""

    @staticmethod
    def _normalize_hotkey(hotkey: str) -> str:
        value = hotkey.strip()
        if not value:
            return ""
        parts = [part.strip().lower() for part in value.replace(" ", "").split("+") if part.strip()]
        if not parts:
            return ""
        normalized: list[str] = []
        for part in parts:
            if part in {"control", "ctrl"}:
                normalized.append("ctrl")
            elif part == "alt":
                normalized.append("alt")
            elif part == "shift":
                normalized.append("shift")
            elif part.startswith("f") and part[1:].isdigit():
                normalized.append(part.upper())
            elif len(part) == 1 and part.isalnum():
                normalized.append(part.lower())
            else:
                normalized.append(part)
        return "+".join(normalized)

    @staticmethod
    def _display_hotkey(hotkey: str) -> str:
        if not hotkey:
            return "Не задано"
        labels = []
        for part in hotkey.split("+"):
            if part == "ctrl":
                labels.append("Ctrl")
            elif part == "alt":
                labels.append("Alt")
            elif part == "shift":
                labels.append("Shift")
            else:
                labels.append(part.upper() if len(part) == 1 else part)
        return " + ".join(labels)


def icon_widget(icon: str | Path, size: int = 28, fallback_style: str = "font-size: 22px; color: #1677ff;", color: str = "#1677ff") -> QWidget:
    if isinstance(icon, Path) and icon.suffix.lower() == ".svg":
        return SvgIcon(icon, size, color)
    label = QLabel()
    label.setFixedSize(size, size)
    label.setAlignment(Qt.AlignmentFlag.AlignCenter)
    if isinstance(icon, Path):
        pixmap = load_pixmap(icon, size)
        if not pixmap.isNull():
            label.setPixmap(pixmap)
        else:
            label.setText("◌")
            label.setStyleSheet(fallback_style)
    else:
        label.setText(icon)
        label.setStyleSheet(fallback_style)
    return label


class MetricCard(Card):
    def __init__(self, label: str, value: str = "—", icon: str | Path = "", parent: QWidget | None = None) -> None:
        super().__init__(parent, soft=True)
        layout = QVBoxLayout(self)
        layout.setContentsMargins(10, 8, 10, 8)
        layout.setSpacing(5)
        self.value_label = QLabel(value)
        self.value_label.setProperty("metricValue", True)
        self.value_label.setMinimumWidth(0)
        self.value_label.setWordWrap(True)
        layout.addWidget(self.value_label)
        label_row = QHBoxLayout()
        label_row.setContentsMargins(0, 0, 0, 0)
        label_row.setSpacing(6)
        if icon:
            label_row.addWidget(icon_widget(icon, 17), 0, Qt.AlignmentFlag.AlignVCenter)
        self.label_label = QLabel(label)
        self.label_label.setProperty("metricLabel", True)
        self.label_label.setWordWrap(True)
        label_row.addWidget(self.label_label, 1)
        layout.addLayout(label_row)

    def set_value(self, value: str) -> None:
        if self.value_label.text() == value:
            return
        self.value_label.setText(value)
        length = len(value)
        if length > 22:
            size = 12
        elif length > 16:
            size = 14
        elif length > 12:
            size = 16
        else:
            size = 18
        self.value_label.setStyleSheet(f"font-size: {size}px; font-weight: 800; color: #14203d;")


class SettingCard(Card):
    def __init__(self, title: str, subtitle: str = "", icon: str | Path = "", parent: QWidget | None = None) -> None:
        super().__init__(parent, soft=True)
        self.root_layout = QVBoxLayout(self)
        self.root_layout.setContentsMargins(10, 8, 10, 8)
        self.root_layout.setSpacing(7)
        top = QHBoxLayout()
        top.setSpacing(7)
        if icon:
            top.addWidget(icon_widget(icon, 20, "font-size: 17px; color: #1677ff;"))
        text_layout = QVBoxLayout()
        text_layout.setContentsMargins(0, 0, 0, 0)
        text_layout.setSpacing(2)
        title_label = QLabel(title)
        title_label.setProperty("sectionTitle", True)
        title_label.setWordWrap(True)
        text_layout.addWidget(title_label)
        if subtitle:
            subtitle_label = QLabel(subtitle)
            subtitle_label.setProperty("muted", True)
            subtitle_label.setWordWrap(True)
            text_layout.addWidget(subtitle_label)
        top.addLayout(text_layout, 1)
        self.root_layout.addLayout(top)

    def add_widget(self, widget: QWidget) -> None:
        self.root_layout.addWidget(widget)

    def add_layout(self, layout) -> None:
        self.root_layout.addLayout(layout)


class IconLabel(QLabel):
    def __init__(self, path: Path, size: int = 42, parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self.setFixedSize(size, size)
        self.setAlignment(Qt.AlignmentFlag.AlignCenter)
        pixmap = icon_from_path(path).pixmap(size, size)
        if not pixmap.isNull():
            self.setPixmap(pixmap)
        else:
            fallback = load_pixmap(path, size)
            if not fallback.isNull():
                self.setPixmap(fallback)
            else:
                self.setText("◌")


def icon_from_path(path: Path) -> QIcon:
    return QIcon(str(path)) if path.exists() else QIcon()
