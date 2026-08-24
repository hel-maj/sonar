#include "sonar/fishing/live_observation_preflight/live_observation_preflight.h"

#include <stdexcept>
#include <string>
#include <string_view>

namespace preflight = sonar::fishing::live_observation_preflight;

namespace {

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

class fake_port final : public preflight::observation_port {
 public:
  [[nodiscard]] preflight::target_probe resolve_target() noexcept override {
    ++target_calls;
    return target;
  }

  [[nodiscard]] preflight::build_probe inspect_build() noexcept override {
    ++build_calls;
    return build;
  }

  [[nodiscard]] preflight::observation_probe capture_and_detect()
      noexcept override {
    ++capture_calls;
    return capture;
  }

  [[nodiscard]] preflight::observation_probe capture_memory()
      noexcept override {
    ++memory_calls;
    return memory;
  }

  preflight::target_probe target{
      .process_ready = true,
      .window_ready = true,
      .width = 3840U,
      .height = 2160U,
      .reason = preflight::readiness_reason::ready,
  };
  preflight::build_probe build{
      .build_ready = true,
      .profile_ready = true,
      .reason = preflight::readiness_reason::ready,
  };
  preflight::observation_probe capture{
      .ready = true,
      .reason = preflight::readiness_reason::ready,
  };
  preflight::observation_probe memory{
      .ready = true,
      .reason = preflight::readiness_reason::ready,
  };
  int target_calls{};
  int build_calls{};
  int capture_calls{};
  int memory_calls{};
};

void one_bounded_ready_pass_reports_only_coarse_state() {
  fake_port port;
  const auto result = preflight::run(port);

  require(result.ready, "ready_pass_rejected");
  require(result.process_ready && result.window_ready && result.build_ready &&
      result.profile_ready && result.capture_ready && result.memory_ready,
      "ready_aggregate_incomplete");
  require(result.reason == preflight::readiness_reason::ready,
      "ready_reason_changed");
  require(port.target_calls == 1 && port.build_calls == 1 &&
      port.capture_calls == 1 && port.memory_calls == 1,
      "preflight_not_one_shot");

  const auto json = preflight::serialize_json(result);
  require(json ==
      "{\"schema_version\":1,\"ready\":true,\"process_ready\":true,"
      "\"window_ready\":true,\"build_ready\":true,"
      "\"profile_ready\":true,\"capture_ready\":true,"
      "\"memory_ready\":true,\"reason\":\"ready\"}",
      "coarse_json_contract_changed");
  for (const auto forbidden : {
           "pid", "hwnd", "window_handle", "path", "sha256", "address",
           "pixels", "profile_id", "stage", "confidence"}) {
    require(json.find(forbidden) == std::string::npos,
        "sensitive_or_fine_data_leaked");
  }
}

void target_failure_stops_before_any_process_access() {
  fake_port port;
  port.target = {
      .reason = preflight::readiness_reason::game_process_unavailable,
  };
  const auto result = preflight::run(port);

  require(!result.ready &&
      result.reason == preflight::readiness_reason::game_process_unavailable,
      "missing_process_not_fail_closed");
  require(port.target_calls == 1 && port.build_calls == 0 &&
      port.capture_calls == 0 && port.memory_calls == 0,
      "target_failure_touched_downstream_adapter");
}

void capture_budget_is_checked_before_capture() {
  fake_port port;
  port.target.width = 8192U;
  port.target.height = 8192U;
  const auto result = preflight::run(port);

  require(!result.ready && result.process_ready && result.window_ready,
      "oversized_geometry_lost_target_readiness");
  require(result.reason ==
      preflight::readiness_reason::capture_geometry_unsupported,
      "oversized_geometry_reason_changed");
  require(port.build_calls == 0 && port.capture_calls == 0 &&
      port.memory_calls == 0,
      "oversized_geometry_allocated_or_read_process");
}

void unsupported_build_still_checks_readonly_capture_but_skips_memory() {
  fake_port port;
  port.build = {
      .build_ready = true,
      .reason = preflight::readiness_reason::game_build_unsupported,
  };
  const auto result = preflight::run(port);

  require(!result.ready && result.build_ready && !result.profile_ready,
      "unsupported_profile_not_reported");
  require(result.capture_ready && !result.memory_ready,
      "unsupported_profile_aggregate_changed");
  require(result.reason == preflight::readiness_reason::game_build_unsupported,
      "unsupported_profile_reason_changed");
  require(port.capture_calls == 1 && port.memory_calls == 0,
      "unsupported_profile_touched_memory");
}

void detector_failure_blocks_memory_and_readiness() {
  fake_port port;
  port.capture = {
      .reason = preflight::readiness_reason::detector_unavailable,
  };
  const auto result = preflight::run(port);

  require(!result.ready && !result.capture_ready && !result.memory_ready,
      "detector_failure_not_fail_closed");
  require(result.reason == preflight::readiness_reason::detector_unavailable,
      "detector_failure_reason_changed");
  require(port.memory_calls == 0, "detector_failure_touched_memory");
}

void memory_failure_preserves_prior_readiness() {
  fake_port port;
  port.memory = {
      .reason = preflight::readiness_reason::memory_unavailable,
  };
  const auto result = preflight::run(port);

  require(!result.ready && result.process_ready && result.window_ready &&
      result.build_ready && result.profile_ready && result.capture_ready &&
      !result.memory_ready,
      "memory_failure_aggregate_changed");
  require(result.reason == preflight::readiness_reason::memory_unavailable,
      "memory_failure_reason_changed");
}

}  // namespace

int main() {
  one_bounded_ready_pass_reports_only_coarse_state();
  target_failure_stops_before_any_process_access();
  capture_budget_is_checked_before_capture();
  unsupported_build_still_checks_readonly_capture_but_skips_memory();
  detector_failure_blocks_memory_and_readiness();
  memory_failure_preserves_prior_readiness();
  return 0;
}
