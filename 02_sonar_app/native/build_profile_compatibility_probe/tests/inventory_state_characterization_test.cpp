#include "inventory_state_characterization.h"

#include <iostream>
#include <stdexcept>

namespace probe = sonar::fishing::build_profile_compatibility_probe;

namespace {

void require(const bool condition, const char* message) {
  if (!condition) {
    throw std::runtime_error(message);
  }
}

void differential_candidates_are_bounded_and_validated() {
  std::vector<std::byte> closed(0x1200U, std::byte{0U});
  auto open = closed;
  open[0x10U] = std::byte{128U};
  open[0x11U] = std::byte{63U};
  open[0x1010U] = std::byte{1U};
  const auto discovered = probe::discover_inventory_candidates(
      {{0x100000U, closed}},
      {{0x100000U, open}},
      {.maximum_candidates = 8U,
       .maximum_candidates_per_region = 8U,
       .maximum_candidates_per_page = 2U});
  require(discovered.ready() && discovered.candidates.size() == 3U,
      "inventory candidates were not discovered");

  std::vector<probe::inventory_candidate_sample> samples;
  for (const bool is_open : {false, true, false, true}) {
    probe::inventory_candidate_sample sample{.open = is_open};
    for (const auto& candidate : discovered.candidates) {
      sample.values.push_back(is_open
          ? candidate.open_value
          : candidate.closed_value);
    }
    samples.push_back(std::move(sample));
  }
  auto noisy = samples;
  noisy.back().values.back() = std::nullopt;
  const auto validated = probe::validate_inventory_candidates(
      discovered.candidates, noisy);
  require(validated.ready() && validated.candidates.size() == 2U,
      "unstable inventory candidate was not rejected");
  for (const auto& candidate : validated.candidates) {
    require(candidate.accuracy == 1.0 && candidate.correct == 4U &&
            candidate.wrong == 0U && candidate.unreadable == 0U,
        "validated inventory candidate metrics changed");
  }
}

void drift_and_one_sided_validation_fail_closed() {
  require(!probe::discover_inventory_candidates(
              {{0x1000U, {std::byte{0U}}}},
              {{0x2000U, {std::byte{1U}}}})
               .ready(),
      "region drift was accepted");
  require(!probe::validate_inventory_candidates(
              {{.address = 0x1000U,
                .closed_value = 0U,
                .open_value = 1U,
                .region_size = 1U}},
              {{.open = true, .values = {std::uint8_t{1U}}}})
               .ready(),
      "one-sided validation was accepted");
}

void region_limit_is_applied_after_full_region_ranking() {
  std::vector<std::byte> closed(1024U, std::byte{0U});
  std::vector<std::byte> open(1024U, std::byte{1U});
  open[900U] = std::byte{255U};
  const auto discovered = probe::discover_inventory_candidates(
      {{0x100000U, closed}},
      {{0x100000U, open}},
      {.maximum_candidates = 2U,
       .maximum_candidates_per_region = 2U,
       .maximum_candidates_per_page = 2U});
  bool late_candidate_retained = false;
  for (const auto& candidate : discovered.candidates) {
    late_candidate_retained = late_candidate_retained ||
        candidate.address == 0x100000U + 900U;
  }
  require(discovered.ready() && discovered.candidates.size() == 2U &&
          late_candidate_retained,
      "region scan truncated before deterministic ranking");
}

}  // namespace

int main() {
  try {
    differential_candidates_are_bounded_and_validated();
    drift_and_one_sided_validation_fail_closed();
    region_limit_is_applied_after_full_region_ranking();
    std::cout << "inventory characterization tests passed\n";
    return 0;
  } catch (const std::exception& error) {
    std::cerr << "inventory characterization test failed: "
              << error.what() << '\n';
    return 1;
  }
}
