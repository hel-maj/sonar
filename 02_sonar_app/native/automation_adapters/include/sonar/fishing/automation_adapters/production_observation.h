#pragma once

#include <memory>
#include <optional>
#include <stop_token>
#include <string>
#include <string_view>

#include "sonar/fishing/automation_adapters/fishing_adapters.h"
#include "sonar/fishing/catch_observation/catch_observation.h"
#include "sonar/fishing/maintenance_episode/maintenance_episode.h"

namespace sonar::fishing::automation_adapters {

struct recognized_text final {
  std::string text;
  std::string reason;
};

class runtime_text_recognizer {
 public:
  virtual ~runtime_text_recognizer() = default;
  [[nodiscard]] virtual recognized_text recognize(
      const runtime_platform::client_frame& frame,
      const stage_detection::normalized_rect& bounds) noexcept = 0;
};

[[nodiscard]] std::unique_ptr<runtime_text_recognizer>
make_windows_runtime_text_recognizer() noexcept;

struct production_catch_observation final {
  std::uint64_t sequence{};
  bool visible{};
  std::optional<catch_observation::CatchObservation> catch_fact;
  stage_detection::normalized_rect keep_button;
  stage_detection::normalized_rect release_button;
  bool inventory_full{};
  std::string error;
};

namespace detail {

// A completed detector pass with no trigger is a proven inactive mini-game.
// Detector failure is unknown, and even a populated defensive DTO must not
// turn the sentinel `none` stage into active merely because it has a value.
[[nodiscard]] std::optional<bool> derive_fishing_minigame_active(
    const stage_detection::stage_detection_result& detection) noexcept;

}  // namespace detail

// One capture owner projects the same client frame into catch, item/context
// geometry and maintenance facts. Inventory openness is authoritative only
// when the coherent memory snapshot normalizes to open/closed; OCR remains an
// internal bounded geometry adapter and unknown fails closed. Frames and OCR
// calls never cross Host IPC. All geometry is normalized to the current client
// area and every returned sequence is suitable for the immediate final gate.
class production_frame_observer final
    : public maintenance_episode::maintenance_observer {
 public:
  production_frame_observer(
      runtime_platform::client_capture_source& capture,
      stage_detection::majestic_fishing_stage_detector& stage_detector,
      fishing_memory_source& memory,
      mutable_runtime_policy_source& policy,
      runtime_text_recognizer& text) noexcept;
  ~production_frame_observer() override;

  production_frame_observer(const production_frame_observer&) = delete;
  production_frame_observer& operator=(const production_frame_observer&) =
      delete;

  [[nodiscard]] production_catch_observation observe_catch(
      std::stop_token stop_token);

  [[nodiscard]] inventory_store::inventory_observation observe(
      std::stop_token stop_token) override;
  [[nodiscard]] const maintenance_episode::maintenance_observation&
  current_maintenance() const noexcept override;

  void expect_context_item(
      std::string instance_id,
      stage_detection::normalized_rect item_bounds);
  void clear_context_item() noexcept;

 private:
  struct implementation;
  std::unique_ptr<implementation> implementation_;
};

}  // namespace sonar::fishing::automation_adapters
