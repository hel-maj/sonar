#include "sonar/fishing/game_chat/game_chat.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace {

namespace chat = sonar::fishing::game_chat;

void require(const bool condition, const std::string_view reason) {
  if (!condition) {
    throw std::runtime_error(std::string(reason));
  }
}

[[nodiscard]] chat::chat_observation make_observation(
    const bool active,
    const std::string_view selected = "0",
    const bool valid_input = true) {
  return {
      .active = active,
      .tabs = {
          {
              .id = "0",
              .name = "Все",
              .selected = selected == "0",
              .bounds = {.x = 0.02, .y = 0.02, .width = 0.05, .height = 0.03},
          },
          {
              .id = "1",
              .name = "Семья",
              .selected = selected == "1",
              .bounds = {.x = 0.08, .y = 0.02, .width = 0.07, .height = 0.03},
          },
      },
      .selected_tab_id = std::string(selected),
      .input_bounds = valid_input
          ? chat::normalized_rect{
                .x = 0.02,
                .y = 0.42,
                .width = 0.25,
                .height = 0.05,
            }
          : chat::normalized_rect{},
  };
}

class sequence_observer final : public chat::chat_observer {
 public:
  explicit sequence_observer(std::vector<chat::chat_observation> observations)
      : observations_(std::move(observations)) {
    if (observations_.empty()) {
      throw std::invalid_argument("observation_sequence_empty");
    }
  }

  [[nodiscard]] chat::chat_observation observe() override {
    ++calls_;
    const std::size_t index = std::min(next_, observations_.size() - 1);
    ++next_;
    return observations_[index];
  }

  [[nodiscard]] std::size_t calls() const noexcept { return calls_; }

 private:
  std::vector<chat::chat_observation> observations_;
  std::size_t next_{};
  std::size_t calls_{};
};

class recording_input final : public chat::chat_input_port {
 public:
  [[nodiscard]] chat::chat_input_result apply(
      const chat::chat_input_intent& intent) override {
    intents.push_back(intent);
    if (reject_kind.has_value() && intent.kind == *reject_kind) {
      return chat::chat_input_result::rejected(reject_reason);
    }
    return chat::chat_input_result::accepted();
  }

  [[nodiscard]] std::size_t count(const chat::chat_intent_kind kind) const {
    return static_cast<std::size_t>(std::count_if(
        intents.begin(),
        intents.end(),
        [kind](const chat::chat_input_intent& intent) {
          return intent.kind == kind;
        }));
  }

  std::vector<chat::chat_input_intent> intents;
  std::optional<chat::chat_intent_kind> reject_kind;
  std::string reject_reason{"runtime_safety_rejected"};
};

void normalized_geometry_fails_closed() {
  require(chat::normalized_point{0.0, 1.0}.valid(), "point_boundary_rejected");
  require(!chat::normalized_point{-0.01, 0.5}.valid(), "negative_point_accepted");
  require(
      chat::normalized_rect{0.1, 0.2, 0.3, 0.4}.valid(),
      "valid_rect_rejected");
  require(
      !chat::normalized_rect{0.8, 0.2, 0.3, 0.4}.valid(),
      "out_of_viewport_rect_accepted");
}

void explicit_command_classifier_matches_shared_legacy_corpus() {
  std::ifstream input(SONAR_FISHING_GAME_CHAT_FIXTURE);
  require(input.good(), "game_chat_fixture_missing");
  std::string line;
  std::size_t cases = 0;
  while (std::getline(input, line)) {
    if (line.empty() || line.front() == '#') {
      continue;
    }
    const auto delimiter = line.rfind('\t');
    require(delimiter != std::string::npos, "game_chat_fixture_row_invalid");
    const std::string message = line.substr(0, delimiter);
    const std::string expected = line.substr(delimiter + 1);
    require(
        chat::message_uses_explicit_chat_command(message) ==
            (expected == "explicit"),
        "explicit_command_parity_changed");
    ++cases;
  }
  require(cases >= 8, "game_chat_fixture_too_small");
}

