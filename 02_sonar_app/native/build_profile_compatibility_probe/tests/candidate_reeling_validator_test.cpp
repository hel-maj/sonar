#include "candidate_reeling_validator.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
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
constexpr std::size_t kModuleSize = 64U * 1024U;
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

struct fake_state final {
  memory::process_identity identity;
  std::map<std::uintptr_t, std::vector<std::byte>> regions;
  bool generation_current{true};
  std::optional<std::uintptr_t> zero_on_second_exact_read;
  std::size_t watched_exact_reads{};
  std::optional<std::uintptr_t> denied_exact_read;
  std::size_t denied_exact_size{};
};

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

  auto module = std::vector<std::byte>(kModuleSize, std::byte{0xCCU});
  materialize_pattern(
      module, 0x100U, baseline->world_patterns.front(), 0x800U, kWorld);
  materialize_pattern(
      module, 0x300U, baseline->replay_pattern, 0x900U, kReplay);
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
      0x500U,
      same.baseline.world_patterns.front(),
      0xA00U,
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
      0x500U,
      distinct.baseline.world_patterns.front(),
      0xA00U,
      second_world);
  add_player(*distinct.state, second_world, second_player);
  const auto distinct_result = validate(distinct);
  require(!distinct_result.patterns_unique &&
      distinct_result.reason == probe::readiness_reason::pattern_ambiguous,
      "distinct_player_endpoints_not_rejected");
}

void replay_signature_must_be_exactly_one() {
  auto fixture = make_fixture();
  auto& module = fixture.state->regions.at(kModule);
  materialize_pattern(
      module,
      0x600U,
      fixture.baseline.replay_pattern,
      0xB00U,
      kReplay);
  const auto result = validate(fixture);
  require(!result.patterns_unique &&
      result.reason == probe::readiness_reason::pattern_ambiguous,
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

void incomplete_module_scan_fails_closed() {
  auto fixture = make_fixture();
  fixture.state->regions.at(kModule).resize(kModuleSize - 1U);
  const auto result = validate(fixture);
  require(!result.patterns_unique &&
      result.reason == probe::readiness_reason::pattern_scan_incomplete,
      "incomplete_module_scan_not_rejected");
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
    incomplete_module_scan_fails_closed();
    post_capture_active_identity_is_revalidated();
    unreadable_second_exact_fish_cannot_hide_from_uniqueness();
    return 0;
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
