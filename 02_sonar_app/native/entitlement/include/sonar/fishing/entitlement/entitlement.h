#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "sonar/licensing/signed_response_verifier.hpp"

namespace sonar::fishing::entitlement {

inline constexpr std::string_view product_id = "fishing";
inline constexpr std::string_view audience = "sonar-fishing-engine";

enum class entitlement_error : std::uint32_t {
  none = 0,
  trust_root_missing,
  transport_rejected,
  claims_malformed,
  validation_rejected,
  product_mismatch,
  audience_mismatch,
  machine_mismatch,
  bundle_mismatch,
  policy_mismatch,
  required_feature_missing,
  lease_invalid,
  lease_replayed,
};

struct signed_entitlement_envelope_view final {
  std::string_view method;
  std::string_view request_target;
  std::string_view host;
  std::string_view date_header;
  std::string_view digest_header;
  std::string_view signature_header;
  std::span<const std::byte> raw_body;
};

struct trust_policy_view final {
  std::string_view expected_key_id;
  std::string_view expected_method;
  std::string_view expected_request_target;
  std::string_view expected_host;
  std::string_view rsa_public_key_pem;
  std::int64_t now_unix_seconds{};
  std::int64_t maximum_response_age_seconds{};
  std::int64_t maximum_future_skew_seconds{};

  [[nodiscard]] constexpr bool has_trust_root() const noexcept {
    return !expected_key_id.empty() && !rsa_public_key_pem.empty();
  }
};

struct claim_policy_view final {
  std::string_view expected_machine_fingerprint;
  std::string_view expected_bundle_manifest_hash;
  std::string_view expected_policy_id;
  std::span<const std::string_view> required_features;
  std::uint64_t last_accepted_generation{};
  std::int64_t maximum_lease_seconds{};
};

struct entitlement_claims final {
  std::string license_id;
  std::string machine_fingerprint;
  std::string bundle_manifest_hash;
  std::string policy_id;
  std::vector<std::string> features;
  std::int64_t issued_unix_seconds{};
  std::int64_t expires_unix_seconds{};
  std::uint64_t generation{};
};

struct verification_result final {
  entitlement_error error{entitlement_error::claims_malformed};
  sonar::licensing::verification_error transport_error{
      sonar::licensing::verification_error::none};
  std::optional<entitlement_claims> claims;

  [[nodiscard]] bool accepted() const noexcept {
    return error == entitlement_error::none && claims.has_value();
  }
};

struct keygen_claim_policy_view final {
  std::string_view expected_machine_fingerprint;
  std::span<const std::string_view> required_features;
  std::uint64_t last_accepted_generation{};
  std::int64_t maximum_lease_seconds{};
};

struct keygen_entitlement_claims final {
  std::string license_id;
  std::string policy_id;
  std::string group;
  std::vector<std::string> features;
  std::int64_t license_expires_unix_seconds{};
  std::int64_t lease_expires_unix_seconds{};
  std::uint64_t generation{};
};

struct keygen_verification_result final {
  entitlement_error error{entitlement_error::claims_malformed};
  sonar::licensing::verification_error transport_error{
      sonar::licensing::verification_error::none};
  std::optional<keygen_entitlement_claims> claims;

  [[nodiscard]] bool accepted() const noexcept {
    return error == entitlement_error::none && claims.has_value();
  }
};

[[nodiscard]] verification_result verify(
    const signed_entitlement_envelope_view& envelope,
    const trust_policy_view& trust,
    const claim_policy_view& claims_policy) noexcept;

// Verifies the exact current Keygen CE JSON:API validation response after the
// same raw RSA-signed HTTP envelope has been admitted. It intentionally does
// not accept the older migration fixture claim schema used by verify().
[[nodiscard]] keygen_verification_result verify_keygen(
    const signed_entitlement_envelope_view& envelope,
    const trust_policy_view& trust,
    const keygen_claim_policy_view& claims_policy) noexcept;

[[nodiscard]] trust_policy_view production_keygen_trust_policy(
    std::int64_t now_unix_seconds,
    std::int64_t maximum_response_age_seconds = 300) noexcept;

// Compatibility helper retained for characterization tests of the previous
// fail-closed migration stage. Production uses production_keygen_trust_policy.
[[nodiscard]] trust_policy_view production_trust_policy_missing_key(
    std::int64_t now_unix_seconds) noexcept;

}  // namespace sonar::fishing::entitlement
