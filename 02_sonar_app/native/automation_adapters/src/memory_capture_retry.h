#pragma once

#include <cstddef>
#include <cstdint>
#include <utility>

#include "sonar/fishing/automation_adapters/fishing_adapters.h"

namespace sonar::fishing::automation_adapters::detail {

// Keep the retry policy in one adapter-owned operation so production and its
// regression exercise the same commit/reset sequence. Resolver and observer
// remain injected only at this private boundary.
template <typename Resolver, typename Observer>
[[nodiscard]] memory_snapshot_result capture_reeling_with_bounded_retry(
    Resolver& resolver,
    Observer& observer,
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns,
    const sonar::platform::windows::process_generation& game_generation)
    noexcept {
  for (std::size_t attempt = 0U; attempt < 2U; ++attempt) {
    auto resolved = resolver.resolve_reeling(
        sequence, captured_at_steady_ns, game_generation);
    if (!resolved.ready()) {
      if (resolver.terminal_transition_pending()) {
        resolver.reset();
      }
      return {.reason = resolved.reason.empty()
          ? "production_memory_profile_unavailable"
          : std::move(resolved.reason)};
    }
    auto captured = observer.capture(*resolved.profile, *resolved.plan);
    if (captured.ready()) {
      resolver.commit_capture(*captured.snapshot);
      return {.snapshot = std::move(captured.snapshot)};
    }
    const bool invalidates_session =
        captured.failure == memory_observation::capture_failure::read_failed ||
        captured.failure ==
            memory_observation::capture_failure::process_changed ||
        captured.failure ==
            memory_observation::capture_failure::decode_failed;
    if (invalidates_session) {
      observer.reset_sessions();
    }
    const bool retryable = attempt == 0U &&
        invalidates_session;
    if (!retryable) {
      if (resolver.terminal_transition_pending()) {
        resolver.reset();
      }
      return {.reason = captured.reason.empty()
          ? "production_memory_capture_unavailable"
          : std::move(captured.reason)};
    }
    // One bounded retry discards stale discovery and observer session state.
    // A pending confirmed terminal transition survives only read/decode drift
    // and only until this operation either commits a coherent snapshot or
    // resets.
    if (captured.failure ==
        memory_observation::capture_failure::process_changed) {
      resolver.reset();
    } else {
      resolver.prepare_capture_retry();
    }
  }
  resolver.reset();
  return {.reason = "production_memory_capture_unavailable"};
}

}  // namespace sonar::fishing::automation_adapters::detail
