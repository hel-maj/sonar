#include "sonar/fishing/live_observation_preflight/live_observation_preflight.h"

namespace sonar::fishing::live_observation_preflight {
namespace {

[[nodiscard]] bool is_success(const readiness_reason reason) noexcept {
  return reason == readiness_reason::ready;
}

[[nodiscard]] readiness_reason first_failure(
    const target_probe& target,
    const build_probe& build,
    const observation_probe& capture,
    const observation_probe& memory) noexcept {
  if (!target.process_ready || !target.window_ready) {
    return is_success(target.reason)
        ? readiness_reason::game_window_unavailable
        : target.reason;
  }
  if (!build.build_ready || !build.profile_ready) {
    return is_success(build.reason)
        ? readiness_reason::game_build_unavailable
        : build.reason;
  }
  if (!capture.ready) {
    return is_success(capture.reason)
        ? readiness_reason::capture_unavailable
        : capture.reason;
  }
  if (!memory.ready) {
    return is_success(memory.reason)
        ? readiness_reason::memory_unavailable
        : memory.reason;
  }
  return readiness_reason::ready;
}

}  // namespace

preflight_result run(observation_port& port) noexcept {
  preflight_result result;
  try {
    const auto target = port.resolve_target();
    result.process_ready = target.process_ready;
    result.window_ready = target.window_ready;
    if (!target.process_ready || !target.window_ready) {
      result.reason = first_failure(target, {}, {}, {});
      return result;
    }
    if (target.width == 0U || target.height == 0U ||
        static_cast<std::uint64_t>(target.width) * target.height >
            maximum_capture_pixels) {
      result.reason = readiness_reason::capture_geometry_unsupported;
      return result;
    }

    const auto build = port.inspect_build();
    result.build_ready = build.build_ready;
    result.profile_ready = build.profile_ready;

    const auto capture = port.capture_and_detect();
    result.capture_ready = capture.ready;

    observation_probe memory{
        .ready = false,
        .reason = readiness_reason::game_build_unsupported,
    };
    if (build.build_ready && build.profile_ready && capture.ready) {
      memory = port.capture_memory();
    }
    result.memory_ready = memory.ready;
    result.reason = first_failure(target, build, capture, memory);
    result.ready = is_success(result.reason) && result.process_ready &&
        result.window_ready && result.build_ready && result.profile_ready &&
        result.capture_ready && result.memory_ready;
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
    case readiness_reason::capture_geometry_unsupported:
      return "capture_geometry_unsupported";
    case readiness_reason::game_build_unavailable:
      return "game_build_unavailable";
    case readiness_reason::game_build_unsupported:
      return "game_build_unsupported";
    case readiness_reason::capture_unavailable:
      return "capture_unavailable";
    case readiness_reason::detector_unavailable:
      return "detector_unavailable";
    case readiness_reason::memory_unavailable:
      return "memory_unavailable";
    case readiness_reason::internal_error:
      return "internal_error";
  }
  return "internal_error";
}

std::string serialize_json(const preflight_result& result) {
  const auto boolean = [](const bool value) { return value ? "true" : "false"; };
  std::string json;
  json.reserve(256U);
  json += "{\"schema_version\":";
  json += std::to_string(result.schema_version);
  json += ",\"ready\":";
  json += boolean(result.ready);
  json += ",\"process_ready\":";
  json += boolean(result.process_ready);
  json += ",\"window_ready\":";
  json += boolean(result.window_ready);
  json += ",\"build_ready\":";
  json += boolean(result.build_ready);
  json += ",\"profile_ready\":";
  json += boolean(result.profile_ready);
  json += ",\"capture_ready\":";
  json += boolean(result.capture_ready);
  json += ",\"memory_ready\":";
  json += boolean(result.memory_ready);
  json += ",\"reason\":\"";
  json += reason_key(result.reason);
  json += "\"}";
  return json;
}

}  // namespace sonar::fishing::live_observation_preflight
