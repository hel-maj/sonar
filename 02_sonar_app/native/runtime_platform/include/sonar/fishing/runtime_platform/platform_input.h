#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <stop_token>
#include <string>
#include <string_view>

#include "sonar/platform/windows/window.hpp"

namespace sonar::fishing::runtime_platform {

struct normalized_point final {
  double x{};
  double y{};

  [[nodiscard]] bool valid() const noexcept;
};

enum class input_packet_kind : std::uint8_t {
  key_down,
  key_up,
  left_button_down,
  left_button_up,
  right_button_down,
  right_button_up,
};

struct input_packet final {
  input_packet_kind kind{input_packet_kind::key_up};
  std::uint16_t scan_code{};

  friend bool operator==(const input_packet&, const input_packet&) = default;
};

class native_platform_api {
 public:
  virtual ~native_platform_api() = default;
  [[nodiscard]] virtual bool activate_window(
      sonar::platform::windows::native_window_handle window) noexcept = 0;
  [[nodiscard]] virtual bool set_cursor_position(
      std::int32_t x,
      std::int32_t y) noexcept = 0;
  [[nodiscard]] virtual std::size_t send_input(
      std::span<const input_packet> packets) noexcept = 0;
  [[nodiscard]] virtual bool set_clipboard_text(
      std::wstring_view text) noexcept = 0;
};

enum class mutation_kind : std::uint8_t {
  activate_window,
  release_all_keys,
  release_reeling_keys,
  key_down,
  key_up,
  switch_held_key,
  press_key,
  hotkey,
  move_client,
  click_client_left,
  click_client_right,
  set_clipboard_text,
  pause,
};

struct mutation_intent final {
  mutation_kind kind{mutation_kind::pause};
  std::string primary;
  std::string secondary;
  std::string text;
  normalized_point point;
  std::size_t packet_count{};
  std::size_t delay_milliseconds{};
};

struct mutation_result final {
  bool applied{};
  std::string reason;

  [[nodiscard]] static mutation_result accepted();
  [[nodiscard]] static mutation_result rejected(std::string reason);
};

class platform_mutation_sink {
 public:
  virtual ~platform_mutation_sink() = default;
  [[nodiscard]] virtual mutation_result apply(
      const mutation_intent& intent) = 0;
};

// Complete bounded SendInput batches with partial-prefix release cleanup.
// Construction is inert. The production composition creates this adapter only
// after target/session admission; tests inject native_platform_api recorders.
class win32_platform_mutation_sink final : public platform_mutation_sink {
 public:
  win32_platform_mutation_sink(
      sonar::platform::windows::window_client_snapshot expected,
      std::stop_token stop);
  win32_platform_mutation_sink(
      sonar::platform::windows::window_client_snapshot expected,
      std::stop_token stop,
      native_platform_api& api) noexcept;
  ~win32_platform_mutation_sink();

  win32_platform_mutation_sink(const win32_platform_mutation_sink&) = delete;
  win32_platform_mutation_sink& operator=(
      const win32_platform_mutation_sink&) = delete;

  [[nodiscard]] mutation_result apply(
      const mutation_intent& intent) override;

 private:
  [[nodiscard]] mutation_result send_batch(
      std::span<const input_packet> packets);
  [[nodiscard]] mutation_result pause(std::size_t milliseconds) const;

  sonar::platform::windows::window_client_snapshot expected_;
  std::stop_token stop_;
  std::unique_ptr<native_platform_api> owned_api_;
  native_platform_api* api_{};
};

[[nodiscard]] std::size_t expected_packet_count(
    mutation_kind kind) noexcept;

}  // namespace sonar::fishing::runtime_platform
