#include "sonar/fishing/inventory_store/inventory_store_episode.h"

#include <algorithm>
#include <cmath>
#include <exception>
#include <string_view>
#include <unordered_set>
#include <utility>

namespace sonar::fishing::inventory_store {
namespace {

constexpr double kMinimumAcceptedConfidence = 0.90;
constexpr std::size_t kMaximumIdentifierBytes = 96;
constexpr std::size_t kMaximumTitleBytes = 512;
constexpr std::size_t kMaximumErrorBytes = 512;
constexpr std::size_t kMaximumRequestedFish = 128;
constexpr std::size_t kMaximumObservedItems = 256;
constexpr std::size_t kMaximumStoredItems = 128;
constexpr std::size_t kMenuCloseAttempts = 3;
constexpr std::size_t kStageExitAttempts = 4;
constexpr std::size_t kInventoryOpenAttempts = 2;
constexpr std::size_t kInventoryOpenPolls = 3;
constexpr std::size_t kContextOpenAttempts = 2;
constexpr std::size_t kRemovalPolls = 3;
constexpr std::size_t kInventoryCloseAttempts = 2;
constexpr std::size_t kInventoryClosePolls = 3;
constexpr std::size_t kResumePolls = 4;
constexpr std::size_t kMenuSettleMilliseconds = 200;
constexpr std::size_t kStageExitSettleMilliseconds = 2'300;
constexpr std::size_t kInventoryPreOpenMilliseconds = 1'000;
constexpr std::size_t kInventoryToggleSettleMilliseconds = 1'000;
constexpr std::size_t kInventoryRetryMilliseconds = 500;
constexpr std::size_t kObservationPollMilliseconds = 150;
constexpr std::size_t kContextOpenMilliseconds = 300;
constexpr std::size_t kRemoveSettleMilliseconds = 500;
constexpr std::size_t kInventoryCloseFinalMilliseconds = 1'500;
constexpr std::size_t kFishingEntrySettleMilliseconds = 300;

[[nodiscard]] bool bounded_text(
    const std::string_view value,
    const std::size_t maximum,
    const bool allow_empty = false) noexcept {
  return (allow_empty || !value.empty()) && value.size() <= maximum &&
      value.find('\0') == std::string_view::npos;
}

[[nodiscard]] bool valid_identifier(const std::string_view value) noexcept {
  if (!bounded_text(value, kMaximumIdentifierBytes)) {
    return false;
  }
  return std::all_of(
      value.begin(),
      value.end(),
      [](const unsigned char character) {
        return (character >= 'a' && character <= 'z') ||
            (character >= 'A' && character <= 'Z') ||
            (character >= '0' && character <= '9') || character == '_' ||
            character == '-' || character == '.' || character == ':';
      });
}

[[nodiscard]] bool valid_rect(
    const stage_detection::normalized_rect& rect) noexcept {
  return std::isfinite(rect.x) && std::isfinite(rect.y) &&
      std::isfinite(rect.width) && std::isfinite(rect.height) &&
      rect.x >= 0.0 && rect.y >= 0.0 && rect.width > 0.0 &&
      rect.height > 0.0 && rect.x + rect.width <= 1.0 &&
      rect.y + rect.height <= 1.0;
}

[[nodiscard]] bool valid_confidence(const double value) noexcept {
  return std::isfinite(value) && value >= 0.0 && value <= 1.0;
}

[[nodiscard]] bool is_inventory_surface(
    const inventory_surface surface) noexcept {
  return surface == inventory_surface::inventory ||
      surface == inventory_surface::item_context_menu;
}

[[nodiscard]] bool stage_is_active(
    const stage_detection::observed_fishing_stage stage) noexcept {
  return stage != stage_detection::observed_fishing_stage::none;
}

[[nodiscard]] inventory_mutation_intent key_intent(
    const inventory_intent_kind kind,
    const std::uint64_t sequence,
    std::string key,
    const std::size_t packet_count) {
  return {
      .kind = kind,
      .expected_observation_sequence = sequence,
      .key = std::move(key),
      .packet_count = packet_count,
  };
}

[[nodiscard]] inventory_mutation_intent target_intent(
    const inventory_intent_kind kind,
    const std::uint64_t sequence,
    std::string instance_id,
    const stage_detection::normalized_rect bounds) {
  return {
      .kind = kind,
      .expected_observation_sequence = sequence,
      .item_instance_id = std::move(instance_id),
      .target_bounds = bounds,
      .packet_count = 3,
  };
}

[[nodiscard]] inventory_mutation_intent pause_intent(
    const std::uint64_t sequence,
    const std::size_t milliseconds) {
  return {
      .kind = inventory_intent_kind::pause,
      .expected_observation_sequence = sequence,
      .delay_milliseconds = milliseconds,
  };
}

class episode final : public inventory_episode_context {
 public:
  episode(
      const inventory_store_request& request,
      inventory_observer& observer,
      inventory_mutation_port& mutation,
      const std::stop_token stop_token,
      inventory_episode_operation* const operation = nullptr)
      : request_(request),
        observer_(observer),
        mutation_(mutation),
        stop_token_(stop_token),
        operation_(operation) {}

