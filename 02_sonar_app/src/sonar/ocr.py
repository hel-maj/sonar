from __future__ import annotations

import os
import shutil
import sys
from pathlib import Path
from typing import Any

from sonar.paths import RESOURCE_DIR


def configure_tesseract(pytesseract_module: Any) -> None:
    _configure_tessdata_prefix()
    bundled = _bundled_tesseract()
    if bundled is not None:
        pytesseract_module.pytesseract.tesseract_cmd = str(bundled)
        return
    if shutil.which("tesseract"):
        return
    for path in (
        Path(r"C:\Program Files\Tesseract-OCR\tesseract.exe"),
        Path(r"C:\Program Files (x86)\Tesseract-OCR\tesseract.exe"),
    ):
        if path.exists():
            pytesseract_module.pytesseract.tesseract_cmd = str(path)
            return


def tessdata_config(config: str, lang: str) -> str:
    tessdata_dir = RESOURCE_DIR / "tessdata"
    language_files = [part.strip() for part in lang.split("+") if part.strip()]
    if language_files and all((tessdata_dir / f"{language}.traineddata").exists() for language in language_files):
        return f"{config} --tessdata-dir {tessdata_dir.as_posix()}"
    return config


def has_tessdata(language: str) -> bool:
    return (RESOURCE_DIR / "tessdata" / f"{language}.traineddata").exists()


def _bundled_tesseract() -> Path | None:
    if sys.platform.startswith("win"):
        path = RESOURCE_DIR / "tesseract" / "windows" / "tesseract.exe"
        return path if path.exists() else None
    return None


def _configure_tessdata_prefix() -> None:
    tessdata_dir = RESOURCE_DIR / "tessdata"
    if tessdata_dir.exists():
        os.environ["TESSDATA_PREFIX"] = str(tessdata_dir)
