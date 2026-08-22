#include "sonar/fishing/game_chat/chat_observation.h"
#include "sonar/fishing/game_chat/chat_runtime.h"

#include <cmath>
#include <iostream>
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

[[nodiscard]] chat::chat_frame make_frame(const std::uint64_t sequence) {
  chat::chat_frame frame{
      .width = 200,
      .height = 100,
      .stride_bytes = 600,
      .sequence = sequence,
  };
  frame.bgr24.resize(frame.stride_bytes * frame.height);
  return frame;
}

[[nodiscard]] chat::pixel_chat_detection make_detection(
    const bool active = true,
    const std::string_view selected = "1") {
  return {
      .active = active,
      .tabs = {
          {
              .id = "0",
              .name = "Все",
              .selected = selected == "0",
              .bounds = {.x = 10, .y = 4, .width = 40, .height = 10},
          },
          {
              .id = "1",
              .name = "Семья",
              .selected = selected == "1",
              .bounds = {.x = 55, .y = 4, .width = 50, .height = 10},
          },
      },
      .selected_tab_id = std::string(selected),
      .input_bounds = active
          ? std::optional<chat::pixel_rect>({
                .x = 10,
                .y = 42,
                .width = 100,
                .height = 8,
            })
          : std::nullopt,
  };
}

class scripted_capture final : public chat::chat_capture_source {
 public:
  explicit scripted_capture(std::vector<chat::chat_frame> frames)
      : frames_(std::move(frames)) {}

  [[nodiscard]] chat::chat_capture_result capture() override {
    ++calls;
    if (frames_.empty()) {
      return chat::chat_capture_result::unavailable("fixture_exhausted");
    }
    auto frame = std::move(frames_.front());
    frames_.erase(frames_.begin());
    return chat::chat_capture_result::captured(std::move(frame));
  }

  std::size_t calls{};

 private:
  std::vector<chat::chat_frame> frames_;
};

class scripted_detector final : public chat::chat_frame_detector {
 public:
  explicit scripted_detector(std::vector<chat::pixel_chat_detection> detections)
      : detections_(std::move(detections)) {}

  [[nodiscard]] chat::pixel_chat_detection detect(
      const chat::chat_frame& frame) override {
    static_cast<void>(frame);
    ++calls;
    if (detections_.empty()) {
      return {.error = "fixture_exhausted"};
    }
    auto detection = std::move(detections_.front());
    detections_.erase(detections_.begin());
    return detection;
  }

  std::size_t calls{};

 private:
  std::vector<chat::pixel_chat_detection> detections_;
};

[[nodiscard]] std::string kind_text(const chat::chat_intent_kind kind) {
  return std::to_string(static_cast<int>(kind));
}

class recording_gate final : public chat::chat_final_gate {
 public:
  explicit recording_gate(std::vector<std::string>& trace) : trace_(trace) {}

  [[nodiscard]] chat::chat_input_result revalidate(
      const chat::chat_input_intent& intent) override {
    trace_.push_back("gate:" + kind_text(intent.kind));
    ++calls;
    if (reject_kind.has_value() && intent.kind == *reject_kind) {
      return chat::chat_input_result::rejected("fixture_final_gate_rejected");
    }
    return chat::chat_input_result::accepted();
  }

  std::optional<chat::chat_intent_kind> reject_kind;
  std::size_t calls{};

 private:
  std::vector<std::string>& trace_;
};

class recording_sink final : public chat::chat_platform_mutation_sink {
 public:
  recording_sink(
      chat::chat_input_lease_coordinator& leases,
      std::vector<std::string>& trace)
      : leases_(leases), trace_(trace) {}

  [[nodiscard]] chat::chat_input_result apply(
      const chat::chat_input_intent& intent) override {
    require(leases_.chat_owned(), "mutation_without_chat_lease");
    trace_.push_back("sink:" + kind_text(intent.kind));
    ++calls;
    return chat::chat_input_result::accepted();
  }

  std::size_t calls{};

 private:
  chat::chat_input_lease_coordinator& leases_;
  std::vector<std::string>& trace_;
};

void frame_and_pixel_geometry_are_bounded() {
  auto frame = make_frame(1);
  require(frame.valid(), "valid_bgr_frame_rejected");
  require(
      chat::pixel_rect{10, 20, 30, 40}.valid_for(frame),
      "valid_pixel_rect_rejected");
  require(
      !chat::pixel_rect{190, 20, 20, 40}.valid_for(frame),
      "overflow_pixel_rect_accepted");
  frame.bgr24.pop_back();
  require(!frame.valid(), "truncated_bgr_frame_accepted");
}

void observer_normalizes_fresh_frame_geometry() {
  scripted_capture capture({make_frame(7)});
  scripted_detector detector({make_detection()});
  chat::capture_chat_observer observer(capture, detector);
  const auto observation = observer.observe();
  require(observation.error.empty() && observation.active, "valid_detection_rejected");
  require(observation.tabs.size() == 2, "normalized_tabs_changed");
  require(observation.selected_tab_id == "1", "normalized_selection_changed");
  require(std::abs(observation.input_bounds.x - 0.05) < 0.0001, "input_x_not_normalized");
  require(std::abs(observation.input_bounds.y - 0.42) < 0.0001, "input_y_not_normalized");
  require(std::abs(observation.input_bounds.width - 0.5) < 0.0001, "input_width_not_normalized");
}

