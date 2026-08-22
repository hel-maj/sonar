#include "sonar/fishing/inventory_store/inventory_store_episode.h"

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <stop_token>

namespace inventory = sonar::fishing::inventory_store;

namespace {

class benchmark_observer final : public inventory::inventory_observer {
 public:
  [[nodiscard]] inventory::inventory_observation observe(
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested() || cursor_ >= 3) {
      return {.error = "benchmark_fixture_exhausted"};
    }
    ++cursor_;
    return {
        .sequence = cursor_,
        .surface = cursor_ == 1 ? inventory::inventory_surface::inventory
                                : inventory::inventory_surface::gameplay,
    };
  }

 private:
  std::uint64_t cursor_{};
};

class benchmark_mutation_port final : public inventory::inventory_mutation_port {
 public:
  [[nodiscard]] inventory::inventory_mutation_result apply(
      const inventory::inventory_mutation_intent& intent,
      const std::stop_token stop_token) override {
    checksum += intent.expected_observation_sequence + intent.packet_count +
        intent.delay_milliseconds;
    if (stop_token.stop_requested()) {
      return inventory::inventory_mutation_result::rejected(
          "benchmark_cancelled");
    }
    return inventory::inventory_mutation_result::accepted();
  }

  std::uint64_t checksum{};
};

}  // namespace

int main() {
  constexpr std::size_t kEpisodes = 100'000;
  const inventory::inventory_store_request request{
      .fish_to_store = {"rainbow_trout"},
      .resume_fishing = false,
  };
  const inventory::inventory_store_episode_runner runner;
  std::uint64_t checksum{};

  const auto started_at = std::chrono::steady_clock::now();
  for (std::size_t index = 0; index < kEpisodes; ++index) {
    benchmark_observer observer;
    benchmark_mutation_port mutation;
    const auto result = runner.run(request, observer, mutation);
    if (!result.ok) {
      std::cerr << "inventory store benchmark failed: " << result.reason << '\n';
      return 1;
    }
    checksum += mutation.checksum + result.observation.sequence +
        result.stored_count + index % 7;
  }
  const auto elapsed = std::chrono::steady_clock::now() - started_at;
  const double elapsed_milliseconds =
      std::chrono::duration<double, std::milli>(elapsed).count();
  const double nanoseconds_per_episode =
      std::chrono::duration<double, std::nano>(elapsed).count() /
      static_cast<double>(kEpisodes);

  std::cout << std::fixed << std::setprecision(3)
            << "METRIC inventory_store episodes=" << kEpisodes
            << " elapsed_ms=" << elapsed_milliseconds
            << " ns_per_episode=" << nanoseconds_per_episode
            << " checksum=" << checksum << '\n';
  return 0;
}
