#include "sonar/fishing/runtime_settings/runtime_settings.h"

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string_view>

namespace {

namespace settings = sonar::fishing::runtime_settings;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

[[nodiscard]] settings::RuntimeSettingsSnapshot valid_snapshot(
    const std::uint64_t revision) {
  settings::RuntimeSettingsSnapshot result;
  result.revision = revision;
  result.fish_keep_policy.emplace("marlin", true);
  result.garbage_disposal_policy.emplace("bag", true);
  result.custom_fish_prices.emplace("marlin", 700.0);
  return result;
}

void hotkey_contract_is_strict_and_stable() {
  require(settings::IsValidHotkey("F9"), "function_key_rejected");
  require(settings::IsValidHotkey("ctrl+alt+t"), "modifier_combo_rejected");
  require(settings::IsValidHotkey("Ctrl+Tab"), "named_key_case_rejected");
  require(settings::IsValidHotkey("space"), "named_key_rejected");
  require(!settings::IsValidHotkey(""), "empty_hotkey_accepted");
  require(!settings::IsValidHotkey("F25"), "invalid_function_key_accepted");
  require(!settings::IsValidHotkey("ctrl+ctrl+t"), "duplicate_modifier_accepted");
  require(!settings::IsValidHotkey("t+q"), "multiple_base_keys_accepted");
  require(!settings::IsValidHotkey("ctrl + t"), "spacey_wire_value_accepted");
}

void full_snapshot_applies_atomically() {
  settings::RuntimeSettingsOwner owner;
  auto first = valid_snapshot(1);
  first.restore_food_from = 12;
  first.fish_keep_policy.emplace("albula", false);
  const auto accepted = owner.Apply(first);
  require(accepted.accepted(), "valid_snapshot_rejected");
  require(accepted.accepted_revision == 1, "accepted_revision_changed");

  auto invalid = valid_snapshot(2);
  invalid.restore_water_from = 91;
  invalid.fish_keep_policy["marlin"] = false;
  const auto rejected = owner.Apply(invalid);
  require(
      rejected.status == settings::ApplyStatus::invalid_snapshot,
      "invalid_snapshot_accepted");
  require(
      rejected.reason == "settings_threshold_out_of_range",
      "invalid_reason_changed");
  const auto current = owner.Current();
  require(current.has_value(), "accepted_snapshot_lost");
  require(current->revision == 1, "invalid_snapshot_mutated_revision");
  require(current->restore_food_from == 12, "invalid_snapshot_partially_mutated");
  require(current->fish_keep_policy.at("marlin"), "invalid_policy_partially_mutated");
}

void stale_and_equal_revisions_are_rejected() {
  settings::RuntimeSettingsOwner owner;
  require(owner.Apply(valid_snapshot(5)).accepted(), "initial_snapshot_rejected");
  for (const std::uint64_t revision : {5ULL, 4ULL, 1ULL}) {
    const auto result = owner.Apply(valid_snapshot(revision));
    require(
        result.status == settings::ApplyStatus::stale_revision,
        "stale_revision_accepted");
    require(result.accepted_revision == 5, "stale_revision_changed_owner");
  }
  require(owner.Apply(valid_snapshot(9)).accepted(), "revision_gap_rejected");
  require(owner.AcceptedRevision() == 9, "revision_gap_not_applied");
}

void invalid_policy_values_fail_closed() {
  settings::RuntimeSettingsOwner owner;

  auto empty_identifier = valid_snapshot(1);
  empty_identifier.fish_keep_policy.emplace("", true);
  require(
      owner.Apply(empty_identifier).reason == "settings_policy_identifier_invalid",
      "empty_identifier_accepted");

  auto invalid_price = valid_snapshot(1);
  invalid_price.custom_fish_prices["marlin"] = -1.0;
  require(
      owner.Apply(invalid_price).reason == "settings_custom_price_invalid",
      "negative_price_accepted");

  invalid_price.custom_fish_prices["marlin"] =
      std::numeric_limits<double>::quiet_NaN();
  require(
      owner.Apply(invalid_price).reason == "settings_custom_price_invalid",
      "nan_price_accepted");

  auto invalid_hotkey = valid_snapshot(1);
  invalid_hotkey.chat_hotkey = "mouse4";
  require(
      owner.Apply(invalid_hotkey).reason == "settings_hotkey_invalid",
      "invalid_hotkey_accepted");
  require(owner.AcceptedRevision() == 0, "invalid_state_was_retained");

  auto conflicting_hotkeys = valid_snapshot(1);
  conflicting_hotkeys.start_stop_hotkey = "ctrl+shift+t";
  conflicting_hotkeys.inventory_hotkey = "Shift+Control+T";
  require(
      owner.Apply(conflicting_hotkeys).reason == "settings_hotkey_conflict",
      "semantically_duplicate_hotkeys_accepted");
  require(owner.AcceptedRevision() == 0, "conflicting_hotkeys_were_retained");
}

int run() {
  hotkey_contract_is_strict_and_stable();
  full_snapshot_applies_atomically();
  stale_and_equal_revisions_are_rejected();
  invalid_policy_values_fail_closed();
  std::cout << "PASS Fishing runtime settings revision and validation gates\n";
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
