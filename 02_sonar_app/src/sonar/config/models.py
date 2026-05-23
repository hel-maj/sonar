from __future__ import annotations

from dataclasses import asdict, dataclass, field
from typing import Any

from sonar.config.defaults import DEFAULT_FISH_SETTINGS, DEFAULT_GARBAGE_SETTINGS


@dataclass(slots=True)
class FishingSettings:
    auto_meal: bool = True
    auto_change_bait: bool = True
    store_in_backpack: bool = False
    store_in_trunk: bool = True
    shutdown_on_overweight: bool = False
    overweight_action: str = "stop"
    fish_without_leader: bool = False
    leader_depleted_action: str = "stop"
    fish_without_net: bool = True
    net_depleted_action: str = "stop"
    equipment_depleted_action: str = "stop"
    fish_settings: dict[str, bool] = field(default_factory=lambda: dict(DEFAULT_FISH_SETTINGS))
    hotkey: str = "F9"
    inventory_hotkey: str = "i"
    use_item_hotkey: str = "e"
    discard_key: str = "q"
    chat_hotkey: str = "t"
    stream_snapshot_mode: bool = False
    start_stop_sound_enabled: bool = True
    garbage_settings: dict[str, bool] = field(default_factory=lambda: dict(DEFAULT_GARBAGE_SETTINGS))
    custom_fish_prices: dict[str, float] = field(default_factory=dict)

    @classmethod
    def from_dict(cls, data: dict[str, Any]) -> "FishingSettings":
        defaults = cls()
        fish_settings = dict(defaults.fish_settings)
        fish_settings.update(data.get("fish_settings") or {})
        garbage_settings = dict(defaults.garbage_settings)
        garbage_settings.update(data.get("garbage_settings") or {})
        custom_fish_prices: dict[str, float] = {}
        for fish_id, value in (data.get("custom_fish_prices") or {}).items():
            try:
                custom_fish_prices[str(fish_id)] = float(value)
            except (TypeError, ValueError):
                continue
        overweight_action = str(data.get("overweight_action", defaults.overweight_action))
        if data.get("shutdown_on_overweight") and "overweight_action" not in data:
            overweight_action = "stop"
        if overweight_action not in {"release", "stop", "exit_game"}:
            overweight_action = defaults.overweight_action
        leader_depleted_action = str(data.get("leader_depleted_action", defaults.leader_depleted_action))
        if leader_depleted_action not in {"stop", "exit_game"}:
            leader_depleted_action = defaults.leader_depleted_action
        net_depleted_action = str(data.get("net_depleted_action", defaults.net_depleted_action))
        if net_depleted_action not in {"stop", "exit_game"}:
            net_depleted_action = defaults.net_depleted_action
        equipment_depleted_action = str(data.get("equipment_depleted_action", defaults.equipment_depleted_action))
        if equipment_depleted_action not in {"stop", "exit_game", "shutdown_pc"}:
            equipment_depleted_action = defaults.equipment_depleted_action
        return cls(
            auto_meal=bool(data.get("auto_meal", defaults.auto_meal)),
            auto_change_bait=bool(data.get("auto_change_bait", defaults.auto_change_bait)),
            store_in_backpack=False,
            store_in_trunk=bool(data.get("store_in_trunk", defaults.store_in_trunk)),
            shutdown_on_overweight=bool(data.get("shutdown_on_overweight", overweight_action == "stop")),
            overweight_action=overweight_action,
            fish_without_leader=bool(data.get("fish_without_leader", defaults.fish_without_leader)),
            leader_depleted_action=leader_depleted_action,
            fish_without_net=bool(data.get("fish_without_net", defaults.fish_without_net)),
            net_depleted_action=net_depleted_action,
            equipment_depleted_action=equipment_depleted_action,
            fish_settings=fish_settings,
            hotkey=str(data.get("hotkey", defaults.hotkey)),
            inventory_hotkey=str(data.get("inventory_hotkey", defaults.inventory_hotkey)),
            use_item_hotkey=str(data.get("use_item_hotkey", defaults.use_item_hotkey)),
            discard_key=str(data.get("discard_key", defaults.discard_key)),
            chat_hotkey=str(data.get("chat_hotkey", defaults.chat_hotkey)),
            stream_snapshot_mode=bool(data.get("stream_snapshot_mode", defaults.stream_snapshot_mode)),
            start_stop_sound_enabled=bool(data.get("start_stop_sound_enabled", defaults.start_stop_sound_enabled)),
            garbage_settings=garbage_settings,
            custom_fish_prices=custom_fish_prices,
        )

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass(slots=True)
class TelegramSettings:
    enabled: bool = False
    bot_token: str = ""
    admin_ids: list[int] = field(default_factory=list)
    notify_catch: bool = True
    notify_start_stop: bool = True
    notify_meal: bool = True
    notify_inventory_full: bool = True
    notify_focus_lost: bool = False

    @classmethod
    def from_dict(cls, data: dict[str, Any]) -> "TelegramSettings":
        raw_ids = data.get("admin_ids") or []
        if isinstance(raw_ids, str):
            raw_ids = [item.strip() for item in raw_ids.split(",") if item.strip()]
        admin_ids = []
        for item in raw_ids:
            try:
                admin_ids.append(int(item))
            except (TypeError, ValueError):
                continue
        return cls(
            enabled=bool(data.get("enabled", False)),
            bot_token=str(data.get("bot_token", "")),
            admin_ids=admin_ids,
            notify_catch=bool(data.get("notify_catch", True)),
            notify_start_stop=bool(data.get("notify_start_stop", True)),
            notify_meal=bool(data.get("notify_meal", True)),
            notify_inventory_full=bool(data.get("notify_inventory_full", True)),
            notify_focus_lost=bool(data.get("notify_focus_lost", False)),
        )

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass(slots=True)
class LicenseSettings:
    license_key: str = ""
    license_id: str = ""
    last_validated_at: str = ""
    expires_at: str = ""
    role: str = "user"

    @classmethod
    def from_dict(cls, data: dict[str, Any]) -> "LicenseSettings":
        defaults = cls()
        return cls(
            license_key=str(data.get("license_key", defaults.license_key)).strip(),
            license_id=str(data.get("license_id", defaults.license_id)).strip(),
            last_validated_at=str(data.get("last_validated_at", defaults.last_validated_at)).strip(),
            expires_at=str(data.get("expires_at", defaults.expires_at)).strip(),
            role=str(data.get("role", defaults.role)).strip() or defaults.role,
        )

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass(slots=True)
class SonarSettings:
    fishing: FishingSettings = field(default_factory=FishingSettings)
    telegram: TelegramSettings = field(default_factory=TelegramSettings)
    license: LicenseSettings = field(default_factory=LicenseSettings)

    def to_dict(self) -> dict[str, Any]:
        return {
            "fishing": self.fishing.to_dict(),
            "telegram": self.telegram.to_dict(),
            "license": self.license.to_dict(),
        }
