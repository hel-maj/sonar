#include "session_commands.h"

#include <chrono>
#include <limits>
#include <stdexcept>

namespace sonar::fishing::engine_ipc::runtime {
namespace {

[[nodiscard]] double monotonic_seconds() noexcept {
  return std::chrono::duration<double>(
      std::chrono::steady_clock::now().time_since_epoch()).count();
}

[[nodiscard]] std::int64_t current_unix_seconds() noexcept {
  return std::chrono::duration_cast<std::chrono::seconds>(
      std::chrono::system_clock::now().time_since_epoch()).count();
}

void publish_session_snapshot(
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::fishing::session_statistics::SessionStatisticsSnapshot&
        snapshot,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    std::uint64_t& snapshot_revision,
    const bool running,
    const bool stopping,
    const sonar::fishing::ipc::v1::FishingPhase phase,
    const std::string_view detected_stage,
    const std::optional<std::string_view> last_error = std::nullopt) {
  if (snapshot_revision == std::numeric_limits<std::uint64_t>::max()) {
    throw std::runtime_error("session_snapshot_revision_exhausted");
  }
  ++snapshot_revision;
  fishing_envelope snapshot_envelope;
  populate_header(
      *snapshot_envelope.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_SNAPSHOT,
      session_id,
      1,
      request.header().request_id(),
      "ready",
      platform_v1::CHANNEL_KIND_EVENTS);
  auto* product_snapshot = snapshot_envelope.mutable_fishing_session_snapshot();
  product_snapshot->set_revision(snapshot_revision);
  product_snapshot->set_running(running);
  product_snapshot->set_stopping(stopping);
  product_snapshot->set_phase(phase);
  product_snapshot->set_detected_stage(detected_stage);
  if (last_error.has_value()) {
    product_snapshot->set_last_error(*last_error);
  }
  product_snapshot->set_accepted_settings_revision(
      settings.AcceptedRevision());
  auto* totals = product_snapshot->mutable_totals();
  totals->set_duration_seconds(snapshot.totals.duration_seconds);
  totals->set_caught_count(snapshot.totals.caught_count);
  totals->set_caught_kg(snapshot.totals.caught_kg);
  totals->set_released_count(snapshot.totals.released_count);
  totals->set_released_kg(snapshot.totals.released_kg);
  totals->set_earned_min(snapshot.totals.earned_min);
  totals->set_earned_max(snapshot.totals.earned_max);
  for (const auto& item : snapshot.tackle_items) {
    auto* tackle = product_snapshot->add_tackle_items();
    tackle->set_key(item.key);
    tackle->set_name(item.name);
    tackle->set_count(item.count);
  }
  for (const auto& item : snapshot.fish_rows) {
    auto* row = product_snapshot->add_fish_rows();
    row->set_fish_id(item.fish_id);
    row->set_name(item.name);
    row->set_caught_count(item.caught_count);
    row->set_caught_kg(item.caught_kg);
    row->set_released_count(item.released_count);
    row->set_released_kg(item.released_kg);
    row->set_kept_count(item.kept_count);
    row->set_kept_kg(item.kept_kg);
    if (item.base_price.has_value()) {
      auto* price = row->mutable_base_price();
      price->set_per_item_min(item.base_price->per_item_min);
      price->set_per_item_max(item.base_price->per_item_max);
      price->set_per_1000_min(item.base_price->per_1000_min);
      price->set_per_1000_max(item.base_price->per_1000_max);
    }
    if (item.custom_price.has_value()) {
      row->set_custom_price(*item.custom_price);
    }
    row->set_earned_min(item.earned_min);
    row->set_earned_max(item.earned_max);
  }
  for (const auto& item : snapshot.catch_sizes) {
    auto* catch_size = product_snapshot->add_catch_sizes();
    catch_size->set_key(item.key);
    catch_size->set_label(item.label);
    catch_size->set_count(item.count);
    catch_size->set_percent(item.percent);
  }
  const auto snapshot_payload = serialize_envelope(snapshot_envelope);
  event_writer.publish_latest_snapshot(snapshot_payload);
}

[[nodiscard]] sonar::fishing::ipc::v1::FishingPhase wire_phase(
    const sonar::fishing::engine_ipc::production_phase phase) noexcept {
  using native = sonar::fishing::engine_ipc::production_phase;
  using wire = sonar::fishing::ipc::v1::FishingPhase;
  switch (phase) {
    case native::idle: return wire::FISHING_PHASE_IDLE;
    case native::fishing: return wire::FISHING_PHASE_REELING;
    case native::catch_processing: return wire::FISHING_PHASE_CATCH;
    case native::inventory: return wire::FISHING_PHASE_INVENTORY;
    case native::maintenance: return wire::FISHING_PHASE_RECOVERY;
    case native::stopping: return wire::FISHING_PHASE_STOPPING;
  }
  return wire::FISHING_PHASE_UNSPECIFIED;
}

}  // namespace

void publish_pending_production_progress(
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const std::optional<fishing_envelope>& active_start_request,
    const std::string_view session_id,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    std::uint64_t& snapshot_revision,
    std::uint64_t& published_progress_revision) {
  if (!active_start_request.has_value()) {
    return;
  }
  const auto progress = capabilities.snapshot();
  if (progress.progress_revision <= published_progress_revision) {
    return;
  }
  if (progress.operation_completed && lifecycle.running()) {
    static_cast<void>(lifecycle.stop());
  }
  publish_session_snapshot(
      event_writer,
      *active_start_request,
      session_id,
      progress.statistics,
      settings,
      headers,
      snapshot_revision,
      lifecycle.running() && !progress.operation_completed,
      progress.phase ==
          sonar::fishing::engine_ipc::production_phase::stopping,
      wire_phase(progress.phase),
      progress.detected_stage,
      progress.operation_completed && !progress.last_operation_ok
          ? std::optional<std::string_view>(progress.last_operation_reason)
          : std::nullopt);
  published_progress_revision = progress.progress_revision;
}

void handle_start_read_only_session(
    const HANDLE control_pipe,
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::fishing::session_statistics::SessionStatistics& statistics,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness,
    std::uint64_t& snapshot_revision) {
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_platform() ||
      !request.platform().has_start_engine_session() ||
      !request.platform().start_engine_session().read_only() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "start-engine-session") {
    throw std::runtime_error("start_read_only_session_invalid");
  }
  if (settings.AcceptedRevision() == 0) {
    throw std::runtime_error("runtime_settings_required_before_session");
  }
  const auto current_settings = settings.Current();
  if (!current_settings.has_value()) {
    throw std::runtime_error("runtime_settings_snapshot_missing");
  }

