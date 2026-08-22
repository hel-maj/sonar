#include "maintenance_operation.h"

#include <algorithm>
#include <cstddef>
#include <optional>
#include <string_view>
#include <utility>
#include <vector>

#include "sonar/fishing/garbage_disposal/garbage_disposal.h"

namespace sonar::fishing::maintenance_episode::detail {
namespace {

constexpr double kMinimumItemConfidence = 0.90;
constexpr std::size_t kMaximumDisposals = 128;
constexpr std::size_t kDiscardSettleMilliseconds = 400;

struct candidate_record final {
  garbage_disposal::Candidate candidate;
  const inventory_store::inventory_item_observation* item{};
};

[[nodiscard]] std::optional<garbage_disposal::GarbageKind> garbage_kind(
    const std::string_view item_id) noexcept {
  return garbage_disposal::KindFromKey(item_id);
}

[[nodiscard]] garbage_disposal::SelectionPolicy selection_policy(
    const runtime_settings::RuntimeSettingsSnapshot& settings) {
  const auto enabled = [&settings](const std::string_view key) {
    const auto found = settings.garbage_disposal_policy.find(key);
    return found != settings.garbage_disposal_policy.end() && found->second;
  };
  return {
      .corn = enabled("corn"),
      .bag = enabled("bag"),
      .pack = enabled("pack"),
  };
}

[[nodiscard]] std::vector<candidate_record> records(
    const inventory_store::inventory_observation& observation) {
  std::vector<candidate_record> result;
  result.reserve(observation.items.size());
  for (const auto& item : observation.items) {
    const auto kind = garbage_kind(item.item_id);
    if (!kind.has_value() ||
        item.compartment !=
            inventory_store::inventory_compartment::player_inventory ||
        item.confidence < kMinimumItemConfidence) {
      continue;
    }
    result.push_back({
        .candidate = {
            .kind = *kind,
            .normalized_x = item.bounds.x + item.bounds.width / 2.0,
            .normalized_y = item.bounds.y + item.bounds.height / 2.0,
            .confidence = item.confidence,
        },
        .item = &item,
    });
  }
  return result;
}

[[nodiscard]] std::size_t selected_count(
    const std::vector<candidate_record>& source,
    const garbage_disposal::SelectionPolicy& policy) {
  return static_cast<std::size_t>(std::count_if(
      source.begin(),
      source.end(),
      [&policy](const auto& item) {
        return policy.enabled(item.candidate.kind);
      }));
}

[[nodiscard]] bool has_instance(
    const inventory_store::inventory_observation& observation,
    const std::string_view instance_id) {
  return std::any_of(
      observation.items.begin(),
      observation.items.end(),
      [instance_id](const auto& item) {
        return item.instance_id == instance_id;
      });
}

}  // namespace

bool operation::execute_garbage(
    inventory_store::inventory_episode_context& context,
    const std::stop_token stop_token) {
  const auto policy = selection_policy(request_.settings);
  if (!policy.any_enabled()) {
    completion_reason_ = "garbage_disabled";
    return true;
  }

  while (affected_count_ < kMaximumDisposals) {
    if (stop_requested(context, stop_token)) {
      return false;
    }
    if (coherent(context) == nullptr) {
      return false;
    }
    const auto current_records = records(context.current());
    std::vector<garbage_disposal::Candidate> candidates;
    candidates.reserve(current_records.size());
    for (const auto& item : current_records) {
      candidates.push_back(item.candidate);
    }
    const auto plan = garbage_disposal::PlanDisposal(candidates, policy);
    if (plan.reason == garbage_disposal::PlanReason::disabled) {
      completion_reason_ = "garbage_disabled";
      return true;
    }
    if (plan.targets.empty()) {
      completion_reason_ = affected_count_ == 0
          ? "garbage_none"
          : "garbage_disposed";
      return true;
    }

    const auto selected = std::find_if(
        current_records.begin(),
        current_records.end(),
        [&plan](const auto& item) {
          return item.candidate == plan.targets.front();
        });
    if (selected == current_records.end() || selected->item == nullptr) {
      return context.reject("garbage_plan_target_missing");
    }
    const std::string instance_id = selected->item->instance_id;
    const std::size_t before = selected_count(current_records, policy);
    if (!context.mutate(item_intent(
            inventory_store::inventory_intent_kind::discard_inventory_item,
            *selected->item,
            request_.settings.discard_hotkey,
            6)) ||
        !context.wait(kDiscardSettleMilliseconds) || !context.refresh()) {
      return false;
    }
    if (coherent(context) == nullptr) {
      return false;
    }
    const auto after_records = records(context.current());
    if (has_instance(context.current(), instance_id) ||
        selected_count(after_records, policy) >= before) {
      return context.reject("garbage_disposal_not_confirmed");
    }
    ++affected_count_;
  }

  if (selected_count(records(context.current()), policy) != 0) {
    return context.reject("garbage_disposal_limit_reached");
  }
  completion_reason_ = "garbage_disposed";
  return true;
}

}  // namespace sonar::fishing::maintenance_episode::detail
