#include "sonar/fishing/fish_identity/fish_identity.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <map>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace sonar::fishing::fish_identity {
namespace {

struct FishDefinition {
  std::string_view id;
  std::string_view display_name;
};

#include "fish_catalog.generated.h"

[[nodiscard]] std::u32string DecodeUtf8(const std::string_view text) {
  std::u32string decoded;
  decoded.reserve(text.size());
  std::size_t cursor = 0;
  while (cursor < text.size()) {
    const auto first = static_cast<unsigned char>(text[cursor]);
    if (first < 0x80U) {
      decoded.push_back(first);
      ++cursor;
      continue;
    }

    std::size_t length = 0;
    char32_t value = 0;
    char32_t minimum = 0;
    if ((first & 0xE0U) == 0xC0U) {
      length = 2;
      value = first & 0x1FU;
      minimum = 0x80U;
    } else if ((first & 0xF0U) == 0xE0U) {
      length = 3;
      value = first & 0x0FU;
      minimum = 0x800U;
    } else if ((first & 0xF8U) == 0xF0U) {
      length = 4;
      value = first & 0x07U;
      minimum = 0x10000U;
    } else {
      ++cursor;
      continue;
    }
    if (cursor + length > text.size()) {
      ++cursor;
      continue;
    }
    bool valid = true;
    for (std::size_t offset = 1; offset < length; ++offset) {
      const auto next = static_cast<unsigned char>(text[cursor + offset]);
      if ((next & 0xC0U) != 0x80U) {
        valid = false;
        break;
      }
      value = static_cast<char32_t>((value << 6U) | (next & 0x3FU));
    }
    if (!valid || value < minimum || value > 0x10FFFFU ||
        (value >= 0xD800U && value <= 0xDFFFU)) {
      ++cursor;
      continue;
    }
    decoded.push_back(value);
    cursor += length;
  }
  return decoded;
}

[[nodiscard]] char32_t Lower(const char32_t value) noexcept {
  if (value >= U'A' && value <= U'Z') {
    return value + (U'a' - U'A');
  }
  if (value >= 0x0410U && value <= 0x042FU) {
    return value + 0x20U;
  }
  if (value == 0x0401U) {
    return 0x0451U;
  }
  return value;
}

[[nodiscard]] bool IsIdentityCharacter(const char32_t value) noexcept {
  return (value >= U'0' && value <= U'9') ||
         (value >= U'a' && value <= U'z') ||
         (value >= 0x0430U && value <= 0x044FU) || value == 0x0451U;
}

[[nodiscard]] std::u32string Normalize(const std::string_view text) {
  std::u32string normalized;
  for (const char32_t code_point : DecodeUtf8(text)) {
    const char32_t lowered = Lower(code_point);
    if (IsIdentityCharacter(lowered)) {
      normalized.push_back(lowered);
    }
  }
  return normalized;
}

struct Match {
  std::size_t first;
  std::size_t second;
  std::size_t size;
};

[[nodiscard]] Match FindLongestMatch(
    const std::u32string& left,
    const std::u32string& right,
    const std::size_t left_begin,
    const std::size_t left_end,
    const std::size_t right_begin,
    const std::size_t right_end) {
  std::map<char32_t, std::vector<std::size_t>> positions;
  for (std::size_t index = right_begin; index < right_end; ++index) {
    positions[right[index]].push_back(index);
  }

  Match best{left_begin, right_begin, 0};
  std::map<std::size_t, std::size_t> previous_lengths;
  for (std::size_t left_index = left_begin; left_index < left_end; ++left_index) {
    std::map<std::size_t, std::size_t> current_lengths;
    const auto candidates = positions.find(left[left_index]);
    if (candidates != positions.end()) {
      for (const std::size_t right_index : candidates->second) {
        const auto previous = previous_lengths.find(right_index - 1);
        const std::size_t length =
            (previous == previous_lengths.end() ? 0 : previous->second) + 1;
        current_lengths.emplace(right_index, length);
        if (length > best.size) {
          best = Match{
              left_index - length + 1,
              right_index - length + 1,
              length,
          };
        }
      }
    }
    previous_lengths = std::move(current_lengths);
  }
  return best;
}

[[nodiscard]] std::size_t MatchingCharacters(
    const std::u32string& left,
    const std::u32string& right) {
  struct Range {
    std::size_t left_begin;
    std::size_t left_end;
    std::size_t right_begin;
    std::size_t right_end;
  };
  std::vector<Range> pending{{0, left.size(), 0, right.size()}};
  std::vector<Match> matches;
  while (!pending.empty()) {
    const Range range = pending.back();
    pending.pop_back();
    const Match match = FindLongestMatch(
        left,
        right,
        range.left_begin,
        range.left_end,
        range.right_begin,
        range.right_end);
    if (match.size == 0) {
      continue;
    }
    matches.push_back(match);
    if (range.left_begin < match.first && range.right_begin < match.second) {
      pending.push_back(Range{
          range.left_begin,
          match.first,
          range.right_begin,
          match.second,
      });
    }
    const std::size_t left_after = match.first + match.size;
    const std::size_t right_after = match.second + match.size;
    if (left_after < range.left_end && right_after < range.right_end) {
      pending.push_back(Range{
          left_after,
          range.left_end,
          right_after,
          range.right_end,
      });
    }
  }
  std::ranges::sort(matches, {}, &Match::first);
  std::size_t total = 0;
  for (const Match match : matches) {
    total += match.size;
  }
  return total;
}

[[nodiscard]] double SequenceRatio(
    const std::u32string& left,
    const std::u32string& right) {
  if (left.empty() && right.empty()) {
    return 1.0;
  }
  return 2.0 * static_cast<double>(MatchingCharacters(left, right)) /
      static_cast<double>(left.size() + right.size());
}

}  // namespace

std::string_view DisplayName(
    const std::optional<std::string_view> fish_id) noexcept {
  if (!fish_id.has_value() || fish_id->empty()) {
    return "unknown";
  }
  const auto found = std::ranges::find(kFishCatalog, *fish_id, &FishDefinition::id);
  return found == kFishCatalog.end() ? *fish_id : found->display_name;
}

std::optional<std::string_view> Identify(
    const std::optional<std::string_view> display_text) {
  if (!display_text.has_value() || display_text->empty()) {
    return std::nullopt;
  }
  const std::u32string normalized = Normalize(*display_text);
  if (normalized.size() < 4) {
    return std::nullopt;
  }

  std::optional<std::string_view> best_id;
  double best_score = 0.0;
  for (const FishDefinition definition : kFishCatalog) {
    const std::u32string candidate = Normalize(definition.display_name);
    if (candidate == normalized) {
      return definition.id;
    }
    const double score = SequenceRatio(normalized, candidate);
    if (score > best_score) {
      best_id = definition.id;
      best_score = score;
    }
  }
  return best_score >= 0.72 ? best_id : std::nullopt;
}

}  // namespace sonar::fishing::fish_identity
