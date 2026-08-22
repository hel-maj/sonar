#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <string_view>

namespace sonar::fishing::stage_detection {

enum class observed_fishing_stage : std::uint8_t {
  none = 0,
  tackle_selection = 1,
  casting = 2,
  waiting_for_bite = 3,
  reeling = 4,
};

struct bgr24_frame_view final {
  std::uint32_t width{};
  std::uint32_t height{};
  std::size_t stride_bytes{};
  std::span<const std::uint8_t> pixels;

  [[nodiscard]] bool valid() const noexcept;
};

struct normalized_rect final {
  double x{};
  double y{};
  double width{};
  double height{};
};

struct stage_observation final {
  observed_fishing_stage stage{observed_fishing_stage::none};
  std::string trigger_id;
  double confidence{};
  normalized_rect bounds;
};

struct stage_detection_result final {
  std::optional<stage_observation> observation;
  std::string error;
};

struct bubble_cue_observation final {
  double confidence{};
  normalized_rect bounds;
};

struct bubble_cue_detection_result final {
  std::optional<bubble_cue_observation> observation;
  std::string error;
};

// Product-owned visual detector. It is pure and performs no capture, window,
// input, clipboard, process, or network operation.
class majestic_fishing_stage_detector final {
 public:
  [[nodiscard]] stage_detection_result detect(
      const bgr24_frame_view& frame) const noexcept;
};

// Legacy-characterized bubbles fallback for the waiting-for-bite episode. The
// exact product templates are embedded in Sonar.Engine.exe and searched only
// inside the normalized client-area cue region.
class majestic_bubble_cue_detector final {
 public:
  [[nodiscard]] bubble_cue_detection_result detect(
      const bgr24_frame_view& frame) const noexcept;
};

[[nodiscard]] std::string_view stage_key(
    observed_fishing_stage stage) noexcept;

}  // namespace sonar::fishing::stage_detection
