#include "sonar/fishing/entitlement/windows_machine_fingerprint.h"

#include <Windows.h>
#include <bcrypt.h>

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace sonar::fishing::entitlement {
namespace {

[[nodiscard]] std::string utf8(const std::wstring_view source) {
  if (source.empty()) {
    return {};
  }
  const int required = WideCharToMultiByte(
      CP_UTF8,
      WC_ERR_INVALID_CHARS,
      source.data(),
      static_cast<int>(source.size()),
      nullptr,
      0,
      nullptr,
      nullptr);
  if (required <= 0) {
    throw std::runtime_error("machine_identity_utf8_invalid");
  }
  std::string result(static_cast<std::size_t>(required), '\0');
  if (WideCharToMultiByte(
          CP_UTF8,
          WC_ERR_INVALID_CHARS,
          source.data(),
          static_cast<int>(source.size()),
          result.data(),
          required,
          nullptr,
          nullptr) != required) {
    throw std::runtime_error("machine_identity_utf8_invalid");
  }
  return result;
}

[[nodiscard]] std::array<std::byte, 32> sha256(
    const std::string_view source) {
  BCRYPT_ALG_HANDLE algorithm = nullptr;
  BCRYPT_HASH_HANDLE hash = nullptr;
  std::vector<unsigned char> object;
  std::array<std::byte, 32> digest{};
  try {
    if (BCryptOpenAlgorithmProvider(
            &algorithm, BCRYPT_SHA256_ALGORITHM, nullptr, 0) < 0) {
      throw std::runtime_error("machine_fingerprint_sha256_unavailable");
    }
    DWORD object_size = 0;
    DWORD copied = 0;
    if (BCryptGetProperty(
            algorithm,
            BCRYPT_OBJECT_LENGTH,
            reinterpret_cast<PUCHAR>(&object_size),
            sizeof(object_size),
            &copied,
            0) < 0 || copied != sizeof(object_size) || object_size == 0) {
      throw std::runtime_error("machine_fingerprint_sha256_unavailable");
    }
    object.resize(object_size);
    if (BCryptCreateHash(
            algorithm,
            &hash,
            object.data(),
            static_cast<ULONG>(object.size()),
            nullptr,
            0,
            0) < 0 ||
        BCryptHashData(
            hash,
            reinterpret_cast<PUCHAR>(const_cast<char*>(source.data())),
            static_cast<ULONG>(source.size()),
            0) < 0 ||
        BCryptFinishHash(
            hash,
            reinterpret_cast<PUCHAR>(digest.data()),
            static_cast<ULONG>(digest.size()),
            0) < 0) {
      throw std::runtime_error("machine_fingerprint_sha256_failed");
    }
  } catch (...) {
    if (hash != nullptr) {
      BCryptDestroyHash(hash);
    }
    if (algorithm != nullptr) {
      BCryptCloseAlgorithmProvider(algorithm, 0);
    }
    throw;
  }
  BCryptDestroyHash(hash);
  BCryptCloseAlgorithmProvider(algorithm, 0);
  return digest;
}

[[nodiscard]] std::string lower_hex(
    const std::array<std::byte, 32>& digest) {
  constexpr std::string_view alphabet = "0123456789abcdef";
  std::string result(digest.size() * 2U, '\0');
  for (std::size_t index = 0; index < digest.size(); ++index) {
    const auto value = std::to_integer<unsigned char>(digest[index]);
    result[index * 2U] = alphabet[value >> 4U];
    result[index * 2U + 1U] = alphabet[value & 0x0fU];
  }
  return result;
}

[[nodiscard]] std::string read_machine_guid() {
  DWORD bytes = 0;
  constexpr DWORD flags = RRF_RT_REG_SZ | RRF_SUBKEY_WOW6464KEY;
  const auto size_status = RegGetValueW(
      HKEY_LOCAL_MACHINE,
      L"SOFTWARE\\Microsoft\\Cryptography",
      L"MachineGuid",
      flags,
      nullptr,
      nullptr,
      &bytes);
  if (size_status != ERROR_SUCCESS || bytes < sizeof(wchar_t) ||
      bytes > 4096U) {
    return {};
  }
  std::wstring value(bytes / sizeof(wchar_t), L'\0');
  if (RegGetValueW(
          HKEY_LOCAL_MACHINE,
          L"SOFTWARE\\Microsoft\\Cryptography",
          L"MachineGuid",
          flags,
          nullptr,
          value.data(),
          &bytes) != ERROR_SUCCESS) {
    return {};
  }
  while (!value.empty() && value.back() == L'\0') {
    value.pop_back();
  }
  return utf8(value);
}

[[nodiscard]] std::string read_volume_serial() {
  std::array<wchar_t, MAX_PATH> directory{};
  const UINT length = GetSystemDirectoryW(
      directory.data(), static_cast<UINT>(directory.size()));
  if (length < 3U || length >= directory.size() || directory[1] != L':') {
    return {};
  }
  const std::array<wchar_t, 4> root = {
      directory[0], L':', L'\\', L'\0'};
  DWORD serial = 0;
  if (!GetVolumeInformationW(
          root.data(), nullptr, 0, &serial, nullptr, nullptr, nullptr, 0) ||
      serial == 0) {
    return {};
  }
  return std::to_string(serial);
}

[[nodiscard]] std::string architecture_name() {
  SYSTEM_INFO information{};
  GetNativeSystemInfo(&information);
  switch (information.wProcessorArchitecture) {
    case PROCESSOR_ARCHITECTURE_AMD64:
      return "AMD64";
    case PROCESSOR_ARCHITECTURE_INTEL:
      return "x86";
    case PROCESSOR_ARCHITECTURE_ARM64:
      return "ARM64";
    case PROCESSOR_ARCHITECTURE_ARM:
      return "ARM";
    default:
      return std::to_string(information.wProcessorArchitecture);
  }
}

[[nodiscard]] std::string computer_name() {
  std::array<wchar_t, MAX_COMPUTERNAME_LENGTH + 1> value{};
  DWORD length = static_cast<DWORD>(value.size());
  return GetComputerNameW(value.data(), &length)
      ? utf8(std::wstring_view(value.data(), length))
      : std::string{};
}

}  // namespace

std::string compute_machine_fingerprint(
    const std::string_view platform,
    const std::string_view architecture,
    const std::string_view machine_guid,
    const std::string_view volume_serial,
    const std::string_view fallback_host) {
  std::string raw;
  for (const auto value : {platform, architecture, machine_guid, volume_serial}) {
    if (value.empty()) {
      continue;
    }
    if (!raw.empty()) {
      raw.push_back('|');
    }
    raw.append(value);
  }
  if (raw.empty()) {
    raw.assign(fallback_host);
  }
  if (raw.empty() || raw.size() > 1024U) {
    throw std::runtime_error("license_machine_identity_unavailable");
  }
  return lower_hex(sha256(raw));
}

std::optional<std::string> current_windows_machine_fingerprint() noexcept {
  try {
    return compute_machine_fingerprint(
        "Windows",
        architecture_name(),
        read_machine_guid(),
        read_volume_serial(),
        computer_name());
  } catch (...) {
    return std::nullopt;
  }
}

}  // namespace sonar::fishing::entitlement
