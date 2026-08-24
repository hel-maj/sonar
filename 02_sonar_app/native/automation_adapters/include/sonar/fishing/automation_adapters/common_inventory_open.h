#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <string_view>

#include "sonar/platform/inventory/open_state.hpp"
#include "sonar/platform/windows/process.hpp"

namespace sonar::fishing::automation_adapters {

inline constexpr std::string_view common_inventory_open_package_version{
    "0.1.0"};
inline constexpr std::string_view common_inventory_open_candidate_profile_id{
    "majestic-client-1.20.7-candidate-v1"};

struct common_inventory_open_composition_policy final {
  bool observation_enabled{};
  bool candidate_profile_approved{};
  bool closed_state_bootstrap_approved{};
  std::string_view profile_id;
};

template <bool LocalAccess>
[[nodiscard]] constexpr common_inventory_open_composition_policy
common_inventory_open_policy_for_build() noexcept {
  if constexpr (LocalAccess) {
    return {
        .observation_enabled = true,
        .candidate_profile_approved = true,
        .closed_state_bootstrap_approved = true,
        .profile_id = common_inventory_open_candidate_profile_id,
    };
  } else {
    return {
        .observation_enabled = false,
        .candidate_profile_approved = false,
        .closed_state_bootstrap_approved = false,
        .profile_id = common_inventory_open_candidate_profile_id,
    };
  }
}

// This is intentionally compiled into the product adapter. A normal shipping
// composition cannot approve the candidate through runtime state.
[[nodiscard]] common_inventory_open_composition_policy
selected_common_inventory_open_policy() noexcept;

struct inventory_open_source_result final {
  sonar::platform::inventory::observed_state state{
      sonar::platform::inventory::observed_state::unknown};
  bool binding_hot{};
  std::string reason;
};

// Narrow product port around Common's coarse inventory-open facade. Common
// remains the sole owner of renderer discovery, admission, V8 decoding and
// double-read coherence.
class inventory_open_source {
 public:
  virtual ~inventory_open_source() = default;
  [[nodiscard]] virtual inventory_open_source_result capture(
      const sonar::platform::windows::process_generation& game_generation)
      noexcept = 0;
  virtual void reset() noexcept = 0;
};

class inventory_retry_clock {
 public:
  virtual ~inventory_retry_clock() = default;
  [[nodiscard]] virtual std::uint64_t now_steady_ns() const noexcept = 0;
};

[[nodiscard]] std::unique_ptr<inventory_open_source>
make_common_inventory_open_source() noexcept;
[[nodiscard]] std::unique_ptr<inventory_retry_clock>
make_inventory_retry_clock() noexcept;

}  // namespace sonar::fishing::automation_adapters
