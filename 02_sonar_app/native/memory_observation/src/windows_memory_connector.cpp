#include "sonar/fishing/memory_observation/memory_observation.h"

#include "sonar/platform/windows/trusted_module.hpp"

#include <Windows.h>

#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string>
#include <string_view>
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

struct role_policy final {
  std::wstring_view image_name;
  std::string_view publisher_thumbprint;
};

[[nodiscard]] role_policy policy_for(const process_role role) noexcept {
  switch (role) {
    case process_role::game:
      return {
          L"GTA5.exe",
          "565932392989B3616F2968E1B1D6F974561B1F32",
      };
    case process_role::webengine:
      return {
          L"majestic-webengine.exe",
          "B03C125E345303D797A951DA1BC76B960C21FF57",
      };
  }
  return {};
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
      const auto product_policy = policy_for(role);
      if (product_policy.image_name.empty() ||
          product_policy.publisher_thumbprint.empty()) {
        reason = "memory_process_role_invalid";
        return nullptr;
      }
      auto process = sonar::platform::windows::readonly_process::open(
          process_id,
          sonar::platform::windows::process_access_profile::memory_regions);
      auto admitted = sonar::platform::windows::open_trusted_module_lease(
          std::move(process),
          {
              .process_image_name = std::wstring(product_policy.image_name),
              .module_name = std::wstring(product_policy.image_name),
              .accepted_publisher_thumbprints = {
                  std::string(product_policy.publisher_thumbprint),
              },
          });
      if (!admitted.ready()) {
        reason = "memory_trusted_module_";
        reason += sonar::platform::windows::trusted_module_admission_status_name(
            admitted.status);
        return nullptr;
      }
      const auto& authority = admitted.lease->authority();
      process_identity identity{
          .role = role,
          .generation = authority.generation,
          .image_name = std::wstring(product_policy.image_name),
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
