#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "sonar/fishing/game_chat/game_chat.h"
#include "sonar/fishing/runtime_platform/platform_capture.h"
#include "sonar/platform/windows/window.hpp"

namespace sonar::fishing::game_chat {

// Product-owned BGR24 client-frame contract. A live capture implementation is
// deliberately absent from current composition; fixtures and tests supply
// in-memory frames without touching a window.
struct chat_frame final {
  std::uint32_t width{};
  std::uint32_t height{};
  std::size_t stride_bytes{};
  std::uint64_t sequence{};
  std::vector<std::uint8_t> bgr24;

  [[nodiscard]] bool valid() const noexcept;
};

struct chat_capture_result final {
  std::optional<chat_frame> frame;
  std::string reason;

  [[nodiscard]] static chat_capture_result captured(chat_frame frame);
  [[nodiscard]] static chat_capture_result unavailable(std::string reason);
};

class chat_capture_source {
 public:
  virtual ~chat_capture_source() = default;
  [[nodiscard]] virtual chat_capture_result capture() = 0;
};

struct pixel_rect final {
  std::uint32_t x{};
  std::uint32_t y{};
  std::uint32_t width{};
  std::uint32_t height{};

  [[nodiscard]] bool valid_for(const chat_frame& frame) const noexcept;
};

struct pixel_chat_tab final {
  std::string id;
  std::string name;
  bool selected{};
  pixel_rect bounds;
};

struct pixel_chat_detection final {
  bool active{};
  std::vector<pixel_chat_tab> tabs;
  std::string selected_tab_id;
  std::optional<pixel_rect> input_bounds;
  std::string error;
};

class chat_frame_detector {
 public:
  virtual ~chat_frame_detector() = default;
  [[nodiscard]] virtual pixel_chat_detection detect(
      const chat_frame& frame) = 0;
};

// Converts a fresh product frame and pixel detector result into the normalized
// observation consumed by one coarse episode. Replayed frames, inconsistent
// selected-tab state and out-of-client geometry fail closed.
class capture_chat_observer final : public chat_observer {
 public:
  capture_chat_observer(
      chat_capture_source& capture,
      chat_frame_detector& detector) noexcept;

  [[nodiscard]] chat_observation observe() override;

 private:
  chat_capture_source& capture_;
  chat_frame_detector& detector_;
  std::uint64_t last_sequence_{};
};

class disabled_chat_capture_source final : public chat_capture_source {
 public:
  [[nodiscard]] chat_capture_result capture() override;
};

class disabled_chat_frame_detector final : public chat_frame_detector {
 public:
  [[nodiscard]] pixel_chat_detection detect(
      const chat_frame& frame) override;
};

// Native Majestic visual detector. It owns no capture or mutation resource and
// derives every spatial threshold from the current frame dimensions.
class majestic_chat_frame_detector final : public chat_frame_detector {
 public:
  [[nodiscard]] pixel_chat_detection detect(
      const chat_frame& frame) override;
};

// Product-owned GDI client capture. The caller supplies one coherent Common
// window snapshot. Production composition remains disabled until readiness.
class win32_chat_capture_source final : public chat_capture_source {
 public:
  explicit win32_chat_capture_source(
      sonar::platform::windows::window_client_snapshot expected) noexcept;

 [[nodiscard]] chat_capture_result capture() override;

 private:
  runtime_platform::win32_client_capture_source capture_;
};

}  // namespace sonar::fishing::game_chat
