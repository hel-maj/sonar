#include "windows_forensic_memory_connector.h"

#include <Windows.h>
#include <bcrypt.h>

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <utility>
#include <vector>

namespace sonar::fishing::build_profile_compatibility_probe {
namespace {

namespace memory = sonar::fishing::memory_observation;

class unique_file final {
 public:
  explicit unique_file(HANDLE value) noexcept : value_(value) {}
  ~unique_file() {
    if (value_ != INVALID_HANDLE_VALUE) {
      CloseHandle(value_);
    }
  }
  unique_file(const unique_file&) = delete;
  unique_file& operator=(const unique_file&) = delete;
  [[nodiscard]] HANDLE get() const noexcept { return value_; }

 private:
  HANDLE value_{INVALID_HANDLE_VALUE};
};

class algorithm_handle final {
 public:
  algorithm_handle() = default;
  ~algorithm_handle() {
    if (value_ != nullptr) {
      BCryptCloseAlgorithmProvider(value_, 0U);
    }
  }
  algorithm_handle(const algorithm_handle&) = delete;
  algorithm_handle& operator=(const algorithm_handle&) = delete;
  [[nodiscard]] BCRYPT_ALG_HANDLE* out() noexcept { return &value_; }
  [[nodiscard]] BCRYPT_ALG_HANDLE get() const noexcept { return value_; }

 private:
  BCRYPT_ALG_HANDLE value_{};
};

class hash_handle final {
 public:
  hash_handle() = default;
  ~hash_handle() {
    if (value_ != nullptr) {
      BCryptDestroyHash(value_);
    }
  }
  hash_handle(const hash_handle&) = delete;
  hash_handle& operator=(const hash_handle&) = delete;
  [[nodiscard]] BCRYPT_HASH_HANDLE* out() noexcept { return &value_; }
  [[nodiscard]] BCRYPT_HASH_HANDLE get() const noexcept { return value_; }

