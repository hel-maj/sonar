#include "sonar/fishing/game_chat/chat_runtime.h"

#include <exception>

namespace sonar::fishing::game_chat {
namespace {

[[nodiscard]] std::string action_reason_text(
    const runtime_safety::action_reason reason) {
  using reason_type = runtime_safety::action_reason;
  switch (reason) {
    case reason_type::ready:
      return {};
    case reason_type::entitlement_invalid:
      return "chat_entitlement_invalid";
    case reason_type::settings_not_current:
      return "chat_settings_not_current";
    case reason_type::lifecycle_not_actionable:
      return "chat_lifecycle_not_actionable";
    case reason_type::invalid_packet_count:
      return "chat_input_packet_count_invalid";
    case reason_type::process_unavailable:
      return "chat_process_unavailable";
    case reason_type::process_changed:
      return "chat_process_changed";
    case reason_type::window_unavailable:
      return "chat_window_unavailable";
    case reason_type::window_changed:
      return "chat_window_changed";
    case reason_type::window_not_foreground:
      return "chat_window_not_foreground";
    case reason_type::packet_budget_exhausted:
      return "chat_input_packet_budget_exhausted";
  }
  return "chat_final_gate_unknown";
}

}  // namespace

runtime_safety_chat_final_gate::runtime_safety_chat_final_gate(
    runtime_safety::runtime_target_guard& target,
    chat_runtime_policy_source& policy) noexcept
    : target_(target), policy_(policy) {}

chat_input_result runtime_safety_chat_final_gate::revalidate(
    const chat_input_intent& intent) {
  try {
    const auto policy = policy_.snapshot();
    const auto reason = target_.preflight({
        .entitlement_valid = policy.entitlement_valid,
        .settings_current = policy.settings_current,
        .lifecycle_allows_input = policy.lifecycle_allows_input,
        .packet_count = intent.packet_count,
        .foreground_required =
            intent.kind != chat_intent_kind::activate_window,
    });
    if (reason == runtime_safety::action_reason::ready) {
      return chat_input_result::accepted();
    }
    return chat_input_result::rejected(action_reason_text(reason));
  } catch (const std::exception& error) {
    return chat_input_result::rejected(
        std::string("chat_final_gate_failed:") + error.what());
  } catch (...) {
    return chat_input_result::rejected("chat_final_gate_failed:unknown");
  }
}

guarded_chat_input_port::guarded_chat_input_port(
    const chat_input_lease& lease,
    chat_input_lease_coordinator& coordinator,
    chat_final_gate& final_gate,
    chat_platform_mutation_sink& sink) noexcept
    : lease_(lease),
      coordinator_(coordinator),
      final_gate_(final_gate),
      sink_(sink) {}

chat_input_result guarded_chat_input_port::apply(
    const chat_input_intent& intent) {
  if (!coordinator_.owns(lease_)) {
    return chat_input_result::rejected("chat_input_lease_lost");
  }
  try {
    if (intent.kind != chat_intent_kind::pause) {
      const auto gate = final_gate_.revalidate(intent);
      if (!gate.applied) {
        return gate;
      }
    }
    return sink_.apply(intent);
  } catch (const std::exception& error) {
    return chat_input_result::rejected(
        std::string("chat_platform_mutation_failed:") + error.what());
  } catch (...) {
    return chat_input_result::rejected(
        "chat_platform_mutation_failed:unknown");
  }
}

chat_input_result disabled_chat_final_gate::revalidate(
    const chat_input_intent& intent) {
  static_cast<void>(intent);
  return chat_input_result::rejected("chat_final_gate_disabled");
}

chat_input_result disabled_chat_platform_mutation_sink::apply(
    const chat_input_intent& intent) {
  static_cast<void>(intent);
  return chat_input_result::rejected("chat_platform_mutation_disabled");
}

chat_episode_orchestrator::chat_episode_orchestrator(
    chat_capture_source& capture,
    chat_frame_detector& detector,
    chat_input_lease_coordinator& leases,
    chat_final_gate& final_gate,
    chat_platform_mutation_sink& sink) noexcept
    : capture_(capture),
      detector_(detector),
      leases_(leases),
      final_gate_(final_gate),
      sink_(sink) {}

chat_episode_result chat_episode_orchestrator::run(
    const chat_episode_request& request) const {
  auto lease = leases_.try_acquire();
  if (!lease.has_value()) {
    return {.ok = false, .reason = "chat_input_lease_busy"};
  }
  capture_chat_observer observer(capture_, detector_);
  guarded_chat_input_port input(*lease, leases_, final_gate_, sink_);
  return chat_episode_runner{}.run(request, observer, input);
}

}  // namespace sonar::fishing::game_chat
