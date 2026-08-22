#include "sonar/fishing/fishing_episode/fishing_episode.h"

#include <algorithm>
#include <charconv>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>
#include <stop_token>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#ifndef SONAR_FISHING_EPISODE_FIXTURE
#error SONAR_FISHING_EPISODE_FIXTURE is required
#endif

namespace episode = sonar::fishing::fishing_episode;
namespace memory = sonar::fishing::memory_observation;
namespace reeling = sonar::fishing::reeling_control;
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
  std::size_t start = 0U;
  while (start <= value.size()) {
    const auto end = value.find(delimiter, start);
    fields.emplace_back(value.substr(
        start,
        end == std::string_view::npos ? value.size() - start : end - start));
    if (end == std::string_view::npos) {
      break;
    }
    start = end + 1U;
  }
  return fields;
}

template <typename Value>
[[nodiscard]] Value parse_integer(const std::string_view text) {
  Value value{};
  const auto result =
      std::from_chars(text.data(), text.data() + text.size(), value);
  require(
      result.ec == std::errc{} && result.ptr == text.data() + text.size(),
      "fishing_fixture_integer_invalid");
  return value;
}

[[nodiscard]] double parse_double(const std::string_view text) {
  std::size_t consumed = 0U;
  const double value = std::stod(std::string(text), &consumed);
  require(consumed == text.size(), "fishing_fixture_double_invalid");
  return value;
}

[[nodiscard]] bool parse_bool(const std::string_view text) {
  if (text == "true") {
    return true;
  }
  if (text == "false") {
    return false;
  }
  throw std::runtime_error("fishing_fixture_bool_invalid");
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
  throw std::runtime_error("fishing_fixture_stage_invalid");
}

[[nodiscard]] episode::hook_cue parse_hook(const std::string_view text) {
  if (text == "none") {
    return episode::hook_cue::none;
  }
  if (text == "red") {
    return episode::hook_cue::red;
  }
  if (text == "bubbles") {
    return episode::hook_cue::bubbles;
  }
  throw std::runtime_error("fishing_fixture_hook_invalid");
}

[[nodiscard]] episode::fishing_episode_outcome parse_outcome(
    const std::string_view text) {
  if (text == "none") {
    return episode::fishing_episode_outcome::none;
  }
  if (text == "memory_finished") {
    return episode::fishing_episode_outcome::memory_finished;
  }
  if (text == "catch_visible") {
    return episode::fishing_episode_outcome::catch_visible;
  }
  throw std::runtime_error("fishing_fixture_outcome_invalid");
}

[[nodiscard]] std::optional<stage::stage_observation> stage_observation(
    const std::string_view stage_text,
    const std::string_view trigger) {
  const auto value = parse_stage(stage_text);
  if (value == stage::observed_fishing_stage::none) {
    require(trigger == "-", "fishing_fixture_none_trigger_invalid");
    return std::nullopt;
  }
  return stage::stage_observation{
      .stage = value,
      .trigger_id = std::string(trigger),
      .confidence = 0.99,
      .bounds = {.x = 0.10, .y = 0.10, .width = 0.30, .height = 0.15},
  };
}

[[nodiscard]] std::optional<memory::coherent_memory_snapshot> memory_snapshot(
    const std::vector<std::string>& fields) {
  if (!parse_bool(fields[10])) {
    for (std::size_t index = 11U; index <= 17U; ++index) {
      require(fields[index] == "-", "fishing_fixture_memory_fields_present");
    }
    return std::nullopt;
  }
  const double player_x = parse_double(fields[12]);
  const double player_y = parse_double(fields[13]);
  const double fish_x = parse_double(fields[14]);
  const double fish_y = parse_double(fields[15]);
  const double right_x = parse_double(fields[16]);
  const double right_y = parse_double(fields[17]);
  return memory::coherent_memory_snapshot{
      .sequence = parse_integer<std::uint64_t>(fields[2]),
      .captured_at_steady_ns = parse_integer<std::uint64_t>(fields[3]),
      .profile_id = "fixture-e11",
      .profile_revision = 1U,
      .game_generation = {
          .process_id = 77U,
          .creation_time_filetime_100ns = 88U,
      },
      .reeling = memory::reeling_evidence{
          .active = parse_bool(fields[11]),
          .fish_model_confirmed = true,
          .player_position = {.x = player_x, .y = player_y, .z = 0.0},
          .fish_position = {.x = fish_x, .y = fish_y, .z = 0.0},
          .player_right_x = right_x,
          .player_right_y = right_y,
          .distance = std::hypot(fish_x - player_x, fish_y - player_y),
      },
  };
}

