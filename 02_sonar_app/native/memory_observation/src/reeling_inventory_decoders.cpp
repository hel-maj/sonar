#include "sonar/fishing/memory_observation/memory_observation.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <span>

#include "decoder_support.h"

namespace sonar::fishing::memory_observation {
namespace {

using decoder_support::read_scalar;

[[nodiscard]] std::optional<vector3> read_vector3(
    const std::span<const std::byte> bytes,
    const std::size_t offset) noexcept {
  const auto x = read_scalar<float>(bytes, offset);
  const auto y = read_scalar<float>(bytes, offset + sizeof(float));
  const auto z = read_scalar<float>(bytes, offset + sizeof(float) * 2U);
  if (!x.has_value() || !y.has_value() || !z.has_value() ||
      !std::isfinite(*x) || !std::isfinite(*y) || !std::isfinite(*z)) {
    return std::nullopt;
  }
  return vector3{
      .x = static_cast<double>(*x),
      .y = static_cast<double>(*y),
      .z = static_cast<double>(*z),
  };
}

}  // namespace

std::optional<reeling_evidence> decode_reeling_evidence(
    const std::span<const std::byte> player,
    const std::span<const std::byte> fish,
    const reeling_layout& layout) noexcept {
  if (!std::isfinite(layout.maximum_distance) ||
      layout.maximum_distance <= 0.0) {
    return std::nullopt;
  }
  const auto active = read_scalar<std::uint8_t>(fish, layout.fish_active_offset);
  const auto model_hash =
      read_scalar<std::uint32_t>(fish, layout.fish_model_hash_offset);
  if (!active.has_value() || *active > 1U || !model_hash.has_value() ||
      *model_hash != layout.expected_fish_model_hash) {
    return std::nullopt;
  }
  reeling_evidence result{
      .active = *active == 1U,
      .fish_model_confirmed = true,
  };
  if (!result.active) {
    return result;
  }
  const auto player_position =
      read_vector3(player, layout.player_position_offset);
  const auto fish_position = read_vector3(fish, layout.fish_position_offset);
  const auto right_x = read_scalar<float>(player, layout.player_right_offset);
  const auto right_y = read_scalar<float>(
      player, layout.player_right_offset + sizeof(float));
  if (!player_position.has_value() || !fish_position.has_value() ||
      !right_x.has_value() || !right_y.has_value() ||
      !std::isfinite(*right_x) || !std::isfinite(*right_y)) {
    return std::nullopt;
  }
  const double right_length = std::hypot(
      static_cast<double>(*right_x), static_cast<double>(*right_y));
  if (!(right_length > 0.45 && right_length < 1.55) ||
      std::abs(*right_x) > 1.2F || std::abs(*right_y) > 1.2F) {
    return std::nullopt;
  }
  const double dx = fish_position->x - player_position->x;
  const double dy = fish_position->y - player_position->y;
  const double dz = fish_position->z - player_position->z;
  const double distance = std::sqrt(dx * dx + dy * dy + dz * dz);
  if (!std::isfinite(distance) || distance > layout.maximum_distance) {
    return std::nullopt;
  }
  result.player_position = *player_position;
  result.fish_position = *fish_position;
  result.player_right_x = static_cast<double>(*right_x) / right_length;
  result.player_right_y = static_cast<double>(*right_y) / right_length;
  result.distance = distance;
  return result;
}

std::optional<inventory_evidence> decode_inventory_evidence(
    const std::span<const std::byte> samples,
    const std::span<const inventory_candidate> candidates,
    const std::size_t minimum_votes,
    const double minimum_confidence) noexcept {
  if (samples.size() != candidates.size() || candidates.empty() ||
      candidates.size() > maximum_inventory_candidates || minimum_votes == 0U ||
      minimum_votes > candidates.size() ||
      !std::isfinite(minimum_confidence) || minimum_confidence < 0.5 ||
      minimum_confidence > 1.0) {
    return std::nullopt;
  }
  double open_votes = 0.0;
  double closed_votes = 0.0;
  std::size_t matched = 0U;
  for (std::size_t index = 0U; index < candidates.size(); ++index) {
    const auto& candidate = candidates[index];
    if (candidate.open_value == candidate.closed_value ||
        !std::isfinite(candidate.weight) || candidate.weight <= 0.0) {
      return std::nullopt;
    }
    const auto value = static_cast<std::uint8_t>(samples[index]);
    if (value == candidate.open_value) {
      open_votes += candidate.weight;
      ++matched;
    } else if (value == candidate.closed_value) {
      closed_votes += candidate.weight;
      ++matched;
    }
  }
  const double total = open_votes + closed_votes;
  if (matched < minimum_votes || !(total > 0.0)) {
    return std::nullopt;
  }
  const double confidence = std::max(open_votes, closed_votes) / total;
  if (!std::isfinite(confidence) || confidence < minimum_confidence) {
    return std::nullopt;
  }
  return inventory_evidence{
      .open = open_votes > closed_votes,
      .matched_votes = matched,
      .confidence = confidence,
  };
}

}  // namespace sonar::fishing::memory_observation
