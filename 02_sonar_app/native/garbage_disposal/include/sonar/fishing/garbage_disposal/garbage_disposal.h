#pragma once

#include <optional>
#include <span>
#include <string_view>
#include <vector>

namespace sonar::fishing::garbage_disposal {

enum class GarbageKind {
  corn,
  bag,
  pack,
};

struct Candidate {
  GarbageKind kind;
  double normalized_x;
  double normalized_y;
  double confidence;

  [[nodiscard]] bool operator==(const Candidate&) const = default;
};

struct SelectionPolicy {
  bool corn = true;
  bool bag = true;
  bool pack = true;

  [[nodiscard]] bool enabled(GarbageKind kind) const noexcept;
  [[nodiscard]] bool any_enabled() const noexcept;
};

enum class PlanReason {
  ready,
  disabled,
  no_candidates,
};

struct DisposalPlan {
  PlanReason reason;
  std::vector<Candidate> targets;
};

// Pure internal Engine policy. Detection and the eventual bounded physical
// episode stay on the same Engine side; this plan is never a Host stepwise RPC.
// Input order is the legacy template/matcher order, and equal confidences keep
// that order exactly.
[[nodiscard]] DisposalPlan PlanDisposal(
    std::span<const Candidate> candidates,
    const SelectionPolicy& policy);

[[nodiscard]] std::optional<GarbageKind> KindFromKey(
    std::string_view key) noexcept;
[[nodiscard]] std::string_view Key(GarbageKind kind) noexcept;
[[nodiscard]] std::string_view LegacyName(GarbageKind kind) noexcept;

}  // namespace sonar::fishing::garbage_disposal
