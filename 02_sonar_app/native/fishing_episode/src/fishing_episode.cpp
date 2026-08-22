#include "sonar/fishing/fishing_episode/fishing_episode.h"

#include "episode_validation.h"

#include <cmath>
#include <exception>
#include <utility>

namespace sonar::fishing::fishing_episode {
namespace {

using detail::elapsed_ns;
using detail::memory_reports_finished;
using detail::observed_stage;

enum class episode_phase : std::uint8_t {
  casting,
  confirming_cast,
  hooking,
  confirming_hook,
  reeling,
};

class episode final {
 public:
  episode(
      const fishing_episode_request& request,
      fishing_episode_observer& observer,
      fishing_mutation_session& mutation,
      const std::stop_token stop_token)
      : request_(request),
        observer_(observer),
        mutation_(mutation),
        stop_token_(stop_token) {}

  [[nodiscard]] fishing_episode_result run() {
    if (!observe()) {
      return failure();
    }
    episode_started_at_ = last_.captured_at_steady_ns;
    phase_started_at_ = episode_started_at_;
    if (last_.catch_visible) {
      return success(
          "fishing_catch_visible",
          fishing_episode_outcome::catch_visible);
    }
    if (!select_initial_phase()) {
      return failure();
    }

    while (true) {
      if (stop_token_.stop_requested()) {
        return fail("fishing_episode_cancelled");
      }
      if (last_.catch_visible) {
        return success(
            "fishing_catch_visible",
            fishing_episode_outcome::catch_visible);
      }
      if (elapsed_ns(last_.captured_at_steady_ns, episode_started_at_) >
          request_.episode_timeout_ns) {
        return fail("fishing_episode_timeout");
      }

      bool need_observation = false;
      switch (phase_) {
        case episode_phase::casting:
          need_observation = handle_casting();
          break;
        case episode_phase::confirming_cast:
          need_observation = handle_cast_confirmation();
          break;
        case episode_phase::hooking:
          need_observation = handle_hooking();
          break;
        case episode_phase::confirming_hook:
          need_observation = handle_hook_confirmation();
          break;
        case episode_phase::reeling:
          need_observation = handle_reeling();
          break;
      }
      if (!terminal_.reason.empty()) {
        return terminal_;
      }
      if (need_observation && !observe()) {
        return failure();
      }
    }
  }

  [[nodiscard]] std::uint64_t last_sequence() const noexcept {
    return validator_.last_sequence();
  }

 private:
  [[nodiscard]] bool observe() {
    if (stop_token_.stop_requested()) {
      failure_reason_ = "fishing_episode_cancelled";
      return false;
    }
    if (observations_consumed_ >= request_.maximum_observations) {
      failure_reason_ = "fishing_observation_limit_reached";
      return false;
    }
    fishing_episode_observation observation;
    try {
      observation = observer_.observe(stop_token_);
    } catch (const std::exception& error) {
      failure_reason_ = std::string("fishing_observation_failed:") +
          error.what();
      return false;
    } catch (...) {
      failure_reason_ = "fishing_observation_failed:unknown";
      return false;
    }
    ++observations_consumed_;
    last_ = observation;
    if (!validator_.validate(observation, failure_reason_)) {
      return false;
    }
    last_ = std::move(observation);
    return true;
  }

  [[nodiscard]] bool select_initial_phase() {
    using stage_detection::observed_fishing_stage;
    switch (observed_stage(last_)) {
      case observed_fishing_stage::casting:
        phase_ = episode_phase::casting;
        return true;
      case observed_fishing_stage::waiting_for_bite:
        phase_ = episode_phase::hooking;
        return true;
      case observed_fishing_stage::reeling:
        phase_ = episode_phase::reeling;
        return true;
      case observed_fishing_stage::none:
        failure_reason_ = "fishing_stage_unavailable";
        return false;
      case observed_fishing_stage::tackle_selection:
        failure_reason_ = "fishing_tackle_selection_not_owned";
        return false;
    }
    failure_reason_ = "fishing_stage_invalid";
    return false;
  }

