#pragma once

#include <cstdint>
#include <string_view>

#include "inventory/v1/sonar_inventory.pb.h"
#include "sonar/majestic/cef_inventory/content/snapshot.hpp"

namespace sonar::fishing::engine_ipc {
class event_writer;
}

namespace sonar::platform::ipc {
class session_header_factory;
}

namespace sonar::fishing::engine_ipc::runtime {

void map_inventory_state(
    sonar::inventory::ipc::v1::InventoryStateSnapshot& target,
    const sonar::majestic::cef_inventory::content::inventory_state& source,
    std::uint64_t publication_revision,
    std::uint64_t observed_at_ms);

void publish_inventory_state(
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const sonar::majestic::cef_inventory::content::inventory_state& source,
    std::string_view session_id,
    sonar::platform::ipc::session_header_factory& headers,
    std::uint64_t publication_revision,
    std::uint64_t observed_at_ms);

}  // namespace sonar::fishing::engine_ipc::runtime
