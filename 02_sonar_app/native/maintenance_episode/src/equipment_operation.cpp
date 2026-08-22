#include "maintenance_operation.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <optional>
#include <string>
#include <utility>

namespace sonar::fishing::maintenance_episode::detail {
namespace {

constexpr std::array<std::size_t, 4> kTackleRetryMilliseconds{
    6'000, 2'000, 2'000, 2'000};
constexpr std::size_t kTackleConfirmationAttempts = 2;
constexpr std::size_t kTackleConfirmationMilliseconds = 500;
constexpr std::size_t kBaitExitAttempts = 16;
constexpr std::size_t kBaitExitMilliseconds = 300;
constexpr std::size_t kBaitRestartAttempts = 10;
constexpr std::size_t kBaitRestartMilliseconds = 1'500;

[[nodiscard]] bool all_zero(
    const equipment_recovery::TackleCounts& value) noexcept {
  return value.rod == 0 && value.reel == 0 && value.line == 0 &&
      value.hook == 0 && value.bait == 0 && value.net == 0;
}

[[nodiscard]] bool usable(const tackle_scan_observation& value) noexcept {
  return value.available && value.readable && !value.obscured &&
      !all_zero(value.counts);
}

[[nodiscard]] bool reeling_active(
    const maintenance_observation& value) noexcept {
  return value.inventory.fishing_stage ==
          stage_detection::observed_fishing_stage::reeling ||
      (value.reeling.has_value() && value.reeling->active);
}

[[nodiscard]] bool fishing_stage_active(
    const maintenance_observation& value) noexcept {
  return value.inventory.fishing_stage !=
      stage_detection::observed_fishing_stage::none;
}

[[nodiscard]] bool gameplay_surface(
    const maintenance_observation& value) noexcept {
  return value.inventory.surface ==
      inventory_store::inventory_surface::gameplay;
}

[[nodiscard]] bool inventory_surface(
    const maintenance_observation& value) noexcept {
  return value.inventory.surface ==
          inventory_store::inventory_surface::inventory ||
      value.inventory.surface ==
          inventory_store::inventory_surface::item_context_menu;
}

[[nodiscard]] inventory_store::inventory_mutation_intent key_press(
    std::string key) {
  return {
      .kind = inventory_store::inventory_intent_kind::press_key,
      .key = std::move(key),
      .packet_count = 2,
  };
}

[[nodiscard]] terminal_outcome terminal_for(
    const equipment_recovery::TerminalAction value) noexcept {
  switch (value) {
    case equipment_recovery::TerminalAction::stop:
      return terminal_outcome::stop;
    case equipment_recovery::TerminalAction::exit_game:
      return terminal_outcome::exit_game;
    case equipment_recovery::TerminalAction::shutdown_pc:
      return terminal_outcome::shutdown_pc;
  }
  return terminal_outcome::none;
}

void append_warnings(
    std::vector<equipment_recovery::TackleKind>& destination,
    const equipment_recovery::TackleEvaluation& evaluation) {
  for (const auto& warning : evaluation.warnings) {
    if (std::find(destination.begin(), destination.end(), warning.kind) ==
        destination.end()) {
      destination.push_back(warning.kind);
    }
  }
}

}  // namespace

bool operation::execute_tackle(
    inventory_store::inventory_episode_context& context,
    const std::stop_token stop_token) {
  const maintenance_observation* observation = coherent(context);
  if (observation == nullptr) {
    return false;
  }
  if (!gameplay_surface(*observation)) {
    return context.reject("tackle_surface_invalid");
  }

  const tackle_scan_observation* scan = observation->tackle.has_value()
      ? &*observation->tackle
      : nullptr;
  for (const auto delay : kTackleRetryMilliseconds) {
    if (scan != nullptr && usable(*scan)) {
      break;
    }
    if (stop_requested(context, stop_token) || !context.wait(delay) ||
        !context.refresh()) {
      return false;
    }
    observation = coherent(context);
    if (observation == nullptr) {
      return false;
    }
    if (!gameplay_surface(*observation)) {
      return context.reject("tackle_surface_invalid");
    }
    scan = observation->tackle.has_value() ? &*observation->tackle : nullptr;
  }

  if (scan == nullptr || !usable(*scan)) {
    if (scan != nullptr && scan->obscured) {
      completion_reason_ = "tackle_obscured_skipped";
      return true;
    }
    completion_reason_ = "tackle_unreadable_stop";
    return emit_terminal(context, terminal_outcome::stop);
  }

  auto evaluation = equipment_recovery::EvaluateTackle(
      scan->counts, request_.settings, request_.session_started_with_net);
  append_warnings(warnings_, evaluation);
  if (!evaluation.terminal.has_value()) {
    completion_reason_ = warnings_.empty() ? "tackle_ok" : "tackle_warning";
    return true;
  }

  const auto expected_kind = evaluation.terminal->kind;
  for (std::size_t attempt = 0;
       attempt < kTackleConfirmationAttempts;
       ++attempt) {
    if (stop_requested(context, stop_token) ||
        !context.wait(kTackleConfirmationMilliseconds) ||
        !context.refresh()) {
      return false;
    }
    observation = coherent(context);
    if (observation == nullptr) {
      return false;
    }
    if (!gameplay_surface(*observation)) {
      return context.reject("tackle_surface_invalid");
    }
    if (!observation->tackle.has_value() || !usable(*observation->tackle)) {
      return context.reject("tackle_confirmation_unavailable");
    }
    evaluation = equipment_recovery::EvaluateTackle(
        observation->tackle->counts,
        request_.settings,
        request_.session_started_with_net);
    append_warnings(warnings_, evaluation);
    if (!evaluation.terminal.has_value() ||
        evaluation.terminal->kind != expected_kind) {
      completion_reason_ = "tackle_depletion_not_confirmed";
      return true;
    }
  }

  const auto outcome = terminal_for(evaluation.terminal->action);
  completion_reason_ = std::string("tackle_depleted_") + key(outcome);
  return emit_terminal(context, outcome);
}

bool operation::execute_bait(
    inventory_store::inventory_episode_context& context,
    const std::stop_token stop_token) {
  const auto* observation = coherent(context);
  if (observation == nullptr) {
    return false;
  }
  if (!gameplay_surface(*observation)) {
    return context.reject("bait_surface_invalid");
  }
  if (!bait_recovery_admitted_) {
    return context.reject("bait_recovery_not_admitted");
  }

  if (!context.mutate(key_press("esc")) ||
      !context.wait(kBaitExitMilliseconds) || !context.refresh()) {
    return false;
  }
  for (std::size_t attempt = 0; attempt < kBaitExitAttempts; ++attempt) {
    observation = coherent(context);
    if (observation == nullptr) {
      return false;
    }
    if (reeling_active(*observation)) {
      return context.reject("bait_reeling_started_during_exit");
    }
    if (inventory_surface(*observation)) {
      return context.reject("bait_surface_invalid");
    }
    if (gameplay_surface(*observation) &&
        !fishing_stage_active(*observation)) {
      break;
    }
    if (stop_requested(context, stop_token) ||
        !context.mutate(key_press("esc")) ||
        !context.wait(kBaitExitMilliseconds) || !context.refresh()) {
      return false;
    }
  }
  observation = coherent(context);
  if (observation == nullptr) {
    return false;
  }
  if (!gameplay_surface(*observation) ||
      fishing_stage_active(*observation)) {
    return context.reject("bait_stage_exit_not_confirmed");
  }

  for (std::size_t attempt = 0; attempt < kBaitRestartAttempts; ++attempt) {
    if (stop_requested(context, stop_token) ||
        !context.mutate(key_press("e")) ||
        !context.wait(kBaitRestartMilliseconds) || !context.refresh()) {
      return false;
    }
    observation = coherent(context);
    if (observation == nullptr) {
      return false;
    }
    if (!gameplay_surface(*observation)) {
      return context.reject("bait_surface_invalid");
    }
    if (fishing_stage_active(*observation)) {
      ++affected_count_;
      completion_reason_ = "bait_recovered";
      return true;
    }
  }

  completion_reason_ = "bait_restart_failed_stop";
  return emit_terminal(context, terminal_outcome::stop);
}

}  // namespace sonar::fishing::maintenance_episode::detail
