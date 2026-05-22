from __future__ import annotations

import re
import shutil
import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable

import cv2
import numpy as np
from PIL import Image

from sonar.automation.input_controller import InputController
from sonar.automation.window import WindowActivator
from sonar.paths import RESOURCE_DIR
from sonar.vision.capture import WindowCapture
from sonar.vision.geometry import Rect
from sonar.vision.matching import ensure_bgr


CHAT_OPEN_TIMEOUT_SECONDS = 4.0
CHAT_CLOSE_TIMEOUT_SECONDS = 2.0
CHAT_POLL_SECONDS = 0.15
CHAT_TAB_SWITCH_DELAY_SECONDS = 0.18
CHAT_CLEAR_DELAY_SECONDS = 0.08


@dataclass(frozen=True, slots=True)
class ChatCommand:
    key: str
    title: str
    code: str
    description: str


CHAT_COMMANDS: tuple[ChatCommand, ...] = (
    ChatCommand("local_ic", "обычный локальный IC", "", "сообщение в чат"),
    ChatCommand("whisper", "IC, шёпот", "/w", "видит только конкретный игрок"),
    ChatCommand("shout", "IC, крик", "/s", "видят игроки в увеличенном радиусе"),
    ChatCommand("local_ooc", "OOC", "/b", "неролевое сообщение рядом"),
    ChatCommand("me", "RP-действие", "/me", "описание действия персонажа"),
    ChatCommand("do", "RP-ситуация", "/do", "описание ситуации или факта"),
    ChatCommand("family_ic", "семейный IC", "/c", "ролевой чат семьи"),
    ChatCommand("family_ooc", "семейный OOC", "/cb", "неролевой чат семьи"),
    ChatCommand("group_ic", "групповой IC", "/g", "ролевой чат временной группы"),
    ChatCommand("group_ooc", "групповой OOC", "/gb", "неролевой чат временной группы"),
    ChatCommand("report", "обращение администрации", "/report", "сообщение администрации"),
)
CHAT_COMMAND_BY_CODE = {command.code: command for command in CHAT_COMMANDS if command.code}
EXPLICIT_CHAT_COMMAND_RE = re.compile(r"^/[^\s/]+(?:\s|$)", re.IGNORECASE)


@dataclass(frozen=True, slots=True)
class ChatTab:
    id: str
    name: str
    selected: bool
    rect: Rect


@dataclass(frozen=True, slots=True)
class ChatDetection:
    active: bool = False
    tabs: tuple[ChatTab, ...] = ()
    selected_tab_id: str | None = None
    input_rect: Rect | None = None
    error: str = ""


@dataclass(frozen=True, slots=True)
class ChatActionResult:
    ok: bool
    message: str = ""
    detection: ChatDetection = field(default_factory=ChatDetection)


def message_uses_explicit_chat_command(message: str) -> bool:
    return EXPLICIT_CHAT_COMMAND_RE.match(message.lstrip()) is not None


def chat_command_hint(message: str) -> str:
    text = message.lstrip()
    match = EXPLICIT_CHAT_COMMAND_RE.match(text)
    if not match:
        return CHAT_COMMANDS[0].title
    code = match.group(0).strip().lower()
    command = CHAT_COMMAND_BY_CODE.get(code)
    return command.title if command is not None else "Команда чата"


