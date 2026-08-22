#include "sonar/fishing/runtime_platform/automation_lease.h"
#include "sonar/fishing/runtime_platform/platform_capture.h"
#include "sonar/fishing/runtime_platform/platform_input.h"
#include "sonar/fishing/runtime_platform/target_resolver.h"

#include <cstdint>
#include <deque>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace {

namespace platform = sonar::fishing::runtime_platform;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

[[nodiscard]] sonar::platform::windows::window_client_snapshot target(
    const std::uintptr_t window = 0x1234U,
    const std::uint32_t process_id = 77U) {
  return {
      .window = window,
      .process = {
          .process_id = process_id,
          .creation_time_filetime_100ns = 99U,
      },
      .thread_id = 3U,
      .screen_left = -50,
      .screen_top = 20,
      .width = 200U,
      .height = 100U,
      .dpi = 144U,
      .visible = true,
      .minimized = false,
  };
}

class recording_api final : public platform::native_platform_api {
 public:
  [[nodiscard]] bool activate_window(
      const sonar::platform::windows::native_window_handle window)
      noexcept override {
    activated = window;
    return true;
  }

  [[nodiscard]] bool set_cursor_position(
      const std::int32_t x,
      const std::int32_t y) noexcept override {
    cursor.emplace_back(x, y);
    return true;
  }

  [[nodiscard]] std::size_t send_input(
      const std::span<const platform::input_packet> packets)
      noexcept override {
    batches.emplace_back(packets.begin(), packets.end());
    if (results.empty()) {
      return packets.size();
    }
    const auto result = results.front();
    results.pop_front();
    return result;
  }

  [[nodiscard]] bool set_clipboard_text(
      const std::wstring_view text) noexcept override {
    clipboard.assign(text);
    return true;
  }

  sonar::platform::windows::native_window_handle activated{};
  std::vector<std::pair<std::int32_t, std::int32_t>> cursor;
  std::vector<std::vector<platform::input_packet>> batches;
  std::deque<std::size_t> results;
  std::wstring clipboard;
};

[[nodiscard]] platform::mutation_intent intent(
    const platform::mutation_kind kind) {
  return {.kind = kind, .packet_count = platform::expected_packet_count(kind)};
}

void exact_target_policy_is_fail_closed() {
  require(
      platform::select_exact_game_target({}).reason ==
          "game_target_unavailable",
      "empty_target_not_rejected");

  const std::vector<platform::target_candidate> wrong{{L"other.exe", target()}};
  require(
      platform::select_exact_game_target(wrong).reason ==
          "game_target_unavailable",
      "wrong_image_target_accepted");

  const std::vector<platform::target_candidate> one{{L"gTa5.ExE", target()}};
  const auto selected = platform::select_exact_game_target(one);
  require(selected.ready() && selected.target->window == target().window,
      "exact_game_target_not_selected");

  const std::vector<platform::target_candidate> ambiguous{
      {L"GTA5.exe", target(0x1234U, 77U)},
      {L"GTA5.exe", target(0x5678U, 88U)},
  };
  require(
      platform::select_exact_game_target(ambiguous).reason ==
          "game_target_ambiguous",
      "ambiguous_game_target_accepted");
}

void one_shared_lease_is_exclusive_and_move_owned() {
  platform::automation_lease_coordinator coordinator;
  auto first = coordinator.try_acquire();
  require(first.has_value() && first->active() && coordinator.owned(),
      "automation_lease_not_acquired");
  require(!coordinator.try_acquire().has_value(),
      "second_automation_lease_acquired");
  auto moved = std::move(*first);
  require(moved.active() && !first->active(), "automation_lease_move_invalid");
  moved = platform::automation_lease(std::move(moved));
  require(moved.active(), "automation_lease_self_move_invalid");
}

void generic_input_preserves_legacy_packets_and_cleanup() {
  recording_api api;
  platform::win32_platform_mutation_sink sink(target(), {}, api);

  auto down = intent(platform::mutation_kind::key_down);
  down.primary = "a";
  require(sink.apply(down).applied, "key_down_rejected");
  auto up = intent(platform::mutation_kind::key_up);
  up.primary = "a";
  require(sink.apply(up).applied, "key_up_rejected");
  require(
      api.batches[0] == std::vector<platform::input_packet>({
          {platform::input_packet_kind::key_down, 0x1E}}) &&
      api.batches[1] == std::vector<platform::input_packet>({
          {platform::input_packet_kind::key_up, 0x1E}}),
      "held_key_packet_shape_changed");

  auto right = intent(platform::mutation_kind::click_client_right);
  right.point = {.x = 0.5, .y = 0.5};
  require(sink.apply(right).applied, "right_click_rejected");
  require(
      api.cursor ==
          std::vector<std::pair<std::int32_t, std::int32_t>>({{50, 70}}),
      "normalized_client_geometry_changed");
  require(
      api.batches[2] == std::vector<platform::input_packet>({
          {platform::input_packet_kind::right_button_down, 0},
          {platform::input_packet_kind::right_button_up, 0}}),
      "right_click_packet_shape_changed");

  auto release = intent(platform::mutation_kind::release_reeling_keys);
  require(sink.apply(release).applied, "reeling_cleanup_rejected");
  require(
      api.batches[3] == std::vector<platform::input_packet>({
          {platform::input_packet_kind::key_up, 0x1E},
          {platform::input_packet_kind::key_up, 0x20}}),
      "reeling_cleanup_packet_shape_changed");

  recording_api partial;
  partial.results = {1U, 1U};
  platform::win32_platform_mutation_sink partial_sink(target(), {}, partial);
  auto press = intent(platform::mutation_kind::press_key);
  press.primary = "space";
  const auto result = partial_sink.apply(press);
  require(!result.applied && result.reason == "send_input_incomplete",
      "partial_key_prefix_accepted");
  require(
      partial.batches.size() == 2U &&
      partial.batches[1] == std::vector<platform::input_packet>({
          {platform::input_packet_kind::key_up, 0x39}}),
      "partial_key_cleanup_changed");

  auto blocked = intent(platform::mutation_kind::key_down);
  blocked.primary = "w";
  require(sink.apply(blocked).reason == "key_unsupported",
      "blocked_forward_key_accepted");
}

void frame_contract_is_coherent() {
  platform::client_frame frame{
      .width = 2U,
      .height = 2U,
      .stride_bytes = 6U,
      .sequence = 1U,
      .captured_at_steady_ns = 2U,
      .target = target(),
      .bgr24 = std::vector<std::uint8_t>(12U, 0U),
  };
  require(frame.valid(), "coherent_frame_rejected");
  frame.bgr24.pop_back();
  require(!frame.valid(), "short_frame_accepted");
}

}  // namespace

int main() {
  try {
    exact_target_policy_is_fail_closed();
    one_shared_lease_is_exclusive_and_move_owned();
    generic_input_preserves_legacy_packets_and_cleanup();
    frame_contract_is_coherent();
    return 0;
  } catch (const std::exception&) {
    return 1;
  }
}