  [[nodiscard]] bool handle_casting() {
    using stage_detection::observed_fishing_stage;
    const auto stage = observed_stage(last_);
    if (stage == observed_fishing_stage::waiting_for_bite) {
      transition(episode_phase::hooking);
      return false;
    }
    if (stage == observed_fishing_stage::reeling) {
      transition(episode_phase::reeling);
      return false;
    }
    if (stage != observed_fishing_stage::casting) {
      set_terminal(fail("fishing_casting_stage_lost"));
      return false;
    }
    if (elapsed_ns(last_.captured_at_steady_ns, phase_started_at_) >
        request_.casting_timeout_ns) {
      set_terminal(fail("fishing_casting_timeout"));
      return false;
    }
    if (!last_.cast_ready) {
      return true;
    }
    if (!apply_space(fishing_mutation_kind::tap_cast_space)) {
      set_terminal(failure());
      return false;
    }
    transition(episode_phase::confirming_cast);
    return true;
  }

  [[nodiscard]] bool handle_cast_confirmation() {
    using stage_detection::observed_fishing_stage;
    const auto stage = observed_stage(last_);
    if (stage == observed_fishing_stage::waiting_for_bite) {
      transition(episode_phase::hooking);
      return false;
    }
    if (stage == observed_fishing_stage::reeling) {
      transition(episode_phase::reeling);
      return false;
    }
    if (stage != observed_fishing_stage::casting) {
      set_terminal(fail("fishing_cast_confirmation_stage_invalid"));
      return false;
    }
    if (elapsed_ns(last_.captured_at_steady_ns, phase_started_at_) >
        request_.casting_confirmation_timeout_ns) {
      set_terminal(fail("fishing_cast_not_confirmed"));
      return false;
    }
    return true;
  }

  [[nodiscard]] bool handle_hooking() {
    using stage_detection::observed_fishing_stage;
    const auto stage = observed_stage(last_);
    if (stage == observed_fishing_stage::reeling) {
      transition(episode_phase::reeling);
      return false;
    }
    if (stage != observed_fishing_stage::waiting_for_bite) {
      set_terminal(fail("fishing_hooking_stage_lost"));
      return false;
    }
    if (elapsed_ns(last_.captured_at_steady_ns, phase_started_at_) >
        request_.hooking_timeout_ns) {
      set_terminal(fail("fishing_hooking_timeout"));
      return false;
    }
    if (last_.hook == hook_cue::none) {
      return true;
    }
    if (!apply_space(fishing_mutation_kind::tap_hook_space)) {
      set_terminal(failure());
      return false;
    }
    transition(episode_phase::confirming_hook);
    return true;
  }

  [[nodiscard]] bool handle_hook_confirmation() {
    using stage_detection::observed_fishing_stage;
    const auto stage = observed_stage(last_);
    if (stage == observed_fishing_stage::reeling) {
      transition(episode_phase::reeling);
      return false;
    }
    if (stage != observed_fishing_stage::waiting_for_bite) {
      set_terminal(fail("fishing_hook_confirmation_stage_invalid"));
      return false;
    }
    if (elapsed_ns(last_.captured_at_steady_ns, phase_started_at_) >
        request_.hooking_confirmation_timeout_ns) {
      set_terminal(fail("fishing_hook_not_confirmed"));
      return false;
    }
    return true;
  }