void open_episode_preserves_confirmation_and_focus_order() {
  sequence_observer observer({
      make_observation(false),
      make_observation(true),
  });
  recording_input input;
  const auto result = chat::chat_episode_runner{}.run(
      {.operation = chat::chat_operation::open, .chat_hotkey = "t"},
      observer,
      input);
  require(result.ok && result.reason == "chat_opened", "chat_open_changed");
  require(observer.calls() == 2, "chat_open_confirmation_count_changed");
  require(input.intents.size() == 6, "chat_open_action_count_changed");
  require(
      input.intents[0].kind == chat::chat_intent_kind::activate_window &&
          input.intents[1].kind == chat::chat_intent_kind::release_all_keys &&
          input.intents[2].kind == chat::chat_intent_kind::press_key &&
          input.intents[2].primary == "t",
      "chat_open_prefix_changed");
  require(
      input.intents[3].kind == chat::chat_intent_kind::activate_window &&
          input.intents[4].kind == chat::chat_intent_kind::click_client &&
          input.intents[5].kind == chat::chat_intent_kind::pause,
      "chat_open_focus_changed");
  require(
      input.count(chat::chat_intent_kind::press_key) == 1,
      "chat_open_pressed_extra_key");
}

void already_active_open_does_not_toggle_chat() {
  sequence_observer observer({make_observation(true)});
  recording_input input;
  const auto result = chat::chat_episode_runner{}.run(
      {.operation = chat::chat_operation::open, .chat_hotkey = "t"},
      observer,
      input);
  require(
      result.ok && result.reason == "chat_already_active",
      "already_active_result_changed");
  require(
      input.count(chat::chat_intent_kind::press_key) == 0,
      "already_active_toggled_chat");
  require(
      input.count(chat::chat_intent_kind::release_all_keys) == 1,
      "already_active_release_missing");
}

void close_episode_waits_for_inactive_confirmation() {
  sequence_observer observer({
      make_observation(true),
      make_observation(false),
  });
  recording_input input;
  const auto result = chat::chat_episode_runner{}.run(
      {.operation = chat::chat_operation::close},
      observer,
      input);
  require(result.ok && result.reason == "chat_closed", "chat_close_changed");
  require(observer.calls() == 2, "chat_close_confirmation_count_changed");
  require(
      input.count(chat::chat_intent_kind::press_key) == 1 &&
          input.intents[1].primary == "esc",
      "chat_close_escape_changed");
}

void plain_family_message_restores_tab_prefix_atomically() {
  sequence_observer observer({
      make_observation(true, "1"),
      make_observation(true, "1"),
      make_observation(true, "0"),
      make_observation(true, "1"),
      make_observation(true, "1"),
  });
  recording_input input;
  const auto result = chat::chat_episode_runner{}.run(
      {
          .operation = chat::chat_operation::send_message,
          .chat_hotkey = "t",
          .tab_id = "1",
          .message = "привет",
      },
      observer,
      input);
  require(result.ok && result.reason == "chat_message_sent", "plain_send_changed");
  require(observer.calls() == 5, "plain_send_observation_count_changed");
  require(input.count(chat::chat_intent_kind::click_client) == 5, "tab_prefix_restore_changed");
  require(input.count(chat::chat_intent_kind::set_clipboard_text) == 1, "clipboard_write_changed");
  const auto clipboard = std::find_if(
      input.intents.begin(),
      input.intents.end(),
      [](const chat::chat_input_intent& intent) {
        return intent.kind == chat::chat_intent_kind::set_clipboard_text;
      });
  require(clipboard != input.intents.end() && clipboard->text == "привет", "clipboard_text_changed");
}

void explicit_command_skips_tab_prefix_restore() {
  sequence_observer observer({
      make_observation(true, "1"),
      make_observation(true, "1"),
      make_observation(true, "1"),
  });
  recording_input input;
  const auto result = chat::chat_episode_runner{}.run(
      {
          .operation = chat::chat_operation::send_message,
          .chat_hotkey = "t",
          .tab_id = "1",
          .message = "/cb привет",
      },
      observer,
      input);
  require(result.ok, "explicit_send_failed");
  require(observer.calls() == 3, "explicit_send_observation_count_changed");
  require(input.count(chat::chat_intent_kind::click_client) == 3, "explicit_send_restored_prefix");
}