struct fixture_case final {
  std::string id;
  episode::fishing_episode_request request;
  std::vector<episode::fishing_episode_observation> observations;
  bool expectation_set{};
  bool expected_ok{};
  std::string expected_reason;
  episode::fishing_episode_outcome expected_outcome{
      episode::fishing_episode_outcome::none};
  std::vector<std::string> expected_intents;
};

[[nodiscard]] episode::fishing_episode_request base_request() {
  return {
      .automation_enabled = true,
      .reeling_input_enabled = true,
      .accepted_settings_revision = 101U,
      .expected_entitlement_revision = 202U,
      .expected_lifecycle_revision = 303U,
      .episode_identity = 404U,
  };
}

[[nodiscard]] std::vector<fixture_case> load_fixture() {
  std::ifstream input(SONAR_FISHING_EPISODE_FIXTURE);
  require(input.good(), "fishing_fixture_missing");
  std::string line;
  require(static_cast<bool>(std::getline(input, line)),
          "fishing_fixture_empty");
  require(
      line == "case_id\treeling_input\tsequence\ttime_ns\tstage\ttrigger\tcast_ready\tcast_confidence\thook_cue\thook_confidence\tmemory\tactive\tplayer_x\tplayer_y\tfish_x\tfish_y\tright_x\tright_y\tcatch_visible\texpected_ok\texpected_reason\texpected_outcome\texpected_intents",
      "fishing_fixture_header_invalid");

  std::vector<fixture_case> cases;
  while (std::getline(input, line)) {
    if (line.empty() || line.front() == '#') {
      continue;
    }
    const auto fields = split(line, '\t');
    require(fields.size() == 23U, "fishing_fixture_row_invalid");
    auto found = std::find_if(
        cases.begin(),
        cases.end(),
        [&fields](const auto& value) { return value.id == fields[0]; });
    if (found == cases.end()) {
      fixture_case value;
      value.id = fields[0];
      value.request = base_request();
      value.request.reeling_input_enabled = parse_bool(fields[1]);
      cases.push_back(std::move(value));
      found = std::prev(cases.end());
    } else {
      require(
          found->request.reeling_input_enabled == parse_bool(fields[1]),
          "fishing_fixture_request_changed");
    }

    found->observations.push_back({
        .sequence = parse_integer<std::uint64_t>(fields[2]),
        .captured_at_steady_ns = parse_integer<std::uint64_t>(fields[3]),
        .stage = stage_observation(fields[4], fields[5]),
        .memory = memory_snapshot(fields),
        .cast_ready = parse_bool(fields[6]),
        .cast_confidence = parse_double(fields[7]),
        .hook = parse_hook(fields[8]),
        .hook_confidence = parse_double(fields[9]),
        .catch_visible = parse_bool(fields[18]),
    });

    if (fields[19] != "-") {
      require(!found->expectation_set, "fishing_fixture_expectation_duplicate");
      found->expectation_set = true;
      found->expected_ok = parse_bool(fields[19]);
      found->expected_reason = fields[20];
      found->expected_outcome = parse_outcome(fields[21]);
      found->expected_intents = fields[22] == "-"
          ? std::vector<std::string>{}
          : split(fields[22], ',');
    } else {
      require(
          fields[20] == "-" && fields[21] == "-" && fields[22] == "-",
          "fishing_fixture_partial_expectation");
    }
  }
  require(cases.size() >= 6U, "fishing_fixture_too_small");
  for (const auto& value : cases) {
    require(value.expectation_set, "fishing_fixture_expectation_missing");
    require(!value.observations.empty(), "fishing_fixture_observation_missing");
  }
  return cases;
}

