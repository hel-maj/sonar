#pragma once

#include <cstdint>
#include <string_view>

#include "sonar/fishing/engine_ipc/engine_mode.h"

namespace sonar::fishing::engine_ipc {

struct accepted_entitlement final {
  std::uint64_t generation{};
  std::int64_t expires_unix_seconds{};

  [[nodiscard]] bool valid_at(std::int64_t now_unix_seconds) const noexcept;
  void clear() noexcept;
};

struct start_session_context final {
  engine_authority_mode authority_mode{engine_authority_mode::offline_diagnostics};
  bool side_effects_negotiated{};
  std::uint64_t expected_settings_revision{};
  std::uint64_t accepted_settings_revision{};
  bool settings_snapshot_present{};
  accepted_entitlement entitlement{};
  std::int64_t now_unix_seconds{};
  bool capability_composition_ready{};
  std::string_view capability_reason;
};

struct session_transition final {
  bool accepted{};
  std::string_view status;
  std::string_view reason;
};

struct session_completion_reconciliation final {
  bool transitioned{};
  std::string_view correlation_id;
};

class fishing_session_lifecycle final {
 public:
  [[nodiscard]] session_transition validate_start(
      const start_session_context& context) const noexcept;
  [[nodiscard]] session_transition start(
      const start_session_context& context) noexcept;
  [[nodiscard]] session_transition stop() noexcept;
  [[nodiscard]] session_completion_reconciliation reconcile_completion(
      bool operation_completed,
      std::string_view active_start_correlation_id) noexcept;

  [[nodiscard]] bool running() const noexcept;
  [[nodiscard]] std::uint64_t settings_revision() const noexcept;
  [[nodiscard]] std::uint64_t entitlement_generation() const noexcept;

 private:
  bool running_{};
  std::uint64_t settings_revision_{};
  std::uint64_t entitlement_generation_{};
};

}  // namespace sonar::fishing::engine_ipc
