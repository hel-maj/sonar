#include "sonar/fishing/game_chat/chat_observation.h"

#include <utility>

namespace sonar::fishing::game_chat {

win32_chat_capture_source::win32_chat_capture_source(
    sonar::platform::windows::window_client_snapshot expected) noexcept
    : capture_(std::move(expected)) {}

chat_capture_result win32_chat_capture_source::capture() {
  auto result = capture_.capture();
  if (!result.frame.has_value()) {
    return chat_capture_result::unavailable(
        result.reason.empty()
            ? "chat_capture_unavailable"
            : "chat_" + std::move(result.reason));
  }
  auto frame = std::move(*result.frame);
  return chat_capture_result::captured({
      .width = frame.width,
      .height = frame.height,
      .stride_bytes = frame.stride_bytes,
      .sequence = frame.sequence,
      .bgr24 = std::move(frame.bgr24),
  });
}

}  // namespace sonar::fishing::game_chat
