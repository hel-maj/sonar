#include "sonar/fishing/memory_observation/memory_observation.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace observation = sonar::fishing::memory_observation;

namespace {

struct fixture_row final {
  std::vector<std::string> columns;
};

[[nodiscard]] std::vector<std::string> split_tabs(const std::string& line) {
  std::vector<std::string> result;
  std::size_t begin = 0U;
  for (;;) {
    const auto end = line.find('\t', begin);
    if (end == std::string::npos) {
      result.push_back(line.substr(begin));
      return result;
    }
    result.push_back(line.substr(begin, end - begin));
    begin = end + 1U;
  }
}

[[nodiscard]] std::vector<fixture_row> load_fixture() {
  std::ifstream input(SONAR_FISHING_MEMORY_OBSERVATION_FIXTURE);
  if (!input) {
    throw std::runtime_error("fixture_open_failed");
  }
  std::vector<fixture_row> rows;
  std::string line;
  while (std::getline(input, line)) {
    if (!line.empty() && line.front() != '#') {
      rows.push_back(fixture_row{.columns = split_tabs(line)});
    }
  }
  return rows;
}

[[nodiscard]] std::string load_build_profile_fixture() {
  std::ifstream input(
      SONAR_FISHING_MEMORY_BUILD_PROFILE_FIXTURE,
      std::ios::binary);
  if (!input) {
    throw std::runtime_error("build_profile_fixture_open_failed");
  }
  return std::string(
      std::istreambuf_iterator<char>(input),
      std::istreambuf_iterator<char>());
}

[[nodiscard]] unsigned char hex_nibble(const char value) {
  if (value >= '0' && value <= '9') {
    return static_cast<unsigned char>(value - '0');
  }
  if (value >= 'a' && value <= 'f') {
    return static_cast<unsigned char>(value - 'a' + 10);
  }
  if (value >= 'A' && value <= 'F') {
    return static_cast<unsigned char>(value - 'A' + 10);
  }
  throw std::runtime_error("fixture_hex_invalid");
}

[[nodiscard]] std::vector<std::byte> decode_hex(const std::string_view value) {
  if (value.size() % 2U != 0U) {
    throw std::runtime_error("fixture_hex_length_invalid");
  }
  std::vector<std::byte> result(value.size() / 2U);
  for (std::size_t index = 0U; index < result.size(); ++index) {
    result[index] = static_cast<std::byte>(
        (hex_nibble(value[index * 2U]) << 4U) |
        hex_nibble(value[index * 2U + 1U]));
  }
  return result;
}

[[nodiscard]] bool parse_bool(const std::string_view value) {
  if (value == "true") {
    return true;
  }
  if (value == "false") {
    return false;
  }
  throw std::runtime_error("fixture_bool_invalid");
}

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

[[nodiscard]] const fixture_row& find_row(
    const std::vector<fixture_row>& rows,
    const std::string_view kind,
    const std::string_view name) {
  const auto found = std::find_if(rows.begin(), rows.end(), [&](const auto& row) {
    return row.columns.size() >= 2U && row.columns[0] == kind &&
        row.columns[1] == name;
  });
  if (found == rows.end()) {
    throw std::runtime_error("fixture_case_missing");
  }
  return *found;
}

[[nodiscard]] observation::reeling_layout fixture_reeling_layout() {
  return observation::reeling_layout{
      .player_position_offset = 0U,
      .player_right_offset = 12U,
      .fish_position_offset = 0U,
      .fish_model_hash_offset = 12U,
      .fish_active_offset = 16U,
      .expected_fish_model_hash = 802685111U,
      .maximum_distance = 120.0,
  };
}

[[nodiscard]] std::vector<observation::inventory_candidate>
fixture_inventory_candidates() {
  return std::vector<observation::inventory_candidate>(
      8U,
      observation::inventory_candidate{
          .closed_value = 1U,
          .open_value = 2U,
          .weight = 1.0,
      });
}

void test_language_neutral_fixture_parity(
    const std::vector<fixture_row>& rows) {
  const auto& reeling = find_row(rows, "reeling", "legacy_world_motion");
  require(reeling.columns.size() == 6U, "reeling_fixture_shape");
  const auto player = decode_hex(reeling.columns[2]);
  const auto fish = decode_hex(reeling.columns[3]);
  const auto decoded_reeling = observation::decode_reeling_evidence(
      player, fish, fixture_reeling_layout());
  require(decoded_reeling.has_value(), "reeling_fixture_decode");
  require(
      decoded_reeling->active == parse_bool(reeling.columns[4]),
      "reeling_fixture_active");
  require(
      std::abs(decoded_reeling->distance - std::stod(reeling.columns[5])) < 1e-9,
      "reeling_fixture_distance");
  require(
      std::abs(decoded_reeling->player_right_x - 1.0) < 1e-9 &&
          std::abs(decoded_reeling->player_right_y) < 1e-9,
      "reeling_fixture_right_vector");

  const auto& inventory =
      find_row(rows, "inventory", "legacy_weighted_open");
  require(inventory.columns.size() == 6U, "inventory_fixture_shape");
  const auto samples = decode_hex(inventory.columns[2]);
  const auto candidates = fixture_inventory_candidates();
  const auto decoded_inventory = observation::decode_inventory_evidence(
      samples, candidates, 6U, 0.85);
  require(decoded_inventory.has_value(), "inventory_fixture_decode");
  require(
      decoded_inventory->open == parse_bool(inventory.columns[3]),
      "inventory_fixture_state");
  require(
      decoded_inventory->matched_votes ==
          static_cast<std::size_t>(std::stoull(inventory.columns[4])),
      "inventory_fixture_votes");
  require(
      std::abs(decoded_inventory->confidence - std::stod(inventory.columns[5])) <
          1e-9,
      "inventory_fixture_confidence");

  const auto& status =
      find_row(rows, "player_status", "legacy_webengine_status");
  require(status.columns.size() == 10U, "status_fixture_shape");
  const auto status_window = decode_hex(status.columns[2]);
  const std::vector<std::vector<std::byte>> no_samples;
  const std::vector<observation::status_candidate> no_candidates;
  const auto decoded_status = observation::decode_player_status_evidence(
      no_samples, no_candidates, status_window);
  require(decoded_status.has_value(), "status_fixture_decode");
  require(decoded_status->food == std::stoi(status.columns[3]), "status_food");
  require(decoded_status->water == std::stoi(status.columns[4]), "status_water");
  require(decoded_status->health == std::stoi(status.columns[5]), "status_health");
  require(
      decoded_status->inventory_weight.has_value() &&
          std::abs(*decoded_status->inventory_weight -
                   std::stod(status.columns[6])) < 1e-9,
      "status_inventory_weight");
  require(
      decoded_status->inventory_weight_max.has_value() &&
          std::abs(*decoded_status->inventory_weight_max -
                   std::stod(status.columns[7])) < 1e-9,
      "status_inventory_max");
  require(
      decoded_status->backpack_weight.has_value() &&
          std::abs(*decoded_status->backpack_weight -
                   std::stod(status.columns[8])) < 1e-9,
      "status_backpack_weight");
  require(
      decoded_status->backpack_weight_max.has_value() &&
          std::abs(*decoded_status->backpack_weight_max -
                   std::stod(status.columns[9])) < 1e-9,
      "status_backpack_max");

  const std::vector<std::vector<std::byte>> scalar_samples{
      {std::byte{40U}},
      {std::byte{40U}},
      {std::byte{41U}},
      {std::byte{70U}},
      {std::byte{60U}},
  };
  const std::vector<observation::status_candidate> scalar_candidates{
      {observation::player_status_field::food,
       observation::scalar_type::u8, 1.0, 0.0, 0.0, 100.0},
      {observation::player_status_field::food,
       observation::scalar_type::u8, 1.0, 0.0, 0.0, 100.0},
      {observation::player_status_field::food,
       observation::scalar_type::u8, 1.0, 0.0, 0.0, 100.0},
      {observation::player_status_field::water,
       observation::scalar_type::u8, 1.0, 0.0, 0.0, 100.0},
      {observation::player_status_field::health,
       observation::scalar_type::u8, 1.0, 0.0, 0.0, 100.0},
  };
  const auto decoded_scalars = observation::decode_player_status_evidence(
      scalar_samples,
      scalar_candidates,
      std::span<const std::byte>{});
  require(
      decoded_scalars.has_value() && decoded_scalars->food == 40 &&
          decoded_scalars->water == 70 && decoded_scalars->health == 60,
      "status_scalar_vote_parity");

  auto invalid_field_candidates = scalar_candidates;
  invalid_field_candidates.front().field =
      static_cast<observation::player_status_field>(255U);
  require(
      !observation::decode_player_status_evidence(
           scalar_samples,
           invalid_field_candidates,
           std::span<const std::byte>{})
           .has_value(),
      "invalid_status_field_rejected");

  for (const auto& row : rows) {
    if (row.columns.empty() || row.columns[0] != "chat") {
      continue;
    }
    require(row.columns.size() == 7U, "chat_fixture_shape");
    const auto bytes = decode_hex(row.columns[2]);
    const auto decoded_chat = observation::decode_chat_evidence(bytes);
    require(decoded_chat.has_value(), "chat_fixture_decode");
    require(
        decoded_chat->input_active == parse_bool(row.columns[3]),
        "chat_fixture_input");
    require(
        decoded_chat->visible == parse_bool(row.columns[4]),
        "chat_fixture_visible");
    require(
        (row.columns[5] == "-" && decoded_chat->active_tab_id.empty()) ||
            decoded_chat->active_tab_id == row.columns[5],
        "chat_fixture_tab");
    const auto expected_confidence = row.columns[6] == "high"
        ? observation::chat_confidence::high
        : observation::chat_confidence::medium;
    require(
        decoded_chat->confidence == expected_confidence,
        "chat_fixture_confidence");
  }
}

struct fake_process_state final {
  observation::process_identity identity;
  std::map<std::uintptr_t, std::vector<std::byte>> memory;
  std::vector<sonar::platform::windows::memory_region_snapshot> regions;
  std::size_t region_queries{};
  bool generation_current{true};
};

class fake_session final : public observation::readonly_memory_session {
 public:
  explicit fake_session(std::shared_ptr<fake_process_state> state)
      : state_(std::move(state)) {}

