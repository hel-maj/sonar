#include "sonar/fishing/runtime_safety/runtime_safety.h"

#include <Windows.h>

#include <iostream>
#include <stdexcept>
#include <string_view>

namespace {

namespace safety = sonar::fishing::runtime_safety;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

void product_prerequisites_fail_closed_in_stable_order() {
  safety::action_request request{
      .entitlement_valid = false,
      .settings_current = false,
      .lifecycle_allows_input = false,
      .packet_count = 0,
  };
  require(
      safety::validate_product_prerequisites(request) ==
          safety::action_reason::entitlement_invalid,
      "entitlement_gate_order_changed");
  request.entitlement_valid = true;
  require(
      safety::validate_product_prerequisites(request) ==
          safety::action_reason::settings_not_current,
      "settings_gate_order_changed");
  request.settings_current = true;
  require(
      safety::validate_product_prerequisites(request) ==
          safety::action_reason::lifecycle_not_actionable,
      "lifecycle_gate_order_changed");
  request.lifecycle_allows_input = true;
  require(
      safety::validate_product_prerequisites(request) ==
          safety::action_reason::invalid_packet_count,
      "zero_packet_action_accepted");
  request.packet_count = 2;
  require(
      safety::validate_product_prerequisites(request) ==
          safety::action_reason::ready,
      "valid_product_prerequisites_rejected");
}

void common_packet_budget_is_the_only_budget_mechanism() {
  sonar::platform::input::input_packet_budget budget(3);
  require(
      safety::reserve_packet_budget(budget, 2) == safety::action_reason::ready,
      "initial_packet_reservation_failed");
  require(budget.remaining_packets() == 1, "packet_budget_usage_changed");
  require(
      safety::reserve_packet_budget(budget, 2) ==
          safety::action_reason::packet_budget_exhausted,
      "packet_budget_overrun_accepted");
  require(budget.reserved_packets() == 2, "failed_reservation_mutated_budget");
}

void invalid_window_attach_fails_without_external_observation() {
  safety::attach_reason reason = safety::attach_reason::ready;
  const auto guard = safety::runtime_target_guard::attach(
      GetCurrentProcessId(),
      0,
      8,
      reason);
  require(!guard, "invalid_window_created_runtime_guard");
  require(reason == safety::attach_reason::invalid_argument,
          "invalid_window_reason_changed");
}

int run() {
  product_prerequisites_fail_closed_in_stable_order();
  common_packet_budget_is_the_only_budget_mechanism();
  invalid_window_attach_fails_without_external_observation();
  std::cout << "PASS Fishing runtime target and input preflight policy\n";
  return 0;
}

}  // namespace

int main() {
  try {
    return run();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
