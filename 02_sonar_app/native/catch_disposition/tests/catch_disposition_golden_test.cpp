#include "sonar/fishing/catch_disposition/catch_disposition.h"

#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace {

namespace catch_disposition = sonar::fishing::catch_disposition;

[[nodiscard]] std::vector<std::string_view> split(
    const std::string& value,
    const char separator) {
  std::vector<std::string_view> fields;
  std::size_t begin = 0;
  while (true) {
    const std::size_t position = value.find(separator, begin);
    if (position == std::string::npos) {
      fields.emplace_back(value.data() + begin, value.size() - begin);
      return fields;
    }
    fields.emplace_back(value.data() + begin, position - begin);
    begin = position + 1;
  }
}

[[nodiscard]] std::optional<std::string_view> decode_fish_id(
    const std::string_view kind,
    const std::string_view value) {
  if (kind == "none") {
    return std::nullopt;
  }
  if (kind == "empty") {
    return std::string_view{};
  }
  if (kind == "text") {
    return value;
  }
  throw std::runtime_error("invalid_fish_id_kind");
}

[[nodiscard]] std::vector<std::string_view> decode_selected(
    const std::string_view encoded) {
  if (encoded == "-") {
    return {};
  }
  std::vector<std::string_view> values;
  std::size_t begin = 0;
  while (true) {
    const std::size_t position = encoded.find('|', begin);
    std::string_view item = encoded.substr(
        begin,
        position == std::string_view::npos ? std::string_view::npos
                                           : position - begin);
    values.push_back(item == "@empty" ? std::string_view{} : item);
    if (position == std::string_view::npos) {
      return values;
    }
    begin = position + 1;
  }
}

void report_failure(
    const std::size_t line_number,
    const std::string_view case_id,
    const std::string_view message,
    int& failures) {
  std::cerr << "line " << line_number << " (" << case_id << "): "
            << message << '\n';
  ++failures;
}

}  // namespace

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "usage: SonarFishingCatchDispositionTests <legacy_oracle.tsv>\n";
    return 2;
  }

  std::ifstream corpus(argv[1], std::ios::binary);
  if (!corpus) {
    std::cerr << "cannot open corpus: " << argv[1] << '\n';
    return 2;
  }

  constexpr std::string_view kHeader =
      "case_id\tfish_id_kind\tfish_id\tselected_fish_ids\tinventory_full\t"
      "expected_keep\texpected_reason";
  std::string line;
  if (!std::getline(corpus, line)) {
    std::cerr << "corpus is empty\n";
    return 2;
  }
  if (!line.empty() && line.back() == '\r') {
    line.pop_back();
  }
  if (line != kHeader) {
    std::cerr << "unexpected corpus header\n";
    return 2;
  }

  int failures = 0;
  std::size_t cases = 0;
  std::size_t line_number = 1;
  while (std::getline(corpus, line)) {
    ++line_number;
    if (!line.empty() && line.back() == '\r') {
      line.pop_back();
    }
    if (line.empty()) {
      continue;
    }

    const std::vector<std::string_view> fields = split(line, '\t');
    if (fields.size() != 7) {
      report_failure(line_number, "invalid-row", "expected seven TSV fields", failures);
      continue;
    }
    ++cases;
    try {
      const std::optional<std::string_view> fish_id =
          decode_fish_id(fields[1], fields[2]);
      const std::vector<std::string_view> selected = decode_selected(fields[3]);
      const bool inventory_full = fields[4] == "true";
      const bool expected_keep = fields[5] == "true";
      if ((fields[4] != "true" && fields[4] != "false") ||
          (fields[5] != "true" && fields[5] != "false")) {
        throw std::runtime_error("invalid_boolean");
      }
      const catch_disposition::Decision actual = catch_disposition::Decide(
          fish_id,
          std::span<const std::string_view>(selected),
          inventory_full);
      if (actual.should_keep() != expected_keep) {
        report_failure(line_number, fields[0], "disposition mismatch", failures);
      }
      if (catch_disposition::ReasonKey(actual.rationale) != fields[6]) {
        report_failure(line_number, fields[0], "reason mismatch", failures);
      }
    } catch (const std::exception& error) {
      report_failure(line_number, fields[0], error.what(), failures);
    }
  }

  if (cases == 0) {
    std::cerr << "corpus contains no cases\n";
    return 2;
  }
  if (failures != 0) {
    std::cerr << failures << " of " << cases << " cases failed\n";
    return 1;
  }

  std::cout << cases << " catch-disposition golden cases passed\n";
  return 0;
}