  [[nodiscard]] inventory_store_result run() {
    if (!validate_request()) {
      return fail_current();
    }
    if (!observe()) {
      return fail_current();
    }
    if (last_.catch_screen_visible) {
      return fail("inventory_catch_screen_active");
    }
    if (operation_ != nullptr) {
      const auto preflight = operation_->preflight(last_, stop_token_);
      switch (preflight.disposition) {
        case inventory_operation_preflight_disposition::proceed:
          break;
        case inventory_operation_preflight_disposition::complete:
          return success("inventory_operation_completed");
        case inventory_operation_preflight_disposition::reject:
          return fail(
              preflight.reason.empty()
                  ? "inventory_operation_preflight_rejected"
                  : preflight.reason);
      }
    }
    if (last_.fishing_stage ==
        stage_detection::observed_fishing_stage::reeling) {
      return fail("inventory_reeling_active");
    }
    if (!apply(key_intent(
            inventory_intent_kind::activate_window,
            last_.sequence,
            {},
            1)) ||
        !apply(key_intent(
            inventory_intent_kind::release_all_keys,
            last_.sequence,
            {},
            9))) {
      return fail_current();
    }
    if (request_.open_inventory &&
        (!close_game_menu() || !open_inventory())) {
      return fail_with_recovery();
    }
    if (operation_ != nullptr) {
      if (!operation_->execute(*this, stop_token_)) {
        if (failure_.empty()) {
          failure_ = "inventory_operation_failed";
        }
        return fail_with_recovery();
      }
    } else {
      while (stored_count_ < kMaximumStoredItems) {
        const auto targets = matching_items(last_);
        if (targets.empty()) {
          break;
        }
        if (!store_one(targets.front(), targets.size())) {
          return fail_with_recovery();
        }
      }
      if (!matching_items(last_).empty()) {
        return fail_with_reason_and_recovery("inventory_item_limit_reached");
      }
    }
    if (!close_inventory()) {
      return fail_with_recovery();
    }
    if (request_.resume_fishing && !resume_suppressed_ && !resume_fishing()) {
      return fail_with_recovery();
    }
    return success(
        operation_ == nullptr ? "inventory_store_completed"
                              : "inventory_operation_completed");
  }

  [[nodiscard]] const inventory_observation& current() const noexcept override {
    return last_;
  }

  [[nodiscard]] bool refresh() override { return observe(); }

  [[nodiscard]] bool mutate(inventory_mutation_intent intent) override {
    return apply(std::move(intent));
  }

  [[nodiscard]] bool wait(const std::size_t milliseconds) override {
    return pause(milliseconds);
  }

  [[nodiscard]] bool reject(std::string reason) override {
    failure_ = std::move(reason);
    return false;
  }

  void prevent_resume() noexcept override { resume_suppressed_ = true; }

 private:
  [[nodiscard]] bool validate_request() {
    if (!valid_identifier(request_.inventory_hotkey) ||
        !valid_identifier(request_.fishing_entry_hotkey)) {
      failure_ = "inventory_hotkey_invalid";
      return false;
    }
    if (request_.fish_to_store.size() > kMaximumRequestedFish) {
      failure_ = "inventory_request_too_large";
      return false;
    }
    for (const auto& item_id : request_.fish_to_store) {
      if (!valid_identifier(item_id)) {
        failure_ = "inventory_item_id_invalid";
        return false;
      }
    }
    requested_fish_.reserve(request_.fish_to_store.size());
    requested_fish_.insert(
        request_.fish_to_store.begin(), request_.fish_to_store.end());
    return true;
  }

