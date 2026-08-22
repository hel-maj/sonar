#include "maintenance_operation.h"

#include <algorithm>
#include <array>
#include <optional>
#include <string_view>

#include "sonar/fishing/meal_recovery/meal_recovery.h"

namespace sonar::fishing::maintenance_episode::detail {
namespace {

constexpr double kMinimumItemConfidence = 0.90;
constexpr std::size_t kMaximumConsumes = 10;
constexpr std::size_t kMaximumBackpackMoves = 5;
constexpr std::size_t kClosePolls = 3;
constexpr std::size_t kHudPolls = 4;
constexpr std::size_t kInventoryToggleMilliseconds = 1'000;
constexpr std::size_t kInventoryCloseFinalMilliseconds = 1'500;
constexpr std::size_t kObservationPollMilliseconds = 150;
constexpr std::size_t kBackpackMoveMilliseconds = 1'000;
constexpr std::size_t kMealAnimationMilliseconds = 6'000;
constexpr std::size_t kHudPollMilliseconds = 500;

[[nodiscard]] bool is_food_id(const std::string_view value) noexcept {
  return value == "irp" || value == "donut" || value == "cocktail";
}

[[nodiscard]] const inventory_store::inventory_item_observation* find_instance(
    const inventory_store::inventory_observation& observation,
    const std::string_view instance_id) {
  const auto found = std::find_if(
      observation.items.begin(),
      observation.items.end(),
      [instance_id](const auto& item) {
        return item.instance_id == instance_id;
      });
  return found == observation.items.end() ? nullptr : &*found;
}

[[nodiscard]] const inventory_store::inventory_item_observation* find_food(
    const inventory_store::inventory_observation& observation,
    const inventory_store::inventory_compartment compartment) {
  constexpr std::array<std::string_view, 3> priority{
      "irp", "donut", "cocktail"};
  for (const auto item_id : priority) {
    const inventory_store::inventory_item_observation* best = nullptr;
    for (const auto& item : observation.items) {
      if (item.item_id != item_id || item.compartment != compartment ||
          item.confidence < kMinimumItemConfidence) {
        continue;
      }
      if (best == nullptr || item.bounds.y < best->bounds.y ||
          (item.bounds.y == best->bounds.y && item.bounds.x < best->bounds.x) ||
          (item.bounds.y == best->bounds.y && item.bounds.x == best->bounds.x &&
           item.instance_id < best->instance_id)) {
        best = &item;
      }
    }
    if (best != nullptr) {
      return best;
    }
  }
  return nullptr;
}

[[nodiscard]] std::size_t food_count(
    const inventory_store::inventory_observation& observation,
    const inventory_store::inventory_compartment compartment) {
  return static_cast<std::size_t>(std::count_if(
      observation.items.begin(),
      observation.items.end(),
      [compartment](const auto& item) {
        return item.compartment == compartment && is_food_id(item.item_id) &&
            item.confidence >= kMinimumItemConfidence;
      }));
}

[[nodiscard]] std::size_t item_count(
    const inventory_store::inventory_observation& observation,
    const inventory_store::inventory_compartment compartment,
    const std::string_view item_id) {
  return static_cast<std::size_t>(std::count_if(
      observation.items.begin(),
      observation.items.end(),
      [compartment, item_id](const auto& item) {
        return item.compartment == compartment && item.item_id == item_id &&
            item.confidence >= kMinimumItemConfidence;
      }));
}

[[nodiscard]] std::optional<bool> meal_need(
    const maintenance_observation& observation,
    const maintenance_request& request) {
  if (observation.player_status.has_value() &&
      observation.player_status->food.has_value() &&
      observation.player_status->water.has_value()) {
    const meal_recovery::PlayerStatus status{
        .food = observation.player_status->food,
        .water = observation.player_status->water,
        .health = observation.player_status->health,
        .inventory_weight = observation.player_status->inventory_weight,
        .inventory_weight_max = observation.player_status->inventory_weight_max,
        .backpack_weight = observation.player_status->backpack_weight,
        .backpack_weight_max = observation.player_status->backpack_weight_max,
        .source = "e11-memory",
    };
    return meal_recovery::HasNeeds(
        status,
        static_cast<int>(request.settings.restore_food_from),
        static_cast<int>(request.settings.restore_water_from),
        std::nullopt);
  }
  if (observation.hunger_visible || observation.thirst_visible) {
    return true;
  }
  return std::nullopt;
}

[[nodiscard]] bool close_for_hud_check(
    inventory_store::inventory_episode_context& context,
    maintenance_observer& observer,
    const std::string_view inventory_hotkey) {
  for (std::size_t attempt = 0;
       attempt < 2 &&
       (context.current().surface == inventory_store::inventory_surface::inventory ||
        context.current().surface ==
            inventory_store::inventory_surface::item_context_menu);
       ++attempt) {
    if (!context.mutate({
            .kind = inventory_store::inventory_intent_kind::press_key,
            .key = std::string(inventory_hotkey),
            .packet_count = 2,
        }) ||
        !context.wait(kInventoryToggleMilliseconds)) {
      return false;
    }
    for (std::size_t poll = 0; poll < kClosePolls; ++poll) {
      if (!context.refresh()) {
        return false;
      }
      if (observer.current_maintenance().inventory.sequence !=
          context.current().sequence) {
        return context.reject("maintenance_observation_not_coherent");
      }
      if (context.current().surface ==
          inventory_store::inventory_surface::gameplay) {
        if (context.current().catch_screen_visible ||
            context.current().fishing_stage !=
                stage_detection::observed_fishing_stage::none) {
          return context.reject("meal_hud_check_state_invalid");
        }
        return context.wait(kInventoryCloseFinalMilliseconds) &&
            context.refresh();
      }
      if (poll + 1 < kClosePolls &&
          !context.wait(kObservationPollMilliseconds)) {
        return false;
      }
    }
  }
  if (context.current().surface !=
      inventory_store::inventory_surface::gameplay) {
    return context.reject("meal_inventory_close_not_confirmed");
  }
  return true;
}

}  // namespace

bool operation::execute_meal(
    inventory_store::inventory_episode_context& context,
    const std::stop_token stop_token) {
  if (!request_.settings.auto_meal) {
    completion_reason_ = "meal_disabled";
    return true;
  }

  std::size_t consume_attempts = 0;
  std::size_t backpack_attempts = 0;
  while (consume_attempts < kMaximumConsumes) {
    if (stop_requested(context, stop_token)) {
      return false;
    }
    const auto* observation = coherent(context);
    if (observation == nullptr) {
      return false;
    }
    const auto need = meal_need(*observation, request_);
    if (need.has_value() && !*need) {
      completion_reason_ = affected_count_ == 0
          ? "meal_already_satisfied"
          : "meal_recovered";
      return true;
    }

    if (const auto* item = find_food(
            context.current(),
            inventory_store::inventory_compartment::player_inventory);
        item != nullptr) {
      const std::string instance_id = item->instance_id;
      const std::size_t before = food_count(
          context.current(),
          inventory_store::inventory_compartment::player_inventory);
      if (!context.mutate(item_intent(
              inventory_store::inventory_intent_kind::use_inventory_item,
              *item,
              request_.settings.use_item_hotkey,
              4)) ||
          !context.wait(kMealAnimationMilliseconds) || !context.refresh()) {
        return false;
      }
      if (coherent(context) == nullptr) {
        return false;
      }
      if (find_instance(context.current(), instance_id) != nullptr ||
          food_count(
              context.current(),
              inventory_store::inventory_compartment::player_inventory) >=
              before) {
        return context.reject("meal_consumption_not_confirmed");
      }
      ++affected_count_;
      ++consume_attempts;
      backpack_attempts = 0;
      continue;
    }

    if (const auto* item = find_food(
            context.current(),
            inventory_store::inventory_compartment::backpack);
        item != nullptr && backpack_attempts < kMaximumBackpackMoves) {
      const std::string instance_id = item->instance_id;
      const std::string item_id = item->item_id;
      const std::size_t player_count_before = item_count(
          context.current(),
          inventory_store::inventory_compartment::player_inventory,
          item_id);
      if (!context.mutate(item_intent(
              inventory_store::inventory_intent_kind::move_backpack_item,
              *item,
              request_.settings.backpack_move_hotkey,
              4)) ||
          !context.wait(kBackpackMoveMilliseconds) || !context.refresh()) {
        return false;
      }
      if (coherent(context) == nullptr) {
        return false;
      }
      const auto* moved = find_instance(context.current(), instance_id);
      const bool moved_to_inventory = moved != nullptr &&
          moved->item_id == item_id &&
          moved->compartment ==
              inventory_store::inventory_compartment::player_inventory;
      const bool item_count_increased = item_count(
          context.current(),
          inventory_store::inventory_compartment::player_inventory,
          item_id) > player_count_before;
      if (!moved_to_inventory && !item_count_increased) {
        return context.reject("meal_backpack_move_not_confirmed");
      }
      ++backpack_attempts;
      ++backpack_move_count_;
      continue;
    }

    if (!close_for_hud_check(
            context, observer_, request_.settings.inventory_hotkey)) {
      return false;
    }

    std::size_t clear_polls = 0;
    bool still_needed = true;
    for (std::size_t poll = 0; poll < kHudPolls; ++poll) {
      const auto* hud_observation = coherent(context);
      if (hud_observation == nullptr) {
        return false;
      }
      const auto current_need = meal_need(*hud_observation, request_);
      if (current_need.has_value() && !*current_need) {
        still_needed = false;
        break;
      }
      if (hud_observation->hunger_visible ||
          hud_observation->thirst_visible ||
          (current_need.has_value() && *current_need)) {
        clear_polls = 0;
      } else {
        ++clear_polls;
        if (clear_polls >= 2) {
          still_needed = false;
          break;
        }
      }
      if (poll + 1 < kHudPolls &&
          (!context.wait(kHudPollMilliseconds) || !context.refresh())) {
        return false;
      }
    }
    if (!still_needed) {
      completion_reason_ = affected_count_ == 0
          ? "meal_hud_clear"
          : "meal_recovered";
      return true;
    }

    switch (request_.settings.food_depleted_action) {
      case runtime_settings::FoodDepletedAction::continue_fishing:
        meal_search_disabled_ = true;
        completion_reason_ = "meal_depleted_continue";
        return true;
      case runtime_settings::FoodDepletedAction::stop:
        completion_reason_ = "meal_depleted_stop";
        return emit_terminal(context, terminal_outcome::stop);
      case runtime_settings::FoodDepletedAction::exit_game:
        completion_reason_ = "meal_depleted_exit_game";
        return emit_terminal(context, terminal_outcome::exit_game);
      case runtime_settings::FoodDepletedAction::shutdown_pc:
        completion_reason_ = "meal_depleted_shutdown_pc";
        return emit_terminal(context, terminal_outcome::shutdown_pc);
    }
  }
  return context.reject("meal_consume_limit_reached");
}

}  // namespace sonar::fishing::maintenance_episode::detail
