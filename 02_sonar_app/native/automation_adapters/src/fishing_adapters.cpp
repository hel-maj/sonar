#include "sonar/fishing/automation_adapters/fishing_adapters.h"

#include "memory_capture_retry.h"

#include <algorithm>
#include <limits>
#include <string_view>
#include <utility>

namespace sonar::fishing::automation_adapters {
namespace {

[[nodiscard]] std::string_view key_for(
    const reeling_control::HeldKey key) noexcept {
  switch (key) {
    case reeling_control::HeldKey::none: return {};
    case reeling_control::HeldKey::a: return "a";
    case reeling_control::HeldKey::d: return "d";
  }
  return {};
}

class guarded_fishing_mutation_session final
    : public fishing_episode::fishing_mutation_session {
 public:
  guarded_fishing_mutation_session(
      runtime_platform::automation_lease lease,
      runtime_platform::automation_lease_coordinator& coordinator,
      immediate_action_gate& final_gate,
      runtime_platform::platform_mutation_sink& sink) noexcept
      : lease_(std::move(lease)),
        coordinator_(coordinator),
        final_gate_(final_gate),
        sink_(sink) {}

  [[nodiscard]] fishing_episode::fishing_mutation_result apply(
      const fishing_episode::fishing_mutation_intent& intent,
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested()) {
      return fishing_episode::fishing_mutation_result::rejected(
          "fishing_mutation_cancelled");
    }
    if (!coordinator_.owns(lease_)) {
      return fishing_episode::fishing_mutation_result::rejected(
          "fishing_input_lease_lost");
    }
    runtime_platform::mutation_intent platform_intent;
    switch (intent.kind) {
      case fishing_episode::fishing_mutation_kind::tap_cast_space:
      case fishing_episode::fishing_mutation_kind::tap_hook_space:
        platform_intent = {
            .kind = runtime_platform::mutation_kind::press_key,
            .primary = "space",
            .packet_count = 2U,
        };
        break;
      case fishing_episode::fishing_mutation_kind::pulse_reeling_key: {
        const auto desired = intent.desired_reeling_key;
        const auto key = key_for(desired);
        if (key.empty()) {
          return fishing_episode::fishing_mutation_result::rejected(
              "fishing_reeling_pulse_key_invalid");
        }
        platform_intent = {
            .kind = runtime_platform::mutation_kind::press_key,
            .primary = std::string(key),
            .packet_count = 2U,
        };
        break;
      }
    }
    if (platform_intent.packet_count != intent.packet_count) {
      return fishing_episode::fishing_mutation_result::rejected(
          "fishing_mutation_packet_shape_invalid");
    }
    const auto gate = final_gate_.revalidate({
        .expected_observation_sequence = intent.expected_observation_sequence,
        .expected_settings_revision = intent.expected_settings_revision,
        .expected_entitlement_revision = intent.expected_entitlement_revision,
        .expected_lifecycle_revision = intent.expected_lifecycle_revision,
        .packet_count = platform_intent.packet_count,
        .foreground_required = true,
    });
    if (!gate.accepted) {
      return fishing_episode::fishing_mutation_result::rejected(
          gate.reason.empty() ? "fishing_final_gate_rejected" : gate.reason);
    }
    const auto applied = sink_.apply(platform_intent);
    if (!applied.applied) {
      return fishing_episode::fishing_mutation_result::rejected(
          applied.reason.empty()
              ? "fishing_platform_mutation_failed"
              : applied.reason);
    }
    return fishing_episode::fishing_mutation_result::accepted();
  }

  [[nodiscard]] fishing_episode::fishing_mutation_result cleanup_reeling_keys(
      const std::uint64_t expected_observation_sequence) noexcept override {
    if (!coordinator_.owns(lease_)) {
      return fishing_episode::fishing_mutation_result::rejected(
          "fishing_cleanup_lease_lost");
    }
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
    const auto result = sink_.apply({
        .kind = runtime_platform::mutation_kind::release_reeling_keys,
        .packet_count = 2U,
    });
    if (!result.applied) {
      return fishing_episode::fishing_mutation_result::rejected(
          result.reason.empty() ? "fishing_cleanup_failed" : result.reason);
    }
    return fishing_episode::fishing_mutation_result::accepted();
  }

