#pragma once

#include <memory>

#include "sonar/fishing/live_observation_preflight/live_observation_preflight.h"

namespace sonar::fishing::live_observation_preflight {

// Construction is inert. The returned adapter performs one bounded read-only
// observation only when its methods are invoked by run().
[[nodiscard]] std::unique_ptr<observation_port>
make_windows_observation_port();

}  // namespace sonar::fishing::live_observation_preflight
