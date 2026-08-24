#include "sonar/fishing/automation_adapters/production_observation.h"

#include "production_visual_detector.h"

#include "sonar/platform/inventory/open_state.hpp"

#include <algorithm>
#include <cctype>
#include <optional>
#include <string>
#include <string_view>
#include <utility>

namespace sonar::fishing::automation_adapters {
namespace {

[[nodiscard]] bool contains_inventory_title(
    const std::string_view text) noexcept {
  return text.find("Инвентарь") != std::string_view::npos ||
      text.find("инвентарь") != std::string_view::npos ||
      text.find("ИНВЕНТАРЬ") != std::string_view::npos;
}

[[nodiscard]] bool contains_menu_affordance(
    const std::string_view text) noexcept {
  return text.find("Назад") != std::string_view::npos ||
      text.find("назад") != std::string_view::npos ||
      text.find("Скрыть") != std::string_view::npos ||
      text.find("скрыть") != std::string_view::npos;
}

[[nodiscard]] stage_detection::bgr24_frame_view view(
    const runtime_platform::client_frame& frame) noexcept {
  return {
      .width = frame.width,
      .height = frame.height,
      .stride_bytes = frame.stride_bytes,
      .pixels = frame.bgr24,
  };
}

[[nodiscard]] std::optional<std::string_view> text_view(
    const recognized_text& text) noexcept {
  return text.text.empty()
      ? std::nullopt
      : std::optional<std::string_view>(text.text);
}

}  // namespace

struct production_frame_observer::implementation final {
  runtime_platform::client_capture_source& capture;
  stage_detection::majestic_fishing_stage_detector& stage_detector;
  fishing_memory_source& memory;
  mutable_runtime_policy_source& policy;
  runtime_text_recognizer& text;
  detail::production_visual_detector visual;
  maintenance_episode::maintenance_observation current;
  std::optional<std::string> expected_context_item;
  stage_detection::normalized_rect expected_context_bounds;

