#include "trusted_reeling_binding.h"

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

namespace sonar::fishing::memory_observation::detail {
namespace {

constexpr std::size_t kMaximumPatternHits = 4096U;
constexpr std::size_t kMaximumPatternBytes = 64U * 1024U;
constexpr std::size_t kMaximumReplayEntities = 2048U;
constexpr std::uintptr_t kMinimumUserPointer = 0x10000U;
constexpr std::uintptr_t kMaximumUserPointer = 0x00007FFF'FFFF'FFFFULL;
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

[[nodiscard]] bool same_image_name(
    const std::wstring_view left,
    const std::wstring_view right) noexcept {
  return left.size() == right.size() &&
      std::equal(
          left.begin(), left.end(), right.begin(),
          [](const wchar_t first, const wchar_t second) {
            return std::towlower(first) == std::towlower(second);
          });
}

[[nodiscard]] bool module_contains(
    const executable_module_image& module,
    const std::uintptr_t address,
    const std::size_t size = 1U) noexcept {
  return size > 0U && address >= module.base &&
      address - module.base < module.size &&
      size <= module.size - static_cast<std::size_t>(address - module.base);
}

enum class read_status : std::uint8_t {
  invalid,
  ready,
  unavailable,
};

template <typename Value>
struct value_read final {
  read_status status{read_status::invalid};
  Value value{};
};

template <typename Value>
[[nodiscard]] value_read<Value> read_value(
    readonly_memory_session& session,
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

[[nodiscard]] bool valid_pattern(
    const relative_pointer_pattern& pattern) noexcept {
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
    const relative_pointer_pattern& pattern) noexcept {
  if (offset > bytes.size() ||
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

struct pattern_hits final {
  bool valid{};
  bool over_budget{};
  std::vector<std::uintptr_t> addresses;
};

[[nodiscard]] pattern_hits enumerate_pattern_hits(
    const executable_module_image& module,
    const relative_pointer_pattern& pattern) {
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
      if (result.addresses.size() == kMaximumPatternHits) {
        result.over_budget = true;
        continue;
      }
      result.addresses.push_back(*address);
    }
  }
  return result;
}

[[nodiscard]] std::optional<std::span<const std::byte>> module_bytes_at(
    const executable_module_image& module,
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
  invalid,
  ready,
  incomplete,
};

struct pointer_endpoint final {
  endpoint_status status{endpoint_status::invalid};
  std::uintptr_t value{};
};

[[nodiscard]] pointer_endpoint resolve_pattern_endpoint(
    readonly_memory_session& session,
    const executable_module_image& module,
    const std::uintptr_t hit_address,
    const relative_pointer_pattern& pattern) noexcept {
  const auto bytes = module_bytes_at(module, hit_address, pattern.bytes.size());
  if (!bytes.has_value() ||
      !module_contains(module, hit_address, pattern.instruction_length)) {
    return {};
  }
  std::int32_t displacement{};
  std::memcpy(
      &displacement,
      bytes->data() + pattern.displacement_offset,
      sizeof(displacement));
  const auto instruction_end = checked_add(
      hit_address, pattern.instruction_length);
  if (!instruction_end.has_value() ||
      *instruction_end > static_cast<std::uintptr_t>(
          (std::numeric_limits<std::int64_t>::max)())) {
    return {};
  }
  const auto signed_target = static_cast<std::int64_t>(*instruction_end) +
      static_cast<std::int64_t>(displacement);
  if (signed_target <= 0 ||
      static_cast<std::uint64_t>(signed_target) > kMaximumUserPointer) {
    return {};
  }
  const auto pointer_slot = static_cast<std::uintptr_t>(signed_target);
  if (!module_contains(module, pointer_slot, sizeof(std::uintptr_t))) {
    return {};
  }
  auto value = read_value<std::uintptr_t>(session, pointer_slot);
  if (value.status == read_status::unavailable) {
    return {.status = endpoint_status::incomplete};
  }
  if (value.status != read_status::ready ||
      !plausible_pointer(value.value)) {
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
    if (value.status != read_status::ready ||
        !plausible_pointer(value.value)) {
      return {};
    }
  }
  return {.status = endpoint_status::ready, .value = value.value};
}

struct finite_vector3 final {
  double x{};
  double y{};
  double z{};
};

[[nodiscard]] std::optional<finite_vector3> read_vector3(
    readonly_memory_session& session,
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
  return finite_vector3{values[0], values[1], values[2]};
}

struct player_endpoint final {
  endpoint_status status{endpoint_status::invalid};
  std::size_t right_offset{};
};

[[nodiscard]] player_endpoint validate_player_endpoint(
    readonly_memory_session& session,
    const std::uintptr_t player,
    const executable_module_image& module,
    const embedded_memory_build_profile& profile) noexcept {
  const auto vtable = read_value<std::uintptr_t>(session, player);
  if (vtable.status == read_status::unavailable) {
    return {.status = endpoint_status::incomplete};
  }
  if (vtable.status != read_status::ready ||
      !module_contains(module, vtable.value)) {
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
  std::uintptr_t address{};
  std::size_t right_offset{};
  std::string reason;

  [[nodiscard]] bool ready() const noexcept {
    return address != 0U && right_offset != 0U && reason.empty();
  }
};

[[nodiscard]] player_resolution resolve_unique_player(
    readonly_memory_session& session,
    const executable_module_image& module,
    const embedded_memory_build_profile& profile) {
  std::map<std::uintptr_t, std::size_t> players;
  bool observed_hit = false;
  bool incomplete = false;
  bool conflicting_projection = false;
  for (const auto& pattern : profile.world_patterns) {
    const auto hits = enumerate_pattern_hits(module, pattern);
    if (!hits.valid) {
      return {.reason = "memory_world_pattern_invalid"};
    }
    if (hits.over_budget) {
      return {.reason = "memory_world_endpoint_ambiguous"};
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
    return {.reason = "memory_world_endpoint_incomplete"};
  }
  if (conflicting_projection || players.size() > 1U) {
    return {.reason = "memory_world_endpoint_ambiguous"};
  }
  if (!observed_hit || players.empty()) {
    return {.reason = "memory_world_endpoint_unresolved"};
  }
  return {
      .address = players.begin()->first,
      .right_offset = players.begin()->second,
  };
}

struct replay_resolution final {
  std::uintptr_t address{};
  std::string reason;

  [[nodiscard]] bool ready() const noexcept {
    return address != 0U && reason.empty();
  }
};

[[nodiscard]] replay_resolution resolve_unique_replay(
    readonly_memory_session& session,
    const executable_module_image& module,
    const embedded_memory_build_profile& profile) {
  const auto hits = enumerate_pattern_hits(module, profile.replay_pattern);
  if (!hits.valid) {
    return {.reason = "memory_replay_pattern_invalid"};
  }
  if (hits.over_budget || hits.addresses.size() > 1U) {
    return {.reason = "memory_replay_endpoint_ambiguous"};
  }
  if (hits.addresses.empty()) {
    return {.reason = "memory_replay_endpoint_unresolved"};
  }
  const auto endpoint = resolve_pattern_endpoint(
      session, module, hits.addresses.front(), profile.replay_pattern);
  if (endpoint.status == endpoint_status::incomplete) {
    return {.reason = "memory_replay_endpoint_incomplete"};
  }
  if (endpoint.status != endpoint_status::ready) {
    return {.reason = "memory_replay_endpoint_unresolved"};
  }
  return {.address = endpoint.value};
}

enum class fish_hash_status : std::uint8_t {
  unavailable,
  ready,
  absent,
  ambiguous,
};

struct fish_hash_resolution final {
  fish_hash_status status{fish_hash_status::absent};
  std::uintptr_t address{};
};

[[nodiscard]] fish_hash_resolution find_exact_fish_hash(
    readonly_memory_session& session,
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
      } else if (value.status == read_status::ready &&
                 value.value == expected_hash) {
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
    } else if (value.status == read_status::ready &&
               value.value == expected_hash) {
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
  unavailable,
  invalid,
  ready,
};

[[nodiscard]] distance_status validate_fish_distance(
    readonly_memory_session& session,
    const std::uintptr_t player,
    const std::uintptr_t fish) noexcept {
  const auto player_address = checked_add(player, kPlayerPositionOffset);
  const auto fish_address = checked_add(fish, kFishWorldPositionOffset);
  if (!player_address.has_value() || !fish_address.has_value()) {
    return distance_status::invalid;
  }
  bool unavailable = false;
  const auto player_position = read_vector3(
      session, *player_address, unavailable);
  const auto fish_position = read_vector3(
      session, *fish_address, unavailable);
  if (unavailable) {
    return distance_status::unavailable;
  }
  if (!player_position.has_value() || !fish_position.has_value()) {
    return distance_status::invalid;
  }
  const auto dx = fish_position->x - player_position->x;
  const auto dy = fish_position->y - player_position->y;
  const auto dz = fish_position->z - player_position->z;
  const auto squared = dx * dx + dy * dy + dz * dz;
  return std::isfinite(squared) && squared > 1.0 &&
          squared < 120.0 * 120.0
      ? distance_status::ready
      : distance_status::invalid;
}

[[nodiscard]] bool uncertain_reason(const std::string_view reason) noexcept {
  return reason.ends_with("_incomplete") || reason.ends_with("_ambiguous") ||
      reason == "memory_module_executable_scan_incomplete";
}

}  // namespace

trusted_fish_binding resolve_trusted_active_fish(
    readonly_memory_session& session,
    const std::uintptr_t replay,
    const std::uintptr_t player,
    const embedded_memory_build_profile& profile) noexcept {
  try {
    constexpr std::array interface_offsets{
        0x08U, 0x20U, 0x18U, 0x10U, 0x28U};
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
        const auto list = read_value<std::uintptr_t>(session, *list_address);
        const auto count = read_value<std::int32_t>(session, *count_address);
        if (list.status == read_status::unavailable ||
            count.status == read_status::unavailable) {
          declared_list_incomplete = true;
          continue;
        }
        if (list.status != read_status::ready ||
            count.status != read_status::ready ||
            !plausible_pointer(list.value) ||
            (list.value % alignof(std::uintptr_t)) != 0U ||
            count.value <= 0 ||
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
          const auto hash = find_exact_fish_hash(
              session, entity.value, profile.fish_model_hash);
          if (hash.status == fish_hash_status::unavailable) {
            declared_list_incomplete = true;
            continue;
          }
          if (hash.status == fish_hash_status::ambiguous) {
            identity_ambiguous = true;
            continue;
          }
          if (hash.status != fish_hash_status::ready) {
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
              entity.value, hash.address);
          if (!inserted && found->second != hash.address) {
            identity_ambiguous = true;
          }
          const auto distance = validate_fish_distance(
              session, player, entity.value);
          if (distance == distance_status::unavailable) {
            declared_list_incomplete = true;
          } else if (distance != distance_status::ready) {
            active_geometry_invalid = true;
          }
        }
      }
    }
    if (identity_ambiguous || active_candidates.size() > 1U) {
      return {.reason = "memory_active_fish_ambiguous"};
    }
    if (!valid_bounded_count || declared_list_incomplete) {
      return {.reason = "memory_active_fish_incomplete"};
    }
    if (active_candidates.empty() || active_geometry_invalid) {
      return {.reason = "memory_active_fish_unavailable"};
    }
    return {
        .entity = active_candidates.begin()->first,
        .hash_address = active_candidates.begin()->second,
    };
  } catch (...) {
    return {.reason = "memory_active_fish_resolution_failed"};
  }
}

trusted_reeling_binding resolve_trusted_reeling_binding(
    readonly_memory_session& session,
    const sonar::platform::windows::module_snapshot& module,
    const std::span<const embedded_memory_build_profile> profiles,
    const std::wstring_view image_name) noexcept {
  try {
    if (session.identity().admission !=
            process_admission::trusted_publisher_runtime ||
        session.identity().authority_fingerprint == 0U ||
        profiles.empty() || image_name.empty()) {
      return {.reason = "memory_trusted_authority_invalid"};
    }
    auto image = read_executable_module(session, module);
    if (!image.image.has_value()) {
      return {.reason = image.status ==
              executable_module_read_status::scan_incomplete
          ? "memory_module_executable_scan_incomplete"
          : "memory_module_layout_unavailable"};
    }
    if (!session.generation_current()) {
      return {.reason = "memory_process_generation_changed"};
    }

    std::vector<trusted_reeling_binding> admitted;
    std::string uncertain;
    bool matching_profile = false;
    for (const auto& profile : profiles) {
      if (!same_image_name(image_name, profile.game.image_name)) {
        continue;
      }
      matching_profile = true;
      const auto player = resolve_unique_player(
          session, *image.image, profile);
      if (!player.ready()) {
        if (uncertain_reason(player.reason)) {
          uncertain = player.reason;
        }
        continue;
      }
      const auto replay = resolve_unique_replay(
          session, *image.image, profile);
      if (!replay.ready()) {
        if (uncertain_reason(replay.reason)) {
          uncertain = replay.reason;
        }
        continue;
      }
      auto fish = resolve_trusted_active_fish(
          session, replay.address, player.address, profile);
      if (!fish.ready()) {
        if (uncertain_reason(fish.reason)) {
          uncertain = fish.reason;
        }
        continue;
      }
      admitted.push_back({
          .profile = &profile,
          .player = player.address,
          .replay = replay.address,
          .fish = std::move(fish),
          .player_right_offset = player.right_offset,
      });
    }
    if (!session.generation_current()) {
      return {.reason = "memory_process_generation_changed"};
    }
    if (!uncertain.empty()) {
      return {.reason = std::move(uncertain)};
    }
    if (admitted.size() > 1U) {
      return {.reason = "memory_semantic_layout_ambiguous"};
    }
    if (admitted.empty()) {
      return {.reason = matching_profile
          ? "memory_semantic_layout_unresolved"
          : "memory_semantic_layout_unavailable"};
    }
    return std::move(admitted.front());
  } catch (...) {
    return {.reason = "memory_semantic_layout_resolution_failed"};
  }
}

}  // namespace sonar::fishing::memory_observation::detail
