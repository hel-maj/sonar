#include "sonar/fishing/automation_adapters/fishing_adapters.h"

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
    const memory_capture_scope scope,
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns,
    const sonar::platform::windows::process_generation& game_generation)
    noexcept {
  static_cast<void>(scope);
  static_cast<void>(sequence);
  static_cast<void>(captured_at_steady_ns);
  static_cast<void>(game_generation);
  return {.reason = "production_memory_profile_unavailable"};
}

resolved_fishing_memory_source::resolved_fishing_memory_source(
    std::unique_ptr<memory_observation::memory_connector> connector)
    : connector_(std::move(connector)) {
  if (connector_) {
    resolver_ = std::make_unique<
        memory_observation::memory_capture_plan_resolver>(*connector_);
    observer_ = std::make_unique<memory_observation::memory_observer>(
        *connector_);
  }
}

memory_snapshot_result resolved_fishing_memory_source::capture(
    const memory_capture_scope scope,
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns,
    const sonar::platform::windows::process_generation& game_generation)
    noexcept {
  if (!resolver_ || !observer_) {
    return {.reason = "production_memory_connector_unavailable"};
  }
  std::optional<memory_observation::memory_observation_profile> profile;
  std::optional<memory_observation::capture_plan> plan;
  std::string resolution_reason;
  switch (scope) {
    case memory_capture_scope::reeling: {
      auto resolved = resolver_->resolve_reeling(
          sequence, captured_at_steady_ns, game_generation);
      if (resolved.ready()) {
        profile = std::move(resolved.profile);
        plan = std::move(resolved.plan);
      } else {
        resolution_reason = std::move(resolved.reason);
      }
      break;
    }
    case memory_capture_scope::inventory_state: {
      auto resolved = resolver_->resolve_inventory(
          sequence, captured_at_steady_ns, game_generation);
      if (resolved.ready()) {
        profile = std::move(resolved.profile);
        plan = std::move(resolved.plan);
      } else {
        resolution_reason = std::move(resolved.reason);
      }
      break;
    }
  }
  if (!profile.has_value() || !plan.has_value()) {
    return {.reason = resolution_reason.empty()
        ? "production_memory_profile_unavailable"
        : std::move(resolution_reason)};
  }
  auto captured = observer_->capture(*profile, *plan);
  if (!captured.ready()) {
    return {.reason = captured.reason.empty()
        ? "production_memory_capture_unavailable"
        : std::move(captured.reason)};
  }
  return {.snapshot = std::move(captured.snapshot)};
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
        memory_capture_scope::reeling,
        frame.sequence,
        frame.captured_at_steady_ns,
        frame.target.process);
    result.memory = std::move(memory.snapshot);
    if (!result.memory.has_value()) {
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
