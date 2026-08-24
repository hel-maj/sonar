#include <atomic>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <variant>
#include <vector>

#include "sonar/fishing/engine_ipc/production_composition.h"

namespace {

namespace engine = sonar::fishing::engine_ipc;
namespace episode = sonar::fishing::fishing_episode;
namespace settings = sonar::fishing::runtime_settings;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

struct fixture_state final {
  std::atomic_size_t factory_calls{};
  std::atomic_size_t run_calls{};
  std::atomic_uint64_t settings_revision{};
  std::atomic_uint64_t entitlement_revision{};
  std::atomic_int64_t entitlement_expires_unix_seconds{};
  std::atomic_size_t entitlement_refresh_calls{};
  std::atomic_uint64_t lifecycle_revision{};
  std::atomic_uint64_t episode_identity{};
  std::atomic_bool auto_meal{};
  std::atomic_size_t progress_phase_calls{};
};

class fixture_progress final : public engine::production_session_progress_sink {
 public:
  void publish_phase(
      const engine::production_phase,
      std::string) noexcept override {
    ++phase_calls;
  }

  void record_catch(
      const sonar::fishing::catch_observation::CatchObservation&,
      const bool) noexcept override {}

  void publish_tackle(
      const sonar::fishing::equipment_recovery::TackleCounts&) noexcept
      override {}

  void publish_notification(
      engine::production_notification_event) noexcept override {}

  std::size_t phase_calls{};
};

[[nodiscard]] settings::RuntimeSettingsSnapshot valid_settings(
    const std::uint64_t revision = 7U) {
  settings::RuntimeSettingsSnapshot snapshot;
  snapshot.revision = revision;
  snapshot.auto_meal = false;
  snapshot.fish_keep_policy.emplace("marlin", true);
  snapshot.garbage_disposal_policy.emplace("bag", true);
  snapshot.custom_fish_prices.emplace("marlin", 250.0);
  return snapshot;
}

class fixture_session final : public engine::production_automation_session {
 public:
  explicit fixture_session(std::shared_ptr<fixture_state> state)
      : state_(std::move(state)) {}

  [[nodiscard]] engine::production_session_result run(
      const engine::production_session_request& request,
      const std::stop_token stop_token,
      engine::production_session_progress_sink& progress) override {
    if (stop_token.stop_requested()) {
      return {.reason = "fixture_cancelled"};
    }
    state_->settings_revision = request.settings.revision;
    state_->entitlement_revision = request.entitlement_generation;
    state_->entitlement_expires_unix_seconds =
        request.entitlement_expires_unix_seconds;
    state_->lifecycle_revision = request.lifecycle_revision;
    state_->episode_identity = request.lifecycle_revision;
    state_->auto_meal = request.settings.auto_meal;
    progress.publish_phase(engine::production_phase::fishing, "fixture");
    sonar::fishing::catch_observation::CatchObservation observed{
        .valid_content = true,
        .fish_text = "Марлин",
        .quality_label = "Трофейная",
        .quality_key = "trophy",
        .weight_kg = 12.5,
    };
    progress.record_catch(observed, false);
    progress.publish_notification(
        engine::production_meal_recovered_notification{
            .affected_count = 1U,
        });
    progress.publish_notification(
        engine::production_inventory_full_notification{});
    progress.publish_notification(
        engine::production_player_status_notification{
            .food = 80,
            .inventory_weight = 39.0,
            .inventory_weight_max = 40.0,
        });
    progress.publish_notification(
        engine::production_bait_tired_notification{});
    progress.publish_notification(
        engine::production_focus_lost_notification{
            .reason = "window_not_foreground",
        });
    for (std::size_t index = 0U;
         index < engine::maximum_pending_production_notifications;
         ++index) {
      progress.publish_notification(
          engine::production_bait_tired_notification{});
    }
    ++state_->progress_phase_calls;
    ++state_->run_calls;
    return {
        .ok = true,
        .reason = "fixture_production_session_complete",
        .cycles_completed = 1U,
    };
  }

  [[nodiscard]] bool refresh_entitlement_expiry(
      const std::uint64_t admitted_entitlement_generation,
      const std::int64_t expires_unix_seconds) noexcept override {
    ++state_->entitlement_refresh_calls;
    if (admitted_entitlement_generation != state_->entitlement_revision ||
        expires_unix_seconds <= 0) {
      return false;
    }
    state_->entitlement_expires_unix_seconds = expires_unix_seconds;
    return true;
  }

