#include "sonar/fishing/lifecycle/fishing_lifecycle.h"

#include <iostream>
#include <stdexcept>
#include <string_view>

namespace {

namespace lifecycle = sonar::fishing::lifecycle;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

[[nodiscard]] lifecycle::Event event(const lifecycle::EventKind kind) {
  return lifecycle::Event{.kind = kind};
}

void start_is_fail_closed() {
  lifecycle::FishingLifecycle machine;
  auto start = event(lifecycle::EventKind::start_requested);
  start.accepted_settings_revision = 1;
  start.entitlement_valid = true;
  start.game_ready = false;
  require(!machine.Apply(start).accepted, "start_without_game_accepted");
  start.game_ready = true;
  start.entitlement_valid = false;
  require(!machine.Apply(start).accepted, "start_without_entitlement_accepted");
  start.entitlement_valid = true;
  const auto accepted = machine.Apply(start);
  require(accepted.accepted, "valid_start_rejected");
  require(accepted.snapshot.running, "accepted_start_not_running");
  require(
      accepted.snapshot.requested_episode == lifecycle::Episode::prepare_cast,
      "accepted_start_did_not_prepare_cast");
}

void trigger_precedence_maps_to_whole_episodes() {
  lifecycle::FishingLifecycle machine;
  auto start = event(lifecycle::EventKind::start_requested);
  start.accepted_settings_revision = 7;
  start.entitlement_valid = true;
  start.game_ready = true;
  require(machine.Apply(start).accepted, "start_rejected");

  const auto tackle = machine.Apply(event(lifecycle::EventKind::stage_tackle_selection));
  require(tackle.snapshot.phase == lifecycle::Phase::casting, "tackle_phase_changed");
  require(tackle.snapshot.requested_episode == lifecycle::Episode::prepare_cast, "tackle_episode_changed");
  const auto casting = machine.Apply(event(lifecycle::EventKind::stage_casting));
  require(casting.snapshot.requested_episode == lifecycle::Episode::cast, "cast_episode_changed");
  const auto waiting = machine.Apply(event(lifecycle::EventKind::stage_waiting_for_bite));
  require(waiting.snapshot.phase == lifecycle::Phase::hooking, "hook_phase_changed");
  const auto reeling = machine.Apply(event(lifecycle::EventKind::stage_reeling));
  require(reeling.snapshot.phase == lifecycle::Phase::reeling, "reel_phase_changed");
  require(reeling.snapshot.requested_episode == lifecycle::Episode::reel, "reel_episode_changed");
  const auto caught = machine.Apply(event(lifecycle::EventKind::catch_visible));
  require(caught.snapshot.phase == lifecycle::Phase::catch_resolution, "catch_phase_changed");
  require(caught.snapshot.requested_episode == lifecycle::Episode::resolve_catch, "catch_episode_changed");
}

void reeling_defers_noncritical_recovery() {
  lifecycle::FishingLifecycle machine;
  auto start = event(lifecycle::EventKind::start_requested);
  start.accepted_settings_revision = 1;
  start.entitlement_valid = true;
  start.game_ready = true;
  require(machine.Apply(start).accepted, "start_rejected");
  require(machine.Apply(event(lifecycle::EventKind::stage_reeling)).accepted, "reeling_rejected");
  require(!machine.Apply(event(lifecycle::EventKind::meal_needed)).accepted, "meal_interrupted_reeling");
  require(!machine.Apply(event(lifecycle::EventKind::bait_depleted)).accepted, "bait_interrupted_reeling");
  require(!machine.Apply(event(lifecycle::EventKind::inventory_required)).accepted, "inventory_interrupted_reeling");
  const auto queued = machine.Apply(event(lifecycle::EventKind::player_status_scan_requested));
  require(queued.accepted, "status_scan_was_not_queued");
  require(queued.snapshot.player_status_scan_pending, "status_scan_pending_flag_missing");
  require(queued.snapshot.requested_episode == lifecycle::Episode::reel, "queued_scan_split_reel_episode");
}

void stop_cleanup_is_terminal_and_explicit() {
  lifecycle::FishingLifecycle machine;
  auto start = event(lifecycle::EventKind::start_requested);
  start.accepted_settings_revision = 4;
  start.entitlement_valid = true;
  start.game_ready = true;
  require(machine.Apply(start).accepted, "start_rejected");
  const auto stopping = machine.Apply(event(lifecycle::EventKind::stop_requested));
  require(stopping.snapshot.stopping, "stop_did_not_enter_stopping");
  require(stopping.snapshot.requested_episode == lifecycle::Episode::stop_cleanup, "stop_cleanup_missing");
  require(!machine.Apply(event(lifecycle::EventKind::stage_free)).accepted, "event_mutated_stopping_state");
  const auto stopped = machine.Apply(event(lifecycle::EventKind::stop_completed));
  require(stopped.accepted, "stop_completion_rejected");
  require(!stopped.snapshot.running && !stopped.snapshot.stopping, "stop_not_terminal");
  require(stopped.snapshot.accepted_settings_revision == 4, "settings_revision_lost_on_stop");
}

void episode_failure_forces_cleanup() {
  lifecycle::FishingLifecycle machine;
  auto start = event(lifecycle::EventKind::start_requested);
  start.accepted_settings_revision = 1;
  start.entitlement_valid = true;
  start.game_ready = true;
  require(machine.Apply(start).accepted, "start_rejected");
  auto failed = event(lifecycle::EventKind::episode_failed);
  failed.reason = "capture_identity_lost";
  const auto result = machine.Apply(failed);
  require(result.accepted, "failure_transition_rejected");
  require(result.snapshot.stopping, "failure_did_not_stop");
  require(result.snapshot.last_error == "capture_identity_lost", "failure_reason_lost");
}

int run() {
  start_is_fail_closed();
  trigger_precedence_maps_to_whole_episodes();
  reeling_defers_noncritical_recovery();
  stop_cleanup_is_terminal_and_explicit();
  episode_failure_forces_cleanup();
  std::cout << "PASS Fishing whole-lifecycle state-machine gates\n";
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
