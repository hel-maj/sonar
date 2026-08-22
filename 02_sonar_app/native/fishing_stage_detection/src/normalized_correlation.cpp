#include "normalized_correlation.h"

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <mutex>
#include <numbers>
#include <span>
#include <stdexcept>
#include <utility>
#include <vector>

namespace sonar::fishing::stage_detection::detail {
namespace {

using complex = std::complex<double>;

[[nodiscard]] std::size_t next_power_of_two(std::size_t value) {
  if (value == 0) {
    return 1;
  }
  --value;
  for (std::size_t shift = 1; shift < sizeof(value) * 8; shift <<= 1) {
    value |= value >> shift;
  }
  if (value == std::numeric_limits<std::size_t>::max()) {
    throw std::overflow_error("fishing_stage_fft_size_overflow");
  }
  return value + 1;
}

struct fft_stage final {
  std::size_t length{};
  std::vector<complex> factors;
};

struct fft_plan final {
  std::size_t count{};
  bool inverse{};
  std::vector<fft_stage> stages;
};

[[nodiscard]] fft_plan make_fft_plan(
    const std::size_t count,
    const bool inverse) {
  fft_plan plan{.count = count, .inverse = inverse};
  for (std::size_t length = 2; length <= count; length <<= 1) {
    const auto half = length / 2;
    fft_stage stage{.length = length};
    stage.factors.reserve(half);
    const auto angle_step = 2.0 * std::numbers::pi_v<double> /
        static_cast<double>(length) * (inverse ? 1.0 : -1.0);
    for (std::size_t item = 0; item < half; ++item) {
      const auto angle = angle_step * static_cast<double>(item);
      stage.factors.emplace_back(std::cos(angle), std::sin(angle));
    }
    plan.stages.push_back(std::move(stage));
    if (length > count / 2) {
      break;
    }
  }
  return plan;
}

void fft_1d(std::span<complex> values, const fft_plan& plan) {
  const auto count = values.size();
  if (count != plan.count) {
    throw std::invalid_argument("fishing_stage_fft_plan_mismatch");
  }
  for (std::size_t index = 1, reversed = 0; index < count; ++index) {
    auto bit = count >> 1;
    for (; (reversed & bit) != 0; bit >>= 1) {
      reversed ^= bit;
    }
    reversed ^= bit;
    if (index < reversed) {
      std::swap(values[index], values[reversed]);
    }
  }
  for (const auto& stage : plan.stages) {
    const auto length = stage.length;
    for (std::size_t offset = 0; offset < count; offset += length) {
      const auto half = length / 2;
      for (std::size_t item = 0; item < half; ++item) {
        const auto even = values[offset + item];
        const auto odd = values[offset + item + half] * stage.factors[item];
        values[offset + item] = even + odd;
        values[offset + item + half] = even - odd;
      }
    }
  }
  if (plan.inverse) {
    const auto divisor = static_cast<double>(count);
    for (auto& value : values) {
      value /= divisor;
    }
  }
}

void fft_2d(
    std::vector<complex>& values,
    const std::size_t width,
    const std::size_t height,
    const bool inverse) {
  const auto row_plan = make_fft_plan(width, inverse);
  const auto column_plan = make_fft_plan(height, inverse);
  for (std::size_t y = 0; y < height; ++y) {
    fft_1d(
        std::span<complex>(values).subspan(y * width, width), row_plan);
  }
  std::vector<complex> column(height);
  for (std::size_t x = 0; x < width; ++x) {
    for (std::size_t y = 0; y < height; ++y) {
      column[y] = values[y * width + x];
    }
    fft_1d(column, column_plan);
    for (std::size_t y = 0; y < height; ++y) {
      values[y * width + x] = column[y];
    }
  }
}

struct prepared_template final {
  std::size_t fft_width{};
  std::size_t fft_height{};
  std::uint64_t sum{};
  double variance{};
  std::vector<complex> frequency;
};

struct template_cache_key final {
  std::uint32_t search_width{};
  std::uint32_t search_height{};
  std::uint32_t template_width{};
  std::uint32_t template_height{};
  std::uint64_t pixel_hash{};

