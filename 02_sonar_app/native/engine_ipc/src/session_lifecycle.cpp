#include "sonar/fishing/engine_ipc/session_lifecycle.h"

namespace sonar::fishing::engine_ipc {

bool accepted_entitlement::valid_at(
    const std::int64_t now_unix_seconds) const noexcept {
  return generation != 0 && now_unix_seconds < expires_unix_seconds;
}

void accepted_entitlement::clear() noexcept {
  generation = 0;
  expires_unix_seconds = 0;
}

session_transition fishing_session_lifecycle::validate_start(
    const start_session_context& context) const noexcept {
  if (context.authority_mode != engine_authority_mode::production
#if defined(SONAR_FISHING_DEVELOPER_FULL_ACCESS)
      && context.authority_mode != engine_authority_mode::developer_full_access
#endif
  ) {
    return {false, "rejected", "production_authority_required"};
  }
  if (!context.side_effects_negotiated) {
    return {false, "rejected", "side_effects_not_negotiated"};
  }
  if (!context.settings_snapshot_present ||
      context.accepted_settings_revision == 0) {
    return {false, "rejected", "runtime_settings_required_before_session"};
  }
  if (context.expected_settings_revision == 0 ||
      context.expected_settings_revision != context.accepted_settings_revision) {
    return {false, "rejected", "runtime_settings_revision_mismatch"};
  }
  if (context.entitlement.generation == 0) {
    return {false, "rejected", "signed_entitlement_required_before_session"};
  }
  if (!context.entitlement.valid_at(context.now_unix_seconds)) {
    return {false, "rejected", "signed_entitlement_expired"};
  }
  if (!context.capability_composition_ready) {
    return {
        false,
        "rejected",
        context.capability_reason.empty()
            ? std::string_view{"production_capability_composition_unavailable"}
            : context.capability_reason,
    };
  }
  if (running_) {
    return {false, "rejected", "fishing_session_already_running"};
  }

  return {true, "completed", "fishing_session_admission_ready"};
}

session_transition fishing_session_lifecycle::start(
    const start_session_context& context) noexcept {
  const auto validation = validate_start(context);
  if (!validation.accepted) {
    return validation;
  }

  running_ = true;
  settings_revision_ = context.accepted_settings_revision;
  entitlement_generation_ = context.entitlement.generation;
  return {true, "completed", "fishing_session_started"};
}

session_transition fishing_session_lifecycle::stop() noexcept {
  if (!running_) {
    return {true, "completed", "automation_already_stopped"};
  }
  running_ = false;
  settings_revision_ = 0;
  entitlement_generation_ = 0;
  return {true, "completed", "automation_stopped"};
}

session_completion_reconciliation
fishing_session_lifecycle::reconcile_completion(
    const bool operation_completed,
    const std::string_view active_start_correlation_id) noexcept {
  if (!operation_completed || !running_) {
    return {};
  }
  static_cast<void>(stop());
  return {
      true,
      active_start_correlation_id,
  };
}

bool fishing_session_lifecycle::running() const noexcept {
  return running_;
}

std::uint64_t fishing_session_lifecycle::settings_revision() const noexcept {
  return settings_revision_;
}

std::uint64_t fishing_session_lifecycle::entitlement_generation() const noexcept {
  return entitlement_generation_;
}

}  // namespace sonar::fishing::engine_ipc
