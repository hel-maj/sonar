#pragma once

#include "sonar/fishing/memory_observation/memory_observation.h"

#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <string_view>

namespace sonar::fishing::memory_observation::detail {

struct trusted_fish_binding final {
  std::uintptr_t entity{};
  std::uintptr_t hash_address{};
  std::string reason;

  [[nodiscard]] bool ready() const noexcept {
    return entity != 0U && hash_address != 0U && reason.empty();
  }
};

struct trusted_reeling_binding final {
  const embedded_memory_build_profile* profile{};
  std::uintptr_t player{};
  std::uintptr_t replay{};
  trusted_fish_binding fish;
  std::size_t player_right_offset{};
  std::string reason;

  [[nodiscard]] bool ready() const noexcept {
    return profile != nullptr && player != 0U && replay != 0U &&
        fish.ready() && player_right_offset != 0U && reason.empty();
  }
};

// Shipping semantic admission. The caller already owns a Common trusted
// module lease through the session. This operation scans only a fully covered
// executable image, rejects ambiguous anchors, and binds one current active
// fish without consulting a known executable identity.
[[nodiscard]] trusted_reeling_binding resolve_trusted_reeling_binding(
    readonly_memory_session& session,
    const sonar::platform::windows::module_snapshot& module,
    std::span<const embedded_memory_build_profile> profiles,
    std::wstring_view image_name) noexcept;

// Hot fish rediscovery after the previously bound fish disappears. Player,
// replay and profile were already admitted in the same process generation.
[[nodiscard]] trusted_fish_binding resolve_trusted_active_fish(
    readonly_memory_session& session,
    std::uintptr_t replay,
    std::uintptr_t player,
    const embedded_memory_build_profile& profile) noexcept;

}  // namespace sonar::fishing::memory_observation::detail
