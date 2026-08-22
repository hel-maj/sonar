#include "sonar/fishing/garbage_disposal/garbage_disposal.h"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace {

namespace disposal = sonar::fishing::garbage_disposal;

[[nodiscard]] std::vector<std::string> split(
    const std::string_view value,
    const char delimiter) {
  std::vector<std::string> fields;
  std::size_t start = 0;
  while (start <= value.size()) {
    const std::size_t end = value.find(delimiter, start);
    fields.emplace_back(value.substr(
        start,
        end == std::string_view::npos ? value.size() - start : end - start));
    if (end == std::string_view::npos) {
      break;
    }
    start = end + 1;
  }
  return fields;
}

[[nodiscard]] disposal::SelectionPolicy policy(const std::string_view encoded) {
  disposal::SelectionPolicy result{.corn = false, .bag = false, .pack = false};
  if (encoded == "-") {
    return result;
  }
  for (const std::string& key : split(encoded, ',')) {
    const auto kind = disposal::KindFromKey(key);
    if (!kind.has_value()) {
      throw std::runtime_error("policy_key_invalid");
    }
    switch (*kind) {
      case disposal::GarbageKind::corn:
        result.corn = true;
        break;
      case disposal::GarbageKind::bag:
        result.bag = true;
        break;
      case disposal::GarbageKind::pack:
        result.pack = true;
        break;
    }
  }
  return result;
}

[[nodiscard]] std::vector<disposal::Candidate> candidates(
    const std::string_view encoded) {
  if (encoded == "-") {
    return {};
  }
  std::vector<disposal::Candidate> result;
  for (const std::string& item : split(encoded, ';')) {
    const auto fields = split(item, '~');
    if (fields.size() != 4) {
      throw std::runtime_error("candidate_invalid");
    }
    const auto kind = disposal::KindFromKey(fields[0]);
    if (!kind.has_value()) {
      throw std::runtime_error("candidate_key_invalid");
    }
    result.push_back(disposal::Candidate{
        .kind = *kind,
        .normalized_x = std::stod(fields[1]),
        .normalized_y = std::stod(fields[2]),
        .confidence = std::stod(fields[3]),
    });
  }
  return result;
}

[[nodiscard]] std::string encode(const disposal::DisposalPlan& plan) {
  if (plan.targets.empty()) {
    return "-";
  }
  std::ostringstream output;
  for (std::size_t index = 0; index < plan.targets.size(); ++index) {
    if (index != 0) {
      output << ',';
    }
    output << disposal::Key(plan.targets[index].kind);
  }
  return output.str();
}

int run(const std::string& path) {
  std::ifstream input(path);
  if (!input) {
    throw std::runtime_error("corpus_open_failed");
  }
  std::string line;
  std::getline(input, line);
  std::size_t line_number = 1;
  std::size_t cases = 0;
  while (std::getline(input, line)) {
    ++line_number;
    if (line.empty()) {
      continue;
    }
    const auto fields = split(line, '\t');
    if (fields.size() != 4) {
      throw std::runtime_error("corpus_field_count_invalid");
    }
    const auto input_candidates = candidates(fields[2]);
    const auto plan = disposal::PlanDisposal(
        input_candidates,
        policy(fields[1]));
    if (encode(plan) != fields[3]) {
      throw std::runtime_error(
          "line_" + std::to_string(line_number) + "_order_changed");
    }
    ++cases;
  }
  if (cases == 0) {
    throw std::runtime_error("corpus_empty");
  }
  if (disposal::LegacyName(disposal::GarbageKind::pack) !=
      "empty cigarette pack") {
    throw std::runtime_error("legacy_name_changed");
  }
  bool invalid_rejected = false;
  try {
    const disposal::Candidate invalid{
        .kind = disposal::GarbageKind::bag,
        .normalized_x = 1.1,
        .normalized_y = 0.5,
        .confidence = 0.9,
    };
    static_cast<void>(disposal::PlanDisposal(
        std::span(&invalid, 1),
        disposal::SelectionPolicy{}));
  } catch (const std::invalid_argument&) {
    invalid_rejected = true;
  }
  if (!invalid_rejected) {
    throw std::runtime_error("invalid_candidate_accepted");
  }
  std::cout << "PASS " << cases
            << " Python/C++ garbage-disposal corpus rows\n";
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
