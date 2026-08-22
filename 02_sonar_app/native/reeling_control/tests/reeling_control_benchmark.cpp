#include "sonar/fishing/reeling_control/reeling_control.h"

#include <array>
#include <chrono>
#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
  namespace control = sonar::fishing::reeling_control;
  constexpr std::size_t kOperations = 1'000'000;
  constexpr std::array<double, 8> kVelocities{
      1.2, 1.2, -1.2, -1.2, 0.1, 0.0, 0.8, -0.8};

  control::ProjectedVelocityPolicy policy;
  control::MoveStabilizer stabilizer;
  control::FishVelocityTracker velocity_tracker;
  static_cast<void>(policy.Evaluate(0.0, 100, false, true));
  double now_seconds = 1.0;
  double fish_x = 0.0;
  double checksum = 0.0;

  const auto started_at = std::chrono::steady_clock::now();
  for (std::size_t index = 0; index < kOperations; ++index) {
    fish_x += kVelocities[index % kVelocities.size()] * 0.005;
    const bool motion_updated = velocity_tracker.Update(
        now_seconds, {fish_x, 0.0, 0.0}, false);
    const auto decision = policy.Evaluate(
        velocity_tracker.CurrentVelocity().x,
        100,
        false,
        motion_updated);
    const auto stable = stabilizer.Stabilize(
        decision.move, decision.action_epsilon, now_seconds);
    checksum += stable.move + policy.CurrentThreshold();
    now_seconds += 0.005;
  }
  const auto elapsed = std::chrono::steady_clock::now() - started_at;
  const double elapsed_milliseconds =
      std::chrono::duration<double, std::milli>(elapsed).count();
  const double nanoseconds_per_operation =
      std::chrono::duration<double, std::nano>(elapsed).count() /
      static_cast<double>(kOperations);

  std::cout << std::fixed << std::setprecision(3)
            << "METRIC reeling_control operations=" << kOperations
            << " elapsed_ms=" << elapsed_milliseconds
            << " ns_per_operation=" << nanoseconds_per_operation
            << " checksum=" << checksum << '\n';
  return 0;
}