  [[nodiscard]] const observation::process_identity& identity()
      const noexcept override {
    return state_->identity;
  }

  [[nodiscard]] bool read_exact(
      const std::uintptr_t address,
      const std::span<std::byte> destination) noexcept override {
    auto found = state_->memory.upper_bound(address);
    if (found == state_->memory.begin()) {
      return false;
    }
    --found;
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

  [[nodiscard]] std::optional<
      sonar::platform::windows::memory_region_snapshot>
  query_region(const std::uintptr_t address) noexcept override {
    ++state_->region_queries;
    const auto found = std::ranges::find_if(
        state_->regions,
        [address](const auto& region) {
          return address >= region.base_address &&
              address - region.base_address < region.size;
        });
    return found == state_->regions.end()
        ? std::nullopt
        : std::optional(*found);
  }

  [[nodiscard]] bool generation_current() noexcept override {
    return state_->generation_current;
  }

 private:
  std::shared_ptr<fake_process_state> state_;
};

class fake_connector final : public observation::memory_connector {
 public:
  fake_connector(
      std::shared_ptr<fake_process_state> game,
      std::shared_ptr<fake_process_state> webengine)
      : game_(std::move(game)), webengine_(std::move(webengine)) {}

  [[nodiscard]] std::unique_ptr<observation::readonly_memory_session> connect(
      const observation::process_role role,
      const std::uint32_t process_id,
      std::string& reason) noexcept override {
    const auto& state = role == observation::process_role::game
        ? game_
        : webengine_;
    if (!state || state->identity.generation.process_id != process_id) {
      reason = "fake_process_unavailable";
      return nullptr;
    }
    ++connect_count_;
    reason = "ready";
    return std::make_unique<fake_session>(state);
  }

