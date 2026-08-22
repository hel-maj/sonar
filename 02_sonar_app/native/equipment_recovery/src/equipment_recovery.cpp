#include "sonar/fishing/equipment_recovery/equipment_recovery.h"

#include <array>
#include <cmath>
#include <stdexcept>

namespace sonar::fishing::equipment_recovery {
namespace {

constexpr double kBaitChangeCooldownSeconds = 3.0;

struct Check {
  TackleKind kind;
  std::string_view reason;
};

constexpr std::array<Check, 6> kChecks{{
    {TackleKind::rod, "Удочка закончилась"},
    {TackleKind::reel, "Катушка закончилась"},
    {TackleKind::line, "Кончилась леска"},
    {TackleKind::hook, "Закончились крючки/поводки"},
    {TackleKind::bait, "Закончилась наживка/блёсна"},
    {TackleKind::net, "Подсак закончился"},
}};

[[nodiscard]] TerminalAction Map(
    const runtime_settings::EquipmentDepletedAction action) noexcept {
  switch (action) {
    case runtime_settings::EquipmentDepletedAction::stop:
      return TerminalAction::stop;
    case runtime_settings::EquipmentDepletedAction::exit_game:
      return TerminalAction::exit_game;
    case runtime_settings::EquipmentDepletedAction::shutdown_pc:
      return TerminalAction::shutdown_pc;
  }
  return TerminalAction::stop;
}

[[nodiscard]] TerminalAction Map(
    const runtime_settings::DepletedAction action) noexcept {
  switch (action) {
    case runtime_settings::DepletedAction::stop:
      return TerminalAction::stop;
    case runtime_settings::DepletedAction::exit_game:
      return TerminalAction::exit_game;
  }
  return TerminalAction::stop;
}

[[nodiscard]] bool AllowedWithout(
    const TackleKind kind,
    const runtime_settings::RuntimeSettingsSnapshot& settings) noexcept {
  return (kind == TackleKind::hook && settings.fish_without_leader) ||
      (kind == TackleKind::net && settings.fish_without_net);
}

[[nodiscard]] TerminalAction Action(
    const TackleKind kind,
    const runtime_settings::RuntimeSettingsSnapshot& settings) noexcept {
  if (kind == TackleKind::hook) {
    return Map(settings.leader_depleted_action);
  }
  if (kind == TackleKind::net) {
    return Map(settings.net_depleted_action);
  }
  return Map(settings.equipment_depleted_action);
}

}  // namespace

std::uint32_t TackleCounts::count(const TackleKind kind) const noexcept {
  switch (kind) {
    case TackleKind::rod:
      return rod;
    case TackleKind::reel:
      return reel;
    case TackleKind::line:
      return line;
    case TackleKind::hook:
      return hook;
    case TackleKind::bait:
      return bait;
    case TackleKind::net:
      return net;
  }
  return 0;
}

TackleEvaluation EvaluateTackle(
    const TackleCounts& counts,
    const runtime_settings::RuntimeSettingsSnapshot& settings,
    const std::optional<bool> session_started_with_net) {
  TackleEvaluation result;
  if (counts.hook == 0 && settings.fish_without_leader) {
    result.warnings.push_back({
        .kind = TackleKind::hook,
        .reason = "Закончились крючки/поводки",
    });
  }
  if (counts.net == 0 && settings.fish_without_net &&
      session_started_with_net != false) {
    result.warnings.push_back({
        .kind = TackleKind::net,
        .reason = "Подсак закончился",
    });
  }
  for (const Check& check : kChecks) {
    if (counts.count(check.kind) > 0 || AllowedWithout(check.kind, settings)) {
      continue;
    }
    result.terminal = TerminalInstruction{
        .kind = check.kind,
        .action = Action(check.kind, settings),
        .reason = check.reason,
    };
    break;
  }
  return result;
}

BaitNoticeDecision EvaluateBaitNotice(
    const bool auto_change_bait,
    const double now_seconds,
    const double last_change_at,
    const bool reeling_visible,
    const bool changed_bait_visible,
    const bool gear_visible) {
  if (!std::isfinite(now_seconds) || !std::isfinite(last_change_at)) {
    throw std::invalid_argument("bait_change_time_invalid");
  }
  if (!auto_change_bait) {
    return {
        .reason = BaitNoticeReason::disabled,
        .next_last_change_at = last_change_at,
        .cooldown_advanced = false,
    };
  }
  if (now_seconds - last_change_at < kBaitChangeCooldownSeconds) {
    return {
        .reason = BaitNoticeReason::cooldown,
        .next_last_change_at = last_change_at,
        .cooldown_advanced = false,
    };
  }
  BaitNoticeDecision result{
      .reason = BaitNoticeReason::no_notice,
      .next_last_change_at = now_seconds,
      .cooldown_advanced = true,
  };
  if (reeling_visible) {
    result.reason = BaitNoticeReason::reeling;
  } else if (changed_bait_visible || gear_visible) {
    result.reason = BaitNoticeReason::begin_recovery;
  }
  return result;
}

std::string_view Key(const TackleKind kind) noexcept {
  switch (kind) {
    case TackleKind::rod:
      return "rod";
    case TackleKind::reel:
      return "reel";
    case TackleKind::line:
      return "line";
    case TackleKind::hook:
      return "hook";
    case TackleKind::bait:
      return "bait";
    case TackleKind::net:
      return "net";
  }
  return {};
}

std::string_view Key(const TerminalAction action) noexcept {
  switch (action) {
    case TerminalAction::stop:
      return "stop";
    case TerminalAction::exit_game:
      return "exit_game";
    case TerminalAction::shutdown_pc:
      return "shutdown_pc";
  }
  return {};
}

std::string_view Key(const BaitNoticeReason reason) noexcept {
  switch (reason) {
    case BaitNoticeReason::disabled:
      return "disabled";
    case BaitNoticeReason::cooldown:
      return "cooldown";
    case BaitNoticeReason::reeling:
      return "reeling";
    case BaitNoticeReason::no_notice:
      return "no_notice";
    case BaitNoticeReason::begin_recovery:
      return "begin_recovery";
  }
  return {};
}

}  // namespace sonar::fishing::equipment_recovery