 private:
  runtime_platform::automation_lease lease_;
  runtime_platform::automation_lease_coordinator& coordinator_;
  immediate_action_gate& final_gate_;
  runtime_platform::platform_mutation_sink& sink_;
};

}  // namespace

memory_snapshot_result unavailable_fishing_memory_source::capture(
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns,
    const sonar::platform::windows::process_generation& game_generation,
    const bool reeling_stage_visible)
    noexcept {
  static_cast<void>(sequence);
  static_cast<void>(captured_at_steady_ns);
  static_cast<void>(game_generation);
  static_cast<void>(reeling_stage_visible);
  return {.reason = "production_memory_profile_unavailable"};
}

resolved_fishing_memory_source::resolved_fishing_memory_source(
    std::unique_ptr<memory_observation::memory_connector> connector,
    std::unique_ptr<inventory_open_source> inventory_open,
    std::unique_ptr<inventory_retry_clock> retry_clock)
    : connector_(std::move(connector)),
      inventory_open_(std::move(inventory_open)),
      retry_clock_(std::move(retry_clock)) {
  if (connector_) {
    resolver_ = std::make_unique<
        memory_observation::memory_capture_plan_resolver>(*connector_);
    observer_ = std::make_unique<memory_observation::memory_observer>(
        *connector_);
  }
}

memory_snapshot_result resolved_fishing_memory_source::capture(
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns,
    const sonar::platform::windows::process_generation& game_generation,
    const bool reeling_stage_visible)
    noexcept {
  if (!reeling_stage_visible) {
    if (!inventory_open_ || !retry_clock_) {
      return {.reason = "production_inventory_source_unavailable"};
    }
    if (inventory_game_generation_.has_value() &&
        *inventory_game_generation_ != game_generation) {
      inventory_open_->reset();
      inventory_unknown_streak_ = 0U;
      inventory_retry_not_before_ns_ = 0U;
      inventory_unknown_reason_.clear();
    }
    inventory_game_generation_ = game_generation;
    const auto now_ns = retry_clock_->now_steady_ns();
    inventory_open_source_result observed;
    if (inventory_retry_not_before_ns_ != 0U &&
        now_ns < inventory_retry_not_before_ns_) {
      observed.reason = inventory_unknown_reason_;
    } else {
      observed = inventory_open_->capture(game_generation);
      if (observed.state ==
          sonar::platform::inventory::observed_state::unknown) {
        inventory_unknown_streak_ = std::min(
            inventory_unknown_streak_ + 1U, 5U);
        constexpr std::uint64_t base_delay_ns = 250'000'000ULL;
        constexpr std::uint64_t maximum_delay_ns = 4'000'000'000ULL;
        const auto delay_ns = std::min(
            base_delay_ns << (inventory_unknown_streak_ - 1U),
            maximum_delay_ns);
        inventory_retry_not_before_ns_ =
            now_ns > std::numeric_limits<std::uint64_t>::max() - delay_ns
            ? std::numeric_limits<std::uint64_t>::max()
            : now_ns + delay_ns;
        inventory_unknown_reason_ = observed.reason.empty()
            ? "production_inventory_state_unknown"
            : observed.reason;
        observed.reason = inventory_unknown_reason_;
      } else {
        inventory_unknown_streak_ = 0U;
        inventory_retry_not_before_ns_ = 0U;
        inventory_unknown_reason_.clear();
      }
    }
    memory_observation::coherent_memory_snapshot snapshot{
        .sequence = sequence,
        .captured_at_steady_ns = captured_at_steady_ns,
        .profile_id = std::string(common_inventory_open_package_version),
        .profile_revision = 1U,
        .game_generation = game_generation,
        .inventory_open_state = observed.state,
    };
    return {
        .snapshot = std::move(snapshot),
        .reason = std::move(observed.reason),
    };
  }
  if (!resolver_ || !observer_) {
    return {.reason = "production_memory_connector_unavailable"};
  }
  return detail::capture_reeling_with_bounded_retry(
      *resolver_,
      *observer_,
      sequence,
      captured_at_steady_ns,
      game_generation);
}