class sequence_observer final : public episode::fishing_episode_observer {
 public:
  explicit sequence_observer(
      std::vector<episode::fishing_episode_observation> observations)
      : observations_(std::move(observations)) {}

  [[nodiscard]] episode::fishing_episode_observation observe(
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested()) {
      return {.error = "fixture_cancelled"};
    }
    if (cursor_ >= observations_.size()) {
      return {.error = "fixture_exhausted"};
    }
    auto value = observations_[cursor_++];
    latest_sequence_ = value.sequence;
    return value;
  }

  [[nodiscard]] std::uint64_t latest_sequence() const noexcept {
    return latest_sequence_;
  }

  [[nodiscard]] std::size_t consumed() const noexcept { return cursor_; }

 private:
  std::vector<episode::fishing_episode_observation> observations_;
  std::size_t cursor_{};
  std::uint64_t latest_sequence_{};
};

struct mutation_state final {
  sequence_observer* observer{};
  std::uint64_t settings_revision{101U};
  std::uint64_t entitlement_revision{202U};
  std::uint64_t lifecycle_revision{303U};
  bool foreground{true};
  std::size_t packet_budget{128U};
  std::size_t acquire_count{};
  std::size_t cleanup_count{};
  std::uint64_t cleanup_sequence{};
  bool cleanup_allowed{true};
  std::optional<std::size_t> cancel_after;
  std::stop_source* stop_source{};
  std::vector<episode::fishing_mutation_intent> intents;
};

class recording_session final : public episode::fishing_mutation_session {
 public:
  explicit recording_session(std::shared_ptr<mutation_state> state)
      : state_(std::move(state)) {}

  [[nodiscard]] episode::fishing_mutation_result apply(
      const episode::fishing_mutation_intent& intent,
      const std::stop_token stop_token) override {
    if (stop_token.stop_requested()) {
      return episode::fishing_mutation_result::rejected(
          "fixture_cancelled");
    }
    if (state_->observer == nullptr ||
        intent.expected_observation_sequence !=
            state_->observer->latest_sequence()) {
      return episode::fishing_mutation_result::rejected(
          "fixture_observation_gate_rejected");
    }
    if (intent.expected_settings_revision != state_->settings_revision) {
      return episode::fishing_mutation_result::rejected(
          "fixture_settings_gate_rejected");
    }
    if (intent.expected_entitlement_revision !=
        state_->entitlement_revision) {
      return episode::fishing_mutation_result::rejected(
          "fixture_entitlement_gate_rejected");
    }
    if (intent.expected_lifecycle_revision != state_->lifecycle_revision) {
      return episode::fishing_mutation_result::rejected(
          "fixture_lifecycle_gate_rejected");
    }
    if (!state_->foreground) {
      return episode::fishing_mutation_result::rejected(
          "fixture_window_gate_rejected");
    }
    bool packet_shape_valid = false;
    switch (intent.kind) {
      case episode::fishing_mutation_kind::tap_cast_space:
      case episode::fishing_mutation_kind::tap_hook_space:
        packet_shape_valid = intent.packet_count == 2U &&
            intent.desired_reeling_key == reeling::HeldKey::none;
        break;
      case episode::fishing_mutation_kind::pulse_reeling_key:
        packet_shape_valid = intent.packet_count == 2U &&
            (intent.desired_reeling_key == reeling::HeldKey::a ||
             intent.desired_reeling_key == reeling::HeldKey::d);
        break;
    }
    if (!packet_shape_valid) {
      return episode::fishing_mutation_result::rejected(
          "fixture_packet_shape_rejected");
    }
    if (state_->packet_budget < intent.packet_count) {
      return episode::fishing_mutation_result::rejected(
          "fixture_input_budget_rejected");
    }
    state_->packet_budget -= intent.packet_count;
    state_->intents.push_back(intent);
    const std::size_t index = state_->intents.size() - 1U;
    if (state_->cancel_after.has_value() && index == *state_->cancel_after &&
        state_->stop_source != nullptr) {
      state_->stop_source->request_stop();
    }
    return episode::fishing_mutation_result::accepted();
  }

