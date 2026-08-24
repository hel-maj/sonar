#pragma once

#include <cstdint>
#include <string_view>

#include "sonar/fishing/build_profile_compatibility_probe/build_profile_compatibility_probe.h"
#include "sonar/fishing/memory_observation/memory_observation.h"

namespace sonar::fishing::build_profile_compatibility_probe {

inline constexpr std::uint32_t candidate_profile_schema_version = 1U;
inline constexpr std::string_view candidate_profile_id =
    "nonshipping-build-profile-candidate-v1";

// Diagnostic-only compatibility evidence. This function is compiled solely
// into the OFF-by-default probe target and its focused test; Sonar.Engine never
// links it. The baseline stays immutable and no registry admission is changed.
[[nodiscard]] validation_probe validate_candidate_reeling(
    memory_observation::memory_connector& connector,
    const memory_observation::embedded_memory_build_profile& frozen_baseline,
    std::string_view candidate_sha256,
    const sonar::platform::windows::process_generation& game_generation,
    std::uint64_t sequence,
    std::uint64_t captured_at_steady_ns) noexcept;

}  // namespace sonar::fishing::build_profile_compatibility_probe
