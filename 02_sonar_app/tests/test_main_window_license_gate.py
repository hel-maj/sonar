from __future__ import annotations

from types import SimpleNamespace

from sonar.license.client import LicenseStatus
from sonar.license.context import LicenseContext
from sonar.license.features import FEATURE_FISHING, FEATURE_FISHING_BOT, FEATURE_STREAM_CHAT, FEATURE_TELEGRAM
from sonar.core.state import BotPhase
from sonar.streaming.chat import ChatActionResult, ChatDetection
from sonar.license.startup_block import StartupBlockStatus
from sonar.ui.main_window import MainWindow, startup_block_allows_launch, startup_block_blocks_running_app


class DummyStack:
    def __init__(self, current_widget: object) -> None:
        self._current_widget = current_widget

    def currentWidget(self) -> object:
        return self._current_widget


def test_license_gate_synchronizes_telegram_runtime_permission():
    overview_tab = object()
    license_tab = object()
    runtime_permissions: list[bool] = []
    disabled_chat_modes: list[bool] = []
    stream_snapshot = SimpleNamespace(chat_mode_enabled=True)
    window = SimpleNamespace(
        license_status=LicenseStatus(
            valid=True,
            group="basic",
            features=("overview", "fishing", "settings", "statistics"),
        ),
        stack=DummyStack(overview_tab),
        license_tab=license_tab,
        overview_tab=overview_tab,
        _licensed_page_features={},
        _nav_buttons={},
        bot=SimpleNamespace(
            state=SimpleNamespace(running=False),
            notification_manager=SimpleNamespace(set_runtime_enabled=runtime_permissions.append),
        ),
        stream_service=SimpleNamespace(
            stop_stream=lambda _reason: None,
            snapshot=lambda: stream_snapshot,
            disable_chat_mode=lambda *, force=False: disabled_chat_modes.append(force),
        ),
        _select_page=lambda _page: None,
    )
    window._has_active_license = lambda: window.license_status.valid and not window.license_status.expired
    window._license_context = lambda: LicenseContext.from_status(window.license_status)
    window._can_use_feature = lambda feature_key: window._license_context().can(feature_key)

    MainWindow._apply_license_gate(window)
    window.license_status = LicenseStatus(
        valid=True,
        group="standard",
        features=("overview", "fishing", "settings", "statistics", FEATURE_TELEGRAM),
    )
    MainWindow._apply_license_gate(window)

    assert runtime_permissions == [False, True]
    assert disabled_chat_modes == [True, True]


def test_license_gate_forces_chat_mode_off_when_entitlement_is_revoked():
    overview_tab = object()
    license_tab = object()
    disabled_chat_modes: list[bool] = []
    window = SimpleNamespace(
        license_status=LicenseStatus(
            valid=True,
            group="streamer",
            features=("overview", "fishing", "settings", "statistics", "stream", "telegram"),
        ),
        stack=DummyStack(overview_tab),
        license_tab=license_tab,
        overview_tab=overview_tab,
        _licensed_page_features={},
        _nav_buttons={},
        bot=SimpleNamespace(
            state=SimpleNamespace(running=False),
            notification_manager=SimpleNamespace(set_runtime_enabled=lambda _enabled: None),
        ),
        stream_service=SimpleNamespace(
            stop_stream=lambda _reason: None,
            snapshot=lambda: SimpleNamespace(chat_mode_enabled=True),
            disable_chat_mode=lambda *, force=False: disabled_chat_modes.append(force),
        ),
        _select_page=lambda _page: None,
    )
    window._has_active_license = lambda: window.license_status.valid and not window.license_status.expired
    window._license_context = lambda: LicenseContext.from_status(window.license_status)
    window._can_use_feature = lambda feature_key: window._license_context().can(feature_key)

    MainWindow._apply_license_gate(window)

    assert window._can_use_feature(FEATURE_STREAM_CHAT) is False
    assert disabled_chat_modes == [True]


def test_failed_chat_close_stops_paused_bot():
    stops: list[str] = []
    window = SimpleNamespace(
        chat_controller=SimpleNamespace(
            close_chat=lambda force=False: ChatActionResult(False, "close failed", ChatDetection(active=True))
        ),
        bot=SimpleNamespace(
            state=SimpleNamespace(running=True),
            stop=stops.append,
        ),
        _resume_bot_after_chat=True,
        log_bridge=SimpleNamespace(message=SimpleNamespace(emit=lambda _message: None)),
    )

    result = MainWindow._disable_chat_mode_from_stream(window)

    assert result.ok is False
    assert stops == ["не удалось закрыть режим чата"]
    assert window._resume_bot_after_chat is False


