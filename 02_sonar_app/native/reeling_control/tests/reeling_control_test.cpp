#include "sonar/fishing/reeling_control/reeling_control.h"

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <string_view>

namespace {

namespace control = sonar::fishing::reeling_control;

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

void projected_velocity_matches_legacy_direction_and_warmup() {
  control::ProjectedVelocityPolicy policy;
  const auto warmup = policy.Evaluate(99.0, 100, false, true);
  require(warmup.move == 0.0, "new_target_did_not_warm_up");
  require(
      warmup.source == control::MovementSource::motion_warmup,
      "new_target_warmup_reason_changed");
  require_near(
      policy.CurrentThreshold(),
      control::kLateralVelocityEpsilon,
      "warmup_threshold_changed");

  const auto right = policy.Evaluate(1.2, 100, false, true);
  require(right.move == -1.0, "right_motion_did_not_reel_left");
  require(
      right.source == control::MovementSource::reel_against_right_motion,
      "right_motion_reason_changed");

  const auto left = policy.Evaluate(-1.2, 100, false, true);
  require(left.move == 1.0, "left_motion_did_not_reel_right");
  require(
      left.source == control::MovementSource::reel_against_left_motion,
      "left_motion_reason_changed");

  const auto duplicate = policy.Evaluate(5.0, 100, false, false);
  require(duplicate.move == 0.0, "duplicate_position_moved");
  require(
      duplicate.source == control::MovementSource::wait_fish_motion,
      "duplicate_position_reason_changed");

  const auto stale = policy.Evaluate(5.0, 100, true, true);
  require(stale.move == 0.0, "stale_position_moved");
  require(
      stale.source == control::MovementSource::wait_fresh_position,
      "stale_position_reason_changed");

  const auto changed_target = policy.Evaluate(-5.0, 200, false, true);
  require(changed_target.move == 0.0, "changed_target_skipped_warmup");
}

void fish_velocity_matches_legacy_update_and_duplicate_semantics() {
  control::FishVelocityTracker tracker;
  require(
      !tracker.Update(10.0, {5.0, 6.0, 0.0}, false),
      "first_position_claimed_motion");
  require(
      tracker.Update(10.02, {5.04, 6.0, 0.0}, false),
      "changed_position_did_not_update_motion");
  const auto velocity = tracker.CurrentVelocity();
  require_near(velocity.x, 1.6, "legacy_velocity_weight_changed");
  require_near(velocity.y, 0.0, "stationary_axis_velocity_changed");

  require(
      !tracker.Update(10.025, {5.04, 6.0, 0.0}, false),
      "duplicate_position_claimed_motion");
  require_near(
      tracker.CurrentVelocity().x,
      velocity.x,
      "duplicate_position_changed_velocity");
  require(
      !tracker.Update(10.03, {100.0, 100.0, 0.0}, true),
      "stale_position_claimed_motion");
  require_near(
      tracker.CurrentVelocity().x,
      velocity.x,
      "stale_position_changed_velocity");

  require(
      !tracker.Update(
          std::numeric_limits<double>::quiet_NaN(),
          {5.06, 6.0, 0.0},
          false),
      "invalid_timestamp_claimed_motion");
  require_near(
      tracker.CurrentVelocity().x,
      velocity.x,
      "invalid_timestamp_poisoned_velocity");

  tracker.Reset();
  require_near(
      tracker.CurrentVelocity().x, 0.0, "reset_retained_horizontal_velocity");
  require_near(
      tracker.CurrentVelocity().y, 0.0, "reset_retained_vertical_velocity");
}

void adaptive_threshold_matches_legacy_bounds() {
  control::ProjectedVelocityPolicy slow_policy;
  static_cast<void>(slow_policy.Evaluate(0.0, 100, false, true));
  for (int sample = 0; sample < 40; ++sample) {
    static_cast<void>(slow_policy.Evaluate(0.30, 100, false, true));
  }
  const auto slow_motion = slow_policy.Evaluate(0.50, 100, false, true);
  require(
      slow_policy.CurrentThreshold() < control::kLateralVelocityEpsilon,
      "slow_threshold_did_not_adapt");
  require(slow_motion.move == -1.0, "slow_sustained_motion_filtered");

  control::ProjectedVelocityPolicy fast_policy;
  static_cast<void>(fast_policy.Evaluate(0.0, 100, false, true));
  for (int sample = 0; sample < 50; ++sample) {
    static_cast<void>(fast_policy.Evaluate(10.0, 100, false, true));
  }
  require_near(
      fast_policy.CurrentThreshold(),
      control::kProjectedVelocityMaximumEpsilon,
      "fast_threshold_maximum_changed");
  const auto medium_motion = fast_policy.Evaluate(0.60, 100, false, true);
  require(medium_motion.move == 0.0, "medium_motion_not_filtered");

  control::ProjectedVelocityPolicy quiet_policy;
  static_cast<void>(quiet_policy.Evaluate(0.0, 100, false, true));
  for (int sample = 0; sample < 100; ++sample) {
    static_cast<void>(quiet_policy.Evaluate(0.0, 100, false, true));
  }
  require_near(
      quiet_policy.CurrentThreshold(),
      control::kProjectedVelocityMinimumEpsilon,
      "quiet_threshold_minimum_changed");
}

void invalid_velocity_fails_closed_without_poisoning_threshold() {
  control::ProjectedVelocityPolicy policy;
  static_cast<void>(policy.Evaluate(0.0, 100, false, true));
  const double threshold = policy.CurrentThreshold();
  const auto invalid = policy.Evaluate(
      std::numeric_limits<double>::quiet_NaN(), 100, false, true);
  require(invalid.move == 0.0, "invalid_velocity_moved");
  require(
      invalid.source == control::MovementSource::invalid_sample,
      "invalid_velocity_reason_changed");
  require_near(
      policy.CurrentThreshold(), threshold, "invalid_velocity_mutated_threshold");
}

void fish_side_orientation_matches_legacy_deadband() {
  const control::Vector2 right{1.0, 0.0};
  const control::Position3 player{0.0, 0.0, 0.0};

  const auto behind = control::OrientProjectedVelocityToFishSide(
      1.2, right, player, {0.0, -10.0, 0.0});
  require(behind.fish_behind_player, "behind_fish_not_detected");
  require(behind.velocity_along == -1.2, "behind_velocity_not_flipped");

  const auto side_on = control::OrientProjectedVelocityToFishSide(
      1.2, right, player, {10.0, 0.0, 0.0});
  require(!side_on.fish_behind_player, "side_on_fish_marked_behind");
  require(side_on.fish_forward == 0.0, "side_on_forward_distance_changed");
  require(side_on.velocity_along == 1.2, "side_on_velocity_flipped");

  const auto deadband = control::OrientProjectedVelocityToFishSide(
      1.2, right, player, {10.0, -0.5, 0.0});
  require(!deadband.fish_behind_player, "behind_deadband_removed");
  require(deadband.velocity_along == 1.2, "deadband_velocity_flipped");

  const auto exact_boundary = control::OrientProjectedVelocityToFishSide(
      1.2, right, player, {0.0, -1.0, 0.0});
  require(
      !exact_boundary.fish_behind_player,
      "behind_boundary_lost_strict_comparison");
}

void move_stabilizer_matches_legacy_confirmation() {
  control::MoveStabilizer stabilizer;
  const auto center = stabilizer.Stabilize(0.0, 0.5, 10.0);
  require(center.move == 0.0, "initial_center_moved");
  require(
      center.source == control::StabilizationSource::stable_center,
      "initial_center_reason_changed");

  const auto initial = stabilizer.Stabilize(1.0, 0.5, 10.1);
  require(initial.move == 1.0, "initial_direction_changed");
  require(
      initial.source == control::StabilizationSource::stable_initial,
      "initial_direction_reason_changed");

  const auto jitter = stabilizer.Stabilize(-1.0, 0.5, 10.11);
  require(jitter.move == 1.0, "single_opposite_jitter_switched");
  require(
      jitter.source == control::StabilizationSource::switch_pending,
      "jitter_reason_changed");

  const auto too_soon = stabilizer.Stabilize(-1.0, 0.5, 10.114);
  require(too_soon.move == 1.0, "time_gate_not_applied");
  require(
      too_soon.source == control::StabilizationSource::switch_pending,
      "time_gate_reason_changed");

  const auto confirmed = stabilizer.Stabilize(-1.0, 0.5, 10.126);
  require(confirmed.move == -1.0, "confirmed_direction_not_switched");
  require(
      confirmed.source == control::StabilizationSource::switch_confirmed,
      "confirmed_direction_reason_changed");

  const auto centered = stabilizer.Stabilize(0.5, 0.5, 10.13);
  require(centered.move == -1.0, "center_did_not_hold_stable_direction");
  require(
      centered.source == control::StabilizationSource::hold_stable_center,
      "center_hold_reason_changed");
}

void stale_hold_has_exact_legacy_grace() {
  control::MoveStabilizer stabilizer;
  static_cast<void>(stabilizer.Stabilize(1.0, 0.5, 10.0));
  const auto within_grace = stabilizer.HoldLastStableMove(
      10.0 + control::kStaleInputHoldSeconds - 0.001);
  require(within_grace.has_value(), "stale_hold_grace_rejected");
  require(*within_grace == 1.0, "stale_hold_direction_changed");
  require(
      !stabilizer
           .HoldLastStableMove(10.0 + control::kStaleInputHoldSeconds + 0.001)
           .has_value(),
      "expired_stale_hold_accepted");

  stabilizer.Reset();
  require(
      !stabilizer.HoldLastStableMove(10.0).has_value(),
      "reset_stabilizer_retained_hold");
}

void input_projection_is_pure_and_preserves_center_hold() {
  const auto right = control::ProjectInputIntent(1.0, 0.5, control::HeldKey::a);
  require(right.kind == control::InputIntentKind::hold_d, "right_intent_changed");
  require(right.desired_held_key == control::HeldKey::d, "right_key_changed");
  require(!right.preserve_current_key, "right_intent_preserved_opposite_key");

  const auto left = control::ProjectInputIntent(-1.0, 0.5, control::HeldKey::d);
  require(left.kind == control::InputIntentKind::hold_a, "left_intent_changed");
  require(left.desired_held_key == control::HeldKey::a, "left_key_changed");

  const auto wait = control::ProjectInputIntent(0.0, 0.5, control::HeldKey::d);
  require(
      wait.kind == control::InputIntentKind::hold_d_wait,
      "center_wait_action_changed");
  require(wait.preserve_current_key, "center_wait_released_key");

  const auto center =
      control::ProjectInputIntent(0.0, 0.5, control::HeldKey::none);
  require(center.kind == control::InputIntentKind::center, "center_action_changed");
}

int run() {
  fish_velocity_matches_legacy_update_and_duplicate_semantics();
  projected_velocity_matches_legacy_direction_and_warmup();
  adaptive_threshold_matches_legacy_bounds();
  invalid_velocity_fails_closed_without_poisoning_threshold();
  fish_side_orientation_matches_legacy_deadband();
  move_stabilizer_matches_legacy_confirmation();
  stale_hold_has_exact_legacy_grace();
  input_projection_is_pure_and_preserves_center_hold();
  std::cout << "PASS Fishing reeling control replay policy\n";
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
