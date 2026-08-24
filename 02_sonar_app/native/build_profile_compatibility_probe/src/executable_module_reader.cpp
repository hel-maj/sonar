#include "executable_module_reader.h"

#include <algorithm>
#include <array>
#include <cstring>
#include <limits>
#include <span>
#include <utility>

namespace sonar::fishing::build_profile_compatibility_probe::detail {
namespace {

namespace memory = sonar::fishing::memory_observation;

constexpr std::size_t kScanChunkBytes = 64U * 1024U;
constexpr std::size_t kMinimumRetrySliceBytes = 4U * 1024U;
constexpr std::size_t kMaximumScannedModuleBytes = 256U * 1024U * 1024U;
constexpr std::size_t kMaximumScanReadBudgetBytes =
    1024U * 1024U * 1024U;
constexpr std::size_t kMaximumPeHeaderOffset = 1024U * 1024U;
constexpr std::size_t kMaximumPeOptionalHeaderBytes = 4096U;
constexpr std::size_t kMaximumPeSections = 96U;
constexpr std::uintptr_t kMinimumUserPointer = 0x10000U;
constexpr std::uintptr_t kMaximumUserPointer = 0x00007FFF'FFFF'FFFFULL;
constexpr std::uint16_t kDosMagic = 0x5A4DU;
constexpr std::uint16_t kPe32PlusMagic = 0x020BU;
constexpr std::uint16_t kAmd64Machine = 0x8664U;
constexpr std::uint32_t kPeSignature = 0x00004550U;
constexpr std::uint32_t kImageSectionMemExecute = 0x20000000U;

[[nodiscard]] bool plausible_pointer(const std::uintptr_t value) noexcept {
  return value >= kMinimumUserPointer && value <= kMaximumUserPointer;
}

struct scan_read_budget final {
  std::size_t used{};

