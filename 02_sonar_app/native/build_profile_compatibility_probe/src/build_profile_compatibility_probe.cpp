#include "sonar/fishing/build_profile_compatibility_probe/build_profile_compatibility_probe.h"

#include <algorithm>

namespace sonar::fishing::build_profile_compatibility_probe {
namespace {

[[nodiscard]] bool valid_sha256(const std::string_view value) noexcept {
  return value.size() == 64U &&
      std::ranges::all_of(value, [](const char character) {
        return (character >= '0' && character <= '9') ||
            (character >= 'a' && character <= 'f') ||
            (character >= 'A' && character <= 'F');
      });
}

[[nodiscard]] bool valid_profile_id(const std::string_view value) noexcept {
  return !value.empty() && value.size() <= 96U &&
      std::ranges::all_of(value, [](const char character) {
        return (character >= 'a' && character <= 'z') ||
            (character >= 'A' && character <= 'Z') ||
            (character >= '0' && character <= '9') || character == '-' ||
            character == '_' || character == '.';
      });
}

}  // namespace

probe_result run(compatibility_port& port) noexcept {
  probe_result result;
  try {
    const auto identity = port.inspect_identity();
    result.process_ready = identity.process_ready;
    result.window_ready = identity.window_ready;
    result.hash_ready = identity.hash_ready;
    result.baseline_ready = identity.baseline_ready;
    if (!result.process_ready || !result.window_ready || !result.hash_ready ||
        !result.baseline_ready) {
      result.reason = identity.reason == readiness_reason::ready
          ? readiness_reason::game_build_unavailable
          : identity.reason;
      return result;
    }
    if (!valid_sha256(identity.candidate_sha256) ||
        !valid_profile_id(identity.baseline_profile_id) ||
        identity.baseline_profile_revision == 0U) {
      result.reason = readiness_reason::candidate_identity_invalid;
      return result;
    }
    result.candidate_sha256 = identity.candidate_sha256;
    result.baseline_profile_id = identity.baseline_profile_id;
    result.baseline_profile_revision = identity.baseline_profile_revision;

    const auto validation = port.validate_candidate();
    result.patterns_unique = validation.patterns_unique;
    result.fish_identity_ready = result.patterns_unique &&
        validation.fish_identity_ready;
    result.snapshot_ready = result.fish_identity_ready &&
        validation.snapshot_ready;
    result.reason = validation.reason;
    result.ready = result.patterns_unique && result.fish_identity_ready &&
        result.snapshot_ready && result.reason == readiness_reason::ready;
    if (!result.ready && result.reason == readiness_reason::ready) {
      result.reason = readiness_reason::coherent_snapshot_unavailable;
    }
    return result;
  } catch (...) {
    result.ready = false;
    result.reason = readiness_reason::internal_error;
    return result;
  }
}

std::string_view reason_key(const readiness_reason reason) noexcept {
  switch (reason) {
    case readiness_reason::ready: return "ready";
    case readiness_reason::game_process_unavailable:
      return "game_process_unavailable";
    case readiness_reason::game_window_unavailable:
      return "game_window_unavailable";
    case readiness_reason::game_target_ambiguous:
      return "game_target_ambiguous";
    case readiness_reason::game_window_not_foreground:
      return "game_window_not_foreground";
    case readiness_reason::game_target_changed:
      return "game_target_changed";
    case readiness_reason::game_build_unavailable:
      return "game_build_unavailable";
    case readiness_reason::baseline_profile_unavailable:
      return "baseline_profile_unavailable";
    case readiness_reason::candidate_identity_invalid:
      return "candidate_identity_invalid";
    case readiness_reason::pattern_scan_incomplete:
      return "pattern_scan_incomplete";
    case readiness_reason::pattern_ambiguous:
      return "pattern_ambiguous";
    case readiness_reason::pattern_unresolved:
      return "pattern_unresolved";
    case readiness_reason::active_fish_unavailable:
      return "active_fish_unavailable";
    case readiness_reason::active_fish_ambiguous:
      return "active_fish_ambiguous";
    case readiness_reason::coherent_snapshot_unavailable:
      return "coherent_snapshot_unavailable";
    case readiness_reason::internal_error:
      return "internal_error";
  }
  return "internal_error";
}

std::string serialize_json(const probe_result& result) {
  const auto boolean = [](const bool value) { return value ? "true" : "false"; };
  std::string json;
  json.reserve(512U);
  json += "{\"schema_version\":";
  json += std::to_string(result.schema_version);
  json += ",\"ready\":";
  json += boolean(result.ready);
  json += ",\"process_ready\":";
  json += boolean(result.process_ready);
  json += ",\"window_ready\":";
  json += boolean(result.window_ready);
  json += ",\"hash_ready\":";
  json += boolean(result.hash_ready);
  json += ",\"baseline_ready\":";
  json += boolean(result.baseline_ready);
  json += ",\"patterns_unique\":";
  json += boolean(result.patterns_unique);
  json += ",\"fish_identity_ready\":";
  json += boolean(result.fish_identity_ready);
  json += ",\"snapshot_ready\":";
  json += boolean(result.snapshot_ready);
  json += ",\"candidate_sha256\":\"";
  json += result.candidate_sha256;
  json += "\",\"baseline_profile_id\":\"";
  json += result.baseline_profile_id;
  json += "\",\"baseline_profile_revision\":";
  json += std::to_string(result.baseline_profile_revision);
  json += ",\"reason\":\"";
  json += reason_key(result.reason);
  json += "\"}";
  return json;
}

}  // namespace sonar::fishing::build_profile_compatibility_probe
