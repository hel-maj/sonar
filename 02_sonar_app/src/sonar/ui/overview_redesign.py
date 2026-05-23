from __future__ import annotations

import base64
from pathlib import Path
from typing import Callable

from PySide6.QtCore import QRectF, Qt
from PySide6.QtGui import QColor, QPainter, QPainterPath, QPixmap
from PySide6.QtWidgets import QFrame, QGraphicsDropShadowEffect, QGridLayout, QHBoxLayout, QLabel, QSizePolicy, QVBoxLayout, QWidget

from sonar.paths import RESOURCE_DIR
from sonar.ui import widgets
from sonar.ui.widgets import ActionButton, Badge, Card, IconLabel, SectionHeader, icon_widget


UI_ICON_DIR = RESOURCE_DIR / 'ui_icons'


def ui_icon(name: str) -> Path:
    return UI_ICON_DIR / name


class GamePreviewFrame(QFrame):
    def __init__(self, parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self.setObjectName('overviewGamePreview')
        self.setFixedSize(284, 228)
        self._pixmap = self._load_preview()
        self.setAttribute(Qt.WidgetAttribute.WA_StyledBackground, True)

    @staticmethod
    def _load_preview() -> QPixmap:
        try:
            from sonar.ui.overview_preview import PREVIEW_JPEG_BASE64
        except Exception:
            return QPixmap()
        data = base64.b64decode(PREVIEW_JPEG_BASE64)
        pixmap = QPixmap()
        pixmap.loadFromData(data, 'JPG')
        return pixmap

    def paintEvent(self, event) -> None:  # type: ignore[override]
        super().paintEvent(event)
        painter = QPainter(self)
        painter.setRenderHint(QPainter.RenderHint.Antialiasing)
        path = QPainterPath()
        path.addRoundedRect(QRectF(self.rect()), 12, 12)
        painter.setClipPath(path)
        if self._pixmap.isNull():
            painter.fillRect(self.rect(), QColor('#dce8f7'))
            painter.end()
            return
        scaled = self._pixmap.scaled(self.size(), Qt.AspectRatioMode.KeepAspectRatioByExpanding, Qt.TransformationMode.SmoothTransformation)
        x = (self.width() - scaled.width()) // 2
        y = (self.height() - scaled.height()) // 2
        painter.drawPixmap(x, y, scaled)
        painter.end()


class OverviewMetric(QFrame):
    def __init__(self, label: str, value: str, icon: Path, color: str = '#1f7aff', parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self.setObjectName('overviewMetric')
        self.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Fixed)
        self.setMinimumHeight(64)
        layout = QHBoxLayout(self)
        layout.setContentsMargins(14, 8, 14, 8)
        layout.setSpacing(10)
        layout.addWidget(icon_widget(icon, 26, color=color), 0, Qt.AlignmentFlag.AlignVCenter)
        text_layout = QVBoxLayout()
        text_layout.setContentsMargins(0, 0, 0, 0)
        text_layout.setSpacing(1)
        self.value_label = QLabel(value)
        self.value_label.setObjectName('overviewMetricValue')
        self.label_label = QLabel(label)
        self.label_label.setObjectName('overviewMetricLabel')
        text_layout.addWidget(self.value_label)
        text_layout.addWidget(self.label_label)
        layout.addLayout(text_layout, 1)

    def set_value(self, value: str) -> None:
        self.value_label.setText(value)
        length = len(value)
        if length > 22:
            size = 15
        elif length > 16:
            size = 17
        elif length > 12:
            size = 20
        else:
            size = 22
        self.value_label.setStyleSheet(f'font-size: {size}px; font-weight: 850; color: #14203d;')


class InfoPill(QFrame):
    def __init__(self, label: str, value: str, tone: str = 'green', parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self.setObjectName('overviewInfoPill')
        layout = QVBoxLayout(self)
        layout.setContentsMargins(12, 8, 12, 8)
        layout.setSpacing(2)
        caption = QLabel(label)
        caption.setObjectName('overviewPillCaption')
        self.value_label = QLabel(value)
        self.value_label.setObjectName('overviewPillValue')
        self.set_tone(tone)
        layout.addWidget(caption)
        layout.addWidget(self.value_label)

    def set_value(self, value: str, tone: str = 'green') -> None:
        self.value_label.setText(value)
        self.set_tone(tone)

    def set_tone(self, tone: str) -> None:
        self.setProperty('tone', tone)
        self.style().unpolish(self)
        self.style().polish(self)


def _shadow(widget: QWidget, blur: int = 28, y: int = 10, alpha: int = 28) -> None:
    effect = QGraphicsDropShadowEffect(widget)
    effect.setBlurRadius(blur)
    effect.setOffset(0, y)
    effect.setColor(QColor(46, 74, 126, alpha))
    widget.setGraphicsEffect(effect)


def _status_badge(text: str, tone: str = 'green') -> Badge:
    badge = Badge(text, tone)
    badge.setObjectName('overviewStatusBadge')
    return badge


def _build_overview_tab(self) -> QWidget:
    page = QWidget()
    layout = QVBoxLayout(page)
    layout.setContentsMargins(0, 0, 0, 0)
    layout.setSpacing(14)
    layout.addWidget(SectionHeader('Обзор', 'Главный экран управления рыбалкой, стримом и уведомлениями.'))

    top = QHBoxLayout()
    top.setSpacing(16)
    top.addWidget(_build_overview_fishing_control_card(self), 3)
    top.addWidget(_build_overview_system_state_card(self), 2)
    layout.addLayout(top)

    session_card = Card()
    session_card.setObjectName('overviewSessionCard')
    _shadow(session_card, blur=22, y=8, alpha=20)
    session_layout = QVBoxLayout(session_card)
    session_layout.setContentsMargins(18, 14, 18, 14)
    session_layout.setSpacing(10)
    title = QLabel('Текущая сессия')
    title.setProperty('sectionTitle', True)
    session_layout.addWidget(title)
    metrics = QHBoxLayout()
    metrics.setSpacing(0)
    self.overview_duration_metric = OverviewMetric('Время', '00:00', ui_icon('clock.svg'))
    self.overview_caught_metric = OverviewMetric('Поймано', '0', ui_icon('fish_solid.svg'))
    self.overview_released_metric = OverviewMetric('Отпущено', '0', ui_icon('fish.svg'))
    self.overview_income_metric = OverviewMetric('Доход', '0 $', ui_icon('dollar.svg'), '#ff9f0a')
    self.overview_income_hour_metric = OverviewMetric('Доход / час', '0 $', ui_icon('profit.svg'), '#28b957')
    for index, widget in enumerate((
        self.overview_duration_metric,
        self.overview_caught_metric,
        self.overview_released_metric,
        self.overview_income_metric,
        self.overview_income_hour_metric,
    )):
        metrics.addWidget(widget)
        if index < 4:
            divider = QFrame()
            divider.setObjectName('overviewMetricDivider')
            metrics.addWidget(divider)
    session_layout.addLayout(metrics)
    layout.addWidget(session_card)

    bottom = QHBoxLayout()
    bottom.setSpacing(16)
    bottom.addWidget(_build_overview_small_status_card(self, 'Telegram', 'Бот и уведомления', ui_icon('telegram_color.svg'), self._select_telegram_page), 1)
    bottom.addWidget(_build_overview_small_status_card(self, 'Стрим', 'Трансляция и чат', ui_icon('stream.svg'), self._select_stream_page), 1)
    bottom.addWidget(self._build_recent_events_card(), 2)
    layout.addLayout(bottom, 1)
    return page


def _build_overview_fishing_control_card(self) -> QWidget:
    card = Card()
    card.setObjectName('overviewFishingCard')
    _shadow(card)
    layout = QVBoxLayout(card)
    layout.setContentsMargins(18, 18, 18, 18)
    layout.setSpacing(16)

    top = QHBoxLayout()
    top.setSpacing(18)
    left = QVBoxLayout()
    left.setContentsMargins(0, 0, 0, 0)
    left.setSpacing(12)
    title_row = QHBoxLayout()
    title = QLabel('Рыбалка')
    title.setProperty('title', True)
    ready_badge = _status_badge('Готов к работе', 'green')
    self._ready_badges.append(ready_badge)
    title_row.addWidget(title)
    title_row.addWidget(ready_badge)
    title_row.addStretch(1)
    left.addLayout(title_row)

    state_caption = QLabel('Состояние')
    state_caption.setProperty('muted', True)
    left.addWidget(state_caption)
    status_label = QLabel('Ожидание')
    status_label.setObjectName('overviewFishingStatus')
    status_description_label = QLabel('Ожидание команды для начала рыбалки')
    status_description_label.setProperty('muted', True)
    self._status_labels.append(status_label)
    self._status_description_labels.append(status_description_label)
    self.status_label = status_label
    left.addWidget(status_label)
    left.addWidget(status_description_label)

    hotkey_row = QHBoxLayout()
    hotkey_row.setSpacing(8)
    hotkey_card = Card(soft=True)
    hotkey_card.setObjectName('overviewHotkeyCard')
    hotkey_layout = QHBoxLayout(hotkey_card)
    hotkey_layout.setContentsMargins(12, 9, 12, 9)
    hotkey_layout.setSpacing(8)
    hotkey_title = QLabel('Горячая клавиша')
    hotkey_title.setProperty('muted', True)
    main_hotkey_label = Badge('F9', 'blue')
    main_hotkey_label.setObjectName('overviewHotkeyBadge')
    self._hotkey_badges.append(main_hotkey_label)
    hotkey_layout.addWidget(main_hotkey_label)
    hotkey_layout.addWidget(hotkey_title)
    hotkey_layout.addWidget(QLabel('Старт / Стоп'))
    hotkey_row.addWidget(hotkey_card)
    hotkey_row.addStretch(1)
    left.addLayout(hotkey_row)
    left.addStretch(1)
    top.addLayout(left, 1)
    top.addWidget(GamePreviewFrame(), 0, Qt.AlignmentFlag.AlignTop)
    layout.addLayout(top)

    buttons = QHBoxLayout()
    buttons.setSpacing(18)
    start_button = ActionButton('Запустить', 'primary', icon=ui_icon('play_white.svg'), size='xl')
    stop_button = ActionButton('Остановить', 'danger', icon=ui_icon('stop_white.svg'), size='xl')
    start_button.clicked.connect(self.start_bot)
    stop_button.clicked.connect(self.stop_bot)
    self._start_buttons.append(start_button)
    self._stop_buttons.append(stop_button)
    self.start_button = start_button
    self.stop_button = stop_button
    buttons.addWidget(start_button)
    buttons.addWidget(stop_button)
    layout.addLayout(buttons)
    return card


def _build_overview_system_state_card(self) -> QWidget:
    card = Card()
    card.setObjectName('overviewSystemCard')
    _shadow(card)
    layout = QVBoxLayout(card)
    layout.setContentsMargins(16, 16, 16, 16)
    layout.setSpacing(12)
    title = QLabel('Состояние системы')
    title.setProperty('sectionTitle', True)
    layout.addWidget(title)
    grid = QGridLayout()
    grid.setHorizontalSpacing(10)
    grid.setVerticalSpacing(10)
    self.game_state_tile = _overview_status_tile(self, 'Игра', 'Не проверялась', 'Majestic RP', ui_icon('monitor.svg'))
    self.tackle_bait_tile = _overview_status_tile(self, 'Наживка', 'Не сканировалась', '', ui_icon('bait.png'))
    self.tackle_leader_tile = _overview_status_tile(self, 'Поводок', 'Не сканировался', '', ui_icon('leader.png'))
    self.tackle_net_tile = _overview_status_tile(self, 'Подсак', 'Не сканировался', '', ui_icon('landing_net.png'))
    self._system_tiles['game'].append(self.game_state_tile)
    self._system_tiles['bait'].append(self.tackle_bait_tile)
    self._system_tiles['leader'].append(self.tackle_leader_tile)
    self._system_tiles['net'].append(self.tackle_net_tile)
    grid.addWidget(self.game_state_tile, 0, 0)
    grid.addWidget(self.tackle_bait_tile, 0, 1)
    grid.addWidget(self.tackle_leader_tile, 1, 0)
    grid.addWidget(self.tackle_net_tile, 1, 1)
    layout.addLayout(grid)

    license_row = Card(soft=True)
    license_row.setObjectName('overviewLicenseRow')
    license_layout = QHBoxLayout(license_row)
    license_layout.setContentsMargins(12, 10, 12, 10)
    license_layout.setSpacing(10)
    license_layout.addWidget(icon_widget(ui_icon('shield_check.svg'), 28, color='#23a75a'))
    license_text = QLabel('Лицензия: проверяем статус')
    license_text.setProperty('muted', True)
    self._license_overview_lines.append(license_text)
    license_layout.addWidget(license_text, 1)
    license_button = ActionButton('Управление', size='xs')
    license_button.clicked.connect(lambda: self._select_page(self.license_tab))
    license_layout.addWidget(license_button)
    layout.addWidget(license_row)
    return card


def _overview_status_tile(self, title: str, value: str, subtitle: str, icon: str | Path) -> QWidget:
    tile = Card(soft=True)
    tile.setObjectName('overviewStatusTile')
    tile.setMinimumHeight(74)
    tile.setSizePolicy(QSizePolicy.Policy.Preferred, QSizePolicy.Policy.Fixed)
    layout = QHBoxLayout(tile)
    layout.setContentsMargins(12, 10, 10, 10)
    layout.setSpacing(10)
    layout.addWidget(icon_widget(icon, 34, color='#1f7aff'), 0, Qt.AlignmentFlag.AlignVCenter)
    texts = QVBoxLayout()
    texts.setContentsMargins(0, 0, 0, 0)
    texts.setSpacing(1)
    title_label = QLabel(title)
    title_label.setProperty('muted', True)
    value_label = QLabel(value)
    value_label.setObjectName('overviewStatusValue')
    subtitle_label = QLabel(subtitle or ' ')
    subtitle_label.setProperty('muted', True)
    subtitle_label.setMinimumHeight(16)
    texts.addWidget(title_label)
    texts.addWidget(value_label)
    texts.addWidget(subtitle_label)
    layout.addLayout(texts, 1)
    dot = QLabel('●')
    dot.setObjectName('overviewStatusDot')
    dot.setFixedSize(16, 16)
    dot.setAlignment(Qt.AlignmentFlag.AlignCenter)
    dot.setStyleSheet('color: #ff4d4f; font-size: 13px;')
    layout.addWidget(dot, 0, Qt.AlignmentFlag.AlignTop | Qt.AlignmentFlag.AlignRight)
    tile.value_label = value_label
    tile.subtitle_label = subtitle_label
    tile.dot_label = dot
    return tile


def _build_overview_small_status_card(self, title: str, subtitle: str, icon: str | Path, callback: Callable[[], None]) -> QWidget:
    card = Card()
    card.setObjectName('overviewSmallCard')
    _shadow(card, blur=20, y=8, alpha=18)
    layout = QVBoxLayout(card)
    layout.setContentsMargins(18, 16, 18, 16)
    layout.setSpacing(12)
    row = QHBoxLayout()
    row.setSpacing(10)
    if isinstance(icon, Path):
        row.addWidget(IconLabel(icon, 28))
    else:
        icon_label = QLabel(icon)
        icon_label.setStyleSheet('font-size: 24px; color: #1677ff;')
        row.addWidget(icon_label)
    title_label = QLabel(title)
    title_label.setProperty('sectionTitle', True)
    row.addWidget(title_label, 1)
    badge = _status_badge('—', 'gray')
    row.addWidget(badge)
    layout.addLayout(row)
    subtitle_label = QLabel(subtitle)
    subtitle_label.setProperty('muted', True)
    layout.addWidget(subtitle_label)

    if title == 'Telegram':
        self.overview_telegram_status = InfoPill('Статус', 'Не настроен', 'gray')
        self.overview_telegram_notify = InfoPill('Уведомления', 'По настройкам', 'blue')
        self.overview_telegram_badge = badge
        layout.addWidget(self.overview_telegram_status)
        layout.addWidget(self.overview_telegram_notify)
    elif title == 'Стрим':
        self.overview_stream_status = InfoPill('Статус', 'Офлайн', 'gray')
        self.overview_stream_quality = InfoPill('Качество', '720p', 'blue')
        self.overview_stream_badge = badge
        layout.addWidget(self.overview_stream_status)
        layout.addWidget(self.overview_stream_quality)
    layout.addStretch(1)
    button = ActionButton('Настроить', icon=ui_icon('settings.svg'))
    button.clicked.connect(callback)
    layout.addWidget(button)
    return card


def _set_status_tiles(self, key: str, value: str, subtitle: str, ok: bool) -> None:
    for tile in self._system_tiles.get(key, []):
        tile.value_label.setText(value)
        tile.subtitle_label.setText(subtitle or ' ')
        tile.dot_label.setStyleSheet(f"color: {'#31c65b' if ok else '#ff4d4f'}; font-size: 13px;")


def _patch_telegram(original):
    def wrapped(self, telegram) -> None:
        original(self, telegram)
        if not hasattr(self, 'overview_telegram_status'):
            return
        if telegram.enabled and telegram.bot_token.strip() and telegram.admin_ids:
            self.overview_telegram_status.set_value('Подключен', 'green')
            self.overview_telegram_badge.setText('Подключен')
            self.overview_telegram_badge.set_tone('green')
        elif telegram.enabled:
            self.overview_telegram_status.set_value('Нужна настройка', 'yellow')
            self.overview_telegram_badge.setText('Настроить')
            self.overview_telegram_badge.set_tone('gray')
        else:
            self.overview_telegram_status.set_value('Отключен', 'gray')
            self.overview_telegram_badge.setText('Отключен')
            self.overview_telegram_badge.set_tone('gray')
        enabled = []
        if telegram.notify_catch:
            enabled.append('улов')
        if telegram.notify_start_stop:
            enabled.append('старт/стоп')
        if telegram.notify_inventory_full:
            enabled.append('место')
        text = ', '.join(enabled[:2]) if enabled else 'выключены'
        if len(enabled) > 2:
            text = f'{text} +{len(enabled) - 2}'
        self.overview_telegram_notify.set_value(text, 'blue' if enabled else 'gray')
    return wrapped


def _patch_stream(original):
    def wrapped(self) -> None:
        original(self)
        if not hasattr(self, 'overview_stream_status'):
            return
        snapshot = self.stream_service.snapshot()
        if snapshot.active:
            self.overview_stream_status.set_value('Онлайн', 'green')
            self.overview_stream_badge.setText('Активен')
            self.overview_stream_badge.set_tone('green')
        elif snapshot.status in {'starting', 'preparing'}:
            self.overview_stream_status.set_value('Запускается', 'yellow')
            self.overview_stream_badge.setText('Запуск')
            self.overview_stream_badge.set_tone('blue')
        elif snapshot.error:
            self.overview_stream_status.set_value('Ошибка', 'red')
            self.overview_stream_badge.setText('Ошибка')
            self.overview_stream_badge.set_tone('red')
        else:
            self.overview_stream_status.set_value('Офлайн', 'gray')
            self.overview_stream_badge.setText('Офлайн')
            self.overview_stream_badge.set_tone('gray')
        fps = '10fps' if snapshot.snapshot_mode_enabled else '30fps'
        self.overview_stream_quality.set_value(f'{snapshot.quality} · {fps}', 'blue')
    return wrapped


def apply(main_window_module) -> None:
    qss = """
QWidget#appRoot {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #f7fbff, stop:0.56 #f2f7ff, stop:1 #eaf3ff);
}
QFrame[card="true"] {
    background: rgba(255,255,255,0.94);
    border: 1px solid rgba(213,226,244,0.96);
    border-radius: 18px;
}
QFrame[softCard="true"] {
    background: rgba(248,251,255,0.96);
    border: 1px solid rgba(222,233,248,0.98);
    border-radius: 13px;
}
QLabel[title="true"] {
    font-size: 23px;
    font-weight: 850;
    color: #121a35;
}
QLabel[sectionTitle="true"] {
    font-size: 16px;
    font-weight: 800;
    color: #15203d;
}
QPushButton[buttonSize="xl"] {
    min-height: 54px;
    padding: 11px 20px;
    border-radius: 11px;
    font-size: 15px;
    font-weight: 800;
}
QPushButton[role="primary"] {
    color: #ffffff;
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0, stop:0 #2f7cff, stop:1 #0d6bff);
    border: 1px solid #0d6bff;
}
QPushButton[role="danger"] {
    color: #ffffff;
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0, stop:0 #ff676d, stop:1 #ff3f49);
    border: 1px solid #ff3f49;
}
QFrame#overviewGamePreview {
    border: 0;
    border-radius: 12px;
    background: #dce8f7;
}
QFrame#overviewStatusTile, QFrame#overviewLicenseRow, QFrame#overviewInfoPill {
    border-radius: 12px;
}
QLabel#overviewFishingStatus {
    font-size: 24px;
    font-weight: 850;
    color: #17203c;
}
QLabel#overviewStatusValue {
    font-size: 14px;
    font-weight: 850;
    color: #17203c;
}
QFrame#overviewMetric {
    background: transparent;
    border: none;
}
QFrame#overviewMetricDivider {
    background: #e1e9f5;
    border: none;
    min-width: 1px;
    max-width: 1px;
    margin-top: 10px;
    margin-bottom: 10px;
}
QLabel#overviewMetricValue {
    font-size: 22px;
    font-weight: 850;
    color: #14203d;
}
QLabel#overviewMetricLabel, QLabel#overviewPillCaption {
    color: #7180a0;
    font-size: 12px;
    font-weight: 650;
}
QLabel#overviewPillValue {
    color: #17203c;
    font-size: 13px;
    font-weight: 800;
}
QFrame#overviewInfoPill[tone="green"] {
    background: #ecfbf1;
    border: 1px solid #d4f4dd;
}
QFrame#overviewInfoPill[tone="blue"] {
    background: #f1f6ff;
    border: 1px solid #dce9ff;
}
QFrame#overviewInfoPill[tone="yellow"] {
    background: #fff8e9;
    border: 1px solid #ffe8b8;
}
QFrame#overviewInfoPill[tone="red"] {
    background: #fff1f2;
    border: 1px solid #ffd8dc;
}
QFrame#overviewInfoPill[tone="gray"] {
    background: #f7faff;
    border: 1px solid #e2ebf7;
}
QLabel#overviewStatusBadge {
    font-size: 12px;
}
QLabel[badge="yellow"] {
    color: #b77900;
    background: #fff5dc;
    border-radius: 9px;
    padding: 4px 10px;
    font-weight: 700;
}
QLabel#overviewHotkeyBadge {
    min-width: 28px;
    min-height: 24px;
}
"""
    if 'overviewGamePreview' not in widgets.SONAR_QSS:
        widgets.SONAR_QSS = widgets.SONAR_QSS + qss
    main_window_module.MainWindow._build_overview_tab = _build_overview_tab
    main_window_module.MainWindow._set_status_tiles = _set_status_tiles
    main_window_module.MainWindow._apply_telegram_settings_to_ui = _patch_telegram(main_window_module.MainWindow._apply_telegram_settings_to_ui)
    main_window_module.MainWindow._refresh_stream_tab = _patch_stream(main_window_module.MainWindow._refresh_stream_tab)
