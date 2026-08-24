#include "sonar/fishing/inventory_store/inventory_store_episode.h"

#include <algorithm>
#include <charconv>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <stop_token>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#ifndef SONAR_FISHING_INVENTORY_STORE_FIXTURE
#error SONAR_FISHING_INVENTORY_STORE_FIXTURE is required
#endif

namespace inventory = sonar::fishing::inventory_store;
namespace stage = sonar::fishing::stage_detection;

namespace {

void require(const bool condition, const std::string_view message) {
  if (!condition) {
    throw std::runtime_error(std::string(message));
  }
}

[[nodiscard]] std::vector<std::string> split(
    const std::string_view value,
    const char delimiter) {
  std::vector<std::string> fields;
  std::size_t start = 0;
  while (start <= value.size()) {
    const auto end = value.find(delimiter, start);
    fields.emplace_back(value.substr(
        start,
        end == std::string_view::npos ? value.size() - start : end - start));
    if (end == std::string_view::npos) {
      break;
    }
    start = end + 1;
  }
  return fields;
}

template <typename Value>
[[nodiscard]] Value parse_number(const std::string_view text) {
  Value value{};
  const auto result = std::from_chars(text.data(), text.data() + text.size(), value);
  require(
      result.ec == std::errc{} && result.ptr == text.data() + text.size(),
      "inventory_fixture_number_invalid");
  return value;
}

[[nodiscard]] bool parse_bool(const std::string_view text) {
  if (text == "true") {
    return true;
  }
  if (text == "false") {
    return false;
  }
  throw std::runtime_error("inventory_fixture_bool_invalid");
}

[[nodiscard]] inventory::inventory_surface parse_surface(
    const std::string_view text) {
  if (text == "gameplay") {
    return inventory::inventory_surface::gameplay;
  }
  if (text == "game_menu") {
    return inventory::inventory_surface::game_menu;
  }
  if (text == "inventory") {
    return inventory::inventory_surface::inventory;
  }
  if (text == "item_context_menu") {
    return inventory::inventory_surface::item_context_menu;
  }
  throw std::runtime_error("inventory_fixture_surface_invalid");
}

[[nodiscard]] stage::observed_fishing_stage parse_stage(
    const std::string_view text) {
  if (text == "none") {
    return stage::observed_fishing_stage::none;
  }
  if (text == "tackle_selection") {
    return stage::observed_fishing_stage::tackle_selection;
  }
  if (text == "casting") {
    return stage::observed_fishing_stage::casting;
  }
  if (text == "waiting_for_bite") {
    return stage::observed_fishing_stage::waiting_for_bite;
  }
  if (text == "reeling") {
    return stage::observed_fishing_stage::reeling;
  }
  throw std::runtime_error("inventory_fixture_stage_invalid");
}

[[nodiscard]] stage::normalized_rect parse_rect(
    const std::vector<std::string>& fields,
    const std::size_t start) {
  require(fields.size() >= start + 4, "inventory_fixture_rect_invalid");
  return {
      .x = parse_number<double>(fields[start]),
      .y = parse_number<double>(fields[start + 1]),
      .width = parse_number<double>(fields[start + 2]),
      .height = parse_number<double>(fields[start + 3]),
  };
}

[[nodiscard]] std::vector<inventory::inventory_item_observation> parse_items(
    const std::string_view text) {
  std::vector<inventory::inventory_item_observation> items;
  if (text == "-") {
    return items;
  }
  for (const auto& encoded : split(text, '&')) {
    const auto fields = split(encoded, '~');
    require(fields.size() == 7, "inventory_fixture_item_invalid");
    items.push_back({
        .instance_id = fields[0],
        .item_id = fields[1],
        .title = fields[1],
        .confidence = parse_number<double>(fields[2]),
        .bounds = parse_rect(fields, 3),
    });
  }
  return items;
}

[[nodiscard]] std::optional<inventory::inventory_context_action_observation>
parse_remove_action(const std::string_view text) {
  if (text == "-") {
    return std::nullopt;
  }
  const auto fields = split(text, '~');
  require(fields.size() == 6, "inventory_fixture_remove_action_invalid");
  return inventory::inventory_context_action_observation{
      .item_instance_id = fields[0],
      .confidence = parse_number<double>(fields[1]),
      .bounds = parse_rect(fields, 2),
  };
}

struct fixture_case final {
  std::string id;
  inventory::inventory_store_request request;
  std::vector<inventory::inventory_observation> observations;
  bool expectation_set{};
  bool expected_ok{};
  std::string expected_reason;
  std::size_t expected_stored_count{};
  std::vector<std::string> expected_intents;
};

[[nodiscard]] std::vector<fixture_case> load_fixture() {
  std::ifstream input(SONAR_FISHING_INVENTORY_STORE_FIXTURE);
  require(input.good(), "inventory_fixture_missing");

  std::vector<fixture_case> cases;
  std::string line;
  require(static_cast<bool>(std::getline(input, line)), "inventory_fixture_empty");
  require(
      line == "case_id\tfish_ids\tresume\tsequence\tsurface\tstage\tcatch_visible\titems\tremove_action\texpected_ok\texpected_reason\texpected_stored_count\texpected_intents",
      "inventory_fixture_header_invalid");

  while (std::getline(input, line)) {
    if (line.empty() || line.front() == '#') {
      continue;
    }
    const auto fields = split(line, '\t');
    require(fields.size() == 13, "inventory_fixture_row_invalid");

    auto found = std::find_if(
        cases.begin(),
        cases.end(),
        [&fields](const auto& item) { return item.id == fields[0]; });
    if (found == cases.end()) {
      fixture_case item;
      item.id = fields[0];
      item.request.fish_to_store =
          fields[1] == "-" ? std::vector<std::string>{} : split(fields[1], ',');
      item.request.resume_fishing = parse_bool(fields[2]);
      cases.push_back(std::move(item));
      found = std::prev(cases.end());
    } else {
      const auto fish =
          fields[1] == "-" ? std::vector<std::string>{} : split(fields[1], ',');
      require(found->request.fish_to_store == fish,
              "inventory_fixture_request_changed");
      require(found->request.resume_fishing == parse_bool(fields[2]),
              "inventory_fixture_resume_changed");
    }

    found->observations.push_back({
        .sequence = parse_number<std::uint64_t>(fields[3]),
        .surface = parse_surface(fields[4]),
        .fishing_stage = parse_stage(fields[5]),
        .catch_screen_visible = parse_bool(fields[6]),
        .items = parse_items(fields[7]),
        .remove_action = parse_remove_action(fields[8]),
    });

    if (fields[9] != "-") {
      require(!found->expectation_set, "inventory_fixture_expectation_duplicate");
      found->expectation_set = true;
      found->expected_ok = parse_bool(fields[9]);
      found->expected_reason = fields[10];
      found->expected_stored_count = parse_number<std::size_t>(fields[11]);
      found->expected_intents =
          fields[12] == "-" ? std::vector<std::string>{} : split(fields[12], ',');
    } else {
      require(fields[10] == "-" && fields[11] == "-" && fields[12] == "-",
              "inventory_fixture_partial_expectation");
    }
  }

  require(cases.size() >= 4, "inventory_fixture_too_small");
  for (const auto& item : cases) {
    require(item.expectation_set, "inventory_fixture_expectation_missing");
    require(!item.observations.empty(), "inventory_fixture_observation_missing");
  }
  return cases;
}

class sequence_observer final : public inventory::inventory_observer {
 public:
  explicit sequence_observer(std::vector<inventory::inventory_observation> source)
      : source_(std::move(source)) {}

