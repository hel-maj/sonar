#include "sonar/fishing/stage_detection/fishing_stage_detector.h"

#include "normalized_correlation.h"
#include "stage_image.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

namespace sonar::fishing::stage_detection {
namespace {

using detail::gray_image;
using detail::pixel_rect;

struct run final {
  std::uint16_t count{};
  std::uint8_t value{};
};

// Exact grayscale payload derived from the retired product templates
// bubles.png (Git blob b553194f...) and bubles_2k.png (1592d901...).
static constexpr std::array<run, 109> kBubbleFullHd{{
    {47,39},{1,69},{2,88},{1,69},{16,39},{1,69},{1,99},{2,104},{1,99},{1,69},
    {15,39},{1,96},{4,105},{1,96},{15,39},{1,102},{4,105},{1,102},{15,39},{1,82},
    {4,105},{1,82},{15,39},{1,47},{1,84},{2,103},{1,84},{1,47},{16,39},{1,47},
    {2,53},{1,47},{231,39},{1,62},{1,81},{2,89},{1,81},{1,62},{13,39},{1,46},
    {1,81},{1,98},{1,102},{2,105},{1,102},{1,98},{1,81},{1,46},{11,39},{1,82},
    {1,102},{6,105},{1,102},{1,82},{10,39},{1,62},{1,102},{8,105},{1,102},{1,62},
    {9,39},{1,87},{10,105},{1,87},{9,39},{1,101},{10,105},{1,101},{9,39},{1,104},
    {10,105},{1,104},{9,39},{1,94},{10,105},{1,94},{9,39},{1,74},{10,105},{1,74},
    {9,39},{1,45},{1,95},{8,105},{1,95},{1,45},{10,39},{1,57},{1,95},{6,105},
    {1,95},{1,57},{11,39},{1,41},{1,50},{1,77},{1,95},{2,104},{1,95},{1,77},
    {1,50},{1,41},{13,39},{1,45},{1,50},{2,53},{1,50},{1,45},{27,39},
}};

static constexpr std::array<run, 166> kBubbleTwoK{{
    {47,39},{1,41},{1,45},{2,49},{1,45},{1,41},{15,39},{1,41},{1,59},{1,87},
    {2,103},{1,87},{1,59},{1,41},{14,39},{1,57},{1,103},{4,105},{1,103},{1,57},
    {14,39},{1,87},{6,105},{1,87},{14,39},{1,102},{6,105},{1,103},{14,39},{1,100},
    {6,105},{1,100},{14,39},{1,80},{1,104},{4,105},{1,104},{1,80},{14,39},{1,50},
    {1,95},{1,102},{2,104},{1,102},{1,95},{1,50},{15,39},{1,50},{1,78},{2,93},
    {1,78},{1,50},{309,39},{1,40},{2,42},{1,41},{1,40},{15,39},{1,41},{1,45},
    {1,52},{1,63},{1,67},{1,66},{1,56},{1,47},{1,43},{12,39},{1,43},{1,60},
    {1,86},{5,105},{1,93},{1,69},{1,45},{10,39},{1,43},{1,74},{9,105},{1,86},
    {1,47},{8,39},{1,41},{1,74},{11,105},{1,88},{1,43},{7,39},{1,57},{13,105},
    {1,76},{1,40},{5,39},{1,40},{1,86},{13,105},{1,103},{1,45},{5,39},{1,45},
    {15,105},{1,66},{5,39},{1,57},{15,105},{1,77},{5,39},{1,60},{15,105},{1,82},
    {5,39},{1,57},{15,105},{1,78},{5,39},{1,47},{1,103},{14,105},{1,66},{6,39},
    {1,87},{13,105},{1,102},{1,49},{6,39},{1,60},{1,102},{11,105},{1,104},{1,77},
    {8,39},{1,77},{1,102},{9,105},{1,104},{1,93},{1,46},{8,39},{1,40},{1,78},
    {1,100},{1,104},{6,105},{1,102},{1,92},{1,52},{11,39},{1,67},{1,94},{1,99},
    {1,100},{1,102},{1,101},{1,100},{1,97},{1,76},{1,46},{13,39},{1,41},{1,59},
    {1,71},{1,76},{1,75},{1,64},{1,49},{50,39},
}};

[[nodiscard]] gray_image expand(
    const std::span<const run> payload,
    const std::uint32_t width,
    const std::uint32_t height) {
  gray_image result{.width = width, .height = height};
  result.pixels.reserve(static_cast<std::size_t>(width) * height);
  for (const auto item : payload) {
    result.pixels.insert(result.pixels.end(), item.count, item.value);
  }
  if (!result.valid()) {
    throw std::runtime_error("fishing_bubble_template_invalid");
  }
  return result;
}

[[nodiscard]] const gray_image& bubble_template(const bool two_k) {
  static const auto full_hd = expand(kBubbleFullHd, 21U, 33U);
  static const auto two_k_image = expand(kBubbleTwoK, 22U, 44U);
  return two_k ? two_k_image : full_hd;
}

[[nodiscard]] pixel_rect bubble_roi(
    const std::uint32_t width,
    const std::uint32_t height) noexcept {
  // The two characterized legacy rectangles differ by less than 0.15% of the
  // client area. Their union remains normalized and resolution-independent.
  const auto left = static_cast<std::uint32_t>(std::llround(width * 0.705));
  const auto top = static_cast<std::uint32_t>(std::llround(height * 0.792));
  const auto right = static_cast<std::uint32_t>(std::llround(width * 0.742));
  const auto bottom = static_cast<std::uint32_t>(std::llround(height * 0.854));
  return {
      .x = (std::min)(left, width - 1U),
      .y = (std::min)(top, height - 1U),
      .width = (std::max)(1U, (std::min)(right, width) - (std::min)(left, width - 1U)),
      .height = (std::max)(1U, (std::min)(bottom, height) - (std::min)(top, height - 1U)),
  };
}

[[nodiscard]] std::vector<double> scales_for(
    const std::uint32_t width,
    const std::uint32_t height,
    const bool two_k) {
  const double reference_width = two_k ? 2560.0 : 1920.0;
  const double reference_height = two_k ? 1440.0 : 1080.0;
  const double base = (width / reference_width + height / reference_height) / 2.0;
  constexpr std::array factors{0.82, 0.90, 0.96, 1.0, 1.04, 1.10, 1.20};
  std::set<double> unique;
  for (const auto factor : factors) {
    const double scale = std::round(base * factor * 100.0) / 100.0;
    if (scale >= 0.30 && scale <= 3.25) {
      unique.insert(scale);
    }
  }
  return {unique.begin(), unique.end()};
}

}  // namespace

bubble_cue_detection_result majestic_bubble_cue_detector::detect(
    const bgr24_frame_view& frame) const noexcept {
  if (!frame.valid()) {
    return {.error = "fishing_bubble_frame_invalid"};
  }
  try {
    const bool two_k = frame.width >= 2500U || frame.height >= 1300U;
    const auto image = detail::grayscale(frame);
    const auto roi = bubble_roi(image.width, image.height);
    const auto search = detail::crop(image, roi);
    std::optional<bubble_cue_observation> best;
    for (const auto scale : scales_for(image.width, image.height, two_k)) {
      const auto templ = detail::resize_template(bubble_template(two_k), scale);
      if (templ.width > search.width || templ.height > search.height) {
        continue;
      }
      const auto match = detail::best_normalized_correlation(search, templ);
      if (match.confidence < 0.85) {
        continue;
      }
      const bubble_cue_observation candidate{
          .confidence = match.confidence,
          .bounds = {
              .x = static_cast<double>(roi.x + match.x) / image.width,
              .y = static_cast<double>(roi.y + match.y) / image.height,
              .width = static_cast<double>(templ.width) / image.width,
              .height = static_cast<double>(templ.height) / image.height,
          },
      };
      if (!best.has_value() || candidate.confidence > best->confidence) {
        best = candidate;
      }
    }
    return {.observation = std::move(best)};
  } catch (...) {
    return {.error = "fishing_bubble_detector_failed"};
  }
}

}  // namespace sonar::fishing::stage_detection
