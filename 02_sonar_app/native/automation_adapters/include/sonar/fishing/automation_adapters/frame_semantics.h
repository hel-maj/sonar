#pragma once

#include "sonar/fishing/fishing_episode/fishing_episode.h"
#include "sonar/fishing/runtime_platform/platform_capture.h"

namespace sonar::fishing::automation_adapters {

struct frame_semantics final {
  bool cast_ready{};
  double cast_confidence{};
  fishing_episode::hook_cue hook{fishing_episode::hook_cue::none};
  double hook_confidence{};
  bool catch_visible{};
};

// Pure normalized detector preserving the legacy green-zone and red hook cue
// thresholds while adding a structural catch-panel fact. No fixed screen
// resolution or physical coordinate enters the contract.
[[nodiscard]] frame_semantics detect_frame_semantics(
    const runtime_platform::client_frame& frame) noexcept;

}  // namespace sonar::fishing::automation_adapters