void observer_rejects_replay_and_inconsistent_detector_output() {
  scripted_capture replay_capture({make_frame(8), make_frame(8)});
  scripted_detector replay_detector({make_detection(), make_detection()});
  chat::capture_chat_observer replay_observer(replay_capture, replay_detector);
  require(replay_observer.observe().error.empty(), "initial_frame_rejected");
  require(
      replay_observer.observe().error == "chat_capture_replayed",
      "replayed_frame_accepted");
  require(replay_detector.calls == 1, "replayed_frame_reached_detector");

  auto inconsistent = make_detection();
  inconsistent.selected_tab_id = "0";
  scripted_capture inconsistent_capture({make_frame(9)});
  scripted_detector inconsistent_detector({std::move(inconsistent)});
  chat::capture_chat_observer inconsistent_observer(
      inconsistent_capture,
      inconsistent_detector);
  require(
      inconsistent_observer.observe().error ==
          "chat_detector_selection_inconsistent",
      "inconsistent_selection_accepted");
}

void disabled_capture_and_detector_are_explicit() {
  chat::disabled_chat_capture_source capture;
  chat::disabled_chat_frame_detector detector;
  chat::capture_chat_observer observer(capture, detector);
  require(
      observer.observe().error ==
          "chat_capture_unavailable:chat_live_capture_disabled",
      "disabled_capture_reason_changed");
}

void win32_capture_rejects_missing_target_before_capture() {
  chat::win32_chat_capture_source capture({});
  const auto result = capture.capture();
  require(!result.frame.has_value(), "invalid_target_capture_succeeded");
  require(
      result.reason == "chat_capture_target_unavailable:invalid_handle",
      "invalid_target_capture_reason_changed");
}

void orchestrator_holds_exclusive_lease_and_revalidates_immediately() {
  scripted_capture capture({make_frame(10)});
  scripted_detector detector({make_detection(true, "0")});
  chat::chat_input_lease_coordinator leases;
  std::vector<std::string> trace;
  recording_gate gate(trace);
  recording_sink sink(leases, trace);
  chat::chat_episode_orchestrator orchestrator(
      capture,
      detector,
      leases,
      gate,
      sink);
  const auto result = orchestrator.run({
      .operation = chat::chat_operation::open,
      .chat_hotkey = "t",
  });
  require(result.ok && result.reason == "chat_already_active", "orchestrated_open_changed");
  require(!leases.chat_owned(), "chat_lease_not_released");
  require(capture.calls == 1 && detector.calls == 1, "orchestrator_observation_changed");
  require(gate.calls == 4, "final_gate_call_count_changed");
  require(sink.calls == 5, "platform_sink_call_count_changed");
  require(
      trace == std::vector<std::string>({
          "gate:0", "sink:0",
          "gate:1", "sink:1",
          "gate:0", "sink:0",
          "gate:4", "sink:4",
          "sink:6",
      }),
      "gate_sink_immediacy_changed");
}

void busy_lease_blocks_observation_and_mutation() {
  scripted_capture capture({make_frame(11)});
  scripted_detector detector({make_detection()});
  chat::chat_input_lease_coordinator leases;
  auto held = leases.try_acquire();
  require(held.has_value() && leases.chat_owned(), "fixture_lease_missing");
  std::vector<std::string> trace;
  recording_gate gate(trace);
  recording_sink sink(leases, trace);
  chat::chat_episode_orchestrator orchestrator(
      capture,
      detector,
      leases,
      gate,
      sink);
  const auto result = orchestrator.run({.operation = chat::chat_operation::open});
  require(
      !result.ok && result.reason == "chat_input_lease_busy",
      "concurrent_chat_episode_accepted");
  require(capture.calls == 0 && trace.empty(), "busy_episode_touched_runtime");
}

void final_gate_rejection_never_reaches_platform_sink() {
  scripted_capture capture({make_frame(12)});
  scripted_detector detector({make_detection()});
  chat::chat_input_lease_coordinator leases;
  std::vector<std::string> trace;
  recording_gate gate(trace);
  gate.reject_kind = chat::chat_intent_kind::activate_window;
  recording_sink sink(leases, trace);
  chat::chat_episode_orchestrator orchestrator(
      capture,
      detector,
      leases,
      gate,
      sink);
  const auto result = orchestrator.run({.operation = chat::chat_operation::open});
  require(
      !result.ok && result.reason == "fixture_final_gate_rejected",
      "final_gate_rejection_lost");
  require(capture.calls == 0 && sink.calls == 0, "rejected_mutation_reached_runtime");
  require(!leases.chat_owned(), "rejected_episode_leaked_lease");
}

int run() {
  frame_and_pixel_geometry_are_bounded();
  observer_normalizes_fresh_frame_geometry();
  observer_rejects_replay_and_inconsistent_detector_output();
  disabled_capture_and_detector_are_explicit();
  win32_capture_rejects_missing_target_before_capture();
  orchestrator_holds_exclusive_lease_and_revalidates_immediately();
  busy_lease_blocks_observation_and_mutation();
  final_gate_rejection_never_reaches_platform_sink();
  std::cout << "PASS native chat capture/detector boundary and exclusive final gate\n";
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
