#pragma once

#include <cstddef>
#include <cstdint>
#include <mutex>
#include <string>

#include "sonar/fishing/runtime_safety/runtime_safety.h"

namespace sonar::fishing::automation_adapters {

struct runtime_policy_snapshot final {
  bool entitlement_valid{};
  bool settings_current{};
  bool lifecycle_allows_input{};
  std::uint64_t settings_revision{};
  std::uint64_t entitlement_revision{};
  std::int64_t entitlement_expires_unix_seconds{};
  std::uint64_t lifecycle_revision{};
  std::uint64_t latest_observation_sequence{};

  [[nodiscard]] bool entitlement_valid_at(
      std::int64_t now_unix_seconds) const noexcept;
};

class runtime_policy_source {
 public:
  virtual ~runtime_policy_source() = default;
  [[nodiscard]] virtual runtime_policy_snapshot snapshot() const = 0;
};

class mutable_runtime_policy_source final : public runtime_policy_source {
 public:
  [[nodiscard]] runtime_policy_snapshot snapshot() const override;
  void publish(runtime_policy_snapshot value);
  [[nodiscard]] bool refresh_entitlement_expiry(
      std::uint64_t admitted_entitlement_revision,
      std::int64_t expires_unix_seconds) noexcept;
  void stop() noexcept;
  void observe(std::uint64_t sequence) noexcept;

 private:
  mutable std::mutex mutex_;
  runtime_policy_snapshot value_;
};

struct action_claim final {
  enum class effect_kind : std::uint8_t {
    input_packets,
    system_terminal_action,
  };

  std::uint64_t expected_observation_sequence{};
  std::uint64_t expected_settings_revision{};
  std::uint64_t expected_entitlement_revision{};
  std::uint64_t expected_lifecycle_revision{};
  std::size_t packet_count{};
  bool foreground_required{true};
  bool cleanup_only{};
  effect_kind effect{effect_kind::input_packets};
};

struct action_gate_result final {
  bool accepted{};
  std::string reason;
};

class immediate_action_gate {
 public:
  virtual ~immediate_action_gate() = default;
  [[nodiscard]] virtual action_gate_result revalidate(
      const action_claim& claim) noexcept = 0;
};

class runtime_safety_action_gate final : public immediate_action_gate {
 public:
  runtime_safety_action_gate(
      runtime_safety::runtime_target_guard& target,
      const runtime_policy_source& policy) noexcept;

  [[nodiscard]] action_gate_result revalidate(
      const action_claim& claim) noexcept override;

 private:
  runtime_safety::runtime_target_guard& target_;
  const runtime_policy_source& policy_;
};

}  // namespace sonar::fishing::automation_adapters
