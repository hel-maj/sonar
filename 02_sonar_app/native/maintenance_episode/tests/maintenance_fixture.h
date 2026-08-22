#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <limits>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "sonar/fishing/maintenance_episode/maintenance_episode.h"

namespace sonar::fishing::maintenance_episode::tests {

namespace inventory = sonar::fishing::inventory_store;
namespace memory = sonar::fishing::memory_observation;
namespace settings = sonar::fishing::runtime_settings;
namespace stage = sonar::fishing::stage_detection;

struct expected_result final {
  bool ok{};
  std::string reason;
  std::size_t affected_count{};
  std::size_t backpack_move_count{};
  bool meal_search_disabled{};
  double next_bait_change_at_seconds{};
  bool bait_cooldown_advanced{};
  terminal_outcome terminal{terminal_outcome::none};
  std::vector<equipment_recovery::TackleKind> warnings;
  std::vector<std::string> intents;
};

struct fixture_case final {
  std::string id;
  maintenance_request request;
  std::vector<maintenance_observation> observations;
  expected_result expected;
  std::string raw_contract;
};

[[noreturn]] inline void fixture_error(
    const std::size_t line,
    const std::string_view reason) {
  throw std::runtime_error(
      "fixture_line_" + std::to_string(line) + ":" + std::string(reason));
}

[[nodiscard]] inline std::vector<std::string> split(
    const std::string_view value,
    const char delimiter) {
  std::vector<std::string> result;
  std::size_t start = 0;
  while (start <= value.size()) {
    const std::size_t end = value.find(delimiter, start);
    result.emplace_back(value.substr(
        start,
        end == std::string_view::npos ? value.size() - start : end - start));
    if (end == std::string_view::npos) {
      break;
    }
    start = end + 1;
  }
  return result;
}

[[nodiscard]] inline bool parse_bool(
    const std::string_view value,
    const std::size_t line) {
  if (value == "1" || value == "true") {
    return true;
  }
  if (value == "0" || value == "false") {
    return false;
  }
  fixture_error(line, "bool_invalid");
}

[[nodiscard]] inline std::uint64_t parse_u64(
    const std::string_view value,
    const std::size_t line) {
  std::size_t consumed{};
  const auto parsed = std::stoull(std::string(value), &consumed);
  if (consumed != value.size()) {
    fixture_error(line, "uint_invalid");
  }
  return parsed;
}

[[nodiscard]] inline std::uint32_t parse_u32(
    const std::string_view value,
    const std::size_t line) {
  const std::uint64_t parsed = parse_u64(value, line);
  if (parsed > std::numeric_limits<std::uint32_t>::max()) {
    fixture_error(line, "uint32_overflow");
  }
  return static_cast<std::uint32_t>(parsed);
}

[[nodiscard]] inline std::size_t parse_size(
    const std::string_view value,
    const std::size_t line) {
  const std::uint64_t parsed = parse_u64(value, line);
  if (parsed > std::numeric_limits<std::size_t>::max()) {
    fixture_error(line, "size_overflow");
  }
  return static_cast<std::size_t>(parsed);
}

[[nodiscard]] inline double parse_double(
    const std::string_view value,
    const std::size_t line) {
  std::size_t consumed{};
  const double parsed = std::stod(std::string(value), &consumed);
  if (consumed != value.size()) {
    fixture_error(line, "double_invalid");
  }
  return parsed;
}

[[nodiscard]] inline std::optional<int> parse_optional_int(
    const std::string_view value,
    const std::size_t line) {
  if (value == "-") {
    return std::nullopt;
  }
  std::size_t consumed{};
  const long parsed = std::stol(std::string(value), &consumed);
  if (consumed != value.size() ||
      parsed < std::numeric_limits<int>::min() ||
      parsed > std::numeric_limits<int>::max()) {
    fixture_error(line, "optional_int_invalid");
  }
  return static_cast<int>(parsed);
}

[[nodiscard]] inline episode_kind parse_kind(
    const std::string_view value,
    const std::size_t line) {
  if (value == "meal") {
    return episode_kind::meal_recovery;
  }
  if (value == "garbage") {
    return episode_kind::garbage_disposal;
  }
  if (value == "tackle") {
    return episode_kind::tackle_check;
  }
  if (value == "bait") {
    return episode_kind::bait_recovery;
  }
  fixture_error(line, "kind_invalid");
}

[[nodiscard]] inline inventory::inventory_surface parse_surface(
    const std::string_view value,
    const std::size_t line) {
  if (value == "gameplay") {
    return inventory::inventory_surface::gameplay;
  }
  if (value == "game_menu") {
    return inventory::inventory_surface::game_menu;
  }
  if (value == "inventory") {
    return inventory::inventory_surface::inventory;
  }
  if (value == "item_context_menu") {
    return inventory::inventory_surface::item_context_menu;
  }
  fixture_error(line, "surface_invalid");
}

[[nodiscard]] inline stage::observed_fishing_stage parse_stage(
    const std::string_view value,
    const std::size_t line) {
  if (value == "none") {
    return stage::observed_fishing_stage::none;
  }
  if (value == "tackle_selection") {
    return stage::observed_fishing_stage::tackle_selection;
  }
  if (value == "casting") {
    return stage::observed_fishing_stage::casting;
  }
  if (value == "waiting_for_bite") {
    return stage::observed_fishing_stage::waiting_for_bite;
  }
  if (value == "reeling") {
    return stage::observed_fishing_stage::reeling;
  }
  fixture_error(line, "stage_invalid");
}

[[nodiscard]] inline inventory::inventory_compartment parse_compartment(
    const std::string_view value,
    const std::size_t line) {
  if (value == "player") {
    return inventory::inventory_compartment::player_inventory;
  }
  if (value == "backpack") {
    return inventory::inventory_compartment::backpack;
  }
  fixture_error(line, "compartment_invalid");
}

[[nodiscard]] inline std::vector<inventory::inventory_item_observation>
parse_items(const std::string_view value, const std::size_t line) {
  std::vector<inventory::inventory_item_observation> result;
  if (value == "-") {
    return result;
  }
  for (const auto& encoded_item : split(value, ';')) {
    const auto fields = split(encoded_item, ',');
    if (fields.size() != 8) {
      fixture_error(line, "item_field_count");
    }
    result.push_back({
        .instance_id = fields[0],
        .item_id = fields[1],
        .title = fields[1],
        .compartment = parse_compartment(fields[2], line),
        .confidence = parse_double(fields[3], line),
        .bounds = {
            .x = parse_double(fields[4], line),
            .y = parse_double(fields[5], line),
            .width = parse_double(fields[6], line),
            .height = parse_double(fields[7], line),
        },
    });
  }
  return result;
}

[[nodiscard]] inline std::optional<tackle_scan_observation> parse_tackle(
    const std::string_view value,
    const std::size_t line) {
  if (value == "-") {
    return std::nullopt;
  }
  const auto fields = split(value, ',');
  if (fields.size() != 9) {
    fixture_error(line, "tackle_field_count");
  }
  return tackle_scan_observation{
      .available = parse_bool(fields[0], line),
      .readable = parse_bool(fields[1], line),
      .obscured = parse_bool(fields[2], line),
      .counts = {
          .rod = parse_u32(fields[3], line),
          .reel = parse_u32(fields[4], line),
          .line = parse_u32(fields[5], line),
          .hook = parse_u32(fields[6], line),
          .bait = parse_u32(fields[7], line),
          .net = parse_u32(fields[8], line),
      },
  };
}

[[nodiscard]] inline settings::FoodDepletedAction parse_food_action(
    const std::string_view value,
    const std::size_t line) {
  if (value == "continue") {
    return settings::FoodDepletedAction::continue_fishing;
  }
  if (value == "stop") {
    return settings::FoodDepletedAction::stop;
  }
  if (value == "exit_game") {
    return settings::FoodDepletedAction::exit_game;
  }
  if (value == "shutdown_pc") {
    return settings::FoodDepletedAction::shutdown_pc;
  }
  fixture_error(line, "food_action_invalid");
}

[[nodiscard]] inline settings::EquipmentDepletedAction
parse_equipment_action(
    const std::string_view value,
    const std::size_t line) {
  if (value == "stop") {
    return settings::EquipmentDepletedAction::stop;
  }
  if (value == "exit_game") {
    return settings::EquipmentDepletedAction::exit_game;
  }
  if (value == "shutdown_pc") {
    return settings::EquipmentDepletedAction::shutdown_pc;
  }
  fixture_error(line, "equipment_action_invalid");
}

[[nodiscard]] inline terminal_outcome parse_terminal(
    const std::string_view value,
    const std::size_t line) {
  if (value == "none") {
    return terminal_outcome::none;
  }
  if (value == "stop") {
    return terminal_outcome::stop;
  }
  if (value == "exit_game") {
    return terminal_outcome::exit_game;
  }
  if (value == "shutdown_pc") {
    return terminal_outcome::shutdown_pc;
  }
  fixture_error(line, "terminal_invalid");
}

[[nodiscard]] inline equipment_recovery::TackleKind parse_warning(
    const std::string_view value,
    const std::size_t line) {
  using equipment_recovery::TackleKind;
  if (value == "rod") return TackleKind::rod;
  if (value == "reel") return TackleKind::reel;
  if (value == "line") return TackleKind::line;
  if (value == "hook") return TackleKind::hook;
  if (value == "bait") return TackleKind::bait;
  if (value == "net") return TackleKind::net;
  fixture_error(line, "warning_invalid");
}

[[nodiscard]] inline std::string contract_tail(
    const std::vector<std::string>& fields) {
  std::string result;
  for (std::size_t index = 13; index < fields.size(); ++index) {
    if (!result.empty()) {
      result.push_back('\t');
    }
    result.append(fields[index]);
  }
  return result;
}

inline void parse_contract(
    fixture_case& target,
    const std::vector<std::string>& fields,
    const std::size_t line) {
  target.request.kind = parse_kind(fields[1], line);
  target.request.settings.revision = 1;
  target.request.settings.auto_meal = parse_bool(fields[13], line);
  target.request.settings.food_depleted_action =
      parse_food_action(fields[14], line);
  if (fields[15] != "-") {
    for (const auto& item : split(fields[15], ',')) {
      target.request.settings.garbage_disposal_policy.emplace(item, true);
    }
  }
  target.request.settings.equipment_depleted_action =
      parse_equipment_action(fields[16], line);
  target.request.settings.auto_change_bait = parse_bool(fields[17], line);
  target.request.settings.inventory_hotkey = fields[18];
  if (fields[19] != "-") {
    target.request.session_started_with_net = parse_bool(fields[19], line);
  }
  target.request.now_seconds = parse_double(fields[20], line);
  target.request.last_bait_change_at_seconds = parse_double(fields[21], line);
  target.request.resume_fishing = parse_bool(fields[22], line);

  target.expected.ok = parse_bool(fields[23], line);
  target.expected.reason = fields[24];
  target.expected.affected_count = parse_size(fields[25], line);
  target.expected.backpack_move_count = parse_size(fields[26], line);
  target.expected.meal_search_disabled = parse_bool(fields[27], line);
  target.expected.next_bait_change_at_seconds =
      parse_double(fields[28], line);
  target.expected.bait_cooldown_advanced = parse_bool(fields[29], line);
  target.expected.terminal = parse_terminal(fields[30], line);
  if (fields[31] != "-") {
    for (const auto& item : split(fields[31], ',')) {
      target.expected.warnings.push_back(parse_warning(item, line));
    }
  }
  target.expected.intents = split(fields[32], ';');
  target.raw_contract = contract_tail(fields);
}

[[nodiscard]] inline maintenance_observation parse_observation(
    const std::vector<std::string>& fields,
    const std::size_t line) {
  maintenance_observation result{
      .inventory = {
          .sequence = parse_u64(fields[2], line),
          .surface = parse_surface(fields[3], line),
          .fishing_stage = parse_stage(fields[4], line),
          .items = parse_items(fields[5], line),
      },
      .hunger_visible = parse_bool(fields[8], line),
      .thirst_visible = parse_bool(fields[9], line),
      .tackle = parse_tackle(fields[10], line),
      .changed_bait_visible = parse_bool(fields[11], line),
      .gear_visible = parse_bool(fields[12], line),
  };
  const auto food = parse_optional_int(fields[6], line);
  const auto water = parse_optional_int(fields[7], line);
  if (food.has_value() || water.has_value()) {
    result.player_status = memory::player_status_evidence{
        .food = food,
        .water = water,
    };
  }
  return result;
}

[[nodiscard]] inline std::vector<fixture_case> load_fixture(
    const std::string& path) {
  std::ifstream input(path);
  if (!input) {
    throw std::runtime_error("maintenance_fixture_not_found:" + path);
  }
  constexpr std::string_view expected_header =
      "case_id\tkind\tsequence\tsurface\tstage\titems\tfood\twater\t"
      "hunger\tthirst\ttackle\tchanged_bait\tgear\tauto_meal\t"
      "food_action\tgarbage\tequipment_action\tauto_change_bait\t"
      "inventory_hotkey\tsession_net\tnow_seconds\tlast_bait_seconds\t"
      "resume\texpected_ok\texpected_reason\texpected_affected\t"
      "expected_moves\texpected_meal_disabled\texpected_next_bait\t"
      "expected_cooldown\texpected_terminal\texpected_warnings\t"
      "expected_intents";
  std::string line;
  if (!std::getline(input, line) || line != expected_header) {
    throw std::runtime_error("maintenance_fixture_header_changed");
  }

  std::vector<fixture_case> result;
  std::size_t line_number = 1;
  while (std::getline(input, line)) {
    ++line_number;
    if (line.empty()) {
      continue;
    }
    const auto fields = split(line, '\t');
    if (fields.size() != 33) {
      fixture_error(line_number, "field_count");
    }
    const auto found = std::find_if(
        result.begin(),
        result.end(),
        [&fields](const auto& item) { return item.id == fields[0]; });
    fixture_case* target{};
    if (found == result.end()) {
      result.push_back({.id = fields[0]});
      target = &result.back();
      parse_contract(*target, fields, line_number);
    } else {
      target = &*found;
      if (target->raw_contract != contract_tail(fields) ||
          target->request.kind != parse_kind(fields[1], line_number)) {
        fixture_error(line_number, "case_contract_changed");
      }
    }
    target->observations.push_back(parse_observation(fields, line_number));
  }
  if (result.empty()) {
    throw std::runtime_error("maintenance_fixture_empty");
  }
  for (const auto& item : result) {
    if (item.observations.empty()) {
      throw std::runtime_error("maintenance_fixture_case_empty:" + item.id);
    }
  }
  return result;
}

}  // namespace sonar::fishing::maintenance_episode::tests
