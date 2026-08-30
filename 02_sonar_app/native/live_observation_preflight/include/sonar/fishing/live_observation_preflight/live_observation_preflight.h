#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace sonar::fishing::live_observation_preflight {

inline constexpr std::uint32_t result_schema_version = 1U;
inline constexpr std::uint64_t maximum_capture_pixels = 16'777'216U;

enum class readiness_reason : std::uint8_t {
  ready = 0,
  game_process_unavailable,
  game_window_unavailable,
  game_target_ambiguous,
  game_window_not_foreground,
  game_target_changed,
  capture_geometry_unsupported,
  game_build_unavailable,
  game_build_unsupported,
  capture_unavailable,
  detector_unavailable,
  memory_unavailable,
  memory_module_scan_incomplete,
  memory_semantic_layout_unresolved,
  memory_semantic_layout_ambiguous,
  memory_active_fish_unavailable,
  memory_active_fish_incomplete,
  memory_active_fish_ambiguous,
  memory_capture_unavailable,
  internal_error,
};

struct target_probe final {
  bool process_ready{};
  bool window_ready{};
  std::uint32_t width{};
  std::uint32_t height{};
  readiness_reason reason{readiness_reason::internal_error};
};

struct build_probe final {
  bool build_ready{};
  bool profile_ready{};
  readiness_reason reason{readiness_reason::internal_error};
};

struct observation_probe final {
  bool ready{};
  readiness_reason reason{readiness_reason::internal_error};
};

class observation_port {
 public:
  virtual ~observation_port() = default;
  [[nodiscard]] virtual target_probe resolve_target() noexcept = 0;
  [[nodiscard]] virtual build_probe inspect_build() noexcept = 0;
  [[nodiscard]] virtual observation_probe capture_and_detect() noexcept = 0;
  [[nodiscard]] virtual observation_probe capture_memory() noexcept = 0;
};

struct preflight_result final {
  std::uint32_t schema_version{result_schema_version};
  bool ready{};
  bool process_ready{};
  bool window_ready{};
  bool build_ready{};
  bool profile_ready{};
  bool capture_ready{};
  bool memory_ready{};
  readiness_reason reason{readiness_reason::internal_error};
};

[[nodiscard]] preflight_result run(observation_port& port) noexcept;
[[nodiscard]] readiness_reason classify_memory_failure_reason(
    std::string_view reason) noexcept;
[[nodiscard]] std::string_view reason_key(readiness_reason reason) noexcept;
[[nodiscard]] std::string serialize_json(const preflight_result& result);

}  // namespace sonar::fishing::live_observation_preflight
