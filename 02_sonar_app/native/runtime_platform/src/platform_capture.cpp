#include "sonar/fishing/runtime_platform/platform_capture.h"

#include <Windows.h>

#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <utility>

namespace sonar::fishing::runtime_platform {
namespace {

class window_dc final {
 public:
  explicit window_dc(const HWND window) noexcept
      : window_(window), value_(GetDC(window)) {}
  ~window_dc() {
    if (value_ != nullptr) {
      ReleaseDC(window_, value_);
    }
  }
  window_dc(const window_dc&) = delete;
  window_dc& operator=(const window_dc&) = delete;
  [[nodiscard]] HDC get() const noexcept { return value_; }

 private:
  HWND window_{};
  HDC value_{};
};

class memory_dc final {
 public:
  explicit memory_dc(const HDC compatible) noexcept
      : value_(CreateCompatibleDC(compatible)) {}
  ~memory_dc() {
    if (value_ != nullptr) {
      DeleteDC(value_);
    }
  }
  memory_dc(const memory_dc&) = delete;
  memory_dc& operator=(const memory_dc&) = delete;
  [[nodiscard]] HDC get() const noexcept { return value_; }

 private:
  HDC value_{};
};

class owned_bitmap final {
 public:
  explicit owned_bitmap(const HBITMAP value) noexcept : value_(value) {}
  ~owned_bitmap() {
    if (value_ != nullptr) {
      DeleteObject(value_);
    }
  }
  owned_bitmap(const owned_bitmap&) = delete;
  owned_bitmap& operator=(const owned_bitmap&) = delete;
  [[nodiscard]] HBITMAP get() const noexcept { return value_; }

 private:
  HBITMAP value_{};
};

class bitmap_selection final {
 public:
  bitmap_selection(const HDC device, const HBITMAP bitmap) noexcept
      : device_(device), previous_(SelectObject(device, bitmap)) {}
  ~bitmap_selection() {
    if (device_ != nullptr && previous_ != nullptr && previous_ != HGDI_ERROR) {
      SelectObject(device_, previous_);
    }
  }
  bitmap_selection(const bitmap_selection&) = delete;
  bitmap_selection& operator=(const bitmap_selection&) = delete;
  [[nodiscard]] bool ready() const noexcept {
    return previous_ != nullptr && previous_ != HGDI_ERROR;
  }

