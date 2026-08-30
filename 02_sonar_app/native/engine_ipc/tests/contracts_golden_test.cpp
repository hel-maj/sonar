#include <cstddef>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>

#include "ipc/v1/sonar_fishing.pb.h"

namespace {

void require(const bool condition, const std::string_view message) {
  if (!condition) {
    throw std::runtime_error(std::string(message));
  }
}

[[nodiscard]] unsigned char hex_nibble(const char value) {
  if (value >= '0' && value <= '9') {
    return static_cast<unsigned char>(value - '0');
  }
  if (value >= 'A' && value <= 'F') {
    return static_cast<unsigned char>(value - 'A' + 10);
  }
  throw std::runtime_error("golden_hex_invalid");
}

[[nodiscard]] std::string read_golden(const std::string_view file_name) {
  const auto path = std::filesystem::path(SONAR_FISHING_IPC_FIXTURE_ROOT) /
                    file_name;
  std::ifstream input(path);
  require(input.good(), "golden_fixture_missing");
  std::string hex;
  input >> hex;
  require(hex.size() % 2 == 0, "golden_hex_length_invalid");
  std::string bytes(hex.size() / 2, '\0');
  for (std::size_t index = 0; index < bytes.size(); ++index) {
    bytes[index] = static_cast<char>(
        (hex_nibble(hex[index * 2]) << 4U) |
        hex_nibble(hex[index * 2 + 1]));
  }
  return bytes;
}

}  // namespace

int main() {
  try {
    const std::string catch_quality_golden =
        read_golden("catch_quality_request.hex");
    sonar::fishing::ipc::v1::Envelope catch_quality;
    require(
        catch_quality.ParseFromString(catch_quality_golden),
        "catch_quality_golden_parse_failed");
    require(
        catch_quality.has_classify_catch_quality_request(),
        "catch_quality_golden_payload_case_changed");
    require(
        catch_quality.classify_catch_quality_request().has_raw_text(),
        "catch_quality_golden_presence_changed");
    require(
        catch_quality.classify_catch_quality_request().raw_text() == "Трофейная",
        "catch_quality_golden_text_changed");
    std::string serialized;
    require(
        catch_quality.SerializeToString(&serialized),
        "catch_quality_golden_serialize_failed");
    require(
        serialized == catch_quality_golden,
        "catch_quality_native_wire_parity_changed");

    const std::string catch_disposition_golden =
        read_golden("catch_disposition_request.hex");
    sonar::fishing::ipc::v1::Envelope catch_disposition;
    require(
        catch_disposition.ParseFromString(catch_disposition_golden),
        "catch_disposition_golden_parse_failed");
    require(
        catch_disposition.has_evaluate_catch_disposition_request(),
        "catch_disposition_golden_payload_case_changed");
    const auto& request = catch_disposition.evaluate_catch_disposition_request();
    require(request.has_fish_id(), "catch_disposition_golden_presence_changed");
    require(request.fish_id() == "marlin", "catch_disposition_golden_fish_changed");
    require(
        request.selected_fish_ids_size() == 2 &&
            request.selected_fish_ids(0) == "ruster" &&
            request.selected_fish_ids(1) == "marlin",
        "catch_disposition_golden_policy_changed");
    require(
        request.inventory_full(),
        "catch_disposition_golden_inventory_changed");
    serialized.clear();
    require(
        catch_disposition.SerializeToString(&serialized),
        "catch_disposition_golden_serialize_failed");
    require(
        serialized == catch_disposition_golden,
        "catch_disposition_native_wire_parity_changed");

    const std::string inventory_snapshot_golden =
        read_golden("inventory_snapshot_event.hex");
    sonar::fishing::ipc::v1::Envelope inventory_snapshot;
    require(
        inventory_snapshot.ParseFromString(inventory_snapshot_golden),
        "inventory_snapshot_golden_parse_failed");
    require(
        inventory_snapshot.has_inventory_state_snapshot(),
        "inventory_snapshot_golden_payload_case_changed");
    require(
        inventory_snapshot.inventory_state_snapshot().availability() ==
            sonar::inventory::ipc::v1::INVENTORY_AVAILABILITY_READY &&
            inventory_snapshot.inventory_state_snapshot().revision() == 1U,
        "inventory_snapshot_golden_fields_changed");
    serialized.clear();
    require(
        inventory_snapshot.SerializeToString(&serialized),
        "inventory_snapshot_golden_serialize_failed");
    require(
        serialized == inventory_snapshot_golden,
        "inventory_snapshot_native_wire_parity_changed");

    const std::string reset_statistics_golden =
        read_golden("reset_fishing_session_statistics_request.hex");
    sonar::fishing::ipc::v1::Envelope reset_statistics;
    require(
        reset_statistics.ParseFromString(reset_statistics_golden),
        "reset_statistics_golden_parse_failed");
    require(
        reset_statistics.has_reset_fishing_session_statistics_request(),
        "reset_statistics_golden_payload_case_changed");
    serialized.clear();
    require(
        reset_statistics.SerializeToString(&serialized),
        "reset_statistics_golden_serialize_failed");
    require(
        serialized == reset_statistics_golden,
        "reset_statistics_native_wire_parity_changed");

    std::cout << "PASS Fishing product envelopes native golden parity\n";
    return 0;
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
