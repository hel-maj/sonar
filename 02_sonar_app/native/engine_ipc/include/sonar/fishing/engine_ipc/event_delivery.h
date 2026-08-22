#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <stop_token>
#include <string>
#include <string_view>
#include <vector>

#include "sonar/platform/ipc/bounded_buffers.hpp"

namespace sonar::fishing::engine_ipc {

struct event_delivery_limits final {
  sonar::platform::ipc::priority_queue_limits safety{8, 512U * 1024U};
  sonar::platform::ipc::priority_queue_limits lifecycle{32, 2U * 1024U * 1024U};
  sonar::platform::ipc::priority_queue_limits normal{128, 4U * 1024U * 1024U};
  std::size_t latest_snapshot_bytes =
      sonar::platform::ipc::event_frame_maximum;
};

struct event_delivery_usage final {
  sonar::platform::ipc::priority_queue_usage safety;
  sonar::platform::ipc::priority_queue_usage lifecycle;
  sonar::platform::ipc::priority_queue_usage normal;
  std::size_t latest_snapshot_bytes = 0;
  std::uint64_t coalesced_snapshot_count = 0;
};

class event_delivery_error final : public std::runtime_error {
 public:
  explicit event_delivery_error(std::string reason);

  [[nodiscard]] const std::string& reason() const noexcept;

 private:
  std::string reason_;
};

class event_outbox final {
 public:
  explicit event_outbox(event_delivery_limits limits = {});

  void enqueue_priority(
      std::span<const std::byte> payload,
      sonar::platform::ipc::frame_priority priority);
  void publish_latest_snapshot(std::span<const std::byte> payload);

  [[nodiscard]] std::optional<std::vector<std::byte>> take_next();
  [[nodiscard]] bool has_pending() const;
  [[nodiscard]] event_delivery_usage usage() const;

 private:
  sonar::platform::ipc::priority_frame_queue priority_;
  sonar::platform::ipc::latest_frame_buffer latest_snapshot_;
};

using event_frame_sink = std::function<void(
    std::span<const std::byte> payload,
    std::stop_token cancellation)>;

// Product-owned ordering and lifecycle around Common bounded buffers. The sink
// is the only transport side effect and is invoked by one cancellable writer.
class event_writer final {
 public:
  explicit event_writer(
      event_frame_sink sink,
      event_delivery_limits limits = {});
  ~event_writer();

  event_writer(const event_writer&) = delete;
  event_writer& operator=(const event_writer&) = delete;

  void enqueue_priority(
      std::span<const std::byte> payload,
      sonar::platform::ipc::frame_priority priority);
  void publish_latest_snapshot(std::span<const std::byte> payload);

  // Stops accepting frames, drains every accepted priority frame and the
  // newest coalesced snapshot, then surfaces a writer failure to the session.
  void close_and_drain();
  void cancel() noexcept;

  [[nodiscard]] event_delivery_usage usage() const;

 private:
  struct state;
  std::unique_ptr<state> state_;
};

}  // namespace sonar::fishing::engine_ipc
