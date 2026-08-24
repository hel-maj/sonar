#include "entitlement_commands.h"

#include <array>
#include <chrono>
#include <cstdint>
#include <span>
#include <string>

#include "sonar/fishing/entitlement/entitlement.h"

#if SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS
#include "offline_entitlement_fixture.h"
#endif

namespace sonar::fishing::engine_ipc::runtime {
namespace {

[[nodiscard]] std::string_view entitlement_reason_key(
    const sonar::fishing::entitlement::entitlement_error error) noexcept {
  using reason = sonar::fishing::entitlement::entitlement_error;
  switch (error) {
    case reason::none:
      return "entitlement_accepted";
    case reason::trust_root_missing:
      return "entitlement_trust_root_missing";
    case reason::transport_rejected:
      return "entitlement_transport_rejected";
    case reason::claims_malformed:
      return "entitlement_claims_malformed";
    case reason::validation_rejected:
      return "entitlement_validation_rejected";
    case reason::product_mismatch:
      return "entitlement_product_mismatch";
    case reason::audience_mismatch:
      return "entitlement_audience_mismatch";
    case reason::machine_mismatch:
      return "entitlement_machine_mismatch";
    case reason::bundle_mismatch:
      return "entitlement_bundle_mismatch";
    case reason::policy_mismatch:
      return "entitlement_policy_mismatch";
    case reason::required_feature_missing:
      return "entitlement_required_feature_missing";
    case reason::lease_invalid:
      return "entitlement_lease_invalid";
    case reason::lease_replayed:
      return "entitlement_lease_replayed";
  }
  return "entitlement_rejected";
}

void reconcile_active_entitlement(
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    const sonar::fishing::engine_ipc::accepted_entitlement& entitlement) {
  if (!lifecycle.running()) {
    return;
  }
  if (entitlement.generation != 0U) {
    const auto refreshed = capabilities.refresh_entitlement_expiry(
        lifecycle.entitlement_generation(),
        entitlement.expires_unix_seconds);
    if (refreshed.accepted) {
      return;
    }
  }
  // A rejected/revoked replacement or a refresh race cannot leave the
  // previously admitted short lease active. Stop and drain the one coarse
  // Engine operation before acknowledging the entitlement command.
  capabilities.stop();
  static_cast<void>(lifecycle.stop());
}

}  // namespace

void handle_apply_signed_entitlement(
    const HANDLE pipe,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    const engine_authority_mode authority_mode,
    const std::string_view production_machine_fingerprint,
    sonar::fishing::engine_ipc::accepted_entitlement& accepted_entitlement,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  static_cast<void>(authority_mode);
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_apply_signed_entitlement_request() ||
      !request.apply_signed_entitlement_request().has_envelope() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "apply-signed-entitlement") {
    throw std::runtime_error("apply_signed_entitlement_request_invalid");
  }

  const auto& source = request.apply_signed_entitlement_request().envelope();
  const auto raw_body = std::as_bytes(
      std::span(source.raw_body().data(), source.raw_body().size()));
  const sonar::fishing::entitlement::signed_entitlement_envelope_view envelope{
      .method = source.method(),
      .request_target = source.request_target(),
      .host = source.host(),
      .date_header = source.date_header(),
      .digest_header = source.digest_header(),
      .signature_header = source.signature_header(),
      .raw_body = raw_body,
  };
  bool accepted = false;
  auto error = sonar::fishing::entitlement::entitlement_error::claims_malformed;
  std::uint64_t next_generation = 0;
  std::int64_t expires_unix_seconds = 0;
#if SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS
  if (authority_mode == engine_authority_mode::offline_diagnostics) {
    const auto verified = sonar::fishing::entitlement::verify(
        envelope,
        sonar::fishing::engine_ipc::offline_entitlement_fixture::trust(),
        sonar::fishing::engine_ipc::offline_entitlement_fixture::claims(
            accepted_entitlement.generation));
    accepted = verified.accepted();
    error = verified.error;
    if (accepted) {
      next_generation = verified.claims->generation;
      expires_unix_seconds = verified.claims->expires_unix_seconds;
    }
  } else
#endif
  {
    constexpr std::array<std::string_view, 1> required_features = {"fishing"};
    const auto now_unix_seconds = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    const auto verified = sonar::fishing::entitlement::verify_keygen(
        envelope,
        sonar::fishing::entitlement::production_keygen_trust_policy(
            now_unix_seconds),
        sonar::fishing::entitlement::keygen_claim_policy_view{
            .expected_machine_fingerprint = production_machine_fingerprint,
            .required_features = required_features,
            .last_accepted_generation = accepted_entitlement.generation,
            .maximum_lease_seconds = 600,
        });
    accepted = verified.accepted();
    error = verified.error;
    if (accepted) {
      next_generation = verified.claims->generation;
      expires_unix_seconds = verified.claims->lease_expires_unix_seconds;
    }
  }

  // Any rejected replacement clears the previous short authority. A signed
  // denial, malformed message or replay can never leave a stale lease active.
  if (accepted) {
    accepted_entitlement.generation = next_generation;
    accepted_entitlement.expires_unix_seconds = expires_unix_seconds;
  } else {
    accepted_entitlement.clear();
  }
  reconcile_active_entitlement(
      lifecycle, capabilities, accepted_entitlement);

  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      2,
      request.header().request_id(),
      accepted ? "completed" : "rejected");
  auto* result = response.mutable_apply_signed_entitlement_result();
  result->set_accepted(accepted);
  result->set_reason(entitlement_reason_key(error));
  if (accepted) {
    result->set_accepted_generation(accepted_entitlement.generation);
    result->set_expires_unix_seconds(expires_unix_seconds);
  }
  write_envelope(pipe, response);
}

void handle_revoke_signed_entitlement(
    const HANDLE pipe,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::fishing::engine_ipc::accepted_entitlement& accepted_entitlement,
    sonar::fishing::engine_ipc::fishing_session_lifecycle& lifecycle,
    sonar::fishing::engine_ipc::production_capability_composition& capabilities,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_revoke_signed_entitlement_request() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "revoke-signed-entitlement") {
    throw std::runtime_error("revoke_signed_entitlement_request_invalid");
  }
  const auto previous_generation = accepted_entitlement.generation;
  accepted_entitlement.clear();
  reconcile_active_entitlement(
      lifecycle, capabilities, accepted_entitlement);

  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      2,
      request.header().request_id(),
      "completed");
  auto* result = response.mutable_revoke_signed_entitlement_result();
  result->set_revoked(true);
  result->set_previous_generation(previous_generation);
  result->set_reason("entitlement_revoked");
  write_envelope(pipe, response);
}

}  // namespace sonar::fishing::engine_ipc::runtime
