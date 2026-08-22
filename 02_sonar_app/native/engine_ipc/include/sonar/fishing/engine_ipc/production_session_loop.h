#pragma once

#include <cstddef>
#include <cstdint>
#include <stop_token>
#include <string>

#include "sonar/fishing/fishing_episode/fishing_episode.h"
#include "sonar/fishing/runtime_settings/runtime_settings.h"

namespace sonar::fishing::engine_ipc {

inline constexpr std::size_t maximum_production_session_cycles = 100'000U;

struct production_session_request final {
  runtime_settings::RuntimeSettingsSnapshot settings;
  std::uint64_t entitlement_generation{};
  std::int64_t entitlement_expires_unix_seconds{};
  std::uint64_t lifecycle_revision{};
  std::size_t maximum_cycles{maximum_production_session_cycles};
};

struct production_step_result final {
  bool ok{};
  bool performed{};
  bool session_complete{};
  std::string reason;

  [[nodiscard]] static production_step_result completed(
      bool performed = true,
      bool session_complete = false);
  [[nodiscard]] static production_step_result rejected(std::string reason);
};

// Internal Engine seam only. It never crosses Host IPC: one worker owns the
// entire fishing -> catch -> inventory -> maintenance cycle and all final
// revalidation/mutation adapters underneath it.
class production_cycle_port {
 public:
  virtual ~production_cycle_port() = default;
  [[nodiscard]] virtual fishing_episode::fishing_episode_result run_fishing(
      const production_session_request& request,
      std::uint64_t cycle_identity,
      std::stop_token stop_token) = 0;
  [[nodiscard]] virtual production_step_result process_catch(
      const production_session_request& request,
      std::uint64_t cycle_identity,
      const fishing_episode::fishing_episode_result& fishing,
      std::stop_token stop_token) = 0;
  [[nodiscard]] virtual production_step_result run_inventory(
      const production_session_request& request,
      std::uint64_t cycle_identity,
      std::stop_token stop_token) = 0;
  [[nodiscard]] virtual production_step_result run_maintenance(
      const production_session_request& request,
      std::uint64_t cycle_identity,
      std::stop_token stop_token) = 0;
};

struct production_session_result final {
  bool ok{};
  bool stopped{};
  std::string reason;
  std::size_t cycles_completed{};
  std::size_t catches_processed{};
  std::size_t inventory_episodes_completed{};
  std::size_t maintenance_episodes_completed{};
};

class production_session_loop final {
 public:
  [[nodiscard]] production_session_result run(
      const production_session_request& request,
      production_cycle_port& port,
      std::stop_token stop_token = {}) const;
};

}  // namespace sonar::fishing::engine_ipc
