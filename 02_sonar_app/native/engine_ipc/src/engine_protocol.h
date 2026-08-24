#pragma once

#include <Windows.h>

#include <cstddef>
#include <cstdint>
#include <span>
#include <string_view>
#include <vector>

#include "ipc/v1/sonar_fishing.pb.h"
#include "sonar/fishing/engine_ipc/engine_mode.h"
#include "sonar/platform/ipc/frame_codec.hpp"
#include "sonar/platform/ipc/heartbeat_liveness.hpp"
#include "sonar/platform/ipc/session_header_contract.hpp"
#include "sonar/platform/ipc/session_header_factory.hpp"
#include "sonar/platform/ipc/session_sequence_gate.hpp"

namespace sonar::fishing::engine_ipc::runtime {

using fishing_envelope = sonar::fishing::ipc::v1::Envelope;
namespace platform_v1 = sonar::platform::ipc::v1;

constexpr std::uint32_t kIoTimeoutMilliseconds = 5000;

[[nodiscard]] std::vector<std::byte> serialize_envelope(
    const fishing_envelope& envelope);

void write_envelope(
    HANDLE pipe,
    const fishing_envelope& envelope,
    std::size_t maximum = sonar::platform::ipc::control_frame_maximum);

[[nodiscard]] fishing_envelope read_envelope(HANDLE pipe);

void populate_header(
    platform_v1::EnvelopeHeader& header,
    sonar::platform::ipc::session_header_factory& headers,
    platform_v1::MessageKind message_kind,
    std::string_view session_id,
    std::uint64_t sequence,
    std::string_view correlation_id,
    std::string_view status,
    platform_v1::ChannelKind channel = platform_v1::CHANNEL_KIND_CONTROL);

void require_host_envelope(
    const fishing_envelope& envelope,
    platform_v1::MessageKind expected_kind,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness);

void send_handshake_hello(
    HANDLE pipe,
    std::string_view session_id,
    std::string_view nonce,
    engine_authority_mode authority_mode,
    sonar::platform::ipc::session_header_factory& headers);

[[nodiscard]] bool require_handshake_accepted(
    const fishing_envelope& envelope,
    const sonar::platform::ipc::session_identity_expectation& identity,
    engine_authority_mode authority_mode,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness);

void handle_heartbeat(
    HANDLE pipe,
    const fishing_envelope& request,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::heartbeat_responder& responder,
    sonar::platform::ipc::peer_liveness_tracker& liveness);

}  // namespace sonar::fishing::engine_ipc::runtime
