#include "sonar/fishing/automation_adapters/common_inventory_open.h"
#include "sonar/fishing/automation_adapters/fishing_adapters.h"

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <memory>
#include <string_view>
#include <utility>
#include <vector>

namespace adapters = sonar::fishing::automation_adapters;
namespace inventory = sonar::platform::inventory;
namespace windows = sonar::platform::windows;

namespace {

void require(const bool condition, const std::string_view message) {
  if (!condition) {
    std::cerr << "FAIL: " << message << '\n';
    std::exit(1);
  }
}

class scripted_inventory_open_source final
    : public adapters::inventory_open_source {
 public:
  explicit scripted_inventory_open_source(
      std::vector<inventory::observed_state> states)
      : states_(std::move(states)) {}

  [[nodiscard]] adapters::inventory_open_source_result capture(
      const windows::process_generation& generation) noexcept override {
    ++capture_calls;
    generations.push_back(generation);
    const auto index = capture_calls - 1U;
    const auto state = index < states_.size()
        ? states_[index]
        : inventory::observed_state::unknown;
    return {
        .state = state,
        .binding_hot = state != inventory::observed_state::unknown,
        .reason = state == inventory::observed_state::unknown
            ? "production_inventory_semantic_not_found"
            : std::string{},
    };
  }

  void reset() noexcept override {
    ++reset_calls;
  }

  std::size_t capture_calls{};
  std::size_t reset_calls{};
  std::vector<windows::process_generation> generations;

 private:
  std::vector<inventory::observed_state> states_;
};

class scripted_retry_clock final : public adapters::inventory_retry_clock {
 public:
  [[nodiscard]] std::uint64_t now_steady_ns() const noexcept override {
    return now_ns;
  }

