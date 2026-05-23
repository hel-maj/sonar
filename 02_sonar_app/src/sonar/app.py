from __future__ import annotations

import sys
import faulthandler
import logging
import os

from sonar.chat_wip_gate import apply_chat_wip_gate, is_chat_wip_enabled
from sonar.core.logging import configure_logging
from sonar.paths import LOG_DIR, LOGS_ENABLED


def main(argv: list[str] | None = None) -> int:
    configure_logging()
    argv = argv if argv is not None else sys.argv
    if "--debug" in argv:
        os.environ["SONAR_DEBUG_CAPTURE"] = "1"
        os.environ["SONAR_DEBUG_MODE"] = "1"
    ui_argv = [arg for arg in argv if arg != "--debug"]
    chat_wip_enabled = is_chat_wip_enabled(argv)
    fault_log = None
    if LOGS_ENABLED:
        LOG_DIR.mkdir(parents=True, exist_ok=True)
        fault_log = (LOG_DIR / "faulthandler.log").open("a", encoding="utf-8")
        faulthandler.enable(file=fault_log, all_threads=True)
    try:
        try:
            import sonar.streaming.service as streaming_service_module
            import sonar.telegram.notifier as notification_module
            from sonar.ui import main_window as main_window_module
            from sonar.ui.overview_redesign import apply as apply_overview_redesign
        except ImportError as exc:
            logging.getLogger("sonar").exception("Unable to import desktop UI")
            print("PySide6 is required for the desktop UI. Install dependencies with: python -m pip install -e .")
            print(f"Import error: {exc}")
            return 2
        apply_overview_redesign(main_window_module)
        apply_chat_wip_gate(
            main_window_module=main_window_module,
            streaming_service_module=streaming_service_module,
            notification_module=notification_module,
            enabled=chat_wip_enabled,
        )
        return main_window_module.run_ui(ui_argv)
    finally:
        if "--smoke-test" in argv:
            try:
                from sonar.automation.window import WindowActivator

                WindowActivator().force_activate_gta5()
            except Exception:
                pass
        if fault_log is not None:
            fault_log.close()