  [[nodiscard]] bool consume(const std::size_t value) noexcept {
    if (used > kMaximumScanReadBudgetBytes ||
        value > kMaximumScanReadBudgetBytes - used) {
      return false;
    }
    used += value;
    return true;
  }
};

[[nodiscard]] std::size_t split_offset(const std::size_t size) noexcept {
  if (size <= kMinimumRetrySliceBytes) {
    return 0U;
  }
  const auto half = size / 2U;
  auto split = half / kMinimumRetrySliceBytes * kMinimumRetrySliceBytes;
  if (split == 0U || split >= size) {
    split = half;
  }
  return split > 0U && split < size ? split : 0U;
}

[[nodiscard]] bool read_with_exact_coverage(
    memory::readonly_memory_session& session,
    const std::uintptr_t address,
    const std::span<std::byte> destination,
    scan_read_budget& budget) noexcept {
  if (destination.empty() || !plausible_pointer(address) ||
      destination.size() >
          (std::numeric_limits<std::uintptr_t>::max)() - address ||
      !budget.consume(destination.size())) {
    return false;
  }
  if (session.read_exact(address, destination)) {
    return true;
  }

  const auto split = split_offset(destination.size());
  if (split == 0U) {
    // A retry must overwrite the whole failed leaf; partially copied bytes
    // from the failed exact read never enter the scan image.
    return budget.consume(destination.size()) &&
        session.read_exact(address, destination);
  }
  return read_with_exact_coverage(
             session, address, destination.first(split), budget) &&
      read_with_exact_coverage(
          session, address + split, destination.subspan(split), budget);
}

template <typename Value>
[[nodiscard]] bool copy_scalar(
    const std::span<const std::byte> source,
    const std::size_t offset,
    Value& destination) noexcept {
  if (offset > source.size() || sizeof(Value) > source.size() - offset) {
    return false;
  }
  std::memcpy(&destination, source.data() + offset, sizeof(Value));
  return true;
}

struct executable_section_layout final {
  std::size_t relative_address{};
  std::size_t size{};
};

[[nodiscard]] bool module_range(
    const sonar::platform::windows::module_snapshot& module,
    const std::size_t offset,
    const std::size_t size,
    std::uintptr_t& address) noexcept {
  if (!plausible_pointer(module.base_address) || module.size == 0U ||
      module.size > kMaximumScannedModuleBytes ||
      module.size > (std::numeric_limits<std::size_t>::max)() ||
      offset > module.size || size > module.size - offset ||
      offset > (std::numeric_limits<std::uintptr_t>::max)() -
          module.base_address) {
    return false;
  }
  address = module.base_address + offset;
  return plausible_pointer(address) &&
      size <= (std::numeric_limits<std::uintptr_t>::max)() - address;
}

[[nodiscard]] bool read_module_bytes(
    memory::readonly_memory_session& session,
    const sonar::platform::windows::module_snapshot& module,
    const std::size_t offset,
    const std::span<std::byte> destination,
    scan_read_budget& budget) noexcept {
  std::uintptr_t address{};
  return module_range(module, offset, destination.size(), address) &&
      read_with_exact_coverage(session, address, destination, budget);
}

[[nodiscard]] std::optional<std::vector<executable_section_layout>>
parse_executable_sections(
    memory::readonly_memory_session& session,
    const sonar::platform::windows::module_snapshot& module,
    scan_read_budget& budget) {
  std::array<std::byte, 64U> dos{};
  if (!read_module_bytes(session, module, 0U, dos, budget)) {
    return std::nullopt;
  }
  std::uint16_t dos_magic{};
  std::uint32_t nt_offset{};
  if (!copy_scalar(dos, 0U, dos_magic) || dos_magic != kDosMagic ||
      !copy_scalar(dos, 0x3CU, nt_offset) || nt_offset < dos.size() ||
      nt_offset > kMaximumPeHeaderOffset) {
    return std::nullopt;
  }

  std::array<std::byte, 24U> nt_fixed{};
  if (!read_module_bytes(session, module, nt_offset, nt_fixed, budget)) {
    return std::nullopt;
  }
  std::uint32_t signature{};
  std::uint16_t machine{};
  std::uint16_t section_count{};
  std::uint16_t optional_size{};
  if (!copy_scalar(nt_fixed, 0U, signature) || signature != kPeSignature ||
      !copy_scalar(nt_fixed, 4U, machine) || machine != kAmd64Machine ||
      !copy_scalar(nt_fixed, 6U, section_count) || section_count == 0U ||
      section_count > kMaximumPeSections ||
      !copy_scalar(nt_fixed, 20U, optional_size) || optional_size < 64U ||
      optional_size > kMaximumPeOptionalHeaderBytes) {
    return std::nullopt;
  }

  const auto optional_offset = static_cast<std::size_t>(nt_offset) +
      nt_fixed.size();
  std::vector<std::byte> optional(optional_size);
  if (!read_module_bytes(session, module, optional_offset, optional, budget)) {
    return std::nullopt;
  }
  std::uint16_t optional_magic{};
  std::uint32_t size_of_image{};
  std::uint32_t size_of_headers{};
  if (!copy_scalar(optional, 0U, optional_magic) ||
      optional_magic != kPe32PlusMagic ||
      !copy_scalar(optional, 56U, size_of_image) ||
      !copy_scalar(optional, 60U, size_of_headers) ||
      static_cast<std::uint64_t>(size_of_image) != module.size ||
      size_of_headers == 0U ||
      static_cast<std::uint64_t>(size_of_headers) > module.size) {
    return std::nullopt;
  }

  const auto section_table_offset = optional_offset + optional.size();
  const auto section_table_size =
      static_cast<std::size_t>(section_count) * 40U;
  if (section_table_offset > size_of_headers ||
      section_table_size > size_of_headers - section_table_offset) {
    return std::nullopt;
  }
  std::vector<std::byte> table(section_table_size);
  if (!read_module_bytes(
          session, module, section_table_offset, table, budget)) {
    return std::nullopt;
  }

  std::vector<executable_section_layout> sections;
  std::size_t total_size{};
  for (std::size_t index = 0U; index < section_count; ++index) {
    const auto offset = index * 40U;
    std::uint32_t virtual_size{};
    std::uint32_t virtual_address{};
    std::uint32_t raw_size{};
    std::uint32_t characteristics{};
    if (!copy_scalar(table, offset + 8U, virtual_size) ||
        !copy_scalar(table, offset + 12U, virtual_address) ||
        !copy_scalar(table, offset + 16U, raw_size) ||
        !copy_scalar(table, offset + 36U, characteristics)) {
      return std::nullopt;
    }
    if ((characteristics & kImageSectionMemExecute) == 0U) {
      continue;
    }
    const auto section_address = static_cast<std::size_t>(virtual_address);
    const auto section_size = static_cast<std::size_t>(
        virtual_size == 0U ? raw_size : virtual_size);
    const auto image_size = static_cast<std::size_t>(size_of_image);
    if (section_address < static_cast<std::size_t>(size_of_headers) ||
        section_size == 0U ||
        section_address > image_size ||
        section_size > image_size - section_address ||
        total_size > kMaximumScannedModuleBytes - section_size) {
      return std::nullopt;
    }
    total_size += section_size;
    sections.push_back({section_address, section_size});
  }
  if (sections.empty()) {
    return std::nullopt;
  }
  std::ranges::sort(sections, {}, &executable_section_layout::relative_address);
  for (std::size_t index = 1U; index < sections.size(); ++index) {
    const auto& previous = sections[index - 1U];
    if (sections[index].relative_address <
        previous.relative_address + previous.size) {
      return std::nullopt;
    }
  }
  return sections;
}

[[nodiscard]] bool read_fully_covered_section(
    memory::readonly_memory_session& session,
    const std::uintptr_t section_address,
    const std::span<std::byte> destination,
    scan_read_budget& budget) {
  if (!plausible_pointer(section_address) || destination.empty() ||
      destination.size() >
          (std::numeric_limits<std::uintptr_t>::max)() - section_address) {
    return false;
  }
  const auto section_end = section_address + destination.size();
  auto cursor = section_address;
  while (cursor < section_end) {
    const auto region = session.query_region(cursor);
    if (!region.has_value() || region->size == 0U ||
        region->base_address > cursor ||
        region->size > (std::numeric_limits<std::uintptr_t>::max)() -
                region->base_address) {
      return false;
    }
    const auto region_end = region->base_address +
        static_cast<std::uintptr_t>(region->size);
    if (cursor >= region_end || !region->committed_readable()) {
      return false;
    }
    const auto covered_end = (std::min)(section_end, region_end);
    while (cursor < covered_end) {
      const auto count = static_cast<std::size_t>((std::min)(
          static_cast<std::uintptr_t>(kScanChunkBytes),
          covered_end - cursor));
      const auto offset = static_cast<std::size_t>(
          cursor - section_address);
      if (!read_with_exact_coverage(
              session,
              cursor,
              destination.subspan(offset, count),
              budget)) {
        return false;
      }
      cursor += count;
    }
  }
  return true;
}

}  // namespace

executable_module_read read_executable_module(
    memory::readonly_memory_session& session,
    const sonar::platform::windows::module_snapshot& module) {
  scan_read_budget budget;
  const auto layouts = parse_executable_sections(session, module, budget);
  if (!layouts.has_value()) {
    return {};
  }
  executable_module_image image{
      .base = module.base_address,
      .size = static_cast<std::size_t>(module.size),
  };
  image.executable_sections.reserve(layouts->size());
  for (const auto& layout : *layouts) {
    std::uintptr_t address{};
    if (!module_range(
            module, layout.relative_address, layout.size, address)) {
      return {};
    }
    executable_section_image section{
        .address = address,
        .bytes = std::vector<std::byte>(layout.size),
    };
    if (!read_fully_covered_section(
            session, section.address, section.bytes, budget)) {
      return {.status = executable_module_read_status::scan_incomplete};
    }
    image.executable_sections.push_back(std::move(section));
  }
  return {
      .image = std::move(image),
      .status = executable_module_read_status::ready,
  };
}

}  // namespace sonar::fishing::build_profile_compatibility_probe::detail
