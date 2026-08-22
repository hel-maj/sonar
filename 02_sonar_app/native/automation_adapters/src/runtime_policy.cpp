#include "sonar/fishing/automation_adapters/runtime_policy.h"

#include <chrono>
#include <utility>

namespace sonar::fishing::automation_adapters {
namespace {

[[nodiscard]] std::string action_reason_text(
    const runtime_safety::action_reason reason) {
  using value = runtime_safety::action_reason;
  switch (reason) {
    case value::ready: return {};
    case value::entitlement_invalid: return "entitlement_invalid";
    case value::settings_not_current: return "settings_not_current";
    case value::lifecycle_not_actionable: return "lifecycle_not_actionable";
    case value::invalid_packet_count: return "input_packet_count_invalid";
    case value::process_unavailable: return "process_unavailable";
    case value::process_changed: return "process_changed";
    case value::window_unavailable: return "window_unavailable";
    case value::window_changed: return "window_changed";
    case value::window_not_foreground: return "window_not_foreground";
    case value::packet_budget_exhausted: return "input_packet_budget_exhausted";
  }
  return "final_gate_unknown";
}

}  // namespace

bool runtime_policy_snapshot::entitlement_valid_at(
    const std::int64_t now_unix_seconds) const noexcept {
  return entitlement_valid && entitlement_revision != 0U &&
      now_unix_seconds < entitlement_expires_unix_seconds;
}

runtime_policy_snapshot mutable_runtime_policy_source::snapshot() const {
  std::lock_guard lock(mutex_);
  return value_;
}

void mutable_runtime_policy_source::publish(runtime_policy_snapshot value) {
  std::lock_guard lock(mutex_);
  value_ = std::move(value);
}

bool mutable_runtime_policy_source::refresh_entitlement_expiry(
    const std::uint64_t admitted_entitlement_revision,
    const std::int64_t expires_unix_seconds) noexcept {
  std::lock_guard lock(mutex_);
  if (!value_.entitlement_valid || !value_.lifecycle_allows_input ||
      admitted_entitlement_revision == 0U ||
      value_.entitlement_revision != admitted_entitlement_revision ||
      expires_unix_seconds <= 0) {
    return false;
  }
  value_.entitlement_expires_unix_seconds = expires_unix_seconds;
  return true;
}

void mutable_runtime_policy_source::stop() noexcept {
  std::lock_guard lock(mutex_);
  value_.lifecycle_allows_input = false;
}

void mutable_runtime_policy_source::observe(
    const std::uint64_t sequence) noexcept {
  std::lock_guard lock(mutex_);
  value_.latest_observation_sequence = sequence;
}

runtime_safety_action_gate::runtime_safety_action_gate(
    runtime_safety::runtime_target_guard& target,
    const runtime_policy_source& policy) noexcept
    : target_(target), policy_(policy) {}

action_gate_result runtime_safety_action_gate::revalidate(
    const action_claim& claim) noexcept {
  try {
    const auto policy = policy_.snapshot();
    if (claim.expected_observation_sequence !=
        policy.latest_observation_sequence) {
      return {.reason = "observation_sequence_stale"};
    }
    if (claim.cleanup_only) {
      const auto reason = target_.preflight_cleanup(claim.packet_count);
      return reason == runtime_safety::action_reason::ready
          ? action_gate_result{true, {}}
          : action_gate_result{false, action_reason_text(reason)};
    }
    if (claim.expected_settings_revision != policy.settings_revision) {
      return {.reason = "settings_revision_stale"};
    }
    if (claim.expected_entitlement_revision !=
        policy.entitlement_revision) {
      return {.reason = "entitlement_revision_stale"};
    }
    if (claim.expected_lifecycle_revision != policy.lifecycle_revision) {
      return {.reason = "lifecycle_revision_stale"};
    }
    const auto now_unix_seconds =
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    const bool entitlement_current =
        policy.entitlement_valid_at(now_unix_seconds);
    if (!entitlement_current) {
      return {.reason = "entitlement_invalid"};
    }
    if (!policy.settings_current) {
      return {.reason = "settings_not_current"};
    }
    if (!policy.lifecycle_allows_input) {
      return {.reason = "lifecycle_not_actionable"};
    }
    if (claim.effect == action_claim::effect_kind::system_terminal_action) {
      if (claim.packet_count != 0U || claim.cleanup_only) {
        return {.reason = "system_terminal_action_shape_invalid"};
      }
      const auto reason =
          target_.preflight_target_identity(claim.foreground_required);
      return reason == runtime_safety::action_reason::ready
          ? action_gate_result{true, {}}
          : action_gate_result{false, action_reason_text(reason)};
    }
    const auto reason = target_.preflight({
        .entitlement_valid = entitlement_current,
        .settings_current = policy.settings_current,
        .lifecycle_allows_input = policy.lifecycle_allows_input,
        .packet_count = claim.packet_count,
        .foreground_required = claim.foreground_required,
    });
    return reason == runtime_safety::action_reason::ready
        ? action_gate_result{true, {}}
        : action_gate_result{false, action_reason_text(reason)};
  } catch (...) {
    return {.reason = "final_gate_failed"};
  }
}

}  // namespace sonar::fishing::automation_adapters
