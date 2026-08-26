#include "candidate_reeling_validator.h"
#include "executable_module_reader.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cwctype>
#include <limits>
#include <map>
#include <optional>
#include <set>
#include <span>
#include <string>
#include <utility>
#include <vector>

namespace sonar::fishing::build_profile_compatibility_probe {
namespace {

namespace memory = sonar::fishing::memory_observation;
namespace memory_detail = sonar::fishing::memory_observation::detail;

constexpr std::size_t kMaximumPatternHits = 4096U;
constexpr std::size_t kMaximumPatternBytes = 64U * 1024U;
constexpr std::size_t kMaximumReplayEntities = 2048U;
constexpr std::uintptr_t kMinimumUserPointer = 0x10000U;
constexpr std::uintptr_t kMaximumUserPointer = 0x00007FFF'FFFF'FFFFULL;
constexpr std::size_t kFishIdentityProjectionOffset = 0x20U;
constexpr std::size_t kPlayerPositionOffset = 0x90U;
constexpr std::size_t kFishWorldPositionOffset = 0x90U;

[[nodiscard]] bool plausible_pointer(const std::uintptr_t value) noexcept {
  return value >= kMinimumUserPointer && value <= kMaximumUserPointer;
}

[[nodiscard]] std::optional<std::uintptr_t> checked_add(
    const std::uintptr_t base,
    const std::size_t offset) noexcept {
  if (offset > (std::numeric_limits<std::uintptr_t>::max)() - base) {
    return std::nullopt;
  }
  const auto value = base + offset;
  return plausible_pointer(value) ? std::optional<std::uintptr_t>(value)
                                  : std::nullopt;
}

[[nodiscard]] bool valid_sha256(const std::string_view value) noexcept {
  return value.size() == 64U &&
      std::ranges::all_of(value, [](const char character) {
        return (character >= '0' && character <= '9') ||
            (character >= 'a' && character <= 'f') ||
            (character >= 'A' && character <= 'F');
      });
}

[[nodiscard]] char lower_hex(const char value) noexcept {
  return value >= 'A' && value <= 'F'
      ? static_cast<char>(value - 'A' + 'a')
      : value;
}

[[nodiscard]] bool same_sha256(
    const std::string_view left,
    const std::string_view right) noexcept {
  return valid_sha256(left) && valid_sha256(right) &&
      std::equal(
          left.begin(), left.end(), right.begin(),
          [](const char a, const char b) {
            return lower_hex(a) == lower_hex(b);
          });
}

[[nodiscard]] bool same_image_name(
    const std::wstring_view left,
    const std::wstring_view right) noexcept {
  return left.size() == right.size() &&
      std::equal(
          left.begin(), left.end(), right.begin(),
          [](const wchar_t a, const wchar_t b) {
            return std::towlower(a) == std::towlower(b);
          });
}

[[nodiscard]] bool same_pattern(
    const memory::relative_pointer_pattern& left,
    const memory::relative_pointer_pattern& right) noexcept {
  return left.bytes == right.bytes &&
      left.displacement_offset == right.displacement_offset &&
      left.instruction_length == right.instruction_length &&
      left.dereference_offsets == right.dereference_offsets;
}

[[nodiscard]] bool same_embedded_profile(
    const memory::embedded_memory_build_profile& left,
    const memory::embedded_memory_build_profile& right) noexcept {
  return left.schema_version == right.schema_version &&
      left.profile_id == right.profile_id &&
      left.profile_revision == right.profile_revision &&
      same_image_name(left.game.image_name, right.game.image_name) &&
      same_sha256(left.game.image_sha256, right.game.image_sha256) &&
      left.game.required == right.game.required &&
      left.player_matrix_offsets == right.player_matrix_offsets &&
      left.fish_position_offsets == right.fish_position_offsets &&
      left.fish_model_hash == right.fish_model_hash &&
      left.fish_active_offset == right.fish_active_offset &&
      left.world_patterns.size() == right.world_patterns.size() &&
      std::equal(
          left.world_patterns.begin(),
          left.world_patterns.end(),
          right.world_patterns.begin(),
          same_pattern) &&
      same_pattern(left.replay_pattern, right.replay_pattern);
}

[[nodiscard]] bool exact_frozen_baseline(
    const memory::embedded_memory_build_profile& baseline) noexcept {
  const auto profiles = memory::embedded_memory_build_profiles();
  return std::ranges::any_of(profiles, [&](const auto& embedded) {
    return same_embedded_profile(baseline, embedded);
  });
}

enum class read_status : std::uint8_t {
  ready = 0,
  invalid_address,
  unavailable,
};

template <typename Value>
struct value_read final {
  read_status status{read_status::invalid_address};
  Value value{};
};

template <typename Value>
[[nodiscard]] value_read<Value> read_value(
    memory::readonly_memory_session& session,
    const std::uintptr_t address) noexcept {
  if (!plausible_pointer(address)) {
    return {};
  }
  std::array<std::byte, sizeof(Value)> bytes{};
  if (!session.read_exact(address, bytes)) {
    return {.status = read_status::unavailable};
  }
  Value value{};
  std::memcpy(&value, bytes.data(), sizeof(value));
  return {.status = read_status::ready, .value = value};
}

[[nodiscard]] bool module_contains(
    const std::uintptr_t module_base,
    const std::size_t module_size,
    const std::uintptr_t address,
    const std::size_t size = 1U) noexcept {
  return size > 0U && address >= module_base &&
      address - module_base < module_size &&
      size <= module_size - static_cast<std::size_t>(address - module_base);
}

[[nodiscard]] const sonar::platform::windows::module_snapshot* exact_game_module(
    const memory::process_identity& identity) noexcept {
  const sonar::platform::windows::module_snapshot* selected = nullptr;
  for (const auto& module : identity.modules) {
    if (!same_image_name(module.name, L"GTA5.exe")) {
      continue;
    }
    if (selected != nullptr) {
      return nullptr;
    }
    selected = &module;
  }
  return selected;
}

using module_image = memory_detail::executable_module_image;

[[nodiscard]] bool valid_pattern(
    const memory::relative_pointer_pattern& pattern) noexcept {
  return !pattern.bytes.empty() &&
      pattern.bytes.size() <= kMaximumPatternBytes &&
      pattern.displacement_offset <= pattern.bytes.size() &&
      sizeof(std::int32_t) <=
          pattern.bytes.size() - pattern.displacement_offset &&
      pattern.instruction_length >=
          pattern.displacement_offset + sizeof(std::int32_t);
}

[[nodiscard]] bool matches_at(
    const std::span<const std::byte> bytes,
    const std::size_t offset,
    const memory::relative_pointer_pattern& pattern) noexcept {
  if (offset > bytes.size() || pattern.bytes.size() > bytes.size() - offset) {
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

struct pattern_hits final {
  bool valid{};
  bool over_budget{};
  std::vector<std::uintptr_t> addresses;
};

[[nodiscard]] pattern_hits enumerate_pattern_hits(
    const module_image& module,
    const memory::relative_pointer_pattern& pattern) {
  if (!valid_pattern(pattern)) {
    return {};
  }
  pattern_hits result{.valid = true};
  for (const auto& section : module.executable_sections) {
    for (std::size_t offset = 0U;
         offset + pattern.bytes.size() <= section.bytes.size();
         ++offset) {
      if (!matches_at(section.bytes, offset, pattern)) {
        continue;
      }
      const auto address = checked_add(section.address, offset);
      if (!address.has_value()) {
        return {};
      }
      if (result.addresses.size() < kMaximumPatternHits) {
        result.addresses.push_back(*address);
      } else {
        result.over_budget = true;
      }
    }
  }
  return result;
}

[[nodiscard]] std::optional<std::span<const std::byte>> module_bytes_at(
    const module_image& module,
    const std::uintptr_t address,
    const std::size_t size) noexcept {
  for (const auto& section : module.executable_sections) {
    if (address < section.address) {
      continue;
    }
    const auto offset = address - section.address;
    if (offset <= section.bytes.size() &&
        size <= section.bytes.size() - static_cast<std::size_t>(offset)) {
      return std::span(section.bytes).subspan(
          static_cast<std::size_t>(offset), size);
    }
  }
  return std::nullopt;
}

enum class endpoint_status : std::uint8_t {
  invalid = 0,
  ready,
  incomplete,
};

struct pointer_endpoint final {
  endpoint_status status{endpoint_status::invalid};
  std::uintptr_t value{};
};

[[nodiscard]] pointer_endpoint resolve_pattern_endpoint(
    memory::readonly_memory_session& session,
    const module_image& module,
    const std::uintptr_t hit_address,
    const memory::relative_pointer_pattern& pattern) noexcept {
  const auto bytes = module_bytes_at(
      module, hit_address, pattern.bytes.size());
  if (!bytes.has_value()) {
    return {};
  }
  std::int32_t displacement{};
  std::memcpy(
      &displacement,
      bytes->data() + pattern.displacement_offset,
      sizeof(displacement));
  if (!module_contains(
          module.base, module.size, hit_address,
          pattern.instruction_length)) {
    return {};
  }
  const auto instruction_end = checked_add(
      hit_address, pattern.instruction_length);
  if (!instruction_end.has_value() ||
      *instruction_end >
          static_cast<std::uintptr_t>((std::numeric_limits<std::int64_t>::max)())) {
    return {};
  }
  const auto signed_target = static_cast<std::int64_t>(*instruction_end) +
      static_cast<std::int64_t>(displacement);
  if (signed_target <= 0 ||
      static_cast<std::uint64_t>(signed_target) > kMaximumUserPointer) {
    return {};
  }
  const auto pointer_slot = static_cast<std::uintptr_t>(signed_target);
  if (!module_contains(
          module.base, module.size, pointer_slot,
          sizeof(std::uintptr_t))) {
    return {};
  }
  auto value = read_value<std::uintptr_t>(session, pointer_slot);
  if (value.status == read_status::unavailable) {
    return {.status = endpoint_status::incomplete};
  }
  if (value.status != read_status::ready || !plausible_pointer(value.value)) {
    return {};
  }
  for (const auto offset : pattern.dereference_offsets) {
    const auto address = checked_add(value.value, offset);
    if (!address.has_value()) {
      return {};
    }
    value = read_value<std::uintptr_t>(session, *address);
    if (value.status == read_status::unavailable) {
      return {.status = endpoint_status::incomplete};
    }
    if (value.status != read_status::ready || !plausible_pointer(value.value)) {
      return {};
    }
  }
  return {.status = endpoint_status::ready, .value = value.value};
}

struct vector3 final {
  double x{};
  double y{};
  double z{};
};

[[nodiscard]] std::optional<vector3> read_vector3(
    memory::readonly_memory_session& session,
    const std::uintptr_t address,
    bool& unavailable) noexcept {
  std::array<std::byte, sizeof(float) * 3U> bytes{};
  if (!plausible_pointer(address) || !session.read_exact(address, bytes)) {
    unavailable = true;
    return std::nullopt;
  }
  std::array<float, 3U> values{};
  std::memcpy(values.data(), bytes.data(), bytes.size());
  if (!std::ranges::all_of(values, [](const float value) {
        return std::isfinite(value);
      })) {
    return std::nullopt;
  }
  return vector3{values[0], values[1], values[2]};
}

struct player_endpoint final {
  endpoint_status status{endpoint_status::invalid};
  std::size_t right_offset{};
};

[[nodiscard]] player_endpoint validate_player_endpoint(
    memory::readonly_memory_session& session,
    const std::uintptr_t player,
    const module_image& module,
    const memory::embedded_memory_build_profile& profile) noexcept {
  const auto vtable = read_value<std::uintptr_t>(session, player);
  if (vtable.status == read_status::unavailable) {
    return {.status = endpoint_status::incomplete};
  }
  if (vtable.status != read_status::ready ||
      !module_contains(module.base, module.size, vtable.value)) {
    return {};
  }
  bool position_unavailable = false;
  const auto position_address = checked_add(player, kPlayerPositionOffset);
  if (!position_address.has_value()) {
    return {};
  }
  const auto position = read_vector3(
      session, *position_address, position_unavailable);
  if (position_unavailable) {
    return {.status = endpoint_status::incomplete};
  }
  if (!position.has_value()) {
    return {};
  }

  bool matrix_unavailable = false;
  for (const auto matrix_offset : profile.player_matrix_offsets) {
    const auto matrix_address = checked_add(player, matrix_offset);
    if (!matrix_address.has_value()) {
      continue;
    }
    std::array<std::byte, sizeof(float) * 16U> bytes{};
    if (!session.read_exact(*matrix_address, bytes)) {
      matrix_unavailable = true;
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
        return {
            .status = endpoint_status::ready,
            .right_offset = matrix_offset + row * sizeof(float) * 4U,
        };
      }
    }
  }
  return matrix_unavailable
      ? player_endpoint{.status = endpoint_status::incomplete}
      : player_endpoint{};
}

struct player_resolution final {
  readiness_reason reason{readiness_reason::world_endpoint_unresolved};
  std::uintptr_t address{};
  std::size_t right_offset{};
};

[[nodiscard]] player_resolution resolve_unique_player(
    memory::readonly_memory_session& session,
    const module_image& module,
    const memory::embedded_memory_build_profile& profile) {
  std::map<std::uintptr_t, std::size_t> players;
  bool observed_hit = false;
  bool incomplete = false;
  bool conflicting_projection = false;
  for (const auto& pattern : profile.world_patterns) {
    const auto hits = enumerate_pattern_hits(module, pattern);
    if (!hits.valid) {
      return {.reason = readiness_reason::world_endpoint_unresolved};
    }
    if (hits.over_budget) {
      return {.reason = readiness_reason::world_endpoint_ambiguous};
    }
    observed_hit = observed_hit || !hits.addresses.empty();
    for (const auto hit : hits.addresses) {
      const auto endpoint = resolve_pattern_endpoint(
          session, module, hit, pattern);
      if (endpoint.status == endpoint_status::incomplete) {
        incomplete = true;
        continue;
      }
      if (endpoint.status != endpoint_status::ready) {
        continue;
      }
      const auto player = validate_player_endpoint(
          session, endpoint.value, module, profile);
      if (player.status == endpoint_status::incomplete) {
        incomplete = true;
      } else if (player.status == endpoint_status::ready) {
        const auto [found, inserted] = players.emplace(
            endpoint.value, player.right_offset);
        if (!inserted && found->second != player.right_offset) {
          conflicting_projection = true;
        }
      }
    }
  }
  if (incomplete) {
    return {.reason = readiness_reason::world_endpoint_incomplete};
  }
  if (conflicting_projection || players.size() > 1U) {
    return {.reason = readiness_reason::world_endpoint_ambiguous};
  }
  if (!observed_hit || players.empty()) {
    return {.reason = readiness_reason::world_endpoint_unresolved};
  }
  return {
      .reason = readiness_reason::ready,
      .address = players.begin()->first,
      .right_offset = players.begin()->second,
  };
}

struct replay_resolution final {
  readiness_reason reason{readiness_reason::replay_endpoint_unresolved};
  std::uintptr_t address{};
};

[[nodiscard]] replay_resolution resolve_unique_replay(
    memory::readonly_memory_session& session,
    const module_image& module,
    const memory::embedded_memory_build_profile& profile) {
  const auto hits = enumerate_pattern_hits(module, profile.replay_pattern);
  if (!hits.valid || hits.addresses.empty()) {
    return {.reason = readiness_reason::replay_endpoint_unresolved};
  }
  if (hits.over_budget || hits.addresses.size() != 1U) {
    return {.reason = readiness_reason::replay_endpoint_ambiguous};
  }
  const auto endpoint = resolve_pattern_endpoint(
      session, module, hits.addresses.front(), profile.replay_pattern);
  if (endpoint.status == endpoint_status::incomplete) {
    return {.reason = readiness_reason::replay_endpoint_incomplete};
  }
  if (endpoint.status != endpoint_status::ready) {
    return {.reason = readiness_reason::replay_endpoint_unresolved};
  }
  return {.reason = readiness_reason::ready, .address = endpoint.value};
}

enum class fish_hash_status : std::uint8_t {
  unavailable = 0,
  ready,
  absent,
  ambiguous,
};

struct fish_hash_resolution final {
  fish_hash_status status{fish_hash_status::absent};
  std::uintptr_t address{};
};

[[nodiscard]] fish_hash_resolution exact_fish_hash_address(
    memory::readonly_memory_session& session,
    const std::uintptr_t entity,
    const std::uint32_t expected_hash) noexcept {
  constexpr std::array archetype_offsets{0x20U, 0x18U, 0x28U, 0x10U};
  constexpr std::array hash_offsets{0x18U, 0x20U, 0x24U, 0x10U, 0x08U};
  bool unavailable = false;
  std::set<std::uintptr_t> matches;
  for (const auto archetype_offset : archetype_offsets) {
    const auto archetype_address = checked_add(entity, archetype_offset);
    if (!archetype_address.has_value()) {
      continue;
    }
    const auto archetype = read_value<std::uintptr_t>(
        session, *archetype_address);
    if (archetype.status == read_status::unavailable) {
      unavailable = true;
      continue;
    }
    if (archetype.status != read_status::ready ||
        !plausible_pointer(archetype.value)) {
      continue;
    }
    for (const auto hash_offset : hash_offsets) {
      const auto address = checked_add(archetype.value, hash_offset);
      if (!address.has_value()) {
        continue;
      }
      const auto value = read_value<std::uint32_t>(session, *address);
      if (value.status == read_status::unavailable) {
        unavailable = true;
        continue;
      }
      if (value.status == read_status::ready && value.value == expected_hash) {
        matches.insert(*address);
      }
    }
  }
  for (const auto offset : std::array{0x20U, 0x18U, 0x10U}) {
    const auto address = checked_add(entity, offset);
    if (!address.has_value()) {
      continue;
    }
    const auto value = read_value<std::uint32_t>(session, *address);
    if (value.status == read_status::unavailable) {
      unavailable = true;
      continue;
    }
    if (value.status == read_status::ready && value.value == expected_hash) {
      matches.insert(*address);
    }
  }
  if (unavailable) {
    return {.status = fish_hash_status::unavailable};
  }
  if (matches.size() > 1U) {
    return {.status = fish_hash_status::ambiguous};
  }
  if (matches.empty()) {
    return {.status = fish_hash_status::absent};
  }
  return {
      .status = fish_hash_status::ready,
      .address = *matches.begin(),
  };
}

enum class distance_status : std::uint8_t {
  unavailable = 0,
  invalid,
  ready,
};

struct distance_resolution final {
  distance_status status{distance_status::invalid};
  double squared{};
};

[[nodiscard]] distance_resolution fish_distance_squared(
    memory::readonly_memory_session& session,
    const std::uintptr_t player,
    const std::uintptr_t fish) noexcept {
  bool unavailable = false;
  const auto player_position_address = checked_add(
      player, kPlayerPositionOffset);
  const auto fish_position_address = checked_add(
      fish, kFishWorldPositionOffset);
  if (!player_position_address.has_value() ||
      !fish_position_address.has_value()) {
    return {.status = distance_status::unavailable};
  }
  const auto player_position = read_vector3(
      session, *player_position_address, unavailable);
  const auto fish_position = read_vector3(
      session, *fish_position_address, unavailable);
  if (unavailable || !player_position.has_value() ||
      !fish_position.has_value()) {
    return {.status = unavailable
        ? distance_status::unavailable
        : distance_status::invalid};
  }
  const auto dx = fish_position->x - player_position->x;
  const auto dy = fish_position->y - player_position->y;
  const auto dz = fish_position->z - player_position->z;
  const auto squared = dx * dx + dy * dy + dz * dz;
  return std::isfinite(squared) && squared > 1.0 &&
          squared < 120.0 * 120.0
      ? distance_resolution{
            .status = distance_status::ready,
            .squared = squared,
        }
      : distance_resolution{.status = distance_status::invalid};
}

struct fish_resolution final {
  readiness_reason reason{readiness_reason::active_fish_unavailable};
  std::uintptr_t entity{};
  std::uintptr_t hash_address{};
};

[[nodiscard]] fish_resolution resolve_unique_active_fish(
    memory::readonly_memory_session& session,
    const std::uintptr_t replay,
    const std::uintptr_t player,
    const memory::embedded_memory_build_profile& profile) noexcept {
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

  bool valid_bounded_count = false;
  bool declared_list_incomplete = false;
  bool identity_ambiguous = false;
  bool active_geometry_invalid = false;
  std::map<std::uintptr_t, std::uintptr_t> active_candidates;
  for (const auto interface_offset : interface_offsets) {
    const auto interface_address = checked_add(replay, interface_offset);
    if (!interface_address.has_value()) {
      continue;
    }
    const auto interface_value = read_value<std::uintptr_t>(
        session, *interface_address);
    if (interface_value.status == read_status::unavailable) {
      declared_list_incomplete = true;
      continue;
    }
    if (interface_value.status != read_status::ready ||
        !plausible_pointer(interface_value.value)) {
      continue;
    }
    for (const auto layout : layouts) {
      const auto list_address = checked_add(
          interface_value.value, layout.list_offset);
      const auto count_address = checked_add(
          interface_value.value, layout.count_offset);
      if (!list_address.has_value() || !count_address.has_value()) {
        continue;
      }
      const auto list = read_value<std::uintptr_t>(
          session, *list_address);
      const auto count = read_value<std::int32_t>(
          session, *count_address);
      if (list.status == read_status::unavailable ||
          count.status == read_status::unavailable) {
        declared_list_incomplete = true;
        continue;
      }
      if (list.status != read_status::ready ||
          count.status != read_status::ready ||
          !plausible_pointer(list.value) ||
          (list.value % alignof(std::uintptr_t)) != 0U || count.value <= 0 ||
          count.value > static_cast<std::int32_t>(kMaximumReplayEntities)) {
        continue;
      }
      valid_bounded_count = true;
      for (std::size_t index = 0U;
           index < static_cast<std::size_t>(count.value);
           ++index) {
        const auto entity_slot = checked_add(list.value, index * 0x10U);
        if (!entity_slot.has_value()) {
          declared_list_incomplete = true;
          continue;
        }
        const auto entity = read_value<std::uintptr_t>(
            session, *entity_slot);
        if (entity.status == read_status::unavailable) {
          declared_list_incomplete = true;
          continue;
        }
        if (entity.status != read_status::ready ||
            !plausible_pointer(entity.value) || entity.value == player) {
          continue;
        }
        const auto hash_address = exact_fish_hash_address(
            session, entity.value, profile.fish_model_hash);
        if (hash_address.status == fish_hash_status::unavailable) {
          declared_list_incomplete = true;
          continue;
        }
        if (hash_address.status == fish_hash_status::ambiguous) {
          identity_ambiguous = true;
          continue;
        }
        if (hash_address.status != fish_hash_status::ready) {
          continue;
        }
        const auto active_address = checked_add(
            entity.value, profile.fish_active_offset);
        if (!active_address.has_value()) {
          declared_list_incomplete = true;
          continue;
        }
        const auto active = read_value<std::uint8_t>(
            session, *active_address);
        if (active.status == read_status::unavailable) {
          declared_list_incomplete = true;
          continue;
        }
        if (active.status != read_status::ready || active.value != 1U) {
          continue;
        }
        const auto [found, inserted] = active_candidates.emplace(
            entity.value, hash_address.address);
        if (!inserted && found->second != hash_address.address) {
          identity_ambiguous = true;
        }
        const auto distance = fish_distance_squared(
            session, player, entity.value);
        if (distance.status == distance_status::unavailable) {
          declared_list_incomplete = true;
          continue;
        }
        if (distance.status != distance_status::ready) {
          active_geometry_invalid = true;
          continue;
        }
      }
    }
  }
  if (identity_ambiguous) {
    return {.reason = readiness_reason::active_fish_ambiguous};
  }
  if (!valid_bounded_count || declared_list_incomplete) {
    return {.reason = readiness_reason::active_fish_unavailable};
  }
  if (active_candidates.size() > 1U) {
    return {.reason = readiness_reason::active_fish_ambiguous};
  }
  if (active_candidates.empty() || active_geometry_invalid) {
    return {.reason = readiness_reason::active_fish_unavailable};
  }
  return {
      .reason = readiness_reason::ready,
      .entity = active_candidates.begin()->first,
      .hash_address = active_candidates.begin()->second,
  };
}

[[nodiscard]] validation_probe validate_impl(
    memory::memory_connector& connector,
    const memory::embedded_memory_build_profile& frozen_baseline,
    const std::string_view candidate_sha256,
    const sonar::platform::windows::process_generation& game_generation,
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns) {
  if (!exact_frozen_baseline(frozen_baseline) ||
      !valid_sha256(candidate_sha256) || game_generation.process_id == 0U ||
      game_generation.creation_time_filetime_100ns == 0U || sequence == 0U ||
      captured_at_steady_ns == 0U) {
    return {.reason = readiness_reason::candidate_identity_invalid};
  }
  for (const auto& admitted : memory::embedded_memory_build_profiles()) {
    if (same_image_name(admitted.game.image_name, frozen_baseline.game.image_name) &&
        same_sha256(admitted.game.image_sha256, candidate_sha256)) {
      return {.reason = readiness_reason::candidate_identity_invalid};
    }
  }

  auto candidate_layout = frozen_baseline;
  candidate_layout.game.image_sha256 = std::string(candidate_sha256);

  std::string connector_reason;
  auto session = connector.connect(
      memory::process_role::game,
      game_generation.process_id,
      connector_reason);
  if (!session || session->identity().generation != game_generation ||
      !same_image_name(
          session->identity().image_name, candidate_layout.game.image_name) ||
      !same_sha256(
          session->identity().image_sha256,
          candidate_layout.game.image_sha256) ||
      session->identity().admission !=
          memory::process_admission::exact_image_sha256 ||
      !session->generation_current()) {
    return {.reason = readiness_reason::game_target_changed};
  }
  const auto* module = exact_game_module(session->identity());
  if (module == nullptr) {
    return {.reason = readiness_reason::module_layout_unavailable};
  }
  auto image = memory_detail::read_executable_module(*session, *module);
  if (!image.image.has_value()) {
    if (!session->generation_current()) {
      return {.reason = readiness_reason::game_target_changed};
    }
    return {.reason = image.status ==
            memory_detail::executable_module_read_status::scan_incomplete
        ? readiness_reason::module_executable_scan_incomplete
        : readiness_reason::module_layout_unavailable};
  }
  if (!session->generation_current()) {
    return {.reason = readiness_reason::game_target_changed};
  }

  const auto player = resolve_unique_player(
      *session, *image.image, candidate_layout);
  if (player.reason != readiness_reason::ready) {
    return {.reason = player.reason};
  }
  const auto replay = resolve_unique_replay(
      *session, *image.image, candidate_layout);
  if (replay.reason != readiness_reason::ready) {
    return {.reason = replay.reason};
  }
  if (!session->generation_current()) {
    return {.reason = readiness_reason::game_target_changed};
  }
  const auto fish = resolve_unique_active_fish(
      *session, replay.address, player.address, candidate_layout);
  if (fish.reason != readiness_reason::ready) {
    return {
        .patterns_unique = true,
        .reason = fish.reason,
    };
  }
  if (!session->generation_current()) {
    return {
        .patterns_unique = true,
        .fish_identity_ready = true,
        .reason = readiness_reason::game_target_changed,
    };
  }

  const auto player_size = (std::max)(
      kPlayerPositionOffset + sizeof(float) * 3U,
      player.right_offset + sizeof(float) * 2U);
  const auto fish_size = (std::max)({
      kFishWorldPositionOffset + sizeof(float) * 3U,
      candidate_layout.fish_active_offset + sizeof(std::uint8_t),
      kFishIdentityProjectionOffset + sizeof(std::uint32_t),
  });
  memory::memory_observation_profile candidate_profile{
      .profile_id = std::string(candidate_profile_id),
      .profile_revision = candidate_profile_schema_version,
      .game = candidate_layout.game,
      .webengine = {.required = false},
      .reeling = {
          .player_position_offset = kPlayerPositionOffset,
          .player_right_offset = player.right_offset,
          .fish_position_offset = kFishWorldPositionOffset,
          .fish_model_hash_offset = kFishIdentityProjectionOffset,
          .fish_active_offset = candidate_layout.fish_active_offset,
          .expected_fish_model_hash = candidate_layout.fish_model_hash,
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
  memory::capture_plan plan{
      .sequence = sequence,
      .captured_at_steady_ns = captured_at_steady_ns,
      .game_process_id = game_generation.process_id,
      .expected_game_generation = game_generation,
      .regions = {
          {memory::evidence_region_kind::reeling_player,
           memory::process_role::game, 0U, player.address, player_size},
          {memory::evidence_region_kind::reeling_fish,
           memory::process_role::game, 0U, fish.entity, fish_size},
          {memory::evidence_region_kind::reeling_fish_identity,
           memory::process_role::game, 0U, fish.hash_address,
           sizeof(std::uint32_t)},
      },
  };

  memory::memory_observer observer(connector);
  const auto captured = observer.capture(candidate_profile, plan);
  if (!captured.ready() || !captured.snapshot.has_value() ||
      !captured.snapshot->reeling.has_value()) {
    return {
        .patterns_unique = true,
        .fish_identity_ready = true,
        .reason = readiness_reason::coherent_snapshot_unavailable,
    };
  }
  const auto& snapshot = *captured.snapshot;
  const auto& reeling = *snapshot.reeling;
  const auto finite_geometry =
      std::isfinite(reeling.player_position.x) &&
      std::isfinite(reeling.player_position.y) &&
      std::isfinite(reeling.player_position.z) &&
      std::isfinite(reeling.fish_position.x) &&
      std::isfinite(reeling.fish_position.y) &&
      std::isfinite(reeling.fish_position.z) &&
      std::isfinite(reeling.player_right_x) &&
      std::isfinite(reeling.player_right_y) &&
      std::isfinite(reeling.distance) && reeling.distance > 1.0 &&
      reeling.distance < 120.0;
  if (snapshot.sequence != sequence ||
      snapshot.captured_at_steady_ns != captured_at_steady_ns ||
      snapshot.game_generation != game_generation ||
      snapshot.profile_id != candidate_profile_id ||
      snapshot.profile_revision != candidate_profile_schema_version ||
      !reeling.active || !reeling.fish_model_confirmed || !finite_geometry) {
    return {
        .patterns_unique = true,
        .fish_identity_ready = true,
        .reason = readiness_reason::coherent_snapshot_unavailable,
    };
  }

  const auto post_hash = read_value<std::uint32_t>(
      *session, fish.hash_address);
  const auto post_active_address = checked_add(
      fish.entity, candidate_layout.fish_active_offset);
  if (!post_active_address.has_value()) {
    return {
        .patterns_unique = true,
        .fish_identity_ready = true,
        .reason = readiness_reason::coherent_snapshot_unavailable,
    };
  }
  const auto post_active = read_value<std::uint8_t>(
      *session, *post_active_address);
  if (post_hash.status != read_status::ready ||
      post_hash.value != candidate_layout.fish_model_hash ||
      post_active.status != read_status::ready || post_active.value != 1U ||
      !session->generation_current()) {
    return {
        .patterns_unique = true,
        .fish_identity_ready = true,
        .reason = readiness_reason::coherent_snapshot_unavailable,
    };
  }
  return {
      .patterns_unique = true,
      .fish_identity_ready = true,
      .snapshot_ready = true,
      .reason = readiness_reason::ready,
  };
}

}  // namespace

validation_probe validate_candidate_reeling(
    memory::memory_connector& connector,
    const memory::embedded_memory_build_profile& frozen_baseline,
    const std::string_view candidate_sha256,
    const sonar::platform::windows::process_generation& game_generation,
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns) noexcept {
  try {
    return validate_impl(
        connector,
        frozen_baseline,
        candidate_sha256,
        game_generation,
        sequence,
        captured_at_steady_ns);
  } catch (...) {
    return {.reason = readiness_reason::internal_error};
  }
}

}  // namespace sonar::fishing::build_profile_compatibility_probe
