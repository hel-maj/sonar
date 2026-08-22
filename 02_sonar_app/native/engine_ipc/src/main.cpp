#include <Windows.h>

#include <array>
#include <charconv>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <iostream>
#include <optional>
#include <map>
#include <limits>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <utility>
#include <vector>

#include "ipc/v1/sonar_fishing.pb.h"
#include "sonar/fishing/catch_disposition/catch_disposition.h"
#include "sonar/fishing/catch_quality/catch_quality.h"
#include "sonar/fishing/entitlement/entitlement.h"
#include "sonar/fishing/entitlement/windows_machine_fingerprint.h"
#include "sonar/fishing/engine_ipc/engine_mode.h"
#include "sonar/fishing/engine_ipc/event_delivery.h"
#include "sonar/fishing/engine_ipc/production_composition.h"
#include "sonar/fishing/engine_ipc/session_lifecycle.h"
#include "sonar/fishing/session_statistics/session_statistics.h"
#include "sonar/fishing/runtime_settings/runtime_settings.h"
#include "sonar/platform/ipc/frame_codec.hpp"
#include "sonar/platform/ipc/header_validation.hpp"
#include "sonar/platform/ipc/handshake_contract.hpp"
#include "sonar/platform/ipc/heartbeat_liveness.hpp"
#include "sonar/platform/ipc/local_pipe_client_pair.hpp"
#include "sonar/platform/ipc/pipe_frame_io.hpp"
#include "sonar/platform/ipc/session_header_contract.hpp"
#include "sonar/platform/ipc/session_header_factory.hpp"
#include "sonar/platform/ipc/session_sequence_gate.hpp"

#if SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS
#include "offline_entitlement_fixture.h"
#endif

