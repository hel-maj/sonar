#include "sonar/fishing/catch_observation/catch_observation.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace {

[[nodiscard]] std::vector<std::string> split(
    const std::string_view text,
    const char delimiter) {
  std::vector<std::string> values;
  std::size_t start = 0;
  while (start <= text.size()) {
    const std::size_t end = text.find(delimiter, start);
    values.emplace_back(text.substr(
        start,
        end == std::string_view::npos ? text.size() - start : end - start));
    if (end == std::string_view::npos) {
      break;
    }
    start = end + 1;
  }
  return values;
}

[[nodiscard]] std::optional<std::string_view> optional_text(
    const std::string_view value) {
  return value == "<none>" ? std::nullopt : std::optional(value);
}

[[nodiscard]] std::optional<double> optional_number(
    const std::string_view value) {
  return value == "<none>"
      ? std::nullopt
      : std::optional(std::stod(std::string(value)));
}

[[nodiscard]] std::optional<std::uint64_t> optional_whole(
    const std::string_view value) {
  return value == "<none>"
      ? std::nullopt
      : std::optional<std::uint64_t>(std::stoull(std::string(value)));
}

void require_optional_text(
    const std::optional<std::string>& actual,
    const std::string_view expected,
    const std::string_view field,
    const std::size_t row) {
  const auto expected_value = optional_text(expected);
  if (actual.has_value() != expected_value.has_value() ||
      (actual.has_value() && *actual != *expected_value)) {
    throw std::runtime_error(
        std::string(field) + "_changed_at_row_" + std::to_string(row));
  }
}

void require_optional_number(
    const std::optional<double> actual,
    const std::string_view expected,
    const std::size_t row) {
  const auto expected_value = optional_number(expected);
  if (actual.has_value() != expected_value.has_value() ||
      (actual.has_value() && std::abs(*actual - *expected_value) > 1e-9)) {
    throw std::runtime_error("weight_changed_at_row_" + std::to_string(row));
  }
}

int run(const std::string& path) {
  std::ifstream input(path);
  if (!input) {
    throw std::runtime_error("corpus_open_failed");
  }
  std::string line;
  std::getline(input, line);
  std::size_t row = 1;
  while (std::getline(input, line)) {
    ++row;
    const auto fields = split(line, '\t');
    if (fields.size() != 13) {
      throw std::runtime_error("corpus_row_invalid_" + std::to_string(row));
    }
    const auto result = sonar::fishing::catch_observation::Interpret({
        .fish = optional_text(fields[0]),
        .quality = optional_text(fields[1]),
        .weight = optional_text(fields[2]),
        .experience = optional_text(fields[3]),
    });
    if (result.valid_content != (fields[4] == "1")) {
      throw std::runtime_error("validity_changed_at_row_" + std::to_string(row));
    }
    require_optional_text(result.fish_id, fields[5], "fish_id", row);
    require_optional_text(result.fish_text, fields[6], "fish_text", row);
    require_optional_text(result.quality_label, fields[7], "quality", row);
    if (result.quality_key != fields[8]) {
      throw std::runtime_error("quality_key_changed_at_row_" + std::to_string(row));
    }
    require_optional_number(result.weight_kg, fields[9], row);
    if (result.experience.is_max_level != (fields[10] == "1") ||
        result.experience.current != optional_whole(fields[11]) ||
        result.experience.total != optional_whole(fields[12])) {
      throw std::runtime_error("experience_changed_at_row_" + std::to_string(row));
    }
  }
  if (row == 1) {
    throw std::runtime_error("corpus_empty");
  }
  std::cout << "PASS " << row - 1
            << " Python/C++ catch-observation rows\n";
  return 0;
}

}  // namespace

int main(const int argc, char** argv) {
  try {
    if (argc != 2) {
      throw std::runtime_error("usage: test <corpus.tsv>");
    }
    return run(argv[1]);
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
