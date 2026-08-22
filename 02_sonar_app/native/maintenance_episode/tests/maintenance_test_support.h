#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <stop_token>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "maintenance_fixture.h"

namespace sonar::fishing::maintenance_episode::tests {

class sequence_observer final : public maintenance_observer {
 public:
  explicit sequence_observer(std::vector<maintenance_observation> source)
      : source_(std::move(source)) {}

  [[nodiscard]] inventory::inventory_observation observe(
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested()) {
      return {
          .sequence = latest_sequence_ + 1,
          .surface = inventory::inventory_surface::gameplay,
          .error = "fixture_cancelled",
      };
    }
    if (cursor_ >= source_.size()) {
      return {
          .sequence = latest_sequence_ + 1,
          .surface = inventory::inventory_surface::gameplay,
          .error = "fixture_exhausted",
      };
    }
    current_ = source_[cursor_++];
    latest_sequence_ = current_.inventory.sequence;
    if (corrupt_current_after_observe) {
      current_.inventory.surface = inventory::inventory_surface::game_menu;
    }
    return source_[cursor_ - 1].inventory;
  }

  [[nodiscard]] const maintenance_observation& current_maintenance()
      const noexcept override {
    return current_;
  }

  [[nodiscard]] std::uint64_t latest_sequence() const noexcept {
    return latest_sequence_;
  }

  [[nodiscard]] std::size_t consumed() const noexcept { return cursor_; }

  bool corrupt_current_after_observe{};

 private:
  std::vector<maintenance_observation> source_;
  std::size_t cursor_{};
  std::uint64_t latest_sequence_{};
  maintenance_observation current_;
};

[[nodiscard]] inline bool valid_target(
    const stage::normalized_rect& bounds) noexcept {
  return bounds.width > 0.0 && bounds.height > 0.0 && bounds.x >= 0.0 &&
      bounds.y >= 0.0 && bounds.x + bounds.width <= 1.0 &&
      bounds.y + bounds.height <= 1.0;
}

[[nodiscard]] inline bool item_intent(
    const inventory::inventory_intent_kind kind) noexcept {
  return kind == inventory::inventory_intent_kind::use_inventory_item ||
      kind == inventory::inventory_intent_kind::move_backpack_item ||
      kind == inventory::inventory_intent_kind::discard_inventory_item;
}

[[nodiscard]] inline bool terminal_intent(
    const inventory::inventory_intent_kind kind) noexcept {
  return kind == inventory::inventory_intent_kind::stop_automation ||
      kind == inventory::inventory_intent_kind::exit_game ||
      kind == inventory::inventory_intent_kind::shutdown_pc;
}

class recording_mutation_port final : public inventory::inventory_mutation_port {
 public:
  explicit recording_mutation_port(sequence_observer& observer) noexcept
      : observer_(observer) {}

  [[nodiscard]] inventory::inventory_mutation_result apply(
      const inventory::inventory_mutation_intent& intent,
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested()) {
      return inventory::inventory_mutation_result::rejected(
          "fixture_cancelled");
    }
    if (intent.expected_observation_sequence != observer_.latest_sequence()) {
      return inventory::inventory_mutation_result::rejected(
          "fixture_final_sequence_gate_failed");
    }
    if (intent.kind == inventory::inventory_intent_kind::pause) {
      if (intent.delay_milliseconds == 0 || intent.packet_count != 0) {
        return inventory::inventory_mutation_result::rejected(
            "fixture_pause_invalid");
      }
    } else if (terminal_intent(intent.kind)) {
      if (intent.packet_count != 0 || intent.delay_milliseconds != 0 ||
          !intent.key.empty() || !intent.item_instance_id.empty()) {
        return inventory::inventory_mutation_result::rejected(
            "fixture_terminal_invalid");
      }
    } else if (intent.packet_count == 0 || intent.delay_milliseconds != 0) {
      return inventory::inventory_mutation_result::rejected(
          "fixture_mutation_invalid");
    }
    if (item_intent(intent.kind) &&
        (intent.item_instance_id.empty() || intent.key.empty() ||
         !valid_target(intent.target_bounds))) {
      return inventory::inventory_mutation_result::rejected(
          "fixture_item_target_invalid");
    }

    intents.push_back(intent);
    if (reject_at.has_value() && intents.size() - 1 == *reject_at) {
      return inventory::inventory_mutation_result::rejected(rejection_reason);
    }
    return inventory::inventory_mutation_result::accepted();
  }

  std::vector<inventory::inventory_mutation_intent> intents;
  std::optional<std::size_t> reject_at;
  std::string rejection_reason{"fixture_final_gate_rejected"};

 private:
  sequence_observer& observer_;
};

[[nodiscard]] inline std::string intent_token(
    const inventory::inventory_mutation_intent& intent) {
  std::string token = inventory::inventory_intent_key(intent.kind);
  if (intent.kind == inventory::inventory_intent_kind::press_key) {
    token += ':' + intent.key;
  } else if (item_intent(intent.kind)) {
    token += ':' + intent.item_instance_id + ':' + intent.key;
  } else if (intent.kind == inventory::inventory_intent_kind::pause) {
    token += ':' + std::to_string(intent.delay_milliseconds);
  }
  return token;
}

[[nodiscard]] inline std::vector<std::string> intent_tokens(
    const std::vector<inventory::inventory_mutation_intent>& intents) {
  std::vector<std::string> result;
  result.reserve(intents.size());
  std::transform(
      intents.begin(),
      intents.end(),
      std::back_inserter(result),
      intent_token);
  return result;
}

[[nodiscard]] inline maintenance_observation observation(
    const std::uint64_t sequence,
    const inventory::inventory_surface surface,
    const stage::observed_fishing_stage fishing_stage =
        stage::observed_fishing_stage::none) {
  return {
      .inventory = {
          .sequence = sequence,
          .surface = surface,
          .fishing_stage = fishing_stage,
      },
  };
}

[[nodiscard]] inline inventory::inventory_item_observation observed_item(
    std::string instance_id,
    std::string item_id,
    const inventory::inventory_compartment compartment =
        inventory::inventory_compartment::player_inventory,
    const double confidence = 0.99) {
  return {
      .instance_id = std::move(instance_id),
      .item_id = std::move(item_id),
      .title = "fixture item",
      .compartment = compartment,
      .confidence = confidence,
      .bounds = {.x = 0.15, .y = 0.20, .width = 0.08, .height = 0.08},
  };
}

[[nodiscard]] inline runtime_settings::RuntimeSettingsSnapshot
valid_settings() {
  runtime_settings::RuntimeSettingsSnapshot result;
  result.revision = 1;
  return result;
}

}  // namespace sonar::fishing::maintenance_episode::tests
