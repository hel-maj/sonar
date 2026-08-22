#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "sonar/platform/windows/window.hpp"

namespace sonar::fishing::runtime_platform {

struct client_frame final {
  std::uint32_t width{};
  std::uint32_t height{};
  std::size_t stride_bytes{};
  std::uint64_t sequence{};
  std::uint64_t captured_at_steady_ns{};
  sonar::platform::windows::window_client_snapshot target;
  std::vector<std::uint8_t> bgr24;

  [[nodiscard]] bool valid() const noexcept;
};

struct capture_result final {
  std::optional<client_frame> frame;
  std::string reason;

  [[nodiscard]] static capture_result captured(client_frame frame);
  [[nodiscard]] static capture_result unavailable(std::string reason);
};

class client_capture_source {
 public:
  virtual ~client_capture_source() = default;
  [[nodiscard]] virtual capture_result capture() = 0;
};

// Product-owned GDI capture adapter. Common owns the coherent target snapshot;
// this adapter only captures its current client area and revalidates the exact
// identity and geometry both before and after the frame copy.
class win32_client_capture_source final : public client_capture_source {
 public:
  explicit win32_client_capture_source(
      sonar::platform::windows::window_client_snapshot expected) noexcept;

  [[nodiscard]] capture_result capture() override;

 private:
  sonar::platform::windows::window_client_snapshot expected_;
  std::uint64_t sequence_{};
};

}  // namespace sonar::fishing::runtime_platform