namespace {

using fishing_envelope = sonar::fishing::ipc::v1::Envelope;
namespace platform_v1 = sonar::platform::ipc::v1;
using sonar::fishing::engine_ipc::engine_authority_mode;

constexpr std::uint32_t kIoTimeoutMilliseconds = 5000;
constexpr std::string_view kProductId = "fishing";
constexpr std::string_view kCatchQualityCapabilityId = "catch-quality.aggregate";
constexpr std::string_view kCatchDispositionCapabilityId =
    "catch-disposition.evaluate";
constexpr std::string_view kSessionStatisticsCapabilityId =
    "fishing-session.statistics";
constexpr std::string_view kRuntimeSettingsCapabilityId =
    "fishing-runtime-settings.apply";
constexpr std::string_view kSignedEntitlementCapabilityId =
    "signed-entitlement.verify";
#if SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS
constexpr std::string_view kOfflineHostBuildId = "offline-host-0.1.0";
constexpr std::string_view kOfflineEngineBuildId = "offline-engine-0.1.0";
constexpr std::string_view kOfflineBundleManifestHash =
    "offline-bundle-manifest";
#endif

[[noreturn]] void throw_native_error(
    const std::string_view reason,
    const DWORD native_error = GetLastError()) {
  throw std::runtime_error(
      std::string(reason) + ":" + std::to_string(native_error));
}

[[nodiscard]] std::wstring require_environment(const wchar_t* name) {
  const DWORD required = GetEnvironmentVariableW(name, nullptr, 0);
  if (required == 0) {
    throw_native_error("offline_bootstrap_missing");
  }
  std::wstring value(required, L'\0');
  const DWORD copied = GetEnvironmentVariableW(name, value.data(), required);
  if (copied == 0 || copied >= required) {
    throw_native_error("offline_bootstrap_invalid");
  }
  value.resize(copied);
  return value;
}

[[nodiscard]] std::string require_ascii_environment(const wchar_t* name) {
  const std::wstring value = require_environment(name);
  std::string result;
  result.reserve(value.size());
  for (const wchar_t character : value) {
    if (character < L' ' || character > L'~') {
      throw std::runtime_error("offline_bootstrap_not_ascii");
    }
    result.push_back(static_cast<char>(character));
  }
  return result;
}

[[nodiscard]] std::optional<std::string> optional_ascii_environment(
    const wchar_t* name) {
  const DWORD required = GetEnvironmentVariableW(name, nullptr, 0);
  if (required == 0) {
    return std::nullopt;
  }
  std::wstring value(required, L'\0');
  const DWORD copied = GetEnvironmentVariableW(name, value.data(), required);
  if (copied == 0 || copied >= required) {
    throw_native_error("engine_bootstrap_invalid");
  }
  value.resize(copied);
  std::string result;
  result.reserve(value.size());
  for (const wchar_t character : value) {
    if (character < L' ' || character > L'~') {
      throw std::runtime_error("engine_bootstrap_not_ascii");
    }
    result.push_back(static_cast<char>(character));
  }
  return result;
}

[[nodiscard]] std::string require_production_environment(
    const wchar_t* name,
    const std::string_view missing_reason) {
  auto value = optional_ascii_environment(name);
  if (!value.has_value() || value->empty()) {
    throw std::runtime_error(std::string(missing_reason));
  }
  return std::move(*value);
}

[[nodiscard]] engine_authority_mode require_authority_mode() {
  const auto offline = optional_ascii_environment(
      L"SONAR_FISHING_OFFLINE_GATE");
  const auto mode = optional_ascii_environment(
      L"SONAR_FISHING_ENGINE_MODE");
#if SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS
  if (offline == "1" && !mode.has_value()) {
    return engine_authority_mode::offline_diagnostics;
  }
#endif
  if (!offline.has_value() && mode == "production") {
    return engine_authority_mode::production;
  }
  throw std::runtime_error("production_authority_gate_closed");
}

struct engine_build_identity final {
  std::string host_build_id;
  std::string engine_build_id;
  std::string bundle_manifest_hash;
};

[[nodiscard]] engine_build_identity require_build_identity(
    const engine_authority_mode authority_mode) {
#if SONAR_FISHING_ENABLE_OFFLINE_DIAGNOSTICS
  if (authority_mode == engine_authority_mode::offline_diagnostics) {
    return engine_build_identity{
        .host_build_id = std::string(kOfflineHostBuildId),
        .engine_build_id = std::string(kOfflineEngineBuildId),
        .bundle_manifest_hash = std::string(kOfflineBundleManifestHash),
    };
  }
#else
  if (authority_mode != engine_authority_mode::production) {
    throw std::runtime_error("production_authority_required");
  }
#endif
  return engine_build_identity{
      .host_build_id = require_production_environment(
          L"SONAR_FISHING_HOST_BUILD_ID",
          "production_host_build_id_missing"),
      .engine_build_id = require_production_environment(
          L"SONAR_FISHING_ENGINE_BUILD_ID",
          "production_engine_build_id_missing"),
      .bundle_manifest_hash = require_production_environment(
          L"SONAR_FISHING_BUNDLE_MANIFEST_HASH",
          "production_bundle_manifest_hash_missing"),
  };
}

[[nodiscard]] std::uint32_t require_process_id() {
  const std::string value = require_ascii_environment(
      L"SONAR_FISHING_EXPECTED_HOST_PID");
  std::uint32_t process_id = 0;
  const auto [end, error] = std::from_chars(
      value.data(), value.data() + value.size(), process_id);
  if (error != std::errc{} || end != value.data() + value.size() ||
      process_id == 0) {
    throw std::runtime_error("offline_host_pid_invalid");
  }
  return process_id;
}

[[nodiscard]] unsigned char hex_nibble(const char value) {
  if (value >= '0' && value <= '9') {
    return static_cast<unsigned char>(value - '0');
  }
  if (value >= 'A' && value <= 'F') {
    return static_cast<unsigned char>(value - 'A' + 10);
  }
  if (value >= 'a' && value <= 'f') {
    return static_cast<unsigned char>(value - 'a' + 10);
  }
  throw std::runtime_error("offline_nonce_not_hex");
}

[[nodiscard]] std::string require_bootstrap_nonce() {
  const std::string encoded = require_ascii_environment(
      L"SONAR_FISHING_BOOTSTRAP_NONCE");
  if (encoded.size() != 64) {
    throw std::runtime_error("offline_nonce_length_invalid");
  }
  std::string decoded(encoded.size() / 2, '\0');
  for (std::size_t index = 0; index < decoded.size(); ++index) {
    decoded[index] = static_cast<char>(
        (hex_nibble(encoded[index * 2]) << 4U) |
        hex_nibble(encoded[index * 2 + 1]));
  }
  return decoded;
}

[[nodiscard]] std::vector<std::byte> serialize_envelope(
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
    const std::size_t maximum =
        sonar::platform::ipc::control_frame_maximum) {
  const auto payload = serialize_envelope(envelope);
  sonar::platform::ipc::write_framed_payload(
      pipe,
      payload,
      maximum,
      kIoTimeoutMilliseconds);
}

[[nodiscard]] fishing_envelope read_envelope(const HANDLE pipe) {
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
    const platform_v1::ChannelKind channel =
        platform_v1::CHANNEL_KIND_CONTROL) {
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
  sonar::fishing::engine_ipc::apply_handshake_mode(*hello, authority_mode);
  write_envelope(pipe, envelope);
}

[[nodiscard]] bool require_handshake_accepted(
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

[[nodiscard]] sonar::fishing::runtime_settings::OverweightAction
map_overweight_action(const sonar::fishing::ipc::v1::OverweightAction value) {
  using source = sonar::fishing::ipc::v1::OverweightAction;
  using target = sonar::fishing::runtime_settings::OverweightAction;
  switch (value) {
    case source::OVERWEIGHT_ACTION_RELEASE:
      return target::release;
    case source::OVERWEIGHT_ACTION_STOP:
      return target::stop;
    case source::OVERWEIGHT_ACTION_EXIT_GAME:
      return target::exit_game;
    default:
      throw std::runtime_error("settings_overweight_action_invalid");
  }
}

[[nodiscard]] sonar::fishing::runtime_settings::DepletedAction
map_depleted_action(const sonar::fishing::ipc::v1::DepletedAction value) {
  using source = sonar::fishing::ipc::v1::DepletedAction;
  using target = sonar::fishing::runtime_settings::DepletedAction;
  switch (value) {
    case source::DEPLETED_ACTION_STOP:
      return target::stop;
    case source::DEPLETED_ACTION_EXIT_GAME:
      return target::exit_game;
    default:
      throw std::runtime_error("settings_depleted_action_invalid");
  }
}

[[nodiscard]] sonar::fishing::runtime_settings::EquipmentDepletedAction
map_equipment_action(
    const sonar::fishing::ipc::v1::EquipmentDepletedAction value) {
  using source = sonar::fishing::ipc::v1::EquipmentDepletedAction;
  using target = sonar::fishing::runtime_settings::EquipmentDepletedAction;
  switch (value) {
    case source::EQUIPMENT_DEPLETED_ACTION_STOP:
      return target::stop;
    case source::EQUIPMENT_DEPLETED_ACTION_EXIT_GAME:
      return target::exit_game;
    case source::EQUIPMENT_DEPLETED_ACTION_SHUTDOWN_PC:
      return target::shutdown_pc;
    default:
      throw std::runtime_error("settings_equipment_action_invalid");
  }
}

[[nodiscard]] sonar::fishing::runtime_settings::FoodDepletedAction
map_food_action(const sonar::fishing::ipc::v1::FoodDepletedAction value) {
  using source = sonar::fishing::ipc::v1::FoodDepletedAction;
  using target = sonar::fishing::runtime_settings::FoodDepletedAction;
  switch (value) {
    case source::FOOD_DEPLETED_ACTION_CONTINUE:
      return target::continue_fishing;
    case source::FOOD_DEPLETED_ACTION_STOP:
      return target::stop;
    case source::FOOD_DEPLETED_ACTION_EXIT_GAME:
      return target::exit_game;
    case source::FOOD_DEPLETED_ACTION_SHUTDOWN_PC:
      return target::shutdown_pc;
    default:
      throw std::runtime_error("settings_food_action_invalid");
  }
}

template <typename TEntry>
[[nodiscard]] std::map<std::string, bool, std::less<>> map_boolean_policy(
    const google::protobuf::RepeatedPtrField<TEntry>& entries) {
  std::map<std::string, bool, std::less<>> result;
  for (const auto& entry : entries) {
    const auto [unused, inserted] = result.emplace(entry.id(), entry.enabled());
    static_cast<void>(unused);
    if (!inserted) {
      throw std::runtime_error("settings_policy_duplicate_id");
    }
  }
  return result;
}

[[nodiscard]] sonar::fishing::runtime_settings::RuntimeSettingsSnapshot
map_runtime_settings(
    const sonar::fishing::ipc::v1::FishingRuntimeSettings& source) {
  namespace target = sonar::fishing::runtime_settings;
  target::RuntimeSettingsSnapshot result{
      .revision = source.revision(),
      .auto_meal = source.auto_meal(),
      .restore_food_from = source.restore_food_from(),
      .restore_water_from = source.restore_water_from(),
      .restore_health_from = source.restore_health_from(),
      .auto_change_bait = source.auto_change_bait(),
      .store_in_trunk = source.store_in_trunk(),
      .start_stop_sound_enabled = source.start_stop_sound_enabled(),
      .overweight_action = map_overweight_action(source.overweight_action()),
      .fish_without_leader = source.fish_without_leader(),
      .leader_depleted_action = map_depleted_action(
          source.leader_depleted_action()),
      .fish_without_net = source.fish_without_net(),
      .net_depleted_action = map_depleted_action(source.net_depleted_action()),
      .equipment_depleted_action = map_equipment_action(
          source.equipment_depleted_action()),
      .food_depleted_action = map_food_action(source.food_depleted_action()),
      .start_stop_hotkey = source.start_stop_hotkey(),
      .inventory_hotkey = source.inventory_hotkey(),
      .use_item_hotkey = source.use_item_hotkey(),
      .backpack_move_hotkey = source.backpack_move_hotkey(),
      .discard_hotkey = source.discard_hotkey(),
      .chat_hotkey = source.chat_hotkey(),
      .stream_snapshot_mode = source.stream_snapshot_mode(),
      .fish_keep_policy = map_boolean_policy(source.fish_keep_policy()),
      .garbage_disposal_policy = map_boolean_policy(
          source.garbage_disposal_policy()),
  };
  for (const auto& entry : source.custom_fish_prices()) {
    const auto [unused, inserted] = result.custom_fish_prices.emplace(
        entry.fish_id(), entry.price());
    static_cast<void>(unused);
    if (!inserted) {
      throw std::runtime_error("settings_custom_price_duplicate_id");
    }
  }
  return result;
}

void handle_apply_runtime_settings(
    const HANDLE pipe,
    const fishing_envelope& request,
    const std::string_view session_id,
    const sonar::platform::ipc::session_identity_expectation& identity,
    sonar::fishing::runtime_settings::RuntimeSettingsOwner& settings,
    sonar::platform::ipc::session_header_factory& headers,
    sonar::platform::ipc::incoming_sequence_gate& incoming_sequences,
    sonar::platform::ipc::peer_liveness_tracker& liveness) {
  require_host_envelope(
      request,
      platform_v1::MESSAGE_KIND_COMMAND,
      identity,
      incoming_sequences,
      liveness);
  if (!request.has_apply_runtime_settings_request() ||
      !request.apply_runtime_settings_request().has_settings() ||
      request.header().request_id().empty() ||
      request.header().command_id() != "apply-runtime-settings") {
    throw std::runtime_error("apply_runtime_settings_request_invalid");
  }

  sonar::fishing::runtime_settings::ApplyResult applied{
      .status = sonar::fishing::runtime_settings::ApplyStatus::invalid_snapshot,
      .accepted_revision = settings.AcceptedRevision(),
      .reason = "settings_payload_invalid",
  };
  try {
    applied = settings.Apply(map_runtime_settings(
        request.apply_runtime_settings_request().settings()));
  } catch (const std::exception& error) {
    applied.reason = error.what();
  }

  fishing_envelope response;
  populate_header(
      *response.mutable_header(),
      headers,
      platform_v1::MESSAGE_KIND_REPLY,
      session_id,
      2,
      request.header().request_id(),
      applied.accepted() ? "completed" : "rejected");
  auto* result = response.mutable_apply_runtime_settings_result();
  result->set_accepted(applied.accepted());
  result->set_accepted_revision(applied.accepted_revision);
  result->set_reason(applied.reason);
  write_envelope(pipe, response);
}

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

[[nodiscard]] bool handle_start_fishing_session(
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

int run() {
  const auto authority_mode = require_authority_mode();
  const auto build_identity = require_build_identity(authority_mode);
  const auto production_machine_fingerprint =
      authority_mode == engine_authority_mode::production
          ? sonar::fishing::entitlement::current_windows_machine_fingerprint()
          : std::optional<std::string>{std::string{}};
  if (!production_machine_fingerprint.has_value()) {
    throw std::runtime_error("license_machine_identity_unavailable");
  }
  const std::wstring control_pipe_name = require_environment(
      L"SONAR_FISHING_CONTROL_PIPE");
  const std::wstring event_pipe_name = require_environment(
      L"SONAR_FISHING_EVENT_PIPE");
  const std::string nonce = require_bootstrap_nonce();
  const std::uint32_t host_process_id = require_process_id();
  const std::string session_id = require_ascii_environment(
      L"SONAR_FISHING_SESSION_ID");

  auto pipes = sonar::platform::ipc::local_pipe_client_pair::connect(
      control_pipe_name,
      event_pipe_name,
      host_process_id,
      sonar::platform::ipc::local_pipe_pair_limits{},
      kIoTimeoutMilliseconds);
  const sonar::platform::ipc::session_identity_expectation identity{
      .product_id = kProductId,
      .host_build_id = build_identity.host_build_id,
      .engine_build_id = build_identity.engine_build_id,
      .bundle_manifest_hash = build_identity.bundle_manifest_hash,
      .schema_hash = SONAR_FISHING_SCHEMA_SHA256,
      .session_id = session_id,
      .session_generation = 1,
  };
  sonar::platform::ipc::session_header_factory headers(
      identity, platform_v1::PEER_ROLE_ENGINE);
  sonar::platform::ipc::incoming_sequence_gate incoming_sequences;
  sonar::platform::ipc::heartbeat_responder heartbeat_responder;
  sonar::platform::ipc::peer_liveness_tracker liveness(
      std::chrono::seconds(15));
  send_handshake_hello(
      pipes.control_pipe(), session_id, nonce, authority_mode, headers);
  const bool side_effects_negotiated = require_handshake_accepted(
      read_envelope(pipes.control_pipe()),
      identity,
      authority_mode,
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
  std::uint64_t snapshot_revision = 0;
  sonar::fishing::engine_ipc::accepted_entitlement accepted_entitlement;
  sonar::fishing::engine_ipc::fishing_session_lifecycle session_lifecycle;
  sonar::fishing::engine_ipc::production_capability_composition
      production_capabilities;
  std::optional<fishing_envelope> active_start_request;
  std::uint64_t published_progress_revision = 0U;
  bool shutdown_requested = false;
  while (!shutdown_requested) {
    auto request = read_envelope(pipes.control_pipe());
    publish_pending_production_progress(
        event_writer,
        active_start_request,
        session_id,
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
          session_id,
          identity,
          runtime_settings,
          headers,
          incoming_sequences,
          liveness);
    } else if (request.has_apply_signed_entitlement_request()) {
      handle_apply_signed_entitlement(
          pipes.control_pipe(),
          request,
          session_id,
          identity,
          authority_mode,
          *production_machine_fingerprint,
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
          session_id,
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
          session_id,
          identity,
          authority_mode,
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
          session_id,
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
          session_id,
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
          session_id,
          identity,
          headers,
          incoming_sequences,
          liveness);
    } else if (request.has_evaluate_catch_disposition_request()) {
      handle_catch_disposition(
          pipes.control_pipe(),
          request,
          session_id,
          identity,
          headers,
          incoming_sequences,
          liveness);
    } else if (request.has_platform() &&
               request.platform().has_shutdown_engine()) {
      handle_shutdown(
          pipes.control_pipe(),
          request,
          session_id,
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
  event_writer.close_and_drain();
  liveness.stop();
  std::cout << "PASS offline Fishing diagnostics; production authority unchanged\n";
  return 0;
}

}  // namespace

int main() {
  try {
    return run();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 2;
  }
}
