#include "sonar/fishing/engine_ipc/engine_mode.h"

namespace sonar::fishing::engine_ipc {

handshake_mode_policy handshake_policy(
    const engine_authority_mode mode) noexcept {
  switch (mode) {
    case engine_authority_mode::offline_diagnostics:
      return handshake_mode_policy{
          .diagnostic_mode = true,
          .side_effect_support = false,
          .side_effects_may_be_enabled = false,
          .advertises_session_control = false,
      };
    case engine_authority_mode::production:
    case engine_authority_mode::developer_full_access:
      return handshake_mode_policy{
          .diagnostic_mode = false,
          .side_effect_support = true,
          .side_effects_may_be_enabled = true,
          .advertises_session_control = true,
      };
  }
  return handshake_mode_policy{
      .diagnostic_mode = true,
      .side_effect_support = false,
      .side_effects_may_be_enabled = false,
      .advertises_session_control = false,
  };
}

void apply_handshake_mode(
    sonar::platform::ipc::v1::HandshakeHello& hello,
    const engine_authority_mode mode) {
  const auto policy = handshake_policy(mode);
  hello.set_diagnostic_mode(policy.diagnostic_mode);
  hello.set_side_effect_support(policy.side_effect_support);
  if (policy.advertises_session_control) {
    auto* capability = hello.add_capabilities();
    capability->set_capability_id(fishing_session_control_capability_id);
    capability->set_major(1);
    capability->set_minor(0);
  }
}

}  // namespace sonar::fishing::engine_ipc
