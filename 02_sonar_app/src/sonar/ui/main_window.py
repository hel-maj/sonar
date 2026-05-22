from __future__ import annotations

import html
import os
import re
import threading
from datetime import datetime, timezone
from pathlib import Path

from PyQt6.QtCore import QObject, QRegularExpression, QTimer, Qt, pyqtSignal
from PyQt6.QtGui import QIcon, QRegularExpressionValidator
from PyQt6.QtWidgets import (
    QApplication,
    QAbstractItemView,
    QCheckBox,
    QComboBox,
    QFileDialog,
    QFormLayout,
    QGridLayout,
    QGroupBox,
    QHeaderView,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QMainWindow,
    QMessageBox,
    QPushButton,
    QScrollArea,
    QStyledItemDelegate,
    QTableWidget,
    QTableWidgetItem,
    QTabWidget,
    QVBoxLayout,
    QWidget,
)

from sonar.config.manager import ConfigManager
from sonar.config.models import SonarSettings
from sonar.build_metadata import APP_BUILD_HASH, APP_NAME
from sonar.fishing.bot import FishingBot
from sonar.fishing.fish_names import FISH_DISPLAY_NAMES
from sonar.fishing.statistics import (
    FishingSessionStats,
    format_base_price,
    format_catch_summary,
    format_duration,
    format_money_range,
    format_weight,
    parse_fish_prices_from_markdown,
)
from sonar.fishing.statistics_export import default_stats_csv_path, write_stats_csv
from sonar.fishing.tackle_detection import format_tackle_items
from sonar.license.client import LicenseStatus
from sonar.license.manager import LicenseManager
from sonar.paths import APP_DIR, RESOURCE_DIR
from sonar.self_uninstall import get_uninstall_availability, schedule_self_uninstall
from sonar.streaming import StreamingService
from sonar.streaming.chat import ChatActionResult, ChatDetection, MajesticChatController
from sonar.version import APP_VERSION


URL_RE = re.compile(r"https?://[^\s<>'\"]+", re.IGNORECASE)
TRAILING_URL_PUNCTUATION = ".,;:!?)]}"
LICENSE_REFRESH_INTERVAL_SECONDS = 600
KEEP_DEBUG_CAPTURE_ARG = "--keep-debug-capture"


def format_update_message_html(text: str) -> str:
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


class LogBridge(QObject):
    message = pyqtSignal(str)


class LicenseBridge(QObject):
    result = pyqtSignal(object)


class TelegramSettingsBridge(QObject):
    changed = pyqtSignal(object)


class DigitsOnlyDelegate(QStyledItemDelegate):
    def createEditor(self, parent, option, index):  # type: ignore[override]
        editor = QLineEdit(parent)
        editor.setValidator(QRegularExpressionValidator(QRegularExpression(r"\d*"), editor))
        return editor

    def setModelData(self, editor, model, index) -> None:  # type: ignore[override]
        text = re.sub(r"\D", "", editor.text())
        model.setData(index, text, Qt.ItemDataRole.EditRole)


