#include "sonar/fishing/engine_ipc/inventory_observation_worker.h"

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <utility>

namespace sonar::fishing::engine_ipc {
namespace {

namespace content = sonar::majestic::cef_inventory::content;

[[nodiscard]] std::uint64_t monotonic_milliseconds() noexcept {
  const auto count = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::steady_clock::now().time_since_epoch()).count();
  return static_cast<std::uint64_t>(std::max<std::int64_t>(1, count));
}

[[nodiscard]] bool same_visible_state(
    const content::inventory_state& left,
    const content::inventory_state& right) noexcept {
  if (left.ready != right.ready) {
    return false;
  }
  if (!left.ready) {
    return left.reason == right.reason;
  }
  const auto& a = left.snapshot;
  const auto& b = right.snapshot;
  return a.open == b.open &&
      a.current_weight == b.current_weight &&
      a.maximum_weight == b.maximum_weight &&
      a.grid_rows == b.grid_rows &&
      a.grid_columns == b.grid_columns &&
      a.items == b.items &&
      a.active_position == b.active_position;
}

}  // namespace

inventory_observation_worker::inventory_observation_worker(
    std::unique_ptr<inventory_sampler> sampler,
    const std::chrono::milliseconds interval)
    : sampler_(std::move(sampler)), interval_(interval) {
  if (sampler_ == nullptr || interval_ <= std::chrono::milliseconds::zero()) {
    throw std::invalid_argument("inventory_observation_worker_invalid");
  }
  worker_ = std::jthread(
      [this](const std::stop_token cancellation) { run(cancellation); });
}

inventory_observation_worker::~inventory_observation_worker() {
  stop();
}

std::optional<inventory_publication> inventory_observation_worker::poll() {
  std::scoped_lock lock(mutex_);
  if (!latest_.has_value() || latest_->revision <= delivered_revision_) {
    return std::nullopt;
  }
  delivered_revision_ = latest_->revision;
  return latest_;
}

void inventory_observation_worker::stop() noexcept {
  if (!worker_.joinable()) {
    return;
  }
  worker_.request_stop();
  worker_.join();
}

void inventory_observation_worker::run(
    const std::stop_token cancellation) noexcept {
  while (!cancellation.stop_requested()) {
    const auto now_ms = monotonic_milliseconds();
    content::inventory_state observed;
    try {
      observed = sampler_->sample(now_ms, cancellation);
    } catch (...) {
      observed = {false, "inventory_source_failed", {}};
    }
    if (cancellation.stop_requested()) {
      return;
    }

    {
      std::scoped_lock lock(mutex_);
      if (!latest_.has_value() ||
          !same_visible_state(latest_->state, observed)) {
        if (next_revision_ == std::numeric_limits<std::uint64_t>::max()) {
          return;
        }
        latest_ = inventory_publication{
            next_revision_++, now_ms, std::move(observed)};
      }
    }

    auto remaining = interval_;
    constexpr auto slice = std::chrono::milliseconds(25);
    while (!cancellation.stop_requested() && remaining.count() > 0) {
      const auto wait = std::min(remaining, slice);
      std::this_thread::sleep_for(wait);
      remaining -= wait;
    }
  }
}

}  // namespace sonar::fishing::engine_ipc