  [[nodiscard]] inventory::inventory_observation observe(
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested()) {
      return {.error = "fixture_cancelled"};
    }
    if (cursor_ >= source_.size()) {
      return {.error = "fixture_exhausted"};
    }
    auto value = source_[cursor_++];
    latest_sequence_ = value.sequence;
    return value;
  }

  [[nodiscard]] std::uint64_t latest_sequence() const noexcept {
    return latest_sequence_;
  }

  [[nodiscard]] std::size_t consumed() const noexcept { return cursor_; }

 private:
  std::vector<inventory::inventory_observation> source_;
  std::size_t cursor_{};
  std::uint64_t latest_sequence_{};
};

[[nodiscard]] bool valid_target(const stage::normalized_rect& bounds) noexcept {
  return bounds.width > 0.0 && bounds.height > 0.0 && bounds.x >= 0.0 &&
      bounds.y >= 0.0 && bounds.x + bounds.width <= 1.0 &&
      bounds.y + bounds.height <= 1.0;
}

class recording_mutation_port final : public inventory::inventory_mutation_port {
 public:
  explicit recording_mutation_port(sequence_observer& observer)
      : observer_(observer) {}

  [[nodiscard]] inventory::inventory_mutation_result apply(
      const inventory::inventory_mutation_intent& intent,
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested()) {
      return inventory::inventory_mutation_result::rejected(
          "fixture_cancelled");
    }
    if (intent.expected_observation_sequence != observer_.latest_sequence()) {
      return inventory::inventory_mutation_result::rejected(
          "fixture_final_sequence_gate_failed");
    }
    if (intent.kind == inventory::inventory_intent_kind::pause) {
      if (intent.delay_milliseconds == 0 || intent.packet_count != 0) {
        return inventory::inventory_mutation_result::rejected(
            "fixture_pause_intent_invalid");
      }
    } else if (intent.packet_count == 0 || intent.delay_milliseconds != 0) {
      return inventory::inventory_mutation_result::rejected(
          "fixture_mutation_intent_invalid");
    }
    if ((intent.kind == inventory::inventory_intent_kind::right_click_item ||
         intent.kind == inventory::inventory_intent_kind::click_context_action) &&
        (intent.item_instance_id.empty() || !valid_target(intent.target_bounds))) {
      return inventory::inventory_mutation_result::rejected(
          "fixture_target_intent_invalid");
    }