 private:
  HDC device_{};
  HGDIOBJ previous_{};
};

[[nodiscard]] std::string observation_reason_key(
    const sonar::platform::windows::window_observation_reason reason) {
  using value = sonar::platform::windows::window_observation_reason;
  switch (reason) {
    case value::ready: return "ready";
    case value::invalid_handle: return "invalid_handle";
    case value::owner_unavailable: return "owner_unavailable";
    case value::owner_changed: return "owner_changed";
    case value::process_unavailable: return "process_unavailable";
    case value::process_generation_changed: return "process_generation_changed";
    case value::client_unavailable: return "client_unavailable";
    case value::client_empty: return "client_empty";
    case value::not_visible: return "not_visible";
    case value::minimized: return "minimized";
    case value::not_foreground: return "not_foreground";
    case value::identity_changed: return "identity_changed";
    case value::geometry_changed: return "geometry_changed";
  }
  return "unknown";
}

[[nodiscard]] bool matches_expected(
    const sonar::platform::windows::window_client_snapshot& current,
    const sonar::platform::windows::window_client_snapshot& expected) noexcept {
  return current.same_identity(expected) && current.same_geometry(expected);
}

[[nodiscard]] std::uint64_t steady_now_ns() noexcept {
  return static_cast<std::uint64_t>(
      std::chrono::duration_cast<std::chrono::nanoseconds>(
          std::chrono::steady_clock::now().time_since_epoch()).count());
}

}  // namespace

bool client_frame::valid() const noexcept {
  if (width == 0 || height == 0 || sequence == 0 ||
      captured_at_steady_ns == 0 || target.window == 0 ||
      stride_bytes < static_cast<std::size_t>(width) * 3U) {
    return false;
  }
  return bgr24.size() == stride_bytes * static_cast<std::size_t>(height);
}

capture_result capture_result::captured(client_frame frame) {
  return {.frame = std::move(frame)};
}

capture_result capture_result::unavailable(std::string reason) {
  return {.reason = std::move(reason)};
}

win32_client_capture_source::win32_client_capture_source(
    sonar::platform::windows::window_client_snapshot expected) noexcept
    : expected_(std::move(expected)) {}

capture_result win32_client_capture_source::capture() {
  const auto before = sonar::platform::windows::observe_window_client(
      expected_.window);
  if (!before.ready() || !before.snapshot.has_value()) {
    return capture_result::unavailable(
        "capture_target_unavailable:" + observation_reason_key(before.reason));
  }
  if (!matches_expected(*before.snapshot, expected_)) {
    return capture_result::unavailable("capture_target_changed");
  }
  const auto width = before.snapshot->width;
  const auto height = before.snapshot->height;
  if (width == 0 || height == 0 ||
      width > static_cast<std::uint32_t>(std::numeric_limits<LONG>::max()) ||
      height > static_cast<std::uint32_t>(std::numeric_limits<LONG>::max()) ||
      width > std::numeric_limits<std::size_t>::max() / 4U ||
      static_cast<std::size_t>(width) * 4U >
          std::numeric_limits<std::size_t>::max() / height ||
      sequence_ == std::numeric_limits<std::uint64_t>::max()) {
    return capture_result::unavailable("capture_geometry_invalid");
  }

  const auto window = reinterpret_cast<HWND>(expected_.window);
  window_dc source(window);
  if (source.get() == nullptr) {
    return capture_result::unavailable("capture_window_dc_failed");
  }
  memory_dc destination(source.get());
  if (destination.get() == nullptr) {
    return capture_result::unavailable("capture_memory_dc_failed");
  }

  BITMAPINFO info{};
  info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
  info.bmiHeader.biWidth = static_cast<LONG>(width);
  info.bmiHeader.biHeight = -static_cast<LONG>(height);
  info.bmiHeader.biPlanes = 1;
  info.bmiHeader.biBitCount = 32;
  info.bmiHeader.biCompression = BI_RGB;
  void* raw_pixels = nullptr;
  owned_bitmap bitmap(CreateDIBSection(
      source.get(), &info, DIB_RGB_COLORS, &raw_pixels, nullptr, 0));
  if (bitmap.get() == nullptr || raw_pixels == nullptr) {
    return capture_result::unavailable("capture_bitmap_failed");
  }
  bitmap_selection selection(destination.get(), bitmap.get());
  if (!selection.ready()) {
    return capture_result::unavailable("capture_bitmap_select_failed");
  }
  if (!BitBlt(
          destination.get(),
          0,
          0,
          static_cast<int>(width),
          static_cast<int>(height),
          source.get(),
          0,
          0,
          SRCCOPY | CAPTUREBLT)) {
    return capture_result::unavailable("capture_blit_failed");
  }

  const auto after = sonar::platform::windows::observe_window_client(
      expected_.window);
  if (!after.ready() || !after.snapshot.has_value() ||
      !matches_expected(*after.snapshot, *before.snapshot)) {
    return capture_result::unavailable("capture_target_changed_during_frame");
  }

  const auto destination_stride = static_cast<std::size_t>(width) * 3U;
  std::vector<std::uint8_t> bgr24(destination_stride * height);
  const auto* source_pixels = static_cast<const std::uint8_t*>(raw_pixels);
  const auto source_stride = static_cast<std::size_t>(width) * 4U;
  for (std::uint32_t y = 0; y < height; ++y) {
    for (std::uint32_t x = 0; x < width; ++x) {
      const auto source_offset = static_cast<std::size_t>(y) * source_stride +
          static_cast<std::size_t>(x) * 4U;
      const auto destination_offset =
          static_cast<std::size_t>(y) * destination_stride +
          static_cast<std::size_t>(x) * 3U;
      std::copy_n(
          source_pixels + source_offset,
          3,
          bgr24.begin() + static_cast<std::ptrdiff_t>(destination_offset));
    }
  }
  ++sequence_;
  return capture_result::captured({
      .width = width,
      .height = height,
      .stride_bytes = destination_stride,
      .sequence = sequence_,
      .captured_at_steady_ns = steady_now_ns(),
      .target = *after.snapshot,
      .bgr24 = std::move(bgr24),
  });
}

}  // namespace sonar::fishing::runtime_platform
