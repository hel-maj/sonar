#include "sonar/fishing/equipment_recovery/equipment_recovery.h"

#include <iostream>
#include <optional>
#include <stdexcept>
#include <string_view>

namespace {

namespace recovery = sonar::fishing::equipment_recovery;
namespace settings = sonar::fishing::runtime_settings;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

[[nodiscard]] recovery::TackleCounts full_tackle() {
  return {.rod = 1, .reel = 1, .line = 1, .hook = 1, .bait = 1, .net = 1};
}

void test_tackle_priority_and_actions() {
  settings::RuntimeSettingsSnapshot policy;
  auto counts = full_tackle();
  counts.rod = 0;
  counts.line = 0;
  policy.equipment_depleted_action = settings::EquipmentDepletedAction::exit_game;
  const auto result = recovery::EvaluateTackle(counts, policy, std::nullopt);
  require(result.terminal.has_value(), "tackle_terminal_missing");
  require(result.terminal->kind == recovery::TackleKind::rod, "tackle_priority_changed");
  require(result.terminal->action == recovery::TerminalAction::exit_game, "equipment_action_changed");
  require(result.terminal->reason == "Удочка закончилась", "rod_reason_changed");
}

void test_allowed_warnings_and_session_start_net() {
  settings::RuntimeSettingsSnapshot policy;
  policy.fish_without_leader = true;
  policy.fish_without_net = true;
  auto counts = full_tackle();
  counts.hook = 0;
  counts.net = 0;
  const auto existing_net = recovery::EvaluateTackle(counts, policy, true);
  require(existing_net.warnings.size() == 2, "allowed_warning_union_changed");
  require(!existing_net.terminal.has_value(), "allowed_item_stopped_session");
  const auto absent_from_start = recovery::EvaluateTackle(counts, policy, false);
  require(absent_from_start.warnings.size() == 1, "initial_net_warning_not_suppressed");
  require(absent_from_start.warnings[0].kind == recovery::TackleKind::hook, "hook_warning_changed");
}

void test_required_hook_and_net_actions() {
  settings::RuntimeSettingsSnapshot policy;
  policy.fish_without_leader = false;
  policy.leader_depleted_action = settings::DepletedAction::exit_game;
  auto counts = full_tackle();
  counts.hook = 0;
  auto result = recovery::EvaluateTackle(counts, policy, std::nullopt);
  require(result.terminal->kind == recovery::TackleKind::hook, "hook_terminal_changed");
  require(result.terminal->action == recovery::TerminalAction::exit_game, "hook_action_changed");

  counts = full_tackle();
  counts.net = 0;
  policy.fish_without_net = false;
  policy.net_depleted_action = settings::DepletedAction::stop;
  result = recovery::EvaluateTackle(counts, policy, false);
  require(result.terminal->kind == recovery::TackleKind::net, "required_net_ignored");
  require(result.warnings.empty(), "required_net_published_allowed_warning");
}

void test_bait_notice_precedence_and_cooldown() {
  auto decision = recovery::EvaluateBaitNotice(false, 10.0, 2.0, false, true, false);
  require(decision.reason == recovery::BaitNoticeReason::disabled, "bait_disabled_changed");
  require(!decision.cooldown_advanced && decision.next_last_change_at == 2.0, "disabled_advanced_cooldown");

  decision = recovery::EvaluateBaitNotice(true, 4.99, 2.0, false, true, false);
  require(decision.reason == recovery::BaitNoticeReason::cooldown, "bait_cooldown_boundary_changed");
  decision = recovery::EvaluateBaitNotice(true, 5.0, 2.0, true, true, true);
  require(decision.reason == recovery::BaitNoticeReason::reeling, "reeling_precedence_changed");
  require(decision.cooldown_advanced && decision.next_last_change_at == 5.0, "reeling_did_not_advance_cooldown");
  decision = recovery::EvaluateBaitNotice(true, 8.0, 5.0, false, false, false);
  require(decision.reason == recovery::BaitNoticeReason::no_notice, "no_notice_changed");
  require(decision.cooldown_advanced, "no_notice_did_not_advance_cooldown");
  decision = recovery::EvaluateBaitNotice(true, 11.0, 8.0, false, false, true);
  require(decision.reason == recovery::BaitNoticeReason::begin_recovery, "gear_notice_ignored");
}

int run() {
  test_tackle_priority_and_actions();
  test_allowed_warnings_and_session_start_net();
  test_required_hook_and_net_actions();
  test_bait_notice_precedence_and_cooldown();
  std::cout << "PASS native equipment-recovery policy\n";
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
