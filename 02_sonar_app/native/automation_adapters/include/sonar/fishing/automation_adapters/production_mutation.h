#pragma once

#include <cstdint>
#include <memory>
#include <stop_token>
#include <string>

#include "sonar/fishing/automation_adapters/production_observation.h"
#include "sonar/fishing/automation_adapters/system_terminal_action.h"
#include "sonar/fishing/inventory_store/inventory_store_episode.h"

namespace sonar::fishing::automation_adapters {

enum class requested_terminal_action : std::uint8_t {
  none,
  stop,
  exit_game,
  shutdown_pc,
};

// A single exclusive lease spans the whole production session. Fishing and
// inventory/maintenance receive short borrowed views; every physical mutation
// is immediately revalidated and consists only of complete down/up batches.
class guarded_production_mutation_port final
    : public fishing_episode::fishing_mutation_port,
      public inventory_store::inventory_mutation_port {
 public:
  [[nodiscard]] static std::unique_ptr<guarded_production_mutation_port>
  acquire(
      runtime_platform::automation_lease_coordinator& leases,
      immediate_action_gate& final_gate,
      runtime_platform::platform_mutation_sink& sink,
      system_terminal_action_sink& terminal_sink,
      production_frame_observer& observer,
      std::uint64_t settings_revision,
      std::uint64_t entitlement_revision,
      std::uint64_t lifecycle_revision,
      std::string& reason) noexcept;

  ~guarded_production_mutation_port() override;

  [[nodiscard]] std::unique_ptr<fishing_episode::fishing_mutation_session>
  acquire(
      const fishing_episode::fishing_episode_request& request,
      std::stop_token stop_token,
      std::string& reason) override;

  [[nodiscard]] inventory_store::inventory_mutation_result apply(
      const inventory_store::inventory_mutation_intent& intent,
      std::stop_token stop_token) override;

  [[nodiscard]] inventory_store::inventory_mutation_result apply_catch_button(
      std::uint64_t expected_observation_sequence,
      const stage_detection::normalized_rect& bounds,
      std::stop_token stop_token);

  [[nodiscard]] requested_terminal_action terminal_action() const noexcept;
  [[nodiscard]] bool cleanup() noexcept;

 private:
  class fishing_view;

  guarded_production_mutation_port(
      runtime_platform::automation_lease lease,
      runtime_platform::automation_lease_coordinator& leases,
      immediate_action_gate& final_gate,
      runtime_platform::platform_mutation_sink& sink,
      system_terminal_action_sink& terminal_sink,
      production_frame_observer& observer,
      std::uint64_t settings_revision,
      std::uint64_t entitlement_revision,
      std::uint64_t lifecycle_revision) noexcept;

  [[nodiscard]] fishing_episode::fishing_mutation_result apply_fishing(
      const fishing_episode::fishing_mutation_intent& intent,
      std::stop_token stop_token);
  [[nodiscard]] fishing_episode::fishing_mutation_result cleanup_fishing(
      std::uint64_t expected_observation_sequence) noexcept;

  runtime_platform::automation_lease lease_;
  runtime_platform::automation_lease_coordinator& leases_;
  immediate_action_gate& final_gate_;
  runtime_platform::platform_mutation_sink& sink_;
  system_terminal_action_sink& terminal_sink_;
  production_frame_observer& observer_;
  std::uint64_t settings_revision_{};
  std::uint64_t entitlement_revision_{};
  std::uint64_t lifecycle_revision_{};
  std::uint64_t last_observation_sequence_{};
  requested_terminal_action terminal_action_{requested_terminal_action::none};
  bool fishing_view_active_{};
  bool cleaned_{};
};

}  // namespace sonar::fishing::automation_adapters
