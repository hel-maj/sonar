#include "sonar/fishing/memory_observation/memory_observation.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cwctype>
#include <limits>
#include <optional>
#include <span>
#include <string>
#include <utility>
#include <vector>

namespace sonar::fishing::memory_observation {
namespace {

constexpr std::size_t kScanChunkBytes = 64U * 1024U;
constexpr std::size_t kMaximumScannedModuleBytes = 256U * 1024U * 1024U;
constexpr std::uintptr_t kMinimumUserPointer = 0x10000U;
constexpr std::uintptr_t kMaximumUserPointer = 0x00007FFF'FFFF'FFFFULL;
constexpr std::size_t kMaximumReplayEntities = 2048U;
constexpr std::size_t kFallbackReplayEntities = 512U;
constexpr std::size_t kFishIdentityProjectionOffset = 0x20U;
constexpr std::size_t kPlayerPositionOffset = 0x90U;
constexpr std::size_t kFishWorldPositionOffset = 0x90U;

[[nodiscard]] bool plausible_pointer(const std::uintptr_t value) noexcept {
  return value >= kMinimumUserPointer && value <= kMaximumUserPointer;
}

template <typename Value>
[[nodiscard]] std::optional<Value> read_value(
    readonly_memory_session& session,
    const std::uintptr_t address) noexcept {
  std::array<std::byte, sizeof(Value)> bytes{};
  if (!plausible_pointer(address) || !session.read_exact(address, bytes)) {
    return std::nullopt;
  }
  Value result{};
  std::memcpy(&result, bytes.data(), sizeof(result));
  return result;
}

[[nodiscard]] std::optional<vector3> read_vector3(
    readonly_memory_session& session,
    const std::uintptr_t address) noexcept {
  std::array<std::byte, sizeof(float) * 3U> bytes{};
  if (!plausible_pointer(address) || !session.read_exact(address, bytes)) {
    return std::nullopt;
  }
  std::array<float, 3U> values{};
  std::memcpy(values.data(), bytes.data(), bytes.size());
  if (!std::ranges::all_of(values, [](const float item) {
        return std::isfinite(item);
      })) {
    return std::nullopt;
  }
  return vector3{values[0], values[1], values[2]};
}

[[nodiscard]] bool matches_at(
    const std::span<const std::byte> bytes,
    const std::size_t offset,
    const relative_pointer_pattern& pattern) noexcept {
  if (pattern.bytes.empty() || offset > bytes.size() ||
      pattern.bytes.size() > bytes.size() - offset) {
    return false;
  }
  for (std::size_t index = 0U; index < pattern.bytes.size(); ++index) {
    const auto expected = pattern.bytes[index];
    if (expected >= 0 &&
        static_cast<std::uint8_t>(bytes[offset + index]) !=
            static_cast<std::uint8_t>(expected)) {
      return false;
    }
  }
  return true;
}

[[nodiscard]] std::optional<std::uintptr_t> find_pattern(
    readonly_memory_session& session,
    const std::uintptr_t base,
    const std::size_t size,
    const relative_pointer_pattern& pattern) {
  if (!plausible_pointer(base) || size == 0U ||
      size > kMaximumScannedModuleBytes || pattern.bytes.empty() ||
      pattern.bytes.size() > kScanChunkBytes ||
      pattern.displacement_offset > pattern.bytes.size() ||
      sizeof(std::int32_t) >
          pattern.bytes.size() - pattern.displacement_offset) {
    return std::nullopt;
  }
  std::vector<std::byte> overlap;
  std::vector<std::byte> chunk;
  std::size_t consumed = 0U;
  while (consumed < size) {
    const auto count = (std::min)(kScanChunkBytes, size - consumed);
    chunk.resize(count);
    if (!session.read_exact(base + consumed, chunk)) {
      overlap.clear();
      consumed += count;
      continue;
    }
    std::vector<std::byte> combined;
    combined.reserve(overlap.size() + chunk.size());
    combined.insert(combined.end(), overlap.begin(), overlap.end());
    combined.insert(combined.end(), chunk.begin(), chunk.end());
    for (std::size_t offset = 0U;
         offset + pattern.bytes.size() <= combined.size();
         ++offset) {
      if (matches_at(combined, offset, pattern)) {
        return base + consumed - overlap.size() + offset;
      }
    }
    const auto retained = (std::min)(
        pattern.bytes.size() - 1U, combined.size());
    overlap.assign(combined.end() - static_cast<std::ptrdiff_t>(retained),
                   combined.end());
    consumed += count;
  }
  return std::nullopt;
}

[[nodiscard]] std::optional<std::uintptr_t> relative_pointer(
    readonly_memory_session& session,
    const std::uintptr_t hit,
    const relative_pointer_pattern& pattern) noexcept {
  const auto relative = read_value<std::int32_t>(
      session, hit + pattern.displacement_offset);
  if (!relative.has_value()) {
    return std::nullopt;
  }
  const auto instruction_end = hit + pattern.instruction_length;
  const auto signed_end = static_cast<std::int64_t>(instruction_end);
  const auto signed_target = signed_end + static_cast<std::int64_t>(*relative);
  if (signed_target <= 0 ||
      static_cast<std::uint64_t>(signed_target) > kMaximumUserPointer) {
    return std::nullopt;
  }
  return read_value<std::uintptr_t>(
      session, static_cast<std::uintptr_t>(signed_target));
}

[[nodiscard]] bool module_contains(
    const std::uintptr_t module_base,
    const std::size_t module_size,
    const std::uintptr_t address) noexcept {
  return address >= module_base &&
      address - module_base < module_size;
}

[[nodiscard]] std::optional<std::size_t> player_right_offset(
    readonly_memory_session& session,
    const std::uintptr_t player,
    const embedded_memory_build_profile& profile) noexcept {
  for (const auto matrix_offset : profile.player_matrix_offsets) {
    std::array<std::byte, sizeof(float) * 16U> bytes{};
    if (!session.read_exact(player + matrix_offset, bytes)) {
      continue;
    }
    std::array<float, 16U> values{};
    std::memcpy(values.data(), bytes.data(), bytes.size());
    for (std::size_t row = 0U; row < 3U; ++row) {
      const auto x = values[row * 4U];
      const auto y = values[row * 4U + 1U];
      const auto z = values[row * 4U + 2U];
      const auto length = std::hypot(x, y);
      if (std::isfinite(x) && std::isfinite(y) && std::isfinite(z) &&
          length > 0.45F && length < 1.55F &&
          std::abs(x) <= 1.2F && std::abs(y) <= 1.2F) {
        return matrix_offset + row * sizeof(float) * 4U;
      }
    }
  }
  return std::nullopt;
}

[[nodiscard]] bool valid_player(
    readonly_memory_session& session,
    const std::uintptr_t player,
    const std::uintptr_t module_base,
    const std::size_t module_size,
    const embedded_memory_build_profile& profile,
    std::size_t& right_offset) noexcept {
  const auto vtable = read_value<std::uintptr_t>(session, player);
  const auto position = read_vector3(
      session, player + kPlayerPositionOffset);
  const auto right = player_right_offset(session, player, profile);
  if (!vtable.has_value() ||
      !module_contains(module_base, module_size, *vtable) ||
      !position.has_value() || !right.has_value()) {
    return false;
  }
  right_offset = *right;
  return true;
}

[[nodiscard]] std::optional<std::uintptr_t> resolve_player(
    readonly_memory_session& session,
    const std::uintptr_t module_base,
    const std::size_t module_size,
    const embedded_memory_build_profile& profile,
    std::size_t& right_offset) {
  for (const auto& pattern : profile.world_patterns) {
    const auto hit = find_pattern(
        session, module_base, module_size, pattern);
    if (!hit.has_value()) {
      continue;
    }
    auto value = relative_pointer(session, *hit, pattern);
    for (const auto offset : pattern.dereference_offsets) {
      if (!value.has_value() || !plausible_pointer(*value)) {
        value.reset();
        break;
      }
      value = read_value<std::uintptr_t>(session, *value + offset);
    }
    if (value.has_value() && valid_player(
            session,
            *value,
            module_base,
            module_size,
            profile,
            right_offset)) {
      return value;
    }
  }
  return std::nullopt;
}

[[nodiscard]] std::optional<std::uintptr_t> resolve_replay(
    readonly_memory_session& session,
    const std::uintptr_t module_base,
    const std::size_t module_size,
    const embedded_memory_build_profile& profile) {
  const auto hit = find_pattern(
      session, module_base, module_size, profile.replay_pattern);
  if (!hit.has_value()) {
    return std::nullopt;
  }
  const auto value = relative_pointer(session, *hit, profile.replay_pattern);
  return value.has_value() && plausible_pointer(*value)
      ? value
      : std::nullopt;
}

struct fish_identity final {
  std::uintptr_t entity{};
  std::uintptr_t hash_address{};
};

[[nodiscard]] std::optional<std::uintptr_t> exact_fish_hash_address(
    readonly_memory_session& session,
    const std::uintptr_t entity,
    const std::uint32_t expected_hash) noexcept {
  constexpr std::array archetype_offsets{0x20U, 0x18U, 0x28U, 0x10U};
  constexpr std::array hash_offsets{0x18U, 0x20U, 0x24U, 0x10U, 0x08U};
  for (const auto archetype_offset : archetype_offsets) {
    const auto archetype = read_value<std::uintptr_t>(
        session, entity + archetype_offset);
    if (!archetype.has_value() || !plausible_pointer(*archetype)) {
      continue;
    }
    for (const auto hash_offset : hash_offsets) {
      const auto address = *archetype + hash_offset;
      const auto value = read_value<std::uint32_t>(session, address);
      if (value.has_value() && *value == expected_hash) {
        return address;
      }
    }
  }
  for (const auto offset : std::array{0x20U, 0x18U, 0x10U}) {
    const auto address = entity + offset;
    const auto value = read_value<std::uint32_t>(session, address);
    if (value.has_value() && *value == expected_hash) {
      return address;
    }
  }
  return std::nullopt;
}

[[nodiscard]] std::optional<bool> exact_fish_active_state(
    readonly_memory_session& session,
    const fish_identity& fish,
    const embedded_memory_build_profile& profile) noexcept {
  const auto hash = read_value<std::uint32_t>(session, fish.hash_address);
  const auto active = read_value<std::uint8_t>(
      session, fish.entity + profile.fish_active_offset);
  if (!hash.has_value() || *hash != profile.fish_model_hash ||
      !active.has_value() || *active > 1U) {
    return std::nullopt;
  }
  return *active == 1U;
}

[[nodiscard]] std::optional<double> fish_distance_squared(
    readonly_memory_session& session,
    const std::uintptr_t player,
    const std::uintptr_t fish) noexcept {
  const auto player_position = read_vector3(
      session, player + kPlayerPositionOffset);
  const auto fish_position = read_vector3(
      session, fish + kFishWorldPositionOffset);
  if (!player_position.has_value() || !fish_position.has_value()) {
    return std::nullopt;
  }
  const auto dx = fish_position->x - player_position->x;
  const auto dy = fish_position->y - player_position->y;
  const auto dz = fish_position->z - player_position->z;
  const auto distance = dx * dx + dy * dy + dz * dz;
  return std::isfinite(distance) && distance > 1.0 && distance < 120.0 * 120.0
      ? std::optional<double>(distance)
      : std::nullopt;
}

[[nodiscard]] std::optional<fish_identity> resolve_fish(
    readonly_memory_session& session,
    const std::uintptr_t replay,
    const std::uintptr_t player,
    const embedded_memory_build_profile& profile) noexcept {
  constexpr std::array interface_offsets{0x08U, 0x20U, 0x18U, 0x10U, 0x28U};
  struct list_layout final {
    std::size_t list_offset;
    std::size_t count_offset;
  };
  constexpr std::array layouts{
      list_layout{0x00U, 0x18U},
      list_layout{0x08U, 0x18U},
      list_layout{0x30U, 0x38U},
      list_layout{0x100U, 0x108U},
      list_layout{0x108U, 0x110U},
      list_layout{0x110U, 0x118U},
  };
  std::optional<fish_identity> best;
  double best_distance = (std::numeric_limits<double>::max)();
  for (const auto interface_offset : interface_offsets) {
    const auto interface_value = read_value<std::uintptr_t>(
        session, replay + interface_offset);
    if (!interface_value.has_value() ||
        !plausible_pointer(*interface_value)) {
      continue;
    }
    for (const auto layout : layouts) {
      const auto list = read_value<std::uintptr_t>(
          session, *interface_value + layout.list_offset);
      if (!list.has_value() || !plausible_pointer(*list) ||
          (*list % alignof(std::uintptr_t)) != 0U) {
        continue;
      }
      const auto observed_count = read_value<std::int32_t>(
          session, *interface_value + layout.count_offset);
      const auto count = observed_count.has_value() && *observed_count > 0 &&
              *observed_count <= static_cast<std::int32_t>(kMaximumReplayEntities)
          ? static_cast<std::size_t>(*observed_count)
          : kFallbackReplayEntities;
      for (std::size_t index = 0U; index < count; ++index) {
        const auto entity = read_value<std::uintptr_t>(
            session, *list + index * 0x10U);
        if (!entity.has_value() || !plausible_pointer(*entity) ||
            *entity == player) {
          continue;
        }
        const auto hash_address = exact_fish_hash_address(
            session, *entity, profile.fish_model_hash);
        if (!hash_address.has_value()) {
          continue;
        }
        const fish_identity candidate{*entity, *hash_address};
        if (exact_fish_active_state(session, candidate, profile) != true) {
          continue;
        }
        const auto distance = fish_distance_squared(session, player, *entity);
        if (distance.has_value() && *distance < best_distance) {
          best = candidate;
          best_distance = *distance;
        }
      }
      if (best.has_value()) {
        return best;
      }
    }
  }
  return best;
}

[[nodiscard]] const sonar::platform::windows::module_snapshot* game_module(
    const process_identity& identity) noexcept {
  const auto same_name = [](const std::wstring& left,
                            const std::wstring_view right) {
    return left.size() == right.size() &&
        std::equal(
            left.begin(), left.end(), right.begin(),
            [](const wchar_t a, const wchar_t b) {
              return std::towlower(a) == std::towlower(b);
            });
  };
  const auto found = std::ranges::find_if(
      identity.modules,
      [&](const auto& module) { return same_name(module.name, L"GTA5.exe"); });
  return found == identity.modules.end() ? nullptr : &*found;
}

[[nodiscard]] resolved_memory_capture fail(std::string reason) {
  return {
      .registry_sha256 = std::string(embedded_build_profile_registry_sha256),
      .reason = std::move(reason),
  };
}

}  // namespace

bool resolved_memory_capture::ready() const noexcept {
  return profile.has_value() && plan.has_value() && reason.empty() &&
      registry_sha256 == embedded_build_profile_registry_sha256;
}

memory_capture_plan_resolver::memory_capture_plan_resolver(
    memory_connector& connector) noexcept
    : memory_capture_plan_resolver(
          connector, embedded_memory_build_profiles()) {}

memory_capture_plan_resolver::memory_capture_plan_resolver(
    memory_connector& connector,
    const std::span<const embedded_memory_build_profile> profiles) noexcept
    : connector_(connector), profiles_(profiles) {}

void memory_capture_plan_resolver::reset() noexcept {
  session_.reset();
  build_profile_ = nullptr;
  generation_ = {};
  module_base_ = 0U;
  module_size_ = 0U;
  player_address_ = 0U;
  replay_address_ = 0U;
  fish_address_ = 0U;
  fish_hash_address_ = 0U;
  terminal_transition_pending_ = false;
  terminal_transition_sequence_ = 0U;
  terminal_transition_captured_at_steady_ns_ = 0U;
  player_right_offset_ = 0U;
  inventory_signature_hits_.clear();
  inventory_last_failure_ = inventory_binding_failure::none;
  inventory_retry_after_steady_ns_ = 0U;
}

void memory_capture_plan_resolver::commit_capture(
    const coherent_memory_snapshot& snapshot) noexcept {
  if (!terminal_transition_pending_ || !snapshot.reeling.has_value() ||
      snapshot.reeling->active || !snapshot.reeling->fish_model_confirmed ||
      snapshot.sequence != terminal_transition_sequence_ ||
      snapshot.captured_at_steady_ns !=
          terminal_transition_captured_at_steady_ns_ ||
      snapshot.game_generation != generation_ || build_profile_ == nullptr ||
      snapshot.profile_id != build_profile_->profile_id ||
      snapshot.profile_revision != build_profile_->profile_revision) {
    return;
  }
  fish_address_ = 0U;
  fish_hash_address_ = 0U;
  terminal_transition_pending_ = false;
  terminal_transition_sequence_ = 0U;
  terminal_transition_captured_at_steady_ns_ = 0U;
}

void memory_capture_plan_resolver::prepare_capture_retry() noexcept {
  if (!terminal_transition_pending_) {
    reset();
  }
}

bool memory_capture_plan_resolver::terminal_transition_pending()
    const noexcept {
  return terminal_transition_pending_;
}

std::string memory_capture_plan_resolver::prepare_session(
    const sonar::platform::windows::process_generation& game_generation)
    noexcept {
  if (session_ != nullptr && generation_ != game_generation) {
    reset();
  }
  if (session_ == nullptr) {
    std::string connector_reason;
    session_ = connector_.connect(
        process_role::game, game_generation.process_id, connector_reason);
    if (!session_) {
      return connector_reason.empty()
          ? "memory_process_unavailable"
          : connector_reason;
    }
    if (session_->identity().generation != game_generation) {
      reset();
      return "memory_process_generation_mismatch";
    }
    const auto selection = select_memory_build_profile(
        profiles_,
        session_->identity().image_name,
        session_->identity().image_sha256);
    if (!selection.ready()) {
      reset();
      return selection.reason.empty()
          ? "memory_game_build_unsupported"
          : selection.reason;
    }
    build_profile_ = selection.profile;
    generation_ = game_generation;
    const auto* module = game_module(session_->identity());
    if (module == nullptr || module->base_address == 0U ||
        module->size == 0U || module->size > kMaximumScannedModuleBytes ||
        module->size > (std::numeric_limits<std::size_t>::max)()) {
      reset();
      return "memory_game_module_unavailable";
    }
    module_base_ = module->base_address;
    module_size_ = static_cast<std::size_t>(module->size);
  }
  if (!session_->generation_current()) {
    reset();
    return "memory_process_generation_changed";
  }
  return {};
}

resolved_memory_capture memory_capture_plan_resolver::resolve_reeling(
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns,
    const sonar::platform::windows::process_generation& game_generation)
    noexcept {
  try {
    if (sequence == 0U || captured_at_steady_ns == 0U ||
        game_generation.process_id == 0U ||
        game_generation.creation_time_filetime_100ns == 0U) {
      return fail("memory_capture_identity_invalid");
    }
    if (auto reason = prepare_session(game_generation); !reason.empty()) {
      return fail(std::move(reason));
    }
    if (player_address_ == 0U || replay_address_ == 0U) {
      std::size_t right_offset{};
      const auto player = resolve_player(
          *session_, module_base_, module_size_, *build_profile_, right_offset);
      const auto replay = resolve_replay(
          *session_, module_base_, module_size_, *build_profile_);
      if (!player.has_value() || !replay.has_value()) {
        return fail("memory_profile_anchor_unresolved");
      }
      player_address_ = *player;
      replay_address_ = *replay;
      player_right_offset_ = right_offset;
    }
    bool observed_inactive_cached_fish = false;
    const fish_identity current{fish_address_, fish_hash_address_};
    const auto current_active = fish_address_ != 0U && fish_hash_address_ != 0U
        ? exact_fish_active_state(*session_, current, *build_profile_)
        : std::nullopt;
    const bool current_ready = current_active.has_value() &&
        (!*current_active ||
         fish_distance_squared(*session_, player_address_, fish_address_)
             .has_value());
    if (!current_ready) {
      fish_address_ = 0U;
      fish_hash_address_ = 0U;
      terminal_transition_pending_ = false;
      terminal_transition_sequence_ = 0U;
      terminal_transition_captured_at_steady_ns_ = 0U;
      const auto fish = resolve_fish(
          *session_, replay_address_, player_address_, *build_profile_);
      if (!fish.has_value()) {
        return fail("memory_active_fish_unavailable");
      }
      fish_address_ = fish->entity;
      fish_hash_address_ = fish->hash_address;
    } else {
      // This is the exact legacy fish_caught transition: a previously
      // confirmed fish whose byte at +0x189 changed from 1 to 0. Publish that
      // one fresh inactive sample. Keep the exact anchor pending until the
      // adapter commits a successful coherent capture; this permits one
      // bounded retry without replaying a last-known snapshot.
      observed_inactive_cached_fish = !*current_active;
      if (observed_inactive_cached_fish) {
        terminal_transition_pending_ = true;
        terminal_transition_sequence_ = sequence;
        terminal_transition_captured_at_steady_ns_ = captured_at_steady_ns;
      }
    }
    if (!session_->generation_current()) {
      reset();
      return fail("memory_process_generation_changed");
    }
    const auto player_size = (std::max)(
        kPlayerPositionOffset + sizeof(float) * 3U,
        player_right_offset_ + sizeof(float) * 2U);
    const auto fish_size = (std::max)({
        kFishWorldPositionOffset + sizeof(float) * 3U,
        build_profile_->fish_active_offset + sizeof(std::uint8_t),
        kFishIdentityProjectionOffset + sizeof(std::uint32_t),
    });
    memory_observation_profile profile{
        .profile_id = build_profile_->profile_id,
        .profile_revision = build_profile_->profile_revision,
        .game = build_profile_->game,
        .webengine = {.required = false},
        .reeling = {
            .player_position_offset = kPlayerPositionOffset,
            .player_right_offset = player_right_offset_,
            .fish_position_offset = kFishWorldPositionOffset,
            .fish_model_hash_offset = kFishIdentityProjectionOffset,
            .fish_active_offset = build_profile_->fish_active_offset,
            .expected_fish_model_hash = build_profile_->fish_model_hash,
            .maximum_distance = 120.0,
        },
        .inventory_candidates = {},
        .status_candidates = {},
        .minimum_inventory_votes = 0U,
        .minimum_inventory_confidence = 0.85,
        .require_reeling = true,
        .require_inventory = false,
        .require_player_status = false,
        .require_chat = false,
    };
    capture_plan plan{
        .sequence = sequence,
        .captured_at_steady_ns = captured_at_steady_ns,
        .game_process_id = game_generation.process_id,
        .expected_game_generation = game_generation,
        .regions = {
            {evidence_region_kind::reeling_player,
             process_role::game, 0U, player_address_, player_size},
            {evidence_region_kind::reeling_fish,
             process_role::game, 0U, fish_address_, fish_size},
            {evidence_region_kind::reeling_fish_identity,
             process_role::game, 0U, fish_hash_address_,
             sizeof(std::uint32_t)},
        },
    };
    return {
        .profile = std::move(profile),
        .plan = std::move(plan),
        .registry_sha256 = std::string(embedded_build_profile_registry_sha256),
    };
  } catch (...) {
    reset();
    return fail("memory_profile_resolution_failed");
  }
}

resolved_memory_capture
memory_capture_plan_resolver::resolve_runtime_observation(
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns,
    const sonar::platform::windows::process_generation& game_generation,
    const bool reeling_stage_visible) noexcept {
  try {
    if (reeling_stage_visible) {
      return resolve_reeling(
          sequence, captured_at_steady_ns, game_generation);
    }
    auto inventory = resolve_inventory(
        sequence, captured_at_steady_ns, game_generation);

    if (!inventory.ready()) {
      return fail(inventory.reason.empty()
          ? std::string("memory_runtime_observation_unavailable")
          : std::move(inventory.reason));
    }
    return {
        .profile = std::move(inventory.profile),
        .plan = std::move(inventory.plan),
        .registry_sha256 = std::move(inventory.registry_sha256),
    };
  } catch (...) {
    reset();
    return fail("memory_runtime_observation_resolution_failed");
  }
}

}  // namespace sonar::fishing::memory_observation
