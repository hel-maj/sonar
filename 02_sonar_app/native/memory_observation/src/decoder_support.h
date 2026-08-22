#pragma once

#include <cstddef>
#include <cstring>
#include <optional>
#include <span>
#include <string_view>
#include <type_traits>

namespace sonar::fishing::memory_observation::decoder_support {

template <typename T>
[[nodiscard]] std::optional<T> read_scalar(
    const std::span<const std::byte> bytes,
    const std::size_t offset) noexcept {
  static_assert(std::is_trivially_copyable_v<T>);
  if (offset > bytes.size() || bytes.size() - offset < sizeof(T)) {
    return std::nullopt;
  }
  T value{};
  std::memcpy(&value, bytes.data() + offset, sizeof(T));
  return value;
}

[[nodiscard]] inline bool ascii_alnum(const unsigned char value) noexcept {
  return (value >= static_cast<unsigned char>('0') &&
          value <= static_cast<unsigned char>('9')) ||
      (value >= static_cast<unsigned char>('A') &&
       value <= static_cast<unsigned char>('Z')) ||
      (value >= static_cast<unsigned char>('a') &&
       value <= static_cast<unsigned char>('z'));
}

[[nodiscard]] inline bool ascii_space(const unsigned char value) noexcept {
  return value == static_cast<unsigned char>(' ') ||
      value == static_cast<unsigned char>('\t') ||
      value == static_cast<unsigned char>('\r') ||
      value == static_cast<unsigned char>('\n') ||
      value == static_cast<unsigned char>('\f') ||
      value == static_cast<unsigned char>('\v');
}

[[nodiscard]] inline bool contains(
    const std::string_view value,
    const std::string_view needle) noexcept {
  return value.find(needle) != std::string_view::npos;
}

}  // namespace sonar::fishing::memory_observation::decoder_support
