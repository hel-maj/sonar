#pragma once

#include <cstdint>
#include <optional>
#include <string_view>
#include <vector>

#include "sonar/fishing/runtime_settings/runtime_settings.h"

namespace sonar::fishing::equipment_recovery {

enum class TackleKind : std::uint8_t {
  rod,
  reel,
  line,
  hook,
  bait,
  net,
};

struct TackleCounts {
  std::uint32_t rod = 0;
  std::uint32_t reel = 0;
  std::uint32_t line = 0;
  std::uint32_t hook = 0;
  std::uint32_t bait = 0;
  std::uint32_t net = 0;

  [[nodiscard]] std::uint32_t count(TackleKind kind) const noexcept;
};

enum class TerminalAction : std::uint8_t {
  stop,
  exit_game,
  shutdown_pc,
};

struct AllowedWarning {
  TackleKind kind;
  std::string_view reason;
};

struct TerminalInstruction {
  TackleKind kind;
  TerminalAction action;
  std::string_view reason;
};

struct TackleEvaluation {
  std::vector<AllowedWarning> warnings;
  std::optional<TerminalInstruction> terminal;
};

// Mirrors current fixed slot priority and allowed-without-item notifications.
// Scan confirmation/CV and terminal side effects stay in the later bounded
// Engine episode rather than crossing Host IPC.
[[nodiscard]] TackleEvaluation EvaluateTackle(
    const TackleCounts& counts,
    const runtime_settings::RuntimeSettingsSnapshot& settings,
    std::optional<bool> session_started_with_net);

enum class BaitNoticeReason : std::uint8_t {
  disabled,
  cooldown,
  reeling,
  no_notice,
  begin_recovery,
};

struct BaitNoticeDecision {
  BaitNoticeReason reason;
  double next_last_change_at;
  bool cooldown_advanced;
};

// Current effective override advances the 3-second cooldown before it checks
// reeling or whether the bait/gear notice is still present.
[[nodiscard]] BaitNoticeDecision EvaluateBaitNotice(
    bool auto_change_bait,
    double now_seconds,
    double last_change_at,
    bool reeling_visible,
    bool changed_bait_visible,
    bool gear_visible);

[[nodiscard]] std::string_view Key(TackleKind kind) noexcept;
[[nodiscard]] std::string_view Key(TerminalAction action) noexcept;
[[nodiscard]] std::string_view Key(BaitNoticeReason reason) noexcept;

}  // namespace sonar::fishing::equipment_recovery
