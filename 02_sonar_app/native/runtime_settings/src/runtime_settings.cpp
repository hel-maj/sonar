#include "sonar/fishing/runtime_settings/runtime_settings.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <utility>

namespace sonar::fishing::runtime_settings {
namespace {

[[nodiscard]] bool is_ascii_alphanumeric(const char value) noexcept {
  const auto byte = static_cast<unsigned char>(value);
  return std::isalnum(byte) != 0 && byte <= 0x7fU;
}

[[nodiscard]] bool is_base_key(const std::string_view value) noexcept {
  if (value.size() == 1 && is_ascii_alphanumeric(value.front())) {
    return true;
  }
  if (value == "tab" || value == "backspace" || value == "enter" ||
      value == "space") {
    return true;
  }
  if (value.size() < 2 || value.size() > 3 ||
      (value.front() != 'f' && value.front() != 'F')) {
    return false;
  }
  unsigned int number = 0;
  for (const char digit : value.substr(1)) {
    if (digit < '0' || digit > '9') {
      return false;
    }
    number = number * 10U + static_cast<unsigned int>(digit - '0');
  }
  return number >= 1U && number <= 24U;
}

[[nodiscard]] bool valid_identifier(const std::string_view value) noexcept {
  if (value.empty() || value.size() > 128) {
    return false;
  }
  return std::ranges::all_of(value, [](const char character) {
    const auto byte = static_cast<unsigned char>(character);
    return byte >= 0x21U && byte <= 0x7eU;
  });
}

template <typename TValue>
[[nodiscard]] bool valid_policy_identifiers(
    const std::map<std::string, TValue, std::less<>>& values) noexcept {
  return std::ranges::all_of(values, [](const auto& item) {
    return valid_identifier(item.first);
  });
}

[[nodiscard]] std::optional<std::string> normalize_hotkey(
    const std::string_view value) noexcept {
  if (value.empty() || value.size() > 48) {
    return std::nullopt;
  }

  std::array<bool, 3> modifiers{};
  std::optional<std::string> base_key;
  std::size_t start = 0;
  while (start <= value.size()) {
    const std::size_t end = value.find('+', start);
    const std::string_view part = value.substr(
        start,
        end == std::string_view::npos ? value.size() - start : end - start);
    if (part.empty() ||
        std::ranges::any_of(part, [](const char character) {
          return std::isspace(static_cast<unsigned char>(character)) != 0;
        })) {
      return std::nullopt;
    }

    std::string lower(part);
    std::ranges::transform(lower, lower.begin(), [](const char character) {
      return static_cast<char>(
          std::tolower(static_cast<unsigned char>(character)));
    });
    std::optional<std::size_t> modifier_index;
    if (lower == "ctrl" || lower == "control") {
      modifier_index = 0;
    } else if (lower == "alt") {
      modifier_index = 1;
    } else if (lower == "shift") {
      modifier_index = 2;
    }

    if (modifier_index.has_value()) {
      if (base_key.has_value() || modifiers[*modifier_index]) {
        return std::nullopt;
      }
      modifiers[*modifier_index] = true;
    } else {
      if (base_key.has_value() || !is_base_key(lower)) {
        return std::nullopt;
      }
      base_key = std::move(lower);
    }

    if (end == std::string_view::npos) {
      break;
    }
    start = end + 1;
  }
  if (!base_key.has_value()) {
    return std::nullopt;
  }

  std::string result;
  constexpr std::array names{"ctrl", "alt", "shift"};
  for (std::size_t index = 0; index < modifiers.size(); ++index) {
    if (modifiers[index]) {
      result.append(names[index]).push_back('+');
    }
  }
  result.append(*base_key);
  return result;
}

}  // namespace

bool IsValidHotkey(const std::string_view value) noexcept {
  return normalize_hotkey(value).has_value();
}

std::string_view Validate(
    const RuntimeSettingsSnapshot& candidate) noexcept {
  if (candidate.revision == 0) {
    return "settings_revision_zero";
  }
  const auto threshold_valid = [](const std::uint32_t value) {
    return value >= 1U && value <= 90U;
  };
  if (!threshold_valid(candidate.restore_food_from) ||
      !threshold_valid(candidate.restore_water_from) ||
      !threshold_valid(candidate.restore_health_from)) {
    return "settings_threshold_out_of_range";
  }

  const std::array hotkeys{
      std::string_view(candidate.start_stop_hotkey),
      std::string_view(candidate.inventory_hotkey),
      std::string_view(candidate.use_item_hotkey),
      std::string_view(candidate.backpack_move_hotkey),
      std::string_view(candidate.discard_hotkey),
      std::string_view(candidate.chat_hotkey),
  };
  if (!std::ranges::all_of(hotkeys, IsValidHotkey)) {
    return "settings_hotkey_invalid";
  }
  std::array<std::string, hotkeys.size()> normalized_hotkeys;
  for (std::size_t index = 0; index < hotkeys.size(); ++index) {
    normalized_hotkeys[index] = *normalize_hotkey(hotkeys[index]);
  }
  for (std::size_t left = 0; left < normalized_hotkeys.size(); ++left) {
    for (std::size_t right = left + 1; right < normalized_hotkeys.size(); ++right) {
      if (normalized_hotkeys[left] == normalized_hotkeys[right]) {
        return "settings_hotkey_conflict";
      }
    }
  }
  if (!valid_policy_identifiers(candidate.fish_keep_policy) ||
      !valid_policy_identifiers(candidate.garbage_disposal_policy) ||
      !valid_policy_identifiers(candidate.custom_fish_prices)) {
    return "settings_policy_identifier_invalid";
  }
  if (std::ranges::any_of(
          candidate.custom_fish_prices,
          [](const auto& item) {
            return !std::isfinite(item.second) || item.second < 0.0;
          })) {
    return "settings_custom_price_invalid";
  }
  return {};
}

ApplyResult RuntimeSettingsOwner::Apply(RuntimeSettingsSnapshot candidate) {
  if (current_.has_value() && candidate.revision <= current_->revision) {
    return ApplyResult{
        .status = ApplyStatus::stale_revision,
        .accepted_revision = current_->revision,
        .reason = "settings_revision_not_increasing",
    };
  }
  const std::string_view reason = Validate(candidate);
  if (!reason.empty()) {
    return ApplyResult{
        .status = ApplyStatus::invalid_snapshot,
        .accepted_revision = AcceptedRevision(),
        .reason = std::string(reason),
    };
  }
  const std::uint64_t revision = candidate.revision;
  current_.emplace(std::move(candidate));
  return ApplyResult{
      .status = ApplyStatus::accepted,
      .accepted_revision = revision,
      .reason = "settings_applied",
  };
}

std::optional<RuntimeSettingsSnapshot> RuntimeSettingsOwner::Current() const {
  return current_;
}

std::uint64_t RuntimeSettingsOwner::AcceptedRevision() const noexcept {
  return current_.has_value() ? current_->revision : 0;
}

}  // namespace sonar::fishing::runtime_settings
