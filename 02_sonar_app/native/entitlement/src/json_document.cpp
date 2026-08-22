#include "json_document.h"

#include <array>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace sonar::fishing::entitlement::detail {
namespace {

constexpr std::size_t maximum_depth = 16;
constexpr std::size_t maximum_nodes = 4096;

[[nodiscard]] bool is_digit(const char value) noexcept {
  return value >= '0' && value <= '9';
}

[[nodiscard]] int hex_value(const char value) noexcept {
  if (value >= '0' && value <= '9') {
    return value - '0';
  }
  if (value >= 'a' && value <= 'f') {
    return value - 'a' + 10;
  }
  if (value >= 'A' && value <= 'F') {
    return value - 'A' + 10;
  }
  return -1;
}

void append_utf8(std::string& output, const std::uint32_t code_point) {
  if (code_point <= 0x7FU) {
    output.push_back(static_cast<char>(code_point));
  } else if (code_point <= 0x7FFU) {
    output.push_back(static_cast<char>(0xC0U | (code_point >> 6U)));
    output.push_back(static_cast<char>(0x80U | (code_point & 0x3FU)));
  } else if (code_point <= 0xFFFFU) {
    output.push_back(static_cast<char>(0xE0U | (code_point >> 12U)));
    output.push_back(static_cast<char>(0x80U | ((code_point >> 6U) & 0x3FU)));
    output.push_back(static_cast<char>(0x80U | (code_point & 0x3FU)));
  } else if (code_point <= 0x10FFFFU) {
    output.push_back(static_cast<char>(0xF0U | (code_point >> 18U)));
    output.push_back(static_cast<char>(0x80U | ((code_point >> 12U) & 0x3FU)));
    output.push_back(static_cast<char>(0x80U | ((code_point >> 6U) & 0x3FU)));
    output.push_back(static_cast<char>(0x80U | (code_point & 0x3FU)));
  } else {
    throw std::runtime_error("json_code_point_invalid");
  }
}

class parser final {
 public:
  explicit parser(const std::string_view source) : source_(source) {}

  [[nodiscard]] json_value parse() {
    skip_whitespace();
    auto result = parse_value(0);
    skip_whitespace();
    if (position_ != source_.size()) {
      throw std::runtime_error("json_trailing_content");
    }
    return result;
  }

 private:
  [[nodiscard]] json_value parse_value(const std::size_t depth) {
    if (depth > maximum_depth || ++nodes_ > maximum_nodes || at_end()) {
      throw std::runtime_error("json_bound_exceeded");
    }
    switch (peek()) {
      case '{':
        return parse_object(depth);
      case '[':
        return parse_array(depth);
      case '"': {
        json_value value;
        value.kind = json_kind::string;
        value.text = parse_string();
        return value;
      }
      case 't':
        require_literal("true");
        return json_value{.kind = json_kind::boolean, .boolean_value = true};
      case 'f':
        require_literal("false");
        return json_value{.kind = json_kind::boolean, .boolean_value = false};
      case 'n':
        require_literal("null");
        return json_value{};
      default:
        if (peek() == '-' || is_digit(peek())) {
          json_value value;
          value.kind = json_kind::number;
          value.text = parse_number();
          return value;
        }
        throw std::runtime_error("json_value_invalid");
    }
  }

  [[nodiscard]] json_value parse_object(const std::size_t depth) {
    consume('{');
    json_value result;
    result.kind = json_kind::object;
    skip_whitespace();
    if (try_consume('}')) {
      return result;
    }
    while (true) {
      skip_whitespace();
      if (at_end() || peek() != '"') {
        throw std::runtime_error("json_object_name_invalid");
      }
      auto name = parse_string();
      for (const auto& existing : result.object_items) {
        if (existing.first == name) {
          throw std::runtime_error("json_duplicate_property");
        }
      }
      skip_whitespace();
      consume(':');
      skip_whitespace();
      result.object_items.emplace_back(
          std::move(name), parse_value(depth + 1));
      skip_whitespace();
      if (try_consume('}')) {
        return result;
      }
      consume(',');
      skip_whitespace();
      if (!at_end() && peek() == '}') {
        throw std::runtime_error("json_trailing_comma");
      }
    }
  }

  [[nodiscard]] json_value parse_array(const std::size_t depth) {
    consume('[');
    json_value result;
    result.kind = json_kind::array;
    skip_whitespace();
    if (try_consume(']')) {
      return result;
    }
    while (true) {
      result.array_items.push_back(parse_value(depth + 1));
      skip_whitespace();
      if (try_consume(']')) {
        return result;
      }
      consume(',');
      skip_whitespace();
      if (!at_end() && peek() == ']') {
        throw std::runtime_error("json_trailing_comma");
      }
    }
  }

