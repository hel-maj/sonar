#include "sonar/fishing/memory_observation/memory_observation.h"

#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <span>
#include <string_view>
#include <vector>

int main() {
  namespace observation = sonar::fishing::memory_observation;
  constexpr std::size_t operations = 250'000U;
  std::array<std::byte, 20U> player{};
  std::array<std::byte, 17U> fish{};
  constexpr std::array<float, 5U> player_values{0.0F, 0.0F, 0.0F, 1.0F, 0.0F};
  constexpr std::array<float, 3U> fish_values{3.0F, 4.0F, 0.0F};
  constexpr std::uint32_t fish_hash = 802685111U;
  std::memcpy(player.data(), player_values.data(), sizeof(player_values));
  std::memcpy(fish.data(), fish_values.data(), sizeof(fish_values));
  std::memcpy(fish.data() + 12U, &fish_hash, sizeof(fish_hash));
  fish[16U] = std::byte{1U};
  constexpr observation::reeling_layout layout{
      .player_position_offset = 0U,
      .player_right_offset = 12U,
      .fish_position_offset = 0U,
      .fish_model_hash_offset = 12U,
      .fish_active_offset = 16U,
      .expected_fish_model_hash = fish_hash,
      .maximum_distance = 120.0,
  };
  const std::vector<std::byte> inventory_samples(
      8U, std::byte{2U});
  const std::vector<observation::inventory_candidate> inventory_candidates(
      8U,
      observation::inventory_candidate{
          .closed_value = 1U,
          .open_value = 2U,
          .weight = 1.0,
      });
  constexpr std::string_view chat_text =
      "{\"chatIsActive\":true,\"chatIsShow\":true,"
      "\"inputStatus\":true,\"activeFilter\":{\"id\":\"fam\"}}";
  const auto chat = std::as_bytes(
      std::span<const char>(chat_text.data(), chat_text.size()));

  double checksum = 0.0;
  const auto started = std::chrono::steady_clock::now();
  for (std::size_t index = 0U; index < operations; ++index) {
    const auto reeling =
        observation::decode_reeling_evidence(player, fish, layout);
    const auto inventory = observation::decode_inventory_evidence(
        inventory_samples, inventory_candidates, 6U, 0.85);
    const auto chat_state = observation::decode_chat_evidence(chat);
    if (reeling.has_value() && inventory.has_value() &&
        chat_state.has_value()) {
      checksum += reeling->distance + inventory->confidence +
          static_cast<double>(chat_state->active_tab_id.size());
    }
  }
  const auto elapsed = std::chrono::steady_clock::now() - started;
  const double elapsed_ms =
      std::chrono::duration<double, std::milli>(elapsed).count();
  const double ns_per_aggregate =
      std::chrono::duration<double, std::nano>(elapsed).count() /
      static_cast<double>(operations);
  std::cout << std::fixed << std::setprecision(3)
            << "METRIC memory_observation aggregates=" << operations
            << " elapsed_ms=" << elapsed_ms
            << " ns_per_aggregate=" << ns_per_aggregate
            << " checksum=" << checksum << '\n';
  return 0;
}
