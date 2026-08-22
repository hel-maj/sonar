#pragma once

#include "stage_image.h"

#include <cstdint>

namespace sonar::fishing::stage_detection::detail {

struct correlation_match final {
  std::uint32_t x{};
  std::uint32_t y{};
  double confidence{-1.0};
};

// Exact full-search normalized cross-correlation. FFT accelerates only the raw
// cross-correlation term; every output position receives its exact local mean
// and variance before selection.
[[nodiscard]] correlation_match best_normalized_correlation(
    const gray_image& search,
    const gray_image& templ);

}  // namespace sonar::fishing::stage_detection::detail
