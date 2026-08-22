#include "sonar/fishing/garbage_disposal/garbage_disposal.h"

#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace sonar::fishing::garbage_disposal {

bool SelectionPolicy::enabled(const GarbageKind kind) const noexcept {
  switch (kind) {
    case GarbageKind::corn:
      return corn;
    case GarbageKind::bag:
      return bag;
    case GarbageKind::pack:
      return pack;
  }
  return false;
}

bool SelectionPolicy::any_enabled() const noexcept {
  return corn || bag || pack;
}

DisposalPlan PlanDisposal(
    const std::span<const Candidate> candidates,
    const SelectionPolicy& policy) {
  if (!policy.any_enabled()) {
    return {.reason = PlanReason::disabled};
  }

  DisposalPlan plan{.reason = PlanReason::no_candidates};
  plan.targets.reserve(candidates.size());
  for (const Candidate& candidate : candidates) {
    if (!std::isfinite(candidate.normalized_x) ||
        !std::isfinite(candidate.normalized_y) ||
        !std::isfinite(candidate.confidence) ||
        candidate.normalized_x < 0.0 || candidate.normalized_x > 1.0 ||
        candidate.normalized_y < 0.0 || candidate.normalized_y > 1.0 ||
        candidate.confidence < 0.0 || candidate.confidence > 1.0) {
      throw std::invalid_argument("garbage_candidate_invalid");
    }
    if (policy.enabled(candidate.kind)) {
      plan.targets.push_back(candidate);
    }
  }
  std::stable_sort(
      plan.targets.begin(),
      plan.targets.end(),
      [](const Candidate& left, const Candidate& right) {
        return left.confidence > right.confidence;
      });
  if (!plan.targets.empty()) {
    plan.reason = PlanReason::ready;
  }
  return plan;
}

std::optional<GarbageKind> KindFromKey(const std::string_view key) noexcept {
  if (key == "corn") {
    return GarbageKind::corn;
  }
  if (key == "bag") {
    return GarbageKind::bag;
  }
  if (key == "pack") {
    return GarbageKind::pack;
  }
  return std::nullopt;
}

std::string_view Key(const GarbageKind kind) noexcept {
  switch (kind) {
    case GarbageKind::corn:
      return "corn";
    case GarbageKind::bag:
      return "bag";
    case GarbageKind::pack:
      return "pack";
  }
  return {};
}

std::string_view LegacyName(const GarbageKind kind) noexcept {
  switch (kind) {
    case GarbageKind::corn:
      return "corn can";
    case GarbageKind::bag:
      return "empty bag";
    case GarbageKind::pack:
      return "empty cigarette pack";
  }
  return {};
}

}  // namespace sonar::fishing::garbage_disposal
