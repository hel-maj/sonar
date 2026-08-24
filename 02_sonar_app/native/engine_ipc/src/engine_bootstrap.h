#pragma once

#include <cstdint>
#include <string>

#include "sonar/fishing/engine_ipc/engine_mode.h"

namespace sonar::fishing::engine_ipc::runtime {

struct engine_build_identity final {
  std::string host_build_id;
  std::string engine_build_id;
  std::string bundle_manifest_hash;
};

struct engine_bootstrap_configuration final {
  engine_authority_mode authority_mode;
  engine_build_identity build_identity;
  std::string machine_fingerprint;
  std::wstring control_pipe_name;
  std::wstring event_pipe_name;
  std::string nonce;
  std::uint32_t host_process_id{};
  std::string session_id;
};

[[nodiscard]] engine_bootstrap_configuration load_engine_bootstrap();

}  // namespace sonar::fishing::engine_ipc::runtime
