#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <stop_token>
#include <string>
#include <vector>

#include "sonar/fishing/equipment_recovery/equipment_recovery.h"
#include "sonar/fishing/inventory_store/inventory_store_episode.h"
#include "sonar/fishing/memory_observation/memory_observation.h"
#include "sonar/fishing/runtime_settings/runtime_settings.h"

namespace sonar::fishing::maintenance_episode {

enum class episode_kind : std::uint8_t {
  meal_recovery = 0,
  garbage_disposal = 1,
  tackle_check = 2,
  bait_recovery = 3,
};

enum class terminal_outcome : std::uint8_t {
  none = 0,
  stop = 1,
  exit_game = 2,
  shutdown_pc = 3,
};

struct tackle_scan_observation final {
  bool available{};
  bool readable{};
  bool obscured{};
  equipment_recovery::TackleCounts counts;
};

// One coherent aggregate is produced for each E15 inventory observation. The
// inventory sequence is the final-gate revision; E11 player-status evidence and
// product trigger/tackle projections are captured in the same aggregate.
struct maintenance_observation final {
  inventory_store::inventory_observation inventory;
  std::optional<memory_observation::reeling_evidence> reeling;
  std::optional<memory_observation::player_status_evidence> player_status;
  bool hunger_visible{};
  bool thirst_visible{};
  std::optional<tackle_scan_observation> tackle;
  bool changed_bait_visible{};
  bool gear_visible{};
};

class maintenance_observer : public inventory_store::inventory_observer {
 public:
  ~maintenance_observer() override = default;
  [[nodiscard]] virtual const maintenance_observation& current_maintenance()
      const noexcept = 0;
};

struct maintenance_request final {
  episode_kind kind{episode_kind::meal_recovery};
  runtime_settings::RuntimeSettingsSnapshot settings;
  std::optional<bool> session_started_with_net;
  double now_seconds{};
  double last_bait_change_at_seconds{};
  bool resume_fishing{true};
};

struct maintenance_result final {
  bool ok{};
  std::string reason;
  episode_kind kind{episode_kind::meal_recovery};
  std::size_t affected_count{};
  std::size_t backpack_move_count{};
  bool meal_search_disabled_until_restart{};
  double next_bait_change_at_seconds{};
  bool bait_cooldown_advanced{};
  terminal_outcome terminal{terminal_outcome::none};
  std::vector<equipment_recovery::TackleKind> warnings;
  bool recovery_attempted{};
  bool recovery_completed{};
  inventory_store::inventory_observation observation;
};

class maintenance_episode_runner final {
 public:
  [[nodiscard]] maintenance_result run(
      const maintenance_request& request,
      maintenance_observer& observer,
      inventory_store::inventory_mutation_port& mutation,
      std::stop_token stop_token = {}) const;
};

[[nodiscard]] const char* key(episode_kind value) noexcept;
[[nodiscard]] const char* key(terminal_outcome value) noexcept;

}  // namespace sonar::fishing::maintenance_episode