    intents.push_back(intent);
    if (reject_at.has_value() && intents.size() - 1 == *reject_at) {
      return inventory::inventory_mutation_result::rejected(
          rejection_reason);
    }
    return inventory::inventory_mutation_result::accepted();
  }

  std::vector<inventory::inventory_mutation_intent> intents;
  std::optional<std::size_t> reject_at;
  std::string rejection_reason{"fixture_final_gate_rejected"};

 private:
  sequence_observer& observer_;
};

[[nodiscard]] std::string intent_token(
    const inventory::inventory_mutation_intent& intent) {
  std::string token = inventory::inventory_intent_key(intent.kind);
  if (intent.kind == inventory::inventory_intent_kind::press_key) {
    token += ':' + intent.key;
  } else if (
      intent.kind == inventory::inventory_intent_kind::right_click_item ||
      intent.kind == inventory::inventory_intent_kind::click_context_action) {
    token += ':' + intent.item_instance_id;
  } else if (intent.kind == inventory::inventory_intent_kind::pause) {
    token += ':' + std::to_string(intent.delay_milliseconds);
  }
  return token;
}

[[nodiscard]] inventory::inventory_observation observation(
    const std::uint64_t sequence,
    const inventory::inventory_surface surface,
    const stage::observed_fishing_stage fishing_stage =
        stage::observed_fishing_stage::none) {
  return {
      .sequence = sequence,
      .surface = surface,
      .fishing_stage = fishing_stage,
  };
}

[[nodiscard]] inventory::inventory_item_observation fish(
    std::string instance_id,
    const double confidence = 0.98) {
  return {
      .instance_id = std::move(instance_id),
      .item_id = "rainbow_trout",
      .title = "Rainbow trout",
      .confidence = confidence,
      .bounds = {.x = 0.10, .y = 0.20, .width = 0.12, .height = 0.10},
  };
}

[[nodiscard]] inventory::inventory_context_action_observation remove_action(
    std::string instance_id) {
  return {
      .item_instance_id = std::move(instance_id),
      .confidence = 0.98,
      .bounds = {.x = 0.12, .y = 0.43, .width = 0.20, .height = 0.08},
  };
}

void test_fixture_episodes() {
  const inventory::inventory_store_episode_runner runner;
  for (const auto& item : load_fixture()) {
    sequence_observer observer(item.observations);
    recording_mutation_port mutation(observer);
    const auto result = runner.run(item.request, observer, mutation);

    require(result.ok == item.expected_ok, item.id + ":ok_changed");
    require(result.reason == item.expected_reason,
            item.id + ":reason_changed");
    require(result.stored_count == item.expected_stored_count,
            item.id + ":stored_count_changed");
    require(observer.consumed() == item.observations.size(),
            item.id + ":observation_count_changed");

    std::vector<std::string> actual_intents;
    actual_intents.reserve(mutation.intents.size());
    std::transform(
        mutation.intents.begin(),
        mutation.intents.end(),
        std::back_inserter(actual_intents),
        intent_token);
    require(actual_intents == item.expected_intents,
            item.id + ":intent_sequence_changed");
  }
}

void test_invalid_observation_blocks_before_mutation() {
  auto value = observation(1, inventory::inventory_surface::inventory);
  auto invalid = fish("trout_01");
  invalid.bounds.width = 1.5;
  value.items.push_back(std::move(invalid));
  sequence_observer observer({value});
  recording_mutation_port mutation(observer);

  const auto result = inventory::inventory_store_episode_runner{}.run(
      {.fish_to_store = {"rainbow_trout"}, .resume_fishing = false},
      observer,
      mutation);
  require(!result.ok && result.reason == "inventory_item_observation_invalid",
          "invalid_observation_not_blocked");
  require(mutation.intents.empty(), "invalid_observation_mutated");
}

