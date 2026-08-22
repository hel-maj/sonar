#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

namespace sonar::fishing::lifecycle {

enum class Phase : std::uint8_t {
  idle = 0,
  casting = 1,
  hooking = 2,
  reeling = 3,
  catch_resolution = 4,
  inventory = 5,
  recovery = 6,
  stopping = 7,
};

enum class ObservedStage : std::uint8_t {
  free = 0,
  tackle_selection = 1,
  casting = 2,
  waiting_for_bite = 3,
  reeling = 4,
  caught_fish = 5,
  chat = 6,
};

enum class Episode : std::uint8_t {
  none = 0,
  prepare_cast = 1,
  cast = 2,
  hook = 3,
  reel = 4,
  resolve_catch = 5,
  scan_player_status = 6,
  recover_meal = 7,
  recover_bait = 8,
  handle_inventory = 9,
  prepare_chat = 10,
  stop_cleanup = 11,
};

enum class EventKind : std::uint8_t {
  start_requested = 0,
  stage_free = 1,
  stage_tackle_selection = 2,
  stage_casting = 3,
  stage_waiting_for_bite = 4,
  stage_reeling = 5,
  catch_visible = 6,
  catch_resolved = 7,
  player_status_scan_requested = 8,
  player_status_scan_completed = 9,
  meal_needed = 10,
  meal_completed = 11,
  bait_depleted = 12,
  bait_recovery_completed = 13,
  inventory_required = 14,
  inventory_completed = 15,
  chat_pause_requested = 16,
  chat_resume_requested = 17,
  stop_requested = 18,
  stop_completed = 19,
  episode_failed = 20,
};

struct Event {
  EventKind kind;
  std::uint64_t accepted_settings_revision = 0;
  bool entitlement_valid = false;
  bool game_ready = false;
  std::string_view reason;
};

struct Snapshot {
  std::uint64_t revision = 0;
  std::uint64_t accepted_settings_revision = 0;
  bool running = false;
  bool stopping = false;
  bool player_status_scan_pending = false;
  bool paused_for_chat = false;
  Phase phase = Phase::idle;
  ObservedStage stage = ObservedStage::free;
  Episode requested_episode = Episode::none;
  std::optional<std::string> last_error;
};

struct TransitionResult {
  bool accepted;
  std::string reason;
  Snapshot snapshot;
};

// Pure state-machine owner. The Engine composition executes only the returned
// whole Episode and feeds its terminal observation back as a new Event.
class FishingLifecycle final {
 public:
  [[nodiscard]] TransitionResult Apply(const Event& event);
  [[nodiscard]] Snapshot Current() const;

 private:
  [[nodiscard]] TransitionResult Reject(std::string_view reason) const;
  [[nodiscard]] TransitionResult Accept();
  void SetStage(ObservedStage stage, Phase phase, Episode episode) noexcept;

  Snapshot state_;
};

[[nodiscard]] std::string_view PhaseKey(Phase phase) noexcept;
[[nodiscard]] std::string_view StageKey(ObservedStage stage) noexcept;
[[nodiscard]] std::string_view EpisodeKey(Episode episode) noexcept;

}  // namespace sonar::fishing::lifecycle
