#include "sonar/fishing/runtime_platform/target_resolver.h"

#include <algorithm>
#include <cwctype>
#include <utility>

#include "sonar/platform/windows/process.hpp"

namespace sonar::fishing::runtime_platform {
namespace {

[[nodiscard]] bool same_image_name(
    const std::wstring& left,
    const std::wstring_view right) {
  if (left.size() != right.size()) {
    return false;
  }
  return std::equal(
      left.begin(), left.end(), right.begin(),
      [](const wchar_t a, const wchar_t b) {
        return std::towlower(a) == std::towlower(b);
      });
}

}  // namespace

bool target_resolution::ready() const noexcept {
  return target.has_value() && reason.empty();
}

target_resolution select_exact_game_target(
    const std::span<const target_candidate> candidates) noexcept {
  try {
    std::optional<sonar::platform::windows::window_client_snapshot> selected;
    for (const auto& candidate : candidates) {
      if (!same_image_name(candidate.image_name, L"GTA5.exe") ||
          candidate.window.window == 0 ||
          candidate.window.process.process_id == 0 ||
          candidate.window.process.creation_time_filetime_100ns == 0 ||
          candidate.window.width == 0 || candidate.window.height == 0 ||
          !candidate.window.visible || candidate.window.minimized) {
        continue;
      }
      if (selected.has_value() &&
          !selected->same_identity(candidate.window)) {
        return {.reason = "game_target_ambiguous"};
      }
      selected = candidate.window;
    }
    if (!selected.has_value()) {
      return {.reason = "game_target_unavailable"};
    }
    return {.target = std::move(selected)};
  } catch (...) {
    return {.reason = "game_target_selection_failed"};
  }
}

sonar::platform::windows::top_level_window_policy
exact_game_window_policy() noexcept {
  sonar::platform::windows::top_level_window_policy policy;
  policy.maximum_candidates =
      sonar::platform::windows::maximum_top_level_window_candidates;
  policy.require_visible = true;
  policy.require_not_minimized = true;
  // The previous Fishing eligibility contract did not reject an otherwise
  // exact GTA client solely because it was owned or marked as a tool window.
  policy.require_unowned = false;
  policy.exclude_tool_windows = false;
  return policy;
}

target_resolution windows_game_target_resolver::resolve() noexcept {
  try {
    const auto process_ids =
        sonar::platform::windows::readonly_process::find_process_ids(
            L"GTA5.exe");
    if (process_ids.empty()) {
      return {.reason = "game_process_unavailable"};
    }
    std::vector<target_candidate> candidates;
    candidates.reserve(process_ids.size());
    for (const auto process_id : process_ids) {
      try {
        auto process = sonar::platform::windows::readonly_process::open(
            process_id,
            sonar::platform::windows::process_access_profile::identity);
        const auto generation = process.generation();
        auto image_name = process.image_name();
        if (!same_image_name(image_name, L"GTA5.exe")) {
          continue;
        }

        sonar::platform::windows::unique_top_level_client_observer observer(
            generation,
            exact_game_window_policy());
        const auto observed = observer.observe();
        if (observed.ready() && observed.snapshot.has_value()) {
          candidates.push_back({std::move(image_name), *observed.snapshot});
          continue;
        }

        using reason =
            sonar::platform::windows::unique_window_observation_reason;
        switch (observed.reason) {
          case reason::ambiguous:
            return {.reason = "game_target_ambiguous"};
          case reason::invalid_policy:
          case reason::resource_limit:
          case reason::system_failure:
            return {.reason = "game_window_enumeration_failed"};
          case reason::ready:
            return {.reason = "game_target_resolution_failed"};
          case reason::missing:
          case reason::process_unavailable:
          case reason::process_changed:
          case reason::owner_changed:
          case reason::not_visible:
          case reason::minimized:
          case reason::client_empty:
            break;
        }
      } catch (const sonar::platform::windows::process_error&) {
        // A PID may disappear or become inaccessible after exact-name
        // enumeration. Preserve the prior behavior by ignoring that stale
        // candidate while evaluating the remaining exact processes.
      }
    }
    return select_exact_game_target(candidates);
  } catch (const sonar::platform::windows::process_error&) {
    return {.reason = "game_process_unavailable"};
  } catch (...) {
    return {.reason = "game_target_resolution_failed"};
  }
}

}  // namespace sonar::fishing::runtime_platform
