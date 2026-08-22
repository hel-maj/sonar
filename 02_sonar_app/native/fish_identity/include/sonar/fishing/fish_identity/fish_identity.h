#pragma once

#include <optional>
#include <string_view>

namespace sonar::fishing::fish_identity {

[[nodiscard]] std::string_view DisplayName(
    std::optional<std::string_view> fish_id) noexcept;

// Preserves Python difflib.SequenceMatcher semantics for the current short
// product catalog, including insertion-order tie breaking and the 0.72 gate.
[[nodiscard]] std::optional<std::string_view> Identify(
    std::optional<std::string_view> display_text);

}  // namespace sonar::fishing::fish_identity