  [[nodiscard]] bool handle_reeling() {
    using stage_detection::observed_fishing_stage;
    if (observed_stage(last_) != observed_fishing_stage::reeling) {
      if (memory_reports_finished(last_)) {
        set_terminal(success(
            "fishing_memory_finished",
            fishing_episode_outcome::memory_finished));
      } else {
        set_terminal(fail("fishing_reeling_stage_lost_unconfirmed"));
      }
      return false;
    }
    if (elapsed_ns(last_.captured_at_steady_ns, phase_started_at_) >
        request_.reeling_timeout_ns) {
      set_terminal(fail("fishing_reeling_timeout"));
      return false;
    }

    const auto& evidence = *last_.memory->reeling;
    if (!evidence.active) {
      set_terminal(success(
          "fishing_memory_finished",
          fishing_episode_outcome::memory_finished));
      return false;
    }
    if (!request_.reeling_input_enabled) {
      return true;
    }

    const double now_seconds =
        static_cast<double>(last_.captured_at_steady_ns) / 1'000'000'000.0;
    const reeling_control::Position3 fish_position{
        evidence.fish_position.x,
        evidence.fish_position.y,
        evidence.fish_position.z};
    const bool motion_updated = velocity_.Update(
        now_seconds, fish_position, false);
    const auto velocity = velocity_.CurrentVelocity();
    const reeling_control::Vector2 right{
        evidence.player_right_x,
        evidence.player_right_y};
    const reeling_control::Position3 player_position{
        evidence.player_position.x,
        evidence.player_position.y,
        evidence.player_position.z};
    const double velocity_along =
        velocity.x * right.x + velocity.y * right.y;
    const auto oriented = reeling_control::OrientProjectedVelocityToFishSide(
        velocity_along, right, player_position, fish_position);
    const auto decision = policy_.Evaluate(
        oriented.velocity_along,
        request_.episode_identity,
        false,
        motion_updated);
    const auto stabilized = stabilizer_.Stabilize(
        decision.move, decision.action_epsilon, now_seconds);
    const auto intent = reeling_control::ProjectInputIntent(
        stabilized.move,
        decision.action_epsilon,
        reeling_control::HeldKey::none);
    if (intent.preserve_current_key ||
        intent.desired_held_key == reeling_control::HeldKey::none) {
      return true;
    }
    if (!apply_reeling_pulse(intent.desired_held_key)) {
      set_terminal(failure());
      return false;
    }
    return true;
  }

  [[nodiscard]] bool apply_space(const fishing_mutation_kind kind) {
    return apply({
        .kind = kind,
        .expected_observation_sequence = last_.sequence,
        .expected_settings_revision = request_.accepted_settings_revision,
        .expected_entitlement_revision =
            request_.expected_entitlement_revision,
        .expected_lifecycle_revision = request_.expected_lifecycle_revision,
        .packet_count = 2U,
    });
  }

  [[nodiscard]] bool apply_reeling_pulse(
      const reeling_control::HeldKey desired_key) {
    if (desired_key != reeling_control::HeldKey::a &&
        desired_key != reeling_control::HeldKey::d) {
      failure_reason_ = "fishing_reeling_pulse_key_invalid";
      return false;
    }
    return apply({
        .kind = fishing_mutation_kind::pulse_reeling_key,
        .expected_observation_sequence = last_.sequence,
        .expected_settings_revision = request_.accepted_settings_revision,
        .expected_entitlement_revision = request_.expected_entitlement_revision,
        .expected_lifecycle_revision = request_.expected_lifecycle_revision,
        .desired_reeling_key = desired_key,
        .packet_count = 2U,
    });
  }

  [[nodiscard]] bool apply(const fishing_mutation_intent& intent) {
    if (stop_token_.stop_requested()) {
      failure_reason_ = "fishing_episode_cancelled";
      return false;
    }
    try {
      const auto result = mutation_.apply(intent, stop_token_);
      if (!result.applied) {
        failure_reason_ = result.reason.empty()
            ? "fishing_final_gate_rejected"
            : result.reason;
        return false;
      }
    } catch (const std::exception& error) {
      failure_reason_ = std::string("fishing_mutation_failed:") +
          error.what();
      return false;
    } catch (...) {
      failure_reason_ = "fishing_mutation_failed:unknown";
      return false;
    }
    ++mutations_applied_;
    return true;
  }

  void transition(const episode_phase phase) noexcept {
    phase_ = phase;
    phase_started_at_ = last_.captured_at_steady_ns;
    if (phase == episode_phase::reeling) {
      velocity_.Reset();
      policy_.Reset();
      stabilizer_.Reset();
    }
  }

  void set_terminal(fishing_episode_result result) {
    terminal_ = std::move(result);
  }

  [[nodiscard]] fishing_episode_result success(
      std::string reason,
      const fishing_episode_outcome outcome) const {
    return {
        .ok = true,
        .reason = std::move(reason),
        .outcome = outcome,
        .observations_consumed = observations_consumed_,
        .mutations_applied = mutations_applied_,
        .observation = last_,
    };
  }

