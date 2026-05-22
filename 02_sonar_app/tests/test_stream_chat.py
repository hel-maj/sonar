from __future__ import annotations

from pathlib import Path

import cv2

from sonar.streaming.chat import (
    ChatDetection,
    ChatTab,
    MajesticChatController,
    MajesticChatDetector,
    chat_command_hint,
    message_uses_explicit_chat_command,
)
from sonar.vision.geometry import Rect


FIXTURES = Path(__file__).parent / "fixtures" / "chat"


def load_frame(name: str):
    frame = cv2.imread(str(FIXTURES / name))
    assert frame is not None
    return frame


def test_chat_detector_finds_active_input_and_tabs_on_day_screenshot():
    detection = MajesticChatDetector().detect(load_frame("chat_all_day.jpg"))

    assert detection.active is True
    assert detection.input_rect is not None
    assert detection.input_rect.width >= 450
    assert len(detection.tabs) >= 2
    assert detection.selected_tab_id == "0"


def test_chat_detector_finds_family_tab_selection_on_night_screenshot():
    detection = MajesticChatDetector().detect(load_frame("chat_family_night_prefix.jpg"))

    assert detection.active is True
    assert len(detection.tabs) >= 2
    assert detection.selected_tab_id == "1"


def test_chat_detector_uses_input_bar_when_message_backgrounds_are_enabled():
    detector = MajesticChatDetector()

    for name in (
        "chat_input_message_backgrounds_200258.jpg",
        "chat_input_message_backgrounds_212128.jpg",
        "chat_input_message_backgrounds_212134.jpg",
        "chat_input_message_backgrounds_212140.jpg",
        "chat_input_message_backgrounds_212144.jpg",
        "chat_input_message_backgrounds_212151.jpg",
    ):
        detection = detector.detect(load_frame(name))
        assert detection.active is True, name
        assert detection.input_rect is not None, name
        assert 450 <= detection.input_rect.y <= 500, name
        assert detection.input_rect.width >= 420, name


def test_chat_detector_rejects_tabs_without_active_input():
    frame = load_frame("chat_all_day.jpg")
    frame[430:560, 0:560] = frame[580:710, 0:560]

    detection = MajesticChatDetector().detect(frame)

    assert detection.active is False
    assert len(detection.tabs) >= 2


def test_chat_detector_rejects_visible_tabs_when_input_is_closed():
    detector = MajesticChatDetector()

    for name in ("chat_inactive_home_1.jpg", "chat_inactive_home_2.jpg", "chat_inactive_home_3.jpg"):
        detection = detector.detect(load_frame(name))
        assert detection.active is False, name
        assert detection.input_rect is None, name


def test_chat_command_hint_uses_known_majestic_slash_codes():
    assert chat_command_hint("/b бегаю по полю") == "OOC"
    assert chat_command_hint("/cb текст") == "семейный OOC"
    assert chat_command_hint("обычный текст") == "обычный локальный IC"
    assert chat_command_hint("/me машет рукой") == "RP-действие"
    assert chat_command_hint("/report нужна помощь") == "обращение администрации"
    assert message_uses_explicit_chat_command("/gb привет") is True
    assert message_uses_explicit_chat_command("без слеша") is False


class DummyInput:
    def __init__(self) -> None:
        self.actions: list[tuple[str, tuple[str, ...]]] = []

    def release_all_keys(self) -> None:
        self.actions.append(("release", ()))

    def press_key(self, key: str) -> bool:
        self.actions.append(("press", (key,)))
        return True

    def hotkey(self, *keys: str) -> bool:
        self.actions.append(("hotkey", tuple(keys)))
        return True

    def click(self, x: int, y: int) -> bool:
        self.actions.append(("click", (str(x), str(y))))
        return True


class DummyCapture:
    def __init__(self, detections: list[ChatDetection]) -> None:
        self.detections = detections

    def capture(self):
        return object()

    def client_to_screen(self, x: int, y: int) -> tuple[int, int]:
        return x, y


class DummyActivator:
    def activate_window(self) -> bool:
        return True


class SequenceDetector:
    def __init__(self, detections: list[ChatDetection]) -> None:
        self.detections = detections
        self.index = 0

    def detect(self, frame) -> ChatDetection:
        detection = self.detections[min(self.index, len(self.detections) - 1)]
        self.index += 1
        return detection


