#pragma once

#include <cstdint>
#include <optional>
#include <string_view>

namespace sonar::fishing::reeling_control {

inline constexpr double kStaleInputHoldSeconds = 0.55;
inline constexpr double kLateralVelocityEpsilon = 0.65;
inline constexpr double kProjectedVelocityMinimumEpsilon = 0.20;
inline constexpr double kProjectedVelocityMaximumEpsilon = 0.75;
inline constexpr double kProjectedVelocityEpsilonWeight = 0.02;
inline constexpr double kFishBehindPlayerForwardEpsilon = 1.0;
inline constexpr double kDirectionSwitchConfirmSeconds = 0.015;
inline constexpr std::uint32_t kDirectionSwitchConfirmSamples = 2;
inline constexpr double kDirectionMove = 1.0;
inline constexpr double kDirectionEpsilon = 0.5;
inline constexpr double kFishPositionChangeEpsilon = 0.00001;
inline constexpr double kFishVelocityNewSampleWeight = 0.8;

struct Vector2 {
  double x = 0.0;
  double y = 0.0;
};

struct Position3 {
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
};

// Pure motion estimator fed by an already validated Engine observation. It
// preserves the legacy rule that duplicate/stale samples do not advance time.
class FishVelocityTracker final {
 public:
  [[nodiscard]] bool Update(
      double now_seconds,
      Position3 fish_position,
      bool using_stale_fish_position) noexcept;
  void Reset() noexcept;

  [[nodiscard]] Vector2 CurrentVelocity() const noexcept;

 private:
  std::optional<double> last_time_;
  std::optional<Vector2> last_fish_position_;
  Vector2 velocity_;
};

enum class MovementSource : std::uint8_t {
  wait_fresh_position = 0,
  motion_warmup = 1,
  wait_fish_motion = 2,
  reel_against_right_motion = 3,
  reel_against_left_motion = 4,
  invalid_sample = 5,
};

struct MovementDecision {
  double move = 0.0;
  MovementSource source = MovementSource::wait_fish_motion;
  double action_epsilon = kDirectionEpsilon;
};

struct OrientedVelocity {
  double velocity_along = 0.0;
  double fish_forward = 0.0;
  bool fish_behind_player = false;
};

// Pure adaptive decision policy. Target identity is an opaque replay/runtime
// token; memory-address validation belongs to the Engine memory adapter.
class ProjectedVelocityPolicy final {
 public:
  [[nodiscard]] MovementDecision Evaluate(
      double velocity_along,
      std::optional<std::uint64_t> target_identity,
      bool using_stale_fish_position,
      bool motion_updated) noexcept;
  void Reset() noexcept;

  [[nodiscard]] double CurrentThreshold() const noexcept;

 private:
  std::optional<std::uint64_t> target_identity_;
  double projected_velocity_ = 0.0;
  double projected_velocity_absolute_ema_ = kLateralVelocityEpsilon;
  double projected_velocity_epsilon_ = kLateralVelocityEpsilon;
};

[[nodiscard]] double FishForwardDistance(
    Vector2 right,
    Position3 player_position,
    Position3 fish_position) noexcept;

[[nodiscard]] OrientedVelocity OrientProjectedVelocityToFishSide(
    double velocity_along,
    Vector2 right,
    Position3 player_position,
    Position3 fish_position) noexcept;

enum class StabilizationSource : std::uint8_t {
  stable_center = 0,
  hold_stable_center = 1,
  stable_initial = 2,
  stable_same = 3,
  switch_pending = 4,
  switch_confirmed = 5,
};

struct StabilizedMove {
  double move = 0.0;
  StabilizationSource source = StabilizationSource::stable_center;
};

// Stateful jitter filter with replay-supplied monotonic timestamps. It owns no
// clock and performs no input; the complete Engine episode supplies both.
class MoveStabilizer final {
 public:
  [[nodiscard]] StabilizedMove Stabilize(
      double move,
      double action_epsilon,
      double now_seconds) noexcept;
  [[nodiscard]] std::optional<double> HoldLastStableMove(
      double now_seconds) const noexcept;
  void Reset() noexcept;

 private:
  [[nodiscard]] static int MoveSign(
      double move,
      double action_epsilon) noexcept;

  std::optional<int> stable_move_sign_;
  double last_stable_move_at_ = 0.0;
  std::optional<int> pending_move_sign_;
  double pending_move_since_ = 0.0;
  std::uint32_t pending_move_count_ = 0;
};

enum class HeldKey : std::uint8_t {
  none = 0,
  a = 1,
  d = 2,
};

enum class InputIntentKind : std::uint8_t {
  hold_a = 0,
  hold_d = 1,
  hold_a_wait = 2,
  hold_d_wait = 3,
  center = 4,
};

struct InputIntent {
  InputIntentKind kind = InputIntentKind::center;
  HeldKey desired_held_key = HeldKey::none;
  bool preserve_current_key = false;
};

// Maps a stable decision to an input intent only. The future input adapter must
// still recheck focus, entitlement, settings revision and its key lease before
// producing a physical side effect.
[[nodiscard]] InputIntent ProjectInputIntent(
    double move,
    double action_epsilon,
    HeldKey held_key) noexcept;

[[nodiscard]] std::string_view MovementSourceKey(
    MovementSource source) noexcept;
[[nodiscard]] std::string_view StabilizationSourceKey(
    StabilizationSource source) noexcept;
[[nodiscard]] std::string_view InputIntentKey(InputIntentKind kind) noexcept;

}  // namespace sonar::fishing::reeling_control
