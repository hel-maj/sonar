#pragma once

#include <Windows.h>

#include <string_view>

#include "engine_protocol.h"
#include "sonar/fishing/engine_ipc/production_composition.h"
#include "sonar/fishing/engine_ipc/session_lifecycle.h"

namespace sonar::fishing::engine_ipc::runtime {

void handle_apply_signed_entitlement(
    HANDLE pipe,
    const fishing_envelope& request,
    std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    engine_authority_mode authority_mode,
    std::string_view production_machine_fingerprint,
    sonar::fishing::engine_ipc::accepted_entitlement& accepted_entitlement,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness);

void handle_revoke_signed_entitlement(
    HANDLE pipe,
    const fishing_envelope& request,
    std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::fishing::engine_ipc::accepted_entitlement& accepted_entitlement,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness);

}  // namespace sonar::fishing::engine_ipc::runtime
