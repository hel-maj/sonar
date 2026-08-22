#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include "sonar/fishing/entitlement/entitlement.h"
#include "sonar/fishing/entitlement/windows_machine_fingerprint.h"

namespace {

namespace entitlement = sonar::fishing::entitlement;

struct fixture final {
  std::map<std::string, std::string, std::less<>> properties;
  std::string public_key;
  std::vector<std::byte> raw_body;

  [[nodiscard]] const std::string& value(const std::string_view key) const {
    const auto found = properties.find(key);
    if (found == properties.end()) {
      throw std::runtime_error("fixture_property_missing");
    }
    return found->second;
  }

  [[nodiscard]] entitlement::signed_entitlement_envelope_view envelope() const {
    return entitlement::signed_entitlement_envelope_view{
        .method = value("method"),
        .request_target = value("requestTarget"),
        .host = value("host"),
        .date_header = value("date"),
        .digest_header = value("digest"),
        .signature_header = value("signature"),
        .raw_body = raw_body,
    };
  }

  [[nodiscard]] entitlement::trust_policy_view trust() const {
    return entitlement::trust_policy_view{
        .expected_key_id = value("keyId"),
        .expected_method = value("method"),
        .expected_request_target = value("requestTarget"),
        .expected_host = value("host"),
        .rsa_public_key_pem = public_key,
        .now_unix_seconds = std::stoll(value("nowUnix")),
        .maximum_response_age_seconds = 300,
        .maximum_future_skew_seconds = 60,
    };
  }
};

[[nodiscard]] std::string read_all(const std::filesystem::path& path) {
  std::ifstream stream(path, std::ios::binary);
  if (!stream) {
    throw std::runtime_error("fixture_open_failed");
  }
  return std::string(
      std::istreambuf_iterator<char>(stream),
      std::istreambuf_iterator<char>());
}

[[nodiscard]] int hex_nibble(const char value) noexcept {
  if (value >= '0' && value <= '9') {
    return value - '0';
  }
  if (value >= 'A' && value <= 'F') {
    return value - 'A' + 10;
  }
  if (value >= 'a' && value <= 'f') {
    return value - 'a' + 10;
  }
  return -1;
}

[[nodiscard]] fixture load_fixture(const std::string_view fixture_name) {
  const std::filesystem::path root = SONAR_FISHING_ENTITLEMENT_FIXTURE_ROOT;
  fixture result;
  const auto prefix = std::string(fixture_name);
  std::ifstream properties(root / (prefix + ".properties"));
  std::string line;
  while (std::getline(properties, line)) {
    if (!line.empty() && line.back() == '\r') {
      line.pop_back();
    }
    if (line.empty() || line.front() == '#') {
      continue;
    }
    const auto separator = line.find('=');
    if (separator == std::string::npos || separator == 0) {
      throw std::runtime_error("fixture_property_invalid");
    }
    result.properties.emplace(
        line.substr(0, separator), line.substr(separator + 1));
  }
  if (result.value("schemaVersion") != "1") {
    throw std::runtime_error("fixture_schema_invalid");
  }
  result.public_key = read_all(root / (prefix + "-public.pem"));
  const auto encoded = read_all(root / (prefix + "-body.hex"));
  std::string compact;
  for (const char value : encoded) {
    if (value != ' ' && value != '\t' && value != '\r' && value != '\n') {
      compact.push_back(value);
    }
  }
  if (compact.empty() || compact.size() % 2 != 0) {
    throw std::runtime_error("fixture_body_hex_invalid");
  }
  result.raw_body.reserve(compact.size() / 2);
  for (std::size_t index = 0; index < compact.size(); index += 2) {
    const auto high = hex_nibble(compact[index]);
    const auto low = hex_nibble(compact[index + 1]);
    if (high < 0 || low < 0) {
      throw std::runtime_error("fixture_body_hex_invalid");
    }
    result.raw_body.push_back(
        static_cast<std::byte>((high << 4) | low));
  }
  return result;
}

[[nodiscard]] fixture load_fixture() {
  return load_fixture("signed-entitlement-v1");
}

[[nodiscard]] entitlement::claim_policy_view claim_policy(
    const fixture& source,
    const std::span<const std::string_view> required,
    const std::uint64_t last_generation = 0,
    const std::string_view machine = {}) {
  return entitlement::claim_policy_view{
      .expected_machine_fingerprint = machine.empty()
          ? std::string_view(source.value("machineFingerprint"))
          : machine,
      .expected_bundle_manifest_hash = source.value("bundleManifestHash"),
      .expected_policy_id = source.value("policyId"),
      .required_features = required,
      .last_accepted_generation = last_generation,
      .maximum_lease_seconds = 600,
  };
}

[[nodiscard]] entitlement::keygen_claim_policy_view keygen_claim_policy(
    const fixture& source,
    const std::span<const std::string_view> required,
    const std::uint64_t last_generation = 0,
    const std::string_view machine = {}) {
  return entitlement::keygen_claim_policy_view{
      .expected_machine_fingerprint = machine.empty()
          ? std::string_view(source.value("machineFingerprint"))
          : machine,
      .required_features = required,
      .last_accepted_generation = last_generation,
      .maximum_lease_seconds = 600,
  };
}

void require(const bool condition, const std::string_view message) {
  if (!condition) {
    throw std::runtime_error(std::string(message));
  }
}

void golden_signed_entitlement_is_accepted() {
  const auto source = load_fixture();
  constexpr std::string_view required[] = {"fishing", "fishing_bot"};
  const auto result = entitlement::verify(
      source.envelope(), source.trust(), claim_policy(source, required));
  require(result.accepted(), "golden_entitlement_rejected");
  require(result.claims->license_id == "license-test", "license_id_changed");
  require(result.claims->generation == 7, "generation_changed");
}

void production_missing_trust_root_is_closed() {
  const auto source = load_fixture();
  constexpr std::string_view required[] = {"fishing", "fishing_bot"};
  const auto result = entitlement::verify(
      source.envelope(),
      entitlement::production_trust_policy_missing_key(
          std::stoll(source.value("nowUnix"))),
      claim_policy(source, required));
  require(!result.accepted(), "missing_trust_root_accepted");
  require(
      result.error == entitlement::entitlement_error::trust_root_missing,
      "missing_trust_root_reason_changed");
}

void transport_and_claim_policy_fail_closed() {
  auto source = load_fixture();
  constexpr std::string_view required[] = {"fishing", "fishing_bot"};
  source.raw_body.back() ^= std::byte{1};
  const auto transport = entitlement::verify(
      source.envelope(), source.trust(), claim_policy(source, required));
  require(
      transport.error == entitlement::entitlement_error::transport_rejected,
      "mutated_body_reached_claims");
  require(
      transport.transport_error ==
          sonar::licensing::verification_error::digest_mismatch,
      "mutated_body_reason_changed");

  source = load_fixture();
  const auto machine = entitlement::verify(
      source.envelope(),
      source.trust(),
      claim_policy(source, required, 0, "other-machine"));
  require(
      machine.error == entitlement::entitlement_error::machine_mismatch,
      "machine_mismatch_accepted");
}

void generation_and_feature_policy_fail_closed() {
  const auto source = load_fixture();
  constexpr std::string_view required[] = {"fishing", "fishing_bot"};
  const auto replay = entitlement::verify(
      source.envelope(), source.trust(), claim_policy(source, required, 7));
  require(
      replay.error == entitlement::entitlement_error::lease_replayed,
      "equal_generation_replayed");

  constexpr std::string_view unavailable[] = {"fishing", "stream"};
  const auto feature = entitlement::verify(
      source.envelope(), source.trust(), claim_policy(source, unavailable));
  require(
      feature.error == entitlement::entitlement_error::required_feature_missing,
      "missing_feature_accepted");
}

void current_keygen_schema_is_independently_accepted() {
  const auto source = load_fixture("keygen-response-v1");
  constexpr std::string_view required[] = {"fishing", "fishing_bot"};
  const auto result = entitlement::verify_keygen(
      source.envelope(), source.trust(), keygen_claim_policy(source, required));
  if (!result.accepted()) {
    throw std::runtime_error(
        "current_keygen_schema_rejected:" +
        std::to_string(static_cast<std::uint32_t>(result.error)) + ":" +
        std::to_string(static_cast<std::uint32_t>(result.transport_error)));
  }
  require(result.claims->license_id == "license-001", "keygen_license_id_changed");
  require(result.claims->policy_id == "policy-001", "keygen_policy_id_changed");
  require(result.claims->group == "basic", "keygen_group_changed");
  require(
      result.claims->generation ==
          static_cast<std::uint64_t>(std::stoull(source.value("generation"))),
      "keygen_server_date_generation_changed");
  require(
      result.claims->lease_expires_unix_seconds == 1787361123,
      "keygen_short_lease_changed");
}

void current_keygen_schema_transport_machine_feature_and_replay_fail_closed() {
  auto source = load_fixture("keygen-response-v1");
  constexpr std::string_view required[] = {"fishing", "fishing_bot"};
  source.raw_body.back() ^= std::byte{1};
  const auto transport = entitlement::verify_keygen(
      source.envelope(), source.trust(), keygen_claim_policy(source, required));
  require(
      transport.error == entitlement::entitlement_error::transport_rejected,
      "tampered_keygen_body_reached_claims");

  source = load_fixture("keygen-response-v1");
  const auto machine = entitlement::verify_keygen(
      source.envelope(),
      source.trust(),
      keygen_claim_policy(source, required, 0, "other-machine"));
  require(
      machine.error == entitlement::entitlement_error::machine_mismatch,
      "keygen_machine_mismatch_accepted");

  constexpr std::string_view unavailable[] = {"fishing", "stream"};
  const auto feature = entitlement::verify_keygen(
      source.envelope(),
      source.trust(),
      keygen_claim_policy(source, unavailable));
  require(
      feature.error == entitlement::entitlement_error::required_feature_missing,
      "keygen_missing_feature_accepted");

  const auto replay = entitlement::verify_keygen(
      source.envelope(),
      source.trust(),
      keygen_claim_policy(
          source,
          required,
          static_cast<std::uint64_t>(std::stoull(source.value("generation")))));
  require(
      replay.error == entitlement::entitlement_error::lease_replayed,
      "keygen_equal_generation_replayed");
}

void production_keygen_trust_root_is_embedded() {
  const auto trust = entitlement::production_keygen_trust_policy(1787360580);
  require(trust.has_trust_root(), "production_keygen_trust_root_missing");
  require(
      trust.expected_key_id == "e8b61b74-558a-4d85-9bc5-4ac5870a27ae",
      "production_keygen_key_id_changed");
  require(
      trust.expected_request_target ==
          "/v1/licenses/actions/validate-key?include=policy",
      "production_keygen_target_changed");
  require(trust.expected_host == "m-sonar-addr.ru", "production_keygen_host_changed");
  require(
      trust.rsa_public_key_pem.find("BEGIN PUBLIC KEY") != std::string_view::npos,
      "production_keygen_public_key_invalid");
}

void native_machine_fingerprint_matches_managed_contract() {
  const auto fingerprint = entitlement::compute_machine_fingerprint(
      "Windows", "AMD64", "machine-guid", "123456", "fallback");
  require(
      fingerprint ==
          "690109d05ab5a84e4a41ef98e8438a147fa594006a191075e2067c292944c4b5",
      "native_managed_machine_fingerprint_diverged");
  require(
      fingerprint == entitlement::compute_machine_fingerprint(
          "Windows", "AMD64", "machine-guid", "123456", "other-fallback"),
      "machine_fingerprint_used_irrelevant_fallback");
}

}  // namespace

