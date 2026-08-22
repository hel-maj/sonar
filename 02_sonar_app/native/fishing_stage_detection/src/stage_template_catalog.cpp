#include "stage_template_catalog.h"

#include "embedded_stage_assets.h"

#include <charconv>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <span>
#include <stdexcept>
#include <string_view>
#include <vector>

namespace sonar::fishing::stage_detection::detail {
namespace {

[[nodiscard]] std::string_view next_token(
    const std::span<const std::uint8_t> bytes,
    std::size_t& cursor) {
  while (cursor < bytes.size()) {
    if (bytes[cursor] == '#') {
      while (cursor < bytes.size() && bytes[cursor] != '\n') {
        ++cursor;
      }
      continue;
    }
    if (std::isspace(static_cast<unsigned char>(bytes[cursor])) == 0) {
      break;
    }
    ++cursor;
  }
  const auto begin = cursor;
  while (cursor < bytes.size() &&
         std::isspace(static_cast<unsigned char>(bytes[cursor])) == 0) {
    ++cursor;
  }
  return {
      reinterpret_cast<const char*>(bytes.data() + begin),
      cursor - begin,
  };
}

[[nodiscard]] std::uint32_t parse_u32(const std::string_view token) {
  std::uint32_t value = 0;
  const auto [end, error] = std::from_chars(
      token.data(), token.data() + token.size(), value);
  if (error != std::errc{} || end != token.data() + token.size() || value == 0) {
    throw std::runtime_error("fishing_stage_template_header_invalid");
  }
  return value;
}

[[nodiscard]] gray_image parse_pgm(const embedded_stage_asset_id id) {
  const auto bytes = embedded_stage_asset(id);
  std::size_t cursor = 0;
  if (next_token(bytes, cursor) != "P5") {
    throw std::runtime_error("fishing_stage_template_magic_invalid");
  }
  const auto width = parse_u32(next_token(bytes, cursor));
  const auto height = parse_u32(next_token(bytes, cursor));
  if (parse_u32(next_token(bytes, cursor)) != 255 || cursor >= bytes.size() ||
      std::isspace(static_cast<unsigned char>(bytes[cursor])) == 0) {
    throw std::runtime_error("fishing_stage_template_header_invalid");
  }
  if (bytes[cursor] == '\r' && cursor + 1 < bytes.size() &&
      bytes[cursor + 1] == '\n') {
    cursor += 2;
  } else {
    ++cursor;
  }
  const auto pixel_count = static_cast<std::size_t>(width) * height;
  if (width > std::numeric_limits<std::size_t>::max() / height ||
      bytes.size() - cursor != pixel_count) {
    throw std::runtime_error("fishing_stage_template_payload_invalid");
  }
  return {
      .width = width,
      .height = height,
      .pixels = std::vector<std::uint8_t>(
          bytes.begin() + static_cast<std::ptrdiff_t>(cursor), bytes.end()),
  };
}

[[nodiscard]] stage_template_catalog load_catalog(const bool two_k) {
  using id = embedded_stage_asset_id;
  return {
      .ad = parse_pgm(two_k ? id::ad_2k : id::ad_fhd),
      .start = parse_pgm(two_k ? id::start_2k : id::start_fhd),
      .cast = parse_pgm(two_k ? id::cast_2k : id::cast_fhd),
      .hook = parse_pgm(two_k ? id::hook_2k : id::hook_fhd),
      .wait = parse_pgm(two_k ? id::wait_2k : id::wait_fhd),
  };
}

}  // namespace

const stage_template_catalog& stage_templates(
    const stage_resolution_profile profile) {
  static const auto full_hd = load_catalog(false);
  static const auto two_k = load_catalog(true);
  return profile == stage_resolution_profile::two_k ? two_k : full_hd;
}

}  // namespace sonar::fishing::stage_detection::detail
