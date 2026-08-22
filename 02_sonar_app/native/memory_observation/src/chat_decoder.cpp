#include "sonar/fishing/memory_observation/memory_observation.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <utility>

#include "decoder_support.h"

namespace sonar::fishing::memory_observation {
namespace {

using decoder_support::ascii_space;
using decoder_support::contains;

[[nodiscard]] bool valid_utf8(const std::string_view value) noexcept {
  std::size_t index = 0U;
  while (index < value.size()) {
    const auto first = static_cast<unsigned char>(value[index]);
    std::size_t continuation = 0U;
    std::uint32_t codepoint = 0U;
    if (first <= 0x7FU) {
      ++index;
      continue;
    }
    if ((first & 0xE0U) == 0xC0U) {
      continuation = 1U;
      codepoint = first & 0x1FU;
    } else if ((first & 0xF0U) == 0xE0U) {
      continuation = 2U;
      codepoint = first & 0x0FU;
    } else if ((first & 0xF8U) == 0xF0U) {
      continuation = 3U;
      codepoint = first & 0x07U;
    } else {
      return false;
    }
    if (index + continuation >= value.size()) {
      return false;
    }
    for (std::size_t part = 1U; part <= continuation; ++part) {
      const auto next = static_cast<unsigned char>(value[index + part]);
      if ((next & 0xC0U) != 0x80U) {
        return false;
      }
      codepoint = (codepoint << 6U) | (next & 0x3FU);
    }
    if ((continuation == 1U && codepoint < 0x80U) ||
        (continuation == 2U && codepoint < 0x800U) ||
        (continuation == 3U && codepoint < 0x10000U) ||
        codepoint > 0x10FFFFU ||
        (codepoint >= 0xD800U && codepoint <= 0xDFFFU)) {
      return false;
    }
    index += continuation + 1U;
  }
  return true;
}

[[nodiscard]] std::optional<bool> parse_bool_field(
    const std::string_view text,
    const std::string_view key) noexcept {
  const std::string quoted_key = "\"" + std::string(key) + "\"";
  std::size_t position = text.find(quoted_key);
  if (position == std::string_view::npos) {
    position = text.find(key);
  }
  if (position == std::string_view::npos) {
    return std::nullopt;
  }
  position = text.find_first_of(":=", position + key.size());
  if (position == std::string_view::npos) {
    return std::nullopt;
  }
  ++position;
  while (position < text.size() &&
         ascii_space(static_cast<unsigned char>(text[position]))) {
    ++position;
  }
  if (position < text.size() && text[position] == '"') {
    ++position;
  }
  if (text.substr(position, 4U) == "true" ||
      text.substr(position, 1U) == "1") {
    return true;
  }
  if (text.substr(position, 5U) == "false" ||
      text.substr(position, 1U) == "0") {
    return false;
  }
  return std::nullopt;
}

[[nodiscard]] std::optional<std::string> parse_text_value(
    const std::string_view text,
    const std::string_view key,
    const std::size_t search_begin,
    const std::size_t search_end) {
  if (search_begin >= text.size() || search_begin >= search_end) {
    return std::nullopt;
  }
  const std::string quoted_key = "\"" + std::string(key) + "\"";
  std::size_t position = text.find(quoted_key, search_begin);
  if (position == std::string_view::npos || position >= search_end) {
    return std::nullopt;
  }
  position = text.find(':', position + quoted_key.size());
  if (position == std::string_view::npos || position >= search_end) {
    return std::nullopt;
  }
  ++position;
  while (position < search_end &&
         ascii_space(static_cast<unsigned char>(text[position]))) {
    ++position;
  }
  if (position >= search_end) {
    return std::nullopt;
  }
  if (text[position] == '"') {
    const std::size_t value_begin = ++position;
    const std::size_t value_end = text.find('"', value_begin);
    if (value_end == std::string_view::npos || value_end > search_end ||
        value_end == value_begin || value_end - value_begin > 40U) {
      return std::nullopt;
    }
    return std::string(text.substr(value_begin, value_end - value_begin));
  }
  const std::size_t value_begin = position;
  if (text[position] == '-') {
    ++position;
  }
  while (position < search_end && text[position] >= '0' &&
         text[position] <= '9' && position - value_begin <= 4U) {
    ++position;
  }
  if (position == value_begin ||
      (position == value_begin + 1U && text[value_begin] == '-')) {
    return std::nullopt;
  }
  return std::string(text.substr(value_begin, position - value_begin));
}

[[nodiscard]] std::pair<std::string, chat_confidence> parse_active_tab(
    const std::string_view text) {
  constexpr std::array<std::string_view, 4U> keys{
      "activeFilter", "activeTab", "selectedTab", "currentTab"};
  constexpr std::array<std::string_view, 5U> object_fields{
      "id", "key", "value", "type", "name"};
  for (const auto key : keys) {
    const std::string quoted_key = "\"" + std::string(key) + "\"";
    const std::size_t key_position = text.find(quoted_key);
    if (key_position == std::string_view::npos) {
      continue;
    }
    const std::size_t colon = text.find(':', key_position + quoted_key.size());
    if (colon == std::string_view::npos) {
      continue;
    }
    const std::size_t object_begin = text.find('{', colon + 1U);
    if (object_begin != std::string_view::npos && object_begin - colon <= 8U) {
      const std::size_t maximum_end = std::min(text.size(), object_begin + 502U);
      const std::size_t object_end = text.find('}', object_begin + 1U);
      if (object_end != std::string_view::npos && object_end < maximum_end) {
        for (const auto field : object_fields) {
          const auto value = parse_text_value(
              text, field, object_begin + 1U, object_end);
          if (value.has_value()) {
            return {*value, chat_confidence::high};
          }
        }
      }
    }
    const auto direct = parse_text_value(
        text, key, key_position, std::min(text.size(), key_position + 128U));
    if (direct.has_value()) {
      return {*direct, chat_confidence::medium};
    }
  }
  return {{}, chat_confidence::unknown};
}

}  // namespace

bool chat_evidence::has_any_value() const noexcept {
  return input_active.has_value() || visible.has_value() ||
      !active_tab_id.empty();
}

std::optional<chat_evidence> decode_chat_evidence(
    const std::span<const std::byte> state_window) noexcept {
  if (state_window.empty() || state_window.size() > maximum_read_region_bytes) {
    return std::nullopt;
  }
  const std::string_view text(
      reinterpret_cast<const char*>(state_window.data()), state_window.size());
  if (!valid_utf8(text)) {
    return std::nullopt;
  }
  chat_evidence result;
  const auto input_status = parse_bool_field(text, "inputStatus");
  const auto chat_active = parse_bool_field(text, "chatIsActive");
  result.input_active = input_status.has_value() ? input_status : chat_active;
  result.visible = parse_bool_field(text, "chatIsShow");
  if (result.input_active.has_value() || result.visible.has_value()) {
    result.confidence = chat_confidence::high;
  }
  const auto [tab_id, tab_confidence] = parse_active_tab(text);
  result.active_tab_id = tab_id;
  if (static_cast<int>(tab_confidence) > static_cast<int>(result.confidence)) {
    result.confidence = tab_confidence;
  }

  const bool disabled_selector = contains(text, "div.chat.disabled") ||
      contains(text, "div.chat-container > div.chat.disabled");
  const bool enabled_selector =
      contains(text, "div.chat-container > div.chat >") ||
      contains(text, "label.chat-input.withCommand") ||
      (contains(text, "ui.click") &&
       (contains(text, "chatInput") || contains(text, "label.chat-input")));
  if (!result.input_active.has_value() &&
      (disabled_selector || enabled_selector)) {
    result.input_active = enabled_selector;
    result.visible = true;
    result.confidence = chat_confidence::medium;
  }
  return result.has_any_value() ? std::optional<chat_evidence>(result)
                                : std::nullopt;
}

}  // namespace sonar::fishing::memory_observation