  [[nodiscard]] bool validate_observation(
      const inventory_observation& observation) {
    if (observation.sequence == 0 ||
        observation.sequence <= last_sequence_) {
      failure_ = "inventory_observation_stale";
      return false;
    }
    if (observation.surface == inventory_surface::unknown) {
      failure_ = "inventory_surface_unknown";
      return false;
    }
    if (observation.items.size() > kMaximumObservedItems) {
      failure_ = "inventory_observation_too_large";
      return false;
    }
    if (!is_inventory_surface(observation.surface) &&
        (!observation.items.empty() || observation.remove_action.has_value())) {
      failure_ = "inventory_surface_content_invalid";
      return false;
    }
    if (is_inventory_surface(observation.surface) &&
        stage_is_active(observation.fishing_stage)) {
      failure_ = "inventory_surface_stage_ambiguous";
      return false;
    }
    if (is_inventory_surface(observation.surface) &&
        observation.catch_screen_visible) {
      failure_ = "inventory_surface_catch_ambiguous";
      return false;
    }
    if (observation.surface == inventory_surface::item_context_menu &&
        !observation.remove_action.has_value()) {
      failure_ = "inventory_context_action_missing";
      return false;
    }
    if (observation.surface != inventory_surface::item_context_menu &&
        observation.remove_action.has_value()) {
      failure_ = "inventory_context_surface_missing";
      return false;
    }

    std::unordered_set<std::string> instance_ids;
    for (const auto& item : observation.items) {
      if (item.compartment != inventory_compartment::player_inventory &&
          item.compartment != inventory_compartment::backpack) {
        failure_ = "inventory_item_compartment_invalid";
        return false;
      }
      if (!valid_identifier(item.instance_id) ||
          !valid_identifier(item.item_id) ||
          !bounded_text(item.title, kMaximumTitleBytes, true) ||
          !valid_confidence(item.confidence) || !valid_rect(item.bounds)) {
        failure_ = "inventory_item_observation_invalid";
        return false;
      }
      if (!instance_ids.insert(item.instance_id).second) {
        failure_ = "inventory_item_instance_duplicate";
        return false;
      }
    }
    if (observation.remove_action.has_value()) {
      const auto& action = *observation.remove_action;
      if (!valid_identifier(action.item_instance_id) ||
          !valid_confidence(action.confidence) || !valid_rect(action.bounds) ||
          instance_ids.find(action.item_instance_id) == instance_ids.end()) {
        failure_ = "inventory_context_action_invalid";
        return false;
      }
    }
    return true;
  }

  [[nodiscard]] bool observe() {
    if (stop_token_.stop_requested()) {
      failure_ = "inventory_cancelled";
      cancelled_ = true;
      return false;
    }
    inventory_observation observation;
    try {
      observation = observer_.observe(stop_token_);
    } catch (const std::exception& error) {
      failure_ = std::string("inventory_observation_failed:") + error.what();
      return false;
    } catch (...) {
      failure_ = "inventory_observation_failed:unknown";
      return false;
    }
    if (!observation.error.empty()) {
      if (!bounded_text(observation.error, kMaximumErrorBytes)) {
        failure_ = "inventory_observation_error_invalid";
        return false;
      }
      failure_ = "inventory_observation_unavailable:" + observation.error;
      return false;
    }
    if (!validate_observation(observation)) {
      return false;
    }
    last_sequence_ = observation.sequence;
    last_ = std::move(observation);
    return true;
  }

