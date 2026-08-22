#include "sonar/fishing/automation_adapters/frame_semantics.h"

#include "sonar/fishing/stage_detection/fishing_stage_detector.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>

namespace sonar::fishing::automation_adapters {
namespace {

struct pixel_region final {
  std::uint32_t left{};
  std::uint32_t top{};
  std::uint32_t right{};
  std::uint32_t bottom{};

  [[nodiscard]] std::size_t area() const noexcept {
    return static_cast<std::size_t>(right - left) * (bottom - top);
  }
};

[[nodiscard]] pixel_region region(
    const runtime_platform::client_frame& frame,
    const double left,
    const double top,
    const double right,
    const double bottom) noexcept {
  const auto scale_x = static_cast<double>(frame.width);
  const auto scale_y = static_cast<double>(frame.height);
  const auto clamp_x = [&frame](const double value) {
    return (std::min)(frame.width,
        static_cast<std::uint32_t>(std::llround(value)));
  };
  const auto clamp_y = [&frame](const double value) {
    return (std::min)(frame.height,
        static_cast<std::uint32_t>(std::llround(value)));
  };
  pixel_region value{
      clamp_x(left * scale_x),
      clamp_y(top * scale_y),
      clamp_x(right * scale_x),
      clamp_y(bottom * scale_y),
  };
  if (value.left < frame.width) {
    value.right = (std::max)(value.right, value.left + 1U);
  }
  if (value.top < frame.height) {
    value.bottom = (std::max)(value.bottom, value.top + 1U);
  }
  value.right = (std::min)(value.right, frame.width);
  value.bottom = (std::min)(value.bottom, frame.height);
  return value;
}

template <typename Predicate>
[[nodiscard]] double matching_fraction(
    const runtime_platform::client_frame& frame,
    const pixel_region& roi,
    Predicate predicate) noexcept {
  if (roi.area() == 0U) {
    return 0.0;
  }
  std::size_t matched = 0U;
  for (std::uint32_t y = roi.top; y < roi.bottom; ++y) {
    for (std::uint32_t x = roi.left; x < roi.right; ++x) {
      const auto offset = static_cast<std::size_t>(y) * frame.stride_bytes +
          static_cast<std::size_t>(x) * 3U;
      if (predicate(
              frame.bgr24[offset],
              frame.bgr24[offset + 1U],
              frame.bgr24[offset + 2U])) {
        ++matched;
      }
    }
  }
  return static_cast<double>(matched) / static_cast<double>(roi.area());
}

[[nodiscard]] bool detect_catch_panel(
    const runtime_platform::client_frame& frame) noexcept {
  const auto panel = region(frame, 0.385, 0.265, 0.615, 0.730);
  const auto heading = region(frame, 0.395, 0.290, 0.585, 0.335);
  const auto buttons = region(frame, 0.400, 0.645, 0.600, 0.705);
  const double panel_dark = matching_fraction(
      frame, panel, [](const auto blue, const auto green, const auto red) {
        return blue < 55U && green < 55U && red < 55U;
      });
  const double heading_bright = matching_fraction(
      frame, heading, [](const auto blue, const auto green, const auto red) {
        return blue > 175U && green > 175U && red > 175U;
      });
  const double button_dark = matching_fraction(
      frame, buttons, [](const auto blue, const auto green, const auto red) {
        return blue < 75U && green < 75U && red < 75U;
      });
  return panel_dark >= 0.72 && heading_bright >= 0.012 &&
      button_dark >= 0.58;
}

}  // namespace

frame_semantics detect_frame_semantics(
    const runtime_platform::client_frame& frame) noexcept {
  if (!frame.valid()) {
    return {};
  }
  const auto casting = region(frame, 0.355, 0.815, 0.650, 0.845);
  const double green = matching_fraction(
      frame, casting, [](const auto blue, const auto green, const auto red) {
        return green >= 85U && green >= blue + 18U &&
            green >= red + 18U && red <= 180U;
      });

  const auto hooking = region(frame, 0.700, 0.895, 0.800, 0.940);
  const double red = matching_fraction(
      frame, hooking, [](const auto blue, const auto green, const auto red) {
        return red >= 145U && red >= green + 40U && red >= blue + 35U;
      });

  static const stage_detection::majestic_bubble_cue_detector bubbles;
  const auto bubble = bubbles.detect({
      .width = frame.width,
      .height = frame.height,
      .stride_bytes = frame.stride_bytes,
      .pixels = frame.bgr24,
  });
  const double bubble_confidence = bubble.observation.has_value()
      ? bubble.observation->confidence
      : 0.0;

  frame_semantics result{
      .cast_ready = green >= 0.008,
      .cast_confidence = (std::min)(1.0, green / 0.08),
      .hook = red >= 0.012
          ? fishing_episode::hook_cue::red
          : (bubble.observation.has_value()
                ? fishing_episode::hook_cue::bubbles
                : fishing_episode::hook_cue::none),
      .hook_confidence = red >= 0.012
          ? (std::min)(1.0, red / 0.12)
          : bubble_confidence,
      .catch_visible = detect_catch_panel(frame),
  };
  return result;
}

}  // namespace sonar::fishing::automation_adapters
