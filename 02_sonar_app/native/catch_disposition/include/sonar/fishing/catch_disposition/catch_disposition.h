#pragma once

#include <optional>
#include <span>
#include <string_view>

namespace sonar::fishing::catch_disposition {

enum class Disposition {
  Keep,
  Release,
};

enum class Reason {
  InventoryFull,
  FishUnrecognized,
  FishSelected,
  FishNotSelected,
};

struct Decision {
  Disposition outcome;
  Reason rationale;

  [[nodiscard]] constexpr bool should_keep() const noexcept {
    return outcome == Disposition::Keep;
  }
};

[[nodiscard]] Decision Decide(
    std::optional<std::string_view> fish_id,
    std::span<const std::string_view> selected_fish_ids,
    bool inventory_full) noexcept;

[[nodiscard]] std::string_view ReasonKey(Reason value) noexcept;

}  // namespace sonar::fishing::catch_disposition