  [[nodiscard]] bool operator==(
      const template_cache_key&) const noexcept = default;
};

[[nodiscard]] std::uint64_t stable_pixel_hash(
    const gray_image& image) noexcept {
  std::uint64_t value = 14695981039346656037ULL;
  for (const auto pixel : image.pixels) {
    value ^= pixel;
    value *= 1099511628211ULL;
  }
  return value;
}

[[nodiscard]] std::shared_ptr<const prepared_template> build_prepared_template(
    const gray_image& search,
    const gray_image& templ) {
  auto result = std::make_shared<prepared_template>();
  result->fft_width = next_power_of_two(
      static_cast<std::size_t>(search.width) + templ.width - 1);
  result->fft_height = next_power_of_two(
      static_cast<std::size_t>(search.height) + templ.height - 1);
  if (result->fft_width > std::numeric_limits<std::size_t>::max() /
      result->fft_height) {
    throw std::overflow_error("fishing_stage_fft_area_overflow");
  }
  result->frequency.resize(result->fft_width * result->fft_height);
  std::uint64_t square_sum = 0;
  for (std::uint32_t y = 0; y < templ.height; ++y) {
    for (std::uint32_t x = 0; x < templ.width; ++x) {
      const auto value = templ.at(x, y);
      result->sum += value;
      square_sum += static_cast<std::uint64_t>(value) * value;
      const auto reverse_x = templ.width - x - 1;
      const auto reverse_y = templ.height - y - 1;
      result->frequency[
          static_cast<std::size_t>(reverse_y) * result->fft_width +
          reverse_x] = static_cast<double>(value);
    }
  }
  const auto sample_count = static_cast<double>(templ.width) * templ.height;
  result->variance = static_cast<double>(square_sum) -
      static_cast<double>(result->sum) * result->sum / sample_count;
  fft_2d(
      result->frequency,
      result->fft_width,
      result->fft_height,
      false);
  return result;
}

[[nodiscard]] std::shared_ptr<const prepared_template> prepare_template(
    const gray_image& search,
    const gray_image& templ) {
  // Only the two large tension templates demonstrate a material repeated FFT
  // cost. Keep their read-only spectra in a tiny bounded cache; small stage
  // templates remain allocation-local and do not grow process residency.
  constexpr std::size_t kCacheThresholdPixels = 30'000;
  constexpr std::size_t kMaximumCacheEntries = 4;
  if (templ.pixels.size() < kCacheThresholdPixels) {
    return build_prepared_template(search, templ);
  }
  const template_cache_key key{
      .search_width = search.width,
      .search_height = search.height,
      .template_width = templ.width,
      .template_height = templ.height,
      .pixel_hash = stable_pixel_hash(templ),
  };
  using cache_entry =
      std::pair<template_cache_key, std::shared_ptr<const prepared_template>>;
  static std::mutex cache_mutex;
  static std::vector<cache_entry> cache;
  {
    const std::scoped_lock lock(cache_mutex);
    const auto found = std::ranges::find(cache, key, &cache_entry::first);
    if (found != cache.end()) {
      return found->second;
    }
  }
  const auto prepared = build_prepared_template(search, templ);
  {
    const std::scoped_lock lock(cache_mutex);
    const auto raced = std::ranges::find(cache, key, &cache_entry::first);
    if (raced != cache.end()) {
      return raced->second;
    }
    if (cache.size() == kMaximumCacheEntries) {
      cache.erase(cache.begin());
    }
    cache.emplace_back(key, prepared);
  }
  return prepared;
}

struct integral_pair final {
  std::size_t stride{};
  std::vector<std::uint64_t> sum;
  std::vector<std::uint64_t> square_sum;
};

[[nodiscard]] integral_pair build_integrals(const gray_image& image) {
  integral_pair result{
      .stride = static_cast<std::size_t>(image.width) + 1,
      .sum = std::vector<std::uint64_t>(
          (static_cast<std::size_t>(image.width) + 1) *
          (static_cast<std::size_t>(image.height) + 1)),
      .square_sum = std::vector<std::uint64_t>(
          (static_cast<std::size_t>(image.width) + 1) *
          (static_cast<std::size_t>(image.height) + 1)),
  };
  for (std::uint32_t y = 0; y < image.height; ++y) {
    std::uint64_t row_sum = 0;
    std::uint64_t row_square_sum = 0;
    for (std::uint32_t x = 0; x < image.width; ++x) {
      const auto value = image.at(x, y);
      row_sum += value;
      row_square_sum += static_cast<std::uint64_t>(value) * value;
      const auto target = (static_cast<std::size_t>(y) + 1) * result.stride +
          x + 1;
      result.sum[target] = result.sum[target - result.stride] + row_sum;
      result.square_sum[target] =
          result.square_sum[target - result.stride] + row_square_sum;
    }
  }
  return result;
}

[[nodiscard]] std::uint64_t rectangle_sum(
    const std::vector<std::uint64_t>& integral,
    const std::size_t stride,
    const std::uint32_t x,
    const std::uint32_t y,
    const std::uint32_t width,
    const std::uint32_t height) noexcept {
  const auto left = static_cast<std::size_t>(x);
  const auto top = static_cast<std::size_t>(y);
  const auto right = left + width;
  const auto bottom = top + height;
  return integral[bottom * stride + right] -
      integral[top * stride + right] -
      integral[bottom * stride + left] +
      integral[top * stride + left];
}

}  // namespace

correlation_match best_normalized_correlation(
    const gray_image& search,
    const gray_image& templ) {
  if (!search.valid() || !templ.valid() ||
      templ.width > search.width || templ.height > search.height) {
    throw std::invalid_argument("fishing_stage_correlation_input_invalid");
  }
  const auto prepared = prepare_template(search, templ);
  const auto fft_width = prepared->fft_width;
  const auto fft_height = prepared->fft_height;
  const auto fft_area = fft_width * fft_height;
  std::vector<complex> image_frequency(fft_area);
  for (std::uint32_t y = 0; y < search.height; ++y) {
    for (std::uint32_t x = 0; x < search.width; ++x) {
      image_frequency[static_cast<std::size_t>(y) * fft_width + x] =
          static_cast<double>(search.at(x, y));
    }
  }
  fft_2d(image_frequency, fft_width, fft_height, false);
  for (std::size_t index = 0; index < fft_area; ++index) {
    image_frequency[index] *= prepared->frequency[index];
  }
  fft_2d(image_frequency, fft_width, fft_height, true);

  const auto integrals = build_integrals(search);
  const auto sample_count = static_cast<double>(templ.width) * templ.height;
  if (prepared->variance <= std::numeric_limits<double>::epsilon()) {
    return {};
  }

  correlation_match best;
  const auto positions_x = search.width - templ.width + 1;
  const auto positions_y = search.height - templ.height + 1;
  for (std::uint32_t y = 0; y < positions_y; ++y) {
    for (std::uint32_t x = 0; x < positions_x; ++x) {
      const auto window_sum = rectangle_sum(
          integrals.sum,
          integrals.stride,
          x,
          y,
          templ.width,
          templ.height);
      const auto window_square_sum = rectangle_sum(
          integrals.square_sum,
          integrals.stride,
          x,
          y,
          templ.width,
          templ.height);
      const auto window_variance =
          static_cast<double>(window_square_sum) -
          static_cast<double>(window_sum) * window_sum / sample_count;
      if (window_variance <= std::numeric_limits<double>::epsilon()) {
        continue;
      }
      const auto raw = image_frequency[
          (static_cast<std::size_t>(y) + templ.height - 1) * fft_width +
          x + templ.width - 1].real();
      const auto centered = raw -
          static_cast<double>(window_sum) * prepared->sum / sample_count;
      const auto denominator = std::sqrt(
          window_variance * prepared->variance);
      const auto confidence = std::clamp(centered / denominator, -1.0, 1.0);
      if (confidence > best.confidence) {
        best = {.x = x, .y = y, .confidence = confidence};
      }
    }
  }
  return best;
}

}  // namespace sonar::fishing::stage_detection::detail
