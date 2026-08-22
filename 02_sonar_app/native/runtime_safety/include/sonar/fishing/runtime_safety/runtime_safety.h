#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

#include "sonar/platform/input/input_packet_budget.hpp"
#include "sonar/platform/windows/process.hpp"
#include "sonar/platform/windows/window.hpp"

namespace sonar::fishing::runtime_safety {

enum class attach_reason {
  ready,
  invalid_argument,
  process_unavailable,
  window_unavailable,
  window_owner_changed,
};

enum class action_reason {
  ready,
  entitlement_invalid,
  settings_not_current,
  lifecycle_not_actionable,
  invalid_packet_count,
  process_unavailable,
  process_changed,
  window_unavailable,
  window_changed,
  window_not_foreground,
  packet_budget_exhausted,
};

struct action_request final {
  bool entitlement_valid{};
  bool settings_current{};
  bool lifecycle_allows_input{};
  std::size_t packet_count{};
  bool foreground_required{true};
};

// Product policy stays separate from Common mechanisms so an Engine episode
// can reject an action before touching the current process/window observation.
[[nodiscard]] action_reason validate_product_prerequisites(
    const action_request& request) noexcept;

[[nodiscard]] action_reason reserve_packet_budget(
    sonar::platform::input::input_packet_budget& budget,
    std::size_t packet_count) noexcept;

// Episode-owned, single-threaded target guard. A successful preflight is not a
// transferable authorization: the owning input adapter must call it directly
// before the matching side effect and discard the guard on any target change.
class runtime_target_guard final {
 public:
  runtime_target_guard(const runtime_target_guard&) = delete;
  runtime_target_guard& operator=(const runtime_target_guard&) = delete;
  runtime_target_guard(runtime_target_guard&&) = delete;
  runtime_target_guard& operator=(runtime_target_guard&&) = delete;

  [[nodiscard]] static std::unique_ptr<runtime_target_guard> attach(
      std::uint32_t process_id,
      sonar::platform::windows::native_window_handle window,
      std::size_t maximum_packets,
      attach_reason& reason) noexcept;

  [[nodiscard]] action_reason preflight(
      const action_request& request) noexcept;

  // Revalidates the exact process/window generation without consuming the
  // input packet budget. Product-owned non-input effects (for example an OS
  // terminal action) use this only after their own authority gate and while
  // holding the same exclusive automation lease.
  [[nodiscard]] action_reason preflight_target_identity(
      bool foreground_required) noexcept;

  // Cleanup is not a new action: it ignores revoked product admission but
  // still requires the exact process/window generation and reserves the
  // matching bounded release packet batch.
  [[nodiscard]] action_reason preflight_cleanup(
      std::size_t packet_count) noexcept;

  [[nodiscard]] std::size_t remaining_packets() const noexcept;

 private:
  runtime_target_guard(
      sonar::platform::windows::readonly_process process,
      sonar::platform::windows::process_generation generation,
      sonar::platform::windows::window_client_snapshot window,
      std::size_t maximum_packets);

  sonar::platform::windows::readonly_process process_;
  sonar::platform::windows::process_generation generation_;
  sonar::platform::windows::window_client_snapshot window_;
  sonar::platform::input::input_packet_budget packet_budget_;
};

}  // namespace sonar::fishing::runtime_safety
