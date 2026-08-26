#include "windows_observation_port.h"

#include <algorithm>
#include <cwctype>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

#include "sonar/fishing/memory_observation/memory_observation.h"
#include "sonar/fishing/runtime_platform/platform_capture.h"
#include "sonar/fishing/runtime_platform/target_resolver.h"
#include "sonar/fishing/stage_detection/fishing_stage_detector.h"
#include "sonar/platform/windows/window.hpp"

namespace sonar::fishing::live_observation_preflight {
namespace {

namespace memory = sonar::fishing::memory_observation;
namespace platform = sonar::fishing::runtime_platform;
namespace stage = sonar::fishing::stage_detection;
namespace windows = sonar::platform::windows;

[[nodiscard]] bool same_image_name(
    const std::wstring_view left,
    const std::wstring_view right) noexcept {
  return left.size() == right.size() &&
      std::equal(
          left.begin(), left.end(), right.begin(),
          [](const wchar_t first, const wchar_t second) {
            return std::towlower(first) == std::towlower(second);
          });
}

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

class windows_observation_port final : public observation_port {
 public:
  windows_observation_port()
      : memory_connector_(memory::make_windows_memory_connector()) {}

  [[nodiscard]] target_probe resolve_target() noexcept override {
    target_.reset();
    frame_.reset();
    try {
      const auto resolved = target_resolver_.resolve();
      if (!resolved.ready() || !resolved.target.has_value()) {
        if (resolved.reason == "game_process_unavailable") {
          return {
              .reason = readiness_reason::game_process_unavailable,
          };
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
      target_ = *foreground.snapshot;
      return {
          .process_ready = true,
          .window_ready = true,
          .width = target_->width,
          .height = target_->height,
          .reason = readiness_reason::ready,
      };
    } catch (...) {
      return {.reason = readiness_reason::internal_error};
    }
  }

  [[nodiscard]] build_probe inspect_build() noexcept override {
    if (!target_.has_value() || memory_connector_ == nullptr) {
      return {.reason = readiness_reason::game_build_unavailable};
    }
    try {
      std::string connector_reason;
      auto session = memory_connector_->connect(
          memory::process_role::game,
          target_->process.process_id,
          connector_reason);
      if (!session || session->identity().generation != target_->process ||
          !session->generation_current()) {
        return {.reason = readiness_reason::game_build_unavailable};
      }
      if (session->identity().admission !=
              memory::process_admission::trusted_publisher_runtime ||
          session->identity().authority_fingerprint == 0U) {
        return {.reason = readiness_reason::game_build_unavailable};
      }
      const auto profiles = memory::embedded_memory_build_profiles();
      const auto semantic_layout_available = std::ranges::any_of(
          profiles,
          [&](const auto& profile) {
            return same_image_name(
                profile.game.image_name, session->identity().image_name);
          });
      if (!semantic_layout_available) {
        return {
            .build_ready = true,
            .reason = readiness_reason::game_build_unsupported,
        };
      }
      return {
          .build_ready = true,
          .profile_ready = true,
          .reason = readiness_reason::ready,
      };
    } catch (...) {
      return {.reason = readiness_reason::game_build_unavailable};
    }
  }

  [[nodiscard]] observation_probe capture_and_detect() noexcept override {
    frame_.reset();
    if (!target_.has_value()) {
      return {.reason = readiness_reason::capture_unavailable};
    }
    try {
      platform::win32_client_capture_source source(*target_);
      auto captured = source.capture();
      if (!captured.frame.has_value() || !captured.frame->valid()) {
        return {.reason = readiness_reason::capture_unavailable};
      }
      if (!captured.frame->target.same_identity(*target_) ||
          !captured.frame->target.same_geometry(*target_)) {
        return {.reason = readiness_reason::game_target_changed};
      }
      const stage::majestic_fishing_stage_detector detector;
      const auto detected = detector.detect({
          .width = captured.frame->width,
          .height = captured.frame->height,
          .stride_bytes = captured.frame->stride_bytes,
          .pixels = captured.frame->bgr24,
      });
      if (!detected.error.empty()) {
        return {.reason = readiness_reason::detector_unavailable};
      }
      frame_ = std::move(captured.frame);
      return {.ready = true, .reason = readiness_reason::ready};
    } catch (...) {
      return {.reason = readiness_reason::capture_unavailable};
    }
  }

  [[nodiscard]] observation_probe capture_memory() noexcept override {
    if (!target_.has_value() || !frame_.has_value() ||
        memory_connector_ == nullptr) {
      return {.reason = readiness_reason::memory_unavailable};
    }
    try {
      memory::memory_capture_plan_resolver resolver(*memory_connector_);
      auto resolved = resolver.resolve_reeling(
          frame_->sequence,
          frame_->captured_at_steady_ns,
          target_->process);
      if (!resolved.ready() || !resolved.profile.has_value() ||
          !resolved.plan.has_value()) {
        return {.reason = readiness_reason::memory_unavailable};
      }
      memory::memory_observer observer(*memory_connector_);
      const auto captured = observer.capture(*resolved.profile, *resolved.plan);
      if (!captured.ready() || !captured.snapshot.has_value()) {
        return {.reason = readiness_reason::memory_unavailable};
      }
      const auto& snapshot = *captured.snapshot;
      if (snapshot.sequence != frame_->sequence ||
          snapshot.captured_at_steady_ns != frame_->captured_at_steady_ns ||
          snapshot.game_generation != target_->process ||
          snapshot.profile_id != resolved.profile->profile_id ||
          snapshot.profile_revision != resolved.profile->profile_revision) {
        return {.reason = readiness_reason::game_target_changed};
      }
      return {.ready = true, .reason = readiness_reason::ready};
    } catch (...) {
      return {.reason = readiness_reason::memory_unavailable};
    }
  }

 private:
  platform::windows_game_target_resolver target_resolver_;
  std::unique_ptr<memory::memory_connector> memory_connector_;
  std::optional<windows::window_client_snapshot> target_;
  std::optional<platform::client_frame> frame_;
};

}  // namespace

std::unique_ptr<observation_port> make_windows_observation_port() {
  return std::make_unique<windows_observation_port>();
}

}  // namespace sonar::fishing::live_observation_preflight
