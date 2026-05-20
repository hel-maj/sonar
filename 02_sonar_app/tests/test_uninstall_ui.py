from types import SimpleNamespace

from sonar.ui import main_window


class FakeWidget:
    def __init__(self) -> None:
        self._enabled = True
        self._tooltip = ""

    def setEnabled(self, enabled: bool) -> None:
        self._enabled = enabled

    def isEnabled(self) -> bool:
        return self._enabled

    def setToolTip(self, tooltip: str) -> None:
        self._tooltip = tooltip

    def toolTip(self) -> str:
        return self._tooltip


def test_uninstall_button_is_disabled_when_unavailable(tmp_path, monkeypatch):
    fake_window = SimpleNamespace(
        uninstall_button=FakeWidget(),
        uninstall_note_label=FakeWidget(),
    )
    monkeypatch.setattr(
        main_window,
        "get_uninstall_availability",
        lambda: SimpleNamespace(enabled=False, target_dir=tmp_path, reason="source run"),
    )

    main_window.MainWindow._refresh_uninstall_button(fake_window)

    assert fake_window.uninstall_button.isEnabled() is False
    assert "source run" in fake_window.uninstall_button.toolTip()
    assert str(tmp_path) in fake_window.uninstall_button.toolTip()


def test_uninstall_button_is_enabled_when_available(tmp_path, monkeypatch):
    fake_window = SimpleNamespace(
        uninstall_button=FakeWidget(),
        uninstall_note_label=FakeWidget(),
    )
    monkeypatch.setattr(
        main_window,
        "get_uninstall_availability",
        lambda: SimpleNamespace(enabled=True, target_dir=tmp_path, reason=""),
    )

    main_window.MainWindow._refresh_uninstall_button(fake_window)

    assert fake_window.uninstall_button.isEnabled() is True
    assert str(tmp_path) in fake_window.uninstall_button.toolTip()


def test_confirm_uninstall_schedules_after_confirmation(tmp_path, monkeypatch):
    calls = []
    fake_bot = SimpleNamespace(
        stop=lambda: calls.append("stop"),
        notification_manager=SimpleNamespace(stop_polling=lambda: calls.append("stop_polling")),
    )
    fake_window = SimpleNamespace(
        bot=fake_bot,
        append_log=lambda message: calls.append(("log", message)),
        uninstall_button=FakeWidget(),
        uninstall_note_label=FakeWidget(),
    )
    monkeypatch.setattr(
        main_window,
        "get_uninstall_availability",
        lambda: SimpleNamespace(enabled=True, target_dir=tmp_path, reason=""),
    )
    monkeypatch.setattr(
        main_window.QMessageBox,
        "warning",
        lambda *args, **kwargs: main_window.QMessageBox.StandardButton.Yes,
    )
    monkeypatch.setattr(main_window, "schedule_self_uninstall", lambda: tmp_path / "uninstall.cmd")
    monkeypatch.setattr(main_window.QApplication, "quit", lambda: calls.append("quit"))

    main_window.MainWindow.confirm_self_uninstall(fake_window)

    assert calls[0:2] == ["stop", "stop_polling"]
    assert ("log", f"Удаление запланировано: {tmp_path / 'uninstall.cmd'}") in calls
    assert "quit" in calls


def test_confirm_uninstall_does_not_schedule_when_cancelled(tmp_path, monkeypatch):
    calls = []
    fake_window = SimpleNamespace(
        bot=SimpleNamespace(
            stop=lambda: calls.append("stop"),
            notification_manager=SimpleNamespace(stop_polling=lambda: calls.append("stop_polling")),
        ),
        append_log=lambda message: calls.append(("log", message)),
        uninstall_button=FakeWidget(),
        uninstall_note_label=FakeWidget(),
    )
    monkeypatch.setattr(
        main_window,
        "get_uninstall_availability",
        lambda: SimpleNamespace(enabled=True, target_dir=tmp_path, reason=""),
    )
    monkeypatch.setattr(
        main_window.QMessageBox,
        "warning",
        lambda *args, **kwargs: main_window.QMessageBox.StandardButton.No,
    )
    monkeypatch.setattr(main_window, "schedule_self_uninstall", lambda: calls.append("schedule"))

    main_window.MainWindow.confirm_self_uninstall(fake_window)

    assert calls == []
