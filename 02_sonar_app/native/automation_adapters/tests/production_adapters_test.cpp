#include "sonar/fishing/automation_adapters/production_mutation.h"

#include "production_visual_detector.h"
#include "visual_assets.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>
#include <wincodec.h>
#include <wrl/client.h>

#include <atomic>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#ifndef SONAR_FISHING_CATCH_PRODUCTION_FIXTURE
#error SONAR_FISHING_CATCH_PRODUCTION_FIXTURE is required
#endif
#ifndef SONAR_FISHING_INVENTORY_PRODUCTION_FIXTURE
#error SONAR_FISHING_INVENTORY_PRODUCTION_FIXTURE is required
#endif
#ifndef SONAR_FISHING_INVENTORY_FISH_FIXTURE
#error SONAR_FISHING_INVENTORY_FISH_FIXTURE is required
#endif
#ifndef SONAR_FISHING_TACKLE_PRODUCTION_FIXTURE
#error SONAR_FISHING_TACKLE_PRODUCTION_FIXTURE is required
#endif

namespace {

using Microsoft::WRL::ComPtr;
namespace adapters = sonar::fishing::automation_adapters;
namespace detail = sonar::fishing::automation_adapters::detail;
namespace inventory = sonar::fishing::inventory_store;
namespace platform = sonar::fishing::runtime_platform;

void require(const bool value, const std::string_view reason) {
  if (!value) {
    throw std::runtime_error(std::string(reason));
  }
}

void check(const HRESULT value, const std::string_view reason) {
  if (FAILED(value)) {
    throw std::runtime_error(
        std::string(reason) + ':' + std::to_string(value));
  }
}

class com_apartment final {
 public:
  com_apartment() {
    const auto value = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    require(SUCCEEDED(value), "production_fixture_com_failed");
    initialized_ = true;
  }
  ~com_apartment() {
    if (initialized_) {
      CoUninitialize();
    }
  }

 private:
  bool initialized_{};
};

[[nodiscard]] platform::client_frame load_frame(
    IWICImagingFactory& factory,
    const std::filesystem::path& path,
    const std::uint64_t sequence) {
  ComPtr<IWICBitmapDecoder> decoder;
  check(factory.CreateDecoderFromFilename(
            path.c_str(), nullptr, GENERIC_READ,
            WICDecodeMetadataCacheOnLoad, decoder.GetAddressOf()),
      "production_fixture_open_failed");
  ComPtr<IWICBitmapFrameDecode> decoded;
  check(decoder->GetFrame(0, decoded.GetAddressOf()),
      "production_fixture_frame_failed");
  ComPtr<IWICFormatConverter> converter;
  check(factory.CreateFormatConverter(converter.GetAddressOf()),
      "production_fixture_converter_failed");
  check(converter->Initialize(
            decoded.Get(), GUID_WICPixelFormat24bppBGR,
            WICBitmapDitherTypeNone, nullptr, 0.0,
            WICBitmapPaletteTypeCustom),
      "production_fixture_conversion_failed");
  UINT width{};
  UINT height{};
  check(converter->GetSize(&width, &height),
      "production_fixture_size_failed");
  const auto stride = static_cast<std::size_t>(width) * 3U;
  const auto bytes = stride * height;
  require(bytes <= (std::numeric_limits<UINT>::max)(),
      "production_fixture_too_large");
  std::vector<std::uint8_t> pixels(bytes);
  check(converter->CopyPixels(
            nullptr, static_cast<UINT>(stride),
            static_cast<UINT>(bytes), pixels.data()),
      "production_fixture_copy_failed");
  return {
      .width = width,
      .height = height,
      .stride_bytes = stride,
      .sequence = sequence,
      .captured_at_steady_ns = sequence * 1'000U,
      .target = {
          .window = 0x1234U,
          .process = {
              .process_id = 77U,
              .creation_time_filetime_100ns = 99U,
          },
          .thread_id = 3U,
          .width = width,
          .height = height,
          .dpi = 96U,
          .visible = true,
      },
      .bgr24 = std::move(pixels),
  };
}

class repeating_capture final : public platform::client_capture_source {
 public:
  explicit repeating_capture(platform::client_frame frame)
      : frame_(std::move(frame)) {}

