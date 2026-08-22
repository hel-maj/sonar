#include "chat_image_ops.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <queue>
#include <stdexcept>
#include <utility>

namespace sonar::fishing::game_chat::detail {
namespace {

[[nodiscard]] std::size_t index_of(
    const std::uint32_t width,
    const std::uint32_t x,
    const std::uint32_t y) noexcept {
  return static_cast<std::size_t>(y) * width + x;
}

[[nodiscard]] std::uint8_t bgr_gray(
    const std::uint8_t blue,
    const std::uint8_t green,
    const std::uint8_t red) noexcept {
  constexpr int kBlueWeight = 1868;
  constexpr int kGreenWeight = 9617;
  constexpr int kRedWeight = 4899;
  constexpr int kRound = 1 << 13;
  return static_cast<std::uint8_t>(
      (blue * kBlueWeight + green * kGreenWeight + red * kRedWeight +
       kRound) >> 14);
}

[[nodiscard]] int clamped_coordinate(
    const int value,
    const int maximum) noexcept {
  return std::clamp(value, 0, maximum - 1);
}

[[nodiscard]] byte_image dilate(
    const byte_image& source,
    const std::uint32_t kernel_width,
    const std::uint32_t kernel_height) {
  byte_image result{
      .width = source.width,
      .height = source.height,
      .pixels = std::vector<std::uint8_t>(source.pixels.size()),
  };
  const auto anchor_x = static_cast<int>(kernel_width / 2);
  const auto anchor_y = static_cast<int>(kernel_height / 2);
  for (std::uint32_t y = 0; y < source.height; ++y) {
    for (std::uint32_t x = 0; x < source.width; ++x) {
      bool found = false;
      for (std::uint32_t ky = 0; ky < kernel_height && !found; ++ky) {
        const auto source_y = static_cast<int>(y) +
            static_cast<int>(ky) - anchor_y;
        if (source_y < 0 || source_y >= static_cast<int>(source.height)) {
          continue;
        }
        for (std::uint32_t kx = 0; kx < kernel_width; ++kx) {
          const auto source_x = static_cast<int>(x) +
              static_cast<int>(kx) - anchor_x;
          if (source_x >= 0 && source_x < static_cast<int>(source.width) &&
              source.at(
                  static_cast<std::uint32_t>(source_x),
                  static_cast<std::uint32_t>(source_y)) != 0) {
            found = true;
            break;
          }
        }
      }
      result.pixels[index_of(result.width, x, y)] = found ? 255 : 0;
    }
  }
  return result;
}

[[nodiscard]] byte_image erode(
    const byte_image& source,
    const std::uint32_t kernel_width,
    const std::uint32_t kernel_height) {
  byte_image result{
      .width = source.width,
      .height = source.height,
      .pixels = std::vector<std::uint8_t>(source.pixels.size()),
  };
  const auto anchor_x = static_cast<int>(kernel_width / 2);
  const auto anchor_y = static_cast<int>(kernel_height / 2);
  for (std::uint32_t y = 0; y < source.height; ++y) {
    for (std::uint32_t x = 0; x < source.width; ++x) {
      bool retained = true;
      for (std::uint32_t ky = 0; ky < kernel_height && retained; ++ky) {
        const auto source_y = static_cast<int>(y) +
            static_cast<int>(ky) - anchor_y;
        if (source_y < 0 || source_y >= static_cast<int>(source.height)) {
          continue;
        }
        for (std::uint32_t kx = 0; kx < kernel_width; ++kx) {
          const auto source_x = static_cast<int>(x) +
              static_cast<int>(kx) - anchor_x;
          if (source_x < 0 || source_x >= static_cast<int>(source.width)) {
            continue;
          }
          if (source.at(
                  static_cast<std::uint32_t>(source_x),
                  static_cast<std::uint32_t>(source_y)) == 0) {
            retained = false;
            break;
          }
        }
      }
      result.pixels[index_of(result.width, x, y)] = retained ? 255 : 0;
    }
  }
  return result;
}

struct hsv_pixel final {
  double hue{};
  double saturation{};
  std::uint8_t value{};
};

[[nodiscard]] hsv_pixel to_hsv(
    const std::uint8_t blue,
    const std::uint8_t green,
    const std::uint8_t red) noexcept {
  const auto maximum = std::max({blue, green, red});
  const auto minimum = std::min({blue, green, red});
  const auto delta = static_cast<double>(maximum - minimum);
  double hue_degrees = 0.0;
  if (delta != 0.0) {
    if (maximum == red) {
      hue_degrees = 60.0 *
          (static_cast<double>(green) - blue) / delta;
      if (hue_degrees < 0.0) {
        hue_degrees += 360.0;
      }
    } else if (maximum == green) {
      hue_degrees = 60.0 *
          (2.0 + (static_cast<double>(blue) - red) / delta);
    } else {
      hue_degrees = 60.0 *
          (4.0 + (static_cast<double>(red) - green) / delta);
    }
  }
  return {
      .hue = hue_degrees / 2.0,
      .saturation = maximum == 0
          ? 0.0
          : delta * 255.0 / static_cast<double>(maximum),
      .value = maximum,
  };
}

template <typename Predicate>
[[nodiscard]] byte_image color_mask(
    const chat_frame& frame,
    const pixel_rect& bounds,
    Predicate predicate) {
  byte_image result{
      .width = bounds.width,
      .height = bounds.height,
      .pixels = std::vector<std::uint8_t>(
          static_cast<std::size_t>(bounds.width) * bounds.height),
  };
  for (std::uint32_t y = 0; y < bounds.height; ++y) {
    const auto source_row = static_cast<std::size_t>(bounds.y + y) *
        frame.stride_bytes;
    for (std::uint32_t x = 0; x < bounds.width; ++x) {
      const auto source = source_row +
          static_cast<std::size_t>(bounds.x + x) * 3;
      const auto hsv = to_hsv(
          frame.bgr24[source],
          frame.bgr24[source + 1],
          frame.bgr24[source + 2]);
      result.pixels[index_of(result.width, x, y)] =
          predicate(hsv) ? 255 : 0;
    }
  }
  return result;
}

}  // namespace

std::uint8_t byte_image::at(
    const std::uint32_t x,
    const std::uint32_t y) const noexcept {
  return pixels[index_of(width, x, y)];
}

byte_image grayscale(const chat_frame& frame) {
  if (!frame.valid()) {
    throw std::invalid_argument("chat_detector_frame_invalid");
  }
  byte_image result{
      .width = frame.width,
      .height = frame.height,
      .pixels = std::vector<std::uint8_t>(
          static_cast<std::size_t>(frame.width) * frame.height),
  };
  for (std::uint32_t y = 0; y < frame.height; ++y) {
    const auto source_row = static_cast<std::size_t>(y) * frame.stride_bytes;
    for (std::uint32_t x = 0; x < frame.width; ++x) {
      const auto source = source_row + static_cast<std::size_t>(x) * 3;
      result.pixels[index_of(result.width, x, y)] = bgr_gray(
          frame.bgr24[source],
          frame.bgr24[source + 1],
          frame.bgr24[source + 2]);
    }
  }
  return result;
}

byte_image canny_edges(
    const byte_image& source,
    const int low_threshold,
    const int high_threshold) {
  if (source.width < 3 || source.height < 3 ||
      low_threshold < 0 || high_threshold <= low_threshold) {
    throw std::invalid_argument("chat_detector_canny_invalid");
  }
  const auto count = static_cast<std::size_t>(source.width) * source.height;
  std::vector<int> dx(count);
  std::vector<int> dy(count);
  std::vector<int> magnitude(count);
  const auto maximum_x = static_cast<int>(source.width);
  const auto maximum_y = static_cast<int>(source.height);
  for (int y = 0; y < maximum_y; ++y) {
    const auto y0 = clamped_coordinate(y - 1, maximum_y);
    const auto y1 = y;
    const auto y2 = clamped_coordinate(y + 1, maximum_y);
    for (int x = 0; x < maximum_x; ++x) {
      const auto x0 = clamped_coordinate(x - 1, maximum_x);
      const auto x2 = clamped_coordinate(x + 1, maximum_x);
      const auto p00 = source.at(x0, y0);
      const auto p01 = source.at(x, y0);
      const auto p02 = source.at(x2, y0);
      const auto p10 = source.at(x0, y1);
      const auto p12 = source.at(x2, y1);
      const auto p20 = source.at(x0, y2);
      const auto p21 = source.at(x, y2);
      const auto p22 = source.at(x2, y2);
      const auto index = index_of(
          source.width,
          static_cast<std::uint32_t>(x),
          static_cast<std::uint32_t>(y));
      dx[index] = -p00 + p02 - 2 * p10 + 2 * p12 - p20 + p22;
      dy[index] = -p00 - 2 * p01 - p02 + p20 + 2 * p21 + p22;
      magnitude[index] = std::abs(dx[index]) + std::abs(dy[index]);
    }
  }

  std::vector<std::uint8_t> edge_state(count);
  std::queue<std::size_t> strong;
  constexpr int kTangent22 = 13573;
  for (std::uint32_t y = 1; y + 1 < source.height; ++y) {
    for (std::uint32_t x = 1; x + 1 < source.width; ++x) {
      const auto index = index_of(source.width, x, y);
      const auto current = magnitude[index];
      if (current <= low_threshold) {
        continue;
      }
      const auto absolute_x = std::abs(dx[index]);
      const auto absolute_y = std::abs(dy[index]) << 15;
      const auto tangent22 = absolute_x * kTangent22;
      int previous{};
      int next{};
      if (absolute_y < tangent22) {
        previous = magnitude[index - 1];
        next = magnitude[index + 1];
      } else if (absolute_y > tangent22 + (absolute_x << 16)) {
        previous = magnitude[index - source.width];
        next = magnitude[index + source.width];
      } else {
        const auto step = (dx[index] ^ dy[index]) < 0
            ? static_cast<std::ptrdiff_t>(source.width) - 1
            : static_cast<std::ptrdiff_t>(source.width) + 1;
        previous = magnitude[static_cast<std::size_t>(
            static_cast<std::ptrdiff_t>(index) - step)];
        next = magnitude[static_cast<std::size_t>(
            static_cast<std::ptrdiff_t>(index) + step)];
      }
      if (current > previous && current >= next) {
        edge_state[index] = current > high_threshold ? 2 : 1;
        if (edge_state[index] == 2) {
          strong.push(index);
        }
      }
    }
  }

  while (!strong.empty()) {
    const auto index = strong.front();
    strong.pop();
    const auto y = static_cast<std::uint32_t>(index / source.width);
    const auto x = static_cast<std::uint32_t>(index % source.width);
    for (int offset_y = -1; offset_y <= 1; ++offset_y) {
      for (int offset_x = -1; offset_x <= 1; ++offset_x) {
        if (offset_x == 0 && offset_y == 0) {
          continue;
        }
        const auto neighbor_x = static_cast<int>(x) + offset_x;
        const auto neighbor_y = static_cast<int>(y) + offset_y;
        if (neighbor_x <= 0 || neighbor_y <= 0 ||
            neighbor_x >= maximum_x - 1 || neighbor_y >= maximum_y - 1) {
          continue;
        }
        const auto neighbor = index_of(
            source.width,
            static_cast<std::uint32_t>(neighbor_x),
            static_cast<std::uint32_t>(neighbor_y));
        if (edge_state[neighbor] == 1) {
          edge_state[neighbor] = 2;
          strong.push(neighbor);
        }
      }
    }
  }

  byte_image result{
      .width = source.width,
      .height = source.height,
      .pixels = std::vector<std::uint8_t>(count),
  };
  for (std::size_t index = 0; index < count; ++index) {
    result.pixels[index] = edge_state[index] == 2 ? 255 : 0;
  }
  return result;
}

byte_image morphological_close(
    const byte_image& source,
    const std::uint32_t kernel_width,
    const std::uint32_t kernel_height) {
  if (kernel_width == 0 || kernel_height == 0) {
    throw std::invalid_argument("chat_detector_kernel_invalid");
  }
  return erode(
      dilate(source, kernel_width, kernel_height),
      kernel_width,
      kernel_height);
}

std::vector<binary_component> connected_components(byte_image source) {
  std::vector<binary_component> result;
  std::vector<std::size_t> pending;
  for (std::uint32_t y = 0; y < source.height; ++y) {
    for (std::uint32_t x = 0; x < source.width; ++x) {
      const auto first = index_of(source.width, x, y);
      if (source.pixels[first] == 0) {
        continue;
      }
      source.pixels[first] = 0;
      pending.clear();
      pending.push_back(first);
      auto left = x;
      auto right = x;
      auto top = y;
      auto bottom = y;
      std::size_t area = 0;
      while (!pending.empty()) {
        const auto current = pending.back();
        pending.pop_back();
        ++area;
        const auto current_y = static_cast<std::uint32_t>(
            current / source.width);
        const auto current_x = static_cast<std::uint32_t>(
            current % source.width);
        left = std::min(left, current_x);
        right = std::max(right, current_x);
        top = std::min(top, current_y);
        bottom = std::max(bottom, current_y);
        for (int offset_y = -1; offset_y <= 1; ++offset_y) {
          for (int offset_x = -1; offset_x <= 1; ++offset_x) {
            if (offset_x == 0 && offset_y == 0) {
              continue;
            }
            const auto neighbor_x = static_cast<int>(current_x) + offset_x;
            const auto neighbor_y = static_cast<int>(current_y) + offset_y;
            if (neighbor_x < 0 || neighbor_y < 0 ||
                neighbor_x >= static_cast<int>(source.width) ||
                neighbor_y >= static_cast<int>(source.height)) {
              continue;
            }
            const auto neighbor = index_of(
                source.width,
                static_cast<std::uint32_t>(neighbor_x),
                static_cast<std::uint32_t>(neighbor_y));
            if (source.pixels[neighbor] != 0) {
              source.pixels[neighbor] = 0;
              pending.push_back(neighbor);
            }
          }
        }
      }
      result.push_back({
          .x = left,
          .y = top,
          .width = right - left + 1,
          .height = bottom - top + 1,
          .area = area,
      });
    }
  }
  return result;
}

byte_image crop(const byte_image& source, const pixel_rect& bounds) {
  if (bounds.width == 0 || bounds.height == 0 ||
      bounds.x > source.width || bounds.y > source.height ||
      bounds.width > source.width - bounds.x ||
      bounds.height > source.height - bounds.y) {
    throw std::invalid_argument("chat_detector_crop_invalid");
  }
  byte_image result{
      .width = bounds.width,
      .height = bounds.height,
      .pixels = std::vector<std::uint8_t>(
          static_cast<std::size_t>(bounds.width) * bounds.height),
  };
  for (std::uint32_t y = 0; y < bounds.height; ++y) {
    const auto source_offset = index_of(
        source.width, bounds.x, bounds.y + y);
    const auto destination_offset = index_of(result.width, 0, y);
    std::copy_n(
        source.pixels.begin() + static_cast<std::ptrdiff_t>(source_offset),
        bounds.width,
        result.pixels.begin() + static_cast<std::ptrdiff_t>(destination_offset));
  }
  return result;
}

double mean(const byte_image& source, const pixel_rect& bounds) noexcept {
  if (bounds.width == 0 || bounds.height == 0 ||
      bounds.x >= source.width || bounds.y >= source.height ||
      bounds.width > source.width - bounds.x ||
      bounds.height > source.height - bounds.y) {
    return std::numeric_limits<double>::quiet_NaN();
  }
  std::uint64_t total = 0;
  for (std::uint32_t y = bounds.y; y < bounds.y + bounds.height; ++y) {
    for (std::uint32_t x = bounds.x; x < bounds.x + bounds.width; ++x) {
      total += source.at(x, y);
    }
  }
  return static_cast<double>(total) /
      static_cast<double>(bounds.width * bounds.height);
}

double nonzero_ratio(const byte_image& source) noexcept {
  if (source.pixels.empty()) {
    return 0.0;
  }
  const auto count = static_cast<std::size_t>(std::count_if(
      source.pixels.begin(), source.pixels.end(),
      [](const std::uint8_t value) { return value != 0; }));
  return static_cast<double>(count) /
      static_cast<double>(source.pixels.size());
}

byte_image red_hsv_mask(
    const chat_frame& frame,
    const pixel_rect& bounds) {
  return color_mask(frame, bounds, [](const hsv_pixel& pixel) {
    return (pixel.hue >= 155.0 || pixel.hue <= 5.0) &&
        pixel.saturation >= 60.0 && pixel.value >= 55;
  });
}

byte_image light_low_saturation_mask(
    const chat_frame& frame,
    const pixel_rect& bounds,
    const std::uint8_t minimum_value,
    const std::uint8_t maximum_saturation) {
  return color_mask(frame, bounds, [=](const hsv_pixel& pixel) {
    return pixel.value > minimum_value &&
        pixel.saturation < maximum_saturation;
  });
}

}  // namespace sonar::fishing::game_chat::detail
