#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "sonar/platform/windows/process.hpp"
#include "sonar/platform/inventory/open_state.hpp"

namespace sonar::fishing::memory_observation {

inline constexpr std::size_t maximum_read_region_bytes = 256U * 1024U;
inline constexpr std::size_t maximum_capture_bytes = 1024U * 1024U;
inline constexpr std::size_t maximum_read_regions = 96U;
inline constexpr std::size_t maximum_inventory_candidates = 80U;
inline constexpr std::size_t maximum_status_candidates = 48U;

enum class process_role {
  game,
  webengine,
};

enum class evidence_region_kind {
  reeling_player,
  reeling_fish,
  reeling_fish_identity,
  inventory_candidate,
  player_status_candidate,
  player_status_window,
  chat_state_window,
};

enum class scalar_type {
  u8,
  i8,
  u16_le,
  i16_le,
  u32_le,
  i32_le,
  f32_le,
  f64_le,
};

enum class player_status_field {
  food,
  water,
  health,
};

enum class chat_confidence {
  unknown,
  low,
  medium,
  high,
};

enum class capture_failure {
  none,
  disabled,
  invalid_profile,
  invalid_plan,
  sequence_replayed,
  process_unavailable,
  process_identity_mismatch,
  profile_hash_mismatch,
  read_failed,
  process_changed,
  decode_failed,
};

struct expected_process final {
  std::wstring image_name;
  std::string image_sha256;
  bool required{true};
};

struct reeling_layout final {
  std::size_t player_position_offset{};
  std::size_t player_right_offset{};
  std::size_t fish_position_offset{};
  std::size_t fish_model_hash_offset{};
  std::size_t fish_active_offset{};
  std::uint32_t expected_fish_model_hash{802685111U};
  double maximum_distance{120.0};
};

struct inventory_candidate final {
  std::uint8_t closed_value{};
  std::uint8_t open_value{};
  double weight{1.0};
};

struct status_candidate final {
  player_status_field field{player_status_field::food};
  scalar_type type{scalar_type::u8};
  double scale{1.0};
  double offset{};
  double minimum{0.0};
  double maximum{100.0};
};

struct memory_observation_profile final {
  std::string profile_id;
  std::uint32_t profile_revision{};
  expected_process game;
  expected_process webengine;
  reeling_layout reeling;
  std::vector<inventory_candidate> inventory_candidates;
  std::vector<status_candidate> status_candidates;
  std::size_t minimum_inventory_votes{6U};
  double minimum_inventory_confidence{0.85};
  bool require_reeling{true};
  bool require_inventory{true};
  bool require_player_status{true};
  bool require_chat{true};
};

struct read_region final {
  evidence_region_kind kind{evidence_region_kind::reeling_player};
  process_role role{process_role::game};
  std::uint32_t slot{};
  std::uintptr_t address{};
  std::size_t size{};
};

struct capture_plan final {
  std::uint64_t sequence{};
  std::uint64_t captured_at_steady_ns{};
  std::uint32_t game_process_id{};
  std::uint32_t webengine_process_id{};
  sonar::platform::windows::process_generation expected_game_generation;
  std::optional<sonar::platform::windows::process_generation>
      expected_webengine_generation;
  std::vector<read_region> regions;
};

struct process_identity final {
  process_role role{process_role::game};
  sonar::platform::windows::process_generation generation;
  std::wstring image_name;
  std::string image_sha256;
  std::vector<sonar::platform::windows::module_snapshot> modules;
};

struct vector3 final {
  double x{};
  double y{};
  double z{};
};

struct reeling_evidence final {
  bool active{};
  bool fish_model_confirmed{};
  vector3 player_position;
  vector3 fish_position;
  double player_right_x{};
  double player_right_y{};
  double distance{};
};

struct inventory_evidence final {
  bool open{};
  std::size_t matched_votes{};
  double confidence{};
};

struct player_status_evidence final {
  std::optional<int> food;
  std::optional<int> water;
  std::optional<int> health;
  std::optional<double> inventory_weight;
  std::optional<double> inventory_weight_max;
  std::optional<double> backpack_weight;
  std::optional<double> backpack_weight_max;

  [[nodiscard]] bool has_any_value() const noexcept;
};

struct chat_evidence final {
  std::optional<bool> input_active;
  std::optional<bool> visible;
  std::string active_tab_id;
  chat_confidence confidence{chat_confidence::unknown};

  [[nodiscard]] bool has_any_value() const noexcept;
};

struct coherent_memory_snapshot final {
  std::uint64_t sequence{};
  std::uint64_t captured_at_steady_ns{};
  std::string profile_id;
  std::uint32_t profile_revision{};
  sonar::platform::windows::process_generation game_generation;
  std::optional<sonar::platform::windows::process_generation>
      webengine_generation;
  std::optional<reeling_evidence> reeling;
  std::optional<inventory_evidence> inventory;
  std::optional<sonar::platform::inventory::observed_state>
      inventory_open_state;
  std::optional<player_status_evidence> player_status;
  std::optional<chat_evidence> chat;
};

struct capture_result final {
  std::optional<coherent_memory_snapshot> snapshot;
  capture_failure failure{capture_failure::none};
  std::string reason;