int main() {
  const std::vector<std::pair<std::string_view, void (*)()>> tests = {
      {"golden_signed_entitlement_is_accepted", golden_signed_entitlement_is_accepted},
      {"production_missing_trust_root_is_closed", production_missing_trust_root_is_closed},
      {"transport_and_claim_policy_fail_closed", transport_and_claim_policy_fail_closed},
      {"generation_and_feature_policy_fail_closed", generation_and_feature_policy_fail_closed},
      {"current_keygen_schema_is_independently_accepted", current_keygen_schema_is_independently_accepted},
      {"current_keygen_schema_transport_machine_feature_and_replay_fail_closed", current_keygen_schema_transport_machine_feature_and_replay_fail_closed},
      {"production_keygen_trust_root_is_embedded", production_keygen_trust_root_is_embedded},
      {"native_machine_fingerprint_matches_managed_contract", native_machine_fingerprint_matches_managed_contract},
  };
  std::size_t failures = 0;
  for (const auto& [name, run] : tests) {
    try {
      run();
      std::cout << "PASS " << name << '\n';
    } catch (const std::exception& error) {
      ++failures;
      std::cerr << "FAIL " << name << ": " << error.what() << '\n';
    }
  }
  std::cout << "Executed " << tests.size()
            << " Fishing entitlement tests; failures: " << failures << ".\n";
  return failures == 0 ? 0 : 1;
}
