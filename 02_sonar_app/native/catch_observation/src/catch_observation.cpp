#include "sonar/fishing/catch_observation/catch_observation.h"

#include <algorithm>
#include <charconv>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

#include "sonar/fishing/catch_quality/catch_quality.h"
#include "sonar/fishing/fish_identity/fish_identity.h"

namespace sonar::fishing::catch_observation {
namespace {

[[nodiscard]] bool IsAsciiDigit(const char value) noexcept {
  return value >= '0' && value <= '9';
}

[[nodiscard]] bool IsAsciiWhitespace(const char value) noexcept {
  return value == ' ' || value == '\t' || value == '\r' || value == '\n' ||
         value == '\f' || value == '\v';
}

[[nodiscard]] std::optional<std::uint64_t> ParseUnsigned(
    const std::string_view digits) noexcept {
  std::uint64_t value = 0;
  const auto [end, error] = std::from_chars(
      digits.data(), digits.data() + digits.size(), value);
  if (error != std::errc{} || end != digits.data() + digits.size()) {
    return std::nullopt;
  }
  return value;
}

[[nodiscard]] std::vector<std::string_view> NumberRuns(
    const std::string_view text) {
  std::vector<std::string_view> numbers;
  std::size_t cursor = 0;
  while (cursor < text.size()) {
    while (cursor < text.size() && !IsAsciiDigit(text[cursor])) {
      ++cursor;
    }
    const std::size_t begin = cursor;
    while (cursor < text.size() && IsAsciiDigit(text[cursor])) {
      ++cursor;
    }
    if (begin != cursor) {
      numbers.push_back(text.substr(begin, cursor - begin));
    }
  }
  return numbers;
}

[[nodiscard]] bool ContainsMaximumMarker(const std::string_view text) {
  return text.find("максималь") != std::string_view::npos ||
         text.find("Максималь") != std::string_view::npos ||
         text.find("МАКСИМАЛЬ") != std::string_view::npos;
}

[[nodiscard]] bool HasThreeIdentityCharacters(const std::string_view text) {
  std::size_t count = 0;
  std::size_t cursor = 0;
  while (cursor < text.size()) {
    const auto first = static_cast<unsigned char>(text[cursor]);
    if ((first >= '0' && first <= '9') ||
        (first >= 'A' && first <= 'Z') ||
        (first >= 'a' && first <= 'z')) {
      ++count;
      ++cursor;
    } else if (first == 0xD0U || first == 0xD1U) {
      if (cursor + 1 < text.size()) {
        const auto second = static_cast<unsigned char>(text[cursor + 1]);
        if ((first == 0xD0U && second >= 0x81U && second <= 0xBFU) ||
            (first == 0xD1U && second >= 0x80U && second <= 0x91U)) {
          ++count;
          cursor += 2;
          continue;
        }
      }
      ++cursor;
    } else {
      ++cursor;
    }
    if (count >= 3) {
      return true;
    }
  }
  return count >= 3;
}

[[nodiscard]] bool ValidContent(
    const std::optional<std::string>& fish_id,
    const std::optional<std::string>& fish_text,
    const std::optional<double> weight_kg) {
  if (!weight_kg.has_value() || !(*weight_kg >= 0.01 && *weight_kg <= 500.0)) {
    return false;
  }
  if (fish_id.has_value() && !fish_id->empty()) {
    return true;
  }
  return fish_text.has_value() && !fish_text->empty() &&
      HasThreeIdentityCharacters(*fish_text);
}

}  // namespace

std::optional<double> ParseWeight(
    const std::optional<std::string_view> text) {
  if (!text.has_value() || text->empty()) {
    return std::nullopt;
  }
  std::size_t cursor = 0;
  while (cursor < text->size() && !IsAsciiDigit((*text)[cursor])) {
    ++cursor;
  }
  if (cursor == text->size()) {
    return std::nullopt;
  }
  const std::size_t begin = cursor;
  while (cursor < text->size() && IsAsciiDigit((*text)[cursor])) {
    ++cursor;
  }
  const std::size_t whole_end = cursor;
  std::size_t fraction_begin = cursor;
  std::size_t fraction_end = cursor;
  bool has_separator = false;
  if (cursor < text->size() && ((*text)[cursor] == '.' || (*text)[cursor] == ',')) {
    const std::size_t separator = cursor++;
    const std::size_t possible_fraction = cursor;
    while (cursor < text->size() && IsAsciiDigit((*text)[cursor])) {
      ++cursor;
    }
    if (cursor != possible_fraction) {
      has_separator = true;
      fraction_begin = possible_fraction;
      fraction_end = cursor;
    } else {
      cursor = separator;
    }
  }

  const std::string_view whole = text->substr(begin, whole_end - begin);
  const auto whole_value = ParseUnsigned(whole);
  if (!whole_value.has_value()) {
    return std::nullopt;
  }
  if (!has_separator && whole.size() >= 3) {
    return static_cast<double>(*whole_value) / 100.0;
  }
  if (!has_separator) {
    return static_cast<double>(*whole_value);
  }
  const std::size_t fraction_digits =
      std::min<std::size_t>(2, fraction_end - fraction_begin);
  const std::string_view fraction = text->substr(fraction_begin, fraction_digits);
  const auto fraction_value = ParseUnsigned(fraction);
  if (!fraction_value.has_value()) {
    return std::nullopt;
  }
  const double divisor = fraction_digits == 1 ? 10.0 : 100.0;
  return static_cast<double>(*whole_value) +
      static_cast<double>(*fraction_value) / divisor;
}

ExperienceReading ParseExperience(
    const std::optional<std::string_view> text) {
  if (!text.has_value() || text->empty()) {
    return {false, std::nullopt, std::nullopt};
  }

  std::size_t cursor = 0;
  while (cursor < text->size()) {
    while (cursor < text->size() && !IsAsciiDigit((*text)[cursor])) {
      ++cursor;
    }
    const std::size_t first_begin = cursor;
    while (cursor < text->size() && IsAsciiDigit((*text)[cursor])) {
      ++cursor;
    }
    if (first_begin == cursor) {
      break;
    }
    const std::size_t first_end = cursor;
    while (cursor < text->size() && IsAsciiWhitespace((*text)[cursor])) {
      ++cursor;
    }
    if (cursor < text->size() && (*text)[cursor] == '/') {
      ++cursor;
      while (cursor < text->size() && IsAsciiWhitespace((*text)[cursor])) {
        ++cursor;
      }
      const std::size_t second_begin = cursor;
      while (cursor < text->size() && IsAsciiDigit((*text)[cursor])) {
        ++cursor;
      }
      if (second_begin != cursor) {
        return {
            false,
            ParseUnsigned(text->substr(first_begin, first_end - first_begin)),
            ParseUnsigned(text->substr(second_begin, cursor - second_begin)),
        };
      }
    }
  }

  const auto runs = NumberRuns(*text);
  if (ContainsMaximumMarker(*text)) {
    if (runs.empty()) {
      return {true, std::nullopt, std::nullopt};
    }
    std::string_view best = runs.front();
    for (const std::string_view candidate : runs) {
      const auto best_value = ParseUnsigned(best).value_or(0);
      const auto candidate_value = ParseUnsigned(candidate).value_or(0);
      if (candidate.size() > best.size() ||
          (candidate.size() == best.size() && candidate_value > best_value)) {
        best = candidate;
      }
    }
    return {true, ParseUnsigned(best), std::nullopt};
  }
  return {
      false,
      runs.empty() ? std::nullopt : ParseUnsigned(runs.front()),
      std::nullopt,
  };
}

CatchObservation Interpret(const RawCatchText& raw) {
  const auto identified = sonar::fishing::fish_identity::Identify(raw.fish);
  std::optional<std::string> fish_id;
  std::optional<std::string> fish_text;
  if (identified.has_value()) {
    fish_id = std::string(*identified);
    fish_text = std::string(
        sonar::fishing::fish_identity::DisplayName(identified));
  } else if (raw.fish.has_value() && !raw.fish->empty()) {
    fish_text = std::string(*raw.fish);
  }

  const auto quality =
      sonar::fishing::catch_quality::NormalizeCatchSize(raw.quality);
  const std::optional<std::string_view> quality_view = quality.has_value()
      ? std::optional<std::string_view>(*quality)
      : std::nullopt;
  const std::string quality_key(
      sonar::fishing::catch_quality::CatchSizeKey(quality_view));
  const auto weight = ParseWeight(raw.weight);
  return CatchObservation{
      .valid_content = ValidContent(fish_id, fish_text, weight),
      .fish_id = std::move(fish_id),
      .fish_text = std::move(fish_text),
      .fish_confidence = identified.has_value() ? 0.95 : 0.0,
      .quality_label = quality,
      .quality_key = quality_key,
      .weight_kg = weight,
      .experience = ParseExperience(raw.experience),
  };
}

}  // namespace sonar::fishing::catch_observation
