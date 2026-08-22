#include "sonar/fishing/automation_adapters/production_mutation.h"

#include <cmath>
#include <memory>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace sonar::fishing::automation_adapters {
namespace {

[[nodiscard]] runtime_platform::normalized_point center(
    const stage_detection::normalized_rect& bounds) noexcept {
  return {
      bounds.x + bounds.width / 2.0,
      bounds.y + bounds.height / 2.0,
  };
}

[[nodiscard]] bool valid_bounds(
    const stage_detection::normalized_rect& value) noexcept {
  return std::isfinite(value.x) && std::isfinite(value.y) &&
      std::isfinite(value.width) && std::isfinite(value.height) &&
      value.x >= 0.0 && value.y >= 0.0 && value.width > 0.0 &&
      value.height > 0.0 && value.x + value.width <= 1.0 &&
      value.y + value.height <= 1.0;
}

[[nodiscard]] std::string_view reeling_key(
    const reeling_control::HeldKey key) noexcept {
  switch (key) {
    case reeling_control::HeldKey::a: return "a";
    case reeling_control::HeldKey::d: return "d";
    case reeling_control::HeldKey::none: return {};
  }
  return {};
}

}  // namespace

class guarded_production_mutation_port::fishing_view final
    : public fishing_episode::fishing_mutation_session {
 public:
  explicit fishing_view(guarded_production_mutation_port& owner) noexcept
      : owner_(owner) {}
  ~fishing_view() override { owner_.fishing_view_active_ = false; }

  [[nodiscard]] fishing_episode::fishing_mutation_result apply(
      const fishing_episode::fishing_mutation_intent& intent,
      const std::stop_token stop_token) override {
    return owner_.apply_fishing(intent, stop_token);
  }

  [[nodiscard]] fishing_episode::fishing_mutation_result cleanup_reeling_keys(
      const std::uint64_t expected_observation_sequence) noexcept override {
    return owner_.cleanup_fishing(expected_observation_sequence);
  }

 private:
  guarded_production_mutation_port& owner_;
};

guarded_production_mutation_port::guarded_production_mutation_port(
    runtime_platform::automation_lease lease,
    runtime_platform::automation_lease_coordinator& leases,
    immediate_action_gate& final_gate,
    runtime_platform::platform_mutation_sink& sink,
    system_terminal_action_sink& terminal_sink,
    production_frame_observer& observer,
    const std::uint64_t settings_revision,
    const std::uint64_t entitlement_revision,
    const std::uint64_t lifecycle_revision) noexcept
    : lease_(std::move(lease)),
      leases_(leases),
      final_gate_(final_gate),
      sink_(sink),
      terminal_sink_(terminal_sink),
      observer_(observer),
      settings_revision_(settings_revision),
      entitlement_revision_(entitlement_revision),
      lifecycle_revision_(lifecycle_revision) {}

guarded_production_mutation_port::~guarded_production_mutation_port() {
  static_cast<void>(cleanup());
}

std::unique_ptr<guarded_production_mutation_port>
guarded_production_mutation_port::acquire(
    runtime_platform::automation_lease_coordinator& leases,
    immediate_action_gate& final_gate,
    runtime_platform::platform_mutation_sink& sink,
    system_terminal_action_sink& terminal_sink,
    production_frame_observer& observer,
    const std::uint64_t settings_revision,
    const std::uint64_t entitlement_revision,
    const std::uint64_t lifecycle_revision,
    std::string& reason) noexcept {
  if (settings_revision == 0U || entitlement_revision == 0U ||
      lifecycle_revision == 0U) {
    reason = "production_mutation_authority_invalid";
    return nullptr;
  }
  auto lease = leases.try_acquire();
  if (!lease.has_value()) {
    reason = "production_input_lease_busy";
    return nullptr;
  }
  reason.clear();
  return std::unique_ptr<guarded_production_mutation_port>(
      new guarded_production_mutation_port(
          std::move(*lease), leases, final_gate, sink, terminal_sink, observer,
          settings_revision, entitlement_revision, lifecycle_revision));
}

std::unique_ptr<fishing_episode::fishing_mutation_session>
guarded_production_mutation_port::acquire(
    const fishing_episode::fishing_episode_request& request,
    const std::stop_token stop_token,
    std::string& reason) {
  if (stop_token.stop_requested()) {
    reason = "fishing_episode_cancelled";
    return nullptr;
  }
  if (!leases_.owns(lease_) || fishing_view_active_) {
    reason = "production_input_lease_unavailable";
    return nullptr;
  }
  if (request.accepted_settings_revision != settings_revision_ ||
      request.expected_entitlement_revision != entitlement_revision_ ||
      request.expected_lifecycle_revision != lifecycle_revision_) {
    reason = "production_mutation_authority_stale";
    return nullptr;
  }
  fishing_view_active_ = true;
  reason.clear();
  return std::make_unique<fishing_view>(*this);
}

