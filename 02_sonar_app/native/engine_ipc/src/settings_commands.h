#pragma once

#include <Windows.h>

#include <string_view>

#include "engine_protocol.h"
#include "sonar/fishing/runtime_settings/runtime_settings.h"

namespace sonar::fishing::engine_ipc::runtime {

void handle_apply_runtime_settings(
    HANDLE pipe,
    const fishing_envelope& request,
    std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness);

}  // namespace sonar::fishing::engine_ipc::runtime