void test_stale_observation_blocks_episode() {
  sequence_observer observer({
      observation(1, inventory::inventory_surface::gameplay),
      observation(1, inventory::inventory_surface::gameplay),
  });
  recording_mutation_port mutation(observer);

  const auto result = inventory::inventory_store_episode_runner{}.run(
      {.fish_to_store = {"rainbow_trout"}, .resume_fishing = false},
      observer,
      mutation);
  require(!result.ok && result.reason == "inventory_observation_stale",
          "stale_observation_not_blocked");
  require(mutation.intents.size() == 4,
          "stale_observation_mutation_count_changed");
  require(
      mutation.intents.back().kind ==
          inventory::inventory_intent_kind::release_all_keys,
      "stale_observation_cleanup_missing");
}

void test_reeling_transition_never_emits_escape() {
  sequence_observer observer({
      observation(1, inventory::inventory_surface::gameplay),
      observation(2, inventory::inventory_surface::gameplay),
      observation(
          3,
          inventory::inventory_surface::game_menu,
          stage::observed_fishing_stage::reeling),
  });
  recording_mutation_port mutation(observer);

  const auto result = inventory::inventory_store_episode_runner{}.run(
      {.fish_to_store = {"rainbow_trout"}, .resume_fishing = false},
      observer,
      mutation);
  require(!result.ok && result.reason == "inventory_reeling_active",
          "reeling_transition_not_blocked");
  require(
      std::none_of(
          mutation.intents.begin(),
          mutation.intents.end(),
          [](const auto& intent) {
            return intent.kind == inventory::inventory_intent_kind::press_key &&
                intent.key == "esc";
          }),
      "reeling_transition_emitted_escape");
}

void test_final_gate_rejection_stops_without_cleanup_input() {
  sequence_observer observer({
      observation(1, inventory::inventory_surface::inventory),
  });
  recording_mutation_port mutation(observer);
  mutation.reject_at = 0;

  const auto result = inventory::inventory_store_episode_runner{}.run(
      {.fish_to_store = {"rainbow_trout"}, .resume_fishing = false},
      observer,
      mutation);
  require(!result.ok && result.reason == "fixture_final_gate_rejected",
          "final_gate_rejection_changed");
  require(!result.recovery_attempted,
          "final_gate_rejection_cleanup_mutated");
  require(mutation.intents.size() == 1,
          "final_gate_rejection_not_terminal");
}

void test_disabled_adapter_is_fail_closed() {
  sequence_observer observer({
      observation(1, inventory::inventory_surface::inventory),
  });
  inventory::disabled_inventory_mutation_port mutation;
  const auto result = inventory::inventory_store_episode_runner{}.run(
      {.fish_to_store = {"rainbow_trout"}, .resume_fishing = false},
      observer,
      mutation);
  require(!result.ok && result.reason == "inventory_live_adapter_disabled",
          "disabled_adapter_not_fail_closed");
  require(!result.recovery_attempted,
          "disabled_adapter_attempted_recovery");
}

void test_removal_timeout_runs_bounded_cleanup() {
  auto first = observation(1, inventory::inventory_surface::inventory);
  first.items.push_back(fish("trout_01"));
  std::vector<inventory::inventory_observation> source{first};
  for (std::uint64_t sequence = 2; sequence <= 5; ++sequence) {
    auto context = observation(
        sequence, inventory::inventory_surface::item_context_menu);
    context.items.push_back(fish("trout_01"));
    context.remove_action = remove_action("trout_01");
    source.push_back(std::move(context));
  }
  auto recovered_inventory =
      observation(6, inventory::inventory_surface::inventory);
  recovered_inventory.items.push_back(fish("trout_01"));
  source.push_back(std::move(recovered_inventory));
  source.push_back(observation(7, inventory::inventory_surface::gameplay));

  sequence_observer observer(std::move(source));
  recording_mutation_port mutation(observer);
  const auto result = inventory::inventory_store_episode_runner{}.run(
      {.fish_to_store = {"rainbow_trout"}, .resume_fishing = false},
      observer,
      mutation);
  require(!result.ok && result.reason == "inventory_removal_not_confirmed",
          "removal_timeout_reason_changed");
  require(result.stored_count == 0, "unconfirmed_removal_counted");
  require(result.recovery_attempted && result.recovery_completed,
          "removal_timeout_recovery_changed");
  require(observer.consumed() == 7, "removal_timeout_not_bounded");
}

