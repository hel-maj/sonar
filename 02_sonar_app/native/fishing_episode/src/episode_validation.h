#pragma once

#include <cstdint>
#include <optional>
#include <string>

#include "sonar/fishing/fishing_episode/fishing_episode.h"

namespace sonar::fishing::fishing_episode::detail {

[[nodiscard]] std::uint64_t elapsed_ns(
    std::uint64_t now,
    std::uint64_t started) noexcept;

[[nodiscard]] stage_detection::observed_fishing_stage observed_stage(
    const fishing_episode_observation& observation) noexcept;

[[nodiscard]] bool memory_reports_finished(
    const fishing_episode_observation& observation) noexcept;

[[nodiscard]] bool valid_request(
    const fishing_episode_request& request,
    std::string& reason) noexcept;

class observation_validator final {
 public:
  [[nodiscard]] bool validate(
      const fishing_episode_observation& observation,
      std::string& reason);

  [[nodiscard]] std::uint64_t last_sequence() const noexcept;

 private:
  std::uint64_t last_sequence_{};
  std::uint64_t last_captured_at_{};
  std::optional<std::string> memory_profile_id_;
  std::uint32_t memory_profile_revision_{};
  sonar::platform::windows::process_generation memory_game_generation_;
  std::optional<sonar::platform::windows::process_generation>
      memory_webengine_generation_;
};

}  // namespace sonar::fishing::fishing_episode::detail
