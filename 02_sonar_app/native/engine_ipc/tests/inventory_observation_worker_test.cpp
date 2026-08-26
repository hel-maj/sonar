#include "sonar/fishing/engine_ipc/inventory_observation_worker.h"

#include <atomic>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <optional>
#include <string_view>
#include <thread>
#include <utility>

namespace {

namespace content = sonar::majestic::cef_inventory::content;
using sonar::fishing::engine_ipc::inventory_observation_worker;
using sonar::fishing::engine_ipc::inventory_publication;
using sonar::fishing::engine_ipc::inventory_sampler;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    std::cerr << "FAIL " << reason << '\n';
    std::exit(1);
  }
}

[[nodiscard]] content::inventory_state ready_state(
    const std::uint64_t revision,
    const std::uint64_t observed_at_ms) {
  content::item_snapshot item;
  item.runtime_id = "instance-1";
  item.instance_id = 1U;
  item.catalog_item_id = 246U;
  item.name = "Knife";
  item.column_span = 1U;
  item.row_span = 1U;
  item.count = 1U;
  content::inventory_snapshot snapshot;
  snapshot.revision = revision;
  snapshot.observed_at_ms = observed_at_ms;
  snapshot.current_weight = 19.9;
  snapshot.maximum_weight = 100.0;
  snapshot.items.push_back(std::move(item));
  return {true, "ready", std::move(snapshot)};
}

class sequence_sampler final : public inventory_sampler {
 public:
  [[nodiscard]] content::inventory_state sample(
      const std::uint64_t now_ms,
      std::stop_token cancellation) override {
    if (cancellation.stop_requested()) {
      return {false, "inventory_cancelled", {}};
    }
    const auto call = calls_.fetch_add(1U);
    if (call < 2U) {
      return {false, "inventory_missing", {}};
    }
    return ready_state(call, now_ms);
  }

  [[nodiscard]] std::uint32_t calls() const noexcept {
    return calls_.load();
  }

 private:
  std::atomic<std::uint32_t> calls_{};
};

class cancellable_sampler final : public inventory_sampler {
 public:
  explicit cancellable_sampler(std::atomic<bool>& entered) : entered_(entered) {}

  [[nodiscard]] content::inventory_state sample(
      std::uint64_t,
      const std::stop_token cancellation) override {
    entered_.store(true);
    while (!cancellation.stop_requested()) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    return {false, "inventory_cancelled", {}};
  }

 private:
  std::atomic<bool>& entered_;
};

[[nodiscard]] std::optional<inventory_publication> wait_for_publication(
    inventory_observation_worker& worker,
    const std::uint64_t minimum_revision) {
  const auto deadline = std::chrono::steady_clock::now() +
      std::chrono::seconds(2);
  while (std::chrono::steady_clock::now() < deadline) {
    if (auto value = worker.poll();
        value.has_value() && value->revision >= minimum_revision) {
      return value;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  return std::nullopt;
}

void deduplicates_source_identity_only_changes() {
  auto sampler = std::make_unique<sequence_sampler>();
  auto* sampler_view = sampler.get();
  inventory_observation_worker worker(
      std::move(sampler), std::chrono::milliseconds(2));
  const auto unavailable = wait_for_publication(worker, 1U);
  require(
      unavailable.has_value() && unavailable->revision == 1U &&
          !unavailable->state.ready,
      "initial_unavailable_publication_missing");
  const auto ready = wait_for_publication(worker, 2U);
  require(
      ready.has_value() && ready->revision == 2U && ready->state.ready,
      "ready_transition_publication_missing");
  while (sampler_view->calls() < 6U) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  require(
      !worker.poll().has_value(),
      "unchanged_content_was_republished_from_source_revision_only");
  worker.stop();
}

void cancellation_bounds_worker_shutdown() {
  std::atomic<bool> entered{};
  auto worker = std::make_unique<inventory_observation_worker>(
      std::make_unique<cancellable_sampler>(entered),
      std::chrono::seconds(1));
  const auto deadline = std::chrono::steady_clock::now() +
      std::chrono::seconds(2);
  while (!entered.load() && std::chrono::steady_clock::now() < deadline) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  require(entered.load(), "blocking_sampler_was_not_entered");
  const auto started = std::chrono::steady_clock::now();
  worker.reset();
  require(
      std::chrono::steady_clock::now() - started < std::chrono::seconds(1),
      "worker_shutdown_did_not_cancel_source");
}

}  // namespace

int main() {
  deduplicates_source_identity_only_changes();
  cancellation_bounds_worker_shutdown();
  std::cout << "PASS Fishing inventory observation worker\n";
  return 0;
}
