#include <array>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>

#include "sonar/fishing/engine_ipc/engine_mode.h"
#include "sonar/fishing/engine_ipc/session_lifecycle.h"

namespace {

using sonar::fishing::engine_ipc::accepted_entitlement;
using sonar::fishing::engine_ipc::engine_authority_mode;
using sonar::fishing::engine_ipc::fishing_session_lifecycle;
using sonar::fishing::engine_ipc::start_session_context;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

[[nodiscard]] start_session_context valid_context() {
  return start_session_context{
      .authority_mode = engine_authority_mode::production,
      .side_effects_negotiated = true,
      .expected_settings_revision = 7,
      .accepted_settings_revision = 7,
      .settings_snapshot_present = true,
      .entitlement = accepted_entitlement{
          .generation = 11,
          .expires_unix_seconds = 2'000,
      },
      .now_unix_seconds = 1'000,
      .capability_composition_ready = true,
      .capability_reason = "production_capability_composition_ready",
  };
}

void handshake_is_mode_specific() {
  sonar::platform::ipc::v1::HandshakeHello offline;
  sonar::fishing::engine_ipc::apply_handshake_mode(
      offline, engine_authority_mode::offline_diagnostics);
  require(offline.diagnostic_mode(), "offline_handshake_not_diagnostic");
  require(!offline.side_effect_support(), "offline_side_effects_advertised");
  require(offline.capabilities_size() == 0, "offline_session_control_advertised");
  const auto offline_policy = sonar::fishing::engine_ipc::handshake_policy(
      engine_authority_mode::offline_diagnostics);
  require(
      !offline_policy.side_effects_may_be_enabled,
      "offline_acceptance_may_enable_side_effects");

  sonar::platform::ipc::v1::HandshakeHello production;
  sonar::fishing::engine_ipc::apply_handshake_mode(
      production, engine_authority_mode::production);
  require(!production.diagnostic_mode(), "production_handshake_diagnostic");
  require(production.side_effect_support(), "production_side_effects_missing");
  require(production.capabilities_size() == 2, "production_capability_count_changed");
  require(
      production.capabilities(0).capability_id() ==
          sonar::fishing::engine_ipc::
              fishing_session_statistics_reset_capability_id,
      "production_statistics_reset_missing");
  require(
      production.capabilities(0).major() == 1 &&
          production.capabilities(0).minor() == 0,
      "production_statistics_reset_version_changed");
  require(
      production.capabilities(1).capability_id() ==
          sonar::fishing::engine_ipc::fishing_session_control_capability_id &&
          production.capabilities(1).major() == 1 &&
          production.capabilities(1).minor() == 0,
      "production_session_control_missing");
  const auto production_policy = sonar::fishing::engine_ipc::handshake_policy(
      engine_authority_mode::production);
  require(
      production_policy.side_effects_may_be_enabled,
      "production_acceptance_cannot_enable_side_effects");

  sonar::platform::ipc::v1::HandshakeHello developer;
  sonar::fishing::engine_ipc::apply_handshake_mode(
      developer, engine_authority_mode::developer_full_access);
  require(!developer.diagnostic_mode(), "developer_handshake_diagnostic");
  require(developer.side_effect_support(), "developer_side_effects_missing");
  require(
      developer.capabilities_size() == 2,
      "developer_capability_count_changed");
}

void production_start_gates_fail_closed() {
  struct test_case final {
    std::string_view name;
    void (*mutate)(start_session_context&);
    std::string_view expected_reason;
  };
  constexpr std::array cases{
      test_case{
          "offline_mode",
          [](start_session_context& value) {
            value.authority_mode = engine_authority_mode::offline_diagnostics;
          },
          "production_authority_required",
      },
      test_case{
          "side_effects_disabled",
          [](start_session_context& value) { value.side_effects_negotiated = false; },
          "side_effects_not_negotiated",
      },
      test_case{
          "settings_missing",
          [](start_session_context& value) { value.settings_snapshot_present = false; },
          "runtime_settings_required_before_session",
      },
      test_case{
          "settings_revision_mismatch",
          [](start_session_context& value) { value.expected_settings_revision = 6; },
          "runtime_settings_revision_mismatch",
      },
      test_case{
          "entitlement_missing",
          [](start_session_context& value) { value.entitlement.clear(); },
          "signed_entitlement_required_before_session",
      },
      test_case{
          "entitlement_expired",
          [](start_session_context& value) { value.now_unix_seconds = 2'000; },
          "signed_entitlement_expired",
      },
      test_case{
          "capability_composition_unavailable",
          [](start_session_context& value) {
            value.capability_composition_ready = false;
            value.capability_reason = "production_capability_adapters_unavailable";
          },
          "production_capability_adapters_unavailable",
      },
  };

  for (const auto& item : cases) {
    auto context = valid_context();
    item.mutate(context);
    fishing_session_lifecycle lifecycle;
    const auto result = lifecycle.start(context);
    require(!result.accepted, item.name);
    require(result.status == "rejected", item.name);
    require(result.reason == item.expected_reason, item.name);
    require(!lifecycle.running(), item.name);
  }
}

void start_and_stop_are_coarse_and_bounded() {
  fishing_session_lifecycle lifecycle;
  const auto validated = lifecycle.validate_start(valid_context());
  require(validated.accepted, "pure_start_admission_rejected");
  require(!lifecycle.running(), "pure_start_admission_mutated_lifecycle");
  const auto started = lifecycle.start(valid_context());
  require(started.accepted, "valid_start_rejected");
  require(started.status == "completed", "valid_start_status_changed");
  require(started.reason == "fishing_session_started", "valid_start_reason_changed");
  require(lifecycle.running(), "lifecycle_not_running");
  require(lifecycle.settings_revision() == 7, "active_settings_revision_changed");
  require(lifecycle.entitlement_generation() == 11, "active_entitlement_changed");

  const auto duplicate = lifecycle.start(valid_context());
  require(!duplicate.accepted, "duplicate_start_accepted");
  require(
      duplicate.reason == "fishing_session_already_running",
      "duplicate_start_reason_changed");

  const auto stopped = lifecycle.stop();
  require(stopped.accepted, "stop_rejected");
  require(stopped.reason == "automation_stopped", "stop_reason_changed");
  require(!lifecycle.running(), "lifecycle_still_running");
  require(lifecycle.settings_revision() == 0, "stopped_settings_not_cleared");
  require(lifecycle.entitlement_generation() == 0, "stopped_entitlement_not_cleared");

  const auto repeated_stop = lifecycle.stop();
  require(repeated_stop.accepted, "idempotent_stop_rejected");
  require(
      repeated_stop.reason == "automation_already_stopped",
      "idempotent_stop_reason_changed");
}

void completed_operation_reconciliation_is_exactly_once_and_restartable() {
  fishing_session_lifecycle lifecycle;
  const auto started = lifecycle.start(valid_context());
  require(started.accepted, "completion_race_start_rejected");

  const auto pending = lifecycle.reconcile_completion(
      false,
      "original-start-request");
  require(!pending.transitioned, "pending_progress_stopped_lifecycle");
  require(lifecycle.running(), "pending_progress_cleared_lifecycle");

  const auto reset_capture = lifecycle.reconcile_completion(
      true,
      "original-start-request");
  require(reset_capture.transitioned, "reset_completion_was_not_reconciled");
  require(
      reset_capture.correlation_id == "original-start-request",
      "reset_completion_lost_original_start_correlation");
  require(!lifecycle.running(), "completed_reset_capture_left_lifecycle_running");

  const auto next_pending = lifecycle.reconcile_completion(
      true,
      "original-start-request");
  require(!next_pending.transitioned, "completion_notification_would_be_duplicated");
  require(next_pending.correlation_id.empty(), "duplicate_completion_retained_correlation");

  const auto restarted = lifecycle.start(valid_context());
  require(restarted.accepted, "completed_session_blocked_subsequent_start");
}

void developer_authority_is_compile_isolated() {
  auto context = valid_context();
  context.authority_mode = engine_authority_mode::developer_full_access;
  fishing_session_lifecycle lifecycle;
  const auto result = lifecycle.start(context);
#if defined(SONAR_FISHING_DEVELOPER_FULL_ACCESS)
  require(result.accepted, "compiled_developer_authority_rejected");
  require(lifecycle.running(), "compiled_developer_session_not_running");
#else
  require(!result.accepted, "production_build_accepted_developer_authority");
  require(
      result.reason == "production_authority_required",
      "production_developer_rejection_reason_changed");
  require(!lifecycle.running(), "production_developer_rejection_mutated_state");
#endif
}

}  // namespace

int main() {
  try {
    handshake_is_mode_specific();
    production_start_gates_fail_closed();
    start_and_stop_are_coarse_and_bounded();
    completed_operation_reconciliation_is_exactly_once_and_restartable();
    developer_authority_is_compile_isolated();
    std::cout << "PASS Fishing Engine mode handshake and session lifecycle\n";
    return 0;
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
