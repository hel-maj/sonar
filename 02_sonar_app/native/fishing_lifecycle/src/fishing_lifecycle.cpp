#include "sonar/fishing/lifecycle/fishing_lifecycle.h"

#include <utility>

namespace sonar::fishing::lifecycle {

TransitionResult FishingLifecycle::Apply(const Event& event) {
  if (event.kind == EventKind::start_requested) {
    if (state_.running) {
      return Reject("session_already_running");
    }
    if (state_.stopping) {
      return Reject("session_still_stopping");
    }
    if (event.accepted_settings_revision == 0) {
      return Reject("runtime_settings_missing");
    }
    if (!event.entitlement_valid) {
      return Reject("entitlement_invalid");
    }
    if (!event.game_ready) {
      return Reject("game_not_ready");
    }
    state_.running = true;
    state_.accepted_settings_revision = event.accepted_settings_revision;
    state_.last_error.reset();
    SetStage(ObservedStage::free, Phase::idle, Episode::prepare_cast);
    return Accept();
  }

  if (event.kind == EventKind::stop_completed) {
    if (!state_.stopping) {
      return Reject("stop_not_pending");
    }
    const auto accepted_settings_revision = state_.accepted_settings_revision;
    const auto next_revision = state_.revision + 1;
    state_ = Snapshot{};
    state_.accepted_settings_revision = accepted_settings_revision;
    state_.revision = next_revision;
    return TransitionResult{true, "stop_completed", state_};
  }

  if (!state_.running) {
    return Reject("session_not_running");
  }
  if (state_.stopping && event.kind != EventKind::stop_requested) {
    return Reject("session_stopping");
  }

  switch (event.kind) {
    case EventKind::stage_free:
      SetStage(ObservedStage::free, Phase::idle, Episode::prepare_cast);
      break;
    case EventKind::stage_tackle_selection:
      SetStage(
          ObservedStage::tackle_selection,
          Phase::casting,
          Episode::prepare_cast);
      break;
    case EventKind::stage_casting:
      SetStage(ObservedStage::casting, Phase::casting, Episode::cast);
      break;
    case EventKind::stage_waiting_for_bite:
      SetStage(
          ObservedStage::waiting_for_bite,
          Phase::hooking,
          Episode::hook);
      break;
    case EventKind::stage_reeling:
      SetStage(ObservedStage::reeling, Phase::reeling, Episode::reel);
      break;
    case EventKind::catch_visible:
      SetStage(
          ObservedStage::caught_fish,
          Phase::catch_resolution,
          Episode::resolve_catch);
      break;
    case EventKind::catch_resolved:
      SetStage(ObservedStage::free, Phase::idle, Episode::prepare_cast);
      break;
    case EventKind::player_status_scan_requested:
      state_.player_status_scan_pending = true;
      if (state_.phase != Phase::reeling) {
        state_.phase = Phase::inventory;
        state_.requested_episode = Episode::scan_player_status;
      } else {
        state_.requested_episode = Episode::reel;
      }
      break;
    case EventKind::player_status_scan_completed:
      if (!state_.player_status_scan_pending) {
        return Reject("player_status_scan_not_pending");
      }
      state_.player_status_scan_pending = false;
      SetStage(ObservedStage::free, Phase::idle, Episode::prepare_cast);
      break;
    case EventKind::meal_needed:
      if (state_.phase == Phase::reeling) {
        return Reject("meal_deferred_during_reeling");
      }
      state_.phase = Phase::recovery;
      state_.requested_episode = Episode::recover_meal;
      break;
    case EventKind::meal_completed:
      if (state_.phase != Phase::recovery ||
          state_.requested_episode != Episode::recover_meal) {
        return Reject("meal_not_pending");
      }
      SetStage(ObservedStage::free, Phase::idle, Episode::prepare_cast);
      break;
    case EventKind::bait_depleted:
      if (state_.phase == Phase::reeling) {
        return Reject("bait_change_deferred_during_reeling");
      }
      state_.phase = Phase::recovery;
      state_.requested_episode = Episode::recover_bait;
      break;
    case EventKind::bait_recovery_completed:
      if (state_.phase != Phase::recovery ||
          state_.requested_episode != Episode::recover_bait) {
        return Reject("bait_recovery_not_pending");
      }
      SetStage(ObservedStage::free, Phase::idle, Episode::prepare_cast);
      break;
    case EventKind::inventory_required:
      if (state_.phase == Phase::reeling) {
        return Reject("inventory_deferred_during_reeling");
      }
      state_.phase = Phase::inventory;
      state_.requested_episode = Episode::handle_inventory;
      break;
    case EventKind::inventory_completed:
      if (state_.phase != Phase::inventory) {
        return Reject("inventory_not_pending");
      }
      SetStage(ObservedStage::free, Phase::idle, Episode::prepare_cast);
      break;
    case EventKind::chat_pause_requested:
      state_.paused_for_chat = true;
      SetStage(ObservedStage::chat, Phase::idle, Episode::prepare_chat);
      break;
    case EventKind::chat_resume_requested:
      if (!state_.paused_for_chat) {
        return Reject("chat_pause_not_active");
      }
      state_.paused_for_chat = false;
      SetStage(ObservedStage::free, Phase::idle, Episode::prepare_cast);
      break;
    case EventKind::stop_requested:
      state_.stopping = true;
      state_.phase = Phase::stopping;
      state_.requested_episode = Episode::stop_cleanup;
      break;
    case EventKind::episode_failed:
      state_.last_error = event.reason.empty()
          ? std::optional<std::string>("episode_failed")
          : std::optional<std::string>(event.reason);
      state_.stopping = true;
      state_.phase = Phase::stopping;
      state_.requested_episode = Episode::stop_cleanup;
      break;
    case EventKind::start_requested:
    case EventKind::stop_completed:
      return Reject("event_invalid_in_running_state");
  }
  return Accept();
}

Snapshot FishingLifecycle::Current() const {
  return state_;
}

TransitionResult FishingLifecycle::Reject(const std::string_view reason) const {
  return TransitionResult{false, std::string(reason), state_};
}

TransitionResult FishingLifecycle::Accept() {
  ++state_.revision;
  return TransitionResult{true, "accepted", state_};
}

void FishingLifecycle::SetStage(
    const ObservedStage stage,
    const Phase phase,
    const Episode episode) noexcept {
  state_.stage = stage;
  state_.phase = phase;
  state_.requested_episode = episode;
}

std::string_view PhaseKey(const Phase phase) noexcept {
  switch (phase) {
    case Phase::idle: return "idle";
    case Phase::casting: return "casting";
    case Phase::hooking: return "hooking";
    case Phase::reeling: return "reeling";
    case Phase::catch_resolution: return "catch";
    case Phase::inventory: return "inventory";
    case Phase::recovery: return "recovery";
    case Phase::stopping: return "stopping";
  }
  return "unknown";
}

std::string_view StageKey(const ObservedStage stage) noexcept {
  switch (stage) {
    case ObservedStage::free: return "free";
    case ObservedStage::tackle_selection: return "start";
    case ObservedStage::casting: return "start1";
    case ObservedStage::waiting_for_bite: return "start2";
    case ObservedStage::reeling: return "ad";
    case ObservedStage::caught_fish: return "catch";
    case ObservedStage::chat: return "chat";
  }
  return "unknown";
}

std::string_view EpisodeKey(const Episode episode) noexcept {
  switch (episode) {
    case Episode::none: return "none";
    case Episode::prepare_cast: return "prepare_cast";
    case Episode::cast: return "cast";
    case Episode::hook: return "hook";
    case Episode::reel: return "reel";
    case Episode::resolve_catch: return "resolve_catch";
    case Episode::scan_player_status: return "scan_player_status";
    case Episode::recover_meal: return "recover_meal";
    case Episode::recover_bait: return "recover_bait";
    case Episode::handle_inventory: return "handle_inventory";
    case Episode::prepare_chat: return "prepare_chat";
    case Episode::stop_cleanup: return "stop_cleanup";
  }
  return "unknown";
}

}  // namespace sonar::fishing::lifecycle
