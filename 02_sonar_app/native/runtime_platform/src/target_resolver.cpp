#include "sonar/fishing/runtime_platform/target_resolver.h"

#include <Windows.h>

#include <algorithm>
#include <cwctype>
#include <unordered_set>
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

struct enumeration_context final {
  const std::unordered_set<std::uint32_t>* process_ids{};
  std::vector<target_candidate>* candidates{};
};

BOOL CALLBACK collect_window(const HWND window, const LPARAM parameter) {
  auto* context = reinterpret_cast<enumeration_context*>(parameter);
  if (context == nullptr || context->process_ids == nullptr ||
      context->candidates == nullptr || IsWindowVisible(window) == FALSE) {
    return TRUE;
  }
  DWORD process_id = 0;
  if (GetWindowThreadProcessId(window, &process_id) == 0 || process_id == 0 ||
      context->process_ids->contains(process_id) == false) {
    return TRUE;
  }
  const auto observed = sonar::platform::windows::observe_window_client(
      reinterpret_cast<sonar::platform::windows::native_window_handle>(window));
  if (!observed.ready() || !observed.snapshot.has_value()) {
    return TRUE;
  }
  context->candidates->push_back({L"GTA5.exe", *observed.snapshot});
  return TRUE;
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

target_resolution windows_game_target_resolver::resolve() noexcept {
  try {
    const auto process_ids =
        sonar::platform::windows::readonly_process::find_process_ids(
            L"GTA5.exe");
    if (process_ids.empty()) {
      return {.reason = "game_process_unavailable"};
    }
    const std::unordered_set<std::uint32_t> exact_ids(
        process_ids.begin(), process_ids.end());
    std::vector<target_candidate> candidates;
    enumeration_context context{&exact_ids, &candidates};
    if (EnumWindows(collect_window, reinterpret_cast<LPARAM>(&context)) == FALSE) {
      return {.reason = "game_window_enumeration_failed"};
    }
    return select_exact_game_target(candidates);
  } catch (const sonar::platform::windows::process_error&) {
    return {.reason = "game_process_unavailable"};
  } catch (...) {
    return {.reason = "game_target_resolution_failed"};
  }
}

}  // namespace sonar::fishing::runtime_platform
