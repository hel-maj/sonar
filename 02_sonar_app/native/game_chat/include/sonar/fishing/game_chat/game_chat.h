#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include <vector>

namespace sonar::fishing::game_chat {

struct normalized_point final {
  double x{};
  double y{};

  [[nodiscard]] bool valid() const noexcept;
};

struct normalized_rect final {
  double x{};
  double y{};
  double width{};
  double height{};

  [[nodiscard]] bool valid() const noexcept;
  [[nodiscard]] normalized_point center() const noexcept;
};

struct chat_tab_observation final {
  std::string id;
  std::string name;
  bool selected{};
  normalized_rect bounds;
};

struct chat_observation final {
  bool active{};
  std::vector<chat_tab_observation> tabs;
  std::string selected_tab_id;
  normalized_rect input_bounds;
  std::string error;
};

enum class chat_operation {
  open,
  close,
  clear_input,
  select_tab,
  send_message,
};

struct chat_episode_request final {
  chat_operation operation{chat_operation::open};
  std::string chat_hotkey{"t"};
  std::string tab_id;
  std::string message;
  bool force_close{};
};

enum class chat_intent_kind {
  activate_window,
  release_all_keys,
  press_key,
  hotkey,
  click_client,
  set_clipboard_text,
  pause,
};

struct chat_input_intent final {
  chat_intent_kind kind{chat_intent_kind::pause};
  std::string primary;
  std::string secondary;
  normalized_point point;
  std::string text;
  std::size_t packet_count{};
  std::size_t delay_milliseconds{};
};

struct chat_input_result final {
  bool applied{};
  std::string reason;

  [[nodiscard]] static chat_input_result accepted();
  [[nodiscard]] static chat_input_result rejected(std::string reason);
};

class chat_observer {
 public:
  virtual ~chat_observer() = default;
  [[nodiscard]] virtual chat_observation observe() = 0;
};

// This is the atomic final boundary. A live implementation must revalidate
// entitlement, settings revision, lifecycle, process/window generation,
// foreground identity and Common packet budget immediately before applying the
// matching platform mutation. It must not retain an earlier authorization.
class chat_input_port {
 public:
  virtual ~chat_input_port() = default;
  [[nodiscard]] virtual chat_input_result apply(
      const chat_input_intent& intent) = 0;
};

struct chat_episode_result final {
  bool ok{};
  std::string reason;
  chat_observation observation;
};

class chat_episode_runner final {
 public:
  [[nodiscard]] chat_episode_result run(
      const chat_episode_request& request,
      chat_observer& observer,
      chat_input_port& input) const;
};

// Shipping composition stays fail closed until a guarded native window/input
// implementation is deliberately connected. Tests use a recording port.
class disabled_chat_input_port final : public chat_input_port {
 public:
  [[nodiscard]] chat_input_result apply(
      const chat_input_intent& intent) override;
};

[[nodiscard]] bool message_uses_explicit_chat_command(
    std::string_view message) noexcept;

}  // namespace sonar::fishing::game_chat
