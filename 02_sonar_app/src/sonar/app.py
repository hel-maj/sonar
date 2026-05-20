from __future__ import annotations

import sys
import faulthandler
import logging
import os

from sonar.core.logging import configure_logging
from sonar.paths import LOG_DIR, LOGS_ENABLED


def main(argv: list[str] | None = None) -> int:
    configure_logging()
    argv = argv if argv is not None else sys.argv
    if "--debug" in argv:
        os.environ["SONAR_DEBUG_CAPTURE"] = "1"
    ui_argv = [arg for arg in argv if arg != "--debug"]
    fault_log = None
    if LOGS_ENABLED:
        LOG_DIR.mkdir(parents=True, exist_ok=True)
        fault_log = (LOG_DIR / "faulthandler.log").open("a", encoding="utf-8")
        faulthandler.enable(file=fault_log, all_threads=True)
    try:
        try:
            from sonar.ui.main_window import run_ui
        except ImportError as exc:
            logging.getLogger("sonar").exception("Unable to import desktop UI")
            print("PyQt6 is required for the desktop UI. Install dependencies with: python -m pip install -e .")
            print(f"Import error: {exc}")
            return 2
        return run_ui(ui_argv)
    finally:
        if "--smoke-test" in argv:
            try:
                from sonar.automation.window import WindowActivator

                WindowActivator().force_activate_gta5()
            except Exception:
                pass
        if fault_log is not None:
            fault_log.close()