class MajesticChatDetector:
    def detect(self, frame: np.ndarray) -> ChatDetection:
        if frame is None or frame.size == 0:
            return ChatDetection(error="empty frame")
        image = ensure_bgr(frame)
        input_rect = self._detect_input_rect(image)
        active_tab_rect = self._detect_active_tab_rect(image)
        tabs = self._detect_tabs(image, active_tab_rect)
        selected_tab_id = next((tab.id for tab in tabs if tab.selected), None)
        return ChatDetection(
            active=input_rect is not None,
            tabs=tabs,
            selected_tab_id=selected_tab_id,
            input_rect=input_rect,
        )

    def _detect_active_tab_rect(self, frame: np.ndarray) -> Rect | None:
        height, width = frame.shape[:2]
        roi = frame[: max(1, int(height * 0.09)), : max(1, int(width * 0.35))]
        hsv = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
        red_mask = (
            (((hsv[:, :, 0] >= 155) | (hsv[:, :, 0] <= 5)) & (hsv[:, :, 1] >= 60) & (hsv[:, :, 2] >= 55))
        ).astype("uint8")
        components = cv2.connectedComponentsWithStats(red_mask, 8)[2]
        candidates: list[Rect] = []
        for x, y, component_width, component_height, area in components[1:]:
            if (
                y < height * 0.06
                and 20 <= component_width <= max(200, int(width * 0.16))
                and 18 <= component_height <= max(50, int(height * 0.06))
                and area > max(350, int(width * height * 0.00012))
            ):
                candidates.append(Rect(int(x), int(y), int(component_width), int(component_height)))
        if not candidates:
            return None
        return max(candidates, key=lambda item: item.width * item.height)

    def _detect_tabs(self, frame: np.ndarray, active_rect: Rect | None) -> tuple[ChatTab, ...]:
        if active_rect is None:
            return ()
        height, width = frame.shape[:2]
        scale = max(0.5, min(width / 1920.0, height / 1080.0))
        pad_y = max(2, int(round(3 * scale)))
        row = Rect(
            0,
            max(0, active_rect.y - pad_y),
            int(width * 0.35),
            active_rect.height + pad_y * 2,
        ).clamp(width, height)
        crop = frame[row.slice()]
        if crop.size == 0:
            return (self._fallback_active_tab(frame, active_rect, 0),)

        hsv = cv2.cvtColor(crop, cv2.COLOR_BGR2HSV)
        text_mask = ((hsv[:, :, 2] > 115) & (hsv[:, :, 1] < 110)).astype("uint8") * 255
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (max(3, int(round(4 * scale))), max(1, int(round(2 * scale)))))
        text_mask = cv2.morphologyEx(text_mask, cv2.MORPH_CLOSE, kernel)
        components = cv2.connectedComponentsWithStats(text_mask, 8)[2]
        text_rects: list[Rect] = []
        for x, y, component_width, component_height, area in components[1:]:
            if (
                8 * scale <= component_width <= 140 * scale
                and 7 * scale <= component_height <= 28 * scale
                and area >= 18 * scale
                and x < width * 0.25
            ):
                text_rects.append(Rect(int(row.x + x), int(row.y + y), int(component_width), int(component_height)))
        text_rects = self._merge_close_text_rects(text_rects, max_gap=max(5, int(round(8 * scale))))
        tabs: list[ChatTab] = []
        for text_rect in sorted(text_rects, key=lambda item: item.x):
            tab_rect = Rect(
                int(text_rect.x - 12 * scale),
                int(text_rect.y - 8 * scale),
                int(text_rect.width + 24 * scale),
                int(text_rect.height + 17 * scale),
            ).clamp(width, height)
            if tab_rect.width <= 0 or tab_rect.height <= 0:
                continue
            selected = self._rect_center_inside(tab_rect, active_rect)
            name = self._read_tab_text(frame, tab_rect) or f"Вкладка {len(tabs) + 1}"
            tabs.append(ChatTab(id="", name=name, selected=selected, rect=tab_rect))

        if not tabs:
            tabs.append(self._fallback_active_tab(frame, active_rect, 0))
        elif not any(tab.selected for tab in tabs):
            fallback = self._fallback_active_tab(frame, active_rect, len(tabs))
            tabs.append(fallback)

        normalized: list[ChatTab] = []
        for index, tab in enumerate(sorted(tabs, key=lambda item: item.rect.x)):
            normalized.append(ChatTab(id=str(index), name=tab.name, selected=tab.selected, rect=tab.rect))
        return tuple(normalized)

    def _detect_input_rect(self, frame: np.ndarray) -> Rect | None:
        height, width = frame.shape[:2]
        y_offset = int(height * 0.20)
        roi = frame[y_offset : int(height * 0.65), : int(width * 0.40)]
        if roi.size == 0:
            return None
        scale = max(0.5, min(width / 1920.0, height / 1080.0))
        gray = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 20, 70)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (max(5, int(round(7 * scale))), max(3, int(round(3 * scale)))))
        closed = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, kernel)
        contours, _ = cv2.findContours(closed, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        candidates: list[tuple[Rect, float]] = []
        for contour in contours:
            x, y, component_width, component_height = cv2.boundingRect(contour)
            rect = Rect(int(x), int(y + y_offset), int(component_width), int(component_height))
            if not (
                rect.x < width * 0.06
                and width * 0.18 <= rect.width <= width * 0.35
                and height * 0.025 <= rect.height <= height * 0.08
            ):
                continue
            inner = gray[y + 3 : max(y + 4, y + component_height - 3), x + 3 : max(x + 4, x + component_width - 3)]
            if inner.size == 0:
                continue
            inner_mean = float(inner.mean())
            if inner_mean > 95:
                continue
            candidates.append((rect, inner_mean))
        edge_rect = self._detect_input_rect_from_edges(frame)
        if edge_rect is not None:
            candidates.append((edge_rect, 0.0))
        valid_candidates = [item for item in candidates if self._looks_like_input_body(frame, item[0]) and self._has_command_buttons_below(frame, item[0])]
        if valid_candidates:
            return max(valid_candidates, key=lambda item: (item[0].y, item[0].width * item[0].height))[0]
        if not candidates:
            return None
        return max(candidates, key=lambda item: (item[0].y, item[0].width * item[0].height))[0]

    def _detect_input_rect_from_edges(self, frame: np.ndarray) -> Rect | None:
        height, width = frame.shape[:2]
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 20, 70)
        x_limit = max(1, int(width * 0.30))
        row_scores = edges[:, :x_limit].sum(axis=1) / 255
        min_score = max(90, int(width * 0.045))
        groups: list[tuple[int, int]] = []
        start: int | None = None
        last = 0
        for y in range(int(height * 0.20), int(height * 0.62)):
            if row_scores[y] >= min_score:
                if start is None:
                    start = y
                last = y
            elif start is not None:
                groups.append((start, last))
                start = None
        if start is not None:
            groups.append((start, last))

        candidates: list[Rect] = []
        min_input_height = int(height * 0.028)
        max_input_height = int(height * 0.078)
        for index, (top_start, top_end) in enumerate(groups):
            top = (top_start + top_end) // 2
            top_span = self._largest_horizontal_edge_span(edges, top, x_limit)
            if top_span is None:
                continue
            for bottom_start, bottom_end in groups[index + 1 :]:
                bottom = (bottom_start + bottom_end) // 2
                rect_height = bottom - top + 1
                if rect_height < min_input_height:
                    continue
                if rect_height > max_input_height:
                    break
                bottom_span = self._largest_horizontal_edge_span(edges, bottom, x_limit)
                if bottom_span is None:
                    continue
                left = min(top_span[0], bottom_span[0])
                right = max(top_span[1], bottom_span[1])
                rect_width = right - left + 1
                if not (
                    left < width * 0.07
                    and width * 0.18 <= rect_width <= width * 0.36
                    and height * 0.025 <= rect_height <= height * 0.08
                ):
                    continue
                rect = Rect(int(left), int(top), int(rect_width), int(rect_height))
                if self._looks_like_input_body(frame, rect) and self._has_command_buttons_below(frame, rect):
                    candidates.append(rect)
        if not candidates:
            return None
        return max(candidates, key=lambda item: (item.y, item.width * item.height))

    @staticmethod
    def _largest_horizontal_edge_span(edges: np.ndarray, y: int, x_limit: int) -> tuple[int, int] | None:
        band = edges[max(0, y - 2) : min(edges.shape[0], y + 3), :x_limit]
        columns = np.where(band.max(axis=0) > 0)[0]
        if columns.size == 0:
            return None
        segments: list[tuple[int, int]] = []
        start = int(columns[0])
        last = start
        for column in columns[1:]:
            current = int(column)
            if current - last <= 18:
                last = current
                continue
            segments.append((start, last))
            start = current
            last = current
        segments.append((start, last))
        return max(segments, key=lambda item: item[1] - item[0])

    @staticmethod
    def _looks_like_input_body(frame: np.ndarray, rect: Rect) -> bool:
        height, width = frame.shape[:2]
        clamped = rect.clamp(width, height)
        if clamped.width <= 0 or clamped.height <= 0:
            return False
        crop = frame[clamped.slice()]
        gray = cv2.cvtColor(crop, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 20, 70)
        inner = gray[4 : max(5, gray.shape[0] - 4), 4 : max(5, gray.shape[1] - 4)]
        if inner.size == 0:
            return False
        bright_ratio = float((inner > 130).mean())
        edge_density = float((edges > 0).mean())
        return bright_ratio <= 0.04 and edge_density <= 0.11

    @staticmethod
    def _has_command_buttons_below(frame: np.ndarray, rect: Rect) -> bool:
        height, width = frame.shape[:2]
        y1 = min(height, rect.bottom + 3)
        y2 = min(height, rect.bottom + max(52, int(height * 0.07)))
        x2 = min(width, rect.x + rect.width + max(20, int(width * 0.04)))
        if y2 <= y1 or x2 <= 0:
            return False
        crop = frame[y1:y2, :x2]
        scale = max(0.5, min(width / 1920.0, height / 1080.0))
        hsv = cv2.cvtColor(crop, cv2.COLOR_BGR2HSV)
        text_mask = ((hsv[:, :, 2] > 110) & (hsv[:, :, 1] < 120)).astype("uint8") * 255
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (max(5, int(round(9 * scale))), max(2, int(round(3 * scale)))))
        text_mask = cv2.morphologyEx(text_mask, cv2.MORPH_CLOSE, kernel)
        components = cv2.connectedComponentsWithStats(text_mask, 8)[2]
        command_text_tops: list[int] = []
        for x, y, component_width, component_height, area in components[1:]:
            if (
                x < width * 0.22
                and 8 * scale <= component_width <= 85 * scale
                and 7 * scale <= component_height <= 28 * scale
                and area >= 15 * scale
            ):
                command_text_tops.append(y1 + int(y))
        if len(command_text_tops) < 3:
            return False
        return min(command_text_tops) - rect.bottom <= max(30, int(height * 0.035))

    def _read_tab_text(self, frame: np.ndarray, rect: Rect) -> str | None:
        try:
            import pytesseract
        except Exception:
            return None
        self._configure_tesseract(pytesseract)
        height, width = frame.shape[:2]
        crop = frame[rect.clamp(width, height).slice()]
        if crop.size == 0:
            return None
        scaled = cv2.resize(crop, None, fx=4.0, fy=4.0, interpolation=cv2.INTER_CUBIC)
        gray = cv2.cvtColor(scaled, cv2.COLOR_BGR2GRAY)
        _, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
        tessdata_dir = RESOURCE_DIR / "tessdata"
        config = "--psm 7"
        lang = "rus"
        if (tessdata_dir / "rus.traineddata").exists():
            config += f" --tessdata-dir {tessdata_dir.as_posix()}"
        for candidate in (Image.fromarray(gray), Image.fromarray(thresh)):
            try:
                text = pytesseract.image_to_string(candidate, lang=lang, config=config)
            except Exception:
                continue
            normalized = self._normalize_tab_text(text)
            if normalized:
                return normalized
        return None

    @staticmethod
    def _normalize_tab_text(text: str) -> str:
        text = " ".join(text.replace("\n", " ").split())
        text = re.sub(r"[^0-9A-Za-zА-Яа-яЁё _-]+", "", text)
        return " ".join(text.split())

    @staticmethod
    def _merge_close_text_rects(rects: list[Rect], *, max_gap: int) -> list[Rect]:
        if not rects:
            return []
        merged: list[Rect] = []
        for rect in sorted(rects, key=lambda item: item.x):
            if not merged:
                merged.append(rect)
                continue
            last = merged[-1]
            same_row = abs((last.y + last.height // 2) - (rect.y + rect.height // 2)) <= max(last.height, rect.height)
            if same_row and rect.x - last.right <= max_gap:
                right = max(last.right, rect.right)
                bottom = max(last.bottom, rect.bottom)
                merged[-1] = Rect(last.x, min(last.y, rect.y), right - last.x, bottom - min(last.y, rect.y))
            else:
                merged.append(rect)
        return merged

    @staticmethod
    def _fallback_active_tab(frame: np.ndarray, active_rect: Rect, index: int) -> ChatTab:
        height, width = frame.shape[:2]
        rect = Rect(active_rect.x, active_rect.y, active_rect.width, active_rect.height).clamp(width, height)
        return ChatTab(id=str(index), name=f"Вкладка {index + 1}", selected=True, rect=rect)

    @staticmethod
    def _rects_overlap(first: Rect, second: Rect) -> bool:
        left = max(first.x, second.x)
        top = max(first.y, second.y)
        right = min(first.right, second.right)
        bottom = min(first.bottom, second.bottom)
        return right > left and bottom > top

    @staticmethod
    def _rect_center_inside(inner: Rect, outer: Rect) -> bool:
        center_x = inner.x + inner.width // 2
        center_y = inner.y + inner.height // 2
        return outer.x <= center_x <= outer.right and outer.y <= center_y <= outer.bottom

    @staticmethod
    def _configure_tesseract(pytesseract_module) -> None:
        if shutil.which("tesseract"):
            return
        for path in (
            Path(r"C:\Program Files\Tesseract-OCR\tesseract.exe"),
            Path(r"C:\Program Files (x86)\Tesseract-OCR\tesseract.exe"),
        ):
            if path.exists():
                pytesseract_module.pytesseract.tesseract_cmd = str(path)
                return


class MajesticChatController:
    def __init__(
        self,
        *,
        capture: WindowCapture | None = None,
        window_activator: WindowActivator | None = None,
        input_controller: InputController | None = None,
        detector: MajesticChatDetector | None = None,
        clipboard_setter: Callable[[str], None] | None = None,
        sleep: Callable[[float], None] = time.sleep,
        log_callback: Callable[[str], None] | None = None,
    ) -> None:
        self.capture = capture or WindowCapture()
        self.window_activator = window_activator or WindowActivator()
        self.input_controller = input_controller or InputController()
        self.detector = detector or MajesticChatDetector()
        self.clipboard_setter = clipboard_setter or set_clipboard_text
        self.sleep = sleep
        self.log_callback = log_callback

    def detect(self) -> ChatDetection:
        try:
            frame = self.capture.capture()
            return self.detector.detect(frame)
        except Exception as exc:
            return ChatDetection(error=str(exc))

    def open_chat(self, chat_hotkey: str = "t", *, timeout: float = CHAT_OPEN_TIMEOUT_SECONDS) -> ChatActionResult:
        if not self.window_activator.activate_window():
            return ChatActionResult(False, "Не удалось сфокусировать игру", self.detect())
        self.input_controller.release_all_keys()
        detection = self.detect()
        if detection.active:
            self._focus_input(detection)
            return ChatActionResult(True, "Чат уже активен", detection)
        if not self.input_controller.press_key(chat_hotkey):
            return ChatActionResult(False, "Не удалось нажать клавишу чата", self.detect())
        deadline = time.monotonic() + timeout
        while time.monotonic() < deadline:
            detection = self.detect()
            if detection.active:
                self._focus_input(detection)
                return ChatActionResult(True, "Чат открыт", detection)
            self.sleep(CHAT_POLL_SECONDS)
        return ChatActionResult(False, "Поле ввода чата не подтвердилось", detection)

    def close_chat(self, *, timeout: float = CHAT_CLOSE_TIMEOUT_SECONDS, force: bool = False) -> ChatActionResult:
        if not self.window_activator.activate_window():
            return ChatActionResult(False, "Не удалось сфокусировать игру", self.detect())
        detection = self.detect()
        if not detection.active and not force:
            return ChatActionResult(True, "Чат уже закрыт", detection)
        if not self.input_controller.press_key("esc"):
            return ChatActionResult(False, "Не удалось нажать Esc", detection)
        deadline = time.monotonic() + timeout
        while time.monotonic() < deadline:
            detection = self.detect()
            if not detection.active:
                return ChatActionResult(True, "Режим чата выключен", detection)
            self.sleep(CHAT_POLL_SECONDS)
        return ChatActionResult(False, "Чат остался активным", detection)

    def clear_chat_input(self, chat_hotkey: str = "t") -> ChatActionResult:
        opened = self.open_chat(chat_hotkey)
        if not opened.ok:
            return opened
        self._focus_input(opened.detection)
        self._clear_input()
        return ChatActionResult(True, "Поле ввода очищено", self.detect())

    def select_tab(self, tab_id: str | None, chat_hotkey: str = "t") -> ChatActionResult:
        opened = self.open_chat(chat_hotkey)
        if not opened.ok:
            return opened
        detection = self._select_tab(tab_id, opened.detection)
        return ChatActionResult(True, "Вкладка чата выбрана", detection)

    def send_message(self, tab_id: str | None, message: str, chat_hotkey: str = "t") -> ChatActionResult:
        text = message.strip()
        if not text:
            return ChatActionResult(False, "Сообщение пустое", self.detect())
        opened = self.open_chat(chat_hotkey)
        if not opened.ok:
            return opened
        detection = self._select_tab(tab_id, opened.detection)
        selected_tab_id = tab_id or detection.selected_tab_id
        self._focus_input(detection)
        self._clear_input()
        detection = self.detect()
        if selected_tab_id and not message_uses_explicit_chat_command(text):
            detection = self._restore_tab_prefix(selected_tab_id, detection)
        self._focus_input(detection)
        self.clipboard_setter(text)
        self.input_controller.hotkey("ctrl", "v")
        self.sleep(0.05)
        self.input_controller.press_key("enter")
        detection = self.detect()
        return ChatActionResult(True, "Сообщение отправлено", detection)

    def _select_tab(self, tab_id: str | None, detection: ChatDetection) -> ChatDetection:
        if not tab_id:
            return detection
        tab = self._find_tab(detection, tab_id)
        if tab is None or tab.selected:
            return detection
        self._click_tab(tab)
        self.sleep(CHAT_TAB_SWITCH_DELAY_SECONDS)
        return self.detect()

    def _restore_tab_prefix(self, selected_tab_id: str, detection: ChatDetection) -> ChatDetection:
        if len(detection.tabs) <= 1:
            return detection
        selected_tab = self._find_tab(detection, selected_tab_id) or next((tab for tab in detection.tabs if tab.selected), None)
        if selected_tab is None:
            return detection
        if self._is_all_tab(selected_tab):
            return detection
        all_tab = self._find_tab(detection, "all")
        if all_tab is None or all_tab.id == selected_tab.id:
            return detection
        self._click_tab(all_tab)
        self.sleep(CHAT_TAB_SWITCH_DELAY_SECONDS)
        refreshed = self.detect()
        selected_tab = self._find_tab(refreshed, selected_tab_id) or selected_tab
        self._click_tab(selected_tab)
        self.sleep(CHAT_TAB_SWITCH_DELAY_SECONDS)
        return self.detect()

    def _clear_input(self) -> None:
        self.input_controller.hotkey("ctrl", "a")
        self.sleep(CHAT_CLEAR_DELAY_SECONDS)
        for _ in range(3):
            self.input_controller.press_key("backspace")
            self.sleep(CHAT_CLEAR_DELAY_SECONDS)

    def _focus_input(self, detection: ChatDetection) -> None:
        if not self.window_activator.activate_window():
            return
        rect = detection.input_rect
        if rect is None:
            try:
                frame = self.capture.capture()
                height, width = frame.shape[:2]
                rect = Rect(int(width * 0.015), int(height * 0.425), int(width * 0.25), max(32, int(height * 0.045)))
            except Exception:
                return
        screen_x, screen_y = self.capture.client_to_screen(
            rect.x + min(max(20, rect.width // 5), max(20, rect.width - 20)),
            rect.y + rect.height // 2,
        )
        self.input_controller.click(screen_x, screen_y)
        self.sleep(0.05)

    def _click_tab(self, tab: ChatTab) -> None:
        screen_x, screen_y = self.capture.client_to_screen(tab.rect.x + tab.rect.width // 2, tab.rect.y + tab.rect.height // 2)
        self.input_controller.click(screen_x, screen_y)

    @staticmethod
    def _find_tab(detection: ChatDetection, tab_id: str) -> ChatTab | None:
        tab_id = str(tab_id)
        for tab in detection.tabs:
            if tab.id == tab_id or tab.name == tab_id or MajesticChatController._tab_alias_matches(tab, tab_id):
                return tab
        return None

    @staticmethod
    def _is_all_tab(tab: ChatTab) -> bool:
        return tab.id == "0" or MajesticChatController._tab_alias_matches(tab, "all")

    @staticmethod
    def _tab_alias_matches(tab: ChatTab, tab_id: str) -> bool:
        normalized_id = tab_id.strip().lower()
        normalized_name = tab.name.strip().lower()
        aliases = {
            "all": {"0", "все", "вкладка 1"},
            "fam": {"1", "семья", "family", "вкладка 2"},
            "frac": {"2", "фракция", "fraction", "вкладка 3"},
            "gov": {"3", "департамент", "department", "вкладка 4"},
            "report": {"4", "репорт", "report", "вкладка 5"},
        }
        expected = aliases.get(normalized_id, {normalized_id})
        return tab.id in expected or normalized_name in expected


def set_clipboard_text(text: str) -> None:
    import win32clipboard
    import win32con

    win32clipboard.OpenClipboard()
    try:
        win32clipboard.EmptyClipboard()
        win32clipboard.SetClipboardText(text, win32con.CF_UNICODETEXT)
    finally:
        win32clipboard.CloseClipboard()
