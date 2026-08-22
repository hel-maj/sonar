#include "sonar/fishing/maintenance_episode/maintenance_episode.h"

#include <cmath>
#include <optional>
#include <string_view>
#include <utility>

#include "maintenance_operation.h"

namespace sonar::fishing::maintenance_episode {
namespace detail {
namespace {

[[nodiscard]] bool same_rect(
    const stage_detection::normalized_rect& left,
    const stage_detection::normalized_rect& right) noexcept {
  return left.x == right.x && left.y == right.y &&
      left.width == right.width && left.height == right.height;
}

[[nodiscard]] bool same_item(
    const inventory_store::inventory_item_observation& left,
    const inventory_store::inventory_item_observation& right) noexcept {
  return left.instance_id == right.instance_id &&
      left.item_id == right.item_id && left.title == right.title &&
      left.compartment == right.compartment &&
      left.confidence == right.confidence && same_rect(left.bounds, right.bounds);
}

[[nodiscard]] bool same_context_action(
    const std::optional<inventory_store::inventory_context_action_observation>&
        left,
    const std::optional<inventory_store::inventory_context_action_observation>&
        right) noexcept {
  if (left.has_value() != right.has_value()) {
    return false;
  }
  return !left.has_value() ||
      (left->item_instance_id == right->item_instance_id &&
       left->confidence == right->confidence &&
       same_rect(left->bounds, right->bounds));
}

[[nodiscard]] bool same_inventory_observation(
    const inventory_store::inventory_observation& left,
    const inventory_store::inventory_observation& right) noexcept {
  if (left.sequence != right.sequence || left.surface != right.surface ||
      left.fishing_stage != right.fishing_stage ||
      left.catch_screen_visible != right.catch_screen_visible ||
      left.error != right.error || left.items.size() != right.items.size() ||
      !same_context_action(left.remove_action, right.remove_action)) {
    return false;
  }
  for (std::size_t index = 0; index < left.items.size(); ++index) {
    if (!same_item(left.items[index], right.items[index])) {
      return false;
    }
  }
  return true;
}

}  // namespace

operation::operation(
    const maintenance_request& request,
    maintenance_observer& observer) noexcept
    : request_(request),
      observer_(observer),
      next_bait_change_at_seconds_(request.last_bait_change_at_seconds) {}

inventory_store::inventory_operation_preflight_result operation::preflight(
    const inventory_store::inventory_observation& observation,
    const std::stop_token stop_token) {
  using disposition =
      inventory_store::inventory_operation_preflight_disposition;
  if (stop_token.stop_requested()) {
    return {.disposition = disposition::reject,
            .reason = "maintenance_cancelled"};
  }
  if (!same_inventory_observation(
          observer_.current_maintenance().inventory, observation)) {
    return {.disposition = disposition::reject,
            .reason = "maintenance_observation_not_coherent"};
  }
  if (request_.kind != episode_kind::bait_recovery) {
    if (request_.kind == episode_kind::tackle_check &&
        observer_.current_maintenance().inventory.surface !=
            inventory_store::inventory_surface::gameplay) {
      return {.disposition = disposition::reject,
              .reason = "tackle_surface_invalid"};
    }
    return {};
  }
  const auto& current = observer_.current_maintenance();
  if (current.inventory.surface !=
      inventory_store::inventory_surface::gameplay) {
    return {.disposition = disposition::reject,
            .reason = "bait_surface_invalid"};
  }
  const bool reeling =
      current.inventory.fishing_stage ==
          stage_detection::observed_fishing_stage::reeling ||
      (current.reeling.has_value() && current.reeling->active);
  const auto decision = equipment_recovery::EvaluateBaitNotice(
      request_.settings.auto_change_bait,
      request_.now_seconds,
      request_.last_bait_change_at_seconds,
      reeling,
      current.changed_bait_visible,
      current.gear_visible);
  next_bait_change_at_seconds_ = decision.next_last_change_at;
  bait_cooldown_advanced_ = decision.cooldown_advanced;
  if (decision.reason == equipment_recovery::BaitNoticeReason::begin_recovery) {
    bait_recovery_admitted_ = true;
    return {};
  }
  completion_reason_ =
      std::string("bait_") + std::string(equipment_recovery::Key(decision.reason));
  return {.disposition = disposition::complete};
}

bool operation::execute(
    inventory_store::inventory_episode_context& context,
    const std::stop_token stop_token) {
  switch (request_.kind) {
    case episode_kind::meal_recovery:
      return execute_meal(context, stop_token);
    case episode_kind::garbage_disposal:
      return execute_garbage(context, stop_token);
    case episode_kind::tackle_check:
      return execute_tackle(context, stop_token);
    case episode_kind::bait_recovery:
      return execute_bait(context, stop_token);
  }
  return context.reject("maintenance_kind_invalid");
}

const maintenance_observation* operation::coherent(
    inventory_store::inventory_episode_context& context) {
  const auto& value = observer_.current_maintenance();
  if (!same_inventory_observation(value.inventory, context.current())) {
    static_cast<void>(
        context.reject("maintenance_observation_not_coherent"));
    return nullptr;
  }
  return &value;
}

const std::string& operation::completion_reason() const noexcept {
  return completion_reason_;
}

std::size_t operation::affected_count() const noexcept {
  return affected_count_;
}

std::size_t operation::backpack_move_count() const noexcept {
  return backpack_move_count_;
}

bool operation::meal_search_disabled() const noexcept {
  return meal_search_disabled_;
}

double operation::next_bait_change_at_seconds() const noexcept {
  return next_bait_change_at_seconds_;
}

bool operation::bait_cooldown_advanced() const noexcept {
  return bait_cooldown_advanced_;
}

terminal_outcome operation::terminal() const noexcept { return terminal_; }

const std::vector<equipment_recovery::TackleKind>& operation::warnings()
    const noexcept {
  return warnings_;
}

inventory_store::inventory_mutation_intent item_intent(
    const inventory_store::inventory_intent_kind kind,
    const inventory_store::inventory_item_observation& item,
    std::string key,
    const std::size_t packet_count) {
  return {
      .kind = kind,
      .key = std::move(key),
      .item_instance_id = item.instance_id,
      .target_bounds = item.bounds,
      .packet_count = packet_count,
  };
}

bool stop_requested(
    inventory_store::inventory_episode_context& context,
    const std::stop_token stop_token) {
  if (!stop_token.stop_requested()) {
    return false;
  }
  static_cast<void>(context.reject("maintenance_cancelled"));
  return true;
}

bool operation::emit_terminal(
    inventory_store::inventory_episode_context& context,
    const terminal_outcome outcome) {
  inventory_store::inventory_intent_kind intent_kind =
      inventory_store::inventory_intent_kind::stop_automation;
  switch (outcome) {
    case terminal_outcome::stop:
      intent_kind = inventory_store::inventory_intent_kind::stop_automation;
      break;
    case terminal_outcome::exit_game:
      intent_kind = inventory_store::inventory_intent_kind::exit_game;
      break;
    case terminal_outcome::shutdown_pc:
      intent_kind = inventory_store::inventory_intent_kind::shutdown_pc;
      break;
    case terminal_outcome::none:
      return context.reject("maintenance_terminal_invalid");
  }
  context.prevent_resume();
  if (!context.mutate({.kind = intent_kind})) {
    return false;
  }
  terminal_ = outcome;
  return true;
}

}  // namespace detail

maintenance_result maintenance_episode_runner::run(
    const maintenance_request& request,
    maintenance_observer& observer,
    inventory_store::inventory_mutation_port& mutation,
    const std::stop_token stop_token) const {
  maintenance_result result{.kind = request.kind};
  const std::string_view settings_error =
      runtime_settings::Validate(request.settings);
  if (!settings_error.empty()) {
    result.reason = std::string(settings_error);
    return result;
  }
  if (!std::isfinite(request.now_seconds) ||
      !std::isfinite(request.last_bait_change_at_seconds) ||
      request.now_seconds < 0.0 || request.last_bait_change_at_seconds < 0.0) {
    result.reason = "maintenance_time_invalid";
    return result;
  }
  switch (request.kind) {
    case episode_kind::meal_recovery:
    case episode_kind::garbage_disposal:
    case episode_kind::tackle_check:
    case episode_kind::bait_recovery:
      break;
    default:
      result.reason = "maintenance_kind_invalid";
      return result;
  }

  detail::operation operation(request, observer);
  const bool uses_inventory =
      request.kind == episode_kind::meal_recovery ||
      request.kind == episode_kind::garbage_disposal;
  const inventory_store::inventory_store_request session_request{
      .inventory_hotkey = request.settings.inventory_hotkey,
      .fishing_entry_hotkey = "e",
      .fish_to_store = {},
      .open_inventory = uses_inventory,
      .resume_fishing = uses_inventory && request.resume_fishing,
  };
  const auto session = inventory_store::inventory_store_episode_runner{}
                           .run_operation(
                               session_request,
                               operation,
                               observer,
                               mutation,
                               stop_token);
  result.ok = session.ok;
  result.reason = session.ok ? operation.completion_reason() : session.reason;
  result.affected_count = operation.affected_count();
  result.backpack_move_count = operation.backpack_move_count();
  result.meal_search_disabled_until_restart =
      operation.meal_search_disabled();
  result.next_bait_change_at_seconds =
      operation.next_bait_change_at_seconds();
  result.bait_cooldown_advanced = operation.bait_cooldown_advanced();
  result.terminal = operation.terminal();
  result.warnings = operation.warnings();
  result.recovery_attempted = session.recovery_attempted;
  result.recovery_completed = session.recovery_completed;
  result.observation = session.observation;
  return result;
}

const char* key(const episode_kind value) noexcept {
  switch (value) {
    case episode_kind::meal_recovery:
      return "meal";
    case episode_kind::garbage_disposal:
      return "garbage";
    case episode_kind::tackle_check:
      return "tackle";
    case episode_kind::bait_recovery:
      return "bait";
  }
  return "unknown";
}

const char* key(const terminal_outcome value) noexcept {
  switch (value) {
    case terminal_outcome::none:
      return "none";
    case terminal_outcome::stop:
      return "stop";
    case terminal_outcome::exit_game:
      return "exit_game";
    case terminal_outcome::shutdown_pc:
      return "shutdown_pc";
  }
  return "unknown";
}

}  // namespace sonar::fishing::maintenance_episode
