#include "candidate_reeling_validator.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace probe = sonar::fishing::build_profile_compatibility_probe;
namespace memory = sonar::fishing::memory_observation;

namespace {

constexpr std::uintptr_t kModule = 0x100000U;
constexpr std::size_t kModuleSize = 0x30000U;
constexpr std::size_t kHeadersSize = 0x1000U;
constexpr std::size_t kTextRva = 0x1000U;
constexpr std::size_t kTextSize = 0x20000U;
constexpr std::size_t kDataRva = 0x22000U;
constexpr std::size_t kDataSize = 0xD000U;
constexpr std::size_t kWorldHitOffset = kTextRva + 0x100U;
constexpr std::size_t kReplayHitOffset = kTextRva + 0x300U;
constexpr std::size_t kWorldSlotOffset = kDataRva + 0x100U;
constexpr std::size_t kReplaySlotOffset = kDataRva + 0x200U;
constexpr std::uint32_t kMemoryCommit = 0x1000U;
constexpr std::uint32_t kPageNoAccess = 0x01U;
constexpr std::uint32_t kPageExecuteRead = 0x20U;
constexpr std::uint32_t kMemoryImage = 0x1000000U;
constexpr std::uintptr_t kWorld = 0x200000U;
constexpr std::uintptr_t kPlayer = 0x210000U;
constexpr std::uintptr_t kReplay = 0x220000U;
constexpr std::uintptr_t kInterface = 0x230000U;
constexpr std::uintptr_t kEntityList = 0x240000U;
constexpr std::uintptr_t kFish = 0x250000U;
constexpr std::uintptr_t kArchetype = 0x260000U;
constexpr std::uint32_t kProcessId = 4242U;
constexpr std::uint64_t kCreatedAt = 99112233U;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

template <typename Value>
void write_value(
    std::vector<std::byte>& bytes,
    const std::size_t offset,
    const Value value) {
  if (offset > bytes.size() || sizeof(Value) > bytes.size() - offset) {
    throw std::runtime_error("test_write_out_of_range");
  }
  std::memcpy(bytes.data() + offset, &value, sizeof(value));
}

void write_vector3(
    std::vector<std::byte>& bytes,
    const std::size_t offset,
    const float x,
    const float y,
    const float z) {
  write_value(bytes, offset, x);
  write_value(bytes, offset + sizeof(float), y);
  write_value(bytes, offset + sizeof(float) * 2U, z);
}

void write_section_header(
    std::vector<std::byte>& image,
    const std::size_t offset,
    const std::uint32_t virtual_size,
    const std::uint32_t virtual_address,
    const std::uint32_t raw_size,
    const std::uint32_t characteristics) {
  write_value(image, offset + 8U, virtual_size);
  write_value(image, offset + 12U, virtual_address);
  write_value(image, offset + 16U, raw_size);
  write_value(image, offset + 36U, characteristics);
}

void materialize_pe_layout(std::vector<std::byte>& image) {
  constexpr std::size_t nt_offset = 0x80U;
  constexpr std::size_t optional_offset = nt_offset + 24U;
  constexpr std::uint16_t optional_size = 0xF0U;
  constexpr std::size_t section_table_offset =
      optional_offset + optional_size;
  write_value(image, 0U, std::uint16_t{0x5A4DU});
  write_value(image, 0x3CU, std::uint32_t{nt_offset});
  write_value(image, nt_offset, std::uint32_t{0x00004550U});
  write_value(image, nt_offset + 4U, std::uint16_t{0x8664U});
  write_value(image, nt_offset + 6U, std::uint16_t{2U});
  write_value(image, nt_offset + 20U, optional_size);
  write_value(image, optional_offset, std::uint16_t{0x020BU});
  write_value(
      image, optional_offset + 56U,
      static_cast<std::uint32_t>(kModuleSize));
  write_value(
      image, optional_offset + 60U,
      static_cast<std::uint32_t>(kHeadersSize));
  write_section_header(
      image,
      section_table_offset,
      static_cast<std::uint32_t>(kTextSize),
      static_cast<std::uint32_t>(kTextRva),
      static_cast<std::uint32_t>(kTextSize),
      0x60000020U);
  write_section_header(
      image,
      section_table_offset + 40U,
      static_cast<std::uint32_t>(kDataSize),
      static_cast<std::uint32_t>(kDataRva),
      static_cast<std::uint32_t>(kDataSize),
      0xC0000040U);
}

struct fake_state final {
  memory::process_identity identity;
  std::map<std::uintptr_t, std::vector<std::byte>> regions;
  std::vector<sonar::platform::windows::memory_region_snapshot>
      virtual_regions;
  bool generation_current{true};
  std::optional<std::uintptr_t> zero_on_second_exact_read;
  std::size_t watched_exact_reads{};
  std::optional<std::uintptr_t> denied_exact_read;
  std::size_t denied_exact_size{};
  std::optional<std::uintptr_t> denied_range;
  std::size_t denied_range_size{};
  std::map<std::pair<std::uintptr_t, std::size_t>, std::size_t>
      transient_failures;
  std::size_t exact_read_attempts{};
};

[[nodiscard]] bool ranges_overlap(
    const std::uintptr_t first_address,
    const std::size_t first_size,
    const std::uintptr_t second_address,
    const std::size_t second_size) noexcept {
  if (first_size == 0U || second_size == 0U) {
    return false;
  }
  const auto maximum = (std::numeric_limits<std::uintptr_t>::max)();
  if (first_size > maximum - first_address ||
      second_size > maximum - second_address) {
    return true;
  }
  return first_address < second_address + second_size &&
      second_address < first_address + first_size;
}

class fake_session final : public memory::readonly_memory_session {
 public:
  explicit fake_session(std::shared_ptr<fake_state> state)
      : state_(std::move(state)) {}

