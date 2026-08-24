#pragma once

#include <memory>

#include "sonar/fishing/build_profile_compatibility_probe/build_profile_compatibility_probe.h"

namespace sonar::fishing::build_profile_compatibility_probe {

[[nodiscard]] std::unique_ptr<compatibility_port>
make_windows_compatibility_port();

}  // namespace sonar::fishing::build_profile_compatibility_probe
