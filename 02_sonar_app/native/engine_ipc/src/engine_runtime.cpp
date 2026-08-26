#include "engine_runtime.h"

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <optional>
#include <limits>
#include <span>
#include <stdexcept>
#include <string_view>

#include "diagnostic_commands.h"
#include "engine_bootstrap.h"
#include "engine_protocol.h"
#include "entitlement_commands.h"
#include "inventory_events.h"
#include "session_commands.h"
#include "settings_commands.h"
#include "sonar/fishing/engine_ipc/event_delivery.h"
#include "sonar/fishing/engine_ipc/inventory_observation_worker.h"
#include "sonar/fishing/engine_ipc/production_composition.h"
#include "sonar/fishing/engine_ipc/session_lifecycle.h"
#include "sonar/fishing/runtime_settings/runtime_settings.h"
#include "sonar/fishing/session_statistics/session_statistics.h"
#include "sonar/platform/ipc/local_pipe_client_pair.hpp"
#include "sonar/platform/ipc/pipe_frame_io.hpp"

namespace sonar::fishing::engine_ipc::runtime {
namespace {

constexpr std::string_view kProductId = "fishing";
constexpr bool kLiveInventoryObservationEnabled =
    SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS == 0;

}  // namespace

int run_engine_runtime() {
  const auto bootstrap = load_engine_bootstrap();
  auto pipes = sonar::platform::ipc::local_pipe_client_pair::connect(
      bootstrap.control_pipe_name,
      bootstrap.event_pipe_name,
      bootstrap.host_process_id,
      sonar::platform::ipc::local_pipe_pair_limits{},
      kIoTimeoutMilliseconds);
  const sonar::platform::ipc::session_identity_expectation identity{
      .product_id = kProductId,
      .host_build_id = bootstrap.build_identity.host_build_id,
      .engine_build_id = bootstrap.build_identity.engine_build_id,
      .bundle_manifest_hash = bootstrap.build_identity.bundle_manifest_hash,
      .schema_hash = SONAR_FISHING_SCHEMA_SHA256,
      .session_id = bootstrap.session_id,
      .session_generation = 1,
  };
  sonar::platform::ipc::session_header_factory headers(
      identity, platform_v1::PEER_ROLE_ENGINE);
  sonar::platform::ipc::incoming_sequence_gate incoming_sequences;
  sonar::platform::ipc::heartbeat_responder heartbeat_responder;
  sonar::platform::ipc::peer_liveness_tracker liveness(
      std::chrono::seconds(15));
  send_handshake_hello(
      pipes.control_pipe(),
      bootstrap.session_id,
      bootstrap.nonce,
      bootstrap.authority_mode,
      headers);
  const bool side_effects_negotiated = require_handshake_accepted(
      read_envelope(pipes.control_pipe()),
      identity,
      bootstrap.authority_mode,
      incoming_sequences,
      liveness);
  sonar::fishing::runtime_settings::RuntimeSettingsOwner runtime_settings;
  sonar::fishing::session_statistics::SessionStatistics statistics(
      sonar::fishing::session_statistics::DefaultPriceCatalog());
  sonar::fishing::engine_ipc::event_writer event_writer(
      [event_pipe = pipes.events_pipe()](
          const std::span<const std::byte> payload,
          const std::stop_token cancellation) {
        sonar::platform::ipc::write_framed_payload(
            event_pipe,
            payload,
            sonar::platform::ipc::event_frame_maximum,
            kIoTimeoutMilliseconds,
            cancellation);
      });
  sonar::fishing::engine_ipc::inventory_observation_worker inventory_observation(
      sonar::fishing::engine_ipc::create_win32_inventory_sampler(
          kLiveInventoryObservationEnabled));
  std::uint64_t snapshot_revision = 0;
  sonar::fishing::engine_ipc::accepted_entitlement accepted_entitlement;
#if defined(SONAR_FISHING_DEVELOPER_FULL_ACCESS)
  if (bootstrap.authority_mode == engine_authority_mode::developer_full_access) {
    accepted_entitlement.generation = 1U;
    accepted_entitlement.expires_unix_seconds =
        std::numeric_limits<std::int64_t>::max();
  }
#endif
  sonar::fishing::engine_ipc::fishing_session_lifecycle session_lifecycle;
  sonar::fishing::engine_ipc::production_capability_composition
      production_capabilities;
  std::optional<fishing_envelope> active_start_request;
  std::uint64_t published_progress_revision = 0U;
  bool shutdown_requested = false;
  while (!shutdown_requested) {
    auto request = read_envelope(pipes.control_pipe());
    if (const auto inventory = inventory_observation.poll();
        inventory.has_value()) {
      publish_inventory_state(
          event_writer,
          inventory->state,
          bootstrap.session_id,
          headers,
          inventory->revision,
          inventory->observed_at_ms);
    }
    publish_pending_production_progress(
        event_writer,
        active_start_request,
        bootstrap.session_id,
        session_lifecycle,
        production_capabilities,
        runtime_settings,
        headers,
        snapshot_revision,
        published_progress_revision);
    if (request.has_platform() && request.platform().has_heartbeat()) {
      handle_heartbeat(
          pipes.control_pipe(),
          request,
          identity,
          headers,
          incoming_sequences,
          heartbeat_responder,
          liveness);
    } else if (request.has_apply_runtime_settings_request()) {
      handle_apply_runtime_settings(
          pipes.control_pipe(),
          request,
          bootstrap.session_id,
          identity,
          runtime_settings,
          headers,
          incoming_sequences,
          liveness);
    } else if (request.has_apply_signed_entitlement_request()) {
      handle_apply_signed_entitlement(
          pipes.control_pipe(),
          request,
          bootstrap.session_id,
          identity,
          bootstrap.authority_mode,
          bootstrap.machine_fingerprint,
          accepted_entitlement,
          session_lifecycle,
          production_capabilities,
          headers,
          incoming_sequences,
          liveness);
    } else if (request.has_revoke_signed_entitlement_request()) {
      handle_revoke_signed_entitlement(
          pipes.control_pipe(),
          request,
          bootstrap.session_id,
          identity,
          accepted_entitlement,
          session_lifecycle,
          production_capabilities,
          headers,
          incoming_sequences,
          liveness);
    } else if (request.has_start_fishing_session_request()) {
      const bool started = handle_start_fishing_session(
          pipes.control_pipe(),
          event_writer,
          request,
          bootstrap.session_id,
          identity,
          bootstrap.authority_mode,
          side_effects_negotiated,
          session_lifecycle,
          production_capabilities,
          statistics,
          runtime_settings,
          accepted_entitlement,
          headers,
          incoming_sequences,
          liveness,
          snapshot_revision,
          published_progress_revision);
      if (started) {
        active_start_request = request;
      }
    } else if (request.has_platform() &&
               request.platform().has_stop_automation()) {
      handle_stop_automation(
          pipes.control_pipe(),
          event_writer,
          request,
          bootstrap.session_id,
          identity,
          session_lifecycle,
          production_capabilities,
          runtime_settings,
          headers,
          incoming_sequences,
          liveness,
          snapshot_revision);
      active_start_request.reset();
      published_progress_revision =
          production_capabilities.snapshot().progress_revision;
    } else if (request.has_platform() &&
               request.platform().has_start_engine_session()) {
      handle_start_read_only_session(
          pipes.control_pipe(),
          event_writer,
          request,
          bootstrap.session_id,
          identity,
          statistics,
          runtime_settings,
          headers,
          incoming_sequences,
          liveness,
          snapshot_revision);
    } else if (request.has_classify_catch_quality_request()) {
      handle_catch_quality(
          pipes.control_pipe(),
          request,
          bootstrap.session_id,
          identity,
          headers,
          incoming_sequences,
          liveness);
    } else if (request.has_evaluate_catch_disposition_request()) {
      handle_catch_disposition(
          pipes.control_pipe(),
          request,
          bootstrap.session_id,
          identity,
          headers,
          incoming_sequences,
          liveness);
    } else if (request.has_platform() &&
               request.platform().has_shutdown_engine()) {
      handle_shutdown(
          pipes.control_pipe(),
          request,
          bootstrap.session_id,
          identity,
          headers,
          incoming_sequences,
          liveness);
      shutdown_requested = true;
    } else {
      throw std::runtime_error("offline_command_not_supported");
    }
  }
  production_capabilities.stop();
  static_cast<void>(session_lifecycle.stop());
  inventory_observation.stop();
  event_writer.close_and_drain();
  liveness.stop();
  std::cout << "PASS offline Fishing diagnostics; production authority unchanged\n";
  return 0;
}

}  // namespace sonar::fishing::engine_ipc::runtime
