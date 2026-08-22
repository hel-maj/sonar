#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <stop_token>
#include <string>
#include <utility>
#include <vector>

#include "maintenance_test_support.h"

#ifndef SONAR_FISHING_MAINTENANCE_FIXTURE
#error "SONAR_FISHING_MAINTENANCE_FIXTURE is required"
#endif

namespace sonar::fishing::maintenance_episode::tests {
namespace {

void require(const bool condition, const std::string& message) {
  if (!condition) {
    throw std::runtime_error(message);
  }
}

[[nodiscard]] std::string joined(const std::vector<std::string>& values) {
  std::string result;
  for (const auto& value : values) {
    if (!result.empty()) {
      result.push_back(';');
    }
    result.append(value);
  }
  return result;
}

void set_tackle(
    maintenance_observation& value,
    const std::uint32_t rod) {
  value.tackle = tackle_scan_observation{
      .available = true,
      .readable = true,
      .counts = {
          .rod = rod,
          .reel = 1,
          .line = 1,
          .hook = 1,
          .bait = 1,
          .net = 1,
      },
  };
}

void set_needs_meal(maintenance_observation& value) {
  value.player_status = memory::player_status_evidence{
      .food = 30,
      .water = 40,
  };
}

void test_fixture_episodes() {
  const maintenance_episode_runner runner;
  for (const auto& item : load_fixture(SONAR_FISHING_MAINTENANCE_FIXTURE)) {
    sequence_observer observer(item.observations);
    recording_mutation_port mutation(observer);
    const auto result = runner.run(item.request, observer, mutation);

    require(result.ok == item.expected.ok, item.id + ":ok_changed");
    require(result.reason == item.expected.reason,
            item.id + ":reason_changed:" + result.reason);
    require(result.affected_count == item.expected.affected_count,
            item.id + ":affected_count_changed");
    require(result.backpack_move_count == item.expected.backpack_move_count,
            item.id + ":backpack_move_count_changed");
    require(
        result.meal_search_disabled_until_restart ==
            item.expected.meal_search_disabled,
        item.id + ":meal_disabled_changed");
    require(
        std::abs(
            result.next_bait_change_at_seconds -
            item.expected.next_bait_change_at_seconds) < 1.0e-9,
        item.id + ":next_bait_changed");
    require(
        result.bait_cooldown_advanced ==
            item.expected.bait_cooldown_advanced,
        item.id + ":bait_cooldown_changed");
    require(result.terminal == item.expected.terminal,
            item.id + ":terminal_changed");
    require(result.warnings == item.expected.warnings,
            item.id + ":warnings_changed");
    require(observer.consumed() == item.observations.size(),
            item.id + ":observation_count_changed");
    const auto actual_intents = intent_tokens(mutation.intents);
    require(
        actual_intents == item.expected.intents,
        item.id + ":intent_sequence_changed:actual=" +
            joined(actual_intents) + ":expected=" +
            joined(item.expected.intents));
  }
}

void test_disabled_adapter_is_fail_closed() {
  auto current = observation(1, inventory::inventory_surface::gameplay);
  set_tackle(current, 1);
  sequence_observer observer({current});
  inventory::disabled_inventory_mutation_port mutation;
  maintenance_request request{
      .kind = episode_kind::tackle_check,
      .settings = valid_settings(),
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(!result.ok && result.reason == "inventory_live_adapter_disabled",
          "disabled_adapter_not_fail_closed");
  require(!result.recovery_attempted,
          "disabled_adapter_attempted_cleanup_mutation");
  require(observer.consumed() == 1, "disabled_adapter_observation_changed");
}

void test_aggregate_coherence_is_required() {
  auto current = observation(1, inventory::inventory_surface::gameplay);
  set_tackle(current, 1);
  sequence_observer observer({current});
  observer.corrupt_current_after_observe = true;
  recording_mutation_port mutation(observer);
  maintenance_request request{
      .kind = episode_kind::tackle_check,
      .settings = valid_settings(),
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(
      !result.ok && result.reason == "maintenance_observation_not_coherent",
      "aggregate_incoherence_not_blocked");
  require(!result.recovery_attempted,
          "aggregate_incoherence_attempted_preflight_cleanup");
  require(mutation.intents.empty(),
          "aggregate_incoherence_touched_mutation_boundary");
}

void test_terminal_final_gate_rejection_is_terminal() {
  std::vector<maintenance_observation> source;
  for (std::uint64_t sequence = 1; sequence <= 3; ++sequence) {
    auto current = observation(
        sequence, inventory::inventory_surface::gameplay);
    set_tackle(current, 0);
    source.push_back(std::move(current));
  }
  sequence_observer observer(std::move(source));
  recording_mutation_port mutation(observer);
  mutation.reject_at = 4;
  maintenance_request request{
      .kind = episode_kind::tackle_check,
      .settings = valid_settings(),
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(!result.ok && result.reason == "fixture_final_gate_rejected",
          "terminal_final_gate_rejection_changed");
  require(result.terminal == terminal_outcome::none,
          "rejected_terminal_was_committed");
  require(!result.recovery_attempted,
          "rejected_final_gate_reused_for_cleanup");
  require(mutation.intents.size() == 5,
          "terminal_final_gate_not_last_intent");
}

void test_stale_confirmation_runs_bounded_cleanup() {
  auto first = observation(1, inventory::inventory_surface::gameplay);
  auto stale = observation(1, inventory::inventory_surface::gameplay);
  set_tackle(first, 0);
  set_tackle(stale, 0);
  sequence_observer observer({first, stale});
  recording_mutation_port mutation(observer);
  maintenance_request request{
      .kind = episode_kind::tackle_check,
      .settings = valid_settings(),
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(!result.ok && result.reason == "inventory_observation_stale",
          "stale_confirmation_not_blocked");
  require(result.recovery_attempted && result.recovery_completed,
          "stale_confirmation_cleanup_changed");
  require(observer.consumed() == 2,
          "stale_confirmation_observation_bound_changed");
}

void test_meal_consumption_requires_exact_item_confirmation() {
  auto initial = observation(1, inventory::inventory_surface::inventory);
  set_needs_meal(initial);
  initial.inventory.items.push_back(observed_item("meal_1", "irp"));
  auto unchanged = initial;
  unchanged.inventory.sequence = 2;
  auto recovered = observation(3, inventory::inventory_surface::gameplay);
  sequence_observer observer({initial, unchanged, recovered});
  recording_mutation_port mutation(observer);
  maintenance_request request{
      .kind = episode_kind::meal_recovery,
      .settings = valid_settings(),
      .resume_fishing = false,
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(!result.ok && result.reason == "meal_consumption_not_confirmed",
          "meal_wrong_confirmation_accepted");
  require(result.affected_count == 0,
          "unconfirmed_meal_was_counted");
  require(result.recovery_attempted && result.recovery_completed,
          "meal_confirmation_cleanup_changed");
}

void test_partial_player_status_does_not_hide_hud_need() {
  auto initial = observation(1, inventory::inventory_surface::inventory);
  initial.player_status = memory::player_status_evidence{.food = 95};
  initial.thirst_visible = true;
  initial.inventory.items.push_back(observed_item("meal_1", "irp"));
  auto satisfied = observation(2, inventory::inventory_surface::inventory);
  satisfied.player_status = memory::player_status_evidence{
      .food = 95,
      .water = 95,
  };
  auto closed = observation(3, inventory::inventory_surface::gameplay);
  auto settled = observation(4, inventory::inventory_surface::gameplay);
  sequence_observer observer({initial, satisfied, closed, settled});
  recording_mutation_port mutation(observer);
  maintenance_request request{
      .kind = episode_kind::meal_recovery,
      .settings = valid_settings(),
      .resume_fishing = false,
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(result.ok && result.reason == "meal_recovered",
          "partial_status_hid_hud_need");
  require(result.affected_count == 1,
          "partial_status_skipped_consumption");
  require(
      std::any_of(
          mutation.intents.begin(),
          mutation.intents.end(),
          [](const auto& intent) {
            return intent.kind ==
                inventory::inventory_intent_kind::use_inventory_item;
          }),
      "partial_status_emitted_no_consume_intent");
}

void test_backpack_move_requires_target_or_count_delta() {
  auto initial = observation(1, inventory::inventory_surface::inventory);
  set_needs_meal(initial);
  initial.inventory.items.push_back(observed_item(
      "backpack_irp",
      "irp",
      inventory::inventory_compartment::backpack));
  auto unchanged = initial;
  unchanged.inventory.sequence = 2;
  auto recovered = observation(3, inventory::inventory_surface::gameplay);
  sequence_observer observer({initial, unchanged, recovered});
  recording_mutation_port mutation(observer);
  maintenance_request request{
      .kind = episode_kind::meal_recovery,
      .settings = valid_settings(),
      .resume_fishing = false,
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(!result.ok && result.reason == "meal_backpack_move_not_confirmed",
          "unmoved_backpack_item_accepted");
  require(result.backpack_move_count == 0,
          "unconfirmed_backpack_move_counted");
}

void test_garbage_requires_exact_target_disappearance() {
  auto initial = observation(1, inventory::inventory_surface::inventory);
  initial.inventory.items.push_back(observed_item("corn_1", "corn"));
  auto unchanged = initial;
  unchanged.inventory.sequence = 2;
  auto recovered = observation(3, inventory::inventory_surface::gameplay);
  sequence_observer observer({initial, unchanged, recovered});
  recording_mutation_port mutation(observer);
  auto configured = valid_settings();
  configured.garbage_disposal_policy.emplace("corn", true);
  maintenance_request request{
      .kind = episode_kind::garbage_disposal,
      .settings = std::move(configured),
      .resume_fishing = false,
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(!result.ok && result.reason == "garbage_disposal_not_confirmed",
          "garbage_wrong_confirmation_accepted");
  require(result.affected_count == 0,
          "unconfirmed_garbage_was_counted");
  require(result.recovery_attempted && result.recovery_completed,
          "garbage_confirmation_cleanup_changed");
}

void test_tackle_depletion_must_repeat() {
  auto depleted = observation(1, inventory::inventory_surface::gameplay);
  auto recovered = observation(2, inventory::inventory_surface::gameplay);
  set_tackle(depleted, 0);
  set_tackle(recovered, 1);
  sequence_observer observer({depleted, recovered});
  recording_mutation_port mutation(observer);
  maintenance_request request{
      .kind = episode_kind::tackle_check,
      .settings = valid_settings(),
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(result.ok && result.reason == "tackle_depletion_not_confirmed",
          "single_tackle_depletion_became_terminal");
  require(result.terminal == terminal_outcome::none,
          "single_tackle_depletion_emitted_terminal");
  require(
      std::none_of(
          mutation.intents.begin(),
          mutation.intents.end(),
          [](const auto& intent) { return terminal_intent(intent.kind); }),
      "single_tackle_depletion_mutated_terminal");
}

void test_reeling_transition_stops_bait_without_second_escape() {
  auto initial = observation(
      1,
      inventory::inventory_surface::gameplay,
      stage::observed_fishing_stage::waiting_for_bite);
  initial.changed_bait_visible = true;
  auto reeling = observation(
      2,
      inventory::inventory_surface::gameplay,
      stage::observed_fishing_stage::reeling);
  sequence_observer observer({initial, reeling});
  recording_mutation_port mutation(observer);
  maintenance_request request{
      .kind = episode_kind::bait_recovery,
      .settings = valid_settings(),
      .now_seconds = 10.0,
      .last_bait_change_at_seconds = 1.0,
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(!result.ok && result.reason == "bait_reeling_started_during_exit",
          "bait_reeling_transition_not_blocked");
  require(
      std::count_if(
          mutation.intents.begin(),
          mutation.intents.end(),
          [](const auto& intent) {
            return intent.kind == inventory::inventory_intent_kind::press_key &&
                intent.key == "esc";
          }) == 1,
      "bait_reeling_transition_emitted_second_escape");
  require(result.recovery_attempted && result.recovery_completed,
          "bait_reeling_cleanup_changed");
}

void test_initial_reeling_advances_bait_cooldown_without_mutation() {
  auto reeling = observation(
      1,
      inventory::inventory_surface::gameplay,
      stage::observed_fishing_stage::reeling);
  reeling.changed_bait_visible = true;
  reeling.reeling = memory::reeling_evidence{.active = true};
  sequence_observer observer({reeling});
  recording_mutation_port mutation(observer);
  maintenance_request request{
      .kind = episode_kind::bait_recovery,
      .settings = valid_settings(),
      .now_seconds = 10.0,
      .last_bait_change_at_seconds = 1.0,
  };

  const auto result = maintenance_episode_runner{}.run(
      request, observer, mutation);
  require(result.ok && result.reason == "bait_reeling",
          "initial_reeling_bait_reason_changed");
  require(result.bait_cooldown_advanced &&
              std::abs(result.next_bait_change_at_seconds - 10.0) < 1.0e-9,
          "initial_reeling_did_not_advance_bait_cooldown");
  require(mutation.intents.empty(),
          "initial_reeling_touched_mutation_boundary");
}

void test_cancelled_and_invalid_requests_are_mutation_free() {
  maintenance_request cancelled_request{
      .kind = episode_kind::tackle_check,
      .settings = valid_settings(),
  };
  sequence_observer cancelled_observer({});
  recording_mutation_port cancelled_mutation(cancelled_observer);
  std::stop_source stop;
  stop.request_stop();
  const auto cancelled = maintenance_episode_runner{}.run(
      cancelled_request,
      cancelled_observer,
      cancelled_mutation,
      stop.get_token());
  require(!cancelled.ok && cancelled.reason == "inventory_cancelled",
          "maintenance_cancellation_reason_changed");
  require(cancelled_observer.consumed() == 0 &&
              cancelled_mutation.intents.empty(),
          "maintenance_cancellation_touched_boundary");

  auto invalid_settings = valid_settings();
  invalid_settings.revision = 0;
  maintenance_request invalid_request{
      .kind = episode_kind::meal_recovery,
      .settings = std::move(invalid_settings),
  };
  sequence_observer invalid_observer({});
  recording_mutation_port invalid_mutation(invalid_observer);
  const auto invalid = maintenance_episode_runner{}.run(
      invalid_request, invalid_observer, invalid_mutation);
  require(!invalid.ok && invalid.reason == "settings_revision_zero",
          "maintenance_invalid_settings_reason_changed");
  require(invalid_observer.consumed() == 0 && invalid_mutation.intents.empty(),
          "maintenance_invalid_settings_touched_boundary");

  maintenance_request invalid_kind{
      .kind = static_cast<episode_kind>(255),
      .settings = valid_settings(),
  };
  sequence_observer kind_observer({});
  recording_mutation_port kind_mutation(kind_observer);
  const auto kind_result = maintenance_episode_runner{}.run(
      invalid_kind, kind_observer, kind_mutation);
  require(!kind_result.ok && kind_result.reason == "maintenance_kind_invalid",
          "maintenance_invalid_kind_reason_changed");
  require(kind_observer.consumed() == 0 && kind_mutation.intents.empty(),
          "maintenance_invalid_kind_touched_boundary");
}

}  // namespace
}  // namespace sonar::fishing::maintenance_episode::tests

int main() {
  using namespace sonar::fishing::maintenance_episode::tests;
  try {
    test_fixture_episodes();
    test_disabled_adapter_is_fail_closed();
    test_aggregate_coherence_is_required();
    test_terminal_final_gate_rejection_is_terminal();
    test_stale_confirmation_runs_bounded_cleanup();
    test_meal_consumption_requires_exact_item_confirmation();
    test_partial_player_status_does_not_hide_hud_need();
    test_backpack_move_requires_target_or_count_delta();
    test_garbage_requires_exact_target_disappearance();
    test_tackle_depletion_must_repeat();
    test_reeling_transition_stops_bait_without_second_escape();
    test_initial_reeling_advances_bait_cooldown_without_mutation();
    test_cancelled_and_invalid_requests_are_mutation_free();
    std::cout << "maintenance episode tests passed\n";
    return 0;
  } catch (const std::exception& error) {
    std::cerr << "maintenance episode tests failed: " << error.what() << '\n';
    return 1;
  }
}
