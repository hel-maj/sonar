#include "inventory_state_characterization.h"

#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <span>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

#include "sonar/fishing/memory_observation/memory_observation.h"
#include "sonar/platform/windows/process.hpp"
#include "windows_forensic_memory_connector.h"

namespace probe = sonar::fishing::build_profile_compatibility_probe;
namespace memory = sonar::fishing::memory_observation;
namespace windows = sonar::platform::windows;

namespace {

constexpr std::uintptr_t minimum_scan_address = 0x10000000000ULL;
constexpr std::uintptr_t maximum_scan_address = 0x40000000000ULL;
constexpr std::size_t maximum_total_bytes = 512U * 1024U * 1024U;
constexpr std::size_t maximum_region_bytes = 16U * 1024U * 1024U;
constexpr std::size_t maximum_enumerated_regions = 32U * 1024U;
constexpr std::size_t read_chunk_bytes = 64U * 1024U;
constexpr std::size_t validation_cycles = 2U;
constexpr std::size_t samples_per_state = 3U;
constexpr auto sample_interval = std::chrono::milliseconds(120);

struct scan_region final {
  std::uintptr_t address{};
  std::size_t size{};
};

[[nodiscard]] std::string narrow_ascii(const std::wstring_view value) {
  std::string result;
  result.reserve(value.size());
  for (const auto character : value) {
    result.push_back(character >= 0 && character <= 0x7F
        ? static_cast<char>(character)
        : '?');
  }
  return result;
}

[[nodiscard]] std::string hex_address(const std::uintptr_t value) {
  std::ostringstream output;
  output << "0x" << std::uppercase << std::hex << value;
  return output.str();
}

[[nodiscard]] bool prompt(const std::string_view state) {
  std::cerr << "Set inventory " << state
            << ", wait until the transition is complete, then press Enter...\n";
  std::string line;
  return static_cast<bool>(std::getline(std::cin, line));
}

[[nodiscard]] std::optional<std::vector<scan_region>> select_regions(
    memory::readonly_memory_session& session) {
  std::vector<scan_region> eligible;
  auto cursor = minimum_scan_address;
  std::size_t enumerated = 0U;
  while (cursor < maximum_scan_address) {
    if (++enumerated > maximum_enumerated_regions) {
      return std::nullopt;
    }
    const auto observed = session.query_region(cursor);
    if (!observed.has_value() || observed->size == 0U ||
        observed->size >
            static_cast<std::uint64_t>(
                (std::numeric_limits<std::uintptr_t>::max)()) ||
        observed->base_address >
            (std::numeric_limits<std::uintptr_t>::max)() -
                static_cast<std::uintptr_t>(observed->size)) {
      return std::nullopt;
    }
    const auto end = observed->base_address +
        static_cast<std::uintptr_t>(observed->size);
    if (observed->base_address > cursor || end <= cursor) {
      return std::nullopt;
    }
    if (observed->committed_readable() &&
        observed->size <= maximum_region_bytes) {
      const auto begin = (std::max)(cursor, minimum_scan_address);
      const auto clipped_end = (std::min)(end, maximum_scan_address);
      if (begin < clipped_end) {
        eligible.push_back({
            begin, static_cast<std::size_t>(clipped_end - begin)});
      }
    }
    cursor = end;
  }
  std::ranges::sort(eligible, [](const auto& left, const auto& right) {
    return left.size != right.size
        ? left.size < right.size
        : left.address < right.address;
  });
  std::vector<scan_region> selected;
  std::size_t total = 0U;
  for (const auto& region : eligible) {
    if (region.size > maximum_total_bytes - total) {
      continue;
    }
    selected.push_back(region);
    total += region.size;
  }
  std::ranges::sort(selected, [](const auto& left, const auto& right) {
    return left.address < right.address;
  });
  return selected.empty()
      ? std::nullopt
      : std::optional(std::move(selected));
}

[[nodiscard]] std::optional<std::vector<probe::inventory_region_image>>
capture_regions(
    memory::readonly_memory_session& session,
    const std::span<const scan_region> regions) {
  if (!session.generation_current()) {
    return std::nullopt;
  }
  std::vector<probe::inventory_region_image> captured;
  captured.reserve(regions.size());
  for (const auto& region : regions) {
    probe::inventory_region_image image{
        .address = region.address,
        .bytes = std::vector<std::byte>(region.size),
    };
    std::size_t consumed = 0U;
    while (consumed < region.size) {
      const auto count = (std::min)(
          read_chunk_bytes, region.size - consumed);
      if (!session.read_exact(
              region.address + consumed,
              std::span(image.bytes).subspan(consumed, count))) {
        return std::nullopt;
      }
      consumed += count;
    }
    captured.push_back(std::move(image));
  }
  return session.generation_current()
      ? std::optional(std::move(captured))
      : std::nullopt;
}

[[nodiscard]] std::optional<probe::inventory_candidate_sample>
capture_candidate_sample(
    memory::readonly_memory_session& session,
    const std::span<const probe::inventory_candidate> candidates,
    const bool open) {
  if (!session.generation_current()) {
    return std::nullopt;
  }
  probe::inventory_candidate_sample sample{.open = open};
  sample.values.reserve(candidates.size());
  for (const auto& candidate : candidates) {
    std::byte value{};
    if (session.read_exact(candidate.address, std::span(&value, 1U))) {
      sample.values.push_back(static_cast<std::uint8_t>(value));
    } else {
      sample.values.push_back(std::nullopt);
    }
  }
  return session.generation_current()
      ? std::optional(std::move(sample))
      : std::nullopt;
}

[[nodiscard]] bool write_receipt(
    const std::string& path,
    const memory::process_identity& identity,
    const std::span<const scan_region> regions,
    const std::size_t discovered_count,
    const probe::inventory_candidate_result& result) {
  std::ofstream output(path, std::ios::binary | std::ios::trunc);
  if (!output) {
    return false;
  }
  std::size_t total = 0U;
  for (const auto& region : regions) {
    total += region.size;
  }
  output << "{\n"
         << "  \"schema_version\": 1,\n"
         << "  \"kind\": \"sonar_fishing_inventory_state_characterization\",\n"
         << "  \"ready\": " << (result.ready() ? "true" : "false")
         << ",\n"
         << "  \"process_id\": " << identity.generation.process_id << ",\n"
         << "  \"process_creation_time_filetime_100ns\": "
         << identity.generation.creation_time_filetime_100ns << ",\n"
         << "  \"image_name\": \"" << narrow_ascii(identity.image_name)
         << "\",\n"
         << "  \"image_sha256\": \"" << identity.image_sha256 << "\",\n"
         << "  \"scan_minimum\": \"" << hex_address(minimum_scan_address)
         << "\",\n"
         << "  \"scan_maximum_exclusive\": \""
         << hex_address(maximum_scan_address) << "\",\n"
         << "  \"scan_region_count\": " << regions.size() << ",\n"
         << "  \"scan_total_bytes\": " << total << ",\n"
         << "  \"discovered_candidate_count\": " << discovered_count
         << ",\n"
         << "  \"validated_candidate_count\": "
         << result.candidates.size() << ",\n"
         << "  \"validation_cycles\": " << validation_cycles << ",\n"
         << "  \"samples_per_state\": " << samples_per_state << ",\n"
         << "  \"reason\": \""
         << (result.ready() ? "ready" : result.reason) << "\",\n"
         << "  \"candidates\": [";
  for (std::size_t index = 0U; index < result.candidates.size(); ++index) {
    const auto& candidate = result.candidates[index];
    output << (index == 0U ? "\n" : ",\n")
           << "    {\"address\": \"" << hex_address(candidate.address)
           << "\", \"closed_value\": "
           << static_cast<unsigned>(candidate.closed_value)
           << ", \"open_value\": "
           << static_cast<unsigned>(candidate.open_value)
           << ", \"accuracy\": " << std::fixed << std::setprecision(6)
           << candidate.accuracy << ", \"samples\": "
           << candidate.total << "}";
  }
  output << (result.candidates.empty() ? "" : "\n  ") << "]\n}\n";
  return output.good();
}

}  // namespace

