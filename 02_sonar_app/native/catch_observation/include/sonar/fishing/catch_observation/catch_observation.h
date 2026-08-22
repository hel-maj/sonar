#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

namespace sonar::fishing::catch_observation {

struct RawCatchText {
  std::optional<std::string_view> fish;
  std::optional<std::string_view> quality;
  std::optional<std::string_view> weight;
  std::optional<std::string_view> experience;
};

struct ExperienceReading {
  bool is_max_level;
  std::optional<std::uint64_t> current;
  std::optional<std::uint64_t> total;
};

struct CatchObservation {
  bool valid_content;
  std::optional<std::string> fish_id;
  std::optional<std::string> fish_text;
  double fish_confidence;
  std::optional<std::string> quality_label;
  std::string quality_key;
  std::optional<double> weight_kg;
  ExperienceReading experience;
};

// Interprets one already-extracted OCR fact set as an atomic Engine-internal
// observation. Frame capture, OCR, decision, final gates, and input never cross
// Host IPC as separate operations.
[[nodiscard]] CatchObservation Interpret(const RawCatchText& raw);

[[nodiscard]] std::optional<double> ParseWeight(
    std::optional<std::string_view> text);

[[nodiscard]] ExperienceReading ParseExperience(
    std::optional<std::string_view> text);

}  // namespace sonar::fishing::catch_observation