  [[nodiscard]] episode::fishing_mutation_result cleanup_reeling_keys(
      const std::uint64_t expected_observation_sequence) noexcept override {
    ++state_->cleanup_count;
    state_->cleanup_sequence = expected_observation_sequence;
    if (!state_->cleanup_allowed || state_->observer == nullptr ||
        expected_observation_sequence > state_->observer->latest_sequence()) {
      return episode::fishing_mutation_result::rejected(
          "fixture_cleanup_rejected");
    }
    return episode::fishing_mutation_result::accepted();
  }

 private:
  std::shared_ptr<mutation_state> state_;
};

class recording_port final : public episode::fishing_mutation_port {
 public:
  explicit recording_port(sequence_observer& observer)
      : state(std::make_shared<mutation_state>()) {
    state->observer = &observer;
  }

  [[nodiscard]] std::unique_ptr<episode::fishing_mutation_session> acquire(
      const episode::fishing_episode_request& request,
      const std::stop_token stop_token,
      std::string& reason) override {
    static_cast<void>(request);
    if (stop_token.stop_requested()) {
      reason = "fixture_cancelled";
      return nullptr;
    }
    ++state->acquire_count;
    return std::make_unique<recording_session>(state);
  }

  std::shared_ptr<mutation_state> state;
};

[[nodiscard]] std::string intent_token(
    const episode::fishing_mutation_intent& intent) {
  std::string value = episode::fishing_mutation_key(intent.kind);
  if (intent.kind == episode::fishing_mutation_kind::pulse_reeling_key) {
    switch (intent.desired_reeling_key) {
      case reeling::HeldKey::none:
        value += ":none";
        break;
      case reeling::HeldKey::a:
        value += ":a";
        break;
      case reeling::HeldKey::d:
        value += ":d";
        break;
    }
  }
  return value;
}

[[nodiscard]] episode::fishing_episode_observation simple_observation(
    const std::uint64_t sequence,
    const std::uint64_t time_ns,
    const stage::observed_fishing_stage stage_value,
    const bool cue = false) {
  std::string trigger;
  switch (stage_value) {
    case stage::observed_fishing_stage::casting:
      trigger = "start1";
      break;
    case stage::observed_fishing_stage::waiting_for_bite:
      trigger = "start2";
      break;
    case stage::observed_fishing_stage::reeling:
      trigger = "ad";
      break;
    case stage::observed_fishing_stage::tackle_selection:
      trigger = "start";
      break;
    case stage::observed_fishing_stage::none:
      break;
  }
  episode::fishing_episode_observation value{
      .sequence = sequence,
      .captured_at_steady_ns = time_ns,
      .cast_ready = cue &&
          stage_value == stage::observed_fishing_stage::casting,
      .cast_confidence = cue &&
              stage_value == stage::observed_fishing_stage::casting
          ? 0.95
          : 0.0,
      .hook = cue &&
              stage_value == stage::observed_fishing_stage::waiting_for_bite
          ? episode::hook_cue::red
          : episode::hook_cue::none,
      .hook_confidence = cue &&
              stage_value == stage::observed_fishing_stage::waiting_for_bite
          ? 0.95
          : 0.0,
  };
  if (stage_value != stage::observed_fishing_stage::none) {
    value.stage = stage::stage_observation{
        .stage = stage_value,
        .trigger_id = std::move(trigger),
        .confidence = 0.99,
        .bounds = {.x = 0.1, .y = 0.1, .width = 0.2, .height = 0.2},
    };
  }
  return value;
}

