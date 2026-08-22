#include "sonar/fishing/meal_recovery/meal_recovery.h"

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <string_view>

namespace {

namespace meal = sonar::fishing::meal_recovery;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

void require_near(
    const double actual,
    const double expected,
    const std::string_view reason) {
  require(std::abs(actual - expected) < 0.0000001, reason);
}

meal::PlayerStatus complete_status(
    const int food = 100,
    const int water = 100,
    const int health = 100) {
  return meal::PlayerStatus{
      .food = food,
      .water = water,
      .health = health,
      .source = "screenshot",
  };
}

void status_value_contract_matches_legacy() {
  const meal::PlayerStatus primary{
      .food = 40,
      .inventory_weight = 12.5,
      .source = "memory",
  };
  const meal::PlayerStatus fallback{
      .food = 90,
      .water = 70,
      .health = 60,
      .inventory_weight = 10.0,
      .inventory_weight_max = 40.0,
      .source = "screenshot",
  };
  const auto merged = meal::MergeMissing(primary, fallback);
  require(merged.food == 40, "primary_food_not_preserved");
  require(merged.water == 70, "missing_water_not_merged");
  require(merged.inventory_weight == 12.5, "primary_weight_not_preserved");
  require(merged.inventory_weight_max == 40.0, "weight_max_not_merged");
  require(merged.source == "memory+screenshot", "source_order_changed");
  require(meal::HasAnyValue(merged), "merged_status_marked_empty");
  require(meal::HasCoreValues(merged), "merged_status_missing_core");
  require(meal::HasNeeds(merged, 41, 70), "strict_food_threshold_changed");
  require(!meal::HasNeeds(merged, 40, 70), "equal_threshold_became_need");
  require(
      meal::HasNeeds(merged, 1, 1, 61),
      "optional_health_threshold_not_preserved");

  meal::PlayerStatus no_values;
  require(!meal::HasAnyValue(no_values), "empty_status_marked_present");
  require(!meal::HasCoreValues(no_values), "empty_status_marked_complete");
}

void estimate_matches_decay_and_timer_boundaries() {
  meal::PlayerStatusEstimate estimate;
  estimate.Update(complete_status(), 1000.0, true);

  const auto immediate = estimate.Estimate(1000.0);
  require(immediate.has_value(), "trusted_scan_not_retained");
  require(immediate->food == 100, "immediate_food_changed");
  require(immediate->water == 100, "immediate_water_changed");
  require(immediate->source == "estimate", "estimate_source_changed");

  const auto before_food_drop = estimate.Estimate(1299.999);
  require(before_food_drop->food == 100, "food_decayed_before_boundary");
  require(before_food_drop->water == 98, "water_boundary_count_changed");
  const auto at_food_drop = estimate.Estimate(1300.0);
  require(at_food_drop->food == 98, "food_did_not_decay_at_boundary");
  const auto clamped = estimate.Estimate(100000.0);
  require(clamped->food == 0 && clamped->water == 0, "decay_did_not_clamp");

  const auto waits = estimate.SecondsUntilBelowBreakdown(50, 80, 1000.0);
  require(waits.has_value(), "complete_status_has_no_timer");
  require_near(waits->first, 7800.0, "food_wait_changed");
  require_near(waits->second, 1980.0, "water_wait_changed");
  require_near(
      *estimate.SecondsUntilBelow(50, 80, 1000.0),
      1980.0,
      "shorter_timer_not_selected");
  require_near(
      *estimate.SecondsUntilBelow(100, 100, 1000.0),
      180.0,
      "equal_threshold_next_drop_changed");
  require_near(
      *estimate.SecondsUntilBelow(101, 101, 1000.0),
      0.0,
      "already_below_threshold_not_immediate");
}

void update_trust_and_inventory_semantics_match_legacy() {
  meal::PlayerStatusEstimate estimate;
  meal::PlayerStatus untrusted_core = complete_status(80, 70, 60);
  untrusted_core.inventory_weight = 10.0;
  untrusted_core.inventory_weight_max = 12.0;
  estimate.Update(untrusted_core, 1000.0, false, true);
  auto current = estimate.Estimate(1000.0);
  require(current.has_value(), "weight_only_scan_not_retained");
  require(!current->food.has_value(), "untrusted_food_was_accepted");
  require(current->inventory_weight == 10.0, "inventory_weight_lost");

  estimate.Update(complete_status(90, 80, 70), 1100.0, true);
  estimate.AddInventoryFishWeight(std::nullopt);
  estimate.AddInventoryFishWeight(-1.0);
  estimate.AddInventoryFishWeight(1.5);
  estimate.AddInventoryFishWeight(2.0);
  current = estimate.Estimate(1100.0);
  require(current->inventory_weight == 12.0, "fish_weight_not_capped");

  meal::PlayerStatus weight_refresh;
  weight_refresh.inventory_weight = 9.0;
  weight_refresh.inventory_weight_max = 20.0;
  weight_refresh.source = "screenshot";
  estimate.Update(weight_refresh, 1400.0, false, true);
  current = estimate.Estimate(1400.0);
  require(current->inventory_weight == 9.0, "inventory_scan_did_not_reset_delta");
  require(current->food == 86, "untrusted_refresh_changed_decay_semantics");
  require(current->water == 76, "untrusted_refresh_changed_water_semantics");

  const auto before_invalid = *current;
  estimate.Update(
      complete_status(1, 1, 1),
      std::numeric_limits<double>::quiet_NaN(),
      true);
  current = estimate.Estimate(1400.0);
  require(current->food == before_invalid.food, "invalid_time_mutated_status");
  require(
      !estimate.Estimate(std::numeric_limits<double>::infinity()).has_value(),
      "invalid_estimate_time_was_accepted");
}

void partial_status_never_schedules_long_timer() {
  meal::PlayerStatusEstimate estimate;
  meal::PlayerStatus partial;
  partial.food = 100;
  partial.health = 100;
  partial.source = "screenshot";
  estimate.Update(partial, 1000.0, true);
  require(
      !estimate.SecondsUntilBelowBreakdown(50, 80, 1000.0).has_value(),
      "partial_status_scheduled_breakdown");
  require(
      !estimate.SecondsUntilBelow(50, 80, 1000.0).has_value(),
      "partial_status_scheduled_timer");
}

void meal_need_precedence_matches_brain_loop() {
  meal::MealNeedInput input;
  input.latest_status = complete_status(89, 100, 10);
  input.latest_status_at_seconds = 90.0;
  input.inventory_retry_after_seconds = 95.0;
  input.restore_food_from = 90;
  input.restore_water_from = 90;

  const auto ready = meal::EvaluateMealNeed(input, 100.0);
  require(ready.status_needs_meal, "fresh_low_food_not_detected");
  require(ready.timer_needs_meal, "due_timer_not_detected");
  require(ready.needs_meal && ready.handle_now, "ready_meal_not_selected");

  input.reeling_stage = true;
  const auto reeling = meal::EvaluateMealNeed(input, 100.0);
  require(!reeling.status_needs_meal, "status_interrupted_reeling");
  require(reeling.timer_needs_meal, "reeling_lost_due_timer_fact");
  require(reeling.needs_meal, "reeling_lost_deferred_meal");
  require(!reeling.handle_now, "meal_started_during_reeling");

  input.reeling_stage = false;
  input.latest_status_at_seconds = 84.999;
  input.inventory_retry_after_seconds = 200.0;
  const auto stale = meal::EvaluateMealNeed(input, 100.0);
  require(!stale.status_needs_meal, "stale_status_was_trusted");
  require(!stale.needs_meal, "stale_status_requested_meal");

  input.hunger_trigger = true;
  const auto trigger_wait = meal::EvaluateMealNeed(input, 100.0);
  require(trigger_wait.needs_meal, "hud_trigger_not_detected");
  require(!trigger_wait.handle_now, "retry_deadline_not_respected");

  input.search_disabled_until_restart = true;
  const auto disabled = meal::EvaluateMealNeed(input, 250.0);
  require(!disabled.needs_meal, "disabled_search_restarted");

  input.search_disabled_until_restart = false;
  input.auto_meal = false;
  const auto auto_off = meal::EvaluateMealNeed(input, 250.0);
  require(auto_off.trigger_needs_meal, "trigger_fact_was_hidden");
  require(!auto_off.needs_meal, "auto_meal_off_requested_meal");
}

void meal_search_step_preserves_inventory_precedence() {
  meal::MealSearchObservation observation;
  observation.status = complete_status(100, 100, 100);
  require(
      meal::SelectMealSearchStep(observation) ==
          meal::MealSearchStep::finish_satisfied,
      "satisfied_status_did_not_finish");

  observation.status = complete_status(91, 100, 100);
  observation.restore_food_from = 90;
  observation.inventory_item_available = true;
  observation.backpack_item_available = true;
  require(meal::ScanThreshold(90) == 92, "scan_tolerance_changed");
  require(
      meal::SelectMealSearchStep(observation) ==
          meal::MealSearchStep::consume_inventory_item,
      "inventory_item_lost_precedence");

  observation.inventory_item_available = false;
  require(
      meal::SelectMealSearchStep(observation) ==
          meal::MealSearchStep::move_backpack_item,
      "backpack_item_not_moved");
  observation.backpack_move_attempts = meal::kBackpackMoveMaximumAttempts;
  require(
      meal::SelectMealSearchStep(observation) ==
          meal::MealSearchStep::confirm_depleted,
      "backpack_attempt_limit_changed");

  observation.status.reset();
  observation.backpack_item_available = false;
  observation.hud_indicates_need = false;
  require(
      meal::SelectMealSearchStep(observation) ==
          meal::MealSearchStep::confirm_hud_need,
      "missing_status_skipped_hud_confirmation");
  observation.hud_indicates_need = true;
  require(
      meal::SelectMealSearchStep(observation) ==
          meal::MealSearchStep::confirm_depleted,
      "confirmed_hud_need_did_not_check_depletion");

  observation.auto_meal = false;
  require(
      meal::SelectMealSearchStep(observation) ==
          meal::MealSearchStep::skip_disabled,
      "disabled_auto_meal_entered_search");
  require(
      meal::MealSearchStepKey(meal::MealSearchStep::confirm_depleted) ==
          "confirm_depleted",
      "step_key_changed");
}

int run() {
  status_value_contract_matches_legacy();
  estimate_matches_decay_and_timer_boundaries();
  update_trust_and_inventory_semantics_match_legacy();
  partial_status_never_schedules_long_timer();
  meal_need_precedence_matches_brain_loop();
  meal_search_step_preserves_inventory_precedence();
  std::cout << "PASS Fishing meal/player-status recovery replay policy\n";
  return 0;
}

}  // namespace

int main() {
  try {
    return run();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