  [[nodiscard]] bool apply(inventory_mutation_intent intent) {
    if (stop_token_.stop_requested()) {
      failure_ = "inventory_cancelled";
      cancelled_ = true;
      return false;
    }
    intent.expected_observation_sequence = last_.sequence;
    try {
      const auto result = mutation_.apply(intent, stop_token_);
      if (!result.applied) {
        failure_ = result.reason.empty()
            ? "inventory_mutation_rejected"
            : result.reason;
        mutation_rejected_ = true;
        return false;
      }
    } catch (const std::exception& error) {
      failure_ = std::string("inventory_mutation_failed:") + error.what();
      mutation_rejected_ = true;
      return false;
    } catch (...) {
      failure_ = "inventory_mutation_failed:unknown";
      mutation_rejected_ = true;
      return false;
    }
    return true;
  }

  [[nodiscard]] bool pause(const std::size_t milliseconds) {
    return apply(pause_intent(last_.sequence, milliseconds));
  }

  [[nodiscard]] bool close_game_menu() {
    for (std::size_t attempt = 0;
         last_.surface == inventory_surface::game_menu &&
         attempt < kMenuCloseAttempts;
         ++attempt) {
      if (last_.fishing_stage ==
          stage_detection::observed_fishing_stage::reeling) {
        failure_ = "inventory_reeling_active";
        return false;
      }
      if (last_.catch_screen_visible) {
        failure_ = "inventory_catch_screen_active";
        return false;
      }
      if (!apply(key_intent(
              inventory_intent_kind::press_key,
              last_.sequence,
              "esc",
              2)) ||
          !pause(kMenuSettleMilliseconds) || !observe()) {
        return false;
      }
    }
    if (last_.surface == inventory_surface::game_menu) {
      failure_ = "inventory_game_menu_close_not_confirmed";
      return false;
    }
    return true;
  }

  [[nodiscard]] bool exit_fishing_stage() {
    for (std::size_t attempt = 0;
         stage_is_active(last_.fishing_stage) &&
         attempt < kStageExitAttempts;
         ++attempt) {
      if (last_.fishing_stage ==
          stage_detection::observed_fishing_stage::reeling) {
        failure_ = "inventory_reeling_active";
        return false;
      }
      if (last_.catch_screen_visible) {
        failure_ = "inventory_catch_screen_active";
        return false;
      }
      if (!apply(key_intent(
              inventory_intent_kind::press_key,
              last_.sequence,
              "esc",
              2)) ||
          !pause(kStageExitSettleMilliseconds) || !observe() ||
          !close_game_menu()) {
        return false;
      }
      if (is_inventory_surface(last_.surface)) {
        return true;
      }
    }
    if (stage_is_active(last_.fishing_stage)) {
      failure_ = "inventory_stage_exit_not_confirmed";
      return false;
    }
    return true;
  }

  [[nodiscard]] bool open_inventory() {
    if (is_inventory_surface(last_.surface)) {
      return true;
    }
    if (!close_game_menu() || !exit_fishing_stage()) {
      return false;
    }
    if (is_inventory_surface(last_.surface)) {
      return true;
    }
    if (!pause(kInventoryPreOpenMilliseconds) || !observe() ||
        !close_game_menu() || !exit_fishing_stage()) {
      return false;
    }
    if (is_inventory_surface(last_.surface)) {
      return true;
    }

    for (std::size_t attempt = 0; attempt < kInventoryOpenAttempts; ++attempt) {
      if (last_.surface != inventory_surface::gameplay ||
          last_.catch_screen_visible || stage_is_active(last_.fishing_stage)) {
        failure_ = "inventory_preopen_state_changed";
        return false;
      }
      if (!apply(key_intent(
              inventory_intent_kind::press_key,
              last_.sequence,
              request_.inventory_hotkey,
              2)) ||
          !pause(kInventoryToggleSettleMilliseconds)) {
        return false;
      }
      for (std::size_t poll = 0; poll < kInventoryOpenPolls; ++poll) {
        if (!observe() || !close_game_menu()) {
          return false;
        }
        if (is_inventory_surface(last_.surface)) {
          return true;
        }
        if (last_.catch_screen_visible || stage_is_active(last_.fishing_stage)) {
          failure_ = "inventory_stage_changed_while_opening";
          return false;
        }
        if (poll + 1 < kInventoryOpenPolls &&
            !pause(kObservationPollMilliseconds)) {
          return false;
        }
      }
      if (attempt + 1 < kInventoryOpenAttempts &&
          (!pause(kInventoryRetryMilliseconds) || !observe())) {
        return false;
      }
      if (is_inventory_surface(last_.surface)) {
        return true;
      }
    }
    failure_ = "inventory_open_not_confirmed";
    return false;
  }

