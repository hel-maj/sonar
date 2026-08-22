#pragma once

#include <stop_token>

#include "sonar/fishing/game_chat/chat_runtime.h"
#include "sonar/fishing/runtime_platform/platform_input.h"
#include "sonar/platform/windows/window.hpp"

namespace sonar::fishing::game_chat {

using native_input_packet_kind = runtime_platform::input_packet_kind;
using native_input_packet = runtime_platform::input_packet;
using chat_native_platform_api = runtime_platform::native_platform_api;

// Concrete product mutation boundary. Key/hotkey/click actions use complete
// bounded pulse batches; an API-reported partial prefix is followed by the
// minimum key-up/mouse-up cleanup for that prefix. Pauses are cancellable and
// do not touch the platform API. The default production composition does not
// construct this class until the external entitlement trust root/readiness
// gates are satisfied.
class win32_chat_platform_mutation_sink final
    : public chat_platform_mutation_sink {
 public:
  win32_chat_platform_mutation_sink(
      sonar::platform::windows::window_client_snapshot expected,
      std::stop_token stop);
  win32_chat_platform_mutation_sink(
      sonar::platform::windows::window_client_snapshot expected,
      std::stop_token stop,
      chat_native_platform_api& api) noexcept;
  ~win32_chat_platform_mutation_sink() override;

  win32_chat_platform_mutation_sink(
      const win32_chat_platform_mutation_sink&) = delete;
  win32_chat_platform_mutation_sink& operator=(
      const win32_chat_platform_mutation_sink&) = delete;

 [[nodiscard]] chat_input_result apply(
      const chat_input_intent& intent) override;

 private:
  runtime_platform::win32_platform_mutation_sink sink_;
};

}  // namespace sonar::fishing::game_chat
