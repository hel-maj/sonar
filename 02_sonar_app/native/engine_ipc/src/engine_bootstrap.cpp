#include "engine_bootstrap.h"

#include <Windows.h>

#include <charconv>
#include <optional>
#include <stdexcept>
#include <string_view>
#include <system_error>
#include <utility>

#include "sonar/fishing/entitlement/windows_machine_fingerprint.h"

namespace sonar::fishing::engine_ipc::runtime {
namespace {

#if SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS
constexpr std::string_view kOfflineHostBuildId = "offline-host-0.1.0";
constexpr std::string_view kOfflineEngineBuildId = "offline-engine-0.1.0";
constexpr std::string_view kOfflineBundleManifestHash =
    "offline-bundle-manifest";
#endif

[[noreturn]] void throw_native_error(
    const std::string_view reason,
    const DWORD native_error = GetLastError()) {
  throw std::runtime_error(
      std::string(reason) + ":" + std::to_string(native_error));
}

[[nodiscard]] std::wstring require_environment(const wchar_t* name) {
  const DWORD required = GetEnvironmentVariableW(name, nullptr, 0);
  if (required == 0) {
    throw_native_error("offline_bootstrap_missing");
  }
  std::wstring value(required, L'\0');
  const DWORD copied = GetEnvironmentVariableW(name, value.data(), required);
  if (copied == 0 || copied >= required) {
    throw_native_error("offline_bootstrap_invalid");
  }
  value.resize(copied);
  return value;
}

[[nodiscard]] std::string require_ascii_environment(const wchar_t* name) {
  const std::wstring value = require_environment(name);
  std::string result;
  result.reserve(value.size());
  for (const wchar_t character : value) {
    if (character < L' ' || character > L'~') {
      throw std::runtime_error("offline_bootstrap_not_ascii");
    }
    result.push_back(static_cast<char>(character));
  }
  return result;
}

[[nodiscard]] std::optional<std::string> optional_ascii_environment(
    const wchar_t* name) {
  const DWORD required = GetEnvironmentVariableW(name, nullptr, 0);
  if (required == 0) {
    return std::nullopt;
  }
  std::wstring value(required, L'\0');
  const DWORD copied = GetEnvironmentVariableW(name, value.data(), required);
  if (copied == 0 || copied >= required) {
    throw_native_error("engine_bootstrap_invalid");
  }
  value.resize(copied);
  std::string result;
  result.reserve(value.size());
  for (const wchar_t character : value) {
    if (character < L' ' || character > L'~') {
      throw std::runtime_error("engine_bootstrap_not_ascii");
    }
    result.push_back(static_cast<char>(character));
  }
  return result;
}

[[nodiscard]] std::string require_production_environment(
    const wchar_t* name,
    const std::string_view missing_reason) {
  auto value = optional_ascii_environment(name);
  if (!value.has_value() || value->empty()) {
    throw std::runtime_error(std::string(missing_reason));
  }
  return std::move(*value);
}

[[nodiscard]] engine_authority_mode require_authority_mode() {
  const auto offline = optional_ascii_environment(
      L"SONAR_FISHING_OFFLINE_GATE");
  const auto mode = optional_ascii_environment(
      L"SONAR_FISHING_ENGINE_MODE");
#if SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS
  if (offline == "1" && !mode.has_value()) {
    return engine_authority_mode::offline_diagnostics;
  }
#endif
  if (!offline.has_value() && mode == "production") {
    return engine_authority_mode::production;
  }
#if defined(SONAR_FISHING_DEVELOPER_FULL_ACCESS)
  if (!offline.has_value() && mode == "developer-full-access") {
    return engine_authority_mode::developer_full_access;
  }
#endif
  throw std::runtime_error("production_authority_gate_closed");
}

[[nodiscard]] engine_build_identity require_build_identity(
    const engine_authority_mode authority_mode) {
#if SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS
  if (authority_mode == engine_authority_mode::offline_diagnostics) {
    return engine_build_identity{
        .host_build_id = std::string(kOfflineHostBuildId),
        .engine_build_id = std::string(kOfflineEngineBuildId),
        .bundle_manifest_hash = std::string(kOfflineBundleManifestHash),
    };
  }
#else
  if (authority_mode == engine_authority_mode::offline_diagnostics) {
    throw std::runtime_error("production_authority_required");
  }
#endif
  const bool developer_full_access =
      authority_mode == engine_authority_mode::developer_full_access;
  return engine_build_identity{
      .host_build_id = require_production_environment(
          L"SONAR_FISHING_HOST_BUILD_ID",
          developer_full_access
              ? "developer_host_build_id_missing"
              : "production_host_build_id_missing"),
      .engine_build_id = require_production_environment(
          L"SONAR_FISHING_ENGINE_BUILD_ID",
          developer_full_access
              ? "developer_engine_build_id_missing"
              : "production_engine_build_id_missing"),
      .bundle_manifest_hash = require_production_environment(
          L"SONAR_FISHING_BUNDLE_MANIFEST_HASH",
          developer_full_access
              ? "developer_bundle_manifest_hash_missing"
              : "production_bundle_manifest_hash_missing"),
  };
}

[[nodiscard]] std::uint32_t require_process_id() {
  const std::string value = require_ascii_environment(
      L"SONAR_FISHING_EXPECTED_HOST_PID");
  std::uint32_t process_id = 0;
  const auto [end, error] = std::from_chars(
      value.data(), value.data() + value.size(), process_id);
  if (error != std::errc{} || end != value.data() + value.size() ||
      process_id == 0) {
    throw std::runtime_error("offline_host_pid_invalid");
  }
  return process_id;
}

[[nodiscard]] unsigned char hex_nibble(const char value) {
  if (value >= '0' && value <= '9') {
    return static_cast<unsigned char>(value - '0');
  }
  if (value >= 'A' && value <= 'F') {
    return static_cast<unsigned char>(value - 'A' + 10);
  }
  if (value >= 'a' && value <= 'f') {
    return static_cast<unsigned char>(value - 'a' + 10);
  }
  throw std::runtime_error("offline_nonce_not_hex");
}

[[nodiscard]] std::string require_bootstrap_nonce() {
  const std::string encoded = require_ascii_environment(
      L"SONAR_FISHING_BOOTSTRAP_NONCE");
  if (encoded.size() != 64) {
    throw std::runtime_error("offline_nonce_length_invalid");
  }
  std::string decoded(encoded.size() / 2, '\0');
  for (std::size_t index = 0; index < decoded.size(); ++index) {
    decoded[index] = static_cast<char>(
        (hex_nibble(encoded[index * 2]) << 4U) |
        hex_nibble(encoded[index * 2 + 1]));
  }
  return decoded;
}

}  // namespace

engine_bootstrap_configuration load_engine_bootstrap() {
  const auto authority_mode = require_authority_mode();
  const auto build_identity = require_build_identity(authority_mode);
  const auto machine_fingerprint =
      authority_mode == engine_authority_mode::production
          ? sonar::fishing::entitlement::current_windows_machine_fingerprint()
          : std::optional<std::string>{std::string{}};
  if (!machine_fingerprint.has_value()) {
    throw std::runtime_error("license_machine_identity_unavailable");
  }
  return engine_bootstrap_configuration{
      .authority_mode = authority_mode,
      .build_identity = build_identity,
      .machine_fingerprint = *machine_fingerprint,
      .control_pipe_name = require_environment(
          L"SONAR_FISHING_CONTROL_PIPE"),
      .event_pipe_name = require_environment(L"SONAR_FISHING_EVENT_PIPE"),
      .nonce = require_bootstrap_nonce(),
      .host_process_id = require_process_id(),
      .session_id = require_ascii_environment(L"SONAR_FISHING_SESSION_ID"),
  };
}

}  // namespace sonar::fishing::engine_ipc::runtime