  [[nodiscard]] fishing_episode_result fail(std::string reason) const {
    return {
        .ok = false,
        .reason = std::move(reason),
        .observations_consumed = observations_consumed_,
        .mutations_applied = mutations_applied_,
        .observation = last_,
    };
  }

  [[nodiscard]] fishing_episode_result failure() const {
    return fail(failure_reason_.empty()
        ? "fishing_episode_failed"
        : failure_reason_);
  }

  const fishing_episode_request& request_;
  fishing_episode_observer& observer_;
  fishing_mutation_session& mutation_;
  std::stop_token stop_token_;
  fishing_episode_observation last_;
  fishing_episode_result terminal_;
  episode_phase phase_{episode_phase::casting};
  std::uint64_t episode_started_at_{};
  std::uint64_t phase_started_at_{};
  std::size_t observations_consumed_{};
  std::size_t mutations_applied_{};
  reeling_control::FishVelocityTracker velocity_;
  reeling_control::ProjectedVelocityPolicy policy_;
  reeling_control::MoveStabilizer stabilizer_;
  detail::observation_validator validator_;
  std::string failure_reason_;
};

}  // namespace

fishing_mutation_result fishing_mutation_result::accepted() {
  return {.applied = true};
}

fishing_mutation_result fishing_mutation_result::rejected(
    std::string reason) {
  return {.applied = false, .reason = std::move(reason)};
}

fishing_episode_result fishing_episode_runner::run(
    const fishing_episode_request& request,
    fishing_episode_observer& observer,
    fishing_mutation_port& mutation,
    const std::stop_token stop_token) const {
  std::string reason;
  if (!detail::valid_request(request, reason)) {
    return {.reason = std::move(reason)};
  }
  if (stop_token.stop_requested()) {
    return {.reason = "fishing_episode_cancelled"};
  }

  std::unique_ptr<fishing_mutation_session> session;
  try {
    session = mutation.acquire(request, stop_token, reason);
  } catch (const std::exception& error) {
    return {.reason = std::string("fishing_lease_failed:") + error.what()};
  } catch (...) {
    return {.reason = "fishing_lease_failed:unknown"};
  }
  if (!session) {
    return {.reason = reason.empty()
        ? "fishing_input_lease_unavailable"
        : std::move(reason)};
  }

  episode operation(request, observer, *session, stop_token);
  fishing_episode_result result;
  try {
    result = operation.run();
  } catch (const std::exception& error) {
    result.reason = std::string("fishing_episode_failed:") + error.what();
  } catch (...) {
    result.reason = "fishing_episode_failed:unknown";
  }
  result.cleanup_attempted = true;
  const auto cleanup = session->cleanup_reeling_keys(
      operation.last_sequence());
  result.cleanup_completed = cleanup.applied;
  if (!cleanup.applied && result.ok) {
    result.ok = false;
    result.outcome = fishing_episode_outcome::none;
    result.reason = cleanup.reason.empty()
        ? "fishing_cleanup_failed"
        : cleanup.reason;
  }
  return result;
}

std::unique_ptr<fishing_mutation_session>
disabled_fishing_mutation_port::acquire(
    const fishing_episode_request& request,
    const std::stop_token stop_token,
    std::string& reason) {
  static_cast<void>(request);
  static_cast<void>(stop_token);
  reason = "fishing_live_adapter_disabled";
  return nullptr;
}

const char* fishing_mutation_key(
    const fishing_mutation_kind kind) noexcept {
  switch (kind) {
    case fishing_mutation_kind::tap_cast_space:
      return "tap_cast_space";
    case fishing_mutation_kind::tap_hook_space:
      return "tap_hook_space";
    case fishing_mutation_kind::pulse_reeling_key:
      return "pulse_reeling_key";
  }
  return "unknown";
}

const char* fishing_outcome_key(
    const fishing_episode_outcome outcome) noexcept {
  switch (outcome) {
    case fishing_episode_outcome::none:
      return "none";
    case fishing_episode_outcome::memory_finished:
      return "memory_finished";
    case fishing_episode_outcome::catch_visible:
      return "catch_visible";
  }
  return "unknown";
}

}  // namespace sonar::fishing::fishing_episode
