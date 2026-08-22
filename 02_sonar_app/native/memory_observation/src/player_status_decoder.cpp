#include "sonar/fishing/memory_observation/memory_observation.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>
#include <span>
#include <string_view>
#include <vector>

#include "decoder_support.h"

namespace sonar::fishing::memory_observation {
namespace {

using decoder_support::ascii_alnum;
using decoder_support::ascii_space;
using decoder_support::contains;
using decoder_support::read_scalar;

[[nodiscard]] std::optional<double> decode_scalar(
    const std::span<const std::byte> bytes,
    const scalar_type type) noexcept {
  switch (type) {
    case scalar_type::u8: {
      const auto value = read_scalar<std::uint8_t>(bytes, 0U);
      return value.has_value()
          ? std::optional<double>(static_cast<double>(*value))
          : std::nullopt;
    }
    case scalar_type::i8: {
      const auto value = read_scalar<std::int8_t>(bytes, 0U);
      return value.has_value()
          ? std::optional<double>(static_cast<double>(*value))
          : std::nullopt;
    }
    case scalar_type::u16_le: {
      const auto value = read_scalar<std::uint16_t>(bytes, 0U);
      return value.has_value()
          ? std::optional<double>(static_cast<double>(*value))
          : std::nullopt;
    }
    case scalar_type::i16_le: {
      const auto value = read_scalar<std::int16_t>(bytes, 0U);
      return value.has_value()
          ? std::optional<double>(static_cast<double>(*value))
          : std::nullopt;
    }
    case scalar_type::u32_le: {
      const auto value = read_scalar<std::uint32_t>(bytes, 0U);
      return value.has_value()
          ? std::optional<double>(static_cast<double>(*value))
          : std::nullopt;
    }
    case scalar_type::i32_le: {
      const auto value = read_scalar<std::int32_t>(bytes, 0U);
      return value.has_value()
          ? std::optional<double>(static_cast<double>(*value))
          : std::nullopt;
    }
    case scalar_type::f32_le: {
      const auto value = read_scalar<float>(bytes, 0U);
      return value.has_value() && std::isfinite(*value)
          ? std::optional<double>(static_cast<double>(*value))
          : std::nullopt;
    }
    case scalar_type::f64_le: {
      const auto value = read_scalar<double>(bytes, 0U);
      return value.has_value() && std::isfinite(*value)
          ? value
          : std::nullopt;
    }
  }
  return std::nullopt;
}

[[nodiscard]] std::optional<int> legacy_vote(
    const std::vector<int>& values) noexcept {
  if (values.empty()) {
    return std::nullopt;
  }
  std::size_t best_count = 0U;
  int best = values.front();
  for (const int candidate : values) {
    const auto count = static_cast<std::size_t>(std::count(
        values.begin(), values.end(), candidate));
    if (count > best_count) {
      best_count = count;
      best = candidate;
    }
  }
  return best;
}

struct decimal_entry final {
  std::size_t position{};
  double value{};
};

[[nodiscard]] std::vector<decimal_entry> maximum_entries(
    const std::string_view bytes) {
  std::vector<decimal_entry> result;
  for (std::size_t slash = 0U; slash < bytes.size(); ++slash) {
    if (bytes[slash] != '/' ||
        (slash > 0U && ascii_alnum(static_cast<unsigned char>(bytes[slash - 1U])))) {
      continue;
    }
    std::size_t cursor = slash + 1U;
    while (cursor < bytes.size() &&
           ascii_space(static_cast<unsigned char>(bytes[cursor]))) {
      ++cursor;
    }
    const std::size_t digits_begin = cursor;
    while (cursor < bytes.size() && cursor - digits_begin < 3U &&
           bytes[cursor] >= '0' && bytes[cursor] <= '9') {
      ++cursor;
    }
    const std::size_t digits = cursor - digits_begin;
    if (digits == 0U ||
        (cursor < bytes.size() && bytes[cursor] >= '0' && bytes[cursor] <= '9')) {
      continue;
    }
    while (cursor < bytes.size() &&
           ascii_space(static_cast<unsigned char>(bytes[cursor]))) {
      ++cursor;
    }
    if (cursor < bytes.size() &&
        ascii_alnum(static_cast<unsigned char>(bytes[cursor]))) {
      continue;
    }
    int value = 0;
    for (std::size_t index = digits_begin; index < digits_begin + digits;
         ++index) {
      value = value * 10 + (bytes[index] - '0');
    }
    if (value >= 1 && value <= 500) {
      result.push_back(decimal_entry{
          .position = slash,
          .value = static_cast<double>(value),
      });
    }
  }
  return result;
}

[[nodiscard]] std::vector<decimal_entry> decimal_entries(
    const std::string_view bytes) {
  std::vector<decimal_entry> result;
  for (std::size_t begin = 0U; begin < bytes.size(); ++begin) {
    if (bytes[begin] < '0' || bytes[begin] > '9' ||
        (begin > 0U && (bytes[begin - 1U] == '.' ||
                       (bytes[begin - 1U] >= '0' &&
                        bytes[begin - 1U] <= '9')))) {
      continue;
    }
    std::size_t cursor = begin;
    while (cursor < bytes.size() && cursor - begin < 3U &&
           bytes[cursor] >= '0' && bytes[cursor] <= '9') {
      ++cursor;
    }
    if (cursor == begin || cursor >= bytes.size() || bytes[cursor] != '.') {
      continue;
    }
    const std::size_t dot = cursor++;
    const std::size_t fraction_begin = cursor;
    while (cursor < bytes.size() && cursor - fraction_begin < 2U &&
           bytes[cursor] >= '0' && bytes[cursor] <= '9') {
      ++cursor;
    }
    if (cursor == fraction_begin ||
        (cursor < bytes.size() &&
         (bytes[cursor] == '.' ||
          (bytes[cursor] >= '0' && bytes[cursor] <= '9')))) {
      continue;
    }
    double value = 0.0;
    for (std::size_t index = begin; index < dot; ++index) {
      value = value * 10.0 + static_cast<double>(bytes[index] - '0');
    }
    double divisor = 10.0;
    for (std::size_t index = fraction_begin; index < cursor; ++index) {
      value += static_cast<double>(bytes[index] - '0') / divisor;
      divisor *= 10.0;
    }
    if (value >= 0.0 && value <= 500.0) {
      result.push_back(decimal_entry{.position = begin, .value = value});
    }
  }
  return result;
}

[[nodiscard]] std::optional<decimal_entry> first_maximum(
    const std::vector<decimal_entry>& entries,
    const double expected) noexcept {
  const auto found = std::find_if(
      entries.begin(), entries.end(), [expected](const decimal_entry& entry) {
        return std::abs(entry.value - expected) < 0.01;
      });
  return found == entries.end() ? std::nullopt
                                : std::optional<decimal_entry>(*found);
}

[[nodiscard]] std::optional<decimal_entry> nearest_decimal(
    const std::vector<decimal_entry>& entries,
    const std::size_t origin,
    const double maximum,
    const std::size_t distance,
    const bool only_after,
    const std::optional<std::size_t> excluded = std::nullopt) noexcept {
  std::optional<decimal_entry> best;
  std::size_t best_distance = std::numeric_limits<std::size_t>::max();
  for (const auto& entry : entries) {
    if (entry.value > maximum ||
        (excluded.has_value() && entry.position == *excluded) ||
        (only_after && entry.position < origin)) {
      continue;
    }
    const std::size_t current_distance = entry.position >= origin
        ? entry.position - origin
        : origin - entry.position;
    if (current_distance <= distance && current_distance < best_distance) {
      best = entry;
      best_distance = current_distance;
    }
  }
  return best;
}

[[nodiscard]] std::array<std::uint32_t, 13U> indicator_record(
    const std::span<const std::byte> bytes,
    const std::size_t offset) noexcept {
  std::array<std::uint32_t, 13U> values{};
  for (std::size_t index = 0U; index < values.size(); ++index) {
    const auto value = read_scalar<std::uint32_t>(
        bytes, offset + index * sizeof(std::uint32_t));
    if (!value.has_value()) {
      return {};
    }
    values[index] = *value;
  }
  return values;
}

[[nodiscard]] int indicator_score(
    const std::array<std::uint32_t, 13U>& first,
    const std::array<std::uint32_t, 13U>& second,
    const std::array<std::uint32_t, 13U>& third) noexcept {
  int score = 0;
  if (first[1] == second[1] && second[1] == third[1] &&
      (first[1] & 1U) != 0U && first[1] > 0x10000U) {
    score += 10;
  }
  if (first[4] == second[4] && second[4] == third[4] &&
      (first[4] & 1U) != 0U) {
    score += 6;
  }
  if (first[6] == second[6] && second[6] == third[6] &&
      (first[6] & 1U) != 0U) {
    score += 5;
  }
  if (first[8] == second[8] && second[8] == third[8] &&
      first[9] == second[9] && second[9] == third[9] &&
      first[8] == first[9]) {
    score += 8;
  }
  if (first[7] == second[7] && third[7] != first[7]) {
    score += 8;
  }
  if (first[10] == second[10] && third[10] != first[10]) {
    score += 8;
  }
  if (first[11] == second[11] && third[11] != first[11]) {
    score += 5;
  }
  if (first[12] == second[12] && third[12] != first[12]) {
    score += 5;
  }
  const std::array<std::uint32_t, 3U> values{
      first[0] / 2U, second[0] / 2U, third[0] / 2U};
  if (values[2] >= 20U) {
    score += 4;
  }
  if (values[0] >= 20U && values[1] >= 20U) {
    score += 4;
  }
  if (values[0] >= values[2] || values[1] >= values[2]) {
    score += 1;
  }
  return score;
}

[[nodiscard]] std::array<std::optional<int>, 3U> decode_indicators(
    const std::span<const std::byte> bytes) noexcept {
  constexpr std::size_t record_bytes = 52U;
  constexpr int minimum_score = 60;
  std::array<std::optional<int>, 3U> result{};
  if (bytes.size() < record_bytes * 3U) {
    return result;
  }
  int best_score = -1;
  const std::size_t last = bytes.size() - record_bytes * 3U;
  for (std::size_t alignment = 0U; alignment < 4U; ++alignment) {
    for (std::size_t offset = alignment; offset <= last; offset += 4U) {
      const auto first = indicator_record(bytes, offset);
      const auto second = indicator_record(bytes, offset + record_bytes);
      const auto third = indicator_record(bytes, offset + record_bytes * 2U);
      if ((first[0] & 1U) != 0U || (second[0] & 1U) != 0U ||
          (third[0] & 1U) != 0U || first[0] / 2U > 100U ||
          second[0] / 2U > 100U || third[0] / 2U > 100U) {
        continue;
      }
      const int score = indicator_score(first, second, third);
      if (score >= minimum_score && score > best_score) {
        best_score = score;
        result = {
            static_cast<int>(first[0] / 2U),
            static_cast<int>(second[0] / 2U),
            static_cast<int>(third[0] / 2U),
        };
      }
    }
  }
  return result;
}

}  // namespace

bool player_status_evidence::has_any_value() const noexcept {
  return food.has_value() || water.has_value() || health.has_value() ||
      inventory_weight.has_value() || inventory_weight_max.has_value() ||
      backpack_weight.has_value() || backpack_weight_max.has_value();
}

std::optional<player_status_evidence> decode_player_status_evidence(
    const std::span<const std::vector<std::byte>> scalar_samples,
    const std::span<const status_candidate> candidates,
    const std::span<const std::byte> webengine_window) noexcept {
  if (scalar_samples.size() != candidates.size() ||
      candidates.size() > maximum_status_candidates ||
      webengine_window.size() > maximum_read_region_bytes) {
    return std::nullopt;
  }
  std::array<std::vector<int>, 3U> votes;
  for (std::size_t index = 0U; index < candidates.size(); ++index) {
    const auto& candidate = candidates[index];
    const auto field_index = static_cast<std::size_t>(candidate.field);
    if (field_index >= votes.size()) {
      return std::nullopt;
    }
    if (!std::isfinite(candidate.scale) || !std::isfinite(candidate.offset) ||
        !std::isfinite(candidate.minimum) ||
        !std::isfinite(candidate.maximum) ||
        candidate.minimum > candidate.maximum) {
      return std::nullopt;
    }
    const auto raw = decode_scalar(scalar_samples[index], candidate.type);
    if (!raw.has_value()) {
      continue;
    }
    const double transformed = *raw * candidate.scale + candidate.offset;
    if (!std::isfinite(transformed)) {
      continue;
    }
    const double rounded = std::round(transformed);
    if (rounded < candidate.minimum || rounded > candidate.maximum ||
        rounded < static_cast<double>(std::numeric_limits<int>::min()) ||
        rounded > static_cast<double>(std::numeric_limits<int>::max())) {
      continue;
    }
    votes[field_index].push_back(static_cast<int>(rounded));
  }

  player_status_evidence profile_status{
      .food = legacy_vote(votes[0]),
      .water = legacy_vote(votes[1]),
      .health = legacy_vote(votes[2]),
  };
  player_status_evidence webengine_status;
  if (!webengine_window.empty()) {
    const std::string_view text(
        reinterpret_cast<const char*>(webengine_window.data()),
        webengine_window.size());
    constexpr std::array<std::string_view, 3U> markers{
        "inventory/indicators/v2/health.svg",
        "inventory-interface full-width full-height router-view",
        "weight__text-current",
    };
    if (std::any_of(markers.begin(), markers.end(), [text](const auto marker) {
          return contains(text, marker);
        })) {
      const auto indicators = decode_indicators(webengine_window);
      webengine_status.food = indicators[0];
      webengine_status.water = indicators[1];
      webengine_status.health = indicators[2];

      const auto maximums = maximum_entries(text);
      const auto decimals = decimal_entries(text);
      const auto backpack_max = first_maximum(maximums, 20.0);
      const auto inventory_max = first_maximum(maximums, 40.0);
      std::optional<std::size_t> used_position;
      if (backpack_max.has_value()) {
        webengine_status.backpack_weight_max = backpack_max->value;
        auto backpack = nearest_decimal(
            decimals, backpack_max->position, backpack_max->value, 2048U, true);
        if (!backpack.has_value()) {
          backpack = nearest_decimal(
              decimals, backpack_max->position, backpack_max->value, 4096U, false);
        }
        if (backpack.has_value()) {
          webengine_status.backpack_weight = backpack->value;
          used_position = backpack->position;
        }
      }
      if (inventory_max.has_value()) {
        webengine_status.inventory_weight_max = inventory_max->value;
        constexpr std::string_view health_marker =
            "inventory/indicators/v2/health.svg";
        const std::size_t marker_position = text.find(health_marker);
        std::optional<decimal_entry> inventory;
        if (marker_position != std::string_view::npos) {
          for (const auto& entry : decimals) {
            if ((!used_position.has_value() || entry.position != *used_position) &&
                entry.value <= inventory_max->value &&
                entry.position <= marker_position &&
                marker_position - entry.position <= 24U * 1024U) {
              if (!inventory.has_value() ||
                  entry.position > inventory->position) {
                inventory = entry;
              }
            }
          }
        }
        if (!inventory.has_value()) {
          inventory = nearest_decimal(
              decimals,
              inventory_max->position,
              inventory_max->value,
              24U * 1024U,
              false,
              used_position);
        }
        if (inventory.has_value()) {
          webengine_status.inventory_weight = inventory->value;
        }
      }
    }
  }

  player_status_evidence result = webengine_status;
  if (!result.food.has_value()) {
    result.food = profile_status.food;
  }
  if (!result.water.has_value()) {
    result.water = profile_status.water;
  }
  if (!result.health.has_value()) {
    result.health = profile_status.health;
  }
  return result.has_any_value() ? std::optional<player_status_evidence>(result)
                                : std::nullopt;
}

}  // namespace sonar::fishing::memory_observation