fishing_episode::fishing_mutation_result
guarded_production_mutation_port::apply_fishing(
    const fishing_episode::fishing_mutation_intent& intent,
    const std::stop_token stop_token) {
  if (stop_token.stop_requested()) {
    return fishing_episode::fishing_mutation_result::rejected(
        "fishing_mutation_cancelled");
  }
  if (!leases_.owns(lease_)) {
    return fishing_episode::fishing_mutation_result::rejected(
        "production_input_lease_lost");
  }
  runtime_platform::mutation_intent projected;
  switch (intent.kind) {
    case fishing_episode::fishing_mutation_kind::tap_cast_space:
    case fishing_episode::fishing_mutation_kind::tap_hook_space:
      projected = {
          .kind = runtime_platform::mutation_kind::press_key,
          .primary = "space",
          .packet_count = 2U,
      };
      break;
    case fishing_episode::fishing_mutation_kind::pulse_reeling_key: {
      const auto key = reeling_key(intent.desired_reeling_key);
      if (key.empty()) {
        return fishing_episode::fishing_mutation_result::rejected(
            "fishing_reeling_pulse_key_invalid");
      }
      projected = {
          .kind = runtime_platform::mutation_kind::press_key,
          .primary = std::string(key),
          .packet_count = 2U,
      };
      break;
    }
  }
  if (intent.packet_count != projected.packet_count ||
      intent.expected_settings_revision != settings_revision_ ||
      intent.expected_entitlement_revision != entitlement_revision_ ||
      intent.expected_lifecycle_revision != lifecycle_revision_) {
    return fishing_episode::fishing_mutation_result::rejected(
        "fishing_mutation_authority_or_shape_invalid");
  }
  last_observation_sequence_ = intent.expected_observation_sequence;
  const auto gate = final_gate_.revalidate({
      .expected_observation_sequence = intent.expected_observation_sequence,
      .expected_settings_revision = settings_revision_,
      .expected_entitlement_revision = entitlement_revision_,
      .expected_lifecycle_revision = lifecycle_revision_,
      .packet_count = projected.packet_count,
      .foreground_required = true,
  });
  if (!gate.accepted) {
    return fishing_episode::fishing_mutation_result::rejected(
        gate.reason.empty() ? "fishing_final_gate_rejected" : gate.reason);
  }
  const auto applied = sink_.apply(projected);
  return applied.applied
      ? fishing_episode::fishing_mutation_result::accepted()
      : fishing_episode::fishing_mutation_result::rejected(
            applied.reason.empty()
                ? "fishing_platform_mutation_failed"
                : applied.reason);
}

fishing_episode::fishing_mutation_result
guarded_production_mutation_port::cleanup_fishing(
    const std::uint64_t expected_observation_sequence) noexcept {
  if (!leases_.owns(lease_)) {
    return fishing_episode::fishing_mutation_result::rejected(
        "production_input_lease_lost");
  }
  last_observation_sequence_ = expected_observation_sequence;
  const auto gate = final_gate_.revalidate({
      .expected_observation_sequence = expected_observation_sequence,
      .packet_count = 2U,
      .foreground_required = false,
      .cleanup_only = true,
  });
  if (!gate.accepted) {
    return fishing_episode::fishing_mutation_result::rejected(
        gate.reason.empty() ? "fishing_cleanup_gate_rejected" : gate.reason);
  }
  const auto applied = sink_.apply({
      .kind = runtime_platform::mutation_kind::release_reeling_keys,
      .packet_count = 2U,
  });
  return applied.applied
      ? fishing_episode::fishing_mutation_result::accepted()
      : fishing_episode::fishing_mutation_result::rejected(
            applied.reason.empty() ? "fishing_cleanup_failed" : applied.reason);
}