  [[nodiscard]] std::vector<inventory_item_observation> matching_items(
      const inventory_observation& observation) const {
    std::vector<inventory_item_observation> result;
    for (const auto& item : observation.items) {
      if (item.confidence < kMinimumAcceptedConfidence ||
          item.compartment != inventory_compartment::player_inventory ||
          requested_fish_.find(item.item_id) == requested_fish_.end()) {
        continue;
      }
      result.push_back(item);
    }
    std::sort(
        result.begin(),
        result.end(),
        [](const auto& left, const auto& right) {
          if (left.bounds.y != right.bounds.y) {
            return left.bounds.y < right.bounds.y;
          }
          if (left.bounds.x != right.bounds.x) {
            return left.bounds.x < right.bounds.x;
          }
          return left.instance_id < right.instance_id;
        });
    return result;
  }

  [[nodiscard]] const inventory_item_observation* find_instance(
      const std::string_view instance_id) const {
    const auto found = std::find_if(
        last_.items.begin(),
        last_.items.end(),
        [instance_id](const auto& item) {
          return item.instance_id == instance_id;
        });
    return found == last_.items.end() ? nullptr : &*found;
  }

  [[nodiscard]] bool store_one(
      const inventory_item_observation& initial_target,
      const std::size_t before_count) {
    for (std::size_t attempt = 0; attempt < kContextOpenAttempts; ++attempt) {
      if (last_.surface != inventory_surface::inventory) {
        failure_ = "inventory_surface_lost_before_item";
        return false;
      }
      const auto* target = find_instance(initial_target.instance_id);
      if (target == nullptr || target->item_id != initial_target.item_id) {
        failure_ = "inventory_item_reflowed_before_action";
        return false;
      }
      if (!apply(target_intent(
              inventory_intent_kind::right_click_item,
              last_.sequence,
              target->instance_id,
              target->bounds)) ||
          !pause(kContextOpenMilliseconds) || !observe()) {
        return false;
      }
      if (last_.surface == inventory_surface::item_context_menu &&
          last_.remove_action.has_value()) {
        if (last_.remove_action->item_instance_id !=
            initial_target.instance_id) {
          failure_ = "inventory_context_target_changed";
          return false;
        }
        if (last_.remove_action->confidence < kMinimumAcceptedConfidence) {
          failure_ = "inventory_context_confidence_low";
          return false;
        }
        return apply_remove(initial_target, before_count);
      }
      if (matching_items(last_).size() < before_count) {
        failure_ = "inventory_item_changed_without_confirmation";
        return false;
      }
      if (last_.surface != inventory_surface::inventory) {
        failure_ = "inventory_context_surface_invalid";
        return false;
      }
    }
    failure_ = "inventory_context_not_confirmed";
    return false;
  }

  [[nodiscard]] bool apply_remove(
      const inventory_item_observation& target,
      const std::size_t before_count) {
    const auto action = *last_.remove_action;
    if (!apply(target_intent(
            inventory_intent_kind::click_context_action,
            last_.sequence,
            target.instance_id,
            action.bounds)) ||
        !pause(kRemoveSettleMilliseconds)) {
      return false;
    }
    for (std::size_t poll = 0; poll < kRemovalPolls; ++poll) {
      if (!observe()) {
        return false;
      }
      if (last_.surface == inventory_surface::inventory &&
          matching_items(last_).size() < before_count) {
        if (find_instance(target.instance_id) != nullptr) {
          failure_ = "inventory_target_removal_not_confirmed";
          return false;
        }
        ++stored_count_;
        return true;
      }
      if (!is_inventory_surface(last_.surface)) {
        failure_ = "inventory_surface_lost_after_remove";
        return false;
      }
      if (last_.surface == inventory_surface::item_context_menu &&
          last_.remove_action.has_value() &&
          last_.remove_action->item_instance_id != target.instance_id) {
        failure_ = "inventory_context_target_changed";
        return false;
      }
      if (poll + 1 < kRemovalPolls &&
          !pause(kObservationPollMilliseconds)) {
        return false;
      }
    }
    failure_ = "inventory_removal_not_confirmed";
    return false;
  }