void test_fixture_episodes() {
  for (const auto& item : load_fixture()) {
    sequence_observer observer(item.observations);
    recording_port mutation(observer);
    const auto result = episode::fishing_episode_runner{}.run(
        item.request, observer, mutation);
    require(result.ok == item.expected_ok, item.id + ":ok_changed");
    require(result.reason == item.expected_reason,
            item.id + ":reason_changed");
    require(result.outcome == item.expected_outcome,
            item.id + ":outcome_changed");
    require(observer.consumed() == item.observations.size(),
            item.id + ":observation_count_changed");
    require(mutation.state->acquire_count == 1U,
            item.id + ":lease_count_changed");
    require(result.cleanup_attempted && result.cleanup_completed &&
                mutation.state->cleanup_count == 1U,
            item.id + ":cleanup_changed");

    std::vector<std::string> intents;
    std::transform(
        mutation.state->intents.begin(),
        mutation.state->intents.end(),
        std::back_inserter(intents),
        intent_token);
    if (intents != item.expected_intents) {
      std::cerr << item.id << ": expected intents";
      for (const auto& value : item.expected_intents) {
        std::cerr << " [" << value << ']';
      }
      std::cerr << ", actual";
      for (const auto& value : intents) {
        std::cerr << " [" << value << ']';
      }
      std::cerr << '\n';
      require(false, item.id + ":intent_sequence_changed");
    }
  }
}