inventory_store::inventory_mutation_result
guarded_production_mutation_port::apply(
    const inventory_store::inventory_mutation_intent& intent,
    const std::stop_token stop_token) {
  if (stop_token.stop_requested()) {
    return inventory_store::inventory_mutation_result::rejected(
        "inventory_cancelled");
  }
  if (!leases_.owns(lease_)) {
    return inventory_store::inventory_mutation_result::rejected(
        "production_input_lease_lost");
  }
  if (cleaned_) {
    return inventory_store::inventory_mutation_result::rejected(
        "production_mutation_session_cleaned");
  }
  last_observation_sequence_ = intent.expected_observation_sequence;
  if (intent.kind == inventory_store::inventory_intent_kind::stop_automation) {
    terminal_action_ = requested_terminal_action::stop;
    return inventory_store::inventory_mutation_result::accepted();
  }
  if (intent.kind == inventory_store::inventory_intent_kind::shutdown_pc) {
    if (intent.packet_count != 0U || !cleanup()) {
      return inventory_store::inventory_mutation_result::rejected(
          "production_shutdown_cleanup_failed");
    }
    const auto gate = final_gate_.revalidate({
        .expected_observation_sequence = intent.expected_observation_sequence,
        .expected_settings_revision = settings_revision_,
        .expected_entitlement_revision = entitlement_revision_,
        .expected_lifecycle_revision = lifecycle_revision_,
        .packet_count = 0U,
        .foreground_required = false,
        .effect = action_claim::effect_kind::system_terminal_action,
    });
    if (!gate.accepted) {
      return inventory_store::inventory_mutation_result::rejected(
          gate.reason.empty()
              ? "production_shutdown_final_gate_rejected"
              : gate.reason);
    }
    const auto applied = terminal_sink_.shutdown_pc();
    if (!applied.applied) {
      return inventory_store::inventory_mutation_result::rejected(
          applied.reason.empty()
              ? "production_shutdown_request_failed"
              : applied.reason);
    }
    terminal_action_ = requested_terminal_action::shutdown_pc;
    return inventory_store::inventory_mutation_result::accepted();
  }

  std::vector<runtime_platform::mutation_intent> projected;
  std::size_t gate_packets = intent.packet_count;
  switch (intent.kind) {
    case inventory_store::inventory_intent_kind::activate_window:
      projected.push_back({
          .kind = runtime_platform::mutation_kind::activate_window,
          .packet_count = 1U,
      });
      break;
    case inventory_store::inventory_intent_kind::release_all_keys:
      projected.push_back({
          .kind = runtime_platform::mutation_kind::release_all_keys,
          .packet_count = 9U,
      });
      break;
    case inventory_store::inventory_intent_kind::press_key:
      projected.push_back({
          .kind = runtime_platform::mutation_kind::press_key,
          .primary = intent.key,
          .packet_count = 2U,
      });
      break;
    case inventory_store::inventory_intent_kind::right_click_item:
      if (!valid_bounds(intent.target_bounds) || intent.item_instance_id.empty()) {
        return inventory_store::inventory_mutation_result::rejected(
            "inventory_item_target_invalid");
      }
      observer_.expect_context_item(
          intent.item_instance_id, intent.target_bounds);
      projected.push_back({
          .kind = runtime_platform::mutation_kind::click_client_right,
          .point = center(intent.target_bounds),
          .packet_count = 3U,
      });
      break;
    case inventory_store::inventory_intent_kind::click_context_action:
      if (!valid_bounds(intent.target_bounds)) {
        return inventory_store::inventory_mutation_result::rejected(
            "inventory_context_target_invalid");
      }
      projected.push_back({
          .kind = runtime_platform::mutation_kind::click_client_left,
          .point = center(intent.target_bounds),
          .packet_count = 3U,
      });
      break;
    case inventory_store::inventory_intent_kind::pause:
      if (intent.packet_count != 0U) {
        return inventory_store::inventory_mutation_result::rejected(
            "inventory_pause_shape_invalid");
      }
      return sink_.apply({
          .kind = runtime_platform::mutation_kind::pause,
          .delay_milliseconds = intent.delay_milliseconds,
      }).applied
          ? inventory_store::inventory_mutation_result::accepted()
          : inventory_store::inventory_mutation_result::rejected(
                "inventory_pause_failed");
    case inventory_store::inventory_intent_kind::use_inventory_item:
    case inventory_store::inventory_intent_kind::move_backpack_item:
      if (!valid_bounds(intent.target_bounds)) {
        return inventory_store::inventory_mutation_result::rejected(
            "inventory_item_target_invalid");
      }
      projected.push_back({
          .kind = runtime_platform::mutation_kind::move_client,
          .point = center(intent.target_bounds),
          .packet_count = 1U,
      });
      projected.push_back({
          .kind = runtime_platform::mutation_kind::press_key,
          .primary = intent.key,
          .packet_count = 2U,
      });
      break;
    case inventory_store::inventory_intent_kind::discard_inventory_item:
      if (!valid_bounds(intent.target_bounds)) {
        return inventory_store::inventory_mutation_result::rejected(
            "inventory_item_target_invalid");
      }
      projected.push_back({
          .kind = runtime_platform::mutation_kind::click_client_right,
          .point = center(intent.target_bounds),
          .packet_count = 3U,
      });
      projected.push_back({
          .kind = runtime_platform::mutation_kind::press_key,
          .primary = intent.key,
          .packet_count = 2U,
      });
      break;
    case inventory_store::inventory_intent_kind::exit_game:
      terminal_action_ = requested_terminal_action::exit_game;
      gate_packets = 4U;
      projected.push_back({
          .kind = runtime_platform::mutation_kind::hotkey,
          .primary = "alt",
          .secondary = "f4",
          .packet_count = 4U,
      });
      break;
    case inventory_store::inventory_intent_kind::stop_automation:
    case inventory_store::inventory_intent_kind::shutdown_pc:
      break;
  }
  if (projected.empty()) {
    return inventory_store::inventory_mutation_result::rejected(
        "inventory_intent_unavailable");
  }
  if (intent.kind != inventory_store::inventory_intent_kind::exit_game &&
      gate_packets == 0U) {
    return inventory_store::inventory_mutation_result::rejected(
        "inventory_packet_shape_invalid");
  }
  const auto gate = final_gate_.revalidate({
      .expected_observation_sequence = intent.expected_observation_sequence,
      .expected_settings_revision = settings_revision_,
      .expected_entitlement_revision = entitlement_revision_,
      .expected_lifecycle_revision = lifecycle_revision_,
      .packet_count = gate_packets,
      .foreground_required = true,
  });
  if (!gate.accepted) {
    observer_.clear_context_item();
    return inventory_store::inventory_mutation_result::rejected(
        gate.reason.empty() ? "inventory_final_gate_rejected" : gate.reason);
  }
  for (const auto& item : projected) {
    const auto applied = sink_.apply(item);
    if (!applied.applied) {
      observer_.clear_context_item();
      return inventory_store::inventory_mutation_result::rejected(
          applied.reason.empty()
              ? "inventory_platform_mutation_failed"
              : applied.reason);
    }
  }
  if (intent.kind ==
      inventory_store::inventory_intent_kind::click_context_action) {
    observer_.clear_context_item();
  }
  return inventory_store::inventory_mutation_result::accepted();
}

