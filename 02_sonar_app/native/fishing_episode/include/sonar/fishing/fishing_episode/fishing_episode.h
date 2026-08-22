#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <stop_token>
#include <string>

#include "sonar/fishing/memory_observation/memory_observation.h"
#include "sonar/fishing/reeling_control/reeling_control.h"
#include "sonar/fishing/stage_detection/fishing_stage_detector.h"

namespace sonar::fishing::fishing_episode {

inline constexpr std::size_t maximum_episode_observations = 8'192U;
inline constexpr std::uint64_t maximum_episode_duration_ns =
    5ULL * 60ULL * 1'000'000'000ULL;

enum class hook_cue : std::uint8_t {
  none = 0,
  red = 1,
  bubbles = 2,
};

// One Engine observation cycle. The E14 stage and E11 memory snapshot must use
// this exact sequence/time when memory evidence is present. Cast/hook cues are
// semantic detector facts; no frame or detector step crosses the Host boundary.
struct fishing_episode_observation final {
  std::uint64_t sequence{};
  std::uint64_t captured_at_steady_ns{};
  std::optional<stage_detection::stage_observation> stage;
  std::optional<memory_observation::coherent_memory_snapshot> memory;
  bool cast_ready{};
  double cast_confidence{};
  hook_cue hook{hook_cue::none};
  double hook_confidence{};
  bool catch_visible{};
  std::string error;
};

struct fishing_episode_request final {
  // Shipping composition remains off until product admission deliberately
  // enables it and supplies a guarded mutation port.
  bool automation_enabled{};
  bool reeling_input_enabled{true};
  std::uint64_t accepted_settings_revision{};
  std::uint64_t expected_entitlement_revision{};
  std::uint64_t expected_lifecycle_revision{};
  // One nonzero token per whole cast-hook-reel episode. The one-fish-per-
  // episode invariant lets the reeling estimator reset without exposing a
  // memory address or target-resolver detail through this contract.
  std::uint64_t episode_identity{};
  std::size_t maximum_observations{4'096U};
  std::uint64_t casting_timeout_ns{10ULL * 1'000'000'000ULL};
  std::uint64_t casting_confirmation_timeout_ns{8ULL * 1'000'000'000ULL};
  std::uint64_t hooking_timeout_ns{60ULL * 1'000'000'000ULL};
  std::uint64_t hooking_confirmation_timeout_ns{3ULL * 1'000'000'000ULL};
  std::uint64_t reeling_timeout_ns{180ULL * 1'000'000'000ULL};
  std::uint64_t episode_timeout_ns{260ULL * 1'000'000'000ULL};
};

class fishing_episode_observer {
 public:
  virtual ~fishing_episode_observer() = default;
  [[nodiscard]] virtual fishing_episode_observation observe(
      std::stop_token stop_token) = 0;
};

enum class fishing_mutation_kind : std::uint8_t {
  tap_cast_space = 0,
  tap_hook_space = 1,
  // A/D is emitted as one bounded down/up packet pair. The Engine never
  // keeps a synthetic reeling key down across observations.
  pulse_reeling_key = 2,
};

struct fishing_mutation_intent final {
  fishing_mutation_kind kind{fishing_mutation_kind::tap_cast_space};
  std::uint64_t expected_observation_sequence{};
  std::uint64_t expected_settings_revision{};
  std::uint64_t expected_entitlement_revision{};
  std::uint64_t expected_lifecycle_revision{};
  reeling_control::HeldKey desired_reeling_key{
      reeling_control::HeldKey::none};
  std::size_t packet_count{};
};

struct fishing_mutation_result final {
  bool applied{};
  std::string reason;

  [[nodiscard]] static fishing_mutation_result accepted();
  [[nodiscard]] static fishing_mutation_result rejected(std::string reason);
};

// Acquiring a session acquires only the shared exclusive Engine input lease; it
// is not authorization. apply() must immediately revalidate entitlement,
// settings/lifecycle revisions, exact process/window generation, foreground
// identity and Common packet budget before every matching side effect.
class fishing_mutation_session {
 public:
  virtual ~fishing_mutation_session() = default;
  [[nodiscard]] virtual fishing_mutation_result apply(
      const fishing_mutation_intent& intent,
      std::stop_token stop_token) = 0;

  // Cleanup is one bounded best-effort A/D key-up batch. A live implementation
  // still validates exact target identity, but does not skip a safety release
  // merely because cancellation or entitlement revocation was observed.
  [[nodiscard]] virtual fishing_mutation_result cleanup_reeling_keys(
      std::uint64_t expected_observation_sequence) noexcept = 0;
};

class fishing_mutation_port {
 public:
  virtual ~fishing_mutation_port() = default;
  [[nodiscard]] virtual std::unique_ptr<fishing_mutation_session> acquire(
      const fishing_episode_request& request,
      std::stop_token stop_token,
      std::string& reason) = 0;
};

enum class fishing_episode_outcome : std::uint8_t {
  none = 0,
  memory_finished = 1,
  catch_visible = 2,
};

struct fishing_episode_result final {
  bool ok{};
  std::string reason;
  fishing_episode_outcome outcome{fishing_episode_outcome::none};
  std::size_t observations_consumed{};
  std::size_t mutations_applied{};
  bool cleanup_attempted{};
  bool cleanup_completed{};
  fishing_episode_observation observation;
};

class fishing_episode_runner final {
 public:
  [[nodiscard]] fishing_episode_result run(
      const fishing_episode_request& request,
      fishing_episode_observer& observer,
      fishing_mutation_port& mutation,
      std::stop_token stop_token = {}) const;
};

// The only shipping-ready default. It acquires no lease and performs no
// process/window/capture/input operation.
class disabled_fishing_mutation_port final : public fishing_mutation_port {
 public:
  [[nodiscard]] std::unique_ptr<fishing_mutation_session> acquire(
      const fishing_episode_request& request,
      std::stop_token stop_token,
      std::string& reason) override;
};

[[nodiscard]] const char* fishing_mutation_key(
    fishing_mutation_kind kind) noexcept;
[[nodiscard]] const char* fishing_outcome_key(
    fishing_episode_outcome outcome) noexcept;

}  // namespace sonar::fishing::fishing_episode
