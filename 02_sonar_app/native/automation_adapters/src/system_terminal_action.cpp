#include "sonar/fishing/automation_adapters/system_terminal_action.h"

#include <Windows.h>

#include <string>
#include <utility>

namespace sonar::fishing::automation_adapters {
namespace {

class unique_handle final {
 public:
  explicit unique_handle(HANDLE value = nullptr) noexcept : value_(value) {}
  ~unique_handle() {
    if (value_ != nullptr && value_ != INVALID_HANDLE_VALUE) {
      CloseHandle(value_);
    }
  }
  unique_handle(const unique_handle&) = delete;
  unique_handle& operator=(const unique_handle&) = delete;
  unique_handle(unique_handle&& other) noexcept
      : value_(std::exchange(other.value_, nullptr)) {}
  unique_handle& operator=(unique_handle&& other) noexcept {
    if (this != &other) {
      if (value_ != nullptr && value_ != INVALID_HANDLE_VALUE) {
        CloseHandle(value_);
      }
      value_ = std::exchange(other.value_, nullptr);
    }
    return *this;
  }
  [[nodiscard]] HANDLE get() const noexcept { return value_; }

 private:
  HANDLE value_{};
};

class scoped_shutdown_privilege final {
 public:
  scoped_shutdown_privilege() noexcept {
    HANDLE token = nullptr;
    if (OpenProcessToken(
            GetCurrentProcess(),
            TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
            &token) == FALSE) {
      return;
    }
    token_ = unique_handle(token);

    LUID privilege{};
    if (LookupPrivilegeValueA(nullptr, SE_SHUTDOWN_NAME, &privilege) == FALSE) {
      return;
    }
    TOKEN_PRIVILEGES requested{};
    requested.PrivilegeCount = 1U;
    requested.Privileges[0].Luid = privilege;
    requested.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    DWORD previous_size = sizeof(previous_);
    SetLastError(ERROR_SUCCESS);
    if (AdjustTokenPrivileges(
            token_.get(), FALSE, &requested, sizeof(previous_), &previous_,
            &previous_size) == FALSE ||
        GetLastError() != ERROR_SUCCESS) {
      return;
    }
    enabled_ = true;
  }

  ~scoped_shutdown_privilege() {
    if (enabled_) {
      static_cast<void>(AdjustTokenPrivileges(
          token_.get(), FALSE, &previous_, 0U, nullptr, nullptr));
    }
  }

  scoped_shutdown_privilege(const scoped_shutdown_privilege&) = delete;
  scoped_shutdown_privilege& operator=(
      const scoped_shutdown_privilege&) = delete;

  [[nodiscard]] bool enabled() const noexcept { return enabled_; }

 private:
  unique_handle token_;
  TOKEN_PRIVILEGES previous_{};
  bool enabled_{};
};

}  // namespace

system_terminal_action_result system_terminal_action_result::accepted() {
  return {.applied = true};
}

system_terminal_action_result system_terminal_action_result::rejected(
    std::string reason) {
  return {.reason = std::move(reason)};
}

system_terminal_action_result
win32_system_terminal_action_sink::shutdown_pc() noexcept {
  try {
    scoped_shutdown_privilege privilege;
    if (!privilege.enabled()) {
      return system_terminal_action_result::rejected(
          "shutdown_privilege_unavailable");
    }
    constexpr DWORD kReason =
        SHTDN_REASON_MAJOR_APPLICATION |
        SHTDN_REASON_MINOR_MAINTENANCE |
        SHTDN_REASON_FLAG_PLANNED;
    // Preserve legacy `/s /t 0` timing without forcing applications that have
    // unsaved work. The call is asynchronous and requires SE_SHUTDOWN_NAME.
    if (InitiateSystemShutdownExW(
            nullptr, nullptr, 0U, FALSE, FALSE, kReason) == FALSE) {
      return system_terminal_action_result::rejected(
          "shutdown_request_rejected");
    }
    return system_terminal_action_result::accepted();
  } catch (...) {
    return system_terminal_action_result::rejected(
        "shutdown_request_failed");
  }
}

}  // namespace sonar::fishing::automation_adapters
