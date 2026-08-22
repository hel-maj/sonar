#include "sonar/fishing/runtime_platform/platform_input.h"

#include <Windows.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cctype>
#include <condition_variable>
#include <cstring>
#include <limits>
#include <mutex>
#include <optional>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

namespace sonar::fishing::runtime_platform {
namespace {

constexpr std::size_t kMaximumPauseMilliseconds = 5'000U;

class clipboard_guard final {
 public:
  clipboard_guard() noexcept : open_(OpenClipboard(nullptr) != FALSE) {}
  ~clipboard_guard() {
    if (open_) {
      CloseClipboard();
    }
  }
  clipboard_guard(const clipboard_guard&) = delete;
  clipboard_guard& operator=(const clipboard_guard&) = delete;
  [[nodiscard]] bool open() const noexcept { return open_; }

 private:
  bool open_{};
};

class global_memory final {
 public:
  explicit global_memory(const std::size_t bytes) noexcept
      : value_(GlobalAlloc(GMEM_MOVEABLE, bytes)) {}
  ~global_memory() {
    if (value_ != nullptr) {
      GlobalFree(value_);
    }
  }
  global_memory(const global_memory&) = delete;
  global_memory& operator=(const global_memory&) = delete;
  [[nodiscard]] HGLOBAL get() const noexcept { return value_; }
  [[nodiscard]] HGLOBAL release() noexcept {
    return std::exchange(value_, nullptr);
  }

 private:
  HGLOBAL value_{};
};

class win32_native_platform_api final : public native_platform_api {
 public:
  [[nodiscard]] bool activate_window(
      const sonar::platform::windows::native_window_handle window)
      noexcept override {
    return window != 0 &&
        SetForegroundWindow(reinterpret_cast<HWND>(window)) != FALSE;
  }

  [[nodiscard]] bool set_cursor_position(
      const std::int32_t x,
      const std::int32_t y) noexcept override {
    return SetCursorPos(x, y) != FALSE;
  }

  [[nodiscard]] std::size_t send_input(
      const std::span<const input_packet> packets) noexcept override {
    if (packets.empty() || packets.size() > std::numeric_limits<UINT>::max()) {
      return 0;
    }
    std::vector<INPUT> native;
    native.reserve(packets.size());
    for (const auto& packet : packets) {
      INPUT input{};
      switch (packet.kind) {
        case input_packet_kind::key_down:
        case input_packet_kind::key_up:
          if (packet.scan_code == 0) {
            return 0;
          }
          input.type = INPUT_KEYBOARD;
          input.ki.wScan = packet.scan_code;
          input.ki.dwFlags = KEYEVENTF_SCANCODE;
          if (packet.kind == input_packet_kind::key_up) {
            input.ki.dwFlags |= KEYEVENTF_KEYUP;
          }
          break;
        case input_packet_kind::left_button_down:
          input.type = INPUT_MOUSE;
          input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
          break;
        case input_packet_kind::left_button_up:
          input.type = INPUT_MOUSE;
          input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
          break;
        case input_packet_kind::right_button_down:
          input.type = INPUT_MOUSE;
          input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
          break;
        case input_packet_kind::right_button_up:
          input.type = INPUT_MOUSE;
          input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
          break;
      }
      native.push_back(input);
    }
    return static_cast<std::size_t>(SendInput(
        static_cast<UINT>(native.size()), native.data(), sizeof(INPUT)));
  }

