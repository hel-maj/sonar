#include "sonar/fishing/engine_ipc/inventory_observation_worker.h"

#include <memory>
#include <stdexcept>

#include "sonar/majestic/cef_inventory/content/win32_provider.hpp"

namespace sonar::fishing::engine_ipc {
namespace {

namespace content = sonar::majestic::cef_inventory::content;

class common_inventory_sampler final : public inventory_sampler {
 public:
  explicit common_inventory_sampler(const bool observation_enabled)
      : provider_(
            content::create_win32_trusted_publisher_inventory_content_provider(
                5'000U,
                {},
                observation_enabled)) {
    if (provider_ == nullptr) {
      throw std::runtime_error("inventory_provider_missing");
    }
  }

  [[nodiscard]] content::inventory_state sample(
      const std::uint64_t now_ms,
      const std::stop_token cancellation) override {
    return provider_->sample(now_ms, cancellation);
  }

 private:
  std::unique_ptr<content::provider> provider_;
};

}  // namespace

std::unique_ptr<inventory_sampler> create_win32_inventory_sampler(
    const bool observation_enabled) {
  return std::make_unique<common_inventory_sampler>(observation_enabled);
}

}  // namespace sonar::fishing::engine_ipc
