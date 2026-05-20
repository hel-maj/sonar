from __future__ import annotations

import json
from pathlib import Path
from typing import Any

from sonar.config.models import FishingSettings, LicenseSettings, SonarSettings, TelegramSettings
from sonar.paths import CONFIG_DIR, ensure_runtime_dirs


class ConfigManager:
    def __init__(self, config_dir: Path = CONFIG_DIR) -> None:
        self.config_dir = config_dir
        self.fishing_path = config_dir / "fishing_settings.json"
        self.telegram_path = config_dir / "telegram_settings.json"
        self.license_path = config_dir / "license_settings.json"

    def load(self) -> SonarSettings:
        ensure_runtime_dirs()
        fishing = FishingSettings.from_dict(self._read_json(self.fishing_path))
        telegram = TelegramSettings.from_dict(self._read_json(self.telegram_path))
        license_settings = LicenseSettings.from_dict(self._read_json(self.license_path))
        settings = SonarSettings(fishing=fishing, telegram=telegram, license=license_settings)
        self.save(settings)
        return settings

    def save(self, settings: SonarSettings) -> None:
        ensure_runtime_dirs()
        self._write_json(self.fishing_path, settings.fishing.to_dict())
        self._write_json(self.telegram_path, settings.telegram.to_dict())
        self._write_json(self.license_path, settings.license.to_dict())

    def get_fish_to_keep(self) -> set[str]:
        settings = self.load().fishing
        return {name for name, keep in settings.fish_settings.items() if keep}

    def get_fish_to_release(self) -> set[str]:
        settings = self.load().fishing
        return {name for name, keep in settings.fish_settings.items() if not keep}

    def get_garbage_to_eject(self) -> set[str]:
        settings = self.load().fishing
        return {name for name, enabled in settings.garbage_settings.items() if enabled}

    @staticmethod
    def _read_json(path: Path) -> dict[str, Any]:
        if not path.exists():
            return {}
        try:
            with path.open("r", encoding="utf-8") as file:
                data = json.load(file)
            return data if isinstance(data, dict) else {}
        except (OSError, json.JSONDecodeError):
            return {}

    @staticmethod
    def _write_json(path: Path, data: dict[str, Any]) -> None:
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.open("w", encoding="utf-8") as file:
            json.dump(data, file, ensure_ascii=False, indent=4)
