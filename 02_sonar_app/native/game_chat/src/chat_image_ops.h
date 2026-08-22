#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "sonar/fishing/game_chat/chat_observation.h"

namespace sonar::fishing::game_chat::detail {

struct byte_image final {
  std::uint32_t width{};
  std::uint32_t height{};
  std::vector<std::uint8_t> pixels;

  [[nodiscard]] std::uint8_t at(
      std::uint32_t x,
      std::uint32_t y) const noexcept;
};

struct binary_component final {
  std::uint32_t x{};
  std::uint32_t y{};
  std::uint32_t width{};
  std::uint32_t height{};
  std::size_t area{};
};

[[nodiscard]] byte_image grayscale(const chat_frame& frame);

[[nodiscard]] byte_image canny_edges(
    const byte_image& source,
    int low_threshold,
    int high_threshold);

[[nodiscard]] byte_image morphological_close(
    const byte_image& source,
    std::uint32_t kernel_width,
    std::uint32_t kernel_height);

[[nodiscard]] std::vector<binary_component> connected_components(
    byte_image source);

[[nodiscard]] byte_image crop(
    const byte_image& source,
    const pixel_rect& bounds);

[[nodiscard]] double mean(
    const byte_image& source,
    const pixel_rect& bounds) noexcept;

[[nodiscard]] double nonzero_ratio(const byte_image& source) noexcept;

[[nodiscard]] byte_image red_hsv_mask(
    const chat_frame& frame,
    const pixel_rect& bounds);

[[nodiscard]] byte_image light_low_saturation_mask(
    const chat_frame& frame,
    const pixel_rect& bounds,
    std::uint8_t minimum_value,
    std::uint8_t maximum_saturation);

}  // namespace sonar::fishing::game_chat::detail
