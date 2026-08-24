#include <iostream>
#include <string_view>

#include "sonar/fishing/live_observation_preflight/live_observation_preflight.h"
#include "windows_observation_port.h"

namespace preflight = sonar::fishing::live_observation_preflight;

int main(const int argument_count, const char* const* arguments) {
  if (argument_count != 2 || arguments == nullptr || arguments[1] == nullptr ||
      std::string_view(arguments[1]) != "--confirmed-live-read-only") {
    std::cerr << "Usage: Sonar.Fishing.LiveObservationPreflight.exe "
                 "--confirmed-live-read-only\n";
    return 64;
  }
  try {
    auto port = preflight::make_windows_observation_port();
    if (!port) {
      return 70;
    }
    const auto result = preflight::run(*port);
    std::cout << preflight::serialize_json(result) << '\n';
    return result.ready ? 0 : 2;
  } catch (...) {
    const preflight::preflight_result failed{
        .reason = preflight::readiness_reason::internal_error,
    };
    std::cout << preflight::serialize_json(failed) << '\n';
    return 70;
  }
}
