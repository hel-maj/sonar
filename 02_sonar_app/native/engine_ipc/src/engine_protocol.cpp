#include "engine_protocol.h"

#include <array>
#include <stdexcept>
#include <string>
#include <utility>

#include "sonar/platform/ipc/frame_codec.hpp"
#include "sonar/platform/ipc/header_validation.hpp"
#include "sonar/platform/ipc/handshake_contract.hpp"
#include "sonar/platform/ipc/pipe_frame_io.hpp"

namespace sonar::fishing::engine_ipc::runtime {
namespace {

constexpr std::string_view kCatchQualityCapabilityId = "catch-quality.aggregate";
constexpr std::string_view kCatchDispositionCapabilityId =
    "catch-disposition.evaluate";
constexpr std::string_view kSessionStatisticsCapabilityId =
    "fishing-session.statistics";
constexpr std::string_view kRuntimeSettingsCapabilityId =
    "fishing-runtime-settings.apply";
constexpr std::string_view kSignedEntitlementCapabilityId =
    "signed-entitlement.verify";
constexpr std::string_view kNotificationEventsCapabilityId =
    "fishing-notifications.events";

}  // namespace

std::vector<std::byte> serialize_envelope(
    const fishing_envelope& envelope) {
  std::string payload;
  if (!envelope.SerializeToString(&payload)) {
    throw std::runtime_error("protobuf_serialize_failed");
  }
  const auto bytes = std::as_bytes(
      std::span(payload.data(), payload.size()));
  return {bytes.begin(), bytes.end()};
}

void write_envelope(
    const HANDLE pipe,
    const fishing_envelope& envelope,
    const std::size_t maximum) {
  const auto payload = serialize_envelope(envelope);
  sonar::platform::ipc::write_framed_payload(
      pipe,
      payload,
      maximum,
      kIoTimeoutMilliseconds);
}

fishing_envelope read_envelope(const HANDLE pipe) {
  const auto payload = sonar::platform::ipc::read_framed_payload(
      pipe,
      sonar::platform::ipc::control_frame_maximum,
      kIoTimeoutMilliseconds);
  fishing_envelope envelope;
  if (!envelope.ParseFromArray(payload.data(), static_cast<int>(payload.size()))) {
    throw std::runtime_error("protobuf_parse_failed");
  }
  return envelope;
}

void populate_header(
    platform_v1::EnvelopeHeader& header,
    sonar::platform::ipc::session_header_factory& headers,
    const platform_v1::MessageKind message_kind,
    const std::string_view session_id,
    const std::uint64_t sequence,
    const std::string_view correlation_id,
    const std::string_view status,
    const platform_v1::ChannelKind channel) {
  static_cast<void>(session_id);
  static_cast<void>(sequence);
  header = headers.create(
      channel,
      message_kind,
      sonar::platform::ipc::envelope_metadata{
          .correlation_id = correlation_id,
          .status = status,
      });
}

void require_host_envelope(
    const fishing_envelope& envelope,
    const platform_v1::MessageKind expected_kind,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  std::string_view reason;
  if (!envelope.has_header() ||
      !sonar::platform::ipc::validate_session_header(
          envelope.header(),
          identity,
          platform_v1::PEER_ROLE_HOST,
          platform_v1::CHANNEL_KIND_CONTROL,
          expected_kind,
          reason)) {
    throw std::runtime_error(
        reason.empty() ? "header_missing" : std::string(reason));
  }
  if (!incoming_sequences.validate_and_advance(envelope.header(), reason)) {
    throw std::runtime_error(std::string(reason));
  }
  if (!liveness.try_mark_alive(reason)) {
    throw std::runtime_error(std::string(reason));
  }
}

void send_handshake_hello(
    const HANDLE pipe,
    const std::string_view session_id,
    const std::string_view nonce,
    const engine_authority_mode authority_mode,
    sonar::platform::ipc::session_header_factory& headers) {
  fishing_envelope envelope;
  populate_header(
      *envelope.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_HANDSHAKE,
      session_id,
      1,
      {},
      "pending");
  auto* hello = envelope.mutable_platform()->mutable_handshake_hello();
  hello->set_minimum_protocol_minor(sonar::platform::ipc::protocol_minor);
  hello->set_maximum_protocol_minor(sonar::platform::ipc::protocol_minor);
  hello->set_bootstrap_nonce(nonce);
  auto* catch_quality = hello->add_capabilities();
  catch_quality->set_capability_id(kCatchQualityCapabilityId);
  catch_quality->set_major(1);
  catch_quality->set_minor(0);
  auto* catch_disposition = hello->add_capabilities();
  catch_disposition->set_capability_id(kCatchDispositionCapabilityId);
  catch_disposition->set_major(1);
  catch_disposition->set_minor(0);
  auto* session_statistics = hello->add_capabilities();
  session_statistics->set_capability_id(kSessionStatisticsCapabilityId);
  session_statistics->set_major(1);
  session_statistics->set_minor(0);
  auto* runtime_settings = hello->add_capabilities();
  runtime_settings->set_capability_id(kRuntimeSettingsCapabilityId);
  runtime_settings->set_major(1);
  runtime_settings->set_minor(0);
  auto* signed_entitlement = hello->add_capabilities();
  signed_entitlement->set_capability_id(kSignedEntitlementCapabilityId);
  signed_entitlement->set_major(1);
  signed_entitlement->set_minor(0);
  auto* notification_events = hello->add_capabilities();
  notification_events->set_capability_id(kNotificationEventsCapabilityId);
  notification_events->set_major(1);
  notification_events->set_minor(0);
  sonar::fishing::engine_ipc::apply_handshake_mode(*hello, authority_mode);
  write_envelope(pipe, envelope);
}

bool require_handshake_accepted(
    const fishing_envelope& envelope,
    const sonar::platform::ipc::session_identity_expectation& identity,
    const engine_authority_mode authority_mode,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  if (!envelope.has_platform() ||
      !envelope.platform().has_handshake_accepted()) {
    throw std::runtime_error("handshake_accepted_missing");
  }
  const std::array required_capabilities{
      sonar::platform::ipc::capability_requirement{
          .capability_id = kCatchQualityCapabilityId,
          .major = 1,
          .minimum_minor = 0,
      },
      sonar::platform::ipc::capability_requirement{
          .capability_id = kCatchDispositionCapabilityId,
          .major = 1,
          .minimum_minor = 0,
      },
      sonar::platform::ipc::capability_requirement{
          .capability_id = kSessionStatisticsCapabilityId,
          .major = 1,
          .minimum_minor = 0,
      },
      sonar::platform::ipc::capability_requirement{
          .capability_id = kRuntimeSettingsCapabilityId,
          .major = 1,
          .minimum_minor = 0,
      },
      sonar::platform::ipc::capability_requirement{
          .capability_id = kSignedEntitlementCapabilityId,
          .major = 1,
          .minimum_minor = 0,
      },
      sonar::platform::ipc::capability_requirement{
          .capability_id = kNotificationEventsCapabilityId,
          .major = 1,
          .minimum_minor = 0,
      },
      sonar::platform::ipc::capability_requirement{
          .capability_id =
              sonar::fishing::engine_ipc::fishing_session_control_capability_id,
          .major = 1,
          .minimum_minor = 0,
      },
  };
  const auto mode_policy =
      sonar::fishing::engine_ipc::handshake_policy(authority_mode);
  const auto required_capability_count =
      mode_policy.advertises_session_control
          ? required_capabilities.size()
          : required_capabilities.size() - 1;
  const sonar::platform::ipc::handshake_acceptance_expectation expectation{
      .identity = identity,
      .minimum_protocol_minor = sonar::platform::ipc::protocol_minor,
      .maximum_protocol_minor = sonar::platform::ipc::protocol_minor,
      .required_capabilities = std::span(required_capabilities).first(
          required_capability_count),
      .side_effects_may_be_enabled = mode_policy.side_effects_may_be_enabled,
  };
  std::string_view reason;
  if (!sonar::platform::ipc::validate_handshake_acceptance(
          envelope.header(),
          envelope.platform().handshake_accepted(),
          expectation,
          reason)) {
    throw std::runtime_error(std::string(reason));
  }
  if (!incoming_sequences.validate_and_advance(envelope.header(), reason)) {
    throw std::runtime_error(std::string(reason));
  }
  if (!liveness.try_mark_alive(reason)) {
    throw std::runtime_error(std::string(reason));
  }
  return envelope.platform().handshake_accepted().side_effects_enabled();
}

void handle_heartbeat(
    const HANDLE pipe,
    const fishing_envelope& request,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::heartbeat_responder& responder,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  if (!request.has_header() || !request.has_platform() ||
      !request.platform().has_heartbeat()) {
    throw std::runtime_error("heartbeat_request_invalid");
  }
  platform_v1::EnvelopeHeader acknowledgement_header;
  platform_v1::HeartbeatAcknowledged acknowledgement;
  std::string_view reason;
  if (!responder.try_acknowledge(
          request.header(),
          request.platform().heartbeat(),
          identity,
          incoming_sequences,
          headers,
          acknowledgement_header,
          acknowledgement,
          reason)) {
    throw std::runtime_error(std::string(reason));
  }
  if (!liveness.try_mark_alive(reason)) {
    throw std::runtime_error(std::string(reason));
  }
  fishing_envelope response;
  *response.mutable_header() = std::move(acknowledgement_header);
  *response.mutable_platform()->mutable_heartbeat_acknowledged() =
      std::move(acknowledgement);
  write_envelope(pipe, response);
}

}  // namespace sonar::fishing::engine_ipc::runtime