  [[nodiscard]] bool ready() const noexcept;
};

class readonly_memory_session {
 public:
  virtual ~readonly_memory_session() = default;
  [[nodiscard]] virtual const process_identity& identity() const noexcept = 0;
  [[nodiscard]] virtual bool read_exact(
      std::uintptr_t address,
      std::span<std::byte> destination) noexcept = 0;
  [[nodiscard]] virtual std::optional<
      sonar::platform::windows::memory_region_snapshot>
  query_region(std::uintptr_t address) noexcept = 0;
  [[nodiscard]] virtual bool generation_current() noexcept = 0;
};

class memory_connector {
 public:
  virtual ~memory_connector() = default;
  [[nodiscard]] virtual std::unique_ptr<readonly_memory_session> connect(
      process_role role,
      std::uint32_t process_id,
      std::string& reason) noexcept = 0;
};

class disabled_memory_connector final : public memory_connector {
 public:
  [[nodiscard]] std::unique_ptr<readonly_memory_session> connect(
      process_role role,
      std::uint32_t process_id,
      std::string& reason) noexcept override;
};

// This factory is the only shipping platform seam. It uses the frozen Common
// least-rights readonly_process implementation and adds Fishing's executable
// hash/profile policy. Creating the connector performs no process access.
[[nodiscard]] std::unique_ptr<memory_connector>
make_windows_memory_connector();

[[nodiscard]] std::optional<reeling_evidence> decode_reeling_evidence(
    std::span<const std::byte> player,
    std::span<const std::byte> fish,
    const reeling_layout& layout) noexcept;

[[nodiscard]] std::optional<inventory_evidence> decode_inventory_evidence(
    std::span<const std::byte> samples,
    std::span<const inventory_candidate> candidates,
    std::size_t minimum_votes,
    double minimum_confidence) noexcept;

[[nodiscard]] std::optional<player_status_evidence>
decode_player_status_evidence(
    std::span<const std::vector<std::byte>> scalar_samples,
    std::span<const status_candidate> candidates,
    std::span<const std::byte> webengine_window) noexcept;

[[nodiscard]] std::optional<chat_evidence> decode_chat_evidence(
    std::span<const std::byte> state_window) noexcept;

// A single Engine owner calls capture(). Reads are bounded and revalidated as
// one cycle. No per-field Host RPC is exposed by this capability.
class memory_observer final {
 public:
  explicit memory_observer(memory_connector& connector) noexcept;

  [[nodiscard]] capture_result capture(
      const memory_observation_profile& profile,
      const capture_plan& plan) noexcept;

  // Drop process handles after a bounded adapter failure without weakening
  // sequence replay protection. The next fresh plan reconnects explicitly.
  void reset_sessions() noexcept;

 private:
  memory_connector& connector_;
  std::unique_ptr<readonly_memory_session> game_session_;
  std::unique_ptr<readonly_memory_session> webengine_session_;
  std::uint64_t last_sequence_{};
};

inline constexpr std::uint32_t embedded_build_profile_schema_version = 2U;
inline constexpr std::string_view embedded_build_profile_registry_sha256 =
    "A49D7CE5FE04EB3E5B24DCC717A5AF160E315D0C9449DA725B1578A643F9EB8C";

// Product-owned, immutable pattern data for one exact game image. The
// registry is embedded into Sonar.Engine.exe; no loose profile or mutable
// address file is consumed at runtime.
struct relative_pointer_pattern final {
  std::vector<std::int16_t> bytes;
  std::size_t displacement_offset{};
  std::size_t instruction_length{};
  std::vector<std::size_t> dereference_offsets;
};

struct masked_memory_pattern final {
  std::vector<std::int16_t> bytes;
};

struct embedded_inventory_signal final {
  std::size_t offset{};
  inventory_candidate candidate;
};

// A binding is admitted only as part of one exact executable profile. Empty
// optional state means that the build has no production inventory authority;
// it is not permission to reuse a loose development profile or stale address.
struct embedded_inventory_binding final {
  std::uintptr_t minimum_address_inclusive{};
  std::uintptr_t maximum_address_exclusive{};
  std::size_t maximum_scanned_bytes{};
  std::size_t maximum_region_bytes{};
  std::size_t maximum_enumerated_regions{};
  std::size_t maximum_pattern_hits{};
  std::size_t slot_stride{};
  std::size_t slot_count{};
  masked_memory_pattern slot_pattern;
  std::vector<embedded_inventory_signal> signals;
  std::size_t minimum_votes{6U};
  double minimum_confidence{0.85};
};

struct embedded_memory_build_profile final {
  std::uint32_t schema_version{};
  std::string profile_id;
  std::uint32_t profile_revision{};
  expected_process game;
  std::vector<std::size_t> player_matrix_offsets;
  std::vector<std::size_t> fish_position_offsets;
  std::uint32_t fish_model_hash{};
  std::size_t fish_active_offset{};
  std::vector<relative_pointer_pattern> world_patterns;
  relative_pointer_pattern replay_pattern;
  std::optional<embedded_inventory_binding> inventory_binding;
};

struct build_profile_selection final {
  const embedded_memory_build_profile* profile{};
  std::string reason;

