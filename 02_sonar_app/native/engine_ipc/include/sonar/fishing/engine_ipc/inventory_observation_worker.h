#pragma once

#include <chrono>
#include <cstdint>
#include <memory>
#include <mutex>
#include <optional>
#include <stop_token>
#include <thread>

#include "sonar/majestic/cef_inventory/content/snapshot.hpp"

namespace sonar::fishing::engine_ipc {

class inventory_sampler {
 public:
  virtual ~inventory_sampler() = default;

  [[nodiscard]] virtual
      sonar::majestic::cef_inventory::content::inventory_state sample(
          std::uint64_t now_ms,
          std::stop_token cancellation) = 0;
};

[[nodiscard]] std::unique_ptr<inventory_sampler>
create_win32_inventory_sampler(bool observation_enabled);

struct inventory_publication final {
  std::uint64_t revision{};
  std::uint64_t observed_at_ms{};
  sonar::majestic::cef_inventory::content::inventory_state state;
};

// Keeps slow read-only discovery away from the Host control/heartbeat pipe.
// Only a changed aggregate state crosses to the main Engine loop; source
// revision/timestamps never become product-session IPC identity.
class inventory_observation_worker final {
 public:
  explicit inventory_observation_worker(
      std::unique_ptr<inventory_sampler> sampler,
      std::chrono::milliseconds interval = std::chrono::milliseconds(500));
  ~inventory_observation_worker();

  inventory_observation_worker(const inventory_observation_worker&) = delete;
  inventory_observation_worker& operator=(
      const inventory_observation_worker&) = delete;

  [[nodiscard]] std::optional<inventory_publication> poll();
  void stop() noexcept;

 private:
  void run(std::stop_token cancellation) noexcept;

  std::unique_ptr<inventory_sampler> sampler_;
  std::chrono::milliseconds interval_;
  std::mutex mutex_;
  std::optional<inventory_publication> latest_;
  std::uint64_t next_revision_{1U};
  std::uint64_t delivered_revision_{};
  std::jthread worker_;
};

}  // namespace sonar::fishing::engine_ipc
