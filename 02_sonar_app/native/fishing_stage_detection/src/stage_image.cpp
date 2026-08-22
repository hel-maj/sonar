#include "stage_image.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <limits>
#include <stdexcept>

namespace sonar::fishing::stage_detection::detail {
namespace {

[[nodiscard]] std::size_t image_index(
    const std::uint32_t width,
    const std::uint32_t x,
    const std::uint32_t y) noexcept {
  return static_cast<std::size_t>(y) * width + x;
}

[[nodiscard]] std::uint8_t bgr_gray(
    const std::uint8_t blue,
    const std::uint8_t green,
    const std::uint8_t red) noexcept {
  // OpenCV's 8-bit BGR -> gray fixed-point coefficients.
  constexpr int kBlueWeight = 1868;
  constexpr int kGreenWeight = 9617;
  constexpr int kRedWeight = 4899;
  constexpr int kRound = 1 << 13;
  return static_cast<std::uint8_t>(
      (blue * kBlueWeight + green * kGreenWeight + red * kRedWeight +
       kRound) >> 14);
}

[[nodiscard]] double cubic_weight(const double distance) noexcept {
  constexpr double kA = -0.75;
  const auto value = std::abs(distance);
  if (value <= 1.0) {
    return (kA + 2.0) * value * value * value -
        (kA + 3.0) * value * value + 1.0;
  }
  if (value < 2.0) {
    return kA * value * value * value - 5.0 * kA * value * value +
        8.0 * kA * value - 4.0 * kA;
  }
  return 0.0;
}

[[nodiscard]] gray_image resize_cubic(
    const gray_image& source,
    const std::uint32_t width,
    const std::uint32_t height) {
  gray_image result{
      .width = width,
      .height = height,
      .pixels = std::vector<std::uint8_t>(
          static_cast<std::size_t>(width) * height),
  };
  const auto scale_x = static_cast<double>(source.width) / width;
  const auto scale_y = static_cast<double>(source.height) / height;
  for (std::uint32_t y = 0; y < height; ++y) {
    const auto source_y = (static_cast<double>(y) + 0.5) * scale_y - 0.5;
    const auto base_y = static_cast<int>(std::floor(source_y));
    for (std::uint32_t x = 0; x < width; ++x) {
      const auto source_x = (static_cast<double>(x) + 0.5) * scale_x - 0.5;
      const auto base_x = static_cast<int>(std::floor(source_x));
      double weighted = 0.0;
      double total_weight = 0.0;
      for (int offset_y = -1; offset_y <= 2; ++offset_y) {
        const auto sample_y = std::clamp(
            base_y + offset_y, 0, static_cast<int>(source.height) - 1);
        const auto weight_y = cubic_weight(source_y - (base_y + offset_y));
        for (int offset_x = -1; offset_x <= 2; ++offset_x) {
          const auto sample_x = std::clamp(
              base_x + offset_x, 0, static_cast<int>(source.width) - 1);
          const auto weight = weight_y *
              cubic_weight(source_x - (base_x + offset_x));
          weighted += weight * source.at(
              static_cast<std::uint32_t>(sample_x),
              static_cast<std::uint32_t>(sample_y));
          total_weight += weight;
        }
      }
      const auto value = total_weight == 0.0 ? 0.0 : weighted / total_weight;
      result.pixels[image_index(width, x, y)] = static_cast<std::uint8_t>(
          std::clamp(std::lround(value), 0L, 255L));
    }
  }
  return result;
}

}  // namespace

bool gray_image::valid() const noexcept {
  if (width == 0 || height == 0 ||
      width > std::numeric_limits<std::size_t>::max() / height) {
    return false;
  }
  return pixels.size() == static_cast<std::size_t>(width) * height;
}

std::uint8_t gray_image::at(
    const std::uint32_t x,
    const std::uint32_t y) const noexcept {
  return pixels[image_index(width, x, y)];
}

gray_image grayscale(const bgr24_frame_view& frame) {
  if (!frame.valid()) {
    throw std::invalid_argument("fishing_stage_frame_invalid");
  }
  gray_image result{
      .width = frame.width,
      .height = frame.height,
      .pixels = std::vector<std::uint8_t>(
          static_cast<std::size_t>(frame.width) * frame.height),
  };
  for (std::uint32_t y = 0; y < frame.height; ++y) {
    const auto row = static_cast<std::size_t>(y) * frame.stride_bytes;
    for (std::uint32_t x = 0; x < frame.width; ++x) {
      const auto source = row + static_cast<std::size_t>(x) * 3;
      result.pixels[image_index(frame.width, x, y)] = bgr_gray(
          frame.pixels[source],
          frame.pixels[source + 1],
          frame.pixels[source + 2]);
    }
  }
  return result;
}

gray_image crop(const gray_image& source, const pixel_rect& bounds) {
  if (!source.valid() || bounds.width == 0 || bounds.height == 0 ||
      bounds.x > source.width || bounds.y > source.height ||
      bounds.width > source.width - bounds.x ||
      bounds.height > source.height - bounds.y) {
    throw std::invalid_argument("fishing_stage_crop_invalid");
  }
  gray_image result{
      .width = bounds.width,
      .height = bounds.height,
      .pixels = std::vector<std::uint8_t>(
          static_cast<std::size_t>(bounds.width) * bounds.height),
  };
  for (std::uint32_t y = 0; y < bounds.height; ++y) {
    const auto first = source.pixels.begin() + static_cast<std::ptrdiff_t>(
        image_index(source.width, bounds.x, bounds.y + y));
    const auto destination = result.pixels.begin() +
        static_cast<std::ptrdiff_t>(image_index(bounds.width, 0, y));
    std::copy_n(first, bounds.width, destination);
  }
  return result;
}

gray_image resize_area(
    const gray_image& source,
    const std::uint32_t width,
    const std::uint32_t height) {
  if (!source.valid() || width == 0 || height == 0 ||
      width > source.width || height > source.height) {
    throw std::invalid_argument("fishing_stage_area_resize_invalid");
  }
  if (width == source.width && height == source.height) {
    return source;
  }
  gray_image result{
      .width = width,
      .height = height,
      .pixels = std::vector<std::uint8_t>(
          static_cast<std::size_t>(width) * height),
  };
  const auto scale_x = static_cast<double>(source.width) / width;
  const auto scale_y = static_cast<double>(source.height) / height;
  for (std::uint32_t y = 0; y < height; ++y) {
    const auto top = static_cast<double>(y) * scale_y;
    const auto bottom = static_cast<double>(y + 1) * scale_y;
    const auto first_y = static_cast<int>(std::floor(top));
    const auto last_y = static_cast<int>(std::ceil(bottom));
    for (std::uint32_t x = 0; x < width; ++x) {
      const auto left = static_cast<double>(x) * scale_x;
      const auto right = static_cast<double>(x + 1) * scale_x;
      const auto first_x = static_cast<int>(std::floor(left));
      const auto last_x = static_cast<int>(std::ceil(right));
      double weighted = 0.0;
      double area = 0.0;
      for (auto source_y = first_y; source_y < last_y; ++source_y) {
        if (source_y < 0 || source_y >= static_cast<int>(source.height)) {
          continue;
        }
        const auto height_weight = std::max(
            0.0,
            std::min(bottom, static_cast<double>(source_y + 1)) -
                std::max(top, static_cast<double>(source_y)));
        for (auto source_x = first_x; source_x < last_x; ++source_x) {
          if (source_x < 0 || source_x >= static_cast<int>(source.width)) {
            continue;
          }
          const auto width_weight = std::max(
              0.0,
              std::min(right, static_cast<double>(source_x + 1)) -
                  std::max(left, static_cast<double>(source_x)));
          const auto weight = width_weight * height_weight;
          weighted += weight * source.at(
              static_cast<std::uint32_t>(source_x),
              static_cast<std::uint32_t>(source_y));
          area += weight;
        }
      }
      result.pixels[image_index(width, x, y)] = static_cast<std::uint8_t>(
          std::clamp(std::lround(weighted / area), 0L, 255L));
    }
  }
  return result;
}

gray_image resize_template(const gray_image& source, const double scale) {
  if (!source.valid() || !std::isfinite(scale) || scale <= 0.0) {
    throw std::invalid_argument("fishing_stage_template_scale_invalid");
  }
  const auto width = std::max(
      std::int64_t{1}, std::llround(static_cast<double>(source.width) * scale));
  const auto height = std::max(
      std::int64_t{1}, std::llround(static_cast<double>(source.height) * scale));
  if (width < 3 || height < 3 ||
      width > static_cast<std::int64_t>(
          std::numeric_limits<std::uint32_t>::max()) ||
      height > static_cast<std::int64_t>(
          std::numeric_limits<std::uint32_t>::max())) {
    throw std::invalid_argument("fishing_stage_template_scale_out_of_range");
  }
  if (width == static_cast<std::int64_t>(source.width) &&
      height == static_cast<std::int64_t>(source.height)) {
    return source;
  }
  if (scale < 1.0) {
    return resize_area(
        source,
        static_cast<std::uint32_t>(width),
        static_cast<std::uint32_t>(height));
  }
  return resize_cubic(
      source,
      static_cast<std::uint32_t>(width),
      static_cast<std::uint32_t>(height));
}

pixel_rect scale_rect(
    const pixel_rect& reference,
    const std::uint32_t width,
    const std::uint32_t height,
    const std::uint32_t reference_width,
    const std::uint32_t reference_height) noexcept {
  const auto scale_x = static_cast<double>(width) / reference_width;
  const auto scale_y = static_cast<double>(height) / reference_height;
  const auto left = std::clamp(
      std::llround(reference.x * scale_x),
      std::int64_t{0},
      static_cast<std::int64_t>(width));
  const auto top = std::clamp(
      std::llround(reference.y * scale_y),
      std::int64_t{0},
      static_cast<std::int64_t>(height));
  const auto right = std::clamp(
      std::llround((reference.x + reference.width) * scale_x),
      left,
      static_cast<std::int64_t>(width));
  const auto bottom = std::clamp(
      std::llround((reference.y + reference.height) * scale_y),
      top,
      static_cast<std::int64_t>(height));
  return {
      .x = static_cast<std::uint32_t>(left),
      .y = static_cast<std::uint32_t>(top),
      .width = static_cast<std::uint32_t>(
          std::max(std::int64_t{1}, right - left)),
      .height = static_cast<std::uint32_t>(
          std::max(std::int64_t{1}, bottom - top)),
  };
}

}  // namespace sonar::fishing::stage_detection::detail
