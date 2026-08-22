#include "sonar/fishing/entitlement/entitlement.h"

#include <algorithm>
#include <charconv>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <string_view>
#include <utility>

#include "json_document.h"

namespace sonar::fishing::entitlement {
namespace {

using detail::json_kind;
using detail::json_value;

struct parsed_claims final {
  bool validation_accepted{};
  std::string product;
  std::string audience_value;
  entitlement_claims claims;
};

[[nodiscard]] verification_result reject(
    const entitlement_error error,
    const sonar::licensing::verification_error transport_error =
        sonar::licensing::verification_error::none) noexcept {
  return verification_result{
      .error = error,
      .transport_error = transport_error,
      .claims = std::nullopt,
  };
}

[[nodiscard]] const json_value* require_member(
    const json_value* value,
    const std::string_view name,
    const json_kind kind) noexcept {
  if (value == nullptr || value->kind != json_kind::object) {
    return nullptr;
  }
  const auto* member = value->member(name);
  return member != nullptr && member->kind == kind ? member : nullptr;
}

[[nodiscard]] bool bounded_string(
    const json_value* value,
    const std::size_t maximum,
    std::string& destination) {
  if (value == nullptr || value->kind != json_kind::string ||
      value->text.empty() || value->text.size() > maximum) {
    return false;
  }
  destination = value->text;
  return true;
}

template <typename Integer>
[[nodiscard]] bool exact_integer(
    const json_value* value,
    Integer& destination) noexcept {
  if (value == nullptr || value->kind != json_kind::number ||
      value->text.empty() || value->text.find_first_of(".eE") !=
          std::string::npos) {
    return false;
  }
  Integer parsed{};
  const auto [end, error] = std::from_chars(
      value->text.data(), value->text.data() + value->text.size(), parsed);
  if (error != std::errc{} || end != value->text.data() + value->text.size()) {
    return false;
  }
  destination = parsed;
  return true;
}

[[nodiscard]] bool parse_claims(
    const std::span<const std::byte> raw_body,
    parsed_claims& output) {
  const auto source = std::string_view(
      reinterpret_cast<const char*>(raw_body.data()), raw_body.size());
  json_value root;
  if (!detail::parse_json_document(source, root) ||
      root.kind != json_kind::object) {
    return false;
  }

  const auto* meta = require_member(&root, "meta", json_kind::object);
  const auto* valid = require_member(meta, "valid", json_kind::boolean);
  const auto* code = require_member(meta, "code", json_kind::string);
  if (valid == nullptr || code == nullptr) {
    return false;
  }
  output.validation_accepted = valid->boolean_value && code->text == "VALID";

  const auto* data = require_member(&root, "data", json_kind::object);
  const auto* type = require_member(data, "type", json_kind::string);
  if (type == nullptr || type->text != "licenses" ||
      !bounded_string(
          require_member(data, "id", json_kind::string),
          128,
          output.claims.license_id)) {
    return false;
  }
  const auto* attributes = require_member(data, "attributes", json_kind::object);
  const auto* metadata = require_member(attributes, "metadata", json_kind::object);
  if (!bounded_string(
          require_member(metadata, "product_id", json_kind::string),
          64,
          output.product) ||
      !bounded_string(
          require_member(metadata, "audience", json_kind::string),
          128,
          output.audience_value) ||
      !bounded_string(
          require_member(metadata, "machine_fingerprint", json_kind::string),
          256,
          output.claims.machine_fingerprint) ||
      !bounded_string(
          require_member(metadata, "bundle_manifest_hash", json_kind::string),
          256,
          output.claims.bundle_manifest_hash) ||
      !exact_integer(
          require_member(metadata, "issued_unix", json_kind::number),
          output.claims.issued_unix_seconds) ||
      !exact_integer(
          require_member(metadata, "expires_unix", json_kind::number),
          output.claims.expires_unix_seconds) ||
      !exact_integer(
          require_member(metadata, "generation", json_kind::number),
          output.claims.generation) ||
      output.claims.generation == 0) {
    return false;
  }

  const auto* features = require_member(metadata, "features", json_kind::array);
  if (features == nullptr || features->array_items.empty() ||
      features->array_items.size() > 64) {
    return false;
  }
  output.claims.features.reserve(features->array_items.size());
  for (const auto& item : features->array_items) {
    if (item.kind != json_kind::string || item.text.empty() ||
        item.text.size() > 64 ||
        std::find(
            output.claims.features.begin(),
            output.claims.features.end(),
            item.text) != output.claims.features.end()) {
      return false;
    }
    output.claims.features.push_back(item.text);
  }

  const auto* relationships = require_member(
      data, "relationships", json_kind::object);
  const auto* policy = require_member(
      relationships, "policy", json_kind::object);
  const auto* policy_data = require_member(
      policy, "data", json_kind::object);
  const auto* policy_type = require_member(
      policy_data, "type", json_kind::string);
  return policy_type != nullptr && policy_type->text == "policies" &&
      bounded_string(
          require_member(policy_data, "id", json_kind::string),
          128,
          output.claims.policy_id);
}

[[nodiscard]] bool valid_claim_policy(
    const claim_policy_view& policy) noexcept {
  return !policy.expected_machine_fingerprint.empty() &&
      policy.expected_machine_fingerprint.size() <= 256 &&
      !policy.expected_bundle_manifest_hash.empty() &&
      policy.expected_bundle_manifest_hash.size() <= 256 &&
      !policy.expected_policy_id.empty() &&
      policy.expected_policy_id.size() <= 128 &&
      !policy.required_features.empty() &&
      policy.required_features.size() <= 64 &&
      policy.maximum_lease_seconds > 0 &&
      policy.maximum_lease_seconds <= 3600;
}

[[nodiscard]] bool has_required_features(
    const entitlement_claims& claims,
    const std::span<const std::string_view> required) noexcept {
  for (const auto feature : required) {
    if (feature.empty() || feature.size() > 64 ||
        std::find(claims.features.begin(), claims.features.end(), feature) ==
            claims.features.end()) {
      return false;
    }
  }
  return true;
}

}  // namespace

verification_result verify(
    const signed_entitlement_envelope_view& envelope,
    const trust_policy_view& trust,
    const claim_policy_view& claims_policy) noexcept {
  if (!trust.has_trust_root()) {
    return reject(entitlement_error::trust_root_missing);
  }
  if (!valid_claim_policy(claims_policy)) {
    return reject(entitlement_error::claims_malformed);
  }

  const auto transport = sonar::licensing::verify_rsa_sha256_response(
      sonar::licensing::signed_http_response_view{
          .method = envelope.method,
          .request_target = envelope.request_target,
          .host = envelope.host,
          .date_header = envelope.date_header,
          .digest_header = envelope.digest_header,
          .signature_header = envelope.signature_header,
          .raw_body = envelope.raw_body,
      },
      sonar::licensing::signed_response_verification_policy_view{
          .expected_key_id = trust.expected_key_id,
          .expected_method = trust.expected_method,
          .expected_request_target = trust.expected_request_target,
          .expected_host = trust.expected_host,
          .rsa_public_key_pem = trust.rsa_public_key_pem,
          .now_unix_seconds = trust.now_unix_seconds,
          .maximum_age_seconds = trust.maximum_response_age_seconds,
          .maximum_future_skew_seconds = trust.maximum_future_skew_seconds,
      });
  if (!transport.verified()) {
    return reject(entitlement_error::transport_rejected, transport.error);
  }

  try {
    parsed_claims parsed;
    if (!parse_claims(envelope.raw_body, parsed)) {
      return reject(entitlement_error::claims_malformed);
    }
    if (!parsed.validation_accepted) {
      return reject(entitlement_error::validation_rejected);
    }
    if (parsed.product != product_id) {
      return reject(entitlement_error::product_mismatch);
    }
    if (parsed.audience_value != audience) {
      return reject(entitlement_error::audience_mismatch);
    }
    if (parsed.claims.machine_fingerprint !=
        claims_policy.expected_machine_fingerprint) {
      return reject(entitlement_error::machine_mismatch);
    }
    if (parsed.claims.bundle_manifest_hash !=
        claims_policy.expected_bundle_manifest_hash) {
      return reject(entitlement_error::bundle_mismatch);
    }
    if (parsed.claims.policy_id != claims_policy.expected_policy_id) {
      return reject(entitlement_error::policy_mismatch);
    }
    if (!has_required_features(parsed.claims, claims_policy.required_features)) {
      return reject(entitlement_error::required_feature_missing);
    }
    if (parsed.claims.generation <= claims_policy.last_accepted_generation) {
      return reject(entitlement_error::lease_replayed);
    }
    if (parsed.claims.issued_unix_seconds > transport.server_unix_seconds ||
        transport.server_unix_seconds >= parsed.claims.expires_unix_seconds ||
        trust.now_unix_seconds >= parsed.claims.expires_unix_seconds ||
        parsed.claims.expires_unix_seconds <= parsed.claims.issued_unix_seconds ||
        parsed.claims.expires_unix_seconds - parsed.claims.issued_unix_seconds >
            claims_policy.maximum_lease_seconds) {
      return reject(entitlement_error::lease_invalid);
    }
    return verification_result{
        .error = entitlement_error::none,
        .transport_error = sonar::licensing::verification_error::none,
        .claims = std::move(parsed.claims),
    };
  } catch (...) {
    return reject(entitlement_error::claims_malformed);
  }
}

trust_policy_view production_trust_policy_missing_key(
    const std::int64_t now_unix_seconds) noexcept {
  return trust_policy_view{
      .expected_key_id = {},
      .expected_method = "post",
      .expected_request_target = "/v1/licenses/actions/validate-key?include=policy",
      .expected_host = "m-sonar-addr.ru",
      .rsa_public_key_pem = {},
      .now_unix_seconds = now_unix_seconds,
      .maximum_response_age_seconds = 300,
      .maximum_future_skew_seconds = 60,
  };
}

}  // namespace sonar::fishing::entitlement
