#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <stop_token>
#include <string>

#include "sonar/fishing/automation_adapters/frame_semantics.h"
#include "sonar/fishing/automation_adapters/runtime_policy.h"
#include "sonar/fishing/fishing_episode/fishing_episode.h"
#include "sonar/fishing/runtime_platform/automation_lease.h"
#include "sonar/fishing/runtime_platform/platform_capture.h"
#include "sonar/fishing/runtime_platform/platform_input.h"
#include "sonar/fishing/stage_detection/fishing_stage_detector.h"

namespace sonar::fishing::automation_adapters {

struct memory_snapshot_result final {
  std::optional<memory_observation::coherent_memory_snapshot> snapshot;
  std::string reason;
};

enum class memory_capture_scope : std::uint8_t {
  reeling,
  inventory_state,
};

class fishing_memory_source {
 public:
  virtual ~fishing_memory_source() = default;
  [[nodiscard]] virtual memory_snapshot_result capture(
      memory_capture_scope scope,
      std::uint64_t sequence,
      std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation)
      noexcept = 0;
};

class unavailable_fishing_memory_source final : public fishing_memory_source {
 public:
  [[nodiscard]] memory_snapshot_result capture(
      memory_capture_scope scope,
      std::uint64_t sequence,
      std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation)
      noexcept override;
};

class resolved_fishing_memory_source final : public fishing_memory_source {
 public:
  explicit resolved_fishing_memory_source(
      std::unique_ptr<memory_observation::memory_connector> connector);

  [[nodiscard]] memory_snapshot_result capture(
      memory_capture_scope scope,
      std::uint64_t sequence,
      std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation)
      noexcept override;

 private:
  std::unique_ptr<memory_observation::memory_connector> connector_;
  std::unique_ptr<memory_observation::memory_capture_plan_resolver> resolver_;
  std::unique_ptr<memory_observation::memory_observer> observer_;
};

class frame_fishing_observer final
    : public fishing_episode::fishing_episode_observer {
 public:
  frame_fishing_observer(
      runtime_platform::client_capture_source& capture,
      stage_detection::majestic_fishing_stage_detector& stage_detector,
      fishing_memory_source& memory,
      mutable_runtime_policy_source& policy) noexcept;

  [[nodiscard]] fishing_episode::fishing_episode_observation observe(
      std::stop_token stop_token) override;

 private:
  runtime_platform::client_capture_source& capture_;
  stage_detection::majestic_fishing_stage_detector& stage_detector_;
  fishing_memory_source& memory_;
  mutable_runtime_policy_source& policy_;
};

class guarded_fishing_mutation_port final
    : public fishing_episode::fishing_mutation_port {
 public:
  guarded_fishing_mutation_port(
      runtime_platform::automation_lease_coordinator& leases,
      immediate_action_gate& final_gate,
      runtime_platform::platform_mutation_sink& sink) noexcept;

  [[nodiscard]] std::unique_ptr<fishing_episode::fishing_mutation_session>
  acquire(
      const fishing_episode::fishing_episode_request& request,
      std::stop_token stop_token,
      std::string& reason) override;

 private:
  runtime_platform::automation_lease_coordinator& leases_;
  immediate_action_gate& final_gate_;
  runtime_platform::platform_mutation_sink& sink_;
};

}  // namespace sonar::fishing::automation_adapters