  [[nodiscard]] std::optional<runtime_platform::client_frame> capture_frame(
      const std::stop_token stop_token,
      std::string& reason) {
    if (stop_token.stop_requested()) {
      reason = "production_observation_cancelled";
      return std::nullopt;
    }
    auto result = capture.capture();
    if (!result.frame.has_value() || !result.frame->valid()) {
      reason = result.reason.empty()
          ? "production_capture_unavailable"
          : std::move(result.reason);
      return std::nullopt;
    }
    policy.observe(result.frame->sequence);
    return std::move(*result.frame);
  }
};

production_frame_observer::production_frame_observer(
    runtime_platform::client_capture_source& capture,
    stage_detection::majestic_fishing_stage_detector& stage_detector,
    fishing_memory_source& memory,
    mutable_runtime_policy_source& policy,
    runtime_text_recognizer& text) noexcept
    : implementation_(std::make_unique<implementation>(
          implementation{capture, stage_detector, memory, policy, text})) {}

production_frame_observer::~production_frame_observer() = default;

production_catch_observation production_frame_observer::observe_catch(
    const std::stop_token stop_token) {
  production_catch_observation result;
  if (!implementation_) {
    result.error = "production_observer_unavailable";
    return result;
  }
  auto frame = implementation_->capture_frame(stop_token, result.error);
  if (!frame.has_value()) {
    return result;
  }
  result.sequence = frame->sequence;
  const auto surface = implementation_->visual.detect_catch(*frame);
  if (!surface.visible) {
    result.error = "production_catch_not_visible";
    return result;
  }
  const auto fish = implementation_->text.recognize(
      *frame, surface.fish_text);
  const auto quality = implementation_->text.recognize(
      *frame, surface.quality_text);
  const auto weight = implementation_->text.recognize(
      *frame, surface.weight_text);
  const auto experience = implementation_->text.recognize(
      *frame, surface.experience_text);
  if (!fish.reason.empty() || !weight.reason.empty()) {
    result.error = !fish.reason.empty() ? fish.reason : weight.reason;
    return result;
  }
  result.catch_fact = catch_observation::Interpret({
      .fish = text_view(fish),
      .quality = text_view(quality),
      .weight = text_view(weight),
      .experience = text_view(experience),
  });
  if (!result.catch_fact->valid_content) {
    result.error = "production_catch_content_unrecognized";
    return result;
  }
  result.visible = true;
  result.inventory_full = surface.inventory_full;
  result.keep_button = surface.keep_button;
  result.release_button = surface.release_button;
  return result;
}

inventory_store::inventory_observation production_frame_observer::observe(
    const std::stop_token stop_token) {
  inventory_store::inventory_observation result;
  if (!implementation_) {
    result.error = "production_observer_unavailable";
    return result;
  }
  auto frame = implementation_->capture_frame(stop_token, result.error);
  if (!frame.has_value()) {
    return result;
  }
  result.sequence = frame->sequence;
  const auto stage = implementation_->stage_detector.detect(view(*frame));
  if (!stage.error.empty()) {
    result.error = stage.error;
    return result;
  }
  const auto title = implementation_->text.recognize(
      *frame, {0.20, 0.015, 0.60, 0.09});
  const bool inventory_title = title.reason.empty() &&
      contains_inventory_title(title.text);
  auto visual = implementation_->visual.detect_inventory(
      *frame,
      inventory_title,
      implementation_->expected_context_item.has_value()
          ? std::optional<std::string_view>(
                *implementation_->expected_context_item)
          : std::nullopt,
      implementation_->expected_context_item.has_value()
          ? std::optional<stage_detection::normalized_rect>(
                implementation_->expected_context_bounds)
          : std::nullopt);
  result.items = std::move(visual.items);
  result.remove_action = std::move(visual.remove_action);
  result.catch_screen_visible =
      implementation_->visual.detect_catch(*frame).visible;
  if (stage.observation.has_value()) {
    result.fishing_stage = stage.observation->stage;
  }
  bool game_menu_visible = false;
  if (!inventory_title && result.fishing_stage ==
          stage_detection::observed_fishing_stage::none &&
      !result.catch_screen_visible) {
    const auto menu = implementation_->text.recognize(
        *frame, {0.50, 0.70, 0.49, 0.29});
    if (menu.reason.empty() && contains_menu_affordance(menu.text)) {
      game_menu_visible = true;
    }
  }

  // Inventory visibility is one coherent memory fact. The frame remains the
  // owner of item/context geometry, but OCR/title pixels never authorize an
  // open or closed state and unknown is never collapsed into closed.
  const auto memory = implementation_->memory.capture(
      memory_capture_scope::inventory_state,
      frame->sequence,
      frame->captured_at_steady_ns,
      frame->target.process);
  const bool coherent_memory = memory.snapshot.has_value() &&
      memory.snapshot->sequence == frame->sequence;
  sonar::platform::inventory::open_state_evidence inventory_evidence;
  if (coherent_memory &&
      memory.snapshot->inventory.has_value()) {
    const auto& observed = *memory.snapshot->inventory;
    inventory_evidence = {
        .is_open = observed.open,
        .matched_signals = static_cast<std::uint32_t>(
            observed.matched_votes),
        .confidence = observed.confidence,
        .coherent = true,
    };
  }
  const auto inventory_state =
      sonar::platform::inventory::normalize_open_state(inventory_evidence);
  switch (inventory_state.state) {
    case sonar::platform::inventory::observed_state::open:
      result.surface = visual.surface ==
              inventory_store::inventory_surface::item_context_menu
          ? inventory_store::inventory_surface::item_context_menu
          : inventory_store::inventory_surface::inventory;
      break;
    case sonar::platform::inventory::observed_state::closed:
      result.surface = game_menu_visible
          ? inventory_store::inventory_surface::game_menu
          : inventory_store::inventory_surface::gameplay;
      result.items.clear();
      result.remove_action.reset();
      break;
    case sonar::platform::inventory::observed_state::unknown:
      result.surface = inventory_store::inventory_surface::unknown;
      result.items.clear();
      result.remove_action.reset();
      break;
  }

  implementation_->current = {
      .inventory = result,
      .hunger_visible = visual.hunger_visible,
      .thirst_visible = visual.thirst_visible,
      .tackle = visual.tackle.available
          ? std::optional<maintenance_episode::tackle_scan_observation>(
                visual.tackle)
          : std::nullopt,
      .changed_bait_visible = visual.changed_bait_visible,
      .gear_visible = visual.gear_visible,
  };
  // Inventory state uses its own memory scope and never depends on an active
  // fish. Geometry still comes from the frame; absent exact build binding stays
  // unknown instead of falling back to OCR/title pixels.
  if (coherent_memory) {
    implementation_->current.reeling = memory.snapshot->reeling;
    implementation_->current.player_status = memory.snapshot->player_status;
  }
  if (result.surface !=
      inventory_store::inventory_surface::item_context_menu) {
    implementation_->expected_context_item.reset();
  }
  return result;
}

const maintenance_episode::maintenance_observation&
production_frame_observer::current_maintenance() const noexcept {
  static const maintenance_episode::maintenance_observation unavailable{};
  return implementation_ ? implementation_->current : unavailable;
}

void production_frame_observer::expect_context_item(
    std::string instance_id,
    const stage_detection::normalized_rect item_bounds) {
  if (!implementation_) {
    return;
  }
  implementation_->expected_context_item = std::move(instance_id);
  implementation_->expected_context_bounds = item_bounds;
}

void production_frame_observer::clear_context_item() noexcept {
  if (implementation_) {
    implementation_->expected_context_item.reset();
  }
}

}  // namespace sonar::fishing::automation_adapters
