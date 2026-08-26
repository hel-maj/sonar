#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>

#include "sonar/fishing/memory_observation/memory_observation.h"

namespace sonar::fishing::memory_observation::detail {

struct executable_section_image final {
  std::uintptr_t address{};
  std::vector<std::byte> bytes;
};

struct executable_module_image final {
  std::uintptr_t base{};
  std::size_t size{};
  std::vector<executable_section_image> executable_sections;
};

enum class executable_module_read_status : std::uint8_t {
  ready = 0,
  layout_unavailable,
  scan_incomplete,
};

struct executable_module_read final {
  std::optional<executable_module_image> image;
  executable_module_read_status status{
      executable_module_read_status::layout_unavailable};
};

// Reads a bounded PE64 layout, then copies only fully covered committed and
// readable executable sections. A permanent hole leaves the entire module
// image unavailable; no partial executable image is returned.
[[nodiscard]] executable_module_read read_executable_module(
    readonly_memory_session& session,
    const sonar::platform::windows::module_snapshot& module);

}  // namespace sonar::fishing::memory_observation::detail
