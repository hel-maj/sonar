#include "sonar/fishing/game_chat/chat_platform_mutation.h"

#include <limits>
#include <string>
#include <utility>

namespace sonar::fishing::game_chat {
namespace {

[[nodiscard]] runtime_platform::mutation_kind map_kind(
    const chat_intent_kind kind) noexcept {
  using target = runtime_platform::mutation_kind;
  switch (kind) {
    case chat_intent_kind::activate_window: return target::activate_window;
    case chat_intent_kind::release_all_keys: return target::release_all_keys;
    case chat_intent_kind::press_key: return target::press_key;
    case chat_intent_kind::hotkey: return target::hotkey;
    case chat_intent_kind::click_client: return target::click_client_left;
    case chat_intent_kind::set_clipboard_text: return target::set_clipboard_text;
    case chat_intent_kind::pause: return target::pause;
  }
  return target::pause;
}

[[nodiscard]] std::string chat_reason(std::string reason) {
  return reason.empty()
      ? "chat_platform_mutation_failed"
      : "chat_" + std::move(reason);
}

}  // namespace

win32_chat_platform_mutation_sink::win32_chat_platform_mutation_sink(
    sonar::platform::windows::window_client_snapshot expected,
    const std::stop_token stop)
    : sink_(std::move(expected), stop) {}

win32_chat_platform_mutation_sink::win32_chat_platform_mutation_sink(
    sonar::platform::windows::window_client_snapshot expected,
    const std::stop_token stop,
    chat_native_platform_api& api) noexcept
    : sink_(std::move(expected), stop, api) {}

win32_chat_platform_mutation_sink::~win32_chat_platform_mutation_sink() =
    default;

chat_input_result win32_chat_platform_mutation_sink::apply(
    const chat_input_intent& intent) {
  const auto result = sink_.apply({
      .kind = map_kind(intent.kind),
      .primary = intent.primary,
      .secondary = intent.secondary,
      .text = intent.text,
      .point = {.x = intent.point.x, .y = intent.point.y},
      .packet_count = intent.packet_count,
      .delay_milliseconds = intent.delay_milliseconds,
  });
  return result.applied
      ? chat_input_result::accepted()
      : chat_input_result::rejected(chat_reason(result.reason));
}

}  // namespace sonar::fishing::game_chat
