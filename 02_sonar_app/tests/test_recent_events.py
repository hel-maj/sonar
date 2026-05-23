from __future__ import annotations

from datetime import datetime

from PySide6.QtWidgets import QApplication

from sonar.core.events import UiEventMessage
from sonar.ui.main_window import MainWindow, RecentUiEvent


def make_window_stub() -> MainWindow:
    window = MainWindow.__new__(MainWindow)
    return window


def process_qt_events(times: int = 20) -> None:
    app = QApplication.instance() or QApplication([])
    for _ in range(times):
        app.processEvents()


def test_recent_event_block_keeps_payload_without_filtering():
    window = make_window_stub()
    window._recent_events = []
    window._refresh_recent_events = lambda: None  # type: ignore[method-assign]

    MainWindow._handle_ui_event(
        window,
        UiEventMessage(
            text='Стрим: режим 10fps, запускаю HLS-видео через FFmpeg',
            event_type='info',
            icon='stream.svg',
            detail='технический текст тоже покажется, если его явно отправили',
            extra_green='+ 1 $',
            created_at=datetime(2026, 5, 23, 12, 0, 0),
        ),
    )

    assert len(window._recent_events) == 1
    event = window._recent_events[0]
    assert event.text == 'Стрим: режим 10fps, запускаю HLS-видео через FFmpeg'
    assert event.event_type == 'info'
    assert event.icon == 'stream.svg'
    assert event.detail == 'технический текст тоже покажется, если его явно отправили'
    assert event.extra_green == '+ 1 $'
    assert event.created_at == datetime(2026, 5, 23, 12, 0, 0)


def test_append_log_does_not_send_logs_to_recent_events():
    window = make_window_stub()
    window._recent_events = []
    window._refresh_recent_events = lambda: None  # type: ignore[method-assign]

    MainWindow.append_log(window, 'Заброс пропущен: стадия рыбалки не найдена')
    MainWindow.append_log(window, 'Настройки сохранены')

    assert window._recent_events == []


def test_recent_events_are_stored_old_to_new_and_limited():
    window = make_window_stub()
    window._recent_events = []
    window._refresh_recent_events = lambda: None  # type: ignore[method-assign]

    for index in range(405):
        MainWindow.add_recent_event(window, f'Событие {index}')

    assert len(window._recent_events) == 400
    assert window._recent_events[0].text == 'Событие 5'
    assert window._recent_events[-1].text == 'Событие 404'


def test_recent_event_detail_is_rendered_inline_without_separate_row():
    event = RecentUiEvent(
        text='Рыбалка остановлена',
        event_type='info',
        detail='вручную',
        created_at=datetime(2026, 5, 23, 12, 0, 0),
    )

    assert MainWindow._recent_event_visible_text(event) == 'Рыбалка остановлена · вручную'


def test_recent_events_detect_bottom_with_small_threshold():
    assert MainWindow._recent_events_is_at_bottom(98, 100)
    assert MainWindow._recent_events_is_at_bottom(100, 100)
    assert not MainWindow._recent_events_is_at_bottom(97, 100)


def test_recent_events_restore_scroll_keeps_user_position_when_not_at_bottom():
    assert MainWindow._recent_events_restore_value(45, 120, False) == 45
    assert MainWindow._recent_events_restore_value(150, 120, False) == 120


def test_recent_events_restore_scroll_moves_to_new_bottom_when_user_was_at_bottom():
    assert MainWindow._recent_events_restore_value(80, 140, True) == 140


def test_recent_events_scroll_follows_bottom_only_when_user_was_at_bottom():
    app = QApplication.instance() or QApplication([])
    window = make_window_stub()
    card = MainWindow._build_recent_events_card(window)
    card.resize(360, 140)
    card.show()

    for index in range(20):
        MainWindow.add_recent_event(window, f'Событие {index}')
    process_qt_events()

    bar = window.recent_events_scroll.verticalScrollBar()
    bar.setValue(bar.maximum())
    MainWindow.add_recent_event(window, 'Новое нижнее событие')
    process_qt_events()

    assert bar.value() == bar.maximum()

    bar.setValue(10)
    user_scroll_value = bar.value()
    MainWindow.add_recent_event(window, 'Событие вне текущего просмотра')
    process_qt_events()

    assert bar.value() == user_scroll_value

    card.close()
    card.deleteLater()
    app.processEvents()

