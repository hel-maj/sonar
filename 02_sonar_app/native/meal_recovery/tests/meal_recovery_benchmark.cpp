#include "sonar/fishing/meal_recovery/meal_recovery.h"

#include <chrono>
#include <cstdint>
#include <iomanip>
#include <iostream>

int main() {
  namespace meal = sonar::fishing::meal_recovery;
  constexpr std::uint64_t kSamples = 1'000'000;

  meal::PlayerStatusEstimate estimate;
  meal::PlayerStatus status{
      .food = 100,
      .water = 100,
      .health = 100,
      .inventory_weight = 10.0,
      .inventory_weight_max = 40.0,
      .source = "screenshot",
  };
  estimate.Update(status, 1'000.0, true, true);

  double checksum = 0.0;
  const auto started_at = std::chrono::steady_clock::now();
  for (std::uint64_t sample = 0; sample < kSamples; ++sample) {
    const double now = 1'000.0 + static_cast<double>(sample % 10'000) * 0.01;
    if (sample % 97 == 0) {
      estimate.AddInventoryFishWeight(0.05);
    }
    const auto projected = estimate.Estimate(now);
    const auto waits = estimate.SecondsUntilBelowBreakdown(50, 80, now);
    meal::MealNeedInput input;
    input.latest_status = projected;
    input.latest_status_at_seconds = now;
    input.inventory_retry_after_seconds = now + 1.0;
    input.restore_food_from = 50;
    input.restore_water_from = 80;
    const auto decision = meal::EvaluateMealNeed(input, now);
    checksum += projected->inventory_weight.value_or(0.0);
    checksum += waits->first + waits->second;
    checksum += decision.needs_meal ? 1.0 : 0.0;
  }
  const auto elapsed = std::chrono::steady_clock::now() - started_at;
  const double elapsed_ms =
      std::chrono::duration<double, std::milli>(elapsed).count();
  const double nanoseconds_per_sample = elapsed_ms * 1'000'000.0 /
                                        static_cast<double>(kSamples);

  std::cout << std::fixed << std::setprecision(3)
            << "METRIC meal_recovery samples=" << kSamples
            << " elapsed_ms=" << elapsed_ms
            << " ns_per_sample=" << nanoseconds_per_sample
            << " checksum=" << checksum << '\n';
  return 0;
}
