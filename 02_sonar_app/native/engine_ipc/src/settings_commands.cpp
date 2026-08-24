#include "settings_commands.h"

#include <map>
#include <stdexcept>
#include <string>

namespace sonar::fishing::engine_ipc::runtime {
namespace {

[[nodiscard]] sonar::fishing::runtime_settings::OverweightAction
map_overweight_action(const sonar::fishing::ipc::v1::OverweightAction value) {
  using source = sonar::fishing::ipc::v1::OverweightAction;
  using target = sonar::fishing::runtime_settings::OverweightAction;
  switch (value) {
    case source::OVERWEIGHT_ACTION_RELEASE:
      return target::release;
    case source::OVERWEIGHT_ACTION_STOP:
      return target::stop;
    case source::OVERWEIGHT_ACTION_EXIT_GAME:
      return target::exit_game;
    default:
      throw std::runtime_error("settings_overweight_action_invalid");
  }
}

[[nodiscard]] sonar::fishing::runtime_settings::DepletedAction
map_depleted_action(const sonar::fishing::ipc::v1::DepletedAction value) {
  using source = sonar::fishing::ipc::v1::DepletedAction;
  using target = sonar::fishing::runtime_settings::DepletedAction;
  switch (value) {
    case source::DEPLETED_ACTION_STOP:
      return target::stop;
    case source::DEPLETED_ACTION_EXIT_GAME:
      return target::exit_game;
    default:
      throw std::runtime_error("settings_depleted_action_invalid");
  }
}

[[nodiscard]] sonar::fishing::runtime_settings::EquipmentDepletedAction
map_equipment_action(
    const sonar::fishing::ipc::v1::EquipmentDepletedAction value) {
  using source = sonar::fishing::ipc::v1::EquipmentDepletedAction;
  using target = sonar::fishing::runtime_settings::EquipmentDepletedAction;
  switch (value) {
    case source::EQUIPMENT_DEPLETED_ACTION_STOP:
      return target::stop;
    case source::EQUIPMENT_DEPLETED_ACTION_EXIT_GAME:
      return target::exit_game;
    case source::EQUIPMENT_DEPLETED_ACTION_SHUTDOWN_PC:
      return target::shutdown_pc;
    default:
      throw std::runtime_error("settings_equipment_action_invalid");
  }
}

[[nodiscard]] sonar::fishing::runtime_settings::FoodDepletedAction
map_food_action(const sonar::fishing::ipc::v1::FoodDepletedAction value) {
  using source = sonar::fishing::ipc::v1::FoodDepletedAction;
  using target = sonar::fishing::runtime_settings::FoodDepletedAction;
  switch (value) {
    case source::FOOD_DEPLETED_ACTION_CONTINUE:
      return target::continue_fishing;
    case source::FOOD_DEPLETED_ACTION_STOP:
      return target::stop;
    case source::FOOD_DEPLETED_ACTION_EXIT_GAME:
      return target::exit_game;
    case source::FOOD_DEPLETED_ACTION_SHUTDOWN_PC:
      return target::shutdown_pc;
    default:
      throw std::runtime_error("settings_food_action_invalid");
  }
}

template <typename TEntry>
[[nodiscard]] std::map<std::string, bool, std::less<>> map_boolean_policy(
    const google::protobuf::RepeatedPtrField<TEntry>& entries) {
  std::map<std::string, bool, std::less<>> result;
  for (const auto& entry : entries) {
    const auto [unused, inserted] = result.emplace(entry.id(), entry.enabled());
    static_cast<void>(unused);
    if (!inserted) {
      throw std::runtime_error("settings_policy_duplicate_id");
    }
  }
  return result;
}

[[nodiscard]] sonar::fishing::runtime_settings::RuntimeSettingsSnapshot
map_runtime_settings(
    const sonar::fishing::ipc::v1::FishingRuntimeSettings& source) {
  namespace target = sonar::fishing::runtime_settings;
  target::RuntimeSettingsSnapshot result{
      .revision = source.revision(),
      .auto_meal = source.auto_meal(),
      .restore_food_from = source.restore_food_from(),
      .restore_water_from = source.restore_water_from(),
      .restore_health_from = source.restore_health_from(),
      .auto_change_bait = source.auto_change_bait(),
      .store_in_trunk = source.store_in_trunk(),
      .start_stop_sound_enabled = source.start_stop_sound_enabled(),
      .overweight_action = map_overweight_action(source.overweight_action()),
      .fish_without_leader = source.fish_without_leader(),
      .leader_depleted_action = map_depleted_action(
          source.leader_depleted_action()),
      .fish_without_net = source.fish_without_net(),
      .net_depleted_action = map_depleted_action(source.net_depleted_action()),
      .equipment_depleted_action = map_equipment_action(
          source.equipment_depleted_action()),
      .food_depleted_action = map_food_action(source.food_depleted_action()),
      .start_stop_hotkey = source.start_stop_hotkey(),
      .inventory_hotkey = source.inventory_hotkey(),
      .use_item_hotkey = source.use_item_hotkey(),
      .backpack_move_hotkey = source.backpack_move_hotkey(),
      .discard_hotkey = source.discard_hotkey(),
      .chat_hotkey = source.chat_hotkey(),
      .stream_snapshot_mode = source.stream_snapshot_mode(),
      .fish_keep_policy = map_boolean_policy(source.fish_keep_policy()),
      .garbage_disposal_policy = map_boolean_policy(
          source.garbage_disposal_policy()),
  };
  for (const auto& entry : source.custom_fish_prices()) {
    const auto [unused, inserted] = result.custom_fish_prices.emplace(
        entry.fish_id(), entry.price());
    static_cast<void>(unused);
    if (!inserted) {
      throw std::runtime_error("settings_custom_price_duplicate_id");
    }
  }
  return result;
}

}  // namespace

void handle_apply_runtime_settings(
    const HANDLE pipe,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_apply_runtime_settings_request() ||
      !request.apply_runtime_settings_request().has_settings() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "apply-runtime-settings") {
    throw std::runtime_error("apply_runtime_settings_request_invalid");
  }

  sonar::fishing::runtime_settings::ApplyResult applied{
      .status = sonar::fishing::runtime_settings::ApplyStatus::invalid_snapshot,
      .accepted_revision = settings.AcceptedRevision(),
      .reason = "settings_payload_invalid",
  };
  try {
    applied = settings.Apply(map_runtime_settings(
        request.apply_runtime_settings_request().settings()));
  } catch (const std::exception& error) {
    applied.reason = error.what();
  }

  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      2,
      request.header().request_id(),
      applied.accepted() ? "completed" : "rejected");
  auto* result = response.mutable_apply_runtime_settings_result();
  result->set_accepted(applied.accepted());
  result->set_accepted_revision(applied.accepted_revision);
  result->set_reason(applied.reason);
  write_envelope(pipe, response);
}

}  // namespace sonar::fishing::engine_ipc::runtime
