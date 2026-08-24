#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace sonar::fishing::build_profile_compatibility_probe {

struct inventory_region_image final {
  std::uintptr_t address{};
  std::vector<std::byte> bytes;
};

struct inventory_candidate final {
  std::uintptr_t address{};
  std::uint8_t closed_value{};
  std::uint8_t open_value{};
  std::size_t region_size{};
  std::size_t correct{};
  std::size_t wrong{};
  std::size_t unreadable{};
  std::size_t total{};
  double accuracy{};
};

struct inventory_candidate_sample final {
  bool open{};
  std::vector<std::optional<std::uint8_t>> values;
};

struct inventory_characterization_policy final {
  std::size_t maximum_candidates{1600U};
  std::size_t maximum_candidates_per_region{512U};
  std::size_t maximum_candidates_per_page{16U};
};

struct inventory_candidate_result final {
  std::vector<inventory_candidate> candidates;
  std::string reason;

  [[nodiscard]] bool ready() const noexcept;
};

// Pure differential stage used by the non-shipping tool. Both snapshots must
// cover the same immutable region selection and one exact process generation.
[[nodiscard]] inventory_candidate_result discover_inventory_candidates(
    const std::vector<inventory_region_image>& closed,
    const std::vector<inventory_region_image>& open,
    const inventory_characterization_policy& policy = {});

// Retains only candidates that matched every controlled validation sample.
// Unknown reads, opposite values and missing closed/open samples fail closed.
[[nodiscard]] inventory_candidate_result validate_inventory_candidates(
    std::vector<inventory_candidate> candidates,
    const std::vector<inventory_candidate_sample>& samples);

}  // namespace sonar::fishing::build_profile_compatibility_probe
