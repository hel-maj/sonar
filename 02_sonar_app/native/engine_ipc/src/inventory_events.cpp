#include "inventory_events.h"

#include <cstddef>
#include <span>
#include <string>
#include <string_view>

#include "engine_protocol.h"
#include "sonar/fishing/engine_ipc/event_delivery.h"

namespace sonar::fishing::engine_ipc::runtime {
namespace {

namespace content = sonar::majestic::cef_inventory::content;
namespace inventory_v1 = sonar::inventory::ipc::v1;
namespace platform_v1 = sonar::platform::ipc::v1;

[[nodiscard]] std::string unavailable_reason(std::string_view value) {
  if (value.empty() || value.size() > 256U) {
    return "inventory_source_unavailable";
  }
  for (const char character : value) {
    if ((character >= 'a' && character <= 'z') ||
        (character >= '0' && character <= '9') || character == '_' ||
        character == '-' || character == '.') {
      continue;
    }
    return "inventory_source_unavailable";
  }
  return std::string(value);
}

[[nodiscard]] inventory_v1::InventoryConditionKind condition_kind(
    const content::condition_kind value) noexcept {
  switch (value) {
    case content::condition_kind::wear:
      return inventory_v1::INVENTORY_CONDITION_KIND_WEAR;
    case content::condition_kind::food:
      return inventory_v1::INVENTORY_CONDITION_KIND_FOOD;
    case content::condition_kind::none:
      return inventory_v1::INVENTORY_CONDITION_KIND_UNSPECIFIED;
  }
  return inventory_v1::INVENTORY_CONDITION_KIND_UNSPECIFIED;
}

void map_item(
    inventory_v1::InventoryItemSnapshot& target,
    const content::item_snapshot& source) {
  target.set_runtime_id(source.runtime_id);
  if (source.instance_id.has_value()) {
    target.set_instance_id(*source.instance_id);
  }
  target.set_catalog_item_id(source.catalog_item_id);
  target.set_name(source.name);
  target.set_category(source.category);
  target.set_column(source.column);
  target.set_row(source.row);
  target.set_column_span(source.column_span);
  target.set_row_span(source.row_span);
  target.set_count(source.count);
  if (source.maximum_count.has_value()) {
    target.set_maximum_count(*source.maximum_count);
  }
  if (source.unit_weight.has_value()) {
    target.set_unit_weight(*source.unit_weight);
  }
  if (source.total_weight.has_value()) {
    target.set_total_weight(*source.total_weight);
  }
  if (source.weight_grams.has_value()) {
    target.set_weight_grams(*source.weight_grams);
  }
  if (source.condition_percent.has_value()) {
    target.set_condition_percent(*source.condition_percent);
  }
  if (source.freshness_percent.has_value()) {
    target.set_freshness_percent(*source.freshness_percent);
  }
  if (source.raw_condition.has_value()) {
    target.set_raw_condition(*source.raw_condition);
  }
  target.set_condition_kind(condition_kind(source.condition));
  target.set_durability(source.durability);
  target.set_description(source.description);
  target.set_image_reference(source.image_reference);
  target.set_icon_key(source.icon_key);
  for (const auto& source_stat : source.stats) {
    auto* stat = target.add_stats();
    stat->set_name(source_stat.name);
    if (source_stat.numeric_value.has_value()) {
      stat->set_numeric_value(*source_stat.numeric_value);
    }
    if (source_stat.text_value.has_value()) {
      stat->set_text_value(*source_stat.text_value);
    }
    stat->set_background_color(source_stat.background_color);
    stat->set_color(source_stat.color);
  }
  for (const auto& source_buff : source.buffs) {
    auto* buff = target.add_buffs();
    buff->set_name(source_buff.name);
    buff->set_description(source_buff.description);
    if (source_buff.duration_ms.has_value()) {
      buff->set_duration_ms(*source_buff.duration_ms);
    }
    if (source_buff.icon.has_value()) {
      buff->set_icon(*source_buff.icon);
    }
    buff->set_background_color(source_buff.background_color);
    for (const auto& modifier : source_buff.modifiers) {
      buff->add_modifiers(modifier);
    }
    for (const auto& source_effect : source_buff.effects) {
      auto* effect = buff->add_effects();
      effect->set_title(source_effect.title);
      effect->set_description(source_effect.description);
    }
  }
  if (source.usable.has_value()) {
    target.set_usable(*source.usable);
  }
  if (source.rottable.has_value()) {
    target.set_rottable(*source.rottable);
  }
}

}  // namespace

void map_inventory_state(
    inventory_v1::InventoryStateSnapshot& target,
    const content::inventory_state& source,
    const std::uint64_t publication_revision,
    const std::uint64_t observed_at_ms) {
  target.Clear();
  target.set_revision(publication_revision);
  target.set_observed_at_ms(observed_at_ms);
  if (!source.ready) {
    target.set_availability(inventory_v1::INVENTORY_AVAILABILITY_UNAVAILABLE);
    target.set_reason(unavailable_reason(source.reason));
    return;
  }

  target.set_availability(inventory_v1::INVENTORY_AVAILABILITY_READY);
  target.set_open(source.snapshot.open);
  target.set_current_weight(source.snapshot.current_weight);
  target.set_maximum_weight(source.snapshot.maximum_weight);
  target.set_grid_rows(source.snapshot.grid_rows);
  target.set_grid_columns(source.snapshot.grid_columns);
  if (source.snapshot.active_position.has_value()) {
    target.set_active_position(*source.snapshot.active_position);
  }
  for (const auto& item : source.snapshot.items) {
    map_item(*target.add_items(), item);
  }
}

void publish_inventory_state(
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const content::inventory_state& source,
    const std::string_view session_id,
    sonar::platform::ipc::session_header_factory& headers,
    const std::uint64_t publication_revision,
    const std::uint64_t observed_at_ms) {
  fishing_envelope envelope;
  populate_header(
      *envelope.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_SNAPSHOT,
      session_id,
      publication_revision,
      "",
      source.ready ? "ready" : "unavailable",
      platform_v1::CHANNEL_KIND_EVENTS);
  map_inventory_state(
      *envelope.mutable_inventory_state_snapshot(),
      source,
      publication_revision,
      observed_at_ms);
  const auto payload = serialize_envelope(envelope);
  event_writer.publish_latest_inventory_snapshot(payload);
}

}  // namespace sonar::fishing::engine_ipc::runtime
