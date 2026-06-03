from __future__ import annotations

import html
import os
import re
import signal
import threading
import time
from dataclasses import dataclass, field
from datetime import date, datetime, timezone
from pathlib import Path
from types import ModuleType

from PySide6.QtCore import QEvent, QEventLoop, QObject, QRegularExpression, QRectF, QSize, QTimer, Qt, Signal
from PySide6.QtGui import QColor, QCursor, QFont, QFontDatabase, QIcon, QImage, QPainter, QPen, QPixmap, QRegularExpressionValidator
from PySide6.QtWidgets import (
    QApplication,
    QAbstractItemView,
    QCheckBox,
    QComboBox,
    QFileDialog,
    QFrame,
    QFormLayout,
    QGraphicsDropShadowEffect,
    QGridLayout,
    QGroupBox,
    QHeaderView,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QMainWindow,
    QMessageBox,
    QPushButton,
    QProgressBar,
    QScrollArea,
    QSizePolicy,
    QSlider,
    QStackedWidget,
    QStyledItemDelegate,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)

from sonar.config.manager import ConfigManager
from sonar.config.models import SonarSettings
from sonar.core.events import UiEventMessage, event_bus
from sonar.core.state import BotPhase
from sonar.build_metadata import APP_BUILD_HASH, APP_NAME
from sonar.fishing.bot import FishingBot
from sonar.fishing.catch_quality import CATCH_SIZE_COLORS_BY_KEY
from sonar.fishing.fish_names import FISH_DISPLAY_NAMES, fish_id_from_display
from sonar.fishing.player_status import PlayerStatus
from sonar.fishing.statistics import (
    FishingSessionStats,
    format_base_price,
    format_catch_summary,
    format_duration,
    format_money_range,
    format_weight,
    parse_fish_prices_from_markdown,
)
from sonar.fishing.session_history import FishingSessionHistory, StoredFishingSession
from sonar.fishing.statistics_export import default_stats_csv_path, write_stats_csv
from sonar.fishing.tackle_detection import format_tackle_items
from sonar.license.client import LicenseStatus
from sonar.license.context import LicenseContext
from sonar.license.features import (
    FEATURE_FISHING,
    FEATURE_OVERVIEW,
    FEATURE_SETTINGS,
    FEATURE_STATISTICS,
    FEATURE_STREAM,
    FEATURE_STREAM_CHAT,
    FEATURE_TELEGRAM,
)
from sonar.license.manager import LicenseManager
from sonar.paths import APP_DIR, CONFIG_DIR, RESOURCE_DIR
from sonar.self_uninstall import get_uninstall_availability, schedule_self_uninstall
from sonar.streaming import StreamingService
from sonar.streaming.chat import ChatActionResult, ChatDetection, MajesticChatController
from sonar.streaming.service import STREAM_QUALITIES
from sonar.ui.feature_gate import apply_page_feature_gate, fallback_page
from sonar.ui.widgets import (
    ActionButton,
    Badge,
    Card,
    ContainedScrollArea,
    ElidedLabel,
    ExternalLinkLabel,
    HotkeyButton,
    IconLabel,
    MetricCard,
    NavButton,
    NonScrollingComboBox,
    PageScrollArea,
    SectionHeader,
    SettingCard,
    SvgIcon,
    ToggleSwitch,
    apply_sonar_style,
    clear_layout,
    icon_widget,
)
from sonar.version import APP_VERSION


URL_RE = re.compile(r"https?://[^\s<>'\"]+", re.IGNORECASE)
TRAILING_URL_PUNCTUATION = ".,;:!?)]}"
LICENSE_REFRESH_INTERVAL_SECONDS = 600
KEEP_DEBUG_CAPTURE_ARG = "--keep-debug-capture"
MANUAL_REELING_ARG = "--manual-reeling"
UI_ICON_DIR = RESOURCE_DIR / "ui_icons"
FISH_ICON_DIR = RESOURCE_DIR / "fishing" / "fish"
FONT_DIR = RESOURCE_DIR / "fonts"
FISH_KEEP_COLUMNS = 2


RECENT_EVENT_LIMIT = 400
RECENT_EVENT_RENDER_LIMIT = 80
SYSTEM_STATE_REFRESH_INTERVAL_SECONDS = 1.5
FISHING_PREVIEW_INTERVAL_MS = 2000

STATS_FILTER_CURRENT = "current"
STATS_FILTER_SESSION = "session"
STATS_FILTER_DATE = "date"
STATS_FILTER_RANGE = "range"
STATS_FILTER_SINCE = "since"


@dataclass(slots=True)
class RecentUiEvent:
    text: str
    event_type: str = "info"
    icon: str = ""
    detail: str = ""
    extra_green: str = ""
    extra_red: str = ""
    created_at: datetime = field(default_factory=datetime.now)


def ui_icon(name: str) -> Path:
    return UI_ICON_DIR / name


def fish_icon(fish_id: str) -> Path:
    return FISH_ICON_DIR / f"{fish_id}.png"


def fish_ui_pixmap(fish_id: str, size: QSize) -> QPixmap:
    path = fish_icon(fish_id)
    if not path.exists():
        return QPixmap()
    image = QImage(str(path)).convertToFormat(QImage.Format.Format_ARGB32)
    if image.isNull():
        return QPixmap()
    return QPixmap.fromImage(image).scaled(size, Qt.AspectRatioMode.KeepAspectRatio, Qt.TransformationMode.SmoothTransformation)


def catch_size_chart_color(key: str) -> str:
    return {
        "modest": "#9aa6bb",
        "good": "#2f80ff",
        "record": "#20c46b",
        "trophy": "#9b7cff",
        "unknown": "#f6b73c",
    }.get(key, CATCH_SIZE_COLORS_BY_KEY.get(key, "#2f80ff"))


def load_app_fonts() -> None:
    font_paths: list[Path] = []
    if FONT_DIR.exists():
        font_paths.extend(path for path in sorted(FONT_DIR.iterdir()) if path.suffix.lower() in {".otf", ".ttf"})
    windows_font_dir = Path(os.environ.get("WINDIR", r"C:\Windows")) / "Fonts"
    for name in ("segoeui.ttf", "segoeuib.ttf", "arial.ttf", "arialbd.ttf", "tahoma.ttf"):
        path = windows_font_dir / name
        if path.exists():
            font_paths.append(path)
    sf_download_dir = Path(r"D:\Downloads\San-Francisco-Pro-Fonts-master\San-Francisco-Pro-Fonts-master")
    for name in ("SF-Pro-Text-Regular.otf", "SF-Pro-Text-Semibold.otf", "SF-Pro-Display-Regular.otf", "SF-Pro-Display-Bold.otf"):
        path = sf_download_dir / name
        if path.exists():
            font_paths.append(path)
    loaded: set[Path] = set()
    for path in font_paths:
        normalized = path.resolve()
        if normalized in loaded:
            continue
        loaded.add(normalized)
        QFontDatabase.addApplicationFont(str(normalized))


def apply_app_font(app: QApplication) -> None:
    families = set(QFontDatabase.families())
    for family in ("Segoe UI Variable", "Segoe UI", "Arial"):
        if family in families:
            font = QFont(family, 8)
            font.setStyleStrategy(QFont.StyleStrategy.PreferAntialias)
            font.setHintingPreference(QFont.HintingPreference.PreferNoHinting)
            app.setFont(font)
            return


def format_update_message_html(text: str) -> str:
    text = normalize_update_message_text(text)
    parts: list[str] = []
    last_end = 0
    for match in URL_RE.finditer(text):
        parts.append(html.escape(text[last_end : match.start()], quote=False))
        url = match.group(0)
        suffix = ""
        while url and url[-1] in TRAILING_URL_PUNCTUATION:
            suffix = url[-1] + suffix
            url = url[:-1]
        if url:
            escaped_url = html.escape(url, quote=True)
            parts.append(f'<a href="{escaped_url}">{html.escape(url, quote=False)}</a>')
        parts.append(html.escape(suffix, quote=False))
        last_end = match.end()
    parts.append(html.escape(text[last_end:], quote=False))
    return "".join(parts).replace("\n", "<br>")


def format_download_link_html(url: str, label: str = "Скачать обновление") -> str:
    escaped_url = html.escape(url.strip(), quote=True)
    escaped_label = html.escape(label, quote=False)
    return f'<a href="{escaped_url}">{escaped_label}</a>'


def normalize_update_message_text(text: str) -> str:
    return str(text or "").replace("\r\n", "\n").replace("\r", "\n").replace("\\n", "\n")


def is_update_available(latest_version: str, current_version: str = APP_VERSION) -> bool:
    latest = _normalize_version_for_compare(latest_version)
    current = _normalize_version_for_compare(current_version)
    return bool(latest) and latest != current


def _normalize_version_for_compare(value: str) -> str:
    text = str(value or "").strip()
    if text[:1].lower() == "v":
        text = text[1:].strip()
    return text


class LogBridge(QObject):
    message = Signal(str)


class UiEventsBridge(QObject):
    message = Signal(object)


class LicenseBridge(QObject):
    result = Signal(object)


class TelegramSettingsBridge(QObject):
    changed = Signal(object)


class PlayerStatusBridge(QObject):
    updated = Signal(object)


class FishingPreviewBridge(QObject):
    updated = Signal(object)


class DigitsOnlyDelegate(QStyledItemDelegate):
    def createEditor(self, parent, option, index):  # type: ignore[override]
        editor = QLineEdit(parent)
        editor.setValidator(QRegularExpressionValidator(QRegularExpression(r"\d*"), editor))
        return editor

    def setModelData(self, editor, model, index) -> None:  # type: ignore[override]
        text = re.sub(r"\D", "", editor.text())
        model.setData(index, text, Qt.ItemDataRole.EditRole)


class CatchSizeDonut(QWidget):
    def __init__(self, parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self._rows: list[CatchSizeStat] = []
        self.setMinimumSize(110, 110)
        self.setSizePolicy(QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed)

    def set_rows(self, rows: list[CatchSizeStat]) -> None:
        self._rows = list(rows)
        self.update()

    def paintEvent(self, event) -> None:  # type: ignore[override]
        del event
        painter = QPainter(self)
        painter.setRenderHint(QPainter.RenderHint.Antialiasing)
        side = min(self.width(), self.height()) - 12
        rect = QRectF((self.width() - side) / 2, (self.height() - side) / 2, side, side)
        pen = QPen(QColor("#d9e2ef"), 12)
        pen.setCapStyle(Qt.PenCapStyle.FlatCap)
        painter.setPen(pen)
        painter.drawArc(rect, 0, 360 * 16)

        total = sum(row.count for row in self._rows)
        if total > 0:
            start_angle = 90 * 16
            for row in self._rows:
                if row.count <= 0:
                    continue
                span = -round(360 * 16 * row.count / total)
                pen.setColor(QColor(catch_size_chart_color(row.key)))
                painter.setPen(pen)
                painter.drawArc(rect, start_angle, span)
                start_angle += span

        painter.setPen(QColor("#17203c"))
        font = painter.font()
        font.setPointSize(14)
        font.setBold(True)
        painter.setFont(font)
        painter.drawText(rect, Qt.AlignmentFlag.AlignCenter, str(total))
        painter.end()


class CompactMetric(QFrame):
    def __init__(self, label: str, value: str = "—", icon: str | Path = "", parent: QWidget | None = None) -> None:
        super().__init__(parent)
        self.setObjectName("compactMetric")
        self.setStyleSheet(
            "QFrame#compactMetric { background: #f8fbff; border: 1px solid #e1eaf6; border-radius: 8px; }"
        )
        self.setMinimumHeight(42)
        self.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Fixed)
        layout = QHBoxLayout(self)
        layout.setContentsMargins(8, 6, 8, 6)
        layout.setSpacing(6)
        if icon:
            layout.addWidget(icon_widget(icon, 17), 0, Qt.AlignmentFlag.AlignVCenter)
        text_layout = QVBoxLayout()
        text_layout.setContentsMargins(0, 0, 0, 0)
        text_layout.setSpacing(0)
        self.value_label = QLabel(value)
        self.value_label.setMinimumWidth(0)
        self.value_label.setStyleSheet("font-size: 13px; font-weight: 850; color: #14203d;")
        self.label_label = QLabel(label)
        self.label_label.setProperty("metricLabel", True)
        text_layout.addWidget(self.value_label)
        text_layout.addWidget(self.label_label)
        layout.addLayout(text_layout, 1)

    def set_value(self, value: str) -> None:
        if self.value_label.text() == value:
            return
        self.value_label.setText(value)
        if len(value) > 18:
            size = 10
        elif len(value) > 13:
            size = 11
        else:
            size = 13
        self.value_label.setStyleSheet(f"font-size: {size}px; font-weight: 850; color: #14203d;")