  [[nodiscard]] bool close_context_menu() {
    if (last_.surface != inventory_surface::item_context_menu) {
      return true;
    }
    if (!apply(key_intent(
            inventory_intent_kind::press_key,
            last_.sequence,
            "esc",
            2)) ||
        !pause(kMenuSettleMilliseconds) || !observe()) {
      return false;
    }
    if (last_.surface == inventory_surface::item_context_menu) {
      failure_ = "inventory_context_close_not_confirmed";
      return false;
    }
    return true;
  }

  [[nodiscard]] bool close_inventory() {
    if (!close_context_menu()) {
      return false;
    }
    if (!is_inventory_surface(last_.surface)) {
      return true;
    }
    for (std::size_t attempt = 0;
         is_inventory_surface(last_.surface) &&
         attempt < kInventoryCloseAttempts;
         ++attempt) {
      if (!apply(key_intent(
              inventory_intent_kind::press_key,
              last_.sequence,
              request_.inventory_hotkey,
              2)) ||
          !pause(kInventoryToggleSettleMilliseconds)) {
        return false;
      }
      for (std::size_t poll = 0; poll < kInventoryClosePolls; ++poll) {
        if (!observe()) {
          return false;
        }
        if (!is_inventory_surface(last_.surface)) {
          if (last_.catch_screen_visible ||
              stage_is_active(last_.fishing_stage)) {
            failure_ = "inventory_state_changed_while_closing";
            return false;
          }
          if (last_.surface == inventory_surface::game_menu &&
              !close_game_menu()) {
            return false;
          }
          if (last_.surface == inventory_surface::gameplay) {
            if (!pause(kInventoryCloseFinalMilliseconds) || !observe()) {
              return false;
            }
          }
          return !is_inventory_surface(last_.surface);
        }
        if (poll + 1 < kInventoryClosePolls &&
            !pause(kObservationPollMilliseconds)) {
          return false;
        }
      }
    }
    failure_ = "inventory_close_not_confirmed";
    return false;
  }

  [[nodiscard]] bool resume_fishing() {
    if (last_.catch_screen_visible ||
        last_.surface != inventory_surface::gameplay) {
      failure_ = "fishing_resume_state_invalid";
      return false;
    }
    if (stage_is_active(last_.fishing_stage)) {
      return true;
    }
    if (!apply(key_intent(
            inventory_intent_kind::press_key,
            last_.sequence,
            request_.fishing_entry_hotkey,
            2)) ||
        !pause(kFishingEntrySettleMilliseconds)) {
      return false;
    }
    for (std::size_t poll = 0; poll < kResumePolls; ++poll) {
      if (!observe()) {
        return false;
      }
      if (last_.surface == inventory_surface::gameplay &&
          stage_is_active(last_.fishing_stage) &&
          !last_.catch_screen_visible) {
        return true;
      }
      if (last_.surface != inventory_surface::gameplay ||
          last_.catch_screen_visible) {
        failure_ = "fishing_resume_state_invalid";
        return false;
      }
      if (poll + 1 < kResumePolls &&
          !pause(kObservationPollMilliseconds)) {
        return false;
      }
    }
    failure_ = "fishing_resume_not_confirmed";
    return false;
  }

  void attempt_recovery() {
    if (mutation_rejected_ || cancelled_) {
      return;
    }
    recovery_attempted_ = true;
    if (!apply(key_intent(
            inventory_intent_kind::release_all_keys,
            last_.sequence,
            {},
            9))) {
      return;
    }
    if (!is_inventory_surface(last_.surface)) {
      recovery_completed_ = true;
      return;
    }
    if (last_.surface == inventory_surface::item_context_menu) {
      if (!close_context_menu()) {
        return;
      }
    }
    for (std::size_t attempt = 0;
         is_inventory_surface(last_.surface) &&
         attempt < kInventoryCloseAttempts;
         ++attempt) {
      if (!apply(key_intent(
              inventory_intent_kind::press_key,
              last_.sequence,
              request_.inventory_hotkey,
              2)) ||
          !pause(kInventoryToggleSettleMilliseconds) || !observe()) {
        return;
      }
    }
    recovery_completed_ = !is_inventory_surface(last_.surface);
  }

