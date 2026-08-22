#pragma once

#include <cstddef>
#include <optional>
#include <stop_token>
#include <string>
#include <string_view>
#include <vector>

#include "sonar/fishing/maintenance_episode/maintenance_episode.h"

namespace sonar::fishing::maintenance_episode::detail {

class operation final : public inventory_store::inventory_episode_operation {
 public:
  operation(
      const maintenance_request& request,
      maintenance_observer& observer) noexcept;

  [[nodiscard]] inventory_store::inventory_operation_preflight_result preflight(
      const inventory_store::inventory_observation& observation,
      std::stop_token stop_token) override;
  [[nodiscard]] bool execute(
      inventory_store::inventory_episode_context& context,
      std::stop_token stop_token) override;

  [[nodiscard]] const std::string& completion_reason() const noexcept;
  [[nodiscard]] std::size_t affected_count() const noexcept;
  [[nodiscard]] std::size_t backpack_move_count() const noexcept;
  [[nodiscard]] bool meal_search_disabled() const noexcept;
  [[nodiscard]] double next_bait_change_at_seconds() const noexcept;
  [[nodiscard]] bool bait_cooldown_advanced() const noexcept;
  [[nodiscard]] terminal_outcome terminal() const noexcept;
  [[nodiscard]] const std::vector<equipment_recovery::TackleKind>& warnings()
      const noexcept;

 private:
  [[nodiscard]] const maintenance_observation* coherent(
      inventory_store::inventory_episode_context& context);
  [[nodiscard]] bool execute_meal(
      inventory_store::inventory_episode_context& context,
      std::stop_token stop_token);
  [[nodiscard]] bool execute_garbage(
      inventory_store::inventory_episode_context& context,
      std::stop_token stop_token);
  [[nodiscard]] bool execute_tackle(
      inventory_store::inventory_episode_context& context,
      std::stop_token stop_token);
  [[nodiscard]] bool execute_bait(
      inventory_store::inventory_episode_context& context,
      std::stop_token stop_token);
  [[nodiscard]] bool emit_terminal(
      inventory_store::inventory_episode_context& context,
      terminal_outcome outcome);

  const maintenance_request& request_;
  maintenance_observer& observer_;
  std::string completion_reason_{"maintenance_completed"};
  std::size_t affected_count_{};
  std::size_t backpack_move_count_{};
  bool meal_search_disabled_{};
  double next_bait_change_at_seconds_{};
  bool bait_cooldown_advanced_{};
  bool bait_recovery_admitted_{};
  terminal_outcome terminal_{terminal_outcome::none};
  std::vector<equipment_recovery::TackleKind> warnings_;
};

[[nodiscard]] inventory_store::inventory_mutation_intent item_intent(
    inventory_store::inventory_intent_kind kind,
    const inventory_store::inventory_item_observation& item,
    std::string key,
    std::size_t packet_count);

[[nodiscard]] bool stop_requested(
    inventory_store::inventory_episode_context& context,
    std::stop_token stop_token);

}  // namespace sonar::fishing::maintenance_episode::detail
