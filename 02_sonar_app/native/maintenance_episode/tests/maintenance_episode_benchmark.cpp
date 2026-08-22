#include "sonar/fishing/maintenance_episode/maintenance_episode.h"

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <stop_token>

namespace maintenance = sonar::fishing::maintenance_episode;
namespace inventory = sonar::fishing::inventory_store;

namespace {

class benchmark_observer final : public maintenance::maintenance_observer {
 public:
  benchmark_observer() {
    current_.inventory = {
        .sequence = 1,
        .surface = inventory::inventory_surface::gameplay,
    };
    current_.tackle = maintenance::tackle_scan_observation{
        .available = true,
        .readable = true,
        .counts = {.rod = 1, .reel = 1, .line = 1, .hook = 1, .bait = 1, .net = 1},
    };
  }

  [[nodiscard]] inventory::inventory_observation observe(
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested()) {
      return {.error = "benchmark_cancelled"};
    }
    return current_.inventory;
  }

  [[nodiscard]] const maintenance::maintenance_observation&
  current_maintenance() const noexcept override {
    return current_;
  }

 private:
  maintenance::maintenance_observation current_;
};

class benchmark_mutation_port final : public inventory::inventory_mutation_port {
 public:
  [[nodiscard]] inventory::inventory_mutation_result apply(
      const inventory::inventory_mutation_intent& intent,
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested() ||
        intent.expected_observation_sequence != 1) {
      return inventory::inventory_mutation_result::rejected(
          "benchmark_gate_rejected");
    }
    checksum += intent.expected_observation_sequence + intent.packet_count +
        static_cast<std::uint64_t>(intent.kind);
    return inventory::inventory_mutation_result::accepted();
  }

  std::uint64_t checksum{};
};

}  // namespace

int main() {
  constexpr std::size_t kEpisodes = 100'000;
  auto settings = sonar::fishing::runtime_settings::RuntimeSettingsSnapshot{};
  settings.revision = 1;
  const maintenance::maintenance_request request{
      .kind = maintenance::episode_kind::tackle_check,
      .settings = settings,
  };
  const maintenance::maintenance_episode_runner runner;
  std::uint64_t checksum{};

  const auto started_at = std::chrono::steady_clock::now();
  for (std::size_t index = 0; index < kEpisodes; ++index) {
    benchmark_observer observer;
    benchmark_mutation_port mutation;
    const auto result = runner.run(request, observer, mutation);
    if (!result.ok) {
      std::cerr << "maintenance episode benchmark failed: "
                << result.reason << '\n';
      return 1;
    }
    checksum += mutation.checksum + result.observation.sequence + index % 7;
  }
  const auto elapsed = std::chrono::steady_clock::now() - started_at;
  const double elapsed_milliseconds =
      std::chrono::duration<double, std::milli>(elapsed).count();
  const double nanoseconds_per_episode =
      std::chrono::duration<double, std::nano>(elapsed).count() /
      static_cast<double>(kEpisodes);

  std::cout << std::fixed << std::setprecision(3)
            << "METRIC maintenance_episode episodes=" << kEpisodes
            << " elapsed_ms=" << elapsed_milliseconds
            << " ns_per_episode=" << nanoseconds_per_episode
            << " checksum=" << checksum << '\n';
  return checksum == 1'699'995 ? 0 : 1;
}
