#include "sonar/fishing/automation_adapters/common_inventory_open.h"

#include <chrono>
#include <exception>
#include <utility>

#include "sonar/majestic/cef_inventory/inventory_open.hpp"

namespace sonar::fishing::automation_adapters {
namespace {

[[nodiscard]] std::string map_reason(
    const sonar::majestic::cef_inventory::reason_category reason) {
  if (reason == sonar::majestic::cef_inventory::reason_category::ready) {
    return {};
  }
  std::string mapped{"production_inventory_"};
  mapped.append(sonar::majestic::cef_inventory::reason_name(reason));
  return mapped;
}

class common_inventory_open_source final : public inventory_open_source {
 public:
  common_inventory_open_source() {
    sonar::majestic::cef_inventory::acquisition_policy policy;
    // A coherent semantic CLOSED root remains useful to Fishing, but this
    // never bypasses Common's trusted-publisher and file/process proof.
    policy.allow_closed_open_state_bootstrap = true;
    acquisition_ = sonar::majestic::cef_inventory::
        create_win32_trusted_publisher_inventory_open_acquisition(
            policy, true);
  }

  [[nodiscard]] inventory_open_source_result capture(
      const sonar::platform::windows::process_generation& game_generation)
      noexcept override {
    if (!acquisition_) {
      return {.reason = "production_inventory_source_unavailable"};
    }
    try {
      // Common performs its own bounded cold-to-hot discovery and coherent
      // double-read. Fishing calls the facade exactly once per requested
      // non-reeling aggregate capture.
      const auto observed = acquisition_->observe();
      if (!observed.known() ||
          observed.reason !=
              sonar::majestic::cef_inventory::reason_category::ready) {
        auto reason = map_reason(observed.reason);
        return {
            .reason = reason.empty()
                ? "production_inventory_state_unknown"
                : std::move(reason),
        };
      }
      {
        auto process = sonar::platform::windows::readonly_process::open(
            game_generation.process_id,
            sonar::platform::windows::process_access_profile::identity);
        if (!process.generation_matches(game_generation)) {
          acquisition_->reset();
          return {.reason = "production_inventory_game_generation_changed"};
        }
      }
      return {
          .state = observed.state,
          .binding_hot = observed.binding_hot,
          .reason = map_reason(observed.reason),
      };
    } catch (const sonar::platform::windows::process_error&) {
      acquisition_->reset();
      return {.reason = "production_inventory_game_generation_unavailable"};
    } catch (const std::exception&) {
      acquisition_->reset();
      return {.reason = "production_inventory_capture_failed"};
    } catch (...) {
      acquisition_->reset();
      return {.reason = "production_inventory_capture_failed"};
    }
  }

  void reset() noexcept override {
    if (acquisition_) {
      acquisition_->reset();
    }
  }

 private:
  std::unique_ptr<sonar::majestic::cef_inventory::inventory_open_acquisition>
      acquisition_;
};

class steady_inventory_retry_clock final : public inventory_retry_clock {
 public:
  [[nodiscard]] std::uint64_t now_steady_ns() const noexcept override {
    const auto value = std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count();
    return value > 0 ? static_cast<std::uint64_t>(value) : 0U;
  }
};

}  // namespace

std::unique_ptr<inventory_open_source> make_common_inventory_open_source()
    noexcept {
  try {
    return std::make_unique<common_inventory_open_source>();
  } catch (...) {
    return nullptr;
  }
}

std::unique_ptr<inventory_retry_clock> make_inventory_retry_clock() noexcept {
  try {
    return std::make_unique<steady_inventory_retry_clock>();
  } catch (...) {
    return nullptr;
  }
}

}  // namespace sonar::fishing::automation_adapters
