#pragma once

#include <optional>
#include <span>
#include <string>
#include <vector>

#include "sonar/platform/windows/window.hpp"

namespace sonar::fishing::runtime_platform {

struct target_candidate final {
  std::wstring image_name;
  sonar::platform::windows::window_client_snapshot window;
};

struct target_resolution final {
  std::optional<sonar::platform::windows::window_client_snapshot> target;
  std::string reason;

  [[nodiscard]] bool ready() const noexcept;
};

// Pure ambiguity/eligibility policy used by the Win32 enumerator and fixtures.
[[nodiscard]] target_resolution select_exact_game_target(
    std::span<const target_candidate> candidates) noexcept;

// Product-owned eligibility policy passed to Common's bounded exact-generation
// top-level client observer.
[[nodiscard]] sonar::platform::windows::top_level_window_policy
exact_game_window_policy() noexcept;

class game_target_resolver {
 public:
  virtual ~game_target_resolver() = default;
  [[nodiscard]] virtual target_resolution resolve() noexcept = 0;
};

// Performs no work at construction. resolve() discovers exact GTA5.exe
// generations and their unique visible client windows through Common;
// multiple eligible windows fail closed instead of choosing by order.
class windows_game_target_resolver final : public game_target_resolver {
 public:
  [[nodiscard]] target_resolution resolve() noexcept override;
};

}  // namespace sonar::fishing::runtime_platform
