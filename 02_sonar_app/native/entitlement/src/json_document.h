#pragma once

#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace sonar::fishing::entitlement::detail {

enum class json_kind {
  null_value,
  boolean,
  number,
  string,
  array,
  object,
};

struct json_value final {
  json_kind kind{json_kind::null_value};
  bool boolean_value{};
  std::string text;
  std::vector<json_value> array_items;
  std::vector<std::pair<std::string, json_value>> object_items;

  [[nodiscard]] const json_value* member(std::string_view name) const noexcept;
};

[[nodiscard]] bool parse_json_document(
    std::string_view source,
    json_value& value) noexcept;

}  // namespace sonar::fishing::entitlement::detail
