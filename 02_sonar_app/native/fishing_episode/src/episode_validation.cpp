#include "episode_validation.h"

#include <cmath>
#include <cstddef>
#include <string_view>

namespace sonar::fishing::fishing_episode::detail {
namespace {

constexpr std::size_t kMaximumErrorBytes = 512U;
constexpr std::size_t kMaximumProfileIdBytes = 128U;
constexpr std::size_t kMaximumTriggerIdBytes = 32U;

[[nodiscard]] bool bounded_text(
    const std::string_view value,
    const std::size_t maximum,
    const bool allow_empty = false) noexcept {
  return (allow_empty || !value.empty()) && value.size() <= maximum &&
      value.find('\0') == std::string_view::npos;
}

[[nodiscard]] bool valid_confidence(const double value) noexcept {
  return std::isfinite(value) && value >= 0.0 && value <= 1.0;
}

[[nodiscard]] bool valid_rect(
    const stage_detection::normalized_rect& rect) noexcept {
  return std::isfinite(rect.x) && std::isfinite(rect.y) &&
      std::isfinite(rect.width) && std::isfinite(rect.height) &&
      rect.x >= 0.0 && rect.y >= 0.0 && rect.width > 0.0 &&
      rect.height > 0.0 && rect.x + rect.width <= 1.0 &&
      rect.y + rect.height <= 1.0;
}

[[nodiscard]] bool trigger_matches_stage(
    const stage_detection::stage_observation& observation) noexcept {
  using stage_detection::observed_fishing_stage;
  switch (observation.stage) {
    case observed_fishing_stage::tackle_selection:
      return observation.trigger_id == "start";
    case observed_fishing_stage::casting:
      return observation.trigger_id == "start1";
    case observed_fishing_stage::waiting_for_bite:
      return observation.trigger_id == "start2" ||
          observation.trigger_id == "wait_tension";
    case observed_fishing_stage::reeling:
      return observation.trigger_id == "ad";
    case observed_fishing_stage::none:
      return false;
  }
  return false;
}

[[nodiscard]] bool finite_reeling(
    const memory_observation::reeling_evidence& value) noexcept {
  return std::isfinite(value.player_position.x) &&
      std::isfinite(value.player_position.y) &&
      std::isfinite(value.player_position.z) &&
      std::isfinite(value.fish_position.x) &&
      std::isfinite(value.fish_position.y) &&
      std::isfinite(value.fish_position.z) &&
      std::isfinite(value.player_right_x) &&
      std::isfinite(value.player_right_y) && std::isfinite(value.distance) &&
      value.distance >= 0.0;
}

[[nodiscard]] bool valid_duration(const std::uint64_t value) noexcept {
  return value > 0U && value <= maximum_episode_duration_ns;
}

}  // namespace

std::uint64_t elapsed_ns(
    const std::uint64_t now,
    const std::uint64_t started) noexcept {
  return now >= started ? now - started : 0U;
}

stage_detection::observed_fishing_stage observed_stage(
    const fishing_episode_observation& observation) noexcept {
  return observation.stage.has_value()
      ? observation.stage->stage
      : stage_detection::observed_fishing_stage::none;
}

bool memory_reports_finished(
    const fishing_episode_observation& observation) noexcept {
  return observation.memory.has_value() &&
      observation.memory->reeling.has_value() &&
      !observation.memory->reeling->active;
}

bool valid_request(
    const fishing_episode_request& request,
    std::string& reason) noexcept {
  if (!request.automation_enabled) {
    reason = "fishing_automation_disabled";
    return false;
  }
  if (request.accepted_settings_revision == 0U ||
      request.expected_entitlement_revision == 0U ||
      request.expected_lifecycle_revision == 0U ||
      request.episode_identity == 0U) {
    reason = "fishing_authority_revision_invalid";
    return false;
  }
  if (request.maximum_observations == 0U ||
      request.maximum_observations > maximum_episode_observations) {
    reason = "fishing_observation_budget_invalid";
    return false;
  }
  if (!valid_duration(request.casting_timeout_ns) ||
      !valid_duration(request.casting_confirmation_timeout_ns) ||
      !valid_duration(request.hooking_timeout_ns) ||
      !valid_duration(request.hooking_confirmation_timeout_ns) ||
      !valid_duration(request.reeling_timeout_ns) ||
      !valid_duration(request.episode_timeout_ns)) {
    reason = "fishing_timeout_invalid";
    return false;
  }
  return true;
}

bool observation_validator::validate(
    const fishing_episode_observation& observation,
    std::string& reason) {
  if (!observation.error.empty()) {
    reason = bounded_text(observation.error, kMaximumErrorBytes)
        ? "fishing_observation_unavailable:" + observation.error
        : "fishing_observation_error_invalid";
    return false;
  }
  if (observation.sequence == 0U || observation.sequence <= last_sequence_) {
    reason = "fishing_observation_stale";
    return false;
  }
  if (observation.captured_at_steady_ns == 0U ||
      observation.captured_at_steady_ns <= last_captured_at_) {
    reason = "fishing_observation_time_invalid";
    return false;
  }
  if (!valid_confidence(observation.cast_confidence) ||
      !valid_confidence(observation.hook_confidence)) {
    reason = "fishing_cue_confidence_invalid";
    return false;
  }
  if (observation.cast_ready != (observation.cast_confidence > 0.0) ||
      (observation.hook == hook_cue::none) !=
          (observation.hook_confidence == 0.0)) {
    reason = "fishing_cue_state_ambiguous";
    return false;
  }
  if (observation.hook != hook_cue::none &&
      observation.hook != hook_cue::red &&
      observation.hook != hook_cue::bubbles) {
    reason = "fishing_hook_cue_invalid";
    return false;
  }

  const auto stage = observed_stage(observation);
  if (observation.stage.has_value()) {
    if (!bounded_text(
            observation.stage->trigger_id, kMaximumTriggerIdBytes) ||
        !valid_confidence(observation.stage->confidence) ||
        observation.stage->confidence <= 0.0 ||
        !valid_rect(observation.stage->bounds) ||
        !trigger_matches_stage(*observation.stage)) {
      reason = "fishing_stage_observation_invalid";
      return false;
    }
  }
  if (observation.cast_ready &&
      stage != stage_detection::observed_fishing_stage::casting) {
    reason = "fishing_cast_cue_stage_mismatch";
    return false;
  }
  if (observation.hook != hook_cue::none &&
      stage != stage_detection::observed_fishing_stage::waiting_for_bite) {
    reason = "fishing_hook_cue_stage_mismatch";
    return false;
  }

  if (observation.memory.has_value()) {
    const auto& memory = *observation.memory;
    if (memory.sequence != observation.sequence ||
        memory.captured_at_steady_ns != observation.captured_at_steady_ns ||
        !bounded_text(memory.profile_id, kMaximumProfileIdBytes) ||
        memory.profile_revision == 0U || !memory.reeling.has_value() ||
        memory.game_generation.process_id == 0U ||
        memory.game_generation.creation_time_filetime_100ns == 0U ||
        !finite_reeling(*memory.reeling) ||
        !memory.reeling->fish_model_confirmed) {
      reason = "fishing_memory_observation_invalid";
      return false;
    }
    if (memory.webengine_generation.has_value() &&
        (memory.webengine_generation->process_id == 0U ||
         memory.webengine_generation->creation_time_filetime_100ns == 0U)) {
      reason = "fishing_memory_observation_invalid";
      return false;
    }
    if (!memory_profile_id_.has_value()) {
      memory_profile_id_ = memory.profile_id;
      memory_profile_revision_ = memory.profile_revision;
      memory_game_generation_ = memory.game_generation;
      memory_webengine_generation_ = memory.webengine_generation;
    } else if (*memory_profile_id_ != memory.profile_id ||
               memory_profile_revision_ != memory.profile_revision) {
      reason = "fishing_memory_profile_drift";
      return false;
    } else if (memory_game_generation_ != memory.game_generation ||
               memory_webengine_generation_ != memory.webengine_generation) {
      reason = "fishing_memory_target_drift";
      return false;
    }
  }
  if (stage == stage_detection::observed_fishing_stage::reeling &&
      !observation.memory.has_value()) {
    reason = "fishing_reeling_memory_missing";
    return false;
  }

  last_sequence_ = observation.sequence;
  last_captured_at_ = observation.captured_at_steady_ns;
  return true;
}

std::uint64_t observation_validator::last_sequence() const noexcept {
  return last_sequence_;
}

}  // namespace sonar::fishing::fishing_episode::detail
