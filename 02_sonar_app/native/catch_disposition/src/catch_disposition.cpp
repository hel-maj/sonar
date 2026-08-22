#include "sonar/fishing/catch_disposition/catch_disposition.h"

#include <algorithm>

namespace sonar::fishing::catch_disposition {

Decision Decide(
    const std::optional<std::string_view> fish_id,
    const std::span<const std::string_view> selected_fish_ids,
    const bool inventory_full) noexcept {
  if (inventory_full) {
    return {Disposition::Release, Reason::InventoryFull};
  }
  if (!fish_id.has_value() || fish_id->empty()) {
    return {Disposition::Release, Reason::FishUnrecognized};
  }
  const bool selected = std::ranges::find(selected_fish_ids, *fish_id) !=
                        selected_fish_ids.end();
  if (selected) {
    return {Disposition::Keep, Reason::FishSelected};
  }
  return {Disposition::Release, Reason::FishNotSelected};
}

std::string_view ReasonKey(const Reason value) noexcept {
  switch (value) {
    case Reason::InventoryFull:
      return "inventory_full";
    case Reason::FishUnrecognized:
      return "fish_unrecognized";
    case Reason::FishSelected:
      return "fish_selected";
    case Reason::FishNotSelected:
      return "fish_not_selected";
  }
  return "unknown";
}

}  // namespace sonar::fishing::catch_disposition
