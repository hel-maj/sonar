#include "sonar/fishing/engine_ipc/production_composition.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <exception>
#include <limits>
#include <optional>
#include <string_view>
#include <utility>
#include <vector>

#include "sonar/fishing/automation_adapters/fishing_adapters.h"
#include "sonar/fishing/automation_adapters/production_mutation.h"
#include "sonar/fishing/automation_adapters/production_observation.h"
#include "sonar/fishing/automation_adapters/runtime_policy.h"
#include "sonar/fishing/automation_adapters/system_terminal_action.h"
#include "sonar/fishing/catch_disposition/catch_disposition.h"
#include "sonar/fishing/runtime_platform/automation_lease.h"
#include "sonar/fishing/runtime_platform/platform_capture.h"
#include "sonar/fishing/runtime_platform/platform_input.h"
#include "sonar/fishing/runtime_platform/target_resolver.h"
#include "sonar/fishing/runtime_safety/runtime_safety.h"

namespace sonar::fishing::engine_ipc {
namespace {

constexpr std::size_t kMaximumSessionInputPackets = 65'536U;
constexpr std::size_t kCatchDismissPolls = 8U;
constexpr std::size_t kCatchDismissPollMilliseconds = 150U;

[[nodiscard]] double steady_now_seconds() noexcept {
  return std::chrono::duration<double>(
      std::chrono::steady_clock::now().time_since_epoch()).count();
}

[[nodiscard]] std::string attach_reason_key(
    const runtime_safety::attach_reason reason) {
  using value = runtime_safety::attach_reason;
  switch (reason) {
    case value::ready: return {};
    case value::invalid_argument: return "game_target_invalid";
    case value::process_unavailable: return "game_process_unavailable";
    case value::window_unavailable: return "game_window_unavailable";
    case value::window_owner_changed: return "game_window_owner_changed";
  }
  return "game_target_attach_failed";
}

[[nodiscard]] std::optional<production_player_status_notification>
player_status_notification(
    const std::optional<memory_observation::player_status_evidence>& source) {
  if (!source.has_value() || !source->has_any_value()) {
    return std::nullopt;
  }
  return production_player_status_notification{
      .food = source->food,
      .water = source->water,
      .health = source->health,
      .inventory_weight = source->inventory_weight,
      .inventory_weight_max = source->inventory_weight_max,
      .backpack_weight = source->backpack_weight,
      .backpack_weight_max = source->backpack_weight_max,
  };
}

[[nodiscard]] bool is_focus_loss_reason(
    const std::string_view reason) noexcept {
  return reason.find("not_foreground") != std::string_view::npos;
}

class windows_fishing_automation_session final
    : public production_automation_session,
      private production_cycle_port {
 public:
  windows_fishing_automation_session(
      sonar::platform::windows::window_client_snapshot target,
      std::unique_ptr<runtime_safety::runtime_target_guard> guard)
      : target_(std::move(target)),
        guard_(std::move(guard)),
        capture_(target_) {}

  [[nodiscard]] production_session_result run(
      const production_session_request& request,
      const std::stop_token stop_token,
      production_session_progress_sink& progress) override {
    progress_ = &progress;
    struct progress_reset final {
      production_session_progress_sink*& target;
      ~progress_reset() { target = nullptr; }
    } reset{progress_};
    if (!guard_) {
      return {.reason = "game_target_guard_unavailable"};
    }
    policy_.publish({
        .entitlement_valid = true,
        .settings_current = true,
        .lifecycle_allows_input = true,
        .settings_revision = request.settings.revision,
        .entitlement_revision = request.entitlement_generation,
        .entitlement_expires_unix_seconds =
            request.entitlement_expires_unix_seconds,
        .lifecycle_revision = request.lifecycle_revision,
    });
    runtime_platform::win32_platform_mutation_sink sink(target_, stop_token);
    automation_adapters::win32_system_terminal_action_sink terminal_sink;
    automation_adapters::runtime_safety_action_gate final_gate(
        *guard_, policy_);
    text_ = automation_adapters::make_windows_runtime_text_recognizer();
    if (!text_) {
      policy_.stop();
      return {.reason = "production_text_recognizer_unavailable"};
    }
    fishing_observer_ =
        std::make_unique<automation_adapters::frame_fishing_observer>(
        capture_, stage_detector_, memory_, policy_);
    production_observer_ =
        std::make_unique<automation_adapters::production_frame_observer>(
            capture_, stage_detector_, memory_, policy_, *text_);
    std::string mutation_reason;
    mutation_ = automation_adapters::guarded_production_mutation_port::acquire(
        leases_, final_gate, sink, terminal_sink, *production_observer_,
        request.settings.revision, request.entitlement_generation,
        request.lifecycle_revision, mutation_reason);
    if (!mutation_) {
      production_observer_.reset();
      fishing_observer_.reset();
      text_.reset();
      policy_.stop();
      return {.reason = mutation_reason.empty()
          ? "production_mutation_admission_failed"
          : std::move(mutation_reason)};
    }
    const auto result = loop_.run(request, *this, stop_token);
    if (!result.ok && is_focus_loss_reason(result.reason)) {
      progress.publish_notification(production_focus_lost_notification{
          .reason = result.reason,
      });
    }
    const bool cleanup_completed = mutation_->cleanup();
    mutation_.reset();
    production_observer_.reset();
    fishing_observer_.reset();
    text_.reset();
    policy_.stop();
    if (!cleanup_completed && result.ok) {
      auto failed = result;
      failed.ok = false;
      failed.stopped = false;
      failed.reason = "production_session_cleanup_failed";
      return failed;
    }
    return result;
  }

  [[nodiscard]] bool refresh_entitlement_expiry(
      const std::uint64_t admitted_entitlement_generation,
      const std::int64_t expires_unix_seconds) noexcept override {
    return policy_.refresh_entitlement_expiry(
        admitted_entitlement_generation, expires_unix_seconds);
  }

 private:
  [[nodiscard]] fishing_episode::fishing_episode_result run_fishing(
      const production_session_request& request,
      const std::uint64_t cycle_identity,
      const std::stop_token stop_token) override {
    if (!fishing_observer_ || !mutation_) {
      return {.reason = "production_fishing_adapters_unavailable"};
    }
    if (progress_ != nullptr) {
      progress_->publish_phase(production_phase::fishing, "fishing");
    }
    return runner_.run({
        .automation_enabled = true,
        .reeling_input_enabled = true,
        .accepted_settings_revision = request.settings.revision,
        .expected_entitlement_revision = request.entitlement_generation,
        .expected_lifecycle_revision = request.lifecycle_revision,
        .episode_identity = cycle_identity,
    }, *fishing_observer_, *mutation_, stop_token);
  }

  [[nodiscard]] production_step_result process_catch(
      const production_session_request& request,
      const std::uint64_t,
      const fishing_episode::fishing_episode_result&,
      const std::stop_token stop_token) override {
    pending_store_ids_.clear();
    if (!production_observer_ || !mutation_) {
      return production_step_result::rejected(
          "production_catch_adapters_unavailable");
    }
    if (progress_ != nullptr) {
      progress_->publish_phase(
          production_phase::catch_processing, "catch");
    }
    const auto observed = production_observer_->observe_catch(stop_token);
    if (!observed.visible || !observed.catch_fact.has_value() ||
        !observed.error.empty()) {
      return production_step_result::rejected(
          observed.error.empty()
              ? "production_catch_observation_unavailable"
              : observed.error);
    }

    if (observed.inventory_full && progress_ != nullptr) {
      progress_->publish_notification(
          production_inventory_full_notification{});
    }
    if (observed.inventory_full &&
        request.settings.overweight_action !=
            runtime_settings::OverweightAction::release) {
      const auto terminal = mutation_->apply({
          .kind = request.settings.overweight_action ==
                  runtime_settings::OverweightAction::exit_game
              ? inventory_store::inventory_intent_kind::exit_game
              : inventory_store::inventory_intent_kind::stop_automation,
          .expected_observation_sequence = observed.sequence,
      }, stop_token);
      return terminal.applied
          ? production_step_result::completed(true, true)
          : production_step_result::rejected(
                terminal.reason.empty()
                    ? "production_overweight_terminal_rejected"
                    : terminal.reason);
    }

    std::vector<std::string_view> selected;
    selected.reserve(request.settings.fish_keep_policy.size());
    for (const auto& [fish_id, keep] : request.settings.fish_keep_policy) {
      if (keep) {
        selected.emplace_back(fish_id);
      }
    }
    const auto& fact = *observed.catch_fact;
    const std::optional<std::string_view> fish_id = fact.fish_id.has_value()
        ? std::optional<std::string_view>(*fact.fish_id)
        : std::nullopt;
    const auto decision = catch_disposition::Decide(
        fish_id, selected, observed.inventory_full);
    const auto& target = decision.should_keep()
        ? observed.keep_button
        : observed.release_button;
    const auto applied = mutation_->apply_catch_button(
        observed.sequence, target, stop_token);
    if (!applied.applied) {
      return production_step_result::rejected(
          applied.reason.empty()
              ? "production_catch_mutation_rejected"
              : applied.reason);
    }

    std::uint64_t latest_sequence = observed.sequence;
    bool dismissed = false;
    for (std::size_t poll = 0U; poll < kCatchDismissPolls; ++poll) {
      const auto waited = mutation_->apply({
          .kind = inventory_store::inventory_intent_kind::pause,
          .expected_observation_sequence = latest_sequence,
          .delay_milliseconds = kCatchDismissPollMilliseconds,
      }, stop_token);
      if (!waited.applied) {
        return production_step_result::rejected(
            waited.reason.empty()
                ? "production_catch_confirmation_wait_failed"
                : waited.reason);
      }
      const auto confirmation =
          production_observer_->observe_catch(stop_token);
      if (!confirmation.visible &&
          confirmation.error == "production_catch_not_visible") {
        dismissed = true;
        break;
      }
      if (!confirmation.error.empty()) {
        return production_step_result::rejected(confirmation.error);
      }
      latest_sequence = confirmation.sequence;
    }
    if (!dismissed) {
      return production_step_result::rejected(
          "production_catch_dismissal_not_confirmed");
    }
    if (decision.should_keep() && fact.fish_id.has_value() &&
        request.settings.store_in_trunk) {
      pending_store_ids_.push_back(*fact.fish_id);
    }
    if (progress_ != nullptr) {
      progress_->record_catch(fact, decision.should_keep());
    }
    return production_step_result::completed();
  }

  [[nodiscard]] production_step_result run_inventory(
      const production_session_request& request,
      const std::uint64_t,
      const std::stop_token stop_token) override {
    if (!production_observer_ || !mutation_) {
      return production_step_result::rejected(
          "production_inventory_adapters_unavailable");
    }
    if (!request.settings.store_in_trunk || pending_store_ids_.empty()) {
      pending_store_ids_.clear();
      return production_step_result::completed(false);
    }
    if (progress_ != nullptr) {
      progress_->publish_phase(production_phase::inventory, "inventory");
    }
    const auto stored = inventory_runner_.run({
        .inventory_hotkey = request.settings.inventory_hotkey,
        .fishing_entry_hotkey = request.settings.use_item_hotkey,
        .fish_to_store = pending_store_ids_,
        .open_inventory = true,
        .resume_fishing = true,
    }, *production_observer_, *mutation_, stop_token);
    if (!stored.ok) {
      return production_step_result::rejected(
          stored.reason.empty()
              ? "production_inventory_episode_failed"
              : stored.reason);
    }
    if (stored.stored_count != pending_store_ids_.size()) {
      return production_step_result::rejected(
          "production_inventory_store_not_confirmed");
    }
    pending_store_ids_.clear();
    return production_step_result::completed(
        true,
        mutation_->terminal_action() !=
            automation_adapters::requested_terminal_action::none);
  }

  [[nodiscard]] production_step_result run_maintenance(
      const production_session_request& request,
      const std::uint64_t,
      const std::stop_token stop_token) override {
    if (!production_observer_ || !mutation_) {
      return production_step_result::rejected(
          "production_maintenance_adapters_unavailable");
    }
    if (progress_ != nullptr) {
      progress_->publish_phase(production_phase::maintenance, "maintenance");
    }
    const auto run = [&](const maintenance_episode::episode_kind kind) {
      return maintenance_runner_.run({
          .kind = kind,
          .settings = request.settings,
          .session_started_with_net = session_started_with_net_,
          .now_seconds = steady_now_seconds(),
          .last_bait_change_at_seconds = last_bait_change_at_seconds_,
          .resume_fishing = true,
      }, *production_observer_, *mutation_, stop_token);
    };
    const auto accept = [&](const maintenance_episode::maintenance_result& value)
        -> std::optional<production_step_result> {
      if (!value.ok) {
        return production_step_result::rejected(
            value.reason.empty()
                ? "production_maintenance_episode_failed"
                : value.reason);
      }
      if (value.bait_cooldown_advanced) {
        last_bait_change_at_seconds_ = value.next_bait_change_at_seconds;
      }
      if (value.meal_search_disabled_until_restart) {
        meal_search_disabled_ = true;
      }
      if (value.terminal != maintenance_episode::terminal_outcome::none ||
          mutation_->terminal_action() !=
              automation_adapters::requested_terminal_action::none) {
        return production_step_result::completed(true, true);
      }
      return std::nullopt;
    };

    const auto tackle = run(maintenance_episode::episode_kind::tackle_check);
    if (progress_ != nullptr) {
      const auto status = player_status_notification(
          production_observer_->current_maintenance().player_status);
      if (status.has_value()) {
        progress_->publish_notification(*status);
      }
    }
    if (const auto terminal = accept(tackle); terminal.has_value()) {
      return *terminal;
    }
    const auto& after_tackle = production_observer_->current_maintenance();
    if (!session_started_with_net_.has_value() &&
        after_tackle.tackle.has_value() &&
        after_tackle.tackle->available && after_tackle.tackle->readable &&
        !after_tackle.tackle->obscured) {
      session_started_with_net_ = after_tackle.tackle->counts.net != 0U;
    }
    if (progress_ != nullptr && after_tackle.tackle.has_value() &&
        after_tackle.tackle->available && after_tackle.tackle->readable &&
        !after_tackle.tackle->obscured) {
      progress_->publish_tackle(after_tackle.tackle->counts);
    }

    const auto bait = run(maintenance_episode::episode_kind::bait_recovery);
    if (progress_ != nullptr && bait.recovery_attempted) {
      progress_->publish_notification(production_bait_tired_notification{});
    }
    if (const auto terminal = accept(bait); terminal.has_value()) {
      return *terminal;
    }

    const auto& current = production_observer_->current_maintenance();
    bool meal_needed = current.hunger_visible || current.thirst_visible;
    if (current.player_status.has_value()) {
      const auto& status = *current.player_status;
      meal_needed = meal_needed ||
          (status.food.has_value() &&
           *status.food <
               static_cast<int>(request.settings.restore_food_from)) ||
          (status.water.has_value() &&
           *status.water <
               static_cast<int>(request.settings.restore_water_from));
    }
    if (request.settings.auto_meal && !meal_search_disabled_ && meal_needed) {
      const auto meal = run(maintenance_episode::episode_kind::meal_recovery);
      if (progress_ != nullptr && meal.ok && meal.affected_count != 0U) {
        progress_->publish_notification(
            production_meal_recovered_notification{
                .affected_count = meal.affected_count,
                .player_status = player_status_notification(
                    production_observer_->current_maintenance().player_status),
            });
      }
      if (const auto terminal = accept(meal); terminal.has_value()) {
        return *terminal;
      }
    }

    const bool garbage_enabled = std::ranges::any_of(
        request.settings.garbage_disposal_policy,
        [](const auto& entry) { return entry.second; });
    if (garbage_enabled) {
      const auto garbage =
          run(maintenance_episode::episode_kind::garbage_disposal);
      if (const auto terminal = accept(garbage); terminal.has_value()) {
        return *terminal;
      }
    }
    return production_step_result::completed(true);
  }

  sonar::platform::windows::window_client_snapshot target_;
  std::unique_ptr<runtime_safety::runtime_target_guard> guard_;
  runtime_platform::win32_client_capture_source capture_;
  stage_detection::majestic_fishing_stage_detector stage_detector_;
  automation_adapters::resolved_fishing_memory_source memory_{
      memory_observation::make_windows_memory_connector(),
      automation_adapters::make_common_inventory_open_source(),
      automation_adapters::make_inventory_retry_clock()};
  automation_adapters::mutable_runtime_policy_source policy_;
  runtime_platform::automation_lease_coordinator leases_;
  fishing_episode::fishing_episode_runner runner_;
  inventory_store::inventory_store_episode_runner inventory_runner_;
  maintenance_episode::maintenance_episode_runner maintenance_runner_;
  production_session_loop loop_;
  std::unique_ptr<automation_adapters::runtime_text_recognizer> text_;
  std::unique_ptr<automation_adapters::frame_fishing_observer>
      fishing_observer_;
  std::unique_ptr<automation_adapters::production_frame_observer>
      production_observer_;
  std::unique_ptr<automation_adapters::guarded_production_mutation_port>
      mutation_;
  std::vector<std::string> pending_store_ids_;
  std::optional<bool> session_started_with_net_;
  double last_bait_change_at_seconds_{};
  bool meal_search_disabled_{};
  production_session_progress_sink* progress_{};
};

class windows_fishing_automation_session_factory final
    : public production_automation_session_factory {
 public:
  [[nodiscard]] production_automation_session_admission prepare()
      noexcept override {
    try {
      auto resolution = resolver_.resolve();
      if (!resolution.ready() || !resolution.target.has_value()) {
        return {
            nullptr,
            resolution.reason.empty()
                ? "game_target_unavailable"
                : std::move(resolution.reason),
        };
      }
      runtime_safety::attach_reason attach_reason{};
      auto guard = runtime_safety::runtime_target_guard::attach(
          resolution.target->process.process_id,
          resolution.target->window,
          kMaximumSessionInputPackets,
          attach_reason);
      if (!guard) {
        return {nullptr, attach_reason_key(attach_reason)};
      }
      return {
          std::make_unique<windows_fishing_automation_session>(
              std::move(*resolution.target), std::move(guard)),
          {},
      };
    } catch (const std::exception&) {
      return {nullptr, "production_platform_session_prepare_failed"};
    } catch (...) {
      return {nullptr, "production_platform_session_prepare_failed"};
    }
  }

 private:
  runtime_platform::windows_game_target_resolver resolver_;
};

}  // namespace

std::unique_ptr<production_automation_session_factory>
make_windows_production_automation_session_factory() {
  return std::make_unique<windows_fishing_automation_session_factory>();
}

bool production_capability_snapshot::complete_native_graph() const noexcept {
  return stage_detection_linked && memory_observation_linked &&
      fishing_episode_linked && inventory_store_linked &&
      maintenance_episode_linked && catch_observation_linked;
}

bool production_capability_snapshot::ready_for_live_automation()
    const noexcept {
  return complete_native_graph() && observation_adapters_enabled &&
      mutation_adapters_enabled && session_prepared;
}

production_capability_composition::production_capability_composition()
    : production_capability_composition(
          make_windows_production_automation_session_factory()) {}

production_capability_composition::production_capability_composition(
    std::unique_ptr<production_automation_session_factory> factory)
    : factory_(std::move(factory)) {}

production_capability_composition::~production_capability_composition() {
  stop();
}

production_capability_snapshot production_capability_composition::snapshot()
    const {
  const std::scoped_lock lock(state_gate_);
  return snapshot_locked(steady_now_seconds());
}

production_capability_snapshot
production_capability_composition::snapshot_locked(
    const double now_seconds) const {
  return production_capability_snapshot{
      .stage_detection_linked = true,
      .memory_observation_linked = true,
      .fishing_episode_linked = true,
      .inventory_store_linked = true,
      .maintenance_episode_linked = true,
      .catch_observation_linked = true,
      .observation_adapters_enabled = session_ != nullptr,
      .mutation_adapters_enabled = session_ != nullptr,
      .session_prepared = session_prepared_,
      .operation_running = operation_running_,
      .operation_completed = operation_completed_,
      .last_operation_ok = last_operation_ok_,
      .last_operation_reason = last_operation_reason_,
      .progress_revision = progress_revision_,
      .phase = phase_,
      .detected_stage = detected_stage_,
      .cycles_completed = last_result_.cycles_completed,
      .catches_processed = last_result_.catches_processed,
      .inventory_episodes_completed =
          last_result_.inventory_episodes_completed,
      .maintenance_episodes_completed =
          last_result_.maintenance_episodes_completed,
      .pending_notification_count = pending_notifications_.size(),
      .dropped_notification_count = dropped_notification_count_,
      .statistics = statistics_.Snapshot(now_seconds),
  };
}

std::vector<production_notification_event>
production_capability_composition::take_pending_notifications() noexcept {
  const std::scoped_lock lock(state_gate_);
  std::vector<production_notification_event> result;
  try {
    result.reserve(pending_notifications_.size());
    while (!pending_notifications_.empty()) {
      result.push_back(std::move(pending_notifications_.front()));
      pending_notifications_.pop_front();
    }
  } catch (...) {
    const auto lost = pending_notifications_.size();
    pending_notifications_.clear();
    if (dropped_notification_count_ <=
        (std::numeric_limits<std::uint64_t>::max)() - lost) {
      dropped_notification_count_ += lost;
    } else {
      dropped_notification_count_ =
          (std::numeric_limits<std::uint64_t>::max)();
    }
    result.clear();
  }
  return result;
}

production_capability_admission
production_capability_composition::prepare_session(
    runtime_settings::RuntimeSettingsSnapshot settings,
    const std::uint64_t entitlement_generation,
    const std::int64_t entitlement_expires_unix_seconds) noexcept {
  {
    const std::scoped_lock lock(state_gate_);
    if (session_prepared_ || operation_running_) {
      return {false, "production_capability_session_already_prepared"};
    }
  }
  if (settings.revision == 0U ||
      !runtime_settings::Validate(settings).empty()) {
    return {false, "runtime_settings_required_before_capability_composition"};
  }
  if (entitlement_generation == 0U ||
      entitlement_expires_unix_seconds <= 0) {
    return {false, "signed_entitlement_required_before_capability_composition"};
  }
  if (!factory_) {
    return {false, "production_platform_factory_unavailable"};
  }
  auto prepared = factory_->prepare();
  if (!prepared.session) {
    return {
        false,
        prepared.reason.empty()
            ? "production_platform_session_unavailable"
            : std::move(prepared.reason),
    };
  }
  const std::scoped_lock lock(state_gate_);
  if (lifecycle_revision_ == (std::numeric_limits<std::uint64_t>::max)()) {
    return {false, "production_lifecycle_revision_exhausted"};
  }
  session_ = std::move(prepared.session);
  prepared_settings_ = std::move(settings);
  prepared_entitlement_generation_ = entitlement_generation;
  prepared_entitlement_expires_unix_seconds_ =
      entitlement_expires_unix_seconds;
  ++lifecycle_revision_;
  session_prepared_ = true;
  operation_completed_ = false;
  last_operation_ok_ = false;
  last_operation_reason_.clear();
  last_result_ = {};
  pending_notifications_.clear();
  phase_ = production_phase::idle;
  detected_stage_ = "ready";
  statistics_.SetCustomPrices(prepared_settings_.custom_fish_prices);
  statistics_.Reset(steady_now_seconds());
  advance_progress_revision();
  return {true, "production_capability_composition_ready"};
}

production_capability_admission
production_capability_composition::start_session() noexcept {
  production_session_request request;
  {
    const std::scoped_lock lock(state_gate_);
    if (!session_prepared_ || !session_) {
      return {false, "production_capability_session_not_prepared"};
    }
    if (operation_.joinable() || operation_running_) {
      return {false, "production_capability_operation_already_running"};
    }
    request = {
        .settings = prepared_settings_,
        .entitlement_generation = prepared_entitlement_generation_,
        .entitlement_expires_unix_seconds =
            prepared_entitlement_expires_unix_seconds_,
        .lifecycle_revision = lifecycle_revision_,
    };
    operation_running_ = true;
    operation_completed_ = false;
    phase_ = production_phase::fishing;
    detected_stage_ = "starting";
    statistics_.StartTimer(steady_now_seconds());
    advance_progress_revision();
  }
  try {
    operation_ = std::jthread(
        [this, request](const std::stop_token stop_token) noexcept {
          production_session_result result;
          try {
            result = session_->run(request, stop_token, *this);
          } catch (const std::exception& error) {
            result.reason =
                std::string("production_automation_failed:") + error.what();
          } catch (...) {
            result.reason = "production_automation_failed:unknown";
          }
          const std::scoped_lock lock(state_gate_);
          operation_running_ = false;
          operation_completed_ = true;
          last_operation_ok_ = result.ok;
          last_result_ = result;
          last_operation_reason_ = result.reason.empty()
              ? "production_automation_failed"
              : std::move(result.reason);
          statistics_.StopTimer(steady_now_seconds());
          phase_ = production_phase::idle;
          detected_stage_ = result.stopped ? "stopped" :
              result.ok ? "completed" : "failed";
          advance_progress_revision();
        });
  } catch (...) {
    const std::scoped_lock lock(state_gate_);
    operation_running_ = false;
    operation_completed_ = false;
    return {false, "production_automation_worker_start_failed"};
  }
  return {true, "production_automation_worker_started"};
}

production_capability_admission
production_capability_composition::refresh_entitlement_expiry(
    const std::uint64_t admitted_entitlement_generation,
    const std::int64_t expires_unix_seconds) noexcept {
  const std::scoped_lock lock(state_gate_);
  if (!session_prepared_ || !operation_running_ || !session_ ||
      admitted_entitlement_generation == 0U ||
      admitted_entitlement_generation != prepared_entitlement_generation_ ||
      expires_unix_seconds <= 0) {
    return {false, "production_entitlement_refresh_not_applicable"};
  }
  if (!session_->refresh_entitlement_expiry(
          admitted_entitlement_generation, expires_unix_seconds)) {
    return {false, "production_entitlement_refresh_rejected"};
  }
  prepared_entitlement_expires_unix_seconds_ = expires_unix_seconds;
  return {true, "production_entitlement_refreshed"};
}

production_statistics_reset_result
production_capability_composition::reset_session_statistics() {
  const auto now_seconds = steady_now_seconds();
  const std::scoped_lock lock(state_gate_);
  const auto totals_before_reset =
      statistics_.Snapshot(now_seconds).totals;
  statistics_.Reset(now_seconds);
  advance_progress_revision();
  return {
      .progress = snapshot_locked(now_seconds),
      .totals_before_reset = totals_before_reset,
  };
}

void production_capability_composition::stop() noexcept {
  if (operation_.joinable()) {
    operation_.request_stop();
    operation_.join();
  }
  const std::scoped_lock lock(state_gate_);
  session_.reset();
  prepared_settings_ = {};
  prepared_entitlement_generation_ = 0U;
  prepared_entitlement_expires_unix_seconds_ = 0;
  session_prepared_ = false;
  operation_running_ = false;
}

void production_capability_composition::publish_phase(
    const production_phase phase,
    std::string detected_stage) noexcept {
  try {
    const std::scoped_lock lock(state_gate_);
    phase_ = phase;
    detected_stage_ = std::move(detected_stage);
    advance_progress_revision();
  } catch (...) {
    // Progress cannot authorize side effects. A failed diagnostic projection
    // leaves the previous immutable aggregate in place.
  }
}

void production_capability_composition::record_catch(
    const catch_observation::CatchObservation& observation,
    const bool kept) noexcept {
  try {
    const std::scoped_lock lock(state_gate_);
    statistics_.RecordCatch({
        .fish_id = observation.fish_id.has_value()
            ? std::optional<std::string_view>(*observation.fish_id)
            : std::nullopt,
        .fish_name = observation.fish_text.has_value()
            ? std::optional<std::string_view>(*observation.fish_text)
            : std::nullopt,
        .weight_kg = observation.weight_kg,
        .kept = kept,
        .released = !kept,
        .catch_size_key = observation.quality_key,
    });
    if (observation.fish_text.has_value() &&
        !observation.fish_text->empty()) {
      if (pending_notifications_.size() <
          maximum_pending_production_notifications) {
        pending_notifications_.push_back(production_catch_notification{
            .fish_name = *observation.fish_text,
            .weight_kg = observation.weight_kg,
            .quality_text = observation.quality_label,
            .released = !kept,
            .totals = statistics_.Snapshot(steady_now_seconds()).totals,
            .xp_current = observation.experience.current,
            .xp_total = observation.experience.total,
        });
      } else if (dropped_notification_count_ !=
                 (std::numeric_limits<std::uint64_t>::max)()) {
        ++dropped_notification_count_;
      }
    }
    advance_progress_revision();
  } catch (...) {
    // Statistics are observational and never widen mutation authority.
  }
}

void production_capability_composition::publish_tackle(
    const equipment_recovery::TackleCounts& counts) noexcept {
  try {
    const std::array items{
        session_statistics::TackleItem{"rod", "Удочка", counts.rod},
        session_statistics::TackleItem{"reel", "Катушка", counts.reel},
        session_statistics::TackleItem{"line", "Леска", counts.line},
        session_statistics::TackleItem{"hook", "Крючок", counts.hook},
        session_statistics::TackleItem{"bait", "Наживка", counts.bait},
        session_statistics::TackleItem{"net", "Подсак", counts.net},
    };
    const std::scoped_lock lock(state_gate_);
    statistics_.SetTackleScan(items);
    advance_progress_revision();
  } catch (...) {
    // Tackle projection is latest-only session telemetry.
  }
}

void production_capability_composition::publish_notification(
    production_notification_event notification) noexcept {
  enqueue_notification(std::move(notification));
}

void production_capability_composition::enqueue_notification(
    production_notification_event notification) noexcept {
  try {
    const std::scoped_lock lock(state_gate_);
    if (pending_notifications_.size() >=
        maximum_pending_production_notifications) {
      if (dropped_notification_count_ !=
          (std::numeric_limits<std::uint64_t>::max)()) {
        ++dropped_notification_count_;
      }
      return;
    }
    pending_notifications_.push_back(std::move(notification));
  } catch (...) {
    const std::scoped_lock lock(state_gate_);
    if (dropped_notification_count_ !=
        (std::numeric_limits<std::uint64_t>::max)()) {
      ++dropped_notification_count_;
    }
  }
}

void production_capability_composition::advance_progress_revision() noexcept {
  if (progress_revision_ != (std::numeric_limits<std::uint64_t>::max)()) {
    ++progress_revision_;
  }
}

catch_observation::CatchObservation
production_capability_composition::interpret_catch(
    const catch_observation::RawCatchText& raw) const {
  return catch_observation::Interpret(raw);
}

}  // namespace sonar::fishing::engine_ipc
