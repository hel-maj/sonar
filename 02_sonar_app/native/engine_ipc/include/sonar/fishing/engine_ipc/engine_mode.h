#pragma once

#include "ipc/v1/sonar_platform.pb.h"

namespace sonar::fishing::engine_ipc {

enum class engine_authority_mode {
  offline_diagnostics,
  production,
  developer_full_access,
};

inline constexpr char fishing_session_control_capability_id[] =
    "fishing-session.control";

struct handshake_mode_policy final {
  bool diagnostic_mode;
  bool side_effect_support;
  bool side_effects_may_be_enabled;
  bool advertises_session_control;
};

[[nodiscard]] handshake_mode_policy handshake_policy(
    engine_authority_mode mode) noexcept;

// Applies only mode-owned fields. Product-neutral identity, protocol and other
// capability versions remain composed by the Engine transport entrypoint.
void apply_handshake_mode(
    sonar::platform::ipc::v1::HandshakeHello& hello,
    engine_authority_mode mode);

}  // namespace sonar::fishing::engine_ipc