 private:
  BCRYPT_HASH_HANDLE value_{};
};

[[nodiscard]] bool bcrypt_ok(const NTSTATUS status) noexcept {
  return status >= 0;
}

[[nodiscard]] std::optional<std::string> sha256_file(
    const std::wstring& path) noexcept {
  try {
    const unique_file file(CreateFileW(
        path.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
        nullptr));
    if (file.get() == INVALID_HANDLE_VALUE) {
      return std::nullopt;
    }
    algorithm_handle algorithm;
    if (!bcrypt_ok(BCryptOpenAlgorithmProvider(
            algorithm.out(), BCRYPT_SHA256_ALGORITHM, nullptr, 0U))) {
      return std::nullopt;
    }
    DWORD object_size{};
    DWORD digest_size{};
    ULONG copied{};
    if (!bcrypt_ok(BCryptGetProperty(
            algorithm.get(), BCRYPT_OBJECT_LENGTH,
            reinterpret_cast<PUCHAR>(&object_size), sizeof(object_size),
            &copied, 0U)) ||
        copied != sizeof(object_size) || object_size == 0U ||
        !bcrypt_ok(BCryptGetProperty(
            algorithm.get(), BCRYPT_HASH_LENGTH,
            reinterpret_cast<PUCHAR>(&digest_size), sizeof(digest_size),
            &copied, 0U)) ||
        copied != sizeof(digest_size) || digest_size != 32U) {
      return std::nullopt;
    }
    std::vector<UCHAR> hash_object(object_size);
    hash_handle hash;
    if (!bcrypt_ok(BCryptCreateHash(
            algorithm.get(), hash.out(), hash_object.data(),
            static_cast<ULONG>(hash_object.size()), nullptr, 0U, 0U))) {
      return std::nullopt;
    }
    constexpr DWORD chunk_bytes = 1024U * 1024U;
    std::vector<UCHAR> chunk(chunk_bytes);
    for (;;) {
      DWORD read{};
      if (!ReadFile(file.get(), chunk.data(), chunk_bytes, &read, nullptr)) {
        return std::nullopt;
      }
      if (read == 0U) {
        break;
      }
      if (!bcrypt_ok(BCryptHashData(hash.get(), chunk.data(), read, 0U))) {
        return std::nullopt;
      }
    }
    std::array<UCHAR, 32U> digest{};
    if (!bcrypt_ok(BCryptFinishHash(
            hash.get(), digest.data(), static_cast<ULONG>(digest.size()), 0U))) {
      return std::nullopt;
    }
    constexpr std::array<char, 16U> hex{
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    std::string encoded;
    encoded.reserve(digest.size() * 2U);
    for (const auto value : digest) {
      encoded.push_back(hex[(value >> 4U) & 0x0FU]);
      encoded.push_back(hex[value & 0x0FU]);
    }
    return encoded;
  } catch (...) {
    return std::nullopt;
  }
}

class forensic_memory_session final : public memory::readonly_memory_session {
 public:
  forensic_memory_session(
      std::unique_ptr<memory::readonly_memory_session> inner,
      memory::process_identity identity)
      : inner_(std::move(inner)), identity_(std::move(identity)) {}

  [[nodiscard]] const memory::process_identity& identity()
      const noexcept override {
    return identity_;
  }

  [[nodiscard]] bool read_exact(
      const std::uintptr_t address,
      const std::span<std::byte> destination) noexcept override {
    return inner_ != nullptr && inner_->read_exact(address, destination);
  }

  [[nodiscard]] std::optional<
      sonar::platform::windows::memory_region_snapshot>
  query_region(const std::uintptr_t address) noexcept override {
    return inner_ == nullptr ? std::nullopt : inner_->query_region(address);
  }

  [[nodiscard]] bool generation_current() noexcept override {
    return inner_ != nullptr && inner_->generation_current();
  }

 private:
  std::unique_ptr<memory::readonly_memory_session> inner_;
  memory::process_identity identity_;
};

class forensic_memory_connector final : public memory::memory_connector {
 public:
  forensic_memory_connector()
      : inner_(memory::make_windows_memory_connector()) {}

  [[nodiscard]] std::unique_ptr<memory::readonly_memory_session> connect(
      const memory::process_role role,
      const std::uint32_t process_id,
      std::string& reason) noexcept override {
    try {
      if (inner_ == nullptr) {
        reason = "memory_forensic_connector_unavailable";
        return nullptr;
      }
      auto session = inner_->connect(role, process_id, reason);
      if (session == nullptr || !session->generation_current()) {
        if (reason.empty()) {
          reason = "memory_forensic_authority_changed";
        }
        return nullptr;
      }
      auto identity = session->identity();
      if (identity.admission !=
              memory::process_admission::trusted_publisher_runtime ||
          identity.authority_fingerprint == 0U ||
          identity.modules.size() != 1U ||
          identity.modules.front().path.empty()) {
        reason = "memory_forensic_authority_invalid";
        return nullptr;
      }
      const auto hash = sha256_file(identity.modules.front().path);
      if (!hash.has_value() || !session->generation_current()) {
        reason = "memory_forensic_image_hash_unavailable";
        return nullptr;
      }
      identity.image_sha256 = *hash;
      identity.admission = memory::process_admission::exact_image_sha256;
      identity.authority_fingerprint = 0U;
      reason = "ready";
      return std::make_unique<forensic_memory_session>(
          std::move(session), std::move(identity));
    } catch (...) {
      reason = "memory_forensic_connector_unavailable";
      return nullptr;
    }
  }

 private:
  std::unique_ptr<memory::memory_connector> inner_;
};

}  // namespace

std::unique_ptr<memory_observation::memory_connector>
make_windows_forensic_memory_connector() {
  return std::make_unique<forensic_memory_connector>();
}

}  // namespace sonar::fishing::build_profile_compatibility_probe
