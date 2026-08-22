#include "sonar/fishing/game_chat/game_chat.h"

#include <algorithm>
#include <cmath>
#include <cctype>
#include <exception>
#include <limits>
#include <optional>
#include <utility>

namespace sonar::fishing::game_chat {
namespace {

constexpr std::size_t kMaximumMessageBytes = 4096;
constexpr std::size_t kMaximumHotkeyBytes = 32;
constexpr std::size_t kOpenObservationLimit = 28;
constexpr std::size_t kCloseObservationLimit = 15;
constexpr std::size_t kPollDelayMilliseconds = 150;
constexpr std::size_t kTabDelayMilliseconds = 180;
constexpr std::size_t kClearDelayMilliseconds = 80;
constexpr std::size_t kInputFocusDelayMilliseconds = 50;
constexpr std::size_t kPasteDelayMilliseconds = 50;

[[nodiscard]] std::string_view trim_ascii(const std::string_view value) noexcept {
  std::size_t first = 0;
  while (first < value.size() &&
         std::isspace(static_cast<unsigned char>(value[first])) != 0) {
    ++first;
  }
  std::size_t last = value.size();
  while (last > first &&
         std::isspace(static_cast<unsigned char>(value[last - 1])) != 0) {
    --last;
  }
  return value.substr(first, last - first);
}

[[nodiscard]] bool bounded_text(
    const std::string_view value,
    const std::size_t maximum) noexcept {
  return !value.empty() && value.size() <= maximum &&
      value.find('\0') == std::string_view::npos;
}

[[nodiscard]] std::string ascii_lower(std::string_view value) {
  std::string result(value);
  std::transform(
      result.begin(),
      result.end(),
      result.begin(),
      [](const unsigned char character) {
        return static_cast<char>(std::tolower(character));
      });
  return result;
}

[[nodiscard]] bool tab_alias_matches(
    const chat_tab_observation& tab,
    const std::string_view requested) {
  if (tab.id == requested || tab.name == requested) {
    return true;
  }
  const std::string query = ascii_lower(trim_ascii(requested));
  const std::string id = ascii_lower(trim_ascii(tab.id));
  const std::string name = ascii_lower(trim_ascii(tab.name));
  if (query == "all") {
    return id == "0" || name == "all" || tab.name == "Все" ||
        tab.name == "Вкладка 1";
  }
  if (query == "fam") {
    return id == "1" || name == "family" || tab.name == "Семья" ||
        tab.name == "Вкладка 2";
  }
  if (query == "frac") {
    return id == "2" || name == "fraction" || tab.name == "Фракция" ||
        tab.name == "Вкладка 3";
  }
  if (query == "gov") {
    return id == "3" || name == "department" ||
        tab.name == "Департамент" || tab.name == "Вкладка 4";
  }
  if (query == "report") {
    return id == "4" || name == "report" || tab.name == "Репорт" ||
        tab.name == "Вкладка 5";
  }
  return id == query || name == query;
}

[[nodiscard]] const chat_tab_observation* find_tab(
    const chat_observation& observation,
    const std::string_view requested) {
  const auto found = std::find_if(
      observation.tabs.begin(),
      observation.tabs.end(),
      [requested](const chat_tab_observation& tab) {
        return tab_alias_matches(tab, requested);
      });
  return found == observation.tabs.end() ? nullptr : &*found;
}

[[nodiscard]] const chat_tab_observation* selected_tab(
    const chat_observation& observation) {
  const auto selected = std::find_if(
      observation.tabs.begin(),
      observation.tabs.end(),
      [](const chat_tab_observation& tab) { return tab.selected; });
  return selected == observation.tabs.end() ? nullptr : &*selected;
}

[[nodiscard]] bool is_all_tab(const chat_tab_observation& tab) {
  return tab.id == "0" || tab_alias_matches(tab, "all");
}

[[nodiscard]] chat_input_intent activate_intent() {
  return {
      .kind = chat_intent_kind::activate_window,
      .packet_count = 1,
  };
}

[[nodiscard]] chat_input_intent release_intent() {
  return {
      .kind = chat_intent_kind::release_all_keys,
      .packet_count = 9,
  };
}

[[nodiscard]] chat_input_intent press_intent(std::string key) {
  return {
      .kind = chat_intent_kind::press_key,
      .primary = std::move(key),
      .packet_count = 2,
  };
}

[[nodiscard]] chat_input_intent hotkey_intent(
    std::string first,
    std::string second) {
  return {
      .kind = chat_intent_kind::hotkey,
      .primary = std::move(first),
      .secondary = std::move(second),
      .packet_count = 4,
  };
}

[[nodiscard]] chat_input_intent click_intent(const normalized_point point) {
  return {
      .kind = chat_intent_kind::click_client,
      .point = point,
      .packet_count = 3,
  };
}

[[nodiscard]] chat_input_intent clipboard_intent(std::string text) {
  return {
      .kind = chat_intent_kind::set_clipboard_text,
      .text = std::move(text),
      .packet_count = 1,
  };
}

[[nodiscard]] chat_input_intent pause_intent(const std::size_t milliseconds) {
  return {
      .kind = chat_intent_kind::pause,
      .delay_milliseconds = milliseconds,
  };
}

class episode final {
 public:
  episode(chat_observer& observer, chat_input_port& input)
      : observer_(observer), input_(input) {}

