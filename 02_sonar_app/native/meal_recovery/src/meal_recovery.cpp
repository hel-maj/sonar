#include "sonar/fishing/meal_recovery/meal_recovery.h"

#include <algorithm>
#include <cmath>
#include <string_view>

namespace sonar::fishing::meal_recovery {
namespace {

template <typename T>
[[nodiscard]] std::optional<T> Prefer(
    const std::optional<T>& primary,
    const std::optional<T>& fallback) {
  return primary.has_value() ? primary : fallback;
}

[[nodiscard]] std::string MergeSources(
    const std::string& primary,
    const std::string& fallback) {
  if (primary.empty()) {
    return fallback;
  }
  if (fallback.empty() || fallback == primary) {
    return primary;
  }
  return primary + "+" + fallback;
}

}  // namespace

bool HasNeeds(
    const PlayerStatus& status,
    const int food_threshold,
    const int water_threshold,
    const std::optional<int> health_threshold) noexcept {
  if (status.food.has_value() && *status.food < food_threshold) {
    return true;
  }
  if (status.water.has_value() && *status.water < water_threshold) {
    return true;
  }
  return health_threshold.has_value() && status.health.has_value() &&
         *status.health < *health_threshold;
}

PlayerStatus MergeMissing(
    const PlayerStatus& primary,
    const PlayerStatus& fallback) {
  return PlayerStatus{
      .food = Prefer(primary.food, fallback.food),
      .water = Prefer(primary.water, fallback.water),
      .health = Prefer(primary.health, fallback.health),
      .inventory_weight =
          Prefer(primary.inventory_weight, fallback.inventory_weight),
      .inventory_weight_max =
          Prefer(primary.inventory_weight_max, fallback.inventory_weight_max),
      .backpack_weight =
          Prefer(primary.backpack_weight, fallback.backpack_weight),
      .backpack_weight_max =
          Prefer(primary.backpack_weight_max, fallback.backpack_weight_max),
      .source = MergeSources(primary.source, fallback.source),
  };
}

bool HasCoreValues(const PlayerStatus& status) noexcept {
  return status.food.has_value() && status.water.has_value() &&
         status.health.has_value();
}

bool HasAnyValue(const PlayerStatus& status) noexcept {
  return status.food.has_value() || status.water.has_value() ||
         status.health.has_value() || status.inventory_weight.has_value() ||
         status.inventory_weight_max.has_value() ||
         status.backpack_weight.has_value() ||
         status.backpack_weight_max.has_value();
}

void PlayerStatusEstimate::Update(
    std::optional<PlayerStatus> status,
    const double now_seconds,
    const bool trusted_core,
    const bool inventory_scan) noexcept {
  if (!status.has_value() || !HasAnyValue(*status) ||
      !std::isfinite(now_seconds)) {
    return;
  }

  const std::optional<PlayerStatus> previous = Estimate(now_seconds);
  const auto previous_value = [&previous](auto PlayerStatus::*member) {
    using Optional = decltype((*previous).*member);
    return previous.has_value() ? (*previous).*member : Optional{};
  };

  const std::optional<int> food =
      trusted_core && status->food.has_value()
          ? status->food
          : previous_value(&PlayerStatus::food);
  const std::optional<int> water =
      trusted_core && status->water.has_value()
          ? status->water
          : previous_value(&PlayerStatus::water);
  const std::optional<int> health =
      trusted_core && status->health.has_value()
          ? status->health
          : previous_value(&PlayerStatus::health);
  const std::optional<double> inventory_weight = Prefer(
      status->inventory_weight,
      previous_value(&PlayerStatus::inventory_weight));
  const std::optional<double> inventory_weight_max = Prefer(
      status->inventory_weight_max,
      previous_value(&PlayerStatus::inventory_weight_max));
  const std::optional<double> backpack_weight = Prefer(
      status->backpack_weight,
      previous_value(&PlayerStatus::backpack_weight));
  const std::optional<double> backpack_weight_max = Prefer(
      status->backpack_weight_max,
      previous_value(&PlayerStatus::backpack_weight_max));

  if (inventory_scan && status->inventory_weight.has_value()) {
    inventory_fish_weight_ = 0.0;
  }
  status_ = PlayerStatus{
      .food = food,
      .water = water,
      .health = health,
      .inventory_weight = inventory_weight,
      .inventory_weight_max = inventory_weight_max,
      .backpack_weight = backpack_weight,
      .backpack_weight_max = backpack_weight_max,
      .source = "scan",
  };
  if (trusted_core) {
    scanned_at_seconds_ = now_seconds;
  } else if (scanned_at_seconds_ <= 0.0) {
    scanned_at_seconds_ = now_seconds;
  }
}

void PlayerStatusEstimate::AddInventoryFishWeight(
    const std::optional<double> weight_kg) noexcept {
  if (!weight_kg.has_value() || *weight_kg <= 0.0) {
    return;
  }
  inventory_fish_weight_ += *weight_kg;
}

std::optional<PlayerStatus> PlayerStatusEstimate::Estimate(
    const double now_seconds) const noexcept {
  if (!status_.has_value() || !std::isfinite(now_seconds)) {
    return std::nullopt;
  }
  const double elapsed_seconds =
      std::max(0.0, now_seconds - scanned_at_seconds_);
  std::optional<double> inventory_weight = status_->inventory_weight;
  if (inventory_weight.has_value()) {
    *inventory_weight += inventory_fish_weight_;
    if (status_->inventory_weight_max.has_value()) {
      *inventory_weight =
          std::min(*inventory_weight, *status_->inventory_weight_max);
    }
  }
  return PlayerStatus{
      .food = DecayedPercent(
          status_->food, elapsed_seconds, kFoodDecaySeconds),
      .water = DecayedPercent(
          status_->water, elapsed_seconds, kWaterDecaySeconds),
      .health = status_->health,
      .inventory_weight = inventory_weight,
      .inventory_weight_max = status_->inventory_weight_max,
      .backpack_weight = status_->backpack_weight,
      .backpack_weight_max = status_->backpack_weight_max,
      .source = "estimate",
  };
}

std::optional<std::pair<double, double>>
PlayerStatusEstimate::SecondsUntilBelowBreakdown(
    const int food_threshold,
    const int water_threshold,
    const double now_seconds) const noexcept {
  if (!status_.has_value() || !std::isfinite(now_seconds)) {
    return std::nullopt;
  }
  const std::optional<double> food_wait = SecondsUntilValueBelow(
      status_->food,
      scanned_at_seconds_,
      kFoodDecaySeconds,
      food_threshold,
      now_seconds);
  const std::optional<double> water_wait = SecondsUntilValueBelow(
      status_->water,
      scanned_at_seconds_,
      kWaterDecaySeconds,
      water_threshold,
      now_seconds);
  if (!food_wait.has_value() || !water_wait.has_value()) {
    return std::nullopt;
  }
  return std::pair{
      std::max(0.0, *food_wait), std::max(0.0, *water_wait)};
}

std::optional<double> PlayerStatusEstimate::SecondsUntilBelow(
    const int food_threshold,
    const int water_threshold,
    const double now_seconds) const noexcept {
  const auto breakdown = SecondsUntilBelowBreakdown(
      food_threshold, water_threshold, now_seconds);
  if (!breakdown.has_value()) {
    return std::nullopt;
  }
  return std::min(breakdown->first, breakdown->second);
}

std::optional<int> PlayerStatusEstimate::DecayedPercent(
    const std::optional<int> value,
    const double elapsed_seconds,
    const double period_seconds) noexcept {
  if (!value.has_value()) {
    return std::nullopt;
  }
  const double drops = std::floor(elapsed_seconds / period_seconds);
  const double decayed =
      static_cast<double>(*value) - drops * kStatusDecayStep;
  return static_cast<int>(std::clamp(decayed, 0.0, 100.0));
}

std::optional<double> PlayerStatusEstimate::SecondsUntilValueBelow(
    const std::optional<int> value,
    const double scanned_at_seconds,
    const double period_seconds,
    const int threshold,
    const double now_seconds) noexcept {
  if (!value.has_value()) {
    return std::nullopt;
  }
  const double elapsed_seconds =
      std::max(0.0, now_seconds - scanned_at_seconds);
  const auto drops_done = static_cast<long long>(
      std::floor(elapsed_seconds / period_seconds));
  const auto current = std::max<long long>(
      0, static_cast<long long>(*value) - drops_done * kStatusDecayStep);
  if (current < threshold) {
    return 0.0;
  }
  const auto drops_needed =
      ((current - static_cast<long long>(threshold)) / kStatusDecayStep) + 1;
  const double next_drop_in =
      period_seconds - std::fmod(elapsed_seconds, period_seconds);
  return next_drop_in +
         static_cast<double>(std::max<long long>(0, drops_needed - 1)) *
             period_seconds;
}

MealNeedDecision EvaluateMealNeed(
    const MealNeedInput& input,
    const double now_seconds) noexcept {
  MealNeedDecision result;
  result.trigger_needs_meal = input.hunger_trigger || input.thirst_trigger;
  if (input.auto_meal && !input.reeling_stage && input.latest_status.has_value() &&
      now_seconds - input.latest_status_at_seconds <= kStatusMaximumAgeSeconds) {
    result.status_needs_meal = HasNeeds(
        *input.latest_status,
        input.restore_food_from,
        input.restore_water_from,
        std::nullopt);
  }
  result.timer_needs_meal =
      input.auto_meal && input.inventory_retry_after_seconds > 0.0 &&
      now_seconds >= input.inventory_retry_after_seconds;
  result.needs_meal =
      input.auto_meal &&
      (result.trigger_needs_meal || result.status_needs_meal ||
       result.timer_needs_meal) &&
      !input.search_disabled_until_restart;
  result.handle_now =
      result.needs_meal && !input.reeling_stage &&
      now_seconds >= input.inventory_retry_after_seconds;
  return result;
}

int ScanThreshold(const int configured_threshold) noexcept {
  return std::min(100, configured_threshold + kStatusThresholdTolerance);
}

MealSearchStep SelectMealSearchStep(
    const MealSearchObservation& observation) noexcept {
  if (!observation.auto_meal) {
    return MealSearchStep::skip_disabled;
  }
  if (observation.status.has_value() &&
      !HasNeeds(
          *observation.status,
          ScanThreshold(observation.restore_food_from),
          ScanThreshold(observation.restore_water_from),
          std::nullopt)) {
    return MealSearchStep::finish_satisfied;
  }
  if (!observation.status.has_value() && !observation.hud_indicates_need) {
    return MealSearchStep::confirm_hud_need;
  }
  if (observation.inventory_item_available) {
    return MealSearchStep::consume_inventory_item;
  }
  if (observation.backpack_item_available &&
      observation.backpack_move_attempts < kBackpackMoveMaximumAttempts) {
    return MealSearchStep::move_backpack_item;
  }
  return MealSearchStep::confirm_depleted;
}

std::string_view MealSearchStepKey(const MealSearchStep step) noexcept {
  switch (step) {
    case MealSearchStep::skip_disabled:
      return "skip_disabled";
    case MealSearchStep::finish_satisfied:
      return "finish_satisfied";
    case MealSearchStep::confirm_hud_need:
      return "confirm_hud_need";
    case MealSearchStep::consume_inventory_item:
      return "consume_inventory_item";
    case MealSearchStep::move_backpack_item:
      return "move_backpack_item";
    case MealSearchStep::confirm_depleted:
      return "confirm_depleted";
  }
  return "unknown";
}

}  // namespace sonar::fishing::meal_recovery
