#pragma once

#include <optional>
#include <string>
#include <vector>

#include "sonar/fishing/inventory_store/inventory_store_episode.h"
#include "sonar/fishing/maintenance_episode/maintenance_episode.h"
#include "sonar/fishing/runtime_platform/platform_capture.h"

namespace sonar::fishing::automation_adapters::detail {

struct visual_catch_surface final {
  bool visible{};
  bool inventory_full{};
  stage_detection::normalized_rect keep_button;
  stage_detection::normalized_rect release_button;
  stage_detection::normalized_rect fish_text;
  stage_detection::normalized_rect quality_text;
  stage_detection::normalized_rect weight_text;
  stage_detection::normalized_rect experience_text;
};

struct visual_inventory_surface final {
  inventory_store::inventory_surface surface{
      inventory_store::inventory_surface::unknown};
  std::vector<inventory_store::inventory_item_observation> items;
  std::optional<inventory_store::inventory_context_action_observation>
      remove_action;
  bool hunger_visible{};
  bool thirst_visible{};
  bool changed_bait_visible{};
  bool gear_visible{};
  maintenance_episode::tackle_scan_observation tackle;
};

class production_visual_detector final {
 public:
  [[nodiscard]] visual_catch_surface detect_catch(
      const runtime_platform::client_frame& frame) const noexcept;

  [[nodiscard]] visual_inventory_surface detect_inventory(
      const runtime_platform::client_frame& frame,
      bool inventory_title_confirmed,
      std::optional<std::string_view> expected_context_instance =
          std::nullopt,
      std::optional<stage_detection::normalized_rect> expected_context_bounds =
          std::nullopt) const noexcept;
};

}  // namespace sonar::fishing::automation_adapters::detail