 private:
  std::shared_ptr<fixture_state> state_;
};

class fixture_factory final
    : public engine::production_automation_session_factory {
 public:
  fixture_factory(
      std::shared_ptr<fixture_state> state,
      const bool reject = false)
      : state_(std::move(state)), reject_(reject) {}

  [[nodiscard]] engine::production_automation_session_admission prepare()
      noexcept override {
    ++state_->factory_calls;
    if (reject_) {
      return {nullptr, "fixture_target_unavailable"};
    }
    return {std::make_unique<fixture_session>(state_), {}};
  }

 private:
  std::shared_ptr<fixture_state> state_;
  bool reject_{};
};

void complete_graph_is_inert_at_construction() {
  engine::production_capability_composition composition;
  const auto snapshot = composition.snapshot();
  require(snapshot.complete_native_graph(),
      "production_capability_graph_incomplete");
  require(!snapshot.observation_adapters_enabled,
      "production_observation_adapter_enabled_at_construction");
  require(!snapshot.mutation_adapters_enabled,
      "production_mutation_adapter_enabled_at_construction");
  require(!snapshot.ready_for_live_automation(),
      "production_composition_ready_at_construction");
  require(!snapshot.session_prepared,
      "production_session_prepared_at_construction");
}

void pure_invalid_admission_never_calls_platform_factory() {
  const auto state = std::make_shared<fixture_state>();
  engine::production_capability_composition composition(
      std::make_unique<fixture_factory>(state));
  auto invalid = valid_settings(0U);
  auto admission = composition.prepare_session(
      std::move(invalid), 11U, 1'900'000'000);
  require(!admission.accepted && admission.reason ==
          "runtime_settings_required_before_capability_composition",
      "missing_settings_not_rejected");
  admission = composition.prepare_session(
      valid_settings(), 0U, 1'900'000'000);
  require(!admission.accepted && admission.reason ==
          "signed_entitlement_required_before_capability_composition",
      "missing_entitlement_not_rejected");
  require(state->factory_calls == 0U,
      "platform_factory_called_before_pure_admission");
  composition.stop();
  composition.stop();
}

void fixture_platform_runs_one_coarse_cancellable_episode() {
  const auto state = std::make_shared<fixture_state>();
  engine::production_capability_composition composition(
      std::make_unique<fixture_factory>(state));
  const auto admission = composition.prepare_session(
      valid_settings(), 11U, 1'900'000'000);
  require(admission.accepted && admission.reason ==
          "production_capability_composition_ready",
      "fixture_platform_not_admitted");
  auto snapshot = composition.snapshot();
  require(snapshot.ready_for_live_automation() && snapshot.session_prepared,
      "prepared_fixture_platform_not_ready");
  const auto started = composition.start_session();
  require(started.accepted && started.reason ==
          "production_automation_worker_started",
      "fixture_operation_not_started");

  for (std::size_t attempt = 0U; attempt < 10'000U; ++attempt) {
    snapshot = composition.snapshot();
    if (snapshot.operation_completed) {
      break;
    }
    std::this_thread::yield();
  }
  require(snapshot.operation_completed && !snapshot.operation_running &&
          snapshot.last_operation_ok &&
          snapshot.last_operation_reason ==
              "fixture_production_session_complete",
      "fixture_operation_result_not_published");
  require(state->factory_calls == 1U && state->run_calls == 1U,
      "fixture_operation_call_count_changed");
  require(state->settings_revision == 7U &&
          state->entitlement_revision == 11U &&
          state->entitlement_expires_unix_seconds == 1'900'000'000 &&
          state->lifecycle_revision != 0U &&
          state->episode_identity == state->lifecycle_revision &&
          !state->auto_meal,
      "coarse_episode_authority_identity_changed");
  require(state->progress_phase_calls == 1U &&
          snapshot.progress_revision >= 3U &&
          snapshot.cycles_completed == 1U,
      "coarse_progress_aggregate_not_published");
  require(
      snapshot.pending_notification_count ==
          engine::maximum_pending_production_notifications &&
          snapshot.dropped_notification_count == 6U,
      "production_notification_queue_not_bounded");
  const auto notifications = composition.take_pending_notifications();
  require(
      notifications.size() == engine::maximum_pending_production_notifications &&
          std::holds_alternative<engine::production_catch_notification>(
              notifications[0]) &&
          std::holds_alternative<
              engine::production_meal_recovered_notification>(
              notifications[1]) &&
          std::holds_alternative<
              engine::production_inventory_full_notification>(
              notifications[2]) &&
          std::holds_alternative<
              engine::production_player_status_notification>(
              notifications[3]) &&
          std::holds_alternative<
              engine::production_bait_tired_notification>(
              notifications[4]) &&
          std::holds_alternative<
              engine::production_focus_lost_notification>(
              notifications[5]),
      "production_notification_order_or_type_changed");
  require(
      composition.snapshot().pending_notification_count == 0U,
      "production_notification_drain_replayed_events");
  require(!composition.start_session().accepted,
      "completed_worker_restarted_without_new_session");
  composition.stop();
  snapshot = composition.snapshot();
  require(!snapshot.session_prepared &&
          !snapshot.observation_adapters_enabled &&
          !snapshot.mutation_adapters_enabled,
      "stop_retained_platform_adapters");
}

void platform_factory_failure_is_stable_and_fail_closed() {
  const auto state = std::make_shared<fixture_state>();
  engine::production_capability_composition composition(
      std::make_unique<fixture_factory>(state, true));
  const auto admission = composition.prepare_session(
      valid_settings(), 11U, 1'900'000'000);
  require(!admission.accepted &&
          admission.reason == "fixture_target_unavailable",
      "platform_failure_reason_changed");
  require(!composition.snapshot().session_prepared,
      "rejected_platform_session_retained");
}

struct refreshable_state final {
  std::atomic_bool running{};
  std::atomic_uint64_t admitted_generation{};
  std::atomic_int64_t expires_unix_seconds{};
  std::atomic_size_t refresh_calls{};
};

class refreshable_session final : public engine::production_automation_session {
 public:
  explicit refreshable_session(std::shared_ptr<refreshable_state> state)
      : state_(std::move(state)) {}

  [[nodiscard]] engine::production_session_result run(
      const engine::production_session_request& request,
      const std::stop_token stop_token,
      engine::production_session_progress_sink&) override {
    state_->admitted_generation = request.entitlement_generation;
    state_->expires_unix_seconds = request.entitlement_expires_unix_seconds;
    state_->running = true;
    while (!stop_token.stop_requested()) {
      std::this_thread::yield();
    }
    state_->running = false;
    return {
        .ok = true,
        .stopped = true,
        .reason = "fixture_refreshable_stopped",
    };
  }

  [[nodiscard]] bool refresh_entitlement_expiry(
      const std::uint64_t admitted_entitlement_generation,
      const std::int64_t expires_unix_seconds) noexcept override {
    ++state_->refresh_calls;
    if (!state_->running || admitted_entitlement_generation == 0U ||
        admitted_entitlement_generation != state_->admitted_generation ||
        expires_unix_seconds <= 0) {
      return false;
    }
    state_->expires_unix_seconds = expires_unix_seconds;
    return true;
  }

 private:
  std::shared_ptr<refreshable_state> state_;
};

class refreshable_factory final
    : public engine::production_automation_session_factory {
 public:
  explicit refreshable_factory(std::shared_ptr<refreshable_state> state)
      : state_(std::move(state)) {}

  [[nodiscard]] engine::production_automation_session_admission prepare()
      noexcept override {
    return {std::make_unique<refreshable_session>(state_), {}};
  }

 private:
  std::shared_ptr<refreshable_state> state_;
};

void active_session_refreshes_only_the_admitted_entitlement_lease() {
  const auto state = std::make_shared<refreshable_state>();
  engine::production_capability_composition composition(
      std::make_unique<refreshable_factory>(state));
  require(composition.prepare_session(
              valid_settings(), 41U, 1'900'000'000).accepted,
      "refresh_fixture_not_prepared");
  require(composition.start_session().accepted,
      "refresh_fixture_not_started");
  for (std::size_t attempt = 0U;
       attempt < 100'000U && !state->running; ++attempt) {
    std::this_thread::yield();
  }
  require(state->running, "refresh_fixture_worker_not_running");
  const auto refreshed = composition.refresh_entitlement_expiry(
      41U, 1'900'000'600);
  require(refreshed.accepted &&
          refreshed.reason == "production_entitlement_refreshed" &&
          state->refresh_calls == 1U &&
          state->expires_unix_seconds == 1'900'000'600,
      "active_entitlement_expiry_not_refreshed");
  require(!composition.refresh_entitlement_expiry(
              42U, 1'900'001'200).accepted &&
          state->refresh_calls == 1U &&
          state->expires_unix_seconds == 1'900'000'600,
      "non_admitted_entitlement_generation_refreshed");
  composition.stop();
  require(!state->running &&
          !composition.refresh_entitlement_expiry(
              41U, 1'900'001'800).accepted,
      "stopped_entitlement_lease_refreshed");
}

class ordered_cycle_port final : public engine::production_cycle_port {
 public:
  [[nodiscard]] episode::fishing_episode_result run_fishing(
      const engine::production_session_request& request,
      const std::uint64_t identity,
      const std::stop_token) override {
    require(request.settings.revision == 19U,
        "loop_settings_snapshot_changed");
    identities.push_back(identity);
    order.emplace_back("fish");
    return {
        .ok = true,
        .reason = "catch_visible",
        .outcome = episode::fishing_episode_outcome::catch_visible,
    };
  }

  [[nodiscard]] engine::production_step_result process_catch(
      const engine::production_session_request&,
      const std::uint64_t identity,
      const episode::fishing_episode_result& fishing,
      const std::stop_token) override {
    require(fishing.outcome == episode::fishing_episode_outcome::catch_visible,
        "loop_catch_fact_changed");
    require(identity == identities.back(), "loop_catch_identity_changed");
    order.emplace_back("catch");
    return engine::production_step_result::completed();
  }

  [[nodiscard]] engine::production_step_result run_inventory(
      const engine::production_session_request&,
      const std::uint64_t identity,
      const std::stop_token) override {
    require(identity == identities.back(), "loop_inventory_identity_changed");
    order.emplace_back("inventory");
    return engine::production_step_result::completed();
  }

  [[nodiscard]] engine::production_step_result run_maintenance(
      const engine::production_session_request&,
      const std::uint64_t identity,
      const std::stop_token) override {
    require(identity == identities.back(), "loop_maintenance_identity_changed");
    order.emplace_back("maintenance");
    return engine::production_step_result::completed(
        true, identities.size() == 2U);
  }

  std::vector<std::string> order;
  std::vector<std::uint64_t> identities;
};

void continuous_loop_owns_the_whole_coarse_cycle() {
  ordered_cycle_port port;
  engine::production_session_request request{
      .settings = valid_settings(19U),
      .entitlement_generation = 23U,
      .entitlement_expires_unix_seconds = 1'900'000'000,
      .lifecycle_revision = 29U,
      .maximum_cycles = 3U,
  };
  const auto result = engine::production_session_loop{}.run(request, port);
  require(result.ok && !result.stopped &&
          result.reason == "production_session_completed" &&
          result.cycles_completed == 2U &&
          result.catches_processed == 2U &&
          result.inventory_episodes_completed == 2U &&
          result.maintenance_episodes_completed == 2U,
      "coarse_production_loop_result_changed");
  require(port.identities == std::vector<std::uint64_t>({29U, 30U}),
      "coarse_production_loop_identity_changed");
  require(port.order == std::vector<std::string>({
          "fish", "catch", "inventory", "maintenance",
          "fish", "catch", "inventory", "maintenance"}),
      "coarse_production_loop_order_changed");
}

void catch_observation_is_owned_as_one_pure_internal_fact() {
  engine::production_capability_composition composition;
  const sonar::fishing::catch_observation::RawCatchText raw{
      .fish = "Марлин",
      .quality = "Трофейная",
      .weight = "12.5 кг",
      .experience = "100 / 200",
  };
  const auto interpreted = composition.interpret_catch(raw);
  require(interpreted.valid_content, "catch_observation_not_connected");
  require(interpreted.fish_id.has_value(), "catch_identity_not_connected");
  require(interpreted.quality_key == "trophy",
      "catch_quality_not_connected");
}

}  // namespace

int main() {
  try {
    complete_graph_is_inert_at_construction();
    pure_invalid_admission_never_calls_platform_factory();
    fixture_platform_runs_one_coarse_cancellable_episode();
    platform_factory_failure_is_stable_and_fail_closed();
    active_session_refreshes_only_the_admitted_entitlement_lease();
    continuous_loop_owns_the_whole_coarse_cycle();
    catch_observation_is_owned_as_one_pure_internal_fact();
    return 0;
  } catch (const std::exception&) {
    return 1;
  }
}
