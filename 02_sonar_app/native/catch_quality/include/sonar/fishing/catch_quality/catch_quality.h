#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace sonar::fishing::catch_quality {

[[nodiscard]] std::optional<std::string> NormalizeCatchSize(
    std::optional<std::string_view> text);

[[nodiscard]] std::string_view CatchSizeKey(
    std::optional<std::string_view> label) noexcept;

[[nodiscard]] std::string_view CatchSizeLabel(std::string_view key) noexcept;

}  // namespace sonar::fishing::catch_quality
