#include "sonar/fishing/fishing_episode/fishing_episode.h"

#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <memory>
#include <stop_token>
#include <string>

namespace episode = sonar::fishing::fishing_episode;
namespace memory = sonar::fishing::memory_observation;
namespace stage = sonar::fishing::stage_detection;

namespace {

[[nodiscard]] episode::fishing_episode_observation observation(
    const std::uint64_t sequence,
    const stage::observed_fishing_stage stage_value,
    const bool cue,
    const bool active,
    const double fish_x) {
  const std::uint64_t captured_at = 1'000'000'000U +
      sequence * 20'000'000U;
  std::string trigger = stage_value == stage::observed_fishing_stage::casting
      ? "start1"
      : stage_value == stage::observed_fishing_stage::waiting_for_bite
      ? "start2"
      : "ad";
  episode::fishing_episode_observation value{
      .sequence = sequence,
      .captured_at_steady_ns = captured_at,
      .stage = stage::stage_observation{
          .stage = stage_value,
          .trigger_id = std::move(trigger),
          .confidence = 0.99,
          .bounds = {.x = 0.1, .y = 0.1, .width = 0.2, .height = 0.2},
      },
      .cast_ready = cue &&
          stage_value == stage::observed_fishing_stage::casting,
      .cast_confidence = cue &&
              stage_value == stage::observed_fishing_stage::casting
          ? 0.95
          : 0.0,
      .hook = cue &&
              stage_value == stage::observed_fishing_stage::waiting_for_bite
          ? episode::hook_cue::red
          : episode::hook_cue::none,
      .hook_confidence = cue &&
              stage_value == stage::observed_fishing_stage::waiting_for_bite
          ? 0.95
          : 0.0,
  };
  if (stage_value == stage::observed_fishing_stage::reeling) {
    value.memory = memory::coherent_memory_snapshot{
        .sequence = sequence,
        .captured_at_steady_ns = captured_at,
        .profile_id = "benchmark-e11",
        .profile_revision = 1U,
        .game_generation = {
            .process_id = 77U,
            .creation_time_filetime_100ns = 88U,
        },
        .reeling = memory::reeling_evidence{
            .active = active,
            .fish_model_confirmed = true,
            .player_position = {},
            .fish_position = {.x = fish_x, .y = 10.0, .z = 0.0},
            .player_right_x = 1.0,
            .player_right_y = 0.0,
            .distance = 10.0,
        },
    };
  }
  return value;
}

class benchmark_observer final : public episode::fishing_episode_observer {
 public:
  benchmark_observer()
      : values_{
            observation(1U, stage::observed_fishing_stage::casting, true, false, 0.0),
            observation(2U, stage::observed_fishing_stage::waiting_for_bite, true, false, 0.0),
            observation(3U, stage::observed_fishing_stage::reeling, false, true, 0.0),
            observation(4U, stage::observed_fishing_stage::reeling, false, true, 1.0),
            observation(5U, stage::observed_fishing_stage::reeling, false, true, 2.0),
            observation(6U, stage::observed_fishing_stage::reeling, false, false, 2.0),
        } {}

  [[nodiscard]] episode::fishing_episode_observation observe(
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested() || cursor_ >= values_.size()) {
      return {.error = "benchmark_exhausted"};
    }
    latest_sequence = values_[cursor_].sequence;
    return values_[cursor_++];
  }

  std::uint64_t latest_sequence{};

 private:
  std::array<episode::fishing_episode_observation, 6U> values_;
  std::size_t cursor_{};
};

class benchmark_session final : public episode::fishing_mutation_session {
 public:
  benchmark_session(benchmark_observer& observer, std::uint64_t& checksum)
      : observer_(observer), checksum_(checksum) {}

  [[nodiscard]] episode::fishing_mutation_result apply(
      const episode::fishing_mutation_intent& intent,
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested() ||
        intent.expected_observation_sequence != observer_.latest_sequence) {
      return episode::fishing_mutation_result::rejected(
          "benchmark_gate_rejected");
    }
    checksum_ += intent.packet_count +
        static_cast<std::uint64_t>(intent.kind);
    return episode::fishing_mutation_result::accepted();
  }

  [[nodiscard]] episode::fishing_mutation_result cleanup_reeling_keys(
      const std::uint64_t expected_observation_sequence) noexcept override {
    checksum_ += expected_observation_sequence;
    return episode::fishing_mutation_result::accepted();
  }

 private:
  benchmark_observer& observer_;
  std::uint64_t& checksum_;
};

class benchmark_port final : public episode::fishing_mutation_port {
 public:
  benchmark_port(benchmark_observer& observer, std::uint64_t& checksum)
      : observer_(observer), checksum_(checksum) {}

  [[nodiscard]] std::unique_ptr<episode::fishing_mutation_session> acquire(
      const episode::fishing_episode_request& request,
      const std::stop_token stop_token,
      std::string& reason) override {
    static_cast<void>(request);
    static_cast<void>(reason);
    if (stop_token.stop_requested()) {
      return nullptr;
    }
    return std::make_unique<benchmark_session>(observer_, checksum_);
  }

 private:
  benchmark_observer& observer_;
  std::uint64_t& checksum_;
};

}  // namespace

int main() {
  constexpr std::size_t iterations = 100'000U;
  const episode::fishing_episode_request request{
      .automation_enabled = true,
      .reeling_input_enabled = true,
      .accepted_settings_revision = 101U,
      .expected_entitlement_revision = 202U,
      .expected_lifecycle_revision = 303U,
      .episode_identity = 404U,
  };
  std::uint64_t checksum = 0U;
  const auto started = std::chrono::steady_clock::now();
  for (std::size_t index = 0U; index < iterations; ++index) {
    benchmark_observer observer;
    benchmark_port mutation(observer, checksum);
    const auto result = episode::fishing_episode_runner{}.run(
        request, observer, mutation);
    if (!result.ok) {
      std::cerr << result.reason << '\n';
      return 1;
    }
    checksum += result.observations_consumed + result.mutations_applied;
  }
  const auto elapsed = std::chrono::steady_clock::now() - started;
  const auto elapsed_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
  std::cout << "iterations=" << iterations
            << " elapsed_ns=" << elapsed_ns
            << " ns_per_episode="
            << static_cast<double>(elapsed_ns) /
                   static_cast<double>(iterations)
            << " checksum=" << checksum << '\n';
  return checksum == 2'900'000U ? 0 : 1;
}