frame_fishing_observer::frame_fishing_observer(
    runtime_platform::client_capture_source& capture,
    stage_detection::majestic_fishing_stage_detector& stage_detector,
    fishing_memory_source& memory,
    mutable_runtime_policy_source& policy) noexcept
    : capture_(capture),
      stage_detector_(stage_detector),
      memory_(memory),
      policy_(policy) {}

fishing_episode::fishing_episode_observation
frame_fishing_observer::observe(const std::stop_token stop_token) {
  if (stop_token.stop_requested()) {
    return {.error = "fishing_observation_cancelled"};
  }
  auto captured = capture_.capture();
  if (!captured.frame.has_value() || !captured.frame->valid()) {
    return {.error = captured.reason.empty()
        ? "fishing_capture_unavailable"
        : std::move(captured.reason)};
  }
  auto frame = std::move(*captured.frame);
  const auto stage = stage_detector_.detect({
      .width = frame.width,
      .height = frame.height,
      .stride_bytes = frame.stride_bytes,
      .pixels = frame.bgr24,
  });
  if (!stage.error.empty()) {
    return {
        .sequence = frame.sequence,
        .captured_at_steady_ns = frame.captured_at_steady_ns,
        .error = stage.error,
    };
  }
  const auto semantics = detect_frame_semantics(frame);
  fishing_episode::fishing_episode_observation result{
      .sequence = frame.sequence,
      .captured_at_steady_ns = frame.captured_at_steady_ns,
      .stage = stage.observation,
      .cast_ready = semantics.cast_ready,
      .cast_confidence = semantics.cast_confidence,
      .hook = semantics.hook,
      .hook_confidence = semantics.hook_confidence,
      .catch_visible = semantics.catch_visible,
  };
  if (stage.observation.has_value() &&
      stage.observation->stage ==
          stage_detection::observed_fishing_stage::reeling) {
    auto memory = memory_.capture(
        frame.sequence,
        frame.captured_at_steady_ns,
        frame.target.process,
        true);
    if (memory.snapshot.has_value() && memory.snapshot->reeling.has_value()) {
      result.memory = std::move(memory.snapshot);
    } else {
      result.error = memory.reason.empty()
          ? "fishing_memory_unavailable"
          : std::move(memory.reason);
    }
  }
  policy_.observe(frame.sequence);
  return result;
}

guarded_fishing_mutation_port::guarded_fishing_mutation_port(
    runtime_platform::automation_lease_coordinator& leases,
    immediate_action_gate& final_gate,
    runtime_platform::platform_mutation_sink& sink) noexcept
    : leases_(leases), final_gate_(final_gate), sink_(sink) {}

std::unique_ptr<fishing_episode::fishing_mutation_session>
guarded_fishing_mutation_port::acquire(
    const fishing_episode::fishing_episode_request& request,
    const std::stop_token stop_token,
    std::string& reason) {
  static_cast<void>(request);
  if (stop_token.stop_requested()) {
    reason = "fishing_episode_cancelled";
    return nullptr;
  }
  auto lease = leases_.try_acquire();
  if (!lease.has_value()) {
    reason = "fishing_input_lease_busy";
    return nullptr;
  }
  return std::make_unique<guarded_fishing_mutation_session>(
      std::move(*lease), leases_, final_gate_, sink_);
}

}  // namespace sonar::fishing::automation_adapters