  [[nodiscard]] chat_episode_result run(const chat_episode_request& request) {
    if (!bounded_text(trim_ascii(request.chat_hotkey), kMaximumHotkeyBytes)) {
      return fail("chat_hotkey_invalid");
    }
    switch (request.operation) {
      case chat_operation::open:
        return open(request.chat_hotkey);
      case chat_operation::close:
        return close(request.force_close);
      case chat_operation::clear_input:
        return clear(request.chat_hotkey);
      case chat_operation::select_tab:
        return select(request.chat_hotkey, request.tab_id);
      case chat_operation::send_message:
        return send(request.chat_hotkey, request.tab_id, request.message);
    }
    return fail("chat_operation_invalid");
  }

 private:
  [[nodiscard]] bool apply(const chat_input_intent& intent) {
    try {
      const auto result = input_.apply(intent);
      if (!result.applied) {
        failure_ = result.reason.empty()
            ? "chat_input_rejected"
            : result.reason;
        return false;
      }
      return true;
    } catch (const std::exception& error) {
      failure_ = std::string("chat_input_failed:") + error.what();
      return false;
    } catch (...) {
      failure_ = "chat_input_failed:unknown";
      return false;
    }
  }

  [[nodiscard]] bool observe() {
    try {
      last_ = observer_.observe();
    } catch (const std::exception& error) {
      failure_ = std::string("chat_observation_failed:") + error.what();
      return false;
    } catch (...) {
      failure_ = "chat_observation_failed:unknown";
      return false;
    }
    if (!last_.error.empty()) {
      failure_ = "chat_observation_unavailable:" + last_.error;
      return false;
    }
    return true;
  }

  [[nodiscard]] bool focus_input(const chat_observation& observation) {
    if (!observation.active || !observation.input_bounds.valid()) {
      failure_ = "chat_input_bounds_unavailable";
      return false;
    }
    const auto& bounds = observation.input_bounds;
    const normalized_point target{
        bounds.x + bounds.width * 0.2,
        bounds.y + bounds.height * 0.5,
    };
    return target.valid() && apply(activate_intent()) &&
        apply(click_intent(target)) &&
        apply(pause_intent(kInputFocusDelayMilliseconds));
  }

  [[nodiscard]] chat_episode_result open(const std::string_view hotkey) {
    if (!apply(activate_intent()) || !apply(release_intent()) || !observe()) {
      return fail_current();
    }
    if (last_.active) {
      if (!focus_input(last_)) {
        return fail_current();
      }
      return success("chat_already_active");
    }
    if (!apply(press_intent(std::string(trim_ascii(hotkey))))) {
      return fail_current();
    }
    for (std::size_t attempt = 0; attempt < kOpenObservationLimit; ++attempt) {
      if (!observe()) {
        return fail_current();
      }
      if (last_.active) {
        if (!focus_input(last_)) {
          return fail_current();
        }
        return success("chat_opened");
      }
      if (attempt + 1 < kOpenObservationLimit &&
          !apply(pause_intent(kPollDelayMilliseconds))) {
        return fail_current();
      }
    }
    return fail("chat_open_not_confirmed");
  }

  [[nodiscard]] chat_episode_result close(const bool force) {
    if (!apply(activate_intent()) || !observe()) {
      return fail_current();
    }
    if (!last_.active && !force) {
      return success("chat_already_closed");
    }
    if (!apply(press_intent("esc"))) {
      return fail_current();
    }
    for (std::size_t attempt = 0; attempt < kCloseObservationLimit; ++attempt) {
      if (!observe()) {
        return fail_current();
      }
      if (!last_.active) {
        return success("chat_closed");
      }
      if (attempt + 1 < kCloseObservationLimit &&
          !apply(pause_intent(kPollDelayMilliseconds))) {
        return fail_current();
      }
    }
    return fail("chat_close_not_confirmed");
  }

  [[nodiscard]] bool clear_input() {
    if (!focus_input(last_) ||
        !apply(hotkey_intent("ctrl", "a")) ||
        !apply(pause_intent(kClearDelayMilliseconds))) {
      return false;
    }
    for (std::size_t attempt = 0; attempt < 3; ++attempt) {
      if (!apply(press_intent("backspace")) ||
          !apply(pause_intent(kClearDelayMilliseconds))) {
        return false;
      }
    }
    return true;
  }

  [[nodiscard]] chat_episode_result clear(const std::string_view hotkey) {
    const auto opened = open(hotkey);
    if (!opened.ok) {
      return opened;
    }
    if (!clear_input() || !observe()) {
      return fail_current();
    }
    return success("chat_input_cleared");
  }

  [[nodiscard]] bool click_tab(const chat_tab_observation& tab) {
    if (!tab.bounds.valid()) {
      failure_ = "chat_tab_bounds_unavailable";
      return false;
    }
    return apply(click_intent(tab.bounds.center())) &&
        apply(pause_intent(kTabDelayMilliseconds));
  }