class MainWindow(QMainWindow):
    def __init__(
        self,
        *,
        keep_debug_capture: bool = False,
        manual_reeling_mode: bool = False,
        initial_license_status: LicenseStatus | None = None,
        check_license_on_start: bool = True,
    ) -> None:
        super().__init__()
        self.config_manager = ConfigManager()
        self.settings = self.config_manager.load()
        self.license_manager = LicenseManager(self.config_manager)
        self.license_status = initial_license_status or LicenseStatus()
        self._license_checking = False
        self._next_license_refresh_at: datetime | None = None
        self._pending_bot_start_after_license = False
        self.license_bridge = LicenseBridge()
        self.license_bridge.result.connect(self._handle_license_result)
        self.telegram_settings_bridge = TelegramSettingsBridge()
        self.telegram_settings_bridge.changed.connect(self._handle_telegram_settings_changed)
        self.session_stats = FishingSessionStats(
            default_prices=parse_fish_prices_from_markdown(),
            custom_prices=self.settings.fishing.custom_fish_prices,
        )
        self.session_history = FishingSessionHistory(CONFIG_DIR / "statistics_sessions.json")
        self._stats_history_records: list[StoredFishingSession] = self.session_history.load()
        self._stats_display_stats: FishingSessionStats = self.session_stats
        self._stats_applied_filter_key: tuple[object, ...] = (STATS_FILTER_CURRENT,)
        self._stats_table_signature: tuple[object, ...] | None = None
        self._stats_metrics_signature: tuple[object, ...] | None = None
        self._catch_size_signature: tuple[object, ...] | None = None
        self._last_system_state_refresh_at = 0.0
        self._last_system_state_signature: tuple[object, ...] | None = None
        self._fishing_preview_refreshing = False
        self._recent_events_render_signature: tuple[object, ...] | None = None
        self._last_bot_running = False
        self._archived_stats_signature: tuple[object, ...] | None = None
        self.log_bridge = LogBridge()
        self.log_bridge.message.connect(self.append_log)
        self.ui_events_bridge = UiEventsBridge()
        self.ui_events_bridge.message.connect(self._handle_ui_event)
        self._unsubscribe_ui_events = event_bus.subscribe_ui_events(self.ui_events_bridge.message.emit)
        self.player_status_bridge = PlayerStatusBridge()
        self.player_status_bridge.updated.connect(self._handle_player_status_update)
        self.fishing_preview_bridge = FishingPreviewBridge()
        self.fishing_preview_bridge.updated.connect(self._handle_fishing_preview_image)
        self._player_status_refreshing = False
        self._latest_player_status: PlayerStatus | None = None
        self._latest_player_status_at = 0.0
        self._last_player_status_screenshot_at = 0.0
        self.bot = FishingBot(
            log_callback=self.log_bridge.message.emit,
            config_manager=self.config_manager,
            session_stats=self.session_stats,
            can_start_callback=self._can_start_fishing,
            start_command_callback=self._start_bot_from_remote,
            telegram_runtime_enabled_callback=lambda: self._can_use_feature(FEATURE_TELEGRAM),
            telegram_settings_changed_callback=self.telegram_settings_bridge.changed.emit,
            player_status_callback=self.player_status_bridge.updated.emit,
            keep_debug_capture=keep_debug_capture,
            manual_reeling_mode=manual_reeling_mode,
        )
        self.chat_controller = MajesticChatController(
            capture=self.bot.capture,
            window_activator=self.bot.window_activator,
            input_controller=self.bot.input_controller,
            log_callback=self.log_bridge.message.emit,
        )
        self.stream_service = StreamingService(
            log_callback=self.log_bridge.message.emit,
            chat_mode_callback=self._enable_chat_mode_from_stream,
            chat_exit_callback=self._disable_chat_mode_from_stream,
            chat_status_callback=self._detect_stream_chat_state,
            chat_select_callback=self._select_stream_chat_tab,
            chat_send_callback=self._send_stream_chat_message,
            chat_clear_callback=self._clear_stream_chat,
            game_window_available_callback=self.bot.capture.is_window_available,
            snapshot_mode_changed_callback=self._stream_snapshot_mode_changed_from_page,
            license_role_callback=self._license_role,
        )
        self.stream_service.set_snapshot_mode_enabled(self.settings.fishing.stream_snapshot_mode)
        self._resume_bot_after_chat = False
        self.bot.configure_streaming_callbacks(
            status_callback=self.stream_service.snapshot,
            start_callback=self._start_stream_from_remote,
            stop_callback=self._stop_stream_from_remote,
            set_quality_callback=self.stream_service.set_quality,
            set_chat_zoom_callback=self.stream_service.set_chat_zoom_enabled,
            set_snapshot_mode_callback=self._set_stream_snapshot_mode_from_remote,
        )
        self._stats_refreshing = False
        self._app_stopped_notified = False
        self._interrupt_quit_requested = False
        self.setWindowTitle(APP_NAME)
        icon_path = find_app_icon_path()
        if icon_path is not None:
            self.setWindowIcon(QIcon(str(icon_path)))
        self.resize(990, 615)
        self.setMinimumSize(860, 540)
        self._build_ui()
        self._load_settings_to_ui(self.settings)
        self.telegram_enabled_check.stateChanged.connect(self._telegram_enabled_changed)
        self._refresh_license_ui()
        self._refresh_update_block()
        if initial_license_status is not None:
            self._schedule_next_license_refresh(initial_license_status)
        self._apply_license_gate()
        if check_license_on_start:
            self._start_saved_license_check()
        self._hotkey_down = False
        self._hotkey_text = ""
        self._hotkey_vks: tuple[int, ...] = ()
        self._hotkey_suppressed_until_release = False
        self._win32api = self._load_win32api()
        self.hotkey_timer = QTimer(self)
        self.hotkey_timer.timeout.connect(self._poll_hotkey)
        if self._win32api is not None:
            self.hotkey_timer.start(80)
        self.status_timer = QTimer(self)
        self.status_timer.timeout.connect(self._refresh_status_label)
        self.status_timer.start(250)
        self.player_status_timer = QTimer(self)
        self.player_status_timer.timeout.connect(self._refresh_player_status)
        self.player_status_timer.start(5000)
        self.stats_timer = QTimer(self)
        self.stats_timer.timeout.connect(self._refresh_stats_tab)
        self.stats_timer.start(1000)
        self.fishing_preview_timer = QTimer(self)
        self.fishing_preview_timer.timeout.connect(self._refresh_fishing_preview)
        self.fishing_preview_timer.start(FISHING_PREVIEW_INTERVAL_MS)
        self.stream_timer = QTimer(self)
        self.stream_timer.timeout.connect(self._refresh_stream_tab)
        self.stream_timer.start(1000)
        self.license_timer = QTimer(self)
        self.license_timer.timeout.connect(self._license_tick)
        self.license_timer.start(1000)
        QTimer.singleShot(500, self._refresh_player_status)
        QTimer.singleShot(800, self._refresh_fishing_preview)
        QTimer.singleShot(0, self._notify_app_started)

    def _build_ui(self) -> None:
        apply_sonar_style(self)
        root = QWidget()
        root.setObjectName("appRoot")
        self.setCentralWidget(root)
        shell = QHBoxLayout(root)
        shell.setContentsMargins(0, 0, 0, 0)
        shell.setSpacing(0)

        self.sidebar = Card()
        self.sidebar.setObjectName("sidebar")
        self.sidebar.setProperty("card", False)
        self.sidebar.setFixedWidth(172)
        sidebar_layout = QVBoxLayout(self.sidebar)
        sidebar_layout.setContentsMargins(14, 18, 14, 14)
        sidebar_layout.setSpacing(8)
        self._build_sidebar(sidebar_layout)
        shell.addWidget(self.sidebar)

        self.content_shell = Card()
        self.content_shell.setObjectName("contentShell")
        self.content_shell.setProperty("card", False)
        self.content_shell.setGraphicsEffect(None)
        content_layout = QVBoxLayout(self.content_shell)
        content_layout.setContentsMargins(20, 18, 20, 18)
        content_layout.setSpacing(0)
        self.stack = QStackedWidget()
        self.stack.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)
        content_layout.addWidget(self.stack)
        self.content_shell.installEventFilter(self)
        self.stack.installEventFilter(self)
        shell.addWidget(self.content_shell, 1)

        self._nav_buttons: dict[QWidget, NavButton] = {}
        self._page_titles: dict[QWidget, str] = {}
        self._licensed_page_features: dict[QWidget, str] = {}
        self._status_labels: list[QLabel] = []
        self._status_description_labels: list[QLabel] = []
        self._start_buttons: list[QPushButton] = []
        self._stop_buttons: list[QPushButton] = []
        self._hotkey_badges: list[Badge] = []
        self._ready_badges: list[Badge] = []
        self._system_tiles: dict[str, list[QWidget]] = {
            "game": [],
            "food": [],
            "water": [],
            "inventory": [],
            "bait": [],
            "leader": [],
            "net": [],
        }
        self._license_overview_lines: list[QLabel] = []
        self._fishing_preview_labels: list[QLabel] = []

        self.overview_tab = self._build_overview_tab()
        self.license_tab = self._build_license_tab()
        self.fishing_tab = self._build_fishing_tab()
        self.settings_tab = self._build_settings_tab()
        self.statistics_tab = self._build_statistics_tab()
        self.stream_tab = self._build_stream_tab()
        self.telegram_tab = self._build_telegram_tab()
        self.about_tab = self._build_about_tab()

        self._register_page(self.overview_tab, "Обзор", ui_icon("menu.svg"), licensed=True, feature_key=FEATURE_OVERVIEW)
        self._register_page(self.license_tab, "Лицензия", ui_icon("id_card.svg"), licensed=False)
        self._register_page(self.fishing_tab, "Рыбалка", ui_icon("fishing_rod.svg"), licensed=True, feature_key=FEATURE_FISHING)
        self._register_page(self.settings_tab, "Настройки", ui_icon("settings.svg"), licensed=True, feature_key=FEATURE_SETTINGS)
        self._register_page(self.statistics_tab, "Статистика", ui_icon("chart.svg"), licensed=True, feature_key=FEATURE_STATISTICS)
        self._register_page(self.stream_tab, "Стрим", ui_icon("stream.svg"), licensed=True, feature_key=FEATURE_STREAM)
        self._register_page(self.telegram_tab, "Telegram", ui_icon("telegram_outline.svg"), licensed=True, feature_key=FEATURE_TELEGRAM)
        self._register_page(self.about_tab, "О приложении", ui_icon("info.svg"), licensed=False)
        self._select_page(self.license_tab)
        self._apply_license_gate()

    def eventFilter(self, watched, event) -> bool:  # type: ignore[override]
        if event.type() == QEvent.Type.Wheel and self._forward_page_wheel(event):
            return True
        return super().eventFilter(watched, event)

    def _forward_page_wheel(self, event) -> bool:
        if not hasattr(self, "stack"):
            return False
        page = self.stack.currentWidget()
        scroll = getattr(page, "_sonar_page_scroll_area", None)
        if scroll is None or not scroll.isVisible():
            return False
        try:
            global_pos = event.globalPosition().toPoint()
        except AttributeError:
            global_pos = QCursor.pos()
        page_pos = page.mapFromGlobal(global_pos)
        if not page.rect().contains(page_pos):
            return False
        if page_pos.y() < scroll.geometry().top():
            return False
        bar = scroll.verticalScrollBar()
        if bar.maximum() <= 0:
            return False
        delta = event.pixelDelta().y() if hasattr(event, "pixelDelta") and not event.pixelDelta().isNull() else event.angleDelta().y()
        if delta == 0:
            return False
        bar.setValue(bar.value() - delta)
        event.accept()
        return True

    def _build_sidebar(self, layout: QVBoxLayout) -> None:
        logo_row = QHBoxLayout()
        logo_row.setSpacing(8)
        logo_path = find_app_logo_path()
        if logo_path is not None:
            logo_row.addWidget(IconLabel(logo_path, 36))
        else:
            fallback = QLabel("◉")
            fallback.setStyleSheet("font-size: 34px; color: #1677ff;")
            logo_row.addWidget(fallback)
        app_label = QLabel("Sonar")
        app_label.setStyleSheet("font-size: 22px; font-weight: 850; color: #0d67e9;")
        logo_row.addWidget(app_label, 1)
        layout.addLayout(logo_row)
        layout.addSpacing(14)

        self.nav_layout = QVBoxLayout()
        self.nav_layout.setSpacing(4)
        layout.addLayout(self.nav_layout)
        layout.addStretch(1)

        self.sidebar_license_card = Card(soft=True)
        license_layout = QVBoxLayout(self.sidebar_license_card)
        license_layout.setContentsMargins(9, 9, 9, 9)
        license_layout.setSpacing(6)
        top = QHBoxLayout()
        self.sidebar_license_icon = SvgIcon(ui_icon("shield_check.svg"), 17, "#9aa6bb")
        top.addWidget(self.sidebar_license_icon)
        label_box = QVBoxLayout()
        label_box.setContentsMargins(0, 0, 0, 0)
        self.sidebar_license_title = QLabel("Лицензия")
        self.sidebar_license_title.setProperty("sectionTitle", True)
        self.sidebar_license_title.setStyleSheet("font-size: 11px; font-weight: 800;")
        self.sidebar_license_subtitle = QLabel("Статус неизвестен")
        self.sidebar_license_subtitle.setProperty("muted", True)
        self.sidebar_license_subtitle.setStyleSheet("font-size: 9px;")
        label_box.addWidget(self.sidebar_license_title)
        label_box.addWidget(self.sidebar_license_subtitle)
        top.addLayout(label_box, 1)
        license_layout.addLayout(top)
        self.sidebar_license_button = ActionButton("Управление", size="xxs")
        self.sidebar_license_button.clicked.connect(lambda: self._select_page(self.license_tab))
        license_layout.addWidget(self.sidebar_license_button)
        layout.addWidget(self.sidebar_license_card)

        self.sidebar_version_label = QLabel("")
        self.sidebar_version_label.setProperty("muted", True)
        self.sidebar_version_label.setStyleSheet("font-size: 11px;")
        self.sidebar_update_label = QLabel("")
        self.sidebar_update_label.setStyleSheet("font-size: 11px; color: #e54848; font-weight: 800;")
        self.sidebar_update_label.hide()
        layout.addWidget(self.sidebar_version_label)
        layout.addWidget(self.sidebar_update_label)

    def _register_page(self, page: QWidget, title: str, icon: str | Path, *, licensed: bool, feature_key: str | None = None) -> None:
        self.stack.addWidget(page)
        button = NavButton(title, icon)
        button.clicked.connect(lambda checked=False, page=page: self._select_page(page))
        self.nav_layout.addWidget(button)
        self._nav_buttons[page] = button
        self._page_titles[page] = title
        if licensed:
            self._licensed_page_features[page] = feature_key or title.lower()

    def _select_page(self, page: QWidget) -> None:
        if not hasattr(self, "stack"):
            return
        feature_key = self._licensed_page_features.get(page)
        if feature_key and not self._can_use_feature(feature_key):
            page = self.license_tab
        self.stack.setCurrentWidget(page)
        page.installEventFilter(self)
        page.setGraphicsEffect(None)
        for item, button in self._nav_buttons.items():
            button.set_selected(item is page)
        page.update()
        self.stack.update()
        if page in {getattr(self, "overview_tab", None), getattr(self, "fishing_tab", None)}:
            QTimer.singleShot(0, self._refresh_fishing_preview)
        if page is getattr(self, "about_tab", None):
            self._refresh_update_block()

    def _page(self, title: str, subtitle: str = "") -> tuple[QWidget, QVBoxLayout]:
        page = QWidget()
        layout = QVBoxLayout(page)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.setSpacing(12)
        layout.addWidget(SectionHeader(title, subtitle))
        return page, layout

    def _scroll_page(self, title: str, subtitle: str = "") -> tuple[QWidget, QVBoxLayout]:
        page, layout = self._page(title, subtitle)
        scroll = PageScrollArea()
        scroll.setWidgetResizable(True)
        scroll.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        content = QWidget()
        content.setObjectName("scrollPageContent")
        content_layout = QVBoxLayout(content)
        content_layout.setContentsMargins(0, 0, 6, 0)
        content_layout.setSpacing(12)
        scroll.setWidget(content)
        page._sonar_page_scroll_area = scroll
        layout.addWidget(scroll, 1)
        return page, content_layout

    def _build_overview_tab(self) -> QWidget:
        page, layout = self._page("Обзор", "Главный экран управления рыбалкой, стримом и уведомлениями.")
        top = QHBoxLayout()
        top.setSpacing(12)
        top.addWidget(self._build_fishing_control_card(), 3)
        top.addWidget(self._build_system_state_card(include_tackle=False), 2)
        layout.addLayout(top, 3)

        session_card = Card()
        session_card.setMinimumHeight(78)
        session_card.setMaximumHeight(86)
        session_layout = QVBoxLayout(session_card)
        session_layout.setContentsMargins(12, 8, 12, 10)
        session_layout.setSpacing(7)
        title = QLabel("Текущая сессия")
        title.setProperty("sectionTitle", True)
        session_layout.addWidget(title)
        metrics = QHBoxLayout()
        metrics.setSpacing(7)
        self.overview_duration_metric = CompactMetric("Время", "00:00", ui_icon("clock.svg"))
        self.overview_caught_metric = CompactMetric("Поймано", "0", ui_icon("fish_solid.svg"))
        self.overview_released_metric = CompactMetric("Отпущено", "0", ui_icon("fish.svg"))
        self.overview_income_metric = CompactMetric("Доход", "0 $", ui_icon("dollar.svg"))
        self.overview_income_hour_metric = CompactMetric("Доход / час", "0 $", ui_icon("profit.svg"))
        for widget in (
            self.overview_duration_metric,
            self.overview_caught_metric,
            self.overview_released_metric,
            self.overview_income_metric,
            self.overview_income_hour_metric,
        ):
            metrics.addWidget(widget)
        session_layout.addLayout(metrics)
        layout.addWidget(session_card, 0)

        bottom = QHBoxLayout()
        bottom.setSpacing(12)
        bottom.addWidget(self._build_overview_telegram_card(), 1)
        bottom.addWidget(self._build_overview_stream_card(), 1)
        bottom.addWidget(self._build_recent_events_card(), 2)
        layout.addLayout(bottom, 3)
        return page

    def _build_update_card(self) -> QWidget:
        card = Card(soft=True)
        card.hide()
        self.update_group = card
        layout = QHBoxLayout(card)
        layout.setContentsMargins(12, 10, 12, 10)
        layout.setSpacing(9)
        layout.addWidget(icon_widget(ui_icon("download.svg"), 22, color="#1677ff"), 0, Qt.AlignmentFlag.AlignTop)
        text_box = QVBoxLayout()
        text_box.setContentsMargins(0, 0, 0, 0)
        text_box.setSpacing(6)
        self.update_label = QLabel("")
        self.update_label.setWordWrap(True)
        self.update_label.setTextFormat(Qt.TextFormat.RichText)
        self.update_label.setOpenExternalLinks(True)
        self.update_label.setTextInteractionFlags(Qt.TextInteractionFlag.TextBrowserInteraction)
        self.update_label.setProperty("muted", True)
        self.update_download_link = QLabel("")
        self.update_download_link.setTextFormat(Qt.TextFormat.RichText)
        self.update_download_link.setOpenExternalLinks(True)
        self.update_download_link.setTextInteractionFlags(Qt.TextInteractionFlag.TextBrowserInteraction)
        self.update_download_link.setStyleSheet("font-size: 13px; font-weight: 800;")
        text_box.addWidget(self.update_label)
        text_box.addWidget(self.update_download_link)
        layout.addLayout(text_box, 1)
        return card

    def _build_player_status_card(self) -> QWidget:
        card = Card()
        card.setMaximumHeight(222)
        layout = QVBoxLayout(card)
        layout.setContentsMargins(12, 10, 12, 12)
        layout.setSpacing(8)
        title_row = QHBoxLayout()
        title = QLabel("Игрок")
        title.setProperty("sectionTitle", True)
        self.player_status_source_label = QLabel("Ожидание данных")
        self.player_status_source_label.setProperty("muted", True)
        self.player_status_scan_button = ActionButton("Просканировать показатели", icon=ui_icon("pulse.svg"), size="s")
        self.player_status_scan_button.clicked.connect(self.request_player_status_scan)
        title_row.addWidget(title)
        title_row.addStretch(1)
        title_row.addWidget(self.player_status_source_label)
        title_row.addWidget(self.player_status_scan_button)
        layout.addLayout(title_row)
        metrics = QHBoxLayout()
        metrics.setSpacing(9)
        self.player_food_metric = MetricCard("Еда", "—", ui_icon("food.svg"))
        self.player_water_metric = MetricCard("Вода", "—", ui_icon("gauge_10fps.png"))
        self.player_health_metric = MetricCard("HP", "—", ui_icon("gauge_10fps.png"))
        self.player_inventory_weight_metric = MetricCard("Инвентарь", "—", ui_icon("scales.svg"))
        self.player_backpack_weight_metric = MetricCard("Рюкзак", "—", ui_icon("backpack.png"))
        for metric in (
            self.player_food_metric,
            self.player_water_metric,
            self.player_health_metric,
            self.player_inventory_weight_metric,
            self.player_backpack_weight_metric,
        ):
            metrics.addWidget(metric)
        layout.addLayout(metrics)
        return card

    def _build_fishing_control_card(self) -> QWidget:
        card = Card()
        layout = QVBoxLayout(card)
        layout.setContentsMargins(14, 12, 14, 14)
        layout.setSpacing(11)
        heading = QHBoxLayout()
        heading.setSpacing(10)
        title_box = QVBoxLayout()
        title_box.setContentsMargins(0, 0, 0, 0)
        title = QLabel("Рыбалка")
        title.setProperty("title", True)
        fishing_ready_badge = Badge("Готов", "green")
        self._ready_badges.append(fishing_ready_badge)
        title_row = QHBoxLayout()
        title_row.addWidget(title)
        title_row.addWidget(fishing_ready_badge)
        title_row.addStretch(1)
        title_box.addLayout(title_row)
        state_caption = QLabel("Состояние")
        state_caption.setProperty("muted", True)
        status_label = QLabel("Ожидание")
        status_label.setStyleSheet("font-size: 19px; font-weight: 850; color: #17203c;")
        status_description_label = QLabel("Ожидание команды для начала рыбалки")
        status_description_label.setProperty("muted", True)
        status_description_label.setWordWrap(True)
        self._status_labels.append(status_label)
        self._status_description_labels.append(status_description_label)
        self.status_label = status_label
        title_box.addWidget(state_caption)
        title_box.addWidget(status_label)
        title_box.addWidget(status_description_label)
        heading.addLayout(title_box, 1)
        hotkey_card = Card(soft=True)
        hotkey_card.setFixedWidth(102)
        hotkey_card.setMinimumHeight(70)
        hotkey_layout = QVBoxLayout(hotkey_card)
        hotkey_layout.setContentsMargins(9, 8, 9, 8)
        hotkey_layout.setSpacing(5)
        hotkey_title = QLabel("Горячая")
        hotkey_title.setProperty("muted", True)
        main_hotkey_label = Badge("F9", "blue")
        main_hotkey_label.setMinimumHeight(28)
        self._hotkey_badges.append(main_hotkey_label)
        hotkey_layout.addWidget(hotkey_title)
        hotkey_layout.addWidget(main_hotkey_label)
        heading.addWidget(hotkey_card)
        preview = QLabel("Скриншот игры появится после захвата")
        preview.setObjectName("fishingPreview")
        preview.setAlignment(Qt.AlignmentFlag.AlignCenter)
        preview.setWordWrap(True)
        preview.setFixedSize(160, 96)
        preview.setSizePolicy(QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed)
        preview.setProperty("muted", True)
        self._fishing_preview_labels.append(preview)
        heading.addWidget(preview)
        layout.addLayout(heading)

        buttons = QHBoxLayout()
        buttons.setSpacing(9)
        start_button = ActionButton("Запустить", "primary", icon=ui_icon("play_white.svg"), size="xl")
        stop_button = ActionButton("Остановить", "danger", icon=ui_icon("stop_white.svg"), size="xl")
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

    def _build_system_state_card(self, *, include_tackle: bool = True) -> QWidget:
        card = Card()
        layout = QVBoxLayout(card)
        layout.setContentsMargins(12, 10, 12, 10)
        layout.setSpacing(6)
        title = QLabel("Состояние системы")
        title.setProperty("sectionTitle", True)
        layout.addWidget(title)
        grid = QGridLayout()
        grid.setHorizontalSpacing(8)
        grid.setVerticalSpacing(6)
        self.game_state_tile = self._status_tile("Игра", "Не проверялась", "Majestic RP", ui_icon("monitor.svg"))
        self.player_food_tile = self._status_tile("Еда", "—", "Показатель", ui_icon("food.svg"))
        self.player_water_tile = self._status_tile("Вода", "—", "Показатель", ui_icon("pulse.svg"))
        self.player_inventory_tile = self._status_tile("Инвентарь", "—", "Вес", ui_icon("backpack.png"))
        self._system_tiles["game"].append(self.game_state_tile)
        self._system_tiles["food"].append(self.player_food_tile)
        self._system_tiles["water"].append(self.player_water_tile)
        self._system_tiles["inventory"].append(self.player_inventory_tile)
        grid.addWidget(self.game_state_tile, 0, 0)
        grid.addWidget(self.player_inventory_tile, 0, 1)
        grid.addWidget(self.player_food_tile, 1, 0)
        grid.addWidget(self.player_water_tile, 1, 1)
        if include_tackle:
            self.tackle_bait_tile = self._status_tile("Наживка", "Не сканировалась", "", ui_icon("bait.png"))
            self.tackle_leader_tile = self._status_tile("Поводок", "Не сканировался", "", ui_icon("leader.png"))
            self.tackle_net_tile = self._status_tile("Подсак", "Не сканировался", "", ui_icon("landing_net.png"))
            self._system_tiles["bait"].append(self.tackle_bait_tile)
            self._system_tiles["leader"].append(self.tackle_leader_tile)
            self._system_tiles["net"].append(self.tackle_net_tile)
            grid.addWidget(self.tackle_bait_tile, 2, 0)
            grid.addWidget(self.tackle_leader_tile, 2, 1)
            grid.addWidget(self.tackle_net_tile, 3, 0)
        layout.addLayout(grid)
        return card

    def _status_tile(self, title: str, value: str, subtitle: str, icon: str | Path) -> QWidget:
        tile = Card(soft=True)
        tile.setMinimumHeight(45)
        tile.setSizePolicy(QSizePolicy.Policy.Preferred, QSizePolicy.Policy.Fixed)
        layout = QHBoxLayout(tile)
        layout.setContentsMargins(7, 5, 7, 5)
        layout.setSpacing(6)
        layout.addWidget(icon_widget(icon, 18, color="#1f7aff"), 0, Qt.AlignmentFlag.AlignVCenter)
        texts = QVBoxLayout()
        texts.setContentsMargins(0, 0, 0, 0)
        texts.setSpacing(0)
        title_label = QLabel(title)
        title_label.setProperty("muted", True)
        value_label = QLabel(value)
        value_label.setStyleSheet("font-size: 12px; font-weight: 800; color: #17203c;")
        subtitle_label = QLabel(subtitle or " ")
        subtitle_label.setProperty("muted", True)
        subtitle_label.setMinimumHeight(13)
        texts.addWidget(title_label)
        texts.addWidget(value_label)
        texts.addWidget(subtitle_label)
        layout.addLayout(texts, 1)
        dot = QLabel("●")
        dot.setFixedSize(14, 14)
        dot.setAlignment(Qt.AlignmentFlag.AlignCenter)
        dot.setStyleSheet("color: #ff4d4f; font-size: 12px;")
        layout.addWidget(dot, 0, Qt.AlignmentFlag.AlignTop | Qt.AlignmentFlag.AlignRight)
        tile.value_label = value_label
        tile.subtitle_label = subtitle_label
        tile.dot_label = dot
        return tile

    def _overview_detail_row(self, label: str, value: QLabel) -> QHBoxLayout:
        row = QHBoxLayout()
        row.setSpacing(8)
        label_widget = QLabel(label)
        label_widget.setProperty("muted", True)
        row.addWidget(label_widget)
        row.addWidget(value, 1, Qt.AlignmentFlag.AlignRight)
        return row

    def _build_overview_telegram_card(self) -> QWidget:
        card = Card()
        card.setMinimumHeight(190)
        layout = QVBoxLayout(card)
        layout.setContentsMargins(12, 10, 12, 12)
        layout.setSpacing(8)
        header = QHBoxLayout()
        header.setSpacing(8)
        header.addWidget(IconLabel(ui_icon("telegram_color.svg"), 21))
        title = QLabel("Telegram")
        title.setProperty("sectionTitle", True)
        self.overview_telegram_badge = Badge("Отключен", "gray")
        header.addWidget(title, 1)
        header.addWidget(self.overview_telegram_badge)
        layout.addLayout(header)
        self.overview_telegram_description = QLabel("Бот и уведомления")
        self.overview_telegram_description.setWordWrap(True)
        self.overview_telegram_description.setProperty("muted", True)
        layout.addWidget(self.overview_telegram_description)
        self.overview_telegram_chat_id_label = QLabel("—")
        self.overview_telegram_chat_id_label.setStyleSheet("font-weight: 800; color: #1268e8;")
        self.overview_telegram_status_label = QLabel("—")
        self.overview_telegram_status_label.setStyleSheet("font-weight: 800; color: #17203c;")
        self.overview_telegram_notifications_label = QLabel("—")
        self.overview_telegram_notifications_label.setStyleSheet("font-weight: 800; color: #17203c;")
        layout.addLayout(self._overview_detail_row("Chat ID", self.overview_telegram_chat_id_label))
        layout.addLayout(self._overview_detail_row("Статус", self.overview_telegram_status_label))
        layout.addLayout(self._overview_detail_row("Уведомления", self.overview_telegram_notifications_label))
        layout.addStretch(1)
        button = ActionButton("Настроить", icon=ui_icon("settings.svg"), size="s")
        button.clicked.connect(self._select_telegram_page)
        layout.addWidget(button)
        self._refresh_overview_telegram_card()
        return card

    def _build_overview_stream_card(self) -> QWidget:
        card = Card()
        card.setMinimumHeight(190)
        layout = QVBoxLayout(card)
        layout.setContentsMargins(12, 10, 12, 12)
        layout.setSpacing(8)
        header = QHBoxLayout()
        header.setSpacing(8)
        header.addWidget(icon_widget(ui_icon("stream.svg"), 21, color="#1f7aff"))
        title = QLabel("Стрим")
        title.setProperty("sectionTitle", True)
        self.overview_stream_badge = Badge("Ожидание", "gray")
        header.addWidget(title, 1)
        header.addWidget(self.overview_stream_badge)
        layout.addLayout(header)
        self.overview_stream_description = QLabel("Трансляция и чат")
        self.overview_stream_description.setWordWrap(True)
        self.overview_stream_description.setProperty("muted", True)
        layout.addWidget(self.overview_stream_description)
        self.overview_stream_status_label = QLabel("—")
        self.overview_stream_status_label.setStyleSheet("font-weight: 800; color: #17203c;")
        self.overview_stream_quality_label = QLabel("—")
        self.overview_stream_quality_label.setStyleSheet("font-weight: 800; color: #17203c;")
        self.overview_stream_mode_label = QLabel("—")
        self.overview_stream_mode_label.setStyleSheet("font-weight: 800; color: #17203c;")
        layout.addLayout(self._overview_detail_row("Статус", self.overview_stream_status_label))
        layout.addLayout(self._overview_detail_row("Качество", self.overview_stream_quality_label))
        layout.addLayout(self._overview_detail_row("Режим", self.overview_stream_mode_label))
        layout.addStretch(1)
        button = ActionButton("Настроить", icon=ui_icon("settings.svg"), size="s")
        button.clicked.connect(self._select_stream_page)
        layout.addWidget(button)
        self._refresh_overview_stream_card()
        return card

    def _build_small_status_card(self, title: str, subtitle: str, icon: str | Path, callback) -> QWidget:
        card = Card()
        card.setMinimumHeight(150)
        layout = QVBoxLayout(card)
        layout.setContentsMargins(12, 10, 12, 12)
        layout.setSpacing(8)
        row = QHBoxLayout()
        if isinstance(icon, Path):
            row.addWidget(IconLabel(icon, 21))
        else:
            icon_label = QLabel(icon)
            icon_label.setStyleSheet("font-size: 24px; color: #1677ff;")
            row.addWidget(icon_label)
        title_label = QLabel(title)
        title_label.setProperty("sectionTitle", True)
        row.addWidget(title_label, 1)
        layout.addLayout(row)
        subtitle_label = QLabel(subtitle)
        subtitle_label.setProperty("muted", True)
        layout.addWidget(subtitle_label)
        button = ActionButton("Настроить")
        button.clicked.connect(callback)
        layout.addStretch(1)
        layout.addWidget(button)
        return card

    def _select_telegram_page(self) -> None:
        self._select_page(self.telegram_tab)

    def _select_stream_page(self) -> None:
        self._select_page(self.stream_tab)

    def _build_recent_events_card(self) -> QWidget:
        card = Card()
        card.setMinimumHeight(190)
        layout = QVBoxLayout(card)
        layout.setContentsMargins(12, 10, 12, 12)
        layout.setSpacing(6)
        row = QHBoxLayout()
        title = QLabel("Последние события")
        title.setProperty("sectionTitle", True)
        row.addWidget(title, 1)
        clear_button = ActionButton("Очистить", size="xs")
        clear_button.clicked.connect(self._clear_recent_events)
        row.addWidget(clear_button)
        layout.addLayout(row)
        self.recent_events_scroll = QScrollArea()
        self.recent_events_scroll.setObjectName("recentEventsScroll")
        self.recent_events_scroll.setWidgetResizable(True)
        self.recent_events_scroll.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.recent_events_scroll.setFrameShape(QFrame.Shape.NoFrame)
        self.recent_events_widget = QWidget()
        self.recent_events_widget.setObjectName("recentEventsWidget")
        self.recent_events_layout = QVBoxLayout(self.recent_events_widget)
        self.recent_events_layout.setContentsMargins(0, 0, 5, 0)
        self.recent_events_layout.setSpacing(0)
        self.recent_events_layout.setAlignment(Qt.AlignmentFlag.AlignBottom)
        self.recent_events_scroll.setWidget(self.recent_events_widget)
        layout.addWidget(self.recent_events_scroll, 1)
        self._recent_events: list[RecentUiEvent] = []
        self._refresh_recent_events()
        return card

    def _build_license_tab(self) -> QWidget:
        page, layout = self._page("Лицензия", "Активация ключа и состояние аккаунта.")
        row = QHBoxLayout()
        row.setSpacing(16)
        activation = Card()
        activation_layout = QVBoxLayout(activation)
        activation_layout.setContentsMargins(18, 16, 18, 18)
        activation_layout.setSpacing(12)
        title = QLabel("Лицензия")
        title.setProperty("sectionTitle", True)
        self.license_summary_label = QLabel("Введите ключ лицензии")
        self.license_summary_label.setWordWrap(True)
        self.license_summary_label.setProperty("muted", True)
        self.license_key_input = QLineEdit()
        self.license_key_input.setPlaceholderText("FA5B1-...-G2K34")
        self.license_key_input.setEchoMode(QLineEdit.EchoMode.Password)
        self.license_activate_button = ActionButton("Активировать", "primary")
        self.license_activate_button.clicked.connect(self.activate_license)
        self.license_status_label = QLabel("")
        self.license_status_label.setWordWrap(True)
        self.license_status_label.setProperty("muted", True)
        activation_layout.addWidget(title)
        activation_layout.addWidget(self.license_summary_label)
        activation_layout.addWidget(QLabel("Ключ лицензии"))
        activation_layout.addWidget(self.license_key_input)
        activation_layout.addWidget(self.license_activate_button)
        activation_layout.addWidget(self.license_status_label)
        activation_layout.addStretch(1)
        row.addWidget(activation, 2)

        info = Card()
        info_layout = QVBoxLayout(info)
        info_layout.setContentsMargins(18, 16, 18, 18)
        info_layout.setSpacing(12)
        info_title = QLabel("Аккаунт")
        info_title.setProperty("sectionTitle", True)
        self.license_account_status = MetricCard("Статус", "Не активна", ui_icon("shield_check.svg"))
        self.license_account_expiry = MetricCard("Действует до", "—", ui_icon("calendar.svg"))
        self.license_account_role = MetricCard("Роль", "user", ui_icon("id_card.svg"))
        self.license_account_role.hide()
        info_layout.addWidget(info_title)
        info_layout.addWidget(self.license_account_status)
        info_layout.addWidget(self.license_account_expiry)
        info_layout.addStretch(1)
        row.addWidget(info, 1)
        layout.addLayout(row, 1)
        return page

    def _build_fishing_tab(self) -> QWidget:
        page, layout = self._page("Рыбалка", "Запуск бота, состояние снастей и краткая сводка сессии.")
        row = QHBoxLayout()
        row.setSpacing(12)
        row.addWidget(self._build_fishing_control_card(), 3)
        row.addWidget(self._build_system_state_card(), 2)
        layout.addLayout(row)

        summary_row = QHBoxLayout()
        summary_row.setSpacing(12)
        details = Card()
        details_layout = QHBoxLayout(details)
        details_layout.setContentsMargins(12, 10, 12, 12)
        details_layout.setSpacing(9)
        self.fishing_duration_metric = MetricCard("Время", "00:00", ui_icon("clock.svg"))
        self.fishing_caught_metric = MetricCard("Поймано", "0", ui_icon("fish_solid.svg"))
        self.fishing_released_metric = MetricCard("Отпущено", "0", ui_icon("fish.svg"))
        self.fishing_income_metric = MetricCard("Доход", "0 $", ui_icon("dollar.svg"))
        for widget in (
            self.fishing_duration_metric,
            self.fishing_caught_metric,
            self.fishing_released_metric,
            self.fishing_income_metric,
        ):
            details_layout.addWidget(widget)
        summary_row.addWidget(details, 3)

        tackle_group = Card()
        tackle_layout = QVBoxLayout(tackle_group)
        tackle_layout.setContentsMargins(12, 10, 12, 12)
        tackle_layout.setSpacing(6)
        tackle_title = QLabel("Снаряжение")
        tackle_title.setProperty("sectionTitle", True)
        self.fishing_tackle_label = QLabel("Снаряжение ещё не сканировалось")
        self.fishing_tackle_label.setWordWrap(True)
        self.fishing_tackle_label.setProperty("muted", True)
        tackle_layout.addWidget(tackle_title)
        tackle_layout.addWidget(self.fishing_tackle_label, 1)
        summary_row.addWidget(tackle_group, 2)

        layout.addLayout(summary_row)
        layout.addStretch(1)
        return page

    def _build_settings_tab(self) -> QWidget:
        page, layout = self._scroll_page("Настройки", "Настройте поведение бота под ваш стиль игры. Все элементы закреплены в единой сетке.")
        main = QHBoxLayout()
        main.setSpacing(12)
        left = QVBoxLayout()
        left.setSpacing(9)
        settings_grid = QGridLayout()
        settings_grid.setSpacing(9)

        self.auto_meal_check = ToggleSwitch("Включено")
        settings_grid.addWidget(self._switch_card("Авто-питание", "Автоматически использовать еду и воду при признаках голода/жажды.", ui_icon("food.svg"), self.auto_meal_check), 0, 0)
        self.food_depleted_action_combo = NonScrollingComboBox()
        self.food_depleted_action_combo.addItem("Продолжать рыбалку", "continue")
        self.food_depleted_action_combo.addItem("Остановить рыбалку", "stop")
        self.food_depleted_action_combo.addItem("Выключить игру", "exit_game")
        self.food_depleted_action_combo.addItem("Выключить компьютер", "shutdown_pc")
        self.food_depleted_action_card = self._combo_card("Действия, если закончилась еда", "Что делать, если голод/жажда остались, а еды нет.", ui_icon("food.svg"), self.food_depleted_action_combo)
        settings_grid.addWidget(self.food_depleted_action_card, 0, 1)
        self.auto_change_bait_check = ToggleSwitch("Включено")
        settings_grid.addWidget(self._switch_card("Авто-смена наживки", "Менять наживку, когда игра показывает необходимость замены.", ui_icon("bait.png"), self.auto_change_bait_check), 1, 0)
        self.store_trunk_check = ToggleSwitch("Включено")
        settings_grid.addWidget(self._switch_card("Складывать в багажник", "Автоматически складывать рыбу в багажник.", ui_icon("trunk.svg"), self.store_trunk_check), 1, 1)
        self.start_stop_sound_check = ToggleSwitch("Включено")
        settings_grid.addWidget(self._switch_card("Звук запуска и остановки", "Воспроизводить нейтральный звук при старте и остановке.", ui_icon("sound.svg"), self.start_stop_sound_check), 2, 0)

        self.overweight_action_combo = NonScrollingComboBox()
        self.overweight_action_combo.addItem("Отпускать рыбу", "release")
        self.overweight_action_combo.addItem("Остановить рыбалку", "stop")
        self.overweight_action_combo.addItem("Закрыть игру", "exit_game")
        settings_grid.addWidget(self._combo_card("Действия при перевесе", "Что делать, если инвентарь перегружен.", ui_icon("scales.svg"), self.overweight_action_combo), 2, 1)

        self.fish_without_leader_check = ToggleSwitch("Продолжать без поводка")
        self.leader_depleted_action_combo = NonScrollingComboBox()
        self.leader_depleted_action_combo.addItem("Рыбалка остановится", "stop")
        self.leader_depleted_action_combo.addItem("Закроется игра", "exit_game")
        leader_card = self._switch_combo_card("Рыбалка без поводка", "Если поводки закончились.", ui_icon("leader.png"), self.fish_without_leader_check, self.leader_depleted_action_combo)
        settings_grid.addWidget(leader_card, 3, 0)

        self.fish_without_net_check = ToggleSwitch("Продолжать без подсака")
        self.net_depleted_action_combo = NonScrollingComboBox()
        self.net_depleted_action_combo.addItem("Рыбалка остановится", "stop")
        self.net_depleted_action_combo.addItem("Закроется игра", "exit_game")
        net_card = self._switch_combo_card("Рыбалка без подсака", "Если подсак закончился или сломался.", ui_icon("landing_net.png"), self.fish_without_net_check, self.net_depleted_action_combo)
        settings_grid.addWidget(net_card, 3, 1)

        self.equipment_depleted_action_combo = NonScrollingComboBox()
        self.equipment_depleted_action_combo.addItem("Остановить бота", "stop")
        self.equipment_depleted_action_combo.addItem("Закрыть игру", "exit_game")
        self.equipment_depleted_action_combo.addItem("Выключить компьютер", "shutdown_pc")
        settings_grid.addWidget(self._combo_card("Если закончилось снаряжение", "Общее действие при отсутствии нужных снастей.", ui_icon("settings.svg"), self.equipment_depleted_action_combo), 4, 0, 1, 2)

        self.auto_meal_check.stateChanged.connect(self._refresh_meal_action_controls)
        self.fish_without_leader_check.stateChanged.connect(self._refresh_tackle_action_controls)
        self.fish_without_net_check.stateChanged.connect(self._refresh_tackle_action_controls)
        left.addLayout(settings_grid)

        self.meal_thresholds_card = Card()
        meal_thresholds_layout = QVBoxLayout(self.meal_thresholds_card)
        meal_thresholds_layout.setContentsMargins(12, 10, 12, 12)
        meal_thresholds_layout.setSpacing(8)
        meal_thresholds_title = QLabel("Пороги восстановления")
        meal_thresholds_title.setProperty("sectionTitle", True)
        meal_thresholds_layout.addWidget(meal_thresholds_title)
        self.restore_food_slider = self._threshold_slider("Восстанавливать еду от", meal_thresholds_layout)
        self.restore_water_slider = self._threshold_slider("Восстанавливать воду от", meal_thresholds_layout)
        left.addWidget(self.meal_thresholds_card)

        self.garbage_checks: dict[str, QCheckBox] = {}

        fish_group = Card()
        fish_layout = QVBoxLayout(fish_group)
        fish_layout.setContentsMargins(12, 10, 12, 12)
        fish_layout.setSpacing(7)
        fish_title = QLabel("Рыбу оставлять")
        fish_title.setProperty("sectionTitle", True)
        fish_note = QLabel("Выберите рыбу, которую бот будет забирать. Остальную — отпускать.")
        fish_note.setProperty("muted", True)
        fish_layout.addWidget(fish_title)
        fish_layout.addWidget(fish_note)
        fish_scroll = ContainedScrollArea()
        fish_scroll.setObjectName("fishKeepScroll")
        fish_scroll.setWidgetResizable(True)
        fish_scroll.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        fish_scroll.setFixedHeight(195)
        fish_widget = QWidget()
        fish_widget.setObjectName("fishKeepList")
        fish_grid = QGridLayout(fish_widget)
        fish_grid.setContentsMargins(0, 0, 0, 0)
        fish_grid.setSpacing(6)
        for column in range(FISH_KEEP_COLUMNS):
            fish_grid.setColumnStretch(column, 1)
        self.fish_checks: dict[str, QCheckBox] = {}
        for index, fish_id in enumerate(sorted(FISH_DISPLAY_NAMES, key=lambda item: FISH_DISPLAY_NAMES[item])):
            card, checkbox = self._fish_keep_card(fish_id, FISH_DISPLAY_NAMES[fish_id])
            self.fish_checks[fish_id] = checkbox
            fish_grid.addWidget(card, index // FISH_KEEP_COLUMNS, index % FISH_KEEP_COLUMNS)
        fish_scroll.setWidget(fish_widget)
        fish_layout.addWidget(fish_scroll)
        left.addWidget(fish_group)
        main.addLayout(left, 1)

        right = QVBoxLayout()
        right.setSpacing(12)
        hotkey_card = Card()
        hotkey_layout = QVBoxLayout(hotkey_card)
        hotkey_layout.setContentsMargins(12, 10, 12, 12)
        hotkey_layout.setSpacing(7)
        hotkey_title = QLabel("Горячие клавиши")
        hotkey_title.setProperty("sectionTitle", True)
        hotkey_layout.addWidget(hotkey_title)
        self.hotkey_input = HotkeyButton()
        self.inventory_hotkey_input = HotkeyButton()
        self.use_item_hotkey_input = HotkeyButton()
        self.backpack_move_hotkey_input = HotkeyButton()
        self.discard_key_input = HotkeyButton()
        self.chat_hotkey_input = HotkeyButton()
        self._hotkey_inputs = [
            self.hotkey_input,
            self.inventory_hotkey_input,
            self.use_item_hotkey_input,
            self.backpack_move_hotkey_input,
            self.discard_key_input,
            self.chat_hotkey_input,
        ]
        for input_widget in self._hotkey_inputs:
            input_widget.hotkeyChanged.connect(self._suppress_hotkey_until_release)
            input_widget.captureStateChanged.connect(self._hotkey_capture_state_changed)
        for label, widget in (
            ("Старт / Стоп", self.hotkey_input),
            ("Инвентарь", self.inventory_hotkey_input),
            ("Использование", self.use_item_hotkey_input),
            ("Положить/поднять в рюкзак", self.backpack_move_hotkey_input),
            ("Выброс", self.discard_key_input),
            ("Чат", self.chat_hotkey_input),
        ):
            hotkey_layout.addLayout(self._compact_form_row(label, widget))
        right.addWidget(hotkey_card)
        self.save_settings_button = ActionButton("Сохранить настройки", "primary", icon=ui_icon("shield_check_white.svg"))
        self.save_settings_button.clicked.connect(self.save_settings)
        right.addWidget(self.save_settings_button)
        save_note = QLabel("Изменения сохраняются в конфиг и сразу применяются к боту.")
        save_note.setProperty("muted", True)
        save_note.setWordWrap(True)
        right.addWidget(save_note)

        uninstall_group = Card(danger=True)
        uninstall_layout = QVBoxLayout(uninstall_group)
        uninstall_layout.setContentsMargins(12, 10, 12, 12)
        uninstall_layout.setSpacing(7)
        uninstall_title = QLabel("Удаление")
        uninstall_title.setStyleSheet("font-size: 13px; font-weight: 800; color: #e54848;")
        self.uninstall_note_label = QLabel("Удалит всю папку программы вместе с настройками. Файлы не попадут в корзину.")
        self.uninstall_note_label.setWordWrap(True)
        self.uninstall_note_label.setProperty("muted", True)
        self.uninstall_button = ActionButton("Удалить бота", "ghostDanger")
        self.uninstall_button.clicked.connect(self.confirm_self_uninstall)
        uninstall_layout.addWidget(uninstall_title)
        uninstall_layout.addWidget(self.uninstall_note_label)
        uninstall_layout.addWidget(self.uninstall_button)
        right.addWidget(uninstall_group)
        right.addStretch(1)
        main.addLayout(right, 0)
        layout.addLayout(main)
        self._refresh_uninstall_button()
        return page


    def _refresh_meal_action_controls(self) -> None:
        if hasattr(self, "food_depleted_action_card"):
            self.food_depleted_action_card.setEnabled(self.auto_meal_check.isChecked())
        if hasattr(self, "meal_thresholds_card"):
            self.meal_thresholds_card.setEnabled(self.auto_meal_check.isChecked())

    def _fish_keep_card(self, fish_id: str, title: str) -> tuple[QWidget, QCheckBox]:
        card = QFrame()
        card.setObjectName("fishKeepCard")
        card.setMinimumHeight(40)
        card.setMinimumWidth(0)
        layout = QHBoxLayout(card)
        layout.setContentsMargins(8, 6, 8, 6)
        layout.setSpacing(6)
        image = QLabel()
        image.setFixedSize(56, 29)
        image.setAlignment(Qt.AlignmentFlag.AlignCenter)
        pixmap = fish_ui_pixmap(fish_id, QSize(56, 29))
        if not pixmap.isNull():
            image.setPixmap(pixmap)
        layout.addWidget(image)
        name = QLabel(title)
        name.setStyleSheet("font-size: 10px; font-weight: 700; color: #17203c;")
        name.setWordWrap(True)
        layout.addWidget(name, 1)
        checkbox = ToggleSwitch("")
        checkbox.setToolTip("Оставлять")
        checkbox.setStyleSheet("font-size: 11px;")
        layout.addWidget(checkbox)
        return card, checkbox

    def _threshold_slider(self, label: str, parent_layout: QVBoxLayout) -> QSlider:
        row = QHBoxLayout()
        row.setSpacing(7)
        label_widget = QLabel(label)
        label_widget.setProperty("muted", True)
        value_label = Badge("90", "blue")
        value_label.setFixedWidth(48)
        slider = QSlider(Qt.Orientation.Horizontal)
        slider.setRange(1, 90)
        slider.setSingleStep(1)
        slider.setPageStep(5)
        slider.setValue(90)
        slider.valueChanged.connect(lambda value, badge=value_label: badge.setText(str(value)))
        row.addWidget(label_widget, 2)
        row.addWidget(slider, 3)
        row.addWidget(value_label)
        parent_layout.addLayout(row)
        return slider

    def _switch_card(self, title: str, subtitle: str, icon: str | Path, checkbox: QCheckBox) -> QWidget:
        card = SettingCard(title, subtitle, icon)
        card.add_widget(checkbox)
        return card

    def _combo_card(self, title: str, subtitle: str, icon: str | Path, combo: QComboBox) -> QWidget:
        card = SettingCard(title, subtitle, icon)
        card.add_widget(combo)
        return card

    def _switch_combo_card(self, title: str, subtitle: str, icon: str | Path, checkbox: QCheckBox, combo: QComboBox) -> QWidget:
        card = SettingCard(title, subtitle, icon)
        card.add_widget(checkbox)
        card.add_widget(combo)
        return card

    def _compact_form_row(self, label: str, widget: QWidget, *, label_stretch: int = 1, value_stretch: int = 0) -> QHBoxLayout:
        row = QHBoxLayout()
        row.setSpacing(10)
        label_widget = QLabel(label)
        label_widget.setProperty("muted", True)
        row.addWidget(label_widget, label_stretch)
        if isinstance(widget, QLineEdit):
            widget.setFixedWidth(90)
        else:
            widget.setMinimumWidth(90)
        row.addWidget(widget, value_stretch)
        return row

    def _build_stats_filter_card(self) -> QWidget:
        card = Card(soft=True)
        card.setMaximumHeight(66)
        layout = QHBoxLayout(card)
        layout.setContentsMargins(10, 8, 10, 8)
        layout.setSpacing(10)
        title_block = QVBoxLayout()
        title_block.setContentsMargins(0, 0, 0, 0)
        title_block.setSpacing(1)
        title = QLabel("Фильтр статистики")
        title.setProperty("sectionTitle", True)
        self.stats_filter_summary_label = QLabel("Показана текущая сессия")
        self.stats_filter_summary_label.setProperty("muted", True)
        self.stats_filter_summary_label.setStyleSheet("font-size: 10px;")
        title_block.addWidget(title)
        title_block.addWidget(self.stats_filter_summary_label)
        layout.addLayout(title_block, 1)

        controls = QHBoxLayout()
        controls.setSpacing(6)
        self.stats_filter_mode_combo = NonScrollingComboBox()
        self.stats_filter_mode_combo.addItem("Текущая сессия", STATS_FILTER_CURRENT)
        self.stats_filter_mode_combo.addItem("Конкретная сессия", STATS_FILTER_SESSION)
        self.stats_filter_mode_combo.addItem("Дата", STATS_FILTER_DATE)
        self.stats_filter_mode_combo.addItem("Диапазон дат", STATS_FILTER_RANGE)
        self.stats_filter_mode_combo.addItem("С даты", STATS_FILTER_SINCE)
        self.stats_filter_mode_combo.currentIndexChanged.connect(self._stats_filter_controls_changed)
        self.stats_filter_mode_combo.setFixedWidth(138)
        controls.addWidget(self.stats_filter_mode_combo, 0)

        self.stats_session_combo = NonScrollingComboBox()
        self.stats_session_combo.currentIndexChanged.connect(self._stats_filter_controls_changed)
        controls.addWidget(self.stats_session_combo, 2)

        self.stats_date_input = self._stats_date_input("дд.мм.гггг")
        self.stats_from_date_input = self._stats_date_input("с")
        self.stats_to_date_input = self._stats_date_input("по")
        controls.addWidget(self.stats_date_input, 0)
        controls.addWidget(self.stats_from_date_input, 0)
        controls.addWidget(self.stats_to_date_input, 0)

        self.stats_apply_filter_button = ActionButton("Применить фильтр", "primary", size="xs")
        self.stats_apply_filter_button.clicked.connect(self.apply_stats_filter)
        self.stats_return_current_button = ActionButton("К текущей", size="xs")
        self.stats_return_current_button.clicked.connect(self.return_to_current_stats_session)
        controls.addWidget(self.stats_apply_filter_button, 0)
        controls.addWidget(self.stats_return_current_button, 0)
        layout.addLayout(controls, 4)

        self._refresh_stats_session_combo()
        self._set_stats_filter_default_dates()
        self._update_stats_filter_controls()
        self._update_stats_filter_apply_state()
        return card

    def _stats_date_input(self, placeholder: str) -> QLineEdit:
        widget = QLineEdit()
        widget.setPlaceholderText(placeholder)
        widget.setFixedWidth(86)
        widget.setMaxLength(10)
        widget.setValidator(QRegularExpressionValidator(QRegularExpression(r"\d{0,2}(\.\d{0,2}(\.\d{0,4})?)?"), widget))
        widget.textEdited.connect(lambda _text, line_edit=widget: self._stats_date_text_edited(line_edit))
        widget.textChanged.connect(self._stats_filter_controls_changed)
        return widget

    def _stats_date_text_edited(self, widget: QLineEdit) -> None:
        formatted = self._format_stats_date_text(widget.text())
        if formatted != widget.text():
            widget.blockSignals(True)
            widget.setText(formatted)
            widget.setCursorPosition(len(formatted))
            widget.blockSignals(False)
        self._stats_filter_controls_changed()

    @staticmethod
    def _format_stats_date_text(value: str) -> str:
        digits = re.sub(r"\D", "", value)[:8]
        if len(digits) <= 2:
            return digits
        if len(digits) <= 4:
            return f"{digits[:2]}.{digits[2:]}"
        return f"{digits[:2]}.{digits[2:4]}.{digits[4:]}"

    def _refresh_stats_session_combo(self) -> None:
        if not hasattr(self, "stats_session_combo"):
            return
        current_id = self.stats_session_combo.currentData()
        self.stats_session_combo.blockSignals(True)
        self.stats_session_combo.clear()
        for record in self._stats_history_records:
            self.stats_session_combo.addItem(record.title(default_prices=self.session_stats.default_prices), record.session_id)
        if self.stats_session_combo.count() == 0:
            self.stats_session_combo.addItem("Сохранённых сессий нет", "")
        elif current_id:
            index = self.stats_session_combo.findData(current_id)
            if index >= 0:
                self.stats_session_combo.setCurrentIndex(index)
        self.stats_session_combo.blockSignals(False)

    def _set_stats_filter_default_dates(self) -> None:
        if not hasattr(self, "stats_from_date_input"):
            return
        first_day, last_day = self._stats_date_bounds()
        defaults = (
            (self.stats_date_input, last_day),
            (self.stats_from_date_input, first_day),
            (self.stats_to_date_input, last_day),
        )
        for widget, value in defaults:
            if not widget.text().strip():
                widget.setText(value.strftime("%d.%m.%Y"))

    def _stats_date_bounds(self) -> tuple[date, date]:
        days = [record.day for record in self._stats_history_records]
        if self.session_stats.has_catches():
            days.append(self.session_stats.started_at().date())
        if not days:
            today = datetime.now().date()
            return today, today
        return min(days), max(days)

    def _stats_filter_controls_changed(self, *_args) -> None:
        self._update_stats_filter_controls()
        self._update_stats_filter_apply_state()

    def _update_stats_filter_controls(self) -> None:
        if not hasattr(self, "stats_filter_mode_combo"):
            return
        mode = self.stats_filter_mode_combo.currentData()
        self.stats_session_combo.setVisible(mode == STATS_FILTER_SESSION)
        self.stats_date_input.setVisible(mode == STATS_FILTER_DATE)
        self.stats_from_date_input.setVisible(mode in {STATS_FILTER_RANGE, STATS_FILTER_SINCE})
        self.stats_to_date_input.setVisible(mode == STATS_FILTER_RANGE)
        self.stats_return_current_button.setVisible(self._stats_applied_filter_key != (STATS_FILTER_CURRENT,))
        self._set_stats_filter_default_dates()

    def _stats_filter_key_from_ui(self) -> tuple[object, ...]:
        mode = self.stats_filter_mode_combo.currentData() if hasattr(self, "stats_filter_mode_combo") else STATS_FILTER_CURRENT
        if mode == STATS_FILTER_SESSION:
            return (mode, self.stats_session_combo.currentData() or "")
        if mode == STATS_FILTER_DATE:
            return (mode, self.stats_date_input.text().strip())
        if mode == STATS_FILTER_RANGE:
            return (mode, self.stats_from_date_input.text().strip(), self.stats_to_date_input.text().strip())
        if mode == STATS_FILTER_SINCE:
            return (mode, self.stats_from_date_input.text().strip())
        return (STATS_FILTER_CURRENT,)

    def _update_stats_filter_apply_state(self) -> None:
        if not hasattr(self, "stats_apply_filter_button"):
            return
        self.stats_apply_filter_button.setEnabled(self._stats_filter_key_from_ui() != self._stats_applied_filter_key)

    def apply_stats_filter(self) -> None:
        self._set_stats_filter_default_dates()
        key = self._stats_filter_key_from_ui()
        try:
            stats, summary = self._stats_for_filter_key(key)
        except ValueError as exc:
            self.stats_filter_summary_label.setText(str(exc))
            return
        self._stats_display_stats = stats
        self._stats_applied_filter_key = key
        self.stats_filter_summary_label.setText(summary)
        self._invalidate_stats_view_cache()
        self._refresh_stats_tab(force=True)
        self._update_stats_filter_controls()
        self._update_stats_filter_apply_state()

    def return_to_current_stats_session(self) -> None:
        if not hasattr(self, "stats_filter_mode_combo"):
            return
        index = self.stats_filter_mode_combo.findData(STATS_FILTER_CURRENT)
        if index >= 0:
            self.stats_filter_mode_combo.setCurrentIndex(index)
        self.apply_stats_filter()

    def _stats_for_filter_key(self, key: tuple[object, ...]) -> tuple[FishingSessionStats, str]:
        mode = key[0] if key else STATS_FILTER_CURRENT
        if mode == STATS_FILTER_CURRENT:
            return self.session_stats, "Показана текущая сессия"
        if mode == STATS_FILTER_SESSION:
            session_id = str(key[1] if len(key) > 1 else "")
            record = next((item for item in self._stats_history_records if item.session_id == session_id), None)
            if record is None:
                return self._empty_stats_view(), "Сохранённых сессий нет"
            return record.to_stats(default_prices=self.session_stats.default_prices, custom_prices=self.session_stats.custom_prices), record.title(default_prices=self.session_stats.default_prices)
        if mode == STATS_FILTER_DATE:
            selected_day = self._parse_stats_filter_date(str(key[1] if len(key) > 1 else ""))
            records = [item for item in self._stats_history_records if item.day == selected_day]
            return self._stats_from_records(records), f"Дата: {selected_day.strftime('%d.%m.%Y')} · сессий: {len(records)}"
        if mode == STATS_FILTER_RANGE:
            start_day = self._parse_stats_filter_date(str(key[1] if len(key) > 1 else ""))
            end_day = self._parse_stats_filter_date(str(key[2] if len(key) > 2 else ""))
            if end_day < start_day:
                raise ValueError("Дата «по» должна быть не раньше даты «с»")
            records = [item for item in self._stats_history_records if start_day <= item.day <= end_day]
            return self._stats_from_records(records), f"{start_day.strftime('%d.%m.%Y')} — {end_day.strftime('%d.%m.%Y')} · сессий: {len(records)}"
        if mode == STATS_FILTER_SINCE:
            start_day = self._parse_stats_filter_date(str(key[1] if len(key) > 1 else ""))
            records = [item for item in self._stats_history_records if item.day >= start_day]
            return self._stats_from_records(records), f"С {start_day.strftime('%d.%m.%Y')} · сессий: {len(records)}"
        return self.session_stats, "Показана текущая сессия"

    @staticmethod
    def _parse_stats_filter_date(value: str) -> date:
        text = value.strip()
        try:
            return datetime.strptime(text, "%d.%m.%Y").date()
        except ValueError as exc:
            raise ValueError("Введите дату в формате дд.мм.гггг") from exc

    def _empty_stats_view(self) -> FishingSessionStats:
        return FishingSessionStats(default_prices=self.session_stats.default_prices, custom_prices=self.session_stats.custom_prices)

    def _stats_from_records(self, records: list[StoredFishingSession]) -> FishingSessionStats:
        stats_items = [
            record.to_stats(default_prices=self.session_stats.default_prices, custom_prices=self.session_stats.custom_prices)
            for record in records
        ]
        return FishingSessionStats.aggregate(
            stats_items,
            default_prices=self.session_stats.default_prices,
            custom_prices=self.session_stats.custom_prices,
        )

    def _stats_source(self) -> FishingSessionStats:
        return self.session_stats if self._stats_applied_filter_key == (STATS_FILTER_CURRENT,) else self._stats_display_stats

    def _is_current_stats_view(self) -> bool:
        return self._stats_applied_filter_key == (STATS_FILTER_CURRENT,)

    def _invalidate_stats_view_cache(self) -> None:
        self._stats_table_signature = None
        self._stats_metrics_signature = None
        self._catch_size_signature = None

    def _build_statistics_tab(self) -> QWidget:
        page, layout = self._page("Статистика", "Подробная статистика рыбалки, размеров улова и доходов.")
        layout.addWidget(self._build_stats_filter_card())
        actions = QHBoxLayout()
        actions.addStretch(1)
        self.reset_stats_button = ActionButton("Сбросить сессию", icon=ui_icon("reload.svg"))
        self.reset_stats_button.clicked.connect(self.reset_session_stats)
        self.export_stats_button = ActionButton("Выгрузить CSV", icon=ui_icon("download.svg"))
        self.export_stats_button.clicked.connect(self.export_stats_csv)
        actions.addWidget(self.reset_stats_button)
        actions.addWidget(self.export_stats_button)
        layout.addLayout(actions)

        metrics = QGridLayout()
        metrics.setSpacing(9)
        self.stats_duration_label = MetricCard("Время рыбалки", "0 мин", ui_icon("clock.svg"))
        self.stats_caught_label = MetricCard("Поймано", "0 шт · 0 кг", ui_icon("fish_solid.svg"))
        self.stats_released_label = MetricCard("Отпущено", "0 шт · 0 кг", ui_icon("fish.svg"))
        self.stats_kept_label = MetricCard("Общий вес", "0 кг", ui_icon("weigher.svg"))
        self.stats_income_label = MetricCard("Доход", "0 $", ui_icon("dollar.svg"))
        self.stats_income_per_hour_label = MetricCard("Доход в час", "0 $", ui_icon("profit.svg"))
        for index, widget in enumerate((
            self.stats_duration_label,
            self.stats_caught_label,
            self.stats_released_label,
            self.stats_kept_label,
            self.stats_income_label,
            self.stats_income_per_hour_label,
        )):
            metrics.addWidget(widget, index // 3, index % 3)
        layout.addLayout(metrics)

        body = QHBoxLayout()
        body.setSpacing(12)
        table_group = Card()
        table_layout = QVBoxLayout(table_group)
        table_layout.setContentsMargins(12, 10, 12, 12)
        table_layout.setSpacing(7)
        table_title = QLabel("Статистика по рыбе")
        table_title.setProperty("sectionTitle", True)
        table_layout.addWidget(table_title)
        self.stats_table = QTableWidget(0, 6)
        self.stats_table.setMinimumHeight(260)
        self.stats_table.setHorizontalHeaderLabels(["Рыба", "Поймано", "Отпущено", "Цена", "Своя цена", "Доход"])
        self.stats_table.horizontalHeader().setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        self.stats_table.horizontalHeader().setMinimumSectionSize(58)
        self.stats_table.setAlternatingRowColors(True)
        self.stats_table.verticalHeader().setVisible(False)
        self.stats_table.setShowGrid(False)
        self.stats_table.setIconSize(QSize(36, 24))
        self.stats_table.verticalHeader().setDefaultSectionSize(32)
        self.stats_price_delegate = DigitsOnlyDelegate(self.stats_table)
        self.stats_table.setItemDelegateForColumn(4, self.stats_price_delegate)
        self.stats_table.itemChanged.connect(self._stats_price_changed)
        table_layout.addWidget(self.stats_table, 1)
        body.addWidget(table_group, 4)

        catch_size_group = Card()
        catch_size_group.setMinimumWidth(250)
        catch_size_group.setMaximumWidth(290)
        catch_size_layout = QVBoxLayout(catch_size_group)
        catch_size_layout.setContentsMargins(12, 10, 12, 12)
        catch_size_title = QLabel("Статистика по типу улова")
        catch_size_title.setProperty("sectionTitle", True)
        catch_size_layout.addWidget(catch_size_title)
        catch_body = QHBoxLayout()
        catch_body.setSpacing(12)
        self.catch_size_chart = CatchSizeDonut()
        self.catch_size_legend_layout = QVBoxLayout()
        self.catch_size_legend_layout.setSpacing(6)
        catch_body.addWidget(self.catch_size_chart, 0, Qt.AlignmentFlag.AlignVCenter)
        catch_body.addLayout(self.catch_size_legend_layout, 1)
        catch_size_layout.addLayout(catch_body)
        body.addWidget(catch_size_group, 1)
        layout.addLayout(body, 1)
        self._refresh_stats_tab()
        return page

    def _build_telegram_tab(self) -> QWidget:
        page, layout = self._page("Telegram", "Настройки бота и уведомлений.")
        row = QHBoxLayout()
        row.setSpacing(12)
        group = Card()
        form = QVBoxLayout(group)
        form.setContentsMargins(13, 12, 13, 13)
        form.setSpacing(9)
        title = QLabel("Бот")
        title.setProperty("sectionTitle", True)
        self.telegram_enabled_check = ToggleSwitch("Telegram включён")
        self.telegram_token_input = QLineEdit()
        self.telegram_token_input.setEchoMode(QLineEdit.EchoMode.Password)
        self.telegram_token_input.setPlaceholderText("Токен бота")
        self.telegram_admins_input = QLineEdit()
        self.telegram_admins_input.setPlaceholderText("123456789, 987654321")
        form.addWidget(title)
        form.addWidget(self.telegram_enabled_check)
        form.addLayout(self._field_block("Токен бота", self.telegram_token_input))
        form.addLayout(self._field_block("ID администраторов", self.telegram_admins_input))
        button = ActionButton("Сохранить Telegram", "primary", icon=ui_icon("telegram_outline_white.svg"))
        button.clicked.connect(self.save_settings)
        form.addStretch(1)
        form.addWidget(button)
        row.addWidget(group, 1)

        notify = Card()
        notify_layout = QVBoxLayout(notify)
        notify_layout.setContentsMargins(13, 12, 13, 13)
        notify_layout.setSpacing(7)
        notify_title = QLabel("Уведомления")
        notify_title.setProperty("sectionTitle", True)
        self.telegram_notify_catch_check = ToggleSwitch("Улов")
        self.telegram_notify_start_stop_check = ToggleSwitch("Запуск / остановка")
        self.telegram_notify_meal_check = ToggleSwitch("Питание")
        self.telegram_notify_inventory_full_check = ToggleSwitch("Закончилось место")
        self.telegram_notify_inventory_space_low_check = ToggleSwitch("Оповещать, когда места в инвентаре меньше, чем:")
        self.telegram_inventory_space_low_input = QLineEdit()
        self.telegram_inventory_space_low_input.setPlaceholderText("1.00")
        self.telegram_inventory_space_low_input.setValidator(
            QRegularExpressionValidator(QRegularExpression(r"\d{0,6}([\.,]\d{0,2})?"), self.telegram_inventory_space_low_input)
        )
        self.telegram_inventory_space_low_input.editingFinished.connect(self._normalize_inventory_space_threshold_input)
        self.telegram_notify_bait_tired_check = ToggleSwitch("Рыба устала от приманки")
        self.telegram_notify_focus_lost_check = ToggleSwitch("Потеря фокуса игры")
        notify_layout.addWidget(notify_title)
        for checkbox in (
            self.telegram_notify_catch_check,
            self.telegram_notify_start_stop_check,
            self.telegram_notify_meal_check,
            self.telegram_notify_inventory_full_check,
            self.telegram_notify_inventory_space_low_check,
            self.telegram_notify_bait_tired_check,
            self.telegram_notify_focus_lost_check,
        ):
            notify_layout.addWidget(checkbox)
            if checkbox is self.telegram_notify_inventory_space_low_check:
                threshold_row = QHBoxLayout()
                threshold_row.setSpacing(8)
                threshold_row.addWidget(self.telegram_inventory_space_low_input)
                threshold_unit = QLabel("кг.")
                threshold_unit.setProperty("muted", True)
                threshold_row.addWidget(threshold_unit)
                notify_layout.addLayout(threshold_row)
        notify_layout.addStretch(1)
        row.addWidget(notify, 1)
        layout.addLayout(row, 1)
        return page

    def _field_block(self, label: str, widget: QWidget) -> QVBoxLayout:
        block = QVBoxLayout()
        block.setSpacing(4)
        label_widget = QLabel(label)
        label_widget.setProperty("muted", True)
        block.addWidget(label_widget)
        block.addWidget(widget)
        return block

    def _normalize_inventory_space_threshold_input(self) -> None:
        if not hasattr(self, "telegram_inventory_space_low_input"):
            return
        value = self._parse_inventory_space_threshold(self.telegram_inventory_space_low_input.text())
        self.telegram_inventory_space_low_input.setText(f"{value:.2f}")

    @staticmethod
    def _parse_inventory_space_threshold(value: str) -> float:
        try:
            return max(1.0, round(float(value.replace(",", ".")), 2))
        except ValueError:
            return 1.0

    def _build_stream_tab(self) -> QWidget:
        page, layout = self._page("Стрим", "Управление трансляцией и производительностью стрима.")
        top = QHBoxLayout()
        top.setSpacing(12)

        status_group = Card()
        status_group.setMinimumHeight(230)
        status_layout = QVBoxLayout(status_group)
        status_layout.setContentsMargins(13, 12, 13, 13)
        status_layout.setSpacing(7)
        title = QLabel("Управление стримом")
        title.setProperty("sectionTitle", True)
        status_layout.addWidget(title)
        self.stream_status_label = QLabel("offline")
        self.stream_area_label = QLabel("Все окно")
        self.stream_quality_label = QLabel("720p")
        self.stream_auto_stop_label = QLabel("—")
        self.stream_url_label = ExternalLinkLabel("—")
        self.stream_url_label.setWordWrap(False)
        self.stream_url_label.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Fixed)
        self.stream_url_label.setMaximumHeight(22)
        for label, widget in (
            ("Статус", self.stream_status_label),
            ("Область", self.stream_area_label),
            ("Качество", self.stream_quality_label),
            ("Автостоп", self.stream_auto_stop_label),
            ("Stream URL", self.stream_url_label),
        ):
            status_layout.addLayout(self._compact_form_row(label, widget, label_stretch=2, value_stretch=1))
        buttons = QHBoxLayout()
        buttons.setSpacing(9)
        self.stream_start_button = ActionButton("Запустить стрим", "primary", icon=ui_icon("play_white.svg"), size="l")
        self.stream_start_button.clicked.connect(self.start_stream)
        self.stream_stop_button = ActionButton("Остановить стрим", "danger", icon=ui_icon("stop_white.svg"), size="l")
        self.stream_stop_button.clicked.connect(self.stop_stream)
        self.stream_chat_mode_button = ActionButton("Включить режим чата", icon=ui_icon("chat_window.svg"), size="l")
        self.stream_chat_mode_button.clicked.connect(self.enable_chat_mode)
        buttons.addWidget(self.stream_start_button)
        buttons.addWidget(self.stream_stop_button)
        buttons.addWidget(self.stream_chat_mode_button)
        status_layout.addStretch(1)
        status_layout.addLayout(buttons)
        top.addWidget(status_group, 3)

        side = QVBoxLayout()
        side.setSpacing(12)
        telegram_group = Card()
        telegram_group.setMinimumHeight(112)
        telegram_layout = QVBoxLayout(telegram_group)
        telegram_layout.setContentsMargins(13, 12, 13, 13)
        telegram_layout.setSpacing(6)
        telegram_header = QHBoxLayout()
        telegram_header.addWidget(IconLabel(ui_icon("telegram_color.svg"), 20))
        telegram_title = QLabel("Telegram")
        telegram_title.setProperty("sectionTitle", True)
        self.stream_telegram_badge = Badge("Отключен", "gray")
        telegram_header.addWidget(telegram_title, 1)
        telegram_header.addWidget(self.stream_telegram_badge)
        telegram_layout.addLayout(telegram_header)
        self.stream_telegram_status_label = QLabel("Бот отключён")
        self.stream_telegram_status_label.setProperty("muted", True)
        self.stream_telegram_admins_label = QLabel("Chat ID: —")
        self.stream_telegram_admins_label.setProperty("muted", True)
        telegram_layout.addWidget(self.stream_telegram_status_label)
        telegram_layout.addWidget(self.stream_telegram_admins_label)
        side.addWidget(telegram_group)

        license_group = Card()
        license_group.setMinimumHeight(100)
        license_layout = QVBoxLayout(license_group)
        license_layout.setContentsMargins(13, 12, 13, 13)
        license_layout.setSpacing(6)
        license_title = QLabel("Лицензия и аккаунт")
        license_title.setProperty("sectionTitle", True)
        self.stream_license_status_label = QLabel("Статус: —")
        self.stream_license_status_label.setProperty("muted", True)
        self.stream_license_expires_label = QLabel("Действует до: —")
        self.stream_license_expires_label.setProperty("muted", True)
        license_layout.addWidget(license_title)
        license_layout.addWidget(self.stream_license_status_label)
        license_layout.addWidget(self.stream_license_expires_label)
        side.addWidget(license_group)
        top.addLayout(side, 2)
        layout.addLayout(top, 3)

        options = QHBoxLayout()
        options.setSpacing(12)
        quality_group = Card()
        quality_layout = QVBoxLayout(quality_group)
        quality_layout.setContentsMargins(13, 12, 13, 13)
        quality_layout.setSpacing(8)
        quality_title = QLabel("Качество стрима")
        quality_title.setProperty("sectionTitle", True)
        self.stream_quality_combo = NonScrollingComboBox()
        self.stream_quality_combo.addItems(["480p", "720p", "1080p"])
        self.stream_quality_combo.setCurrentText("720p")
        self.stream_quality_combo.currentTextChanged.connect(self._stream_quality_changed)
        quality_note = QLabel("Разрешение и битрейт трансляции.")
        quality_note.setProperty("muted", True)
        quality_note.setWordWrap(True)
        quality_layout.addWidget(quality_title)
        quality_layout.addWidget(quality_note)
        quality_layout.addWidget(self.stream_quality_combo)
        options.addWidget(quality_group, 1)

        chat_group = Card()
        chat_layout = QVBoxLayout(chat_group)
        chat_layout.setContentsMargins(13, 12, 13, 13)
        chat_layout.setSpacing(8)
        chat_title = QLabel("Увеличить чат")
        chat_title.setProperty("sectionTitle", True)
        chat_note = QLabel("Крупная область чата для лучшей читаемости.")
        chat_note.setProperty("muted", True)
        chat_note.setWordWrap(True)
        self.stream_chat_zoom_check = ToggleSwitch("Увеличить чат")
        self.stream_chat_zoom_check.stateChanged.connect(self._stream_chat_zoom_changed)
        chat_layout.addWidget(chat_title)
        chat_layout.addWidget(chat_note)
        chat_layout.addStretch(1)
        chat_layout.addWidget(self.stream_chat_zoom_check)
        options.addWidget(chat_group, 1)

        fps_group = Card()
        fps_layout = QVBoxLayout(fps_group)
        fps_layout.setContentsMargins(13, 12, 13, 13)
        fps_layout.setSpacing(8)
        fps_title = QLabel("Режим 10fps")
        fps_title.setProperty("sectionTitle", True)
        fps_layout.addWidget(fps_title)
        fps_layout.addWidget(icon_widget(ui_icon("gauge_10fps.png"), 58), 0, Qt.AlignmentFlag.AlignCenter)
        self.stream_snapshot_mode_check = ToggleSwitch("Режим 10fps")
        self.stream_snapshot_mode_check.stateChanged.connect(self._stream_snapshot_mode_changed)
        fps_layout.addStretch(1)
        fps_layout.addWidget(self.stream_snapshot_mode_check)
        options.addWidget(fps_group, 1)
        layout.addLayout(options, 2)

        perf = Card()
        perf_layout = QVBoxLayout(perf)
        perf_layout.setContentsMargins(12, 10, 12, 12)
        perf_title = QLabel("Текущая сессия стрима")
        perf_title.setProperty("sectionTitle", True)
        perf_layout.addWidget(perf_title)
        perf_metrics = QHBoxLayout()
        perf_metrics.setSpacing(9)
        self.stream_fps_metric = MetricCard("Целевой FPS", "30", ui_icon("gauge_10fps.png"))
        self.stream_bitrate_metric = MetricCard("Битрейт профиля", "2900k", ui_icon("profit.svg"))
        self.stream_mode_metric = MetricCard("Режим", "Обычный", ui_icon("frame.svg"))
        self.stream_uptime_metric = MetricCard("Время стрима", "—", ui_icon("timer.svg"))
        for metric in (self.stream_fps_metric, self.stream_bitrate_metric, self.stream_mode_metric, self.stream_uptime_metric):
            perf_metrics.addWidget(metric)
        perf_layout.addLayout(perf_metrics)
        layout.addWidget(perf, 1)
        self._refresh_overview_telegram_card()
        self._refresh_stream_license_card()
        self._refresh_stream_tab()
        return page

    def _build_about_tab(self) -> QWidget:
        page, layout = self._page("О приложении", "Версия приложения, состояние обновления и сведения о билде.")
        top = QHBoxLayout()
        top.setSpacing(12)

        version_card = Card()
        version_layout = QVBoxLayout(version_card)
        version_layout.setContentsMargins(13, 12, 13, 13)
        version_layout.setSpacing(9)
        title = QLabel("Текущая версия")
        title.setProperty("sectionTitle", True)
        self.about_current_version_label = QLabel(f"v{APP_VERSION}")
        self.about_current_version_label.setProperty("title", True)
        self.about_build_hash_label = QLabel(f"Билд: {APP_BUILD_HASH or 'dev'}")
        self.about_build_hash_label.setProperty("muted", True)
        version_layout.addWidget(title)
        version_layout.addWidget(self.about_current_version_label)
        version_layout.addWidget(self.about_build_hash_label)
        top.addWidget(version_card, 1)

        app_card = Card()
        app_layout = QVBoxLayout(app_card)
        app_layout.setContentsMargins(13, 12, 13, 13)
        app_layout.setSpacing(8)
        app_title = QLabel(APP_NAME)
        app_title.setProperty("sectionTitle", True)
        app_note = QLabel("Автоматизация рыбалки, уведомления и локальный стрим для Majestic RP.")
        app_note.setWordWrap(True)
        app_note.setProperty("muted", True)
        app_layout.addWidget(app_title)
        app_layout.addWidget(app_note)
        app_layout.addStretch(1)
        top.addWidget(app_card, 1)

        layout.addLayout(top)
        layout.addWidget(self._build_update_card())
        layout.addStretch(1)
        return page

    def _load_settings_to_ui(self, settings: SonarSettings) -> None:
        fishing = settings.fishing
        self.auto_meal_check.setChecked(fishing.auto_meal)
        self.restore_food_slider.setValue(fishing.restore_food_from)
        self.restore_water_slider.setValue(fishing.restore_water_from)
        if hasattr(self, "restore_health_slider"):
            self.restore_health_slider.setValue(fishing.restore_health_from)
        self.auto_change_bait_check.setChecked(fishing.auto_change_bait)
        self.store_trunk_check.setChecked(fishing.store_in_trunk)
        self.start_stop_sound_check.setChecked(fishing.start_stop_sound_enabled)
        index = self.overweight_action_combo.findData(fishing.overweight_action)
        self.overweight_action_combo.setCurrentIndex(max(index, 0))
        self.fish_without_leader_check.setChecked(fishing.fish_without_leader)
        index = self.leader_depleted_action_combo.findData(fishing.leader_depleted_action)
        self.leader_depleted_action_combo.setCurrentIndex(max(index, 0))
        self.fish_without_net_check.setChecked(fishing.fish_without_net)
        index = self.net_depleted_action_combo.findData(fishing.net_depleted_action)
        self.net_depleted_action_combo.setCurrentIndex(max(index, 0))
        index = self.equipment_depleted_action_combo.findData(fishing.equipment_depleted_action)
        self.equipment_depleted_action_combo.setCurrentIndex(max(index, 0))
        index = self.food_depleted_action_combo.findData(fishing.food_depleted_action)
        self.food_depleted_action_combo.setCurrentIndex(max(index, 0))
        self._refresh_tackle_action_controls()
        self._refresh_meal_action_controls()
        self.hotkey_input.set_hotkey(fishing.hotkey)
        self.inventory_hotkey_input.set_hotkey(fishing.inventory_hotkey)
        self.use_item_hotkey_input.set_hotkey(fishing.use_item_hotkey)
        self.backpack_move_hotkey_input.set_hotkey(fishing.backpack_move_hotkey)
        self.discard_key_input.set_hotkey(fishing.discard_key)
        self.chat_hotkey_input.set_hotkey(fishing.chat_hotkey)
        for badge in getattr(self, "_hotkey_badges", []):
            badge.setText(fishing.hotkey)
        for key, checkbox in getattr(self, "garbage_checks", {}).items():
            checkbox.setChecked(fishing.garbage_settings.get(key, True))
        if hasattr(self, "stream_snapshot_mode_check"):
            self.stream_snapshot_mode_check.setChecked(fishing.stream_snapshot_mode)
        for fish_id, checkbox in self.fish_checks.items():
            checkbox.setChecked(fishing.fish_settings.get(fish_id, True))
        self._apply_telegram_settings_to_ui(settings.telegram)

    def _refresh_tackle_action_controls(self, *args) -> None:
        del args
        if hasattr(self, "leader_depleted_action_combo"):
            self.leader_depleted_action_combo.setEnabled(not self.fish_without_leader_check.isChecked())
        if hasattr(self, "net_depleted_action_combo"):
            self.net_depleted_action_combo.setEnabled(not self.fish_without_net_check.isChecked())

    def _apply_telegram_settings_to_ui(self, telegram) -> None:
        widgets = (
            self.telegram_enabled_check,
            self.telegram_token_input,
            self.telegram_admins_input,
            self.telegram_notify_catch_check,
            self.telegram_notify_start_stop_check,
            self.telegram_notify_meal_check,
            self.telegram_notify_inventory_full_check,
            self.telegram_notify_inventory_space_low_check,
            self.telegram_inventory_space_low_input,
            self.telegram_notify_bait_tired_check,
            self.telegram_notify_focus_lost_check,
        )
        old_states = [widget.blockSignals(True) for widget in widgets]
        try:
            self.telegram_enabled_check.setChecked(telegram.enabled)
            self.telegram_token_input.setText(telegram.bot_token)
            self.telegram_admins_input.setText(",".join(str(item) for item in telegram.admin_ids))
            self.telegram_notify_catch_check.setChecked(telegram.notify_catch)
            self.telegram_notify_start_stop_check.setChecked(telegram.notify_start_stop)
            self.telegram_notify_meal_check.setChecked(telegram.notify_meal)
            self.telegram_notify_inventory_full_check.setChecked(telegram.notify_inventory_full)
            self.telegram_notify_inventory_space_low_check.setChecked(telegram.notify_inventory_space_low)
            self.telegram_inventory_space_low_input.setText(f"{telegram.inventory_space_low_threshold_kg:.2f}")
            self.telegram_notify_bait_tired_check.setChecked(telegram.notify_bait_tired)
            self.telegram_notify_focus_lost_check.setChecked(telegram.notify_focus_lost)
        finally:
            for widget, old_state in zip(widgets, old_states):
                widget.blockSignals(old_state)
        self._refresh_overview_telegram_card()

    def _refresh_overview_telegram_card(self) -> None:
        if not hasattr(self, "overview_telegram_badge"):
            return
        telegram = self.settings.telegram
        enabled = bool(telegram.enabled)
        self.overview_telegram_badge.setText("Подключен" if enabled else "Отключен")
        self.overview_telegram_badge.set_tone("green" if enabled else "gray")
        self.overview_telegram_description.setText(
            "Бот активен и принимает команды." if enabled else "Бот отключён. Уведомления не отправляются."
        )
        chat_id = ", ".join(str(item) for item in telegram.admin_ids[:2])
        if len(telegram.admin_ids) > 2:
            chat_id = f"{chat_id}, +{len(telegram.admin_ids) - 2}"
        self.overview_telegram_chat_id_label.setText(chat_id or "—")
        self.overview_telegram_status_label.setText("Онлайн" if enabled else "Оффлайн")
        notification_count = sum(
            bool(item)
            for item in (
                telegram.notify_catch,
                telegram.notify_start_stop,
                telegram.notify_meal,
                telegram.notify_inventory_full,
                telegram.notify_inventory_space_low,
                telegram.notify_bait_tired,
                telegram.notify_focus_lost,
            )
        )
        self.overview_telegram_notifications_label.setText(f"{notification_count} типов")
        if hasattr(self, "stream_telegram_badge"):
            self.stream_telegram_badge.setText("Подключен" if enabled else "Отключен")
            self.stream_telegram_badge.set_tone("green" if enabled else "gray")
            self.stream_telegram_status_label.setText("Бот принимает команды" if enabled else "Бот отключён")
            self.stream_telegram_admins_label.setText(f"Chat ID: {chat_id or '—'}")

    def _refresh_overview_stream_card(self) -> None:
        if not hasattr(self, "overview_stream_badge"):
            return
        snapshot = self.stream_service.snapshot()
        active = bool(snapshot.active)
        self.overview_stream_badge.setText("Активен" if active else "Ожидание")
        self.overview_stream_badge.set_tone("green" if active else "gray")
        if snapshot.error:
            self.overview_stream_description.setText(snapshot.error)
        else:
            self.overview_stream_description.setText("Трансляция запущена." if active else "Трансляция ожидает запуска.")
        self.overview_stream_status_label.setText("Онлайн" if active else str(snapshot.status or "Оффлайн"))
        self.overview_stream_quality_label.setText(str(snapshot.quality or "—"))
        self.overview_stream_mode_label.setText("10fps" if snapshot.snapshot_mode_enabled else "Обычный")

    def _refresh_stream_license_card(self) -> None:
        if not hasattr(self, "stream_license_status_label"):
            return
        status = self.license_status
        if status.valid:
            expires = self._format_license_expiry(status.expires_at)
            self.stream_license_status_label.setText("Статус: активна")
            self.stream_license_expires_label.setText(f"Действует до: {expires}")
        else:
            self.stream_license_status_label.setText("Статус: не активна")
            self.stream_license_expires_label.setText("Действует до: —")

    def _handle_telegram_settings_changed(self, telegram_settings: object) -> None:
        if not hasattr(telegram_settings, "to_dict"):
            return
        self.settings = self.config_manager.load()
        self._apply_telegram_settings_to_ui(self.settings.telegram)

    def activate_license(self) -> None:
        key = self.license_key_input.text().strip()
        if not key:
            self.license_status_label.setText("Введите ключ лицензии")
            return
        self._run_license_check(key)

    def _start_saved_license_check(self) -> None:
        if self.settings.license.license_key:
            self._run_license_check(self.settings.license.license_key)
        else:
            self.license_status = LicenseStatus(valid=False, error="Лицензия не введена")
            self._refresh_license_ui()

    def _run_license_check(self, key: str, *, pending_bot_start: bool = False) -> None:
        key = key.strip()
        if pending_bot_start:
            self._pending_bot_start_after_license = True
        if not key:
            return
        if self._license_checking:
            return
        self._license_checking = True
        self.license_activate_button.setEnabled(False)
        self.license_status_label.setText("Проверяем лицензию...")

        def worker() -> None:
            status = self.license_manager.validate_key(key)
            self.license_bridge.result.emit(status)

        threading.Thread(target=worker, name="sonar-license-check", daemon=True).start()

    def _handle_license_result(self, status: object) -> None:
        if not isinstance(status, LicenseStatus):
            return
        self._license_checking = False
        self.license_activate_button.setEnabled(True)
        self.license_status = status
        self._schedule_next_license_refresh(status)
        self.settings = self.config_manager.load()
        if status.valid:
            self.bot.reload_settings()
        self._refresh_license_ui()
        self._apply_license_gate()
        self._refresh_update_block()
        if self._pending_bot_start_after_license:
            self._pending_bot_start_after_license = False
            if self._has_active_license():
                self._start_bot_now()
            else:
                self._select_page(self.license_tab)
                self.status_label.setText("Лицензия не активна")
                self.append_log("Лицензия не активна")

    def _has_active_license(self) -> bool:
        return self.license_status.valid and not self.license_status.expired

    def _license_context(self) -> LicenseContext:
        return LicenseContext.from_status(self.license_status)

    def _can_use_feature(self, feature_key: str) -> bool:
        return self._license_context().can(feature_key)

    def _can_start_fishing(self) -> bool:
        return self._can_use_feature(FEATURE_FISHING)

    def _schedule_next_license_refresh(self, status: LicenseStatus) -> None:
        now = datetime.now(timezone.utc)
        next_refresh = now.timestamp() + LICENSE_REFRESH_INTERVAL_SECONDS
        if status.valid and status.expires_at is not None:
            next_refresh = min(next_refresh, status.expires_at.timestamp())
        self._next_license_refresh_at = datetime.fromtimestamp(next_refresh, timezone.utc)

    def _current_license_key(self) -> str:
        return (
            self.license_key_input.text().strip()
            or self.license_status.license_key.strip()
            or self.settings.license.license_key.strip()
        )

    def _apply_license_gate(self) -> None:
        if not hasattr(self, "stack") or not hasattr(self, "license_tab"):
            return
        active = self._has_active_license()
        context = self._license_context()
        allowed_pages = apply_page_feature_gate(
            page_features=getattr(self, "_licensed_page_features", {}),
            nav_buttons=self._nav_buttons,
            license_context=context,
        )
        if hasattr(self, "bot"):
            self.bot.notification_manager.set_runtime_enabled(self._can_use_feature(FEATURE_TELEGRAM))
        if active and not self._can_use_feature(FEATURE_STREAM_CHAT) and hasattr(self, "stream_service"):
            snapshot = self.stream_service.snapshot()
            if snapshot.chat_mode_enabled:
                self.stream_service.disable_chat_mode(force=True)
        if not active:
            self._select_page(self.license_tab)
            if hasattr(self, "bot") and self.bot.state.running:
                self.bot.stop()
            if hasattr(self, "stream_service"):
                self.stream_service.stop_stream("license inactive")
        elif self.stack.currentWidget() in self._licensed_page_features and self.stack.currentWidget() not in allowed_pages:
            self._select_page(allowed_pages[0] if allowed_pages else self.license_tab)
        if active and not self._can_use_feature(FEATURE_FISHING) and hasattr(self, "bot") and self.bot.state.running:
            self.bot.stop()
        if active and not self._can_use_feature(FEATURE_STREAM) and hasattr(self, "stream_service"):
            self.stream_service.stop_stream("stream feature inactive")
        if active and self.stack.currentWidget() is self.license_tab:
            self._select_page(fallback_page(preferred=self.overview_tab, license_page=self.license_tab, allowed_pages=allowed_pages))

    def _refresh_license_ui(self) -> None:
        if not hasattr(self, "license_summary_label"):
            return
        status = self.license_status
        if status.valid:
            expires = self._format_license_expiry(status.expires_at)
            left = self._format_license_left(status.expires_at)
            self.license_summary_label.setText(f"Лицензия {status.masked_key}")
            self.license_status_label.setText(f"Статус: активна\nИстекает: {expires}\nОсталось: {left}")
            self.license_key_input.setText(status.license_key)
            self.license_account_status.set_value("Активна")
            self.license_account_expiry.set_value(expires)
            self.license_account_role.set_value(status.role or "user")
            self.sidebar_license_title.setText("Лицензия активна")
            self.sidebar_license_subtitle.setText(f"до {expires}")
            if hasattr(self, "sidebar_license_icon"):
                self.sidebar_license_icon.set_color("#31c65b")
            for label in getattr(self, "_license_overview_lines", []):
                label.setText(f"Лицензия: активна до {expires}")
        else:
            error = status.error or "Лицензия не активна"
            self.license_summary_label.setText("Введите ключ лицензии")
            self.license_status_label.setText(f"Статус: не активна\n{error}")
            self.license_account_status.set_value("Не активна")
            self.license_account_expiry.set_value("—")
            self.license_account_role.set_value("user")
            self.sidebar_license_title.setText("Лицензия не активна")
            self.sidebar_license_subtitle.setText("нужна активация")
            if hasattr(self, "sidebar_license_icon"):
                self.sidebar_license_icon.set_color("#e54848")
            for label in getattr(self, "_license_overview_lines", []):
                label.setText("Лицензия: не активна")
        self._refresh_sidebar_version_status()
        self._refresh_stream_license_card()

    def _license_tick(self) -> None:
        self._refresh_license_ui()
        now = datetime.now(timezone.utc)
        if self.license_status.expires_at is not None and self.license_status.expires_at <= now:
            self._apply_license_gate()
        key = self._current_license_key()
        should_refresh = key and not self._license_checking and (
            self._next_license_refresh_at is None
            or now >= self._next_license_refresh_at
            or (self.license_status.valid and self.license_status.expires_at is not None and now >= self.license_status.expires_at)
        )
        if should_refresh:
            self._run_license_check(key)
        if self._has_active_license():
            self._refresh_update_block()

    def _refresh_update_block(self) -> None:
        self._refresh_sidebar_version_status()
        if hasattr(self, "about_current_version_label"):
            self.about_current_version_label.setText(f"v{APP_VERSION}")
        if not hasattr(self, "update_group"):
            return
        if not self._has_active_license():
            self.update_group.hide()
            return
        latest = self.license_status.latest_version.strip()
        if not is_update_available(latest):
            self.update_download_link.setText("")
            self.update_download_link.setToolTip("")
            self.update_download_link.hide()
            self.update_group.hide()
            return
        message = normalize_update_message_text(self.license_status.update_message).strip()
        download_link = self.license_status.download_link.strip()
        text = f"Доступна новая версия: v{latest}"
        if message:
            text = f"{text}\n{message}"
        self.update_label.setText(format_update_message_html(text))
        if download_link:
            self.update_download_link.setText(format_download_link_html(download_link))
            self.update_download_link.setToolTip(download_link)
            self.update_download_link.show()
        else:
            self.update_download_link.hide()
        self.update_group.show()

    def _refresh_sidebar_version_status(self) -> None:
        if hasattr(self, "sidebar_version_label"):
            self.sidebar_version_label.setText(f"Текущая версия: v{APP_VERSION}")
        if not hasattr(self, "sidebar_update_label"):
            return
        latest = self.license_status.latest_version.strip()
        if self._has_active_license() and is_update_available(latest):
            self.sidebar_update_label.setText(f"Доступна новая версия: v{latest}")
            self.sidebar_update_label.show()
        else:
            self.sidebar_update_label.hide()

    @staticmethod
    def _format_license_expiry(value: datetime | None) -> str:
        if value is None:
            return "бессрочно"
        return value.astimezone().strftime("%d.%m.%Y %H:%M")

    @staticmethod
    def _format_license_left(value: datetime | None) -> str:
        if value is None:
            return "бессрочно"
        seconds = max(0, int((value - datetime.now(timezone.utc)).total_seconds()))
        days, remainder = divmod(seconds, 86400)
        hours, remainder = divmod(remainder, 3600)
        minutes = remainder // 60
        return f"{days}д {hours}ч {minutes}мин"

    def _collect_settings_from_ui(self) -> SonarSettings:
        settings = self.config_manager.load()
        fishing = settings.fishing
        fishing.auto_meal = self.auto_meal_check.isChecked()
        fishing.restore_food_from = self.restore_food_slider.value()
        fishing.restore_water_from = self.restore_water_slider.value()
        fishing.restore_health_from = self.restore_health_slider.value() if hasattr(self, "restore_health_slider") else 1
        fishing.auto_change_bait = self.auto_change_bait_check.isChecked()
        fishing.store_in_backpack = False
        fishing.store_in_trunk = self.store_trunk_check.isChecked()
        fishing.start_stop_sound_enabled = self.start_stop_sound_check.isChecked()
        fishing.overweight_action = str(self.overweight_action_combo.currentData() or "stop")
        fishing.shutdown_on_overweight = fishing.overweight_action == "stop"
        fishing.fish_without_leader = self.fish_without_leader_check.isChecked()
        fishing.leader_depleted_action = str(self.leader_depleted_action_combo.currentData() or "stop")
        fishing.fish_without_net = self.fish_without_net_check.isChecked()
        fishing.net_depleted_action = str(self.net_depleted_action_combo.currentData() or "stop")
        fishing.equipment_depleted_action = str(self.equipment_depleted_action_combo.currentData() or "stop")
        fishing.food_depleted_action = str(self.food_depleted_action_combo.currentData() or "continue")
        fishing.hotkey = self.hotkey_input.hotkey() or "F9"
        fishing.inventory_hotkey = self.inventory_hotkey_input.hotkey() or "i"
        fishing.use_item_hotkey = self.use_item_hotkey_input.hotkey() or "e"
        fishing.backpack_move_hotkey = self.backpack_move_hotkey_input.hotkey() or "r"
        fishing.discard_key = self.discard_key_input.hotkey() or "q"
        fishing.chat_hotkey = self.chat_hotkey_input.hotkey() or "t"
        if hasattr(self, "stream_snapshot_mode_check"):
            fishing.stream_snapshot_mode = self.stream_snapshot_mode_check.isChecked()
        for key, checkbox in getattr(self, "garbage_checks", {}).items():
            fishing.garbage_settings[key] = checkbox.isChecked()
        for fish_id, checkbox in self.fish_checks.items():
            fishing.fish_settings[fish_id] = checkbox.isChecked()
        telegram = settings.telegram
        telegram.enabled = self.telegram_enabled_check.isChecked()
        telegram.bot_token = self.telegram_token_input.text().strip()
        telegram.admin_ids = [int(item.strip()) for item in self.telegram_admins_input.text().split(",") if item.strip().isdigit()]
        telegram.notify_catch = self.telegram_notify_catch_check.isChecked()
        telegram.notify_start_stop = self.telegram_notify_start_stop_check.isChecked()
        telegram.notify_meal = self.telegram_notify_meal_check.isChecked()
        telegram.notify_inventory_full = self.telegram_notify_inventory_full_check.isChecked()
        telegram.notify_inventory_space_low = self.telegram_notify_inventory_space_low_check.isChecked()
        telegram.inventory_space_low_threshold_kg = self._parse_inventory_space_threshold(self.telegram_inventory_space_low_input.text())
        self.telegram_inventory_space_low_input.setText(f"{telegram.inventory_space_low_threshold_kg:.2f}")
        telegram.notify_bait_tired = self.telegram_notify_bait_tired_check.isChecked()
        telegram.notify_focus_lost = self.telegram_notify_focus_lost_check.isChecked()
        return settings

    def save_settings(self) -> None:
        self.settings = self._collect_settings_from_ui()
        self.config_manager.save(self.settings)
        self.session_stats.set_custom_prices(self.settings.fishing.custom_fish_prices)
        self.bot.reload_settings()
        self._refresh_overview_telegram_card()
        self._refresh_overview_stream_card()
        self.append_log("Настройки сохранены")

    def _refresh_uninstall_button(self) -> None:
        if not hasattr(self, "uninstall_button"):
            return
        availability = get_uninstall_availability()
        self.uninstall_button.setEnabled(availability.enabled)
        tooltip = f"Папка программы: {availability.target_dir}"
        if not availability.enabled:
            tooltip = f"{availability.reason}\n{tooltip}"
        self.uninstall_button.setToolTip(tooltip)
        self.uninstall_note_label.setToolTip(tooltip)

    def confirm_self_uninstall(self) -> None:
        availability = get_uninstall_availability()
        if not availability.enabled:
            QMessageBox.warning(self, "Удаление недоступно", availability.reason)
            self._refresh_uninstall_button()
            return
        answer = QMessageBox.warning(
            self,
            "Удалить бота?",
            (
                "Будет удалена вся папка программы:\n"
                f"{availability.target_dir}\n\n"
                "Файлы не попадут в корзину. Продолжить?"
            ),
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if answer != QMessageBox.StandardButton.Yes:
            return
        try:
            if hasattr(self, "stream_service"):
                self.stream_service.stop_stream("self uninstall")
            self.bot.stop()
            if hasattr(self, "_notify_app_stopped"):
                self._notify_app_stopped()
            self.bot.notification_manager.stop_polling()
            script_path = schedule_self_uninstall()
        except Exception as exc:
            QMessageBox.critical(self, "Ошибка удаления", str(exc))
            self._refresh_uninstall_button()
            return
        self.append_log(f"Удаление запланировано: {script_path}")
        QApplication.quit()

    def _telegram_enabled_changed(self, *args) -> None:
        del args
        self.settings = self.config_manager.load()
        self.settings.telegram.enabled = self.telegram_enabled_check.isChecked()
        self.config_manager.save(self.settings)
        self.bot.reload_settings()
        self._refresh_overview_telegram_card()

    def start_bot(self) -> None:
        try:
            if self.bot.state.running:
                return
            key = self._current_license_key()
            if not key:
                self._select_page(self.license_tab)
                self.status_label.setText("Лицензия не активна")
                self.append_log("Лицензия не активна")
                return
            self.status_label.setText("Проверяем лицензию...")
            self.append_log("Проверяем лицензию перед запуском бота")
            self._run_license_check(key, pending_bot_start=True)
        except Exception as exc:
            self.status_label.setText("Ошибка запуска")
            self.append_log(f"Ошибка запуска: {exc}")

    def _start_bot_now(self) -> None:
        try:
            if not self._can_use_feature(FEATURE_FISHING):
                self._select_page(self.license_tab)
                self.status_label.setText("Лицензия не активна")
                self.append_log("Лицензия не активна")
                return
            self._prepare_stats_for_new_run()
            self.save_settings()
            if self.bot.start(skip_license_check=True):
                self._refresh_status_label()
            else:
                self.status_label.setText("Ошибка запуска")
        except Exception as exc:
            self.status_label.setText("Ошибка запуска")
            self.append_log(f"Ошибка запуска: {exc}")

    def _start_bot_from_remote(self) -> bool:
        if self.bot.state.running:
            return True
        key = self._current_license_key()
        if not key:
            self.log_bridge.message.emit("Лицензия не активна")
            return False
        status = self.license_manager.validate_key(key)
        self.license_status = status
        self._schedule_next_license_refresh(status)
        self.license_bridge.result.emit(status)
        if not status.valid or status.expired or not self._can_use_feature(FEATURE_FISHING):
            self.log_bridge.message.emit("Лицензия не активна")
            return False
        self._prepare_stats_for_new_run()
        return self.bot.start(skip_license_check=True)

    def stop_bot(self) -> None:
        try:
            self._pending_bot_start_after_license = False
            self.bot.stop_async()
        except Exception as exc:
            self.append_log(f"Ошибка остановки: {exc}")
        finally:
            self._refresh_status_label()

    def toggle_bot(self) -> None:
        if self.bot.state.running:
            self.stop_bot()
        else:
            self.start_bot()

    @staticmethod
    def _load_win32api() -> ModuleType | None:
        if os.name != "nt":
            return None
        try:
            import win32api
        except ImportError:
            return None
        return win32api

    def _current_hotkey_vks(self) -> tuple[int, ...]:
        hotkey = self.hotkey_input.hotkey() or "F9"
        if hotkey == self._hotkey_text:
            return self._hotkey_vks
        self._hotkey_text = hotkey
        self._hotkey_vks = self._hotkey_to_vks(hotkey)
        return self._hotkey_vks

    def _hotkey_capture_state_changed(self, active: bool) -> None:
        if active:
            self._suppress_hotkey_until_release()

    def _suppress_hotkey_until_release(self, *_args: object) -> None:
        self._hotkey_suppressed_until_release = True
        self._hotkey_down = False

    def _hotkey_capture_is_active(self) -> bool:
        return any(widget.is_capture_active() for widget in getattr(self, "_hotkey_inputs", []))

    def _poll_hotkey(self) -> None:
        try:
            self._poll_hotkey_impl()
        except KeyboardInterrupt:
            self._request_quit_from_interrupt()

    def _poll_hotkey_impl(self) -> None:
        if self._win32api is None:
            return
        if self._hotkey_capture_is_active():
            self._suppress_hotkey_until_release()
            return
        if not self._can_use_feature(FEATURE_FISHING):
            self._hotkey_down = False
            return
        vks = self._current_hotkey_vks()
        if not vks:
            self._hotkey_down = False
            return
        is_down = all(bool(self._win32api.GetAsyncKeyState(vk) & 0x8000) for vk in vks)
        if self._hotkey_suppressed_until_release:
            if not is_down:
                self._hotkey_suppressed_until_release = False
            self._hotkey_down = is_down
            return
        if is_down and not self._hotkey_down:
            QTimer.singleShot(0, self.toggle_bot)
        self._hotkey_down = is_down

    def _request_quit_from_interrupt(self) -> None:
        if self._interrupt_quit_requested:
            return
        self._interrupt_quit_requested = True
        for timer in (
            getattr(self, "hotkey_timer", None),
            getattr(self, "status_timer", None),
            getattr(self, "player_status_timer", None),
            getattr(self, "stats_timer", None),
            getattr(self, "fishing_preview_timer", None),
            getattr(self, "stream_timer", None),
            getattr(self, "license_timer", None),
        ):
            if timer is not None:
                timer.stop()
        self.close()
        QApplication.quit()

    @classmethod
    def _hotkey_to_vks(cls, hotkey: str) -> tuple[int, ...]:
        parts = [part.strip() for part in hotkey.replace(" ", "").split("+") if part.strip()]
        if not parts:
            return ()
        result: list[int] = []
        for part in parts:
            vk = cls._hotkey_to_vk(part)
            if vk is None:
                return ()
            if vk not in result:
                result.append(vk)
        return tuple(result)

    @staticmethod
    def _hotkey_to_vk(hotkey: str) -> int | None:
        key = hotkey.upper().strip()
        modifiers = {
            "CTRL": 0x11,
            "CONTROL": 0x11,
            "SHIFT": 0x10,
            "ALT": 0x12,
        }
        if key in modifiers:
            return modifiers[key]
        named_keys = {
            "TAB": 0x09,
            "BACKSPACE": 0x08,
            "ENTER": 0x0D,
            "SPACE": 0x20,
        }
        if key in named_keys:
            return named_keys[key]
        if key.startswith("F") and key[1:].isdigit():
            num = int(key[1:])
            if 1 <= num <= 24:
                return 0x70 + num - 1
        if len(key) == 1 and key.isalnum():
            return ord(key)
        return None

    def append_log(self, text: str) -> None:
        del text

    def _handle_ui_event(self, event: object) -> None:
        if not isinstance(event, UiEventMessage):
            return
        self.add_recent_event(
            event.text,
            event_type=event.event_type,
            icon=event.icon,
            detail=event.detail,
            extra_green=event.extra_green,
            extra_red=event.extra_red,
            created_at=event.created_at,
        )

    def add_recent_event(
        self,
        text: str,
        *,
        event_type: str = "info",
        icon: str = "",
        detail: str = "",
        extra_green: str = "",
        extra_red: str = "",
        created_at: datetime | None = None,
    ) -> None:
        text = text.strip()
        detail = detail.strip()
        extra_green = extra_green.strip()
        extra_red = extra_red.strip()
        if not text:
            return
        events = getattr(self, "_recent_events", None)
        if events is None:
            return
        events.append(
            RecentUiEvent(
                text=text,
                event_type=event_type,
                icon=icon.strip(),
                detail=detail,
                extra_green=extra_green,
                extra_red=extra_red,
                created_at=created_at or datetime.now(),
            )
        )
        overflow = len(events) - RECENT_EVENT_LIMIT
        if overflow > 0:
            del events[:overflow]
        self._refresh_recent_events()

    def _clear_recent_events(self) -> None:
        self._recent_events = []
        self._recent_events_render_signature = None
        self._refresh_recent_events()

    def _refresh_recent_events(self) -> None:
        if not hasattr(self, "recent_events_layout"):
            return
        old_scroll_value = 0
        was_at_bottom = True
        if hasattr(self, "recent_events_scroll"):
            bar = self.recent_events_scroll.verticalScrollBar()
            old_scroll_value = bar.value()
            was_at_bottom = self._recent_events_is_at_bottom(bar.value(), bar.maximum())
        events = getattr(self, "_recent_events", [])
        visible_events = events[-RECENT_EVENT_RENDER_LIMIT:]
        signature = tuple(
            (
                event.text,
                event.detail,
                event.extra_green,
                event.extra_red,
                event.event_type,
                event.icon,
                event.created_at.strftime("%H:%M:%S"),
            )
            for event in visible_events
        )
        if signature == self._recent_events_render_signature:
            return
        self._recent_events_render_signature = signature
        clear_layout(self.recent_events_layout)
        self.recent_events_layout.addStretch(1)
        if not events:
            empty = QLabel("Событий пока нет")
            empty.setProperty("muted", True)
            self.recent_events_layout.addWidget(empty)
            return
        for index, event in enumerate(visible_events):
            row = QFrame()
            row.setObjectName("recentEventRow")
            row.setFixedHeight(24)
            row_layout = QHBoxLayout(row)
            row_layout.setContentsMargins(0, 0, 0, 0)
            row_layout.setSpacing(5)
            icon = self._recent_event_icon(event)
            row_layout.addWidget(icon, 0, Qt.AlignmentFlag.AlignVCenter)
            title = ElidedLabel(self._recent_event_visible_text(event))
            title.setProperty("recentTitle", True)
            row_layout.addWidget(title, 1)
            if event.extra_green or event.extra_red:
                extra_text = event.extra_green or event.extra_red
                extra_label = QLabel(extra_text)
                extra_label.setProperty("recentExtraGreen" if event.extra_green else "recentExtraRed", True)
                extra_label.setSizePolicy(QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed)
                row_layout.addWidget(extra_label, 0, Qt.AlignmentFlag.AlignVCenter)
            time_label = QLabel(event.created_at.strftime("%H:%M:%S"))
            time_label.setProperty("recentTime", True)
            row_layout.addWidget(time_label, 0, Qt.AlignmentFlag.AlignVCenter)
            self.recent_events_layout.addWidget(row)
            if index < len(visible_events) - 1:
                divider = QFrame()
                divider.setObjectName("recentEventDivider")
                divider.setFixedHeight(1)
                self.recent_events_layout.addWidget(divider)
        if hasattr(self, "recent_events_scroll"):
            self.recent_events_widget.adjustSize()
            self.recent_events_scroll.viewport().updateGeometry()
            QTimer.singleShot(0, lambda: self._restore_recent_events_scroll(old_scroll_value, was_at_bottom, 4))

    @staticmethod
    def _recent_events_is_at_bottom(value: int, maximum: int) -> bool:
        return value >= maximum - 2

    @staticmethod
    def _recent_events_restore_value(old_value: int, maximum: int, was_at_bottom: bool) -> int:
        if was_at_bottom:
            return maximum
        return min(old_value, maximum)

    @staticmethod
    def _recent_event_visible_text(event: RecentUiEvent) -> str:
        if event.detail:
            return f"{event.text} · {event.detail}"
        return event.text

    def _recent_event_icon(self, event: RecentUiEvent) -> QWidget:
        if event.icon:
            path = ui_icon(event.icon)
            if path.exists():
                return icon_widget(path, 13, color=self._recent_event_color(event.event_type))
        marker = QLabel("●")
        marker.setFixedSize(13, 13)
        marker.setAlignment(Qt.AlignmentFlag.AlignCenter)
        marker.setStyleSheet(f"color: {self._recent_event_color(event.event_type)}; font-size: 9px;")
        return marker

    def _restore_recent_events_scroll(self, old_value: int, was_at_bottom: bool, attempts_left: int = 0) -> None:
        if not hasattr(self, "recent_events_scroll"):
            return
        bar = self.recent_events_scroll.verticalScrollBar()
        bar.setValue(self._recent_events_restore_value(old_value, bar.maximum(), was_at_bottom))
        if was_at_bottom and attempts_left > 0:
            QTimer.singleShot(0, lambda: self._restore_recent_events_scroll(old_value, was_at_bottom, attempts_left - 1))

    @staticmethod
    def _recent_event_color(event_type: str) -> str:
        return {
            "success": "#31c65b",
            "warning": "#f59e0b",
            "danger": "#ff4d4f",
            "fish": "#1f7aff",
            "meal": "#31c65b",
            "info": "#1f7aff",
        }.get(event_type, "#1f7aff")

    def _refresh_fishing_preview(self) -> None:
        if not getattr(self, "_fishing_preview_labels", None):
            return
        if getattr(self, "_fishing_preview_refreshing", False):
            return
        if hasattr(self, "stack") and self.stack.currentWidget() not in {self.overview_tab, self.fishing_tab}:
            return
        self._fishing_preview_refreshing = True

        def worker() -> None:
            image: QImage | None = None
            try:
                frame = self.bot.capture.capture()
                if frame is not None and frame.size:
                    rgb = frame[:, :, ::-1].copy()
                    height, width = rgb.shape[:2]
                    image = QImage(rgb.data, width, height, 3 * width, QImage.Format.Format_RGB888).copy()
            except Exception:
                image = None
            self.fishing_preview_bridge.updated.emit(image)

        threading.Thread(target=worker, name="sonar-fishing-preview", daemon=True).start()

    def _handle_fishing_preview_image(self, image: object) -> None:
        self._fishing_preview_refreshing = False
        if not getattr(self, "_fishing_preview_labels", None):
            return
        qimage = image if isinstance(image, QImage) and not image.isNull() else None
        for label in self._fishing_preview_labels:
            if qimage is None:
                label.setPixmap(QPixmap())
                label.setText("Скриншот игры появится после захвата")
                continue
            pixmap = QPixmap.fromImage(qimage).scaled(
                label.size(),
                Qt.AspectRatioMode.KeepAspectRatioByExpanding,
                Qt.TransformationMode.SmoothTransformation,
            )
            label.setText("")
            label.setPixmap(pixmap)

    def _refresh_player_status(self) -> None:
        if getattr(self, "_player_status_refreshing", False):
            return
        self._player_status_refreshing = True
        allow_screenshot_fallback = self._should_use_player_status_screenshot_fallback()
        if allow_screenshot_fallback:
            self._last_player_status_screenshot_at = time.time()

        def worker() -> None:
            try:
                self.bot.detect_player_status(allow_screenshot_fallback=allow_screenshot_fallback)
            except Exception as exc:
                self.log_bridge.message.emit(f"Не удалось обновить показатели игрока: {exc}")
                self.player_status_bridge.updated.emit(None)
            finally:
                self._player_status_refreshing = False

        threading.Thread(target=worker, name="sonar-player-status-refresh", daemon=True).start()

    def request_player_status_scan(self) -> None:
        ok, message = self.bot.request_player_status_scan()
        self.log_bridge.message.emit(message)
        if hasattr(self, "player_status_source_label"):
            self.player_status_source_label.setText("Сканирование запланировано" if ok else message)

    def _should_use_player_status_screenshot_fallback(self) -> bool:
        status = getattr(self, "_latest_player_status", None)
        if status is None:
            return True
        if not status.has_core_values() and time.time() - self._last_player_status_screenshot_at >= 20.0:
            return True
        return status.has_core_values() and time.time() - self._last_player_status_screenshot_at >= 60.0

    def _handle_player_status_update(self, status: object) -> None:
        if status is not None and not isinstance(status, PlayerStatus):
            return
        self._latest_player_status = status
        self._latest_player_status_at = time.time()
        self._render_player_status(status)

    def _render_player_status(self, status: PlayerStatus | None) -> None:
        if hasattr(self, "player_food_metric"):
            self.player_food_metric.set_value(self._format_percent_value(status.food if status else None))
            self.player_water_metric.set_value(self._format_percent_value(status.water if status else None))
            self.player_health_metric.set_value(self._format_percent_value(status.health if status else None))
            self.player_inventory_weight_metric.set_value(
                self._format_weight_pair(
                    status.inventory_weight if status else None,
                    status.inventory_weight_max if status else None,
                )
            )
            self.player_backpack_weight_metric.set_value(
                self._format_weight_pair(
                    status.backpack_weight if status else None,
                    status.backpack_weight_max if status else None,
                )
            )
            if hasattr(self, "player_status_source_label"):
                self.player_status_source_label.setText(self._format_player_status_source(status))
        self._refresh_system_state(force=True)

    @staticmethod
    def _format_percent_value(value: int | None) -> str:
        return "—" if value is None else f"{value}%"

    @staticmethod
    def _format_weight_pair(current: float | None, maximum: float | None) -> str:
        if current is None and maximum is None:
            return "—"
        if current is None:
            return f"— / {MainWindow._format_weight_number(maximum)} кг"
        if maximum is None:
            return f"{MainWindow._format_weight_number(current)} кг"
        return f"{MainWindow._format_weight_number(current)} / {MainWindow._format_weight_number(maximum)} кг"

    @staticmethod
    def _format_weight_number(value: float | None) -> str:
        if value is None:
            return "—"
        text = f"{value:.2f}".rstrip("0").rstrip(".")
        return text or "0"

    @staticmethod
    def _format_player_status_source(status: PlayerStatus | None) -> str:
        if status is None or not status.has_any_value():
            return "Нет данных"
        if "estimate" in status.source:
            return "Расчёт"
        if "screenshot" in status.source and "memory" in status.source:
            return "Память + скрин"
        if "memory" in status.source:
            return "Память процесса"
        if "screenshot" in status.source:
            return "Скриншот"
        return status.source or "Данные получены"

    def _refresh_status_label(self) -> None:
        active_license = self._has_active_license()
        fishing_allowed = self._can_use_feature(FEATURE_FISHING)
        running = bool(fishing_allowed and self.bot.state.running)
        stopping = self.bot.state.phase == BotPhase.STOPPING
        if self._last_bot_running and not running and not stopping:
            self._archive_current_stats_session()
        self._last_bot_running = running
        if not active_license:
            title = "Лицензия не активна"
            description = "Активируйте ключ, чтобы запустить рыбалку"
        elif not fishing_allowed:
            title = "Рыбалка недоступна"
            description = "Функция отключена для этой лицензии"
        elif stopping:
            title = "Останавливаем"
            description = "Завершаем текущие операции"
        elif running:
            title = "Работает"
            description = self.bot.state.detected_stage or "Бот выполняет текущий цикл"
        else:
            title = "Ожидание"
            description = "Ожидание команды для начала рыбалки"
        for label in getattr(self, "_status_labels", []):
            label.setText(title)
        for label in getattr(self, "_status_description_labels", []):
            label.setText(description)
        for button in getattr(self, "_start_buttons", []):
            button.setEnabled(fishing_allowed and not running and not stopping and not self._license_checking)
        for button in getattr(self, "_stop_buttons", []):
            button.setEnabled(running and not stopping)
        for badge in getattr(self, "_ready_badges", []):
            if running:
                badge.setText("Активен")
                badge.set_tone("green")
            elif fishing_allowed:
                badge.setText("Готов")
                badge.set_tone("green")
            else:
                badge.setText("Нужна лицензия")
                badge.set_tone("red")
        hotkey = self.hotkey_input.hotkey() if hasattr(self, "hotkey_input") else "F9"
        for badge in getattr(self, "_hotkey_badges", []):
            badge.setText(hotkey or "F9")
        self._refresh_system_state()

    def _refresh_system_state(self, *, force: bool = False) -> None:
        if not hasattr(self, "_system_tiles"):
            return
        now = time.monotonic()
        if not force and now - self._last_system_state_refresh_at < SYSTEM_STATE_REFRESH_INTERVAL_SECONDS:
            return
        self._last_system_state_refresh_at = now
        game_available = False
        try:
            game_available = self.bot.capture.is_window_available()
        except Exception:
            game_available = False
        items = {item.key: item for item in self.session_stats.tackle_items()}
        bait = items.get("bait")
        leader = items.get("hook")
        net = items.get("net")
        player_status = getattr(self, "_latest_player_status", None)
        food_value = self._format_percent_value(player_status.food if player_status else None)
        water_value = self._format_percent_value(player_status.water if player_status else None)
        inventory_value = self._format_weight_pair(
            player_status.inventory_weight if player_status else None,
            player_status.inventory_weight_max if player_status else None,
        )
        signature = (
            game_available,
            food_value,
            water_value,
            inventory_value,
            bait.count if bait is not None else None,
            leader.count if leader is not None else None,
            net.count if net is not None else None,
        )
        if not force and signature == self._last_system_state_signature:
            return
        self._last_system_state_signature = signature
        self._set_status_tiles("game", "Обнаружено" if game_available else "Не найдено", "Majestic RP", game_available)
        self._set_status_tiles("food", food_value, "Показатель", player_status is not None and player_status.food is not None and player_status.food > 0)
        self._set_status_tiles("water", water_value, "Показатель", player_status is not None and player_status.water is not None and player_status.water > 0)
        self._set_status_tiles("inventory", inventory_value, "Вес", player_status is not None and player_status.inventory_weight is not None)
        self._set_status_tiles("bait", self._format_tackle_presence(bait.count if bait is not None else None), self._format_tackle_count(bait.count if bait is not None else None), bait is not None and bait.count > 0)
        self._set_status_tiles("leader", self._format_tackle_presence(leader.count if leader is not None else None), self._format_tackle_count(leader.count if leader is not None else None), leader is not None and leader.count > 0)
        self._set_status_tiles("net", self._format_tackle_presence(net.count if net is not None else None), self._format_tackle_count(net.count if net is not None else None), net is not None and net.count > 0)

    def _set_status_tiles(self, key: str, value: str, subtitle: str, ok: bool) -> None:
        for tile in self._system_tiles.get(key, []):
            if tile.value_label.text() != value:
                tile.value_label.setText(value)
            subtitle_text = subtitle or " "
            if tile.subtitle_label.text() != subtitle_text:
                tile.subtitle_label.setText(subtitle_text)
            color = "#31c65b" if ok else "#ff4d4f"
            if getattr(tile, "_dot_color", "") != color:
                tile.dot_label.setStyleSheet(f"color: {color}; font-size: 12px;")
                tile._dot_color = color

    @staticmethod
    def _format_tackle_presence(count: int | None) -> str:
        if count is None:
            return "Не сканировалось"
        if count <= 0:
            return "Нет"
        return "Есть" if count == 1 else f"Есть · {count}"

    @staticmethod
    def _format_tackle_count(count: int | None) -> str:
        if count is None:
            return ""
        return f"Количество: {max(0, count)}"

    def _refresh_stats_tab(self, *, force: bool = False) -> None:
        if not hasattr(self, "stats_table"):
            return
        stats = self._stats_source()
        totals = stats.totals()
        current_totals = self.session_stats.totals()
        duration = format_duration(totals.duration_seconds)
        caught = format_catch_summary(totals.caught_count, totals.caught_kg)
        released = format_catch_summary(totals.released_count, totals.released_kg)
        kept = format_weight(totals.kept_kg)
        income = format_money_range(totals.earned_min, totals.earned_max)
        income_hour = format_money_range(totals.earned_per_hour_min, totals.earned_per_hour_max) if totals.duration_seconds > 0 else "0 $"
        metrics_signature = (
            duration,
            caught,
            released,
            kept,
            income,
            income_hour,
            self._stats_applied_filter_key,
        )
        if force or metrics_signature != self._stats_metrics_signature:
            self.stats_duration_label.set_value(duration)
            self.stats_caught_label.set_value(caught)
            self.stats_released_label.set_value(released)
            self.stats_kept_label.set_value(kept)
            self.stats_income_label.set_value(income)
            self.stats_income_per_hour_label.set_value(income_hour)
            self._stats_metrics_signature = metrics_signature
        current_duration = format_duration(current_totals.duration_seconds)
        current_income = format_money_range(current_totals.earned_min, current_totals.earned_max)
        current_income_hour = (
            format_money_range(current_totals.earned_per_hour_min, current_totals.earned_per_hour_max)
            if current_totals.duration_seconds > 0
            else "0 $"
        )
        for metric in (getattr(self, "overview_duration_metric", None), getattr(self, "fishing_duration_metric", None)):
            if metric is not None:
                metric.set_value(current_duration)
        for metric in (getattr(self, "overview_caught_metric", None), getattr(self, "fishing_caught_metric", None)):
            if metric is not None:
                metric.set_value(str(current_totals.caught_count))
        for metric in (getattr(self, "overview_released_metric", None), getattr(self, "fishing_released_metric", None)):
            if metric is not None:
                metric.set_value(str(current_totals.released_count))
        for metric in (getattr(self, "overview_income_metric", None), getattr(self, "fishing_income_metric", None)):
            if metric is not None:
                metric.set_value(current_income)
        if hasattr(self, "overview_income_hour_metric"):
            self.overview_income_hour_metric.set_value(current_income_hour)
        if hasattr(self, "fishing_tackle_label"):
            self.fishing_tackle_label.setText(format_tackle_items(self.session_stats.tackle_items()))
        self._refresh_catch_size_rows(force=force)
        if (
            self._is_current_stats_view()
            and self.stats_table.state() == QAbstractItemView.State.EditingState
            and self.stats_table.currentColumn() == 4
        ):
            return
        rows = stats.rows()
        table_signature = tuple(
            (
                row.stat.fish_id,
                row.stat.name,
                row.stat.caught_count,
                round(row.stat.caught_kg, 3),
                row.stat.released_count,
                round(row.stat.released_kg, 3),
                row.custom_price,
                round(row.earned_min, 2),
                round(row.earned_max, 2),
            )
            for row in rows
        )
        if not force and table_signature == self._stats_table_signature:
            return
        self._stats_refreshing = True
        self.stats_table.blockSignals(True)
        self.stats_table.setRowCount(len(rows))
        for row_index, row in enumerate(rows):
            stat = row.stat
            values = [
                stat.name,
                format_catch_summary(stat.caught_count, stat.caught_kg),
                format_catch_summary(stat.released_count, stat.released_kg),
                format_base_price(row.base_price),
                f"{row.custom_price:g}" if row.custom_price is not None else "",
                format_money_range(row.earned_min, row.earned_max),
            ]
            for column, value in enumerate(values):
                item = QTableWidgetItem(value)
                if column == 0:
                    icon_path = fish_icon(stat.fish_id)
                    if icon_path.exists():
                        item.setIcon(QIcon(str(icon_path)))
                if column == 4:
                    item.setData(Qt.ItemDataRole.UserRole, stat.fish_id)
                    if not self._is_current_stats_view():
                        item.setFlags(item.flags() & ~Qt.ItemFlag.ItemIsEditable)
                else:
                    item.setFlags(item.flags() & ~Qt.ItemFlag.ItemIsEditable)
                self.stats_table.setItem(row_index, column, item)
            self.stats_table.setRowHeight(row_index, 32)
        self.stats_table.blockSignals(False)
        self._stats_refreshing = False
        self._stats_table_signature = table_signature

    def _refresh_catch_size_rows(self, *, force: bool = False) -> None:
        if not hasattr(self, "catch_size_legend_layout"):
            return
        rows = self._stats_source().catch_size_rows()
        signature = tuple((item.key, item.count, round(item.percent, 2)) for item in rows)
        if not force and signature == self._catch_size_signature:
            return
        self._catch_size_signature = signature
        self.catch_size_chart.set_rows(rows)
        clear_layout(self.catch_size_legend_layout)
        visible_rows = [item for item in rows if item.count > 0]
        if not visible_rows:
            empty = QLabel("Уловов пока нет")
            empty.setProperty("muted", True)
            self.catch_size_legend_layout.addWidget(empty)
            return
        for item in visible_rows:
            row = QHBoxLayout()
            row.setSpacing(8)
            marker = QLabel("●")
            marker.setFixedWidth(12)
            marker.setStyleSheet(f"color: {catch_size_chart_color(item.key)}; font-size: 12px;")
            label = QLabel(item.label.replace(" улов", ""))
            label.setProperty("muted", True)
            value = QLabel(f"{item.count} ({item.percent:.1f}%)")
            value.setProperty("muted", True)
            row.addWidget(marker)
            row.addWidget(label, 1)
            row.addWidget(value)
            self.catch_size_legend_layout.addLayout(row)
        self.catch_size_legend_layout.addStretch(1)

    def _stats_price_changed(self, item: QTableWidgetItem) -> None:
        if self._stats_refreshing or item.column() != 4 or not self._is_current_stats_view():
            return
        fish_id = item.data(Qt.ItemDataRole.UserRole)
        if not fish_id:
            return
        text = re.sub(r"\D", "", item.text())
        if item.text() != text:
            self.stats_table.blockSignals(True)
            item.setText(text)
            self.stats_table.blockSignals(False)
        price = float(text) if text else None
        self.session_stats.set_custom_price(str(fish_id), price)
        self.settings = self.config_manager.load()
        self.settings.fishing.custom_fish_prices = dict(self.session_stats.custom_prices)
        self.config_manager.save(self.settings)
        self.bot.reload_settings()
        self._refresh_stats_tab()

    def _start_stream_from_remote(self) -> bool:
        if not self._can_use_feature(FEATURE_STREAM):
            self.log_bridge.message.emit("Лицензия не активна: стрим не запущен")
            return False
        return self.stream_service.start_stream()

    def _stop_stream_from_remote(self) -> None:
        self.stream_service.stop_stream("telegram")

    def _set_stream_snapshot_mode_from_remote(self, enabled: bool) -> bool:
        ok = self.stream_service.set_snapshot_mode_enabled(enabled)
        self.settings = self.config_manager.load()
        self.settings.fishing.stream_snapshot_mode = bool(enabled)
        self.config_manager.save(self.settings)
        self._refresh_stream_tab()
        return ok

    def _notify_app_started(self) -> None:
        threading.Thread(
            target=self.bot.notification_manager.notify_app_started,
            name="sonar-telegram-app-start",
            daemon=True,
        ).start()

    def _notify_app_stopped(self) -> None:
        if getattr(self, "_app_stopped_notified", False):
            return
        self._app_stopped_notified = True
        self.bot.notification_manager.notify_app_stopped()

    def stop_stream(self) -> None:
        self.stream_service.stop_stream("ui")
        self._refresh_stream_tab()

    def start_stream(self) -> None:
        self._start_stream_from_remote()
        self._refresh_stream_tab()

    def enable_chat_mode(self) -> None:
        if not self._can_use_feature(FEATURE_STREAM_CHAT):
            self.log_bridge.message.emit("Режим чата недоступен для этой лицензии")
            return
        snapshot = self.stream_service.snapshot()
        self.stream_service.set_chat_mode_enabled(not (snapshot.chat_active or snapshot.chat_mode_enabled))
        self._refresh_stream_tab()

    def _enable_chat_mode_from_stream(self) -> ChatActionResult:
        if not self._can_use_feature(FEATURE_STREAM_CHAT):
            detection = ChatDetection(error="Режим чата недоступен для этой лицензии")
            return ChatActionResult(False, detection.error, detection)
        was_running = getattr(self, "bot", None) is not None and self.bot.state.running
        self._resume_bot_after_chat = was_running
        if was_running:
            self.bot.pause_for_chat(True)
        self.settings = self.config_manager.load()
        result = self.chat_controller.open_chat(self.settings.fishing.chat_hotkey, timeout=1.5)
        if result.ok:
            self.log_bridge.message.emit(result.message)
            return result
        self.log_bridge.message.emit(f"Режим чата: {result.message}, возвращаю персонажа в простой")
        ready, ready_message = self.bot.prepare_for_chat_mode()
        if not ready:
            if was_running:
                self.bot.pause_for_chat(False, restart_on_resume=False)
                self._resume_bot_after_chat = False
            result = ChatActionResult(False, ready_message, self.chat_controller.detect())
            self.log_bridge.message.emit(f"Режим чата: {ready_message}")
            return result
        self.log_bridge.message.emit(f"Режим чата: {ready_message}")
        result = self.chat_controller.open_chat(self.settings.fishing.chat_hotkey)
        if not result.ok and was_running:
            self.bot.pause_for_chat(False, restart_on_resume=False)
            self._resume_bot_after_chat = False
        self.log_bridge.message.emit(result.message if result.ok else f"Режим чата: {result.message}")
        return result

    def _disable_chat_mode_from_stream(self) -> ChatActionResult:
        result = self.chat_controller.close_chat(force=True)
        chat_closed = result.ok and not result.detection.active
        if chat_closed:
            if self._resume_bot_after_chat and getattr(self, "bot", None) is not None and self.bot.state.running:
                self.bot.pause_for_chat(False)
            self._resume_bot_after_chat = False
        elif self._resume_bot_after_chat:
            if getattr(self, "bot", None) is not None and self.bot.state.running:
                self.bot.stop("не удалось закрыть режим чата")
            self._resume_bot_after_chat = False
        self.log_bridge.message.emit(result.message if result.ok else f"Режим чата: {result.message}")
        return result

    def _detect_stream_chat_state(self) -> ChatDetection:
        return self.chat_controller.detect()

    def _select_stream_chat_tab(self, tab_id: str | None) -> ChatActionResult:
        self.settings = self.config_manager.load()
        return self.chat_controller.select_tab(tab_id, chat_hotkey=self.settings.fishing.chat_hotkey)

    def _send_stream_chat_message(self, tab_id: str | None, message: str) -> ChatActionResult:
        self.settings = self.config_manager.load()
        return self.chat_controller.send_message(tab_id, message, chat_hotkey=self.settings.fishing.chat_hotkey)

    def _clear_stream_chat(self) -> ChatActionResult:
        self.settings = self.config_manager.load()
        return self.chat_controller.clear_chat_input(self.settings.fishing.chat_hotkey)

    def _stream_snapshot_mode_changed_from_page(self, enabled: bool) -> None:
        self.settings = self.config_manager.load()
        self.settings.fishing.stream_snapshot_mode = bool(enabled)
        self.config_manager.save(self.settings)

    def _stream_quality_changed(self, quality: str) -> None:
        if not hasattr(self, "stream_service"):
            return
        self.stream_service.set_quality(quality)
        self._refresh_stream_tab()

    def _stream_chat_zoom_changed(self, *args) -> None:
        del args
        if not hasattr(self, "stream_service"):
            return
        self.stream_service.set_chat_zoom_enabled(self.stream_chat_zoom_check.isChecked())
        self._refresh_stream_tab()

    def _stream_snapshot_mode_changed(self, *args) -> None:
        del args
        if not hasattr(self, "stream_service"):
            return
        enabled = self.stream_snapshot_mode_check.isChecked()
        self.settings = self.config_manager.load()
        self.settings.fishing.stream_snapshot_mode = enabled
        self.config_manager.save(self.settings)
        threading.Thread(
            target=self._apply_stream_snapshot_mode_from_ui,
            args=(enabled,),
            name="sonar-stream-snapshot-mode-ui",
            daemon=True,
        ).start()
        self._refresh_stream_tab()

    def _apply_stream_snapshot_mode_from_ui(self, enabled: bool) -> None:
        self.stream_service.set_snapshot_mode_enabled(enabled)
        QTimer.singleShot(0, self._refresh_stream_tab)

    def _license_role(self) -> str:
        try:
            return self._license_context().role
        except Exception:
            return "user"

    def _refresh_stream_tab(self) -> None:
        if not hasattr(self, "stream_status_label"):
            return
        snapshot = self.stream_service.snapshot()
        self.stream_status_label.setText(snapshot.status)
        self.stream_area_label.setText("Чат" if snapshot.area == "chat" else "Все окно")
        self.stream_quality_label.setText(snapshot.quality)
        if snapshot.active and snapshot.seconds_until_auto_stop is not None:
            minutes, seconds = divmod(max(0, int(snapshot.seconds_until_auto_stop)), 60)
            self.stream_auto_stop_label.setText(f"{minutes}:{seconds:02d} без зрителей")
        else:
            self.stream_auto_stop_label.setText("—")
        if snapshot.stream_url:
            self.stream_url_label.set_link(snapshot.stream_url)
        elif snapshot.error:
            self.stream_url_label.set_plain_text(snapshot.error, snapshot.error)
        else:
            self.stream_url_label.set_plain_text("—")
        quality_block = self.stream_quality_combo.blockSignals(True)
        chat_block = self.stream_chat_zoom_check.blockSignals(True)
        snapshot_block = self.stream_snapshot_mode_check.blockSignals(True)
        try:
            self.stream_quality_combo.setCurrentText(snapshot.quality)
            self.stream_chat_zoom_check.setChecked(snapshot.chat_zoom_enabled)
            self.stream_snapshot_mode_check.setChecked(snapshot.snapshot_mode_enabled)
        finally:
            self.stream_quality_combo.blockSignals(quality_block)
            self.stream_chat_zoom_check.blockSignals(chat_block)
            self.stream_snapshot_mode_check.blockSignals(snapshot_block)
        stream_allowed = self._can_use_feature(FEATURE_STREAM)
        chat_allowed = self._can_use_feature(FEATURE_STREAM_CHAT)
        self.stream_start_button.setEnabled(stream_allowed and (not snapshot.active) and snapshot.status not in {"starting", "preparing"})
        self.stream_stop_button.setEnabled(snapshot.active or snapshot.status in {"starting", "preparing", "error"})
        self.stream_chat_mode_button.setText("Выйти из режима чата" if snapshot.chat_active or snapshot.chat_mode_enabled else "Включить режим чата")
        self.stream_chat_mode_button.setVisible(chat_allowed)
        self.stream_chat_mode_button.setEnabled(chat_allowed and (snapshot.active or snapshot.chat_active or snapshot.chat_mode_enabled))
        quality = STREAM_QUALITIES.get(snapshot.quality)
        fps = 10 if snapshot.snapshot_mode_enabled else 30
        self.stream_fps_metric.set_value(str(fps))
        self.stream_bitrate_metric.set_value(quality.bitrate_for_fps(fps) if quality is not None else "—")
        self.stream_mode_metric.set_value("10fps" if snapshot.snapshot_mode_enabled else "Обычный")
        if snapshot.active and snapshot.started_at is not None:
            self.stream_uptime_metric.set_value(format_duration(max(0.0, self.stream_service.clock() - snapshot.started_at)))
        else:
            self.stream_uptime_metric.set_value("—")
        self._refresh_overview_stream_card()

    def reset_session_stats(self) -> None:
        self._archive_current_stats_session()
        self.session_stats.reset()
        self._archived_stats_signature = None
        if self._is_current_stats_view():
            self._stats_display_stats = self.session_stats
        self._invalidate_stats_view_cache()
        self._refresh_stats_tab(force=True)

    def _archive_current_stats_session(self) -> StoredFishingSession | None:
        signature = self._stats_archive_signature(self.session_stats)
        if signature == self._archived_stats_signature:
            return None
        record = self.session_history.add_from_stats(self.session_stats)
        if record is None:
            return None
        self._archived_stats_signature = signature
        self._stats_history_records = self.session_history.load()
        self._refresh_stats_session_combo()
        self._set_stats_filter_default_dates()
        self.append_log(f"Сессия сохранена: {record.title(default_prices=self.session_stats.default_prices)}")
        return record

    def _prepare_stats_for_new_run(self) -> None:
        if not self.session_stats.has_catches():
            return
        signature = self._stats_archive_signature(self.session_stats)
        if signature != self._archived_stats_signature:
            self._archive_current_stats_session()
        self.session_stats.reset()
        self._archived_stats_signature = None
        if self._is_current_stats_view():
            self._stats_display_stats = self.session_stats
        self._invalidate_stats_view_cache()
        self._refresh_stats_tab(force=True)

    @staticmethod
    def _stats_archive_signature(stats: FishingSessionStats) -> tuple[object, ...]:
        totals = stats.totals()
        rows = tuple(
            (
                row.stat.fish_id,
                row.stat.caught_count,
                round(row.stat.caught_kg, 3),
                row.stat.released_count,
                round(row.stat.released_kg, 3),
            )
            for row in stats.rows()
        )
        return (
            stats.started_at().isoformat(timespec="seconds"),
            round(totals.duration_seconds, 1),
            totals.caught_count,
            round(totals.caught_kg, 3),
            totals.released_count,
            round(totals.released_kg, 3),
            rows,
        )

    def export_stats_csv(self) -> None:
        default_path = default_stats_csv_path(APP_DIR, APP_NAME)
        path_text, _ = QFileDialog.getSaveFileName(
            self,
            "Сохранить статистику",
            str(default_path),
            "CSV (*.csv)",
        )
        if not path_text:
            return
        path = Path(path_text)
        if path.suffix.lower() != ".csv":
            path = path.with_suffix(".csv")
        write_stats_csv(path, self._stats_source(), app_name=APP_NAME, build_hash=APP_BUILD_HASH)
        self.append_log(f"Статистика выгружена: {path}")

    def closeEvent(self, event) -> None:  # type: ignore[override]
        try:
            self._archive_current_stats_session()
            self.settings = self._collect_settings_from_ui()
            self.config_manager.save(self.settings)
            self.bot.reload_settings()
        except Exception:
            pass
        unsubscribe = getattr(self, "_unsubscribe_ui_events", None)
        if unsubscribe is not None:
            unsubscribe()
            self._unsubscribe_ui_events = None
        if hasattr(self, "stream_service"):
            self.stream_service.stop_stream("app close")
        self.bot.stop()
        self._notify_app_stopped()
        self.bot.notification_manager.stop_polling()
        event.accept()


class StartupLoader(QWidget):
    def __init__(self) -> None:
        super().__init__()
        self.setObjectName("startupWindow")
        self.setWindowTitle(APP_NAME)
        self.setFixedSize(390, 220)
        self.setWindowFlags(Qt.WindowType.Window | Qt.WindowType.FramelessWindowHint)
        self.setAttribute(Qt.WidgetAttribute.WA_TranslucentBackground, True)
        self.setAttribute(Qt.WidgetAttribute.WA_NoSystemBackground, True)
        self.setAutoFillBackground(False)
        apply_sonar_style(self)
        root = QVBoxLayout(self)
        root.setContentsMargins(22, 22, 22, 22)
        card = QFrame()
        card.setObjectName("startupLoader")
        card.setAttribute(Qt.WidgetAttribute.WA_StyledBackground, True)
        shadow = QGraphicsDropShadowEffect(card)
        shadow.setBlurRadius(34)
        shadow.setOffset(0, 12)
        shadow.setColor(QColor(35, 70, 120, 52))
        card.setGraphicsEffect(shadow)
        layout = QVBoxLayout(card)
        layout.setContentsMargins(24, 22, 24, 22)
        layout.setSpacing(12)
        logo_row = QHBoxLayout()
        logo_path = find_app_logo_path()
        if logo_path is not None:
            logo_row.addWidget(IconLabel(logo_path, 44))
        title = QLabel("Sonar")
        title.setStyleSheet("font-size: 28px; font-weight: 850; color: #0d67e9;")
        logo_row.addWidget(title, 1)
        layout.addLayout(logo_row)
        caption = QLabel("Проверяем лицензию и готовим интерфейс")
        caption.setProperty("muted", True)
        layout.addWidget(caption)
        progress = QProgressBar()
        progress.setRange(0, 0)
        progress.setTextVisible(False)
        layout.addWidget(progress)
        root.addWidget(card)
        self._center_on_screen()

    def _center_on_screen(self) -> None:
        screen = QApplication.primaryScreen()
        if screen is None:
            return
        area = screen.availableGeometry()
        self.move(area.center().x() - self.width() // 2, area.center().y() - self.height() // 2)


def _initial_license_status_with_loader(app: QApplication) -> LicenseStatus:
    splash = StartupLoader()
    splash.show()
    app.processEvents()
    result: dict[str, LicenseStatus] = {}
    bridge = LicenseBridge()
    loop = QEventLoop()

    def finish(status: object) -> None:
        if isinstance(status, LicenseStatus):
            result["status"] = status
        else:
            result["status"] = LicenseStatus(valid=False, error="Не удалось проверить лицензию")
        QTimer.singleShot(200, loop.quit)

    bridge.result.connect(finish)

    def worker() -> None:
        try:
            manager = LicenseManager(ConfigManager())
            settings = manager.config_manager.load()
            if not settings.license.license_key:
                status = LicenseStatus(valid=False, error="Лицензия не введена")
            else:
                status = manager.check_saved_license()
        except Exception as exc:
            status = LicenseStatus(valid=False, error=str(exc))
        bridge.result.emit(status)

    threading.Thread(target=worker, name="sonar-startup-license", daemon=True).start()
    loop.exec()
    splash.close()
    splash.deleteLater()
    app.processEvents()
    return result.get("status") or LicenseStatus(valid=False, error="Не удалось проверить лицензию")


def find_app_icon_path():
    for icon_path in (RESOURCE_DIR / "app.ico", RESOURCE_DIR / "icon.ico", RESOURCE_DIR / "sonar_logo.png"):
        if icon_path.exists():
            return icon_path
    return None


def find_app_logo_path():
    for icon_path in (RESOURCE_DIR / "sonar_logo.png", RESOURCE_DIR / "app.ico", RESOURCE_DIR / "icon.ico"):
        if icon_path.exists():
            return icon_path
    return None


def run_ui(argv: list[str]) -> int:
    keep_debug_capture = KEEP_DEBUG_CAPTURE_ARG in argv or os.environ.get("SONAR_KEEP_DEBUG_CAPTURE") == "1"
    manual_reeling_mode = MANUAL_REELING_ARG in argv or os.environ.get("SONAR_REELING_MANUAL_MODE") == "1"
    qt_argv = [arg for arg in argv if arg not in {KEEP_DEBUG_CAPTURE_ARG, MANUAL_REELING_ARG}]
    app = QApplication(qt_argv)
    load_app_fonts()
    apply_app_font(app)
    app.setApplicationName(APP_NAME)
    app.setApplicationDisplayName(APP_NAME)
    icon_path = find_app_icon_path()
    if icon_path is not None:
        app.setWindowIcon(QIcon(str(icon_path)))
    initial_license_status = _initial_license_status_with_loader(app)
    window = MainWindow(
        keep_debug_capture=keep_debug_capture,
        manual_reeling_mode=manual_reeling_mode,
        initial_license_status=initial_license_status,
        check_license_on_start=False,
    )
    window.show()
    previous_sigint_handler = signal.getsignal(signal.SIGINT)

    def handle_sigint(_signum, _frame) -> None:
        window._request_quit_from_interrupt()

    signal.signal(signal.SIGINT, handle_sigint)
    if "--smoke-test" in argv:
        QTimer.singleShot(1200, window.close)
    try:
        result = app.exec()
    except KeyboardInterrupt:
        window._request_quit_from_interrupt()
        return 130
    finally:
        signal.signal(signal.SIGINT, previous_sigint_handler)
    if window._interrupt_quit_requested:
        return 130
    return result
