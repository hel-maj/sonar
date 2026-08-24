#include <iostream>
#include <string_view>

#include "sonar/fishing/build_profile_compatibility_probe/build_profile_compatibility_probe.h"
#include "windows_compatibility_port.h"

namespace probe = sonar::fishing::build_profile_compatibility_probe;

int main(const int argument_count, const char* const* arguments) {
  if (argument_count != 2 || arguments == nullptr || arguments[1] == nullptr ||
      std::string_view(arguments[1]) !=
          "--confirmed-live-build-profile-compatibility") {
    std::cerr << "Usage: Sonar.Fishing.BuildProfileCompatibilityProbe.exe "
                 "--confirmed-live-build-profile-compatibility\n";
    return 64;
  }
  try {
    auto port = probe::make_windows_compatibility_port();
    if (!port) {
      return 70;
    }
    const auto result = probe::run(*port);
    std::cout << probe::serialize_json(result) << '\n';
    return result.ready ? 0 : 2;
  } catch (...) {
    const probe::probe_result failed{
        .reason = probe::readiness_reason::internal_error,
    };
    std::cout << probe::serialize_json(failed) << '\n';
    return 70;
  }
}