  [[nodiscard]] inventory_store_result success(std::string reason) const {
    return {
        .ok = true,
        .reason = std::move(reason),
        .stored_count = stored_count_,
        .recovery_attempted = recovery_attempted_,
        .recovery_completed = recovery_completed_,
        .observation = last_,
    };
  }

  [[nodiscard]] inventory_store_result fail(std::string reason) const {
    return {
        .ok = false,
        .reason = std::move(reason),
        .stored_count = stored_count_,
        .recovery_attempted = recovery_attempted_,
        .recovery_completed = recovery_completed_,
        .observation = last_,
    };
  }

  [[nodiscard]] inventory_store_result fail_current() const {
    return fail(failure_.empty() ? "inventory_episode_failed" : failure_);
  }

  [[nodiscard]] inventory_store_result fail_with_recovery() {
    const std::string reason = failure_.empty()
        ? "inventory_episode_failed"
        : failure_;
    attempt_recovery();
    return fail(reason);
  }

  [[nodiscard]] inventory_store_result fail_with_reason_and_recovery(
      std::string reason) {
    failure_ = reason;
    return fail_with_recovery();
  }

  const inventory_store_request& request_;
  inventory_observer& observer_;
  inventory_mutation_port& mutation_;
  std::stop_token stop_token_;
  inventory_episode_operation* operation_{};
  std::unordered_set<std::string> requested_fish_;
  inventory_observation last_;
  std::uint64_t last_sequence_{};
  std::size_t stored_count_{};
  bool recovery_attempted_{};
  bool recovery_completed_{};
  bool mutation_rejected_{};
  bool cancelled_{};
  bool resume_suppressed_{};
  std::string failure_;
};

}  // namespace

inventory_mutation_result inventory_mutation_result::accepted() {
  return {.applied = true};
}

inventory_mutation_result inventory_mutation_result::rejected(
    std::string reason) {
  return {.applied = false, .reason = std::move(reason)};
}

inventory_store_result inventory_store_episode_runner::run(
    const inventory_store_request& request,
    inventory_observer& observer,
    inventory_mutation_port& mutation,
    const std::stop_token stop_token) const {
  return episode(request, observer, mutation, stop_token).run();
}

inventory_store_result inventory_store_episode_runner::run_operation(
    const inventory_store_request& request,
    inventory_episode_operation& operation,
    inventory_observer& observer,
    inventory_mutation_port& mutation,
    const std::stop_token stop_token) const {
  return episode(request, observer, mutation, stop_token, &operation).run();
}

inventory_operation_preflight_result inventory_episode_operation::preflight(
    const inventory_observation& observation,
    const std::stop_token stop_token) {
  static_cast<void>(observation);
  static_cast<void>(stop_token);
  return {};
}

inventory_mutation_result disabled_inventory_mutation_port::apply(
    const inventory_mutation_intent& intent,
    const std::stop_token stop_token) {
  static_cast<void>(intent);
  static_cast<void>(stop_token);
  return inventory_mutation_result::rejected(
      "inventory_live_adapter_disabled");
}

const char* inventory_intent_key(const inventory_intent_kind kind) noexcept {
  switch (kind) {
    case inventory_intent_kind::activate_window:
      return "activate";
    case inventory_intent_kind::release_all_keys:
      return "release_all";
    case inventory_intent_kind::press_key:
      return "press_key";
    case inventory_intent_kind::right_click_item:
      return "right_click";
    case inventory_intent_kind::click_context_action:
      return "click_context";
    case inventory_intent_kind::pause:
      return "pause";
    case inventory_intent_kind::use_inventory_item:
      return "use_item";
    case inventory_intent_kind::move_backpack_item:
      return "move_backpack";
    case inventory_intent_kind::discard_inventory_item:
      return "discard_item";
    case inventory_intent_kind::stop_automation:
      return "stop_automation";
    case inventory_intent_kind::exit_game:
      return "exit_game";
    case inventory_intent_kind::shutdown_pc:
      return "shutdown_pc";
  }
  return "unknown";
}

}  // namespace sonar::fishing::inventory_store