  std::uint64_t now_ns{1'000'000'000ULL};
};

void compile_isolated_policy_is_explicit() {
  constexpr auto shipping =
      adapters::common_inventory_open_policy_for_build<false>();
  constexpr auto local =
      adapters::common_inventory_open_policy_for_build<true>();
  static_assert(!shipping.observation_enabled);
  static_assert(!shipping.candidate_profile_approved);
  static_assert(!shipping.closed_state_bootstrap_approved);
  static_assert(local.observation_enabled);
  static_assert(local.candidate_profile_approved);
  static_assert(local.closed_state_bootstrap_approved);
  static_assert(local.profile_id ==
      adapters::common_inventory_open_candidate_profile_id);

  const auto selected = adapters::selected_common_inventory_open_policy();
#if defined(SONAR_FISHING_DEVELOPER_FULL_ACCESS)
  require(selected.observation_enabled &&
          selected.candidate_profile_approved &&
          selected.closed_state_bootstrap_approved,
          "Local Access must explicitly admit only the built-in candidate");
#else
  require(!selected.observation_enabled &&
          !selected.candidate_profile_approved &&
          !selected.closed_state_bootstrap_approved,
          "ordinary shipping composition must stay denied and inert");
  auto source = adapters::make_common_inventory_open_source();
  require(source != nullptr, "disabled Common facade must still be constructible");
  const auto result = source->capture({.process_id = 1U});
  require(result.state == inventory::observed_state::unknown &&
          result.reason == "production_inventory_source_disabled",
          "disabled Common facade must map source_disabled without touching GTA");
#endif
}

void aggregate_routing_is_bounded_and_generation_safe() {
  const windows::process_generation first{
      .process_id = 11U,
      .creation_time_filetime_100ns = 101U,
  };
  const windows::process_generation second{
      .process_id = 11U,
      .creation_time_filetime_100ns = 202U,
  };
  auto scripted = std::make_unique<scripted_inventory_open_source>(
      std::vector<inventory::observed_state>{
              inventory::observed_state::unknown,
              inventory::observed_state::unknown,
              inventory::observed_state::open,
              inventory::observed_state::closed,
          });
  auto* observed = scripted.get();
  auto clock = std::make_unique<scripted_retry_clock>();
  auto* time = clock.get();
  adapters::resolved_fishing_memory_source source(
      std::unique_ptr<sonar::fishing::memory_observation::memory_connector>{},
      std::move(scripted),
      std::move(clock));

  const auto reeling = source.capture(1U, 100U, first, true);
  require(!reeling.snapshot.has_value() &&
          reeling.reason == "production_memory_connector_unavailable" &&
          observed->capture_calls == 0U,
          "reeling path must never invoke cold inventory discovery");

  const auto unknown = source.capture(2U, 200U, first, false);
  require(unknown.snapshot.has_value() &&
          unknown.snapshot->inventory_open_state ==
              inventory::observed_state::unknown &&
          observed->capture_calls == 1U && observed->reset_calls == 0U,
          "one non-reeling aggregate must make one Common facade call");

  const auto cached = source.capture(3U, 300U, first, false);
  require(cached.snapshot.has_value() &&
          cached.snapshot->inventory_open_state ==
              inventory::observed_state::unknown &&
          observed->capture_calls == 1U,
          "repeated unknown must be cached until the bounded retry deadline");

  time->now_ns += 250'000'000ULL;
  const auto retried = source.capture(4U, 400U, first, false);
  require(retried.snapshot.has_value() &&
          retried.snapshot->inventory_open_state ==
              inventory::observed_state::unknown &&
          observed->capture_calls == 2U && observed->reset_calls == 0U,
          "retry deadline must trigger exactly one new cold attempt");

  time->now_ns += 499'000'000ULL;
  const auto still_cached = source.capture(5U, 500U, first, false);
  require(still_cached.snapshot.has_value() &&
          still_cached.snapshot->inventory_open_state ==
              inventory::observed_state::unknown &&
          observed->capture_calls == 2U,
          "exponential retry delay must remain capped and monotonic");

  const auto regenerated = source.capture(6U, 600U, second, false);
  require(regenerated.snapshot.has_value() &&
          regenerated.snapshot->inventory_open_state ==
              inventory::observed_state::open &&
          observed->capture_calls == 3U && observed->reset_calls == 1U &&
          observed->generations.back() == second,
          "new GTA generation must bypass backoff after exactly one reset");

  const auto hot = source.capture(7U, 700U, second, false);
  require(hot.snapshot.has_value() &&
          hot.snapshot->inventory_open_state ==
              inventory::observed_state::closed &&
          observed->capture_calls == 4U && observed->reset_calls == 1U,
          "known state must preserve hot per-capture cadence without caching");
}

void unknown_backoff_is_exponential_and_capped() {
  const windows::process_generation generation{
      .process_id = 22U,
      .creation_time_filetime_100ns = 303U,
  };
  auto scripted = std::make_unique<scripted_inventory_open_source>(
      std::vector<inventory::observed_state>(
          8U, inventory::observed_state::unknown));
  auto* observed = scripted.get();
  auto clock = std::make_unique<scripted_retry_clock>();
  auto* time = clock.get();
  adapters::resolved_fishing_memory_source source(
      std::unique_ptr<sonar::fishing::memory_observation::memory_connector>{},
      std::move(scripted),
      std::move(clock));

  static constexpr std::uint64_t delays_ns[]{
      250'000'000ULL,
      500'000'000ULL,
      1'000'000'000ULL,
      2'000'000'000ULL,
      4'000'000'000ULL,
      4'000'000'000ULL,
  };
  static_cast<void>(source.capture(10U, 10U, generation, false));
  require(observed->capture_calls == 1U, "initial cold attempt was not made");
  for (std::size_t index = 0U; index < std::size(delays_ns); ++index) {
    time->now_ns += delays_ns[index] - 1U;
    static_cast<void>(source.capture(
        11U + index * 2U, 11U + index * 2U, generation, false));
    require(observed->capture_calls == index + 1U,
        "unknown state retried before its deadline");
    ++time->now_ns;
    static_cast<void>(source.capture(
        12U + index * 2U, 12U + index * 2U, generation, false));
    require(observed->capture_calls == index + 2U,
        "unknown state did not retry at its deadline");
  }
}

}  // namespace

int main() {
  compile_isolated_policy_is_explicit();
  aggregate_routing_is_bounded_and_generation_safe();
  unknown_backoff_is_exponential_and_capped();
  std::cout << "PASS common inventory-open adapter tests\n";
  return 0;
}
