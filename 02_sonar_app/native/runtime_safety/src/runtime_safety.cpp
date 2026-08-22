#include "sonar/fishing/runtime_safety/runtime_safety.h"

#include <utility>

namespace sonar::fishing::runtime_safety {
namespace {

[[nodiscard]] action_reason map_window_reason(
    const sonar::platform::windows::window_observation_reason reason) noexcept {
  using common_reason = sonar::platform::windows::window_observation_reason;
  switch (reason) {
    case common_reason::not_foreground:
      return action_reason::window_not_foreground;
    case common_reason::identity_changed:
    case common_reason::geometry_changed:
    case common_reason::owner_changed:
    case common_reason::process_generation_changed:
      return action_reason::window_changed;
    default:
      return action_reason::window_unavailable;
  }
}

}  // namespace

action_reason validate_product_prerequisites(
    const action_request& request) noexcept {
  if (!request.entitlement_valid) {
    return action_reason::entitlement_invalid;
  }
  if (!request.settings_current) {
    return action_reason::settings_not_current;
  }
  if (!request.lifecycle_allows_input) {
    return action_reason::lifecycle_not_actionable;
  }
  if (request.packet_count == 0) {
    return action_reason::invalid_packet_count;
  }
  return action_reason::ready;
}

action_reason reserve_packet_budget(
    sonar::platform::input::input_packet_budget& budget,
    const std::size_t packet_count) noexcept {
  if (packet_count == 0) {
    return action_reason::invalid_packet_count;
  }
  return budget.try_reserve(packet_count)
      ? action_reason::ready
      : action_reason::packet_budget_exhausted;
}

runtime_target_guard::runtime_target_guard(
    sonar::platform::windows::readonly_process process,
    const sonar::platform::windows::process_generation generation,
    sonar::platform::windows::window_client_snapshot window,
    const std::size_t maximum_packets)
    : process_(std::move(process)),
      generation_(generation),
      window_(std::move(window)),
      packet_budget_(maximum_packets) {}

std::unique_ptr<runtime_target_guard> runtime_target_guard::attach(
    const std::uint32_t process_id,
    const sonar::platform::windows::native_window_handle window,
    const std::size_t maximum_packets,
    attach_reason& reason) noexcept {
  if (process_id == 0 || window == 0 || maximum_packets == 0) {
    reason = attach_reason::invalid_argument;
    return nullptr;
  }
  try {
    auto process = sonar::platform::windows::readonly_process::open(
        process_id,
        sonar::platform::windows::process_access_profile::memory);
    const auto generation = process.generation();
    const auto observation = sonar::platform::windows::observe_window_client(window);
    if (!observation.ready() || !observation.snapshot.has_value()) {
      reason = attach_reason::window_unavailable;
      return nullptr;
    }
    if (observation.snapshot->process != generation) {
      reason = attach_reason::window_owner_changed;
      return nullptr;
    }
    reason = attach_reason::ready;
    return std::unique_ptr<runtime_target_guard>(new runtime_target_guard(
        std::move(process),
        generation,
        *observation.snapshot,
        maximum_packets));
  } catch (const sonar::platform::windows::process_error&) {
    reason = attach_reason::process_unavailable;
    return nullptr;
  } catch (...) {
    reason = attach_reason::process_unavailable;
    return nullptr;
  }
}

action_reason runtime_target_guard::preflight(
    const action_request& request) noexcept {
  const auto prerequisite = validate_product_prerequisites(request);
  if (prerequisite != action_reason::ready) {
    return prerequisite;
  }
  const auto target = preflight_target_identity(request.foreground_required);
  if (target != action_reason::ready) {
    return target;
  }
  return reserve_packet_budget(packet_budget_, request.packet_count);
}

action_reason runtime_target_guard::preflight_target_identity(
    const bool foreground_required) noexcept {
  try {
    if (!process_.is_alive()) {
      return action_reason::process_unavailable;
    }
    if (!process_.generation_matches(generation_)) {
      return action_reason::process_changed;
    }
  } catch (const sonar::platform::windows::process_error&) {
    return action_reason::process_unavailable;
  } catch (...) {
    return action_reason::process_unavailable;
  }

  const auto window = foreground_required
      ? sonar::platform::windows::validate_foreground_window(window_)
      : sonar::platform::windows::observe_window_client(window_.window);
  if (!window.ready()) {
    return map_window_reason(window.reason);
  }
  if (!window.snapshot.has_value() ||
      !window.snapshot->same_identity(window_) ||
      !window.snapshot->same_geometry(window_)) {
    return action_reason::window_changed;
  }
  return action_reason::ready;
}

action_reason runtime_target_guard::preflight_cleanup(
    const std::size_t packet_count) noexcept {
  if (packet_count == 0) {
    return action_reason::invalid_packet_count;
  }
  const auto target = preflight_target_identity(false);
  if (target != action_reason::ready) {
    return target;
  }
  return reserve_packet_budget(packet_budget_, packet_count);
}

std::size_t runtime_target_guard::remaining_packets() const noexcept {
  return packet_budget_.remaining_packets();
}

}  // namespace sonar::fishing::runtime_safety
