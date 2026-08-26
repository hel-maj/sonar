#include "sonar/fishing/engine_ipc/event_delivery.h"

#include <condition_variable>
#include <exception>
#include <mutex>
#include <thread>
#include <utility>

namespace sonar::fishing::engine_ipc {
namespace {

[[nodiscard]] std::string stable_writer_failure(
    const std::exception_ptr& failure) {
  if (!failure) {
    return {};
  }
  try {
    std::rethrow_exception(failure);
  } catch (const event_delivery_error& error) {
    return error.reason();
  } catch (const std::exception& error) {
    return std::string("event_writer_failed:") + error.what();
  } catch (...) {
    return "event_writer_failed:unknown";
  }
}

}  // namespace

event_delivery_error::event_delivery_error(std::string reason)
    : std::runtime_error(reason), reason_(std::move(reason)) {}

const std::string& event_delivery_error::reason() const noexcept {
  return reason_;
}

event_outbox::event_outbox(const event_delivery_limits limits)
    : priority_(limits.safety, limits.lifecycle, limits.normal),
      latest_session_snapshot_(limits.latest_session_snapshot_bytes),
      latest_inventory_snapshot_(limits.latest_inventory_snapshot_bytes) {}

void event_outbox::enqueue_priority(
    const std::span<const std::byte> payload,
    const sonar::platform::ipc::frame_priority priority) {
  std::string_view reason;
  if (!priority_.try_enqueue(payload, priority, reason)) {
    throw event_delivery_error(
        reason.empty() ? "event_priority_enqueue_failed" : std::string(reason));
  }
}

void event_outbox::publish_latest_session_snapshot(
    const std::span<const std::byte> payload) {
  std::string_view reason;
  if (!latest_session_snapshot_.publish(payload, reason)) {
    throw event_delivery_error(
        reason.empty()
            ? "event_session_snapshot_publish_failed"
            : std::string(reason));
  }
}

void event_outbox::publish_latest_inventory_snapshot(
    const std::span<const std::byte> payload) {
  std::string_view reason;
  if (!latest_inventory_snapshot_.publish(payload, reason)) {
    throw event_delivery_error(
        reason.empty()
            ? "event_inventory_snapshot_publish_failed"
            : std::string(reason));
  }
}

std::optional<std::vector<std::byte>> event_outbox::take_next() {
  if (auto priority = priority_.try_dequeue(); priority.has_value()) {
    return priority;
  }
  if (take_inventory_next_) {
    if (auto inventory = latest_inventory_snapshot_.take();
        inventory.has_value()) {
      take_inventory_next_ = false;
      return inventory;
    }
    if (auto session = latest_session_snapshot_.take(); session.has_value()) {
      take_inventory_next_ = true;
      return session;
    }
  } else {
    if (auto session = latest_session_snapshot_.take(); session.has_value()) {
      take_inventory_next_ = true;
      return session;
    }
    if (auto inventory = latest_inventory_snapshot_.take();
        inventory.has_value()) {
      take_inventory_next_ = false;
      return inventory;
    }
  }
  return std::nullopt;
}

bool event_outbox::has_pending() const {
  return priority_.usage(sonar::platform::ipc::frame_priority::safety).count != 0 ||
      priority_.usage(sonar::platform::ipc::frame_priority::lifecycle).count != 0 ||
      priority_.usage(sonar::platform::ipc::frame_priority::normal).count != 0 ||
      latest_session_snapshot_.pending_bytes() != 0 ||
      latest_inventory_snapshot_.pending_bytes() != 0;
}

event_delivery_usage event_outbox::usage() const {
  return {
      .safety = priority_.usage(sonar::platform::ipc::frame_priority::safety),
      .lifecycle = priority_.usage(
          sonar::platform::ipc::frame_priority::lifecycle),
      .normal = priority_.usage(sonar::platform::ipc::frame_priority::normal),
      .latest_session_snapshot_bytes =
          latest_session_snapshot_.pending_bytes(),
      .latest_inventory_snapshot_bytes =
          latest_inventory_snapshot_.pending_bytes(),
      .coalesced_session_snapshot_count =
          latest_session_snapshot_.coalesced_count(),
      .coalesced_inventory_snapshot_count =
          latest_inventory_snapshot_.coalesced_count(),
  };
}

struct event_writer::state final {
  explicit state(event_frame_sink target, const event_delivery_limits limits)
      : sink(std::move(target)), outbox(limits) {
    if (!sink) {
      throw std::invalid_argument("event_sink_missing");
    }
    worker = std::jthread([this](const std::stop_token cancellation) {
      run(cancellation);
    });
  }