  [[nodiscard]] const memory::process_identity& identity()
      const noexcept override {
    return state_->identity;
  }

  [[nodiscard]] bool read_exact(
      const std::uintptr_t address,
      const std::span<std::byte> destination) noexcept override {
    ++state_->exact_read_attempts;
    const auto transient = state_->transient_failures.find(
        {address, destination.size()});
    if (transient != state_->transient_failures.end() &&
        transient->second > 0U) {
      --transient->second;
      return false;
    }
    if (state_->denied_range.has_value() && ranges_overlap(
            address,
            destination.size(),
            *state_->denied_range,
            state_->denied_range_size)) {
      return false;
    }
    if (state_->denied_exact_read == address &&
        state_->denied_exact_size == destination.size()) {
      return false;
    }
    if (state_->zero_on_second_exact_read == address &&
        destination.size() == 1U) {
      ++state_->watched_exact_reads;
      if (state_->watched_exact_reads >= 2U) {
        std::fill(destination.begin(), destination.end(), std::byte{0U});
        return true;
      }
    }
    auto found = state_->regions.upper_bound(address);
    if (found == state_->regions.begin()) {
      return false;
    }
    --found;
    if (address < found->first) {
      return false;
    }
    const auto offset = static_cast<std::size_t>(address - found->first);
    if (offset > found->second.size() ||
        destination.size() > found->second.size() - offset) {
      return false;
    }
    std::copy_n(
        found->second.begin() + static_cast<std::ptrdiff_t>(offset),
        destination.size(),
        destination.begin());
    return true;
  }

  [[nodiscard]] bool generation_current() noexcept override {
    return state_->generation_current;
  }

  [[nodiscard]] std::optional<
      sonar::platform::windows::memory_region_snapshot>
  query_region(const std::uintptr_t address) noexcept override {
    for (const auto& region : state_->virtual_regions) {
      if (region.size == 0U || region.base_address > address) {
        continue;
      }
      const auto offset = address - region.base_address;
      if (offset < region.size) {
        return region;
      }
    }
    return std::nullopt;
  }

 private:
  std::shared_ptr<fake_state> state_;
};

class fake_connector final : public memory::memory_connector {
 public:
  explicit fake_connector(std::shared_ptr<fake_state> state)
      : state_(std::move(state)) {}

  [[nodiscard]] std::unique_ptr<memory::readonly_memory_session> connect(
      const memory::process_role role,
      const std::uint32_t process_id,
      std::string& reason) noexcept override {
    if (role != memory::process_role::game || process_id != kProcessId) {
      reason = "fake_process_unavailable";
      return nullptr;
    }
    ++connect_count_;
    reason = "ready";
    return std::make_unique<fake_session>(state_);
  }

