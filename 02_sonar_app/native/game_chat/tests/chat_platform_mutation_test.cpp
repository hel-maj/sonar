#include "sonar/fishing/game_chat/chat_platform_mutation.h"

#include <chrono>
#include <cstdint>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <stop_token>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

namespace {

namespace chat = sonar::fishing::game_chat;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

class recording_native_api final : public chat::chat_native_platform_api {
 public:
  [[nodiscard]] bool activate_window(
      const sonar::platform::windows::native_window_handle window)
      noexcept override {
    ++activate_calls;
    activated_window = window;
    return activation_succeeds;
  }

  [[nodiscard]] bool set_cursor_position(
      const std::int32_t x,
      const std::int32_t y) noexcept override {
    cursor_positions.emplace_back(x, y);
    return cursor_succeeds;
  }

  [[nodiscard]] std::size_t send_input(
      const std::span<const chat::native_input_packet> packets)
      noexcept override {
    batches.emplace_back(packets.begin(), packets.end());
    if (send_results.empty()) {
      return packets.size();
    }
    const std::size_t result = send_results.front();
    send_results.pop_front();
    return result;
  }

  [[nodiscard]] bool set_clipboard_text(
      const std::wstring_view text) noexcept override {
    ++clipboard_calls;
    clipboard.assign(text);
    return clipboard_succeeds;
  }