  void run(const std::stop_token cancellation) noexcept {
    try {
      while (true) {
        std::unique_lock lock(gate);
        const bool ready = wake.wait(
            lock,
            cancellation,
            [this] { return closing || outbox.has_pending(); });
        if (!ready || cancellation.stop_requested()) {
          return;
        }
        if (auto payload = outbox.take_next(); payload.has_value()) {
          lock.unlock();
          sink(*payload, cancellation);
          continue;
        }
        if (closing) {
          return;
        }
      }
    } catch (...) {
      const std::scoped_lock lock(gate);
      failure = std::current_exception();
      accepting = false;
      closing = true;
      wake.notify_all();
    }
  }

  void require_healthy_and_accepting() const {
    if (failure) {
      throw event_delivery_error(stable_writer_failure(failure));
    }
    if (!accepting) {
      throw event_delivery_error("event_writer_closed");
    }
  }

  event_frame_sink sink;
  event_outbox outbox;
  mutable std::mutex gate;
  std::condition_variable_any wake;
  bool accepting = true;
  bool closing = false;
  std::exception_ptr failure;
  std::jthread worker;
};

event_writer::event_writer(
    event_frame_sink sink,
    const event_delivery_limits limits)
    : state_(std::make_unique<state>(std::move(sink), limits)) {}

event_writer::~event_writer() {
  cancel();
}

void event_writer::enqueue_priority(
    const std::span<const std::byte> payload,
    const sonar::platform::ipc::frame_priority priority) {
  const std::scoped_lock lock(state_->gate);
  state_->require_healthy_and_accepting();
  state_->outbox.enqueue_priority(payload, priority);
  state_->wake.notify_one();
}

void event_writer::publish_latest_session_snapshot(
    const std::span<const std::byte> payload) {
  const std::scoped_lock lock(state_->gate);
  state_->require_healthy_and_accepting();
  state_->outbox.publish_latest_session_snapshot(payload);
  state_->wake.notify_one();
}

void event_writer::publish_latest_inventory_snapshot(
    const std::span<const std::byte> payload) {
  const std::scoped_lock lock(state_->gate);
  state_->require_healthy_and_accepting();
  state_->outbox.publish_latest_inventory_snapshot(payload);
  state_->wake.notify_one();
}

void event_writer::close_and_drain() {
  {
    const std::scoped_lock lock(state_->gate);
    state_->accepting = false;
    state_->closing = true;
    state_->wake.notify_all();
  }
  if (state_->worker.joinable()) {
    state_->worker.join();
  }
  const std::scoped_lock lock(state_->gate);
  if (state_->failure) {
    throw event_delivery_error(stable_writer_failure(state_->failure));
  }
  if (state_->outbox.has_pending()) {
    throw event_delivery_error("event_writer_drain_incomplete");
  }
}

void event_writer::cancel() noexcept {
  if (!state_) {
    return;
  }
  {
    const std::scoped_lock lock(state_->gate);
    state_->accepting = false;
    state_->closing = true;
  }
  state_->worker.request_stop();
  state_->wake.notify_all();
  if (state_->worker.joinable()) {
    state_->worker.join();
  }
}

event_delivery_usage event_writer::usage() const {
  const std::scoped_lock lock(state_->gate);
  return state_->outbox.usage();
}

}  // namespace sonar::fishing::engine_ipc