def make_detection(selected: str = "0") -> ChatDetection:
    tabs = (
        ChatTab("0", "Все", selected == "0", Rect(25, 20, 48, 30)),
        ChatTab("1", "Семья", selected == "1", Rect(75, 20, 64, 30)),
    )
    return ChatDetection(active=True, tabs=tabs, selected_tab_id=selected, input_rect=Rect(24, 460, 470, 47))


def make_inactive_detection() -> ChatDetection:
    detection = make_detection("0")
    return ChatDetection(active=False, tabs=detection.tabs, selected_tab_id=detection.selected_tab_id)


def make_controller(detections: list[ChatDetection], input_controller: DummyInput, clipboard: list[str]) -> MajesticChatController:
    return MajesticChatController(
        capture=DummyCapture(detections),
        window_activator=DummyActivator(),
        input_controller=input_controller,  # type: ignore[arg-type]
        detector=SequenceDetector(detections),  # type: ignore[arg-type]
        clipboard_setter=clipboard.append,
        sleep=lambda seconds: None,
    )


def test_open_chat_focuses_game_and_presses_configured_hotkey_without_escape():
    input_controller = DummyInput()
    controller = make_controller([make_inactive_detection(), make_detection("0")], input_controller, [])

    result = controller.open_chat("t")

    assert result.ok is True
    assert ("press", ("t",)) in input_controller.actions
    assert ("press", ("esc",)) not in input_controller.actions


def test_open_chat_does_not_press_hotkey_when_chat_is_already_active():
    input_controller = DummyInput()
    controller = make_controller([make_detection("0")], input_controller, [])

    result = controller.open_chat("t")

    assert result.ok is True
    assert ("release", ()) in input_controller.actions
    assert [action for action in input_controller.actions if action[0] == "press"] == []


def test_close_chat_presses_escape_until_chat_becomes_inactive():
    input_controller = DummyInput()
    controller = make_controller([make_detection("0"), make_inactive_detection()], input_controller, [])

    result = controller.close_chat()

    assert result.ok is True
    assert ("press", ("esc",)) in input_controller.actions


def test_select_tab_clicks_requested_tab_in_game():
    input_controller = DummyInput()
    controller = make_controller([make_detection("0"), make_detection("1")], input_controller, [])

    result = controller.select_tab("1", chat_hotkey="t")

    assert result.ok is True
    clicks = [action for action in input_controller.actions if action[0] == "click"]
    assert len(clicks) == 2


def test_send_message_restores_tab_prefix_for_plain_text():
    input_controller = DummyInput()
    clipboard: list[str] = []
    controller = make_controller([make_detection("0")] * 6, input_controller, clipboard)

    result = controller.send_message("0", "привет", chat_hotkey="t")

    assert result.ok is True
    assert clipboard == ["привет"]
    assert input_controller.actions.count(("hotkey", ("ctrl", "a"))) == 1
    assert ("hotkey", ("ctrl", "v")) in input_controller.actions
    clicks = [action for action in input_controller.actions if action[0] == "click"]
    assert len(clicks) == 3


def test_send_message_restores_non_all_tab_prefix_through_all_tab():
    input_controller = DummyInput()
    clipboard: list[str] = []
    controller = make_controller([make_detection("1")] * 6, input_controller, clipboard)

    result = controller.send_message("1", "привет", chat_hotkey="t")

    assert result.ok is True
    assert clipboard == ["привет"]
    clicks = [action for action in input_controller.actions if action[0] == "click"]
    assert len(clicks) == 5
    assert ("click", ("49", "35")) in clicks
    assert ("click", ("107", "35")) in clicks


def test_send_message_skips_tab_restore_for_explicit_slash_command():
    input_controller = DummyInput()
    clipboard: list[str] = []
    controller = make_controller([make_detection("0")] * 4, input_controller, clipboard)

    result = controller.send_message("0", "/cb привет", chat_hotkey="t")

    assert result.ok is True
    assert clipboard == ["/cb привет"]
    clicks = [action for action in input_controller.actions if action[0] == "click"]
    assert len(clicks) == 3
