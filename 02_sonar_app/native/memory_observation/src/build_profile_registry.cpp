#include "sonar/fishing/memory_observation/memory_observation.h"

#include <algorithm>
#include <array>
#include <cwctype>
#include <string>
#include <utility>

namespace sonar::fishing::memory_observation {
namespace {

using pattern_byte = std::int16_t;
constexpr pattern_byte any = -1;

[[nodiscard]] relative_pointer_pattern pattern(
    std::initializer_list<pattern_byte> bytes,
    const std::size_t displacement_offset,
    const std::size_t instruction_length,
    std::initializer_list<std::size_t> dereference_offsets) {
  return {
      .bytes = std::vector<pattern_byte>(bytes),
      .displacement_offset = displacement_offset,
      .instruction_length = instruction_length,
      .dereference_offsets =
          std::vector<std::size_t>(dereference_offsets),
  };
}

[[nodiscard]] embedded_memory_build_profile make_current_profile() {
  return {
      .schema_version = embedded_build_profile_schema_version,
      .profile_id = "majestic-gta5-677e4e35-v1",
      .profile_revision = 1U,
      .game = {
          .image_name = L"GTA5.exe",
          .image_sha256 =
              "677E4E355CFBDB13273B1D992407E3C261B3A108DC4DD5C8A0C4C1DA651802E5",
          .required = true,
      },
      .player_matrix_offsets = {0x50U, 0x40U, 0x60U, 0x30U},
      .fish_position_offsets = {0x90U, 0x130U, 0x120U, 0x110U, 0x160U},
      .fish_model_hash = 802685111U,
      .fish_active_offset = 0x189U,
      .world_patterns = {
          pattern(
              {0x48, 0x8B, 0x05, any, any, any, any,
               0x48, 0x8B, 0x48, 0x08, 0x48, 0x85, 0xC9},
              3U, 7U, {0x8U}),
          pattern(
              {0x48, 0x8B, 0x05, any, any, any, any,
               0xF3, 0x0F, 0x10, 0x50},
              3U, 7U, {0x8U, 0x10U}),
          pattern(
              {0x48, 0x8B, 0x05, any, any, any, any,
               0x48, 0x85, 0xC0},
              3U, 7U, {0x8U, 0x10U, 0x18U}),
          pattern(
              {0x48, 0x8B, 0x0D, any, any, any, any,
               0x48, 0x85, 0xC9},
              3U, 7U, {0x8U}),
          pattern(
              {0x48, 0x8B, 0x05, any, any, any, any, 0x33, 0xFF},
              3U, 7U, {0x8U}),
      },
      .replay_pattern = pattern(
          {0x48, 0x8D, 0x0D, any, any, any, any,
           0x48, 0x8B, 0xD7, 0xE8, any, any, any, any,
           0x48, 0x8D, 0x0D, any, any, any, any,
           0x8A, 0xD8, 0xE8, any, any, any, any,
           0x84, 0xDB, 0x75, 0x13, 0x48, 0x8D, 0x0D},
          3U, 7U, {}),
  };
}

[[nodiscard]] bool same_image_name(
    const std::wstring_view left,
    const std::wstring_view right) noexcept {
  return left.size() == right.size() &&
      std::equal(
          left.begin(), left.end(), right.begin(),
          [](const wchar_t a, const wchar_t b) {
            return std::towlower(a) == std::towlower(b);
          });
}

[[nodiscard]] char lower_hex(const char value) noexcept {
  return value >= 'A' && value <= 'F'
      ? static_cast<char>(value - 'A' + 'a')
      : value;
}

[[nodiscard]] bool same_sha256(
    const std::string_view left,
    const std::string_view right) noexcept {
  return left.size() == 64U && right.size() == 64U &&
      std::equal(
          left.begin(), left.end(), right.begin(),
          [](const char a, const char b) {
            return lower_hex(a) == lower_hex(b);
          });
}

}  // namespace

bool build_profile_selection::ready() const noexcept {
  return profile != nullptr && reason.empty();
}

std::span<const embedded_memory_build_profile>
embedded_memory_build_profiles() noexcept {
  static const std::array profiles{make_current_profile()};
  return profiles;
}

build_profile_selection select_embedded_memory_build_profile(
    const std::wstring_view image_name,
    const std::string_view image_sha256) noexcept {
  try {
    const auto profiles = embedded_memory_build_profiles();
    const embedded_memory_build_profile* selected = nullptr;
    for (const auto& profile : profiles) {
      if (!same_image_name(image_name, profile.game.image_name) ||
          !same_sha256(image_sha256, profile.game.image_sha256)) {
        continue;
      }
      if (selected != nullptr) {
        return {.reason = "memory_build_profile_ambiguous"};
      }
      selected = &profile;
    }
    if (selected == nullptr) {
      return {.reason = "memory_game_build_unsupported"};
    }
    return {.profile = selected};
  } catch (...) {
    return {.reason = "memory_build_profile_selection_failed"};
  }
}

std::string embedded_memory_build_profile_canonical_tsv() {
  return
      "schema_version\tprofile_id\tprofile_revision\tgame_image\tgame_sha256\t"
      "player_matrix_offsets\tfish_position_offsets\tfish_model_hash\t"
      "fish_active_offset\tworld_patterns\treplay_pattern\n"
      "1\tmajestic-gta5-677e4e35-v1\t1\tGTA5.exe\t"
      "677E4E355CFBDB13273B1D992407E3C261B3A108DC4DD5C8A0C4C1DA651802E5\t"
      "0x50,0x40,0x60,0x30\t0x90,0x130,0x120,0x110,0x160\t"
      "802685111\t0x189\t"
      "488B05????????488B48084885C9@3@7@0x8;"
      "488B05????????F30F1050@3@7@0x8,0x10;"
      "488B05????????4885C0@3@7@0x8,0x10,0x18;"
      "488B0D????????4885C9@3@7@0x8;"
      "488B05????????33FF@3@7@0x8\t"
      "488D0D????????488BD7E8????????488D0D????????8AD8E8????????84DB7513488D0D\n";
}

}  // namespace sonar::fishing::memory_observation
