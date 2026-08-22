#pragma once

#include <string>

namespace sonar::fishing::automation_adapters {

struct system_terminal_action_result final {
  bool applied{};
  std::string reason;

  [[nodiscard]] static system_terminal_action_result accepted();
  [[nodiscard]] static system_terminal_action_result rejected(
      std::string reason);
};

// Product-owned side-effect boundary. Tests inject an inert recorder; the
// shipping Windows implementation is constructed only inside an admitted
// production session and is never called by setup, tests, package or smoke.
class system_terminal_action_sink {
 public:
  virtual ~system_terminal_action_sink() = default;
  [[nodiscard]] virtual system_terminal_action_result shutdown_pc() noexcept = 0;
};

class win32_system_terminal_action_sink final
    : public system_terminal_action_sink {
 public:
  [[nodiscard]] system_terminal_action_result shutdown_pc() noexcept override;
};

}  // namespace sonar::fishing::automation_adapters
