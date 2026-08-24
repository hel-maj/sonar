#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <stop_token>
#include <string>

#include "sonar/fishing/automation_adapters/frame_semantics.h"
#include "sonar/fishing/automation_adapters/common_inventory_open.h"
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

class fishing_memory_source {
 public:
  virtual ~fishing_memory_source() = default;
  // One in-Engine aggregate operation. A positive reeling stage requests only
  // latency-critical reeling evidence; other frames request inventory. No
  // field is exposed as a separate Host/IPC call.
  [[nodiscard]] virtual memory_snapshot_result capture(
      std::uint64_t sequence,
      std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation,
      bool reeling_stage_visible)
      noexcept = 0;
};

class unavailable_fishing_memory_source final : public fishing_memory_source {
 public:
  [[nodiscard]] memory_snapshot_result capture(
      std::uint64_t sequence,
      std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation,
      bool reeling_stage_visible)
      noexcept override;
};

class resolved_fishing_memory_source final : public fishing_memory_source {
 public:
  explicit resolved_fishing_memory_source(
      std::unique_ptr<memory_observation::memory_connector> connector,
      std::unique_ptr<inventory_open_source> inventory_open,
      std::unique_ptr<inventory_retry_clock> retry_clock);

  [[nodiscard]] memory_snapshot_result capture(
      std::uint64_t sequence,
      std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation,
      bool reeling_stage_visible)
      noexcept override;

 private:
  std::unique_ptr<memory_observation::memory_connector> connector_;
  std::unique_ptr<memory_observation::memory_capture_plan_resolver> resolver_;
  std::unique_ptr<memory_observation::memory_observer> observer_;
  std::unique_ptr<inventory_open_source> inventory_open_;
  std::optional<sonar::platform::windows::process_generation>
      inventory_game_generation_;
  std::unique_ptr<inventory_retry_clock> retry_clock_;
  std::uint32_t inventory_unknown_streak_{};
  std::uint64_t inventory_retry_not_before_ns_{};
  std::string inventory_unknown_reason_;
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
