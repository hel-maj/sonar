from __future__ import annotations

import os
import sys
from typing import Any


CHAT_WIP_DEBUG_ARG = "--debug"
CHAT_WIP_ENV = "SONAR_DEBUG_MODE"
CHAT_WIP_UNAVAILABLE_MESSAGE = "Режим чата (WIP) доступен только при запуске python с --debug"
TELEGRAM_CHAT_MODE_HINT = "Режим чата доступен на странице стрима"


_CHAT_HIDE_SCRIPT = """
  <script id=\"sonar-chat-wip-runtime-gate\">
    (() => {
      const removeChatWipNodes = () => {
        document.querySelectorAll('button, .metric').forEach((node) => {
          const text = (node.textContent || '').toLowerCase();
          if (text.includes('режим чата')) {
            node.remove();
          }
        });
      };
      const start = () => {
        const root = document.getElementById('root') || document.body;
        removeChatWipNodes();
        new MutationObserver(removeChatWipNodes).observe(root, {
          childList: true,
          subtree: true,
          characterData: true,
        });
      };
      if (document.readyState === 'loading') {
        document.addEventListener('DOMContentLoaded', start, { once: true });
      } else {
        start();
      }
    })();
  </script>
"""


def is_chat_wip_enabled(argv: list[str]) -> bool:
    return not getattr(sys, "frozen", False) and (
        CHAT_WIP_DEBUG_ARG in argv or os.environ.get(CHAT_WIP_ENV) == "1"
    )


def apply_chat_wip_gate(
    *,
    main_window_module: Any,
    streaming_service_module: Any,
    notification_module: Any,
    enabled: bool,
) -> None:
    _patch_stream_page_html(streaming_service_module, enabled)
    _patch_main_window(main_window_module, enabled)
    _patch_notification_text(notification_module)
    if not enabled:
        _disable_streaming_chat_methods(streaming_service_module)


def _patch_stream_page_html(streaming_service_module: Any, enabled: bool) -> None:
    html = str(getattr(streaming_service_module, "STREAM_PAGE_HTML", ""))
    if not html:
        return
    if enabled:
        streaming_service_module.STREAM_PAGE_HTML = _mark_chat_mode_wip(html)
        return
    if "sonar-chat-wip-runtime-gate" in html:
        return
    streaming_service_module.STREAM_PAGE_HTML = html.replace("</body>", f"{_CHAT_HIDE_SCRIPT}\n</body>")


def _patch_main_window(main_window_module: Any, enabled: bool) -> None:
    main_window_class = main_window_module.MainWindow
    if getattr(main_window_class, "_sonar_chat_wip_gate_patched", False):
        return
    original_build_stream_tab = main_window_class._build_stream_tab
    original_refresh_stream_tab = main_window_class._refresh_stream_tab
    original_enable_chat_mode = main_window_class.enable_chat_mode

    def build_stream_tab(self: Any) -> Any:
        widget = original_build_stream_tab(self)
        _apply_stream_tab_gate(main_window_module, self, enabled)
        return widget

    def refresh_stream_tab(self: Any) -> None:
        original_refresh_stream_tab(self)
        _apply_stream_tab_gate(main_window_module, self, enabled)

    def enable_chat_mode(self: Any) -> None:
        if not enabled:
            if hasattr(self, "log_bridge"):
                self.log_bridge.message.emit(CHAT_WIP_UNAVAILABLE_MESSAGE)
            return
        original_enable_chat_mode(self)

    main_window_class._build_stream_tab = build_stream_tab
    main_window_class._refresh_stream_tab = refresh_stream_tab
    main_window_class.enable_chat_mode = enable_chat_mode
    main_window_class._sonar_chat_wip_gate_patched = True


def _apply_stream_tab_gate(main_window_module: Any, window: Any, enabled: bool) -> None:
    button = getattr(window, "stream_chat_mode_button", None)
    if button is not None:
        if enabled:
            button.show()
            button.setText(_mark_chat_mode_wip(button.text()))
            button.setToolTip("WIP: доступно только при прямом запуске python с --debug")
        else:
            button.setEnabled(False)
            button.hide()

    stream_tab = getattr(window, "stream_tab", None)
    if stream_tab is None:
        return
    try:
        labels = stream_tab.findChildren(main_window_module.QLabel)
    except Exception:
        return
    for label in labels:
        text = label.text()
        if "Режим чата" not in text:
            continue
        label.setText(_mark_chat_mode_wip(text) if enabled else "Стрим можно запускать здесь или из Telegram.")


def _disable_streaming_chat_methods(streaming_service_module: Any) -> None:
    service_class = streaming_service_module.StreamingService
    if getattr(service_class, "_sonar_chat_wip_disabled", False):
        return

    def unavailable_snapshot(self: Any, *args: Any, **kwargs: Any) -> Any:
        del args, kwargs
        with self._lock:
            self._chat_mode_enabled = False
            self._chat_memory_enabled = False
            self._chat_memory_restore_enabled = False
            self._chat_memory_loading = False
            self._chat_memory = {}
            self._chat_last_action = CHAT_WIP_UNAVAILABLE_MESSAGE
        return self.snapshot()

    def chat_snapshot(self: Any) -> dict[str, object]:
        return {
            "chat_memory_enabled": False,
            "chat_mode_enabled": False,
            "chat_active": False,
            "chat_tabs": (),
            "chat_selected_tab_id": None,
            "chat_status_error": "",
            "chat_last_action": CHAT_WIP_UNAVAILABLE_MESSAGE,
            "chat_memory_loading": False,
            "chat_history": None,
            "chat_confirmed_outbox": [],
            "license_role": self._license_role_locked(),
            "chat_commands": (),
        }

    for method_name in (
        "enable_chat_mode",
        "disable_chat_mode",
        "set_chat_mode_enabled",
        "set_chat_memory_enabled",
        "send_chat_message",
        "select_chat_tab",
        "clear_chat_input",
    ):
        setattr(service_class, method_name, unavailable_snapshot)
    service_class.chat_snapshot = chat_snapshot
    service_class._sonar_chat_wip_disabled = True


def _patch_notification_text(notification_module: Any) -> None:
    manager_class = notification_module.NotificationManager
    if getattr(manager_class, "_sonar_chat_wip_text_patched", False):
        return
    original_send_message = manager_class.send_message
    original_send_or_edit_message = manager_class._send_or_edit_message

    def send_message(self: Any, text: str, *args: Any, **kwargs: Any) -> Any:
        return original_send_message(self, _strip_telegram_chat_hint(text), *args, **kwargs)

    def send_or_edit_message(self: Any, text: str, *args: Any, **kwargs: Any) -> Any:
        return original_send_or_edit_message(self, _strip_telegram_chat_hint(text), *args, **kwargs)

    manager_class.send_message = send_message
    manager_class._send_or_edit_message = send_or_edit_message
    manager_class._sonar_chat_wip_text_patched = True


def _mark_chat_mode_wip(text: str) -> str:
    if "(WIP)" in text:
        return text
    return text.replace("режима чата", "режима чата (WIP)").replace("Режим чата", "Режим чата (WIP)")


def _strip_telegram_chat_hint(text: str) -> str:
    lines = [line for line in str(text).splitlines() if TELEGRAM_CHAT_MODE_HINT not in line]
    return "\n".join(lines).rstrip()