void test_other_item_loss_does_not_confirm_target_removal() {
  auto initial = observation(1, inventory::inventory_surface::inventory);
  initial.items.push_back(fish("trout_01"));
  initial.items.push_back(fish("trout_02"));

  auto context = observation(
      2, inventory::inventory_surface::item_context_menu);
  context.items = initial.items;
  context.remove_action = remove_action("trout_01");

  auto wrong_item_removed =
      observation(3, inventory::inventory_surface::inventory);
  wrong_item_removed.items.push_back(fish("trout_01"));

  sequence_observer observer({
      std::move(initial),
      std::move(context),
      std::move(wrong_item_removed),
      observation(4, inventory::inventory_surface::gameplay),
  });
  recording_mutation_port mutation(observer);
  const auto result = inventory::inventory_store_episode_runner{}.run(
      {.fish_to_store = {"rainbow_trout"}, .resume_fishing = false},
      observer,
      mutation);
  require(
      !result.ok &&
          result.reason == "inventory_target_removal_not_confirmed",
      "wrong_item_loss_confirmed_target");
  require(result.stored_count == 0, "wrong_item_loss_counted");
  require(result.recovery_attempted && result.recovery_completed,
          "wrong_item_loss_recovery_changed");
}

void test_default_inventory_tab_open_retry_is_bounded() {
  std::vector<inventory::inventory_observation> source;
  for (std::uint64_t sequence = 1; sequence <= 9; ++sequence) {
    source.push_back(observation(
        sequence, inventory::inventory_surface::gameplay));
  }
  sequence_observer observer(std::move(source));
  recording_mutation_port mutation(observer);

  const auto result = inventory::inventory_store_episode_runner{}.run(
      {.fish_to_store = {"rainbow_trout"}, .resume_fishing = false},
      observer,
      mutation);
  require(!result.ok && result.reason == "inventory_open_not_confirmed",
          "open_retry_reason_changed");
  require(observer.consumed() == 9, "open_retry_observation_bound_changed");
  require(
      std::count_if(
          mutation.intents.begin(),
          mutation.intents.end(),
          [](const auto& intent) {
            return intent.kind == inventory::inventory_intent_kind::press_key &&
                intent.key == "tab";
          }) == 2,
      "default_inventory_tab_open_retry_changed");
}

void test_cancellation_and_invalid_request_are_input_free() {
  inventory::inventory_store_episode_runner runner;
  sequence_observer cancelled_observer({});
  recording_mutation_port cancelled_mutation(cancelled_observer);
  std::stop_source source;
  source.request_stop();
  const auto cancelled = runner.run(
      {.fish_to_store = {"rainbow_trout"}},
      cancelled_observer,
      cancelled_mutation,
      source.get_token());
  require(!cancelled.ok && cancelled.reason == "inventory_cancelled",
          "cancellation_reason_changed");
  require(cancelled_observer.consumed() == 0 &&
              cancelled_mutation.intents.empty(),
          "cancelled_episode_touched_boundary");

  sequence_observer invalid_observer({});
  recording_mutation_port invalid_mutation(invalid_observer);
  const auto invalid = runner.run(
      {.fish_to_store = {"invalid fish id"}},
      invalid_observer,
      invalid_mutation);
  require(!invalid.ok && invalid.reason == "inventory_item_id_invalid",
          "invalid_request_reason_changed");
  require(invalid_observer.consumed() == 0 && invalid_mutation.intents.empty(),
          "invalid_request_touched_boundary");
}

}  // namespace

int main() {
  try {
    test_fixture_episodes();
    test_invalid_observation_blocks_before_mutation();
    test_stale_observation_blocks_episode();
    test_reeling_transition_never_emits_escape();
    test_final_gate_rejection_stops_without_cleanup_input();
    test_disabled_adapter_is_fail_closed();
    test_removal_timeout_runs_bounded_cleanup();
    test_other_item_loss_does_not_confirm_target_removal();
    test_default_inventory_tab_open_retry_is_bounded();
    test_cancellation_and_invalid_request_are_input_free();
    std::cout << "inventory store tests passed\n";
    return 0;
  } catch (const std::exception& error) {
    std::cerr << "inventory store tests failed: " << error.what() << '\n';
    return 1;
  }
}
