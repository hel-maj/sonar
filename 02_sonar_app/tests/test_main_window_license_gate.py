from __future__ import annotations

from types import SimpleNamespace

from sonar.license.client import LicenseStatus
from sonar.license.context import LicenseContext
from sonar.license.features import FEATURE_STREAM_CHAT, FEATURE_TELEGRAM
from sonar.streaming.chat import ChatActionResult, ChatDetection
from sonar.ui.main_window import MainWindow


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
        bot=SimpleNamespace(stop_async=lambda: events.append("stop_async")),
        append_log=lambda message: events.append(message),
        _refresh_status_label=lambda: events.append("refresh"),
    )

    MainWindow.stop_bot(window)

    assert window._pending_bot_start_after_license is False
    assert events == ["stop_async", "refresh"]
