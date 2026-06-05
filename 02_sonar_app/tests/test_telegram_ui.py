from __future__ import annotations

from types import SimpleNamespace

from PySide6.QtWidgets import QApplication, QLabel, QLineEdit

from sonar.config.models import SonarSettings, TelegramSettings
from sonar.ui.main_window import MainWindow
from sonar.ui.widgets import ToggleSwitch


def make_window_stub() -> MainWindow:
    QApplication.instance() or QApplication([])
    window = MainWindow.__new__(MainWindow)
    window.telegram_enabled_check = ToggleSwitch("Telegram включён")
    window.telegram_token_input = QLineEdit()
    window.telegram_admins_input = QLineEdit()
    window.telegram_bot_status_label = QLabel()
    window.settings = SonarSettings()
    window._telegram_availability_signature = None
    window._telegram_available = None
    window._telegram_availability_error = ""
    window._telegram_availability_checking_signature = None
    window._queue_telegram_availability_check = lambda: None  # type: ignore[method-assign]
    window._refresh_settings_dirty_state = lambda *args: None  # type: ignore[method-assign]
    return window


def test_telegram_credentials_inputs_lock_when_bot_is_enabled():
    window = make_window_stub()
    window.telegram_token_input.setText("token")
    window.telegram_admins_input.setText("123")

    MainWindow._refresh_telegram_controls_state(window)

    assert not window.telegram_enabled_check.isEnabled()
    assert window.telegram_token_input.isEnabled()
    assert window.telegram_admins_input.isEnabled()

    window._telegram_availability_signature = MainWindow._telegram_availability_key("token", [123])
    window._telegram_available = True
    MainWindow._refresh_telegram_controls_state(window)

    assert window.telegram_enabled_check.isEnabled()
    assert window.telegram_token_input.isEnabled()
    assert window.telegram_admins_input.isEnabled()

    MainWindow._set_telegram_enabled_checked(window, True)
    MainWindow._refresh_telegram_controls_state(window)

    assert window.telegram_enabled_check.isEnabled()
    assert not window.telegram_token_input.isEnabled()
    assert not window.telegram_admins_input.isEnabled()
    assert window.telegram_bot_status_label.text() == "Статус: Включен"


def test_telegram_toggle_reverts_when_credentials_are_missing():
    window = make_window_stub()
    saved_settings = SonarSettings(telegram=TelegramSettings(enabled=True, bot_token="old-token", admin_ids=[1]))
    saves: list[SonarSettings] = []
    logs: list[str] = []
    window.config_manager = SimpleNamespace(load=lambda: saved_settings, save=saves.append)
    window.bot = SimpleNamespace(reload_settings=lambda: None)
    window.append_log = logs.append
    window._refresh_overview_telegram_card = lambda: None  # type: ignore[method-assign]
    window.telegram_token_input.setText("")
    window.telegram_admins_input.setText("")
    MainWindow._set_telegram_enabled_checked(window, True)

    MainWindow._telegram_enabled_changed(window)

    assert not window.telegram_enabled_check.isChecked()
    assert saves == []
    assert logs == ["Telegram не включён: укажите токен бота и ID администраторов"]


def test_telegram_toggle_reverts_when_telegram_is_unavailable():
    window = make_window_stub()
    saved_settings = SonarSettings(telegram=TelegramSettings(enabled=False, bot_token="", admin_ids=[]))
    saves: list[SonarSettings] = []
    logs: list[str] = []
    window.config_manager = SimpleNamespace(load=lambda: saved_settings, save=saves.append)
    window.bot = SimpleNamespace(reload_settings=lambda: None)
    window.append_log = logs.append
    window._refresh_overview_telegram_card = lambda: None  # type: ignore[method-assign]
    window.telegram_token_input.setText("bad-token")
    window.telegram_admins_input.setText("123")
    window._telegram_availability_signature = MainWindow._telegram_availability_key("bad-token", [123])
    window._telegram_available = False
    window._telegram_availability_error = "Неверный токен"
    MainWindow._set_telegram_enabled_checked(window, True)

    MainWindow._telegram_enabled_changed(window)

    assert not window.telegram_enabled_check.isChecked()
    assert saves == []
    assert logs == ["Telegram не включён: Неверный токен"]


def test_telegram_successful_check_is_bound_to_current_token():
    window = make_window_stub()
    window.telegram_token_input.setText("old-token")
    window.telegram_admins_input.setText("123")
    window._telegram_availability_signature = MainWindow._telegram_availability_key("old-token", [123])
    window._telegram_available = True

    MainWindow._refresh_telegram_controls_state(window)
    assert window.telegram_enabled_check.isEnabled()

    window.telegram_token_input.setText("new-token")
    MainWindow._refresh_telegram_controls_state(window)

    assert not window.telegram_enabled_check.isEnabled()
    assert window.telegram_bot_status_label.text() == "Статус: Недоступен"


def test_telegram_runtime_requires_successful_check_for_saved_settings():
    window = make_window_stub()
    runtime_permissions: list[bool] = []
    window.settings = SonarSettings(telegram=TelegramSettings(enabled=True, bot_token="token", admin_ids=[123]))
    window.bot = SimpleNamespace(notification_manager=SimpleNamespace(set_runtime_enabled=runtime_permissions.append))

    MainWindow._refresh_telegram_runtime_state(window)

    window._telegram_availability_signature = MainWindow._telegram_availability_key("token", [123])
    window._telegram_available = True
    MainWindow._refresh_telegram_runtime_state(window)

    assert runtime_permissions == [False, True]