int main(const int argc, const char* const argv[]) {
  if (argc != 4 ||
      std::string_view(argv[1]) !=
          "--confirmed-manual-inventory-characterization" ||
      std::string_view(argv[2]) != "--output" ||
      std::string_view(argv[3]).empty()) {
    std::cerr << "Explicit manual inventory characterization authority and "
                 "output path are required.\n";
    return 64;
  }
  try {
    const auto process_ids = windows::readonly_process::find_process_ids(
        L"GTA5.exe");
    if (process_ids.size() != 1U) {
      std::cerr << "Exactly one GTA5.exe process is required.\n";
      return 2;
    }
    auto connector = probe::make_windows_forensic_memory_connector();
    std::string reason;
    auto session = connector->connect(
        memory::process_role::game, process_ids.front(), reason);
    if (!session || !session->generation_current()) {
      std::cerr << (reason.empty() ? "memory_process_unavailable" : reason)
                << '\n';
      return 2;
    }
    const auto identity = session->identity();
    const auto regions = select_regions(*session);
    if (!regions.has_value()) {
      std::cerr << "inventory_characterization_region_enumeration_failed\n";
      return 2;
    }

    if (!prompt("CLOSED")) {
      return 2;
    }
    auto closed = capture_regions(*session, *regions);
    if (!closed.has_value()) {
      std::cerr << "inventory_characterization_closed_capture_failed\n";
      return 2;
    }
    if (!prompt("OPEN")) {
      return 2;
    }
    auto open = capture_regions(*session, *regions);
    if (!open.has_value()) {
      std::cerr << "inventory_characterization_open_capture_failed\n";
      return 2;
    }
    auto discovered = probe::discover_inventory_candidates(*closed, *open);
    closed.reset();
    open.reset();
    if (!discovered.ready()) {
      if (!write_receipt(
              argv[3], identity, *regions, 0U, discovered)) {
        return 2;
      }
      return 2;
    }
    const auto discovered_count = discovered.candidates.size();
    std::vector<probe::inventory_candidate_sample> samples;
    samples.reserve(validation_cycles * 2U * samples_per_state);
    for (std::size_t cycle = 0U; cycle < validation_cycles; ++cycle) {
      for (const bool is_open : {false, true}) {
        if (!prompt(is_open ? "OPEN" : "CLOSED")) {
          return 2;
        }
        for (std::size_t sample_index = 0U;
             sample_index < samples_per_state;
             ++sample_index) {
          const auto sample = capture_candidate_sample(
              *session, discovered.candidates, is_open);
          if (!sample.has_value()) {
            std::cerr << "inventory_characterization_validation_read_failed\n";
            return 2;
          }
          samples.push_back(*sample);
          if (sample_index + 1U < samples_per_state) {
            std::this_thread::sleep_for(sample_interval);
          }
        }
      }
    }
    auto validated = probe::validate_inventory_candidates(
        std::move(discovered.candidates), samples);
    if (!write_receipt(
            argv[3], identity, *regions, discovered_count, validated)) {
      std::cerr << "inventory_characterization_receipt_write_failed\n";
      return 2;
    }
    std::cerr << "Inventory characterization receipt: " << argv[3] << '\n';
    return validated.ready() ? 0 : 2;
  } catch (...) {
    std::cerr << "inventory_characterization_internal_error\n";
    return 2;
  }
}
