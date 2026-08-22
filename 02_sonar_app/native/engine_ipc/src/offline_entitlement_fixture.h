#pragma once

#include <array>
#include <cstdint>
#include <string_view>

#include "sonar/fishing/entitlement/entitlement.h"

namespace sonar::fishing::engine_ipc::offline_entitlement_fixture {

inline constexpr std::string_view key_id =
    "11111111-1111-1111-1111-111111111111";
inline constexpr std::string_view method = "post";
inline constexpr std::string_view request_target =
    "/v1/accounts/11111111-1111-1111-1111-111111111111/licenses/actions/validate-key?include=policy";
inline constexpr std::string_view host = "api.keygen.sh";
inline constexpr std::string_view public_key = R"(-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAvyu5ufxlJkqYvDtSQ6lo
mW8/QmOJqh268hSvvGConlcCtjx2O0cMuJwvHm790joGjY9ARqr2pce/8JOgE2xE
WmEPxC+KDLN1g01i2m4hDlDzEkzisUFHlVfh1mVFIMYFPhj1/YoexnYEOdSB8iSD
bojfWzkVUUbeRWIk2tpXopOOyg1/oGOb502a2TfPZFdM3bwiRLPIl+flPxm6aQ7D
JfIkdSWWCU/vZZQZRpuRauJEQUkpMvboBoOCW85WfjKw2XRJrxYFjEtzCsSg4NyJ
FHYJVNwI3GKAskuty+0U9mvPyDWawI4I9FGqNWRya/n8Zi6o1UwLv+fhtoQIIISu
9QIDAQAB
-----END PUBLIC KEY-----)";
inline constexpr std::string_view machine_fingerprint = "machine-test-001";
inline constexpr std::string_view bundle_manifest_hash = "bundle-test-sha256";
inline constexpr std::string_view policy_id = "policy-fishing-test";
inline constexpr std::array<std::string_view, 2> required_features = {
    "fishing",
    "fishing_bot",
};
inline constexpr std::int64_t now_unix_seconds = 1787360580;

[[nodiscard]] inline entitlement::trust_policy_view trust() noexcept {
  return entitlement::trust_policy_view{
      .expected_key_id = key_id,
      .expected_method = method,
      .expected_request_target = request_target,
      .expected_host = host,
      .rsa_public_key_pem = public_key,
      .now_unix_seconds = now_unix_seconds,
      .maximum_response_age_seconds = 300,
      .maximum_future_skew_seconds = 60,
  };
}

[[nodiscard]] inline entitlement::claim_policy_view claims(
    const std::uint64_t last_accepted_generation) noexcept {
  return entitlement::claim_policy_view{
      .expected_machine_fingerprint = machine_fingerprint,
      .expected_bundle_manifest_hash = bundle_manifest_hash,
      .expected_policy_id = policy_id,
      .required_features = required_features,
      .last_accepted_generation = last_accepted_generation,
      .maximum_lease_seconds = 600,
  };
}

}  // namespace sonar::fishing::engine_ipc::offline_entitlement_fixture
