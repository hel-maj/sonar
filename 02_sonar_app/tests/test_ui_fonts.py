from __future__ import annotations

import hashlib
from pathlib import Path

import pytest

from sonar.ui import main_window
from sonar.ui.widgets import SONAR_QSS


EXPECTED_BUNDLE_FILES = (
    "Inter-Regular.ttf",
    "Inter-Italic.ttf",
    "Inter-Medium.ttf",
    "Inter-MediumItalic.ttf",
    "Inter-SemiBold.ttf",
    "Inter-SemiBoldItalic.ttf",
    "Inter-Bold.ttf",
    "Inter-BoldItalic.ttf",
    "Inter-ExtraBold.ttf",
    "Inter-ExtraBoldItalic.ttf",
    "LICENSE.txt",
)


class FakeFont:
    class StyleStrategy:
        PreferAntialias = object()

    class HintingPreference:
        PreferNoHinting = object()

    def __init__(self, family: str, point_size: int) -> None:
        self.family = family
        self.point_size = point_size
        self.style_strategy = None
        self.hinting_preference = None

    def setStyleStrategy(self, strategy: object) -> None:
        self.style_strategy = strategy

    def setHintingPreference(self, preference: object) -> None:
        self.hinting_preference = preference


class FakeApplication:
    def __init__(self) -> None:
        self.font = None

    def setFont(self, font: FakeFont) -> None:
        self.font = font


def test_bundled_inter_files_match_manifest() -> None:
    font_dir = main_window.FONT_DIR
    assert font_dir == main_window.RESOURCE_DIR / "fonts"

    manifest_lines = (font_dir / "SHA256SUMS").read_text(encoding="utf-8").splitlines()
    manifest = []
    for line in manifest_lines:
        digest, filename = line.split("  ", maxsplit=1)
        manifest.append((digest, filename))

    assert tuple(filename for _, filename in manifest) == EXPECTED_BUNDLE_FILES
    for expected_digest, filename in manifest:
        actual_digest = hashlib.sha256((font_dir / filename).read_bytes()).hexdigest()
        assert actual_digest == expected_digest


def test_load_app_fonts_registers_local_fonts_before_system_fallback(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    bundled_dir = tmp_path / "bundled"
    bundled_dir.mkdir()
    bundled_regular = bundled_dir / "Inter-Regular.ttf"
    bundled_bold = bundled_dir / "Inter-Bold.ttf"
    bundled_regular.write_bytes(b"regular")
    bundled_bold.write_bytes(b"bold")
    (bundled_dir / "README.md").write_text("ignored", encoding="utf-8")

    windows_dir = tmp_path / "Windows"
    windows_fonts = windows_dir / "Fonts"
    windows_fonts.mkdir(parents=True)
    system_fallback = windows_fonts / "segoeui.ttf"
    system_fallback.write_bytes(b"fallback")

    registered: list[Path] = []

    class FakeFontDatabase:
        @staticmethod
        def addApplicationFont(path: str) -> int:
            registered.append(Path(path))
            return len(registered) - 1

    monkeypatch.setattr(main_window, "FONT_DIR", bundled_dir)
    monkeypatch.setattr(main_window, "QFontDatabase", FakeFontDatabase)
    monkeypatch.setenv("WINDIR", str(windows_dir))

    main_window.load_app_fonts()

    assert registered == [bundled_bold.resolve(), bundled_regular.resolve(), system_fallback.resolve()]


@pytest.mark.parametrize(
    ("available_families", "expected_family"),
    [
        (("Arial", "Segoe UI", "Inter"), "Inter"),
        (("Arial", "Segoe UI"), "Segoe UI"),
        (("Arial",), "Arial"),
    ],
)
def test_apply_app_font_prefers_inter_and_preserves_fallbacks(
    available_families: tuple[str, ...],
    expected_family: str,
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    class FakeFontDatabase:
        @staticmethod
        def families() -> list[str]:
            return list(available_families)

    app = FakeApplication()
    monkeypatch.setattr(main_window, "QFontDatabase", FakeFontDatabase)
    monkeypatch.setattr(main_window, "QFont", FakeFont)

    main_window.apply_app_font(app)

    assert app.font is not None
    assert app.font.family == expected_family
    assert app.font.point_size == 8
    assert app.font.style_strategy is FakeFont.StyleStrategy.PreferAntialias
    assert app.font.hinting_preference is FakeFont.HintingPreference.PreferNoHinting


def test_global_stylesheet_prefers_inter_with_system_fallbacks() -> None:
    assert 'font-family: "Inter", "Segoe UI Variable", "Segoe UI", Arial, sans-serif;' in SONAR_QSS