  [[nodiscard]] std::string parse_string() {
    consume('"');
    std::string result;
    while (!at_end()) {
      const auto value = take();
      if (value == '"') {
        return result;
      }
      if (static_cast<unsigned char>(value) < 0x20U) {
        throw std::runtime_error("json_control_character");
      }
      if (value != '\\') {
        result.push_back(value);
        continue;
      }
      if (at_end()) {
        throw std::runtime_error("json_escape_truncated");
      }
      switch (take()) {
        case '"': result.push_back('"'); break;
        case '\\': result.push_back('\\'); break;
        case '/': result.push_back('/'); break;
        case 'b': result.push_back('\b'); break;
        case 'f': result.push_back('\f'); break;
        case 'n': result.push_back('\n'); break;
        case 'r': result.push_back('\r'); break;
        case 't': result.push_back('\t'); break;
        case 'u': append_escaped_code_point(result); break;
        default: throw std::runtime_error("json_escape_invalid");
      }
    }
    throw std::runtime_error("json_string_truncated");
  }

  void append_escaped_code_point(std::string& output) {
    auto code_point = parse_hex_quad();
    if (code_point >= 0xD800U && code_point <= 0xDBFFU) {
      if (position_ + 2 > source_.size() ||
          source_[position_] != '\\' || source_[position_ + 1] != 'u') {
        throw std::runtime_error("json_surrogate_missing");
      }
      position_ += 2;
      const auto low = parse_hex_quad();
      if (low < 0xDC00U || low > 0xDFFFU) {
        throw std::runtime_error("json_surrogate_invalid");
      }
      code_point = 0x10000U + ((code_point - 0xD800U) << 10U) +
          (low - 0xDC00U);
    } else if (code_point >= 0xDC00U && code_point <= 0xDFFFU) {
      throw std::runtime_error("json_surrogate_invalid");
    }
    append_utf8(output, code_point);
  }

  [[nodiscard]] std::uint32_t parse_hex_quad() {
    if (position_ + 4 > source_.size()) {
      throw std::runtime_error("json_unicode_truncated");
    }
    std::uint32_t result = 0;
    for (std::size_t index = 0; index < 4; ++index) {
      const int nibble = hex_value(source_[position_++]);
      if (nibble < 0) {
        throw std::runtime_error("json_unicode_invalid");
      }
      result = (result << 4U) | static_cast<std::uint32_t>(nibble);
    }
    return result;
  }

  [[nodiscard]] std::string parse_number() {
    const auto start = position_;
    static_cast<void>(try_consume('-'));
    if (at_end()) {
      throw std::runtime_error("json_number_truncated");
    }
    if (try_consume('0')) {
      if (!at_end() && is_digit(peek())) {
        throw std::runtime_error("json_number_leading_zero");
      }
    } else {
      require_digits();
    }
    if (try_consume('.')) {
      require_digits();
    }
    if (!at_end() && (peek() == 'e' || peek() == 'E')) {
      ++position_;
      if (!at_end() && (peek() == '+' || peek() == '-')) {
        ++position_;
      }
      require_digits();
    }
    return std::string(source_.substr(start, position_ - start));
  }

  void require_digits() {
    if (at_end() || !is_digit(peek())) {
      throw std::runtime_error("json_number_invalid");
    }
    while (!at_end() && is_digit(peek())) {
      ++position_;
    }
  }

  void require_literal(const std::string_view literal) {
    if (source_.substr(position_, literal.size()) != literal) {
      throw std::runtime_error("json_literal_invalid");
    }
    position_ += literal.size();
  }

  void skip_whitespace() noexcept {
    while (!at_end() &&
           (peek() == ' ' || peek() == '\t' || peek() == '\r' || peek() == '\n')) {
      ++position_;
    }
  }

  void consume(const char expected) {
    if (at_end() || take() != expected) {
      throw std::runtime_error("json_token_invalid");
    }
  }

  [[nodiscard]] bool try_consume(const char expected) noexcept {
    if (!at_end() && peek() == expected) {
      ++position_;
      return true;
    }
    return false;
  }

  [[nodiscard]] bool at_end() const noexcept {
    return position_ >= source_.size();
  }

  [[nodiscard]] char peek() const noexcept {
    return source_[position_];
  }

  [[nodiscard]] char take() noexcept {
    return source_[position_++];
  }

  std::string_view source_;
  std::size_t position_{};
  std::size_t nodes_{};
};

}  // namespace

const json_value* json_value::member(const std::string_view name) const noexcept {
  if (kind != json_kind::object) {
    return nullptr;
  }
  for (const auto& item : object_items) {
    if (item.first == name) {
      return &item.second;
    }
  }
  return nullptr;
}

bool parse_json_document(
    const std::string_view source,
    json_value& value) noexcept {
  try {
    value = parser(source).parse();
    return true;
  } catch (...) {
    return false;
  }
}

}  // namespace sonar::fishing::entitlement::detail