void invalid_observation_and_disabled_input_fail_closed() {
  sequence_observer invalid_bounds({make_observation(true, "0", false)});
  recording_input recording;
  const auto invalid_result = chat::chat_episode_runner{}.run(
      {.operation = chat::chat_operation::open},
      invalid_bounds,
      recording);
  require(
      !invalid_result.ok && invalid_result.reason == "chat_input_bounds_unavailable",
      "invalid_input_bounds_not_rejected");
  require(
      recording.count(chat::chat_intent_kind::click_client) == 0,
      "invalid_input_bounds_clicked");

  sequence_observer disabled_observer({make_observation(true)});
  chat::disabled_chat_input_port disabled;
  const auto disabled_result = chat::chat_episode_runner{}.run(
      {.operation = chat::chat_operation::open},
      disabled_observer,
      disabled);
  require(
      !disabled_result.ok && disabled_result.reason == "chat_live_adapter_disabled",
      "disabled_live_adapter_not_fail_closed");
  require(disabled_observer.calls() == 0, "disabled_adapter_observed_game");
}

void final_boundary_rejection_stops_remaining_episode() {
  sequence_observer observer({
      make_observation(true),
      make_observation(true),
  });
  recording_input input;
  input.reject_kind = chat::chat_intent_kind::set_clipboard_text;
  input.reject_reason = "foreground_generation_changed";
  const auto result = chat::chat_episode_runner{}.run(
      {
          .operation = chat::chat_operation::send_message,
          .message = "hello",
      },
      observer,
      input);
  require(
      !result.ok && result.reason == "foreground_generation_changed",
      "final_boundary_rejection_lost");
  require(
      input.count(chat::chat_intent_kind::set_clipboard_text) == 1,
      "clipboard_rejection_not_reached");
  require(
      std::none_of(
          input.intents.begin(),
          input.intents.end(),
          [](const chat::chat_input_intent& intent) {
            return intent.kind == chat::chat_intent_kind::press_key &&
                intent.primary == "enter";
          }),
      "episode_continued_after_rejection");
}

void open_confirmation_is_bounded() {
  sequence_observer observer({make_observation(false)});
  recording_input input;
  const auto result = chat::chat_episode_runner{}.run(
      {.operation = chat::chat_operation::open},
      observer,
      input);
  require(
      !result.ok && result.reason == "chat_open_not_confirmed",
      "open_timeout_changed");
  require(observer.calls() == 29, "open_timeout_observation_bound_changed");
  require(input.count(chat::chat_intent_kind::pause) == 27, "open_timeout_pause_bound_changed");
}

void invalid_message_has_no_input_side_effect() {
  sequence_observer observer({make_observation(true)});
  recording_input input;
  const auto result = chat::chat_episode_runner{}.run(
      {
          .operation = chat::chat_operation::send_message,
          .message = "   ",
      },
      observer,
      input);
  require(!result.ok && result.reason == "chat_message_invalid", "empty_message_changed");
  require(observer.calls() == 1, "empty_message_detection_changed");
  require(input.intents.empty(), "empty_message_applied_input");
}

int run() {
  normalized_geometry_fails_closed();
  explicit_command_classifier_matches_shared_legacy_corpus();
  open_episode_preserves_confirmation_and_focus_order();
  already_active_open_does_not_toggle_chat();
  close_episode_waits_for_inactive_confirmation();
  plain_family_message_restores_tab_prefix_atomically();
  explicit_command_skips_tab_prefix_restore();
  invalid_observation_and_disabled_input_fail_closed();
  final_boundary_rejection_stops_remaining_episode();
  open_confirmation_is_bounded();
  invalid_message_has_no_input_side_effect();
  std::cout << "PASS native game-chat episode and fail-closed adapter policy\n";
  return 0;
}

}  // namespace

int main() {
  try {
    return run();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
