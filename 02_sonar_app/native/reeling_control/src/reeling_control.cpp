#include "sonar/fishing/reeling_control/reeling_control.h"

#include <algorithm>
#include <cmath>

namespace sonar::fishing::reeling_control {

bool FishVelocityTracker::Update(
    const double now_seconds,
    const Position3 fish_position,
    const bool using_stale_fish_position) noexcept {
  if (using_stale_fish_position || !std::isfinite(now_seconds) ||
      !std::isfinite(fish_position.x) || !std::isfinite(fish_position.y)) {
    return false;
  }
  const Vector2 current{fish_position.x, fish_position.y};
  if (!last_fish_position_.has_value() || !last_time_.has_value()) {
    last_time_ = now_seconds;
    last_fish_position_ = current;
    return false;
  }

  const double delta_x = current.x - last_fish_position_->x;
  const double delta_y = current.y - last_fish_position_->y;
  if (std::hypot(delta_x, delta_y) <= kFishPositionChangeEpsilon) {
    return false;
  }
  const double delta_seconds = std::max(now_seconds - *last_time_, 0.001);
  constexpr double kOldSampleWeight = 1.0 - kFishVelocityNewSampleWeight;
  velocity_ = {
      velocity_.x * kOldSampleWeight +
          delta_x / delta_seconds * kFishVelocityNewSampleWeight,
      velocity_.y * kOldSampleWeight +
          delta_y / delta_seconds * kFishVelocityNewSampleWeight,
  };
  last_time_ = now_seconds;
  last_fish_position_ = current;
  return true;
}

void FishVelocityTracker::Reset() noexcept {
  last_time_.reset();
  last_fish_position_.reset();
  velocity_ = {};
}

Vector2 FishVelocityTracker::CurrentVelocity() const noexcept {
  return velocity_;
}

MovementDecision ProjectedVelocityPolicy::Evaluate(
    const double velocity_along,
    const std::optional<std::uint64_t> target_identity,
    const bool using_stale_fish_position,
    const bool motion_updated) noexcept {
  if (using_stale_fish_position) {
    return {0.0, MovementSource::wait_fresh_position, kDirectionEpsilon};
  }
  if (!std::isfinite(velocity_along)) {
    return {0.0, MovementSource::invalid_sample, kDirectionEpsilon};
  }
  if (!target_identity.has_value() || target_identity_ != target_identity) {
    target_identity_ = target_identity;
    projected_velocity_ = 0.0;
    projected_velocity_absolute_ema_ = kLateralVelocityEpsilon;
    projected_velocity_epsilon_ = kLateralVelocityEpsilon;
    return {0.0, MovementSource::motion_warmup, kDirectionEpsilon};
  }
  if (!motion_updated) {
    return {0.0, MovementSource::wait_fish_motion, kDirectionEpsilon};
  }

  projected_velocity_ = velocity_along;
  projected_velocity_absolute_ema_ =
      projected_velocity_absolute_ema_ *
          (1.0 - kProjectedVelocityEpsilonWeight) +
      std::abs(velocity_along) * kProjectedVelocityEpsilonWeight;
  projected_velocity_epsilon_ = std::clamp(
      projected_velocity_absolute_ema_,
      kProjectedVelocityMinimumEpsilon,
      kProjectedVelocityMaximumEpsilon);
  if (velocity_along > projected_velocity_epsilon_) {
    return {
        -kDirectionMove,
        MovementSource::reel_against_right_motion,
        kDirectionEpsilon};
  }
  if (velocity_along < -projected_velocity_epsilon_) {
    return {
        kDirectionMove,
        MovementSource::reel_against_left_motion,
        kDirectionEpsilon};
  }
  return {0.0, MovementSource::wait_fish_motion, kDirectionEpsilon};
}

void ProjectedVelocityPolicy::Reset() noexcept {
  target_identity_.reset();
  projected_velocity_ = 0.0;
  projected_velocity_absolute_ema_ = kLateralVelocityEpsilon;
  projected_velocity_epsilon_ = kLateralVelocityEpsilon;
}

double ProjectedVelocityPolicy::CurrentThreshold() const noexcept {
  return projected_velocity_epsilon_;
}

double FishForwardDistance(
    const Vector2 right,
    const Position3 player_position,
    const Position3 fish_position) noexcept {
  const Vector2 forward{-right.y, right.x};
  return (fish_position.x - player_position.x) * forward.x +
      (fish_position.y - player_position.y) * forward.y;
}

OrientedVelocity OrientProjectedVelocityToFishSide(
    const double velocity_along,
    const Vector2 right,
    const Position3 player_position,
    const Position3 fish_position) noexcept {
  const double fish_forward =
      FishForwardDistance(right, player_position, fish_position);
  const bool fish_behind_player =
      fish_forward < -kFishBehindPlayerForwardEpsilon;
  return {
      fish_behind_player ? -velocity_along : velocity_along,
      fish_forward,
      fish_behind_player};
}

StabilizedMove MoveStabilizer::Stabilize(
    const double move,
    const double action_epsilon,
    const double now_seconds) noexcept {
  const int sign = MoveSign(move, action_epsilon);
  if (sign == 0) {
    pending_move_sign_.reset();
    pending_move_since_ = 0.0;
    pending_move_count_ = 0;
    if (!stable_move_sign_.has_value()) {
      return {0.0, StabilizationSource::stable_center};
    }
    return {
        static_cast<double>(*stable_move_sign_) * kDirectionMove,
        StabilizationSource::hold_stable_center};
  }
  if (!stable_move_sign_.has_value()) {
    stable_move_sign_ = sign;
    last_stable_move_at_ = now_seconds;
    pending_move_sign_.reset();
    pending_move_since_ = 0.0;
    pending_move_count_ = 0;
    return {
        static_cast<double>(sign) * kDirectionMove,
        StabilizationSource::stable_initial};
  }
  if (sign == *stable_move_sign_) {
    last_stable_move_at_ = now_seconds;
    pending_move_sign_.reset();
    pending_move_since_ = 0.0;
    pending_move_count_ = 0;
    return {
        static_cast<double>(sign) * kDirectionMove,
        StabilizationSource::stable_same};
  }
  if (!pending_move_sign_.has_value() || sign != *pending_move_sign_) {
    pending_move_sign_ = sign;
    pending_move_since_ = now_seconds;
    pending_move_count_ = 1;
    return {
        static_cast<double>(*stable_move_sign_) * kDirectionMove,
        StabilizationSource::switch_pending};
  }

  ++pending_move_count_;
  const double pending_age = now_seconds - pending_move_since_;
  if (pending_move_count_ >= kDirectionSwitchConfirmSamples &&
      pending_age >= kDirectionSwitchConfirmSeconds) {
    stable_move_sign_ = sign;
    last_stable_move_at_ = now_seconds;
    pending_move_sign_.reset();
    pending_move_since_ = 0.0;
    pending_move_count_ = 0;
    return {
        static_cast<double>(sign) * kDirectionMove,
        StabilizationSource::switch_confirmed};
  }
  return {
      static_cast<double>(*stable_move_sign_) * kDirectionMove,
      StabilizationSource::switch_pending};
}

std::optional<double> MoveStabilizer::HoldLastStableMove(
    const double now_seconds) const noexcept {
  if (!stable_move_sign_.has_value() || last_stable_move_at_ <= 0.0 ||
      now_seconds - last_stable_move_at_ > kStaleInputHoldSeconds) {
    return std::nullopt;
  }
  return static_cast<double>(*stable_move_sign_) * kDirectionMove;
}

void MoveStabilizer::Reset() noexcept {
  stable_move_sign_.reset();
  last_stable_move_at_ = 0.0;
  pending_move_sign_.reset();
  pending_move_since_ = 0.0;
  pending_move_count_ = 0;
}

int MoveStabilizer::MoveSign(
    const double move,
    const double action_epsilon) noexcept {
  if (move > action_epsilon) {
    return 1;
  }
  if (move < -action_epsilon) {
    return -1;
  }
  return 0;
}

InputIntent ProjectInputIntent(
    const double move,
    const double action_epsilon,
    const HeldKey held_key) noexcept {
  if (move > action_epsilon) {
    return {InputIntentKind::hold_d, HeldKey::d, false};
  }
  if (move < -action_epsilon) {
    return {InputIntentKind::hold_a, HeldKey::a, false};
  }
  if (held_key == HeldKey::d) {
    return {InputIntentKind::hold_d_wait, HeldKey::d, true};
  }
  if (held_key == HeldKey::a) {
    return {InputIntentKind::hold_a_wait, HeldKey::a, true};
  }
  return {InputIntentKind::center, HeldKey::none, false};
}

std::string_view MovementSourceKey(const MovementSource source) noexcept {
  switch (source) {
    case MovementSource::wait_fresh_position: return "wait_fresh_position";
    case MovementSource::motion_warmup: return "motion_warmup";
    case MovementSource::wait_fish_motion: return "wait_fish_motion";
    case MovementSource::reel_against_right_motion:
      return "reel_against_right_motion";
    case MovementSource::reel_against_left_motion:
      return "reel_against_left_motion";
    case MovementSource::invalid_sample: return "invalid_sample";
  }
  return "unknown";
}

std::string_view StabilizationSourceKey(
    const StabilizationSource source) noexcept {
  switch (source) {
    case StabilizationSource::stable_center: return "stable_center";
    case StabilizationSource::hold_stable_center: return "hold_stable_center";
    case StabilizationSource::stable_initial: return "stable_initial";
    case StabilizationSource::stable_same: return "stable_same";
    case StabilizationSource::switch_pending: return "switch_pending";
    case StabilizationSource::switch_confirmed: return "switch_confirmed";
  }
  return "unknown";
}

std::string_view InputIntentKey(const InputIntentKind kind) noexcept {
  switch (kind) {
    case InputIntentKind::hold_a: return "hold_a";
    case InputIntentKind::hold_d: return "hold_d";
    case InputIntentKind::hold_a_wait: return "hold_a_wait";
    case InputIntentKind::hold_d_wait: return "hold_d_wait";
    case InputIntentKind::center: return "center";
  }
  return "unknown";
}

}  // namespace sonar::fishing::reeling_control
