#include "sonar/fishing/build_profile_compatibility_probe/build_profile_compatibility_probe.h"

#include <stdexcept>
#include <string>
#include <string_view>

namespace probe = sonar::fishing::build_profile_compatibility_probe;

namespace {

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

class fake_port final : public probe::compatibility_port {
 public:
  [[nodiscard]] probe::identity_probe inspect_identity() noexcept override {
    ++identity_calls;
    return identity;
  }

  [[nodiscard]] probe::validation_probe validate_candidate()
      noexcept override {
    ++validation_calls;
    return validation;
  }

  probe::identity_probe identity{
      .process_ready = true,
      .window_ready = true,
      .hash_ready = true,
      .baseline_ready = true,
      .candidate_sha256 = std::string(64U, 'A'),
      .baseline_profile_id = "majestic-gta5-677e4e35-v1",
      .baseline_profile_revision = 1U,
      .reason = probe::readiness_reason::ready,
  };
  probe::validation_probe validation{
      .patterns_unique = true,
      .fish_identity_ready = true,
      .snapshot_ready = true,
      .reason = probe::readiness_reason::ready,
  };
  int identity_calls{};
  int validation_calls{};
};

void ready_probe_is_one_shot_and_serializes_allowlist() {
  fake_port port;
  const auto result = probe::run(port);
  require(result.ready, "ready_candidate_rejected");
  require(port.identity_calls == 1 && port.validation_calls == 1,
      "compatibility_probe_not_one_shot");
  const auto json = probe::serialize_json(result);
  require(json ==
      "{\"schema_version\":1,\"ready\":true,\"process_ready\":true,"
      "\"window_ready\":true,\"hash_ready\":true,"
      "\"baseline_ready\":true,\"patterns_unique\":true,"
      "\"fish_identity_ready\":true,\"snapshot_ready\":true,"
      "\"candidate_sha256\":\"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
      "AAAAAAAAAAAAAAAAAAAAAAAA\","
      "\"baseline_profile_id\":\"majestic-gta5-677e4e35-v1\","
      "\"baseline_profile_revision\":1,\"reason\":\"ready\"}",
      "compatibility_json_contract_changed");
  for (const auto forbidden : {
           "pid", "hwnd", "window_handle", "path", "address", "frame",
           "raw_memory", "distance", "position", "stage", "confidence"}) {
    require(json.find(forbidden) == std::string::npos,
        "fine_or_sensitive_data_leaked");
  }
}

void target_failure_skips_hash_and_validation() {
  fake_port port;
  port.identity = {
      .candidate_sha256 = "C:/sensitive/game/path",
      .baseline_profile_id = "sensitive-address-value",
      .baseline_profile_revision = 99U,
      .reason = probe::readiness_reason::game_process_unavailable,
  };
  const auto result = probe::run(port);
  require(!result.ready &&
      result.reason == probe::readiness_reason::game_process_unavailable,
      "missing_process_not_fail_closed");
  require(port.identity_calls == 1 && port.validation_calls == 0,
      "target_failure_touched_candidate_validation");
  require(result.candidate_sha256.empty() &&
      result.baseline_profile_id.empty() &&
      result.baseline_profile_revision == 0U,
      "failed_identity_leaked_unvalidated_values");
}

void invalid_candidate_identity_skips_memory_validation() {
  fake_port port;
  port.identity.candidate_sha256 = "not-a-sha";
  const auto result = probe::run(port);
  require(!result.ready &&
      result.reason == probe::readiness_reason::candidate_identity_invalid,
      "invalid_candidate_identity_not_rejected");
  require(result.candidate_sha256.empty() &&
      result.baseline_profile_id.empty() &&
      result.baseline_profile_revision == 0U,
      "invalid_candidate_identity_not_sanitized");
  require(port.validation_calls == 0,
      "invalid_candidate_touched_memory_validation");
}

void ambiguous_world_endpoint_is_not_promoted_to_compatibility() {
  fake_port port;
  port.validation = {
      .fish_identity_ready = true,
      .snapshot_ready = true,
      .reason = probe::readiness_reason::world_endpoint_ambiguous,
  };
  const auto result = probe::run(port);
  require(!result.ready && !result.patterns_unique &&
      !result.fish_identity_ready && !result.snapshot_ready &&
      result.reason == probe::readiness_reason::world_endpoint_ambiguous,
      "ambiguous_world_endpoint_not_fail_closed");
}

void active_fish_and_snapshot_are_separate_gates() {
  fake_port port;
  port.validation = {
      .patterns_unique = true,
      .reason = probe::readiness_reason::active_fish_unavailable,
  };
  const auto no_fish = probe::run(port);
  require(!no_fish.ready && no_fish.patterns_unique &&
      !no_fish.fish_identity_ready && !no_fish.snapshot_ready,
      "missing_fish_identity_promoted");

  port.validation = {
      .patterns_unique = true,
      .fish_identity_ready = true,
      .reason = probe::readiness_reason::coherent_snapshot_unavailable,
  };
  const auto no_snapshot = probe::run(port);
  require(!no_snapshot.ready && no_snapshot.patterns_unique &&
      no_snapshot.fish_identity_ready && !no_snapshot.snapshot_ready,
      "missing_snapshot_promoted");
}

}  // namespace

int main() {
  ready_probe_is_one_shot_and_serializes_allowlist();
  target_failure_skips_hash_and_validation();
  invalid_candidate_identity_skips_memory_validation();
    ambiguous_world_endpoint_is_not_promoted_to_compatibility();
  active_fish_and_snapshot_are_separate_gates();
  return 0;
}