class MainWindow(QMainWindow):
    def __init__(self, *, keep_debug_capture: bool = False) -> None:
        super().__init__()
        self.config_manager = ConfigManager()
        self.settings = self.config_manager.load()
        self.license_manager = LicenseManager(self.config_manager)
        self.license_status = LicenseStatus()
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
        self.log_bridge = LogBridge()
        self.log_bridge.message.connect(self.append_log)
        self.bot = FishingBot(
            log_callback=self.log_bridge.message.emit,
            config_manager=self.config_manager,
            session_stats=self.session_stats,
            can_start_callback=self._has_active_license,
            start_command_callback=self._start_bot_from_remote,
            telegram_settings_changed_callback=self.telegram_settings_bridge.changed.emit,
            keep_debug_capture=keep_debug_capture,
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
        self.setWindowTitle(APP_NAME)
        icon_path = find_app_icon_path()
        if icon_path is not None:
            self.setWindowIcon(QIcon(str(icon_path)))
        self.resize(980, 680)
        self._build_ui()
        self._load_settings_to_ui(self.settings)
        self.telegram_enabled_check.stateChanged.connect(self._telegram_enabled_changed)
        self._refresh_license_ui()
        self._apply_license_gate()
        self._start_saved_license_check()
        self._hotkey_down = False
        self.hotkey_timer = QTimer(self)
        self.hotkey_timer.timeout.connect(self._poll_hotkey)
        self.hotkey_timer.start(80)
        self.status_timer = QTimer(self)
        self.status_timer.timeout.connect(self._refresh_status_label)
        self.status_timer.start(250)
        self.stats_timer = QTimer(self)
        self.stats_timer.timeout.connect(self._refresh_stats_tab)
        self.stats_timer.start(1000)
        self.stream_timer = QTimer(self)
        self.stream_timer.timeout.connect(self._refresh_stream_tab)
        self.stream_timer.start(1000)
        self.license_timer = QTimer(self)
        self.license_timer.timeout.connect(self._license_tick)
        self.license_timer.start(1000)
        QTimer.singleShot(0, self._notify_app_started)

    def _build_ui(self) -> None:
        self.tabs = QTabWidget()
        self.setCentralWidget(self.tabs)
        self.license_tab = self._build_license_tab()
        self.fishing_tab = self._build_fishing_tab()
        self.settings_tab = self._build_settings_tab()
        self.statistics_tab = self._build_statistics_tab()
        self.telegram_tab = self._build_telegram_tab()
        self.stream_tab = self._build_stream_tab()
        self._licensed_tabs = [
            (self.fishing_tab, "Рыбалка"),
            (self.settings_tab, "Настройки"),
            (self.statistics_tab, "Статистика"),
            (self.stream_tab, "Стрим"),
            (self.telegram_tab, "Telegram"),
        ]
        self._apply_license_gate()

    def _build_license_tab(self) -> QWidget:
        page = QWidget()
        layout = QVBoxLayout(page)
        group = QGroupBox("Лицензия")
        form = QFormLayout(group)
        self.license_summary_label = QLabel("Введите ключ лицензии")
        self.license_summary_label.setWordWrap(True)
        self.license_key_input = QLineEdit()
        self.license_key_input.setPlaceholderText("FA5B1-...-G2K34")
        self.license_key_input.setEchoMode(QLineEdit.EchoMode.Password)
        self.license_activate_button = QPushButton("Активировать")
        self.license_activate_button.clicked.connect(self.activate_license)
        self.license_status_label = QLabel("")
        self.license_status_label.setWordWrap(True)
        form.addRow(self.license_summary_label)
        form.addRow("Ключ", self.license_key_input)
        form.addRow(self.license_activate_button)
        form.addRow(self.license_status_label)
        layout.addWidget(group)
        layout.addStretch(1)
        return page

    def _build_fishing_tab(self) -> QWidget:
        page = QWidget()
        layout = QVBoxLayout(page)
        self.update_group = QGroupBox("Обновление")
        update_layout = QVBoxLayout(self.update_group)
        self.update_label = QLabel("")
        self.update_label.setWordWrap(True)
        self.update_label.setTextFormat(Qt.TextFormat.RichText)
        self.update_label.setTextInteractionFlags(Qt.TextInteractionFlag.TextBrowserInteraction)
        self.update_label.setOpenExternalLinks(True)
        update_layout.addWidget(self.update_label)
        self.update_group.hide()
        layout.addWidget(self.update_group)
        header = QHBoxLayout()
        self.status_label = QLabel("Остановлен")
        self.status_label.setAlignment(Qt.AlignmentFlag.AlignVCenter)
        self.start_button = QPushButton("Запустить")
        self.stop_button = QPushButton("Остановить")
        self.start_button.clicked.connect(self.start_bot)
        self.stop_button.clicked.connect(self.stop_bot)
        header.addWidget(QLabel("Статус:"))
        header.addWidget(self.status_label, 1)
        header.addWidget(self.start_button)
        header.addWidget(self.stop_button)
        layout.addLayout(header)
        layout.addStretch(1)
        return page

    def _build_settings_tab(self) -> QWidget:
        page = QWidget()
        layout = QVBoxLayout(page)
        group = QGroupBox("Рыбалка")
        form = QFormLayout(group)
        self.auto_meal_check = QCheckBox()
        self.auto_change_bait_check = QCheckBox()
        self.store_backpack_check = QCheckBox()
        self.store_trunk_check = QCheckBox()
        self.start_stop_sound_check = QCheckBox()
        self.overweight_action_combo = QComboBox()
        self.overweight_action_combo.addItem("Отпускать рыбу", "release")
        self.overweight_action_combo.addItem("Остановить рыбалку", "stop")
        self.overweight_action_combo.addItem("Выключить игру", "exit_game")
        self.fish_without_leader_check = QCheckBox()
        self.leader_note_label = QLabel("Если вы рыбачите с удочки, то оставьте выключенным")
        self.leader_note_label.setWordWrap(True)
        self.leader_depleted_action_combo = QComboBox()
        self.leader_depleted_action_combo.addItem("Рыбалка остановится", "stop")
        self.leader_depleted_action_combo.addItem("Закроется игра", "exit_game")
        self.fish_without_net_check = QCheckBox()
        self.net_depleted_action_combo = QComboBox()
        self.net_depleted_action_combo.addItem("Рыбалка остановится", "stop")
        self.net_depleted_action_combo.addItem("Закроется игра", "exit_game")
        self.equipment_depleted_action_combo = QComboBox()
        self.equipment_depleted_action_combo.addItem("Остановить бота", "stop")
        self.equipment_depleted_action_combo.addItem("Закрыть игру", "exit_game")
        self.equipment_depleted_action_combo.addItem("Выключить компьютер", "shutdown_pc")
        self.fish_without_leader_check.stateChanged.connect(self._refresh_tackle_action_controls)
        self.fish_without_net_check.stateChanged.connect(self._refresh_tackle_action_controls)
        self.hotkey_input = QLineEdit()
        self.inventory_hotkey_input = QLineEdit()
        self.use_item_hotkey_input = QLineEdit()
        self.discard_key_input = QLineEdit()
        self.chat_hotkey_input = QLineEdit()
        form.addRow("Авто-питание", self.auto_meal_check)
        form.addRow("Авто-смена наживки", self.auto_change_bait_check)
        form.addRow("Складывать в рюкзак", self.store_backpack_check)
        form.addRow("Складывать в багажник", self.store_trunk_check)
        form.addRow("Звук включения/отключения", self.start_stop_sound_check)
        form.addRow("Что делать при перевесе", self.overweight_action_combo)
        form.addRow("Рыбалка без поводка", self.fish_without_leader_check)
        form.addRow("", self.leader_note_label)
        form.addRow("Если закончились поводки", self.leader_depleted_action_combo)
        form.addRow("Рыбалка без подсака", self.fish_without_net_check)
        form.addRow("Если закончился подсак", self.net_depleted_action_combo)
        form.addRow("Если закончилось снаряжение", self.equipment_depleted_action_combo)
        form.addRow("Горячая клавиша", self.hotkey_input)
        form.addRow("Клавиша инвентаря", self.inventory_hotkey_input)
        form.addRow("Клавиша использования", self.use_item_hotkey_input)
        form.addRow("Клавиша выброса", self.discard_key_input)
        form.addRow("Клавиша чата", self.chat_hotkey_input)
        layout.addWidget(group)

        fish_group = QGroupBox("Рыбу оставлять")
        fish_layout = QVBoxLayout(fish_group)
        fish_scroll = QScrollArea()
        fish_scroll.setWidgetResizable(True)
        fish_widget = QWidget()
        fish_grid = QGridLayout(fish_widget)
        self.fish_checks: dict[str, QCheckBox] = {}
        for index, fish_id in enumerate(sorted(FISH_DISPLAY_NAMES, key=lambda item: FISH_DISPLAY_NAMES[item])):
            checkbox = QCheckBox(FISH_DISPLAY_NAMES[fish_id])
            self.fish_checks[fish_id] = checkbox
            fish_grid.addWidget(checkbox, index // 2, index % 2)
        fish_scroll.setWidget(fish_widget)
        fish_layout.addWidget(fish_scroll)
        layout.addWidget(fish_group, 1)

        self.save_settings_button = QPushButton("Сохранить настройки")
        self.save_settings_button.clicked.connect(self.save_settings)
        layout.addWidget(self.save_settings_button)

        uninstall_group = QGroupBox("Удаление")
        uninstall_layout = QVBoxLayout(uninstall_group)
        self.uninstall_note_label = QLabel(
            "Удалит всю папку программы вместе с настройками. Файлы не попадут в корзину."
        )
        self.uninstall_note_label.setWordWrap(True)
        self.uninstall_button = QPushButton("Удалить бота")
        self.uninstall_button.clicked.connect(self.confirm_self_uninstall)
        uninstall_layout.addWidget(self.uninstall_note_label)
        uninstall_layout.addWidget(self.uninstall_button)
        layout.addWidget(uninstall_group)
        self._refresh_uninstall_button()
        return page

    def _build_statistics_tab(self) -> QWidget:
        page = QWidget()
        layout = QVBoxLayout(page)
        totals_group = QGroupBox("Всего")
        totals_grid = QGridLayout(totals_group)
        self.stats_duration_label = QLabel("0 мин")
        self.stats_caught_label = QLabel("0 шт · 0 кг")
        self.stats_released_label = QLabel("0 шт · 0 кг")
        self.stats_income_label = QLabel("0 $")
        self.stats_income_per_hour_label = QLabel("0 $")
        self.stats_kept_label = QLabel("0 кг")
        totals_grid.addWidget(QLabel("Время рыбалки:"), 0, 0)
        totals_grid.addWidget(self.stats_duration_label, 0, 1)
        totals_grid.addWidget(QLabel("Поймано:"), 1, 0)
        totals_grid.addWidget(self.stats_caught_label, 1, 1)
        totals_grid.addWidget(QLabel("Отпущено:"), 2, 0)
        totals_grid.addWidget(self.stats_released_label, 2, 1)
        totals_grid.addWidget(QLabel("Общий вес:"), 3, 0)
        totals_grid.addWidget(self.stats_kept_label, 3, 1)
        totals_grid.addWidget(QLabel("Доход:"), 4, 0)
        totals_grid.addWidget(self.stats_income_label, 4, 1)
        totals_grid.addWidget(QLabel("Доход в час:"), 5, 0)
        totals_grid.addWidget(self.stats_income_per_hour_label, 5, 1)
        self.reset_stats_button = QPushButton("Сбросить сессию")
        self.reset_stats_button.clicked.connect(self.reset_session_stats)
        self.export_stats_button = QPushButton("Выгрузить CSV")
        self.export_stats_button.clicked.connect(self.export_stats_csv)
        totals_grid.addWidget(self.reset_stats_button, 6, 0)
        totals_grid.addWidget(self.export_stats_button, 6, 1)
        layout.addWidget(totals_group)

        tackle_group = QGroupBox("Снаряжение")
        tackle_layout = QVBoxLayout(tackle_group)
        self.stats_tackle_label = QLabel("Снаряжение ещё не сканировалось")
        self.stats_tackle_label.setWordWrap(True)
        tackle_layout.addWidget(self.stats_tackle_label)
        layout.addWidget(tackle_group)

        self.stats_table = QTableWidget(0, 6)
        self.stats_table.setHorizontalHeaderLabels(
            [
                "Рыба",
                "Поймано",
                "Отпущено",
                "Цена",
                "Своя цена за 1000",
                "Доход",
            ]
        )
        self.stats_table.horizontalHeader().setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        self.stats_price_delegate = DigitsOnlyDelegate(self.stats_table)
        self.stats_table.setItemDelegateForColumn(4, self.stats_price_delegate)
        self.stats_table.itemChanged.connect(self._stats_price_changed)
        layout.addWidget(self.stats_table, 1)
        self._refresh_stats_tab()
        return page

    def _build_telegram_tab(self) -> QWidget:
        page = QWidget()
        layout = QVBoxLayout(page)
        group = QGroupBox("Telegram")
        form = QFormLayout(group)
        self.telegram_enabled_check = QCheckBox()
        self.telegram_token_input = QLineEdit()
        self.telegram_token_input.setEchoMode(QLineEdit.EchoMode.Password)
        self.telegram_admins_input = QLineEdit()
        self.telegram_notify_catch_check = QCheckBox()
        self.telegram_notify_start_stop_check = QCheckBox()
        self.telegram_notify_meal_check = QCheckBox()
        self.telegram_notify_inventory_full_check = QCheckBox()
        self.telegram_notify_focus_lost_check = QCheckBox()
        form.addRow("Включён", self.telegram_enabled_check)
        form.addRow("Токен бота", self.telegram_token_input)
        form.addRow("ID администраторов", self.telegram_admins_input)
        form.addRow("Улов", self.telegram_notify_catch_check)
        form.addRow("Запуск/Остановка", self.telegram_notify_start_stop_check)
        form.addRow("Питание", self.telegram_notify_meal_check)
        form.addRow("Закончилось место", self.telegram_notify_inventory_full_check)
        layout.addWidget(group)
        button = QPushButton("Сохранить Telegram")
        form.addRow("Потеря фокуса игры", self.telegram_notify_focus_lost_check)
        button.clicked.connect(self.save_settings)
        layout.addWidget(button)
        layout.addStretch(1)
        return page

    def _build_stream_tab(self) -> QWidget:
        page = QWidget()
        layout = QVBoxLayout(page)

        status_group = QGroupBox("Управление стримом")
        grid = QGridLayout(status_group)
        self.stream_status_label = QLabel("offline")
        self.stream_area_label = QLabel("Все окно")
        self.stream_quality_label = QLabel("720p")
        self.stream_auto_stop_label = QLabel("—")
        self.stream_url_label = QLabel("—")
        self.stream_url_label.setWordWrap(True)
        self.stream_url_label.setTextFormat(Qt.TextFormat.RichText)
        self.stream_url_label.setTextInteractionFlags(Qt.TextInteractionFlag.TextBrowserInteraction)
        self.stream_url_label.setOpenExternalLinks(True)
        grid.addWidget(QLabel("Статус:"), 0, 0)
        grid.addWidget(self.stream_status_label, 0, 1)
        grid.addWidget(QLabel("Область:"), 1, 0)
        grid.addWidget(self.stream_area_label, 1, 1)
        grid.addWidget(QLabel("Качество:"), 2, 0)
        grid.addWidget(self.stream_quality_label, 2, 1)
        grid.addWidget(QLabel("Автостоп:"), 3, 0)
        grid.addWidget(self.stream_auto_stop_label, 3, 1)
        grid.addWidget(QLabel("Ссылка:"), 4, 0)
        grid.addWidget(self.stream_url_label, 4, 1)
        layout.addWidget(status_group)

        controls_group = QGroupBox("Настройки трансляции")
        controls = QFormLayout(controls_group)
        self.stream_quality_combo = QComboBox()
        self.stream_quality_combo.addItems(["480p", "720p", "1080p"])
        self.stream_quality_combo.setCurrentText("720p")
        self.stream_quality_combo.currentTextChanged.connect(self._stream_quality_changed)
        self.stream_chat_zoom_check = QCheckBox("Увеличить чат")
        self.stream_chat_zoom_check.stateChanged.connect(self._stream_chat_zoom_changed)
        self.stream_snapshot_mode_check = QCheckBox("Режим 10fps")
        self.stream_snapshot_mode_check.stateChanged.connect(self._stream_snapshot_mode_changed)
        controls.addRow("Качество", self.stream_quality_combo)
        controls.addRow("Область чата", self.stream_chat_zoom_check)
        controls.addRow("Скриншоты", self.stream_snapshot_mode_check)
        layout.addWidget(controls_group)

        buttons = QHBoxLayout()
        self.stream_start_button = QPushButton("Запустить стрим")
        self.stream_start_button.clicked.connect(self.start_stream)
        self.stream_stop_button = QPushButton("Остановить стрим")
        self.stream_stop_button.clicked.connect(self.stop_stream)
        self.stream_chat_mode_button = QPushButton("Включить режим чата")
        self.stream_chat_mode_button.clicked.connect(self.enable_chat_mode)
        buttons.addWidget(self.stream_start_button)
        buttons.addWidget(self.stream_stop_button)
        buttons.addWidget(self.stream_chat_mode_button)
        layout.addLayout(buttons)

        note = QLabel("Стрим можно запускать здесь или из Telegram. Режим чата приостанавливает рыбалку и восстанавливает её при выходе.")
        note.setWordWrap(True)
        layout.addWidget(note)
        layout.addStretch(1)
        self._refresh_stream_tab()
        return page

    def _load_settings_to_ui(self, settings: SonarSettings) -> None:
        fishing = settings.fishing
        self.auto_meal_check.setChecked(fishing.auto_meal)
        self.auto_change_bait_check.setChecked(fishing.auto_change_bait)
        self.store_backpack_check.setChecked(fishing.store_in_backpack)
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
        self._refresh_tackle_action_controls()
        self.hotkey_input.setText(fishing.hotkey)
        self.inventory_hotkey_input.setText(fishing.inventory_hotkey)
        self.use_item_hotkey_input.setText(fishing.use_item_hotkey)
        self.discard_key_input.setText(fishing.discard_key)
        self.chat_hotkey_input.setText(fishing.chat_hotkey)
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
            self.telegram_notify_focus_lost_check.setChecked(telegram.notify_focus_lost)
        finally:
            for widget, old_state in zip(widgets, old_states):
                widget.blockSignals(old_state)

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
                self.tabs.setCurrentWidget(self.license_tab)
                self.status_label.setText("Лицензия не активна")
                self.append_log("Лицензия не активна")

    def _has_active_license(self) -> bool:
        return self.license_status.valid and not self.license_status.expired

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
        if not hasattr(self, "tabs") or not hasattr(self, "license_tab"):
            return
        current = self.tabs.currentWidget()
        self.tabs.clear()
        self.tabs.addTab(self.license_tab, "Лицензия")
        if self._has_active_license():
            for widget, title in self._licensed_tabs:
                self.tabs.addTab(widget, title)
            if current and current is not self.license_tab:
                self.tabs.setCurrentWidget(current)
        else:
            self.tabs.setCurrentWidget(self.license_tab)
            if hasattr(self, "bot") and self.bot.state.running:
                self.bot.stop()
            if hasattr(self, "stream_service"):
                self.stream_service.stop_stream("license inactive")

    def _refresh_license_ui(self) -> None:
        if not hasattr(self, "license_summary_label"):
            return
        status = self.license_status
        if status.valid:
            expires = self._format_license_expiry(status.expires_at)
            left = self._format_license_left(status.expires_at)
            self.license_summary_label.setText(f"🔑 Лицензия {status.masked_key}")
            self.license_status_label.setText(f"Статус: 🟢Активна\nИстекает: {expires}\nОсталось: 🕐 {left}")
            self.license_key_input.setText(status.license_key)
        else:
            error = status.error or "Лицензия не активна"
            self.license_summary_label.setText("Введите ключ лицензии")
            self.license_status_label.setText(f"Статус: 🔴Не активна\n{error}")

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
        if not hasattr(self, "update_group"):
            return
        latest = self.license_status.latest_version.strip()
        if self._has_active_license() and latest and latest != APP_VERSION:
            message = self.license_status.update_message.strip()
            text = f"💡 Вышла новая версия: {latest}!"
            if message:
                text = f"{text}\n{message}"
            self.update_label.setText(format_update_message_html(text))
            self.update_group.show()
        else:
            self.update_group.hide()

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
        fishing.auto_change_bait = self.auto_change_bait_check.isChecked()
        fishing.store_in_backpack = self.store_backpack_check.isChecked()
        fishing.store_in_trunk = self.store_trunk_check.isChecked()
        fishing.start_stop_sound_enabled = self.start_stop_sound_check.isChecked()
        fishing.overweight_action = str(self.overweight_action_combo.currentData() or "stop")
        fishing.shutdown_on_overweight = fishing.overweight_action == "stop"
        fishing.fish_without_leader = self.fish_without_leader_check.isChecked()
        fishing.leader_depleted_action = str(self.leader_depleted_action_combo.currentData() or "stop")
        fishing.fish_without_net = self.fish_without_net_check.isChecked()
        fishing.net_depleted_action = str(self.net_depleted_action_combo.currentData() or "stop")
        fishing.equipment_depleted_action = str(self.equipment_depleted_action_combo.currentData() or "stop")
        fishing.hotkey = self.hotkey_input.text().strip() or "F9"
        fishing.inventory_hotkey = self.inventory_hotkey_input.text().strip() or "i"
        fishing.use_item_hotkey = self.use_item_hotkey_input.text().strip() or "e"
        fishing.discard_key = self.discard_key_input.text().strip() or "q"
        fishing.chat_hotkey = self.chat_hotkey_input.text().strip() or "t"
        if hasattr(self, "stream_snapshot_mode_check"):
            fishing.stream_snapshot_mode = self.stream_snapshot_mode_check.isChecked()
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
        telegram.notify_focus_lost = self.telegram_notify_focus_lost_check.isChecked()
        return settings

    def save_settings(self) -> None:
        self.settings = self._collect_settings_from_ui()
        self.config_manager.save(self.settings)
        self.session_stats.set_custom_prices(self.settings.fishing.custom_fish_prices)
        self.bot.reload_settings()
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

    def start_bot(self) -> None:
        try:
            if self.bot.state.running:
                return
            key = self._current_license_key()
            if not key:
                self.tabs.setCurrentWidget(self.license_tab)
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
            if not self._has_active_license():
                self.tabs.setCurrentWidget(self.license_tab)
                self.status_label.setText("Лицензия не активна")
                self.append_log("Лицензия не активна")
                return
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
        if not status.valid or status.expired:
            self.log_bridge.message.emit("Лицензия не активна")
            return False
        return self.bot.start(skip_license_check=True)

    def stop_bot(self) -> None:
        try:
            self.bot.stop()
        except Exception as exc:
            self.append_log(f"Ошибка остановки: {exc}")
        finally:
            self._refresh_status_label()

    def toggle_bot(self) -> None:
        if self.bot.state.running:
            self.stop_bot()
        else:
            self.start_bot()

    def _poll_hotkey(self) -> None:
        if not self._has_active_license():
            return
        vk = self._hotkey_to_vk(self.hotkey_input.text().strip() or "F9")
        if vk is None:
            return
        try:
            import win32api
        except ImportError:
            return
        is_down = bool(win32api.GetAsyncKeyState(vk) & 0x8000)
        if is_down and not self._hotkey_down:
            QTimer.singleShot(0, self.toggle_bot)
        self._hotkey_down = is_down

    @staticmethod
    def _hotkey_to_vk(hotkey: str) -> int | None:
        key = hotkey.upper().strip()
        if key.startswith("F") and key[1:].isdigit():
            num = int(key[1:])
            if 1 <= num <= 24:
                return 0x70 + num - 1
        if len(key) == 1 and key.isalnum():
            return ord(key)
        return None

    def append_log(self, text: str) -> None:
        del text
        return

    def _refresh_status_label(self) -> None:
        if not self._has_active_license():
            self.status_label.setText("Лицензия не активна")
            return
        if self.bot.state.running:
            self.status_label.setText(f"Работает: {self.bot.state.detected_stage}")
        else:
            self.status_label.setText("Остановлен")

    def _refresh_stats_tab(self) -> None:
        if not hasattr(self, "stats_table"):
            return
        totals = self.session_stats.totals()
        self.stats_duration_label.setText(format_duration(totals.duration_seconds))
        self.stats_caught_label.setText(format_catch_summary(totals.caught_count, totals.caught_kg))
        self.stats_released_label.setText(format_catch_summary(totals.released_count, totals.released_kg))
        self.stats_kept_label.setText(format_weight(totals.kept_kg))
        self.stats_income_label.setText(format_money_range(totals.earned_min, totals.earned_max))
        if totals.duration_seconds > 0:
            self.stats_income_per_hour_label.setText(format_money_range(totals.earned_per_hour_min, totals.earned_per_hour_max))
        else:
            self.stats_income_per_hour_label.setText("0 $")
        if hasattr(self, "stats_tackle_label"):
            self.stats_tackle_label.setText(format_tackle_items(self.session_stats.tackle_items()))
        if (
            self.stats_table.state() == QAbstractItemView.State.EditingState
            and self.stats_table.currentColumn() == 4
        ):
            return
        rows = self.session_stats.rows()
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
                if column == 4:
                    item.setData(Qt.ItemDataRole.UserRole, stat.fish_id)
                else:
                    item.setFlags(item.flags() & ~Qt.ItemFlag.ItemIsEditable)
                self.stats_table.setItem(row_index, column, item)
        self.stats_table.blockSignals(False)
        self._stats_refreshing = False

    def _stats_price_changed(self, item: QTableWidgetItem) -> None:
        if self._stats_refreshing or item.column() != 4:
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
        if not self._has_active_license():
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
        snapshot = self.stream_service.snapshot()
        self.stream_service.set_chat_mode_enabled(not (snapshot.chat_active or snapshot.chat_mode_enabled))
        self._refresh_stream_tab()

    def _enable_chat_mode_from_stream(self) -> ChatActionResult:
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
            return self.license_manager.cached_status().role
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
            url = html.escape(snapshot.stream_url, quote=True)
            self.stream_url_label.setText(f'<a href="{url}">{html.escape(snapshot.stream_url, quote=False)}</a>')
        elif snapshot.error:
            self.stream_url_label.setText(html.escape(snapshot.error, quote=False))
        else:
            self.stream_url_label.setText("—")
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
        self.stream_start_button.setEnabled((not snapshot.active) and snapshot.status not in {"starting", "preparing"})
        self.stream_stop_button.setEnabled(snapshot.active or snapshot.status in {"starting", "preparing", "error"})
        self.stream_chat_mode_button.setText(
            "Выйти из режима чата" if snapshot.chat_active or snapshot.chat_mode_enabled else "Включить режим чата"
        )
        self.stream_chat_mode_button.setEnabled(snapshot.active or snapshot.chat_active or snapshot.chat_mode_enabled)

    def reset_session_stats(self) -> None:
        self.session_stats.reset()
        self._refresh_stats_tab()

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
        write_stats_csv(path, self.session_stats, app_name=APP_NAME, build_hash=APP_BUILD_HASH)
        self.append_log(f"Статистика выгружена: {path}")

    def closeEvent(self, event) -> None:  # type: ignore[override]
        try:
            self.settings = self._collect_settings_from_ui()
            self.config_manager.save(self.settings)
            self.bot.reload_settings()
        except Exception:
            pass
        if hasattr(self, "stream_service"):
            self.stream_service.stop_stream("app close")
        self.bot.stop()
        self._notify_app_stopped()
        self.bot.notification_manager.stop_polling()
        event.accept()


def find_app_icon_path():
    for icon_path in (RESOURCE_DIR / "app.ico", RESOURCE_DIR / "icon.ico"):
        if icon_path.exists():
            return icon_path
    return None


def run_ui(argv: list[str]) -> int:
    keep_debug_capture = KEEP_DEBUG_CAPTURE_ARG in argv or os.environ.get("SONAR_KEEP_DEBUG_CAPTURE") == "1"
    qt_argv = [arg for arg in argv if arg != KEEP_DEBUG_CAPTURE_ARG]
    app = QApplication(qt_argv)
    app.setApplicationName(APP_NAME)
    app.setApplicationDisplayName(APP_NAME)
    icon_path = find_app_icon_path()
    if icon_path is not None:
        app.setWindowIcon(QIcon(str(icon_path)))
    window = MainWindow(keep_debug_capture=keep_debug_capture)
    window.show()
    if "--smoke-test" in argv:
        QTimer.singleShot(1200, window.close)
    return app.exec()