inventory_store::inventory_mutation_result
guarded_production_mutation_port::apply_catch_button(
    const std::uint64_t expected_observation_sequence,
    const stage_detection::normalized_rect& bounds,
    const std::stop_token stop_token) {
  if (stop_token.stop_requested()) {
    return inventory_store::inventory_mutation_result::rejected(
        "catch_mutation_cancelled");
  }
  if (!leases_.owns(lease_) || !valid_bounds(bounds)) {
    return inventory_store::inventory_mutation_result::rejected(
        "catch_mutation_target_invalid");
  }
  last_observation_sequence_ = expected_observation_sequence;
  const auto gate = final_gate_.revalidate({
      .expected_observation_sequence = expected_observation_sequence,
      .expected_settings_revision = settings_revision_,
      .expected_entitlement_revision = entitlement_revision_,
      .expected_lifecycle_revision = lifecycle_revision_,
      .packet_count = 3U,
      .foreground_required = true,
  });
  if (!gate.accepted) {
    return inventory_store::inventory_mutation_result::rejected(
        gate.reason.empty() ? "catch_final_gate_rejected" : gate.reason);
  }
  const auto applied = sink_.apply({
      .kind = runtime_platform::mutation_kind::click_client_left,
      .point = center(bounds),
      .packet_count = 3U,
  });
  return applied.applied
      ? inventory_store::inventory_mutation_result::accepted()
      : inventory_store::inventory_mutation_result::rejected(
            applied.reason.empty()
                ? "catch_platform_mutation_failed"
                : applied.reason);
}

requested_terminal_action
guarded_production_mutation_port::terminal_action() const noexcept {
  return terminal_action_;
}

bool guarded_production_mutation_port::cleanup() noexcept {
  if (cleaned_) {
    return true;
  }
  cleaned_ = true;
  observer_.clear_context_item();
  if (!leases_.owns(lease_)) {
    return false;
  }
  if (last_observation_sequence_ == 0U) {
    return true;
  }
  const auto snapshot_sequence = final_gate_.revalidate({
      .expected_observation_sequence = last_observation_sequence_,
      .packet_count = 9U,
      .foreground_required = false,
      .cleanup_only = true,
  });
  if (!snapshot_sequence.accepted) {
    return false;
  }
  return sink_.apply({
      .kind = runtime_platform::mutation_kind::release_all_keys,
      .packet_count = 9U,
  }).applied;
}

}  // namespace sonar::fishing::automation_adapters
