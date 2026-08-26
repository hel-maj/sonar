#include "inventory_events.h"

#include <cstdlib>
#include <iostream>
#include <optional>
#include <string_view>
#include <utility>

namespace {

namespace content = sonar::majestic::cef_inventory::content;
namespace inventory_v1 = sonar::inventory::ipc::v1;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    std::cerr << "FAIL " << reason << '\n';
    std::exit(1);
  }
}

[[nodiscard]] content::inventory_state ready_state() {
  content::item_snapshot item;
  item.runtime_id = "instance-42";
  item.instance_id = 42U;
  item.catalog_item_id = 246U;
  item.name = "Knife";
  item.category = "Ammunition";
  item.column = 2U;
  item.row = 3U;
  item.column_span = 1U;
  item.row_span = 3U;
  item.count = 1U;
  item.maximum_count = 1U;
  item.unit_weight = 0.18;
  item.total_weight = 0.18;
  item.weight_grams = 180U;
  item.condition_percent = 75.0;
  item.raw_condition = 75U;
  item.condition = content::condition_kind::wear;
  item.durability = "good";
  item.description = "Inventory item";
  item.image_reference = "https://example.test/knife.png";
  item.icon_key = "knife";
  item.stats.push_back({"Damage", 12.5, std::nullopt, "#fff", "#000"});
  content::buff_snapshot buff;
  buff.name = "Warmth";
  buff.description = "Warm";
  buff.modifiers.push_back("+1");
  buff.effects.push_back({"Effect", "Description"});
  buff.duration_ms = 5000.0;
  buff.icon = 7U;
  buff.background_color = "#123456";
  item.buffs.push_back(std::move(buff));
  item.usable = true;
  item.rottable = false;

  content::inventory_snapshot snapshot;
  snapshot.revision = 8U;
  snapshot.observed_at_ms = 900U;
  snapshot.open = true;
  snapshot.current_weight = 19.9;
  snapshot.maximum_weight = 100.0;
  snapshot.grid_rows = 17U;
  snapshot.grid_columns = 6U;
  snapshot.items.push_back(std::move(item));
  snapshot.active_position = 21U;
  return {true, "ready", std::move(snapshot)};
}

void maps_ready_content_without_source_identity_leak() {
  inventory_v1::InventoryStateSnapshot wire;
  sonar::fishing::engine_ipc::runtime::map_inventory_state(
      wire, ready_state(), 12U, 1'500U);
  require(
      wire.availability() == inventory_v1::INVENTORY_AVAILABILITY_READY,
      "ready_availability_changed");
  require(wire.reason().empty(), "ready_reason_was_not_empty");
  require(
      wire.revision() == 12U && wire.observed_at_ms() == 1'500U,
      "product_publication_identity_not_authoritative");
  require(
      wire.has_open() && wire.open() && wire.has_current_weight() &&
          wire.current_weight() == 19.9 && wire.grid_rows() == 17U &&
          wire.grid_columns() == 6U && wire.items_size() == 1,
      "ready_inventory_summary_changed");
  const auto& item = wire.items(0);
  require(
      item.runtime_id() == "instance-42" && item.has_instance_id() &&
          item.instance_id() == 42U && item.catalog_item_id() == 246U &&
          item.row_span() == 3U && item.image_reference().ends_with("knife.png"),
      "inventory_item_mapping_changed");
  require(
      item.condition_kind() == inventory_v1::INVENTORY_CONDITION_KIND_WEAR &&
          item.stats_size() == 1 && item.buffs_size() == 1 &&
          item.has_usable() && item.usable() && item.has_rottable() &&
          !item.rottable(),
      "inventory_nested_mapping_changed");
}

void maps_unavailable_without_stale_content() {
  auto stale = ready_state();
  stale.ready = false;
  stale.reason = "inventory_missing";
  inventory_v1::InventoryStateSnapshot wire;
  sonar::fishing::engine_ipc::runtime::map_inventory_state(
      wire, stale, 13U, 1'600U);
  require(
      wire.availability() == inventory_v1::INVENTORY_AVAILABILITY_UNAVAILABLE &&
          wire.reason() == "inventory_missing" && !wire.has_open() &&
          !wire.has_current_weight() && wire.grid_rows() == 0U &&
          wire.items().empty(),
      "unavailable_snapshot_replayed_stale_content");

  stale.reason = "not valid: detail";
  sonar::fishing::engine_ipc::runtime::map_inventory_state(
      wire, stale, 14U, 1'700U);
  require(
      wire.reason() == "inventory_source_unavailable",
      "invalid_source_reason_crossed_ipc_boundary");
}

}  // namespace

int main() {
  maps_ready_content_without_source_identity_leak();
  maps_unavailable_without_stale_content();
  std::cout << "PASS Fishing inventory event mapping\n";
  return 0;
}