  [[nodiscard]] platform::capture_result capture() override {
    auto copy = frame_;
    copy.sequence = next_sequence_++;
    copy.captured_at_steady_ns = copy.sequence * 1'000U;
    return platform::capture_result::captured(std::move(copy));
  }

 private:
  platform::client_frame frame_;
  std::uint64_t next_sequence_{1U};
};

[[nodiscard]] std::vector<std::uint8_t> decode_base64(
    const std::string_view source) {
  constexpr std::string_view alphabet =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  std::vector<std::uint8_t> result;
  std::uint32_t accumulator{};
  int bits{};
  for (const char character : source) {
    if (character == '=') {
      break;
    }
    const auto position = alphabet.find(character);
    require(position != std::string_view::npos,
        "production_asset_base64_invalid");
    accumulator = (accumulator << 6U) |
        static_cast<std::uint32_t>(position);
    bits += 6;
    if (bits >= 8) {
      bits -= 8;
      result.push_back(static_cast<std::uint8_t>(
          (accumulator >> bits) & 0xFFU));
    }
  }
  return result;
}

[[nodiscard]] const detail::embedded_visual_asset& asset(
    const std::string_view id,
    const detail::visual_asset_kind kind,
    const std::string_view profile) {
  const auto values = detail::embedded_visual_assets();
  const auto found = std::ranges::find_if(
      values, [&](const auto& value) {
        return value.id == id && value.kind == kind &&
            value.profile == profile;
      });
  require(found != values.end(), "production_asset_missing");
  return *found;
}

void blit_asset(
    platform::client_frame& frame,
    const detail::embedded_visual_asset& source,
    const std::uint32_t left,
    const std::uint32_t top) {
  const auto rgba = decode_base64(source.rgba_base64);
  require(rgba.size() == static_cast<std::size_t>(source.width) *
              source.height * 4U &&
          left + source.width <= frame.width &&
          top + source.height <= frame.height,
      "production_asset_blit_invalid");
  for (std::uint32_t y = 0U; y < source.height; ++y) {
    for (std::uint32_t x = 0U; x < source.width; ++x) {
      const auto input =
          (static_cast<std::size_t>(y) * source.width + x) * 4U;
      const auto output = static_cast<std::size_t>(top + y) *
              frame.stride_bytes +
          static_cast<std::size_t>(left + x) * 3U;
      frame.bgr24[output] = rgba[input + 2U];
      frame.bgr24[output + 1U] = rgba[input + 1U];
      frame.bgr24[output + 2U] = rgba[input];
    }
  }
}

class unavailable_memory final : public adapters::fishing_memory_source {
 public:
  [[nodiscard]] adapters::memory_snapshot_result capture(
      std::uint64_t,
      std::uint64_t,
      const sonar::platform::windows::process_generation&) noexcept override {
    return {.reason = "fixture_memory_unavailable"};
  }
};

class inventory_memory final : public adapters::fishing_memory_source {
 public:
  explicit inventory_memory(const bool open) : open_(open) {}

  [[nodiscard]] adapters::memory_snapshot_result capture(
      const std::uint64_t sequence,
      const std::uint64_t captured_at_steady_ns,
      const sonar::platform::windows::process_generation& game_generation)
      noexcept override {
    return {
        .snapshot = sonar::fishing::memory_observation::coherent_memory_snapshot{
            .sequence = sequence,
            .captured_at_steady_ns = captured_at_steady_ns,
            .profile_id = "fixture-profile",
            .profile_revision = 1U,
            .game_generation = game_generation,
            .inventory = sonar::fishing::memory_observation::inventory_evidence{
                .open = open_,
                .matched_votes = 6U,
                .confidence = 0.95,
            },
        },
    };
  }

 private:
  bool open_{};
};

class queued_text final : public adapters::runtime_text_recognizer {
 public:
  explicit queued_text(std::vector<std::string> values)
      : values_(std::move(values)) {}

  [[nodiscard]] adapters::recognized_text recognize(
      const platform::client_frame&,
      const sonar::fishing::stage_detection::normalized_rect&) noexcept
      override {
    if (cursor_ >= values_.size()) {
      return {};
    }
    return {.text = values_[cursor_++]};
  }