  [[nodiscard]] bool ready() const noexcept;
};

[[nodiscard]] std::span<const embedded_memory_build_profile>
embedded_memory_build_profiles() noexcept;

[[nodiscard]] build_profile_selection select_embedded_memory_build_profile(
    std::wstring_view image_name,
    std::string_view image_sha256) noexcept;

[[nodiscard]] build_profile_selection select_memory_build_profile(
    std::span<const embedded_memory_build_profile> profiles,
    std::wstring_view image_name,
    std::string_view image_sha256) noexcept;

[[nodiscard]] std::string embedded_memory_build_profile_canonical_tsv();

struct resolved_memory_capture final {
  std::optional<memory_observation_profile> profile;
  std::optional<capture_plan> plan;
  std::string registry_sha256;
  std::string reason;

  [[nodiscard]] bool ready() const noexcept;
};

enum class inventory_binding_failure : std::uint8_t {
  none,
  profile_unavailable,
  region_enumeration_failed,
  scan_incomplete,
  signature_unresolved,
  signature_ambiguous,
  signature_changed,
  process_changed,
  internal_error,
};

struct resolved_inventory_capture final {
  std::optional<memory_observation_profile> profile;
  std::optional<capture_plan> plan;
  inventory_binding_failure failure{inventory_binding_failure::none};
  std::string registry_sha256;
  std::string reason;

  [[nodiscard]] bool ready() const noexcept;
};

// Resolves the legacy-characterized player/replay/fish chains only after the
// exact image hash selects an embedded profile. Resolution is bounded, cached
// by process generation, and revalidates the fish identity before every plan.
class memory_capture_plan_resolver final {
 public:
  explicit memory_capture_plan_resolver(memory_connector& connector) noexcept;
  memory_capture_plan_resolver(
      memory_connector& connector,
      std::span<const embedded_memory_build_profile> profiles) noexcept;

  [[nodiscard]] resolved_memory_capture resolve_reeling(
      std::uint64_t sequence,
      std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation)
      noexcept;

  // Offline characterization compatibility seam. Production adapter code is
  // forbidden from calling this legacy inventory branch; it uses
  // resolve_reeling or the exact-pinned Common facade instead.
  [[nodiscard]] resolved_memory_capture resolve_runtime_observation(
      std::uint64_t sequence,
      std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation,
      bool reeling_stage_visible) noexcept;

  // Historical Fishing binding resolver for fixtures/characterization only.
  [[nodiscard]] resolved_inventory_capture resolve_inventory(
      std::uint64_t sequence,
      std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation)
      noexcept;

  // A confirmed inactive fish remains pending until the corresponding fresh
  // coherent snapshot succeeds. The adapter may preserve it for one bounded
  // read/decode retry; every other cache is invalidated normally.
  void commit_capture(const coherent_memory_snapshot& snapshot) noexcept;
  void prepare_capture_retry() noexcept;
  [[nodiscard]] bool terminal_transition_pending() const noexcept;

  void reset() noexcept;

 private:
  [[nodiscard]] std::string prepare_session(
      const sonar::platform::windows::process_generation& game_generation)
      noexcept;

  memory_connector& connector_;
  std::span<const embedded_memory_build_profile> profiles_;
  std::unique_ptr<readonly_memory_session> session_;
  const embedded_memory_build_profile* build_profile_{};
  sonar::platform::windows::process_generation generation_;
  std::uintptr_t module_base_{};
  std::size_t module_size_{};
  std::uintptr_t player_address_{};
  std::uintptr_t replay_address_{};
  std::uintptr_t fish_address_{};
  std::uintptr_t fish_hash_address_{};
  bool terminal_transition_pending_{};
  std::uint64_t terminal_transition_sequence_{};
  std::uint64_t terminal_transition_captured_at_steady_ns_{};
  std::size_t player_right_offset_{};
  std::vector<std::uintptr_t> inventory_signature_hits_;
  inventory_binding_failure inventory_last_failure_{
      inventory_binding_failure::none};
  std::uint64_t inventory_retry_after_steady_ns_{};
};

[[nodiscard]] std::string_view to_string(capture_failure value) noexcept;
[[nodiscard]] std::string_view to_string(
    inventory_binding_failure value) noexcept;

}  // namespace sonar::fishing::memory_observation
