#include "sonar/fishing/game_chat/chat_observation.h"

#include <algorithm>
#include <exception>
#include <limits>
#include <string_view>
#include <unordered_set>
#include <utility>

namespace sonar::fishing::game_chat {
namespace {

constexpr std::size_t kMaximumTabs = 16;
constexpr std::size_t kMaximumTabTextBytes = 256;

[[nodiscard]] chat_observation unavailable(std::string reason) {
  return {.error = std::move(reason)};
}

[[nodiscard]] bool bounded_tab_text(const std::string_view value) noexcept {
  return !value.empty() && value.size() <= kMaximumTabTextBytes &&
      value.find('\0') == std::string_view::npos;
}

[[nodiscard]] normalized_rect normalize(
    const pixel_rect& bounds,
    const chat_frame& frame) noexcept {
  const auto width = static_cast<double>(frame.width);
  const auto height = static_cast<double>(frame.height);
  return {
      .x = static_cast<double>(bounds.x) / width,
      .y = static_cast<double>(bounds.y) / height,
      .width = static_cast<double>(bounds.width) / width,
      .height = static_cast<double>(bounds.height) / height,
  };
}

}  // namespace

bool chat_frame::valid() const noexcept {
  if (width == 0 || height == 0 || sequence == 0 ||
      width > std::numeric_limits<std::size_t>::max() / 3) {
    return false;
  }
  const auto minimum_stride = static_cast<std::size_t>(width) * 3;
  if (stride_bytes < minimum_stride ||
      stride_bytes > std::numeric_limits<std::size_t>::max() / height) {
    return false;
  }
  return bgr24.size() == stride_bytes * static_cast<std::size_t>(height);
}

chat_capture_result chat_capture_result::captured(chat_frame frame) {
  return {.frame = std::move(frame)};
}

chat_capture_result chat_capture_result::unavailable(std::string reason) {
  return {.reason = std::move(reason)};
}

bool pixel_rect::valid_for(const chat_frame& frame) const noexcept {
  return frame.valid() && width > 0 && height > 0 &&
      x < frame.width && y < frame.height &&
      width <= frame.width - x && height <= frame.height - y;
}

capture_chat_observer::capture_chat_observer(
    chat_capture_source& capture,
    chat_frame_detector& detector) noexcept
    : capture_(capture), detector_(detector) {}

chat_observation capture_chat_observer::observe() {
  chat_capture_result captured;
  try {
    captured = capture_.capture();
  } catch (const std::exception& error) {
    return unavailable(std::string("chat_capture_failed:") + error.what());
  } catch (...) {
    return unavailable("chat_capture_failed:unknown");
  }
  if (!captured.frame.has_value()) {
    return unavailable(captured.reason.empty()
        ? "chat_capture_unavailable"
        : "chat_capture_unavailable:" + captured.reason);
  }
  const auto& frame = *captured.frame;
  if (!frame.valid()) {
    return unavailable("chat_capture_invalid");
  }
  if (frame.sequence <= last_sequence_) {
    return unavailable("chat_capture_replayed");
  }
  last_sequence_ = frame.sequence;

  pixel_chat_detection detection;
  try {
    detection = detector_.detect(frame);
  } catch (const std::exception& error) {
    return unavailable(std::string("chat_detector_failed:") + error.what());
  } catch (...) {
    return unavailable("chat_detector_failed:unknown");
  }
  if (!detection.error.empty()) {
    return unavailable("chat_detector_unavailable:" + detection.error);
  }
  if (detection.tabs.size() > kMaximumTabs) {
    return unavailable("chat_detector_tabs_overflow");
  }
  if (detection.active && !detection.input_bounds.has_value()) {
    return unavailable("chat_detector_active_without_input");
  }

  chat_observation result;
  result.active = detection.active;
  result.selected_tab_id = detection.selected_tab_id;
  std::unordered_set<std::string> ids;
  std::size_t selected_count = 0;
  for (const auto& tab : detection.tabs) {
    if (!bounded_tab_text(tab.id) || !bounded_tab_text(tab.name) ||
        !tab.bounds.valid_for(frame) || !ids.emplace(tab.id).second) {
      return unavailable("chat_detector_tab_invalid");
    }
    if (tab.selected) {
      ++selected_count;
      if (!detection.selected_tab_id.empty() &&
          detection.selected_tab_id != tab.id) {
        return unavailable("chat_detector_selection_inconsistent");
      }
    }
    result.tabs.push_back({
        .id = tab.id,
        .name = tab.name,
        .selected = tab.selected,
        .bounds = normalize(tab.bounds, frame),
    });
  }
  if (selected_count > 1 ||
      (selected_count == 0 && !detection.selected_tab_id.empty()) ||
      (selected_count == 1 && detection.selected_tab_id.empty())) {
    return unavailable("chat_detector_selection_inconsistent");
  }
  if (detection.input_bounds.has_value()) {
    if (!detection.input_bounds->valid_for(frame)) {
      return unavailable("chat_detector_input_invalid");
    }
    result.input_bounds = normalize(*detection.input_bounds, frame);
  }
  return result;
}

chat_capture_result disabled_chat_capture_source::capture() {
  return chat_capture_result::unavailable("chat_live_capture_disabled");
}

pixel_chat_detection disabled_chat_frame_detector::detect(
    const chat_frame& frame) {
  static_cast<void>(frame);
  return {.error = "chat_live_detector_disabled"};
}

}  // namespace sonar::fishing::game_chat
