from __future__ import annotations

from PySide6.QtCore import Qt

from sonar.ui.main_window import MainWindow
from sonar.ui.widgets import HotkeyButton


def test_hotkey_button_normalizes_and_displays_combinations():
    assert HotkeyButton._normalize_hotkey('Ctrl + f9') == 'ctrl+F9'
    assert HotkeyButton._normalize_hotkey('control+shift+x') == 'ctrl+shift+x'
    assert HotkeyButton._display_hotkey('ctrl+F9') == 'Ctrl + F9'
    assert HotkeyButton._display_hotkey('ctrl+shift+x') == 'Ctrl + Shift + X'


def test_hotkey_button_builds_combination_from_key_event():
    assert HotkeyButton._hotkey_from_key_event(
        int(Qt.Key.Key_F9),
        '',
        Qt.KeyboardModifier.ControlModifier,
    ) == 'ctrl+F9'
    assert HotkeyButton._key_name_from_key_event(int(Qt.Key.Key_Escape), '') == ''


def test_main_window_hotkey_parser_supports_combinations():
    assert MainWindow._hotkey_to_vks('F9') == (0x78,)
    assert MainWindow._hotkey_to_vks('ctrl+F9') == (0x11, 0x78)
    assert MainWindow._hotkey_to_vks('ctrl + shift + x') == (0x11, 0x10, 0x58)
    assert MainWindow._hotkey_to_vks('ctrl+unknown') == ()
