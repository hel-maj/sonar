#include "sonar/fishing/memory_observation/memory_observation.h"

#include "sonar/majestic/runtime_module/runtime_module.hpp"
#include "sonar/platform/windows/trusted_module.hpp"

#include <Windows.h>

#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string>
#include <utility>

namespace sonar::fishing::memory_observation {
namespace {

class common_windows_memory_session final : public readonly_memory_session {
 public:
  common_windows_memory_session(
      std::unique_ptr<sonar::platform::windows::trusted_module_lease> lease,
      process_identity identity)
      : lease_(std::move(lease)), identity_(std::move(identity)) {}

  [[nodiscard]] const process_identity& identity() const noexcept override {
    return identity_;
  }

  [[nodiscard]] bool read_exact(
      const std::uintptr_t address,
      const std::span<std::byte> destination) noexcept override {
    if (address == 0U || destination.empty() ||
        destination.size() > maximum_read_region_bytes) {
      return false;
    }
    try {
      lease_->process().read_exact(address, destination);
      return true;
    } catch (...) {
      return false;
    }
  }

  [[nodiscard]] std::optional<
      sonar::platform::windows::memory_region_snapshot>
  query_region(const std::uintptr_t address) noexcept override {
    try {
      return lease_->process().query_region(address);
    } catch (...) {
      return std::nullopt;
    }
  }

  [[nodiscard]] bool generation_current() noexcept override {
    try {
      return lease_ != nullptr &&
          lease_->revalidate() ==
              sonar::platform::windows::trusted_module_admission_status::ready;
    } catch (...) {
      return false;
    }
  }

 private:
  std::unique_ptr<sonar::platform::windows::trusted_module_lease> lease_;
  process_identity identity_;
};

namespace common_runtime = sonar::majestic::runtime_module;

[[nodiscard]] std::optional<common_runtime::win32_runtime_module_role>
common_role_for(const process_role role) noexcept {
  switch (role) {
    case process_role::game:
      return common_runtime::win32_runtime_module_role::gta5;
    case process_role::webengine:
      return common_runtime::win32_runtime_module_role::majestic_webengine;
  }
  return std::nullopt;
}

[[nodiscard]] std::string admission_reason(
    const common_runtime::win32_runtime_module_open_result& admitted) {
  std::string reason{"memory_trusted_module_"};
  if (admitted.status !=
      common_runtime::win32_runtime_module_open_status::authority_rejected) {
    reason += common_runtime::win32_runtime_module_open_status_name(
        admitted.status);
    return reason;
  }
  reason += sonar::platform::windows::trusted_module_admission_status_name(
      admitted.authority_status);
  return reason;
}

class common_windows_memory_connector final : public memory_connector {
 public:
  [[nodiscard]] std::unique_ptr<readonly_memory_session> connect(
      const process_role role,
      const std::uint32_t process_id,
      std::string& reason) noexcept override {
    if (process_id == 0U) {
      reason = "memory_process_id_invalid";
      return nullptr;
    }
    try {
      const auto common_role = common_role_for(role);
      if (!common_role.has_value()) {
        reason = "memory_process_role_invalid";
        return nullptr;
      }
      auto admitted =
          common_runtime::open_win32_trusted_runtime_module_lease(
              *common_role, process_id);
      if (!admitted.ready()) {
        reason = admission_reason(admitted);
        return nullptr;
      }
      const auto& authority = admitted.lease->authority();
      process_identity identity{
          .role = role,
          .generation = authority.generation,
          .image_name = authority.module.name,
          .image_sha256 = {},
          .admission = process_admission::trusted_publisher_runtime,
          .authority_fingerprint = authority.identity_fingerprint,
          .modules = {authority.module},
      };
      reason = "ready";
      return std::make_unique<common_windows_memory_session>(
          std::move(admitted.lease), std::move(identity));
    } catch (const sonar::platform::windows::process_error&) {
      reason = "memory_process_unavailable";
      return nullptr;
    } catch (...) {
      reason = "memory_process_unavailable";
      return nullptr;
    }
  }
};

}  // namespace

std::unique_ptr<memory_connector> make_windows_memory_connector() {
  return std::make_unique<common_windows_memory_connector>();
}

}  // namespace sonar::fishing::memory_observation
