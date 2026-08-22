#include "sonar/fishing/stage_detection/fishing_stage_detector.h"

#include "normalized_correlation.h"
#include "stage_image.h"
#include "stage_template_catalog.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>
#include <set>
#include <stdexcept>
#include <string_view>
#include <utility>
#include <vector>

namespace sonar::fishing::stage_detection {
namespace {

using detail::gray_image;
using detail::pixel_rect;
using detail::stage_resolution_profile;
using detail::stage_template_catalog;

constexpr std::uint32_t kFullHdWidth = 1920;
constexpr std::uint32_t kFullHdHeight = 1080;
constexpr std::uint32_t kTwoKWidth = 2560;
constexpr std::uint32_t kTwoKHeight = 1440;

enum class roi_kind {
  stage,
  tension,
  reeling,
};

struct profile_geometry final {
  std::uint32_t width{};
  std::uint32_t height{};
  pixel_rect stage;
  pixel_rect tension;
  pixel_rect reeling;
};

constexpr profile_geometry kFullHdGeometry{
    .width = kFullHdWidth,
    .height = kFullHdHeight,
    .stage = {.x = 1535, .y = 1022, .width = 372, .height = 44},
    .tension = {.x = 1240, .y = 760, .width = 360, .height = 320},
    .reeling = {.x = 690, .y = 885, .width = 660, .height = 185},
};

constexpr profile_geometry kTwoKGeometry{
    .width = kTwoKWidth,
    .height = kTwoKHeight,
    .stage = {.x = 2052, .y = 1365, .width = 492, .height = 55},
    .tension = {.x = 1660, .y = 1010, .width = 470, .height = 420},
    .reeling = {.x = 920, .y = 1180, .width = 880, .height = 250},
};

struct normalized_search final {
  gray_image image;
  stage_resolution_profile profile{stage_resolution_profile::full_hd};
};

struct trigger_match final {
  std::uint32_t x{};
  std::uint32_t y{};
  std::uint32_t width{};
  std::uint32_t height{};
  double confidence{};
};

[[nodiscard]] stage_resolution_profile profile_for(
    const std::uint32_t width,
    const std::uint32_t height) noexcept {
  return width >= 2500 || height >= 1300
      ? stage_resolution_profile::two_k
      : stage_resolution_profile::full_hd;
}

[[nodiscard]] const profile_geometry& geometry_for(
    const stage_resolution_profile profile) noexcept {
  return profile == stage_resolution_profile::two_k
      ? kTwoKGeometry
      : kFullHdGeometry;
}

[[nodiscard]] normalized_search normalize_search(gray_image image) {
  const auto profile = profile_for(image.width, image.height);
  const auto& geometry = geometry_for(profile);
  const auto within_legacy_size =
      image.width <= static_cast<std::uint32_t>(geometry.width * 1.12) &&
      image.height <= static_cast<std::uint32_t>(geometry.height * 1.12);
  if (within_legacy_size) {
    return {.image = std::move(image), .profile = profile};
  }
  const auto aspect = static_cast<double>(image.width) / image.height;
  const auto reference_aspect =
      static_cast<double>(geometry.width) / geometry.height;
  const auto relative_aspect_error =
      std::abs(aspect - reference_aspect) / reference_aspect;
  if (relative_aspect_error > 0.025) {
    return {.image = std::move(image), .profile = profile};
  }
  return {
      .image = detail::resize_area(image, geometry.width, geometry.height),
      .profile = profile,
  };
}

[[nodiscard]] pixel_rect resolved_roi(
    const roi_kind kind,
    const normalized_search& search) noexcept {
  const auto& geometry = geometry_for(search.profile);
  const auto& reference = kind == roi_kind::stage
      ? geometry.stage
      : (kind == roi_kind::tension ? geometry.tension : geometry.reeling);
  return detail::scale_rect(
      reference,
      search.image.width,
      search.image.height,
      geometry.width,
      geometry.height);
}

[[nodiscard]] std::vector<double> template_scales(
    const normalized_search& search) {
  const auto& geometry = geometry_for(search.profile);
  const auto base = (
      static_cast<double>(search.image.width) / geometry.width +
      static_cast<double>(search.image.height) / geometry.height) / 2.0;
  if (std::abs(base - 1.0) <= 0.02) {
    return {1.0};
  }
  constexpr std::array factors{0.82, 0.90, 0.96, 1.0, 1.04, 1.10, 1.20};
  std::set<double> unique{1.0};
  for (const auto factor : factors) {
    const auto value = std::round(base * factor * 100.0) / 100.0;
    if (value >= 0.30 && value <= 3.25) {
      unique.insert(value);
    }
  }
  std::vector<double> result(unique.begin(), unique.end());
  const auto priority_base = result[result.size() / 2];
  std::ranges::sort(result, [=](const double left, const double right) {
    const auto left_distance = std::abs(left - priority_base);
    const auto right_distance = std::abs(right - priority_base);
    return left_distance == right_distance
        ? left < right
        : left_distance < right_distance;
  });
  return result;
}

[[nodiscard]] std::optional<trigger_match> find_trigger(
    const normalized_search& search,
    const gray_image& base_template,
    const roi_kind roi,
    const double threshold) {
  const auto bounds = resolved_roi(roi, search);
  const auto search_area = detail::crop(search.image, bounds);
  std::optional<trigger_match> best;
  for (const auto scale : template_scales(search)) {
    const auto templ = detail::resize_template(base_template, scale);
    if (templ.width > search_area.width || templ.height > search_area.height) {
      continue;
    }
    const auto match = detail::best_normalized_correlation(search_area, templ);
    if (match.confidence < threshold) {
      continue;
    }
    trigger_match candidate{
        .x = bounds.x + match.x,
        .y = bounds.y + match.y,
        .width = templ.width,
        .height = templ.height,
        .confidence = match.confidence,
    };
    if (!best.has_value() || candidate.confidence > best->confidence) {
      best = candidate;
      // Characterized legacy behavior stops scale search for a near-perfect
      // result. The full position search above is still exact for this scale.
      if (candidate.confidence >= 0.98) {
        return best;
      }
    }
  }
  return best;
}

[[nodiscard]] normalized_rect normalized_bounds(
    const trigger_match& match,
    const gray_image& image) noexcept {
  return {
      .x = static_cast<double>(match.x) / image.width,
      .y = static_cast<double>(match.y) / image.height,
      .width = static_cast<double>(match.width) / image.width,
      .height = static_cast<double>(match.height) / image.height,
  };
}

}  // namespace

bool bgr24_frame_view::valid() const noexcept {
  if (width == 0 || height == 0 ||
      width > std::numeric_limits<std::size_t>::max() / 3) {
    return false;
  }
  const auto minimum_stride = static_cast<std::size_t>(width) * 3;
  if (stride_bytes < minimum_stride ||
      height > std::numeric_limits<std::size_t>::max() / stride_bytes) {
    return false;
  }
  return pixels.size() >= stride_bytes * height;
}

stage_detection_result majestic_fishing_stage_detector::detect(
    const bgr24_frame_view& frame) const noexcept {
  if (!frame.valid()) {
    return {.error = "fishing_stage_frame_invalid"};
  }
  try {
    const auto search = normalize_search(detail::grayscale(frame));
    const auto& catalog = detail::stage_templates(search.profile);
    struct candidate final {
      std::string_view trigger;
      observed_fishing_stage stage;
      const gray_image* image;
      roi_kind roi;
      double threshold;
    };
    // This ordering is the legacy product's explicit stage authority.
    const std::array candidates{
        candidate{"ad", observed_fishing_stage::reeling,
                  &catalog.ad, roi_kind::reeling, 0.65},
        candidate{"start2", observed_fishing_stage::waiting_for_bite,
                  &catalog.hook, roi_kind::stage, 0.80},
        candidate{"wait_tension", observed_fishing_stage::waiting_for_bite,
                  &catalog.wait, roi_kind::tension, 0.75},
        candidate{"start1", observed_fishing_stage::casting,
                  &catalog.cast, roi_kind::stage, 0.80},
        candidate{"start", observed_fishing_stage::tackle_selection,
                  &catalog.start, roi_kind::stage, 0.80},
    };
    for (const auto& candidate : candidates) {
      const auto match = find_trigger(
          search,
          *candidate.image,
          candidate.roi,
          candidate.threshold);
      if (match.has_value()) {
        return {
            .observation = stage_observation{
                .stage = candidate.stage,
                .trigger_id = std::string(candidate.trigger),
                .confidence = match->confidence,
                .bounds = normalized_bounds(*match, search.image),
            },
        };
      }
    }
    return {};
  } catch (...) {
    return {.error = "fishing_stage_detector_failed"};
  }
}

std::string_view stage_key(const observed_fishing_stage stage) noexcept {
  switch (stage) {
    case observed_fishing_stage::none:
      return "none";
    case observed_fishing_stage::tackle_selection:
      return "tackle_selection";
    case observed_fishing_stage::casting:
      return "casting";
    case observed_fishing_stage::waiting_for_bite:
      return "waiting_for_bite";
    case observed_fishing_stage::reeling:
      return "reeling";
  }
  return "none";
}

}  // namespace sonar::fishing::stage_detection
