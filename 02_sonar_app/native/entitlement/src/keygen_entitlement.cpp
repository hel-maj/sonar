#include "sonar/fishing/entitlement/entitlement.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "json_document.h"

namespace sonar::fishing::entitlement {
namespace {

using detail::json_kind;
using detail::json_value;

constexpr std::string_view keygen_account_id =
    "e8b61b74-558a-4d85-9bc5-4ac5870a27ae";
constexpr std::string_view keygen_product_id =
    "f92e17ce-1a7f-44ac-b98e-3cd0a514543b";
constexpr std::string_view keygen_host = "m-sonar-addr.ru";
constexpr std::string_view keygen_validation_target =
    "/v1/licenses/actions/validate-key?include=policy";
constexpr std::string_view keygen_public_key = R"(-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA827rC65fMFhIeaTyIFtI
5bMqSRHL3boAcVkZLnVJriM6Y7OKdMLnK4XRpISHHJUG5CCQJFtLogfcQkX0Pk6z
E8J0GBRytJgPlb8VoYp8oIX7M4H9lubc2cwKd9nRkjUaTWR449v0hWuHr2uXz6mF
DsKS1ZHw1NkbOlRAFb4tmufQvn+pcx0regiVtZOlaA40gdZC0u8FlgwVOhWnuu89
C9sdxilrcPtOwy9zH7N9XpPXSrhSG40LbONIR+wBb9wORpS6lgak25lNcFceJKot
LMomwKErDDSEC1SjPlSCymimkCvb1CxIefTDgZ1V1JkfnwFaQ2AcGf5v/ucGqPNc
HwIDAQAB
-----END PUBLIC KEY-----)";

constexpr std::array<std::string_view, 10> all_features = {
    "overview",
    "overview_session_stats",
    "fishing",
    "fishing_bot",
    "fishing_tackle",
    "settings",
    "statistics",
    "stream",
    "stream_chat",
    "telegram",
};
constexpr std::array<std::string_view, 1> intro_features = {"fishing"};
constexpr std::array<std::string_view, 5> basic_features = {
    "overview", "fishing", "fishing_bot", "fishing_tackle", "telegram"};

struct parsed_keygen_claims final {
  bool validation_accepted{};
  std::string code;
  std::string product_id;
  std::string machine_fingerprint;
  keygen_entitlement_claims claims;
};

[[nodiscard]] keygen_verification_result reject_keygen(
    const entitlement_error error,
    const sonar::licensing::verification_error transport_error =
        sonar::licensing::verification_error::none) noexcept {
  return keygen_verification_result{
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

[[nodiscard]] bool ascii_space(const char value) noexcept {
  return value == ' ' || value == '\t' || value == '\r' || value == '\n';
}

[[nodiscard]] bool normalize_token(
    const std::string_view source,
    const std::size_t maximum,
    std::string& destination) {
  std::size_t begin = 0;
  while (begin < source.size() && ascii_space(source[begin])) {
    ++begin;
  }
  std::size_t end = source.size();
  while (end > begin && ascii_space(source[end - 1])) {
    --end;
  }
  if (begin == end || end - begin > maximum) {
    return false;
  }
  destination.clear();
  destination.reserve(end - begin);
  for (std::size_t index = begin; index < end; ++index) {
    const unsigned char value = static_cast<unsigned char>(source[index]);
    if (value > 0x7fU) {
      return false;
    }
    destination.push_back(
        value >= 'A' && value <= 'Z'
            ? static_cast<char>(value + ('a' - 'A'))
            : static_cast<char>(value));
  }
  return true;
}

[[nodiscard]] bool exact_digits(
    const std::string_view source,
    const std::size_t offset,
    const std::size_t count,
    unsigned& output) noexcept {
  if (offset + count > source.size()) {
    return false;
  }
  unsigned value = 0;
  for (std::size_t index = 0; index < count; ++index) {
    const char character = source[offset + index];
    if (character < '0' || character > '9') {
      return false;
    }
    value = value * 10U + static_cast<unsigned>(character - '0');
  }
  output = value;
  return true;
}

[[nodiscard]] bool parse_utc_expiry(
    const std::string_view source,
    std::int64_t& unix_seconds) noexcept {
  if (source.size() < 20U || source.size() > 32U ||
      source[4] != '-' || source[7] != '-' || source[10] != 'T' ||
      source[13] != ':' || source[16] != ':') {
    return false;
  }
  unsigned year_value = 0;
  unsigned month_value = 0;
  unsigned day_value = 0;
  unsigned hour_value = 0;
  unsigned minute_value = 0;
  unsigned second_value = 0;
  if (!exact_digits(source, 0, 4, year_value) ||
      !exact_digits(source, 5, 2, month_value) ||
      !exact_digits(source, 8, 2, day_value) ||
      !exact_digits(source, 11, 2, hour_value) ||
      !exact_digits(source, 14, 2, minute_value) ||
      !exact_digits(source, 17, 2, second_value) ||
      hour_value > 23U || minute_value > 59U || second_value > 59U) {
    return false;
  }
  if (source[19] == '.') {
    if (source.back() != 'Z' || source.size() < 22U) {
      return false;
    }
    for (std::size_t index = 20; index + 1 < source.size(); ++index) {
      if (source[index] < '0' || source[index] > '9') {
        return false;
      }
    }
  } else if (source.size() != 20U || source[19] != 'Z') {
    return false;
  }

  const std::chrono::year_month_day day{
      std::chrono::year{static_cast<int>(year_value)},
      std::chrono::month{month_value},
      std::chrono::day{day_value}};
  if (!day.ok()) {
    return false;
  }
  const auto point = std::chrono::sys_days{day} +
      std::chrono::hours{hour_value} +
      std::chrono::minutes{minute_value} +
      std::chrono::seconds{second_value};
  unix_seconds = std::chrono::duration_cast<std::chrono::seconds>(
                     point.time_since_epoch())
                     .count();
  return unix_seconds > 0;
}

[[nodiscard]] bool contains_feature(
    const std::vector<std::string>& features,
    const std::string_view feature) noexcept {
  return std::find(features.begin(), features.end(), feature) != features.end();
}

[[nodiscard]] bool known_feature(const std::string_view feature) noexcept {
  return std::find(all_features.begin(), all_features.end(), feature) !=
      all_features.end();
}

template <std::size_t Size>
void assign_features(
    const std::array<std::string_view, Size>& source,
    std::vector<std::string>& destination) {
  destination.clear();
  destination.reserve(Size);
  for (const auto feature : source) {
    destination.emplace_back(feature);
  }
}

[[nodiscard]] bool resolve_group(
    const json_value* metadata,
    std::string& group,
    std::vector<std::string>& features) {
  constexpr std::array<std::string_view, 4> names = {
      "licenseGroup",
      "license_group",
      "sonarSubscriptionLevel",
      "sonar_subscription_level",
  };
  bool found = false;
  for (const auto name : names) {
    const auto* value = metadata->member(name);
    if (value == nullptr) {
      continue;
    }
    if (value->kind != json_kind::string) {
      return false;
    }
    std::string candidate;
    if (!normalize_token(value->text, 32, candidate) ||
        (found && candidate != group)) {
      return false;
    }
    group = std::move(candidate);
    found = true;
  }
  if (!found) {
    return false;
  }
  if (group == "intro") {
    assign_features(intro_features, features);
  } else if (group == "basic") {
    assign_features(basic_features, features);
  } else if (group == "premium" || group == "dev" || group == "promo") {
    assign_features(all_features, features);
  } else {
    return false;
  }
  return true;
}

[[nodiscard]] bool apply_feature_array(
    const json_value* metadata,
    const std::string_view name,
    const bool allow,
    std::vector<std::string>& features) {
  const auto* value = metadata->member(name);
  if (value == nullptr) {
    return true;
  }
  if (value->kind != json_kind::array || value->array_items.size() > 64U) {
    return false;
  }
  std::vector<std::string> seen;
  seen.reserve(value->array_items.size());
  for (const auto& item : value->array_items) {
    if (item.kind != json_kind::string) {
      return false;
    }
    std::string feature;
    if (!normalize_token(item.text, 64, feature) ||
        contains_feature(seen, feature)) {
      return false;
    }
    seen.push_back(feature);
    if (!known_feature(feature)) {
      continue;
    }
    const auto position = std::find(features.begin(), features.end(), feature);
    if (allow && position == features.end()) {
      features.push_back(std::move(feature));
    } else if (!allow && position != features.end()) {
      features.erase(position);
    }
  }
  return true;
}

[[nodiscard]] bool relationship_id(
    const json_value* relationships,
    const std::string_view name,
    const std::string_view expected_type,
    std::string& identifier) {
  const auto* relation = require_member(relationships, name, json_kind::object);
  const auto* data = require_member(relation, "data", json_kind::object);
  const auto* type = require_member(data, "type", json_kind::string);
  return type != nullptr && type->text == expected_type &&
      bounded_string(
          require_member(data, "id", json_kind::string), 128, identifier);
}

[[nodiscard]] bool parse_keygen_claims(
    const std::span<const std::byte> raw_body,
    parsed_keygen_claims& output) {
  const auto source = std::string_view(
      reinterpret_cast<const char*>(raw_body.data()), raw_body.size());
  json_value root;
  if (!detail::parse_json_document(source, root) ||
      root.kind != json_kind::object) {
    return false;
  }
  const auto* meta = require_member(&root, "meta", json_kind::object);
  const auto* valid = require_member(meta, "valid", json_kind::boolean);
  if (valid == nullptr ||
      !bounded_string(
          require_member(meta, "code", json_kind::string), 128, output.code)) {
    return false;
  }
  output.validation_accepted = valid->boolean_value && output.code == "VALID";
  const auto* scope = require_member(meta, "scope", json_kind::object);
  if (!bounded_string(
          require_member(scope, "fingerprint", json_kind::string),
          256,
          output.machine_fingerprint)) {
    return false;
  }

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
  std::string expiry;
  if (!bounded_string(
          require_member(attributes, "expiry", json_kind::string), 64, expiry) ||
      !parse_utc_expiry(expiry, output.claims.license_expires_unix_seconds)) {
    return false;
  }
  const auto* metadata = require_member(attributes, "metadata", json_kind::object);
  if (metadata == nullptr ||
      !resolve_group(metadata, output.claims.group, output.claims.features)) {
    return false;
  }
  constexpr std::array<std::string_view, 3> allow_names = {
      "allowFeatures", "allow_features", "features"};
  constexpr std::array<std::string_view, 2> deny_names = {
      "denyFeatures", "deny_features"};
  for (const auto name : allow_names) {
    if (!apply_feature_array(metadata, name, true, output.claims.features)) {
      return false;
    }
  }
  for (const auto name : deny_names) {
    if (!apply_feature_array(metadata, name, false, output.claims.features)) {
      return false;
    }
  }
  std::sort(output.claims.features.begin(), output.claims.features.end());

  const auto* relationships = require_member(
      data, "relationships", json_kind::object);
  return relationship_id(
             relationships, "product", "products", output.product_id) &&
      relationship_id(
             relationships, "policy", "policies", output.claims.policy_id);
}

[[nodiscard]] bool valid_keygen_policy(
    const keygen_claim_policy_view& policy) noexcept {
  if (policy.expected_machine_fingerprint.empty() ||
      policy.expected_machine_fingerprint.size() > 256U ||
      policy.required_features.empty() || policy.required_features.size() > 64U ||
      policy.maximum_lease_seconds <= 0 ||
      policy.maximum_lease_seconds > 900) {
    return false;
  }
  for (const auto feature : policy.required_features) {
    if (feature.empty() || feature.size() > 64U) {
      return false;
    }
  }
  return true;
}

[[nodiscard]] bool has_required_features(
    const keygen_entitlement_claims& claims,
    const std::span<const std::string_view> required) noexcept {
  return std::all_of(
      required.begin(), required.end(), [&claims](const std::string_view feature) {
        return contains_feature(claims.features, feature);
      });
}

}  // namespace

keygen_verification_result verify_keygen(
    const signed_entitlement_envelope_view& envelope,
    const trust_policy_view& trust,
    const keygen_claim_policy_view& claims_policy) noexcept {
  if (!trust.has_trust_root()) {
    return reject_keygen(entitlement_error::trust_root_missing);
  }
  if (!valid_keygen_policy(claims_policy)) {
    return reject_keygen(entitlement_error::claims_malformed);
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
    return reject_keygen(entitlement_error::transport_rejected, transport.error);
  }

  try {
    parsed_keygen_claims parsed;
    if (!parse_keygen_claims(envelope.raw_body, parsed)) {
      return reject_keygen(entitlement_error::claims_malformed);
    }
    if (!parsed.validation_accepted) {
      return reject_keygen(entitlement_error::validation_rejected);
    }
    if (parsed.product_id != keygen_product_id) {
      return reject_keygen(entitlement_error::product_mismatch);
    }
    if (parsed.machine_fingerprint !=
        claims_policy.expected_machine_fingerprint) {
      return reject_keygen(entitlement_error::machine_mismatch);
    }
    if (!has_required_features(parsed.claims, claims_policy.required_features)) {
      return reject_keygen(entitlement_error::required_feature_missing);
    }
    if (transport.server_unix_seconds <= 0 ||
        static_cast<std::uint64_t>(transport.server_unix_seconds) <=
            claims_policy.last_accepted_generation) {
      return reject_keygen(entitlement_error::lease_replayed);
    }
    const auto maximum_expiry = transport.server_unix_seconds +
        claims_policy.maximum_lease_seconds;
    parsed.claims.lease_expires_unix_seconds = std::min(
        parsed.claims.license_expires_unix_seconds, maximum_expiry);
    if (trust.now_unix_seconds >= parsed.claims.license_expires_unix_seconds ||
        trust.now_unix_seconds >= parsed.claims.lease_expires_unix_seconds ||
        parsed.claims.lease_expires_unix_seconds <=
            transport.server_unix_seconds) {
      return reject_keygen(entitlement_error::lease_invalid);
    }
    parsed.claims.generation =
        static_cast<std::uint64_t>(transport.server_unix_seconds);
    return keygen_verification_result{
        .error = entitlement_error::none,
        .transport_error = sonar::licensing::verification_error::none,
        .claims = std::move(parsed.claims),
    };
  } catch (...) {
    return reject_keygen(entitlement_error::claims_malformed);
  }
}

trust_policy_view production_keygen_trust_policy(
    const std::int64_t now_unix_seconds,
    const std::int64_t maximum_response_age_seconds) noexcept {
  return trust_policy_view{
      .expected_key_id = keygen_account_id,
      .expected_method = "post",
      .expected_request_target = keygen_validation_target,
      .expected_host = keygen_host,
      .rsa_public_key_pem = keygen_public_key,
      .now_unix_seconds = now_unix_seconds,
      .maximum_response_age_seconds = maximum_response_age_seconds,
      .maximum_future_skew_seconds = 60,
  };
}

}  // namespace sonar::fishing::entitlement