void test_default_off_and_disabled_port_do_not_observe() {
  sequence_observer observer({simple_observation(
      1U, 1'000'000'000U, stage::observed_fishing_stage::casting, true)});
  recording_port recording(observer);
  const auto off = episode::fishing_episode_runner{}.run(
      {}, observer, recording);
  require(!off.ok && off.reason == "fishing_automation_disabled",
          "default_off_reason_changed");
  require(observer.consumed() == 0U && recording.state->acquire_count == 0U,
          "default_off_touched_runtime");

  auto request = base_request();
  episode::disabled_fishing_mutation_port disabled;
  const auto disabled_result = episode::fishing_episode_runner{}.run(
      request, observer, disabled);
  require(!disabled_result.ok &&
              disabled_result.reason == "fishing_live_adapter_disabled",
          "disabled_port_reason_changed");
  require(observer.consumed() == 0U,
          "disabled_port_observed_before_lease");
}

void test_profile_drift_and_stale_sequence_fail_closed() {
  auto first = simple_observation(
      1U, 1'000'000'000U, stage::observed_fishing_stage::reeling);
  first.memory = memory::coherent_memory_snapshot{
      .sequence = 1U,
      .captured_at_steady_ns = first.captured_at_steady_ns,
      .profile_id = "fixture-e11",
      .profile_revision = 1U,
      .game_generation = {
          .process_id = 77U,
          .creation_time_filetime_100ns = 88U,
      },
      .reeling = memory::reeling_evidence{
          .active = true,
          .fish_model_confirmed = true,
          .player_right_x = 1.0,
          .distance = 1.0,
      },
  };
  auto drift = first;
  drift.sequence = 2U;
  drift.captured_at_steady_ns += 20'000'000U;
  drift.memory->sequence = drift.sequence;
  drift.memory->captured_at_steady_ns = drift.captured_at_steady_ns;
  drift.memory->profile_revision = 2U;
  drift.memory->reeling->active = false;
  sequence_observer profile_observer({first, drift});
  recording_port profile_mutation(profile_observer);
  const auto profile = episode::fishing_episode_runner{}.run(
      base_request(), profile_observer, profile_mutation);
  require(!profile.ok && profile.reason == "fishing_memory_profile_drift",
          "profile_drift_not_rejected");
  require(profile_mutation.state->intents.empty(),
          "profile_drift_mutated");

  auto target_drift = first;
  target_drift.sequence = 2U;
  target_drift.captured_at_steady_ns += 20'000'000U;
  target_drift.memory->sequence = target_drift.sequence;
  target_drift.memory->captured_at_steady_ns =
      target_drift.captured_at_steady_ns;
  ++target_drift.memory->game_generation.creation_time_filetime_100ns;
  target_drift.memory->reeling->active = false;
  sequence_observer target_observer({first, target_drift});
  recording_port target_mutation(target_observer);
  const auto target_result = episode::fishing_episode_runner{}.run(
      base_request(), target_observer, target_mutation);
  require(!target_result.ok &&
              target_result.reason == "fishing_memory_target_drift",
          "target_drift_not_rejected");
  require(target_mutation.state->intents.empty(), "target_drift_mutated");

  const auto cast = simple_observation(
      1U, 2'000'000'000U, stage::observed_fishing_stage::casting);
  auto stale = cast;
  stale.captured_at_steady_ns += 20'000'000U;
  sequence_observer stale_observer({cast, stale});
  recording_port stale_mutation(stale_observer);
  const auto stale_result = episode::fishing_episode_runner{}.run(
      base_request(), stale_observer, stale_mutation);
  require(!stale_result.ok &&
              stale_result.reason == "fishing_observation_stale",
          "stale_sequence_not_rejected");
}

void test_final_gate_dimensions_fail_closed() {
  const auto cue = simple_observation(
      1U, 3'000'000'000U, stage::observed_fishing_stage::casting, true);
  struct gate_case final {
    std::string expected;
    void (*break_gate)(mutation_state&);
  };
  const std::vector<gate_case> cases{
      {"fixture_settings_gate_rejected",
       [](mutation_state& state) { state.settings_revision = 999U; }},
      {"fixture_entitlement_gate_rejected",
       [](mutation_state& state) { state.entitlement_revision = 999U; }},
      {"fixture_lifecycle_gate_rejected",
       [](mutation_state& state) { state.lifecycle_revision = 999U; }},
      {"fixture_window_gate_rejected",
       [](mutation_state& state) { state.foreground = false; }},
      {"fixture_input_budget_rejected",
       [](mutation_state& state) { state.packet_budget = 1U; }},
  };
  for (const auto& item : cases) {
    sequence_observer observer({cue});
    recording_port mutation(observer);
    item.break_gate(*mutation.state);
    const auto result = episode::fishing_episode_runner{}.run(
        base_request(), observer, mutation);
    require(!result.ok && result.reason == item.expected,
            "final_gate_reason_changed");
    require(result.cleanup_attempted && result.cleanup_completed,
            "final_gate_cleanup_missing");
  }
}

void test_cancellation_after_mutation_still_cleans_up() {
  sequence_observer observer({
      simple_observation(
          1U, 4'000'000'000U, stage::observed_fishing_stage::casting, true),
      simple_observation(
          2U, 4'020'000'000U, stage::observed_fishing_stage::casting),
  });
  recording_port mutation(observer);
  std::stop_source source;
  mutation.state->cancel_after = 0U;
  mutation.state->stop_source = &source;
  const auto result = episode::fishing_episode_runner{}.run(
      base_request(), observer, mutation, source.get_token());
  require(!result.ok && result.reason == "fishing_episode_cancelled",
          "cancellation_reason_changed");
  require(result.mutations_applied == 1U,
          "cancellation_mutation_count_changed");
  require(result.cleanup_attempted && result.cleanup_completed &&
              mutation.state->cleanup_count == 1U,
          "cancellation_cleanup_missing");
}

void test_cleanup_failure_revokes_success() {
  auto finished = simple_observation(
      1U, 5'000'000'000U, stage::observed_fishing_stage::reeling);
  finished.memory = memory::coherent_memory_snapshot{
      .sequence = 1U,
      .captured_at_steady_ns = finished.captured_at_steady_ns,
      .profile_id = "fixture-e11",
      .profile_revision = 1U,
      .game_generation = {
          .process_id = 77U,
          .creation_time_filetime_100ns = 88U,
      },
      .reeling = memory::reeling_evidence{
          .active = false,
          .fish_model_confirmed = true,
          .player_right_x = 1.0,
          .distance = 1.0,
      },
  };
  sequence_observer observer({finished});
  recording_port mutation(observer);
  mutation.state->cleanup_allowed = false;
  const auto result = episode::fishing_episode_runner{}.run(
      base_request(), observer, mutation);
  require(!result.ok && result.reason == "fixture_cleanup_rejected",
          "cleanup_failure_did_not_revoke_success");
  require(result.cleanup_attempted && !result.cleanup_completed,
          "cleanup_failure_status_changed");
}

void test_invalid_cue_stage_and_tackle_selection_are_inert() {
  auto mismatch = simple_observation(
      1U, 6'000'000'000U, stage::observed_fishing_stage::waiting_for_bite);
  mismatch.cast_ready = true;
  mismatch.cast_confidence = 0.9;
  sequence_observer mismatch_observer({mismatch});
  recording_port mismatch_mutation(mismatch_observer);
  const auto mismatch_result = episode::fishing_episode_runner{}.run(
      base_request(), mismatch_observer, mismatch_mutation);
  require(!mismatch_result.ok &&
              mismatch_result.reason == "fishing_cast_cue_stage_mismatch",
          "cue_stage_mismatch_not_rejected");
  require(mismatch_mutation.state->intents.empty(),
          "cue_stage_mismatch_mutated");

  sequence_observer tackle_observer({simple_observation(
      1U,
      7'000'000'000U,
      stage::observed_fishing_stage::tackle_selection)});
  recording_port tackle_mutation(tackle_observer);
  const auto tackle = episode::fishing_episode_runner{}.run(
      base_request(), tackle_observer, tackle_mutation);
  require(!tackle.ok && tackle.reason == "fishing_tackle_selection_not_owned",
          "tackle_boundary_changed");
  require(tackle_mutation.state->intents.empty(), "tackle_boundary_mutated");

  auto caught = simple_observation(
      1U, 8'000'000'000U, stage::observed_fishing_stage::none);
  caught.catch_visible = true;
  sequence_observer catch_observer({caught});
  recording_port catch_mutation(catch_observer);
  const auto catch_result = episode::fishing_episode_runner{}.run(
      base_request(), catch_observer, catch_mutation);
  require(catch_result.ok &&
              catch_result.outcome ==
                  episode::fishing_episode_outcome::catch_visible,
          "initial_catch_terminal_changed");
  require(catch_mutation.state->intents.empty(), "initial_catch_mutated");

  auto invalid_hook = simple_observation(
      1U,
      9'000'000'000U,
      stage::observed_fishing_stage::waiting_for_bite);
  invalid_hook.hook = static_cast<episode::hook_cue>(255U);
  invalid_hook.hook_confidence = 0.9;
  sequence_observer hook_observer({invalid_hook});
  recording_port hook_mutation(hook_observer);
  const auto hook_result = episode::fishing_episode_runner{}.run(
      base_request(), hook_observer, hook_mutation);
  require(!hook_result.ok &&
              hook_result.reason == "fishing_hook_cue_invalid",
          "invalid_hook_cue_not_rejected");
  require(hook_mutation.state->intents.empty(), "invalid_hook_cue_mutated");

  sequence_observer limit_observer({
      simple_observation(
          1U, 10'000'000'000U, stage::observed_fishing_stage::casting),
      simple_observation(
          2U, 10'020'000'000U, stage::observed_fishing_stage::casting),
  });
  recording_port limit_mutation(limit_observer);
  auto limited_request = base_request();
  limited_request.maximum_observations = 1U;
  const auto limit_result = episode::fishing_episode_runner{}.run(
      limited_request, limit_observer, limit_mutation);
  require(!limit_result.ok &&
              limit_result.reason == "fishing_observation_limit_reached",
          "observation_limit_changed");
  require(limit_observer.consumed() == 1U &&
              limit_mutation.state->intents.empty(),
          "observation_limit_not_inert");
}

}  // namespace

int main() {
  try {
    test_fixture_episodes();
    test_default_off_and_disabled_port_do_not_observe();
    test_profile_drift_and_stale_sequence_fail_closed();
    test_final_gate_dimensions_fail_closed();
    test_cancellation_after_mutation_still_cleans_up();
    test_cleanup_failure_revokes_success();
    test_invalid_cue_stage_and_tackle_selection_are_inert();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
  std::cout << "fishing_episode_tests_ok\n";
  return 0;
}
