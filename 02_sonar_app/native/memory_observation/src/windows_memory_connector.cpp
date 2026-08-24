#include "sonar/fishing/memory_observation/memory_observation.h"

#include <Windows.h>
#include <bcrypt.h>

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string>
#include <utility>
#include <vector>

namespace sonar::fishing::memory_observation {
namespace {

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
  ~algorithm_handle() {
    if (value_ != nullptr) {
      BCryptCloseAlgorithmProvider(value_, 0U);
    }
  }
  algorithm_handle(const algorithm_handle&) = delete;
  algorithm_handle& operator=(const algorithm_handle&) = delete;
  algorithm_handle() = default;
  [[nodiscard]] BCRYPT_ALG_HANDLE* out() noexcept { return &value_; }
  [[nodiscard]] BCRYPT_ALG_HANDLE get() const noexcept { return value_; }

 private:
  BCRYPT_ALG_HANDLE value_{};
};

class hash_handle final {
 public:
  ~hash_handle() {
    if (value_ != nullptr) {
      BCryptDestroyHash(value_);
    }
  }
  hash_handle(const hash_handle&) = delete;
  hash_handle& operator=(const hash_handle&) = delete;
  hash_handle() = default;
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
    DWORD object_size = 0U;
    DWORD digest_size = 0U;
    ULONG copied = 0U;
    if (!bcrypt_ok(BCryptGetProperty(
            algorithm.get(),
            BCRYPT_OBJECT_LENGTH,
            reinterpret_cast<PUCHAR>(&object_size),
            sizeof(object_size),
            &copied,
            0U)) ||
        copied != sizeof(object_size) || object_size == 0U ||
        !bcrypt_ok(BCryptGetProperty(
            algorithm.get(),
            BCRYPT_HASH_LENGTH,
            reinterpret_cast<PUCHAR>(&digest_size),
            sizeof(digest_size),
            &copied,
            0U)) ||
        copied != sizeof(digest_size) || digest_size != 32U) {
      return std::nullopt;
    }
    std::vector<UCHAR> hash_object(object_size);
    hash_handle hash;
    if (!bcrypt_ok(BCryptCreateHash(
            algorithm.get(),
            hash.out(),
            hash_object.data(),
            static_cast<ULONG>(hash_object.size()),
            nullptr,
            0U,
            0U))) {
      return std::nullopt;
    }
    constexpr DWORD chunk_bytes = 1024U * 1024U;
    std::vector<UCHAR> chunk(chunk_bytes);
    for (;;) {
      DWORD read = 0U;
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

class common_windows_memory_session final : public readonly_memory_session {
 public:
  common_windows_memory_session(
      sonar::platform::windows::readonly_process process,
      process_identity identity)
      : process_(std::move(process)), identity_(std::move(identity)) {}

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
      process_.read_exact(address, destination);
      return true;
    } catch (...) {
      return false;
    }
  }

  [[nodiscard]] std::optional<
      sonar::platform::windows::memory_region_snapshot>
  query_region(const std::uintptr_t address) noexcept override {
    try {
      return process_.query_region(address);
    } catch (...) {
      return std::nullopt;
    }
  }

  [[nodiscard]] bool generation_current() noexcept override {
    try {
      return process_.generation_matches(identity_.generation);
    } catch (...) {
      return false;
    }
  }

 private:
  sonar::platform::windows::readonly_process process_;
  process_identity identity_;
};

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
      auto process = sonar::platform::windows::readonly_process::open(
          process_id,
          sonar::platform::windows::process_access_profile::memory_regions);
      const auto generation = process.generation();
      const auto path = process.image_path();
      const auto hash = sha256_file(path);
      if (!hash.has_value()) {
        reason = "memory_image_hash_unavailable";
        return nullptr;
      }
      process_identity identity{
          .role = role,
          .generation = generation,
          .image_name = process.image_name(),
          .image_sha256 = *hash,
          .modules = process.modules(),
      };
      reason = "ready";
      return std::make_unique<common_windows_memory_session>(
          std::move(process), std::move(identity));
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
