from sonar.config.models import FishingSettings, LicenseSettings, TelegramSettings


def test_fishing_settings_merges_defaults():
    settings = FishingSettings.from_dict({"fish_settings": {"albula": False}, "garbage_settings": {"bag": False}})

    assert settings.fish_settings["albula"] is False
    assert settings.fish_settings["marlin"] is True
    assert settings.garbage_settings["bag"] is False
    assert settings.garbage_settings["corn"] is True
    assert settings.start_stop_sound_enabled is True


def test_fishing_settings_accepts_start_stop_sound_toggle():
    settings = FishingSettings.from_dict({"start_stop_sound_enabled": False})

    assert settings.start_stop_sound_enabled is False


def test_fishing_settings_accepts_chat_hotkey():
    settings = FishingSettings.from_dict({"chat_hotkey": "Y"})

    assert settings.chat_hotkey == "Y"


def test_fishing_settings_accepts_tackle_depletion_options():
    settings = FishingSettings.from_dict(
        {
            "fish_without_leader": True,
            "leader_depleted_action": "exit_game",
            "fish_without_net": False,
            "net_depleted_action": "exit_game",
            "equipment_depleted_action": "shutdown_pc",
        }
    )

    assert settings.fish_without_leader is True
    assert settings.leader_depleted_action == "exit_game"
    assert settings.fish_without_net is False
    assert settings.net_depleted_action == "exit_game"
    assert settings.equipment_depleted_action == "shutdown_pc"




def test_fishing_settings_accepts_food_depleted_and_backpack_move_options():
    settings = FishingSettings.from_dict({"food_depleted_action": "shutdown_pc", "backpack_move_hotkey": "R"})

    assert settings.food_depleted_action == "shutdown_pc"
    assert settings.backpack_move_hotkey == "R"


def test_fishing_settings_accepts_restore_thresholds():
    settings = FishingSettings.from_dict({"restore_food_from": 12, "restore_water_from": "91", "restore_health_from": 0})

    assert settings.restore_food_from == 12
    assert settings.restore_water_from == 90
    assert settings.restore_health_from == 1


def test_fishing_settings_rejects_unknown_food_depleted_action():
    settings = FishingSettings.from_dict({"food_depleted_action": "loop_forever"})

    assert settings.food_depleted_action == "continue"

def test_telegram_settings_accepts_comma_separated_ids():
    settings = TelegramSettings.from_dict({"enabled": True, "admin_ids": "1, 2, bad"})

    assert settings.enabled is True
    assert settings.admin_ids == [1, 2]


def test_license_settings_serializes_only_runtime_license_state():
    settings = LicenseSettings.from_dict(
        {
            "server_url": "https://example.invalid",
            "account_id": "account",
            "license_key": "FA5B1-ABCDE-G2K34",
            "license_id": "license-id",
            "last_validated_at": "2026-05-19T10:00:00+00:00",
            "expires_at": "2026-06-19T10:00:00+00:00",
            "latest_version": "9.9.9",
            "update_message": "not persisted",
        }
    )

    assert settings.to_dict() == {
        "license_key": "FA5B1-ABCDE-G2K34",
        "license_id": "license-id",
        "last_validated_at": "2026-05-19T10:00:00+00:00",
        "expires_at": "2026-06-19T10:00:00+00:00",
        "role": "user",
    }


def test_telegram_settings_accepts_low_inventory_space_threshold():
    settings = TelegramSettings.from_dict(
        {"notify_inventory_space_low": True, "inventory_space_low_threshold_kg": "2,75"}
    )

    assert settings.notify_inventory_space_low is True
    assert settings.inventory_space_low_threshold_kg == 2.75


def test_telegram_settings_clamps_low_inventory_space_threshold():
    settings = TelegramSettings.from_dict({"inventory_space_low_threshold_kg": "0,5"})

    assert settings.inventory_space_low_threshold_kg == 1.0
