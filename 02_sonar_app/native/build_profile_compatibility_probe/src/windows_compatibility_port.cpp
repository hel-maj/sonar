#include "windows_compatibility_port.h"

#include <algorithm>
#include <chrono>
#include <memory>
#include <optional>
#include <string>
#include <utility>

#include "candidate_reeling_validator.h"
#include "sonar/fishing/memory_observation/memory_observation.h"
#include "sonar/fishing/runtime_platform/target_resolver.h"
#include "sonar/platform/windows/window.hpp"
#include "windows_forensic_memory_connector.h"

namespace sonar::fishing::build_profile_compatibility_probe {
namespace {

namespace memory = sonar::fishing::memory_observation;
namespace platform = sonar::fishing::runtime_platform;
namespace windows = sonar::platform::windows;

[[nodiscard]] readiness_reason map_window_reason(
    const windows::window_observation_reason reason) noexcept {
  using value = windows::window_observation_reason;
  switch (reason) {
    case value::not_foreground:
      return readiness_reason::game_window_not_foreground;
    case value::owner_changed:
    case value::process_generation_changed:
    case value::identity_changed:
    case value::geometry_changed:
      return readiness_reason::game_target_changed;
    default:
      return readiness_reason::game_window_unavailable;
  }
}

class windows_compatibility_port final : public compatibility_port {
 public:
  windows_compatibility_port()
      : memory_connector_(make_windows_forensic_memory_connector()) {}

  [[nodiscard]] identity_probe inspect_identity() noexcept override {
    target_.reset();
    baseline_.reset();
    candidate_sha256_.clear();
    try {
      const auto resolved = target_resolver_.resolve();
      if (!resolved.ready() || !resolved.target.has_value()) {
        if (resolved.reason == "game_process_unavailable") {
          return {.reason = readiness_reason::game_process_unavailable};
        }
        return {
            .process_ready = true,
            .reason = resolved.reason == "game_target_ambiguous"
                ? readiness_reason::game_target_ambiguous
                : readiness_reason::game_window_unavailable,
        };
      }
      const auto foreground = windows::validate_foreground_window(
          *resolved.target);
      if (!foreground.ready() || !foreground.snapshot.has_value()) {
        return {
            .process_ready = true,
            .reason = map_window_reason(foreground.reason),
        };
      }
      if (!foreground.snapshot->same_identity(*resolved.target) ||
          !foreground.snapshot->same_geometry(*resolved.target)) {
        return {
            .process_ready = true,
            .reason = readiness_reason::game_target_changed,
        };
      }
      if (memory_connector_ == nullptr) {
        return {
            .process_ready = true,
            .window_ready = true,
            .reason = readiness_reason::game_build_unavailable,
        };
      }

      constexpr std::string_view baseline_id =
          "majestic-gta5-677e4e35-v1";
      constexpr std::uint32_t baseline_revision = 1U;
      const auto baselines = memory::embedded_memory_build_profiles();
      const memory::embedded_memory_build_profile* baseline = nullptr;
      for (const auto& profile : baselines) {
        if (profile.profile_id != baseline_id ||
            profile.profile_revision != baseline_revision) {
          continue;
        }
        if (baseline != nullptr) {
          return {
              .process_ready = true,
              .window_ready = true,
              .reason = readiness_reason::baseline_profile_unavailable,
          };
        }
        baseline = &profile;
      }
      if (baseline == nullptr) {
        return {
            .process_ready = true,
            .window_ready = true,
            .reason = readiness_reason::baseline_profile_unavailable,
        };
      }
      std::string connector_reason;
      auto session = memory_connector_->connect(
          memory::process_role::game,
          foreground.snapshot->process.process_id,
          connector_reason);
      if (!session ||
          session->identity().generation != foreground.snapshot->process ||
          !session->generation_current()) {
        return {
            .process_ready = true,
            .window_ready = true,
            .reason = readiness_reason::game_build_unavailable,
        };
      }

      baseline_ = *baseline;
      candidate_sha256_ = session->identity().image_sha256;
      target_ = *foreground.snapshot;
      return {
          .process_ready = true,
          .window_ready = true,
          .hash_ready = true,
          .baseline_ready = true,
          .candidate_sha256 = candidate_sha256_,
          .baseline_profile_id = baseline_->profile_id,
          .baseline_profile_revision = baseline_->profile_revision,
          .reason = readiness_reason::ready,
      };
    } catch (...) {
      return {.reason = readiness_reason::internal_error};
    }
  }

  [[nodiscard]] validation_probe validate_candidate() noexcept override {
    if (!target_.has_value() || !baseline_.has_value() ||
        candidate_sha256_.empty() ||
        memory_connector_ == nullptr) {
      return {.reason = readiness_reason::candidate_identity_invalid};
    }
    try {
      const auto foreground_before = windows::validate_foreground_window(
          *target_);
      if (!foreground_before.ready() ||
          !foreground_before.snapshot.has_value()) {
        return {.reason = map_window_reason(foreground_before.reason)};
      }
      if (!foreground_before.snapshot->same_identity(*target_) ||
          !foreground_before.snapshot->same_geometry(*target_)) {
        return {.reason = readiness_reason::game_target_changed};
      }
      const auto captured_at = static_cast<std::uint64_t>(
          std::chrono::duration_cast<std::chrono::nanoseconds>(
              std::chrono::steady_clock::now().time_since_epoch())
              .count());
      if (captured_at == 0U) {
        return {.reason = readiness_reason::internal_error};
      }

      const auto validation = validate_candidate_reeling(
          *memory_connector_,
          *baseline_,
          candidate_sha256_,
          target_->process,
          1U,
          captured_at);
      if (validation.reason != readiness_reason::ready) {
        return validation;
      }
      const auto foreground_after = windows::validate_foreground_window(
          *target_);
      if (!foreground_after.ready() ||
          !foreground_after.snapshot.has_value()) {
        return {
            .patterns_unique = validation.patterns_unique,
            .fish_identity_ready = validation.fish_identity_ready,
            .reason = map_window_reason(foreground_after.reason),
        };
      }
      if (!foreground_after.snapshot->same_identity(*target_) ||
          !foreground_after.snapshot->same_geometry(*target_)) {
        return {
            .patterns_unique = validation.patterns_unique,
            .fish_identity_ready = validation.fish_identity_ready,
            .reason = readiness_reason::game_target_changed,
        };
      }
      return validation;
    } catch (...) {
      return {.reason = readiness_reason::internal_error};
    }
  }

 private:
  platform::windows_game_target_resolver target_resolver_;
  std::unique_ptr<memory::memory_connector> memory_connector_;
  std::optional<windows::window_client_snapshot> target_;
  std::optional<memory::embedded_memory_build_profile> baseline_;
  std::string candidate_sha256_;
};

}  // namespace

std::unique_ptr<compatibility_port> make_windows_compatibility_port() {
  return std::make_unique<windows_compatibility_port>();
}

}  // namespace sonar::fishing::build_profile_compatibility_probe