  bool activation_succeeds{true};
  bool cursor_succeeds{true};
  bool clipboard_succeeds{true};
  std::size_t activate_calls{};
  std::size_t clipboard_calls{};
  sonar::platform::windows::native_window_handle activated_window{};
  std::vector<std::pair<std::int32_t, std::int32_t>> cursor_positions;
  std::vector<std::vector<chat::native_input_packet>> batches;
  std::deque<std::size_t> send_results;
  std::wstring clipboard;
};

[[nodiscard]] sonar::platform::windows::window_client_snapshot target() {
  return {
      .window = 0x1234,
      .screen_left = -50,
      .screen_top = 20,
      .width = 200,
      .height = 100,
      .dpi = 144,
      .visible = true,
  };
}

[[nodiscard]] chat::chat_input_intent intent(
    const chat::chat_intent_kind kind) {
  std::size_t packet_count{};
  switch (kind) {
    case chat::chat_intent_kind::activate_window:
      packet_count = 1;
      break;
    case chat::chat_intent_kind::release_all_keys:
      packet_count = 9;
      break;
    case chat::chat_intent_kind::press_key:
      packet_count = 2;
      break;
    case chat::chat_intent_kind::hotkey:
      packet_count = 4;
      break;
    case chat::chat_intent_kind::click_client:
      packet_count = 3;
      break;
    case chat::chat_intent_kind::set_clipboard_text:
      packet_count = 1;
      break;
    case chat::chat_intent_kind::pause:
      packet_count = 0;
      break;
  }
  return {.kind = kind, .packet_count = packet_count};
}

void every_supported_mutation_has_exact_bounded_shape() {
  recording_native_api api;
  chat::win32_chat_platform_mutation_sink sink(target(), {}, api);

  require(
      sink.apply(intent(chat::chat_intent_kind::activate_window)).applied,
      "window_activation_rejected");
  require(
      api.activate_calls == 1 && api.activated_window == target().window,
      "window_activation_target_changed");

  require(
      sink.apply(intent(chat::chat_intent_kind::release_all_keys)).applied,
      "release_keys_rejected");
  require(api.batches.size() == 1 && api.batches[0].size() == 9,
      "release_packet_count_changed");
  for (const auto& packet : api.batches[0]) {
    require(
        packet.kind == chat::native_input_packet_kind::key_up &&
            packet.scan_code != 0,
        "release_packet_not_key_up");
  }

  auto press = intent(chat::chat_intent_kind::press_key);
  press.primary = " T ";
  require(sink.apply(press).applied, "press_rejected");
  require(
      api.batches[1] == std::vector<chat::native_input_packet>({
          {chat::native_input_packet_kind::key_down, 0x14},
          {chat::native_input_packet_kind::key_up, 0x14},
      }),
      "press_pulse_changed");

  auto hotkey = intent(chat::chat_intent_kind::hotkey);
  hotkey.primary = "ctrl";
  hotkey.secondary = "v";
  require(sink.apply(hotkey).applied, "hotkey_rejected");
  require(
      api.batches[2] == std::vector<chat::native_input_packet>({
          {chat::native_input_packet_kind::key_down, 0x1D},
          {chat::native_input_packet_kind::key_down, 0x2F},
          {chat::native_input_packet_kind::key_up, 0x2F},
          {chat::native_input_packet_kind::key_up, 0x1D},
      }),
      "hotkey_pulse_changed");

  auto click = intent(chat::chat_intent_kind::click_client);
  click.point = {.x = 0.5, .y = 0.5};
  require(sink.apply(click).applied, "click_rejected");
  require(
      api.cursor_positions ==
          std::vector<std::pair<std::int32_t, std::int32_t>>({{50, 70}}),
      "normalized_client_point_changed");
  require(
      api.batches[3] == std::vector<chat::native_input_packet>({
          {chat::native_input_packet_kind::left_button_down, 0},
          {chat::native_input_packet_kind::left_button_up, 0},
      }),
      "click_pulse_changed");

  auto clipboard = intent(chat::chat_intent_kind::set_clipboard_text);
  clipboard.text = "привет";
  require(sink.apply(clipboard).applied, "unicode_clipboard_rejected");
  require(
      api.clipboard_calls == 1 && api.clipboard == L"привет",
      "clipboard_utf16_changed");

  auto pause = intent(chat::chat_intent_kind::pause);
  pause.delay_milliseconds = 1;
  require(sink.apply(pause).applied, "bounded_pause_rejected");
}

void partial_input_prefix_gets_only_required_release_cleanup() {
  recording_native_api press_api;
  press_api.send_results = {1, 1};
  chat::win32_chat_platform_mutation_sink press_sink(target(), {}, press_api);
  auto press = intent(chat::chat_intent_kind::press_key);
  press.primary = "enter";
  const auto press_result = press_sink.apply(press);
  require(
      !press_result.applied &&
          press_result.reason == "chat_send_input_incomplete",
      "partial_press_reason_changed");
  require(
      press_api.batches.size() == 2 &&
          press_api.batches[1] == std::vector<chat::native_input_packet>({
              {chat::native_input_packet_kind::key_up, 0x1C},
          }),
      "partial_press_cleanup_changed");

  recording_native_api hotkey_api;
  hotkey_api.send_results = {2, 2};
  chat::win32_chat_platform_mutation_sink hotkey_sink(target(), {}, hotkey_api);
  auto hotkey = intent(chat::chat_intent_kind::hotkey);
  hotkey.primary = "ctrl";
  hotkey.secondary = "v";
  const auto hotkey_result = hotkey_sink.apply(hotkey);
  require(!hotkey_result.applied, "partial_hotkey_accepted");
  require(
      hotkey_api.batches.size() == 2 &&
          hotkey_api.batches[1] == std::vector<chat::native_input_packet>({
              {chat::native_input_packet_kind::key_up, 0x2F},
              {chat::native_input_packet_kind::key_up, 0x1D},
          }),
      "partial_hotkey_cleanup_changed");

  recording_native_api click_api;
  click_api.send_results = {1, 1};
  chat::win32_chat_platform_mutation_sink click_sink(target(), {}, click_api);
  auto click = intent(chat::chat_intent_kind::click_client);
  click.point = {.x = 0.25, .y = 0.75};
  const auto click_result = click_sink.apply(click);
  require(!click_result.applied, "partial_click_accepted");
  require(
      click_api.batches.size() == 2 &&
          click_api.batches[1] == std::vector<chat::native_input_packet>({
              {chat::native_input_packet_kind::left_button_up, 0},
          }),
      "partial_click_cleanup_changed");

  recording_native_api failed_cleanup_api;
  failed_cleanup_api.send_results = {1, 0};
  chat::win32_chat_platform_mutation_sink failed_cleanup_sink(
      target(), {}, failed_cleanup_api);
  const auto cleanup_result = failed_cleanup_sink.apply(press);
  require(
      !cleanup_result.applied &&
          cleanup_result.reason == "chat_send_input_cleanup_failed",
      "cleanup_failure_not_fail_closed");
}

void invalid_or_cancelled_mutation_never_reaches_native_api() {
  recording_native_api api;
  chat::win32_chat_platform_mutation_sink sink(target(), {}, api);

  auto blocked = intent(chat::chat_intent_kind::press_key);
  blocked.primary = "w";
  require(
      sink.apply(blocked).reason == "chat_key_unsupported",
      "blocked_key_accepted");

  auto invalid_hotkey = intent(chat::chat_intent_kind::hotkey);
  invalid_hotkey.primary = "ctrl";
  invalid_hotkey.secondary = "control";
  require(
      sink.apply(invalid_hotkey).reason == "chat_hotkey_unsupported",
      "duplicate_hotkey_accepted");

  auto invalid_click = intent(chat::chat_intent_kind::click_client);
  invalid_click.point = {.x = 1.01, .y = 0.5};
  require(
      sink.apply(invalid_click).reason == "chat_click_target_invalid",
      "invalid_click_accepted");

  auto invalid_text = intent(chat::chat_intent_kind::set_clipboard_text);
  invalid_text.text = std::string("\xC3\x28", 2);
  require(
      sink.apply(invalid_text).reason == "chat_clipboard_text_invalid",
      "invalid_utf8_accepted");

  auto invalid_pause = intent(chat::chat_intent_kind::pause);
  invalid_pause.delay_milliseconds = 0;
  require(
      sink.apply(invalid_pause).reason == "chat_pause_invalid",
      "zero_pause_accepted");

  auto under_budgeted = intent(chat::chat_intent_kind::hotkey);
  under_budgeted.primary = "ctrl";
  under_budgeted.secondary = "v";
  under_budgeted.packet_count = 1;
  require(
      sink.apply(under_budgeted).reason ==
          "chat_platform_packet_count_mismatch",
      "under_budgeted_hotkey_accepted");
  require(
      api.batches.empty() && api.cursor_positions.empty() &&
          api.clipboard_calls == 0,
      "invalid_intent_reached_native_api");

  std::stop_source already_stopped;
  already_stopped.request_stop();
  recording_native_api cancelled_api;
  chat::win32_chat_platform_mutation_sink cancelled_sink(
      target(), already_stopped.get_token(), cancelled_api);
  require(
      cancelled_sink.apply(intent(chat::chat_intent_kind::activate_window))
              .reason == "chat_platform_mutation_cancelled",
      "cancelled_mutation_reached_platform");
  auto cancelled_pause = intent(chat::chat_intent_kind::pause);
  cancelled_pause.delay_milliseconds = 500;
  require(
      cancelled_sink.apply(cancelled_pause).reason == "chat_pause_cancelled",
      "pre_cancelled_pause_waited");
  require(
      cancelled_api.activate_calls == 0 && cancelled_api.batches.empty(),
      "cancelled_sink_touched_native_api");
}

void in_flight_pause_is_cancellable_without_platform_mutation() {
  std::stop_source source;
  recording_native_api api;
  chat::win32_chat_platform_mutation_sink sink(
      target(), source.get_token(), api);
  std::jthread canceller([&source]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    source.request_stop();
  });
  auto pause = intent(chat::chat_intent_kind::pause);
  pause.delay_milliseconds = 2'000;
  const auto started = std::chrono::steady_clock::now();
  const auto result = sink.apply(pause);
  const auto elapsed = std::chrono::steady_clock::now() - started;
  require(
      !result.applied && result.reason == "chat_pause_cancelled",
      "in_flight_pause_not_cancelled");
  require(
      elapsed < std::chrono::milliseconds(500),
      "in_flight_pause_cancel_too_slow");
  require(api.batches.empty(), "pause_touched_native_input");
}

int run() {
  every_supported_mutation_has_exact_bounded_shape();
  partial_input_prefix_gets_only_required_release_cleanup();
  invalid_or_cancelled_mutation_never_reaches_native_api();
  in_flight_pause_is_cancellable_without_platform_mutation();
  std::cout << "PASS Win32 chat mutation pulse, cleanup, clipboard and cancellation boundary\n";
  return 0;
}

}  // namespace

int main() {
  try {
    return run();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
