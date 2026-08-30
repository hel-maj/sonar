#pragma once

#include <Windows.h>

#include <cstdint>
#include <optional>
#include <string_view>

#include "engine_protocol.h"
#include "sonar/fishing/engine_ipc/event_delivery.h"
#include "sonar/fishing/engine_ipc/production_composition.h"
#include "sonar/fishing/engine_ipc/session_lifecycle.h"
#include "sonar/fishing/runtime_settings/runtime_settings.h"
#include "sonar/fishing/session_statistics/session_statistics.h"

namespace sonar::fishing::engine_ipc::runtime {

void publish_pending_production_progress(
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const std::optional<fishing_envelope>& active_start_request,
    std::string_view session_id,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    std::uint64_t& snapshot_revision,
    std::uint64_t& published_progress_revision);

void handle_start_read_only_session(
    HANDLE control_pipe,
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const fishing_envelope& request,
    std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::fishing::session_statistics::SessionStatistics& statistics,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness,
    std::uint64_t& snapshot_revision);

[[nodiscard]] bool handle_start_fishing_session(
    HANDLE control_pipe,
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const fishing_envelope& request,
    std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    engine_authority_mode authority_mode,
    bool side_effects_negotiated,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    sonar::fishing::session_statistics::SessionStatistics& statistics,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    const sonar::fishing::engine_ipc::accepted_entitlement& entitlement,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness,
    std::uint64_t& snapshot_revision,
    std::uint64_t& published_progress_revision);

void handle_reset_session_statistics(
    HANDLE control_pipe,
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const fishing_envelope& request,
    const std::optional<fishing_envelope>& active_start_request,
    std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    engine_authority_mode authority_mode,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness,
    std::uint64_t& snapshot_revision,
    std::uint64_t& published_progress_revision);

void handle_stop_automation(
    HANDLE control_pipe,
    sonar::fishing::engine_ipc::event_writer& event_writer,
    const fishing_envelope& request,
    std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    const sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness,
    std::uint64_t& snapshot_revision);

}  // namespace sonar::fishing::engine_ipc::runtime