  [[nodiscard]] std::size_t connect_count() const noexcept {
    return connect_count_;
  }

 private:
  std::shared_ptr<fake_process_state> game_;
  std::shared_ptr<fake_process_state> webengine_;
  std::size_t connect_count_{};
};

[[nodiscard]] observation::memory_observation_profile fixture_profile() {
  return observation::memory_observation_profile{
      .profile_id = "majestic-e11-fixture-v1",
      .profile_revision = 1U,
      .game = observation::expected_process{
          .image_name = L"gta5.exe",
          .image_sha256 = std::string(64U, 'a'),
          .required = true,
      },
      .webengine = observation::expected_process{
          .image_name = L"majestic-webengine.exe",
          .image_sha256 = std::string(64U, 'b'),
          .required = true,
      },
      .reeling = fixture_reeling_layout(),
      .inventory_candidates = fixture_inventory_candidates(),
      .status_candidates = {},
      .minimum_inventory_votes = 6U,
      .minimum_inventory_confidence = 0.85,
      .require_reeling = true,
      .require_inventory = true,
      .require_player_status = true,
      .require_chat = true,
  };
}

struct fixture_runtime final {
  std::shared_ptr<fake_process_state> game;
  std::shared_ptr<fake_process_state> webengine;
  observation::capture_plan plan;
};

[[nodiscard]] fixture_runtime make_runtime_fixture(
    const std::vector<fixture_row>& rows) {
  const auto& reeling = find_row(rows, "reeling", "legacy_world_motion");
  const auto& inventory =
      find_row(rows, "inventory", "legacy_weighted_open");
  const auto& status =
      find_row(rows, "player_status", "legacy_webengine_status");
  const auto& chat =
      find_row(rows, "chat", "legacy_serialized_state");
  auto game = std::make_shared<fake_process_state>();
  game->identity = observation::process_identity{
      .role = observation::process_role::game,
      .generation = {
          .process_id = 101U,
          .creation_time_filetime_100ns = 111U,
      },
      .image_name = L"GTA5.EXE",
      .image_sha256 = std::string(64U, 'A'),
  };
  game->memory[0x1000U] = decode_hex(reeling.columns[2]);
  game->memory[0x2000U] = decode_hex(reeling.columns[3]);
  const auto inventory_bytes = decode_hex(inventory.columns[2]);

  auto webengine = std::make_shared<fake_process_state>();
  webengine->identity = observation::process_identity{
      .role = observation::process_role::webengine,
      .generation = {
          .process_id = 202U,
          .creation_time_filetime_100ns = 222U,
      },
      .image_name = L"MAJESTIC-WEBENGINE.EXE",
      .image_sha256 = std::string(64U, 'B'),
  };
  webengine->memory[0x4000U] = decode_hex(status.columns[2]);
  webengine->memory[0x5000U] = decode_hex(chat.columns[2]);

  observation::capture_plan plan{
      .sequence = 7U,
      .captured_at_steady_ns = 9000U,
      .game_process_id = 101U,
      .webengine_process_id = 202U,
      .expected_game_generation = {
          .process_id = 101U,
          .creation_time_filetime_100ns = 111U,
      },
      .expected_webengine_generation =
          sonar::platform::windows::process_generation{
              .process_id = 202U,
              .creation_time_filetime_100ns = 222U,
          },
      .regions = {
          {observation::evidence_region_kind::reeling_player,
           observation::process_role::game, 0U, 0x1000U,
           game->memory[0x1000U].size()},
          {observation::evidence_region_kind::reeling_fish,
           observation::process_role::game, 0U, 0x2000U,
           game->memory[0x2000U].size()},
          {observation::evidence_region_kind::player_status_window,
           observation::process_role::webengine, 0U, 0x4000U,
           webengine->memory[0x4000U].size()},
          {observation::evidence_region_kind::chat_state_window,
           observation::process_role::webengine, 0U, 0x5000U,
           webengine->memory[0x5000U].size()},
      },
  };
  for (std::size_t index = 0U; index < inventory_bytes.size(); ++index) {
    const auto address = 0x3000U + index;
    game->memory[address] = {inventory_bytes[index]};
    plan.regions.push_back(observation::read_region{
        .kind = observation::evidence_region_kind::inventory_candidate,
        .role = observation::process_role::game,
        .slot = static_cast<std::uint32_t>(index),
        .address = address,
        .size = 1U,
    });
  }
  return fixture_runtime{
      .game = std::move(game),
      .webengine = std::move(webengine),
      .plan = std::move(plan),
  };
}

void test_coherent_snapshot_and_replay_rejection(
    const std::vector<fixture_row>& rows) {
  auto fixture = make_runtime_fixture(rows);
  fake_connector connector(fixture.game, fixture.webengine);
  observation::memory_observer observer(connector);
  const auto profile = fixture_profile();

  const auto captured = observer.capture(profile, fixture.plan);
  require(captured.ready(), "coherent_snapshot_ready");
  require(captured.snapshot->sequence == 7U, "coherent_snapshot_sequence");
  require(
      captured.snapshot->game_generation == fixture.game->identity.generation,
      "coherent_snapshot_game_generation");
  require(
      captured.snapshot->webengine_generation ==
          fixture.webengine->identity.generation,
      "coherent_snapshot_webengine_generation");
  require(
      captured.snapshot->reeling.has_value() &&
          captured.snapshot->inventory.has_value() &&
          captured.snapshot->player_status.has_value() &&
          captured.snapshot->chat.has_value(),
      "coherent_snapshot_union");

  fixture.plan.sequence = 8U;
  fixture.plan.captured_at_steady_ns = 9001U;
  const auto next = observer.capture(profile, fixture.plan);
  require(next.ready(), "coherent_snapshot_next_ready");
  require(connector.connect_count() == 2U, "coherent_sessions_reused");

  const auto replayed = observer.capture(profile, fixture.plan);
  require(
      replayed.failure == observation::capture_failure::sequence_replayed,
      "coherent_snapshot_replay_rejected");
}

void test_embedded_build_registry_contract() {
  const auto fixture = load_build_profile_fixture();
  require(
      fixture == observation::embedded_memory_build_profile_canonical_tsv(),
      "build_profile_canonical_fixture_drift");
  require(
      observation::embedded_build_profile_registry_sha256 ==
          std::string_view(SONAR_FISHING_MEMORY_BUILD_PROFILE_SHA256),
      "build_profile_hash_pin_drift");
  const auto profiles = observation::embedded_memory_build_profiles();
  require(profiles.size() == 1U, "build_profile_count_changed");
  const auto& profile = profiles.front();
  require(
      profile.schema_version == 2U &&
          profile.profile_id == "majestic-gta5-677e4e35-v1" &&
          profile.profile_revision == 1U &&
          profile.fish_model_hash == 802685111U &&
          profile.fish_active_offset == 0x189U &&
          profile.world_patterns.size() == 5U &&
          profile.replay_pattern.bytes.size() == 36U &&
          !profile.inventory_binding.has_value(),
      "build_profile_payload_changed");
  const auto selected = observation::select_embedded_memory_build_profile(
      L"gta5.EXE", profile.game.image_sha256);
  require(selected.ready() && selected.profile == &profile,
          "exact_build_profile_not_selected");
  const auto unsupported = observation::select_embedded_memory_build_profile(
      L"GTA5.exe", std::string(64U, '0'));
  require(
      !unsupported.ready() &&
          unsupported.reason == "memory_game_build_unsupported",
      "unsupported_build_not_fail_closed");
}

constexpr std::uintptr_t inventory_scan_base = 0x10000000000ULL;

[[nodiscard]] observation::embedded_inventory_binding
fixture_inventory_binding() {
  observation::masked_memory_pattern pattern;
  pattern.bytes.assign(34U, 0x5AU);
  pattern.bytes[16U] = -1;
  pattern.bytes[17U] = -1;
  return {
      .minimum_address_inclusive = inventory_scan_base,
      .maximum_address_exclusive = inventory_scan_base + 0x2000U,
      .maximum_scanned_bytes = 0x1000U,
      .maximum_region_bytes = 0x1000U,
      .maximum_enumerated_regions = 4U,
      .maximum_pattern_hits = 12U,
      .slot_stride = 0x100U,
      .slot_count = 3U,
      .slot_pattern = std::move(pattern),
      .signals = {
          {16U, {0U, 128U, 1.0}},
          {17U, {0U, 63U, 1.0}},
      },
      .minimum_votes = 6U,
      .minimum_confidence = 0.85,
  };
}

void materialize_inventory_slot(
    std::vector<std::byte>& region,
    const std::size_t offset,
    const observation::embedded_inventory_binding& binding,
    const bool open) {
  require(
      offset <= region.size() &&
          binding.slot_pattern.bytes.size() <= region.size() - offset,
      "inventory_slot_fixture_range_invalid");
  for (std::size_t index = 0U;
       index < binding.slot_pattern.bytes.size();
       ++index) {
    const auto value = binding.slot_pattern.bytes[index];
    region[offset + index] = value < 0
        ? std::byte{0U}
        : static_cast<std::byte>(value);
  }
  for (const auto& signal : binding.signals) {
    region[offset + signal.offset] = static_cast<std::byte>(
        open ? signal.candidate.open_value : signal.candidate.closed_value);
  }
}

[[nodiscard]] std::shared_ptr<fake_process_state>
make_inventory_binding_process(
    const observation::embedded_memory_build_profile& profile,
    const observation::embedded_inventory_binding& binding,
    const bool ambiguous) {
  auto game = std::make_shared<fake_process_state>();
  game->identity = {
      .role = observation::process_role::game,
      .generation = {303U, 333U},
      .image_name = L"GTA5.exe",
      .image_sha256 = profile.game.image_sha256,
      .modules = {{
          L"GTA5.exe", L"C:\\fixture\\GTA5.exe", 0x140000000ULL, 0x1000U}},
  };
  auto& bytes = game->memory[inventory_scan_base];
  bytes.assign(0x1000U, std::byte{0U});
  for (const auto offset : std::array{0x100U, 0x200U, 0x300U}) {
    materialize_inventory_slot(bytes, offset, binding, true);
  }
  if (ambiguous) {
    for (const auto offset : std::array{0x500U, 0x600U, 0x700U}) {
      materialize_inventory_slot(bytes, offset, binding, false);
    }
  }
  game->regions = {
      {inventory_scan_base, 0x1000U, 0x1000U, 0x04U, 0x20000U},
      {inventory_scan_base + 0x1000U, 0x1000U, 0U, 0x01U, 0U},
  };
  return game;
}

void test_inventory_scope_discovery_and_recovery() {
  auto profile = observation::embedded_memory_build_profiles().front();
  profile.inventory_binding = fixture_inventory_binding();
  auto game = make_inventory_binding_process(
      profile, *profile.inventory_binding, false);
  fake_connector connector(game, nullptr);
  observation::memory_capture_plan_resolver resolver(
      connector,
      std::span<const observation::embedded_memory_build_profile>{
          &profile, 1U});

  const auto first = resolver.resolve_inventory(1U, 100U,
      game->identity.generation);
  require(first.ready() && first.profile->require_inventory &&
          !first.profile->require_reeling &&
          first.profile->inventory_candidates.size() == 6U &&
          first.plan->regions.size() == 6U,
      "inventory_binding_not_resolved_independently");
  const auto queries_after_discovery = game->region_queries;

  observation::memory_observer observer(connector);
  const auto captured = observer.capture(*first.profile, *first.plan);
  require(captured.ready() && captured.snapshot->inventory.has_value() &&
          captured.snapshot->inventory->open &&
          captured.snapshot->inventory->matched_votes == 6U &&
          captured.snapshot->inventory->confidence == 1.0,
      "inventory_binding_open_state_not_decoded");

  const auto cached = resolver.resolve_inventory(2U, 200U,
      game->identity.generation);
  require(cached.ready() && game->region_queries == queries_after_discovery,
      "inventory_binding_cache_redid_cold_scan");

  auto& bytes = game->memory.at(inventory_scan_base);
  std::fill(bytes.begin(), bytes.end(), std::byte{0U});
  for (const auto offset : std::array{0x500U, 0x600U, 0x700U}) {
    materialize_inventory_slot(
        bytes, offset, *profile.inventory_binding, false);
  }
  const auto recovered = resolver.resolve_inventory(3U, 300U,
      game->identity.generation);
  require(recovered.ready() &&
          game->region_queries > queries_after_discovery &&
          recovered.plan->regions.front().address ==
              inventory_scan_base + 0x500U + 16U,
      "inventory_binding_did_not_rediscover_after_drift");

  observation::memory_observer recovered_observer(connector);
  const auto closed = recovered_observer.capture(
      *recovered.profile, *recovered.plan);
  require(closed.ready() && closed.snapshot->inventory.has_value() &&
          !closed.snapshot->inventory->open &&
          closed.snapshot->inventory->confidence == 1.0,
      "inventory_binding_closed_state_not_decoded");
}

void test_inventory_scope_typed_blockers() {
  auto profile = observation::embedded_memory_build_profiles().front();
  auto current_game = make_inventory_binding_process(
      profile, fixture_inventory_binding(), false);
  current_game->identity.image_sha256 =
      "8C2C3F768B87F060D678D9E175842AA20449CF5BC164C630692A494EB353D472";
  fake_connector current_connector(current_game, nullptr);
  observation::memory_capture_plan_resolver current(
      current_connector,
      std::span<const observation::embedded_memory_build_profile>{
          &profile, 1U});
  const auto unsupported = current.resolve_inventory(
      1U, 100U, current_game->identity.generation);
  require(!unsupported.ready() &&
          unsupported.failure ==
              observation::inventory_binding_failure::profile_unavailable &&
          unsupported.reason == "memory_game_build_unsupported" &&
          current_game->region_queries == 0U,
      "current_inventory_build_blocker_was_not_typed_before_scan");

  auto game = make_inventory_binding_process(
      profile, fixture_inventory_binding(), false);
  fake_connector connector(game, nullptr);
  observation::memory_capture_plan_resolver unavailable(
      connector,
      std::span<const observation::embedded_memory_build_profile>{
          &profile, 1U});
  const auto missing = unavailable.resolve_inventory(
      1U, 100U, game->identity.generation);
  require(!missing.ready() &&
          missing.failure ==
              observation::inventory_binding_failure::profile_unavailable &&
          missing.reason == "memory_inventory_binding_unavailable" &&
          game->region_queries == 0U,
      "missing_inventory_profile_did_not_fail_typed_before_scan");

  profile.inventory_binding = fixture_inventory_binding();
  profile.inventory_binding->slot_pattern.bytes[16U] = 0U;
  auto invalid_game = make_inventory_binding_process(
      profile, *profile.inventory_binding, false);
  fake_connector invalid_connector(invalid_game, nullptr);
  observation::memory_capture_plan_resolver invalid(
      invalid_connector,
      std::span<const observation::embedded_memory_build_profile>{
          &profile, 1U});
  const auto invalid_binding = invalid.resolve_inventory(
      1U, 100U, invalid_game->identity.generation);
  require(!invalid_binding.ready() &&
          invalid_binding.failure ==
              observation::inventory_binding_failure::profile_unavailable &&
          invalid_binding.reason == "memory_inventory_binding_unavailable" &&
          invalid_game->region_queries == 0U,
      "dynamic_inventory_signal_was_admitted_as_exact_signature_byte");

  profile.inventory_binding = fixture_inventory_binding();
  auto ambiguous_game = make_inventory_binding_process(
      profile, *profile.inventory_binding, true);
  fake_connector ambiguous_connector(ambiguous_game, nullptr);
  observation::memory_capture_plan_resolver ambiguous(
      ambiguous_connector,
      std::span<const observation::embedded_memory_build_profile>{
          &profile, 1U});
  const auto rejected = ambiguous.resolve_inventory(
      1U, 100U, ambiguous_game->identity.generation);
  const auto queries_after_rejection = ambiguous_game->region_queries;
  require(!rejected.ready() &&
          rejected.failure ==
              observation::inventory_binding_failure::signature_ambiguous &&
          rejected.reason == "memory_inventory_signature_ambiguous",
      "ambiguous_inventory_signature_was_admitted");
  const auto throttled = ambiguous.resolve_inventory(
      2U, 200U, ambiguous_game->identity.generation);
  require(!throttled.ready() &&
          throttled.failure == rejected.failure &&
          ambiguous_game->region_queries == queries_after_rejection,
      "failed_inventory_discovery_was_repeated_without_cooldown");
  const auto retried = ambiguous.resolve_inventory(
      3U, 5'000'000'200ULL, ambiguous_game->identity.generation);
  require(!retried.ready() &&
          retried.failure == rejected.failure &&
          ambiguous_game->region_queries > queries_after_rejection,
      "failed_inventory_discovery_did_not_retry_after_cooldown");
}

void test_independent_fish_identity_projection(
    const std::vector<fixture_row>& rows) {
  auto fixture = make_runtime_fixture(rows);
  auto& fish = fixture.game->memory.at(0x2000U);
  std::fill(fish.begin() + 12, fish.begin() + 16, std::byte{0U});
  std::vector<std::byte> identity(sizeof(std::uint32_t));
  const std::uint32_t hash = 802685111U;
  std::memcpy(identity.data(), &hash, sizeof(hash));
  fixture.game->memory[0x2500U] = identity;
  fixture.plan.regions.push_back({
      observation::evidence_region_kind::reeling_fish_identity,
      observation::process_role::game,
      0U,
      0x2500U,
      sizeof(hash),
  });
  fake_connector connector(fixture.game, fixture.webengine);
  observation::memory_observer observer(connector);
  const auto projected = observer.capture(fixture_profile(), fixture.plan);
  require(
      projected.ready() && projected.snapshot->reeling.has_value(),
      "independent_fish_identity_projection_failed");

  auto changed = make_runtime_fixture(rows);
  changed.game->memory[0x2500U] = std::vector<std::byte>(
      sizeof(std::uint32_t), std::byte{0U});
  changed.plan.regions.push_back({
      observation::evidence_region_kind::reeling_fish_identity,
      observation::process_role::game,
      0U,
      0x2500U,
      sizeof(std::uint32_t),
  });
  fake_connector changed_connector(changed.game, changed.webengine);
  observation::memory_observer changed_observer(changed_connector);
  const auto rejected = changed_observer.capture(
      fixture_profile(), changed.plan);
  require(
      rejected.failure == observation::capture_failure::decode_failed &&
          rejected.reason == "reeling_fish_identity_changed",
      "changed_fish_identity_not_rejected");
}

void test_negative_and_profile_drift(
    const std::vector<fixture_row>& rows) {
  {
    auto fixture = make_runtime_fixture(rows);
    fake_connector connector(fixture.game, fixture.webengine);
    observation::memory_observer observer(connector);
    auto profile = fixture_profile();
    profile.profile_revision = 0U;
    const auto result = observer.capture(profile, fixture.plan);
    require(
        result.failure == observation::capture_failure::invalid_profile,
        "profile_revision_drift_rejected");
  }
  {
    auto fixture = make_runtime_fixture(rows);
    fake_connector connector(fixture.game, fixture.webengine);
    observation::memory_observer observer(connector);
    auto profile = fixture_profile();
    profile.game.image_sha256 = std::string(64U, 'c');
    const auto result = observer.capture(profile, fixture.plan);
    require(
        result.failure == observation::capture_failure::profile_hash_mismatch,
        "profile_hash_drift_rejected");
  }
  {
    auto fixture = make_runtime_fixture(rows);
    fixture.game->memory.erase(0x2000U);
    fake_connector connector(fixture.game, fixture.webengine);
    observation::memory_observer observer(connector);
    const auto result = observer.capture(fixture_profile(), fixture.plan);
    require(
        result.failure == observation::capture_failure::read_failed,
        "short_read_rejected");
  }
  {
    auto fixture = make_runtime_fixture(rows);
    fixture.webengine->generation_current = false;
    fake_connector connector(fixture.game, fixture.webengine);
    observation::memory_observer observer(connector);
    const auto result = observer.capture(fixture_profile(), fixture.plan);
    require(
        result.failure == observation::capture_failure::process_changed,
        "generation_drift_rejected");
  }
  {
    auto fixture = make_runtime_fixture(rows);
    fixture.plan.regions.front().size =
        observation::maximum_read_region_bytes + 1U;
    fake_connector connector(fixture.game, fixture.webengine);
    observation::memory_observer observer(connector);
    const auto result = observer.capture(fixture_profile(), fixture.plan);
    require(
        result.failure == observation::capture_failure::invalid_plan,
        "oversize_read_rejected");
  }
  {
    auto fixture = make_runtime_fixture(rows);
    fixture.game->memory[0x2000U][12U] = std::byte{0U};
    fake_connector connector(fixture.game, fixture.webengine);
    observation::memory_observer observer(connector);
    const auto result = observer.capture(fixture_profile(), fixture.plan);
    require(
        result.failure == observation::capture_failure::decode_failed,
        "unknown_fish_hash_rejected");
  }
  {
    const std::vector<std::byte> invalid_utf8{std::byte{0xFFU}};
    require(
        !observation::decode_chat_evidence(invalid_utf8).has_value(),
        "invalid_utf8_rejected");
  }
  {
    const std::vector<std::byte> split_votes{
        std::byte{1U}, std::byte{1U}, std::byte{1U}, std::byte{1U},
        std::byte{2U}, std::byte{2U}, std::byte{2U}, std::byte{2U},
    };
    const auto candidates = fixture_inventory_candidates();
    require(
        !observation::decode_inventory_evidence(
             split_votes, candidates, 6U, 0.85)
             .has_value(),
        "ambiguous_inventory_rejected");
  }
}

void test_default_off_composition() {
  observation::disabled_memory_connector connector;
  observation::memory_observer observer(connector);
  const auto profile = fixture_profile();
  observation::capture_plan plan{
      .sequence = 1U,
      .captured_at_steady_ns = 1U,
      .game_process_id = 101U,
      .webengine_process_id = 202U,
      .expected_game_generation = {
          .process_id = 101U,
          .creation_time_filetime_100ns = 111U,
      },
      .expected_webengine_generation =
          sonar::platform::windows::process_generation{
              .process_id = 202U,
              .creation_time_filetime_100ns = 222U,
          },
      .regions = {
          {observation::evidence_region_kind::reeling_player,
           observation::process_role::game, 0U, 0x1000U, 20U},
          {observation::evidence_region_kind::reeling_fish,
           observation::process_role::game, 0U, 0x2000U, 17U},
          {observation::evidence_region_kind::player_status_window,
           observation::process_role::webengine, 0U, 0x4000U, 256U},
          {observation::evidence_region_kind::chat_state_window,
           observation::process_role::webengine, 0U, 0x5000U, 128U},
      },
  };
  for (std::size_t index = 0U; index < 8U; ++index) {
    plan.regions.push_back(observation::read_region{
        .kind = observation::evidence_region_kind::inventory_candidate,
        .role = observation::process_role::game,
        .slot = static_cast<std::uint32_t>(index),
        .address = 0x3000U + index,
        .size = 1U,
    });
  }
  const auto result = observer.capture(profile, plan);
  require(
      result.failure == observation::capture_failure::disabled,
      "default_off_connector");
  require(
      observation::make_windows_memory_connector() != nullptr,
      "windows_connector_factory_is_inert");
}

}  // namespace

int main() {
  try {
    const auto rows = load_fixture();
    test_language_neutral_fixture_parity(rows);
    test_coherent_snapshot_and_replay_rejection(rows);
    test_embedded_build_registry_contract();
    test_inventory_scope_discovery_and_recovery();
    test_inventory_scope_typed_blockers();
    test_independent_fish_identity_projection(rows);
    test_negative_and_profile_drift(rows);
    test_default_off_composition();
    std::cout << "memory_observation tests passed\n";
    return 0;
  } catch (const std::exception& error) {
    std::cerr << "memory_observation test failed: " << error.what() << '\n';
    return 1;
  }
}
