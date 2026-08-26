#include "sonar/fishing/engine_ipc/event_delivery.h"

#include <array>
#include <cstddef>
#include <iostream>
#include <mutex>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace {

using sonar::fishing::engine_ipc::event_delivery_error;
using sonar::fishing::engine_ipc::event_delivery_limits;
using sonar::fishing::engine_ipc::event_outbox;
using sonar::fishing::engine_ipc::event_writer;
using sonar::platform::ipc::frame_priority;
using sonar::platform::ipc::priority_queue_limits;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

[[nodiscard]] std::vector<std::byte> frame(const unsigned char value) {
  return {static_cast<std::byte>(value)};
}

void outbox_preserves_priority_and_coalesces_only_snapshots() {
  event_outbox outbox;
  const auto normal = frame(0x30);
  const auto lifecycle = frame(0x20);
  const auto safety = frame(0x10);
  const auto old_session_snapshot = frame(0x41);
  const auto latest_session_snapshot = frame(0x42);
  const auto old_inventory_snapshot = frame(0x51);
  const auto latest_inventory_snapshot = frame(0x52);
  outbox.enqueue_priority(normal, frame_priority::normal);
  outbox.enqueue_priority(lifecycle, frame_priority::lifecycle);
  outbox.enqueue_priority(safety, frame_priority::safety);
  outbox.publish_latest_session_snapshot(old_session_snapshot);
  outbox.publish_latest_session_snapshot(latest_session_snapshot);
  outbox.publish_latest_inventory_snapshot(old_inventory_snapshot);
  outbox.publish_latest_inventory_snapshot(latest_inventory_snapshot);

  require(outbox.take_next() == safety, "safety_event_was_not_first");
  require(outbox.take_next() == lifecycle, "lifecycle_event_was_not_second");
  require(outbox.take_next() == normal, "normal_event_was_not_third");
  require(
      outbox.take_next() == latest_session_snapshot,
      "latest_session_snapshot_was_not_coalesced");
  require(
      outbox.take_next() == latest_inventory_snapshot,
      "latest_inventory_snapshot_was_not_coalesced");
  require(!outbox.take_next().has_value(), "outbox_did_not_drain");
  const auto usage = outbox.usage();
  require(
      usage.coalesced_session_snapshot_count == 1,
      "session_snapshot_coalescing_count_changed");
  require(
      usage.coalesced_inventory_snapshot_count == 1,
      "inventory_snapshot_coalescing_count_changed");
}

void saturated_priority_is_explicit_and_never_dropped() {
  const priority_queue_limits one_frame{1, 8};
  event_outbox outbox(event_delivery_limits{
      .safety = one_frame,
      .lifecycle = one_frame,
      .normal = one_frame,
      .latest_session_snapshot_bytes = 8,
      .latest_inventory_snapshot_bytes = 8,
  });
  const auto safety = frame(0x10);
  outbox.enqueue_priority(safety, frame_priority::safety);
  try {
    outbox.enqueue_priority(safety, frame_priority::safety);
  } catch (const event_delivery_error& error) {
    require(
        error.reason() == "safety_queue_saturated",
        "safety_pressure_reason_changed");
    return;
  }
  throw std::runtime_error("saturated_safety_event_was_silently_dropped");
}

void writer_drains_accepted_frames_and_closes_admission() {
  std::mutex gate;
  std::vector<std::vector<std::byte>> delivered;
  event_writer writer(
      [&gate, &delivered](
          const std::span<const std::byte> payload,
          const std::stop_token cancellation) {
        require(!cancellation.stop_requested(), "drain_was_cancelled");
        const std::scoped_lock lock(gate);
        delivered.emplace_back(payload.begin(), payload.end());
      });
  const auto lifecycle = frame(0x20);
  const auto snapshot = frame(0x40);
  writer.enqueue_priority(lifecycle, frame_priority::lifecycle);
  writer.publish_latest_session_snapshot(snapshot);
  writer.close_and_drain();

  {
    const std::scoped_lock lock(gate);
    require(delivered.size() == 2, "accepted_frames_were_not_drained");
    require(delivered.front() == lifecycle, "lifecycle_order_changed");
    require(delivered.back() == snapshot, "snapshot_order_changed");
  }
  try {
    writer.publish_latest_session_snapshot(snapshot);
  } catch (const event_delivery_error& error) {
    require(error.reason() == "event_writer_closed", "closed_reason_changed");
    return;
  }
  throw std::runtime_error("closed_writer_accepted_a_snapshot");
}

struct test_case final {
  std::string_view name;
  void (*run)();
};

}  // namespace

int main() {
  const std::array tests{
      test_case{
          "outbox_preserves_priority_and_coalesces_only_snapshots",
          outbox_preserves_priority_and_coalesces_only_snapshots},
      test_case{
          "saturated_priority_is_explicit_and_never_dropped",
          saturated_priority_is_explicit_and_never_dropped},
      test_case{
          "writer_drains_accepted_frames_and_closes_admission",
          writer_drains_accepted_frames_and_closes_admission},
  };

  std::size_t failures = 0;
  for (const auto& test : tests) {
    try {
      test.run();
      std::cout << "PASS " << test.name << '\n';
    } catch (const std::exception& error) {
      ++failures;
      std::cerr << "FAIL " << test.name << ": " << error.what() << '\n';
    }
  }
  std::cout << "Executed " << tests.size()
            << " event-delivery tests; failures: " << failures << "\n";
  return failures == 0 ? 0 : 1;
}
