#pragma once

#include "sonar/fishing/memory_observation/memory_observation.h"

#include <memory>

namespace sonar::fishing::build_profile_compatibility_probe {

// Diagnostic-only adapter. Shipping uses Common trusted-publisher authority;
// this wrapper adds a concrete file SHA solely for forensic profile/replay
// comparison after the Common lease is admitted.
[[nodiscard]] std::unique_ptr<memory_observation::memory_connector>
make_windows_forensic_memory_connector();

}  // namespace sonar::fishing::build_profile_compatibility_probe
