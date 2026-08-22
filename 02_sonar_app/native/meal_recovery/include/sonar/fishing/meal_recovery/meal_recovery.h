#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <utility>

namespace sonar::fishing::meal_recovery {

inline constexpr double kFoodDecaySeconds = 5.0 * 60.0;
inline constexpr double kWaterDecaySeconds = 3.0 * 60.0;
inline constexpr int kStatusDecayStep = 2;
inline constexpr double kStatusMaximumAgeSeconds = 15.0;
inline constexpr int kStatusThresholdTolerance = 2;
inline constexpr double kMissingStatusRetrySeconds = 45.0;
inline constexpr unsigned int kBackpackMoveMaximumAttempts = 5;

struct PlayerStatus {
  std::optional<int> food;
  std::optional<int> water;
  std::optional<int> health;
  std::optional<double> inventory_weight;
  std::optional<double> inventory_weight_max;
  std::optional<double> backpack_weight;
  std::optional<double> backpack_weight_max;
  std::string source;
};

[[nodiscard]] bool HasNeeds(
    const PlayerStatus& status,
    int food_threshold = 100,
    int water_threshold = 100,
    std::optional<int> health_threshold = std::nullopt) noexcept;
[[nodiscard]] PlayerStatus MergeMissing(
    const PlayerStatus& primary,
    const PlayerStatus& fallback);
[[nodiscard]] bool HasCoreValues(const PlayerStatus& status) noexcept;
[[nodiscard]] bool HasAnyValue(const PlayerStatus& status) noexcept;

// Engine-owned estimator fed by already validated observations. The caller
// supplies monotonic replay/runtime time so the policy owns no wall clock.
class PlayerStatusEstimate final {
 public:
  void Update(
      std::optional<PlayerStatus> status,
      double now_seconds,
      bool trusted_core = false,
      bool inventory_scan = false) noexcept;
  void AddInventoryFishWeight(std::optional<double> weight_kg) noexcept;

  [[nodiscard]] std::optional<PlayerStatus> Estimate(
      double now_seconds) const noexcept;
  [[nodiscard]] std::optional<std::pair<double, double>>
  SecondsUntilBelowBreakdown(
      int food_threshold,
      int water_threshold,
      double now_seconds) const noexcept;
  [[nodiscard]] std::optional<double> SecondsUntilBelow(
      int food_threshold,
      int water_threshold,
      double now_seconds) const noexcept;

 private:
  [[nodiscard]] static std::optional<int> DecayedPercent(
      std::optional<int> value,
      double elapsed_seconds,
      double period_seconds) noexcept;
  [[nodiscard]] static std::optional<double> SecondsUntilValueBelow(
      std::optional<int> value,
      double scanned_at_seconds,
      double period_seconds,
      int threshold,
      double now_seconds) noexcept;

  std::optional<PlayerStatus> status_;
  double scanned_at_seconds_ = 0.0;
  double inventory_fish_weight_ = 0.0;
};

struct MealNeedInput {
  bool auto_meal = true;
  bool reeling_stage = false;
  bool hunger_trigger = false;
  bool thirst_trigger = false;
  bool search_disabled_until_restart = false;
  std::optional<PlayerStatus> latest_status;
  double latest_status_at_seconds = 0.0;
  double inventory_retry_after_seconds = 0.0;
  int restore_food_from = 90;
  int restore_water_from = 90;
};

struct MealNeedDecision {
  bool trigger_needs_meal = false;
  bool status_needs_meal = false;
  bool timer_needs_meal = false;
  bool needs_meal = false;
  bool handle_now = false;
};

// Pure projection used only inside the future whole Engine meal episode. It is
// not a Host RPC and authorizes no capture, memory read or physical input.
[[nodiscard]] MealNeedDecision EvaluateMealNeed(
    const MealNeedInput& input,
    double now_seconds) noexcept;
[[nodiscard]] int ScanThreshold(int configured_threshold) noexcept;

enum class MealSearchStep {
  skip_disabled,
  finish_satisfied,
  confirm_hud_need,
  consume_inventory_item,
  move_backpack_item,
  confirm_depleted,
};

struct MealSearchObservation {
  bool auto_meal = true;
  std::optional<PlayerStatus> status;
  bool hud_indicates_need = false;
  bool inventory_item_available = false;
  bool backpack_item_available = false;
  unsigned int backpack_move_attempts = 0;
  int restore_food_from = 90;
  int restore_water_from = 90;
};

[[nodiscard]] MealSearchStep SelectMealSearchStep(
    const MealSearchObservation& observation) noexcept;
[[nodiscard]] std::string_view MealSearchStepKey(MealSearchStep step) noexcept;

}  // namespace sonar::fishing::meal_recovery
