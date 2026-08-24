#include "inventory_state_characterization.h"

#include <algorithm>
#include <cmath>
#include <iterator>
#include <limits>
#include <utility>

namespace sonar::fishing::build_profile_compatibility_probe {
namespace {

[[nodiscard]] bool stronger_candidate(
    const inventory_candidate& left,
    const inventory_candidate& right) noexcept {
  const auto left_delta = std::abs(
      static_cast<int>(left.open_value) - left.closed_value);
  const auto right_delta = std::abs(
      static_cast<int>(right.open_value) - right.closed_value);
  if (left_delta != right_delta) {
    return left_delta > right_delta;
  }
  if (left.region_size != right.region_size) {
    return left.region_size < right.region_size;
  }
  return left.address < right.address;
}

void retain_strongest(
    std::vector<inventory_candidate>& candidates,
    const std::size_t limit) {
  std::ranges::sort(candidates, stronger_candidate);
  if (candidates.size() > limit) {
    candidates.resize(limit);
  }
}

}  // namespace

bool inventory_candidate_result::ready() const noexcept {
  return reason.empty() && !candidates.empty();
}

inventory_candidate_result discover_inventory_candidates(
    const std::vector<inventory_region_image>& closed,
    const std::vector<inventory_region_image>& open,
    const inventory_characterization_policy& policy) {
  if (closed.empty() || closed.size() != open.size() ||
      policy.maximum_candidates == 0U ||
      policy.maximum_candidates_per_region == 0U ||
      policy.maximum_candidates_per_page == 0U) {
    return {.reason = "inventory_characterization_snapshot_invalid"};
  }
  std::vector<inventory_candidate> discovered;
  for (std::size_t region_index = 0U;
       region_index < closed.size();
       ++region_index) {
    const auto& before = closed[region_index];
    const auto& after = open[region_index];
    if (before.address == 0U || before.address != after.address ||
        before.bytes.empty() || before.bytes.size() != after.bytes.size() ||
        before.bytes.size() - 1U >
            (std::numeric_limits<std::uintptr_t>::max)() - before.address) {
      return {.reason = "inventory_characterization_region_drift"};
    }
    std::vector<inventory_candidate> page_candidates;
    std::vector<inventory_candidate> region_candidates;
    auto active_page = before.address & ~std::uintptr_t{0xFFFU};
    const auto flush_page = [&]() {
      retain_strongest(
          page_candidates, policy.maximum_candidates_per_page);
      region_candidates.insert(
          region_candidates.end(),
          std::make_move_iterator(page_candidates.begin()),
          std::make_move_iterator(page_candidates.end()));
      page_candidates.clear();
    };
    for (std::size_t offset = 0U;
         offset < before.bytes.size();
         ++offset) {
      const auto address = before.address + offset;
      const auto page = address & ~std::uintptr_t{0xFFFU};
      if (page != active_page) {
        flush_page();
        active_page = page;
      }
      const auto closed_value = static_cast<std::uint8_t>(
          before.bytes[offset]);
      const auto open_value = static_cast<std::uint8_t>(
          after.bytes[offset]);
      if (closed_value == open_value) {
        continue;
      }
      page_candidates.push_back({
          .address = address,
          .closed_value = closed_value,
          .open_value = open_value,
          .region_size = before.bytes.size(),
      });
    }
    flush_page();
    retain_strongest(
        region_candidates, policy.maximum_candidates_per_region);
    discovered.insert(
        discovered.end(),
        std::make_move_iterator(region_candidates.begin()),
        std::make_move_iterator(region_candidates.end()));
    retain_strongest(discovered, policy.maximum_candidates);
  }
  return discovered.empty()
      ? inventory_candidate_result{
            .reason = "inventory_characterization_no_candidates"}
      : inventory_candidate_result{.candidates = std::move(discovered)};
}

inventory_candidate_result validate_inventory_candidates(
    std::vector<inventory_candidate> candidates,
    const std::vector<inventory_candidate_sample>& samples) {
  if (candidates.empty() || samples.empty() ||
      std::ranges::none_of(samples, [](const auto& sample) {
        return sample.open;
      }) ||
      std::ranges::none_of(samples, [](const auto& sample) {
        return !sample.open;
      })) {
    return {.reason = "inventory_characterization_validation_invalid"};
  }
  for (const auto& sample : samples) {
    if (sample.values.size() != candidates.size()) {
      return {.reason = "inventory_characterization_validation_shape_drift"};
    }
    for (std::size_t index = 0U; index < candidates.size(); ++index) {
      auto& candidate = candidates[index];
      ++candidate.total;
      if (!sample.values[index].has_value()) {
        ++candidate.unreadable;
        continue;
      }
      const auto expected = sample.open
          ? candidate.open_value
          : candidate.closed_value;
      const auto opposite = sample.open
          ? candidate.closed_value
          : candidate.open_value;
      if (*sample.values[index] == expected) {
        ++candidate.correct;
      } else if (*sample.values[index] == opposite) {
        ++candidate.wrong;
      } else {
        ++candidate.unreadable;
      }
    }
  }
  std::vector<inventory_candidate> validated;
  for (auto& candidate : candidates) {
    candidate.accuracy = candidate.total == 0U
        ? 0.0
        : static_cast<double>(candidate.correct) /
            static_cast<double>(candidate.total);
    if (candidate.total == samples.size() &&
        candidate.correct == candidate.total &&
        candidate.wrong == 0U && candidate.unreadable == 0U) {
      validated.push_back(std::move(candidate));
    }
  }
  return validated.empty()
      ? inventory_candidate_result{
            .reason = "inventory_characterization_validation_failed"}
      : inventory_candidate_result{.candidates = std::move(validated)};
}

}  // namespace sonar::fishing::build_profile_compatibility_probe
