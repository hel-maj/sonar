#pragma once

#include <cstdint>
#include <span>

namespace sonar::fishing::stage_detection::detail {

enum class embedded_stage_asset_id : std::uint8_t {
  ad_fhd,
  ad_2k,
  start_fhd,
  start_2k,
  cast_fhd,
  cast_2k,
  hook_fhd,
  hook_2k,
  wait_fhd,
  wait_2k,
};

[[nodiscard]] std::span<const std::uint8_t> embedded_stage_asset(
    embedded_stage_asset_id id) noexcept;

}  // namespace sonar::fishing::stage_detection::detail