  [[nodiscard]] bool set_clipboard_text(
      const std::wstring_view text) noexcept override {
    if (text.empty() ||
        text.size() > (std::numeric_limits<std::size_t>::max() /
            sizeof(wchar_t)) - 1U) {
      return false;
    }
    const std::size_t bytes = (text.size() + 1U) * sizeof(wchar_t);
    global_memory memory(bytes);
    if (memory.get() == nullptr) {
      return false;
    }
    void* destination = GlobalLock(memory.get());
    if (destination == nullptr) {
      return false;
    }
    std::memcpy(destination, text.data(), text.size() * sizeof(wchar_t));
    static_cast<wchar_t*>(destination)[text.size()] = L'\0';
    GlobalUnlock(memory.get());

    clipboard_guard clipboard;
    if (!clipboard.open() || EmptyClipboard() == FALSE ||
        SetClipboardData(CF_UNICODETEXT, memory.get()) == nullptr) {
      return false;
    }
    static_cast<void>(memory.release());
    return true;
  }
};

[[nodiscard]] std::string normalize_key(const std::string_view key) {
  std::size_t first = 0;
  while (first < key.size() &&
         std::isspace(static_cast<unsigned char>(key[first])) != 0) {
    ++first;
  }
  std::size_t last = key.size();
  while (last > first &&
         std::isspace(static_cast<unsigned char>(key[last - 1U])) != 0) {
    --last;
  }
  std::string normalized(key.substr(first, last - first));
  std::transform(
      normalized.begin(), normalized.end(), normalized.begin(),
      [](const unsigned char character) {
        return static_cast<char>(std::tolower(character));
      });
  return normalized;
}

[[nodiscard]] std::optional<std::uint16_t> scan_code_for(
    const std::string_view key) {
  const std::string normalized = normalize_key(key);
  if (normalized == "w") {
    return std::nullopt;
  }
  static constexpr std::array<std::pair<std::string_view, std::uint16_t>, 60>
      kScanCodes{{
          {"esc", 0x01}, {"escape", 0x01},
          {"1", 0x02}, {"2", 0x03}, {"3", 0x04}, {"4", 0x05},
          {"5", 0x06}, {"6", 0x07}, {"7", 0x08}, {"8", 0x09},
          {"9", 0x0A}, {"0", 0x0B}, {"backspace", 0x0E},
          {"tab", 0x0F}, {"q", 0x10}, {"e", 0x12}, {"r", 0x13},
          {"t", 0x14}, {"y", 0x15}, {"u", 0x16}, {"i", 0x17},
          {"o", 0x18}, {"p", 0x19}, {"a", 0x1E}, {"s", 0x1F},
          {"d", 0x20}, {"f", 0x21}, {"g", 0x22}, {"h", 0x23},
          {"j", 0x24}, {"k", 0x25}, {"l", 0x26}, {"z", 0x2C},
          {"x", 0x2D}, {"c", 0x2E}, {"v", 0x2F}, {"b", 0x30},
          {"n", 0x31}, {"m", 0x32}, {"enter", 0x1C},
          {"return", 0x1C}, {"ctrl", 0x1D}, {"control", 0x1D},
          {"left_ctrl", 0x1D}, {"alt", 0x38}, {"space", 0x39},
          {"shift", 0x2A}, {"left_shift", 0x2A},
          {"f1", 0x3B}, {"f2", 0x3C}, {"f3", 0x3D},
          {"f4", 0x3E}, {"f5", 0x3F}, {"f6", 0x40},
          {"f7", 0x41}, {"f8", 0x42}, {"f9", 0x43},
          {"f10", 0x44}, {"f11", 0x57}, {"f12", 0x58},
      }};
  const auto found = std::find_if(
      kScanCodes.begin(), kScanCodes.end(),
      [&normalized](const auto& entry) { return entry.first == normalized; });
  return found == kScanCodes.end()
      ? std::nullopt
      : std::optional<std::uint16_t>(found->second);
}

[[nodiscard]] std::optional<std::wstring> strict_utf8_to_utf16(
    const std::string_view text) {
  if (text.empty() || text.find('\0') != std::string_view::npos ||
      text.size() > static_cast<std::size_t>(std::numeric_limits<int>::max())) {
    return std::nullopt;
  }
  const int required = MultiByteToWideChar(
      CP_UTF8, MB_ERR_INVALID_CHARS, text.data(),
      static_cast<int>(text.size()), nullptr, 0);
  if (required <= 0) {
    return std::nullopt;
  }
  std::wstring converted(static_cast<std::size_t>(required), L'\0');
  const int written = MultiByteToWideChar(
      CP_UTF8, MB_ERR_INVALID_CHARS, text.data(),
      static_cast<int>(text.size()), converted.data(), required);
  if (written != required || converted.find(L'\0') != std::wstring::npos) {
    return std::nullopt;
  }
  return converted;
}

[[nodiscard]] std::vector<input_packet> cleanup_for_prefix(
    const std::span<const input_packet> packets,
    const std::size_t applied) {
  std::vector<input_packet> cleanup;
  std::unordered_set<std::uint16_t> held_keys;
  bool left_held = false;
  bool right_held = false;
  const std::size_t bounded = (std::min)(applied, packets.size());
  for (std::size_t index = 0; index < bounded; ++index) {
    const auto& packet = packets[index];
    switch (packet.kind) {
      case input_packet_kind::key_down: held_keys.insert(packet.scan_code); break;
      case input_packet_kind::key_up: held_keys.erase(packet.scan_code); break;
      case input_packet_kind::left_button_down: left_held = true; break;
      case input_packet_kind::left_button_up: left_held = false; break;
      case input_packet_kind::right_button_down: right_held = true; break;
      case input_packet_kind::right_button_up: right_held = false; break;
    }
  }
  for (auto iterator = packets.rbegin(); iterator != packets.rend(); ++iterator) {
    if (iterator->kind == input_packet_kind::key_down &&
        held_keys.erase(iterator->scan_code) != 0) {
      cleanup.push_back({input_packet_kind::key_up, iterator->scan_code});
    }
  }
  if (left_held) {
    cleanup.push_back({input_packet_kind::left_button_up, 0});
  }
  if (right_held) {
    cleanup.push_back({input_packet_kind::right_button_up, 0});
  }
  return cleanup;
}

[[nodiscard]] std::optional<std::pair<std::int32_t, std::int32_t>>
client_point_to_screen(
    const sonar::platform::windows::window_client_snapshot& expected,
    const normalized_point point) {
  if (!point.valid() || expected.window == 0 || expected.width == 0 ||
      expected.height == 0) {
    return std::nullopt;
  }
  const auto x_offset = static_cast<std::int64_t>(std::llround(
      point.x * static_cast<double>(expected.width - 1U)));
  const auto y_offset = static_cast<std::int64_t>(std::llround(
      point.y * static_cast<double>(expected.height - 1U)));
  const std::int64_t screen_x =
      static_cast<std::int64_t>(expected.screen_left) + x_offset;
  const std::int64_t screen_y =
      static_cast<std::int64_t>(expected.screen_top) + y_offset;
  if (screen_x < std::numeric_limits<std::int32_t>::min() ||
      screen_x > std::numeric_limits<std::int32_t>::max() ||
      screen_y < std::numeric_limits<std::int32_t>::min() ||
      screen_y > std::numeric_limits<std::int32_t>::max()) {
    return std::nullopt;
  }
  return std::pair{
      static_cast<std::int32_t>(screen_x),
      static_cast<std::int32_t>(screen_y)};
}

}  // namespace

bool normalized_point::valid() const noexcept {
  return std::isfinite(x) && std::isfinite(y) && x >= 0.0 && x <= 1.0 &&
      y >= 0.0 && y <= 1.0;
}

mutation_result mutation_result::accepted() {
  return {.applied = true};
}

mutation_result mutation_result::rejected(std::string reason) {
  return {.reason = std::move(reason)};
}

std::size_t expected_packet_count(const mutation_kind kind) noexcept {
  switch (kind) {
    case mutation_kind::activate_window: return 1U;
    case mutation_kind::release_all_keys: return 9U;
    case mutation_kind::release_reeling_keys: return 2U;
    case mutation_kind::key_down:
    case mutation_kind::key_up: return 1U;
    case mutation_kind::switch_held_key: return 2U;
    case mutation_kind::press_key: return 2U;
    case mutation_kind::hotkey: return 4U;
    case mutation_kind::move_client: return 1U;
    case mutation_kind::click_client_left:
    case mutation_kind::click_client_right: return 3U;
    case mutation_kind::set_clipboard_text: return 1U;
    case mutation_kind::pause: return 0U;
  }
  return std::numeric_limits<std::size_t>::max();
}

win32_platform_mutation_sink::win32_platform_mutation_sink(
    sonar::platform::windows::window_client_snapshot expected,
    const std::stop_token stop)
    : expected_(std::move(expected)),
      stop_(stop),
      owned_api_(std::make_unique<win32_native_platform_api>()),
      api_(owned_api_.get()) {}

win32_platform_mutation_sink::win32_platform_mutation_sink(
    sonar::platform::windows::window_client_snapshot expected,
    const std::stop_token stop,
    native_platform_api& api) noexcept
    : expected_(std::move(expected)), stop_(stop), api_(&api) {}

win32_platform_mutation_sink::~win32_platform_mutation_sink() = default;

mutation_result win32_platform_mutation_sink::send_batch(
    const std::span<const input_packet> packets) {
  if (packets.empty() || api_ == nullptr) {
    return mutation_result::rejected("send_input_invalid");
  }
  const std::size_t applied = api_->send_input(packets);
  if (applied == packets.size()) {
    return mutation_result::accepted();
  }
  const auto cleanup = cleanup_for_prefix(packets, applied);
  if (!cleanup.empty() && api_->send_input(cleanup) != cleanup.size()) {
    return mutation_result::rejected("send_input_cleanup_failed");
  }
  return mutation_result::rejected("send_input_incomplete");
}

mutation_result win32_platform_mutation_sink::pause(
    const std::size_t milliseconds) const {
  if (milliseconds == 0 || milliseconds > kMaximumPauseMilliseconds) {
    return mutation_result::rejected("pause_invalid");
  }
  if (stop_.stop_requested()) {
    return mutation_result::rejected("pause_cancelled");
  }
  std::mutex mutex;
  std::condition_variable condition;
  std::stop_callback callback(stop_, [&condition]() noexcept {
    condition.notify_all();
  });
  std::unique_lock lock(mutex);
  const bool cancelled = condition.wait_for(
      lock,
      std::chrono::milliseconds(milliseconds),
      [this]() noexcept { return stop_.stop_requested(); });
  return cancelled
      ? mutation_result::rejected("pause_cancelled")
      : mutation_result::accepted();
}

mutation_result win32_platform_mutation_sink::apply(
    const mutation_intent& intent) {
  if (intent.packet_count != expected_packet_count(intent.kind)) {
    return mutation_result::rejected("platform_packet_count_mismatch");
  }
  if (intent.kind == mutation_kind::pause) {
    return pause(intent.delay_milliseconds);
  }
  if (stop_.stop_requested()) {
    return mutation_result::rejected("platform_mutation_cancelled");
  }
  if (api_ == nullptr) {
    return mutation_result::rejected("platform_api_unavailable");
  }

  switch (intent.kind) {
    case mutation_kind::activate_window:
      return expected_.window != 0 && api_->activate_window(expected_.window)
          ? mutation_result::accepted()
          : mutation_result::rejected("window_activation_failed");
    case mutation_kind::release_all_keys: {
      static constexpr std::array<std::uint16_t, 9> kReleaseScans{
          0x1E, 0x1F, 0x20, 0x12, 0x10, 0x2A, 0x39, 0x1D, 0x38};
      std::array<input_packet, kReleaseScans.size()> packets{};
      for (std::size_t index = 0; index < packets.size(); ++index) {
        packets[index] = {input_packet_kind::key_up, kReleaseScans[index]};
      }
      return send_batch(packets);
    }
    case mutation_kind::release_reeling_keys: {
      const std::array<input_packet, 2> packets{{
          {input_packet_kind::key_up, 0x1E},
          {input_packet_kind::key_up, 0x20}}};
      return send_batch(packets);
    }
    case mutation_kind::key_down:
    case mutation_kind::key_up: {
      const auto scan = scan_code_for(intent.primary);
      if (!scan.has_value()) {
        return mutation_result::rejected("key_unsupported");
      }
      const std::array<input_packet, 1> packets{{{
          intent.kind == mutation_kind::key_down
              ? input_packet_kind::key_down
              : input_packet_kind::key_up,
          *scan}}};
      return send_batch(packets);
    }
    case mutation_kind::switch_held_key: {
      const auto released = scan_code_for(intent.primary);
      const auto pressed = scan_code_for(intent.secondary);
      if (!released.has_value() || !pressed.has_value() ||
          *released == *pressed) {
        return mutation_result::rejected("key_switch_unsupported");
      }
      const std::array<input_packet, 2> packets{{
          {input_packet_kind::key_up, *released},
          {input_packet_kind::key_down, *pressed}}};
      return send_batch(packets);
    }
    case mutation_kind::press_key: {
      const auto scan = scan_code_for(intent.primary);
      if (!scan.has_value()) {
        return mutation_result::rejected("key_unsupported");
      }
      const std::array<input_packet, 2> packets{{
          {input_packet_kind::key_down, *scan},
          {input_packet_kind::key_up, *scan}}};
      return send_batch(packets);
    }
    case mutation_kind::hotkey: {
      const auto first = scan_code_for(intent.primary);
      const auto second = scan_code_for(intent.secondary);
      if (!first.has_value() || !second.has_value() || *first == *second) {
        return mutation_result::rejected("hotkey_unsupported");
      }
      const std::array<input_packet, 4> packets{{
          {input_packet_kind::key_down, *first},
          {input_packet_kind::key_down, *second},
          {input_packet_kind::key_up, *second},
          {input_packet_kind::key_up, *first}}};
      return send_batch(packets);
    }
    case mutation_kind::move_client:
    case mutation_kind::click_client_left:
    case mutation_kind::click_client_right: {
      const auto screen = client_point_to_screen(expected_, intent.point);
      if (!screen.has_value()) {
        return mutation_result::rejected("click_target_invalid");
      }
      if (!api_->set_cursor_position(screen->first, screen->second)) {
        return mutation_result::rejected("cursor_move_failed");
      }
      if (intent.kind == mutation_kind::move_client) {
        return mutation_result::accepted();
      }
      const bool left = intent.kind == mutation_kind::click_client_left;
      const std::array<input_packet, 2> packets{{
          {left ? input_packet_kind::left_button_down
                : input_packet_kind::right_button_down, 0},
          {left ? input_packet_kind::left_button_up
                : input_packet_kind::right_button_up, 0}}};
      return send_batch(packets);
    }
    case mutation_kind::set_clipboard_text: {
      const auto text = strict_utf8_to_utf16(intent.text);
      if (!text.has_value()) {
        return mutation_result::rejected("clipboard_text_invalid");
      }
      return api_->set_clipboard_text(*text)
          ? mutation_result::accepted()
          : mutation_result::rejected("clipboard_write_failed");
    }
    case mutation_kind::pause:
      break;
  }
  return mutation_result::rejected("platform_intent_invalid");
}

}  // namespace sonar::fishing::runtime_platform
