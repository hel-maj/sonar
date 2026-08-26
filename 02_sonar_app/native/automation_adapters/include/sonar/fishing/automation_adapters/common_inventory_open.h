#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <string_view>

#include "sonar/platform/inventory/open_state.hpp"
#include "sonar/platform/windows/process.hpp"

namespace sonar::fishing::automation_adapters {

inline constexpr std::string_view common_inventory_open_authority_id{
    "common-trusted-publisher-runtime-v1"};
inline constexpr std::uint32_t common_inventory_open_authority_revision{1U};

struct inventory_open_source_result final {
  sonar::platform::inventory::observed_state state{
      sonar::platform::inventory::observed_state::unknown};
  bool binding_hot{};
  std::string reason;
};

// Narrow product port around Common's coarse inventory-open facade. Common
// remains the sole owner of renderer discovery, admission, V8 decoding and
// double-read coherence.
class inventory_open_source {
 public:
  virtual ~inventory_open_source() = default;
  [[nodiscard]] virtual inventory_open_source_result capture(
      const sonar::platform::windows::process_generation& game_generation)
      noexcept = 0;
  virtual void reset() noexcept = 0;
};

class inventory_retry_clock {
 public:
  virtual ~inventory_retry_clock() = default;
  [[nodiscard]] virtual std::uint64_t now_steady_ns() const noexcept = 0;
};

[[nodiscard]] std::unique_ptr<inventory_open_source>
make_common_inventory_open_source() noexcept;
[[nodiscard]] std::unique_ptr<inventory_retry_clock>
make_inventory_retry_clock() noexcept;

}  // namespace sonar::fishing::automation_adapters