def test_stop_button_cancels_pending_start_and_requests_async_cleanup():
    events: list[str] = []
    window = SimpleNamespace(
        _pending_bot_start_after_license=True,
        _bot_is_stopping=lambda: False,
        bot=SimpleNamespace(stop_async=lambda: events.append("stop_async")),
        append_log=lambda message: events.append(message),
        _refresh_status_label=lambda: events.append("refresh"),
    )

    MainWindow.stop_bot(window)

    assert window._pending_bot_start_after_license is False
    assert events == ["stop_async", "refresh"]


def test_status_label_disables_controls_and_shows_stopping_badge():
    class Label:
        def __init__(self) -> None:
            self.text = ""

        def setText(self, text: str) -> None:
            self.text = text

    class Button:
        def __init__(self) -> None:
            self.enabled = True

        def setEnabled(self, enabled: bool) -> None:
            self.enabled = enabled

    class Badge(Label):
        def __init__(self) -> None:
            super().__init__()
            self.tone = ""

        def set_tone(self, tone: str) -> None:
            self.tone = tone

    status = Label()
    description = Label()
    start_buttons = [Button(), Button()]
    stop_buttons = [Button(), Button()]
    badge = Badge()
    window = SimpleNamespace(
        bot=SimpleNamespace(
            state=SimpleNamespace(running=False, phase=BotPhase.IDLE),
            is_stopping=lambda: True,
        ),
        _has_active_license=lambda: True,
        _can_use_feature=lambda feature: True,
        _can_start_fishing=lambda: True,
        _bot_is_stopping=lambda: True,
        _license_checking=False,
        _status_labels=[status],
        _status_description_labels=[description],
        _start_buttons=start_buttons,
        _stop_buttons=stop_buttons,
        _ready_badges=[badge],
        _hotkey_badges=[],
        _last_bot_running=False,
        _refresh_system_state=lambda: None,
    )

    MainWindow._refresh_status_label(window)

    assert status.text == "Остановка"
    assert all(not button.enabled for button in start_buttons)
    assert all(not button.enabled for button in stop_buttons)
    assert badge.text == "Остановка"
    assert badge.tone == "orange"


def test_hotkey_logs_and_does_not_toggle_while_bot_is_stopping():
    events: list[str] = []
    window = SimpleNamespace(
        _win32api=SimpleNamespace(GetAsyncKeyState=lambda _vk: 0x8000),
        _hotkey_capture_is_active=lambda: False,
        _can_start_fishing=lambda: True,
        _current_hotkey_vks=lambda: (1,),
        _hotkey_suppressed_until_release=False,
        _hotkey_down=False,
        _bot_is_stopping=lambda: True,
        _log_bot_still_stopping=lambda: events.append("still stopping"),
        _refresh_status_label=lambda: events.append("refresh"),
        toggle_bot=lambda: events.append("toggle"),
    )

    MainWindow._poll_hotkey_impl(window)

    assert events == ["still stopping", "refresh"]
    assert window._hotkey_down is True


def test_intro_license_allows_fishing_page_but_not_bot_start():
    window = SimpleNamespace(
        license_status=LicenseStatus(valid=True, group="intro"),
    )
    window._license_context = lambda: LicenseContext.from_status(window.license_status)
    window._can_use_feature = lambda feature_key: window._license_context().can(feature_key)

    assert window._can_use_feature(FEATURE_FISHING) is True
    assert MainWindow._can_start_fishing(window) is False
    assert window._can_use_feature(FEATURE_FISHING_BOT) is False


def test_startup_block_check_is_required_for_launch():
    assert startup_block_allows_launch(StartupBlockStatus(checked=True, blocked=False)) is True
    assert startup_block_allows_launch(StartupBlockStatus(checked=False, blocked=False, error="request failed")) is False
    assert startup_block_allows_launch(StartupBlockStatus(checked=True, blocked=True, download_url="https://example.test")) is False


def test_runtime_startup_block_ignores_network_errors():
    assert startup_block_blocks_running_app(StartupBlockStatus(checked=False, blocked=False, error="request failed")) is False
    assert startup_block_blocks_running_app(StartupBlockStatus(checked=True, blocked=False)) is False
    assert startup_block_blocks_running_app(StartupBlockStatus(checked=True, blocked=True, download_url="https://example.test")) is True
