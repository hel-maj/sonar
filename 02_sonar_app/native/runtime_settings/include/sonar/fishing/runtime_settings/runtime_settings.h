#pragma once

#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace sonar::fishing::runtime_settings {

enum class OverweightAction {
  release,
  stop,
  exit_game,
};

enum class DepletedAction {
  stop,
  exit_game,
};

enum class EquipmentDepletedAction {
  stop,
  exit_game,
  shutdown_pc,
};

enum class FoodDepletedAction {
  continue_fishing,
  stop,
  exit_game,
  shutdown_pc,
};

struct RuntimeSettingsSnapshot {
  std::uint64_t revision = 0;
  bool auto_meal = true;
  std::uint32_t restore_food_from = 90;
  std::uint32_t restore_water_from = 90;
  std::uint32_t restore_health_from = 1;
  bool auto_change_bait = true;
  bool store_in_trunk = true;
  bool start_stop_sound_enabled = true;
  OverweightAction overweight_action = OverweightAction::stop;
  bool fish_without_leader = false;
  DepletedAction leader_depleted_action = DepletedAction::stop;
  bool fish_without_net = true;
  DepletedAction net_depleted_action = DepletedAction::stop;
  EquipmentDepletedAction equipment_depleted_action =
      EquipmentDepletedAction::stop;
  FoodDepletedAction food_depleted_action =
      FoodDepletedAction::continue_fishing;
  std::string start_stop_hotkey = "F9";
  std::string inventory_hotkey = "tab";
  std::string use_item_hotkey = "e";
  std::string backpack_move_hotkey = "r";
  std::string discard_hotkey = "q";
  std::string chat_hotkey = "t";
  bool stream_snapshot_mode = false;
  std::map<std::string, bool, std::less<>> fish_keep_policy;
  std::map<std::string, bool, std::less<>> garbage_disposal_policy;
  std::map<std::string, double, std::less<>> custom_fish_prices;
};

enum class ApplyStatus {
  accepted,
  stale_revision,
  invalid_snapshot,
};

struct ApplyResult {
  ApplyStatus status;
  std::uint64_t accepted_revision;
  std::string reason;

  [[nodiscard]] bool accepted() const noexcept {
    return status == ApplyStatus::accepted;
  }
};

// Engine-owned atomic settings holder. Callers build and validate a complete
// immutable snapshot before any state-machine operation observes it.
class RuntimeSettingsOwner final {
 public:
  [[nodiscard]] ApplyResult Apply(RuntimeSettingsSnapshot candidate);
  [[nodiscard]] std::optional<RuntimeSettingsSnapshot> Current() const;
  [[nodiscard]] std::uint64_t AcceptedRevision() const noexcept;

 private:
  std::optional<RuntimeSettingsSnapshot> current_;
};

[[nodiscard]] bool IsValidHotkey(std::string_view value) noexcept;
[[nodiscard]] std::string_view Validate(
    const RuntimeSettingsSnapshot& candidate) noexcept;

}  // namespace sonar::fishing::runtime_settings
