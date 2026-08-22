#pragma once

#include "sonar/fishing/stage_detection/fishing_stage_detector.h"

#include <cstdint>
#include <vector>

namespace sonar::fishing::stage_detection::detail {

struct pixel_rect final {
  std::uint32_t x{};
  std::uint32_t y{};
  std::uint32_t width{};
  std::uint32_t height{};
};

struct gray_image final {
  std::uint32_t width{};
  std::uint32_t height{};
  std::vector<std::uint8_t> pixels;

  [[nodiscard]] bool valid() const noexcept;
  [[nodiscard]] std::uint8_t at(
      std::uint32_t x,
      std::uint32_t y) const noexcept;
};

[[nodiscard]] gray_image grayscale(const bgr24_frame_view& frame);

[[nodiscard]] gray_image crop(
    const gray_image& source,
    const pixel_rect& bounds);

[[nodiscard]] gray_image resize_area(
    const gray_image& source,
    std::uint32_t width,
    std::uint32_t height);

[[nodiscard]] gray_image resize_template(
    const gray_image& source,
    double scale);

[[nodiscard]] pixel_rect scale_rect(
    const pixel_rect& reference,
    std::uint32_t width,
    std::uint32_t height,
    std::uint32_t reference_width,
    std::uint32_t reference_height) noexcept;

}  // namespace sonar::fishing::stage_detection::detail
