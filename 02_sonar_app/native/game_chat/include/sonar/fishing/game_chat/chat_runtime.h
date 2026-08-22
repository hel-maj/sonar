#pragma once

#include <optional>
#include <string>

#include "sonar/fishing/game_chat/chat_observation.h"
#include "sonar/fishing/runtime_platform/automation_lease.h"
#include "sonar/fishing/runtime_safety/runtime_safety.h"

namespace sonar::fishing::game_chat {

struct chat_runtime_policy final {
  bool entitlement_valid{};
  bool settings_current{};
  bool lifecycle_allows_input{};
};

class chat_runtime_policy_source {
 public:
  virtual ~chat_runtime_policy_source() = default;
  [[nodiscard]] virtual chat_runtime_policy snapshot() = 0;
};

class chat_final_gate {
 public:
  virtual ~chat_final_gate() = default;
  [[nodiscard]] virtual chat_input_result revalidate(
      const chat_input_intent& intent) = 0;
};

// Product adapter over the frozen Common process/window/input mechanisms. It
// reads policy anew and revalidates the target immediately before every real
// platform mutation; the authorization is never cached or transferred.
class runtime_safety_chat_final_gate final : public chat_final_gate {
 public:
  runtime_safety_chat_final_gate(
      runtime_safety::runtime_target_guard& target,
      chat_runtime_policy_source& policy) noexcept;

  [[nodiscard]] chat_input_result revalidate(
      const chat_input_intent& intent) override;

 private:
  runtime_safety::runtime_target_guard& target_;
  chat_runtime_policy_source& policy_;
};

class chat_platform_mutation_sink {
 public:
  virtual ~chat_platform_mutation_sink() = default;
  [[nodiscard]] virtual chat_input_result apply(
      const chat_input_intent& intent) = 0;
};

using chat_input_lease = runtime_platform::automation_lease;
using chat_input_lease_coordinator =
    runtime_platform::automation_lease_coordinator;

class guarded_chat_input_port final : public chat_input_port {
 public:
  guarded_chat_input_port(
      const chat_input_lease& lease,
      chat_input_lease_coordinator& coordinator,
      chat_final_gate& final_gate,
      chat_platform_mutation_sink& sink) noexcept;

  [[nodiscard]] chat_input_result apply(
      const chat_input_intent& intent) override;

 private:
  const chat_input_lease& lease_;
  chat_input_lease_coordinator& coordinator_;
  chat_final_gate& final_gate_;
  chat_platform_mutation_sink& sink_;
};

class disabled_chat_final_gate final : public chat_final_gate {
 public:
  [[nodiscard]] chat_input_result revalidate(
      const chat_input_intent& intent) override;
};

class disabled_chat_platform_mutation_sink final
    : public chat_platform_mutation_sink {
 public:
  [[nodiscard]] chat_input_result apply(
      const chat_input_intent& intent) override;
};

class chat_episode_orchestrator final {
 public:
  chat_episode_orchestrator(
      chat_capture_source& capture,
      chat_frame_detector& detector,
      chat_input_lease_coordinator& leases,
      chat_final_gate& final_gate,
      chat_platform_mutation_sink& sink) noexcept;

  [[nodiscard]] chat_episode_result run(
      const chat_episode_request& request) const;

 private:
  chat_capture_source& capture_;
  chat_frame_detector& detector_;
  chat_input_lease_coordinator& leases_;
  chat_final_gate& final_gate_;
  chat_platform_mutation_sink& sink_;
};

}  // namespace sonar::fishing::game_chat
