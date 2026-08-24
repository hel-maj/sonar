#include "sonar/fishing/memory_observation/memory_observation.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>
#include <set>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace sonar::fishing::memory_observation {
namespace {

constexpr std::size_t kScanChunkBytes = 64U * 1024U;
constexpr std::uintptr_t kMinimumUserPointer = 0x10000U;
constexpr std::uintptr_t kMaximumUserPointer = 0x00007FFF'FFFF'FFFFULL;
constexpr std::size_t kMaximumInventoryScanBytes = 1024U * 1024U * 1024U;
constexpr std::size_t kMaximumInventoryRegionBytes = 64U * 1024U * 1024U;
constexpr std::size_t kMaximumInventoryRegionCount = 32U * 1024U;
constexpr std::size_t kMaximumInventoryPatternBytes = 64U * 1024U;
constexpr std::size_t kMinimumInventoryExactRunBytes = 16U;
constexpr std::uint64_t kInventoryRediscoveryCooldownNs = 5'000'000'000ULL;

[[nodiscard]] bool matches_at(
    const std::span<const std::byte> bytes,
    const std::size_t offset,
    const masked_memory_pattern& pattern) noexcept {
  if (pattern.bytes.empty() || offset > bytes.size() ||
      pattern.bytes.size() > bytes.size() - offset) {
    return false;
  }
  for (std::size_t index = 0U; index < pattern.bytes.size(); ++index) {
    const auto expected = pattern.bytes[index];
    if (expected >= 0 &&
        static_cast<std::uint8_t>(bytes[offset + index]) !=
            static_cast<std::uint8_t>(expected)) {
      return false;
    }
  }
  return true;
}

struct exact_run final {
  std::size_t offset{};
  std::size_t size{};
};

[[nodiscard]] exact_run longest_exact_run(
    const masked_memory_pattern& pattern) noexcept {
  exact_run best;
  exact_run current;
  for (std::size_t index = 0U; index < pattern.bytes.size(); ++index) {
    if (pattern.bytes[index] >= 0) {
      if (current.size == 0U) {
        current.offset = index;
      }
      ++current.size;
      if (current.size > best.size) {
        best = current;
      }
    } else {
      current = {};
    }
  }
  return best;
}

[[nodiscard]] bool valid_inventory_binding(
    const embedded_inventory_binding& binding) noexcept {
  if (binding.minimum_address_inclusive < kMinimumUserPointer ||
      binding.maximum_address_exclusive <=
          binding.minimum_address_inclusive ||
      binding.maximum_address_exclusive > kMaximumUserPointer + 1U ||
      binding.maximum_scanned_bytes == 0U ||
      binding.maximum_scanned_bytes > kMaximumInventoryScanBytes ||
      binding.maximum_region_bytes == 0U ||
      binding.maximum_region_bytes > kMaximumInventoryRegionBytes ||
      binding.maximum_region_bytes > binding.maximum_scanned_bytes ||
      binding.maximum_enumerated_regions == 0U ||
      binding.maximum_enumerated_regions > kMaximumInventoryRegionCount ||
      binding.maximum_pattern_hits == 0U ||
      binding.maximum_pattern_hits > maximum_inventory_candidates * 8U ||
      binding.slot_stride < binding.slot_pattern.bytes.size() ||
      binding.slot_count == 0U ||
      binding.signals.empty() ||
      binding.slot_pattern.bytes.size() < kMinimumInventoryExactRunBytes ||
      binding.slot_pattern.bytes.size() > kMaximumInventoryPatternBytes ||
      binding.slot_count > maximum_inventory_candidates /
          binding.signals.size() ||
      binding.minimum_votes == 0U ||
      binding.minimum_votes > binding.slot_count * binding.signals.size() ||
      !std::isfinite(binding.minimum_confidence) ||
      binding.minimum_confidence < 0.5 ||
      binding.minimum_confidence > 1.0 ||
      longest_exact_run(binding.slot_pattern).size <
          kMinimumInventoryExactRunBytes) {
    return false;
  }
  std::set<std::size_t> signal_offsets;
  for (const auto& signal : binding.signals) {
    if (signal.offset >= binding.slot_pattern.bytes.size() ||
        binding.slot_pattern.bytes[signal.offset] >= 0 ||
        signal.candidate.closed_value == signal.candidate.open_value ||
        !std::isfinite(signal.candidate.weight) ||
        signal.candidate.weight <= 0.0 ||
        !signal_offsets.insert(signal.offset).second) {
      return false;
    }
  }
  return true;
}

struct inventory_scan_region final {
  std::uintptr_t address{};
  std::size_t size{};
};

struct inventory_discovery final {
  std::vector<std::uintptr_t> hits;
  inventory_binding_failure failure{inventory_binding_failure::none};
};

[[nodiscard]] inventory_discovery inventory_failure(
    const inventory_binding_failure failure) {
  return {.failure = failure};
}

[[nodiscard]] std::optional<std::vector<inventory_scan_region>>
select_inventory_scan_regions(
    readonly_memory_session& session,
    const embedded_inventory_binding& binding) {
  std::vector<inventory_scan_region> eligible;
  auto cursor = binding.minimum_address_inclusive;
  std::size_t enumerated = 0U;
  while (cursor < binding.maximum_address_exclusive) {
    if (++enumerated > binding.maximum_enumerated_regions) {
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
    const auto region_end = observed->base_address +
        static_cast<std::uintptr_t>(observed->size);
    if (observed->base_address > cursor || region_end <= cursor) {
      return std::nullopt;
    }
    if (observed->committed_readable() &&
        observed->size <= binding.maximum_region_bytes) {
      const auto begin = (std::max)(
          cursor, binding.minimum_address_inclusive);
      const auto end = (std::min)(
          region_end, binding.maximum_address_exclusive);
      if (begin < end && end - begin <= binding.maximum_region_bytes) {
        eligible.push_back({begin, static_cast<std::size_t>(end - begin)});
      }
    }
    cursor = region_end;
  }
  std::ranges::sort(
      eligible,
      [](const auto& left, const auto& right) {
        return left.size != right.size
            ? left.size < right.size
            : left.address < right.address;
      });
  std::vector<inventory_scan_region> selected;
  std::size_t total = 0U;
  for (const auto& region : eligible) {
    if (region.size > binding.maximum_scanned_bytes - total) {
      continue;
    }
    selected.push_back(region);
    total += region.size;
  }
  std::ranges::sort(
      selected,
      [](const auto& left, const auto& right) {
        return left.address < right.address;
      });
  return selected;
}

[[nodiscard]] bool append_pattern_hits(
    const std::span<const std::byte> bytes,
    const std::uintptr_t base,
    const masked_memory_pattern& pattern,
    const std::size_t maximum_hits,
    std::vector<std::uintptr_t>& hits) {
  const auto anchor = longest_exact_run(pattern);
  auto search = bytes.begin();
  const auto anchor_begin = pattern.bytes.begin() +
      static_cast<std::ptrdiff_t>(anchor.offset);
  const auto anchor_end = anchor_begin +
      static_cast<std::ptrdiff_t>(anchor.size);
  while (search != bytes.end()) {
    const auto found = std::search(
        search,
        bytes.end(),
        anchor_begin,
        anchor_end,
        [](const std::byte observed, const std::int16_t expected) {
          return static_cast<std::uint8_t>(observed) ==
              static_cast<std::uint8_t>(expected);
        });
    if (found == bytes.end()) {
      break;
    }
    const auto anchor_offset = static_cast<std::size_t>(
        std::distance(bytes.begin(), found));
    if (anchor_offset >= anchor.offset) {
      const auto candidate_offset = anchor_offset - anchor.offset;
      if (matches_at(bytes, candidate_offset, pattern)) {
        const auto address = base + candidate_offset;
        if (hits.empty() || address > hits.back()) {
          hits.push_back(address);
          if (hits.size() > maximum_hits) {
            return false;
          }
        }
      }
    }
    search = found + 1;
  }
  return true;
}

[[nodiscard]] inventory_discovery discover_inventory_hits(
    readonly_memory_session& session,
    const embedded_inventory_binding& binding) {
  const auto selected = select_inventory_scan_regions(session, binding);
  if (!selected.has_value()) {
    return inventory_failure(
        inventory_binding_failure::region_enumeration_failed);
  }
  std::vector<std::uintptr_t> hits;
  std::vector<std::byte> overlap;
  std::vector<std::byte> chunk;
  for (const auto& region : *selected) {
    overlap.clear();
    std::size_t consumed = 0U;
    while (consumed < region.size) {
      const auto count = (std::min)(
          kScanChunkBytes, region.size - consumed);
      chunk.resize(count);
      if (!session.read_exact(region.address + consumed, chunk)) {
        return inventory_failure(
            inventory_binding_failure::scan_incomplete);
      }
      std::vector<std::byte> combined;
      combined.reserve(overlap.size() + chunk.size());
      combined.insert(combined.end(), overlap.begin(), overlap.end());
      combined.insert(combined.end(), chunk.begin(), chunk.end());
      const auto combined_base = region.address + consumed - overlap.size();
      if (!append_pattern_hits(
              combined,
              combined_base,
              binding.slot_pattern,
              binding.maximum_pattern_hits,
              hits)) {
        return inventory_failure(
            inventory_binding_failure::signature_ambiguous);
      }
      const auto retained = (std::min)(
          binding.slot_pattern.bytes.size() - 1U, combined.size());
      overlap.assign(
          combined.end() - static_cast<std::ptrdiff_t>(retained),
          combined.end());
      consumed += count;
    }
  }
  if (hits.empty()) {
    return inventory_failure(
        inventory_binding_failure::signature_unresolved);
  }
  std::ranges::sort(hits);
  hits.erase(std::unique(hits.begin(), hits.end()), hits.end());
  std::vector<std::vector<std::uintptr_t>> runs;
  for (std::size_t begin = 0U; begin < hits.size();) {
    std::size_t end = begin + 1U;
    while (end < hits.size() &&
           hits[end - 1U] <=
               (std::numeric_limits<std::uintptr_t>::max)() -
                   binding.slot_stride &&
           hits[end] == hits[end - 1U] + binding.slot_stride) {
      ++end;
    }
    if (end - begin >= binding.slot_count) {
      runs.emplace_back(hits.begin() + static_cast<std::ptrdiff_t>(begin),
                        hits.begin() + static_cast<std::ptrdiff_t>(end));
    }
    begin = end;
  }
  if (runs.empty()) {
    return inventory_failure(
        inventory_binding_failure::signature_unresolved);
  }
  if (runs.size() != 1U || runs.front().size() != binding.slot_count) {
    return inventory_failure(
        inventory_binding_failure::signature_ambiguous);
  }
  return {.hits = std::move(runs.front())};
}

[[nodiscard]] bool validate_inventory_hits(
    readonly_memory_session& session,
    const embedded_inventory_binding& binding,
    const std::span<const std::uintptr_t> hits) {
  if (hits.size() != binding.slot_count) {
    return false;
  }
  std::vector<std::byte> bytes(binding.slot_pattern.bytes.size());
  for (std::size_t index = 0U; index < hits.size(); ++index) {
    if ((index != 0U &&
         (hits[index - 1U] >
              (std::numeric_limits<std::uintptr_t>::max)() -
                  binding.slot_stride ||
          hits[index] != hits[index - 1U] + binding.slot_stride)) ||
        !session.read_exact(hits[index], bytes) ||
        !matches_at(bytes, 0U, binding.slot_pattern)) {
      return false;
    }
  }
  return true;
}

[[nodiscard]] resolved_inventory_capture fail_inventory(
    const inventory_binding_failure failure,
    std::string reason = {}) {
  if (reason.empty()) {
    reason = std::string(to_string(failure));
  }
  return {
      .failure = failure,
      .registry_sha256 = std::string(embedded_build_profile_registry_sha256),
      .reason = std::move(reason),
  };
}

}  // namespace

bool resolved_inventory_capture::ready() const noexcept {
  return failure == inventory_binding_failure::none &&
      profile.has_value() && plan.has_value() && reason.empty() &&
      registry_sha256 == embedded_build_profile_registry_sha256;
}

resolved_inventory_capture memory_capture_plan_resolver::resolve_inventory(
    const std::uint64_t sequence,
    const std::uint64_t captured_at_steady_ns,
    const sonar::platform::windows::process_generation& game_generation)
    noexcept {
  try {
    if (sequence == 0U || captured_at_steady_ns == 0U ||
        game_generation.process_id == 0U ||
        game_generation.creation_time_filetime_100ns == 0U) {
      return fail_inventory(
          inventory_binding_failure::internal_error,
          "memory_capture_identity_invalid");
    }
    if (auto reason = prepare_session(game_generation); !reason.empty()) {
      const auto failure = reason == "memory_process_generation_changed" ||
              reason == "memory_process_generation_mismatch"
          ? inventory_binding_failure::process_changed
          : inventory_binding_failure::profile_unavailable;
      return fail_inventory(failure, std::move(reason));
    }
    if (build_profile_ == nullptr ||
        !build_profile_->inventory_binding.has_value() ||
        !valid_inventory_binding(*build_profile_->inventory_binding)) {
      return fail_inventory(
          inventory_binding_failure::profile_unavailable,
          "memory_inventory_binding_unavailable");
    }
    const auto& binding = *build_profile_->inventory_binding;
    const auto remember_failure = [&](
        const inventory_binding_failure failure) {
      inventory_last_failure_ = failure;
      inventory_retry_after_steady_ns_ = captured_at_steady_ns >
              (std::numeric_limits<std::uint64_t>::max)() -
                  kInventoryRediscoveryCooldownNs
          ? (std::numeric_limits<std::uint64_t>::max)()
          : captured_at_steady_ns + kInventoryRediscoveryCooldownNs;
      return fail_inventory(failure);
    };
    const bool had_cached_binding = !inventory_signature_hits_.empty();
    if (had_cached_binding && !validate_inventory_hits(
            *session_, binding, inventory_signature_hits_)) {
      inventory_signature_hits_.clear();
    }
    if (inventory_signature_hits_.empty()) {
      if (inventory_last_failure_ != inventory_binding_failure::none &&
          captured_at_steady_ns < inventory_retry_after_steady_ns_) {
        return fail_inventory(inventory_last_failure_);
      }
      inventory_last_failure_ = inventory_binding_failure::none;
      inventory_retry_after_steady_ns_ = 0U;
      auto discovered = discover_inventory_hits(*session_, binding);
      if (discovered.failure != inventory_binding_failure::none) {
        if (had_cached_binding &&
            discovered.failure ==
                inventory_binding_failure::signature_unresolved) {
          discovered.failure = inventory_binding_failure::signature_changed;
        }
        return remember_failure(discovered.failure);
      }
      inventory_signature_hits_ = std::move(discovered.hits);
      inventory_last_failure_ = inventory_binding_failure::none;
      inventory_retry_after_steady_ns_ = 0U;
    }
    if (!validate_inventory_hits(
            *session_, binding, inventory_signature_hits_)) {
      inventory_signature_hits_.clear();
      return remember_failure(
          inventory_binding_failure::signature_changed);
    }
    if (!session_->generation_current()) {
      reset();
      return fail_inventory(
          inventory_binding_failure::process_changed);
    }

    memory_observation_profile profile{
        .profile_id = build_profile_->profile_id,
        .profile_revision = build_profile_->profile_revision,
        .game = build_profile_->game,
        .webengine = {.required = false},
        .reeling = {.maximum_distance = 120.0},
        .status_candidates = {},
        .minimum_inventory_votes = binding.minimum_votes,
        .minimum_inventory_confidence = binding.minimum_confidence,
        .require_reeling = false,
        .require_inventory = true,
        .require_player_status = false,
        .require_chat = false,
    };
    capture_plan plan{
        .sequence = sequence,
        .captured_at_steady_ns = captured_at_steady_ns,
        .game_process_id = game_generation.process_id,
        .expected_game_generation = game_generation,
    };
    profile.inventory_candidates.reserve(
        binding.slot_count * binding.signals.size());
    plan.regions.reserve(
        binding.slot_count * binding.signals.size());
    for (const auto hit : inventory_signature_hits_) {
      for (const auto& signal : binding.signals) {
        if (hit > (std::numeric_limits<std::uintptr_t>::max)() -
                signal.offset) {
          inventory_signature_hits_.clear();
          return fail_inventory(
              inventory_binding_failure::signature_changed);
        }
        const auto slot = static_cast<std::uint32_t>(
            profile.inventory_candidates.size());
        profile.inventory_candidates.push_back(signal.candidate);
        plan.regions.push_back({
            evidence_region_kind::inventory_candidate,
            process_role::game,
            slot,
            hit + signal.offset,
            1U,
        });
      }
    }
    return {
        .profile = std::move(profile),
        .plan = std::move(plan),
        .registry_sha256 = std::string(embedded_build_profile_registry_sha256),
    };
  } catch (...) {
    inventory_signature_hits_.clear();
    return fail_inventory(inventory_binding_failure::internal_error);
  }
}

std::string_view to_string(
    const inventory_binding_failure value) noexcept {
  switch (value) {
    case inventory_binding_failure::none:
      return "ready";
    case inventory_binding_failure::profile_unavailable:
      return "memory_inventory_binding_unavailable";
    case inventory_binding_failure::region_enumeration_failed:
      return "memory_inventory_region_enumeration_failed";
    case inventory_binding_failure::scan_incomplete:
      return "memory_inventory_scan_incomplete";
    case inventory_binding_failure::signature_unresolved:
      return "memory_inventory_signature_unresolved";
    case inventory_binding_failure::signature_ambiguous:
      return "memory_inventory_signature_ambiguous";
    case inventory_binding_failure::signature_changed:
      return "memory_inventory_signature_changed";
    case inventory_binding_failure::process_changed:
      return "memory_process_generation_changed";
    case inventory_binding_failure::internal_error:
      return "memory_inventory_resolution_failed";
  }
  return "memory_inventory_resolution_failed";
}

}  // namespace sonar::fishing::memory_observation
