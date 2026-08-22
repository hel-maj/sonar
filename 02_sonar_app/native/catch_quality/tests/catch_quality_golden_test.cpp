#include "sonar/fishing/catch_quality/catch_quality.h"

#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace {

using sonar::fishing::catch_quality::CatchSizeKey;
using sonar::fishing::catch_quality::CatchSizeLabel;
using sonar::fishing::catch_quality::NormalizeCatchSize;

[[nodiscard]] std::vector<std::string_view> SplitTabs(const std::string& line) {
    std::vector<std::string_view> fields;
    std::size_t begin = 0;
    while (true) {
        const std::size_t separator = line.find('\t', begin);
        if (separator == std::string::npos) {
            fields.emplace_back(line.data() + begin, line.size() - begin);
            return fields;
        }
        fields.emplace_back(line.data() + begin, separator - begin);
        begin = separator + 1;
    }
}

[[nodiscard]] bool IsValueKind(std::string_view kind) noexcept {
    return kind == "none" || kind == "empty" || kind == "text";
}

[[nodiscard]] std::optional<std::string_view> DecodeOptional(
    std::string_view kind,
    std::string_view value) {
    if (kind == "none") {
        return std::nullopt;
    }
    if (kind == "empty") {
        return std::string_view{};
    }
    return value;
}

[[nodiscard]] bool MatchesExpected(
    const std::optional<std::string>& actual,
    std::string_view expected_kind,
    std::string_view expected) {
    if (expected_kind == "none") {
        return !actual.has_value();
    }
    if (!actual.has_value()) {
        return false;
    }
    if (expected_kind == "empty") {
        return actual->empty();
    }
    return *actual == expected;
}

void ReportFailure(
    std::size_t line_number,
    std::string_view case_id,
    std::string_view message,
    int& failures) {
    std::cerr << "line " << line_number << " (" << case_id << "): "
              << message << '\n';
    ++failures;
}

}  // namespace

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage: SonarFishingCatchQualityTests <legacy_oracle.tsv>\n";
        return 2;
    }

    std::ifstream corpus(argv[1], std::ios::binary);
    if (!corpus) {
        std::cerr << "cannot open corpus: " << argv[1] << '\n';
        return 2;
    }

    constexpr std::string_view kHeader =
        "case_id\toperation\tinput_kind\tinput\texpected_kind\texpected";
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

        const std::vector<std::string_view> fields = SplitTabs(line);
        if (fields.size() != 6) {
            ReportFailure(line_number, "invalid-row", "expected six TSV fields", failures);
            continue;
        }
        const std::string_view case_id = fields[0];
        const std::string_view operation = fields[1];
        const std::string_view input_kind = fields[2];
        const std::string_view input = fields[3];
        const std::string_view expected_kind = fields[4];
        const std::string_view expected = fields[5];
        if (!IsValueKind(input_kind) || !IsValueKind(expected_kind)) {
            ReportFailure(line_number, case_id, "invalid value kind", failures);
            continue;
        }
        ++cases;

        const std::optional<std::string_view> decoded_input =
            DecodeOptional(input_kind, input);
        if (operation == "normalize") {
            const std::optional<std::string> actual = NormalizeCatchSize(decoded_input);
            if (!MatchesExpected(actual, expected_kind, expected)) {
                ReportFailure(line_number, case_id, "normalization mismatch", failures);
            }
        } else if (operation == "key") {
            if (expected_kind != "text" || CatchSizeKey(decoded_input) != expected) {
                ReportFailure(line_number, case_id, "key mismatch", failures);
            }
        } else if (operation == "label") {
            if (!decoded_input.has_value() || expected_kind != "text" ||
                CatchSizeLabel(*decoded_input) != expected) {
                ReportFailure(line_number, case_id, "label mismatch", failures);
            }
        } else {
            ReportFailure(line_number, case_id, "unknown operation", failures);
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

    std::cout << cases << " catch-quality golden cases passed\n";
    return 0;
}
