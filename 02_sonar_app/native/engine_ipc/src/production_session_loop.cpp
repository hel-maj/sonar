#include "sonar/fishing/engine_ipc/production_session_loop.h"

#include <exception>
#include <limits>
#include <string_view>
#include <utility>

namespace sonar::fishing::engine_ipc {
namespace {

[[nodiscard]] production_session_result failure(
    const production_session_result& current,
    std::string reason) {
  auto result = current;
  result.reason = reason.empty()
      ? "production_session_step_failed"
      : std::move(reason);
  return result;
}

[[nodiscard]] bool valid_request(
    const production_session_request& request) noexcept {
  return request.settings.revision != 0U &&
      request.entitlement_generation != 0U &&
      request.entitlement_expires_unix_seconds > 0 &&
      request.lifecycle_revision != 0U &&
      request.maximum_cycles != 0U &&
      request.maximum_cycles <= maximum_production_session_cycles &&
      runtime_settings::Validate(request.settings).empty();
}

}  // namespace

production_step_result production_step_result::completed(
    const bool performed,
    const bool session_complete) {
  return {
      .ok = true,
      .performed = performed,
      .session_complete = session_complete,
  };
}

production_step_result production_step_result::rejected(std::string reason) {
  return {.reason = std::move(reason)};
}

production_session_result production_session_loop::run(
    const production_session_request& request,
    production_cycle_port& port,
    const std::stop_token stop_token) const {
  production_session_result result;
  if (!valid_request(request)) {
    result.reason = "production_session_request_invalid";
    return result;
  }
  for (std::size_t cycle = 0U; cycle < request.maximum_cycles; ++cycle) {
    if (stop_token.stop_requested()) {
      result.ok = true;
      result.stopped = true;
      result.reason = "production_session_stopped";
      return result;
    }
    if (request.lifecycle_revision >
        (std::numeric_limits<std::uint64_t>::max)() - cycle) {
      return failure(result, "production_cycle_identity_exhausted");
    }
    const auto identity = request.lifecycle_revision + cycle;
    fishing_episode::fishing_episode_result fishing;
    try {
      fishing = port.run_fishing(request, identity, stop_token);
    } catch (const std::exception& error) {
      return failure(result,
          std::string("production_fishing_failed:") + error.what());
    } catch (...) {
      return failure(result, "production_fishing_failed:unknown");
    }
    if (!fishing.ok) {
      if (stop_token.stop_requested() ||
          fishing.reason == "fishing_episode_cancelled") {
        result.ok = true;
        result.stopped = true;
        result.reason = "production_session_stopped";
        return result;
      }
      return failure(result, fishing.reason);
    }
    if (fishing.outcome != fishing_episode::fishing_episode_outcome::catch_visible) {
      ++result.cycles_completed;
      continue;
    }

    const auto execute = [&](auto&& operation, const std::string_view fallback)
        -> production_step_result {
      try {
        return operation();
      } catch (const std::exception& error) {
        return production_step_result::rejected(
            std::string(fallback) + ':' + error.what());
      } catch (...) {
        return production_step_result::rejected(
            std::string(fallback) + ":unknown");
      }
    };
    auto catch_result = execute(
        [&] { return port.process_catch(
            request, identity, fishing, stop_token); },
        "production_catch_failed");
    if (!catch_result.ok) {
      return failure(result, std::move(catch_result.reason));
    }
    if (catch_result.performed) {
      ++result.catches_processed;
    }
    if (catch_result.session_complete) {
      ++result.cycles_completed;
      result.ok = true;
      result.reason = "production_session_completed";
      return result;
    }

    auto inventory = execute(
        [&] { return port.run_inventory(
            request, identity, stop_token); },
        "production_inventory_failed");
    if (!inventory.ok) {
      return failure(result, std::move(inventory.reason));
    }
    if (inventory.performed) {
      ++result.inventory_episodes_completed;
    }
    if (inventory.session_complete) {
      ++result.cycles_completed;
      result.ok = true;
      result.reason = "production_session_completed";
      return result;
    }

    auto maintenance = execute(
        [&] { return port.run_maintenance(
            request, identity, stop_token); },
        "production_maintenance_failed");
    if (!maintenance.ok) {
      return failure(result, std::move(maintenance.reason));
    }
    if (maintenance.performed) {
      ++result.maintenance_episodes_completed;
    }
    ++result.cycles_completed;
    if (maintenance.session_complete) {
      result.ok = true;
      result.reason = "production_session_completed";
      return result;
    }
  }
  result.reason = "production_session_cycle_limit_reached";
  return result;
}

}  // namespace sonar::fishing::engine_ipc
