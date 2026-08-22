#include "sonar/fishing/catch_quality/catch_quality.h"

#include <array>
#include <cstddef>
#include <cstdint>

namespace sonar::fishing::catch_quality {
namespace {

struct CatchSizeType {
    std::string_view key;
    std::string_view label;
    std::string_view marker;
};

constexpr std::array<CatchSizeType, 4> kCatchSizeTypes{{
    {"modest", "Скромный улов", "скром"},
    {"good", "Хороший улов", "хорош"},
    {"record", "Рекордный улов", "рекорд"},
    {"trophy", "Трофейная", "троф"},
}};

constexpr std::string_view kUnknownCatchSizeKey = "unknown";
constexpr std::string_view kUnknownCatchSizeLabel = "Не распознано";

struct DecodedCodePoint {
    std::uint32_t value;
    std::size_t begin;
    std::size_t end;
    bool valid;
};

[[nodiscard]] bool IsContinuationByte(unsigned char value) noexcept {
    return (value & 0xC0U) == 0x80U;
}

[[nodiscard]] DecodedCodePoint DecodeNext(
    std::string_view text,
    std::size_t& cursor) noexcept {
    const std::size_t begin = cursor;
    const auto first = static_cast<unsigned char>(text[cursor]);
    if (first < 0x80U) {
        ++cursor;
        return {first, begin, cursor, true};
    }

    std::size_t length = 0;
    std::uint32_t value = 0;
    std::uint32_t minimum = 0;
    if ((first & 0xE0U) == 0xC0U) {
        length = 2;
        value = first & 0x1FU;
        minimum = 0x80U;
    } else if ((first & 0xF0U) == 0xE0U) {
        length = 3;
        value = first & 0x0FU;
        minimum = 0x800U;
    } else if ((first & 0xF8U) == 0xF0U) {
        length = 4;
        value = first & 0x07U;
        minimum = 0x10000U;
    } else {
        ++cursor;
        return {first, begin, cursor, false};
    }

    if (cursor + length > text.size()) {
        ++cursor;
        return {first, begin, cursor, false};
    }

    for (std::size_t offset = 1; offset < length; ++offset) {
        const auto next = static_cast<unsigned char>(text[cursor + offset]);
        if (!IsContinuationByte(next)) {
            ++cursor;
            return {first, begin, cursor, false};
        }
        value = (value << 6U) | (next & 0x3FU);
    }

    cursor += length;
    const bool is_surrogate = value >= 0xD800U && value <= 0xDFFFU;
    if (value < minimum || value > 0x10FFFFU || is_surrogate) {
        cursor = begin + 1;
        return {first, begin, cursor, false};
    }
    return {value, begin, cursor, true};
}

void AppendUtf8(std::uint32_t value, std::string& target) {
    if (value <= 0x7FU) {
        target.push_back(static_cast<char>(value));
    } else if (value <= 0x7FFU) {
        target.push_back(static_cast<char>(0xC0U | (value >> 6U)));
        target.push_back(static_cast<char>(0x80U | (value & 0x3FU)));
    } else if (value <= 0xFFFFU) {
        target.push_back(static_cast<char>(0xE0U | (value >> 12U)));
        target.push_back(static_cast<char>(0x80U | ((value >> 6U) & 0x3FU)));
        target.push_back(static_cast<char>(0x80U | (value & 0x3FU)));
    } else {
        target.push_back(static_cast<char>(0xF0U | (value >> 18U)));
        target.push_back(static_cast<char>(0x80U | ((value >> 12U) & 0x3FU)));
        target.push_back(static_cast<char>(0x80U | ((value >> 6U) & 0x3FU)));
        target.push_back(static_cast<char>(0x80U | (value & 0x3FU)));
    }
}

[[nodiscard]] std::uint32_t LowerForClassifier(std::uint32_t value) noexcept {
    if (value >= 'A' && value <= 'Z') {
        return value + ('a' - 'A');
    }
    if (value >= 0x0410U && value <= 0x042FU) {
        return value + 0x20U;
    }
    if (value == 0x0401U) {
        return 0x0451U;
    }
    return value;
}

[[nodiscard]] bool IsClassifierCodePoint(std::uint32_t value) noexcept {
    return (value >= '0' && value <= '9') ||
           (value >= 'a' && value <= 'z') ||
           (value >= 0x0430U && value <= 0x044FU) || value == 0x0451U;
}

[[nodiscard]] bool IsPythonWhitespace(std::uint32_t value) noexcept {
    return (value >= 0x09U && value <= 0x0DU) ||
           (value >= 0x1CU && value <= 0x20U) || value == 0x85U ||
           value == 0xA0U || value == 0x1680U ||
           (value >= 0x2000U && value <= 0x200AU) ||
           value == 0x2028U || value == 0x2029U || value == 0x202FU ||
           value == 0x205FU || value == 0x3000U;
}

[[nodiscard]] std::string BuildClassifierText(std::string_view text) {
    std::string result;
    result.reserve(text.size());
    std::size_t cursor = 0;
    while (cursor < text.size()) {
        const DecodedCodePoint decoded = DecodeNext(text, cursor);
        if (!decoded.valid) {
            continue;
        }
        const std::uint32_t lowered = LowerForClassifier(decoded.value);
        if (IsClassifierCodePoint(lowered)) {
            AppendUtf8(lowered, result);
        }
    }
    return result;
}

[[nodiscard]] std::string CollapsePythonWhitespace(std::string_view text) {
    std::string result;
    result.reserve(text.size());
    bool pending_space = false;
    std::size_t cursor = 0;
    while (cursor < text.size()) {
        const DecodedCodePoint decoded = DecodeNext(text, cursor);
        if (decoded.valid && IsPythonWhitespace(decoded.value)) {
            pending_space = !result.empty();
            continue;
        }
        if (pending_space) {
            result.push_back(' ');
            pending_space = false;
        }
        result.append(text.substr(decoded.begin, decoded.end - decoded.begin));
    }
    return result;
}

}  // namespace

std::optional<std::string> NormalizeCatchSize(
    std::optional<std::string_view> text) {
    if (!text.has_value() || text->empty()) {
        return std::nullopt;
    }

    const std::string classifier_text = BuildClassifierText(*text);
    for (const CatchSizeType& item : kCatchSizeTypes) {
        if (classifier_text.find(item.marker) != std::string::npos) {
            return std::string(item.label);
        }
    }
    return CollapsePythonWhitespace(*text);
}

std::string_view CatchSizeKey(
    std::optional<std::string_view> label) noexcept {
    if (!label.has_value() || label->empty()) {
        return kUnknownCatchSizeKey;
    }
    for (const CatchSizeType& item : kCatchSizeTypes) {
        if (*label == item.label) {
            return item.key;
        }
    }
    return kUnknownCatchSizeKey;
}

std::string_view CatchSizeLabel(std::string_view key) noexcept {
    for (const CatchSizeType& item : kCatchSizeTypes) {
        if (key == item.key) {
            return item.label;
        }
    }
    return kUnknownCatchSizeLabel;
}

}  // namespace sonar::fishing::catch_quality
