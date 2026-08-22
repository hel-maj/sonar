#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace sonar::fishing::entitlement {

[[nodiscard]] std::string compute_machine_fingerprint(
    std::string_view platform,
    std::string_view architecture,
    std::string_view machine_guid,
    std::string_view volume_serial,
    std::string_view fallback_host);

[[nodiscard]] std::optional<std::string>
current_windows_machine_fingerprint() noexcept;

}  // namespace sonar::fishing::entitlement