  [[nodiscard]] std::size_t connect_count() const noexcept {
    return connect_count_;
  }

 private:
  std::shared_ptr<fake_state> state_;
  std::size_t connect_count_{};
};

void materialize_pattern(
    std::vector<std::byte>& module,
    const std::size_t hit_offset,
    const memory::relative_pointer_pattern& pattern,
    const std::size_t pointer_slot_offset,
    const std::uintptr_t initial_pointer) {
  if (hit_offset > module.size() ||
      pattern.bytes.size() > module.size() - hit_offset ||
      pointer_slot_offset > module.size() ||
      sizeof(std::uintptr_t) > module.size() - pointer_slot_offset) {
    throw std::runtime_error("test_pattern_out_of_range");
  }
  for (std::size_t index = 0U; index < pattern.bytes.size(); ++index) {
    module[hit_offset + index] = pattern.bytes[index] < 0
        ? std::byte{0x90U}
        : static_cast<std::byte>(pattern.bytes[index]);
  }
  const auto instruction_end = kModule + hit_offset +
      pattern.instruction_length;
  const auto pointer_slot = kModule + pointer_slot_offset;
  const auto displacement = static_cast<std::int32_t>(
      static_cast<std::int64_t>(pointer_slot) -
      static_cast<std::int64_t>(instruction_end));
  write_value(
      module,
      hit_offset + pattern.displacement_offset,
      displacement);
  write_value(module, pointer_slot_offset, initial_pointer);
}

void add_player(
    fake_state& state,
    const std::uintptr_t world,
    const std::uintptr_t player) {
  auto world_bytes = std::vector<std::byte>(0x100U);
  write_value(world_bytes, 0x08U, player);
  state.regions[world] = std::move(world_bytes);

  auto player_bytes = std::vector<std::byte>(0x200U);
  write_value(player_bytes, 0U, kModule + 0x3000U);
  write_vector3(player_bytes, 0x90U, 0.0F, 0.0F, 0.0F);
  std::array<float, 16U> matrix{};
  matrix[0] = 1.0F;
  std::memcpy(player_bytes.data() + 0x50U, matrix.data(), sizeof(matrix));
  state.regions[player] = std::move(player_bytes);
}

void add_fish(
    fake_state& state,
    const std::uintptr_t fish,
    const std::uintptr_t archetype,
    const float x) {
  auto fish_bytes = std::vector<std::byte>(0x200U);
  write_value(fish_bytes, 0x20U, archetype);
  write_vector3(fish_bytes, 0x90U, x, 0.0F, 0.0F);
  write_value(fish_bytes, 0x189U, std::uint8_t{1U});
  state.regions[fish] = std::move(fish_bytes);

  auto archetype_bytes = std::vector<std::byte>(0x100U);
  write_value(archetype_bytes, 0x18U, std::uint32_t{802685111U});
  state.regions[archetype] = std::move(archetype_bytes);
}

struct validator_fixture final {
  std::shared_ptr<fake_state> state;
  memory::embedded_memory_build_profile baseline;
  std::string candidate_sha256;
};

[[nodiscard]] validator_fixture make_fixture() {
  const auto profiles = memory::embedded_memory_build_profiles();
  constexpr std::string_view baseline_id = "majestic-gta5-677e4e35-v1";
  constexpr std::uint32_t baseline_revision = 1U;
  const memory::embedded_memory_build_profile* baseline = nullptr;
  for (const auto& profile : profiles) {
    if (profile.profile_id != baseline_id ||
        profile.profile_revision != baseline_revision) {
      continue;
    }
    require(baseline == nullptr, "test_baseline_identity_duplicated");
    baseline = &profile;
  }
  require(baseline != nullptr, "test_baseline_identity_missing");
  auto state = std::make_shared<fake_state>();
  state->identity = memory::process_identity{
      .role = memory::process_role::game,
      .generation = {
          .process_id = kProcessId,
          .creation_time_filetime_100ns = kCreatedAt,
      },
      .image_name = L"GTA5.exe",
      .image_sha256 = std::string(64U, 'D'),
      .modules = {{
          .name = L"GTA5.exe",
          .path = L"ignored-test-path",
          .base_address = kModule,
          .size = kModuleSize,
      }},
  };
  state->virtual_regions = {{
      .base_address = kModule,
      .size = kModuleSize,
      .state = kMemoryCommit,
      .protection = kPageExecuteRead,
      .kind = kMemoryImage,
  }};

  auto module = std::vector<std::byte>(kModuleSize, std::byte{0U});
  std::fill(
      module.begin() + static_cast<std::ptrdiff_t>(kTextRva),
      module.begin() + static_cast<std::ptrdiff_t>(kTextRva + kTextSize),
      std::byte{0xCCU});
  materialize_pe_layout(module);
  materialize_pattern(
      module,
      kWorldHitOffset,
      baseline->world_patterns.front(),
      kWorldSlotOffset,
      kWorld);
  materialize_pattern(
      module,
      kReplayHitOffset,
      baseline->replay_pattern,
      kReplaySlotOffset,
      kReplay);
  state->regions[kModule] = std::move(module);
  add_player(*state, kWorld, kPlayer);

  auto replay_bytes = std::vector<std::byte>(0x200U);
  write_value(replay_bytes, 0x08U, kInterface);
  state->regions[kReplay] = std::move(replay_bytes);
  auto interface_bytes = std::vector<std::byte>(0x200U);
  write_value(interface_bytes, 0x00U, kEntityList);
  write_value(interface_bytes, 0x18U, std::int32_t{1});
  state->regions[kInterface] = std::move(interface_bytes);
  auto list_bytes = std::vector<std::byte>(0x10U);
  write_value(list_bytes, 0U, kFish);
  state->regions[kEntityList] = std::move(list_bytes);
  add_fish(*state, kFish, kArchetype, 10.0F);

  return {
      .state = std::move(state),
      .baseline = *baseline,
      .candidate_sha256 = std::string(64U, 'D'),
  };
}

[[nodiscard]] probe::validation_probe validate(validator_fixture& fixture) {
  fake_connector connector(fixture.state);
  return probe::validate_candidate_reeling(
      connector,
      fixture.baseline,
      fixture.candidate_sha256,
      fixture.state->identity.generation,
      1U,
      1000U);
}

void exact_candidate_proves_unique_coherent_snapshot() {
  auto fixture = make_fixture();
  const auto result = validate(fixture);
  require(result.patterns_unique && result.fish_identity_ready &&
      result.snapshot_ready && result.reason == probe::readiness_reason::ready,
      "valid_candidate_not_proven");
  require(probe::candidate_profile_id != fixture.baseline.profile_id,
      "candidate_identity_reused_baseline_id");
}

void already_admitted_hash_and_mutated_baseline_are_rejected() {
  auto admitted = make_fixture();
  admitted.candidate_sha256 = admitted.baseline.game.image_sha256;
  admitted.state->identity.image_sha256 = admitted.candidate_sha256;
  fake_connector admitted_connector(admitted.state);
  const auto admitted_result = probe::validate_candidate_reeling(
      admitted_connector,
      admitted.baseline,
      admitted.candidate_sha256,
      admitted.state->identity.generation,
      1U,
      1000U);
  require(admitted_result.reason ==
      probe::readiness_reason::candidate_identity_invalid,
      "admitted_hash_not_rejected");
  require(admitted_connector.connect_count() == 0U,
      "admitted_hash_touched_process");

  auto mutated = make_fixture();
  ++mutated.baseline.fish_active_offset;
  fake_connector mutated_connector(mutated.state);
  const auto mutated_result = probe::validate_candidate_reeling(
      mutated_connector,
      mutated.baseline,
      mutated.candidate_sha256,
      mutated.state->identity.generation,
      1U,
      1000U);
  require(mutated_result.reason ==
      probe::readiness_reason::candidate_identity_invalid,
      "mutated_baseline_not_rejected");
}

void world_endpoints_must_collapse_to_one_distinct_player() {
  auto same = make_fixture();
  auto& same_module = same.state->regions.at(kModule);
  materialize_pattern(
      same_module,
      kTextRva + 0x1500U,
      same.baseline.world_patterns.front(),
      kDataRva + 0x300U,
      kWorld);
  const auto same_result = validate(same);
  require(same_result.reason == probe::readiness_reason::ready,
      "same_player_endpoint_not_deduplicated");

  auto distinct = make_fixture();
  constexpr std::uintptr_t second_world = 0x270000U;
  constexpr std::uintptr_t second_player = 0x280000U;
  auto& distinct_module = distinct.state->regions.at(kModule);
  materialize_pattern(
      distinct_module,
      kTextRva + 0x1500U,
      distinct.baseline.world_patterns.front(),
      kDataRva + 0x300U,
      second_world);
  add_player(*distinct.state, second_world, second_player);
  const auto distinct_result = validate(distinct);
  require(!distinct_result.patterns_unique &&
      distinct_result.reason ==
          probe::readiness_reason::world_endpoint_ambiguous,
      "distinct_player_endpoints_not_rejected");
}

void replay_signature_must_be_exactly_one() {
  auto fixture = make_fixture();
  auto& module = fixture.state->regions.at(kModule);
  materialize_pattern(
      module,
      kTextRva + 0x1700U,
      fixture.baseline.replay_pattern,
      kDataRva + 0x400U,
      kReplay);
  const auto result = validate(fixture);
  require(!result.patterns_unique &&
      result.reason ==
          probe::readiness_reason::replay_endpoint_ambiguous,
      "duplicate_replay_signature_not_rejected");
}

void fish_enumeration_has_no_count_fallback_and_requires_one_identity() {
  auto no_count = make_fixture();
  write_value(
      no_count.state->regions.at(kInterface),
      0x18U,
      std::int32_t{0});
  const auto no_count_result = validate(no_count);
  require(no_count_result.patterns_unique &&
      !no_count_result.fish_identity_ready &&
      no_count_result.reason == probe::readiness_reason::active_fish_unavailable,
      "invalid_entity_count_used_fallback");

  auto two_fish = make_fixture();
  constexpr std::uintptr_t second_fish = 0x290000U;
  constexpr std::uintptr_t second_archetype = 0x2A0000U;
  write_value(
      two_fish.state->regions.at(kInterface),
      0x18U,
      std::int32_t{2});
  auto list = std::vector<std::byte>(0x20U);
  write_value(list, 0U, kFish);
  write_value(list, 0x10U, second_fish);
  two_fish.state->regions[kEntityList] = std::move(list);
  add_fish(*two_fish.state, second_fish, second_archetype, 15.0F);
  const auto two_fish_result = validate(two_fish);
  require(two_fish_result.patterns_unique &&
      !two_fish_result.fish_identity_ready &&
      two_fish_result.reason == probe::readiness_reason::active_fish_ambiguous,
      "multiple_active_fish_not_rejected");

  auto hidden_by_geometry = make_fixture();
  write_value(
      hidden_by_geometry.state->regions.at(kInterface),
      0x18U,
      std::int32_t{2});
  auto geometry_list = std::vector<std::byte>(0x20U);
  write_value(geometry_list, 0U, kFish);
  write_value(geometry_list, 0x10U, second_fish);
  hidden_by_geometry.state->regions[kEntityList] = std::move(geometry_list);
  add_fish(
      *hidden_by_geometry.state, second_fish, second_archetype, 200.0F);
  const auto hidden_by_geometry_result = validate(hidden_by_geometry);
  require(hidden_by_geometry_result.patterns_unique &&
      !hidden_by_geometry_result.fish_identity_ready &&
      hidden_by_geometry_result.reason ==
          probe::readiness_reason::active_fish_ambiguous,
      "active_fish_hidden_by_invalid_geometry");
}

void unreadable_non_executable_data_does_not_block_scan() {
  auto fixture = make_fixture();
  const auto readable_data_end = kDataRva + 0x1000U;
  fixture.state->virtual_regions = {
      {
          .base_address = kModule,
          .size = readable_data_end,
          .state = kMemoryCommit,
          .protection = kPageExecuteRead,
          .kind = kMemoryImage,
      },
      {
          .base_address = kModule + readable_data_end,
          .size = kModuleSize - readable_data_end,
          .state = kMemoryCommit,
          .protection = kPageNoAccess,
          .kind = kMemoryImage,
      },
  };
  fixture.state->denied_range = kModule + readable_data_end;
  fixture.state->denied_range_size = kModuleSize - readable_data_end;
  const auto result = validate(fixture);
  require(result.patterns_unique && result.snapshot_ready &&
      result.reason == probe::readiness_reason::ready,
      "unreadable_data_was_scanned");
}

void permanent_executable_hole_fails_closed() {
  auto fixture = make_fixture();
  constexpr std::size_t hole_offset = kTextRva + 0x8000U;
  constexpr std::size_t hole_size = 0x1000U;
  fixture.state->virtual_regions = {
      {
          .base_address = kModule,
          .size = hole_offset,
          .state = kMemoryCommit,
          .protection = kPageExecuteRead,
          .kind = kMemoryImage,
      },
      {
          .base_address = kModule + hole_offset,
          .size = hole_size,
          .state = kMemoryCommit,
          .protection = kPageNoAccess,
          .kind = kMemoryImage,
      },
      {
          .base_address = kModule + hole_offset + hole_size,
          .size = kModuleSize - hole_offset - hole_size,
          .state = kMemoryCommit,
          .protection = kPageExecuteRead,
          .kind = kMemoryImage,
      },
  };
  fixture.state->denied_range = kModule + hole_offset;
  fixture.state->denied_range_size = hole_size;
  const auto result = validate(fixture);
  require(!result.patterns_unique &&
      result.reason ==
          probe::readiness_reason::module_executable_scan_incomplete,
      "permanent_executable_hole_not_rejected");
}

void transient_executable_read_recovers_with_bounded_splits() {
  auto fixture = make_fixture();
  const auto address = kModule + kTextRva;
  fixture.state->transient_failures = {
      {{address, 64U * 1024U}, 1U},
      {{address, 32U * 1024U}, 1U},
      {{address, 16U * 1024U}, 1U},
      {{address, 8U * 1024U}, 1U},
      {{address, 4U * 1024U}, 1U},
  };
  const auto result = validate(fixture);
  const auto all_failures_consumed = std::ranges::all_of(
      fixture.state->transient_failures,
      [](const auto& entry) { return entry.second == 0U; });
  require(result.reason == probe::readiness_reason::ready &&
      all_failures_consumed,
      "transient_executable_read_not_recovered");
}

void pattern_wildcard_crossing_scan_chunk_is_found() {
  auto fixture = make_fixture();
  const auto& pattern = fixture.baseline.world_patterns.front();
  require(pattern.bytes.size() > 5U, "world_pattern_too_short_for_boundary");
  auto& module = fixture.state->regions.at(kModule);
  std::fill_n(
      module.begin() + static_cast<std::ptrdiff_t>(kWorldHitOffset),
      pattern.bytes.size(),
      std::byte{0xCCU});
  const auto boundary_hit = kTextRva + 64U * 1024U - 5U;
  materialize_pattern(
      module,
      boundary_hit,
      pattern,
      kWorldSlotOffset,
      kWorld);
  const auto result = validate(fixture);
  require(result.reason == probe::readiness_reason::ready,
      "chunk_boundary_wildcard_not_found");
}

void malformed_pe_layout_is_rejected() {
  auto fixture = make_fixture();
  write_value(
      fixture.state->regions.at(kModule),
      0U,
      std::uint16_t{0U});
  const auto result = validate(fixture);
  require(result.reason == probe::readiness_reason::module_layout_unavailable,
      "malformed_pe_layout_not_rejected");
}

void scanner_reason_keys_are_stage_specific_and_sanitized() {
  require(probe::reason_key(
      probe::readiness_reason::module_layout_unavailable) ==
          "module_layout_unavailable",
      "module_layout_reason_key_changed");
  require(probe::reason_key(
      probe::readiness_reason::module_executable_scan_incomplete) ==
          "module_executable_scan_incomplete",
      "module_scan_reason_key_changed");
  require(probe::reason_key(
      probe::readiness_reason::world_endpoint_incomplete) ==
          "world_endpoint_incomplete" &&
      probe::reason_key(
          probe::readiness_reason::world_endpoint_unresolved) ==
          "world_endpoint_unresolved" &&
      probe::reason_key(
          probe::readiness_reason::world_endpoint_ambiguous) ==
          "world_endpoint_ambiguous",
      "world_reason_keys_collapsed");
  require(probe::reason_key(
      probe::readiness_reason::replay_endpoint_incomplete) ==
          "replay_endpoint_incomplete" &&
      probe::reason_key(
          probe::readiness_reason::replay_endpoint_unresolved) ==
          "replay_endpoint_unresolved" &&
      probe::reason_key(
          probe::readiness_reason::replay_endpoint_ambiguous) ==
          "replay_endpoint_ambiguous",
      "replay_reason_keys_collapsed");
}

void world_and_replay_endpoint_failures_are_stage_specific() {
  auto world_unresolved = make_fixture();
  const auto& world_pattern = world_unresolved.baseline.world_patterns.front();
  std::fill_n(
      world_unresolved.state->regions.at(kModule).begin() +
          static_cast<std::ptrdiff_t>(kWorldHitOffset),
      world_pattern.bytes.size(),
      std::byte{0xCCU});
  require(validate(world_unresolved).reason ==
      probe::readiness_reason::world_endpoint_unresolved,
      "world_unresolved_reason_collapsed");

  auto world_incomplete = make_fixture();
  world_incomplete.state->denied_exact_read = kModule + kWorldSlotOffset;
  world_incomplete.state->denied_exact_size = sizeof(std::uintptr_t);
  require(validate(world_incomplete).reason ==
      probe::readiness_reason::world_endpoint_incomplete,
      "world_incomplete_reason_collapsed");

  auto replay_unresolved = make_fixture();
  const auto& replay_pattern = replay_unresolved.baseline.replay_pattern;
  std::fill_n(
      replay_unresolved.state->regions.at(kModule).begin() +
          static_cast<std::ptrdiff_t>(kReplayHitOffset),
      replay_pattern.bytes.size(),
      std::byte{0xCCU});
  require(validate(replay_unresolved).reason ==
      probe::readiness_reason::replay_endpoint_unresolved,
      "replay_unresolved_reason_collapsed");

  auto replay_incomplete = make_fixture();
  replay_incomplete.state->denied_exact_read = kModule + kReplaySlotOffset;
  replay_incomplete.state->denied_exact_size = sizeof(std::uintptr_t);
  require(validate(replay_incomplete).reason ==
      probe::readiness_reason::replay_endpoint_incomplete,
      "replay_incomplete_reason_collapsed");
}

void post_capture_active_identity_is_revalidated() {
  auto fixture = make_fixture();
  fixture.state->zero_on_second_exact_read = kFish + 0x189U;
  const auto result = validate(fixture);
  require(result.patterns_unique && result.fish_identity_ready &&
      !result.snapshot_ready && result.reason ==
          probe::readiness_reason::coherent_snapshot_unavailable,
      "post_capture_active_identity_not_revalidated");
}

void unreadable_second_exact_fish_cannot_hide_from_uniqueness() {
  auto fixture = make_fixture();
  constexpr std::uintptr_t second_fish = 0x290000U;
  constexpr std::uintptr_t second_archetype = 0x2A0000U;
  write_value(
      fixture.state->regions.at(kInterface),
      0x18U,
      std::int32_t{2});
  auto list = std::vector<std::byte>(0x20U);
  write_value(list, 0U, kFish);
  write_value(list, 0x10U, second_fish);
  fixture.state->regions[kEntityList] = std::move(list);
  add_fish(*fixture.state, second_fish, second_archetype, 15.0F);
  fixture.state->denied_exact_read = second_fish + 0x90U;
  fixture.state->denied_exact_size = sizeof(float) * 3U;

  const auto result = validate(fixture);
  require(result.patterns_unique && !result.fish_identity_ready &&
      !result.snapshot_ready && result.reason ==
          probe::readiness_reason::active_fish_unavailable,
      "unreadable_exact_fish_hidden_from_uniqueness");
}

}  // namespace

int main() {
  try {
    exact_candidate_proves_unique_coherent_snapshot();
    already_admitted_hash_and_mutated_baseline_are_rejected();
    world_endpoints_must_collapse_to_one_distinct_player();
    replay_signature_must_be_exactly_one();
    fish_enumeration_has_no_count_fallback_and_requires_one_identity();
    unreadable_non_executable_data_does_not_block_scan();
    permanent_executable_hole_fails_closed();
    transient_executable_read_recovers_with_bounded_splits();
    pattern_wildcard_crossing_scan_chunk_is_found();
    malformed_pe_layout_is_rejected();
    scanner_reason_keys_are_stage_specific_and_sanitized();
    world_and_replay_endpoint_failures_are_stage_specific();
    post_capture_active_identity_is_revalidated();
    unreadable_second_exact_fish_cannot_hide_from_uniqueness();
    return 0;
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
