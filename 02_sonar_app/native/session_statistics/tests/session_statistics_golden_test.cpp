#include "sonar/fishing/session_statistics/session_statistics.h"

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace {

namespace statistics = sonar::fishing::session_statistics;

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

[[nodiscard]] double number(const std::string_view text) {
  std::size_t consumed = 0;
  const double value = std::stod(std::string(text), &consumed);
  if (consumed != text.size()) {
    throw std::runtime_error("number_invalid");
  }
  return value;
}

[[nodiscard]] std::uint64_t whole_number(const std::string_view text) {
  std::size_t consumed = 0;
  const unsigned long long value = std::stoull(std::string(text), &consumed);
  if (consumed != text.size()) {
    throw std::runtime_error("whole_number_invalid");
  }
  return static_cast<std::uint64_t>(value);
}

[[nodiscard]] std::optional<std::string_view> optional_text(
    const std::string_view value) {
  return value == "<none>" ? std::nullopt : std::optional(value);
}

[[nodiscard]] std::vector<statistics::TackleItem> tackle_items(
    const std::string_view encoded) {
  if (encoded == "-") {
    return {};
  }
  std::vector<statistics::TackleItem> items;
  for (const std::string& item : split(encoded, ';')) {
    const auto fields = split(item, '~');
    if (fields.size() != 3) {
      throw std::runtime_error("tackle_item_invalid");
    }
    items.push_back(statistics::TackleItem{
        .key = fields[0],
        .name = fields[1],
        .count = static_cast<std::uint32_t>(whole_number(fields[2])),
    });
  }
  return items;
}

[[nodiscard]] std::string encode_tackle(
    const std::vector<statistics::TackleItem>& items) {
  if (items.empty()) {
    return "-";
  }
  std::ostringstream output;
  for (std::size_t index = 0; index < items.size(); ++index) {
    if (index != 0) {
      output << ';';
    }
    output << items[index].key << ':' << items[index].count;
  }
  return output.str();
}

void require_close(
    const double actual,
    const double expected,
    const std::string_view field,
    const std::size_t line_number) {
  if (std::abs(actual - expected) > 1e-9) {
    throw std::runtime_error(
        "line_" + std::to_string(line_number) + "_" +
        std::string(field) + "_changed");
  }
}

void apply_operation(
    statistics::SessionStatistics& state,
    const std::vector<std::string>& fields) {
  const std::string_view operation = fields[2];
  const double now = number(fields[3]);
  if (operation == "start") {
    state.StartTimer(now);
    return;
  }
  if (operation == "stop") {
    state.StopTimer(now);
    return;
  }
  if (operation == "reset") {
    state.Reset(now);
    return;
  }
  if (operation == "observe") {
    return;
  }
  if (operation == "clear_tackle") {
    state.ClearTackleScan();
    return;
  }
  if (operation == "tackle") {
    const auto items = tackle_items(fields[4]);
    state.SetTackleScan(items);
    return;
  }
  if (operation == "custom") {
    state.SetCustomPrice(
        fields[4],
        fields[5] == "none"
            ? std::nullopt
            : std::optional(number(fields[5])));
    return;
  }
  if (operation == "record") {
    const auto release_and_size = split(fields[8], ',');
    if (release_and_size.size() != 2) {
      throw std::runtime_error("record_policy_invalid");
    }
    std::optional<bool> released;
    if (release_and_size[0] == "true") {
      released = true;
    } else if (release_and_size[0] == "false") {
      released = false;
    } else if (release_and_size[0] != "auto") {
      throw std::runtime_error("record_release_invalid");
    }
    state.RecordCatch(statistics::CatchRecord{
        .fish_id = optional_text(fields[4]),
        .fish_name = optional_text(fields[5]),
        .weight_kg = fields[6] == "<none>"
            ? std::nullopt
            : std::optional(number(fields[6])),
        .kept = fields[7] == "1",
        .released = released,
        .catch_size_key = release_and_size[1],
    });
    return;
  }
  throw std::runtime_error("operation_unknown");
}

void require_expected(
    const statistics::SessionStatisticsSnapshot& snapshot,
    const std::vector<std::string>& fields,
    const std::size_t line_number) {
  require_close(
      snapshot.totals.duration_seconds,
      number(fields[9]),
      "duration",
      line_number);
  if (snapshot.totals.caught_count != whole_number(fields[10])) {
    throw std::runtime_error("caught_count_changed");
  }
  require_close(
      snapshot.totals.caught_kg,
      number(fields[11]),
      "caught_kg",
      line_number);
  if (snapshot.totals.released_count != whole_number(fields[12])) {
    throw std::runtime_error("released_count_changed");
  }
  require_close(
      snapshot.totals.released_kg,
      number(fields[13]),
      "released_kg",
      line_number);
  require_close(
      snapshot.totals.earned_min,
      number(fields[14]),
      "earned_min",
      line_number);
  require_close(
      snapshot.totals.earned_max,
      number(fields[15]),
      "earned_max",
      line_number);
  if (encode_tackle(snapshot.tackle_items) != fields[16]) {
    throw std::runtime_error("tackle_snapshot_changed");
  }
}

int run(const std::string& path) {
  const auto default_prices = statistics::DefaultPriceCatalog();
  if (default_prices.size() != 20) {
    throw std::runtime_error("default_price_catalog_size_changed");
  }
  const auto marlin = default_prices.find("marlin");
  if (marlin == default_prices.end() ||
      marlin->second.per_item_min != 0.67 ||
      marlin->second.per_item_max != 0.73 ||
      marlin->second.per_1000_min != 670.0 ||
      marlin->second.per_1000_max != 730.0) {
    throw std::runtime_error("default_price_catalog_marlin_changed");
  }
  if (default_prices.contains("bream_leshch")) {
    throw std::runtime_error("default_price_catalog_optional_price_changed");
  }

  std::ifstream input(path);
  if (!input) {
    throw std::runtime_error("corpus_open_failed");
  }

  std::string line;
  std::getline(input, line);
  std::string active_scenario;
  std::optional<statistics::SessionStatistics> state;
  std::size_t line_number = 1;
  std::size_t cases = 0;
  while (std::getline(input, line)) {
    ++line_number;
    if (line.empty()) {
      continue;
    }
    const auto fields = split(line, '\t');
    if (fields.size() != 17) {
      throw std::runtime_error(
          "line_" + std::to_string(line_number) + "_field_count_invalid");
    }
    if (fields[0] != active_scenario) {
      active_scenario = fields[0];
      statistics::PriceCatalog prices{
          {"marlin", statistics::FishPrice{0.67, 0.73, 670.0, 730.0}},
      };
      state.emplace(std::move(prices));
    }
    apply_operation(*state, fields);
    require_expected(state->Snapshot(number(fields[3])), fields, line_number);
    ++cases;
  }
  if (cases == 0) {
    throw std::runtime_error("corpus_empty");
  }
  std::cout << "PASS " << cases
            << " Python/C++ session-statistics corpus rows\n";
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
