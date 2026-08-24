#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace sonar::fishing::build_profile_compatibility_probe {

inline constexpr std::uint32_t result_schema_version = 1U;

enum class readiness_reason : std::uint8_t {
  ready = 0,
  game_process_unavailable,
  game_window_unavailable,
  game_target_ambiguous,
  game_window_not_foreground,
  game_target_changed,
  game_build_unavailable,
  baseline_profile_unavailable,
  candidate_identity_invalid,
  pattern_scan_incomplete,
  pattern_ambiguous,
  pattern_unresolved,
  active_fish_unavailable,
  active_fish_ambiguous,
  coherent_snapshot_unavailable,
  internal_error,
};

struct identity_probe final {
  bool process_ready{};
  bool window_ready{};
  bool hash_ready{};
  bool baseline_ready{};
  std::string candidate_sha256;
  std::string baseline_profile_id;
  std::uint32_t baseline_profile_revision{};
  readiness_reason reason{readiness_reason::internal_error};
};

struct validation_probe final {
  bool patterns_unique{};
  bool fish_identity_ready{};
  bool snapshot_ready{};
  readiness_reason reason{readiness_reason::internal_error};
};

class compatibility_port {
 public:
  virtual ~compatibility_port() = default;
  [[nodiscard]] virtual identity_probe inspect_identity() noexcept = 0;
  [[nodiscard]] virtual validation_probe validate_candidate() noexcept = 0;
};

struct probe_result final {
  std::uint32_t schema_version{result_schema_version};
  bool ready{};
  bool process_ready{};
  bool window_ready{};
  bool hash_ready{};
  bool baseline_ready{};
  bool patterns_unique{};
  bool fish_identity_ready{};
  bool snapshot_ready{};
  std::string candidate_sha256;
  std::string baseline_profile_id;
  std::uint32_t baseline_profile_revision{};
  readiness_reason reason{readiness_reason::internal_error};
};

[[nodiscard]] probe_result run(compatibility_port& port) noexcept;
[[nodiscard]] std::string_view reason_key(readiness_reason reason) noexcept;
[[nodiscard]] std::string serialize_json(const probe_result& result);

}  // namespace sonar::fishing::build_profile_compatibility_probe
