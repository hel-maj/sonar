#include "sonar/fishing/fish_identity/fish_identity.h"

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

int run(const std::string& path) {
  std::ifstream input(path);
  if (!input) {
    throw std::runtime_error("corpus_open_failed");
  }
  std::string line;
  std::getline(input, line);
  std::size_t row_count = 0;
  while (std::getline(input, line)) {
    const auto fields = split(line, '\t');
    if (fields.size() != 3) {
      throw std::runtime_error("corpus_row_invalid");
    }
    const auto raw = optional_text(fields[0]);
    const auto expected_id = optional_text(fields[1]);
    const auto actual_id = sonar::fishing::fish_identity::Identify(raw);
    if (actual_id != expected_id) {
      throw std::runtime_error("fish_identity_changed_at_row_" +
          std::to_string(row_count + 2));
    }
    const std::string_view actual_display = actual_id.has_value()
        ? sonar::fishing::fish_identity::DisplayName(actual_id)
        : (raw.has_value() && !raw->empty() ? *raw : std::string_view("unknown"));
    if (actual_display != fields[2]) {
      throw std::runtime_error("fish_display_changed_at_row_" +
          std::to_string(row_count + 2));
    }
    ++row_count;
  }
  if (row_count == 0) {
    throw std::runtime_error("corpus_empty");
  }
  std::cout << "PASS " << row_count << " Python/C++ fish-identity rows\n";
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
