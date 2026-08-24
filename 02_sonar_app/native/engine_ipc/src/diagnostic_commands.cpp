#include "diagnostic_commands.h"

#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

#include "sonar/fishing/catch_disposition/catch_disposition.h"
#include "sonar/fishing/catch_quality/catch_quality.h"

namespace sonar::fishing::engine_ipc::runtime {

void handle_catch_disposition(
    const HANDLE pipe,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_evaluate_catch_disposition_request() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "evaluate-catch-disposition") {
    throw std::runtime_error("catch_disposition_request_invalid");
  }

  const auto& command = request.evaluate_catch_disposition_request();
  std::optional<std::string_view> fish_id;
  if (command.has_fish_id()) {
    fish_id = command.fish_id();
  }
  std::vector<std::string_view> selected_fish_ids;
  selected_fish_ids.reserve(
      static_cast<std::size_t>(command.selected_fish_ids_size()));
  for (const std::string& selected_fish_id : command.selected_fish_ids()) {
    selected_fish_ids.emplace_back(selected_fish_id);
  }
  const auto decision = sonar::fishing::catch_disposition::Decide(
      fish_id,
      std::span<const std::string_view>(selected_fish_ids),
      command.inventory_full());

  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      5,
      request.header().request_id(),
      "completed");
  auto* result = response.mutable_evaluate_catch_disposition_result();
  result->set_disposition(
      decision.should_keep()
          ? sonar::fishing::ipc::v1::CATCH_DISPOSITION_KEEP
          : sonar::fishing::ipc::v1::CATCH_DISPOSITION_RELEASE);
  result->set_reason(
      sonar::fishing::catch_disposition::ReasonKey(decision.rationale));
  write_envelope(pipe, response);
}

void handle_catch_quality(
    const HANDLE pipe,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_classify_catch_quality_request() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "classify-catch-quality") {
    throw std::runtime_error("catch_quality_request_invalid");
  }

  const auto& command = request.classify_catch_quality_request();
  std::optional<std::string_view> raw_text;
  if (command.has_raw_text()) {
    raw_text = command.raw_text();
  }
  const std::optional<std::string> normalized =
      sonar::fishing::catch_quality::NormalizeCatchSize(raw_text);
  const std::optional<std::string_view> normalized_view = normalized.has_value()
      ? std::optional<std::string_view>(*normalized)
      : std::nullopt;
  const std::string_view stable_key =
      sonar::fishing::catch_quality::CatchSizeKey(normalized_view);

  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      4,
      request.header().request_id(),
      "completed");
  auto* result = response.mutable_classify_catch_quality_result();
  if (normalized.has_value()) {
    result->set_normalized_label(*normalized);
  }
  result->set_stable_key(stable_key);
  result->set_recognized(stable_key != "unknown");
  write_envelope(pipe, response);
}

void handle_shutdown(
    const HANDLE pipe,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_platform() ||
      !request.platform().has_shutdown_engine() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "shutdown-engine") {
    throw std::runtime_error("shutdown_request_invalid");
  }

  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      6,
      request.header().request_id(),
      "ready");
  response.mutable_platform()->mutable_shutdown_ready()->set_reason(
      "offline_gate_complete");
  write_envelope(pipe, response);
}

}  // namespace sonar::fishing::engine_ipc::runtime