  statistics.SetCustomPrices(current_settings->custom_fish_prices);
  statistics.Reset(monotonic_seconds());
  statistics.StartTimer(monotonic_seconds());

  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      3,
      request.header().request_id(),
      "completed");
  auto* command_result = response.mutable_platform()->mutable_command_result();
  command_result->set_command_id("start-engine-session");
  command_result->set_status("completed");
  command_result->set_reason("read_only_session_started");
  write_envelope(control_pipe, response);

  publish_session_snapshot(
      event_writer,
      request,
      session_id,
      statistics.Snapshot(monotonic_seconds()),
      settings,
      headers,
      snapshot_revision,
      false,
      false,
      sonar::fishing::ipc::v1::FISHING_PHASE_IDLE,
      "read_only_session_started");
}

bool handle_start_fishing_session(
    const HANDLE control_pipe,
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    const engine_authority_mode authority_mode,
    const bool side_effects_negotiated,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    sonar::fishing::session_statistics::SessionStatistics& statistics,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    const sonar::fishing::engine_ipc::accepted_entitlement& entitlement,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness,
    std::uint64_t& snapshot_revision,
    std::uint64_t& published_progress_revision) {
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_start_fishing_session_request() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "start-fishing-session") {
    throw std::runtime_error("start_fishing_session_request_invalid");
  }

  const auto current_settings = settings.Current();
  auto start_context =
      sonar::fishing::engine_ipc::start_session_context{
        .authority_mode = authority_mode,
        .side_effects_negotiated = side_effects_negotiated,
        .expected_settings_revision =
            request.start_fishing_session_request().expected_revision(),
        .accepted_settings_revision = settings.AcceptedRevision(),
        .settings_snapshot_present = current_settings.has_value(),
        .entitlement = entitlement,
        .now_unix_seconds = current_unix_seconds(),
        // Pure lifecycle admission must reject authority/settings/license
        // failures before the production factory enumerates any process or
        // window. The real composition result replaces this immediately.
        .capability_composition_ready = true,
        .capability_reason = "production_capability_preflight_pending",
      };
  auto transition = lifecycle.validate_start(start_context);
  sonar::fishing::engine_ipc::production_capability_admission
      capability_admission;
  sonar::fishing::engine_ipc::production_capability_admission
      execution_admission;
  if (transition.accepted) {
    capability_admission = capabilities.prepare_session(
        *current_settings,
        entitlement.generation,
        entitlement.expires_unix_seconds);
    start_context.capability_composition_ready = capability_admission.accepted;
    start_context.capability_reason = capability_admission.reason;
    transition = lifecycle.start(start_context);
  }
  if (transition.accepted) {
    execution_admission = capabilities.start_session();
    if (!execution_admission.accepted) {
      capabilities.stop();
      static_cast<void>(lifecycle.stop());
      transition = {
          false,
          "rejected",
          execution_admission.reason.empty()
              ? std::string_view{"production_automation_worker_unavailable"}
              : std::string_view{execution_admission.reason},
      };
    }
  }
  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      1,
      request.header().request_id(),
      transition.status);
  auto* command_result = response.mutable_platform()->mutable_command_result();
  command_result->set_command_id("start-fishing-session");
  command_result->set_status(transition.status);
  command_result->set_reason(transition.reason);
  write_envelope(control_pipe, response);

  auto progress = capabilities.snapshot();
  if (progress.operation_completed && lifecycle.running()) {
    static_cast<void>(lifecycle.stop());
  }
  publish_session_snapshot(
      event_writer,
      request,
      session_id,
      transition.accepted
          ? progress.statistics
          : statistics.Snapshot(monotonic_seconds()),
      settings,
      headers,
      snapshot_revision,
      lifecycle.running() && !progress.operation_completed,
      false,
      transition.accepted
          ? wire_phase(progress.phase)
          : sonar::fishing::ipc::v1::FISHING_PHASE_IDLE,
      transition.accepted ? progress.detected_stage : transition.reason,
      transition.accepted
          ? progress.operation_completed && !progress.last_operation_ok
              ? std::optional<std::string_view>(progress.last_operation_reason)
              : std::nullopt
          : std::optional<std::string_view>(transition.reason));
  if (transition.accepted) {
    published_progress_revision = progress.progress_revision;
  }
  return transition.accepted;
}

void handle_stop_automation(
    const HANDLE control_pipe,
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness,
    std::uint64_t& snapshot_revision) {
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_platform() ||
      !request.platform().has_stop_automation() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "stop-automation") {
    throw std::runtime_error("stop_automation_request_invalid");
  }

  capabilities.stop();
  const auto transition = lifecycle.stop();

  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      1,
      request.header().request_id(),
      transition.status);
  auto* command_result = response.mutable_platform()->mutable_command_result();
  command_result->set_command_id("stop-automation");
  command_result->set_status(transition.status);
  command_result->set_reason(transition.reason);
  write_envelope(control_pipe, response);

  publish_session_snapshot(
      event_writer,
      request,
      session_id,
      capabilities.snapshot().statistics,
      settings,
      headers,
      snapshot_revision,
      false,
      false,
      sonar::fishing::ipc::v1::FISHING_PHASE_IDLE,
      transition.reason);
}

}  // namespace sonar::fishing::engine_ipc::runtime