 private:
  std::vector<std::string> values_;
  std::size_t cursor_{};
};

[[nodiscard]] std::unique_ptr<adapters::production_frame_observer> observer(
    repeating_capture& capture,
    adapters::fishing_memory_source& memory,
    adapters::mutable_runtime_policy_source& policy,
    adapters::runtime_text_recognizer& text,
    sonar::fishing::stage_detection::majestic_fishing_stage_detector& stage) {
  policy.publish({
      .entitlement_valid = true,
      .settings_current = true,
      .lifecycle_allows_input = true,
      .settings_revision = 4U,
      .entitlement_revision = 5U,
      .lifecycle_revision = 6U,
  });
  return std::make_unique<adapters::production_frame_observer>(
      capture, stage, memory, policy, text);
}

void catch_frame_produces_one_typed_fact(IWICImagingFactory& factory) {
  repeating_capture capture(load_frame(
      factory, SONAR_FISHING_CATCH_PRODUCTION_FIXTURE, 1U));
  unavailable_memory memory;
  adapters::mutable_runtime_policy_source policy;
  queued_text text({"Марлин", "Хороший улов", "3.10 кг", "10813"});
  sonar::fishing::stage_detection::majestic_fishing_stage_detector stage;
  auto target = observer(capture, memory, policy, text, stage);
  const auto fact = target->observe_catch({});
  require(fact.visible && fact.error.empty() && fact.catch_fact.has_value() &&
          fact.catch_fact->fish_id == "marlin" &&
          fact.catch_fact->weight_kg.has_value() &&
          *fact.catch_fact->weight_kg == 3.10 &&
          fact.keep_button.x < fact.release_button.x,
      "production_catch_fact_changed");
  require(policy.snapshot().latest_observation_sequence == fact.sequence,
      "production_catch_sequence_not_published");
}

void inventory_frame_rejects_unmatched_slots(IWICImagingFactory& factory) {
  repeating_capture capture(load_frame(
      factory, SONAR_FISHING_INVENTORY_FISH_FIXTURE, 1U));
  inventory_memory memory(true);
  adapters::mutable_runtime_policy_source policy;
  queued_text text({"Окружение Инвентарь", "Окружение Инвентарь"});
  sonar::fishing::stage_detection::majestic_fishing_stage_detector stage;
  auto target = observer(capture, memory, policy, text, stage);
  const auto fact = target->observe({});
  require(fact.error.empty() &&
          fact.surface == inventory::inventory_surface::inventory,
      "production_inventory_surface_changed");
  require(fact.items.empty(), "production_inventory_false_positive");
  for (const auto& item : fact.items) {
    require(!item.instance_id.empty() && !item.item_id.empty() &&
            item.confidence >= 0.90 &&
            item.bounds.x >= 0.0 && item.bounds.x + item.bounds.width <= 1.0,
        "production_inventory_item_invalid");
  }
  target->expect_context_item("backpack:0:0", {0.22, 0.54, 0.03, 0.05});
  const auto context = target->observe({});
  require(context.surface == inventory::inventory_surface::inventory &&
          !context.remove_action.has_value(),
      "production_context_action_fabricated");
}

void inventory_visibility_is_memory_authoritative(
    IWICImagingFactory& factory) {
  repeating_capture capture(load_frame(
      factory, SONAR_FISHING_INVENTORY_FISH_FIXTURE, 1U));
  inventory_memory closed_memory(false);
  adapters::mutable_runtime_policy_source policy;
  queued_text text({"Окружение Инвентарь"});
  sonar::fishing::stage_detection::majestic_fishing_stage_detector stage;
  auto closed = observer(capture, closed_memory, policy, text, stage);
  const auto contradicted = closed->observe({});
  require(contradicted.surface == inventory::inventory_surface::gameplay &&
          contradicted.items.empty() &&
          !contradicted.remove_action.has_value(),
      "production_visual_inventory_overrode_memory_closed");

  repeating_capture unknown_capture(load_frame(
      factory, SONAR_FISHING_INVENTORY_FISH_FIXTURE, 2U));
  unavailable_memory unavailable;
  adapters::mutable_runtime_policy_source unknown_policy;
  queued_text unknown_text({"Окружение Инвентарь"});
  auto unknown = observer(
      unknown_capture, unavailable, unknown_policy, unknown_text, stage);
  const auto unavailable_fact = unknown->observe({});
  require(unavailable_fact.surface == inventory::inventory_surface::unknown &&
          unavailable_fact.items.empty() &&
          !unavailable_fact.remove_action.has_value(),
      "production_unknown_inventory_collapsed_into_visual_state");
}

void memory_open_preserves_context_geometry(IWICImagingFactory& factory) {
  auto frame = load_frame(
      factory, SONAR_FISHING_INVENTORY_PRODUCTION_FIXTURE, 1U);
  const auto& fish = asset(
      "marlin", detail::visual_asset_kind::fish, "any");
  const auto& remove = asset(
      "remove", detail::visual_asset_kind::context_action, "fhd");
  constexpr std::uint32_t column = 3U;
  constexpr std::uint32_t row = 8U;
  const double cell_width = (0.7800 - 0.6100) / 6.0;
  const double cell_height = (0.9430 - 0.0850) / 17.0;
  const sonar::fishing::stage_detection::normalized_rect item_bounds{
      0.6100 + cell_width * column,
      0.0850 + cell_height * row,
      cell_width,
      cell_height,
  };
  const auto center_x = static_cast<std::uint32_t>(std::llround(
      (item_bounds.x + item_bounds.width / 2.0) * frame.width));
  const auto center_y = static_cast<std::uint32_t>(std::llround(
      (item_bounds.y + item_bounds.height / 2.0) * frame.height));
  blit_asset(
      frame, fish, center_x - fish.width / 2U, center_y - fish.height / 2U);
  const auto search_left = static_cast<std::uint32_t>(std::llround(
      (item_bounds.x - 0.12) * frame.width));
  const auto search_top = static_cast<std::uint32_t>(std::llround(
      (item_bounds.y - 0.10) * frame.height));
  blit_asset(
      frame,
      remove,
      search_left + (std::max)(2U, remove.width / 24U) * 5U,
      search_top + (std::max)(2U, remove.height / 3U) * 5U);

  repeating_capture capture(std::move(frame));
  inventory_memory memory(true);
  adapters::mutable_runtime_policy_source policy;
  queued_text text({"Окружение Инвентарь"});
  sonar::fishing::stage_detection::majestic_fishing_stage_detector stage;
  auto target = observer(capture, memory, policy, text, stage);
  target->expect_context_item("inventory:8:3", item_bounds);
  const auto fact = target->observe({});
  require(
      fact.surface == inventory::inventory_surface::item_context_menu &&
          fact.remove_action.has_value() &&
          fact.remove_action->item_instance_id == "inventory:8:3" &&
          std::ranges::any_of(fact.items, [](const auto& item) {
            return item.instance_id == "inventory:8:3" &&
                item.item_id == "marlin";
          }),
      "production_memory_open_lost_context_geometry");
}

void embedded_assets_drive_positive_inventory_and_context_matches(
    IWICImagingFactory& factory) {
  auto inventory_frame = load_frame(
      factory, SONAR_FISHING_INVENTORY_PRODUCTION_FIXTURE, 1U);
  const auto& fish = asset(
      "marlin", detail::visual_asset_kind::fish, "any");
  constexpr std::uint32_t column = 3U;
  constexpr std::uint32_t row = 8U;
  const double cell_width = (0.7800 - 0.6100) / 6.0;
  const double cell_height = (0.9430 - 0.0850) / 17.0;
  const auto center_x = static_cast<std::uint32_t>(std::llround(
      (0.6100 + cell_width * (column + 0.5)) * inventory_frame.width));
  const auto center_y = static_cast<std::uint32_t>(std::llround(
      (0.0850 + cell_height * (row + 0.5)) * inventory_frame.height));
  blit_asset(
      inventory_frame, fish,
      center_x - fish.width / 2U, center_y - fish.height / 2U);
  detail::production_visual_detector detector;
  const auto inventory_result =
      detector.detect_inventory(inventory_frame, true);
  const auto detected = std::ranges::find_if(
      inventory_result.items,
      [](const auto& item) {
        return item.instance_id == "inventory:8:3" &&
            item.item_id == "marlin" && item.confidence >= 0.99;
      });
  require(detected != inventory_result.items.end(),
      "production_embedded_fish_match_changed");

  auto context_frame = load_frame(
      factory, SONAR_FISHING_INVENTORY_PRODUCTION_FIXTURE, 2U);
  const auto& remove = asset(
      "remove", detail::visual_asset_kind::context_action, "fhd");
  constexpr sonar::fishing::stage_detection::normalized_rect expected{
      0.50, 0.50, 0.03, 0.05};
  const auto search_left = static_cast<std::uint32_t>(std::llround(
      (expected.x - 0.12) * context_frame.width));
  const auto search_top = static_cast<std::uint32_t>(std::llround(
      (expected.y - 0.10) * context_frame.height));
  const auto step_x = (std::max)(2U, remove.width / 24U);
  const auto step_y = (std::max)(2U, remove.height / 3U);
  blit_asset(
      context_frame, remove,
      search_left + step_x * 5U, search_top + step_y * 5U);
  const auto context_result = detector.detect_inventory(
      context_frame, true, "inventory:fixture", expected);
  require(
      context_result.surface ==
          inventory::inventory_surface::item_context_menu &&
      context_result.remove_action.has_value() &&
      context_result.remove_action->item_instance_id == "inventory:fixture" &&
      context_result.remove_action->confidence >= 0.99,
      "production_embedded_context_match_changed");
}

void gameplay_frame_projects_tackle_without_fixed_resolution(
    IWICImagingFactory& factory) {
  repeating_capture capture(load_frame(
      factory, SONAR_FISHING_TACKLE_PRODUCTION_FIXTURE, 1U));
  inventory_memory memory(false);
  adapters::mutable_runtime_policy_source policy;
  queued_text text({"", ""});
  sonar::fishing::stage_detection::majestic_fishing_stage_detector stage;
  auto target = observer(capture, memory, policy, text, stage);
  const auto fact = target->observe({});
  const auto& maintenance = target->current_maintenance();
  require(fact.error.empty() &&
          fact.surface == inventory::inventory_surface::gameplay &&
          maintenance.tackle.has_value() &&
          maintenance.tackle->available && maintenance.tackle->readable,
      "production_tackle_projection_changed");
  require(maintenance.tackle->counts.rod != 0U &&
          maintenance.tackle->counts.bait != 0U,
      "production_tackle_occupancy_not_detected");
}

class recording_gate final : public adapters::immediate_action_gate {
 public:
  [[nodiscard]] adapters::action_gate_result revalidate(
      const adapters::action_claim& claim) noexcept override {
    claims.push_back(claim);
    return {true, {}};
  }
  std::vector<adapters::action_claim> claims;
};

class recording_sink final : public platform::platform_mutation_sink {
 public:
  [[nodiscard]] platform::mutation_result apply(
      const platform::mutation_intent& intent) override {
    intents.push_back(intent);
    return platform::mutation_result::accepted();
  }
  std::vector<platform::mutation_intent> intents;
};

class recording_terminal_sink final
    : public adapters::system_terminal_action_sink {
 public:
  [[nodiscard]] adapters::system_terminal_action_result shutdown_pc()
      noexcept override {
    ++shutdown_calls;
    return accept
        ? adapters::system_terminal_action_result::accepted()
        : adapters::system_terminal_action_result::rejected(
              "fixture_shutdown_rejected");
  }

  std::size_t shutdown_calls{};
  bool accept{true};
};

void one_session_lease_guards_catch_and_inventory(IWICImagingFactory& factory) {
  repeating_capture capture(load_frame(
      factory, SONAR_FISHING_INVENTORY_PRODUCTION_FIXTURE, 1U));
  unavailable_memory memory;
  adapters::mutable_runtime_policy_source policy;
  queued_text text({});
  sonar::fishing::stage_detection::majestic_fishing_stage_detector stage;
  auto observed = observer(capture, memory, policy, text, stage);
  platform::automation_lease_coordinator leases;
  recording_gate gate;
  recording_sink sink;
  recording_terminal_sink terminal;
  std::string reason;
  auto mutation = adapters::guarded_production_mutation_port::acquire(
      leases, gate, sink, terminal, *observed, 4U, 5U, 6U, reason);
  require(mutation != nullptr && reason.empty() && leases.owned(),
      "production_session_lease_not_acquired");
  std::string second_reason;
  require(adapters::guarded_production_mutation_port::acquire(
              leases, gate, sink, terminal, *observed, 4U, 5U, 6U,
              second_reason) == nullptr &&
          second_reason == "production_input_lease_busy",
      "production_session_lease_not_exclusive");
  const auto catch_result = mutation->apply_catch_button(
      1U, {0.40, 0.60, 0.10, 0.05}, {});
  require(catch_result.applied && gate.claims.size() == 1U &&
          sink.intents.size() == 1U &&
          sink.intents.back().kind ==
              platform::mutation_kind::click_client_left,
      "production_catch_mutation_not_guarded");
  const auto inventory_result = mutation->apply({
      .kind = inventory::inventory_intent_kind::press_key,
      .expected_observation_sequence = 2U,
      .key = "i",
      .packet_count = 2U,
  }, {});
  require(inventory_result.applied && gate.claims.size() == 2U &&
          sink.intents.size() == 2U &&
          sink.intents.back().kind == platform::mutation_kind::press_key,
      "production_inventory_mutation_not_guarded");
  mutation.reset();
  require(!leases.owned() && !sink.intents.empty() &&
          sink.intents.back().kind ==
              platform::mutation_kind::release_all_keys,
      "production_session_cleanup_not_applied");
}

void shutdown_is_cleanup_first_and_uses_a_non_input_final_gate(
    IWICImagingFactory& factory) {
  repeating_capture capture(load_frame(
      factory, SONAR_FISHING_INVENTORY_PRODUCTION_FIXTURE, 1U));
  unavailable_memory memory;
  adapters::mutable_runtime_policy_source policy;
  queued_text text({});
  sonar::fishing::stage_detection::majestic_fishing_stage_detector stage;
  auto observed = observer(capture, memory, policy, text, stage);
  platform::automation_lease_coordinator leases;
  recording_gate gate;
  recording_sink sink;
  recording_terminal_sink terminal;
  std::string reason;
  auto mutation = adapters::guarded_production_mutation_port::acquire(
      leases, gate, sink, terminal, *observed, 4U, 5U, 6U, reason);
  require(mutation != nullptr && reason.empty(),
      "shutdown_fixture_session_not_acquired");

  const auto result = mutation->apply({
      .kind = inventory::inventory_intent_kind::shutdown_pc,
      .expected_observation_sequence = 9U,
  }, {});
  require(result.applied && terminal.shutdown_calls == 1U &&
          mutation->terminal_action() ==
              adapters::requested_terminal_action::shutdown_pc,
      "shutdown_terminal_action_not_applied");
  require(sink.intents.size() == 1U &&
          sink.intents.front().kind ==
              platform::mutation_kind::release_all_keys,
      "shutdown_did_not_cleanup_before_terminal_action");
  require(gate.claims.size() == 2U &&
          gate.claims[0U].cleanup_only &&
          gate.claims[0U].packet_count == 9U &&
          gate.claims[1U].effect ==
              adapters::action_claim::effect_kind::system_terminal_action &&
          gate.claims[1U].packet_count == 0U &&
          !gate.claims[1U].foreground_required,
      "shutdown_final_gate_shape_changed");
  const auto after_cleanup = mutation->apply({
      .kind = inventory::inventory_intent_kind::press_key,
      .expected_observation_sequence = 10U,
      .key = "i",
      .packet_count = 2U,
  }, {});
  require(!after_cleanup.applied &&
          after_cleanup.reason == "production_mutation_session_cleaned",
      "mutation_applied_after_terminal_cleanup");
}

}  // namespace

int main() {
  try {
    com_apartment apartment;
    ComPtr<IWICImagingFactory> factory;
    check(CoCreateInstance(
              CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
              IID_PPV_ARGS(factory.GetAddressOf())),
        "production_fixture_factory_failed");
    catch_frame_produces_one_typed_fact(*factory.Get());
    inventory_frame_rejects_unmatched_slots(*factory.Get());
    inventory_visibility_is_memory_authoritative(*factory.Get());
    memory_open_preserves_context_geometry(*factory.Get());
    embedded_assets_drive_positive_inventory_and_context_matches(
        *factory.Get());
      gameplay_frame_projects_tackle_without_fixed_resolution(*factory.Get());
      one_session_lease_guards_catch_and_inventory(*factory.Get());
      shutdown_is_cleanup_first_and_uses_a_non_input_final_gate(*factory.Get());
      return 0;
  } catch (const std::exception& exception) {
    std::cerr << exception.what() << '\n';
    return 1;
  }
}