  [[nodiscard]] bool select_tab(const std::string_view tab_id) {
    if (tab_id.empty()) {
      return true;
    }
    const auto* tab = find_tab(last_, tab_id);
    if (tab == nullptr || tab->selected) {
      return true;
    }
    return click_tab(*tab) && observe();
  }

  [[nodiscard]] chat_episode_result select(
      const std::string_view hotkey,
      const std::string_view tab_id) {
    const auto opened = open(hotkey);
    if (!opened.ok) {
      return opened;
    }
    if (!select_tab(tab_id)) {
      return fail_current();
    }
    return success("chat_tab_selected");
  }

  [[nodiscard]] bool restore_tab_prefix(const std::string_view selected_id) {
    if (last_.tabs.size() <= 1) {
      return true;
    }
    const auto* selected = find_tab(last_, selected_id);
    if (selected == nullptr) {
      selected = selected_tab(last_);
    }
    if (selected == nullptr || is_all_tab(*selected)) {
      return true;
    }
    const std::string stable_id = selected->id;
    const chat_tab_observation stable_tab = *selected;
    const auto* all = find_tab(last_, "all");
    if (all == nullptr || all->id == stable_id) {
      return true;
    }
    if (!click_tab(*all) || !observe()) {
      return false;
    }
    const auto* refreshed = find_tab(last_, stable_id);
    return click_tab(refreshed == nullptr ? stable_tab : *refreshed) && observe();
  }

  [[nodiscard]] chat_episode_result send(
      const std::string_view hotkey,
      const std::string_view tab_id,
      const std::string_view message) {
    const std::string_view trimmed = trim_ascii(message);
    if (!bounded_text(trimmed, kMaximumMessageBytes)) {
      if (!observe()) {
        return fail_current();
      }
      return fail("chat_message_invalid");
    }
    const auto opened = open(hotkey);
    if (!opened.ok) {
      return opened;
    }
    if (!select_tab(tab_id)) {
      return fail_current();
    }
    const std::string selected_id = tab_id.empty()
        ? last_.selected_tab_id
        : std::string(tab_id);
    if (!clear_input() || !observe()) {
      return fail_current();
    }
    if (!selected_id.empty() &&
        !message_uses_explicit_chat_command(trimmed) &&
        !restore_tab_prefix(selected_id)) {
      return fail_current();
    }
    if (!focus_input(last_) ||
        !apply(clipboard_intent(std::string(trimmed))) ||
        !apply(hotkey_intent("ctrl", "v")) ||
        !apply(pause_intent(kPasteDelayMilliseconds)) ||
        !apply(press_intent("enter")) ||
        !observe()) {
      return fail_current();
    }
    return success("chat_message_sent");
  }

  [[nodiscard]] chat_episode_result success(std::string reason) const {
    return {.ok = true, .reason = std::move(reason), .observation = last_};
  }

  [[nodiscard]] chat_episode_result fail(std::string reason) const {
    return {.ok = false, .reason = std::move(reason), .observation = last_};
  }

  [[nodiscard]] chat_episode_result fail_current() const {
    return fail(failure_.empty() ? "chat_episode_failed" : failure_);
  }

  chat_observer& observer_;
  chat_input_port& input_;
  chat_observation last_;
  std::string failure_;
};

}  // namespace

bool normalized_point::valid() const noexcept {
  return std::isfinite(x) && std::isfinite(y) &&
      x >= 0.0 && x <= 1.0 && y >= 0.0 && y <= 1.0;
}

bool normalized_rect::valid() const noexcept {
  return std::isfinite(x) && std::isfinite(y) &&
      std::isfinite(width) && std::isfinite(height) &&
      x >= 0.0 && y >= 0.0 && width > 0.0 && height > 0.0 &&
      x + width <= 1.0 && y + height <= 1.0;
}

normalized_point normalized_rect::center() const noexcept {
  return {x + width * 0.5, y + height * 0.5};
}

chat_input_result chat_input_result::accepted() {
  return {.applied = true};
}

chat_input_result chat_input_result::rejected(std::string reason) {
  return {.applied = false, .reason = std::move(reason)};
}

chat_episode_result chat_episode_runner::run(
    const chat_episode_request& request,
    chat_observer& observer,
    chat_input_port& input) const {
  return episode(observer, input).run(request);
}

chat_input_result disabled_chat_input_port::apply(
    const chat_input_intent& intent) {
  static_cast<void>(intent);
  return chat_input_result::rejected("chat_live_adapter_disabled");
}

bool message_uses_explicit_chat_command(
    const std::string_view message) noexcept {
  const std::string_view trimmed = trim_ascii(message);
  if (trimmed.size() < 2 || trimmed[0] != '/' || trimmed[1] == '/' ||
      std::isspace(static_cast<unsigned char>(trimmed[1])) != 0) {
    return false;
  }
  for (std::size_t index = 1; index < trimmed.size(); ++index) {
    if (std::isspace(static_cast<unsigned char>(trimmed[index])) != 0) {
      return true;
    }
    if (trimmed[index] == '/') {
      return false;
    }
  }
  return true;
}

}  // namespace sonar::fishing::game_chat
